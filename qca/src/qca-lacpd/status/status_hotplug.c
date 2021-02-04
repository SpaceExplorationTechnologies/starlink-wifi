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
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <general_os_service.h>

#include "status_hotplug.h"

static struct lacpd_hotplug_status_system lacpd_hotplug_st_sys;

static void lacpd_hotplug_queue_event(const char *sw_name, uint32_t port_num, enum lacpd_hotplug_event_type event)
{
	struct lacpd_hotplug_event *evt;

	evt = (struct lacpd_hotplug_event *)calloc(1, sizeof(struct lacpd_hotplug_event));
	if (!evt) {
		return;
	}

	snprintf(evt->sw_name, sizeof(evt->sw_name), "%s", sw_name);
	evt->port_num = port_num;
	evt->event_type = event;

	list_add_tail(&evt->node, &lacpd_hotplug_st_sys.pending_events);
}

static void lacpd_hotplug_run_cmd(const char *sw_name, uint32_t port_num, enum lacpd_hotplug_event_type event)
{
	struct genl_os_service *os_service = lacpd_hotplug_st_sys.base.user->os_service;
	char *eventnames[] = {"port_created", "port_destroyed"};
	char port_num_str[16];
	char *argv[3];
	int pid;

	if (lacpd_hotplug_st_sys.task_is_running) {
		return;
	}

	pid = fork();
	if (pid < 0) {
		return;
	}

	if (pid > 0) {
		lacpd_hotplug_st_sys.task_is_running = true;
		lacpd_hotplug_st_sys.task.pid = pid;
		os_service->task_add(&lacpd_hotplug_st_sys.task);
		return;
	}

	snprintf(port_num_str, sizeof(port_num_str), "%d", port_num);

	setenv("SWITCH", sw_name, 1);
	setenv("PORT", port_num_str, 1);
	setenv("ACTION", eventnames[event], 1);

	argv[0] = DEFAULT_HOTPLUG_PATH;
	argv[1] = "switch";
	argv[2] = NULL;
	execvp(argv[0], argv);
	exit(127);
}

static void lacpd_hotplug_schedule_run(void)
{
	struct lacpd_hotplug_status_system *st_sys = &lacpd_hotplug_st_sys;
	struct lacpd_hotplug_event *current;

	if (list_empty(&st_sys->pending_events)) {
		return;
	}

	if (st_sys->task_is_running) {
		return;
	}

	current = list_first_entry(&st_sys->pending_events, struct lacpd_hotplug_event, node);
	list_del_init(&current->node);
	lacpd_hotplug_run_cmd(current->sw_name, current->port_num, current->event_type);

	free(current);
}

static void lacpd_hotplug_run(const char *sw_name, uint32_t port_num, enum lacpd_hotplug_event_type event)
{
	struct lacpd_hotplug_status_system *st_sys = &lacpd_hotplug_st_sys;

	if (!st_sys->task_is_running && list_empty(&st_sys->pending_events)) {
		lacpd_hotplug_run_cmd(sw_name, port_num, event);
	} else {
		lacpd_hotplug_queue_event(sw_name, port_num, event);
		lacpd_hotplug_schedule_run();
	}
}

static void lacpd_hotplug_task_complete(struct genl_os_service_task *task, int ret)
{
	lacpd_hotplug_st_sys.task_is_running = false;
	lacpd_hotplug_schedule_run();
}

/*
 * lacpd_hotplug_notify_switch_port_created: a new switch port is created
 * sw_name: name of switch
 * port_num: mapped hardware port number, different type of port have different range
 */
static void lacpd_hotplug_notify_switch_port_created(const char *sw_name, uint32_t port_num)
{
	lacpd_hotplug_run(sw_name, port_num, LACPD_HOTPLUG_EVENT_PORT_CREATED);
}

/*
 * lacpd_hotplug_notify_switch_port_destroyed: an exist switch port is destroyed
 * sw_name: name of switch
 * port_num: mapped hardware port number, different type of port have different range
 */
static void lacpd_hotplug_notify_switch_port_destroyed(const char *sw_name, uint32_t port_num)
{
	lacpd_hotplug_run(sw_name, port_num, LACPD_HOTPLUG_EVENT_PORT_DESTROYED);
}

/*
 * lacpd_hotplug_status_system_init: initialize status system
 * return value:successful or failed
 */
static bool lacpd_hotplug_status_system_init(void)
{
	INIT_LIST_HEAD(&lacpd_hotplug_st_sys.pending_events);
	lacpd_hotplug_st_sys.task.cb = lacpd_hotplug_task_complete;

	DP(STATUS, INFO, "Hotplug status system init successful");
	return true;
}

/*
 * lacpd_hotplug_status_system_exit: system is going to exit, free all allocated resources
 */
static void lacpd_hotplug_status_system_exit(void)
{
	struct lacpd_hotplug_status_system *st_sys = &lacpd_hotplug_st_sys;
	struct lacpd_hotplug_event *evt, *tmp;

	list_for_each_entry_safe(evt, tmp, &st_sys->pending_events, node) {
		list_del(&evt->node);
		free(evt);
	}

	DP(STATUS, INFO, "Hotplug status system exit successful");
}

void lacpd_hotplug_status_system_probe(void)
{
	struct lacpd_status_system *st_sys = &lacpd_hotplug_st_sys.base;

	snprintf(st_sys->name, sizeof(st_sys->name), "hotplug");
	st_sys->init = lacpd_hotplug_status_system_init;
	st_sys->exit = lacpd_hotplug_status_system_exit;
	st_sys->notify.switch_port_created = lacpd_hotplug_notify_switch_port_created;
	st_sys->notify.switch_port_destroyed = lacpd_hotplug_notify_switch_port_destroyed;

	lacpd_status_sys_register(st_sys);
}
