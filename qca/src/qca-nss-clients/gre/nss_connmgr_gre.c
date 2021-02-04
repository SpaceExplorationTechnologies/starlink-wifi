/*
 **************************************************************************
 * Copyright (c) 2017 The Linux Foundation. All rights reserved.
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
 * nss_connnmgr_gre.c
 *  This file implements client for GRE.
 */

#include <linux/version.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <net/ip_tunnels.h>
#include <net/ip6_tunnel.h>
#include <linux/if_ether.h>
#include <net/gre.h>
#include <net/ip.h>

#include <nss_api_if.h>
#include <nss_dynamic_interface.h>

#include "nss_connmgr_gre_public.h"
#include "nss_connmgr_gre.h"

#define MAX_RETRY_COUNT 100
#define MAX_WIFI_HEADROOM 66

/*
 * netdevice notifier is disabled by default
 */
static bool enable_notifier;
module_param(enable_notifier, bool, 0);

/*
 * nss_connmgr_gre_dev_change_mtu()
 *	Netdev ops function to modify MTU of netdevice.
 */
static int nss_connmgr_gre_dev_change_mtu(struct net_device *dev, int new_mtu)
{
	if (new_mtu < 68 ||
	    new_mtu > 0xFFF8 - dev->needed_headroom) {
		return -EINVAL;
	}

	dev->mtu = new_mtu;
	return 0;
}

/*
 * nss_connmgr_gre_dev_init()
 *	Netdev ops function to intialize netdevice.
 */
static int nss_connmgr_gre_dev_init(struct net_device *dev)
{
	int i;
	nss_connmgr_gre_priv_t *priv = netdev_priv(dev);
	int32_t append = priv->pad_len + priv->gre_hlen;

	dev->tstats = alloc_percpu(struct pcpu_sw_netstats);
	if (!dev->tstats) {
		return -ENOMEM;
	}

	for_each_possible_cpu(i) {
		struct pcpu_sw_netstats *stats;
		stats = per_cpu_ptr(dev->tstats, i);
		u64_stats_init(&stats->syncp);
	}

	if ((dev->priv_flags & IFF_GRE_V4_TAP) || (dev->type == ARPHRD_IPGRE)) {
		dev->needed_headroom = sizeof(struct iphdr) + sizeof(struct ethhdr) + MAX_WIFI_HEADROOM + append;
		dev->mtu = ETH_DATA_LEN - sizeof(struct iphdr) - append;
		dev->features |= NETIF_F_NETNS_LOCAL | NETIF_F_SG | NETIF_F_FRAGLIST | NETIF_F_HIGHDMA;
		dev->hw_features |= NETIF_F_SG | NETIF_F_FRAGLIST | NETIF_F_HIGHDMA;
		return 0;
	}

	/*
	 * Ipv6
	 */
	dev->needed_headroom = sizeof(struct ipv6hdr) + sizeof(struct ethhdr) + MAX_WIFI_HEADROOM + append;
	dev->mtu = ETH_DATA_LEN - sizeof(struct ipv6hdr) - append;
	if (dev->mtu < IPV6_MIN_MTU) {
		dev->mtu = IPV6_MIN_MTU;
	}

	dev->features |= NETIF_F_NETNS_LOCAL;
	return 0;
}

/*
 * nss_connmgr_gre_dev_uninit()
 *	Netdev ops function to unintialize netdevice.
 */
static void nss_connmgr_gre_dev_uninit(struct net_device *dev)
{
	free_percpu(dev->tstats);
	return;
}

/*
 * nss_connmgr_gre_dev_xmit()
 *	Netdev ops function to send packet to NSS.
 */
static netdev_tx_t nss_connmgr_gre_dev_xmit(struct sk_buff *skb, struct net_device *dev)
{
	nss_tx_status_t status;
	int if_number;
	struct nss_ctx_instance *gre_ctx;
	nss_connmgr_gre_priv_t *priv = netdev_priv(dev);

	if_number = priv->nss_if_number;
	if (unlikely(if_number <= 0)) {
		nss_connmgr_gre_info("%p: GRE dev is not registered with nss\n", dev);
		goto fail;
	}

	gre_ctx = nss_gre_get_context();
	if (unlikely(!gre_ctx)) {
		nss_connmgr_gre_info("%p: NSS GRE context not found for if_number %d\n", dev, if_number);
		goto fail;
	}

	/*
	 * Make room for needed headroom and un-share
	 * the SKB if it is cloned.
	 */
	if (skb_cow_head(skb, dev->needed_headroom)) {
		nss_connmgr_gre_info("%p: NSS GRE insufficient headroom\n", dev);
		goto fail;
	}

	status = nss_gre_tx_buf(gre_ctx, if_number, skb);
	if (unlikely(status != NSS_TX_SUCCESS)) {
		nss_connmgr_gre_info("%p: NSS GRE could not send packet to NSS %d\n", dev, if_number);
		goto fail;
	}

	return NETDEV_TX_OK;

fail:
	dev->stats.tx_dropped++;
	dev_kfree_skb_any(skb);
	return NETDEV_TX_OK;
}

/*
 * nss_connmgr_gre_dev_stats64()
 *	Netdev ops function to retrieve stats.
 */
