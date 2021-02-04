/* Copyright (c) 2016, The Linux Foundation. All rights reserved.
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

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/timer.h>
#include <linux/etherdevice.h>
#include <linux/if_bonding_genl.h>
#include <net/arp.h>
#include <net/bonding.h>
#include <net/bond_l2da.h>

#define L2DA_OPTS_DEFAULT 0

static int l2da_multimac;
module_param(l2da_multimac, int, 0);
MODULE_PARM_DESC(l2da_multimac, "Slaves will keep their own MAC addresses in L2DA mode. 0 for disabled (default), 1 for enabled.");

struct l2da_bond_matrix_entry {
	struct hlist_node hnode;
	unsigned char da[ETH_ALEN];
	struct slave *slave;
};

#define BOND_L2DA_INFO(bond) ((bond)->l2da_info)

#define SLAVE_CAN_XMIT(slave) (bond_slave_is_up(slave) && \
				((slave)->link == BOND_LINK_UP) && \
				bond_is_active_slave(slave))

static void _bond_l2da_arp_timer_handler(unsigned long data);
static DEFINE_TIMER(arp_timer, _bond_l2da_arp_timer_handler, 0, 0);
#define ARP_TIMER_TIMEOUT_TICKS (HZ + 2)

/**
 * _bond_l2da_slave_name - returns slave name
 * @slave: slave struct to work on
 *
 * Returns @slave network device name, or "null" if it can't be found.
 */
static inline const char *_bond_l2da_slave_name(struct slave *slave)
{
	if (slave && slave->dev)
		return netdev_name(slave->dev);
	return "null";
}

/**
 * _bond_l2da_hash_val - hash function for L2DA map hash table
 * @da: DA to be used as a hash key
 *
 * Returns hash value for @da
 */
static inline u32 _bond_l2da_hash_val(const unsigned char *da)
{
	return da[ETH_ALEN - 2];
}

/**
 * _bond_l2da_find_entry_unsafe - searches for DA:iface mapping within the map
 * @bond_info: L2DA bonding struct to work on
 * @da: DA to be used as a key
 *
 * Returns map entry for @da, or %NULL if it can't be found.
 *
 * The function must be called under the L2DA bonding struct lock.
 */
static struct l2da_bond_matrix_entry *
_bond_l2da_find_entry_unsafe(struct l2da_bond_info *bond_info,
			     const unsigned char *da)
{
	struct l2da_bond_matrix_entry *entry = NULL;
	u32 hash_val;

	WARN_ON(!da);

	hash_val = _bond_l2da_hash_val(da);
	hash_for_each_possible(bond_info->da_matrix, entry, hnode, hash_val)
		if (ether_addr_equal(entry->da, da))
			return entry;
	return NULL;
}

/**
 * create_and_xmit_arp - Creates a skb with the bonding IP ARP announcement
 * and sends the skb to the slave
 * @slave: The slave to send the ARP on
 */
static void bond_l2da_create_and_xmit_arp(struct slave *slave)
{
	struct sk_buff *skb;
	struct in_device *in_dev;
	struct in_ifaddr *if_addr;
	__be32 bond_ip_addr = 0;

	rcu_read_lock();
	in_dev = rcu_dereference(slave->bond->dev->ip_ptr);
	if_addr = in_dev->ifa_list;
	if (if_addr)
		bond_ip_addr = if_addr->ifa_address;

	if (!bond_ip_addr) {
		rcu_read_unlock();
		pr_info("bond_l2da: cannot find bonding IP address. Skipping ARP xmit\n");
		return;
	}

	skb = arp_create(ARPOP_REQUEST, ETH_P_ARP, bond_ip_addr, slave->dev,
			 bond_ip_addr, NULL, NULL, NULL);

	pr_debug("bond_l2da: xmit ARP announcement for %s [%pM] with IP address %pi4\n",
		 slave->dev->name, slave->dev->dev_addr, &bond_ip_addr);
	rcu_read_unlock();

	if (!skb) {
		pr_err("bond_l2da: failed to create an ARP packet\n");
		return;
	}

	bond_dev_queue_xmit(slave->bond, skb, slave->dev);
}

