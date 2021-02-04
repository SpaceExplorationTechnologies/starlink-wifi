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

#include <net/genetlink.h>
#include <linux/if_bonding_genl.h>
#include <linux/if_ether.h>

#include <net/bonding.h>
#include "bond_genl.h"
#include <net/bond_l2da.h>
#include "bond_l2da_ctrl.h"

struct bond_genl_ops_l2da_get_map_ctx {
	struct sk_buff *msg;
	int             cnt;
	int             last_ret;
};

struct net_device *bond_device_from_info(struct genl_info *info)
{
	struct net *net = genl_info_net(info);
	struct net_device *bond_dev;
	char *bond_name;

	if (!info->attrs[BOND_GENL_ATTR_BOND_NAME]) {
		pr_err("BOND_GENL_ATTR_BOND_NAME must be defined\n");
		return NULL;
	}
	bond_name = nla_data(info->attrs[BOND_GENL_ATTR_BOND_NAME]);
	pr_debug("device_from_info: bond_name = %s\n", bond_name);

	bond_dev = dev_get_by_name(net, bond_name);
	if (!bond_dev) {
		pr_err("device_from_info: cannot find bond netdev for %s\n",
		       bond_name);
		return NULL;
	}

	return bond_dev;
}

static int bond_genl_pre_doit(const struct genl_ops *ops, struct sk_buff *skb,
			      struct genl_info *info)
{
	struct net_device *bond_dev;

	bond_dev = bond_device_from_info(info);
	if (!bond_dev)
		return -EINVAL;

	info->user_ptr[0] = bond_dev;
	return 0;
}

static void bond_genl_post_doit(const struct genl_ops *ops, struct sk_buff *skb,
				struct genl_info *info)
{
	WARN_ON(!info->user_ptr[0]);
	dev_put(info->user_ptr[0]);
}

static struct genl_family l2da_nl_family = {
	.id        = GENL_ID_GENERATE,
	.name      = BOND_GENL_NAME,
	.version   = BOND_GENL_VERSION,
	.hdrsize   = 0,
	.maxattr   = BOND_GENL_ATTR_LAST - 1,
	.netnsok   = true,
	.pre_doit  = bond_genl_pre_doit,
	.post_doit = bond_genl_post_doit,
};

static inline void *bond_hdr_put(struct sk_buff *skb, u32 portid, u32 seq,
				 int flags, u8 cmd)
{
	/* since there is no private header just add the generic one */
	return genlmsg_put(skb, portid, seq, &l2da_nl_family, flags, cmd);
}

static int bond_genl_ops_l2da_set_default(struct sk_buff *skb,
					  struct genl_info *info)
{
	char *slave_name;
	struct bonding *bond;

	WARN_ON(!info->user_ptr[0]);

	if (!info->attrs[BOND_GENL_ATTR_SLAVE_NAME]) {
		pr_err("l2da_set_default: BOND_GENL_ATTR_SLAVE_NAME must be defined\n");
		return -EINVAL;
	}

	slave_name = nla_data(info->attrs[BOND_GENL_ATTR_SLAVE_NAME]);

	bond = netdev_priv(info->user_ptr[0]);

	return bond_l2da_ctrl_set_default(bond, slave_name);
}

static int bond_genl_ops_l2da_map_change(struct genl_info *info, int add)
{
	char *slave_name = NULL;
	struct bonding *bond;
	u8 *da;

	WARN_ON(!info->user_ptr[0]);

	if (add) {
		if (!info->attrs[BOND_GENL_ATTR_SLAVE_NAME]) {
			pr_err("l2da_map_change: BOND_GENL_ATTR_SLAVE_NAME must be defined\n");
			return -EINVAL;
		}

		slave_name = nla_data(info->attrs[BOND_GENL_ATTR_SLAVE_NAME]);
	}

	if (!info->attrs[BOND_GENL_ATTR_MAC]) {
		pr_err("l2da_map_change: BOND_GENL_ATTR_MAC must be defined\n");
		return -EINVAL;
	}

	if (nla_len(info->attrs[BOND_GENL_ATTR_MAC]) != ETH_ALEN) {
		pr_err("l2da_map_change: BOND_GENL_ATTR_MAC must be of %d bytes long\n",
		       ETH_ALEN);
		return -EINVAL;
	}

	da =  nla_data(info->attrs[BOND_GENL_ATTR_MAC]);

	bond = netdev_priv(info->user_ptr[0]);

	return bond_l2da_ctrl_change_map_entry(bond, da, slave_name);
}

static int bond_genl_ops_l2da_add_map(struct sk_buff *skb,
				      struct genl_info *info)
{
	return bond_genl_ops_l2da_map_change(info, 1);
}