struct rtnl_link_stats64 *nss_connmgr_gre_dev_stats64(struct net_device *dev,
						struct rtnl_link_stats64 *tot)
{
	uint64_t rx_packets, rx_bytes, tx_packets, tx_bytes;
	unsigned int start;
	int i;
	for_each_possible_cpu(i) {
		const struct pcpu_sw_netstats *tstats = per_cpu_ptr(dev->tstats, i);

		do {
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3, 15, 0))
			start = u64_stats_fetch_begin_bh(&tstats->syncp);
#else
			start = u64_stats_fetch_begin_irq(&tstats->syncp);
#endif
			rx_packets = tstats->rx_packets;
			tx_packets = tstats->tx_packets;
			rx_bytes = tstats->rx_bytes;
			tx_bytes = tstats->tx_bytes;
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3, 15, 0))
		} while (u64_stats_fetch_retry_bh(&tstats->syncp, start));
#else
		} while (u64_stats_fetch_retry_irq(&tstats->syncp, start));
#endif

		tot->rx_packets += rx_packets;
		tot->tx_packets += tx_packets;
		tot->rx_bytes   += rx_bytes;
		tot->tx_bytes   += tx_bytes;

		tot->rx_dropped = dev->stats.rx_dropped;
		tot->tx_dropped = dev->stats.tx_dropped;
	}

	return tot;
}

/*
 * nss_connmgr_gre_dev_open()
 *	Netdev ops function to open netdevice.
 */
static int nss_connmgr_gre_dev_open(struct net_device *dev)
{
	struct nss_ctx_instance *nss_ctx;
	struct nss_gre_msg req;
	struct nss_gre_linkup_msg *linkup = &req.msg.linkup;
	nss_tx_status_t status;

	int if_number = nss_cmn_get_interface_number_by_dev(dev);
	if (if_number < 0) {
		return -EINVAL;
	}

	nss_ctx = nss_gre_get_context();

	memset(&req, 0, sizeof(struct nss_gre_msg));
	linkup->if_number = if_number;
	nss_gre_msg_init(&req, if_number, NSS_IF_OPEN, sizeof(struct nss_gre_linkup_msg), NULL, NULL);

	status = nss_gre_tx_msg_sync(nss_ctx, &req);
	if (status == NSS_TX_SUCCESS) {
		netif_start_queue(dev);
		return 0;
	}

	nss_connmgr_gre_info("%p: open failed for interface %s", dev, dev->name);
	return -EFAULT;
}

/*
 * nss_connmgr_gre_dev_close()
 *	Netdevice ops function to close netdevice.
 */
static int nss_connmgr_gre_dev_close(struct net_device *dev)
{
	struct nss_ctx_instance *nss_ctx;
	struct nss_gre_msg req;
	struct nss_gre_linkdown_msg *linkdown = &req.msg.linkdown;
	nss_tx_status_t status;
	int if_number;

	netif_stop_queue(dev);

	if_number = nss_cmn_get_interface_number_by_dev(dev);
	if (if_number < 0) {
		return -EINVAL;
	}

	nss_ctx = nss_gre_get_context();

	memset(&req, 0, sizeof(struct nss_gre_msg));
	linkdown->if_number = if_number;
	nss_gre_msg_init(&req, if_number, NSS_IF_CLOSE, sizeof(struct nss_gre_linkdown_msg), NULL, NULL);

	status = nss_gre_tx_msg_sync(nss_ctx, &req);
	if (status == NSS_TX_SUCCESS) {
		return 0;
	}

	nss_connmgr_gre_info("%p: close failed for interface %s", dev, dev->name);
	return -EFAULT;
}

/*
 * Tap net device ops
 */
static const struct net_device_ops nss_connmgr_gre_tap_ops = {
	.ndo_init = nss_connmgr_gre_dev_init,
	.ndo_uninit = nss_connmgr_gre_dev_uninit,
	.ndo_open = nss_connmgr_gre_dev_open,
	.ndo_stop = nss_connmgr_gre_dev_close,
	.ndo_set_mac_address = eth_mac_addr,
	.ndo_validate_addr = eth_validate_addr,
	.ndo_change_mtu	= nss_connmgr_gre_dev_change_mtu,
	.ndo_start_xmit = nss_connmgr_gre_dev_xmit,
	.ndo_get_stats64 = nss_connmgr_gre_dev_stats64,
};

/*
 * Tun netdevice ops
 */
static const struct net_device_ops nss_connmgr_gre_tun_ops = {
	.ndo_init = nss_connmgr_gre_dev_init,
	.ndo_uninit = nss_connmgr_gre_dev_uninit,
	.ndo_open = nss_connmgr_gre_dev_open,
	.ndo_stop = nss_connmgr_gre_dev_close,
	.ndo_change_mtu	= nss_connmgr_gre_dev_change_mtu,
	.ndo_start_xmit = nss_connmgr_gre_dev_xmit,
	.ndo_get_stats64 = nss_connmgr_gre_dev_stats64,
};

/*
 * nss_connmgr_gre_tun_setup()
 */
static void nss_connmgr_gre_tun_setup(struct net_device *dev)
{
	dev->addr_len = 4;
	dev->flags = IFF_NOARP | IFF_POINTOPOINT;
	dev->priv_flags	&= ~IFF_XMIT_DST_RELEASE;
	dev->netdev_ops = &nss_connmgr_gre_tun_ops;
}

/*
 * nss_connmgr_gre_tap_setup()
 */
static void nss_connmgr_gre_tap_setup(struct net_device *dev)
{
	dev->netdev_ops = &nss_connmgr_gre_tap_ops;
	eth_hw_addr_random(dev);
}

/*
 * nss_connmgr_gre_prepare_config_cmd()
 *	Retrieve info from netdevie and fill it in config message to NSS.
 */
