/*
 * Copyright (c) 2010, 2013-2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// <copyright file="wmi_unified.h" company="Atheros">
//    Copyright (c) 2004-2010, 2013 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

#ifndef _RTT_INTF_H_
#define _RTT_INTF_H_


#ifdef __cplusplus
extern "C" {
#endif

#ifndef _WMI_UNIFIED_H_
typedef enum {
    /* 0 to 2 are reserved */
    WMI_GRP_START = 0x3,
    WMI_GRP_SCAN = WMI_GRP_START,
    WMI_GRP_PDEV,
    WMI_GRP_VDEV,
    WMI_GRP_PEER,
    WMI_GRP_MGMT,
    WMI_GRP_BA_NEG,
    WMI_GRP_STA_PS,
    WMI_GRP_DFS,
    WMI_GRP_ROAM,
    WMI_GRP_OFL_SCAN,
    WMI_GRP_P2P,
    WMI_GRP_AP_PS,
    WMI_GRP_RATE_CTRL,
    WMI_GRP_PROFILE,
    WMI_GRP_SUSPEND,
    WMI_GRP_BCN_FILTER,
    WMI_GRP_WOW,
    WMI_GRP_RTT,
    WMI_GRP_SPECTRAL,
    WMI_GRP_STATS,
    WMI_GRP_ARP_NS_OFL,
    WMI_GRP_NLO_OFL,
    WMI_GRP_GTK_OFL,
    WMI_GRP_CSA_OFL,
    WMI_GRP_CHATTER,
    WMI_GRP_TID_ADDBA,
    WMI_GRP_MISC,
    WMI_GRP_GPIO,
    WMI_GRP_FWTEST,
    WMI_GRP_TDLS,
    WMI_GRP_RESMGR,
    WMI_GRP_STA_SMPS,
} WMI_GRP_ID;

#define WMI_CMD_GRP_START_ID(grp_id) (((grp_id) << 12) | 0x1)
#define WMI_EVT_GRP_START_ID(grp_id) (((grp_id) << 12) | 0x1)

/*
 * These don't necessarily belong here; but as the MS/SM macros require
 * ar6000_internal.h to be included, it may not be defined as yet.
 */
