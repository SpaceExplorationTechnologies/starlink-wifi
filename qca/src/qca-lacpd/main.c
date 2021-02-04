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
#include <signal.h>
#include <libubox/list.h>
#include <libubox/uloop.h>

#include "lib_general_device/general_device_api.h"
#include "config/config_api.h"
#include "status/status_api.h"
#include "lacp/lacp_api.h"
#include "wrapper.h"

/*
 * Module description: this module implement all APIs provided by wrapper to all other sub modules,
 * such as 'configuration', 'status', 'general device', 'LACP'
 */

struct lacpd_wrapper __lacpd_wrapper;

unsigned int debug_mask[DBG_MOD_MAX];

/*
 *Internal function declaration, start
 */
static bool lacpd_cfg_lacp_destroy(const char *name);
/*
 *Internal function declaration, end
 */

/*
 * APIs for wrapper itself, start
 */
/*
 * lacpd_wrapper_lookup: lookup LACP instance by name
 */
static struct lacpd_wrapper_instance *lacpd_wrapper_lookup(const char *name)
{
	struct lacpd_wrapper_instance *inst;

	if (!name) {
		return NULL;
	}

	list_for_each_entry(inst, &__lacpd_wrapper.wrappers, node) {
		if (!strncmp(name, inst->name, sizeof(inst->name))) {
			return inst;
		}
	}

	return NULL;
}

/*
 * lacpd_wrapper_instance_add: add LACP instance
 */
static bool lacpd_wrapper_add(struct lacpd_wrapper_instance *inst)
{
	if (!inst) {
		return false;
	}

	if (lacpd_wrapper_lookup(inst->name)) {
		return true;
	}

	list_add_tail(&inst->node, &__lacpd_wrapper.wrappers);
	return true;
}

/*
 * lacpd_wrapper_del: delete LACP instance
 */
static void lacpd_wrapper_del(struct lacpd_wrapper_instance *inst)
{
	if (!inst) {
		return;
	}

	if (!lacpd_wrapper_lookup(inst->name)) {
		return;
	}

	list_del(&inst->node);
}

/*
 * lacpd_wrapper_lookup: lookup LACP instance by name
 */
static void lacpd_wrapper_cleanup(void)
{
	struct lacpd_wrapper_instance *inst, *tmp;

	list_for_each_entry_safe(inst, tmp, &__lacpd_wrapper.wrappers, node) {
		list_del(&inst->node);

		if (inst->lacp_obj) {
			inst->lacp_obj->destroy(inst->lacp_obj);
		}

		if (inst->dev_sys) {
			genl_dev_sys_del_user(inst->dev_sys->name, &inst->dev_sys_user);
		}

		free(inst);
	}
}

/*
 * APIs for wrapper itself, end
 */
/*
 * APIs for LACP, start
 */
/*
 * lacpd_wrapper_get_sys_hw_addr : get hardware address of system
 * lacp_user: provided by wrapper, used to get device system of physical device
 * mac_addr: returned MAC address of system
 * return value: successful or fail
 */
static bool lacpd_wrapper_get_sys_hw_addr(struct lacp_out_api *user, uint8_t *mac_addr)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return false;
	}

	return inst->dev_sys->system.get_hw_addr(inst->dev_sys, mac_addr);
}

/*
 * lacpd_wrapper_get_dev_name: returns name of network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * dev_name, returned name
 * return value: point to dev_name if success, or NULL if failed
 */
static char *lacpd_wrapper_get_dev_name(struct lacp_out_api *user, uint32_t dev_obj, char *dev_name)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return NULL;
	}

	return inst->dev_sys->common.netdev_obj_to_name(inst->dev_sys, dev_obj, dev_name);
}

/*
 * lacpd_wrapper_get_dev_duplex : get duplex of network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: 1: full duplex, 0: half duplex
 */
static uint32_t lacpd_wrapper_get_dev_duplex(struct lacp_out_api *user, uint32_t dev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return 0;
	}

	return inst->dev_sys->common.get_duplex(inst->dev_sys, dev_obj);
}

/*
 * lacpd_wrapper_get_dev_speed : get speed of network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: 0: invalid, 1: 1Mbps, 10: 10Mbps, 100: 100Mbps, 1000: 1Gbps, 10000: 10Gbps
 */
static uint32_t lacpd_wrapper_get_dev_speed(struct lacp_out_api *user, uint32_t dev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return 0;
	}

	return inst->dev_sys->common.get_speed(inst->dev_sys, dev_obj);
}

/*
 * lacpd_wrapper_get_dev_link_status : get link status of network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: true: link up; false: link down
 */
static bool lacpd_wrapper_get_dev_link_status(struct lacp_out_api *user, uint32_t dev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return false;
	}

	return inst->dev_sys->common.get_link_status(inst->dev_sys, dev_obj);
}

/*
 * lacpd_wrapper_get_dev_hw_addr : get hardware address of network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * mac_addr: returned MAC address of network device
 * return value: successful or fail
 */
static bool lacpd_wrapper_get_dev_hw_addr(struct lacp_out_api *user, uint32_t dev_obj, uint8_t *mac_addr)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return false;
	}

	return inst->dev_sys->common.get_hw_addr(inst->dev_sys, dev_obj, mac_addr);
}

