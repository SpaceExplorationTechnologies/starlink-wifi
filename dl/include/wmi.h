/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// Copyright (c) 2004-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

/*
 * This file contains the definitions of the WMI protocol specified in the
 * Wireless Module Interface (WMI).  It includes definitions of all the
 * commands and events. Commands are messages from the host to the WM.
 * Events and Replies are messages from the WM to the host.
 *
 * Ownership of correctness in regards to commands
 * belongs to the host driver and the WMI is not required to validate
 * parameters for value, proper range, or any other checking.
 *
 */

#ifndef _WMI_H_
#define _WMI_H_

#ifndef ATH_TARGET
#include "athstartpack.h"
#endif
#include "targcfg.h"
#include "wlan_defs.h"
#include "wmix.h"
#include "wmi_unified.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HTC_PROTOCOL_VERSION    0x0002

#define WMI_PROTOCOL_VERSION    0x0002

#define WMI_MODE_MAX              8
#define WMI_MAX_RATE_MASK         6


PREPACK struct host_app_area_s {
    A_UINT32 wmi_protocol_ver;
} POSTPACK;


typedef enum {
    DATA_MSGTYPE = 0x0,
    CNTL_MSGTYPE,
    SYNC_MSGTYPE,
    OPT_MSGTYPE,
} WMI_MSG_TYPE;


/*
 * Macros for operating on WMI_DATA_HDR (info) field
 */
#define WMI_DATA_HDR_MSG_TYPE_MASK  0x03
#define WMI_DATA_HDR_MSG_TYPE_SHIFT 0

#define WMI_DATA_HDR_UP_MASK        0x07
#define WMI_DATA_HDR_UP_SHIFT       2
/* In AP mode, the same bit (b5) is used to indicate Power save state in
 * the Rx dir and More data bit state in the tx direction.
 */
#define WMI_DATA_HDR_PS_MASK        0x1
#define WMI_DATA_HDR_PS_SHIFT       5

#define WMI_DATA_HDR_MORE_MASK      0x1
#define WMI_DATA_HDR_MORE_SHIFT     5

typedef enum {
    WMI_DATA_HDR_DATA_TYPE_802_3 = 0,
    WMI_DATA_HDR_DATA_TYPE_802_11,
    WMI_DATA_HDR_DATA_TYPE_ACL,
} WMI_DATA_HDR_DATA_TYPE;

/* Bitmap of data header flags */
typedef enum {
    WMI_DATA_HDR_FLAGS_MORE = 0x1,
    WMI_DATA_HDR_FLAGS_EOSP = 0x2,
} WMI_DATA_HDR_FLAGS;

#define WMI_DATA_HDR_DATA_TYPE_MASK     0x3
#define WMI_DATA_HDR_DATA_TYPE_SHIFT    6

#define WMI_DATA_HDR_HAS_MORE_BIT(h) ((h)->info & (WMI_DATA_HDR_MORE_MASK << WMI_DATA_HDR_MORE_SHIFT))

#define WMI_DATA_HDR_IS_MSG_TYPE(h, t)  (((h)->info & (WMI_DATA_HDR_MSG_TYPE_MASK)) == (t))
#define WMI_DATA_HDR_GET_UP(h)    (((h)->info >> WMI_DATA_HDR_UP_SHIFT) & WMI_DATA_HDR_UP_MASK)
#define WMI_DATA_HDR_SET_UP(h, p) (h)->info = (((h)->info & ~(WMI_DATA_HDR_UP_MASK << WMI_DATA_HDR_UP_SHIFT)) | (p << WMI_DATA_HDR_UP_SHIFT))

#define WMI_DATA_HDR_GET_DATA_TYPE(h)   (((h)->info >> WMI_DATA_HDR_DATA_TYPE_SHIFT) & WMI_DATA_HDR_DATA_TYPE_MASK)

#define WMI_DATA_HDR_GET_DOT11(h)   (WMI_DATA_HDR_GET_DATA_TYPE((h)) == WMI_DATA_HDR_DATA_TYPE_802_11)

