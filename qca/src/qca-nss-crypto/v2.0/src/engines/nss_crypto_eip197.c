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

#include "nss_crypto_hlos.h"
#include <nss_api_if.h>
#include <nss_crypto_defines.h>
#include <nss_crypto_api.h>
#include <nss_crypto_hdr.h>

#include "nss_crypto_ctrl.h"
#include "nss_crypto_debugfs.h"
#include "engines/nss_crypto_eip197.h"

/*
 * nss_crypto_eip197_ctx_info
 *	eip context info structure
 */
struct nss_crypto_eip197_ctx_ctrl {
	uint32_t ctrl[NSS_CRYPTO_EIP197_MAX_CTRL];
};

static struct nss_crypto_eip197_ctx_ctrl g_ctx_info[NSS_CRYPTO_CMN_ALGO_MAX] = {
	[NSS_CRYPTO_CMN_ALGO_3DES_CBC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_3DES |
				NSS_CRYPTO_EIP197_CTX_SIZE_8WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CBC,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_CBC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES128 |
				NSS_CRYPTO_EIP197_CTX_SIZE_6WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CBC,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_CTR] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES128 |
				NSS_CRYPTO_EIP197_CTX_SIZE_7WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CTR,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_ECB] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES128 |
				NSS_CRYPTO_EIP197_CTX_SIZE_6WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_ECB,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_CBC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES192 |
				NSS_CRYPTO_EIP197_CTX_SIZE_8WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CBC,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_CTR] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES192 |
				NSS_CRYPTO_EIP197_CTX_SIZE_9WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CTR,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_ECB] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES192 |
				NSS_CRYPTO_EIP197_CTX_SIZE_8WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_ECB,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_CBC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES256 |
				NSS_CRYPTO_EIP197_CTX_SIZE_10WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CBC,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_CTR] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES256 |
				NSS_CRYPTO_EIP197_CTX_SIZE_11WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CTR,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_ECB] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES256 |
				NSS_CRYPTO_EIP197_CTX_SIZE_10WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_ECB,
	},
	[NSS_CRYPTO_CMN_ALGO_SHA160_HASH] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_ALGO_SHA1,
	},
	[NSS_CRYPTO_CMN_ALGO_SHA224_HASH] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_ALGO_SHA224,
	},
	[NSS_CRYPTO_CMN_ALGO_SHA256_HASH] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_ALGO_SHA256,
	},
	[NSS_CRYPTO_CMN_ALGO_SHA160_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_ALGO_SHA1 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_10WORDS,
	},
	[NSS_CRYPTO_CMN_ALGO_SHA256_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_ALGO_SHA256 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_18WORDS,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_CBC_SHA160_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES128 |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA1 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_16WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CBC,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_CBC_SHA256_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES128 |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA256 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_22WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CBC,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_CTR_SHA160_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES128 |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA1 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_17WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CTR,
	},
	[NSS_CRYPTO_CMN_ALGO_AES128_CTR_SHA256_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES128 |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA256 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_23WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CTR,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_CBC_SHA160_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES192 |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA1 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_18WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CBC,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_CBC_SHA256_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES192 |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA256 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_24WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CBC,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_CTR_SHA160_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES192 |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA1 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_19WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CTR,
	},
	[NSS_CRYPTO_CMN_ALGO_AES192_CTR_SHA256_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES192 |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA256 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_25WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CTR,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_CBC_SHA160_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES256 |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA1 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_20WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CBC,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_CBC_SHA256_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES256 |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA256 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_26WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CBC,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_CTR_SHA160_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES256 |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA1 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_21WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CTR,
	},
	[NSS_CRYPTO_CMN_ALGO_AES256_CTR_SHA256_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_AES256 |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA256 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_27WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CTR,
	},
	[NSS_CRYPTO_CMN_ALGO_3DES_CBC_SHA160_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_3DES |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA1 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_18WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CBC,
	},
	[NSS_CRYPTO_CMN_ALGO_3DES_CBC_SHA256_HMAC] = {
		.ctrl[0] = NSS_CRYPTO_EIP197_CTX_WITH_KEY | NSS_CRYPTO_EIP197_CTX_ALGO_3DES |
			NSS_CRYPTO_EIP197_CTX_ALGO_SHA256 | NSS_CRYPTO_EIP197_CTX_AUTH_MODE_HMAC |
			NSS_CRYPTO_EIP197_CTX_SIZE_24WORDS,
		.ctrl[1] = NSS_CRYPTO_EIP197_CTX_CIPHER_MODE_CBC,
	},
};

