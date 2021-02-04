/*
 * Copyright (c) 2013,2017 The Linux Foundation. All rights reserved.
 *
 *		This program is free software; you can redistribute it and/or
 *		modify it under the terms of the GNU General Public License
 *		and version 2 as published by the Free Software Foundation.
 *
 *
 *    Authors:  Alexey Kuznetsov, <kuznet@ms2.inr.ac.ru>
 *              Jamal Hadi Salim, <hadi@cyberus.ca> 990601
 *              - Ingress support
 */

#include <linux/bitops.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/string.h>
#include <linux/errno.h>
#include <linux/netdevice.h>
#include <linux/skbuff.h>
#include <linux/rtnetlink.h>
#include <linux/init.h>
#include <linux/rcupdate.h>
#include <linux/list.h>
#include <net/pkt_sched.h>
#include <net/net_namespace.h>
#include <linux/if_vlan.h>
#include <linux/proc_fs.h>
#include <linux/version.h>

#define HYFI_PRO_MME            0x88e1
#define HYFI_PRO_1905           0x893a
#define HYFI_PRO_EAPOL          0x888e
#define HYFI_PRO_LLDP           0x88cc

static int hyfi_qdisc_enable = 1;
static struct proc_dir_entry *hyfi_proc_entry;
static struct proc_dir_entry *hyfi_qdisc_entry;

static const u8 prio2band[TC_PRIO_MAX+2] = { 
    2, 3, 3, 3, 2, 3, 1, 1 , 2, 2, 2, 2, 2, 2, 2, 2, 0
};

/* 4-band FIFO queue: old style, but should be a bit faster than
   generic prio+fifo combination.
 */

#define PFIFO_FAST_BANDS 4

/*
 * Private data for a pfifo_fast scheduler containing:
 * 	- queues for the three band
 * 	- bitmap indicating which of the bands contain skbs
 */
struct hyfi_pfifo_fast_priv {
	u32 bitmap;
	struct sk_buff_head q[PFIFO_FAST_BANDS];
};

/*
 * Convert a bitmap to the first band number where an skb is queued, where:
 * 	bitmap=0 means there are no skbs on any band.
 * 	bitmap=1 means there is an skb on band 0.
 *	bitmap=7 means there are skbs on all 3 bands, etc.
 */
static const int bitmap2band[] = {-1, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0};

static inline int hyfi_pfifo_fast_filter(struct sk_buff *skb)
{
    u16 h_proto;

    if (!hyfi_qdisc_enable) 
        return 0;

    skb_reset_mac_header(skb);

    if (skb->protocol == htons(ETH_P_8021Q)) {
        struct vlan_ethhdr *vlan_eth = vlan_eth_hdr(skb);
        h_proto = ntohs(vlan_eth->h_vlan_encapsulated_proto);
    } else {
        struct ethhdr *eth = eth_hdr(skb);
        h_proto = ntohs(eth->h_proto);
    }

    return (h_proto == HYFI_PRO_MME || h_proto == HYFI_PRO_1905 ||
            h_proto == HYFI_PRO_EAPOL || h_proto == HYFI_PRO_LLDP);
}

static inline struct sk_buff_head *band2list(struct hyfi_pfifo_fast_priv *priv,
					     int band)
{
	return priv->q + band;
}

static int hyfi_pfifo_fast_enqueue(struct sk_buff *skb, struct Qdisc *qdisc)
{
	if (skb_queue_len(&qdisc->q) < qdisc_dev(qdisc)->tx_queue_len) {
		int band = prio2band[hyfi_pfifo_fast_filter(skb) ? 
            TC_PRIO_MAX + 1 : skb->priority & TC_PRIO_MAX];
		struct hyfi_pfifo_fast_priv *priv = qdisc_priv(qdisc);
		struct sk_buff_head *list = band2list(priv, band);

		priv->bitmap |= (1 << band);
		qdisc->q.qlen++;
		return __qdisc_enqueue_tail(skb, qdisc, list);
	}

	return qdisc_drop(skb, qdisc);
}

static struct sk_buff *hyfi_pfifo_fast_dequeue(struct Qdisc *qdisc)
{
	struct hyfi_pfifo_fast_priv *priv = qdisc_priv(qdisc);
	int band = bitmap2band[priv->bitmap];

	if (likely(band >= 0)) {
		struct sk_buff_head *list = band2list(priv, band);
		struct sk_buff *skb = __qdisc_dequeue_head(qdisc, list);

		qdisc->q.qlen--;
		if (skb_queue_empty(list))
			priv->bitmap &= ~(1 << band);

		return skb;
	}

