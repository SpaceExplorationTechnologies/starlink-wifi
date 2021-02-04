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
#include "port.h"
#include "aggregator.h"
#include "lacp_fsm.h"

/*
 * lacpd_port_lookup : lookup port by its physical network device
 * dev_ifindex: requested network device
 * return value: found port or NULL
 */
struct lacpd_port *lacpd_port_lookup(struct lacpd_lacp *lacp, uint32_t dev_ifindex)
{
	struct lacpd_port *port, *tmp;

	if (!lacp || (dev_ifindex == 0)) {
		return NULL;
	}

	list_for_each_entry_safe(port, tmp, &lacp->ports, node) {
		if (port->dev_ifindex == dev_ifindex) {
			return port;
		}
	}

	return NULL;
}

/*
 * lacpd_port_state_machine_get : get a specific type of state machine of port
 * port: LACP port to lookup
 * type: type of state machine to get
 * return value: found state machine or NULL
 */
struct state_machine *lacpd_port_state_machine_get(struct lacpd_port *port, enum lacpd_port_state_machines type)
{
	return fsm_runner_lookup_state_machine(&port->runner, type);
}

/*
 * lacpd_port_dump_status : get status of LACP port
 * port: LACP port whose status to get
 * p: lacp use this printer to print content of status
 */
void lacpd_port_dump_status(struct lacpd_port *port, struct lacpd_status_printer *p)
{
	char dev_name[LACP_NAME_SIZE];

	if (port->lacp->out_api->get_dev_name(port->lacp->out_api, port->dev_ifindex, dev_name)) {
		p->fn(p, LACP_STATUS_FIELD_PORT_START, (void *)dev_name);
		p->fn(p, LACP_STATUS_FIELD_DEV, (void *)dev_name);
	} else {
		p->fn(p, LACP_STATUS_FIELD_PORT_START, (void *)"Unknown slave");
		p->fn(p, LACP_STATUS_FIELD_DEV, (void *)"Unknown device");
	}

	p->fn(p, LACP_STATUS_FIELD_PORT_LINK_STATUS, (void *)port->port_enabled);
	p->fn(p, LACP_STATUS_FIELD_PORT_SPEED, (void *)lacpd_port_key_to_speed(lacp_port_key_get_speed(port->actor_port_info.key)));
	p->fn(p, LACP_STATUS_FIELD_PORT_DUPLEX, (void *)lacp_port_key_get_duplex(port->actor_port_info.key));
	p->fn(p, LACP_STATUS_FIELD_PORT_HW_ADDR, (void *)port->mac);
	p->fn(p, LACP_STATUS_FIELD_ACTOR_PORT, (void *)(uint32_t)port->actor_port_info.port);
	p->fn(p, LACP_STATUS_FIELD_ACTOR_STATE, (void *)&port->actor_port_info.state);
	p->fn(p, LACP_STATUS_FIELD_PARTNER_PORT, (void *)(uint32_t)port->partner_port_info.port);
	p->fn(p, LACP_STATUS_FIELD_PARTNER_STATE, (void *)&port->partner_port_info.state);
	p->fn(p, LACP_STATUS_FIELD_AGG_ID, (void *)port->actor_port_aggregator_identifier);
	p->fn(p, LACP_STATUS_FIELD_PORT_STATS_TX_SUCCESS, (void *)port->tx_successes);
	p->fn(p, LACP_STATUS_FIELD_PORT_STATS_RX_SUCCESS, (void *)port->rx_successes);
	p->fn(p, LACP_STATUS_FIELD_PORT_STATS_TX_ERROR, (void *)port->tx_error);
	p->fn(p, LACP_STATUS_FIELD_PORT_STATS_RX_ERROR, (void *)port->rx_error);

	p->fn(p, LACP_STATUS_FIELD_PORT_END, NULL);
}

/*
 * lacpd_port_initialize_manageable_variable : initialize manageable variables of port
 */
static bool lacpd_port_initialize_manageable_variable(struct lacpd_port *port, uint32_t port_num, struct lacp_port_parameters *param)
{
	uint32_t user_key = param ? param->user_key : LACP_PORT_USER_KEY_DEFAULT;

	mac_addr_copy(port->actor_admin_port_info.system, port->lacp->actor_system);
	port->actor_admin_port_info.system_priority = port->lacp->actor_system_priority;
	port->actor_admin_port_info.key = lacp_port_key_make(user_key, LACP_PORT_SPEED_DEFAULT, LACP_PORT_DUPLEX_DEFAULT);
	port->actor_admin_port_info.port_priority = DEFAULT_PORT_PRIORITY;
	port->actor_admin_port_info.port = port_num;
	port->actor_admin_port_info.state.activity = true;
	port->actor_admin_port_info.state.timeout = port->lacp->param.lacp_rate;
	port->actor_admin_port_info.state.aggregation = true;

	port->partner_admin_port_info.system_priority = DEFAULT_SYSTEM_PRIORITY;
	port->partner_admin_port_info.port_priority = DEFAULT_PORT_PRIORITY;
	port->partner_admin_port_info.state.activity = true;
	port->partner_admin_port_info.state.aggregation = false;

	return true;
}

