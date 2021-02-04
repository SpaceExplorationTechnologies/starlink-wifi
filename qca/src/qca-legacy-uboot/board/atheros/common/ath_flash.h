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


#ifndef _ATH_FLASH_H
#define _ATH_FLASH_H

#define display(_x)

/*
 * primitives
 */

#define ath_be_msb(_val, _i) (((_val) & (1 << (7 - _i))) >> (7 - _i))

#define ath_spi_bit_banger(_byte)	do {				\
	int i;								\
	for(i = 0; i < 8; i++) {					\
		ath_reg_wr_nf(ATH_SPI_WRITE,				\
			ATH_SPI_CE_LOW | ath_be_msb(_byte, i));		\
		ath_reg_wr_nf(ATH_SPI_WRITE,				\
			ATH_SPI_CE_HIGH | ath_be_msb(_byte, i));	\
	}								\
} while (0)

#define ath_spi_go()	do {				\
	ath_reg_wr_nf(ATH_SPI_WRITE, ATH_SPI_CE_LOW);	\
	ath_reg_wr_nf(ATH_SPI_WRITE, ATH_SPI_CS_DIS);	\
} while (0)


#define ath_spi_send_addr_4b(__a) do {			\
	ath_spi_bit_banger(((__a & 0xff000000) >> 24));	\
	ath_spi_bit_banger(((__a & 0x00ff0000) >> 16));	\
	ath_spi_bit_banger(((__a & 0x0000ff00) >> 8));	\
	ath_spi_bit_banger(__a & 0x000000ff);		\
} while (0)

#define ath_spi_send_addr(__a) do {			\
	ath_spi_bit_banger(((__a & 0xff0000) >> 16));	\
	ath_spi_bit_banger(((__a & 0x00ff00) >> 8));	\
	ath_spi_bit_banger(__a & 0x0000ff);		\
} while (0)

#define ath_spi_delay_8()	ath_spi_bit_banger(0)
#define ath_spi_done()		ath_reg_wr_nf(ATH_SPI_FS, 0)

extern unsigned long flash_get_geom (flash_info_t *flash_info);

#endif /* _ATH_FLASH_H */
