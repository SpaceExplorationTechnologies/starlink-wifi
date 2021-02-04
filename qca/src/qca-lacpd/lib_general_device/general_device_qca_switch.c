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
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <linux/if_packet.h>
#include <api/sw_ioctl.h>

#include "general_device_qca_switch.h"

/*
 * Utilities start
 */
/*
 * qca_switch_shell_cmd: run a specific command in shell script "/lib/functions/qca_switch_config.sh"
 * return value : length of string in result
 */
static int qca_switch_shell_cmd(const char *cmd, char *result, int max_len)
{
	FILE *fp = NULL;
	int result_len = 0;

	memset(result, 0, max_len);
	fp = popen(cmd, "r");
	if (!fp) {
		return 0;
	}

	while(fgets(result + result_len, max_len - result_len - 1, fp)) {
		result_len += strlen(result + result_len);
		if(result_len + 1 == max_len)
			break;
	}

	pclose(fp);
	return result_len;
}

/*
 * qca_switch_shell_cmd_get_int: simple shell command just return an integer
 * return value : >=0, result of command; <0, failed
 */
static int qca_switch_shell_cmd_get_int(const char *sw_name, const char *cmd)
{
	char cmd_buf[QCA_SW_SHELL_CMD_SIZE];
	char result_buf[QCA_SW_SHELL_CMD_RESULT_SIZE];

	if (sw_name) {
		snprintf(cmd_buf, sizeof(cmd_buf), "%s %s %s", QCA_SW_CONFIG_PATH, cmd, sw_name);
	} else {
		snprintf(cmd_buf, sizeof(cmd_buf), "%s %s", QCA_SW_CONFIG_PATH, cmd);
	}

	if (!qca_switch_shell_cmd(cmd_buf, result_buf, sizeof(result_buf))) {
		return -1;
	}

	return strtol(result_buf, NULL, 0);
}

/*
 * qca_switch_shell_cmd_get_word_list: run command, and get a list of word
 * return value : >=0, number of word; <0, failed
 */
static int qca_switch_shell_cmd_get_word_list(const char *sw_name, const char *cmd, char word_list[][QCA_SW_SHELL_CMD_WORD_SIZE], int max)
{
	char cmd_buf[QCA_SW_SHELL_CMD_SIZE];
	char result_buf[QCA_SW_SHELL_CMD_RESULT_SIZE];
	int result_len, word_cnt;
	char *index;

	if (sw_name) {
		snprintf(cmd_buf, sizeof(cmd_buf), "%s %s %s", QCA_SW_CONFIG_PATH, cmd, sw_name);
	} else {
		snprintf(cmd_buf, sizeof(cmd_buf), "%s %s", QCA_SW_CONFIG_PATH, cmd);
	}

	result_len = qca_switch_shell_cmd(cmd_buf, result_buf, sizeof(result_buf));
	if (result_len <= 0) {
		return 0;
	}

	for(index = result_buf, word_cnt = 0; index < (result_buf + result_len) && word_cnt < max; index += strlen(word_list[word_cnt]), ++word_cnt) {
		while((*index == ' ') || (*index == '\r') || (*index == '\n'))++index;
		if (*index == 0) {
			break;
		}

		if(sscanf(index, "%64s", word_list[word_cnt]) <= 0) {
			break;
		}
	}

	return word_cnt;
}

/*
 * qca_switch_api_param_nums: calculate number of parameters for a specific API
 */
static uint32_t qca_switch_api_param_nums(uint32_t api_id)
{
	switch(api_id) {
	case SW_API_MIRROR_ANALY_PT_SET:
	case SW_API_FDB_RESV_ADD:
	case SW_API_FDB_RESV_DEL:
	case SW_API_TRUNK_HASH_SET:
	case SW_API_TRUNK_HASH_GET:
		return 2;
	case SW_API_FDB_DELPORT:
	case SW_API_PT_SPEED_GET:
	case SW_API_PT_DUPLEX_GET:
	case SW_API_PT_LINK_STATUS_GET:
	case SW_API_HEADER_TYPE_SET:
	case SW_API_PT_RXHDR_SET:
	case SW_API_PT_TXHDR_SET:
		return 3;
	case SW_API_STP_PT_STATE_SET:
	case SW_API_TRUNK_GROUP_SET:
	case SW_API_TRUNK_GROUP_GET:
		return 4;
	}

	return 0;
}

static int qca_switch_driver_fd = -1;

/*
 * qca_switch_ioctl: use ioctl to talk with QCA switch driver to configure QCA switch
 */
static bool qca_switch_ioctl(uint32_t api_id, ...)
{
	uint32_t value[QCA_SW_API_MAX_PARAM] = { 0 };
	uint32_t rtn = 0, i;
	int rv;
	va_list arg_ptr;
	uint32_t nr_param = 0;

	if((nr_param = qca_switch_api_param_nums(api_id)) == 0)
		return false;

	if(qca_switch_driver_fd < 0) {
		qca_switch_driver_fd = open("/dev/switch_ssdk", O_RDWR);
		if(qca_switch_driver_fd < 0)
			return false;
	}

	value[0] = api_id;
	value[1] = (uint32_t)&rtn;

	va_start(arg_ptr, api_id);
	for (i = 0; i < nr_param; i++) {
		value[i + 2] = va_arg(arg_ptr, uint32_t);
	}
	va_end(arg_ptr);

	rv = ioctl(qca_switch_driver_fd, SIOCDEVPRIVATE, value);
	if (rv) {
		return false;
	}

	return (rtn == 0);
}

/*
 * qca_switch_enable_private_header: configure private header in switch
 */
static bool qca_switch_enable_private_header(struct qca_switch_system *qca_sw, bool enable)
{
	bool ret = false;

	if (qca_sw->private_hdr_type == 0) {
		/*
		 * No need to configure private header
		 */
		return true;
	}

	enable ? (++qca_sw->private_hdr_enabled) : (--qca_sw->private_hdr_enabled);
	if (qca_sw->private_hdr_enabled != enable) {
		return true;
	}

	ret = qca_switch_ioctl(SW_API_HEADER_TYPE_SET, qca_sw->base.switch_obj, enable, (enable ? qca_sw->private_hdr_type : 0));
	if (!ret) {
		enable ? (--qca_sw->raw_socket_enabled) : (++qca_sw->raw_socket_enabled);
	}

	return ret;
}

/*
 * qca_switch_enable_private_header_on_cpu_port: enable/disable private header on CPU port
 */