/*
 * g_crypto_eip197_debugfs
 *	debugfs structure
 */
struct nss_crypto_debugfs_entry g_crypto_eip197_debugfs[] = {
	{
		.name = "dma_regs",
		.ops = {
			.owner = THIS_MODULE,
			.open = simple_open,
			.read = nss_crypto_eip197_read_dma_reg,
		},
	},
	{
		.name = "hia_regs",
		.ops = {
			.owner = THIS_MODULE,
			.open = simple_open,
			.read = nss_crypto_eip197_read_hia_reg,
		},
	},
	{
		.name = "pe_regs",
		.ops = {
			.owner = THIS_MODULE,
			.open = simple_open,
			.read = nss_crypto_eip197_read_pe_reg,
		},
	},
};

/*
 * nss_crypto_eip197_clock_init()
 *	Initialise crypto clock
 */
static int nss_crypto_eip197_clock_init(struct platform_device *pdev)
{
	struct device_node *np = of_node_get(pdev->dev.of_node);
	const char *clk_string;
	struct property *prop;
	uint64_t *clk_rate;
	struct clk *clk;
	int status = 0;
	int count, i;
	size_t size;

	/*
	 * Enable crypto clock
	 */
	count = of_property_count_strings(np, "clock-names");
	if (count < 0) {
		nss_crypto_info("crypto clock entry not found\n");
		return 0;
	}

	/*
	 * Parse clock frequency from crypto DTSI node
	 */
	prop = of_find_property(np, "clock-frequency", NULL);
	if (!prop) {
		nss_crypto_info("crypto clock frequency entry not found\n");
		return 0;
	}

	size = prop->length / sizeof(*clk_rate);

	clk_rate = kzalloc(size, GFP_KERNEL);
	if (!clk_rate)
		return -ENOMEM;

	if (of_property_read_u64_array(np, "clock-frequency", clk_rate, size)) {
		status = -EINVAL;
		goto free;
	}

	for (i = 0; i < count; i++) {
		/*
		 * parse clock names from DTSI
		 */
		of_property_read_string_index(np, "clock-names", i, &clk_string);

		clk = devm_clk_get(&pdev->dev, clk_string);
		if (IS_ERR(clk)) {
			nss_crypto_err("%p: cannot get crypto clock: %s\n", &pdev->dev, clk_string);
			status = -ENOENT;
			goto free;
		}

		if (clk_set_rate(clk, clk_rate[i])) {
			nss_crypto_err("%p: cannot set %llx freq for %s\n", &pdev->dev, clk_rate[i], clk_string);
			status = -EINVAL;
			goto free;
		}

		if (clk_prepare_enable(clk)) {
			nss_crypto_err("%p: cannot enable clock: %s\n", &pdev->dev, clk_string);
			status = -EFAULT;
			goto free;
		}
	}

free:
	kfree(clk_rate);
	return status;
}

/*
 * nss_crypto_eip197_fill_digest()
 *	Precomputing the first pass of the digest.
 *
 * Note: this is essentially recommended by the HW to
 * pre-compute the first pass of the digest using the
 * fixed set of the information. This requires producing
 * the first pass of the hash with the authentication key
 * and values suggested for HMAC computation. The HW requires
 * this to be fed to it instead of the key.
 */
