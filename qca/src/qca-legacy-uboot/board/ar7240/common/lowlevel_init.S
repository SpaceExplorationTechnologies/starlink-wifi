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
#define clear_mask(_reg, _mask)                     \
    li  t7, KSEG1ADDR(_reg);                        \
    lw  t8, 0(t7);                                  \
    li  t9, ~_mask;                                 \
    and t8, t8, t9;                                 \
    sw  t8, 0(t7)            

#define set_val(_reg, _mask, _val)                  \
    li  t7, KSEG1ADDR(_reg);                        \
    lw  t8, 0(t7);                                  \
    li  t9, ~_mask;                                 \
    and t8, t8, t9;                                 \
    li  t9, _val;                                   \
    or  t8, t8, t9;                                 \
    sw  t8, 0(t7)            

#define set_val_f(_reg, _mask, _val)                \
    li  t7, KSEG1ADDR(_reg);                        \
    lw  t8, 0(t7);                                  \
    li  t9, ~_mask;                                 \
    and t8, t8, t9;                                 \
    li  t6, KSEG1ADDR(_val);                        \
    lw  t9, 0(t6);                                  \
    or  t8, t8, t9;                                 \
    sw  t8, 0(t7)            


#define get_val(_reg, _mask, _shift, _res_reg)      \
    li  t7, KSEG1ADDR(_reg);                        \
    lw  t8, 0(t7);                                  \
    li  t9, _mask;                                  \
    and t8, t8, t9;                                 \
    srl _res_reg, t8, _shift                        \

#define pll_clr(_mask)                              \
    clear_mask(AR7240_CPU_PLL_CONFIG, _mask)

#define pll_set(_mask, _val)                        \
    set_val(AR7240_CPU_PLL_CONFIG,  _mask, _val)

#define pll_set_f(_mask, _val)                      \
    set_val_f(AR7240_CPU_PLL_CONFIG,  _mask, _val)

#define pll_get(_mask, _shift, _res_reg)            \
    get_val(AR7240_CPU_PLL_CONFIG, _mask, _shift, _res_reg)

#define clk_clr(_mask)                              \
    clear_mask(AR7240_CPU_CLOCK_CONTROL, _mask)

#define clk_set(_mask, _val)                        \
    set_val(AR7240_CPU_CLOCK_CONTROL,  _mask, _val)

#define clk_get(_mask, _shift, _res_reg)            \
    get_val(AR7240_CPU_CLOCK_CONTROL, _mask, _shift, _res_reg)


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

.globl lowlevel_init

lowlevel_init:

    /*
     * The code below is for the real chip. Wont work on FPGA
     */
    /* jr ra  */

#if !defined(CONFIG_AR7240_EMU) && defined(CONFIG_WASP_SUPPORT)
#if !defined(CONFIG_ATH_NAND_BR)
	b ar934x_lowlevel_init
#endif
#else

#ifndef CONFIG_HORNET_EMU
#if defined(CONFIG_MACH_HORNET)
    b hornet_pll_init
#else
wdt_reset:
#ifndef CONFIG_AR7240_EMU
	li	$3, -1207566336		# 0xffffffffb8060000
	ori	$4, $3, 0x8
	lw	$2, 0($4)
	bltz	$2, $L6
	nop
	ori	$5, $3, 0xc

	li	$3, 300			# 0x4
	sw	$3, 0($5)
	li	$3, 3			# 0x3
	sw	$3, 0($4)
$L3:
	b	$L3
	nop
#endif
$L6:
	nop
	nop
#ifndef CONFIG_AR7240_EMU
#ifndef COMPRESSED_UBOOT

    /* 
     * WAR for the bug#55574: Set the CKE (bit 7 in DDR_CONFIG2 register) 
     * to low initially 
     */
    li  t7, KSEG1ADDR(AR7240_DDR_CONFIG2);
    lw  t8, 0(t7);
    li  t9, 0xffffff7f;
    and t8, t8, t9;
    sw  t8, 0(t7);
#endif

    /*
     * Check if the PLL is already set and CPU is Reset
     */
    clk_get(CLOCK_CONTROL_RST_SWITCH_MASK, CLOCK_CONTROL_RST_SWITCH_SHIFT, t6)
    bne zero, t6, initialize_pll
    nop

