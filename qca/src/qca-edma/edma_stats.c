/*
 * Copyright (c) 2017, The Linux Foundation. All rights reserved.
 *
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

#include "edma.h"
#include "ess_edma.h"

#define EDMA_SYSCTL_RBUF_MAX_SIZE 300
#define EDMA_SYSCTL_WBUF_MAX_SIZE 7
#define EDMA_SYSCTL_FLOW_TBL_SIZE 800

extern struct net_device *edma_netdev[EDMA_MAX_PORTID_SUPPORTED];

const char *edma_access_category[] = {
			"BK",
			"BE",
			"VI",
			"VO",
};

u8 edma_dscp2ac_tbl[EDMA_PRECEDENCE_MAX];
u32 edma_per_prec_stats_enable __read_mostly = 0;
u32 edma_prec_stats_reset __read_mostly = 0;
u32 edma_iad_stats_enable __read_mostly = 0;
u32 edma_iad_stats_reset __read_mostly = 0;
u32 edma_max_valid_ifd_usec __read_mostly = 5*1000000;
struct edma_flow_attrib edma_flow_tbl[EDMA_MAX_IAD_FLOW_STATS_SUPPORTED];
struct edma_video_delay_stats  edma_iad_stats_tx[EDMA_MAX_IAD_FLOW_STATS_SUPPORTED];
struct edma_video_delay_stats  edma_iad_stats_rx[EDMA_MAX_IAD_FLOW_STATS_SUPPORTED];

/* edma_dscp2ac_mapping_update()
 *	Map dscp to user-provided Access category values
 */
int edma_dscp2ac_mapping_update(struct ctl_table *table, int write,
				       void __user *buffer, size_t *lenp,
				       loff_t *ppos)
{
	char *tokens[EDMA_DSCP2AC_INPUT_PARAMS_MAX];
	char *readbuf = NULL;
	size_t add_len = 0;
	int len, i, ret;
	u8 precedence, ac;
	char writebuf[EDMA_SYSCTL_WBUF_MAX_SIZE];
	loff_t w_offset = 0;
	char *str;
	int count;

	if (write) {
		add_len = simple_write_to_buffer(writebuf, sizeof(writebuf), &w_offset,  buffer, EDMA_SYSCTL_WBUF_MAX_SIZE - 1);
		writebuf[add_len] = '\0';

		count = 0;
		str = writebuf;
		tokens[count] = strsep(&str, " ");
		while (tokens[count] != NULL) {
			count++;
			if (count == EDMA_DSCP2AC_INPUT_PARAMS_MAX) {
				break;
			}

			tokens[count] = strsep(&str, " ");
		}

		ret = sscanf(tokens[0], "%hhu", &precedence);
		if (ret != 1) {
			pr_err("Failed to read precedence token\n");
			return -EFAULT;
		}

		ret = sscanf(tokens[1], "%hhu", &ac);
		if (ret != 1) {
			pr_err("Failed to read AC token\n");
			return -EFAULT;
		}

		/* Use first 3-bits of the 6-bit input DSCP for precedence */
		precedence = precedence >> 3;

		if (precedence > 7 || ac > 3 ) {
			pr_info(" Invalid Input. Valid Range: precedence - 0-7, ac - 0-3\n");
			return -EINVAL;
		}

		/* Update access category in the global dscp table */
		edma_dscp2ac_tbl[precedence] = ac;

		return 0;
	}

	readbuf = vmalloc(EDMA_SYSCTL_RBUF_MAX_SIZE);
	if (!readbuf) {
		pr_err("Failed to allocate Memory\n");
		return -EINVAL;
	}

	len = scnprintf(readbuf + add_len, 45 ,"%s \n", "precedence:   0   1   2   3   4   5   6   7\n");
	add_len += len;
	len = scnprintf(readbuf + add_len, 15, "%s", "AC:          ");
	add_len += len;

	for (i = 0; i < EDMA_PRECEDENCE_MAX; i++) {
		len = scnprintf(readbuf + add_len, 6, " %s ", edma_access_category[edma_dscp2ac_tbl[i]]);
		add_len += len;
	}

	len = scnprintf(readbuf + add_len, 4, "\n\n");
	add_len += len;

	/* Add Usage/help details in the read buffer */
	len = scnprintf(readbuf + add_len, 40, "Usage: echo \"<dscp> <AC>\" > dscp2ac\n");
	add_len += len;
	len = scnprintf(readbuf + add_len, 37, "dscp: 6 bits dscp value in Decimal\n");
	add_len += len;
	len = scnprintf(readbuf + add_len, 55, "AC: 0 --> BK\n    1 --> BE\n    2 --> VI\n    3 --> VO\n");
	add_len += len;

	add_len = simple_read_from_buffer(buffer, *lenp, ppos, readbuf, add_len);
	*lenp = add_len;

	vfree(readbuf);

	return 0;
}

