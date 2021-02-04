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
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 **************************************************************************
 */

/* nss_ipsecmgr.c
 *	NSS to HLOS IPSec Manager
 */
#include <linux/version.h>
#include <linux/types.h>
#include <linux/ip.h>
#include <linux/of.h>
#include <linux/ipv6.h>
#include <linux/skbuff.h>
#include <linux/module.h>
#include <linux/bitops.h>
#include <linux/netdevice.h>
#include <linux/rtnetlink.h>
#include <linux/etherdevice.h>
#include <linux/vmalloc.h>
#include <linux/debugfs.h>
#include <linux/atomic.h>
#include <net/protocol.h>
#include <net/route.h>
#include <net/ip6_route.h>
#include <net/esp.h>
#include <net/xfrm.h>
#include <net/icmp.h>

#include <nss_api_if.h>
#include <nss_ipsec.h>
#include <nss_ipsecmgr.h>

#include "nss_ipsecmgr_priv.h"
#include <nss_tstamp.h>

struct nss_ipsecmgr_drv *ipsecmgr_drv;

static const struct net_device_ops nss_ipsecmgr_dummy_ndev_ops;

/*
 * nss_ipsecmgr_dev_dummy_setup()
 *	Setup function for dummy netdevice.
 */
static void nss_ipsecmgr_dev_dummy_setup(struct net_device *dev)
{
}

/*
 * nss_ipsecmgr_dev_open()
 *	open the tunnel for usage
 */
static int nss_ipsecmgr_dev_open(struct net_device *dev)
{
	struct nss_ipsecmgr_priv *priv __attribute__((unused)) = netdev_priv(dev);

	netif_start_queue(dev);
	return 0;
}

/*
 * nss_ipsecmgr_dev_stop()
 *	stop the IPsec tunnel
 */
static int nss_ipsecmgr_dev_stop(struct net_device *dev)
{
	struct nss_ipsecmgr_priv *priv __attribute__((unused)) = netdev_priv(dev);

	netif_stop_queue(dev);
	return 0;
}

/*
 * nss_ipsecmgr_dev_tx()
 *	tunnel transmit function
 */
static netdev_tx_t nss_ipsecmgr_dev_tx(struct sk_buff *skb, struct net_device *dev)
{
	struct nss_ipsecmgr_priv *priv __attribute__((unused)) = netdev_priv(dev);
	struct iphdr *iph;
	bool expand_skb = false;
	int nhead, ntail;

	nhead = dev->needed_headroom;
	ntail = dev->needed_tailroom;

	iph = (struct iphdr *)skb->data;

	/*
	 * IPsec does not encapsulate non-IP frames
	 */
	if ((iph->version != IPVERSION) && (iph->version != 6))
		goto free;

	/*
	 * Check if skb is shared
	 */
	if (unlikely(skb_shared(skb)))
		skb = skb_unshare(skb, in_atomic() ? GFP_ATOMIC : GFP_KERNEL);

	/*
	 * For all these cases
	 * - create a writable copy of buffer
	 * - increase the head room
	 * - increase the tail room
	 */
	if (skb_cloned(skb) || (skb_headroom(skb) < nhead) || (skb_tailroom(skb) < ntail)) {
		expand_skb = true;
	}

	if (expand_skb && pskb_expand_head(skb, nhead, ntail, GFP_KERNEL)) {
		nss_ipsecmgr_trace("%s: unable to expand buffer\n", dev->name);
		goto free;
	}

	/*
	 * Send the packet down;
	 * TODO: Use stop queue and start queue to restart in case of
	 * queue full condition
	 */
	if (nss_ipsec_tx_buf(skb, ipsecmgr_drv->encap_ifnum) != 0) {
		goto free;
	}

	return NETDEV_TX_OK;

free:
	dev_kfree_skb_any(skb);
	return NETDEV_TX_OK;
}

/*
 * nss_ipsecmgr_dev_stats64()
 *	Get device statistics
 */
static struct rtnl_link_stats64 *nss_ipsecmgr_dev_stats64(struct net_device *dev, struct rtnl_link_stats64 *stats)
{
	struct nss_ipsecmgr_priv *priv = netdev_priv(dev);

	memcpy(stats, &priv->stats, sizeof(struct rtnl_link_stats64));

