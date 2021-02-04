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
#ifndef __LACPD_AGGREGATOR_H
#define __LACPD_AGGREGATOR_H

#include <libubox/list.h>

#include "lacp.h"
#include "port.h"

struct lacpd_aggregator {
	/*Link to lacp->aggregators*/
	struct list_head node;
	/*All ports attached to this aggregator*/
	struct list_head ports;
	/*Lacp protocol instance this aggregator belongs to*/
	struct lacpd_lacp *lacp;

	/*Aggregator Identifier, in format of MAC address, unique in global*/
	uint8_t aggregator_mac_address[6];
	/*Aggregator Identifier, in format of integer, unique in LACP protocol instance*/
	uint32_t aggregator_identifier;
	/*individual link or aggregatable link*/
	bool individual_aggregator;
	/*Admin key for aggregator, configured by administrator*/
	uint16_t actor_admin_aggregator_key;
	/*Operation key for aggregator*/
	uint16_t actor_oper_aggregator_key;
	/*Mac address of peer, may be empty if no attached port*/
	uint8_t partner_system[6];
	/*System priority of peer, may be 0 if no attached port*/
	uint16_t partner_system_priority;
	/*operation key of peer, may be 0 if no attached port*/
	uint16_t partner_oper_aggregator_key;
	/*If receiving function of aggregator is enabled or not, set to true once any port is added into this aggregator and can receive*/
	bool receive_state;
	/*If transmiting function of aggregator is enabled or not, set to true once any port is added into this aggregator and can transmit*/
	bool transmit_state;
	/*Aggregator is free when no port attached to it*/
	bool is_free;
	/*Ifindex of physical network device which this aggregator represent*/
	uint32_t dev_ifindex;

	/*Set to true if all pending ports(wait to add to aggregator) are ready(port->ready_N is true)*/
	bool ready;

} lacpd_aggregator_t;

/*
 * lacpd_aggregator_dump_status : get status of LACP aggregator
 * agg: LACP aggregator whose status to get
 * p: lacp use this printer to print content of status
 */
void lacpd_aggregator_dump_status(struct lacpd_aggregator *agg, struct lacpd_status_printer *p);
/*
 * lacpd_aggregator_update_ready : update ready status of aggregator when wait while timer expired, or port is added/deleted
 */
void lacpd_aggregator_update_ready(struct lacpd_aggregator *agg);
/*
 * lacpd_aggregator_selector_by_id : select an aggregator by its id
 */
static inline bool lacpd_aggregator_selector_by_id(struct lacpd_aggregator *agg, void *arg)
{
	if ((agg->aggregator_identifier == 0) || ((uint32_t)arg == 0)) {
		/*
		 * Identifier is not initialized
		 */
		return false;
	}

	return agg->aggregator_identifier == (uint32_t)arg;
}

/*
 * lacpd_aggregator_selector_by_free : select a free aggregator which have no slaves
 */
static inline bool lacpd_aggregator_selector_by_free(struct lacpd_aggregator *agg, void *arg)
{
	return agg->is_free;
}

typedef bool (*aggregator_select_func_t)(struct lacpd_aggregator *agg, void *arg);
/*
 * lacpd_aggregator_lookup : use an input selection function to lookup a specific aggregator
 * lacp: lacp protocol instance, only lookup aggregators in this protocol instance
 * func: selection function
 * arg: argument passed to above function
 * return value: found aggregator or NULL
 */
struct lacpd_aggregator *
lacpd_aggregator_lookup(struct lacpd_lacp *lacp, aggregator_select_func_t func, void *arg);
/*
 * lacpd_aggregator_add_port : add a port to its selected aggregator
 */
bool lacpd_aggregator_add_port(struct lacpd_aggregator *agg, struct lacpd_port *port);
/*
 * lacpd_aggregator_del_port : delete a port from its attached aggregator
 */
bool lacpd_aggregator_del_port(struct lacpd_aggregator *agg, struct lacpd_port *port);
/*
 * lacpd_aggregator_attach_port : attach a port's physical device to physical device of its attached aggregator
 */
bool lacpd_aggregator_attach_port(struct lacpd_aggregator *agg, struct lacpd_port *port);
/*
 * lacpd_aggregator_detach_port : detach a port's physical device from physical device of its attached aggregator
 */
bool lacpd_aggregator_detach_port(struct lacpd_aggregator *agg, struct lacpd_port *port);
/*
 * lacpd_aggregator_new : create an aggregator. Initailly it is not bound to any physcial device
 */
struct lacpd_aggregator *lacpd_aggregator_new(struct lacpd_lacp *lacp, uint32_t aggregator_id);
/*
 * lacpd_aggregator_destroy : destroy an aggregator. delete all ports in it, detach from physical network device, free it
 */
void lacpd_aggregator_destroy(struct lacpd_aggregator *agg);

#endif /*__LACPD_AGGREGATOR_H*/
