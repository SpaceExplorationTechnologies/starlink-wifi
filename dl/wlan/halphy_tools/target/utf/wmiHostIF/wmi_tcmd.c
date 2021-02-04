/*
 * Copyright (c) 2012-2018 Qualcomm Technologies, Inc. All Rights Reserved.
 * 2012-2016 Qualcomm Atheros, Inc.
 * Qualcomm Technologies Confidential and Proprietary.
 */
/*
 * Copyright (c) 2004-2007 Atheros Communications Inc.
 * All rights reserved.
 * $ATH_LICENSE_TARGET_C$
 *
 * This module implements the hardware independent layer of the
 * Wireless Module Interface (WMI) protocol specific to TCMD application.
 *
 */

#include <athdefs.h>
#include <osapi.h>
#include <htc_api.h>
#include <wmi.h>
#include <wmi_tcmd.h>
#include <tcmd_api.h>
#include <testcmd.h>
#include <mbox_map.h>
#include <sw_version.h>
#include "utf_dev.h"
#include "hif_api.h"
#include "htt_tgt_rx_api.h"
#include "wmi_unified.h"
#include <whal_api.h>
#include <utf_cal.h>
#include <wlan_defs.h>

#include "wreg_api.h"	
#include "ar6000_eeprom.h"
#if (defined(AR900B) || defined(QCA9984)) || defined(IPQ4019) || defined(QCA9888)
#include "qcache_api.h"
#include "codeswap_api.h"
#endif

#define HT_CAP_WITH_STBC_1SS    \
    (((WMI_HT_CAP_DEFAULT_ALL) & (~(WMI_HT_CAP_RX_STBC))) | \
            (WMI_HT_CAP_RX_STBC_1SS))
#define HT_CAP_WITH_STBC_2SS    \
    (((WMI_HT_CAP_DEFAULT_ALL) & (~(WMI_HT_CAP_RX_STBC))) | \
            (WMI_HT_CAP_RX_STBC_2SS))
#define HT_CAP_WITH_STBC_3SS    WMI_HT_CAP_DEFAULT_ALL

#define VHT_CAP_WITH_STBC_1SS   \
    (((WMI_VHT_CAP_DEFAULT_ALL) & (~(WMI_VHT_CAP_RX_STBC_MASK))) | \
            (WMI_VHT_CAP_RX_STBC_1SS))
#define VHT_CAP_WITH_STBC_2SS   \
    (((WMI_VHT_CAP_DEFAULT_ALL) & (~(WMI_VHT_CAP_RX_STBC_MASK))) | \
            (WMI_VHT_CAP_RX_STBC_2SS))
#define VHT_CAP_WITH_STBC_3SS   \
    (((WMI_VHT_CAP_DEFAULT_ALL) & (~(WMI_VHT_CAP_RX_STBC_MASK))) | \
            (WMI_VHT_CAP_RX_STBC_3SS))

#define VHT_CAP_WITH_STBC_1SS_VHT80 ((VHT_CAP_WITH_STBC_1SS) & (~WMI_VHT_CAP_SGI_160MHZ))
#define VHT_CAP_WITH_STBC_2SS_VHT80 ((VHT_CAP_WITH_STBC_2SS) & (~WMI_VHT_CAP_SGI_160MHZ))
#define VHT_CAP_WITH_STBC_3SS_VHT80 ((VHT_CAP_WITH_STBC_3SS) & (~WMI_VHT_CAP_SGI_160MHZ))

#if defined(CONFIG_160MHZ_SUPPORT)
#define VHT_CAP_WITH_STBC_1SS_VHT160 VHT_CAP_WITH_STBC_1SS 
#define VHT_CAP_WITH_STBC_2SS_VHT160 VHT_CAP_WITH_STBC_2SS 
#define VHT_CAP_WITH_STBC_3SS_VHT160 VHT_CAP_WITH_STBC_3SS
#endif

#if defined(DBGLOG_FTM_SUPPORT)
#define EVT_PKT_IN_USE        (1 << 0)
#define EVT_PKT_IS_FREE(e)    !((e)->Flags & EVT_PKT_IN_USE)
#define EVT_MARK_FREE(e)      (e)->Flags &= ~EVT_PKT_IN_USE;
#define EVT_MARK_INUSE(e)     (e)->Flags |= EVT_PKT_IN_USE

WLAN_WMI_APIS _wlan_wmi_api;
A_UINT8 * dbgBufSpace;
WMI_EVT_PACKET *pEvtPacket = NULL;
A_UINT8 directEvts = DBGLOG_NUM_LOG_BUFFERS + 8; /* Number of direct events */
#endif

#if defined(CONFIG_160MHZ_SUPPORT)
static __attribute__((always_inline)) A_UINT32 wal_set_vht160_cap_info (void)
{
    A_UINT32 vht_cap_info = 0;
    HAL_REG_CAPABILITIES hal_reg_cap_info = {0};
    whalGetRegCapabilities(&hal_reg_cap_info);

    if ((hal_reg_cap_info.wireless_modes & REGDMN_MODE_11AC_VHT160) &&
        (hal_reg_cap_info.wireless_modes & REGDMN_MODE_11AC_VHT80_80)) {
        vht_cap_info |= (IEEE80211_VHTCAP_SUP_CHAN_WIDTH_80_160 | IEEE80211_VHTCAP_SHORTGI_160);
    } else if ((hal_reg_cap_info.wireless_modes & REGDMN_MODE_11AC_VHT160) &&
               (~(hal_reg_cap_info.wireless_modes & REGDMN_MODE_11AC_VHT80_80))) {
        vht_cap_info |= (IEEE80211_VHTCAP_SUP_CHAN_WIDTH_160 | IEEE80211_VHTCAP_SHORTGI_160);
    }

   return vht_cap_info;
}
#endif



// "athtestcmd" TCMD tool WAR macro for QCA9888-hw-v1
// To disable this WAR, please commet out this macro
//comment the WAR for QCA9888-hw-v2
//#if defined(QCA9888)
//#define QCA9888_TCMD_WAR 1
//#endif

//#define A_PRINTF_ONCE A_CMN(printf._printf)
#if WMI_CONTROL_BUFSZ > HTC_BUFSZ_MAX_SEND
#error "wmi htc buffer size too large"
#endif

#if defined(QCA9888_TCMD_WAR)
extern int cmnos_printf(const char * format, ...);
#ifndef SWAP32
#define SWAP32(_x) ((A_UINT32)(                       \
                                (((const A_UINT8 *)(&_x))[3]) |        \
                                (((const A_UINT8 *)(&_x))[2]<< 8) |    \
                                (((const A_UINT8 *)(&_x))[1]<<16) |    \
                                (((const A_UINT8 *)(&_x))[0]<<24)))
#endif
#endif

#ifdef WMI_DEBUG
static A_INT32 wmi_debug = 0;
#define WMI_PRINTF(args...)        if (wmi_debug) A_PRINTF(args);
#else
#define WMI_PRINTF(args...)
#endif
//#define A_PRINTF_ONCE A_CMN(printf._printf)
#if defined(AR6002_REV4) || defined(AR6002_REV6)
#define WMI_TCMD_CTRL_MAX_HTC_MSG_SIZE 1536
#else
#define WMI_TCMD_CTRL_MAX_HTC_MSG_SIZE 512
#endif

#define MAX_UTF_EVENT_LENGTH 2048
#define MAX_WMI_UTF_LEN      252
#define MAX_PAYLOAD_LEN      1536

typedef struct {
    A_UINT32 len;
    A_UINT32 msgref;
    A_UINT32 segmentInfo;
    A_UINT32 pad;
} SEG_HDR_INFO_STRUCT;

