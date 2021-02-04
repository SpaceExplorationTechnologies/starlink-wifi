/*
 *  linux/drivers/mmc/host/msm_sdcc.c - Qualcomm MSM 7X00A SDCC Driver
 *
 *  Copyright (C) 2007 Google Inc,
 *  Copyright (C) 2003 Deep Blue Solutions, Ltd, All Rights Reserved.
 *  Copyright (c) 2009-2012, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Based on mmci.c
 *
 * Author: San Mehat (san@android.com)
 *
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/ioport.h>
#include <linux/device.h>
#include <linux/io.h>
#include <linux/interrupt.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/err.h>
#include <linux/highmem.h>
#include <linux/log2.h>
#include <linux/mmc/pm.h>
#include <linux/mmc/host.h>
#include <linux/mmc/card.h>
#include <linux/mmc/sdio.h>
#include <linux/mmc/mmc.h>
#include <linux/mmc/slot-gpio.h>
#include <linux/amba/bus.h>
#include <linux/clk.h>
#include <linux/scatterlist.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/regulator/consumer.h>
#include <linux/dmaengine.h>
#include <linux/dma-mapping.h>
#include <linux/amba/mmci.h>
#include <linux/pm_runtime.h>
#include <linux/types.h>
#include <linux/pinctrl/consumer.h>

#include <asm/div64.h>
#include <linux/io.h>
#include <linux/sizes.h>

#include "mmci.h"
#include "mmci_qcom_tuning.h"

#define DBG(host, fmt, args...)	\
	pr_debug("%s: %s: " fmt "\n", mmc_hostname(host->mmc), __func__ , args)

#define IRQ_DEBUG 0

/*
 * An array holding the Tuning pattern to compare with when
 * executing a tuning cycle.
 */
static const u32 tuning_block_64[] = {
	0x00FF0FFF, 0xCCC3CCFF, 0xFFCC3CC3, 0xEFFEFFFE,
	0xDDFFDFFF, 0xFBFFFBFF, 0xFF7FFFBF, 0xEFBDF777,
	0xF0FFF0FF, 0x3CCCFC0F, 0xCFCC33CC, 0xEEFFEFFF,
	0xFDFFFDFF, 0xFFBFFFDF, 0xFFF7FFBB, 0xDE7B7FF7
};

static const u32 tuning_block_128[] = {
	0xFF00FFFF, 0x0000FFFF, 0xCCCCFFFF, 0xCCCC33CC,
	0xCC3333CC, 0xFFFFCCCC, 0xFFFFEEFF, 0xFFEEEEFF,
	0xFFDDFFFF, 0xDDDDFFFF, 0xBBFFFFFF, 0xBBFFFFFF,
	0xFFFFFFBB, 0xFFFFFF77, 0x77FF7777, 0xFFEEDDBB,
	0x00FFFFFF, 0x00FFFFFF, 0xCCFFFF00, 0xCC33CCCC,
	0x3333CCCC, 0xFFCCCCCC, 0xFFEEFFFF, 0xEEEEFFFF,
	0xDDFFFFFF, 0xDDFFFFFF, 0xFFFFFFDD, 0xFFFFFFBB,
	0xFFFFBBBB, 0xFFFF77FF, 0xFF7777FF, 0xEEDDBB77
};

static inline void mmci_qtune_sync_reg_wr(struct mmci_host *host)
{
	mb();
	if (!is_wait_for_reg_write(host))
		udelay(100);
	else if (readl_relaxed(host->base + MMCISTATUS2) &
			MCI_MCLK_REG_WR_ACTIVE) {
		ktime_t start, diff;

		start = ktime_get();
		while (readl_relaxed(host->base + MMCISTATUS2) &
				MCI_MCLK_REG_WR_ACTIVE) {
			diff = ktime_sub(ktime_get(), start);
			/* poll for max. 1 ms */
			if (ktime_to_us(diff) > 1000) {
				pr_warn("%s: previous reg. write is still active\n",
						mmc_hostname(host->mmc));
				break;
			}
		}
	}
}

