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
