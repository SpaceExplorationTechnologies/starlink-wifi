/*
 **************************************************************************
 * Copyright (c) 2014-2017, The Linux Foundation. All rights reserved.
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
 * nss_tx_rx_lag.c
 *	NSS LAG Tx APIs
 */

#include <linux/if_bonding.h>

#include "nss_tx_rx_common.h"

#define NSS_LAG_RESP_TIMEOUT 60000	/* 60 Sec */

/*
 * Private data structure of dynamic interface
 */
struct nss_lag_pvt {
	struct completion complete;		/* completion structure */
	enum nss_cmn_response response;		/* Message response */
};

/*
 * nss_lag_state_callback()
 *	Call back function for nss LAG State
 */
void nss_lag_state_callback(void *arg, struct nss_lag_msg *nm)
{
	struct nss_lag_pvt *lag_msg_state = arg;

	/*
	 * Unblock the sleeping function.
	 */
	lag_msg_state->response = nm->cm.response;
	complete(&lag_msg_state->complete);
}

/*
 * nss_lag_verify_ifnum()
 *
 */
static void nss_lag_verify_ifnum(uint32_t if_num)
{
	nss_assert((if_num == NSS_LAG0_INTERFACE_NUM) ||
		   (if_num == NSS_LAG1_INTERFACE_NUM) ||
		   (if_num == NSS_LAG2_INTERFACE_NUM) ||
		   (if_num == NSS_LAG3_INTERFACE_NUM));
}

/*
 * nss_lag_get_context()
 */
static struct nss_ctx_instance *nss_lag_get_context(void)
{
	uint8_t ipv4_handler_id = nss_top_main.ipv4_handler_id;

	return (struct nss_ctx_instance *)&nss_top_main.nss[ipv4_handler_id];
}

/*
 * nss_lag_tx()
 *	Transmit a LAG msg to the firmware.
 */
nss_tx_status_t nss_lag_tx(struct nss_ctx_instance *nss_ctx, struct nss_lag_msg *msg)
{
	struct sk_buff *nbuf;
	int32_t status;
	struct nss_lag_msg *nm;

	nss_info("%p: NSS LAG Tx\n", nss_ctx);

	NSS_VERIFY_CTX_MAGIC(nss_ctx);
	if (unlikely(nss_ctx->state != NSS_CORE_STATE_INITIALIZED)) {
		nss_warning("%p: LAG msg dropped as core not ready", nss_ctx);
		return NSS_TX_FAILURE_NOT_READY;
	}

	nbuf = dev_alloc_skb(NSS_NBUF_PAYLOAD_SIZE);
	if (unlikely(!nbuf)) {
		NSS_PKT_STATS_INCREMENT(nss_ctx, &nss_ctx->nss_top->stats_drv[NSS_STATS_DRV_NBUF_ALLOC_FAILS]);
		nss_warning("%p: LAG msg dropped as command allocation failed", nss_ctx);
		return NSS_TX_FAILURE;
	}

	nm = (struct nss_lag_msg *)skb_put(nbuf, sizeof(struct nss_lag_msg));
	memcpy(nm, msg, sizeof(struct nss_lag_msg));

	status = nss_core_send_buffer(nss_ctx, 0, nbuf, NSS_IF_CMD_QUEUE, H2N_BUFFER_CTRL, 0);
	if (status != NSS_CORE_STATUS_SUCCESS) {
		dev_kfree_skb_any(nbuf);
		nss_warning("%p: Unable to enqueue LAG msg\n", nss_ctx);
		return NSS_TX_FAILURE;
	}
	nss_hal_send_interrupt(nss_ctx, NSS_H2N_INTR_DATA_COMMAND_QUEUE);

	NSS_PKT_STATS_INCREMENT(nss_ctx, &nss_ctx->nss_top->stats_drv[NSS_STATS_DRV_TX_CMD_REQ]);
	return NSS_TX_SUCCESS;
}
EXPORT_SYMBOL(nss_lag_tx);

/**
 * nss_register_lag_if()
 */
void *nss_register_lag_if(uint32_t if_num,
			 nss_lag_callback_t lag_cb,
			 nss_lag_event_callback_t lag_ev_cb,
			 struct net_device *netdev)
{
	struct nss_ctx_instance *nss_ctx = nss_lag_get_context();
	uint32_t features = 0;

	nss_assert(nss_ctx);
	nss_lag_verify_ifnum(if_num);

	nss_core_register_subsys_dp(nss_ctx, if_num, lag_cb, NULL, NULL, netdev, features);

	nss_top_main.lag_event_callback = lag_ev_cb;

	/*
	 * Return the NSS driver context for LAG (same as for ipv4 functions)
	 */
	return (void *)nss_ctx;
}
EXPORT_SYMBOL(nss_register_lag_if);


/**
 * nss_unregister_lag_if()
 */
