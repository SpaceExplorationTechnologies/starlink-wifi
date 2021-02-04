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
#ifndef __LACPD_API_H
#define __LACPD_API_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <general_os_service.h>
#include <libubox/list.h>
#include <status_api.h>

enum lacp_ad_select_alg {
	LACP_AD_SELECT_ALG_ALL,
	LACP_AD_SELECT_ALG_STABLE,
	LACP_AD_SELECT_ALG_BANDWIDTH,
	LACP_AD_SELECT_ALG_COUNT,
	LACP_AD_SELECT_ALG_MAX
};

struct lacp_parameters {
	uint32_t priority;
	uint32_t lacp_rate;
	enum lacp_ad_select_alg ad_select;
};

struct lacp_port_parameters {
	uint32_t user_key;
};

/*
 * This is the APIs provided by LACP protocol instance for wrapper
 */
struct lacp_in_api {
/*
 * add_device : let a physical network device join a LACP protocol instance
 * lacp_obj: this is used to get instance of LACP protocol
 * dev_obj: requested network device
 * param: parameters for LACP port
 * return value: successful or fail
 */
bool (*add_device)(struct lacp_in_api *lacp_obj, uint32_t dev_obj, struct lacp_port_parameters *param);
/*
 * del_device : let a physical network device leave a LACP protocol instance
 * lacp_obj: this is used to get instance of LACP protocol
 * dev_obj: requested network device
 * return value: successful or fail
 */
bool (*del_device)(struct lacp_in_api *lacp_obj, uint32_t dev_obj);
/*
 * link_status_changed : notify link status event of physical network device
 * lacp_obj: this is used to get instance of LACP protocol
 * dev_obj: network device where event happen
 * new_status: new link status of device
 */
void (*link_status_changed)(struct lacp_in_api *lacp_obj, uint32_t dev_obj, int new_status);
/*
 * receive_lacpdu : receive LACP packet
 * lacp_obj: this is used to get instance of LACP protocol
 * buf: packet
 * buf_len: length of packet
 * dev_obj: receiving network device
 * return value: packet is consumed or not
 */
bool (*receive_lacpdu)(struct lacp_in_api *lacp_obj, uint8_t *buf, uint32_t buf_len, uint32_t dev_obj);
/*
 * status_dump : get status of LACP instance
 * lacp_obj: this is used to get instance of LACP protocol
 * p: lacp use this printer to print content of status
 */
void (*status_dump)(struct lacp_in_api *lacp_obj, struct lacpd_status_printer *p);
/*
 * destroy : destroy a LACP protocol instance, LACP user shouldn't reference lacp_obj after this calling
 * lacp_obj: this is used to get instance of LACP protocol
 */
void (*destroy)(struct lacp_in_api *lacp_obj);
};

/*
 * This is the APIs which should be provided by wrapper
 */
