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

#include "hw/apb_athr_wlan_map.h"


#ifndef BT_HEADERS

#define UART_BASE_ADDRESS WLAN_UART_BASE_ADDRESS
#define UMBOX_BASE_ADDRESS WLAN_UMBOX_BASE_ADDRESS
#define SI_BASE_ADDRESS WLAN_SI_BASE_ADDRESS
#define GPIO_BASE_ADDRESS WLAN_GPIO_BASE_ADDRESS
#define ANALOG_INTF_BASE_ADDRESS WLAN_ANALOG_INTF_BASE_ADDRESS
#define MAC_BASE_ADDRESS WLAN_MAC_BASE_ADDRESS
#define UART2_BASE_ADDRESS WLAN_UART2_BASE_ADDRESS
#define RDMA_BASE_ADDRESS WLAN_RDMA_BASE_ADDRESS

#if defined(CONFIG_DBG_UART_ALTERNATE)
#define DBG_UART_BASE_ADDRESS WLAN_UART2_BASE_ADDRESS
#else
#define DBG_UART_BASE_ADDRESS WLAN_UART_BASE_ADDRESS
#endif

#endif
#endif
