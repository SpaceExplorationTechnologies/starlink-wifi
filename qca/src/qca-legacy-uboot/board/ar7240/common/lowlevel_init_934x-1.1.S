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

#include <config.h>
#include <version.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>
#include <asm/addrspace.h>
#include <ar7240_soc.h>

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

#define inc_loop_count(loc)		\
	li	t9,	loc;		\
	lw	t7,	0(t9);		\
	addi	t7,	t7,	1;	\
	sw	t7,	0(t9);

#define clear_loop_count(loc)	\
	li	t9,	loc;	\
	sw	zero,	0(t9);

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

	li	t7,	PLL_CONFIG_VAL_F
	lw	t8,	0(t7)
	li	t7,	PLL_MAGIC
	beq	t7,	t8,	read_from_flash
	nop
	j	pll_bypass_set
	nop
read_from_flash:
	li	t7,	PLL_CONFIG_VAL_F + 4
	lw	t5,	0(t7)
	lw	t4,	4(t7)
	lw	t6,	8(t7)
	lw	t3,	12(t7)


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
	/* See if we have to read the pll values from flash */
	li	t7,	SRIF_PLL_CONFIG_VAL_F
	lw	t8,	0(t7)
	li	t7,	SRIF_PLL_MAGIC
	beq	t7,	t8,	read_srif_from_flash
	nop

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
	li	t5,	((0x8 << 27) | (90 << 18) | 0);	// ddr freq = (40 MHz refclk/refdiv 8) * Nint
#endif /* CONFIG_ATH_NAND_SUPPORT */
#endif
	j	2f
	nop
1:
#if cpu_from_srif
	li	t4,	((0x5 << 27) | (112 << 18) | 0);// cpu freq = (25 MHz refclk/refdiv 5) * Nint
#endif
#if ddr_from_srif
#ifdef CONFIG_ATH_NAND_SUPPORT
	li	t5,	((0x5 << 27) | (160 << 18) | 0);// ddr freq = (25 MHz refclk/refdiv 5) * Nint
#else
	li	t5,	((0x5 << 27) | (90 << 18) | 0);	// ddr freq = (25 MHz refclk/refdiv 5) * Nint
#endif /* CONFIG_ATH_NAND_SUPPORT */
#endif
	j	2f
	nop
#else	/* defined(CONFIG_AP123) */
	/*		refdiv		nint		nfrac */
#if cpu_from_srif
	li	t4,	((0x8 << 27) | (107 << 18) | 0);// cpu freq = (40 MHz refclk/refdiv 8) * Nint
#endif
#if ddr_from_srif
	li	t5,	((0x8 << 27) | (160 << 18) | 0);// ddr freq = (40 MHz refclk/refdiv 8) * Nint
#endif
	j	2f
	nop
1:
#if cpu_from_srif
	li	t4,	((0x5 << 27) | (107 << 18) | 0);// cpu freq = (25 MHz refclk/refdiv 5) * Nint
#endif
#if ddr_from_srif
	li	t5,	((0x5 << 27) | (160 << 18) | 0);// ddr freq = (25 MHz refclk/refdiv 5) * Nint
#endif
	j	2f
	nop
#endif	/* !defined(CONFIG_AP123) */

read_srif_from_flash:
	li	t7,	SRIF_PLL_CONFIG_VAL_F + 4
#if cpu_from_srif
	lw	t4,	0(t7);	// CPU PLL
#endif
#if ddr_from_srif
	lw	t5,	4(t7);	// DDR PLL
#endif
	/* CPU */
2:

	clear_loop_count(ATH_CPU_COUNT_LOC);

cpu_pll_is_not_locked:

	inc_loop_count(ATH_CPU_COUNT_LOC);

#if cpu_from_srif
	set_srif_pll(0xb81161c4, (0x4 << 26) | (0x10 << 19) | (0x1e << 7) | (1 << 16));
	set_srif_pll_reg(0xb81161c0, t4);
	set_srif_pll(0xb81161c4, (0x3 << 30) | (0x4 << 26) | (0x10 << 19) | (0x1e << 7) | (1 << 16));
	set_srif_pll(0xb81161c8, (6 << 23));
	set_srif_pll(0xb81161c4, (0x3 << 30) | (0x4 << 26) | (0x10 << 19) | (0x1e << 7));

