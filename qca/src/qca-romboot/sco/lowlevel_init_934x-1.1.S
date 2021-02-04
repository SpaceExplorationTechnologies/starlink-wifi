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

#include <config.h>
#include <version.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>
#include <asm/addrspace.h>
#include <ar934x_soc.h>

/*
 * Helper macros.
 * These Clobber t7, t8 and t9
 */
#define set_val(_reg, _mask, _val)		\
	li	t7,	KSEG1ADDR(_reg);	\
	lw	t8,	0(t7);			\
	li	t9,	~_mask;			\
	and	t8,	t8,	t9;		\
	li	t9,	_val;			\
	or	t8,	t8,	t9;		\
	sw	t8,	0(t7)

#define cpu_pll_set(_mask, _val)	\
	set_val(AR934X_CPU_PLL_CONFIG, _mask, _val)

#define ddr_pll_set(_mask, _val)	\
	set_val(AR934X_DDR_PLL_CONFIG, _mask, _val)

#define cpu_ddr_control_set(_mask, _val)	\
	set_val(AR934X_CPU_DDR_CLOCK_CONTROL, _mask, _val)

#define set_bb_pll(reg, val)		\
	li	t7,	KSEG1ADDR(reg);	\
	li	t8,	val;		\
	sw	t8,	0(t7);

#define set_srif_pll(reg, val)		\
	li	t7,	KSEG1ADDR(reg);	\
	li	t8,	val;		\
	sw	t8,	0(t7);

#define set_srif_pll_reg(reg, _r)	\
	li	t7,	KSEG1ADDR(reg);	\
	sw	_r,	0(t7);


/******************************************************************************
 * first level initialization:
 *
 * 0) If clock cntrl reset switch is already set, we're recovering from
 *    "divider reset"; goto 3.
 * 1) Setup divide ratios.
 * 2) Reset.
 * 3) Setup pll's, wait for lock.
 *
 *****************************************************************************/

.globl ar934x_1_dot_1_lowlevel_init
	.type	ar934x_1_dot_1_lowlevel_init, @function
	.text
	.align 4
ar934x_1_dot_1_lowlevel_init:

	set_bb_pll(DPLL2_ADDRESS_c4, 0x13210f00);
	set_bb_pll(DPLL3_ADDRESS_c8, 0x03000000);
	set_bb_pll(DPLL2_ADDRESS_44, 0x13210f00);
	set_bb_pll(DPLL3_ADDRESS_48, 0x03000000);
	set_bb_pll(DPLL3_ADDRESS_88, 0x03000000);

	li	t5,	KSEG1ADDR(WASP_BOOTSTRAP_REG);
	li	t6,	WASP_REF_CLK_25
	lw	t7,	0(t5);
	and	t6,	t7,	t6
	beq	zero,	t6,	setup_ref25_val
	nop
setup_ref40_val:
	li	t5,	CPU_PLL_CONFIG_NINT_VAL_40
	li	t6,	DDR_PLL_CONFIG_NINT_VAL_40
	li	t7,	CPU_PLL_NFRAC_40
	li	t9,	DDR_PLL_NFRAC_40
	b	1f
	nop

setup_ref25_val:
	li	t5,	CPU_PLL_CONFIG_NINT_VAL_25
	li	t6,	DDR_PLL_CONFIG_NINT_VAL_25
	li	t7,	CPU_PLL_NFRAC_25
	li	t9,	DDR_PLL_NFRAC_25

1:
	li	t4,	(CPU_PLL_DITHER_DITHER_EN_SET(0) | \
			CPU_PLL_DITHER_NFRAC_STEP_SET(1) | \
			CPU_PLL_DITHER_UPDATE_COUNT_SET(0xf));
	or	t4,	t4,	t7

	li	t8,	(CPU_PLL_CONFIG_REF_DIV_VAL | \
			CPU_PLL_CONFIG_RANGE_VAL | \
			CPU_PLL_CONFIG_OUT_DIV_VAL2);
	or	t5,	t5,	t8

	li	t8,	(DDR_PLL_CONFIG_REF_DIV_VAL | \
			DDR_PLL_CONFIG_RANGE_VAL | \
			DDR_PLL_CONFIG_OUT_DIV_VAL2);
	or	t6,	t6,	t8

