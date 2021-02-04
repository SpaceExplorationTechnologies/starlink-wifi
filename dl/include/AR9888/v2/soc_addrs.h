/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// Copyright (c) 2004-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

#ifndef __SOC_ADDRS_H__
#define __SOC_ADDRS_H__

/*
 * Special Platform Addresses that may be needed by special
 * applications (e.g. ART) on the Host as well as Target.
 *
 * TBDXXX: Use AR9888_ prefix for definitions that are visible
 * to both Host and Target.  Host may simultaneously include
 * soc_addrs.h files from multiple platforms, so avoid name
 * conflicts.  For Target, use more generic TARG_ prefix;
 * but only do this under a Target-specific ifdef.  There's
 * no use for an AR6K_ prefix.
 */

#define TARG_DRAM_START 0x00400000
#define TARG_RAM_START TARG_DRAM_START
#define AR6K_RAM_START TARG_DRAM_START
#define TARG_RAM_OFFSET(vaddr) (((A_UINT32)(vaddr) & 0x0fffff))

#if defined(REDUCED_FW_RAM_SZ)
#if REDUCED_FW_RAM_SZ
#define TARG_RAM_SZ_MAX  (256*1024)     /* Declare the reduced RAM/ROM */
#else
#define TARG_RAM_SZ_MAX  (320*1024)     /* Max possible DRAM size */
#endif
#endif

#define TARG_ROM_SZ      (256*1024)

#define TARG_IRAM_START 0x00980000
#define TARG_IRAM_SZ (320*1024)

#define TARG_RAM_ACS_RESERVE  32

#define AR6K_RAM_ADDR(byte_offset) (AR6K_RAM_START+(byte_offset))
#define TARG_RAM_ADDRS(byte_offset) AR6K_RAM_ADDR(byte_offset)

#define AR6K_ROM_START 0x00940000
#define TARG_ROM_OFFSET(vaddr) ((A_UINT32)(vaddr) & 0xfffff)
#define AR6K_ROM_ADDR(byte_offset) (AR6K_ROM_START+(byte_offset))
#define TARG_ROM_ADDRS(byte_offset) AR6K_ROM_ADDR(byte_offset)

/*
 * At this ROM address is a pointer to the start of the ROM DataSet Index.
 * If there are no ROM DataSets, there's a 0 at this address.
 */
#define ROM_DATASET_INDEX_ADDR          (TARG_ROM_ADDRS(TARG_ROM_SZ)-8)
#define ROM_MBIST_CKSUM_ADDR            (TARG_ROM_ADDRS(TARG_ROM_SZ)-4)

/*
 * The API A_BOARD_DATA_ADDR() is the proper way to get a read pointer to
 * board data.
 */

/* Size of Board Data, in bytes */
#define BOARD_DATA_SZ AR9888_BOARD_DATA_SZ

#endif /* __SOC_ADDRS_H__ */
