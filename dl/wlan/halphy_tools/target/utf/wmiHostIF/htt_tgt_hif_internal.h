#ifndef _HTT_TGT_HIF_INTERNAL_H
#define _HTT_TGT_HIF_INTERNAL_H

#include <osapi.h>          /* A_UINT8 */

/*--------------- htt_tgt_hif internal API ---------------*/

#ifndef DISABLE_FUNCTION_INDIRECTION

typedef struct {

    A_UINT8 (*svc_connect)(HTC_SERVICE *pService,
                           HTC_ENDPOINT_ID endpoint,
                           A_UINT8 *pDataIn,
                           A_INT32 LengthIn,
                           A_UINT8 *pDataOut,
                           A_INT32 *pLengthOut);

    void (*svc_callback)(HTC_ENDPOINT_ID endpoint, HTC_BUFFER *msg_buf);

    void (*svc_h2t_recv_buf_pool_attach)(int buf_sz, int pool_sz);

    void (*svc_h2t_recv_buf_pool_init)(HTC_ENDPOINT_ID EndPt);

    void (*svc_h2t_refill_recv_buf)(HTC_ENDPOINT_ID EndPt, int num); 

    void (*svc_h2t_input)(HTC_ENDPOINT_ID ep, HTC_BUFFER *bufs[], int num);

} HTT_TGT_HIF_INTERNAL_FN;

extern HTT_TGT_HIF_INTERNAL_FN  htt_tgt_hif_internal_indir_tbl;

#define HTT_TGT_HIF_INTERNAL_FN(fn)     htt_tgt_hif_internal_indir_tbl.fn

#else

A_UINT8
_htt_tgt_hif_svc_connect(
    HTC_SERVICE *pService,
    HTC_ENDPOINT_ID endpoint,
    A_UINT8 *pDataIn,
    A_INT32 LengthIn,
    A_UINT8 *pDataOut,
    A_INT32 *pLengthOut);

void
_htt_tgt_hif_svc_callback(HTC_ENDPOINT_ID endpoint, HTC_BUFFER *msg_buf);

/**
 * @brief - attach buffer pool used to receive H2T messages
 *
 * @description attach the receive buffer pool for H2T messages. The attach
 * function will allocate the receive buffers and link them together with
 * HTC header. The HTC header of the 1st receive buffer will be stored in
 * the global H2T structure 
 * (g_htt_tgt_hif_svc_state_ptr->h2t_state.h2t_recv_buf_freelist)
 *
 * @param buf_sz - the size in bytes of each receive buffer
 * @param pool_sz - the number of receive buffers allocated for the pool
 */
void 
_htt_tgt_hif_svc_h2t_recv_buf_pool_attach(int buf_sz, int pool_sz);

/**
 * @brief initialize the receive buffer pool for H2T messages
 *
 * @description initialize the receive buffer pool for H2T messages. The
 * initialization is mostly requeued the buffer to HTC endpoint
 *
 * @param EndPt - endpoint ID to requeued the buffers to
 */
void 
_htt_tgt_hif_svc_h2t_recv_buf_pool_init(HTC_ENDPOINT_ID EndPt);

/**
 * @brief refill the H2T receive buffer to endpoint
 *
 * @description this API requeues the some buffers to endpoint for new
 * incoming H2T message
 *
 * @param EndPt - the endpoint to requeue the buffer to
 * @param num - the number of buffers to requeue
 */
void 
_htt_tgt_hif_svc_h2t_refill_recv_buf(HTC_ENDPOINT_ID EndPt, int num); 

/**
 * @brief entry function to handle H2T messages
 *
 * @description this is the entry function to receive the H2T messages.
 * It will be called by HTC layer when new incoming H2T messages arrived.
 * This function works as a H2T message dispatcher by checking the type
 * of the incoming H2T messages and dispatching the message to registerd
 * callback function.
 * This API handles the HTC padding so that the callbacks do not need to
 * worry about the HTC layer header/padding. It also performs message
 * buffer management.
 *
 * @param bufs - incoming HTC buffers that contain H2T messages
 * @param num - number of incoming HTC buffers
 */
void
_htt_tgt_hif_svc_h2t_input(
    HTC_ENDPOINT_ID ep, HTC_BUFFER *bufs[], int num);

#define HTT_TGT_HIF_INTERNAL_FN(fn)     _htt_tgt_hif_##fn

#endif

#define htt_tgt_hif_svc_connect     HTT_TGT_HIF_INTERNAL_FN(svc_connect)

#define htt_tgt_hif_svc_callback    HTT_TGT_HIF_INTERNAL_FN(svc_callback)

#define htt_tgt_hif_svc_h2t_recv_buf_pool_attach        \
    HTT_TGT_HIF_INTERNAL_FN(svc_h2t_recv_buf_pool_attach)

#define htt_tgt_hif_svc_h2t_recv_buf_pool_init          \
    HTT_TGT_HIF_INTERNAL_FN(svc_h2t_recv_buf_pool_init)

#define htt_tgt_hif_svc_h2t_refill_recv_buf             \
    HTT_TGT_HIF_INTERNAL_FN(svc_h2t_refill_recv_buf)

#define htt_tgt_hif_svc_h2t_input                     \
    HTT_TGT_HIF_INTERNAL_FN(svc_h2t_input)

#endif //_HTT_TGT_HIF_INTERNAL_H

