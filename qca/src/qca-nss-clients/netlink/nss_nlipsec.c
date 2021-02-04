
/*
 **************************************************************************
 * Copyright (c) 2015-2016, The Linux Foundation. All rights reserved.
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
 * nss_nlipsec.c
 *	NSS Netlink IPsec Handler
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/types.h>
#include <linux/if.h>
#include <linux/netlink.h>
#include <linux/mutex.h>

#include <net/genetlink.h>
#include <net/sock.h>

#include <nss_api_if.h>
#include <nss_cmn.h>
#include <nss_ipsec.h>
#include <nss_ipsecmgr.h>
#include <nss_nl_if.h>
#include "nss_crypto_if.h"
#include "nss_nl.h"
#include "nss_nlcmn_if.h"
#include "nss_nlipsec_if.h"
#include "nss_nlipv6_if.h"


/* remove the "%d" and the NULL terminator */
#define NSS_NLIPSEC_TUNNEL_NAME_SZ (sizeof(NSS_IPSECMGR_TUN_NAME) - 3)

/**
 * Local protos.
 */
static int nss_nlipsec_op_create_tunnel(struct sk_buff *skb_msg, struct genl_info *info);
static int nss_nlipsec_op_destroy_tunnel(struct sk_buff *skb_msg, struct genl_info *info);
static int nss_nlipsec_op_create_encap_flow(struct sk_buff *skb, struct genl_info *info);
static int nss_nlipsec_op_destroy_encap_flow(struct sk_buff *skb, struct genl_info *info);
static int nss_nlipsec_op_destroy_encap_sa(struct sk_buff *skb, struct genl_info *info);
static int nss_nlipsec_op_create_decap_sa(struct sk_buff *skb, struct genl_info *info);
static int nss_nlipsec_op_destroy_decap_sa(struct sk_buff *skb, struct genl_info *info);

/*
 * IPsec family definition
 */
static struct genl_family nss_nlipsec_family = {
	.id = GENL_ID_GENERATE,				/* Auto generate ID */
	.name = NSS_NLIPSEC_FAMILY,			/* family name string */
	.hdrsize = sizeof(struct nss_nlipsec_rule),	/* NSS NETLINK IPsec rule */
	.version = NSS_NL_VER,				/* Set it to NSS_NL version */
	.maxattr = NSS_NLIPSEC_CMD_MAX,			/* maximum commands supported */
	.netnsok = true,
	.pre_doit = NULL,
	.post_doit = NULL,
};

/*
 * multicast group for sending message status & events
 */
static struct genl_multicast_group nss_nlipsec_mcgrp = {
	.name = NSS_NLIPSEC_FAMILY,
};

/*
 * operation table called by the generic netlink layer based on the command
 */
static struct genl_ops nss_nlipsec_ops[] = {
	{.cmd = NSS_NLIPSEC_CMD_CREATE_TUNNEL, .doit = nss_nlipsec_op_create_tunnel,},		/* create tunnel */
	{.cmd = NSS_NLIPSEC_CMD_DESTROY_TUNNEL, .doit = nss_nlipsec_op_destroy_tunnel,},	/* destroy tunnel */
	{.cmd = NSS_NLIPSEC_CMD_CREATE_ENCAP_FLOW, .doit = nss_nlipsec_op_create_encap_flow,},	/* create encap flow */
	{.cmd = NSS_NLIPSEC_CMD_DESTROY_ENCAP_FLOW, .doit = nss_nlipsec_op_destroy_encap_flow,},/* destroy encap flow */
	{.cmd = NSS_NLIPSEC_CMD_DESTROY_ENCAP_SA, .doit = nss_nlipsec_op_destroy_encap_sa,},	/* destroy encap SA */
	{.cmd = NSS_NLIPSEC_CMD_CREATE_DECAP_SA, .doit = nss_nlipsec_op_create_decap_sa,},	/* create decap SA */
	{.cmd = NSS_NLIPSEC_CMD_DESTROY_DECAP_SA, .doit = nss_nlipsec_op_destroy_decap_sa,},	/* destroy decap SA */
};

/*
 * Hold netdevice references
 */
struct nss_nlipsec_ref {
	struct mutex lock;	/* mutex for field access */
	int ifindex;		/* device interface index */
	bool valid;		/* reference is valid or invalid */
};

/*
 * Local context for the NSS_NLIPSEC
 */
struct nss_nlipsec_ctx {
	atomic_t tunnels;	/* number tunnels allocated */
	/*
	 * This table stores device reference associated
	 * to the IPsec tunnel that it has created through NETLINK
	 * thus prohibiting any spurious attempts to delete
	 * random net_devices from the Linux kernel
	 */
	struct nss_nlipsec_ref ref_tbl[NSS_IPSECMGR_MAX_TUNNELS];
};

/*
 * global context
 */
static struct nss_nlipsec_ctx gbl_ctx;

