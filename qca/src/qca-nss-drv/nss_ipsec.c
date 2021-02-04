/*
 **************************************************************************
 * Copyright (c) 2013-2017, The Linux Foundation. All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 **************************************************************************
 */

/*
 * nss_ipsec.c
 *	NSS IPsec APIs
 */

#include "nss_tx_rx_common.h"
#include "nss_ipsec.h"

#if defined(NSS_HAL_IPQ806X_SUPPORT)
#define NSS_IPSEC_ENCAP_INTERFACE_NUM NSS_IPSEC_ENCAP_IF_NUMBER
#define NSS_IPSEC_DECAP_INTERFACE_NUM NSS_IPSEC_DECAP_IF_NUMBER
#define NSS_IPSEC_DATA_INTERFACE_NUM NSS_C2C_TX_INTERFACE

#elif defined(NSS_HAL_FSM9010_SUPPORT)
#define NSS_IPSEC_ENCAP_INTERFACE_NUM NSS_IPSEC_ENCAP_IF_NUMBER
#define NSS_IPSEC_DECAP_INTERFACE_NUM NSS_IPSEC_DECAP_IF_NUMBER
#define NSS_IPSEC_DATA_INTERFACE_NUM NSS_IPSEC_RULE_INTERFACE

#elif defined(NSS_HAL_IPQ807x_SUPPORT)
#define NSS_IPSEC_ENCAP_INTERFACE_NUM NSS_IPSEC_RULE_INTERFACE
#define NSS_IPSEC_DECAP_INTERFACE_NUM NSS_IPSEC_RULE_INTERFACE
#define NSS_IPSEC_DATA_INTERFACE_NUM NSS_IPSEC_RULE_INTERFACE

#else
#define NSS_IPSEC_ENCAP_INTERFACE_NUM -1
#define NSS_IPSEC_DECAP_INTERFACE_NUM -1
#define NSS_IPSEC_DATA_INTERFACE_NUM -1

#endif

/*
 * nss_ipsec_get_msg_ctx()
 * 	return ipsec message context assoicated with the callback
 *
 * Note: certain SOC the decap interface specially programmed
 */
static inline nss_ptr_t nss_ipsec_get_msg_ctx(struct nss_ctx_instance *nss_ctx, uint32_t interface_num)
{
	struct nss_top_instance *nss_top = nss_ctx->nss_top;

	/*
	 * the encap is primary interface
	 */
	if (interface_num == NSS_IPSEC_ENCAP_INTERFACE_NUM)
		return (nss_ptr_t)nss_top->ipsec_encap_ctx;

	return (nss_ptr_t)nss_top->ipsec_decap_ctx;
}

/*
 * nss_ipsec_get_msg_callback()
 * 	this gets the message callback handler
 */
static inline nss_ptr_t nss_ipsec_get_msg_callback(struct nss_ctx_instance *nss_ctx, uint32_t interface_num)
{
	struct nss_top_instance *nss_top = nss_ctx->nss_top;

	/*
	 * the encap is primary interface
	 */
	if (interface_num == NSS_IPSEC_ENCAP_INTERFACE_NUM)
		return (nss_ptr_t)nss_top->ipsec_encap_callback;

	return (nss_ptr_t)nss_top->ipsec_decap_callback;
}

/*
 **********************************
 Rx APIs
 **********************************
 */

/*
 * nss_ipsec_msg_handler()
 * 	this handles all the IPsec events and responses
 */
static void nss_ipsec_msg_handler(struct nss_ctx_instance *nss_ctx, struct nss_cmn_msg *ncm, void *app_data __attribute((unused)))
{
	struct nss_ipsec_msg *nim = (struct nss_ipsec_msg *)ncm;
	nss_ipsec_msg_callback_t cb = NULL;
	uint32_t if_num = ncm->interface;

	/*
	 * Sanity check the message type
	 */
	if (ncm->type > NSS_IPSEC_MSG_TYPE_MAX) {
		nss_warning("%p: rx message type out of range: %d", nss_ctx, ncm->type);
		return;
	}

	if (nss_cmn_get_msg_len(ncm) > sizeof(struct nss_ipsec_msg)) {
		nss_warning("%p: rx message length is invalid: %d", nss_ctx, nss_cmn_get_msg_len(ncm));
		return;
	}

	BUG_ON((if_num != NSS_IPSEC_ENCAP_INTERFACE_NUM) && (if_num != NSS_IPSEC_DECAP_INTERFACE_NUM));

	if (ncm->response == NSS_CMN_RESPONSE_LAST) {
		nss_warning("%p: rx message response for if %d, type %d, is invalid: %d", nss_ctx, ncm->interface,
				ncm->type, ncm->response);
		return;
	}

	/*
	 * Is this a notification? if, yes then fill up the callback and app_data from
	 * locally stored state
	 */
	if (ncm->response == NSS_CMM_RESPONSE_NOTIFY) {
		ncm->cb = nss_ipsec_get_msg_callback(nss_ctx, if_num);
		ncm->app_data = nss_ipsec_get_msg_ctx(nss_ctx, if_num);
	}

	nss_core_log_msg_failures(nss_ctx, ncm);

	/*
	 * load, test & call
	 */
	cb = (nss_ipsec_msg_callback_t)ncm->cb;
	if (unlikely(!cb)) {
		nss_trace("%p: rx handler has been unregistered for i/f: %d", nss_ctx, ncm->interface);
		return;
	}

	cb((void *)ncm->app_data, nim);
}