const A_UINT8 up_to_ac[]= {
                [1] WMM_AC_BK,
                [2] WMM_AC_BK,
                [0] WMM_AC_BE,
                [3] WMM_AC_BE,
                [4] WMM_AC_VI,
                [5] WMM_AC_VI,
                [6] WMM_AC_VO,
                [7] WMM_AC_VO,
                };

HTC_ENDPOINT_ID      g_ac_to_htc_ep[WMM_AC_MAX];
#if 0
const A_UINT8  ac_to_up[] = {
                    [WMM_AC_BE] 0,
                    [WMM_AC_BK] 1,
                    [WMM_AC_VI] 5,
                    [WMM_AC_VO] 6,
                    };

/* global mapping of legacy mailboxes to endpoints */
int                  g_htc_ep_to_ac[ENDPOINT_MAX];
#endif

A_UINT8 host_app_space[A_CACHE_LINE_SIZE + sizeof(struct host_app_area_s) + A_CACHE_LINE_SIZE];
#define HOSTAPPSPACE_PTR ((struct host_app_area_s *) (A_ROUND_UP_PWR2(((A_UINT32)host_app_space), A_CACHE_LINE_SIZE)))

/*
 * Definitions
 */
static HTC_ENDPOINT_ID wmiTcmdControlEp;

A_UINT8 dataPayload[MAX_UTF_EVENT_LENGTH]; //MAX_PAYLOAD_LEN(256)*8 (2k buffer max we receive 8 segments.. 256 bytes each)

/* buffer used for aligning control messages
 * only messages <= 256 bytes can be guaranteed to be
 * aligned for parsing by the command handlers */
typedef struct _WMI_ALIGNMENT_BUFFER {
        A_UINT8 _pad[sizeof(WMI_CMD_HDR)];  /* has to be padded so that when the ptr is advanced                                            it will re-align again */
        A_UINT8 payload[WMI_CONTROL_BUFSZ]; /* start of payload */
}__ATTRIB_PACK __ATTRIB_ALIGN(4) WMI_ALIGNMENT_BUFFER;

static struct wmi_info wmiInfo;
A_UINT32 swapEnable=0;

static struct wmi_event_hdr wmi_tcmd_cmd_buffers[WMI_TCMD_NUM_BUFFERS];
static struct wmi_event_hdr wmi_tcmd_ev_buffers[WMI_TCMD_NUM_EVENT_BUFFERS];

/*
 * Calibration caching data context referenced from utf_cal.c
 */
utf_cal_ctxt *pCalibrationData = NULL;

static HTC_SERVICE WMITcmdControlService;
#if !defined(AR6320)
#define TCMD_DATA_SERVICES 4
#else
#define TCMD_DATA_SERVICES 5
#endif //AR6320
static HTC_SERVICE TcmdDataServices[TCMD_DATA_SERVICES];
static WMI_ALIGNMENT_BUFFER wmi_alignment_buffer;

void wmi_utf_unified_reply(struct wmi_info *wi, A_UINT16 len, A_UINT8* buf);
void wlan_utf_cal_init (A_UINT32 num_chunks, wlan_host_memory_chunk *p_chunks);
void wmi_tcmd_dispatch_wlan_init(A_UINT32 cmd, A_UINT8 * pCmdBuffer);
void wlan_utf_cal_register(wlan_host_mem_req * host_mem_req_array,A_UINT32 *p_host_mem_req_array_index);

/*
 * Function defintions.
 */
LOCAL A_UINT8 wmi_tcmd_ctrl_svc_connect(HTC_SERVICE  *pService,
                                        HTC_ENDPOINT_ID eid,
                                        A_UINT8 *pDataIn,
                                        int LengthIn,
                                        A_UINT8 *pDataOut,
                                        int *pLengthOut)
{
    switch (pService->ServiceID) {
        case WMI_CONTROL_SVC:
            wmiTcmdControlEp = eid;
            break;
        case WMI_DATA_BE_SVC:
            break;
        case WMI_DATA_BK_SVC:
            break;
        case WMI_DATA_VI_SVC:
            break;
        case WMI_DATA_VO_SVC:
            break;
        default:
            A_ASSERT(FALSE);
    }

   return HTC_SERVICE_SUCCESS;
}

#if defined(DBGLOG_FTM_SUPPORT)
void utf_wmi_dbglogbuf_send_complete(void *pContext)
{
    A_UINT8 *buffer;
    A_STATUS status;

    buffer = (A_UINT8 *)pContext;
    A_ASSERT(buffer != NULL);

    /* undo buffer adjustements */
    buffer += sizeof(A_UINT32);
    A_ASSERT((buffer == WLAN_WMI_DBGBUFSPACE_PTR_0()) ||
             (buffer == WLAN_WMI_DBGBUFSPACE_PTR_1()));
    status = DBGLOG_QUEUE_BUFFER(buffer,
                                 DBGLOG_TARGET_LOG_BUFFER_SIZE);
    A_ASSERT(status == A_OK);
}

static void utf_create_event_buffer(void)
{
    pEvtPacket = (WMI_EVT_PACKET *)A_ALLOCRAM_BY_ARENA(ALLOCRAM_SRAM_ARENA, (sizeof(WMI_EVT_PACKET) * directEvts));
}

static WMI_EVT_PACKET * UTF_AllocEvent(WMI_EVT_CLASS EventClass, int Length)
{
    WMI_EVT_PACKET *pEvt;
    A_UINT8 i;

    A_ASSERT(pEvtPacket != NULL);

    pEvt = pEvtPacket;

    for (i = 0; i < directEvts; i++, pEvt++)
    {
        if (EVT_PKT_IS_FREE(pEvt))
        {
            /* mark in use */
            EVT_MARK_INUSE(pEvt);
            break;
        }
    }
    if (i < directEvts)
    {
        pEvt->EventClass = EventClass;
        return pEvt;
    }
    // We should not reach here
    A_ASSERT(FALSE);
    return NULL;
}

static void utf_wmi_send_event(WMI_EVT_PACKET * pEvt, A_UINT32 EventId, int Length)
{
    A_UINT8 *pBuffer;
    WMI_CMD_HDR *wmi_hdr;
    
    pBuffer = WMI_EVT_GET_DIRECT_EVT_PTR(pEvt);

    if (WMI_EVT_CLASS_DIRECT_BUFFER == pEvt->EventClass)
    {
        /* direct buffer events relies on the caller to provide headroom
         * adjust the HTC buffer so that we can fill in the WMI header */
        pEvt->HtcBuf.buffer -= sizeof(WMI_CMD_HDR);
    }

    /* NOTE: buffered events already have the WMI header adjustment */

    wmi_hdr = (WMI_CMD_HDR *)pEvt->HtcBuf.buffer;
    /* set eventID in the WMI header */
    wmi_hdr->commandId = EventId;
    /* set plt_priv in the WMI header */
    wmi_hdr->plt_priv = 0;
    wmi_hdr->reserved = 0;
    /* set length to include WMI header */
    pEvt->HtcBuf.actual_length = Length + sizeof(WMI_CMD_HDR);

    /* send it out */
    A_DATA_CACHE_FLUSH(pEvt->HtcBuf.buffer, pEvt->HtcBuf.actual_length);
    HTC_SendMsg(wmiTcmdControlEp, &pEvt->HtcBuf);
}

