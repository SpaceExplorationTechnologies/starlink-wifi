
//-----------------------------------------------------------------------------
// Qualcomm Proprietary
// Copyright (c) 2015 Qualcomm Atheros, Inc.
// All rights reserved.
// Qualcomm Atheros Confidential and Proprietary.
//
//
// All data and information contained in or disclosed by this document
// are confidential and proprietary information of Qualcomm Atheros, Inc.
// and all rights therein are expressly reserved. By accepting this
// material, the recipient agrees that this material and the information
// contained therein are held in confidence and in trust and will not be
// used, copied, reproduced in whole or in part, nor its contents
// revealed in any manner to others without the express written
// permission of Qualcomm Atheros, Inc.
//
// This technology was exported from the United States in accordance with
// the Export Administration Regulations. Diversion contrary to U.S. law
// prohibited.
//-----------------------------------------------------------------------------


/**
 * Generated file ... Do not hand edit ...
 */

#ifndef _WIFI_TLV_ENUM_H_
#define _WIFI_TLV_ENUM_H_

//-----------------------------------------------------------------------------
// "ht_sig" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_HT_20_MHZ                                     = 0,
  WIFI_HT_40_MHZ                                     = 1
} ht_sig__cbw_e;                                     ///< cbw Enum Type
typedef enum {
  WIFI_SMOOTHING                                     = 0,
  WIFI_NO_SMOOTHING                                  = 1
} ht_sig__smoothing_e;                               ///< smoothing Enum Type
typedef enum {
  WIFI_SOUNDING                                      = 0,
  WIFI_NOT_SOUNDING                                  = 1
} ht_sig__not_sounding_e;                            ///< not_sounding Enum Type
typedef enum {
  WIFI_MPDU                                          = 0,
  WIFI_A_MPDU                                        = 1
} ht_sig__aggregation_e;                             ///< aggregation Enum Type
typedef enum {
  WIFI_NO_STBC                                       = 0,
  WIFI_1_STR_STBC                                    = 1,
  WIFI_2_STR_STBC                                    = 2
} ht_sig__stbc_e;                                    ///< stbc Enum Type
typedef enum {
  WIFI_HT_BCC                                        = 0,
  WIFI_HT_LDPC                                       = 1
} ht_sig__fec_coding_e;                              ///< fec_coding Enum Type
typedef enum {
  WIFI_HT_NORMAL_GI                                  = 0,
  WIFI_HT_SHORT_GI                                   = 1
} ht_sig__short_gi_e;                                ///< short_gi Enum Type
typedef enum {
  WIFI_0_EXT_SP_STR                                  = 0,
  WIFI_1_EXT_SP_STR                                  = 1,
  WIFI_2_EXT_SP_STR                                  = 2
} ht_sig__num_ext_sp_str_e;                          ///< num_ext_sp_str Enum Type

//-----------------------------------------------------------------------------
// "l_sig_a" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_OFDM_48_MBPS                                  = 8,
  WIFI_OFDM_24_MBPS                                  = 9,
  WIFI_OFDM_12_MBPS                                  = 10,
  WIFI_OFDM_6_MBPS                                   = 11,
  WIFI_OFDM_54_MBPS                                  = 12,
  WIFI_OFDM_36_MBPS                                  = 13,
  WIFI_OFDM_18_MBPS                                  = 14,
  WIFI_OFDM_9_MBPS                                   = 15
} l_sig_a__rate_e;                                   ///< rate Enum Type
typedef enum {
  WIFI_DOT11A                                        = 0,
  WIFI_DOT11B                                        = 1,
  WIFI_DOT11N_MM                                     = 2,
  WIFI_DOT11AC                                       = 3,
  WIFI_DOT11N_GF                                     = 4
} l_sig_a__rx_pkt_type_e;                            ///< rx_pkt_type Enum Type

//-----------------------------------------------------------------------------
// "l_sig_b" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_DSSS_1_MPBS_LONG                              = 1,
  WIFI_DSSS_2_MBPS_LONG                              = 2,
  WIFI_CCK_5_5_MBPS_LONG                             = 3,
  WIFI_CCK_11_MBPS_LONG                              = 4,
  WIFI_DSSS_2_MBPS_SHORT                             = 5,
  WIFI_CCK_5_5_MBPS_SHORT                            = 6,
  WIFI_CCK_11_MBPS_SHORT                             = 7
} l_sig_b__rate_e;                                   ///< rate Enum Type

//-----------------------------------------------------------------------------
// "mac_pkt_end" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_TX_SUCCESS                                    = 0,
  WIFI_TX_ABORT                                      = 1,
  WIFI_RF_ONLY_ABORT                                 = 2
} mac_pkt_end__status_e;                             ///< status Enum Type

