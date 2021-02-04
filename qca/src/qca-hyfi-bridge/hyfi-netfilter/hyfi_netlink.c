/*
 *  Hy-Fi Netlink
 *  QCA HyFi Netfilter
 *
 * Copyright (c) 2012-2016, The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#define DEBUG_LEVEL HYFI_NF_DEBUG_LEVEL

#include <linux/kernel.h>
#include <net/net_namespace.h>
#include <net/sock.h>
#include "hyfi_api.h"
#include "hyfi_hatbl.h"
#include "hyfi_hdtbl.h"
#include "hyfi_fdb.h"
#include "hyfi_netlink.h"
/* ref_port_ctrl.h and ref_fdb.h header file is  platform dependent code and this
   is not required for 3rd party platform. So avoided this header file inclusion
   by the flag HYFI_DISABLE_SSDK_SUPPORT
 */
#ifndef HYFI_DISABLE_SSDK_SUPPORT
#include "ref/ref_port_ctrl.h"
#include "ref/ref_fdb.h"
#endif

static struct sock *hyfi_nl_sk = NULL;
static struct sock *hyfi_nl_event_sk = NULL;

static void hyfi_netlink_receive(struct sk_buff *__skb)
{
	struct net_device *brdev = NULL;
	struct hyfi_net_bridge *br;
	struct net_device *bridge_dev = NULL;
	struct sk_buff *skb;
	struct nlmsghdr *nlh = NULL;
	void *hymsgdata = NULL;
	u32 pid, seq, retval, msgtype;
	struct __hyctl_msg_header *hymsghdr;
	struct __hybr_info brinfo;
	struct net_bridge_port *br_port = NULL;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 10, 0))
        if ((skb = skb_clone(__skb, GFP_KERNEL)) != NULL)
#else
	if ((skb = skb_get(__skb)) != NULL )