/* Macros for operating on WMI_DATA_HDR (info2) field */

#define WMI_DATA_HDR_META_MASK      0x7
#define WMI_DATA_HDR_META_SHIFT     13


#define WMI_DATA_HDR_GET_META(h)        (((h)->info2 >> WMI_DATA_HDR_META_SHIFT) & WMI_DATA_HDR_META_MASK)


#define WMI_DATA_HDR_TRIGGER_MASK      0x1
#define WMI_DATA_HDR_TRIGGER_SHIFT     4

#define WMI_DATA_HDR_EOSP_MASK      WMI_DATA_HDR_TRIGGER_MASK
#define WMI_DATA_HDR_EOSP_SHIFT     WMI_DATA_HDR_TRIGGER_SHIFT

#define WMI_DATA_HDR_HAS_EOSP_BIT(h) ((h)->info3 & (WMI_DATA_HDR_EOSP_MASK << WMI_DATA_HDR_EOSP_SHIFT))

#define WMI_DATA_HDR_PAD_BEFORE_DATA_MASK               0xFF
#define WMI_DATA_HDR_PAD_BEFORE_DATA_SHIFT              0x8
#define GET_PAD_BEFORE_DATA_START(_v)                   ((_v) & WMI_DATA_HDR_PAD_BEFORE_DATA_MASK)

#define WMI_DATA_HDR_SET_PAD_BEFORE_DATA_START(h, _v)   ((h)->info3 = ((h)->info3 & ~(WMI_DATA_HDR_PAD_BEFORE_DATA_MASK << WMI_DATA_HDR_PAD_BEFORE_DATA_SHIFT)) | (GET_PAD_BEFORE_DATA_START(_v) << WMI_DATA_HDR_PAD_BEFORE_DATA_SHIFT))

typedef PREPACK struct {
    A_INT8      rssi;
    A_UINT8     info;               /* usage of 'info' field(8-bit):
                                     *  b1:b0       - WMI_MSG_TYPE
                                     *  b4:b3:b2    - UP(tid)
                                     *  b5          - Used in AP mode. More-data in tx dir, PS in rx.
                                     *  b7:b6       -  Dot3 header(0),
                                     *                 Dot11 Header(1),
                                     *                 ACL data(2)
                                     */

    A_UINT16    info2;              /* usage of 'info2' field(16-bit):
                                     * b11:b0       - seq_no
                                     * b12          - A-MSDU?
                                     * b15:b13      - META_DATA_VERSION 0 - 7
                                     */
    A_UINT16    info3;              /* b3:b2:b1:b0  - device id
                                     * b4           - Used in AP mode. uAPSD trigger in rx, EOSP in tx
                                     * b7:b5        - unused?
                                     * b15:b8       - pad before data start(irrespective of meta version)
                                     */
} POSTPACK WMI_DATA_HDR;

/*
 *  TX META VERSION DEFINITIONS
 */
#define WMI_MAX_TX_META_SZ  (12)
#define WMI_META_VERSION_1 (0x01)
#define WMI_META_VERSION_2 (0X02)
#define WMI_META_VERSION_3 (0x03)
#define WMI_META_VERSION_4 (0x04)


typedef PREPACK struct {
    A_UINT8     pktID;           /* The packet ID to identify the tx request */
    A_UINT8     ratePolicyID;    /* The rate policy to be used for the tx of this frame */
} POSTPACK WMI_TX_META_V1;



typedef PREPACK struct {
    A_UINT8    csumStart;       /*Offset from start of the Payload(SNAP header) for csum calculation to begin */
    A_UINT8    csumDest;        /*Offset from start of Payload(SNAP header) where final csum goes*/
    A_UINT8     csumFlags;    /*Flag for check sum engine to be offloaded to device*/
} POSTPACK WMI_TX_META_V2;


/* WMI_TX_RATE_SCHEDULE - Acts as a host-provided rate schedule to replace what would be normally determined
 * by firmware.  This allows the host to specify what rates and attempts should be used to transmit the
 * frame. */
