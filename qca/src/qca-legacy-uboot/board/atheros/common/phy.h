/* 
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
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
 * 
 */
#ifndef _PHY_H
#define _PHY_H

#include <config.h>

#define ath_gmac_unit2name(_unit) (_unit ?  "eth1" : "eth0")

extern int ath_gmac_miiphy_read(char *devname, uint32_t phaddr, uint8_t reg, uint16_t *data);
extern int ath_gmac_miiphy_write(char *devname, uint32_t phaddr, uint8_t reg, uint16_t data);

#define phy_reg_read(base, addr, reg)	\
	ath_gmac_miiphy_read(ath_gmac_unit2name(base), addr, reg, NULL)

#define phy_reg_write(base, addr, reg, data)	\
	ath_gmac_miiphy_write(ath_gmac_unit2name(base), addr, reg, data)

#endif