static bool qca_switch_enable_private_header_on_cpu_port(struct qca_switch_system *qca_sw, bool enable)
{
	bool ret = false;

	if (qca_sw->cpu_port < 0) {
		/*
		 * No need to configure private header
		 */
		return true;
	}

	enable ? (++qca_sw->cpu_port_priv_hdr_enabled) : (--qca_sw->cpu_port_priv_hdr_enabled);
	if (qca_sw->cpu_port_priv_hdr_enabled != enable) {
		return true;
	}

	ret = qca_switch_ioctl(SW_API_PT_RXHDR_SET, qca_sw->base.switch_obj, qca_sw->cpu_port, enable);
	ret = ret && qca_switch_ioctl(SW_API_PT_TXHDR_SET, qca_sw->base.switch_obj, qca_sw->cpu_port, enable);
	if (!ret) {
		enable ? (--qca_sw->cpu_port_priv_hdr_enabled) : (++qca_sw->cpu_port_priv_hdr_enabled);
	}

	return ret;
}

/*
 * qca_switch_enable_private_header_on_mirror_port: enable/disable private header on mirror port
 */
static bool qca_switch_enable_private_header_on_mirror_port(struct qca_switch_system *qca_sw, bool enable)
{
	bool ret = false;

	if (qca_sw->mirror_port < 0) {
		/*
		 * No need to configure private header
		 */
		return true;
	}

	enable ? (++qca_sw->mirror_port_priv_hdr_enabled) : (--qca_sw->mirror_port_priv_hdr_enabled);
	if (qca_sw->mirror_port_priv_hdr_enabled != enable) {
		return true;
	}

	ret = qca_switch_ioctl(SW_API_PT_RXHDR_SET, qca_sw->base.switch_obj, qca_sw->mirror_port, enable);
	ret = ret && qca_switch_ioctl(SW_API_PT_TXHDR_SET, qca_sw->base.switch_obj, qca_sw->mirror_port, enable);
	ret = ret && qca_switch_ioctl(SW_API_MIRROR_ANALY_PT_SET, qca_sw->base.switch_obj, qca_sw->mirror_port);
	if (!ret) {
		enable ? (--qca_sw->mirror_port_priv_hdr_enabled) : (++qca_sw->mirror_port_priv_hdr_enabled);
	}

	return ret;
}

fal_fdb_entry_t resv_entries[QCA_SW_RESV_FDB_MAX] =
{
	{
		{{0x01,0x80,0xc2,0x0,0x0,0x0}},	/*addr*/
		65535,							/*fid*/
		FAL_MAC_RDT_TO_CPU,				/*dacmd*/
		FAL_MAC_FRWRD,					/*sacmd*/
		{0},							/*port.map*/
		true,							/*portmap_en*/
		true,							/*is_multicast*/
		true,							/*static_en*/
		false,							/*leaky_en*/
		true,							/*mirror_en*/
		false,							/*clone_en*/
		true,							/*cross_pt_state*/
		false,							/*da_pri_en*/
		false,							/*da_queue*/
		false,							/*white_list_en*/
	},
	{
		{{0x01,0x80,0xc2,0x0,0x0,0x2}},	/*addr*/
		65535,							/*fid*/
		FAL_MAC_RDT_TO_CPU,				/*dacmd*/
		FAL_MAC_FRWRD,					/*sacmd*/
		{0},							/*port.map*/
		true,							/*portmap_en*/
		true,							/*is_multicast*/
		true,							/*static_en*/
		false,							/*leaky_en*/
		true,							/*mirror_en*/
		false,							/*clone_en*/
		true,							/*cross_pt_state*/
		false,							/*da_pri_en*/
		false,							/*da_queue*/
		false,							/*white_list_en*/
	}
};

/*
 * qca_switch_enable_reserved_fdb : Add a reserved FDB to trap/mirror control/protocol packet
 */
static bool qca_switch_enable_reserved_fdb(struct qca_switch_system *qca_sw, enum qca_sw_reserved_fdb_type type, bool enable)
{
	int ret = false, *counter;

	switch (type) {
	case QCA_SW_RESV_FDB_STP:
		counter = &qca_sw->stp_reserved_fdb_enabled;
		break;
	case QCA_SW_RESV_FDB_LACP:
		counter = &qca_sw->lacp_reserved_fdb_enabled;
		break;
	default:
		return false;
	}

	enable ? (++(*counter)) : (--(*counter));
	if ((*counter) != enable) {
		return true;
	}

	ret = qca_switch_ioctl((enable ? SW_API_FDB_RESV_ADD : SW_API_FDB_RESV_DEL), qca_sw->base.switch_obj, (uint32_t)&resv_entries[type]);
	if (!ret) {
		enable ? (--(*counter)) : (++(*counter));
	}

	return ret;
}

/*
 * qca_switch_private_header_parse : parse QCA switch private header in packet
 * buf: buffer for packet
 * buf_len: length of above buffer
 * src_port: returned value, which switch port is this packet received from
 * priv_hdr_start: point to start of private header
 * priv_hdr_end: point to end of private header
 * return value: success or fail
 */
static bool qca_switch_private_header_parse(struct qca_switch_system *qca_sw, uint8_t *buf, uint32_t buf_len, uint32_t *src_port,  uint8_t **priv_hdr_start, uint8_t **priv_hdr_end)
{
	struct qca_sw_priv_hdr_rx *hdr;

	if (buf_len < (QCA_SW_PRIV_HDR_OFFSET + sizeof(struct qca_sw_priv_hdr_rx))) {
		return false;
	}

	*priv_hdr_start = buf + QCA_SW_PRIV_HDR_OFFSET;
	*priv_hdr_end = *priv_hdr_start + sizeof(struct qca_sw_priv_hdr_rx);

	hdr = (struct qca_sw_priv_hdr_rx *)(*priv_hdr_start);
	*((uint32_t *)hdr) = ntohl(*((uint32_t *)hdr));
	if ((hdr->version != QCA_SW_PRIV_HDR_VERSION) || (hdr->type != qca_sw->private_hdr_type)) {
		return false;
	}

	*src_port = hdr->src_port;
	return true;
}

/*
 * qca_switch_pkt_type_parse : get packet type, such as BPDU, LACPDU
 * buf: buffer for packet
 * buf_len: length of above buffer
 * return value: packet type
 */
static enum qca_sw_pkt_type qca_switch_pkt_type_parse(uint8_t *buf, uint32_t buf_len)
{
	static uint8_t bpdu_dst_mac[GENERAL_DEVICE_HW_ADDR_SIZE] = {0x01, 0x80, 0xc2, 0x0, 0x0, 0x0};
	static uint8_t lacpdu_dst_mac[GENERAL_DEVICE_HW_ADDR_SIZE] = {0x01, 0x80, 0xc2, 0x0, 0x0, 0x2};

	if (!memcmp(buf, bpdu_dst_mac, sizeof(bpdu_dst_mac))) {
		return QCA_SW_PKT_TYPE_BPDU;
	}

