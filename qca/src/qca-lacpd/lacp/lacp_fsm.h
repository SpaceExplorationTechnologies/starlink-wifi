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
#ifndef __LACPD_LACP_FSM_H
#define __LACPD_LACP_FSM_H

#include "fsm.h"
#include "port.h"

#define MSECS_PER_SEC 1000

#define LACP_FAST_PERIODIC_TIME (1 * MSECS_PER_SEC)
#define LACP_SLOW_PERIODIC_TIME (30 * MSECS_PER_SEC)

#define LACP_SHORT_TIMEOUT_TIME (3 * MSECS_PER_SEC)
#define LACP_LONG_TIMEOUT_TIME (90 * MSECS_PER_SEC)

#define LACP_CHURN_DETECTION_TIME (60 * MSECS_PER_SEC)
#define LACP_AGGREGATE_WAIT_TIME (2 * MSECS_PER_SEC)

enum lacpd_state_machine_receive_state {
	LACPD_RECV_ST_INITIALIZE,
	LACPD_RECV_ST_PORT_DISABLED,
	LACPD_RECV_ST_EXPIRED,
	LACPD_RECV_ST_LACP_DISABLED,
	LACPD_RECV_ST_DEFAULTED,
	LACPD_RECV_ST_CURRENT,
	LACPD_RECV_ST_MAX
};

struct lacpd_state_machine_receive {
	struct state_machine base;
	struct genl_os_service_timer current_while_timer;
};

/*
 * lacpd_fsm_receive_new : Create LACP receive state machine for LACP port
 */
struct state_machine *lacpd_fsm_receive_new(struct lacpd_port *port);

enum lacpd_state_machine_periodic_transmission_state {
	LACPD_PERIODIC_ST_NO_PERIODIC,
	LACPD_PERIODIC_ST_FAST_PERIODIC,
	LACPD_PERIODIC_ST_SLOW_PERIODIC,
	LACPD_PERIODIC_ST_PERIODIC_TX,
	LACPD_PERIODIC_ST_MAX
};

struct lacpd_state_machine_periodic_transmission {
	struct state_machine base;
	struct genl_os_service_timer periodic_timer;
};

/*
 * lacpd_fsm_periodic_transmission_new : Create LACP periodic transmission state machine for LACP port
 */
struct state_machine *lacpd_fsm_periodic_transmission_new(struct lacpd_port *port);

enum lacpd_state_machine_selection_logic_state {
	LACPD_SELECT_LOGIC_ST_UNSELECTED,
	LACPD_SELECT_LOGIC_ST_SELECTED,
	LACPD_SELECT_LOGIC_ST_MAX
};

struct lacpd_state_machine_selection_logic {
	struct state_machine base;
};

/*
 * lacpd_fsm_selection_logic_new : Create LACP selection logic state machine for LACP port
 */
struct state_machine *lacpd_fsm_selection_logic_new(struct lacpd_port *port);

enum lacpd_state_machine_mux_state {
	LACPD_MUX_ST_DETACHED,
	LACPD_MUX_ST_WAITING,
	LACPD_MUX_ST_ATTACHED,
	LACPD_MUX_ST_COLLECTING_DISTRIBUTING,
	LACPD_MUX_ST_MAX
};

struct lacpd_state_machine_mux {
	struct state_machine base;
	struct genl_os_service_timer wait_while_timer;
};

/*
 * lacpd_fsm_mux_new : Create LACP mux state machine for LACP port
 */
struct state_machine *lacpd_fsm_mux_new(struct lacpd_port *port);

enum lacpd_state_machine_transmit_state {
	LACPD_TRANSMIT_ST_NO_TX,
	LACPD_TRANSMIT_ST_TX,
	LACPD_TRANSMIT_ST_DISABLED,
	LACPD_TRANSMIT_ST_MAX
};

struct lacpd_state_machine_transmit {
	struct state_machine base;
	struct genl_os_service_timer rate_limit_timer;
	unsigned int pkt_sent;
};

/*
 * lacpd_fsm_transmit_new : Create LACP transmit state machine for LACP port
 */
struct state_machine *lacpd_fsm_transmit_new(struct lacpd_port *port);

#endif /*__LACPD_LACP_FSM_H*/