/**
 * _bond_l2da_arp_timer_handler - ARP timer handler
 * @data: The timer data, should be the pointer to bond_info
 */
static void _bond_l2da_arp_timer_handler(unsigned long data)
{
	struct l2da_bond_info *bond_info = (struct l2da_bond_info *)data;
	struct slave *slave = bond_info->default_slave;

	if (slave) {
		bond_l2da_create_and_xmit_arp(slave);
		pr_info("bond_l2da ARP timer invoked for slave %s\n",
			_bond_l2da_slave_name(slave));
	}
}

/**
 * bond_l2da_announce_arp - Send ARP announcement for the slave, if the options
 * allow ARP announcements
 * @slave: The slave to announce for
 */
static void bond_l2da_announce_arp(struct slave *slave)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(slave->bond);
	u32 opts = atomic_read(&bond_info->opts);

	if (opts & BOND_L2DA_OPT_AUTO_ARP_ANNOUNCE) {
		del_timer_sync(&arp_timer);
		bond_l2da_create_and_xmit_arp(slave);
		arp_timer.data = (unsigned long)&BOND_L2DA_INFO(slave->bond);
		mod_timer(&arp_timer, jiffies + ARP_TIMER_TIMEOUT_TICKS);
	}
}

/**
 * _bond_l2da_assign_default_slave
 * @bond: bonding struct to work on
 * @slave: new default slave (can be NULL)
 */
static void
_bond_l2da_assign_default_slave(struct bonding *bond, struct slave *slave)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);
	struct slave *prev_default_slave = bond_info->default_slave;

	bond_info->default_slave = slave;
	if (prev_default_slave && slave && prev_default_slave != slave) {
		if (!ether_addr_equal(prev_default_slave->dev->dev_addr,
				      slave->dev->dev_addr))
			bond_l2da_announce_arp(slave);
	} else if (!slave) {
		del_timer_sync(&arp_timer);
	}
	pr_info("bond_l2da default slave set to %s\n",
		_bond_l2da_slave_name(slave));
}

/**
 * _bond_l2da_check_default_slave_unsafe - Checks if the default slave is set
 * and up, otherwise tries to select another existing and running slave as
 * the default slave.
 * @bond: bonding struct to work on
 *
 * The function must be called under the L2DA bonding struct lock.
 */
static void
_bond_l2da_check_default_slave_unsafe(struct bonding *bond)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);
	struct slave *slave;
	struct list_head *iter;

	/* Default slave is OK, so continue to use it */
	if (bond_info->default_slave &&
	    SLAVE_CAN_XMIT(bond_info->default_slave))
		return;

	/* Select new default slave */
	bond_for_each_slave(bond, slave, iter) {
		if (slave != bond_info->default_slave &&
		    SLAVE_CAN_XMIT(slave)) {
			pr_info("bond_l2da default slave changed to %s\n",
				_bond_l2da_slave_name(slave));
			_bond_l2da_assign_default_slave(bond, slave);
			break;
		}
	}
}

/**
 * _bond_l2da_remove_entries_unsafe - removes all iface mappings from the map
 * @bond_info: L2DA bonding struct to work on
 * @slave: slave whose mappings have to be removed
 *
 * The function must be called under the L2DA bonding struct lock.
 */
static void _bond_l2da_remove_entries_unsafe(struct l2da_bond_info *bond_info,
					     struct slave *slave)
{
	struct l2da_bond_matrix_entry *entry = NULL;
	struct hlist_node *tmp;
	int counter;

	hash_for_each_safe(bond_info->da_matrix, counter, tmp, entry, hnode) {
		/* NULL slave means "remove all" */
		if (!slave || entry->slave == slave) {
			hash_del(&entry->hnode);
			bond_notify_l2da(entry->da);
			kfree(entry);
		}
	}

