/*
 **************************************************************************
 * Copyright (c) 2015-2017, The Linux Foundation. All rights reserved.
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

#include <linux/version.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/rwlock_types.h>
#include <linux/hashtable.h>
#include <linux/inetdevice.h>
#include <linux/ip.h>
#include <net/ipv6.h>
#include <linux/if_arp.h>
#include <net/route.h>
#include <linux/if_pppox.h>
#include <net/ip.h>

#ifdef CONFIG_OF
#include <linux/of.h>
#endif

#include <nss_api_if.h>
#include <nss_dynamic_interface.h>
#include "nss_connmgr_pptp.h"

#define PPP_HDR_LEN        4

/*
 * NSS pptp debug macros
 */
#if (NSS_PPTP_DEBUG_LEVEL < 1)
#define nss_connmgr_pptp_assert(fmt, args...)
#else
#define nss_connmgr_pptp_assert(c)  BUG_ON(!(c));
#endif

#if (NSS_PPTP_DEBUG_LEVEL < 2)
#define nss_connmgr_pptp_info(s, ...)
#else
#define nss_connmgr_pptp_info(s, ...) pr_info("%s[%d]:" s, __func__, __LINE__, ##__VA_ARGS__)
#endif

#define NUM_PPTP_CHANNELS_IN_PPP_NETDEVICE  1
#define HASH_BUCKET_SIZE 2  /* ( 2^ HASH_BUCKET_SIZE ) == 4 */

static DEFINE_HASHTABLE(pptp_session_table, HASH_BUCKET_SIZE);

/*
 * nss_connmgr_pptp_client_xmit()
 * 	PPTP GRE seq/ack offload callback handler. Sends SKB to NSS firmware.
 * 	Note: RCU lock is already held by caller.
 */
static int nss_connmgr_pptp_client_xmit(struct sk_buff *skb, struct net_device *dev)
{
	struct nss_connmgr_pptp_session_entry *session_info;
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 8, 0))
	struct hlist_node *node;
#endif
	struct nss_ctx_instance *nss_pptp_ctx;
	nss_tx_status_t status;
	int if_number;

	/*
	 * Check if pptp is registered ?
	 */
	if_number = nss_cmn_get_interface_number_by_dev(dev);
	if (if_number < 0) {
		nss_connmgr_pptp_info("%p: PPTP dev is not registered with nss\n", dev);
		return -1;
	}

	nss_pptp_ctx = nss_pptp_get_context();
	if (!nss_pptp_ctx) {
		nss_connmgr_pptp_info("%p: NSS PPTP context not found for if_number %d\n", dev, if_number);
		return -1;
	}

	hash_for_each_possible_rcu(pptp_session_table, session_info,
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 8, 0))
				    node,
#endif
				    hash_list, dev->ifindex) {
		if (session_info->dev != dev) {
			continue;
		}

		status = nss_pptp_tx_buf(nss_pptp_ctx, if_number, skb);
		if (status == NSS_TX_SUCCESS) {
			/*
			 * Found a match for a session and successfully posted
			 * packet to firmware. Retrun success.
			 */
			return 0;
		}

		nss_connmgr_pptp_info("%p: NSS FW tx failed if_number %d\n", dev, if_number);
		return -1;
	}

	/* Return error, Could not find a match for session */
	return -1;
}

/*
 * nss_connmgr_pptp_get_session()
 *	Retrieve pptp session associated with this netdevice if any
 */
