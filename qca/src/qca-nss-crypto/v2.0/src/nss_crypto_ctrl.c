/*
 * Copyright (c) 2017-2018, The Linux Foundation. All rights reserved.
 *
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
 */
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/memory.h>
#include <linux/io.h>
#include <linux/clk.h>
#include <linux/uaccess.h>
#include <linux/dma-mapping.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_net.h>
#include <linux/of_irq.h>
#include <linux/of_platform.h>
#include <linux/of_address.h>
#include <linux/reset.h>
#include <linux/bitmap.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/vmalloc.h>
#include <linux/debugfs.h>
#include <linux/log2.h>
#include <linux/completion.h>
#include <crypto/sha.h>
#include <crypto/des.h>
#include <crypto/aes.h>
#include <crypto/md5.h>
#include <crypto/ghash.h>
#include <engines/nss_crypto_engine.h>
#include <nss_crypto_hlos.h>
#include <nss_api_if.h>
#include <nss_crypto_api.h>
#include <nss_crypto_hdr.h>
#include <nss_crypto_ctrl.h>
#include <nss_crypto_cmn.h>
#include <nss_crypto_debugfs.h>

struct nss_crypto_ctrl g_control = { {0} };

#define NSS_CRYPTO_TX_RETRY_TICKS msecs_to_jiffies(100/* msecs */)
#define NSS_CRYPTO_DELAYED_INIT_TICKS msecs_to_jiffies(100/* msecs */)

/*
 * Standard initialization vector for SHA-1, source: FIPS 180-2
 */
static uint32_t fips_std_sha1_iv[SHA1_DIGEST_SIZE / sizeof(uint32_t)] = {
	SHA1_H0, SHA1_H1,
	SHA1_H2, SHA1_H3,
	SHA1_H4
};

/*
 * Standard initialization vector for SHA-224, source: FIPS 180-2
 */
static uint32_t fips_std_sha224_iv[SHA256_DIGEST_SIZE / sizeof(uint32_t)] = {
	SHA224_H0, SHA224_H1,
	SHA224_H2, SHA224_H3,
	SHA224_H4, SHA224_H5,
	SHA224_H6, SHA224_H7
};

/*
 * Standard initialization vector for SHA-256, source: FIPS 180-2
 */
static uint32_t fips_std_sha256_iv[SHA256_DIGEST_SIZE / sizeof(uint32_t)] = {
	SHA256_H0, SHA256_H1,
	SHA256_H2, SHA256_H3,
	SHA256_H4, SHA256_H5,
	SHA256_H6, SHA256_H7
};

/*
 * g_algo_info
 *	global structure for algorithm specific information
 */
