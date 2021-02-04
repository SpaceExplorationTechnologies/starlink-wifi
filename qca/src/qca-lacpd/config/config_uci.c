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

#include <libubox/list.h>
#include <libubox/blobmsg.h>
#include <uci_blob.h>

#include "config_api.h"
#include "config_uci.h"

static struct lacpd_uci_configuration lacpd_uci_cfg;

static const struct blobmsg_policy lacp_switch_attrs[LACP_SWITCH_ATTR_MAX] = {
	[LACP_SWITCH_ATTR_IFNAME] = { .name = "ifname", .type = BLOBMSG_TYPE_STRING },
};

const struct uci_blob_param_list lacp_switch_attr_list = {
	.n_params = LACP_SWITCH_ATTR_MAX,
	.params = lacp_switch_attrs,
};

static const struct blobmsg_policy lacp_attrs[LACP_ATTR_MAX] = {
	[LACP_ATTR_ENABLE] = { .name = "enable", .type = BLOBMSG_TYPE_BOOL },
	[LACP_ATTR_NAME] = { .name = "name", .type = BLOBMSG_TYPE_STRING },
	[LACP_ATTR_PRIORITY] = { .name = "priority", .type = BLOBMSG_TYPE_INT32 },
	[LACP_ATTR_TX_HASH_POLICY] = { .name = "txHashPolicy", .type = BLOBMSG_TYPE_STRING },
	[LACP_ATTR_LACPDU_RATE] = { .name = "lacpRate", .type = BLOBMSG_TYPE_BOOL },
	[LACP_ATTR_AD_SELECT] = { .name = "adSelect", .type = BLOBMSG_TYPE_STRING },
};

const struct uci_blob_param_list lacp_attr_list = {
	.n_params = LACP_ATTR_MAX,
	.params = lacp_attrs,
};

static const struct blobmsg_policy lacp_port_attrs[LACP_PORT_ATTR_MAX] = {
	[LACP_PORT_ATTR_ENABLE] = { .name = "enable", .type = BLOBMSG_TYPE_BOOL },
	[LACP_PORT_ATTR_IFNAME] = { .name = "ifname", .type = BLOBMSG_TYPE_STRING },
	[LACP_PORT_ATTR_LACP] = { .name = "lacp", .type = BLOBMSG_TYPE_STRING },
	[LACP_PORT_ATTR_SWITCH] = { .name = "switch", .type = BLOBMSG_TYPE_STRING },
	[LACP_PORT_ATTR_SWITCH_PORT_ID] = { .name = "switchPortId", .type = BLOBMSG_TYPE_INT32 },
	[LACP_PORT_ATTR_USER_KEY] = { .name = "userKey", .type = BLOBMSG_TYPE_INT32 },
};

const struct uci_blob_param_list lacp_port_attr_list = {
	.n_params = LACP_PORT_ATTR_MAX,
	.params = lacp_port_attrs,
};

/*
 * lacpd_uci_cfg_select_str_option: find the index of option
 * v: string to find, for example: "op2"
 * options: available options, must end with NULL. for example: char *options = {"op1", "op2", "opN", NULL}
 * return value: index of option or index of NULL
 */
static uint32_t lacpd_uci_cfg_select_str_option(const char *v, char **options)
{
	uint32_t idx;

	for (idx = 0; options[idx]; idx++) {
		if (!strcmp(v, options[idx])) {
			break;
		}
	}

	return idx;
}

/*
 * lacpd_uci_cfg_lookup_switch: find switch by its UCI section name
 */
static struct lacpd_uci_configuration_switch *lacpd_uci_cfg_lookup_switch(const char *sw_section_name)
{
	struct lacpd_uci_configuration_switch *sw_cfg;

	list_for_each_entry(sw_cfg, &lacpd_uci_cfg.switches, node) {
		if (!strncmp(sw_section_name, sw_cfg->section_name, sizeof(sw_cfg->section_name))) {
			return sw_cfg;
		}
	}

	return NULL;
}

