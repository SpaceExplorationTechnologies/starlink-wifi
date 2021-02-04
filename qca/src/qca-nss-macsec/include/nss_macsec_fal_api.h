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

#ifndef _NSS_MACSEC_FAL_API_H_
#define _NSS_MACSEC_FAL_API_H_

#include "nss_macsec_emac.h"
#include "nss_macsec_interrupt.h"
#include "nss_macsec.h"
#include "nss_macsec_mib.h"
#include "nss_macsec_secy.h"
#include "nss_macsec_secy_rx.h"
#include "nss_macsec_secy_tx.h"

enum {
	NSS_MACSEC_SECY_INTERRUPT_EN_GET_CMD,
	NSS_MACSEC_SECY_INTERRUPT_EN_SET_CMD,
	NSS_MACSEC_SECY_INTERRUPT_GET_CMD,
	NSS_MACSEC_EMAC_INIT_CMD,
	NSS_MACSEC_SPEED_CMD,
	NSS_MACSEC_EMAC_ENABLE_CMD,
	NSS_MACSEC_EMAC_RESET_CMD,
	NSS_MACSEC_SECY_TX_SC_MIB_GET_CMD,
	NSS_MACSEC_SECY_TX_SA_MIB_GET_CMD,
	NSS_MACSEC_SECY_TX_MIB_GET_CMD,
	NSS_MACSEC_SECY_RX_SA_MIB_GET_CMD,
	NSS_MACSEC_SECY_RX_MIB_GET_CMD,
	NSS_MACSEC_SECY_TX_MIB_CLEAR_CMD,
	NSS_MACSEC_SECY_TX_SC_MIB_CLEAR_CMD,
	NSS_MACSEC_SECY_TX_SA_MIB_CLEAR_CMD,
	NSS_MACSEC_SECY_RX_MIB_CLEAR_CMD,
	NSS_MACSEC_SECY_RX_SA_MIB_CLEAR_CMD,
	NSS_MACSEC_SECY_RX_REG_GET_CMD,
	NSS_MACSEC_SECY_RX_REG_SET_CMD,
	NSS_MACSEC_SECY_RX_CTL_FILT_GET_CMD,
	NSS_MACSEC_SECY_RX_CTL_FILT_SET_CMD,
	NSS_MACSEC_SECY_RX_CTL_FILT_CLEAR_CMD,
	NSS_MACSEC_SECY_RX_CTL_FILT_CLEAR_ALL_CMD,
	NSS_MACSEC_SECY_RX_PRC_LUT_GET_CMD,
	NSS_MACSEC_SECY_RX_PRC_LUT_SET_CMD,
	NSS_MACSEC_SECY_RX_PRC_LUT_CLEAR_CMD,
	NSS_MACSEC_SECY_RX_PRC_LUT_CLEAR_ALL_CMD,
	NSS_MACSEC_SECY_RX_SC_CREATE_CMD,
	NSS_MACSEC_SECY_RX_SC_EN_GET_CMD,
	NSS_MACSEC_SECY_RX_SC_EN_SET_CMD,
	NSS_MACSEC_SECY_RX_SC_DEL_CMD,
	NSS_MACSEC_SECY_RX_SC_DEL_ALL_CMD,
	NSS_MACSEC_SECY_RX_SC_VALIDATE_FRAME_GET_CMD,
	NSS_MACSEC_SECY_RX_SC_VALIDATE_FRAME_SET_CMD,
	NSS_MACSEC_SECY_RX_SC_REPLAY_PROTECT_GET_CMD,
	NSS_MACSEC_SECY_RX_SC_REPLAY_PROTECT_SET_CMD,
	NSS_MACSEC_SECY_RX_SC_ANTI_REPLAY_WINDOW_GET_CMD,
	NSS_MACSEC_SECY_RX_SC_ANTI_REPLAY_WINDOW_SET_CMD,
	NSS_MACSEC_SECY_RX_SC_IN_USED_GET_CMD,
	NSS_MACSEC_SECY_RX_SC_AN_ROLL_OVER_GET_CMD,
	NSS_MACSEC_SECY_RX_SC_AN_ROLL_OVER_SET_CMD,
	NSS_MACSEC_SECY_RX_SC_START_STOP_TIME_GET_CMD,
	NSS_MACSEC_SECY_RX_SC_START_STOP_TIME_SET_CMD,
	NSS_MACSEC_SECY_RX_SA_CREATE_CMD,
	NSS_MACSEC_SECY_RX_SA_EN_GET_CMD,
	NSS_MACSEC_SECY_RX_SA_EN_SET_CMD,
	NSS_MACSEC_SECY_RX_SA_NEXT_PN_GET_CMD,
	NSS_MACSEC_SECY_RX_SA_DEL_CMD,
	NSS_MACSEC_SECY_RX_SA_DEL_ALL_CMD,
	NSS_MACSEC_SECY_RX_SAK_GET_CMD,
	NSS_MACSEC_SECY_RX_SAK_SET_CMD,
	NSS_MACSEC_SECY_RX_SA_IN_USED_GET_CMD,
	NSS_MACSEC_SECY_RX_SA_START_STOP_TIME_GET_CMD,
	NSS_MACSEC_SECY_RX_SA_START_STOP_TIME_SET_CMD,
	NSS_MACSEC_SECY_RX_PN_THRESHOLD_GET_CMD,
	NSS_MACSEC_SECY_RX_PN_THRESHOLD_SET_CMD,
	NSS_MACSEC_SECY_RX_REPLAY_PROTECT_GET_CMD,
	NSS_MACSEC_SECY_RX_REPLAY_PROTECT_SET_CMD,
	NSS_MACSEC_SECY_RX_VALIDATE_FRAME_GET_CMD,
	NSS_MACSEC_SECY_RX_VALIDATE_FRAME_SET_CMD,
	NSS_MACSEC_SECY_TX_REG_GET_CMD,
	NSS_MACSEC_SECY_TX_REG_SET_CMD,
	NSS_MACSEC_SECY_TX_DROP_SC_SA_INVLID_GET_CMD,
	NSS_MACSEC_SECY_TX_DROP_SC_SA_INVLID_SET_CMD,
	NSS_MACSEC_SECY_TX_UNMATCHED_USE_SC_0_GET_CMD,
	NSS_MACSEC_SECY_TX_UNMATCHED_USE_SC_0_SET_CMD,
	NSS_MACSEC_SECY_TX_GCM_START_GET_CMD,
	NSS_MACSEC_SECY_TX_GCM_START_SET_CMD,
	NSS_MACSEC_SECY_TX_DROP_CLASS_MISS_GET_CMD,
	NSS_MACSEC_SECY_TX_DROP_CLASS_MISS_SET_CMD,
	NSS_MACSEC_SECY_TX_DROP_KAY_PKT_GET_CMD,
	NSS_MACSEC_SECY_TX_DROP_KAY_PKT_SET_CMD,
	NSS_MACSEC_SECY_TX_CTL_FILT_GET_CMD,
	NSS_MACSEC_SECY_TX_CTL_FILT_SET_CMD,
	NSS_MACSEC_SECY_TX_CTL_FILT_CLEAR_CMD,
	NSS_MACSEC_SECY_TX_CTL_FILT_CLEAR_ALL_CMD,
	NSS_MACSEC_SECY_TX_CLASS_LUT_GET_CMD,
	NSS_MACSEC_SECY_TX_CLASS_LUT_SET_CMD,
	NSS_MACSEC_SECY_TX_CLASS_LUT_CLEAR_CMD,
	NSS_MACSEC_SECY_TX_CLASS_LUT_CLEAR_ALL_CMD,
	NSS_MACSEC_SECY_TX_SC_CREATE_CMD,
	NSS_MACSEC_SECY_TX_SC_EN_GET_CMD,
	NSS_MACSEC_SECY_TX_SC_EN_SET_CMD,
	NSS_MACSEC_SECY_TX_SC_DEL_CMD,
	NSS_MACSEC_SECY_TX_SC_DEL_ALL_CMD,
	NSS_MACSEC_SECY_TX_SC_AN_GET_CMD,
	NSS_MACSEC_SECY_TX_SC_AN_SET_CMD,
	NSS_MACSEC_SECY_TX_SC_AN_ROLL_OVER_EN_GET_CMD,
	NSS_MACSEC_SECY_TX_SC_AN_ROLL_OVER_EN_SET_CMD,
	NSS_MACSEC_SECY_TX_SC_IN_USED_GET_CMD,
	NSS_MACSEC_SECY_TX_SC_TCI_7_2_GET_CMD,
	NSS_MACSEC_SECY_TX_SC_TCI_7_2_SET_CMD,
	NSS_MACSEC_SECY_TX_SC_CONFIDENTIALITY_OFFSET_GET_CMD,
	NSS_MACSEC_SECY_TX_SC_CONFIDENTIALITY_OFFSET_SET_CMD,
	NSS_MACSEC_SECY_TX_SC_PROTECT_GET_CMD,
	NSS_MACSEC_SECY_TX_SC_PROTECT_SET_CMD,
	NSS_MACSEC_SECY_TX_SC_SCI_GET_CMD,
	NSS_MACSEC_SECY_TX_SC_START_STOP_TIME_GET_CMD,
	NSS_MACSEC_SECY_TX_SC_START_STOP_TIME_SET_CMD,
	NSS_MACSEC_SECY_TX_SA_CREATE_CMD,
	NSS_MACSEC_SECY_TX_SA_EN_GET_CMD,
	NSS_MACSEC_SECY_TX_SA_EN_SET_CMD,
	NSS_MACSEC_SECY_TX_SA_DEL_CMD,
	NSS_MACSEC_SECY_TX_SA_DEL_ALL_CMD,
	NSS_MACSEC_SECY_TX_SA_NEXT_PN_GET_CMD,
	NSS_MACSEC_SECY_TX_SA_NEXT_PN_SET_CMD,
	NSS_MACSEC_SECY_TX_SA_IN_USED_GET_CMD,
	NSS_MACSEC_SECY_TX_SA_START_STOP_TIME_GET_CMD,
	NSS_MACSEC_SECY_TX_SA_START_STOP_TIME_SET_CMD,
	NSS_MACSEC_SECY_TX_SAK_GET_CMD,
	NSS_MACSEC_SECY_TX_SAK_SET_CMD,
	NSS_MACSEC_SECY_TX_QTAG_PARSE_SET_CMD,
	NSS_MACSEC_SECY_TX_QTAG_PARSE_GET_CMD,
	NSS_MACSEC_SECY_TX_STAG_PARSE_SET_CMD,
	NSS_MACSEC_SECY_TX_STAG_PARSE_GET_CMD,
	NSS_MACSEC_SECY_TX_PN_THRESHOLD_GET_CMD,
	NSS_MACSEC_SECY_TX_PN_THRESHOLD_SET_CMD,
	NSS_MACSEC_SECY_RESET_CMD,
	NSS_MACSEC_SECY_TX_SW_RESET_CMD,
	NSS_MACSEC_SECY_INIT_CMD,
	NSS_MACSEC_SECY_SC_SA_MAPPING_MODE_GET_CMD,
	NSS_MACSEC_SECY_SC_SA_MAPPING_MODE_SET_CMD,
	NSS_MACSEC_SECY_CONTROLLED_PORT_EN_GET_CMD,
	NSS_MACSEC_SECY_CONTROLLED_PORT_EN_SET_CMD,
	NSS_MACSEC_SECY_IP_VERSION_GET_CMD,
	NSS_MACSEC_SECY_CIPHER_SUITE_GET_CMD,
	NSS_MACSEC_SECY_CIPHER_SUITE_SET_CMD,
	NSS_MACSEC_SECY_MTU_GET_CMD,
	NSS_MACSEC_SECY_MTU_SET_CMD,
	NSS_MACSEC_SECY_EN_GET_CMD,
	NSS_MACSEC_SECY_EN_SET_CMD,
};

