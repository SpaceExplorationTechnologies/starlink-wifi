/*
 **************************************************************************
 * Copyright (c) 2014, 2016-2017, The Linux Foundation. All rights reserved.
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

#include "nss_qdisc.h"

struct nss_codel_stats {
	u32 peak_queue_delay;		/* Peak delay experienced by a dequeued packet */
	u32 peak_drop_delay;		/* Peak delay experienced by a packet that is dropped */
};

struct nss_codel_sched_data {
	struct nss_qdisc nq;	/* Common base class for all nss qdiscs */
	u32 target;		/* Acceptable value of queue delay */
	u32 limit;		/* Length of queue */
	u32 interval;		/* Monitoring interval */
	u8 set_default;		/* Flag to set qdisc as default qdisc for enqueue */
	struct nss_codel_stats stats;
				/* Contains nss_codel related stats */
};

static struct nla_policy nss_codel_policy[TCA_NSSCODEL_MAX + 1] = {
	[TCA_NSSCODEL_PARMS] = { .len = sizeof(struct tc_nsscodel_qopt) },
};

static int nss_codel_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
	return nss_qdisc_enqueue(skb, sch);
}

static struct sk_buff *nss_codel_dequeue(struct Qdisc *sch)
{
	return nss_qdisc_dequeue(sch);
}

static unsigned int nss_codel_drop(struct Qdisc *sch)
{
	return nss_qdisc_drop(sch);
}

static void nss_codel_reset(struct Qdisc *sch)
{
	nss_qdisc_info("nss_codel resetting!");
	nss_qdisc_reset(sch);
}

static void nss_codel_destroy(struct Qdisc *sch)
{
	struct nss_qdisc *nq = qdisc_priv(sch);
	/*
	 * Stop the polling of basic stats
	 */
	nss_qdisc_stop_basic_stats_polling(nq);
	nss_qdisc_destroy(nq);
	nss_qdisc_info("nss_codel destroyed");
}

static int nss_codel_change(struct Qdisc *sch, struct nlattr *opt)
{
	struct nss_codel_sched_data *q;
	struct tc_nsscodel_qopt *qopt;
	struct nss_if_msg nim;
	struct net_device *dev = qdisc_dev(sch);

	qopt = nss_qdisc_qopt_get(opt, nss_codel_policy, TCA_NSSCODEL_MAX, TCA_NSSCODEL_PARMS);
	if (!qopt) {
		return -EINVAL;
	}

	if (!qopt->target || !qopt->interval) {
		nss_qdisc_error("nss_codel requires a non-zero value for target "
				"and interval\n");
		return -EINVAL;
	}

	if (!qopt->limit) {
		qopt->limit = dev->tx_queue_len ? : 1;
	}

	q = qdisc_priv(sch);
	q->target = qopt->target;
	q->limit = qopt->limit;
	q->interval = qopt->interval;
	q->set_default = qopt->set_default;

	/*
	 * Required for basic stats display
	 */
	sch->limit = qopt->limit;

	nss_qdisc_info("Target:%u Limit:%u Interval:%u set_default = %u\n",
		q->target, q->limit, q->interval, qopt->set_default);


	nim.msg.shaper_configure.config.msg.shaper_node_config.qos_tag = q->nq.qos_tag;
	/*
	 * Target and interval time needs to be provided in milliseconds
	 * (tc provides us the time in mircoseconds and therefore we divide by 1000)
	 */
	nim.msg.shaper_configure.config.msg.shaper_node_config.snc.codel_param.qlen_max = q->limit;
	nim.msg.shaper_configure.config.msg.shaper_node_config.snc.codel_param.cap.interval = q->interval/1000;
	nim.msg.shaper_configure.config.msg.shaper_node_config.snc.codel_param.cap.target = q->target/1000;
	nim.msg.shaper_configure.config.msg.shaper_node_config.snc.codel_param.cap.mtu = psched_mtu(dev);
	nss_qdisc_info("MTU size of interface %s is %u bytes\n", dev->name,
			nim.msg.shaper_configure.config.msg.shaper_node_config.snc.codel_param.cap.mtu);

	if (nss_qdisc_configure(&q->nq, &nim,
				NSS_SHAPER_CONFIG_TYPE_SHAPER_NODE_CHANGE_PARAM) < 0) {
		return -EINVAL;
	}

	/*
	 * There is nothing we need to do if the qdisc is not
	 * set as default qdisc.
	 */
	if (!q->set_default) {
		return 0;
	}

	/*
	 * Set this qdisc to be the default qdisc for enqueuing packets.
	 */
	if (nss_qdisc_set_default(&q->nq) < 0) {
		return -EINVAL;
	}

	return 0;
}