/*
 **********************************
 Tx APIs
 **********************************
 */

/*
 * nss_ipsec_tx_msg
 *	Send ipsec rule to NSS.
 */
nss_tx_status_t nss_ipsec_tx_msg(struct nss_ctx_instance *nss_ctx, struct nss_ipsec_msg *msg)
{
	struct nss_cmn_msg *ncm = &msg->cm;
	struct nss_ipsec_msg *nim;
	struct sk_buff *nbuf;
	int32_t status;

	nss_info("%p: message %d for if %d\n", nss_ctx, ncm->type, ncm->interface);

	NSS_VERIFY_CTX_MAGIC(nss_ctx);

	if (unlikely(nss_ctx->state != NSS_CORE_STATE_INITIALIZED)) {
		nss_warning("%p: tx message dropped as core not ready", nss_ctx);
		return NSS_TX_FAILURE_NOT_READY;
	}

	BUILD_BUG_ON(NSS_NBUF_PAYLOAD_SIZE < sizeof(struct nss_ipsec_msg));

	if ((ncm->interface != NSS_IPSEC_ENCAP_INTERFACE_NUM) && (ncm->interface != NSS_IPSEC_DECAP_INTERFACE_NUM)) {
		nss_warning("%p: tx message request for another interface: %d", nss_ctx, ncm->interface);
		return NSS_TX_FAILURE;
	}

	if (ncm->type > NSS_IPSEC_MSG_TYPE_MAX) {
		nss_warning("%p: tx message type out of range: %d", nss_ctx, ncm->type);
		return NSS_TX_FAILURE;
	}

	if (nss_cmn_get_msg_len(ncm) > sizeof(struct nss_ipsec_msg)) {
		nss_warning("%p: tx message request len for if %d, is bad: %d", nss_ctx, ncm->interface, nss_cmn_get_msg_len(ncm));
		return NSS_TX_FAILURE_BAD_PARAM;
	}

	nbuf = dev_alloc_skb(NSS_NBUF_PAYLOAD_SIZE);
	if (unlikely(!nbuf)) {
		NSS_PKT_STATS_INCREMENT(nss_ctx, &nss_ctx->nss_top->stats_drv[NSS_STATS_DRV_NBUF_ALLOC_FAILS]);
		nss_warning("%p: tx rule dropped as command allocation failed", nss_ctx);
		return NSS_TX_FAILURE;
	}

	nss_info("msg params version:%d, interface:%d, type:%d, cb:%p, app_data:%p, len:%d\n",
			ncm->version, ncm->interface, ncm->type, (void *)ncm->cb, (void *)ncm->app_data, ncm->len);

	nim = (struct nss_ipsec_msg *)skb_put(nbuf, sizeof(struct nss_ipsec_msg));
	memcpy(nim, msg, sizeof(struct nss_ipsec_msg));

	status = nss_core_send_buffer(nss_ctx, 0, nbuf, NSS_IF_CMD_QUEUE, H2N_BUFFER_CTRL, 0);
	if (status != NSS_CORE_STATUS_SUCCESS) {
		dev_kfree_skb_any(nbuf);
		nss_warning("%p: tx Unable to enqueue message \n", nss_ctx);
		return NSS_TX_FAILURE;
	}

	nss_hal_send_interrupt(nss_ctx, NSS_H2N_INTR_DATA_COMMAND_QUEUE);

	return NSS_TX_SUCCESS;
}
EXPORT_SYMBOL(nss_ipsec_tx_msg);

