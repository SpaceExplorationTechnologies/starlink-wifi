/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
// Copyright (c) 2011 Atheros Communications Inc.
// All rights reserved.
// $ATH_LICENSE_TARGET_C$
//

/*
 * HTT target -> host message transport
 */

#include <osapi.h>                  /* A_UINT8 */
#include <os/athos_api.h>           /* iHTC_SendMsg */
#include <htc_api.h>                /* HTC_ENDPOINT_ID, HTC_BUFFER */
#include <htt.h>
#include <htt_tgt_api.h>
//#include <htt_tgt_rx_api.h>         /* htt_tgt_hif_svc_msg_to_host */
#include "htt_tgt_hif_internal.h"   /* htt_tgt_hif_svc_connect, etc */
#include <mbox_map.h>               /* ac_to_htc_ep */
#include <htc_services.h>           /* HTT_DATA_MSG_SVC */
#include <htc.h>                    /* HTC_SERVICE_SUCCESS */
#include <wlan_dev.h>               /* GET_PDEV */
#include <wal_rx.h>                 /* wal_rx_ring_setup */
#include <mbox_map.h>               /* ac_to_htc_ep */
//#include <htt_tgt_tx_api.h>         /* htt_tgt_tx APIs */
#include <pipecfg_api.h>

#define ARRAY_LEN(x) (sizeof(x)/sizeof((x)[0]))

#if defined(AR6320)
#define HTT_HL_DATA_SVC_PIPE_DEPTH_TCMD 12 
#else
#define HTT_HL_DATA_SVC_PIPE_DEPTH_TCMD HTT_HL_DATA_SVC_PIPE_DEPTH 
#endif


#if defined(A_SIMOS)
#include <simhw/simhw_api.h> /* sim_has_host */
void htt_sim_htc_send_msg(
    void *dummy_instance, HTC_ENDPOINT_ID endpoint, HTC_BUFFER *msg_buf);
#define HTT_HTC_SEND_MSG(htc_instance, endpoint, msg_buf)           \
    do {                                                            \
        if (sim_has_host()) {                                       \
            iHTC_SendMsg(htc_instance, endpoint, msg_buf);          \
        } else {                                                    \
            htt_sim_htc_send_msg(htc_instance, endpoint, msg_buf);  \
        }                                                           \
    } while (0)
void htt_sim_htc_register_service(HTC_SERVICE *pService);
#define HTT_HTC_REGISTER_SERVICE(service)          \
    do {                                           \
        if (sim_has_host()) {                      \
            HTC_RegisterService(service);          \
        } else {                                   \
            htt_sim_htc_register_service(service); \
        }                                          \
    } while (0)
#else
    /* real HW - real HTC */
    #define HTT_HTC_SEND_MSG iHTC_SendMsg
    #define HTT_HTC_REGISTER_SERVICE HTC_RegisterService
#endif

struct htt_tgt_hif_svc_h2t_state {
    HTC_BUFFER *h2t_recv_buf_freelist;
    htt_tgt_hif_svc_h2t_msg_cb cbs[HTT_H2T_NUM_MSGS];
};

#define HTT_INVALID_ENDPOINT -1
struct htt_tgt_hif_svc_state {
    int endpoint;
    int max_msg_sz;
    htt_tgt_hif_svc_cb callbacks[HTT_T2H_NUM_MSGS];
    struct htt_tgt_hif_svc_h2t_state h2t_state;
//} *g_htt_tgt_hif_svc_state_ptr = NULL;
} g_htt_tgt_hif_svc_state, *g_htt_tgt_hif_svc_state_ptr = NULL;

