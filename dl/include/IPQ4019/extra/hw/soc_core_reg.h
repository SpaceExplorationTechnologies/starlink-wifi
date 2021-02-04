// ------------------------------------------------------------------
// Copyright (c) 2004-2007 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Atheros"
//===================================================================
#ifdef WLAN_HEADERS
#ifndef   __EXTRA_SOC_CORE_REG
#define  __EXTRA_SOC_CORE_REG

#include "wifi_top_reg_map.h"
#include "../../hw/soc_core_reg.h"
#include "../../hw/scratch_reg.h"

#define FW_AXI_MSI_ADDR	    (WIFI_SCRATCH_0_ADDRESS)
#define FW_AXI_MSI_DATA	    (WIFI_SCRATCH_1_ADDRESS)
#define FW_CPU_PLL_CONFIG   (WIFI_SCRATCH_5_ADDRESS)

/* Firmware indications to the Host via SCRATCH_3 register. */
#define FW_INDICATOR_ADDRESS 	(WIFI_SCRATCH_3_ADDRESS)
#define FW_IND_EVENT_PENDING    1
#define FW_IND_INITIALIZED      2
#define FW_IND_HOST_READY	    0x80000000

/* Interrupts masks for use with PCIE_INTR_CAUSE, PCIE_INTR_CLR */
#define PCIE_INTR_FIRMWARE_MASK 0x00100000 /* "HOST_REG" interrupt from firmware */
#define PCIE_INTR_CE0_MASK      0x00000100
#define PCIE_INTR_CE_MASK_ALL   0x000fff00 /* All CEs */
#define PCIE_INTR_CE_MASK(n)    (PCIE_INTR_CE0_MASK<<(n))


#define FW_AXI_MSI_STATUS_DATA_LSB     0
#define FW_AXI_MSI_STATUS_DATA_MASK    0x00ffffff
#define FW_AXI_MSI_STATUS_DATA_GET(x)  (((x) & FW_AXI_MSI_STATUS_DATA_MASK) >> FW_AXI_MSI_STATUS_DATA_LSB)

#define FW_AXI_MSI_STATUS_EN_LSB       24
#define FW_AXI_MSI_STATUS_EN_MASK      0xff000000
#define FW_AXI_MSI_STATUS_EN_GET(x)    (((x) & FW_AXI_MSI_STATUS_EN_MASK) >> FW_AXI_MSI_STATUS_EN_LSB)

#endif
#endif