static int32_t nss_connmgr_gre_prepare_config_cmd(struct net_device *dev,
						      struct nss_gre_msg *req,
						      struct net_device **next_dev,
						      bool hold)
{
	struct nss_gre_config_msg *cmsg = &req->msg.cmsg;

	if ((dev->type == ARPHRD_ETHER) && (dev->priv_flags & IFF_GRE_V4_TAP)) {
		cmsg->mode = NSS_GRE_MODE_TAP;
		cmsg->ip_type = NSS_GRE_IP_IPV4;
		return nss_connmgr_gre_v4_get_config(dev, req, next_dev, hold);
	}

	if ((dev->type == ARPHRD_ETHER) && (dev->priv_flags & IFF_GRE_V6_TAP)) {
		cmsg->mode = NSS_GRE_MODE_TAP;
		cmsg->ip_type = NSS_GRE_IP_IPV6;
		return nss_connmgr_gre_v6_get_config(dev, req, next_dev, hold);
	}

	if (dev->type == ARPHRD_IPGRE) {
		cmsg->mode = NSS_GRE_MODE_TUN;
		cmsg->ip_type = NSS_GRE_IP_IPV4;
		return nss_connmgr_gre_v4_get_config(dev, req, next_dev, hold);
	}

	if (dev->type == ARPHRD_IP6GRE) {
		cmsg->mode = NSS_GRE_MODE_TUN;
		cmsg->ip_type = NSS_GRE_IP_IPV6;
		return nss_connmgr_gre_v6_get_config(dev, req, next_dev, hold);
	}

	return GRE_ERR_NOT_GRE_NETDEV;
}

/*
 * nss_connmgr_gre_exception()
 */
static void nss_connmgr_gre_exception(struct net_device *dev, struct sk_buff *skb,
					  __attribute__((unused)) struct napi_struct *napi)
{

	struct ethhdr *eth_hdr;
	if (unlikely(!enable_notifier)) {
		nss_connmgr_gre_error("%p: NSS GRE exception handler called\n", dev);
		dev_kfree_skb_any(skb);
		return;
	}

	if (unlikely(!pskb_may_pull(skb, sizeof(struct ethhdr)))) {
		nss_connmgr_gre_warning("%p: pskb_may_pull failed for skb:%p\n", dev, skb);
		dev_kfree_skb_any(skb);
		return;
	}
	eth_hdr = (struct ethhdr *)skb->data;
	if (likely(ntohs(eth_hdr->h_proto) >= ETH_P_802_3_MIN)) {
		switch (ntohs(eth_hdr->h_proto)) {
		case ETH_P_IP:
			if (unlikely(!pskb_may_pull(skb, sizeof(struct iphdr)))) {
				nss_connmgr_gre_warning("%p: pskb_may_pull failed for skb:%p\n", dev, skb);
				dev_kfree_skb_any(skb);
				return;
			}
			return nss_connmgr_gre_v4_exception(dev, skb);
		case ETH_P_IPV6:
			if (unlikely(!pskb_may_pull(skb, sizeof(struct ipv6hdr)))) {
				nss_connmgr_gre_warning("%p: pskb_may_pull failed for skb:%p\n", dev, skb);
				dev_kfree_skb_any(skb);
				return;
			}
			return nss_connmgr_gre_v6_exception(dev, skb);
		default:
			break;
		}
	}

	/*
	 * These are decapped and exceptioned non IP packets.
	 */
	skb->protocol = eth_type_trans(skb, dev);
	netif_receive_skb(skb);
	return;
}

/*
 * nss_connmgr_gre_rx_pkt()
 *	GRE Tap function to receive packet from NSS.
 */
static void nss_connmgr_gre_rx_pkt(struct net_device *dev, struct sk_buff *skb,
				       __attribute__((unused)) struct napi_struct *napi)
{
	skb->dev = dev;
	skb->protocol = eth_type_trans(skb, dev);
	netif_receive_skb(skb);
}

/*
 * nss_connmgr_gre_event_receive()
 *	Event Callback to receive events from NSS
 */
static void nss_connmgr_gre_event_receive(void *if_ctx, struct nss_gre_msg *tnlmsg)
{
	struct net_device *dev = if_ctx;
	struct nss_cmn_node_stats *stats = &tnlmsg->msg.sstats.node_stats;
	struct pcpu_sw_netstats *tstats;

	switch (tnlmsg->cm.type) {
	case NSS_GRE_MSG_SESSION_STATS:
		dev->stats.rx_packets += stats->rx_packets;
		dev->stats.rx_bytes += stats->rx_bytes;
		dev->stats.tx_packets += stats->tx_packets;
		dev->stats.tx_bytes += stats->tx_bytes;
		dev->stats.rx_dropped += nss_cmn_rx_dropped_sum(stats);

		tstats = this_cpu_ptr(dev->tstats);
		u64_stats_update_begin(&tstats->syncp);
		tstats->rx_packets += stats->rx_packets;
		tstats->rx_bytes += stats->rx_bytes;
		tstats->tx_packets += stats->tx_packets;
		tstats->tx_bytes += stats->tx_bytes;
		u64_stats_update_end(&tstats->syncp);
		break;

	case NSS_GRE_MSG_BASE_STATS:
		break;

	default:
		nss_connmgr_gre_info("%p: Unknown Event from NSS\n", dev);
		break;
	}
}

/*
 * nss_connmgr_gre_is_gre()
 *	Check whether device is of type GRE Tap or GRE Tun.
 */
