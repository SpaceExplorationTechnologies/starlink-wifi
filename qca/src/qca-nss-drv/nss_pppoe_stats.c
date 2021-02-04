/*
 **************************************************************************
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
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

#include "nss_stats.h"
#include "nss_core.h"
#include "nss_pppoe_stats.h"

uint64_t nss_pppoe_stats[NSS_PPPOE_STATS_MAX];
uint64_t nss_pppoe_stats_exception[NSS_MAX_PHYSICAL_INTERFACES + 1][NSS_PPPOE_NUM_SESSION_PER_INTERFACE + 1][NSS_PPPOE_EXCEPTION_EVENT_MAX];

/*
 * nss_pppoe_stats_str
 *	PPPoE stats strings
 */
static int8_t *nss_pppoe_stats_str[NSS_PPPOE_STATS_MAX] = {
	"create_requests",
	"create_failures",
	"destroy_requests",
	"destroy_misses"
};

/*
 * nss_pppoe_stats_exception_str
 *	Interface stats strings for PPPoE exceptions
 */
static int8_t *nss_pppoe_stats_exception_str[NSS_PPPOE_EXCEPTION_EVENT_MAX] = {
	"PPPOE_WRONG_VERSION_OR_TYPE",
	"PPPOE_WRONG_CODE",
	"PPPOE_HEADER_INCOMPLETE",
	"PPPOE_UNSUPPORTED_PPP_PROTOCOL",
	"PPPOE_DEPRECATED"
};

/*
 * nss_pppoe_stats_read()
 *	Read PPPoE stats
 */
static ssize_t nss_pppoe_stats_read(struct file *fp, char __user *ubuf, size_t sz, loff_t *ppos)
{
	uint64_t stats_shadow_pppoe_except[NSS_PPPOE_NUM_SESSION_PER_INTERFACE][NSS_PPPOE_EXCEPTION_EVENT_MAX];
	int32_t i, j, k;

	/*
	 * max output lines = #stats + start tag line + end tag line + three blank lines
	 */
	uint32_t max_output_lines = (NSS_STATS_NODE_MAX + 2) + (NSS_PPPOE_STATS_MAX + 3) +
					((NSS_MAX_PHYSICAL_INTERFACES * NSS_PPPOE_NUM_SESSION_PER_INTERFACE * (NSS_PPPOE_EXCEPTION_EVENT_MAX + 5)) + 3) + 5;
	size_t size_al = NSS_STATS_MAX_STR_LENGTH * max_output_lines;
	size_t size_wr = 0;
	ssize_t bytes_read = 0;
	uint64_t *stats_shadow;

	char *lbuf = kzalloc(size_al, GFP_KERNEL);
	if (unlikely(lbuf == NULL)) {
		nss_warning("Could not allocate memory for local statistics buffer");
		return 0;
	}

	stats_shadow = kzalloc(64 * 8, GFP_KERNEL);
	if (unlikely(stats_shadow == NULL)) {
		nss_warning("Could not allocate memory for local shadow buffer");
		kfree(lbuf);
		return 0;
	}

	size_wr = scnprintf(lbuf, size_al, "pppoe stats start:\n\n");

	size_wr = nss_stats_fill_common_stats(NSS_PPPOE_RX_INTERFACE, lbuf, size_wr, size_al);

	/*
	 * PPPoE node stats
	 */
	size_wr += scnprintf(lbuf + size_wr, size_al - size_wr, "\npppoe node stats:\n\n");
	spin_lock_bh(&nss_top_main.stats_lock);
	for (i = 0; (i < NSS_PPPOE_STATS_MAX); i++) {
		stats_shadow[i] = nss_pppoe_stats[i];
	}
	spin_unlock_bh(&nss_top_main.stats_lock);

	for (i = 0; (i < NSS_PPPOE_STATS_MAX); i++) {
		size_wr += scnprintf(lbuf + size_wr, size_al - size_wr,
					"%s = %llu\n", nss_pppoe_stats_str[i], stats_shadow[i]);
	}

	/*
	 * Exception stats
	 */
	size_wr += scnprintf(lbuf + size_wr, size_al - size_wr, "\nException PPPoE:\n\n");

	for (j = 1; j <= NSS_MAX_PHYSICAL_INTERFACES; j++) {
		size_wr += scnprintf(lbuf + size_wr, size_al - size_wr, "\nInterface %d:\n\n", j);

		spin_lock_bh(&nss_top_main.stats_lock);
		for (k = 1; k <= NSS_PPPOE_NUM_SESSION_PER_INTERFACE; k++) {
			for (i = 0; (i < NSS_PPPOE_EXCEPTION_EVENT_MAX); i++) {
				stats_shadow_pppoe_except[k - 1][i] = nss_pppoe_stats_exception[j][k][i];
			}
		}
		spin_unlock_bh(&nss_top_main.stats_lock);

		for (k = 1; k <= NSS_PPPOE_NUM_SESSION_PER_INTERFACE; k++) {
			size_wr += scnprintf(lbuf + size_wr, size_al - size_wr, "%d. Session\n", k);
			for (i = 0; (i < NSS_PPPOE_EXCEPTION_EVENT_MAX); i++) {
				size_wr += scnprintf(lbuf + size_wr, size_al - size_wr,
						"%s = %llu\n",
						nss_pppoe_stats_exception_str[i],
						stats_shadow_pppoe_except[k - 1][i]);
			}
		}

	}

	size_wr += scnprintf(lbuf + size_wr, size_al - size_wr, "\npppoe stats end\n\n");
	bytes_read = simple_read_from_buffer(ubuf, sz, ppos, lbuf, strlen(lbuf));
	kfree(lbuf);
	kfree(stats_shadow);

	return bytes_read;
}

