/*
 **************************************************************************
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
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
 * @file nss_ppe.h
 *	NSS PPE interface definitions.
 */

#ifndef _NSS_PPE_H_
#define _NSS_PPE_H_

/**
 * @addtogroup nss_ppe_subsystem
 * @{
 */

/*
 * NSS PORT defines
 */
#define NSS_PPE_NUM_PHY_PORTS_MAX		8
		/**< Maximum number of PPE phsyical ports. */

/**
 * nss_ppe_metadata_types
 *	Message types for Packet Processing Engine (PPE) requests and responses.
 */
enum nss_ppe_metadata_types {
	NSS_PPE_MSG_SYNC_STATS,
	NSS_PPE_MSG_L2_EXCEPTION,
	NSS_PPE_MSG_MAX,
};

/**
 * nss_ppe_msg_error_type
 *	PPE error types.
 */
enum nss_ppe_msg_error_type {
	PPE_MSG_ERROR_OK,
	PPE_MSG_ERROR_UNKNOWN_TYPE,
};

/**
 * nss_ppe_sync_stats_msg
 *	Message information for PPE synchronization statistics.
 */
struct nss_ppe_sync_stats_msg {
	uint32_t nss_ppe_v4_l3_flows;		/**< Number of IPv4 routed flows. */
	uint32_t nss_ppe_v4_l2_flows;		/**< Number of IPv4 bridge flows. */
	uint32_t nss_ppe_v4_create_req;		/**< Number of IPv4 create requests. */
	uint32_t nss_ppe_v4_create_fail;	/**< Number of IPv4 create failures. */
	uint32_t nss_ppe_v4_destroy_req;	/**< Number of IPv4 delete requests. */
	uint32_t nss_ppe_v4_destroy_fail;	/**< Number of IPv4 delete failures. */
	uint32_t nss_ppe_v4_mc_create_req;	/**< Number of IPv4 MC create requests. */
	uint32_t nss_ppe_v4_mc_create_fail;	/**< Number of IPv4 MC create failure. */
	uint32_t nss_ppe_v4_mc_update_req;	/**< Number of IPv4 MC update requests. */
	uint32_t nss_ppe_v4_mc_update_fail;	/**< Number of IPv4 MC update failure. */
	uint32_t nss_ppe_v4_mc_destroy_req;	/**< Number of IPv4 MC delete requests. */
	uint32_t nss_ppe_v4_mc_destroy_fail;	/**< Number of IPv4 MC delete failure. */

	uint32_t nss_ppe_v6_l3_flows;		/**< Number of IPv6 routed flows. */
	uint32_t nss_ppe_v6_l2_flows;		/**< Number of IPv6 bridge flows. */
	uint32_t nss_ppe_v6_create_req;		/**< Number of IPv6 create requests. */
	uint32_t nss_ppe_v6_create_fail;	/**< Number of IPv6 create failures. */
	uint32_t nss_ppe_v6_destroy_req;	/**< Number of IPv6 delete requests. */
	uint32_t nss_ppe_v6_destroy_fail;	/**< Number of IPv6 delete failures. */
	uint32_t nss_ppe_v6_mc_create_req;	/**< Number of IPv6 MC create requests. */
	uint32_t nss_ppe_v6_mc_create_fail;	/**< Number of IPv6 MC create failure. */
	uint32_t nss_ppe_v6_mc_update_req;	/**< Number of IPv6 MC update requests. */
	uint32_t nss_ppe_v6_mc_update_fail;	/**< Number of IPv6 MC update failure. */
	uint32_t nss_ppe_v6_mc_destroy_req;	/**< Number of IPv6 MC delete requests. */
	uint32_t nss_ppe_v6_mc_destroy_fail;	/**< Number of IPv6 MC delete failure. */

	uint32_t nss_ppe_fail_vp_full;
			/**< Request failed because the virtual port table is full */
	uint32_t nss_ppe_fail_nh_full;
			/**< Request failed because the next hop table is full. */
	uint32_t nss_ppe_fail_flow_full;
			/**< Request failed because the flow table is full. */
	uint32_t nss_ppe_fail_host_full;
			/**< Request failed because the host table is full. */
	uint32_t nss_ppe_fail_pubip_full;
			/**< Request failed because the public IP table is full. */
	uint32_t nss_ppe_fail_port_setup;
			/**< Request failed because the PPE port is not setup. */
	uint32_t nss_ppe_fail_rw_fifo_full;
			/**< Request failed because the read/write FIFO is full. */
	uint32_t nss_ppe_fail_flow_command;
			/**< Request failed because the PPE flow command failed. */
	uint32_t nss_ppe_fail_unknown_proto;
			/**< Request failed because of an unknown protocol. */
	uint32_t nss_ppe_fail_ppe_unresponsive;
			/**< Request failed because the PPE is not responding. */
	uint32_t nss_ppe_ce_opaque_invalid;
			/**< Request failed because of invalid opaque in connection entry */
	uint32_t nss_ppe_fail_fqg_full;
			/**< Request failed because the flow QoS group is full. */
};

/*
 * nss_ppe_l2_exception_msg
 *	Message structure for L2 exception.
 */
struct nss_ppe_l2_exception_msg {
	uint32_t l2_exception_enable;   /**< Enable/Disable L2 exception. */
};