void utf_wmi_dbglog_event(void *cookie, A_UINT8 *buffer, A_UINT32 length, A_UINT32 dropped)
{
    WMI_EVT_PACKET *evh;
    A_STATUS status;

    evh = UTF_AllocEvent(WMI_EVT_CLASS_DIRECT_BUFFER, 0);
    if (evh == NULL)
    {
        /* Re queue the buffer back to bebug module */
        status = DBGLOG_QUEUE_BUFFER(buffer,
                                     DBGLOG_TARGET_LOG_BUFFER_SIZE);
        A_ASSERT(status == A_OK);
        return;
    }

    /* Push the number of dropped dbglog buffers */
    buffer -= sizeof(A_UINT32);
    length += sizeof(A_UINT32);
    *((A_UINT32 *)buffer) = dropped;

    WMI_EVT_ATTACH_DIRECT_BUFFER(evh,
                                 buffer,
                                 utf_wmi_dbglogbuf_send_complete, 
                                 buffer);
    utf_wmi_send_event(evh, WMI_DEBUG_MESG_EVENTID,  length);
}

static void utf_allocate_dbgbufspace(WLAN_WMI_APIS *pApis)
{
    if (HOST_INTEREST_DBGLOG_IS_ENABLED())
    {
        if (!dbgBufSpace)
        {
            dbgBufSpace = (A_UINT8 *) A_ALLOCRAM_BY_ARENA(ALLOCRAM_SRAM_ARENA, DBGLOG_NUM_LOG_BUFFERS * DBGBUF_SZ);
        }
        pApis->_DBGBUFSPACE_PTR_0 = DBGBUFSPACE_PTR(0);
        pApis->_DBGBUFSPACE_PTR_1 = DBGBUFSPACE_PTR(1);
    }
}

static void utf_init_dbglog(struct wmi_info *wi)
{
    A_INT32 i;
    A_STATUS status;
    struct dbglog_config_msg_s configmsg;
    
    utf_create_event_buffer();

    if (HOST_INTEREST_DBGLOG_IS_ENABLED())
    {
        /* Initialize the dbglog infrastructure */
        DBGLOG_INIT(utf_wmi_dbglog_event, (void *)wi);
        for (i = 0; i < DBGLOG_NUM_LOG_BUFFERS; i++)
        {
            status = DBGLOG_QUEUE_BUFFER(DBGBUFSPACE_PTR(i),
                                     DBGLOG_TARGET_LOG_BUFFER_SIZE);
            A_ASSERT(status == A_OK);
        }

        A_MEMSET(&configmsg, 0, sizeof(struct dbglog_config_msg_s));
        for (i = 0; i <= WLAN_MODULE_ID_MAX; i++)
        {
            DBGLOG_MODULE_ENABLE(configmsg.config.mod_id, i);
        }
        /* Enable logging for all the VAPS by default */
        for (i = 0; i < DBGLOG_VAPID_NUM_MAX; i++)
        {
            DBGLOG_VAP_ENABLE(configmsg.config.dbg_config, i);
        }

        /* by default log level is set to DBGLOG_UTF */
        DBGLOG_LOG_LVL_ENABLE(configmsg.config.dbg_config, DBGLOG_UTF);

        DBGLOG_REPORTING_ENABLE(configmsg.config.dbg_config);      /*Reporting enabled */
        DBGLOG_TIMESTAMP_RES_SET(configmsg.config.dbg_config, 5);  /*Timestamp resolution */
        DBGLOG_REPORT_SIZE_SET(configmsg.config.dbg_config, 0);

        for (i = 0; i < DBGLOG_MODULE_BITMAP_SIZE; i++)
        {
            configmsg.cfgvalid[i] = DBGLOG_MODULE_LOG_ENABLE_MASK;
        }

        configmsg.cfgvalid[DBGLOG_MODULE_BITMAP_SIZE] = DBGLOG_REPORTING_ENABLE_MASK |
            DBGLOG_TIMESTAMP_RESOLUTION_MASK |
            DBGLOG_VAP_LOG_ENABLE_MASK |
            DBGLOG_REPORT_SIZE_MASK |
            DBGLOG_LOG_LVL_ENABLE_MASK |
            DBGLOG_TIMER_ENABLE_MASK;
        DBGLOG_CONFIG_DEBUG_MODULE(&configmsg);
    }
}
#endif

void utf_hif_module_install() {
    switch (cmnos_boot_info->interconnect_type) {
#if defined(CONFIG_MBOX_SUPPORT)
    case A_HOST_IC_SDIO:
    case A_HOST_IC_SPI:
        HIF_MODULE_INSTALL();
        MBOXHW_MODULE_INSTALL();
        //HTC_MODULE_INSTALL();
        HTC_PIPE_MODULE_INSTALL();
#if defined(AR6320)
        pipecfg_module_install();
        pipecfg_init();
#endif
        break;
#endif
#if defined(CONFIG_USB_SUPPORT)
#if !defined(CONFIG_AR6004_FW_REARCH)
    case A_HOST_IC_USB:
    case A_HOST_IC_USB_HSIC:
        HIF_MODULE_INSTALL();
        HTC_PIPE_MODULE_INSTALL();
        pipecfg_module_install();
        pipecfg_init();
        break;
#endif /* CONFIG_AR6004_FW_REARCH */
#endif
#if defined(CONFIG_PCIE_SUPPORT)
    case A_HOST_IC_CE_PCIE:
        HIF_MODULE_INSTALL();
#if ((WIFI_IP_CODE >= WIFI_IP_VER(2,0)) || defined(IPQ4019)) && (CONFIG_QCACHE || CONFIG_CODE_SWAP)
        wal_qcache_init();
#endif
        HIF_memcpy_init();
        HTC_PIPE_MODULE_INSTALL();
        pipecfg_module_install();
        pipecfg_init();
        break;
#endif

#if defined(CONFIG_AXI_SUPPORT)
        case A_HOST_IC_CE_AXI:
            HIF_MODULE_INSTALL();
#if ((WIFI_IP_CODE >= WIFI_IP_VER(2,0)) || defined(IPQ4019)) && (CONFIG_QCACHE || CONFIG_CODE_SWAP)
            wal_qcache_init();
#endif
            HIF_memcpy_init();
            HTC_PIPE_MODULE_INSTALL();
            pipecfg_module_install();
            pipecfg_init();
            break;
#endif

    default:
        A_ASSERT(0);
        break;
    }
}
//
// Architectural notes:
//   hostIFProcessing should be called here ..
//
 /*
  * Initializes  the wmi path.
  */