static bool nss_connmgr_gre_is_gre(struct net_device *dev)
{
	if ((dev->type == ARPHRD_IPGRE) ||
	      (dev->type == ARPHRD_IP6GRE) || ((dev->type == ARPHRD_ETHER) &&
	      (dev->priv_flags & (IFF_GRE_V4_TAP | IFF_GRE_V6_TAP)))) {
		return true;
	}

	return false;
}

/*
 * nss_connmgr_gre_make_name()
 *	Generate a name for netdevice if user does not provide one.
 */
static void nss_connmgr_gre_make_name(struct nss_connmgr_gre_cfg *cfg, char *name)
{
	switch (cfg->mode) {
	case GRE_MODE_TUN:
		strlcpy(name, "tun-%d", IFNAMSIZ);
		break;
	case GRE_MODE_TAP:
		strlcpy(name, "tap-%d", IFNAMSIZ);
		break;
	default:
		break;
	}
}

/*
 * __nss_connmgr_gre_create_interface()
 *	Creates GRE Tap/Tun netdevice and configure GRE node in NSS.
 *	This should be called after acquiring rtnl_lock().
 */
static struct net_device *__nss_connmgr_gre_create_interface(struct nss_connmgr_gre_cfg *cfg,
							     enum nss_connmgr_gre_err_codes *err_code)
{
	struct net_device *dev = NULL;
	int ret = -1;
	struct nss_gre_msg req;
	struct nss_gre_config_msg *cmsg = &req.msg.cmsg;
	int if_number;
	uint32_t features = 0;
	struct nss_ctx_instance *nss_ctx;
	nss_tx_status_t status;
	char name[IFNAMSIZ] = {0};
	nss_connmgr_gre_priv_t *priv;
	int retry = 0;
	struct net_device *next_dev = NULL;

	if (cfg->name) {
		strlcpy(name, cfg->name, IFNAMSIZ);
	} else {
		nss_connmgr_gre_make_name(cfg, name);
	}

	switch (cfg->mode) {
	case GRE_MODE_TUN:
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3, 17, 0))
		dev = alloc_netdev(sizeof(nss_connmgr_gre_priv_t), name, nss_connmgr_gre_tun_setup);
#else
		dev = alloc_netdev(sizeof(nss_connmgr_gre_priv_t), name, NET_NAME_UNKNOWN, nss_connmgr_gre_tun_setup);
