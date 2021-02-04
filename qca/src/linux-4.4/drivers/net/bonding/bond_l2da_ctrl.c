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

#include <net/bonding.h>
#include <net/bond_l2da.h>
#include "bond_l2da_ctrl.h"

int  _bond_l2da_ctrl_try_lock(struct bonding *bond, bool set)
{
	if (!rtnl_trylock())
		return restart_syscall();

	if (!bond_is_l2da(bond)) {
		pr_info("%s: not in L2DA mode\n", netdev_name(bond->dev));
		rtnl_unlock();
		return -EINVAL;
	}

	if (set)
		block_netpoll_tx();

	return 0;
}

void _bond_l2da_ctrl_unlock(struct bonding *bond, bool set)
{
	if (set)
		unblock_netpoll_tx();
	rtnl_unlock();
}

int bond_l2da_ctrl_set_default(struct bonding *bond, const char *slave_ifname)
{
	struct slave *slave;
	struct list_head *iter;
	int ret = -EINVAL;
	struct slave *prev_default_slave;
	struct l2da_bond_info *bond_info = &bond->l2da_info;
	struct bond_cb *bond_cb_ref;

	ret = _bond_l2da_ctrl_try_lock(bond, true);
	if (ret)
		return ret;

	prev_default_slave = bond_info->default_slave;
	bond_for_each_slave(bond, slave, iter) {
		if (!strncmp(netdev_name(slave->dev), slave_ifname, IFNAMSIZ)) {
			if (slave->link == BOND_LINK_UP &&
			    bond_slave_is_up(slave))
				ret = bond_l2da_set_default_slave(bond, slave);
			else
				pr_warn("%s: cannot set %s as default slave\n",
					netdev_name(bond->dev),
					netdev_name(slave->dev));

			break;
		}
	}

	if (ret < 0)
		pr_err("%s: Unable to to set %s as default slave\n",
		       netdev_name(bond->dev), slave_ifname);

	rcu_read_lock();
	bond_cb_ref = rcu_dereference(bond_cb);
	if (!ret && prev_default_slave && bond_cb_ref &&
	    bond_cb_ref->bond_cb_delete_by_slave)
		bond_cb_ref->bond_cb_delete_by_slave(prev_default_slave->dev);
	rcu_read_unlock();

	_bond_l2da_ctrl_unlock(bond, true);

	return ret;
}

int bond_l2da_ctrl_get_default(struct bonding *bond, char *buf, int size)
{
	int ret;

	ret = _bond_l2da_ctrl_try_lock(bond, false);
	if (ret)
		return ret;

	ret = bond_l2da_get_default_slave_name(bond, buf, size);

	_bond_l2da_ctrl_unlock(bond, false);
	return ret;
}

int bond_l2da_ctrl_change_map_entry(struct bonding *bond,
				    const u8 *da,
				    const char *slave_ifname)
{
	int ret;
	struct slave *slave;
	struct list_head *iter;
	bool slave_found;

	if (!is_valid_ether_addr(da)) {
		pr_err("%s: Invalid L2DA MAC address: %pM\n",
		       netdev_name(bond->dev), da);
		return -EINVAL;
	}

	if (slave_ifname && !dev_valid_name(slave_ifname)) {
		pr_err("%s: Invalid L2DA slave name: '%s'\n",
		       netdev_name(bond->dev), slave_ifname);
		return -EINVAL;
	}

	ret = _bond_l2da_ctrl_try_lock(bond, true);
	if (ret)
		return ret;

	if (slave_ifname) {
		slave_found = false;
		bond_for_each_slave(bond, slave, iter) {
			if (!strncmp(netdev_name(slave->dev), slave_ifname,
				     IFNAMSIZ)) {
				slave_found = true;
				ret = bond_l2da_set_da_slave(bond, da, slave);
				break;
			}
		}
		if (!slave_found) {
			ret = -EINVAL;
			pr_err("%s: L2DA cannot find slave: %s\n",
			       netdev_name(bond->dev), slave_ifname);
		}
	} else {
		ret = bond_l2da_del_da(bond, da);
	}

	_bond_l2da_ctrl_unlock(bond, true);

	bond_notify_l2da((uint8_t *)da);

	return ret;
}

int bond_l2da_ctrl_reset_map(struct bonding *bond)
{
	int ret = _bond_l2da_ctrl_try_lock(bond, true);

	if (ret)
		return ret;

	bond_l2da_purge(bond);

	_bond_l2da_ctrl_unlock(bond, true);

	return ret;
}

int bond_l2da_ctrl_set_opts(struct bonding *bond, u32 opts)
{
	int ret = _bond_l2da_ctrl_try_lock(bond, true);

	if (ret)
		return ret;

	bond_l2da_set_opts(bond, opts);

	_bond_l2da_ctrl_unlock(bond, true);
	return 0;
}

int bond_l2da_ctrl_get_opts(struct bonding *bond, u32 *opts)
{
	int ret = _bond_l2da_ctrl_try_lock(bond, false);

	if (ret)
		return ret;

	*opts = bond_l2da_get_opts(bond);

	_bond_l2da_ctrl_unlock(bond, false);
	return 0;
}
