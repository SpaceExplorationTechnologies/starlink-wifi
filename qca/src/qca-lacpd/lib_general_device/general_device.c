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

#include "general_device_api.h"

struct genl_os_service *current_os_service;
struct general_device_system *ndev_systems[GENERAL_DEVICE_SYSTEM_MAX_DOMAIN];

/*
 * genl_dev_alloc_domain: find a free slot in 'ndev_systems'
 */
static bool genl_dev_alloc_domain(struct general_device_system *system_obj)
{
	int idx;

	if (!strncmp(system_obj->name, "linux", sizeof(system_obj->name))) {
		system_obj->domain = 0;
		system_obj->next_internal_domain = 0;
		return true;
	}

	if ((system_obj->domain > 0) && (system_obj->domain < GENERAL_DEVICE_SYSTEM_MAX_DOMAIN) && !ndev_systems[system_obj->domain]) {
		if (!system_obj->next_internal_domain) {
			system_obj->next_internal_domain = GENERAL_DEVICE_SYSTEM_INIT_INTERNAL_DOMAIN;
		}

		return true;
	}

	for (idx = 0; idx < GENERAL_DEVICE_SYSTEM_MAX_DOMAIN; idx++) {
		if (!ndev_systems[idx]) {
			system_obj->domain = idx;

			if (!system_obj->next_internal_domain) {
				system_obj->next_internal_domain = GENERAL_DEVICE_SYSTEM_INIT_INTERNAL_DOMAIN;
			}

			return true;
		}
	}

	return false;
}

/*
 * genl_dev_sys_lookup: lookup network device system by its name
 */
static struct general_device_system *genl_dev_sys_lookup(const char *dev_sys_name)
{
	struct general_device_system *dev_sys;
	int idx;

	if (!dev_sys_name) {
		return NULL;
	}

	for (idx = 0; idx < GENERAL_DEVICE_SYSTEM_MAX_DOMAIN; idx++) {
		if (NULL == (dev_sys = ndev_systems[idx])) {
			continue;
		}

		if (!strncmp(dev_sys_name, dev_sys->name, sizeof(dev_sys->name))) {
			return dev_sys;
		}
	}

	DP(GENL_DEVICE, DEBUG, "network device system %s not found", dev_sys_name);
	return NULL;
}

/*
 * APIs for upper layer above general device, start
 */

/*
 * genl_dev_init: initialize general device sub module
 * 	os_service: operate system service provided by wrapper
 * 	return value: successful or fail
 */
bool genl_dev_init(struct genl_os_service *os_service)
{
	struct general_device_system *dev_sys;
	int idx;

	current_os_service = os_service;

	for (idx = 0; idx < GENERAL_DEVICE_SYSTEM_MAX_DOMAIN; idx++) {
		if (NULL == (dev_sys = ndev_systems[idx])) {
			continue;
		}

		dev_sys->init(dev_sys);
	}

	return true;
}

/*
 * genl_dev_sys_resolve_by_name: resolve device system of a device by its name
 * 	Normally this will call dev_sys->common->name_to_netdev_obj() to check if a device system
 * 	is aware of this device.
 */
struct general_device_system *genl_dev_sys_resolve_by_name(const char *netdev_name)
{
	return genl_dev_sys_resolve_by_obj(genl_dev_name_to_netdev_obj(netdev_name));
}

/*
 * genl_dev_sys_resolve_by_obj: resolve device system of a device by its object
 * 	Normally this will call dev_sys->common->is_compatible() to check if a device system
 * 	is aware of this device.
 */
struct general_device_system *genl_dev_sys_resolve_by_obj(uint32_t netdev_obj)
{
	struct general_device_system *dev_sys;

	if (netdev_obj_is_invalid(netdev_obj)) {
		return NULL;
	}

	dev_sys = ndev_systems[netdev_obj_to_domain(netdev_obj)];
	if (dev_sys->common.is_compatible(dev_sys, netdev_obj)) {
			return dev_sys;
	}

	return NULL;
}

/*
 * genl_dev_sys_add_user: add user of generic network device module
 * dev_sys_name: name of device system which user want to use
 * genl_dev_user: APIs to talk with user of generic network device module
 * return value: true: successful, false: failed
 */