static inline void mmci_qtune_cm_sdc4_dll_set_freq(struct mmci_host *host)
{
	u32 mclk_freq = 0;

	/* Program the MCLK value to MCLK_FREQ bit field */
	if (host->mclk <= 112000000)
		mclk_freq = 0;
	else if (host->mclk <= 125000000)
		mclk_freq = 1;
	else if (host->mclk <= 137000000)
		mclk_freq = 2;
	else if (host->mclk <= 150000000)
		mclk_freq = 3;
	else if (host->mclk <= 162000000)
		mclk_freq = 4;
	else if (host->mclk <= 175000000)
		mclk_freq = 5;
	else if (host->mclk <= 187000000)
		mclk_freq = 6;
	else if (host->mclk <= 200000000)
		mclk_freq = 7;

	writel_relaxed(((readl_relaxed(host->base + MCIDLL_CONFIG)
			& ~(7 << 24)) | (mclk_freq << 24)),
			host->base + MCIDLL_CONFIG);
}

/* Initialize the DLL (Programmable Delay Line ) */
static int mmci_qtune_init_cm_sdc4_dll(struct mmci_host *host)
{
	int rc = 0;
	unsigned long flags;
	u32 wait_cnt;

	spin_lock_irqsave(&host->lock, flags);
	/*
	 * Make sure that clock is always enabled when DLL
	 * tuning is in progress. Keeping PWRSAVE ON may
	 * turn off the clock. So let's disable the PWRSAVE
	 * here and re-enable it once tuning is completed.
	 */
	writel_relaxed((readl_relaxed(host->base + MMCICLOCK)
			& ~MCI_CLK_PWRSAVE), host->base + MMCICLOCK);
	mmci_qtune_sync_reg_wr(host);

	/* Write 1 to DLL_RST bit of MCIDLL_CONFIG register */
	writel_relaxed((readl_relaxed(host->base + MCIDLL_CONFIG)
			| MCI_DLL_RST), host->base + MCIDLL_CONFIG);

	/* Write 1 to DLL_PDN bit of MCIDLL_CONFIG register */
	writel_relaxed((readl_relaxed(host->base + MCIDLL_CONFIG)
			| MCI_DLL_PDN), host->base + MCIDLL_CONFIG);

	mmci_qtune_cm_sdc4_dll_set_freq(host);

	/* Write 0 to DLL_RST bit of MCIDLL_CONFIG register */
	writel_relaxed((readl_relaxed(host->base + MCIDLL_CONFIG)
			& ~MCI_DLL_RST), host->base + MCIDLL_CONFIG);

	/* Write 0 to DLL_PDN bit of MCIDLL_CONFIG register */
	writel_relaxed((readl_relaxed(host->base + MCIDLL_CONFIG)
			& ~MCI_DLL_PDN), host->base + MCIDLL_CONFIG);

	/* Set DLL_EN bit to 1. */
	writel_relaxed((readl_relaxed(host->base + MCIDLL_CONFIG)
			| MCI_DLL_EN), host->base + MCIDLL_CONFIG);

	/* Set CK_OUT_EN bit to 1. */
	writel_relaxed((readl_relaxed(host->base + MCIDLL_CONFIG)
			| MCI_CK_OUT_EN), host->base + MCIDLL_CONFIG);

	wait_cnt = 50;
	/* Wait until DLL_LOCK bit of MCI_DLL_STATUS register becomes '1' */
	while (!(readl_relaxed(host->base + MCI_DLL_STATUS) & MCI_DLL_LOCK)) {
		/* max. wait for 50us sec for LOCK bit to be set */
		if (--wait_cnt == 0) {
			pr_err("%s: %s: DLL failed to LOCK\n",
				mmc_hostname(host->mmc), __func__);
			rc = -ETIMEDOUT;
			goto out;
		}
		/* wait for 1us before polling again */
		udelay(1);
	}

out:
	spin_unlock_irqrestore(&host->lock, flags);

	return rc;
}