/*
 * lacpd_wrapper_enable_dev : enable network device, data packet can be received on this device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: successful or fail
 */
static bool lacpd_wrapper_enable_dev(struct lacp_out_api *user, uint32_t dev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return false;
	}

	return inst->dev_sys->stp.set_port_state(inst->dev_sys, dev_obj, GENL_DEV_STP_STATE_FORWARD);
}

/*
 * lacpd_wrapper_disable_dev : disable network device, data packet is prohibited on this device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: successful or fail
 */
static bool lacpd_wrapper_disable_dev(struct lacp_out_api *user, uint32_t dev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return false;
	}

	return inst->dev_sys->stp.set_port_state(inst->dev_sys, dev_obj, GENL_DEV_STP_STATE_DISABLE);
}

/*
 * lacpd_wrapper_dev_enable_lacp : enable LACP on network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: successful or fail
 */
static bool lacpd_wrapper_dev_enable_lacp(struct lacp_out_api *user, uint32_t dev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return false;
	}

	return inst->dev_sys->agg.enable(inst->dev_sys, dev_obj);
}

/*
 * lacpd_wrapper_dev_disable_lacp : disable LACP on network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: successful or fail
 */
static bool lacpd_wrapper_dev_disable_lacp(struct lacp_out_api *user, uint32_t dev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return false;
	}

	return inst->dev_sys->agg.disable(inst->dev_sys, dev_obj);
}

/*
 * lacpd_wrapper_instance_dev_send_lacpdu : send lacp packet on a specific network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * buf: buffer of LACP packet
 * buf_len: length of above buffer
 * return value: successful or fail
 */
static bool lacpd_wrapper_dev_send_lacpdu(struct lacp_out_api *user, uint32_t dev_obj, uint8_t *buf, uint32_t buf_len)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return false;
	}

	return inst->dev_sys->agg.send_lacpdu(inst->dev_sys, dev_obj, buf, buf_len);
}

/*
 * lacpd_wrapper_dev_is_slave : check if a network device is a slave of another network device
 * user: provided by wrapper, used to get device system of physical device
 * slave_dev_obj: index of network device
 * master_dev_obj: index of network device
 * return value: is a slave or not a slave
 */
static bool lacpd_wrapper_dev_is_slave(struct lacp_out_api *user, uint32_t slave_dev_obj, uint32_t master_dev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return false;
	}

	return inst->dev_sys->agg.is_slave(inst->dev_sys, slave_dev_obj, master_dev_obj);
}

/*
 * lacpd_wrapper_dev_number_of_slaves : get number of slave network devices of a master network device
 * user: provided by wrapper, used to get device system of physical device
 * master_dev_obj: index of network device
 * return value: number of slaves
 */
static uint32_t lacpd_wrapper_dev_number_of_slaves(struct lacp_out_api *user, uint32_t master_dev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return 0;
	}

	return inst->dev_sys->agg.number_of_slaves(inst->dev_sys, master_dev_obj);
}

/*
 * lacpd_wrapper_sys_new_aggregator : create physical network device for aggregator
 * user: provided by wrapper, used to get device system of physical device
 * name: name of aggregator, length of name is less 64
 * return value: network device index of new aggregator
 */
static uint32_t lacpd_wrapper_sys_new_aggregator(struct lacp_out_api *user, const char *name)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);
	uint32_t netdev_obj;

	if (!inst->dev_sys) {
		return 0;
	}

	netdev_obj = inst->dev_sys->agg.new_aggregator(inst->dev_sys, name);
	if (!netdev_obj_is_invalid(netdev_obj)) {
		inst->dev_sys->agg.set_tx_hash_policy(inst->dev_sys, netdev_obj, inst->lacp_param.tx_hash_policy);
	}

	return netdev_obj;
}

/*
 * lacpd_wrapper_sys_destroy_aggregator : destroy physical network device of aggregator
 * user: provided by wrapper, used to get device system of physical device
 * aggregator_dev_obj: index of network device
 * return value: successful or fail
 */
static bool lacpd_wrapper_sys_destroy_aggregator(struct lacp_out_api *user, uint32_t aggregator_dev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return false;
	}

	return inst->dev_sys->agg.destroy_aggregator(inst->dev_sys, aggregator_dev_obj);
}

/*
 * lacpd_wrapper_dev_attach_slave : attach a slave network device to a master network device
 * user: provided by wrapper, used to get device system of physical device
 * master_dev_obj: index of network device
 * slave_dev_obj: index of network device
 * return value: successful or fail
 */
static bool lacpd_wrapper_dev_attach_slave(struct lacp_out_api *user, uint32_t master_dev_obj, uint32_t slave_dev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return false;
	}

	return inst->dev_sys->agg.attach_slave(inst->dev_sys, master_dev_obj, slave_dev_obj);
}

/*
 * lacpd_wrapper_dev_detach_slave : detach a slave network device from a master network device
 * user: provided by wrapper, used to get device system of physical device
 * master_dev_obj: index of network device
 * slave_dev_obj: index of network device
 * return value: successful or fail
 */