bool genl_dev_sys_add_user(char *dev_sys_name, struct general_device_out_api *genl_dev_user)
{
	struct general_device_system *dev_sys;
	struct general_device_out_api *dev_sys_user;

	if (!genl_dev_user) {
		return false;
	}

	dev_sys = genl_dev_sys_lookup(dev_sys_name);
	if (!dev_sys) {
		return false;
	}

	list_for_each_entry(dev_sys_user, &dev_sys->users, node) {
		if (dev_sys_user == genl_dev_user) {
			/*Already added*/
			return true;
		}
	}

	list_add_tail(&genl_dev_user->node, &dev_sys->users);
	return true;
}

/*
 * genl_dev_sys_del_user: delete user of generic network device module
 * dev_sys_name: name of device system which user want to delete
 * genl_dev_user: APIs to talk with user of generic network device module
 */
void genl_dev_sys_del_user(char *dev_sys_name, struct general_device_out_api *genl_dev_user)
{
	struct general_device_system *dev_sys;
	struct general_device_out_api *dev_sys_user, *temp;

	if (!genl_dev_user) {
		return;
	}

	dev_sys = genl_dev_sys_lookup(dev_sys_name);
	if (!dev_sys) {
		return;
	}

	list_for_each_entry_safe(dev_sys_user, temp, &dev_sys->users, node) {
		if (dev_sys_user == genl_dev_user) {
			list_del(&genl_dev_user->node);
			return;
		}
	}
}

/*
 * genl_dev_name_to_netdev_obj: returns network device according to name of network device
 */
uint32_t genl_dev_name_to_netdev_obj(const char *netdev_name)
{
	struct general_device_system *dev_sys;
	uint32_t netdev_obj;
	int idx;

	if (!netdev_name) {
		return GENERAL_DEVICE_INVALID_ID;
	}

	for (idx = 0; idx < GENERAL_DEVICE_SYSTEM_MAX_DOMAIN; idx++) {
		if (NULL == (dev_sys = ndev_systems[idx])) {
			continue;
		}

		netdev_obj = dev_sys->common.name_to_netdev_obj(dev_sys, netdev_name);
		if (!netdev_obj_is_invalid(netdev_obj)) {
			return netdev_obj;
		}
	}

	return GENERAL_DEVICE_INVALID_ID;
}

/*
 * genl_dev_netdev_obj_to_name: returns name of network device
 */
char *genl_dev_netdev_obj_to_name(uint32_t netdev_obj, char *netdev_name)
{
	struct general_device_system *dev_sys;

	dev_sys = genl_dev_sys_resolve_by_obj(netdev_obj);
	if (!dev_sys) {
		DP(GENL_DEVICE, DEBUG, "Can't resolve device system for %d", netdev_obj);
		return NULL;
	}

	return dev_sys->common.netdev_obj_to_name(dev_sys, netdev_obj, netdev_name);
}

/*
 * genl_dev_get_link_status : get link status of network device
 * netdev_obj: network device
 * return value: true: link up; false: link down
 */
bool genl_dev_get_link_status(uint32_t netdev_obj)
{
	struct general_device_system *dev_sys;

	dev_sys = genl_dev_sys_resolve_by_obj(netdev_obj);
	if (!dev_sys) {
		DP(GENL_DEVICE, DEBUG, "Can't resolve device system for %d", netdev_obj);
		return false;
	}

	return dev_sys->common.get_link_status(dev_sys, netdev_obj);
}

/*
 * genl_dev_get_duplex : get duplex of network device
 * netdev_obj: network device
 * return value: 1: full duplex, 0: half duplex
 */
uint32_t genl_dev_get_duplex(uint32_t netdev_obj)
{
	struct general_device_system *dev_sys;

	dev_sys = genl_dev_sys_resolve_by_obj(netdev_obj);
	if (!dev_sys) {
		DP(GENL_DEVICE, DEBUG, "Can't resolve device system for %d", netdev_obj);
		return 0;
	}

	return dev_sys->common.get_duplex(dev_sys, netdev_obj);
}

/*
 * genl_dev_get_speed : get speed of network device
 * netdev_obj: network device
 * return value: 0: invalid, 1: 1Mbps, 10: 10Mbps, 100: 100Mbps, 1000: 1Gbps, 10000: 10Gbps
 */
