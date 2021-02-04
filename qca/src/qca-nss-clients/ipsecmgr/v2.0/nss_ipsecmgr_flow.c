/*
 **************************************************************************
 * Copyright (c) 2017-2018, The Linux Foundation. All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTUOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 **************************************************************************
 */
#include <linux/types.h>
#include <linux/ip.h>
#include <linux/inet.h>
#include <linux/of.h>
#include <linux/ipv6.h>
#include <linux/kernel.h>
#include <linux/skbuff.h>
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/rtnetlink.h>
#include <asm/atomic.h>
#include <linux/debugfs.h>
#include <linux/completion.h>
#include <linux/vmalloc.h>
#include <net/icmp.h>
#include <net/route.h>
#include <net/ip6_route.h>

#include <nss_api_if.h>
#include <nss_ipsec.h>
#include <nss_ipsecmgr.h>

#include "nss_ipsecmgr_priv.h"

extern struct nss_ipsecmgr_drv *ipsecmgr_drv;

/*
 * nss_ipsecmgr_flow_add_resp()
 * 	response for the flow message
 */
static void nss_ipsecmgr_flow_add_resp(void *app_data, struct nss_ipsec_msg *nim)
{
	struct nss_ipsecmgr_flow_entry *flow = app_data;
	struct nss_ipsec_tuple sa_tuple = {0};
	struct nss_ipsecmgr_sa_entry *sa;
	uint32_t index;

	BUG_ON(!in_atomic());

	/*
	 * If, NSS rejected the flow add then we will not
	 * add it to our list
	 */
	if (nim->cm.response != NSS_CMN_RESPONSE_ACK) {
		kfree(flow);
		return;
	}

	nss_ipsecmgr_flow_outer2tuple(&flow->outer, &sa_tuple);

	write_lock(&ipsecmgr_drv->lock);
	sa = nss_ipsecmgr_sa_lookup(ipsecmgr_drv->sa_db, &sa_tuple);
	if (!sa) {
		write_unlock(&ipsecmgr_drv->lock);
		kfree(flow);
		return;
	}

	/*
	 * Add reference of the flow to the SA associated
	 * with the outer.
	 */
	nss_ipsecmgr_ref_add(&flow->ref, &sa->ref);

	index = nss_ipsecmgr_tuple2index(&nim->tuple, NSS_IPSECMGR_FLOW_MAX);
	list_add(&flow->list, &ipsecmgr_drv->flow_db[index]);
	write_unlock(&ipsecmgr_drv->lock);

	return;
}

/*
 * nss_ipsecmgr_flow_del_resp()
 * 	response for the flow message
 */
static void nss_ipsecmgr_flow_del_resp(void *app_data, struct nss_ipsec_msg *nim)
{
	struct nss_ipsecmgr_flow_entry *flow = app_data;

	kfree(flow);
	return;
}

/*
 * nss_ipsecmgr_flow_retry()
 *	Retry the flow message
 */
static void nss_ipsecmgr_flow_retry(struct work_struct *work)
{
	struct nss_ipsecmgr_flow_entry *flow = container_of(work, struct nss_ipsecmgr_flow_entry, retry_work.work);
	nss_tx_status_t status;

	status = nss_ipsec_tx_msg(ipsecmgr_drv->nss_ctx, &flow->nim);
	if (status == NSS_TX_FAILURE_QUEUE)
		schedule_delayed_work(&flow->retry_work, NSS_IPSECMGR_FLOW_RETRY_TIMEOUT);

	nss_ipsecmgr_trace("%p: Flow retry status(%u)", flow, status);
}

/*
 * nss_ipsecmgr_flow_free()
 *	Free the flow entry
 */