static int nss_connmgr_pptp_get_session(struct net_device *dev, struct pptp_opt *opt)
{
	struct ppp_channel *channel[1] = {NULL};
	int px_proto;
	int ppp_ch_count;

	/*
	 * check whether the interface is of type PPP
	 */
	if (dev->type != ARPHRD_PPP || !(dev->flags & IFF_POINTOPOINT)) {
		nss_connmgr_pptp_info("%p: netdevice is not a PPP tunnel type\n", dev);
		return -1;
	}

	if (ppp_is_multilink(dev)) {
		nss_connmgr_pptp_info("%p: channel is multilink PPP\n", dev);
		return -1;
	}

	ppp_ch_count = ppp_hold_channels(dev, channel, 1);
	nss_connmgr_pptp_info("%p: PPP hold channel ret %d\n", dev, ppp_ch_count);
	if (ppp_ch_count != 1) {
		nss_connmgr_pptp_info("%p: hold channel for netdevice failed\n", dev);
		return -1;
	}

	if (!channel[0]) {
		nss_connmgr_pptp_info("%p: channel don't have a ppp_channel\n", dev);
		return -1;
	}

	px_proto = ppp_channel_get_protocol(channel[0]);
	if (px_proto != PX_PROTO_PPTP) {
		nss_connmgr_pptp_info("%p: session socket is not of type PX_PROTO_PPTP\n", dev);
		ppp_release_channels(channel, 1);
		return -1;
	}

	pptp_channel_addressing_get(opt, channel[0]);

	ppp_release_channels(channel, 1);
	return 0;
}

/*
 * nss_connmgr_add_pptp_session()
 *	Add PPTP session entry into Hash table
 */
static struct nss_connmgr_pptp_session_entry *nss_connmgr_add_pptp_session(struct net_device *dev, struct pptp_opt *session)

{
	struct nss_connmgr_pptp_session_entry *pptp_session_data = NULL;
	struct nss_connmgr_pptp_session_info *data;
	struct net_device *physical_dev;

	pptp_session_data = kmalloc(sizeof(struct nss_connmgr_pptp_session_entry),
				      GFP_KERNEL);
	if (!pptp_session_data) {
		nss_connmgr_pptp_info("%p: failed to allocate pptp_session_data\n", dev);
		return NULL;
	}

	data = &pptp_session_data->data;

	/*
	 * Get session info
	 */
	data->src_call = session->src_addr.call_id;
	data->dst_call = session->dst_addr.call_id;
	data->src_ip = session->src_addr.sin_addr.s_addr;
	data->dst_ip = session->dst_addr.sin_addr.s_addr;

	nss_connmgr_pptp_info("%p: src_call_id=%u peer_call_id=%u\n", dev, data->src_call, data->dst_call);

	/*
	 * This netdev hold will be released when netdev
	 * down event arrives and session goes down.
	 */
	dev_hold(dev);
	pptp_session_data->dev = dev;

	/*
	 * Note: ip_dev_find does a hold on the physical device,
	 * which is released when PPTP session goes down
	 */
	physical_dev = ip_dev_find(&init_net, data->src_ip);
	if (!physical_dev) {
		nss_connmgr_pptp_info("%p: couldn't find a phycal dev %s\n", dev, dev->name);
		dev_put(dev);
		kfree(pptp_session_data);
		return NULL;
	}

	pptp_session_data->phy_dev = physical_dev;

	/*
	 * There is no need for protecting simultaneous addition &
	 * deletion of pptp_session_data as all netdev notifier chain
	 * call back is called with rtln mutex lock.
	 */
	hash_add_rcu(pptp_session_table,
		&pptp_session_data->hash_list,
		dev->ifindex);

	return pptp_session_data;
}

/*
 * nss_connmgr_pptp_event_receive()
 *	Event Callback to receive events from NSS
 */
static void nss_connmgr_pptp_event_receive(void *if_ctx, struct nss_pptp_msg *tnlmsg)
{
	struct nss_connmgr_pptp_session_entry *session_info = (struct nss_connmgr_pptp_session_entry *)if_ctx;
	struct net_device *netdev = session_info->dev;
	struct nss_pptp_sync_session_stats_msg *sync_stats;

	switch (tnlmsg->cm.type) {
	case NSS_PPTP_MSG_SYNC_STATS:
		if (!netdev) {
			return;
		}

		nss_connmgr_pptp_info("%p: Update PPP stats for PPTP netdev %p\n", session_info, netdev);
		sync_stats = (struct nss_pptp_sync_session_stats_msg *)&tnlmsg->msg.stats;
		dev_hold(netdev);

		/*
		 * Update ppp stats
		 */
		ppp_update_stats(netdev,
				 (unsigned long)sync_stats->encap_stats.rx_packets,
				 (unsigned long)sync_stats->encap_stats.rx_bytes,
				 (unsigned long)sync_stats->encap_stats.tx_packets,
				 (unsigned long)sync_stats->encap_stats.tx_bytes,
				  0, 0, 0, 0);

		dev_put(netdev);
		break;

	default:
		nss_connmgr_pptp_info("%p: Unknown Event from NSS\n", session_info);
		break;
	}
}