#if 0 /* !defined(CONFIG_AP123) && !defined(CONFIG_MI124) */
	/*
	 * From: Ravi Subramanian
	 * Subject: Workaround for 5G RX reset-reset variation
	 * Date: Mon, 30 Aug 2010 12:53:49 +0530
	 *
	 * We are observing a reset to reset issue related to 5G RX
	 * performance (and EVM). As a workaround, pushing the DDR
	 * frequency from 400 MHz to 406 MHz, fixes this issue.
	 * Could you please give us a new u-boot with the following
	 * change?
	 */
	li	t3,	(DDR_PLL_DITHER_DITHER_EN_SET(1) | \
			DDR_PLL_DITHER_NFRAC_STEP_SET(1) | \
			DDR_PLL_DITHER_UPDATE_COUNT_SET(0xf));
#else
	li	t3,	(DDR_PLL_DITHER_DITHER_EN_SET(0) | \
			DDR_PLL_DITHER_NFRAC_STEP_SET(1) | \
			DDR_PLL_DITHER_UPDATE_COUNT_SET(0xf));
#endif

	or	t3,	t3,	t9
pll_bypass_set:
	cpu_ddr_control_set (CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_MASK, CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_SET(1));
	cpu_ddr_control_set (CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_MASK, CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_SET(1));
	cpu_ddr_control_set (CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_MASK, CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_SET(1));

init_cpu_pll:
	li	t7,	KSEG1ADDR(AR934X_CPU_PLL_CONFIG);
	li	t8,	CPU_PLL_CONFIG_PLLPWD_SET(1)
	or	t8,	t8,	t5
	sw	t8,	0(t7);

init_ddr_pll:
	li	t7,	KSEG1ADDR(AR934X_DDR_PLL_CONFIG);
	li	t8,	DDR_PLL_CONFIG_PLLPWD_SET(1)
	or	t8,	t8,	t6
	sw	t8,	0(t7);

init_ahb_pll:
	li	t7,	KSEG1ADDR(AR934X_CPU_DDR_CLOCK_CONTROL);
	li	t8,	(CPU_DDR_CLOCK_CONTROL_AHB_DIV_VAL | \
			CPU_DDR_CLOCK_CONTROL_AHB_CLK_DDR | \
			CPU_DDR_CLOCK_CONTROL_DDR_CLK_DDR | \
			CPU_DDR_CLOCK_CONTROL_CPU_CLK_CPU | \
			CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV | \
			CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV | \
			CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_SET(1) | \
			CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_SET(1) | \
			CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_SET(1));
	sw	t8,	0(t7);
#define cpu_from_srif	1
#define ddr_from_srif	1

pll_pwd_unset:
#if !cpu_from_srif
	cpu_pll_set(CPU_PLL_CONFIG_PLLPWD_MASK, CPU_PLL_CONFIG_PLLPWD_SET(0));
#endif
#if !ddr_from_srif
	ddr_pll_set(DDR_PLL_CONFIG_PLLPWD_MASK, DDR_PLL_CONFIG_PLLPWD_SET(0));
#endif

srif_set:
	/* Use built in values, based on ref clock */
	li	t5,	KSEG1ADDR(WASP_BOOTSTRAP_REG);
	li	t6,	WASP_REF_CLK_25
	lw	t7,	0(t5);
	and	t6,	t7,	t6
	beq	zero,	t6,	1f
	nop
#if !defined(CONFIG_AP123)
	/*		refdiv		nint		nfrac */
#if cpu_from_srif
	li	t4,	((0x8 << 27) | (112 << 18) | 0);// cpu freq = (40 MHz refclk/refdiv 8) * Nint
#endif
#if ddr_from_srif
#ifdef CONFIG_ATH_NAND_SUPPORT
	li	t5,	((0x8 << 27) | (160 << 18) | 0);// ddr freq = (40 MHz refclk/refdiv 8) * Nint
#else
	li	t5,	((0x8 << 27) | (96 << 18) | 0);	// ddr freq = (40 MHz refclk/refdiv 8) * Nint
#endif /* CONFIG_ATH_NAND_SUPPORT */
#endif
	j	2f
	nop
1:
#if cpu_from_srif
	li	t4,	((0x5 << 27) | (112 << 18) | 0);// cpu freq = (25 MHz refclk/refdiv 8) * Nint
#endif
#if ddr_from_srif
#ifdef CONFIG_ATH_NAND_SUPPORT
	li	t5,	((0x5 << 27) | (160 << 18) | 0);// ddr freq = (25 MHz refclk/refdiv 5) * Nint
#else
	li	t5,	((0x5 << 27) | (96 << 18) | 0);	// ddr freq = (25 MHz refclk/refdiv 8) * Nint
#endif /* CONFIG_ATH_NAND_SUPPORT */
#endif
	j	2f
	nop