	if (!memcmp(buf, lacpdu_dst_mac, sizeof(lacpdu_dst_mac))) {
		return QCA_SW_PKT_TYPE_LACPDU;
	}

	return QCA_SW_PKT_TYPE_UNKNOWN;
}

/*
 * qca_switch_calculate_dest_port_in_agg : calculate designated port when sending packet on a trunk
 * qca_sw: switch system
 * agg: trunk to send packet
 * buf: buffer for packet
 * return value: trunk member where packet is finally sent to
 */
static int qca_switch_calculate_dest_port_in_agg(struct qca_switch_system *qca_sw, struct switch_port *agg, uint8_t *buf)
{
	int idx, ports[QCA_SW_PORT_NUM], ports_cnt = 0;
	uint8_t mac_hash = 0;

	/*
	 * Init trunk members
	 */
	for (idx = 0; idx < QCA_SW_PORT_NUM; idx++) {
		ports[idx] = -1;
	}

	for (idx = QCA_SW_PORT_ID_MIN; idx <= QCA_SW_PORT_ID_MAX; idx++) {
		if ((1 << idx) & agg->port_num) {
			ports[ports_cnt++] = idx;
		}
	}

	/*
	 * Return error if no trunk members
	 */
	if (ports_cnt == 0) {
		DP(GENL_DEVICE, WARNING, "Trunk has no member when calculate destination port in trunk");
		return -1;
	}

	/*
	 * Return if only one trunk member
	 */
	if (ports_cnt == 1) {
		DP(GENL_DEVICE, DEBUG, "Trunk has only one member, skip calculating");
		return ports[0];
	}

	/*
	 * calculate hash by xor every 2 bits in destination mac and source mac
	 */
	for (idx = 0; idx < (2 * GENERAL_DEVICE_HW_ADDR_SIZE); idx++) {
		mac_hash ^= (buf[idx] & 0x3) ^ ((buf[idx] >> 2) & 0x3) ^ ((buf[idx] >> 4) & 0x3) ^ ((buf[idx] >> 6) & 0x3);
	}

	/*
	 * Adjust hash if we can't get a valid trunk member by hash
	 */
	for (idx = 0; idx < QCA_SW_MAX_MEMBERS_IN_AGG; idx++) {
		uint8_t adjust_hash = mac_hash ^ idx;
		if (ports[adjust_hash] != -1) {
			return ports[adjust_hash];
		}
	}

	DP(GENL_DEVICE, WARNING, "Calculate destination port in trunk failed");
	return -1;
}

/*
 * qca_switch_change_smac_according_to_hash_alg : change source mac address according to hash algorithm to
 * 						  send packet on a designated port
 * qca_sw: switch system
 * port: switch port which we want to send packet to
 * buf: buffer for packet
 * return value: successful or fail
 */
static bool qca_switch_change_smac_according_to_hash_alg(struct qca_switch_system *qca_sw, struct switch_port *port, uint8_t *buf)
{
	struct switch_port *master = port->agg_parent;
	uint8_t *byte_to_change = &buf[2 * GENERAL_DEVICE_HW_ADDR_SIZE - 1];
	uint8_t original_byte = *byte_to_change;
	int idx;

	if (!master) {
		DP(GENL_DEVICE, DEBUG, "Port is not member of trunk, no need to change source MAC");
		return true;
	}

	for (idx = 0; idx < QCA_SW_MAX_MEMBERS_IN_AGG; idx++) {
		*byte_to_change = original_byte ^ idx;
		if (qca_switch_calculate_dest_port_in_agg(qca_sw, master, buf) == port->port_num) {
			return true;
		}
	}

	DP(GENL_DEVICE, WARNING, "changing source MAC failed on port %d", port->port_num);
	return false;
}

/*
 * qca_switch_recv_packet : receive control/protocol packet
 */
static void qca_switch_recv_packet(struct genl_os_service_fd *fd, unsigned int events)
{
	struct qca_switch_system *qca_sw = (struct qca_switch_system *)fd->arg;
	uint8_t buf[QCA_SW_CONTROL_PKT_MAX_SIZE];
	struct sockaddr_ll sl;
	socklen_t salen = sizeof(sl);
	int ret_buf_len, adjusted_buf_len, src_port;
	uint8_t *priv_hdr_start, *priv_hdr_end;
	uint8_t *adjusted_buf;
	enum qca_sw_pkt_type pkt_type;
	char control_channel[GENERAL_DEVICE_SYSTEM_NAME_SIZE];
	bool ret;

	if (!(events & GENL_OS_SERVICE_FD_EVENTS_READ)) {
		DP(GENL_DEVICE, WARNING, "event %d is not read event, return", events);
		return;
	}

	ret_buf_len = recvfrom(fd->fd, buf, sizeof(buf), 0, (struct sockaddr *) &sl, &salen);
	if (ret_buf_len <= 0) {
		DP(GENL_DEVICE, WARNING, "recvfrom failed: %m");
		return;
	}

	if (NULL == genl_dev_netdev_obj_to_name(sl.sll_ifindex, control_channel)) {
		DP(GENL_DEVICE, WARNING, "received packet from unknown network device");
		return;
	}

	ret = qca_switch_private_header_parse(qca_sw, buf, ret_buf_len, (uint32_t *)&src_port, &priv_hdr_start, &priv_hdr_end);
	if (!ret) {
		DP(GENL_DEVICE, WARNING, "Parse QCA private header failed");
		return;
	}

	adjusted_buf = buf + (priv_hdr_end - priv_hdr_start);
	memmove(adjusted_buf, buf, (priv_hdr_start - buf));
	adjusted_buf_len = ret_buf_len - (priv_hdr_end - priv_hdr_start);

	pkt_type = qca_switch_pkt_type_parse(adjusted_buf, adjusted_buf_len);
	switch (pkt_type) {
	case QCA_SW_PKT_TYPE_BPDU:
		ret = genl_dev_sw_port_recv_bpdu(&qca_sw->base, control_channel, src_port, adjusted_buf, adjusted_buf_len);
		break;
	case QCA_SW_PKT_TYPE_LACPDU:
		ret = genl_dev_sw_port_recv_lacpdu(&qca_sw->base, control_channel, src_port, adjusted_buf, adjusted_buf_len);
		break;
	default:
		DP(GENL_DEVICE, WARNING, "Received unknown packet");
		break;
	}
}

/*
 * qca_switch_send_packet : send control/protocol packet
 * qca_sw: switch system
 * port: switch port
 * buf: buffer for packet
 * buf_len: length of above buffer
 * return value: success or fail
 */