#endif

		if (!dev) {
			nss_connmgr_gre_warning("Allocation of netdev failed\n");
			*err_code = GRE_ERR_ALLOC_NETDEV;
			return NULL;
		}

		if (cfg->is_ipv6) {
			dev->type = ARPHRD_IP6GRE;
			ret = nss_connmgr_gre_v6_set_config(dev, cfg);
		} else {
			dev->type = ARPHRD_IPGRE;
			ret = nss_connmgr_gre_v4_set_config(dev, cfg);
		}

		break;

	case GRE_MODE_TAP:
		dev = alloc_etherdev(sizeof(nss_connmgr_gre_priv_t));
		if (!dev) {
			nss_connmgr_gre_warning("Allocation of netdev failed\n");
			*err_code = GRE_ERR_ALLOC_NETDEV;
			return NULL;
		}

		nss_connmgr_gre_tap_setup(dev);

		if (cfg->is_ipv6) {
			dev->priv_flags |= IFF_GRE_V6_TAP;
			ret = nss_connmgr_gre_v6_set_config(dev, cfg);
		} else {
			dev->priv_flags |= IFF_GRE_V4_TAP;
			ret = nss_connmgr_gre_v4_set_config(dev, cfg);
		}
		break;

	default:
		nss_connmgr_gre_warning("Please Specify gre mode\n");
		*err_code = GRE_ERR_INVALID_MODE;
		goto err1;
	}

	if (ret) {
		nss_connmgr_gre_warning("%p: gre interface configuration failed\n", dev);
		*err_code = ret;
		goto err1;
	}

	/*
	 * Set name
	 */
	memcpy(dev->name, name, IFNAMSIZ);

	/*
	 * Create config cmd for acceleration engine
	 */
	memset(&req, 0, sizeof(struct nss_gre_msg));
	ret = nss_connmgr_gre_prepare_config_cmd(dev, &req, &next_dev, true);
	if (ret) {
		nss_connmgr_gre_warning("%p: gre get config failed\n", dev);
		*err_code = ret;
		goto err1;
	}

	/*
	 *  Replace MAC addr and next node with user provided entries.
	 */
	if (cfg->use_mac_hdr) {
		memcpy(cmsg->src_mac, cfg->src_mac, ETH_ALEN);
		memcpy(cmsg->dest_mac, cfg->dest_mac, ETH_ALEN);
		cmsg->flags |= NSS_GRE_CONFIG_SET_MAC;
	}

	/*
	 * By now, we should have valid MAC addresses
	 */
	if (!is_valid_ether_addr((const u8 *)cmsg->src_mac) ||
	    !is_valid_ether_addr((const u8 *)cmsg->dest_mac)) {
		nss_connmgr_gre_warning("%p: Could not find MAC address for src/dest IP\n", dev);
		*err_code = GRE_ERR_INVALID_MAC;
		goto err1;
	}

	if (cfg->next_dev) {

		if (next_dev) {
			dev_put(next_dev);
		}

		dev_hold(cfg->next_dev);
		cmsg->next_node_if_num = nss_cmn_get_interface_number_by_dev(cfg->next_dev);
		next_dev = cfg->next_dev;

		if (cmsg->next_node_if_num < 0) {
			nss_connmgr_gre_warning("%p: Next dev = %s is not registered with ae engine\n",
						dev, cfg->next_dev->name);
			*err_code = GRE_ERR_NEXT_NODE_UNREG_IN_AE;
			goto err1;
		}
		cmsg->flags |= NSS_GRE_CONFIG_NEXT_NODE_AVAILABLE;
	}

	/*
	 * By now, we should have a valid next node
	 */
	if (!(cmsg->flags & NSS_GRE_CONFIG_NEXT_NODE_AVAILABLE)) {
		nss_connmgr_gre_warning("%p: Next dev is not available\n", dev);
		*err_code = GRE_ERR_NO_NEXT_NETDEV;
		goto err1;
	}

	if (cfg->add_padding) {
		cmsg->flags |= NSS_GRE_CONFIG_SET_PADDING;
	}

	if (cfg->copy_metadata) {
		cmsg->flags |= NSS_GRE_CONFIG_COPY_METADATA;
		cmsg->metadata_size = sizeof(struct nss_wifi_append_statsv2_metahdr);
	}

	/*
	 * Register net_device
	 */
	ret = register_netdevice(dev);
	if (ret) {
		*err_code = GRE_ERR_NETDEV_REG_FAILED;
		nss_connmgr_gre_warning("%p: Netdevice registration failed\n", dev);
		goto err1;
	}

	/*
	 * Create nss dynamic interface
	 */
	if_number = nss_dynamic_interface_alloc_node(NSS_DYNAMIC_INTERFACE_TYPE_GRE);
	if (if_number < 0) {
		nss_connmgr_gre_warning("%p: Request interface number failed\n", dev);
		*err_code = GRE_ERR_DYNMAIC_IFACE_CREATE;
		goto err2;
	}

	priv = (nss_connmgr_gre_priv_t *)netdev_priv(dev);
	priv->nss_if_number = if_number;
	priv->next_dev = next_dev;

	/*
	 * Register gre tunnel with NSS
	 */
	nss_ctx = nss_gre_register_if(if_number,
				       nss_connmgr_gre_rx_pkt,
				       nss_connmgr_gre_event_receive,
				       dev,
				       features);
	if (!nss_ctx) {
		nss_connmgr_gre_info("%p: nss_register_gre_if failed\n", dev);
		*err_code = GRE_ERR_GRE_IFACE_REG;
		goto err3;
	}
	nss_connmgr_gre_info("%p: nss_register_gre_if() successful. nss_ctx = %p\n", dev, nss_ctx);

	/*
	 * Send config to AE
	 */
	nss_gre_msg_init(&req, if_number, NSS_GRE_MSG_CONFIGURE, sizeof(struct nss_gre_config_msg), NULL, NULL);
	status = nss_gre_tx_msg_sync(nss_ctx, &req);
	if (status != NSS_TX_SUCCESS) {
		*err_code = GRE_ERR_AE_CONFIG_FAILED;
		goto err4;
	}

	/*
	 * Set vap next hop
	 */
	ret = nss_connmgr_gre_set_wifi_next_hop(cfg->next_dev);
	if (ret) {
		nss_connmgr_gre_info("%p: Setting next hop of wifi vdev failed\n", dev);
		*err_code = ret;
		goto err4;
	}

	/*
	 * Success
	 */
	*err_code = GRE_SUCCESS;
	return dev;

err4:
	nss_gre_unregister_if(if_number);

err3:
	status = nss_dynamic_interface_dealloc_node(if_number, NSS_DYNAMIC_INTERFACE_TYPE_GRE);
	if (status != NSS_TX_SUCCESS) {
		if (++retry <= MAX_RETRY_COUNT) {
			goto err3;
		}
		nss_connmgr_gre_error("%p: Fatal Error, Unable to dealloc the node[%d] in the NSS FW!\n", dev, if_number);
	}

err2:
	unregister_netdevice(dev);

err1:
	if (next_dev) {
		dev_put(next_dev);
	}

	return dev;
}

/*
 * __nss_connmgr_gre_destroy_interface()
 *	Destroy GRE Tap/Tun netdevice. Acquire rtnl_lock() before calling this
 *	function.
 */
static enum nss_connmgr_gre_err_codes __nss_connmgr_gre_destroy_interface(struct net_device *dev)
{
	struct nss_gre_msg req;
	struct nss_gre_deconfig_msg *dmsg;
	int if_number;
	nss_tx_status_t status;
	int retry = 0;
	nss_connmgr_gre_priv_t *priv;

	netif_tx_disable(dev);

	/*
	 * Decrement ref to next_dev
	 */
	priv = (nss_connmgr_gre_priv_t *)netdev_priv(dev);
	dev_put(priv->next_dev);

	/*
	 * Check if gre-std interface is registered with NSS
	 */
	if_number = nss_cmn_get_interface_number_by_dev(dev);
	if (if_number < 0) {
		nss_connmgr_gre_info("%p: Net device is not registered with nss\n", dev);
		return GRE_ERR_NODE_UNREG_IN_AE;
	}

retry_deconfig:
	memset(&req, 0, sizeof(struct nss_gre_msg));
	dmsg = &req.msg.dmsg;
	dmsg->if_number = if_number;
	nss_gre_msg_init(&req, if_number, NSS_GRE_MSG_DECONFIGURE, sizeof(struct nss_gre_deconfig_msg), NULL, NULL);
	status = nss_gre_tx_msg_sync(nss_gre_get_context(), &req);
	if (status != NSS_TX_SUCCESS) {
		nss_connmgr_gre_info("%p: gre instance deconfigure command failed, if_number = %d\n", dev, if_number);

		if (++retry <= MAX_RETRY_COUNT) {
			goto retry_deconfig;
		}

		nss_connmgr_gre_error("%p: Fatal Error, failed to send GRE deconfig command to NSS\n", dev);
		return GRE_ERR_AE_DECONFIG_FAILED;
	}

