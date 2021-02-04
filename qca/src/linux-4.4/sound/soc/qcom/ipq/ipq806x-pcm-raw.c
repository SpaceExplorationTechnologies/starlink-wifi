/* Copyright (c) 2010-2011,2013,2017, The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <linux/init.h>
#include <linux/err.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/time.h>
#include <linux/wait.h>
#include <linux/slab.h>
#include <linux/dma-mapping.h>
#include <asm/dma.h>
#include <linux/interrupt.h>
#include <linux/spinlock.h>
#include <linux/platform_device.h>
#include <sound/pcm.h>
#include <linux/clk.h>
#include <linux/gpio.h>
#include <linux/irq.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/wait.h>
#include <linux/io.h>
#include <linux/of_device.h>
#include <linux/reset-controller.h>
#include <linux/reset.h>
#include "ipq806x-lpaif.h"
#include "ipq806x.h"
#include "ipq806x-pcm.h"

/*
* RT Miss counter buckets
*/
#ifdef RTMISS_PROC_CNTRS
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#endif

static atomic_t data_avail;
static atomic_t data_at;
static struct voice_dma_buffer *rx_dma_buffer;
static struct voice_dma_buffer *tx_dma_buffer;
static spinlock_t pcm_lock;
static DECLARE_WAIT_QUEUE_HEAD(pcm_q);
static struct pcm_context context;
static struct dai_dma_params tx_dma_params;
static struct dai_dma_params rx_dma_params;
static struct platform_device *pcm_pdev;
static int voice_allocate_dma_buffer(struct device *dev,
		struct voice_dma_buffer *dma_buffer);
static int voice_free_dma_buffer(struct device *dev,
		struct voice_dma_buffer *dma_buff);
static int dsp_flag;
static int dsp_realtime_flag;

#ifdef RTMISS_PROC_CNTRS
unsigned rtmiss_cnts[NR_CNTS] = { 0 };
static struct proc_dir_entry *proc_rt_miss;

static int rtmiss_cnt_show(struct seq_file *p, void *v)
{
	int i;

	seq_puts(p, "RTMISS:");
	for (i = 0; i < NR_CNTS; i++)
		seq_printf(p, " %5u", rtmiss_cnts[i]);

	seq_putc(p, '\n');

	return 0;
}

static int rtmiss_cnt_open(struct inode *inode, struct file *file)
{
	return single_open(file, rtmiss_cnt_show, NULL);
}

static ssize_t rtmiss_cnt_reset(struct file *file, const char *buf,
				size_t size, loff_t *ppos)
{
#define CLEAR_STATS_CMD	"reset\n"

	char buff[sizeof(CLEAR_STATS_CMD)];
	int cmdsize = sizeof(CLEAR_STATS_CMD) - 1;
	int i;

	if (size != cmdsize)
		return -ENOSYS;

	buff[cmdsize] = '\0';

	if (copy_from_user(buff, buf, cmdsize))
		return -EFAULT;

	if (strcasecmp(buff, CLEAR_STATS_CMD) == 0) {
		/* Clear RT miss counters */
		for (i = 0; i < NR_CNTS; i++)
			rtmiss_cnts[i] = 0;
	}

	return size;
}

