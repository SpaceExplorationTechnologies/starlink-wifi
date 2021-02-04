/*
 * Copyright (c) 2014, The Linux Foundation. All rights reserved.
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
 */

#ifndef _NSS_MACSEC_EMAC_H_
#define _NSS_MACSEC_EMAC_H_

#include "nss_macsec_types.h"

enum emac_link_speed {
	SPEED10 = 1,
	SPEED100 = 2,
	SPEED1000 = 3,
};

u32 nss_macsec_emac_init(u32 secy_id);
u32 nss_macsec_speed(u32 secy_id, enum emac_link_speed speed);
u32 nss_macsec_emac_enable(u32 secy_id, BOOL enable);
u32 nss_macsec_emac_reset(u32 secy_id);

#endif /* _NSS_MACSEC_EMAC_H_ */
