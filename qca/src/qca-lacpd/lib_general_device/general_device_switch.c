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
#include "general_device_switch.h"
/*
 * Utilities start
 */
/*
 *Internal function declaration, start
 */
static uint32_t genl_dev_sw_port_name_to_netdev_obj(struct general_device_system *system_obj, const char *netdev_name);
static bool genl_dev_sw_port_detach_slave(struct general_device_system *system_obj, uint32_t master_dev_obj, uint32_t slave_dev_obj);
/*
 *Internal function declaration, end
 */
/*
 * genl_dev_sw_port_lookup: lookup switch port by its index
 */
struct switch_port *genl_dev_sw_port_lookup(struct general_device_switch_system *sw_sys, uint32_t netdev_obj)
{
	struct switch_port *port, *slave;

	if (netdev_obj_is_invalid(netdev_obj)) {
		return NULL;
	}

	list_for_each_entry(port, &sw_sys->switch_ports, node) {
		if (port->switch_port_obj == netdev_obj) {
			return port;
		}

		if (switch_port_is_aggregator(port)) {
			list_for_each_entry(slave, &port->agg_slaves, node) {
				if (slave->switch_port_obj == netdev_obj) {
					return slave;
				}
			}
		}
	}

	return NULL;
}

/*
 * genl_dev_sw_port_del: delete switch port.
 */
static bool genl_dev_sw_port_del(struct general_device_switch_system *sw_sys, struct switch_port *port)
{
	if (!sw_sys || !port) {
		return false;
	}

	if (genl_dev_sw_port_lookup(sw_sys, port->switch_port_obj)) {
		list_del(&port->node);
	}

	if (port->agg_parent) {
		if (!port->agg_parent->sw_sys->real_agg_dev) {
			port->agg_parent->port_num &= ~(1 << port->port_num);
		}
		port->agg_parent = NULL;
	}

	return true;
}

/*
 * genl_dev_sw_port_add: add switch port. if master not NULL, remove switch port firstly, then add it as slave of master
 */
static bool genl_dev_sw_port_add(struct general_device_switch_system *sw_sys, struct switch_port *port, struct switch_port *master)
{
	if (!genl_dev_sw_port_del(sw_sys, port)) {
		return false;
	}

	if (master) {
		port->agg_parent = master;

		if (!master->sw_sys->real_agg_dev) {
			master->port_num |= (1 << port->port_num);
		}

		list_add_tail(&port->node, &master->agg_slaves);
	} else {
		port->agg_parent = NULL;
		list_add_tail(&port->node, &sw_sys->switch_ports);
	}

	return true;
}

/*
 * genl_dev_sw_port_create: create a switch port, it may be a normal switch port or an aggregator
 * sw_sys: switch system
 * port_name: port name
 * port_num: mapped switch hardware port number, it's a bitmap of member ports if create an aggregator
 * switch_port_obj: index of network device
 * ctrl_channel: control channel of switch port, may be NULL if create an aggregator
 * data_channel: data channel of switch port, may be NULL if create an aggregator
 * return value: created switch port or NULL
 */
struct switch_port *genl_dev_sw_port_create(struct general_device_switch_system *sw_sys, const char *port_name, uint32_t port_num,
											uint32_t switch_port_obj, const char *ctrl_channel, const char *data_channel)
{
	struct switch_port *port;
	uint32_t netdev_obj;

	netdev_obj = genl_dev_sw_port_name_to_netdev_obj(&sw_sys->base, port_name);
	if (!netdev_obj_is_invalid(netdev_obj)) {
		DP(GENL_DEVICE, CRIT, "switch port %s already created", port_name);
		return NULL;
	}

	if (genl_dev_sw_port_lookup(sw_sys, switch_port_obj)) {
		DP(GENL_DEVICE, DEBUG, "switch port %d already created", switch_port_obj);
		return NULL;
	}

	port = (struct switch_port *)calloc(1, sizeof(struct switch_port));
	if (!port) {
		DP(GENL_DEVICE, CRIT, "Allocate memory for QCA switch port %s failed", port_name);
		return NULL;
	}

	INIT_LIST_HEAD(&port->agg_slaves);
	snprintf(port->name, sizeof(port->name), "%s", port_name);
	port->port_num = port_num;
	port->switch_port_obj = switch_port_obj;
	port->sw_sys = sw_sys;

	if (ctrl_channel) {
		snprintf(port->control_channel, sizeof(port->control_channel), "%s", ctrl_channel);
	}

	if (data_channel) {
		snprintf(port->data_channel, sizeof(port->data_channel), "%s", data_channel);
	}

	if (ctrl_channel && data_channel) {
		if (!strncmp(port->control_channel, port->data_channel, sizeof(port->control_channel))) {
			port->type = SWITCH_PORT_TYPE_HIDDEN;
		} else {
			port->type = SWITCH_PORT_TYPE_EXPORTED;
		}
	}

	genl_dev_sw_port_add(sw_sys, port, NULL);

	/*
	 * Notify network device add event
	 */
	genl_dev_notify_netdev_obj_added(&sw_sys->base, port->switch_port_obj);

	return port;
}

