/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
// ------------------------------------------------------------------
// Copyright (c) 2004-2007 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Atheros"
//===================================================================


#ifdef WLAN_HEADERS

#include "../../hw/soc_core_reg.h"

/* Firmware indications to the Host via SCRATCH_3 register. */
#define FW_INDICATOR_ADDRESS (SOC_CORE_BASE_ADDRESS+SCRATCH_3_ADDRESS)
#define FW_IND_EVENT_PENDING    1
#define FW_IND_INITIALIZED      2

/* Interrupts masks for use with PCIE_INTR_CAUSE, PCIE_INTR_CLR */
#define PCIE_INTR_FIRMWARE_MASK 0x00000400 /* "HOST_REG" interrupt from firmware */
#define PCIE_INTR_CE0_MASK      0x00000800
#define PCIE_INTR_CE_MASK_ALL   0x0007f800 /* All CEs */
#define PCIE_INTR_CE_MASK(n)    (PCIE_INTR_CE0_MASK<<(n))

#endif
