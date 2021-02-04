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
#include <arpa/inet.h>

#include "lacpdu.h"

/*
 * lacpdu_validate : validate lacp packet
 * pkt: lacp packet
 * return value: successful or fail
 */
bool lacpdu_validate(struct lacpdu *pkt)
{
	return (pkt->subtype == LACPDU_SUB_TYPE) &&
		(pkt->version_number == LACPDU_VERSION) &&
		(pkt->actor.tlv_type == LACPDU_TLV_TYPE_ACTOR) &&
		(pkt->actor.tlv_length == sizeof(struct lacpdu_port_info)) &&
		(pkt->partner.tlv_type == LACPDU_TLV_TYPE_PARTNER) &&
		(pkt->partner.tlv_length == sizeof(struct lacpdu_port_info));
}

/*
 * lacpdu_get_port_info : get port information from packet
 * info : returned port information
 * pkt: lacp packet
 * is_actor: read actor information or partner information
 * return value: successful or fail
 */
bool lacpdu_get_port_info(struct lacpd_port_info *info, struct lacpdu *pkt, bool is_actor)
{
	struct lacpdu_port_info *from = is_actor? (&pkt->actor) : (&pkt->partner);

	info->system_priority = ntohs(from->system_priority);
	mac_addr_copy(info->system, from->system);
	info->key = ntohs(from->key);
	info->port_priority = ntohs(from->port_priority);
	info->port = ntohs(from->port);
	info->state.activity = !!(from->state & LACPDU_STATE_activity);
	info->state.timeout = !!(from->state & LACPDU_STATE_timeout);
	info->state.aggregation = !!(from->state & LACPDU_STATE_aggregation);
	info->state.synchronization = !!(from->state & LACPDU_STATE_synchronization);
	info->state.collecting = !!(from->state & LACPDU_STATE_collecting);
	info->state.distributing = !!(from->state & LACPDU_STATE_distributing);
	info->state.defaulted = !!(from->state & LACPDU_STATE_defaulted);
	info->state.expired = !!(from->state & LACPDU_STATE_expired);

	return true;
}

/*
 * lacpdu_set_port_info : use provided port information to fill lacp packet
 * info : provided port information
 * pkt: lacp packet
 * is_actor: fill actor information or partner information
 * return value: successful or fail
 */
bool lacpdu_set_port_info(struct lacpd_port_info *info, struct lacpdu *pkt, bool is_actor)
{
	struct lacpdu_port_info *to = is_actor? (&pkt->actor) : (&pkt->partner);

	to->system_priority = htons(info->system_priority);
	mac_addr_copy(to->system, info->system);
	to->key = htons(info->key);
	to->port_priority = htons(info->port_priority);
	to->port = htons(info->port);
	to->state |= info->state.activity ? (LACPDU_STATE_activity) : 0;
	to->state |= info->state.timeout ? (LACPDU_STATE_timeout) : 0;
	to->state |= info->state.aggregation ? (LACPDU_STATE_aggregation) : 0;
	to->state |= info->state.synchronization ? (LACPDU_STATE_synchronization) : 0;
	to->state |= info->state.collecting ? (LACPDU_STATE_collecting) : 0;
	to->state |= info->state.distributing ? (LACPDU_STATE_distributing) : 0;
	to->state |= info->state.defaulted ? (LACPDU_STATE_defaulted) : 0;
	to->state |= info->state.expired ? (LACPDU_STATE_expired) : 0;

	return true;
}

/*
 * lacpdu_init : fill lacp packet with default values
 */
void lacpdu_init(struct lacp_pkt *pkt)
{
	static uint8_t lacpdu_dst_mac[6] = {0x01, 0x80, 0xc2, 0x0, 0x0, 0x02};

	memset(pkt, 0, sizeof(struct lacp_pkt));
	mac_addr_copy(pkt->eth.dst_mac, lacpdu_dst_mac);
	pkt->eth.eth_type = htons(LACPDU_ETH_TYPE);
	pkt->lacp.subtype = LACPDU_SUB_TYPE;
	pkt->lacp.version_number = LACPDU_VERSION;
	pkt->lacp.actor.tlv_type = LACPDU_TLV_TYPE_ACTOR;
	pkt->lacp.actor.tlv_length = sizeof(struct lacpdu_port_info);
	pkt->lacp.partner.tlv_type = LACPDU_TLV_TYPE_PARTNER;
	pkt->lacp.partner.tlv_length = sizeof(struct lacpdu_port_info);
	pkt->lacp.collector_delay.tlv_type = LACPDU_TLV_TYPE_COLLECTOR_DELAY;
	pkt->lacp.collector_delay.tlv_length = sizeof(struct lacpdu_collector_delay);
	pkt->lacp.collector_delay.delay = 0;
	pkt->lacp.terminator.tlv_type = LACPDU_TLV_TYPE_TERMINATOR;
	pkt->lacp.terminator.tlv_length = 0;
}
