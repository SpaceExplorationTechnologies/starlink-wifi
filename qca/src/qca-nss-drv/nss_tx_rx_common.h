/*
 **************************************************************************
 * Copyright (c) 2013-2018, The Linux Foundation. All rights reserved.
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
 * nss_tx_rx_common.h
 *	NSS APIs common header file
 */

#ifndef __NSS_TX_RX_COMMON_H
#define __NSS_TX_RX_COMMON_H

#include <nss_hal.h>
#include <linux/module.h>
#include <linux/vmalloc.h>

/*
 * Global definitions
 */
#define NSS_HLOS_MESSAGE_VERSION 1	/* Update when the common message structure changed */

#if (NSS_DEBUG_LEVEL > 0)
#define NSS_VERIFY_CTX_MAGIC(x) nss_verify_ctx_magic(x)
#define NSS_VERIFY_INIT_DONE(x) nss_verify_init_done(x)

/*
 * nss_verify_ctx_magic()
 */
static inline void nss_verify_ctx_magic(struct nss_ctx_instance *nss_ctx)
{
	nss_assert(nss_ctx->magic == NSS_CTX_MAGIC);
}

static inline void nss_verify_init_done(struct nss_ctx_instance *nss_ctx)
{
	nss_assert(nss_ctx->state == NSS_CORE_STATE_INITIALIZED);
}

#else
#define NSS_VERIFY_CTX_MAGIC(x)
#define NSS_VERIFY_INIT_DONE(x)
#endif

#define NSS_TX_RX_VIRT_IF_GET_INDEX(if_num)     (if_num - NSS_DYNAMIC_IF_START)

/*
 * Deprecated Redirect
 */

/**
 * @brief Request/Response types
 */
enum nss_tx_rx_virt_if_msg_types {
	NSS_TX_RX_VIRT_IF_OPEN = NSS_IF_OPEN,
	NSS_TX_RX_VIRT_IF_CLOSE = NSS_IF_CLOSE,
	NSS_TX_RX_VIRT_IF_LINK_STATE_NOTIFY = NSS_IF_LINK_STATE_NOTIFY,
	NSS_TX_RX_VIRT_IF_MTU_CHANGE = NSS_IF_MTU_CHANGE,
	NSS_TX_RX_VIRT_IF_MAC_ADDR_SET = NSS_IF_MAC_ADDR_SET,
	NSS_TX_RX_VIRT_IF_STATS_SYNC = NSS_IF_STATS,
	NSS_TX_RX_VIRT_IF_ISHAPER_ASSIGN = NSS_IF_ISHAPER_ASSIGN,
	NSS_TX_RX_VIRT_IF_BSHAPER_ASSIGN = NSS_IF_BSHAPER_ASSIGN,
	NSS_TX_RX_VIRT_IF_ISHAPER_UNASSIGN = NSS_IF_ISHAPER_UNASSIGN,
	NSS_TX_RX_VIRT_IF_BSHAPER_UNASSIGN = NSS_IF_BSHAPER_UNASSIGN,
	NSS_TX_RX_VIRT_IF_ISHAPER_CONFIG = NSS_IF_ISHAPER_CONFIG,
	NSS_TX_RX_VIRT_IF_BSHAPER_CONFIG = NSS_IF_BSHAPER_CONFIG,
	NSS_TX_RX_VIRT_IF_VSI_ASSIGN = NSS_IF_VSI_ASSIGN,
	NSS_TX_RX_VIRT_IF_VSI_UNASSIGN = NSS_IF_VSI_UNASSIGN,
	NSS_TX_RX_VIRT_IF_TX_CREATE_MSG = NSS_IF_MAX_MSG_TYPES + 1,
	NSS_TX_RX_VIRT_IF_TX_DESTROY_MSG,
	NSS_TX_RX_VIRT_IF_STATS_SYNC_MSG,
	NSS_TX_RX_VIRT_IF_MAX_MSG_TYPES,
};

/**
 * virt_if error types
 */
enum nss_tx_rx_virt_if_error_types {
	NSS_TX_RX_VIRT_IF_SUCCESS,			/*< Success */
	NSS_TX_RX_VIRT_IF_CORE_FAILURE,		/*< nss core failure */
	NSS_TX_RX_VIRT_IF_ALLOC_FAILURE,		/*< Memory allocation failure */
	NSS_TX_RX_VIRT_IF_DYNAMIC_IF_FAILURE,	/*< Dynamic interface failure */
	NSS_TX_RX_VIRT_IF_MSG_TX_FAILURE,		/*< Message transmission failure */
	NSS_TX_RX_VIRT_IF_REG_FAILURE,		/*< Registration failure */
	NSS_TX_RX_VIRT_IF_CORE_NOT_INITIALIZED,	/*< NSS core not intialized */
};

/**
 * Structure which contains stats received from NSS.
 */
