/*
 * sfe_drv.c
 *	simulated sfe driver for shortcut forwarding engine.
 *
 * Copyright (c) 2015,2016 The Linux Foundation. All rights reserved.
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
#include <linux/module.h>
#include <linux/version.h>
#include <linux/sysfs.h>
#include <linux/skbuff.h>
#include <net/addrconf.h>
#include <linux/inetdevice.h>
#include <net/pkt_sched.h>

#include "../shortcut-fe/sfe.h"
#include "../shortcut-fe/sfe_cm.h"
#include "sfe_drv.h"

typedef enum sfe_drv_exception {
	SFE_DRV_EXCEPTION_IPV4_MSG_UNKNOW,
	SFE_DRV_EXCEPTION_IPV6_MSG_UNKNOW,
	SFE_DRV_EXCEPTION_CONNECTION_INVALID,
	SFE_DRV_EXCEPTION_NOT_SUPPORT_BRIDGE,
	SFE_DRV_EXCEPTION_TCP_INVALID,
	SFE_DRV_EXCEPTION_PROTOCOL_NOT_SUPPORT,
	SFE_DRV_EXCEPTION_SRC_DEV_NOT_L3,
	SFE_DRV_EXCEPTION_DEST_DEV_NOT_L3,
	SFE_DRV_EXCEPTION_CREATE_FAILED,
	SFE_DRV_EXCEPTION_ENQUEUE_FAILED,
	SFE_DRV_EXCEPTION_NOT_SUPPORT_6RD,
	SFE_DRV_EXCEPTION_NO_SYNC_CB,
	SFE_DRV_EXCEPTION_MAX
} sfe_drv_exception_t;

static char *sfe_drv_exception_events_string[SFE_DRV_EXCEPTION_MAX] = {
	"IPV4_MSG_UNKNOW",
	"IPV6_MSG_UNKNOW",
	"CONNECTION_INVALID",
	"NOT_SUPPORT_BRIDGE",
	"TCP_INVALID",
	"PROTOCOL_NOT_SUPPORT",
	"SRC_DEV_NOT_L3",
	"DEST_DEV_NOT_L3",
	"CREATE_FAILED",
	"ENQUEUE_FAILED",
	"NOT_SUPPORT_6RD",
	"NO_SYNC_CB"
};

#define SFE_MESSAGE_VERSION 0x1
#define SFE_MAX_CONNECTION_NUM 65535
#define sfe_drv_ipv6_addr_copy(src, dest) memcpy((void *)(dest), (void *)(src), 16)
#define sfe_drv_ipv4_stopped(CTX) (rcu_dereference((CTX)->ipv4_stats_sync_cb) == NULL)
#define sfe_drv_ipv6_stopped(CTX) (rcu_dereference((CTX)->ipv6_stats_sync_cb) == NULL)

/*
 * message type of queued response message
 */
typedef enum {
	SFE_DRV_MSG_TYPE_IPV4,
	SFE_DRV_MSG_TYPE_IPV6
} sfe_drv_msg_types_t;

/*
 * queued response message,
 * will be sent back to caller in workqueue
 */
struct sfe_drv_response_msg {
	struct list_head node;
	sfe_drv_msg_types_t type;
	void *msg[0];
};

#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 10, 0)
#define list_first_entry_or_null(ptr, type, member) \
	(!list_empty(ptr) ? list_first_entry(ptr, type, member) : NULL)
#endif

/*
 * sfe driver context instance, private for sfe driver
 */
struct sfe_drv_ctx_instance_internal {
	struct sfe_drv_ctx_instance base;/* exported sfe driver context, is public to user of sfe driver*/

	/*
	 * Control state.
	 */
	struct kobject *sys_sfe_drv;	/* sysfs linkage */

	struct list_head msg_queue;	/* response message queue*/
	spinlock_t lock;		/* Lock to protect message queue */

	struct work_struct work;	/* work to send response message back to caller*/

	sfe_ipv4_msg_callback_t __rcu ipv4_stats_sync_cb;	/* callback to call to sync ipv4 statistics */
	void *ipv4_stats_sync_data;	/* argument for above callback: ipv4_stats_sync_cb */

	sfe_ipv6_msg_callback_t __rcu ipv6_stats_sync_cb;	/* callback to call to sync ipv6 statistics */
	void *ipv6_stats_sync_data;	/* argument for above callback: ipv6_stats_sync_cb */

	u32 exceptions[SFE_DRV_EXCEPTION_MAX];		/* statistics for exception */
};

static struct sfe_drv_ctx_instance_internal __sfe_drv_ctx;

/*
 * convert public sfe driver context to internal context
 */
#define SFE_DRV_CTX_TO_PRIVATE(base) (struct sfe_drv_ctx_instance_internal *)(base)
/*
 * convert internal sfe driver context to public context
 */
#define SFE_DRV_CTX_TO_PUBLIC(intrv) (struct sfe_drv_ctx_instance *)(intrv)

/*
 * sfe_drv_incr_exceptions()
 *	increase an exception counter.
 */
static inline void sfe_drv_incr_exceptions(sfe_drv_exception_t except)
{
	struct sfe_drv_ctx_instance_internal *sfe_drv_ctx = &__sfe_drv_ctx;

	spin_lock_bh(&sfe_drv_ctx->lock);
	sfe_drv_ctx->exceptions[except]++;
	spin_unlock_bh(&sfe_drv_ctx->lock);
}

/*
 * sfe_drv_dev_is_layer_3_interface()
 * 	check if a network device is ipv4 or ipv6 layer 3 interface
 *
 * @param dev network device to check
 * @param check_v4 check ipv4 layer 3 interface(which have ipv4 address) or ipv6 layer 3 interface(which have ipv6 address)
 */
inline bool sfe_drv_dev_is_layer_3_interface(struct net_device *dev, bool check_v4)
{
	struct in_device *in4_dev;
	struct inet6_dev *in6_dev;

	BUG_ON(!dev);

	if (likely(check_v4)) {
		/*
		 * Does our input device support IPv4 processing?
		 */
		in4_dev = (struct in_device *)dev->ip_ptr;
		if (unlikely(!in4_dev)) {
			return false;
		}

		/*
		 * Does it have an IPv4 address?  If it doesn't then we can't do anything
		 * interesting here!
		 */
		if (unlikely(!in4_dev->ifa_list)) {
			return false;
		}

		return true;
	}

	/*
	 * Does our input device support IPv6 processing?
	 */
	in6_dev = (struct inet6_dev *)dev->ip6_ptr;
	if (unlikely(!in6_dev)) {
		return false;
	}

	/*
	 * Does it have an IPv6 address?  If it doesn't then we can't do anything
	 * interesting here!
	 */
	if (unlikely(list_empty(&in6_dev->addr_list))) {
		return false;
	}

	return true;
}