/**
 * nss_ppe_msg
 *	Data for sending and receiving PPE host-to-NSS messages.
 */
struct nss_ppe_msg {
	struct nss_cmn_msg cm;		/**< Common message header. */

	/**
	 * Payload of a PPE host-to-NSS message.
	 */
	union {
		struct nss_ppe_sync_stats_msg stats;
				/**< Synchronization statistics. */
		struct nss_ppe_l2_exception_msg l2_exception;
				/**< L2 exception message. */
	} msg;			/**< Message payload. */
};

/**
 * Callback function for receiving PPE messages.
 *
 * @datatypes
 * nss_ppe_msg
 *
 * @param[in] app_data  Pointer to the application context of the message.
 * @param[in] msg       Pointer to the message data.
 */
typedef void (*nss_ppe_msg_callback_t)(void *app_data, struct nss_ppe_msg *msg);

/**
 * nss_ppe_register_handler
 *	Registers the PPE interface with NSS.
 *
 * @return
 * None.
 */
extern void nss_ppe_register_handler(void);

/**
 * nss_ppe_tx_msg
 *	Sends PPE messages to the NSS.
 *
 * @datatypes
 * nss_ctx_instance \n
 * nss_ppe_msg
 *
 * @param[in] nss_ctx  Pointer to the NSS context.
 * @param[in] msg      Pointer to the message data.
 *
 * @return
 * Status of the Tx operation.
 */
nss_tx_status_t nss_ppe_tx_msg(struct nss_ctx_instance *nss_ctx, struct nss_ppe_msg *msg);

/**
 * nss_ppe_tx_msg_sync
 *	Sends PPE messages synchronously to the NSS.
 *
 * @datatypes
 * nss_ctx_instance \n
 * nss_ppe_msg
 *
 * @param[in]     nss_ctx  Pointer to the NSS context.
 * @param[in,out] msg      Pointer to the message data.
 *
 * @return
 * Status of the Tx operation.
 */
nss_tx_status_t nss_ppe_tx_msg_sync(struct nss_ctx_instance *nss_ctx, struct nss_ppe_msg *msg);

/**
 * nss_ppe_msg_init
 *	Initializes a PPE message.
 *
 * @datatypes
 * nss_ppe_msg
 *
 * @param[in,out] ncm       Pointer to the message.
 * @param[in]     if_num    Interface number
 * @param[in]     type      Type of message.
 * @param[in]     len       Size of the payload.
 * @param[in]     cb        Callback function for the message.
 * @param[in]     app_data  Pointer to the application context of the message.
 *
 * @return
 * None.
 */
void nss_ppe_msg_init(struct nss_ppe_msg *ncm, uint16_t if_num, uint32_t type,  uint32_t len, void *cb, void *app_data);

/**
 * nss_ppe_get_context
 *	Gets the PPE context used in nss_ppe_tx.
 *
 * @return
 * Pointer to the NSS core context.
 */
struct nss_ctx_instance *nss_ppe_get_context(void);

/**
 * nss_ppe_tx_l2_exception_msg
 *      Sends the PPE a message to enable/disable L2 exceptions.
 *
 * @param[in] if_num  Interface number of the PPE.
 * @param[in] exception_enable  Enable/disable flag.
 *
 * @return
 * Status of the Tx operation.
 */
nss_tx_status_t nss_ppe_tx_l2_exception_msg(uint32_t if_num, bool exception_enable);

/**
 * nss_ppe_stats_conn_get
 *	Gets PPE connection statistics.
 *
 * @param[out] stats  Pointer to the connections statistics.
 *
 * @return
 * None.
 */
void nss_ppe_stats_conn_get(uint32_t *stats);

/**
 * nss_ppe_stats_l3_get
 *	Gets PPE l3 debug statistics.
 *
 * @param[out] stats  Pointer to the debug registers of the layer 3 interface.
 *
 * @return
 * None.
 */
void nss_ppe_stats_l3_get(uint32_t *stats);

/**
 * nss_ppe_stats_code_get
 *	Gets PPE packet code statistics.
 *
 * @param[out] stats  Pointer to the drop or CPU code for the flow.
 *
 * @return
 * None.
 */
void nss_ppe_stats_code_get(uint32_t *stats);

/**
 * nss_ppe_port_drop_code_get
 *      Gets PPE per port drop code statistics.
 *
 * @param[in]  port_id	Port ID for which drop counters are being read.
 * @param[out] stats  	Pointer to the drop code counters.
 *
 * @return
 * None.
 */
void nss_ppe_port_drop_code_get(uint32_t *stats, uint8_t port_id);

/**
 * nss_ppe_cpu_code_exception_get
 *      Gets PPE CPU code statistics for flow exceptions.
 *
 * @param[out] stats  	Pointer to the CPU code counters.
 *
 * @return
 * None.
 */
void nss_ppe_cpu_code_exception_get(uint32_t *stats);

/**
 * nss_ppe_cpu_code_nonexception_get
 *      Gets PPE CPU code statistics for non-exceptions.
 *
 * @param[out] stats  	Pointer to the CPU code counters.
 *
 * @return
 * None.
 */
void nss_ppe_cpu_code_nonexception_get(uint32_t *stats);

/** @} */ /* end_addtogroup nss_ppe_subsystem */

#endif /* _NSS_PPE_H_ */
