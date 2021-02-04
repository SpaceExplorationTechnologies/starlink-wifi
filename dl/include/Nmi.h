/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/*
 *
 * Copyright (c) 2004-2010 Atheros Communications Inc.
 * All rights reserved.
 *
 * $ATH_LICENSE_HOSTSDK0_C$
 *
 */


#ifndef _NMI_H_
#define _NMI_H_

#ifdef __cplusplus
extern "C" {
#endif

#define HTC_PROTOCOL_VERSION    0x0002
#define HTC_PROTOCOL_REVISION   0x0000

#define NMI_PROTOCOL_VERSION    0x0002
#define NMI_PROTOCOL_REVISION   0x0000

#define A_MAX_ENUM_DATA_32     0x7FFFFFFF

#define ATH_MAC_LEN             6               /* length of mac in bytes */
#define NMI_CMD_MAX_LEN         100
#define NMI_CONTROL_MSG_MAX_LEN     256
#define NMI_OPT_CONTROL_MSG_MAX_LEN 1536
#define IS_ETHERTYPE(_typeOrLen)        ((_typeOrLen) >= 0x0600)
#define RFC1042OUI      {0x00, 0x00, 0x00}

#define IP_ETHERTYPE 0x0800

#define NMI_IMPLICIT_PSTREAM 0xFF
#define NMI_MAX_THINSTREAM 15

/*
 * Macros for operating on NMI_DATA_HDR (info) field 
 */

#define NMI_DATA_HDR_MSG_TYPE_MASK  0x03
#define NMI_DATA_HDR_MSG_TYPE_SHIFT 0
#define NMI_DATA_HDR_UP_MASK        0x07
#define NMI_DATA_HDR_UP_SHIFT       2	
/* In AP mode, the same bit (b5) is used to indicate Power save state in
 * the Rx dir and More data bit state in the tx direction.
 */
#if 0
#define NMI_DATA_HDR_PS_MASK        0x1
#define NMI_DATA_HDR_PS_SHIFT       5
#endif

#define NMI_DATA_HDR_CABQFLAG_MASK      0x1
#define NMI_DATA_HDR_CABQFLAG_SHIFT     5

#define NMI_DATA_HDR_SET_CABQFLAG_BIT(h) ((h)->info |= (NMI_DATA_HDR_CABQFLAG_MASK << NMI_DATA_HDR_CABQFLAG_SHIFT))

/*bit 6 is indicate if send Self-CTS or not*/

#define NMI_DATA_HDR_SELF_CTS_MASK 0x01
#define NMI_DATA_HDR_SELF_CTS_SHIFT 6

#define NMI_DATA_HDR_SET_SELF_CTS_BIT(h) ((h)->info |= (NMI_DATA_HDR_SELF_CTS_MASK << NMI_DATA_HDR_SELF_CTS_SHIFT))

/*bit6 also used as tell host whether to forward BC or not */
#define NMI_DATA_HDR_AP_DIS_FWD_BC_MASK 0x01
#define NMI_DATA_HDR_AP_DIS_FWD_BC_SHIFT 6

#define NMI_DATA_DHR_AP_DIS_FWD_BC (NMI_DATA_HDR_AP_DIS_FWD_BC_MASK<<NMI_DATA_HDR_AP_DIS_FWD_BC_SHIFT)

/* bit 7 indicate if nmi event or not 
  * which is used to report beacon/probe req/resp
  * with size larger than 512
  */
#define NMI_DATA_HDR_NMI_EVENT_MASK 0x01
#define NMI_DATA_HDR_NMI_EVENT_SHIFT 7
#define NMI_DATA_DHR_NMI_EVENT (NMI_DATA_HDR_NMI_EVENT_MASK<<NMI_DATA_HDR_NMI_EVENT_SHIFT)
#define NMI_DATA_HDR_NMI_EVENT(h) (((h)->info & (NMI_DATA_DHR_NMI_EVENT)) == (NMI_DATA_DHR_NMI_EVENT))

#define NMI_DATA_HDR_IS_MSG_TYPE(h, t)  (((h)->info & (NMI_DATA_HDR_MSG_TYPE_MASK)) == (t))
#define NMI_DATA_HDR_SET_MSG_TYPE(h, t) (h)->info = (((h)->info & ~(NMI_DATA_HDR_MSG_TYPE_MASK << NMI_DATA_HDR_MSG_TYPE_SHIFT)) | (t << NMI_DATA_HDR_MSG_TYPE_SHIFT))
#define NMI_DATA_HDR_GET_UP(h)    (((h)->info >> NMI_DATA_HDR_UP_SHIFT) & NMI_DATA_HDR_UP_MASK)
#define NMI_DATA_HDR_SET_UP(h, p) (h)->info = (((h)->info & ~(NMI_DATA_HDR_UP_MASK << NMI_DATA_HDR_UP_SHIFT)) | (p << NMI_DATA_HDR_UP_SHIFT))

#if 0
/* Macros for operating on NMI_DATA_HDR (info2) field */
#define NMI_DATA_HDR_SEQNO_MASK     0xFFF
#define NMI_DATA_HDR_SEQNO_SHIFT    0

#define NMI_DATA_HDR_AMSDU_MASK     0x1
#define NMI_DATA_HDR_AMSDU_SHIFT    12

#define GET_SEQ_NO(_v)                  ((_v) & NMI_DATA_HDR_SEQNO_MASK)
#define GET_ISMSDU(_v)                  ((_v) & NMI_DATA_HDR_AMSDU_MASK)

#define NMI_DATA_HDR_GET_SEQNO(h)        GET_SEQ_NO((h)->info2 >> NMI_DATA_HDR_SEQNO_SHIFT)
#define NMI_DATA_HDR_SET_SEQNO(h, _v)   ((h)->info2 = ((h)->info2 & ~(NMI_DATA_HDR_SEQNO_MASK << NMI_DATA_HDR_SEQNO_SHIFT)) | (GET_SEQ_NO(_v) << NMI_DATA_HDR_SEQNO_SHIFT))

#define NMI_DATA_HDR_IS_AMSDU(h)        GET_ISMSDU((h)->info2 >> NMI_DATA_HDR_AMSDU_SHIFT)
#define NMI_DATA_HDR_SET_AMSDU(h, _v)   ((h)->info2 = ((h)->info2 & ~(NMI_DATA_HDR_AMSDU_MASK << NMI_DATA_HDR_AMSDU_SHIFT)) | (GET_ISMSDU(_v) << NMI_DATA_HDR_AMSDU_SHIFT))
#endif

#define NMI_CMD_HDR_SIZE         (sizeof(NMI_CMD_HDR))
#define NMI_DATA_HDR_SIZE       (sizeof(NMI_DATA_HDR))

typedef struct {
    A_INT8      rssi;            
    A_UINT8     info;            /* NMI_MSG_TYPE in lower 2 bits - b1b0 */
                                 /* UP in next 3 bits - b4b3b2 */
} __ATTRIB_PACK NMI_DATA_HDR;

/*
 * Control Path
 */
typedef struct {
    A_UINT16    commandId;
} __ATTRIB_PACK NMI_CMD_HDR;        /* used for commands and events */

/*
 * List of Commnands
 */
typedef enum {
    NMI_SET_IPDATA_RCV_FILTER_CMDID = 0xE000,
    NMI_GET_ACS_CONN_STATE_CMDID,
    NMI_ACS_SET_WORK_MODE_CMDID,
    NMI_POWER_ON_MODEM_CMDID,
    NMI_POWER_DOWN_MODEM_CMDID,
    NMI_CONNECT_CMDID,
    NMI_DISCONNECT_CMDID,
    NMI_ENABLE_STATUS_REPORT_CMD,
    NMI_DISABLE_STATUS_REPORT_CMD,    
    NMI_HOST_EXIT_NOTIFY_CMDID,
    NMI_HB_CHALLENGE_RESP_CMDID,
    NMI_GET_SMS_CMDID,
    NMI_DEL_SMS_CMDID,
} NMI_COMMAND_ID;

#define ADD_IP_FILTER   1
#define DEL_IP_FILTER   2
#define IP_FILTER_MIN_INDEX 0
#define IP_FILTER_MAX_INDEX 5

typedef struct {
    A_UINT8     action;/* add or del */
    A_UINT8     index;/* min=0, max=5 */
    A_UINT8     ipaddr[4];
} __ATTRIB_PACK NMI_SET_IPDATA_RCV_FILTER_CMD;

#define ACS_AUTO_MODE    0
#define ACS_MANUAL_MODE  1

typedef struct {
    A_UINT8     mode;
} __ATTRIB_PACK NMI_SET_ACS_WORK_MODE_CMD;

/*
 * NMI_HB_CHALLENGE_RESP_CMDID
 * Heartbeat Challenge Response command
 */
typedef struct {
    A_UINT32              cookie;
    A_UINT32              source;
} __ATTRIB_PACK NMI_HB_CHALLENGE_RESP_CMD;

typedef struct {
    A_UINT32 frequency;
    A_UINT8  hostThreshold;
    A_UINT8  targetThreshold;
} __ATTRIB_PACK NMI_SET_HB_CHALLENGE_RESP_PARAMS_CMD;

/*
 * List of Events (target to host)
 */
typedef enum {
    NMI_ACS_CONN_STATE_EVENTID      = 0xD000,
    NMI_UPDATE_WWAN_STATE_EVENTID,    
    NMI_ERROR_REPORT_EVENTID,
    NMI_NEWSMS_INDICATION_EVENTID,
    NMI_SMSCONTENT_EVENTID,
    NMI_DEL_SMS_COMPLETE_EVENTID,
} NMI_EVENT_ID;


typedef struct {
    A_UINT8  ip_addr[4];       /* Local IP address of WWAN-side interface */
    A_UINT8  primary_dns[4];      /* primary DNS */ 
    A_UINT8  secondary_dns[4];    /* secondary DNS */
} __ATTRIB_PACK NMI_ACS_CONN_STATE_EVENT;

#define WWAN_POWER_STATE_OFF    0
#define WWAN_POWER_STATE_ON     1
#define WWAN_POWER_STATE_FLT    2

#define WWAN_NETWORK_NONE       0  /* no network available */
#define WWAN_NETWORK_AVAIL      1  /* available but not connected */
#define WWAN_NETWORK_CONNECTED  2  /* available and connected */

#define WWAN_NETWORK_EVENTID_NONE         0  /* no network available */
#define WWAN_NETWORK_EVENTID_AVAIL        1  /* available but not connected */
#define WWAN_NETWORK_EVENTID_CONNECTED    2  /* available and connected */
#define WWAN_NETWORK_EVENTID_UNAVAIL      3  /* unavailable */
#define WWAN_NETWORK_EVENTID_DISCONNECTED 4  /* available and disconnected */

typedef struct {
    A_UINT8 modem_update_evt;
    A_UINT8 wwan_update_evt;
} __ATTRIB_PACK NMI_ACS_WWAN_STATE_EVENT;

/*
 *  NMI_ERROR_REPORT_EVENTID
 */
typedef enum{
    NMI_TARGET_PM_ERR_FAIL      = 0x00000001,
    NMI_TARGET_KEY_NOT_FOUND    = 0x00000002,
    NMI_TARGET_DECRYPTION_ERR   = 0x00000004,
    NMI_TARGET_BMISS            = 0x00000008,
    NMI_PSDISABLE_NODE_JOIN     = 0x00000010,
    NMI_TARGET_COM_ERR          = 0x00000020,
    NMI_TARGET_FATAL_ERR        = 0x00000040
}__ATTRIB_PACK NMI_TARGET_ERROR_VAL;

typedef struct {
    A_UINT32 errorVal;
}__ATTRIB_PACK  NMI_TARGET_ERROR_REPORT_EVENT;

typedef struct {
    A_UINT16 index; 
}__ATTRIB_PACK  NMI_GET_SMS_CMD, NMI_DEL_SMS_CMD;

#define MAX_SMS_COUNT   30
typedef struct {
    A_UINT16 num;
    A_UINT16 index[MAX_SMS_COUNT];
}__ATTRIB_PACK NMI_SMS_INDIC_EVENT;

#define SMS_CONTENT_BUF_SIZE 512
typedef struct {
    A_UINT16 length;
    A_UINT8  smscontent[SMS_CONTENT_BUF_SIZE];
}__ATTRIB_PACK NMI_SMS_CONTENT_EVENT;
#ifdef __cplusplus
}
#endif

#endif /* _NMI_H_ */