/*
 * sfe_drv_clean_response_msg_by_type()
 * 	clean response message in queue when ECM exit
 *
 * @param sfe_drv_ctx sfe driver context
 * @param msg_type message type, ipv4 or ipv6
 */
static void sfe_drv_clean_response_msg_by_type(struct sfe_drv_ctx_instance_internal *sfe_drv_ctx, sfe_drv_msg_types_t msg_type)
{
	struct sfe_drv_response_msg *response, *tmp;

	if (!sfe_drv_ctx) {
		return;
	}

	spin_lock_bh(&sfe_drv_ctx->lock);
	list_for_each_entry_safe(response, tmp, &sfe_drv_ctx->msg_queue, node) {
		if (response->type == msg_type) {
			list_del(&response->node);
			/*
			 * free response message
			 */
			kfree(response);
		}
	}
	spin_unlock_bh(&sfe_drv_ctx->lock);

}

/*
 * sfe_drv_process_response_msg()
 * 	send all pending response message to ECM by calling callback function included in message
 *
 * @param work work structure
 */
static void sfe_drv_process_response_msg(struct work_struct *work)
{
	struct sfe_drv_ctx_instance_internal *sfe_drv_ctx = container_of(work, struct sfe_drv_ctx_instance_internal, work);
	struct sfe_drv_response_msg *response;

	spin_lock_bh(&sfe_drv_ctx->lock);
	while ((response = list_first_entry_or_null(&sfe_drv_ctx->msg_queue, struct sfe_drv_response_msg, node))) {
		list_del(&response->node);
		spin_unlock_bh(&sfe_drv_ctx->lock);
		rcu_read_lock();

		/*
		 * send response message back to caller
		 */
		if ((response->type == SFE_DRV_MSG_TYPE_IPV4) && !sfe_drv_ipv4_stopped(sfe_drv_ctx)) {
			struct sfe_ipv4_msg *msg = (struct sfe_ipv4_msg *)response->msg;
			sfe_ipv4_msg_callback_t callback = (sfe_ipv4_msg_callback_t)msg->cm.cb;
			if (callback) {
				callback((void *)msg->cm.app_data, msg);
			}
		} else if ((response->type == SFE_DRV_MSG_TYPE_IPV6) && !sfe_drv_ipv6_stopped(sfe_drv_ctx)) {
			struct sfe_ipv6_msg *msg = (struct sfe_ipv6_msg *)response->msg;
			sfe_ipv6_msg_callback_t callback = (sfe_ipv6_msg_callback_t)msg->cm.cb;
			if (callback) {
				callback((void *)msg->cm.app_data, msg);
			}
		}

		rcu_read_unlock();
		/*
		 * free response message
		 */
		kfree(response);
		spin_lock_bh(&sfe_drv_ctx->lock);
	}
	spin_unlock_bh(&sfe_drv_ctx->lock);
}

/*
 * sfe_drv_alloc_response_msg()
 * 	alloc and construct new response message
 *
 * @param type message type
 * @param msg used to construct response message if not NULL
 *
 * @return !NULL, success; NULL, failed
 */
static struct sfe_drv_response_msg *
sfe_drv_alloc_response_msg(sfe_drv_msg_types_t type, void *msg)
{
	struct sfe_drv_response_msg *response;
	int size;

	switch (type) {
	case SFE_DRV_MSG_TYPE_IPV4:
		size = sizeof(struct sfe_ipv4_msg);
		break;
	case SFE_DRV_MSG_TYPE_IPV6:
		size = sizeof(struct sfe_ipv6_msg);
		break;
	default:
		DEBUG_ERROR("message type %d not supported\n", type);
		return NULL;
	}

	response = (struct sfe_drv_response_msg *)kzalloc(sizeof(struct sfe_drv_response_msg) + size, GFP_ATOMIC);
	if (!response) {
		DEBUG_ERROR("allocate memory failed\n");
		return NULL;
	}

	response->type = type;

	if (msg) {
		memcpy(response->msg, msg, size);
	}

	return response;
}

/*
 * sfe_drv_enqueue_msg()
 * 	queue response message
 *
 * @param sfe_drv_ctx sfe driver context
 * @param response response message to be queue
 */
static inline void sfe_drv_enqueue_msg(struct sfe_drv_ctx_instance_internal *sfe_drv_ctx, struct sfe_drv_response_msg *response)
{
	spin_lock_bh(&sfe_drv_ctx->lock);
	list_add_tail(&response->node, &sfe_drv_ctx->msg_queue);
	spin_unlock_bh(&sfe_drv_ctx->lock);

	schedule_work(&sfe_drv_ctx->work);
}

/*
 * sfe_cmn_msg_init()
 *	Initialize the common message structure.
 *
 * @param ncm message to init
 * @param if_num interface number related with this message
 * @param type message type
 * @param cb callback function to process repsonse of this message
 * @param app_data argument for above callback function
 */
static void sfe_cmn_msg_init(struct sfe_cmn_msg *ncm, u16 if_num, u32 type,  u32 len, void *cb, void *app_data)
{
	ncm->interface = if_num;
	ncm->version = SFE_MESSAGE_VERSION;
	ncm->type = type;
	ncm->len = len;
	ncm->cb = (u32)cb;
	ncm->app_data = (u32)app_data;
}

/*
 * sfe_drv_ipv4_stats_sync_callback()
 *	Synchronize a connection's state.
 *
 * @param sis SFE statistics from SFE core engine
 */
