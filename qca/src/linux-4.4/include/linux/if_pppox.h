/*
 **************************************************************************
 * Copyright (c) 2016, The Linux Foundation.  All rights reserved.
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
 **************************************************************************
 */

/***************************************************************************
 * Linux PPP over X - Generic PPP transport layer sockets
 * Linux PPP over Ethernet (PPPoE) Socket Implementation (RFC 2516)
 *
 * This file supplies definitions required by the PPP over Ethernet driver
 * (pppox.c).  All version information wrt this file is located in pppox.c
 *
 * License:
 *		This program is free software; you can redistribute it and/or
 *		modify it under the terms of the GNU General Public License
 *		as published by the Free Software Foundation; either version
 *		2 of the License, or (at your option) any later version.
 *
 */

#ifndef __LINUX_IF_PPPOX_H
#define __LINUX_IF_PPPOX_H

#include <linux/if.h>
#include <linux/netdevice.h>
#include <linux/ppp_channel.h>
#include <linux/skbuff.h>
#include <linux/workqueue.h>
#include <uapi/linux/if_pppox.h>

static inline struct pppoe_hdr *pppoe_hdr(const struct sk_buff *skb)
{
	return (struct pppoe_hdr *)skb_network_header(skb);
}

struct pppoe_opt {
	struct net_device      *dev;	  /* device associated with socket*/
	int			ifindex;  /* ifindex of device associated with socket */
	struct pppoe_addr	pa;	  /* what this socket is bound to*/
	struct sockaddr_pppox	relay;	  /* what socket data will be
					     relayed to (PPPoE relaying) */
	struct work_struct      padt_work;/* Work item for handling PADT */
};

struct pptp_opt {
	struct pptp_addr src_addr;
	struct pptp_addr dst_addr;
	u32 ack_sent, ack_recv;
	u32 seq_sent, seq_recv;
	int ppp_flags;
	bool pptp_offload_mode;
};
#include <net/sock.h>

struct pppox_sock {
	/* struct sock must be the first member of pppox_sock */
	struct sock sk;
	struct ppp_channel chan;
	struct pppox_sock	*next;	  /* for hash table */
	union {
		struct pppoe_opt pppoe;
		struct pptp_opt  pptp;
	} proto;
	__be16			num;
};
#define pppoe_dev	proto.pppoe.dev
#define pppoe_ifindex	proto.pppoe.ifindex
#define pppoe_pa	proto.pppoe.pa
#define pppoe_relay	proto.pppoe.relay

static inline struct pppox_sock *pppox_sk(struct sock *sk)
{
	return (struct pppox_sock *)sk;
}

static inline struct sock *sk_pppox(struct pppox_sock *po)
{
	return (struct sock *)po;
}

struct module;

struct pppox_proto {
	int		(*create)(struct net *net, struct socket *sock, int kern);
	int		(*ioctl)(struct socket *sock, unsigned int cmd,
				 unsigned long arg);
	struct module	*owner;
};

extern int register_pppox_proto(int proto_num, const struct pppox_proto *pp);
extern void unregister_pppox_proto(int proto_num);
extern void pppox_unbind_sock(struct sock *sk);/* delete ppp-channel binding */
extern int pppox_ioctl(struct socket *sock, unsigned int cmd, unsigned long arg);

/* PPPoX socket states */
enum {
    PPPOX_NONE		= 0,  /* initial state */
    PPPOX_CONNECTED	= 1,  /* connection established ==TCP_ESTABLISHED */
    PPPOX_BOUND		= 2,  /* bound to ppp device */
    PPPOX_RELAY		= 4,  /* forwarding is enabled */
    PPPOX_ZOMBIE	= 8,  /* dead, but still bound to ppp device */
    PPPOX_DEAD		= 16  /* dead, useless, please clean me up!*/
};

/*
 * PPPoE Channel specific operations
 */
struct pppoe_channel_ops {
	/* Must be first - general to all PPP channels */
	struct ppp_channel_ops ops;
	void (*get_addressing)(struct ppp_channel *, struct pppoe_opt *);
};

/* PPTP client callback */
typedef int (*pptp_gre_seq_offload_callback_t)(struct sk_buff *skb,
					       struct net_device *pptp_dev);

/* Return PPPoE channel specific addressing information */
extern void pppoe_channel_addressing_get(struct ppp_channel *chan,
					 struct pppoe_opt *addressing);

/* Lookup PPTP session info and return PPTP session */
extern int pptp_session_find(struct pptp_opt *opt, __be16 peer_call_id,
			     __be32 peer_ip_addr);

/* Return PPTP session information given the channel */
extern void pptp_channel_addressing_get(struct pptp_opt *opt,
					struct ppp_channel *chan);

/* Enable the PPTP session offload flag */
extern int pptp_session_enable_offload_mode(__be16 peer_call_id,
					    __be32 peer_ip_addr);

/* Disable the PPTP session offload flag */
extern int pptp_session_disable_offload_mode(__be16 peer_call_id,
					     __be32 peer_ip_addr);

/* Register the PPTP GRE packets sequence number offload callback */
extern int
pptp_register_gre_seq_offload_callback(pptp_gre_seq_offload_callback_t
				       pptp_client_cb);

/* Unregister the PPTP GRE packets sequence number offload callback */
extern void pptp_unregister_gre_seq_offload_callback(void);

#endif /* !(__LINUX_IF_PPPOX_H) */
