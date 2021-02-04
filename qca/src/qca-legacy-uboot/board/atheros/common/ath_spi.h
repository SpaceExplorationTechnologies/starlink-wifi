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
#ifndef _ATH_SPI_H
#define _ATH_SPI_H

#define ATH_FLASH_MAX_BANKS	1

#define display(_x)	ath_reg_wr_nf(0x18040008, (_x))

/*
 * primitives
 */

#define ath_be_msb(_val, __i) (((_val) & (1 << (7 - __i))) >> (7 - __i))

#define ath_spi_bit_banger(l, h, b)					\
do {									\
	int i;								\
	for(i = 0; i < 8; i++) {					\
		ath_reg_wr_nf(ATH_SPI_WRITE, l | ath_be_msb(b, i));	\
		ath_reg_wr_nf(ATH_SPI_WRITE, h | ath_be_msb(b, i));	\
	}								\
} while (0)

#define ath_spi_go(l)					\
do {							\
	ath_reg_wr_nf(ATH_SPI_WRITE, l);		\
	ath_reg_wr_nf(ATH_SPI_WRITE, ATH_SPI_CS_DIS);	\
} while (0)


#define ath_spi_send_addr(l, h, a)				\
do {								\
	ath_spi_bit_banger(l, h, ((a & 0xff0000) >> 16));	\
	ath_spi_bit_banger(l, h, ((a & 0x00ff00) >> 8));	\
	ath_spi_bit_banger(l, h, ((a & 0x0000ff) >> 0));	\
} while (0)

#define ath_spi_word_banger(_byte, _num, _cs)			\
do {								\
	unsigned int i;						\
	ath_reg_wr_nf(ATH_SPI_SHIFT_DO, _byte);			\
	ath_reg_wr_nf(ATH_SPI_SHIFT_CNT, (_num | _cs));		\
	do {							\
		i = ath_reg_rd(ATH_SPI_SHIFT_CNT);		\
	} while (i & 0x80000000);				\
} while (0)

#define ath_spi_delay_8(l, h)	ath_spi_bit_banger(l, h, 0)
#define ath_spi_done()		ath_reg_wr(ATH_SPI_FS, 0)

#define ath_flash_spi_down()			\
do {						\
	extern struct semaphore ath_flash_sem;	\
	down(&ath_flash_sem);			\
} while (0)

#define ath_flash_spi_up()			\
do {						\
	extern struct semaphore ath_flash_sem;	\
	up(&ath_flash_sem);			\
} while (0)

#define ath_spi_fs(x)	ath_reg_wr(ATH_SPI_FS, x)


#endif /*_ATH_SPI_H*/
