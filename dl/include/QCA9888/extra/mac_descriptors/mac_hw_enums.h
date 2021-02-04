// Copyright (c) 2013 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// EDIT WITH CAUTION!  These definitions are tied to a particular hardware layout

#ifndef _MAC_HW_ENUMS_H_
#define _MAC_HW_ENUMS_H_
#include <common/wifi_tlv_enum.h>

typedef pcu_ppdu_setup__transmit_fes_type_e wifi_txfes_type_t;

typedef scheduler_cmd__txop_time_ctrl_e wifi_sch_txop_t;

typedef scheduler_cmd__ndp_frame_bw_e wifi_ndp_bw_t;

typedef scheduler_cmd__fes_control_mode_e wifi_fes_mode_t;

typedef pcu_ppdu_setup__medium_prot_type_e wifi_mproto_type_t;

typedef pcu_ppdu_setup__su_response_type_e wifi_resp_type_t;

typedef tx_pkt_end__status_e wifi_tx_pkt_end_status_t;

typedef scheduler_cmd__start_time_reference_e wifi_start_time_ref_t;
typedef scheduler_cmd__start_time_reference_e wifi_end_time_ref_t;

typedef l_sig_a__rate_e wifi_lsig_a_rate_t;

typedef l_sig_a__rx_pkt_type_e wifi_ppdu_type_t;

typedef msdu_link__encap_type_e wifi_msdu_encap_t;

typedef scheduler_transmit_status__cmd_ring_stall_status_e wifi_cmd_ring_stall_status_t;

typedef scheduler_transmit_status__sch_cmd_result_e  wifi_xmit_status_t;

typedef scheduler_transmit_status__sifs_burst_status_e wifi_sifs_xmit_status_t;

typedef tx_phy_desc__bf_type_e wifi_bf_t;

typedef tx_fes_setup__mprot_addr_sel_e wifi_tx_addr_t;

typedef tx_fes_status__fes_transmit_result_e wifi_fes_status_t;

typedef tx_fes_status__fes_error_status_e wifi_fes_errno_t;

typedef tx_fes_status__data_underflow_warning_e wifi_underrun_status_t;

typedef tx_fes_status__response_frame_rcvd_e wifi_fes_resp_rcvd_t;

#endif /* _MAC_HW_ENUMS_H_ */

