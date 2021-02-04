/*
 * Copyright (c) 2012, 2015, 2018 The Linux Foundation. All rights reserved.
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

#include <linux/kernel.h>
#include <net/net_namespace.h>
#include <net/sock.h>
#include <linux/etherdevice.h>

#include "mc_osdep.h"
#include "mc_api.h"
#include "mc_snooping.h"
#include "mc_netlink.h"

static struct sock *mc_nl_sk = NULL;

static void mc_acltbl_update(struct mc_struct *mc, void *param)
{
	int i;
	struct mc_param_pattern pattern;
	struct __mc_param_acl_rule *ar = (struct __mc_param_acl_rule *)param;

	memset(&pattern, 0, sizeof pattern);
	if (ar->pattern_type == MC_ACL_PATTERN_IGMP) {
		pattern.rule = ar->pattern.rule;
		memcpy(pattern.mac, ar->pattern.mac, ETH_ALEN);
		memcpy(pattern.mac_mask, ar->pattern.mac_mask, ETH_ALEN);
		/* Input value in network byte order which be converted from the string by inet_pton() */
		pattern.ip.ip4 = *((__be32 *)ar->pattern.ip);
		pattern.ip_mask.ip4_mask = *((__be32 *)ar->pattern.ip_mask);

		if (pattern.ip.ip4) {
			for (i = 0; i < mc->igmp_acl.pattern_count; i++) {
				if (mc->igmp_acl.patterns[i].ip.ip4 == pattern.ip.ip4)
					break;
			}
		} else if (!is_zero_ether_addr(pattern.mac)) {
			for (i = 0; i < mc->igmp_acl.pattern_count; i++) {
				if (!memcmp(mc->igmp_acl.patterns[i].mac, pattern.mac,
						sizeof pattern - sizeof pattern.rule))
					break;
			}
		} else {
			goto out;
		}

		if (ar->pattern.rule == MC_ACL_RULE_DISABLE) {
			if (i != mc->igmp_acl.pattern_count) {
				if (i < mc->igmp_acl.pattern_count - 1)
					memcpy(&mc->igmp_acl.patterns[i], &mc->igmp_acl.patterns[i+1],
						(sizeof pattern) * (mc->igmp_acl.pattern_count - 1 - i));
				mc->igmp_acl.pattern_count--;
			}
			MC_PRINT(KERN_INFO "%s: Del IGMP acl rule, count=%d\n", __func__, mc->igmp_acl.pattern_count);
		} else {
			if (i != mc->igmp_acl.pattern_count) {
				memcpy(&mc->igmp_acl.patterns[i], &pattern, sizeof pattern);
				MC_PRINT(KERN_INFO "%s: Update acl rule\n", __func__);
				goto out;
			}

			if (mc->igmp_acl.pattern_count == MC_ACL_RULE_MAX_COUNT) {
				MC_PRINT(KERN_INFO "%s: Add IGMP acl rule failed, table is full\n", __func__);
				goto out;
			}

			memcpy(&mc->igmp_acl.patterns[mc->igmp_acl.pattern_count], &pattern, sizeof pattern);
			mc->igmp_acl.pattern_count++;
			MC_PRINT(KERN_INFO "%s: Add IGMP acl rule, count=%d\n", __func__, mc->igmp_acl.pattern_count);
		}
	}
