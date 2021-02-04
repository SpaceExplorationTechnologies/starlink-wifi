/*
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
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
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>

#include <net/if.h>
#include <linux/if_ether.h>
#include <linux/ethtool.h>
#include <linux/sockios.h>

#include "general_device_linux.h"

struct general_device_linux_system linux_ndev_system;

/*
 * genl_dev_linux_init : initialize network device system when it is attached to a specific OS
 * system_obj: network device system
 * return value: true: successful, false: failed
 */
static bool genl_dev_linux_init(struct general_device_system *system_obj)
{
	return true;
}

/*
 * genl_dev_linux_exit : finalize network device system when it is detached from a specific OS
 * system_obj: network device system
 * return value: true: successful, false: failed
 */
static bool genl_dev_linux_exit(struct general_device_system *system_obj)
{
	return true;
}

/*
 * genl_dev_linux_get_hw_addr : get hardware address of system
 * system_obj: network device system
 * mac_addr: returned MAC address of system
 * return value: successful or fail
 */
static bool genl_dev_linux_get_hw_addr(struct general_device_system *system_obj, uint8_t *mac_addr)
{
	return false;
}

/*
 * genl_dev_linux_ndev_is_compatible: check if a device belongs to this type of device
 */
static bool genl_dev_linux_ndev_is_compatible(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	char ifname[GENERAL_DEVICE_SYSTEM_NAME_SIZE];

	if (netdev_obj_to_domain(netdev_obj) != GENL_LINUX_NETDEV_DOMAIN) {
		return false;
	}

	return (NULL != if_indextoname(netdev_obj, ifname));
}

/*
 * genl_dev_linux_ndev_name_to_netdev_obj: returns network device according to name of network device
 */
static uint32_t genl_dev_linux_ndev_name_to_netdev_obj(struct general_device_system *system_obj, const char *netdev_name)
{
	if (!netdev_name) {
		return GENERAL_DEVICE_INVALID_ID;
	}

	return if_nametoindex(netdev_name);
}

/*
 * genl_dev_linux_netdev_obj_to_name: returns name of network device
 */
static char *genl_dev_linux_netdev_obj_to_name(struct general_device_system *system_obj, uint32_t netdev_obj, char *netdev_name)
{
	if (netdev_obj_to_domain(netdev_obj) != GENL_LINUX_NETDEV_DOMAIN) {
		return NULL;
	}

	return if_indextoname(netdev_obj, netdev_name);
}

/*
 * genl_dev_linux_ndev_get_link_status : get link status of network device
 * system_obj: network device system
 * netdev_obj: network device
 * return value: true: link up; false: link down
 */
static bool genl_dev_linux_ndev_get_link_status(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	char ifname[GENERAL_DEVICE_SYSTEM_NAME_SIZE];
	int socket_fd = -1;
	struct ifreq ifr = {};

	if (netdev_obj_to_domain(netdev_obj) != GENL_LINUX_NETDEV_DOMAIN) {
		return false;
	}

	if (NULL == if_indextoname(netdev_obj, ifname)) {
		return false;
	}

	socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (socket_fd <= 0) {
		return false;
	}

	strlcpy(ifr.ifr_name, ifname, sizeof(ifr.ifr_name));

	if(0 != ioctl(socket_fd, SIOCGIFFLAGS, &ifr)) {
		close(socket_fd);
		return false;
	}

	close(socket_fd);

	return ((ifr.ifr_flags & (IFF_UP|IFF_RUNNING)) == (IFF_UP|IFF_RUNNING));
}

/*
 * genl_dev_linux_ndev_get_duplex : get duplex of network device
 * system_obj: network device system
 * netdev_obj: network device
 * return value: 1: full duplex, 0: half duplex
 */
static uint32_t genl_dev_linux_ndev_get_duplex(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	char ifname[GENERAL_DEVICE_SYSTEM_NAME_SIZE];
	int socket_fd = -1;
	struct ethtool_cmd ecmd;
	struct ifreq ifr = {};


	if (netdev_obj_to_domain(netdev_obj) != GENL_LINUX_NETDEV_DOMAIN) {
		return 0;
	}

	if (NULL == if_indextoname(netdev_obj, ifname)) {
		return 0;
	}

	socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (socket_fd < 0) {
		return false;
	}

	ecmd.cmd = ETHTOOL_GSET;
	strlcpy(ifr.ifr_name, ifname, sizeof(ifr.ifr_name));
	ifr.ifr_data = (caddr_t)&ecmd;
	if (ioctl(socket_fd, SIOCETHTOOL, &ifr) < 0) {
		close(socket_fd);
		return false;
	}

	close(socket_fd);

	return ecmd.duplex;
}

