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

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/dma-mapping.h>
#include <linux/debugfs.h>
#include <linux/delay.h>
#include <linux/uaccess.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/spinlock.h>
#include <linux/slab.h>
#include <linux/clk.h>
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/soc.h>
#include <linux/of_device.h>
#include <linux/reset.h>
#include "ipq806x-pcm.h"
#include "ipq806x-lpaif.h"
#include "ipq806x.h"

struct ipq_lpaif_dai_baseinfo dai_info;
EXPORT_SYMBOL(dai_info);

struct dai_drv *dai[MAX_LPAIF_CHANNELS];
static spinlock_t dai_lock;
struct clk *lpaif_pcm_bit_clk;
EXPORT_SYMBOL(lpaif_pcm_bit_clk);
struct reset_control *lpaif_blk_rst;
EXPORT_SYMBOL(lpaif_blk_rst);

int ipq_pcm_int_enable(uint8_t dma_ch)
{
	uint32_t intr_val;
	uint32_t status_val;
	unsigned long flags;

	if (dma_ch >= MAX_LPAIF_CHANNELS)
		return -EINVAL;

	spin_lock_irqsave(&dai_lock, flags);
	/* clear status before enabling interrupt */
	status_val = readl(dai_info.base + LPAIF_IRQ_CLEAR(0));
	status_val = status_val | (1 << (dma_ch * 3));
	writel(status_val, dai_info.base + LPAIF_IRQ_CLEAR(0));

	intr_val = readl(dai_info.base + LPAIF_IRQ_EN(0));
	intr_val = intr_val | (1 << (dma_ch * 3));
	writel(intr_val, dai_info.base + LPAIF_IRQ_EN(0));
	spin_unlock_irqrestore(&dai_lock, flags);

	return 0;
}
EXPORT_SYMBOL(ipq_pcm_int_enable);

int ipq_pcm_int_disable(uint8_t dma_ch)
{
	uint32_t intr_val;
	unsigned long flags;

	if (dma_ch >= MAX_LPAIF_CHANNELS)
		return -EINVAL;

	spin_lock_irqsave(&dai_lock, flags);
	intr_val = readl(dai_info.base + LPAIF_IRQ_EN(0));
	intr_val = intr_val & ~(1 << (dma_ch * 3));
	writel(intr_val, dai_info.base + LPAIF_IRQ_EN(0));
	spin_unlock_irqrestore(&dai_lock, flags);

	return 0;
}
EXPORT_SYMBOL(ipq_pcm_int_disable);

void ipq_cfg_pcm_aux_mode(uint8_t mode)
{
	uint32_t cfg;

	cfg = readl(dai_info.base + LPA_IF_PCM_0);

	if (mode)
		cfg |= LPA_IF_PCM_AUX_MODE;
	else
		cfg &= ~(LPA_IF_PCM_AUX_MODE);

	writel(cfg, dai_info.base + LPA_IF_PCM_0);
}
EXPORT_SYMBOL(ipq_cfg_pcm_aux_mode);

void ipq_cfg_pcm_sync_src(uint8_t src)
{
	uint32_t cfg;

	cfg = readl(dai_info.base + LPA_IF_PCM_0);

	if (src)
		cfg |= LPA_IF_PCM_SYNC_SRC_INT;
	else
		cfg = cfg & ~(LPA_IF_PCM_SYNC_SRC_INT);

	writel(cfg, dai_info.base + LPA_IF_PCM_0);
}
EXPORT_SYMBOL(ipq_cfg_pcm_sync_src);

void ipq_cfg_pcm_slot(uint8_t slot, uint8_t dir)
{
	uint32_t cfg;

	cfg = readl(dai_info.base + LPA_IF_PCM_0);

	if (dir)
		cfg = (cfg & ~(LPA_IF_RPCM_SLOT_MASK)) |
			(LPA_IF_PCM_RPCM_SLOT(slot));
	else
		cfg = (cfg & ~(LPA_IF_TPCM_SLOT_MASK))  |
			LPA_IF_PCM_TPCM_SLOT(slot);

	writel(cfg, dai_info.base + LPA_IF_PCM_0);
}
EXPORT_SYMBOL(ipq_cfg_pcm_slot);