#ifdef MC_SUPPORT_MLD
	else { /* MLD */
		pattern.rule = ar->pattern.rule;
		memcpy(pattern.mac, ar->pattern.mac, ETH_ALEN);
		memcpy(pattern.mac_mask, ar->pattern.mac_mask, ETH_ALEN);
		/* Input value in network byte order which be converted from the string by inet_pton() */
		ipv6_addr_set(&pattern.ip.ip6,
				((struct in6_addr *)ar->pattern.ip)->s6_addr32[0],
				((struct in6_addr *)ar->pattern.ip)->s6_addr32[1],
				((struct in6_addr *)ar->pattern.ip)->s6_addr32[2],
				((struct in6_addr *)ar->pattern.ip)->s6_addr32[3]);
		ipv6_addr_set(&pattern.ip_mask.ip6_mask,
				((struct in6_addr *)ar->pattern.ip_mask)->s6_addr32[0],
				((struct in6_addr *)ar->pattern.ip_mask)->s6_addr32[1],
				((struct in6_addr *)ar->pattern.ip_mask)->s6_addr32[2],
				((struct in6_addr *)ar->pattern.ip_mask)->s6_addr32[3]);

		if (!ipv6_addr_any(&pattern.ip.ip6)) {
			for (i = 0; i < mc->mld_acl.pattern_count; i++) {
				if (!ipv6_addr_cmp(&mc->mld_acl.patterns[i].ip.ip6, &pattern.ip.ip6))
					break;
			}
		} else if (!is_zero_ether_addr(pattern.mac)) {
			for (i = 0; i < mc->mld_acl.pattern_count; i++) {
				u_int32_t pattern_size = sizeof pattern - sizeof pattern.rule;

				if (pattern_size > ETH_ALEN)
					pattern_size = ETH_ALEN;
				if (!memcmp(mc->mld_acl.patterns[i].mac, pattern.mac, pattern_size))
					break;
			}
		} else {
			goto out;
		}

		if (ar->pattern.rule == MC_ACL_RULE_DISABLE) {
			if (i != mc->mld_acl.pattern_count) {
				if (i < mc->mld_acl.pattern_count - 1)
					memcpy(&mc->mld_acl.patterns[i], &mc->mld_acl.patterns[i+1],
						(sizeof pattern) * (mc->mld_acl.pattern_count - 1 - i));
				mc->mld_acl.pattern_count--;
			}
			MC_PRINT(KERN_INFO "%s: Del MLD acl rule, count=%d\n", __func__, mc->mld_acl.pattern_count);
		} else {
			if (i != mc->mld_acl.pattern_count) {
				memcpy(&mc->mld_acl.patterns[mc->mld_acl.pattern_count], &pattern, sizeof pattern);
				MC_PRINT(KERN_INFO "%s: Update acl rule\n", __func__);
				goto out;
			}

			if (mc->mld_acl.pattern_count == MC_ACL_RULE_MAX_COUNT) {
				MC_PRINT(KERN_INFO "%s: Add MLD acl rule failed, table is full\n", __func__);
				goto out;
			}

			memcpy(&mc->mld_acl.patterns[mc->mld_acl.pattern_count], &pattern, sizeof pattern);
			mc->mld_acl.pattern_count++;
			MC_PRINT(KERN_INFO "%s: Add MLD acl rule, count=%d\n", __func__, mc->mld_acl.pattern_count);
		}
	}
#endif
out:
	return;
}

static void mc_acltbl_flush(struct mc_struct *mc, void *param)
{
	struct __mc_param_acl_rule *ar = (struct __mc_param_acl_rule *)param;

	if (ar->pattern_type == MC_ACL_PATTERN_IGMP) {
		memset(&mc->igmp_acl, 0, sizeof(mc->igmp_acl));
		MC_PRINT(KERN_INFO "%s: Flush IGMP acl rule table.\n", __func__);
	}
#ifdef MC_SUPPORT_MLD
	else { /* MLD */
		memset(&mc->mld_acl, 0, sizeof(mc->mld_acl));
		MC_PRINT(KERN_INFO "%s: Flush MLD acl rule table.\n", __func__);
	}
#endif
}