/* This function currently applies to Hera but not McKinley */
void
_htt_tgt_hif_svc_data_to_host(void *ctxt, A_UINT16 pid,
    A_UINT32 tid, struct wal_rx_status *mpdu_list,
    int count, enum htt_rx_ind_mpdu_status status)
{
    BUF_LIST chain;
    struct ath_buf *abf;
    struct HTC_bufinfo_s *htc_buf;
    struct HTC_bufinfo_s *prev_htc_buf;
    struct HTC_bufinfo_s *first_htc_buf;
    A_UINT8 *buffer_start;
    A_UINT8 *buffer_pos;
    A_UINT8 ac;

    A_MEMZERO(&chain, sizeof(BUF_LIST));
    /* ring operation: update the ring index and get the MSDUs in chain  */
//    htt_tgt_rx_ind_handler(ctxt, rx_peer_state, tid, mpdu_list, count, status, &chain);
    if (WAL_NON_QOS_TID == tid) {
        tid = WAL_DEFAULT_TID;
    }
    ac = TID_TO_WMM_AC(tid);
    /* convert format from 'ath_buf' to 'HTC_bufinfo_s' */
    abf = STAILQ_FIRST(&(chain.buf_list));
    A_ASSERT(abf);
    first_htc_buf = ATH2HTC(abf);
    /* link all buf to htc_buf list */
    while (abf) {
        htc_buf = ATH2HTC(abf);
#if defined(A_SIMOS)
        A_PRINTF("HTT Debug(%s): htt_tgt_rx_ring_enque--(abf=0x%x, rx=0x%x)\n",
                 __FUNCTION__, (A_UINT32)abf, (A_UINT32)WLAN_BUF_START(abf->bf_b.wlanBuf.rx));
#endif
        if (WLAN_BUF_LENGTH(abf->bf_b.wlanBuf.rx)) {
            buffer_start = (A_UINT8 *)&abf->bf_b.wlanBuf.rx->bfData;
            buffer_pos = (A_UINT8 *)WLAN_BUF_START(abf->bf_b.wlanBuf.rx);
            htc_buf->buffer = buffer_pos;
            htc_buf->buffer_offset = buffer_pos - buffer_start;
            htc_buf->actual_length = WLAN_BUF_LENGTH(abf->bf_b.wlanBuf.rx);
        } else {
            /* FIXME: A zero length buffer, free it to Ring? */
#if defined(A_SIMOS)
            buffer_start = (A_UINT8 *)&abf->bf_b.wlanBuf.rx->bfData;
            buffer_pos = (A_UINT8 *)WLAN_BUF_START(abf->bf_b.wlanBuf.rx);
            htc_buf->buffer = buffer_pos;
            htc_buf->buffer_offset = buffer_pos - buffer_start;
            htc_buf->actual_length = WLAN_BUF_LENGTH(abf->bf_b.wlanBuf.rx);
#else
            A_ASSERT(0);
#endif
        }

        prev_htc_buf = htc_buf;
        STAILQ_REMOVE_HEAD(&(chain.buf_list), bf_list);
        chain.num_of_bufs--;
        abf = STAILQ_FIRST(&(chain.buf_list));
        if(NULL != abf) {
            prev_htc_buf->next = ATH2HTC(abf);
        } else {
            prev_htc_buf->next = NULL;
        }
    }

    A_ASSERT(0 == chain.num_of_bufs);
    /* FIXME: the htc instance is 0? */
#if defined(A_SIMOS)
    if (sim_has_host()) {
        iHTC_SendMsg(g_pHTCInstances[0], ac_to_htc_ep(ac), first_htc_buf);
    } else {
        htt_tgt_rx_to_host_complete(ac_to_htc_ep(ac), first_htc_buf);
    }
#else
    iHTC_SendMsg(g_pHTCInstances[0], ac_to_htc_ep(ac), first_htc_buf);
#endif
}

void
_htt_tgt_hif_svc_msg_to_host(HTC_BUFFER *msg_buf, char *msg_data, int msg_bytes)
{
    /* check that the HTT_DATA_MSG service is connected */
    A_ASSERT(g_htt_tgt_hif_svc_state_ptr->endpoint != HTT_INVALID_ENDPOINT);
    /* make sure that we do not send message larger than maximum allowed */
    A_ASSERT(msg_bytes + (msg_data - (char *)msg_buf) <=
             g_htt_tgt_hif_svc_state_ptr->max_msg_sz);

    msg_buf->buffer = (A_UINT8 *) msg_data - HTC_HDR_ALIGNMENT_PADDING;
    msg_buf->actual_length = msg_bytes + HTC_HDR_ALIGNMENT_PADDING;
    msg_buf->next = NULL; /* sending single message */
    msg_buf->buffer_offset = 0;
    msg_buf->app_context = 0;

    /* FIX THIS
     * Assume that the initial (only?) HTC instance is the proper one to use.
     * (Perhaps get the HTC instance handle from the pService->pContext
     * parameter to htt_tgt_hif_svc_connect, and use that
     * dynamically-selected HTC instance, instead?)
     */
    HTT_HTC_SEND_MSG(
        g_pHTCInstances[0], g_htt_tgt_hif_svc_state_ptr->endpoint, msg_buf);
}

A_UINT8
_htt_tgt_hif_svc_connect(
    HTC_SERVICE *pService,
    HTC_ENDPOINT_ID endpoint,
    A_UINT8 *pDataIn,
    A_INT32 LengthIn,
    A_UINT8 *pDataOut,
    A_INT32 *pLengthOut)
{
    return HTC_SERVICE_SUCCESS;

    A_ASSERT(pService->ServiceID == HTT_DATA_MSG_SVC);

    g_htt_tgt_hif_svc_state_ptr->endpoint = endpoint;

    return HTC_SERVICE_SUCCESS;
}

