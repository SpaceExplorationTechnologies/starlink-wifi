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

#include <asm-mips/regdef.h>
#include <asm-mips/mipsregs.h>
#include <defines.h>
#include "asm.h"

LEAF(__start)

	.set	mips2

	/* Disable interrupts */
	mtc0	zero, CP0_STATUS

    /* Disable watch exception. */
    mtc0    zero, CP0_WATCHLO
    mtc0    zero, CP0_WATCHHI

	/* disable kernel mode cache */
	mfc0	t0, CP0_CONFIG
	and	t0, ~0x7
	ori	t0, 0x2
	mtc0	t0, CP0_CONFIG

	/* set up stack */
	li	sp, STACK_POINTER_INIT_ADDR
	li	gp, STACK_POINTER_INIT_ADDR

	/* jump */
	jal	spi_prog

loop:
	j	loop
	nop
END(__start)

