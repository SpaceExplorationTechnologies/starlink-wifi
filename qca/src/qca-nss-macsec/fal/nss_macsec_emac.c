/*
 * Copyright (c) 2014, The Linux Foundation. All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

//#include "osal_common.h"
#include "nss_macsec_types.h"
#include "nss_macsec_register_api.h"
#include "nss_macsec_utility.h"
#include "nss_macsec_secy.h"
#include "nss_macsec_emac.h"

#define RX_SEC_FULL_THRESHOLD     0x3B
#define TX_SEC_FULL_THRESHOLD     0x60
#define RX_ALMOST_EMPTY_THRESHOLD 0x8
#define RX_ALMOST_FULL_THRESHOLD  0x8
#define TX_ALMOST_EMPTY_THRESHOLD 0x8
#define TX_ALMOST_FULL_THRESHOLD  0x10

#define RX_MAX_EMAC_FRAME_LEN     0x3FFF
#define TX_MIN_EMAC_IPG           12

#define EG_ETHERNET_MAC_VALUE  0x6
#define IG_ETHERNET_MAC_VALUE  0x6

static void emac1_fifo_thresholds(u32 secy_id)
{
	union emac1_rx_section_full_u rx_sec_full;
	union emac1_tx_section_full_u tx_sec_full;
	union emac1_rx_almost_empty_u rx_almost_empty;
	union emac1_rx_almost_full_u rx_almost_full;
	union emac1_tx_almost_empty_u tx_almost_empty;
	union emac1_tx_almost_full_u tx_almost_full;

	/* Program a RX FIFO Section Full Threshold value */
	rx_sec_full.val = 0;
	rx_sec_full.bf.rx_section_full = RX_SEC_FULL_THRESHOLD;
	emac1_rx_section_full_set(secy_id, &rx_sec_full);

	/* Program a TX FIFO Section Full Threshold value */
	tx_sec_full.val = 0;
	tx_sec_full.bf.tx_section_full = TX_SEC_FULL_THRESHOLD;
	emac1_tx_section_full_set(secy_id, &tx_sec_full);

	/* Program a RX FIFO Almost Empty Threshold value */
	rx_almost_empty.val = 0;
	rx_almost_empty.bf.rx_almost_empty = RX_ALMOST_EMPTY_THRESHOLD;
	emac1_rx_almost_empty_set(secy_id, &rx_almost_empty);

	/* Program a RX FIFO Almost Full Threshold value */
	rx_almost_full.val = 0;
	rx_almost_full.bf.rx_almost_full = RX_ALMOST_FULL_THRESHOLD;
	emac1_rx_almost_full_set(secy_id, &rx_almost_full);

	/* Program a TX FIFO Almost Empty Threshold value */
	tx_almost_empty.val = 0;
	tx_almost_empty.bf.tx_almost_empty = TX_ALMOST_EMPTY_THRESHOLD;
	emac1_tx_almost_empty_set(secy_id, &tx_almost_empty);

	/* Program a TX FIFO Almost Full Threshold value */
	tx_almost_full.val = 0;
	tx_almost_full.bf.tx_almost_full = TX_ALMOST_FULL_THRESHOLD;
	emac1_tx_almost_full_set(secy_id, &tx_almost_full);

	return;
}