#else	/* defined(CONFIG_AP123) */
	/*		refdiv		nint		nfrac */
#if cpu_from_srif
	li	t4,	((0x8 << 27) | (107 << 18) | 0);// cpu freq = (40 MHz refclk/refdiv 5) * Nint
#endif
#if ddr_from_srif
	li	t5,	((0x8 << 27) | (80 << 18) | 0);	// ddr freq = (40 MHz refclk/refdiv 8) * Nint
#endif
	j	2f
	nop
1:
#if cpu_from_srif
	li	t4,	((0x5 << 27) | (107 << 18) | 0);// cpu freq = (25 MHz refclk/refdiv 5) * Nint
#endif
#if ddr_from_srif
	li	t5,	((0x5 << 27) | (80 << 18) | 0);	// ddr freq = (25 MHz refclk/refdiv 8) * Nint
#endif
	j	2f
	nop
#endif	/* !defined(CONFIG_AP123) */

	/* CPU */
2:
#if cpu_from_srif
	set_srif_pll(0xb81161c4, (0x4 << 26) | (0x10 << 19) | (0x1e << 7) | (1 << 16));
	set_srif_pll_reg(0xb81161c0, t4);
	set_srif_pll(0xb81161c4, (0x3 << 30) | (0x4 << 26) | (0x10 << 19) | (0x1e << 7) | (1 << 16));
	set_srif_pll(0xb81161c8, (6 << 23));
	set_srif_pll(0xb81161c4, (0x3 << 30) | (0x4 << 26) | (0x10 << 19) | (0x1e << 7));
#endif
	/* DDR */
#if ddr_from_srif
#if defined(CONFIG_ATH_NAND_SUPPORT)
	set_srif_pll(0xb8116244, (0x4 << 26) | (0x10 << 19) | (1 << 13) | (0x1e << 7) | (1 << 16));
	set_srif_pll_reg(0xb8116240, t5);
	set_srif_pll(0xb8116244, (0x1 << 30) | (0x4 << 26) | (0x10 << 19) | (1 << 13) | (0x1e << 7) | (1 << 16));
	set_srif_pll(0xb8116248, (6 << 23));
	set_srif_pll(0xb8116244, (0x1 << 30) | (0x4 << 26) | (0x10 << 19) | (1 << 13) | (0x1e << 7));
#elif !defined(CONFIG_AP123)
	set_srif_pll(0xb8116244, (0x4 << 26) | (0x10 << 19) | (0x1e << 7) | (1 << 16));
	set_srif_pll_reg(0xb8116240, t5);
	set_srif_pll(0xb8116244, (0x3 << 30) | (0x4 << 26) | (0x10 << 19) | (0x1e << 7) | (1 << 16));
	set_srif_pll(0xb8116248, (6 << 23));
	set_srif_pll(0xb8116244, (0x3 << 30) | (0x4 << 26) | (0x10 << 19) | (0x1e << 7));
#else /* defined(CONFIG_AP123) */
	/* AP123 uses outdiv = 1 for ddr pll */
	set_srif_pll(0xb8116244, (0x4 << 26) | (0x10 << 19) | (1 << 13) | (0x1e << 7) | (1 << 16));
	set_srif_pll_reg(0xb8116240, t5);
	set_srif_pll(0xb8116244, (0x1 << 30) | (0x4 << 26) | (0x10 << 19) | (1 << 13) | (0x1e << 7) | (1 << 16));
	set_srif_pll(0xb8116248, (6 << 23));
	set_srif_pll(0xb8116244, (0x1 << 30) | (0x4 << 26) | (0x10 << 19) | (1 << 13) | (0x1e << 7));
#endif /* !defined(CONFIG_AP123) */
#endif

pll_bypass_unset:
	cpu_ddr_control_set (CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_MASK, CPU_DDR_CLOCK_CONTROL_CPU_PLL_BYPASS_SET(0));
	cpu_ddr_control_set (CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_MASK, CPU_DDR_CLOCK_CONTROL_DDR_PLL_BYPASS_SET(0));
	cpu_ddr_control_set (CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_MASK, CPU_DDR_CLOCK_CONTROL_AHB_PLL_BYPASS_SET(0));

ddr_pll_dither_unset:
	li	t7,	KSEG1ADDR(AR934X_DDR_PLL_DITHER);
	sw	t3,	0(t7);

cpu_pll_dither_unset:
	li	t7,	KSEG1ADDR(AR934X_CPU_PLL_DITHER);
	sw	t4,	0(t7);

	jr ra
	nop
