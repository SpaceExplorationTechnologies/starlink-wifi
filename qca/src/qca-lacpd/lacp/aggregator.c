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
#include "aggregator.h"

/*
 * lacpd_aggregator_clear : clear an aggregator when no ports attached to it
 */
static void lacpd_aggregator_clear(struct lacpd_aggregator *agg)
{
	if (!agg) {
		DP(LACP, CRIT, "Arguments are invalid");
		return;
	}

	agg->individual_aggregator = false;
	agg->actor_admin_aggregator_key = 0;
	agg->actor_oper_aggregator_key = 0;
	memset(agg->partner_system, 0, sizeof(agg->partner_system));
	agg->partner_system_priority = 0;
	agg->partner_oper_aggregator_key = 0;
	agg->receive_state = false;
	agg->transmit_state = false;
	agg->is_free = true;
	agg->ready = false;
}

/*
 * lacpd_aggregator_contains_port : check if a port is in a specific aggregator
 */
static bool lacpd_aggregator_contains_port(struct lacpd_aggregator *agg, struct lacpd_port *port)
{
	struct lacpd_port *port_idx;

	if (!agg || !port) {
		DP(LACP, CRIT, "Arguments are invalid");
		return false;
	}

	if (agg->lacp != port->lacp) {
		DP(LACP, CRIT, "Aggregator and port are not in the same lacp protocol instance");
		return false;
	}

	list_for_each_entry(port_idx, &agg->ports, aggregator_node) {
		if (port_idx == port) {
			return true;
		}
	}

	return false;
}

/*
 * lacpd_aggregator_init_by_port : initialize aggregator when its first port was added
 */
static void lacpd_aggregator_init_by_port(struct lacpd_aggregator *agg, struct lacpd_port *port)
{
	agg->individual_aggregator = !port->actor_port_info.state.aggregation ||
					mac_addr_is_empty(port->partner_port_info.system) ||
					!port->partner_port_info.state.aggregation;
	agg->actor_admin_aggregator_key = port->actor_admin_port_info.key;
	agg->actor_oper_aggregator_key = port->actor_port_info.key;
	mac_addr_copy(agg->partner_system, port->partner_port_info.system);
	agg->partner_system_priority = port->partner_port_info.system_priority;
	agg->partner_oper_aggregator_key = port->partner_port_info.key;
	agg->receive_state = false;
	agg->transmit_state = false;
	agg->is_free = false;
	agg->ready = false;
}

/*
 * lacpd_aggregator_dump_status : get status of LACP aggregator
 * agg: LACP aggregator whose status to get
 * p: lacp use this printer to print content of status
 */
void lacpd_aggregator_dump_status(struct lacpd_aggregator *agg, struct lacpd_status_printer *p)
{
	char dev_name[LACP_NAME_SIZE];
	struct lacpd_port *port;
	uint32_t num_of_ports = 0;

	if (agg->lacp->out_api->get_dev_name(agg->lacp->out_api, agg->dev_ifindex, dev_name)) {
		p->fn(p, LACP_STATUS_FIELD_AGG_START, (void *)dev_name);
		p->fn(p, LACP_STATUS_FIELD_DEV, (void *)dev_name);
	} else {
		p->fn(p, LACP_STATUS_FIELD_AGG_START, (void *)"Unknown aggregator");
		p->fn(p, LACP_STATUS_FIELD_DEV, (void *)"Unknown device");
	}

	list_for_each_entry(port, &agg->ports, aggregator_node) {
		++num_of_ports;
	}

	p->fn(p, LACP_STATUS_FIELD_AGG_ID, (void *)agg->aggregator_identifier);
	p->fn(p, LACP_STATUS_FIELD_AGG_PORTS_CNT, (void *)num_of_ports);
	p->fn(p, LACP_STATUS_FIELD_AGG_ACTOR_KEY, (void *)(uint32_t)agg->actor_oper_aggregator_key);
	p->fn(p, LACP_STATUS_FIELD_AGG_PARTNER_KEY, (void *)(uint32_t)agg->partner_oper_aggregator_key);
	p->fn(p, LACP_STATUS_FIELD_AGG_PARTNER_HW_ADDR, (void *)agg->partner_system);

	p->fn(p, LACP_STATUS_FIELD_AGG_END, NULL);
}