/**
 * @brief Callback for when message transfer is finished.
 */
void
_htt_tgt_hif_svc_callback(HTC_ENDPOINT_ID endpoint, HTC_BUFFER *msg_buf)
{
    A_UINT8 msg_type;

    return;

    //A_ASSERT(endpoint == g_htt_tgt_hif_svc_state_ptr->endpoint);
    /* check the HTT message ID to determine how to route the completion */

    msg_type = HTT_T2H_MSG_TYPE_GET(*((A_UINT32 *)
        (((char *) msg_buf) + HTT_HTC_HDR_SIZE)));
    A_ASSERT(g_htt_tgt_hif_svc_state_ptr->callbacks[msg_type]);
    g_htt_tgt_hif_svc_state_ptr->callbacks[msg_type](msg_buf);
}

void
_htt_tgt_hif_svc_cb_set(A_UINT8 msg_type, htt_tgt_hif_svc_cb cb)
{
    A_ASSERT(msg_type > 0);
    A_ASSERT(msg_type < ARRAY_LEN(g_htt_tgt_hif_svc_state_ptr->callbacks));
    g_htt_tgt_hif_svc_state_ptr->callbacks[msg_type] = cb;
}


int _htt_tgt_hif_svc_max_msg_sz(void)
{
    return g_htt_tgt_hif_svc_state_ptr->max_msg_sz;
}

void
_htt_tgt_hif_svc_h2t_input(HTC_ENDPOINT_ID ep, HTC_BUFFER *bufs[], int num)
{
    int i;

    return;

    for (i = 0; i < num; i++) {
        A_UINT8 *msg_buf, h2t_msg_type;

        /*
         * For the existed htc_pipe implementation, there will not be more 
         * than 1 HTC buffer indicated to HTC_recvdone_fn_t callback. Thus, 
         * it is sufficient to have one extra buffer refilled right after 
         * receiving buffer dequeued.
         */
        htt_tgt_hif_svc_h2t_refill_recv_buf(ep, 1);

        /*
         * Adjust the HTC header padding accordingly so that H2T message
         * callbacks could directly handle the H2T message 
         */
        msg_buf = bufs[i]->buffer + HTC_HDR_ALIGNMENT_PADDING; 
        A_ASSERT(!((unsigned)msg_buf & 0x3));

        /*
         * Dispatch the H2T message to registered callback
         */
#if defined(CONVERGED_SW)
        h2t_msg_type = HTT_H2T_MSG_TYPE_GET(*(A_UINT32 *)msg_buf);
#else
        h2t_msg_type = HTT_H2T_MSG_TYPE_TX_FRM; 
#endif
        g_htt_tgt_hif_svc_state_ptr->h2t_state.cbs[h2t_msg_type](msg_buf);

        /* Return the handled H2T message buffer to freelist */
        bufs[i]->buffer -= HTC_HDR_LENGTH;
        bufs[i]->next = 
            g_htt_tgt_hif_svc_state_ptr->h2t_state.h2t_recv_buf_freelist;
        g_htt_tgt_hif_svc_state_ptr->h2t_state.h2t_recv_buf_freelist = 
            bufs[i];
    }
}

void
_htt_tgt_hif_svc_h2t_msg_cb_set(
    A_UINT8 msg_type, htt_tgt_hif_svc_h2t_msg_cb fn)
{
    /* Sanity check: allowed H2T message type */
    /* Sanity check: not registered before */
    if ((msg_type < HTT_H2T_NUM_MSGS) && (!g_htt_tgt_hif_svc_state_ptr->h2t_state.cbs[msg_type]))
    {
    	g_htt_tgt_hif_svc_state_ptr->h2t_state.cbs[msg_type] = fn;
    }
    else
    {
    	A_ASSERT(0);
    }
}

void 
_htt_tgt_hif_svc_h2t_refill_recv_buf(HTC_ENDPOINT_ID EndPt, int num) 
{
    int i;
    HTC_BUFFER *htc_buf = 
        g_htt_tgt_hif_svc_state_ptr->h2t_state.h2t_recv_buf_freelist;

    for (i = 0; i < num; i++) {
        HTC_BUFFER *htc_buf_next;

        A_ASSERT(htc_buf);
        htc_buf_next = htc_buf->next;
        htc_buf->next = NULL;
        HTC_ReturnBuffers(EndPt, htc_buf);
        htc_buf = htc_buf_next;
    }
    g_htt_tgt_hif_svc_state_ptr->h2t_state.h2t_recv_buf_freelist = htc_buf;
}

