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

#include "nss_macsec_sdk_api.h"
#include "nss_macsec_emac.h"
#include "nss_macsec_interrupt.h"
#include "nss_macsec.h"
#include "nss_macsec_mib.h"
#include "nss_macsec_secy.h"
#include "nss_macsec_secy_rx.h"
#include "nss_macsec_secy_tx.h"
#include "nss_macsec_fal_api.h"

unsigned int nss_macsec_cmd_len[] = {
	sizeof(struct nss_macsec_secy_interrupt_en_get_cmd),
	sizeof(struct nss_macsec_secy_interrupt_en_set_cmd),
	sizeof(struct nss_macsec_secy_interrupt_get_cmd),
	sizeof(struct nss_macsec_emac_init_cmd),
	sizeof(struct nss_macsec_speed_cmd),
	sizeof(struct nss_macsec_emac_enable_cmd),
	sizeof(struct nss_macsec_emac_reset_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_mib_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sa_mib_get_cmd),
	sizeof(struct nss_macsec_secy_tx_mib_get_cmd),
	sizeof(struct nss_macsec_secy_rx_sa_mib_get_cmd),
	sizeof(struct nss_macsec_secy_rx_mib_get_cmd),
	sizeof(struct nss_macsec_secy_tx_mib_clear_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_mib_clear_cmd),
	sizeof(struct nss_macsec_secy_tx_sa_mib_clear_cmd),
	sizeof(struct nss_macsec_secy_rx_mib_clear_cmd),
	sizeof(struct nss_macsec_secy_rx_sa_mib_clear_cmd),
	sizeof(struct nss_macsec_secy_rx_reg_get_cmd),
	sizeof(struct nss_macsec_secy_rx_reg_set_cmd),
	sizeof(struct nss_macsec_secy_rx_ctl_filt_get_cmd),
	sizeof(struct nss_macsec_secy_rx_ctl_filt_set_cmd),
	sizeof(struct nss_macsec_secy_rx_ctl_filt_clear_cmd),
	sizeof(struct nss_macsec_secy_rx_ctl_filt_clear_all_cmd),
	sizeof(struct nss_macsec_secy_rx_prc_lut_get_cmd),
	sizeof(struct nss_macsec_secy_rx_prc_lut_set_cmd),
	sizeof(struct nss_macsec_secy_rx_prc_lut_clear_cmd),
	sizeof(struct nss_macsec_secy_rx_prc_lut_clear_all_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_create_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_en_get_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_en_set_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_del_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_del_all_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_validate_frame_get_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_validate_frame_set_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_replay_protect_get_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_replay_protect_set_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_anti_replay_window_get_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_anti_replay_window_set_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_in_used_get_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_an_roll_over_get_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_an_roll_over_set_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_start_stop_time_get_cmd),
	sizeof(struct nss_macsec_secy_rx_sc_start_stop_time_set_cmd),
	sizeof(struct nss_macsec_secy_rx_sa_create_cmd),
	sizeof(struct nss_macsec_secy_rx_sa_en_get_cmd),
	sizeof(struct nss_macsec_secy_rx_sa_en_set_cmd),
	sizeof(struct nss_macsec_secy_rx_sa_next_pn_get_cmd),
	sizeof(struct nss_macsec_secy_rx_sa_del_cmd),
	sizeof(struct nss_macsec_secy_rx_sa_del_all_cmd),
	sizeof(struct nss_macsec_secy_rx_sak_get_cmd),
	sizeof(struct nss_macsec_secy_rx_sak_set_cmd),
	sizeof(struct nss_macsec_secy_rx_sa_in_used_get_cmd),
	sizeof(struct nss_macsec_secy_rx_sa_start_stop_time_get_cmd),
	sizeof(struct nss_macsec_secy_rx_sa_start_stop_time_set_cmd),
	sizeof(struct nss_macsec_secy_rx_pn_threshold_get_cmd),
	sizeof(struct nss_macsec_secy_rx_pn_threshold_set_cmd),
	sizeof(struct nss_macsec_secy_rx_replay_protect_get_cmd),
	sizeof(struct nss_macsec_secy_rx_replay_protect_set_cmd),
	sizeof(struct nss_macsec_secy_rx_validate_frame_get_cmd),
	sizeof(struct nss_macsec_secy_rx_validate_frame_set_cmd),
	sizeof(struct nss_macsec_secy_tx_reg_get_cmd),
	sizeof(struct nss_macsec_secy_tx_reg_set_cmd),
	sizeof(struct nss_macsec_secy_tx_drop_sc_sa_invlid_get_cmd),
	sizeof(struct nss_macsec_secy_tx_drop_sc_sa_invlid_set_cmd),
	sizeof(struct nss_macsec_secy_tx_unmatched_use_sc_0_get_cmd),
	sizeof(struct nss_macsec_secy_tx_unmatched_use_sc_0_set_cmd),
	sizeof(struct nss_macsec_secy_tx_gcm_start_get_cmd),
	sizeof(struct nss_macsec_secy_tx_gcm_start_set_cmd),
	sizeof(struct nss_macsec_secy_tx_drop_class_miss_get_cmd),
	sizeof(struct nss_macsec_secy_tx_drop_class_miss_set_cmd),
	sizeof(struct nss_macsec_secy_tx_drop_kay_pkt_get_cmd),
	sizeof(struct nss_macsec_secy_tx_drop_kay_pkt_set_cmd),
	sizeof(struct nss_macsec_secy_tx_ctl_filt_get_cmd),
	sizeof(struct nss_macsec_secy_tx_ctl_filt_set_cmd),
	sizeof(struct nss_macsec_secy_tx_ctl_filt_clear_cmd),
	sizeof(struct nss_macsec_secy_tx_ctl_filt_clear_all_cmd),
	sizeof(struct nss_macsec_secy_tx_class_lut_get_cmd),
	sizeof(struct nss_macsec_secy_tx_class_lut_set_cmd),
	sizeof(struct nss_macsec_secy_tx_class_lut_clear_cmd),
	sizeof(struct nss_macsec_secy_tx_class_lut_clear_all_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_create_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_en_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_en_set_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_del_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_del_all_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_an_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_an_set_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_an_roll_over_en_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_an_roll_over_en_set_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_in_used_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_tci_7_2_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_tci_7_2_set_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_confidentiality_offset_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_confidentiality_offset_set_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_protect_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_protect_set_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_sci_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_start_stop_time_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sc_start_stop_time_set_cmd),
	sizeof(struct nss_macsec_secy_tx_sa_create_cmd),
	sizeof(struct nss_macsec_secy_tx_sa_en_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sa_en_set_cmd),
	sizeof(struct nss_macsec_secy_tx_sa_del_cmd),
	sizeof(struct nss_macsec_secy_tx_sa_del_all_cmd),
	sizeof(struct nss_macsec_secy_tx_sa_next_pn_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sa_next_pn_set_cmd),
	sizeof(struct nss_macsec_secy_tx_sa_in_used_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sa_start_stop_time_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sa_start_stop_time_set_cmd),
	sizeof(struct nss_macsec_secy_tx_sak_get_cmd),
	sizeof(struct nss_macsec_secy_tx_sak_set_cmd),
	sizeof(struct nss_macsec_secy_tx_qtag_parse_set_cmd),
	sizeof(struct nss_macsec_secy_tx_qtag_parse_get_cmd),
	sizeof(struct nss_macsec_secy_tx_stag_parse_set_cmd),
	sizeof(struct nss_macsec_secy_tx_stag_parse_get_cmd),
	sizeof(struct nss_macsec_secy_tx_pn_threshold_get_cmd),
	sizeof(struct nss_macsec_secy_tx_pn_threshold_set_cmd),
	sizeof(struct nss_macsec_secy_reset_cmd),
	sizeof(struct nss_macsec_secy_tx_sw_reset_cmd),
	sizeof(struct nss_macsec_secy_init_cmd),
	sizeof(struct nss_macsec_secy_sc_sa_mapping_mode_get_cmd),
	sizeof(struct nss_macsec_secy_sc_sa_mapping_mode_set_cmd),
	sizeof(struct nss_macsec_secy_controlled_port_en_get_cmd),
	sizeof(struct nss_macsec_secy_controlled_port_en_set_cmd),
	sizeof(struct nss_macsec_secy_ip_version_get_cmd),
	sizeof(struct nss_macsec_secy_cipher_suite_get_cmd),
	sizeof(struct nss_macsec_secy_cipher_suite_set_cmd),
	sizeof(struct nss_macsec_secy_mtu_get_cmd),
	sizeof(struct nss_macsec_secy_mtu_set_cmd),
	sizeof(struct nss_macsec_secy_en_get_cmd),
	sizeof(struct nss_macsec_secy_en_set_cmd)
};