static void sfe_drv_ipv4_stats_sync_callback(struct sfe_connection_sync *sis)
{
	struct sfe_drv_ctx_instance_internal *sfe_drv_ctx = &__sfe_drv_ctx;
	struct sfe_ipv4_msg msg;
	struct sfe_ipv4_conn_sync *sync_msg;
	sfe_ipv4_msg_callback_t sync_cb;

	rcu_read_lock();
	sync_cb = rcu_dereference(sfe_drv_ctx->ipv4_stats_sync_cb);
	if (!sync_cb) {
		rcu_read_unlock();
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_NO_SYNC_CB);
		return;
	}

	sync_msg = &msg.msg.conn_stats;

	memset(&msg, 0, sizeof(msg));
	sfe_cmn_msg_init(&msg.cm, 0, SFE_RX_CONN_STATS_SYNC_MSG,
			sizeof(struct sfe_ipv4_conn_sync), NULL, NULL);

	/*
	 * fill connection specific information
	 */
	sync_msg->protocol = (u8)sis->protocol;
	sync_msg->flow_ip = sis->src_ip.ip;
	sync_msg->flow_ip_xlate = sis->src_ip_xlate.ip;
	sync_msg->flow_ident = sis->src_port;
	sync_msg->flow_ident_xlate = sis->src_port_xlate;

	sync_msg->return_ip = sis->dest_ip.ip;
	sync_msg->return_ip_xlate = sis->dest_ip_xlate.ip;
	sync_msg->return_ident = sis->dest_port;
	sync_msg->return_ident_xlate = sis->dest_port_xlate;

	/*
	 * fill TCP protocol specific information
	 */
	if (sis->protocol == IPPROTO_TCP) {
		sync_msg->flow_max_window = sis->src_td_max_window;
		sync_msg->flow_end = sis->src_td_end;
		sync_msg->flow_max_end = sis->src_td_max_end;

		sync_msg->return_max_window = sis->dest_td_max_window;
		sync_msg->return_end = sis->dest_td_end;
		sync_msg->return_max_end = sis->dest_td_max_end;
	}

	/*
	 * fill statistics information
	 */
	sync_msg->flow_rx_packet_count = sis->src_new_packet_count;
	sync_msg->flow_rx_byte_count = sis->src_new_byte_count;
	sync_msg->flow_tx_packet_count = sis->dest_new_packet_count;
	sync_msg->flow_tx_byte_count = sis->dest_new_byte_count;

	sync_msg->return_rx_packet_count = sis->dest_new_packet_count;
	sync_msg->return_rx_byte_count = sis->dest_new_byte_count;
	sync_msg->return_tx_packet_count = sis->src_new_packet_count;
	sync_msg->return_tx_byte_count = sis->src_new_byte_count;

	/*
	 * fill expiration time to extend, in unit of msec
	 */
	sync_msg->inc_ticks = (((u32)sis->delta_jiffies) * MSEC_PER_SEC)/HZ;

	/*
	 * fill other information
	 */
	switch (sis->reason) {
	case SFE_SYNC_REASON_DESTROY:
		sync_msg->reason = SFE_RULE_SYNC_REASON_DESTROY;
		break;
	case SFE_SYNC_REASON_FLUSH:
		sync_msg->reason = SFE_RULE_SYNC_REASON_FLUSH;
		break;
	default:
		sync_msg->reason = SFE_RULE_SYNC_REASON_STATS;
		break;
	}

	/*
	 * SFE sync calling is excuted in a timer, so we can redirect it to ECM directly.
	 */
	sync_cb(sfe_drv_ctx->ipv4_stats_sync_data, &msg);
	rcu_read_unlock();
}

/*
 * sfe_drv_create_ipv4_rule_msg()
 * 	convert create message format from ecm to sfe
 *
 * @param sfe_drv_ctx sfe driver context
 * @param msg The IPv4 message
 *
 * @return sfe_tx_status_t The status of the Tx operation
 */
sfe_tx_status_t sfe_drv_create_ipv4_rule_msg(struct sfe_drv_ctx_instance_internal *sfe_drv_ctx, struct sfe_ipv4_msg *msg)
{
	struct sfe_connection_create sic;
	struct net_device *src_dev = NULL;
	struct net_device *dest_dev = NULL;
	struct sfe_drv_response_msg *response;
	enum sfe_cmn_response ret;

	response = sfe_drv_alloc_response_msg(SFE_DRV_MSG_TYPE_IPV4, msg);
	if (!response) {
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_ENQUEUE_FAILED);
		return SFE_TX_FAILURE_QUEUE;
	}

	if (!(msg->msg.rule_create.valid_flags & SFE_RULE_CREATE_CONN_VALID)) {
		ret = SFE_CMN_RESPONSE_EMSG;
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_CONNECTION_INVALID);
		goto failed_ret;
	}

	/*
	 * not support bridged flows now
	 */
	if (msg->msg.rule_create.rule_flags & SFE_RULE_CREATE_FLAG_BRIDGE_FLOW) {
		ret = SFE_CMN_RESPONSE_EINTERFACE;
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_NOT_SUPPORT_BRIDGE);
		goto failed_ret;
	}

	sic.protocol = msg->msg.rule_create.tuple.protocol;
	sic.src_ip.ip = msg->msg.rule_create.tuple.flow_ip;
	sic.dest_ip.ip = msg->msg.rule_create.tuple.return_ip;
	sic.src_ip_xlate.ip = msg->msg.rule_create.conn_rule.flow_ip_xlate;
	sic.dest_ip_xlate.ip = msg->msg.rule_create.conn_rule.return_ip_xlate;

	sic.flags = 0;
	switch (sic.protocol) {
	case IPPROTO_TCP:
		if (!(msg->msg.rule_create.valid_flags & SFE_RULE_CREATE_TCP_VALID)) {
			ret = SFE_CMN_RESPONSE_EMSG;
			sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_TCP_INVALID);
			goto failed_ret;
		}

		sic.src_port = msg->msg.rule_create.tuple.flow_ident;
		sic.dest_port = msg->msg.rule_create.tuple.return_ident;
		sic.src_port_xlate = msg->msg.rule_create.conn_rule.flow_ident_xlate;
		sic.dest_port_xlate = msg->msg.rule_create.conn_rule.return_ident_xlate;
		sic.src_td_window_scale = msg->msg.rule_create.tcp_rule.flow_window_scale;
		sic.src_td_max_window = msg->msg.rule_create.tcp_rule.flow_max_window;
		sic.src_td_end = msg->msg.rule_create.tcp_rule.flow_end;
		sic.src_td_max_end = msg->msg.rule_create.tcp_rule.flow_max_end;
		sic.dest_td_window_scale = msg->msg.rule_create.tcp_rule.return_window_scale;
		sic.dest_td_max_window = msg->msg.rule_create.tcp_rule.return_max_window;
		sic.dest_td_end = msg->msg.rule_create.tcp_rule.return_end;
		sic.dest_td_max_end = msg->msg.rule_create.tcp_rule.return_max_end;
		if (msg->msg.rule_create.rule_flags & SFE_RULE_CREATE_FLAG_NO_SEQ_CHECK) {
			sic.flags |= SFE_CREATE_FLAG_NO_SEQ_CHECK;
		}
		break;

	case IPPROTO_UDP:
		sic.src_port = msg->msg.rule_create.tuple.flow_ident;
		sic.dest_port = msg->msg.rule_create.tuple.return_ident;
		sic.src_port_xlate = msg->msg.rule_create.conn_rule.flow_ident_xlate;
		sic.dest_port_xlate = msg->msg.rule_create.conn_rule.return_ident_xlate;
		break;

	default:
		ret = SFE_CMN_RESPONSE_EMSG;
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_PROTOCOL_NOT_SUPPORT);
		goto failed_ret;
	}

	memcpy(sic.src_mac, msg->msg.rule_create.conn_rule.flow_mac, ETH_ALEN);
	memset(sic.src_mac_xlate, 0, ETH_ALEN);
	memset(sic.dest_mac, 0, ETH_ALEN);
	memcpy(sic.dest_mac_xlate, msg->msg.rule_create.conn_rule.return_mac, ETH_ALEN);

	/*
	 * Does our input device support IP processing?
	 */
	src_dev = dev_get_by_index(&init_net, msg->msg.rule_create.conn_rule.flow_top_interface_num);
	if (!src_dev || !sfe_drv_dev_is_layer_3_interface(src_dev, true)) {
		ret = SFE_CMN_RESPONSE_EINTERFACE;
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_SRC_DEV_NOT_L3);
		goto failed_ret;
	}

	/*
	 * Does our output device support IP processing?
	 */
	dest_dev = dev_get_by_index(&init_net, msg->msg.rule_create.conn_rule.return_top_interface_num);
	if (!dest_dev || !sfe_drv_dev_is_layer_3_interface(dest_dev, true)) {
		ret = SFE_CMN_RESPONSE_EINTERFACE;
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_DEST_DEV_NOT_L3);
		goto failed_ret;
	}

	sic.src_dev = src_dev;
	sic.dest_dev = dest_dev;

	sic.src_mtu = msg->msg.rule_create.conn_rule.flow_mtu;
	sic.dest_mtu = msg->msg.rule_create.conn_rule.return_mtu;

	if (msg->msg.rule_create.valid_flags & SFE_RULE_CREATE_QOS_VALID) {
		sic.src_priority = msg->msg.rule_create.qos_rule.flow_qos_tag;
		sic.dest_priority = msg->msg.rule_create.qos_rule.return_qos_tag;
		sic.flags |= SFE_CREATE_FLAG_REMARK_PRIORITY;
	}

	if (msg->msg.rule_create.valid_flags & SFE_RULE_CREATE_DSCP_MARKING_VALID) {
		sic.src_dscp = msg->msg.rule_create.dscp_rule.flow_dscp;
		sic.dest_dscp = msg->msg.rule_create.dscp_rule.return_dscp;
		sic.flags |= SFE_CREATE_FLAG_REMARK_DSCP;
	}