/*
 * nss_connmgr_pptp_exception()
 *	Exception handler registered to NSS for handling pptp pkts
 */
static void nss_connmgr_pptp_exception(struct net_device *dev,
				       struct sk_buff *skb,
				       __attribute__((unused)) struct napi_struct *napi)

{
	struct iphdr *iph_outer;
	struct nss_connmgr_pptp_session_entry *session_info;
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 8, 0))
	struct hlist_node *node;
#endif
	struct nss_pptp_gre_hdr *gre_hdr;
	__be32 tunnel_local_ip;
	__be32 tunnel_peer_ip;
	struct rtable *rt;
	struct net_device *out_dev;

	/* discard L2 header */
	skb_pull(skb, sizeof(struct ethhdr));
	skb_reset_mac_header(skb);

	iph_outer = (struct iphdr *)skb->data;

	rcu_read_lock();
	hash_for_each_possible_rcu(pptp_session_table, session_info,
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 8, 0))
				   node,
#endif
				   hash_list, dev->ifindex) {
		if (session_info->dev == dev) {
			tunnel_local_ip = session_info->data.src_ip;
			tunnel_peer_ip = session_info->data.dst_ip;
			rcu_read_unlock();
			if ((iph_outer->version == 4) && (iph_outer->protocol == IPPROTO_GRE) &&
				(iph_outer->saddr == tunnel_local_ip) && (iph_outer->daddr == tunnel_peer_ip)) { /*pkt is encapsulated */

				/*
				 * Pull the outer IP header and confirm the packet is a PPTP GRE Packet
				 */
				skb_pull(skb, sizeof(struct iphdr));
				gre_hdr = (struct nss_pptp_gre_hdr *)skb->data;
				if ((ntohs(gre_hdr->protocol) != NSS_PPTP_GRE_PROTO) &&
						(gre_hdr->flags_ver == NSS_PPTP_GRE_VER)) {
					nss_connmgr_pptp_info("%p, Not PPTP_GRE_PROTO, so freeing\n", session_info);
					dev_kfree_skb_any(skb);
					return;
				}

				skb_push(skb, sizeof(struct iphdr));

				/*
				 * This is a PPTP encapsulated packet that has been exceptioned to host from NSS.
				 * We can send it directly to the physical device
				 */
				rt = ip_route_output(&init_net, tunnel_peer_ip, tunnel_local_ip, 0, session_info->phy_dev->ifindex);
				if (unlikely(IS_ERR(rt))) {
					nss_connmgr_pptp_info("%p: Martian packets, drop\n", session_info);
					nss_connmgr_pptp_info("%p: No route or out dev, drop packet...\n", session_info);
					dev_kfree_skb_any(skb);
					return;
				}

				out_dev = rt->dst.dev;
				if (likely(out_dev)) {
					nss_connmgr_pptp_info("%p: dst route dev is %s\n", session_info, out_dev->name);
				} else {
					nss_connmgr_pptp_info("%p: No out dev, drop packet...\n", session_info);
					dev_kfree_skb_any(skb);
				}

				/*
				 * Sets the 'dst' entry for SKB, reset the IP and Transport
				 * Header and sends the packet out directly to the physical
				 * device associated with the PPTP tunnel interface.
				 */
				skb->dev = dev;
				skb_dst_drop(skb);
				skb_dst_set(skb, &rt->dst);
				skb->ip_summed = CHECKSUM_COMPLETE;

				skb_reset_network_header(skb);
				skb_set_transport_header(skb, iph_outer->ihl*4);
				skb->skb_iif = dev->ifindex;
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 4, 0))
				ip_local_out(skb);
#else
				ip_local_out(&init_net, skb->sk, skb);
#endif
				return;
			} else  { /* pkt is decapsulated */
				if (iph_outer->version == 4) {
					skb->protocol = htons(ETH_P_IP);
				} else if (iph_outer->version == 6) {
					skb->protocol = htons(ETH_P_IPV6);
				} else {
					nss_connmgr_pptp_info("%p: pkt may be a control packet\n", session_info);
				}
				skb_reset_network_header(skb);
				skb->pkt_type = PACKET_HOST;
				skb->skb_iif = dev->ifindex;
				skb->ip_summed = CHECKSUM_NONE;
				skb->dev = dev;
				nss_connmgr_pptp_info("%p: send decapsulated packet through network stack", session_info);
				netif_receive_skb(skb);
				return;
			}
		}
	}
	rcu_read_unlock();
	nss_connmgr_pptp_info("%p: unable to find session for PPTP exception packet from %s, so freeing\n", dev, dev->name);
	dev_kfree_skb_any(skb);
}