void ipq_cfg_pcm_rate(uint32_t rate)
{
	uint32_t cfg;

	cfg = readl(dai_info.base + LPA_IF_PCM_0);

	/* Clear the rate field */
	cfg = cfg & ~(LPA_IF_PCM_RATE_MASK);
	switch (rate) {
	case IPQ_PCM_BITS_IN_FRAME_8:
		cfg |= LPA_IF_PCM_CTL_8_BITS;
		break;
	case IPQ_PCM_BITS_IN_FRAME_16:
		cfg |= LPA_IF_PCM_CTL_16_BITS;
		break;
	case IPQ_PCM_BITS_IN_FRAME_32:
		cfg |= LPA_IF_PCM_CTL_32_BITS;
		break;
	case IPQ_PCM_BITS_IN_FRAME_64:
		cfg |= LPA_IF_PCM_CTL_64_BITS;
		break;
	case IPQ_PCM_BITS_IN_FRAME_128:
		cfg |= LPA_IF_PCM_CTL_128_BITS;
		break;
	case IPQ_PCM_BITS_IN_FRAME_256:
		cfg |= LPA_IF_PCM_CTL_256_BITS;
		break;
	default:
		break;
	}
	writel(cfg, dai_info.base + LPA_IF_PCM_0);
}
EXPORT_SYMBOL(ipq_cfg_pcm_rate);

void ipq_cfg_pcm_width(uint8_t bit_width, uint8_t dir)
{
	uint32_t cfg;

	cfg = readl(dai_info.base + LPA_IF_PCM_0);

	switch (bit_width) {
	case IPQ_PCM_BIT_WIDTH_8:
		if (dir)
			cfg = cfg & ~(LPA_IF_PCM_TPCM_WIDTH);
		else
			cfg = cfg & ~(LPA_IF_PCM_RPCM_WIDTH);
		break;
	case IPQ_PCM_BIT_WIDTH_16:
		if (dir)
			cfg |= LPA_IF_PCM_TPCM_WIDTH;
		else
			cfg |= LPA_IF_PCM_RPCM_WIDTH;
		break;
	default:
		break;
	}
	writel(cfg, dai_info.base + LPA_IF_PCM_0);
}
EXPORT_SYMBOL(ipq_cfg_pcm_width);

int ipq_cfg_pcm_active_slot_count(uint8_t slot_count, uint8_t dir)
{
	uint32_t cfg;

	if (slot_count > LPA_IF_PCM_MAX_ACT_SLOT)
		return -EINVAL;

	cfg = readl(dai_info.base + LPA_IF_PCM_SLOT2_CTL0);

	if (dir) { /* rx */
		cfg &= ~(LPA_IF_PCM_RPCM_SLOT_COUNT_MASK);
		cfg |= LPA_IF_PCM_RPCM_SLOT_COUNT(slot_count - 1); /* 0 based */
	} else { /* tx */
		cfg &= ~(LPA_IF_PCM_TPCM_SLOT_COUNT_MASK);
		cfg |= LPA_IF_PCM_TPCM_SLOT_COUNT(slot_count - 1); /* 0 based */
	}

	writel(cfg, dai_info.base + LPA_IF_PCM_SLOT2_CTL0);
	return 0;
}
EXPORT_SYMBOL(ipq_cfg_pcm_active_slot_count);

