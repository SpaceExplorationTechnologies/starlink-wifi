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
#include "status_api.h"

#define DEFAULT_HOTPLUG_PATH "/sbin/hotplug-call"

enum lacpd_hotplug_event_type {
	LACPD_HOTPLUG_EVENT_PORT_CREATED,
	LACPD_HOTPLUG_EVENT_PORT_DESTROYED
};

struct lacpd_hotplug_event {
	struct list_head node;

	char sw_name[LACP_STATUS_SYS_NAME_SIZE];
	uint32_t port_num;
	enum lacpd_hotplug_event_type event_type;
};

struct lacpd_hotplug_status_system {
	struct lacpd_status_system base;

	struct list_head pending_events;

	struct genl_os_service_task task;
	bool task_is_running;
};