static int mc_acltbl_fillbuf(struct mc_struct *mc, void *buf,
			     __be32 buflen, __be32 *bytes_written, __be32 *bytes_needed)
{
	struct __mc_param_acl_rule *entry = buf;
	int i, total = 0, num = 0, num_entrys, ret = 0;
	struct mc_param_pattern *p = &mc->igmp_acl.patterns[0];

	num_entrys = buflen / sizeof(*entry);

	for (i = 0; i < mc->igmp_acl.pattern_count; i++) {
		total++;
		if (num >= num_entrys) {
			ret = -EAGAIN;
			continue;
		}

		entry->pattern_type = MC_ACL_PATTERN_IGMP;
		entry->pattern.rule = p[i].rule;
		memcpy(entry->pattern.mac, p[i].mac, ETH_ALEN);
		memcpy(entry->pattern.mac_mask, p[i].mac_mask, ETH_ALEN);
		memcpy(entry->pattern.ip, &p[i].ip.ip4, sizeof(__be32));
		memcpy(entry->pattern.ip_mask, &p[i].ip_mask.ip4_mask, sizeof(entry->pattern.ip_mask));

		entry++;
		num++;
	}
	if (ret < 0)
		goto out;

#ifdef MC_SUPPORT_MLD
	p = &mc->mld_acl.patterns[0];
	for (i = 0; i < mc->mld_acl.pattern_count; i++) {
		total++;
		if (num >= num_entrys) {
			ret = -EAGAIN;
			continue;
		}

		entry->pattern_type = MC_ACL_PATTERN_MLD;
		entry->pattern.rule = p[i].rule;
		memcpy(entry->pattern.mac, p[i].mac, ETH_ALEN);
		memcpy(entry->pattern.mac_mask, p[i].mac_mask, ETH_ALEN);
		memcpy(entry->pattern.ip, &p[i].ip.ip6, sizeof(entry->pattern.ip));
		memcpy(entry->pattern.ip_mask, &p[i].ip_mask.ip6_mask, sizeof(entry->pattern.ip_mask));

		entry++;
		num++;
	}
#endif
out:
	if (bytes_written)
		*bytes_written = num * sizeof(*entry);

	if (bytes_needed) {
		if (ret == -EAGAIN)
			*bytes_needed = total * sizeof(*entry);
		else
			*bytes_needed = 0;
	}
	return ret;
}

/* call with rcu_read_lock() */
static int mc_mdbtbl_fillbuf(struct mc_struct *mc, void *buf,
			     __be32 buflen, __be32 *bytes_written, __be32 *bytes_needed)
{
	unsigned long now = jiffies;
	struct __mc_mdb_entry *entry = buf;
	int i, total = 0, num = 0, num_entrys, ret = 0;

	num_entrys = buflen / sizeof(*entry);

	for (i = 0; i < MC_HASH_SIZE; i++) {
		struct mc_mdb_entry *mdb;
		struct hlist_node *mdbh;

		os_hlist_for_each_entry_rcu(mdb, mdbh, &mc->hash[i], hlist) {
			struct mc_port_group *pg;
			struct hlist_node *pgh;

			if (!atomic_read(&mdb->users) || hlist_empty(&mdb->pslist))
				continue;

			os_hlist_for_each_entry_rcu(pg, pgh, &mdb->pslist, pslist) {
				struct mc_fdb_group *fg;
				struct hlist_node *fgh;

				if (hlist_empty(&pg->fslist))
					continue;

				os_hlist_for_each_entry_rcu(fg, fgh, &pg->fslist, fslist) {
					total++;
					if (num >= num_entrys) {
						ret = -EAGAIN;
						continue;
					}

					if (mdb->group.pro == htons(ETH_P_IP)) {
						entry->nsrcs = fg->a.nsrcs;
						entry->group.pro = mdb->group.pro;
						entry->group.u.ip4 = mdb->group.u.ip4;
						memcpy(entry->srcs, fg->a.srcs, fg->a.nsrcs * sizeof(int));
					}
#ifdef MC_SUPPORT_MLD
					else {
						entry->nsrcs = fg->a.nsrcs;
						entry->group.pro = mdb->group.pro;
						memcpy(entry->group.u.ip6, mdb->group.u.ip6.s6_addr, sizeof(struct in6_addr));
						memcpy(entry->srcs, fg->a.srcs, fg->a.nsrcs * sizeof(struct in6_addr));
					}
#endif
					entry->ifindex = ((struct net_bridge_port *)pg->port)->dev->ifindex;
					entry->filter_mode = fg->filter_mode;
					entry->aging = jiffies_to_msecs(now - fg->ageing_timer) / 1000;
					entry->fdb_age_out = fg->fdb_age_out;
					memcpy(entry->mac, mc_fdb_mac_get(fg), ETH_ALEN);

					entry++;
					num++;
				}
			}
		}
	}

	if (bytes_written)
		*bytes_written = num * sizeof(*entry);

	if (bytes_needed) {
		if (ret == -EAGAIN)
			*bytes_needed = total * sizeof(*entry);
		else
			*bytes_needed = 0;
	}
	return ret;
}