	return stats;
}

/*
 * nss_ipsecmgr_dev_mtu()
 *	Change device MTU
 */
static int nss_ipsecmgr_dev_mtu(struct net_device *dev, int mtu)
{
	dev->mtu = mtu;
	return 0;
}

/* NSS IPsec tunnel operation */
static const struct net_device_ops ipsecmgr_dev_ops = {
	.ndo_open = nss_ipsecmgr_dev_open,
	.ndo_stop = nss_ipsecmgr_dev_stop,
	.ndo_start_xmit = nss_ipsecmgr_dev_tx,
	.ndo_get_stats64 = nss_ipsecmgr_dev_stats64,
	.ndo_change_mtu = nss_ipsecmgr_dev_mtu,
};

/*
 * nss_ipsecmgr_dev_free()
 *	free an existing IPsec tunnel interface
 */
static void nss_ipsecmgr_dev_free(struct net_device *dev)
{
	nss_ipsecmgr_info("IPsec tunnel device(%s) freed\n", dev->name);
	free_netdev(dev);
}

/*
 * nss_ipsecmr_dev_setup()
 *	setup the IPsec tunnel
 */
static void nss_ipsecmgr_dev_setup(struct net_device *dev)
{
	dev->addr_len = ETH_ALEN;
	dev->mtu = NSS_IPSECMGR_TUN_MTU(ETH_DATA_LEN);

	dev->hard_header_len = NSS_IPSECMGR_TUN_MAX_HDR_LEN;
	dev->needed_headroom = NSS_IPSECMGR_TUN_HEADROOM;
	dev->needed_tailroom = NSS_IPSECMGR_TUN_TAILROOM;

	dev->type = NSS_IPSEC_ARPHRD_IPSEC;

	dev->ethtool_ops = NULL;
	dev->header_ops = NULL;
	dev->netdev_ops = &ipsecmgr_dev_ops;

	dev->destructor = nss_ipsecmgr_dev_free;

	/*
	 * Get the MAC address from the ethernet device
	 */
	random_ether_addr(dev->dev_addr);

	memset(dev->broadcast, 0xff, dev->addr_len);
	memcpy(dev->perm_addr, dev->dev_addr, dev->addr_len);
}

/*
 * nss_ipsecmgr_ref_no_free()
 *	dummy functions for object owner when there is no free
 */
static void nss_ipsecmgr_ref_no_free(struct nss_ipsecmgr_ref *ref)
{
	nss_ipsecmgr_trace("%p: ref_no_free triggered\n", ref);
	return;
}

/*
 * nss_ipsecmgr_dev_rx_route_v4()
 *	NSS IPsec manager device send IPv4 packet for routing
 */
static void nss_ipsecmgr_dev_rx_route_v4(struct sk_buff *skb)
{
	struct iphdr *iph = ip_hdr(skb);
	struct rtable *rt;

	rt = ip_route_output(&init_net, iph->daddr, iph->saddr, 0, 0);
	if (unlikely(IS_ERR(rt))) {
		nss_ipsecmgr_warn("%pK: No route, drop packet.\n", skb);
		dev_kfree_skb_any(skb);
		return;
	}

	/*
	 * Sets the 'dst' entry for SKB and sends the packet out directly to the physical
	 * device associated with the IPsec tunnel interface.
	 */
	skb_dst_set(skb, &rt->dst);
	skb->ip_summed = CHECKSUM_COMPLETE;
	ip_local_out(&init_net, NULL, skb);
}

/*
 * nss_ipsecmgr_dev_rx_route_v6()
 *	NSS IPsec manager device send IPv6 packet for routing
 */
static void nss_ipsecmgr_dev_rx_route_v6(struct sk_buff *skb)
{
	struct ipv6hdr *ip6h = ipv6_hdr(skb);
	struct dst_entry *dst;
	struct flowi6 fl6;

	memset(&fl6, 0, sizeof(fl6));
	memcpy(&fl6.daddr, &ip6h->daddr, sizeof(fl6.daddr));
	memcpy(&fl6.saddr, &ip6h->saddr, sizeof(fl6.saddr));

	dst = ip6_route_output(&init_net, NULL, &fl6);
	if (unlikely(IS_ERR(dst))) {
		nss_ipsecmgr_warn("%pK: No route, drop packet.\n", skb);
		dev_kfree_skb_any(skb);
		return;
	}

	/*
	 * Sets the 'dst' entry for SKB and sends the packet out directly to the physical
	 * device associated with the IPsec tunnel interface.
	 */
	skb_dst_set(skb, dst);
	skb->ip_summed = CHECKSUM_COMPLETE;
	ip6_local_out(&init_net, NULL, skb);
}