/*
 * genl_dev_sw_link_status_update: handler of timer "struct general_device_switch_system -> link_status_monitor"
 */
static void genl_dev_sw_link_status_update(struct genl_os_service_timer *timer)
{
	struct general_device_switch_system *sw_sys = (struct general_device_switch_system *)timer->arg;
	struct genl_os_service *os_service = genl_dev_os_service_get();
	struct switch_port *port, *slave;
	bool new_link_status, slave_new_link_status;

	list_for_each_entry(port, &sw_sys->switch_ports, node) {
		if (switch_port_is_aggregator(port) && (!sw_sys->real_agg_dev)) {
			new_link_status = false;
			list_for_each_entry(slave, &port->agg_slaves, node) {
				slave_new_link_status = sw_sys->ops.common.get_link_status(slave);
				if (slave_new_link_status != slave->link_status){
					slave->link_status = slave_new_link_status;
					genl_dev_sw_port_link_status_changed(sw_sys, slave, slave->link_status);
				}

				new_link_status = new_link_status || slave->link_status;
			}
		} else {
			new_link_status = sw_sys->ops.common.get_link_status(port);
		}

		if (new_link_status != port->link_status){
			port->link_status = new_link_status;
			genl_dev_sw_port_link_status_changed(sw_sys, port, port->link_status);
		}
	}

	os_service->timer_set(&sw_sys->link_status_monitor, sw_sys->link_status_poll_interval);
}

/*
 * Utilities end
 */
/*
 * APIs for upper layer above switch system, start
 */
/*
 * genl_dev_sw_init : initialize network device system when it is attached to a specific OS
 * system_obj: network device system
 * return value: true: successful, false: failed
 */
static bool genl_dev_sw_init(struct general_device_system *system_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct genl_os_service *os_service;

	if (!sw_sys->support_link_event) {
		os_service = genl_dev_os_service_get();

		sw_sys->link_status_monitor.cb = genl_dev_sw_link_status_update;
		sw_sys->link_status_monitor.arg = (void *)sw_sys;
		sw_sys->link_status_monitor.msecs = sw_sys->link_status_poll_interval;

		os_service->timer_set(&sw_sys->link_status_monitor, sw_sys->link_status_poll_interval);
	}

	return sw_sys->ops.init(sw_sys);
}

/*
 * genl_dev_sw_exit : finalize network device system when it is detached from a specific OS
 * system_obj: network device system
 * return value: true: successful, false: failed
 */
static bool genl_dev_sw_exit(struct general_device_system *system_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct genl_os_service *os_service;

	if (!sw_sys->support_link_event) {
		os_service = genl_dev_os_service_get();

		os_service->timer_cancel(&sw_sys->link_status_monitor);
	}

	return sw_sys->ops.exit(sw_sys);
}

/*
 * genl_dev_sw_private : if internal operation is understanded by switch port layer, do it. Otherwise, pass it to lower driver
 * system_obj: network device system
 * func_id: identifier of operation
 * input_arg: input argument
 * output_arg: output argument
 * return value: true: successful, false: failed
 */
static bool genl_dev_sw_private(struct general_device_system *system_obj, uint32_t func_id, void *input_arg, void *output_arg)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);

	return (NULL != sw_sys->ops.private) ? (sw_sys->ops.private(sw_sys, func_id, input_arg, output_arg)) : false;
}

/*
 * genl_dev_sw_get_hw_addr : get hardware address of system
 * system_obj: network device system
 * mac_addr: returned MAC address of system
 * return value: successful or fail
 */
static bool genl_dev_sw_get_hw_addr(struct general_device_system *system_obj, uint8_t *mac_addr)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port, *lowest_port, *slave;

	if (sw_sys->ops.system.get_hw_addr) {
		return sw_sys->ops.system.get_hw_addr(sw_sys, mac_addr);
	}

	lowest_port = NULL;
	list_for_each_entry(port, &sw_sys->switch_ports, node) {
		if (switch_port_is_aggregator(port)) {
			list_for_each_entry(slave, &port->agg_slaves, node) {
				if ((lowest_port == NULL) || (slave->port_num < lowest_port->port_num)) {
					lowest_port = slave;
				}
			}
		} else if ((lowest_port == NULL) || (port->port_num < lowest_port->port_num)) {
			lowest_port = port;
		}
	}

	if (!lowest_port) {
		DP(GENL_DEVICE, DEBUG, "No switch port in device system %s", system_obj->name);
		return false;
	}

	return genl_dev_get_hw_addr(genl_dev_name_to_netdev_obj(lowest_port->control_channel), mac_addr);
}

/*
 * genl_dev_sw_port_is_compatible: check if a device belongs to this type of device
 */
static bool genl_dev_sw_port_is_compatible(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);

	return (NULL != genl_dev_sw_port_lookup(sw_sys, netdev_obj));
}

/*
 * genl_dev_sw_port_name_to_netdev_obj: returns network device according to name of network device
 */