static bool qca_switch_send_packet(struct qca_switch_system *qca_sw, struct switch_port *port, const uint8_t *buf, uint32_t buf_len)
{
	uint32_t control_channel_netdev_obj, copied_buf_len;
	uint8_t *copied_buf, *priv_hdr_start, *priv_hdr_end;
	struct qca_sw_priv_hdr_tx *hdr;
	struct sockaddr_ll sl;
	int sent_len;

	control_channel_netdev_obj = genl_dev_name_to_netdev_obj(port->control_channel);
	if (netdev_obj_is_invalid(control_channel_netdev_obj)) {
		DP(GENL_DEVICE, WARNING, "Can't resolve control channel of switch port %s", port->name);
		return false;
	}

	memset(&sl, 0, sizeof(sl));
	sl.sll_family = AF_PACKET;
	sl.sll_protocol = htons(qca_sw->private_hdr_type);
	sl.sll_ifindex = control_channel_netdev_obj;
	sl.sll_halen = GENERAL_DEVICE_HW_ADDR_SIZE;
	memcpy(&sl.sll_addr, buf, GENERAL_DEVICE_HW_ADDR_SIZE);

	copied_buf = (uint8_t *)malloc(QCA_SW_CONTROL_PKT_MAX_SIZE);
	if (!copied_buf) {
		DP(GENL_DEVICE, CRIT, "Failed to allocate memory to copy packet");
		return false;
	}

	priv_hdr_start = copied_buf + QCA_SW_PRIV_HDR_OFFSET;
	priv_hdr_end = priv_hdr_start + sizeof(struct qca_sw_priv_hdr_tx);

	memcpy(copied_buf, buf, (priv_hdr_start - copied_buf));
	memcpy(priv_hdr_end, buf + (priv_hdr_start - copied_buf), (buf_len - (priv_hdr_start - copied_buf)));
	copied_buf_len = buf_len + (priv_hdr_end - priv_hdr_start);

	hdr = (struct qca_sw_priv_hdr_tx *)priv_hdr_start;
	hdr->type = qca_sw->private_hdr_type;
	hdr->version = QCA_SW_PRIV_HDR_VERSION;
	hdr->priority = 7;
	hdr->action = 0;
	hdr->from_cpu = 1;
	hdr->dst_port = (1 << port->port_num);
	*((uint32_t *)hdr) = htonl(*((uint32_t *)hdr));

	if (switch_port_is_agg_slave(port) && !qca_sw->support_priv_hdr_in_agg) {
		/*
		 * We want to specify destination port by private header, but hardware don't support it in trunk
		 * so we have to crack source mac address to send it on what port we want.
		 */
		qca_switch_change_smac_according_to_hash_alg(qca_sw, port, copied_buf);
	}

	sent_len = sendto(qca_sw->raw_socket.fd, copied_buf, copied_buf_len, 0, (struct sockaddr *) &sl, sizeof(sl));
	if (sent_len < 0) {
		DP(GENL_DEVICE, NOTICE, "Send packet failed");
	} else if (sent_len != copied_buf_len) {
		DP(GENL_DEVICE, NOTICE, "Short send %d instead of %d", sent_len, copied_buf_len);
	}

	free(copied_buf);
	return (sent_len == copied_buf_len);
}

/*
 * qca_switch_enable_raw_socket : Open raw socket to receive control/protocol packet
 */
static bool qca_switch_enable_raw_socket(struct qca_switch_system *qca_sw, bool enable)
{
	struct genl_os_service *os_service = genl_dev_os_service_get();
	bool ret = false;

	if (!os_service) {
		return false;
	}

	if (qca_sw->private_hdr_type == 0) {
		/*
		 * No need to configure private header
		 */
		return false;
	}

	enable ? (++qca_sw->raw_socket_enabled) : (--qca_sw->raw_socket_enabled);
	if (qca_sw->raw_socket_enabled != enable) {
		return true;
	}

	if (enable) {
		qca_sw->raw_socket.fd = socket(PF_PACKET, SOCK_RAW, htons(qca_sw->private_hdr_type));
		if (qca_sw->raw_socket.fd >= 0) {
			if (fcntl(qca_sw->raw_socket.fd, F_SETFL, (fcntl(qca_sw->raw_socket.fd, F_GETFL, 0) | O_NONBLOCK)) >= 0) {
				qca_sw->raw_socket.cb = qca_switch_recv_packet;
				qca_sw->raw_socket.arg = (void *)qca_sw;
				if (os_service->fd_add(&qca_sw->raw_socket, GENL_OS_SERVICE_FD_FLAGS_READ)) {
					ret = true;
					DP(GENL_DEVICE, DEBUG, "open lacp/stp raw socket successful");
				}
			}
		}
	} else {
		if (os_service->fd_del(&qca_sw->raw_socket)) {
			if (close(qca_sw->raw_socket.fd) >= 0) {
				qca_sw->raw_socket.fd = 0;
				ret = true;
				DP(GENL_DEVICE, DEBUG, "close lacp/stp raw socket successful");
			}
		}
	}

	if (!ret) {
		enable ? (--qca_sw->raw_socket_enabled) : (++qca_sw->raw_socket_enabled);
	}

	return ret;
}

/*
 * qca_switch_allocate_agg_id : allocate a free aggregator id
 */
static uint32_t qca_switch_allocate_agg_id(struct qca_switch_system *qca_sw)
{
	uint32_t idx;

	for (idx = QCA_SW_AGG_ID_MIN; idx <= QCA_SW_AGG_ID_MAX; idx++) {
		if (!(qca_sw->agg_id_bitmap & (1 << idx))) {
			qca_sw->agg_id_bitmap |= (1 << idx);
			return idx;
		}
	}

	return QCA_SW_AGG_ID_MAX + 1;
}

/*
 * qca_switch_free_agg_id : free an aggregator id
 */
static void qca_switch_free_agg_id(struct qca_switch_system *qca_sw, uint32_t agg_id)
{
	if (!qca_sw_agg_id_is_valid(qca_sw, agg_id)) {
		return;
	}

	qca_sw->agg_id_bitmap &= ~(1 << agg_id);
}

/*
 * qca_sw_agg_id_is_active : check if an aggregator id is allocated
 */
static bool qca_sw_agg_id_is_active(struct qca_switch_system *qca_sw, uint32_t agg_id)
{
	if (!qca_sw_agg_id_is_valid(qca_sw, agg_id)) {
		return false;
	}

	return (qca_sw->agg_id_bitmap & (1 << agg_id)) != 0;
}

/*
 * qca_switch_load_runtime_ports : load all switch ports from "/tmp/qca_switch_ports"
 */
static bool qca_switch_load_runtime_ports(struct qca_switch_system *qca_sw)
{
	return false;
}