/*
 * lacpd_uci_cfg_lookup_lacp_instance: find LACP instance by its UCI section name
 */
static struct lacpd_uci_configuration_lacp *lacpd_uci_cfg_lookup_lacp_instance(const char *lacp_section_name)
{
	struct lacpd_uci_configuration_lacp *lacp_cfg;

	list_for_each_entry(lacp_cfg, &lacpd_uci_cfg.lacp_instances, node) {
		if (!strncmp(lacp_section_name, lacp_cfg->section_name, sizeof(lacp_cfg->section_name))) {
			return lacp_cfg;
		}
	}

	return NULL;
}

/*
 * lacpd_uci_cfg_parse_port_section: parse port UCI section, allocate a new switch port for each section to save configuration,
 * then link it to its associated switch
 */
static bool lacpd_uci_cfg_parse_port_section(struct uci_section *s)
{
	struct lacpd_uci_configuration_switch *sw_cfg;
	struct lacpd_uci_configuration_lacp *lacp_cfg;
	struct lacpd_uci_configuration_port *sw_port_cfg;
	struct blob_buf bf;
	struct blob_attr *tb[LACP_PORT_ATTR_MAX];
	bool port_enable;

	memset(&bf, 0, sizeof(bf));
	blob_buf_init(&bf, 0);
	uci_to_blob(&bf, s, &lacp_port_attr_list);
	blobmsg_parse(lacp_port_attrs, LACP_PORT_ATTR_MAX, tb, blob_data(bf.head), blob_len(bf.head));

	if (!tb[LACP_PORT_ATTR_LACP] || !tb[LACP_PORT_ATTR_SWITCH] || !tb[LACP_PORT_ATTR_SWITCH_PORT_ID]) {
		blob_buf_free(&bf);
		return false;
	}

	port_enable = blobmsg_get_bool_default(tb[LACP_PORT_ATTR_ENABLE], LACPD_PORT_ENABLE_DEFAULT);
	if (!port_enable) {
		/*
		 * Ignore disabled LACP instance
		 */
		blob_buf_free(&bf);
		return true;
	}

	lacp_cfg = lacpd_uci_cfg_lookup_lacp_instance(blobmsg_get_string(tb[LACP_PORT_ATTR_LACP]));
	if (!lacp_cfg) {
		blob_buf_free(&bf);
		return false;
	}

	sw_cfg = lacpd_uci_cfg_lookup_switch(blobmsg_get_string(tb[LACP_PORT_ATTR_SWITCH]));
	if (!sw_cfg) {
		blob_buf_free(&bf);
		return false;
	}

	sw_port_cfg = (struct lacpd_uci_configuration_port *)calloc(1, sizeof(struct lacpd_uci_configuration_port));
	if (!sw_port_cfg) {
		blob_buf_free(&bf);
		return false;
	}

	if (tb[LACP_PORT_ATTR_IFNAME]) {
		char *ifname = blobmsg_get_string(tb[LACP_PORT_ATTR_IFNAME]);

		if (ifname) {
			snprintf(sw_port_cfg->ifname, sizeof(sw_port_cfg->ifname), "%s", ifname);
		}
	}

	sw_port_cfg->sw = sw_cfg;
	sw_port_cfg->port_num = blobmsg_get_u32(tb[LACP_PORT_ATTR_SWITCH_PORT_ID]);
	sw_port_cfg->user_key = tb[LACP_PORT_ATTR_USER_KEY] ? blobmsg_get_u32(tb[LACP_PORT_ATTR_USER_KEY]) : LACPD_USER_KEY_DEFAULT;

	list_add_tail(&sw_port_cfg->node, &lacp_cfg->ports);
	blob_buf_free(&bf);
	return true;
}

/*
 * lacpd_uci_cfg_parse_port: traverse all port UCI section, and parse its content
 */