static struct nss_crypto_algo_info g_algo_info[NSS_CRYPTO_CMN_ALGO_MAX] = {
	[NSS_CRYPTO_CMN_ALGO_NULL] = {
		.name = "qcom,NULL",
		.cipher_valid = false,
		.auth_valid = false,
	},
	[NSS_CRYPTO_CMN_ALGO_3DES_CBC] = {
		.name = "qcom,3des-cbc",
		.cipher_key_len = DES3_EDE_KEY_SIZE,
		.cipher_blk_len = DES3_EDE_BLOCK_SIZE,
		.iv_len = DES3_EDE_BLOCK_SIZE,
		.cipher_valid = true,
		.auth_valid = false,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_CBC] = {
		.name = "qcom,aes128-cbc",
		.cipher_key_len = AES_KEYSIZE_128,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.cipher_valid = true,
		.auth_valid = false,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_CTR] = {
		.name = "qcom,aes128-ctr",
		.cipher_key_len = AES_KEYSIZE_128,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.cipher_valid = true,
		.auth_valid = false,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_ECB] = {
		.name = "qcom,aes128-ecb",
		.cipher_key_len = AES_KEYSIZE_128,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.cipher_valid = true,
		.auth_valid = false,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_CBC] = {
		.name = "qcom,aes192-cbc",
		.cipher_key_len = AES_KEYSIZE_192,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.cipher_valid = true,
		.auth_valid = false,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_CTR] = {
		.name = "qcom,aes192-ctr",
		.cipher_key_len = AES_KEYSIZE_192,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.cipher_valid = true,
		.auth_valid = false,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_ECB] = {
		.name = "qcom,aes192-ecb",
		.cipher_key_len = AES_KEYSIZE_192,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.cipher_valid = true,
		.auth_valid = false,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_CBC] = {
		.name = "qcom,aes256-cbc",
		.cipher_key_len = AES_KEYSIZE_256,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.cipher_valid = true,
		.auth_valid = false,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_CTR] = {
		.name = "qcom,aes256-ctr",
		.cipher_key_len = AES_KEYSIZE_256,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.cipher_valid = true,
		.auth_valid = false,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_ECB] = {
		.name = "qcom,aes256-ecb",
		.cipher_key_len = AES_KEYSIZE_256,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.cipher_valid = true,
		.auth_valid = false,
	},
	[NSS_CRYPTO_CMN_ALGO_SHA160_HASH] = {
		.name = "qcom,sha160-hash",
		.digest_sz = SHA1_DIGEST_SIZE,
		.auth_blk_len = SHA1_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha1_iv,
		.cipher_valid = false,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_SHA224_HASH] = {
		.name = "qcom,sha224-hash",
		.digest_sz = SHA224_DIGEST_SIZE,
		.auth_blk_len = SHA224_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha224_iv,
		.cipher_valid = false,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_SHA256_HASH] = {
		.name = "qcom,sha256-hash",
		.digest_sz = SHA256_DIGEST_SIZE,
		.auth_blk_len = SHA256_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha256_iv,
		.cipher_valid = false,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_SHA160_HMAC] = {
		.name = "qcom,sha160-hmac",
		.auth_key_len = SHA1_DIGEST_SIZE,
		.digest_sz = SHA1_DIGEST_SIZE,
		.auth_blk_len = SHA1_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha1_iv,
		.cipher_valid = false,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_SHA256_HMAC] = {
		.name = "qcom,sha256-hmac",
		.auth_key_len = SHA256_DIGEST_SIZE,
		.digest_sz = SHA256_DIGEST_SIZE,
		.auth_blk_len = SHA256_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha256_iv,
		.cipher_valid = false,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_CBC_SHA160_HMAC] = {
		.name = "qcom,aes128-cbc-sha160-hmac",
		.cipher_key_len = AES_KEYSIZE_128,
		.auth_key_len = SHA1_DIGEST_SIZE,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.digest_sz = SHA1_DIGEST_SIZE,
		.auth_blk_len = SHA1_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha1_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_CBC_SHA256_HMAC] = {
		.name = "qcom,aes128-cbc-sha256-hmac",
		.cipher_key_len = AES_KEYSIZE_128,
		.auth_key_len = SHA256_DIGEST_SIZE,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.digest_sz = SHA256_DIGEST_SIZE,
		.auth_blk_len = SHA256_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha256_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_CTR_SHA160_HMAC] = {
		.name = "qcom,aes128-ctr-sha160-hmac",
		.cipher_key_len = AES_KEYSIZE_128,
		.auth_key_len = SHA1_DIGEST_SIZE,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.digest_sz = SHA1_DIGEST_SIZE,
		.auth_blk_len = SHA1_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha1_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_CTR_SHA256_HMAC] = {
		.name = "qcom,aes128-ctr-sha256-hmac",
		.cipher_key_len = AES_KEYSIZE_128,
		.auth_key_len = SHA256_DIGEST_SIZE,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.digest_sz = SHA256_DIGEST_SIZE,
		.auth_blk_len = SHA256_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha256_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_CBC_SHA160_HMAC] = {
		.name = "qcom,aes192-cbc-sha160-hmac",
		.cipher_key_len = AES_KEYSIZE_192,
		.auth_key_len = SHA1_DIGEST_SIZE,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.digest_sz = SHA1_DIGEST_SIZE,
		.auth_blk_len = SHA1_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha1_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_CBC_SHA256_HMAC] = {
		.name = "qcom,aes192-cbc-sha256-hmac",
		.cipher_key_len = AES_KEYSIZE_192,
		.auth_key_len = SHA256_DIGEST_SIZE,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.digest_sz = SHA256_DIGEST_SIZE,
		.auth_blk_len = SHA256_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha256_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_CTR_SHA160_HMAC] = {
		.name = "qcom,aes192-ctr-sha160-hmac",
		.cipher_key_len = AES_KEYSIZE_192,
		.auth_key_len = SHA1_DIGEST_SIZE,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.digest_sz = SHA1_DIGEST_SIZE,
		.auth_blk_len = SHA1_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha1_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_CTR_SHA256_HMAC] = {
		.name = "qcom,aes192-ctr-sha256-hmac",
		.cipher_key_len = AES_KEYSIZE_192,
		.auth_key_len = SHA256_DIGEST_SIZE,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.digest_sz = SHA256_DIGEST_SIZE,
		.auth_blk_len = SHA256_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha256_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_CBC_SHA160_HMAC] = {
		.name = "qcom,aes256-cbc-sha160-hmac",
		.cipher_key_len = AES_KEYSIZE_256,
		.auth_key_len = SHA1_DIGEST_SIZE,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.digest_sz = SHA1_DIGEST_SIZE,
		.auth_blk_len = SHA1_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha1_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_CBC_SHA256_HMAC] = {
		.name = "qcom,aes256-cbc-sha256-hmac",
		.cipher_key_len = AES_KEYSIZE_256,
		.auth_key_len = SHA256_DIGEST_SIZE,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.digest_sz = SHA256_DIGEST_SIZE,
		.auth_blk_len = SHA256_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha256_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_CTR_SHA160_HMAC] = {
		.name = "qcom,aes256-ctr-sha160-hmac",
		.cipher_key_len = AES_KEYSIZE_256,
		.auth_key_len = SHA1_DIGEST_SIZE,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.digest_sz = SHA1_DIGEST_SIZE,
		.auth_blk_len = SHA1_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha1_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_CTR_SHA256_HMAC] = {
		.name = "qcom,aes256-ctr-sha256-hmac",
		.cipher_key_len = AES_KEYSIZE_256,
		.auth_key_len = SHA256_DIGEST_SIZE,
		.cipher_blk_len = AES_BLOCK_SIZE,
		.iv_len = AES_BLOCK_SIZE,
		.digest_sz = SHA256_DIGEST_SIZE,
		.auth_blk_len = SHA256_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha256_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_3DES_CBC_SHA160_HMAC] = {
		.name = "qcom,3des-cbc-sha160-hmac",
		.cipher_key_len = DES3_EDE_KEY_SIZE,
		.auth_key_len = SHA1_DIGEST_SIZE,
		.cipher_blk_len = DES3_EDE_BLOCK_SIZE,
		.iv_len = DES3_EDE_BLOCK_SIZE,
		.digest_sz = SHA1_DIGEST_SIZE,
		.auth_blk_len = SHA1_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha1_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
	[NSS_CRYPTO_CMN_ALGO_3DES_CBC_SHA256_HMAC] = {
		.name = "qcom,3des-cbc-sha256-hmac",
		.cipher_key_len = DES3_EDE_KEY_SIZE,
		.auth_key_len = SHA256_DIGEST_SIZE,
		.cipher_blk_len = DES3_EDE_BLOCK_SIZE,
		.iv_len = DES3_EDE_BLOCK_SIZE,
		.digest_sz = SHA256_DIGEST_SIZE,
		.auth_blk_len = SHA256_BLOCK_SIZE,
		.auth_fips_iv = fips_std_sha256_iv,
		.cipher_valid = true,
		.auth_valid = true,
	},
};

/*
 * nss_crypto_ctrl_stats_init
 *	Initialize control stats in crypto control
 */
static void nss_crypto_ctrl_stats_init(struct nss_crypto_ctrl_stats *stats)
{
	atomic_set(&stats->alloc, 0);
	atomic_set(&stats->alloc_fail_node, 0);
	atomic_set(&stats->alloc_fail_nomem, 0);
	atomic_set(&stats->alloc_fail_nospace, 0);
	atomic_set(&stats->alloc_fail_noalgo, 0);
	atomic_set(&stats->alloc_fail_noresp, 0);
	atomic_set(&stats->free, 0);
	atomic_set(&stats->free_fail_msg, 0);
	atomic_set(&stats->free_fail_inuse, 0);
	atomic_set(&stats->free_fail_queue, 0);
	atomic_set(&stats->free_fail_retry, 0);
}

/*
 * nss_crypto_get_cipher_block_len()
 *	Return the cipher block len associated with the index
 */
uint16_t nss_crypto_get_cipher_block_len(uint32_t session)
{
	struct nss_crypto_ctrl *ctrl = &g_control;
	uint16_t idx = NSS_CRYPTO_SESSION_INDEX(session, ctrl->max_contexts);
	struct nss_crypto_ctx *ctx;
	uint16_t blk_len;

	ctx = &ctrl->ctx_tbl[idx];
	if (!kref_get_unless_zero(&ctx->ref))
		return 0;

	blk_len = ctx->info->cipher_blk_len;
	kref_put(&ctx->ref, nss_crypto_ctx_free);
	return blk_len;
}
EXPORT_SYMBOL(nss_crypto_get_cipher_block_len);

/*
 * nss_crypto_get_iv_len()
 *     Return the iv associated with the index
 */
uint16_t nss_crypto_get_iv_len(uint32_t session)
{
	struct nss_crypto_ctrl *ctrl = &g_control;
	uint16_t idx = NSS_CRYPTO_SESSION_INDEX(session, ctrl->max_contexts);
	struct nss_crypto_ctx *ctx;
	uint16_t iv_len;

	ctx = &ctrl->ctx_tbl[idx];
	if (!kref_get_unless_zero(&ctx->ref))
		return 0;

	iv_len = ctx->info->iv_len;
	kref_put(&ctx->ref, nss_crypto_ctx_free);
	return iv_len;
}
EXPORT_SYMBOL(nss_crypto_get_iv_len);

/*
 * nss_crypto_ctx_free()
 *	put the reference down for the context
 *
 * Note: this will schedule the delayed free
 */
void nss_crypto_ctx_free(struct kref *ref)
{
	struct nss_crypto_ctrl *ctrl = &g_control;
	atomic_inc(&ctrl->cstats.free);
}
EXPORT_SYMBOL(nss_crypto_ctx_free);

/*
 * nss_crypto_process_event()
 *	process incoming messages
 */
void nss_crypto_process_event(void *app_data, struct nss_crypto_cmn_msg *nim)
{
	struct nss_crypto_ctrl *ctrl = &g_control;
	struct nss_crypto_cmn_stats *stats;
	struct nss_crypto_node *node;
	struct nss_crypto_ctx *ctx;
	bool process = false;
	uint16_t idx;

	stats = &nim->msg.stats;

	/*
	 * find the node associated with message
	 */
	list_for_each_entry(node, &ctrl->node_head, list) {
		if (node->nss_ifnum == nim->cm.interface) {
			process = true;
			break;
		}
	}

	/*
	 * check if we need to process the message
	 */
	if (!process)
		return;

	switch (nim->cm.type) {
	case NSS_CRYPTO_CMN_MSG_TYPE_SYNC_NODE_STATS:
		memcpy(&node->stats, stats, sizeof(node->stats));
		break;

	case NSS_CRYPTO_CMN_MSG_TYPE_SYNC_CTX_STATS:
		idx = NSS_CRYPTO_SESSION_INDEX(nim->uid, ctrl->max_contexts);

		ctx = &ctrl->ctx_tbl[idx];
		if (!kref_get_unless_zero(&ctx->ref))
			break;

		memcpy(&ctx->stats, stats, sizeof(ctx->stats));
		kref_put(&ctx->ref, nss_crypto_ctx_free);
		break;

	default:
		nss_crypto_warn("%p: unsupported message (%d), uid (%d)\n", node, nim->cm.type, nim->uid);
		break;
	}
}

/*
 * nss_crypto_delayed_free()
 *	delayed free worker for freeing up context later
 *
 * Note: The expectation is that if the context is in use
 * then it cannot be freed immediately at host and NSS.
 * We should wait in a delayed thread context to attempt
 * freeing at NSS first followed by host. It is also
 * possible that the host to NSS queue is busy in which
 * case we need to retry.
 */
void nss_crypto_delayed_free(struct work_struct *work)
{
	struct nss_crypto_ctrl *ctrl = &g_control;
	struct nss_crypto_ctx *ctx;
	int32_t status;

	ctx = container_of(to_delayed_work(work), struct nss_crypto_ctx, free_work);

	/*
	 * If, the NSS queue is congested then try few more times to see
	 * if the message goes through. Otherwise the index will remain
	 * in use and will not be allocated to any other user
	 */
	status = nss_crypto_cmn_tx_msg_sync(ctrl->nss_msg_hdl, &ctx->nim);
	switch (status) {
	case NSS_TX_SUCCESS:
		break;

	case NSS_TX_FAILURE_QUEUE:
		schedule_delayed_work(&ctx->free_work, NSS_CRYPTO_TX_RETRY_TICKS);
		return;

	default:
		BUG_ON(1);
	}

	/*
	 * Check if the NSS is successful in deleting the context; otherwise
	 * retry after sometime to see if the context can be released. This
	 * will happen if the NSS crypto context has outstanding packets
	 */
	if (ctx->nim.cm.response != NSS_CMN_RESPONSE_ACK) {
		atomic_inc(&ctrl->cstats.free_fail_retry);
		ctx->nim.cm.type = NSS_CRYPTO_CMN_MSG_TYPE_VERIFY_CTX;
		schedule_delayed_work(&ctx->free_work, ctx->free_timeout);
		return;
	}

	if (ctx->dentry)
		debugfs_remove_recursive(ctx->dentry);

	kref_put(&ctx->ref, nss_crypto_ctx_free);
}

/*
 * nss_crypto_session_alloc()
 *	allocate the session index and fill other context related information
 */
int nss_crypto_session_alloc(struct nss_crypto_user *user, struct nss_crypto_session_data *data,
				uint32_t *session)
{
	enum nss_crypto_cmn_msg_type type = NSS_CRYPTO_CMN_MSG_TYPE_SETUP_CTX;
	struct nss_crypto_ctrl *ctrl = &g_control;
	struct nss_crypto_cmn_msg nim = { {0} };
	struct nss_crypto_cmn_ctx *msg = &nim.msg.ctx;
	struct nss_crypto_node *node;
	struct nss_crypto_ctx *ctx;
	nss_tx_status_t status;
	void __iomem *hw_ctx;
	void __iomem *vaddr;
	bool found = false;
	size_t ctx_sz;
	uint16_t idx;
	int error;

	BUG_ON(in_atomic());

	if (data->algo > NSS_CRYPTO_CMN_ALGO_MAX) {
		nss_crypto_warn("%p: invalid configuration (algo - %d)\n", user, data->algo);
		atomic_inc(&ctrl->cstats.alloc_fail_noalgo);
		return -ERANGE;
	}

	/*
	 * this only allows one outstanding session_alloc
	 * to run on any core
	 */
	mutex_lock(&ctrl->mutex); /* lock*/
	for (idx = 0, ctx = ctrl->ctx_tbl; idx < ctrl->max_contexts; idx++, ctx++) {
		/*
		 * To check whether the context is available, we would
		 * acquire the reference to see whether the context is
		 * already in use or not. In case, it is not in use
		 * kref_init would acquire the reference thus holding it
		 * for the current session
		 */
		if (!kref_get_unless_zero(&ctx->ref)) {
			memset(ctx, 0, sizeof(*ctx));
			ctx->idx = idx;
			kref_init(&ctx->ref);
			break;
		}

		kref_put(&ctx->ref, nss_crypto_ctx_free);
	}

	mutex_unlock(&ctrl->mutex); /* unlock */

	/*
	 * if there is nothing available indicate it to the caller
	 */
	if (idx == ctrl->max_contexts) {
		atomic_inc(&ctrl->cstats.alloc_fail_nospace);
		return -ENOSPC;
	}

	/*
	 * Walk through each node and call node specific context fill routine
	 */
	list_for_each_entry(node, &ctrl->node_head, list) {
		/*
		 * check if the node supports requested algorithm;
		 * if the current node does not support the requested
		 * algorithm then try the next one. It is desired that
		 * only one of the nodes will be capable of handling a
		 * particular algorithm
		 */
		if (node->algo[data->algo]) {
			found = true;
			break;
		}
	}

	if (!found) {
		atomic_inc(&ctrl->cstats.alloc_fail_noalgo);
		return -ENOENT;
	}

	/*
	 * We will allocate memory of ctx_words size and pass it to
	 * engine specific context fill api to fill cipher keys and
	 * auth keys. Once the message is communicated to NSS FW,
	 * we will unmap and free the memory allocated.
	 */
	ctx_sz = ctrl->max_ctx_size * sizeof(uint32_t);
	vaddr = kzalloc(ctx_sz + SMP_CACHE_BYTES, GFP_KERNEL);
	if (!vaddr) {
		nss_crypto_warn("%p: unable to allocate HW context(%zu)\n", user, ctx_sz);
		atomic_inc(&ctrl->cstats.alloc_fail_nomem);
		kref_put(&ctx->ref, nss_crypto_ctx_free);
		return -ENOMEM;
	}

	/*
	 * Fill common information for context
	 */
	ctx->info = &g_algo_info[data->algo];
	ctx->node = node;
	ctx->algo = data->algo;
	ctx->nss_ifnum = node->nss_ifnum;

	/*
	 * We need to make sure that NSS gets the address
	 * aligned to cache line boundary
	 */
	hw_ctx = PTR_ALIGN(vaddr, SMP_CACHE_BYTES);

	/*
	 * Fill Hardware specific information
	 */
	error = node->fill_ctx(ctx, data, msg, hw_ctx);
	if (error < 0) {
		atomic_inc(&ctrl->cstats.alloc_fail_node);
		kref_put(&ctx->ref, nss_crypto_ctx_free);
		kfree(vaddr);
		return error;
	}

	/*
	 * Fill other fields of context message
	 */
	msg->index = idx;
	msg->addr = (uint32_t)dma_map_single(node->dev, hw_ctx, ctx_sz, DMA_TO_DEVICE);
	msg->algo = data->algo;

	if (data->sec_key) {
		msg->sec_offset = data->sec_key_offset;
		msg->flags |= NSS_CRYPTO_CMN_CTX_FLAGS_SEC_OFFSET;
	}

	/*
	 * Prepare a sync message
	 */
	nss_cmn_msg_init(&nim.cm, node->nss_ifnum, type, sizeof(nim) - sizeof(nim.cm), NULL, ctx);

	/*
	 * context alloc is a synchronous call which will
	 * query the NSS and see if the context can be
	 * allocated or not
	 */
	status = nss_crypto_cmn_tx_msg_sync(ctrl->nss_msg_hdl, &nim);
	if (status != NSS_TX_SUCCESS) {
		nss_crypto_warn("%p: unable to send(%d), status(%d), response(%d), error(%d)\n",
				ctx, nim.cm.type, status, nim.cm.response, nim.cm.error);
		atomic_inc(&ctrl->cstats.alloc_fail_noresp);
		kref_put(&ctx->ref, nss_crypto_ctx_free);
		dma_unmap_single(node->dev, msg->addr, ctx_sz, DMA_FROM_DEVICE);
		kfree(vaddr);
		return -EBUSY;
	}

	dma_unmap_single(node->dev, msg->addr, ctx_sz, DMA_FROM_DEVICE);
	kfree(vaddr);

	/*
	 * Initialize the delayed free
	 */
	ctx->free_timeout = user->ctx.timeout_ticks;
	INIT_DELAYED_WORK(&ctx->free_work, nss_crypto_delayed_free);

	/*
	 * create context debugfs entry
	 */
	nss_crypto_debugfs_add_ctx(ctx, node->dentry);

	atomic_inc(&ctrl->cstats.alloc);

	*session = idx;
	return 0;
}
EXPORT_SYMBOL(nss_crypto_session_alloc);

/*
 * nss_crypto_session_free()
 *	free the crypto session, that was previously allocated
 */
void nss_crypto_session_free(struct nss_crypto_user *user, uint32_t session)
{
	enum nss_crypto_cmn_msg_type type = NSS_CRYPTO_CMN_MSG_TYPE_CLEAR_CTX;
	struct nss_crypto_ctrl *ctrl = &g_control;
	uint16_t idx = NSS_CRYPTO_SESSION_INDEX(session, ctrl->max_contexts);
	struct nss_crypto_ctx *ctx;

	mutex_lock(&ctrl->mutex);

	ctx = &ctrl->ctx_tbl[idx];
	if (!kref_get_unless_zero(&ctx->ref)) {
		mutex_unlock(&ctrl->mutex);
		atomic_inc(&ctrl->cstats.free_fail_inuse);	/**< Sessions freed queue congested */
		nss_crypto_warn("%p: session id(%d) not in use\n", user, idx);
		return;
	}

	kref_put(&ctx->ref, nss_crypto_ctx_free);
	mutex_unlock(&ctrl->mutex);

	nss_cmn_msg_init(&ctx->nim.cm, ctx->nss_ifnum, type, sizeof(ctx->nim) - sizeof(ctx->nim.cm), NULL, ctx);
	ctx->nim.msg.ctx.index = idx;

	schedule_delayed_work(&ctx->free_work, NSS_CRYPTO_DELAYED_INIT_TICKS);
}
EXPORT_SYMBOL(nss_crypto_session_free);

/*
 * nss_crypto_engine_init()
 *	initialize the crypto engine
 */
int nss_crypto_engine_init(struct nss_crypto_node *node, struct nss_crypto_engine *eng)
{
	struct nss_crypto_ctrl *ctrl = &g_control;
	struct nss_crypto_cmn_msg nim = {0};
	struct nss_crypto_cmn_engine *msg = &nim.msg.eng;
	struct nss_crypto_cmn_dma *dma_msg = &nim.msg.dma;
	nss_tx_status_t status;
	unsigned long *mask;
	uint16_t id;

	/*
	 * We should not enter this function in atomic state
	 */
	BUG_ON(in_atomic());

	nss_cmn_msg_init(&nim.cm, node->nss_ifnum, NSS_CRYPTO_CMN_MSG_TYPE_SETUP_ENG,
			 sizeof(nim) - sizeof(nim.cm), NULL, eng);

	nim.uid = eng->id;

	status = nss_crypto_cmn_tx_msg_sync(ctrl->nss_msg_hdl, &nim);
	if (status != NSS_TX_SUCCESS) {
		nss_crypto_warn("%p: unable to send(%d), status(%d), response(%d), error(%d)\n",
			node, nim.cm.type, status, nim.cm.response, nim.cm.error);
		return (status == NSS_TX_FAILURE_QUEUE) ? -EBUSY : -ENODEV;
	}

	eng->dma_mask = msg->dma_mask;
	if (!eng->dma_mask)
		return -ENOENT;

	/*
	 * Walk and find the DMA rings to initialize
	 */
	mask = (unsigned long *)&eng->dma_mask;
	for_each_set_bit(id, mask, BITS_PER_BYTE * sizeof(eng->dma_mask)) {
		memset(&nim, 0, sizeof(nim));

		/*
		 * Initialize Engine Specific DMA structures
		 */
		nss_cmn_msg_init(&nim.cm, node->nss_ifnum, NSS_CRYPTO_CMN_MSG_TYPE_SETUP_DMA,
			 sizeof(nim) - sizeof(nim.cm), NULL, eng);

		dma_msg->pair_id = id;

		status = nss_crypto_cmn_tx_msg_sync(ctrl->nss_msg_hdl, &nim);
		if (status != NSS_TX_SUCCESS) {
			nss_crypto_warn("%p: unable to send(%d), status(%d), rsp(%d), error(%d)\n",
					node, nim.cm.type, status, nim.cm.response, nim.cm.error);
			continue;
		}
	}

	/*
	 * Add engine to node head list and create a
	 * debugfs entry
	 */
	list_add_tail(&eng->list, &node->eng_head);

	nss_crypto_debugfs_add_engine(eng, node->dentry);

	return 0;
}

/*
 * nss_crypto_engine_alloc()
 *	This will allocate engine pointer
 */
struct nss_crypto_engine *nss_crypto_engine_alloc(struct platform_device *pdev)
{
	struct nss_crypto_engine *eng;