void 
_htt_tgt_hif_svc_h2t_recv_buf_pool_init(HTC_ENDPOINT_ID EndPt)
{
    /* 
     * enqueue the buffers to the pipe
     */
    htt_tgt_hif_svc_h2t_refill_recv_buf(EndPt, HTT_HL_DATA_SVC_PIPE_DEPTH_TCMD);
}

void 
_htt_tgt_hif_svc_h2t_recv_buf_pool_attach(int buf_sz, int pool_sz)
{
    int i;
    HTC_BUFFER *htc_buf = NULL;
    void *buf;

    /* Make sure we allocate the buffer with 4-octet aligned size */
    buf_sz = A_ROUND_UP_PWR2(buf_sz, 4);
    buf = A_ALLOCRAM(buf_sz * pool_sz);
    A_ASSERT(buf);

    g_htt_tgt_hif_svc_state_ptr->h2t_state.h2t_recv_buf_freelist = 
        (HTC_BUFFER *)buf;
    for (i = 0; i < pool_sz; i++) {
        htc_buf = buf;
        htc_buf->buffer = (unsigned char *)buf + sizeof(HTC_BUFFER);
        htc_buf->actual_length = buf_sz - sizeof(HTC_BUFFER);
        buf = (char *)buf + buf_sz;
        htc_buf->next = buf;
        htc_buf->buffer_offset = 0;
        htc_buf->app_context = 0;
    }
    /* Last HTC buffer should point to NULL */
    if (htc_buf)
    {
    	htc_buf->next = NULL;
    }
}

void
_htt_tgt_hif_svc_init(void)
{
    int buf_sz, pipe_id;
    static HTC_SERVICE htt_data_msg_service;

    if (g_htt_tgt_hif_svc_state_ptr) {
        /* already initialized */
        return;
    }

    /*
     * First allocate our own state object.
     * If there are any cycles in the series of init() calls, this
     * will allow the above check on g_htt_tgt_hif_svc_state_ptr
     * to break out of the cycle.
     */
    g_htt_tgt_hif_svc_state_ptr = &g_htt_tgt_hif_svc_state;
//    g_htt_tgt_hif_svc_state_ptr =
//        A_MALLOC(sizeof(*g_htt_tgt_hif_svc_state_ptr));
    A_ASSERT(g_htt_tgt_hif_svc_state_ptr != NULL);
    A_MEMSET(
        g_htt_tgt_hif_svc_state_ptr, 0, sizeof(*g_htt_tgt_hif_svc_state_ptr));
    g_htt_tgt_hif_svc_state_ptr->endpoint = HTT_INVALID_ENDPOINT;

    /*
     * Attach the H2T receive buffer pool
     *
     * NB: we are allocating the H2T receive buffer with the size of HTC
     * header + host Tx descriptor + partial SDU header, which is relatively
     * small so that we could have more queued to HW ring.
     *
     * We allocate total (depth of pipe + 1) buffers. This should be 
     * sufficient as for existed HTC_pipe implementation, only one HTC 
     * buffer will be indicated to receive callback. When HTT is 
     * processing dequeued buffer, HIF layer will not be able to dequeue
     * buffer any more.
     */
    buf_sz = sizeof(HTC_BUFFER) + A_ROUND_UP_PWR2(HTC_HDR_LENGTH, 4) + 
        HTT_TX_DESC_LEN +  HTT_HL_TX_FRM_HDR_LEN; 
    htt_tgt_hif_svc_h2t_recv_buf_pool_attach(
        buf_sz, HTT_HL_DATA_SVC_PIPE_DEPTH_TCMD + 1);

    /*
     * Figure out the maximum size of message allowed to send
     */
    pipe_id = pipecfg_service_lookup(HTT_DATA_MSG_SVC, PIPEDIR_IN);
    g_htt_tgt_hif_svc_state_ptr->max_msg_sz =
        pipecfg_max_msg_length(pipe_id, PIPEDIR_IN); 
         
    /*
     * Register our HTT data message service so HTC can connect
     * our service with an endpoint.
     */
    htt_data_msg_service.ProcessRecvMsgMultiple = htt_tgt_hif_svc_h2t_input; 
    htt_data_msg_service.ProcessSendBufferComplete = htt_tgt_hif_svc_callback;
    htt_data_msg_service.ProcessConnect = htt_tgt_hif_svc_connect;
    htt_data_msg_service.InitNonCreditRecvBuffer = 
        htt_tgt_hif_svc_h2t_recv_buf_pool_init;
    htt_data_msg_service.MaxSvcMsgSize = 2000; /* FIX THIS */
    htt_data_msg_service.ServiceID = HTT_DATA_MSG_SVC;

    HTT_HTC_REGISTER_SERVICE(&htt_data_msg_service);

}

