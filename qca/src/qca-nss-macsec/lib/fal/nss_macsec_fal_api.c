/*
 * Copyright (c) 2014, The Linux Foundation. All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <poll.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <linux/if_ether.h>
#include <unistd.h>
#include <net/if.h>
#include <netinet/in.h>

#include "nss_macsec_sdk_api.h"
#include "nss_macsec_emac.h"
#include "nss_macsec_interrupt.h"
#include "nss_macsec.h"
#include "nss_macsec_mib.h"
#include "nss_macsec_secy.h"
#include "nss_macsec_secy_rx.h"
#include "nss_macsec_secy_tx.h"
#include "nss_macsec_fal_api.h"

#define SDK_MSG_HDRLEN       sizeof (struct sdk_msg_header)
#define SDK_MSG_SIZE( x )		( NLMSG_LENGTH(0) + SDK_MSG_HDRLEN + (x) )
#define SDK_MSG_HEADER(p)      ((void*)(((char*)p) + NLMSG_LENGTH(0)))
#define SDK_MSG_DATA(p)      ((void*)(((char*)p) + NLMSG_LENGTH(0) + SDK_MSG_HDRLEN))

#define DEBUG_SDK_NETLINK

int nss_macsec_sdk_netlink_msg(int msg_type, unsigned char *data, int data_len,
			       int netlink_key)
{
	struct sockaddr_nl src_addr, dest_addr;
	struct nlmsghdr *nlh = NULL;
	socklen_t fromlen;
	int ret = SDK_RET_UNKOWN_ERR;
	int sock_fd;
	struct sdk_msg_header *msg_header;
	static pid_t myPid = 0;

	/* Do it only once per context, save a system call */
	if (!myPid)
		myPid = getpid();

	do {
		sock_fd = socket(AF_NETLINK, SOCK_RAW, netlink_key);
		if (sock_fd <= 0) {
#ifdef DEBUG_SDK_NETLINK
			printf("netlink socket create failed\n");
#endif
			break;
		}

		/* Set nonblock. */
		if (fcntl
		    (sock_fd, F_SETFL, fcntl(sock_fd, F_GETFL) | O_NONBLOCK)) {
#ifdef DEBUG_SDK_NETLINK
			perror("fcntl():");
#endif
			break;
		}

		fromlen = sizeof(src_addr);
		memset(&src_addr, 0, sizeof(src_addr));
		src_addr.nl_family = AF_NETLINK;
		src_addr.nl_pid = myPid;	/* self pid */
		src_addr.nl_groups = 0;	/* not in mcast groups */

		bind(sock_fd, (struct sockaddr *)&src_addr, sizeof(src_addr));
		memset(&dest_addr, 0, sizeof(dest_addr));
		dest_addr.nl_family = AF_NETLINK;
		dest_addr.nl_pid = 0;	/* For Linux Kernel */
		dest_addr.nl_groups = 0;	/* unicast */
		nlh = (struct nlmsghdr *)data;
		/* Fill the netlink message header */
		nlh->nlmsg_type = msg_type;
		nlh->nlmsg_len = NLMSG_SPACE(SDK_MSG_HDRLEN + data_len);
		nlh->nlmsg_pid = myPid;	/* self pid */
		nlh->nlmsg_flags = 0;

		if (sendto(sock_fd,
			   (void *)nlh,
			   nlh->nlmsg_len,
			   0,
			   (struct sockaddr *)&dest_addr,
			   sizeof(struct sockaddr_nl)) <= 0) {
#ifdef DEBUG_SDK_NETLINK
			printf("netlink socket send failed\n");
#endif
			break;
		}

		struct pollfd pollfd = {
			sock_fd,
			POLLIN,
			0
		};

		if (poll(&pollfd, 1, 3000) <= 0) {	/* timeout:3s */
#ifdef DEBUG_SDK_NETLINK
			perror("poll():");
#endif
			break;
		}

		if (recvfrom(sock_fd,
			     (void *)nlh,
			     NLMSG_SPACE(SDK_MSG_HDRLEN + data_len),
			     MSG_WAITALL,
			     (struct sockaddr *)&src_addr, &fromlen) <= 0) {
#ifdef DEBUG_SDK_NETLINK
			printf("netlink socket receive failed\n");
#endif
			break;
		}
		msg_header = (struct sdk_msg_header *)NLMSG_DATA(nlh);

		ret = msg_header->ret;

#ifdef DEBUG_SDK_NETLINK
		if (ret != SDK_RET_SUCCESS)
			printf("netlink socket status failed %d\n", ret);
#endif

	} while (0);

	if (sock_fd > 0)
		close(sock_fd);

	return ret;
}

u32 nss_macsec_secy_interrupt_en_get(u32 secy_id, fal_interrupt_en_t *p_int_en)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_interrupt_en_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_interrupt_en_get_cmd *param =
	    (struct nss_macsec_secy_interrupt_en_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_INTERRUPT_EN_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_interrupt_en_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_interrupt_en_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*p_int_en = param->p_int_en;
	}
	return ret;
}

u32 nss_macsec_secy_interrupt_en_set(u32 secy_id, fal_interrupt_en_t *p_int_en)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_interrupt_en_set_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_interrupt_en_set_cmd *param =
	    (struct nss_macsec_secy_interrupt_en_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_INTERRUPT_EN_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_interrupt_en_set_cmd);
	param->secy_id = secy_id;
	param->p_int_en = *p_int_en;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_interrupt_en_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_interrupt_get(u32 secy_id, fal_interrupt_t *pint)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_interrupt_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_interrupt_get_cmd *param =
	    (struct nss_macsec_secy_interrupt_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_INTERRUPT_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_interrupt_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_interrupt_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pint = param->pint;
	}
	return ret;
}