static bool lacpd_wrapper_dev_detach_slave(struct lacp_out_api *user, uint32_t master_dev_obj, uint32_t slave_dev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(user, struct lacpd_wrapper_instance, lacp_user);

	if (!inst->dev_sys) {
		return false;
	}

	return inst->dev_sys->agg.detach_slave(inst->dev_sys, master_dev_obj, slave_dev_obj);
}

/*
 * APIs for LACP, end
 */
/*
 * APIs for general device system, start
 */
/*
 * lacpd_wrapper_dev_link_status_changed : notify link status event of physical network device
 * genl_dev_user: APIs to talk with user of generic network device system
 * netdev_obj: network device where event happen
 * new_status: new link status of device
 */
static void lacpd_wrapper_dev_link_status_changed(struct general_device_out_api *genl_dev_user, uint32_t netdev_obj, int new_status)
{
	struct lacpd_wrapper_instance *inst = container_of(genl_dev_user, struct lacpd_wrapper_instance, dev_sys_user);

	if (!inst->lacp_obj) {
		return;
	}

	return inst->lacp_obj->link_status_changed(inst->lacp_obj, netdev_obj, new_status);
}

/*
 * QCA_SW_PRIVATE_FUNC_ID_GET_PORT_HW_ID =
 * 	(QCA_SWITCH_LAYER_DEPTH << 16) | QCA_SW_PRIVATE_FUNC_get_port_hw_id
 */
#define QCA_SW_PRIVATE_FUNC_ID_GET_PORT_HW_ID ((0x2 << 16) | 0x2)

/*
 * lacpd_wrapper_netdev_obj_added : new physical network device was added into this network device system
 * genl_dev_user: APIs to talk with user of generic network device system
 * netdev_obj: network device where event happen
 */
static void lacpd_wrapper_netdev_obj_added(struct general_device_out_api *genl_dev_user, uint32_t netdev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(genl_dev_user, struct lacpd_wrapper_instance, dev_sys_user);
	struct general_device_system *dev_sys = inst->dev_sys;
	uint32_t port_hw_id = 0xffff;

	if (!dev_sys || netdev_obj_is_invalid(netdev_obj)) {
		return;
	}

	dev_sys->private(dev_sys, QCA_SW_PRIVATE_FUNC_ID_GET_PORT_HW_ID, (void *)netdev_obj, (void *)&port_hw_id);

	if (port_hw_id != 0xffff) {
		if (dev_sys->agg.is_aggregator(dev_sys, netdev_obj, 0)) {
			/*
			 * For user, valid aggregator id is 256~263, but for hardware, valid aggregator id is 0~3
			 * so we have to add aggregator id by 256
			 */
			port_hw_id += 1 << 8;
		}

		__lacpd_wrapper.ubus_st_sys->notify.switch_port_created(inst->dev_sys->name, port_hw_id);
		__lacpd_wrapper.hotplug_st_sys->notify.switch_port_created(inst->dev_sys->name, port_hw_id);
	}
}

/*
 * lacpd_wrapper_netdev_obj_deleted : physical network device was deleted from this network device system
 * genl_dev_user: APIs to talk with user of generic network device system
 * netdev_obj: network device where event happen
 */
static void lacpd_wrapper_netdev_obj_deleted(struct general_device_out_api *genl_dev_user, uint32_t netdev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(genl_dev_user, struct lacpd_wrapper_instance, dev_sys_user);
	struct general_device_system *dev_sys = inst->dev_sys;
	uint32_t port_hw_id = 0xffff;

	if (!dev_sys || netdev_obj_is_invalid(netdev_obj)) {
		return;
	}

	dev_sys->private(dev_sys, QCA_SW_PRIVATE_FUNC_ID_GET_PORT_HW_ID, (void *)netdev_obj, (void *)&port_hw_id);

	if (port_hw_id != 0xffff) {
		if (dev_sys->agg.is_aggregator(dev_sys, netdev_obj, 0)) {
			/*
			 * For user, valid aggregator id is 256~263, but for hardware, valid aggregator id is 0~3
			 * so we have to add aggregator id by 256
			 */
			port_hw_id += 1 << 8;
		}

		__lacpd_wrapper.ubus_st_sys->notify.switch_port_destroyed(inst->dev_sys->name, port_hw_id);
		__lacpd_wrapper.hotplug_st_sys->notify.switch_port_destroyed(inst->dev_sys->name, port_hw_id);
	}
}

/*
 * lacpd_wrapper_dev_receive_lacpdu : receive LACPDU packet
 * genl_dev_user: APIs to talk with user of generic network device system
 * buf: packet
 * buf_len: length of packet
 * dev_obj: receiving network device
 * return value: packet is consumed or not
 */
static bool lacpd_wrapper_dev_receive_lacpdu(struct general_device_out_api *genl_dev_user, uint8_t *buf, uint32_t buf_len, uint32_t netdev_obj)
{
	struct lacpd_wrapper_instance *inst = container_of(genl_dev_user, struct lacpd_wrapper_instance, dev_sys_user);

	if (!inst->lacp_obj) {
		return false;
	}

	return inst->lacp_obj->receive_lacpdu(inst->lacp_obj, buf, buf_len, netdev_obj);
}