struct wmi_info *
wmiTcmdInit(wlan_tcmd_dev_t *dev)
{
    A_INT32 i;
    A_UINT32 num_hmem_reqs=0;
    struct wmi_event_hdr *evh;
    struct wmi_info *wi = &wmiInfo;
    wi->wi_devht       = dev;
    wi->wi_dtm_drained = 0;
    wi->wi_sync_state  = DEFAULT_SYNC;

//    A_PRINTF_ONCE("tcmd_enable in wmiTcmdInit\n");
#if defined(DBGLOG_FTM_SUPPORT)
    utf_allocate_dbgbufspace(&_wlan_wmi_api);
#endif
    HTC_Init(tcmd_enable, MAX_PAYLOAD_LEN);

    WMITcmdControlService.ProcessRecvMsg = wmi_tcmd_htc_rx;
    WMITcmdControlService.ProcessSendBufferComplete = wmi_tcmd_htc_tx_complete;
    WMITcmdControlService.ProcessConnect = wmi_tcmd_ctrl_svc_connect;
    WMITcmdControlService.MaxSvcMsgSize = WMI_SVC_MSG_SIZE + sizeof(WMI_CMD_HDR);
    WMITcmdControlService.TrailerSpcCheckLimit = WMI_CONTROL_BUFSZ;
    WMITcmdControlService.ServiceID = WMI_CONTROL_SVC;
    HTC_RegisterService(&WMITcmdControlService);

      /* Even though TCMD doesnt require any DATA services, we register 4 data
         services similar to WLAN, inorder to have same host driver.
         Note that this is harmless , as long as the host doesn't
         send any data on this services.
       */
    for (i = 0; i < TCMD_DATA_SERVICES  ; i++) {
        TcmdDataServices[i].ProcessRecvMsg = wmi_tcmd_htc_rx;
        TcmdDataServices[i].ProcessSendBufferComplete =
                                                       wmi_tcmd_htc_tx_complete;
        TcmdDataServices[i].ProcessConnect = wmi_tcmd_ctrl_svc_connect;
        TcmdDataServices[i].MaxSvcMsgSize = WMI_TCMD_CTRL_MAX_HTC_MSG_SIZE;
        TcmdDataServices[i].TrailerSpcCheckLimit = WMI_CONTROL_BUFSZ;
    }
        TcmdDataServices[0].ServiceID = WMI_DATA_BE_SVC;
        HTC_RegisterService(&TcmdDataServices[0]);
        TcmdDataServices[1].ServiceID = WMI_DATA_BK_SVC;
        HTC_RegisterService(&TcmdDataServices[1]);
        TcmdDataServices[2].ServiceID = WMI_DATA_VI_SVC;
        HTC_RegisterService(&TcmdDataServices[2]);
        TcmdDataServices[3].ServiceID = WMI_DATA_VO_SVC;
        HTC_RegisterService(&TcmdDataServices[3]);
#if defined(AR6320)
        TcmdDataServices[4].ServiceID = HTT_DATA_MSG_SVC;
        HTC_RegisterService(&TcmdDataServices[4]);
#endif //AR6320
    /*
     * HTC needs to allocate free desc pool based on number of cmd and event
     * buffers.
     */
    HTC_AddBufferResources( WMI_TCMD_NUM_BUFFERS +
                            WMI_TCMD_NUM_EVENT_BUFFERS);

    /*
     * initialize wmi buffer pool and give it HTC, Note that this operation
     * needs to be done before, HTC completes the setup operation. i.e before
     * the app calls HTC_Ready.
     */

    //A_DATA_CACHE_INVAL(wmihtc_buffers.data, sizeof(wmihtc_buffers.data));
    for (i= 0; i < WMI_TCMD_NUM_BUFFERS; i++) {
        evh = &wmi_tcmd_cmd_buffers[i];
        evh->we_flag = WMIEV_FREE_FLG;
        evh->we_bufinfo.next = NULL;
#if defined(AR900B)
        evh->we_bufinfo.buffer = A_ALLOCRAM_BY_ARENA(ALLOCRAM_SRAM_ARENA, MAX_PAYLOAD_LEN + HTC_HDR_SZ + sizeof(WMI_CMD_HDR));
#else
        evh->we_bufinfo.buffer = A_ALLOCRAM(MAX_PAYLOAD_LEN + HTC_HDR_SZ + sizeof(WMI_CMD_HDR));
#endif
        evh->we_bufinfo.buffer += HTC_HDR_SZ;
        evh->we_bufinfo.actual_length = 0;
        HTC_ReturnBuffers(ENDPOINT0, &evh->we_bufinfo);
    }

    //A_DATA_CACHE_INVAL(wmihtc_event_buffers.data, sizeof(wmihtc_event_buffers.data));
    for (i = 0; i < WMI_TCMD_NUM_EVENT_BUFFERS; i++) {
        evh = &wmi_tcmd_ev_buffers[i];
        evh->we_flag = WMIEV_FREE_FLG;
        evh->we_bufinfo.next = NULL;
#if defined(AR900B)
        evh->we_bufinfo.buffer = A_ALLOCRAM_BY_ARENA(ALLOCRAM_SRAM_ARENA, MAX_PAYLOAD_LEN + HTC_HDR_SZ + sizeof(WMI_CMD_HDR));
#else
        evh->we_bufinfo.buffer = A_ALLOCRAM(MAX_PAYLOAD_LEN + HTC_HDR_SZ + sizeof(WMI_CMD_HDR));
#endif
        evh->we_bufinfo.buffer += HTC_HDR_SZ;
        evh->we_bufinfo.actual_length = 0;
    }

#if defined(DBGLOG_FTM_SUPPORT)
    utf_init_dbglog(wi);
#endif
    htt_tgt_hif_svc_init();

    /*
     * register for host memory for Calibration data.
     */
    wlan_utf_cal_register(dev->host_mem_req,&num_hmem_reqs);
    HTC_Ready();
    return (wi);
}

extern wlan_tcmd_dev_t utf_dev;
void wmiIFAttach(void)
{
//    A_PRINTF_ONCE("wmiIFAttach \n");
    utf_dev.wmi = wmiTcmdInit(&utf_dev);
}

/*
 * wmi_alloc_evbuf is used to allocate a buffer to send an event to
 * the host.  The size provided is the length of the wmi event message
 * not including the WMI_CMD_HDR.  The returned wmi_tcmd_event_hdr will
 * contain a buffer of at least size bytes.
 */
struct wmi_event_hdr *
wmi_alloc_evbuf(struct wmi_info *wi, A_INT32 size)
{
    struct wmi_event_hdr *evh;
    A_INT32 i;

//    A_PRINTF("wmi_alloc_evbuf , size %d \n", size);

    for (i=0; i < WMI_TCMD_NUM_EVENT_BUFFERS; i++) {
        evh = &wmi_tcmd_ev_buffers[i];
        if (evh->we_flag & WMIEV_FREE_FLG) {
            evh->we_bufinfo.next = NULL;
            evh->we_bufinfo.actual_length = size + sizeof(WMI_CMD_HDR);
            evh->we_flag = WMIEV_WMIBUF_FLG;    /* clrs WMIEV_FREE_FLG */
            A_MEMZERO(evh->we_bufinfo.buffer, evh->we_bufinfo.actual_length);
            return (evh);
        }
    }

#if 0
    for (i=0; i < WMI_TCMD_NUM_EVENT_BUFFERS; i++)
    {
        evh = &wmi_tcmd_ev_buffers[i];
        if (!(evh->we_flag & WMIEV_FREE_FLG))
        {
            A_PRINTF("%d evh->we_flag %x \n",i, evh->we_flag);
        }
    }
#endif
    return (NULL);
}
/*
 * reset's bufinfo used for control receive channel and gives it back to
 * HTC.
 */
void
wmi_control_refill(struct wmi_info *wi, struct HTC_bufinfo_s *bufinfo,
                   HTC_ENDPOINT_ID eid)
{
    A_ASSERT(bufinfo->next == NULL);
    bufinfo->buffer -= HTC_HDR_LENGTH;
    A_DATA_CACHE_INVAL(bufinfo->buffer, bufinfo->actual_length + HTC_HDR_SZ);
    HTC_ReturnBuffers(eid, bufinfo);
}
void
wmi_free_evbuf(struct wmi_info *wi, struct wmi_event_hdr *evh)
{
    struct wmi_event_hdr *next;

    while (evh != NULL) {
        next = (struct wmi_event_hdr *)(evh->we_bufinfo.next);
        evh->we_bufinfo.next = NULL;
        if (evh->we_flag & WMIEV_WMIBUF_FLG) {
            evh->we_flag = WMIEV_FREE_FLG;
        } else {
            //A_PRINTF("wmi_free_evbuf: bad flag!\n");
        }
        evh = next;
    }
}

void
wmi_tcmd_event_send(struct wmi_info *wi, struct wmi_event_hdr *evh)
{
    /* Invalidate buffer memory */
    A_DATA_CACHE_FLUSH(evh->we_bufinfo.buffer, evh->we_bufinfo.actual_length);
    HTC_SendMsg(wmiTcmdControlEp, &evh->we_bufinfo);
}