	eng = vzalloc(sizeof(struct nss_crypto_engine));
	if (!eng)
		return NULL;

	eng->dev = &pdev->dev;
	INIT_LIST_HEAD(&eng->list);

	return eng;
}

/*
 * nss_crypto_engine_free()
 *	deallocate the engine
 */
void nss_crypto_engine_free(struct nss_crypto_engine *eng)
{

	list_del(&eng->list);

	nss_crypto_debugfs_del_engine(eng);

	/*
	 * unmap previously mapped addresses
	 */
	iounmap(eng->crypto_vaddr);
	vfree(eng);
}

/*
 * nss_crypto_ndev_setup()
 *	setup the dummy netdevice
 */
void nss_crypto_ndev_setup(struct net_device *dev)
{
	nss_crypto_info("%p: dummy netdevice for crypto\n", dev);
}

/*
 * nss_crypto_node_alloc()
 *	Allocate the crypto node
 */
struct nss_crypto_node *nss_crypto_node_alloc(struct platform_device *pdev, uint32_t if_num, const char *name)
{
	struct nss_crypto_node *node;
	struct net_device *ndev;

	/*
	 * Create a dummy netdevice required for registering data callback with NSS driver
	 */
	ndev = alloc_netdev(sizeof(struct nss_crypto_node), name, NET_NAME_UNKNOWN, nss_crypto_ndev_setup);
	if (!ndev) {
		nss_crypto_warn("%p: unable to allocate node\n", pdev);
		return NULL;
	}