/*
 * lacpd_wrapper_dev_sys_unregistered : general device system is unregistered
 * genl_dev_user: APIs to talk with user of generic network device system
 */
static void lacpd_wrapper_dev_sys_unregistered(struct general_device_out_api *genl_dev_user)
{
	struct lacpd_wrapper_instance *inst = container_of(genl_dev_user, struct lacpd_wrapper_instance, dev_sys_user);

	lacpd_cfg_lacp_destroy(inst->name);
}

/*
 * APIs for general device system, end
 */
/*
 * APIs for configuration, start
 */
/*
 * lacpd_cfg_lacp_new : configuration module use this API to create a LACP instance
 * name: name of LACP instance, max size is LACP_INSTANCE_NAME_SIZE
 * param: parameters of LACP instance
 * return value: successful or failed
 */
static bool lacpd_cfg_lacp_new(const char *name, struct lacpd_cfg_lacp_parameters *param)
{
	struct lacpd_wrapper_instance *inst = lacpd_wrapper_lookup(name);

	if (inst) {
		DP(WRAPPER, CRIT, "Instance %s already exist", name);
		return false;
	}

	inst = (struct lacpd_wrapper_instance *)calloc(1, sizeof(struct lacpd_wrapper_instance));
	if (!inst) {
		DP(WRAPPER, CRIT, "Allocate LACP Instance failed");
		return false;
	}

	snprintf(inst->name, sizeof(inst->name), "%s", name);
	inst->lacp_param = *param;

	if(!lacpd_wrapper_add(inst)) {
		free(inst);
		DP(WRAPPER, CRIT, "Failed to add wrapper %s", name);
		return false;
	}

	DP(WRAPPER, INFO, "Add wrapper %s successful", name);
	return true;
}

/*
 * lacpd_cfg_lacp_destroy : configuration module use this API to destroy a LACP instance
 * name: name of LACP instance, max size is LACP_INSTANCE_NAME_SIZE
 * return value: successful or failed
 */
static bool lacpd_cfg_lacp_destroy(const char *name)
{
	struct lacpd_wrapper_instance *inst = lacpd_wrapper_lookup(name);

	if (!inst) {
		DP(WRAPPER, CRIT, "Instance %s is not created yet", name);
		return false;
	}

	if (inst->lacp_obj) {
		inst->lacp_obj->destroy(inst->lacp_obj);
		inst->lacp_obj = NULL;
	}

	if (inst->dev_sys) {
		genl_dev_sys_del_user(inst->dev_sys->name, &inst->dev_sys_user);
		inst->dev_sys = NULL;
	}

	lacpd_wrapper_del(inst);
	free(inst);

	DP(WRAPPER, INFO, "Destroy wrapper %s successful", name);
	return true;
}

/*
 * lacpd_cfg_add_dev : configuration module use this API to add a device into a LACP instance
 * lacp_name: name of LACP instance, max size is LACP_INSTANCE_NAME_SIZE
 * dev_name: name of device, max size is LACP_DEVICE_NAME_SIZE
 * param: parameters of LACP port
 * return value: successful or failed
 */
