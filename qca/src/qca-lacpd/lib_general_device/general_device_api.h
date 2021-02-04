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
#ifndef __GENERAL_DEVICE_API_H
#define __GENERAL_DEVICE_API_H

/*
 * Concept of general device
 *
 *-------------------------------------------------------------------------------------------
 *|                              | protocol, such as 'stp', 'lacp', 'igmp'|                  |
 *-------------------------------------------------------------------------------------------
 *|  |configuration, such as 'uci', 'command'|      wrapper      |status, such as 'ubus'|    |
 *-------------------------------------------------------------------------------------------
 *|                                  |   general device   |                                  |
 *-------------------------------------------------------------------------------------------
 *|                     |qca switch|         |Linux|            |other|                      |
 *-------------------------------------------------------------------------------------------
 *
 *1, General device
 * General device layer provide unified APIs to upper layer, such as 'configuration' module, 'wrapper' module, 'status' module.
 * Specific device type register itself in general device. Every specific device type have its own ifindex domain which is the
 * magic prefix of ifindex of device. For example, domain of linux device is 0, domain of QCA switch port may be 0x2bcd0000.
 * General device use domain of ifindex of device to identify which type device belongs to, then call corresponding APIs.
 */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <libubox/list.h>

#include "general_os_service.h"

#define GENERAL_DEVICE_LAYER_DEPTH 0
#define GENERAL_DEVICE_SYSTEM_MAX_DOMAIN 256
#define GENERAL_DEVICE_SYSTEM_INIT_INTERNAL_DOMAIN 0x1a
#define netdev_obj_to_domain(NDEV_OBJ) (((NDEV_OBJ)>>24) & 0xff)
#define GENERAL_DEVICE_SYSTEM_NAME_SIZE 64
#define GENERAL_DEVICE_INVALID_ID 0
#define netdev_obj_is_invalid(XID) ((XID) == GENERAL_DEVICE_INVALID_ID)
#define GENERAL_DEVICE_HW_ADDR_SIZE 6

struct general_device_system;

struct general_device_in_api_system {
	/*
	 * get_hw_addr : get hardware address of system
	 * system_obj: network device system
	 * mac_addr: returned MAC address of system
	 * return value: successful or fail
	 */
	bool (*get_hw_addr)(struct general_device_system *system_obj, uint8_t *mac_addr);
};

struct general_device_in_api_common {
	/*
	 * is_compatible: check if a device belongs to this type of device
	 */
	bool (*is_compatible)(struct general_device_system *system_obj, uint32_t netdev_obj);
	/*
	 * name_to_netdev_obj: returns network device according to name of network device
	 */
	uint32_t (*name_to_netdev_obj)(struct general_device_system *system_obj, const char *netdev_name);
	/*
	 * netdev_obj_to_name: returns name of network device
	 */
	char *(*netdev_obj_to_name)(struct general_device_system *system_obj, uint32_t netdev_obj, char *netdev_name);
	/*
	 * get_link_status : get link status of network device
	 * system_obj: network device system
	 * netdev_obj: network device
	 * return value: true: link up; false: link down
	 */
	bool (*get_link_status)(struct general_device_system *system_obj, uint32_t netdev_obj);
	/*
	 * get_duplex : get duplex of network device
	 * system_obj: network device system
	 * netdev_obj: network device
	 * return value: 1: full duplex, 0: half duplex
	 */
	uint32_t (*get_duplex)(struct general_device_system *system_obj, uint32_t netdev_obj);
	/*
	 * get_speed : get speed of network device
	 * system_obj: network device system
	 * netdev_obj: network device
	 * return value: 0: invalid, 1: 1Mbps, 10: 10Mbps, 100: 100Mbps, 1000: 1Gbps, 10000: 10Gbps
	 */
	uint32_t (*get_speed)(struct general_device_system *system_obj, uint32_t netdev_obj);
	/*
	 * get_hw_addr : get hardware address of network device
	 * system_obj: network device system
	 * netdev_obj: network device
	 * hw_addr: returned hw address of network device, max size is 6 bytes
	 * return value: successful or fail
	 */
	bool (*get_hw_addr)(struct general_device_system *system_obj, uint32_t netdev_obj, uint8_t *hw_addr);
};