static int bond_genl_ops_l2da_del_map(struct sk_buff *skb,
				      struct genl_info *info)
{
	return bond_genl_ops_l2da_map_change(info, 0);
}

static int bond_genl_ops_l2da_get_default(struct sk_buff *skb,
					  struct genl_info *info)
{
	struct bonding *bond;
	struct sk_buff *msg = NULL;
	void *hdr = NULL;
	char ifname[IFNAMSIZ + 1];

	WARN_ON(!info->user_ptr[0]);

	bond = netdev_priv(info->user_ptr[0]);

	if (bond_l2da_ctrl_get_default(bond, ifname, sizeof(ifname)))
		return -EINVAL;

	msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
	if (!msg)
		return -ENOMEM;

	hdr = bond_hdr_put(msg, info->snd_portid, info->snd_seq, 0,
			   BOND_GENL_CMD_L2DA_GET_DEFAULT);
	if (!hdr)
		goto out;

	if (nla_put_string(msg, BOND_GENL_ATTR_SLAVE_NAME, ifname))
		goto out;

	genlmsg_end(msg, hdr);

	return genlmsg_reply(msg, info);

out:
	if (hdr)
		genlmsg_cancel(msg, hdr);

	nlmsg_free(msg);
	return -EMSGSIZE;
}

static int bond_genl_ops_l2da_get_map_clb(const unsigned char *da,
					  struct slave *slave, void *_ctx)
{
	int ret = -ENOBUFS;
	struct bond_genl_ops_l2da_get_map_ctx *ctx = _ctx;
	struct nlattr *nl_entry;

	nl_entry = nla_nest_start(ctx->msg, ctx->cnt + 1);
	if (!nl_entry)
		goto nla_put_failure;

	if (nla_put_string(ctx->msg, BOND_GENL_ATTR_SLAVE_NAME,
			   netdev_name(slave->dev)))
		goto nla_put_failure;

	if (nla_put(ctx->msg, BOND_GENL_ATTR_MAC, ETH_ALEN, da))
		goto nla_put_failure;

	nla_nest_end(ctx->msg, nl_entry);

	++ctx->cnt;
	ret = 0;

nla_put_failure:
	ctx->last_ret = ret;
	return ret;
}

static int bond_genl_ops_l2da_get_map(struct sk_buff *skb,
				      struct genl_info *info)
{
	struct bonding *bond;
	struct sk_buff *msg = NULL;
	void *hdr = NULL;
	struct nlattr *nl_nodes;
	struct bond_genl_ops_l2da_get_map_ctx ctx;
	int ret = -ENOMEM;

	WARN_ON(!info->user_ptr[0]);

	bond = netdev_priv(info->user_ptr[0]);

	msg = nlmsg_new(4096, GFP_KERNEL);
	if (!msg)
		goto out;

	hdr = bond_hdr_put(msg, info->snd_portid, info->snd_seq, 0,
			   BOND_GENL_CMD_L2DA_GET_MAP);
	if (!hdr)
		goto out;

	memset(&ctx, 0, sizeof(ctx));

	nl_nodes = nla_nest_start(msg, BOND_GENL_ATTR_L2DA_MAP);
	if (!nl_nodes)
		goto out;

	ret = _bond_l2da_ctrl_try_lock(bond, false);
	if (ret)
		goto out;

	bond_l2da_call_foreach(bond, bond_genl_ops_l2da_get_map_clb, &ctx);

	_bond_l2da_ctrl_unlock(bond, false);

	if (ctx.last_ret)
		goto out;

	nla_nest_end(msg, nl_nodes);

	genlmsg_end(msg, hdr);

	return genlmsg_reply(msg, info);

out:
	if (hdr)
		genlmsg_cancel(msg, hdr);
	if (msg)
		nlmsg_free(msg);
	return ret;
}

static int bond_genl_ops_l2da_reset_map(struct sk_buff *skb,
					struct genl_info *info)
{
	struct bonding *bond;
	int ret;

	WARN_ON(!info->user_ptr[0]);

	bond = netdev_priv(info->user_ptr[0]);

	ret = bond_l2da_ctrl_reset_map(bond);
	if (ret)
		pr_err("l2da_reset_map: couldn't reset map");
	else
		pr_info("l2da_reset_map: map reset successfully");

	return ret;
}

static int bond_genl_ops_l2da_set_opts(struct sk_buff *skb,
				       struct genl_info *info)
{
	u32 opts;
	struct bonding *bond;

	WARN_ON(!info->user_ptr[0]);

	if (!info->attrs[BOND_GENL_ATTR_L2DA_OPTS]) {
		pr_err("l2da_set_default: BOND_GENL_ATTR_L2DA_OPTS must be defined\n");
		return -EINVAL;
	}

