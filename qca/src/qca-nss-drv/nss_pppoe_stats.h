/*
 ******************************************************************************
 * Copyright (c) 2017, The Linux Foundation. All rights reserved.
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
 * ****************************************************************************
 */

#ifndef __NSS_PPPOE_STATS_H
#define __NSS_PPPOE_STATS_H

/*
 * PPPoE statistics
 */
enum nss_pppoe_stats_types {
	NSS_PPPOE_STATS_SESSION_CREATE_REQUESTS = 0,
					/* Number of PPPoE session create requests */
	NSS_PPPOE_STATS_SESSION_CREATE_FAILURES,
					/* Number of PPPoE session create failures */
	NSS_PPPOE_STATS_SESSION_DESTROY_REQUESTS,
					/* Number of PPPoE session destroy requests */
	NSS_PPPOE_STATS_SESSION_DESTROY_MISSES,
					/* Number of PPPoE session destroy requests that missed the cache */
	NSS_PPPOE_STATS_MAX,
};

/*
 * PPPoE statistics APIs
 */
extern void nss_pppoe_stats_node_sync(struct nss_ctx_instance *nss_ctx, struct nss_pppoe_node_stats_sync_msg *npess);
extern void nss_pppoe_stats_session_reset(struct nss_ctx_instance *nss_ctx, struct nss_pppoe_session_reset_msg *npsr);
extern void nss_pppoe_stats_exception_sync(struct nss_ctx_instance *nss_ctx, struct nss_pppoe_conn_stats_sync_msg *npess);
extern void nss_pppoe_stats_dentry_create(void);

#endif /* __NSS_PPPOE_STATS_H */
