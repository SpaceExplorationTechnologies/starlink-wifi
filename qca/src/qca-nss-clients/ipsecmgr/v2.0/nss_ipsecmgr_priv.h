/*
 * ********************************************************************************
 * Copyright (c) 2016-2018, The Linux Foundation. All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 **********************************************************************************
 */

#ifndef __NSS_IPSECMGR_PRIV_H
#define __NSS_IPSECMGR_PRIV_H

#include <net/ipv6.h>
#include <nss_api_if.h>
#include <nss_ipsec.h>
#include <nss_ipsecmgr.h>

#define NSS_IPSECMGR_DEBUG_LVL_ERROR 1		/**< Turn on debug for an error. */
#define NSS_IPSECMGR_DEBUG_LVL_WARN 2		/**< Turn on debug for a warning. */
#define NSS_IPSECMGR_DEBUG_LVL_INFO 3		/**< Turn on debug for information. */
#define NSS_IPSECMGR_DEBUG_LVL_TRACE 4		/**< Turn on debug for trace. */

#define nss_ipsecmgr_info_always(s, ...) pr_info("%s[%d]:" s "\n", __func__, __LINE__, ##__VA_ARGS__)

#define nss_ipsecmgr_error(s, ...) do {	\
	if (net_ratelimit()) {	\
		pr_alert("%s[%d]:" s "\n", __func__, __LINE__, ##__VA_ARGS__);	\
	}	\
} while (0)

#define nss_ipsecmgr_warn(s, ...) do {	\
	if (net_ratelimit()) {	\
		pr_warn("%s[%d]:" s "\n", __func__, __LINE__, ##__VA_ARGS__);	\
	}	\
} while (0)

#if defined(CONFIG_DYNAMIC_DEBUG)
/*
 * Compile messages for dynamic enable/disable
 */
#define nss_ipsecmgr_info(s, ...) pr_debug("%s[%d]:" s "\n", __func__, __LINE__, ##__VA_ARGS__)
#define nss_ipsecmgr_trace(s, ...) pr_debug("%s[%d]:" s "\n", __func__, __LINE__, ##__VA_ARGS__)

#else
/*
 * Statically compile messages at different levels
 */
#define nss_ipsecmgr_info(s, ...) {	\
	if (NSS_IPSECMGR_DEBUG_LEVEL > NSS_IPSECMGR_DEBUG_LVL_INFO) {	\
		pr_notice("%s[%d]:" s "\n", __func__, __LINE__, ##__VA_ARGS__);	\
	}	\
}
#define nss_ipsecmgr_trace(s, ...) {	\
	if (NSS_IPSECMGR_DEBUG_LEVEL > NSS_IPSECMGR_DEBUG_LVL_TRACE) {	\
		pr_info("%s[%d]:" s "\n", __func__, __LINE__, ##__VA_ARGS__);	\
	}	\
}

#endif /* !CONFIG_DYNAMIC_DEBUG */
#define NSS_IPSECMGR_CHK_POW2(x) (__builtin_constant_p(x) && !(~(x - 1) & (x >> 1)))

#define NSS_IPSECMGR_MAX_NAME (NSS_IPSECMGR_MAX_KEY_NAME + 64)

#define NSS_IPSECMGR_SA_MAX  64 /* Max SAs */
#if (~(NSS_IPSECMGR_SA_MAX - 1) & (NSS_IPSECMGR_SA_MAX >> 1))
#error "NSS_IPSECMGR_SA_MAX is not a power of 2"
#endif

#define NSS_IPSECMGR_SA_STATS_SZ 512
#define NSS_IPSECMGR_SA_STATS_BUF_SZ 2048
#define NSS_IPSECMGR_SA_FREE_TIMEOUT msecs_to_jiffies(100) /* msecs */

#define NSS_IPSECMGR_FLOW_MAX 256 /* Max flows */
#if (~(NSS_IPSECMGR_FLOW_MAX - 1) & (NSS_IPSECMGR_FLOW_MAX >> 1))
#error "NSS_IPSECMGR_FLOW_MAX is not a power of 2"
#endif

#define NSS_IPSECMGR_FLOW_RETRY_TIMEOUT msecs_to_jiffies(500) /* msecs */

#define NSS_IPSECMGR_DEFAULT_TUN_NAME "ipsecdummy"
#define NSS_IPSECMGR_ESP_TRAIL_SZ 2 /* esp trailer size */
#define NSS_IPSECMGR_ESP_PAD_SZ 14 /* maximum amount of padding */

struct nss_ipsecmgr_ref;
struct nss_ipsecmgr_priv;

typedef void (*nss_ipsecmgr_ref_method_t)(struct nss_ipsecmgr_ref *ref);

/*
 * nss_ipsecmgr_flow_state
 */