static bool lacpd_cfg_add_dev(const char *lacp_name, const char *dev_name, struct lacpd_cfg_lacp_port_parameters *param)
{
	struct lacpd_wrapper_instance *inst = lacpd_wrapper_lookup(lacp_name);
	struct general_device_system *dev_sys = genl_dev_sys_resolve_by_name(dev_name);
	struct lacp_parameters lacp_param;
	struct lacp_port_parameters port_param;
	uint32_t dev_obj;

	if (!inst) {
		DP(WRAPPER, CRIT, "Instance %s not created", lacp_name);
		return false;
	}

	if (!dev_sys) {
		DP(WRAPPER, CRIT, "Unknown device %s", dev_name);
		return false;
	}

	dev_obj = dev_sys->common.name_to_netdev_obj(dev_sys, dev_name);
	if (!dev_obj) {
		DP(WRAPPER, CRIT, "Can't resolve device %s", dev_name);
		return false;
	}

	if (inst->dev_sys && (inst->dev_sys != dev_sys)) {
		DP(WRAPPER, CRIT, "Can't aggregate different types of device");
		return false;
	}

	if (!inst->dev_sys) {
		inst->dev_sys = dev_sys;

		inst->dev_sys_user.link_status_changed = lacpd_wrapper_dev_link_status_changed;
		inst->dev_sys_user.netdev_obj_added = lacpd_wrapper_netdev_obj_added;
		inst->dev_sys_user.netdev_obj_deleted = lacpd_wrapper_netdev_obj_deleted;
		inst->dev_sys_user.receive_lacpdu = lacpd_wrapper_dev_receive_lacpdu;
		inst->dev_sys_user.system_unregistered = lacpd_wrapper_dev_sys_unregistered;
		if (!genl_dev_sys_add_user(dev_sys->name, &inst->dev_sys_user)) {
			DP(WRAPPER, CRIT, "Can't use device system %s", dev_sys->name);
			return false;
		}
	}

	if (!inst->lacp_obj) {
		inst->lacp_user.os_service = &__lacpd_wrapper.os_service;
		inst->lacp_user.get_sys_mac_addr = lacpd_wrapper_get_sys_hw_addr;
		inst->lacp_user.get_dev_name = lacpd_wrapper_get_dev_name;
		inst->lacp_user.get_dev_duplex = lacpd_wrapper_get_dev_duplex;
		inst->lacp_user.get_dev_speed = lacpd_wrapper_get_dev_speed;
		inst->lacp_user.get_dev_link_status = lacpd_wrapper_get_dev_link_status;
		inst->lacp_user.get_dev_mac_addr = lacpd_wrapper_get_dev_hw_addr;
		inst->lacp_user.enable_dev = lacpd_wrapper_enable_dev;
		inst->lacp_user.disable_dev = lacpd_wrapper_disable_dev;
		inst->lacp_user.enable_lacp = lacpd_wrapper_dev_enable_lacp;
		inst->lacp_user.disable_lacp = lacpd_wrapper_dev_disable_lacp;
		inst->lacp_user.send_lacpdu = lacpd_wrapper_dev_send_lacpdu;
		inst->lacp_user.is_slave = lacpd_wrapper_dev_is_slave;
		inst->lacp_user.number_of_slaves = lacpd_wrapper_dev_number_of_slaves;
		inst->lacp_user.new_aggregator = lacpd_wrapper_sys_new_aggregator;
		inst->lacp_user.destroy_aggregator = lacpd_wrapper_sys_destroy_aggregator;
		inst->lacp_user.attach_slave = lacpd_wrapper_dev_attach_slave;
		inst->lacp_user.detach_slave = lacpd_wrapper_dev_detach_slave;

		memset(&lacp_param, 0, sizeof(lacp_param));
		lacp_param.priority = inst->lacp_param.priority;
		lacp_param.lacp_rate = inst->lacp_param.lacp_rate;
		lacp_param.ad_select = inst->lacp_param.ad_select;

		inst->lacp_obj = lacp_new(inst->name, &inst->lacp_user, &lacp_param);
		if (!inst->lacp_obj) {
			DP(WRAPPER, CRIT, "Can't create LACP instance %s", lacp_name);
			return false;
		}
	}

	memset(&port_param, 0, sizeof(port_param));
	port_param.user_key = param->user_key;
	return inst->lacp_obj->add_device(inst->lacp_obj, dev_obj, &port_param);
}

/*
 * lacpd_cfg_del_dev : configuration module use this API to delete a device from a LACP instance
 * lacp_name: name of LACP instance, max size is LACP_INSTANCE_NAME_SIZE
 * dev_name: name of device, max size is LACP_DEVICE_NAME_SIZE
 * return value: successful or failed
 */
static bool lacpd_cfg_del_dev(const char *lacp_name, const char *dev_name)
{
	struct lacpd_wrapper_instance *inst = lacpd_wrapper_lookup(lacp_name);
	uint32_t dev_obj;

	if (!inst) {
		DP(WRAPPER, CRIT, "Instance %s not created", lacp_name);
		return false;
	}

	if (!inst->lacp_obj) {
		DP(WRAPPER, CRIT, "LACP instance %s not created", lacp_name);
		return false;
	}

	if (!inst->dev_sys) {
		DP(WRAPPER, CRIT, "Unknown device system for LACP instance %s", lacp_name);
		return false;
	}

	dev_obj = inst->dev_sys->common.name_to_netdev_obj(inst->dev_sys, dev_name);
	if (!dev_obj) {
		DP(WRAPPER, CRIT, "Can't resolve device %s", dev_name);
		return false;
	}

	return inst->lacp_obj->del_device(inst->lacp_obj, dev_obj);
}

/*
 * APIs for configuration, end
 */
/*
 * APIs for status, start
 */
/*
 * lacpd_wrapper_dump_status: dump status of a LACP protocol instance
 * lacp_inst_name: LACP protocol instance to dump
 * p: lacp use this printer to print content of status
 */
static void lacpd_wrapper_dump_status(const char *lacp_inst_name, struct lacpd_status_printer *p)
{
	struct lacpd_wrapper_instance *inst;
	int inst_cnt = 0;

	list_for_each_entry(inst, &__lacpd_wrapper.wrappers, node) {
		if (!inst->lacp_obj) {
			continue;
		}

		if (!lacp_inst_name || !strncmp(lacp_inst_name, inst->name, sizeof(inst->name))) {
			inst->lacp_obj->status_dump(inst->lacp_obj, p);
			++inst_cnt;
		}
	}

	if (inst_cnt == 0) {
		p->fn(p, LACP_STATUS_FIELD_ERROR, (void *)"No such a LACP instance");
		return;
	}
}

/*
 * lacpd_wrapper_get_aggregator_of_port: get aggregator of port
 * sw_name: name of switch
 * port_num: mapped hardware port number
 * return value: index of aggregator of port, user should check if it is in valid range
 */