//-----------------------------------------------------------------------------
// "rx_location_info" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_LOCATION_FAC_INVALID                          = 0,
  WIFI_LOCATION_LEGACY_FAC_VALID                     = 1,
  WIFI_LOCATION_HT_VHT_FAC_VALID                     = 2
} rx_location_info__fac_status_e;                    ///< fac_status Enum Type
typedef enum {
  WIFI_LOCATION_LEGACY                               = 0,
  WIFI_LOCATION_HT_VHT20                             = 1,
  WIFI_LOCATION_HT_VHT40                             = 2,
  WIFI_LOCATION_HT_VHT80                             = 3
} rx_location_info__pkt_bw_e;                        ///< pkt_bw Enum Type

//-----------------------------------------------------------------------------
// "tx_bf_params" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_20_MHZ                                        = 0,
  WIFI_40_MHZ                                        = 1,
  WIFI_80_MHZ                                        = 2,
  WIFI_160_MHZ                                       = 3
} tx_bf_params__static_bandwidth_e;                  ///< static_bandwidth Enum Type

//-----------------------------------------------------------------------------
// "tx_expect_ndp" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_11AC_SU                                       = 0,
  WIFI_11AC_MU                                       = 1
} tx_expect_ndp__feedback_type_e;                    ///< feedback_type Enum Type

//-----------------------------------------------------------------------------
// "tx_location_req" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_IFFT_RESPONSE                                 = 0,
  WIFI_RAW_RESPONSE                                  = 1
} tx_location_req__location_type_e;                  ///< location_type Enum Type

//-----------------------------------------------------------------------------
// "tx_phy_desc" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_NO_BF                                         = 0,
  WIFI_LEGACY_BF                                     = 1,
  WIFI_SU_BF                                         = 2,
  WIFI_MU_BF                                         = 3
} tx_phy_desc__bf_type_e;                            ///< bf_type Enum Type
typedef enum {
  WIFI_SHORT_PREAMBLE                                = 0,
  WIFI_LONG_PREAMBLE                                 = 1
} tx_phy_desc__dot11b_preamble_type_e;               ///< dot11b_preamble_type Enum Type
typedef l_sig_a__rx_pkt_type_e                       tx_phy_desc__pkt_type_e;
typedef tx_bf_params__static_bandwidth_e             tx_phy_desc__bandwidth_e;
typedef enum {
  WIFI_DPD_OFF                                       = 0,
  WIFI_DPD_ON                                        = 1
} tx_phy_desc__dpd_enable_e;                         ///< dpd_enable Enum Type
typedef enum {
  WIFI_CLPC_OFF                                      = 0,
  WIFI_CLPC_ON                                       = 1
} tx_phy_desc__clpc_enable_e;                        ///< clpc_enable Enum Type
typedef enum {
  WIFI_MEASURE_DIS                                   = 0,
  WIFI_MEASURE_EN                                    = 1
} tx_phy_desc__measure_power_e;                      ///< measure_power Enum Type

//-----------------------------------------------------------------------------
// "tx_pkt_end" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_ERROR_TX_UNDERRUN                             = 1,
  WIFI_ERROR_TX_CHAIN_MASK_ZERO                      = 2,
  WIFI_ERROR_TX_EXTRA_SYM_MISMATCH                   = 3,
  WIFI_ERROR_TX_VHT_LENGTH_NOT_MULTIPLE_OF_3         = 4,
  WIFI_ERROR_TX_BW_IS_GT_DYN_BW                      = 5,
  WIFI_ERROR_TX_11B_RATE_ILLEGAL                     = 6,
  WIFI_ERROR_TX_LEGACY_RATE_ILLEGAL                  = 7,
  WIFI_ERROR_TX_HT_RATE_ILLEGAL                      = 8,
  WIFI_ERROR_TX_VHT_RATE_ILLEGAL                     = 9,
  WIFI_ERROR_TX_OVERFLOW                             = 10,
  WIFI_ERROR_MAC_TX_ABORT                            = 11,
  WIFI_ERROR_MAC_RF_ONLY_ABORT                       = 12,
  WIFI_ERROR_UNSUPPORTED_CBF                         = 13,
  WIFI_ERROR_CV_STATIC_BANDWIDTH_MISMATCH            = 14,
  WIFI_ERROR_CV_DYNAMIC_BANDWIDTH_MISMATCH           = 15,
  WIFI_ERROR_CV_UNSUPPORTED_NSS_TOTAL                = 16,
  WIFI_ERROR_NSS_BF_PARAMS_MISMATCH                  = 17,
  WIFI_ERROR_TXBF_FAIL                               = 18,
  WIFI_ERROR_ILLEGAL_NSS                             = 19,
  WIFI_ERROR_OTP_TXBF                                = 20
} tx_pkt_end__status_e;                              ///< status Enum Type

//-----------------------------------------------------------------------------
// "vector_transfer_start" enums
//-----------------------------------------------------------------------------
typedef tx_phy_desc__bf_type_e                       vector_transfer_start__bf_type_e;