static uint32_t genl_dev_sw_port_name_to_netdev_obj(struct general_device_system *system_obj, const char *netdev_name)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port, *slave;

	if (!netdev_name) {
		return GENERAL_DEVICE_INVALID_ID;
	}

	list_for_each_entry(port, &sw_sys->switch_ports, node) {
		if (!strncmp(port->name, netdev_name, sizeof(port->name))) {
			return port->switch_port_obj;
		}

		if (switch_port_is_aggregator(port)) {
			list_for_each_entry(slave, &port->agg_slaves, node) {
				if (!strncmp(slave->name, netdev_name, sizeof(slave->name))) {
					return slave->switch_port_obj;
				}
			}
		}
	}

	return GENERAL_DEVICE_INVALID_ID;
}

/*
 * genl_dev_sw_port_netdev_obj_to_name: returns name of network device
 */
static char *genl_dev_sw_port_netdev_obj_to_name(struct general_device_system *system_obj, uint32_t netdev_obj, char *netdev_name)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port;

	port = genl_dev_sw_port_lookup(sw_sys, netdev_obj);
	if (!port) {
		return NULL;
	}

	if (netdev_name) {
		snprintf(netdev_name, GENERAL_DEVICE_SYSTEM_NAME_SIZE, "%s", port->name);
		return netdev_name;
	}

	return port->name;
}

/*
 * genl_dev_sw_port_get_link_status : get link status of network device
 * system_obj: network device system
 * netdev_obj: network device
 * return value: true: link up; false: link down
 */
static bool genl_dev_sw_port_get_link_status(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, netdev_obj);
	struct switch_port *slave;

	if (!port) {
		return false;
	}

	if (switch_port_is_aggregator(port) && (!sw_sys->real_agg_dev)) {
		list_for_each_entry(slave, &port->agg_slaves, node) {
			if (sw_sys->ops.common.get_link_status(slave)) {
				return true;
			}
		}

		return false;
	}

	return sw_sys->ops.common.get_link_status(port);
}

/*
 * genl_dev_sw_port_get_duplex : get duplex of network device
 * system_obj: network device system
 * netdev_obj: network device
 * return value: 1: full duplex, 0: half duplex
 */
static uint32_t genl_dev_sw_port_get_duplex(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, netdev_obj);
	struct switch_port *slave;

	if (!port) {
		return 0;
	}

	if (switch_port_is_aggregator(port) && (!sw_sys->real_agg_dev)) {
		list_for_each_entry(slave, &port->agg_slaves, node) {
			return sw_sys->ops.common.get_duplex(slave);
		}

		return 0;
	}

	return sw_sys->ops.common.get_duplex(port);
}

/*
 * genl_dev_sw_port_get_speed : get speed of network device
 * system_obj: network device system
 * netdev_obj: network device
 * return value: 0: invalid, 1: 1Mbps, 10: 10Mbps, 100: 100Mbps, 1000: 1Gbps, 10000: 10Gbps
 */
static uint32_t genl_dev_sw_port_get_speed(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, netdev_obj);
	struct switch_port *slave;
	uint32_t speed = 0;

	if (!port) {
		return 0;
	}

	if (switch_port_is_aggregator(port) && (!sw_sys->real_agg_dev)) {
		list_for_each_entry(slave, &port->agg_slaves, node) {
			speed += sw_sys->ops.common.get_speed(slave);
		}

		return speed;
	}

	return sw_sys->ops.common.get_speed(port);
}

/*
 * genl_dev_sw_port_get_hw_addr : get hardware address of network device
 * system_obj: network device system
 * netdev_obj: network device
 * hw_addr: returned hw address of network device, max size is 6 bytes
 * return value: successful or fail
 */
static bool genl_dev_sw_port_get_hw_addr(struct general_device_system *system_obj, uint32_t netdev_obj, uint8_t *hw_addr)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, netdev_obj);
	struct switch_port *slave, *lowest_slave;
	bool ret;

	if (!port) {
		return false;
	}

	if (port->hwaddr_cache_valid) {
		memcpy(hw_addr, port->hwaddr_cache, 6);
		return true;
	}

	if (switch_port_is_aggregator(port) && (!sw_sys->real_agg_dev)) {
		lowest_slave = NULL;
		list_for_each_entry(slave, &port->agg_slaves, node) {
			if ((lowest_slave == NULL) || (slave->port_num < lowest_slave->port_num)) {
				lowest_slave = slave;
			}
		}

		return lowest_slave ? genl_dev_sw_port_get_hw_addr(system_obj, lowest_slave->switch_port_obj, hw_addr) : false;
	}

	if (sw_sys->ops.common.get_hw_addr) {
		ret = sw_sys->ops.common.get_hw_addr(port, hw_addr);
		goto cache_hw_addr;
	}

	if (switch_port_is_aggregator(port)) {
		DP(GENL_DEVICE, CRIT, "switch support real aggregator device, but didn't provide API to get its MAC address");
		return false;
	}

	ret = genl_dev_get_hw_addr(genl_dev_name_to_netdev_obj(port->control_channel), hw_addr);
	if (ret) {
		hw_addr[5] += port->port_num;
	}