static uint32_t lacpd_wrapper_get_aggregator_of_port(const char *sw_name, uint32_t port_num)
{
	struct lacpd_wrapper_instance *inst = NULL;
	struct general_device_system *dev_sys = NULL;
	uint32_t agg_id = 0xffff;

	list_for_each_entry(inst, &__lacpd_wrapper.wrappers, node) {
		if (!inst->dev_sys) {
			continue;
		}

		if (!strncmp(sw_name, inst->dev_sys->name, sizeof(inst->dev_sys->name))) {
			dev_sys = inst->dev_sys;
			break;
		}
	}

	if (!dev_sys || !dev_sys->private) {
		return 0;
	}

/*
 * QCA_SW_PRIVATE_FUNC_ID_GET_AGG_ID_OF_PORT =
 * 	(QCA_SWITCH_LAYER_DEPTH << 16) | QCA_SW_PRIVATE_FUNC_get_agg_id_of_port
 */
#define QCA_SW_PRIVATE_FUNC_ID_GET_AGG_ID_OF_PORT ((0x2 << 16) | 0x0)

	if (dev_sys->private(dev_sys, QCA_SW_PRIVATE_FUNC_ID_GET_AGG_ID_OF_PORT,
					(void *)port_num, (void *)&agg_id)) {
		/*
		 * We have defined valid aggregator id is 256~263
		 */
		agg_id += 1 << 8;
	}

	return agg_id;
}

/*
 * lacpd_wrapper_get_ports_of_aggregator: get ports in aggregator
 * sw_name: name of switch
 * agg_num: id of aggregator
 * return value: bitmap of ports
 */
static uint32_t lacpd_wrapper_get_ports_of_aggregator(const char *sw_name, uint32_t agg_num)
{
	struct lacpd_wrapper_instance *inst = NULL;
	struct general_device_system *dev_sys = NULL;
	uint32_t bitmap_of_ports = 0;

	list_for_each_entry(inst, &__lacpd_wrapper.wrappers, node) {
		if (!inst->dev_sys) {
			continue;
		}

		if (!strncmp(sw_name, inst->dev_sys->name, sizeof(inst->dev_sys->name))) {
			dev_sys = inst->dev_sys;
			break;
		}
	}

	if (!dev_sys || !dev_sys->private) {
		return 0;
	}

/*
 * QCA_SW_PRIVATE_FUNC_ID_GET_PORTS_OF_AGG =
 * 	(QCA_SWITCH_LAYER_DEPTH << 16) | QCA_SW_PRIVATE_FUNC_get_ports_of_agg
 */
#define QCA_SW_PRIVATE_FUNC_ID_GET_PORTS_OF_AGG ((0x2 << 16) | 0x1)

	/*
	 * For user, valid aggregator id is 256~263, but for hardware, valid aggregator id is 0~3
	 * so we have to sub aggregator id by 256
	 */
	dev_sys->private(dev_sys, QCA_SW_PRIVATE_FUNC_ID_GET_PORTS_OF_AGG,
					(void *)(agg_num - (1 << 8)), (void *)&bitmap_of_ports);

	return bitmap_of_ports;
}

/*
 * APIs for status, end
 */
/*
 * APIs for general OS service, start
 */
/*
 * lacpd_wrapper_os_service_fd_cb: handler for general OS service file descriptor
 */
static void lacpd_wrapper_os_service_fd_cb(struct uloop_fd *u, unsigned int events)
{
	struct genl_os_service_private *private_ptr = (struct genl_os_service_private *)u;
	struct genl_os_service_fd *genl_os_fd = container_of(private_ptr, struct genl_os_service_fd, private_data);
	unsigned int genl_os_events = 0;

	if (!u->registered) {
		DP(WRAPPER, CRIT, "uloop fd %d has been delted by uloop", u->fd);
	}

	if (events & ULOOP_READ) {
		genl_os_events = genl_os_events | GENL_OS_SERVICE_FD_EVENTS_READ;
	}

	if (events & ULOOP_WRITE) {
		genl_os_events = genl_os_events | GENL_OS_SERVICE_FD_EVENTS_WRITE;
	}

	genl_os_fd->cb(genl_os_fd, genl_os_events);
}

/*
 * lacpd_wrapper_os_service_fd_add : listen on a file descriptor for reading or writing
 * fd: file descriptor
 * flags: call 'cb' when file descriptor is able to read or write
 * return value: successful or fail
 */
static int lacpd_wrapper_os_service_fd_add(struct genl_os_service_fd *fd, unsigned int flags)
{
	struct uloop_fd *ufd = (struct uloop_fd *)&fd->private_data;
	uint8_t uflags = 0;

	ufd->fd = fd->fd;
	ufd->cb = lacpd_wrapper_os_service_fd_cb;

	if (flags & GENL_OS_SERVICE_FD_FLAGS_READ) {
		uflags = uflags | ULOOP_READ;
	}

	if (flags & GENL_OS_SERVICE_FD_FLAGS_WRITE) {
		uflags = uflags | ULOOP_WRITE;
	}

	return 0 == uloop_fd_add(ufd, uflags);
}

/*
 * lacpd_wrapper_os_service_fd_del : cancel to listen on file descriptor
 * fd: file descriptor
 * return value: successful or fail
 */
