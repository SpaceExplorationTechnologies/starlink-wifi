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
#ifndef __LACPD_CONFIG_UCI_H
#define __LACPD_CONFIG_UCI_H

#include <stdint.h>
#include <stdbool.h>

#include <libubox/list.h>
#include <uci.h>

#include "config_api.h"

#define LACPD_UCI_PKG_NAME_DEFAULT "lacpd"
#define LACPD_TX_HASH_POLICY_DEFAULT "L2_L3"
#define LACPDU_RATE_DEFAULT false
#define LACPD_SELECT_ALG_DEFAULT "all"
#define LACPD_INSTANCE_ENABLE_DEFAULT true
#define LACPD_INSTANCE_PRIORITY_DEFAULT 0xffff
#define LACPD_PORT_ENABLE_DEFAULT true
#define LACPD_USER_KEY_DEFAULT 0

#define blobmsg_get_bool_default(ATTR, VAL) ((ATTR) ? blobmsg_get_bool(ATTR) : (VAL))

enum {
	LACP_SWITCH_ATTR_IFNAME,
	LACP_SWITCH_ATTR_MAX
};

enum {
	LACP_ATTR_ENABLE,
	LACP_ATTR_NAME,
	LACP_ATTR_PRIORITY,
	LACP_ATTR_TX_HASH_POLICY,
	LACP_ATTR_LACPDU_RATE,
	LACP_ATTR_AD_SELECT,
	LACP_ATTR_MAX
};

enum {
	LACP_PORT_ATTR_ENABLE,
	LACP_PORT_ATTR_IFNAME,
	LACP_PORT_ATTR_LACP,
	LACP_PORT_ATTR_SWITCH,
	LACP_PORT_ATTR_SWITCH_PORT_ID,
	LACP_PORT_ATTR_USER_KEY,
	LACP_PORT_ATTR_MAX
};

struct lacpd_uci_configuration_switch {
	struct list_head node;				/*Linked to "struct lacpd_uci_configuration" ->switches*/

	char section_name[LACPD_CONFIG_SYS_NAME_SIZE];	/*Name of switch section*/
	char ifname[LACPD_CONFIG_SYS_NAME_SIZE];	/*Control interface of switch, switch hide behind this Linux interface*/
};

struct lacpd_uci_configuration_lacp {
	struct list_head node;				/*Linked to "struct lacpd_uci_configuration" ->lacp_instances*/
	struct list_head ports;				/*Switch ports linked to this LACP instance*/

	char section_name[LACPD_CONFIG_SYS_NAME_SIZE];	/*Name of LACP section*/
	char name[LACPD_CONFIG_SYS_NAME_SIZE];		/*Name of LACP instance*/
	uint32_t priority;				/*System priority of LACP instance*/
	enum lacpd_cfg_tx_hash_policy tx_hash_policy;	/*Transmit hash policy, select output port base on layer 2 or layer 3 information*/
	bool lacpdu_rate;				/*LACPDU transmit rate, depends on if link is congested*/
	enum lacpd_cfg_ad_select_alg ad_select;		/*How to select active aggregator when there are multiple aggregators in LACP instance*/
};

struct lacpd_uci_configuration_port {
	struct list_head node;				/*Linked to "struct lacpd_uci_configuration_switch" ->ports*/

	struct lacpd_uci_configuration_switch *sw;	/*associated switch*/
	char ifname[LACPD_CONFIG_SYS_NAME_SIZE];	/*Name for exported switch port, such as eth2*/
	uint32_t port_num;				/*Mapped switch hardware port number*/
	uint32_t user_key;				/*User define key. Different user key will create different aggregation group in switch*/
};

struct lacpd_uci_configuration {
	struct lacpd_configuration_system base;

	struct uci_context *uci_ctx;			/*Save UCI context once UCI package is initialized*/
	struct uci_package *uci_lacp;			/*Loaded LACPD UCI configuration*/

	struct list_head switches;			/*List of switch section in "/etc/config/lacpd"*/
	struct list_head lacp_instances;		/*List of LACP section in "/etc/config/lacpd"*/
};

#endif /*__LACPD_CONFIG_UCI_H*/