	node = netdev_priv(ndev);
	node->dev = &pdev->dev;

	INIT_LIST_HEAD(&node->list);
	INIT_LIST_HEAD(&node->eng_head);

	node->nss_ifnum = if_num;
	node->ndev = ndev;

	/*
	 * TODO Need to register a netdevice if we desire to
	 * communicate data to crypto from userspace
	 */

	return node;
}

/*
 * nss_crypto_node_init()
 *	initialize the crypto node
 */
int nss_crypto_node_init(struct nss_crypto_node *node, struct device_node *np)
{
	struct nss_crypto_cmn_msg nim = { {0} };
	struct nss_crypto_cmn_node *msg = &nim.msg.node;
	const size_t msg_sz = sizeof(nim) - sizeof(nim.cm);
	struct nss_crypto_ctrl *ctrl = &g_control;
	struct nss_crypto_algo_info *info;
	nss_tx_status_t status;
	int i;

	/*
	 * We should not enter this function in atomic state
	 */
	BUG_ON(in_atomic());

	/*
	 * read maximum DMA rings
	 */
	if (of_property_read_u32(np, "qcom,dma-mask", &node->dma_mask)) {
		nss_crypto_warn("%p: unable to read node DMA mask\n", np);
		return -ENOENT;
	}

	node->tx_enabled = of_property_read_bool(np, "qcom,transform-enabled");

	/*
	 * we need to map and mark the algorithms suggested by DTSI
	 * and supported by the driver
	 */
	for (i = 0, info = g_algo_info; i < ARRAY_SIZE(g_algo_info); i++, info++)
		node->algo[i] = info->name ? of_property_read_bool(np, info->name) : false;

	/*
	 * This is a synchronous message; hence there is nothing to callback
	 */
	nss_cmn_msg_init(&nim.cm, node->nss_ifnum, NSS_CRYPTO_CMN_MSG_TYPE_SETUP_NODE,
				msg_sz, NULL, node);

	msg->max_dma_rings = node->dma_mask;
	msg->max_ctx = ctrl->max_contexts;
	msg->max_ctx_size = ctrl->max_ctx_size;

	status = nss_crypto_cmn_tx_msg_sync(ctrl->nss_msg_hdl, &nim);
	if (status != NSS_TX_SUCCESS) {
		nss_crypto_warn("%p: unable to send(%d), status(%d), response(%d), error(%d)\n",
				node, nim.cm.type, status, nim.cm.response, nim.cm.error);
		return (status == NSS_TX_FAILURE_QUEUE) ? -EBUSY : -ENODEV;
	}

	list_add(&node->list, &ctrl->node_head);

	nss_crypto_debugfs_add_node(node, ctrl->dentry, node->ndev->name);

	node->nss_data_hdl = nss_crypto_cmn_data_register(node->nss_ifnum,
							nss_crypto_transform_done,
							node->ndev, 0);

	return 0;
}

/*
 * nss_crypto_node_free()
 *	free a crypto node
 */
void nss_crypto_node_free(struct nss_crypto_node *node)
{
	struct nss_crypto_engine *eng;
	struct nss_crypto_engine *tmp;

	list_for_each_entry_safe(eng, tmp, &node->eng_head, list)
		nss_crypto_engine_free(eng);

	list_del(&node->list);
	if (node->dentry)
		debugfs_remove_recursive(node->dentry);

	free_netdev(node->ndev);
}

/*
 * nss_crypto_user_free()
 *	free a crypto user
 */
void nss_crypto_user_free(struct kref *ref)
{
	struct nss_crypto_user *user = container_of(ref, struct nss_crypto_user, ref);
	struct sk_buff_head *sk_head = &user->sk_head;
	struct nss_crypto_ctrl *ctrl = &g_control;

	/*
	 * wake up the user unregister if its waiting for pending SKB(s)
	 */
	complete(&ctrl->complete);

	/*
	 * Note: we don't need a lock here to access the skb pool
	 * the fact that this is called when the references to the
	 * user has dropped to zero protects this list from being
	 * accessed by any other legitimate caller
	 */
	while (!skb_queue_empty(sk_head))
		dev_kfree_skb_any(__skb_dequeue(sk_head));

	vfree(user);
}

/*
 * nss_crypto_register_user()
 *	register a new user of the crypto driver
 */
struct nss_crypto_user *nss_crypto_register_user(struct nss_crypto_user_ctx *ctx, void *app_data)
{
	struct nss_crypto_ctrl *ctrl = &g_control;
	uint16_t hdr_pool_sz, default_hdr_sz;
	struct nss_crypto_user *user;
	struct sk_buff *skb;
	int num_skb;

