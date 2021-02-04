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

#ifndef _FLASH_H
#define _FLASH_H

#include "ar7240_soc.h"

#define AR7240_SPI_FS           0x1f000000
#define AR7240_SPI_CLOCK        0x1f000004
#define AR7240_SPI_WRITE        0x1f000008
#define AR7240_SPI_READ         0x1f000000
#define AR7240_SPI_RD_STATUS    0x1f00000c

#define AR7240_SPI_CS_DIS       0x70000
#define AR7240_SPI_CE_LOW       0x60000
#define AR7240_SPI_CE_HIGH      0x60100

#define AR7240_SPI_CMD_WRITE_SR     0x01
#define AR7240_SPI_CMD_WREN         0x06
#define AR7240_SPI_CMD_RD_STATUS    0x05
#define AR7240_SPI_CMD_FAST_READ    0x0b
#define AR7240_SPI_CMD_PAGE_PROG    0x02
#define AR7240_SPI_CMD_SECTOR_ERASE 0xd8
#define AR7240_SPI_CMD_CHIP_ERASE   0xc7
#define AR7240_SPI_CMD_RDID         0x9f

#define AR7240_SPI_SECTOR_SIZE      (1024*64)
#define AR7240_SPI_PAGE_SIZE        256


#define display(_x)     ar7240_reg_wr_nf(0x18040008, (_x))

/*
 * primitives
 */

#define ar7240_be_msb(_val, _i) (((_val) & (1 << (7 - _i))) >> (7 - _i))

#define ar7240_spi_bit_banger(_byte)  do {        \
    int i;                                      \
    for(i = 0; i < 8; i++) {                    \
        ar7240_reg_wr_nf(AR7240_SPI_WRITE,      \
                        AR7240_SPI_CE_LOW | ar7240_be_msb(_byte, i));  \
        ar7240_reg_wr_nf(AR7240_SPI_WRITE,      \
                        AR7240_SPI_CE_HIGH | ar7240_be_msb(_byte, i)); \
    }       \
}while(0);

#define ar7240_spi_go() do {        \
    ar7240_reg_wr_nf(AR7240_SPI_WRITE, AR7240_SPI_CE_LOW); \
    ar7240_reg_wr_nf(AR7240_SPI_WRITE, AR7240_SPI_CS_DIS); \
}while(0);


#define ar7240_spi_send_addr(__a) do {			\
    ar7240_spi_bit_banger(((__a & 0xff0000) >> 16));	\
    ar7240_spi_bit_banger(((__a & 0x00ff00) >> 8));	\
    ar7240_spi_bit_banger(__a & 0x0000ff);		\
} while (0)

#define ar7240_spi_delay_8()    ar7240_spi_bit_banger(0)
#define ar7240_spi_done()       ar7240_reg_wr_nf(AR7240_SPI_FS, 0)

extern unsigned long flash_get_geom (flash_info_t *flash_info);

#endif /*_FLASH_H*/