	if (bond_info->default_slave &&
	    (!slave || memcmp(bond_info->default_slave->dev->dev_addr,
			      slave->dev->dev_addr, ETH_ALEN)))
		bond_l2da_announce_arp(bond_info->default_slave);
}

/**
 * _bond_l2da_bridge_clone_and_xmit - clones received packet and sends it to
 *      specific slave
 * @bond: bond struct to work on
 * @slave: slave to send cloned skb to
 * @skb: received packet to be cloned and sent
 *
 * Returns: %true if forwarding succeeded, %false - otherwise
 */
static bool _bond_l2da_bridge_clone_and_xmit(struct bonding *bond,
					     struct slave *slave,
					     struct sk_buff *skb)
{
	struct sk_buff *skb2;

	if (!SLAVE_CAN_XMIT(slave))
		return false;

	skb2 = skb_clone(skb, GFP_ATOMIC);
	if (!skb2) {
		pr_err_ratelimited("%s: Error: _bond_l2da_bridge_clone_and_xmit(): skb_clone() failed\n",
				   bond->dev->name);
		return false;
	}

	skb2->protocol = htons(ETH_P_802_3);
	skb_forward_csum(skb2);
	skb_push(skb2, ETH_HLEN);
	/* bond_dev_queue_xmit always returns 0 */
	bond_dev_queue_xmit(bond, skb2, slave->dev);
	return true;
}

/**
 * _bond_l2da_bridge_flood_multicast - implements L2DA packet forwarding
 *      functionality for multicast packets. See %BOND_L2DA_OPT_FORWARD_RX for
 *      more info.
 * @bond: bond struct to work on
 * @slave: slave that received the packet
 * @skb: received multicast packet
 *
 * Returns: always %true for consistency with other _bond_l2da_bridge_flood...
 *      functions.
 */
static bool _bond_l2da_bridge_flood_multicast(struct bonding *bond,
					      struct slave *slave,
					      struct sk_buff *skb)
{
	struct list_head *iter;
	struct slave *s;

	rcu_read_lock_bh();
	bond_for_each_slave_rcu(bond, s, iter) {
		if (s == slave)
			continue;

		if (_bond_l2da_bridge_clone_and_xmit(bond, s, skb))
			pr_debug("bond_l2da: bridge: MC (SA=%pM DA=%pM) %s => %s\n",
				 eth_hdr(skb)->h_source,
				 eth_hdr(skb)->h_dest,
				 _bond_l2da_slave_name(slave),
				 _bond_l2da_slave_name(s));
	}
	rcu_read_unlock_bh();
	/* Multicast packets should also be delivered locally */
	return true;
}

/**
 * _bond_l2da_bridge_flood_unicast - implements L2DA packet forwarding
 *      functionality for unicast packets. See %BOND_L2DA_OPT_FORWARD_RX for
 *      more info.
 * @bond: bond struct to work on
 * @slave: slave that received the packet
 * @skb: received unicast packet
 *
 * Returns: %true if skb should be delivered locally, %false - otherwise
 */
static bool _bond_l2da_bridge_flood_unicast(struct bonding *bond,
					    struct slave *slave,
					    struct sk_buff *skb)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);
	struct l2da_bond_matrix_entry *entry;
	struct ethhdr *eth_data;
	bool res = true;

	eth_data = eth_hdr(skb);

	read_lock_bh(&bond_info->lock);
	/* There is no flood actually. Packet is sent to only single slave (if
	 * found in map).
	 */
	entry = _bond_l2da_find_entry_unsafe(bond_info, eth_data->h_dest);
	if (entry && entry->slave && entry->slave != slave) {
		/* We should not forward packet if entry->slave == slave
		 * (i.e. back to the slave it arrived from), as this scenario is
		 * supposed to be handled by underlying slave driver.
		 */
		if (_bond_l2da_bridge_clone_and_xmit(bond, entry->slave, skb)) {
			pr_debug("bond_l2da: bridge: UC (SA=%pM DA=%pM) %s => %s\n",
				 eth_hdr(skb)->h_source,
				 eth_hdr(skb)->h_dest,
				 _bond_l2da_slave_name(slave),
				 _bond_l2da_slave_name(entry->slave));
			res = false;
		}
	}
	read_unlock_bh(&bond_info->lock);

	return res;
}