/*
 * nss_ipsec_tx_buf
 * 	Send data packet for ipsec processing
 */
nss_tx_status_t nss_ipsec_tx_buf(struct sk_buff *skb, uint32_t if_num)
{
	struct nss_ctx_instance *nss_ctx = &nss_top_main.nss[nss_top_main.ipsec_handler_id];
	int32_t status;

	nss_trace("%p: IPsec If Tx packet, id:%d, data=%p", nss_ctx, if_num, skb->data);

	NSS_VERIFY_CTX_MAGIC(nss_ctx);
	if (unlikely(nss_ctx->state != NSS_CORE_STATE_INITIALIZED)) {
		nss_warning("%p: 'IPsec If Tx' packet dropped as core not ready", nss_ctx);
		return NSS_TX_FAILURE_NOT_READY;
	}

	status = nss_core_send_buffer(nss_ctx, if_num, skb, NSS_IF_DATA_QUEUE_0, H2N_BUFFER_PACKET, 0);
	if (unlikely(status != NSS_CORE_STATUS_SUCCESS)) {
		nss_warning("%p: Unable to enqueue 'IPsec If Tx' packet\n", nss_ctx);
		if (status == NSS_CORE_STATUS_FAILURE_QUEUE) {
			return NSS_TX_FAILURE_QUEUE;
		}

		return NSS_TX_FAILURE;
	}

	/*
	 * Kick the NSS awake so it can process our new entry.
	 */
	nss_hal_send_interrupt(nss_ctx, NSS_H2N_INTR_DATA_COMMAND_QUEUE);
	NSS_PKT_STATS_INCREMENT(nss_ctx, &nss_ctx->nss_top->stats_drv[NSS_STATS_DRV_TX_PACKET]);
	return NSS_TX_SUCCESS;
}
EXPORT_SYMBOL(nss_ipsec_tx_buf);

/*
 **********************************
 Register APIs
 **********************************
 */

/*
 * nss_ipsec_notify_register()
 * 	register message notifier for the given interface (if_num)
 */
struct nss_ctx_instance *nss_ipsec_notify_register(uint32_t if_num, nss_ipsec_msg_callback_t cb, void *app_data)
{
	struct nss_top_instance *nss_top = &nss_top_main;
	uint8_t core_id = nss_top->ipsec_handler_id;
	struct nss_ctx_instance *nss_ctx = &nss_top->nss[core_id];

	if (if_num >= NSS_MAX_NET_INTERFACES) {
		nss_warning("%p: notfiy register received for invalid interface %d", nss_ctx, if_num);
		return NULL;
	}

	/*
	 * the encap is primary interface
	 */
	if (if_num == NSS_IPSEC_ENCAP_INTERFACE_NUM) {
		nss_top->ipsec_encap_callback = cb;
		nss_top->ipsec_encap_ctx = app_data;
		return nss_ctx;
	}

	nss_top->ipsec_decap_callback = cb;
	nss_top->ipsec_decap_ctx = app_data;
	return nss_ctx;
}
EXPORT_SYMBOL(nss_ipsec_notify_register);

/*
 * nss_ipsec_notify_unregister()
 * 	unregister the IPsec notifier for the given interface number (if_num)
 */
void nss_ipsec_notify_unregister(struct nss_ctx_instance *nss_ctx, uint32_t if_num)
{
	struct nss_top_instance *nss_top = nss_ctx->nss_top;

	if (if_num >= NSS_MAX_NET_INTERFACES) {
		nss_warning("%p: notify unregister received for invalid interface %d", nss_ctx, if_num);
		return;
	}

	/*
	 * the encap is primary interface
	 */
	if (if_num == NSS_IPSEC_ENCAP_INTERFACE_NUM) {
		nss_top->ipsec_encap_callback = NULL;
		nss_top->ipsec_encap_ctx = NULL;
		return;
	}

	nss_top->ipsec_decap_callback = NULL;
	nss_top->ipsec_decap_ctx = NULL;
}
EXPORT_SYMBOL(nss_ipsec_notify_unregister);

/*
 * nss_ipsec_data_register()
 * 	register a data callback routine
 */
struct nss_ctx_instance *nss_ipsec_data_register(uint32_t if_num, nss_ipsec_buf_callback_t cb, struct net_device *netdev, uint32_t features)
{
	struct nss_ctx_instance *nss_ctx, *nss_ctx0;

	nss_ctx = &nss_top_main.nss[nss_top_main.ipsec_handler_id];