/*
 * qca_switch_load_ports : load all switch ports from configuration file
 */
static bool qca_switch_load_ports(struct qca_switch_system *qca_sw)
{
	char ports_desc[QCA_SW_WORDS_PER_PORT * QCA_SW_PORT_NUM][QCA_SW_SHELL_CMD_WORD_SIZE];
	struct general_device_switch_system *sw_sys = &qca_sw->base;
	int num_of_words = qca_switch_shell_cmd_get_word_list(sw_sys->name, "get_switch_ports", ports_desc, (QCA_SW_WORDS_PER_PORT * QCA_SW_PORT_NUM));
	char *sw_name, *ctrl_ch, *data_ch, port_name[GENERAL_DEVICE_SYSTEM_NAME_SIZE];
	uint32_t idx, port_num, switch_port_obj, netdev_obj;
	struct switch_port *port;

	for (idx = 0; (idx + QCA_SW_WORDS_PER_PORT) <= num_of_words; idx += QCA_SW_WORDS_PER_PORT) {
		/*
		 * Description of port is like this: "@switch_name control_channel data_channel port_num port_name"
		 */
		sw_name = ports_desc[idx + QCA_SW_PORT_DESC_SW_NAME] + 1;
		ctrl_ch = ports_desc[idx + QCA_SW_PORT_DESC_CTRL_CH];
		data_ch = ports_desc[idx + QCA_SW_PORT_DESC_DATA_CH];
		port_num = strtol(ports_desc[idx + QCA_SW_PORT_DESC_PT_NUM], NULL, 0);

		/*
		 * Validate configuration start
		 */
		if (strncmp(sw_name, sw_sys->name, sizeof(sw_sys->name))) {
			continue;
		}

		netdev_obj = genl_dev_name_to_netdev_obj(ctrl_ch);
		if (netdev_obj_is_invalid(netdev_obj)) {
			DP(GENL_DEVICE, CRIT, "Control channel %s not exist", ctrl_ch);
			continue;
		}

		netdev_obj = genl_dev_name_to_netdev_obj(data_ch);
		if (netdev_obj_is_invalid(netdev_obj)) {
			DP(GENL_DEVICE, CRIT, "Data channel %s not exist", data_ch);
			continue;
		}

		if (port_num < QCA_SW_PORT_ID_MIN || port_num > QCA_SW_PORT_ID_MAX) {
			DP(GENL_DEVICE, CRIT, "Switch port number %d is not in valid range", port_num);
			continue;
		}
		/*
		 * Validate configuration end
		 */

		switch_port_obj = qca_sw->port_domain + port_num;
		snprintf(port_name, sizeof(port_name), "%s.%s", ctrl_ch, ports_desc[idx + QCA_SW_PORT_DESC_PT_NAME]);

		port = genl_dev_sw_port_create(sw_sys, port_name, port_num, switch_port_obj, ctrl_ch, data_ch);
		if (!port) {
			DP(GENL_DEVICE, CRIT, "Create switch port %s failed", port_name);
			return false;
		}
	}

	return true;
}

/*
 * Utilities end
 */

/*
 * qca_switch_port_get_link_status : get link status of switch port
 * port: switch port
 * return value: true: link up; false: link down
 */
static bool qca_switch_port_get_link_status(struct switch_port *port)
{
	int status = false;

	if (!port) {
		return false;
	}

	qca_switch_ioctl(SW_API_PT_LINK_STATUS_GET, port->sw_sys->switch_obj, port->port_num, (uint32_t)(&status));

	return status;
}

/*
 * qca_switch_port_get_duplex : get duplex of switch port
 * port: switch port
 * return value: 1: full duplex, 0: half duplex
 */
static uint32_t qca_switch_port_get_duplex(struct switch_port *port)
{
	int duplex = 0;

	if (!port) {
		return duplex;
	}

	qca_switch_ioctl(SW_API_PT_DUPLEX_GET, port->sw_sys->switch_obj, port->port_num, (uint32_t)(&duplex));

	return duplex;
}

/*
 * get_speed : get speed of switch port
 * port: switch port
 * return value: 0: invalid, 1: 1Mbps, 10: 10Mbps, 100: 100Mbps, 1000: 1Gbps, 10000: 10Gbps
 */
static uint32_t qca_switch_port_get_speed(struct switch_port *port)
{
	int speed = 0;

	if (!port) {
		return speed;
	}

	qca_switch_ioctl(SW_API_PT_SPEED_GET, port->sw_sys->switch_obj, port->port_num, (uint32_t)(&speed));

	return speed;
}

/*
 * qca_switch_port_is_bridge_member : check if a port is in a bridge
 * port: port
 * br: bridge
 * return value: true: is a bridge member, false: not a bridge member
 */
static bool qca_switch_port_is_bridge_member(struct switch_port *port, struct switch_port *br)
{
	return false;
}

/*
 * qca_switch_port_flush_fdb : flush all FDB learnt on this port
 * port: switch port
 * return value: true: successful, false: failed
 */
static bool qca_switch_port_flush_fdb(struct switch_port *port)
{
	if (!port) {
		return false;
	}

	return qca_switch_ioctl(SW_API_FDB_DELPORT, port->sw_sys->switch_obj, port->port_num, 0);
}

/*
 * qca_switch_port_stp_enable : enable STP on port, this means STP protocol starts to run on this port
 * port: switch port
 * return value: true: successful, false: failed
 */
static bool qca_switch_port_stp_enable(struct switch_port *port)
{
	struct general_device_switch_system *sw_sys;
	struct qca_switch_system *qca_sw;
	bool ret;

	if (!port) {
		return false;
	}

	sw_sys = port->sw_sys;
	if (!sw_sys) {
		return false;
	}

	qca_sw = container_of(sw_sys, struct qca_switch_system, base);

	ret = qca_switch_enable_private_header(qca_sw, true);
	if (!ret) {
		return false;
	}

	ret = qca_switch_enable_private_header_on_cpu_port(qca_sw, true);
	if (!ret) {
		goto err_exit1;
	}

	ret = qca_switch_enable_private_header_on_mirror_port(qca_sw, true);
	if (!ret) {
		goto err_exit2;
	}

	ret = qca_switch_enable_reserved_fdb(qca_sw, QCA_SW_RESV_FDB_STP, true);
	if (!ret) {
		goto err_exit3;
	}

	ret = qca_switch_enable_raw_socket(qca_sw, true);
	if (!ret) {
		goto err_exit4;
	}

	return true;

err_exit4:
	qca_switch_enable_reserved_fdb(qca_sw, QCA_SW_RESV_FDB_STP, false);
err_exit3:
	qca_switch_enable_private_header_on_mirror_port(qca_sw, false);
err_exit2:
	qca_switch_enable_private_header_on_cpu_port(qca_sw, false);
err_exit1:
	qca_switch_enable_private_header(qca_sw, false);

	return false;
}

