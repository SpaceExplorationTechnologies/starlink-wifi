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

/*
 * Memory controller config:
 * Assumes that the caches are initialized.
 *
 * 0) Figah out the Tap controller settings.
 * 1) Figure out whether the interface is 16bit or 32bit.
 * 2) Size the DRAM
 *
 *  0) Tap controller settings
 *  --------------------------
 * The Table below provides all possible values of TAP controllers. We need to
 * find the extreme left and extreme right of the spectrum (of max_udelay and
 * min_udelay). We then program the TAP to be in the middle.
 * Note for this we would need to be able to read and write memory. So,
 * initially we assume that a 16bit interface, which will always work unless
 * there is exactly _1_ 32 bit part...for now we assume this is not the case.
 *
 * The algo:
 * 0) Program the controller in 16bit mode.
 * 1) Start with the extreme left of the table
 * 2) Write 0xa4, 0xb5, 0xc6, 0xd7 to 0, 2, 4, 6
 * 3) Read 0 - this will fetch the entire cacheline.
 * 4) If the value at address 4 is good, record this table entry, goto 6
 * 5) Increment to get the next table entry. Goto 2.
 * 6) Start with extreme right. Do the same as above.
 *
 * 1) 16bit or 32bit
 * -----------------
 *  31st bit of reg 0x1800_0000 will  determine the mode. By default,
 *  controller is set to 32-bit mode. In 32 bit mode, full data bus DQ [31:0]
 *  will be used to write 32 bit data. Suppose you have 16bit DDR memory
 *  (it will have 16bit wide data bus). If you try to write 16 bit DDR in 32
 *  bit mode, you are going to miss upper 16 bits of data. Reading to that
 *  location will give you only lower 16 bits correctly, upper 16 bits will
 *  have some junk value. E.g.,
 *
 *  write to 0x0000_0000 0x12345678
 *  write to 0x0000_1000 0x00000000 (just to discharge DQ[31:16] )
 *  read from 0x0000_0000
 *  if u see something like 0x0000_5678 (or XXXX_5678 but not equal to
 *  0x12345678) - its a 16 bit interface
 *
 *  2) Size the DRAM
 *  -------------------
 *  DDR wraps around. Write a pattern to 0x0000_0000. Write an address
 *  pattern at 4M, 8M, 16M etc. and check when 0x0000_0000 gets overwritten.
 *
 *
 *  We can use #define's for all these addresses and patterns but its easier
 *  to see what's going on without :)
 */
#include <asm/types.h>
#include <asm/addrspace.h>
#include <ar934x_soc.h>
#include "dt_defs.h"
#include "rom.addrs.h"

#define uint8_t		__u8
#define uint16_t	__u16
#define uint32_t	__u32

//#define CONFIG_HORNET_EMU_EBU 1
uint8_t tap_settings[] =
	{0x40, 0x41, 0x10, 0x12, 0x13, 0x15, 0x1a, 0x1c, 0x1f, 0x2f, 0x3f};

uint16_t tap_pattern[] = {0xa5, 0xb6, 0xc7, 0xd8};

#define printf		serial_puts

void
ar7240_ddr_tap_set(uint8_t set)
{
	ar7240_reg_wr_nf(AR7240_DDR_TAP_CONTROL0, set);
	ar7240_reg_wr_nf(AR7240_DDR_TAP_CONTROL1, set);
	ar7240_reg_wr_nf(AR7240_DDR_TAP_CONTROL2, set);
	ar7240_reg_wr_nf(AR7240_DDR_TAP_CONTROL3, set);
}

/*
 * We check for size in 4M increments
 */
#define AR7240_DDR_SIZE_INCR	(4*1024*1024)
int
ar7240_ddr_find_size(void)
{
	uint8_t	*p = (uint8_t *)KSEG1, pat = 0x77;
	int i;

	*p = pat;

	for(i = 1; ; i++) {
		*(p + i * AR7240_DDR_SIZE_INCR) = (uint8_t)(i);
		if (*p != pat) {
			break;
		}
	}

	return (i*AR7240_DDR_SIZE_INCR);
}

