/*
 * Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <asm/types.h>
#include <asm/addrspace.h>
#include <apb_map.h>
#include <ath_chip.h>
#include <fwd.h>
#include "rom.addrs.h"

void (*serial_puts) (const char *s);
int (*printf) (const char *fmt, ...);
void (*udelay) (unsigned long usec);
void (*simple_mips_cache_reset)(void);
void (*call_fw)(u32, u32);

#ifdef CONFIG_ATH_EMULATION
void ath_emu_mem_config(u32);
#else
int ath_mem_config(void);
int pci_init_board (void);
#endif
void gmac_fwd_main(void);

extern int bss_start, bss_end;	// declared in linker script

void
drv_main(void)
{
	int	interface, ver, *bss;
	extern	bootrom_fn_t bootrom_fn[];
	extern	void lowlevel_init(void);

	ver = ath_reg_rd(RST_REVISION_ID_ADDRESS) & 0xf;

	/* clear bss */
	for (bss = &bss_start; bss <= &bss_end; bss ++) {
		*bss = 0;
	}

	serial_puts		= bootrom_fn[ver].serial_puts;
	printf			= bootrom_fn[ver].printf;
	udelay			= bootrom_fn[ver].udelay;
	simple_mips_cache_reset	= bootrom_fn[ver].simple_mips_cache_reset;
	call_fw			= bootrom_fn[ver].call_fw;

	simple_mips_cache_reset();
	interface = RST_BOOTSTRAP_BOOT_INTF_SEL_GET
				(ath_reg_rd(RST_BOOTSTRAP_ADDRESS));

	ath_reg_wr(ATH_SPI_CLOCK, 0x246);

#if 1
#ifdef CONFIG_ATH_EMULATION
	serial_puts("initialize DDR\n");
	ath_emu_mem_config(interface);
#else
	serial_puts("initialize PLL & DDR\n");
	lowlevel_init();
	ath_mem_config();
	serial_puts("... done\n");

	pci_init_board();
#endif
#else
	serial_puts("dont init PLL & DDR\n");
#endif

	serial_puts("... done\n");

	switch (interface) {
	case HIF_USB:
		serial_puts("fw1: USB Init\n");
		break;
	case HIF_PCIE:
		serial_puts("fw1: PCIe Init\n");
		break;
	case HIF_GMAC:
		serial_puts("fw1: GMAC Init\n");
		gmac_fwd_main();
		break;
	case HIF_NAND:
		serial_puts("fw1: Nand Init\n");
		break;
	}

	 serial_puts("leave FW1\n");
}