uint32_t genl_dev_get_speed(uint32_t netdev_obj)
{
	struct general_device_system *dev_sys;

	dev_sys = genl_dev_sys_resolve_by_obj(netdev_obj);
	if (!dev_sys) {
		DP(GENL_DEVICE, DEBUG, "Can't resolve device system for %d", netdev_obj);
		return 0;
	}

	return dev_sys->common.get_speed(dev_sys, netdev_obj);
}

/*
 * genl_dev_get_hw_addr : get hardware address of network device
 * netdev_obj: network device
 * hw_addr: returned hw address of network device, max size is 6 bytes
 * return value: successful or fail
 */
bool genl_dev_get_hw_addr(uint32_t netdev_obj, uint8_t *hw_addr)
{
	struct general_device_system *dev_sys;

	dev_sys = genl_dev_sys_resolve_by_obj(netdev_obj);
	if (!dev_sys) {
		DP(GENL_DEVICE, DEBUG, "Can't resolve device system for %d", netdev_obj);
		return false;
	}

	return dev_sys->common.get_hw_addr(dev_sys, netdev_obj, hw_addr);
}

/*
 * genl_dev_is_bridge_member : check if a port is in a bridge
 * port_dev_obj: port
 * br_dev_obj: bridge
 * return value: true: is a bridge member, false: not a bridge member
 */
bool genl_dev_is_bridge_member(uint32_t port_dev_obj, uint32_t br_dev_obj)
{
	struct general_device_system *dev_sys = genl_dev_sys_resolve_by_obj(port_dev_obj);
	if (!dev_sys) {
		DP(GENL_DEVICE, DEBUG, "Can't resolve device system for %d", port_dev_obj);
		return false;
	}

	return dev_sys->bridge.is_bridge_member(dev_sys, port_dev_obj, br_dev_obj);
}

/*
 * genl_dev_flush_fdb : flush all FDB learned on bridge port
 * port_dev_obj: FDB learned on this port should be flushed,
 * 				 it could be index of bridge, then it means flush all FDB in bridge
 * return value: true: successful, false: failed
 */
bool genl_dev_flush_fdb(uint32_t port_dev_obj)
{
	struct general_device_system *dev_sys = genl_dev_sys_resolve_by_obj(port_dev_obj);
	if (!dev_sys) {
		DP(GENL_DEVICE, DEBUG, "Can't resolve device system for %d", port_dev_obj);
		return false;
	}

	return dev_sys->bridge.flush_fdb(dev_sys, port_dev_obj);
}

/*
 * APIs for upper layer above general device, end
 */
/*
 * APIs for lower layer below general device, start
 */

/*
 * genl_dev_link_status_changed : notify link status event of physical network device
 * dev_sys: device system
 * netdev_obj: network device where event happen
 * new_status: new link status of device
 */
void genl_dev_link_status_changed(struct general_device_system *dev_sys, uint32_t netdev_obj, int new_status)
{
	struct general_device_out_api *dev_sys_user;

	list_for_each_entry(dev_sys_user, &dev_sys->users, node) {
		if (dev_sys_user->link_status_changed) {
			dev_sys_user->link_status_changed(dev_sys_user, netdev_obj, new_status);
		}
	}
}

/*
 * genl_dev_notify_netdev_obj_added : notify creation event of physical network device
 * dev_sys: device system
 * netdev_obj: network device where event happen
 */
void genl_dev_notify_netdev_obj_added(struct general_device_system *dev_sys, uint32_t netdev_obj)
{
	struct general_device_out_api *dev_sys_user;

	list_for_each_entry(dev_sys_user, &dev_sys->users, node) {
		if (dev_sys_user->netdev_obj_added) {
			dev_sys_user->netdev_obj_added(dev_sys_user, netdev_obj);
		}
	}
}

/*
 * genl_dev_notify_netdev_obj_deleted : notify destroy event of physical network device
 * dev_sys: device system
 * netdev_obj: network device where event happen
 */
