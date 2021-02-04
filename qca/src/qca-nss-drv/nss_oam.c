/*
 **************************************************************************
 * Copyright (c) 2016-2017 The Linux Foundation. All rights reserved.
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
 * nss_oam.c
 *	OAM - Operations, Administration and Maintenance Service for NSS
 *
 * This adapter module is responsible for sending and
 * receiving to and from NSS FW
 * This file contains the API for communicating NSS FW to send/receive
 * commands OAM commands.
 */

#include "nss_tx_rx_common.h"

/*
 * nss_oam_rx_msg_handler()
 *	Message handler for OAM messages from NSS
 */
static void nss_oam_rx_msg_handler(struct nss_ctx_instance *nss_ctx, struct nss_cmn_msg *ncm, __attribute__((unused)) void *app_data)
{
	struct nss_oam_msg *nom = (struct nss_oam_msg *)ncm;
	nss_oam_msg_callback_t cb;

	/*
	 * Sanity check the message type
	 */
	if (nss_cmn_get_msg_len(ncm) > sizeof(struct nss_oam_msg)) {
		nss_warning("%p: recevied with invalid msg size: %d", nss_ctx, nss_cmn_get_msg_len(ncm));
		return;
	}

	if (ncm->type > NSS_OAM_MSG_TYPE_MAX) {
		nss_warning("%p: received with invalid resp type: %d", nss_ctx, ncm->type);
		return;
	}

	/*
	 * Log the failures
	 */
	nss_core_log_msg_failures(nss_ctx, ncm);

	if (ncm->response == NSS_CMM_RESPONSE_NOTIFY) {
		ncm->cb = (nss_ptr_t)nss_top_main.oam_callback;
		ncm->app_data = (nss_ptr_t)nss_top_main.oam_ctx;
	}

	cb = (nss_oam_msg_callback_t)ncm->cb;
	if (unlikely(!cb)) {
		nss_trace("%p: rx handler has been unregistered for i/f: %d", nss_ctx, ncm->interface);
		return;
	}
	cb((void *)ncm->app_data, nom);
}

/*
 * nss_oam_tx()
 *	Transmit an oam message to the FW.
 */
nss_tx_status_t nss_oam_tx_msg(struct nss_ctx_instance *nss_ctx, struct nss_oam_msg *nom)
{
	const uint32_t msg_sz = sizeof(struct nss_oam_msg);
	struct nss_cmn_msg *ncm = &nom->cm;
	struct sk_buff *nbuf;
	int32_t status;

	NSS_VERIFY_CTX_MAGIC(nss_ctx);
	if (unlikely(nss_ctx->state != NSS_CORE_STATE_INITIALIZED)) {
		nss_warning("%p: oam msg dropped as core not ready", nss_ctx);
		return NSS_TX_FAILURE_NOT_READY;
	}

	if (ncm->type > NSS_OAM_MSG_TYPE_MAX) {
		nss_warning("%p: CMD type for oam module is invalid - %d", nss_ctx, ncm->type);
		return NSS_TX_FAILURE_BAD_PARAM;
	}

	if (ncm->interface != NSS_OAM_INTERFACE) {
		nss_warning("%p: tx message request for another interface: %d", nss_ctx, ncm->interface);
		return NSS_TX_FAILURE;
	}

	if (nss_cmn_get_msg_len(ncm) > msg_sz) {
		nss_warning("%p: tx request with invalid size: %d", nss_ctx, nss_cmn_get_msg_len(ncm));
		return NSS_TX_FAILURE_TOO_SHORT;
	}

	/*
	 * Check whether msg_sz exceeds max payload size
	 */
	BUG_ON(msg_sz > NSS_NBUF_PAYLOAD_SIZE);

	nbuf = dev_alloc_skb(NSS_NBUF_PAYLOAD_SIZE);
	if (unlikely(!nbuf)) {
		NSS_PKT_STATS_INCREMENT(nss_ctx, &nss_ctx->nss_top->stats_drv[NSS_STATS_DRV_NBUF_ALLOC_FAILS]);
		nss_warning("%p: msg dropped as command allocation failed", nss_ctx);
		return NSS_TX_FAILURE;
	}

	/*
	 * Copy the message to our skb.
	 */
	memcpy(skb_put(nbuf, msg_sz), nom, msg_sz);

	status = nss_core_send_buffer(nss_ctx, 0, nbuf, NSS_IF_CMD_QUEUE, H2N_BUFFER_CTRL, 0);
	if (status != NSS_CORE_STATUS_SUCCESS) {
		dev_kfree_skb_any(nbuf);
		nss_warning("%p: unable to enqueue OAM msg\n", nss_ctx);
		return NSS_TX_FAILURE;
	}

	nss_hal_send_interrupt(nss_ctx, NSS_H2N_INTR_DATA_COMMAND_QUEUE);
	NSS_PKT_STATS_INCREMENT(nss_ctx, &nss_ctx->nss_top->stats_drv[NSS_STATS_DRV_TX_CMD_REQ]);
	return NSS_TX_SUCCESS;
}
EXPORT_SYMBOL(nss_oam_tx_msg);

/*
 * nss_oam_notify_register()
 *	Register to receive OAM events.
 */
struct nss_ctx_instance *nss_oam_notify_register(nss_oam_msg_callback_t cb, void *app_data)
{
	if (nss_top_main.oam_ctx || nss_top_main.oam_callback) {
		nss_warning("Failed to register notify callback - already registered\n");
		return NULL;
	}

	nss_top_main.oam_ctx = app_data;
	nss_top_main.oam_callback = cb;
	return &nss_top_main.nss[nss_top_main.oam_handler_id];
}
EXPORT_SYMBOL(nss_oam_notify_register);

/*
 * nss_oam_notify_unregister()
 *	Unregister to received OAM events.
 */
void nss_oam_notify_unregister(void)
{
	nss_top_main.oam_callback = NULL;
	nss_top_main.oam_ctx = NULL;
}
EXPORT_SYMBOL(nss_oam_notify_unregister);

/*
 * nss_register_oam_handler()
 *	Register our handler to receive messages for this interface
 */
void nss_oam_register_handler(void)
{
	struct nss_ctx_instance *nss_ctx = &nss_top_main.nss[nss_top_main.oam_handler_id];

	if (nss_core_register_handler(nss_ctx, NSS_OAM_INTERFACE, nss_oam_rx_msg_handler, NULL) != NSS_CORE_STATUS_SUCCESS) {
		nss_warning("OAM handler failed to register");
	}
}
