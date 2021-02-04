/*
 *  Startup Code for MIPS32 CPU-core
 *
 *  Copyright (c) 2003	Wolfgang Denk <wd@denx.de>
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


#include <config.h>
#include <version.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>

#define AR7100_SPI_CLOCK  0xbf000004

#define RVECENT(f,n) \
   b f; nop
#define XVECENT(f,bev) \
   b f     ;           \
   li k0,bev

	.set noreorder

	.globl _start_bootstrap
	.text
_start_bootstrap:
	RVECENT(reset,0)	/* U-boot entry point */
	RVECENT(reset,1)	/* software reboot */
	RVECENT(romReserved,2)
	RVECENT(romReserved,3)
	RVECENT(romReserved,4)
	RVECENT(romReserved,5)
	RVECENT(romReserved,6)
	RVECENT(romReserved,7)
	RVECENT(romReserved,8)
	RVECENT(romReserved,9)
	RVECENT(romReserved,10)
	RVECENT(romReserved,11)
	RVECENT(romReserved,12)
	RVECENT(romReserved,13)
	RVECENT(romReserved,14)
	RVECENT(romReserved,15)
	RVECENT(romReserved,16)
	RVECENT(romReserved,17)
	RVECENT(romReserved,18)
	RVECENT(romReserved,19)
	RVECENT(romReserved,20)
	RVECENT(romReserved,21)
	RVECENT(romReserved,22)
	RVECENT(romReserved,23)
	RVECENT(romReserved,24)
	RVECENT(romReserved,25)
	RVECENT(romReserved,26)
	RVECENT(romReserved,27)
	RVECENT(romReserved,28)
	RVECENT(romReserved,29)
	RVECENT(romReserved,30)
	RVECENT(romReserved,31)
	RVECENT(romReserved,32)
	RVECENT(romReserved,33)
	RVECENT(romReserved,34)
	RVECENT(romReserved,35)
	RVECENT(romReserved,36)
	RVECENT(romReserved,37)
	RVECENT(romReserved,38)
	RVECENT(romReserved,39)
	RVECENT(romReserved,40)
	RVECENT(romReserved,41)
	RVECENT(romReserved,42)
	RVECENT(romReserved,43)
	RVECENT(romReserved,44)
	RVECENT(romReserved,45)
	RVECENT(romReserved,46)
	RVECENT(romReserved,47)
	RVECENT(romReserved,48)
	RVECENT(romReserved,49)
	RVECENT(romReserved,50)
	RVECENT(romReserved,51)
	RVECENT(romReserved,52)
	RVECENT(romReserved,53)
	RVECENT(romReserved,54)
	RVECENT(romReserved,55)
	RVECENT(romReserved,56)
	RVECENT(romReserved,57)
	RVECENT(romReserved,58)
	RVECENT(romReserved,59)
	RVECENT(romReserved,60)
	RVECENT(romReserved,61)
	RVECENT(romReserved,62)
	RVECENT(romReserved,63)
	XVECENT(romExcHandle,0x200)	/* bfc00200: R4000 tlbmiss vector */
	RVECENT(romReserved,65)
	RVECENT(romReserved,66)
	RVECENT(romReserved,67)
	RVECENT(romReserved,68)
	RVECENT(romReserved,69)
	RVECENT(romReserved,70)
	RVECENT(romReserved,71)
	RVECENT(romReserved,72)
	RVECENT(romReserved,73)
	RVECENT(romReserved,74)
	RVECENT(romReserved,75)
	RVECENT(romReserved,76)
	RVECENT(romReserved,77)
	RVECENT(romReserved,78)
	RVECENT(romReserved,79)
	XVECENT(romExcHandle,0x280)	/* bfc00280: R4000 xtlbmiss vector */
	RVECENT(romReserved,81)
	RVECENT(romReserved,82)
	RVECENT(romReserved,83)
	RVECENT(romReserved,84)
	RVECENT(romReserved,85)
	RVECENT(romReserved,86)
	RVECENT(romReserved,87)
	RVECENT(romReserved,88)
	RVECENT(romReserved,89)
	RVECENT(romReserved,90)
	RVECENT(romReserved,91)
	RVECENT(romReserved,92)
	RVECENT(romReserved,93)
	RVECENT(romReserved,94)
	RVECENT(romReserved,95)
	XVECENT(romExcHandle,0x300)	/* bfc00300: R4000 cache vector */
	RVECENT(romReserved,97)
	RVECENT(romReserved,98)
	RVECENT(romReserved,99)
	RVECENT(romReserved,100)
	RVECENT(romReserved,101)
	RVECENT(romReserved,102)
	RVECENT(romReserved,103)
	RVECENT(romReserved,104)
	RVECENT(romReserved,105)
	RVECENT(romReserved,106)
	RVECENT(romReserved,107)
	RVECENT(romReserved,108)
	RVECENT(romReserved,109)
	RVECENT(romReserved,110)
	RVECENT(romReserved,111)
	XVECENT(romExcHandle,0x380)	/* bfc00380: R4000 general vector */
	RVECENT(romReserved,113)
	RVECENT(romReserved,114)
	RVECENT(romReserved,115)
	RVECENT(romReserved,116)
	RVECENT(romReserved,116)
	RVECENT(romReserved,118)
	RVECENT(romReserved,119)
	RVECENT(romReserved,120)
	RVECENT(romReserved,121)
	RVECENT(romReserved,122)
	RVECENT(romReserved,123)
	RVECENT(romReserved,124)
	RVECENT(romReserved,125)
	RVECENT(romReserved,126)
	RVECENT(romReserved,127)

	/* We hope there are no more reserved vectors!
	 * 128 * 8 == 1024 == 0x400
	 * so this is address R_VEC+0x400 == 0xbfc00400
	 */
	.align 4
