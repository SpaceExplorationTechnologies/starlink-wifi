//
// Copyright (c) 2012  Qualcomm Atheros Inc.
// All rights reserved.
// $ATH_LICENSE_TARGET_C$
//
// This module implements the Wake on Wireless feature.
//
//

#ifndef _WLAN_WOW_H
#define _WLAN_WOW_H

#define WOW_DEFAULT_BITMAP_PATTERN_SIZE      64
#define WOW_DEFAULT_BITMASK_SIZE             64
#define WOW_MAX_BITMAP_FILTERS               16
#define WOW_DEFAULT_MAGIG_PATTERN_MATCH_CNT  16
#define WOW_DEFAULT_EVT_BUF_SIZE             128  /* Maximum 128 bytes of the data is copied starting from header
                                                   * incase if the match is found */

typedef enum pattern_type_e {
    WOW_PATTERN_MIN = 0,
    WOW_BITMAP_PATTERN = WOW_PATTERN_MIN,
    WOW_IPV4_SYNC_PATTERN,
    WOW_IPV6_SYNC_PATTERN,
    WOW_WILD_CARD_PATTERN,
    WOW_TIMER_PATTERN,
    WOW_PATTERN_MAX
}WOW_PATTERN_TYPE;

typedef enum event_type_e {
    WOW_BMISS_EVENT = 0,
    WOW_BETTER_AP_EVENT,
    WOW_DEAUTH_RECVD_EVENT,
    WOW_MAGIC_PKT_RECVD_EVENT,
    WOW_GTK_ERR_EVENT,
    WOW_GTK_UPDATE_EVENT,
    WOW_FOURWAY_HSHAKE_EVENT,
    WOW_EAPOL_RECVD_EVENT,
    WOW_PATTERN_MATCH_EVENT,
}WOW_WAKE_EVENT_TYPE;

typedef enum wake_reason_e {
    WOW_REASON_UNSPECIFIED =-1,
    WOW_REASON_NLOD = 0,
    WOW_REASON_AP_ASSOC_LOST,
    WOW_REASON_DEAUTH_RECVD,
    WOW_REASON_LOW_RSSI,
    WOW_REASON_DISASSOC_RECVD,
    WOW_REASON_GTK_HS_ERR,
    WOW_REASON_EAP_REQ,
    WOW_REASON_FOURWAY_HS_RECV,
    WOW_REASON_TIMER_INTR_RECV,
    WOW_REASON_PATTERN_MATCH_FOUND,
    WOW_REASON_RECV_MAGIC_PATTERN,
}WOW_WAKE_REASON_TYPE;

typedef struct bitmap_pattern_s {
    A_UINT8      patternbuf[WOW_DEFAULT_BITMAP_PATTERN_SIZE];
    A_UINT8      bitmaskbuf[WOW_DEFAULT_BITMASK_SIZE];
    A_UINT8      pattern_offset;
    A_UINT32     pattern_len;
    A_UINT32     bitmask_len;
    A_UINT32     pattern_id;  /* must be less than max_bitmap_filters */
}WOW_BITMAP_PATTERN_T;

typedef struct ipv4_sync_s {
    A_UINT8      ipv4_src_addr[4];
    A_UINT8      ipv4_dst_addr[4];
    A_UINT32     tcp_src_prt;
    A_UINT32     tcp_dst_prt;
}WOW_IPV4_SYNC_PATTERN_T;

typedef struct ipv6_sync_s {
    A_UINT8      ipv6_src_addr[16];
    A_UINT8      ipv6_dst_addr[16];
    A_UINT32     tcp_src_prt;
    A_UINT32     tcp_dst_prt;
}WOW_IPV6_SYNC_PATTERN_T;

typedef struct  event_info_s {
    A_UINT32    wake_reason;
    A_UINT32    data_len;
}EVENT_INFO;


#endif /* _WLAN_WOW_H */