int ipq_cfg_pcm_tx_active_slot(uint32_t slot, uint32_t val)
{
	uint32_t cfg;

	switch (slot) {
	case LPA_IF_TPCM_SLOT0:
		cfg = readl(dai_info.base + LPA_IF_PCM_0);
		cfg = (cfg & ~(LPA_IF_TPCM_SLOT_MASK)) |
			LPA_IF_PCM_TPCM_SLOT(val);
		writel(cfg, dai_info.base + LPA_IF_PCM_0);
		break;
	case LPA_IF_TPCM_SLOT1:
		cfg = readl(dai_info.base + LPA_IF_PCM_SLOT_CTL0);
		cfg = ((cfg & ~(LPA_IF_PCM_TPCM_SLOT1_MASK)) |
				LPA_IF_PCM_TPCM_SLOT1(val));
		writel(cfg, dai_info.base + LPA_IF_PCM_SLOT_CTL0);
		break;
	case LPA_IF_TPCM_SLOT2:
		cfg = readl(dai_info.base + LPA_IF_PCM_SLOT2_CTL0);
		cfg = ((cfg & ~(LPA_IF_PCM_TPCM_SLOT2_MASK)) |
				LPA_IF_PCM_TPCM_SLOT2(val));
		writel(cfg, dai_info.base + LPA_IF_PCM_SLOT2_CTL0);
		break;
	case LPA_IF_TPCM_SLOT3:
		cfg = readl(dai_info.base + LPA_IF_PCM_SLOT2_CTL0);
		cfg = ((cfg & ~(LPA_IF_PCM_TPCM_SLOT3_MASK)) |
				LPA_IF_PCM_TPCM_SLOT3(val));
		writel(cfg, dai_info.base + LPA_IF_PCM_SLOT2_CTL0);
		break;
	default:
		return -EINVAL;
	}
	return 0;
}
EXPORT_SYMBOL(ipq_cfg_pcm_tx_active_slot);

int ipq_cfg_pcm_rx_active_slot(uint32_t slot, uint32_t val)
{
	uint32_t cfg;

	switch (slot) {
	case LPA_IF_RPCM_SLOT0:
		cfg = readl(dai_info.base + LPA_IF_PCM_0);
		cfg = ((cfg & ~(LPA_IF_RPCM_SLOT_MASK)) |
			(LPA_IF_PCM_RPCM_SLOT(val)));
		writel(cfg, dai_info.base + LPA_IF_PCM_0);
		break;
	case LPA_IF_RPCM_SLOT1:
		cfg = readl(dai_info.base + LPA_IF_PCM_SLOT_CTL0);
		cfg = ((cfg & ~(LPA_IF_PCM_RPCM_SLOT1_MASK)) |
			(LPA_IF_PCM_RPCM_SLOT1(val)));
		writel(cfg, dai_info.base + LPA_IF_PCM_SLOT_CTL0);
		break;
	case LPA_IF_RPCM_SLOT2:
		cfg = readl(dai_info.base + LPA_IF_PCM_SLOT_CTL0);
		cfg = ((cfg & ~(LPA_IF_PCM_RPCM_SLOT2_MASK)) |
			(LPA_IF_PCM_RPCM_SLOT2(val)));
		writel(cfg, dai_info.base + LPA_IF_PCM_SLOT_CTL0);
		break;
	case LPA_IF_RPCM_SLOT3:
		cfg = readl(dai_info.base + LPA_IF_PCM_SLOT_CTL0);
		cfg = ((cfg & ~(LPA_IF_PCM_RPCM_SLOT3_MASK)) |
			(LPA_IF_PCM_RPCM_SLOT3(val)));
		writel(cfg, dai_info.base + LPA_IF_PCM_SLOT_CTL0);
		break;
	default:
		return -EINVAL;
	}
	return 0;
}
EXPORT_SYMBOL(ipq_cfg_pcm_rx_active_slot);

void ipq_pcm_start(void)
{
	reset_control_deassert(lpaif_blk_rst);
}
EXPORT_SYMBOL(ipq_pcm_start);

void ipq_pcm_stop(void)
{
	reset_control_assert(lpaif_blk_rst);
}
EXPORT_SYMBOL(ipq_pcm_stop);

void ipq_cfg_mi2s_disable(uint32_t off)
{
	writel(0, dai_info.base + LPAIF_MI2S_CTL_OFFSET(off));
}
EXPORT_SYMBOL(ipq_cfg_mi2s_disable);

void ipq_cfg_i2s_spkr(uint8_t enable, uint32_t mode, uint32_t off)
{
	uint32_t cfg;
	unsigned long flags;

	spin_lock_irqsave(&dai_lock, flags);

	cfg = readl(dai_info.base + LPAIF_MI2S_CTL_OFFSET(off));

	if (enable)
		cfg |= LPA_IF_SPK_EN;
	else
		cfg = cfg & (~(LPA_IF_SPK_EN));

	cfg |= (mode << LPA_IF_SPK_MODE);
	cfg = cfg & ~LPA_IF_WS;

	writel(cfg, dai_info.base + LPAIF_MI2S_CTL_OFFSET(off));
	spin_unlock_irqrestore(&dai_lock, flags);
}
EXPORT_SYMBOL(ipq_cfg_i2s_spkr);