/*
 * nss_ipsecmgr_ref_init()
 *	initiaize the reference object
 */
void nss_ipsecmgr_ref_init(struct nss_ipsecmgr_ref *ref, nss_ipsecmgr_ref_method_t free)
{
	INIT_LIST_HEAD(&ref->head);
	INIT_LIST_HEAD(&ref->node);

	ref->id = 0;
	ref->parent = NULL;
	ref->free = free ? free : nss_ipsecmgr_ref_no_free;
}

/*
 * nss_ipsecmgr_ref_add()
 *	add child reference to parent chain
 */
void nss_ipsecmgr_ref_add(struct nss_ipsecmgr_ref *child, struct nss_ipsecmgr_ref *parent)
{
	/*
	 * DEBUG check to see if the lock is taken before touching the list
	 */
	BUG_ON(write_can_lock(&ipsecmgr_drv->lock));

	/*
	 * if child is already part of an existing chain then remove it before
	 * adding it to the new one. In case this is a new entry then the list
	 * init during alloc would ensure that the "del_init" operation results
	 * in a no-op
	 */
	list_del_init(&child->node);
	list_add(&child->node, &parent->head);

	child->parent = parent;
}

/*
 * nss_ipsecmgr_ref_free()
 *	Free all references from the "ref" object
 *
 * Note: If, the "ref" has child references then it
 * will walk the child reference chain first and issue
 * free for each of the associated "child ref" objects.
 * At the end it will invoke free for the "parent" ref
 * object.
 *
 * +-------+
 * |  tun0 |
 * +-------+
 *     |
 *     V
 * +-------+    +-------+    +-------+
 * |  SA1  |--->|  SA2  |--->|  SA3  |
 * +-------+    +-------+    +-------+
 *     |
 *     V
 * +-------+    +-------+    +-------+
 * | Flow1 |--->| Flow2 |--->| Flow4 |
 * +-------+    +-------+    +-------+
 */
void nss_ipsecmgr_ref_free(struct nss_ipsecmgr_ref *ref)
{
	struct nss_ipsecmgr_ref *entry;

	/*
	 * DEBUG check to see if the lock is taken before touching the list
	 */
	BUG_ON(write_can_lock(&ipsecmgr_drv->lock));

	while (!list_empty(&ref->head)) {
		entry = list_first_entry(&ref->head, struct nss_ipsecmgr_ref, node);
		nss_ipsecmgr_ref_free(entry);
	}

	list_del_init(&ref->node);
	ref->free(ref);
}

/*
 * nss_ipsecmgr_dev_rx_inner()
 *	NSS IPsec manager device receive, process inner exception
 */