/*
 * qca_switch_port_stp_disable : disable STP on port, this means STP protocol stops to run on this port
 * port: switch port
 * return value: true: successful, false: failed
 */
static bool qca_switch_port_stp_disable(struct switch_port *port)
{
	struct general_device_switch_system *sw_sys;
	struct qca_switch_system *qca_sw;
	bool ret;

	if (!port) {
		return false;
	}

	sw_sys = port->sw_sys;
	if (!sw_sys) {
		return false;
	}

	qca_sw = container_of(sw_sys, struct qca_switch_system, base);

	ret = qca_switch_enable_private_header(qca_sw, false);
	if (!ret) {
		return false;
	}

	ret = qca_switch_enable_private_header_on_cpu_port(qca_sw, false);
	if (!ret) {
		goto err_exit1;
	}

	ret = qca_switch_enable_private_header_on_mirror_port(qca_sw, false);
	if (!ret) {
		goto err_exit2;
	}

	ret = qca_switch_enable_reserved_fdb(qca_sw, QCA_SW_RESV_FDB_STP, false);
	if (!ret) {
		goto err_exit3;
	}

	ret = qca_switch_enable_raw_socket(qca_sw, false);
	if (!ret) {
		goto err_exit4;
	}

	return true;

err_exit4:
	qca_switch_enable_reserved_fdb(qca_sw, QCA_SW_RESV_FDB_STP, true);
err_exit3:
	qca_switch_enable_private_header_on_mirror_port(qca_sw, true);
err_exit2:
	qca_switch_enable_private_header_on_cpu_port(qca_sw, true);
err_exit1:
	qca_switch_enable_private_header(qca_sw, true);

	return false;
}

/*
 * qca_switch_port_set_stp_state : set STP state of port
 * port: switch port
 * state: state of port
 * return value: true: successful, false: failed
 */
static bool qca_switch_port_set_stp_state(struct switch_port *port, enum general_device_stp_state state)
{
	if (!port) {
		return false;
	}

	return qca_switch_ioctl(SW_API_STP_PT_STATE_SET, port->sw_sys->switch_obj, 0, port->port_num, (uint32_t)state);
}

/*
 * send_bpdu : send BPDU on port
 * port: switch port
 * buf: buffer which contains BPDU
 * buf_len: length of above buffer
 * return value: true: successful, false: failed
 */
static bool qca_switch_port_send_bpdu(struct switch_port *port, const uint8_t *buf, uint32_t buf_len)
{
	struct general_device_switch_system *sw_sys = port->sw_sys;
	struct qca_switch_system *qca_sw = container_of(sw_sys, struct qca_switch_system, base);

	return qca_switch_send_packet(qca_sw, port, buf, buf_len);
}

/*
 * enable : enable LACP on port, this means LACP protocol starts to run on this port
 * port: switch port
 * return value: true: successful, false: failed
 */
static bool qca_switch_port_enable_lacp(struct switch_port *port)
{
	struct general_device_switch_system *sw_sys;
	struct qca_switch_system *qca_sw;
	bool ret;

	if (!port) {
		return false;
	}

	sw_sys = port->sw_sys;
	if (!sw_sys) {
		return false;
	}

	qca_sw = container_of(sw_sys, struct qca_switch_system, base);

	ret = qca_switch_enable_private_header(qca_sw, true);
	if (!ret) {
		return false;
	}

	ret = qca_switch_enable_private_header_on_cpu_port(qca_sw, true);
	if (!ret) {
		goto err_exit1;
	}

	ret = qca_switch_enable_private_header_on_mirror_port(qca_sw, true);
	if (!ret) {
		goto err_exit2;
	}

	ret = qca_switch_enable_reserved_fdb(qca_sw, QCA_SW_RESV_FDB_LACP, true);
	if (!ret) {
		goto err_exit3;
	}

	ret = qca_switch_enable_raw_socket(qca_sw, true);
	if (!ret) {
		goto err_exit4;
	}

	return true;

err_exit4:
	qca_switch_enable_reserved_fdb(qca_sw, QCA_SW_RESV_FDB_LACP, false);
err_exit3:
	qca_switch_enable_private_header_on_mirror_port(qca_sw, false);
err_exit2:
	qca_switch_enable_private_header_on_cpu_port(qca_sw, false);
err_exit1:
	qca_switch_enable_private_header(qca_sw, false);

	return false;
}

/*
 * disable : disable LACP on port, this means LACP protocol stops to run on this port
 * port: switch port
 * return value: true: successful, false: failed
 */
static bool qca_switch_port_disable_lacp(struct switch_port *port)
{
	struct general_device_switch_system *sw_sys;
	struct qca_switch_system *qca_sw;
	bool ret;

	if (!port) {
		return false;
	}

	sw_sys = port->sw_sys;
	if (!sw_sys) {
		return false;
	}

	qca_sw = container_of(sw_sys, struct qca_switch_system, base);

	ret = qca_switch_enable_private_header(qca_sw, false);
	if (!ret) {
		return false;
	}

	ret = qca_switch_enable_private_header_on_cpu_port(qca_sw, false);
	if (!ret) {
		goto err_exit1;
	}

	ret = qca_switch_enable_private_header_on_mirror_port(qca_sw, false);
	if (!ret) {
		goto err_exit2;
	}

	ret = qca_switch_enable_reserved_fdb(qca_sw, QCA_SW_RESV_FDB_LACP, false);
	if (!ret) {
		goto err_exit3;
	}

	ret = qca_switch_enable_raw_socket(qca_sw, false);
	if (!ret) {
		goto err_exit4;
	}

	return true;

err_exit4:
	qca_switch_enable_reserved_fdb(qca_sw, QCA_SW_RESV_FDB_LACP, true);
err_exit3:
	qca_switch_enable_private_header_on_mirror_port(qca_sw, true);
err_exit2:
	qca_switch_enable_private_header_on_cpu_port(qca_sw, true);
err_exit1:
	qca_switch_enable_private_header(qca_sw, true);

	return false;
}

/*
 * new_aggregator : create physical network device for aggregator
 * port: aggregator to create
 * return value: successful or fail
 */
static bool qca_switch_new_aggregator(struct switch_port *port)
{
	struct general_device_switch_system *sw_sys = port->sw_sys;
	struct qca_switch_system *qca_sw = container_of(sw_sys, struct qca_switch_system, base);
	uint32_t agg_id;

	agg_id = qca_switch_allocate_agg_id(qca_sw);
	if (!qca_sw_agg_id_is_valid(qca_sw, agg_id)) {
		return false;
	}

	port->switch_port_obj = qca_sw->agg_domain + agg_id;
	return true;
}

