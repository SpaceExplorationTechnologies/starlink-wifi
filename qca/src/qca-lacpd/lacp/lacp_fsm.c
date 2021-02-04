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
#include "lacpdu.h"
#include "lacp.h"
#include "lacp_fsm.h"
#include "port.h"
#include "aggregator.h"

static bool lacpd_fsm_select_aggregator_by_port(struct lacpd_aggregator *agg, void *arg)
{
	struct lacpd_port *port = (struct lacpd_port *)arg;

	return !agg->is_free && !agg->individual_aggregator && (port->actor_port_info.key == agg->actor_oper_aggregator_key) &&
		(port->partner_port_info.system_priority == agg->partner_system_priority) && mac_addr_euqal(port->partner_port_info.system, agg->partner_system) &&
		(port->partner_port_info.key == agg->partner_oper_aggregator_key);
}

static bool lacpd_fsm_select_aggregator_by_slave_dev(struct lacpd_aggregator *agg, void *arg)
{
	if ((agg->dev_ifindex == 0) || ((uint32_t)arg == 0)) {
		/*
		 * dev ifindex is invalid
		 */
		return false;
	}

	return agg->lacp->out_api->is_slave(agg->lacp->out_api, (uint32_t)arg, agg->dev_ifindex);
}

static void lacpd_fsm_print_lacpdu(struct lacpd_port *port, struct lacpdu *pkt, bool recv)
{
	char dev_name[LACP_NAME_SIZE];
	struct lacpd_port_info info;
	int idx;

	if (!(debug_mask[DBG_MOD_LACP_PKT] >= DBG_LEVEL_INFO)) {
		return;
	}

	if (!port->lacp->out_api->get_dev_name(port->lacp->out_api, port->dev_ifindex, dev_name)) {
		snprintf(dev_name, sizeof(dev_name), "Unknown device");
	}

	fprintf(stderr, "\nLACPDU %s port %s\n", (recv ? "received from" : "sent to"), dev_name);

	for (idx = 0; idx < 2; idx++) {
		lacpdu_get_port_info(&info, pkt, (idx == 0));
		fprintf(stderr, "%s system: %02x:%02x:%02x:%02x:%02x:%02x\n", ((idx == 0)? "Actor" : "Partner"),
				info.system[0], info.system[1], info.system[2],
				info.system[3], info.system[4], info.system[5]);
		fprintf(stderr, "%s port: %d\n", ((idx == 0)? "Actor" : "Partner"), info.port);
		fprintf(stderr, "%s state: %s %s %s %s %s %s %s %s\n", ((idx == 0)? "Actor" : "Partner"),
				(info.state.activity ? "activity" : ""),
				(info.state.timeout ? "timeout" : ""),
				(info.state.aggregation ? "aggregation" : ""),
				(info.state.synchronization ? "synchronization" : ""),
				(info.state.collecting ? "collecting" : ""),
				(info.state.distributing ? "distributing" : ""),
				(info.state.defaulted ? "defaulted" : ""),
				(info.state.expired ? "expired" : ""));
	}
}

/*
 * lacpd_fsm_receive_current_while_timer_cb : callback of current while timer
 */
static void lacpd_fsm_receive_current_while_timer_cb(struct genl_os_service_timer *t)
{
	struct lacpd_state_machine_receive *lacp_st= container_of(t, struct lacpd_state_machine_receive, current_while_timer);
	struct state_machine *st = &lacp_st->base;
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	/*
	 * Schedule a new running for all state machines of port
	 */
	lacpd_port_fsm_schedule_run(port);
}

/*
 * lacpd_fsm_receive_cond_to_INITIALIZE : condition to enter 'INITIALIZE' state of receive state machine
 */
static bool lacpd_fsm_receive_cond_to_INITIALIZE(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	return (st->state == LACPD_RECV_ST_PORT_DISABLED) && port->port_moved;
}

/*
 * lacpd_fsm_receive_cond_to_PORT_DISABLED : condition to enter 'PORT_DISABLED' state of receive state machine
 */
static bool lacpd_fsm_receive_cond_to_PORT_DISABLED(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	return (st->state == LACPD_RECV_ST_INITIALIZE) || ((st->state != LACPD_RECV_ST_PORT_DISABLED) && !port->port_enabled && !port->port_moved);
}

/*
 * lacpd_fsm_receive_cond_to_EXPIRED : condition to enter 'EXPIRED' state of receive state machine
 */
