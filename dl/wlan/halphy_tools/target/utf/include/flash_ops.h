/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
// Copyright (c) 2010 Atheros Communications Inc.
// All rights reserved.
// $ATH_LICENSE_TARGET_C$

#ifndef __INCflash_ops_h__
#define __INCflash_ops_h__

#ifdef AR6K
#include "soc/soc.h"
#endif

#define sysRegRead(_addr)         (*((volatile A_ULONG *)((A_UINT32)(_addr)| A_MIPS_KSEG_UNCACHED)))
#define sysRegWrite(_addr, _val)  (*((volatile A_ULONG *)((A_UINT32)(_addr)| A_MIPS_KSEG_UNCACHED)) = (_val))
#define sysRegRead16(_addr)         (*((volatile A_UINT16 *)((A_UINT32)(_addr)| A_MIPS_KSEG_UNCACHED)))
#define sysRegWrite16(_addr, _val)  (*((volatile A_UINT16 *)((A_UINT32)(_addr)| A_MIPS_KSEG_UNCACHED)) = (_val))
#define sysRegRead8(_addr)         (*((volatile A_UINT8 *)((A_UINT32)(_addr)| A_MIPS_KSEG_UNCACHED)))
#define sysRegWrite8(_addr, _val)  (*((volatile A_UINT8 *)((A_UINT32)(_addr)| A_MIPS_KSEG_UNCACHED)) = (_val))
#define SAVED_DATA_LENGTH 4


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

extern A_UINT32 sysEepromRead(A_UINT32 offset);
extern A_INT8 sysEepromWrite(A_UINT32 addr, A_UINT8 *data, A_UINT32 size);

extern A_UINT32 sysFlashRead(A_UINT32 offset);
extern A_INT8 sysFlashConfigWrite(A_UINT32 addr, A_UINT8 *data, A_UINT32 size);
extern void erase_sector(A_UINT32 sAddr);
extern void spi_unprotect_memory(void);
extern void sysFlashWrite(A_UINT32 sAddr, A_UINT32 data32);
extern A_UINT32 spi_get_device_id(void);
extern A_UINT8  *cal_offset;
extern A_UINT32 spi_deviceid;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif

