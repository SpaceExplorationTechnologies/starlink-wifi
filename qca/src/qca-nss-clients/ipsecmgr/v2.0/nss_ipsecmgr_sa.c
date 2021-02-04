/*
 **************************************************************************
 * Copyright (c) 2016-2018, The Linux Foundation. All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTUOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 **************************************************************************
 */
#include <linux/types.h>
#include <linux/ip.h>
#include <linux/of.h>
#include <linux/ipv6.h>
#include <linux/skbuff.h>
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/rtnetlink.h>
#include <net/route.h>
#include <net/ip6_route.h>
#include <asm/atomic.h>
#include <linux/debugfs.h>
#include <linux/vmalloc.h>

#include <crypto/algapi.h>
#include <crypto/aead.h>
#include <crypto/internal/hash.h>
#include <crypto/authenc.h>

#include <nss_api_if.h>
#include <nss_ipsec.h>
#include <nss_cryptoapi.h>
#include <nss_ipsecmgr.h>
#include "nss_ipsecmgr_priv.h"

#define NSS_IPSECMGR_DEBUGFS_NAME_SZ 128 /* bytes */

extern struct nss_ipsecmgr_drv *ipsecmgr_drv;

/*
 * Linux crypto algorithm names.
 */
static const char *g_ipsec_algo_name[NSS_IPSECMGR_ALGO_MAX] = {
	"echainiv(authenc(hmac(sha1),cbc(aes)))",
	"echainiv(authenc(hmac(sha256),cbc(aes)))",
	"echainiv(authenc(hmac(sha1),cbc(des3_ede)))",
	"echainiv(authenc(hmac(sha256),cbc(des3_ede)))",
	"hmac(sha1)",
	"hmac(sha256)"
};

/*
 * nss_ipsecmgr_sa_print_stats()
 *	Print sa statistics
 */
static ssize_t nss_ipsecmgr_sa_print_stats(struct nss_ipsecmgr_sa_entry *sa, char *buf, ssize_t max_len)
{
	struct nss_ipsecmgr_sa_stats_priv *stats = &sa->stats;
	struct nss_ipsecmgr_flow_outer *outer = &sa->outer;
	struct nss_ipsec_rule_data *data = &sa->data;
	uint32_t addr[4];
	ssize_t len;
	char *type;

	switch (sa->type) {
	case NSS_IPSEC_TYPE_ENCAP:
		type = "encap";
		break;

	case NSS_IPSEC_TYPE_DECAP:
		type = "decap";
		break;

	default:
		return 0;
	}

	len = snprintf(buf, max_len, "Type:%s\n", type);

	switch (outer->ip_version) {
	case IPVERSION:
		len += snprintf(buf + len, max_len - len, "dest_ip: %pI4h\n", outer->dest_ip);
		len += snprintf(buf + len, max_len - len, "src_ip: %pI4h\n", outer->src_ip);
		break;

	case 6:
		nss_ipsecmgr_hton_v6addr(addr, outer->dest_ip);
		len += snprintf(buf + len, max_len - len, "dest_ip: %pI6c\n", addr);
		nss_ipsecmgr_hton_v6addr(addr, outer->src_ip);
		len += snprintf(buf + len, max_len - len, "src_ip: %pI6c\n", addr);

		break;
	}

	len += snprintf(buf + len, max_len - len, "spi_idx: 0x%x\n", outer->spi_index);
	len += snprintf(buf + len, max_len - len, "crypto session: %d\n", data->crypto_index);

	len += snprintf(buf + len, max_len - len, "ESN: %d\n", data->enable_esn);
	len += snprintf(buf + len, max_len - len, "seq_num: %llx\n\n", stats->seq_num);

	/*
	 * Display window information only for decap SA
	 */
	len += snprintf(buf + len, max_len - len, "win_size: %d\n", stats->window_size);
	len += snprintf(buf + len, max_len - len, "wmax: 0x%llx\n\n", stats->window_max);

	/*
	 * Packet stats
	 */
	len += snprintf(buf + len, max_len - len, "processed: %llu\n", stats->count);
	len += snprintf(buf + len, max_len - len, "no_headroom: %llu\n", stats->no_headroom);
	len += snprintf(buf + len, max_len - len, "no_tailroom: %llu\n", stats->no_tailroom);
	len += snprintf(buf + len, max_len - len, "no_buf: %llu\n", stats->no_buf);
	len += snprintf(buf + len, max_len - len, "fail_queue: %llu\n", stats->fail_queue);
	len += snprintf(buf + len, max_len - len, "fail_hash: %llu\n", stats->fail_hash);
	len += snprintf(buf + len, max_len - len, "fail_replay: %llu\n\n\n", stats->fail_replay);

	return len;
}

