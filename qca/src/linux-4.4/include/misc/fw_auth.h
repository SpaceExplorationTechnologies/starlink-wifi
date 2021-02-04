/*
 * Copyright (c) 2015-2017, The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#ifndef _FW_AUTH_H
#define _FW_AUTH_H

#include <crypto/public_key.h>

struct auth_input {
	uint8_t *certBuffer;
	uint8_t *signature;
	uint8_t *data;
	int cert_len;
	int sig_len;
	int data_len;
	enum hash_algo sig_hash_algo; /* Hash Algorithm used for signature */
	enum pkey_algo pk_algo; /* Public Key Algorithm */;
	enum pkey_id_type cert_type; /* Type of Public Key Certificate */
};

int authenticate_fw(struct auth_input *ai);
#endif /* _FW_AUTH_H */
