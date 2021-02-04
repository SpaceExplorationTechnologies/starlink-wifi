/* Copyright (c) 2012-2013,2015,2017, The Linux Foundation. All rights reserved.
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
 *
 */

#include <linux/init.h>
#include <linux/err.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/time.h>
#include <linux/wait.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/string.h>
#include <linux/platform_device.h>
#include <linux/of_device.h>
#include "ipq806x-pcm.h"

/*
 * This is an external loopback test module for PCM interface.
 * For this to work, the Rx and Tx should be shorted in the
 * SLIC header.
 * This test module exposes a sysfs interface to start\stop the
 * tests. This module sends a sequence of numbers starting from
 * 0 to 255 and wraps around to 0 and continues the sequence.
 * The received data is then compared for the sequence. Any errors
 * found are reported immediately. When test stop, a final statistics
 * of how much passed and failed is displayed.
 */

/* the test configurations supported */
#define PCM_LBTEST_8BIT_8KHZ_2CH_TX_TO_RX	1
#define PCM_LBTEST_8BIT_8KHZ_2CH_RX_TO_TX	101
#define PCM_LBTEST_16BIT_16KHZ_2CH_TX_TO_RX	2
#define PCM_LBTEST_16BIT_16KHZ_2CH_RX_TO_TX	201
#define PCM_LBTEST_16BIT_8KHZ_4CH_TX_TO_RX	3
#define PCM_LBTEST_16BIT_8KHZ_4CH_RX_TO_TX	301

#define PCM_LBTEST_CFG_MAX_DIG_COUNT		4

#define IS_PCM_LBTEST_RX_TO_TX(config)					\
		((config == PCM_LBTEST_8BIT_8KHZ_2CH_RX_TO_TX) ||	\
		(config == PCM_LBTEST_16BIT_16KHZ_2CH_RX_TO_TX) ||	\
		(config == PCM_LBTEST_16BIT_8KHZ_4CH_RX_TO_TX))

#define LOOPBACK_SKIP_COUNT		10
#define LOOPBACK_FAIL_THRESHOLD		200
struct pcm_lb_test_ctx {
	uint32_t failed;
	uint32_t passed;
	unsigned char *last_rx_buff;
	int running;
	unsigned char tx_data;
	unsigned char expected_rx_seq;
	int read_count;
	struct task_struct *task;
};

static struct pcm_lb_test_ctx ctx;
static unsigned long int start;
static void pcm_start_test(void);

static ssize_t show_pcm_lb_value(struct device_driver *driver,
						char *buff)
{
	return snprintf(buff, PCM_LBTEST_CFG_MAX_DIG_COUNT, "%ld", start);
}

static ssize_t store_pcm_lb_value(struct device_driver *driver,
				const char *buff, size_t count)
{
	if (kstrtoul(buff, 0, &start)) {
		pr_err("%s: invalid lb value\n", __func__);
		return -EINVAL;
	}
	pcm_start_test();
	return count;
}

static DRIVER_ATTR(pcmlb, 0644, show_pcm_lb_value, store_pcm_lb_value);

static int pcm_lb_drv_attr_init(struct platform_device *pdev)
{
	return driver_create_file(pdev->dev.driver, &driver_attr_pcmlb);
}

static void pcm_lb_drv_attr_deinit(struct platform_device *pdev)
{
	driver_remove_file(pdev->dev.driver, &driver_attr_pcmlb);
}

static uint32_t pcm_read_write(void)
{
	char *rx_buff;
	char *tx_buff;
	uint32_t i;
	uint32_t size;

	size = ipq806x_pcm_data(&rx_buff, &tx_buff);
	ctx.last_rx_buff = rx_buff;

	if (IS_PCM_LBTEST_RX_TO_TX(start)) {
		/* Redirect Rx data to Tx */
		memcpy(tx_buff, rx_buff, size);
	} else {
		/* get current Tx buffer and write the pattern
		 * We will write 1, 2, 3, ..., 255, 1, 2, 3...
		 */
		for (i =  0; i < size; i++) {
			tx_buff[i] = ctx.tx_data;
			ctx.tx_data++;
		}
	}
	ipq806x_pcm_done();
	return size;
}