static void *mc_find_entry_by_mdb(struct mc_struct *mc, struct mc_mdb_entry *mdb,
				  __be32 entry_size, void *param, __be32 param_len)
{
	struct mc_ip group;
	int i, entry_cnt = param_len / entry_size;
	__u8 *entry = param;

	for (i = 0; i < entry_cnt; i++, entry += entry_size) {
		struct __mc_group *entry_group = (struct __mc_group *)entry;

		memset(&group, 0, sizeof group);
		group.pro = entry_group->pro;
		if (group.pro == htons(ETH_P_IP))
			group.u.ip4 = entry_group->u.ip4;
#ifdef MC_SUPPORT_MLD
		else
			memcpy(group.u.ip6.s6_addr, entry_group->u.ip6, sizeof(struct in6_addr));
#endif

		if (!memcmp(&group, &mdb->group, sizeof(struct mc_ip)))
			return entry;
	}
	return NULL;
}

/*call with rcu_read_lock()*/
static void mc_group_list_add(struct mc_ip *pgroup, struct mc_glist_entry **ghead)
{
	struct mc_glist_entry *pge;

	pge = kmalloc(sizeof(struct mc_glist_entry), GFP_ATOMIC);
	if (!pge) {
		printk("MC out-of-memory\n");
		return;
	}

	memcpy(&pge->group, pgroup, sizeof(struct mc_ip));
	pge->next = *ghead;
	*ghead = pge;
}

void mc_group_notify_one(struct mc_struct *mc, struct mc_ip *pgroup)
{
	struct net_device *brdev;

	brdev = mc->dev;
	if (!brdev)
		return;

	if (pgroup->pro == htons(ETH_P_IP)) {
		mc_bridge_ipv4_update_callback_t ipv4_mc_event_cb;
		ipv4_mc_event_cb = mc_bridge_ipv4_update_callback_get();
		if (!ipv4_mc_event_cb)
			return;

		MC_PRINT("Group "MC_IP4_STR"  changed\n", MC_IP4_FMT((u8 *)&pgroup->u.ip4));
		ipv4_mc_event_cb(brdev, pgroup->u.ip4);
	}
#ifdef MC_SUPPORT_MLD
	else {
		mc_bridge_ipv6_update_callback_t ipv6_mc_event_cb;
		ipv6_mc_event_cb = mc_bridge_ipv6_update_callback_get();
		if (!ipv6_mc_event_cb)
			return;

		MC_PRINT("Group "MC_IP6_STR"  changed\n", MC_IP6_FMT((__be16 *)&pgroup->u.ip6));
		ipv6_mc_event_cb(brdev, &pgroup->u.ip6);
	}
#endif
}


/*call with lock-free*/
static void mc_group_notify(struct mc_struct *mc, struct mc_glist_entry **ghead)
{
	struct mc_glist_entry *pge;
	struct mc_glist_entry *prev;

	pge = *ghead;
	*ghead = NULL;

	while (pge) {
		mc_group_notify_one(mc, &pge->group);
		prev = pge;
		pge = pge->next;
		kfree(prev);
	}

}