typedef PREPACK struct {
#define WMI_TX_MAX_RATE_SERIES (4)
    A_UINT8 rateSeries[WMI_TX_MAX_RATE_SERIES]; //rate index for each series. first invalid rate terminates series.
    A_UINT8 trySeries[WMI_TX_MAX_RATE_SERIES]; //number of tries for each series.
    A_UINT8 flags; // combination of WMI_META_TX_FLAG...
    A_UINT8 accessCategory; // should be WMM_AC_BE for managment frames and multicast frames.
    //A_UINT8 keyIndex;
    //
}POSTPACK WMI_TX_RATE_SCHEDULE;

#ifdef TIME_BASED_DISCARD
typedef PREPACK struct {
    A_UINT32 txdiscardTime;
    A_UINT8 discardDispostion;
} POSTPACK WMI_TX_META_V4;
#endif

typedef PREPACK struct {
    WMI_TX_RATE_SCHEDULE rateSched;
    A_UINT8     pktID;           /* The packet ID to identify the tx request */
} POSTPACK WMI_TX_META_V3;

/*
 *  RX META VERSION DEFINITIONS
 */
/* if RX meta data is present at all then the meta data field
 *  will consume WMI_MAX_RX_META_SZ bytes of space between the
 *  WMI_DATA_HDR and the payload. How much of the available
 *  Meta data is actually used depends on which meta data
 *  version is active. */
#define WMI_MAX_RX_META_SZ  (12)

#define WMI_RX_FLAGS_AGGR           0x0001 /* part of AGGR */
#define WMI_RX_FlAGS_STBC           0x0002 /* used STBC */
#define WMI_RX_FLAGS_SGI            0x0004 /* used SGI */
#define WMI_RX_FLAGS_HT             0x0008 /* is HT packet */
/* the flags field is also used to store the CRYPTO_TYPE of the frame
 * that value is shifted by WMI_RX_FLAGS_CRYPTO_SHIFT */


#define RX_CSUM_VALID_FLAG (0x1)
typedef PREPACK struct {
    A_UINT16    csum;
    A_UINT8     csumFlags;/* bit 0 set -partial csum valid
                             bit 1 set -test mode */
} POSTPACK WMI_RX_META_V2;

#define WMI_GET_DEVICE_ID(info1) ((info1) & 0xF)

#undef MS
#define MS(_v, _f) (((_v) & _f##_MASK) >> _f##_LSB)
#undef SM
#define SM(_v, _f) (((_v) << _f##_LSB) & _f##_MASK)
#undef WO
#define WO(_f)      ((_f##_OFFSET) >> 2)