/*
 * nss_connmgr_pptp_dev_up()
 *	pppopptp interface's up event handler
 */
static int nss_connmgr_pptp_dev_up(struct net_device *dev)
{
	struct pptp_opt opt;
	struct nss_connmgr_pptp_session_entry *session_info = NULL;
	struct nss_connmgr_pptp_session_info *data;
	nss_tx_status_t status;
	struct nss_ctx_instance *nss_ctx;
	uint32_t features = 0;
	uint32_t if_number;
	struct nss_pptp_msg  pptpmsg;
	struct nss_pptp_session_configure_msg *pptpcfg;
	int ret;

	ret = nss_connmgr_pptp_get_session(dev, &opt);
	if (ret < 0) {
		return NOTIFY_DONE;
	}

	/*
	 * Create nss dynamic interface and register
	 */
	if_number = nss_dynamic_interface_alloc_node(NSS_DYNAMIC_INTERFACE_TYPE_PPTP);
	if (if_number == -1) {
		nss_connmgr_pptp_info("%p: Request interface number failed\n", dev);
		return NOTIFY_DONE;
	}

	nss_connmgr_pptp_info("%p: nss_dynamic_interface_alloc_node() sucessful. if_number %d\n", dev, if_number);

	if (!nss_is_dynamic_interface(if_number)) {
		nss_connmgr_pptp_info("%p: Invalid NSS dynamic I/F number %d\n", dev, if_number);
		return NOTIFY_BAD;
	}

	session_info = nss_connmgr_add_pptp_session(dev, &opt);
	if (session_info == NULL) {
		status = nss_dynamic_interface_dealloc_node(if_number, NSS_DYNAMIC_INTERFACE_TYPE_PPTP);
		if (status != NSS_TX_SUCCESS) {
			nss_connmgr_pptp_info("%p: Unable to dealloc the node[%d] in the NSS fw!\n", dev, if_number);
		}
		return NOTIFY_BAD;
	}

	/*
	 * Register pptp  tunnel with NSS
	 */
	nss_ctx = nss_register_pptp_if(if_number,
				       nss_connmgr_pptp_exception,
				       nss_connmgr_pptp_event_receive,
				       dev,
				       features,
				       session_info);

	if (!nss_ctx) {
		status = nss_dynamic_interface_dealloc_node(if_number, NSS_DYNAMIC_INTERFACE_TYPE_PPTP);
		if (status != NSS_TX_SUCCESS) {
			nss_connmgr_pptp_info("%p: Unable to dealloc the node in the NSS fw!\n", dev);
		}
		nss_connmgr_pptp_info("%p: nss_register_pptp_if failed\n", dev);
		dev_put(dev);
		dev_put(session_info->phy_dev);
		hash_del_rcu(&session_info->hash_list);
		synchronize_rcu();
		kfree(session_info);
		return NOTIFY_BAD;
	}

	nss_connmgr_pptp_info("%p: nss_register_pptp_if() successful\n", nss_ctx);

	data = &session_info->data;

	memset(&pptpmsg, 0, sizeof(struct nss_pptp_msg));
	pptpcfg = &pptpmsg.msg.session_configure_msg;

	/*
	 * The call id is already in host byte order,
	 * therefore no need to do ntohs() for call id.
	 */
	pptpcfg->src_call_id = data->src_call;
	pptpcfg->dst_call_id = data->dst_call;

	/*
	 * Convert IP addresses from nework byte order
	 * to host byte order before posting to firmware.
	 */
	pptpcfg->sip = ntohl(data->src_ip);
	pptpcfg->dip = ntohl(data->dst_ip);

	nss_connmgr_pptp_info("%p: pptp info\n", dev);
	nss_connmgr_pptp_info("%p: local_call_id %d peer_call_id %d\n", dev,
									pptpcfg->src_call_id,
									pptpcfg->dst_call_id);
	nss_connmgr_pptp_info("%p: saddr 0x%x daddr 0x%x \n", dev, pptpcfg->sip, pptpcfg->dip);
	nss_connmgr_pptp_info("%p: Sending pptp i/f up command to NSS\n", dev);

	nss_pptp_msg_init(&pptpmsg, if_number, NSS_PPTP_MSG_SESSION_CONFIGURE, sizeof(struct nss_pptp_session_configure_msg), NULL, NULL);

	status = nss_pptp_tx_msg_sync(nss_ctx, &pptpmsg);
	if (status != NSS_TX_SUCCESS) {
		nss_unregister_pptp_if(if_number);
		status = nss_dynamic_interface_dealloc_node(if_number, NSS_DYNAMIC_INTERFACE_TYPE_PPTP);
		if (status != NSS_TX_SUCCESS) {
			nss_connmgr_pptp_info("%p: Unable to dealloc the node[%d] in the NSS fw!\n", dev, if_number);
		}
		nss_connmgr_pptp_info("%p: nss pptp session creation command error %d\n", dev, status);
		dev_put(dev);
		dev_put(session_info->phy_dev);
		hash_del_rcu(&session_info->hash_list);
		synchronize_rcu();
		kfree(session_info);
		return NOTIFY_BAD;
	}
	nss_connmgr_pptp_info("%p: nss_pptp_tx() successful\n", dev);

	/*
	 * Enable the offload mode for Linux PPTP kernel driver. After this
	 * all PPTP GRE packets will go through the NSS FW.
	 */
	pptp_session_enable_offload_mode(data->dst_call, data->dst_ip);
	return NOTIFY_DONE;
}