#ifndef DISABLE_FUNCTION_INDIRECTION

HTT_TGT_HIF_SVC_API_FN   htt_tgt_hif_svc_api_indir_tbl = {
    _htt_tgt_hif_svc_init,
    _htt_tgt_hif_svc_cb_set,
    _htt_tgt_hif_svc_h2t_msg_cb_set,
    _htt_tgt_hif_svc_msg_to_host,
    _htt_tgt_hif_svc_max_msg_sz,
    NULL,
    NULL,
    _htt_tgt_hif_svc_data_to_host,
};

HTT_TGT_HIF_INTERNAL_FN  htt_tgt_hif_internal_indir_tbl = {
    _htt_tgt_hif_svc_connect,
    _htt_tgt_hif_svc_callback,
    _htt_tgt_hif_svc_h2t_recv_buf_pool_attach,
    _htt_tgt_hif_svc_h2t_recv_buf_pool_init,
    _htt_tgt_hif_svc_h2t_refill_recv_buf,
    _htt_tgt_hif_svc_h2t_input,
};

#endif

#if defined(A_SIMOS)

A_COMPILE_TIME_ASSERT(htt_hif_size_quantum, ((HTT_HTC_HDR_SIZE & 0x3) == 0))

void
htt_tgt_hif_svc_test_msg_buf_free_dummy(HTC_BUFFER *msg_buf)
{
    /* do nothing - the test msg buffer is a static (BSS) allocation */
}

void
htt_tgt_hif_svc_test_msg_send(void)
{
#define HTT_HIF_TEST_MSG_NUM_INTS  3
#define HTT_HIF_TEST_MSG_NUM_CHARS 10
#define HTT_HIF_TEST_MSG_BYTES \
    (4 /* header */ + \
    4 * HTT_HIF_TEST_MSG_NUM_INTS + \
    HTT_HIF_TEST_MSG_NUM_CHARS)
#define HTT_HIF_TEST_MSG_ALLOC_BYTES \
    (HTT_HIF_TEST_MSG_BYTES + HTT_HTC_HDR_SIZE)
#define HTT_HIF_TEST_MSG_ALLOC_WORDS \
    ((HTT_HIF_TEST_MSG_ALLOC_BYTES + 3) >> 2)
    static A_UINT32 msg_buf[HTT_HIF_TEST_MSG_ALLOC_WORDS];
    A_UINT32 nums[HTT_HIF_TEST_MSG_NUM_INTS] = {42, 43, 44};
    A_UINT32 *msg_ptr;
    A_UINT32 *num_ptr;
    A_UINT8 text[HTT_HIF_TEST_MSG_NUM_CHARS] = "Hi earth!";
    A_UINT8 *text_ptr;
    int i;

    msg_ptr = (A_UINT32 *) (((char *) msg_buf) + HTT_HTC_HDR_SIZE);

    HTT_T2H_MSG_TYPE_SET(*msg_ptr, HTT_T2H_MSG_TYPE_TEST);
    HTT_RX_TEST_NUM_INTS_SET(*msg_ptr, HTT_HIF_TEST_MSG_NUM_INTS);
    HTT_RX_TEST_NUM_CHARS_SET(*msg_ptr, HTT_HIF_TEST_MSG_NUM_CHARS);

    num_ptr = (A_UINT32 *) (((char *) msg_ptr) + 4);
    for (i = 0; i < HTT_HIF_TEST_MSG_NUM_INTS; i++, num_ptr++) {
        *num_ptr = nums[i];
    }

    text_ptr = ((A_UINT8 *) msg_ptr) + 4 * (1 + HTT_HIF_TEST_MSG_NUM_INTS);
    for (i = 0; i < HTT_HIF_TEST_MSG_NUM_CHARS; i++, text_ptr++) {
        *text_ptr = text[i];
    }

    htt_tgt_hif_svc_cb_set(
        HTT_T2H_MSG_TYPE_TEST, htt_tgt_hif_svc_test_msg_buf_free_dummy);
    htt_tgt_hif_svc_msg_to_host(
        (HTC_BUFFER *) msg_buf, (char *) msg_ptr, HTT_HIF_TEST_MSG_BYTES);
}
#endif /* HTT_TGT_MSG_TEST */