cache_hw_addr:
	if (ret) {
		memcpy(port->hwaddr_cache, hw_addr, 6);
		port->hwaddr_cache_valid = true;
	}

	return ret;
}

/*
 * is_bridge_member : check if a port is in a bridge
 * system_obj: network device system
 * port_dev_obj: port
 * br_dev_obj: bridge
 * return value: true: is a bridge member, false: not a bridge member
 */
static bool genl_dev_sw_port_is_bridge_member(struct general_device_system *system_obj, uint32_t port_dev_obj, uint32_t br_dev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, port_dev_obj);
	struct switch_port *br = genl_dev_sw_port_lookup(sw_sys, br_dev_obj);
	uint32_t netdev_obj;

	if (!port) {
		return false;
	}

	if (switch_port_is_agg_slave(port)) {
		return false;
	}

	if (br) {
		return sw_sys->ops.bridge.is_bridge_member(port, br);
	}

	if (port->type == SWITCH_PORT_TYPE_HIDDEN) {
		netdev_obj = genl_dev_name_to_netdev_obj(port->control_channel);
	} else {
		netdev_obj = genl_dev_name_to_netdev_obj(port->data_channel);
	}

	return genl_dev_is_bridge_member(netdev_obj, br_dev_obj);
}

/*
 * genl_dev_sw_port_flush_fdb : flush all FDB learned on this port
 * system_obj: network device system
 * port_dev_obj: port, it could be index of bridge, then it means flush all FDB in bridge
 * return value: true: successful, false: failed
 */
static bool genl_dev_sw_port_flush_fdb(struct general_device_system *system_obj, uint32_t port_dev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, port_dev_obj);
	struct switch_port *slave;
	bool ret;

	if (!port) {
		return false;
	}

	if (switch_port_is_agg_slave(port)) {
		DP(GENL_DEVICE, DEBUG, "Can't operate on slave of aggregator");
		return false;
	}

	if (switch_port_is_aggregator(port) && (!sw_sys->real_agg_dev)) {
		ret = true;

		list_for_each_entry(slave, &port->agg_slaves, node) {
			ret = ret && sw_sys->ops.bridge.flush_fdb(slave);
		}

		return ret;
	}

	return sw_sys->ops.bridge.flush_fdb(port);
}

/*
 * genl_dev_sw_port_stp_enable : enable STP on port, this means STP protocol starts to run on this port
 * system_obj: network device system
 * netdev_obj: network device
 * return value: true: successful, false: failed
 */
static bool genl_dev_sw_port_stp_enable(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, netdev_obj);
	struct switch_port *slave;
	bool ret;

	if (!port) {
		return false;
	}

	if (switch_port_is_agg_slave(port)) {
		DP(GENL_DEVICE, DEBUG, "Can't operate on slave of aggregator");
		return false;
	}

	if (switch_port_is_aggregator(port) && (!sw_sys->real_agg_dev)) {
		ret = true;

		list_for_each_entry(slave, &port->agg_slaves, node) {
			ret = ret && sw_sys->ops.stp.enable(slave);
		}

		return ret;
	}

	return sw_sys->ops.stp.enable(port);
}

/*
 * genl_dev_sw_port_stp_disable : disable STP on port, this means STP protocol stops to run on this port
 * system_obj: network device system
 * netdev_obj: network device
 * return value: true: successful, false: failed
 */
static bool genl_dev_sw_port_stp_disable(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, netdev_obj);
	struct switch_port *slave;
	bool ret;

	if (!port) {
		return false;
	}

	if (switch_port_is_agg_slave(port)) {
		DP(GENL_DEVICE, DEBUG, "Can't operate on slave of aggregator");
		return false;
	}

	if (switch_port_is_aggregator(port) && (!sw_sys->real_agg_dev)) {
		ret = true;

		list_for_each_entry(slave, &port->agg_slaves, node) {
			ret = ret && sw_sys->ops.stp.disable(slave);
		}

		return ret;
	}

	return sw_sys->ops.stp.disable(port);
}

/*
 * genl_dev_sw_port_set_stp_state : set STP state of port
 * system_obj: network device system
 * netdev_obj: network device
 * state: state of port
 * return value: true: successful, false: failed
 */
static bool genl_dev_sw_port_set_stp_state(struct general_device_system *system_obj, uint32_t netdev_obj, enum general_device_stp_state state)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, netdev_obj);
	struct switch_port *slave;
	bool ret;

	if (!port) {
		return false;
	}

	if (switch_port_is_agg_slave(port)) {
		DP(GENL_DEVICE, DEBUG, "Can't operate on slave of aggregator");
		return false;
	}

	if (switch_port_is_aggregator(port) && (!sw_sys->real_agg_dev)) {
		ret = true;

		list_for_each_entry(slave, &port->agg_slaves, node) {
			ret = ret && sw_sys->ops.stp.set_port_state(slave, state);
		}

		return ret;
	}

	return sw_sys->ops.stp.set_port_state(port, state);
}