struct nss_macsec_secy_interrupt_en_get_cmd {
	u32 secy_id;
	fal_interrupt_en_t p_int_en;
};

struct nss_macsec_secy_interrupt_en_set_cmd {
	u32 secy_id;
	fal_interrupt_en_t p_int_en;
};

struct nss_macsec_secy_interrupt_get_cmd {
	u32 secy_id;
	fal_interrupt_t pint;
};

struct nss_macsec_emac_init_cmd {
	u32 secy_id;
};

struct nss_macsec_speed_cmd {
	u32 secy_id;
	enum emac_link_speed speed;
};

struct nss_macsec_emac_enable_cmd {
	u32 secy_id;
	BOOL enable;
};

struct nss_macsec_emac_reset_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_tx_sc_mib_get_cmd {
	u32 secy_id;
	u32 channel;
	fal_tx_sc_mib_t pmib;
};

struct nss_macsec_secy_tx_sa_mib_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	fal_tx_sa_mib_t pmib;
};

struct nss_macsec_secy_tx_mib_get_cmd {
	u32 secy_id;
	fal_tx_mib_t pmib;
};

struct nss_macsec_secy_rx_sa_mib_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	fal_rx_sa_mib_t pmib;
};

struct nss_macsec_secy_rx_mib_get_cmd {
	u32 secy_id;
	fal_rx_mib_t pmib;
};