void ipq_cfg_i2s_mic(uint8_t enable, uint32_t off)
{
	uint32_t cfg;
	unsigned long flags;

	spin_lock_irqsave(&dai_lock, flags);

	cfg = readl(dai_info.base + LPAIF_MI2S_CTL_OFFSET(off));

	if (enable)
		cfg |= LPA_IF_MIC_EN;
	else
		cfg = cfg & (~(LPA_IF_MIC_EN));

	cfg = cfg & ~LPA_IF_WS;

	writel(cfg, dai_info.base + LPAIF_MI2S_CTL_OFFSET(off));
	spin_unlock_irqrestore(&dai_lock, flags);
}
EXPORT_SYMBOL(ipq_cfg_i2s_mic);

int ipq_cfg_mi2s_hwparams_bit_width(uint32_t bit_width, uint32_t off)
{
	int ret = 0;
	uint32_t cfg;
	unsigned long flags;

	spin_lock_irqsave(&dai_lock, flags);

	cfg = readl(dai_info.base + LPAIF_MI2S_CTL_OFFSET(off));
	cfg &= ~(LPA_IF_BIT_MASK);

	switch (bit_width) {
	case SNDRV_PCM_FORMAT_S16:
		cfg |= LPA_IF_BIT_RATE16;
		break;
	case SNDRV_PCM_FORMAT_S24:
		cfg |= LPA_IF_BIT_RATE24;
		break;
	case SNDRV_PCM_FORMAT_S32:
		cfg |= LPA_IF_BIT_RATE32;
		break;
	default:
		ret = -EINVAL;
		break;
	}

	if (!ret)
		writel(cfg, dai_info.base + LPAIF_MI2S_CTL_OFFSET(off));

	spin_unlock_irqrestore(&dai_lock, flags);
	return ret;
}
EXPORT_SYMBOL(ipq_cfg_mi2s_hwparams_bit_width);

int ipq_cfg_mi2s_playback_hwparams_channels(uint32_t channels, uint32_t off,
						uint32_t bit_width)
{
	int ret = 0;
	uint32_t cfg;
	unsigned long flags;

	spin_lock_irqsave(&dai_lock, flags);

	cfg = readl(dai_info.base + LPAIF_MI2S_CTL_OFFSET(off));
	cfg &= ~(LPA_IF_SPK_MODE_MASK);

	switch (channels) {
	case IPQ_CHANNELS_STEREO:
		cfg |= LPA_IF_SPK_MODE_SD0;
		break;
	case IPQ_CHANNELS_4:
		cfg |= LPA_IF_SPK_MODE_QUAD01;
		break;
	case IPQ_CHANNELS_6:
		cfg |= LPA_IF_SPK_MODE_6CH;
		break;
	case IPQ_CHANNELS_8:
		cfg |= LPA_IF_SPK_MODE_8CH;
		break;
	default:
		ret = -EINVAL;
		break;
	}

	if (!ret)
		writel(cfg, dai_info.base + LPAIF_MI2S_CTL_OFFSET(off));

	spin_unlock_irqrestore(&dai_lock, flags);

	return ret;
}
EXPORT_SYMBOL(ipq_cfg_mi2s_playback_hwparams_channels);

int ipq_cfg_mi2s_capture_hwparams_channels(uint32_t channels, uint32_t off,
						uint32_t bit_width)
{
	uint32_t cfg;
	int ret = 0;
	unsigned long flags;

	spin_lock_irqsave(&dai_lock, flags);

	cfg = readl(dai_info.base + LPAIF_MI2S_CTL_OFFSET(off));
	cfg &= ~(LPA_IF_MIC_MODE_MASK);

	switch (channels) {
	case IPQ_CHANNELS_STEREO:
		cfg |= LPA_IF_MIC_MODE_SD3;
		break;
	default:
		ret = -EINVAL;
		break;
	}

	if (!ret)
		writel(cfg, dai_info.base + LPAIF_MI2S_CTL_OFFSET(off));

	spin_unlock_irqrestore(&dai_lock, flags);

	return ret;
}
EXPORT_SYMBOL(ipq_cfg_mi2s_capture_hwparams_channels);