reset:
	/*
	 * Clearing CP0 registers - This is generally required for the MIPS-24k
     * core used by Atheros.
	 */
	mtc0	zero, $0
	mtc0	zero, $1
	mtc0	zero, $2
	mtc0	zero, $3
	mtc0	zero, $4
	mtc0	zero, $5
	mtc0	zero, $6
	mtc0	zero, $7
	mtc0	zero, $8
	mtc0	zero, $9
	mtc0	zero, $10
	mtc0	zero, $11
	li	t0, 0x10000004
	mtc0	t0, $12
	mtc0	zero, $13
	mtc0	zero, $14
	mtc0	zero, $15
	mtc0	zero, $16
	mtc0	zero, $17
	mtc0	zero, $18
	mtc0	zero, $19
	mtc0	zero, $20
	mtc0	zero, $21
	mtc0	zero, $22
#ifndef CONFIG_HORNET_EMU
	mtc0	zero, $23
#endif
	mtc0	zero, $24
	mtc0	zero, $25
	mtc0	zero, $26
	mtc0	zero, $27
	mtc0	zero, $28
#if defined(CONFIG_WASP_SUPPORT) || defined(CONFIG_MACH_QCA955x) || defined(CONFIG_MACH_QCA953x) || defined(CONFIG_MACH_QCA956x) || defined(CONFIG_MACH_QCN550x)
	mtc0	zero, $29	# C0_TagHi
	mtc0	zero, $28, 2	# C0_DTagLo
	mtc0	zero, $29, 2	# C0_DTagHi
#endif

	/*
	 * Clear watch registers.
	 */

	mtc0	zero, CP0_WATCHLO
	mtc0	zero, CP0_WATCHHI

	/* STATUS register */
	mfc0	k0, CP0_STATUS
	li	k1, ~ST0_IE
	and	k0, k1
        mtc0	zero, CP0_CAUSE
	mtc0	k0, CP0_STATUS

	/* CAUSE register */
	mtc0	zero, CP0_CAUSE

	/* Init Timer */
	mtc0	zero, CP0_COUNT
	mtc0	zero, CP0_COMPARE

	/* CONFIG0 register */
	li	t0, CONF_CM_UNCACHED
	mtc0	t0, CP0_CONFIG


    /* Initialize GOT pointer.*/
	bal     1f
	nop
	.word   _GLOBAL_OFFSET_TABLE_
	1:
	move    gp, ra
	lw      t1, 0(ra)
	move	gp, t1