void
wmi_tcmd_service_ready_event(struct wmi_info *wi)
{
    A_UINT8 *evbuf;
    struct wmi_event_hdr *evh;
    wmi_service_ready_event *readyev;
    A_UINT32 idx;
#if defined(CONFIG_160MHZ_SUPPORT)
    A_UINT32 vht_cap_mask;
#endif  

    evh = wmi_alloc_evbuf(wi, sizeof(wmi_service_ready_event));
    if (evh == NULL) {
        //A_PRINTF("No WMI event Buffers\n");
        A_ASSERT(FALSE);
        return;
    }

    evbuf = evh->we_bufinfo.buffer;
    ((WMI_CMD_HDR *)evbuf)->commandId = WMI_SERVICE_READY_EVENTID;
    ((WMI_CMD_HDR *)evbuf)->plt_priv = 0;
    readyev = (wmi_service_ready_event *)(evbuf + sizeof(WMI_CMD_HDR));
    readyev->sw_version = SOC_SW_VERSION;
    readyev->abi_version = SOC_ABI_VERSION;

    readyev->phy_capability = 0;

    /* Copy other device capabilities */
    readyev->num_rf_chains = 1;//utf_dev.pdev->pdev_info->num_rf_chains;
    readyev->ht_cap_info   = 0;//utf_dev.pdev->pdev_info->ht_cap_info;
    readyev->vht_cap_info  = 0;//DEV_GET_WAL_PDEV_INFO(utf_dev.pdev)->vht_cap_info;
#if defined(CONFIG_160MHZ_SUPPORT)
    readyev->vht_cap_info  = VHT_CAP_WITH_STBC_1SS_VHT160;
    vht_cap_mask = wal_set_vht160_cap_info();
    readyev->vht_cap_info |= vht_cap_mask;
#else
    readyev->vht_cap_info  = VHT_CAP_WITH_STBC_1SS_VHT80;
#endif
    readyev->vht_supp_mcs  = 0;//DEV_GET_WAL_PDEV_INFO(utf_dev.pdev)->vht_supp_mcs;
    whalGetRegCapabilities(&readyev->hal_reg_capabilities);
#if defined(CONFIG_BAND_SWITCH)
    /* Convey the support for GPIO programming for band select to host */
    WMI_SERVICE_ENABLE(readyev->wmi_service_bitmap, WMI_SERVICE_PROG_GPIO_BAND_SELECT);
#endif

    readyev->num_mem_reqs  = 0;
    idx=0;
    while(idx < UTF_MAX_HOST_MEM_REQ && utf_dev.host_mem_req[idx].unit_size) {
         readyev->mem_reqs[idx]  = utf_dev.host_mem_req[idx];
         ++idx;
         ++readyev->num_mem_reqs;
    }

    evh->we_bufinfo.actual_length += ((readyev->num_mem_reqs > 1) ? (sizeof(readyev->mem_reqs[0])*(readyev->num_mem_reqs-1)) : 0);

    /* Invalidate buffer memory */
    A_DATA_CACHE_FLUSH(evh->we_bufinfo.buffer, evh->we_bufinfo.actual_length);
    HTC_SendMsg(wmiTcmdControlEp, &evh->we_bufinfo);

}


struct wmi_info temp_wmi_info;
A_UINT8 temp_mac[6];

void
wmi_tcmd_ready_event_2(struct wmi_info *wi, A_UINT8 *macaddr)
{
    A_UINT8 *evbuf;
    struct wmi_event_hdr *evh;
    wmi_ready_event *readyev;

    evh = wmi_alloc_evbuf(wi, sizeof(wmi_ready_event));
    if (evh == NULL) {
        //A_PRINTF("No WMI event Buffers\n");
        A_ASSERT(FALSE);
        return;
    }

    evbuf = evh->we_bufinfo.buffer;
    ((WMI_CMD_HDR *)evbuf)->commandId = WMI_READY_EVENTID;
    ((WMI_CMD_HDR *)evbuf)->reserved = 0;
    ((WMI_CMD_HDR *)evbuf)->plt_priv = 0;
    readyev = (wmi_ready_event *)(evbuf + sizeof(WMI_CMD_HDR));
    WMI_MAC_ADDR_TO_CHAR_ARRAY(&readyev->mac_addr, macaddr);
    readyev->sw_version = SOC_SW_VERSION;
    readyev->abi_version = SOC_ABI_VERSION;

    wmi_tcmd_event_send(wi, evh);
}


/*
 * Individual Events common between apps.
 */
void
wmi_tcmd_ready_event(struct wmi_info *wi, A_UINT8 *macaddr)
{
#ifndef IPQ4019
    A_UINT8 *evbuf;
    struct wmi_event_hdr *evh;
    wmi_ready_event *readyev;

    wmi_tcmd_service_ready_event(wi);
    evh = wmi_alloc_evbuf(wi, sizeof(wmi_ready_event));
    if (evh == NULL) {
        //A_PRINTF("No WMI event Buffers\n");
        A_ASSERT(FALSE);
        return;
    }

    evbuf = evh->we_bufinfo.buffer;
    ((WMI_CMD_HDR *)evbuf)->commandId = WMI_READY_EVENTID;
    ((WMI_CMD_HDR *)evbuf)->reserved = 0;
    ((WMI_CMD_HDR *)evbuf)->plt_priv = 0;
    readyev = (wmi_ready_event *)(evbuf + sizeof(WMI_CMD_HDR));
    WMI_MAC_ADDR_TO_CHAR_ARRAY(&readyev->mac_addr, macaddr);
    readyev->sw_version = SOC_SW_VERSION;
    readyev->abi_version = SOC_ABI_VERSION;

    wmi_tcmd_event_send(wi, evh);
#else
    /* WMI_READY_EVENT is replied after receiving WMI_INIT_CMD.
     * Send WMI_SERVICE_READY_EVENT here, but reply WMI_READY_EVENT
     * after receiving WMI_INIT_CMD in wmi_cmd_rx(). */
    wmi_tcmd_service_ready_event(wi);

    memcpy(&temp_wmi_info, wi, sizeof(struct wmi_info));
    memcpy(temp_mac, macaddr, 6);
#endif

    wi->wi_ready = TRUE;
    HOST_INTEREST->hi_app_host_interest = (A_UINT32)HOSTAPPSPACE_PTR;
    CMNOS_DCACHE_FLUSH(HOSTAPPSPACE_PTR, sizeof(struct host_app_area_s));
    CMNOS_DCACHE_FLUSH(&(HOST_INTEREST->hi_app_host_interest), sizeof(HOST_INTEREST->hi_app_host_interest));
}

