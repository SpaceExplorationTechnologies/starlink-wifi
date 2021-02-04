/*
 * (C) Copyright 2003
 * Wolfgang Denk, DENX Software Engineering, <wd@denx.de>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <command.h>
#include <asm/inca-ip.h>
#include <asm/mipsregs.h>

#if defined(CONFIG_AR7100)
#include <asm/addrspace.h>
#include <ar7100_soc.h>
#endif

#if defined(CONFIG_AR7240)
#include <asm/addrspace.h>
#include <ar7240_soc.h>
#endif

#if defined(CONFIG_ATHEROS)
#include <asm/addrspace.h>
#include <atheros.h>
#endif


int do_reset(cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
#if defined(CONFIG_ATHEROS)
	while (1) {
		ath_reg_wr(RST_RESET_ADDRESS, RST_RESET_FULL_CHIP_RESET_SET(1));
	}
#elif defined(CONFIG_INCA_IP)
	*INCA_IP_WDT_RST_REQ = 0x3f;
#elif defined(CONFIG_PURPLE) || defined(CONFIG_TB0229)
	void (*f)(void) = (void *) 0xbfc00000;

	f();
#elif defined(CONFIG_AR7100)
#ifndef COMPRESSED_UBOOT
	fprintf(stdout, "\nResetting...\n");
#endif  /* #ifndef COMPRESSED_UBOOT */
	for (;;) {
		ar7100_reg_wr(AR7100_RESET,
			(AR7100_RESET_FULL_CHIP | AR7100_RESET_DDR));
	}
#elif defined(CONFIG_AR7240)
#ifndef COMPRESSED_UBOOT
	fprintf(stdout, "\nResetting...\n");
#endif  /* #ifndef COMPRESSED_UBOOT */
	for (;;) {
#ifdef CONFIG_WASP
		if (ar7240_reg_rd(AR7240_REV_ID) & 0xf) {
			ar7240_reg_wr(AR7240_RESET,
				(AR7240_RESET_FULL_CHIP | AR7240_RESET_DDR));
		} else {
			/*
			 * WAR for full chip reset spi vs. boot-rom selection
			 * bug in wasp 1.0
			 */
			ar7240_reg_wr (AR7240_GPIO_OE,
				ar7240_reg_rd(AR7240_GPIO_OE) & (~(1 << 17)));
		}
#else
		ar7240_reg_wr(AR7240_RESET,
			(AR7240_RESET_FULL_CHIP | AR7240_RESET_DDR));
#endif
	}
#endif
#ifndef COMPRESSED_UBOOT
	fprintf(stderr, "*** reset failed ***\n");
#endif  /* #ifndef COMPRESSED_UBOOT */
	return 0;
}

void flush_cache (ulong start_addr, ulong size)
{
	u32 end, a;
    int i;

    a = start_addr & ~(CFG_CACHELINE_SIZE - 1);
    size = (size + CFG_CACHELINE_SIZE - 1) & ~(CFG_CACHELINE_SIZE - 1);
    end = a + size;

    dcache_flush_range(a, end);
}

void write_one_tlb( int index, u32 pagemask, u32 hi, u32 low0, u32 low1 ){
	write_32bit_cp0_register(CP0_ENTRYLO0, low0);
	write_32bit_cp0_register(CP0_PAGEMASK, pagemask);
	write_32bit_cp0_register(CP0_ENTRYLO1, low1);
	write_32bit_cp0_register(CP0_ENTRYHI, hi);
	write_32bit_cp0_register(CP0_INDEX, index);
	tlb_write_indexed();
}
