/*
 * Copyright (c) 2016 The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef __SPI_PROG_H__
#define __SPI_PROG_H__
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

#define AR7100_SPI_FS           0x1f000000
#define AR7100_SPI_CLOCK        0x1f000004
#define AR7100_SPI_WRITE        0x1f000008
#define AR7100_SPI_RD_STATUS    0x1f00000c

#define AR7100_SPI_READ         0x1f000000

#define AR7100_SPI_CS_DIS       0x70000
#define AR7100_SPI_CE_LOW       0x60000
#define AR7100_SPI_CE_HIGH      0x60100

#define AR7100_SPI_CMD_WREN         0x06
#define AR7100_SPI_CMD_RD_STATUS    0x05
#define AR7100_SPI_CMD_FAST_READ    0x0b
#define AR7100_SPI_CMD_PAGE_PROG    0x02
#define AR7100_SPI_CMD_SECTOR_ERASE 0xd8
#define AR7100_SPI_CMD_CHIP_ERASE   0xc7

#define AR7100_SPI_SECTOR_SIZE      (1024*64)
#define AR7100_SPI_PAGE_SIZE        256

#define SPI_CLOCK_DIVIDER	3
#define INFO_ADDR	0xa0000010
#define INFO_STAGE0	0xdeed0000
#define INFO_STAGE1	0xdeed0001
#define INFO_STAGE2	0xdeed0002
#define INFO_PASS	0x500ddeed
#define INFO_FAIL	0xdeadbeef

/*
 * Free Programming Setting (for prog_free)
 *  example : erase 0x9f130000 +0xb0000
 *            tftp 0x80060000 vmlinux.lzma.uImage
 *            cp.b $fileaddr 0x9f130000 $filesize
 *            -> Set *(unsigned int *)(FREE_PROG_FLASH_ADDR_LOC)= 0x00130000 and
 *            -> Set *(unsigned int *)(FREE_PROG_FLASH_SIZE_LOC)= 0x000b0000 by ICE before program is run
 */
#define FREE_PROG_FLASH_ADDR_LOC    0xa0000000
#define FREE_PROG_FLASH_SIZE_LOC    0xa0000004

/*
 * Source (DDR) Address and Size in Octet
 */
#define PROG_DATA_ADDR  (KSEG1 + RESERVED_SEGMENT_SIZE)
#define PROG_DATA_SIZE  (64*1024)


#define KSEG1ADDR(_x)   (0xa0000000 | (_x))
#define ar7100_reg_rd(_phys)    (*(volatile uint32_t *)KSEG1ADDR(_phys))

#define ar7100_reg_wr(_phys, _val) do {     \
    ((*(volatile uint32_t *)KSEG1ADDR(_phys)) = (_val)); \
}while(0);

/*
 * primitives
 */

#define ar7100_be_msb(_val, _i) (((_val) & (1 << (7 - _i))) >> (7 - _i))

#define ar7100_spi_bit_banger(_byte)  do {        \
    int i;                                      \
    for(i = 0; i < 8; i++) {                    \
        ar7100_reg_wr(AR7100_SPI_WRITE,      \
                        AR7100_SPI_CE_LOW | ar7100_be_msb(_byte, i));  \
        ar7100_reg_wr(AR7100_SPI_WRITE,      \
                        AR7100_SPI_CE_HIGH | ar7100_be_msb(_byte, i)); \
    }       \
}while(0);

#define ar7100_spi_go() do {        \
    ar7100_reg_wr(AR7100_SPI_WRITE, AR7100_SPI_CE_LOW); \
    ar7100_reg_wr(AR7100_SPI_WRITE, AR7100_SPI_CS_DIS); \
}while(0);


#define ar7100_spi_send_addr(_addr) do {                    \
    ar7100_spi_bit_banger(((addr & 0xff0000) >> 16));                 \
    ar7100_spi_bit_banger(((addr & 0x00ff00) >> 8));                 \
    ar7100_spi_bit_banger(addr & 0x0000ff);                 \
}while(0);

#define ar7100_spi_delay_8()    ar7100_spi_bit_banger(0)
#endif