/*
 * nss_ipsecmgr_sa_read_stats()
 *	Read sa statistics
 */
ssize_t nss_ipsecmgr_sa_read_stats(struct file *fp, char __user *ubuf, size_t sz, loff_t *ppos)
{
	struct nss_ipsecmgr_sa_entry *sa = fp->private_data;
	ssize_t max_buf_len;
	ssize_t len = 0;
	ssize_t ret;
	char *buf;

	max_buf_len = NSS_IPSECMGR_SA_STATS_SZ;

	buf = vzalloc(max_buf_len);
	if (!buf) {
		nss_ipsecmgr_error("Unable to allocate local buffer for SA stats\n");
		return 0;
	}

	/*
	 * Walk the SA database for each entry and retrieve the stats
	 */
	len = nss_ipsecmgr_sa_print_stats(sa, buf, max_buf_len);

	ret = simple_read_from_buffer(ubuf, sz, ppos, buf, len);
	vfree(buf);

	return ret;
}

/*
 * nss_ipsecmgr_sa_update_stats()
 *	Update sa stats locally
 */
void nss_ipsecmgr_sa_update_stats(struct nss_ipsecmgr_sa_entry *sa, struct nss_ipsec_sa_stats *stats,
					struct nss_ipsecmgr_event *ev)
{
	struct nss_ipsecmgr_sa_stats_priv *priv_stats = &sa->stats;
	struct nss_ipsecmgr_sa_stats *ev_stats;

	/*
	 * DEBUG check to see if the lock is taken before accessing
	 * SA entry in the database
	 */
	BUG_ON(write_can_lock(&ipsecmgr_drv->lock));

	/*
	 * update SA specific stats
	 */
	priv_stats->count += stats->count;
	priv_stats->bytes += stats->bytes;

	priv_stats->no_headroom += stats->no_headroom;
	priv_stats->no_tailroom += stats->no_tailroom;
	priv_stats->no_buf += stats->no_resource;

	priv_stats->fail_queue += stats->fail_queue;
	priv_stats->fail_hash += stats->fail_hash;
	priv_stats->fail_replay += stats->fail_replay;

	priv_stats->seq_num = stats->seq_num;
	priv_stats->window_max = stats->window_max;
	priv_stats->window_size = stats->window_size;

	/*
	 * If, there is no event to publish then skip
	 */
	if (!ev)
		return;

	ev_stats = &ev->data.stats;

	/*
	 * copy stats and SA information
	 */
	memcpy(&ev_stats->outer, &sa->outer, sizeof(ev_stats->outer));

	ev_stats->crypto_index = sa->data.crypto_index;

	ev_stats->seq_num = stats->seq_num;
	ev_stats->esn_enabled = stats->esn_enabled;
	ev_stats->window_max = stats->window_max;
	ev_stats->window_size = stats->window_size;

	ev_stats->pkt_count = stats->count;
	ev_stats->pkt_bytes = stats->bytes;

	/*
	 * All drop counters are consolidated into
	 * failures for the IPsec user event
	 */
	ev_stats->pkt_failed = stats->no_headroom;
	ev_stats->pkt_failed += stats->no_tailroom;
	ev_stats->pkt_failed += stats->no_resource;
	ev_stats->pkt_failed += stats->fail_queue;
	ev_stats->pkt_failed += stats->fail_hash;
	ev_stats->pkt_failed += stats->fail_replay;
}

/*
 * SA file operation structure instance
 */
static const struct file_operations sa_stats_op = {
	.open = simple_open,
	.llseek = default_llseek,
	.read = nss_ipsecmgr_sa_read_stats,
};

/*
 * nss_ipsecmgr_sa_crypto_alloc()
 *	Allocate Crypto resources
 */
static nss_ipsecmgr_status_t nss_ipsecmgr_sa_crypto_alloc(struct nss_ipsecmgr_priv *priv,
							struct nss_ipsecmgr_sa_entry *sa,
							struct nss_ipsecmgr_sa_cmn *cmn)
{
	struct nss_ipsecmgr_crypto_keys *keys = &cmn->keys;
	struct crypto_authenc_key_param *key_param;
	struct rtattr *rta;
	char *rt_keys, *p;
	uint32_t index;
	uint16_t keylen;

