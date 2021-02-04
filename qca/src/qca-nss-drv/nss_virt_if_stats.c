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
#include "nss_tx_rx_common.h"

/*
 * Data structure that holds the virtual interface context.
 */
extern struct nss_virt_if_handle *nss_virt_if_handle_t[];

/*
 * Spinlock to protect the global data structure virt_handle.
 */
extern spinlock_t nss_virt_if_lock;

/*
 * nss_virt_if_stats_get()
 *	Get stats from the virt_if handle to buffer(line)
 */
static int32_t nss_virt_if_stats_get(int32_t if_num, int i, char *line)
{
	int32_t bytes = 0;
	struct nss_virt_if_stats *stats;
	int32_t ifnum;
	uint32_t len = 80;
	struct nss_virt_if_handle *handle = NULL;

	if (!nss_virt_if_verify_if_num(if_num)) {
		nss_warning("invalid if_num\n");
		return 0;
	}

	ifnum = if_num - NSS_DYNAMIC_IF_START;

	spin_lock_bh(&nss_virt_if_lock);
	if (!nss_virt_if_handle_t[ifnum]) {
		spin_unlock_bh(&nss_virt_if_lock);
		goto end;
	}

	handle = nss_virt_if_handle_t[ifnum];
	spin_unlock_bh(&nss_virt_if_lock);

	stats = &handle->stats;

	switch (i) {
	case 0:
		bytes = scnprintf(line, len, "rx_packets=%d\n",
					stats->node_stats.rx_packets);
		break;

	case 1:
		bytes = scnprintf(line, len, "rx_bytes=%d\n",
					stats->node_stats.rx_bytes);
		break;

	case 2:
		bytes = scnprintf(line, len, "rx_dropped=%d\n",
					nss_cmn_rx_dropped_sum(&stats->node_stats));
		break;

	case 3:
		bytes = scnprintf(line, len, "tx_packets=%d\n",
					stats->node_stats.tx_packets);
		break;

	case 4:
		bytes = scnprintf(line, len, "tx_bytes=%d\n",
					stats->node_stats.tx_bytes);
		break;

	case 5:
		bytes = scnprintf(line, len, "tx_enqueue_failed=%d\n",
						stats->tx_enqueue_failed);
		break;

	case 6:
		bytes = scnprintf(line, len, "shaper_enqueue_failed=%d\n",
						stats->shaper_enqueue_failed);
		break;
	}

end:
	return bytes;
}

/*
 * nss_virt_if_stats_read()
 *	Read virt_if statistics
 */
static ssize_t nss_virt_if_stats_read(struct file *fp, char __user *ubuf,
						size_t sz, loff_t *ppos)
{
	struct nss_stats_data *data = fp->private_data;
	struct nss_ctx_instance *nss_ctx = (struct nss_ctx_instance *)&nss_top_main.nss[nss_top_main.wifi_handler_id];
	int32_t if_num = NSS_DYNAMIC_IF_START;
	int32_t max_if_num = if_num + NSS_MAX_DYNAMIC_INTERFACES;
	size_t bytes = 0;
	ssize_t bytes_read = 0;
	char line[80];
	int start, end;

	if (data) {
		if_num = data->if_num;
	}

	if (if_num > max_if_num) {
		return 0;
	}

	for (; if_num < max_if_num; if_num++) {
		/*
		 * redir_h2n will collect stats from redir_n2h and redir_h2n in nss.
		 */
		if (nss_dynamic_interface_get_type(nss_ctx, if_num) != NSS_DYNAMIC_INTERFACE_TYPE_802_3_REDIR_H2N)
			continue;

		bytes = scnprintf(line, sizeof(line), "if_num %d stats start:\n\n", if_num);
		if ((bytes_read + bytes) > sz)
			break;

		if (copy_to_user(ubuf + bytes_read, line, bytes) != 0) {
			bytes_read = -EFAULT;
			goto end;
		}

		bytes_read += bytes;

		start = 0;
		end = 7;
		while (bytes_read < sz && start < end) {
			bytes = nss_virt_if_stats_get(if_num, start, line);
			if (!bytes)
				break;

			if ((bytes_read + bytes) > sz)
				break;

			if (copy_to_user(ubuf + bytes_read, line, bytes) != 0) {
				bytes_read = -EFAULT;
				goto end;
			}

			bytes_read += bytes;
			start++;
		}

		bytes = scnprintf(line, sizeof(line), "if_num %d stats end:\n\n", if_num);
		if (bytes_read > (sz - bytes))
			break;

		if (copy_to_user(ubuf + bytes_read, line, bytes) != 0) {
			bytes_read = -EFAULT;
			goto end;
		}

		bytes_read += bytes;
	}

	if (bytes_read > 0) {
		*ppos = bytes_read;
	}

	if (data) {
		data->if_num = if_num;
	}

end:
	return bytes_read;
}

/*
 * nss_virt_if_stats_ops
 */
NSS_STATS_DECLARE_FILE_OPERATIONS(virt_if)

/*
 * nss_virt_if_stats_dentry_create()
 *	Create virt_if statistics debug entry.
 */
void nss_virt_if_stats_dentry_create(void)
{
	nss_stats_create_dentry("virt_if", &nss_virt_if_stats_ops);
}

/*
 * nss_virt_if_stats_sync()
 *	Sync stats from the NSS FW
 */
void nss_virt_if_stats_sync(struct nss_virt_if_handle *handle,
					struct nss_virt_if_stats *nwis)
{
	struct nss_virt_if_stats *stats = &handle->stats;
	int i;

	stats->node_stats.rx_packets += nwis->node_stats.rx_packets;
	stats->node_stats.rx_bytes += nwis->node_stats.rx_bytes;
	stats->node_stats.tx_packets += nwis->node_stats.tx_packets;
	stats->node_stats.tx_bytes += nwis->node_stats.tx_bytes;

	for (i = 0; i < NSS_MAX_NUM_PRI; i++) {
		stats->node_stats.rx_dropped[i] += nwis->node_stats.rx_dropped[i];
	}

	stats->tx_enqueue_failed += nwis->tx_enqueue_failed;
	stats->shaper_enqueue_failed += nwis->shaper_enqueue_failed;
}