static void nss_ipsecmgr_flow_free(struct nss_ipsecmgr_ref *ref)
{
	struct nss_ipsecmgr_flow_entry *flow = container_of(ref, struct nss_ipsecmgr_flow_entry, ref);
	nss_tx_status_t status;

	/*
	 * Write lock needs to be held by the caller since flow db is
	 * getting modified.
	 */
	BUG_ON(write_can_lock(&ipsecmgr_drv->lock));

	list_del_init(&flow->list);

	/*
	 * Initialize the IPsec message to be sent.
	 */
	nss_ipsec_msg_init(&flow->nim, flow->nim.cm.interface,
				NSS_IPSEC_MSG_TYPE_DEL_RULE,
				NSS_IPSEC_MSG_LEN,
				nss_ipsecmgr_flow_del_resp,
				flow);

	status = nss_ipsec_tx_msg(ipsecmgr_drv->nss_ctx, &flow->nim);

	switch (status) {
	case NSS_TX_SUCCESS:
		return;

	case NSS_TX_FAILURE:
	case NSS_TX_FAILURE_QUEUE:
		schedule_delayed_work(&flow->retry_work, NSS_IPSECMGR_FLOW_RETRY_TIMEOUT);
		return;

	default:
		nss_ipsecmgr_warn("%p: Failed to send message to NSS (%u)", ref, status);
		kfree(flow);
		return;
	}
}

/*
 * nss_ipsecmgr_flow_inner2tuple()
 *	Convert flow inner to tuple
 */
void nss_ipsecmgr_flow_inner2tuple(struct nss_ipsecmgr_flow_inner *inner, struct nss_ipsec_tuple *tuple)
{
	/*
	 * copy IP addresses
	 */
	memcpy(tuple->dst_addr, inner->dest_ip, sizeof(tuple->dst_addr));
	memcpy(tuple->src_addr, inner->src_ip, sizeof(tuple->src_addr));

	tuple->proto_next_hdr = inner->proto_next_hdr;
	tuple->esp_spi = 0;
	tuple->ip_ver = inner->ip_version;

	tuple->dst_port = inner->dport;
	tuple->src_port = inner->sport;
}

/*
 * nss_ipsecmgr_flow_outer2tuple()
 *	Convert flow outer to tuple
 */
void nss_ipsecmgr_flow_outer2tuple(struct nss_ipsecmgr_flow_outer *outer, struct nss_ipsec_tuple *tuple)
{
	/*
	 * copy IP addresses
	 */
	memcpy(tuple->dst_addr, outer->dest_ip, sizeof(tuple->dst_addr));
	memcpy(tuple->src_addr, outer->src_ip, sizeof(tuple->src_addr));

	tuple->proto_next_hdr = IPPROTO_ESP;
	tuple->esp_spi = outer->spi_index;
	tuple->ip_ver = outer->ip_version;

	tuple->dst_port = 0;
	tuple->src_port = 0;
}

/*
 * nss_ipsecmgr_flow_lookup()
 *	Lookup the given flow in the data base
 *
 * Note: No locks are taken here; so needs to be called with a read/write lock held.
 */
struct nss_ipsecmgr_flow_entry *nss_ipsecmgr_flow_lookup(struct list_head *db, struct nss_ipsec_tuple *tuple)
{
	uint32_t index = nss_ipsecmgr_tuple2index(tuple, NSS_IPSECMGR_FLOW_MAX);
	struct nss_ipsecmgr_flow_entry *flow;
	struct list_head *head = &db[index];

	/*
	 * Linux does not provide any specific API(s) to test for RW locks. The caller
	 * being internal is assumed to hold write lock before intiating this.
	 */
	list_for_each_entry(flow, head, list) {
		if (nss_ipsecmgr_tuple_match(&flow->tuple, tuple))
			return flow;
	}

	return NULL;
}

/*
 * nss_ipsecmgr_flow_del()
 *	Delete a existing flow from the database
 *
 * Note: We will only delete the flow associated with the requested SA.
 * If we donot find the association then the flow delete will not perform
 * the delete
 */
void nss_ipsecmgr_flow_del(struct net_device *tun, struct nss_ipsecmgr_flow_inner *inner,
				struct nss_ipsecmgr_flow_outer *outer)
{
	struct nss_ipsecmgr_priv *priv = netdev_priv(tun);
	struct nss_ipsec_tuple flow_sa_tuple = {0};
	struct nss_ipsec_tuple flow_tuple = {0};
	struct nss_ipsec_tuple sa_tuple = {0};
	struct nss_ipsecmgr_flow_entry *flow;

