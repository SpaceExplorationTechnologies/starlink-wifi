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
#include "lacp.h"
#include "lacpdu.h"
#include "port.h"
#include "aggregator.h"

/*
 * lacpd_aggregator_selection_compare: decide if "curr" is a better choice for the new active aggregator
 * than the current best, according to the configured selection policy.
 */
static struct lacpd_aggregator *lacpd_aggregator_selection_compare(struct lacpd_aggregator *best, struct lacpd_aggregator *curr)
{
	int num_of_ports_of_best, num_of_ports_of_curr;
	int bandwidth_of_best, bandwidth_of_curr;
	struct lacpd_port *port;

	/* 0. If no best, select current.
	 *
	 * 1. If the current agg is not individual, and the best is
	 *    individual, select current.
	 *
	 * 2. If current agg is individual and the best is not, keep best.
	 *
	 * 3. Therefore, current and best are both individual or both not
	 *    individual, so:
	 *
	 * 3a. If current agg partner replied, and best agg partner did not,
	 *     select current.
	 *
	 * 3b. If current agg partner did not reply and best agg partner
	 *     did reply, keep best.
	 *
	 * 4.  Therefore, current and best both have partner replies or
	 *     both do not, so perform selection policy:
	 *
	 * BOND_AD_COUNT: Select by count of ports.  If count is equal,
	 *     select by bandwidth.
	 *
	 * BOND_AD_STABLE, BOND_AD_BANDWIDTH: Select by bandwidth.
	 */
	if (!best) {
		return curr;
	}

	if (!curr->individual_aggregator && best->individual_aggregator) {
		return curr;
	}

	if (curr->individual_aggregator && !best->individual_aggregator) {
		return best;
	}

	if (!mac_addr_is_empty(curr->partner_system) && mac_addr_is_empty(best->partner_system)) {
		return curr;
	}

	if (mac_addr_is_empty(curr->partner_system) && !mac_addr_is_empty(best->partner_system)) {
		return best;
	}

	num_of_ports_of_best = 0;
	bandwidth_of_best = 0;
	list_for_each_entry(port, &best->ports, aggregator_node) {
		++num_of_ports_of_best;
		bandwidth_of_best += lacpd_port_key_to_speed(lacp_port_key_get_speed(port->actor_port_info.key));
	}

	num_of_ports_of_curr = 0;
	bandwidth_of_curr = 0;
	list_for_each_entry(port, &curr->ports, aggregator_node) {
		++num_of_ports_of_curr;
		bandwidth_of_curr += lacpd_port_key_to_speed(lacp_port_key_get_speed(port->actor_port_info.key));
	}

	switch (curr->lacp->param.ad_select) {
	case LACP_AD_SELECT_ALG_COUNT:
		if (num_of_ports_of_curr > num_of_ports_of_best) {
			return curr;
		}

		if (num_of_ports_of_curr < num_of_ports_of_best) {
			return best;
		}

		/*fall through*/
	case LACP_AD_SELECT_ALG_STABLE:
	case LACP_AD_SELECT_ALG_BANDWIDTH:
		if (bandwidth_of_curr > bandwidth_of_best) {
			return curr;
		}

		break;

	default:
		break;
	}

	return best;
}

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
void lacpd_select_active_aggregator(struct lacpd_lacp *lacp)
{
	struct lacpd_aggregator *active, *best, *agg;

	if (!lacp) {
		return;
	}

	if (lacp->param.ad_select == LACP_AD_SELECT_ALG_ALL) {
		/*
		 * all aggregator should be active, so nothing to do
		 */
		return;
	}

	active = lacpd_aggregator_lookup(lacp, lacpd_aggregator_selector_by_id, (void *)lacp->active_aggregator);
	best = (active && lacp->out_api->get_dev_link_status(lacp->out_api, active->dev_ifindex)) ? active : NULL;
	lacp->active_aggregator = 0;

	list_for_each_entry(agg, &lacp->aggregators, node) {
		if (!agg->is_free && lacp->out_api->get_dev_link_status(lacp->out_api, agg->dev_ifindex)) {
			best = lacpd_aggregator_selection_compare(best, agg);
		}
	}

	if (best && lacp->param.ad_select == LACP_AD_SELECT_ALG_STABLE) {
		/*
		 * For the stable policy, don't replace the old active aggregator if it's still active (it has an answering
		 * partner) or if both the best and active don't have an answering partner.
		 */
		if (active && !list_empty(&active->ports) &&
			lacp->out_api->get_dev_link_status(lacp->out_api, active->dev_ifindex) &&
		    (!mac_addr_is_empty(active->partner_system) ||
		     (mac_addr_is_empty(active->partner_system) && mac_addr_is_empty(best->partner_system)))) {
			if (!(!active->actor_oper_aggregator_key && best->actor_oper_aggregator_key)) {
				lacp->active_aggregator = active->aggregator_identifier;
				best = NULL;
			}
		}
	}

	if (best && (best == active)) {
		lacp->active_aggregator = active->aggregator_identifier;
		best = NULL;
	}

	/*
	 * if there is new best aggregator, activate it
	 */
	if (best) {
		lacp->active_aggregator = best->aggregator_identifier;

		/*
		 * disable former active_aggregator
		 */
		if (active) {
			lacp->out_api->disable_dev(lacp->out_api, active->dev_ifindex);
		}
	}

	/*
	 * enable selected active aggregator
	 */
	active = lacpd_aggregator_lookup(lacp, lacpd_aggregator_selector_by_id, (void *)lacp->active_aggregator);
	if (active) {
		lacp->out_api->enable_dev(lacp->out_api, active->dev_ifindex);
	}
}