struct general_device_in_api_bridge {
	/*
	 * is_bridge_member : check if a port is in a bridge
	 * system_obj: network device system
	 * port_dev_obj: port
	 * br_dev_obj: bridge
	 * return value: true: is a bridge member, false: not a bridge member
	 */
	bool (*is_bridge_member)(struct general_device_system *system_obj, uint32_t port_dev_obj, uint32_t br_dev_obj);
	/*
	 * flush_fdb : flush all FDB learned on bridge port
	 * system_obj: network device system
	 * port_dev_obj: FDB learned on this port should be flushed,
	 * 				 it could be index of bridge, then it means flush all FDB in bridge
	 * return value: true: successful, false: failed
	 */
	bool (*flush_fdb)(struct general_device_system *system_obj, uint32_t port_dev_obj);
};

enum general_device_stp_state
{
	GENL_DEV_STP_STATE_DISABLE,
	GENL_DEV_STP_STATE_BLOCK,
	GENL_DEV_STP_STATE_LISTEN,
	GENL_DEV_STP_STATE_LEARN,
	GENL_DEV_STP_STATE_FORWARD
};

enum general_device_agg_tx_hash_policy
{
	GENL_DEV_AGG_TX_HASH_POLICY_L2,
	GENL_DEV_AGG_TX_HASH_POLICY_L3,
	GENL_DEV_AGG_TX_HASH_POLICY_L2_L3,
	GENL_DEV_AGG_TX_HASH_POLICY_L4,
	GENL_DEV_AGG_TX_HASH_POLICY_L3_L4,
	GENL_DEV_AGG_TX_HASH_POLICY_L2_L3_L4,
	GENL_DEV_AGG_TX_HASH_POLICY_MAX
};

struct general_device_in_api_stp {
	/*
	 * enable : enable STP on port, this means STP protocol starts to run on this port
	 * system_obj: network device system
	 * netdev_obj: network device
	 * return value: true: successful, false: failed
	 */
	bool (*enable)(struct general_device_system *system_obj, uint32_t netdev_obj);
	/*
	 * disable : disable STP on port, this means STP protocol stops to run on this port
	 * system_obj: network device system
	 * netdev_obj: network device
	 * return value: true: successful, false: failed
	 */
	bool (*disable)(struct general_device_system *system_obj, uint32_t netdev_obj);
	/*
	 * set_port_state : set STP state of port
	 * system_obj: network device system
	 * netdev_obj: network device
	 * state: state of port
	 * return value: true: successful, false: failed
	 */
	bool (*set_port_state)(struct general_device_system *system_obj, uint32_t netdev_obj, enum general_device_stp_state state);
	/*
	 * send_bpdu : send BPDU on port
	 * system_obj: network device system
	 * netdev_obj: network device
	 * buf: buffer which contains BPDU
	 * buf_len: length of above buffer
	 * return value: true: successful, false: failed
	 */
	bool (*send_bpdu)(struct general_device_system *system_obj, uint32_t netdev_obj, const uint8_t *buf, uint32_t buf_len);
};

