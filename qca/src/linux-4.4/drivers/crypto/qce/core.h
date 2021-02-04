/*
 * Copyright (c) 2010-2014, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _CORE_H_
#define _CORE_H_

#include "dma.h"

#define DEBUG_MAX_RW_BUF 2048
#define DEBUG_MAX_FNAME  16

/**
 * struct qce_stat - statistics of crypto requests per algorithm to qce engine
 */
struct qce_stat {
	u64 aead_sha1_aes_enc;
	u64 aead_sha1_aes_dec;
	u64 aead_sha1_des_enc;
	u64 aead_sha1_des_dec;
	u64 aead_sha1_3des_enc;
	u64 aead_sha1_3des_dec;
	u64 aead_sha256_aes_enc;
	u64 aead_sha256_aes_dec;
	u64 aead_sha256_des_enc;
	u64 aead_sha256_des_dec;
	u64 aead_sha256_3des_enc;
	u64 aead_sha256_3des_dec;
	u64 aead_ccm_aes_enc;
	u64 aead_ccm_aes_dec;
	u64 aead_rfc4309_ccm_aes_enc;
	u64 aead_rfc4309_ccm_aes_dec;
	u64 aead_op_success;
	u64 aead_op_fail;
	u64 aead_bad_msg;
	u64 ablk_cipher_aes_enc;
	u64 ablk_cipher_aes_dec;
	u64 ablk_cipher_des_enc;
	u64 ablk_cipher_des_dec;
	u64 ablk_cipher_3des_enc;
	u64 ablk_cipher_3des_dec;
	u64 ablk_cipher_op_success;
	u64 ablk_cipher_op_fail;
	u64 sha1_digest;
	u64 sha256_digest;
	u64 sha1_hmac_digest;
	u64 sha256_hmac_digest;
	u64 ahash_op_success;
	u64 ahash_op_fail;
};

/**
 * struct qce_device - crypto engine device structure
 * @queue: crypto request queue
 * @lock: the lock protects queue and req
 * @done_tasklet: done tasklet object
 * @req: current active request
 * @result: result of current transform
 * @base: virtual IO base
 * @dev: pointer to device structure
 * @core: core device clock
 * @iface: interface clock
 * @bus: bus clock
 * @dma: pointer to dma data
 * @burst_size: the crypto burst size
 * @pipe_pair_id: which pipe pair id the device using
 * @qce_stat: statistics of requests to qce device
 * @qce_debug_dent: dentry to the "qce" debugfs directory
 * @qce_debug_read_buf: buffer to store the qce stats
 * @async_req_enqueue: invoked by every algorithm to enqueue a request
 * @async_req_done: invoked by every algorithm to finish its request
 */
struct qce_device {
	struct crypto_queue queue;
	spinlock_t lock;
	struct tasklet_struct done_tasklet;
	struct crypto_async_request *req;
	int result;
	void __iomem *base;
	struct device *dev;
	struct clk *core, *iface, *bus;
	struct qce_dma_data dma;
	int burst_size;
	unsigned int pipe_pair_id;
	struct qce_stat qce_stat;
	struct dentry *qce_debug_dent;
	char qce_debug_read_buf[DEBUG_MAX_RW_BUF];
	int (*async_req_enqueue)(struct qce_device *qce,
				 struct crypto_async_request *req);
	void (*async_req_done)(struct qce_device *qce, int ret);
};

/**
 * struct qce_algo_ops - algorithm operations per crypto type
 * @type: should be CRYPTO_ALG_TYPE_XXX
 * @register_algs: invoked by core to register the algorithms
 * @unregister_algs: invoked by core to unregister the algorithms
 * @async_req_handle: invoked by core to handle enqueued request
 */
struct qce_algo_ops {
	u32 type;
	int (*register_algs)(struct qce_device *qce);
	void (*unregister_algs)(struct qce_device *qce);
	int (*async_req_handle)(struct crypto_async_request *async_req);
};

#endif /* _CORE_H_ */