//-----------------------------------------------------------------------------
// "vht_sig_a" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_STBC_DISABLED                                 = 0,
  WIFI_STBC_ENABLED                                  = 1
} vht_sig_a__stbc_e;                                 ///< stbc Enum Type
typedef enum {
  WIFI_TXOP_PS_ALLOWED                               = 0,
  WIFI_TXOP_PS_NOT_ALLOWED                           = 1
} vht_sig_a__txop_ps_not_allowed_e;                  ///< txop_ps_not_allowed Enum Type
typedef enum {
  WIFI_NORMAL_GI                                     = 0,
  WIFI_SHORT_GI                                      = 1,
  WIFI_SHORT_GI_AMBIGUITY                            = 3
} vht_sig_a__short_gi_e;                             ///< short_gi Enum Type

//-----------------------------------------------------------------------------
// "msdu_link" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_RAW                                           = 0,
  WIFI_NATIVE_WIFI                                   = 1,
  WIFI_ETHERNET                                      = 2,
  WIFI_802_3                                         = 3
} msdu_link__encap_type_e;                           ///< encap_type Enum Type

//-----------------------------------------------------------------------------
// "msdu_release" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_RECEIVED_ACK                                  = 0,
  WIFI_RECEIVED_BA                                   = 1,
  WIFI_LIFETIME_EXPIRED_OR_FLUSH                     = 2,
  WIFI_MAX_MPDU_RETRY_CNT                            = 3
} msdu_release__release_reason_e;                    ///< release_reason Enum Type

//-----------------------------------------------------------------------------
// "peer_entry" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_WEP_40                                        = 0,
  WIFI_WEP_104                                       = 1,
  WIFI_TKIP_NO_MIC                                   = 2,
  WIFI_WEP_128                                       = 3,
  WIFI_TKIP_WITH_MIC                                 = 4,
  WIFI_WAPI                                          = 5,
  WIFI_AES_CCMP_128                                  = 6,
  WIFI_NO_CIPHER                                     = 7,
  WIFI_AES_CCMP_256                                  = 8,
  WIFI_AES_GCMP_128                                  = 9,
  WIFI_AES_GCMP_256                                  = 10
} peer_entry__key_type_e;                            ///< key_type Enum Type
typedef enum {
  WIFI_AD3_A__AD4_A                                  = 0,
  WIFI_AD3_A__AD4_B                                  = 1,
  WIFI_AD3_B__AD4_A                                  = 2,
  WIFI_AD3_B__AD4_B                                  = 3,
  WIFI_AD3_DA__AD4_SA                                = 4
} peer_entry__a_msdu_wds_ad3_ad4_e;                  ///< a_msdu_wds_ad3_ad4 Enum Type
typedef enum {
  WIFI_PTE_DECAP_RAW                                 = 0,
  WIFI_PTE_DECAP_NATIVE_WIFI                         = 1,
  WIFI_PTE_DECAP_ETHERNET_802_3                      = 2
} peer_entry__decap_type_e;                          ///< decap_type Enum Type

//-----------------------------------------------------------------------------
// "pre_tx_phy_desc" enums
//-----------------------------------------------------------------------------
typedef tx_phy_desc__dpd_enable_e                    pre_tx_phy_desc__dpd_enable_e;
typedef tx_phy_desc__clpc_enable_e                   pre_tx_phy_desc__clpc_en_e;
typedef tx_phy_desc__measure_power_e                 pre_tx_phy_desc__measure_power_e;
typedef enum {
  WIFI_1_SPATIAL_STREAM                              = 0,
  WIFI_2_SPATIAL_STREAMS                             = 1,
  WIFI_3_SPATIAL_STREAMS                             = 2,
  WIFI_4_SPATIAL_STREAMS                             = 3
} pre_tx_phy_desc__heavy_clip_nss_e;                 ///< heavy_clip_nss Enum Type

//-----------------------------------------------------------------------------
// "tx_flush_req" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_TXPCU_FLREQ_CODE_TXOP_EXCEEDED                = 1,
  WIFI_CRYPT_FLREQ_RX_INT_TX                         = 2,
  WIFI_TXPCU_FLREQ_CODE_RTS_PKT_CCA_ABORT            = 3,
  WIFI_TXPCU_FLREQ_CODE_CTS_CCA_ABORT                = 4,
  WIFI_PDG_FLREQ_CODE_TXOP_ABORT                     = 5,
  WIFI_SW_EXPLICIT_FLUSH_TERMINATION                 = 6,
  WIFI_FES_STP_NOT_ENOUGH_TXOP_REM                   = 7,
  WIFI_FES_STP_SCH_TLV_LEN_ERR                       = 8,
  WIFI_FES_STP_SCH_TLV_ID_ERR                        = 9,
  WIFI_FES_STP_TLV_TIME_EXCEEDED_BKOF_EXP            = 10,
  WIFI_FES_STP_SW_FES_TIME_GT_HW                     = 11,
  WIFI_TXPCU_FLREQ_PPDU_ALLOW_BW_FIELDS_NOT_SET      = 12,
  WIFI_TXPCU_FLREQ_BF_PARAM_BW_NOT_AVAILABLE         = 13,
  WIFI_HWSCH_COEX_ABORT                              = 14,
  WIFI_HWSCH_SVD_RDY_TIMEOUT                         = 15,
  WIFI_NUM_MPDU_CNT_ZERO                             = 16,
  WIFI_UNSUPPORTED_CBF                               = 17
} tx_flush_req__flush_req_reason_e;                  ///< flush_req_reason Enum Type