static void emac2_fifo_thresholds(u32 secy_id)
{
	union emac2_rx_section_full_u rx_sec_full;
	union emac2_tx_section_full_u tx_sec_full;
	union emac2_rx_almost_empty_u rx_almost_empty;
	union emac2_rx_almost_full_u rx_almost_full;
	union emac2_tx_almost_empty_u tx_almost_empty;
	union emac2_tx_almost_full_u tx_almost_full;

	/* Program a RX FIFO Section Full Threshold value */
	rx_sec_full.val = 0;
	rx_sec_full.bf.rx_section_full = RX_SEC_FULL_THRESHOLD;
	emac2_rx_section_full_set(secy_id, &rx_sec_full);

	/* Program a TX FIFO Section Full Threshold value */
	tx_sec_full.val = 0;
	tx_sec_full.bf.tx_section_full = TX_SEC_FULL_THRESHOLD;
	emac2_tx_section_full_set(secy_id, &tx_sec_full);

	/* Program a RX FIFO Almost Empty Threshold value */
	rx_almost_empty.val = 0;
	rx_almost_empty.bf.rx_almost_empty = RX_ALMOST_EMPTY_THRESHOLD;
	emac2_rx_almost_empty_set(secy_id, &rx_almost_empty);

	/* Program a RX FIFO Almost Full Threshold value */
	rx_almost_full.val = 0;
	rx_almost_full.bf.rx_almost_full = RX_ALMOST_FULL_THRESHOLD;
	emac2_rx_almost_full_set(secy_id, &rx_almost_full);

	/* Program a TX FIFO Almost Empty Threshold value */
	tx_almost_empty.val = 0;
	tx_almost_empty.bf.tx_almost_empty = TX_ALMOST_EMPTY_THRESHOLD;
	emac2_tx_almost_empty_set(secy_id, &tx_almost_empty);

	/* Program a TX FIFO Almost Full Threshold value */
	tx_almost_full.val = 0;
	tx_almost_full.bf.tx_almost_full = TX_ALMOST_FULL_THRESHOLD;
	emac2_tx_almost_full_set(secy_id, &tx_almost_full);

	return;
}

static u32 emac_config(u32 secy_id)
{
	union emac1_command_config_u emac1_val;
	union emac2_command_config_u emac2_val;
	union emac1_frm_length_u emac1_mtu;
	union emac2_frm_length_u emac2_mtu;
	union emac1_tx_ipg_length_u emac1_ipg;
	union emac2_tx_ipg_length_u emac2_ipg;
	int ret = 0;

	emac1_val.val = 0;
	emac1_val.bf.promis_en = 1;
	emac1_val.bf.pause_fwd = 1;
	emac1_val.bf.pause_ignore = 1;
	emac1_val.bf.rx_err_disc = 1;
	emac1_val.bf.cnt_reset = 1;
	ret = emac1_command_config_set(secy_id, &emac1_val);
	if (ret)
		return ERROR_ERROR;

	emac1_mtu.val = 0;
	emac1_mtu.bf.max_frame_length = RX_MAX_EMAC_FRAME_LEN;
	ret = emac1_frm_length_set(secy_id, &emac1_mtu);
	if (ret)
		return ERROR_ERROR;

	emac1_ipg.val = 0;
	emac1_ipg.bf.tx_ipg_length = TX_MIN_EMAC_IPG;
	ret = emac1_tx_ipg_length_set(secy_id, &emac1_ipg);
	if (ret)
		return ERROR_ERROR;

	emac2_val.val = 0;
	emac2_val.bf.promis_en = 1;
	emac2_val.bf.pause_fwd = 1;
	emac2_val.bf.pause_ignore = 1;
	emac2_val.bf.rx_err_disc = 1;
	emac2_val.bf.cnt_reset = 1;
	ret = emac2_command_config_set(secy_id, &emac2_val);
	if (ret)
		return ERROR_ERROR;

	emac2_mtu.val = 0;
	emac2_mtu.bf.max_frame_length = RX_MAX_EMAC_FRAME_LEN;
	ret = emac2_frm_length_set(secy_id, &emac2_mtu);
	if (ret)
		return ERROR_ERROR;

	emac2_ipg.val = 0;
	emac2_ipg.bf.tx_ipg_length = TX_MIN_EMAC_IPG;
	ret = emac2_tx_ipg_length_set(secy_id, &emac2_ipg);
	if (ret)
		return ERROR_ERROR;

	return ERROR_OK;
}

