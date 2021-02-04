/*
 **************************************************************************
 * Copyright (c) 2013-2016, The Linux Foundation. All rights reserved.
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
 * nss_tx_rx_virt_if.c
 *	NSS virtual/redirect handler APIs
 */

#include "nss_tx_rx_common.h"
#include <net/arp.h>

#define NSS_TX_RX_VIRT_IF_TX_TIMEOUT		3000 /* 3 Seconds */
#define NSS_TX_RX_VIRT_IF_802_3_PKT		0x2
#define NSS_TX_RX_VIRT_IF_NATIVE_WIFI_PKT 	0x3

extern int nss_ctl_redirect;

/*
 * Data structure that holds the virtual interface context.
 */
struct nss_tx_rx_virt_if_handle *nss_tx_rx_virt_if_handles[NSS_MAX_DYNAMIC_INTERFACES];

/*
 * Spinlock to protect the global data structure virt_handle.
 */
DEFINE_SPINLOCK(nss_tx_rx_virt_if_lock);

/*
 * nss_tx_rx_virt_if_msg_handler()
 *	Handle msg responses from the FW on virtual interfaces
 */
static void nss_tx_rx_virt_if_msg_handler(struct nss_ctx_instance *nss_ctx,
					struct nss_cmn_msg *ncm,
					void *app_data)
{
	struct nss_tx_rx_virt_if_msg *nvim = (struct nss_tx_rx_virt_if_msg *)ncm;
	int32_t if_num;

	nss_tx_rx_virt_if_msg_callback_t cb;
	struct nss_tx_rx_virt_if_handle *handle = NULL;

	/*
	 * Sanity check the message type
	 */
	if (ncm->type > NSS_VIRT_IF_MAX_MSG_TYPES) {
		nss_warning("%p: message type out of range: %d", nss_ctx, ncm->type);
		return;
	}

	/*
	 * Messages value that are within the base class are handled by the base class.
	 */
	if (ncm->type < NSS_IF_MAX_MSG_TYPES) {
		return nss_if_msg_handler(nss_ctx, ncm, app_data);
	}

	if (!NSS_IS_IF_TYPE(DYNAMIC, ncm->interface)) {
		nss_warning("%p: response for another interface: %d", nss_ctx, ncm->interface);
		return;
	}

	if_num = NSS_TX_RX_VIRT_IF_GET_INDEX(ncm->interface);

	spin_lock_bh(&nss_tx_rx_virt_if_lock);
	if (!nss_tx_rx_virt_if_handles[if_num]) {
		spin_unlock_bh(&nss_tx_rx_virt_if_lock);
		nss_warning("%p: redir_if handle is NULL\n", nss_ctx);
		return;
	}

	handle = nss_tx_rx_virt_if_handles[if_num];
	spin_unlock_bh(&nss_tx_rx_virt_if_lock);

	switch (nvim->cm.type) {
	case NSS_VIRT_IF_STATS_SYNC_MSG:
		nss_tx_rx_virt_if_stats_sync(handle, &nvim->msg.stats);
		break;
	}

	/*
	 * Log failures
	 */
	nss_core_log_msg_failures(nss_ctx, ncm);

	/*
	 * Update the callback and app_data for NOTIFY messages, IPv4 sends all notify messages
	 * to the same callback/app_data.
	 */
	if (ncm->response == NSS_CMM_RESPONSE_NOTIFY) {
		ncm->cb = (nss_ptr_t)nss_ctx->nss_top->if_rx_msg_callback[ncm->interface];
		ncm->app_data = (nss_ptr_t)nss_ctx->subsys_dp_register[ncm->interface].ndev;
	}

	/*
	 * Do we have a callback?
	 */
	if (!ncm->cb) {
		return;
	}

	/*
	 * Callback
	 */
	cb = (nss_tx_rx_virt_if_msg_callback_t)ncm->cb;
	cb((void *)ncm->app_data, ncm);
}

/*
 * nss_tx_rx_virt_if_callback
 *	Callback to handle the completion of NSS ->HLOS messages.
 */
