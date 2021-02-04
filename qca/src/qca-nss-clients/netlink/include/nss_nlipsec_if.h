/*
 **************************************************************************
 * Copyright (c) 2015, The Linux Foundation. All rights reserved.
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

#ifndef __NSS_NLIPSEC_IF_H
#define __NSS_NLIPSEC_IF_H

/**
 * @addtogroup nss_netlink
 * @{
 */

/*
 * @file nss_nlipsec_if.h
 *	NSS Netlink IPsec headers
 */

#define NSS_NLIPSEC_FAMILY "nss_nlipsec"	/**< IPsec family */

/**
 * @brief ipsec commands types
 */
enum nss_nlipsec_cmd {
	NSS_NLIPSEC_CMD_UNSPEC = 0,		/**< unspecified cmd */
	NSS_NLIPSEC_CMD_CREATE_TUNNEL = 1,	/**< create tunnel */
	NSS_NLIPSEC_CMD_DESTROY_TUNNEL = 2,	/**< destroy tunnel */
	NSS_NLIPSEC_CMD_CREATE_ENCAP_FLOW = 3,	/**< create encap flow rule */
	NSS_NLIPSEC_CMD_DESTROY_ENCAP_FLOW = 4,	/**< delete encap flow rule */
	NSS_NLIPSEC_CMD_DESTROY_ENCAP_SA = 5,	/**< flush encap SA */
	NSS_NLIPSEC_CMD_CREATE_DECAP_SA = 6,	/**< create decap flow rule */
	NSS_NLIPSEC_CMD_DESTROY_DECAP_SA = 7,	/**< delete decap flow rule */

	NSS_NLIPSEC_CMD_MAX
};

/**
 * @brief IPsec message
 */
struct nss_nlipsec_rule {
	struct nss_nlcmn cm;				/**< common message header */

	uint8_t ifname[IFNAMSIZ];			/**< IPsec tunnel interface name */

	struct {
		struct nss_ipsecmgr_encap_flow flow;
		struct nss_ipsecmgr_sa sa;
		struct nss_ipsecmgr_sa_data data;
	} msg;

	struct nss_ipsecmgr_event event;		/**< IPsec event */
};

/**
 * @brief NETLINK IPsec message init
 *
 * @param rule[IN] NSS NETLINK IPsec message
 * @param type[IN] IPsec message type
 */
static inline void nss_nlipsec_rule_init(struct nss_nlipsec_rule *rule, enum nss_nlipsec_cmd type)
{
	nss_nlcmn_set_ver(&rule->cm, NSS_NL_VER);
	nss_nlcmn_init_cmd(&rule->cm, sizeof(struct nss_nlipsec_rule), type);
}

/**@}*/
#endif /* __NSS_NLIPSEC_IF_H */
