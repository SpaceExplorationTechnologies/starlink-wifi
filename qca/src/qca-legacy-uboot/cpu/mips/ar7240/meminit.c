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
#include <common.h>
#include <asm/addrspace.h>
#include "ar7240_soc.h"

#ifdef COMPRESSED_UBOOT
#	define prmsg(...)
#else
#	define prmsg	printf
#endif

uint8_t     tap_settings[] = 
            {0x40, 0x41, 0x10, 0x12, 0x13, 0x15, 0x1a, 0x1c, 0x1f, 0x2f, 0x3f};

uint16_t    tap_pattern[] = {0xa5, 0xb6, 0xc7, 0xd8};

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
#define AR7240_DDR_SIZE_INCR    (4*1024*1024)
int
ar7240_ddr_find_size(void)
{
    uint8_t  *p = (uint8_t *)KSEG1, pat = 0x77;
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

#ifndef CONFIG_WASP
void
ar7240_ddr_initial_config(uint32_t refresh)
{
	int ddr2 = 0,ddr_config;
	int ddr_config2,ext_mod,ddr2_ext_mod;
	int mod_val,mod_val_init;

	prmsg("\nsri\n");
#if 0
	ar7240_reg_wr(AR7240_RESET, AR7240_RESET_DDR);
	udelay(10);
#endif
	ddr2 = ((ar7240_reg_rd(0xb8050020) & 0x1) == 0);
#ifdef ENABLE_DYNAMIC_CONF
	if(*(volatile int *)CFG_DDR_MAGIC_F == CFG_DDR_MAGIC){
		ddr_config = CFG_DDR_CONFIG_VAL_F;
		ddr_config2 = CFG_DDR_CONFIG2_VAL_F;
		ext_mod = CFG_DDR_EXT_MODE_VAL_F;
		ddr2_ext_mod = ext_mod;
	}
	else
#endif
	{
#ifdef CONFIG_SUPPORT_AR7241
		if (is_ar7241() || is_ar7242()) {
			if (ddr2) {
				prmsg("%s(%d): virian ddr2 init\n", __func__, __LINE__);
				ddr_config	= CFG_7241_DDR2_CONFIG_VAL;
				ddr_config2	= CFG_7241_DDR2_CONFIG2_VAL;
				ext_mod		= CFG_7241_DDR2_EXT_MODE_VAL;
				ddr2_ext_mod	= CFG_DDR2_EXT_MODE_VAL;
				mod_val_init	= CFG_7241_DDR2_MODE_VAL_INIT;
				mod_val		= CFG_7241_DDR2_MODE_VAL;
			} else {
				prmsg("%s(%d): virian ddr1 init\n", __func__, __LINE__);
				ddr_config	= CFG_7241_DDR1_CONFIG_VAL;
				ddr_config2	= CFG_7241_DDR1_CONFIG2_VAL;
				ext_mod		= CFG_7241_DDR1_EXT_MODE_VAL;
				ddr2_ext_mod	= CFG_DDR2_EXT_MODE_VAL;
				mod_val_init	= CFG_7241_DDR1_MODE_VAL_INIT;
				mod_val		= CFG_7241_DDR1_MODE_VAL;
			}
		}
		else
#endif
		{
			prmsg("%s(%d): python ddr init\n", __func__, __LINE__);
			ddr_config = CFG_DDR_CONFIG_VAL;
			ddr_config2 = CFG_DDR_CONFIG2_VAL;
			ext_mod = CFG_DDR_EXT_MODE_VAL;
#ifndef CONFIG_WASP_EMU
			ddr2_ext_mod = CFG_DDR2_EXT_MODE_VAL;
#endif
			mod_val_init = CFG_DDR_MODE_VAL_INIT;
			mod_val = CFG_DDR_MODE_VAL;
		}
	}

	if (ddr2) {
		ar7240_reg_wr_nf(0xb800008c, 0xA59);
		udelay(100);
		ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x10);
		udelay(10);
		ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x20);
		udelay(10);
	}

	ar7240_reg_wr_nf(AR7240_DDR_CONFIG, ddr_config);
	udelay(100);
	ar7240_reg_wr_nf(AR7240_DDR_CONFIG2, ddr_config2 | 0x80);
	udelay(100);
	ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x8);
	udelay(10);

	ar7240_reg_wr_nf(AR7240_DDR_MODE, mod_val_init);
	udelay(1000);

	ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x1);
	udelay(10);

	if (ddr2) {
		ar7240_reg_wr_nf(AR7240_DDR_EXT_MODE, ddr2_ext_mod);
	} else {
		ar7240_reg_wr_nf(AR7240_DDR_EXT_MODE, ext_mod);
	}

	udelay(100);
	ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x2);
	udelay(10);
	ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x8);
	udelay(10);
	ar7240_reg_wr_nf(AR7240_DDR_MODE, mod_val);
	udelay(100);
	ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x1);
	udelay(10);
	ar7240_reg_wr_nf(AR7240_DDR_REFRESH, refresh);
	udelay(100);
	ar7240_reg_wr_nf(AR7240_DDR_RD_DATA_THIS_CYCLE,
				CFG_DDR_RD_DATA_THIS_CYCLE_VAL);
	udelay(100);
}
#else
int /* ram type */
wasp_ddr_initial_config(uint32_t refresh)
{
#if !defined(CONFIG_ATH_NAND_BR)
	int		ddr_config, ddr_config2, ext_mod, mod_val,
			mod_val_init, cycle_val, tap_val, type;
	uint32_t	*pll = (unsigned *)PLL_CONFIG_VAL_F;

	prmsg("\nsri\n");
	prmsg("Wasp 1.%d\n", ar7240_reg_rd(AR7240_REV_ID) & 0xf);

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
		prmsg("%s(%d): Wasp sdram\n", __func__, __LINE__);
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

		prmsg("%s(%d): (", __func__, __LINE__);
		if (ar7240_reg_rd(AR7240_REV_ID) & 0xf) {
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
		prmsg("%s(%d): Wasp (16bit) ddr1 init\n", __func__, __LINE__);
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
#if 0
	if (*pll == PLL_MAGIC) {
		uint32_t cas = pll[5];
		if (cas == 3 || cas == 4) {
			cas = (cas * 2) + 1;
			ddr_config &= ~(DDR_CONFIG_CAS_LATENCY_MSB_MASK |
					DDR_CONFIG_CAS_LATENCY_MASK);
			ddr_config |= DDR_CONFIG_CAS_LATENCY_SET(cas & 0x7) |
				DDR_CONFIG_CAS_LATENCY_MSB_SET((cas >> 3) & 1);

			cas = pll[5];

			ddr_config2 &= ~DDR_CONFIG2_GATE_OPEN_LATENCY_MASK;
			ddr_config2 |= DDR_CONFIG2_GATE_OPEN_LATENCY_SET(2 * cas);

			if (type == 1) {
				uint32_t tmp;
				tmp = ar7240_reg_rd(AR7240_DDR_DDR2_CONFIG);
				tmp &= ~DDR2_CONFIG_DDR2_TWL_MASK;
				tmp |= DDR2_CONFIG_DDR2_TWL_SET(cas == 3 ? 3 : 5);
				ar7240_reg_wr_nf(AR7240_DDR_DDR2_CONFIG, tmp);
			}

			mod_val = (cas == 3 ? 0x33 : 0x43);
			mod_val_init = 0x100 | mod_val;
		}
	}
#else
	if (*pll == PLL_MAGIC) {
		uint32_t cas = pll[5];
		if (cas == 3 || cas == 4) {
			cas = (cas * 2) + 2;
			ddr_config &= ~(DDR_CONFIG_CAS_LATENCY_MSB_MASK |
					DDR_CONFIG_CAS_LATENCY_MASK);
			ddr_config |= DDR_CONFIG_CAS_LATENCY_SET(cas & 0x7) |
				DDR_CONFIG_CAS_LATENCY_MSB_SET((cas >> 3) & 1);

			cas = pll[5];

			ddr_config2 &= ~DDR_CONFIG2_GATE_OPEN_LATENCY_MASK;
			ddr_config2 |= DDR_CONFIG2_GATE_OPEN_LATENCY_SET((2 * cas) + 1);

			if (type == 1) {
				uint32_t tmp;
				tmp = ar7240_reg_rd(AR7240_DDR_DDR2_CONFIG);
				tmp &= ~DDR2_CONFIG_DDR2_TWL_MASK;
				tmp |= DDR2_CONFIG_DDR2_TWL_SET(cas == 3 ? 3 : 5);
				ar7240_reg_wr_nf(AR7240_DDR_DDR2_CONFIG, tmp);
			}

			mod_val = (cas == 3 ? 0x33 : 0x43);
			mod_val_init = 0x100 | mod_val;
		}
	}
#endif

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

	if (ar7240_reg_rd(AR7240_REV_ID) & 0xf) {
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
		prmsg("%s(%d): Wasp ddr init done\n", __func__, __LINE__);

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
#endif

#ifdef CONFIG_HORNET_EMU
void
ar7240_ddr_initial_config_for_fpga(void)
{
 #ifdef CONFIG_HORNET_EMU_HARDI
    /* HARDI FPGA board */
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x4);          /* Auto-Refresh */
    udelay(10);      
    ar7240_reg_wr_nf(AR7240_DDR_REFRESH, 0x4100);
    udelay(10);  
        
    ar7240_reg_wr_nf(AR7240_DDR_CONFIG, 0x7fd68cd0);    /* Cas Latency 7 */
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_CONFIG2, 0x959ec6a8);   /* Gate Open 5 */
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_DDR2_CONFIG, 0x858);    /* Disable DDR2, set Write Latency */
    udelay(10);    
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x8);          /* precharge all */
    udelay(10);       
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x8);          /* precharge all */
    udelay(10);       
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x1);          /* MR update */
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_MODE, 0x133);           /* Mode Word Settings  */
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_EXT_MODE, 0x0);         /* Extended Mode Word Settings */
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_RD_DATA_THIS_CYCLE, 0xff);  /* DDR read data capture bit mask */
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x1);          /* MR update */
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x2);          /* EMR update */
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x8);          /* precharge all */
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x8);          /* precharge all */
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x4);          /* Auto-Refresh */
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x4);          /* Auto-Refresh */
    udelay(10);        
    ar7240_reg_wr_nf(AR7240_DDR_MODE, 0x133);           /* Mode Word Settings  */
    udelay(10);    
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x1);          /* MR update */    
    udelay(10); 
    ar7240_reg_wr_nf(AR7240_DDR_EXT_MODE, 0x382);       /* Extended Mode Word Settings */     
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x2);          /* EMR update */
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_EXT_MODE, 0x402);       /* Extended Mode Word Settings */     
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x2);          /* EMR update */
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_MODE, 0x33);            /* Mode Word Settings  */
    udelay(10);    
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x1);          /* MR update */    
    udelay(10);
    #ifdef CONFIG_HORNET_EMU_HARDI_WLAN
    /* 
     * Emulation board reference clock is 48 MHz(20.833ns)
     * DDR request 64ms has 8192 refresh
     * So each refresh interval is 64ms/8192 = 7812.5 ns
     * i.e ddr have to refresh in 7812.5/20.833 = 375 = 0x177 clock cycles     
     */
    ar7240_reg_wr_nf(AR7240_DDR_REFRESH, 0x4177);
    #else
    /* 
     * Emulation board reference clock is 80 MHz(12.5ns)
     * DDR request 64ms has 8192 refresh
     * So each refresh interval is 64ms/8192 = 7812.5 ns
     * i.e ddr have to refresh in 7812.5/12.5 = 625 = 0x271 clock cycles
     */
    ar7240_reg_wr_nf(AR7240_DDR_REFRESH, 0x4271);
    #endif
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_TAP_CONTROL0, 0x0);
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_TAP_CONTROL1, 0x0);
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_TAP_CONTROL2, 0x0);
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_TAP_CONTROL3, 0x0);
    udelay(10);
 #else
    /* EBU FPGA board */
    ar7240_reg_wr_nf(AR7240_DDR_CONFIG, 0xc7bc8cd0); /* Cas Latency 8 */
    udelay(100);
    ar7240_reg_wr_nf(AR7240_DDR_CONFIG2, 0x95d0e6a8); /* Gate Open 5 */
    udelay(100);
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x8);
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_MODE, 0x123);
    udelay(100);
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x1);
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_EXT_MODE, 0x1);
    udelay(100);
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x2);
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x8);
    udelay(10);
    ar7240_reg_wr_nf(AR7240_DDR_MODE, 0x23);
    udelay(100);
    ar7240_reg_wr_nf(AR7240_DDR_CONTROL, 0x1);
    udelay(10);
    /* 
     * Emulation board reference clock is 80 MHz(12.5ns)
     * DDR request 64ms has 8192 refresh
     * So each refresh interval is 64ms/8192 = 7812.5 ns
     * i.e ddr have to refresh in 7812.5/12.5 = 625 = 0x271 clock cycles     
     */
    ar7240_reg_wr_nf(AR7240_DDR_REFRESH, 0x4271);
    udelay(100);
    ar7240_reg_wr_nf(AR7240_DDR_RD_DATA_THIS_CYCLE, 0x00ff);
    udelay(100);
 #endif
}
#endif