int ipq_lpaif_dai_config_dma(uint32_t dma_ch)
{
	if (dma_ch >= MAX_LPAIF_CHANNELS)
		return -EINVAL;

	writel(dai[dma_ch]->buffer_phys,
			dai_info.base + LPA_IF_DMA_BASE_ADDR(dma_ch));
	writel(((dai[dma_ch]->buffer_len >> 2) - 1),
			dai_info.base + LPA_IF_DMA_BUFF_LEN(dma_ch));
	writel(((dai[dma_ch]->period_len >> 2) - 1),
			dai_info.base + LPA_IF_DMA_PER_LEN(dma_ch));
	mb(); /* ensure the hardware sees the change */

	return 0;
}
EXPORT_SYMBOL(ipq_lpaif_dai_config_dma);

void ipq_lpaif_disable_dma(uint32_t dma_ch)
{
	unsigned long flag;

	spin_lock_irqsave(&dai_lock, flag);
	writel(0x0, dai_info.base + LPA_IF_DMACTL(dma_ch));
	spin_unlock_irqrestore(&dai_lock, flag);
}
EXPORT_SYMBOL(ipq_lpaif_disable_dma);

static void ipq_lpaif_dai_disable_codec(uint32_t dma_ch, int codec)
{
	uint32_t intr_val;
	unsigned long flag;

	spin_lock_irqsave(&dai_lock, flag);

	intr_val = readl(dai_info.base + LPAIF_MI2S_CTL_OFFSET(codec));

	if (codec == DAI_SPKR)
		intr_val = intr_val & ~(LPA_IF_SPK_EN);
	else if (codec == DAI_MIC)
		intr_val = intr_val & ~(LPA_IF_MIC_EN);

	writel(intr_val, dai_info.base + LPAIF_MI2S_CTL_OFFSET(codec));
	writel(0x0, dai_info.base + LPA_IF_DMACTL(dma_ch));

	spin_unlock_irqrestore(&dai_lock, flag);
}

int ipq_lpaif_dai_open(uint32_t dma_ch)
{
	if (!dai_info.base) {
		pr_debug("%s: %d: failed as no DAI device\n",
					__func__, __LINE__);
		return -ENODEV;
	}

	if (dma_ch >= MAX_LPAIF_CHANNELS) {
		pr_debug("%s over max channesl %d\n", __func__, dma_ch);
		return -ENODEV;
	}
	return 0;
}

void ipq_lpaif_dai_close(uint32_t dma_ch)
{
	if ((dma_ch >= MIN_DMA_RD_CH) && (dma_ch < MIN_DMA_WR_CH))
		ipq_lpaif_dai_disable_codec(dma_ch, DAI_SPKR);
	else
		ipq_lpaif_dai_disable_codec(dma_ch, DAI_MIC);
}

void ipq_lpaif_dai_set_master_mode(uint32_t dma_ch, int mode)
{
	if (dma_ch < MAX_LPAIF_CHANNELS)
		dai[dma_ch]->master_mode = mode;
	else
		pr_err("%s: %d:invalid dma channel\n", __func__, __LINE__);
}