/*
 * lacpd_add_device : let a physical network device join a LACP protocol instance
 * lacp_obj: this is used to get instance of LACP protocol
 * dev_obj: network device to run LACP protocol
 * param: parameters for LACP port
 * return value: successful or fail
 */
static bool lacpd_add_device(struct lacp_in_api *lacp_obj, uint32_t dev_ifindex, struct lacp_port_parameters *param)
{
	struct lacpd_lacp *lacp = container_of(lacp_obj, struct lacpd_lacp, in_api);
	struct lacpd_port *port;
	struct lacpd_aggregator *agg;

	port = lacpd_port_lookup(lacp, dev_ifindex);
	if (port) {
		DP(LACP, CRIT, "Port already exist");
		return false;
	}

	port = lacpd_port_new(lacp, lacp->next_port_agg_id, dev_ifindex, param);
	if (!port) {
		DP(LACP, CRIT, "Create port failed");
		return false;
	}

	agg = lacpd_aggregator_new(lacp, lacp->next_port_agg_id);
	if (!agg) {
		DP(LACP, CRIT, "Create aggregator failed");
		lacpd_port_destroy(port);
		return false;
	}

	list_add_tail(&port->node, &lacp->ports);
	list_add_tail(&agg->node, &lacp->aggregators);
	++lacp->next_port_agg_id;

	port->lacp->out_api->enable_lacp(port->lacp->out_api, port->dev_ifindex);
	lacpd_port_fsm_schedule_run(port);

	return true;
}

/*
 * lacpd_del_device : let a physical network device leave a LACP protocol instance
 * lacp_obj: this is used to get instance of LACP protocol
 * dev_ifindex: requested network device
 * return value: successful or fail
 */
static bool lacpd_del_device(struct lacp_in_api *lacp_obj, uint32_t dev_ifindex)
{
	struct lacpd_lacp *lacp = container_of(lacp_obj, struct lacpd_lacp, in_api);
	struct lacpd_port *port;
	struct lacpd_aggregator *agg;

	port = lacpd_port_lookup(lacp, dev_ifindex);
	if (!port) {
		DP(LACP, CRIT, "Port doesn't exist");
		return false;
	}

	port->lacp->out_api->disable_lacp(port->lacp->out_api, port->dev_ifindex);

	list_del(&port->node);
	lacpd_port_destroy(port);

	agg = lacpd_aggregator_lookup(lacp, lacpd_aggregator_selector_by_free, NULL);
	if (agg) {
		list_del(&agg->node);
		lacpd_aggregator_destroy(agg);
	}

	return true;
}

/*
 * lacpd_link_status_changed : notify link status event of physical network device
 * lacp_obj: this is used to get instance of LACP protocol
 * dev_ifindex: network device where event happen
 * new_status: new link status of device
 */
static void lacpd_link_status_changed(struct lacp_in_api *lacp_obj, uint32_t dev_ifindex, int new_status)
{
	struct lacpd_lacp *lacp = container_of(lacp_obj, struct lacpd_lacp, in_api);
	struct lacpd_port *port, *tmp;

	list_for_each_entry_safe(port, tmp, &lacp->ports, node) {
		if (port->dev_ifindex == dev_ifindex) {
			uint32_t user_key = lacp_port_key_get_user(port->actor_port_info.key);
			uint32_t duplex = port->lacp->out_api->get_dev_duplex(port->lacp->out_api, port->dev_ifindex);
			uint32_t speed = port->lacp->out_api->get_dev_speed(port->lacp->out_api, port->dev_ifindex);

			port->actor_port_info.key = lacp_port_key_make(user_key, lacpd_port_speed_to_key(speed), duplex);
			port->actor_port_info.state.aggregation = (duplex ? true : false);

			port->port_enabled = new_status;
			port->runner.initialized = false;
			lacpd_port_fsm_schedule_run(port);
			break;
		}
	}
}

/*
 * lacpd_receive_lacpdu : receive LACP packet
 * lacp_obj: this is used to get instance of LACP protocol
 * buf: packet
 * buf_len: length of packet
 * dev_ifindex: receiving network device
 * return value: packet is consumed or not
 */
