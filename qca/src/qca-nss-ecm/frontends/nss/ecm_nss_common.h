/*
 **************************************************************************
 * Copyright (c) 2015, 2018, The Linux Foundation.  All rights reserved.
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
 * Some constants used with constructing NSS acceleration rules.
 * GGG TODO These should be provided by the NSS driver itself!
 */
#define ECM_NSS_CONNMGR_VLAN_ID_NOT_CONFIGURED 0xFFF
#define ECM_NSS_CONNMGR_VLAN_MARKING_NOT_CONFIGURED 0xFFFF

/*
 * This macro converts ECM ip_addr_t to NSS IPv6 address
 */
#define ECM_IP_ADDR_TO_NSS_IPV6_ADDR(nss6, ipaddrt) \
	{ \
		ecm_type_check_ae_ipv6(nss6); \
		ecm_type_check_ecm_ip_addr(ipaddrt); \
		nss6[0] = ipaddrt[3]; \
		nss6[1] = ipaddrt[2]; \
		nss6[2] = ipaddrt[1]; \
		nss6[3] = ipaddrt[0]; \
	}

/*
 * This macro converts NSS IPv6 address to ECM ip_addr_t
 */
#define ECM_NSS_IPV6_ADDR_TO_IP_ADDR(ipaddrt, nss6) \
	{ \
		ecm_type_check_ecm_ip_addr(ipaddrt); \
		ecm_type_check_ae_ipv6(nss6); \
		ipaddrt[0] = nss6[3]; \
		ipaddrt[1] = nss6[2]; \
		ipaddrt[2] = nss6[1]; \
		ipaddrt[3] = nss6[0]; \
	}

/*
 * ecm_nss_common_get_interface_number_by_dev()
 *	Returns the acceleration engine interface number based on the net_device object.
 */
static inline int32_t ecm_nss_common_get_interface_number_by_dev(struct net_device *dev)
{
	/*
	 * nss_interface_num for all IPsec tunnels will always be the one specific to acceleration engine.
	 */
	if (dev->type == ECM_ARPHRD_IPSEC_TUNNEL_TYPE) {
		return ECM_INTERFACE_IPSEC_IF_NUM;
	}

	return nss_cmn_get_interface_number_by_dev(dev);
}

/*
 * ecm_nss_common_get_interface_number_by_dev_type()
 *	Returns the acceleration engine interface number based on the net_device object and type.
 */
static inline int32_t ecm_nss_common_get_interface_number_by_dev_type(struct net_device *dev, uint32_t type)
{
	/*
	 * nss_interface_num for all IPsec tunnels will always be the one specific to acceleration engine.
	 */
	if (dev->type == ECM_ARPHRD_IPSEC_TUNNEL_TYPE) {
		return ECM_INTERFACE_IPSEC_IF_NUM;
	}

	return nss_cmn_get_interface_number_by_dev_and_type(dev, type);
}

/*
 * ecm_nss_common_connection_regenerate()
 *	Re-generate a specific connection in NSS front end
 */
static inline void ecm_nss_common_connection_regenerate(struct ecm_front_end_connection_instance *feci, struct ecm_db_connection_instance *ci)
{
	/*
	 * Flag the connection as needing re-generation.
	 * Re-generation occurs when we next see traffic OR an acceleration engine sync for this connection.
	 * Refer to front end protocol specific process() functions.
	 */
	ecm_db_connection_regeneration_needed(ci);
}

/*
 * ecm_nss_common_get_interface_type()
 *	Gets the NSS interface type based on some features.
 *
 * TODO: For now the feature is the IP version and the net device type. It can be changed
 * in the future for other needs.
 */
static inline int32_t ecm_nss_common_get_interface_type(struct ecm_front_end_connection_instance *feci, int32_t dev_type)
{
	switch (dev_type) {
	case ARPHRD_SIT:
		if (feci->ip_version == 4) {
			return NSS_DYNAMIC_INTERFACE_TYPE_TUN6RD_OUTER;
		}

		if (feci->ip_version == 6) {
			return NSS_DYNAMIC_INTERFACE_TYPE_TUN6RD_INNER;
		}
	default:
		break;
	}

	/*
	 * By default.
	 */
	return NSS_DYNAMIC_INTERFACE_TYPE_NONE;
}