	nss_gre_unregister_if(if_number);
	retry = 0;

retry_dealloc:
	status = nss_dynamic_interface_dealloc_node(if_number, NSS_DYNAMIC_INTERFACE_TYPE_GRE);
	if (status != NSS_TX_SUCCESS) {
		nss_connmgr_gre_info("%p: gre dealloc node failure for if_number = %d\n", dev, if_number);

		if (++retry <= MAX_RETRY_COUNT) {
			goto retry_dealloc;
		}

		nss_connmgr_gre_error("%p: Fatal Error, failed to send GRE dealloc command to NSS\n", dev);
		return GRE_ERR_DYNMAIC_IFACE_DESTROY;
	}

	nss_connmgr_gre_info("%p: deleting gre instance, if_number = %d\n", dev, if_number);
	unregister_netdevice(dev);
	return GRE_SUCCESS;
}

/*
 * nss_connmgr_gre_validate_config()
 *	No support for KEY, CSUM, SEQ number
 */
static bool nss_connmgr_gre_validate_config(struct nss_connmgr_gre_cfg *cfg)
{
	if (cfg->ikey_valid || cfg->okey_valid || cfg->iseq_valid ||
	    cfg->oseq_valid || cfg->icsum_valid || cfg->ocsum_valid) {
		return false;
	}

	return true;
}

/*
 * nss_connmgr_gre_dev_up()
 *	Netdevice notifier call back to configure NSS for GRE Tap/Tun device.
 */
static int nss_connmgr_gre_dev_up(struct net_device *dev)
{
	struct nss_gre_msg req;
	struct nss_gre_config_msg *cmsg = &req.msg.cmsg;
	int if_number;
	uint32_t features = 0;
	struct nss_ctx_instance *nss_ctx;
	nss_tx_status_t status;
	struct net_device *next_dev = NULL;

	if (!nss_connmgr_gre_is_gre(dev)) {
		nss_connmgr_gre_info("%p: No GRE net_device found\n", dev);
		return NOTIFY_DONE;
	}

	/*
	 * Create config cmd for acceleration engine
	 */
	if (nss_connmgr_gre_prepare_config_cmd(dev, &req, &next_dev, false)) {
		nss_connmgr_gre_info("%p: gre tunnel get config failed\n", dev);
		return NOTIFY_DONE;
	}

	/*
	 * Ignore set_mac and next_dev flags for generic GRE
	 */
	cmsg->flags &= ~(NSS_GRE_CONFIG_SET_MAC | NSS_GRE_CONFIG_NEXT_NODE_AVAILABLE);

	/*
	 * Create nss dynamic interface and register
	 */
	if_number = nss_dynamic_interface_alloc_node(NSS_DYNAMIC_INTERFACE_TYPE_GRE);
	if (if_number < 0) {
		nss_connmgr_gre_warning("%p: Request interface number failed\n", dev);
		return NOTIFY_DONE;
	}

	/*
	 * Register gre tunnel with NSS
	 */
	nss_ctx = nss_gre_register_if(if_number,
				       nss_connmgr_gre_exception,
				       nss_connmgr_gre_event_receive,
				       dev,
				       features);

	if (!nss_ctx) {
		status = nss_dynamic_interface_dealloc_node(if_number, NSS_DYNAMIC_INTERFACE_TYPE_GRE);
		if (status != NSS_TX_SUCCESS) {
			nss_connmgr_gre_info("%p: Unable to dealloc the node[%d] in the NSS FW!\n", dev, if_number);
		}
		nss_connmgr_gre_info("%p: nss_register_gre_if failed\n", dev);
		return NOTIFY_DONE;
	}

	nss_connmgr_gre_info("%p: nss_register_gre_if() successful. nss_ctx = %p\n", dev, nss_ctx);

	if (nss_connmgr_gre_dev_open(dev)) {
		nss_gre_unregister_if(if_number);
		status = nss_dynamic_interface_dealloc_node(if_number, NSS_DYNAMIC_INTERFACE_TYPE_GRE);
		if (status != NSS_TX_SUCCESS) {
			nss_connmgr_gre_warning("%p: Unable to dealloc the node[%d] in the NSS fw!\n", dev, if_number);
		}
		nss_connmgr_gre_warning("%p: nss gre std device up command failed %d\n", dev, status);
		return NOTIFY_DONE;
	}

	nss_gre_msg_init(&req, if_number, NSS_GRE_MSG_CONFIGURE, sizeof(struct nss_gre_config_msg), NULL, NULL);

	status = nss_gre_tx_msg_sync(nss_ctx, &req);
	if (status != NSS_TX_SUCCESS) {
		nss_gre_unregister_if(if_number);
		status = nss_dynamic_interface_dealloc_node(if_number, NSS_DYNAMIC_INTERFACE_TYPE_GRE);
		if (status != NSS_TX_SUCCESS) {
			nss_connmgr_gre_warning("%p: Unable to dealloc the node[%d] in the NSS fw!\n", dev, if_number);
		}
		nss_connmgr_gre_warning("%p: nss gre std configure command error %d\n", dev, status);
		return NOTIFY_DONE;
	}

	return NOTIFY_DONE;
}