#endif
        {
		/* process netlink message pointed by skb->data */
		nlh = nlmsg_hdr(skb);
		pid = nlh->nlmsg_pid;
		seq = nlh->nlmsg_seq;
		hymsghdr = NLMSG_DATA( nlh );
		hymsghdr->status = HYFI_STATUS_SUCCESS;
		hymsgdata = HYFI_MSG_DATA(nlh);
		msgtype = nlh->nlmsg_type;

		brdev = dev_get_by_name(&init_net, hymsghdr->if_name);
		if (!brdev) {
			DEBUG_ERROR("Device not found: %s\n", hymsghdr->if_name);
			hymsghdr->status = HYFI_STATUS_NOT_FOUND;
			goto done;
		}

		br = hyfi_bridge_get(netdev_priv(brdev));
		do {
			if (msgtype == HYFI_ATTACH_BRIDGE ||
				msgtype == HYFI_DETACH_BRIDGE ||
				msgtype == HYFI_GET_BRIDGE) {
				bool release_read_lock = false;
				struct hyfi_net_bridge * hf_br = NULL;

				if (br) {
					rcu_read_lock();
					bridge_dev = hyfi_bridge_dev_get_rcu(br);
					release_read_lock = true;
				}
				if (msgtype == HYFI_ATTACH_BRIDGE) {
					if (br && bridge_dev) {
						DEBUG_INFO("hyfi: Already attached to bridge %s\n",
								bridge_dev->name);
					} else {
						/* Can't call set_bridge_name under rcu_read_lock */
						if (release_read_lock) {
							release_read_lock = false;
							rcu_read_unlock();
						}
						hf_br = hyfi_bridge_alloc_hyfi_bridge(hymsghdr->if_name);
						if (hf_br == NULL) {
							DEBUG_ERROR("hyfi: cannot support anymore hyfi bridges\n");
							hymsghdr->status = HYFI_STATUS_FAILURE;
							goto done;
						}
						if (hyfi_bridge_set_bridge_name(hf_br, hymsghdr->if_name)) {
							DEBUG_ERROR("hyfi: failed to attach bridge %s\n",hymsghdr->if_name);
							hymsghdr->status = HYFI_STATUS_FAILURE;
						}
					}
				} else if (msgtype == HYFI_DETACH_BRIDGE) {
					if (!br || !bridge_dev || strcmp(bridge_dev->name, hymsghdr->if_name)) {
						DEBUG_ERROR("hyfi: Not attached to bridge %s\n",
								hymsghdr->if_name);
						hymsghdr->status = HYFI_STATUS_FAILURE;
					} else {
						/* Can't call set_bridge_name under rcu_read_lock */
						if (release_read_lock) {
							release_read_lock = false;
							rcu_read_unlock();
						}
						if (hyfi_bridge_set_bridge_name(br, NULL )) {
							hymsghdr->status = HYFI_STATUS_FAILURE;
						}
					}
				} else if (msgtype == HYFI_GET_BRIDGE) {
					if (!br || !bridge_dev) {
						brinfo.ifindex = -ENODEV;
						brinfo.flags = 0;
						hymsghdr->status = HYFI_STATUS_FAILURE;
					} else {

						brinfo.ifindex = bridge_dev->ifindex;
						brinfo.flags = br->flags;

						*(struct __hybr_info*) hymsgdata = brinfo;
					}
				}

				if (release_read_lock)
					rcu_read_unlock();

				break;
			}

			if (!brdev || !br || brdev != br->dev) {
				if (!(msgtype == HYFI_GET_FDB && brdev && (brdev->priv_flags & IFF_EBRIDGE))) {
					DEBUG_ERROR("Not a Hy-Fi device, or device not found: %s\n",
							hymsghdr->if_name);
					hymsghdr->status = HYFI_STATUS_NOT_FOUND;
					goto done;
				}
			}

			switch (msgtype) {

			case HYFI_GET_HA_TABLE:
				if (hyfi_hatbl_fillbuf(br, hymsgdata, hymsghdr->buf_len,
						hymsghdr->tbl_offsite, &hymsghdr->bytes_written,
						&hymsghdr->bytes_needed)) {
					hymsghdr->status = HYFI_STATUS_BUFFER_OVERFLOW;
				}
				break;

			case HYFI_GET_HD_TABLE:
				if (hyfi_hdtbl_fillbuf(br, hymsgdata, hymsghdr->buf_len,
						hymsghdr->tbl_offsite, &hymsghdr->bytes_written)) {
					hymsghdr->status = HYFI_STATUS_BUFFER_OVERFLOW;
				}

				break;

			case HYFI_GET_FDB: {
				struct net_bridge *br = netdev_priv(brdev);

				if (hyfi_fdb_fillbuf(br, hymsgdata, hymsghdr->buf_len,
						hymsghdr->tbl_offsite, &hymsghdr->bytes_written,
						&hymsghdr->bytes_needed)) {
					hymsghdr->status = HYFI_STATUS_BUFFER_OVERFLOW;
				}
				break;
			}

			case HYFI_ADD_HATBL_ENTRIES: {
				int retval;
				struct __hatbl_entry *p = hymsgdata;
				u32 i, num_entries = hymsghdr->buf_len
						/ sizeof(struct __hatbl_entry);
				for (i = 0; i < num_entries; i++, p++) {
					retval = hyfi_hatbl_addentry(br, p);
					if (retval == -EINVAL) {
						hymsghdr->status = HYFI_STATUS_INVALID_PARAMETER;
						break;
					} else if (retval == -ENOMEM) {
						hymsghdr->status = HYFI_STATUS_RESOURCES;
						break;
					}
				}

				break;
			}

			case HYFI_UPDATE_HATBL_ENTRIES: {
				struct __hatbl_entry *p = hymsgdata;
				u32 i, num_entries = hymsghdr->buf_len
						/ sizeof(struct __hatbl_entry);
				u32 errcnt = 0;
				for (i = 0; i < num_entries; i++, p++) {
					retval = hyfi_hatbl_update(br, brdev, p, 0);
					if (retval != HYFI_STATUS_SUCCESS) {
						errcnt++;
					}
				}
				if (errcnt)
					hymsghdr->status = HYFI_STATUS_NOT_FOUND;

				break;
			}

			case HYFI_UPDATE_HATBL_ENTRY: {
				struct __hatbl_entry *p = hymsgdata;

				retval = hyfi_hatbl_update(br, brdev, p, 1);

				if (retval)
					hymsghdr->status = HYFI_STATUS_NOT_FOUND;

				break;
			}

			case HYFI_UPDATE_HDTBL_ENTRIES: {
				struct __hdtbl_entry *p = hymsgdata;
				u32 i, num_entries = hymsghdr->buf_len
						/ sizeof(struct __hdtbl_entry);
				u32 errcnt = 0;
				for (i = 0; i < num_entries; i++, p++) {
					retval = hyfi_hdtbl_update(br, brdev, p);
					if (retval != HYFI_STATUS_SUCCESS) {
						errcnt++;
					}
				}
				if (errcnt)
					hymsghdr->status = HYFI_STATUS_RESOURCES;

				break;
			}

			case HYFI_ADD_HDTBL_ENTRIES: {
				struct __hdtbl_entry *p = hymsgdata;
				u32 i, num_entries = hymsghdr->buf_len
						/ sizeof(struct __hdtbl_entry);
				for (i = 0; i < num_entries; i++, p++) {
					retval = hyfi_hdtbl_insert(br, brdev, p);
					if (retval == -EINVAL) {
						hymsghdr->status = HYFI_STATUS_INVALID_PARAMETER;
						break;
					} else if (retval == -ENOMEM) {
						hymsghdr->status = HYFI_STATUS_RESOURCES;
						break;
					}
				}

				break;
			}

			case HYFI_DEL_HDTBL_ENTRIES: {
				struct __hdtbl_entry *p = hymsgdata;
				u32 i, num_entries = hymsghdr->buf_len
						/ sizeof(struct __hdtbl_entry);
				for (i = 0; i < num_entries; i++, p++) {
					if (hyfi_hdtbl_delete(br, p->mac_addr) == -EINVAL) {
						hymsghdr->status = HYFI_STATUS_INVALID_PARAMETER;
						break;
					}
				}

				break;
			}

			case HYFI_DEL_HDTBL_ENTRIES_BYID: {
				struct __hdtbl_entry *p = hymsgdata;
				u32 i, num_entries = hymsghdr->buf_len
						/ sizeof(struct __hdtbl_entry);
				for (i = 0; i < num_entries; i++, p++) {
					if (hyfi_hdtbl_delete_byid(br, p->id) == -EINVAL) {
						hymsghdr->status = HYFI_STATUS_INVALID_PARAMETER;
						break;
					}
				}

				break;
			}

			case HYFI_FLUSH_HDTBL:
				hyfi_hdtbl_flush(br);
				break;

			case HYFI_SET_HATBL_AGING_PARAM: {
				struct __aging_param *p = hymsgdata;
				if (!p->aging_time || p->aging_time > HYFI_HACTIVE_TBL_EXPIRE_TIME)
				{
					// Invalid max age
					hymsghdr->status = HYFI_STATUS_INVALID_PARAMETER;
					break;
				}
				spin_lock_bh(&br->lock);
				br->hatbl_aging_time = msecs_to_jiffies(p->aging_time);
				spin_unlock_bh(&br->lock);

				break;
			}

			case HYFI_SET_EVENT_PID: {
				struct __event_info *p = hymsgdata;
				spin_lock_bh(&br->lock);
				br->event_pid = p->event_pid;
				spin_unlock_bh(&br->lock);
				DEBUG_INFO("hyfi: Initialized event process id %d\n", p->event_pid);
				break;
			}

			case HYFI_GET_PORT_LIST: {
				struct net_bridge_port *p;
				struct __brport_group *pg = hymsgdata;
				struct net_bridge *br = netdev_priv(brdev);
				u_int32_t i = 0;

				rcu_read_lock();
				if (br && !list_empty(&br->port_list)) {
					list_for_each_entry_rcu(p, &br->port_list, list)
					{
						if (i
								< hymsghdr->buf_len
										/ sizeof(struct __brport_group)) {
							struct hyfi_net_bridge_port *hyfi_p = hyfi_bridge_get_port(p);

							if (hyfi_p) {
								pg->bcast_enable = hyfi_p->bcast_enable;
								pg->group_num = hyfi_p->group_num;
								pg->group_type = hyfi_p->group_type;
								pg->port_type = hyfi_p->port_type;
								pg->ifindex = p->dev->ifindex;

								hymsghdr->bytes_written +=
										sizeof(struct __brport_group);
								pg++;
								i++;
							}
						}
					}
				}
				rcu_read_unlock();
			}
				break;

			case HYFI_FLUSH_HATBL:
				hyfi_hatbl_flush(br);
				break;

			case HYFI_SET_BRIDGE_MODE: {
				u32 *p = hymsgdata;
				if (!(*p == HYFI_BRIDGE_MODE_RELAY_OVERRIDE
						|| *p == !HYFI_BRIDGE_MODE_RELAY_OVERRIDE)) {
					hymsghdr->status = HYFI_STATUS_INVALID_PARAMETER;
					break;
				}
				spin_lock_bh(&br->lock);
				if (*p == HYFI_BRIDGE_MODE_RELAY_OVERRIDE)
					br->flags |= HYFI_BRIDGE_FLAG_MODE_RELAY_OVERRIDE;
				else
					br->flags &= ~HYFI_BRIDGE_FLAG_MODE_RELAY_OVERRIDE;
				spin_unlock_bh(&br->lock);

				break;
			}

			case HYFI_SET_BRIDGE_FWMODE: {
				u32 *p = hymsgdata;
				spin_lock_bh(&br->lock);
				if (*p == HYFI_BRIDGE_FWMODE_APS) {
					br->flags &= ~HYFI_BRIDGE_FLAG_FWMODE_NO_HYBRID_TABLES;
					br->flags &= ~HYFI_BRIDGE_FLAG_FWMODE_MCAST_ONLY;
				}
				else if (*p == HYFI_BRIDGE_FWMODE_NO_HYBRID_TABLES) {
					br->flags |= HYFI_BRIDGE_FLAG_FWMODE_NO_HYBRID_TABLES;
					br->flags &= ~HYFI_BRIDGE_FLAG_FWMODE_MCAST_ONLY;
				}
				else if (*p == HYFI_BRIDGE_FWMODE_MCAST_ONLY) {
					br->flags &= ~HYFI_BRIDGE_FLAG_FWMODE_NO_HYBRID_TABLES;
					br->flags |= HYFI_BRIDGE_FLAG_FWMODE_MCAST_ONLY;
				}
				else {
					hymsghdr->status = HYFI_STATUS_INVALID_PARAMETER;
				}
				spin_unlock_bh(&br->lock);

				break;
			}


			case HYFI_SET_BRPORT_GROUP: {
				struct __brport_group *p = hymsgdata;
				struct net_bridge_port *bp;
				struct net_device *dev;
				if (!(p->group_type == HYFI_PORTGRP_TYPE_RELAY
						|| p->group_type == !HYFI_PORTGRP_TYPE_RELAY)) {
					hymsghdr->status = HYFI_STATUS_INVALID_PARAMETER;
					break;
				}
				rcu_read_lock();
				if ((dev = dev_get_by_index(&init_net, p->ifindex))) {
					br_port = hyfi_br_port_get(dev);
					if ((bp = br_port)) {
						struct hyfi_net_bridge_port *hyfi_p = hyfi_bridge_get_port(bp);
						if (hyfi_p) {
							hyfi_p->group_num = p->group_num;
							hyfi_p->group_type = p->group_type;
						} else {
							hymsghdr->status = HYFI_STATUS_FAILURE;
						}
					} else
						hymsghdr->status = HYFI_STATUS_NOT_FOUND;
					dev_put(dev);
				} else
					hymsghdr->status = HYFI_STATUS_NOT_FOUND;
				rcu_read_unlock();

				break;
			}

			case HYFI_SET_BRPORT_BCAST: {
				struct __brport_group *p = hymsgdata;
				struct net_bridge_port *bp;
				struct net_device *dev;
				rcu_read_lock();
				if ((dev = dev_get_by_index(&init_net, p->ifindex))) {
					br_port = hyfi_br_port_get(dev);
					if ((bp = br_port)) {
						struct hyfi_net_bridge_port *hyfi_p = hyfi_bridge_get_port(bp);

						if (hyfi_p) {
							hyfi_p->bcast_enable = p->bcast_enable;
						} else {
							hymsghdr->status = HYFI_STATUS_FAILURE;
						}
					} else
						hymsghdr->status = HYFI_STATUS_NOT_FOUND;
					dev_put(dev);
				} else
					hymsghdr->status = HYFI_STATUS_NOT_FOUND;
				rcu_read_unlock();

				break;
			}

			case HYFI_SET_BRPORT_TYPE: {
				struct __brport_group *p = hymsgdata;
				struct net_bridge_port *bp;
				struct net_device *dev;
				if (p->port_type >= hyInterface_NumberOfChildInterfaces) {
					hymsghdr->status = HYFI_STATUS_INVALID_PARAMETER;
					break;
				}
				rcu_read_lock();
				if ((dev = dev_get_by_index(&init_net, p->ifindex))) {
					br_port = hyfi_br_port_get(dev);
					if ((bp = br_port)) {
						struct hyfi_net_bridge_port *hyfi_p = hyfi_bridge_get_port(bp);

						if (hyfi_p) {
							hyfi_p->port_type = p->port_type;
						} else {
							hymsghdr->status = HYFI_STATUS_FAILURE;
						}
					} else
						hymsghdr->status = HYFI_STATUS_NOT_FOUND;
					dev_put(dev);
				} else
					hymsghdr->status = HYFI_STATUS_NOT_FOUND;
				rcu_read_unlock();

				break;
			}

			case HYFI_SET_BRIDGE_TCP_SP: {
				u32 *p = hymsgdata;
				spin_lock_bh(&br->lock);
				if (*p)
					br->flags |= HYFI_BRIDGE_FLAG_MODE_TCP_SP;
				else
					br->flags &= ~HYFI_BRIDGE_FLAG_MODE_TCP_SP;
				spin_unlock_bh( &br->lock);
				break;
			}

			case HYFI_SET_PATHSWITCH_PARAM: {
				struct __path_switch_param *p = hymsgdata;
				spin_lock_bh(&br->lock);
				hyfi_psw_param_update(br, p);
				spin_unlock_bh(&br->lock);
				break;
			}
/* switch support is not required for 3rd party platform and this is platform dependent code.
   So avoided this case by using the flag HYFI_DISABLE_SSDK_SUPPORT for 3rd party platform.
 */
#ifndef HYFI_DISABLE_SSDK_SUPPORT
			case HYFI_GET_SWITCH_PORT_ID: {
				struct __switchport_index *p =hymsgdata;
				fal_port_t port_id;
				port_id = ref_fdb_get_port_by_mac(p->vlanid,p->mac_addr);
				p->portid = port_id;
				hyfi_fdb_perport(br, p);
				break;
			}
#endif
			case HYFI_SET_PSW_MSE_TIMEOUT:
			case HYFI_SET_PSW_DROP_MARKERS:
			case HYFI_SET_PSW_OLD_IF_QUIET_TIME:
			case HYFI_SET_PSW_DUP_PKT_FLUSH_QUOTA: {
				void *p = hymsgdata;
				spin_lock_bh(&br->lock);
				hyfi_psw_adv_param_update(br, msgtype, p);
				spin_unlock_bh(&br->lock);
			}
				break;

			default:
				DEBUG_WARN("hyfi: Unknown message type 0x%x\n", msgtype);
				hymsghdr->status = HYFI_STATUS_INVALID_PARAMETER;
				break;

			} /* switch */

		} while (false);

	done:
		if (brdev)
			dev_put(brdev);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 7, 0))
		NETLINK_CB(skb).portid = 0; /* from kernel */