/*
 * nss_connmgr_pptp_dev_down()
 *	pppopptp interface's down event handler
 */
static int nss_connmgr_pptp_dev_down(struct net_device *dev)
{
	struct nss_connmgr_pptp_session_entry *session_info;
	struct hlist_node *tmp;
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 8, 0))
	struct hlist_node *node;
#endif

	struct nss_pptp_msg pptpmsg;
	struct nss_pptp_session_deconfigure_msg *pptpcfg;
	nss_tx_status_t status;
	int if_number;

	/*
	 * check whether the interface is of type PPP
	 */
	if (dev->type != ARPHRD_PPP || !(dev->flags & IFF_POINTOPOINT)) {
		nss_connmgr_pptp_info("%p: netdevice is not a pptp tunnel type\n", dev);
		return NOTIFY_DONE;
	}

	/*
	 * Check if pptp is registered ?
	 */
	if_number = nss_cmn_get_interface_number_by_dev(dev);
	if (if_number < 0) {
		nss_connmgr_pptp_info("%p: Net device is not registered with nss\n", dev);
		return NOTIFY_DONE;
	}

	hash_for_each_possible_safe(pptp_session_table, session_info,
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 8, 0))
				    node,
#endif
				    tmp, hash_list, dev->ifindex) {
		if (session_info->dev != dev) {
			continue;
		}

		/*
		 * Disable the pptp offload mode. This will allow all PPTP GRE packets
		 * to go through linux PPTP kernel module.
		 */
		pptp_session_disable_offload_mode(session_info->data.dst_call, session_info->data.dst_ip);
		dev_put(dev);
		dev_put(session_info->phy_dev);
		hash_del_rcu(&session_info->hash_list);
		synchronize_rcu();

		memset(&pptpmsg, 0, sizeof(struct nss_pptp_msg));
		pptpcfg = &pptpmsg.msg.session_deconfigure_msg;
		pptpcfg->src_call_id = session_info->data.src_call;

		nss_pptp_msg_init(&pptpmsg, if_number, NSS_PPTP_MSG_SESSION_DECONFIGURE, sizeof(struct nss_pptp_session_deconfigure_msg), NULL, NULL);
		status = nss_pptp_tx_msg_sync(nss_pptp_get_context(), &pptpmsg);
		if (status != NSS_TX_SUCCESS) {
			nss_connmgr_pptp_info("%p: pptp session destroy command failed, if_number = %d\n", dev, if_number);
			kfree(session_info);
			return NOTIFY_BAD;
		}
		nss_unregister_pptp_if(if_number);
		status = nss_dynamic_interface_dealloc_node(if_number, NSS_DYNAMIC_INTERFACE_TYPE_PPTP);
		if (status != NSS_TX_SUCCESS) {
			nss_connmgr_pptp_info("%p: pptp dealloc node failure for if_number=%d\n", dev, if_number);
			kfree(session_info);
			return NOTIFY_BAD;
		}
		nss_connmgr_pptp_info("%p: deleting pptpsession, if_number %d, local_call_id %d, peer_call_id %d\n", dev,
							dev->ifindex, session_info->data.src_call,  session_info->data.dst_call);
		kfree(session_info);
		break;
	}

	return NOTIFY_DONE;
}