//-----------------------------------------------------------------------------
// "tx_msdu_start_userx" enums
//-----------------------------------------------------------------------------
typedef msdu_link__encap_type_e                      tx_msdu_start_userx__encap_type_e;

//-----------------------------------------------------------------------------
// "tx_rate_setting" enums
//-----------------------------------------------------------------------------
typedef pre_tx_phy_desc__heavy_clip_nss_e            tx_rate_setting__nss_e;
typedef tx_phy_desc__dpd_enable_e                    tx_rate_setting__dpd_enable_e;

//-----------------------------------------------------------------------------
// "uapsd_response" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_ORDERED                                       = 0,
  WIFI_RR                                            = 1,
  WIFI_SAME_AC                                       = 2,
  WIFI_SAME_AC_OR_LOWER                              = 3
} uapsd_response__qid_selection_control_e;           ///< qid_selection_control Enum Type
typedef enum {
  WIFI_BEST_EFFORT                                   = 0,
  WIFI_BEST_CASE                                     = 1,
  WIFI_VIDEO                                         = 2,
  WIFI_VOICE                                         = 3
} uapsd_response__queue0_ac_e;                       ///< queue0_ac Enum Type
typedef uapsd_response__queue0_ac_e                  uapsd_response__queue1_ac_e;
typedef uapsd_response__queue0_ac_e                  uapsd_response__queue2_ac_e;
typedef uapsd_response__queue0_ac_e                  uapsd_response__queue3_ac_e;
typedef uapsd_response__queue0_ac_e                  uapsd_response__queue4_ac_e;
typedef uapsd_response__queue0_ac_e                  uapsd_response__queue5_ac_e;
typedef uapsd_response__queue0_ac_e                  uapsd_response__queue6_ac_e;
typedef uapsd_response__queue0_ac_e                  uapsd_response__queue7_ac_e;
typedef uapsd_response__queue0_ac_e                  uapsd_response__queue8_ac_e;
typedef uapsd_response__queue0_ac_e                  uapsd_response__queue9_ac_e;

//-----------------------------------------------------------------------------
// "add_frame_cmd" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_MAX_COLUMN_A                                  = 0,
  WIFI_MAX_COLUMN_B                                  = 1,
  WIFI_MAX_COLUMN_C                                  = 2,
  WIFI_MAX_COLUMN_D                                  = 3
} add_frame_cmd__rate_offset_e;                      ///< rate_offset Enum Type

//-----------------------------------------------------------------------------
// "flush_qid_cmd" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_FLUSH_ALL                                     = 0,
  WIFI_FLUSH_RETRY_ONLY                              = 1
} flush_qid_cmd__flush_ctrl_e;                       ///< flush_ctrl Enum Type

//-----------------------------------------------------------------------------
// "scheduler_cmd" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_BASIC                                         = 0,
  WIFI_START_AFTER_BO_OR_ONGOING                     = 1
} scheduler_cmd__txop_time_ctrl_e;                   ///< txop_time_ctrl Enum Type
typedef enum {
  WIFI_20MHZ_NDP                                     = 0,
  WIFI_40MHZ_NDP                                     = 1,
  WIFI_80MHZ_NDP                                     = 2
} scheduler_cmd__ndp_frame_bw_e;                     ///< ndp_frame_bw Enum Type
typedef enum {
  WIFI_SW_TRANSMIT_MODE                              = 0,
  WIFI_PDG_TRANSMIT_MODE                             = 1
} scheduler_cmd__fes_control_mode_e;                 ///< fes_control_mode Enum Type
typedef enum {
  WIFI_SIFS                                          = 0,
  WIFI_PIFS                                          = 1
} scheduler_cmd__burst_continuation_ifs_time_e;      ///< burst_continuation_ifs_time Enum Type
typedef enum {
  WIFI_TSF1                                          = 0,
  WIFI_TSF2                                          = 1,
  WIFI_WB_TIMER                                      = 2,
  WIFI_QUEUE_TIMER0                                  = 3,
  WIFI_QUEUE_TIMER1                                  = 4
} scheduler_cmd__start_time_reference_e;             ///< start_time_reference Enum Type
typedef scheduler_cmd__start_time_reference_e        scheduler_cmd__end_time_reference_e;