#else
		NETLINK_CB(skb).pid = 0; /* from kernel */
#endif
		NETLINK_CB(skb).dst_group = 0; /* unicast */
                netlink_unicast(hyfi_nl_sk, skb, pid, MSG_DONTWAIT);
	}

	return;
}

void hyfi_netlink_event_send(struct hyfi_net_bridge *br,
			 u32 event_type, u32 event_len, void *event_data)
{
	struct sk_buff *skb;
	struct nlmsghdr *nlh = NULL;
	int send_msg = true;
/* ssdk support is platform dependent code and this is not required for 3rd party platform.
   so avoided the ssdk support by using the flag HYFI_DISABLE_SSDK_SUPPORT.
 */
#ifndef HYFI_DISABLE_SSDK_SUPPORT
	ssdk_port_status *linkStatus = NULL;
	struct __ssdkport_entry *ssdk_portentry = NULL;
#endif
	struct __hatbl_entry *hae;
	struct net_hatbl_entry *ha;
	struct net_bridge_port *bp;

	if (!br || br->event_pid == NLEVENT_INVALID_PID) {
		return;
	}

	skb = nlmsg_new(event_len, gfp_any());
	if (skb == NULL) {
		DEBUG_TRACE("hyfi: skb == NULL event_type=%d\n", event_type);
		return;
	}
	nlh = nlmsg_put(skb, br->event_pid, 0, event_type, event_len, 0);
	if (nlh == NULL) {
		DEBUG_ERROR("hyfi: nlh == NULL event_type=%d\n", event_type);
		return;
	}

	switch (event_type) {

	case HYFI_EVENT_ADD_HA_ENTRY:
		ha = (struct net_hatbl_entry *) event_data;
		hae = (struct __hatbl_entry *) NLMSG_DATA( nlh );
		memcpy(hae->da, ha->da.addr, ETH_ALEN);
		memcpy(hae->sa, ha->sa.addr, ETH_ALEN);
		memcpy(hae->id, ha->id.addr, ETH_ALEN);
		hae->port_list[0].port = ha->dst->dev->ifindex;
		hae->action = ha->action;
		hae->hash = ha->hash;
		break;

	case HYFI_EVENT_DEL_HA_ENTRY:
		ha = (struct net_hatbl_entry *) event_data;
		hae = (struct __hatbl_entry *) NLMSG_DATA( nlh );
		memcpy(hae->da, ha->da.addr, ETH_ALEN);
		memcpy(hae->sa, ha->sa.addr, ETH_ALEN);
		memcpy(hae->id, ha->id.addr, ETH_ALEN);
		hae->port_list[0].port = ha->dst->dev->ifindex;
		hae->hash = ha->hash;
		break;

	case HYFI_EVENT_AGEOUT_HA_ENTRIES:
		break;

	case HYFI_EVENT_LINK_UP:
	case HYFI_EVENT_LINK_DOWN:
		bp = event_data;
		*(u32*) NLMSG_DATA( nlh ) = bp->dev->ifindex;

		break;

	case HYFI_EVENT_FDB_UPDATED:
		/* No data; recipient needs to ask for the updated fdb table */
		break;
/* ssdk support is platform dependent code and this is not required for 3rd party platform.
   so avoided the ssdk support by using the flag HYFI_DISABLE_SSDK_SUPPORT.
 */
#ifndef HYFI_DISABLE_SSDK_SUPPORT
	case HYFI_EVENT_LINK_PORT_UP:
	case HYFI_EVENT_LINK_PORT_DOWN:
		linkStatus = (ssdk_port_status *)event_data;
		memcpy((char *)NLMSG_DATA(nlh), (char *)linkStatus, sizeof(ssdk_port_status));
		break;
	case HYFI_EVENT_MAC_LEARN_ON_PORT:
		ssdk_portentry = (struct __ssdkport_entry *)event_data;
		memcpy((char *)NLMSG_DATA(nlh), (char *)ssdk_portentry, sizeof(struct __ssdkport_entry));
		break;
#endif
	default:
		DEBUG_WARN("hyfi: event type %d is not supported\n", event_type);
		send_msg = false;
		break;
	}

	if (send_msg) {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 7, 0))
		NETLINK_CB(skb).portid = 0; /* from kernel */
