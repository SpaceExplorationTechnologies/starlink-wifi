/*
 * Copyright (c) 2015-2017 The Linux Foundation. All rights reserved.
 *
 * Copyright (C) 2012 Red Hat, Inc. All Rights Reserved.
 * Written by David Howells (dhowells@redhat.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public Licence
 * as published by the Free Software Foundation; either version 2
 * of the Licence, or (at your option) any later version.
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/fcntl.h>
#include <crypto/public_key.h>
#include <linux/mpi.h>
#include <crypto/public_key.h>
#include <linux/err.h>
#include <crypto/hash.h>
#include <misc/fw_auth.h>
#include "public_key.h"
#include "x509_parser.h"

static int check_input(struct auth_input *ai)
{
	if (ai &&
	    ai->certBuffer && ai->signature && ai->data &&
	    /* To ignore allocated but empty buffers */
	    ai->cert_len > 0 && ai->sig_len > 0 &&
	    ai->data_len > 0 &&
	    ai->certBuffer[0]) {
		return 0;
	}

	return -EINVAL;
}

static struct public_key_signature *compute_digest(enum hash_algo alg,
					const void *bin, unsigned long bin_len)
{
	struct public_key_signature *pks;
	struct crypto_shash *tfm;
	struct shash_desc *desc;
	size_t digest_size, desc_size;
	int ret;

	/*
	 * Allocate the hashing algorithm we're going to need and find out how
	 * big the hash operational data will be.
	 */
	tfm = crypto_alloc_shash(hash_algo_name[alg], 0, 0);
	if (IS_ERR(tfm))
		return (PTR_ERR(tfm) == -ENOENT) ?
					ERR_PTR(-ENOPKG) : ERR_CAST(tfm);

	desc_size = crypto_shash_descsize(tfm) + sizeof(*desc);
	digest_size = crypto_shash_digestsize(tfm);

	/*
	 * We allocate the hash operational data storage on the end of our
	 * context data and the digest output buffer on the end of that.
	 */
	ret = -ENOMEM;
	pks = kzalloc(digest_size + sizeof(*pks) + desc_size, GFP_KERNEL);
	if (!pks)
		goto error_no_pks;

	pks->pkey_hash_algo = alg;
	pks->digest = (u8 *)pks + sizeof(*pks) + desc_size;
	pks->digest_size = digest_size;

	desc = (void *)pks + sizeof(*pks);
	desc->tfm = tfm;
	desc->flags = CRYPTO_TFM_REQ_MAY_SLEEP;

	ret = crypto_shash_init(desc);
	if (ret < 0)
		goto error;

	ret = crypto_shash_finup(desc, bin, bin_len, pks->digest);
	if (ret < 0)
		goto error;

	crypto_free_shash(tfm);
	return pks;

error:
	kfree(pks);
error_no_pks:
	crypto_free_shash(tfm);
	pr_devel("<==%s() = %d\n", __func__, ret);

	return ERR_PTR(ret);
}

static int extract_mpi_array(const void *data, size_t len,
				struct public_key_signature *pks)
{
	MPI mpi;

	if (len < 1 || !data)
		return -EBADMSG;
	mpi = mpi_read_raw_data(data, len);
	if (!mpi)
		return -ENOMEM;
	pks->mpi[0] = mpi;
	pks->nr_mpi = 1;
	return 0;
}

static struct x509_certificate *parse_validate_cert(struct auth_input *ai)
{
	int ret;
	struct x509_certificate *cert;

	cert = x509_cert_parse(ai->certBuffer, ai->cert_len);
	if (IS_ERR(cert))
		return cert;

	if (cert->pub->pkey_algo >= PKEY_ALGO__LAST ||
	    cert->sig.pkey_algo >= PKEY_ALGO__LAST ||
	    cert->sig.pkey_hash_algo >= PKEY_HASH__LAST ||
	    !pkey_algo[cert->pub->pkey_algo] ||
	    !pkey_algo[cert->sig.pkey_algo] ||
	    !hash_algo_name[cert->sig.pkey_hash_algo]) {
		ret = -ENOPKG;
		goto err_free_cert;
	}

	cert->pub->algo = pkey_algo[cert->pub->pkey_algo];
	cert->pub->id_type = PKEY_ID_X509;

	/* Check the signature on the key if it appears to be self-signed */
	if ((!cert->akid_skid && !cert->akid_id) ||
		asymmetric_key_id_same(cert->skid, cert->akid_skid) ||
		asymmetric_key_id_same(cert->id, cert->akid_id)) {
		ret = x509_check_signature(cert->pub, cert); /* self-signed*/
		if (ret < 0)
			goto err_free_cert;
	}
	return cert;

err_free_cert:
	x509_free_certificate(cert);
	return ERR_PTR(ret);
}

int authenticate_fw(struct auth_input *ai)
{
	struct public_key_signature *pks;
	struct x509_certificate *cert;
	int ret;

	if (check_input(ai))
		return -EINVAL;

	if (ai->sig_hash_algo != HASH_ALGO_SHA256 &&
	    ai->sig_hash_algo != HASH_ALGO_SHA1) {
		pr_info("\nSHA1/SHA256 are the supported hash algorithms\n");
		return -ENOTSUPP;
	}
	if (ai->pk_algo != PKEY_ALGO_RSA)
		return -ENOTSUPP;

	if (ai->cert_type != PKEY_ID_X509)
		return -ENOTSUPP;

	/* Compute hash of the given binary data */
	pks = compute_digest(ai->sig_hash_algo, ai->data, ai->data_len);
	if (IS_ERR(pks))
		return PTR_ERR(pks);

	/* Convert signature to MPI format */
	ret = extract_mpi_array(ai->signature, ai->sig_len, pks);
	if (ret)
		goto err_free;
	/*
	 * Extract public key from certificate and validate
	 * the self-signed certificate signature
	 */
	cert = parse_validate_cert(ai);
	if (IS_ERR(cert)) {
		ret = PTR_ERR(cert);
		goto err_free;
	}
	/* RSA Verify signature */
	if (cert && cert->pub) {
		ret = public_key_verify_signature(cert->pub, pks);
		pr_debug("\nRSA signature verification %s\n",
				(ret == 0) ? "Passed" : "Failed");
	}

	x509_free_certificate(cert);
err_free:
	mpi_free(pks->rsa.s);
	kfree(pks);
	return ret;
}
EXPORT_SYMBOL(authenticate_fw);