struct general_device_in_api_aggregation {
	/*
	 * enable : enable LACP on port, this means LACP protocol starts to run on this port
	 * system_obj: network device system
	 * netdev_obj: network device
	 * return value: true: successful, false: failed
	 */
	bool (*enable)(struct general_device_system *system_obj, uint32_t netdev_obj);
	/*
	 * disable : disable LACP on port, this means LACP protocol stops to run on this port
	 * system_obj: network device system
	 * netdev_obj: network device
	 * return value: true: successful, false: failed
	 */
	bool (*disable)(struct general_device_system *system_obj, uint32_t netdev_obj);
	/*
	 * new_aggregator : create physical network device for aggregator
	 * system_obj: network device system
	 * agg_name: name of aggregator, length of name is less 64
	 * return value: network device object for new aggregator
	 */
	uint32_t (*new_aggregator)(struct general_device_system *system_obj, const char *agg_name);
	/*
	 * destroy_aggregator : destroy physical network device of aggregator
	 * system_obj: network device system
	 * aggregator_dev_obj: network device for aggregator
	 * return value: successful or fail
	 */
	bool (*destroy_aggregator)(struct general_device_system *system_obj, uint32_t aggregator_dev_obj);
	/*
	 * is_aggregator : check if a network device is a aggregator
	 * system_obj: network device system
	 * master_dev_obj: network device for aggregator
	 * slave_dev_obj: network device for port in aggregator, could be 0
	 * return value: successful or fail
	 */
	bool (*is_aggregator)(struct general_device_system *system_obj, uint32_t master_dev_obj, uint32_t slave_dev_obj);
	/*
	 * is_slave : check if a network device is a slave of another network device
	 * system_obj: network device system
	 * slave_dev_obj: network device for port in aggregator
	 * master_dev_obj: network device for aggregator, could be 0
	 * return value: is a slave or not a slave
	 */
	bool (*is_slave)(struct general_device_system *system_obj, uint32_t slave_dev_obj, uint32_t master_dev_obj);
	/*
	 * number_of_slaves : number of slave network devices of a master network device
	 * system_obj: network device system
	 * master_dev_obj: network device for aggregator
	 * return value: number of slaves
	 */
	uint32_t (*number_of_slaves)(struct general_device_system *system_obj, uint32_t master_dev_obj);
	/*
	 * attach_slave : attach a slave network device to a master network device
	 * system_obj: network device system
	 * master_dev_obj: network device for aggregator
	 * slave_dev_obj: network device for port in aggregator
	 * return value: successful or fail
	 */
	bool (*attach_slave)(struct general_device_system *system_obj, uint32_t master_dev_obj, uint32_t slave_dev_obj);
	/*
	 * detach_slave : detach a slave network device from a master network device
	 * system_obj: network device system
	 * master_dev_obj: network device for aggregator
	 * slave_dev_obj: network device for port in aggregator
	 * return value: successful or fail
	 */
	bool (*detach_slave)(struct general_device_system *system_obj, uint32_t master_dev_obj, uint32_t slave_dev_obj);
	/*
	 * send_bpdu : send LACPDU on port
	 * system_obj: network device system
	 * netdev_obj: network device
	 * buf: buffer which contains LACPDU
	 * buf_len: length of above buffer
	 * return value: true: successful, false: failed
	 */
	bool (*send_lacpdu)(struct general_device_system *system_obj, uint32_t netdev_obj, const uint8_t *buf, uint32_t buf_len);
	/*
	 * set_tx_hash_policy : set hash policy to select output port when transmit packet in aggregator
	 * system_obj: network device system
	 * master_dev_obj: network device for aggregator
	 * policy: tx hash policy
	 * return value: true: successful, false: failed
	 */
	bool (*set_tx_hash_policy)(struct general_device_system *system_obj, uint32_t master_dev_obj, enum general_device_agg_tx_hash_policy policy);
};

struct general_device_system {
	char name[GENERAL_DEVICE_SYSTEM_NAME_SIZE];

	/*
	 * init : initialize network device system when it is attached to a specific OS
	 * system_obj: network device system
	 * return value: true: successful, false: failed
	 */
	bool (*init)(struct general_device_system *system_obj);
	/*
	 * exit : finalize network device system when it is detached from a specific OS
	 * system_obj: network device system
	 * return value: true: successful, false: failed
	 */
	bool (*exit)(struct general_device_system *system_obj);
	/*
	 * private : internal operation understanded by lower driver but not upper layer
	 * system_obj: network device system
	 * func_id: identifier of operation
	 * input_arg: input argument
	 * output_arg: output argument
	 * return value: true: successful, false: failed
	 */
	bool (*private)(struct general_device_system *system_obj, uint32_t func_id, void *input_arg, void *output_arg);

	struct general_device_in_api_common common;	/*common APIs*/
	struct general_device_in_api_system system;	/*System related APIs*/
	struct general_device_in_api_bridge bridge;	/*Bridge related APIs*/
	struct general_device_in_api_stp stp;		/*stp related APIs*/
	struct general_device_in_api_aggregation agg;	/*aggregation related APIs*/