#else
		NETLINK_CB(skb).pid = 0; /* from kernel */
#endif
		NETLINK_CB(skb).dst_group = 0; /* unicast */
                netlink_unicast(hyfi_nl_event_sk, skb, br->event_pid, MSG_DONTWAIT);
	}

	return;
}

int __init hyfi_netlink_init( void )
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 6, 0))
	struct netlink_kernel_cfg nlcfg;
	memset(&nlcfg, 0, sizeof(nlcfg));
	nlcfg.groups = 0;
	nlcfg.input = hyfi_netlink_receive;
	hyfi_nl_sk = netlink_kernel_create(&init_net,
			NETLINK_QCA_HYFI,
			&nlcfg);
#else
	hyfi_nl_sk = netlink_kernel_create(&init_net,
			NETLINK_QCA_HYFI,
			0,
			hyfi_netlink_receive,
			NULL,
			THIS_MODULE);
#endif

	if (hyfi_nl_sk == NULL)
	{
		DEBUG_ERROR("hyfi: Failed to create netlink socket\n" );
		return -ENODEV;
	}


#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 6, 0))
	memset(&nlcfg, 0, sizeof(nlcfg));
	nlcfg.groups = 0;
	nlcfg.input = NULL;
	hyfi_nl_event_sk = netlink_kernel_create(&init_net,
			NETLINK_QCA_HYFI_EVENT,
			&nlcfg);
#else
	hyfi_nl_event_sk = netlink_kernel_create(&init_net,
			NETLINK_QCA_HYFI_EVENT,
			0,
			NULL,
			NULL,
			THIS_MODULE);
#endif

	if (hyfi_nl_event_sk == NULL)
	{
		sock_release(hyfi_nl_sk->sk_socket);
		DEBUG_ERROR("hyfi: Failed to create netlink socket\n" );
		return -ENODEV;
	}

	return 0;
}

void hyfi_netlink_fini(void)
{
	if (hyfi_nl_sk) {
		sock_release(hyfi_nl_sk->sk_socket);
		hyfi_nl_sk = NULL;
	}
	if (hyfi_nl_event_sk) {
		sock_release(hyfi_nl_event_sk->sk_socket);
		hyfi_nl_event_sk = NULL;
	}
}