static const struct file_operations proc_rtmiss_cnt_operations = {
	.open		= rtmiss_cnt_open,
	.read		= seq_read,
	.write		= rtmiss_cnt_reset,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static int __init proc_rtmiss_cnt_init(void)
{
	proc_rt_miss = proc_create("rtmiss_cntr", 0, NULL,
				&proc_rtmiss_cnt_operations);
	return 0;
}
void proc_rtmiss_cnt_exit(void)
{
	remove_proc_entry("rtmiss_cntr", NULL);
}
static inline void cnt_update(int count, unsigned *counter)
{
	if (count > NR_CNTS-1)
		counter[NR_CNTS-1] += 1;
	else if (count)
		counter[count-1] += 1;
}
#endif

static irqreturn_t pcm_irq_handler(int intrsrc, void *data)
{
	void *dma_addr;
	uint32_t offset;
	uint32_t dma_at;
	/*
	 * Since Rx and Tx DMA starts at the same time after
	 * PCM is taken out of reset, both would complete at
	 * the same time, so no point in waiting for 2 interrupts.
	 * If one finishes its implicit that other too finishes.
	 * This handler assumes only Tx or Rx DMA interrupt is enabled.
	 *
	 * Read DMA current buffer address and figure out of buffer A
	 * finished or B finished.
	 */

	dma_addr = (void *)readl(dai_info.base +
				LPA_IF_DMA_CURR_ADDR(PCM0_DMA_WR_CH));
	offset = (uint32_t)(dma_addr - rx_dma_buffer->addr);
	dma_at = offset / (rx_dma_buffer->size / NUM_BUFFERS);

	if (dma_at > (NUM_BUFFERS - 1)) {
		/* some error, get out */
		return IRQ_HANDLED;
	}
	atomic_set(&data_at, (dma_at + 1) % NUM_BUFFERS);
	atomic_set(&data_avail, 1);
	wake_up_interruptible(&pcm_q);

	/* Set the real-time miss flag if dsp_flag isn’t cleared by dsp */
	if (dsp_flag)
		dsp_realtime_flag++;

	dsp_flag = 1;

	return IRQ_HANDLED;
}

void ipq_pcm_clear_flag(void)
{
	dsp_flag = 0;
}
EXPORT_SYMBOL(ipq_pcm_clear_flag);

int ipq_pcm_check_flag(void)
{
	int retvalue;

	retvalue = dsp_realtime_flag;
#ifdef RTMISS_PROC_CNTRS
	dsp_realtime_flag = 0;
	cnt_update(retvalue, rtmiss_cnts);
#else
	if (retvalue) {
		dsp_realtime_flag = 0;
		return retvalue;
	}
#endif
	return 0;
}
EXPORT_SYMBOL(ipq_pcm_check_flag);

static uint32_t ipq_pcm_validate_params(struct ipq_pcm_params *params)
{
	uint32_t bits_in_frame;

	if (!params) {
		pr_err("%s: Invalid Params.\n", __func__);
		return -EINVAL;
	}

	/* Bit width supported is 8 or 16 */
	if (!((params->bit_width == IPQ_PCM_BIT_WIDTH_8) ||
		(params->bit_width == IPQ_PCM_BIT_WIDTH_16))) {
		pr_err("%s: Invalid Bitwidth %d.\n",
			__func__, params->bit_width);
		return -EINVAL;
	}

	/* Sampling rate should be 8Khz or 16KHz or 32KHz or 48KHz */
	if (!((params->rate == IPQ_PCM_SAMPLING_RATE_8KHZ) ||
		(params->rate == IPQ_PCM_SAMPLING_RATE_16KHZ) ||
		(params->rate == IPQ_PCM_SAMPLING_RATE_32KHZ) ||
		(params->rate == IPQ_PCM_SAMPLING_RATE_48KHZ))) {
		pr_err("%s: Invalid Rate %d.\n",
			__func__, params->rate);
		return -EINVAL;
	}

	/* Max slots in a frame is 1 or 2 or 4 or 8 or 16 or 32 */
	if (!((params->slot_count == IPQ_PCM_SLOTS_1) ||
		(params->slot_count == IPQ_PCM_SLOTS_2) ||
		(params->slot_count == IPQ_PCM_SLOTS_4) ||
		(params->slot_count == IPQ_PCM_SLOTS_8) ||
		(params->slot_count == IPQ_PCM_SLOTS_16) ||
		(params->slot_count == IPQ_PCM_SLOTS_32))) {
		pr_err("%s: Invalid Slot Count %d.\n",
		__func__, params->slot_count);
		return -EINVAL;
	}

	/* max total bits in frame is 256 for 8KHz,16KHz, 32KHz */
	bits_in_frame = params->slot_count * params->bit_width;
	if (bits_in_frame > IPQ_PCM_BITS_IN_FRAME_256) {
		pr_err("%s: Bits in frame %d exceeds max 256.\n",
		__func__, bits_in_frame);
		return -EINVAL;
	}

	/* max total bits in frame is 128 for 48KHz */
	if ((params->rate == IPQ_PCM_SAMPLING_RATE_48KHZ) &&
		(bits_in_frame > IPQ_PCM_BITS_IN_FRAME_128)) {
		pr_err("%s: Bits in frame %d exceeds max 128.\n",
				__func__, bits_in_frame);
		return -EINVAL;
	}

	/* Number of active slots should be less than or same as max slots */
	if (params->active_slot_count > params->slot_count) {
		pr_err("%s: Active slots should be less "
		"than or same as %d\n", __func__, params->slot_count);
		return -EINVAL;
	}

	/* Number of active slots should 1 to 4 */
	if (!params->active_slot_count ||
		(params->active_slot_count > LPA_IF_TPCM_MAX_SLOT)) {
		pr_err("%s: Active slots should be in range "
		"1 to %d\n", __func__, LPA_IF_TPCM_MAX_SLOT);
		return -EINVAL;
	}

	return 0;
}

int ipq806x_pcm_init(struct ipq_pcm_params *params)
{
	uint32_t ret;
	uint32_t buf_size;
	uint32_t bits_in_frame;
	uint32_t i;

	ret = ipq_pcm_validate_params(params);
	if (ret)
		return ret;

	bits_in_frame = params->slot_count * params->bit_width;
	atomic_set(&data_avail, 0);
	atomic_set(&data_at, 1);
	reset_control_assert(lpaif_blk_rst);

	/* Sync source internal */
	ipq_cfg_pcm_sync_src(1);

	/* Select long FSYNC */
	ipq_cfg_pcm_aux_mode(1);

	/* Configure slots for RX */
	ret = ipq_cfg_pcm_active_slot_count(params->active_slot_count, 0);
	if (ret)
		return ret;

	/* Configure slots for TX */
	ret = ipq_cfg_pcm_active_slot_count(params->active_slot_count, 1);
	if (ret)
		return ret;

	for (i = 0; i < params->active_slot_count; i++) {
		ret = ipq_cfg_pcm_tx_active_slot(i, params->tx_slots[i]);
		if (ret)
			return ret;

		ret = ipq_cfg_pcm_rx_active_slot(i, params->rx_slots[i]);
		if (ret)
			return ret;
	}

	/* Configure bit width */

	ipq_cfg_pcm_width(params->bit_width, 0);
	ipq_cfg_pcm_width(params->bit_width, 1);

	/* Configure the number of slots */
	ipq_cfg_pcm_rate(bits_in_frame);

	/* Configure the DMA */
	buf_size = IPQ_PCM_SAMPLES_PER_10MS(params->rate) * NUM_BUFFERS *
			IPQ_PCM_BYTES_PER_SAMPLE(params->bit_width) *
			params->active_slot_count;

	rx_dma_buffer->size = buf_size;
	ret = voice_allocate_dma_buffer(&pcm_pdev->dev, rx_dma_buffer);
	if (ret) {
		dev_err(&pcm_pdev->dev, "%s: %d:Error in allocating rx ring buffer\n",
				__func__, __LINE__);

		return -ENOMEM;
	}

	tx_dma_buffer->size = buf_size;
	ret = voice_allocate_dma_buffer(&pcm_pdev->dev, tx_dma_buffer);
	if (ret) {
		dev_err(&pcm_pdev->dev, "%s: %d:Error in allocating tx ring buffer\n",
				__func__, __LINE__);
		ret = -ENOMEM;
		goto err_mem_tx;
	}

	tx_dma_params.src_start = tx_dma_buffer->addr;
	tx_dma_params.buffer = (u8 *)tx_dma_buffer->area;
	tx_dma_params.buffer_size = buf_size;
	tx_dma_params.period_size = (buf_size / NUM_BUFFERS);
	ret = ipq_lpaif_cfg_dma(PCM0_DMA_RD_CH, &tx_dma_params,
					params->bit_width, 0 /*disable */);
	if (ret)
		goto error_cfg_rd_ch;

	rx_dma_params.src_start = rx_dma_buffer->addr;
	rx_dma_params.buffer = (u8 *)rx_dma_buffer->area;
	rx_dma_params.buffer_size = buf_size;
	rx_dma_params.period_size = (buf_size / NUM_BUFFERS);
	ret = ipq_lpaif_cfg_dma(PCM0_DMA_WR_CH, &rx_dma_params,
					params->bit_width, 0 /*disable */);
	if (ret)
		goto error_cfg_wr_ch;

	/*
	 * Enable DMA interrupt only for Tx. Its implicit that Rx and Tx
	 * will complete at same time as they operate on same clock.
	 */
	ipq_lpaif_register_dma_irq_handler(PCM0_DMA_WR_CH,
						pcm_irq_handler, NULL);
	ipq_pcm_int_enable(PCM0_DMA_WR_CH);

	/* Start PCLK */
	ret = clk_set_rate(lpaif_pcm_bit_clk, params->rate * bits_in_frame);
	if (IS_ERR_VALUE(ret)) {
		pr_err("%s : clk_set_rate failed for pcm bit clock\n",
								__func__);
		goto error_clk;
	}

	ret = clk_prepare_enable(lpaif_pcm_bit_clk);
	if (IS_ERR_VALUE(ret)) {
		pr_err("%s : clk_prepare_enable failed for pcm bit clock\n",
								 __func__);
		goto error_clk;
	}

	/* take PCM out of reset to start it */
	reset_control_deassert(lpaif_blk_rst);

	context.needs_deinit = 1;
	return 0;

error_clk:
	ipq_lpaif_disable_dma(PCM0_DMA_WR_CH);
error_cfg_wr_ch:
error_cfg_rd_ch:
	ipq_lpaif_unregister_dma_irq_handler(PCM0_DMA_WR_CH);
	voice_free_dma_buffer(&pcm_pdev->dev, tx_dma_buffer);
err_mem_tx:
	voice_free_dma_buffer(&pcm_pdev->dev, rx_dma_buffer);
	return ret;
}
EXPORT_SYMBOL(ipq806x_pcm_init);

void ipq806x_pcm_deinit(void)
{
	context.needs_deinit = 0;
	reset_control_assert(lpaif_blk_rst);
	clk_disable_unprepare(lpaif_pcm_bit_clk);
	 /* set Rx active slot count to default. */
	ipq_cfg_pcm_active_slot_count(LPA_IF_PCM_DEFAULT_SLOT_COUNT, 0);
	 /* set Tx active slot count to default. */
	ipq_cfg_pcm_active_slot_count(LPA_IF_PCM_DEFAULT_SLOT_COUNT, 1);
	ipq_pcm_int_disable(PCM0_DMA_WR_CH);
	ipq_lpaif_unregister_dma_irq_handler(PCM0_DMA_WR_CH);
	ipq_lpaif_unregister_dma_irq_handler(PCM0_DMA_RD_CH);
	ipq_lpaif_disable_dma(PCM0_DMA_WR_CH);
	ipq_lpaif_disable_dma(PCM0_DMA_RD_CH);
	memset(&context, 0, sizeof(struct pcm_context));
	if (tx_dma_buffer)
		voice_free_dma_buffer(&pcm_pdev->dev, tx_dma_buffer);
	if (rx_dma_buffer)
		voice_free_dma_buffer(&pcm_pdev->dev, rx_dma_buffer);
}
EXPORT_SYMBOL(ipq806x_pcm_deinit);

uint32_t ipq806x_pcm_data(char **rx_buf, char **tx_buf)
{
	unsigned long flag;
	uint32_t offset;

	wait_event_interruptible(pcm_q, atomic_read(&data_avail) != 0);
	atomic_set(&data_avail, 0);
	offset = (rx_dma_buffer->size / NUM_BUFFERS) * atomic_read(&data_at);
	spin_lock_irqsave(&pcm_lock, flag);
	*rx_buf = rx_dma_buffer->area + offset;
	*tx_buf = tx_dma_buffer->area + offset;
	spin_unlock_irqrestore(&pcm_lock, flag);

	return (rx_dma_buffer->size / NUM_BUFFERS);
}
EXPORT_SYMBOL(ipq806x_pcm_data);

void ipq806x_pcm_done(void)
{
	atomic_set(&data_avail, 0);
}
EXPORT_SYMBOL(ipq806x_pcm_done);

static int voice_allocate_dma_buffer(struct device *dev,
		struct voice_dma_buffer *dma_buffer)
{
	dma_buffer->area =  dma_alloc_coherent(dev, dma_buffer->size,
			&dma_buffer->addr, GFP_KERNEL);

	if (!dma_buffer->area)
		return -ENOMEM;

	return 0;
}

static int voice_free_dma_buffer(struct device *dev,
		struct voice_dma_buffer *dma_buff)
{
	if (!dma_buff->area)
		return 0;

	dma_free_coherent(dev, dma_buff->size + 4,
			dma_buff->area, dma_buff->addr);
	dma_buff->area = NULL;
	return 0;
}

static const struct of_device_id qca_raw_match_table[] = {
	{ .compatible = "qca,ipq806x-pcm", },
	{},
};

static int ipq_pcm_driver_probe(struct platform_device *pdev)
{
	int ret;

	if (!pdev)
		return -ENOMEM;
	pcm_pdev = pdev;

	if (!pdev->dev.coherent_dma_mask)
		pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);

	/* Allocate memory for rx  and tx instance */
	rx_dma_buffer = kzalloc(sizeof(struct voice_dma_buffer), GFP_KERNEL);
	if (!rx_dma_buffer) {
		dev_err(&pdev->dev, "%s: %d:Error in allocating rx_dma_mem\n",
				__func__, __LINE__);
		ret = -ENOMEM;
		goto error;
	}

	tx_dma_buffer = kzalloc(sizeof(struct voice_dma_buffer), GFP_KERNEL);
	if (!tx_dma_buffer) {
		dev_err(&pdev->dev, "%s: %d:Error in allocating tx_dma_mem\n",
				__func__, __LINE__);
		ret = -ENOMEM;
		goto error_mem;
	}

	pcm_test_init(pcm_pdev);
	spin_lock_init(&pcm_lock);

#ifdef RTMISS_PROC_CNTRS
	/* Create RT miss count proc entry */
	proc_rtmiss_cnt_init();
#endif

	return 0;

error_mem:
	kfree(rx_dma_buffer);
error:
	return ret;
}

static int ipq_pcm_driver_remove(struct platform_device *pdev)
{
	kfree(tx_dma_buffer);
	kfree(rx_dma_buffer);

	pcm_test_exit(pdev);

#ifdef RTMISS_PROC_CNTRS
	/* Remove RT miss count proc entry */
	proc_rtmiss_cnt_exit();
#endif

	return 0;
}


#define DRIVER_NAME "ipq806x-pcm-raw"

static struct platform_driver ipq_pcm_raw_driver = {
	.probe	= ipq_pcm_driver_probe,
	.remove	= ipq_pcm_driver_remove,
	.driver	= {
		.name	= DRIVER_NAME,
		.of_match_table	= qca_raw_match_table,
	},
};

module_platform_driver(ipq_pcm_raw_driver);

MODULE_DESCRIPTION("IPQ RAW PCM VoIP Platform Driver");
MODULE_LICENSE("Dual BSD/GPL");