void nss_unregister_lag_if(uint32_t if_num)
{
	struct nss_ctx_instance *nss_ctx = nss_lag_get_context();

	nss_assert(nss_ctx);
	nss_lag_verify_ifnum(if_num);

	nss_core_unregister_subsys_dp(nss_ctx, if_num);

	nss_top_main.lag_event_callback = NULL;
}
EXPORT_SYMBOL(nss_unregister_lag_if);


/**
 * nss_lag_handler()
 */
void nss_lag_handler(struct nss_ctx_instance *nss_ctx,
		     struct nss_cmn_msg *ncm,
		     void *app_data)
{
	struct nss_lag_msg *lm = (struct nss_lag_msg *)ncm;
	void *ctx = NULL;
	nss_lag_event_callback_t cb;

	BUG_ON(ncm->interface != NSS_LAG0_INTERFACE_NUM
	       && ncm->interface != NSS_LAG1_INTERFACE_NUM
		&& ncm->interface != NSS_LAG2_INTERFACE_NUM
		&& ncm->interface != NSS_LAG3_INTERFACE_NUM);

	if (ncm->type >= NSS_TX_METADATA_LAG_MAX) {
		nss_warning("%p: received invalid message %d for LAG interface", nss_ctx, ncm->type);
		return;
	}

	if (nss_cmn_get_msg_len(ncm) > sizeof(struct nss_lag_msg)) {
		nss_warning("%p: invalid length for LAG message: %d", nss_ctx, nss_cmn_get_msg_len(ncm));
		return;
	}

	/**
	 * Update the callback and app_data for NOTIFY messages.
	 * LAG sends all notify messages to the same callback.
	 */
	if (ncm->response == NSS_CMM_RESPONSE_NOTIFY) {
		ncm->cb = (nss_ptr_t)nss_ctx->nss_top->lag_event_callback;
	}

	/**
	 * Log failures
	 */
	nss_core_log_msg_failures(nss_ctx, ncm);

	/**
	 * Do we have a call back
	 */
	if (!ncm->cb) {
		return;
	}

	/**
	 * callback
	 */
	cb = (nss_lag_event_callback_t)ncm->cb;
	ctx = (void *)ncm->app_data;

	cb(ctx, lm);
}


/**
 * nss_lag_register_handler()
 */
void nss_lag_register_handler(void)
{
	struct nss_ctx_instance *nss_ctx = nss_lag_get_context();

	nss_core_register_handler(nss_ctx, NSS_LAG0_INTERFACE_NUM, nss_lag_handler, NULL);
	nss_core_register_handler(nss_ctx, NSS_LAG1_INTERFACE_NUM, nss_lag_handler, NULL);
	nss_core_register_handler(nss_ctx, NSS_LAG2_INTERFACE_NUM, nss_lag_handler, NULL);
	nss_core_register_handler(nss_ctx, NSS_LAG3_INTERFACE_NUM, nss_lag_handler, NULL);
}

/**
 * nss_lag_msg_init()
 *	Initialize lag message
 */
void nss_lag_msg_init(struct nss_lag_msg *nlm, uint16_t lag_num, uint32_t type, uint32_t len,
		nss_lag_msg_callback_t cb, void *app_data)
{
	nss_cmn_msg_init(&nlm->cm, lag_num, type, len, (void *)cb, app_data);
}
EXPORT_SYMBOL(nss_lag_msg_init);

/**
 * nss_lag_tx_slave_state()
 */
nss_tx_status_t nss_lag_tx_slave_state(uint16_t lagid, int32_t slave_ifnum,
		enum nss_lag_state_change_ev slave_state)
{
	struct nss_lag_msg nm;
	struct nss_lag_state_change *nlsc = NULL;
	nss_tx_status_t status;
	int ret;
	struct nss_ctx_instance *nss_ctx = nss_lag_get_context();
	struct nss_lag_pvt lag_msg_state;

	init_completion(&lag_msg_state.complete);
	lag_msg_state.response = false;

	/*
	 * Construct a message to the NSS to update it
	 */
	nss_lag_msg_init(&nm, lagid,
			 NSS_TX_METADATA_LAG_STATE_CHANGE,
			 sizeof(struct nss_lag_state_change),
			 nss_lag_state_callback, &lag_msg_state);

	nlsc = &nm.msg.state;
	nlsc->event = slave_state;
	nlsc->interface = slave_ifnum;

	status = nss_lag_tx(nss_ctx, &nm);
	if (status != NSS_TX_SUCCESS) {
		nss_warning("%p: Send LAG update failed, status: %d\n", nss_ctx,
				status);
		return NSS_TX_FAILURE;
	}

	/*
	 * Blocking call, wait till we get ACK for this msg.
	 */
	ret = wait_for_completion_timeout(&lag_msg_state.complete,
			msecs_to_jiffies(NSS_LAG_RESP_TIMEOUT));
	if (!ret) {
		nss_warning("%p: Waiting for ack timed out\n", nss_ctx);
		return NSS_TX_FAILURE;
	}

	return lag_msg_state.response;
}
EXPORT_SYMBOL(nss_lag_tx_slave_state);