static void mc_set_psw_encap(struct mc_struct *mc, void *param, __be32 param_len)
{
	int i, entry_cnt = param_len / sizeof(struct __mc_encaptbl_entry);
	struct __mc_encaptbl_entry *entry = param;

	MC_PRINT("%s: %s encap table\n", __func__, entry_cnt ? "Update" : "Clear");
	for (i = 0; i < MC_HASH_SIZE; i++) {
		struct mc_mdb_entry *mdb;
		struct hlist_node *mdbh;
		os_hlist_for_each_entry_rcu(mdb, mdbh, &mc->hash[i], hlist) {
			write_lock_bh(&mdb->rwlock);
			if (entry_cnt && ((entry = mc_find_entry_by_mdb(mc, mdb,
								sizeof(struct __mc_encaptbl_entry), param, param_len)) != NULL)) {
				mdb->encap_dev_cnt = entry->dev_cnt > MC_ENCAP_DEV_MAX ? MC_ENCAP_DEV_MAX : entry->dev_cnt;
				memcpy(mdb->encap_dev, entry->dev,	entry->dev_cnt * sizeof(struct __mc_encaptbl_dev));
			} else {
				mdb->encap_dev_cnt = 0;
				memset(mdb->encap_dev, 0,  sizeof(mdb->encap_dev));
			}
			write_unlock_bh(&mdb->rwlock);
		}
	}
}

static void mc_set_psw_flood(struct mc_struct *mc, void *param, __be32 param_len, struct mc_glist_entry **ghead)
{
	int i, entry_cnt = param_len / sizeof(struct __mc_floodtbl_entry);
	struct __mc_floodtbl_entry *entry = param;
	int    flood_ifcnt;
	int    entry_changed;

	MC_PRINT("%s: Update flood table\n", __func__);
	for (i = 0; i < MC_HASH_SIZE; i++) {
		struct mc_mdb_entry *mdb;
		struct hlist_node *mdbh;
		os_hlist_for_each_entry_rcu(mdb, mdbh, &mc->hash[i], hlist) {
			entry_changed = 0;

			write_lock_bh(&mdb->rwlock);
			if (entry_cnt && ((entry = mc_find_entry_by_mdb(mc, mdb,
								sizeof(struct __mc_floodtbl_entry), param, param_len)) != NULL)) {
				flood_ifcnt = mdb->flood_ifcnt;
				mdb->flood_ifcnt = entry->ifcnt > MC_FLOOD_IF_MAX ? MC_FLOOD_IF_MAX : entry->ifcnt;
				if (flood_ifcnt != mdb->flood_ifcnt ||
					memcmp(mdb->flood_ifindex, entry->ifindex, entry->ifcnt * sizeof(__be32)))
					entry_changed = 1;
				memcpy(mdb->flood_ifindex, entry->ifindex, entry->ifcnt * sizeof(__be32));
			} else {
				if (mdb->flood_ifcnt != 0)
					entry_changed = 1;
				mdb->flood_ifcnt = 0;
				memset(mdb->flood_ifindex, 0, sizeof(mdb->flood_ifindex));
			}
			write_unlock_bh(&mdb->rwlock);

			if (entry_changed) {
				mc_group_list_add(&mdb->group, ghead);
			}
		}
	}
}

static void __mc_netlink_receive(struct sk_buff *__skb)
{
	struct net_device *brdev = NULL;
	struct sk_buff *skb;
	struct nlmsghdr *nlh = NULL;
	void *msgdata = NULL;
	u32 pid, seq, msgtype;
	struct __mcctl_msg_header *msghdr;
	struct mc_struct *mc = NULL;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 10, 0))
	if ((skb = skb_clone(__skb, GFP_ATOMIC)) == NULL)
#else
	if ((skb = skb_get(__skb)) == NULL)