static uint32_t pcm_init(void)
{
	struct ipq_pcm_params  cfg_params;
	uint32_t ret = 0;

	switch (start) {
	case PCM_LBTEST_8BIT_8KHZ_2CH_TX_TO_RX:
	case PCM_LBTEST_8BIT_8KHZ_2CH_RX_TO_TX:
		cfg_params.bit_width = CHANNEL_BIT_WIDTH;
		cfg_params.rate = CHANNEL_SAMPLING_RATE;
		cfg_params.slot_count = NUM_PCM_SLOTS;
		cfg_params.active_slot_count = 1;
		cfg_params.rx_slots[0] = 0;
		cfg_params.tx_slots[0] = 0;
		ret = ipq806x_pcm_init(&cfg_params);
		break;

	case PCM_LBTEST_16BIT_16KHZ_2CH_TX_TO_RX:
	case PCM_LBTEST_16BIT_16KHZ_2CH_RX_TO_TX:
		cfg_params.bit_width = 16;
		cfg_params.rate = 16000;
		cfg_params.slot_count = 8;
		cfg_params.active_slot_count = 2;
		cfg_params.tx_slots[0] = 1;
		cfg_params.tx_slots[1] = 4;
		cfg_params.rx_slots[0] = 1;
		cfg_params.rx_slots[1] = 4;
		ret = ipq806x_pcm_init(&cfg_params);
		break;

	case PCM_LBTEST_16BIT_8KHZ_4CH_TX_TO_RX:
	case PCM_LBTEST_16BIT_8KHZ_4CH_RX_TO_TX:
		cfg_params.bit_width = 16;
		cfg_params.rate = 8000;
		cfg_params.slot_count = 16;
		cfg_params.active_slot_count = 4;
		cfg_params.tx_slots[0] = 0;
		cfg_params.tx_slots[1] = 1;
		cfg_params.tx_slots[2] = 8;
		cfg_params.tx_slots[3] = 9;
		cfg_params.rx_slots[0] = 0;
		cfg_params.rx_slots[1] = 1;
		cfg_params.rx_slots[2] = 8;
		cfg_params.rx_slots[3] = 9;
		ret = ipq806x_pcm_init(&cfg_params);
		break;

	default:
		ret = -EINVAL;
		pr_err("Unknown configuration\n");
	}

	return ret;
}

static void pcm_deinit(void)
{
	memset((void *)&ctx, 0, sizeof(ctx));
	start = 0;
	ipq806x_pcm_deinit();
}

static void process_read(uint32_t size)
{
	uint32_t index;
	static uint32_t continuous_failures;
	char data;

	ctx.read_count++;
	if (ctx.read_count  <= LOOPBACK_SKIP_COUNT) {
		/*
		 * As soon as do pcm init, the DMA would start. So the initial
		 * few rw till the 1st Rx is called will be 0's, so we skip
		 * 10 reads so that our loopback settles down.
		 * Note: our 1st loopback Tx is only after an RX is called.
		 */
		return;
	} else if (ctx.read_count == (LOOPBACK_SKIP_COUNT + 1)) {
		/*
		 * our loopback should have settled, so start looking for the
		 * sequence from here.
		 */
		ctx.expected_rx_seq = ctx.last_rx_buff[0];
	}

	/* get out if test stopped */
	if (start == 0)
		return;

	data = ctx.expected_rx_seq;
	for (index = 0; index < size; index++) {
		if (ctx.last_rx_buff[index] != (data)) {
			pr_err("Rx (%d) Failed at index %d: "
				"Expected : %d, Received : %d\n",
				ctx.read_count, index, data,
				ctx.last_rx_buff[index]);
			break;
		}
		data++;
	}

	if (index == size) {
		ctx.passed++;
		continuous_failures = 0;
	} else {
		ctx.failed++;
		continuous_failures++;
	}

	ctx.expected_rx_seq += size;

	/* Abort if there are more failures */
	if (continuous_failures >= LOOPBACK_FAIL_THRESHOLD) {
		pr_err("Aborting loopback test as there are %d continuous "
				"failures\n", continuous_failures);
		continuous_failures = 0;
		ctx.running = 0; /* stops test thread (current) */
	}
}

static int pcm_test_rw(void *data)
{
	struct sched_param param;
	uint32_t ret;
	uint32_t size;

	/*
	 * set test thread priority as 90, this is to align with what
	 * D2 VOIP stack does.
	 */

	param.sched_priority = 90;
	ret = sched_setscheduler(ctx.task, SCHED_FIFO, &param);
	if (ret)
		pr_err("%s : Error setting priority, error: %d\n",
						__func__, ret);

	ret = pcm_init();
	if (ret) {
		pr_err("Pcm init failed %dn", ret);
		return ret;
	}

	pr_notice("%s : Test thread started\n", __func__);
	ctx.running = 1;
	while (ctx.running) {
		size = pcm_read_write();
		if (!IS_PCM_LBTEST_RX_TO_TX(start))
			process_read(size);
	}
	pr_notice("%s : Test Thread stopped\n", __func__);
	/* for rx to tx loopback, we cnanot detect failures */
	if (!IS_PCM_LBTEST_RX_TO_TX(start))
		pr_notice("\nPassed : %d, Failed : %d\n",
				ctx.passed, ctx.failed);
	pcm_deinit();
	return 0;
}

static void pcm_start_test(void)
{
	pr_notice("%s : %ld\n", __func__, start);
	if (start) {
		if (ctx.running) {
			pr_notice("%s : Test already running\n", __func__);
		} else {
			ctx.task = kthread_create(&pcm_test_rw,
							NULL, "PCMTest");
			if (ctx.task)
				wake_up_process(ctx.task);
		}
	} else {
		if (ctx.running) {
			pr_notice("%s : Stopping test\n", __func__);
			ctx.running = 0;
			/* wait sufficient time for test thread to finish */
			mdelay(2000);
		} else
			pr_notice("%s : Test already stopped\n", __func__);
	}
}

int pcm_test_init(struct platform_device *pdev)
{
	return pcm_lb_drv_attr_init(pdev);
}

void pcm_test_exit(struct platform_device *pdev)
{
	pcm_lb_drv_attr_deinit(pdev);
	if (ctx.running) {
		ctx.running = 0;
		/* wait sufficient time for test thread to finish */
		mdelay(2000);
	}
}