	if (cmn->algo >= ARRAY_SIZE(g_ipsec_algo_name)) {
		nss_ipsecmgr_warn("%p: invalid crypto algorithm", sa);
		return NSS_IPSECMGR_INVALID_ALGO;
	}

	/*
	 * If, crypto is programmed using index(s) skip key-based programming
	 */
	if (!cmn->crypto_has_keys) {
		sa->aead = NULL;
		sa->data.crypto_index = cmn->index.session;
		sa->data.cipher_blk_len = cmn->index.blk_len;
		sa->data.iv_len = cmn->index.iv_len;
		return NSS_IPSECMGR_OK;
	}

	if (!keys->cipher_keylen) {

		/*
		 * AHASH Algorithms
		 */
		sa->ahash = crypto_alloc_ahash(g_ipsec_algo_name[cmn->algo], 0, 0);
		if (IS_ERR(sa->ahash)) {
			nss_ipsecmgr_warn("%p: failed to allocate crypto ahash context", sa);
			return NSS_IPSECMGR_FAIL_NOCRYPTO;
		}

		if (crypto_ahash_setkey(sa->ahash, keys->auth_key, keys->auth_keylen)) {
			nss_ipsecmgr_warn("%p: failed to configure keys", sa);
			crypto_free_ahash(sa->ahash);
			return NSS_IPSECMGR_INVALID_KEYLEN;
		}

		nss_cryptoapi_ahash_ctx2session(sa->ahash, &index);
		sa->data.crypto_index = (uint16_t)index;
		sa->data.cipher_blk_len = 0;
		sa->data.iv_len = 0;
		return NSS_IPSECMGR_OK;
	} else {

		/*
		 * AEAD Algorithms
		 */
		sa->aead = crypto_alloc_aead(g_ipsec_algo_name[cmn->algo], 0, 0);
		if (IS_ERR(sa->aead)) {
			nss_ipsecmgr_warn("%p: failed to allocate crypto aead context", sa);
			return NSS_IPSECMGR_FAIL_NOCRYPTO;
		}
	}

	nss_ipsecmgr_trace("cipher_keylen:%d auth_keylen:%d\n", keys->cipher_keylen, keys->auth_keylen);

	/*
	 * Construct keys
	 */
	keylen = RTA_SPACE(sizeof(*key_param));
	keylen += keys->cipher_keylen;
	keylen += keys->auth_keylen;
	keylen += keys->nonce_size;

	rt_keys = vzalloc(keylen);
	if (!rt_keys) {
		nss_ipsecmgr_warn("%p: failed to allocate key memory", sa);
		crypto_free_aead(sa->aead);
		return NSS_IPSECMGR_FAIL_NOMEM;
	}

	p = rt_keys;
	rta = (void *)p;
	rta->rta_type = CRYPTO_AUTHENC_KEYA_PARAM;
	rta->rta_len = RTA_LENGTH(sizeof(*key_param));
	key_param = RTA_DATA(rta);
	p += RTA_SPACE(sizeof(*key_param));

	/*
	 * Copy authentication key
	 */
	memcpy(p, keys->auth_key, keys->auth_keylen);
	p += keys->auth_keylen;

	/*
	 * Copy cipher Key
	 */
	key_param->enckeylen = cpu_to_be32(keys->cipher_keylen);
	memcpy(p, keys->cipher_key, keys->cipher_keylen);

	if (crypto_aead_setkey(sa->aead, rt_keys, keylen)) {
		nss_ipsecmgr_warn("%p: failed to configure keys", sa);
		vfree(rt_keys);
		crypto_free_aead(sa->aead);
		return NSS_IPSECMGR_INVALID_KEYLEN;
	}

	/*
	 * FIXME: ctx2session requires 32bit whereas
	 * data has 16bit crypto index. Ideally, the message
	 * structure should be updated to take this into account
	 */
	nss_cryptoapi_aead_ctx2session(sa->aead, &index);
	sa->data.crypto_index = (uint16_t)index;
	sa->data.cipher_blk_len = (uint8_t)crypto_aead_blocksize(sa->aead);
	sa->data.iv_len = (uint8_t)crypto_aead_ivsize(sa->aead);

	vfree(rt_keys);
	return 0;
}

/*
 * nss_ipsecmgr_sa_free_delayed()
 *	Free the SA entry in a delayed work context
 */