//-----------------------------------------------------------------------------
// "update_desc_cmd" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_MPDU_LINK_                                    = 0,
  WIFI_MPDU_LINK_EXT_                                = 1,
  WIFI_MSDU_LINK_                                    = 2,
  WIFI_MSDU_LINK_EXT_                                = 3,
  WIFI_MPDU_QUEUE_                                   = 4,
  WIFI_MPDU_QUEUE_EXT_                               = 5
} update_desc_cmd__desc_type_e;                      ///< desc_type Enum Type

//-----------------------------------------------------------------------------
// "mpdu_queue_head_info" enums
//-----------------------------------------------------------------------------
typedef add_frame_cmd__rate_offset_e                 mpdu_queue_head_info__rate_offset_e;

//-----------------------------------------------------------------------------
// "pcu_ppdu_setup" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_REGULAR_TRANSMISSION                          = 0
} pcu_ppdu_setup__transmit_fes_type_e;               ///< transmit_fes_type Enum Type
typedef enum {
  WIFI_NO_PROTECTION                                 = 0,
  WIFI_RTS_LEGACY                                    = 1,
  WIFI_RTS_11AC_STATIC_BW                            = 2,
  WIFI_RTS_11AC_DYNAMIC_BW                           = 3,
  WIFI_CTS2SELF                                      = 4
} pcu_ppdu_setup__medium_prot_type_e;                ///< medium_prot_type Enum Type
typedef enum {
  WIFI_NO_RESPONSE_EXPECTED                          = 0,
  WIFI_ACK_EXPECTED                                  = 1,
  WIFI_BA_EXPECTED                                   = 2,
  WIFI_ACTIONNOACK_EXPECTED                          = 3,
  WIFI_ACK_BA_EXPECTED                               = 4,
  WIFI_CTS_EXPECTED                                  = 5,
  WIFI_ACK_DATA_EXPECTED                             = 6,
  WIFI_ANY_RESPONSE_ACCEPTED                         = 7
} pcu_ppdu_setup__su_response_type_e;                ///< su_response_type Enum Type
typedef tx_location_req__location_type_e             pcu_ppdu_setup__location_type_e;

//-----------------------------------------------------------------------------
// "pdg_bypass" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_NO_ACTION                                     = 0,
  WIFI_GENERATE_LOWER_4BIT                           = 1,
  WIFI_GENERATE_LOWER_5BIT                           = 2,
  WIFI_GENERATE_ALL_7BIT                             = 3
} pdg_bypass__mprot_scrambler_seed_mode_e;           ///< mprot_scrambler_seed_mode Enum Type
typedef pdg_bypass__mprot_scrambler_seed_mode_e      pdg_bypass__ppdu_scrambler_seed_mode_e;

//-----------------------------------------------------------------------------
// "pdg_fes_setup" enums
//-----------------------------------------------------------------------------
typedef pcu_ppdu_setup__transmit_fes_type_e          pdg_fes_setup__transmit_fes_type_e;
typedef pcu_ppdu_setup__medium_prot_type_e           pdg_fes_setup__medium_prot_type_e;
typedef pcu_ppdu_setup__su_response_type_e           pdg_fes_setup__su_response_type_e;
typedef tx_location_req__location_type_e             pdg_fes_setup__location_type_e;
typedef tx_phy_desc__bf_type_e                       pdg_fes_setup__bf_type_e;
typedef tx_phy_desc__clpc_enable_e                   pdg_fes_setup__clpc_en_e;
typedef tx_phy_desc__measure_power_e                 pdg_fes_setup__measure_power_e;
typedef enum {
  WIFI_SET_DUR_ZERO                                  = 0,
  WIFI_PROTECT_ENTIRE_FES                            = 1,
  WIFI_PROTECT_ENTIRE_TXOP                           = 2
} pdg_fes_setup__duration_field_ctrl_e;              ///< duration_field_ctrl Enum Type
typedef enum {
  WIFI_LEGACY_MODE                                   = 0,
  WIFI_GEN_4BIT_STATIC                               = 1,
  WIFI_GEN_4BIT_DYNAMIC                              = 2,
  WIFI_GEN_5BIT                                      = 3,
  WIFI_GEN_7BIT                                      = 4
} pdg_fes_setup__hw_mode_mprot_scrambler_seed_mode_e; ///< hw_mode_mprot_scrambler_seed_mode Enum Type
typedef pdg_fes_setup__hw_mode_mprot_scrambler_seed_mode_e pdg_fes_setup__hw_mode_ppdu_scrambler_seed_mode_e;

//-----------------------------------------------------------------------------
// "pdg_response" enums
//-----------------------------------------------------------------------------
typedef pre_tx_phy_desc__heavy_clip_nss_e            pdg_response__nss_e;
typedef enum {
  WIFI_OFDM_RESP                                     = 0,
  WIFI_CCK_RESP                                      = 1,
  WIFI_CBF                                           = 2,
  WIFI_RTT_HTVHT_RESP                                = 3,
  WIFI_RTT_LEGACY_RESP                               = 4
} pdg_response__response_type_e;                     ///< response_type Enum Type

//-----------------------------------------------------------------------------
// "ppdu_tx_phy_desc" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_RESPONSE_20BW                                 = 0,
  WIFI_RESPONSE_40BW                                 = 1,
  WIFI_RESPONSE_80BW                                 = 2
} ppdu_tx_phy_desc__pdg_sifs_response_bw_e;          ///< pdg_sifs_response_bw Enum Type

//-----------------------------------------------------------------------------
// "rx_message" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_RX_MSG_RX_PHY_OFF                             = 0,
  WIFI_RX_MSG_RX_PHY_ON                              = 1,
  WIFI_RX_MSG_RX_PHY_NAP                             = 2,
  WIFI_RX_MSG_RX_CHAIN_MASK                          = 3,
  WIFI_RX_MSG_TX_EXPECT_NDP                          = 4,
  WIFI_RX_MSG_REQ_IMPLICIT_FB                        = 5,
  WIFI_RX_MSG_TX_MAC_TIMEOUT                         = 6,
  WIFI_RX_MSG_TX_CBF_OFFSET                          = 7,
  WIFI_RX_MSG_CLEAR_NDPA_FLAG                        = 8,
  WIFI_RX_MSG_TX_FREEZE_CAPTURE_CHANNEL              = 9
} rx_message__message_type_e;                        ///< message_type Enum Type
typedef tx_expect_ndp__feedback_type_e               rx_message__ndp_feedback_type_e;
typedef enum {
  WIFI_ALLOW_CHANNEL_CAPTURE                         = 0,
  WIFI_FREEZE_CHANNEL_CAPTURE                        = 1
} rx_message__freeze_e;                              ///< freeze Enum Type

//-----------------------------------------------------------------------------
// "rx_mpdu_pcu_start" enums
//-----------------------------------------------------------------------------
typedef peer_entry__key_type_e                       rx_mpdu_pcu_start__encrypt_type_e;
typedef peer_entry__decap_type_e                     rx_mpdu_pcu_start__decap_type_e;

//-----------------------------------------------------------------------------
// "rx_mpdu_start" enums
//-----------------------------------------------------------------------------
typedef peer_entry__key_type_e                       rx_mpdu_start__encrypt_type_e;

//-----------------------------------------------------------------------------
// "rx_msdu_start" enums
//-----------------------------------------------------------------------------
typedef msdu_link__encap_type_e                      rx_msdu_start__decap_format_e;

//-----------------------------------------------------------------------------
// "rx_ppdu_start" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_LEGACY                                        = 4,
  WIFI_HT                                            = 8,
  WIFI_VHT                                           = 12
} rx_ppdu_start__preamble_type_e;                    ///< preamble_type Enum Type

//-----------------------------------------------------------------------------
// "rx_resp" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_20MHZ_CBF                                     = 0,
  WIFI_40MHZ_CBF                                     = 1,
  WIFI_80MHZ_CBF                                     = 2
} rx_resp__cbf_bw_e;                                 ///< cbf_bw Enum Type
typedef enum {
  WIFI_NC_1                                          = 0,
  WIFI_NC_2                                          = 1,
  WIFI_NC_3                                          = 2,
  WIFI_NC_4                                          = 3,
  WIFI_NC_5                                          = 4,
  WIFI_NC_6                                          = 5,
  WIFI_NC_7                                          = 6,
  WIFI_NC_8                                          = 7
} rx_resp__cbf_nc_index_e;                           ///< cbf_nc_index Enum Type
typedef enum {
  WIFI_NR_1                                          = 0,
  WIFI_NR_2                                          = 1,
  WIFI_NR_3                                          = 2,
  WIFI_NR_4                                          = 3,
  WIFI_NR_5                                          = 4,
  WIFI_NR_6                                          = 5,
  WIFI_NR_7                                          = 6,
  WIFI_NR_8                                          = 7
} rx_resp__cbf_nr_index_e;                           ///< cbf_nr_index Enum Type
typedef enum {
  WIFI_SU                                            = 0,
  WIFI_MU                                            = 1
} rx_resp__cbf_feedback_type_e;                      ///< cbf_feedback_type Enum Type