/*
 * genl_dev_sw_port_send_bpdu : send BPDU on port
 * system_obj: network device system
 * netdev_obj: network device
 * buf: buffer which contains BPDU
 * buf_len: length of above buffer
 * return value: true: successful, false: failed
 */
static bool genl_dev_sw_port_send_bpdu(struct general_device_system *system_obj, uint32_t netdev_obj, const uint8_t *buf, uint32_t buf_len)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, netdev_obj);
	struct switch_port *slave, *lowest_slave;

	if (!port) {
		return false;
	}

	if (switch_port_is_agg_slave(port)) {
		DP(GENL_DEVICE, DEBUG, "Can't operate on slave of aggregator");
		return false;
	}

	if (switch_port_is_aggregator(port) && (!sw_sys->real_agg_dev)) {
		lowest_slave = NULL;
		list_for_each_entry(slave, &port->agg_slaves, node) {
			if ((lowest_slave == NULL) || (slave->port_num < lowest_slave->port_num)) {
				lowest_slave = slave;
			}
		}

		if (!lowest_slave) {
			return false;
		} else {
			port = lowest_slave;
		}
	}

	return sw_sys->ops.stp.send_bpdu(port, buf, buf_len);
}

/*
 * genl_dev_sw_port_lacp_enable : enable LACP on port, this means LACP protocol starts to run on this port
 * system_obj: network device system
 * netdev_obj: network device
 * return value: true: successful, false: failed
 */
static bool genl_dev_sw_port_lacp_enable(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, netdev_obj);

	if (!port) {
		return false;
	}

	if (switch_port_is_aggregator(port)) {
		DP(GENL_DEVICE, DEBUG, "Can't enable LACP on aggregator");
		return false;
	}

	return sw_sys->ops.agg.enable(port);
}

/*
 * genl_dev_sw_port_lacp_disable : disable LACP on port, this means LACP protocol stops to run on this port
 * system_obj: network device system
 * netdev_obj: network device
 * return value: true: successful, false: failed
 */
static bool genl_dev_sw_port_lacp_disable(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, netdev_obj);

	if (!port) {
		return false;
	}

	if (switch_port_is_aggregator(port)) {
		DP(GENL_DEVICE, DEBUG, "Can't disable LACP on aggregator");
		return false;
	}

	return sw_sys->ops.agg.disable(port);
}

/*
 * genl_dev_sw_new_aggregator : create physical network device for aggregator
 * system_obj: network device system
 * agg_name: name of aggregator, length of name is less 64
 * return value: network device object for new aggregator
 */
static uint32_t genl_dev_sw_new_aggregator(struct general_device_system *system_obj, const char *agg_name)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port;

	if (genl_dev_sw_port_name_to_netdev_obj(system_obj, agg_name)) {
		DP(GENL_DEVICE, DEBUG, "Aggregator %s already exist", agg_name);
		return GENERAL_DEVICE_INVALID_ID;
	}

	port = (struct switch_port *)calloc(1, sizeof(struct switch_port));
	if (!port) {
		DP(GENL_DEVICE, CRIT, "Allocate aggregator %s failed", agg_name);
		return GENERAL_DEVICE_INVALID_ID;
	}

	INIT_LIST_HEAD(&port->agg_slaves);
	snprintf(port->name, sizeof(port->name), "%s", agg_name);
	port->sw_sys = sw_sys;

	if (!sw_sys->ops.agg.new_aggregator(port)) {
		DP(GENL_DEVICE, CRIT, "Failed to create aggregator %s", agg_name);
		free(port);
		return GENERAL_DEVICE_INVALID_ID;
	}

	genl_dev_sw_port_add(sw_sys, port, NULL);

	/*
	 * Notify network device add event
	 */
	genl_dev_notify_netdev_obj_added(system_obj, port->switch_port_obj);

	return port->switch_port_obj;
}

/*
 * genl_dev_sw_destroy_aggregator : destroy physical network device of aggregator
 * system_obj: network device system
 * aggregator_dev_obj: network device for aggregator
 * return value: successful or fail
 */
static bool genl_dev_sw_destroy_aggregator(struct general_device_system *system_obj, uint32_t aggregator_dev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, aggregator_dev_obj);
	struct switch_port *slave, *temp;

	if (!port) {
		return false;
	}

	if (!switch_port_is_aggregator(port)) {
		DP(GENL_DEVICE, DEBUG, "Port to destroy is not an aggregator");
		return false;
	}

	/*
	 * Notify network device delete event
	 */
	genl_dev_notify_netdev_obj_deleted(system_obj, port->switch_port_obj);

	list_for_each_entry_safe(slave, temp, &port->agg_slaves, node) {
		genl_dev_sw_port_detach_slave(system_obj, port->switch_port_obj, slave->switch_port_obj);
	}

	if (!list_empty(&port->agg_slaves)) {
		DP(GENL_DEVICE, DEBUG, "Slaves in aggregator can't be cleared");
		return false;
	}

	if (!sw_sys->ops.agg.destroy_aggregator(port)){
		DP(GENL_DEVICE, DEBUG, "Can't destroy aggregator in specific switch system");
		return false;
	}

	genl_dev_sw_port_del(sw_sys, port);
	free(port);
	return true;
}