enum nss_ipsecmgr_flow_state {
	NSS_IPSECMGR_FLOW_STATE_INIT = 0,	/* Flow is initialized */
	NSS_IPSECMGR_FLOW_STATE_PENDING,	/* Flow is pending registration */
	NSS_IPSECMGR_FLOW_STATE_ACTIVE,		/* Flow is registered in NSS */
	NSS_IPSECMGR_FLOW_STATE_MAX
};

/*
 * IPsec manager reference object
 */
struct nss_ipsecmgr_ref {
	struct list_head head;			/* parent "ref" */
	struct list_head node;			/* child "ref" */

	uint32_t id;				/* identifier */
	struct nss_ipsecmgr_ref *parent;	/* reference to parent */

	nss_ipsecmgr_ref_method_t free;		/* free function */
};

/*
 * IPsec manager flow entry
 */
struct nss_ipsecmgr_flow_entry {
	struct list_head list;			/* List object. */
	struct nss_ipsecmgr_ref ref;		/* Reference object. */
	struct nss_ipsec_tuple tuple;		/* Associated inner flow tuple. */
	struct delayed_work retry_work;		/* Retry work */

	struct nss_ipsecmgr_flow_outer outer;	/* Associate outer flow. */

	int tunnel_id;				/* Associate IPsec tunnel */
	struct nss_ipsec_msg nim;		/* IPsec message. */
	atomic_t state;				/* Flow state */
};

/*
 * IPsec manager packets stats per SA
 */
struct nss_ipsecmgr_sa_stats_priv {
	/* Packet counters */
	uint64_t count;				/* Packets processed */
	uint64_t bytes;				/* Bytes processed */

	/* Drop counters */
	uint64_t no_headroom;			/* no headroom */
	uint64_t no_tailroom;			/* no tailroom */
	uint64_t no_buf;			/* no resource in NSS */
	uint64_t fail_queue;			/* Enqueue to nexthop failed */
	uint64_t fail_hash;			/* Hash check failed */
	uint64_t fail_replay;			/* Replay check failed */
	uint64_t fail_hash_cont;		/* Continous fail hash count */

	/* SA state */
	uint64_t seq_num;			/* Current sequence no. */
	uint64_t window_max;			/* Maximum window size supported */
	uint32_t window_size;			/* Current window size */
};

/*
 * IPsec manager SA entry
 */
struct nss_ipsecmgr_sa_entry {
	struct list_head list;			/* List node */
	struct nss_ipsecmgr_ref ref;		/* Reference node */
	struct nss_ipsec_tuple tuple;		/* SA tuple */

	struct delayed_work free_work;		/* Delayed free work */
	unsigned long free_timeout;		/* Delayed free timeout */

	struct crypto_aead *aead;		/* Linux crypto AEAD context */
	struct crypto_ahash *ahash;		/* Linux crypto AHASH context */

	struct nss_ipsecmgr_flow_outer outer;	/* Flow outer representing SA */

	struct nss_ipsec_rule_oip oip;		/* Outer IP information */
	struct nss_ipsec_rule_data data;	/* SA data */

	struct nss_ipsecmgr_priv *priv;		/* Device private */

	struct nss_ipsecmgr_sa_stats_priv stats;/* Per SA  statistics */
	struct dentry *dentry;			/* Debugfs entry per stats dir */

	enum nss_ipsec_type type;		/* ENCAP or DECAP type */
	uint32_t replay_fail_thresh;		/* Replay failure threshold */
	uint16_t if_num;			/* Associated interface number */
};

/*
 * IPsec manager private context
 */
struct nss_ipsecmgr_priv {
	struct net_device *dev;			/* back pointer to tunnel device */
	struct nss_ipsecmgr_ref ref;		/* SA objects under the tunnel */
	struct nss_ipsecmgr_callback cb;	/* Callback entry */
	struct rtnl_link_stats64 stats;		/* stats of IPsec tunnel */
};

/*
 * IPsec manager drv instance
 */
struct nss_ipsecmgr_drv {
	struct dentry *dentry;			/* Debugfs entry per ipsecmgr module. */
	struct net_device *dev;			/* IPsec dummy net device. */

	rwlock_t lock;					/* lock for all DB operations. */
	struct list_head sa_db[NSS_IPSECMGR_SA_MAX];	/* SA database. */
	struct list_head flow_db[NSS_IPSECMGR_FLOW_MAX];/* Flow database. */

	int encap_ifnum;			/* NSS encap interface. */
	int decap_ifnum;			/* NSS decap interface. */
	int data_ifnum;				/* NSS data interface. */

	struct nss_ctx_instance *nss_ctx;	/* NSS context. */
};

/*
 * nss_ipsecmgr_init_flow_db()
 *	Initialize the flow databases
 */
static inline void nss_ipsecmgr_init_flow_db(struct list_head *db)
{
	struct list_head *head = db;
	int i;

	/*
	 * initialize the flow database
	 */
	for (i = 0; i < NSS_IPSECMGR_FLOW_MAX; i++, head++)
		INIT_LIST_HEAD(head);
}