/*
 * nss_connmgr_gre_dev_down()
 *	Netdevice notifier call back to destroy GRE interface in NSS.
 */
static int nss_connmgr_gre_dev_down(struct net_device *dev)
{
	struct nss_gre_msg req;
	struct nss_gre_deconfig_msg *dmsg;
	int if_number;
	nss_tx_status_t status;

	if (!nss_connmgr_gre_is_gre(dev)) {
		nss_connmgr_gre_info("%p: No GRE net_device found\n", dev);
		return NOTIFY_DONE;
	}

	/*
	 * Check if gre-std interface is registered with NSS
	 */
	if_number = nss_cmn_get_interface_number_by_dev(dev);
	if (if_number < 0) {
		nss_connmgr_gre_info("%p: Net device is not registered with nss\n", dev);
		return NOTIFY_DONE;
	}

	memset(&req, 0, sizeof(struct nss_gre_msg));
	dmsg = &req.msg.dmsg;
	dmsg->if_number = if_number;
	nss_gre_msg_init(&req, if_number, NSS_GRE_MSG_DECONFIGURE, sizeof(struct nss_gre_deconfig_msg), NULL, NULL);
	status = nss_gre_tx_msg_sync(nss_gre_get_context(), &req);
	if (status != NSS_TX_SUCCESS) {
		nss_connmgr_gre_info("%p: gre instance deconfigure command failed, if_number = %d\n", dev, if_number);
		return NOTIFY_DONE;
	}

	if (nss_connmgr_gre_dev_close(dev)) {
		nss_connmgr_gre_info("%p: gre instance device close command failed, if_number = %d\n", dev, if_number);
		return NOTIFY_DONE;
	}

	nss_gre_unregister_if(if_number);
	status = nss_dynamic_interface_dealloc_node(if_number, NSS_DYNAMIC_INTERFACE_TYPE_GRE);
	if (status != NSS_TX_SUCCESS) {
		nss_connmgr_gre_info("%p: gre dealloc node failure for if_number = %d\n", dev, if_number);
		return NOTIFY_DONE;
	}
	nss_connmgr_gre_info("%p: deleting gre instance, if_number = %d\n", dev, if_number);
	return NOTIFY_DONE;
}

/*
 * nss_connmgr_gre_dev_event()
 *	Netdevice notifier call back function.
 */
static int nss_connmgr_gre_dev_event(struct notifier_block  *nb,
		unsigned long event, void  *dev)
{
	struct net_device *netdev;
	netdev = netdev_notifier_info_to_dev(dev);

	switch (event) {
	case NETDEV_UP:
		return nss_connmgr_gre_dev_up(netdev);

	case NETDEV_DOWN:
		return nss_connmgr_gre_dev_down(netdev);

	default:
		break;
	}

	return NOTIFY_DONE;
}

/*
 * Linux Net device Notifier
 */
static struct notifier_block nss_connmgr_gre_notifier = {
	.notifier_call = nss_connmgr_gre_dev_event,
};

/*
 * nss_connmgr_gre_dev_init_module()
 *	Tunnel gre module init function
 */
static int __init nss_connmgr_gre_dev_init_module(void)
{
#ifdef CONFIG_OF
	/*
	 * If the node is not compatible, don't do anything.
	 */
	if (!of_find_node_by_name(NULL, "nss-common")) {
		return 0;
	}
#endif
	if (enable_notifier) {
		register_netdevice_notifier(&nss_connmgr_gre_notifier);
	}

	return 0;
}

/*
 * nss_connmgr_gre_exit_module
 *	Tunnel gre module exit function
 */
static void __exit nss_connmgr_gre_exit_module(void)
{
#ifdef CONFIG_OF
	/*
	 * If the node is not compatible, don't do anything.
	 */
	if (!of_find_node_by_name(NULL, "nss-common")) {
		return;
	}
#endif
	if (enable_notifier) {
		unregister_netdevice_notifier(&nss_connmgr_gre_notifier);
	}

}

/*
 * nss_connmgr_gre_set_next_hop()
 *	Function changes next hop of wifi_vdev to NSS_GRE_INTERFACE
 */
int nss_connmgr_gre_set_wifi_next_hop(struct net_device *wifi_vdev)
{
	nss_tx_status_t status;
	void *ctx;
	int ifnumber;

	if (!wifi_vdev) {
		nss_connmgr_gre_info("wifi interface is NULL\n");
		return GRE_ERR_NO_NEXT_NETDEV;
	}

	ifnumber = nss_cmn_get_interface_number_by_dev(wifi_vdev);
	if (ifnumber < 0) {
		nss_connmgr_gre_info("%p: wifi interface is not recognized by NSS\n", wifi_vdev);
		return GRE_ERR_NEXT_NODE_UNREG_IN_AE;
	}

	ctx = nss_wifi_get_context();
	status = nss_wifi_vdev_set_next_hop(ctx, ifnumber, NSS_GRE_INTERFACE);
	if (status != NSS_TX_SUCCESS) {
		nss_connmgr_gre_info("%p: wifi drv api failed to set next hop\n", wifi_vdev);
		return GRE_ERR_AE_SET_NEXT_HOP;
	}

	return GRE_SUCCESS;
}