static void nss_tx_rx_virt_if_callback(void *app_data, struct nss_cmn_msg *ncm)
{
	struct nss_tx_rx_virt_if_handle *handle = (struct nss_tx_rx_virt_if_handle *)app_data;
	struct nss_tx_rx_virt_if_pvt *nvip = handle->pvt;
	int32_t if_num = NSS_TX_RX_VIRT_IF_GET_INDEX(ncm->interface);

	if (!nss_tx_rx_virt_if_handles[if_num]) {
		nss_warning("%p: redir_if Handle does not exist\n", handle->nss_ctx);
		return;
	}

	if (ncm->response != NSS_CMN_RESPONSE_ACK) {
		nss_warning("%p: redir_if Error response %d\n", handle->nss_ctx, ncm->response);
		nvip->response = NSS_TX_FAILURE;
		complete(&nvip->complete);
		return;
	}

	nvip->response = NSS_TX_SUCCESS;
	complete(&nvip->complete);
}

/*
 * nss_register_virt_if()
 */
void *nss_register_virt_if(void *ctx,
				nss_virt_if_rx_callback_t rx_callback,
				struct net_device *netdev)
{
	struct nss_tx_rx_virt_if_handle *handle = (struct nss_tx_rx_virt_if_handle *)ctx;
	struct nss_ctx_instance *nss_ctx;
	int32_t if_num;

	if (!handle) {
		nss_warning("handle is NULL\n");
		return NULL;
	}

	nss_ctx = handle->nss_ctx;
	if_num = handle->if_num;

	nss_core_register_subsys_dp(nss_ctx, if_num, rx_callback, NULL, NULL, netdev, (uint32_t)netdev->features);

	nss_top_main.if_rx_msg_callback[if_num] = NULL;

	return ctx;
}

/*
 * nss_unregister_virt_if()
 */
void nss_unregister_virt_if(void *ctx)
{
	struct nss_tx_rx_virt_if_handle *handle = (struct nss_tx_rx_virt_if_handle *)ctx;
	struct nss_ctx_instance *nss_ctx;
	int32_t if_num;

	if (!handle) {
		nss_warning("handle is NULL\n");
		return;
	}

	nss_ctx = handle->nss_ctx;
	if_num = handle->if_num;

	nss_core_unregister_subsys_dp(nss_ctx, if_num);

	nss_top_main.if_rx_msg_callback[if_num] = NULL;
}

/*
 * nss_tx_virt_if_recvbuf()
 *	HLOS interface has received a packet which we redirect to the NSS, if appropriate to do so.
 */
nss_tx_status_t nss_tx_virt_if_recvbuf(void *ctx, struct sk_buff *skb, uint32_t nwifi)
{
	struct nss_tx_rx_virt_if_handle *handle = (struct nss_tx_rx_virt_if_handle *)ctx;
	int32_t if_num = handle->if_num;
	struct nss_ctx_instance *nss_ctx = handle->nss_ctx;
	nss_tx_status_t status;
	int push_mac_header = 0;

	if (unlikely(nss_ctl_redirect == 0)) {
		return NSS_TX_FAILURE_NOT_ENABLED;
	}

	if (unlikely(skb->vlan_tci)) {
		return NSS_TX_FAILURE_NOT_SUPPORTED;
	}

	nss_assert(NSS_IS_IF_TYPE(DYNAMIC, if_num));
	nss_trace("%p: Virtual Rx packet, if_num:%d, skb:%p", nss_ctx, if_num, skb);

	/*
	 * Get the NSS context that will handle this packet and check that it is initialised and ready
	 */
	NSS_VERIFY_CTX_MAGIC(nss_ctx);
	if (unlikely(nss_ctx->state != NSS_CORE_STATE_INITIALIZED)) {
		nss_warning("%p: Virtual Rx packet dropped as core not ready", nss_ctx);
		return NSS_TX_FAILURE_NOT_READY;
	}

	/*
	 * Sanity check the SKB to ensure that it's suitable for us
	 */
	if (unlikely(skb->len <= ETH_HLEN)) {
		nss_warning("%p: Virtual Rx packet: %p too short", nss_ctx, skb);
		return NSS_TX_FAILURE_TOO_SHORT;
	}

	if (unlikely(skb_shinfo(skb)->nr_frags != 0)) {
		/*
		 * TODO: If we have a connection matching rule for this skbuff,
		 * do we need to flush it??
		 */
		nss_warning("%p: Delivering the packet to Linux because of fragmented skb: %p\n", nss_ctx, skb);
		return NSS_TX_FAILURE_NOT_SUPPORTED;
	}

	/*
	 * We differentiate between skbs with priority to identify native vs non-native wifi pkts
	 */
	if (nwifi) {
		skb->priority = NSS_TX_RX_VIRT_IF_NATIVE_WIFI_PKT;
	} else {
		skb->priority = NSS_TX_RX_VIRT_IF_802_3_PKT;

		/*
		 * NSS expects to see buffer from Ethernet header onwards.
		 * If the wireless driver has called eth_type_trans to remove
		 * the ethernet header, we need to push back the header
		 */
		if (unlikely((skb->data - skb_mac_header(skb)) == ETH_HLEN)) {
			skb_push(skb, ETH_HLEN);
			push_mac_header = 1;
		}
	}

	/*
	 * Direct the buffer to the NSS
	 */
	status = nss_core_send_buffer(nss_ctx, if_num, skb, NSS_IF_DATA_QUEUE_0,
					H2N_BUFFER_PACKET, H2N_BIT_FLAG_VIRTUAL_BUFFER);
	if (unlikely(status != NSS_CORE_STATUS_SUCCESS)) {
		nss_warning("%p: Virtual Rx packet unable to enqueue\n", nss_ctx);

		if (unlikely(push_mac_header)) {
			skb_pull(skb, ETH_HLEN);
		}

		return NSS_TX_FAILURE_QUEUE;
	}

	/*
	 * Kick the NSS awake so it can process our new entry.
	 */
	nss_hal_send_interrupt(nss_ctx, NSS_H2N_INTR_DATA_COMMAND_QUEUE);
	NSS_PKT_STATS_INCREMENT(nss_ctx, &nss_ctx->nss_top->stats_drv[NSS_STATS_DRV_TX_PACKET]);
	return NSS_TX_SUCCESS;
}

