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
#include <libubox/list.h>
#include <libubox/uloop.h>
#include <libubox/ustream.h>
#include <libubox/utils.h>
#include <libubus.h>

#include "status_ubus.h"

#define LACPD_STRING_BUF_MAX_SIZE 64

enum lacpd_status_printer_arg_type {
	LACPD_PRINTER_ARG_TYPE_BUF,
	LACPD_PRINTER_ARG_TYPE_LACP,
	LACPD_PRINTER_ARG_TYPE_AGGS,
	LACPD_PRINTER_ARG_TYPE_AGG,
	LACPD_PRINTER_ARG_TYPE_PORTS,
	LACPD_PRINTER_ARG_TYPE_PORT
};

static struct lacpd_ubus_status_system lacpd_ubus_st_sys;

static inline void lacpd_ubus_status_print_hw_addr(struct blob_buf *bf, const char *name, uint8_t *addr)
{
	char *buf = blobmsg_alloc_string_buffer(bf, name, LACPD_STRING_BUF_MAX_SIZE);
	snprintf(buf, LACPD_STRING_BUF_MAX_SIZE, "%02x:%02x:%02x:%02x:%02x:%02x",
				addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);
	blobmsg_add_string_buffer(bf);
}

static inline void lacpd_ubus_status_print_lacp_flags(struct blob_buf *bf, const char *name, uint8_t *flags)
{
	static char *flag_string[] = {"activity", "timeout", "aggregation", "synchronization",
					"collecting", "distributing", "defaulted", "expired"};
	char *buf = blobmsg_alloc_string_buffer(bf, name, LACPD_STRING_BUF_MAX_SIZE);
	int idx, len = 0;

	for (idx = 0; idx < 8; idx++) {
		if ((*flags) & (1 << idx)) {
			len += snprintf(buf + len, (LACPD_STRING_BUF_MAX_SIZE - len), "%s ", flag_string[idx]);
		}
	}

	blobmsg_add_string_buffer(bf);
}