	struct list_head users;	/*List of "struct general_device_out_api", will notify them when link event or packet received*/
	uint32_t domain;							/*Prefix of index of network device in this device system*/
	uint32_t next_internal_domain;				/*Different type of device inside this device system also have different internal domain*/
};

struct general_device_out_api {
	/*
	 * Linked to "struct general_device_system ->users"
	 */
	struct list_head node;
	/*
	 * link_status_changed : notify link status event of physical network device
	 * genl_dev_user: APIs to talk with user of generic network device system
	 * netdev_obj: network device where event happen
	 * new_status: new link status of device
	 */
	void (*link_status_changed)(struct general_device_out_api *genl_dev_user, uint32_t netdev_obj, int new_status);
	/*
	 * netdev_obj_added : new physical network device was added into this network device system
	 * genl_dev_user: APIs to talk with user of generic network device system
	 * netdev_obj: network device where event happen
	 */
	void (*netdev_obj_added)(struct general_device_out_api *genl_dev_user, uint32_t netdev_obj);
	/*
	 * netdev_obj_deleted : physical network device was deleted from this network device system
	 * genl_dev_user: APIs to talk with user of generic network device system
	 * netdev_obj: network device where event happen
	 */
	void (*netdev_obj_deleted)(struct general_device_out_api *genl_dev_user, uint32_t netdev_obj);
	/*
	 * receive_bpdu : receive BPDU packet
	 * genl_dev_user: APIs to talk with user of generic network device system
	 * buf: packet
	 * buf_len: length of packet
	 * netdev_obj: receiving network device
	 * return value: packet is consumed or not
	 */
	bool (*receive_bpdu)(struct general_device_out_api *genl_dev_user, uint8_t *buf, uint32_t buf_len, uint32_t netdev_obj);
	/*
	 * receive_lacpdu : receive LACPDU packet
	 * genl_dev_user: APIs to talk with user of generic network device system
	 * buf: packet
	 * buf_len: length of packet
	 * dev_obj: receiving network device
	 * return value: packet is consumed or not
	 */
	bool (*receive_lacpdu)(struct general_device_out_api *genl_dev_user, uint8_t *buf, uint32_t buf_len, uint32_t netdev_obj);
	/*
	 * system_unregistered : general device system is unregistered
	 * genl_dev_user: APIs to talk with user of generic network device system
	 */
	void (*system_unregistered)(struct general_device_out_api *genl_dev_user);
};

/*
 * APIs for upper layer above general device, start
 */
void qca_switch_probe(void);
void genl_dev_linux_probe(void);
/*
 * genl_dev_init: initialize general device sub module
 * 	os_service: operate system service provided by wrapper
 * 	return value: successful or fail
 */
bool genl_dev_init(struct genl_os_service *os_service);
/*
 * genl_dev_sys_resolve_by_name: resolve device system of a device by its name
 * 	Normally this will call dev_sys->common->name_to_netdev_obj() to check if a device system
 * 	is aware of this device.
 */
struct general_device_system *genl_dev_sys_resolve_by_name(const char *netdev_name);
/*
 * genl_dev_sys_resolve_by_obj: resolve device system of a device by its object
 * 	Normally this will call dev_sys->common->is_compatible() to check if a device system
 * 	is aware of this device.
 */
struct general_device_system *genl_dev_sys_resolve_by_obj(uint32_t netdev_obj);
/*
 * genl_dev_sys_add_user: add user of generic network device module
 * dev_sys_name: name of device system which user want to use
 * genl_dev_user: APIs to talk with user of generic network device module
 * return value: true: successful, false: failed
 */
bool genl_dev_sys_add_user(char *dev_sys_name, struct general_device_out_api *genl_dev_user);
/*
 * genl_dev_sys_del_user: delete user of generic network device module
 * dev_sys_name: name of device system which user want to delete
 * genl_dev_user: APIs to talk with user of generic network device module
 */
void genl_dev_sys_del_user(char *dev_sys_name, struct general_device_out_api *genl_dev_user);
/*
 * genl_dev_name_to_netdev_obj: returns network device according to name of network device
 */
uint32_t genl_dev_name_to_netdev_obj(const char *netdev_name);
/*
 * genl_dev_netdev_obj_to_name: returns name of network device
 */