struct nss_macsec_secy_tx_mib_clear_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_tx_sc_mib_clear_cmd {
	u32 secy_id;
	u32 channel;
};

struct nss_macsec_secy_tx_sa_mib_clear_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
};

struct nss_macsec_secy_rx_mib_clear_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_rx_sa_mib_clear_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
};

struct nss_macsec_secy_rx_reg_get_cmd {
	u32 secy_id;
	u32 addr;
	u32 pvalue;
};

struct nss_macsec_secy_rx_reg_set_cmd {
	u32 secy_id;
	u32 addr;
	u32 value;
};

struct nss_macsec_secy_rx_ctl_filt_get_cmd {
	u32 secy_id;
	u32 filt_id;
	fal_rx_ctl_filt_t pfilt;
};

struct nss_macsec_secy_rx_ctl_filt_set_cmd {
	u32 secy_id;
	u32 filt_id;
	fal_rx_ctl_filt_t pfilt;
};

struct nss_macsec_secy_rx_ctl_filt_clear_cmd {
	u32 secy_id;
	u32 filt_id;
};

struct nss_macsec_secy_rx_ctl_filt_clear_all_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_rx_prc_lut_get_cmd {
	u32 secy_id;
	u32 index;
	fal_rx_prc_lut_t pentry;
};

