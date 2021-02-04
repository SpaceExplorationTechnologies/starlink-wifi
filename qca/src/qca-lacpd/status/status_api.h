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
#ifndef __LACPD_STATUS_API_H
#define __LACPD_STATUS_API_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <general_os_service.h>
#include <libubox/list.h>

#define LACP_STATUS_SYS_NAME_SIZE 64

struct lacpd_status_notify {
	/*
	 * switch_port_created: a new switch port is created
	 * sw_name: name of switch
	 * port_num: mapped hardware port number, different type of port have different range
	 */
	void (*switch_port_created)(const char *sw_name, uint32_t port_num);
	/*
	 * switch_port_destroyed: an exist switch port is destroyed
	 * sw_name: name of switch
	 * port_num: mapped hardware port number, different type of port have different range
	 */
	void (*switch_port_destroyed)(const char *sw_name, uint32_t port_num);
};

enum lacpd_status_field_type {
	LACP_STATUS_FIELD_LACP_START,
	LACP_STATUS_FIELD_LACP_NAME,
	LACP_STATUS_FIELD_SYS_HW_ADDR,
	LACP_STATUS_FIELD_LACP_RATE,
	LACP_STATUS_FIELD_AD_SELECT_ALG,
	LACP_STATUS_FIELD_LACP_END,
	LACP_STATUS_FIELD_AGGS_START,
	LACP_STATUS_FIELD_AGG_START,
	LACP_STATUS_FIELD_AGG_ID,
	LACP_STATUS_FIELD_AGG_PORTS_CNT,
	LACP_STATUS_FIELD_AGG_ACTOR_KEY,
	LACP_STATUS_FIELD_AGG_PARTNER_KEY,
	LACP_STATUS_FIELD_AGG_PARTNER_HW_ADDR,
	LACP_STATUS_FIELD_AGG_END,
	LACP_STATUS_FIELD_AGGS_END,
	LACP_STATUS_FIELD_PORTS_START,
	LACP_STATUS_FIELD_PORT_START,
	LACP_STATUS_FIELD_PORT_LINK_STATUS,
	LACP_STATUS_FIELD_PORT_SPEED,
	LACP_STATUS_FIELD_PORT_DUPLEX,
	LACP_STATUS_FIELD_PORT_HW_ADDR,
	LACP_STATUS_FIELD_ACTOR_PORT,
	LACP_STATUS_FIELD_ACTOR_STATE,
	LACP_STATUS_FIELD_PARTNER_PORT,
	LACP_STATUS_FIELD_PARTNER_STATE,
	LACP_STATUS_FIELD_PORT_STATS_TX_SUCCESS,
	LACP_STATUS_FIELD_PORT_STATS_RX_SUCCESS,
	LACP_STATUS_FIELD_PORT_STATS_TX_ERROR,
	LACP_STATUS_FIELD_PORT_STATS_RX_ERROR,
	LACP_STATUS_FIELD_PORT_END,
	LACP_STATUS_FIELD_PORTS_END,
	LACP_STATUS_FIELD_DEV,
	LACP_STATUS_FIELD_ERROR
};

struct lacpd_status_printer {
	/*
	 * Private data for printer, user shouldn't access it
	 */
	void *arg[16];
	/*
	 * Function to print content of status
	 */
	void (*fn)(struct lacpd_status_printer *p, enum lacpd_status_field_type, void *value);
};

struct lacpd_status_user {
	/*
	 * OS service provided by wrapper
	 */
	struct genl_os_service *os_service;
	/*
	 * status_dump: dump status of a LACP protocol instance
	 * lacp_inst_name: LACP protocol instance to dump
	 * p: lacp use this printer to print content of status
	 */
	void (*status_dump)(const char *lacp_inst_name, struct lacpd_status_printer *p);
	/*
	 * get_aggregator_of_port: get aggregator of port
	 * sw_name: name of switch
	 * port_num: mapped hardware port number
	 * return value: index of aggregator of port, user should check if it is in valid range
	 */
	uint32_t (*get_aggregator_of_port)(const char *sw_name, uint32_t port_num);
	/*
	 * get_ports_of_aggregator: get ports in aggregator
	 * sw_name: name of switch
	 * agg_num: id of aggregator
	 * return value: bitmap of ports
	 */
	uint32_t (*get_ports_of_aggregator)(const char *sw_name, uint32_t agg_num);
};

struct lacpd_status_system {
	struct list_head node;

	char name[LACP_STATUS_SYS_NAME_SIZE];

	/*
	 * init: initialize status system
	 * return value:successful or failed
	 */
	bool (*init)(void);
	/*
	 * exit: system is going to exit, free all allocated resources
	 */
	void (*exit)(void);
	/*
	 * wrapper will notify status system when new switch port is created or exist switch port is destroyed
	 */
	struct lacpd_status_notify notify;
	/*
	 * APIs provided by Wrapper, it is used by status system to talk with wrapper
	 */
	struct lacpd_status_user *user;
};

/*
 * APIs provided for upper layer, start
 */
void lacpd_ubus_status_system_probe(void);
void lacpd_hotplug_status_system_probe(void);
/*
 * lacpd_status_sys_use: find a status system
 */
struct lacpd_status_system * lacpd_status_sys_use(const char *name, struct lacpd_status_user *user);
/*
 * APIs provided for upper layer, end
 */
/*
 * APIs provided for lower layer, start
 */
/*
 * lacpd_status_sys_register: register a status system
 */
bool lacpd_status_sys_register(struct lacpd_status_system *status_sys);
/*
 * APIs provided for lower layer, end
 */
#endif /*__LACPD_STATUS_API_H*/