void nss_ipsecmgr_dev_rx_inner(struct net_device *dev, struct sk_buff *skb, struct napi_struct *napi)
{
	struct nss_ipsecmgr_flow_entry *flow;
	struct nss_ipsec_tuple tuple = {0};
	struct nss_ipsecmgr_callback *cb;
	struct nss_ipsecmgr_priv *priv;
	uint32_t tunnel_id;

	skb_reset_mac_header(skb);
	skb_reset_network_header(skb);

	BUG_ON(!in_atomic());

	/*
	 * We need to search if the flow is already registred with IPsec;
	 * if we have already configured the flow then the flow entry indicates
	 * the associated tunnel.
	 */
	switch (ip_hdr(skb)->version) {
	case IPVERSION:	{
		struct list_head *flow_db = ipsecmgr_drv->flow_db;
		struct nss_ipsecmgr_flow_inner inner = {0};
		struct iphdr *iph = ip_hdr(skb);
		struct dst_entry *dst;
		struct rtable *rt;

		skb->protocol = cpu_to_be16(ETH_P_IP);
		skb_set_transport_header(skb, sizeof(struct iphdr));

		inner.ip_version = IPVERSION;
		inner.proto_next_hdr = iph->protocol;

		/*
		 * Search by swapping the addresses, since the rule would
		 * have been pushed in the other direction
		 */
		inner.src_ip[0] = ntohl(iph->daddr);
		inner.dest_ip[0] = ntohl(iph->saddr);
		nss_ipsecmgr_flow_inner2tuple(&inner, &tuple);

		read_lock(&ipsecmgr_drv->lock);

		flow = nss_ipsecmgr_flow_lookup(flow_db, &tuple);
		if (flow) {
			tunnel_id = flow->tunnel_id;
			read_unlock(&ipsecmgr_drv->lock);
			break;
		}

		read_unlock(&ipsecmgr_drv->lock);

		/*
		 * If, we could not find the flow then this must be a new
		 * flow that coming in for the first time. We should query
		 * the Linux to see the associated NETDEV
		 */
		rt = ip_route_output(&init_net, iph->saddr, 0, 0, 0);
		if (IS_ERR(rt))
			goto free;


		dst = (struct dst_entry *)rt;
		skb->dev = dst->dev;
		dst_release(dst);

		skb->pkt_type = PACKET_HOST;
		skb->skb_iif = skb->dev->ifindex;

		netif_receive_skb(skb);
		return;

	}

	case 6:	{
		struct list_head *flow_db = ipsecmgr_drv->flow_db;
		struct nss_ipsecmgr_flow_inner inner = {0};
		struct ipv6hdr *ip6h = ipv6_hdr(skb);
		struct dst_entry *dst;
		struct flowi6 fl6;

		skb->protocol = cpu_to_be16(ETH_P_IPV6);

		skb_set_transport_header(skb, sizeof(*ip6h));

		/*
		 * Search by swapping the addresses, since the rule would
		 * have been pushed in the other direction
		 */
		nss_ipsecmgr_ntoh_v6addr(inner.src_ip, ip6h->daddr.s6_addr32);
		nss_ipsecmgr_ntoh_v6addr(inner.dest_ip, ip6h->saddr.s6_addr32);

		inner.proto_next_hdr = ip6h->nexthdr;
		inner.ip_version = 6;

		if (inner.proto_next_hdr == NEXTHDR_FRAGMENT) {
			struct frag_hdr *fragh = (struct frag_hdr *)skb_transport_header(skb);
			skb_set_transport_header(skb, sizeof(*ip6h) + sizeof(*fragh));
			inner.proto_next_hdr = fragh->nexthdr;
		}

		nss_ipsecmgr_flow_inner2tuple(&inner, &tuple);

		read_lock(&ipsecmgr_drv->lock);

		flow = nss_ipsecmgr_flow_lookup(flow_db, &tuple);
		if (flow) {
			tunnel_id = flow->tunnel_id;
			read_unlock(&ipsecmgr_drv->lock);
			break;
		}

		read_unlock(&ipsecmgr_drv->lock);

		/*
		 * If, we could not find the flow then this must be a new
		 * flow that coming in for the first time. We should query
		 * the Linux to see the associated NETDEV
		 */
		memset(&fl6, 0, sizeof(fl6));
		memcpy(&fl6.daddr, &ip6h->saddr, sizeof(fl6.daddr));

		dst = ip6_route_output(&init_net, NULL, &fl6);
		if (IS_ERR(dst))
			goto free;


		skb->dev = dst->dev;
		dst_release(dst);

		skb->pkt_type = PACKET_HOST;
		skb->skb_iif = skb->dev->ifindex;

		netif_receive_skb(skb);
		return;

	}

	default:
		nss_ipsecmgr_warn("%p: non ip packet received after decapsulation", dev);
		goto free;
	}

	/*
	 * Use the tunnel-ID from flow entry to find the associated device
	 */
	dev = dev_get_by_index(&init_net, tunnel_id);
	if (!dev)
		goto free;

	priv = netdev_priv(dev);
	skb->dev = priv->cb.skb_dev;
	skb->pkt_type = PACKET_HOST;
	skb->skb_iif = skb->dev->ifindex;
	dev_put(dev);

	/*
	 * If, data callback is available then send the packet to the
	 * callback funtion
	 */
	cb = &priv->cb;
	if (cb->data_cb) {
		cb->data_cb(cb->app_data, skb);
		return;
	}

	netif_receive_skb(skb);
	return;

free:
	dev_kfree_skb_any(skb);
	return;
}