u32 nss_macsec_emac_init(u32 secy_id)
{
	unsigned char buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_emac_init_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_emac_init_cmd *param =
	    (struct nss_macsec_emac_init_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_EMAC_INIT_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_emac_init_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct nss_macsec_emac_init_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_speed(u32 secy_id, enum emac_link_speed speed)
{
	unsigned char buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_speed_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_speed_cmd *param =
	    (struct nss_macsec_speed_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SPEED_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_speed_cmd);
	param->secy_id = secy_id;
	param->speed = speed;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct nss_macsec_speed_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_emac_enable(u32 secy_id, BOOL enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_emac_enable_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_emac_enable_cmd *param =
	    (struct nss_macsec_emac_enable_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_EMAC_ENABLE_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_emac_enable_cmd);
	param->secy_id = secy_id;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_emac_enable_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_emac_reset(u32 secy_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_emac_reset_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_emac_reset_cmd *param =
	    (struct nss_macsec_emac_reset_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_EMAC_RESET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_emac_reset_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct nss_macsec_emac_reset_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sc_mib_get(u32 secy_id, u32 channel,
				  fal_tx_sc_mib_t *pmib)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sc_mib_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_mib_get_cmd *param =
	    (struct nss_macsec_secy_tx_sc_mib_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_MIB_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sc_mib_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_mib_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pmib = param->pmib;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sa_mib_get(u32 secy_id, u32 channel, u32 an,
				  fal_tx_sa_mib_t *pmib)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sa_mib_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sa_mib_get_cmd *param =
	    (struct nss_macsec_secy_tx_sa_mib_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SA_MIB_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sa_mib_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sa_mib_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pmib = param->pmib;
	}
	return ret;
}

u32 nss_macsec_secy_tx_mib_get(u32 secy_id, fal_tx_mib_t *pmib)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_mib_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_mib_get_cmd *param =
	    (struct nss_macsec_secy_tx_mib_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_MIB_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_mib_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_mib_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pmib = param->pmib;
	}
	return ret;
}

u32 nss_macsec_secy_rx_sa_mib_get(u32 secy_id, u32 channel, u32 an,
				  fal_rx_sa_mib_t *pmib)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_sa_mib_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sa_mib_get_cmd *param =
	    (struct nss_macsec_secy_rx_sa_mib_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SA_MIB_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_sa_mib_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sa_mib_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pmib = param->pmib;
	}
	return ret;
}

u32 nss_macsec_secy_rx_mib_get(u32 secy_id, fal_rx_mib_t *pmib)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_mib_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_mib_get_cmd *param =
	    (struct nss_macsec_secy_rx_mib_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_MIB_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_mib_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_mib_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pmib = param->pmib;
	}
	return ret;
}

u32 nss_macsec_secy_tx_mib_clear(u32 secy_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_mib_clear_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_mib_clear_cmd *param =
	    (struct nss_macsec_secy_tx_mib_clear_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_MIB_CLEAR_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_mib_clear_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_mib_clear_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sc_mib_clear(u32 secy_id, u32 channel)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sc_mib_clear_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_mib_clear_cmd *param =
	    (struct nss_macsec_secy_tx_sc_mib_clear_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_MIB_CLEAR_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sc_mib_clear_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_mib_clear_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sa_mib_clear(u32 secy_id, u32 channel, u32 an)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sa_mib_clear_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sa_mib_clear_cmd *param =
	    (struct nss_macsec_secy_tx_sa_mib_clear_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SA_MIB_CLEAR_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sa_mib_clear_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sa_mib_clear_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_mib_clear(u32 secy_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_mib_clear_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_mib_clear_cmd *param =
	    (struct nss_macsec_secy_rx_mib_clear_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_MIB_CLEAR_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_mib_clear_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_mib_clear_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sa_mib_clear(u32 secy_id, u32 channel, u32 an)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sa_mib_clear_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sa_mib_clear_cmd *param =
	    (struct nss_macsec_secy_rx_sa_mib_clear_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SA_MIB_CLEAR_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sa_mib_clear_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sa_mib_clear_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_reg_get(u32 secy_id, u32 addr, u32 *pvalue)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_reg_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_reg_get_cmd *param =
	    (struct nss_macsec_secy_rx_reg_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_REG_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_reg_get_cmd);
	param->secy_id = secy_id;
	param->addr = addr;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_reg_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pvalue = param->pvalue;
	}
	return ret;
}

u32 nss_macsec_secy_rx_reg_set(u32 secy_id, u32 addr, u32 value)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_reg_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_reg_set_cmd *param =
	    (struct nss_macsec_secy_rx_reg_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_REG_SET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_reg_set_cmd);
	param->secy_id = secy_id;
	param->addr = addr;
	param->value = value;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_reg_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_ctl_filt_get(u32 secy_id, u32 filt_id,
				    fal_rx_ctl_filt_t *pfilt)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_ctl_filt_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_ctl_filt_get_cmd *param =
	    (struct nss_macsec_secy_rx_ctl_filt_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_CTL_FILT_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_ctl_filt_get_cmd);
	param->secy_id = secy_id;
	param->filt_id = filt_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_ctl_filt_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pfilt = param->pfilt;
	}
	return ret;
}

u32 nss_macsec_secy_rx_ctl_filt_set(u32 secy_id, u32 filt_id,
				    fal_rx_ctl_filt_t *pfilt)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_ctl_filt_set_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_ctl_filt_set_cmd *param =
	    (struct nss_macsec_secy_rx_ctl_filt_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_CTL_FILT_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_ctl_filt_set_cmd);
	param->secy_id = secy_id;
	param->filt_id = filt_id;
	param->pfilt = *pfilt;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_ctl_filt_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_ctl_filt_clear(u32 secy_id, u32 filt_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_ctl_filt_clear_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_ctl_filt_clear_cmd *param =
	    (struct nss_macsec_secy_rx_ctl_filt_clear_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_CTL_FILT_CLEAR_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_ctl_filt_clear_cmd);
	param->secy_id = secy_id;
	param->filt_id = filt_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_ctl_filt_clear_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_ctl_filt_clear_all(u32 secy_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_ctl_filt_clear_all_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_ctl_filt_clear_all_cmd *param =
	    (struct nss_macsec_secy_rx_ctl_filt_clear_all_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_CTL_FILT_CLEAR_ALL_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_ctl_filt_clear_all_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_ctl_filt_clear_all_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_prc_lut_get(u32 secy_id, u32 index,
				   fal_rx_prc_lut_t *pentry)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_prc_lut_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_prc_lut_get_cmd *param =
	    (struct nss_macsec_secy_rx_prc_lut_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_PRC_LUT_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_prc_lut_get_cmd);
	param->secy_id = secy_id;
	param->index = index;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_prc_lut_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pentry = param->pentry;
	}
	return ret;
}

u32 nss_macsec_secy_rx_prc_lut_set(u32 secy_id, u32 index,
				   fal_rx_prc_lut_t *pentry)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_prc_lut_set_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_prc_lut_set_cmd *param =
	    (struct nss_macsec_secy_rx_prc_lut_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_PRC_LUT_SET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_prc_lut_set_cmd);
	param->secy_id = secy_id;
	param->index = index;
	param->pentry = *pentry;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_prc_lut_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_prc_lut_clear(u32 secy_id, u32 index)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_prc_lut_clear_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_prc_lut_clear_cmd *param =
	    (struct nss_macsec_secy_rx_prc_lut_clear_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_PRC_LUT_CLEAR_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_prc_lut_clear_cmd);
	param->secy_id = secy_id;
	param->index = index;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_prc_lut_clear_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_prc_lut_clear_all(u32 secy_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_prc_lut_clear_all_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_prc_lut_clear_all_cmd *param =
	    (struct nss_macsec_secy_rx_prc_lut_clear_all_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_PRC_LUT_CLEAR_ALL_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_prc_lut_clear_all_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_prc_lut_clear_all_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sc_create(u32 secy_id, u32 channel)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_sc_create_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_create_cmd *param =
	    (struct nss_macsec_secy_rx_sc_create_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_CREATE_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_sc_create_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_create_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sc_en_get(u32 secy_id, u32 channel, bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_sc_en_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_en_get_cmd *param =
	    (struct nss_macsec_secy_rx_sc_en_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_EN_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_sc_en_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_en_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_rx_sc_en_set(u32 secy_id, u32 channel, bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_sc_en_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_en_set_cmd *param =
	    (struct nss_macsec_secy_rx_sc_en_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_EN_SET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_sc_en_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_en_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sc_del(u32 secy_id, u32 channel)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_sc_del_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_del_cmd *param =
	    (struct nss_macsec_secy_rx_sc_del_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_DEL_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_sc_del_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_del_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sc_del_all(u32 secy_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_sc_del_all_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_del_all_cmd *param =
	    (struct nss_macsec_secy_rx_sc_del_all_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_DEL_ALL_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_sc_del_all_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_del_all_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sc_validate_frame_get(u32 secy_id, u32 channel,
					     fal_rx_sc_validate_frame_e *pmode)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sc_validate_frame_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_validate_frame_get_cmd *param =
	    (struct nss_macsec_secy_rx_sc_validate_frame_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_VALIDATE_FRAME_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sc_validate_frame_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_validate_frame_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pmode = param->pmode;
	}
	return ret;
}

u32 nss_macsec_secy_rx_sc_validate_frame_set(u32 secy_id, u32 channel,
					     fal_rx_sc_validate_frame_e mode)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sc_validate_frame_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_validate_frame_set_cmd *param =
	    (struct nss_macsec_secy_rx_sc_validate_frame_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_VALIDATE_FRAME_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sc_validate_frame_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->mode = mode;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_validate_frame_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sc_replay_protect_get(u32 secy_id, u32 channel,
					     bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sc_replay_protect_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_replay_protect_get_cmd *param =
	    (struct nss_macsec_secy_rx_sc_replay_protect_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_REPLAY_PROTECT_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sc_replay_protect_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_replay_protect_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_rx_sc_replay_protect_set(u32 secy_id, u32 channel,
					     bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sc_replay_protect_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_replay_protect_set_cmd *param =
	    (struct nss_macsec_secy_rx_sc_replay_protect_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_REPLAY_PROTECT_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sc_replay_protect_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_replay_protect_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sc_anti_replay_window_get(u32 secy_id, u32 channel,
						 u32 *pwindow)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof
		 (struct nss_macsec_secy_rx_sc_anti_replay_window_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_anti_replay_window_get_cmd *param =
	    (struct nss_macsec_secy_rx_sc_anti_replay_window_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_ANTI_REPLAY_WINDOW_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sc_anti_replay_window_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_anti_replay_window_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pwindow = param->pwindow;
	}
	return ret;
}

u32 nss_macsec_secy_rx_sc_anti_replay_window_set(u32 secy_id, u32 channel,
						 u32 window)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof
		 (struct nss_macsec_secy_rx_sc_anti_replay_window_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_anti_replay_window_set_cmd *param =
	    (struct nss_macsec_secy_rx_sc_anti_replay_window_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_ANTI_REPLAY_WINDOW_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sc_anti_replay_window_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->window = window;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_anti_replay_window_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sc_in_used_get(u32 secy_id, u32 channel,
				      bool *p_in_used)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sc_in_used_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_in_used_get_cmd *param =
	    (struct nss_macsec_secy_rx_sc_in_used_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_IN_USED_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sc_in_used_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_in_used_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*p_in_used = param->p_in_used;
	}
	return ret;
}

u32 nss_macsec_secy_rx_sc_an_roll_over_get(u32 secy_id, u32 channel,
					   bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sc_an_roll_over_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_an_roll_over_get_cmd *param =
	    (struct nss_macsec_secy_rx_sc_an_roll_over_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_AN_ROLL_OVER_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sc_an_roll_over_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_an_roll_over_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_rx_sc_an_roll_over_set(u32 secy_id, u32 channel,
					   bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sc_an_roll_over_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_an_roll_over_set_cmd *param =
	    (struct nss_macsec_secy_rx_sc_an_roll_over_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_AN_ROLL_OVER_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sc_an_roll_over_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_an_roll_over_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sc_start_stop_time_get(u32 secy_id, u32 channel,
					      u32 *p_start_time,
					      u32 *p_stop_time)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sc_start_stop_time_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_start_stop_time_get_cmd *param =
	    (struct nss_macsec_secy_rx_sc_start_stop_time_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_START_STOP_TIME_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sc_start_stop_time_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_start_stop_time_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*p_start_time = param->p_start_time;
		*p_stop_time = param->p_stop_time;
	}
	return ret;
}

u32 nss_macsec_secy_rx_sc_start_stop_time_set(u32 secy_id, u32 channel,
					      u32 start_time, u32 stop_time)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sc_start_stop_time_set_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sc_start_stop_time_set_cmd *param =
	    (struct nss_macsec_secy_rx_sc_start_stop_time_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SC_START_STOP_TIME_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sc_start_stop_time_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->start_time = start_time;
	param->stop_time = stop_time;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sc_start_stop_time_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sa_create(u32 secy_id, u32 channel, u32 an)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_sa_create_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sa_create_cmd *param =
	    (struct nss_macsec_secy_rx_sa_create_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SA_CREATE_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_sa_create_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sa_create_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sa_en_get(u32 secy_id, u32 channel, u32 an,
				 bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_sa_en_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sa_en_get_cmd *param =
	    (struct nss_macsec_secy_rx_sa_en_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SA_EN_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_sa_en_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sa_en_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_rx_sa_en_set(u32 secy_id, u32 channel, u32 an, bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_sa_en_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sa_en_set_cmd *param =
	    (struct nss_macsec_secy_rx_sa_en_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SA_EN_SET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_sa_en_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sa_en_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sa_next_pn_get(u32 secy_id, u32 channel, u32 an,
				      u32 *pnpn)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sa_next_pn_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sa_next_pn_get_cmd *param =
	    (struct nss_macsec_secy_rx_sa_next_pn_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SA_NEXT_PN_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sa_next_pn_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sa_next_pn_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pnpn = param->pnpn;
	}
	return ret;
}

u32 nss_macsec_secy_rx_sa_del(u32 secy_id, u32 channel, u32 an)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_sa_del_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sa_del_cmd *param =
	    (struct nss_macsec_secy_rx_sa_del_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SA_DEL_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_sa_del_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sa_del_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sa_del_all(u32 secy_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_sa_del_all_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sa_del_all_cmd *param =
	    (struct nss_macsec_secy_rx_sa_del_all_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SA_DEL_ALL_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_sa_del_all_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sa_del_all_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sak_get(u32 secy_id, u32 channel, u32 an,
			       fal_rx_sak_t *pkey)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_sak_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sak_get_cmd *param =
	    (struct nss_macsec_secy_rx_sak_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SAK_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_sak_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sak_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pkey = param->pkey;
	}
	return ret;
}

u32 nss_macsec_secy_rx_sak_set(u32 secy_id, u32 channel, u32 an,
			       fal_rx_sak_t *pkey)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_rx_sak_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sak_set_cmd *param =
	    (struct nss_macsec_secy_rx_sak_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SAK_SET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_rx_sak_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;
	param->pkey = *pkey;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sak_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_sa_in_used_get(u32 secy_id, u32 channel, u32 an,
				      bool *p_in_used)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sa_in_used_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sa_in_used_get_cmd *param =
	    (struct nss_macsec_secy_rx_sa_in_used_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SA_IN_USED_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sa_in_used_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sa_in_used_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*p_in_used = param->p_in_used;
	}
	return ret;
}

u32 nss_macsec_secy_rx_sa_start_stop_time_get(u32 secy_id, u32 channel, u32 an,
					      u32 *p_start_time,
					      u32 *p_stop_time)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sa_start_stop_time_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sa_start_stop_time_get_cmd *param =
	    (struct nss_macsec_secy_rx_sa_start_stop_time_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SA_START_STOP_TIME_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sa_start_stop_time_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sa_start_stop_time_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*p_start_time = param->p_start_time;
		*p_stop_time = param->p_stop_time;
	}
	return ret;
}

u32 nss_macsec_secy_rx_sa_start_stop_time_set(u32 secy_id, u32 channel, u32 an,
					      u32 start_time, u32 stop_time)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_sa_start_stop_time_set_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_sa_start_stop_time_set_cmd *param =
	    (struct nss_macsec_secy_rx_sa_start_stop_time_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_SA_START_STOP_TIME_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_sa_start_stop_time_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;
	param->start_time = start_time;
	param->stop_time = stop_time;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_sa_start_stop_time_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_pn_threshold_get(u32 secy_id, u32 *p_pn_threshold)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_pn_threshold_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_pn_threshold_get_cmd *param =
	    (struct nss_macsec_secy_rx_pn_threshold_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_PN_THRESHOLD_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_pn_threshold_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_pn_threshold_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*p_pn_threshold = param->p_pn_threshold;
	}
	return ret;
}

u32 nss_macsec_secy_rx_pn_threshold_set(u32 secy_id, u32 pn_threshold)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_pn_threshold_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_pn_threshold_set_cmd *param =
	    (struct nss_macsec_secy_rx_pn_threshold_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_PN_THRESHOLD_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_pn_threshold_set_cmd);
	param->secy_id = secy_id;
	param->pn_threshold = pn_threshold;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_pn_threshold_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_replay_protect_get(u32 secy_id, u32 *enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_replay_protect_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_replay_protect_get_cmd *param =
	    (struct nss_macsec_secy_rx_replay_protect_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_REPLAY_PROTECT_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_replay_protect_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_replay_protect_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*enable = param->enable;
	}
	return ret;
}

u32 nss_macsec_secy_rx_replay_protect_set(u32 secy_id, u32 enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_replay_protect_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_replay_protect_set_cmd *param =
	    (struct nss_macsec_secy_rx_replay_protect_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_REPLAY_PROTECT_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_replay_protect_set_cmd);
	param->secy_id = secy_id;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_replay_protect_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_rx_validate_frame_get(u32 secy_id, u32 *mode)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_validate_frame_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_validate_frame_get_cmd *param =
	    (struct nss_macsec_secy_rx_validate_frame_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_VALIDATE_FRAME_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_validate_frame_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_validate_frame_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*mode = param->mode;
	}
	return ret;
}

u32 nss_macsec_secy_rx_validate_frame_set(u32 secy_id, u32 mode)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_rx_validate_frame_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_rx_validate_frame_set_cmd *param =
	    (struct nss_macsec_secy_rx_validate_frame_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RX_VALIDATE_FRAME_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_rx_validate_frame_set_cmd);
	param->secy_id = secy_id;
	param->mode = mode;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_rx_validate_frame_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_reg_get(u32 secy_id, u32 addr, u32 *pvalue)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_reg_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_reg_get_cmd *param =
	    (struct nss_macsec_secy_tx_reg_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_REG_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_reg_get_cmd);
	param->secy_id = secy_id;
	param->addr = addr;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_reg_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pvalue = param->pvalue;
	}
	return ret;
}

u32 nss_macsec_secy_tx_reg_set(u32 secy_id, u32 addr, u32 value)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_reg_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_reg_set_cmd *param =
	    (struct nss_macsec_secy_tx_reg_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_REG_SET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_reg_set_cmd);
	param->secy_id = secy_id;
	param->addr = addr;
	param->value = value;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_reg_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_drop_sc_sa_invalid_get(u32 secy_id, bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_drop_sc_sa_invlid_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_drop_sc_sa_invlid_get_cmd *param =
	    (struct nss_macsec_secy_tx_drop_sc_sa_invlid_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_DROP_SC_SA_INVLID_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_drop_sc_sa_invlid_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_drop_sc_sa_invlid_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_tx_drop_sc_sa_invalid_set(u32 secy_id, bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_drop_sc_sa_invlid_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_drop_sc_sa_invlid_set_cmd *param =
	    (struct nss_macsec_secy_tx_drop_sc_sa_invlid_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_DROP_SC_SA_INVLID_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_drop_sc_sa_invlid_set_cmd);
	param->secy_id = secy_id;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_drop_sc_sa_invlid_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_unmatched_use_sc_0_get(u32 secy_id, bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_unmatched_use_sc_0_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_unmatched_use_sc_0_get_cmd *param =
	    (struct nss_macsec_secy_tx_unmatched_use_sc_0_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_UNMATCHED_USE_SC_0_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_unmatched_use_sc_0_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_unmatched_use_sc_0_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_tx_unmatched_use_sc_0_set(u32 secy_id, bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_unmatched_use_sc_0_set_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_unmatched_use_sc_0_set_cmd *param =
	    (struct nss_macsec_secy_tx_unmatched_use_sc_0_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_UNMATCHED_USE_SC_0_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_unmatched_use_sc_0_set_cmd);
	param->secy_id = secy_id;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_unmatched_use_sc_0_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_gcm_start_get(u32 secy_id, bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_gcm_start_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_gcm_start_get_cmd *param =
	    (struct nss_macsec_secy_tx_gcm_start_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_GCM_START_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_gcm_start_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_gcm_start_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_tx_gcm_start_set(u32 secy_id, bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_gcm_start_set_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_gcm_start_set_cmd *param =
	    (struct nss_macsec_secy_tx_gcm_start_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_GCM_START_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_gcm_start_set_cmd);
	param->secy_id = secy_id;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_gcm_start_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_drop_class_miss_get(u32 secy_id, bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_drop_class_miss_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_drop_class_miss_get_cmd *param =
	    (struct nss_macsec_secy_tx_drop_class_miss_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_DROP_CLASS_MISS_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_drop_class_miss_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_drop_class_miss_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_tx_drop_class_miss_set(u32 secy_id, bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_drop_class_miss_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_drop_class_miss_set_cmd *param =
	    (struct nss_macsec_secy_tx_drop_class_miss_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_DROP_CLASS_MISS_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_drop_class_miss_set_cmd);
	param->secy_id = secy_id;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_drop_class_miss_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_drop_kay_pkt_get(u32 secy_id, bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_drop_kay_pkt_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_drop_kay_pkt_get_cmd *param =
	    (struct nss_macsec_secy_tx_drop_kay_pkt_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_DROP_KAY_PKT_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_drop_kay_pkt_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_drop_kay_pkt_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_tx_drop_kay_pkt_set(u32 secy_id, bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_drop_kay_pkt_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_drop_kay_pkt_set_cmd *param =
	    (struct nss_macsec_secy_tx_drop_kay_pkt_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_DROP_KAY_PKT_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_drop_kay_pkt_set_cmd);
	param->secy_id = secy_id;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_drop_kay_pkt_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_ctl_filt_get(u32 secy_id, u32 filt_id,
				    fal_tx_ctl_filt_t *pfilt)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_ctl_filt_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_ctl_filt_get_cmd *param =
	    (struct nss_macsec_secy_tx_ctl_filt_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_CTL_FILT_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_ctl_filt_get_cmd);
	param->secy_id = secy_id;
	param->filt_id = filt_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_ctl_filt_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pfilt = param->pfilt;
	}
	return ret;
}

u32 nss_macsec_secy_tx_ctl_filt_set(u32 secy_id, u32 filt_id,
				    fal_tx_ctl_filt_t *pfilt)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_ctl_filt_set_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_ctl_filt_set_cmd *param =
	    (struct nss_macsec_secy_tx_ctl_filt_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_CTL_FILT_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_ctl_filt_set_cmd);
	param->secy_id = secy_id;
	param->filt_id = filt_id;
	param->pfilt = *pfilt;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_ctl_filt_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_ctl_filt_clear(u32 secy_id, u32 filt_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_ctl_filt_clear_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_ctl_filt_clear_cmd *param =
	    (struct nss_macsec_secy_tx_ctl_filt_clear_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_CTL_FILT_CLEAR_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_ctl_filt_clear_cmd);
	param->secy_id = secy_id;
	param->filt_id = filt_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_ctl_filt_clear_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_ctl_filt_clear_all(u32 secy_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_ctl_filt_clear_all_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_ctl_filt_clear_all_cmd *param =
	    (struct nss_macsec_secy_tx_ctl_filt_clear_all_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_CTL_FILT_CLEAR_ALL_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_ctl_filt_clear_all_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_ctl_filt_clear_all_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_class_lut_get(u32 secy_id, u32 index,
				     fal_tx_class_lut_t *pentry)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_class_lut_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_class_lut_get_cmd *param =
	    (struct nss_macsec_secy_tx_class_lut_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_CLASS_LUT_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_class_lut_get_cmd);
	param->secy_id = secy_id;
	param->index = index;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_class_lut_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pentry = param->pentry;
	}
	return ret;
}

u32 nss_macsec_secy_tx_class_lut_set(u32 secy_id, u32 index,
				     fal_tx_class_lut_t *pentry)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_class_lut_set_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_class_lut_set_cmd *param =
	    (struct nss_macsec_secy_tx_class_lut_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_CLASS_LUT_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_class_lut_set_cmd);
	param->secy_id = secy_id;
	param->index = index;
	param->pentry = *pentry;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_class_lut_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_class_lut_clear(u32 secy_id, u32 index)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_class_lut_clear_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_class_lut_clear_cmd *param =
	    (struct nss_macsec_secy_tx_class_lut_clear_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_CLASS_LUT_CLEAR_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_class_lut_clear_cmd);
	param->secy_id = secy_id;
	param->index = index;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_class_lut_clear_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_class_lut_clear_all(u32 secy_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_class_lut_clear_all_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_class_lut_clear_all_cmd *param =
	    (struct nss_macsec_secy_tx_class_lut_clear_all_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_CLASS_LUT_CLEAR_ALL_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_class_lut_clear_all_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_class_lut_clear_all_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sc_create(u32 secy_id, u32 channel, u8 *psci,
				 u32 sci_len)
{				/* [16] */
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sc_create_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_create_cmd *param =
	    (struct nss_macsec_secy_tx_sc_create_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_CREATE_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sc_create_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	memcpy(param->psci, psci, sci_len);
	param->sci_len = sci_len;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_create_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sc_en_get(u32 secy_id, u32 channel, bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sc_en_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_en_get_cmd *param =
	    (struct nss_macsec_secy_tx_sc_en_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_EN_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sc_en_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_en_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sc_en_set(u32 secy_id, u32 channel, bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sc_en_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_en_set_cmd *param =
	    (struct nss_macsec_secy_tx_sc_en_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_EN_SET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sc_en_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_en_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sc_del(u32 secy_id, u32 channel)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sc_del_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_del_cmd *param =
	    (struct nss_macsec_secy_tx_sc_del_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_DEL_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sc_del_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_del_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sc_del_all(u32 secy_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sc_del_all_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_del_all_cmd *param =
	    (struct nss_macsec_secy_tx_sc_del_all_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_DEL_ALL_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sc_del_all_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_del_all_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sc_an_get(u32 secy_id, u32 channel, u32 *pan)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sc_an_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_an_get_cmd *param =
	    (struct nss_macsec_secy_tx_sc_an_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_AN_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sc_an_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_an_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pan = param->pan;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sc_an_set(u32 secy_id, u32 channel, u32 an)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sc_an_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_an_set_cmd *param =
	    (struct nss_macsec_secy_tx_sc_an_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_AN_SET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sc_an_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_an_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sc_an_roll_over_en_get(u32 secy_id, u32 channel,
					      bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sc_an_roll_over_en_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_an_roll_over_en_get_cmd *param =
	    (struct nss_macsec_secy_tx_sc_an_roll_over_en_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_AN_ROLL_OVER_EN_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sc_an_roll_over_en_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_an_roll_over_en_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sc_an_roll_over_en_set(u32 secy_id, u32 channel,
					      bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sc_an_roll_over_en_set_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_an_roll_over_en_set_cmd *param =
	    (struct nss_macsec_secy_tx_sc_an_roll_over_en_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_AN_ROLL_OVER_EN_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sc_an_roll_over_en_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_an_roll_over_en_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sc_in_used_get(u32 secy_id, u32 channel,
				      bool *p_in_used)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sc_in_used_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_in_used_get_cmd *param =
	    (struct nss_macsec_secy_tx_sc_in_used_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_IN_USED_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sc_in_used_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_in_used_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*p_in_used = param->p_in_used;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sc_tci_7_2_get(u32 secy_id, u32 channel, u8 *ptci)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sc_tci_7_2_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_tci_7_2_get_cmd *param =
	    (struct nss_macsec_secy_tx_sc_tci_7_2_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_TCI_7_2_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sc_tci_7_2_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_tci_7_2_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*ptci = param->ptci;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sc_tci_7_2_set(u32 secy_id, u32 channel, u8 tci)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sc_tci_7_2_set_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_tci_7_2_set_cmd *param =
	    (struct nss_macsec_secy_tx_sc_tci_7_2_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_TCI_7_2_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sc_tci_7_2_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->tci = tci;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_tci_7_2_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sc_confidentiality_offset_get(u32 secy_id, u32 channel,
						     u32 *poffset)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof
		 (struct nss_macsec_secy_tx_sc_confidentiality_offset_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_confidentiality_offset_get_cmd *param =
	    (struct nss_macsec_secy_tx_sc_confidentiality_offset_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type =
	    NSS_MACSEC_SECY_TX_SC_CONFIDENTIALITY_OFFSET_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sc_confidentiality_offset_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->poffset = *poffset;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_confidentiality_offset_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*poffset = param->poffset;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sc_confidentiality_offset_set(u32 secy_id, u32 channel,
						     u32 offset)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof
		 (struct nss_macsec_secy_tx_sc_confidentiality_offset_set_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_confidentiality_offset_set_cmd *param =
	    (struct nss_macsec_secy_tx_sc_confidentiality_offset_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type =
	    NSS_MACSEC_SECY_TX_SC_CONFIDENTIALITY_OFFSET_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sc_confidentiality_offset_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->offset = offset;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_confidentiality_offset_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sc_protect_get(u32 secy_id, u32 channel, bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sc_protect_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_protect_get_cmd *param =
	    (struct nss_macsec_secy_tx_sc_protect_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_PROTECT_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sc_protect_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_protect_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sc_protect_set(u32 secy_id, u32 channel, bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sc_protect_set_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_protect_set_cmd *param =
	    (struct nss_macsec_secy_tx_sc_protect_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_PROTECT_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sc_protect_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_protect_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sc_sci_get(u32 secy_id, u32 channel, u8 *psci,
				  u32 sci_len)
{				/* [16] */
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sc_sci_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_sci_get_cmd *param =
	    (struct nss_macsec_secy_tx_sc_sci_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_SCI_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sc_sci_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->sci_len = sci_len;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_sci_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		memcpy(psci, param->psci, sci_len);
	}
	return ret;
}

u32 nss_macsec_secy_tx_sc_start_stop_time_get(u32 secy_id, u32 channel,
					      u32 *p_start_time,
					      u32 *p_stop_time)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sc_start_stop_time_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_start_stop_time_get_cmd *param =
	    (struct nss_macsec_secy_tx_sc_start_stop_time_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_START_STOP_TIME_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sc_start_stop_time_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_start_stop_time_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*p_start_time = param->p_start_time;
		*p_stop_time = param->p_stop_time;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sc_start_stop_time_set(u32 secy_id, u32 channel,
					      u32 start_time, u32 stop_time)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sc_start_stop_time_set_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sc_start_stop_time_set_cmd *param =
	    (struct nss_macsec_secy_tx_sc_start_stop_time_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SC_START_STOP_TIME_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sc_start_stop_time_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->start_time = start_time;
	param->stop_time = stop_time;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sc_start_stop_time_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sa_create(u32 secy_id, u32 channel, u32 an)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sa_create_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sa_create_cmd *param =
	    (struct nss_macsec_secy_tx_sa_create_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SA_CREATE_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sa_create_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sa_create_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sa_en_get(u32 secy_id, u32 channel, u32 an,
				 bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sa_en_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sa_en_get_cmd *param =
	    (struct nss_macsec_secy_tx_sa_en_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SA_EN_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sa_en_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sa_en_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sa_en_set(u32 secy_id, u32 channel, u32 an, bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sa_en_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sa_en_set_cmd *param =
	    (struct nss_macsec_secy_tx_sa_en_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SA_EN_SET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sa_en_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sa_en_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sa_del(u32 secy_id, u32 channel, u32 an)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sa_del_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sa_del_cmd *param =
	    (struct nss_macsec_secy_tx_sa_del_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SA_DEL_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sa_del_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sa_del_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sa_del_all(u32 secy_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sa_del_all_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sa_del_all_cmd *param =
	    (struct nss_macsec_secy_tx_sa_del_all_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SA_DEL_ALL_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sa_del_all_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sa_del_all_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sa_next_pn_get(u32 secy_id, u32 channel, u32 an,
				      u32 *p_next_pn)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sa_next_pn_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sa_next_pn_get_cmd *param =
	    (struct nss_macsec_secy_tx_sa_next_pn_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SA_NEXT_PN_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sa_next_pn_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sa_next_pn_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*p_next_pn = param->p_next_pn;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sa_next_pn_set(u32 secy_id, u32 channel, u32 an,
				      u32 next_pn)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sa_next_pn_set_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sa_next_pn_set_cmd *param =
	    (struct nss_macsec_secy_tx_sa_next_pn_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SA_NEXT_PN_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sa_next_pn_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;
	param->next_pn = next_pn;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sa_next_pn_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sa_in_used_get(u32 secy_id, u32 channel, u32 an,
				      bool *p_in_used)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sa_in_used_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sa_in_used_get_cmd *param =
	    (struct nss_macsec_secy_tx_sa_in_used_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SA_IN_USED_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sa_in_used_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sa_in_used_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*p_in_used = param->p_in_used;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sa_start_stop_time_get(u32 secy_id, u32 channel, u32 an,
					      u32 *p_start_time,
					      u32 *p_stop_time)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sa_start_stop_time_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sa_start_stop_time_get_cmd *param =
	    (struct nss_macsec_secy_tx_sa_start_stop_time_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SA_START_STOP_TIME_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sa_start_stop_time_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sa_start_stop_time_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*p_start_time = param->p_start_time;
		*p_stop_time = param->p_stop_time;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sa_start_stop_time_set(u32 secy_id, u32 channel, u32 an,
					      u32 start_time, u32 stop_time)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_sa_start_stop_time_set_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sa_start_stop_time_set_cmd *param =
	    (struct nss_macsec_secy_tx_sa_start_stop_time_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SA_START_STOP_TIME_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_sa_start_stop_time_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;
	param->start_time = start_time;
	param->stop_time = stop_time;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sa_start_stop_time_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sak_get(u32 secy_id, u32 channel, u32 an,
			       fal_tx_sak_t *pentry)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sak_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sak_get_cmd *param =
	    (struct nss_macsec_secy_tx_sak_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SAK_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sak_get_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sak_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pentry = param->pentry;
	}
	return ret;
}

u32 nss_macsec_secy_tx_sak_set(u32 secy_id, u32 channel, u32 an,
			       fal_tx_sak_t *pentry)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sak_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sak_set_cmd *param =
	    (struct nss_macsec_secy_tx_sak_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SAK_SET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sak_set_cmd);
	param->secy_id = secy_id;
	param->channel = channel;
	param->an = an;
	param->pentry = *pentry;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sak_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_qtag_parse_set(u32 secy_id, fal_tx_vlan_parse_t *pentry)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_qtag_parse_set_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_qtag_parse_set_cmd *param =
	    (struct nss_macsec_secy_tx_qtag_parse_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_QTAG_PARSE_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_qtag_parse_set_cmd);
	param->secy_id = secy_id;
	param->pentry = *pentry;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_qtag_parse_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_qtag_parse_get(u32 secy_id, fal_tx_vlan_parse_t *pentry)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_qtag_parse_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_qtag_parse_get_cmd *param =
	    (struct nss_macsec_secy_tx_qtag_parse_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_QTAG_PARSE_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_qtag_parse_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_qtag_parse_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pentry = param->pentry;
	}
	return ret;
}

u32 nss_macsec_secy_tx_stag_parse_set(u32 secy_id, fal_tx_vlan_parse_t *pentry)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_stag_parse_set_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_stag_parse_set_cmd *param =
	    (struct nss_macsec_secy_tx_stag_parse_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_STAG_PARSE_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_stag_parse_set_cmd);
	param->secy_id = secy_id;
	param->pentry = *pentry;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_stag_parse_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_stag_parse_get(u32 secy_id, fal_tx_vlan_parse_t *pentry)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_stag_parse_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_stag_parse_get_cmd *param =
	    (struct nss_macsec_secy_tx_stag_parse_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_STAG_PARSE_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_stag_parse_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_stag_parse_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pentry = param->pentry;
	}
	return ret;
}

u32 nss_macsec_secy_tx_pn_threshold_get(u32 secy_id, u32 *p_pn_threshold)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_pn_threshold_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_pn_threshold_get_cmd *param =
	    (struct nss_macsec_secy_tx_pn_threshold_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_PN_THRESHOLD_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_pn_threshold_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_pn_threshold_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*p_pn_threshold = param->p_pn_threshold;
	}
	return ret;
}

u32 nss_macsec_secy_tx_pn_threshold_set(u32 secy_id, u32 pn_threshold)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_tx_pn_threshold_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_pn_threshold_set_cmd *param =
	    (struct nss_macsec_secy_tx_pn_threshold_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_PN_THRESHOLD_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_tx_pn_threshold_set_cmd);
	param->secy_id = secy_id;
	param->pn_threshold = pn_threshold;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_pn_threshold_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_reset(u32 secy_id)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_reset_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_reset_cmd *param =
	    (struct nss_macsec_secy_reset_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_RESET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_reset_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct nss_macsec_secy_reset_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_tx_sw_reset(u32 secy_id)	//tiger: is this API necessary?
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_tx_sw_reset_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_tx_sw_reset_cmd *param =
	    (struct nss_macsec_secy_tx_sw_reset_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_TX_SW_RESET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_tx_sw_reset_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_tx_sw_reset_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_init(u32 secy_id)
{
	unsigned char buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_init_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_init_cmd *param =
	    (struct nss_macsec_secy_init_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_INIT_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_init_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct nss_macsec_secy_init_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_sc_sa_mapping_mode_get(u32 secy_id,
					   fal_sc_sa_mapping_mode_e *pmode)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_sc_sa_mapping_mode_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_sc_sa_mapping_mode_get_cmd *param =
	    (struct nss_macsec_secy_sc_sa_mapping_mode_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_SC_SA_MAPPING_MODE_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_sc_sa_mapping_mode_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_sc_sa_mapping_mode_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pmode = param->pmode;
	}
	return ret;
}

u32 nss_macsec_secy_sc_sa_mapping_mode_set(u32 secy_id,
					   fal_sc_sa_mapping_mode_e mode)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_sc_sa_mapping_mode_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_sc_sa_mapping_mode_set_cmd *param =
	    (struct nss_macsec_secy_sc_sa_mapping_mode_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_SC_SA_MAPPING_MODE_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_sc_sa_mapping_mode_set_cmd);
	param->secy_id = secy_id;
	param->mode = mode;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_sc_sa_mapping_mode_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_controlled_port_en_get(u32 secy_id, bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_controlled_port_en_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_controlled_port_en_get_cmd *param =
	    (struct nss_macsec_secy_controlled_port_en_get_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_CONTROLLED_PORT_EN_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_controlled_port_en_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_controlled_port_en_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_controlled_port_en_set(u32 secy_id, bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_controlled_port_en_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_controlled_port_en_set_cmd *param =
	    (struct nss_macsec_secy_controlled_port_en_set_cmd *)
	    SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_CONTROLLED_PORT_EN_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_controlled_port_en_set_cmd);
	param->secy_id = secy_id;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_controlled_port_en_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_ip_version_get(u32 secy_id, char *ver_str, u32 ver_str_len)
{				/* [64] */
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_ip_version_get_cmd))]
	    = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_ip_version_get_cmd *param =
	    (struct nss_macsec_secy_ip_version_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_IP_VERSION_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_ip_version_get_cmd);
	param->secy_id = secy_id;
	param->ver_str_len = ver_str_len;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_ip_version_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		memcpy(ver_str, param->ver_str, ver_str_len);
	}
	return ret;
}

u32 nss_macsec_secy_cipher_suite_get(u32 secy_id,
				     fal_cipher_suite_e *p_cipher_suite)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_cipher_suite_get_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_cipher_suite_get_cmd *param =
	    (struct nss_macsec_secy_cipher_suite_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_CIPHER_SUITE_GET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_cipher_suite_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_cipher_suite_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*p_cipher_suite = param->p_cipher_suite;
	}
	return ret;
}

u32 nss_macsec_secy_cipher_suite_set(u32 secy_id,
				     fal_cipher_suite_e cipher_suite)
{
	unsigned char
	    buf[SDK_MSG_SIZE
		(sizeof(struct nss_macsec_secy_cipher_suite_set_cmd))] = { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_cipher_suite_set_cmd *param =
	    (struct nss_macsec_secy_cipher_suite_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_CIPHER_SUITE_SET_CMD;
	msg_header->buf_len =
	    sizeof(struct nss_macsec_secy_cipher_suite_set_cmd);
	param->secy_id = secy_id;
	param->cipher_suite = cipher_suite;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_cipher_suite_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_mtu_get(u32 secy_id, u32 *pmtu)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_mtu_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_mtu_get_cmd *param =
	    (struct nss_macsec_secy_mtu_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_MTU_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_mtu_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_mtu_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*pmtu = param->pmtu;
	}
	return ret;
}

u32 nss_macsec_secy_mtu_set(u32 secy_id, u32 mtu)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_mtu_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_mtu_set_cmd *param =
	    (struct nss_macsec_secy_mtu_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_MTU_SET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_mtu_set_cmd);
	param->secy_id = secy_id;
	param->mtu = mtu;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_mtu_set_cmd),
				       NETLINK_SDK);
	return ret;
}

u32 nss_macsec_secy_en_get(u32 secy_id, bool *penable)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_en_get_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_en_get_cmd *param =
	    (struct nss_macsec_secy_en_get_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_EN_GET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_en_get_cmd);
	param->secy_id = secy_id;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_en_get_cmd),
				       NETLINK_SDK);
	if (SDK_RET_SUCCESS == ret) {
		*penable = param->penable;
	}
	return ret;
}

u32 nss_macsec_secy_en_set(u32 secy_id, bool enable)
{
	unsigned char
	    buf[SDK_MSG_SIZE(sizeof(struct nss_macsec_secy_en_set_cmd))] =
	    { 0 };
	struct sdk_msg_header *msg_header =
	    (struct sdk_msg_header *)SDK_MSG_HEADER(buf);
	struct nss_macsec_secy_en_set_cmd *param =
	    (struct nss_macsec_secy_en_set_cmd *)SDK_MSG_DATA(buf);
	int ret = 0;

	msg_header->version = SDK_MSG_VER;
	msg_header->cmd_type = SDK_FAL_CMD;
	msg_header->sub_type = NSS_MACSEC_SECY_EN_SET_CMD;
	msg_header->buf_len = sizeof(struct nss_macsec_secy_en_set_cmd);
	param->secy_id = secy_id;
	param->enable = enable;

	ret =
	    nss_macsec_sdk_netlink_msg(SDK_CALL_MSG, buf,
				       sizeof(struct
					      nss_macsec_secy_en_set_cmd),
				       NETLINK_SDK);
	return ret;
}
