/*
 * Copyright (c) 2016, The Linux Foundation. All rights reserved.
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
#ifndef __GENERAL_DEVICE_QCA_SWITCH_H
#define __GENERAL_DEVICE_QCA_SWITCH_H

#include "general_device_switch.h"

/*
 * Definitions for shell command, start
 */
#define QCA_SW_CONFIG_PATH "/lib/functions/qca_switch_config.sh"
#define QCA_SW_RUNTIME_PORTS_DESCRIPTION "/tmp/qca_switch_ports"
#define QCA_SW_SHELL_CMD_SIZE 128
#define QCA_SW_SHELL_CMD_RESULT_SIZE 128
#define QCA_SW_SHELL_CMD_WORD_SIZE 16
#define QCA_SW_WORDS_PER_PORT 5
#define QCA_SW_PORT_DESC_SW_NAME 0
#define QCA_SW_PORT_DESC_CTRL_CH 1
#define QCA_SW_PORT_DESC_DATA_CH 2
#define QCA_SW_PORT_DESC_PT_NUM  3
#define QCA_SW_PORT_DESC_PT_NAME 4
#define QCA_SW_NUM_MAX 2
#define QCA_SW_DOMAIN_INIT 0xf0
#define QCA_SW_INTERNAL_DOMAIN_INIT 0xf0

/*
 * Definitions for shell command, end
 */
/*
 * Definitions for private header, start
 */
#define QCA_SW_CONTROL_PKT_MAX_SIZE 512
#define QCA_SW_PRIV_HDR_OFFSET 12
#define QCA_SW_PRIV_HDR_VERSION 2

struct qca_sw_priv_hdr_rx
{
	uint32_t src_port:3;
	uint32_t with_tag:1;
	uint32_t reserved:2;
	uint32_t reason:5;
	uint32_t priority:3;
	uint32_t version:2;
	uint32_t type:16;
};

struct qca_sw_priv_hdr_tx
{
	uint32_t dst_port:7;
	uint32_t from_cpu:1;
	uint32_t action:3;
	uint32_t priority:3;
	uint32_t version:2;
	uint32_t type:16;
};
/*
 * Definitions for private header, end
 */
/*
 * Definitions for SSDK, start
 */
#define QCA_SW_PORT_ID_MIN 0
#define QCA_SW_PORT_ID_MAX 6
#define QCA_SW_PORT_NUM ((QCA_SW_PORT_ID_MAX - QCA_SW_PORT_ID_MIN) + 1)
#define QCA_SW_AGG_ID_MIN 0
#define QCA_SW_AGG_ID_MAX 3
#define QCA_SW_AGG_NUM ((QCA_SW_AGG_ID_MAX - QCA_SW_AGG_ID_MIN) + 1)
#define QCA_SW_MAX_MEMBERS_IN_AGG 4
#define qca_sw_agg_id_is_valid(QCA_SW, AGG_ID) ((AGG_ID) <= QCA_SW_AGG_ID_MAX && (AGG_ID) >= QCA_SW_AGG_ID_MIN)
#define QCA_SW_TX_HASH_DA_EN (1 << 0)
#define QCA_SW_TX_HASH_SA_EN (1 << 1)
#define QCA_SW_TX_HASH_DIP_EN (1 << 2)
#define QCA_SW_TX_HASH_SIP_EN (1 << 3)
#define QCA_SW_API_MAX_PARAM 12

typedef struct
{
	uint8_t uc[6];
} fal_mac_addr_t;

typedef enum
{
	FAL_MAC_FRWRD = 0,      /**<   packets are normally forwarded */
	FAL_MAC_DROP,           /**<   packets are dropped */
	FAL_MAC_CPY_TO_CPU,     /**<   packets are copyed to cpu */
	FAL_MAC_RDT_TO_CPU      /**<   packets are redirected to cpu */
} fal_fwd_cmd_t;

typedef uint32_t fal_pbmp_t;

typedef struct
{
	fal_mac_addr_t addr;
	uint16_t    fid;
	fal_fwd_cmd_t dacmd;
	fal_fwd_cmd_t sacmd;
	union
	{
		uint32_t id;
		fal_pbmp_t map;
	} port;
	uint32_t portmap_en;
	uint32_t is_multicast;
	uint32_t static_en;
	uint32_t leaky_en;
	uint32_t mirror_en;
	uint32_t clone_en;
	uint32_t cross_pt_state;
	uint32_t da_pri_en;
	uint8_t da_queue;
	uint32_t white_list_en;
} fal_fdb_entry_t;
/*
 * Definitions for SSDK, end
 */

#define QCA_SWITCH_LAYER_DEPTH (SWITCH_PORT_LAYER_DEPTH + 1)

enum qca_sw_private_functions {
	QCA_SW_PRIVATE_FUNC_get_agg_id_of_port,
	QCA_SW_PRIVATE_FUNC_get_ports_of_agg,
	QCA_SW_PRIVATE_FUNC_get_port_hw_id,
	QCA_SW_PRIVATE_FUNC_MAX
};

enum qca_sw_reserved_fdb_type {
	QCA_SW_RESV_FDB_STP,
	QCA_SW_RESV_FDB_LACP,
	QCA_SW_RESV_FDB_MAX
};

enum qca_sw_pkt_type {
	QCA_SW_PKT_TYPE_BPDU,
	QCA_SW_PKT_TYPE_LACPDU,
	QCA_SW_PKT_TYPE_UNKNOWN
};

struct qca_switch_system {
	struct general_device_switch_system base;

	/*
	 * Which switch port should we trap control/protocol packet to
	 */
	int cpu_port;
	/*
	 * Insert private header when TX/RX on CPU port
	 * This is a counter.
	 */
	int cpu_port_priv_hdr_enabled;
	/*
	 * Which switch port should we mirror control/protocol packet to
	 */
	int mirror_port;
	/*
	 * Insert private header when TX/RX on mirror port
	 * This is a counter.
	 */
	int mirror_port_priv_hdr_enabled;
	/*
	 * Trapped/mirrored control/protocol packet will be inserted with a private header
	 * |type(16bit)|private data|original packet|, here specify the type of private header
	 */
	uint16_t private_hdr_type;
	uint16_t padd;
	/*
	 * Specify private header in switch
	 * This is a counter.
	 */
	int private_hdr_enabled;
	/*
	 * Add a reserved FDB to trap/mirror BPDU
	 * This is a counter.
	 */
	int stp_reserved_fdb_enabled;
	/*
	 * Add a reserved FDB to trap/mirror LACPDU
	 * This is a counter.
	 */
	int lacp_reserved_fdb_enabled;
	/*
	 * Raw socket is used to receive control/protocol packet, such as BPDU/LACPDU
	 */
	struct genl_os_service_fd raw_socket;
	/*
	 * Open raw socket to receive control/protocol packet
	 * This is a counter.
	 */
	int raw_socket_enabled;
	/*
	 * magic prefix for index of normal switch port
	 */
	uint32_t port_domain;
	/*
	 * magic prefix for index of switch aggregator
	 */
	uint32_t agg_domain;
	/*
	 * Once an aggregator is created, set its corresponding bit here
	 */
	uint32_t agg_id_bitmap;
	/*
	 * We can specify a destination port by private header even this port is
	 * member of trunk
	 */
	int support_priv_hdr_in_agg;
};

#endif /*__GENERAL_DEVICE_QCA_SWITCH_H*/