/**
 * _bond_l2da_bridge_flood - implements L2DA packet forwarding functionality
 * @bond: bond struct to work on
 * @slave: slave that received the packet
 * @skb: received packet
 *
 * Returns: %true if skb should be delivered locally, %false - otherwise
 */
static bool _bond_l2da_bridge_flood(struct bonding *bond,
				    struct slave *slave,
				    struct sk_buff *skb)
{
	struct ethhdr *eth_data;

	if (unlikely(skb->pkt_type == PACKET_LOOPBACK))
		return true;

	eth_data = eth_hdr(skb);

	return is_multicast_ether_addr(eth_data->h_dest) ?
			_bond_l2da_bridge_flood_multicast(bond, slave, skb) :
			_bond_l2da_bridge_flood_unicast(bond, slave, skb);
}

/**
 * bond_l2da_initialize - initializes a bond's L2DA context
 * @bond: bonding struct to work on
 */
int bond_l2da_initialize(struct bonding *bond)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);

	memset(bond_info, 0, sizeof(*bond_info));
	hash_init(bond_info->da_matrix);
	rwlock_init(&bond_info->lock);
	bond_info->default_slave = NULL;
	atomic_set(&bond_info->opts, L2DA_OPTS_DEFAULT);
	bond_info->multimac = l2da_multimac;
	pr_info("bond_l2da initialized\n");
	return 0;
}

/**
 * bond_l2da_deinitialize - deinitializes a bond's L2DA context
 * @bond: bonding struct to work on
 */
void bond_l2da_deinitialize(struct bonding *bond)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);

	bond_l2da_purge(bond);
	del_timer_sync(&arp_timer);
	WARN_ON(!hash_empty(bond_info->da_matrix));
	memset(bond_info, 0, sizeof(*bond_info)); /* for debugging purposes */
	pr_info("bond_l2da de-initialized\n");
}

/**
 * bond_l2da_bind_slave - bind slave to L2DA
 * @bond: bonding struct to work on
 * @slave: slave struct to work on
 *
 * Assigns default slave (if needed).
 */
int bond_l2da_bind_slave(struct bonding *bond, struct slave *slave)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);

	write_lock_bh(&bond_info->lock);
	if (!bond_info->default_slave) {
		_bond_l2da_assign_default_slave(bond, slave);
		pr_info("bond_l2da default slave initially set to %s\n",
			_bond_l2da_slave_name(slave));
	}
	_bond_l2da_check_default_slave_unsafe(bond);
	write_unlock_bh(&bond_info->lock);
	return 0;
}

/**
 * bond_l2da_unbind_slave - unbind slave from L2DA
 * @slave: slave struct to work on
 *
 * Removes all matrix entries for this slave, re-assigns default slave (if
 * needed).
 */
void bond_l2da_unbind_slave(struct bonding *bond, struct slave *slave)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);

	write_lock_bh(&bond_info->lock);
	if (slave == bond_info->default_slave) {
		/* default slave has gone, clear it */
		_bond_l2da_assign_default_slave(bond, NULL);
	}
	_bond_l2da_remove_entries_unsafe(bond_info, slave);
	/* Check the default slave. If cleared, then choose another slave as
	 * the default one
	 */
	_bond_l2da_check_default_slave_unsafe(bond);
	write_unlock_bh(&bond_info->lock);
}

/**
 * _replace_src_mac - Replaces src mac address with the slave address. Also
 * in case of a ARP packet replaces src mac in the payload.
 *
 * @skb: skb to transmit
 * @slave: slave to send on
 * @eth_data: pointer to Ethernet header
 */