init_pll_values:
    li  a2,PLL_CONFIG_VAL_F                 # 0xffffffffbf040000
    lw  a0,0(a2)
    li  v1,PLL_MAGIC                        # 0xffffffffaabb0000
    beq a0,v1,read_pll_from_flash
    nop

#ifdef CONFIG_SUPPORT_AR7241
    li  t7, KSEG1ADDR(AR7240_REV_ID)
    lw  t8, 0(t7)
    li  t9, AR7240_REV_ID_MASK
    and t8, t8, t9
    li  v1, AR7241_REV_1_0
    beq t8,v1,init_7241_pll
    nop
    li  v1, AR7242_REV_1_0
    beq t8,v1,init_7241_pll
    nop
    bne t8,v1,init_default

init_7241_pll:
    pll_clr(PLL_CONFIG_PLL_RESET_MASK)
    pll_set( (PLL_CONFIG_DDR_DIV_MASK | PLL_CONFIG_AHB_DIV_MASK | PLL_CONFIG_PLL_NOPWD_MASK | PLL_CONFIG_PLL_REF_DIV_MASK | PLL_CONFIG_PLL_DIV_MASK) ,( PLL_7241_CONFIG_PLL_REF_DIV_VAL|PLL_7241_CONFIG_PLL_DIV_VAL|PLL_7241_CONFIG_AHB_DIV_VAL|PLL_7241_CONFIG_DDR_DIV_VAL|PLL_CONFIG_PLL_NOPWD_VAL))
    pll_clr(PLL_CONFIG_PLL_BYPASS_MASK) 
    b wait_for_pll_update
    nop

init_default:
#endif

    pll_clr(PLL_CONFIG_PLL_RESET_MASK)
    pll_set( (PLL_CONFIG_DDR_DIV_MASK | PLL_CONFIG_AHB_DIV_MASK | PLL_CONFIG_PLL_NOPWD_MASK | PLL_CONFIG_PLL_REF_DIV_MASK | PLL_CONFIG_PLL_DIV_MASK) ,( PLL_CONFIG_PLL_REF_DIV_VAL|PLL_CONFIG_PLL_DIV_VAL|PLL_CONFIG_AHB_DIV_VAL|PLL_CONFIG_DDR_DIV_VAL|PLL_CONFIG_PLL_NOPWD_VAL))
    pll_clr(PLL_CONFIG_PLL_BYPASS_MASK) 
    b wait_for_pll_update
    nop

read_pll_from_flash:
    pll_clr(PLL_CONFIG_PLL_RESET_MASK)
    pll_set_f((PLL_CONFIG_DDR_DIV_MASK | PLL_CONFIG_AHB_DIV_MASK | PLL_CONFIG_PLL_NOPWD_MASK | PLL_CONFIG_PLL_REF_DIV_MASK | PLL_CONFIG_PLL_DIV_MASK) ,((PLL_CONFIG_VAL_F + 4) | PLL_CONFIG_PLL_NOPWD_VAL))
    pll_clr(PLL_CONFIG_PLL_BYPASS_MASK) 
    b wait_for_pll_update
    nop


wait_for_pll_update:
    pll_get(PLL_CONFIG_PLL_UPDATE_MASK, PLL_CONFIG_PLL_UPDATE_SHIFT, t6)
    bne zero, t6, wait_for_pll_update
    nop

    /*
     * Will cause a reset
     * The RESET_SWITCH need to be set first and then 
     * set the CLOCK_SWITCH for the CPU to boot properly
     * after RESET.
     */
pll_locked:
    clk_set(CLOCK_CONTROL_RST_SWITCH_MASK, 0x2)
    clk_set(CLOCK_CONTROL_CLOCK_SWITCH_MASK, 0x1)
    nop

    /*
     * When the PLL is already set and CPU is RESET
     * The code will jump here
     */
initialize_pll:
    clk_clr(CLOCK_CONTROL_RST_SWITCH_MASK)
    clk_clr(CLOCK_CONTROL_CLOCK_SWITCH_MASK)
#endif
#endif /* CONFIG_MACH_HORNET */
#endif /* CONFIG_HORNET_EMU */
#endif /* CONFIG_MAC_WASP */
    jr ra
    nop