char *genl_dev_netdev_obj_to_name(uint32_t netdev_obj, char *netdev_name);
/*
 * genl_dev_get_link_status : get link status of network device
 * netdev_obj: network device
 * return value: true: link up; false: link down
 */
bool genl_dev_get_link_status(uint32_t netdev_obj);
/*
 * genl_dev_get_duplex : get duplex of network device
 * netdev_obj: network device
 * return value: 1: full duplex, 0: half duplex
 */
uint32_t genl_dev_get_duplex(uint32_t netdev_obj);
/*
 * genl_dev_get_speed : get speed of network device
 * netdev_obj: network device
 * return value: 0: invalid, 1: 1Mbps, 10: 10Mbps, 100: 100Mbps, 1000: 1Gbps, 10000: 10Gbps
 */
uint32_t genl_dev_get_speed(uint32_t netdev_obj);
/*
 * genl_dev_get_hw_addr : get hardware address of network device
 * netdev_obj: network device
 * hw_addr: returned hw address of network device, max size is 6 bytes
 * return value: successful or fail
 */
bool genl_dev_get_hw_addr(uint32_t netdev_obj, uint8_t *hw_addr);
/*
 * genl_dev_is_bridge_member : check if a port is in a bridge
 * port_dev_obj: port
 * br_dev_obj: bridge
 * return value: true: is a bridge member, false: not a bridge member
 */
bool genl_dev_is_bridge_member(uint32_t port_dev_obj, uint32_t br_dev_obj);
/*
 * genl_dev_flush_fdb : flush all FDB learned on bridge port
 * port_dev_obj: FDB learned on this port should be flushed,
 * 				 it could be index of bridge, then it means flush all FDB in bridge
 * return value: true: successful, false: failed
 */
bool genl_dev_flush_fdb(uint32_t port_dev_obj);
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
void genl_dev_link_status_changed(struct general_device_system *dev_sys, uint32_t netdev_obj, int new_status);
/*
 * genl_dev_notify_netdev_obj_added : notify creation event of physical network device
 * dev_sys: device system
 * netdev_obj: network device where event happen
 */
void genl_dev_notify_netdev_obj_added(struct general_device_system *dev_sys, uint32_t netdev_obj);
/*
 * genl_dev_notify_netdev_obj_deleted : notify destroy event of physical network device
 * dev_sys: device system
 * netdev_obj: network device where event happen
 */
void genl_dev_notify_netdev_obj_deleted(struct general_device_system *dev_sys, uint32_t netdev_obj);
/*
 * genl_dev_recv_bpdu: receive BPDU from lower device system
 * dev_sys: device system
 * netdev_obj: receiving network device
 * buf: packet
 * buf_len: length of packet
 * return value: packet is consumed or not
 */
bool genl_dev_recv_bpdu(struct general_device_system *dev_sys, uint32_t netdev_obj, uint8_t *buf, uint32_t buf_len);
/*
 * genl_dev_recv_lacpdu: receive LACPDU from lower device system
 * dev_sys: device system
 * netdev_obj: receiving network device
 * buf: packet
 * buf_len: length of packet
 * return value: packet is consumed or not
 */
bool genl_dev_recv_lacpdu(struct general_device_system *dev_sys, uint32_t netdev_obj, uint8_t *buf, uint32_t buf_len);
/*
 * genl_dev_os_service_get: get operate system service provided by wrapper
 * 	return value: operate system service or NULL
 */
struct genl_os_service *genl_dev_os_service_get(void);
/*
 * genl_dev_alloc_netdev_obj_domain: allocate a magic prefix for index of network device
 * Linux network device system should not use this API because it is always the first device systems
 */
uint32_t genl_dev_alloc_netdev_obj_domain(struct general_device_system *system_obj, uint32_t max_devices);
/*
 * genl_dev_system_register: register a general device system
 */
bool genl_dev_system_register(struct general_device_system *system_obj);
/*
 * genl_dev_system_unregister: unregister a general device system
 */
void genl_dev_system_unregister(struct general_device_system *system_obj);

/*
 * APIs for lower layer below general device, end
 */

#endif /*__GENERAL_DEVICE_API_H*/