#ifdef CONFIG_XFRM
	if (msg->msg.rule_create.valid_flags & SFE_RULE_CREATE_DIRECTION_VALID) {
		sic.original_accel = msg->msg.rule_create.direction_rule.flow_accel;
		sic.reply_accel = msg->msg.rule_create.direction_rule.return_accel;
	} else {
		sic.original_accel = sic.reply_accel = 1;
	}
#endif

	if (!sfe_ipv4_create_rule(&sic)) {
		/* success */
		ret = SFE_CMN_RESPONSE_ACK;
	} else {
		/* failed */
		ret = SFE_CMN_RESPONSE_EMSG;
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_CREATE_FAILED);
	}

	/*
	 * fall through
	 */
failed_ret:
	if (src_dev) {
		dev_put(src_dev);
	}

	if (dest_dev) {
		dev_put(dest_dev);
	}

	/*
	 * try to queue response message
	 */
	((struct sfe_ipv4_msg *)response->msg)->cm.response = msg->cm.response = ret;
	sfe_drv_enqueue_msg(sfe_drv_ctx, response);

	return SFE_TX_SUCCESS;
}

/*
 * sfe_drv_destroy_ipv4_rule_msg()
 * 	convert destroy message format from ecm to sfe
 *
 * @param sfe_drv_ctx sfe driver context
 * @param msg The IPv4 message
 *
 * @return sfe_tx_status_t The status of the Tx operation
 */
sfe_tx_status_t sfe_drv_destroy_ipv4_rule_msg(struct sfe_drv_ctx_instance_internal *sfe_drv_ctx, struct sfe_ipv4_msg *msg)
{
	struct sfe_connection_destroy sid;
	struct sfe_drv_response_msg *response;

	response = sfe_drv_alloc_response_msg(SFE_DRV_MSG_TYPE_IPV4, msg);
	if (!response) {
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_ENQUEUE_FAILED);
		return SFE_TX_FAILURE_QUEUE;
	}

	sid.protocol = msg->msg.rule_destroy.tuple.protocol;
	sid.src_ip.ip = msg->msg.rule_destroy.tuple.flow_ip;
	sid.dest_ip.ip = msg->msg.rule_destroy.tuple.return_ip;
	sid.src_port = msg->msg.rule_destroy.tuple.flow_ident;
	sid.dest_port = msg->msg.rule_destroy.tuple.return_ident;

	sfe_ipv4_destroy_rule(&sid);

	/*
	 * try to queue response message
	 */
	((struct sfe_ipv4_msg *)response->msg)->cm.response = msg->cm.response = SFE_CMN_RESPONSE_ACK;
	sfe_drv_enqueue_msg(sfe_drv_ctx, response);

	return SFE_TX_SUCCESS;
}

/*
 * sfe_drv_ipv4_tx()
 * 	Transmit an IPv4 message to the sfe
 *
 * @param sfe_drv_ctx sfe driver context
 * @param msg The IPv4 message
 *
 * @return sfe_tx_status_t The status of the Tx operation
 */
sfe_tx_status_t sfe_drv_ipv4_tx(struct sfe_drv_ctx_instance *sfe_drv_ctx, struct sfe_ipv4_msg *msg)
{
	switch (msg->cm.type) {
	case SFE_TX_CREATE_RULE_MSG:
		return sfe_drv_create_ipv4_rule_msg(SFE_DRV_CTX_TO_PRIVATE(sfe_drv_ctx), msg);
	case SFE_TX_DESTROY_RULE_MSG:
		return sfe_drv_destroy_ipv4_rule_msg(SFE_DRV_CTX_TO_PRIVATE(sfe_drv_ctx), msg);
	default:
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_IPV4_MSG_UNKNOW);
		return SFE_TX_FAILURE_NOT_ENABLED;
	}
}
EXPORT_SYMBOL(sfe_drv_ipv4_tx);

/*
 * sfe_ipv4_msg_init()
 *	Initialize IPv4 message.
 */
void sfe_ipv4_msg_init(struct sfe_ipv4_msg *nim, u16 if_num, u32 type, u32 len,
			sfe_ipv4_msg_callback_t cb, void *app_data)
{
	sfe_cmn_msg_init(&nim->cm, if_num, type, len, (void *)cb, app_data);
}
EXPORT_SYMBOL(sfe_ipv4_msg_init);

