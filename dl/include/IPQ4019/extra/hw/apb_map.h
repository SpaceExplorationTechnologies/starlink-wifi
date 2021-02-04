/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
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

/* NOTE: chip_top_reg_map.h contains all WIFI blocks(e.g. WIFI RTC, WIFI Coex, WIFI TIMER, WIFI MAC, WICI CMN etc.)
         Registers in chip_top_reg_map.h contains addresses which are offset from base 0x0.
*/

//TODO LS cleanup this, take of redundunt values and keep only the ones that have not been defined in HW registers

/* NOTE that in Beeliner, the register addresses defined in hw header 
 *      file are absolute so base addresses here are 0. 
 */

#define RTC_SOC_BASE_ADDRESS                     0x00000000
#define RTC_WMAC_BASE_ADDRESS                    0x00000000 
#define MAC_COEX_BASE_ADDRESS                    0x00000000
#define BT_COEX_BASE_ADDRESS                     0x00000000
#define PTA_COEX_BASE_ADDRESS                    0x00000000
#define SOC_PCIE_BASE_ADDRESS                    0x00000000  
#define SOC_CORE_BASE_ADDRESS                    0x00000000
#define WLAN_UART_BASE_ADDRESS                   0x00000000 
#define WLAN_SI_BASE_ADDRESS                     0x00000000
#define WLAN_GPIO_BASE_ADDRESS                   0x00000000
#define WLAN_ANALOG_INTF_BASE_ADDRESS            0x00000000  
#define WLAN_MAC_BASE_ADDRESS                    0x00000000
#define FPGA_REG_BASE_ADDRESS                    0x00000000
#define CE0_BASE_ADDRESS                         0x0004a000 /* Used by host to compute the ce register block size? */
#define CE1_BASE_ADDRESS                         0x0004a400
#define CE2_BASE_ADDRESS                         0x0004a800
#define CE3_BASE_ADDRESS                         0x0004ac00
#define CE4_BASE_ADDRESS                         0x0004b000
#define CE5_BASE_ADDRESS                         0x0004b400
#define CE6_BASE_ADDRESS                         0x0004b800
#define CE7_BASE_ADDRESS                         0x0004bc00
#define CE8_BASE_ADDRESS                         0x0004c000
#define CE9_BASE_ADDRESS                         0x0004c400
#define CE10_BASE_ADDRESS                        0x0004c800
#define CE11_BASE_ADDRESS                        0x0004cc00
#define CE_WRAPPER_BASE_ADDRESS                  0x00000000  // 0x4d000
#define DBI_BASE_ADDRESS                         0x00089000  
#define PCIE_PHY_BASE_ADDRESS                    0x0008D000  

#if defined AR900B_WIFITOP_EMU_WAR
#undef WLAN_ANALOG_INTF_PCIE_BASE_ADDRESS
#else
#define WLAN_ANALOG_INTF_PCIE_BASE_ADDRESS       0x00000000
#endif
/* Following bases are needed by map_dma_reg, map_pcu_reg
   and map_rtc_wlan_reg files.
*/
/* START*/
#define WIFICMN_BASE_ADDRESS                     0x00000000
#define WIFI_RTC_BASE_ADDRESS                    0x00000000
#define WIFI_TIMERS_BASE_ADDRESS                 0x00000000
#define WIFI_MCI_COEX_BASE_ADDRESS               0x00000000
#define WIFI_EPTA_COEX_BASE_ADDRESS              0x00000000
#define WIFI_PTA_COEX_BASE_ADDRESS               0x00000000
#define WIFI_CXM_REG_BASE_ADDRESS                0x00000000
#define MAC_CRYPTO_BASE_ADDRESS                  0x00000000
#define MAC_RXPCU_BASE_ADDRESS                   0x00000000
#define MAC_TXPCU_BASE_ADDRESS                   0x00000000
#define RXDMA_BASE_ADDRESS                       0x00000000
/* END */

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