/*
 * nss_connmgr_pptp_dev_event()
 *	Net device notifier for nss pptp module
 */
static int nss_connmgr_pptp_dev_event(struct notifier_block  *nb,
		unsigned long event, void  *dev)
{
	struct net_device *netdev;
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 10, 0))
	netdev = (struct net_device *)dev;
#else
	netdev = netdev_notifier_info_to_dev(dev);
#endif

	switch (event) {
	case NETDEV_UP:
		nss_connmgr_pptp_info("%p: netdevice '%s' UP event\n", netdev, netdev->name);
		return nss_connmgr_pptp_dev_up(netdev);

	case NETDEV_DOWN:
		nss_connmgr_pptp_info("%p: netdevice '%s' Down event\n", netdev, netdev->name);
		return nss_connmgr_pptp_dev_down(netdev);

	default:
		break;
	}

	return NOTIFY_DONE;
}

/*
 * Linux Net device Notifier
 */
struct notifier_block nss_connmgr_pptp_notifier = {
	.notifier_call = nss_connmgr_pptp_dev_event,
};

/*
 * nss_connmgr_pptp_init_module()
 *	Tunnel pptp module init function
 */
int __init nss_connmgr_pptp_init_module(void)
{
#ifdef CONFIG_OF
	/*
	 * If the node is not compatible, don't do anything.
	 */
	if (!of_find_node_by_name(NULL, "nss-common")) {
		return 0;
	}
#endif
	register_netdevice_notifier(&nss_connmgr_pptp_notifier);
	pptp_register_gre_seq_offload_callback(nss_connmgr_pptp_client_xmit);
	return 0;
}

/*
 * nss_connmgr_pptp_exit_module
 *	Tunnel pptp module exit function
 */
void __exit nss_connmgr_pptp_exit_module(void)
{
	pptp_unregister_gre_seq_offload_callback();
#ifdef CONFIG_OF
	/*
	 * If the node is not compatible, don't do anything.
	 */
	if (!of_find_node_by_name(NULL, "nss-common")) {
		return;
	}
#endif
	unregister_netdevice_notifier(&nss_connmgr_pptp_notifier);
}

module_init(nss_connmgr_pptp_init_module);
module_exit(nss_connmgr_pptp_exit_module);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("NSS pptp over ppp offload manager");