/*
 * sfe_drv_ipv4_max_conn_count()
 * 	return maximum number of entries SFE supported
 */
int sfe_drv_ipv4_max_conn_count(void)
{
	return SFE_MAX_CONNECTION_NUM;
}
EXPORT_SYMBOL(sfe_drv_ipv4_max_conn_count);

/*
 * sfe_drv_ipv4_notify_register()
 * 	Register a notifier callback for IPv4 messages from sfe driver
 *
 * @param cb The callback pointer
 * @param app_data The application context for this message
 *
 * @return struct sfe_drv_ctx_instance * The sfe driver context
 */
struct sfe_drv_ctx_instance *sfe_drv_ipv4_notify_register(sfe_ipv4_msg_callback_t cb, void *app_data)
{
	struct sfe_drv_ctx_instance_internal *sfe_drv_ctx = &__sfe_drv_ctx;

	spin_lock_bh(&sfe_drv_ctx->lock);
	/*
	 * Hook the shortcut sync callback.
	 */
	if (cb && !sfe_drv_ctx->ipv4_stats_sync_cb) {
		sfe_ipv4_register_sync_rule_callback(sfe_drv_ipv4_stats_sync_callback);
	}

	rcu_assign_pointer(sfe_drv_ctx->ipv4_stats_sync_cb, cb);
	sfe_drv_ctx->ipv4_stats_sync_data = app_data;

	spin_unlock_bh(&sfe_drv_ctx->lock);

	return SFE_DRV_CTX_TO_PUBLIC(sfe_drv_ctx);
}
EXPORT_SYMBOL(sfe_drv_ipv4_notify_register);

/*
 * sfe_drv_ipv4_notify_unregister()
 * 	Un-Register a notifier callback for IPv4 messages from sfe driver
 */
void sfe_drv_ipv4_notify_unregister(void)
{
	struct sfe_drv_ctx_instance_internal *sfe_drv_ctx = &__sfe_drv_ctx;

	spin_lock_bh(&sfe_drv_ctx->lock);
	/*
	 * Unregister our sync callback.
	 */
	if (sfe_drv_ctx->ipv4_stats_sync_cb) {
		sfe_ipv4_register_sync_rule_callback(NULL);
		rcu_assign_pointer(sfe_drv_ctx->ipv4_stats_sync_cb, NULL);
		sfe_drv_ctx->ipv4_stats_sync_data = NULL;
	}
	spin_unlock_bh(&sfe_drv_ctx->lock);

	sfe_drv_clean_response_msg_by_type(sfe_drv_ctx, SFE_DRV_MSG_TYPE_IPV4);

	return;
}
EXPORT_SYMBOL(sfe_drv_ipv4_notify_unregister);

/*
 * sfe_drv_ipv6_stats_sync_callback()
 *	Synchronize a connection's state.
 */
static void sfe_drv_ipv6_stats_sync_callback(struct sfe_connection_sync *sis)
{
	struct sfe_drv_ctx_instance_internal *sfe_drv_ctx = &__sfe_drv_ctx;
	struct sfe_ipv6_msg msg;
	struct sfe_ipv6_conn_sync *sync_msg;
	sfe_ipv6_msg_callback_t sync_cb;

	rcu_read_lock();
	sync_cb = rcu_dereference(sfe_drv_ctx->ipv6_stats_sync_cb);
	if (!sync_cb) {
		rcu_read_unlock();
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_NO_SYNC_CB);
		return;
	}

	sync_msg = &msg.msg.conn_stats;

	memset(&msg, 0, sizeof(msg));
	sfe_cmn_msg_init(&msg.cm, 0, SFE_RX_CONN_STATS_SYNC_MSG,
			sizeof(struct sfe_ipv6_conn_sync), NULL, NULL);

	/*
	 * fill connection specific information
	 */
	sync_msg->protocol = (u8)sis->protocol;
	sfe_drv_ipv6_addr_copy(sis->src_ip.ip6, sync_msg->flow_ip);
	sync_msg->flow_ident = sis->src_port;

	sfe_drv_ipv6_addr_copy(sis->dest_ip.ip6, sync_msg->return_ip);
	sync_msg->return_ident = sis->dest_port;

	/*
	 * fill TCP protocol specific information
	 */
	if (sis->protocol == IPPROTO_TCP) {
		sync_msg->flow_max_window = sis->src_td_max_window;
		sync_msg->flow_end = sis->src_td_end;
		sync_msg->flow_max_end = sis->src_td_max_end;

		sync_msg->return_max_window = sis->dest_td_max_window;
		sync_msg->return_end = sis->dest_td_end;
		sync_msg->return_max_end = sis->dest_td_max_end;
	}

	/*
	 * fill statistics information
	 */
	sync_msg->flow_rx_packet_count = sis->src_new_packet_count;
	sync_msg->flow_rx_byte_count = sis->src_new_byte_count;
	sync_msg->flow_tx_packet_count = sis->dest_new_packet_count;
	sync_msg->flow_tx_byte_count = sis->dest_new_byte_count;

	sync_msg->return_rx_packet_count = sis->dest_new_packet_count;
	sync_msg->return_rx_byte_count = sis->dest_new_byte_count;
	sync_msg->return_tx_packet_count = sis->src_new_packet_count;
	sync_msg->return_tx_byte_count = sis->src_new_byte_count;

	/*
	 * fill expiration time to extend, in unit of msec
	 */
	sync_msg->inc_ticks = (((u32)sis->delta_jiffies) * MSEC_PER_SEC)/HZ;

	/*
	 * fill other information
	 */
	switch (sis->reason) {
	case SFE_SYNC_REASON_DESTROY:
		sync_msg->reason = SFE_RULE_SYNC_REASON_DESTROY;
		break;
	case SFE_SYNC_REASON_FLUSH:
		sync_msg->reason = SFE_RULE_SYNC_REASON_FLUSH;
		break;
	default:
		sync_msg->reason = SFE_RULE_SYNC_REASON_STATS;
		break;
	}

	/*
	 * SFE sync calling is excuted in a timer, so we can redirect it to ECM directly.
	 */
	sync_cb(sfe_drv_ctx->ipv6_stats_sync_data, &msg);
	rcu_read_unlock();
}

/*
 * sfe_drv_create_ipv6_rule_msg()
 * 	convert create message format from ecm to sfe
 *
 * @param sfe_drv_ctx sfe driver context
 * @param msg The IPv6 message
 *
 * @return sfe_tx_status_t The status of the Tx operation
 */