static bool lacpd_receive_lacpdu(struct lacp_in_api *lacp_obj, uint8_t *buf, uint32_t buf_len, uint32_t dev_ifindex)
{
	struct lacpd_lacp *lacp = container_of(lacp_obj, struct lacpd_lacp, in_api);
	struct lacp_pkt *pkt = (struct lacp_pkt *)buf;
	struct lacpd_port *port, *tmp;

	list_for_each_entry_safe(port, tmp, &lacp->ports, node) {
		if (port->dev_ifindex == dev_ifindex) {
			port->message[0] = pkt->lacp;
			port->lacpdu_indicate = true;
			lacpd_port_fsm_schedule_run(port);
			return true;
		}
	}

	return false;
}

/*
 * lacpd_status_dump : get status of LACP instance
 * lacp_obj: this is used to get instance of LACP protocol
 * p: lacp use this printer to print content of status
 */
static void lacpd_status_dump(struct lacp_in_api *lacp_obj, struct lacpd_status_printer *p)
{
	struct lacpd_lacp *lacp = container_of(lacp_obj, struct lacpd_lacp, in_api);
	struct lacpd_port *port;
	struct lacpd_aggregator *agg;

	p->fn(p, LACP_STATUS_FIELD_LACP_START, NULL);
	p->fn(p, LACP_STATUS_FIELD_LACP_NAME, (void *)lacp->name);
	p->fn(p, LACP_STATUS_FIELD_SYS_HW_ADDR, (void *)lacp->actor_system);
	p->fn(p, LACP_STATUS_FIELD_LACP_RATE, (void *)lacp->param.lacp_rate);
	p->fn(p, LACP_STATUS_FIELD_AD_SELECT_ALG, (void *)lacp->param.ad_select);
	p->fn(p, LACP_STATUS_FIELD_LACP_END, NULL);

	p->fn(p, LACP_STATUS_FIELD_AGGS_START, NULL);
	list_for_each_entry(agg, &lacp->aggregators, node) {
		lacpd_aggregator_dump_status(agg, p);
	}
	p->fn(p, LACP_STATUS_FIELD_AGGS_END, NULL);

	p->fn(p, LACP_STATUS_FIELD_PORTS_START, NULL);
	list_for_each_entry(port, &lacp->ports, node) {
		lacpd_port_dump_status(port, p);
	}
	p->fn(p, LACP_STATUS_FIELD_PORTS_END, NULL);
}

/*
 * lacp_destroy : destroy a LACP protocol instance, LACP user shouldn't reference lacp_obj after this calling
 * lacp_obj: this is used to get instance of LACP protocol
 */
static void lacp_destroy(struct lacp_in_api *lacp_obj)
{
	struct lacpd_lacp *lacp = container_of(lacp_obj, struct lacpd_lacp, in_api);
	struct lacpd_port *port, *tmp;
	struct lacpd_aggregator *agg, *agg_tmp;

	list_for_each_entry_safe(port, tmp, &lacp->ports, node) {
		port->lacp->out_api->disable_lacp(port->lacp->out_api, port->dev_ifindex);
		list_del(&port->node);
		lacpd_port_destroy(port);
	}

	list_for_each_entry_safe(agg, agg_tmp, &lacp->aggregators, node) {
		list_del(&agg->node);
		lacpd_aggregator_destroy(agg);
	}

	DP(LACP, DEBUG, "Destroy lacp instance %s successful", lacp->name);
	free(lacp);
}

/*
 * lacp_new : create a LACP protocol instance
 * name: name of LACP protocol instance
 * lacp_user: APIs provided by wrapper, LACP call these APIs to configure physical device
 * param: parameters for LACP instance
 * return value: APIs provided by LACP instance, wrapper call these APIs to notify LACP instance with LACP packet/link event
 */
struct lacp_in_api *lacp_new(const char *name, struct lacp_out_api *lacp_user, struct lacp_parameters *param)
{
	struct lacpd_lacp *lacp;

	if (!name || !lacp_user) {
		DP(LACP, CRIT, "Arguments are invalid");
		return NULL;
	}

	lacp = (struct lacpd_lacp *)calloc(1, sizeof(struct lacpd_lacp));
	if (!lacp) {
		DP(LACP, CRIT, "Allocate lacpd_lacp failed");
		return NULL;
	}

	if (!lacp_user->get_sys_mac_addr(lacp_user, lacp->actor_system)) {
		DP(LACP, CRIT, "Failed to get system MAC address when create LACP instance %s", name);
		free(lacp);
		return NULL;
	}

	snprintf(lacp->name, sizeof(lacp->name), name);
	lacp->param = *param;
	lacp->actor_system_priority = lacp->param.priority;
	lacp->next_port_agg_id = 1;
	INIT_LIST_HEAD(&lacp->ports);
	INIT_LIST_HEAD(&lacp->aggregators);

	lacp->out_api = lacp_user;
	lacp->in_api.add_device = lacpd_add_device;
	lacp->in_api.del_device = lacpd_del_device;
	lacp->in_api.link_status_changed = lacpd_link_status_changed;
	lacp->in_api.receive_lacpdu = lacpd_receive_lacpdu;
	lacp->in_api.status_dump = lacpd_status_dump;
	lacp->in_api.destroy = lacp_destroy;

	return &lacp->in_api;
}