	if (!of_find_compatible_node(NULL, NULL, "qcom,nss-crypto"))
		return NULL;

	if (!ctx->attach || !ctx->detach) {
		nss_crypto_warn("%p: callbacks missing\n", ctx);
		return NULL;
	}

	hdr_pool_sz = ctx->hdr_pool_sz;
	default_hdr_sz = ctx->default_hdr_sz;

	if (!hdr_pool_sz || !default_hdr_sz) {
		nss_crypto_warn("%p: pool_sz and hdr_sz missing\n", ctx);
		return NULL;
	}

	user = vzalloc(sizeof(struct nss_crypto_user));
	if (!user) {
		nss_crypto_warn("%p: unable to allocate user\n", ctx);
		return NULL;
	}

	memcpy(&user->ctx, ctx, sizeof(user->ctx));

	spin_lock_init(&user->lock);
	skb_queue_head_init(&user->sk_head);

        INIT_LIST_HEAD(&user->list);
	kref_init(&user->ref);

	user->app_data = app_data;

	/*
	 * Try allocating atleast 1 SKB for the pool
	 */
	skb = dev_alloc_skb(default_hdr_sz);
	if (!skb) {
		nss_crypto_warn("%p:unable to allocate atleast 1 skb\n", ctx);
		vfree(user);
		return NULL;
	}

