/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// <copyright file="dgblog_rtt_host.h" company="Atheros">
//    Copyright (c) 2015 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

// Descriptive messages for the RTT CALL FLOW debug messages.
// Indexed by the value passed to the call flow logging function.
char const * const RTT_CALL_FLOW_MSG[] = {
    "WLAN_RTT_SCHED_REQ",
    "WLAN_RTT_SCHEDULE",
    "WLAN_RTT_SCHED_RELEASE",
    "WLAN_RTT_SCHED_DEL",
    "WLAN_RTT_RUN_NEXT_INIT",
    "UNKNOWN",
    "UNKNOWN",
    "WLAN_WMI_OEM_REQ",
    "WLAN_OEM_RTT_MEASREQ_HDL",
    "WLAN_RTT_CAP_MSG_REQ_HDL",
    "WLAN_WMI_RTT_MEASREQ",
    "WLAN_RTT_MEAS_REQ_INIT",
    "WLAN_RTT_INIT_HANDLER",
    "WLAN_RTT_NULL_HANDLER",
    "WLAN_RTT_TMR_HANDLER",
    "WLAN_RTT_CHAN_SWITCH",
    "WLAN_RTT_CHAN_SWITCH_HDL",
    "WLAN_RTT_TMR_START_RX_HDL <<<<<<<<<<<<<<<<<<<<<<<FTMR<<<<<<<<<<<<<<<<<<<<<<",
    "WLAN_RTT_TMR_END_RX_HDL >>>>>>>>>>>>>>>>>>>>>>>FTMR END>>>>>>>>>>>>>>>>>>>>",
    "WLAN_RTT_TM_RX_HDL >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>FTM>>>>>>>>>>>>>>>>>>>>>>>",
    "UNKNOWN",
    "UNKNOWN",
    "UNKNOWN",
    "UNKNOWN",
    
    "WLAN_RTT_SEND_NULL_FRAME >>>>>>>>>>>>>>>>>>>>>>>>NULL>>>>>>>>>>>>>>>>>>>>>>",
    "WLAN_RTT_SEND_TMR_START <<<<<<<<<<<<<<<<<<<<<<<<<FTMR<<<<<<<<<<<<<<<<<<<<<<",
    "WLAN_RTT_SEND_TMR_END <<<<<<<<<<<<<<<<<<<<<<<<<FTMR END<<<<<<<<<<<<<<<<<<<<",
    "WLAN_RTT_SEND_TM_FRAME >>>>>>>>>>>>>>>>>>>>>>>>>>FTM>>>>>>>>>>>>>>>>>>>>>>>",
    "WLAN_RTT_NULL_ACK_HDL",
    "WLAN_RTT_TMR_START_ACK_HDL",
    "WLAN_RTT_TM_ACK_HDL",
    "WLAN_RTT_LOCAL_SEND",
    "UNKNOWN",
    "UNKNOWN",
    "UNKNOWN",
    
    "WLAN_RTT_RESP_INIT",
    "WLAN_RTT_RESP_DELAY_HANDLER",
    "WLAN_RTT_TIMEOUT_HANDLER",
    "WLAN_RTT_SPS_TIMEOUT_HANDLER",
    "UNKNOWN",
    "UNKNOWN",
    "UNKNOWN",
    "UNKNOWN",
    "UNKNOWN",
    "UNKNOWN",
    
    "WMI_SEND_RTT_ERROR_REPORT_EVENT",
    "WLAN_RTT_MEASUEMENT_REPORT2",
    "WLAN_RTT_MEASUREMENT_REPORT",
    "WLAN_RTT_EXIT_CLEAN",
    
    "WLAN_RTT_SEND_TMR_WITH_IE",
    "WLAN_RTT_RECV_FTM1",
    "WLAN_RTT_START_FTM1_TIMER",
    "WLAN_RTT_FTM1_INIT/RESP_TIMER_FIRED",
    "WLAN_RTT_FTM1_TIMER_STOP",
    "WLAN_RTT_START_BURST_TIMER =============BURST START================================",
    "WLAN_RTT_BURST_TIMER_FIRED =============BURST END==================================",
    "WLAN_RTT_BURST_TIMER_STOP ==============BURST STOPPED==============================",
    "WLAN_RTT_START_FTM_DELTA_TIMER",
    "WLAN_RTT_DELTA_TIMER_FIRED",
    "WLAN_RTT_FTM_DELTA_TIMER_STOP",
    "WLAN_RTT_SEND_FTM1",
    "WLAN_RTT_SEND_FTM1_COMPLETE",
    "WLAN_RTT_RECV_TMR_WITH_IE",
    "WLAN_RTT_RESP_EXIT_CLEAN",
    "WLAN_RTT_SEND_FTM1_RETRY",
    "WLAN_RTT_FTM1_EXCEED_MAX_RETRY",
    "WLAN_RTT_START_TMR_RETRY_TIMER",
    "WLAN_RTT_TMR_RETRY_TIMER_STOP",
    "WLAN_RTT_TMR_RETRY_TIMER_FIRED",
    "WLAN_RTT_TMR_BUSY_REPLY",
    "WLAN_RTT_START_PTSF_TIMER",
    "WLAN_RTT_PTSF_TIMER_STOP",
    "WLAN_RTT_PTSF_TIMER_FIRED"
    
};
size_t const RTT_CALL_FLOW_MSG_MAX = sizeof(RTT_CALL_FLOW_MSG) / sizeof(RTT_CALL_FLOW_MSG[0]);