static inline int mmci_qtune_dll_poll_ck_out_en(struct mmci_host *host,
						u8 poll)
{
	int rc = 0;
	u32 wait_cnt = 200;
	u8 ck_out_en = 0;

	/* poll for MCI_CK_OUT_EN bit.  max. poll time = 50us */
	ck_out_en = !!(readl_relaxed(host->base + MCIDLL_CONFIG) &
			MCI_CK_OUT_EN);

	while (ck_out_en != poll) {
		if (--wait_cnt == 0) {
			pr_err("%s: %s: CK_OUT_EN bit is not %d\n",
				mmc_hostname(host->mmc), __func__, poll);
			rc = -ETIMEDOUT;
			goto out;
		}
		udelay(1);

		ck_out_en = !!(readl_relaxed(host->base + MCIDLL_CONFIG) &
			MCI_CK_OUT_EN);
	}
out:
	return rc;
}

static int mmci_qtune_config_cm_sdc4_dll_phase(struct mmci_host *host,
						u8 phase)
{
	int rc = 0;
	u8 grey_coded_phase_table[] = {0x0, 0x1, 0x3, 0x2, 0x6, 0x7, 0x5, 0x4,
					0xC, 0xD, 0xF, 0xE, 0xA, 0xB, 0x9,
					0x8};
	unsigned long flags;
	u32 config;

	if (!host)
		return -EINVAL;

	spin_lock_irqsave(&host->lock, flags);

	config = readl_relaxed(host->base + MCIDLL_CONFIG);
	config &= ~(MCI_CDR_EN | MCI_CK_OUT_EN);
	config |= (MCI_CDR_EXT_EN | MCI_DLL_EN);
	writel_relaxed(config, host->base + MCIDLL_CONFIG);

	/* Wait until CK_OUT_EN bit of MCIDLL_CONFIG register becomes '0' */
	rc = mmci_qtune_dll_poll_ck_out_en(host, 0);
	if (rc)
		goto err_out;

	if (phase >= ARRAY_SIZE(grey_coded_phase_table)) {
		pr_warn("%s: out of bound access - grey_coded_phase_table[%d]\n",
				__func__, phase);
		return -EINVAL;
	}

	/*
	 * Write the selected DLL clock output phase (0 ... 15)
	 * to CDR_SELEXT bit field of MCIDLL_CONFIG register.
	 */
	writel_relaxed(((readl_relaxed(host->base + MCIDLL_CONFIG)
					& ~(0xF << 20))
				| (grey_coded_phase_table[phase] << 20)),
			host->base + MCIDLL_CONFIG);
	/* Set CK_OUT_EN bit of MCIDLL_CONFIG register to 1. */
	writel_relaxed((readl_relaxed(host->base + MCIDLL_CONFIG)
			| MCI_CK_OUT_EN), host->base + MCIDLL_CONFIG);

	/* Wait until CK_OUT_EN bit of MCIDLL_CONFIG register becomes '1' */
	rc = mmci_qtune_dll_poll_ck_out_en(host, 1);
	if (rc)
		goto err_out;

	config = readl_relaxed(host->base + MCIDLL_CONFIG);
	config |= MCI_CDR_EN;
	config &= ~MCI_CDR_EXT_EN;
	writel_relaxed(config, host->base + MCIDLL_CONFIG);
	goto out;

err_out:
	pr_err("%s: %s: Failed to set DLL phase: %d\n",
		mmc_hostname(host->mmc), __func__, phase);
out:
	spin_unlock_irqrestore(&host->lock, flags);
	return rc;
}

#define MAX_DLL_PHASE 15