static bool lacpd_uci_cfg_parse_port(void)
{
	struct uci_package *pkg = lacpd_uci_cfg.uci_lacp;
	struct uci_element *e;

	uci_foreach_element(&pkg->sections, e) {
		struct uci_section *s = uci_to_section(e);

		if (!strcmp(s->type, "port")) {
			if (!lacpd_uci_cfg_parse_port_section(s)) {
				return false;
			}
		}
	}

	return true;
}



/*
 * lacpd_uci_cfg_parse_lacp_section: parse LACP UCI section, and save its configuration
 */
static bool lacpd_uci_cfg_parse_lacp_section(struct uci_section *s)
{
	struct lacpd_uci_configuration_lacp *lacp_cfg;
	struct blob_buf bf;
	struct blob_attr *tb[LACP_ATTR_MAX];
	bool lacp_enable;
	char *tx_hash_policy_str, *tx_hash_policy_options[]={"L2", "L3", "L2_L3", NULL};
	char *ad_select_str, *ad_select_options[]={"all", "stable", "bandwidth", "count", NULL};
	uint32_t tx_hash_policy, ad_select;

	memset(&bf, 0, sizeof(bf));
	blob_buf_init(&bf, 0);
	uci_to_blob(&bf, s, &lacp_attr_list);
	blobmsg_parse(lacp_attrs, LACP_ATTR_MAX, tb, blob_data(bf.head), blob_len(bf.head));

	lacp_enable = blobmsg_get_bool_default(tb[LACP_ATTR_ENABLE], LACPD_INSTANCE_ENABLE_DEFAULT);
	if (!lacp_enable) {
		/*
		 * Ignore disabled LACP instance
		 */
		blob_buf_free(&bf);
		return true;
	}

	tx_hash_policy_str = tb[LACP_ATTR_TX_HASH_POLICY] ? blobmsg_get_string(tb[LACP_ATTR_TX_HASH_POLICY]) : LACPD_TX_HASH_POLICY_DEFAULT;
	tx_hash_policy = lacpd_uci_cfg_select_str_option(tx_hash_policy_str, tx_hash_policy_options);
	if (tx_hash_policy == LACPD_CFG_TX_HASH_POLICY_MAX) {
		blob_buf_free(&bf);
		return false;
	}

	ad_select_str = tb[LACP_ATTR_AD_SELECT] ? blobmsg_get_string(tb[LACP_ATTR_AD_SELECT]) : LACPD_SELECT_ALG_DEFAULT;
	ad_select = lacpd_uci_cfg_select_str_option(ad_select_str, ad_select_options);
	if (ad_select == AD_SELECT_ALG_MAX) {
		blob_buf_free(&bf);
		return false;
	}

	lacp_cfg = (struct lacpd_uci_configuration_lacp *)calloc(1, sizeof(struct lacpd_uci_configuration_lacp));
	if (!lacp_cfg) {
		blob_buf_free(&bf);
		return false;
	}

	INIT_LIST_HEAD(&lacp_cfg->ports);
	snprintf(lacp_cfg->section_name, sizeof(lacp_cfg->section_name), "%s", s->e.name);
	snprintf(lacp_cfg->name, sizeof(lacp_cfg->name), "%s", (tb[LACP_ATTR_NAME] ? blobmsg_get_string(tb[LACP_ATTR_NAME]) : lacp_cfg->section_name));
	lacp_cfg->priority = tb[LACP_ATTR_PRIORITY] ? blobmsg_get_u32(tb[LACP_ATTR_PRIORITY]) : LACPD_INSTANCE_PRIORITY_DEFAULT;
	lacp_cfg->tx_hash_policy = tx_hash_policy;
	lacp_cfg->lacpdu_rate = blobmsg_get_bool_default(tb[LACP_ATTR_LACPDU_RATE], LACPDU_RATE_DEFAULT);
	lacp_cfg->ad_select = ad_select;

	list_add_tail(&lacp_cfg->node, &lacpd_uci_cfg.lacp_instances);
	blob_buf_free(&bf);
	return true;
}

/*
 * lacpd_uci_cfg_parse_lacp: traverse all LACP UCI section, and parse its content
 */