/*
 * @brief Forward virtual interface packets
 *	This function expects packet with L3 header and eth_type_trans
 *	has been called before calling this api
 *
 * @param nss_ctx NSS context (provided during registeration)
 * @param os_buf OS buffer (e.g. skbuff)
 * @return nss_tx_status_t Tx status
 */
nss_tx_status_t nss_tx_virt_if_rxbuf(void *ctx, struct sk_buff *os_buf)
{

	return nss_tx_virt_if_recvbuf(ctx, os_buf, 0);
}

/*
 * @brief Forward Native wifi packet from virtual interface
 *	Expects packet with qca-nwifi format
 *
 * @param nss_ctx NSS context (provided during registeration)
 * @param os_buf OS buffer (e.g. skbuff)
 * @return nss_tx_status_t Tx status
 */
nss_tx_status_t nss_tx_virt_if_rx_nwifibuf(void *ctx, struct sk_buff *os_buf)
{

	return nss_tx_virt_if_recvbuf(ctx, os_buf, 1);
}

/*
 * nss_tx_rx_virt_if_msg_init()
 *	Initialize redir specific message structure.
 */
static void nss_tx_rx_virt_if_msg_init(struct nss_tx_rx_virt_if_msg *nrim,
					uint16_t if_num,
					uint32_t type,
					uint32_t len,
					nss_tx_rx_virt_if_msg_callback_t cb,
					struct nss_tx_rx_virt_if_handle *app_data)
{
	nss_cmn_msg_init(&nrim->cm, if_num, type, len, (void *)cb, (void *)app_data);
}

/*
 * nss_tx_rx_virt_if_handle_create_sync()
 *	Initialize redir handle which holds the if_num and stats per interface.
 */
static struct nss_tx_rx_virt_if_handle *nss_tx_rx_virt_if_handle_create(struct nss_ctx_instance *nss_ctx, int32_t if_num, int32_t *cmd_rsp)
{
	int32_t index;
	struct nss_tx_rx_virt_if_handle *handle;

	index = NSS_TX_RX_VIRT_IF_GET_INDEX(if_num);

	handle = (struct nss_tx_rx_virt_if_handle *)kzalloc(sizeof(struct nss_tx_rx_virt_if_handle),
									GFP_KERNEL);
	if (!handle) {
		nss_warning("%p: handle memory alloc failed\n", nss_ctx);
		*cmd_rsp = NSS_TX_RX_VIRT_IF_ALLOC_FAILURE;
		goto error1;
	}

