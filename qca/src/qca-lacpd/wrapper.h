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
#ifndef __LACPD_WRAPPER_H
#define __LACPD_WRAPPER_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <libubox/list.h>

#include "lib_general_device/general_device_api.h"
#include "config/config_api.h"
#include "status/status_api.h"
#include "lacp/lacp_api.h"

struct lacpd_wrapper_instance {
	struct list_head node;

	char name[LACPD_CONFIG_SYS_NAME_SIZE];		/*Name of LACP instance, provided by configuration system*/

	struct lacp_in_api *lacp_obj;			/*Index of LACP protocol instance, wrapper will notify it with packet/link event*/
	struct lacp_out_api lacp_user;			/*Provided by wrapper, LACP use it to talk with physical device*/
	struct lacpd_cfg_lacp_parameters lacp_param;	/*Parameters for LACP instance*/

	struct general_device_system *dev_sys;		/*Network device system for LACP instance*/
	struct general_device_out_api dev_sys_user;	/*Provided by wrapper, network device system use it to notify packet/link event*/
};

struct lacpd_wrapper {
	struct genl_os_service os_service;
	struct genl_os_service_timer shutdown_timer;

	struct lacpd_cfg_user cfg_user;
	struct lacpd_configuration_system *cfg_sys;

	struct lacpd_status_user status_user;
	struct lacpd_status_system *ubus_st_sys;
	struct lacpd_status_system *hotplug_st_sys;

	struct list_head wrappers;			/*Link all lacp wrapper instances together*/
};

#endif /*__LACPD_WRAPPER_H*/