unsigned int nss_macsec_fal_msg_handle(struct sdk_msg_header *header)
{
	unsigned int ret = SDK_RET_SUCCESS;

	if(header->sub_type >= sizeof(nss_macsec_cmd_len)/sizeof(nss_macsec_cmd_len[0])) {
		printk("sub_type:0x%x is unvalid\n", header->sub_type);
		return SDK_RET_PARAM_ERR;
	}

	if(header->buf_len != nss_macsec_cmd_len[header->sub_type]) {
		printk("buf_len:0x%x is unvalid for command sub_type:0x%x\n", header->buf_len, header->sub_type);
		return SDK_RET_PARAM_ERR;
	}

	switch (header->sub_type) {
	case NSS_MACSEC_SECY_INTERRUPT_EN_GET_CMD:{
			struct nss_macsec_secy_interrupt_en_get_cmd *param =
			    (struct nss_macsec_secy_interrupt_en_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_interrupt_en_get(param->secy_id,
							     &param->p_int_en);
		}
		break;
	case NSS_MACSEC_SECY_INTERRUPT_EN_SET_CMD:{
			struct nss_macsec_secy_interrupt_en_set_cmd *param =
			    (struct nss_macsec_secy_interrupt_en_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_interrupt_en_set(param->secy_id,
							     &param->p_int_en);
		}
		break;
	case NSS_MACSEC_SECY_INTERRUPT_GET_CMD:{
			struct nss_macsec_secy_interrupt_get_cmd *param =
			    (struct nss_macsec_secy_interrupt_get_cmd *)(header
									 + 1);
			ret =
			    nss_macsec_secy_interrupt_get(param->secy_id,
							  &param->pint);
		}
		break;
	case NSS_MACSEC_EMAC_INIT_CMD:{
			struct nss_macsec_emac_init_cmd *param =
			    (struct nss_macsec_emac_init_cmd *)(header + 1);
			ret = nss_macsec_emac_init(param->secy_id);
		}
		break;
	case NSS_MACSEC_SPEED_CMD:{
			struct nss_macsec_speed_cmd *param =
			    (struct nss_macsec_speed_cmd *)(header + 1);
			ret = nss_macsec_speed(param->secy_id, param->speed);
		}
		break;
	case NSS_MACSEC_EMAC_ENABLE_CMD:{
			struct nss_macsec_emac_enable_cmd *param =
			    (struct nss_macsec_emac_enable_cmd *)(header + 1);
			ret =
			    nss_macsec_emac_enable(param->secy_id,
						   param->enable);
		}
		break;
	case NSS_MACSEC_EMAC_RESET_CMD:{
			struct nss_macsec_emac_reset_cmd *param =
			    (struct nss_macsec_emac_reset_cmd *)(header + 1);
			ret = nss_macsec_emac_reset(param->secy_id);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_MIB_GET_CMD:{
			struct nss_macsec_secy_tx_sc_mib_get_cmd *param =
			    (struct nss_macsec_secy_tx_sc_mib_get_cmd *)(header
									 + 1);
			ret =
			    nss_macsec_secy_tx_sc_mib_get(param->secy_id,
							  param->channel,
							  &param->pmib);
		}
		break;
	case NSS_MACSEC_SECY_TX_SA_MIB_GET_CMD:{
			struct nss_macsec_secy_tx_sa_mib_get_cmd *param =
			    (struct nss_macsec_secy_tx_sa_mib_get_cmd *)(header
									 + 1);
			ret =
			    nss_macsec_secy_tx_sa_mib_get(param->secy_id,
							  param->channel,
							  param->an,
							  &param->pmib);
		}
		break;
	case NSS_MACSEC_SECY_TX_MIB_GET_CMD:{
			struct nss_macsec_secy_tx_mib_get_cmd *param =
			    (struct nss_macsec_secy_tx_mib_get_cmd *)(header +
								      1);
			ret =
			    nss_macsec_secy_tx_mib_get(param->secy_id,
						       &param->pmib);
		}
		break;
	case NSS_MACSEC_SECY_RX_SA_MIB_GET_CMD:{
			struct nss_macsec_secy_rx_sa_mib_get_cmd *param =
			    (struct nss_macsec_secy_rx_sa_mib_get_cmd *)(header
									 + 1);
			ret =
			    nss_macsec_secy_rx_sa_mib_get(param->secy_id,
							  param->channel,
							  param->an,
							  &param->pmib);
		}
		break;
	case NSS_MACSEC_SECY_RX_MIB_GET_CMD:{
			struct nss_macsec_secy_rx_mib_get_cmd *param =
			    (struct nss_macsec_secy_rx_mib_get_cmd *)(header +
								      1);
			ret =
			    nss_macsec_secy_rx_mib_get(param->secy_id,
						       &param->pmib);
		}
		break;
	case NSS_MACSEC_SECY_TX_MIB_CLEAR_CMD:{
			struct nss_macsec_secy_tx_mib_clear_cmd *param =
			    (struct nss_macsec_secy_tx_mib_clear_cmd *)(header +
									1);
			ret = nss_macsec_secy_tx_mib_clear(param->secy_id);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_MIB_CLEAR_CMD:{
			struct nss_macsec_secy_tx_sc_mib_clear_cmd *param =
			    (struct nss_macsec_secy_tx_sc_mib_clear_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sc_mib_clear(param->secy_id,
							    param->channel);
		}
		break;
	case NSS_MACSEC_SECY_TX_SA_MIB_CLEAR_CMD:{
			struct nss_macsec_secy_tx_sa_mib_clear_cmd *param =
			    (struct nss_macsec_secy_tx_sa_mib_clear_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sa_mib_clear(param->secy_id,
							    param->channel,
							    param->an);
		}
		break;
	case NSS_MACSEC_SECY_RX_MIB_CLEAR_CMD:{
			struct nss_macsec_secy_rx_mib_clear_cmd *param =
			    (struct nss_macsec_secy_rx_mib_clear_cmd *)(header +
									1);
			ret = nss_macsec_secy_rx_mib_clear(param->secy_id);
		}
		break;
	case NSS_MACSEC_SECY_RX_SA_MIB_CLEAR_CMD:{
			struct nss_macsec_secy_rx_sa_mib_clear_cmd *param =
			    (struct nss_macsec_secy_rx_sa_mib_clear_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sa_mib_clear(param->secy_id,
							    param->channel,
							    param->an);
		}
		break;
	case NSS_MACSEC_SECY_RX_REG_GET_CMD:{
			struct nss_macsec_secy_rx_reg_get_cmd *param =
			    (struct nss_macsec_secy_rx_reg_get_cmd *)(header +
								      1);
			ret =
			    nss_macsec_secy_rx_reg_get(param->secy_id,
						       param->addr,
						       &param->pvalue);
		}
		break;
	case NSS_MACSEC_SECY_RX_REG_SET_CMD:{
			struct nss_macsec_secy_rx_reg_set_cmd *param =
			    (struct nss_macsec_secy_rx_reg_set_cmd *)(header +
								      1);
			ret =
			    nss_macsec_secy_rx_reg_set(param->secy_id,
						       param->addr,
						       param->value);
		}
		break;
	case NSS_MACSEC_SECY_RX_CTL_FILT_GET_CMD:{
			struct nss_macsec_secy_rx_ctl_filt_get_cmd *param =
			    (struct nss_macsec_secy_rx_ctl_filt_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_ctl_filt_get(param->secy_id,
							    param->filt_id,
							    &param->pfilt);
		}
		break;
	case NSS_MACSEC_SECY_RX_CTL_FILT_SET_CMD:{
			struct nss_macsec_secy_rx_ctl_filt_set_cmd *param =
			    (struct nss_macsec_secy_rx_ctl_filt_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_ctl_filt_set(param->secy_id,
							    param->filt_id,
							    &param->pfilt);
		}
		break;
	case NSS_MACSEC_SECY_RX_CTL_FILT_CLEAR_CMD:{
			struct nss_macsec_secy_rx_ctl_filt_clear_cmd *param =
			    (struct nss_macsec_secy_rx_ctl_filt_clear_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_ctl_filt_clear(param->secy_id,
							      param->filt_id);
		}
		break;
	case NSS_MACSEC_SECY_RX_CTL_FILT_CLEAR_ALL_CMD:{
			struct nss_macsec_secy_rx_ctl_filt_clear_all_cmd *param
			    =
			    (struct nss_macsec_secy_rx_ctl_filt_clear_all_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_ctl_filt_clear_all(param->
								  secy_id);
		}
		break;
	case NSS_MACSEC_SECY_RX_PRC_LUT_GET_CMD:{
			struct nss_macsec_secy_rx_prc_lut_get_cmd *param =
			    (struct nss_macsec_secy_rx_prc_lut_get_cmd *)(header
									  + 1);
			ret =
			    nss_macsec_secy_rx_prc_lut_get(param->secy_id,
							   param->index,
							   &param->pentry);
		}
		break;
	case NSS_MACSEC_SECY_RX_PRC_LUT_SET_CMD:{
			struct nss_macsec_secy_rx_prc_lut_set_cmd *param =
			    (struct nss_macsec_secy_rx_prc_lut_set_cmd *)(header
									  + 1);
			ret =
			    nss_macsec_secy_rx_prc_lut_set(param->secy_id,
							   param->index,
							   &param->pentry);
		}
		break;
	case NSS_MACSEC_SECY_RX_PRC_LUT_CLEAR_CMD:{
			struct nss_macsec_secy_rx_prc_lut_clear_cmd *param =
			    (struct nss_macsec_secy_rx_prc_lut_clear_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_prc_lut_clear(param->secy_id,
							     param->index);
		}
		break;
	case NSS_MACSEC_SECY_RX_PRC_LUT_CLEAR_ALL_CMD:{
			struct nss_macsec_secy_rx_prc_lut_clear_all_cmd *param =
			    (struct nss_macsec_secy_rx_prc_lut_clear_all_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_prc_lut_clear_all(param->
								 secy_id);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_CREATE_CMD:{
			struct nss_macsec_secy_rx_sc_create_cmd *param =
			    (struct nss_macsec_secy_rx_sc_create_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_rx_sc_create(param->secy_id,
							 param->channel);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_EN_GET_CMD:{
			struct nss_macsec_secy_rx_sc_en_get_cmd *param =
			    (struct nss_macsec_secy_rx_sc_en_get_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_rx_sc_en_get(param->secy_id,
							 param->channel,
							 &param->penable);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_EN_SET_CMD:{
			struct nss_macsec_secy_rx_sc_en_set_cmd *param =
			    (struct nss_macsec_secy_rx_sc_en_set_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_rx_sc_en_set(param->secy_id,
							 param->channel,
							 param->enable);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_DEL_CMD:{
			struct nss_macsec_secy_rx_sc_del_cmd *param =
			    (struct nss_macsec_secy_rx_sc_del_cmd *)(header +
								     1);
			ret =
			    nss_macsec_secy_rx_sc_del(param->secy_id,
						      param->channel);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_DEL_ALL_CMD:{
			struct nss_macsec_secy_rx_sc_del_all_cmd *param =
			    (struct nss_macsec_secy_rx_sc_del_all_cmd *)(header
									 + 1);
			ret = nss_macsec_secy_rx_sc_del_all(param->secy_id);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_VALIDATE_FRAME_GET_CMD:{
			struct nss_macsec_secy_rx_sc_validate_frame_get_cmd
			    *param =
			    (struct nss_macsec_secy_rx_sc_validate_frame_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sc_validate_frame_get(param->
								     secy_id,
								     param->
								     channel,
								     &param->
								     pmode);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_VALIDATE_FRAME_SET_CMD:{
			struct nss_macsec_secy_rx_sc_validate_frame_set_cmd
			    *param =
			    (struct nss_macsec_secy_rx_sc_validate_frame_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sc_validate_frame_set(param->
								     secy_id,
								     param->
								     channel,
								     param->
								     mode);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_REPLAY_PROTECT_GET_CMD:{
			struct nss_macsec_secy_rx_sc_replay_protect_get_cmd
			    *param =
			    (struct nss_macsec_secy_rx_sc_replay_protect_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sc_replay_protect_get(param->
								     secy_id,
								     param->
								     channel,
								     &param->
								     penable);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_REPLAY_PROTECT_SET_CMD:{
			struct nss_macsec_secy_rx_sc_replay_protect_set_cmd
			    *param =
			    (struct nss_macsec_secy_rx_sc_replay_protect_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sc_replay_protect_set(param->
								     secy_id,
								     param->
								     channel,
								     param->
								     enable);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_ANTI_REPLAY_WINDOW_GET_CMD:{
			struct nss_macsec_secy_rx_sc_anti_replay_window_get_cmd
			    *param =
			    (struct
			     nss_macsec_secy_rx_sc_anti_replay_window_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sc_anti_replay_window_get(param->
									 secy_id,
									 param->
									 channel,
									 &param->
									 pwindow);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_ANTI_REPLAY_WINDOW_SET_CMD:{
			struct nss_macsec_secy_rx_sc_anti_replay_window_set_cmd
			    *param =
			    (struct
			     nss_macsec_secy_rx_sc_anti_replay_window_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sc_anti_replay_window_set(param->
									 secy_id,
									 param->
									 channel,
									 param->
									 window);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_IN_USED_GET_CMD:{
			struct nss_macsec_secy_rx_sc_in_used_get_cmd *param =
			    (struct nss_macsec_secy_rx_sc_in_used_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sc_in_used_get(param->secy_id,
							      param->channel,
							      &param->
							      p_in_used);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_AN_ROLL_OVER_GET_CMD:{
			struct nss_macsec_secy_rx_sc_an_roll_over_get_cmd *param
			    =
			    (struct nss_macsec_secy_rx_sc_an_roll_over_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sc_an_roll_over_get(param->
								   secy_id,
								   param->
								   channel,
								   &param->
								   penable);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_AN_ROLL_OVER_SET_CMD:{
			struct nss_macsec_secy_rx_sc_an_roll_over_set_cmd *param
			    =
			    (struct nss_macsec_secy_rx_sc_an_roll_over_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sc_an_roll_over_set(param->
								   secy_id,
								   param->
								   channel,
								   param->
								   enable);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_START_STOP_TIME_GET_CMD:{
			struct nss_macsec_secy_rx_sc_start_stop_time_get_cmd
			    *param =
			    (struct
			     nss_macsec_secy_rx_sc_start_stop_time_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sc_start_stop_time_get(param->
								      secy_id,
								      param->
								      channel,
								      &param->
								      p_start_time,
								      &param->
								      p_stop_time);
		}
		break;
	case NSS_MACSEC_SECY_RX_SC_START_STOP_TIME_SET_CMD:{
			struct nss_macsec_secy_rx_sc_start_stop_time_set_cmd
			    *param =
			    (struct
			     nss_macsec_secy_rx_sc_start_stop_time_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sc_start_stop_time_set(param->
								      secy_id,
								      param->
								      channel,
								      param->
								      start_time,
								      param->
								      stop_time);
		}
		break;
	case NSS_MACSEC_SECY_RX_SA_CREATE_CMD:{
			struct nss_macsec_secy_rx_sa_create_cmd *param =
			    (struct nss_macsec_secy_rx_sa_create_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_rx_sa_create(param->secy_id,
							 param->channel,
							 param->an);
		}
		break;
	case NSS_MACSEC_SECY_RX_SA_EN_GET_CMD:{
			struct nss_macsec_secy_rx_sa_en_get_cmd *param =
			    (struct nss_macsec_secy_rx_sa_en_get_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_rx_sa_en_get(param->secy_id,
							 param->channel,
							 param->an,
							 &param->penable);
		}
		break;
	case NSS_MACSEC_SECY_RX_SA_EN_SET_CMD:{
			struct nss_macsec_secy_rx_sa_en_set_cmd *param =
			    (struct nss_macsec_secy_rx_sa_en_set_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_rx_sa_en_set(param->secy_id,
							 param->channel,
							 param->an,
							 param->enable);
		}
		break;
	case NSS_MACSEC_SECY_RX_SA_NEXT_PN_GET_CMD:{
			struct nss_macsec_secy_rx_sa_next_pn_get_cmd *param =
			    (struct nss_macsec_secy_rx_sa_next_pn_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sa_next_pn_get(param->secy_id,
							      param->channel,
							      param->an,
							      &param->pnpn);
		}
		break;
	case NSS_MACSEC_SECY_RX_SA_DEL_CMD:{
			struct nss_macsec_secy_rx_sa_del_cmd *param =
			    (struct nss_macsec_secy_rx_sa_del_cmd *)(header +
								     1);
			ret =
			    nss_macsec_secy_rx_sa_del(param->secy_id,
						      param->channel,
						      param->an);
		}
		break;
	case NSS_MACSEC_SECY_RX_SA_DEL_ALL_CMD:{
			struct nss_macsec_secy_rx_sa_del_all_cmd *param =
			    (struct nss_macsec_secy_rx_sa_del_all_cmd *)(header
									 + 1);
			ret = nss_macsec_secy_rx_sa_del_all(param->secy_id);
		}
		break;
	case NSS_MACSEC_SECY_RX_SAK_GET_CMD:{
			struct nss_macsec_secy_rx_sak_get_cmd *param =
			    (struct nss_macsec_secy_rx_sak_get_cmd *)(header +
								      1);
			ret =
			    nss_macsec_secy_rx_sak_get(param->secy_id,
						       param->channel,
						       param->an, &param->pkey);
		}
		break;
	case NSS_MACSEC_SECY_RX_SAK_SET_CMD:{
			struct nss_macsec_secy_rx_sak_set_cmd *param =
			    (struct nss_macsec_secy_rx_sak_set_cmd *)(header +
								      1);
			ret =
			    nss_macsec_secy_rx_sak_set(param->secy_id,
						       param->channel,
						       param->an, &param->pkey);
		}
		break;
	case NSS_MACSEC_SECY_RX_SA_IN_USED_GET_CMD:{
			struct nss_macsec_secy_rx_sa_in_used_get_cmd *param =
			    (struct nss_macsec_secy_rx_sa_in_used_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sa_in_used_get(param->secy_id,
							      param->channel,
							      param->an,
							      &param->
							      p_in_used);
		}
		break;
	case NSS_MACSEC_SECY_RX_SA_START_STOP_TIME_GET_CMD:{
			struct nss_macsec_secy_rx_sa_start_stop_time_get_cmd
			    *param =
			    (struct
			     nss_macsec_secy_rx_sa_start_stop_time_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sa_start_stop_time_get(param->
								      secy_id,
								      param->
								      channel,
								      param->an,
								      &param->
								      p_start_time,
								      &param->
								      p_stop_time);
		}
		break;
	case NSS_MACSEC_SECY_RX_SA_START_STOP_TIME_SET_CMD:{
			struct nss_macsec_secy_rx_sa_start_stop_time_set_cmd
			    *param =
			    (struct
			     nss_macsec_secy_rx_sa_start_stop_time_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_sa_start_stop_time_set(param->
								      secy_id,
								      param->
								      channel,
								      param->an,
								      param->
								      start_time,
								      param->
								      stop_time);
		}
		break;
	case NSS_MACSEC_SECY_RX_PN_THRESHOLD_GET_CMD:{
			struct nss_macsec_secy_rx_pn_threshold_get_cmd *param =
			    (struct nss_macsec_secy_rx_pn_threshold_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_pn_threshold_get(param->secy_id,
								&param->
								p_pn_threshold);
		}
		break;
	case NSS_MACSEC_SECY_RX_PN_THRESHOLD_SET_CMD:{
			struct nss_macsec_secy_rx_pn_threshold_set_cmd *param =
			    (struct nss_macsec_secy_rx_pn_threshold_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_pn_threshold_set(param->secy_id,
								param->
								pn_threshold);
		}
		break;
	case NSS_MACSEC_SECY_RX_REPLAY_PROTECT_GET_CMD:{
			struct nss_macsec_secy_rx_replay_protect_get_cmd *param
			    =
			    (struct nss_macsec_secy_rx_replay_protect_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_replay_protect_get(param->
								  secy_id,
								  &param->
								  enable);
		}
		break;
	case NSS_MACSEC_SECY_RX_REPLAY_PROTECT_SET_CMD:{
			struct nss_macsec_secy_rx_replay_protect_set_cmd *param
			    =
			    (struct nss_macsec_secy_rx_replay_protect_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_replay_protect_set(param->
								  secy_id,
								  param->
								  enable);
		}
		break;
	case NSS_MACSEC_SECY_RX_VALIDATE_FRAME_GET_CMD:{
			struct nss_macsec_secy_rx_validate_frame_get_cmd *param
			    =
			    (struct nss_macsec_secy_rx_validate_frame_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_validate_frame_get(param->
								  secy_id,
								  &param->mode);
		}
		break;
	case NSS_MACSEC_SECY_RX_VALIDATE_FRAME_SET_CMD:{
			struct nss_macsec_secy_rx_validate_frame_set_cmd *param
			    =
			    (struct nss_macsec_secy_rx_validate_frame_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_rx_validate_frame_set(param->
								  secy_id,
								  param->mode);
		}
		break;
	case NSS_MACSEC_SECY_TX_REG_GET_CMD:{
			struct nss_macsec_secy_tx_reg_get_cmd *param =
			    (struct nss_macsec_secy_tx_reg_get_cmd *)(header +
								      1);
			ret =
			    nss_macsec_secy_tx_reg_get(param->secy_id,
						       param->addr,
						       &param->pvalue);
		}
		break;
	case NSS_MACSEC_SECY_TX_REG_SET_CMD:{
			struct nss_macsec_secy_tx_reg_set_cmd *param =
			    (struct nss_macsec_secy_tx_reg_set_cmd *)(header +
								      1);
			ret =
			    nss_macsec_secy_tx_reg_set(param->secy_id,
						       param->addr,
						       param->value);
		}
		break;
	case NSS_MACSEC_SECY_TX_DROP_SC_SA_INVLID_GET_CMD:{
			struct nss_macsec_secy_tx_drop_sc_sa_invlid_get_cmd
			    *param =
			    (struct nss_macsec_secy_tx_drop_sc_sa_invlid_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_drop_sc_sa_invalid_get(param->
								     secy_id,
								     &param->
								     penable);
		}
		break;
	case NSS_MACSEC_SECY_TX_DROP_SC_SA_INVLID_SET_CMD:{
			struct nss_macsec_secy_tx_drop_sc_sa_invlid_set_cmd
			    *param =
			    (struct nss_macsec_secy_tx_drop_sc_sa_invlid_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_drop_sc_sa_invalid_set(param->
								     secy_id,
								     param->
								     enable);
		}
		break;
	case NSS_MACSEC_SECY_TX_UNMATCHED_USE_SC_0_GET_CMD:{
			struct nss_macsec_secy_tx_unmatched_use_sc_0_get_cmd
			    *param =
			    (struct
			     nss_macsec_secy_tx_unmatched_use_sc_0_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_unmatched_use_sc_0_get(param->
								      secy_id,
								      &param->
								      penable);
		}
		break;
	case NSS_MACSEC_SECY_TX_UNMATCHED_USE_SC_0_SET_CMD:{
			struct nss_macsec_secy_tx_unmatched_use_sc_0_set_cmd
			    *param =
			    (struct
			     nss_macsec_secy_tx_unmatched_use_sc_0_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_unmatched_use_sc_0_set(param->
								      secy_id,
								      param->
								      enable);
		}
		break;
	case NSS_MACSEC_SECY_TX_GCM_START_GET_CMD:{
			struct nss_macsec_secy_tx_gcm_start_get_cmd *param =
			    (struct nss_macsec_secy_tx_gcm_start_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_gcm_start_get(param->secy_id,
							     &param->penable);
		}
		break;
	case NSS_MACSEC_SECY_TX_GCM_START_SET_CMD:{
			struct nss_macsec_secy_tx_gcm_start_set_cmd *param =
			    (struct nss_macsec_secy_tx_gcm_start_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_gcm_start_set(param->secy_id,
							     param->enable);
		}
		break;
	case NSS_MACSEC_SECY_TX_DROP_CLASS_MISS_GET_CMD:{
			struct nss_macsec_secy_tx_drop_class_miss_get_cmd *param
			    =
			    (struct nss_macsec_secy_tx_drop_class_miss_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_drop_class_miss_get(param->
								   secy_id,
								   &param->
								   penable);
		}
		break;
	case NSS_MACSEC_SECY_TX_DROP_CLASS_MISS_SET_CMD:{
			struct nss_macsec_secy_tx_drop_class_miss_set_cmd *param
			    =
			    (struct nss_macsec_secy_tx_drop_class_miss_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_drop_class_miss_set(param->
								   secy_id,
								   param->
								   enable);
		}
		break;
	case NSS_MACSEC_SECY_TX_DROP_KAY_PKT_GET_CMD:{
			struct nss_macsec_secy_tx_drop_kay_pkt_get_cmd *param =
			    (struct nss_macsec_secy_tx_drop_kay_pkt_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_drop_kay_pkt_get(param->secy_id,
								&param->
								penable);
		}
		break;
	case NSS_MACSEC_SECY_TX_DROP_KAY_PKT_SET_CMD:{
			struct nss_macsec_secy_tx_drop_kay_pkt_set_cmd *param =
			    (struct nss_macsec_secy_tx_drop_kay_pkt_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_drop_kay_pkt_set(param->secy_id,
								param->enable);
		}
		break;
	case NSS_MACSEC_SECY_TX_CTL_FILT_GET_CMD:{
			struct nss_macsec_secy_tx_ctl_filt_get_cmd *param =
			    (struct nss_macsec_secy_tx_ctl_filt_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_ctl_filt_get(param->secy_id,
							    param->filt_id,
							    &param->pfilt);
		}
		break;
	case NSS_MACSEC_SECY_TX_CTL_FILT_SET_CMD:{
			struct nss_macsec_secy_tx_ctl_filt_set_cmd *param =
			    (struct nss_macsec_secy_tx_ctl_filt_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_ctl_filt_set(param->secy_id,
							    param->filt_id,
							    &param->pfilt);
		}
		break;
	case NSS_MACSEC_SECY_TX_CTL_FILT_CLEAR_CMD:{
			struct nss_macsec_secy_tx_ctl_filt_clear_cmd *param =
			    (struct nss_macsec_secy_tx_ctl_filt_clear_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_ctl_filt_clear(param->secy_id,
							      param->filt_id);
		}
		break;
	case NSS_MACSEC_SECY_TX_CTL_FILT_CLEAR_ALL_CMD:{
			struct nss_macsec_secy_tx_ctl_filt_clear_all_cmd *param
			    =
			    (struct nss_macsec_secy_tx_ctl_filt_clear_all_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_ctl_filt_clear_all(param->
								  secy_id);
		}
		break;
	case NSS_MACSEC_SECY_TX_CLASS_LUT_GET_CMD:{
			struct nss_macsec_secy_tx_class_lut_get_cmd *param =
			    (struct nss_macsec_secy_tx_class_lut_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_class_lut_get(param->secy_id,
							     param->index,
							     &param->pentry);
		}
		break;
	case NSS_MACSEC_SECY_TX_CLASS_LUT_SET_CMD:{
			struct nss_macsec_secy_tx_class_lut_set_cmd *param =
			    (struct nss_macsec_secy_tx_class_lut_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_class_lut_set(param->secy_id,
							     param->index,
							     &param->pentry);
		}
		break;
	case NSS_MACSEC_SECY_TX_CLASS_LUT_CLEAR_CMD:{
			struct nss_macsec_secy_tx_class_lut_clear_cmd *param =
			    (struct nss_macsec_secy_tx_class_lut_clear_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_class_lut_clear(param->secy_id,
							       param->index);
		}
		break;
	case NSS_MACSEC_SECY_TX_CLASS_LUT_CLEAR_ALL_CMD:{
			struct nss_macsec_secy_tx_class_lut_clear_all_cmd *param
			    =
			    (struct nss_macsec_secy_tx_class_lut_clear_all_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_class_lut_clear_all(param->
								   secy_id);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_CREATE_CMD:{
			struct nss_macsec_secy_tx_sc_create_cmd *param =
			    (struct nss_macsec_secy_tx_sc_create_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_tx_sc_create(param->secy_id,
							 param->channel,
							 param->psci,
							 param->sci_len);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_EN_GET_CMD:{
			struct nss_macsec_secy_tx_sc_en_get_cmd *param =
			    (struct nss_macsec_secy_tx_sc_en_get_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_tx_sc_en_get(param->secy_id,
							 param->channel,
							 &param->penable);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_EN_SET_CMD:{
			struct nss_macsec_secy_tx_sc_en_set_cmd *param =
			    (struct nss_macsec_secy_tx_sc_en_set_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_tx_sc_en_set(param->secy_id,
							 param->channel,
							 param->enable);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_DEL_CMD:{
			struct nss_macsec_secy_tx_sc_del_cmd *param =
			    (struct nss_macsec_secy_tx_sc_del_cmd *)(header +
								     1);
			ret =
			    nss_macsec_secy_tx_sc_del(param->secy_id,
						      param->channel);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_DEL_ALL_CMD:{
			struct nss_macsec_secy_tx_sc_del_all_cmd *param =
			    (struct nss_macsec_secy_tx_sc_del_all_cmd *)(header
									 + 1);
			ret = nss_macsec_secy_tx_sc_del_all(param->secy_id);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_AN_GET_CMD:{
			struct nss_macsec_secy_tx_sc_an_get_cmd *param =
			    (struct nss_macsec_secy_tx_sc_an_get_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_tx_sc_an_get(param->secy_id,
							 param->channel,
							 &param->pan);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_AN_SET_CMD:{
			struct nss_macsec_secy_tx_sc_an_set_cmd *param =
			    (struct nss_macsec_secy_tx_sc_an_set_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_tx_sc_an_set(param->secy_id,
							 param->channel,
							 param->an);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_AN_ROLL_OVER_EN_GET_CMD:{
			struct nss_macsec_secy_tx_sc_an_roll_over_en_get_cmd
			    *param =
			    (struct
			     nss_macsec_secy_tx_sc_an_roll_over_en_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sc_an_roll_over_en_get(param->
								      secy_id,
								      param->
								      channel,
								      &param->
								      penable);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_AN_ROLL_OVER_EN_SET_CMD:{
			struct nss_macsec_secy_tx_sc_an_roll_over_en_set_cmd
			    *param =
			    (struct
			     nss_macsec_secy_tx_sc_an_roll_over_en_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sc_an_roll_over_en_set(param->
								      secy_id,
								      param->
								      channel,
								      param->
								      enable);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_IN_USED_GET_CMD:{
			struct nss_macsec_secy_tx_sc_in_used_get_cmd *param =
			    (struct nss_macsec_secy_tx_sc_in_used_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sc_in_used_get(param->secy_id,
							      param->channel,
							      &param->
							      p_in_used);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_TCI_7_2_GET_CMD:{
			struct nss_macsec_secy_tx_sc_tci_7_2_get_cmd *param =
			    (struct nss_macsec_secy_tx_sc_tci_7_2_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sc_tci_7_2_get(param->secy_id,
							      param->channel,
							      &param->ptci);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_TCI_7_2_SET_CMD:{
			struct nss_macsec_secy_tx_sc_tci_7_2_set_cmd *param =
			    (struct nss_macsec_secy_tx_sc_tci_7_2_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sc_tci_7_2_set(param->secy_id,
							      param->channel,
							      param->tci);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_CONFIDENTIALITY_OFFSET_GET_CMD:{
			struct
			    nss_macsec_secy_tx_sc_confidentiality_offset_get_cmd
			    *param =
			    (struct
			     nss_macsec_secy_tx_sc_confidentiality_offset_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sc_confidentiality_offset_get
			    (param->secy_id, param->channel, &param->poffset);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_CONFIDENTIALITY_OFFSET_SET_CMD:{
			struct
			    nss_macsec_secy_tx_sc_confidentiality_offset_set_cmd
			    *param =
			    (struct
			     nss_macsec_secy_tx_sc_confidentiality_offset_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sc_confidentiality_offset_set
			    (param->secy_id, param->channel, param->offset);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_PROTECT_GET_CMD:{
			struct nss_macsec_secy_tx_sc_protect_get_cmd *param =
			    (struct nss_macsec_secy_tx_sc_protect_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sc_protect_get(param->secy_id,
							      param->channel,
							      &param->penable);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_PROTECT_SET_CMD:{
			struct nss_macsec_secy_tx_sc_protect_set_cmd *param =
			    (struct nss_macsec_secy_tx_sc_protect_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sc_protect_set(param->secy_id,
							      param->channel,
							      param->enable);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_SCI_GET_CMD:{
			struct nss_macsec_secy_tx_sc_sci_get_cmd *param =
			    (struct nss_macsec_secy_tx_sc_sci_get_cmd *)(header
									 + 1);
			ret =
			    nss_macsec_secy_tx_sc_sci_get(param->secy_id,
							  param->channel,
							  param->psci,
							  param->sci_len);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_START_STOP_TIME_GET_CMD:{
			struct nss_macsec_secy_tx_sc_start_stop_time_get_cmd
			    *param =
			    (struct
			     nss_macsec_secy_tx_sc_start_stop_time_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sc_start_stop_time_get(param->
								      secy_id,
								      param->
								      channel,
								      &param->
								      p_start_time,
								      &param->
								      p_stop_time);
		}
		break;
	case NSS_MACSEC_SECY_TX_SC_START_STOP_TIME_SET_CMD:{
			struct nss_macsec_secy_tx_sc_start_stop_time_set_cmd
			    *param =
			    (struct
			     nss_macsec_secy_tx_sc_start_stop_time_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sc_start_stop_time_set(param->
								      secy_id,
								      param->
								      channel,
								      param->
								      start_time,
								      param->
								      stop_time);
		}
		break;
	case NSS_MACSEC_SECY_TX_SA_CREATE_CMD:{
			struct nss_macsec_secy_tx_sa_create_cmd *param =
			    (struct nss_macsec_secy_tx_sa_create_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_tx_sa_create(param->secy_id,
							 param->channel,
							 param->an);
		}
		break;
	case NSS_MACSEC_SECY_TX_SA_EN_GET_CMD:{
			struct nss_macsec_secy_tx_sa_en_get_cmd *param =
			    (struct nss_macsec_secy_tx_sa_en_get_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_tx_sa_en_get(param->secy_id,
							 param->channel,
							 param->an,
							 &param->penable);
		}
		break;
	case NSS_MACSEC_SECY_TX_SA_EN_SET_CMD:{
			struct nss_macsec_secy_tx_sa_en_set_cmd *param =
			    (struct nss_macsec_secy_tx_sa_en_set_cmd *)(header +
									1);
			ret =
			    nss_macsec_secy_tx_sa_en_set(param->secy_id,
							 param->channel,
							 param->an,
							 param->enable);
		}
		break;
	case NSS_MACSEC_SECY_TX_SA_DEL_CMD:{
			struct nss_macsec_secy_tx_sa_del_cmd *param =
			    (struct nss_macsec_secy_tx_sa_del_cmd *)(header +
								     1);
			ret =
			    nss_macsec_secy_tx_sa_del(param->secy_id,
						      param->channel,
						      param->an);
		}
		break;
	case NSS_MACSEC_SECY_TX_SA_DEL_ALL_CMD:{
			struct nss_macsec_secy_tx_sa_del_all_cmd *param =
			    (struct nss_macsec_secy_tx_sa_del_all_cmd *)(header
									 + 1);
			ret = nss_macsec_secy_tx_sa_del_all(param->secy_id);
		}
		break;
	case NSS_MACSEC_SECY_TX_SA_NEXT_PN_GET_CMD:{
			struct nss_macsec_secy_tx_sa_next_pn_get_cmd *param =
			    (struct nss_macsec_secy_tx_sa_next_pn_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sa_next_pn_get(param->secy_id,
							      param->channel,
							      param->an,
							      &param->
							      p_next_pn);
		}
		break;
	case NSS_MACSEC_SECY_TX_SA_NEXT_PN_SET_CMD:{
			struct nss_macsec_secy_tx_sa_next_pn_set_cmd *param =
			    (struct nss_macsec_secy_tx_sa_next_pn_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sa_next_pn_set(param->secy_id,
							      param->channel,
							      param->an,
							      param->next_pn);
		}
		break;
	case NSS_MACSEC_SECY_TX_SA_IN_USED_GET_CMD:{
			struct nss_macsec_secy_tx_sa_in_used_get_cmd *param =
			    (struct nss_macsec_secy_tx_sa_in_used_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sa_in_used_get(param->secy_id,
							      param->channel,
							      param->an,
							      &param->
							      p_in_used);
		}
		break;
	case NSS_MACSEC_SECY_TX_SA_START_STOP_TIME_GET_CMD:{
			struct nss_macsec_secy_tx_sa_start_stop_time_get_cmd
			    *param =
			    (struct
			     nss_macsec_secy_tx_sa_start_stop_time_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sa_start_stop_time_get(param->
								      secy_id,
								      param->
								      channel,
								      param->an,
								      &param->
								      p_start_time,
								      &param->
								      p_stop_time);
		}
		break;
	case NSS_MACSEC_SECY_TX_SA_START_STOP_TIME_SET_CMD:{
			struct nss_macsec_secy_tx_sa_start_stop_time_set_cmd
			    *param =
			    (struct
			     nss_macsec_secy_tx_sa_start_stop_time_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_sa_start_stop_time_set(param->
								      secy_id,
								      param->
								      channel,
								      param->an,
								      param->
								      start_time,
								      param->
								      stop_time);
		}
		break;
	case NSS_MACSEC_SECY_TX_SAK_GET_CMD:{
			struct nss_macsec_secy_tx_sak_get_cmd *param =
			    (struct nss_macsec_secy_tx_sak_get_cmd *)(header +
								      1);
			ret =
			    nss_macsec_secy_tx_sak_get(param->secy_id,
						       param->channel,
						       param->an,
						       &param->pentry);
		}
		break;
	case NSS_MACSEC_SECY_TX_SAK_SET_CMD:{
			struct nss_macsec_secy_tx_sak_set_cmd *param =
			    (struct nss_macsec_secy_tx_sak_set_cmd *)(header +
								      1);
			ret =
			    nss_macsec_secy_tx_sak_set(param->secy_id,
						       param->channel,
						       param->an,
						       &param->pentry);
		}
		break;
	case NSS_MACSEC_SECY_TX_QTAG_PARSE_SET_CMD:{
			struct nss_macsec_secy_tx_qtag_parse_set_cmd *param =
			    (struct nss_macsec_secy_tx_qtag_parse_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_qtag_parse_set(param->secy_id,
							      &param->pentry);
		}
		break;
	case NSS_MACSEC_SECY_TX_QTAG_PARSE_GET_CMD:{
			struct nss_macsec_secy_tx_qtag_parse_get_cmd *param =
			    (struct nss_macsec_secy_tx_qtag_parse_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_qtag_parse_get(param->secy_id,
							      &param->pentry);
		}
		break;
	case NSS_MACSEC_SECY_TX_STAG_PARSE_SET_CMD:{
			struct nss_macsec_secy_tx_stag_parse_set_cmd *param =
			    (struct nss_macsec_secy_tx_stag_parse_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_stag_parse_set(param->secy_id,
							      &param->pentry);
		}
		break;
	case NSS_MACSEC_SECY_TX_STAG_PARSE_GET_CMD:{
			struct nss_macsec_secy_tx_stag_parse_get_cmd *param =
			    (struct nss_macsec_secy_tx_stag_parse_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_stag_parse_get(param->secy_id,
							      &param->pentry);
		}
		break;
	case NSS_MACSEC_SECY_TX_PN_THRESHOLD_GET_CMD:{
			struct nss_macsec_secy_tx_pn_threshold_get_cmd *param =
			    (struct nss_macsec_secy_tx_pn_threshold_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_pn_threshold_get(param->secy_id,
								&param->
								p_pn_threshold);
		}
		break;
	case NSS_MACSEC_SECY_TX_PN_THRESHOLD_SET_CMD:{
			struct nss_macsec_secy_tx_pn_threshold_set_cmd *param =
			    (struct nss_macsec_secy_tx_pn_threshold_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_tx_pn_threshold_set(param->secy_id,
								param->
								pn_threshold);
		}
		break;
	case NSS_MACSEC_SECY_RESET_CMD:{
			struct nss_macsec_secy_reset_cmd *param =
			    (struct nss_macsec_secy_reset_cmd *)(header + 1);
			ret = nss_macsec_secy_reset(param->secy_id);
		}
		break;
	case NSS_MACSEC_SECY_TX_SW_RESET_CMD:{
			struct nss_macsec_secy_tx_sw_reset_cmd *param =
			    (struct nss_macsec_secy_tx_sw_reset_cmd *)(header +
								       1);
			ret = nss_macsec_secy_tx_sw_reset(param->secy_id);
		}
		break;
	case NSS_MACSEC_SECY_INIT_CMD:{
			struct nss_macsec_secy_init_cmd *param =
			    (struct nss_macsec_secy_init_cmd *)(header + 1);
			ret = nss_macsec_secy_init(param->secy_id);
		}
		break;
	case NSS_MACSEC_SECY_SC_SA_MAPPING_MODE_GET_CMD:{
			struct nss_macsec_secy_sc_sa_mapping_mode_get_cmd *param
			    =
			    (struct nss_macsec_secy_sc_sa_mapping_mode_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_sc_sa_mapping_mode_get(param->
								   secy_id,
								   &param->
								   pmode);
		}
		break;
	case NSS_MACSEC_SECY_SC_SA_MAPPING_MODE_SET_CMD:{
			struct nss_macsec_secy_sc_sa_mapping_mode_set_cmd *param
			    =
			    (struct nss_macsec_secy_sc_sa_mapping_mode_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_sc_sa_mapping_mode_set(param->
								   secy_id,
								   param->mode);
		}
		break;
	case NSS_MACSEC_SECY_CONTROLLED_PORT_EN_GET_CMD:{
			struct nss_macsec_secy_controlled_port_en_get_cmd *param
			    =
			    (struct nss_macsec_secy_controlled_port_en_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_controlled_port_en_get(param->
								   secy_id,
								   &param->
								   penable);
		}
		break;
	case NSS_MACSEC_SECY_CONTROLLED_PORT_EN_SET_CMD:{
			struct nss_macsec_secy_controlled_port_en_set_cmd *param
			    =
			    (struct nss_macsec_secy_controlled_port_en_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_controlled_port_en_set(param->
								   secy_id,
								   param->
								   enable);
		}
		break;
	case NSS_MACSEC_SECY_IP_VERSION_GET_CMD:{
			struct nss_macsec_secy_ip_version_get_cmd *param =
			    (struct nss_macsec_secy_ip_version_get_cmd *)(header
									  + 1);
			ret =
			    nss_macsec_secy_ip_version_get(param->secy_id,
							   param->ver_str,
							   param->ver_str_len);
		}
		break;
	case NSS_MACSEC_SECY_CIPHER_SUITE_GET_CMD:{
			struct nss_macsec_secy_cipher_suite_get_cmd *param =
			    (struct nss_macsec_secy_cipher_suite_get_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_cipher_suite_get(param->secy_id,
							     &param->
							     p_cipher_suite);
		}
		break;
	case NSS_MACSEC_SECY_CIPHER_SUITE_SET_CMD:{
			struct nss_macsec_secy_cipher_suite_set_cmd *param =
			    (struct nss_macsec_secy_cipher_suite_set_cmd
			     *)(header + 1);
			ret =
			    nss_macsec_secy_cipher_suite_set(param->secy_id,
							     param->
							     cipher_suite);
		}
		break;
	case NSS_MACSEC_SECY_MTU_GET_CMD:{
			struct nss_macsec_secy_mtu_get_cmd *param =
			    (struct nss_macsec_secy_mtu_get_cmd *)(header + 1);
			ret =
			    nss_macsec_secy_mtu_get(param->secy_id,
						    &param->pmtu);
		}
		break;
	case NSS_MACSEC_SECY_MTU_SET_CMD:{
			struct nss_macsec_secy_mtu_set_cmd *param =
			    (struct nss_macsec_secy_mtu_set_cmd *)(header + 1);
			ret =
			    nss_macsec_secy_mtu_set(param->secy_id, param->mtu);
		}
		break;
	case NSS_MACSEC_SECY_EN_GET_CMD:{
			struct nss_macsec_secy_en_get_cmd *param =
			    (struct nss_macsec_secy_en_get_cmd *)(header + 1);
			ret =
			    nss_macsec_secy_en_get(param->secy_id,
						   &param->penable);
		}
		break;
	case NSS_MACSEC_SECY_EN_SET_CMD:{
			struct nss_macsec_secy_en_set_cmd *param =
			    (struct nss_macsec_secy_en_set_cmd *)(header + 1);
			ret =
			    nss_macsec_secy_en_set(param->secy_id,
						   param->enable);
		}
		break;
	default:
		break;
	}

	return ret;
}