static int nss_crypto_eip197_fill_digest(struct nss_crypto_ctx *ctx, const uint8_t *key, uint8_t *data)
{
	uint32_t *in_digest, *out_digest, *tmp_digest;
	uint8_t *ipad_key, *opad_key, *hash_key;
	size_t digest_sz;
	size_t block_sz;
	size_t  total_sz;
	uint16_t words;
	void *mem;
	int i;

	digest_sz = ctx->info->digest_sz;
	block_sz = ctx->info->auth_blk_len;

	/*
	 * We allocate here a big chunk of memory and then
	 * divide the allocated memory into
	 * - ipad_key, opad_key and hash_key.
	 */
	total_sz = (3 * block_sz) + digest_sz;
	mem = vzalloc(total_sz);
	if (!mem)
		return -ENOMEM;

	tmp_digest = mem;
	ipad_key = (uint8_t *)tmp_digest + digest_sz;
	opad_key = ipad_key + block_sz;
	hash_key = opad_key + block_sz;

	/*
	 * Copy key for keyed hash algorithms
	 */
	memcpy(hash_key, key, digest_sz);

	/*
	 * Compute initial fixed hash values as suggested by RFC2104
	 */
	for (i = 0; i < block_sz; i++) {
		ipad_key[i] = hash_key[i] ^ 0x36;
		opad_key[i] = hash_key[i] ^ 0x5c;
	}

	words = digest_sz / sizeof(uint32_t);
	in_digest = (uint32_t *)data;
	out_digest = in_digest + words;

	memcpy(in_digest, ctx->info->auth_fips_iv, digest_sz);
	memcpy(out_digest, ctx->info->auth_fips_iv, digest_sz);

	switch (digest_sz) {
	case SHA1_DIGEST_SIZE:
		sha_transform(in_digest, ipad_key, tmp_digest);
		sha_transform(out_digest, opad_key, tmp_digest);

		break;

	case SHA224_DIGEST_SIZE:
	case SHA256_DIGEST_SIZE:
		sha256_transform(in_digest, ipad_key);
		sha256_transform(out_digest, opad_key);

		break;

	default:
		nss_crypto_warn("%p:unsupported digest size(%zu)\n", data, digest_sz);
		return -EINVAL;
	}

	for (i = 0; i < words; i++) {
		in_digest[i] = cpu_to_be32(in_digest[i]);
		out_digest[i] = cpu_to_be32(out_digest[i]);
	}

	vfree(mem);
	return 0;
}

/*
 * nss_crypto_eip197_ctx_fill()
 *	Fill context record specific information
 */
int nss_crypto_eip197_ctx_fill(struct nss_crypto_ctx *ctx, struct nss_crypto_session_data *data,
			struct nss_crypto_cmn_ctx *msg, void __iomem *hw_ctx)
{
	size_t cipher_key_words;
	size_t auth_key_words;
	uint8_t *cipher_data;
	uint8_t *auth_data;

	if (data->algo > NSS_CRYPTO_CMN_ALGO_MAX)
		return -EINVAL;

	/*
	 * Fill context control words
	 */
	ctx->hw_info = &g_ctx_info[data->algo];

	memcpy(msg->spare, ctx->hw_info, sizeof(struct nss_crypto_eip197_ctx_ctrl));

	cipher_key_words = ctx->info->cipher_key_len / sizeof(uint32_t);
	auth_key_words = ctx->info->auth_key_len / sizeof(uint32_t);

	msg->words = cipher_key_words + (auth_key_words * 2) + NSS_CRYPTO_EIP197_MAX_CTRL;
	msg->flags = NSS_CRYPTO_CMN_CTX_FLAGS_SPARE0 | NSS_CRYPTO_CMN_CTX_FLAGS_SPARE1;

	memcpy(hw_ctx, ctx->hw_info, sizeof(struct nss_crypto_eip197_ctx_ctrl));
	cipher_data = (uint8_t *)hw_ctx + sizeof(struct nss_crypto_eip197_ctx_ctrl);
	auth_data = cipher_data + ctx->info->cipher_key_len;

	/*
	 * Fill cipher keys
	 */
	if (ctx->info->cipher_valid)
		memcpy(cipher_data, data->cipher_key, ctx->info->cipher_key_len);

	/*
	 * Fill auth digest for HMAC mode ops
	 */
	if (ctx->info->auth_valid && ctx->info->auth_key_len)
		return nss_crypto_eip197_fill_digest(ctx, data->auth_key, auth_data);

	return 0;
}

/*
 * nss_crypto_eip197_engine_init()
 *	allocate & initialize engine
 */
int nss_crypto_eip197_engine_init(struct platform_device *pdev, struct device_node *np,
				struct resource *res, uint32_t offset)
{
	struct nss_crypto_node *node = platform_get_drvdata(pdev);
	struct nss_crypto_engine *eng;
	void __iomem *vaddr;
	phys_addr_t paddr;
	int status;