#undef GET_FIELD
#define GET_FIELD(_addr, _f) MS(*((A_UINT32 *)(_addr) + WO(_f)), _f)
#undef SET_FIELD
#define SET_FIELD(_addr, _f, _val)  \
    (*((A_UINT32 *)(_addr) + WO(_f)) = \
     (*((A_UINT32 *)(_addr) + WO(_f)) & ~_f##_MASK) | SM(_val, _f))

#define WMI_GET_FIELD(_msg_buf, _msg_type, _f) \
    GET_FIELD(_msg_buf, _msg_type ## _ ## _f)

#define WMI_SET_FIELD(_msg_buf, _msg_type, _f, _val) \
    SET_FIELD(_msg_buf, _msg_type ## _ ## _f, _val)

/*
 * Control Path
 */
#if 0
typedef PREPACK struct {
    A_UINT32    commandId : 16,
                reserved  : 2, /* reserved for future WMI  */
                plt_priv  : 6, /* platform private */
/*
 * info1 - 16 bits
 * b03:b00 - id
 * b15:b04 - unused
 */
                info1 : 16;
} POSTPACK WMI_CMD_HDR;        /* used for commands and events */
#else
typedef PREPACK struct {
    A_UINT32    commandId : 24,
                reserved  : 2, /* reserved for future WMI  */
                plt_priv  : 6; /* platform private */
/*
 * info1 - 16 bits
 * b03:b00 - id
 * b15:b04 - unused
 */
} POSTPACK WMI_CMD_HDR;        /* used for commands and events */
#endif

#define WMI_CMD_HDR_COMMANDID_LSB           0
//#define WMI_CMD_HDR_COMMANDID_MASK          0x0000ffff
#define WMI_CMD_HDR_COMMANDID_MASK          0x00ffffff
#define WMI_CMD_HDR_COMMANDID_OFFSET        0x00000000
#define WMI_CMD_HDR_INFO1_LSB               16
#define WMI_CMD_HDR_INFO1_MASK              0xffff0000 
#define WMI_CMD_HDR_INFO1_OFFSET            0x00000000 

/*
 * List of Commnands
 */
typedef enum {
    WMI_CONNECT_CMDID           = 0x0001,
    WMI_SYNCHRONIZE_CMDID,  		//used in wlan_wmi.c
    WMI_TARGET_ERROR_REPORT_BITMASK_CMDID,     //used in wlan_wmi.c
    WMI_SET_RETRY_LIMITS_CMDID,				//used in ratectrl.c
    WMI_EXTENSION_CMDID,                     //used in wmi_svc.c   /* Non-wireless extensions */
    WMI_LQ_THRESHOLD_PARAMS_CMDID,		 //used in ratectrl.c
    WMI_SET_FIXRATES_CMDID,					 //used in ratectrl.c
    WMI_GET_FIXRATES_CMDID,			 //used in ratectrl.c
    WMI_TEST_CMDID,					 //used in wmi_tcmd.c

    WMI_SET_FRAMERATES_CMDID,			 //used in ratectrl.c
    /*
     * Developer commands starts at 0xF000
     */
    WMI_SET_BITRATE_CMDID = 0xF000,			 //used in ratectrl.c
    WMI_GET_BITRATE_CMDID,					 //used in ratectrl.c
    WMI_SET_TX_SELECT_RATES_CMDID,			 //used in ratectrl.c
    WMI_SET_TX_SGI_PARAM_CMDID,				 //used in ratectrl.c
    WMI_SET_RATE_POLICY_CMDID,				 //used in ratectrl.c
    WMI_AP_SET_11BG_RATESET_CMDID,     /* F027 */		 //used in ratectrl.c
    WMI_FORCE_TARGET_ASSERT_CMDID,				//used in wlan_wmi.c
} WMI_COMMAND_ID;


typedef enum {
    SUBTYPE_NONE,   //used in wlan_vdev.h
    SUBTYPE_BT,
    SUBTYPE_P2PDEV,
    SUBTYPE_P2PCLIENT,
    SUBTYPE_P2PGO,
} NETWORK_SUBTYPE;


typedef enum {
    NONE_CRYPT          = 0x01,
    WEP_CRYPT           = 0x02,
    TKIP_CRYPT          = 0x04,
    AES_CRYPT           = 0x08,
#ifdef WAPI_ENABLE
    WAPI_CRYPT          = 0x10,
#endif /*WAPI_ENABLE*/
} CRYPTO_TYPE;

#define WMI_MAX_SSID_LEN    32

/*
 * WMI_SET_PMK_CMDID
 */
#define WMI_PMK_LEN     32


/*
 * WMI_ADD_CIPHER_KEY_CMDID
 */
typedef enum {
    PAIRWISE_USAGE      = 0x00,
    GROUP_USAGE         = 0x01,
    TX_USAGE            = 0x02,     /* default Tx Key - Static WEP only */
} KEY_USAGE;

/*
 * Bit Flag
 * Bit 0 - Initialise TSC - default is Initialize
 */

#define WMI_PMKID_LEN 16

typedef enum {
    NONE_BSS_FILTER = 0x0,              /* no beacons forwarded */
    ALL_BSS_FILTER,                     /* all beacons forwarded */
    PROFILE_FILTER,                     /* only beacons matching profile */
    ALL_BUT_PROFILE_FILTER,             /* all but beacons matching profile */
    CURRENT_BSS_FILTER,                 /* only beacons matching current BSS */
    ALL_BUT_BSS_FILTER,                 /* all but beacons matching BSS */
    PROBED_SSID_FILTER,                 /* beacons matching probed ssid */
    LAST_BSS_FILTER,                    /* marker only */
} WMI_BSS_FILTER;

/*
 * WMI_SET_BEACON_INT_CMDID
 */
typedef PREPACK struct {
    A_UINT16     beaconInterval;
} POSTPACK WMI_BEACON_INT_CMD;

typedef PREPACK struct {
    A_UINT16     bmissTime;
    A_UINT16     numBeacons;
} POSTPACK WMI_BMISS_TIME_CMD;


/*
 * WMI_SYNCHRONIZE_CMDID
 */
typedef PREPACK struct {
    A_UINT8 dataSyncMap;
} POSTPACK WMI_SYNC_CMD;



typedef PREPACK struct WMI_LQ_THRESHOLD_PARAMS {
    A_UINT8     enable;
    A_UINT8     thresholdAbove1_Val;
    A_UINT8     thresholdAbove2_Val;
    A_UINT8     thresholdAbove3_Val;
    A_UINT8     thresholdAbove4_Val;
    A_UINT8     thresholdBelow1_Val;
    A_UINT8     thresholdBelow2_Val;
    A_UINT8     thresholdBelow3_Val;
    A_UINT8     thresholdBelow4_Val;
    A_UINT8     reserved[3];
} POSTPACK  WMI_LQ_THRESHOLD_PARAMS_CMD;


typedef PREPACK struct {
    A_UINT8     status;
    A_UINT8     preamblePolicy;
}POSTPACK WMI_SET_LPREAMBLE_CMD;

/*
 *  WMI_TARGET_ERROR_REPORT_BITMASK_CMDID
 *  Sets the error reporting event bitmask in target. Target clears it
 *  upon an error. Subsequent errors are counted, but not reported
 *  via event, unless the bitmask is set again.
 */
typedef PREPACK struct {
    A_UINT32    bitmask;
} POSTPACK  WMI_TARGET_ERROR_REPORT_BITMASK;


typedef enum {
    MGMT_FRAMETYPE    = 0,
    CONTROL_FRAMETYPE = 1,
    DATA_FRAMETYPE    = 2
} WMI_FRAMETYPE;

typedef PREPACK struct {
    A_UINT8 frameType;                      /* WMI_FRAMETYPE */
    A_UINT8 trafficClass;                   /* applies only to DATA_FRAMETYPE */
    A_UINT8 maxRetries;
    A_UINT8 enableNotify;
} POSTPACK WMI_SET_RETRY_LIMITS_CMD;


/*
 * List of Events (target to host)
 */
typedef enum {
    WMI_CMDERROR_EVENTID, //used in wlan_wmi_events.c
    WMI_REGDOMAIN_EVENTID, //used in umac_wmi_events.c and wmi_unified.c
    WMI_ERROR_REPORT_EVENTID,  //used in wlan_wmi_events.c
    WMI_EXTENSION_EVENTID,			//wmi_profhook.c and umac_wmi_events.c
    WMI_TEST_EVENTID,				//wmi_tcmd.c
    WMI_WLAN_VERSION_EVENTID,			//wlan_wmi_events.c and wmi_unified.c
} WMI_EVENT_ID;

typedef enum {
    WMI_11A_CAPABILITY   = 1,
    WMI_11G_CAPABILITY   = 2,
    WMI_11AG_CAPABILITY  = 3,
    WMI_11NA_CAPABILITY  = 4,
    WMI_11NG_CAPABILITY  = 5,
    WMI_11NAG_CAPABILITY = 6,
    WMI_11AC_CAPABILITY  = 7,
    // END CAPABILITY
    WMI_11N_CAPABILITY_OFFSET = (WMI_11NA_CAPABILITY - WMI_11A_CAPABILITY),
} WMI_PHY_CAPABILITY;

#define IEEE80211_NWID_LEN                  32
/*
 * Command Error Event
 */
typedef enum {
    INVALID_PARAM  = 0x01,
    ILLEGAL_STATE  = 0x02,
    INTERNAL_ERROR = 0x03,
} WMI_ERROR_CODE;

typedef PREPACK struct {
    A_UINT16    commandId;
    A_UINT8     errorCode;
} POSTPACK WMI_CMD_ERROR_EVENT;

/*
 * New Regulatory Domain Event
 */
typedef PREPACK struct {
    A_UINT32    regDomain;
} POSTPACK WMI_REG_DOMAIN_EVENT;

/*
 * Reporting statistics.
 */
typedef PREPACK struct {
    A_UINT32   tx_packets;
    A_UINT32   tx_bytes;
    A_UINT32   tx_unicast_pkts;
    A_UINT32   tx_unicast_bytes;
    A_UINT32   tx_multicast_pkts;
    A_UINT32   tx_multicast_bytes;
    A_UINT32   tx_broadcast_pkts;
    A_UINT32   tx_broadcast_bytes;
    A_UINT32   tx_rts_success_cnt;
    A_UINT32   tx_packet_per_ac[4];
    A_UINT32   tx_errors_per_ac[4];

    A_UINT32   tx_errors;
    A_UINT32   tx_failed_cnt;
    A_UINT32   tx_retry_cnt;
    A_UINT32   tx_mult_retry_cnt;
    A_UINT32   tx_rts_fail_cnt;
    A_INT32    tx_unicast_rate;
}POSTPACK tx_stats_t;

typedef PREPACK struct {
    A_UINT32   rx_packets;
    A_UINT32   rx_bytes;
    A_UINT32   rx_unicast_pkts;
    A_UINT32   rx_unicast_bytes;
    A_UINT32   rx_multicast_pkts;
    A_UINT32   rx_multicast_bytes;
    A_UINT32   rx_broadcast_pkts;
    A_UINT32   rx_broadcast_bytes;
    A_UINT32   rx_fragment_pkt;

    A_UINT32   rx_errors;
    A_UINT32   rx_crcerr;
    A_UINT32   rx_key_cache_miss;
    A_UINT32   rx_decrypt_err;
    A_UINT32   rx_duplicate_frames;
    A_INT32    rx_unicast_rate;
}POSTPACK rx_stats_t;

typedef PREPACK struct {
    A_UINT32   tkip_local_mic_failure;
    A_UINT32   tkip_counter_measures_invoked;
    A_UINT32   tkip_replays;
    A_UINT32   tkip_format_errors;
    A_UINT32   ccmp_format_errors;
    A_UINT32   ccmp_replays;
}POSTPACK tkip_ccmp_stats_t;

typedef PREPACK struct {
    tx_stats_t          tx_stats;
    rx_stats_t          rx_stats;
    tkip_ccmp_stats_t   tkipCcmpStats;
}POSTPACK wlan_net_stats_t;

/*
 *  WMI_ERROR_REPORT_EVENTID
 */
typedef enum{
    WMI_TARGET_PM_ERR_FAIL      = 0x00000001,
    WMI_TARGET_KEY_NOT_FOUND    = 0x00000002,
    WMI_TARGET_DECRYPTION_ERR   = 0x00000004,
    WMI_TARGET_BMISS            = 0x00000008,
    WMI_PSDISABLE_NODE_JOIN     = 0x00000010,
    WMI_TARGET_COM_ERR          = 0x00000020,
    WMI_TARGET_FATAL_ERR        = 0x00000040,
    WMI_TARGET_BCN_FOUND        = 0x00000080
} WMI_TARGET_ERROR_VAL;

typedef PREPACK struct {
    A_UINT32 errorVal;
}POSTPACK  WMI_TARGET_ERROR_REPORT_EVENT;

typedef enum{
    WMI_LQ_THRESHOLD1_ABOVE = 1,
    WMI_LQ_THRESHOLD1_BELOW,
    WMI_LQ_THRESHOLD2_ABOVE,
    WMI_LQ_THRESHOLD2_BELOW,
    WMI_LQ_THRESHOLD3_ABOVE,
    WMI_LQ_THRESHOLD3_BELOW,
    WMI_LQ_THRESHOLD4_ABOVE,
    WMI_LQ_THRESHOLD4_BELOW
} WMI_LQ_THRESHOLD_VAL;

typedef PREPACK struct {
    A_INT8      rateIndex;          /* see WMI_BIT_RATE */
    A_INT8      mgmtRateIndex;
    A_INT8      ctlRateIndex;
} POSTPACK WMI_BIT_RATE_CMD;

typedef PREPACK struct {
    A_UINT32      fixRateMask[WMI_MAX_RATE_MASK];          /* see WMI_BIT_RATE */
} POSTPACK WMI_FIX_RATES_CMD, WMI_FIX_RATES_REPLY;

typedef PREPACK struct {
    A_UINT8      bEnableMask;
    A_UINT8      frameType;              /* type and subtype */
    A_UINT8      reserved[2];            /* for alignment    */
    A_UINT32     frameRateMask[WMI_MAX_RATE_MASK];          /* see WMI_BIT_RATE */
} POSTPACK WMI_FRAME_RATES_CMD, WMI_FRAME_RATES_REPLY;

typedef PREPACK struct {
    A_UINT8 pmkid[WMI_PMKID_LEN];
} POSTPACK WMI_PMKID;

/*
 * WMI_SET_PMKID_LIST_CMD
 */
#define WMI_MAX_PMKID_CACHE   8

typedef PREPACK struct {
    A_UINT32    numPMKID;
    WMI_PMKID   pmkidList[WMI_MAX_PMKID_CACHE];
} POSTPACK WMI_SET_PMKID_LIST_CMD;


typedef PREPACK struct {
    A_UINT32 version;
} POSTPACK WMI_WLAN_VERSION_EVENT;


/*
 * ------- AP Mode definitions --------------
 */

/*
 * !!! Warning !!!
 * -Changing the following values needs compilation of both driver and firmware
 */
#ifdef AR6002_REV2
#define AP_MAX_NUM_STA          4
#else
#define AP_MAX_NUM_STA          50 
#endif

/*Maximum no. of virtual interface supported*/
#define NUM_DEV     4

typedef PREPACK struct {
    A_UINT32 rateMasks[WMI_MODE_MAX*WMI_MAX_RATE_MASK];
} POSTPACK WMI_SET_TX_SELECT_RATES_CMD;

typedef PREPACK struct {
    A_UINT32    sgiMask[WMI_MAX_RATE_MASK];
    A_UINT8     sgiPERThreshold;
} POSTPACK WMI_SET_TX_SGI_PARAM_CMD;

typedef PREPACK struct {
    A_UINT32 rateField[WMI_MAX_RATE_MASK]; /* 1 bit per rate corresponding to index */
#define WMI_RATE_POLICY_ID_MAX 5
    A_UINT8 id; /* valid values == 1->WMI_RATE_POLICY_ID_MAX */
    A_UINT8 shortTrys;
    A_UINT8 longTrys;
    A_UINT8 reserved; /* padding */
} POSTPACK WMI_SET_RATE_POLICY_CMD;

#define AP_11BG_RATESET1        1
#define AP_11BG_RATESET2        2
#define DEF_AP_11BG_RATESET     AP_11BG_RATESET1
typedef PREPACK struct {
    A_UINT8 rateset;
} POSTPACK WMI_AP_SET_11BG_RATESET_CMD;
/*
 * End of AP mode definitions
 */

struct _wmm_params {
    A_UINT8     acm;           /* ACM parameter */
    A_UINT8     aifsn;         /* AIFSN parameters */
    A_UINT8     logcwmin;      /* cwmin in exponential form */
    A_UINT8     logcwmax;      /* cwmax in exponential form */
    A_UINT16    txopLimit;     /* txopLimit */
};

/*
 * These constants are used with A_WLAN_BAND_SET.
 */
#define A_BAND_24GHZ           0
#define A_BAND_5GHZ            1
#define A_NUM_BANDS            2

#ifndef ATH_TARGET
#include "athendpack.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /* _WMI_H_ */
