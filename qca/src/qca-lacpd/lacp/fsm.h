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
#ifndef __LACPD_FSM_H
#define __LACPD_FSM_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <general_os_service.h>
#include <libubox/list.h>

#define FSM_RUN_DELAY 50
#define FSM_NAME_SIZE 64
#define FSM_MAX_STATE 32
#define FSM_MAX_ACTION 8

struct state_machine;

typedef bool (*fsm_state_entry_condition)(struct state_machine *st);
typedef void (*fsm_state_entry_action)(struct state_machine *st);

struct state_machine_state {
	char *name;
	/*
	 * Is used to check if state machine can enter this state
	 */
	fsm_state_entry_condition condition;
	/*
	 * All the actions to take when state machine enter this state
	 */
	fsm_state_entry_action actions[FSM_MAX_ACTION];
};

struct state_machine_base {
	/*
	 * Name of state machine
	 */
	char *name;
	/*
	 * index of state machine
	 */
	uint32_t id;
	/*
	 * Initial state when start state machine
	 */
	uint32_t initial_state;
	/*
	 * Maximum state
	 */
	uint32_t max_state;
	/*
	 * All states in this state machine
	 * above variable 'max_state' is the actual size of this array
	 */
	struct state_machine_state states[FSM_MAX_STATE];
	/*
	 * Destroy state machine, free allocated memory
	 */
	void (*destroy)(struct state_machine *st);
};

struct state_machine {
	struct list_head node;
	/*
	 * Shared information by all instances
	 */
	struct state_machine_base *base;
	/*
	 * Current state
	 */
	uint32_t state;
	/*
	 * Which object does this state machine runs for?
	 */
	void *master;
};

struct fsm_runner {
	/*state machines in a system*/
	struct list_head machines;
	/*Are all state machines initialized*/
	bool initialized;
	/*OS service provided by wrapper*/
	struct genl_os_service *os_service;
	/*We will run all state machines after a specific time*/
	struct genl_os_service_timer runner_timer;
	/*How long will above timer delay its running*/
	uint32_t run_delay;
};

/*
 * fsm_runner_schedule : state of system changed, we need to run all state machines after a specific time
 */
void fsm_runner_schedule(struct fsm_runner *runner);
/*
 * fsm_runner_stop : system is going to exit, so we need to stop all state machines
 */
void fsm_runner_stop(struct fsm_runner *runner);
/*
 * fsm_runner_lookup_state_machine : find state machine by its id
 */
struct state_machine *fsm_runner_lookup_state_machine(struct fsm_runner *runner, uint32_t st_id);
/*
 * fsm_runner_add_state_machine : add a state machine into runner
 */
bool fsm_runner_add_state_machine(struct fsm_runner *runner, struct state_machine *st);
/*
 * fsm_runner_del_state_machine : delete a state machine from runner
 */
bool fsm_runner_del_state_machine(struct fsm_runner *runner, struct state_machine *st);
/*
 * fsm_runner_init : initialize runner with default values
 */
void fsm_runner_init(struct fsm_runner *runner, struct genl_os_service *os_service);
/*
 * fsm_runner_cleanup : cancel scheduled running, free all added state machines
 */
void fsm_runner_cleanup(struct fsm_runner *runner);

#endif /*__LACPD_FSM_H*/