sfe_tx_status_t sfe_drv_create_ipv6_rule_msg(struct sfe_drv_ctx_instance_internal *sfe_drv_ctx, struct sfe_ipv6_msg *msg)
{
	struct sfe_connection_create sic;
	struct net_device *src_dev = NULL;
	struct net_device *dest_dev = NULL;
	struct sfe_drv_response_msg *response;
	enum sfe_cmn_response ret;

	response = sfe_drv_alloc_response_msg(SFE_DRV_MSG_TYPE_IPV6, msg);
	if (!response) {
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_ENQUEUE_FAILED);
		return SFE_TX_FAILURE_QUEUE;
	}

	if (!(msg->msg.rule_create.valid_flags & SFE_RULE_CREATE_CONN_VALID)) {
		ret = SFE_CMN_RESPONSE_EMSG;
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_CONNECTION_INVALID);
		goto failed_ret;
	}

	/*
	 * not support bridged flows now
	 */
	if (msg->msg.rule_create.rule_flags & SFE_RULE_CREATE_FLAG_BRIDGE_FLOW) {
		ret = SFE_CMN_RESPONSE_EINTERFACE;
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_NOT_SUPPORT_BRIDGE);
		goto failed_ret;
	}

	sic.protocol = msg->msg.rule_create.tuple.protocol;
	sfe_drv_ipv6_addr_copy(msg->msg.rule_create.tuple.flow_ip, sic.src_ip.ip6);
	sfe_drv_ipv6_addr_copy(msg->msg.rule_create.tuple.return_ip, sic.dest_ip.ip6);
	sfe_drv_ipv6_addr_copy(msg->msg.rule_create.tuple.flow_ip, sic.src_ip_xlate.ip6);
	sfe_drv_ipv6_addr_copy(msg->msg.rule_create.tuple.return_ip, sic.dest_ip_xlate.ip6);

	sic.flags = 0;
	switch (sic.protocol) {
	case IPPROTO_TCP:
		if (!(msg->msg.rule_create.valid_flags & SFE_RULE_CREATE_TCP_VALID)) {
			ret = SFE_CMN_RESPONSE_EMSG;
			sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_TCP_INVALID);
			goto failed_ret;
		}

		sic.src_port = msg->msg.rule_create.tuple.flow_ident;
		sic.dest_port = msg->msg.rule_create.tuple.return_ident;
		sic.src_port_xlate = msg->msg.rule_create.tuple.flow_ident;
		sic.dest_port_xlate = msg->msg.rule_create.tuple.return_ident;
		sic.src_td_window_scale = msg->msg.rule_create.tcp_rule.flow_window_scale;
		sic.src_td_max_window = msg->msg.rule_create.tcp_rule.flow_max_window;
		sic.src_td_end = msg->msg.rule_create.tcp_rule.flow_end;
		sic.src_td_max_end = msg->msg.rule_create.tcp_rule.flow_max_end;
		sic.dest_td_window_scale = msg->msg.rule_create.tcp_rule.return_window_scale;
		sic.dest_td_max_window = msg->msg.rule_create.tcp_rule.return_max_window;
		sic.dest_td_end = msg->msg.rule_create.tcp_rule.return_end;
		sic.dest_td_max_end = msg->msg.rule_create.tcp_rule.return_max_end;
		if (msg->msg.rule_create.rule_flags & SFE_RULE_CREATE_FLAG_NO_SEQ_CHECK) {
			sic.flags |= SFE_CREATE_FLAG_NO_SEQ_CHECK;
		}
		break;

	case IPPROTO_UDP:
		sic.src_port = msg->msg.rule_create.tuple.flow_ident;
		sic.dest_port = msg->msg.rule_create.tuple.return_ident;
		sic.src_port_xlate = msg->msg.rule_create.tuple.flow_ident;
		sic.dest_port_xlate = msg->msg.rule_create.tuple.return_ident;
		break;

	default:
		ret = SFE_CMN_RESPONSE_EMSG;
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_PROTOCOL_NOT_SUPPORT);
		goto failed_ret;
	}

	memcpy(sic.src_mac, msg->msg.rule_create.conn_rule.flow_mac, ETH_ALEN);
	memset(sic.src_mac_xlate, 0, ETH_ALEN);
	memset(sic.dest_mac, 0, ETH_ALEN);
	memcpy(sic.dest_mac_xlate, msg->msg.rule_create.conn_rule.return_mac, ETH_ALEN);
	/*
	 * Does our input device support IP processing?
	 */
	src_dev = dev_get_by_index(&init_net, msg->msg.rule_create.conn_rule.flow_top_interface_num);
	if (!src_dev || !sfe_drv_dev_is_layer_3_interface(src_dev, false)) {
		ret = SFE_CMN_RESPONSE_EINTERFACE;
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_SRC_DEV_NOT_L3);
		goto failed_ret;
	}

	/*
	 * Does our output device support IP processing?
	 */
	dest_dev = dev_get_by_index(&init_net, msg->msg.rule_create.conn_rule.return_top_interface_num);
	if (!dest_dev || !sfe_drv_dev_is_layer_3_interface(dest_dev, false)) {
		ret = SFE_CMN_RESPONSE_EINTERFACE;
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_DEST_DEV_NOT_L3);
		goto failed_ret;
	}

	sic.src_dev = src_dev;
	sic.dest_dev = dest_dev;

	sic.src_mtu = msg->msg.rule_create.conn_rule.flow_mtu;
	sic.dest_mtu = msg->msg.rule_create.conn_rule.return_mtu;

	if (msg->msg.rule_create.valid_flags & SFE_RULE_CREATE_QOS_VALID) {
		sic.src_priority = msg->msg.rule_create.qos_rule.flow_qos_tag;
		sic.dest_priority = msg->msg.rule_create.qos_rule.return_qos_tag;
		sic.flags |= SFE_CREATE_FLAG_REMARK_PRIORITY;
	}

	if (msg->msg.rule_create.valid_flags & SFE_RULE_CREATE_DSCP_MARKING_VALID) {
		sic.src_dscp = msg->msg.rule_create.dscp_rule.flow_dscp;
		sic.dest_dscp = msg->msg.rule_create.dscp_rule.return_dscp;
		sic.flags |= SFE_CREATE_FLAG_REMARK_DSCP;
	}

#ifdef CONFIG_XFRM
	if (msg->msg.rule_create.valid_flags & SFE_RULE_CREATE_DIRECTION_VALID) {
		sic.original_accel = msg->msg.rule_create.direction_rule.flow_accel;
		sic.reply_accel = msg->msg.rule_create.direction_rule.return_accel;
	} else {
		sic.original_accel = sic.reply_accel = 1;
	}