void
parse_unifiedcmd (A_UINT8 *buffer, A_UINT16 dataLen)
{
    struct wmi_info *wi = &wmiInfo;

    SEG_HDR_INFO_STRUCT segHdrInfo;
    static A_UINT32 currentSeq,expectedSeq,totalNumOfSegments;
    static A_UINT32 length=0;

    //A_PRINTF_ONCE("len %d\n",dataLen);
    segHdrInfo = *(SEG_HDR_INFO_STRUCT *)&(buffer[0]);

    currentSeq = (segHdrInfo.segmentInfo & 0xF);
    totalNumOfSegments = (segHdrInfo.segmentInfo >>4)&0xF;
    dataLen = dataLen - sizeof(segHdrInfo);

    if (HOST_ON_BE_CPU()) {
        swapEnable = 1;
    }
    else {
        swapEnable = 0;
    }
#if defined(QCA9888_TCMD_WAR)
	cmnos_printf(".");
   	swapEnable = 0; // force no swap even host is BE
#endif
   // A_PRINTF("segmentInfo=%d, msgref=%d, len=%d\n", segHdrInfo.segmentInfo,segHdrInfo.msgref,segHdrInfo.len);


    //A_PRINTF("total Len %d msgref %d totalNumofSegments %d segmentNumber %d\n",segHdrInfo.len,segHdrInfo.msgref,totalNumOfSegments,currentSeq);

    if ( currentSeq == 0 )
    {
        //A_PRINTF("First Segment\n");
        expectedSeq = 0;
        length = 0;
    }
    else
    {
        if ( expectedSeq != currentSeq )
        {
            A_PRINTF("Mismatch in expecting seq expected Seq %d got seq %d\n",expectedSeq,currentSeq);
        }
    }


    A_MEMCPY(&dataPayload[length], &buffer[sizeof(segHdrInfo)], dataLen);
    length = length + dataLen;
    expectedSeq++;

    if ( expectedSeq == totalNumOfSegments )
    {
        if( length != segHdrInfo.len )
        {
            A_PRINTF("All segs received total len mismatch .. len %d total len %d\n",length,segHdrInfo.len);
        }
#if defined(QCA9888_TCMD_WAR)
    do {
        int i;
        A_UINT32 byte4, swappedByte4;
        /* Even below dummy code not executed, it can resolve T-command failure issue */
        if (swapEnable){
            for(i=0; i<length/4; i++){
                byte4=*((A_UINT32*)&dataPayload[i*4]);
                swappedByte4=SWAP32(byte4);
                *(A_UINT32*)&dataPayload[4*i]=swappedByte4;
            }
        }
    } while(0);
#endif
        tcmd_parse_cmd(wi->wi_devht, dataPayload, length);
    }
}

/*
 * TCMD has a single WMI cmd which encapsulates all the tcmd specific cmds.
 */
A_STATUS
wmi_cmd_rx(A_UINT8 *buffer, A_UINT16 dataLen)
{
	WMI_CMD_ID cmd;
    WMI_CMD_HDR *cmdHdrp;
    A_UINT8 *pCmdBuffer;
    //struct wmi_info *wi = &wmiInfo;
    //A_PRINTF_ONCE("wmi_cmd_rx received.\n");
    if(dataLen < sizeof(WMI_CMD_HDR)) {
        /*
         *XXX packet too short - drop cmd and signal error in debug
         */
        WMI_PRINTF("wmi_cmd_rx: pkt too short\n");
        return (A_ERROR);
    }

    cmdHdrp = (WMI_CMD_HDR *)buffer;
    pCmdBuffer = (A_UINT8 *)((WMI_CMD_HDR *)buffer + sizeof(WMI_CMD_HDR));
    cmd = cmdHdrp->commandId;
    buffer += sizeof(WMI_CMD_HDR);
    dataLen -= sizeof(WMI_CMD_HDR);

    switch (cmd) {
#if 0
    case WMI_TEST_CMDID:
            tcmd_parse_cmd(wi->wi_devht, buffer, dataLen);
        break;
#endif
    case WMI_PDEV_UTF_CMDID:
            A_PRINTF("WMI_INIT_CMD received.\n");
            parse_unifiedcmd(buffer,dataLen);
        break;
#ifdef IPQ4019
    case WMI_INIT_CMDID:
//        A_PRINTF_ONCE("WMI_INIT_CMD received.\n");
#if defined(DBGLOG_FTM_SUPPORT)
        DBGLOG_RECORD_LOG(WLAN_MODULE_FTM, -1, FTM_DBGID_WMI_INIT_RECVD, DBGLOG_UTF, 2, 0xAAAA, cmd);
#endif
        wmi_tcmd_ready_event_2(&temp_wmi_info, temp_mac);
        break;
    case WMI_PROG_GPIO_BAND_SELECT_CMDID:
    	{
            wmi_prog_gpio_band_select_cmd *p_cmd = (wmi_prog_gpio_band_select_cmd *) buffer;
            whalProgramGPIOForBandSelect(p_cmd->gpio_pin_number);
    	}
       break;
#else
    case WMI_INIT_CMDID:
//        A_PRINTF_ONCE("WMI_INIT_CMD received.\n");
#if defined(DBGLOG_FTM_SUPPORT)
        DBGLOG_RECORD_LOG(WLAN_MODULE_FTM, -1, FTM_DBGID_WMI_INIT_RECVD, DBGLOG_UTF, 2, 0xAAAA, cmd);
#endif
        wmi_tcmd_dispatch_wlan_init(cmd, pCmdBuffer);
        wmi_tcmd_ready_event_2(&temp_wmi_info, temp_mac);
        break;
#endif
#if defined(DBGLOG_FTM_SUPPORT)
     case WMI_DBGLOG_CFG_CMDID:
        {
            struct dbglog_config_msg_s configmsg;
            WMI_DBGLOG_CFG_CMD *cfg_cmd =
                ((WMI_DBGLOG_CFG_CMD *)buffer);
            A_MEMCPY(&configmsg, &cfg_cmd->config, sizeof(struct dbglog_config_msg_s));
            DBGLOG_CONFIG_DEBUG_MODULE(&configmsg);
            break;
        }
#endif
    case WMI_PDEV_SET_REGDOMAIN_CMDID:
        {
            A_UINT8 rdCtl[2];

            wmi_pdev_set_regdomain_cmd *p_cmd =
                (wmi_pdev_set_regdomain_cmd *) buffer;

            rdCtl[0] = p_cmd->conformance_test_limit_5G;
            rdCtl[1] = p_cmd->conformance_test_limit_2G;

#if defined(DBGLOG_FTM_SUPPORT)
			DBGLOG_RECORD_LOG(WLAN_MODULE_WAL, -1, FTM_DBGID_SETUP_CHANNEL ,  5, 5 , p_cmd->reg_domain,p_cmd->reg_domain_2G,p_cmd->reg_domain_5G,p_cmd->conformance_test_limit_5G,p_cmd->conformance_test_limit_2G);
#endif
            /*
             * For this Patch we are protecting the Regulatory settigs to be applied only for MKK Domain
             * So that other domain settings will not be take effect in FTM mode.
             */
            if((rdCtl[1] & 0xF0) == MKK)
                whalSetRegulatoryDomain(p_cmd->reg_domain, rdCtl);
            break;

        }
     default :
            A_PRINTF("WMI cmd not supported in Test mode :cmd = 0x%x\n", cmd);
       break;
    }

    return (A_OK);
}

/*
 * HTC callbacks
 */

/*
 * Teardown version wmi_htc_rx handler, since tcmd doesnt require support for
 * data path. This should be called only for WMI tcmd's even though its
 * registered for data services.
 */
void
wmi_tcmd_htc_rx(HTC_ENDPOINT_ID eid, struct HTC_bufinfo_s *bufinfo)
{
    struct wmi_info *wi = &wmiInfo;
    A_UINT8 * pBuffer;
    //A_PRINTF_ONCE("wmi_tcmd_htc_rx recieved \n");
    //A_PRINTF("wmi_tcmd_htc_rx \n");
    if (bufinfo == NULL) {
        //A_PRINTF("Empty buf received from HTC\n");
        A_ASSERT(FALSE);
        return;
    }
    if (eid == wmiTcmdControlEp) {
        A_ASSERT(bufinfo->next == NULL);      /* one buffer per cmd */
        pBuffer = bufinfo->buffer;

        /*
        * buffer address + WMI header is not WORD aligned,
        * we need to copy this to our alignment buffer such that when it
        * get's passed to wmi_cmd_rx, it is nicely aligned
        */
         if ((((A_UINT32)pBuffer + sizeof(WMI_CMD_HDR)) & 0x3) != 0) {
           if (bufinfo->actual_length <= WMI_CONTROL_BUFSZ) {
                A_MEMCPY(wmi_alignment_buffer.payload,  pBuffer,
                         bufinfo->actual_length);
                pBuffer = wmi_alignment_buffer.payload;
           }else {
               //A_PRINTF("Length exceed %d\n",bufinfo->actual_length);
               A_ASSERT(FALSE);
               return;
           }
        }
    wmi_cmd_rx(pBuffer, bufinfo->actual_length);
    /*
     * Reset the buf and give it back to HTC
     */
    }else {
        //A_PRINTF("TCMD app doesn't support data path\n");
    }
    /* Recycle buffer */
    wmi_control_refill(wi, bufinfo, eid);
}

/*
 * Registered senddone handler
 */
void
wmi_tcmd_htc_tx_complete(HTC_ENDPOINT_ID eid , struct HTC_bufinfo_s *bufinfo)
{
    struct wmi_event_hdr *evh;
    struct wmi_info *wi = &wmiInfo;
#if defined(DBGLOG_FTM_SUPPORT)
    A_UINT32 commandId;
#endif

    evh = (struct wmi_event_hdr *)bufinfo;
#if defined(DBGLOG_FTM_SUPPORT)
    commandId = ((WMI_CMD_HDR *)bufinfo->buffer)->commandId;
#endif

    if(eid != wmiTcmdControlEp) {
        //A_PRINTF("Reaped on incorrect eid %d\n", eid);
        A_ASSERT(FALSE);
    }
#if defined(DBGLOG_FTM_SUPPORT)
    if (commandId != WMI_DEBUG_MESG_EVENTID)
    {
#endif
        wmi_free_evbuf(wi, evh);
#if defined(DBGLOG_FTM_SUPPORT)
    }
    else
    {
        while (bufinfo != NULL)
        {

            WMI_EVT_PACKET *pEvt = (WMI_EVT_PACKET *)bufinfo;

            if (WMI_EVT_CLASS_DIRECT_BUFFER == pEvt->EventClass)
            {
                A_ASSERT(pEvt->BufType.Direct.pCompletion != NULL);
                /* call completion routine to notify event sender */
                pEvt->BufType.Direct.pCompletion(pEvt->BufType.Direct.pContext);
            }

            /* get next buffer */
            bufinfo = bufinfo->next;
            /* unlink this buffer */
            pEvt->HtcBuf.next = NULL;
            /* free this event */
            A_ASSERT(pEvt->EventClass < WMI_EVT_CLASS_MAX);
            A_ASSERT(!EVT_PKT_IS_FREE(pEvt));
            EVT_MARK_FREE(pEvt);
        }
    }
#endif
}
/*
 *  Events specific to TCMD.
 */
/*
 * Reports the rx results to the host. All the tcmd events are encapsulated
 * within WMI_TEST_EVENTID ( currently there is only one event).
 */

void
wmi_tcmd_cont_rx_reply_event(struct wmi_info *wi, A_UINT16 len, A_UINT8 *contRx)
{
#if 0
    A_UINT8 *evbuf;
    struct wmi_event_hdr *evh;
    TCMD_CONT_RX *rxCmd;
    evh = wmi_alloc_evbuf(wi, sizeof(*rxCmd));
    A_ASSERT(evh != NULL);

    evbuf = evh->we_bufinfo.buffer;
    ((WMI_CMD_HDR *)evbuf)->commandId = WMI_TEST_EVENTID;
    rxCmd = (TCMD_CONT_RX *)(evbuf + sizeof(WMI_CMD_HDR));

    A_MEMCPY(rxCmd, contRx, sizeof(TCMD_CONT_RX));
/*    rxCmd->act = TCMD_CONT_RX_REPORT;
    rxCmd->u.report.totalPkt = pkt;
    rxCmd->u.report.rssiInDBm = rssiInDBm;
    rxCmd->u.report.crcErrPkt = crcErrPkt;
    rxCmd->u.report.secErrPkt = secErrPkt;
    if (rateCnt) {
        A_MEMCPY(rxCmd->u.report.rateCnt, rateCnt, sizeof(rxCmd->u.report.rateCnt));
    }
    if (rateCntShortGuard) {
        A_MEMCPY(rxCmd->u.report.rateCntShortGuard, rateCntShortGuard, sizeof(rxCmd->u.report.rateCntShortGuard));
    }
*/

    wmi_tcmd_event_send(wi, evh);
#endif
    wmi_utf_unified_reply(wi, sizeof(TCMD_CONT_RX), contRx);
}


void wmi_tc_cmds_reply_event(struct wmi_info *wi, A_UINT16 len, A_UINT8 version, A_INT8* buf)
{
#if 0
    A_UINT8 *evbuf;
    struct wmi_event_hdr *evh;
    TC_CMDS *tCmd;
    evh = wmi_alloc_evbuf(wi, sizeof(*tCmd));
    A_ASSERT(evh != NULL);

    evbuf = evh->we_bufinfo.buffer;
    ((WMI_CMD_HDR *)evbuf)->commandId = WMI_TEST_EVENTID;
    tCmd = (TC_CMDS *)(evbuf + sizeof(WMI_CMD_HDR));

    tCmd->hdr.act = TC_CMD_RESP;
    tCmd->hdr.u.parm.length = len;
    tCmd->hdr.u.parm.version = version;
    A_MEMCPY(tCmd->buf, buf, len);

    wmi_tcmd_event_send(wi, evh);
#endif
    wmi_utf_unified_reply(wi, len,(A_UINT8*)buf);
}

void wmi_utf_unified_reply(struct wmi_info *wi, A_UINT16 len, A_UINT8* buf)
{
    A_UINT8 *evbuf,*payload,*bufpos;
    struct wmi_event_hdr *evh;
    static A_UINT32 msgref = 1; /// We can initialize the value and increment..
    A_UINT32 segNumber =0,segInfo,numSegments;
    A_UINT32  chunkLen, totalBytes;
    SEG_HDR_INFO_STRUCT segHdrInfo;

    if ( len > MAX_UTF_EVENT_LENGTH )
    {
        A_PRINTF("Length exceeded Max. %d length len %d\n",MAX_UTF_EVENT_LENGTH,len);
        return;
    }

    bufpos = buf;
    totalBytes = len;
    numSegments = (totalBytes / MAX_WMI_UTF_LEN );

//    A_PRINTF("totalBytes %d, numSegments %d \n", totalBytes, numSegments);

    if ( len - (numSegments * MAX_WMI_UTF_LEN) )
        numSegments++;

    while (len) {
        if (len > MAX_WMI_UTF_LEN)
            chunkLen = MAX_WMI_UTF_LEN; /* MAX messsage.. */
        else
            chunkLen = len;

        evh = wmi_alloc_evbuf(wi, (chunkLen + sizeof(segHdrInfo)));
        if (evh == NULL) {
            A_PRINTF("Alloc failed %d\n",(chunkLen + sizeof(segHdrInfo)));
            A_ASSERT(FALSE);
            return;
        }

        evbuf = evh->we_bufinfo.buffer;
        ((WMI_CMD_HDR *)evbuf)->commandId = WMI_PDEV_UTF_EVENTID;
        ((WMI_CMD_HDR *)evbuf)->reserved = 0;
        ((WMI_CMD_HDR *)evbuf)->plt_priv = 0;

        payload = (A_UINT8 *)(evbuf + sizeof(WMI_CMD_HDR));

        segHdrInfo.len = totalBytes;
        segHdrInfo.msgref =  msgref;
        segInfo = ((numSegments << 4 ) & 0xF0) | (segNumber & 0xF);
        segHdrInfo.segmentInfo = segInfo;

        //A_PRINTF("totalBytes %d segNumber %d totalSegments %d chunk len %d\n",totalBytes,segNumber,numSegments,chunkLen);

        segNumber++;

        A_MEMCPY(payload, &segHdrInfo, sizeof(segHdrInfo)); // 4 bytes..
        A_MEMCPY(&payload[sizeof(segHdrInfo)], bufpos, chunkLen);

        wmi_tcmd_event_send(wi, evh);

        if ( numSegments > 1 )
            A_DELAY_USECS(100);

        len -= chunkLen;
        bufpos += chunkLen;
    }

    msgref++;
}