/*
 * nss_ipsecmgr_dev_rx_outer()
 *	NSS IPsec manager device receive, process outer exception
 */
void nss_ipsecmgr_dev_rx_outer(struct net_device *dev, struct sk_buff *skb, struct napi_struct *napi)
{
	struct list_head *sa_db = ipsecmgr_drv->sa_db;
	struct nss_ipsecmgr_flow_outer outer = {0};
	struct nss_ipsecmgr_sa_entry *sa_entry;
	struct nss_ipsec_tuple tuple = {0};
	void (*rx_route)(struct sk_buff *) = NULL;

	skb_reset_mac_header(skb);
	skb_reset_network_header(skb);

	BUG_ON(!in_atomic());

	switch (ip_hdr(skb)->version) {
	case IPVERSION:	{
		struct iphdr *iph = ip_hdr(skb);
		skb->protocol = ETH_P_IP;

		skb_set_transport_header(skb, sizeof(struct iphdr));

		outer.src_ip[0] = ntohl(iph->saddr);
		outer.dest_ip[0] = ntohl(iph->daddr);
		outer.ip_version = IPVERSION;
		rx_route = nss_ipsecmgr_dev_rx_route_v4;

		/*
		 * Process only ESP or UDP/NAT-T packets
		 */
		if (iph->protocol == IPPROTO_ESP)
			break;

		if ((iph->protocol == IPPROTO_UDP) && (udp_hdr(skb)->dest == ntohs(NSS_IPSECMGR_NATT_PORT_DATA))) {
			skb_set_transport_header(skb, sizeof(struct iphdr) + sizeof(struct udphdr));
			break;
		}

		nss_ipsecmgr_warn("%p: Unsupported IPv4 protocol(%u)", dev, iph->protocol);
		dev_kfree_skb_any(skb);
		return;
	}

	case 6:	{
		struct ipv6hdr *ip6h = ipv6_hdr(skb);
		skb->protocol = ETH_P_IPV6;
		rx_route = nss_ipsecmgr_dev_rx_route_v6;

		if (ip6h->nexthdr == IPPROTO_ESP) {
			nss_ipsecmgr_ntoh_v6addr(outer.src_ip, ip6h->saddr.s6_addr32);
			nss_ipsecmgr_ntoh_v6addr(outer.dest_ip, ip6h->daddr.s6_addr32);
			outer.ip_version = 6;

			skb_set_transport_header(skb, sizeof(struct ipv6hdr));
			break;
		}

		nss_ipsecmgr_warn("%p: Unsupported IPv6 next header(%u)", dev, ip6h->nexthdr);
		dev_kfree_skb_any(skb);
		return;
	}

	default:
		nss_ipsecmgr_warn("%p: non ip packet received after decapsulation", dev);
		dev_kfree_skb_any(skb);
		return;
	}

	outer.spi_index = ntohl(ip_esp_hdr(skb)->spi);
	nss_ipsecmgr_flow_outer2tuple(&outer, &tuple);

	read_lock(&ipsecmgr_drv->lock);

	sa_entry = nss_ipsecmgr_sa_lookup(sa_db, &tuple);
	if (!sa_entry) {
		read_unlock(&ipsecmgr_drv->lock);
		dev_kfree_skb_any(skb);
		return;
	}

	skb->dev = sa_entry->priv->dev;
	skb->skb_iif = skb->dev->ifindex;
	read_unlock(&ipsecmgr_drv->lock);

	/*
	 * Reaching this point means the outer ECM rule is non-existant
	 * whereas the IPsec rules are still present in FW. So, this is an ESP
	 * encapsulated packet that has been exceptioned to host from NSS.
	 * We can send it to Linux IPstack for further routing.
	 */
	BUG_ON(!rx_route);
	rx_route(skb);
}

/*
 * nss_ipsecmgr_dev_rx()
 *	NSS IPsec manager device receive function
 */