/*
 * lacpd_aggregator_update_ready : update ready status of aggregator when wait while timer expired, or port is added/deleted
 */
void lacpd_aggregator_update_ready(struct lacpd_aggregator *agg)
{
	struct lacpd_port *port_idx;
	bool is_ready;

	if (!agg) {
		DP(LACP, CRIT, "Arguments are invalid");
		return;
	}

	is_ready = !list_empty(&agg->ports);
	list_for_each_entry(port_idx, &agg->ports, aggregator_node) {
		is_ready = is_ready && port_idx->ready_N;
	}

	agg->ready = is_ready;
}

/*
 * lacpd_aggregator_lookup : use an input selection function to lookup a specific aggregator
 * lacp: LACP protocol instance, only lookup aggregators in this protocol instance
 * func: selection function
 * arg: argument passed to above function
 * return value: found aggregator or NULL
 */
struct lacpd_aggregator *
lacpd_aggregator_lookup(struct lacpd_lacp *lacp, aggregator_select_func_t func, void *arg)
{
	struct lacpd_aggregator *agg;

	if (!lacp || !func) {
		DP(LACP, CRIT, "Arguments are invalid");
		return NULL;
	}

	list_for_each_entry(agg, &lacp->aggregators, node) {
		if (func(agg, arg)) {
			return agg;
		}
	}

	return NULL;
}

/*
 * lacpd_aggregator_add_port : add a port to its selected aggregator
 */
bool lacpd_aggregator_add_port(struct lacpd_aggregator *agg, struct lacpd_port *port)
{
	bool is_first_member;

	if (lacpd_aggregator_contains_port(agg, port)) {
		DP(LACP, CRIT, "Can't add because port is already in aggregator");
		return false;
	}

	is_first_member = list_empty(&agg->ports);
	list_add_tail(&port->aggregator_node, &agg->ports);
	if (is_first_member) {
		lacpd_aggregator_init_by_port(agg, port);
	}

	lacpd_aggregator_update_ready(agg);

	return true;
}

/*
 * lacpd_aggregator_del_port : delete a port from its attached aggregator
 */
bool lacpd_aggregator_del_port(struct lacpd_aggregator *agg, struct lacpd_port *port)
{
	if (!lacpd_aggregator_contains_port(agg, port)) {
		DP(LACP, CRIT, "Can't delete because port is not in aggregator");
		return false;
	}

	list_del(&port->aggregator_node);
	if (list_empty(&agg->ports)) {
		lacpd_aggregator_clear(agg);
	}

	lacpd_aggregator_update_ready(agg);

	return true;
}

/*
 * lacpd_aggregator_attach_port : attach a port's physical device to physical device of its attached aggregator
 */
bool lacpd_aggregator_attach_port(struct lacpd_aggregator *agg, struct lacpd_port *port)
{
	char dev_name[LACP_NAME_SIZE];

	if (port->dev_ifindex == 0) {
		DP(LACP, CRIT, "No physical device for port");
		return false;
	}

	if (agg->lacp != port->lacp) {
		DP(LACP, CRIT, "Aggregator and port are not in the same LACP protocol instance");
		return false;
	}

	if (agg->dev_ifindex == 0) {
		snprintf(dev_name, sizeof(dev_name), "%s.aggregator%d", agg->lacp->name, agg->aggregator_identifier);
		agg->dev_ifindex = agg->lacp->out_api->new_aggregator(agg->lacp->out_api, dev_name);
		if (agg->dev_ifindex == 0) {
			DP(LACP, CRIT, "Fail to create physical network device for aggregator");
			return false;
		}
	}

	if (agg->lacp->out_api->is_slave(agg->lacp->out_api, port->dev_ifindex, agg->dev_ifindex)) {
		DP(LACP, WARNING, "Port is already a slave of aggregator");
		return true;
	}

	if (!agg->lacp->out_api->attach_slave(agg->lacp->out_api, agg->dev_ifindex, port->dev_ifindex)) {
		return false;
	}

	lacpd_select_active_aggregator(agg->lacp);

	return true;
}

