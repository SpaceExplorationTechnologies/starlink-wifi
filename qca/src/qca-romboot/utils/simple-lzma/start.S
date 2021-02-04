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

#include <asm/regdef.h>
#include <asm/mipsregs.h>

	.set noreorder
	.align 4
	.globl _start

	.text
_start:
	.align 4

    /* init initial stack */
    la      a0,__init_stack
    move    sp,a0
    nop

    /* clear BSS section */
    la      a0,__bss_start          # start of bss
    la      a1,__bss_end            # end of bss
1:  sb      zero,0(a0)              # zero memory
    addiu   a0,a0,1                 # next addr
    bne     a0,a1,1b                # to next store
    nop

	/* main routine */
	la      t9, main
	j       t9
	nop

    .rept 1024
    .long 0
    .endr
__init_stack:
    