cpu_clear_do_meas1:
	li	t7,	KSEG1ADDR(CPU_DPLL3_ADDRESS)
	lw	t8,	0(t7)
	li	t9,	~CPU_DPLL3_DO_MEAS_SET(1)
	and	t8,	t8,	t9
	sw	t8,	0(t7)

cpu_set_do_meas:
	li	t7,	KSEG1ADDR(CPU_DPLL3_ADDRESS)
	lw	t8,	0(t7)
	li	t9,	CPU_DPLL3_DO_MEAS_SET(1)
	or	t8,	t8,	t9
	sw	t8,	0(t7)

	li	t7,	KSEG1ADDR(CPU_DPLL4_ADDRESS)
cpu_wait_for_meas_done:
	lw	t8,	0(t7)
	andi	t8,	t8,	CPU_DPLL4_MEAS_DONE_SET(1)
	beqz	t8,	cpu_wait_for_meas_done
	nop

cpu_clear_do_meas2:
	li	t7,	KSEG1ADDR(CPU_DPLL3_ADDRESS)
	lw	t8,	0(t7)
	li	t9,	~CPU_DPLL3_DO_MEAS_SET(1)
	and	t8,	t8,	t9
	sw	t8,	0(t7)

cpu_read_sqsum_dvc:
	li	t7,	KSEG1ADDR(CPU_DPLL3_ADDRESS)
	lw	t8,	0(t7)
	li	t9,	CPU_DPLL3_SQSUM_DVC_MASK
	and	t8,	t8,	t9
	sra	t8,	t8,	CPU_DPLL3_SQSUM_DVC_LSB
	li	t9,	0x40000
	subu	t8,	t8,	t9
	bgez	t8,	cpu_pll_is_not_locked
	nop

#endif

	/* DDR */
#if ddr_from_srif

	clear_loop_count(ATH_DDR_COUNT_LOC)

ddr_pll_is_not_locked:

	inc_loop_count(ATH_DDR_COUNT_LOC)

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

ddr_clear_do_meas1:
	li	t7,	KSEG1ADDR(DDR_DPLL3_ADDRESS)
	lw	t8,	0(t7)
	li	t9,	~DDR_DPLL3_DO_MEAS_SET(1)
	and	t8,	t8,	t9
	sw	t8,	0(t7)


ddr_set_do_meas:
	li	t7,	KSEG1ADDR(DDR_DPLL3_ADDRESS)
	lw	t8,	0(t7)
	li	t9,	DDR_DPLL3_DO_MEAS_SET(1)
	or	t8,	t8,	t9
	sw	t8,	0(t7)

	li	t7,	KSEG1ADDR(DDR_DPLL4_ADDRESS)
ddr_wait_for_meas_done:
	lw	t8,	0(t7)
	andi	t8,	t8,	DDR_DPLL4_MEAS_DONE_SET(1)
	beqz	t8,	ddr_wait_for_meas_done
	nop

ddr_clear_do_meas2:
	li	t7,	KSEG1ADDR(DDR_DPLL3_ADDRESS)
	lw	t8,	0(t7)
	li	t9,	~DDR_DPLL3_DO_MEAS_SET(1)
	and	t8,	t8,	t9
	sw	t8,	0(t7)

ddr_read_sqsum_dvc:
	li	t7,	KSEG1ADDR(DDR_DPLL3_ADDRESS)
	lw	t8,	0(t7)
	li	t9,	DDR_DPLL3_SQSUM_DVC_MASK
	and	t8,	t8,	t9
	sra	t8,	t8,	DDR_DPLL3_SQSUM_DVC_LSB
	li	t9,	0x40000
	subu	t8,	t8,	t9
	bgez	t8,	ddr_pll_is_not_locked
	nop
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