/*
 * genl_dev_linux_ndev_get_speed : get speed of network device
 * system_obj: network device system
 * netdev_obj: network device
 * return value: 0: invalid, 1: 1Mbps, 10: 10Mbps, 100: 100Mbps, 1000: 1Gbps, 10000: 10Gbps
 */
static uint32_t genl_dev_linux_ndev_get_speed(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	char ifname[GENERAL_DEVICE_SYSTEM_NAME_SIZE];
	int socket_fd = -1;
	struct ethtool_cmd ecmd;
	struct ifreq ifr = {};


	if (netdev_obj_to_domain(netdev_obj) != GENL_LINUX_NETDEV_DOMAIN) {
		return 0;
	}

	if (NULL == if_indextoname(netdev_obj, ifname)) {
		return 0;
	}

	socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (socket_fd < 0) {
		return false;
	}

	ecmd.cmd = ETHTOOL_GSET;
	strlcpy(ifr.ifr_name, ifname, sizeof(ifr.ifr_name));
	ifr.ifr_data = (caddr_t)&ecmd;
	if (ioctl(socket_fd, SIOCETHTOOL, &ifr) < 0) {
		close(socket_fd);
		return false;
	}

	close(socket_fd);

	return ecmd.speed;
}

/*
 * genl_dev_linux_ndev_get_hw_addr : get hardware address of network device
 * system_obj: network device system
 * netdev_obj: network device
 * hw_addr: returned hw address of network device, max size is 6 bytes
 * return value: successful or fail
 */
static bool genl_dev_linux_ndev_get_hw_addr(struct general_device_system *system_obj, uint32_t netdev_obj, uint8_t *hw_addr)
{
	char ifname[GENERAL_DEVICE_SYSTEM_NAME_SIZE];
	int socket_fd = -1;
	struct ifreq ifr = {};

	if (netdev_obj_to_domain(netdev_obj) != GENL_LINUX_NETDEV_DOMAIN) {
		return false;
	}

	if (NULL == if_indextoname(netdev_obj, ifname)) {
		return false;
	}

	socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (socket_fd <= 0) {
		return false;
	}

	strlcpy(ifr.ifr_name, ifname, sizeof(ifr.ifr_name));

	if(0 != ioctl(socket_fd, SIOCGIFHWADDR, &ifr)) {
		close(socket_fd);
		return false;
	}

	close(socket_fd);

	memcpy(hw_addr, ifr.ifr_hwaddr.sa_data, ETH_ALEN);
	return true;
}

/*
 * genl_dev_linux_ndev_is_bridge_member : check if a port is in a bridge
 * system_obj: network device system
 * port_dev_obj: port
 * br_dev_obj: bridge
 * return value: true: is a bridge member, false: not a bridge member
 */
static bool genl_dev_linux_ndev_is_bridge_member(struct general_device_system *system_obj, uint32_t port_dev_obj, uint32_t br_dev_obj)
{
	char port_name[IFNAMSIZ], br_name[IFNAMSIZ];
	char path[32 + 2 * IFNAMSIZ];

	if (!genl_dev_linux_ndev_is_compatible(system_obj, br_dev_obj)) {
		return false;
	}

	if (NULL == genl_dev_linux_netdev_obj_to_name(system_obj, port_dev_obj, port_name)) {
		return false;
	}

	if (NULL == genl_dev_linux_netdev_obj_to_name(system_obj, br_dev_obj, br_name)) {
		return false;
	}

	snprintf(path, sizeof(path), "/sys/class/net/%s/brif/%s", br_name, port_name);
	return (access(path, R_OK) == 0);
}

/*
 * genl_dev_linux_ndev_flush_fdb : flush all fdb learnt on this port
 * system_obj: network device system
 * port_dev_obj: port
 * return value: true: successful, false: failed
 */
static bool genl_dev_linux_ndev_flush_fdb(struct general_device_system *system_obj, uint32_t port_dev_obj)
{
	char port_name[IFNAMSIZ], path[32 + 2 * IFNAMSIZ];
	FILE *fd;
	int ret;

	if (NULL == genl_dev_linux_netdev_obj_to_name(system_obj, port_dev_obj, port_name)) {
		return false;
	}

	/*
	 * check if it is a bridge port
	 */
	snprintf(path, sizeof(path), "/sys/class/net/%s/master/brif/%s/flush", port_name, port_name);
	fd = fopen(path, "w");
	if (fd) {
		ret = fwrite("1", 1, 1, fd);
		fclose(fd);
		if (ret == 1) {
			return true;
		}
	}

	/*
	 * check if it is a bridge
	 */
	snprintf(path, sizeof(path), "/sys/class/net/%s/bridge/flush", port_name);
	fd = fopen(path, "w");
	if (fd) {
		ret = fwrite("1", 1, 1, fd);
		fclose(fd);
		if (ret == 1) {
			return true;
		}
	}

	return false;
}