static bool lacpd_fsm_receive_cond_to_EXPIRED(struct state_machine *st)
{
	struct lacpd_state_machine_receive *lacp_st= container_of(st, struct lacpd_state_machine_receive, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	bool from_PORT_DISABLED_to_EXPIRED = (st->state == LACPD_RECV_ST_PORT_DISABLED) && port->port_enabled && port->lacp_enabled;
	bool from_CURRENT_to_EXPIRED = (st->state == LACPD_RECV_ST_CURRENT) && !lacp_st->current_while_timer.pending;

	return from_PORT_DISABLED_to_EXPIRED || from_CURRENT_to_EXPIRED;
}

/*
 * lacpd_fsm_receive_cond_to_LACP_DISABLED : condition to enter 'LACP_DISABLED' state of receive state machine
 */
static bool lacpd_fsm_receive_cond_to_LACP_DISABLED(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	return (st->state == LACPD_RECV_ST_PORT_DISABLED) && port->port_enabled && !port->lacp_enabled;
}

/*
 * lacpd_fsm_receive_cond_to_DEFAULTED : condition to enter 'DEFAULTED' state of receive state machine
 */
static bool lacpd_fsm_receive_cond_to_DEFAULTED(struct state_machine *st)
{
	struct lacpd_state_machine_receive *lacp_st= container_of(st, struct lacpd_state_machine_receive, base);

	return (st->state == LACPD_RECV_ST_EXPIRED) && !lacp_st->current_while_timer.pending;
}

/*
 * lacpd_fsm_receive_cond_to_CURRENT : condition to enter 'CURRENT' state of receive state machine
 */
static bool lacpd_fsm_receive_cond_to_CURRENT(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	if (port->lacpdu_indicate) {
		if (!lacpdu_validate(port->message)) {
			memset(port->message, 0, sizeof(port->message));
			port->lacpdu_indicate = false;
			++port->rx_error;
		} else {
			++port->rx_successes;
		}
	}

	return port->lacpdu_indicate && ((st->state == LACPD_RECV_ST_EXPIRED) || (st->state == LACPD_RECV_ST_DEFAULTED) || (st->state == LACPD_RECV_ST_CURRENT));
}

/*
 * lacpd_fsm_receive_act_INITIALIZE_set : (1/2)actions to take when enter 'INITIALIZE' state of receive state machine
 */
static void lacpd_fsm_receive_act_INITIALIZE_set(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->selected = LACPD_SEL_STATE_UNSELECTED;
	port->actor_port_info.state.expired = false;
	port->port_moved = false;
}

/*
 * lacpd_fsm_receive_act_record_default : (2/2)actions to take when enter 'INITIALIZE' state of receive state machine
 */
static void lacpd_fsm_receive_act_record_default(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->partner_port_info = port->partner_admin_port_info;
	port->actor_port_info.state.defaulted = true;
}

/*
 * lacpd_fsm_receive_act_PORT_DISABLED_set : (1/1)actions to take when enter 'PORT_DISABLED' state of receive state machine
 */
static void lacpd_fsm_receive_act_PORT_DISABLED_set(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->partner_port_info.state.synchronization = false;
}

/*
 * lacpd_fsm_receive_act_EXPIRED_set : (1/1)actions to take when enter 'EXPIRED' state of receive state machine
 */
static void lacpd_fsm_receive_act_EXPIRED_set(struct state_machine *st)
{
	struct lacpd_state_machine_receive *lacp_st= container_of(st, struct lacpd_state_machine_receive, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->partner_port_info.state.synchronization = false;
	/*
	 * We can only set peer's timeout as short timeout because we lost peer's information
	 */
	port->partner_port_info.state.timeout = true;
	port->lacp->out_api->os_service->timer_set(&lacp_st->current_while_timer, LACP_SHORT_TIMEOUT_TIME);
	port->actor_port_info.state.expired = true;
}

/*
 * lacpd_fsm_receive_act_LACP_DISABLED_set : (1/2)actions to take when enter 'LACP_DISABLED' state of receive state machine
 *					see 'lacpd_fsm_receive_act_record_default' for (2/2)actions
 */
static void lacpd_fsm_receive_act_LACP_DISABLED_set(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->selected = LACPD_SEL_STATE_UNSELECTED;
	port->partner_port_info.state.aggregation = false;
	port->actor_port_info.state.expired = false;
}

/*
 * lacpd_fsm_receive_act_update_default_selected : (1/3)actions to take when enter 'DEFAULTED' state of receive state machine
 *						see 'lacpd_fsm_receive_act_record_default' for (2/3)actions
 */
static void lacpd_fsm_receive_act_update_default_selected(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	uint32_t ignore_mask = ignore_all_states_except(aggregation);
	if (!port_info_equal(&port->partner_admin_port_info, &port->partner_port_info, ignore_mask)) {
		port->selected = LACPD_SEL_STATE_UNSELECTED;
	}
}

/*
 * lacpd_fsm_receive_act_DEFAULTED_set : (3/3)actions to take when enter 'DEFAULTED' state of receive state machine
 */
static void lacpd_fsm_receive_act_DEFAULTED_set(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->actor_port_info.state.expired = false;
}

/*
 * lacpd_fsm_receive_act_dump_pkt : (1/5)actions to take when enter 'CURRENT' state of receive state machine
 */
static void lacpd_fsm_receive_act_dump_pkt(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	lacpd_fsm_print_lacpdu(port, port->message, true);
}

/*
 * lacpd_fsm_receive_act_update_selected : (2/5)actions to take when enter 'CURRENT' state of receive state machine
 */
static void lacpd_fsm_receive_act_update_selected(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	uint32_t ignore_mask = ignore_all_states_except(aggregation);

	struct lacpd_port_info remote_actor;
	lacpdu_get_port_info(&remote_actor, port->message, true);

	if (!port_info_equal(&remote_actor, &port->partner_port_info, ignore_mask)) {
		port->selected = LACPD_SEL_STATE_UNSELECTED;
	}
}

/*
 * lacpd_fsm_receive_act_update_NTT : (3/5)actions to take when enter 'CURRENT' state of receive state machine
 */
static void lacpd_fsm_receive_act_update_NTT(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	uint32_t ignore_mask = ignore_states(collecting, distributing, defaulted, expired);

	struct lacpd_port_info remote_partner;
	lacpdu_get_port_info(&remote_partner, port->message, false);

	if (!port_info_equal(&remote_partner, &port->actor_port_info, ignore_mask)) {
		port->ntt = true;
	}
}

/*
 * lacpd_fsm_receive_act_record_PDU : (4/5)actions to take when enter 'CURRENT' state of receive state machine
 */
static void lacpd_fsm_receive_act_record_PDU(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	lacpdu_get_port_info(&port->partner_port_info, port->message, true);
	port->actor_port_info.state.defaulted = false;

	if (!port->partner_port_info.state.synchronization) {
		return;
	}

	struct lacpd_port_info remote_partner;
	lacpdu_get_port_info(&remote_partner, port->message, false);

	/* Link is actively if local or peer is actively*/
	bool lacp_is_actively = port->partner_port_info.state.activity || (port->actor_port_info.state.activity && remote_partner.state.activity);
	/* I think peer can not be in synchronization state if link is actively*/
	if (!lacp_is_actively) {
		port->partner_port_info.state.synchronization = false;
		return;
	}

	uint32_t ignore_mask = ignore_all_states_except(aggregation);

	/*Peer has wrong information about me, so he can not be in synchronization state*/
	if (port->partner_port_info.state.aggregation && !port_info_equal(&remote_partner, &port->actor_port_info, ignore_mask)) {
		port->partner_port_info.state.synchronization = false;
	}
}

/*
 * lacpd_fsm_receive_act_CURRENT_set : (5/5)actions to take when enter 'CURRENT' state of receive state machine
 */
static void lacpd_fsm_receive_act_CURRENT_set(struct state_machine *st)
{
	struct lacpd_state_machine_receive *lacp_st= container_of(st, struct lacpd_state_machine_receive, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->lacp->out_api->os_service->timer_set(&lacp_st->current_while_timer, ((port->actor_port_info.state.timeout)? LACP_SHORT_TIMEOUT_TIME : LACP_LONG_TIMEOUT_TIME));
	port->actor_port_info.state.expired = false;
	memset(port->message, 0, sizeof(port->message));
	port->lacpdu_indicate = false;
}

/*
 * lacpd_fsm_receive_destroy : destroy lacp receive state machine of lacp port
 */
static void lacpd_fsm_receive_destroy(struct state_machine *st)
{
	struct lacpd_state_machine_receive *lacp_st= container_of(st, struct lacpd_state_machine_receive, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->lacp->out_api->os_service->timer_cancel(&lacp_st->current_while_timer);
	free(lacp_st);
}

/*
 * lacp receive state machine for lacp port
 */
static struct state_machine_base receive_machine_base = {
	.name = "lacp receive state machine",
	.id = LACPD_PORT_STATE_MACHINE_RECEIVE,
	.initial_state = LACPD_RECV_ST_INITIALIZE,
	.max_state = LACPD_RECV_ST_MAX,
	.states = {
		{
			.name = "INITIALIZE",
			.condition = lacpd_fsm_receive_cond_to_INITIALIZE,
			.actions = {lacpd_fsm_receive_act_INITIALIZE_set, lacpd_fsm_receive_act_record_default}
		},
		{
			.name = "PORT_DISABLED",
			.condition = lacpd_fsm_receive_cond_to_PORT_DISABLED,
			.actions = {lacpd_fsm_receive_act_PORT_DISABLED_set}
		},
		{
			.name = "EXPIRED",
			.condition = lacpd_fsm_receive_cond_to_EXPIRED,
			.actions = {lacpd_fsm_receive_act_EXPIRED_set}
		},
		{
			.name = "LACP_DISABLED",
			.condition = lacpd_fsm_receive_cond_to_LACP_DISABLED,
			.actions = {lacpd_fsm_receive_act_LACP_DISABLED_set, lacpd_fsm_receive_act_record_default}
		},
		{
			.name = "DEFAULTED",
			.condition = lacpd_fsm_receive_cond_to_DEFAULTED,
			.actions = {lacpd_fsm_receive_act_update_default_selected, lacpd_fsm_receive_act_record_default, lacpd_fsm_receive_act_DEFAULTED_set}
		},
		{
			.name = "CURRENT",
			.condition = lacpd_fsm_receive_cond_to_CURRENT,
			.actions = {lacpd_fsm_receive_act_dump_pkt, lacpd_fsm_receive_act_update_selected, lacpd_fsm_receive_act_update_NTT,
				    lacpd_fsm_receive_act_record_PDU, lacpd_fsm_receive_act_CURRENT_set}
		},
	},
	.destroy = lacpd_fsm_receive_destroy
};

/*
 * lacpd_fsm_receive_new : Create lacp receive state machine for lacp port
 */
struct state_machine *
lacpd_fsm_receive_new(struct lacpd_port *port)
{
	struct lacpd_state_machine_receive *st;

	/*
	 * Super class init start
	 */
	st = (struct lacpd_state_machine_receive *)calloc(1, sizeof(struct lacpd_state_machine_receive));
	if (!st) {
		DP(LACP, CRIT, "Allocate lacpd_state_machine_receive failed");
		return NULL;
	}

	st->base.base = &receive_machine_base;
	st->base.master = (void *)port;
	/*
	 * Super class init end
	 */
	/*
	 * Sub class init start
	 */
	st->current_while_timer.cb = lacpd_fsm_receive_current_while_timer_cb;
	/*
	 * Sub class init end
	 */

	return &st->base;
}

/*
 * lacpd_fsm_periodic_transmission_timer_cb : callback of periodic timer
 */
static void lacpd_fsm_periodic_transmission_timer_cb(struct genl_os_service_timer *t)
{
	struct lacpd_state_machine_periodic_transmission *lacp_st= container_of(t, struct lacpd_state_machine_periodic_transmission, periodic_timer);
	struct state_machine *st = &lacp_st->base;
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	/*
	 * Schedule a new running for all state machines of port
	 */
	lacpd_port_fsm_schedule_run(port);
}

/*
 * lacpd_fsm_periodic_transmission_cond_to_NO_PERIODIC : condition to enter 'NO_PERIODIC' state of periodic transmission state machine
 */
static bool lacpd_fsm_periodic_transmission_cond_to_NO_PERIODIC(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	bool to_enter_NO_PERIODIC = !port->lacp_enabled || !port->port_enabled || (!port->actor_port_info.state.activity && !port->partner_port_info.state.activity);
	return st->state != LACPD_PERIODIC_ST_NO_PERIODIC && to_enter_NO_PERIODIC;
}

/*
 * lacpd_fsm_periodic_transmission_cond_to_FAST_PERIODIC : condition to enter 'FAST_PERIODIC' state of periodic transmission state machine
 */
static bool lacpd_fsm_periodic_transmission_cond_to_FAST_PERIODIC(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	bool to_enter_NO_PERIODIC = !port->lacp_enabled || !port->port_enabled || (!port->actor_port_info.state.activity && !port->partner_port_info.state.activity);
	bool from_NO_PERIODIC_to_FAST_PERIODIC = st->state == LACPD_PERIODIC_ST_NO_PERIODIC && !to_enter_NO_PERIODIC;
	return from_NO_PERIODIC_to_FAST_PERIODIC || ((st->state == LACPD_PERIODIC_ST_PERIODIC_TX) && port->partner_port_info.state.timeout);
}

/*
 * lacpd_fsm_periodic_transmission_cond_to_SLOW_PERIODIC : condition to enter 'SLOW_PERIODIC' state of periodic transmission state machine
 */
static bool lacpd_fsm_periodic_transmission_cond_to_SLOW_PERIODIC(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	return ((st->state == LACPD_PERIODIC_ST_PERIODIC_TX) && !port->partner_port_info.state.timeout) ||
		((st->state == LACPD_PERIODIC_ST_FAST_PERIODIC) && !port->partner_port_info.state.timeout);
}

/*
 * lacpd_fsm_periodic_transmission_cond_to_PERIODIC_TX : condition to enter 'PERIODIC_TX' state of periodic transmission state machine
 */
static bool lacpd_fsm_periodic_transmission_cond_to_PERIODIC_TX(struct state_machine *st)
{
	struct lacpd_state_machine_periodic_transmission *lacp_st= container_of(st, struct lacpd_state_machine_periodic_transmission, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	bool from_FAST_PERIODIC_to_PERIODIC_TX = ((st->state == LACPD_PERIODIC_ST_FAST_PERIODIC) && !lacp_st->periodic_timer.pending);
	bool from_SLOW_PERIODIC_to_PERIODIC_TX = ((st->state == LACPD_PERIODIC_ST_SLOW_PERIODIC) && (!lacp_st->periodic_timer.pending || port->partner_port_info.state.timeout));
	return from_FAST_PERIODIC_to_PERIODIC_TX || from_SLOW_PERIODIC_to_PERIODIC_TX;
}

/*
 * lacpd_fsm_periodic_transmission_act_NO_PERIODIC_set : (1/1)actions to take when enter 'NO_PERIODIC' state of periodic transmission state machine
 */
static void lacpd_fsm_periodic_transmission_act_NO_PERIODIC_set(struct state_machine *st)
{
	struct lacpd_state_machine_periodic_transmission *lacp_st= container_of(st, struct lacpd_state_machine_periodic_transmission, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->lacp->out_api->os_service->timer_cancel(&lacp_st->periodic_timer);
}

/*
 * lacpd_fsm_periodic_transmission_act_FAST_PERIODIC_set : (1/1)actions to take when enter 'FAST_PERIODIC' state of periodic transmission state machine
 */
static void lacpd_fsm_periodic_transmission_act_FAST_PERIODIC_set(struct state_machine *st)
{
	struct lacpd_state_machine_periodic_transmission *lacp_st= container_of(st, struct lacpd_state_machine_periodic_transmission, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->lacp->out_api->os_service->timer_set(&lacp_st->periodic_timer, LACP_FAST_PERIODIC_TIME);
}

/*
 * lacpd_fsm_periodic_transmission_act_SLOW_PERIODIC_set : (1/1)actions to take when enter 'SLOW_PERIODIC' state of periodic transmission state machine
 */
static void lacpd_fsm_periodic_transmission_act_SLOW_PERIODIC_set(struct state_machine *st)
{
	struct lacpd_state_machine_periodic_transmission *lacp_st= container_of(st, struct lacpd_state_machine_periodic_transmission, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->lacp->out_api->os_service->timer_set(&lacp_st->periodic_timer, LACP_SLOW_PERIODIC_TIME);
}

/*
 * lacpd_fsm_periodic_transmission_act_PERIODIC_TX_set : (1/1)actions to take when enter 'PERIODIC_TX' state of periodic transmission state machine
 */
static void lacpd_fsm_periodic_transmission_act_PERIODIC_TX_set(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->ntt = true;
}

/*
 * lacpd_fsm_periodic_transmission_destroy : destroy lacp periodic transmission state machine of lacp port
 */
static void lacpd_fsm_periodic_transmission_destroy(struct state_machine *st)
{
	struct lacpd_state_machine_periodic_transmission *lacp_st= container_of(st, struct lacpd_state_machine_periodic_transmission, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->lacp->out_api->os_service->timer_cancel(&lacp_st->periodic_timer);
	free(lacp_st);
}

/*
 * lacp mux state machine for lacp port
 */
static struct state_machine_base periodic_transmit_machine_base = {
	.name = "lacp periodic transmission state machine",
	.id = LACPD_PORT_STATE_MACHINE_PERIODIC,
	.initial_state = LACPD_PERIODIC_ST_NO_PERIODIC,
	.max_state = LACPD_PERIODIC_ST_MAX,
	.states = {
		{
			.name = "NO_PERIODIC",
			.condition = lacpd_fsm_periodic_transmission_cond_to_NO_PERIODIC,
			.actions = {lacpd_fsm_periodic_transmission_act_NO_PERIODIC_set}
		},
		{
			.name = "FAST_PERIODIC",
			.condition = lacpd_fsm_periodic_transmission_cond_to_FAST_PERIODIC,
			.actions = {lacpd_fsm_periodic_transmission_act_FAST_PERIODIC_set}
		},
		{
			.name = "SLOW_PERIODIC",
			.condition = lacpd_fsm_periodic_transmission_cond_to_SLOW_PERIODIC,
			.actions = {lacpd_fsm_periodic_transmission_act_SLOW_PERIODIC_set}
		},
		{
			.name = "PERIODIC_TX",
			.condition = lacpd_fsm_periodic_transmission_cond_to_PERIODIC_TX,
			.actions = {lacpd_fsm_periodic_transmission_act_PERIODIC_TX_set}
		},
	},
	.destroy = lacpd_fsm_periodic_transmission_destroy
};

/*
 * lacpd_fsm_periodic_transmission_new : Create lacp periodic transmission state machine for lacp port
 */
struct state_machine *
lacpd_fsm_periodic_transmission_new(struct lacpd_port *port)
{
	struct lacpd_state_machine_periodic_transmission *st;

	/*
	 * Super class init start
	 */
	st = (struct lacpd_state_machine_periodic_transmission *)calloc(1, sizeof(struct lacpd_state_machine_periodic_transmission));
	if (!st) {
		DP(LACP, CRIT, "Allocate lacpd_state_machine_periodic_transmission failed");
		return NULL;
	}

	st->base.base = &periodic_transmit_machine_base;
	st->base.master = (void *)port;
	/*
	 * Super class init end
	 */
	/*
	 * Sub class init start
	 */
	st->periodic_timer.cb = lacpd_fsm_periodic_transmission_timer_cb;
	/*
	 * Sub class init end
	 */

	return &st->base;
}

/*
 * lacpd_fsm_selection_logic_cond_to_UNSELECTED : condition to enter 'UNSELECTED' state of selection logic state machine
 */
static bool lacpd_fsm_selection_logic_cond_to_UNSELECTED(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	return (st->state == LACPD_SELECT_LOGIC_ST_SELECTED) && (port->selected != LACPD_SEL_STATE_SELECTED);
}

/*
 * lacpd_fsm_selection_logic_cond_to_SELECTED : condition to enter 'SELECTED' state of selection logic state machine
 */
static bool lacpd_fsm_selection_logic_cond_to_SELECTED(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;
	struct state_machine *mux_st = lacpd_port_state_machine_get(port, LACPD_PORT_STATE_MACHINE_MUX);

	if (!mux_st) {
		return false;
	}

	return (st->state == LACPD_SELECT_LOGIC_ST_UNSELECTED) && (mux_st->state == LACPD_MUX_ST_DETACHED);
}

/*
 * lacpd_fsm_selection_logic_act_remove_from_aggregator : (1/1)actions to take when enter 'UNSELECTED' state of selection logic state machine
 */
static void lacpd_fsm_selection_logic_act_remove_from_aggregator(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;
	struct lacpd_aggregator *selected_agg;

	if (!port->actor_port_aggregator_identifier) {
		return;
	}

	selected_agg = lacpd_aggregator_lookup(port->lacp, lacpd_aggregator_selector_by_id, (void *)port->actor_port_aggregator_identifier);
	if (selected_agg) {
		lacpd_aggregator_del_port(selected_agg, port);
	}

	port->actor_port_aggregator_identifier = 0;
}

/*
 * lacpd_fsm_selection_logic_act_add_to_aggregator : (1/1)actions to take when enter 'SELECTED' state of selection logic state machine
 */
static void lacpd_fsm_selection_logic_act_add_to_aggregator(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;
	struct lacpd_aggregator *selected_agg = NULL;

	if (port->actor_port_info.state.aggregation && !mac_addr_is_empty(port->partner_port_info.system) && port->partner_port_info.state.aggregation) {
		selected_agg = lacpd_aggregator_lookup(port->lacp, lacpd_fsm_select_aggregator_by_port, (void *)port);
	}

	/*Select a free aggregator if port can not be added into any existing aggregator*/
	if (!selected_agg) {
		selected_agg = lacpd_aggregator_lookup(port->lacp, lacpd_aggregator_selector_by_free, NULL);
	}

	if (!selected_agg) {
		DP(LACP, CRIT, "Error: no free aggregator available for port");
		return;
	}

	if (lacpd_aggregator_add_port(selected_agg, port)) {
		port->actor_port_aggregator_identifier = selected_agg->aggregator_identifier;
		port->selected = LACPD_SEL_STATE_SELECTED;
	}
}

/*
 * lacpd_fsm_selection_logic_destroy : destroy lacp selection logic state machine of lacp port
 */
static void lacpd_fsm_selection_logic_destroy(struct state_machine *st)
{
	struct lacpd_state_machine_selection_logic *lacp_st= container_of(st, struct lacpd_state_machine_selection_logic, base);

	free(lacp_st);
}

/*
 * lacp selection state machine for lacp port
 */
static struct state_machine_base selection_machine_base = {
	.name = "lacp selection logic state machine",
	.id = LACPD_PORT_STATE_MACHINE_SELECT,
	.initial_state = LACPD_SELECT_LOGIC_ST_UNSELECTED,
	.max_state = LACPD_SELECT_LOGIC_ST_MAX,
	.states = {
		{
			.name = "UNSELECTED",
			.condition = lacpd_fsm_selection_logic_cond_to_UNSELECTED,
			.actions = {lacpd_fsm_selection_logic_act_remove_from_aggregator}
		},
		{
			.name = "SELECTED",
			.condition = lacpd_fsm_selection_logic_cond_to_SELECTED,
			.actions = {lacpd_fsm_selection_logic_act_add_to_aggregator}
		},
	},
	.destroy = lacpd_fsm_selection_logic_destroy
};

/*
 * lacpd_fsm_selection_logic_new : Create lacp selection logic state machine for lacp port
 */
struct state_machine *
lacpd_fsm_selection_logic_new(struct lacpd_port *port)
{
	struct lacpd_state_machine_selection_logic *st;

	/*
	 * Super class init start
	 */
	st = (struct lacpd_state_machine_selection_logic *)calloc(1, sizeof(struct lacpd_state_machine_selection_logic));
	if (!st) {
		DP(LACP, CRIT, "Allocate lacpd_state_machine_selection_logic failed");
		return NULL;
	}

	st->base.base = &selection_machine_base;
	st->base.master = (void *)port;
	/*
	 * Super class init end
	 */
	/*
	 * Sub class init start
	 */

	/*
	 * Sub class init end
	 */

	return &st->base;
}

/*
 * lacpd_fsm_mux_wait_while_timer_cb : callback of wait while timer
 */
static void lacpd_fsm_mux_wait_while_timer_cb(struct genl_os_service_timer *t)
{
	struct lacpd_state_machine_mux *lacp_st= container_of(t, struct lacpd_state_machine_mux, wait_while_timer);
	struct state_machine *st = &lacp_st->base;
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	/*
	 * To avoid race condition
	 */
	if (st->state != LACPD_MUX_ST_WAITING) {
		return;
	}

	struct lacpd_aggregator *selected_agg = lacpd_aggregator_lookup(port->lacp, lacpd_aggregator_selector_by_id, (void *)port->actor_port_aggregator_identifier);
	if (!selected_agg) {
		return;
	}

	port->ready_N = true;
	lacpd_aggregator_update_ready(selected_agg);

	/*
	 * Schedule a new running for all state machines of port
	 */
	lacpd_port_fsm_schedule_run(port);
}

/*
 * lacpd_fsm_mux_cond_to_DETACHED : condition to enter 'DETACHED' state of mux state machine
 */
static bool lacpd_fsm_mux_cond_to_DETACHED(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	return (st->state == LACPD_MUX_ST_WAITING || st->state == LACPD_MUX_ST_ATTACHED) && port->selected == LACPD_SEL_STATE_UNSELECTED;
}

/*
 * lacpd_fsm_mux_cond_to_WAITING : condition to enter 'WAITING' state of mux state machine
 */
static bool lacpd_fsm_mux_cond_to_WAITING(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	return st->state == LACPD_MUX_ST_DETACHED && port->selected == LACPD_SEL_STATE_SELECTED;
}

/*
 * lacpd_fsm_mux_cond_to_ATTACHED : condition to enter 'ATTACHED' state of mux state machine
 */
static bool lacpd_fsm_mux_cond_to_ATTACHED(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	bool from_WAITING_to_ATTACHED = false;

	struct lacpd_aggregator *selected_agg = lacpd_aggregator_lookup(port->lacp, lacpd_aggregator_selector_by_id, (void *)port->actor_port_aggregator_identifier);
	if (selected_agg) {
		from_WAITING_to_ATTACHED = (st->state == LACPD_MUX_ST_WAITING && port->selected == LACPD_SEL_STATE_SELECTED && selected_agg->ready);
	}

	bool from_COLLECTING_DISTRIBUTING_to_ATTACHED = (st->state == LACPD_MUX_ST_COLLECTING_DISTRIBUTING &&
							    (port->selected == LACPD_SEL_STATE_UNSELECTED || !port->partner_port_info.state.synchronization));

	return from_WAITING_to_ATTACHED || from_COLLECTING_DISTRIBUTING_to_ATTACHED;
}

/*
 * lacpd_fsm_mux_cond_to_COLLECTING_DISTRIBUTING : condition to enter 'COLLECTING_DISTRIBUTING' state of mux state machine
 */
static bool lacpd_fsm_mux_cond_to_COLLECTING_DISTRIBUTING(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	return st->state == LACPD_MUX_ST_ATTACHED && port->selected == LACPD_SEL_STATE_SELECTED && port->partner_port_info.state.synchronization;
}

/*
 * lacpd_fsm_mux_act_detach_mux_from_aggregator : (1/3)actions to take when enter 'DETACHED' state of mux state machine
 */
static void lacpd_fsm_mux_act_detach_mux_from_aggregator(struct state_machine *st)
{
	/*Empty: nothing to do*/
}

/*
 * lacpd_fsm_mux_act_disable_collecting_distributing : (2/3)actions to take when enter 'DETACHED' state of mux state machine
 */
static void lacpd_fsm_mux_act_disable_collecting_distributing(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	struct lacpd_aggregator *selected_agg = lacpd_aggregator_lookup(port->lacp, lacpd_fsm_select_aggregator_by_slave_dev, (void *)port->dev_ifindex);
	if (!selected_agg) {
		return;
	}

	lacpd_aggregator_detach_port(selected_agg, port);
}

/*
 * lacpd_fsm_mux_act_DETACHED_set : (3/3)actions to take when enter 'DETACHED' state of mux state machine
 */
static void lacpd_fsm_mux_act_DETACHED_set(struct state_machine *st)
{
	struct lacpd_state_machine_mux *lacp_st= container_of(st, struct lacpd_state_machine_mux, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->actor_port_info.state.synchronization = false;
	port->actor_port_info.state.collecting = false;
	port->actor_port_info.state.distributing = false;
	port->ntt = true;
	port->ready_N = false;
	port->lacp->out_api->os_service->timer_cancel(&lacp_st->wait_while_timer);
}

/*
 * lacpd_fsm_mux_act_WAITING_set : (1/1)actions to take when enter 'WAITING' state of mux state machine
 */
static void lacpd_fsm_mux_act_WAITING_set(struct state_machine *st)
{
	struct lacpd_state_machine_mux *lacp_st= container_of(st, struct lacpd_state_machine_mux, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->lacp->out_api->os_service->timer_set(&lacp_st->wait_while_timer, LACP_AGGREGATE_WAIT_TIME);
}

/*
 * lacpd_fsm_mux_act_attach_mux_to_aggregator : (1/3)actions to take when enter 'ATTACHED' state of mux state machine
 *						(2/3)actions: lacpd_fsm_mux_act_disable_collecting_distributing
 */
static void lacpd_fsm_mux_act_attach_mux_to_aggregator(struct state_machine *st)
{
	/*Empty: nothing to do*/
}

/*
 * lacpd_fsm_mux_act_ATTACHED_set : (3/3)actions to take when enter 'ATTACHED' state of mux state machine
 */
static void lacpd_fsm_mux_act_ATTACHED_set(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->actor_port_info.state.synchronization = true;
	port->actor_port_info.state.collecting = false;
	port->actor_port_info.state.distributing = false;
	port->ntt = true;
}

/*
 * lacpd_fsm_mux_act_enable_collecting_distributing : (1/2)actions to take when enter 'COLLECTING_DISTRIBUTING' state of mux state machine
 */
static void lacpd_fsm_mux_act_enable_collecting_distributing(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	struct lacpd_aggregator *selected_agg = lacpd_aggregator_lookup(port->lacp, lacpd_aggregator_selector_by_id, (void *)port->actor_port_aggregator_identifier);
	if (!selected_agg) {
		return;
	}

	lacpd_aggregator_attach_port(selected_agg, port);
}

/*
 * lacpd_fsm_mux_act_COLLECTING_DISTRIBUTING_set : (1/2)actions to take when enter 'COLLECTING_DISTRIBUTING' state of mux state machine
 */
static void lacpd_fsm_mux_act_COLLECTING_DISTRIBUTING_set(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->actor_port_info.state.collecting = true;
	port->actor_port_info.state.distributing = true;
	port->ntt = true;
}

/*
 * lacpd_fsm_mux_destroy : destroy lacp mux state machine of lacp port
 */
static void lacpd_fsm_mux_destroy(struct state_machine *st)
{
	struct lacpd_state_machine_mux *lacp_st= container_of(st, struct lacpd_state_machine_mux, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->lacp->out_api->os_service->timer_cancel(&lacp_st->wait_while_timer);
	free(lacp_st);
}

/*
 * lacp mux state machine for lacp port
 */
static struct state_machine_base mux_machine_base = {
	.name = "lacp mux state machine",
	.id = LACPD_PORT_STATE_MACHINE_MUX,
	.initial_state = LACPD_MUX_ST_DETACHED,
	.max_state = LACPD_MUX_ST_MAX,
	.states = {
		{
			.name = "DETACHED",
			.condition = lacpd_fsm_mux_cond_to_DETACHED,
			.actions = {lacpd_fsm_mux_act_detach_mux_from_aggregator, lacpd_fsm_mux_act_disable_collecting_distributing, lacpd_fsm_mux_act_DETACHED_set}
		},
		{
			.name = "WAITING",
			.condition = lacpd_fsm_mux_cond_to_WAITING,
			.actions = {lacpd_fsm_mux_act_WAITING_set}
		},
		{
			.name = "ATTACHED",
			.condition = lacpd_fsm_mux_cond_to_ATTACHED,
			.actions = {lacpd_fsm_mux_act_attach_mux_to_aggregator, lacpd_fsm_mux_act_disable_collecting_distributing, lacpd_fsm_mux_act_ATTACHED_set}
		},
		{
			.name = "COLLECTING_DISTRIBUTING",
			.condition = lacpd_fsm_mux_cond_to_COLLECTING_DISTRIBUTING,
			.actions = {lacpd_fsm_mux_act_enable_collecting_distributing, lacpd_fsm_mux_act_COLLECTING_DISTRIBUTING_set}
		},
	},
	.destroy = lacpd_fsm_mux_destroy
};

/*
 * lacpd_fsm_mux_new : Create lacp mux state machine for lacp port
 */
struct state_machine *
lacpd_fsm_mux_new(struct lacpd_port *port)
{
	struct lacpd_state_machine_mux *st;

	/*
	 * Super class init start
	 */
	st = (struct lacpd_state_machine_mux *)calloc(1, sizeof(struct lacpd_state_machine_mux));
	if (!st) {
		DP(LACP, CRIT, "Allocate lacpd_state_machine_mux failed");
		return NULL;
	}

	st->base.base = &mux_machine_base;
	st->base.master = (void *)port;
	/*
	 * Super class init end
	 */
	/*
	 * Sub class init start
	 */
	st->wait_while_timer.cb = lacpd_fsm_mux_wait_while_timer_cb;
	/*
	 * Sub class init end
	 */

	return &st->base;
}

/*
 * lacpd_fsm_transmit_rate_limit_timer_cb : callback of rate limit timer
 */
static void lacpd_fsm_transmit_rate_limit_timer_cb(struct genl_os_service_timer *t)
{
	struct lacpd_state_machine_transmit *lacp_st= container_of(t, struct lacpd_state_machine_transmit, rate_limit_timer);
	struct state_machine *st = &lacp_st->base;
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	lacp_st->pkt_sent = 0;
	port->lacp->out_api->os_service->timer_set(&lacp_st->rate_limit_timer, LACP_FAST_PERIODIC_TIME);

	/*
	 * Schedule a new running for all state machines of port
	 */
	lacpd_port_fsm_schedule_run(port);
}

/*
 * lacpd_fsm_transmit_rate_limit : check if we can send a lacpdu now
 */
static bool lacpd_fsm_transmit_rate_limit(struct lacpd_state_machine_transmit *st)
{
	return st->pkt_sent >= 3;
}

/*
 * lacpd_fsm_transmit_cond_to_NO_TX : condition to enter 'NO_TX' state of transmit state machine
 */
static bool lacpd_fsm_transmit_cond_to_NO_TX(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;
	struct state_machine *periodic_st = lacpd_port_state_machine_get(port, LACPD_PORT_STATE_MACHINE_PERIODIC);
	bool from_DISABLED_to_NO_TX;

	if (!periodic_st) {
		return false;
	}

	from_DISABLED_to_NO_TX = (st->state == LACPD_TRANSMIT_ST_DISABLED) &&
					(periodic_st->state != LACPD_PERIODIC_ST_NO_PERIODIC) &&
					port->lacp_enabled;
	return (st->state == LACPD_TRANSMIT_ST_TX) || from_DISABLED_to_NO_TX;
}

/*
 * lacpd_fsm_transmit_cond_to_TX : condition to enter 'TX' state of transmit state machine
 */
static bool lacpd_fsm_transmit_cond_to_TX(struct state_machine *st)
{
	struct lacpd_state_machine_transmit *lacp_st= container_of(st, struct lacpd_state_machine_transmit, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;
	struct state_machine *periodic_st = lacpd_port_state_machine_get(port, LACPD_PORT_STATE_MACHINE_PERIODIC);

	if (!periodic_st) {
		return false;
	}

	return (st->state == LACPD_TRANSMIT_ST_NO_TX) &&
		port->ntt &&
		(periodic_st->state != LACPD_PERIODIC_ST_NO_PERIODIC) &&
		port->lacp_enabled &&
		!lacpd_fsm_transmit_rate_limit(lacp_st);
}

/*
 * lacpd_fsm_transmit_cond_to_DISABLED : condition to enter 'DISABLED' state of transmit state machine
 */
static bool lacpd_fsm_transmit_cond_to_DISABLED(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;
	struct state_machine *periodic_st = lacpd_port_state_machine_get(port, LACPD_PORT_STATE_MACHINE_PERIODIC);

	if (!periodic_st) {
		return false;
	}

	return (st->state != LACPD_TRANSMIT_ST_DISABLED) &&
		((periodic_st->state == LACPD_PERIODIC_ST_NO_PERIODIC) || !port->lacp_enabled);
}

/*
 * lacpd_fsm_transmit_act_NO_TX_set : (1/1)actions to take when enter 'NO_TX' state of transmit state machine
 */
static void lacpd_fsm_transmit_act_NO_TX_set(struct state_machine *st)
{
	/*Nothing to do*/
}

/*
 * lacpd_fsm_transmit_act_send_lacpdu : (1/2)actions to take when enter 'TX' state of transmit state machine
 */
static void lacpd_fsm_transmit_act_send_lacpdu(struct state_machine *st)
{
	struct lacpd_state_machine_transmit *lacp_st= container_of(st, struct lacpd_state_machine_transmit, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;
	struct lacp_pkt pkt;

	lacpdu_init(&pkt);
	mac_addr_copy(pkt.eth.src_mac, port->mac);
	lacpdu_set_port_info(&port->actor_port_info, &pkt.lacp, true);
	lacpdu_set_port_info(&port->partner_port_info, &pkt.lacp, false);

	lacpd_fsm_print_lacpdu(port, &pkt.lacp, false);

	if (port->lacp->out_api->send_lacpdu(port->lacp->out_api, port->dev_ifindex, (uint8_t *)&pkt, sizeof(pkt))) {
		++port->tx_successes;
	} else {
		++port->tx_error;
	}

	lacp_st->pkt_sent += 1;
}

/*
 * lacpd_fsm_transmit_act_clear_NTT : (2/2)actions to take when enter 'TX' state of transmit state machine
 */
static void lacpd_fsm_transmit_act_clear_NTT(struct state_machine *st)
{
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->ntt = false;
}

/*
 * lacpd_fsm_transmit_destroy : destroy lacp transmit state machine of lacp port
 */
static void lacpd_fsm_transmit_destroy(struct state_machine *st)
{
	struct lacpd_state_machine_transmit *lacp_st= container_of(st, struct lacpd_state_machine_transmit, base);
	struct lacpd_port *port = (struct lacpd_port *)st->master;

	port->lacp->out_api->os_service->timer_cancel(&lacp_st->rate_limit_timer);
	free(lacp_st);
}

/*
 * lacp transmit state machine for lacp port
 */
static struct state_machine_base transmit_machine_base = {
	.name = "lacp transmit state machine",
	.id = LACPD_PORT_STATE_MACHINE_TRANSMIT,
	.initial_state = LACPD_TRANSMIT_ST_NO_TX,
	.max_state = LACPD_TRANSMIT_ST_MAX,
	.states = {
		{
			.name = "NO_TX",
			.condition = lacpd_fsm_transmit_cond_to_NO_TX,
			.actions = {lacpd_fsm_transmit_act_NO_TX_set}
		},
		{
			.name = "TX",
			.condition = lacpd_fsm_transmit_cond_to_TX,
			.actions = {lacpd_fsm_transmit_act_send_lacpdu, lacpd_fsm_transmit_act_clear_NTT}
		},
		{
			.name = "DISABLED",
			.condition = lacpd_fsm_transmit_cond_to_DISABLED,
			.actions = {lacpd_fsm_transmit_act_clear_NTT}
		},
	},
	.destroy = lacpd_fsm_transmit_destroy
};

/*
 * lacpd_fsm_transmit_new : Create lacp transmit state machine for lacp port
 */
struct state_machine *
lacpd_fsm_transmit_new(struct lacpd_port *port)
{
	struct lacpd_state_machine_transmit *st;

	/*
	 * Super class init start
	 */
	st = (struct lacpd_state_machine_transmit *)calloc(1, sizeof(struct lacpd_state_machine_transmit));
	if (!st) {
		DP(LACP, CRIT, "Allocate lacpd_state_machine_transmit failed");
		return NULL;
	}

	st->base.base = &transmit_machine_base;
	st->base.master = (void *)port;
	/*
	 * Super class init end
	 */
	/*
	 * Sub class init start
	 */
	st->rate_limit_timer.cb = lacpd_fsm_transmit_rate_limit_timer_cb;
	/*
	 * Sub class init end
	 */

	port->lacp->out_api->os_service->timer_set(&st->rate_limit_timer, LACP_FAST_PERIODIC_TIME);

	return &st->base;
}