void genl_dev_notify_netdev_obj_deleted(struct general_device_system *dev_sys, uint32_t netdev_obj)
{
	struct general_device_out_api *dev_sys_user;

	list_for_each_entry(dev_sys_user, &dev_sys->users, node) {
		if (dev_sys_user->netdev_obj_deleted) {
			dev_sys_user->netdev_obj_deleted(dev_sys_user, netdev_obj);
		}
	}
}

/*
 * genl_dev_recv_bpdu: receive BPDU from lower device system
 * dev_sys: device system
 * netdev_obj: receiving network device
 * buf: packet
 * buf_len: length of packet
 * return value: packet is consumed or not
 */
bool genl_dev_recv_bpdu(struct general_device_system *dev_sys, uint32_t netdev_obj, uint8_t *buf, uint32_t buf_len)
{
	struct general_device_out_api *dev_sys_user;
	bool ret;

	list_for_each_entry(dev_sys_user, &dev_sys->users, node) {
		if (dev_sys_user->receive_bpdu) {
			ret = dev_sys_user->receive_bpdu(dev_sys_user, buf, buf_len, netdev_obj);
			if (ret) {
				return true;
			}
		}
	}

	return true;
}

/*
 * genl_dev_recv_lacpdu: receive LACPDU from lower device system
 * dev_sys: device system
 * netdev_obj: receiving network device
 * buf: packet
 * buf_len: length of packet
 * return value: packet is consumed or not
 */
bool genl_dev_recv_lacpdu(struct general_device_system *dev_sys, uint32_t netdev_obj, uint8_t *buf, uint32_t buf_len)
{
	struct general_device_out_api *dev_sys_user;
	bool ret;

	list_for_each_entry(dev_sys_user, &dev_sys->users, node) {
		if (dev_sys_user->receive_lacpdu) {
			ret = dev_sys_user->receive_lacpdu(dev_sys_user, buf, buf_len, netdev_obj);
			if (ret) {
				return true;
			}
		}
	}

	return true;
}

/*
 * genl_dev_os_service_get: get operate system service provided by wrapper
 * 	return value: operate system service or NULL
 */
struct genl_os_service *genl_dev_os_service_get(void)
{
	return current_os_service;
}

/*
 * genl_dev_alloc_netdev_obj_domain: allocate a magic prefix for index of network device
 * Linux network device system should not use this API because it is always the first device systems
 */
uint32_t genl_dev_alloc_netdev_obj_domain(struct general_device_system *system_obj, uint32_t max_devices)
{
	if (max_devices > 0xffff) {
		return GENERAL_DEVICE_INVALID_ID;
	}

	if (system_obj->next_internal_domain > 0xff) {
		return GENERAL_DEVICE_INVALID_ID;
	}

	++system_obj->next_internal_domain;
	return ((system_obj->domain << 24) | (system_obj->next_internal_domain << 16));
}

/*
 * genl_dev_system_register: register a general device system
 */
bool genl_dev_system_register(struct general_device_system *system_obj)
{
	if (!system_obj) {
		return false;
	}

	if (genl_dev_sys_lookup(system_obj->name)) {
		DP(GENL_DEVICE, DEBUG, "Network device system %s already registered", system_obj->name);
		return true;
	}

	if (!genl_dev_alloc_domain(system_obj)) {
		DP(GENL_DEVICE, CRIT, "No available domain");
		return false;
	}

	INIT_LIST_HEAD(&system_obj->users);
	ndev_systems[system_obj->domain] = system_obj;

	return true;
}

/*
 * genl_dev_system_unregister: unregister a general device system
 */
void genl_dev_system_unregister(struct general_device_system *system_obj)
{
	struct general_device_out_api *dev_sys_user, *temp;

	if (!system_obj) {
		return;
	}

	if (!genl_dev_sys_lookup(system_obj->name)) {
		DP(GENL_DEVICE, DEBUG, "Network device system %s not registered", system_obj->name);
		return;
	}

	list_for_each_entry_safe(dev_sys_user, temp, &system_obj->users, node) {
		list_del(&dev_sys_user->node);
		dev_sys_user->system_unregistered(dev_sys_user);
	}

	INIT_LIST_HEAD(&system_obj->users);
	ndev_systems[system_obj->domain] = NULL;
}

/*
 * APIs for lower layer below general device, end
 */
