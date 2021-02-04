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
#ifndef __LACPD_CONFIG_API_H
#define __LACPD_CONFIG_API_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <general_os_service.h>
#include <libubox/list.h>

#define LACPD_CONFIG_SYS_NAME_SIZE 64

/*
 * Definitions for configuration of LACP protocol, start
 */
enum lacpd_cfg_tx_hash_policy {
	LACPD_CFG_TX_HASH_POLICY_L2,
	LACPD_CFG_TX_HASH_POLICY_L3,
	LACPD_CFG_TX_HASH_POLICY_L2_L3,
	LACPD_CFG_TX_HASH_POLICY_MAX
};

enum lacpd_cfg_ad_select_alg {
	AD_SELECT_ALG_ALL,
	AD_SELECT_ALG_STABLE,
	AD_SELECT_ALG_BANDWIDTH,
	AD_SELECT_ALG_COUNT,
	AD_SELECT_ALG_MAX
};

struct lacpd_cfg_lacp_parameters {
	uint32_t priority;
	enum lacpd_cfg_tx_hash_policy tx_hash_policy;
	bool lacp_rate;
	enum lacpd_cfg_ad_select_alg ad_select;
};

struct lacpd_cfg_lacp_port_parameters {
	uint32_t user_key;
};
/*
 * Definitions for configuration of LACP protocol, end
 */
/*
 * Definitions for LACPD configuration system, start
 * There may be multiple ways to configure LACPD, such as UCI, UBUS. Each way register its configuration system.
 * Then LACPD will select one or more to load configurations, or listen on runtime configurations.
 */
struct lacpd_cfg_user {
/*
 * OS service provided by wrapper
 */
struct genl_os_service *os_service;
/*
 * lacp_new : configuration system use this API to create a LACP instance
 * name: name of LACP instance, max size is LACP_INSTANCE_NAME_SIZE
 * param: parameters of LACP instance
 * return value: successful or failed
 */
bool (*lacp_new)(const char *name, struct lacpd_cfg_lacp_parameters *param);
/*
 * lacp_destroy : configuration system use this API to destroy a LACP instance
 * name: name of LACP instance, max size is LACP_INSTANCE_NAME_SIZE
 * return value: successful or failed
 */
bool (*lacp_destroy)(const char *name);
/*
 * add_dev : configuration system use this API to add a device into a LACP instance
 * lacp_name: name of LACP instance, max size is LACP_INSTANCE_NAME_SIZE
 * dev_name: name of device, max size is LACP_DEVICE_NAME_SIZE
 * param: parameters of LACP port
 * return value: successful or failed
 */
bool (*add_dev)(const char *lacp_name, const char *dev_name, struct lacpd_cfg_lacp_port_parameters *param);
/*
 * del_dev : configuration system use this API to delete a device from a LACP instance
 * lacp_name: name of LACP instance, max size is LACP_INSTANCE_NAME_SIZE
 * dev_name: name of device, max size is LACP_DEVICE_NAME_SIZE
 * return value: successful or failed
 */
bool (*del_dev)(const char *lacp_name, const char *dev_name);
};
/*
 * LACPD will pass some parameters to configuration system in its initial stage to customize initialization
 */
struct lacpd_cfg_sys_init_params {
	char uci_cfg_pkg_name[LACPD_CONFIG_SYS_NAME_SIZE];
};

enum lacpd_cfg_sys_type {
	LACPD_CFG_SYS_TYPE_ACTIVE,			/*Configuration system can load configuration in its initial stage*/
	LACPD_CFG_SYS_TYPE_PASSIVE			/*Configuration system will wait for configuration at runtime*/
};

struct lacpd_configuration_system {
	struct list_head node;

	char name[LACPD_CONFIG_SYS_NAME_SIZE];
	enum lacpd_cfg_sys_type type;
	/*
	 * init: load LACP configuration
	 * param: parameters to customize initialization, use default parameters if NULL
	 * return value:successful or failed
	 */
	bool (*init)(struct lacpd_cfg_sys_init_params *param);
	/*
	 * exit: system is going to exit, free all allocated resources
	 */
	void (*exit)(void);
	/*
	 * APIs provided by Wrapper, it is used by configuration system to talk with wrapper
	 */
	struct lacpd_cfg_user *user;
};
/*
 * Definitions for LACPD configuration system, end
 */
/*
 * APIs provided for upper layer, start
 */
void lacpd_uci_cfg_probe(void);
/*
 * lacpd_cfg_sys_use: find a configuration system
 */
struct lacpd_configuration_system * lacpd_cfg_sys_use(const char *name, struct lacpd_cfg_user *user);
/*
 * APIs provided for upper layer, end
 */
/*
 * APIs provided for lower layer, start
 */
/*
 * lacpd_cfg_sys_register: register a configuration system
 */
bool lacpd_cfg_sys_register(struct lacpd_configuration_system *cfg_sys);
/*
 * APIs provided for lower layer, end
 */
#endif /*__LACPD_CONFIG_API_H*/