/*
 * lacpd_port_initialize_runtime_variable : initialize runtime variables of port
 */
static bool lacpd_port_initialize_runtime_variable(struct lacpd_port *port)
{
	uint32_t user_key = lacp_port_key_get_user(port->actor_admin_port_info.key);
	uint32_t duplex = port->lacp->out_api->get_dev_duplex(port->lacp->out_api, port->dev_ifindex);
	uint32_t speed = port->lacp->out_api->get_dev_speed(port->lacp->out_api, port->dev_ifindex);

	port->actor_port_info = port->actor_admin_port_info;
	port->actor_port_info.key = lacp_port_key_make(user_key, lacpd_port_speed_to_key(speed), duplex);
	port->actor_port_info.state.aggregation = (duplex ? true : false);

	port->partner_port_info = port->partner_admin_port_info;

	port->actor_port_aggregator_identifier = 0;
	port->ntt = false;
	port->port_enabled = port->lacp->out_api->get_dev_link_status(port->lacp->out_api, port->dev_ifindex);
	port->lacp_enabled = true;
	port->ready_N = false;
	port->selected = LACPD_SEL_STATE_UNSELECTED;

	return true;
}

/*
 * lacpd_port_new : create port base on a physical network device
 */
struct lacpd_port *
lacpd_port_new(struct lacpd_lacp *lacp, uint32_t port_num, uint32_t dev_ifindex, struct lacp_port_parameters *param)
{
	struct lacpd_port *port;

	if (!lacp || (port_num == 0) || (dev_ifindex == 0)) {
		DP(LACP, CRIT, "Arguments are invalid");
		return NULL;
	}

	port = (struct lacpd_port *)calloc(1, sizeof(struct lacpd_port));
	if (!port) {
		DP(LACP, CRIT, "Allocate lacpd_port failed");
		return NULL;
	}

	port->lacp = lacp;
	port->dev_ifindex = dev_ifindex;
	if (!port->lacp->out_api->get_dev_mac_addr(port->lacp->out_api, port->dev_ifindex, port->mac)) {
		DP(LACP, CRIT, "Get MAC address of port failed");
		goto new_port_failed;
	}

	port->lacpdu_indicate = false;

	lacpd_port_initialize_manageable_variable(port, port_num, param);
	lacpd_port_initialize_runtime_variable(port);

	fsm_runner_init(&port->runner, port->lacp->out_api->os_service);

	if (!fsm_runner_add_state_machine(&port->runner, lacpd_fsm_receive_new(port))) {
		goto new_port_failed;
	}

	if (!fsm_runner_add_state_machine(&port->runner, lacpd_fsm_periodic_transmission_new(port))) {
		goto new_port_failed;
	}

	if (!fsm_runner_add_state_machine(&port->runner, lacpd_fsm_selection_logic_new(port))) {
		goto new_port_failed;
	}

	if (!fsm_runner_add_state_machine(&port->runner, lacpd_fsm_mux_new(port))) {
		goto new_port_failed;
	}

	if (!fsm_runner_add_state_machine(&port->runner, lacpd_fsm_transmit_new(port))) {
		goto new_port_failed;
	}

	return port;

new_port_failed:
	fsm_runner_cleanup(&port->runner);

	free(port);

	return NULL;
}

/*
 * lacpd_port_destroy: stop all state machines of port, delete it from its attached aggregator, free it
 */
void lacpd_port_destroy(struct lacpd_port *port)
{
	struct lacpd_aggregator *agg;

	if (!port) {
		DP(LACP, CRIT, "Arguments are invalid");
		return;
	}

	fsm_runner_cleanup(&port->runner);

	agg = lacpd_aggregator_lookup(port->lacp, lacpd_aggregator_selector_by_id, (void *)port->actor_port_aggregator_identifier);
	if (agg) {
		lacpd_aggregator_detach_port(agg, port);
		lacpd_aggregator_del_port(agg, port);
	}

	free(port);
}