/*
 * nss_ipsecmgr_init_sa_db()
 * 	initialize the SA database
 */
static inline void nss_ipsecmgr_init_sa_db(struct list_head *db)
{
	struct list_head *head = db;
	int i;

	/*
	 * initialize the SA database
	 */
	for (i = 0; i < NSS_IPSECMGR_SA_MAX; i++, head++)
		INIT_LIST_HEAD(head);
}

/*
 * nss_ipsecmgr_tuple2index()
 * 	Change tuple to hash index
 */
static inline uint32_t nss_ipsecmgr_tuple2index(struct nss_ipsec_tuple *tuple, uint32_t max)
{
	uint32_t val = 0;

	val ^= tuple->dst_addr[0];
	val ^= tuple->src_addr[0];

	val ^= tuple->dst_addr[1];
	val ^= tuple->src_addr[1];

	val ^= tuple->dst_addr[2];
	val ^= tuple->src_addr[2];

	val ^= tuple->dst_addr[3];
	val ^= tuple->src_addr[3];

	val ^= tuple->esp_spi;

	val ^= tuple->dst_port;
	val ^= tuple->src_port;

	val ^= tuple->proto_next_hdr;
	val ^= tuple->ip_ver;

	return val & (max - 1);
}

/*
 * nss_ipsecmgr_tuple_match()
 * 	Match the tuple
 */
static inline bool nss_ipsecmgr_tuple_match(struct nss_ipsec_tuple *tuple, struct nss_ipsec_tuple *match)
{
	uint8_t status = 0;

	status += !(tuple->dst_addr[0] ^ match->dst_addr[0]);
	status += !(tuple->dst_addr[1] ^ match->dst_addr[1]);
	status += !(tuple->dst_addr[2] ^ match->dst_addr[2]);
	status += !(tuple->dst_addr[3] ^ match->dst_addr[3]);

	status += !(tuple->src_addr[0] ^ match->src_addr[0]);
	status += !(tuple->src_addr[1] ^ match->src_addr[1]);
	status += !(tuple->src_addr[2] ^ match->src_addr[2]);
	status += !(tuple->src_addr[3] ^ match->src_addr[3]);

	status += !(tuple->esp_spi ^ match->esp_spi);
	status += !(tuple->dst_port ^ match->dst_port);
	status += !(tuple->src_port ^ match->src_port);

	status += !(tuple->proto_next_hdr ^ match->proto_next_hdr);
	status += !(tuple->ip_ver ^ match->ip_ver);

	return !!status;
}

/*
 * nss_ipsecmgr_ntoh_v6addr()
 *	Network to host order and swap
 */
static inline void nss_ipsecmgr_ntoh_v6addr(uint32_t *dest, uint32_t *src)
{
	dest[3] = ntohl(src[0]);
	dest[2] = ntohl(src[1]);
	dest[1] = ntohl(src[2]);
	dest[0] = ntohl(src[3]);
}

/*
 * nss_ipsecmgr_hton_v6addr()
 *	Host to network order and swap
 */
static inline void nss_ipsecmgr_hton_v6addr(uint32_t *dest, uint32_t *src)
{
	dest[3] = htonl(src[0]);
	dest[2] = htonl(src[1]);
	dest[1] = htonl(src[2]);
	dest[0] = htonl(src[3]);
}

/* functions to operate on reference object */
extern void nss_ipsecmgr_ref_add(struct nss_ipsecmgr_ref *child, struct nss_ipsecmgr_ref *parent);
extern void nss_ipsecmgr_ref_free(struct nss_ipsecmgr_ref *ref);
extern void nss_ipsecmgr_ref_init(struct nss_ipsecmgr_ref *ref, nss_ipsecmgr_ref_method_t free);

/* functions to operate on flow object */
extern void nss_ipsecmgr_flow_inner2tuple(struct nss_ipsecmgr_flow_inner *inner, struct nss_ipsec_tuple *tuple);
extern void nss_ipsecmgr_flow_outer2tuple(struct nss_ipsecmgr_flow_outer *outer, struct nss_ipsec_tuple *tuple);
extern struct nss_ipsecmgr_flow_entry *nss_ipsecmgr_flow_lookup(struct list_head *db, struct nss_ipsec_tuple *tp);
extern nss_ipsecmgr_status_t nss_ipsecmgr_flow_alloc(struct nss_ipsecmgr_priv *priv, struct nss_ipsec_tuple *tp,
							struct nss_ipsecmgr_sa_entry *sa);

/* functions to operate on SA object */
extern struct nss_ipsecmgr_sa_entry *nss_ipsecmgr_sa_lookup(struct list_head *db, struct nss_ipsec_tuple *tp);
void nss_ipsecmgr_sa_update_stats(struct nss_ipsecmgr_sa_entry *sa, struct nss_ipsec_sa_stats *stats,
					struct nss_ipsecmgr_event *ev);
#endif
