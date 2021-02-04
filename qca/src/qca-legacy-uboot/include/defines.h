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
 * Memory segments (32bit kernel mode addresses)
 */
#define KUSEG			0x00000000
#define KSEG0			0x80000000
#define KSEG1			0xa0000000
#define KSEG2			0xc0000000
#define KSEG3			0xe0000000

#define SRAMADDR        0x1d000000

/*
 * SRAM size
 */
#define SRAM_SIZE       0x2000

/*
 * Reserved Space for code and stack
 */
#define RESERVED_SEGMENT_SIZE   0x2000
#define STACK_POINTER_INIT_ADDR (KSEG0 + SRAMADDR + RESERVED_SEGMENT_SIZE - 4)

/*
 * Test Options
 */
/*UART : because Wasp and Hornet use different UART controllers, it is better to disable UART function */
#define DISABLE_UART        0
#define DISCARD_ERROR       0
#define DATA_PATTERN_NUM    3

/*
 * Information
 */
#define INFO_BASE_ADDR          0xbd000000

#define INFO_GEN_ADDR           (INFO_BASE_ADDR + 0x00)     /* Current Round Number : 1, 2, ... */
#define INFO_SIZE_ADDR          (INFO_GEN_ADDR  + 0x4)
#define INFO_MEM_START_ADDR     (INFO_GEN_ADDR  + 0x8)
#define INFO_MEM_END_ADDR       (INFO_GEN_ADDR  + 0xc)
#define INFO_CACHE_START_ADDR   (INFO_GEN_ADDR  + 0x10)
#define INFO_CACHE_END_ADDR     (INFO_GEN_ADDR  + 0x14)

#define INFO_MT_ADDR            (INFO_BASE_ADDR  + 0x20)    /* 0 : not started in current round, 1 : started in current round */
#define INFO_MT_PAT_ADDR        (INFO_MT_ADDR    + 0x4)     /* Pattern : 1 for Random, 2 for Address, 3 for 0xffffffff */

#define INFO_CT_ADDR            (INFO_BASE_ADDR  + 0x30)    /* 0 : not started in current round, 1 : started in current round */
#define INFO_CT_PAT_ADDR        (INFO_CT_ADDR    + 0x4)     /* Pattern : 1 for Random, 2 for Address, 3 for 0xffffffff */

#define INFO_ERROR_T_ADDR           (INFO_BASE_ADDR    + 0x40)  /* 0 : error not found in current round, 1 : error found in current round */
#define INFO_ERROR_T_INVERSE_ADDR   (INFO_ERROR_T_ADDR + 0x4)   /* 0 : pattern, 1 : inverse pattern */
#define INFO_ERROR_T_STRIDE_ADDR    (INFO_ERROR_T_ADDR + 0x8)   /* Stride */
#define INFO_ERROR_T_OFFSET_ADDR    (INFO_ERROR_T_ADDR + 0xc)   /* Offset */
#define INFO_ERROR_T_ADR_ADDR       (INFO_ERROR_T_ADDR + 0x10)  /* Address */
#define INFO_ERROR_T_DATA_ADDR      (INFO_ERROR_T_ADDR + 0x14)  /* Actual Data */
#define INFO_ERROR_T_EDATA_ADDR     (INFO_ERROR_T_ADDR + 0x18)  /* Expected Data */

#define INFO_FAIL_ADDR          (INFO_BASE_ADDR + 0x60)     /* How many rounds at least one of all tests failed if errors were discarded */
#define INFO_FAIL_MT_ADDR       (INFO_FAIL_ADDR + 0x4)      /* How many rounds MT test                   failed if errors were discarded */
#define INFO_FAIL_CT_ADDR       (INFO_FAIL_ADDR + 0x8)      /* How many rounds CT test                   failed if errors were discarded */

/*
 * Cache Configuration
 */
#define CFG_DCACHE_SIZE		32768
#define CFG_ICACHE_SIZE		65536
#define CFG_CACHELINE_SIZE	32

/*
 * Cache Operations
 */
#define Index_Invalidate_I      0x00
#define Index_Writeback_Inv_D   0x01
#define Index_Invalidate_SI     0x02
#define Index_Writeback_Inv_SD  0x03
#define Index_Load_Tag_I	0x04
#define Index_Load_Tag_D	0x05
#define Index_Load_Tag_SI	0x06
#define Index_Load_Tag_SD	0x07
#define Index_Store_Tag_I	0x08
#define Index_Store_Tag_D	0x09
#define Index_Store_Tag_SI	0x0A
#define Index_Store_Tag_SD	0x0B
#define Create_Dirty_Excl_D	0x0d
#define Create_Dirty_Excl_SD	0x0f
#define Hit_Invalidate_I	0x10
#define Hit_Invalidate_D	0x11
#define Hit_Invalidate_SI	0x12
#define Hit_Invalidate_SD	0x13
#define Fill			0x14
#define Hit_Writeback_Inv_D	0x15
					/* 0x16 is unused */
#define Hit_Writeback_Inv_SD	0x17
#define Hit_Writeback_I		0x18
#define Hit_Writeback_D		0x19
					/* 0x1a is unused */
#define Hit_Writeback_SD	0x1b
					/* 0x1c is unused */
					/* 0x1e is unused */
#define Hit_Set_Virtual_SI	0x1e
#define Hit_Set_Virtual_SD	0x1f
