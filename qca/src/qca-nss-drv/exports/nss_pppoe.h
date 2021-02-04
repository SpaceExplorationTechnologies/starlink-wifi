/*
 **************************************************************************
 * Copyright (c) 2014-2017, The Linux Foundation. All rights reserved.
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

/**
 * @file nss_pppoe.h
 * 	NSS PPPoE interface definitions.
 */

#ifndef __NSS_PPPOE_H
#define __NSS_PPPOE_H

/**
 * @addtogroup nss_pppoe_subsystem
 * @{
 */

/**
 * nss_pppoe_metadata_types
 *	Message types for PPPoE requests and responses.
 *
 * NSS_PPPOE_RX_DEPRECATED0 and NSS_PPPOE_RX_DEPRECATED1 are deprecated types.
 * They are kept for backward compatibility.
 */
enum nss_pppoe_metadata_types {
	NSS_PPPOE_RX_DEPRECATED0,
	NSS_PPPOE_RX_DEPRECATED1,
	NSS_PPPOE_RX_CONN_STATS_SYNC,
	NSS_PPPOE_RX_NODE_STATS_SYNC,
	NSS_PPPOE_RX_SESSION_RESET,
	NSS_PPPOE_MAX,
};

/**
 * nss_pppoe_exception_events
 *	Exception events from the PPPoE handler.
 */
enum nss_pppoe_exception_events {
	NSS_PPPOE_EXCEPTION_EVENT_WRONG_VERSION_OR_TYPE,
	NSS_PPPOE_EXCEPTION_EVENT_WRONG_CODE,
	NSS_PPPOE_EXCEPTION_EVENT_HEADER_INCOMPLETE,
	NSS_PPPOE_EXCEPTION_EVENT_UNSUPPORTED_PPP_PROTOCOL,
	NSS_PPPOE_EXCEPTION_EVENT_DEPRECATED,
	NSS_PPPOE_EXCEPTION_EVENT_MAX,
};

/**
 * nss_pppoe_node_stats_sync_msg
 *	PPPoE node synchronization statistics.
 */
struct nss_pppoe_node_stats_sync_msg {
	struct nss_cmn_node_stats node_stats;	/**< Common node statistics. */
	uint32_t pppoe_session_create_requests;
			/**< Number of PPPoE session create requests. */
	uint32_t pppoe_session_create_failures;
			/**< Number of PPPoE session create failures. */
	uint32_t pppoe_session_destroy_requests;
			/**< Number of PPPoE session destroy requests. */
	uint32_t pppoe_session_destroy_misses;
			/**< Number of PPPoE session destroy misses. */
};

/**
 * nss_pppoe_session_reset_msg
 *	Reset message information for a PPPoE session.
 */
struct nss_pppoe_session_reset_msg {
	uint32_t interface;	/**< NSS interface number. */
	uint32_t session_index;	/**< Index of the session in the NSS PPPoE session array. */
};

/**
 * nss_pppoe_conn_stats_sync_msg
 *	Synchronized statistics message for a PPPoE exception.
 */
struct nss_pppoe_conn_stats_sync_msg {
	uint16_t pppoe_session_id;
			/**< PPPoE session ID on which statistics are based. */
	uint8_t pppoe_remote_mac[ETH_ALEN];
			/**< PPPoE server MAC address. */
	uint32_t exception_events_pppoe[NSS_PPPOE_EXCEPTION_EVENT_MAX];
			/**< PPPoE exception events. */
	uint32_t index;
			/**< Per-interface array index. */
	uint32_t interface_num;
			/**< Interface number on which this session is created. */
};

/**
 * nss_pppoe_msg
 *	Data for sending and receiving PPPoE messages.
 */
struct nss_pppoe_msg {
	struct nss_cmn_msg cm;		/**< Common message header. */

	/**
	 * Payload of a PPPoE message.
	 */
	union {
		struct nss_pppoe_conn_stats_sync_msg pppoe_conn_stats_sync;
				/**< Synchronized statistics for an exception. */
		struct nss_pppoe_node_stats_sync_msg pppoe_node_stats_sync;
				/**< Synchronized statistics for a node. */
		struct nss_pppoe_session_reset_msg pppoe_session_reset;
				/**< Reset a session. */
	} msg;			/**< Message payload. */
};

/**
 * nss_pppoe_tx
 *	Sends a PPPoE message to the NSS firmware.
 *
 * @datatypes
 * nss_ctx_instance \n
 * nss_pppoe_msg
 *
 * @param[in] nss_ctx  Pointer to the NSS context.
 * @param[in] msg      Pointer to the message data.
 *
 * @return
 * Status of the Tx operation.
 */
extern nss_tx_status_t nss_pppoe_tx(struct nss_ctx_instance *nss_ctx, struct nss_pppoe_msg *msg);

/**
 * nss_pppoe_msg_init
 *	Initializes a PPPoE-specific message.
 *
 * @datatypes
 * nss_pppoe_msg
 *
 * @param[in,out] npm       Pointer to the NSS Profiler message.
 * @param[in]     if_num    NSS interface number.
 * @param[in]     type      Type of message.
 * @param[in]     len       Size of the message.
 * @param[in]     cb        Pointer to the callback message.
 * @param[in]     app_data  Pointer to the application context of the message.
 *
 * @return
 * None.
 */
extern void nss_pppoe_msg_init(struct nss_pppoe_msg *npm, uint16_t if_num, uint32_t type, uint32_t len,
				void *cb, void *app_data);

/**
 * @}
 */

#endif /* __NSS_PPPOE_H */