/*
 * genl_dev_sw_port_is_aggregator : check if a network device is an aggregator of another network device
 * system_obj: network device system
 * master_dev_obj: network device for aggregator
 * slave_dev_obj: network device for port in aggregator, could be 0
 * return value: successful or fail
 */
static bool genl_dev_sw_port_is_aggregator(struct general_device_system *system_obj, uint32_t master_dev_obj, uint32_t slave_dev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *master = genl_dev_sw_port_lookup(sw_sys, master_dev_obj);
	struct switch_port *slave = genl_dev_sw_port_lookup(sw_sys, slave_dev_obj);

	if (!master || !switch_port_is_aggregator(master)) {
		return false;
	}

	if (slave_dev_obj && !slave) {
		return false;
	}

	if(sw_sys->real_agg_dev && sw_sys->ops.agg.is_aggregator) {
		return sw_sys->ops.agg.is_aggregator(master, slave);
	}

	return slave_dev_obj ? (slave->agg_parent == master) : true;
}

/*
 * genl_dev_sw_port_is_slave : check if a network device is a slave of another network device
 * system_obj: network device system
 * slave_dev_obj: network device for port in aggregator
 * master_dev_obj: network device for aggregator, could be 0
 * return value: is a slave or not a slave
 */
static bool genl_dev_sw_port_is_slave(struct general_device_system *system_obj, uint32_t slave_dev_obj, uint32_t master_dev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *master = genl_dev_sw_port_lookup(sw_sys, master_dev_obj);
	struct switch_port *slave = genl_dev_sw_port_lookup(sw_sys, slave_dev_obj);

	if (!slave || !switch_port_is_agg_slave(slave)) {
		return false;
	}

	if (master_dev_obj && !master) {
		return false;
	}

	if(sw_sys->real_agg_dev && sw_sys->ops.agg.is_slave) {
		return sw_sys->ops.agg.is_slave(slave, master);
	}

	return master_dev_obj ? (slave->agg_parent == master) : true;
}

/*
 * genl_dev_sw_port_number_of_slaves : number of slave network devices of a master network device
 * system_obj: network device system
 * master_dev_obj: network device for aggregator
 * return value: number of slaves
 */
static uint32_t genl_dev_sw_port_number_of_slaves(struct general_device_system *system_obj, uint32_t master_dev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, master_dev_obj);
	struct switch_port *slave;
	uint32_t slaves_cnt = 0;

	if (!port) {
		return 0;
	}

	if (!switch_port_is_aggregator(port)) {
		return 0;
	}

	if(sw_sys->real_agg_dev && sw_sys->ops.agg.number_of_slaves) {
		return sw_sys->ops.agg.number_of_slaves(port);
	}

	list_for_each_entry(slave, &port->agg_slaves, node) {
		++slaves_cnt;
	}

	return slaves_cnt;
}

/*
 * genl_dev_sw_port_attach_slave : attach a slave network device to a master network device
 * system_obj: network device system
 * master_dev_obj: network device for aggregator
 * slave_dev_obj: network device for port in aggregator
 * return value: successful or fail
 */
static bool genl_dev_sw_port_attach_slave(struct general_device_system *system_obj, uint32_t master_dev_obj, uint32_t slave_dev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *master = genl_dev_sw_port_lookup(sw_sys, master_dev_obj);
	struct switch_port *slave = genl_dev_sw_port_lookup(sw_sys, slave_dev_obj);
	bool ret, is_slave_before_attach = false;

	if (!master || !slave) {
		return false;
	}

	if (!switch_port_is_aggregator(master)) {
		return false;
	}

	if (switch_port_is_agg_slave(slave)) {
		if (slave->agg_parent == master) {
			return true;
		}

		if (!genl_dev_sw_port_detach_slave(system_obj, slave->agg_parent->switch_port_obj, slave->switch_port_obj)){
			return false;
		}

		is_slave_before_attach = true;
	}

	if (!sw_sys->ops.agg.attach_slave(master, slave)) {
		DP(GENL_DEVICE, DEBUG, "Attaching %s to %s failed", slave->name, master->name);
		return false;
	}

	if (!sw_sys->real_agg_dev && list_empty(&master->agg_slaves)) {
		master->type = slave->type;
		memcpy(master->control_channel, slave->control_channel, sizeof(master->control_channel));
		memcpy(master->data_channel, slave->data_channel, sizeof(master->data_channel));
		master->port_num = 0;
		master->hwaddr_cache_valid = false;
		memset(master->hwaddr_cache, 0, sizeof(master->hwaddr_cache));
	}

	ret = genl_dev_sw_port_add(sw_sys, slave, master);
	if (ret && !is_slave_before_attach) {
		/*
		 * Notify network device delete event
		 */
		genl_dev_notify_netdev_obj_deleted(system_obj, slave->switch_port_obj);
	}

	return ret;
}