struct nss_macsec_secy_rx_prc_lut_set_cmd {
	u32 secy_id;
	u32 index;
	fal_rx_prc_lut_t pentry;
};

struct nss_macsec_secy_rx_prc_lut_clear_cmd {
	u32 secy_id;
	u32 index;
};

struct nss_macsec_secy_rx_prc_lut_clear_all_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_rx_sc_create_cmd {
	u32 secy_id;
	u32 channel;
};

struct nss_macsec_secy_rx_sc_en_get_cmd {
	u32 secy_id;
	u32 channel;
	bool penable;
};

struct nss_macsec_secy_rx_sc_en_set_cmd {
	u32 secy_id;
	u32 channel;
	bool enable;
};

struct nss_macsec_secy_rx_sc_del_cmd {
	u32 secy_id;
	u32 channel;
};

struct nss_macsec_secy_rx_sc_del_all_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_rx_sc_validate_frame_get_cmd {
	u32 secy_id;
	u32 channel;
	fal_rx_sc_validate_frame_e pmode;
};

struct nss_macsec_secy_rx_sc_validate_frame_set_cmd {
	u32 secy_id;
	u32 channel;
	fal_rx_sc_validate_frame_e mode;
};

struct nss_macsec_secy_rx_sc_replay_protect_get_cmd {
	u32 secy_id;
	u32 channel;
	bool penable;
};