void
wasp_usb_initial_config(void)
{
#define unset(a)	(~(a))
	// Only for 25 MHz ref clk
	if ((ar7240_reg_rd(WASP_BOOTSTRAP_REG) & WASP_REF_CLK_25) == 0) {
		ar7240_reg_wr_nf(AR934X_SWITCH_CLOCK_SPARE,
			ar7240_reg_rd(AR934X_SWITCH_CLOCK_SPARE) |
			SWITCH_CLOCK_SPARE_USB_REFCLK_FREQ_SEL_SET(2));
		serial_puts("setting for 25\n");
	} else {
		ar7240_reg_wr_nf(AR934X_SWITCH_CLOCK_SPARE,
			ar7240_reg_rd(AR934X_SWITCH_CLOCK_SPARE) |
			SWITCH_CLOCK_SPARE_USB_REFCLK_FREQ_SEL_SET(5));
		serial_puts("setting for 40\n");
	}
	udelay(1000);
	ar7240_reg_wr(AR7240_RESET,
		ar7240_reg_rd(AR7240_RESET) |
		RST_RESET_USB_PHY_SUSPEND_OVERRIDE_SET(1));
	udelay(1000);
	ar7240_reg_wr(AR7240_RESET,
		ar7240_reg_rd(AR7240_RESET) &
		unset(RST_RESET_USB_PHY_RESET_SET(1)));
	udelay(1000);
	ar7240_reg_wr(AR7240_RESET,
		ar7240_reg_rd(AR7240_RESET) &
		unset(RST_RESET_USB_PHY_ARESET_SET(1)));
	udelay(1000);
	ar7240_reg_wr(AR7240_RESET,
		ar7240_reg_rd(AR7240_RESET) &
		unset(RST_RESET_USB_HOST_RESET_SET(1)));
	udelay(1000);
	if ((ar7240_reg_rd(RST_REVISION_ID_ADDRESS) & 0xf) == 0) {
		/* Only for WASP 1.0 */
		ar7240_reg_wr(0xb8116c84 ,
			ar7240_reg_rd(0xb8116c84) & unset(1<<20));
	}
}

#ifdef COMPRESSED_UBOOT
#	define prmsg(...)
#else
#	define prmsg	printf
#endif