#if (defined(CONFIG_MACH_HORNET) && defined(CONFIG_HORNET_1_1_WAR)) || defined(CONFIG_MACH_QCA956x) || defined(CONFIG_MACH_QCN550x)
/**************************************************************************/
/*
 * WAR: Hornet 1.1 currently need a reset once we boot to let the resetb has
 *      enough time to stable, so that trigger reset at 1st boot, system team
 *      is investigaing the issue, will remove in short
 */

do_reset_normal:

    li  t7, 0xbd000000
    lw  t8, 0(t7)            // t8 : value of 0xbd000000
    li  t9, 0x12345678
    bne t8, t9, do_reset     // if value of 0xbd000000 != 0x12345678 , go to do_reset
    nop
    li  t9, 0xffffffff
    sw  t9, 0(t7) 
    b   normal_path
    nop

do_reset:
    sw  t9, 0(t7)
    li  t7, 0xb806001c       // load reset register 0x1806001c
    lw  t8, 0(t7)
    li  t9, 0x1000000        // bit24, fullchip reset
    or  t8, t8, t9
    sw  t8, 0(t7)
do_reset_loop:    
    b   do_reset_loop
    nop

normal_path:
#endif /* CONFIG_MACH_HORNET */

/**************************************************************************/

	/* Initialize any external memory.
	 */
#if defined(CONFIG_AR7100) || defined(CONFIG_AR7240) || defined(CONFIG_MACH_QCA955x) || defined(CONFIG_MACH_QCA953x) || defined(CONFIG_MACH_QCA956x) || defined(CONFIG_MACH_QCN550x)
	la      t9, lowlevel_init
	jalr    t9
	nop
	nop

#if defined(CONFIG_MACH_HORNET)
	la      t9, hornet_ddr_init
	jalr    t9
	nop
	nop

#if 0
	la      t9, hornet_ddr_tap_init
	jalr    t9
	nop
#endif

#endif

	la	t0, rel_start
	j	t0
	nop
#endif

rel_start:

#if defined(CONFIG_AR7100) || defined(CONFIG_AR7240) || defined(CONFIG_MACH_QCA955x) || defined(CONFIG_MACH_QCA953x)
	/* REMAP_DISABLE */
	li	a0, AR7100_SPI_CLOCK
	li	t0, 0x43
	sw	t0, 0(a0)
#elif defined(CONFIG_MACH_QCA956x) || defined(CONFIG_MACH_QCN550x)
	/* REMAP_DISABLE */
	li	a0, AR7100_SPI_CLOCK
	li	t0, 0x46
	sw	t0, 0(a0)
#endif

#if defined(CONFIG_AR9100) && defined(CFG_HOWL_1_2)
    /* Disable remap for parallel flash */
    li  t7, AR9100_FLASH_CONFIG;
    lw  t8, 0(t7);
    li  t9, 0xffbf0000;
    and t8, t8, t9;
    li  t9, 0x22fc;
    or  t8, t8, t9;
    li  t9, 0xffcfffff; /* scale = 0 */
    and t8, t8, t9;
    sw  t8, 0(t7);

#endif

	/* Initialize caches...
	 */
	la      t9, simple_mips_cache_reset
	jalr    t9
	nop

	/* ... and enable them.
	 */
	li	t0, CONF_CM_CACHABLE_NONCOHERENT
	mtc0	t0, CP0_CONFIG

#if !defined(CFG_INIT_STACK_IN_SRAM)
#if !defined(CONFIG_AR7100) && !defined(CONFIG_AR7240)
	/* Set up temporary stack.
	 */
	li	a0, CFG_INIT_SP_OFFSET
	la      t9, mips_cache_lock
	jalr    t9
	nop
#endif

#if defined(CONFIG_AR7100) || defined(CONFIG_AR7240)
	la	t9, mips_cache_lock_24k
	jalr	t9
	nop