struct nss_macsec_secy_rx_sc_replay_protect_set_cmd {
	u32 secy_id;
	u32 channel;
	bool enable;
};

struct nss_macsec_secy_rx_sc_anti_replay_window_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 pwindow;
};

struct nss_macsec_secy_rx_sc_anti_replay_window_set_cmd {
	u32 secy_id;
	u32 channel;
	u32 window;
};

struct nss_macsec_secy_rx_sc_in_used_get_cmd {
	u32 secy_id;
	u32 channel;
	bool p_in_used;
};

struct nss_macsec_secy_rx_sc_an_roll_over_get_cmd {
	u32 secy_id;
	u32 channel;
	bool penable;
};

struct nss_macsec_secy_rx_sc_an_roll_over_set_cmd {
	u32 secy_id;
	u32 channel;
	bool enable;
};

struct nss_macsec_secy_rx_sc_start_stop_time_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 p_start_time;
	u32 p_stop_time;
};

struct nss_macsec_secy_rx_sc_start_stop_time_set_cmd {
	u32 secy_id;
	u32 channel;
	u32 start_time;
	u32 stop_time;
};

struct nss_macsec_secy_rx_sa_create_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
};

struct nss_macsec_secy_rx_sa_en_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	bool penable;
};

struct nss_macsec_secy_rx_sa_en_set_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	bool enable;
};

struct nss_macsec_secy_rx_sa_next_pn_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	u32 pnpn;
};

struct nss_macsec_secy_rx_sa_del_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
};

struct nss_macsec_secy_rx_sa_del_all_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_rx_sak_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	fal_rx_sak_t pkey;
};

struct nss_macsec_secy_rx_sak_set_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	fal_rx_sak_t pkey;
};

struct nss_macsec_secy_rx_sa_in_used_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	bool p_in_used;
};

struct nss_macsec_secy_rx_sa_start_stop_time_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	u32 p_start_time;
	u32 p_stop_time;
};

struct nss_macsec_secy_rx_sa_start_stop_time_set_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	u32 start_time;
	u32 stop_time;
};

struct nss_macsec_secy_rx_pn_threshold_get_cmd {
	u32 secy_id;
	u32 p_pn_threshold;
};

struct nss_macsec_secy_rx_pn_threshold_set_cmd {
	u32 secy_id;
	u32 pn_threshold;
};

struct nss_macsec_secy_rx_replay_protect_get_cmd {
	u32 secy_id;
	u32 enable;
};

struct nss_macsec_secy_rx_replay_protect_set_cmd {
	u32 secy_id;
	u32 enable;
};

struct nss_macsec_secy_rx_validate_frame_get_cmd {
	u32 secy_id;
	u32 mode;
};

struct nss_macsec_secy_rx_validate_frame_set_cmd {
	u32 secy_id;
	u32 mode;
};

struct nss_macsec_secy_tx_reg_get_cmd {
	u32 secy_id;
	u32 addr;
	u32 pvalue;
};

struct nss_macsec_secy_tx_reg_set_cmd {
	u32 secy_id;
	u32 addr;
	u32 value;
};

struct nss_macsec_secy_tx_drop_sc_sa_invlid_get_cmd {
	u32 secy_id;
	bool penable;
};

struct nss_macsec_secy_tx_drop_sc_sa_invlid_set_cmd {
	u32 secy_id;
	bool enable;
};

struct nss_macsec_secy_tx_unmatched_use_sc_0_get_cmd {
	u32 secy_id;
	bool penable;
};

struct nss_macsec_secy_tx_unmatched_use_sc_0_set_cmd {
	u32 secy_id;
	bool enable;
};