static void _replace_src_mac(struct sk_buff *skb, struct slave *slave,
			     struct ethhdr *eth_data)
{
	if (ether_addr_equal(eth_data->h_source, slave->dev->dev_addr))
		return;
	/* do not replace if h_source is not bond's mac */
	if (!ether_addr_equal(eth_data->h_source, slave->bond->dev->dev_addr))
		return;
	ether_addr_copy(eth_data->h_source, slave->dev->dev_addr);
	if (skb->protocol == htons(ETH_P_ARP)) {
		struct arp_pkt *arp = (struct arp_pkt *)skb_network_header(skb);

		if (ether_addr_equal(arp->mac_src, slave->bond->dev->dev_addr))
			ether_addr_copy(arp->mac_src, slave->dev->dev_addr);
	}
}

/**
 * _replace_dst_mac - Replaces packet's dst mac address with the bonding address
 *
 * @skb: received skb
 * @slave: slave the packet received on
 * @eth_data: pointer to Ethernet header
 */
static void _replace_dst_mac(struct sk_buff *skb, struct slave *slave,
			     struct ethhdr *eth_data)
{
	if (!ether_addr_equal(eth_data->h_dest, slave->bond->dev->dev_addr) &&
	    ether_addr_equal(eth_data->h_dest, slave->dev->dev_addr)) {
		ether_addr_copy(eth_data->h_dest, slave->bond->dev->dev_addr);
	}
}

/**
 * bond_l2da_xmit_all_slaves - send packet via all slaves at once.
 *
 * @bond: bond device that got this skb for tx.
 * @skb: hw accel VLAN tagged skb to transmit
 */
static int bond_l2da_xmit_all_slaves(struct bonding *bond, struct sk_buff *skb)
{
	struct slave *slave = NULL;
	struct list_head *iter;
	struct ethhdr *eth_data;
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);
	u32 opts = atomic_read(&bond_info->opts);

	eth_data = eth_hdr(skb);

	bond_for_each_slave_rcu(bond, slave, iter) {
		if (bond_is_last_slave(bond, slave))
			break;
		if (bond_slave_is_up(slave) && slave->link == BOND_LINK_UP) {
			struct sk_buff *skb2 = skb_clone(skb, GFP_ATOMIC);

			if (!skb2) {
				pr_err("%s: Error: bond_xmit_all_slaves(): skb_clone() failed\n",
				       bond->dev->name);
				continue;
			}
			/* bond_dev_queue_xmit always returns 0 */
			if (opts & BOND_L2DA_OPT_REPLACE_MAC)
				_replace_src_mac(skb2, slave, eth_data);
			bond_dev_queue_xmit(bond, skb2, slave->dev);
		}
	}
	if (slave && bond_slave_is_up(slave) && slave->link == BOND_LINK_UP) {
		if (opts & BOND_L2DA_OPT_REPLACE_MAC)
			_replace_src_mac(skb, slave, eth_data);
		bond_dev_queue_xmit(bond, skb, slave->dev);
	} else {
		dev_kfree_skb_any(skb);
	}

	return NETDEV_TX_OK;
}

/**
 * bond_l2da_get_tx_dev - Calculate egress interface for a given packet,
			  for a LAG that is configured in L2DA mode
 * @dst_mac: pointer to destination L2 address
 * @bond_dev: pointer to bond master device

 * Returns: Either valid slave device, or NULL otherwise
 */
struct net_device *bond_l2da_get_tx_dev(u8 *dest_mac,
					struct net_device *bond_dev)
{
	struct bonding *bond = netdev_priv(bond_dev);
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);
	struct l2da_bond_matrix_entry *entry;
	struct net_device *dest_dev = NULL;
	u32 opts = atomic_read(&bond_info->opts);

	if ((opts & BOND_L2DA_OPT_DUP_MC_TX) &&
	    (is_multicast_ether_addr(dest_mac)))
		return NULL;

	read_lock_bh(&bond_info->lock);
	entry = _bond_l2da_find_entry_unsafe(bond_info, dest_mac);
	if (entry && entry->slave && SLAVE_CAN_XMIT(entry->slave)) {
		/* if a slave configured for this DA and it's OK - use it */
		dest_dev = entry->slave->dev;
	} else if (bond_info->default_slave &&
		   SLAVE_CAN_XMIT(bond_info->default_slave)) {
		/* otherwise, if default slave is configured - use it */
		dest_dev = bond_info->default_slave->dev;
	}
	read_unlock_bh(&bond_info->lock);

	return dest_dev;
}

