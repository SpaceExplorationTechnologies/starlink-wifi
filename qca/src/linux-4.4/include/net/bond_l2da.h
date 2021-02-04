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

#ifndef __BOND_L2DA_H__
#define __BOND_L2DA_H__

#include <linux/list.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/hashtable.h>
#include <linux/rwlock.h>

#define BOND_L2A_HASHTABLE_BITS 3

/* L2DA Exported structures to the main bonding code */
struct l2da_bond_info {
	DECLARE_HASHTABLE(da_matrix, BOND_L2A_HASHTABLE_BITS); /*DA:iface map*/
	struct slave *default_slave; /* Default slave */
	rwlock_t lock;
	atomic_t opts;
	int multimac;
};

/* l2DA Exported functions to the main bonding code */
int bond_l2da_initialize(struct bonding *bond);
void bond_l2da_deinitialize(struct bonding *bond);
int bond_l2da_bind_slave(struct bonding *bond, struct slave *slave);
void bond_l2da_unbind_slave(struct bonding *bond, struct slave *slave);
int bond_l2da_xmit(struct sk_buff *skb, struct net_device *dev);
bool bond_l2da_handle_rx_frame(struct bonding *bond, struct slave *slave,
			       struct sk_buff *skb);
void bond_l2da_set_opts(struct bonding *bond, u32 opts);
u32 bond_l2da_get_opts(struct bonding *bond);
int bond_l2da_set_default_slave(struct bonding *bond, struct slave *slave);
int bond_l2da_get_default_slave_name(struct bonding *bond, char *buf, int size);
int bond_l2da_set_da_slave(struct bonding *bond, const unsigned char *da,
			   struct slave *slave);
int bond_l2da_del_da(struct bonding *bond, const unsigned char *da);
void bond_l2da_purge(struct bonding *bond);
void bond_l2da_handle_link_change(struct bonding *bond, struct slave *slave);
void bond_l2da_call_foreach(struct bonding *bond,
			    int (*clb)(const unsigned char *da,
				       struct slave *slave,
				       void *ctx),
			    void *ctx);
struct net_device *bond_l2da_get_tx_dev(uint8_t *dest_mac,
					struct net_device *bond_dev);
#endif /* __BOND_L2DA_H__ */