struct lacp_out_api {
/*
 * OS service provided by wrapper
 */
struct genl_os_service *os_service;
/*
 * get_sys_mac_addr : get hardware address of system
 * user: provided by wrapper, used to get device system of physical device
 * mac_addr: returned MAC address of system
 * return value: successful or fail
 */
bool (*get_sys_mac_addr)(struct lacp_out_api *user, uint8_t *mac_addr);
/*
 * get_dev_name: returns name of network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * dev_name, returned name
 * return value: point to dev_name if success, or NULL if failed
 */
char *(*get_dev_name)(struct lacp_out_api *user, uint32_t dev_obj, char *dev_name);
/*
 * get_dev_duplex : get duplex of network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: 1: full duplex, 0: half duplex
 */
uint32_t (*get_dev_duplex)(struct lacp_out_api *user, uint32_t dev_obj);
/*
 * get_dev_speed : get speed of network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: 0: invalid, 1: 1Mbps, 10: 10Mbps, 100: 100Mbps, 1000: 1Gbps, 10000: 10Gbps
 */
uint32_t (*get_dev_speed)(struct lacp_out_api *user, uint32_t dev_obj);
/*
 * get_dev_link_status : get link status of network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: true: link up; false: link down
 */
bool (*get_dev_link_status)(struct lacp_out_api *user, uint32_t dev_obj);
/*
 * get_dev_mac_addr : get hardware address of network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * mac_addr: returned MAC address of network device
 * return value: successful or fail
 */
bool (*get_dev_mac_addr)(struct lacp_out_api *user, uint32_t dev_obj, uint8_t *mac_addr);
/*
 * enable_dev : enable network device, data packet can be received on this device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: successful or fail
 */
bool (*enable_dev)(struct lacp_out_api *user, uint32_t dev_obj);
/*
 * disable_dev : disable network device, data packet is prohibited on this device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: successful or fail
 */
bool (*disable_dev)(struct lacp_out_api *user, uint32_t dev_obj);
/*
 * enable_lacp : enable LACP on network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: successful or fail
 */
bool (*enable_lacp)(struct lacp_out_api *user, uint32_t dev_obj);
/*
 * disable_lacp : disable LACP on network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * return value: successful or fail
 */
bool (*disable_lacp)(struct lacp_out_api *user, uint32_t dev_obj);
/*
 * send_lacpdu : send LACP packet on a specific network device
 * user: provided by wrapper, used to get device system of physical device
 * dev_obj: index of network device
 * buf: buffer of LACP packet
 * buf_len: length of above buffer
 * return value: successful or fail
 */
bool (*send_lacpdu)(struct lacp_out_api *user, uint32_t dev_obj, uint8_t *buf, uint32_t buf_len);
/*
 * is_slave : check if a network device is a slave of another network device
 * user: provided by wrapper, used to get device system of physical device
 * slave_dev_obj: index of network device
 * master_dev_obj: index of network device
 * return value: is a slave or not a slave
 */
bool (*is_slave)(struct lacp_out_api *user, uint32_t slave_dev_obj, uint32_t master_dev_obj);
/*
 * number_of_slaves : get number of slave network devices of a master network device
 * user: provided by wrapper, used to get device system of physical device
 * master_dev_obj: index of network device
 * return value: number of slaves
 */
uint32_t (*number_of_slaves)(struct lacp_out_api *user, uint32_t master_dev_obj);
/*
 * new_aggregator : create physical network device for aggregator
 * user: provided by wrapper, used to get device system of physical device
 * name: name of aggregator, length of name is less 64
 * return value: network device index of new aggregator
 */
uint32_t (*new_aggregator)(struct lacp_out_api *user, const char *name);
/*
 * destroy_aggregator : destroy physical network device of aggregator
 * user: provided by wrapper, used to get device system of physical device
 * aggregator_dev_obj: index of network device
 * return value: successful or fail
 */
bool (*destroy_aggregator)(struct lacp_out_api *user, uint32_t aggregator_dev_obj);
/*
 * attach_slave : attach a slave network device to a master network device
 * user: provided by wrapper, used to get device system of physical device
 * master_dev_obj: index of network device
 * slave_dev_obj: index of network device
 * return value: successful or fail
 */
bool (*attach_slave)(struct lacp_out_api *user, uint32_t master_dev_obj, uint32_t slave_dev_obj);
/*
 * detach_slave : detach a slave network device from a master network device
 * user: provided by wrapper, used to get device system of physical device
 * master_dev_obj: index of network device
 * slave_dev_obj: index of network device
 * return value: successful or fail
 */
bool (*detach_slave)(struct lacp_out_api *user, uint32_t master_dev_obj, uint32_t slave_dev_obj);
};

/*
 * lacp_new : create a LACP protocol instance
 * name: name of LACP protocol instance
 * user: APIs provided by wrapper, LACP call these APIs to configure physical device
 * param: parameters for LACP instance
 * return value: APIs provided by LACP protocol instance, wrapper call these APIs to notify packet/link event
 */
struct lacp_in_api *lacp_new(const char *name, struct lacp_out_api *user, struct lacp_parameters *param);

#endif /*__LACPD_API_H*/