void nss_ipsecmgr_dev_rx(struct net_device *dev, struct sk_buff *skb, struct napi_struct *napi)
{
	skb_reset_network_header(skb);

	switch (ip_hdr(skb)->version) {
	case IPVERSION:	{
		struct iphdr *iph = ip_hdr(skb);

		if (iph->protocol == IPPROTO_ESP) {
			nss_ipsecmgr_dev_rx_outer(dev, skb, napi);
			return;
		}

		skb_set_transport_header(skb, sizeof(*iph));

		/*
		 * NAT-T is also an outer
		 */
		if ((iph->protocol == IPPROTO_UDP) && (udp_hdr(skb)->dest == ntohs(NSS_IPSECMGR_NATT_PORT_DATA))) {
			nss_ipsecmgr_dev_rx_outer(dev, skb, napi);
			return;
		}

		nss_ipsecmgr_dev_rx_inner(dev, skb, napi);
		return;
	}

	case 6:	{
		struct ipv6hdr *ip6h = ipv6_hdr(skb);

		if (ip6h->nexthdr == IPPROTO_ESP) {
			nss_ipsecmgr_dev_rx_outer(dev, skb, napi);
			return;
		}

		nss_ipsecmgr_dev_rx_inner(dev, skb, napi);
		return;
	}

	default:
		nss_ipsecmgr_trace("%p: non IP packet received", dev);
		dev_kfree_skb_any(skb);
		return;
	}
}


/*
 * nss_ipsecmgr_dev_update_stats()
 *	Update device stats
 */
static void nss_ipsecmgr_dev_update_stats(struct nss_ipsecmgr_priv *priv, struct nss_ipsec_msg *nim)
{
	struct rtnl_link_stats64 *dev_stats;
	struct nss_ipsec_sa_stats *sa_stats;

	dev_stats = &priv->stats;
	sa_stats = &nim->msg.stats.sa;

	if (nim->type == NSS_IPSEC_TYPE_ENCAP) {
		/*
		 * Update tunnel specific stats
		 */
		dev_stats->tx_bytes += sa_stats->bytes;
		dev_stats->tx_packets += sa_stats->count;

		dev_stats->tx_dropped += sa_stats->no_headroom;
		dev_stats->tx_dropped += sa_stats->no_tailroom;
		dev_stats->tx_dropped += sa_stats->no_resource;
		dev_stats->tx_dropped += sa_stats->fail_queue;
		dev_stats->tx_dropped += sa_stats->fail_hash;
		dev_stats->tx_dropped += sa_stats->fail_replay;
		return;
	}

	dev_stats->rx_bytes += sa_stats->bytes;
	dev_stats->rx_packets += sa_stats->count;

	dev_stats->rx_dropped += sa_stats->no_headroom;
	dev_stats->rx_dropped += sa_stats->no_tailroom;
	dev_stats->rx_dropped += sa_stats->no_resource;
	dev_stats->rx_dropped += sa_stats->fail_queue;
	dev_stats->rx_dropped += sa_stats->fail_hash;
	dev_stats->rx_dropped += sa_stats->fail_replay;
}

/*
 * nss_ipsecmgr_dev_rx_notify()
 *	Asynchronous event reception
 */