/*
 * nss_connmgr_gre_get_hlen()
 *	Calculates GRE header length
 */
uint32_t nss_connmgr_gre_get_hlen(struct nss_connmgr_gre_cfg *cfg)
{
	uint32_t size = 4;	/* minimum size of GRE packet */

	if (cfg->okey_valid) {
		size += 4;
	}

	if (cfg->oseq_valid) {
		size += 4;
	}

	if (cfg->ocsum_valid) {
		size += 4;
	}

	return size;
}

/*
 * nss_connmgr_gre_set_gre_flags()
 *	Map User configured flags to tunnel specific flag.
 */
void nss_connmgr_gre_set_gre_flags(struct nss_connmgr_gre_cfg *cfg,
					   uint16_t *o_flags, uint16_t *i_flags)

{
	if (cfg->ikey_valid) {
		*i_flags |= TUNNEL_KEY;
	}

	if (cfg->okey_valid) {
		*o_flags |= TUNNEL_KEY;
	}

	if (cfg->iseq_valid) {
		*i_flags |= TUNNEL_SEQ;
	}

	if (cfg->oseq_valid) {
		*o_flags |= TUNNEL_SEQ;
	}

	if (cfg->icsum_valid) {
		*i_flags |= TUNNEL_CSUM;
	}

	if (cfg->ocsum_valid) {
		*o_flags |= TUNNEL_CSUM;
	}
}

/*
 * nss_connmgr_gre_get_nss_config_flags()
 *	Map tunnel specific flags to NSS flags.
 */
uint32_t nss_connmgr_gre_get_nss_config_flags(uint16_t o_flags, uint16_t i_flags,
						  uint8_t tos, uint8_t ttl,
						  uint16_t frag_off)
{
	uint32_t gre_flags = 0;

	if (i_flags & TUNNEL_KEY) {
		gre_flags |= NSS_GRE_CONFIG_IKEY_VALID;
	}

	if (o_flags & TUNNEL_KEY) {
		gre_flags |= NSS_GRE_CONFIG_OKEY_VALID;
	}

	if (i_flags & TUNNEL_SEQ) {
		gre_flags |= NSS_GRE_CONFIG_ISEQ_VALID;
	}

	if (o_flags & TUNNEL_SEQ) {
		gre_flags |= NSS_GRE_CONFIG_OSEQ_VALID;
	}

	if (i_flags & TUNNEL_CSUM) {
		gre_flags |= NSS_GRE_CONFIG_ICSUM_VALID;
	}

	if (o_flags & TUNNEL_CSUM) {
		gre_flags |= NSS_GRE_CONFIG_OCSUM_VALID;
	}

	if (tos & 0x1) {
		gre_flags |= NSS_GRE_CONFIG_TOS_INHERIT;
	}

	if (!ttl) {
		gre_flags |= NSS_GRE_CONFIG_TTL_INHERIT;
	}

	if (frag_off == htons(IP_DF)) {
		gre_flags |= NSS_GRE_CONFIG_SET_DF;
	}

	return gre_flags;
}

/*
 *  nss_connmgr_gre_destroy_interface()
 *	User API to delete interface
 */
enum nss_connmgr_gre_err_codes nss_connmgr_gre_destroy_interface(struct net_device *dev)
{
	enum nss_connmgr_gre_err_codes ret;

	if (!dev) {
		nss_connmgr_gre_info("Please specifiy valid interface to be deleted\n");
		return GRE_ERR_NO_NETDEV;
	}

	if (in_interrupt()) {
		nss_connmgr_gre_info("%p: nss_connmgr_gre_destroy_interface() called in interrupt context\n", dev);
		return GRE_ERR_IN_INTERRUPT_CTX;
	}

	rtnl_lock();
	ret = __nss_connmgr_gre_destroy_interface(dev);
	rtnl_unlock();

	/*
	 * free_netdev() should be called outside of rtnl lock
	 */
	if (!ret) {
		free_netdev(dev);
	}

	return ret;
}
EXPORT_SYMBOL(nss_connmgr_gre_destroy_interface);

/*
 * nss_connmgr_gre_create_interface()
 *	User API to create gre standard interface
 */
struct net_device *nss_connmgr_gre_create_interface(struct nss_connmgr_gre_cfg *cfg,
						    enum nss_connmgr_gre_err_codes *err_code)
{
	struct net_device *dev;

	if ((!cfg) || (!err_code)) {
		nss_connmgr_gre_info("parameter to this function should not be NULL\n");
		return NULL;
	}

	if (in_interrupt()) {
		nss_connmgr_gre_info("nss_connmgr_gre_create_interface() called in interrupt context\n");
		*err_code = GRE_ERR_IN_INTERRUPT_CTX;
		return NULL;
	}

	if (!nss_connmgr_gre_validate_config(cfg)) {
		nss_connmgr_gre_info("No support for Key/Csum/Sequence number\n");
		*err_code = GRE_ERR_UNSUPPORTED_CFG;
		return NULL;
	}

	rtnl_lock();
	dev = __nss_connmgr_gre_create_interface(cfg, err_code);
	rtnl_unlock();

	if (*err_code == GRE_SUCCESS) {
		return dev;
	}

	if (dev) {
		free_netdev(dev);
	}

	return NULL;
}
EXPORT_SYMBOL(nss_connmgr_gre_create_interface);

module_init(nss_connmgr_gre_dev_init_module);
module_exit(nss_connmgr_gre_exit_module);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("NSS gre offload manager");