	/*
	 * We dont need to take any locks at this point as
	 * the user pointer has not been notified to the caller
	 */
	__skb_queue_head(&user->sk_head, skb);

	/*
	 * Now we know that we have atleast 1 skb in the pool
	 * with which we can work with. Now try allocating
	 * hdr pool size worth of SKBs
	 */
	for (num_skb = 1; num_skb < hdr_pool_sz; num_skb++) {
		skb = dev_alloc_skb(default_hdr_sz);
		if (!skb)
			break;
		__skb_queue_head(&user->sk_head, skb);
	}

	nss_crypto_info("%p: registered user(%s), pool size(%d)\n", user, ctx->name, num_skb);

	/*
	 * We only register ourselves for a pending attach if the
	 * driver is not active
	 */
	mutex_lock(&ctrl->mutex);

	if (!ctrl->active) {
		list_add(&user->list, &ctrl->user_head);
		mutex_unlock(&ctrl->mutex);
		return user;
	}

	mutex_unlock(&ctrl->mutex);

	ctx->attach(app_data, user);
	return user;
}
EXPORT_SYMBOL(nss_crypto_register_user);

/*
 * nss_crypto_unregister_user()
 *	unregister a user from the crypto driver
 */
void nss_crypto_unregister_user(struct nss_crypto_user *user)
{
	unsigned long timeout_ticks = user->ctx.timeout_ticks;
	struct nss_crypto_ctrl *ctrl = &g_control;

	user->ctx.detach(user->app_data, user);

	/*
	 * If there are packets which are still getting
	 * processed for this particular user then kref
	 * put will fail
	 */
	if (kref_put(&user->ref, nss_crypto_user_free))
		return;

	/*
	 * We wait for some ticks worth of time to see if the
	 * outstanding SKBs' return to the pool. This situation
	 * will happen if there are inflight SKBs' while the unregister
	 * has happened.
	 */
	if (wait_for_completion_timeout(&ctrl->complete, timeout_ticks))
		return;
}
EXPORT_SYMBOL(nss_crypto_unregister_user);

static const struct of_device_id nss_crypto_dev_dt_ids[] = {
	{ .compatible =  "qcom,ce5" },
	{ .compatible =  "qcom,eip197" },
	{},
};
MODULE_DEVICE_TABLE(of, nss_crypto_dev_dt_ids);

static const struct of_device_id nss_crypto_dt_ids[] = {
	{ .compatible =  "qcom,nss-crypto" },
	{},
};
MODULE_DEVICE_TABLE(of, nss_crypto_dt_ids);

/*
 * nss_crypto_device_probe()
 *	probe each device node
 */
static int nss_crypto_device_probe(struct platform_device *pdev)
{
	struct device_node *np = of_node_get(pdev->dev.of_node);
	int error = -ENODEV;

	if (of_find_node_by_name(of_get_parent(np), "eip197_node"))
		error = nss_crypto_eip197_init(pdev, "eip197_node");

	return error;
}

/*
 * nss_crypto_device_remove()
 *	remove crypto device and deregister everything
 */
static int nss_crypto_device_remove(struct platform_device *pdev)
{
	nss_crypto_node_free(platform_get_drvdata(pdev));
	return 0;
};

/*
 * nss_crypto_device
 *	platform device instance
 */
static struct platform_driver nss_crypto_device = {
	.probe		= nss_crypto_device_probe,
	.remove		= nss_crypto_device_remove,
	.driver		= {
		.owner	= THIS_MODULE,
		.name	= "nss-crypto-device",
		.of_match_table = of_match_ptr(nss_crypto_dev_dt_ids),
	},
};

/*
 * nss_crypto_probe()
 *	probe the crypto driver
 */
static int nss_crypto_probe(struct platform_device *pdev)
{
	struct nss_crypto_ctrl *ctrl = &g_control;
	unsigned long max_contexts;
	struct device_node *np;
	size_t ctx_tbl_sz;

	np = of_node_get(pdev->dev.of_node);

	if (of_property_read_u32(np, "qcom,max-contexts", &ctrl->max_contexts)) {
		nss_crypto_err("%p: max session undefined\n", pdev);
		return -EINVAL;
	}

	/*
	 * max contexts should be a power of 2
	 */
	max_contexts = ctrl->max_contexts;
	if (!is_power_of_2(max_contexts))
		max_contexts = roundup_pow_of_two(max_contexts);

	ctrl->max_contexts = (uint32_t)max_contexts;

	if (!ctrl->max_contexts) {
		nss_crypto_warn("%p: Empty context\n", np);
		return -ENOSPC;
	}

	if (of_property_read_u32(np, "qcom,max-context-size", &ctrl->max_ctx_size)) {
		nss_crypto_err("%p: max session undefined\n", pdev);
		return -EINVAL;
	}

	ctx_tbl_sz = ctrl->max_contexts * sizeof(struct nss_crypto_ctx);
	ctrl->ctx_tbl = vzalloc(ctx_tbl_sz);
	if (!ctrl->ctx_tbl) {
		nss_crypto_err("%p: context table allocation fails\n", pdev);
		return -ENOMEM;
	}

	/*
	 * Add control debugfs and reset control stats
	 */
	nss_crypto_debugfs_add_control(ctrl);
	nss_crypto_ctrl_stats_init(&ctrl->cstats);

	INIT_LIST_HEAD(&ctrl->node_head);
	platform_set_drvdata(pdev, ctrl);

	return of_platform_populate(np, NULL, NULL, &pdev->dev);
}

/*
 * nss_crypto_remove()
 *	remove the crypto driver
 */
static int nss_crypto_remove(struct platform_device *pdev)
{
	struct nss_crypto_ctrl *ctrl = platform_get_drvdata(pdev);

	if (ctrl->ctrl_dentry)
		debugfs_remove_recursive(ctrl->ctrl_dentry);

	if (ctrl->ctx_tbl)
		vfree(ctrl->ctx_tbl);

	/*
	 * Clear the active state of driver
	 */
	ctrl->active = false;
	return 0;
}

/*
 * nss_crypto_drv
 *	platform device instance
 */
static struct platform_driver nss_crypto_drv = {
	.probe		= nss_crypto_probe,
	.remove		= nss_crypto_remove,
	.driver		= {
		.owner	= THIS_MODULE,
		.name	= "nss-crypto",
		.of_match_table = of_match_ptr(nss_crypto_dt_ids),
	},
};

/*
 * nss_crypto_delayed_probe()
 * 	delayed sequence to initialize crypto after NSS FW is initialized
 */
void nss_crypto_delayed_probe(struct work_struct *work)
{
	struct nss_crypto_ctrl *ctrl;
	struct nss_crypto_user *user;
	struct nss_crypto_user *tmp;

	ctrl = container_of(to_delayed_work(work), struct nss_crypto_ctrl, probe_work);

	/*
	 * Check if NSS FW is initialized
	 */
	if (nss_get_state(ctrl->nss_msg_hdl) != NSS_STATE_INITIALIZED) {
		schedule_delayed_work(&ctrl->probe_work, NSS_CRYPTO_DELAYED_INIT_TICKS);
		return;
	}

	if (platform_driver_register(&nss_crypto_drv)) {
		nss_crypto_warn("%p: unable to register the driver\n", ctrl);
		return;
	}

	if (platform_driver_register(&nss_crypto_device)) {
		nss_crypto_warn("%p: unable to register the device\n", ctrl);
		return;
	}

	/*
	 * We walk the user list to find out those users which have registered
	 * with the crypto driver before the driver was initialized. This is
	 * very much possible as the firmware can take some time to boot and
	 * initialize itself. If, a user registering with crypto driver sees
	 * the driver is not ready would add itself to the pending list and return.
	 * Once, the driver is becomes ready (marked in active flag) all these user
	 * will get notified with the attach. This will be called from the context
	 * of delayed_probe. For any new users registering after the driver is marked
	 * active will not require the list addition. It would get attached in the
	 * same context in which they are registering.
	 */
	mutex_lock(&ctrl->mutex);

	ctrl->active = true;
	list_for_each_entry_safe(user, tmp, &ctrl->user_head, list) {
		list_del_init(&user->list);
		user->ctx.attach(user->app_data, user);
	}

	mutex_unlock(&ctrl->mutex);
}

/*
 * nss_crypto_module_init()
 *	module init for crypto driver
 */
static int __init nss_crypto_module_init(void)
{
	struct nss_crypto_ctrl *ctrl = &g_control;

	nss_crypto_info_always("module loaded %s\n", NSS_CRYPTO_BUILD_ID);

	/*
	 * Mark the crypto driver inactive at start. When
	 * probe completes successfully it will mark this
	 * active
	 */
	ctrl->active = false;

	if (!of_find_compatible_node(NULL, NULL, "qcom,nss-crypto")) {
		nss_crypto_info_always("module loaded for symbol link\n");
		return 0;
	}

	INIT_LIST_HEAD(&ctrl->node_head);
	INIT_LIST_HEAD(&ctrl->user_head);

	mutex_init(&ctrl->mutex);

	ctrl->nss_msg_hdl = nss_crypto_cmn_notify_register(nss_crypto_process_event, ctrl);

	init_completion(&ctrl->complete);
	INIT_DELAYED_WORK(&ctrl->probe_work, nss_crypto_delayed_probe);
	schedule_delayed_work(&ctrl->probe_work, NSS_CRYPTO_DELAYED_INIT_TICKS);

	/*
	 * Non availability of debugfs directory is not a catastrophy
	 * We can still go ahead with other initialization
	 */
	ctrl->dentry = debugfs_create_dir("qca-nss-crypto", NULL);

	return 0;
}
module_init(nss_crypto_module_init);

/*
 * nss_crypto_module_exit()
 *	module exit for crypto driver
 */
static void __exit nss_crypto_module_exit(void)
{
	platform_driver_unregister(&nss_crypto_drv);
	platform_driver_unregister(&nss_crypto_device);
}
module_exit(nss_crypto_module_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("QCA NSS Crypto driver");