static bool lacpd_uci_cfg_parse_lacp(void)
{
	struct uci_package *pkg = lacpd_uci_cfg.uci_lacp;
	struct uci_element *e;

	uci_foreach_element(&pkg->sections, e) {
		struct uci_section *s = uci_to_section(e);

		if (!strcmp(s->type, "lacp")) {
			if (!lacpd_uci_cfg_parse_lacp_section(s)) {
				return false;
			}
		}
	}

	return true;
}

/*
 * lacpd_uci_cfg_parse_switch_section: parse switch UCI section, allocate a new switch for each section to save configuration
 */
static bool lacpd_uci_cfg_parse_switch_section(struct uci_section *s)
{
	struct lacpd_uci_configuration_switch *sw_cfg;
	struct blob_buf bf;
	struct blob_attr *tb[LACP_SWITCH_ATTR_MAX];

	memset(&bf, 0, sizeof(bf));
	blob_buf_init(&bf, 0);
	uci_to_blob(&bf, s, &lacp_switch_attr_list);
	blobmsg_parse(lacp_switch_attrs, LACP_SWITCH_ATTR_MAX, tb, blob_data(bf.head), blob_len(bf.head));

	if (!tb[LACP_SWITCH_ATTR_IFNAME]) {
		blob_buf_free(&bf);
		return false;
	}

	sw_cfg = (struct lacpd_uci_configuration_switch *)calloc(1, sizeof(struct lacpd_uci_configuration_switch));
	if (!sw_cfg) {
		blob_buf_free(&bf);
		return false;
	}

	snprintf(sw_cfg->section_name, sizeof(sw_cfg->section_name), "%s", s->e.name);
	snprintf(sw_cfg->ifname, sizeof(sw_cfg->ifname), "%s", blobmsg_get_string(tb[LACP_SWITCH_ATTR_IFNAME]));

	list_add_tail(&sw_cfg->node, &lacpd_uci_cfg.switches);
	blob_buf_free(&bf);
	return true;
}

/*
 * lacpd_uci_cfg_parse_switch: traverse all switch UCI section, and parse its content
 */
static bool lacpd_uci_cfg_parse_switch(void)
{
	struct uci_package *pkg = lacpd_uci_cfg.uci_lacp;
	struct uci_element *e;

	uci_foreach_element(&pkg->sections, e) {
		struct uci_section *s = uci_to_section(e);

		if (!strcmp(s->type, "switch")) {
			if (!lacpd_uci_cfg_parse_switch_section(s)) {
				return false;
			}
		}
	}

	return true;
}

/*
 * lacpd_uci_cfg_init_package: load LACP configuration from file to UCI context for parsing later
 */
static struct uci_package *lacpd_uci_cfg_init_package(const char *pkg_name)
{
	struct lacpd_uci_configuration *cfg = &lacpd_uci_cfg;
	struct uci_context *ctx = cfg->uci_ctx;
	struct uci_package *pkg = NULL;

	if (!ctx) {
		ctx = uci_alloc_context();
		cfg->uci_ctx = ctx;

		ctx->flags &= ~UCI_FLAG_STRICT;
	} else {
		pkg = uci_lookup_package(ctx, pkg_name);
		if (pkg) {
			uci_unload(ctx, pkg);
		}
	}

	if (uci_load(ctx, pkg_name, &pkg)) {
		return NULL;
	}

	return pkg;
}

/*
 * lacpd_uci_cfg_init: load LACP configuration from UCI file
 * os_service: provided OS service by wrapper
 * param: parameters to customize initialization, use default parameters if NULL
 * return value:successful or failed
 */
