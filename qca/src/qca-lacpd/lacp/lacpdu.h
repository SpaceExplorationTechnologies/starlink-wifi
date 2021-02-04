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
#ifndef __LACPDU_H
#define __LACPDU_H

#include "port_info.h"

#define LACPDU_ETH_TYPE 0x8809
#define LACPDU_SUB_TYPE 0x1
#define LACPDU_VERSION 0x1
#define LACPDU_TLV_TYPE_ACTOR 0x1
#define LACPDU_TLV_TYPE_PARTNER 0x2
#define LACPDU_TLV_TYPE_COLLECTOR_DELAY 0x3
#define LACPDU_TLV_TYPE_TERMINATOR 0x0

#define LACPDU_STATE_activity 			(1<<0)
#define LACPDU_STATE_timeout 			(1<<1)
#define LACPDU_STATE_aggregation 		(1<<2)
#define LACPDU_STATE_synchronization 	(1<<3)
#define LACPDU_STATE_collecting 		(1<<4)
#define LACPDU_STATE_distributing 		(1<<5)
#define LACPDU_STATE_defaulted 			(1<<6)
#define LACPDU_STATE_expired 			(1<<7)

typedef struct lacpdu_port_info {
	uint8_t tlv_type;		/* 0x01 for actor, 0x02 for partner */
	uint8_t tlv_length;		/* Current it is fixed in 20 */
	uint16_t system_priority;
	uint8_t system[6];
	uint16_t key;
	uint16_t port_priority;
	uint16_t port;
	uint8_t state;
	uint8_t reserved[3];
} lacpdu_port_info_t;

typedef struct lacpdu_collector_delay {
	uint8_t tlv_type;		/* 0x03 */
	uint8_t tlv_length;		/* Current it is fixed in 16 */
	uint16_t delay;
	uint8_t reserved[12];
} lacpdu_collector_delay_t;

typedef struct lacpdu_terminator {
	uint8_t tlv_type;		/* 0x0 */
	uint8_t tlv_length;		/* Current it is fixed in 0 */
	uint8_t reserved[50];
} lacpdu_terminator_t;

typedef struct lacpdu {
	uint8_t subtype;			/* LACP(= 0x01) */
	uint8_t version_number;			/* Current it is 1 */
	struct lacpdu_port_info actor;
	struct lacpdu_port_info partner;
	struct lacpdu_collector_delay collector_delay;
	struct lacpdu_terminator terminator;
} lacpdu_t;

typedef struct eth_header {
	uint8_t dst_mac[6];
	uint8_t src_mac[6];
	uint16_t eth_type;
} eth_header_t;

typedef struct lacp_pkt {
	struct eth_header eth;
	struct lacpdu lacp;
} lacp_pkt_t;

#define mac_addr_copy(dst, src) memcpy((dst), (src), 6)

static inline bool mac_addr_is_empty(uint8_t *addr)
{
	uint16_t *a = (uint16_t *)addr;

	return (a[0] | a[1] | a[2]) == 0;
}

static inline bool mac_addr_euqal(uint8_t *addr1, uint8_t *addr2)
{
	uint16_t *a = (uint16_t *)addr1;
	uint16_t *b = (uint16_t *)addr2;

	return ((a[0] ^ b[0]) | (a[1] ^ b[1]) | (a[2] ^ b[2])) == 0;
}

/*
 * lacpdu_validate : validate lacp packet
 * pkt: lacp packet
 * return value: successful or fail
 */
bool lacpdu_validate(struct lacpdu *pkt);
/*
 * lacpdu_get_port_info : get port information from packet
 * info : returned port information
 * pkt: LACP packet
 * is_actor: read actor information or partner information
 * return value: successful or fail
 */
bool lacpdu_get_port_info(struct lacpd_port_info *info, struct lacpdu *pkt, bool is_actor);
/*
 * lacpdu_set_port_info : use provided port information to fill LACP packet
 * info : provided port information
 * pkt: LACP packet
 * is_actor: fill actor information or partner information
 * return value: successful or fail
 */
bool lacpdu_set_port_info(struct lacpd_port_info *info, struct lacpdu *pkt, bool is_actor);
/*
 * lacpdu_init : fill LACP packet with default values
 */
void lacpdu_init(struct lacp_pkt *pkt);

#endif /*__LACPDU_H*/
