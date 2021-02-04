/*
 * Implements a dummy match to allow attaching IDs to rules
 *
 * 2014-08-01 Jo-Philipp Wich <jow@openwrt.org>
 */

#include <linux/module.h>
#include <linux/skbuff.h>
#include <linux/netfilter/x_tables.h>
#include <linux/netfilter/xt_id.h>

MODULE_AUTHOR("Jo-Philipp Wich <jow@openwrt.org>");
MODULE_DESCRIPTION("Xtables: No-op match which can be tagged with a 32bit ID");
MODULE_LICENSE("GPL");
MODULE_ALIAS("ipt_id");
MODULE_ALIAS("ip6t_id");

static bool
id_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	/* We always match */
	return true;
}

static struct xt_match id_mt_reg __read_mostly = {
	.name      = "id",
	.revision  = 0,
	.family    = NFPROTO_UNSPEC,
	.match     = id_mt,
	.matchsize = sizeof(struct xt_id_info),
	.me        = THIS_MODULE,
};

static int __init id_mt_init(void)
{
	return xt_register_match(&id_mt_reg);
}

static void __exit id_mt_exit(void)
{
	xt_unregister_match(&id_mt_reg);
}

module_init(id_mt_init);
module_exit(id_mt_exit);