static void nss_ipsecmgr_dev_rx_notify(void *app_data, struct nss_ipsec_msg *nim)
{
	struct nss_ipsecmgr_drv *ipsecmgr_drv = app_data;
	struct nss_ipsecmgr_priv *priv;
	struct net_device *dev;

	BUG_ON(!nim);

	/*
	 * This holds the ref_cnt for the device
	 */
	dev = dev_get_by_index(&init_net, nim->tunnel_id);
	if (!dev) {
		nss_ipsecmgr_warn("%p: Failed to find the NETDEV(%d) associated with the message", nim, nim->tunnel_id);
		return;
	}

	priv = netdev_priv(dev);

	switch (nim->cm.type) {
	case NSS_IPSEC_MSG_TYPE_SYNC_SA_STATS: {
		struct nss_ipsecmgr_event ev = {.type = NSS_IPSECMGR_EVENT_SA_STATS};
		struct nss_ipsec_sa_stats *nim_stats = &nim->msg.stats.sa;
		struct nss_ipsec_tuple tuple = {0};
		struct nss_ipsecmgr_sa_entry *sa;
		bool send_event = false;

		memcpy(tuple.dst_addr, nim->tuple.dst_addr, sizeof(tuple.dst_addr));
		memcpy(tuple.src_addr, nim->tuple.src_addr, sizeof(tuple.src_addr));

		tuple.esp_spi = nim->tuple.esp_spi;
		tuple.ip_ver = nim->tuple.ip_ver;
		tuple.proto_next_hdr = IPPROTO_ESP;

		send_event = !!priv->cb.event_cb;

		nss_ipsecmgr_dev_update_stats(priv, nim);

		/*
		 * Write lock needed here since SA stats update
		 * modifies the SA entry's contents
		 */
		write_lock(&ipsecmgr_drv->lock);
		sa = nss_ipsecmgr_sa_lookup(ipsecmgr_drv->sa_db, &tuple);
		if (!sa) {
			write_unlock(&ipsecmgr_drv->lock);
			nss_ipsecmgr_warn("%p: Failed to find to the SA; it may have been deleted from host", dev);
			goto done;
		}

		nss_ipsecmgr_sa_update_stats(sa, nim_stats, send_event ? &ev : NULL);
		write_unlock(&ipsecmgr_drv->lock);

		/*
		 * If event callback is available then post the statistics using the callback function
		 */
		if (send_event)
			priv->cb.event_cb(priv->cb.app_data, &ev);

		break;
	}

	default:
		nss_ipsecmgr_info("%p: unhandled ipsec message type\n", nim);
		break;
	}
done:
	dev_put(dev);
}

/*
 * nss_ipsecmgr_tunnel_del()
 *	delete an existing IPsec tunnel
 */
void nss_ipsecmgr_tunnel_del(struct net_device *dev)
{
	struct nss_ipsecmgr_priv *priv = netdev_priv(dev);

	/*
	 * Flush all associated SA(s) and flow(s) with the tunnel
	 */
	write_lock_bh(&ipsecmgr_drv->lock);
	nss_ipsecmgr_ref_free(&priv->ref);
	write_unlock_bh(&ipsecmgr_drv->lock);

	/*
	 * The unregister should start here but the expectation is that the free would
	 * happen when the reference count goes down to '0'
	 */
	rtnl_is_locked() ? unregister_netdevice(dev) : unregister_netdev(dev);
}
EXPORT_SYMBOL(nss_ipsecmgr_tunnel_del);

/*
 * nss_ipsecmgr_tunnel_add()
 *	add a IPsec pseudo tunnel device
 */
struct net_device *nss_ipsecmgr_tunnel_add(struct nss_ipsecmgr_callback *cb)
{
	struct nss_ipsecmgr_priv *priv;
	struct net_device *dev;
	int status;

	dev = alloc_netdev(sizeof(*priv), NSS_IPSECMGR_TUN_NAME, NET_NAME_ENUM, nss_ipsecmgr_dev_setup);
	if (!dev) {
		nss_ipsecmgr_error("unable to allocate a tunnel device\n");
		return NULL;
	}

	priv = netdev_priv(dev);
	priv->dev = dev;
	memcpy(&priv->cb, cb, sizeof(priv->cb));
	memset(&priv->stats, 0, sizeof(priv->stats));

	/*
	 * Use Hlos netdev if it is loaded in the callback context;
	 * else use the NSS netdev
	 */
	if (!cb->skb_dev)
		priv->cb.skb_dev = dev;

	nss_ipsecmgr_ref_init(&priv->ref, NULL);

	status = rtnl_is_locked() ? register_netdevice(dev) : register_netdev(dev);
	if (status < 0) {
		nss_ipsecmgr_error("register net dev failed :%s\n", dev->name);
		free_netdev(dev);
		return NULL;
	}

	return dev;
}
EXPORT_SYMBOL(nss_ipsecmgr_tunnel_add);

/*
 * nss_ipsecmgr_dev_init()
 *	module init
 */