static void lacpd_ubus_status_printer(struct lacpd_status_printer *p, enum lacpd_status_field_type type, void *value)
{
	struct blob_buf *bf = (struct blob_buf *)p->arg[LACPD_PRINTER_ARG_TYPE_BUF];
	char *ad_select_str[]={"all", "stable", "bandwidth", "count"};

	switch(type) {
	case LACP_STATUS_FIELD_LACP_START:
		p->arg[LACPD_PRINTER_ARG_TYPE_LACP] = blobmsg_open_table(bf, "802.3ad instance");
		break;
	case LACP_STATUS_FIELD_LACP_NAME:
		blobmsg_add_string(bf, "Name", (char *)value);
		break;
	case LACP_STATUS_FIELD_SYS_HW_ADDR:
		lacpd_ubus_status_print_hw_addr(bf, "System HW address", (uint8_t *)value);
		break;
	case LACP_STATUS_FIELD_LACP_RATE:
		blobmsg_add_string(bf, "LACP rate", (((bool)value) ? "fast" : "slow"));
		break;
	case LACP_STATUS_FIELD_AD_SELECT_ALG:
		blobmsg_add_string(bf, "Active aggregator select algorithm", ad_select_str[(int)value]);
		break;
	case LACP_STATUS_FIELD_LACP_END:
		blobmsg_close_table(bf, p->arg[LACPD_PRINTER_ARG_TYPE_LACP]);
		break;
	case LACP_STATUS_FIELD_AGGS_START:
		p->arg[LACPD_PRINTER_ARG_TYPE_AGGS] = blobmsg_open_array(bf, "Aggregators");
		break;
	case LACP_STATUS_FIELD_AGG_START:
		p->arg[LACPD_PRINTER_ARG_TYPE_AGG] = blobmsg_open_table(bf, (char *)value);
		break;
	case LACP_STATUS_FIELD_DEV:
		blobmsg_add_string(bf, "Device", (char *)value);
		break;
	case LACP_STATUS_FIELD_AGG_ID:
		blobmsg_add_u32(bf, "Aggregator ID", (uint32_t)value);
		break;
	case LACP_STATUS_FIELD_AGG_PORTS_CNT:
		blobmsg_add_u32(bf, "Number of ports", (uint32_t)value);
		break;
	case LACP_STATUS_FIELD_AGG_ACTOR_KEY:
		blobmsg_add_u32(bf, "Actor key", (uint32_t)value);
		break;
	case LACP_STATUS_FIELD_AGG_PARTNER_KEY:
		blobmsg_add_u32(bf, "Partner key", (uint32_t)value);
		break;
	case LACP_STATUS_FIELD_AGG_PARTNER_HW_ADDR:
		lacpd_ubus_status_print_hw_addr(bf, "Partner HW address", (uint8_t *)value);
		break;
	case LACP_STATUS_FIELD_AGG_END:
		blobmsg_close_table(bf, p->arg[LACPD_PRINTER_ARG_TYPE_AGG]);
		break;
	case LACP_STATUS_FIELD_AGGS_END:
		blobmsg_close_array(bf, p->arg[LACPD_PRINTER_ARG_TYPE_AGGS]);
		break;
	case LACP_STATUS_FIELD_PORTS_START:
		p->arg[LACPD_PRINTER_ARG_TYPE_PORTS] = blobmsg_open_array(bf, "Ports");
		break;
	case LACP_STATUS_FIELD_PORT_START:
		p->arg[LACPD_PRINTER_ARG_TYPE_PORT] = blobmsg_open_table(bf, (char *)value);
		break;
	case LACP_STATUS_FIELD_PORT_LINK_STATUS:
		blobmsg_add_string(bf, "Link status", (((bool)value) ? "up" : "down"));
		break;
	case LACP_STATUS_FIELD_PORT_SPEED:
		blobmsg_add_u32(bf, "Speed(Mbps)", (uint32_t)value);
		break;
	case LACP_STATUS_FIELD_PORT_DUPLEX:
		blobmsg_add_string(bf, "Duplex", (((bool)value) ? "full" : "half"));
		break;
	case LACP_STATUS_FIELD_PORT_HW_ADDR:
		lacpd_ubus_status_print_hw_addr(bf, "Permanent HW address", (uint8_t *)value);
		break;
	case LACP_STATUS_FIELD_ACTOR_PORT:
		blobmsg_add_u32(bf, "Actor port", (uint32_t)value);
		break;
	case LACP_STATUS_FIELD_ACTOR_STATE:
		lacpd_ubus_status_print_lacp_flags(bf, "Actor state", (uint8_t *)value);
		break;
	case LACP_STATUS_FIELD_PARTNER_PORT:
		blobmsg_add_u32(bf, "Partner port", (uint32_t)value);
		break;
	case LACP_STATUS_FIELD_PARTNER_STATE:
		lacpd_ubus_status_print_lacp_flags(bf, "Partner state", (uint8_t *)value);
		break;
	case LACP_STATUS_FIELD_PORT_STATS_TX_SUCCESS:
		blobmsg_add_u32(bf, "Tx successes", (uint32_t)value);
		break;
	case LACP_STATUS_FIELD_PORT_STATS_RX_SUCCESS:
		blobmsg_add_u32(bf, "Rx successes", (uint32_t)value);
		break;
	case LACP_STATUS_FIELD_PORT_STATS_TX_ERROR:
		blobmsg_add_u32(bf, "Tx error", (uint32_t)value);
		break;
	case LACP_STATUS_FIELD_PORT_STATS_RX_ERROR:
		blobmsg_add_u32(bf, "Rx error", (uint32_t)value);
		break;
	case LACP_STATUS_FIELD_PORT_END:
		blobmsg_close_table(bf, p->arg[LACPD_PRINTER_ARG_TYPE_PORT]);
		break;
	case LACP_STATUS_FIELD_PORTS_END:
		blobmsg_close_array(bf, p->arg[LACPD_PRINTER_ARG_TYPE_PORTS]);
		break;
	case LACP_STATUS_FIELD_ERROR:
		blobmsg_add_string(bf, "Error", (char *)value);
		break;
	default:
		DP(STATUS, DEBUG, "Unknown status field");
		break;
	}
}

static const struct blobmsg_policy lacpd_ubus_status_dump_policy[LACPD_STATUS_DUMP_ARG_MAX] = {
		[LACPD_STATUS_DUMP_ARG_LACP_NAME] = { .name = "lacp_name", .type = BLOBMSG_TYPE_STRING },
};

static int lacpd_ubus_status_dump(struct ubus_context *ctx, struct ubus_object *obj,
								struct ubus_request_data *req, const char *method,
								struct blob_attr *msg)
{
	struct lacpd_status_system *st_sys = &lacpd_ubus_st_sys.base;
	struct blob_attr *tb[LACPD_STATUS_DUMP_ARG_MAX];
	struct lacpd_status_printer p;
	struct blob_buf bf;
	char *sw_name;

	blobmsg_parse(lacpd_ubus_status_dump_policy, LACPD_STATUS_DUMP_ARG_MAX, tb, blob_data(msg), blob_len(msg));