	handle->nss_ctx = nss_ctx;
	handle->if_num = if_num;
	handle->pvt = (struct nss_tx_rx_virt_if_pvt *)kzalloc(sizeof(struct nss_tx_rx_virt_if_pvt),
								GFP_KERNEL);
	if (!handle->pvt) {
		nss_warning("%p: failure allocating memory for nss_tx_rx_virt_if_pvt\n", nss_ctx);
		*cmd_rsp = NSS_TX_RX_VIRT_IF_ALLOC_FAILURE;
		goto error2;
	}

	handle->cb = NULL;
	handle->app_data = NULL;

	spin_lock_bh(&nss_tx_rx_virt_if_lock);
	nss_tx_rx_virt_if_handles[index] = handle;
	spin_unlock_bh(&nss_tx_rx_virt_if_lock);

	*cmd_rsp = NSS_VIRT_IF_SUCCESS;

	return handle;

error2:
	kfree(handle);
error1:
	return NULL;
}

/*
 * nss_tx_rx_virt_if_register_handler_sync()
 * 	register msg handler for redir interface and initialize semaphore and completion.
 */
uint32_t nss_tx_rx_virt_if_register_handler(struct nss_tx_rx_virt_if_handle *handle)
{
	struct nss_ctx_instance *nss_ctx = (struct nss_ctx_instance *)&nss_top_main.nss[nss_top_main.wlan_handler_id];

	uint32_t ret;
	struct nss_tx_rx_virt_if_pvt *nrip = NULL;
	int32_t if_num = handle->if_num;

	ret = nss_core_register_handler(nss_ctx, if_num, nss_tx_rx_virt_if_msg_handler, NULL);
	if (ret != NSS_CORE_STATUS_SUCCESS) {
		nss_warning("%d: Message handler failed to be registered for interface\n", if_num);
		return NSS_TX_RX_VIRT_IF_CORE_FAILURE;
	}

	nrip = handle->pvt;
	if (!nrip->sem_init_done) {
		sema_init(&nrip->sem, 1);
		init_completion(&nrip->complete);
		nrip->sem_init_done = 1;
	}

	nss_tx_rx_virt_if_stats_dentry_create();
	return NSS_TX_RX_VIRT_IF_SUCCESS;
}

/*
 * nss_tx_rx_virt_if_tx_msg()
 */
nss_tx_status_t nss_tx_rx_virt_if_tx_msg(struct nss_ctx_instance *nss_ctx, struct nss_tx_rx_virt_if_msg *nrim)
{
	int32_t status;
	struct sk_buff *nbuf;
	struct nss_cmn_msg *ncm = &nrim->cm;
	struct nss_tx_rx_virt_if_msg *nrim2;

	if (unlikely(nss_ctx->state != NSS_CORE_STATE_INITIALIZED)) {
		nss_warning("Interface could not be created as core not ready");
		return NSS_TX_FAILURE;
	}

	/*
	 * Sanity check the message
	 */
	if (!NSS_IS_IF_TYPE(DYNAMIC, ncm->interface)) {
		nss_warning("%p: tx request for another interface: %d", nss_ctx, ncm->interface);
		return NSS_TX_FAILURE;
	}

	if (ncm->type > NSS_TX_RX_VIRT_IF_MAX_MSG_TYPES) {
		nss_warning("%p: message type out of range: %d", nss_ctx, ncm->type);
		return NSS_TX_FAILURE;
	}

	if (nss_cmn_get_msg_len(ncm) > sizeof(struct nss_tx_rx_virt_if_msg)) {
		nss_warning("%p: invalid length: %d. Length of redir msg is %d",
				nss_ctx, nss_cmn_get_msg_len(ncm), (int)sizeof(struct nss_tx_rx_virt_if_msg));
		return NSS_TX_FAILURE;
	}

	nbuf = dev_alloc_skb(NSS_NBUF_PAYLOAD_SIZE);
	if (unlikely(!nbuf)) {
		NSS_PKT_STATS_INCREMENT(nss_ctx, &nss_ctx->nss_top->stats_drv[NSS_STATS_DRV_NBUF_ALLOC_FAILS]);
		nss_warning("%p: redir interface %d: command allocation failed", nss_ctx, ncm->interface);
		return NSS_TX_FAILURE;
	}

	nrim2 = (struct nss_tx_rx_virt_if_msg *)skb_put(nbuf, sizeof(struct nss_tx_rx_virt_if_msg));
	memcpy(nrim2, nrim, sizeof(struct nss_tx_rx_virt_if_msg));

	status = nss_core_send_buffer(nss_ctx, 0, nbuf, NSS_IF_CMD_QUEUE, H2N_BUFFER_CTRL, 0);
	if (status != NSS_CORE_STATUS_SUCCESS) {
		dev_kfree_skb_any(nbuf);
		nss_warning("%p: Unable to enqueue 'virtual interface' command\n", nss_ctx);
		return NSS_TX_FAILURE;
	}

	nss_hal_send_interrupt(nss_ctx, NSS_H2N_INTR_DATA_COMMAND_QUEUE);

	/*
	 * The context returned is the redir interface # which is, essentially, the index into the if_ctx
	 * array that is holding the net_device pointer
	 */
	return NSS_TX_SUCCESS;
}

