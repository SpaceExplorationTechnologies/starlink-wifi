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
#ifndef __GENERAL_DEVICE_SWITCH_PORT_H
#define __GENERAL_DEVICE_SWITCH_PORT_H

#include "general_device_api.h"

#define SWITCH_PORT_LAYER_DEPTH (GENERAL_DEVICE_LAYER_DEPTH + 1)
#define switch_port_is_agg_slave(port) (NULL != (port)->agg_parent)
#define switch_port_is_aggregator(port) ((port)->sw_sys->ops.agg.is_aggregator((port), NULL))

enum switch_port_type
{
	SWITCH_PORT_TYPE_HIDDEN,
	SWITCH_PORT_TYPE_EXPORTED
};

struct switch_port {
	/*
	 * Linked to "struct general_device_switch_port_system ->switch_ports" when switch port is not slave of aggregator
	 * Linked to "struct switch_port ->agg_slaves" when switch port is slave of aggregator
	 */
	struct list_head node;

	/*
	 * Associate aggregator when switch port is slave of aggregator
	 */
	struct switch_port *agg_parent;
	/*
	 * Slaves when switch port is aggregator
	 */
	struct list_head agg_slaves;
	/*
	 * Name of switch port
	 */
	char name[GENERAL_DEVICE_SYSTEM_NAME_SIZE];
	/*
	 * Index of switch port
	 */
	uint32_t switch_port_obj;
	/*
	 * Mapped hardware port when switch port is not an aggregator
	 * Bitmap of member ports when switch port is an aggregator and switch don't support real device for aggregator
	 */
	uint32_t port_num;
	/*
	 * Link status of switch port
	 */
	bool link_status;
	/*
	 * Associated hardware specific switch system
	 */
	struct general_device_switch_system *sw_sys;
	/*
	 * getting MAC address of switch port is too frequent, so cache it
	 * don't cache for aggregator unless switch support real aggregator device
	 */
	bool hwaddr_cache_valid;
	uint8_t hwaddr_cache[6];

	/*
	 * name of Linux network device
	 * 1, use this channel to send and receive BPDU/LACPDU for this switch port
	 * 2, use this channel to manage hardware attributes of this switch port
	 */
	char control_channel[GENERAL_DEVICE_SYSTEM_NAME_SIZE];
	/*
	 * name of Linux network device
	 * data traffic of this switch port will go through this Linux network device
	 */
	char data_channel[GENERAL_DEVICE_SYSTEM_NAME_SIZE];
	/*
	 * 1, switch port is defined as hidden switch port when 'data_channel == control_channel',
	 *    because it hasn't an independent mapped Linux network device
	 * 2, switch port is defined as exported switch port when 'data_channel != control_channel',
	 *    because it has an independent mapped Linux network device
	 */
	enum switch_port_type type;
	/*
	 * hardware specific field, should only be accessed by hardware specific code
	 */
	void *hw_priv;
};

struct switch_ops_system {
	/*
	 * get_hw_addr : (optional), get hardware address of system
	 * sw_sys: switch system
	 * mac_addr: returned MAC address of system
	 * return value: successful or fail
	 */
	bool (*get_hw_addr)(struct general_device_switch_system *sw_sys, uint8_t *mac_addr);
};

struct switch_ops_common {
	/*
	 * get_link_status : get link status of switch port
	 * port: switch port
	 * return value: true: link up; false: link down
	 */
	bool (*get_link_status)(struct switch_port *port);
	/*
	 * get_duplex : get duplex of switch port
	 * port: switch port
	 * return value: 1: full duplex, 0: half duplex
	 */
	uint32_t (*get_duplex)(struct switch_port *port);
	/*
	 * get_speed : get speed of switch port
	 * port: switch port
	 * return value: 0: invalid, 1: 1Mbps, 10: 10Mbps, 100: 100Mbps, 1000: 1Gbps, 10000: 10Gbps
	 */
	uint32_t (*get_speed)(struct switch_port *port);
	/*
	 * get_hw_addr : (optional), get hardware address of switch port
	 * port: switch port
	 * hw_addr: returned hardware address of switch port, max size is 6 bytes
	 * return value: successful or fail
	 */
	bool (*get_hw_addr)(struct switch_port *port, uint8_t *hw_addr);

};