	nss_ipsecmgr_flow_inner2tuple(inner, &flow_tuple);
	nss_ipsecmgr_flow_outer2tuple(outer, &sa_tuple);

	/*
	 * Write lock needed here since Flow DB is looked up and removed
	 * No one should be accessing flow at this point
	 */
	write_lock_bh(&ipsecmgr_drv->lock);

	/*
	 * Convert inner flow info to tuple to allocate
	 * a new flow; if it doesn't exist already.
	 */
	flow = nss_ipsecmgr_flow_lookup(ipsecmgr_drv->flow_db, &flow_tuple);
	if (!flow) {
		write_unlock_bh(&ipsecmgr_drv->lock);
		nss_ipsecmgr_warn("%p:Failed to find entry in flow delete", priv);
		return;
	}

	/*
	 * Match if the SA provided in indeed associated with the flow. In case this is
	 * not associated due to re-key then we should not remove the flow
	 */
	nss_ipsecmgr_flow_outer2tuple(&flow->outer, &flow_sa_tuple);

	if (!nss_ipsecmgr_tuple_match(&flow_sa_tuple, &sa_tuple)) {
		write_unlock_bh(&ipsecmgr_drv->lock);
		nss_ipsecmgr_warn("%p:Failed to match the SA in flow(%p) delete", priv, flow);
		return;
	}

	/*
	 * Free the flow entry and reference.
	 */
	nss_ipsecmgr_flow_free(&flow->ref);
	write_unlock_bh(&ipsecmgr_drv->lock);
}
EXPORT_SYMBOL(nss_ipsecmgr_flow_del);

/*
 * nss_ipsecmgr_flow_add()
 *	Add a new flow to database
 */
nss_ipsecmgr_status_t nss_ipsecmgr_flow_add(struct net_device *tun, struct nss_ipsecmgr_flow_inner *inner,
						struct nss_ipsecmgr_flow_outer *outer)
{
	struct nss_ipsecmgr_priv *priv = netdev_priv(tun);
	struct nss_ipsec_tuple flow_sa_tuple = {0};
	struct nss_ipsec_tuple flow_tuple = {0};
	struct nss_ipsec_tuple sa_tuple = {0};
	struct nss_ipsecmgr_flow_entry *flow;
	struct nss_ipsecmgr_sa_entry *sa;
	struct nss_ipsec_tuple *tuple;
	struct nss_ipsec_msg *nim;

	nss_ipsecmgr_flow_outer2tuple(outer, &sa_tuple);
	nss_ipsecmgr_flow_inner2tuple(inner, &flow_tuple);

	/*
	 * Write lock needed here since Flow DB is looked up and added
	 * No one should be accessing/removing flow at this point
	 */
	write_lock_bh(&ipsecmgr_drv->lock);

	/*
	 * Look for an existing SA to match to.
	 */
	sa = nss_ipsecmgr_sa_lookup(ipsecmgr_drv->sa_db, &sa_tuple);
	if (!sa) {
		write_unlock_bh(&ipsecmgr_drv->lock);
		nss_ipsecmgr_warn("%p: Failed to lookup sa in flow_add", ipsecmgr_drv);
		return NSS_IPSECMGR_FAIL_SA;
	}

	tuple = (sa->type == NSS_IPSEC_TYPE_ENCAP) ? &flow_tuple : &sa_tuple;

