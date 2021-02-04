/*
 **************************************************************************
 * Copyright (c) 2018, The Linux Foundation. All rights reserved.
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
 * nss_c2c_tx.c
 *	NSS C2C_TX APIs
 */

#include "nss_tx_rx_common.h"
#include "nss_c2c_tx_stats.h"

/*
 * Notify data structure
 */
struct nss_c2c_tx_notify_data {
	nss_c2c_tx_msg_callback_t c2c_tx_callback;
	void *app_data;
};

static struct nss_c2c_tx_notify_data nss_c2c_tx_notify[NSS_CORE_MAX];

/*
 * nss_c2c_tx_verify_if_num()
 *	Verify if_num passed to us.
 */
static inline bool nss_c2c_tx_verify_if_num(uint32_t if_num)
{
	return if_num == NSS_C2C_TX_INTERFACE;
}

/*
 * nss_c2c_tx_interface_handler()
 *	Handle NSS -> HLOS messages for C2C_TX Statistics
 */
static void nss_c2c_tx_msg_handler(struct nss_ctx_instance *nss_ctx,
		struct nss_cmn_msg *ncm, __attribute__((unused))void *app_data)
{
	struct nss_c2c_tx_msg *nctm = (struct nss_c2c_tx_msg *)ncm;
	nss_c2c_tx_msg_callback_t cb;

	if (!nss_c2c_tx_verify_if_num(ncm->interface)) {
		nss_warning("%p: invalid interface %d for c2c_tx\n", nss_ctx, ncm->interface);
		return;
	}

	/*
	 * Is this a valid request/response packet?
	 */
	if (ncm->type >= NSS_C2C_TX_MSG_TYPE_MAX) {
		nss_warning("%p: received invalid message %d for c2c_tx", nss_ctx, ncm->type);
		return;
	}

	if (nss_cmn_get_msg_len(ncm) > sizeof(struct nss_c2c_tx_msg)) {
		nss_warning("%p: Length of message is greater than required: %d", nss_ctx, nss_cmn_get_msg_len(ncm));
		return;
	}

	/*
	 * Log failures
	 */
	nss_core_log_msg_failures(nss_ctx, ncm);

	switch (nctm->cm.type) {
	case NSS_C2C_TX_MSG_TYPE_TX_MAP:
		nss_info("%p: NSS c2c_tx tx_map configuration received:\n", nss_ctx);
		break;

	case NSS_C2C_TX_MSG_TYPE_STATS:
		nss_c2c_tx_stats_sync(nss_ctx, &nctm->msg.stats);
		break;
	}

	/*
	 * Update the callback and app_data for NOTIFY messages
	 */
	if (ncm->response == NSS_CMM_RESPONSE_NOTIFY) {
		ncm->cb = (nss_ptr_t)nss_c2c_tx_notify[nss_ctx->id].c2c_tx_callback;
		ncm->app_data = (nss_ptr_t)nss_c2c_tx_notify[nss_ctx->id].app_data;
	}

	/*
	 * Do we have a callback?
	 */
	if (!ncm->cb) {
		return;
	}

	/*
	 * callback
	 */
	cb = (nss_c2c_tx_msg_callback_t)ncm->cb;
	cb((void *)ncm->app_data, nctm);
}

/*
 * nss_c2c_tx_register_handler()
 *	Register handler for messaging
 */
void nss_c2c_tx_register_handler(struct nss_ctx_instance *nss_ctx)
{
	nss_info("%p: nss_c2c_tx_register_handler", nss_ctx);
	nss_core_register_handler(nss_ctx, NSS_C2C_TX_INTERFACE, nss_c2c_tx_msg_handler, NULL);
	nss_c2c_tx_stats_dentry_create();
}
EXPORT_SYMBOL(nss_c2c_tx_register_handler);

/*
 * nss_c2c_tx_tx_msg()
 *	Transmit an c2c_tx message to the FW with a specified size.
 */
nss_tx_status_t nss_c2c_tx_tx_msg(struct nss_ctx_instance *nss_ctx, struct nss_c2c_tx_msg *nctm)
{
	struct nss_cmn_msg *ncm = &nctm->cm;
	struct sk_buff *nbuf;
	int32_t status;

	NSS_VERIFY_CTX_MAGIC(nss_ctx);
	if (unlikely(nss_ctx->state != NSS_CORE_STATE_INITIALIZED)) {
		nss_warning("%p: c2c_tx msg dropped as core not ready", nss_ctx);
		return NSS_TX_FAILURE_NOT_READY;
	}

	/*
	 * Sanity check the message
	 */
	if (!nss_c2c_tx_verify_if_num(ncm->interface)) {
		nss_warning("%p: tx request for another interface: %d", nss_ctx, ncm->interface);
		return NSS_TX_FAILURE;
	}

	if (ncm->type >= NSS_C2C_TX_MSG_TYPE_MAX) {
		nss_warning("%p: message type out of range: %d", nss_ctx, ncm->type);
		return NSS_TX_FAILURE;
	}

	if (nss_cmn_get_msg_len(ncm) > sizeof(struct nss_c2c_tx_msg)) {
		nss_warning("%p: message length is invalid: %d", nss_ctx, nss_cmn_get_msg_len(ncm));
		return NSS_TX_FAILURE;
	}

	nbuf = dev_alloc_skb(NSS_NBUF_PAYLOAD_SIZE);
	if (unlikely(!nbuf)) {
		NSS_PKT_STATS_INCREMENT(nss_ctx, &nss_ctx->nss_top->stats_drv[NSS_STATS_DRV_NBUF_ALLOC_FAILS]);
		nss_warning("%p: msg dropped as command allocation failed", nss_ctx);
		return NSS_TX_FAILURE;
	}

	/*
	 * Copy the message to our skb.
	 */
	memcpy(skb_put(nbuf, sizeof(*nctm)), nctm, sizeof(*nctm));

	status = nss_core_send_buffer(nss_ctx, 0, nbuf, NSS_IF_CMD_QUEUE, H2N_BUFFER_CTRL, 0);
	if (status != NSS_CORE_STATUS_SUCCESS) {
		dev_kfree_skb_any(nbuf);
		nss_warning("%p: unable to enqueue c2c_tx msg\n", nss_ctx);
		return NSS_TX_FAILURE;
	}

	nss_hal_send_interrupt(nss_ctx, NSS_H2N_INTR_DATA_COMMAND_QUEUE);

	NSS_PKT_STATS_INCREMENT(nss_ctx, &nss_ctx->nss_top->stats_drv[NSS_STATS_DRV_TX_CMD_REQ]);
	return NSS_TX_SUCCESS;
}
EXPORT_SYMBOL(nss_c2c_tx_tx_msg);