/*===============================================================================

FUNCTION : wlan_utf_cal_register

Description:
    This function is used to register the firmware request for memory on the HOST.
    Because Firmware is memory strapped , the HOST memory is used.

Parameters:
    wlan_pdev : Pointer to the Peer data structure
    host_mem_req_array : The Global structure for Host memory
    This is used to combine all Host memory requests across all modules
    p_host_mem_req_array_index  : This is the index used to place a unique
    set of requirements to the HOST memory structure.

Return Value : None.

===============================================================================*/
void wlan_utf_cal_register(
        wlan_host_mem_req * host_mem_req_array,
        A_UINT32 *p_host_mem_req_array_index)
{
#if defined(CONFIG_FAST_CALIBRATION_SUPPORT)
//    A_PRINTF_ONCE("wlan_utf_cal_register \n");
    pCalibrationData = utf_cal_get_ctxt();
    if(pCalibrationData != NULL){
        wlan_host_mem_req *h_mem_req = &host_mem_req_array[*p_host_mem_req_array_index];
        h_mem_req->unit_size        = pCalibrationData->nHomeChannelBufferSize; // Get this final size from Halphy team
        h_mem_req->num_units        = (pCalibrationData->nTotalNumberOfChannels * MAX_NUMBER_OF_MODES * MAX_NUMBER_OF_CHAINMASKIDX);
        h_mem_req->num_unit_info    = 0;
        h_mem_req->req_id           = pCalibrationData->nHomeChannelRegistrationID;
        *p_host_mem_req_array_index = *p_host_mem_req_array_index + 1;
        h_mem_req ++;

    }
    else{
        A_PRINTF("UTF_CAL registration error : pCalibrationData = NULL\n");
    }

#endif
    return;

} /* END  _wlan_utf_cal_register */



/*===============================================================================

FUNCTION : _wlan_utf_cal_init

Description:
    This function is called after HOST sends a wmi command back to the firmware
    to initialize WMI_INIT_CMDID.It is used to allocate the calibration context
    and find out which host memory chunks are allocated by the HOST to store
    the requested calibration data.

Parameters:
    pdev : Pointer to the Peer Data structure.
    num_chunks : Total number of chunks allocated by the HOST for all Firmware
    modules requesting HOST memory.
    p_chunks : Pointer to the HOST chunk array.
    HOST memory is allocated in chunks not contiquously. Each chunk
    is labeled for the module that is requesting a certain amount of memory.
    HOST memory is allocated in multiples of chunks to meet the total aggregate
    of the memory requirement of firmware module that has registered its needs in
    a prior api such as _wlan_cal_register

Return Value :
    None.

===============================================================================*/
void wlan_utf_cal_init (A_UINT32 num_chunks, wlan_host_memory_chunk *p_chunks)
{
#if defined(CONFIG_FAST_CALIBRATION_SUPPORT)
    A_UINT32 nIdx,nUsedChunkBytes,nUnusedChunkBytes,nCopyBuffSize, nChannelCount;
    A_UINT32 ChainMskIdx, ModeIdx;
 if (p_chunks == NULL)
    {
      A_PRINTF("pCalibrationData = NULL \n");
      return;
    }

    utf_cal_ctxt *pCalData = pCalibrationData;
    nCopyBuffSize = pCalData->nHomeChannelBufferSize;
    if(A_ERROR == utf_cal_init()){
        return;
    }
    nChannelCount = 0;
    ChainMskIdx = 0;
    ModeIdx = 0;
    for ( nIdx = 0; nIdx < num_chunks; nIdx ++ ) {
        if(nChannelCount >= pCalData->nTotalNumberOfChannels){
          break;
        }
        if ((p_chunks[nIdx].req_id == pCalData->nHomeChannelRegistrationID) &&
            (p_chunks[nIdx].size >= (pCalData->nHomeChannelBufferSize))) {
        //    A_PRINTF_ONCE("p_chunks[nIdx].size = %d ,nIdx = %d p_chunks[nIdx].ptr = %d \n", p_chunks[nIdx].size, nIdx, p_chunks[nIdx].ptr);
          //  A_PRINTF_ONCE("***nChannelCount = %d ChainMskIdx = %d ModeIdx = %d \n",nChannelCount,ChainMskIdx,ModeIdx);
            nUsedChunkBytes = 0;
            nUnusedChunkBytes = p_chunks[nIdx].size;
            while (( nChannelCount < pCalData->nTotalNumberOfChannels ) && ( nUnusedChunkBytes >= nCopyBuffSize )){

                while ((ChainMskIdx < MAX_NUMBER_OF_CHAINMASKIDX) && ( nUnusedChunkBytes >= nCopyBuffSize )){

                    while ((ModeIdx < MAX_NUMBER_OF_MODES)&&( nUnusedChunkBytes >= nCopyBuffSize )) {

                        pCalData->pChannelData[nChannelCount].aChainMask[ChainMskIdx].aMode[ModeIdx].nHostCalibrationBufAddr =
                        (A_UINT32) p_chunks[nIdx].ptr + nUnusedChunkBytes;

                        nUsedChunkBytes += nCopyBuffSize;
                        nUnusedChunkBytes -= nCopyBuffSize;
                        //A_PRINTF_ONCE("nChannelCount = %d ChainMskIdx = %d ModeIdx = %d ",nChannelCount,ChainMskIdx,ModeIdx);
                        //A_PRINTF_ONCE("address = %d \n", pCalData->pChannelData[nChannelCount].aChainMask[ChainMskIdx].aMode[ModeIdx].nHostCalibrationBufAddr);
                        ModeIdx ++;
                    }
                    if (ModeIdx >= MAX_NUMBER_OF_MODES){
                        ModeIdx = 0;
                        ChainMskIdx ++;
                    }
                }
                pCalData->pChannelData[nChannelCount].nChannelNumber = INVALID_CHANNEL_NUMBER;
                if (ChainMskIdx >= MAX_NUMBER_OF_CHAINMASKIDX){
                    ChainMskIdx = 0;
                    nChannelCount++;
                }

            }
        }
    }

   /*
    * Make Sure the chunks allocated are enough for all calibration data storage.
    */
    A_ASSERT( nChannelCount <= pCalData->nTotalNumberOfChannels);

#endif

    return;

} /* END  _wlan_utf_cal_init */


/*===============================================================================

FUNCTION : wmi_tcmd_dispatch_wlan_init

Description:
    This function is used to reserve memory from the host once the wmi command
    is received from the HOST.

Parameters:
    A_UINT32 cmd      : The command parameter from HOST
    A_UINT8 * buffer  : The cmmand buffer from HOST.

Return Value:
    None.

===============================================================================*/
void wmi_tcmd_dispatch_wlan_init(A_UINT32 cmd, A_UINT8 * pCmdBuffer)
{
    wmi_init_cmd *p_cmd = (wmi_init_cmd *)pCmdBuffer;
    if((p_cmd->host_mem_chunks != NULL)&&(p_cmd->num_host_mem_chunks != 0))
    {
        wlan_utf_cal_init(p_cmd->num_host_mem_chunks, p_cmd->host_mem_chunks);
    }
    return;

}/* End  wmi_tcmd_dispatch_wlan_init */

