/*
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef __ar6000defsh___
#define __ar6000defsh___

// set a one in the bit position "s"
#define _SET_ONE_(s)            (1<<(s))
//
// // create a string of "w" ones, starting at bit position "s"
// // will not support a width of 0 (but then why would you want a width of
// 0?)


#define AR6000_EMULATION_MAJOR_REV0	0
#define AR6000_EMULATION_MINOR_REV0	0  
#define AR6000_MAJOR_REV0	6
#define AR6000_MINOR_REV0	0  
#define AR6000_MINOR_REV1	1  
#define REV_MIN_W 4
#define REV_MAJ_W 4
#define REV_MIN_S 0
#define REV_MAJ_S 4
#define REV_MIN_M 0xf
#define REV_MAJ_M 0xf0

#define AR6000_WMAC0_BASE_ADDRESS           0xafff0000 

#if defined(AR9888_VER1)
#include "hw/rtc_soc_reg.h"
#include "extra/hw/rtc_reg.h"
#include "extra/hw/apb_map.h"
#else
#include "hw/rtc_reg.h"
#include "hw/apb_map.h"
#endif
#ifdef AR6000
#include "AR6K/AR6K_addrs.h"
#endif
#include "htc_api.h"

#if defined(AR6320)
#include "hw/rtc_soc_reg.h"
#endif


#endif