	return NULL;
}

static struct sk_buff *hyfi_pfifo_fast_peek(struct Qdisc *qdisc)
{
	struct hyfi_pfifo_fast_priv *priv = qdisc_priv(qdisc);
	int band = bitmap2band[priv->bitmap];

	if (band >= 0) {
		struct sk_buff_head *list = band2list(priv, band);

		return skb_peek(list);
	}

	return NULL;
}

static void hyfi_pfifo_fast_reset(struct Qdisc *qdisc)
{
	int prio;
	struct hyfi_pfifo_fast_priv *priv = qdisc_priv(qdisc);

	for (prio = 0; prio < PFIFO_FAST_BANDS; prio++)
		__qdisc_reset_queue(qdisc, band2list(priv, prio));

	priv->bitmap = 0;
	qdisc->qstats.backlog = 0;
	qdisc->q.qlen = 0;
}

static int hyfi_pfifo_fast_dump(struct Qdisc *qdisc, struct sk_buff *skb)
{
	struct tc_prio_qopt opt = { .bands = PFIFO_FAST_BANDS };

	memcpy(&opt.priomap, prio2band, TC_PRIO_MAX + 1);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 5, 0))
	nla_put(skb, TCA_OPTIONS, sizeof(opt), &opt);
#else
	NLA_PUT(skb, TCA_OPTIONS, sizeof(opt), &opt);
#endif
	return skb->len;

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3, 5, 0))
nla_put_failure:
#endif
	return -1;
}

static int hyfi_pfifo_fast_init(struct Qdisc *qdisc, struct nlattr *opt)
{
	int prio;
	struct hyfi_pfifo_fast_priv *priv = qdisc_priv(qdisc);

	for (prio = 0; prio < PFIFO_FAST_BANDS; prio++)
		skb_queue_head_init(band2list(priv, prio));

	/* Can by-pass the queue discipline */
	qdisc->flags |= TCQ_F_CAN_BYPASS;
	return 0;
}

struct Qdisc_ops hyfi_pfifo_fast_ops __read_mostly = {
	.id		=	"hyfi_pfifo_fast",
	.priv_size	=	sizeof(struct hyfi_pfifo_fast_priv),
	.enqueue	=	hyfi_pfifo_fast_enqueue,
	.dequeue	=	hyfi_pfifo_fast_dequeue,
	.peek		=	hyfi_pfifo_fast_peek,
	.init		=	hyfi_pfifo_fast_init,
	.reset		=	hyfi_pfifo_fast_reset,
	.dump		=	hyfi_pfifo_fast_dump,
	.owner		=	THIS_MODULE,
};

static void hyfi_attach_one_qdisc(struct net_device *dev,
        struct netdev_queue *dev_queue,
        void *_unused)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 3, 8))
     struct Qdisc *qdisc = qdisc_create_dflt(dev_queue, 
             &hyfi_pfifo_fast_ops, TC_H_ROOT);
#else
     struct Qdisc *qdisc = qdisc_create_dflt(dev, dev_queue, 
             &hyfi_pfifo_fast_ops, TC_H_ROOT);
#endif
    if (!qdisc) {
        printk(KERN_ERR "%s: Device %s qdisc create failed\n", 
                __func__, dev->name);
        return;
    }

    dev_queue->qdisc_sleeping = qdisc;
}

static void hyfi_transition_one_qdisc(struct net_device *dev,
        struct netdev_queue *dev_queue,
        void *_need_watchdog)
{
    struct Qdisc *new_qdisc = dev_queue->qdisc_sleeping;

    if (!(new_qdisc->flags & TCQ_F_BUILTIN))
        clear_bit(__QDISC_STATE_DEACTIVATED, &new_qdisc->state);

    rcu_read_lock();
    rcu_assign_pointer(dev_queue->qdisc, new_qdisc);
    rcu_read_unlock();
}

static void hyfi_qdisc_add(struct net_device *dev)
{
    netdev_for_each_tx_queue(dev, hyfi_attach_one_qdisc, NULL);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 3, 8))
    {
        struct netdev_queue *txq = netdev_get_tx_queue(dev, 0);
        dev->qdisc = txq->qdisc_sleeping;
        atomic_inc(&dev->qdisc->refcnt);
    }
#endif

    if (!netif_carrier_ok(dev))
        return;

    netdev_for_each_tx_queue(dev, hyfi_transition_one_qdisc, NULL);
}