int
wasp_ddr_initial_config(uint32_t refresh)
{
#ifndef CONFIG_WASP_EMU
	int	ddr_config, ddr_config2, ext_mod, mod_val,
		mod_val_init, cycle_val, tap_val, type;
	char	ver[] = { "0\n" };

	prmsg("\nsri\nWasp 1.");
	ver[0] += ar7240_reg_rd(RST_REVISION_ID_ADDRESS) & 0xf;
	prmsg(ver);

	switch(WASP_RAM_TYPE(ar7240_reg_rd(WASP_BOOTSTRAP_REG))) {
	case 0:
	case 1:	// SDRAM
		/*
		XXX XXX XXX XXX XXX XXX XXX XXX XXX
		Boot strap select is not working. In some boards,
		ddr2 shows up as sdram. Hence ignoring the foll.
		break statement.
		XXX XXX XXX XXX XXX XXX XXX XXX XXX
		break;
		*/
		prmsg("Wasp sdram\n");
		ddr_config	= CFG_934X_SDRAM_CONFIG_VAL;
		ddr_config2	= CFG_934X_SDRAM_CONFIG2_VAL;
		mod_val_init	= CFG_934X_SDRAM_MODE_VAL_INIT;
		mod_val		= CFG_934X_SDRAM_MODE_VAL;
		cycle_val	= CFG_SDRAM_RD_DATA_THIS_CYCLE_VAL;
		tap_val		= CFG_934X_SDRAM_TAP_VAL;

		ar7240_reg_wr_nf(AR7240_DDR_CTL_CONFIG, 0x13b);
		udelay(100);

		ar7240_reg_wr_nf(AR7240_DDR_DEBUG_RD_CNTL, 0x3000001f);
		udelay(100);

		type = 0;

		break;
	case 2: // ddr2
		ddr_config	= CFG_934X_DDR2_CONFIG_VAL;
		ddr_config2	= CFG_934X_DDR2_CONFIG2_VAL;
		ext_mod		= CFG_934X_DDR2_EXT_MODE_VAL;
		mod_val_init	= CFG_934X_DDR2_MODE_VAL_INIT;
		mod_val		= CFG_934X_DDR2_MODE_VAL;
		cycle_val	= CFG_DDR2_RD_DATA_THIS_CYCLE_VAL;
		tap_val		= CFG_934X_DDR2_TAP_VAL;

		prmsg("Wasp (");
		if (ar7240_reg_rd(RST_REVISION_ID_ADDRESS) & 0xf) {
							/* NAND Clear */
			if (ar7240_reg_rd(WASP_BOOTSTRAP_REG) & (1 << 3)) {
				prmsg("32");
				cycle_val = CFG_DDR2_RD_DATA_THIS_CYCLE_VAL_32;
				ar7240_reg_wr_nf(AR7240_DDR_CTL_CONFIG, (1 << 6));
			} else {
				prmsg("16");
				cycle_val = CFG_DDR2_RD_DATA_THIS_CYCLE_VAL_16;
				ar7240_reg_rmw_set(AR7240_DDR_CTL_CONFIG, (1 << 6));
				ar7240_reg_rmw_clear(AR7240_DDR_CTL_CONFIG, (0xf << 2));
			}
		} else {
#if DDR2_32BIT_SUPPORT
		prmsg("32");
		ar7240_reg_wr_nf(AR7240_DDR_CTL_CONFIG, 0);
#else
		prmsg("16");
#endif
		}
		prmsg("bit) ddr2 init\n");
		udelay(10);
		type = 1;

		break;
	case 3: // ddr1
		prmsg("Wasp (16bit) ddr1 init\n");
		ddr_config	= CFG_934X_DDR1_CONFIG_VAL;
		ddr_config2	= CFG_934X_DDR1_CONFIG2_VAL;
		ext_mod		= CFG_934X_DDR1_EXT_MODE_VAL;
		mod_val_init	= CFG_934X_DDR1_MODE_VAL_INIT;
		mod_val		= CFG_934X_DDR1_MODE_VAL;
		cycle_val	= CFG_DDR1_RD_DATA_THIS_CYCLE_VAL;
		tap_val		= CFG_934X_DDR1_TAP_VAL;
		type = 2;
		break;
	}

	ar7240_reg_wr_nf(AR7240_DDR_RD_DATA_THIS_CYCLE, cycle_val);
	udelay(100);
	ar7240_reg_wr_nf(AR7240_DDR_BURST, 0x74444444);
	udelay(100);
	ar7240_reg_wr_nf(AR7240_DDR_BURST2, 0x222);
	udelay(100);
	ar7240_reg_wr_nf(AR7240_AHB_MASTER_TIMEOUT, 0xfffff);
	udelay(100);
	ar7240_reg_wr_nf(AR7240_DDR_CONFIG, ddr_config);
	udelay(100);
	ar7240_reg_wr_nf(AR7240_DDR_CONFIG2, ddr_config2);
	udelay(100);
	if (type == 1) {
		ar7240_reg_wr_nf(AR7240_DDR_DDR2_CONFIG, CFG_934X_DDR2_EN_TWL_VAL);
		udelay(100);
	}
	ar7240_reg_wr_nf(AR7240_DDR_CONFIG2, ddr_config2 | 0x80); // CKE enable
	udelay(100);
	ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x8); // Precharge
	udelay(10);
	ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x8); // Precharge
	udelay(10);

	if (type == 1) {
		ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x10); // EMR2
		udelay(10);
		ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x20); // EMR3
		udelay(10);
	}
	if (type != 0) {
		ar7240_reg_wr_nf(AR7240_DDR_EXT_MODE, 0x2);
		udelay(100);
		ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x2); // EMR DLL enable
		udelay(10);
	}
	ar7240_reg_wr_nf(AR7240_DDR_MODE, mod_val_init);
	udelay(1000);

	ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x1); // MR Write
	udelay(10);

	ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x8); // Precharge
	udelay(10);
	ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x8); // Precharge
	udelay(10);
	ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x4); // Auto Refresh
	udelay(10);
	ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x4); // Auto Refresh
	udelay(10);
	ar7240_reg_wr_nf(AR7240_DDR_MODE, mod_val);
	udelay(100);
	ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x1); // MR Write
	udelay(10);
	if (type == 1) {
		ar7240_reg_wr_nf(AR7240_DDR_EXT_MODE, CFG_934X_DDR2_EXT_MODE_VAL_INIT);
		udelay(100);
		ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x2); // EMR write
		udelay(100);
		ar7240_reg_wr_nf(AR7240_DDR_EXT_MODE, CFG_934X_DDR2_EXT_MODE_VAL);
		udelay(100);
		ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x2); // EMR write
		udelay(100);
	}

	ar7240_reg_wr_nf(AR7240_DDR_REFRESH, refresh);
	udelay(100);
        ar7240_reg_wr (AR7240_DDR_TAP_CONTROL0, tap_val);
	ar7240_reg_wr (AR7240_DDR_TAP_CONTROL1, tap_val);

	if (ar7240_reg_rd(RST_REVISION_ID_ADDRESS) & 0xf) {
						/* NAND Clear */
		if ((ar7240_reg_rd(WASP_BOOTSTRAP_REG) & (1 << 3)) && type) {
			ar7240_reg_wr (AR7240_DDR_TAP_CONTROL2, tap_val);
			ar7240_reg_wr (AR7240_DDR_TAP_CONTROL3, tap_val);
		}
	} else {
#if DDR2_32BIT_SUPPORT
		if (type != 0) {
			ar7240_reg_wr (AR7240_DDR_TAP_CONTROL2, tap_val);
			ar7240_reg_wr (AR7240_DDR_TAP_CONTROL3, tap_val);
		}
#endif
	}