/*
 * nss_nlipsec_add_ref()
 *	add reference to the netdevice object
 */
static inline void nss_nlipsec_add_ref(struct nss_nlipsec_ref *ref_tbl, struct net_device *dev)
{
	struct nss_nlipsec_ref *ref;
	int i;

	for (i = 0, ref = &ref_tbl[0]; i < NSS_IPSECMGR_MAX_TUNNELS; i++, ref++) {
		mutex_lock(&ref->lock); /* lock_ref */

		if (!ref->valid) {
			ref->ifindex = dev->ifindex;
			ref->valid = true;

			mutex_unlock(&ref->lock); /* unlock_ref */
			return;
		}

		mutex_unlock(&ref->lock); /* unlock_ref */
	}

	BUG_ON(i == NSS_IPSECMGR_MAX_TUNNELS);
}

/*
 * nss_nlipsec_del_ref()
 * 	delete netdevice reference
 */
static inline void nss_nlipsec_del_ref(struct nss_nlipsec_ref *ref)
{
	mutex_lock(&ref->lock);	/* lock_ref */

	ref->ifindex = -1;
	ref->valid = false;

	mutex_unlock(&ref->lock); /* unlock_ref */
}

/*
 * nss_nlipsec_find_ref()
 * 	find refernce node for the given netdevice
 */
struct nss_nlipsec_ref *nss_nlipsec_find_ref(struct nss_nlipsec_ref *ref_tbl, struct net_device *dev)
{
	struct nss_nlipsec_ref *ref = NULL;
	int i;

	for (i = 0, ref = &ref_tbl[0]; i < NSS_IPSECMGR_MAX_TUNNELS; i++, ref++) {

		mutex_lock(&ref->lock); /* lock_ref */

		if (ref->valid && (dev->ifindex == ref->ifindex)) {
			mutex_unlock(&ref->lock); /* unlock_ref */
			return ref;
		}

		mutex_unlock(&ref->lock); /* unlock_ref */
	}

	return NULL;
}

/*
 * nss_nlipsec_verify_create_encap()
 * 	verify create encap flow
 */
static int nss_nlipsec_verify_create_encap(struct nss_ipsecmgr_encap_flow *encap_flow, struct nss_ipsecmgr_sa *encap_sa,
						struct nss_ipsecmgr_sa_data *encap_data)
{
	struct nss_ipsecmgr_encap_v4_tuple *v4_tuple;
	struct nss_ipsecmgr_encap_v4_subnet *v4_subnet;
	struct nss_ipsecmgr_encap_v6_subnet *v6_subnet;
	struct nss_ipsecmgr_encap_v6_tuple *v6_tuple;
	struct nss_ipsecmgr_sa_v4 *v4;
	struct nss_ipsecmgr_sa_v6 *v6;
	const uint32_t encap_req_type = (NSS_CRYPTO_REQ_TYPE_AUTH | NSS_CRYPTO_REQ_TYPE_ENCRYPT);
	uint32_t req_type;