	/*
	 * At this point we do not know whether the flow is duplicate or not
	 * we try to perform a flow lookup to determine whether the flow already
	 * exists in the data base. Once, we have determined the flow then we check
	 * if the caller is performing a SA switch.
	 */
	flow = nss_ipsecmgr_flow_lookup(ipsecmgr_drv->flow_db, tuple);
	if (flow) {
		/*
		 * Flow already exists; check if the SA entry is the same. In case
		 * the SA is same then it is surely a duplicate entry. We need to
		 * return from here without doing anything.
		 */
		nss_ipsecmgr_flow_outer2tuple(&flow->outer, &flow_sa_tuple);

		if (!nss_ipsecmgr_tuple_match(&flow_sa_tuple, &sa_tuple))
			goto flow_init;

		nss_ipsecmgr_trace("%p: Duplicate flow in flow_add", ipsecmgr_drv);
		write_unlock_bh(&ipsecmgr_drv->lock);
		return NSS_IPSECMGR_DUPLICATE_FLOW;
	}

	/*
	 * This is a new flow
	 */
	flow = kzalloc(sizeof(*flow), GFP_ATOMIC);
	if (!flow) {
		write_unlock_bh(&ipsecmgr_drv->lock);
		nss_ipsecmgr_info("%p:Failed to allocate flow", priv);
		return NSS_IPSECMGR_FAIL_FLOW_ALLOC;
	}

	/*
	 * Initialize the flow entry
	 */
	INIT_LIST_HEAD(&flow->list);
	INIT_DELAYED_WORK(&flow->retry_work, nss_ipsecmgr_flow_retry);

	nss_ipsecmgr_ref_init(&flow->ref, nss_ipsecmgr_flow_free);
	flow->tunnel_id = priv->dev->ifindex;

flow_init:

	/*
	 * We can reach here in 2 cases.
	 * 1) When a new flow is added
	 * 2) When an existing flow is updated to new SA
	 *
	 * In both cases we want to operate on the flow entry
	 * after the firmware confirms the changes. That way we will not make
	 * any changes to the flow entry while the firmware processes it.
	 * Thus we start by removing the flow entry from the list of flows if
	 * it is already part of it. Then operate on it. But, we will be accesing
	 * the SA entry hence we need to hold the lock till that time
	 */
	list_del_init(&flow->list);

	/*
	 * Initialize the IPsec message to be sent.
	 */
	nim = &flow->nim;
	memset(nim, 0, sizeof(*nim));

	nss_ipsec_msg_init(nim, sa->if_num,
				NSS_IPSEC_MSG_TYPE_ADD_RULE,
				NSS_IPSEC_MSG_LEN,
				nss_ipsecmgr_flow_add_resp,
				flow);

	nim->tunnel_id = flow->tunnel_id;
	nim->type = sa->type;

	/*
	 * Copy information received during the SA creation
	 * to be used to send encap flow initiation message to FW.
	 */
	memcpy(&nim->msg.rule.oip, &sa->oip, sizeof(nim->msg.rule.oip));
	memcpy(&nim->msg.rule.data, &sa->data, sizeof(nim->msg.rule.data));
	memcpy(&nim->tuple, tuple, sizeof(nim->tuple));

	/*
	 * We need to set protocol to UDP in case of NAT-T;
	 * else to ESP.
	 */
	if ((sa->data.nat_t_req) && (sa->type == NSS_IPSEC_TYPE_DECAP))
		nim->tuple.proto_next_hdr = IPPROTO_UDP;

	memcpy(&flow->tuple, tuple, sizeof(flow->tuple));
	memcpy(&flow->outer, &sa->outer, sizeof(flow->outer));

	write_unlock_bh(&ipsecmgr_drv->lock);

	/*
	 * Note: We donot need to hold the lock for the accessing the flow since
	 * it is not part of the list yet. Now, send a message to firmware for
	 * updating the flow in its table. Once, NSS confirms it then we will
	 * add the flow back in the database
	 */
	if (nss_ipsec_tx_msg(ipsecmgr_drv->nss_ctx, &flow->nim) != NSS_TX_SUCCESS) {
		kfree(flow);
		nss_ipsecmgr_info("%p:unable to send the flow_update message\n", flow);
		return NSS_IPSECMGR_FAIL;
	}

	return NSS_IPSECMGR_OK;
}
EXPORT_SYMBOL(nss_ipsecmgr_flow_add);