/*
 * genl_dev_linux_ndev_stp_enable : enable STP on port, this means STP protocol starts to run on this port
 * system_obj: network device system
 * netdev_obj: network device
 * return value: true: successful, false: failed
 */
static bool genl_dev_linux_ndev_stp_enable(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	/*TBD*/
	return false;
}

/*
 * genl_dev_linux_ndev_stp_disable : disable STP on port, this means STP protocol stops to run on this port
 * system_obj: network device system
 * netdev_obj: network device
 * return value: true: successful, false: failed
 */
static bool genl_dev_linux_ndev_stp_disable(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	/*TBD*/
	return false;
}

/*
 * genl_dev_linux_ndev_set_stp_state : set STP state of port
 * system_obj: network device system
 * netdev_obj: network device
 * state: state of port
 * return value: true: successful, false: failed
 */
static bool genl_dev_linux_ndev_set_stp_state(struct general_device_system *system_obj, uint32_t netdev_obj, enum general_device_stp_state state)
{
	/*TBD*/
	return false;
}

/*
 * genl_dev_linux_ndev_send_bpdu : send BPDU on port
 * system_obj: network device system
 * netdev_obj: network device
 * buf: buffer which contains BPDU
 * buf_len: length of above buffer
 * return value: true: successful, false: failed
 */
static bool genl_dev_linux_ndev_send_bpdu(struct general_device_system *system_obj, uint32_t netdev_obj, const uint8_t *buf, uint32_t buf_len)
{
	/*TBD*/
	return false;
}

/*
 * genl_dev_linux_ndev_lacp_enable : enable LACP on port, this means LACP protocol starts to run on this port
 * system_obj: network device system
 * netdev_obj: network device
 * return value: true: successful, false: failed
 */
static bool genl_dev_linux_ndev_lacp_enable(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	/*TBD*/
	return false;
}

/*
 * genl_dev_linux_ndev_lacp_disable : disable LACP on port, this means LACP protocol stops to run on this port
 * system_obj: network device system
 * netdev_obj: network device
 * return value: true: successful, false: failed
 */
static bool genl_dev_linux_ndev_lacp_disable(struct general_device_system *system_obj, uint32_t netdev_obj)
{
	/*TBD*/
	return false;
}

/*
 * genl_dev_linux_new_aggregator : create physical network device for aggregator
 * system_obj: network device system
 * agg_name: name of aggregator, length of name is less 64
 * return value: network device object for new aggregator
 */
static uint32_t genl_dev_linux_new_aggregator(struct general_device_system *system_obj, const char *agg_name)
{
	/*TBD*/
	return GENERAL_DEVICE_INVALID_ID;
}

/*
 * genl_dev_linux_destroy_aggregator : destroy physical network device of aggregator
 * system_obj: network device system
 * aggregator_dev_obj: network device for aggregator
 * return value: successful or fail
 */
static bool genl_dev_linux_destroy_aggregator(struct general_device_system *system_obj, uint32_t aggregator_dev_obj)
{
	/*TBD*/
	return false;
}

/*
 * genl_dev_linux_ndev_is_aggregator : check if a network device is a aggregator
 * system_obj: network device system
 * master_dev_obj: network device for aggregator
 * slave_dev_obj: network device for port in aggregator, could be 0
 * return value: successful or fail
 */
static bool genl_dev_linux_ndev_is_aggregator(struct general_device_system *system_obj, uint32_t master_dev_obj, uint32_t slave_dev_obj)
{
	/*TBD*/
	return false;
}

/*
 * genl_dev_linux_ndev_is_slave : check if a network device is a slave of another network device
 * system_obj: network device system
 * slave_dev_obj: network device for port in aggregator
 * master_dev_obj: network device for aggregator, could be 0
 * return value: is a slave or not a slave
 */
static bool genl_dev_linux_ndev_is_slave(struct general_device_system *system_obj, uint32_t slave_dev_obj, uint32_t master_dev_obj)
{
	/*TBD*/
	return false;
}