static int ipq_cfg_lpaif_dma_ch(uint32_t lpaif_dma_ch, uint32_t channels,
							uint32_t bit_width)
{
	int ret = 0;
	uint32_t cfg;
	unsigned long flags;

	if (lpaif_dma_ch >= MAX_LPAIF_CHANNELS)
		return -EINVAL;

	spin_lock_irqsave(&dai_lock, flags);

	cfg = readl(dai_info.base + LPA_IF_DMACTL(lpaif_dma_ch));

	if ((lpaif_dma_ch == PCM0_DMA_WR_CH) ||
		(lpaif_dma_ch == PCM0_DMA_RD_CH)) {
		cfg &= LPA_IF_DMACTL_AUDIO_INTF_MASK;
		cfg |= LPA_IF_DMACTL_AUDIO_INTF_PCM;
	} else if ((lpaif_dma_ch == MI2S_DMA_RD_CH) ||
			(lpaif_dma_ch == MI2S_DMA_WR_CH)) {
		cfg |= LPA_IF_DMACTL_AUDIO_INTF_MI2S;
		cfg &= ~(LPA_IF_DMACTL_WPSCNT_MASK);

		if ((bit_width == __BIT_16) &&
			(channels == IPQ_CHANNELS_STEREO))
			cfg |= LPA_IF_DMACTL_WPSCNT_MONO;
		else if (((bit_width == __BIT_16) &&
			(channels == IPQ_CHANNELS_4)) ||
			(((bit_width == __BIT_24) || (bit_width == __BIT_32))
					&& (channels == IPQ_CHANNELS_STEREO)))
			cfg |= LPA_IF_DMACTL_WPSCNT_STEREO;
		else if ((bit_width == __BIT_16) &&
			(channels == IPQ_CHANNELS_6))
			cfg |= LPA_IF_DMACTL_WPSCNT_3CH;
		else if (((bit_width == __BIT_16) &&
			(channels == IPQ_CHANNELS_8)) ||
			(((bit_width == __BIT_32) || (bit_width == __BIT_24)) &&
			(channels == IPQ_CHANNELS_4)))
			cfg |= LPA_IF_DMACTL_WPSCNT_4CH;
		else if (((bit_width == __BIT_24) || (bit_width == __BIT_32)) &&
			(channels == IPQ_CHANNELS_6))
			cfg |= LPA_IF_DMACTL_WPSCNT_6CH;
		else if	(((bit_width == __BIT_24) || (bit_width == __BIT_32)) &&
			(channels == IPQ_CHANNELS_8))
			cfg |= LPA_IF_DMACTL_WPSCNT_8CH;
		else
			ret = -EINVAL;
	}

	if (!ret)
		writel(cfg, dai_info.base + LPA_IF_DMACTL(lpaif_dma_ch));

	spin_unlock_irqrestore(&dai_lock, flags);
	return ret;
}

int ipq_lpaif_cfg_dma(uint32_t dma_ch, struct dai_dma_params *params,
		uint32_t bit_width, bool enable_intr)
{
	int ret;
	uint32_t cfg;

	dai[dma_ch]->buffer = params->buffer;
	dai[dma_ch]->buffer_phys = params->src_start;
	dai[dma_ch]->channels = params->channels;
	dai[dma_ch]->buffer_len = params->buffer_size;
	dai[dma_ch]->period_len = params->period_size;

	ret = ipq_lpaif_dai_config_dma(dma_ch);
	if (ret)
		return ret;

	if (enable_intr)
		ipq_pcm_int_enable(dma_ch);

	ret = ipq_cfg_lpaif_dma_ch(dma_ch, params->channels, bit_width);
	if (ret) {
		ipq_pcm_int_disable(dma_ch);
		return ret;
	}

	cfg = readl(dai_info.base + LPA_IF_DMACTL(dma_ch));
	cfg |= (LPA_IF_DMACTL_FIFO_WM_8 |
			LPA_IF_DMACTL_BURST_EN);
	writel(cfg, dai_info.base + LPA_IF_DMACTL(dma_ch));

	cfg = readl(dai_info.base + LPA_IF_DMACTL(dma_ch));
	cfg |= LPA_IF_DMACTL_ENABLE;
	writel(cfg, dai_info.base + LPA_IF_DMACTL(dma_ch));

	return 0;
}
EXPORT_SYMBOL(ipq_lpaif_cfg_dma);

int ipq_lpaif_dai_stop(uint32_t dma_ch)
{
	writel(0x0, dai_info.base + LPA_IF_DMACTL(dma_ch));
	return 0;
}
EXPORT_SYMBOL(ipq_lpaif_dai_stop);

int ipq_lpaif_pcm_stop(uint32_t dma_ch)
{
	unsigned long flags;

	spin_lock_irqsave(&dai_lock, flags);
	writel(0x0, dai_info.base + LPAIF_IRQ_EN(0));
	writel(~0x0, dai_info.base + LPAIF_IRQ_CLEAR(0));
	writel(0x0, dai_info.base + LPA_IF_DMACTL(dma_ch));
	spin_unlock_irqrestore(&dai_lock, flags);
	return 0;
}
EXPORT_SYMBOL(ipq_lpaif_pcm_stop);

