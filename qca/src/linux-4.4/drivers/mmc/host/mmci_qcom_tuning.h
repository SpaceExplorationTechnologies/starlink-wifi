 /*
 * Copyright (c) 2015, The Linux Foundation. All rights reserved.
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

#ifndef __MMCI_QCOM_TUNING_H_
#define __MMCI_QCOM_TUNING_H_

#define SPS_SDCC_PRODUCER_PIPE_INDEX	1
#define SPS_SDCC_CONSUMER_PIPE_INDEX	2
#define SPS_CONS_PERIPHERAL		0
#define SPS_PROD_PERIPHERAL		1
/* Use SPS only if transfer size is more than this macro */
#define SPS_MIN_XFER_SIZE		MCI_FIFOSIZE

#define INVALID_TUNING_PHASE		-1

#define q_caps(h)			((h)->variant->qcom_hw_caps)
#define set_hw_caps(h, val)		(q_caps(h) |= val)
#define is_sps_mode(h)			(q_caps(h) & MMCIQ_SPS_BAM_SUP)
#define is_dma_mode(h)			(q_caps(h) & MMCIQ_DMA_SUP)
#define is_soft_reset(h)		(q_caps(h) & MMCIQ_SOFT_RESET)
#define is_auto_prog_done(h)		(q_caps(h) & MMCIQ_AUTO_PROG_DONE)
#define is_wait_for_reg_write(h)	(q_caps(h) & MMCIQ_REG_WR_ACTIVE)
#define is_sw_hard_reset(h)		(q_caps(h) & MMCIQ_SW_RST)
#define is_sw_reset_save_config(h)	(q_caps(h) & MMCIQ_SW_RST_CFG)
#define is_wait_for_tx_rx_active(h)	(q_caps(h) & MMCIQ_WAIT_FOR_TX_RX)
#define is_io_pad_pwr_switch(h)		(q_caps(h) & MMCIQ_IO_PAD_PWR_SWITCH)

#define MMCIQ_VERSION_STEP_MASK		0x0000FFFF
#define MMCIQ_VERSION_MINOR_MASK	0x0FFF0000
#define MMCIQ_VERSION_MINOR_SHIFT	16
#define MMCIQ_DMA_SUP			(1 << 0)
#define MMCIQ_SPS_BAM_SUP		(1 << 1)
#define MMCIQ_SOFT_RESET		(1 << 2)
#define MMCIQ_AUTO_PROG_DONE		(1 << 3)
#define MMCIQ_REG_WR_ACTIVE		(1 << 4)
#define MMCIQ_SW_RST			(1 << 5)
#define MMCIQ_SW_RST_CFG		(1 << 6)
#define MMCIQ_WAIT_FOR_TX_RX		(1 << 7)
#define MMCIQ_IO_PAD_PWR_SWITCH		(1 << 8)

int mmci_qtune_execute_tuning(struct mmc_host *mmc, u32 opcode);
void set_default_hw_caps(struct mmci_host *host);
void mmci_qcom_ddr_tuning(struct mmci_host *host);
int mmci_qcom_set_uhs_gpio(struct mmc_host *mmc, unsigned int val);
int mmci_qtune_init(struct mmci_host *host, struct device_node *np);
int mmci_enable_cdr_cm_sdc4_dll(struct mmci_host *host);

#endif /* __MMCI_QCOM_TUNING_H_ */