static inline int hyfi_qdisc_exclude_ifs(struct net_device *dev)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 3, 0))
    return (!strncmp(dev->name, "wifi", 4)||(dev->priv_flags & IFF_NO_QUEUE));
#else
    return (!strncmp(dev->name, "wifi", 4));
#endif
}

static int hyfi_qdisc_event(struct notifier_block *unused, unsigned long event, void *ptr)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 11, 0))
    struct net_device *dev = netdev_notifier_info_to_dev(ptr);
#else
    struct net_device *dev = ptr;
#endif

    if (!dev->tx_queue_len)
        return NOTIFY_DONE;

    if (hyfi_qdisc_exclude_ifs(dev))
        return NOTIFY_DONE;

    if (event == NETDEV_REGISTER)
        hyfi_qdisc_add(dev);

    return NOTIFY_DONE;
}

struct notifier_block hyfi_qdisc_notifier = { 
    .notifier_call = hyfi_qdisc_event
};


#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 3, 10))
static int show_hyfi_enable(struct seq_file *m, void *v)
{
	seq_printf(m, "%d\n", hyfi_qdisc_enable);
	return 0;
}

static ssize_t hyfi_write_proc(struct file *file, const char __user *buffer,
                             size_t count, loff_t *ppos)
{
	unsigned long val;
	int err = kstrtoul_from_user(buffer, count, 0, &val);
	if (err)
		return err;
	hyfi_qdisc_enable = !!val;
	return count;
}

static int hyfi_open_proc(struct inode *inode, struct file *file)
{
	return single_open(file, show_hyfi_enable, NULL);
}

static const struct file_operations fops = {
	.open = hyfi_open_proc,
	.read = seq_read,
	.llseek = seq_lseek,
	.write = hyfi_write_proc,
	.release = single_release,
};
#else
static int hyfi_read_proc(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	/* the buf size is big enough for 0 or 1 plug \n */
	return snprintf(page, 3, "%d\n", hyfi_qdisc_enable);
}

static int hyfi_write_proc(struct file *file, const char *buf, unsigned long count, void *data)
{
	u32 val;

	if (sscanf(buf, "%d", &val) != 1)
		return -EINVAL;
    
    hyfi_qdisc_enable = !!val;

    return count;
}
#endif

static int hyfi_qdisc_proc_entry_create(void)
{
	if (!(hyfi_proc_entry = proc_mkdir("hyfi", NULL)))
		return -ENOENT;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 3, 10))
	if (!(hyfi_qdisc_entry = proc_create("qdisc_enable",
                    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, hyfi_proc_entry, &fops)))
		return -ENOENT;
#else
	if (!(hyfi_qdisc_entry = create_proc_entry("qdisc_enable", 
                    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, hyfi_proc_entry)))
		return -ENOENT;

	hyfi_qdisc_entry->write_proc = hyfi_write_proc;
	hyfi_qdisc_entry->read_proc = hyfi_read_proc;
#endif


    return 0;
}

static void hyfi_qdisc_proc_entry_remove(void)
{
    if (hyfi_qdisc_entry)
        remove_proc_entry("qdisc_enable", hyfi_proc_entry);
}


static int __init hyfi_qdisc_init(void)
{
    if (register_qdisc(&hyfi_pfifo_fast_ops)) {
        printk(KERN_ERR "%s: Register hyfi qdisc failed\n", __func__);
        return -1;
    }
    
    if (register_netdevice_notifier(&hyfi_qdisc_notifier)) {
        printk(KERN_ERR "%s: Register hyfi qdisc notifier failed\n", __func__);
        goto err1;
    }

    if (hyfi_qdisc_proc_entry_create()) {
        printk(KERN_ERR "%s: Create hyfi qidisc proc entry failed\n", __func__);
        goto err0;
    }
    return 0;
err0:
    unregister_netdevice_notifier(&hyfi_qdisc_notifier);
err1:
    unregister_qdisc(&hyfi_pfifo_fast_ops);
    return -1;
}

static void __exit hyfi_qdisc_exit(void)
{
    hyfi_qdisc_proc_entry_remove();
    unregister_netdevice_notifier(&hyfi_qdisc_notifier);
    unregister_qdisc(&hyfi_pfifo_fast_ops);
}

module_init(hyfi_qdisc_init);
module_exit(hyfi_qdisc_exit);
    
MODULE_LICENSE("GPL");