/* edma_per_prec_stats_enable_handler()
 *	Enable per precedence statistics
 */
int edma_per_prec_stats_enable_handler(struct ctl_table *table, int write,
				   void __user *buffer, size_t *lenp,
				   loff_t *ppos)
{
	int ret;

	ret = proc_dointvec(table, write, buffer, lenp, ppos);

	if (!write)
		return ret;

	if (ret) {
		pr_err("Errno: -%d.\n", ret);
		return ret;
	}

	switch (edma_per_prec_stats_enable) {
	case 0:
	case 1:
		break;
	default:
		pr_err("Invalid input. Valid input values: <0|1>\n");
		ret = -1;
		break;
	}

	return ret;
}

/* edma_prec_stats_reset_handler()
 *	Reset per-precedence statistics
 */
int edma_prec_stats_reset_handler(struct ctl_table *table, int write,
				   void __user *buffer, size_t *lenp,
				   loff_t *ppos)
{
	struct edma_adapter *adapter;
	struct edma_common_info *edma_cinfo;
	int ret;

	if (!edma_netdev[0]) {
		pr_err("Invalid Netdevice.\n");
		return -1;
	}

	adapter = netdev_priv(edma_netdev[0]);
	edma_cinfo = adapter->edma_cinfo;

	ret = proc_dointvec(table, write, buffer, lenp, ppos);

	if (!write)
		return ret;

	if (ret) {
		pr_err("Errno: -%d.\n", ret);
		return ret;
	}

	switch (edma_prec_stats_reset) {
	case 0:
		break;
	case 1:
		memset(edma_cinfo->edma_ethstats.tx_prec, 0, sizeof(u64) * EDMA_PRECEDENCE_MAX);
		memset(edma_cinfo->edma_ethstats.rx_prec, 0, sizeof(u64) * EDMA_PRECEDENCE_MAX);
		memset(edma_cinfo->edma_ethstats.tx_ac, 0, sizeof(u64) * EDMA_AC_MAX);
		memset(edma_cinfo->edma_ethstats.rx_ac, 0, sizeof(u64) * EDMA_AC_MAX);
		break;
	default:
		pr_err("Invalid input. Valid input value: 1\n");
		ret = -1;
		break;
	}

	return ret;
}

int edma_iad_stats_enable_handler(struct ctl_table *table, int write,
				   void __user *buffer, size_t *lenp,
				   loff_t *ppos)
{
	int ret;

	ret = proc_dointvec(table, write, buffer, lenp, ppos);

	if (!write)
		return ret;

	if (ret) {
		pr_err("Errno: -%d.\n", ret);
		return ret;
	}

	switch (edma_iad_stats_enable) {
	case 0:
		break;
	case 1:
		edma_per_prec_stats_enable = 1;
		pr_info("This enables per-precedence logs. If not needed, needs to be manually disabled\n");
		pr_info("Usage: echo 0 > /proc/sys/net/edma/per_prec_stats_enable\n");
		break;
	default:
		pr_err("Invalid input.Valid input values: <0|1>\n");
		ret = -1;
		break;
	}

	return ret;
}