static int find_phase_window(struct mmci_host *host, u8 *phase_window)
{
	int i, j, longest_window_index, selected_phase;
	/*
	 * extending windows to allow cyclic windows (such as phase 13
	 * to phase 2)
	 */
	for (i = 0; i < (MAX_DLL_PHASE + 1); i++)
		phase_window[(MAX_DLL_PHASE + 1) + i] = phase_window[i];

	/* for every possible window end point */
	j = 0;
	for (i = (2 * (MAX_DLL_PHASE + 1)) - 1; i >= 0; i--) {
		/* add to windows size or start a new window */
		if (phase_window[i] > 0)
			j++;
		else
			j = 0;
		/* record for each window */
		phase_window[i] = j;
	}

	/* find longest window */
	longest_window_index = 0;
	for (i = 1; i < (MAX_DLL_PHASE + 1); i++) {
		if (phase_window[i] > phase_window[longest_window_index])
			longest_window_index = i;
	}

	if (phase_window[longest_window_index] < 1) {
		/* failed to find a valid window */
		pr_err("%s: %s: Tuning can't find a valid window\n",
				mmc_hostname(host->mmc), __func__);
		return -EINVAL;
	}

	/* Select the phase at the 3/4 mark of the widest window: */
	selected_phase = longest_window_index +
		((3 * (phase_window[longest_window_index]) - 1) >> 2);
	if (selected_phase > MAX_DLL_PHASE)
		selected_phase -= (MAX_DLL_PHASE+1);

	return selected_phase;
}

/*
 * Find out the greatest range of consecuitive selected
 * DLL clock output phases that can be used as sampling
 * setting for SD3.0 UHS-I card read operation (in SDR104
 * timing mode) or for eMMC4.5 card read operation (in HS200
 * timing mode).
 * Select the 3/4 of the range and configure the DLL with the
 * selected DLL clock output phase.
*/
static int find_most_appropriate_phase(struct mmci_host *host,
				u8 *phase_table, u8 total_phases)
{
	#define MAX_PHASES 16
	int ret;
	u8 ranges[MAX_PHASES][MAX_PHASES] = { {0}, {0} };
	u8 phases_per_row[MAX_PHASES] = {0};
	int row_index = 0, col_index = 0, selected_row_index = 0, curr_max = 0;
	int i, cnt, phase_0_raw_index = 0, phase_15_raw_index = 0;
	bool phase_0_found = false, phase_15_found = false;

	if (!total_phases || (total_phases > MAX_PHASES)) {
		pr_err("%s: %s: invalid argument: total_phases=%d\n",
			mmc_hostname(host->mmc), __func__, total_phases);
		return -EINVAL;
	}

	for (cnt = 0; cnt < total_phases; cnt++) {
		ranges[row_index][col_index] = phase_table[cnt];
		phases_per_row[row_index] += 1;
		col_index++;

		if ((cnt + 1) == total_phases) {
			continue;
		/* check if next phase in phase_table is consecutive or not */
		} else if ((phase_table[cnt] + 1) != phase_table[cnt + 1]) {
			row_index++;
			col_index = 0;
		}
	}

	if (row_index >= MAX_PHASES)
		return -EINVAL;

	/* Check if phase-0 is present in first valid window? */
	if (!ranges[0][0]) {
		phase_0_found = true;
		phase_0_raw_index = 0;
		/* Check if cycle exist between 2 valid windows */
		for (cnt = 1; cnt <= row_index; cnt++) {
			if (phases_per_row[cnt]) {
				for (i = 0; i < phases_per_row[cnt]; i++) {
					if (ranges[cnt][i] == 15) {
						phase_15_found = true;
						phase_15_raw_index = cnt;
						break;
					}
				}
			}
		}
	}

	/* If 2 valid windows form cycle then merge them as single window */
	if (phase_0_found && phase_15_found) {
		/* number of phases in raw where phase 0 is present */
		u8 phases_0 = phases_per_row[phase_0_raw_index];
		/* number of phases in raw where phase 15 is present */
		u8 phases_15 = phases_per_row[phase_15_raw_index];

		if (phases_0 + phases_15 >= MAX_PHASES)
			/*
			 * If there are more than 1 phase windows then total
			 * number of phases in both the windows should not be
			 * more than or equal to MAX_PHASES.
			 */
			return -EINVAL;

		/* Merge 2 cyclic windows */
		i = phases_15;
		for (cnt = 0; cnt < phases_0; cnt++) {
			ranges[phase_15_raw_index][i] =
				ranges[phase_0_raw_index][cnt];
			if (++i >= MAX_PHASES)
				break;
		}

		phases_per_row[phase_0_raw_index] = 0;
		phases_per_row[phase_15_raw_index] = phases_15 + phases_0;
	}

	for (cnt = 0; cnt <= row_index; cnt++) {
		if (phases_per_row[cnt] > curr_max) {
			curr_max = phases_per_row[cnt];
			selected_row_index = cnt;
		}
	}

	i = ((curr_max * 3) / 4);
	if (i)
		i--;

	ret = (int)ranges[selected_row_index][i];

	if (ret >= MAX_PHASES) {
		ret = -EINVAL;
		pr_err("%s: %s: invalid phase selected=%d\n",
			mmc_hostname(host->mmc), __func__, ret);
	}

	return ret;
}

