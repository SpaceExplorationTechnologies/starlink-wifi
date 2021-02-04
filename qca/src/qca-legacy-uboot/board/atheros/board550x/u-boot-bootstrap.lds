/*
 * Copyright (c) 2017, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

OUTPUT_FORMAT("elf32-tradbigmips", "elf32-tradbigmips", "elf32-tradbigmips")
OUTPUT_ARCH(mips)
ENTRY(_start_bootstrap)
SECTIONS
{
	. = 0x00000000;

	. = ALIGN(4);
	.text       :
	{
	  *(.text)
	}

	. = ALIGN(4);
	.rodata  : { *(.rodata) }

	. = ALIGN(4);
	.data  : { *(.data) }

	. = ALIGN(4);
	.sdata  : { *(.sdata) }

	. = ALIGN(16);
	_gp = .;
	__got_start_bootstrap = .;
	.got  : { *(.got) }
	__got_end_bootstrap = .;

	.sdata  : { *(.sdata) }

	uboot_end_data_bootstrap = .;
	num_got_entries = (__got_end_bootstrap - __got_start_bootstrap) >> 2;

	. = ALIGN(4);
	.sbss  : { *(.sbss) }
	.bss  : { *(.bss) }
	uboot_end_bootstrap = .;
}