static void nss_ipsecmgr_sa_free_delayed(struct work_struct *work)
{
	struct nss_ipsecmgr_sa_entry *sa = container_of(work, struct nss_ipsecmgr_sa_entry, free_work.work);

	if (sa->aead)
		crypto_free_aead(sa->aead);

	if (sa->ahash)
		crypto_free_ahash(sa->ahash);

	kfree(sa);
}

/*
 * nss_ipsecmgr_sa_free()
 *	Detach the SA entry from the list
 */
static void nss_ipsecmgr_sa_free(struct nss_ipsecmgr_ref *ref)
{
	struct nss_ipsecmgr_sa_entry *sa = container_of(ref, struct nss_ipsecmgr_sa_entry, ref);

	BUG_ON(write_can_lock(&ipsecmgr_drv->lock));

	/*
	 * Linux does not provide any specific API(s) to test for RW locks. The caller
	 * being internal is assumed to hold write lock before intiating this.
	 */
	list_del_init(&sa->list);

	/*
	 * The free path can potentailly sleep hence we detach the SA here but
	 * free it later
	 */
	schedule_delayed_work(&sa->free_work, sa->free_timeout);
}

/*
 * nss_ipsecmgr_sa_alloc_encap()
 *	Allocate encapsulation SA
 */
static nss_ipsecmgr_status_t nss_ipsecmgr_sa_alloc_encap(struct nss_ipsecmgr_priv *priv,
							struct nss_ipsecmgr_flow_outer *outer,
							struct nss_ipsecmgr_sa *sa_data, uint32_t *if_num)
{
	char sa_name[NSS_IPSECMGR_DEBUGFS_NAME_SZ] = {0};
	struct list_head *db = ipsecmgr_drv->sa_db;
	struct nss_ipsecmgr_sa_entry *sa;
	struct nss_ipsec_rule_data *data;
	struct nss_ipsec_rule_oip *oip;
	struct nss_ipsec_tuple tuple = {0};
	uint32_t index;

	nss_ipsecmgr_flow_outer2tuple(outer, &tuple);

	/*
	 * Read lock is sufficient here since we are looking up SA DB
	 */
	read_lock_bh(&ipsecmgr_drv->lock);

	/*
	 * Check if the SA already exists or not
	 */
	if (nss_ipsecmgr_sa_lookup(db, &tuple)) {
		read_unlock_bh(&ipsecmgr_drv->lock);
		return NSS_IPSECMGR_DUPLICATE_SA;
	}

	read_unlock_bh(&ipsecmgr_drv->lock);


	/*
	 * Allocate the SA entry
	 */
	sa = kzalloc(sizeof(*sa), in_atomic() ? GFP_ATOMIC : GFP_KERNEL);
	if (!sa)
		return NSS_IPSECMGR_FAIL_NOMEM;

	/*
	 * Allocate crypto resources
	 */
	if (nss_ipsecmgr_sa_crypto_alloc(priv, sa, &sa_data->cmn)) {
		kfree(sa);
		return NSS_IPSECMGR_FAIL_NOCRYPTO;
	}

	sa->priv = priv;
	sa->type = NSS_IPSEC_TYPE_ENCAP;
	*if_num = sa->if_num = ipsecmgr_drv->encap_ifnum;
	sa->free_timeout = NSS_IPSECMGR_SA_FREE_TIMEOUT;

	/*
	 * Fill the data
	 */
	data = &sa->data;
	data->esp_icv_len = sa_data->cmn.icv_len;
	data->esp_tail_skip = sa_data->cmn.skip_trailer;
	data->enable_esn = sa_data->cmn.enable_esn;
	data->nat_t_req = sa_data->cmn.enable_natt;

	/*
	 * Fill encapsulation specific data
	 */
	data->dscp = sa_data->encap.dscp;
	data->df = sa_data->encap.df;
	data->copy_dscp = sa_data->encap.copy_dscp;
	data->copy_df = sa_data->encap.copy_df;

	memcpy(&sa->tuple, &tuple, sizeof(sa->tuple));
	memcpy(&sa->outer, outer, sizeof(sa->outer));

	/*
	 * Fill outer IP related information
	 */
	oip = &sa->oip;
	oip->esp_spi = outer->spi_index;
	oip->ip_ver = outer->ip_version;
	oip->ttl_hop_limit = sa_data->encap.ttl_hop_limit;
	memcpy(&oip->dst_addr, outer->dest_ip, sizeof(oip->dst_addr));
	memcpy(&oip->src_addr, outer->src_ip, sizeof(oip->src_addr));