#endif

	if (!sfe_ipv6_create_rule(&sic)) {
		/* success */
		ret = SFE_CMN_RESPONSE_ACK;
	} else {
		/* failed */
		ret = SFE_CMN_RESPONSE_EMSG;
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_CREATE_FAILED);
	}

	/*
	 * fall through
	 */
failed_ret:
	if (src_dev) {
		dev_put(src_dev);
	}

	if (dest_dev) {
		dev_put(dest_dev);
	}

	/*
	 * try to queue response message
	 */
	((struct sfe_ipv6_msg *)response->msg)->cm.response = msg->cm.response = ret;
	sfe_drv_enqueue_msg(sfe_drv_ctx, response);

	return SFE_TX_SUCCESS;
}

/*
 * sfe_drv_destroy_ipv6_rule_msg()
 * 	convert destroy message format from ecm to sfe
 *
 * @param sfe_drv_ctx sfe driver context
 * @param msg The IPv6 message
 *
 * @return sfe_tx_status_t The status of the Tx operation
 */
sfe_tx_status_t sfe_drv_destroy_ipv6_rule_msg(struct sfe_drv_ctx_instance_internal *sfe_drv_ctx, struct sfe_ipv6_msg *msg)
{
	struct sfe_connection_destroy sid;
	struct sfe_drv_response_msg *response;

	response = sfe_drv_alloc_response_msg(SFE_DRV_MSG_TYPE_IPV6, msg);
	if (!response) {
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_ENQUEUE_FAILED);
		return SFE_TX_FAILURE_QUEUE;
	}

	sid.protocol = msg->msg.rule_destroy.tuple.protocol;
	sfe_drv_ipv6_addr_copy(msg->msg.rule_destroy.tuple.flow_ip, sid.src_ip.ip6);
	sfe_drv_ipv6_addr_copy(msg->msg.rule_destroy.tuple.return_ip, sid.dest_ip.ip6);
	sid.src_port = msg->msg.rule_destroy.tuple.flow_ident;
	sid.dest_port = msg->msg.rule_destroy.tuple.return_ident;

	sfe_ipv6_destroy_rule(&sid);

	/*
	 * try to queue response message
	 */
	((struct sfe_ipv6_msg *)response->msg)->cm.response = msg->cm.response = SFE_CMN_RESPONSE_ACK;
	sfe_drv_enqueue_msg(sfe_drv_ctx, response);

	return SFE_TX_SUCCESS;
}

/*
 * sfe_drv_ipv6_tx()
 * 	Transmit an IPv6 message to the sfe
 *
 * @param sfe_drv_ctx sfe driver context
 * @param msg The IPv6 message
 *
 * @return sfe_tx_status_t The status of the Tx operation
 */
sfe_tx_status_t sfe_drv_ipv6_tx(struct sfe_drv_ctx_instance *sfe_drv_ctx, struct sfe_ipv6_msg *msg)
{
	switch (msg->cm.type) {
	case SFE_TX_CREATE_RULE_MSG:
		return sfe_drv_create_ipv6_rule_msg(SFE_DRV_CTX_TO_PRIVATE(sfe_drv_ctx), msg);
	case SFE_TX_DESTROY_RULE_MSG:
		return sfe_drv_destroy_ipv6_rule_msg(SFE_DRV_CTX_TO_PRIVATE(sfe_drv_ctx), msg);
	default:
		sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_IPV6_MSG_UNKNOW);
		return SFE_TX_FAILURE_NOT_ENABLED;
	}
}
EXPORT_SYMBOL(sfe_drv_ipv6_tx);

/*
 * sfe_ipv6_msg_init()
 *	Initialize IPv6 message.
 */
void sfe_ipv6_msg_init(struct sfe_ipv6_msg *nim, u16 if_num, u32 type, u32 len,
			sfe_ipv6_msg_callback_t cb, void *app_data)
{
	sfe_cmn_msg_init(&nim->cm, if_num, type, len, (void *)cb, app_data);
}
EXPORT_SYMBOL(sfe_ipv6_msg_init);

/*
 * sfe_drv_ipv6_max_conn_count()
 * 	return maximum number of entries SFE supported
 */
int sfe_drv_ipv6_max_conn_count(void)
{
	return SFE_MAX_CONNECTION_NUM;
}
EXPORT_SYMBOL(sfe_drv_ipv6_max_conn_count);

/*
 * sfe_drv_ipv6_notify_register()
 * 	Register a notifier callback for IPv6 messages from sfe driver
 *
 * @param cb The callback pointer
 * @param app_data The application context for this message
 *
 * @return struct sfe_drv_ctx_instance * The sfe driver context
 */
struct sfe_drv_ctx_instance *sfe_drv_ipv6_notify_register(sfe_ipv6_msg_callback_t cb, void *app_data)
{
	struct sfe_drv_ctx_instance_internal *sfe_drv_ctx = &__sfe_drv_ctx;

	spin_lock_bh(&sfe_drv_ctx->lock);
	/*
	 * Hook the shortcut sync callback.
	 */
	if (cb && !sfe_drv_ctx->ipv6_stats_sync_cb) {
		sfe_ipv6_register_sync_rule_callback(sfe_drv_ipv6_stats_sync_callback);
	}

	rcu_assign_pointer(sfe_drv_ctx->ipv6_stats_sync_cb, cb);
	sfe_drv_ctx->ipv6_stats_sync_data = app_data;

	spin_unlock_bh(&sfe_drv_ctx->lock);

	return SFE_DRV_CTX_TO_PUBLIC(sfe_drv_ctx);
}
EXPORT_SYMBOL(sfe_drv_ipv6_notify_register);

/*
 * sfe_drv_ipv6_notify_unregister()
 * 	Un-Register a notifier callback for IPv6 messages from sfe driver
 */
void sfe_drv_ipv6_notify_unregister(void)
{
	struct sfe_drv_ctx_instance_internal *sfe_drv_ctx = &__sfe_drv_ctx;

	spin_lock_bh(&sfe_drv_ctx->lock);
	/*
	 * Unregister our sync callback.
	 */
	if (sfe_drv_ctx->ipv6_stats_sync_cb) {
		sfe_ipv6_register_sync_rule_callback(NULL);
		rcu_assign_pointer(sfe_drv_ctx->ipv6_stats_sync_cb, NULL);
		sfe_drv_ctx->ipv6_stats_sync_data = NULL;
	}
	spin_unlock_bh(&sfe_drv_ctx->lock);

	sfe_drv_clean_response_msg_by_type(sfe_drv_ctx, SFE_DRV_MSG_TYPE_IPV6);

	return;
}
EXPORT_SYMBOL(sfe_drv_ipv6_notify_unregister);