#endif
#endif /* CFG_INIT_STACK_IN_SRAM */

	li	t0, CFG_SDRAM_BASE + CFG_INIT_SP_OFFSET
#ifdef CFG_INIT_STACK_IN_SRAM
	li	t0, CFG_INIT_SRAM_SP_OFFSET	/* Setup stack in SRAM */
#endif
	la	sp, 0(t0)

	la	t9, bootstrap_board_init_f
	j	t9
	nop


/*
 * void bootstrap_relocate_code (addr_sp, gd, addr_moni)
 *
 * This "function" does not return, instead it continues in RAM
 * after relocating the monitor code.
 *
 * a0 = addr_sp
 * a1 = gd
 * a2 = destination address
 */
	.globl	bootstrap_relocate_code
	.ent	bootstrap_relocate_code
bootstrap_relocate_code:
	move	sp, a0		/* Set new stack pointer		*/

	li	t0, BOOTSTRAP_CFG_MONITOR_BASE
	la	t3, in_ram
	lw	t2, -12(t3)	/* t2 <-- uboot_end_data_bootsrap	*/

	/*
	 * Ideally, following line is not needed. However,
	 * the behaviour is flaky without it. U-boot boots on
	 * some boards, and doesn't on some boards. Even on the
	 * boards it boots, it doesn't boot all the time.
	 *
	 * Adding 256k to what needs to be read in actually.
	 * This introduces some delay that seems to help boot.
	 */
	li	t3, (256 << 10)

	add	t2, t3
	move	t1, a2

	/*
	 * Fix GOT pointer:
	 *
	 * New GOT-PTR = (old GOT-PTR - BOOTSTRAP_CFG_MONITOR_BASE) + Destination Address
	 */
	move	t6, gp
	sub	gp, BOOTSTRAP_CFG_MONITOR_BASE
	add	gp, a2			/* gp now adjusted		*/
	sub	t6, gp, t6		/* t6 <-- relocation offset	*/

	/*
	 * t0 = source address
	 * t1 = target address
	 * t2 = source end address
	 */
1:
	lw	t3, 0(t0)
	sw	t3, 0(t1)
	addu	t0, 4
	ble	t0, t2, 1b
	addu	t1, 4			/* delay slot			*/

	/* If caches were enabled, we would have to flush them here.
	 */

	/* Jump to where we've relocated ourselves.
	 */
	addi	t0, a2, in_ram - _start_bootstrap
	j	t0
	nop

	.word	uboot_end_data_bootstrap
	.word	uboot_end_bootstrap
	.word	num_got_entries

in_ram:
	/* Now we want to update GOT.
	 */
	lw	t3, -4(t0)	/* t3 <-- num_got_entries	*/
	addi	t4, gp, 8	/* Skipping first two entries.	*/
	li	t2, 2
1:
	lw	t1, 0(t4)
	beqz	t1, 2f
	add	t1, t6
	sw	t1, 0(t4)
2:
	addi	t2, 1
	blt	t2, t3, 1b
	addi	t4, 4		/* delay slot			*/

	/* Clear BSS.
	 */
	lw	t1, -12(t0)	/* t1 <-- uboot_end_data_bootstrap	*/
	lw	t2, -8(t0)	/* t2 <-- uboot_end_bootstrap		*/
	add	t1, t6		/* adjust pointers		*/
	add	t2, t6

	sub	t1, 4
1:	addi	t1, 4
	bltl	t1, t2, 1b
	sw	zero, 0(t1)	/* delay slot			*/

	move	a0, a1
	la	t9, bootstrap_board_init_r
	j	t9
	move	a1, a2		/* delay slot			*/

	.end	bootstrap_relocate_code



.globl	ath_ddr_tap_cal
.type   ath_ddr_tap_cal, @function