	opts = nla_get_u32(info->attrs[BOND_GENL_ATTR_L2DA_OPTS]);

	bond = netdev_priv(info->user_ptr[0]);

	return bond_l2da_ctrl_set_opts(bond, opts);
}

static int bond_genl_ops_l2da_get_opts(struct sk_buff *skb,
				       struct genl_info *info)
{
	struct bonding *bond;
	struct sk_buff *msg = NULL;
	void *hdr = NULL;
	u32 opts;

	WARN_ON(!info->user_ptr[0]);

	bond = netdev_priv(info->user_ptr[0]);

	if (bond_l2da_ctrl_get_opts(bond, &opts))
		return -EINVAL;

	msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
	if (!msg)
		return -ENOMEM;

	hdr = bond_hdr_put(msg, info->snd_portid, info->snd_seq, 0,
			   BOND_GENL_CMD_L2DA_GET_OPTS);
	if (!hdr)
		goto out;

	if (nla_put_u32(msg, BOND_GENL_ATTR_L2DA_OPTS, opts))
		goto out;

	genlmsg_end(msg, hdr);

	return genlmsg_reply(msg, info);

out:
	if (hdr)
		genlmsg_cancel(msg, hdr);

	nlmsg_free(msg);
	return -EMSGSIZE;
}

static struct nla_policy l2da_nl_policy[BOND_GENL_ATTR_LAST] = {
	[BOND_GENL_ATTR_BOND_NAME] = {
		.type = NLA_STRING,
		.len = IFNAMSIZ + 1,
	},
	[BOND_GENL_ATTR_SLAVE_NAME] = {
		.type = NLA_STRING,
		.len = IFNAMSIZ + 1,
	},
	[BOND_GENL_ATTR_MAC]     = {
		.type = NLA_BINARY,
		.len = ETH_ALEN,
	},
	[BOND_GENL_ATTR_L2DA_MAP] = {
		.type = NLA_NESTED,
	},
	[BOND_GENL_ATTR_L2DA_OPTS] = {
		.type = NLA_U32,
	},
};

static const struct genl_ops l2da_nl_ops[] = {
	{
		.cmd = BOND_GENL_CMD_L2DA_SET_DEFAULT,
		.doit = bond_genl_ops_l2da_set_default,
		.policy = l2da_nl_policy,
		.flags = GENL_ADMIN_PERM,
	},
	{
		.cmd = BOND_GENL_CMD_L2DA_GET_DEFAULT,
		.doit = bond_genl_ops_l2da_get_default,
		.policy = l2da_nl_policy,
		.flags = GENL_ADMIN_PERM,
	},
	{
		.cmd = BOND_GENL_CMD_L2DA_DEL_MAP_ENTRY,
		.doit = bond_genl_ops_l2da_del_map,
		.policy = l2da_nl_policy,
		.flags = GENL_ADMIN_PERM,
	},
	{
		.cmd = BOND_GENL_CMD_L2DA_ADD_MAP_ENTRY,
		.doit = bond_genl_ops_l2da_add_map,
		.policy = l2da_nl_policy,
		.flags = GENL_ADMIN_PERM,
	},
	{
		.cmd = BOND_GENL_CMD_L2DA_GET_MAP,
		.doit = bond_genl_ops_l2da_get_map,
		.policy = l2da_nl_policy,
		.flags = GENL_ADMIN_PERM,
	},
	{
		.cmd = BOND_GENL_CMD_L2DA_RESET_MAP,
		.doit = bond_genl_ops_l2da_reset_map,
		.policy = l2da_nl_policy,
		.flags = GENL_ADMIN_PERM,
	},
	{
		.cmd = BOND_GENL_CMD_L2DA_SET_OPTS,
		.doit = bond_genl_ops_l2da_set_opts,
		.policy = l2da_nl_policy,
		.flags = GENL_ADMIN_PERM,
	},
	{
		.cmd = BOND_GENL_CMD_L2DA_GET_OPTS,
		.doit = bond_genl_ops_l2da_get_opts,
		.policy = l2da_nl_policy,
		.flags = GENL_ADMIN_PERM,
	},
};

/**
 * Initialize bond generic netlink
 *
 * Returns: 0 on success, negative error code on failure
 */
int bond_genl_initialize(void)
{
	int res;

	res = genl_register_family_with_ops(&l2da_nl_family, l2da_nl_ops);
	if (res) {
		pr_err("bond_genl registration error (%d)\n", res);
		return res;
	}

	pr_debug("bond_genl registered\n");
	return 0;
}

/**
 * Uniniialize bond generic netlink
 */
void bond_genl_deinitialize(void)
{
	genl_unregister_family(&l2da_nl_family);
	pr_debug("bond_genl unregistered\n");
}