static int lacpd_wrapper_os_service_fd_del(struct genl_os_service_fd *fd)
{
	struct uloop_fd *ufd = (struct uloop_fd *)&fd->private_data;

	ufd->fd = fd->fd;

	return 0 == uloop_fd_delete(ufd);
}

/*
 * lacpd_wrapper_os_service_timer_cb: handler for general OS service timer
 */
static void lacpd_wrapper_os_service_timer_cb(struct uloop_timeout *t)
{
	struct genl_os_service_private *private_ptr = (struct genl_os_service_private *)t;
	struct genl_os_service_timer *genl_os_timer = container_of(private_ptr, struct genl_os_service_timer, private_data);

	genl_os_timer->pending = false;
	genl_os_timer->cb(genl_os_timer);
}

/*
 * lacpd_wrapper_os_service_timer_set : start a timer
 * timer: timer
 * msecs: delay of timer, in unit of millisecond
 * return value: successful or fail
 */
static int lacpd_wrapper_os_service_timer_set(struct genl_os_service_timer *timer, int msecs)
{
	struct uloop_timeout *utimer = (struct uloop_timeout *)&timer->private_data;

	timer->pending = true;
	utimer->cb = lacpd_wrapper_os_service_timer_cb;

	return 0 == uloop_timeout_set(utimer, msecs);
}

/*
 * lacpd_wrapper_os_service_timer_cancel : cancel a timer
 * timer: timer
 * return value: successful or fail
 */
static int lacpd_wrapper_os_service_timer_cancel(struct genl_os_service_timer *timer)
{
	struct uloop_timeout *utimer = (struct uloop_timeout *)&timer->private_data;

	timer->pending = false;
	return 0 == uloop_timeout_cancel(utimer);
}

/*
 * lacpd_wrapper_os_service_task_cb: handler for general OS service task
 */
static void lacpd_wrapper_os_service_task_cb(struct uloop_process *c, int ret)
{
	struct genl_os_service_private *private_ptr = (struct genl_os_service_private *)c;
	struct genl_os_service_task *genl_os_task = container_of(private_ptr, struct genl_os_service_task, private_data);

	genl_os_task->cb(genl_os_task, ret);
}

/*
 * lacpd_wrapper_os_service_task_add : wait for a task to complete, then execute corresponding handler
 * task: task descriptor
 * return value: successful or fail
 */
static int lacpd_wrapper_os_service_task_add(struct genl_os_service_task *task)
{
	struct uloop_process *utask = (struct uloop_process *)&task->private_data;

	utask->pid = task->pid;
	utask->cb = lacpd_wrapper_os_service_task_cb;

	return 0 == uloop_process_add(utask);
}

/*
 * lacpd_wrapper_os_service_task_del : cancel to wait for a task
 * task: task descriptor
 * return value: successful or fail
 */
static int lacpd_wrapper_os_service_task_del(struct genl_os_service_task *task)
{
	struct uloop_process *utask = (struct uloop_process *)&task->private_data;

	return 0 == uloop_process_delete(utask);
}

/*
 * APIs for general OS service, end
 */

/*
 * lacpd_shutdown_timer_cb: end uloop after our shutdown timer expires.
 * 				This is to do a graceful shutdown.
 */
static void lacpd_shutdown_timer_cb(struct genl_os_service_timer *timer)
{
	uloop_end();
}

/*
 * lacpd_shutdown_delay: run uloop again until our shutdown timer expires
 * 			 which will end uloop in its callback. We expect all
 * 			 cleanup can be done during this time.
 */
static void lacpd_shutdown_delay(uint32_t msecs)
{
	struct genl_os_service *os_service = &__lacpd_wrapper.os_service;

	__lacpd_wrapper.shutdown_timer.cb = lacpd_shutdown_timer_cb;
	if (os_service->timer_set(&__lacpd_wrapper.shutdown_timer, msecs)) {
		uloop_cancelled = false;
		uloop_run();
	}
}

static bool lacpd_status_init(void)
{
	struct lacpd_status_system *st_sys;

	__lacpd_wrapper.status_user.os_service = &__lacpd_wrapper.os_service;
	__lacpd_wrapper.status_user.status_dump = lacpd_wrapper_dump_status;
	__lacpd_wrapper.status_user.get_aggregator_of_port = lacpd_wrapper_get_aggregator_of_port;
	__lacpd_wrapper.status_user.get_ports_of_aggregator = lacpd_wrapper_get_ports_of_aggregator;

	st_sys = lacpd_status_sys_use("ubus", &__lacpd_wrapper.status_user);
	if (!st_sys || !st_sys->init()) {
		DP(WRAPPER, CRIT, "Load UBUS status system failed");
		return false;
	}

	__lacpd_wrapper.ubus_st_sys = st_sys;

	st_sys = lacpd_status_sys_use("hotplug", &__lacpd_wrapper.status_user);
	if (!st_sys || !st_sys->init()) {
		DP(WRAPPER, CRIT, "Load HOTPLUG status system failed");
		__lacpd_wrapper.ubus_st_sys->exit();
		__lacpd_wrapper.ubus_st_sys = NULL;
		return false;
	}

	__lacpd_wrapper.hotplug_st_sys = st_sys;
	return true;
}