struct switch_ops_bridge {
	/*
	 * is_bridge_member : check if a port is in a bridge
	 * port: port
	 * br: bridge
	 * return value: true: is a bridge member, false: not a bridge member
	 */
	bool (*is_bridge_member)(struct switch_port *port, struct switch_port *br);
	/*
	 * flush_fdb : flush all FDB learnt on this port
	 * port: switch port, it could be bridge, then it means flush all FDB in bridge
	 * return value: true: successful, false: failed
	 */
	bool (*flush_fdb)(struct switch_port *port);
};

struct switch_ops_stp {
	/*
	 * enable : enable STP on port, this means STP protocol starts to run on this port
	 * port: switch port
	 * return value: true: successful, false: failed
	 */
	bool (*enable)(struct switch_port *port);
	/*
	 * disable : disable STP on port, this means STP protocol stops to run on this port
	 * port: switch port
	 * return value: true: successful, false: failed
	 */
	bool (*disable)(struct switch_port *port);
	/*
	 * set_port_state : set STP state of port
	 * port: switch port
	 * state: state of port
	 * return value: true: successful, false: failed
	 */
	bool (*set_port_state)(struct switch_port *port, enum general_device_stp_state state);
	/*
	 * send_bpdu : send BPDU on port
	 * port: switch port
	 * buf: buffer which contains BPDU
	 * buf_len: length of above buffer
	 * return value: true: successful, false: failed
	 */
	bool (*send_bpdu)(struct switch_port *port, const uint8_t *buf, uint32_t buf_len);
};

struct switch_ops_aggregation {
	/*
	 * enable : enable LACP on port, this means LACP protocol starts to run on this port
	 * port: switch port
	 * return value: true: successful, false: failed
	 */
	bool (*enable)(struct switch_port *port);
	/*
	 * disable : disable LACP on port, this means LACP protocol stops to run on this port
	 * port: switch port
	 * return value: true: successful, false: failed
	 */
	bool (*disable)(struct switch_port *port);
	/*
	 * new_aggregator : create physical network device for aggregator
	 * port: aggregator to create
	 * return value: successful or fail
	 */
	bool (*new_aggregator)(struct switch_port *port);
	/*
	 * destroy_aggregator : destroy physical network device of aggregator
	 * port: switch port for aggregator
	 * return value: successful or fail
	 */
	bool (*destroy_aggregator)(struct switch_port *port);
	/*
	 * is_aggregator : check if switch port is the master of another switch port
	 * master: switch port for aggregator
	 * slave: switch port in aggregator, could be NULL
	 * return value: successful or fail
	 */
	bool (*is_aggregator)(struct switch_port *master, struct switch_port *slave);
	/*
	 * is_slave : (optional), check if switch port is the slave of another switch port
	 * slave: switch port in aggregator
	 * master: switch port for aggregator, could be NULL
	 * return value: is a slave or not a slave
	 */
	bool (*is_slave)(struct switch_port *slave, struct switch_port *master);
	/*
	 * number_of_slaves : (optional), number of slave network devices of a master network device
	 * aggregator: network device for aggregator
	 * return value: number of slaves
	 */
	uint32_t (*number_of_slaves)(struct switch_port *aggregator);
	/*
	 * attach_slave : attach a slave network device to a master network device
	 * master: switch port for aggregator
	 * slave: switch port for port in aggregator
	 * return value: successful or fail
	 */
	bool (*attach_slave)(struct switch_port *master, struct switch_port *slave);
	/*
	 * detach_slave : detach a slave network device from a master network device
	 * master: switch port for aggregator
	 * slave: switch port for port in aggregator
	 * return value: successful or fail
	 */
	bool (*detach_slave)(struct switch_port *master, struct switch_port *slave);
	/*
	 * send_bpdu : send LACPDU on port
	 * port: switch port
	 * buf: buffer which contains LACPDU
	 * buf_len: length of above buffer
	 * return value: true: successful, false: failed
	 */
	bool (*send_lacpdu)(struct switch_port *port, const uint8_t *buf, uint32_t buf_len);
	/*
	 * set_tx_hash_policy : set hash policy to select output port when transmit packet in aggregator
	 * aggregator: network device for aggregator
	 * policy: tx hash policy
	 * return value: true: successful, false: failed
	 */
	bool (*set_tx_hash_policy)(struct switch_port *aggregator, enum general_device_agg_tx_hash_policy policy);
};