#endif
		return;

	/* process netlink message pointed by skb->data */
	nlh = nlmsg_hdr(skb);
	pid = nlh->nlmsg_pid;
	seq = nlh->nlmsg_seq;
	msghdr = NLMSG_DATA(nlh);
	msghdr->status = MC_STATUS_SUCCESS;
	msgdata = MC_MSG_DATA(nlh);
	msgtype = nlh->nlmsg_type;

	do {
		brdev = dev_get_by_name(&init_net, msghdr->if_name);

		if (!brdev) {
			printk("Not a bridge device, or device not found: %s\n", msghdr->if_name);
			msghdr->status = MC_STATUS_NOT_FOUND;
			break;
		}

		if ((mc = MC_DEV(brdev)) == NULL && msgtype != MC_MSG_SET_ENABLE) {
			printk("%s: mc module is not registered!\n", __func__);
			msghdr->status = MC_STATUS_FAILURE;
			dev_put(brdev);
			break;
		}

		switch (msgtype) {
		case MC_MSG_SET_ENABLE:
			{
				struct __mc_param_value *e = (struct __mc_param_value *)msgdata;
				if (e->val) {
					if (mc_attach(brdev) == 0)
						printk("%s: Enable bridge snooping!\n", __func__);
					else
						printk("%s: Failed to enable bridge snooping!\n", __func__);
				} else {
					mc_detach(brdev);
					printk("%s: Disable bridge snooping!\n", __func__);
				}
			}
			break;
		case MC_MSG_SET_EVENT_PID:
			{
				struct __event_info *p = msgdata;
				mc->event_pid = p->event_pid;
				MC_PRINT(KERN_INFO "%s: Set event process id %d\n", __func__, p->event_pid);
			}
			break;
		case MC_MSG_SET_DEBUG:
			{
				struct __mc_param_value *e = (struct __mc_param_value *)msgdata;
				mc->debug = e->val;
				MC_PRINT(KERN_INFO "%s: %s MC debug\n", __func__, e->val ? "Enable" : "Disable");
			}
			break;
		case MC_MSG_SET_POLICY:
			{
				struct __mc_param_value *p = (struct __mc_param_value *)msgdata;
				mc->forward_policy = p->val;
				MC_PRINT(KERN_INFO "%s: Set the forward policy %s\n", __func__,
						p->val == MC_POLICY_FLOOD ? "FLOOD" : "DROP");
			}
			break;
		case MC_MSG_SET_MEMBERSHIP_INTERVAL:
			{
				struct __mc_param_value *mi = (struct __mc_param_value *)msgdata;
				mc->membership_interval = mi->val * HZ;
				MC_PRINT(KERN_INFO "%s: Set membership interval to %ds\n", __func__, mi->val);
			}
			break;
		case MC_MSG_SET_RETAG:
			{
				struct __mc_param_retag *t = (struct __mc_param_retag *)msgdata;
				mc->enable_retag = t->enable;
				mc->dscp = t->dscp & 0xff;
				MC_PRINT(KERN_INFO "%s: %s retag, DSCP=%02x\n", __func__, t->enable ? "Enable" : "Disable", mc->dscp);
			}
			break;
		case MC_MSG_SET_ROUTER_PORT:
			{
				struct __mc_param_router_port *rp = (struct __mc_param_router_port *)msgdata;
				if (rp->type >= MC_RTPORT_MAX) {
					MC_PRINT(KERN_ERR "%s: Invalid router port type %d!\n", __func__, rp->type);
				} else {
					mc->rp.type = rp->type;
					mc->rp.ifindex = rp->ifindex;
					MC_PRINT(KERN_INFO "%s: Set router port type=%d, ifindex=%d\n", __func__, rp->type, rp->ifindex);
				}
			}
			break;
		case MC_MSG_SET_ADD_ACL_RULE:
			{
				spin_lock_bh(&mc->lock);
				mc_acltbl_update(mc, msgdata);
				spin_unlock_bh(&mc->lock);
			}
			break;
		case MC_MSG_SET_FLUSH_ACL_RULE:
			{
				spin_lock_bh(&mc->lock);
				mc_acltbl_flush(mc, msgdata);
				spin_unlock_bh(&mc->lock);
			}
			break;
		case MC_MSG_SET_CONVERT_ALL:
			{
				struct __mc_param_value *e = (struct __mc_param_value *)msgdata;
				mc->convert_all = e->val;
				MC_PRINT(KERN_INFO "%s: %s MC convert all.\n", __func__, e->val ? "Enable" : "Disable");
			}
			break;
		case MC_MSG_SET_TIMEOUT:
			{
				struct __mc_param_timeout *t = (struct __mc_param_timeout *)msgdata;
				switch (t->from) {
				case MC_TIMEOUT_FROM_GROUP_SPECIFIC_QUERIES:
					mc->timeout_gsq_enable = t->enable;
					MC_PRINT("%s: %s timeout from %s.\n", __func__,
						t->enable ? "Enable" : "Disable", "group specific queries");
					break;
				case MC_TIMEOUT_FROM_ALL_SYSTEM_QUERIES:
					mc->timeout_asq_enable = t->enable;
					MC_PRINT("%s: %s timeout from %s.\n", __func__,
							t->enable ? "Enable" : "Disable", "all system queries");
					break;
				case MC_TIMEOUT_FROM_GROUP_MEMBERSHIP_INTERVAL:
					mc->timeout_gmi_enable = t->enable;
					MC_PRINT("%s: %s timeout from %s.\n", __func__,
							t->enable ? "Enable" : "Disable", "group membership interval");
					break;
				default:
					MC_PRINT("%s: Set timeout failed, invalid value %d.\n", __func__, t->from);
				}
			}
			break;
		case MC_MSG_SET_M2I3_FILTER:
			{
				struct __mc_param_value *e = (struct __mc_param_value *)msgdata;
				mc->m2i3_filter_enable = e->val;
				MC_PRINT(KERN_INFO "%s: %s IGMPv3/MLDv2 Leave Filter.\n", __func__, e->val ? "Enable" : "Disable");
			}
			break;
		case MC_MSG_SET_TBIT:
			{
				struct __mc_param_value *e = (struct __mc_param_value *)msgdata;
				mc->ignore_tbit = e->val;
				MC_PRINT(KERN_INFO "%s: %s 'ignore T-bit'.\n", __func__, e->val ? "Enable" : "Disable");
			}
			break;
		case MC_MSG_SET_LOCAL_QUERY_INTERVAL:
			{
				struct __mc_param_value *i = (struct __mc_param_value *)msgdata;
				if (i->val) {
					spin_lock_bh(&mc->lock);
					mc->local_query_interval = i->val * HZ;
					if (timer_pending(&mc->qtimer) ?
						time_after(mc->qtimer.expires, jiffies + mc->local_query_interval) :
							try_to_del_timer_sync(&mc->qtimer) >= 0) {
						if (mc->started)
							mod_timer(&mc->qtimer, jiffies + mc->local_query_interval);
					}
					spin_unlock_bh(&mc->lock);
				}
				MC_PRINT(KERN_INFO "%s: Set local query interval to %u\n", __func__, i->val);
			}
			break;
		case MC_MSG_SET_PSW_ENCAP:
			{
				mc_set_psw_encap(mc, msgdata, msghdr->buf_len);
			}
			break;
		case MC_MSG_SET_PSW_FLOOD:
			{
				struct mc_glist_entry *ghead = NULL;
				mc_set_psw_flood(mc, msgdata, msghdr->buf_len, &ghead);
				mc_group_notify(mc, &ghead);
			}
			break;
		case MC_MSG_GET_ACL:
			{
				spin_lock_bh(&mc->lock);
				if (mc_acltbl_fillbuf(mc, msgdata, msghdr->buf_len,
						&msghdr->bytes_written, &msghdr->bytes_needed))
					msghdr->status = MC_STATUS_BUFFER_OVERFLOW;
				spin_unlock_bh(&mc->lock);
			}
			break;
		case MC_MSG_GET_MDB:
			{
				if (mc_mdbtbl_fillbuf(mc, msgdata, msghdr->buf_len,
							&msghdr->bytes_written, &msghdr->bytes_needed))
					msghdr->status = MC_STATUS_BUFFER_OVERFLOW;
			}
			break;
		case MC_MSG_SET_ROUTER:
			{
				struct __mc_param_value *e = (struct __mc_param_value *)msgdata;
				mc->multicast_router = e->val;
				MC_PRINT(KERN_INFO "%s: %s multicast router.\n", __func__, e->val ? "Enable" : "Disable");
			}
			break;
		default:
			MC_PRINT("mc: Unknown message type 0x%x\n", msgtype);
			msghdr->status = MC_STATUS_INVALID_PARAMETER;
			break;
		} /* switch */
		dev_put(brdev);
	} while (0);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 7, 0))
	NETLINK_CB(skb).portid = 0; /* from kernel */