ath_ddr_tap_cal:
	li	a0,	0xbd001f00
	sw	zero,	0x0(a0)			// Place where the tap values are saved and used for SWEEP
	sw	zero,	0x4(a0)			// Place where the number of passing taps are saved.
	sw	zero,	0x14(a0)		// Place where the last pass tap value is stored
	li	a1,	0xaa55aa55		// Indicates that the First pass tap value is not found
	sw	a1,	0x10(a0)		// Place where the First pass tap value is stored
	nop

	li	a0,	0xb8060000		// RESET_BASE_ADDRESS
	lw	a1,	0x1c(a0)		// Reading the RST_RESET_ADDRESS
	li	a2,	0x08000000		// Setting the RST_RESET_RTC_RESET
	or	a1,	a1,	a2
	sw	a1,	0x1c(a0)

	li	a3,	0xffffffff
	xor	a2,	a2,	a3
	and	a1,	a1,	a2
	sw	a1,	0x1c(a0)		// Taking the RTC out of RESET
	nop

	li	a0,	0xb8107000		// RTC_BASE_ADDRESS
	li	a1,	0x1
	sw	a1,	0x0040(a0)		// RTC_SYNC_RESET_ADDRESS

	li	a2,	0x2

_poll_for_RTC_ON:
	lw	a1,	0x0044(a0)		// RTC_SYNC_STATUS_ADDRESS
	and	a1,	a2,	a1
	bne	a1,	a2,	_poll_for_RTC_ON


_CHANGE_TAPS:

	li	t0,	0xbd001f00		// Read the current value of the TAP for programming
	lw	t1,	0x0(t0)
	li	t2,	0x00000000
	or	t3,	t1,	t2


	li	t0,	0xb8000000		// DDR_BASE_ADDRESS

	sw	t3,	0x1c(t0)		// TAP_CONTROL_0_ADDRESS
	sw	t3,	0x20(t0)		// TAP_CONTROL_1_ADDRESS
	sw	t3,	0x24(t0)		// TAP_CONTROL_2_ADDRESS
	sw	t3,	0x28(t0)		// TAP_CONTROL_3_ADDRESS

	li	t1,	0x00000010		// Running the test 8 times
	sw	t1,	0x0068(t0)		// PERF_COMP_ADDR_1_ADDRESS

	li	t1,	0xfa5de83f		// 4 Row Address Bits, 4 Column Address Bits, 2 BA bits
	sw	t1,	0x002c(t0)		// PERF_MASK_ADDR_0_ADDRESS

#if defined(CONFIG_MACH_QCA953x) || defined(CONFIG_MACH_QCA956x) || defined(CONFIG_MACH_QCN550x)
	li	t1,	0x0000ffff
	sw	t1,	0x0070(t0)		// PERF_COMP_AHB_GE0_1_ADDRESS

	li	t1,	0x0000ffff
	sw	t1,	0x0040(t0)		// PERF_COMP_AHB_GE1_0_ADDRESS

	li	t1,	0x0000ffff
	sw	t1,	0x0078(t0)		// PERF_COMP_AHB_GE1_1_ADDRESS

	li	t1,	0x0000ffff
	sw	t1,	0x0034(t0)		// PERF_MASK_AHB_GE0_0_ADDRESS

	li	t1,	0x0000ffff
	sw	t1,	0x006c(t0)		// PERF_MASK_AHB_GE0_1_ADDRESS

	li	t1,	0x0000ffff
	sw	t1,	0x003c(t0)		// PERF_MASK_AHB_GE1_0_ADDRESS

	li	t1,	0x0000ffff
	sw	t1,	0x0074(t0)		// PERF_MASK_AHB_GE1_1_ADDRESS

	li	t1,	0x0000ffff
	sw	t1,	0x0038(t0)		// PERF_COMP_AHB_GE0_0_ADDRESS