/*
 * genl_dev_sw_port_detach_slave : detach a slave network device from a master network device
 * system_obj: network device system
 * master_dev_obj: network device for aggregator
 * slave_dev_obj: network device for port in aggregator
 * return value: successful or fail
 */
static bool genl_dev_sw_port_detach_slave(struct general_device_system *system_obj, uint32_t master_dev_obj, uint32_t slave_dev_obj)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *master = genl_dev_sw_port_lookup(sw_sys, master_dev_obj);
	struct switch_port *slave = genl_dev_sw_port_lookup(sw_sys, slave_dev_obj);

	if (!master || !slave) {
		return false;
	}

	if (!switch_port_is_aggregator(master) || !switch_port_is_agg_slave(slave)) {
		return false;
	}

	if (slave->agg_parent != master) {
		return false;
	}

	if (!sw_sys->ops.agg.detach_slave(master, slave)) {
		DP(GENL_DEVICE, DEBUG, "Detaching %s from %s failed", slave->name, master->name);
		return false;
	}

	genl_dev_sw_port_add(sw_sys, slave, NULL);

	if (!sw_sys->real_agg_dev && list_empty(&master->agg_slaves)) {
		master->type = SWITCH_PORT_TYPE_HIDDEN;
		memset(master->control_channel, 0, sizeof(master->control_channel));
		memset(master->data_channel, 0, sizeof(master->data_channel));
		master->port_num = 0;
		master->hwaddr_cache_valid = false;
		memset(master->hwaddr_cache, 0, sizeof(master->hwaddr_cache));
	}

	/*
	 * Notify network device add event
	 */
	genl_dev_notify_netdev_obj_added(system_obj, slave->switch_port_obj);

	return true;
}

/*
 * genl_dev_sw_port_send_lacpdu : send LACPDU on port
 * system_obj: network device system
 * netdev_obj: network device
 * buf: buffer which contains LACPDU
 * buf_len: length of above buffer
 * return value: true: successful, false: failed
 */
static bool genl_dev_sw_port_send_lacpdu(struct general_device_system *system_obj, uint32_t netdev_obj, const uint8_t *buf, uint32_t buf_len)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, netdev_obj);

	if (!port) {
		return false;
	}

	if (switch_port_is_aggregator(port)) {
		DP(GENL_DEVICE, DEBUG, "Can't send LACPDU on aggregator");
		return false;
	}

	return sw_sys->ops.agg.send_lacpdu(port, buf, buf_len);
}

/*
 * genl_dev_sw_port_set_tx_hash_policy : set hash policy to select output port when transmit packet in aggregator
 * system_obj: network device system
 * master_dev_obj: network device for aggregator
 * policy: tx hash policy
 * return value: true: successful, false: failed
 */
static bool genl_dev_sw_port_set_tx_hash_policy(struct general_device_system *system_obj, uint32_t master_dev_obj, enum general_device_agg_tx_hash_policy policy)
{
	struct general_device_switch_system *sw_sys = container_of(system_obj, struct general_device_switch_system, base);
	struct switch_port *port = genl_dev_sw_port_lookup(sw_sys, master_dev_obj);

	if (!port) {
		return false;
	}

	if (!switch_port_is_aggregator(port)) {
		return false;
	}

	return sw_sys->ops.agg.set_tx_hash_policy(port, policy);
}

/*
 * APIs for upper layer above switch system, end
 */
/*
 * APIs for lower layer below switch system, start
 */
/*
 * genl_dev_sw_port_link_status_changed : link status of switch port changed
 * sw_sys: switch system
 * port: switch port whose link status changed
 * new_status: new link status of switch port
 */
void genl_dev_sw_port_link_status_changed(struct general_device_switch_system *sw_sys, struct switch_port *port, int new_status)
{
	genl_dev_link_status_changed(&sw_sys->base, port->switch_port_obj, new_status);
}

/*
 * genl_dev_sw_port_recv_bpdu : receive BPDU from a switch port
 * sw_sys: switch system
 * control_channel: which Linux network device is this packet received from
 * sw_port_num: which switch port is this packet received from
 * buf: buffer which contains BPDU
 * buf_len: length of above buffer
 * return value: true: successful, false: failed
 */
bool genl_dev_sw_port_recv_bpdu(struct general_device_switch_system *sw_sys, const char *control_channel, uint32_t sw_port_num, uint8_t *buf, uint32_t buf_len)
{
	struct switch_port *port, *slave;

	list_for_each_entry(port, &sw_sys->switch_ports, node) {
		if (!sw_sys->real_agg_dev && switch_port_is_aggregator(port)) {
			list_for_each_entry(slave, &port->agg_slaves, node) {
				if ((slave->port_num == sw_port_num) && !strncmp(slave->control_channel, control_channel, sizeof(slave->control_channel))) {
					return genl_dev_recv_bpdu(&sw_sys->base, port->switch_port_obj, buf, buf_len);
				}
			}
		} else if ((port->port_num == sw_port_num) && !strncmp(port->control_channel, control_channel, sizeof(port->control_channel))) {
			return genl_dev_recv_bpdu(&sw_sys->base, port->switch_port_obj, buf, buf_len);
		}
	}

	return false;
}