struct nss_macsec_secy_tx_gcm_start_get_cmd {
	u32 secy_id;
	bool penable;
};

struct nss_macsec_secy_tx_gcm_start_set_cmd {
	u32 secy_id;
	bool enable;
};

struct nss_macsec_secy_tx_drop_class_miss_get_cmd {
	u32 secy_id;
	bool penable;
};

struct nss_macsec_secy_tx_drop_class_miss_set_cmd {
	u32 secy_id;
	bool enable;
};

struct nss_macsec_secy_tx_drop_kay_pkt_get_cmd {
	u32 secy_id;
	bool penable;
};

struct nss_macsec_secy_tx_drop_kay_pkt_set_cmd {
	u32 secy_id;
	bool enable;
};

struct nss_macsec_secy_tx_ctl_filt_get_cmd {
	u32 secy_id;
	u32 filt_id;
	fal_tx_ctl_filt_t pfilt;
};

struct nss_macsec_secy_tx_ctl_filt_set_cmd {
	u32 secy_id;
	u32 filt_id;
	fal_tx_ctl_filt_t pfilt;
};

struct nss_macsec_secy_tx_ctl_filt_clear_cmd {
	u32 secy_id;
	u32 filt_id;
};

struct nss_macsec_secy_tx_ctl_filt_clear_all_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_tx_class_lut_get_cmd {
	u32 secy_id;
	u32 index;
	fal_tx_class_lut_t pentry;
};

struct nss_macsec_secy_tx_class_lut_set_cmd {
	u32 secy_id;
	u32 index;
	fal_tx_class_lut_t pentry;
};

struct nss_macsec_secy_tx_class_lut_clear_cmd {
	u32 secy_id;
	u32 index;
};

struct nss_macsec_secy_tx_class_lut_clear_all_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_tx_sc_create_cmd {
	u32 secy_id;
	u32 channel;
	u8 psci[16];
	u32 sci_len;
};

struct nss_macsec_secy_tx_sc_en_get_cmd {
	u32 secy_id;
	u32 channel;
	bool penable;
};

struct nss_macsec_secy_tx_sc_en_set_cmd {
	u32 secy_id;
	u32 channel;
	bool enable;
};

struct nss_macsec_secy_tx_sc_del_cmd {
	u32 secy_id;
	u32 channel;
};

struct nss_macsec_secy_tx_sc_del_all_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_tx_sc_an_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 pan;
};

struct nss_macsec_secy_tx_sc_an_set_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
};

struct nss_macsec_secy_tx_sc_an_roll_over_en_get_cmd {
	u32 secy_id;
	u32 channel;
	bool penable;
};

struct nss_macsec_secy_tx_sc_an_roll_over_en_set_cmd {
	u32 secy_id;
	u32 channel;
	bool enable;
};

struct nss_macsec_secy_tx_sc_in_used_get_cmd {
	u32 secy_id;
	u32 channel;
	bool p_in_used;
};

struct nss_macsec_secy_tx_sc_tci_7_2_get_cmd {
	u32 secy_id;
	u32 channel;
	u8 ptci;
};

struct nss_macsec_secy_tx_sc_tci_7_2_set_cmd {
	u32 secy_id;
	u32 channel;
	u8 tci;
};

struct nss_macsec_secy_tx_sc_confidentiality_offset_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 poffset;
};

struct nss_macsec_secy_tx_sc_confidentiality_offset_set_cmd {
	u32 secy_id;
	u32 channel;
	u32 offset;
};

struct nss_macsec_secy_tx_sc_protect_get_cmd {
	u32 secy_id;
	u32 channel;
	bool penable;
};

struct nss_macsec_secy_tx_sc_protect_set_cmd {
	u32 secy_id;
	u32 channel;
	bool enable;
};

struct nss_macsec_secy_tx_sc_sci_get_cmd {
	u32 secy_id;
	u32 channel;
	u8 psci[16];
	u32 sci_len;
};