//-----------------------------------------------------------------------------
// "scheduler_transmit_status" enums
//-----------------------------------------------------------------------------
typedef enum {
  WIFI_SCH_CMD_RING_NUMBER0                          = 0,
  WIFI_SCH_CMD_RING_NUMBER1                          = 1,
  WIFI_SCH_CMD_RING_NUMBER2                          = 2,
  WIFI_SCH_CMD_RING_NUMBER3                          = 3,
  WIFI_SCH_CMD_RING_NUMBER4                          = 4,
  WIFI_SCH_CMD_RING_NUMBER5                          = 5,
  WIFI_SCH_CMD_RING_NUMBER6                          = 6,
  WIFI_SCH_CMD_RING_NUMBER7                          = 7,
  WIFI_SCH_CMD_RING_NUMBER8                          = 8,
  WIFI_SCH_CMD_RING_NUMBER9                          = 9,
  WIFI_SCH_CMD_RING_NUMBER10                         = 10,
  WIFI_SCH_CMD_RING_NUMBER11                         = 11,
  WIFI_SCH_CMD_RING_NUMBER12                         = 12,
  WIFI_SCH_CMD_RING_NUMBER13                         = 13,
  WIFI_SCH_CMD_RING_NUMBER14                         = 14,
  WIFI_SCH_CMD_RING_NUMBER15                         = 15
} scheduler_transmit_status__schedule_cmd_ring_id_e; ///< schedule_cmd_ring_id Enum Type
typedef scheduler_cmd__fes_control_mode_e            scheduler_transmit_status__fes_control_mode_e;
typedef enum {
  WIFI_NOT_STALLED                                   = 0,
  WIFI_STALLED_ON_UNSUCCESSFUL_TRANSMIT              = 1,
  WIFI_STALLED_ON_CBF_LOWER_BW                       = 2,
  WIFI_STALLED_ON_EXCESSIVE_REQUEUE                  = 3
} scheduler_transmit_status__cmd_ring_stall_status_e; ///< cmd_ring_stall_status Enum Type
typedef enum {
  WIFI_SUCCESS                                       = 0,
  WIFI_SU_RESPONSE_TYPE_MISMATCH_FAIL                = 1,
  WIFI_CBF_MIMO_CTRL_MISMATCH_FAIL                   = 2,
  WIFI_LIFESPAN_EXPIRY_FAIL                          = 3,
  WIFI_MAX_SCHEDULE_RETRY_COUNT_FAIL                 = 4,
  WIFI_QCU_FILTERED                                  = 5,
  WIFI_LOWER_CBF_BW_FAIL                             = 6,
  WIFI_FLUSH_RCVD                                    = 7
} scheduler_transmit_status__sch_cmd_result_e;       ///< sch_cmd_result Enum Type
typedef enum {
  WIFI_NO_SIFS_BURST                                 = 0,
  WIFI_SIFS_BURST_IN_PROGRESS                        = 1,
  WIFI_SIFS_BURST_END                                = 2,
  WIFI_SIFS_BURST_PAUSE_ON_FILTER                    = 3,
  WIFI_SIFS_BURST_SPLIT                              = 4,
  WIFI_SIFS_BURST_COMPLETE_IN_PIFS                   = 5,
  WIFI_SIFS_BURST_PAUSE_ON_REQUEUE                   = 6,
  WIFI_SIFS_BURST_PAUSE_ON_NO_NEXT_CMD               = 7
} scheduler_transmit_status__sifs_burst_status_e;    ///< sifs_burst_status Enum Type
typedef tx_flush_req__flush_req_reason_e             scheduler_transmit_status__flush_req_reason_e;

//-----------------------------------------------------------------------------
// "tx_cbf_info" enums
//-----------------------------------------------------------------------------
typedef tx_expect_ndp__feedback_type_e               tx_cbf_info__ndp_feedback_type_e;