/*
 * Enable a CDR circuit in CM_SDC4_DLL block to enable automatic
 * calibration sequence. This function should be called before
 * enabling AUTO_CMD19 bit in MCI_CMD register for block read
 * commands (CMD17/CMD18).
 *
 * This function gets called when host spinlock acquired.
 */
int mmci_enable_cdr_cm_sdc4_dll(struct mmci_host *host)
{
	int rc;
	u32 config;

	config = readl_relaxed(host->base + MCIDLL_CONFIG);
	config |= MCI_CDR_EN;
	config |= MCI_CDR_EXT_EN;
	config &= ~MCI_CK_OUT_EN;
	writel_relaxed(config, host->base + MCIDLL_CONFIG);

	/* Wait until CK_OUT_EN bit of MCI_DLL_CONFIG register becomes '0' */
	rc = mmci_qtune_dll_poll_ck_out_en(host, 0);
	if (rc) {
		pr_err("%s: %s: sdc4_dll config failed\n",
		       mmc_hostname(host->mmc), __func__);
		return rc;
	}

	/* Set CK_OUT_EN bit of MCI_DLL_CONFIG register to 1. */
	writel_relaxed((readl_relaxed(host->base + MCIDLL_CONFIG)
			| MCI_CK_OUT_EN), host->base + MCIDLL_CONFIG);

	/* Wait until CK_OUT_EN bit of MCI_DLL_CONFIG register becomes '1' */
	rc = mmci_qtune_dll_poll_ck_out_en(host, 1);
	if (rc)
		goto err_out;

	goto out;

err_out:
	pr_err("%s: %s: Enabling sdc4_dll failed\n",
	       mmc_hostname(host->mmc), __func__);
out:
	return rc;
}