static bool lacpd_uci_cfg_init(struct lacpd_cfg_sys_init_params *param)
{
	struct lacpd_uci_configuration *cfg = &lacpd_uci_cfg;
	struct lacpd_cfg_user *user = cfg->base.user;
	struct lacpd_uci_configuration_lacp *lacp_cfg;
	struct lacpd_uci_configuration_port *sw_port_cfg;
	struct lacpd_cfg_lacp_parameters lacp_param;
	struct lacpd_cfg_lacp_port_parameters lacp_port_param;
	char port_name[LACPD_CONFIG_SYS_NAME_SIZE];

	INIT_LIST_HEAD(&cfg->switches);
	INIT_LIST_HEAD(&cfg->lacp_instances);

	cfg->uci_lacp = lacpd_uci_cfg_init_package(param ? param->uci_cfg_pkg_name : LACPD_UCI_PKG_NAME_DEFAULT);
	if (!cfg->uci_lacp) {
		DP(CONFIG, CRIT, "Failed to load lacpd configuration");
		return false;
	}

	if (!lacpd_uci_cfg_parse_lacp()) {
		DP(CONFIG, CRIT, "Failed to parse lacp section");
		return false;
	}

	if (!lacpd_uci_cfg_parse_switch()) {
		DP(CONFIG, CRIT, "Failed to parse switch section");
		return false;
	}

	if (!lacpd_uci_cfg_parse_port()) {
		DP(CONFIG, CRIT, "Failed to parse port section");
		return false;
	}

	list_for_each_entry(lacp_cfg, &cfg->lacp_instances, node) {
		lacp_param.priority = lacp_cfg->priority;
		lacp_param.tx_hash_policy = lacp_cfg->tx_hash_policy;
		lacp_param.lacp_rate = lacp_cfg->lacpdu_rate;
		lacp_param.ad_select = lacp_cfg->ad_select;

		if (!user->lacp_new(lacp_cfg->name, &lacp_param)) {
			return false;
		}

		list_for_each_entry(sw_port_cfg, &lacp_cfg->ports, node) {
			if (strlen(sw_port_cfg->ifname)) {
				snprintf(port_name, sizeof(port_name), "%s.%s", sw_port_cfg->sw->ifname, sw_port_cfg->ifname);
			} else {
				snprintf(port_name, sizeof(port_name), "%s.port%d", sw_port_cfg->sw->ifname, sw_port_cfg->port_num);
			}

			lacp_port_param.user_key = sw_port_cfg->user_key;

			if (!user->add_dev(lacp_cfg->name, port_name, &lacp_port_param)){
				return false;
			}
		}
	}

	DP(CONFIG, INFO, "UCI configuration system init successful");
	return true;
}

/*
 * lacpd_uci_cfg_exit: system is going to exit, free all allocated resources
 */
static void lacpd_uci_cfg_exit(void)
{
	struct lacpd_uci_configuration *cfg = &lacpd_uci_cfg;
	struct lacpd_uci_configuration_switch *sw_cfg, *sw_tmp;
	struct lacpd_uci_configuration_lacp *lacp_cfg, *lacp_tmp;
	struct lacpd_uci_configuration_port *sw_port_cfg, *port_tmp;

	list_for_each_entry_safe(lacp_cfg, lacp_tmp, &cfg->lacp_instances, node) {
		list_for_each_entry_safe(sw_port_cfg, port_tmp, &lacp_cfg->ports, node) {
			list_del(&sw_port_cfg->node);
			free(sw_port_cfg);
		}

		list_del(&lacp_cfg->node);
		free(lacp_cfg);
	}

	list_for_each_entry_safe(sw_cfg, sw_tmp, &cfg->switches, node) {
		list_del(&sw_cfg->node);
		free(sw_cfg);
	}

	DP(CONFIG, INFO, "UCI configuration system exit successful");
}

void lacpd_uci_cfg_probe(void)
{
	struct lacpd_configuration_system *cfg_sys = &lacpd_uci_cfg.base;

	snprintf(cfg_sys->name, sizeof(cfg_sys->name), "uci");
	cfg_sys->type = LACPD_CFG_SYS_TYPE_ACTIVE;
	cfg_sys->init = lacpd_uci_cfg_init;
	cfg_sys->exit = lacpd_uci_cfg_exit;

	lacpd_cfg_sys_register(cfg_sys);

	DP(CONFIG, INFO, "UCI configuration system registered");
}