/*
 * genl_dev_linux_ndev_number_of_slaves : number of slave network devices of a master network device
 * system_obj: network device system
 * master_dev_obj: network device for aggregator
 * return value: number of slaves
 */
static uint32_t genl_dev_linux_ndev_number_of_slaves(struct general_device_system *system_obj, uint32_t master_dev_obj)
{
	/*TBD*/
	return 0;
}

/*
 * genl_dev_linux_ndev_attach_slave : attach a slave network device to a master network device
 * system_obj: network device system
 * master_dev_obj: network device for aggregator
 * slave_dev_obj: network device for port in aggregator
 * return value: successful or fail
 */
static bool genl_dev_linux_ndev_attach_slave(struct general_device_system *system_obj, uint32_t master_dev_obj, uint32_t slave_dev_obj)
{
	/*TBD*/
	return false;
}

/*
 * genl_dev_linux_ndev_detach_slave : detach a slave network device from a master network device
 * system_obj: network device system
 * master_dev_obj: network device for aggregator
 * slave_dev_obj: network device for port in aggregator
 * return value: successful or fail
 */
static bool genl_dev_linux_ndev_detach_slave(struct general_device_system *system_obj, uint32_t master_dev_obj, uint32_t slave_dev_obj)
{
	/*TBD*/
	return false;
}

/*
 * genl_dev_linux_ndev_send_lacpdu : send LACPDU on port
 * system_obj: network device system
 * netdev_obj: network device
 * buf: buffer which contains LACPDU
 * buf_len: length of above buffer
 * return value: true: successful, false: failed
 */
static bool genl_dev_linux_ndev_send_lacpdu(struct general_device_system *system_obj, uint32_t netdev_obj, const uint8_t *buf, uint32_t buf_len)
{
	/*TBD*/
	return false;
}

/*
 * genl_dev_linux_probe : register Linux network device system
 */
void genl_dev_linux_probe(void)
{
	struct general_device_linux_system *linux_sys = &linux_ndev_system;
	struct general_device_system *dev_sys = &linux_sys->base;

	snprintf(dev_sys->name, sizeof(dev_sys->name), "linux");
	dev_sys->init = genl_dev_linux_init;
	dev_sys->exit = genl_dev_linux_exit;
	dev_sys->system.get_hw_addr = genl_dev_linux_get_hw_addr;
	dev_sys->common.is_compatible = genl_dev_linux_ndev_is_compatible;
	dev_sys->common.name_to_netdev_obj = genl_dev_linux_ndev_name_to_netdev_obj;
	dev_sys->common.netdev_obj_to_name = genl_dev_linux_netdev_obj_to_name;
	dev_sys->common.get_link_status = genl_dev_linux_ndev_get_link_status;
	dev_sys->common.get_duplex = genl_dev_linux_ndev_get_duplex;
	dev_sys->common.get_speed = genl_dev_linux_ndev_get_speed;
	dev_sys->common.get_hw_addr = genl_dev_linux_ndev_get_hw_addr;
	dev_sys->bridge.is_bridge_member = genl_dev_linux_ndev_is_bridge_member;
	dev_sys->bridge.flush_fdb = genl_dev_linux_ndev_flush_fdb;
	dev_sys->stp.enable = genl_dev_linux_ndev_stp_enable;
	dev_sys->stp.disable = genl_dev_linux_ndev_stp_disable;
	dev_sys->stp.set_port_state = genl_dev_linux_ndev_set_stp_state;
	dev_sys->stp.send_bpdu = genl_dev_linux_ndev_send_bpdu;
	dev_sys->agg.enable = genl_dev_linux_ndev_lacp_enable;
	dev_sys->agg.disable = genl_dev_linux_ndev_lacp_disable;
	dev_sys->agg.new_aggregator = genl_dev_linux_new_aggregator;
	dev_sys->agg.destroy_aggregator = genl_dev_linux_destroy_aggregator;
	dev_sys->agg.is_aggregator = genl_dev_linux_ndev_is_aggregator;
	dev_sys->agg.is_slave = genl_dev_linux_ndev_is_slave;
	dev_sys->agg.number_of_slaves = genl_dev_linux_ndev_number_of_slaves;
	dev_sys->agg.attach_slave = genl_dev_linux_ndev_attach_slave;
	dev_sys->agg.detach_slave = genl_dev_linux_ndev_detach_slave;
	dev_sys->agg.send_lacpdu = genl_dev_linux_ndev_send_lacpdu;

	genl_dev_system_register(dev_sys);
}