static void lacpd_status_exit(void)
{
	struct lacpd_status_system *st_sys;

	st_sys = __lacpd_wrapper.ubus_st_sys;
	if (st_sys) {
		st_sys->exit();
	}

	st_sys = __lacpd_wrapper.hotplug_st_sys;
	if (st_sys) {
		st_sys->exit();
	}
}

static bool lacpd_config_init(void)
{
	struct lacpd_configuration_system *cfg_sys;

	__lacpd_wrapper.cfg_user.os_service = &__lacpd_wrapper.os_service;
	__lacpd_wrapper.cfg_user.lacp_new = lacpd_cfg_lacp_new;
	__lacpd_wrapper.cfg_user.lacp_destroy = lacpd_cfg_lacp_destroy;
	__lacpd_wrapper.cfg_user.add_dev = lacpd_cfg_add_dev;
	__lacpd_wrapper.cfg_user.del_dev = lacpd_cfg_del_dev;

	cfg_sys = lacpd_cfg_sys_use("uci", &__lacpd_wrapper.cfg_user);
	if (!cfg_sys) {
		DP(WRAPPER, CRIT, "Load UCI configuration system failed");
		return false;
	}

	if (!cfg_sys->init(NULL)) {
		return false;
	}

	__lacpd_wrapper.cfg_sys = cfg_sys;
	return true;
}

static void lacpd_config_exit(void)
{
	struct lacpd_configuration_system *cfg_sys = __lacpd_wrapper.cfg_sys;
	if (cfg_sys) {
		cfg_sys->exit();
	}
}

static bool lacpd_os_service_init(void)
{
	if (GENL_OS_SERVICE_PRIVATE_DATA_SIZE < sizeof(struct uloop_fd) ||
		GENL_OS_SERVICE_PRIVATE_DATA_SIZE < sizeof(struct uloop_timeout) ||
		GENL_OS_SERVICE_PRIVATE_DATA_SIZE < sizeof(struct uloop_process)) {
		DP(WRAPPER, CRIT, "Memory for private data of general OS service is not enough");
		return false;
	}

	__lacpd_wrapper.os_service.fd_add = lacpd_wrapper_os_service_fd_add;
	__lacpd_wrapper.os_service.fd_del = lacpd_wrapper_os_service_fd_del;
	__lacpd_wrapper.os_service.timer_set = lacpd_wrapper_os_service_timer_set;
	__lacpd_wrapper.os_service.timer_cancel = lacpd_wrapper_os_service_timer_cancel;
	__lacpd_wrapper.os_service.task_add = lacpd_wrapper_os_service_task_add;
	__lacpd_wrapper.os_service.task_del = lacpd_wrapper_os_service_task_del;

	return true;
}

static void lacpd_handle_signal(int signo)
{
	uloop_end();
}

static void lacpd_setup_signals(void)
{
	struct sigaction s;

	memset(&s, 0, sizeof(s));
	s.sa_handler = lacpd_handle_signal;
	s.sa_flags = 0;
	sigaction(SIGINT, &s, NULL);
	sigaction(SIGTERM, &s, NULL);
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);

	s.sa_handler = SIG_IGN;
	sigaction(SIGPIPE, &s, NULL);
}

static void lacpd_debug_init(void)
{
	debug_mask[DBG_MOD_CONFIG] = LACPD_CONFIG_DBG_LEVEL;
	debug_mask[DBG_MOD_STATUS] = LACPD_STATUS_DBG_LEVEL;
	debug_mask[DBG_MOD_LACP] = LACPD_LACP_DBG_LEVEL;
	debug_mask[DBG_MOD_LACP_FSM] = LACPD_FSM_DBG_LEVEL;
	debug_mask[DBG_MOD_LACP_PKT] = LACPD_PKT_DBG_LEVEL;
	debug_mask[DBG_MOD_GENL_DEVICE] = LACPD_GENL_DEV_DBG_LEVEL;
	debug_mask[DBG_MOD_WRAPPER] = LACPD_WRAPPER_DBG_LEVEL;
}

int main(int argc, char **argv)
{
	qca_switch_probe();
	genl_dev_linux_probe();
	lacpd_uci_cfg_probe();
	lacpd_ubus_status_system_probe();
	lacpd_hotplug_status_system_probe();

	lacpd_debug_init();

	if (!lacpd_os_service_init()) {
		return -1;
	}

	lacpd_setup_signals();

	uloop_init();

	INIT_LIST_HEAD(&__lacpd_wrapper.wrappers);

	genl_dev_init(&__lacpd_wrapper.os_service);

	if (!lacpd_config_init()) {
		DP(WRAPPER, CRIT, "Initialize configuration system failed");
		goto lacpd_error_exit;
	}

	if (!lacpd_status_init()) {
		DP(WRAPPER, CRIT, "Initialize status system failed");
		goto lacpd_error_exit;
	}

	uloop_run();

lacpd_error_exit:

	lacpd_wrapper_cleanup();

	/*
	 * Some tasks/timers may be added when clean up,
	 * so we wait them for half second to shutdown gracefully.
	 */
	lacpd_shutdown_delay(500);

	lacpd_config_exit();

	lacpd_status_exit();

	uloop_done();

	return 0;
}