/* bond_l2da_xmit - transmits skb in L2DA mode
 * @skb: skb to transmit
 * @dev: bonding net device
 */
int bond_l2da_xmit(struct sk_buff *skb, struct net_device *dev)
{
	struct bonding *bond = netdev_priv(dev);
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);
	struct ethhdr *eth_data;
	struct l2da_bond_matrix_entry *entry;
	int no_slave = 0;
	u32 opts = atomic_read(&bond_info->opts);

	skb_reset_mac_header(skb);
	eth_data = eth_hdr(skb);

	if ((opts & BOND_L2DA_OPT_DUP_MC_TX) &&
	    is_multicast_ether_addr(eth_data->h_dest))
		return bond_l2da_xmit_all_slaves(bond, skb);

	read_lock_bh(&bond_info->lock);
	entry = _bond_l2da_find_entry_unsafe(bond_info, eth_data->h_dest);
	if (entry && entry->slave && SLAVE_CAN_XMIT(entry->slave)) {
		if (opts & BOND_L2DA_OPT_REPLACE_MAC)
			_replace_src_mac(skb, entry->slave, eth_data);
		/* if a slave configured for this DA and it's OK - use it */
		bond_dev_queue_xmit(bond, skb, entry->slave->dev);
	} else if (bond_info->default_slave &&
		   SLAVE_CAN_XMIT(bond_info->default_slave)) {
		if (opts & BOND_L2DA_OPT_REPLACE_MAC)
			_replace_src_mac(skb, bond_info->default_slave,
					 eth_data);
		/* otherwise, if default slave is configured - use it */
		bond_dev_queue_xmit(bond, skb, bond_info->default_slave->dev);
	} else {
		no_slave = 1;
	}
	read_unlock_bh(&bond_info->lock);

	if (no_slave) {
		/* no suitable interface, frame not sent */
		dev_kfree_skb_any(skb);
	}

	return NETDEV_TX_OK;
}

/**
 * bond_l2da_handle_rx_frame - handles RX packets on L2DA mode
 * @bond: bonding struct to work on
 * @slave: slave that received the %skb
 * @skb: received skb
 * Returns: %true for allowing this %skb to be delivered to local stack, %false
 *          for dropping it
 */
bool bond_l2da_handle_rx_frame(struct bonding *bond, struct slave *slave,
			       struct sk_buff *skb)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);
	struct ethhdr *eth_data;
	struct l2da_bond_matrix_entry *entry;
	bool res = true;
	u32 opts = atomic_read(&bond_info->opts);

	eth_data = eth_hdr(skb);

	/* if DEDUP disabled, all RX apackets are allowed */
	/* if DEDUP enabled, EAPOLs are allowed from all the slaves */
	if ((opts & BOND_L2DA_OPT_DEDUP_RX) &&
	    eth_data->h_proto != cpu_to_be16(ETH_P_PAE)) {
		/* if DEDUP enabled, non-EAPOL packets are allowed:
		 * - if there's a slave configured for this SA - only from it
		 * - else if default slave configured - only from it
		 * - else - from any slave
		 */
		read_lock_bh(&bond_info->lock);
		entry = _bond_l2da_find_entry_unsafe(bond_info,
						     eth_data->h_source);
		if (entry && entry->slave)
			res = (entry->slave->dev == skb->dev);
		else if (bond_info->default_slave)
			res = (bond_info->default_slave->dev == skb->dev);
		read_unlock_bh(&bond_info->lock);
	}

	if (res && (opts & BOND_L2DA_OPT_REPLACE_MAC))
		_replace_dst_mac(skb, slave, eth_data);

	/* DEDUP takes precedence over FORWARD, i.e. we only flood packets which
	 * are allowed for RX
	 */
	if (res && (opts & BOND_L2DA_OPT_FORWARD_RX))
		res = _bond_l2da_bridge_flood(bond, slave, skb);

	/* Fix skb packet type if our destination is bonding */
	if (res && bond_info->multimac &&
	    ether_addr_equal(eth_data->h_dest, bond->dev->dev_addr))
		skb->pkt_type = PACKET_HOST;

	if (res && (bond->dev->priv_flags & IFF_BRIDGE_PORT) &&
	    skb->pkt_type == PACKET_HOST) {
		if (unlikely(skb_cow_head(skb,
					  skb->data - skb_mac_header(skb))))
			return false;
		_replace_dst_mac(skb, slave, eth_data);
	}

	return res;
}