uint8_t ipq_lpaif_dma_stop(uint8_t dma_ch)
{
	uint32_t cfg;

	cfg = readl(dai_info.base + LPA_IF_DMACTL(dma_ch));
	cfg &= ~(LPA_IF_DMACTL_ENABLE);
	writel(cfg, dai_info.base + LPA_IF_DMACTL(dma_ch));
	return 0;
}
EXPORT_SYMBOL(ipq_lpaif_dma_stop);

uint8_t ipq_lpaif_dma_start(uint8_t dma_ch)
{
	uint32_t cfg;

	cfg = readl(dai_info.base + LPA_IF_DMACTL(dma_ch));
	cfg |= LPA_IF_DMACTL_ENABLE;
	writel(cfg, dai_info.base + LPA_IF_DMACTL(dma_ch));
	return 0;
}
EXPORT_SYMBOL(ipq_lpaif_dma_start);

uint8_t ipq_lpaif_irq_disable(uint8_t dma_ch)
{
	uint32_t cfg;
	unsigned long flags;

	spin_lock_irqsave(&dai_lock, flags);
	cfg = readl(dai_info.base + LPAIF_IRQ_EN(0));
	cfg &= ~((1 << (dma_ch * 3)));
	writel(cfg, dai_info.base + LPAIF_IRQ_EN(0));
	cfg = (1 << (dma_ch * 3));
	writel(cfg, dai_info.base + LPAIF_IRQ_CLEAR(0));
	spin_unlock_irqrestore(&dai_lock, flags);
	return 0;
}
EXPORT_SYMBOL(ipq_lpaif_irq_disable);

uint8_t ipq_lpaif_mi2s_disable(void)
{
	writel(0x0, dai_info.base + LPAIF_MI2S_CTL_OFFSET(LPA_IF_MI2S));
	return 0;
}
EXPORT_SYMBOL(ipq_lpaif_mi2s_disable);

void ipq_lpaif_register_dma_irq_handler(int dma_ch,
	irqreturn_t (*callback)(int intrsrc, void *private_data),
	void *private_data)
{
	dai[dma_ch]->callback = callback;
	dai[dma_ch]->private_data = private_data;
}
EXPORT_SYMBOL(ipq_lpaif_register_dma_irq_handler);

void ipq_lpaif_unregister_dma_irq_handler(int dma_ch)
{
	dai[dma_ch]->callback = NULL;
	dai[dma_ch]->private_data = NULL;
}
EXPORT_SYMBOL(ipq_lpaif_unregister_dma_irq_handler);

/*
 * Logic to find the dma channel from interrupt.
 * In total we have 9 channels, each channel records the transcation
 * status. Either one of ths 3 status will be recorded per transcation
 * (PER_CH,UNDER_RUN,OVER_RUN)
 */
static int dai_find_dma_channel(uint32_t intrsrc)
{
	uint32_t dma_channel = 0;

	while (dma_channel < MAX_LPAIF_CHANNELS) {
		if (intrsrc & (0x1 << (dma_channel * 3)))
			return dma_channel;

		dma_channel++;
	}

	return -1;
}

/*
 * ISR for handling LPA_IF interrupts.
 */
static irqreturn_t dai_irq_handler(int irq, void *data)
{
	unsigned long flag;
	uint32_t intrsrc;
	uint32_t dma_ch;
	irqreturn_t ret = IRQ_NONE;

	spin_lock_irqsave(&dai_lock, flag);
	intrsrc = readl(dai_info.base + LPAIF_IRQ_STAT(0));
	writel(intrsrc, dai_info.base + LPAIF_IRQ_CLEAR(0));
	spin_unlock_irqrestore(&dai_lock, flag);
	mb(); /* ensure the hardware sees the change */
	while (intrsrc) {
		dma_ch = dai_find_dma_channel(intrsrc);
		if (dma_ch != -1) {
			if (dai[dma_ch]->callback) {

				ret = dai[dma_ch]->callback(intrsrc,
					dai[dma_ch]->private_data);
			}
			intrsrc &= ~(0x1 << (dma_ch * 3));
		} else {
			pr_err("%s: %d:error getting channel\n",
					__func__, __LINE__);
			break;
		}
	}
	return ret;
}

