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
#include "config_api.h"

LIST_HEAD(cfg_systems);

/*
 * APIs provided for upper layer, start
 */
/*
 * lacpd_cfg_sys_use: find a configuration system
 */
struct lacpd_configuration_system * lacpd_cfg_sys_use(const char *name, struct lacpd_cfg_user *user)
{
	struct lacpd_configuration_system *cfg_sys;

	if (!name || !user || !user->os_service) {
		return NULL;
	}

	list_for_each_entry(cfg_sys, &cfg_systems, node) {
		if (!strncmp(name, cfg_sys->name, sizeof(cfg_sys->name))) {
			cfg_sys->user = user;
			return cfg_sys;
		}
	}

	return NULL;
}

/*
 * APIs provided for upper layer, end
 */
/*
 * APIs provided for lower layer, start
 */
/*
 * lacpd_cfg_sys_register: register a configuration system
 */
bool lacpd_cfg_sys_register(struct lacpd_configuration_system *cfg_sys)
{
	list_add_tail(&cfg_sys->node, &cfg_systems);
	return true;
}
/*
 * APIs provided for lower layer, end
 */