/*
 * nss_c2c_tx_msg_cfg_map_callback()
 *	Callback function for tx_map configuration
 */
static void nss_c2c_tx_msg_cfg_map_callback(void *app_data, struct nss_c2c_tx_msg *nctm)
{
	struct nss_ctx_instance *nss_ctx __attribute__((unused)) = (struct nss_ctx_instance *)app_data;
	if (nctm->cm.response != NSS_CMN_RESPONSE_ACK) {
		nss_warning("%p: nss c2c_tx_map configuration failed: %d for NSS core %d\n",
			nss_ctx, nctm->cm.error, nss_ctx->id);
	}

	nss_info("%p: nss c2c_tx_map configuration succeeded for NSS core %d\n",
		nss_ctx, nss_ctx->id);

}

/*
 * nss_c2c_tx_msg_cfg_map()
 *	Send NSS to c2c_map
 */
nss_tx_status_t nss_c2c_tx_msg_cfg_map(struct nss_ctx_instance *nss_ctx, uint32_t tx_map, uint32_t c2c_intr_addr)
{
	int32_t status;
	struct nss_c2c_tx_msg nctm;
	struct nss_c2c_tx_map *cfg_map;

	nss_info("%p: C2C map:%x\n", nss_ctx, tx_map);
	nss_c2c_tx_msg_init(&nctm, NSS_C2C_TX_INTERFACE, NSS_C2C_TX_MSG_TYPE_TX_MAP,
		sizeof(struct nss_c2c_tx_map), nss_c2c_tx_msg_cfg_map_callback, (void *)nss_ctx);

	cfg_map = &nctm.msg.map;
	cfg_map->tx_map = tx_map;
	cfg_map->c2c_intr_addr = c2c_intr_addr;

	status = nss_c2c_tx_tx_msg(nss_ctx, &nctm);
	if (unlikely(status != NSS_TX_SUCCESS)) {
		return status;
	}

	return NSS_TX_SUCCESS;
}

/*
 * nss_c2c_tx_msg_init()
 *	Initialize C2C_TX message.
 */
void nss_c2c_tx_msg_init(struct nss_c2c_tx_msg *nctm, uint16_t if_num, uint32_t type, uint32_t len,
			nss_c2c_tx_msg_callback_t cb, void *app_data)
{
	nss_cmn_msg_init(&nctm->cm, if_num, type, len, (void *)cb, app_data);
}
EXPORT_SYMBOL(nss_c2c_tx_msg_init);

/*
 * nss_c2c_tx_notify_register()
 *	Register to receive c2c_tx notify messages.
 */
struct nss_ctx_instance *nss_c2c_tx_notify_register(int core, nss_c2c_tx_msg_callback_t cb, void *app_data)
{
	if (core >= NSS_CORE_MAX) {
		nss_warning("Input core number %d is wrong\n", core);
		return NULL;
	}

	nss_c2c_tx_notify[core].c2c_tx_callback = cb;
	nss_c2c_tx_notify[core].app_data = app_data;

	return (struct nss_ctx_instance *)&nss_top_main.nss[core];
}
EXPORT_SYMBOL(nss_c2c_tx_notify_register);

/*
 * nss_c2c_tx_notify_unregister()
 *	Unregister to receive c2c_tx notify messages.
 */
void nss_c2c_tx_notify_unregister(int core)
{
	if (core >= NSS_CORE_MAX) {
		nss_warning("Input core number %d is wrong\n", core);
		return;
	}

	nss_c2c_tx_notify[core].c2c_tx_callback = NULL;
	nss_c2c_tx_notify[core].app_data = NULL;
}
EXPORT_SYMBOL(nss_c2c_tx_notify_unregister);

/*
 * nss_c2c_tx_init()
 */
void nss_c2c_tx_init(void)
{
	int core;

	for (core = 0; core < NSS_CORE_MAX; core++) {
		nss_c2c_tx_notify_register(core, NULL, NULL);
	}
}