/*
 * nss_tx_rx_virt_if_tx_msg_sync
 *	Send a message from HLOS to NSS synchronously.
 */
static nss_tx_status_t nss_tx_rx_virt_if_tx_msg_sync(struct nss_tx_rx_virt_if_handle *handle,
							struct nss_tx_rx_virt_if_msg *nvim)
{
	nss_tx_status_t status;
	int ret = 0;
	struct nss_tx_rx_virt_if_pvt *nrip = handle->pvt;
	struct nss_ctx_instance *nss_ctx = handle->nss_ctx;

	down(&nrip->sem);

	status = nss_tx_rx_virt_if_tx_msg(nss_ctx, nvim);
	if (status != NSS_TX_SUCCESS) {
		nss_warning("%p: nss_tx_rx_virt_if_msg failed\n", nss_ctx);
		up(&nrip->sem);
		return status;
	}

	ret = wait_for_completion_timeout(&nrip->complete,
						msecs_to_jiffies(NSS_TX_RX_VIRT_IF_TX_TIMEOUT));
	if (!ret) {
		nss_warning("%p: redir_if tx failed due to timeout\n", nss_ctx);
		nrip->response = NSS_TX_FAILURE;
	}

	status = nrip->response;
	up(&nrip->sem);

	return status;
}

/*
 * nss_tx_rx_virt_if_handle_destroy()
 *	Destroy the redir handle either due to request from user or due to error, synchronously.
 */
static int nss_tx_rx_virt_if_handle_destroy(struct nss_tx_rx_virt_if_handle *handle)
{
	nss_tx_status_t status;
	int32_t if_num = handle->if_num;
	int32_t index = NSS_TX_RX_VIRT_IF_GET_INDEX(if_num);

	status = nss_dynamic_interface_dealloc_node(if_num, NSS_DYNAMIC_INTERFACE_TYPE_VIRTIF_DEPRECATED);
	if (status != NSS_TX_SUCCESS) {
		nss_warning("%p: Dynamic interface destroy failed status %d\n", handle->nss_ctx, status);
		return status;
	}

	spin_lock_bh(&nss_tx_rx_virt_if_lock);
	nss_tx_rx_virt_if_handles[index] = NULL;
	spin_unlock_bh(&nss_tx_rx_virt_if_lock);

	kfree(handle->pvt);
	kfree(handle);

	return status;
}

/*
 * nss_create_virt_if()
 *	Create a virtual interface synchronously.
 */
