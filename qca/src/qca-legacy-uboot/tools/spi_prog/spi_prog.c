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
#include <defines.h>
#include "spi_prog.h"

static int              enable_remap = 0;

void
ar7100_spi_write_enable(void)
{
    ar7100_reg_wr(AR7100_SPI_FS, 1);
    ar7100_reg_wr(AR7100_SPI_WRITE, AR7100_SPI_CS_DIS);
    ar7100_spi_bit_banger(AR7100_SPI_CMD_WREN);
    ar7100_spi_go();
}

void
ar7100_spi_poll(void)
{
    int rd;

    do {
        ar7100_reg_wr(AR7100_SPI_WRITE, AR7100_SPI_CS_DIS);
        ar7100_spi_bit_banger(AR7100_SPI_CMD_RD_STATUS);
        ar7100_spi_delay_8();
        rd = (ar7100_reg_rd(AR7100_SPI_RD_STATUS) & 1);
    }while(rd);
}

void
ar7100_spi_sector_erase(uint32_t addr)
{
    ar7100_spi_write_enable();
    ar7100_spi_bit_banger(AR7100_SPI_CMD_SECTOR_ERASE);
    ar7100_spi_send_addr(addr);
    ar7100_spi_go();
    ar7100_spi_poll();
}

void
ar7100_spi_chip_erase(void)
{
    ar7100_spi_write_enable();
    ar7100_spi_bit_banger(AR7100_SPI_CMD_CHIP_ERASE);
    ar7100_spi_go();
    ar7100_spi_poll();
}

void
ar7100_spi_write_page(uint32_t addr, uint8_t *data, int len)
{
    int i;
    uint8_t ch;

    ar7100_spi_write_enable();
    ar7100_spi_bit_banger(AR7100_SPI_CMD_PAGE_PROG);
    ar7100_spi_send_addr(addr);

    for(i = 0; i < len; i++) {
        ch = *(data + i);
        ar7100_spi_bit_banger(ch);
    }

    ar7100_spi_go();
    ar7100_spi_poll();
}

void
ar7100_spi_read(uint32_t addr, uint32_t *data, int len)
{
    int i = 0, val;

    ar7100_reg_wr(AR7100_SPI_FS, 0);

    return;
    for(i = 0; i < len; i++)
        val = ar7100_reg_rd(AR7100_SPI_READ + addr + i);
}

/*
 * 1. Calculate number of sectors this write spans
 * 2. Erase 'em
 * 3. call page programming for every 256 bytes
 */

void ar7100_spi_write(uint32_t addr, uint8_t *data, int len)
{
    int i, nsect, total = 0, lenthislp;

    nsect = len/AR7100_SPI_SECTOR_SIZE;
    if (len % AR7100_SPI_SECTOR_SIZE)
        nsect ++;

    int  base_addr;

    base_addr = addr % AR7100_SPI_SECTOR_SIZE;
    base_addr = addr - base_addr;

    if ( (base_addr + nsect*AR7100_SPI_SECTOR_SIZE) < (addr + len) )
	nsect ++;

    for (i = 0; i < nsect; i++) {
	ar7100_spi_sector_erase(base_addr + i * AR7100_SPI_SECTOR_SIZE);
	}

    i = 0;
    do {
        lenthislp = (len - total) > AR7100_SPI_PAGE_SIZE ?
                    AR7100_SPI_PAGE_SIZE : (len - total);

        ar7100_spi_write_page(addr + total, data + total, lenthislp);

        total += lenthislp;
    }while(total < len);
}

void
ar7100_spi_init(uint32_t remap)
{
    uint32_t    set_val, val;

    ar7100_reg_wr(AR7100_SPI_FS, 0x1);

    if (remap)
        set_val = 0x0; /* Remap 4MB space over */
    else
        set_val = 0x40;

    set_val |= SPI_CLOCK_DIVIDER;

    ar7100_reg_wr(AR7100_SPI_CLOCK, set_val);

    val = ar7100_reg_rd(AR7100_SPI_CLOCK);

    if (val == set_val) {
        ar7100_reg_wr( (INFO_ADDR+0x00000020), set_val );
        ar7100_reg_wr( (INFO_ADDR+0x00000024), val );
    }
    else {
        ar7100_reg_wr( (INFO_ADDR+0x00000020), set_val );
        ar7100_reg_wr( (INFO_ADDR+0x00000024), val );
    }

    ar7100_reg_wr(AR7100_SPI_FS, 0x0);
}

int
ar7100_spi_check(uint32_t addr, uint32_t *data, int len)
{
    ar7100_reg_wr(AR7100_SPI_FS,0);
    int i = 0, flag = 1;
    uint32_t val,t;

    if (enable_remap) {
        val = ar7100_reg_rd( (0x1f000000 | addr) + 32 );
    }

    do{
        val = ar7100_reg_rd( (0x1f000000 | addr) + 4*i );
        t = *(data+i);
        if (val != t)
        {
           flag = 0;
           ar7100_reg_wr( (INFO_ADDR+0x00000004), 0xdeadc0de );
           ar7100_reg_wr( (INFO_ADDR+0x00000008), (0x1f000000 | addr) + 4*i);
           ar7100_reg_wr( (INFO_ADDR+0x0000000c), val);
           ar7100_reg_wr( (INFO_ADDR+0x00000010), t);
           return 1;
        }
        i = i + 1;
    }while ((i < len) && (flag));

    ar7100_reg_wr( (INFO_ADDR+0x00000004), 0x500ddeed );
    return 0;
}

int
flash_program_test(uint32_t flash_addr, uint32_t data_addr, int data_size)
{
    ar7100_spi_write(flash_addr, (uint8_t *)data_addr, data_size);

    return ar7100_spi_check(flash_addr, (uint32_t *)data_addr, data_size/4);
}

void
spi_prog(void)
{
    unsigned int    i;
    unsigned int    flash_prog_addr, flash_prog_size;
    int             ret_val;


    for (i = 0; i < 0x30; i += 4)
        *(unsigned int *)(INFO_ADDR + i) = 0x0;

    *(unsigned int *)(INFO_ADDR) = INFO_STAGE0;
    *(unsigned int *)(INFO_ADDR) = INFO_STAGE1;

    enable_remap = 0;
    ar7100_spi_init(enable_remap);

    *(unsigned int *)(INFO_ADDR) = INFO_STAGE2;

    flash_prog_addr = *(unsigned int *)(FREE_PROG_FLASH_ADDR_LOC);
    flash_prog_size = *(unsigned int *)(FREE_PROG_FLASH_SIZE_LOC);

    ret_val = flash_program_test(flash_prog_addr, PROG_DATA_ADDR, flash_prog_size);

    if (ret_val) {
        *(unsigned int *)(INFO_ADDR) = INFO_FAIL;
        while (1)   ;
    }
    else {
        *(unsigned int *)(INFO_ADDR) = INFO_PASS;
        while (1)   ;
    }
}