#if (CFG_PLL_FREQ == CFG_PLL_600_500_250) || \
    (CFG_PLL_FREQ == CFG_PLL_500_500_250)
	// PMU2 ddr ldo tune
	ar7240_reg_rmw_set(0xb8116c44, (0x3 << 19));
	udelay(100);
#endif
	return type;
#else
	return 0;
#endif
}

int
wasp_mem_config(void)
{
	unsigned int type, reg32;

	type = wasp_ddr_initial_config(CFG_DDR_REFRESH_VAL);

	/* Take WMAC out of reset */
	reg32 = ar7240_reg_rd(AR7240_RESET);
	reg32 = reg32 &  ~AR7240_RESET_WMAC;
	ar7240_reg_wr_nf(AR7240_RESET, reg32);

	/* Switching regulator settings */
	ar7240_reg_wr_nf(0x18116c40, 0x633c8176); /* AR_PHY_PMU1 */
	if (ar7240_reg_rd(RST_REVISION_ID_ADDRESS) & 0xf) {
		if (type == 2) {
			// ddr1
			ar7240_reg_wr_nf(0x18116c44, 0x10000000); /* AR_PHY_PMU2 */
		} else {
			// ddr2 & sdram
			ar7240_reg_wr_nf(0x18116c44, 0x10380000); /* AR_PHY_PMU2 */
		}
	} else {
		ar7240_reg_wr_nf(0x18116c44, 0x10380000); /* AR_PHY_PMU2 */
	}

	wasp_usb_initial_config();

	// for s27
	reg32 = ar7240_reg_rd(AR7240_RESET);
	reg32 &= (~(0x3 << 12));
#ifdef ROMBOOTDRV_DISABLE_PCIE
	reg32 |= AR7240_RESET_PCIE_PHY|AR7240_RESET_PCIE;
#endif
	ar7240_reg_wr_nf(AR7240_RESET, reg32);

	if ((ar7240_reg_rd(WASP_BOOTSTRAP_REG) & WASP_REF_CLK_25) == 0) {
		ar7240_reg_wr(0xb8050024, 0x271);
	} else {
#ifdef ROMBOOTDRV_DISABLE_PCIE
		ar7240_reg_wr_nf(0x18050024, 0x500);       // Supercore shutdown
#else
		ar7240_reg_wr(0xb8050024, 0x570);
#endif
	}

	//wasp_gpio_config();

	return (ar7240_ddr_find_size());
}
/**
 * memset - Fill a region of memory with the given value
 * @s: Pointer to the start of the area.
 * @c: The byte to fill the area with
 * @count: The size of the area.
 *
 * Do not use memset() to access IO space, use memset_io() instead.
 */
static inline void * ar7240_memset(void * s,int c,int count)
{
	char *xs = (char *) s;

	while (count--)
		*xs++ = c;

	return s;
}