	memset(&bf, 0, sizeof(bf));
	blob_buf_init(&bf, 0);
	p.arg[LACPD_PRINTER_ARG_TYPE_BUF] = (void *)&bf;
	p.fn = lacpd_ubus_status_printer;

	sw_name = tb[LACPD_STATUS_DUMP_ARG_LACP_NAME] ? blobmsg_get_string(tb[LACPD_STATUS_DUMP_ARG_LACP_NAME]) : NULL;
	st_sys->user->status_dump(sw_name, &p);

	ubus_send_reply(ctx, req, bf.head);
	blob_buf_free(&bf);

	return 0;
}

static const struct blobmsg_policy lacpd_ubus_get_aggregator_of_port_policy[LACPD_GET_AGG_OF_PORT_ARG_MAX] = {
		[LACPD_GET_AGG_OF_PORT_ARG_SW_NAME] = { .name = "sw_name", .type = BLOBMSG_TYPE_STRING },
		[LACPD_GET_AGG_OF_PORT_ARG_PORT_ID] = { .name = "port_num", .type = BLOBMSG_TYPE_INT32 },
};

static int lacpd_ubus_get_aggregator_of_port(struct ubus_context *ctx, struct ubus_object *obj,
											struct ubus_request_data *req, const char *method,
											struct blob_attr *msg)
{
	struct lacpd_status_system *st_sys = &lacpd_ubus_st_sys.base;
	struct blob_attr *tb[LACPD_GET_AGG_OF_PORT_ARG_MAX];
	struct blob_buf bf;
	char *sw_name;
	uint32_t port_id, agg_id;

	blobmsg_parse(lacpd_ubus_get_aggregator_of_port_policy, LACPD_GET_AGG_OF_PORT_ARG_MAX, tb, blob_data(msg), blob_len(msg));
	if (!tb[LACPD_GET_AGG_OF_PORT_ARG_SW_NAME] || !tb[LACPD_GET_AGG_OF_PORT_ARG_PORT_ID]) {
		return UBUS_STATUS_INVALID_ARGUMENT;
	}

	sw_name = blobmsg_get_string(tb[LACPD_GET_AGG_OF_PORT_ARG_SW_NAME]);
	port_id = blobmsg_get_u32(tb[LACPD_GET_AGG_OF_PORT_ARG_PORT_ID]);
	agg_id = st_sys->user->get_aggregator_of_port(sw_name, port_id);

	memset(&bf, 0, sizeof(bf));
	blob_buf_init(&bf, 0);
	blobmsg_add_u32(&bf, "aggregator_id", agg_id);
	ubus_send_reply(ctx, req, bf.head);
	blob_buf_free(&bf);

	return 0;
}

static const struct blobmsg_policy lacpd_ubus_get_ports_of_aggregator_policy[LACPD_GET_PORTS_OF_AGG_ARG_MAX] = {
		[LACPD_GET_PORTS_OF_AGG_ARG_SW_NAME] = { .name = "sw_name", .type = BLOBMSG_TYPE_STRING },
		[LACPD_GET_PORTS_OF_AGG_ARG_AGG_ID] = { .name = "agg_num", .type = BLOBMSG_TYPE_INT32 },
};

static int lacpd_ubus_get_ports_of_aggregator(struct ubus_context *ctx, struct ubus_object *obj,
											struct ubus_request_data *req, const char *method,
											struct blob_attr *msg)
{
	struct lacpd_status_system *st_sys = &lacpd_ubus_st_sys.base;
	struct blob_attr *tb[LACPD_GET_PORTS_OF_AGG_ARG_MAX];
	struct blob_buf bf;
	char *sw_name;
	uint32_t ports_bitmap, agg_id;

	blobmsg_parse(lacpd_ubus_get_ports_of_aggregator_policy, LACPD_GET_PORTS_OF_AGG_ARG_MAX, tb, blob_data(msg), blob_len(msg));
	if (!tb[LACPD_GET_PORTS_OF_AGG_ARG_SW_NAME] || !tb[LACPD_GET_PORTS_OF_AGG_ARG_AGG_ID]) {
		return UBUS_STATUS_INVALID_ARGUMENT;
	}

	sw_name = blobmsg_get_string(tb[LACPD_GET_PORTS_OF_AGG_ARG_SW_NAME]);
	agg_id = blobmsg_get_u32(tb[LACPD_GET_PORTS_OF_AGG_ARG_AGG_ID]);
	ports_bitmap = st_sys->user->get_ports_of_aggregator(sw_name, agg_id);

