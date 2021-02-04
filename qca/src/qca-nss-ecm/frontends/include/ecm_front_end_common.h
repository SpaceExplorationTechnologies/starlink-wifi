/*
 **************************************************************************
 * Copyright (c) 2015-2016 The Linux Foundation.  All rights reserved.
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

#include <linux/if_pppox.h>
#include <net/netfilter/nf_conntrack.h>
#include <net/netfilter/nf_conntrack_acct.h>

#ifdef ECM_FRONT_END_NSS_ENABLE
#include "ecm_nss_bond_notifier.h"
#else
static inline void ecm_nss_bond_notifier_stop(int num)
{
	/*
	 * Just return if nss front end is not enabled
	 */
	return;
}

static inline int ecm_nss_bond_notifier_init(struct dentry *dentry)
{
	/*
	 * Just return if nss front end is not enabled
	 */
	return 0;
}

static inline void ecm_nss_bond_notifier_exit(void)
{
	/*
	 * Just return if nss front end is not enabled
	 */
	return;
}
#endif

/*
 * ecm_front_end_l2_encap_header_len()
 *      Return length of encapsulating L2 header
 */
static inline uint32_t ecm_front_end_l2_encap_header_len(struct sk_buff *skb)
{
	switch (skb->protocol) {
	case ntohs(ETH_P_PPP_SES):
		return PPPOE_SES_HLEN;
	default:
		return 0;
	}
}

/*
 * ecm_front_end_pull_l2_encap_header()
 *      Pull encapsulating L2 header
 */
static inline void ecm_front_end_pull_l2_encap_header(struct sk_buff *skb, uint32_t len)
{
	skb->data += len;
	skb->network_header += len;
}

/*
 * ecm_front_end_push_l2_encap_header()
 *      Push encapsulating L2 header
 */
static inline void ecm_front_end_push_l2_encap_header(struct sk_buff *skb, uint32_t len)
{
	skb->data -= len;
	skb->network_header -= len;
}

/*
 * ecm_front_end_acceleration_rejected()
 *      Check if the acceleration of a flow could be rejected quickly.
 */
static inline bool ecm_front_end_acceleration_rejected(struct sk_buff *skb)
{
	struct nf_conn *ct;
	enum ip_conntrack_info ctinfo;
	struct nf_conn_counter *acct;

	ct = nf_ct_get(skb, &ctinfo);
	if (unlikely(!ct)) {
		/*
		 * Maybe bridged traffic, no decision here.
		 */
		return false;
	}

	if (unlikely(nf_ct_is_untracked(ct))) {
		/*
		 * Untracked traffic certainly can't be accelerated.
		 */
		return true;
	}

#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 6, 0))
	acct = nf_conn_acct_find(ct);
#else
	acct = nf_conn_acct_find(ct)->counter;
#endif
	if (acct) {
		long long packets = atomic64_read(&acct[CTINFO2DIR(ctinfo)].packets);
		if ((packets > 0xff) && (packets & 0xff)) {
			/*
			 * Connection hits slow path at least 256 times, so it must be not able to accelerate.
			 * But we also give it a chance to walk through ECM every 256 packets
			 */
			return true;
		}
	}

	return false;
}

/*
 * ecm_front_end_flow_and_return_directions_get()
 *	Gets the flow and return flows directions respect to conntrack entry.
 */
static inline void ecm_front_end_flow_and_return_directions_get(struct nf_conn *ct, ip_addr_t flow_ip, int ip_version, int *flow_dir, int *return_dir)
{
	ip_addr_t ct_src_ip;

	if (ip_version == 4) {
		uint32_t flow_ip_32;
		uint32_t ct_src_ip_32;
		ECM_NIN4_ADDR_TO_IP_ADDR(ct_src_ip, ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.src.u3.ip);

		/*
		 * Print the IP addresses for debug purpose.
		 */
		ECM_IP_ADDR_TO_HIN4_ADDR(flow_ip_32, flow_ip);
		ECM_IP_ADDR_TO_HIN4_ADDR(ct_src_ip_32, ct_src_ip);
		DEBUG_TRACE("flow_ip: %pI4h ct_src_ip: %pI4h\n", &flow_ip_32, &ct_src_ip_32);
	} else if (ip_version == 6) {
		ECM_NIN6_ADDR_TO_IP_ADDR(ct_src_ip, ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.src.u3.in6);

		/*
		 * Print the IP addresses for debug purpose.
		 */
		DEBUG_TRACE("flow_ip: " ECM_IP_ADDR_OCTAL_FMT " ct_src_ip: " ECM_IP_ADDR_OCTAL_FMT "\n",
				ECM_IP_ADDR_TO_OCTAL(flow_ip), ECM_IP_ADDR_TO_OCTAL(ct_src_ip));
	} else {
		DEBUG_ASSERT(NULL, "Invalid ip version");
	}

	if (ECM_IP_ADDR_MATCH(ct_src_ip, flow_ip)) {
		*flow_dir = IP_CT_DIR_ORIGINAL;
		*return_dir = IP_CT_DIR_REPLY;
		DEBUG_TRACE("flow_ip and ct_src_ip match\n");
	} else {
		*flow_dir = IP_CT_DIR_REPLY;
		*return_dir = IP_CT_DIR_ORIGINAL;
		DEBUG_TRACE("flow_ip and ct_src_ip do not match\n");
	}

	DEBUG_TRACE("flow_dir: %d return_dir: %d\n", *flow_dir, *return_dir);
}

extern void ecm_front_end_bond_notifier_stop(int num);
extern int ecm_front_end_bond_notifier_init(struct dentry *dentry);
extern void ecm_front_end_bond_notifier_exit(void);
extern void ecm_front_end_destroy_failure_handle(struct ecm_front_end_connection_instance *feci);