int edma_iad_stats_reset_handler(struct ctl_table *table, int write,
				   void __user *buffer, size_t *lenp,
				   loff_t *ppos)
{
	struct edma_adapter *adapter;
	struct edma_common_info *edma_cinfo;
	int ret;

	if (!edma_netdev[0]) {
		pr_err("Invalid Netdevice\n");
		return -1;
	}

	adapter = netdev_priv(edma_netdev[0]);
	edma_cinfo = adapter->edma_cinfo;

	ret = proc_dointvec(table, write, buffer, lenp, ppos);

	if (!write)
		return ret;

	if (ret) {
		pr_err("Errno: -%d.\n", ret);
		return ret;
	}

	switch (edma_iad_stats_reset) {
	case 0:
		break;
	case 1:
		memset(edma_flow_tbl, 0, sizeof(struct edma_flow_attrib) * EDMA_MAX_IAD_FLOW_STATS_SUPPORTED);
		memset(edma_iad_stats_tx, 0, sizeof(struct edma_video_delay_stats) * EDMA_MAX_IAD_FLOW_STATS_SUPPORTED);
		memset(edma_iad_stats_rx, 0, sizeof(struct edma_video_delay_stats) * EDMA_MAX_IAD_FLOW_STATS_SUPPORTED);
		memset(edma_cinfo->edma_ethstats.tx_flow_iad, 0, sizeof(u64) * EDMA_MAX_IAD_FLOW_STATS_SUPPORTED);
		memset(edma_cinfo->edma_ethstats.rx_flow_iad, 0, sizeof(u64) * EDMA_MAX_IAD_FLOW_STATS_SUPPORTED);
		memset(edma_cinfo->edma_ethstats.tx_flow_delta_start_ts, 0, sizeof(u64) * EDMA_MAX_IAD_FLOW_STATS_SUPPORTED);
		memset(edma_cinfo->edma_ethstats.rx_flow_delta_start_ts, 0, sizeof(u64) * EDMA_MAX_IAD_FLOW_STATS_SUPPORTED);
		break;
	default:
		pr_err("Invalid input\n");
		ret = -1;
		break;
	}

	return ret;
}

int edma_print_flow_table_handler(struct ctl_table *table, int write,
				   void __user *buffer, size_t *lenp,
				   loff_t *ppos)
{
	int i, len;
	char *readbuf = NULL;
	size_t add_len = 0;

	if (!write) {
		readbuf = vmalloc(EDMA_SYSCTL_FLOW_TBL_SIZE);
		if (!readbuf) {
			pr_err("Failed to allocate Memory\n");
			return -EINVAL;
		}

		for (i = 0; i < 8; i++) {
			if (edma_flow_tbl[i].ip_version == 4) {
				len =  scnprintf(readbuf + add_len, 75,"Flow: %d SIP: %pI4 DIP: %pI4 Sport: %d Dport: %d \n", i+1, &edma_flow_tbl[i].saddr, &edma_flow_tbl[i].daddr, ntohs(edma_flow_tbl[i].sport), ntohs(edma_flow_tbl[i].dport));
			} else if (edma_flow_tbl[i].ip_version == 6) {
				len =  scnprintf(readbuf + add_len, 100,"Flow: %d SIP: %X DIP: %X Sport: %d Dport: %d \n", i+1, edma_flow_tbl[i].saddr, edma_flow_tbl[i].daddr, ntohs(edma_flow_tbl[i].sport), ntohs(edma_flow_tbl[i].dport));
			} else {
				len =  scnprintf(readbuf + add_len, 75,"Flow: %d SIP: %pI4 DIP: %pI4 Sport: %d Dport: %d \n", i+1, &edma_flow_tbl[i].saddr, &edma_flow_tbl[i].daddr, ntohs(edma_flow_tbl[i].sport), ntohs(edma_flow_tbl[i].dport));
			}

			add_len += len;
		}

		add_len  = simple_read_from_buffer(buffer, *lenp, ppos, readbuf, add_len);
		*lenp = add_len;

		vfree(readbuf);

		return 0;
	}

	return 0;
}

int edma_max_valid_ifd_usec_handler(struct ctl_table *table, int write,
				   void __user *buffer, size_t *lenp,
				   loff_t *ppos)
{
	int ret;

	ret = proc_dointvec(table, write, buffer, lenp, ppos);
	if (ret) {
		pr_err("Errno: -%d.\n", ret);
		return ret;
	}

	return 0;
}

/* edma_get_flow()
 *	get flow id from dest address and destination port
 */
int edma_get_flow_from_4tuple(u32 saddr, u32 daddr, u16 sport, u16 dport, u8 version)
{
	int i = 0;

	/* Lookup for the 4tuple in the flow table */
	while (edma_flow_tbl[i].dport) {
		if ((edma_flow_tbl[i].sport) == sport && (edma_flow_tbl[i].dport == dport)
			&& (edma_flow_tbl[i].daddr == daddr) && (edma_flow_tbl[i].saddr == saddr )) {
				return i;
		}

		i++;

		if (i == EDMA_MAX_IAD_FLOW_STATS_SUPPORTED) {
			return -EINVAL;
		}
	}

	/* Add the flow into the flow table */
	edma_flow_tbl[i].saddr = saddr;
	edma_flow_tbl[i].daddr = daddr;
	edma_flow_tbl[i].sport = sport;
	edma_flow_tbl[i].dport = dport;
	edma_flow_tbl[i].ip_version = version;

	return i;
};