	/*
	 * verify the flow
	 */
	switch (encap_flow->type) {
	case NSS_IPSECMGR_FLOW_TYPE_V4_TUPLE:
		v4_tuple = &encap_flow->data.v4_tuple;

		if (!v4_tuple->src_ip || !v4_tuple->dst_ip || !v4_tuple->protocol) {
			nss_nl_error("Invalid v4 flow tuple\n");
			return -1;
		}
		break;

	case NSS_IPSECMGR_FLOW_TYPE_V4_SUBNET:
		v4_subnet = &encap_flow->data.v4_subnet;

		if (!v4_subnet->dst_subnet && v4_subnet->dst_mask) {
			nss_nl_error("Invalid v4 subnet\n");
			return -1;
		}
		break;

	case NSS_IPSECMGR_FLOW_TYPE_V6_TUPLE:
		v6_tuple = &encap_flow->data.v6_tuple;

		if (bitmap_empty((unsigned long *)v6_tuple->src_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid v6 src_ip\n");
			return -1;
		}

		if (bitmap_empty((unsigned long *)v6_tuple->dst_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid v6 dst_ip\n");
			return -1;
		}

		if (!v6_tuple->next_hdr) {
			nss_nl_error("Invalid v6 next_hdr\n");
			return -1;
		}
		break;

	case NSS_IPSECMGR_FLOW_TYPE_V6_SUBNET:
		v6_subnet = &encap_flow->data.v6_subnet;

		if (bitmap_empty((unsigned long *)v6_subnet->dst_subnet, NSS_NLIPV6_SUBNET_BITS) &&
				!bitmap_empty((unsigned long *)v6_subnet->dst_mask, NSS_NLIPV6_SUBNET_BITS)) {
			nss_nl_error("Invalid v6 dst_subnet\n");
			return -1;
		}
		break;

	default:
		nss_nl_error("Invalid flow type\n");
		return -1;
	}

	/*
	 * verify SA configuration
	 */
	switch (encap_sa->type) {
	case NSS_IPSECMGR_SA_TYPE_V4:
		v4 = &encap_sa->data.v4;

		if (!v4->src_ip || !v4->dst_ip || !v4->spi_index) {
			nss_nl_error("Invalid V4 SA\n");
			return -2;
		}
		break;

	case NSS_IPSECMGR_SA_TYPE_V6:
		v6 = &encap_sa->data.v6;

		if (bitmap_empty((unsigned long *)v6->src_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid V6 src_ip\n");
			return -2;
		}

		if (bitmap_empty((unsigned long *)v6->dst_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid V6 dst_ip\n");
			return -2;
		}

		if (!v6->spi_index) {
			nss_nl_error("Invalid V6 spi_index\n");
			return -2;
		}
		break;

	default:
		nss_nl_error("Invalid SA type\n");
		return -2;
	}

	/*
	 * match request type for crypto with encap direction
	 */
	req_type = nss_crypto_get_reqtype(encap_data->crypto_index);
	if (req_type != encap_req_type) {
		nss_nl_error("Invalid cipher configuration\n");
		return -3;
	}

	return 0;
}

/*
 * nss_nlipsec_verify_create_decap()
 * 	verify create decap SA
 */
static int nss_nlipsec_verify_create_decap(struct nss_ipsecmgr_sa *decap_sa, struct nss_ipsecmgr_sa_data *decap_data)
{
	struct nss_ipsecmgr_sa_v4 *v4;
	struct nss_ipsecmgr_sa_v6 *v6;

	const uint32_t decap_req_type = (NSS_CRYPTO_REQ_TYPE_AUTH | NSS_CRYPTO_REQ_TYPE_DECRYPT);
	uint32_t req_type;

	/*
	 * verify SA configuration
	 */
	switch (decap_sa->type) {
	case NSS_IPSECMGR_SA_TYPE_V4:
		v4 = &decap_sa->data.v4;

		if (!v4->src_ip || !v4->dst_ip || !v4->spi_index) {
			nss_nl_error("Invalid V4 SA\n");
			return -2;
		}
		break;

	case NSS_IPSECMGR_SA_TYPE_V6:
		v6 = &decap_sa->data.v6;

		if (bitmap_empty((unsigned long *)v6->src_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid V6 src_ip\n");
			return -2;
		}

		if (bitmap_empty((unsigned long *)v6->dst_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid V6 dst_ip\n");
			return -2;
		}

		if (!v6->spi_index) {
			nss_nl_error("Invalid V6 spi_index\n");
			return -2;
		}
		break;

	default:
		nss_nl_error("Invalid SA type\n");
		return -2;
	}

	/*
	 * match request type for crypto with encap direction
	 */
	req_type = nss_crypto_get_reqtype(decap_data->crypto_index);
	if (req_type != decap_req_type) {
		return -4;
	}

	return 0;
}

/*
 * nss_nlipsec_verify_destroy_encap_flow()
 * 	verify destroy encap flow
 */
static int nss_nlipsec_verify_destroy_encap_flow(struct nss_ipsecmgr_encap_flow *encap_flow, struct nss_ipsecmgr_sa *encap_sa)
{
	struct nss_ipsecmgr_encap_v4_tuple *v4_tuple;
	struct nss_ipsecmgr_encap_v4_subnet *v4_subnet;
	struct nss_ipsecmgr_encap_v6_subnet *v6_subnet;
	struct nss_ipsecmgr_encap_v6_tuple *v6_tuple;
	struct nss_ipsecmgr_sa_v4 *v4;
	struct nss_ipsecmgr_sa_v6 *v6;

	/*
	 * verify flow
	 */
	switch (encap_flow->type) {
	case NSS_IPSECMGR_FLOW_TYPE_V4_TUPLE:
		v4_tuple = &encap_flow->data.v4_tuple;

		if (!v4_tuple->src_ip || !v4_tuple->dst_ip || !v4_tuple->protocol) {
			nss_nl_error("Invalid v4 flow tuple\n");
			return -1;
		}
		break;

	case NSS_IPSECMGR_FLOW_TYPE_V4_SUBNET:
		v4_subnet = &encap_flow->data.v4_subnet;

		if (!v4_subnet->dst_subnet && v4_subnet->dst_mask) {
			nss_nl_error("Invalid v4 subnet\n");
			return -1;
		}
		break;

	case NSS_IPSECMGR_FLOW_TYPE_V6_TUPLE:
		v6_tuple = &encap_flow->data.v6_tuple;

		if (bitmap_empty((unsigned long *)v6_tuple->src_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid v6 src_ip\n");
			return -1;
		}

		if (bitmap_empty((unsigned long *)v6_tuple->dst_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid v6 dest_ip\n");
			return -1;
		}

		if (!v6_tuple->next_hdr) {
			nss_nl_error("Invalid v6 next_hdr\n");
			return -1;
		}
		break;

	case NSS_IPSECMGR_FLOW_TYPE_V6_SUBNET:
		v6_subnet = &encap_flow->data.v6_subnet;

		if (bitmap_empty((unsigned long *)v6_subnet->dst_subnet, NSS_NLIPV6_SUBNET_BITS) &&
				!bitmap_empty((unsigned long *)v6_subnet->dst_mask, NSS_NLIPV6_SUBNET_BITS)) {
			nss_nl_error("Invalid v6 dst_subnet\n");
			return -1;
		}
		break;

	default:
		nss_nl_error("Invalid flow type\n");
		return -1;
	}

	/*
	 * verify SA configuration
	 */
	switch (encap_sa->type) {
	case NSS_IPSECMGR_SA_TYPE_V4:
		v4 = &encap_sa->data.v4;

		if (!v4->src_ip || !v4->dst_ip || !v4->spi_index) {
			nss_nl_error("Invalid V4 SA\n");
			return -2;
		}
		break;

	case NSS_IPSECMGR_SA_TYPE_V6:
		v6 = &encap_sa->data.v6;

		if (bitmap_empty((unsigned long *)v6->src_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid V6 src_ip\n");
			return -2;
		}

		if (bitmap_empty((unsigned long *)v6->dst_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid V6 dst_ip\n");
			return -2;
		}

		if (!v6->spi_index) {
			nss_nl_error("Invalid V6 spi_index\n");
			return -2;
		}
		break;

	default:
		nss_nl_error("Invalid SA type\n");
		return -2;
	}
	return 0;
}

/*
 * nss_nlipsec_verify_destroy_encap_sa()
 * 	verify destroy encap SA
 */
static int nss_nlipsec_verify_destroy_encap_sa(struct nss_ipsecmgr_sa *encap_sa)
{
	struct nss_ipsecmgr_sa_v4 *v4;
	struct nss_ipsecmgr_sa_v6 *v6;
	/*
	 * verify SA configuration
	 */
	switch (encap_sa->type) {
	case NSS_IPSECMGR_SA_TYPE_V4:
		v4 = &encap_sa->data.v4;

		if (!v4->src_ip || !v4->dst_ip || !v4->spi_index) {
			nss_nl_error("Invalid V4 SA\n");
			return -2;
		}
		break;

	case NSS_IPSECMGR_SA_TYPE_V6:
		v6 = &encap_sa->data.v6;

		if (bitmap_empty((unsigned long *)v6->src_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid V6 src_ip\n");
			return -2;
		}

		if (bitmap_empty((unsigned long *)v6->dst_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid V6 dst_ip\n");
			return -2;
		}

		if (!v6->spi_index) {
			nss_nl_error("Invalid V6 spi_index\n");
			return -2;
		}
		break;

	default:
		nss_nl_error("Invalid SA type\n");
		return -2;
	}
	return 0;
}

/*
 * nss_nlipsec_verify_destroy_decap()
 * 	verify destroy decap rule
 */
static int nss_nlipsec_verify_destroy_decap(struct nss_ipsecmgr_sa *decap_sa)
{
	struct nss_ipsecmgr_sa_v4 *v4;
	struct nss_ipsecmgr_sa_v6 *v6;
	/*
	 * verify SA configuration
	 */
	switch (decap_sa->type) {
	case NSS_IPSECMGR_SA_TYPE_V4:
		v4 = &decap_sa->data.v4;

		if (!v4->src_ip || !v4->dst_ip || !v4->spi_index) {
			nss_nl_error("Invalid V4 SA\n");
			return -2;
		}
		break;

	case NSS_IPSECMGR_SA_TYPE_V6:
		v6 = &decap_sa->data.v6;

		if (bitmap_empty((unsigned long *)v6->src_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid V6 src_ip\n");
			return -2;
		}

		if (bitmap_empty((unsigned long *)v6->dst_ip, NSS_NLIPV6_ADDR_BITS)) {
			nss_nl_error("Invalid V6 dst_ip\n");
			return -2;
		}

		if (!v6->spi_index) {
			nss_nl_error("Invalid V6 spi_index\n");
			return -2;
		}
		break;

	default:
		nss_nl_error("Invalid SA type\n");
		return -2;
	}
	return 0;
}

/*
 * nss_nlipsec_process_event()
 * 	process events from NSS IPsec manager and MCAST it to user
 */
static void nss_nlipsec_process_event(void *ctx, struct nss_ipsecmgr_event *ev)
{
	struct nss_nlipsec_rule *nl_rule;
	struct sk_buff *skb;

	/*
	 * Allocate a new event message
	 */
	skb = nss_nl_new_msg(&nss_nlipsec_family, ev->type);
	if (!skb) {
		nss_nl_error("unable to allocate NSS_NLIPV4 event\n");
		return;
	}

	nl_rule = nss_nl_get_data(skb);

	/*
	 * initialize the NETLINK common header
	 */
	nss_nlipsec_rule_init(nl_rule, ev->type);

	/*
	 * copy the contents of the sync message into the NETLINK message
	 */
	memcpy(&nl_rule->event, ev, sizeof(struct nss_ipsecmgr_event));

	nss_nl_mcast_event(&nss_nlipsec_mcgrp, skb);
}

/*
 * ***********
 * OP handlers
 * ***********
 */

/*
 * nss_nlipsec_op_create_encap_flow()
 * 	create a encap flow rule to the IPsec tunnel
 */
static int nss_nlipsec_op_create_encap_flow(struct sk_buff *skb, struct genl_info *info)
{
	struct nss_ipsecmgr_encap_flow *encap_flow;
	struct nss_ipsecmgr_sa_data *encap_data;
	struct nss_ipsecmgr_sa *encap_sa;
	struct nss_nlipsec_rule *nl_rule;
	struct nss_nlipsec_ref *ref;
	struct nss_nlcmn *nl_cm;
	struct net_device *dev;
	uint32_t pid;
	int error;

	/*
	 * extract the message payload
	 */
	nl_cm = nss_nl_get_msg(&nss_nlipsec_family, info, NSS_NLIPSEC_CMD_CREATE_ENCAP_FLOW);
	if (!nl_cm) {
		nss_nl_error("unable to extract create rule data\n");
		return -EINVAL;
	}

	/*
	 * Message validation required before accepting the configuration
	 */
	nl_rule = container_of(nl_cm, struct nss_nlipsec_rule, cm);
	pid = nl_cm->pid;

	/*
	 * search/get the the linux netdevice object
	 */
	dev = dev_get_by_name(&init_net, nl_rule->ifname);
	if (!dev) {
		nss_nl_error("%d:unable to find netdevice (%s)\n", pid, nl_rule->ifname);
		return -EINVAL;
	}

	/*
	 * find if we have the local reference
	 */
	ref = nss_nlipsec_find_ref(gbl_ctx.ref_tbl, dev);
	if (!ref) {
		nss_nl_error("%d:interface(%s) was not created through NL_IPSEC\n", pid, dev->name);
		error =  -EINVAL;
		goto done;
	}

	encap_flow = &nl_rule->msg.flow;
	encap_sa = &nl_rule->msg.sa;
	encap_data = &nl_rule->msg.data;

	/*
	 * verify create rule
	 */
	error = nss_nlipsec_verify_create_encap(encap_flow, encap_sa, encap_data);

	if (error < 0) {
		nss_nl_error("%d:invalid encap create flow, error(%d)\n", pid, error);
		goto done;
	}

	/*
	 * Add the SA rule to the IPsec tunnel
	 */
	if (nss_ipsecmgr_encap_add(dev, encap_flow, encap_sa, encap_data) == false) {
		nss_nl_error("%d:unable to add encap flow to tunnel(%s)\n", pid, dev->name);
		error =  -EINVAL;
		goto done;
	}

done:
	dev_put(dev);
	return error;
}

/*
 * nss_nlipsec_op_destroy_encap_flow()
 * 	destroy a encap flow from the IPsec tunnel
 */
static int nss_nlipsec_op_destroy_encap_flow(struct sk_buff *skb, struct genl_info *info)
{
	struct nss_ipsecmgr_encap_flow *encap_flow;
	struct nss_nlipsec_rule *nl_rule;
	struct nss_ipsecmgr_sa *encap_sa;
	struct nss_nlipsec_ref *ref;
	struct nss_nlcmn *nl_cm;
	struct net_device *dev;
	uint32_t pid;
	int error;

	/*
	 * extract the message payload
	 */
	nl_cm = nss_nl_get_msg(&nss_nlipsec_family, info, NSS_NLIPSEC_CMD_DESTROY_ENCAP_FLOW);
	if (!nl_cm) {
		nss_nl_error("unable to extract destroy rule data\n");
		return -EINVAL;
	}

	/*
	 * Message validation required before accepting the configuration
	 */
	nl_rule = container_of(nl_cm, struct nss_nlipsec_rule, cm);
	pid = nl_cm->pid;

	/*
	 * search/get the the linux netdevice object
	 */
	dev = dev_get_by_name(&init_net, nl_rule->ifname);
	if (!dev) {
		nss_nl_error("%d:unable to find netdevice (%s)\n", pid, nl_rule->ifname);
		return -EINVAL;
	}

	/*
	 * find if we have the local reference
	 */
	ref = nss_nlipsec_find_ref(gbl_ctx.ref_tbl, dev);
	if (!ref) {
		nss_nl_error("%d:interface(%s) was not created through NL_IPSEC\n", pid, dev->name);
		error =  -EINVAL;
		goto done;
	}

	encap_flow = &nl_rule->msg.flow;
	encap_sa = &nl_rule->msg.sa;

	/*
	 * verify destroy rule
	 */
	error = nss_nlipsec_verify_destroy_encap_flow(encap_flow, encap_sa);

	if (error < 0) {
		nss_nl_error("%d:invalid encap destroy flow, error(%d)\n", pid, error);
		goto done;
	}

	/*
	 * Delete the SA rule from the IPsec tunnel
	 */
	if (nss_ipsecmgr_encap_del(dev, encap_flow, encap_sa) == false) {
		nss_nl_error("%d:unable to delete encap flow from tunnel(%s)\n", pid, dev->name);
		error =  -EINVAL;
		goto done;
	}

done:
	dev_put(dev);
	return error;
}


/*
 * nss_nlipsec_op_destroy_encap_sa()
 * 	destroy encap SA from the IPsec tunnel
 */
static int nss_nlipsec_op_destroy_encap_sa(struct sk_buff *skb, struct genl_info *info)
{
	struct nss_nlipsec_rule *nl_rule;
	struct nss_ipsecmgr_sa *encap_sa;
	struct nss_nlipsec_ref *ref;
	struct nss_nlcmn *nl_cm;
	struct net_device *dev;
	uint32_t pid;
	int error;

	/*
	 * extract the message payload
	 */
	nl_cm = nss_nl_get_msg(&nss_nlipsec_family, info, NSS_NLIPSEC_CMD_DESTROY_ENCAP_SA);
	if (!nl_cm) {
		nss_nl_error("unable to extract destroy rule data\n");
		return -EINVAL;
	}

	/*
	 * Message validation required before accepting the configuration
	 */
	nl_rule = container_of(nl_cm, struct nss_nlipsec_rule, cm);
	pid = nl_cm->pid;

	/*
	 * search/get the the linux netdevice object
	 */
	dev = dev_get_by_name(&init_net, nl_rule->ifname);
	if (!dev) {
		nss_nl_error("%d:unable to find netdevice (%s)\n", pid, nl_rule->ifname);
		return -EINVAL;
	}

	/*
	 * find if we have the local reference
	 */
	ref = nss_nlipsec_find_ref(gbl_ctx.ref_tbl, dev);
	if (!ref) {
		nss_nl_error("%d:interface(%s) was not created through NL_IPSEC\n", pid, dev->name);
		error =  -EINVAL;
		goto done;
	}

	encap_sa = &nl_rule->msg.sa;

	/*
	 * verify destroy rule
	 */
	error = nss_nlipsec_verify_destroy_encap_sa(encap_sa);

	if (error < 0) {
		nss_nl_error("%d:invalid destroy encap SA, error(%d)\n", pid, error);
		goto done;
	}

	/*
	 * Delete the SA rule from the IPsec tunnel
	 */
	if (nss_ipsecmgr_sa_flush(dev, encap_sa) == false) {
		nss_nl_error("%d:unable to delete encap SA from tunnel(%s)\n", pid, dev->name);
		error =  -EINVAL;
		goto done;
	}

done:
	dev_put(dev);
	return error;
}

/*
 * nss_nlipsec_op_create_decap_sa()
 * 	create a decap SA to the IPsec tunnel
 */
static int nss_nlipsec_op_create_decap_sa(struct sk_buff *skb, struct genl_info *info)
{
	struct nss_ipsecmgr_sa_data *decap_data;
	struct nss_ipsecmgr_sa *decap_sa;
	struct nss_nlipsec_rule *nl_rule;
	struct nss_nlipsec_ref *ref;
	struct nss_nlcmn *nl_cm;
	struct net_device *dev;
	uint32_t pid;
	int error;

	/*
	 * extract the message payload
	 */
	nl_cm = nss_nl_get_msg(&nss_nlipsec_family, info, NSS_NLIPSEC_CMD_CREATE_DECAP_SA);
	if (!nl_cm) {
		nss_nl_error("unable to extract create rule data\n");
		return -EINVAL;
	}

	/*
	 * Message validation required before accepting the configuration
	 */
	nl_rule = container_of(nl_cm, struct nss_nlipsec_rule, cm);
	pid = nl_cm->pid;

	/*
	 * search/get the the linux netdevice object
	 */
	dev = dev_get_by_name(&init_net, nl_rule->ifname);
	if (!dev) {
		nss_nl_error("%d:unable to find netdevice (%s)\n", pid, nl_rule->ifname);
		return -EINVAL;
	}

	/*
	 * find if we have the local reference
	 */
	ref = nss_nlipsec_find_ref(gbl_ctx.ref_tbl, dev);
	if (!ref) {
		nss_nl_error("%d:interface(%s) was not created through NL_IPSEC\n", pid, dev->name);
		error =  -EINVAL;
		goto done;
	}

	decap_sa = &nl_rule->msg.sa;
	decap_data = &nl_rule->msg.data;

	/*
	 * verify create rule
	 */
	error = nss_nlipsec_verify_create_decap(decap_sa, decap_data);

	if (error < 0) {
		nss_nl_error("%d:invalid decap create SA, error(%d)\n", pid, error);
		goto done;
	}

	/*
	 * Add the SA rule to the IPsec tunnel
	 */
	if (nss_ipsecmgr_decap_add(dev, decap_sa, decap_data) == false) {
		nss_nl_error("%d:unable to add decap SA to tunnel(%s)\n", pid, dev->name);
		error =  -EINVAL;
		goto done;
	}

done:
	dev_put(dev);
	return error;
}

/*
 * nss_nlipsec_op_destroy_decap_sa()
 * 	destroy a decap SA to the IPsec tunnel
 */
static int nss_nlipsec_op_destroy_decap_sa(struct sk_buff *skb, struct genl_info *info)
{
	struct nss_ipsecmgr_sa *decap_sa;
	struct nss_nlipsec_rule *nl_rule;
	struct nss_nlipsec_ref *ref;
	struct nss_nlcmn *nl_cm;
	struct net_device *dev;
	uint32_t pid;
	int error;

	/*
	 * extract the message payload
	 */
	nl_cm = nss_nl_get_msg(&nss_nlipsec_family, info, NSS_NLIPSEC_CMD_DESTROY_DECAP_SA);
	if (!nl_cm) {
		nss_nl_error("unable to extract create rule data\n");
		return -EINVAL;
	}

	/*
	 * Message validation required before accepting the configuration
	 */
	nl_rule = container_of(nl_cm, struct nss_nlipsec_rule, cm);
	pid = nl_cm->pid;

	/*
	 * search/get the the linux netdevice object
	 */
	dev = dev_get_by_name(&init_net, nl_rule->ifname);
	if (!dev) {
		nss_nl_error("%d:unable to find netdevice (%s)\n", pid, nl_rule->ifname);
		return -EINVAL;
	}

	/*
	 * find if we have the local reference
	 */
	ref = nss_nlipsec_find_ref(gbl_ctx.ref_tbl, dev);
	if (!ref) {
		nss_nl_error("%d:interface(%s) was not created through NL_IPSEC\n", pid, dev->name);
		error =  -EINVAL;
		goto done;
	}

	decap_sa = &nl_rule->msg.sa;

	/*
	 * verify create rule
	 */
	error = nss_nlipsec_verify_destroy_decap(decap_sa);

	if (error < 0) {
		nss_nl_error("%d:invalid decap destroy SA, error(%d)\n", pid, error);
		goto done;
	}

	/*
	 * Add the SA rule to the IPsec tunnel
	 */
	if (nss_ipsecmgr_sa_flush(dev, decap_sa) == false) {
		nss_nl_error("%d:unable to delete decap SA from tunnel(%s)\n", pid, dev->name);
		error =  -EINVAL;
		goto done;
	}

done:
	dev_put(dev);
	return error;
}
/*
 * nss_nlipsec_op_create_tunnel()
 * 	Add IPsec tunnel
 */
static int nss_nlipsec_op_create_tunnel(struct sk_buff *skb, struct genl_info *info)
{
	struct nss_nlipsec_rule *nl_rule;
	struct nss_ipsecmgr_callback cb;
	struct nss_nlcmn *nl_cm;
	struct net_device *dev;
	struct sk_buff *resp;
	uint32_t pid;

	/*
	 * extract the message payload
	 */
	nl_cm = nss_nl_get_msg(&nss_nlipsec_family, info, NSS_NLIPSEC_CMD_CREATE_TUNNEL);
	if (!nl_cm) {
		nss_nl_error("unable to extract create tunnel data\n");
		return -EINVAL;
	}

	pid = nl_cm->pid;

	if (atomic_read(&gbl_ctx.tunnels) == NSS_IPSECMGR_MAX_TUNNELS) {
		nss_nl_error("%d:max allowed tunnel reached (%d)\n", pid, NSS_IPSECMGR_MAX_TUNNELS);
		return -EINVAL;
	}

	/*
	 * create a IPsec tunnel device
	 */
	cb.ctx = &gbl_ctx;
	cb.data_fn = NULL;
	cb.event_fn = nss_nlipsec_process_event;
	dev = nss_ipsecmgr_tunnel_add(&cb);
	if (!dev) {
		nss_nl_error("%d:unable to add IPsec tunnel\n", pid);
		return -ENOMEM;
	}

	/*
	 * add an internal reference to the tunnel dev
	 */
	atomic_inc(&gbl_ctx.tunnels);
	nss_nlipsec_add_ref(gbl_ctx.ref_tbl, dev);

	/*
	 * Response message
	 */
	resp  = nss_nl_copy_msg(skb);
	if (!resp) {
		nss_nl_error("unable to copy incoming message\n");
		goto free_dev;
	}

	/*
	 * overload the nl_rule with the new response address
	 */
	nl_rule = nss_nl_get_data(resp);

	/*
	 * Init the command
	 */
	nss_nlipsec_rule_init(nl_rule, NSS_NLIPSEC_CMD_CREATE_TUNNEL);

	/*
	 * We need to send the  name to the user; copy
	 * the tunnel I/F name into the same rule and send it
	 * as part of the response for the create operation
	 */
	strlcpy(nl_rule->ifname, dev->name, IFNAMSIZ);

	/*
	 * Send to userspace
	 */
	nss_nl_ucast_resp(resp);

	return 0;

free_dev:

	nss_ipsecmgr_tunnel_del(dev);
	return -ENOMEM;
}

/*
 * nss_nlipsec_op_tunnel_del()
 * 	delete an IPsec tunnel
 */
static int nss_nlipsec_op_destroy_tunnel(struct sk_buff *skb, struct genl_info *info)
{
	struct nss_nlipsec_rule *nl_rule;
	struct nss_nlipsec_ref *ref;
	struct nss_nlcmn *nl_cm;
	struct net_device *dev;
	uint32_t pid;

	/*
	 * extract the message payload
	 */
	nl_cm = nss_nl_get_msg(&nss_nlipsec_family, info, NSS_NLIPSEC_CMD_DESTROY_TUNNEL);
	if (!nl_cm) {
		nss_nl_error("unable to extract destroy tunnel data\n");
		return -EINVAL;
	}

	/*
	 * Message validation required before accepting the configuration
	 */
	nl_rule = container_of(nl_cm, struct nss_nlipsec_rule, cm);
	pid = nl_cm->pid;

	if (atomic_read(&gbl_ctx.tunnels) == 0) {
		nss_nl_error("%d:no tunnels available for deletion\n", pid);
		return -EINVAL;
	}
	/*
	 * search/get the the linux netdevice object
	 */
	dev = dev_get_by_name(&init_net, nl_rule->ifname);
	if (!dev) {
		nss_nl_error("%d:unable to find netdevice (%s)\n", pid, nl_rule->ifname);
		return -EINVAL;
	}

	/*
	 * find if we have the local reference
	 */
	ref = nss_nlipsec_find_ref(gbl_ctx.ref_tbl, dev);
	if (!ref) {
		nss_nl_error("%d:interface(%s) was not created through NL_IPSEC\n", pid, dev->name);
		dev_put(dev);
		return -EINVAL;
	}

	nss_nlipsec_del_ref(ref);
	atomic_dec(&gbl_ctx.tunnels);

	/*
	 * down the ref_cnt held by nss_nlipsec_destroy_tunnel
	 */
	dev_put(dev);

	/*
	 * delete the tunnel device
	 */
	nss_ipsecmgr_tunnel_del(dev);

	return 0;
}

#define NSS_NLIPSEC_OPS_SZ ARRAY_SIZE(nss_nlipsec_ops)

/*
 * nss_nlipsec_init()
 * 	handler init
 */
bool nss_nlipsec_init(void)
{
	struct nss_nlipsec_ref *ref;
	int error;
	int i;

	nss_nl_info_always("Init NSS netlink IPsec handler\n");

	/*
	 * initialize reference table
	 */
	for (i = 0, ref = gbl_ctx.ref_tbl; i < NSS_IPSECMGR_MAX_TUNNELS; i++, ref++) {
		mutex_init(&ref->lock);
		ref->valid = false;
		ref->ifindex = -1;
	}

	/*
	 * register with the family
	 */
	error = genl_register_family_with_ops(&nss_nlipsec_family,
			nss_nlipsec_ops, NSS_NLIPSEC_OPS_SZ);
	if (error != 0) {
		nss_nl_info_always("Error: unable to register IPsec family\n");
		return false;
	}

	/*
	 * register NETLINK MCAST group for notifications
	 */
	error = genl_register_mc_group(&nss_nlipsec_family, &nss_nlipsec_mcgrp);
	if (error != 0) {
		nss_nl_info_always("Error: unable to register IPsec Netlink"
				"multicast group\n");
		goto unreg_family;
	}


	return true;

unreg_family:

	/*
	 * undo all registeration
	 */
	genl_unregister_family(&nss_nlipsec_family);

	return false;
}

/*
 * nss_nlipsec_exit()
 * 	handler exit
 */
bool nss_nlipsec_exit(void)
{
	int error;

	nss_nl_info_always("Exit NSS netlink IPsec handler\n");

	/*
	 * unregister the ops family
	 */
	error = genl_unregister_family(&nss_nlipsec_family);
	if (error != 0) {
		nss_nl_info_always("unable to unregister IPsec NETLINK family\n");
		return false;
	}

	return true;
}