int mmci_qtune_execute_tuning(struct mmc_host *mmc, u32 opcode)
{
	int rc = 0;
	struct mmci_host *host = mmc_priv(mmc);
	unsigned long	flags;
	u8 phase, *data_buf, tuned_phases[(MAX_DLL_PHASE+1)*2] = {0};
	u8 tuned_phase_cnt = 0;
	const u32 *tuning_block_pattern = tuning_block_64;
	int size = sizeof(tuning_block_64); /* Tuning pattern size in bytes */
	bool is_tuning_all_phases;

	pr_debug("%s: Enter %s\n", mmc_hostname(mmc), __func__);

	spin_lock_irqsave(&host->lock, flags);

	host->variant->tuning_in_progress = 1;

	if ((opcode == MMC_SEND_TUNING_BLOCK_HS200) &&
		(mmc->ios.bus_width == MMC_BUS_WIDTH_8)) {
		tuning_block_pattern = tuning_block_128;
		size = sizeof(tuning_block_128);
	}
	spin_unlock_irqrestore(&host->lock, flags);

	/* first of all reset the tuning block */
	rc = mmci_qtune_init_cm_sdc4_dll(host);
	if (rc)
		goto out;

	data_buf = kmalloc(size, GFP_KERNEL);
	if (!data_buf) {
		rc = -ENOMEM;
		goto out;
	}

	is_tuning_all_phases = !(host->mmc->card &&
		(host->variant->saved_tuning_phase != INVALID_TUNING_PHASE));
retry:
	if (is_tuning_all_phases)
		phase = 0; /* start from phase 0 during init */
	else
		phase = (u8)host->variant->saved_tuning_phase;
	do {
		struct mmc_command cmd = {0};
		struct mmc_data data = {0};
		struct mmc_request mrq = {
			.cmd = &cmd,
			.data = &data
		};
		struct scatterlist sg;

		/* set the phase in delay line hw block */
		rc = mmci_qtune_config_cm_sdc4_dll_phase(host, phase);
		if (rc)
			goto kfree;

		cmd.opcode = opcode;
		cmd.flags = MMC_RSP_R1 | MMC_CMD_ADTC;

		data.blksz = size;
		data.blocks = 1;
		data.flags = MMC_DATA_READ;
		data.timeout_ns = 1000 * 1000 * 1000; /* 1 sec */

		data.sg = &sg;
		data.sg_len = 1;
		sg_init_one(&sg, data_buf, size);
		memset(data_buf, 0, size);
		mmc_wait_for_req(mmc, &mrq);

		if (!cmd.error && !data.error &&
			!memcmp(data_buf, tuning_block_pattern, size)) {
			/* tuning is successful at this tuning point */
			if (!is_tuning_all_phases)
				goto kfree;
			tuned_phases[tuned_phase_cnt++] = phase;
			pr_debug("%s: %s: found good phase = %d\n",
				mmc_hostname(mmc), __func__, phase);
		} else if (!is_tuning_all_phases) {
			pr_debug("%s: tuning failed at saved phase (%d), retrying\n",
					mmc_hostname(mmc), (u32)phase);
			is_tuning_all_phases = true;
			goto retry;
		}
	} while (++phase < 16);

	if (tuned_phase_cnt) {
		if (gpio_is_valid(host->variant->qcom_uhs_gpio)) {
			rc = find_phase_window(host, tuned_phases);
		} else {
			rc = find_most_appropriate_phase(host, tuned_phases,
					tuned_phase_cnt);
		}

		if (rc < 0)
			goto kfree;
		else
			phase = (u8)rc;

		/*
		 * Finally set the selected phase in delay
		 * line hw block.
		 */
		rc = mmci_qtune_config_cm_sdc4_dll_phase(host, phase);
		if (rc)
			goto kfree;
		else
			host->variant->saved_tuning_phase = phase;
		pr_debug("%s: %s: finally setting the tuning phase to %d\n",
				mmc_hostname(mmc), __func__, phase);
	} else {
		/* tuning failed */
		pr_debug("%s: %s: no tuning point found\n",
			mmc_hostname(mmc), __func__);
		rc = -EAGAIN;
	}

kfree:
	kfree(data_buf);
out:
	spin_lock_irqsave(&host->lock, flags);
	host->variant->tuning_in_progress = 0;
	if (!rc)
		host->variant->tuning_done = true;
	spin_unlock_irqrestore(&host->lock, flags);
	pr_debug("%s: Exit %s\n", mmc_hostname(mmc), __func__);
	return rc;
}

void mmci_qcom_ddr_tuning(struct mmci_host *host)
{
	/* Write 1 to DLL_RST bit of MCI_DLL_CONFIG register */
	writel_relaxed((readl_relaxed(host->base +
			MCIDLL_CONFIG) | MCI_DLL_RST),
			host->base + MCIDLL_CONFIG);

	/* Write 1 to DLL_PDN bit of MCI_DLL_CONFIG register */
	writel_relaxed((readl_relaxed(host->base +
			MCIDLL_CONFIG) | MCI_DLL_PDN),
			host->base + MCIDLL_CONFIG);

}

