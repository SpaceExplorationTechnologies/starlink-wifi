/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/*
 * Copyright (c) 2006-2007 Atheros Communications Inc.
 * All rights reserved.
 * $ATH_LICENSE_TARGET_C$
 *
 * This file contains the api for the Wireless Module Interface (WMI) on the
 * target for TCMD application.
 */

#ifndef _WMI_TCMD_API_H_
#define _WMI_TCMD_API_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "athdefs.h"
#include <utf_dev.h>
//#if defined(AR6002_REV4) || defined(AR6002_REV6)
#include <testcmd.h>
//#endif

/*
 * Macros
 */

typedef enum {
    DEFAULT_SYNC    = 0x0,
    DRAIN_DATA_SYNC,
} WMI_SYNC_STATE;

struct wmi_event_hdr {
    struct HTC_bufinfo_s    we_bufinfo;
    A_UINT16                we_flag;
    A_UINT16                reserved;
};

struct wmi_info {
    wlan_tcmd_dev_t        *wi_devht;
    A_UINT8                 wi_dtm_inUse;   /* bitmap of data mbox in use */
    A_UINT8                 wi_dtm_drained;  /* bitmap of data mbox drained */
    A_UINT8                 wi_sync_state;
    A_BOOL                  wi_ready;
};

/*
 * Prototypes
 */

void wmi_tcmd_event_send(struct wmi_info *wi, struct wmi_event_hdr *evh);
struct wmi_event_hdr * wmi_alloc_htcbuf(struct wmi_info *wi,
                                               A_INT32 size);
void wmi_free_evbuf(struct wmi_info *wi, struct wmi_event_hdr *evh);
void wmi_control_refill(struct wmi_info *wi, struct HTC_bufinfo_s *bufinfo,
                        HTC_ENDPOINT_ID eid);
void wmi_free_evbuf(struct wmi_info *wi, struct wmi_event_hdr *evh);
struct wmi_event_hdr * wmi_alloc_htcbuf(struct wmi_info *wi, A_INT32 size);
struct wmi_event_hdr *wmi_alloc_htcbuf_xtnd(struct wmi_info *wi,
                                                   A_INT32 size);
#define WMI_CONTROL_BUFSZ       280            

/*
 * TCMD has has WMI cmd and event, so theoretically only 1 cmd buffer and 
 * 1 event should be sufficient. However, since tcmd is registering 4 data 
 * services, we need to provide atleast 1 buffer per service(This will keep
 * the host un-modified for wlan and tcmd).
 */
#define WMI_TCMD_NUM_BUFFERS          10
#define WMI_TCMD_NUM_EVENT_BUFFERS    10

#define WMIEV_FREE_FLG          0x0001
#define WMIEV_WMIBUF_FLG        0x0002      /* buffer belongs to WMI */
#define WMIEV_DATABUF_FLG       0x0004      /* buffer belongs to tx/rx */

#define DBGLOG_UTF 5

    
extern struct wmi_info *wmiTcmdInit(wlan_tcmd_dev_t *dev);
extern void wmi_tcmd_ready_event(struct wmi_info *wi, A_UINT8 *macaddr);
extern void wmi_tcmd_cont_rx_reply_event(struct wmi_info *wi, A_UINT16 len, A_UINT8 *contRx);
extern void wmi_tc_cmds_reply_event(struct wmi_info *wi, A_UINT16 len, A_UINT8 version, A_INT8* buf);
/*
 * HTC callbacks
 */
/*
 * wmi_tcmd_htc_rx is the HTC_recvdone_fn_t handler
 */
extern void wmi_tcmd_htc_rx(HTC_ENDPOINT_ID eid, struct HTC_bufinfo_s *bufinfo);

/*
 * wmi_tcmd_htc_tx_complete is the HTC_senddone_fn_t callback
 */
extern  void wmi_tcmd_htc_tx_complete(HTC_ENDPOINT_ID eid, struct HTC_bufinfo_s *bufinfo);


#ifdef __cplusplus
}
#endif

#endif