/* edma_get_time_usec()
 *	Get current time in microseconds
 */
uint64_t edma_get_time_usec(void)
{
	struct timespec ts;
	ktime_get_ts(&ts);

	return ((uint64_t) ts.tv_sec * 1000000) + (ts.tv_nsec / 1000);
}

/* edma_iad_stats_update()
 *	  Update inter-arrival-delay stats
 */
void edma_iad_stats_update(struct edma_common_info *edma_cinfo, u8 flow, u8 dir)
{
	struct edma_video_delay_stats *stats ;
	uint64_t current_ts, current_ifd;
	uint64_t *eth_stat_interframe_delay, *eth_stat_start_ts;

	if (dir == EDMA_INGRESS_DIR) {
		stats = &edma_iad_stats_rx[flow];
		eth_stat_interframe_delay = &edma_cinfo->edma_ethstats.rx_flow_iad[flow];
		eth_stat_start_ts = &edma_cinfo->edma_ethstats.rx_flow_delta_start_ts[flow];
	} else {
		stats = &edma_iad_stats_tx[flow];
		eth_stat_interframe_delay = &edma_cinfo->edma_ethstats.tx_flow_iad[flow];
		eth_stat_start_ts = &edma_cinfo->edma_ethstats.tx_flow_delta_start_ts[flow];
	}

	current_ts = edma_get_time_usec();

	/* If this is first packet */
	if (stats->start_ts == 0) {
		stats->start_ts = current_ts;
		stats->max_interframe_delay = 0;
	} else {
		current_ifd = current_ts - stats->last_frame_ts;

		if ((current_ifd > stats->max_interframe_delay) && (current_ifd <= edma_max_valid_ifd_usec)) {
			stats->max_interframe_delay = current_ifd;

			*eth_stat_interframe_delay = stats->max_interframe_delay;

			/* We note the delta between start timestamp and the timestamp
			 * when the max_interframe_delay was observed
			 */
			*eth_stat_start_ts = current_ts - stats->start_ts;
		}
	}

	stats->last_frame_ts = current_ts;
}

/* edma_iad_process_flow()
 *	Process incoming flow for iad stats
 */
void edma_iad_process_flow(struct edma_common_info *edma_cinfo, struct sk_buff *skb, u8 dir, u8 precedence)
{
	struct flow_keys keys;
	int flow, res;
	int ipver = 4;
	u32 saddr = 0;
	u32 daddr = 0;
	u16 sport = 0;
	u16 dport = 0;
	u8 ip_proto = 0;


	if (dir == EDMA_INGRESS_DIR)
		skb_reset_network_header(skb);

#if (LINUX_VERSION_CODE <= KERNEL_VERSION(3, 18, 21))
	res = skb_flow_dissect(skb, &keys);
	if (res) {
		ip_proto = keys.ip_proto;
		sport = keys.port16[0];
		dport = keys.port16[1];

		if (skb->protocol == htons(ETH_P_IP)) {
			saddr = keys.src;
			daddr = keys.dst;
		}
	}
#else
	res = skb_flow_dissect_flow_keys(skb, &keys, 0);
	if (res) {
		ip_proto = keys.basic.ip_proto;
		sport = keys.ports.src;
		dport = keys.ports.dst;

		if (skb->protocol == htons(ETH_P_IP)) {
			saddr = keys.addrs.v4addrs.src;
			daddr = keys.addrs.v4addrs.dst;
		}
	}
#endif
	/* For IPv6, we use last 32bits of the source/dest address for lookup */
	if (skb->protocol == htons(ETH_P_IPV6)) {
		int nhoff = skb_network_offset(skb);

		const struct ipv6hdr *iph;
		struct ipv6hdr _iph;

		iph = skb_header_pointer(skb, nhoff, sizeof(_iph), &_iph);
		if (!iph) {
			pr_info(" Invalid IP header. Skipping the packet for stats\n");
			return;
		}

		saddr = iph->saddr.s6_addr32[3];
		daddr = iph->daddr.s6_addr32[3];

		ipver = 6;
	}

	/* Get the flow and update the stats */
	if ((ip_proto == IPPROTO_TCP) || (ip_proto == IPPROTO_UDP)) {
		flow = edma_get_flow_from_4tuple(saddr, daddr, sport,
						 dport, ipver);

		if (flow >= 0)
			edma_iad_stats_update(edma_cinfo, flow, dir);
	}
}