struct switch_ops {
	/*
	 * hardware specific initiation when switch port system start
	 */
	bool (*init)(struct general_device_switch_system *sw_sys);
	/*
	 * hardware specific finalization when switch port system stop
	 */
	bool (*exit)(struct general_device_switch_system *sw_sys);
	/*
	 * hardware specific internal operation
	 */
	bool (*private)(struct general_device_switch_system *sw_sys, uint32_t func_id, void *input_arg, void *output_arg);

	struct switch_ops_common common;	/*common APIs*/
	struct switch_ops_system system;	/*System related APIs*/
	struct switch_ops_bridge bridge;	/*Bridge related APIs*/
	struct switch_ops_stp stp;			/*STP related APIs*/
	struct switch_ops_aggregation agg;	/*aggregation related APIs*/
};

struct general_device_switch_system {
	/*
	 * Fields maintained by 'switch port' module, start
	 */
	struct general_device_system base;			/*Super class*/
	struct list_head switch_ports;				/*List of switch ports*/
	struct genl_os_service_timer link_status_monitor;	/*timer to monitor link status of switch port*/
	/*
	 * Fields maintained by 'switch port' module, end
	 */
	/*
	 * Fields maintained by 'hardware specific switch' module, start
	 */
	char name[GENERAL_DEVICE_SYSTEM_NAME_SIZE];		/*name of switch*/
	uint32_t switch_obj;					/*index of switch*/
	bool real_agg_dev;					/*aggregator has a real device index, switch driver can operate on this index*/
	bool support_link_event;				/*lower device system can notify link status event. If false, "switch port" layer will poll*/
	uint32_t link_status_poll_interval;			/*interval to poll link status of switch port if link event is not supported, in unit of msec*/
	struct switch_ops ops;					/*APIs provided by specific switch system*/
	/*
	 * Fields maintained by 'hardware specific switch' module, end
	 */
};

/*
 * APIs for lower layer below switch system, start
 */

/*
 * genl_dev_sw_port_lookup: lookup switch port by its index
 * sw_sys: switch system
 * netdev_obj: index of network device
 * return value: founded switch port or NULL
 */
struct switch_port *genl_dev_sw_port_lookup(struct general_device_switch_system *sw_sys, uint32_t netdev_obj);
/*
 * genl_dev_sw_port_link_status_changed : link status of switch port changed
 * sw_sys: switch system
 * port: switch port whose link status changed
 * new_status: new link status of switch port
 */
void genl_dev_sw_port_link_status_changed(struct general_device_switch_system *sw_sys, struct switch_port *port, int new_status);
/*
 * genl_dev_sw_port_recv_bpdu : receive BPDU from a switch port
 * sw_sys: switch system
 * control_channel: which Linux network device is this packet received from
 * sw_port_num: which switch port is this packet received from
 * buf: buffer which contains BPDU
 * buf_len: length of above buffer
 * return value: true: successful, false: failed
 */
bool genl_dev_sw_port_recv_bpdu(struct general_device_switch_system *sw_sys, const char *control_channel, uint32_t sw_port_num, uint8_t *buf, uint32_t buf_len);
/*
 * genl_dev_sw_port_recv_lacpdu : receive LACPDU from a switch port
 * sw_sys: switch system
 * control_channel: which Linux network device is this packet received from
 * sw_port_num: which switch port is this packet received from
 * buf: buffer which contains LACPDU
 * buf_len: length of above buffer
 * return value: true: successful, false: failed
 */
bool genl_dev_sw_port_recv_lacpdu(struct general_device_switch_system *sw_sys, const char *control_channel, uint32_t sw_port_num, uint8_t *buf, uint32_t buf_len);
/*
 * genl_dev_sw_alloc_netdev_obj_domain: allocate a magic prefix for index of network device
 */
uint32_t genl_dev_sw_alloc_netdev_obj_domain(struct general_device_switch_system *sw_sys, uint32_t max_devices);
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
											uint32_t switch_port_obj, const char *ctrl_channel, const char *data_channel);
/*
 * genl_dev_register_switch_system : register a switch system
 */
bool genl_dev_register_switch_system(struct general_device_switch_system *sw_sys);
/*
 * APIs for lower layer below switch system, end
 */
#endif /*__GENERAL_DEVICE_SWITCH_PORT_H*/