struct nss_tx_rx_virt_if_stats {
	struct nss_cmn_node_stats node_stats;	/**< common stats */
	uint32_t tx_enqueue_failed;	/**< tx enqueue failures in the FW */
	uint32_t shaper_enqueue_failed;	/**< shaper enqueue failures in the FW */
};

/**
 * The NSS virtual interface creation structure.
 */
struct nss_tx_rx_virt_if_create_msg {
	uint32_t flags;			/**< Interface flags */
	uint8_t mac_addr[ETH_ALEN];	/**< MAC address */
};

/**
 * The NSS virtual interface destruction structure.
 */
struct nss_tx_rx_virt_if_destroy_msg {
	int32_t reserved;		/**< place holder */
};

/**
 * Message structure to send/receive virtual interface commands
 */
struct nss_tx_rx_virt_if_msg {
	struct nss_cmn_msg cm;
				/**< Message Header */
	union {
		union nss_if_msgs if_msgs;
		struct nss_tx_rx_virt_if_create_msg if_create;
				/**< Message: create virt if rule */
		struct nss_tx_rx_virt_if_destroy_msg if_destroy;
				/**< Message: destroy virt if rule */
		struct nss_tx_rx_virt_if_stats stats;
				/**< Message: stats */
	} msg;
};

/*
 * Private data structure for virt_if interface
 */
struct nss_tx_rx_virt_if_pvt {
	struct semaphore sem;
	struct completion complete;
	int response;
	int sem_init_done;
};

typedef void (*nss_tx_rx_virt_if_data_callback_t)(struct net_device *netdev, struct sk_buff *skb, struct napi_struct *napi);
typedef void (*nss_tx_rx_virt_if_msg_callback_t)(void *app_data, struct nss_cmn_msg *msg);

/*
 * Handles associated with redir interfaces(virt_if & wifi_i).
 * TODO: Once wifi moves to using the new interfaces, this will be deprecated.
 */

struct nss_tx_rx_virt_if_handle {
	struct nss_ctx_instance *nss_ctx;
	int32_t if_num;
	struct nss_tx_rx_virt_if_pvt *pvt;
	struct nss_tx_rx_virt_if_stats stats;
	nss_tx_rx_virt_if_msg_callback_t cb;
	void *app_data;
};

/*
 * NSS tx_rx_virt_if statistics APIs
 */
extern void nss_tx_rx_virt_if_stats_sync(struct nss_tx_rx_virt_if_handle *handle, struct nss_tx_rx_virt_if_stats *nwis);
extern void nss_tx_rx_virt_if_stats_dentry_create(void);

/*
 * CB handlers for variour interfaces
 */
void nss_phys_if_register_handler(struct nss_ctx_instance *nss_ctx, uint32_t if_num);
extern void nss_c2c_tx_register_handler(struct nss_ctx_instance *nss_ctx);
extern void nss_c2c_rx_register_handler(struct nss_ctx_instance *nss_ctx);
extern void nss_crypto_register_handler(void);
extern void nss_crypto_cmn_register_handler(void);
extern void nss_ipsec_register_handler(void);
extern void nss_ipv4_register_handler(void);
extern void nss_ipv4_reasm_register_handler(void);
extern void nss_ipv6_register_handler(void);
extern void nss_ipv6_reasm_register_handler(void);
extern void nss_n2h_register_handler(struct nss_ctx_instance *nss_ctx);
extern void nss_tunipip6_register_handler(void);
extern void nss_pppoe_register_handler(struct nss_ctx_instance *nss_ctx);
extern void nss_freq_register_handler(void);
extern void nss_eth_rx_register_handler(struct nss_ctx_instance *nss_ctx);
extern void nss_edma_register_handler(void);
extern void nss_lag_register_handler(void);
extern void nss_dynamic_interface_register_handler(struct nss_ctx_instance *nss_ctx);
extern void nss_gre_redir_register_handler(void);
extern void nss_gre_redir_lag_us_register_handler(void);
extern void nss_gre_redir_lag_ds_register_handler(void);
extern void nss_lso_rx_register_handler(struct nss_ctx_instance *nss_ctx);
extern void nss_sjack_register_handler(void);
extern void nss_wifi_register_handler(void);
extern struct net_device *nss_tstamp_register_netdev(void);
extern void nss_tstamp_register_handler(struct net_device *ndev);
extern void nss_portid_register_handler(void);
extern void nss_oam_register_handler(void);
extern void nss_dtls_register_handler(void);
extern void nss_dtls_cmn_register_handler(void);
extern void nss_gre_tunnel_register_handler(void);
extern void nss_trustsec_tx_register_handler(void);
extern void nss_wifili_register_handler(void);

/*
 * nss_if_msg_handler()
 *	External reference for internal base class handler for interface messages.
 *
 * This is not registered with nss_core.c as it is really a base class feature
 * of the phys_if and virt_if handlers.
 */
extern void nss_if_msg_handler(struct nss_ctx_instance *nss_ctx, struct nss_cmn_msg *ncm,
		__attribute__((unused))void *app_data);

#endif /* __NSS_TX_RX_COMMON_H */