static int __init nss_ipsecmgr_dev_init(void)
{
	struct net_device *dev;
	int status;

	ipsecmgr_drv = vzalloc(sizeof(*ipsecmgr_drv));
	if (!ipsecmgr_drv) {
		nss_ipsecmgr_warn("Failed to allocate IPsec manager context");
		return -1;
	}

	ipsecmgr_drv->nss_ctx = nss_ipsec_get_context();
	if (!ipsecmgr_drv->nss_ctx) {
		nss_ipsecmgr_warn("%p: Failed to retrieve NSS context", ipsecmgr_drv);
		goto free;
	}

	dev = alloc_netdev(0, NSS_IPSECMGR_DEFAULT_TUN_NAME, NET_NAME_UNKNOWN, nss_ipsecmgr_dev_dummy_setup);
	if (!dev) {
		nss_ipsecmgr_warn("%p: Failed to allocate dummy netdevice", ipsecmgr_drv);
		goto free;
	}

	dev->netdev_ops = &nss_ipsecmgr_dummy_ndev_ops;

	status = register_netdev(dev);
	if (status) {
		nss_ipsecmgr_info("%p: Failed to register dummy netdevice(%p)", ipsecmgr_drv, dev);
		goto netdev_free;
	}

	ipsecmgr_drv->dev = dev;
	ipsecmgr_drv->data_ifnum = nss_ipsec_get_data_interface();
	ipsecmgr_drv->encap_ifnum = nss_ipsec_get_encap_interface();
	ipsecmgr_drv->decap_ifnum = nss_ipsec_get_decap_interface();

	rwlock_init(&ipsecmgr_drv->lock);
	nss_ipsecmgr_init_sa_db(ipsecmgr_drv->sa_db);
	nss_ipsecmgr_init_flow_db(ipsecmgr_drv->flow_db);

	nss_ipsec_data_register(ipsecmgr_drv->data_ifnum, nss_ipsecmgr_dev_rx, ipsecmgr_drv->dev, 0);
	nss_ipsec_notify_register(ipsecmgr_drv->encap_ifnum, nss_ipsecmgr_dev_rx_notify, ipsecmgr_drv);
	nss_ipsec_notify_register(ipsecmgr_drv->decap_ifnum, nss_ipsecmgr_dev_rx_notify, ipsecmgr_drv);

	/*
	 * Initialize debugfs.
	 */
	ipsecmgr_drv->dentry = debugfs_create_dir("qca-nss-ipsecmgr", NULL);
	if (!ipsecmgr_drv->dentry) {
		nss_ipsecmgr_warn("%p: Failed to create root debugfs entry", ipsecmgr_drv);
		goto unregister_dev;

	}

	nss_ipsecmgr_info("NSS IPsec manager loaded: %s\n", NSS_CLIENT_BUILD_ID);
	return 0;

unregister_dev:
	unregister_netdev(ipsecmgr_drv->dev);

netdev_free:
	free_netdev(ipsecmgr_drv->dev);

free:
	vfree(ipsecmgr_drv);
	ipsecmgr_drv = NULL;

	return -1;
}

/*
 * nss_ipsecmgr_dev_exit()
 *	module exit
 */
static void __exit nss_ipsecmgr_dev_exit(void)
{
	if (!ipsecmgr_drv) {
		nss_ipsecmgr_warn("IPsec manager driver context empty");
		return;
	}

	if (!ipsecmgr_drv->nss_ctx) {
		nss_ipsecmgr_warn("%p: NSS Context empty", ipsecmgr_drv);
		goto free;
	}

	/*
	 * Unregister the callbacks from the HLOS as we are no longer
	 * interested in exception data & async messages
	 */
	nss_ipsec_data_unregister(ipsecmgr_drv->nss_ctx, ipsecmgr_drv->data_ifnum);

	nss_ipsec_notify_unregister(ipsecmgr_drv->nss_ctx, ipsecmgr_drv->encap_ifnum);
	nss_ipsec_notify_unregister(ipsecmgr_drv->nss_ctx, ipsecmgr_drv->decap_ifnum);

	unregister_netdev(ipsecmgr_drv->dev);

	/*
	 * Remove debugfs directory and entries below that.
	 */
	debugfs_remove_recursive(ipsecmgr_drv->dentry);

free:
	/*
	 * Free the ipsecmgr ctx
	 */
	vfree(ipsecmgr_drv);
	ipsecmgr_drv = NULL;

	nss_ipsecmgr_info("NSS IPsec manager unloaded\n");

}

MODULE_LICENSE("Dual BSD/GPL");

module_init(nss_ipsecmgr_dev_init);
module_exit(nss_ipsecmgr_dev_exit);