struct nss_macsec_secy_tx_sc_start_stop_time_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 p_start_time;
	u32 p_stop_time;
};

struct nss_macsec_secy_tx_sc_start_stop_time_set_cmd {
	u32 secy_id;
	u32 channel;
	u32 start_time;
	u32 stop_time;
};

struct nss_macsec_secy_tx_sa_create_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
};

struct nss_macsec_secy_tx_sa_en_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	bool penable;
};

struct nss_macsec_secy_tx_sa_en_set_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	bool enable;
};

struct nss_macsec_secy_tx_sa_del_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
};

struct nss_macsec_secy_tx_sa_del_all_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_tx_sa_next_pn_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	u32 p_next_pn;
};

struct nss_macsec_secy_tx_sa_next_pn_set_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	u32 next_pn;
};

struct nss_macsec_secy_tx_sa_in_used_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	bool p_in_used;
};

struct nss_macsec_secy_tx_sa_start_stop_time_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	u32 p_start_time;
	u32 p_stop_time;
};

struct nss_macsec_secy_tx_sa_start_stop_time_set_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	u32 start_time;
	u32 stop_time;
};

struct nss_macsec_secy_tx_sak_get_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	fal_tx_sak_t pentry;
};

struct nss_macsec_secy_tx_sak_set_cmd {
	u32 secy_id;
	u32 channel;
	u32 an;
	fal_tx_sak_t pentry;
};

struct nss_macsec_secy_tx_qtag_parse_set_cmd {
	u32 secy_id;
	fal_tx_vlan_parse_t pentry;
};

struct nss_macsec_secy_tx_qtag_parse_get_cmd {
	u32 secy_id;
	fal_tx_vlan_parse_t pentry;
};

struct nss_macsec_secy_tx_stag_parse_set_cmd {
	u32 secy_id;
	fal_tx_vlan_parse_t pentry;
};

struct nss_macsec_secy_tx_stag_parse_get_cmd {
	u32 secy_id;
	fal_tx_vlan_parse_t pentry;
};

struct nss_macsec_secy_tx_pn_threshold_get_cmd {
	u32 secy_id;
	u32 p_pn_threshold;
};

struct nss_macsec_secy_tx_pn_threshold_set_cmd {
	u32 secy_id;
	u32 pn_threshold;
};

struct nss_macsec_secy_reset_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_tx_sw_reset_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_init_cmd {
	u32 secy_id;
};

struct nss_macsec_secy_sc_sa_mapping_mode_get_cmd {
	u32 secy_id;
	fal_sc_sa_mapping_mode_e pmode;
};

struct nss_macsec_secy_sc_sa_mapping_mode_set_cmd {
	u32 secy_id;
	fal_sc_sa_mapping_mode_e mode;
};

struct nss_macsec_secy_controlled_port_en_get_cmd {
	u32 secy_id;
	bool penable;
};

struct nss_macsec_secy_controlled_port_en_set_cmd {
	u32 secy_id;
	bool enable;
};

struct nss_macsec_secy_ip_version_get_cmd {
	u32 secy_id;
	char ver_str[64];
	u32 ver_str_len;
};

struct nss_macsec_secy_cipher_suite_get_cmd {
	u32 secy_id;
	fal_cipher_suite_e p_cipher_suite;
};

struct nss_macsec_secy_cipher_suite_set_cmd {
	u32 secy_id;
	fal_cipher_suite_e cipher_suite;
};

struct nss_macsec_secy_mtu_get_cmd {
	u32 secy_id;
	u32 pmtu;
};

struct nss_macsec_secy_mtu_set_cmd {
	u32 secy_id;
	u32 mtu;
};

struct nss_macsec_secy_en_get_cmd {
	u32 secy_id;
	bool penable;
};

struct nss_macsec_secy_en_set_cmd {
	u32 secy_id;
	bool enable;
};

unsigned int nss_macsec_fal_msg_handle(struct sdk_msg_header *header);

#endif