// Descriptive error messages for the RTT error debug message reports.
// Indexed by the value passed to the error report logging function.
char const * const RTT_ERR_MSG[] = {
    "ALLOCATE_FRAME_BUFFER_ERROR",
    "RTT_FRAME_TX_FAIL",
    "RTT_WAL_FRAME_TX_OK --------------------------------------------ACK-----------------------",
    "RTT_WAL_FRAME_TX_FAIL_XRETRY xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxNO ACKxxxxxxxxxxxxxxxxxxxxxx",
    "RTT_WAL_FRAME_TX_DROP xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxNO ACKxxxxxxxxxxxxxxxxxxxxxx",
    "RTT_MODULE_BUSY",
    "RTT_GET_TM_NOTWAIT_TM",
    "RTT UNKNOWN ERROR",
    "TM_TOKEN_MISMATCH",
    "TM_CFR_CAPTURE_ERROR",
    "TM_SEQUENCE_RESTART",
    "RTT_GET_INVALID_TMR_STOP",
    "RTT_RESP_BUSY",
    "RTT_RESP_CTXT_EXIST",
    "RTT_RESP_REQ_ACCEPT",
    "RTT_WAL_FRAME_TX_FILTERED xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxNO ACKxxxxxxxxxxxxxxxxxxxxxx",
};
size_t const RTT_ERR_MSG_MAX = sizeof(RTT_ERR_MSG) / sizeof(RTT_ERR_MSG[0]);

// FTM Protocol burst duration decoding
// Used to pretty-print the burst_duration field in the FTM Parameter Info IE
// See 802.11mc specification, section 8.4.2.166
static char const * dbglog_rtt_get_burst_duration_str(
		A_UINT32 burst_duration_index) {
    switch(burst_duration_index & 0xF) {
        case 2: return "250 us";
        case 3: return "500 us";
        case 4: return "1 ms";
        case 5: return "2 ms";
        case 6: return "4 ms";
        case 7: return "8 ms";
        case 8: return "16 ms";
        case 9: return "32 ms";
        case 10: return "64 ms";
        case 11: return "128 ms";
        case 15: return "No Preference";
        default: return "Reserved";
    }
}

// FMT Protocol channel and bandwidth decoding
// Used to pretty-print the FMT Channel and Bandwidth field in the FTM
// Parameter Info information element.
// See 802.11mc specification, section 8.4.2.166
static char const * dbglog_rtt_get_format_and_bandwidth_str(
		A_UINT32 ftm_format_and_bandwidth) {
    switch(ftm_format_and_bandwidth & 0x3F) {
        case 0:  return "No Preference";
        case 4:  return "Non-HT 5 MHz";
        case 6:  return "Non-HT 10 MHz";
        case 8:  return "Non-HT 20 MHz";
        case 9:  return "HT mixed 20 MHz";
        case 10: return "VHT 20 MHz";
        case 11: return "HT mixed 40 MHz";
        case 12: return "VHT 40 MHz";
        case 13: return "VHT 80 MHz";
        case 14: return "VHT Noncontiguous 80+80 MHz";
        case 15: return "VHT Contiguous 160 MHz (2 LO)";
        case 16: return "VHT Contiguous 160 MHz (1 LO)";
        case 31: return "DMG 2160";
        default: return "Reserved";
    }
}

// FTM Protocol status field decoding
// Used to pretty-print the "status" field in the FTM Parameter Info IE
// See 802.11mc specification, section 8.4.2.166
static char const * RTT_FTM_PARAM_STATUS_STR[] = {
    "Reserved",
    "Success",
    "Incapable",
    "Failed"
};