//-----------------------------------------------------------------------------
// "tx_fes_setup" enums
//-----------------------------------------------------------------------------
typedef scheduler_transmit_status__schedule_cmd_ring_id_e tx_fes_setup__schedule_cmd_ring_id_e;
typedef scheduler_cmd__fes_control_mode_e            tx_fes_setup__fes_control_mode_e;
typedef enum {
  WIFI_MASK_DISABLE                                  = 0,
  WIFI_MASK_ENABLE                                   = 1
} tx_fes_setup__fc_to_ds_mask_e;                     ///< fc_to_ds_mask Enum Type
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__fc_from_ds_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__fc_more_frag_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__fc_retry_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__fc_pwr_mgt_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__fc_more_data_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__fc_prot_frame_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__fc_order_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__duration_field_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__sequence_control_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__qc_tid_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__qc_eosp_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__qc_ack_policy_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__qc_amsdu_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__qc_15to8_mask_e;
typedef tx_fes_setup__fc_to_ds_mask_e                tx_fes_setup__iv_mask_e;
typedef enum {
  WIFI_CLEAR                                         = 0,
  WIFI_SET                                           = 1
} tx_fes_setup__fc_to_ds_setting_e;                  ///< fc_to_ds_setting Enum Type
typedef tx_fes_setup__fc_to_ds_setting_e             tx_fes_setup__fc_from_ds_setting_e;
typedef tx_fes_setup__fc_to_ds_setting_e             tx_fes_setup__fc_more_frag_setting_e;
typedef enum {
  WIFI_FC_RETRY_CLEAR                                = 0,
  WIFI_FC_RETRY_SET                                  = 1,
  WIFI_FC_RETRY_BIMAP_BASED                          = 2
} tx_fes_setup__fc_retry_setting_e;                  ///< fc_retry_setting Enum Type
typedef tx_fes_setup__fc_to_ds_setting_e             tx_fes_setup__fc_pwr_mgt_setting_e;
typedef enum {
  WIFI_FC_MORE_DATA_CLEAR                            = 0,
  WIFI_FC_MORE_DATA_SET                              = 1,
  WIFI_FC_MORE_DATA_PDG_BASED                        = 2
} tx_fes_setup__fc_more_data_setting_e;              ///< fc_more_data_setting Enum Type
typedef enum {
  WIFI_FC_PROT_FRAME_CLEAR                           = 0,
  WIFI_FC_PROT_FRAME_SET                             = 1,
  WIFI_FC_PROT_FRAME_ENCAP_TYPE_BASED                = 2
} tx_fes_setup__fc_prot_frame_setting_e;             ///< fc_prot_frame_setting Enum Type
typedef tx_fes_setup__fc_to_ds_setting_e             tx_fes_setup__fc_order_setting_e;
typedef enum {
  WIFI_QC_EOSP_CLEAR                                 = 0,
  WIFI_QC_EOSP_SET                                   = 1,
  WIFI_QC_EOSP_PDG_BASED                             = 2
} tx_fes_setup__qc_eosp_setting_e;                   ///< qc_eosp_setting Enum Type
typedef tx_fes_setup__fc_to_ds_setting_e             tx_fes_setup__qc_ack_policy_setting_e;
typedef tx_fes_setup__fc_to_ds_setting_e             tx_fes_setup__qc_amsdu_setting_e;
typedef enum {
  WIFI_FROM_PEER_ENTRY                               = 0,
  WIFI_FROM_PPDU                                     = 1
} tx_fes_setup__mprot_addr_sel_e;                    ///< mprot_addr_sel Enum Type
typedef tx_bf_params__static_bandwidth_e             tx_fes_setup__static_bandwidth_e;
typedef tx_phy_desc__bf_type_e                       tx_fes_setup__bf_type_e;
typedef rx_resp__cbf_nc_index_e                      tx_fes_setup__cbf_nc_index_e;
typedef rx_resp__cbf_nr_index_e                      tx_fes_setup__cbf_nr_index_e;
typedef tx_bf_params__static_bandwidth_e             tx_fes_setup__cbf_bw_e;
typedef rx_resp__cbf_feedback_type_e                 tx_fes_setup__cbf_feedback_type_e;

//-----------------------------------------------------------------------------
// "tx_fes_status" enums
//-----------------------------------------------------------------------------
typedef scheduler_transmit_status__schedule_cmd_ring_id_e tx_fes_status__schedule_cmd_ring_id_e;
typedef scheduler_cmd__fes_control_mode_e            tx_fes_status__fes_control_mode_e;
typedef enum {
  WIFI_TX_OK                                         = 0,
  WIFI_PROT_RESP_RX_TIMEOUT                          = 1,
  WIFI_PPDU_RESP_RX_TIMEOUT                          = 2,
  WIFI_FLUSH_CMD_RCVD                                = 3,
  WIFI_FES_ERROR                                     = 4,
  WIFI_TX_PHY_ERROR                                  = 5,
  WIFI_RESP_FRAME_CRC_ERR                            = 6,
  WIFI_SU_RESPONSE_TYPE_MISMATCH                     = 7,
  WIFI_CBF_MIMO_CTRL_MISMATCH                        = 8
} tx_fes_status__fes_transmit_result_e;              ///< fes_transmit_result Enum Type
typedef enum {
  WIFI_NO_ERROR                                      = 0,
  WIFI_PREAMBLE_TIMEOUT                              = 1
} tx_fes_status__fes_error_status_e;                 ///< fes_error_status Enum Type
typedef pcu_ppdu_setup__transmit_fes_type_e          tx_fes_status__transmit_fes_type_e;
typedef pcu_ppdu_setup__medium_prot_type_e           tx_fes_status__medium_prot_type_e;
typedef pcu_ppdu_setup__su_response_type_e           tx_fes_status__response_type_e;
typedef enum {
  WIFI_NO_DATA_UNDERRUN                              = 0,
  WIFI_DATA_UNDERRUN_BETWEEN_MPDU                    = 1,
  WIFI_DATA_UNDERRUN_WITHIN_MPDU                     = 2
} tx_fes_status__data_underflow_warning_e;           ///< data_underflow_warning Enum Type
typedef rx_resp__cbf_bw_e                            tx_fes_status__cbf_bw_received_e;
typedef enum {
  WIFI_NO_RESP_RCVD                                  = 0,
  WIFI_ACK_RCVD                                      = 1,
  WIFI_BA_RCVD                                       = 2,
  WIFI_ACTIONNOACK_RCVD                              = 3,
  WIFI_DATA_RCVD                                     = 4,
  WIFI_CTS_RCVD                                      = 5,
  WIFI_OTHERS_RCVD                                   = 6
} tx_fes_status__response_frame_rcvd_e;              ///< response_frame_rcvd Enum Type


#endif // _WIFI_TLV_ENUM_H_