/*
 * lacpd_aggregator_detach_port : detach a port's physical device from physical device of its attached aggregator
 */
bool lacpd_aggregator_detach_port(struct lacpd_aggregator *agg, struct lacpd_port *port)
{
	if (agg->dev_ifindex == 0 || port->dev_ifindex == 0) {
		DP(LACP, DEBUG, "No physical device for aggregator or port");
		return false;
	}

	if (agg->lacp != port->lacp) {
		DP(LACP, CRIT, "Aggregator and port are not in the same lacp protocol instance");
		return false;
	}

	if (!agg->lacp->out_api->is_slave(agg->lacp->out_api, port->dev_ifindex, agg->dev_ifindex)) {
		DP(LACP, WARNING, "Port is not a slave of aggregator");
		return true;
	}

	if (!agg->lacp->out_api->detach_slave(agg->lacp->out_api, agg->dev_ifindex, port->dev_ifindex)) {
		/*
		 * Failed to detach slave from master
		 */
		return false;
	}

	lacpd_select_active_aggregator(agg->lacp);

	if (agg->lacp->out_api->number_of_slaves(agg->lacp->out_api, agg->dev_ifindex) > 0) {
		/*
		 * Still have slaves in master
		 */
		return true;
	}

	/*
	 * Last slave was removed, so destroy physical network device of aggregator
	 */
	if (agg->lacp->out_api->destroy_aggregator(agg->lacp->out_api, agg->dev_ifindex)) {
		agg->dev_ifindex = 0;
	}

	return true;
}

/*
 * lacpd_aggregator_new : create an aggregator. Initailly it is not bound to any physcial device
 */
struct lacpd_aggregator *
lacpd_aggregator_new(struct lacpd_lacp *lacp, uint32_t aggregator_id)
{
	struct lacpd_aggregator *agg;

	if (!lacp || (aggregator_id == 0)) {
		DP(LACP, CRIT, "Arguments are invalid");
		return NULL;
	}

	agg = (struct lacpd_aggregator *)calloc(1, sizeof(struct lacpd_aggregator));
	if (!agg) {
		DP(LACP, CRIT, "Allocate lacpd_aggregator failed");
		return NULL;
	}

	agg->lacp = lacp;
	INIT_LIST_HEAD(&agg->ports);
	mac_addr_copy(agg->aggregator_mac_address, lacp->actor_system);
	agg->aggregator_identifier = aggregator_id;
	agg->dev_ifindex = 0;

	lacpd_aggregator_clear(agg);

	return agg;
}

/*
 * lacpd_aggregator_destroy : destroy an aggregator. delete all ports in it, detach from physical network device, free it
 */
void lacpd_aggregator_destroy(struct lacpd_aggregator *agg)
{
	struct lacpd_port *port, *tmp;

	if (!agg) {
		DP(LACP, CRIT, "Arguments are invalid");
		return;
	}

	if (!agg->is_free) {
		DP(LACP, WARNING, "Warning: try to free a none-free aggregator");
	}

	list_for_each_entry_safe(port, tmp, &agg->ports, aggregator_node) {
		lacpd_aggregator_detach_port(agg, port);
		lacpd_aggregator_del_port(agg, port);
	}

	if (!agg->is_free) {
		DP(LACP, WARNING, "Warning: aggregator is not cleaned before free");
	}

	free(agg);
}