u32 nss_macsec_emac_init(u32 secy_id)
{
	emac1_fifo_thresholds(secy_id);
	emac2_fifo_thresholds(secy_id);

	return emac_config(secy_id);
}

u32 nss_macsec_speed(u32 secy_id, enum emac_link_speed speed)
{
	union emac1_command_config_u emac1_cfg;
	union emac2_command_config_u emac2_cfg;
	int ret = 0;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM));

	ret = emac1_command_config_get(secy_id, &emac1_cfg);
	if (ret)
		return ERROR_ERROR;
	ret = emac2_command_config_get(secy_id, &emac2_cfg);
	if (ret)
		return ERROR_ERROR;

	if (speed == SPEED10) {
		emac1_cfg.bf.ena_10 = 1;
		emac1_cfg.bf.eth_speed = 0;
		emac2_cfg.bf.ena_10 = 1;
		emac2_cfg.bf.eth_speed = 0;
	} else if (speed == SPEED100) {
		emac1_cfg.bf.ena_10 = 0;
		emac1_cfg.bf.eth_speed = 0;
		emac2_cfg.bf.ena_10 = 0;
		emac2_cfg.bf.eth_speed = 0;

	} else {
		emac1_cfg.bf.ena_10 = 0;
		emac1_cfg.bf.eth_speed = 1;
		emac2_cfg.bf.ena_10 = 0;
		emac2_cfg.bf.eth_speed = 1;
	}

	ret = emac1_command_config_set(secy_id, &emac1_cfg);
	if (ret)
		return ERROR_ERROR;
	ret = emac2_command_config_set(secy_id, &emac2_cfg);
	if (ret)
		return ERROR_ERROR;

	return ERROR_OK;
}

u32 nss_macsec_emac_enable(u32 secy_id, BOOL enable)
{
	union emac1_command_config_u emac1_cfg;
	union emac2_command_config_u emac2_cfg;
	int ret = 0;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM));

	emac1_cfg.val = 0;
	emac2_cfg.val = 0;

	ret = emac1_command_config_get(secy_id, &emac1_cfg);
	if (ret)
		return ERROR_ERROR;
	ret = emac2_command_config_get(secy_id, &emac2_cfg);
	if (ret)
		return ERROR_ERROR;

	if (enable) {
		emac1_cfg.bf.tx_ena = 1;
		emac1_cfg.bf.rx_ena = 1;
		emac2_cfg.bf.tx_ena = 1;
		emac2_cfg.bf.rx_ena = 1;
	} else {
		emac1_cfg.bf.tx_ena = 0;
		emac1_cfg.bf.rx_ena = 0;
		emac2_cfg.bf.tx_ena = 0;
		emac2_cfg.bf.rx_ena = 0;
	}

	ret = emac1_command_config_set(secy_id, &emac1_cfg);
	if (ret)
		return ERROR_ERROR;
	ret = emac2_command_config_set(secy_id, &emac2_cfg);
	if (ret)
		return ERROR_ERROR;

	return ERROR_OK;
}

u32 nss_macsec_emac_reset(u32 secy_id)
{
	union emac1_command_config_u emac1_cfg;
	union emac2_command_config_u emac2_cfg;
	int ret = 0;

	SHR_PARAM_CHECK((secy_id < FAL_SECY_ID_NUM));

	emac1_cfg.val = 0;
	emac2_cfg.val = 0;

	ret = emac1_command_config_get(secy_id, &emac1_cfg);
	if (ret)
		return ERROR_ERROR;
	ret = emac2_command_config_get(secy_id, &emac2_cfg);
	if (ret)
		return ERROR_ERROR;

	emac1_cfg.bf.sw_reset = 1;

	emac2_cfg.bf.sw_reset = 1;

	ret = emac1_command_config_set(secy_id, &emac1_cfg);
	if (ret)
		return ERROR_ERROR;
	ret = emac2_command_config_set(secy_id, &emac2_cfg);
	if (ret)
		return ERROR_ERROR;

	return ERROR_OK;
}