#else // Wasp & Scorpion ...
	li	t1,	0x545fc332
	sw	t1,	0x0070(t0)		// PERF_COMP_AHB_GE0_1_ADDRESS

	li	t1,	0xaba03ccd
	sw	t1,	0x0040(t0)		// PERF_COMP_AHB_GE1_0_ADDRESS

	li	t1,	0x545fc332
	sw	t1,	0x0078(t0)		// PERF_COMP_AHB_GE1_1_ADDRESS

	li	t1,	0xaba03ccd
	sw	t1,	0x0034(t0)		// PERF_MASK_AHB_GE0_0_ADDRESS

	li	t1,	0x545fc332
	sw	t1,	0x006c(t0)		// PERF_MASK_AHB_GE0_1_ADDRESS

	li	t1,	0xaba03ccd
	sw	t1,	0x003c(t0)		// PERF_MASK_AHB_GE1_0_ADDRESS

	li	t1,	0x545fc332
	sw	t1,	0x0074(t0)		// PERF_MASK_AHB_GE1_1_ADDRESS

	li	t1,	0xaba03ccd
	sw	t1,	0x0038(t0)		// PERF_COMP_AHB_GE0_0_ADDRESS
#endif

	li	t1,	0x00000001
	sw	t1,	0x011c(t0)		// DDR_BIST_ADDRESS

	li	t2,	0x1
_bist_done_poll:
	lw	t1,	0x0120(t0)		// DDR_BIST_STATUS_ADDRESS
	and	t1,	t1,	t2
	bne	t1,	t2,	_bist_done_poll

	lw	t1,	0x0120(t0)		// DDR_BIST_STATUS_ADDRESS
	li	t4,	0x000001fe
	and	t2,	t1,	t4
	srl	t2,	t2,	0x1		// no. of Pass Runs

	li	t5,	0x00000000
	sw	t5,	0x011c(t0)		//DDR_BIST_ADDRESS	- Stop the DDR BIST test

	li	t5,	0x0001fe00
	and	t5,	t5,	t1
	bnez	t5,	_iterate_tap		// This is a redundant compare but nevertheless - Comparing the FAILS

	lw	t1,	0x0068(t0)		// PERF_COMP_ADDR_1_ADDRESS
	li	t3,	0x000001fe
	and	t3,	t3,	t1
	srl	t3,	t3,	0x1		// No. of runs in the config register.

	bne	t3,	t2,	_iterate_tap

pass_tap:
	li	t0,	0xbd001f00
	lw	t1,	0x4(t0)
	addiu	t1,	t1,	0x1
	sw	t1,	0x4(t0)

	li	t0,	0xbd001f10
	lw	t1,	0x0(t0)
	li	t2,	0xaa55aa55
	beq	t1,	t2,	_first_pass
	nop
	li	t0,	0xbd001f00
	lw	t1,	0x0(t0)
	li	t0,	0xbd001f10
	sw	t1,	0x4(t0)
	nop
	b	_iterate_tap
	nop

_first_pass:
	li	t0,	0xbd001f00
	lw	t1,	0x0(t0)
	li	t0,	0xbd001f10
	sw	t1,	0x0(t0)
	sw	t1,	0x4(t0)
	nop

_iterate_tap:

	li	t0,	0xbd001f00
	lw	t1,	0x0(t0)
	li	t2,	0x3f
	beq	t1,	t2,	_STOP_TEST
	nop
	addiu	t1,	t1,	0x1
	sw	t1,	0x0(t0)
	nop
	b	_CHANGE_TAPS

_STOP_TEST:
	li	t0,	0xbd001f00
	lw	t1,	0x4(t0)
	bnez	t1,	_load_center_tap
	nop
	li	t3,	0x8			// Default Tap to be used
	b	_load_tap_into_reg

_load_center_tap:
	li	t0,	0xbd001f10
	lw	t1,	0x0(t0)
	lw	t2,	0x4(t0)
	add	t3,	t1,	t2
	srl	t3,	t3,	0x1
	li	t4,	0x3f
	and	t3,	t3,	t4
_load_tap_into_reg:
	li	t0,	0xb8000000
	sw	t3,	0x1c(t0)		// TAP_CONTROL_0_ADDRESS
	sw	t3,	0x20(t0)		// TAP_CONTROL_1_ADDRESS
	sw	t3,	0x24(t0)		// TAP_CONTROL_2_ADDRESS
	sw	t3,	0x28(t0)		// TAP_CONTROL_3_ADDRESS
	jr	ra
	nop



	/* Exception handlers.
	 */
romReserved:
	b romReserved

romExcHandle:
	b romExcHandle