static void ipq_lpaif_dai_ch_free(void)
{
	int i;

	for (i = 0; i < MAX_LPAIF_CHANNELS; i++)
		kfree(dai[i]);
}

static const struct of_device_id ipq_lpaif_match_table[] = {
	{ .compatible = "qca,ipq806x-lpaif" },
	{},
};

static int ipq_lpaif_dai_probe(struct platform_device *pdev)
{
	uint8_t i;
	int32_t rc;
	struct resource *lpa_res;
	struct device *lpaif_device;
	const struct of_device_id *match;

	match = of_match_device(ipq_lpaif_match_table, &pdev->dev);
	if (!match)
		return -ENODEV;

	lpaif_device = &pdev->dev;

	lpa_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!lpa_res) {
		dev_err(&pdev->dev, "%s: %d:error getting resource\n",
				__func__, __LINE__);
		return -ENODEV;
	}
	dai_info.base = devm_ioremap_resource(&pdev->dev, lpa_res);
	if (!dai_info.base) {
		dev_err(&pdev->dev, "%s: %d:error remapping resource\n",
				__func__, __LINE__);
		return -ENOMEM;
	}

	dai_info.irq = platform_get_irq(pdev, 0);
	if (dai_info.irq < 0) {
		dev_err(&pdev->dev, "%s: lpaif IRQ %d is not provided\n",
						__func__, dai_info.irq);
		rc = -ENODEV;
		goto error;
	}

	rc = devm_request_irq(&pdev->dev, dai_info.irq, dai_irq_handler, 0,
				"ipq806x-lpaif", NULL);
	if (rc) {
		dev_err(&pdev->dev, "request_irq() failed with ret: %d\n", rc);
		goto error;
	}

	lpaif_pcm_bit_clk = devm_clk_get(&pdev->dev, "pcm_bit_clk");
	if (IS_ERR(lpaif_pcm_bit_clk)) {
		dev_err(&pdev->dev, "%s: %d: cannot get PCM bit clock\n",
				__func__, __LINE__);
		rc = -EINVAL;
		goto error_irq;
	}

	lpaif_blk_rst = devm_reset_control_get(&pdev->dev, "lcc_pcm_reset");
	if (IS_ERR(lpaif_blk_rst)) {
		rc = -EINVAL;
		goto error_irq;
	}

	/*
	 * Allocating memory for all the LPA_IF DMA channels
	 */
	for (i = 0; i < MAX_LPAIF_CHANNELS; i++) {
		dai[i] = kzalloc(sizeof(struct dai_drv), GFP_KERNEL);
		if (!dai[i]) {
			dev_err(&pdev->dev, "%s: %d:ch allocation failed\n",
					__func__, __LINE__);
			rc = -ENOMEM;
			goto error_mem;
		}
	}
	spin_lock_init(&dai_lock);
	return 0;
error_mem:
	clk_put(lpaif_pcm_bit_clk);
	ipq_lpaif_dai_ch_free();
error_irq:
	devm_free_irq(&pdev->dev, dai_info.irq, NULL);
error:
	iounmap(dai_info.base);
	return rc;
}

static int ipq_lpaif_dai_remove(struct platform_device *pdev)
{
	devm_free_irq(&pdev->dev, dai_info.irq, NULL);
	iounmap(dai_info.base);
	ipq_lpaif_dai_ch_free();
	return 0;
}

#define DRIVER_NAME "ipq806x-lpaif"

static struct platform_driver ipq_lpaif_driver = {
	.probe		= ipq_lpaif_dai_probe,
	.remove		= ipq_lpaif_dai_remove,
	.driver		= {
		.name		= DRIVER_NAME,
		.of_match_table	= ipq_lpaif_match_table,
	},
};

module_platform_driver(ipq_lpaif_driver);

MODULE_DESCRIPTION("IPQ LPA_IF Driver");
MODULE_LICENSE("Dual BSD/GPL");