	if ((if_num >= NSS_MAX_NET_INTERFACES) && (if_num < NSS_MAX_PHYSICAL_INTERFACES)){
		nss_warning("%p: data register received for invalid interface %d", nss_ctx, if_num);
		return NULL;
	}

	/*
	 * avoid multiple registeration for multiple tunnels
	 */
	if (nss_ctx->subsys_dp_register[if_num].cb) {
		return nss_ctx;
	}

	nss_core_register_subsys_dp(nss_ctx, if_num, cb, NULL, NULL, netdev, features);

	if (nss_top_main.ipsec_handler_id == 1) {
		nss_ctx0 = &nss_top_main.nss[0];

		nss_core_register_subsys_dp(nss_ctx0, if_num, cb, NULL, NULL, netdev, features);
	}

	return nss_ctx;
}
EXPORT_SYMBOL(nss_ipsec_data_register);

/*
 * nss_ipsec_data_unregister()
 * 	unregister a data callback routine
 */
void nss_ipsec_data_unregister(struct nss_ctx_instance *nss_ctx, uint32_t if_num)
{
	struct nss_ctx_instance *nss_ctx0;

	if ((if_num >= NSS_MAX_NET_INTERFACES) && (if_num < NSS_MAX_PHYSICAL_INTERFACES)){
		nss_warning("%p: data unregister received for invalid interface %d", nss_ctx, if_num);
		return;
	}

	if (nss_top_main.ipsec_handler_id == 1) {
		nss_ctx0 = &nss_top_main.nss[0];

		nss_core_unregister_subsys_dp(nss_ctx0, if_num);
	}

	nss_core_unregister_subsys_dp(nss_ctx, if_num);
}
EXPORT_SYMBOL(nss_ipsec_data_unregister);

/*
 * nss_ipsec_get_encap_interface()
 * 	Get the NSS interface number for encap message
 */
int32_t nss_ipsec_get_encap_interface(void)
{
	return NSS_IPSEC_ENCAP_INTERFACE_NUM;
}
EXPORT_SYMBOL(nss_ipsec_get_encap_interface);

/*
 * nss_ipsec_get_decap_interface()
 * 	Get the NSS interface number for decap message
 */
int32_t nss_ipsec_get_decap_interface(void)
{
	return NSS_IPSEC_DECAP_INTERFACE_NUM;
}
EXPORT_SYMBOL(nss_ipsec_get_decap_interface);

/*
 * nss_ipsec_get_data_interface()
 * 	Get the NSS interface number used for data path
 */
int32_t nss_ipsec_get_data_interface(void)
{
	return NSS_IPSEC_DATA_INTERFACE_NUM;
}
EXPORT_SYMBOL(nss_ipsec_get_data_interface);

/*
 * nss_ipsec_get_context()
 * 	get NSS context instance for IPsec handle
 */
struct nss_ctx_instance *nss_ipsec_get_context(void)
{
	return &nss_top_main.nss[nss_top_main.ipsec_handler_id];
}
EXPORT_SYMBOL(nss_ipsec_get_context);

/*
 * nss_ipsec_register_handler()
 */
void nss_ipsec_register_handler()
{
	struct nss_ctx_instance *nss_ctx = &nss_top_main.nss[nss_top_main.ipsec_handler_id];

	BUILD_BUG_ON(NSS_IPSEC_ENCAP_INTERFACE_NUM < 0);
	BUILD_BUG_ON(NSS_IPSEC_DECAP_INTERFACE_NUM < 0);

	nss_ctx->nss_top->ipsec_encap_callback = NULL;
	nss_ctx->nss_top->ipsec_decap_callback = NULL;

	nss_ctx->nss_top->ipsec_encap_ctx = NULL;
	nss_ctx->nss_top->ipsec_decap_ctx = NULL;

	nss_core_register_handler(nss_ctx, NSS_IPSEC_ENCAP_INTERFACE_NUM, nss_ipsec_msg_handler, NULL);
	nss_core_register_handler(nss_ctx, NSS_IPSEC_DECAP_INTERFACE_NUM, nss_ipsec_msg_handler, NULL);
}

/*
 * nss_ipsec_msg_init()
 *	Initialize ipsec message.
 */
void nss_ipsec_msg_init(struct nss_ipsec_msg *nim, uint16_t if_num, uint32_t type, uint32_t len,
			nss_ipsec_msg_callback_t cb, void *app_data)
{
	nss_cmn_msg_init(&nim->cm, if_num, type, len, (void *)cb, app_data);
}
EXPORT_SYMBOL(nss_ipsec_msg_init);