#define WMI_F_MS(_v, _f)                                            \
            ( ((_v) & (_f)) >> (_f##_S) )

/*
 * This breaks the "good macro practice" of only referencing each
 * macro field once (to avoid things like field++ from causing issues.)
 */
#define WMI_F_RMW(_var, _v, _f)                                     \
            do {                                                    \
                (_var) &= ~(_f);                                    \
                (_var) |= ( ((_v) << (_f##_S)) & (_f));             \
            } while (0)


/** 2 word representation of MAC addr */
typedef struct {
    /** upper 4 bytes of  MAC address */
    A_UINT32 mac_addr31to0;
    /** lower 2 bytes of  MAC address */
    A_UINT32 mac_addr47to32;
} wmi_mac_addr;

typedef enum {
    /* RTT measurement related cmd */
    /** reques to make an RTT measurement */
    WMI_RTT_MEASREQ_CMDID = WMI_CMD_GRP_START_ID(WMI_GRP_RTT),
    /** reques to report a tsf measurement */
    WMI_RTT_TSF_CMDID

} WMI_RTT_CMD_ID;

typedef enum {
    /*RTT related event ID*/
    /** RTT measurement report */
    WMI_RTT_MEASUREMENT_REPORT_EVENTID = WMI_EVT_GRP_START_ID(WMI_GRP_RTT),
    /** TSF measurement report */
    WMI_TSF_MEASUREMENT_REPORT_EVENTID,
    /** RTT error report */
    WMI_RTT_ERROR_REPORT_EVENTID,

} WMI_RTT_EVT_ID;

#endif

/* Currently we give max length is 32 * SIZEOF(MAC_ADDRS) + 3 + 1(padding) */
#define MAX_COLOCATED_INFO_LEN 196

/*
 * Mesage format for WMI_RTT_TSF_CMDID
 * This CMD trigger FW to report TSF Measurement result to host
 */
typedef struct {
    A_UINT32 req_id; //unique request ID for this TSF measure req
    wmi_mac_addr dest_mac; //destination mac address for measurement
    wmi_mac_addr spoof_bssid; //spoof BSSID for measurement with unassociated STA
    A_UINT32 vdev_id; // vdev used for TSF
    A_UINT32 time_out; //timeout for this TSF mesurement (ms)
    /* This TLV is followed by below TLVs:
     *     wmi_channel channel;          //channel information for this Requirement
     */
} wmi_rtt_tsf_cmd;

/*
 * Message format for WMI_RTT_KEEPALIVE_CMDID
 * This command tells the firmware to keep the connection 
 */
typedef struct {
    A_UINT32 req_id;
    /******************************************************************************
     *bit 15:0       Request ID
     *bit 16:        action  0: start  1: stop
     *bit 31:17      reserved
     ******************************************************************************/
    A_UINT32 control_flag;
    A_UINT32 probe_info;
    /******************************************************************************
     *Bit 7:0 vdev_id vdev used for RTT
     *Bit 15:8 period of the keepalive probing (ms)
     *Bit 23:16 max retry count for this keepalive probing
     *Bit 31:24 reserved
     ******************************************************************************/
    wmi_mac_addr sta_mac;          /* MAC addr of the client to be probed */
} wmi_rtt_keepalive_cmd;

/*
 * Mesage format for WMI_RTT_MEASREQ_CMDID
 * This CMD trigger FW to start measurement with a peer
 * Need be careful about 32 alignment if any change made in future
 */
typedef struct { //any new change need take care of 32 alignment
    A_UINT32 control_flag; // some control information here
    /*********************************************************************************
     *Bits 1:0:   Reserved
     *Bits 4:2:   802.11 Frame Type to measure RTT
     *            000: NULL, 001: Qos NULL, 010: TMR-TM
     *Bits 8:5:   Tx chain mask used for transmission 0000 - 1111
     *Bits 12:9:  Receive chainmask to use for reception 0000 - 1111
     *Bits 13:13  peer is qca chip or not
     *Bits 15:14: BW 0- 20MHz 1- 40MHz 2- 80MHz 3 - 160 MHz
     *Bits 17:16: Preamble 0- Legacy 2- HT 3-VHT
     *Bits 21:18: Retry times
     *Bits 29:22  MCS
     *Bits 31:30  Reserved
     *********************************************************************************/
    A_UINT32 measure_info;
    /*******************************************************************************
     *Bit 7:0:   vdev_id vdev used for RTT
     *Bit 15:8:  num_meas #of measurements of each peer
     *Bit 23:16: timeout for this rtt mesurement (ms)
     *Bit 31:24: report_type
     *******************************************************************************/
    wmi_mac_addr dest_mac; //destination mac address for measurement
    wmi_mac_addr spoof_bssid; //spoof BSSID for measurement with unassociated STA
    A_UINT32 measure_params_1;
    /*******************************************************************************
     *Bit 0:       ASAP = 0/1
     *Bit 1:       LCI Req = True/False
     *Bit 2:       Location Civic Req = True/False
     *Bit 3:       TSF Delta Valid 1:True 0:False
     *Bits 7:4     Reserved
     *Bits 11:8:   Number of Bursts Exponent
     *Bits 15:12:  Burst Duration
     *Bits 31:16:  Burst Period (time between Bursts)
     *******************************************************************************/
    A_UINT32 measure_params_2;
    /*******************************************************************************
     *Bits 31:0:   TSF Delta
     *******************************************************************************/
} wmi_rtt_measreq_body;

typedef struct {
    /** primary 20 MHz channel frequency in mhz */ 
    A_UINT32 mhz;
    /** Center frequency 1 in MHz*/
    A_UINT32 band_center_freq1;
    /** Center frequency 2 in MHz - valid only for 11acvht 80plus80 mode*/
    A_UINT32 band_center_freq2;
    /** channel info described below */ 
    A_UINT32 info; 
    /** contains min power, max power, reg power and reg class id.  */ 
    A_UINT32 reg_info_1;
    /** contains antennamax */
    A_UINT32 reg_info_2;
} wmi_rtt_channel;

typedef struct { //notice on 32 bit alignment if need do any further change
    A_UINT32 req_id; //unique request ID for this RTT measure req
    /******************************************************************************
     *bit 15:0       Request ID
     *bit 16:        sps enable  0- unenable  1--enable
     *bit 31:17      reserved
     ******************************************************************************/
    A_UINT32 sta_num; // how many number of STA in this RTT requirement
    /******************************************************************************
     *bit 7:0        # of measurement peers
     *bit 23:8       if  sps, time delay for SPS (ms)
     *bit 31:24      reserved
     ******************************************************************************/
    wmi_rtt_channel channel;
		
    wmi_rtt_measreq_body body[1];

} wmi_rtt_measreq_head;


typedef enum {
    MOTION_NOT_EXPECTED = 0, // Not expected to change location
    MOTION_EXPECTED = 1,     // Expected to change location
    MOTION_UNKNOWN  = 2,     // Movement pattern unknown
} wmi_rtt_z_subelem_motion_pattern;


typedef struct {
    A_UINT32 req_id; //unique request ID for this RTT measure req
    /******************************************************************************
     *bits 15:0       Request ID
     *bit  16:        sps enable  0- unenable  1--enable
     *bits 31:17      reserved
     ******************************************************************************/
    A_UINT64 latitude;             // LS 34 bits - latitude in degrees * 2^25 , 2's complement
    A_UINT64 longitude;            // LS 34 bits - latitude in degrees * 2^25 , 2's complement
    A_UINT32 lci_cfg_param_info;   // Uncertainities & motion pattern cfg
    /******************************************************************************
     *bits 7:0       Latitude_uncertainity as defined in Section 2.3.2 of IETF RFC 6225
     *bits 15:8      Longitude_uncertainity as defined in Section 2.3.2 of IETF RFC 6225   
     *bits 18:16     Datum
     *bits 19:19     RegLocAgreement
     *bits 20:20     RegLocDSE
     *bits 21:21     Dependent State
     *bits 23:22     Version
     *bits 27:24     motion_pattern for use with z subelement cfg as per
                     wmi_rtt_z_subelem_motion_pattern
     *bits 28:28     co-located BSSIDs info is present
     *bits 30:29     Reserved
     *bits 31:31     Clear LCI - Force LCI to "Unknown"
      ******************************************************************************/
    A_UINT32 altitude;             // LS 30bits - Altitude in units of 1/256 m
    A_UINT32 altitude_info;
    /******************************************************************************
     *bits 7:0       Altitude_uncertainity as defined in Section 2.4.5 of IETF RFC 6225
     *bits 15:8      Altitude type
     *bits 31:16     Reserved
      ******************************************************************************/
     //Following elements for configuring the Z subelement 
    A_UINT32  floor;               // in units 1/16th of floor # if known. 
                                   // value is 80000000 if unknown. 
    A_UINT32  floor_param_info;    // height_above_floor & uncertainity 
    /******************************************************************************
     *bits 23:0      Height above floor in units of 1/4096 m
     *bits 31:14     Height uncertainity as defined in 802.11REVmc D4.0 Z subelem format
                     value 0 means unknown, values 1-18 are valid and 19 and above are reserved
      ******************************************************************************/
    A_UINT32  usage_rules;
    /******************************************************************************
     *bit  0         usage_rules: retransmittion allowed: 0-No 1-Yes
     *bit  1         usage_rules: retention expires relative present: 0-No 1-Yes
     *bit  2         usage_rules: STA Location policy for Additional neighbor info: 0-No 1-Yes
     *bits 7:3       usage_rules: reserved
     *bits 23:8      usage_rules: retention expires relative, if present, as per IETF RFC 4119
     *bits 31:24     reserved
      ******************************************************************************/
    A_UINT32 co_located_bssid_len;
    /******************************************************************************
     *bit  15:0      Length of co-located bssid info
     *bit  31:16     reserved
     ******************************************************************************/
    A_UINT8  colocated_bssids_info[MAX_COLOCATED_INFO_LEN];
} wmi_rtt_lci_cfg_head;

typedef struct {
    A_UINT32 req_id; //unique request ID for this RTT measure req
    /******************************************************************************
     *bit 15:0       Request ID
     *bit 16:        sps enable  0- unenable  1--enable
     *bit 31:17      reserved
     ******************************************************************************/
    A_UINT32 loc_civic_params; // country code and length
    /******************************************************************************
     *bit 7:0        len in bytes. civic_info to be used in reference to this. 
     *bit 31:8       reserved
     ******************************************************************************/
    A_UINT32 civic_info[64];      // Civic info including country_code to be copied in FTM frame. 
                                  // 256 bytes max. Based on len, FW will copy byte-wise into 
                                  // local buffers and transfer OTA. This is packed as a 4 bytes   
                                  // aligned buffer at this interface for transfer to FW though.  
} wmi_rtt_lcr_cfg_head;

typedef struct { //notice on 32 bit alignment if need do any further change
    A_UINT32 sub_type;   
    /*******************************************************************************
     * TARGET_OEM_CAPABILITY_REQ       0x01
     * TARGET_OEM_CAPABILITY_RSP       0x02
     * TARGET_OEM_MEASUREMENT_REQ      0x03
     * TARGET_OEM_MEASUREMENT_RSP      0x04
     * TARGET_OEM_ERROR_REPORT_RSP     0x05
     * TARGET_OEM_NAN_MEAS_REQ         0x06
     * TARGET_OEM_NAN_MEAS_RSP         0x07
     * TARGET_OEM_NAN_PEER_INFO        0x08
     * TARGET_OEM_CONFIGURE_LCR        0x09
     * TARGET_OEM_CONFIGURE_LCI        0x0A
     *******************************************************************************/
    wmi_rtt_measreq_head head;
} wmi_oem_measreq_head;

typedef struct {
    A_UINT32 nan_availability_intvl_bmap;
    A_UINT32 nan_ranging_info;
    /*********************************************************************************
     *Bits 7:0:   nan_availability_invl_dur: 0: 16ms; 1: 32ms; 2:64ms; 3..255: Reserved
     *Bits 15:8   nan_operating_class: Per ieee std
     *Bits 23:16  nan_control_flags 
     *            b'0: if 1 availability info maintained across DW or until updated by the FW
     *            if 0: availability information is only valid till next DW.  b'1..b7: reserved
     *Bits 31:24  nan_ranging_cap: b'0: 1 FTM (802.11Revmc 2.1); b'1..b'7 reserved
     *********************************************************************************/
} wmi_rtt_nan_ranging_info;

typedef struct {
    wmi_rtt_channel channel; //channel target should switch to
    A_UINT32 control_flag; // some control information here
    /*********************************************************************************
     *Bits 1:0:   Reserved
     *Bits 4:2:   802.11 Frame Type to measure RTT
     *            000: NULL, 001: Qos NULL, 010: TMR-TM
     *Bits 8:5:   Tx chain mask used for transmission 0000 - 1111
     *Bits 12:9:  Receive chainmask to use for reception 0000 - 1111
     *Bits 13:13  peer is qca chip or not
     *Bits 15:14: BW 0- 20MHz 1- 40MHz 2- 80MHz 3 - 160 MHz
     *Bits 17:16: Preamble 0- Legacy 2- HT 3-VHT
     *Bits 21:18: Retry times
     *Bits 29:22  MCS
     *Bits 31:30  Reserved
     *********************************************************************************/
    A_UINT32 measure_info;
    /*******************************************************************************
     *Bit 7:0:   vdev_id vdev used for RTT
     *Bit 15:8:  num_meas #of measurements of each peer
     *Bit 23:16: timeout for this rtt mesurement (ms)
     *Bit 31:24: report_type
     *******************************************************************************/
    wmi_mac_addr dest_mac; //destination mac address for measurement
    wmi_mac_addr spoof_bssid; //spoof BSSID for measurement with unassociated STA
    wmi_rtt_nan_ranging_info nan_info; //NAN peer ranging info
} wmi_rtt_nan_req_cmd;

typedef struct {
    A_UINT32 req_id; //unique request ID for this RTT measure req
    /******************************************************************************
     *bit 15:0       Request ID
     *bit 16:        sps enable  0- unenable  1--enable
     *bit 31:17      reserved
     ******************************************************************************/
    A_UINT32 bssid_num; // how many number of STA in this RTT requirement
    /******************************************************************************
     *bit 7:0        # of measurement peers
     *bit 23:8       if  sps, time delay for SPS (ms)
     *bit 31:24      reserved
     ******************************************************************************/
    wmi_rtt_nan_req_cmd cmd[1];
} wmi_rtt_nan_req_head;

//Bit map macro define for RTT measurement command
#define RTT_MEAS_FRAME_NULL 0
#define RTT_MEAS_FRAME_QOSNULL 1
#define RTT_MEAS_FRAME_TMR 2
#define RTT_MEAS_FRAME_KEEPALIVE 3

#define WMI_RTT_BW_20 0
#define WMI_RTT_BW_40 1
#define WMI_RTT_BW_80 2
#define WMI_RTT_BW_160 3

#define WMI_RTT_PREAM_LEGACY 0
#define WMI_RTT_PREAM_HT 2
#define WMI_RTT_PREAM_VHT 3

/*nan availability interval duration*/
#define WMI_RTT_NAN_AVAI_INVL_DUR_16_MS     0
#define WMI_RTT_NAN_AVAI_INVL_DUR_32_MS     1
#define WMI_RTT_NAN_AVAI_INVL_DUR_64_MS     2

/*nan contro flags b'0*/
#define WMI_RTT_NAN_AVAI_ACRS_DW            0x1

/*nan ranging cap b'0*/
#define WMI_RTT_NAN_CAP_FTM_SUPPORTED       0x1

#define WMI_RTT_SUB_TYPE_S 0
#define WMI_RTT_SUB_TYPE (0xffffffff << WMI_RTT_SUB_TYPE_S)
#define WMI_RTT_SUB_TYPE_GET(x) WMI_F_MS(x,WMI_RTT_SUB_TYPE)
#define WMI_RTT_SUB_TYPE_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_SUB_TYPE)

#define WMI_RTT_REQ_ID_S 0
#define WMI_RTT_REQ_ID (0xffff << WMI_RTT_REQ_ID_S)
#define WMI_RTT_REQ_ID_GET(x) WMI_F_MS(x,WMI_RTT_REQ_ID)
#define WMI_RTT_REQ_ID_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_REQ_ID)

//SPS here is synchronized power save
#define WMI_RTT_SPS_S 16
#define WMI_RTT_SPS (0x1 << WMI_RTT_SPS_S)
#define WMI_RTT_SPS_GET(x) WMI_F_MS(x,WMI_RTT_SPS)
#define WMI_RTT_SPS_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_SPS)

#define WMI_RTT_NUM_STA_S 0
#define WMI_RTT_NUM_STA (0xff << WMI_RTT_NUM_STA_S)
#define WMI_RTT_NUM_STA_GET(x) WMI_F_MS(x,WMI_RTT_NUM_STA)
#define WMI_RTT_NUM_STA_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_NUM_STA)

#define WMI_RTT_SPS_DELAY_S 8
#define WMI_RTT_SPS_DELAY (0xffff << WMI_RTT_SPS_DELAY_S)
#define WMI_RTT_SPS_DELAY_GET(x) WMI_F_MS(x,WMI_RTT_SPS_DELAY)
#define WMI_RTT_SPS_DELAY_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_SPS_DELAY)

//req body Macro
#define WMI_RTT_FRAME_TYPE_S 2
#define WMI_RTT_FRAME_TYPE (7 << WMI_RTT_FRAME_TYPE_S)
#define WMI_RTT_FRAME_TYPE_GET(x) WMI_F_MS(x,WMI_RTT_FRAME_TYPE)
#define WMI_RTT_FRAME_TYPE_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_FRAME_TYPE)

#define WMI_RTT_TX_CHAIN_S 5
#define WMI_RTT_TX_CHAIN (0xf << WMI_RTT_TX_CHAIN_S)
#define WMI_RTT_TX_CHAIN_GET(x) WMI_F_MS(x,WMI_RTT_TX_CHAIN)
#define WMI_RTT_TX_CHAIN_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_TX_CHAIN)

#define WMI_RTT_RX_CHAIN_S 9
#define WMI_RTT_RX_CHAIN (0xf << WMI_RTT_RX_CHAIN_S)
#define WMI_RTT_RX_CHAIN_GET(x) WMI_F_MS(x,WMI_RTT_RX_CHAIN)
#define WMI_RTT_RX_CHAIN_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_RX_CHAIN)

#define WMI_RTT_QCA_PEER_S 13
#define WMI_RTT_QCA_PEER (0x1 << WMI_RTT_QCA_PEER_S)
#define WMI_RTT_QCA_PEER_GET(x) WMI_F_MS(x,WMI_RTT_QCA_PEER)
#define WMI_RTT_QCA_PEER_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_QCA_PEER)

#define WMI_RTT_BW_S 14
#define WMI_RTT_BW (0x3 <<WMI_RTT_BW_S)
#define WMI_RTT_BW_GET(x) WMI_F_MS(x,WMI_RTT_BW)
#define WMI_RTT_BW_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_BW)

#define WMI_RTT_PREAMBLE_S 16
#define WMI_RTT_PREAMBLE (0x3 <<WMI_RTT_PREAMBLE_S)
#define WMI_RTT_PREAMBLE_GET(x) WMI_F_MS(x,WMI_RTT_PREAMBLE)
#define WMI_RTT_PREAMBLE_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_PREAMBLE)

#define WMI_RTT_RETRIES_S 18
#define WMI_RTT_RETRIES (0xf << WMI_RTT_RETRIES_S)
#define WMI_RTT_RETRIES_GET(x) WMI_F_MS(x,WMI_RTT_RETRIES)
#define WMI_RTT_RETRIES_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_RETRIES)

#define WMI_RTT_MCS_S 22
#define WMI_RTT_MCS (0xff << WMI_RTT_MCS_S)
#define WMI_RTT_MCS_GET(x) WMI_F_MS(x,WMI_RTT_MCS)
#define WMI_RTT_MCS_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_MCS)

#define WMI_RTT_VDEV_ID_S 0
#define WMI_RTT_VDEV_ID (0xff << WMI_RTT_VDEV_ID_S)
#define WMI_RTT_VDEV_ID_GET(x) WMI_F_MS(x,WMI_RTT_VDEV_ID)
#define WMI_RTT_VDEV_ID_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_VDEV_ID)

#define WMI_RTT_MEAS_NUM_S 8
#define WMI_RTT_MEAS_NUM (0xff << WMI_RTT_MEAS_NUM_S)
#define WMI_RTT_MEAS_NUM_GET(x) WMI_F_MS(x,WMI_RTT_MEAS_NUM)
#define WMI_RTT_MEAS_NUM_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_MEAS_NUM)

#define WMI_RTT_TIMEOUT_S 16
#define WMI_RTT_TIMEOUT (0xff << WMI_RTT_TIMEOUT_S)
#define WMI_RTT_TIMEOUT_GET(x) WMI_F_MS(x,WMI_RTT_TIMEOUT)
#define WMI_RTT_TIMEOUT_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_TIMEOUT)

#define WMI_RTT_REPORT_TYPE_S 24
#define WMI_RTT_REPORT_TYPE (0x3 <<WMI_RTT_REPORT_TYPE_S)
#define WMI_RTT_REPORT_TYPE_GET(x) WMI_F_MS(x,WMI_RTT_REPORT_TYPE)
#define WMI_RTT_REPORT_TYPE_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_REPORT_TYPE)

#define WMI_RTT_ASAP_MODE_S 0
#define WMI_RTT_ASAP_MODE (0x1 <<WMI_RTT_ASAP_MODE_S)
#define WMI_RTT_ASAP_MODE_GET(x) WMI_F_MS(x,WMI_RTT_ASAP_MODE)
#define WMI_RTT_ASAP_MODE_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_ASAP_MODE)

#define WMI_RTT_LCI_REQ_S 1
#define WMI_RTT_LCI_REQ (0x1 <<WMI_RTT_LCI_REQ_S)
#define WMI_RTT_LCI_REQ_GET(x) WMI_F_MS(x,WMI_RTT_LCI_REQ)
#define WMI_RTT_LCI_REQ_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_REQ)

#define WMI_RTT_LOC_CIV_REQ_S 2
#define WMI_RTT_LOC_CIV_REQ (0x1 <<WMI_RTT_LOC_CIV_REQ_S)
#define WMI_RTT_LOC_CIV_REQ_GET(x) WMI_F_MS(x,WMI_RTT_LOC_CIV_REQ)
#define WMI_RTT_LOC_CIV_REQ_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LOC_CIV_REQ)

#define WMI_RTT_TSF_DELTA_VALID_S 3
#define WMI_RTT_TSF_DELTA_VALID (0x1 <<WMI_RTT_TSF_DELTA_VALID_S)
#define WMI_RTT_TSF_DELTA_VALID_GET(x) WMI_F_MS(x,WMI_RTT_TSF_DELTA_VALID)
#define WMI_RTT_TSF_DELTA_VALID_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_TSF_DELTA_VALID)
// TODO: Temp defines to allow the host and other FW components to continue to compile as this is integrated.
// Delete these four defines once the transition has been completed.
#define WMI_RTT_PART_TSF_VALID_S WMI_RTT_TSF_DELTA_VALID_S
#define WMI_RTT_PART_TSF_VALID WMI_RTT_TSF_DELTA_VALID
#define WMI_RTT_PART_TSF_VALID_GET(x) WMI_RTT_TSF_DELTA_VALID_GET(x)
#define WMI_RTT_PART_TSF_VALID_SET(x,z) WMI_RTT_TSF_DELTA_VALID_SET(x,z)

#define WMI_RTT_NUM_BURST_EXP_S 8
#define WMI_RTT_NUM_BURST_EXP (0xf <<WMI_RTT_NUM_BURST_EXP_S)
#define WMI_RTT_NUM_BURST_EXP_GET(x) WMI_F_MS(x,WMI_RTT_NUM_BURST_EXP)
#define WMI_RTT_NUM_BURST_EXP_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_NUM_BURST_EXP)

#define WMI_RTT_BURST_DUR_S 12
#define WMI_RTT_BURST_DUR (0xf <<WMI_RTT_BURST_DUR_S)
#define WMI_RTT_BURST_DUR_GET(x) WMI_F_MS(x,WMI_RTT_BURST_DUR)
#define WMI_RTT_BURST_DUR_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_BURST_DUR)

#define WMI_RTT_BURST_PERIOD_S 16
#define WMI_RTT_BURST_PERIOD (0xffff <<WMI_RTT_BURST_PERIOD_S)
#define WMI_RTT_BURST_PERIOD_GET(x) WMI_F_MS(x,WMI_RTT_BURST_PERIOD)
#define WMI_RTT_BURST_PERIOD_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_BURST_PERIOD)

#define WMI_RTT_TSF_DELTA_S 0
#define WMI_RTT_TSF_DELTA (0xffffffff <<WMI_RTT_TSF_DELTA_S)
#define WMI_RTT_TSF_DELTA_GET(x) WMI_F_MS(x,WMI_RTT_TSF_DELTA)
#define WMI_RTT_TSF_DELTA_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_TSF_DELTA)

#define WMI_RTT_LCI_LAT_UNC_S 0
#define WMI_RTT_LCI_LAT_UNC (0xff << WMI_RTT_LCI_LAT_UNC_S)
#define WMI_RTT_LCI_LAT_UNC_GET(x) WMI_F_MS(x,WMI_RTT_LCI_LAT_UNC)
#define WMI_RTT_LCI_LAT_UNC_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_LAT_UNC)

#define WMI_RTT_LCI_LON_UNC_S 8
#define WMI_RTT_LCI_LON_UNC (0xff << WMI_RTT_LCI_LON_UNC_S)
#define WMI_RTT_LCI_LON_UNC_GET(x) WMI_F_MS(x,WMI_RTT_LCI_LON_UNC)
#define WMI_RTT_LCI_LON_UNC_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_LON_UNC)

#define WMI_RTT_LCI_DATUM_S 16
#define WMI_RTT_LCI_DATUM (0x7 << WMI_RTT_LCI_DATUM_S)
#define WMI_RTT_LCI_DATUM_GET(x) WMI_F_MS(x,WMI_RTT_LCI_DATUM)
#define WMI_RTT_LCI_DATUM_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_DATUM)

#define WMI_RTT_LCI_REG_LOC_AGMT_S 19
#define WMI_RTT_LCI_REG_LOC_AGMT (0x1 << WMI_RTT_LCI_REG_LOC_AGMT_S)
#define WMI_RTT_LCI_REG_LOC_AGMT_GET(x) WMI_F_MS(x,WMI_RTT_LCI_REG_LOC_AGMT)
#define WMI_RTT_LCI_REG_LOC_AGMT_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_REG_LOC_AGMT)

#define WMI_RTT_LCI_REG_LOC_DSE_S 20
#define WMI_RTT_LCI_REG_LOC_DSE (0x1 << WMI_RTT_LCI_REG_LOC_DSE_S)
#define WMI_RTT_LCI_REG_LOC_DSE_GET(x) WMI_F_MS(x,WMI_RTT_LCI_REG_LOC_DSE)
#define WMI_RTT_LCI_REG_LOC_DSE_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_REG_LOC_DSE)

#define WMI_RTT_LCI_DEP_STA_S 21
#define WMI_RTT_LCI_DEP_STA (0x1 << WMI_RTT_LCI_DEP_STA_S)
#define WMI_RTT_LCI_DEP_STA_GET(x) WMI_F_MS(x,WMI_RTT_LCI_DEP_STA)
#define WMI_RTT_LCI_DEP_STA_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_DEP_STA)

#define WMI_RTT_LCI_VERSION_S 22
#define WMI_RTT_LCI_VERSION (0x3 << WMI_RTT_LCI_VERSION_S)
#define WMI_RTT_LCI_VERSION_GET(x) WMI_F_MS(x,WMI_RTT_LCI_VERSION)
#define WMI_RTT_LCI_VERSION_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_VERSION)

#define WMI_RTT_LCI_Z_MOTION_PAT_S 24
#define WMI_RTT_LCI_Z_MOTION_PAT (0xf << WMI_RTT_LCI_Z_MOTION_PAT_S)
#define WMI_RTT_LCI_Z_MOTION_PAT_GET(x) WMI_F_MS(x,WMI_RTT_LCI_Z_MOTION_PAT)
#define WMI_RTT_LCI_Z_MOTION_PAT_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_Z_MOTION_PAT)

#define WMI_RTT_COLOCATED_BSSIDS_IS_PRESENT_S 28
#define WMI_RTT_COLOCATED_BSSIDS_IS_PRESENT  (0x1 << WMI_RTT_COLOCATED_BSSIDS_IS_PRESENT_S)
#define WMI_RTT_COLOCATED_BSSIDS_IS_PRESENT_GET(x) WMI_F_MS(x,WMI_RTT_COLOCATED_BSSIDS_IS_PRESENT)
#define WMI_RTT_COLOCATED_BSSIDS_IS_PRESENT_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_COLOCATED_BSSIDS_IS_PRESENT)

#define WMI_RTT_LCI_CLEAR_S 31
#define WMI_RTT_LCI_CLEAR (0x1 << WMI_RTT_LCI_CLEAR_S)
#define WMI_RTT_LCI_CLEAR_GET(x) WMI_F_MS(x,WMI_RTT_LCI_CLEAR)
#define WMI_RTT_LCI_CLEAR_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_CLEAR)

#define WMI_RTT_LCI_ALT_UNC_S 0
#define WMI_RTT_LCI_ALT_UNC (0xff << WMI_RTT_LCI_ALT_UNC_S)
#define WMI_RTT_LCI_ALT_UNC_GET(x) WMI_F_MS(x,WMI_RTT_LCI_ALT_UNC)
#define WMI_RTT_LCI_ALT_UNC_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_ALT_UNC)

#define WMI_RTT_LCI_ALT_TYPE_S 8
#define WMI_RTT_LCI_ALT_TYPE (0xff << WMI_RTT_LCI_ALT_TYPE_S)
#define WMI_RTT_LCI_ALT_TYPE_GET(x) WMI_F_MS(x,WMI_RTT_LCI_ALT_TYPE)
#define WMI_RTT_LCI_ALT_TYPE_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_ALT_TYPE)

#define WMI_RTT_LCI_Z_HEIGHT_ABV_FLR_S 0
#define WMI_RTT_LCI_Z_HEIGHT_ABV_FLR (0xffffff << WMI_RTT_LCI_Z_HEIGHT_ABV_FLR_S)
#define WMI_RTT_LCI_Z_HEIGHT_ABV_FLR_GET(x) WMI_F_MS(x,WMI_RTT_LCI_Z_HEIGHT_ABV_FLR)
#define WMI_RTT_LCI_Z_HEIGHT_ABV_FLR_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_Z_HEIGHT_ABV_FLR)

#define WMI_RTT_LCI_Z_HEIGHT_UNC_S 24
#define WMI_RTT_LCI_Z_HEIGHT_UNC (0xff << WMI_RTT_LCI_Z_HEIGHT_UNC_S)
#define WMI_RTT_LCI_Z_HEIGHT_UNC_GET(x) WMI_F_MS(x,WMI_RTT_LCI_Z_HEIGHT_UNC)
#define WMI_RTT_LCI_Z_HEIGHT_UNC_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_Z_HEIGHT_UNC)

#define WMI_RTT_LCI_USG_RUL_RETRANS_ALLOWED_S 0
#define WMI_RTT_LCI_USG_RUL_RETRANS_ALLOWED (0x1 << WMI_RTT_LCI_USG_RUL_RETRANS_ALLOWED_S)
#define WMI_RTT_LCI_USG_RUL_RETRANS_ALLOWED_GET(x) WMI_F_MS(x,WMI_RTT_LCI_USG_RUL_RETRANS_ALLOWED)
#define WMI_RTT_LCI_USG_RUL_RETRANS_ALLOWED_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_USG_RUL_RETRANS_ALLOWED)

#define WMI_RTT_LCI_USG_RUL_RETENTION_EXP_S 1
#define WMI_RTT_LCI_USG_RUL_RETENTION_EXP (0x1 << WMI_RTT_LCI_USG_RUL_RETENTION_EXP_S)
#define WMI_RTT_LCI_USG_RUL_RETENTION_EXP_GET(x) WMI_F_MS(x,WMI_RTT_LCI_USG_RUL_RETENTION_EXP)
#define WMI_RTT_LCI_USG_RUL_RETENTION_EXP_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_USG_RUL_RETENTION_EXP)

#define WMI_RTT_LCI_USG_RUL_STA_LOC_POLICY_S 2
#define WMI_RTT_LCI_USG_RUL_STA_LOC_POLICY (0x1 << WMI_RTT_LCI_USG_RUL_STA_LOC_POLICY_S)
#define WMI_RTT_LCI_USG_RUL_STA_LOC_POLICY_GET(x) WMI_F_MS(x,WMI_RTT_LCI_USG_RUL_STA_LOC_POLICY)
#define WMI_RTT_LCI_USG_RUL_STA_LOC_POLICY_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_USG_RUL_STA_LOC_POLICY)

#define WMI_RTT_LCI_USG_RUL_RETENTION_EXP_RELATIVE_S 8
#define WMI_RTT_LCI_USG_RUL_RETENTION_EXP_RELATIVE (0xff << WMI_RTT_LCI_USG_RUL_RETENTION_EXP_RELATIVE_S)
#define WMI_RTT_LCI_USG_RUL_RETENTION_EXP_RELATIVE_GET(x) WMI_F_MS(x,WMI_RTT_LCI_USG_RUL_RETENTION_EXP_RELATIVE)
#define WMI_RTT_LCI_USG_RUL_RETENTION_EXP_RELATIVE_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LCI_USG_RUL_RETENTION_EXP_RELATIVE)

#define WMI_RTT_COLOCATED_LENGTH_S 0
#define WMI_RTT_COLOCATED_LENGTH  (0xffff << WMI_RTT_COLOCATED_LENGTH_S)
#define WMI_RTT_COLOCATED_LENGTH_GET(x) WMI_F_MS(x,WMI_RTT_COLOCATED_LENGTH)
#define WMI_RTT_COLOCATED_LENGTH_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_COLOCATED_LENGTH)

#define WMI_RTT_LOC_CIVIC_LENGTH_S 0
#define WMI_RTT_LOC_CIVIC_LENGTH (0xff << WMI_RTT_LOC_CIVIC_LENGTH_S)
#define WMI_RTT_LOC_CIVIC_LENGTH_GET(x) WMI_F_MS(x,WMI_RTT_LOC_CIVIC_LENGTH)
#define WMI_RTT_LOC_CIVIC_LENGTH_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_LOC_CIVIC_LENGTH)

// TODO: Temp defines to allow the host and other FW components to continue to compile as this is integrated.
// Delete these four defines once the transition has been completed.
#define WMI_RTT_PARTIAL_TSF_S WMI_RTT_TSF_DELTA_S
#define WMI_RTT_PARTIAL_TSF WMI_RTT_TSF_DELTA
#define WMI_RTT_PARTIAL_TSF_GET(x) WMI_RTT_TSF_DELTA_GET(x)
#define WMI_RTT_PARTIAL_TSF_SET(x,z) WMI_RTT_TSF_DELTA_SET(x,z)

/* for keepalive request */
#define WMI_RTT_KEEPALIVE_ACTION_S 16
#define WMI_RTT_KEEPALIVE_ACTION (0x1 << WMI_RTT_KEEPALIVE_ACTION_S)
#define WMI_RTT_KEEPALIVE_ACTION_GET(x) WMI_F_MS(x,WMI_RTT_KEEPALIVE_ACTION)
#define WMI_RTT_KEEPALIVE_ACTION_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_KEEPALIVE_ACTION)

#define WMI_RTT_KEEPALIVE_PERIOD_S 8
#define WMI_RTT_KEEPALIVE_PERIOD (0xff << WMI_RTT_KEEPALIVE_PERIOD_S)
#define WMI_RTT_KEEPALIVE_PERIOD_GET(x) WMI_F_MS(x,WMI_RTT_KEEPALIVE_PERIOD)
#define WMI_RTT_KEEPALIVE_PERIOD_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_KEEPALIVE_PERIOD)
/*---end of RTT COMMAND---*/


/*----RTT Report event definition  ----*/
typedef enum {
    RTT_COMMAND_HEADER_ERROR = 0, //rtt cmd header parsing error  --terminate
    RTT_COMMAND_ERROR, //rtt body parsing error -- skip current STA REQ
    RTT_MODULE_BUSY, //rtt no resource        -- terminate
    RTT_TOO_MANY_STA, //STA exceed the support limit -- only server the first n STA
    RTT_NO_RESOURCE, //any allocate failure
    RTT_VDEV_ERROR, //can not find vdev with vdev ID -- skip current STA REQ
    RTT_TRANSIMISSION_ERROR, //Tx failure   -- continiue and measure number--
    RTT_TM_TIMER_EXPIRE, //wait for first TM timer expire   -- terminate current STA measurement
    RTT_FRAME_TYPE_NOSUPPORT, //we do not support RTT measurement with this type of frame
    RTT_TIMER_EXPIRE, //whole RTT measurement timer expire  -- terminate current STA measurement
    RTT_CHAN_SWITCH_ERROR, //channel swicth failed
    RTT_TMR_TRANS_ERROR, //TMR trans error, this dest peer will be skipped
    RTT_NO_REPORT_BAD_CFR_TOKEN, //V3 only. If both CFR and Token mismatch, do not report
    RTT_NO_REPORT_FIRST_TM_BAD_CFR, //For First TM, if CFR is bad, then do not report
    RTT_REPORT_TYPE2_MIX, //do not allow report type2 mix with type 0, 1
    RTT_LCI_CFG_OK, // LCI Configuration OK. - Responder only
    RTT_LCR_CFG_OK, // LCR configuration OK. - Responder only
    RTT_CFG_ERROR,  // Bad configuration LCI (or) LCR request - Responder only
    WMI_RTT_REJECT_MAX,
} WMI_RTT_ERROR_INDICATOR;

typedef struct {
    A_UINT32 req_id; //identify the command and info
    /**result is a bit mask
     *bit 15:0 req_id from measurement request command
     *bit 16: Success 1 / Fail 0
     *bit 17: Measurement Finished 1 / Measurement not Finished 0
     *bit 20:18 RTT measurement Type 000 - NULL 001-QoS_NULL 002 -TMR
     *bit 23:21 report type (0,1,2)
     *bit 25:24 V3 report status (v2 ignore) (report type 2 ignore)
     *    00-Good 01 - Bad CFR 10 -- bad token
     *bit 26:   V3 accomplishment (v2 ignore) (report type 2 ignore)
     *    0 - sending side is not finishing
     *    1 - sending side finish
     *bit 27: V3 start of a TM sequence (v2 ignore) (report type 2 ignore)
     *    0 - not a start frame  1 -- start frame
     *bit 31:28: #of AP inside this report (only for report type 2, 0,1 ignore)
     */
    wmi_mac_addr dest_mac;
//In report type 1 and 2, MAC of the AP
//in report type 2, bit 31:0 is the channel info
} wmi_rtt_event_hdr;

typedef struct {
    wmi_rtt_event_hdr header;
    A_UINT32 rx_chain;
    /************************************************************
     * Bit:0-3:chain mask                                       *
     * Bit 4-5: band width info                                 *
     * 00 --Legacy 20, 01 --HT/VHT20                            *
     * 10 --HT/VHT40, 11 -- VHT80                               *
     ************************************************************/
    A_TIME64 tod; // resolution of 0.1ns
    A_TIME64 toa; // resolution of 0.1ns
//If Measurement type is TMR, should be T3, T4 here A_TIME64
//chain report body will be expand here
//includes rssi + channel dump for each chain
} wmi_rtt_meas_event;

typedef struct {
    A_UINT32 info; 
   /** bits 7:0      IE Element ID
    *  bits 15:8     Length
    *  bits 31:16    IE body */
    /* More 4 byte aligned IE body based on "Length" */ 
    A_UINT32 bytes; 
    /* Any padding (upto 3 bytes) required to make next IE/data start at 4 byte boundary*/
}wmi_rtt_ie;

typedef struct {
    wmi_mac_addr dest_mac;
    A_UINT32 control;
   /** bits 7:0 #of measurement reports in this AP
     * bits 10:8 RTT measurement type
     * bits 31:11 reserved  */
    A_UINT32 result_info1;
    /** bits 15:0: num_frames_attempted
     *  bits 31:16: actual_burst_duration */
    A_UINT32 result_info2;
    /** bits 7:0:   actual_num_frames_per_burst
     *  bits 15:8: retry_after_duration
     *  bits 23:16 actual_burst_exp
     *  bits 24:31 num_ie_in_hdr */
//If event contains an IE, num_ie_in_hdr will be nonzero and based on 
// num_ie_in_hdr, wmi_rtt_ie (s) will follow here. Each IE has a length field 
// according to which wmi_rtt_per_frame_ie_v2 or wmi_rtt_per_frame_ie_v2 will follow 
// the wmi_rtt_ie (s)
} wmi_rtt_per_peer_event_hdr;

typedef struct {
    A_UINT32 rx_bw; // deprecated
    A_UINT32 rssi;
    A_TIME64 tod;
    A_TIME64 toa;
    A_UINT32 tx_rate_info_1;
    /** bits 2:0:  preamble    - 0: OFDM, 1:CCK, 2:HT 3:VHT
     *  bits 6:3:  bw          - 0:20MHz, 1:40Mhz, 2:80Mhz, 3:160Mhz
     *  bits 7:    reserved
     *  bits 15:8: rateMcsIdx  - OFDM/CCK rate code would be as per
     *                           ieee std in the units of 0.5mbps
     *                         - HT/VHT it would be mcs index
     *  31:16: reserved  */
    A_UINT32 tx_rate_info_2;
    /** bits 31:0: TX bit rate in 100kbps */
    A_UINT32 rx_rate_info_1;
    /** bits 2:0:  preamble    - 0: OFDM, 1:CCK, 2:HT 3:VHT
     *  bits 6:3:  bw          - 0:20MHz, 1:40Mhz, 2:80Mhz, 3:160Mhz
     *  bits 7:    reserved
     *  bits 15:8: rateMcsIdx  - OFDM/CCK rate code would be as per
     *                           ieee std in the units of 0.5mbps
     *                         - HT/VHT it would be mcs index
     *  31:16: reserved  */
    A_UINT32 rx_rate_info_2;
    /** bits 31:0: TX bit rate in 100kbps */
} wmi_rtt_per_frame_ie_v2;

typedef struct {
    A_UINT32 rx_bw; // deprecated
    A_UINT32 rssi;
    A_TIME64 t1;
    A_TIME64 t2;
    A_UINT32 t3_del;
    A_UINT32 t4_del;
    A_UINT32 tx_rate_info_1;
    /** bits 2:0:  preamble    - 0: OFDM, 1:CCK, 2:HT 3:VHT
     *  bits 6:3:  bw          - 0:20MHz, 1:40Mhz, 2:80Mhz, 3:160Mhz
     *  bits 7:    reserved
     *  bits 15:8: rateMcsIdx  - OFDM/CCK rate code would be as per
     *                           ieee std in the units of 0.5mbps
     *                         - HT/VHT it would be mcs index
     *  31:16: reserved  */
    A_UINT32 tx_rate_info_2;
    /** bits 31:0: TX bit rate in 100kbps */
    A_UINT32 rx_rate_info_1;
    /** bits 2:0:  preamble    - 0: OFDM, 1:CCK, 2:HT 3:VHT
     *  bits 6:3:  bw          - 0:20MHz, 1:40Mhz, 2:80Mhz, 3:160Mhz
     *  bits 7:    reserved
     *  bits 15:8: rateMcsIdx  - OFDM/CCK rate code would be as per
     *                           ieee std in the units of 0.5mbps
     *                         - HT/VHT it would be mcs index
     *  31:16: reserved  */
    A_UINT32 rx_rate_info_2;
    /** bits 31:0: TX bit rate in 100kbps */
} wmi_rtt_per_frame_ie_v3;


typedef struct {
    wmi_rtt_event_hdr header;
    WMI_RTT_ERROR_INDICATOR reject_reason;
}wmi_rtt_error_report_event;

typedef struct {
    A_UINT32 req_id; //identify the command
    A_UINT32 result; //Successfully or not 0-fail, 1-success
    A_UINT64 peer_tsf; //TSF of peer
    A_UINT64 self_tsf; //Self's TSF
    A_UINT32 beacon_delta; //time delta between peer and self's beacon
} wmi_rtt_tsf_meas_event;

#define RTT_V3_GOOD 0x0
#define RTT_V3_BAD_CFR 0x1
#define RTT_V3_BAD_TOKEN 0x2

#define RTT_REPORT_PER_FRAME_WITH_CFR 0
#define RTT_REPORT_PER_FRAME_NO_CFR   1
#define RTT_AGGREAGET_REPORT_NON_CFR  2 /* DEPRECATED - will be deleted */
#define RTT_AGGREGATE_REPORT_NON_CFR  2

//define RTT report macro
#define WMI_RTT_REPORT_REQ_ID_S 0
#define WMI_RTT_REPORT_REQ_ID (0xffff << WMI_RTT_REPORT_REQ_ID_S)
#define WMI_RTT_REPORT_REQ_ID_GET(x) WMI_F_MS(x, WMI_RTT_REPORT_REQ_ID)
#define WMI_RTT_REPORT_REQ_ID_SET(x,z) WMI_F_RMW(x,z, WMI_RTT_REPORT_REQ_ID)

#define WMI_RTT_REPORT_CHAN_INFO_S 0
#define WMI_RTT_REPORT_CHAN_INFO (0xffffffff << WMI_RTT_REPORT_CHAN_INFO_S)
#define WMI_RTT_REPORT_CHAN_INFO_GET(x) WMI_F_MS(x, WMI_RTT_REPORT_CHAN_INFO)
#define WMI_RTT_REPORT_CHAN_INFO_SET(x,z) WMI_F_RMW(x,z, WMI_RTT_REPORT_CHAN_INFO)


#define WMI_RTT_REPORT_STATUS_S 16
#define WMI_RTT_REPORT_STATUS (0x1 << WMI_RTT_REPORT_STATUS_S)
#define WMI_RTT_REPORT_STATUS_GET(x) WMI_F_MS(x, WMI_RTT_REPORT_STATUS)
#define WMI_RTT_REPORT_STATUS_SET(x,z) WMI_F_RMW(x,z, WMI_RTT_REPORT_STATUS)

#define WMI_RTT_REPORT_FINISH_S 17
#define WMI_RTT_REPORT_FINISH (0x1 << WMI_RTT_REPORT_FINISH_S)
#define WMI_RTT_REPORT_FINISH_GET(x) WMI_F_MS(x, WMI_RTT_REPORT_FINISH)
#define WMI_RTT_REPORT_FINISH_SET(x,z) WMI_F_RMW(x,z, WMI_RTT_REPORT_FINISH)

#define WMI_RTT_REPORT_MEAS_TYPE_S 18
#define WMI_RTT_REPORT_MEAS_TYPE (0x7 << WMI_RTT_REPORT_MEAS_TYPE_S)
#define WMI_RTT_REPORT_MEAS_TYPE_GET(x) WMI_F_MS(x, WMI_RTT_REPORT_MEAS_TYPE)
#define WMI_RTT_REPORT_MEAS_TYPE_SET(x,z) WMI_F_RMW(x,z, WMI_RTT_REPORT_MEAS_TYPE)

#define WMI_RTT_REPORT_REPORT_TYPE_S 21
#define WMI_RTT_REPORT_REPORT_TYPE (0x7 << WMI_RTT_REPORT_REPORT_TYPE_S)
#define WMI_RTT_REPORT_REPORT_TYPE_GET(x) WMI_F_MS(x, WMI_RTT_REPORT_REPORT_TYPE)
#define WMI_RTT_REPORT_REPORT_TYPE_SET(x,z) WMI_F_RMW(x,z, WMI_RTT_REPORT_REPORT_TYPE)

#define WMI_RTT_REPORT_V3_STATUS_S 24
#define WMI_RTT_REPORT_V3_STATUS (0x3 << WMI_RTT_REPORT_V3_STATUS_S)
#define WMI_RTT_REPORT_V3_STATUS_GET(x) WMI_F_MS(x, WMI_RTT_REPORT_V3_STATUS)
#define WMI_RTT_REPORT_V3_STATUS_SET(x,z) WMI_F_RMW(x,z, WMI_RTT_REPORT_V3_STATUS)

#define WMI_RTT_REPORT_V3_FINISH_S 26
#define WMI_RTT_REPORT_V3_FINISH (0x1 << WMI_RTT_REPORT_V3_FINISH_S)
#define WMI_RTT_REPORT_V3_FINISH_GET(x) WMI_F_MS(x, WMI_RTT_REPORT_V3_FINISH)
#define WMI_RTT_REPORT_V3_FINISH_SET(x,z) WMI_F_RMW(x,z, WMI_RTT_REPORT_V3_FINISH)

#define WMI_RTT_REPORT_V3_TM_START_S 27
#define WMI_RTT_REPORT_V3_TM_START (0x1 << WMI_RTT_REPORT_V3_TM_START_S)
#define WMI_RTT_REPORT_V3_TM_START_GET(x) WMI_F_MS(x, WMI_RTT_REPORT_V3_TM_START)
#define WMI_RTT_REPORT_V3_TM_START_SET(x,z) WMI_F_RMW(x,z, WMI_RTT_REPORT_V3_TM_START)

#define WMI_RTT_REPORT_NUM_AP_S 28     //used for only Report Type 2
#define WMI_RTT_REPORT_NUM_AP (0xf << WMI_RTT_REPORT_NUM_AP_S)
#define WMI_RTT_REPORT_NUM_AP_GET(x) WMI_F_MS(x,WMI_RTT_REPORT_NUM_AP)
#define WMI_RTT_REPORT_NUM_AP_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_REPORT_NUM_AP)

//body start here
#define WMI_RTT_REPORT_RX_CHAIN_S 0
#define WMI_RTT_REPORT_RX_CHAIN (0xf << WMI_RTT_REPORT_RX_CHAIN_S)
#define WMI_RTT_REPORT_RX_CHAIN_GET(x) WMI_F_MS(x, WMI_RTT_REPORT_RX_CHAIN)
#define WMI_RTT_REPORT_RX_CHAIN_SET(x,z) WMI_F_RMW(x,z, WMI_RTT_REPORT_RX_CHAIN)

#define WMI_RTT_REPORT_RX_BW_S 4
#define WMI_RTT_REPORT_RX_BW (0x3 << WMI_RTT_REPORT_RX_BW_S)
#define WMI_RTT_REPORT_RX_BW_GET(x) WMI_F_MS(x, WMI_RTT_REPORT_RX_BW)
#define WMI_RTT_REPORT_RX_BW_SET(x,z) WMI_F_RMW(x,z, WMI_RTT_REPORT_RX_BW)

#define WMI_RTT_REPORT_TYPE2_NUM_MEAS_S 0
#define WMI_RTT_REPORT_TYPE2_NUM_MEAS (0xff << WMI_RTT_REPORT_TYPE2_NUM_MEAS_S)
#define WMI_RTT_REPORT_TYPE2_NUM_MEAS_GET(x) WMI_F_MS(x, WMI_RTT_REPORT_TYPE2_NUM_MEAS)
#define WMI_RTT_REPORT_TYPE2_NUM_MEAS_SET(x,z) WMI_F_RMW(x,z, WMI_RTT_REPORT_TYPE2_NUM_MEAS)

#define WMI_RTT_REPORT_TYPE2_MEAS_TYPE_S 8
#define WMI_RTT_REPORT_TYPE2_MEAS_TYPE (0x7 << WMI_RTT_REPORT_TYPE2_MEAS_TYPE_S)
#define WMI_RTT_REPORT_TYPE2_MEAS_TYPE_GET(x) WMI_F_MS(x, WMI_RTT_REPORT_TYPE2_MEAS_TYPE)
#define WMI_RTT_REPORT_TYPE2_MEAS_TYPE_SET(x,z) WMI_F_RMW(x,z, WMI_RTT_REPORT_TYPE2_MEAS_TYPE)

/*---- end of RTT report event definition ----*/
/*----RTT Capability event definition  ----*/
typedef struct {
    A_UINT32 req_id;
    A_UINT32 support;
    /**************************************************************************
     * Bit 8 - 0 Version support
     *    bit 0 -- RTTv2
     *    bit 1 -- RTTv3 (802.11mc prototyping)
     *    Bit 2 -- RTTv3 (802.11mc D4.0)
     *    Bit 7 - 3 Reserved
     * Bit 15 - 8 Supported Frame types
     *    Bit 8   NULL Frame
     *    Bit 9   QoS_NULL Frame
     *    Bit 10  TMR/TM frame
     *    Bit 11  F-TMR/TM
     *    Bit 12  CTS/RTS
     *    Bit 13-15 : Reserved
     * Bit 23 - 16: Max Dests Per Command
     * Bit 31 - 24: Max Measurement per dest
     **************************************************************************/
    A_UINT32 cap;
    /**************************************************************************
     *Bit 7 - 0 Max Channels allowed  (how many channel can in one meas cmd, 1 now)
     *Bit 15 - 8 Max BW allowed
     *    0 - 20MHz, 1-40MHz, 2-80MHz, 3 -160MHz
     *Bit 23 - 16 Preamble Support
     *    Bit 16 -- Legacy
     *    Bit 17 -- HT
     *    Bit 18-- VHT
     *    Bit 19-23: Reserved
     *Bit 24 - 31 Report types support
     *    Bit 24  Report per frame with CFR
     *    Bit 25  Report Per frame without CFR
     *    Bit 26  Aggregate Report without CFR
     *    Bit 19-23: Reserved
     **************************************************************************/
    A_UINT32 cap_2;
    /**************************************************************************
     *Bit 7 - 0  Maximum chain mask, eg. Peregrine 0x07
     *Bit 15 - 8 FAC support, 0-No FAC, 1- SW IFFT 2 -HW-IFFT
     *Bit 24 - 16 # of radios
     *Bit 31 - 25  Reserved
     *************************************************************************/
} wmi_rtt_cap_event;
#define WMI_RTT_CAP_RTTV2                      (0x01)
#define WMI_RTT_CAP_RTTV3                      (0x02)
#define WMI_RTT_CAP_NULL                       (0x01)
#define WMI_RTT_CAP_QOS_NULL                   (0x02)
#define WMI_RTT_CAP_TMR                        (0x04)
#define WMI_RTT_CAP_FTMR                       (0x08)
#define WMI_RTT_CAP_RTS                        (0x10)
#define WMI_RTT_CAP_20M                        (0x0)
#define WMI_RTT_CAP_40M                        (0x01)
#define WMI_RTT_CAP_80M                        (0x02)
#define WMI_RTT_CAP_160M                       (0x03)
#define WMI_RTT_CAP_LEGACY                     (0x01)
#define WMI_RTT_CAP_HT                         (0x02)
#define WMI_RTT_CAP_VHT                        (0x04)
#define WMI_RTT_CAP_REPORT_PER_FRAME_CFR       (0x01)
#define WMI_RTT_CAP_REPORT_PER_FRAME_NO_CFR    (0x02)
#define WMI_RTT_CAP_REPORT_AGGREGATE_NO_CFR    (0x04)
#define WMI_RTT_CAP_NO_FAC                     (0x0)
#define WMI_RTT_CAP_SW_FAC                     (0x01)
#define WMI_RTT_CAP_HW_FAC                     (0x02)

#define WMI_RTT_CAP_VER_S 0
#define WMI_RTT_CAP_VER (0xff <<  WMI_RTT_CAP_VER_S)
#define WMI_RTT_CAP_VER_GET(x) WMI_F_MS(x, WMI_RTT_CAP_VER)
#define WMI_RTT_CAP_VER_SET(x,y)  WMI_F_RMW(x,y, WMI_RTT_CAP_VER)

#define WMI_RTT_CAP_FRAME_S 8
#define WMI_RTT_CAP_FRAME (0xff <<  WMI_RTT_CAP_FRAME_S)
#define WMI_RTT_CAP_FRAME_GET(x) WMI_F_MS(x, WMI_RTT_CAP_FRAME)
#define WMI_RTT_CAP_FRAME_SET(x,y)  WMI_F_RMW(x,y, WMI_RTT_CAP_FRAME)

#define WMI_RTT_CAP_MAX_DES_NUM_S 16
#define WMI_RTT_CAP_MAX_DES_NUM (0xff <<  WMI_RTT_CAP_MAX_DES_NUM_S)
#define WMI_RTT_CAP_MAX_DES_NUM_GET(x) WMI_F_MS(x, WMI_RTT_CAP_MAX_DES_NUM)
#define WMI_RTT_CAP_MAX_DES_NUM_SET(x,y)  WMI_F_RMW(x,y, WMI_RTT_CAP_MAX_DES_NUM)

#define WMI_RTT_CAP_MAX_MEAS_NUM_S 24
#define WMI_RTT_CAP_MAX_MEAS_NUM (0xff <<  WMI_RTT_CAP_MAX_MEAS_NUM_S)
#define WMI_RTT_CAP_MAX_MEAS_NUM_GET(x) WMI_F_MS(x, WMI_RTT_CAP_MAX_MEAS_NUM)
#define WMI_RTT_CAP_MAX_MEAS_NUM_SET(x,y)  WMI_F_RMW(x,y, WMI_RTT_CAP_MAX_MEAS_NUM)

#define WMI_RTT_CAP_MAX_CHAN_NUM_S 0
#define WMI_RTT_CAP_MAX_CHAN_NUM (0xff <<  WMI_RTT_CAP_MAX_CHAN_NUM_S)
#define WMI_RTT_CAP_MAX_CHAN_NUM_GET(x) WMI_F_MS(x, WMI_RTT_CAP_MAX_CHAN_NUM)
#define WMI_RTT_CAP_MAX_CHAN_NUM_SET(x,y)  WMI_F_RMW(x,y, WMI_RTT_CAP_MAX_CHAN_NUM)

#define WMI_RTT_CAP_MAX_BW_S 8
#define WMI_RTT_CAP_MAX_BW (0xff <<  WMI_RTT_CAP_MAX_BW_S)
#define WMI_RTT_CAP_MAX_BW_GET(x) WMI_F_MS(x, WMI_RTT_CAP_MAX_BW)
#define WMI_RTT_CAP_MAX_BW_SET(x,y)  WMI_F_RMW(x,y, WMI_RTT_CAP_MAX_BW)

#define WMI_RTT_CAP_PREAMBLE_S 16
#define WMI_RTT_CAP_PREAMBLE (0xff <<  WMI_RTT_CAP_PREAMBLE_S)
#define WMI_RTT_CAP_PREAMBLE_GET(x) WMI_F_MS(x, WMI_RTT_CAP_PREAMBLE)
#define WMI_RTT_CAP_PREAMBLE_SET(x,y)  WMI_F_RMW(x,y, WMI_RTT_CAP_PREAMBLE)

#define WMI_RTT_CAP_REPORT_TYPE_S 24
#define WMI_RTT_CAP_REPORT_TYPE (0xff <<  WMI_RTT_CAP_REPORT_TYPE_S)
#define WMI_RTT_CAP_REPORT_TYPE_GET(x) WMI_F_MS(x, WMI_RTT_CAP_REPORT_TYPE)
#define WMI_RTT_CAP_REPORT_TYPE_SET(x,y)  WMI_F_RMW(x,y, WMI_RTT_CAP_REPORT_TYPE)

#define WMI_RTT_CAP_MAX_CHAIN_MASK_S 0
#define WMI_RTT_CAP_MAX_CHAIN_MASK (0xff <<  WMI_RTT_CAP_MAX_CHAIN_MASK_S)
#define WMI_RTT_CAP_MAX_CHAIN_MASK_GET(x) WMI_F_MS(x, WMI_RTT_CAP_MAX_CHAIN_MASK)
#define WMI_RTT_CAP_MAX_CHAIN_MASK_SET(x,y)  WMI_F_RMW(x,y, WMI_RTT_CAP_MAX_CHAIN_MASK)

#define WMI_RTT_CAP_FAC_S 8
#define WMI_RTT_CAP_FAC (0xff <<  WMI_RTT_CAP_FAC_S)
#define WMI_RTT_CAP_FAC_GET(x) WMI_F_MS(x, WMI_RTT_CAP_FAC)
#define WMI_RTT_CAP_FAC_SET(x,y)  WMI_F_RMW(x,y, WMI_RTT_CAP_FAC)

#define WMI_RTT_CAP_RADIO_NUM_S 16
#define WMI_RTT_CAP_RADIO_NUM (0xff <<  WMI_RTT_CAP_RADIO_NUM_S)
#define WMI_RTT_CAP_RADIO_NUM_GET(x) WMI_F_MS(x, WMI_RTT_CAP_RADIO_NUM)
#define WMI_RTT_CAP_RADIO_NUM_SET(x,y)  WMI_F_RMW(x,y, WMI_RTT_CAP_RADIO_NUM)

/*nan peer ranging info*/
#define WMI_RTT_NAN_AVAI_INTVL_DUR_S    0
#define WMI_RTT_NAN_AVAI_INTVL_DUR      (0xff << WMI_RTT_NAN_AVAI_INTVL_DUR_S)
#define WMI_RTT_NAN_AVAI_INTVL_DUR_GET(x)  \
                WMI_F_MS(x,WMI_RTT_NAN_AVAI_INTVL_DUR)
#define WMI_RTT_NAN_AVAI_INTVL_DUR_SET(x,z) \
                WMI_F_RMW(x,z,WMI_RTT_NAN_AVAI_INTVL_DUR)

#define WMI_RTT_NAN_OP_CLASS_S          8
#define WMI_RTT_NAN_OP_CLASS            (0xff << WMI_RTT_NAN_OP_CLASS_S)
#define WMI_RTT_NAN_OP_CLASS_GET(x)     WMI_F_MS(x,WMI_RTT_NAN_OP_CLASS)
#define WMI_RTT_NAN_OP_CLASS_SET(x,z)   WMI_F_RMW(x,z,WMI_RTT_NAN_OP_CLASS)

#define WMI_RTT_NAN_CTRL_FLAGS_S        16
#define WMI_RTT_NAN_CTRL_FLAGS          (0xff << WMI_RTT_NAN_CTRL_FLAGS_S)
#define WMI_RTT_NAN_CTRL_FLAGS_GET(x)   WMI_F_MS(x,WMI_RTT_NAN_CTRL_FLAGS)
#define WMI_RTT_NAN_CTRL_FLAGS_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_NAN_CTRL_FLAGS)

#define WMI_RTT_NAN_RANGING_CAP_S       24
#define WMI_RTT_NAN_RANGING_CAP         (0xff << WMI_RTT_NAN_RANGING_CAP_S)
#define WMI_RTT_NAN_RANGING_CAP_GET(x)  \
                WMI_F_MS(x,WMI_RTT_NAN_RANGING_CAP)
#define WMI_RTT_NAN_RANGING_CAP_SET(x,z)    \
                WMI_F_RMW(x,z,WMI_RTT_NAN_RANGING_CAP)

/*responder parameters for ranging scan report 3*/
#define WMI_RTT_RESP_P_PREAMBLE_S       0
#define WMI_RTT_RESP_P_PREAMBLE         (7 << WMI_RTT_RESP_P_PREAMBLE_S)
#define WMI_RTT_RESP_P_PREAMBLE_GET(x)   WMI_F_MS(x,WMI_RTT_RESP_P_PREAMBLE)
#define WMI_RTT_RESP_P_PREAMBLE_SET(x,z) WMI_F_RMW(x,z,WMI_RTT_RESP_P_PREAMBLE)

#define  WMI_RTT_RESP_P_BW_S            3
#define  WMI_RTT_RESP_P_BW              (7 << WMI_RTT_RESP_P_BW_S)
#define  WMI_RTT_RESP_P_BW_GET(x)       WMI_F_MS(x,WMI_RTT_RESP_P_BW)
#define  WMI_RTT_RESP_P_BW_SET(x,z)     WMI_F_RMW(x,z,WMI_RTT_RESP_P_BW)

#define WMI_RTT_RESP_P_MCS_S            6
#define WMI_RTT_RESP_P_MCS              (31 << WMI_RTT_RESP_P_MCS_S)
#define WMI_RTT_RESP_P_MCS_GET(x)       WMI_F_MS(x,WMI_RTT_RESP_P_MCS)
#define WMI_RTT_RESP_P_MCS_SET(x,z)     WMI_F_RMW(x,z,WMI_RTT_RESP_P_MCS)

#define WMI_RTT_RESP_P_RATE_S           11
#define WMI_RTT_RESP_P_RATE             (0x1fffff << WMI_RTT_RESP_P_RATE_S)
#define WMI_RTT_RESP_P_RATE_GET(x)      WMI_F_MS(x,WMI_RTT_RESP_P_RATE)
#define WMI_RTT_RESP_P_RATE_SET(x,z)    WMI_F_RMW(x,z,WMI_RTT_RESP_P_RATE)

/*---- end of RTT capability event definition ----*/
#ifdef __cplusplus
}
#endif

#endif /*_RTT_INTF_H_*/