/*
 * destroy_aggregator : destroy physical network device of aggregator
 * port: switch port for aggregator
 * return value: successful or fail
 */
static bool qca_switch_destroy_aggregator(struct switch_port *port)
{
	struct general_device_switch_system *sw_sys = port->sw_sys;
	struct qca_switch_system *qca_sw = container_of(sw_sys, struct qca_switch_system, base);
	uint32_t agg_id, agg_ports_bitmap;

	agg_id = port->switch_port_obj - qca_sw->agg_domain;
	if (!qca_sw_agg_id_is_active(qca_sw, agg_id)) {
		return false;
	}

	agg_ports_bitmap = port->port_num;
	if (!qca_switch_ioctl(SW_API_TRUNK_GROUP_SET, sw_sys->switch_obj, agg_id, 0, agg_ports_bitmap)) {
		return false;
	}

	qca_switch_free_agg_id(qca_sw, agg_id);
	return true;
}

/*
 * is_aggregator : check if switch port is the master of another switch port
 * master: switch port for aggregator
 * slave: switch port in aggregator, could be NULL
 * return value: successful or fail
 */
static bool qca_switch_port_is_aggregator(struct switch_port *master, struct switch_port *slave)
{
	struct general_device_switch_system *sw_sys = master->sw_sys;
	struct qca_switch_system *qca_sw = container_of(sw_sys, struct qca_switch_system, base);
	uint32_t agg_id;

	agg_id = master->switch_port_obj - qca_sw->agg_domain;
	return qca_sw_agg_id_is_active(qca_sw, agg_id);
}

/*
 * attach_slave : attach a slave network device to a master network device
 * master: switch port for aggregator
 * slave: switch port for port in aggregator
 * return value: successful or fail
 */
static bool qca_switch_port_attach_slave(struct switch_port *master, struct switch_port *slave)
{
	struct general_device_switch_system *sw_sys = master->sw_sys;
	struct qca_switch_system *qca_sw = container_of(sw_sys, struct qca_switch_system, base);
	uint32_t agg_id, agg_ports_bitmap;

	agg_id = master->switch_port_obj - qca_sw->agg_domain;
	if (!qca_sw_agg_id_is_active(qca_sw, agg_id)) {
		return false;
	}

	agg_ports_bitmap = master->port_num | (1 << slave->port_num);
	return qca_switch_ioctl(SW_API_TRUNK_GROUP_SET, sw_sys->switch_obj, agg_id, 1, agg_ports_bitmap);
}

/*
 * detach_slave : detach a slave network device from a master network device
 * master: switch port for aggregator
 * slave: switch port for port in aggregator
 * return value: successful or fail
 */
static bool qca_switch_port_detach_slave(struct switch_port *master, struct switch_port *slave)
{
	struct general_device_switch_system *sw_sys = master->sw_sys;
	struct qca_switch_system *qca_sw = container_of(sw_sys, struct qca_switch_system, base);
	uint32_t agg_id, agg_ports_bitmap;

	agg_id = master->switch_port_obj - qca_sw->agg_domain;
	if (!qca_sw_agg_id_is_active(qca_sw, agg_id)) {
		return false;
	}

	agg_ports_bitmap = master->port_num & (~(1 << slave->port_num));
	return qca_switch_ioctl(SW_API_TRUNK_GROUP_SET, sw_sys->switch_obj, agg_id, 1, agg_ports_bitmap);
}

/*
 * send_bpdu : send LACPDU on port
 * port: switch port
 * buf: buffer which contains LACPDU
 * buf_len: length of above buffer
 * return value: true: successful, false: failed
 */
static bool qca_switch_port_send_lacpdu(struct switch_port *port, const uint8_t *buf, uint32_t buf_len)
{
	struct general_device_switch_system *sw_sys = port->sw_sys;
	struct qca_switch_system *qca_sw = container_of(sw_sys, struct qca_switch_system, base);

	return qca_switch_send_packet(qca_sw, port, buf, buf_len);
}

/*
 * qca_switch_port_set_tx_hash_policy : set hash policy to select output port when transmit packet in aggregator
 * aggregator: network device for aggregator
 * policy: tx hash policy
 * return value: true: successful, false: failed
 */
static bool qca_switch_port_set_tx_hash_policy(struct switch_port *aggregator, enum general_device_agg_tx_hash_policy policy)
{
	struct general_device_switch_system *sw_sys = aggregator->sw_sys;
	struct qca_switch_system *qca_sw = container_of(sw_sys, struct qca_switch_system, base);
	uint32_t policy_bitmap = 0;

	switch (policy) {
	case GENL_DEV_AGG_TX_HASH_POLICY_L2:
		policy_bitmap = QCA_SW_TX_HASH_DA_EN | QCA_SW_TX_HASH_SA_EN;
		break;
	case GENL_DEV_AGG_TX_HASH_POLICY_L3:
		policy_bitmap = QCA_SW_TX_HASH_DIP_EN | QCA_SW_TX_HASH_SIP_EN;
		break;
	case GENL_DEV_AGG_TX_HASH_POLICY_L2_L3:
		policy_bitmap = QCA_SW_TX_HASH_DA_EN | QCA_SW_TX_HASH_SA_EN | QCA_SW_TX_HASH_DIP_EN | QCA_SW_TX_HASH_SIP_EN;
		break;
	default:
		DP(GENL_DEVICE, WARNING, "Tx hash policy %d is not supported", policy);
		return false;
	}

	return qca_switch_ioctl(SW_API_TRUNK_HASH_SET, qca_sw->base.switch_obj, policy_bitmap);
}

/*
 * qca_switch_get_agg_id_of_port: get aggregator id of port
 * qca_sw: switch system
 * port_num: mapped hardware port number
 * return value: index of aggregator of port if successful, or 0 if failed
 */
static uint32_t qca_switch_get_agg_id_of_port(struct qca_switch_system *qca_sw, uint32_t port_num)
{
	struct switch_port *port = genl_dev_sw_port_lookup(&qca_sw->base, (qca_sw->port_domain + port_num));

	if (!port || !port->agg_parent) {
		return 0xffff;
	}

	return (port->agg_parent->switch_port_obj - qca_sw->agg_domain);
}

/*
 * qca_switch_get_ports_of_agg: get bitmap of slave ports in aggregator
 * qca_sw: switch system
 * agg_id: index of hardware aggregator
 * return value: bitmap of slave ports
 */
static uint32_t qca_switch_get_ports_of_agg(struct qca_switch_system *qca_sw, uint32_t agg_id)
{
	struct switch_port *agg = genl_dev_sw_port_lookup(&qca_sw->base, (qca_sw->agg_domain + agg_id));

	return (agg ? agg->port_num : 0);
}