	memset(&bf, 0, sizeof(bf));
	blob_buf_init(&bf, 0);
	blobmsg_add_u32(&bf, "bitmap_of_ports", ports_bitmap);
	ubus_send_reply(ctx, req, bf.head);
	blob_buf_free(&bf);

	return 0;
}

static struct ubus_method lacpd_ubus_object_methods[] = {
	UBUS_METHOD("status", lacpd_ubus_status_dump, lacpd_ubus_status_dump_policy),
	UBUS_METHOD("get_aggregator_of_port", lacpd_ubus_get_aggregator_of_port, lacpd_ubus_get_aggregator_of_port_policy),
	UBUS_METHOD("get_ports_of_aggregator", lacpd_ubus_get_ports_of_aggregator, lacpd_ubus_get_ports_of_aggregator_policy),
};

static struct ubus_object_type lacpd_ubus_object_type =
	UBUS_OBJECT_TYPE("lacpd", lacpd_ubus_object_methods);

static struct ubus_object lacpd_ubus_object = {
	.name = "lacpd",
	.type = &lacpd_ubus_object_type,
	.methods = lacpd_ubus_object_methods,
	.n_methods = ARRAY_SIZE(lacpd_ubus_object_methods),
};

/*
 * lacpd_ubus_notify_switch_port_created: a new switch port is created
 * sw_name: name of switch
 * port_num: mapped hardware port number, different type of port have different range
 */
static void lacpd_ubus_notify_switch_port_created(const char *sw_name, uint32_t port_num)
{
	struct blob_buf bf;
	int ret;

	memset(&bf, 0, sizeof(bf));
	blob_buf_init(&bf, 0);
	blobmsg_add_string(&bf, "sw_name", sw_name);
	blobmsg_add_u32(&bf, "port_num", port_num);
	ret = ubus_notify(lacpd_ubus_st_sys.ubus_ctx, &lacpd_ubus_object, "switch_port_created", bf.head, -1);
	if (ret) {
		DP(STATUS, WARNING, "Ubus notification failed (%d : %s)", ret, ubus_strerror(ret));
	}
	blob_buf_free(&bf);
}

/*
 * lacpd_ubus_notify_switch_port_destroyed: an exist switch port is destroyed
 * sw_name: name of switch
 * port_num: mapped hardware port number, different type of port have different range
 */
static void lacpd_ubus_notify_switch_port_destroyed(const char *sw_name, uint32_t port_num)
{
	struct blob_buf bf;
	int ret;

	memset(&bf, 0, sizeof(bf));
	blob_buf_init(&bf, 0);
	blobmsg_add_string(&bf, "sw_name", sw_name);
	blobmsg_add_u32(&bf, "port_num", port_num);
	ret = ubus_notify(lacpd_ubus_st_sys.ubus_ctx, &lacpd_ubus_object, "switch_port_destroyed", bf.head, -1);
	if (ret) {
		DP(STATUS, WARNING, "Ubus notification failed (%d : %s)", ret, ubus_strerror(ret));
	}
	blob_buf_free(&bf);
}

/*
 * lacpd_ubus_status_system_init: initialize status system
 * return value:successful or failed
 */
static bool lacpd_ubus_status_system_init(void)
{
	static struct lacpd_ubus_status_system *ubus_st_sys = &lacpd_ubus_st_sys;

	ubus_st_sys->ubus_ctx = ubus_connect(NULL);
	if (!ubus_st_sys->ubus_ctx) {
		return false;
	}

	ubus_add_uloop(ubus_st_sys->ubus_ctx);
	ubus_add_object(ubus_st_sys->ubus_ctx, &lacpd_ubus_object);

	DP(STATUS, INFO, "UBUS status system init successful");
	return true;
}

/*
 * lacpd_ubus_status_system_exit: system is going to exit, free all allocated resources
 */
static void lacpd_ubus_status_system_exit(void)
{
	ubus_free(lacpd_ubus_st_sys.ubus_ctx);
	DP(STATUS, INFO, "UBUS status system exit successful");
}

void lacpd_ubus_status_system_probe(void)
{
	struct lacpd_status_system *st_sys = &lacpd_ubus_st_sys.base;

	snprintf(st_sys->name, sizeof(st_sys->name), "ubus");
	st_sys->init = lacpd_ubus_status_system_init;
	st_sys->exit = lacpd_ubus_status_system_exit;
	st_sys->notify.switch_port_created = lacpd_ubus_notify_switch_port_created;
	st_sys->notify.switch_port_destroyed = lacpd_ubus_notify_switch_port_destroyed;

	lacpd_status_sys_register(st_sys);
}