static int nss_codel_init(struct Qdisc *sch, struct nlattr *opt)
{
	struct nss_qdisc *nq = qdisc_priv(sch);
	struct tc_nsscodel_qopt *qopt;

	if (!opt) {
		return -EINVAL;
	}

	qopt = nss_qdisc_qopt_get(opt, nss_codel_policy, TCA_NSSCODEL_MAX, TCA_NSSCODEL_PARMS);
	if (!qopt) {
		return -EINVAL;
	}

	if (qopt->accel_mode != TCA_NSS_ACCEL_MODE_NSS_FW) {
		nss_qdisc_warning("NSS codel supports only offload mode %d", TCA_NSS_ACCEL_MODE_NSS_FW);
		return -EINVAL;
	}

	nss_codel_reset(sch);
	if (nss_qdisc_init(sch, nq, NSS_SHAPER_NODE_TYPE_CODEL, 0, qopt->accel_mode) < 0) {
		return -EINVAL;
	}

	if (nss_codel_change(sch, opt) < 0) {
		nss_qdisc_destroy(nq);
		return -EINVAL;
	}

	/*
	 * Start the stats polling timer
	 */
	nss_qdisc_start_basic_stats_polling(nq);

	return 0;
}

static int nss_codel_dump(struct Qdisc *sch, struct sk_buff *skb)
{
	struct nss_codel_sched_data *q;
	struct nlattr *opts = NULL;
	struct tc_nsscodel_qopt opt;

	nss_qdisc_info("NssCodel Dumping!");

	q = qdisc_priv(sch);
	if (q == NULL) {
		return -1;
	}

	opt.target = q->target;
	opt.limit = q->limit;
	opt.interval = q->interval;
	opt.set_default = q->set_default;
	opt.accel_mode = nss_qdisc_accel_mode_get(&q->nq);

	opts = nla_nest_start(skb, TCA_OPTIONS);
	if (opts == NULL) {
		goto nla_put_failure;
	}

	if (nla_put(skb, TCA_NSSCODEL_PARMS, sizeof(opt), &opt)) {
		goto nla_put_failure;
	}

	return nla_nest_end(skb, opts);

nla_put_failure:
	nla_nest_cancel(skb, opts);
	return -EMSGSIZE;
}

static int nss_codel_dump_stats(struct Qdisc *sch, struct gnet_dump *d)
{
	struct nss_codel_sched_data *q = qdisc_priv(sch);
	struct tc_nsscodel_xstats st = {
		.peak_queue_delay = q->nq.basic_stats_latest.packet_latency_peak_msec_dequeued,
		.peak_drop_delay = q->nq.basic_stats_latest.packet_latency_peak_msec_dropped,
	};

	return gnet_stats_copy_app(d, &st, sizeof(st));
}

static struct sk_buff *nss_codel_peek(struct Qdisc *sch)
{
	nss_qdisc_info("Nsscodel Peeking");
	return nss_qdisc_peek(sch);
}


struct Qdisc_ops nss_codel_qdisc_ops __read_mostly = {
	.id		=	"nsscodel",
	.priv_size	=	sizeof(struct nss_codel_sched_data),
	.enqueue	=	nss_codel_enqueue,
	.dequeue	=	nss_codel_dequeue,
	.peek		=	nss_codel_peek,
	.drop		=	nss_codel_drop,
	.init		=	nss_codel_init,
	.reset		=	nss_codel_reset,
	.destroy	=	nss_codel_destroy,
	.change		=	nss_codel_change,
	.dump		=	nss_codel_dump,
	.dump_stats	=	nss_codel_dump_stats,
	.owner		=	THIS_MODULE,
};