	/*
	 * remap the I/O addresses
	 */
	paddr = res->start + offset;
	vaddr = ioremap_nocache(paddr, resource_size(res));
	if (!vaddr) {
		nss_crypto_warn("%p: unable to remap crypto_addr(0x%p)\n", node, (void *)paddr);
		return -EIO;
	}

	/*
	 * allocate the engine class
	 */
	eng = nss_crypto_engine_alloc(pdev);
	if (!eng) {
		nss_crypto_warn("%p: unable to allocate engine\n", node);
		iounmap(vaddr);
		return -ENOMEM;
	}

	eng->node = node;

	/*
	 * Populate and add engine debugfs register dump structure
	 */
	eng->debugfs_entries = g_crypto_eip197_debugfs;
	eng->debugfs_num_entries = ARRAY_SIZE(g_crypto_eip197_debugfs);

	/*
	 * Fill EIP197 engine specific parameters
	 */
	eng->id = offset;

	/*
	 * note: for EIP197 the crypto & dma base address are same
	 */
	eng->crypto_paddr = paddr;
	eng->crypto_vaddr = vaddr;

	/*
	 * initialize the H/W
	 */
	nss_crypto_eip197_hw_init(pdev, np, eng->crypto_vaddr);

	status = nss_crypto_engine_init(node, eng);
	if (status < 0) {
		nss_crypto_warn("%p: unable to initialize engine(%d),status(%d)",
				node, eng->id, status);
		nss_crypto_engine_free(eng);
		return status;
	}

	return 0;
}

/*
 * nss_crypto_eip197_node_init()
 *	allocate & initialize eip197 node
 */
int nss_crypto_eip197_node_init(struct platform_device *pdev, const char *name)
{
	struct device_node *np = of_node_get(pdev->dev.of_node);
	struct nss_crypto_node *node;
	int status;

	/*
	 * allocate the EIP197 node
	 */
	node = nss_crypto_node_alloc(pdev, NSS_CRYPTO_EIP197_INTERFACE, name);
	if (!node) {
		nss_crypto_warn("%p: unable to allocate %s node\n", np, name);
		return -ENOMEM;
	}

	node->fill_ctx = nss_crypto_eip197_ctx_fill;

	status = nss_crypto_node_init(node, np);
	if (status < 0) {
		nss_crypto_warn("%p: unable to initialize the node, status(%d)\n", np, status);
		nss_crypto_node_free(node);
		return status;
	}

	platform_set_drvdata(pdev, node);
	return 0;
}

/*
 * nss_crypto_eip197_init()
 *	performs HW initialization, FW boot and DMA initialization
 */
int nss_crypto_eip197_init(struct platform_device *pdev, const char *name)
{
	struct device_node *np = of_node_get(pdev->dev.of_node);
	struct resource crypto_res = {0};
	struct device_node *child;
	uint32_t reg_offset;
	int status;

	status = nss_crypto_eip197_clock_init(pdev);
	if (status < 0) {
		nss_crypto_warn("%p: unable to intialize clock, status(%d)\n", pdev, status);
		return status;
	}

	/*
	 * Crypto Registers resource
	 */
	if (of_address_to_resource(np, 0, &crypto_res) != 0) {
		nss_crypto_warn("%p: unable to read crypto resource\n", np);
		return -EINVAL;
	}

	/*
	 * initialize the EIP197 node
	 */
	status = nss_crypto_eip197_node_init(pdev, name);
	if (status < 0) {
		nss_crypto_warn("%p: unable to intialize node, status(%d)\n", pdev, status);
		return status;
	}

	for_each_child_of_node(np, child) {
		if (of_property_read_u32(child, "reg_offset", &reg_offset)) {
			nss_crypto_warn("%p: unable to read reg_offset\n", child);
			continue;
		}

		status = nss_crypto_eip197_engine_init(pdev, child, &crypto_res, reg_offset);
		if (status < 0) {
			nss_crypto_warn("%p: unable to intialize engine, status(%d)\n",
					child, status);
			break;
		}
	}

	return status;
}