#else
	NETLINK_CB(skb).pid = 0; /* from kernel */
#endif
	NETLINK_CB(skb).dst_group = 0; /* unicast */
	netlink_unicast(mc_nl_sk, skb, pid, MSG_DONTWAIT);
}


static void mc_netlink_receive(struct sk_buff *__skb)
{
	rcu_read_lock();
	__mc_netlink_receive(__skb);
	rcu_read_unlock();
}


void mc_netlink_event_send(struct mc_struct *mc, u32 event_type, u32 event_len, void *event_data)
{
	struct sk_buff *skb;
	struct nlmsghdr *nlh;
	int send_msg = 1;

	if (!mc || mc->event_pid == MC_INVALID_PID ||
			event_type >= MC_EVENT_MAX)
		return;

	if ((skb = nlmsg_new(event_len, gfp_any())) == NULL) {
		MC_PRINT("nlmsg_new failed, event_type=%d\n", event_type);
		return;
	}

	if ((nlh = nlmsg_put(skb, mc->event_pid, 0, event_type, event_len, 0)) == NULL) {
		MC_PRINT("nlmsg_put failed, event_type=%d\n", event_type);
		kfree_skb(skb);
		return;
	}

	switch (event_type) {
	case MC_EVENT_MDB_UPDATED:
		/* No data; recipient needs to ask for the updated mdb table */
		break;

	default:
		MC_PRINT("event type %d is not supported\n", event_type);
		send_msg = 0;
		kfree_skb(skb);
		break;
	}

	if (send_msg) {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 7, 0))
		NETLINK_CB(skb).portid = 0; /* from kernel */
#else
		NETLINK_CB(skb).pid = 0; /* from kernel */
#endif
		NETLINK_CB(skb).dst_group = 0; /* unicast */
		netlink_unicast(mc_nl_sk, skb, mc->event_pid, MSG_DONTWAIT);
	}
}

int __init mc_netlink_init(void)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 6, 0))
	struct netlink_kernel_cfg nlcfg;
	memset(&nlcfg, 0, sizeof(nlcfg));
	nlcfg.groups = 0;
	nlcfg.input = mc_netlink_receive;
	mc_nl_sk = netlink_kernel_create(&init_net,
			NETLINK_QCA_MC,
			&nlcfg);
#else
	mc_nl_sk = netlink_kernel_create(&init_net,
			NETLINK_QCA_MC,
			0,
			mc_netlink_receive,
			NULL,
			THIS_MODULE);
#endif
	if (mc_nl_sk == NULL)
		goto err;

	return 0;
err:
	printk("mc: Failed to create netlink socket\n");
	return -ENODEV;
}

void mc_netlink_exit(void)
{
	if (mc_nl_sk) {
		sock_release(mc_nl_sk->sk_socket);
		mc_nl_sk = NULL;
	}
}

