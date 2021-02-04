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
#ifndef __LACPD_H
#define __LACPD_H

#include <libubox/list.h>
#include <libubox/uloop.h>

#include "lacp_api.h"

#define LACP_NAME_SIZE 64
#define DEFAULT_SYSTEM_PRIORITY 0xffff

struct lacpd_lacp {
	char name[LACP_NAME_SIZE];

	struct lacp_parameters param;	/*Parameters for LACP instance*/
	uint8_t actor_system[6];	/*MAC address of system*/
	uint16_t actor_system_priority;	/*System priority of system*/

	uint32_t next_port_agg_id;	/*Next available id for both port and aggregator*/
	struct list_head ports;		/*Ports in this LACP protocol instance*/
	struct list_head aggregators;	/*Aggregators in this LACP protocol instance*/
	uint32_t active_aggregator;	/*Current active aggregator in LACP instance*/

	struct lacp_out_api *out_api;	/*provided by wrapper, LACP call these API to configure physical network device*/
	struct lacp_in_api in_api;	/*provided by LACP, wrapper call these API to notify packet/link event*/
};

/*
 * lacpd_select_active_aggregator : select an active aggregator according to configured algorithm
 *
 * LACP_AD_SELECT_ALG_ALL: all aggregator in LACP instance should be active,
 * this is useful when all ports of LACP instance are in same bridge. Two ports
 * which can't be aggregated can still be members of same bridge. They can be treated as normal port.
 *
 * LACP_AD_SELECT_ALG_STABLE: select only one aggregator in a LACP instance.
 * select the aggregator with the most ports attached to it, and to reselect the active aggregator
 * only if the previous aggregator has no more ports related to it.
 *
 * LACP_AD_SELECT_ALG_BANDWIDTH: select only one aggregator in a LACP instance.
 * select the aggregator with the highest total bandwidth, and reselect whenever a link state change
 * takes place or the set of slaves in the aggregator changes.
 *
 * LACP_AD_SELECT_ALG_COUNT: select only one aggregator in a LACP instance.
 * select the aggregator with largest number of ports (slaves), and reselect whenever a link state change
 * takes place or the set of slaves in the aggregator changes.
 *
 */
void lacpd_select_active_aggregator(struct lacpd_lacp *lacp);

#endif /*__LACPD_H*/