	INIT_LIST_HEAD(&sa->list);
	nss_ipsecmgr_ref_init(&sa->ref, nss_ipsecmgr_sa_free);
	INIT_DELAYED_WORK(&sa->free_work, nss_ipsecmgr_sa_free_delayed);

	/*
	 * Find the index to save the SA entry
	 */
	index = nss_ipsecmgr_tuple2index(&tuple, NSS_IPSECMGR_SA_MAX);

	/*
	 * Adding sa debugfs entry
	 */
	scnprintf(sa_name, sizeof(sa_name), "sa@spi:%x", oip->esp_spi);
	sa->dentry = debugfs_create_dir(sa_name, ipsecmgr_drv->dentry);
	if (sa->dentry)
		debugfs_create_file("stats", S_IRUGO, sa->dentry, sa, &sa_stats_op);

	write_lock_bh(&ipsecmgr_drv->lock);

	/*
	 * Add SA reference to the tunnel
	 */
	nss_ipsecmgr_ref_add(&sa->ref, &priv->ref);
	list_add(&sa->list, &db[index]);

	write_unlock_bh(&ipsecmgr_drv->lock);

	nss_ipsecmgr_trace("%p:encap SA added", sa);
	return NSS_IPSECMGR_OK;
}

/*
 * nss_ipsecmgr_sa_alloc_decap()
 *	Allocate decapsulation SA
 */
static nss_ipsecmgr_status_t nss_ipsecmgr_sa_alloc_decap(struct nss_ipsecmgr_priv *priv,
							struct nss_ipsecmgr_flow_outer *outer,
							struct nss_ipsecmgr_sa *sa_data, uint32_t *if_num)
{
	char sa_name[NSS_IPSECMGR_DEBUGFS_NAME_SZ] = {0};
	struct list_head *db = ipsecmgr_drv->sa_db;
	struct nss_ipsecmgr_sa_entry *sa;
	struct nss_ipsec_rule_data *data;
	struct nss_ipsec_rule_oip *oip;
	struct nss_ipsec_tuple tuple = {0};
	nss_ipsecmgr_status_t status;
	uint32_t index;

	nss_ipsecmgr_flow_outer2tuple(outer, &tuple);

	read_lock_bh(&ipsecmgr_drv->lock);

	/*
	 * Check if the SA already exists or not
	 */
	if (nss_ipsecmgr_sa_lookup(db, &tuple)) {
		read_unlock_bh(&ipsecmgr_drv->lock);
		return NSS_IPSECMGR_DUPLICATE_SA;
	}

	read_unlock_bh(&ipsecmgr_drv->lock);

	/*
	 * Allocate the SA entry
	 */
	sa = kzalloc(sizeof(*sa), in_atomic() ? GFP_ATOMIC : GFP_KERNEL);
	if (!sa)
		return NSS_IPSECMGR_FAIL_NOMEM;

	/*
	 * Allocate crypto resources
	 */
	if (nss_ipsecmgr_sa_crypto_alloc(priv, sa, &sa_data->cmn)) {
		kfree(sa);
		return NSS_IPSECMGR_FAIL_NOCRYPTO;
	}

	sa->priv = priv;
	sa->type = NSS_IPSEC_TYPE_DECAP;
	*if_num = sa->if_num = ipsecmgr_drv->decap_ifnum;
	sa->free_timeout = NSS_IPSECMGR_SA_FREE_TIMEOUT;

	memcpy(&sa->tuple, &tuple, sizeof(sa->tuple));
	memcpy(&sa->outer, outer, sizeof(sa->outer));

	/*
	 * Fill the data
	 */
	data = &sa->data;
	data->esp_icv_len = sa_data->cmn.icv_len;
	data->esp_tail_skip = sa_data->cmn.skip_trailer;
	data->enable_esn = sa_data->cmn.enable_esn;
	data->nat_t_req = sa_data->cmn.enable_natt;

	/*
	 * Fill decapsulation specific data
	 */
	data->window_size = sa_data->decap.replay_win;
	sa->replay_fail_thresh = sa_data->decap.replay_fail_thresh;

	/*
	 * Fill outer IP related information
	 */
	oip = &sa->oip;
	memcpy(&oip->dst_addr, outer->dest_ip, sizeof(oip->dst_addr));
	memcpy(&oip->src_addr, outer->src_ip, sizeof(oip->src_addr));
	oip->esp_spi = outer->spi_index;
	oip->ip_ver = outer->ip_version;
	oip->ttl_hop_limit = 0;