/*
 * nss_pppoe_stats_ops
 */
NSS_STATS_DECLARE_FILE_OPERATIONS(pppoe)

/*
 * nss_pppoe_stats_dentry_create()
 *	Create PPPoE node statistics debug entry.
 */
void nss_pppoe_stats_dentry_create(void)
{
	nss_stats_create_dentry("pppoe", &nss_pppoe_stats_ops);
}

/*
 * nss_pppoe_stats_node_sync()
 *	Handle the syncing of PPPoE node statistics.
 */
void nss_pppoe_stats_node_sync(struct nss_ctx_instance *nss_ctx, struct nss_pppoe_node_stats_sync_msg *npess)
{
	struct nss_top_instance *nss_top = nss_ctx->nss_top;
	int j;

	spin_lock_bh(&nss_top->stats_lock);

	nss_top->stats_node[NSS_PPPOE_RX_INTERFACE][NSS_STATS_NODE_RX_PKTS] += npess->node_stats.rx_packets;
	nss_top->stats_node[NSS_PPPOE_RX_INTERFACE][NSS_STATS_NODE_RX_BYTES] += npess->node_stats.rx_bytes;
	nss_top->stats_node[NSS_PPPOE_RX_INTERFACE][NSS_STATS_NODE_TX_PKTS] += npess->node_stats.tx_packets;
	nss_top->stats_node[NSS_PPPOE_RX_INTERFACE][NSS_STATS_NODE_TX_BYTES] += npess->node_stats.tx_bytes;

	for (j = 0; j < NSS_MAX_NUM_PRI; j++) {
		nss_top->stats_node[NSS_PPPOE_RX_INTERFACE][NSS_STATS_NODE_RX_QUEUE_0_DROPPED + j] += npess->node_stats.rx_dropped[j];
	}

	nss_pppoe_stats[NSS_PPPOE_STATS_SESSION_CREATE_REQUESTS] += npess->pppoe_session_create_requests;
	nss_pppoe_stats[NSS_PPPOE_STATS_SESSION_CREATE_FAILURES] += npess->pppoe_session_create_failures;
	nss_pppoe_stats[NSS_PPPOE_STATS_SESSION_DESTROY_REQUESTS] += npess->pppoe_session_destroy_requests;
	nss_pppoe_stats[NSS_PPPOE_STATS_SESSION_DESTROY_REQUESTS] += npess->pppoe_session_destroy_requests;

	spin_unlock_bh(&nss_top->stats_lock);
}

/*
 * nss_pppoe_stats_session_reset()
 * 	Reset PPPoE session when session is destroyed.
 */
void nss_pppoe_stats_session_reset(struct nss_ctx_instance *nss_ctx, struct nss_pppoe_session_reset_msg *npsr)
{
	uint32_t i;
	uint32_t interface = npsr->interface;
	uint32_t session_index = npsr->session_index;

	/*
	 * Reset the PPPoE statistics for this specific session.
	 */
	spin_lock_bh(&nss_ctx->nss_top->stats_lock);
	for (i = 0; i < NSS_PPPOE_EXCEPTION_EVENT_MAX; i++) {
		nss_pppoe_stats_exception[interface][session_index][i] = 0;
	}
	spin_unlock_bh(&nss_ctx->nss_top->stats_lock);
}

/*
 * nss_pppoe_stats_exception_sync()
 *	Handle the syncing of PPPoE exception statistics.
 */
void nss_pppoe_stats_exception_sync(struct nss_ctx_instance *nss_ctx, struct nss_pppoe_conn_stats_sync_msg *npess)
{
	struct nss_top_instance *nss_top = nss_ctx->nss_top;
	uint32_t index = npess->index;
	uint32_t interface_num = npess->interface_num;
	uint32_t i;

	spin_lock_bh(&nss_top->stats_lock);

	if (interface_num >= NSS_MAX_PHYSICAL_INTERFACES) {
		spin_unlock_bh(&nss_top->stats_lock);
		nss_warning("%p: Incorrect interface number %d for PPPoE exception stats", nss_ctx, interface_num);
		return;
	}

	/*
	 * pppoe exception stats
	 */
	for (i = 0; i < NSS_PPPOE_EXCEPTION_EVENT_MAX; i++) {
		nss_pppoe_stats_exception[interface_num][index][i] += npess->exception_events_pppoe[i];
	}
	spin_unlock_bh(&nss_top->stats_lock);
}