/*
 * qca_switch_get_port_hw_id: get hardware mapped port id
 * qca_sw: switch system
 * netdev_obj: index of network device
 * return value: hardware mapped port id
 */
static uint32_t qca_switch_get_port_hw_id(struct qca_switch_system *qca_sw, uint32_t netdev_obj)
{
	struct switch_port *port = genl_dev_sw_port_lookup(&qca_sw->base, netdev_obj);

	if (!port) {
		return 0xffff;
	}

	return port->switch_port_obj - (switch_port_is_aggregator(port) ? qca_sw->agg_domain : qca_sw->port_domain);
}

/*
 * hardware specific initiation when switch port system start
 */
static bool qca_switch_init(struct general_device_switch_system *sw_sys)
{
	struct qca_switch_system *qca_sw = container_of(sw_sys, struct qca_switch_system, base);

	qca_sw->port_domain = genl_dev_sw_alloc_netdev_obj_domain(sw_sys, QCA_SW_PORT_NUM);
	qca_sw->agg_domain = genl_dev_sw_alloc_netdev_obj_domain(sw_sys, QCA_SW_AGG_NUM);

	qca_sw->cpu_port = qca_switch_shell_cmd_get_int(sw_sys->name, "get_cpu_port");
	qca_sw->mirror_port = qca_switch_shell_cmd_get_int(sw_sys->name, "get_mirror_port");
	qca_sw->private_hdr_type = qca_switch_shell_cmd_get_int(sw_sys->name, "get_private_header_type");

	return qca_switch_load_runtime_ports(qca_sw) || qca_switch_load_ports(qca_sw);
}

/*
 * hardware specific finalization when switch port system stop
 */
static bool qca_switch_exit(struct general_device_switch_system *sw_sys)
{
	/*To do: create switch port*/
	return true;
}

/*
 * hardware specific internal operation
 */
static bool qca_switch_private(struct general_device_switch_system *sw_sys, uint32_t func_id, void *input_arg, void *output_arg)
{
	struct qca_switch_system *qca_sw = container_of(sw_sys, struct qca_switch_system, base);
	uint32_t ret_value;
	bool ret = true;

	if ((func_id >> 16) != QCA_SWITCH_LAYER_DEPTH) {
		/*
		 * We don't understand this private operation
		 */
		return false;
	}

	if ((func_id & 0xff) >= QCA_SW_PRIVATE_FUNC_MAX) {
		/*
		 * We don't understand this private operation
		 */
		return false;
	}

	switch (func_id & 0xff) {
	case QCA_SW_PRIVATE_FUNC_get_agg_id_of_port:
		*((uint32_t *)output_arg) = ret_value = qca_switch_get_agg_id_of_port(qca_sw, (uint32_t)input_arg);
		ret = (0xffff != ret_value);
	break;
	case QCA_SW_PRIVATE_FUNC_get_ports_of_agg:
		*((uint32_t *)output_arg) = qca_switch_get_ports_of_agg(qca_sw, (uint32_t)input_arg);
	break;
	case QCA_SW_PRIVATE_FUNC_get_port_hw_id:
		*((uint32_t *)output_arg) = ret_value = qca_switch_get_port_hw_id(qca_sw, (uint32_t)input_arg);
		ret = (0xffff != ret_value);
	break;
	default:
		return false;
	}

	return ret;
}

void qca_switch_probe(void)
{
	char sw_names[QCA_SW_NUM_MAX][QCA_SW_SHELL_CMD_WORD_SIZE];
	int num_of_switch = qca_switch_shell_cmd_get_word_list(NULL, "get_switch_list", sw_names, QCA_SW_NUM_MAX);
	struct qca_switch_system *qca_sw;
	struct general_device_switch_system *sw_sys;
	int idx;

	for (idx = 0; idx < num_of_switch; idx++) {
		qca_sw = (struct qca_switch_system *)calloc(1, sizeof(struct qca_switch_system));
		if (!qca_sw) {
			DP(GENL_DEVICE, CRIT, "Allocate memory for QCA switch %d failed", idx);
			return;
		}

		sw_sys = &qca_sw->base;
		snprintf(sw_sys->name, sizeof(sw_sys->name), "%s", sw_names[idx]);
		sw_sys->switch_obj = idx;
		sw_sys->real_agg_dev = false;
		sw_sys->support_link_event = false;
		sw_sys->link_status_poll_interval = qca_switch_shell_cmd_get_int(sw_sys->name, "get_linkstatus_poll_interval");

		sw_sys->ops.common.get_link_status = qca_switch_port_get_link_status;
		sw_sys->ops.common.get_duplex = qca_switch_port_get_duplex;
		sw_sys->ops.common.get_speed = qca_switch_port_get_speed;
		sw_sys->ops.bridge.is_bridge_member = qca_switch_port_is_bridge_member;
		sw_sys->ops.bridge.flush_fdb = qca_switch_port_flush_fdb;
		sw_sys->ops.stp.enable = qca_switch_port_stp_enable;
		sw_sys->ops.stp.disable = qca_switch_port_stp_disable;
		sw_sys->ops.stp.set_port_state = qca_switch_port_set_stp_state;
		sw_sys->ops.stp.send_bpdu = qca_switch_port_send_bpdu;
		sw_sys->ops.agg.enable = qca_switch_port_enable_lacp;
		sw_sys->ops.agg.disable = qca_switch_port_disable_lacp;
		sw_sys->ops.agg.new_aggregator = qca_switch_new_aggregator;
		sw_sys->ops.agg.destroy_aggregator = qca_switch_destroy_aggregator;
		sw_sys->ops.agg.is_aggregator = qca_switch_port_is_aggregator;
		sw_sys->ops.agg.attach_slave = qca_switch_port_attach_slave;
		sw_sys->ops.agg.detach_slave = qca_switch_port_detach_slave;
		sw_sys->ops.agg.send_lacpdu = qca_switch_port_send_lacpdu;
		sw_sys->ops.agg.set_tx_hash_policy = qca_switch_port_set_tx_hash_policy;
		sw_sys->ops.init = qca_switch_init;
		sw_sys->ops.exit = qca_switch_exit;
		sw_sys->ops.private = qca_switch_private;

		sw_sys->base.domain = QCA_SW_DOMAIN_INIT + idx;
		sw_sys->base.next_internal_domain = QCA_SW_INTERNAL_DOMAIN_INIT;

		if (!genl_dev_register_switch_system(sw_sys)) {
			DP(GENL_DEVICE, CRIT, "Register QCA switch %d failed", idx);
			free(qca_sw);
			return;
		}
	}
}