/*
 * sfe_tun6rd_tx()
 * 	Transmit a tun6rd message to sfe engine
 */
sfe_tx_status_t sfe_tun6rd_tx(struct sfe_drv_ctx_instance *sfe_drv_ctx, struct sfe_tun6rd_msg *msg)
{
	sfe_drv_incr_exceptions(SFE_DRV_EXCEPTION_NOT_SUPPORT_6RD);
	return SFE_TX_FAILURE_NOT_ENABLED;
}
EXPORT_SYMBOL(sfe_tun6rd_tx);

/*
 * sfe_tun6rd_msg_init()
 *      Initialize sfe_tun6rd msg.
 */
void sfe_tun6rd_msg_init(struct sfe_tun6rd_msg *ncm, u16 if_num, u32 type,  u32 len, void *cb, void *app_data)
{
	sfe_cmn_msg_init(&ncm->cm, if_num, type, len, cb, app_data);
}
EXPORT_SYMBOL(sfe_tun6rd_msg_init);

/*
 * sfe_drv_recv()
 *	Handle packet receives.
 *
 * Returns 1 if the packet is forwarded or 0 if it isn't.
 */
int sfe_drv_recv(struct sk_buff *skb)
{
	struct net_device *dev;

	/*
	 * We know that for the vast majority of packets we need the transport
	 * layer header so we may as well start to fetch it now!
	 */
	prefetch(skb->data + 32);
	barrier();

	dev = skb->dev;

#ifdef CONFIG_NET_CLS_ACT
	/*
	 * If ingress Qdisc configured, and packet not processed by ingress Qdisc yet
	 * We can not accelerate this packet.
	 */
	if (dev->ingress_queue && !(skb->tc_verd & TC_NCLS)) {
		return 0;
	}
#endif

	/*
	 * We're only interested in IPv4 and IPv6 packets.
	 */
	if (likely(htons(ETH_P_IP) == skb->protocol)) {
		if (sfe_drv_dev_is_layer_3_interface(dev, true)) {
			return sfe_ipv4_recv(dev, skb);
		} else {
			DEBUG_TRACE("no IPv4 address for device: %s\n", dev->name);
			return 0;
		}
	}

	if (likely(htons(ETH_P_IPV6) == skb->protocol)) {
		if (sfe_drv_dev_is_layer_3_interface(dev, false)) {
			return sfe_ipv6_recv(dev, skb);
		} else {
			DEBUG_TRACE("no IPv6 address for device: %s\n", dev->name);
			return 0;
		}
	}

	DEBUG_TRACE("not IP packet\n");
	return 0;
}

/*
 * sfe_drv_get_exceptions()
 * 	dump exception counters
 */
static ssize_t sfe_drv_get_exceptions(struct device *dev,
				     struct device_attribute *attr,
				     char *buf)
{
	int idx, len;
	struct sfe_drv_ctx_instance_internal *sfe_drv_ctx = &__sfe_drv_ctx;

	spin_lock_bh(&sfe_drv_ctx->lock);
	for (len = 0, idx = 0; idx < SFE_DRV_EXCEPTION_MAX; idx++) {
		if (sfe_drv_ctx->exceptions[idx]) {
			len += snprintf(buf + len, (ssize_t)(PAGE_SIZE - len), "%s = %d\n", sfe_drv_exception_events_string[idx], sfe_drv_ctx->exceptions[idx]);
		}
	}
	spin_unlock_bh(&sfe_drv_ctx->lock);

	return len;
}

/*
 * sysfs attributes.
 */
static const struct device_attribute sfe_drv_exceptions_attr =
	__ATTR(exceptions, S_IRUGO, sfe_drv_get_exceptions, NULL);

/*
 * sfe_drv_init()
 */
static int __init sfe_drv_init(void)
{
	struct sfe_drv_ctx_instance_internal *sfe_drv_ctx = &__sfe_drv_ctx;
	int result = -1;

	/*
	 * Create sys/sfe_drv
	 */
	sfe_drv_ctx->sys_sfe_drv = kobject_create_and_add("sfe_drv", NULL);
	if (!sfe_drv_ctx->sys_sfe_drv) {
		DEBUG_ERROR("failed to register sfe_drv\n");
		goto exit1;
	}

	/*
	 * Create sys/sfe_drv/exceptions
	 */
	result = sysfs_create_file(sfe_drv_ctx->sys_sfe_drv, &sfe_drv_exceptions_attr.attr);
	if (result) {
		DEBUG_ERROR("failed to register exceptions file: %d\n", result);
		goto exit2;
	}

	spin_lock_init(&sfe_drv_ctx->lock);

	INIT_LIST_HEAD(&sfe_drv_ctx->msg_queue);
	INIT_WORK(&sfe_drv_ctx->work, sfe_drv_process_response_msg);

	/*
	 * Hook the receive path in the network stack.
	 */
	BUG_ON(athrs_fast_nat_recv);
	RCU_INIT_POINTER(athrs_fast_nat_recv, sfe_drv_recv);

	return 0;
exit2:
	kobject_put(sfe_drv_ctx->sys_sfe_drv);
exit1:
	return result;
}

/*
 * sfe_drv_exit()
 */
static void __exit sfe_drv_exit(void)
{
	struct sfe_drv_ctx_instance_internal *sfe_drv_ctx = &__sfe_drv_ctx;

	/*
	 * Unregister our receive callback.
	 */
	RCU_INIT_POINTER(athrs_fast_nat_recv, NULL);

	/*
	 * Wait for all callbacks to complete.
	 */
	rcu_barrier();

	/*
	 * Destroy all connections.
	 */
	sfe_ipv4_destroy_all_rules_for_dev(NULL);
	sfe_ipv6_destroy_all_rules_for_dev(NULL);

	/*
	 * stop work queue, and flush all pending message in queue
	 */
	cancel_work_sync(&sfe_drv_ctx->work);
	sfe_drv_process_response_msg(&sfe_drv_ctx->work);

	/*
	 * Unregister our sync callback.
	 */
	sfe_drv_ipv4_notify_unregister();
	sfe_drv_ipv6_notify_unregister();

	kobject_put(sfe_drv_ctx->sys_sfe_drv);

	return;
}

module_init(sfe_drv_init)
module_exit(sfe_drv_exit)

MODULE_AUTHOR("Qualcomm Atheros Inc.");
MODULE_DESCRIPTION("Simulated driver for Shortcut Forwarding Engine");
MODULE_LICENSE("Dual BSD/GPL");