/**
 * bond_l2da_set_default_slave - sets default slave
 * @bond: bonding struct to work on
 * @slave: slave struct to set default
 *
 * Returns: 0 on success, negative error code on failure
 */
int bond_l2da_set_default_slave(struct bonding *bond, struct slave *slave)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);
	int res = -EINVAL;

	write_lock_bh(&bond_info->lock);
	if (SLAVE_CAN_XMIT(slave)) {
		_bond_l2da_assign_default_slave(bond, slave);
		pr_info("bond_l2da default slave set to %s\n",
			_bond_l2da_slave_name(slave));
		res = 0;
	} else {
		_bond_l2da_check_default_slave_unsafe(bond);
	}
	write_unlock_bh(&bond_info->lock);
	return res;
}

/**
 * bond_l2da_get_default_slave_name - gets name of currently configured default
 * slave
 * @bond: bonding struct to work on
 * @buf: destination buffer
 * @size: destination buffer size
 */
int bond_l2da_get_default_slave_name(struct bonding *bond, char *buf, int size)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);

	if (!buf || size < IFNAMSIZ)
		return -EINVAL;

	*buf = 0;

	read_lock_bh(&bond_info->lock);
	if (bond_info->default_slave) {
		strncpy(buf, netdev_name(bond_info->default_slave->dev),
			IFNAMSIZ);
		buf[IFNAMSIZ - 1] = 0;
	}
	read_unlock_bh(&bond_info->lock);
	return 0;
}

/**
 * bond_l2da_set_da_slave - adds DA:slave mapping
 * @bond: bonding struct to work on
 * @da: desired L2 destination address to map
 * @slave: slave to be used for sending packets to desired destination address
 */
int bond_l2da_set_da_slave(struct bonding *bond, const unsigned char *da,
			   struct slave *slave)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);
	struct l2da_bond_matrix_entry *entry;
	struct slave *prev_slave = NULL;

	write_lock_bh(&bond_info->lock);
	entry = _bond_l2da_find_entry_unsafe(bond_info, da);
	if (entry) {
		prev_slave = entry->slave;
		entry->slave = slave;
	} else {
		entry = kmalloc(sizeof(*entry), GFP_ATOMIC);
		if (!entry) {
			pr_err("bond_l2da: pair node cannot be allocated for [%pM:%s]\n",
			       da, _bond_l2da_slave_name(slave));
			write_unlock_bh(&bond_info->lock);
			return -ENOMEM;
		}
		entry->slave = slave;
		ether_addr_copy(entry->da, da);
		hash_add(bond_info->da_matrix, &entry->hnode,
			 _bond_l2da_hash_val(da));
	}
	write_unlock_bh(&bond_info->lock);

	pr_info("bond_l2da: pair %s [%pM:%s]\n",
		prev_slave ? "changed" : "added",
		da, _bond_l2da_slave_name(slave));
	if (prev_slave &&
	    memcmp(prev_slave->dev->dev_addr, slave->dev->dev_addr, ETH_ALEN))
		bond_l2da_announce_arp(slave);
	return 0;
}