	INIT_LIST_HEAD(&sa->list);
	nss_ipsecmgr_ref_init(&sa->ref, nss_ipsecmgr_sa_free);
	INIT_DELAYED_WORK(&sa->free_work, nss_ipsecmgr_sa_free_delayed);

	/*
	 * Find the index to save the SA entry
	 */
	index = nss_ipsecmgr_tuple2index(&tuple, NSS_IPSECMGR_SA_MAX);

	/*
	 * Adding sa debugfs entry
	 */
	scnprintf(sa_name, sizeof(sa_name), "sa@spi:%x", oip->esp_spi);
	sa->dentry = debugfs_create_dir(sa_name, ipsecmgr_drv->dentry);
	if (sa->dentry)
		debugfs_create_file("stats", S_IRUGO, sa->dentry, sa, &sa_stats_op);

	/*
	 * Write lock needed here since SA is updated
	 */
	write_lock_bh(&ipsecmgr_drv->lock);

	nss_ipsecmgr_ref_add(&sa->ref, &priv->ref);
	list_add(&sa->list, &db[index]);

	write_unlock_bh(&ipsecmgr_drv->lock);

	nss_ipsecmgr_trace("%p:decap SA added", sa);
	return status;
}

/*
 * nss_ipsecmgr_sa_lookup()
 *	Find an SA using the tuple information
 */
struct nss_ipsecmgr_sa_entry *nss_ipsecmgr_sa_lookup(struct list_head *db, struct nss_ipsec_tuple *tuple)
{
	uint32_t index = nss_ipsecmgr_tuple2index(tuple, NSS_IPSECMGR_SA_MAX);
	struct list_head *head = &db[index];
	struct nss_ipsecmgr_sa_entry *sa;

	/*
	 * Linux does not provide any specific API(s) to test for RW locks. The caller
	 * being internal is assumed to hold write lock before intiating this.
	 */
	list_for_each_entry(sa, head, list) {
		if (nss_ipsecmgr_tuple_match(&sa->tuple, tuple))
			return sa;
	}

	return NULL;
}

/*
 * nss_ipsecmgr_sa_del()
 *	Delete an existing SA
 */
void nss_ipsecmgr_sa_del(struct net_device *tun, struct nss_ipsecmgr_flow_outer *outer)
{
	struct nss_ipsecmgr_priv *priv __attribute__((unused)) = netdev_priv(tun);
	struct list_head *db = ipsecmgr_drv->sa_db;
	struct nss_ipsecmgr_sa_entry *sa;
	struct nss_ipsec_tuple tuple = {0};

	nss_ipsecmgr_flow_outer2tuple(outer, &tuple);

	/*
	 * Write lock needed here since SA and all related Flows
	 * are removed from DB. This requires write lock since SA Delete
	 * might be called in parallel from other cores as well
	 */
	write_lock_bh(&ipsecmgr_drv->lock);

	/*
	 * Find the SA entry to free
	 */
	sa = nss_ipsecmgr_sa_lookup(db, &tuple);
	if (!sa) {
		write_unlock_bh(&ipsecmgr_drv->lock);
		return;
	}

	/*
	 * Remove debugfs entry
	 */
	if (sa->dentry)
		debugfs_remove_recursive(sa->dentry);

	/*
	 * Free the entire reference hierarchy
	 */
	nss_ipsecmgr_ref_free(&sa->ref);

	write_unlock_bh(&ipsecmgr_drv->lock);
}
EXPORT_SYMBOL(nss_ipsecmgr_sa_del);

/*
 * nss_ipsecmgr_sa_add()
 *	Add a new SA for encapsulation or decapsulation
 */
nss_ipsecmgr_status_t nss_ipsecmgr_sa_add(struct net_device *tun, struct nss_ipsecmgr_flow_outer *outer,
					struct nss_ipsecmgr_sa *sa_data, uint32_t *if_num)
{
	struct nss_ipsecmgr_priv *priv = netdev_priv(tun);

	switch (sa_data->type) {
	case NSS_IPSECMGR_SA_TYPE_ENCAP:
		return nss_ipsecmgr_sa_alloc_encap(priv, outer, sa_data, if_num);

	case NSS_IPSECMGR_SA_TYPE_DECAP:
		return nss_ipsecmgr_sa_alloc_decap(priv, outer, sa_data, if_num);

	default:
		nss_ipsecmgr_warn("%p:Unsupported SA type(%u)", tun, sa_data->type);
		return NSS_IPSECMGR_FAIL;
	}
}
EXPORT_SYMBOL(nss_ipsecmgr_sa_add);
