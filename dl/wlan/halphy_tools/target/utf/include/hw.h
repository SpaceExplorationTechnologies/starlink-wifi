/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
/* hw.h - macros and definitions for sim environment hardware access */

/*
 * Copyright (c) 2001 Atheros Communications, Inc., All Rights Reserved
 * $ATH_LICENSE_TARGET_C$
 */

/* 
modification history
--------------------
*/
#ifndef __INChwh
#define __INChwh

/* includes */
//#include "dk_common.h"
#include "dk_client.h"
#include "ar5523defs.h"

#if defined(AR900B) || defined(QCA9984) || defined(QCA9888)
#define IS_BB_ADDR(_arg)		((0x10000 <= (_arg)) && ((_arg) <= 0x4EFFC))
#define IS_RFFE_M_CSR(_arg)		((0x50000 <= (_arg)) && ((_arg) <= 0x503FC))
#define IS_SOC_REG(_arg)		((0x80000 <= (_arg)) && ((_arg) <= 0x913FC))
#define IS_PMU_REG(_arg)		((0x91FC0 <= (_arg)) && ((_arg) <= 0x91FFC))
#define IS_VALID_REG(_arg)		(IS_BB_ADDR(_arg) || IS_RFFE_M_CSR(_arg) || IS_SOC_REG(_arg) || IS_PMU_REG(_arg))
#else
#define MAX_REG_OFFSET		0x3fffc	    /* maximum platform register offset */
#endif

#if defined(IPQ4019)
#define IS_BB_ADDR(_arg)        ((0x10000 <= (_arg)) && ((_arg) <= 0x4EFFC))
#define IS_RFFE_M_CSR(_arg)     ((0x50000 <= (_arg)) && ((_arg) <= 0x50014))
#define IS_SOC_REG(_arg)        ((0x80000 <= (_arg)) && ((_arg) <= 0x913FC))
#define IS_PCIE_REG(_arg)       ((0xA0000 <= (_arg)) && ((_arg) <= 0xA604C))
#if defined(MERLIN_RADIO_EMU) && defined(FPGA)
#define IS_MERLIN_REG(_arg)     ((0xA9000 <= (_arg)) && ((_arg) <= 0xA9098))
#else
#define IS_MERLIN_REG(_arg)     0
#endif
#define IS_VALID_REG(_arg)      (IS_BB_ADDR(_arg) || IS_RFFE_M_CSR(_arg) || IS_SOC_REG(_arg) || IS_PCIE_REG(_arg) || IS_MERLIN_REG(_arg))  
#endif



#define MAX_CFG_OFFSET          256         /* maximum locations for PCI config space per device */
//#define MAX_MEMREAD_BYTES       2048        /* maximum of 2k location per OSmemRead action */
#define MAX_CLIENTS_SUPPORTED 1

/*
 * MDK_WLAN_DEV_INFO structure will hold all kinds of device related information.
 * It will hold OS specific information about the device and a device number.
 * Most of the code doesn't need to know what's inside that structure.
 * The fields are very likely to change.
 */
typedef	struct	mdk_wlanDevInfo
{
	struct dkDevInfo *pdkInfo;   	/* pointer to structure containing info for dk */
	A_UINT32	kpHandle;		/* Device number. */
	A_UCHAR	   	*pbuffMapBytes; /* holds bit maps for buffers allocated */
    A_UINT16   	*pnumBuffs;     /* holds number of buffers allocated by each index */
} MDK_WLAN_DEV_INFO;

/* WLAN_DRIVER_INFO structure will hold the driver global information.
 *
 */
typedef struct mdk_wlanDrvInfo
{
	A_UINT32       devCount;               	/* No. of currently connected devices */
	MDK_WLAN_DEV_INFO *pDevInfoArray[MAX_CLIENTS_SUPPORTED]; 	/* Array of devinfo pointers */
} MDK_WLAN_DRV_INFO;

// extern variable declarations
extern MDK_WLAN_DRV_INFO	globDrvInfo; 

#endif /* __INChwh */
