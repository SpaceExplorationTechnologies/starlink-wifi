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
#include "fsm.h"

/*
 * fsm_runner_schedule : state of system changed, we need to run all state machines after a specific time
 */
void fsm_runner_schedule(struct fsm_runner *runner)
{
	if (!runner || list_empty(&runner->machines) || !runner->runner_timer.cb) {
		DP(LACP, CRIT, "fsm_runner is not ready to run");
		return;
	}

	if (runner->runner_timer.pending) {
		return;
	}

	runner->os_service->timer_set(&runner->runner_timer, runner->run_delay);
}

/*
 * fsm_runner_stop : system is going to exit, so we need to stop all state machines
 */
void fsm_runner_stop(struct fsm_runner *runner)
{
	if (!runner) {
		DP(LACP, CRIT, "Invalid argument");
		return;
	}

	runner->os_service->timer_cancel(&runner->runner_timer);
}

/*
 * fsm_runner_lookup_state_machine : find state machine by its id
 */
struct state_machine *fsm_runner_lookup_state_machine(struct fsm_runner *runner, uint32_t st_id)
{
	struct state_machine *st;

	list_for_each_entry(st, &runner->machines, node) {
		if (st->base->id == st_id) {
			return st;
		}
	}

	return NULL;
}

/*
 * fsm_runner_add_state_machine : add a state machine into runner
 */
bool fsm_runner_add_state_machine(struct fsm_runner *runner, struct state_machine *st)
{
	int idx;

	if (!runner || runner->initialized || !runner->runner_timer.cb) {
		DP(LACP, CRIT, "fsm_runner is not ready to add state machine");
		return false;
	}

	if (!st || (st->base->max_state > FSM_MAX_STATE) || (st->base->initial_state >= st->base->max_state)) {
		DP(LACP, CRIT, "Arguments of state machine are invalid");
		return false;
	}

	for (idx = 0; idx < st->base->max_state; idx++) {
		if (!st->base->states[idx].condition) {
			DP(LACP, CRIT, "No condition checking function for state %d of state machine %s", idx, st->base->name);
			return false;
		}
	}

	if (fsm_runner_lookup_state_machine(runner, st->base->id)) {
		return true;
	}

	list_add_tail(&st->node, &runner->machines);
	return true;
}

/*
 * fsm_runner_del_state_machine : delete a state machine from runner
 */
bool fsm_runner_del_state_machine(struct fsm_runner *runner, struct state_machine *st)
{
	struct state_machine *st_idx, *tmp;

	if (!runner || !st) {
		return false;
	}

	list_for_each_entry_safe(st_idx, tmp, &runner->machines, node) {
		if (st_idx == st) {
			list_del(&st->node);
			break;
		}
	}

	return true;
}

/*
 * fsm_change_to_state : change to a new state, and execute all entry actions in this state
 * st: state machine
 * return value: true: state changed; false: state not changed
 */
static bool fsm_change_to_state(struct state_machine *st, unsigned int new_state)
{
	int action_idx;

	DP(LACP_FSM, DEBUG, "%s change from \"%s\" to \"%s\"", st->base->name, st->base->states[st->state].name, st->base->states[new_state].name);

	st->state = new_state;

	for (action_idx = 0; (action_idx < FSM_MAX_ACTION) && st->base->states[st->state].actions[action_idx]; action_idx++) {
		st->base->states[st->state].actions[action_idx](st);
	}

	return true;
}

/*
 * fsm_check_transit_conditions : Check if a state machine can change to another state
 * st: state machine
 * return value: true: state changed; false: state not changed
 */
static bool fsm_check_transit_conditions(struct state_machine *st)
{
	int changed = false;
	int idx;

	for (idx = 0; idx < st->base->max_state; idx++) {
		if (st->base->states[idx].condition(st)) {
			changed = fsm_change_to_state(st, idx);
		}
	}

	return changed;
}

/*
 * fsm_runner_initail_run : let all state machine change to its initail state
 */
static void fsm_runner_initail_run(struct fsm_runner *runner)
{
	struct state_machine *st;

	if (runner->initialized) {
		return;
	}

	list_for_each_entry(st, &runner->machines, node) {
		fsm_change_to_state(st, st->base->initial_state);
	}

	runner->initialized = true;
}

/*
 * fsm_class_run : Run all state machines untill thier state don't change
 * t: this is the first running if t is NULL
 */
static void fsm_runner_run(struct genl_os_service_timer *t)
{
	struct fsm_runner *runner= container_of(t, struct fsm_runner, runner_timer);
	struct state_machine *st;
	bool changed;


	if (!runner->initialized) {
		fsm_runner_initail_run(runner);
		return;
	}

	/*
	 * Run all state machines until their state don't change
	 */
	do {
		changed = false;
		list_for_each_entry(st, &runner->machines, node) {
			while (fsm_check_transit_conditions(st)) changed = true;
		}
	} while (changed);
}

/*
 * fsm_runner_init : init runner with default values
 */
void fsm_runner_init(struct fsm_runner *runner, struct genl_os_service *os_service)
{
	if (!runner || !os_service) {
		return;
	}

	INIT_LIST_HEAD(&runner->machines);
	runner->initialized = false;
	runner->os_service = os_service;
	runner->runner_timer.cb = fsm_runner_run;
	runner->run_delay = FSM_RUN_DELAY;
}

/*
 * fsm_runner_cleanup : cancel scheduled running, free all added state machines
 */
void fsm_runner_cleanup(struct fsm_runner *runner)
{
	struct state_machine *st, *tmp;

	if (!runner) {
		return;
	}

	fsm_runner_stop(runner);

	list_for_each_entry_safe(st, tmp, &runner->machines, node) {
		list_del(&st->node);
		st->base->destroy(st);
	}

	runner->initialized = false;
}