void *nss_create_virt_if(struct net_device *netdev)
{
	struct nss_ctx_instance *nss_ctx = &nss_top_main.nss[nss_top_main.wlan_handler_id];
	struct nss_tx_rx_virt_if_msg nrim;
	struct nss_tx_rx_virt_if_create_msg *nrcm;
	uint32_t ret;
	struct nss_tx_rx_virt_if_handle *handle = NULL;
	int32_t if_num;

	if (unlikely(nss_ctx->state != NSS_CORE_STATE_INITIALIZED)) {
		nss_warning("%p: Interface could not be created as core not ready\n", nss_ctx);
		return NULL;
	}

	if_num = nss_dynamic_interface_alloc_node(NSS_DYNAMIC_INTERFACE_TYPE_VIRTIF_DEPRECATED);
	if (if_num < 0) {
		nss_warning("%p: failure allocating redir if\n", nss_ctx);
		return NULL;
	}

	handle = nss_tx_rx_virt_if_handle_create(nss_ctx, if_num, &ret);
	if (!handle) {
		nss_warning("%p:redir_if handle creation failed ret %d\n", nss_ctx, ret);
		nss_dynamic_interface_dealloc_node(if_num, NSS_DYNAMIC_INTERFACE_TYPE_VIRTIF_DEPRECATED);
		return NULL;
	}

	/* Initializes the semaphore and also sets the msg handler for if_num */
	ret = nss_tx_rx_virt_if_register_handler(handle);
	if (ret != NSS_VIRT_IF_SUCCESS) {
		nss_warning("%p: Registration handler failed reason: %d\n", nss_ctx, ret);
		goto error;
	}

	nss_tx_rx_virt_if_msg_init(&nrim, handle->if_num, NSS_TX_RX_VIRT_IF_TX_CREATE_MSG,
				sizeof(struct nss_tx_rx_virt_if_create_msg), nss_tx_rx_virt_if_callback, handle);

	nrcm = &nrim.msg.if_create;
	nrcm->flags = 0;
	memcpy(nrcm->mac_addr, netdev->dev_addr, ETH_ALEN);

	ret = nss_tx_rx_virt_if_tx_msg_sync(handle, &nrim);
	if (ret != NSS_TX_SUCCESS) {
		nss_warning("%p: nss_tx_rx_virt_if_tx_msg_sync failed %u\n", nss_ctx, ret);
		goto error;
	}

	spin_lock_bh(&nss_top_main.lock);
	nss_core_register_subsys_dp(nss_ctx, handle->if_num, NULL, NULL, NULL, netdev, 0);
	spin_unlock_bh(&nss_top_main.lock);

	/*
	 * Hold a reference to the net_device
	 */
	dev_hold(netdev);

	/*
	 * The context returned is the handle interface # which contains all the info related to
	 * the interface if_num.
	 */

	return (void*)handle;

error:
	nss_tx_rx_virt_if_handle_destroy(handle);
	return NULL;
}

/*
 * nss_destroy_virt_if()
 *	Destroy a virtual interface synchronously.
 */
nss_tx_status_t nss_destroy_virt_if(void *ctx)
{
	struct nss_tx_rx_virt_if_handle *handle = (struct nss_tx_rx_virt_if_handle *)ctx;
	nss_tx_status_t status;
	struct net_device *dev;
	int32_t if_num;
	struct nss_ctx_instance *nss_ctx;
	uint32_t ret;

	if (!handle) {
		nss_warning("handle is NULL\n");
		return NSS_TX_FAILURE_BAD_PARAM;
	}

	if_num = handle->if_num;
	nss_ctx = handle->nss_ctx;

	if (unlikely(nss_ctx->state != NSS_CORE_STATE_INITIALIZED)) {
		nss_warning("%p: Interface could not be destroyed as core not ready\n", nss_ctx);
		return NSS_TX_FAILURE_NOT_READY;
	}

	spin_lock_bh(&nss_top_main.lock);
	if (!nss_ctx->subsys_dp_register[if_num].ndev) {
		spin_unlock_bh(&nss_top_main.lock);
		nss_warning("%p: Unregister redir interface %d: no context\n", nss_ctx, if_num);
		return NSS_TX_FAILURE_BAD_PARAM;
	}

	dev = nss_ctx->subsys_dp_register[if_num].ndev;
	nss_unregister_virt_if(handle);
	spin_unlock_bh(&nss_top_main.lock);
	dev_put(dev);

	status = nss_tx_rx_virt_if_handle_destroy(handle);
	if (status != NSS_TX_SUCCESS) {
		nss_warning("%p: handle destroy failed for if_num %d\n", nss_ctx, if_num);
		return NSS_TX_FAILURE;
	}

	ret = nss_core_unregister_handler(nss_ctx, if_num);
	if (ret != NSS_CORE_STATUS_SUCCESS) {
		nss_warning("%p: Not able to unregister handler for redir_if interface %d with NSS core\n", nss_ctx, if_num);
		return NSS_TX_FAILURE_BAD_PARAM;
	}

	return status;
}

EXPORT_SYMBOL(nss_tx_virt_if_rxbuf);
EXPORT_SYMBOL(nss_tx_virt_if_rx_nwifibuf);
EXPORT_SYMBOL(nss_create_virt_if);
EXPORT_SYMBOL(nss_destroy_virt_if);
EXPORT_SYMBOL(nss_register_virt_if);