/*
 * genl_dev_sw_port_recv_lacpdu : receive LACPDU from a switch port
 * sw_sys: switch system
 * control_channel: which Linux network device is this packet received from
 * sw_port_num: which switch port is this packet received from
 * buf: buffer which contains LACPDU
 * buf_len: length of above buffer
 * return value: true: successful, false: failed
 */
bool genl_dev_sw_port_recv_lacpdu(struct general_device_switch_system *sw_sys, const char *control_channel, uint32_t sw_port_num, uint8_t *buf, uint32_t buf_len)
{
	struct switch_port *port, *slave;

	list_for_each_entry(port, &sw_sys->switch_ports, node) {
		if (!sw_sys->real_agg_dev && switch_port_is_aggregator(port)) {
			list_for_each_entry(slave, &port->agg_slaves, node) {
				if ((slave->port_num == sw_port_num) && !strncmp(slave->control_channel, control_channel, sizeof(slave->control_channel))) {
					return genl_dev_recv_lacpdu(&sw_sys->base, slave->switch_port_obj, buf, buf_len);
				}
			}
		} else if ((port->port_num == sw_port_num) && !strncmp(port->control_channel, control_channel, sizeof(port->control_channel))) {
			return genl_dev_recv_lacpdu(&sw_sys->base, port->switch_port_obj, buf, buf_len);
		}
	}

	return false;
}

/*
 * genl_dev_sw_alloc_netdev_obj_domain: allocate a magic prefix for index of network device
 */
uint32_t genl_dev_sw_alloc_netdev_obj_domain(struct general_device_switch_system *sw_sys, uint32_t max_devices)
{
	return genl_dev_alloc_netdev_obj_domain(&sw_sys->base, max_devices);
}

/*
 * genl_dev_register_switch_system : register a switch system
 */
bool genl_dev_register_switch_system(struct general_device_switch_system *sw_sys)
{
	struct general_device_system *dev_sys;

	if (!sw_sys) {
		return false;
	}

	INIT_LIST_HEAD(&sw_sys->switch_ports);

	dev_sys = &sw_sys->base;
	snprintf(dev_sys->name, sizeof(dev_sys->name), "%s", sw_sys->name);
	dev_sys->init = genl_dev_sw_init;
	dev_sys->exit = genl_dev_sw_exit;
	dev_sys->private = genl_dev_sw_private;
	dev_sys->system.get_hw_addr = genl_dev_sw_get_hw_addr;
	dev_sys->common.is_compatible = genl_dev_sw_port_is_compatible;
	dev_sys->common.name_to_netdev_obj = genl_dev_sw_port_name_to_netdev_obj;
	dev_sys->common.netdev_obj_to_name = genl_dev_sw_port_netdev_obj_to_name;
	dev_sys->common.get_link_status = genl_dev_sw_port_get_link_status;
	dev_sys->common.get_duplex = genl_dev_sw_port_get_duplex;
	dev_sys->common.get_speed = genl_dev_sw_port_get_speed;
	dev_sys->common.get_hw_addr = genl_dev_sw_port_get_hw_addr;
	dev_sys->bridge.is_bridge_member = genl_dev_sw_port_is_bridge_member;
	dev_sys->bridge.flush_fdb = genl_dev_sw_port_flush_fdb;
	dev_sys->stp.enable = genl_dev_sw_port_stp_enable;
	dev_sys->stp.disable = genl_dev_sw_port_stp_disable;
	dev_sys->stp.set_port_state = genl_dev_sw_port_set_stp_state;
	dev_sys->stp.send_bpdu = genl_dev_sw_port_send_bpdu;
	dev_sys->agg.enable = genl_dev_sw_port_lacp_enable;
	dev_sys->agg.disable = genl_dev_sw_port_lacp_disable;
	dev_sys->agg.new_aggregator = genl_dev_sw_new_aggregator;
	dev_sys->agg.destroy_aggregator = genl_dev_sw_destroy_aggregator;
	dev_sys->agg.is_aggregator = genl_dev_sw_port_is_aggregator;
	dev_sys->agg.is_slave = genl_dev_sw_port_is_slave;
	dev_sys->agg.number_of_slaves = genl_dev_sw_port_number_of_slaves;
	dev_sys->agg.attach_slave = genl_dev_sw_port_attach_slave;
	dev_sys->agg.detach_slave = genl_dev_sw_port_detach_slave;
	dev_sys->agg.send_lacpdu = genl_dev_sw_port_send_lacpdu;
	dev_sys->agg.set_tx_hash_policy = genl_dev_sw_port_set_tx_hash_policy;

	return genl_dev_system_register(dev_sys);
}
/*
 * APIs for lower layer below switch system, end
 */