/**
 * bond_l2da_set_opts - sets L2DA options
 * @bond: bonding struct to work on
 * @opts: options mask, see enum bond_genl_l2da_opts for details
 */
void bond_l2da_set_opts(struct bonding *bond, u32 opts)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);
	u32 old_opts = atomic_xchg(&bond_info->opts, opts);

	if (old_opts != opts)
		pr_info("bond_l2da: opts changed 0x%08x => 0x%08x\n",
			old_opts, opts);
}

/**
 * bond_l2da_get_opts - gets L2DA options
 * @bond: bonding struct to work on
 *
 * Returns: L2DA options value, see enum bond_genl_l2da_opts for details
 */
u32 bond_l2da_get_opts(struct bonding *bond)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);

	return atomic_read(&bond_info->opts);
}

/**
 * bond_l2da_del_da - removes DA mapping
 * @bond: bonding struct to work on
 * @da: L2 destination address whose mapping has to be removed
 */
int bond_l2da_del_da(struct bonding *bond, const unsigned char *da)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);
	struct l2da_bond_matrix_entry *entry;

	write_lock_bh(&bond_info->lock);
	entry = _bond_l2da_find_entry_unsafe(bond_info, da);
	if (entry)
		hash_del(&entry->hnode);
	write_unlock_bh(&bond_info->lock);

	if (!entry) {
		pr_err("bond_l2da: pair node cannot be found for %pM\n", da);
		return -ENOENT;
	}

	pr_info("bond_l2da: pair deleted [%pM:%s]\n",
		da, _bond_l2da_slave_name(entry->slave));
	kfree(entry);
	return 0;
}

/**
 * bond_l2da_purge - removes all DA mappings
 * @bond: bonding struct to work on
 */
void bond_l2da_purge(struct bonding *bond)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);

	write_lock_bh(&bond_info->lock);
	_bond_l2da_remove_entries_unsafe(bond_info, NULL);
	write_unlock_bh(&bond_info->lock);
}

/**
 * bond_l2da_handle_link_change - handle a slave's link status change indication
 * @bond: bonding struct to work on
 * @slave: slave struct whose link status changed
 *
 * Handle re-selection of default slave (if needed).
 */
void bond_l2da_handle_link_change(struct bonding *bond, struct slave *slave)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);
	struct slave *prev_default_slave;
	struct bond_cb *bond_cb_ref;

	write_lock_bh(&bond_info->lock);
	prev_default_slave = bond_info->default_slave;
	_bond_l2da_check_default_slave_unsafe(bond);

	rcu_read_lock();
	bond_cb_ref = rcu_dereference(bond_cb);
	if (prev_default_slave && bond_cb_ref &&
	    bond_cb_ref->bond_cb_delete_by_slave)
		bond_cb_ref->bond_cb_delete_by_slave(prev_default_slave->dev);
	rcu_read_unlock();
	write_unlock_bh(&bond_info->lock);
}

/**
 * bond_l2da_call_foreach - iterates over L2DA map
 * @bond: bonding struct to work on
 * @clb: callback function to be called for every mapping entry found
 * @ctx: user context to be passed to callback
 *
 * Callback function can return non-zero value to stop iteration.
 */
void bond_l2da_call_foreach(struct bonding *bond,
			    int (*clb)(const unsigned char *da,
				       struct slave *slave,
				       void *ctx),
			    void *ctx)
{
	struct l2da_bond_info *bond_info = &BOND_L2DA_INFO(bond);
	struct l2da_bond_matrix_entry *entry;
	int bkt;

	WARN_ON(!clb);

	read_lock_bh(&bond_info->lock);
	hash_for_each(bond_info->da_matrix, bkt, entry, hnode) {
		if (clb(entry->da, entry->slave, ctx))
			break;
	}
	read_unlock_bh(&bond_info->lock);
}