int mmci_qcom_set_uhs_gpio(struct mmc_host *mmc, unsigned int val)
{
	struct mmci_host *host = mmc_priv(mmc);
	unsigned long flags = 0;
	int rc = 0;

	spin_lock_irqsave(&host->lock, flags);

	/* Stop SD CLK output. */
	writel_relaxed((readl_relaxed(host->base + MMCICLOCK) |
			MCI_CLK_PWRSAVE), host->base + MMCICLOCK);
	udelay(30);

	spin_unlock_irqrestore(&host->lock, flags);

	/*
	 * Switch VDD Io from high voltage range (2.7v - 3.6v) to
	 * low voltage range (1.7v - 1.95v).
	 */
	rc = gpio_direction_output(host->variant->qcom_uhs_gpio, val);
	if (rc) {
		pr_err("gpio direction failed\n");
		gpio_free(host->variant->qcom_uhs_gpio);
		rc = -EAGAIN;
		goto out;
	}
	spin_lock_irqsave(&host->lock, flags);
	writel_relaxed((readl_relaxed(host->base + MMCICLOCK)
			| MCI_QCOM_IO_PAD_PWR_SWITCH), host->base
			+ MMCICLOCK);
	spin_unlock_irqrestore(&host->lock, flags);

	/* Wait 5 ms for the voltage regulater in the card to become stable. */
	usleep_range(5000, 5500);

out:
	spin_lock_irqsave(&host->lock, flags);
	/* Disable PWRSAVE would make sure that SD CLK is always running */
	writel_relaxed((readl_relaxed(host->base + MMCICLOCK)
			& ~MCI_CLK_PWRSAVE), host->base + MMCICLOCK);
	udelay(30);
	spin_unlock_irqrestore(&host->lock, flags);

	/*
	 * If MCIDATIN_3_0 and MCICMDIN bits of MCI_TEST_INPUT register
	 * don't become all ones within 1 ms then a Voltage Switch
	 * sequence has failed and a power cycle to the card is required.
	 * Otherwise Voltage Switch sequence is completed successfully.
	 */
	usleep_range(1000, 1500);

	return rc;
}

void set_default_hw_caps(struct mmci_host *host)
{
	u32 version;
	u16 step, minor;

	/*
	 * Lookup the Controller Version, to identify the supported features
	 * Version number read as 0 would indicate SDCC3 or earlier versions.
	 */
	version = readl_relaxed(host->base + MMCIVERSION);
	pr_info("%s: SDCC Version: 0x%.8x\n", mmc_hostname(host->mmc), version);

	if (!version)
		return;

	step = version & MMCIQ_VERSION_STEP_MASK;
	minor = (version & MMCIQ_VERSION_MINOR_MASK) >>
		MMCIQ_VERSION_MINOR_SHIFT;

	if (version) /* SDCC v4 and greater */
		q_caps(host) |= MMCIQ_AUTO_PROG_DONE |
			MMCIQ_SOFT_RESET | MMCIQ_REG_WR_ACTIVE
			| MMCIQ_WAIT_FOR_TX_RX | MMCIQ_IO_PAD_PWR_SWITCH;

	if ((step == 0x18) && (minor >= 3))
		/* Version 0x06000018 need hard reset on errors */
		q_caps(host) &= ~MMCIQ_SOFT_RESET;

	if (step >= 0x2b) /* SDCC v4 2.1.0 and greater */
		q_caps(host) |= MMCIQ_SW_RST | MMCIQ_SW_RST_CFG;
}

int mmci_qtune_init(struct mmci_host *host, struct device_node *np)
{
	uint32_t gpio;

	if (of_property_read_u32(np, "qcom-uhs-gpio", &gpio))
		host->variant->qcom_uhs_gpio = -1;
	else
		host->variant->qcom_uhs_gpio = gpio;

	set_default_hw_caps(host);

	host->variant->saved_tuning_phase = INVALID_TUNING_PHASE;

	return 0;
}

