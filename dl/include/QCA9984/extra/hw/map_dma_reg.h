//                                                                             
// File:       ./mac_dma_reg.h                                                 
// Creator:    knam                                                            
// Time:       Thursday Oct 25, 2012 [5:35:45 pm]                              
//                                                                             
// Path:       /trees/knam/knam-dev/ip/athr/wifi/dev/rtl/mac/rtl/mac_dma/blueprint
// Arguments:  /cad/denali/blueprint/3.7.3//Linux/blueprint -odir . -codegen   
//             ath_vrh.codegen -ath_vrh -ch -Wdesc mac_dma_reg.rdl             
//                                                                             
// Sources:    /trees/knam/knam-dev/ip/athr/wifi/dev/rtl/mac/rtl/mac_dma/blueprint/mac_dma_reg.rdl
//             /trees/knam/knam-dev/ip/athr/wifi/dev/shared/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.3 (Fri Aug 29 12:46:00 PDT 2008)                           
// Machine:    saturn                                                          
// OS:         Linux 2.6.9-78.ELsmp                                            
// Description:                                                                
//                                                                             
// No Description Provided                                                     
//                                                                             
// Copyright (c) 2014 Qualcomm Atheros, Inc.  All rights reserved.
//                                                                             


#ifndef _MAC_DMA_REG_H_
#define _MAC_DMA_REG_H_
#include "wifi_top_reg_map.h"
// 32'h0008 (MAC_DMA_CR)
// Reason:Obsolete. 	 #define MAC_DMA_CR_SWI_MSB 		 MAC_DMA_CR_SWI_MSB
// Reason:Obsolete. 	 #define MAC_DMA_CR_SWI_LSB 		 MAC_DMA_CR_SWI_LSB
// Reason:Obsolete. 	 #define MAC_DMA_CR_SWI_MASK 		 MAC_DMA_CR_SWI_MASK
// Reason:Obsolete. 	 #define MAC_DMA_CR_SWI_GET(x) 		 MAC_DMA_CR_SWI_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CR_SWI_SET(x) 		 MAC_DMA_CR_SWI_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CR_SWI_RESET 		 MAC_DMA_CR_SWI_RESET
// Reason:Obsolete. 	 #define MAC_DMA_CR_RXD_MSB 		 MAC_DMA_CR_RXD_MSB
// Reason:Obsolete. 	 #define MAC_DMA_CR_RXD_LSB 		 MAC_DMA_CR_RXD_LSB
// Reason:Obsolete. 	 #define MAC_DMA_CR_RXD_MASK 		 MAC_DMA_CR_RXD_MASK
// Reason:Obsolete. 	 #define MAC_DMA_CR_RXD_GET(x) 		 MAC_DMA_CR_RXD_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CR_RXD_SET(x) 		 MAC_DMA_CR_RXD_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CR_RXD_RESET 		 MAC_DMA_CR_RXD_RESET
// Reason:Obsolete. 	 #define MAC_DMA_CR_ADDRESS 		 MAC_DMA_CR_ADDRESS
// Reason:Obsolete. 	 #define MAC_DMA_CR_OFFSET 		 MAC_DMA_CR_OFFSET
// SW modifiable bits
// Reason:Obsolete. 	 #define MAC_DMA_CR_SW_MASK 		 MAC_DMA_CR_SW_MASK
// bits defined at reset
// Reason:Obsolete. 	 #define MAC_DMA_CR_RSTMASK 		 MAC_DMA_CR_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete. 	 #define MAC_DMA_CR_RESET 		 MAC_DMA_CR_RESET

// 32'h0014 (MAC_DMA_CFG)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PPDU_END_SWAP_MSB 		 MAC_DMA_CFG_TX_PPDU_END_SWAP_MSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PPDU_END_SWAP_LSB 		 MAC_DMA_CFG_TX_PPDU_END_SWAP_LSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PPDU_END_SWAP_MASK 		 MAC_DMA_CFG_TX_PPDU_END_SWAP_MASK
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PPDU_END_SWAP_GET(x) 		 MAC_DMA_CFG_TX_PPDU_END_SWAP_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PPDU_END_SWAP_SET(x) 		 MAC_DMA_CFG_TX_PPDU_END_SWAP_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PPDU_END_SWAP_RESET 		 MAC_DMA_CFG_TX_PPDU_END_SWAP_RESET
#define MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_MSB 		 MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_MSB
#define MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_LSB 		 MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_LSB
#define MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_MASK 		 MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_MASK
#define MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_GET(x) 		 MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_GET(x)
#define MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_SET(x) 		 MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_SET(x)
#define MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_RESET 		 MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_RESET
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PACKET_SWAP_MSB 		 MAC_DMA_CFG_TX_PACKET_SWAP_MSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PACKET_SWAP_MSB 		 MAC_DMA_CFG_TX_PACKET_SWAP_MSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PACKET_SWAP_LSB 		 MAC_DMA_CFG_TX_PACKET_SWAP_LSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PACKET_SWAP_LSB 		 MAC_DMA_CFG_TX_PACKET_SWAP_LSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PACKET_SWAP_MASK 		 MAC_DMA_CFG_TX_PACKET_SWAP_MASK
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PACKET_SWAP_MASK 		 MAC_DMA_CFG_TX_PACKET_SWAP_MASK
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PACKET_SWAP_GET(x) 		 MAC_DMA_CFG_TX_PACKET_SWAP_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PACKET_SWAP_GET(x) 		 MAC_DMA_CFG_TX_PACKET_SWAP_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PACKET_SWAP_SET(x) 		 MAC_DMA_CFG_TX_PACKET_SWAP_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PACKET_SWAP_SET(x) 		 MAC_DMA_CFG_TX_PACKET_SWAP_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PACKET_SWAP_RESET 		 MAC_DMA_CFG_TX_PACKET_SWAP_RESET
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_PACKET_SWAP_RESET 		 MAC_DMA_CFG_TX_PACKET_SWAP_RESET
// Reason:Obsolete. 	 #define MAC_DMA_CFG_PEER_ENTRY_SWAP_MSB 		 MAC_DMA_CFG_PEER_ENTRY_SWAP_MSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_PEER_ENTRY_SWAP_LSB 		 MAC_DMA_CFG_PEER_ENTRY_SWAP_LSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_PEER_ENTRY_SWAP_MASK 		 MAC_DMA_CFG_PEER_ENTRY_SWAP_MASK
// Reason:Obsolete. 	 #define MAC_DMA_CFG_PEER_ENTRY_SWAP_GET(x) 		 MAC_DMA_CFG_PEER_ENTRY_SWAP_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_PEER_ENTRY_SWAP_SET(x) 		 MAC_DMA_CFG_PEER_ENTRY_SWAP_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_PEER_ENTRY_SWAP_RESET 		 MAC_DMA_CFG_PEER_ENTRY_SWAP_RESET
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_MSDU_START_SWAP_MSB 		 MAC_DMA_CFG_TX_MSDU_START_SWAP_MSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_MSDU_START_SWAP_LSB 		 MAC_DMA_CFG_TX_MSDU_START_SWAP_LSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_MSDU_START_SWAP_MASK 		 MAC_DMA_CFG_TX_MSDU_START_SWAP_MASK
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_MSDU_START_SWAP_GET(x) 		 MAC_DMA_CFG_TX_MSDU_START_SWAP_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_MSDU_START_SWAP_SET(x) 		 MAC_DMA_CFG_TX_MSDU_START_SWAP_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_TX_MSDU_START_SWAP_RESET 		 MAC_DMA_CFG_TX_MSDU_START_SWAP_RESET
#define MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_MSB 		 TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_MSB
#define MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_LSB 		 TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_LSB
#define MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_MASK 		 TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_MASK
#define MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_GET(x) 		 TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_GET(x)
#define MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_SET(x) 		 TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_SET(x)
#define MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_RESET 		 TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_RESET
#define MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_MSB 		 TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_MSB
#define MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_LSB 		 TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_LSB
#define MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_MASK 		 TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_MASK
#define MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_GET(x) 		 TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_GET(x)
#define MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_SET(x) 		 TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_SET(x)
#define MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_RESET 		 TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_RESET
#define MAC_DMA_CFG_HALT_ACK_MSB 		 MXI_STATUS_HALT_ACK_MSB
#define MAC_DMA_CFG_HALT_ACK_LSB 		 MXI_STATUS_HALT_ACK_LSB
#define MAC_DMA_CFG_HALT_ACK_MASK 		 MXI_STATUS_HALT_ACK_MASK
#define MAC_DMA_CFG_HALT_ACK_GET(x) 		 MXI_STATUS_HALT_ACK_GET(x)
#define MAC_DMA_CFG_HALT_ACK_SET(x) 		 MXI_STATUS_HALT_ACK_SET(x)
#define MAC_DMA_CFG_HALT_ACK_RESET 		 MXI_STATUS_HALT_ACK_RESET
#define MAC_DMA_CFG_HALT_REQ_MSB 		 MXI_CFG_12_HALT_REQ_MSB
#define MAC_DMA_CFG_HALT_REQ_LSB 		 MXI_CFG_12_HALT_REQ_LSB
#define MAC_DMA_CFG_HALT_REQ_MASK 		 MXI_CFG_12_HALT_REQ_MASK
#define MAC_DMA_CFG_HALT_REQ_GET(x) 		 MXI_CFG_12_HALT_REQ_GET(x)
#define MAC_DMA_CFG_HALT_REQ_SET(x) 		 MXI_CFG_12_HALT_REQ_SET(x)
#define MAC_DMA_CFG_HALT_REQ_RESET 		 MXI_CFG_12_HALT_REQ_RESET
// Reason:TODO: Not exist. 	 #define MAC_DMA_CFG_CLKGATE_DIS_MSB 		 MAC_DMA_CFG_CLKGATE_DIS_MSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_CFG_CLKGATE_DIS_LSB 		 MAC_DMA_CFG_CLKGATE_DIS_LSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_CFG_CLKGATE_DIS_MASK 		 MAC_DMA_CFG_CLKGATE_DIS_MASK
// Reason:TODO: Not exist. 	 #define MAC_DMA_CFG_CLKGATE_DIS_GET(x) 		 MAC_DMA_CFG_CLKGATE_DIS_GET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_CFG_CLKGATE_DIS_SET(x) 		 MAC_DMA_CFG_CLKGATE_DIS_SET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_CFG_CLKGATE_DIS_RESET 		 MAC_DMA_CFG_CLKGATE_DIS_RESET
// Reason:Obsolete. 	 #define MAC_DMA_CFG_EEPROM_BUSY_MSB 		 MAC_DMA_CFG_EEPROM_BUSY_MSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_EEPROM_BUSY_LSB 		 MAC_DMA_CFG_EEPROM_BUSY_LSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_EEPROM_BUSY_MASK 		 MAC_DMA_CFG_EEPROM_BUSY_MASK
// Reason:Obsolete. 	 #define MAC_DMA_CFG_EEPROM_BUSY_GET(x) 		 MAC_DMA_CFG_EEPROM_BUSY_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_EEPROM_BUSY_SET(x) 		 MAC_DMA_CFG_EEPROM_BUSY_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_EEPROM_BUSY_RESET 		 MAC_DMA_CFG_EEPROM_BUSY_RESET
// Reason:Obsolete. 	 #define MAC_DMA_CFG_PHY_OK_MSB 		 MAC_DMA_CFG_PHY_OK_MSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_PHY_OK_LSB 		 MAC_DMA_CFG_PHY_OK_LSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_PHY_OK_MASK 		 MAC_DMA_CFG_PHY_OK_MASK
// Reason:Obsolete. 	 #define MAC_DMA_CFG_PHY_OK_GET(x) 		 MAC_DMA_CFG_PHY_OK_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_PHY_OK_SET(x) 		 MAC_DMA_CFG_PHY_OK_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_PHY_OK_RESET 		 MAC_DMA_CFG_PHY_OK_RESET
// Reason:Obsolete. 	 #define MAC_DMA_CFG_ADHOC_MSB 		 MAC_DMA_CFG_ADHOC_MSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_ADHOC_LSB 		 MAC_DMA_CFG_ADHOC_LSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_ADHOC_MASK 		 MAC_DMA_CFG_ADHOC_MASK
// Reason:Obsolete. 	 #define MAC_DMA_CFG_ADHOC_GET(x) 		 MAC_DMA_CFG_ADHOC_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_ADHOC_SET(x) 		 MAC_DMA_CFG_ADHOC_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_ADHOC_RESET 		 MAC_DMA_CFG_ADHOC_RESET
// Reason:Obsolete. 	 #define MAC_DMA_CFG_BE_MODE_MMR_MSB 		 MAC_DMA_CFG_BE_MODE_MMR_MSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_BE_MODE_MMR_LSB 		 MAC_DMA_CFG_BE_MODE_MMR_LSB
// Reason:Obsolete. 	 #define MAC_DMA_CFG_BE_MODE_MMR_MASK 		 MAC_DMA_CFG_BE_MODE_MMR_MASK
// Reason:Obsolete. 	 #define MAC_DMA_CFG_BE_MODE_MMR_GET(x) 		 MAC_DMA_CFG_BE_MODE_MMR_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_BE_MODE_MMR_SET(x) 		 MAC_DMA_CFG_BE_MODE_MMR_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_CFG_BE_MODE_MMR_RESET 		 MAC_DMA_CFG_BE_MODE_MMR_RESET
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_MSB 		 MAC_DMA_CFG_RESET_INT_MIT_CNTRS_MSB
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_MSB 		 MAC_DMA_CFG_RESET_INT_MIT_CNTRS_MSB
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_LSB 		 MAC_DMA_CFG_RESET_INT_MIT_CNTRS_LSB
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_LSB 		 MAC_DMA_CFG_RESET_INT_MIT_CNTRS_LSB
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_MASK 		 MAC_DMA_CFG_RESET_INT_MIT_CNTRS_MASK
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_MASK 		 MAC_DMA_CFG_RESET_INT_MIT_CNTRS_MASK
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_GET(x) 		 MAC_DMA_CFG_RESET_INT_MIT_CNTRS_GET(x)
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_GET(x) 		 MAC_DMA_CFG_RESET_INT_MIT_CNTRS_GET(x)
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_SET(x) 		 MAC_DMA_CFG_RESET_INT_MIT_CNTRS_SET(x)
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_SET(x) 		 MAC_DMA_CFG_RESET_INT_MIT_CNTRS_SET(x)
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_RESET 		 MAC_DMA_CFG_RESET_INT_MIT_CNTRS_RESET
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_RESET 		 MAC_DMA_CFG_RESET_INT_MIT_CNTRS_RESET
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_MSB 		 MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_MSB
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_LSB 		 MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_LSB
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_MASK 		 MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_MASK
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_GET(x) 		 MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_GET(x)
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_SET(x) 		 MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_SET(x)
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_RESET 		 MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_RESET
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_MSB 		 MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_MSB
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_LSB 		 MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_LSB
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_MASK 		 MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_MASK
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_GET(x) 		 MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_GET(x)
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_SET(x) 		 MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_SET(x)
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_RESET 		 MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_RESET
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_ADDRESS 		 MAC_DMA_CFG_ADDRESS
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_OFFSET 		 MAC_DMA_CFG_OFFSET
// SW modifiable bits
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_SW_MASK 		 MAC_DMA_CFG_SW_MASK
// bits defined at reset
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RSTMASK 		 MAC_DMA_CFG_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete even in Peregrine. 	 #define MAC_DMA_CFG_RESET 		 MAC_DMA_CFG_RESET

// 32'h001c (MAC_DMA_TXDPPTR_THRESH)
// Reason:Obsolete: archtecture change. 	 #define MAC_DMA_TXDPPTR_THRESH_DATA_MSB 		 MAC_DMA_TXDPPTR_THRESH_DATA_MSB
// Reason:Obsolete: archtecture change. 	 #define MAC_DMA_TXDPPTR_THRESH_DATA_LSB 		 MAC_DMA_TXDPPTR_THRESH_DATA_LSB
// Reason:Obsolete: archtecture change. 	 #define MAC_DMA_TXDPPTR_THRESH_DATA_MASK 		 MAC_DMA_TXDPPTR_THRESH_DATA_MASK
// Reason:Obsolete: archtecture change. 	 #define MAC_DMA_TXDPPTR_THRESH_DATA_GET(x) 		 MAC_DMA_TXDPPTR_THRESH_DATA_GET(x)
// Reason:Obsolete: archtecture change. 	 #define MAC_DMA_TXDPPTR_THRESH_DATA_SET(x) 		 MAC_DMA_TXDPPTR_THRESH_DATA_SET(x)
// Reason:Obsolete: archtecture change. 	 #define MAC_DMA_TXDPPTR_THRESH_DATA_RESET 		 MAC_DMA_TXDPPTR_THRESH_DATA_RESET
// Reason:Obsolete: archtecture change. 	 #define MAC_DMA_TXDPPTR_THRESH_ADDRESS 		 MAC_DMA_TXDPPTR_THRESH_ADDRESS
// Reason:Obsolete: archtecture change. 	 #define MAC_DMA_TXDPPTR_THRESH_OFFSET 		 MAC_DMA_TXDPPTR_THRESH_OFFSET
// SW modifiable bits
// Reason:Obsolete: archtecture change. 	 #define MAC_DMA_TXDPPTR_THRESH_SW_MASK 		 MAC_DMA_TXDPPTR_THRESH_SW_MASK
// bits defined at reset
// Reason:Obsolete: archtecture change. 	 #define MAC_DMA_TXDPPTR_THRESH_RSTMASK 		 MAC_DMA_TXDPPTR_THRESH_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: archtecture change. 	 #define MAC_DMA_TXDPPTR_THRESH_RESET 		 MAC_DMA_TXDPPTR_THRESH_RESET

// 32'h0024 (MAC_DMA_GLOBAL_IER)
// Reason:TODO: Is it needed or interrupt mask is enough? 	 #define MAC_DMA_GLOBAL_IER_ENABLE_MSB 		 MAC_DMA_GLOBAL_IER_ENABLE_MSB
// Reason:TODO: Is it needed or interrupt mask is enough? 	 #define MAC_DMA_GLOBAL_IER_ENABLE_LSB 		 MAC_DMA_GLOBAL_IER_ENABLE_LSB
// Reason:TODO: Is it needed or interrupt mask is enough? 	 #define MAC_DMA_GLOBAL_IER_ENABLE_MASK 		 MAC_DMA_GLOBAL_IER_ENABLE_MASK
// Reason:TODO: Is it needed or interrupt mask is enough? 	 #define MAC_DMA_GLOBAL_IER_ENABLE_GET(x) 		 MAC_DMA_GLOBAL_IER_ENABLE_GET(x)
// Reason:TODO: Is it needed or interrupt mask is enough? 	 #define MAC_DMA_GLOBAL_IER_ENABLE_SET(x) 		 MAC_DMA_GLOBAL_IER_ENABLE_SET(x)
// Reason:TODO: Is it needed or interrupt mask is enough? 	 #define MAC_DMA_GLOBAL_IER_ENABLE_RESET 		 MAC_DMA_GLOBAL_IER_ENABLE_RESET
// Reason:TODO: Is it needed or interrupt mask is enough? 	 #define MAC_DMA_GLOBAL_IER_ADDRESS 		 MAC_DMA_GLOBAL_IER_ADDRESS
// Reason:TODO: Is it needed or interrupt mask is enough? 	 #define MAC_DMA_GLOBAL_IER_OFFSET 		 MAC_DMA_GLOBAL_IER_OFFSET
// SW modifiable bits
// Reason:TODO: Is it needed or interrupt mask is enough? 	 #define MAC_DMA_GLOBAL_IER_SW_MASK 		 MAC_DMA_GLOBAL_IER_SW_MASK
// bits defined at reset
// Reason:TODO: Is it needed or interrupt mask is enough? 	 #define MAC_DMA_GLOBAL_IER_RSTMASK 		 MAC_DMA_GLOBAL_IER_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:TODO: Is it needed or interrupt mask is enough? 	 #define MAC_DMA_GLOBAL_IER_RESET 		 MAC_DMA_GLOBAL_IER_RESET

// 32'h0030 (MAC_DMA_TXCFG)
// Reason:Obsolete 	 #define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_MSB 		 MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_MSB
// Reason:Obsolete 	 #define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_LSB 		 MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_LSB
// Reason:Obsolete 	 #define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_MASK 		 MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_MASK
// Reason:Obsolete 	 #define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_GET(x) 		 MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_SET(x) 		 MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_RESET 		 MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_RESET
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_MSB 		 MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_MSB
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_LSB 		 MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_LSB
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_MASK 		 MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_MASK
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_GET(x) 		 MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_SET(x) 		 MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_RESET 		 MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_RESET
#define MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_MSB 		 MXI_CFG_11_AXI_TIMER_VALUE_MSB
#define MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_LSB 		 MXI_CFG_11_AXI_TIMER_VALUE_LSB
#define MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_MASK 		 MXI_CFG_11_AXI_TIMER_VALUE_MASK
#define MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_GET(x) 		 MXI_CFG_11_AXI_TIMER_VALUE_GET(x)
#define MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_SET(x) 		 MXI_CFG_11_AXI_TIMER_VALUE_SET(x)
#define MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_RESET 		 MXI_CFG_11_AXI_TIMER_VALUE_RESET
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_RTCI_DIS_MSB 		 MAC_DMA_TXCFG_RTCI_DIS_MSB
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_RTCI_DIS_LSB 		 MAC_DMA_TXCFG_RTCI_DIS_LSB
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_RTCI_DIS_MASK 		 MAC_DMA_TXCFG_RTCI_DIS_MASK
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_RTCI_DIS_GET(x) 		 MAC_DMA_TXCFG_RTCI_DIS_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_RTCI_DIS_SET(x) 		 MAC_DMA_TXCFG_RTCI_DIS_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_RTCI_DIS_RESET 		 MAC_DMA_TXCFG_RTCI_DIS_RESET
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_ATIM_DEFER_DIS_MSB 		 MAC_DMA_TXCFG_ATIM_DEFER_DIS_MSB
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_ATIM_DEFER_DIS_LSB 		 MAC_DMA_TXCFG_ATIM_DEFER_DIS_LSB
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_ATIM_DEFER_DIS_MASK 		 MAC_DMA_TXCFG_ATIM_DEFER_DIS_MASK
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_ATIM_DEFER_DIS_GET(x) 		 MAC_DMA_TXCFG_ATIM_DEFER_DIS_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_ATIM_DEFER_DIS_SET(x) 		 MAC_DMA_TXCFG_ATIM_DEFER_DIS_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_ATIM_DEFER_DIS_RESET 		 MAC_DMA_TXCFG_ATIM_DEFER_DIS_RESET
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_MSB 		 MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_MSB
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_LSB 		 MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_LSB
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_MASK 		 MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_MASK
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_GET(x) 		 MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_SET(x) 		 MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_RESET 		 MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_RESET
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_JUMBO_EN_MSB 		 MAC_DMA_TXCFG_JUMBO_EN_MSB
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_JUMBO_EN_LSB 		 MAC_DMA_TXCFG_JUMBO_EN_LSB
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_JUMBO_EN_MASK 		 MAC_DMA_TXCFG_JUMBO_EN_MASK
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_JUMBO_EN_GET(x) 		 MAC_DMA_TXCFG_JUMBO_EN_GET(x)
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_JUMBO_EN_SET(x) 		 MAC_DMA_TXCFG_JUMBO_EN_SET(x)
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_JUMBO_EN_RESET 		 MAC_DMA_TXCFG_JUMBO_EN_RESET
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_TRIGLVL_MSB 		 MAC_DMA_TXCFG_TRIGLVL_MSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_TRIGLVL_LSB 		 MAC_DMA_TXCFG_TRIGLVL_LSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_TRIGLVL_MASK 		 MAC_DMA_TXCFG_TRIGLVL_MASK
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_TRIGLVL_GET(x) 		 MAC_DMA_TXCFG_TRIGLVL_GET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_TRIGLVL_SET(x) 		 MAC_DMA_TXCFG_TRIGLVL_SET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_TRIGLVL_RESET 		 MAC_DMA_TXCFG_TRIGLVL_RESET
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_MSB 		 MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_MSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_LSB 		 MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_LSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_MASK 		 MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_MASK
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_GET(x) 		 MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_GET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_SET(x) 		 MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_SET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_RESET 		 MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_RESET
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_MSB 		 MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_MSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_LSB 		 MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_LSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_MASK 		 MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_MASK
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_GET(x) 		 MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_GET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_SET(x) 		 MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_SET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_RESET 		 MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_RESET
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_MSB 		 MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_MSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_LSB 		 MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_LSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_MASK 		 MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_MASK
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_GET(x) 		 MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_GET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_SET(x) 		 MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_SET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_RESET 		 MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_RESET
#define MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_MSB 		 MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_MSB
#define MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_LSB 		 MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_LSB
#define MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_MASK 		 MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_MASK
#define MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_GET(x) 		 MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_GET(x)
#define MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_SET(x) 		 MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_SET(x)
#define MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_RESET 		 MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_RESET
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_ADDRESS 		 MAC_DMA_TXCFG_ADDRESS
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_OFFSET 		 MAC_DMA_TXCFG_OFFSET
// SW modifiable bits
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_SW_MASK 		 MAC_DMA_TXCFG_SW_MASK
// bits defined at reset
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_RSTMASK 		 MAC_DMA_TXCFG_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete. 	 #define MAC_DMA_TXCFG_RESET 		 MAC_DMA_TXCFG_RESET

// 32'h0040 (MAC_DMA_MIBC)
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_STROBE_MSB 		 MAC_DMA_MIBC_STROBE_MSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_STROBE_LSB 		 MAC_DMA_MIBC_STROBE_LSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_STROBE_MASK 		 MAC_DMA_MIBC_STROBE_MASK
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_STROBE_GET(x) 		 MAC_DMA_MIBC_STROBE_GET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_STROBE_SET(x) 		 MAC_DMA_MIBC_STROBE_SET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_STROBE_RESET 		 MAC_DMA_MIBC_STROBE_RESET
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_CLEAR_MSB 		 MAC_DMA_MIBC_CLEAR_MSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_CLEAR_LSB 		 MAC_DMA_MIBC_CLEAR_LSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_CLEAR_MASK 		 MAC_DMA_MIBC_CLEAR_MASK
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_CLEAR_GET(x) 		 MAC_DMA_MIBC_CLEAR_GET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_CLEAR_SET(x) 		 MAC_DMA_MIBC_CLEAR_SET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_CLEAR_RESET 		 MAC_DMA_MIBC_CLEAR_RESET
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_FREEZE_MSB 		 MAC_DMA_MIBC_FREEZE_MSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_FREEZE_LSB 		 MAC_DMA_MIBC_FREEZE_LSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_FREEZE_MASK 		 MAC_DMA_MIBC_FREEZE_MASK
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_FREEZE_GET(x) 		 MAC_DMA_MIBC_FREEZE_GET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_FREEZE_SET(x) 		 MAC_DMA_MIBC_FREEZE_SET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_FREEZE_RESET 		 MAC_DMA_MIBC_FREEZE_RESET
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_WARNING_MSB 		 MAC_DMA_MIBC_WARNING_MSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_WARNING_LSB 		 MAC_DMA_MIBC_WARNING_LSB
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_WARNING_MASK 		 MAC_DMA_MIBC_WARNING_MASK
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_WARNING_GET(x) 		 MAC_DMA_MIBC_WARNING_GET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_WARNING_SET(x) 		 MAC_DMA_MIBC_WARNING_SET(x)
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_WARNING_RESET 		 MAC_DMA_MIBC_WARNING_RESET
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_ADDRESS 		 MAC_DMA_MIBC_ADDRESS
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_OFFSET 		 MAC_DMA_MIBC_OFFSET
// SW modifiable bits
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_SW_MASK 		 MAC_DMA_MIBC_SW_MASK
// bits defined at reset
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_RSTMASK 		 MAC_DMA_MIBC_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:TODO: Not exist. 	 #define MAC_DMA_MIBC_RESET 		 MAC_DMA_MIBC_RESET

// 32'h0044 (MAC_DMA_TOPS)
// Reason:Obsolete 	 #define MAC_DMA_TOPS_TIMEOUT_MSB 		 MAC_DMA_TOPS_TIMEOUT_MSB
// Reason:Obsolete 	 #define MAC_DMA_TOPS_TIMEOUT_LSB 		 MAC_DMA_TOPS_TIMEOUT_LSB
// Reason:Obsolete 	 #define MAC_DMA_TOPS_TIMEOUT_MASK 		 MAC_DMA_TOPS_TIMEOUT_MASK
// Reason:Obsolete 	 #define MAC_DMA_TOPS_TIMEOUT_GET(x) 		 MAC_DMA_TOPS_TIMEOUT_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_TOPS_TIMEOUT_SET(x) 		 MAC_DMA_TOPS_TIMEOUT_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_TOPS_TIMEOUT_RESET 		 MAC_DMA_TOPS_TIMEOUT_RESET
// Reason:Obsolete 	 #define MAC_DMA_TOPS_ADDRESS 		 MAC_DMA_TOPS_ADDRESS
// Reason:Obsolete 	 #define MAC_DMA_TOPS_OFFSET 		 MAC_DMA_TOPS_OFFSET
// SW modifiable bits
// Reason:Obsolete 	 #define MAC_DMA_TOPS_SW_MASK 		 MAC_DMA_TOPS_SW_MASK
// bits defined at reset
// Reason:Obsolete 	 #define MAC_DMA_TOPS_RSTMASK 		 MAC_DMA_TOPS_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete 	 #define MAC_DMA_TOPS_RESET 		 MAC_DMA_TOPS_RESET

// 32'h0048 (MAC_DMA_RXNPTO)
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_RXNPTO_TIMEOUT_MSB 		 MAC_DMA_RXNPTO_TIMEOUT_MSB
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_RXNPTO_TIMEOUT_LSB 		 MAC_DMA_RXNPTO_TIMEOUT_LSB
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_RXNPTO_TIMEOUT_MASK 		 MAC_DMA_RXNPTO_TIMEOUT_MASK
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_RXNPTO_TIMEOUT_GET(x) 		 MAC_DMA_RXNPTO_TIMEOUT_GET(x)
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_RXNPTO_TIMEOUT_SET(x) 		 MAC_DMA_RXNPTO_TIMEOUT_SET(x)
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_RXNPTO_TIMEOUT_RESET 		 MAC_DMA_RXNPTO_TIMEOUT_RESET
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_RXNPTO_ADDRESS 		 MAC_DMA_RXNPTO_ADDRESS
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_RXNPTO_OFFSET 		 MAC_DMA_RXNPTO_OFFSET
// SW modifiable bits
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_RXNPTO_SW_MASK 		 MAC_DMA_RXNPTO_SW_MASK
// bits defined at reset
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_RXNPTO_RSTMASK 		 MAC_DMA_RXNPTO_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_RXNPTO_RESET 		 MAC_DMA_RXNPTO_RESET

// 32'h004c (MAC_DMA_TXNPTO)
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_MASK_MSB 		 MAC_DMA_TXNPTO_MASK_MSB
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_MASK_LSB 		 MAC_DMA_TXNPTO_MASK_LSB
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_MASK_MASK 		 MAC_DMA_TXNPTO_MASK_MASK
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_MASK_GET(x) 		 MAC_DMA_TXNPTO_MASK_GET(x)
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_MASK_SET(x) 		 MAC_DMA_TXNPTO_MASK_SET(x)
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_MASK_RESET 		 MAC_DMA_TXNPTO_MASK_RESET
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_TIMEOUT_MSB 		 MAC_DMA_TXNPTO_TIMEOUT_MSB
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_TIMEOUT_LSB 		 MAC_DMA_TXNPTO_TIMEOUT_LSB
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_TIMEOUT_MASK 		 MAC_DMA_TXNPTO_TIMEOUT_MASK
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_TIMEOUT_GET(x) 		 MAC_DMA_TXNPTO_TIMEOUT_GET(x)
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_TIMEOUT_SET(x) 		 MAC_DMA_TXNPTO_TIMEOUT_SET(x)
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_TIMEOUT_RESET 		 MAC_DMA_TXNPTO_TIMEOUT_RESET
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_ADDRESS 		 MAC_DMA_TXNPTO_ADDRESS
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_OFFSET 		 MAC_DMA_TXNPTO_OFFSET
// SW modifiable bits
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_SW_MASK 		 MAC_DMA_TXNPTO_SW_MASK
// bits defined at reset
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_RSTMASK 		 MAC_DMA_TXNPTO_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: Not used by SW even in Peregrine 	 #define MAC_DMA_TXNPTO_RESET 		 MAC_DMA_TXNPTO_RESET

// 32'h0050 (MAC_DMA_RPGTO)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RPGTO_TIMEOUT_MSB 		 MAC_DMA_RPGTO_TIMEOUT_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RPGTO_TIMEOUT_LSB 		 MAC_DMA_RPGTO_TIMEOUT_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RPGTO_TIMEOUT_MASK 		 MAC_DMA_RPGTO_TIMEOUT_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RPGTO_TIMEOUT_GET(x) 		 MAC_DMA_RPGTO_TIMEOUT_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RPGTO_TIMEOUT_SET(x) 		 MAC_DMA_RPGTO_TIMEOUT_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RPGTO_TIMEOUT_RESET 		 MAC_DMA_RPGTO_TIMEOUT_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RPGTO_ADDRESS 		 MAC_DMA_RPGTO_ADDRESS
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RPGTO_OFFSET 		 MAC_DMA_RPGTO_OFFSET
// SW modifiable bits
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RPGTO_SW_MASK 		 MAC_DMA_RPGTO_SW_MASK
// bits defined at reset
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RPGTO_RSTMASK 		 MAC_DMA_RPGTO_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RPGTO_RESET 		 MAC_DMA_RPGTO_RESET

// 32'h0058 (MAC_DMA_MACMISC)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_MSB 		 MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_LSB 		 MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_MASK 		 MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_GET(x) 		 MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_SET(x) 		 MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_RESET 		 MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_MSB 		 MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_LSB 		 MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_MASK 		 MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_GET(x) 		 MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_SET(x) 		 MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_RESET 		 MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_MSB 		 MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_LSB 		 MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_MASK 		 MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_GET(x) 		 MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_SET(x) 		 MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_RESET 		 MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_OBS_MUXSEL_MSB 		 MAC_DMA_MACMISC_MISC_OBS_MUXSEL_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_OBS_MUXSEL_LSB 		 MAC_DMA_MACMISC_MISC_OBS_MUXSEL_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_OBS_MUXSEL_MASK 		 MAC_DMA_MACMISC_MISC_OBS_MUXSEL_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_OBS_MUXSEL_GET(x) 		 MAC_DMA_MACMISC_MISC_OBS_MUXSEL_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_OBS_MUXSEL_SET(x) 		 MAC_DMA_MACMISC_MISC_OBS_MUXSEL_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_MISC_OBS_MUXSEL_RESET 		 MAC_DMA_MACMISC_MISC_OBS_MUXSEL_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_DMA_OBS_MUXSEL_MSB 		 MAC_DMA_MACMISC_DMA_OBS_MUXSEL_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_DMA_OBS_MUXSEL_LSB 		 MAC_DMA_MACMISC_DMA_OBS_MUXSEL_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_DMA_OBS_MUXSEL_MASK 		 MAC_DMA_MACMISC_DMA_OBS_MUXSEL_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_DMA_OBS_MUXSEL_GET(x) 		 MAC_DMA_MACMISC_DMA_OBS_MUXSEL_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_DMA_OBS_MUXSEL_SET(x) 		 MAC_DMA_MACMISC_DMA_OBS_MUXSEL_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_DMA_OBS_MUXSEL_RESET 		 MAC_DMA_MACMISC_DMA_OBS_MUXSEL_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_FORCE_PCI_EXT_MSB 		 MAC_DMA_MACMISC_FORCE_PCI_EXT_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_FORCE_PCI_EXT_LSB 		 MAC_DMA_MACMISC_FORCE_PCI_EXT_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_FORCE_PCI_EXT_MASK 		 MAC_DMA_MACMISC_FORCE_PCI_EXT_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_FORCE_PCI_EXT_GET(x) 		 MAC_DMA_MACMISC_FORCE_PCI_EXT_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_FORCE_PCI_EXT_SET(x) 		 MAC_DMA_MACMISC_FORCE_PCI_EXT_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_FORCE_PCI_EXT_RESET 		 MAC_DMA_MACMISC_FORCE_PCI_EXT_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_ADDRESS 		 MAC_DMA_MACMISC_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_OFFSET 		 MAC_DMA_MACMISC_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_SW_MASK 		 MAC_DMA_MACMISC_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_RSTMASK 		 MAC_DMA_MACMISC_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_MACMISC_RESET 		 MAC_DMA_MACMISC_RESET

// 32'h005c (MAC_DMA_INTER)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_MSI_TX_SRC_MSB 		 MAC_DMA_INTER_MSI_TX_SRC_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_MSI_TX_SRC_LSB 		 MAC_DMA_INTER_MSI_TX_SRC_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_MSI_TX_SRC_MASK 		 MAC_DMA_INTER_MSI_TX_SRC_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_MSI_TX_SRC_GET(x) 		 MAC_DMA_INTER_MSI_TX_SRC_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_MSI_TX_SRC_SET(x) 		 MAC_DMA_INTER_MSI_TX_SRC_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_MSI_TX_SRC_RESET 		 MAC_DMA_INTER_MSI_TX_SRC_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_MSI_RX_SRC_MSB 		 MAC_DMA_INTER_MSI_RX_SRC_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_MSI_RX_SRC_LSB 		 MAC_DMA_INTER_MSI_RX_SRC_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_MSI_RX_SRC_MASK 		 MAC_DMA_INTER_MSI_RX_SRC_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_MSI_RX_SRC_GET(x) 		 MAC_DMA_INTER_MSI_RX_SRC_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_MSI_RX_SRC_SET(x) 		 MAC_DMA_INTER_MSI_RX_SRC_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_MSI_RX_SRC_RESET 		 MAC_DMA_INTER_MSI_RX_SRC_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_REQ_MSB 		 MAC_DMA_INTER_REQ_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_REQ_LSB 		 MAC_DMA_INTER_REQ_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_REQ_MASK 		 MAC_DMA_INTER_REQ_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_REQ_GET(x) 		 MAC_DMA_INTER_REQ_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_REQ_SET(x) 		 MAC_DMA_INTER_REQ_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_REQ_RESET 		 MAC_DMA_INTER_REQ_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_ADDRESS 		 MAC_DMA_INTER_ADDRESS
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_OFFSET 		 MAC_DMA_INTER_OFFSET
// SW modifiable bits
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_SW_MASK 		 MAC_DMA_INTER_SW_MASK
// bits defined at reset
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_RSTMASK 		 MAC_DMA_INTER_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_INTER_RESET 		 MAC_DMA_INTER_RESET

// 32'h0060 (MAC_DMA_DATABUF)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_DATABUF_LEN_MSB 		 MAC_DMA_DATABUF_LEN_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_DATABUF_LEN_LSB 		 MAC_DMA_DATABUF_LEN_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_DATABUF_LEN_MASK 		 MAC_DMA_DATABUF_LEN_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_DATABUF_LEN_GET(x) 		 MAC_DMA_DATABUF_LEN_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_DATABUF_LEN_SET(x) 		 MAC_DMA_DATABUF_LEN_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_DATABUF_LEN_RESET 		 MAC_DMA_DATABUF_LEN_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_DATABUF_ADDRESS 		 MAC_DMA_DATABUF_ADDRESS
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_DATABUF_OFFSET 		 MAC_DMA_DATABUF_OFFSET
// SW modifiable bits
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_DATABUF_SW_MASK 		 MAC_DMA_DATABUF_SW_MASK
// bits defined at reset
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_DATABUF_RSTMASK 		 MAC_DMA_DATABUF_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_DATABUF_RESET 		 MAC_DMA_DATABUF_RESET

// 32'h0064 (MAC_DMA_GTT)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_LIMIT_MSB 		 MAC_DMA_GTT_LIMIT_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_LIMIT_LSB 		 MAC_DMA_GTT_LIMIT_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_LIMIT_MASK 		 MAC_DMA_GTT_LIMIT_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_LIMIT_GET(x) 		 MAC_DMA_GTT_LIMIT_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_LIMIT_SET(x) 		 MAC_DMA_GTT_LIMIT_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_LIMIT_RESET 		 MAC_DMA_GTT_LIMIT_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_COUNT_MSB 		 MAC_DMA_GTT_COUNT_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_COUNT_LSB 		 MAC_DMA_GTT_COUNT_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_COUNT_MASK 		 MAC_DMA_GTT_COUNT_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_COUNT_GET(x) 		 MAC_DMA_GTT_COUNT_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_COUNT_SET(x) 		 MAC_DMA_GTT_COUNT_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_COUNT_RESET 		 MAC_DMA_GTT_COUNT_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_ADDRESS 		 MAC_DMA_GTT_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_OFFSET 		 MAC_DMA_GTT_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_SW_MASK 		 MAC_DMA_GTT_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_RSTMASK 		 MAC_DMA_GTT_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTT_RESET 		 MAC_DMA_GTT_RESET

// 32'h0068 (MAC_DMA_GTTM)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_MSB 		 MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_LSB 		 MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_MASK 		 MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_GET(x) 		 MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_SET(x) 		 MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_RESET 		 MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_MSB 		 MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_LSB 		 MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_MASK 		 MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_GET(x) 		 MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_SET(x) 		 MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_RESET 		 MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_CST_USEC_STROBE_MSB 		 MAC_DMA_GTTM_CST_USEC_STROBE_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_CST_USEC_STROBE_LSB 		 MAC_DMA_GTTM_CST_USEC_STROBE_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_CST_USEC_STROBE_MASK 		 MAC_DMA_GTTM_CST_USEC_STROBE_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_CST_USEC_STROBE_GET(x) 		 MAC_DMA_GTTM_CST_USEC_STROBE_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_CST_USEC_STROBE_SET(x) 		 MAC_DMA_GTTM_CST_USEC_STROBE_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_CST_USEC_STROBE_RESET 		 MAC_DMA_GTTM_CST_USEC_STROBE_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_MSB 		 MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_LSB 		 MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_MASK 		 MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_GET(x) 		 MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_SET(x) 		 MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_RESET 		 MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_IGNORE_CHAN_IDLE_MSB 		 MAC_DMA_GTTM_IGNORE_CHAN_IDLE_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_IGNORE_CHAN_IDLE_LSB 		 MAC_DMA_GTTM_IGNORE_CHAN_IDLE_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_IGNORE_CHAN_IDLE_MASK 		 MAC_DMA_GTTM_IGNORE_CHAN_IDLE_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_IGNORE_CHAN_IDLE_GET(x) 		 MAC_DMA_GTTM_IGNORE_CHAN_IDLE_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_IGNORE_CHAN_IDLE_SET(x) 		 MAC_DMA_GTTM_IGNORE_CHAN_IDLE_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_IGNORE_CHAN_IDLE_RESET 		 MAC_DMA_GTTM_IGNORE_CHAN_IDLE_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_USEC_STROBE_MSB 		 MAC_DMA_GTTM_USEC_STROBE_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_USEC_STROBE_LSB 		 MAC_DMA_GTTM_USEC_STROBE_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_USEC_STROBE_MASK 		 MAC_DMA_GTTM_USEC_STROBE_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_USEC_STROBE_GET(x) 		 MAC_DMA_GTTM_USEC_STROBE_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_USEC_STROBE_SET(x) 		 MAC_DMA_GTTM_USEC_STROBE_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_USEC_STROBE_RESET 		 MAC_DMA_GTTM_USEC_STROBE_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_ADDRESS 		 MAC_DMA_GTTM_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_OFFSET 		 MAC_DMA_GTTM_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_SW_MASK 		 MAC_DMA_GTTM_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_RSTMASK 		 MAC_DMA_GTTM_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_GTTM_RESET 		 MAC_DMA_GTTM_RESET

// 32'h006c (MAC_DMA_CST)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_LIMIT_MSB 		 MAC_DMA_CST_LIMIT_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_LIMIT_LSB 		 MAC_DMA_CST_LIMIT_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_LIMIT_MASK 		 MAC_DMA_CST_LIMIT_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_LIMIT_GET(x) 		 MAC_DMA_CST_LIMIT_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_LIMIT_SET(x) 		 MAC_DMA_CST_LIMIT_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_LIMIT_RESET 		 MAC_DMA_CST_LIMIT_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_COUNT_MSB 		 MAC_DMA_CST_COUNT_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_COUNT_LSB 		 MAC_DMA_CST_COUNT_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_COUNT_MASK 		 MAC_DMA_CST_COUNT_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_COUNT_GET(x) 		 MAC_DMA_CST_COUNT_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_COUNT_SET(x) 		 MAC_DMA_CST_COUNT_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_COUNT_RESET 		 MAC_DMA_CST_COUNT_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_ADDRESS 		 MAC_DMA_CST_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_OFFSET 		 MAC_DMA_CST_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_SW_MASK 		 MAC_DMA_CST_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_RSTMASK 		 MAC_DMA_CST_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CST_RESET 		 MAC_DMA_CST_RESET

// 32'h0070 (MAC_DMA_RXDP_SIZE)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_HP_MSB 		 MAC_DMA_RXDP_SIZE_HP_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_HP_LSB 		 MAC_DMA_RXDP_SIZE_HP_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_HP_MASK 		 MAC_DMA_RXDP_SIZE_HP_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_HP_GET(x) 		 MAC_DMA_RXDP_SIZE_HP_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_HP_SET(x) 		 MAC_DMA_RXDP_SIZE_HP_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_HP_RESET 		 MAC_DMA_RXDP_SIZE_HP_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_LP_MSB 		 MAC_DMA_RXDP_SIZE_LP_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_LP_LSB 		 MAC_DMA_RXDP_SIZE_LP_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_LP_MASK 		 MAC_DMA_RXDP_SIZE_LP_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_LP_GET(x) 		 MAC_DMA_RXDP_SIZE_LP_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_LP_SET(x) 		 MAC_DMA_RXDP_SIZE_LP_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_LP_RESET 		 MAC_DMA_RXDP_SIZE_LP_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_ADDRESS 		 MAC_DMA_RXDP_SIZE_ADDRESS
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_OFFSET 		 MAC_DMA_RXDP_SIZE_OFFSET
// SW modifiable bits
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_SW_MASK 		 MAC_DMA_RXDP_SIZE_SW_MASK
// bits defined at reset
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_RSTMASK 		 MAC_DMA_RXDP_SIZE_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RXDP_SIZE_RESET 		 MAC_DMA_RXDP_SIZE_RESET

// 32'h0074 (MAC_DMA_RX_QUEUE_HP_RXDP)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_MSB 		 MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_LSB 		 MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_MASK 		 MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_GET(x) 		 MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_SET(x) 		 MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_RESET 		 MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_HP_RXDP_ADDRESS 		 MAC_DMA_RX_QUEUE_HP_RXDP_ADDRESS
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_HP_RXDP_OFFSET 		 MAC_DMA_RX_QUEUE_HP_RXDP_OFFSET
// SW modifiable bits
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_HP_RXDP_SW_MASK 		 MAC_DMA_RX_QUEUE_HP_RXDP_SW_MASK
// bits defined at reset
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_HP_RXDP_RSTMASK 		 MAC_DMA_RX_QUEUE_HP_RXDP_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_HP_RXDP_RESET 		 MAC_DMA_RX_QUEUE_HP_RXDP_RESET

// 32'h0078 (MAC_DMA_RX_QUEUE_LP_RXDP)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_MSB 		 MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_LSB 		 MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_MASK 		 MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_GET(x) 		 MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_SET(x) 		 MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_RESET 		 MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_LP_RXDP_ADDRESS 		 MAC_DMA_RX_QUEUE_LP_RXDP_ADDRESS
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_LP_RXDP_OFFSET 		 MAC_DMA_RX_QUEUE_LP_RXDP_OFFSET
// SW modifiable bits
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_LP_RXDP_SW_MASK 		 MAC_DMA_RX_QUEUE_LP_RXDP_SW_MASK
// bits defined at reset
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_LP_RXDP_RSTMASK 		 MAC_DMA_RX_QUEUE_LP_RXDP_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_RX_QUEUE_LP_RXDP_RESET 		 MAC_DMA_RX_QUEUE_LP_RXDP_RESET

// 32'h0080 (MAC_DMA_ISR_P)
#define MAC_DMA_ISR_P_GENTMR_MSB 		 WIFICMN_ISR_P_WIFI_TIMER_MSB
#define MAC_DMA_ISR_P_GENTMR_LSB 		 WIFICMN_ISR_P_WIFI_TIMER_LSB
#define MAC_DMA_ISR_P_GENTMR_MASK 		 WIFICMN_ISR_P_WIFI_TIMER_MASK
#define MAC_DMA_ISR_P_GENTMR_GET(x) 		 WIFICMN_ISR_P_WIFI_TIMER_GET(x)
#define MAC_DMA_ISR_P_GENTMR_SET(x) 		 WIFICMN_ISR_P_WIFI_TIMER_SET(x)
#define MAC_DMA_ISR_P_GENTMR_RESET 		 WIFICMN_ISR_P_WIFI_TIMER_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QTRIG_MSB 		 MAC_DMA_ISR_P_QTRIG_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QTRIG_LSB 		 MAC_DMA_ISR_P_QTRIG_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QTRIG_MASK 		 MAC_DMA_ISR_P_QTRIG_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QTRIG_GET(x) 		 MAC_DMA_ISR_P_QTRIG_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QTRIG_SET(x) 		 MAC_DMA_ISR_P_QTRIG_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QTRIG_RESET 		 MAC_DMA_ISR_P_QTRIG_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QCBRURN_MSB 		 MAC_DMA_ISR_P_QCBRURN_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QCBRURN_LSB 		 MAC_DMA_ISR_P_QCBRURN_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QCBRURN_MASK 		 MAC_DMA_ISR_P_QCBRURN_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QCBRURN_GET(x) 		 MAC_DMA_ISR_P_QCBRURN_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QCBRURN_SET(x) 		 MAC_DMA_ISR_P_QCBRURN_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QCBRURN_RESET 		 MAC_DMA_ISR_P_QCBRURN_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QCBROVF_MSB 		 MAC_DMA_ISR_P_QCBROVF_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QCBROVF_LSB 		 MAC_DMA_ISR_P_QCBROVF_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QCBROVF_MASK 		 MAC_DMA_ISR_P_QCBROVF_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QCBROVF_GET(x) 		 MAC_DMA_ISR_P_QCBROVF_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QCBROVF_SET(x) 		 MAC_DMA_ISR_P_QCBROVF_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_QCBROVF_RESET 		 MAC_DMA_ISR_P_QCBROVF_RESET
// Reason:Obsolete: architecture change - used to be OR of tx_config_phy_err, bb_temp_sensor and bb_panic. Only tx_config_phy_err exists. 	 #define MAC_DMA_ISR_P_BB_INT_MSB 		 MAC_DMA_ISR_P_BB_INT_MSB
// Reason:Obsolete: architecture change - used to be OR of tx_config_phy_err, bb_temp_sensor and bb_panic. Only tx_config_phy_err exists. 	 #define MAC_DMA_ISR_P_BB_INT_LSB 		 MAC_DMA_ISR_P_BB_INT_LSB
// Reason:Obsolete: architecture change - used to be OR of tx_config_phy_err, bb_temp_sensor and bb_panic. Only tx_config_phy_err exists. 	 #define MAC_DMA_ISR_P_BB_INT_MASK 		 MAC_DMA_ISR_P_BB_INT_MASK
// Reason:Obsolete: architecture change - used to be OR of tx_config_phy_err, bb_temp_sensor and bb_panic. Only tx_config_phy_err exists. 	 #define MAC_DMA_ISR_P_BB_INT_GET(x) 		 MAC_DMA_ISR_P_BB_INT_GET(x)
// Reason:Obsolete: architecture change - used to be OR of tx_config_phy_err, bb_temp_sensor and bb_panic. Only tx_config_phy_err exists. 	 #define MAC_DMA_ISR_P_BB_INT_SET(x) 		 MAC_DMA_ISR_P_BB_INT_SET(x)
// Reason:Obsolete: architecture change - used to be OR of tx_config_phy_err, bb_temp_sensor and bb_panic. Only tx_config_phy_err exists. 	 #define MAC_DMA_ISR_P_BB_INT_RESET 		 MAC_DMA_ISR_P_BB_INT_RESET
#define MAC_DMA_ISR_P_BCNMISC_MSB 		 WIFICMN_ISR_P_WIFI_TIMER_MSB
#define MAC_DMA_ISR_P_BCNMISC_LSB 		 WIFICMN_ISR_P_WIFI_TIMER_LSB
#define MAC_DMA_ISR_P_BCNMISC_MASK 		 WIFICMN_ISR_P_WIFI_TIMER_MASK
#define MAC_DMA_ISR_P_BCNMISC_GET(x) 		 WIFICMN_ISR_P_WIFI_TIMER_GET(x)
#define MAC_DMA_ISR_P_BCNMISC_SET(x) 		 WIFICMN_ISR_P_WIFI_TIMER_SET(x)
#define MAC_DMA_ISR_P_BCNMISC_RESET 		 WIFICMN_ISR_P_WIFI_TIMER_RESET
#define MAC_DMA_ISR_P_OLE_INT_MSB 		 MCMN_ISR_P_OLE_MSB
#define MAC_DMA_ISR_P_OLE_INT_LSB 		 MCMN_ISR_P_OLE_LSB
#define MAC_DMA_ISR_P_OLE_INT_MASK 		 MCMN_ISR_P_OLE_MASK
#define MAC_DMA_ISR_P_OLE_INT_GET(x) 		 MCMN_ISR_P_OLE_GET(x)
#define MAC_DMA_ISR_P_OLE_INT_SET(x) 		 MCMN_ISR_P_OLE_SET(x)
#define MAC_DMA_ISR_P_OLE_INT_RESET 		 MCMN_ISR_P_OLE_RESET
// Reason:Obsolete: Used for BT coex Rx frame priority 	 #define MAC_DMA_ISR_P_RXINT_MSB 		 MAC_DMA_ISR_P_RXINT_MSB
// Reason:Obsolete: Used for BT coex Rx frame priority 	 #define MAC_DMA_ISR_P_RXINT_LSB 		 MAC_DMA_ISR_P_RXINT_LSB
// Reason:Obsolete: Used for BT coex Rx frame priority 	 #define MAC_DMA_ISR_P_RXINT_MASK 		 MAC_DMA_ISR_P_RXINT_MASK
// Reason:Obsolete: Used for BT coex Rx frame priority 	 #define MAC_DMA_ISR_P_RXINT_GET(x) 		 MAC_DMA_ISR_P_RXINT_GET(x)
// Reason:Obsolete: Used for BT coex Rx frame priority 	 #define MAC_DMA_ISR_P_RXINT_SET(x) 		 MAC_DMA_ISR_P_RXINT_SET(x)
// Reason:Obsolete: Used for BT coex Rx frame priority 	 #define MAC_DMA_ISR_P_RXINT_RESET 		 MAC_DMA_ISR_P_RXINT_RESET
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_P_BNR_MSB 		 MAC_DMA_ISR_P_BNR_MSB
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_P_BNR_LSB 		 MAC_DMA_ISR_P_BNR_LSB
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_P_BNR_MASK 		 MAC_DMA_ISR_P_BNR_MASK
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_P_BNR_GET(x) 		 MAC_DMA_ISR_P_BNR_GET(x)
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_P_BNR_SET(x) 		 MAC_DMA_ISR_P_BNR_SET(x)
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_P_BNR_RESET 		 MAC_DMA_ISR_P_BNR_RESET
#define MAC_DMA_ISR_P_BMISS_MSB 		 MCMN_ISR_S5_BCON_MISS_MSB
#define MAC_DMA_ISR_P_BMISS_LSB 		 MCMN_ISR_S5_BCON_MISS_LSB
#define MAC_DMA_ISR_P_BMISS_MASK 		 MCMN_ISR_S5_BCON_MISS_MASK
#define MAC_DMA_ISR_P_BMISS_GET(x) 		 MCMN_ISR_S5_BCON_MISS_GET(x)
#define MAC_DMA_ISR_P_BMISS_SET(x) 		 MCMN_ISR_S5_BCON_MISS_SET(x)
#define MAC_DMA_ISR_P_BMISS_RESET 		 MCMN_ISR_S5_BCON_MISS_RESET
// Reason:Obsolete: architecture change - OR version is gone but indivisual RSSI_LOW and RSSI_HIGH exist in MCMN_ISR_S5. 	 #define MAC_DMA_ISR_P_BRSSI_MSB 		 MAC_DMA_ISR_P_BRSSI_MSB
// Reason:Obsolete: architecture change - OR version is gone but indivisual RSSI_LOW and RSSI_HIGH exist in MCMN_ISR_S5. 	 #define MAC_DMA_ISR_P_BRSSI_LSB 		 MAC_DMA_ISR_P_BRSSI_LSB
// Reason:Obsolete: architecture change - OR version is gone but indivisual RSSI_LOW and RSSI_HIGH exist in MCMN_ISR_S5. 	 #define MAC_DMA_ISR_P_BRSSI_MASK 		 MAC_DMA_ISR_P_BRSSI_MASK
// Reason:Obsolete: architecture change - OR version is gone but indivisual RSSI_LOW and RSSI_HIGH exist in MCMN_ISR_S5. 	 #define MAC_DMA_ISR_P_BRSSI_GET(x) 		 MAC_DMA_ISR_P_BRSSI_GET(x)
// Reason:Obsolete: architecture change - OR version is gone but indivisual RSSI_LOW and RSSI_HIGH exist in MCMN_ISR_S5. 	 #define MAC_DMA_ISR_P_BRSSI_SET(x) 		 MAC_DMA_ISR_P_BRSSI_SET(x)
// Reason:Obsolete: architecture change - OR version is gone but indivisual RSSI_LOW and RSSI_HIGH exist in MCMN_ISR_S5. 	 #define MAC_DMA_ISR_P_BRSSI_RESET 		 MAC_DMA_ISR_P_BRSSI_RESET
// Reason:TODO: Not exist: PCU_GEN_TIMER_TRIGGER can be used? 	 #define MAC_DMA_ISR_P_SWBA_MSB 		 MAC_DMA_ISR_P_SWBA_MSB
// Reason:TODO: Not exist: PCU_GEN_TIMER_TRIGGER can be used? 	 #define MAC_DMA_ISR_P_SWBA_LSB 		 MAC_DMA_ISR_P_SWBA_LSB
// Reason:TODO: Not exist: PCU_GEN_TIMER_TRIGGER can be used? 	 #define MAC_DMA_ISR_P_SWBA_MASK 		 MAC_DMA_ISR_P_SWBA_MASK
// Reason:TODO: Not exist: PCU_GEN_TIMER_TRIGGER can be used? 	 #define MAC_DMA_ISR_P_SWBA_GET(x) 		 MAC_DMA_ISR_P_SWBA_GET(x)
// Reason:TODO: Not exist: PCU_GEN_TIMER_TRIGGER can be used? 	 #define MAC_DMA_ISR_P_SWBA_SET(x) 		 MAC_DMA_ISR_P_SWBA_SET(x)
// Reason:TODO: Not exist: PCU_GEN_TIMER_TRIGGER can be used? 	 #define MAC_DMA_ISR_P_SWBA_RESET 		 MAC_DMA_ISR_P_SWBA_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_SWI_MSB 		 MAC_DMA_ISR_P_SWI_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_SWI_LSB 		 MAC_DMA_ISR_P_SWI_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_SWI_MASK 		 MAC_DMA_ISR_P_SWI_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_SWI_GET(x) 		 MAC_DMA_ISR_P_SWI_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_SWI_SET(x) 		 MAC_DMA_ISR_P_SWI_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_SWI_RESET 		 MAC_DMA_ISR_P_SWI_RESET
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_P_MIB_MSB 		 MAC_DMA_ISR_P_MIB_MSB
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_P_MIB_LSB 		 MAC_DMA_ISR_P_MIB_LSB
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_P_MIB_MASK 		 MAC_DMA_ISR_P_MIB_MASK
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_P_MIB_GET(x) 		 MAC_DMA_ISR_P_MIB_GET(x)
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_P_MIB_SET(x) 		 MAC_DMA_ISR_P_MIB_SET(x)
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_P_MIB_RESET 		 MAC_DMA_ISR_P_MIB_RESET
#define MAC_DMA_ISR_P_TXURN_MSB 		 MCMN_ISR_S4_DATA_URUN_MSB
#define MAC_DMA_ISR_P_TXURN_LSB 		 MCMN_ISR_S4_DATA_URUN_LSB
#define MAC_DMA_ISR_P_TXURN_MASK 		 MCMN_ISR_S4_DATA_URUN_MASK
#define MAC_DMA_ISR_P_TXURN_GET(x) 		 MCMN_ISR_S4_DATA_URUN_GET(x)
#define MAC_DMA_ISR_P_TXURN_SET(x) 		 MCMN_ISR_S4_DATA_URUN_SET(x)
#define MAC_DMA_ISR_P_TXURN_RESET 		 MCMN_ISR_S4_DATA_URUN_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_TXEOL_MSB 		 MAC_DMA_ISR_P_TXEOL_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_TXEOL_LSB 		 MAC_DMA_ISR_P_TXEOL_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_TXEOL_MASK 		 MAC_DMA_ISR_P_TXEOL_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_TXEOL_GET(x) 		 MAC_DMA_ISR_P_TXEOL_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_TXEOL_SET(x) 		 MAC_DMA_ISR_P_TXEOL_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_TXEOL_RESET 		 MAC_DMA_ISR_P_TXEOL_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_TXNOFR_MSB 		 MAC_DMA_ISR_P_TXNOFR_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_TXNOFR_LSB 		 MAC_DMA_ISR_P_TXNOFR_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_TXNOFR_MASK 		 MAC_DMA_ISR_P_TXNOFR_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_TXNOFR_GET(x) 		 MAC_DMA_ISR_P_TXNOFR_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_TXNOFR_SET(x) 		 MAC_DMA_ISR_P_TXNOFR_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_P_TXNOFR_RESET 		 MAC_DMA_ISR_P_TXNOFR_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_TXERR_MSB 		 MAC_DMA_ISR_P_TXERR_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_TXERR_LSB 		 MAC_DMA_ISR_P_TXERR_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_TXERR_MASK 		 MAC_DMA_ISR_P_TXERR_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_TXERR_GET(x) 		 MAC_DMA_ISR_P_TXERR_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_TXERR_SET(x) 		 MAC_DMA_ISR_P_TXERR_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_P_TXERR_RESET 		 MAC_DMA_ISR_P_TXERR_RESET
#define MAC_DMA_ISR_P_BTINT_MSB 		 WIFICMN_ISR_P_WIFI_COEX_MSB
#define MAC_DMA_ISR_P_BTINT_LSB 		 WIFICMN_ISR_P_WIFI_COEX_LSB
#define MAC_DMA_ISR_P_BTINT_MASK 		 WIFICMN_ISR_P_WIFI_COEX_MASK
#define MAC_DMA_ISR_P_BTINT_GET(x) 		 WIFICMN_ISR_P_WIFI_COEX_GET(x)
#define MAC_DMA_ISR_P_BTINT_SET(x) 		 WIFICMN_ISR_P_WIFI_COEX_SET(x)
#define MAC_DMA_ISR_P_BTINT_RESET 		 WIFICMN_ISR_P_WIFI_COEX_RESET
#define MAC_DMA_ISR_P_TX_DMA_ERR_MSB 		 MCMN_ISR_P_TXDMA_MSB
#define MAC_DMA_ISR_P_TX_DMA_ERR_LSB 		 MCMN_ISR_P_TXDMA_LSB
#define MAC_DMA_ISR_P_TX_DMA_ERR_MASK 		 MCMN_ISR_P_TXDMA_MASK
#define MAC_DMA_ISR_P_TX_DMA_ERR_GET(x) 		 MCMN_ISR_P_TXDMA_GET(x)
#define MAC_DMA_ISR_P_TX_DMA_ERR_SET(x) 		 MCMN_ISR_P_TXDMA_SET(x)
#define MAC_DMA_ISR_P_TX_DMA_ERR_RESET 		 MCMN_ISR_P_TXDMA_RESET
#define MAC_DMA_ISR_P_RXORN_MSB 		 MCMN_ISR_S5_RX_OVFL_MSB
#define MAC_DMA_ISR_P_RXORN_LSB 		 MCMN_ISR_S5_RX_OVFL_LSB
#define MAC_DMA_ISR_P_RXORN_MASK 		 MCMN_ISR_S5_RX_OVFL_MASK
#define MAC_DMA_ISR_P_RXORN_GET(x) 		 MCMN_ISR_S5_RX_OVFL_GET(x)
#define MAC_DMA_ISR_P_RXORN_SET(x) 		 MCMN_ISR_S5_RX_OVFL_SET(x)
#define MAC_DMA_ISR_P_RXORN_RESET 		 MCMN_ISR_S5_RX_OVFL_RESET
#define MAC_DMA_ISR_P_RX_DMA_ERR_MSB 		 MCMN_ISR_P_RXDMA_MSB
#define MAC_DMA_ISR_P_RX_DMA_ERR_LSB 		 MCMN_ISR_P_RXDMA_LSB
#define MAC_DMA_ISR_P_RX_DMA_ERR_MASK 		 MCMN_ISR_P_RXDMA_MASK
#define MAC_DMA_ISR_P_RX_DMA_ERR_GET(x) 		 MCMN_ISR_P_RXDMA_GET(x)
#define MAC_DMA_ISR_P_RX_DMA_ERR_SET(x) 		 MCMN_ISR_P_RXDMA_SET(x)
#define MAC_DMA_ISR_P_RX_DMA_ERR_RESET 		 MCMN_ISR_P_RXDMA_RESET
#define MAC_DMA_ISR_P_RX_DMA_RING_LWM_MSB 		 MCMN_ISR_S3_RXDMA_RNG_LWM_MSB
#define MAC_DMA_ISR_P_RX_DMA_RING_LWM_LSB 		 MCMN_ISR_S3_RXDMA_RNG_LWM_LSB
#define MAC_DMA_ISR_P_RX_DMA_RING_LWM_MASK 		 MCMN_ISR_S3_RXDMA_RNG_LWM_MASK
#define MAC_DMA_ISR_P_RX_DMA_RING_LWM_GET(x) 		 MCMN_ISR_S3_RXDMA_RNG_LWM_GET(x)
#define MAC_DMA_ISR_P_RX_DMA_RING_LWM_SET(x) 		 MCMN_ISR_S3_RXDMA_RNG_LWM_SET(x)
#define MAC_DMA_ISR_P_RX_DMA_RING_LWM_RESET 		 MCMN_ISR_S3_RXDMA_RNG_LWM_RESET
// Reason:Obsolete: Use MCMN_ISR_P or WIFICMN_ISR_P 	 #define MAC_DMA_ISR_P_ADDRESS 		 MAC_DMA_ISR_P_ADDRESS
// Reason:Obsolete: Use MCMN_ISR_P or WIFICMN_ISR_P 	 #define MAC_DMA_ISR_P_OFFSET 		 MAC_DMA_ISR_P_OFFSET
// SW modifiable bits
// Reason:Obsolete: Use MCMN_ISR_P or WIFICMN_ISR_P 	 #define MAC_DMA_ISR_P_SW_MASK 		 MAC_DMA_ISR_P_SW_MASK
// bits defined at reset
// Reason:Obsolete: Use MCMN_ISR_P or WIFICMN_ISR_P 	 #define MAC_DMA_ISR_P_RSTMASK 		 MAC_DMA_ISR_P_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: Use MCMN_ISR_P or WIFICMN_ISR_P 	 #define MAC_DMA_ISR_P_RESET 		 MAC_DMA_ISR_P_RESET
// Reason:Obsolete: Use MCMN_ISR_P or WIFICMN_ISR_P 	 #define MAC_DMA_ISR_P_RESET 		 MAC_DMA_ISR_P_RESET

// 32'h0084 (MAC_DMA_TXRX_ISR)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_HP_MSB 		 MAC_DMA_TXRX_ISR_RXOK_HP_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_HP_LSB 		 MAC_DMA_TXRX_ISR_RXOK_HP_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_HP_MASK 		 MAC_DMA_TXRX_ISR_RXOK_HP_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_HP_GET(x) 		 MAC_DMA_TXRX_ISR_RXOK_HP_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_HP_SET(x) 		 MAC_DMA_TXRX_ISR_RXOK_HP_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_HP_RESET 		 MAC_DMA_TXRX_ISR_RXOK_HP_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_PPDU_MSB 		 MAC_DMA_TXRX_ISR_RXOK_PPDU_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_PPDU_LSB 		 MAC_DMA_TXRX_ISR_RXOK_PPDU_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_PPDU_MASK 		 MAC_DMA_TXRX_ISR_RXOK_PPDU_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_PPDU_GET(x) 		 MAC_DMA_TXRX_ISR_RXOK_PPDU_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_PPDU_SET(x) 		 MAC_DMA_TXRX_ISR_RXOK_PPDU_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_PPDU_RESET 		 MAC_DMA_TXRX_ISR_RXOK_PPDU_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_MPDU_MSB 		 MAC_DMA_TXRX_ISR_RXOK_MPDU_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_MPDU_LSB 		 MAC_DMA_TXRX_ISR_RXOK_MPDU_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_MPDU_MASK 		 MAC_DMA_TXRX_ISR_RXOK_MPDU_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_MPDU_GET(x) 		 MAC_DMA_TXRX_ISR_RXOK_MPDU_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_MPDU_SET(x) 		 MAC_DMA_TXRX_ISR_RXOK_MPDU_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_MPDU_RESET 		 MAC_DMA_TXRX_ISR_RXOK_MPDU_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_MSDU_MSB 		 MAC_DMA_TXRX_ISR_RXOK_MSDU_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_MSDU_LSB 		 MAC_DMA_TXRX_ISR_RXOK_MSDU_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_MSDU_MASK 		 MAC_DMA_TXRX_ISR_RXOK_MSDU_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_MSDU_GET(x) 		 MAC_DMA_TXRX_ISR_RXOK_MSDU_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_MSDU_SET(x) 		 MAC_DMA_TXRX_ISR_RXOK_MSDU_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RXOK_MSDU_RESET 		 MAC_DMA_TXRX_ISR_RXOK_MSDU_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU9_MSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU9_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU9_LSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU9_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU9_MASK 		 MAC_DMA_TXRX_ISR_TXOK_QCU9_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU9_GET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU9_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU9_SET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU9_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU9_RESET 		 MAC_DMA_TXRX_ISR_TXOK_QCU9_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU8_MSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU8_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU8_LSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU8_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU8_MASK 		 MAC_DMA_TXRX_ISR_TXOK_QCU8_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU8_GET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU8_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU8_SET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU8_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU8_RESET 		 MAC_DMA_TXRX_ISR_TXOK_QCU8_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU7_MSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU7_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU7_LSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU7_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU7_MASK 		 MAC_DMA_TXRX_ISR_TXOK_QCU7_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU7_GET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU7_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU7_SET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU7_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU7_RESET 		 MAC_DMA_TXRX_ISR_TXOK_QCU7_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU6_MSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU6_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU6_LSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU6_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU6_MASK 		 MAC_DMA_TXRX_ISR_TXOK_QCU6_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU6_GET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU6_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU6_SET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU6_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU6_RESET 		 MAC_DMA_TXRX_ISR_TXOK_QCU6_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU5_MSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU5_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU5_LSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU5_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU5_MASK 		 MAC_DMA_TXRX_ISR_TXOK_QCU5_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU5_GET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU5_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU5_SET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU5_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU5_RESET 		 MAC_DMA_TXRX_ISR_TXOK_QCU5_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU4_MSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU4_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU4_LSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU4_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU4_MASK 		 MAC_DMA_TXRX_ISR_TXOK_QCU4_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU4_GET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU4_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU4_SET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU4_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU4_RESET 		 MAC_DMA_TXRX_ISR_TXOK_QCU4_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU3_MSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU3_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU3_LSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU3_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU3_MASK 		 MAC_DMA_TXRX_ISR_TXOK_QCU3_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU3_GET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU3_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU3_SET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU3_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU3_RESET 		 MAC_DMA_TXRX_ISR_TXOK_QCU3_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU2_MSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU2_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU2_LSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU2_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU2_MASK 		 MAC_DMA_TXRX_ISR_TXOK_QCU2_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU2_GET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU2_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU2_SET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU2_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU2_RESET 		 MAC_DMA_TXRX_ISR_TXOK_QCU2_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU1_MSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU1_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU1_LSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU1_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU1_MASK 		 MAC_DMA_TXRX_ISR_TXOK_QCU1_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU1_GET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU1_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU1_SET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU1_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU1_RESET 		 MAC_DMA_TXRX_ISR_TXOK_QCU1_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU0_MSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU0_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU0_LSB 		 MAC_DMA_TXRX_ISR_TXOK_QCU0_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU0_MASK 		 MAC_DMA_TXRX_ISR_TXOK_QCU0_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU0_GET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU0_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU0_SET(x) 		 MAC_DMA_TXRX_ISR_TXOK_QCU0_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_TXOK_QCU0_RESET 		 MAC_DMA_TXRX_ISR_TXOK_QCU0_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_ADDRESS 		 MAC_DMA_TXRX_ISR_ADDRESS
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_OFFSET 		 MAC_DMA_TXRX_ISR_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_SW_MASK 		 MAC_DMA_TXRX_ISR_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RSTMASK 		 MAC_DMA_TXRX_ISR_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_ISR_RESET 		 MAC_DMA_TXRX_ISR_RESET

// 32'h0088 (MAC_DMA_ISR_S1)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RSVD_2_MSB 		 MAC_DMA_ISR_S1_RSVD_2_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RSVD_2_LSB 		 MAC_DMA_ISR_S1_RSVD_2_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RSVD_2_MASK 		 MAC_DMA_ISR_S1_RSVD_2_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RSVD_2_GET(x) 		 MAC_DMA_ISR_S1_RSVD_2_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RSVD_2_SET(x) 		 MAC_DMA_ISR_S1_RSVD_2_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RSVD_2_RESET 		 MAC_DMA_ISR_S1_RSVD_2_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_TXEOL_MSB 		 MAC_DMA_ISR_S1_TXEOL_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_TXEOL_LSB 		 MAC_DMA_ISR_S1_TXEOL_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_TXEOL_MASK 		 MAC_DMA_ISR_S1_TXEOL_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_TXEOL_GET(x) 		 MAC_DMA_ISR_S1_TXEOL_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_TXEOL_SET(x) 		 MAC_DMA_ISR_S1_TXEOL_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_TXEOL_RESET 		 MAC_DMA_ISR_S1_TXEOL_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RSVD_1_MSB 		 MAC_DMA_ISR_S1_RSVD_1_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RSVD_1_LSB 		 MAC_DMA_ISR_S1_RSVD_1_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RSVD_1_MASK 		 MAC_DMA_ISR_S1_RSVD_1_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RSVD_1_GET(x) 		 MAC_DMA_ISR_S1_RSVD_1_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RSVD_1_SET(x) 		 MAC_DMA_ISR_S1_RSVD_1_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RSVD_1_RESET 		 MAC_DMA_ISR_S1_RSVD_1_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_TXERR_MSB 		 MAC_DMA_ISR_S1_TXERR_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_TXERR_LSB 		 MAC_DMA_ISR_S1_TXERR_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_TXERR_MASK 		 MAC_DMA_ISR_S1_TXERR_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_TXERR_GET(x) 		 MAC_DMA_ISR_S1_TXERR_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_TXERR_SET(x) 		 MAC_DMA_ISR_S1_TXERR_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_TXERR_RESET 		 MAC_DMA_ISR_S1_TXERR_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_ADDRESS 		 MAC_DMA_ISR_S1_ADDRESS
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_OFFSET 		 MAC_DMA_ISR_S1_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_SW_MASK 		 MAC_DMA_ISR_S1_SW_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_SW_MASK 		 MAC_DMA_ISR_S1_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RSTMASK 		 MAC_DMA_ISR_S1_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_RESET 		 MAC_DMA_ISR_S1_RESET

// 32'h008c (MAC_DMA_ISR_S2)
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM_DTIM_FIELD_MSB 		 MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM_DTIM_FIELD_MSB
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM_DTIM_FIELD_LSB 		 MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM_DTIM_FIELD_LSB
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM_DTIM_FIELD_MASK 		 MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM_DTIM_FIELD_MASK
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM_DTIM_FIELD_GET(x) 		 MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM_DTIM_FIELD_GET(x)
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM_DTIM_FIELD_SET(x) 		 MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM_DTIM_FIELD_SET(x)
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM_DTIM_FIELD_RESET 		 MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM_DTIM_FIELD_RESET
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_ISR_S2_TBTT_TIME_STA_0_MSB 		 MAC_DMA_ISR_S2_TBTT_TIME_STA_0_MSB
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_ISR_S2_TBTT_TIME_STA_0_LSB 		 MAC_DMA_ISR_S2_TBTT_TIME_STA_0_LSB
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_ISR_S2_TBTT_TIME_STA_0_MASK 		 MAC_DMA_ISR_S2_TBTT_TIME_STA_0_MASK
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_ISR_S2_TBTT_TIME_STA_0_GET(x) 		 MAC_DMA_ISR_S2_TBTT_TIME_STA_0_GET(x)
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_ISR_S2_TBTT_TIME_STA_0_SET(x) 		 MAC_DMA_ISR_S2_TBTT_TIME_STA_0_SET(x)
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_ISR_S2_TBTT_TIME_STA_0_RESET 		 MAC_DMA_ISR_S2_TBTT_TIME_STA_0_RESET
#define MAC_DMA_ISR_S2_TSFOOR_STA_0_MSB 		 WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_MSB
#define MAC_DMA_ISR_S2_TSFOOR_STA_0_LSB 		 WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_LSB
#define MAC_DMA_ISR_S2_TSFOOR_STA_0_MASK 		 WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_MASK
#define MAC_DMA_ISR_S2_TSFOOR_STA_0_GET(x) 		 WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_GET(x)
#define MAC_DMA_ISR_S2_TSFOOR_STA_0_SET(x) 		 WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_SET(x)
#define MAC_DMA_ISR_S2_TSFOOR_STA_0_RESET 		 WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_RESET
#define MAC_DMA_ISR_S2_DTIM_STA_0_MSB 		 MCMN_ISR_S5_RX_DTIM_MSB
#define MAC_DMA_ISR_S2_DTIM_STA_0_LSB 		 MCMN_ISR_S5_RX_DTIM_LSB
#define MAC_DMA_ISR_S2_DTIM_STA_0_MASK 		 MCMN_ISR_S5_RX_DTIM_MASK
#define MAC_DMA_ISR_S2_DTIM_STA_0_GET(x) 		 MCMN_ISR_S5_RX_DTIM_GET(x)
#define MAC_DMA_ISR_S2_DTIM_STA_0_SET(x) 		 MCMN_ISR_S5_RX_DTIM_SET(x)
#define MAC_DMA_ISR_S2_DTIM_STA_0_RESET 		 MCMN_ISR_S5_RX_DTIM_RESET
#define MAC_DMA_ISR_S2_CABTO_STA_0_MSB 		 WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_MSB
#define MAC_DMA_ISR_S2_CABTO_STA_0_LSB 		 WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_LSB
#define MAC_DMA_ISR_S2_CABTO_STA_0_MASK 		 WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_MASK
#define MAC_DMA_ISR_S2_CABTO_STA_0_GET(x) 		 WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_GET(x)
#define MAC_DMA_ISR_S2_CABTO_STA_0_SET(x) 		 WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_SET(x)
#define MAC_DMA_ISR_S2_CABTO_STA_0_RESET 		 WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_RESET
#define MAC_DMA_ISR_S2_BCNTO_STA_0_MSB 		 WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_MSB
#define MAC_DMA_ISR_S2_BCNTO_STA_0_LSB 		 WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_LSB
#define MAC_DMA_ISR_S2_BCNTO_STA_0_MASK 		 WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_MASK
#define MAC_DMA_ISR_S2_BCNTO_STA_0_GET(x) 		 WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_GET(x)
#define MAC_DMA_ISR_S2_BCNTO_STA_0_SET(x) 		 WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_SET(x)
#define MAC_DMA_ISR_S2_BCNTO_STA_0_RESET 		 WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_RESET
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_0_MSB 		 WIFICMN_ISR_S0_PCU_DTIM_SYNC_MSB
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_0_LSB 		 WIFICMN_ISR_S0_PCU_DTIM_SYNC_LSB
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_0_MASK 		 WIFICMN_ISR_S0_PCU_DTIM_SYNC_MASK
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_0_GET(x) 		 WIFICMN_ISR_S0_PCU_DTIM_SYNC_GET(x)
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_0_SET(x) 		 WIFICMN_ISR_S0_PCU_DTIM_SYNC_SET(x)
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_0_RESET 		 WIFICMN_ISR_S0_PCU_DTIM_SYNC_RESET
#define MAC_DMA_ISR_S2_CABEND_STA_0_MSB 		 WIFICMN_ISR_S0_PCU_CAB_NO_MORE_MSB
#define MAC_DMA_ISR_S2_CABEND_STA_0_LSB 		 WIFICMN_ISR_S0_PCU_CAB_NO_MORE_LSB
#define MAC_DMA_ISR_S2_CABEND_STA_0_MASK 		 WIFICMN_ISR_S0_PCU_CAB_NO_MORE_MASK
#define MAC_DMA_ISR_S2_CABEND_STA_0_GET(x) 		 WIFICMN_ISR_S0_PCU_CAB_NO_MORE_GET(x)
#define MAC_DMA_ISR_S2_CABEND_STA_0_SET(x) 		 WIFICMN_ISR_S0_PCU_CAB_NO_MORE_SET(x)
#define MAC_DMA_ISR_S2_CABEND_STA_0_RESET 		 WIFICMN_ISR_S0_PCU_CAB_NO_MORE_RESET
#define MAC_DMA_ISR_S2_TIM_STA_0_MSB 		 MCMN_ISR_S5_RX_TIM_MSB
#define MAC_DMA_ISR_S2_TIM_STA_0_LSB 		 MCMN_ISR_S5_RX_TIM_LSB
#define MAC_DMA_ISR_S2_TIM_STA_0_MASK 		 MCMN_ISR_S5_RX_TIM_MASK
#define MAC_DMA_ISR_S2_TIM_STA_0_GET(x) 		 MCMN_ISR_S5_RX_TIM_GET(x)
#define MAC_DMA_ISR_S2_TIM_STA_0_SET(x) 		 MCMN_ISR_S5_RX_TIM_SET(x)
#define MAC_DMA_ISR_S2_TIM_STA_0_RESET 		 MCMN_ISR_S5_RX_TIM_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S2_GTT_MSB 		 MAC_DMA_ISR_S2_GTT_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S2_GTT_LSB 		 MAC_DMA_ISR_S2_GTT_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S2_GTT_MASK 		 MAC_DMA_ISR_S2_GTT_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S2_GTT_GET(x) 		 MAC_DMA_ISR_S2_GTT_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S2_GTT_SET(x) 		 MAC_DMA_ISR_S2_GTT_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S2_GTT_RESET 		 MAC_DMA_ISR_S2_GTT_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S2_CST_MSB 		 MAC_DMA_ISR_S2_CST_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S2_CST_LSB 		 MAC_DMA_ISR_S2_CST_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S2_CST_MASK 		 MAC_DMA_ISR_S2_CST_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S2_CST_GET(x) 		 MAC_DMA_ISR_S2_CST_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S2_CST_SET(x) 		 MAC_DMA_ISR_S2_CST_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S2_CST_RESET 		 MAC_DMA_ISR_S2_CST_RESET
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_ISR_S2_TBTT_TIME_STA_1_MSB 		 MAC_DMA_ISR_S2_TBTT_TIME_STA_1_MSB
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_ISR_S2_TBTT_TIME_STA_1_LSB 		 MAC_DMA_ISR_S2_TBTT_TIME_STA_1_LSB
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_ISR_S2_TBTT_TIME_STA_1_MASK 		 MAC_DMA_ISR_S2_TBTT_TIME_STA_1_MASK
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_ISR_S2_TBTT_TIME_STA_1_GET(x) 		 MAC_DMA_ISR_S2_TBTT_TIME_STA_1_GET(x)
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_ISR_S2_TBTT_TIME_STA_1_SET(x) 		 MAC_DMA_ISR_S2_TBTT_TIME_STA_1_SET(x)
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_ISR_S2_TBTT_TIME_STA_1_RESET 		 MAC_DMA_ISR_S2_TBTT_TIME_STA_1_RESET
#define MAC_DMA_ISR_S2_TSFOOR_STA_1_MSB 		 WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_MSB
#define MAC_DMA_ISR_S2_TSFOOR_STA_1_LSB 		 WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_LSB
#define MAC_DMA_ISR_S2_TSFOOR_STA_1_MASK 		 WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_MASK
#define MAC_DMA_ISR_S2_TSFOOR_STA_1_GET(x) 		 WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_GET(x)
#define MAC_DMA_ISR_S2_TSFOOR_STA_1_SET(x) 		 WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_SET(x)
#define MAC_DMA_ISR_S2_TSFOOR_STA_1_RESET 		 WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_RESET
#define MAC_DMA_ISR_S2_DTIM_STA_1_MSB 		 MCMN_ISR_S5_RX_DTIM_MSB
#define MAC_DMA_ISR_S2_DTIM_STA_1_LSB 		 MCMN_ISR_S5_RX_DTIM_LSB
#define MAC_DMA_ISR_S2_DTIM_STA_1_MASK 		 MCMN_ISR_S5_RX_DTIM_MASK
#define MAC_DMA_ISR_S2_DTIM_STA_1_GET(x) 		 MCMN_ISR_S5_RX_DTIM_GET(x)
#define MAC_DMA_ISR_S2_DTIM_STA_1_SET(x) 		 MCMN_ISR_S5_RX_DTIM_SET(x)
#define MAC_DMA_ISR_S2_DTIM_STA_1_RESET 		 MCMN_ISR_S5_RX_DTIM_RESET
#define MAC_DMA_ISR_S2_CABTO_STA_1_MSB 		 WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_MSB
#define MAC_DMA_ISR_S2_CABTO_STA_1_LSB 		 WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_LSB
#define MAC_DMA_ISR_S2_CABTO_STA_1_MASK 		 WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_MASK
#define MAC_DMA_ISR_S2_CABTO_STA_1_GET(x) 		 WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_GET(x)
#define MAC_DMA_ISR_S2_CABTO_STA_1_SET(x) 		 WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_SET(x)
#define MAC_DMA_ISR_S2_CABTO_STA_1_RESET 		 WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_RESET
#define MAC_DMA_ISR_S2_BCNTO_STA_1_MSB 		 WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_MSB
#define MAC_DMA_ISR_S2_BCNTO_STA_1_LSB 		 WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_LSB
#define MAC_DMA_ISR_S2_BCNTO_STA_1_MASK 		 WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_MASK
#define MAC_DMA_ISR_S2_BCNTO_STA_1_GET(x) 		 WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_GET(x)
#define MAC_DMA_ISR_S2_BCNTO_STA_1_SET(x) 		 WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_SET(x)
#define MAC_DMA_ISR_S2_BCNTO_STA_1_RESET 		 WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_RESET
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_1_MSB 		 WIFICMN_ISR_S0_PCU_DTIM_SYNC_MSB
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_1_LSB 		 WIFICMN_ISR_S0_PCU_DTIM_SYNC_LSB
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_1_MASK 		 WIFICMN_ISR_S0_PCU_DTIM_SYNC_MASK
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_1_GET(x) 		 WIFICMN_ISR_S0_PCU_DTIM_SYNC_GET(x)
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_1_SET(x) 		 WIFICMN_ISR_S0_PCU_DTIM_SYNC_SET(x)
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_1_RESET 		 WIFICMN_ISR_S0_PCU_DTIM_SYNC_RESET
#define MAC_DMA_ISR_S2_CABEND_STA_1_MSB 		 WIFICMN_ISR_S0_PCU_CAB_NO_MORE_MSB
#define MAC_DMA_ISR_S2_CABEND_STA_1_LSB 		 WIFICMN_ISR_S0_PCU_CAB_NO_MORE_LSB
#define MAC_DMA_ISR_S2_CABEND_STA_1_MASK 		 WIFICMN_ISR_S0_PCU_CAB_NO_MORE_MASK
#define MAC_DMA_ISR_S2_CABEND_STA_1_GET(x) 		 WIFICMN_ISR_S0_PCU_CAB_NO_MORE_GET(x)
#define MAC_DMA_ISR_S2_CABEND_STA_1_SET(x) 		 WIFICMN_ISR_S0_PCU_CAB_NO_MORE_SET(x)
#define MAC_DMA_ISR_S2_CABEND_STA_1_RESET 		 WIFICMN_ISR_S0_PCU_CAB_NO_MORE_RESET
#define MAC_DMA_ISR_S2_TIM_STA_1_MSB 		 MCMN_ISR_S5_RX_TIM_MSB
#define MAC_DMA_ISR_S2_TIM_STA_1_LSB 		 MCMN_ISR_S5_RX_TIM_LSB
#define MAC_DMA_ISR_S2_TIM_STA_1_MASK 		 MCMN_ISR_S5_RX_TIM_MASK
#define MAC_DMA_ISR_S2_TIM_STA_1_GET(x) 		 MCMN_ISR_S5_RX_TIM_GET(x)
#define MAC_DMA_ISR_S2_TIM_STA_1_SET(x) 		 MCMN_ISR_S5_RX_TIM_SET(x)
#define MAC_DMA_ISR_S2_TIM_STA_1_RESET 		 MCMN_ISR_S5_RX_TIM_RESET
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_MSB 		 MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_MSB
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_LSB 		 MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_LSB
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_MASK 		 MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_MASK
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_GET(x) 		 MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_SET(x) 		 MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_RESET 		 MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_RESET
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM2_DTIM2_FIELD_MSB 		 MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM2_DTIM2_FIELD_MSB
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM2_DTIM2_FIELD_LSB 		 MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM2_DTIM2_FIELD_LSB
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM2_DTIM2_FIELD_MASK 		 MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM2_DTIM2_FIELD_MASK
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM2_DTIM2_FIELD_GET(x) 		 MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM2_DTIM2_FIELD_GET(x)
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM2_DTIM2_FIELD_SET(x) 		 MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM2_DTIM2_FIELD_SET(x)
// Reason:TODO: Not exist 	 #define MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM2_DTIM2_FIELD_RESET 		 MAC_DMA_ISR_S2_MAC_DMA_REG_IMR_S2_EARLY_TIM2_DTIM2_FIELD_RESET
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_MSB 		 MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_MSB
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_LSB 		 MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_LSB
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_MASK 		 MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_MASK
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_GET(x) 		 MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_SET(x) 		 MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_RESET 		 MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_RESET
#define MAC_DMA_ISR_S2_TXURN_MSB 		 MCMN_ISR_S4_DATA_URUN_MSB
#define MAC_DMA_ISR_S2_TXURN_LSB 		 MCMN_ISR_S4_DATA_URUN_LSB
#define MAC_DMA_ISR_S2_TXURN_MASK 		 MCMN_ISR_S4_DATA_URUN_MASK
#define MAC_DMA_ISR_S2_TXURN_GET(x) 		 MCMN_ISR_S4_DATA_URUN_GET(x)
#define MAC_DMA_ISR_S2_TXURN_SET(x) 		 MCMN_ISR_S4_DATA_URUN_SET(x)
#define MAC_DMA_ISR_S2_TXURN_RESET 		 MCMN_ISR_S4_DATA_URUN_RESET
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_ADDRESS 		 MAC_DMA_ISR_S2_ADDRESS
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_OFFSET 		 MAC_DMA_ISR_S2_OFFSET
// SW modifiable bits
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_SW_MASK 		 MAC_DMA_ISR_S2_SW_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_SW_MASK 		 MAC_DMA_ISR_S2_SW_MASK
// bits defined at reset
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_RSTMASK 		 MAC_DMA_ISR_S2_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S2_RESET 		 MAC_DMA_ISR_S2_RESET

// 32'h0090 (MAC_DMA_ISR_S3)
#define MAC_DMA_ISR_S3_BMISS_STA_1_MSB 		 MCMN_ISR_S5_BCON_MISS_MSB
#define MAC_DMA_ISR_S3_BMISS_STA_1_LSB 		 MCMN_ISR_S5_BCON_MISS_LSB
#define MAC_DMA_ISR_S3_BMISS_STA_1_MASK 		 MCMN_ISR_S5_BCON_MISS_MASK
#define MAC_DMA_ISR_S3_BMISS_STA_1_GET(x) 		 MCMN_ISR_S5_BCON_MISS_GET(x)
#define MAC_DMA_ISR_S3_BMISS_STA_1_SET(x) 		 MCMN_ISR_S5_BCON_MISS_SET(x)
#define MAC_DMA_ISR_S3_BMISS_STA_1_RESET 		 MCMN_ISR_S5_BCON_MISS_RESET
#define MAC_DMA_ISR_S3_BMISS_STA_0_MSB 		 MCMN_ISR_S5_BCON_MISS_MSB
#define MAC_DMA_ISR_S3_BMISS_STA_0_LSB 		 MCMN_ISR_S5_BCON_MISS_LSB
#define MAC_DMA_ISR_S3_BMISS_STA_0_MASK 		 MCMN_ISR_S5_BCON_MISS_MASK
#define MAC_DMA_ISR_S3_BMISS_STA_0_GET(x) 		 MCMN_ISR_S5_BCON_MISS_GET(x)
#define MAC_DMA_ISR_S3_BMISS_STA_0_SET(x) 		 MCMN_ISR_S5_BCON_MISS_SET(x)
#define MAC_DMA_ISR_S3_BMISS_STA_0_RESET 		 MCMN_ISR_S5_BCON_MISS_RESET
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_MSB 		 MCMN_ISR_S5_RSSI_LOW_MSB
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_LSB 		 MCMN_ISR_S5_RSSI_LOW_LSB
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_MASK 		 MCMN_ISR_S5_RSSI_LOW_MASK
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_GET(x) 		 MCMN_ISR_S5_RSSI_LOW_GET(x)
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_SET(x) 		 MCMN_ISR_S5_RSSI_LOW_SET(x)
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_RESET 		 MCMN_ISR_S5_RSSI_LOW_RESET
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_MSB 		 MCMN_ISR_S5_RSSI_HIGH_MSB
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_LSB 		 MCMN_ISR_S5_RSSI_HIGH_LSB
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_MASK 		 MCMN_ISR_S5_RSSI_HIGH_MASK
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_GET(x) 		 MCMN_ISR_S5_RSSI_HIGH_GET(x)
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_SET(x) 		 MCMN_ISR_S5_RSSI_HIGH_SET(x)
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_RESET 		 MCMN_ISR_S5_RSSI_HIGH_RESET
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_MSB 		 MCMN_ISR_S5_RSSI_LOW_MSB
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_LSB 		 MCMN_ISR_S5_RSSI_LOW_LSB
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_MASK 		 MCMN_ISR_S5_RSSI_LOW_MASK
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_GET(x) 		 MCMN_ISR_S5_RSSI_LOW_GET(x)
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_SET(x) 		 MCMN_ISR_S5_RSSI_LOW_SET(x)
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_RESET 		 MCMN_ISR_S5_RSSI_LOW_RESET
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_MSB 		 MCMN_ISR_S5_RSSI_HIGH_MSB
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_LSB 		 MCMN_ISR_S5_RSSI_HIGH_LSB
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_MASK 		 MCMN_ISR_S5_RSSI_HIGH_MASK
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_GET(x) 		 MCMN_ISR_S5_RSSI_HIGH_GET(x)
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_SET(x) 		 MCMN_ISR_S5_RSSI_HIGH_SET(x)
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_RESET 		 MCMN_ISR_S5_RSSI_HIGH_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S3_QCBRURN_MSB 		 MAC_DMA_ISR_S3_QCBRURN_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S3_QCBRURN_LSB 		 MAC_DMA_ISR_S3_QCBRURN_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S3_QCBRURN_MASK 		 MAC_DMA_ISR_S3_QCBRURN_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S3_QCBRURN_GET(x) 		 MAC_DMA_ISR_S3_QCBRURN_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S3_QCBRURN_SET(x) 		 MAC_DMA_ISR_S3_QCBRURN_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S3_QCBRURN_RESET 		 MAC_DMA_ISR_S3_QCBRURN_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_MSB 		 MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_LSB 		 MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_MASK 		 MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_GET(x) 		 MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_SET(x) 		 MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_RESET 		 MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_MSB 		 MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_LSB 		 MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_MASK 		 MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_GET(x) 		 MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_SET(x) 		 MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_RESET 		 MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S3_QCBROVF_MSB 		 MAC_DMA_ISR_S3_QCBROVF_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S3_QCBROVF_LSB 		 MAC_DMA_ISR_S3_QCBROVF_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S3_QCBROVF_MASK 		 MAC_DMA_ISR_S3_QCBROVF_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S3_QCBROVF_GET(x) 		 MAC_DMA_ISR_S3_QCBROVF_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S3_QCBROVF_SET(x) 		 MAC_DMA_ISR_S3_QCBROVF_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S3_QCBROVF_RESET 		 MAC_DMA_ISR_S3_QCBROVF_RESET
// Reason:Obsolete 	 #define MAC_DMA_ISR_S3_ADDRESS 		 MAC_DMA_ISR_S3_ADDRESS
// Reason:Obsolete 	 #define MAC_DMA_ISR_S3_OFFSET 		 MAC_DMA_ISR_S3_OFFSET
// SW modifiable bits
// Reason:Obsolete 	 #define MAC_DMA_ISR_S3_SW_MASK 		 MAC_DMA_ISR_S3_SW_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_SW_MASK 		 MAC_DMA_ISR_S3_SW_MASK
// bits defined at reset
// Reason:Obsolete 	 #define MAC_DMA_ISR_S3_RSTMASK 		 MAC_DMA_ISR_S3_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S3_RESET 		 MAC_DMA_ISR_S3_RESET

// 32'h0094 (MAC_DMA_ISR_S4)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RSVD_2_MSB 		 MAC_DMA_ISR_S4_RSVD_2_MSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RSVD_2_LSB 		 MAC_DMA_ISR_S4_RSVD_2_LSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RSVD_2_MASK 		 MAC_DMA_ISR_S4_RSVD_2_MASK
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RSVD_2_GET(x) 		 MAC_DMA_ISR_S4_RSVD_2_GET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RSVD_2_SET(x) 		 MAC_DMA_ISR_S4_RSVD_2_SET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RSVD_2_RESET 		 MAC_DMA_ISR_S4_RSVD_2_RESET
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_TXDP_FIFO_OVF_MSB 		 MAC_DMA_ISR_S4_TXDP_FIFO_OVF_MSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_TXDP_FIFO_OVF_LSB 		 MAC_DMA_ISR_S4_TXDP_FIFO_OVF_LSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_TXDP_FIFO_OVF_MASK 		 MAC_DMA_ISR_S4_TXDP_FIFO_OVF_MASK
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_TXDP_FIFO_OVF_GET(x) 		 MAC_DMA_ISR_S4_TXDP_FIFO_OVF_GET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_TXDP_FIFO_OVF_SET(x) 		 MAC_DMA_ISR_S4_TXDP_FIFO_OVF_SET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_TXDP_FIFO_OVF_RESET 		 MAC_DMA_ISR_S4_TXDP_FIFO_OVF_RESET
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RSVD_1_MSB 		 MAC_DMA_ISR_S4_RSVD_1_MSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RSVD_1_LSB 		 MAC_DMA_ISR_S4_RSVD_1_LSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RSVD_1_MASK 		 MAC_DMA_ISR_S4_RSVD_1_MASK
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RSVD_1_GET(x) 		 MAC_DMA_ISR_S4_RSVD_1_GET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RSVD_1_SET(x) 		 MAC_DMA_ISR_S4_RSVD_1_SET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RSVD_1_RESET 		 MAC_DMA_ISR_S4_RSVD_1_RESET
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_QTRIG_MSB 		 MAC_DMA_ISR_S4_QTRIG_MSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_QTRIG_LSB 		 MAC_DMA_ISR_S4_QTRIG_LSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_QTRIG_MASK 		 MAC_DMA_ISR_S4_QTRIG_MASK
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_QTRIG_GET(x) 		 MAC_DMA_ISR_S4_QTRIG_GET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_QTRIG_SET(x) 		 MAC_DMA_ISR_S4_QTRIG_SET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_QTRIG_RESET 		 MAC_DMA_ISR_S4_QTRIG_RESET
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_ADDRESS 		 MAC_DMA_ISR_S4_ADDRESS
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_OFFSET 		 MAC_DMA_ISR_S4_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_SW_MASK 		 MAC_DMA_ISR_S4_SW_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_SW_MASK 		 MAC_DMA_ISR_S4_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RSTMASK 		 MAC_DMA_ISR_S4_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_RESET 		 MAC_DMA_ISR_S4_RESET

// 32'h0098 (MAC_DMA_ISR_S5)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_MSB 		 WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_MSB
#define MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_LSB 		 WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_LSB
#define MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_MASK 		 WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_MASK
#define MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_GET(x) 		 WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_GET(x)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_SET(x) 		 WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_SET(x)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_RESET 		 WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_RESET
#define MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_MSB 		 WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_MSB
#define MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_LSB 		 WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_LSB
#define MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_MASK 		 WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_MASK
#define MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_GET(x) 		 WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_GET(x)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_SET(x) 		 WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_SET(x)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_RESET 		 WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_RESET
#define MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_MSB 		 WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_MSB
#define MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_LSB 		 WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_LSB
#define MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_MASK 		 WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_MASK
#define MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_GET(x) 		 WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_GET(x)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_SET(x) 		 WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_SET(x)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_RESET 		 WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_RESET
// Reason:Obsolete 	 #define MAC_DMA_ISR_S5_ADDRESS 		 MAC_DMA_ISR_S5_ADDRESS
// Reason:Obsolete 	 #define MAC_DMA_ISR_S5_OFFSET 		 MAC_DMA_ISR_S5_OFFSET
// SW modifiable bits
// Reason:Obsolete 	 #define MAC_DMA_ISR_S5_SW_MASK 		 MAC_DMA_ISR_S5_SW_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_SW_MASK 		 MAC_DMA_ISR_S5_SW_MASK
// bits defined at reset
// Reason:Obsolete 	 #define MAC_DMA_ISR_S5_RSTMASK 		 MAC_DMA_ISR_S5_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S5_RESET 		 MAC_DMA_ISR_S5_RESET

// 32'h009c (MAC_DMA_ISR_S6)
#define MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_MSB 		 MCMN_IMR_S2_OLE_RDY_TMOUT_MSB
#define MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_LSB 		 MCMN_IMR_S2_OLE_RDY_TMOUT_LSB
#define MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_MASK 		 MCMN_IMR_S2_OLE_RDY_TMOUT_MASK
#define MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_GET(x) 		 MCMN_IMR_S2_OLE_RDY_TMOUT_GET(x)
#define MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_SET(x) 		 MCMN_IMR_S2_OLE_RDY_TMOUT_SET(x)
#define MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_RESET 		 MCMN_IMR_S2_OLE_RDY_TMOUT_RESET
#define MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_MSB 		 MCMN_IMR_S2_AXI_TMOUT_MSB
#define MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_LSB 		 MCMN_IMR_S2_AXI_TMOUT_LSB
#define MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_MASK 		 MCMN_IMR_S2_AXI_TMOUT_MASK
#define MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_GET(x) 		 MCMN_IMR_S2_AXI_TMOUT_GET(x)
#define MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_SET(x) 		 MCMN_IMR_S2_AXI_TMOUT_SET(x)
#define MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_RESET 		 MCMN_IMR_S2_AXI_TMOUT_RESET
#define MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_MSB 		 MCMN_IMR_S5_CONFIG_PHY_ERR_MSB
#define MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_LSB 		 MCMN_IMR_S5_CONFIG_PHY_ERR_LSB
#define MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_MASK 		 MCMN_IMR_S5_CONFIG_PHY_ERR_MASK
#define MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_GET(x) 		 MCMN_IMR_S5_CONFIG_PHY_ERR_GET(x)
#define MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_SET(x) 		 MCMN_IMR_S5_CONFIG_PHY_ERR_SET(x)
#define MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_RESET 		 MCMN_IMR_S5_CONFIG_PHY_ERR_RESET
#define MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_MSB 		 MCMN_IMR_S2_UNEX_NUL_PTR_MSB
#define MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_LSB 		 MCMN_IMR_S2_UNEX_NUL_PTR_LSB
#define MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_MASK 		 MCMN_IMR_S2_UNEX_NUL_PTR_MASK
#define MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_GET(x) 		 MCMN_IMR_S2_UNEX_NUL_PTR_GET(x)
#define MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_SET(x) 		 MCMN_IMR_S2_UNEX_NUL_PTR_SET(x)
#define MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_RESET 		 MCMN_IMR_S2_UNEX_NUL_PTR_RESET
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MSB 		 MCMN_IMR_S3_NON_PKT_BUF_MSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_LSB 		 MCMN_IMR_S3_NON_PKT_BUF_LSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MASK 		 MCMN_IMR_S3_NON_PKT_BUF_MASK
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_GET(x) 		 MCMN_IMR_S3_NON_PKT_BUF_GET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_SET(x) 		 MCMN_IMR_S3_NON_PKT_BUF_SET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_RESET 		 MCMN_IMR_S3_NON_PKT_BUF_RESET
#define MAC_DMA_ISR_S6_RX_DMA_RING_LWM_MSB 		 MCMN_IMR_S3_RXDMA_RNG_LWM_MSB
#define MAC_DMA_ISR_S6_RX_DMA_RING_LWM_LSB 		 MCMN_IMR_S3_RXDMA_RNG_LWM_LSB
#define MAC_DMA_ISR_S6_RX_DMA_RING_LWM_MASK 		 MCMN_IMR_S3_RXDMA_RNG_LWM_MASK
#define MAC_DMA_ISR_S6_RX_DMA_RING_LWM_GET(x) 		 MCMN_IMR_S3_RXDMA_RNG_LWM_GET(x)
#define MAC_DMA_ISR_S6_RX_DMA_RING_LWM_SET(x) 		 MCMN_IMR_S3_RXDMA_RNG_LWM_SET(x)
#define MAC_DMA_ISR_S6_RX_DMA_RING_LWM_RESET 		 MCMN_IMR_S3_RXDMA_RNG_LWM_RESET
#define MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_MSB 		 MCMN_IMR_S3_MDAT_TLV_MSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_LSB 		 MCMN_IMR_S3_MDAT_TLV_LSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_MASK 		 MCMN_IMR_S3_MDAT_TLV_MASK
#define MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_GET(x) 		 MCMN_IMR_S3_MDAT_TLV_GET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_SET(x) 		 MCMN_IMR_S3_MDAT_TLV_SET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_RESET 		 MCMN_IMR_S3_MDAT_TLV_RESET
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_MSB 		 MCMN_IMR_S3_NULL_RNG_MSK_MSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_LSB 		 MCMN_IMR_S3_NULL_RNG_MSK_LSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_MASK 		 MCMN_IMR_S3_NULL_RNG_MSK_MASK
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_GET(x) 		 MCMN_IMR_S3_NULL_RNG_MSK_GET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_SET(x) 		 MCMN_IMR_S3_NULL_RNG_MSK_SET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_RESET 		 MCMN_IMR_S3_NULL_RNG_MSK_RESET
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_MSB 		 MCMN_IMR_S3_INVAL_TAG_ID_MSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_LSB 		 MCMN_IMR_S3_INVAL_TAG_ID_LSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_MASK 		 MCMN_IMR_S3_INVAL_TAG_ID_MASK
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_GET(x) 		 MCMN_IMR_S3_INVAL_TAG_ID_GET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_SET(x) 		 MCMN_IMR_S3_INVAL_TAG_ID_SET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_RESET 		 MCMN_IMR_S3_INVAL_TAG_ID_RESET
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_MSB 		 MCMN_IMR_S3_INVAL_TAG_SEG_MSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_LSB 		 MCMN_IMR_S3_INVAL_TAG_SEG_LSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_MASK 		 MCMN_IMR_S3_INVAL_TAG_SEG_MASK
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_GET(x) 		 MCMN_IMR_S3_INVAL_TAG_SEG_GET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_SET(x) 		 MCMN_IMR_S3_INVAL_TAG_SEG_SET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_RESET 		 MCMN_IMR_S3_INVAL_TAG_SEG_RESET
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_MSB 		 MCMN_IMR_S3_TLV_SHORT_MSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_LSB 		 MCMN_IMR_S3_TLV_SHORT_LSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_MASK 		 MCMN_IMR_S3_TLV_SHORT_MASK
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_GET(x) 		 MCMN_IMR_S3_TLV_SHORT_GET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_SET(x) 		 MCMN_IMR_S3_TLV_SHORT_SET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_RESET 		 MCMN_IMR_S3_TLV_SHORT_RESET
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_MSB 		 MCMN_IMR_S3_TLV_FRME_ERR_MSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_LSB 		 MCMN_IMR_S3_TLV_FRME_ERR_LSB
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_MASK 		 MCMN_IMR_S3_TLV_FRME_ERR_MASK
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_GET(x) 		 MCMN_IMR_S3_TLV_FRME_ERR_GET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_SET(x) 		 MCMN_IMR_S3_TLV_FRME_ERR_SET(x)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_RESET 		 MCMN_IMR_S3_TLV_FRME_ERR_RESET
#define MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_MSB 		 WIFICMN_ISR_S2_PTA_BT_PRIORITY_RISE_MSB
#define MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_LSB 		 WIFICMN_ISR_S2_PTA_BT_PRIORITY_RISE_LSB
#define MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_MASK 		 WIFICMN_ISR_S2_PTA_BT_PRIORITY_RISE_MASK
#define MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_GET(x) 		 WIFICMN_ISR_S2_PTA_BT_PRIORITY_RISE_GET(x)
#define MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_SET(x) 		 WIFICMN_ISR_S2_PTA_BT_PRIORITY_RISE_SET(x)
#define MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_RESET 		 WIFICMN_ISR_S2_PTA_BT_PRIORITY_RISE_RESET
#define MAC_DMA_ISR_S6_BT_PRIORITY_RISING_MSB 		 WIFICMN_ISR_S2_PTA_BT_PRIORITY_RISE_MSB
#define MAC_DMA_ISR_S6_BT_PRIORITY_RISING_LSB 		 WIFICMN_ISR_S2_PTA_BT_PRIORITY_RISE_LSB
#define MAC_DMA_ISR_S6_BT_PRIORITY_RISING_MASK 		 WIFICMN_ISR_S2_PTA_BT_PRIORITY_RISE_MASK
#define MAC_DMA_ISR_S6_BT_PRIORITY_RISING_GET(x) 		 WIFICMN_ISR_S2_PTA_BT_PRIORITY_RISE_GET(x)
#define MAC_DMA_ISR_S6_BT_PRIORITY_RISING_SET(x) 		 WIFICMN_ISR_S2_PTA_BT_PRIORITY_RISE_SET(x)
#define MAC_DMA_ISR_S6_BT_PRIORITY_RISING_RESET 		 WIFICMN_ISR_S2_PTA_BT_PRIORITY_RISE_RESET
#define MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_MSB 		 WIFICMN_ISR_S2_PTA_BT_ACTIVE_FALL_MSB
#define MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_LSB 		 WIFICMN_ISR_S2_PTA_BT_ACTIVE_FALL_LSB
#define MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_MASK 		 WIFICMN_ISR_S2_PTA_BT_ACTIVE_FALL_MASK
#define MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_GET(x) 		 WIFICMN_ISR_S2_PTA_BT_ACTIVE_FALL_GET(x)
#define MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_SET(x) 		 WIFICMN_ISR_S2_PTA_BT_ACTIVE_FALL_SET(x)
#define MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_RESET 		 WIFICMN_ISR_S2_PTA_BT_ACTIVE_FALL_RESET
#define MAC_DMA_ISR_S6_BT_ACTIVE_RISING_MSB 		 WIFICMN_ISR_S2_PTA_BT_ACTIVE_RISE_MSB
#define MAC_DMA_ISR_S6_BT_ACTIVE_RISING_LSB 		 WIFICMN_ISR_S2_PTA_BT_ACTIVE_RISE_LSB
#define MAC_DMA_ISR_S6_BT_ACTIVE_RISING_MASK 		 WIFICMN_ISR_S2_PTA_BT_ACTIVE_RISE_MASK
#define MAC_DMA_ISR_S6_BT_ACTIVE_RISING_GET(x) 		 WIFICMN_ISR_S2_PTA_BT_ACTIVE_RISE_GET(x)
#define MAC_DMA_ISR_S6_BT_ACTIVE_RISING_SET(x) 		 WIFICMN_ISR_S2_PTA_BT_ACTIVE_RISE_SET(x)
#define MAC_DMA_ISR_S6_BT_ACTIVE_RISING_RESET 		 WIFICMN_ISR_S2_PTA_BT_ACTIVE_RISE_RESET
#define MAC_DMA_ISR_S6_WL_STOMPED_MSB 		 WIFICMN_ISR_S2_PTA_WL_STOMPED_MSB
#define MAC_DMA_ISR_S6_WL_STOMPED_LSB 		 WIFICMN_ISR_S2_PTA_WL_STOMPED_LSB
#define MAC_DMA_ISR_S6_WL_STOMPED_MASK 		 WIFICMN_ISR_S2_PTA_WL_STOMPED_MASK
#define MAC_DMA_ISR_S6_WL_STOMPED_GET(x) 		 WIFICMN_ISR_S2_PTA_WL_STOMPED_GET(x)
#define MAC_DMA_ISR_S6_WL_STOMPED_SET(x) 		 WIFICMN_ISR_S2_PTA_WL_STOMPED_SET(x)
#define MAC_DMA_ISR_S6_WL_STOMPED_RESET 		 WIFICMN_ISR_S2_PTA_WL_STOMPED_RESET
#define MAC_DMA_ISR_S6_BT_STOMPED_MSB 		 WIFICMN_ISR_S2_PTA_BT_STOMPED_MSB
#define MAC_DMA_ISR_S6_BT_STOMPED_LSB 		 WIFICMN_ISR_S2_PTA_BT_STOMPED_LSB
#define MAC_DMA_ISR_S6_BT_STOMPED_MASK 		 WIFICMN_ISR_S2_PTA_BT_STOMPED_MASK
#define MAC_DMA_ISR_S6_BT_STOMPED_GET(x) 		 WIFICMN_ISR_S2_PTA_BT_STOMPED_GET(x)
#define MAC_DMA_ISR_S6_BT_STOMPED_SET(x) 		 WIFICMN_ISR_S2_PTA_BT_STOMPED_SET(x)
#define MAC_DMA_ISR_S6_BT_STOMPED_RESET 		 WIFICMN_ISR_S2_PTA_BT_STOMPED_RESET
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_MSB 		 WIFICMN_ISR_S2_PTA_BT_LOW_PRTY_FALL_MSB
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_LSB 		 WIFICMN_ISR_S2_PTA_BT_LOW_PRTY_FALL_LSB
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_MASK 		 WIFICMN_ISR_S2_PTA_BT_LOW_PRTY_FALL_MASK
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_GET(x) 		 WIFICMN_ISR_S2_PTA_BT_LOW_PRTY_FALL_GET(x)
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_SET(x) 		 WIFICMN_ISR_S2_PTA_BT_LOW_PRTY_FALL_SET(x)
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_RESET 		 WIFICMN_ISR_S2_PTA_BT_LOW_PRTY_FALL_RESET
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_MSB 		 WIFICMN_ISR_S2_PTA_BT_LOW_PRTY_RISE_MSB
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_LSB 		 WIFICMN_ISR_S2_PTA_BT_LOW_PRTY_RISE_LSB
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_MASK 		 WIFICMN_ISR_S2_PTA_BT_LOW_PRTY_RISE_MASK
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_GET(x) 		 WIFICMN_ISR_S2_PTA_BT_LOW_PRTY_RISE_GET(x)
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_SET(x) 		 WIFICMN_ISR_S2_PTA_BT_LOW_PRTY_RISE_SET(x)
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_RESET 		 WIFICMN_ISR_S2_PTA_BT_LOW_PRTY_RISE_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S6_BB_PANIC_IRQ_MSB 		 MAC_DMA_ISR_S6_BB_PANIC_IRQ_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S6_BB_PANIC_IRQ_LSB 		 MAC_DMA_ISR_S6_BB_PANIC_IRQ_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S6_BB_PANIC_IRQ_MASK 		 MAC_DMA_ISR_S6_BB_PANIC_IRQ_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S6_BB_PANIC_IRQ_GET(x) 		 MAC_DMA_ISR_S6_BB_PANIC_IRQ_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S6_BB_PANIC_IRQ_SET(x) 		 MAC_DMA_ISR_S6_BB_PANIC_IRQ_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S6_BB_PANIC_IRQ_RESET 		 MAC_DMA_ISR_S6_BB_PANIC_IRQ_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_MSB 		 MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_LSB 		 MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_MASK 		 MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_GET(x) 		 MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_SET(x) 		 MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_RESET 		 MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_RESET
// Reason:Obsolete 	 #define MAC_DMA_ISR_S6_ADDRESS 		 MAC_DMA_ISR_S6_ADDRESS
// Reason:Obsolete 	 #define MAC_DMA_ISR_S6_OFFSET 		 MAC_DMA_ISR_S6_OFFSET
// SW modifiable bits
// Reason:Obsolete 	 #define MAC_DMA_ISR_S6_SW_MASK 		 MAC_DMA_ISR_S6_SW_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_SW_MASK 		 MAC_DMA_ISR_S6_SW_MASK
// bits defined at reset
// Reason:Obsolete 	 #define MAC_DMA_ISR_S6_RSTMASK 		 MAC_DMA_ISR_S6_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S6_RESET 		 MAC_DMA_ISR_S6_RESET

// 32'h00a0 (MAC_DMA_IMR_P)
#define MAC_DMA_IMR_P_GENTMR_MSB 		 WIFICMN_IMR_P_WIFI_TIMER_MSB
#define MAC_DMA_IMR_P_GENTMR_LSB 		 WIFICMN_IMR_P_WIFI_TIMER_LSB
#define MAC_DMA_IMR_P_GENTMR_MASK 		 WIFICMN_IMR_P_WIFI_TIMER_MASK
#define MAC_DMA_IMR_P_GENTMR_GET(x) 		 WIFICMN_IMR_P_WIFI_TIMER_GET(x)
#define MAC_DMA_IMR_P_GENTMR_SET(x) 		 WIFICMN_IMR_P_WIFI_TIMER_SET(x)
#define MAC_DMA_IMR_P_GENTMR_RESET 		 WIFICMN_IMR_P_WIFI_TIMER_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QTRIG_MSB 		 MAC_DMA_IMR_P_QTRIG_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QTRIG_LSB 		 MAC_DMA_IMR_P_QTRIG_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QTRIG_MASK 		 MAC_DMA_IMR_P_QTRIG_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QTRIG_GET(x) 		 MAC_DMA_IMR_P_QTRIG_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QTRIG_SET(x) 		 MAC_DMA_IMR_P_QTRIG_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QTRIG_RESET 		 MAC_DMA_IMR_P_QTRIG_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QCBRURN_MSB 		 MAC_DMA_IMR_P_QCBRURN_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QCBRURN_LSB 		 MAC_DMA_IMR_P_QCBRURN_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QCBRURN_MASK 		 MAC_DMA_IMR_P_QCBRURN_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QCBRURN_GET(x) 		 MAC_DMA_IMR_P_QCBRURN_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QCBRURN_SET(x) 		 MAC_DMA_IMR_P_QCBRURN_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QCBRURN_RESET 		 MAC_DMA_IMR_P_QCBRURN_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QCBROVF_MSB 		 MAC_DMA_IMR_P_QCBROVF_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QCBROVF_LSB 		 MAC_DMA_IMR_P_QCBROVF_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QCBROVF_MASK 		 MAC_DMA_IMR_P_QCBROVF_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QCBROVF_GET(x) 		 MAC_DMA_IMR_P_QCBROVF_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QCBROVF_SET(x) 		 MAC_DMA_IMR_P_QCBROVF_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_QCBROVF_RESET 		 MAC_DMA_IMR_P_QCBROVF_RESET
// Reason:Obsolete: architecture change - used to be OR of tx_config_phy_err, bb_temp_sensor and bb_panic. Only tx_config_phy_err exists. 	 #define MAC_DMA_IMR_P_BB_INT_MSB 		 MAC_DMA_IMR_P_BB_INT_MSB
// Reason:Obsolete: architecture change - used to be OR of tx_config_phy_err, bb_temp_sensor and bb_panic. Only tx_config_phy_err exists. 	 #define MAC_DMA_IMR_P_BB_INT_LSB 		 MAC_DMA_IMR_P_BB_INT_LSB
// Reason:Obsolete: architecture change - used to be OR of tx_config_phy_err, bb_temp_sensor and bb_panic. Only tx_config_phy_err exists. 	 #define MAC_DMA_IMR_P_BB_INT_MASK 		 MAC_DMA_IMR_P_BB_INT_MASK
// Reason:Obsolete: architecture change - used to be OR of tx_config_phy_err, bb_temp_sensor and bb_panic. Only tx_config_phy_err exists. 	 #define MAC_DMA_IMR_P_BB_INT_GET(x) 		 MAC_DMA_IMR_P_BB_INT_GET(x)
// Reason:Obsolete: architecture change - used to be OR of tx_config_phy_err, bb_temp_sensor and bb_panic. Only tx_config_phy_err exists. 	 #define MAC_DMA_IMR_P_BB_INT_SET(x) 		 MAC_DMA_IMR_P_BB_INT_SET(x)
// Reason:Obsolete: architecture change - used to be OR of tx_config_phy_err, bb_temp_sensor and bb_panic. Only tx_config_phy_err exists. 	 #define MAC_DMA_IMR_P_BB_INT_RESET 		 MAC_DMA_IMR_P_BB_INT_RESET
#define MAC_DMA_IMR_P_BCNMISC_MSB 		 WIFICMN_IMR_P_WIFI_TIMER_MSB
#define MAC_DMA_IMR_P_BCNMISC_LSB 		 WIFICMN_IMR_P_WIFI_TIMER_LSB
#define MAC_DMA_IMR_P_BCNMISC_MASK 		 WIFICMN_IMR_P_WIFI_TIMER_MASK
#define MAC_DMA_IMR_P_BCNMISC_GET(x) 		 WIFICMN_IMR_P_WIFI_TIMER_GET(x)
#define MAC_DMA_IMR_P_BCNMISC_SET(x) 		 WIFICMN_IMR_P_WIFI_TIMER_SET(x)
#define MAC_DMA_IMR_P_BCNMISC_RESET 		 WIFICMN_IMR_P_WIFI_TIMER_RESET
#define MAC_DMA_IMR_P_OLE_INT_MSB 		 MCMN_IMR_P_OLE_MSB
#define MAC_DMA_IMR_P_OLE_INT_LSB 		 MCMN_IMR_P_OLE_LSB
#define MAC_DMA_IMR_P_OLE_INT_MASK 		 MCMN_IMR_P_OLE_MASK
#define MAC_DMA_IMR_P_OLE_INT_GET(x) 		 MCMN_IMR_P_OLE_GET(x)
#define MAC_DMA_IMR_P_OLE_INT_SET(x) 		 MCMN_IMR_P_OLE_SET(x)
#define MAC_DMA_IMR_P_OLE_INT_RESET 		 MCMN_IMR_P_OLE_RESET
// Reason:Obsolete: Used for BT coex Rx frame priority 	 #define MAC_DMA_IMR_P_RXINT_MSB 		 MAC_DMA_IMR_P_RXINT_MSB
// Reason:Obsolete: Used for BT coex Rx frame priority 	 #define MAC_DMA_IMR_P_RXINT_LSB 		 MAC_DMA_IMR_P_RXINT_LSB
// Reason:Obsolete: Used for BT coex Rx frame priority 	 #define MAC_DMA_IMR_P_RXINT_MASK 		 MAC_DMA_IMR_P_RXINT_MASK
// Reason:Obsolete: Used for BT coex Rx frame priority 	 #define MAC_DMA_IMR_P_RXINT_GET(x) 		 MAC_DMA_IMR_P_RXINT_GET(x)
// Reason:Obsolete: Used for BT coex Rx frame priority 	 #define MAC_DMA_IMR_P_RXINT_SET(x) 		 MAC_DMA_IMR_P_RXINT_SET(x)
// Reason:Obsolete: Used for BT coex Rx frame priority 	 #define MAC_DMA_IMR_P_RXINT_RESET 		 MAC_DMA_IMR_P_RXINT_RESET
// Reason:TODO: Not exist 	 #define MAC_DMA_IMR_P_BNR_MSB 		 MAC_DMA_IMR_P_BNR_MSB
// Reason:TODO: Not exist 	 #define MAC_DMA_IMR_P_BNR_LSB 		 MAC_DMA_IMR_P_BNR_LSB
// Reason:TODO: Not exist 	 #define MAC_DMA_IMR_P_BNR_MASK 		 MAC_DMA_IMR_P_BNR_MASK
// Reason:TODO: Not exist 	 #define MAC_DMA_IMR_P_BNR_GET(x) 		 MAC_DMA_IMR_P_BNR_GET(x)
// Reason:TODO: Not exist 	 #define MAC_DMA_IMR_P_BNR_SET(x) 		 MAC_DMA_IMR_P_BNR_SET(x)
// Reason:TODO: Not exist 	 #define MAC_DMA_IMR_P_BNR_RESET 		 MAC_DMA_IMR_P_BNR_RESET
#define MAC_DMA_IMR_P_BMISS_MSB 		 MCMN_IMR_S5_BCON_MISS_MSB
#define MAC_DMA_IMR_P_BMISS_LSB 		 MCMN_IMR_S5_BCON_MISS_LSB
#define MAC_DMA_IMR_P_BMISS_MASK 		 MCMN_IMR_S5_BCON_MISS_MASK
#define MAC_DMA_IMR_P_BMISS_GET(x) 		 MCMN_IMR_S5_BCON_MISS_GET(x)
#define MAC_DMA_IMR_P_BMISS_SET(x) 		 MCMN_IMR_S5_BCON_MISS_SET(x)
#define MAC_DMA_IMR_P_BMISS_RESET 		 MCMN_IMR_S5_BCON_MISS_RESET
// Reason:Obsolete: architecture change - OR version is gone but indivisual RSSI_LOW and RSSI_HIGH exist in MCMN_IMR_S5. 	 #define MAC_DMA_IMR_P_BRSSI_MSB 		 MAC_DMA_IMR_P_BRSSI_MSB
// Reason:Obsolete: architecture change - OR version is gone but indivisual RSSI_LOW and RSSI_HIGH exist in MCMN_IMR_S5. 	 #define MAC_DMA_IMR_P_BRSSI_LSB 		 MAC_DMA_IMR_P_BRSSI_LSB
// Reason:Obsolete: architecture change - OR version is gone but indivisual RSSI_LOW and RSSI_HIGH exist in MCMN_IMR_S5. 	 #define MAC_DMA_IMR_P_BRSSI_MASK 		 MAC_DMA_IMR_P_BRSSI_MASK
// Reason:Obsolete: architecture change - OR version is gone but indivisual RSSI_LOW and RSSI_HIGH exist in MCMN_IMR_S5. 	 #define MAC_DMA_IMR_P_BRSSI_GET(x) 		 MAC_DMA_IMR_P_BRSSI_GET(x)
// Reason:Obsolete: architecture change - OR version is gone but indivisual RSSI_LOW and RSSI_HIGH exist in MCMN_IMR_S5. 	 #define MAC_DMA_IMR_P_BRSSI_SET(x) 		 MAC_DMA_IMR_P_BRSSI_SET(x)
// Reason:Obsolete: architecture change - OR version is gone but indivisual RSSI_LOW and RSSI_HIGH exist in MCMN_IMR_S5. 	 #define MAC_DMA_IMR_P_BRSSI_RESET 		 MAC_DMA_IMR_P_BRSSI_RESET
// Reason:TODO: Not exist: PCU_GEN_TIMER_TRIGGER can be used? 	 #define MAC_DMA_IMR_P_SWBA_MSB 		 MAC_DMA_IMR_P_SWBA_MSB
// Reason:TODO: Not exist: PCU_GEN_TIMER_TRIGGER can be used? 	 #define MAC_DMA_IMR_P_SWBA_LSB 		 MAC_DMA_IMR_P_SWBA_LSB
// Reason:TODO: Not exist: PCU_GEN_TIMER_TRIGGER can be used? 	 #define MAC_DMA_IMR_P_SWBA_MASK 		 MAC_DMA_IMR_P_SWBA_MASK
// Reason:TODO: Not exist: PCU_GEN_TIMER_TRIGGER can be used? 	 #define MAC_DMA_IMR_P_SWBA_GET(x) 		 MAC_DMA_IMR_P_SWBA_GET(x)
// Reason:TODO: Not exist: PCU_GEN_TIMER_TRIGGER can be used? 	 #define MAC_DMA_IMR_P_SWBA_SET(x) 		 MAC_DMA_IMR_P_SWBA_SET(x)
// Reason:TODO: Not exist: PCU_GEN_TIMER_TRIGGER can be used? 	 #define MAC_DMA_IMR_P_SWBA_RESET 		 MAC_DMA_IMR_P_SWBA_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_SWI_MSB 		 MAC_DMA_IMR_P_SWI_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_SWI_LSB 		 MAC_DMA_IMR_P_SWI_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_SWI_MASK 		 MAC_DMA_IMR_P_SWI_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_SWI_GET(x) 		 MAC_DMA_IMR_P_SWI_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_SWI_SET(x) 		 MAC_DMA_IMR_P_SWI_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_SWI_RESET 		 MAC_DMA_IMR_P_SWI_RESET
// Reason:TODO: Not exist 	 #define MAC_DMA_IMR_P_MIB_MSB 		 MAC_DMA_IMR_P_MIB_MSB
// Reason:TODO: Not exist 	 #define MAC_DMA_IMR_P_MIB_LSB 		 MAC_DMA_IMR_P_MIB_LSB
// Reason:TODO: Not exist 	 #define MAC_DMA_IMR_P_MIB_MASK 		 MAC_DMA_IMR_P_MIB_MASK
// Reason:TODO: Not exist 	 #define MAC_DMA_IMR_P_MIB_GET(x) 		 MAC_DMA_IMR_P_MIB_GET(x)
// Reason:TODO: Not exist 	 #define MAC_DMA_IMR_P_MIB_SET(x) 		 MAC_DMA_IMR_P_MIB_SET(x)
// Reason:TODO: Not exist 	 #define MAC_DMA_IMR_P_MIB_RESET 		 MAC_DMA_IMR_P_MIB_RESET
#define MAC_DMA_IMR_P_TXURN_MSB 		 MCMN_IMR_S4_DATA_URUN_MSB
#define MAC_DMA_IMR_P_TXURN_LSB 		 MCMN_IMR_S4_DATA_URUN_LSB
#define MAC_DMA_IMR_P_TXURN_MASK 		 MCMN_IMR_S4_DATA_URUN_MASK
#define MAC_DMA_IMR_P_TXURN_GET(x) 		 MCMN_IMR_S4_DATA_URUN_GET(x)
#define MAC_DMA_IMR_P_TXURN_SET(x) 		 MCMN_IMR_S4_DATA_URUN_SET(x)
#define MAC_DMA_IMR_P_TXURN_RESET 		 MCMN_IMR_S4_DATA_URUN_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_TXEOL_MSB 		 MAC_DMA_IMR_P_TXEOL_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_TXEOL_LSB 		 MAC_DMA_IMR_P_TXEOL_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_TXEOL_MASK 		 MAC_DMA_IMR_P_TXEOL_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_TXEOL_GET(x) 		 MAC_DMA_IMR_P_TXEOL_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_TXEOL_SET(x) 		 MAC_DMA_IMR_P_TXEOL_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_TXEOL_RESET 		 MAC_DMA_IMR_P_TXEOL_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_TXNOFR_MSB 		 MAC_DMA_IMR_P_TXNOFR_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_TXNOFR_LSB 		 MAC_DMA_IMR_P_TXNOFR_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_TXNOFR_MASK 		 MAC_DMA_IMR_P_TXNOFR_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_TXNOFR_GET(x) 		 MAC_DMA_IMR_P_TXNOFR_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_TXNOFR_SET(x) 		 MAC_DMA_IMR_P_TXNOFR_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_P_TXNOFR_RESET 		 MAC_DMA_IMR_P_TXNOFR_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_TXERR_MSB 		 MAC_DMA_IMR_P_TXERR_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_TXERR_LSB 		 MAC_DMA_IMR_P_TXERR_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_TXERR_MASK 		 MAC_DMA_IMR_P_TXERR_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_TXERR_GET(x) 		 MAC_DMA_IMR_P_TXERR_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_TXERR_SET(x) 		 MAC_DMA_IMR_P_TXERR_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_P_TXERR_RESET 		 MAC_DMA_IMR_P_TXERR_RESET
#define MAC_DMA_IMR_P_BTINT_MSB 		 WIFICMN_IMR_P_WIFI_COEX_MSB
#define MAC_DMA_IMR_P_BTINT_LSB 		 WIFICMN_IMR_P_WIFI_COEX_LSB
#define MAC_DMA_IMR_P_BTINT_MASK 		 WIFICMN_IMR_P_WIFI_COEX_MASK
#define MAC_DMA_IMR_P_BTINT_GET(x) 		 WIFICMN_IMR_P_WIFI_COEX_GET(x)
#define MAC_DMA_IMR_P_BTINT_SET(x) 		 WIFICMN_IMR_P_WIFI_COEX_SET(x)
#define MAC_DMA_IMR_P_BTINT_RESET 		 WIFICMN_IMR_P_WIFI_COEX_RESET
#define MAC_DMA_IMR_P_TX_DMA_ERR_MSB 		 MCMN_IMR_P_TXDMA_MSB
#define MAC_DMA_IMR_P_TX_DMA_ERR_LSB 		 MCMN_IMR_P_TXDMA_LSB
#define MAC_DMA_IMR_P_TX_DMA_ERR_MASK 		 MCMN_IMR_P_TXDMA_MASK
#define MAC_DMA_IMR_P_TX_DMA_ERR_GET(x) 		 MCMN_IMR_P_TXDMA_GET(x)
#define MAC_DMA_IMR_P_TX_DMA_ERR_SET(x) 		 MCMN_IMR_P_TXDMA_SET(x)
#define MAC_DMA_IMR_P_TX_DMA_ERR_RESET 		 MCMN_IMR_P_TXDMA_RESET
#define MAC_DMA_IMR_P_RXORN_MSB 		 MCMN_IMR_S5_RX_OVFL_MSB
#define MAC_DMA_IMR_P_RXORN_LSB 		 MCMN_IMR_S5_RX_OVFL_LSB
#define MAC_DMA_IMR_P_RXORN_MASK 		 MCMN_IMR_S5_RX_OVFL_MASK
#define MAC_DMA_IMR_P_RXORN_GET(x) 		 MCMN_IMR_S5_RX_OVFL_GET(x)
#define MAC_DMA_IMR_P_RXORN_SET(x) 		 MCMN_IMR_S5_RX_OVFL_SET(x)
#define MAC_DMA_IMR_P_RXORN_RESET 		 MCMN_IMR_S5_RX_OVFL_RESET
#define MAC_DMA_IMR_P_RX_DMA_ERR_MSB 		 MCMN_IMR_P_RXDMA_MSB
#define MAC_DMA_IMR_P_RX_DMA_ERR_LSB 		 MCMN_IMR_P_RXDMA_LSB
#define MAC_DMA_IMR_P_RX_DMA_ERR_MASK 		 MCMN_IMR_P_RXDMA_MASK
#define MAC_DMA_IMR_P_RX_DMA_ERR_GET(x) 		 MCMN_IMR_P_RXDMA_GET(x)
#define MAC_DMA_IMR_P_RX_DMA_ERR_SET(x) 		 MCMN_IMR_P_RXDMA_SET(x)
#define MAC_DMA_IMR_P_RX_DMA_ERR_RESET 		 MCMN_IMR_P_RXDMA_RESET
#define MAC_DMA_IMR_P_RX_DMA_RING_LWM_MSB 		 MCMN_IMR_S3_RXDMA_RNG_LWM_MSB
#define MAC_DMA_IMR_P_RX_DMA_RING_LWM_LSB 		 MCMN_IMR_S3_RXDMA_RNG_LWM_LSB
#define MAC_DMA_IMR_P_RX_DMA_RING_LWM_MASK 		 MCMN_IMR_S3_RXDMA_RNG_LWM_MASK
#define MAC_DMA_IMR_P_RX_DMA_RING_LWM_GET(x) 		 MCMN_IMR_S3_RXDMA_RNG_LWM_GET(x)
#define MAC_DMA_IMR_P_RX_DMA_RING_LWM_SET(x) 		 MCMN_IMR_S3_RXDMA_RNG_LWM_SET(x)
#define MAC_DMA_IMR_P_RX_DMA_RING_LWM_RESET 		 MCMN_IMR_S3_RXDMA_RNG_LWM_RESET
// Reason:Obsolete: Use MCMN_IMR_P or WIFICMN_IMR_P 	 #define MAC_DMA_IMR_P_ADDRESS 		 MAC_DMA_IMR_P_ADDRESS
// Reason:Obsolete: Use MCMN_IMR_P or WIFICMN_IMR_P 	 #define MAC_DMA_IMR_P_OFFSET 		 MAC_DMA_IMR_P_OFFSET
// SW modifiable bits
// Reason:Obsolete: Use MCMN_IMR_P or WIFICMN_IMR_P 	 #define MAC_DMA_IMR_P_SW_MASK 		 MAC_DMA_IMR_P_SW_MASK
// bits defined at reset
// Reason:Obsolete: Use MCMN_IMR_P or WIFICMN_IMR_P 	 #define MAC_DMA_IMR_P_RSTMASK 		 MAC_DMA_IMR_P_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: Use MCMN_IMR_P or WIFICMN_IMR_P 	 #define MAC_DMA_IMR_P_RESET 		 MAC_DMA_IMR_P_RESET
// Reason:Obsolete: Use MCMN_IMR_P or WIFICMN_IMR_P 	 #define MAC_DMA_IMR_P_RESET 		 MAC_DMA_IMR_P_RESET

// 32'h00a4 (MAC_DMA_TXRX_IMR)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_HP_MSB 		 MAC_DMA_TXRX_IMR_RXOK_HP_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_HP_LSB 		 MAC_DMA_TXRX_IMR_RXOK_HP_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_HP_MASK 		 MAC_DMA_TXRX_IMR_RXOK_HP_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_HP_GET(x) 		 MAC_DMA_TXRX_IMR_RXOK_HP_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_HP_SET(x) 		 MAC_DMA_TXRX_IMR_RXOK_HP_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_HP_RESET 		 MAC_DMA_TXRX_IMR_RXOK_HP_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_PPDU_MSB 		 MAC_DMA_TXRX_IMR_RXOK_PPDU_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_PPDU_LSB 		 MAC_DMA_TXRX_IMR_RXOK_PPDU_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_PPDU_MASK 		 MAC_DMA_TXRX_IMR_RXOK_PPDU_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_PPDU_GET(x) 		 MAC_DMA_TXRX_IMR_RXOK_PPDU_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_PPDU_SET(x) 		 MAC_DMA_TXRX_IMR_RXOK_PPDU_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_PPDU_RESET 		 MAC_DMA_TXRX_IMR_RXOK_PPDU_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_MPDU_MSB 		 MAC_DMA_TXRX_IMR_RXOK_MPDU_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_MPDU_LSB 		 MAC_DMA_TXRX_IMR_RXOK_MPDU_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_MPDU_MASK 		 MAC_DMA_TXRX_IMR_RXOK_MPDU_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_MPDU_GET(x) 		 MAC_DMA_TXRX_IMR_RXOK_MPDU_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_MPDU_SET(x) 		 MAC_DMA_TXRX_IMR_RXOK_MPDU_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_MPDU_RESET 		 MAC_DMA_TXRX_IMR_RXOK_MPDU_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_MSDU_MSB 		 MAC_DMA_TXRX_IMR_RXOK_MSDU_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_MSDU_LSB 		 MAC_DMA_TXRX_IMR_RXOK_MSDU_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_MSDU_MASK 		 MAC_DMA_TXRX_IMR_RXOK_MSDU_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_MSDU_GET(x) 		 MAC_DMA_TXRX_IMR_RXOK_MSDU_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_MSDU_SET(x) 		 MAC_DMA_TXRX_IMR_RXOK_MSDU_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RXOK_MSDU_RESET 		 MAC_DMA_TXRX_IMR_RXOK_MSDU_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_TXOK_MSB 		 MAC_DMA_TXRX_IMR_TXOK_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_TXOK_LSB 		 MAC_DMA_TXRX_IMR_TXOK_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_TXOK_MASK 		 MAC_DMA_TXRX_IMR_TXOK_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_TXOK_GET(x) 		 MAC_DMA_TXRX_IMR_TXOK_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_TXOK_SET(x) 		 MAC_DMA_TXRX_IMR_TXOK_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_TXOK_RESET 		 MAC_DMA_TXRX_IMR_TXOK_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_ADDRESS 		 MAC_DMA_TXRX_IMR_ADDRESS
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_OFFSET 		 MAC_DMA_TXRX_IMR_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_SW_MASK 		 MAC_DMA_TXRX_IMR_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RSTMASK 		 MAC_DMA_TXRX_IMR_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_0(rx), wmac_wcpu_intr_1(uapsd), wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_TXRX_IMR_RESET 		 MAC_DMA_TXRX_IMR_RESET

// 32'h00a8 (MAC_DMA_IMR_S1)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RSVD_2_MSB 		 MAC_DMA_IMR_S1_RSVD_2_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RSVD_2_LSB 		 MAC_DMA_IMR_S1_RSVD_2_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RSVD_2_MASK 		 MAC_DMA_IMR_S1_RSVD_2_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RSVD_2_GET(x) 		 MAC_DMA_IMR_S1_RSVD_2_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RSVD_2_SET(x) 		 MAC_DMA_IMR_S1_RSVD_2_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RSVD_2_RESET 		 MAC_DMA_IMR_S1_RSVD_2_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_TXEOL_MSB 		 MAC_DMA_IMR_S1_TXEOL_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_TXEOL_LSB 		 MAC_DMA_IMR_S1_TXEOL_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_TXEOL_MASK 		 MAC_DMA_IMR_S1_TXEOL_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_TXEOL_GET(x) 		 MAC_DMA_IMR_S1_TXEOL_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_TXEOL_SET(x) 		 MAC_DMA_IMR_S1_TXEOL_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_TXEOL_RESET 		 MAC_DMA_IMR_S1_TXEOL_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RSVD_1_MSB 		 MAC_DMA_IMR_S1_RSVD_1_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RSVD_1_LSB 		 MAC_DMA_IMR_S1_RSVD_1_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RSVD_1_MASK 		 MAC_DMA_IMR_S1_RSVD_1_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RSVD_1_GET(x) 		 MAC_DMA_IMR_S1_RSVD_1_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RSVD_1_SET(x) 		 MAC_DMA_IMR_S1_RSVD_1_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RSVD_1_RESET 		 MAC_DMA_IMR_S1_RSVD_1_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_TXERR_MSB 		 MAC_DMA_IMR_S1_TXERR_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_TXERR_LSB 		 MAC_DMA_IMR_S1_TXERR_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_TXERR_MASK 		 MAC_DMA_IMR_S1_TXERR_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_TXERR_GET(x) 		 MAC_DMA_IMR_S1_TXERR_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_TXERR_SET(x) 		 MAC_DMA_IMR_S1_TXERR_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_TXERR_RESET 		 MAC_DMA_IMR_S1_TXERR_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_ADDRESS 		 MAC_DMA_IMR_S1_ADDRESS
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_OFFSET 		 MAC_DMA_IMR_S1_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_SW_MASK 		 MAC_DMA_IMR_S1_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RSTMASK 		 MAC_DMA_IMR_S1_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_IMR_S1_RESET 		 MAC_DMA_IMR_S1_RESET

// 32'h00ac (MAC_DMA_IMR_S2)
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_IMR_S2_TBTT_TIME_STA_0_MSB 		 MAC_DMA_IMR_S2_TBTT_TIME_STA_0_MSB
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_IMR_S2_TBTT_TIME_STA_0_LSB 		 MAC_DMA_IMR_S2_TBTT_TIME_STA_0_LSB
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_IMR_S2_TBTT_TIME_STA_0_MASK 		 MAC_DMA_IMR_S2_TBTT_TIME_STA_0_MASK
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_IMR_S2_TBTT_TIME_STA_0_GET(x) 		 MAC_DMA_IMR_S2_TBTT_TIME_STA_0_GET(x)
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_IMR_S2_TBTT_TIME_STA_0_SET(x) 		 MAC_DMA_IMR_S2_TBTT_TIME_STA_0_SET(x)
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_IMR_S2_TBTT_TIME_STA_0_RESET 		 MAC_DMA_IMR_S2_TBTT_TIME_STA_0_RESET
#define MAC_DMA_IMR_S2_TSFOOR_STA_0_MSB 		 WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_MSB
#define MAC_DMA_IMR_S2_TSFOOR_STA_0_LSB 		 WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_LSB
#define MAC_DMA_IMR_S2_TSFOOR_STA_0_MASK 		 WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_MASK
#define MAC_DMA_IMR_S2_TSFOOR_STA_0_GET(x) 		 WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_GET(x)
#define MAC_DMA_IMR_S2_TSFOOR_STA_0_SET(x) 		 WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_SET(x)
#define MAC_DMA_IMR_S2_TSFOOR_STA_0_RESET 		 WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_RESET
#define MAC_DMA_IMR_S2_DTIM_STA_0_MSB 		 MCMN_IMR_S5_RX_DTIM_MSB
#define MAC_DMA_IMR_S2_DTIM_STA_0_LSB 		 MCMN_IMR_S5_RX_DTIM_LSB
#define MAC_DMA_IMR_S2_DTIM_STA_0_MASK 		 MCMN_IMR_S5_RX_DTIM_MASK
#define MAC_DMA_IMR_S2_DTIM_STA_0_GET(x) 		 MCMN_IMR_S5_RX_DTIM_GET(x)
#define MAC_DMA_IMR_S2_DTIM_STA_0_SET(x) 		 MCMN_IMR_S5_RX_DTIM_SET(x)
#define MAC_DMA_IMR_S2_DTIM_STA_0_RESET 		 MCMN_IMR_S5_RX_DTIM_RESET
#define MAC_DMA_IMR_S2_CABTO_STA_0_MSB 		 WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_MSB
#define MAC_DMA_IMR_S2_CABTO_STA_0_LSB 		 WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_LSB
#define MAC_DMA_IMR_S2_CABTO_STA_0_MASK 		 WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_MASK
#define MAC_DMA_IMR_S2_CABTO_STA_0_GET(x) 		 WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_GET(x)
#define MAC_DMA_IMR_S2_CABTO_STA_0_SET(x) 		 WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_SET(x)
#define MAC_DMA_IMR_S2_CABTO_STA_0_RESET 		 WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_RESET
#define MAC_DMA_IMR_S2_BCNTO_STA_0_MSB 		 WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_MSB
#define MAC_DMA_IMR_S2_BCNTO_STA_0_LSB 		 WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_LSB
#define MAC_DMA_IMR_S2_BCNTO_STA_0_MASK 		 WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_MASK
#define MAC_DMA_IMR_S2_BCNTO_STA_0_GET(x) 		 WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_GET(x)
#define MAC_DMA_IMR_S2_BCNTO_STA_0_SET(x) 		 WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_SET(x)
#define MAC_DMA_IMR_S2_BCNTO_STA_0_RESET 		 WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_RESET
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_0_MSB 		 WIFICMN_IMR_S0_PCU_DTIM_SYNC_MSB
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_0_LSB 		 WIFICMN_IMR_S0_PCU_DTIM_SYNC_LSB
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_0_MASK 		 WIFICMN_IMR_S0_PCU_DTIM_SYNC_MASK
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_0_GET(x) 		 WIFICMN_IMR_S0_PCU_DTIM_SYNC_GET(x)
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_0_SET(x) 		 WIFICMN_IMR_S0_PCU_DTIM_SYNC_SET(x)
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_0_RESET 		 WIFICMN_IMR_S0_PCU_DTIM_SYNC_RESET
#define MAC_DMA_IMR_S2_CABEND_STA_0_MSB 		 WIFICMN_IMR_S0_PCU_CAB_NO_MORE_MSB
#define MAC_DMA_IMR_S2_CABEND_STA_0_LSB 		 WIFICMN_IMR_S0_PCU_CAB_NO_MORE_LSB
#define MAC_DMA_IMR_S2_CABEND_STA_0_MASK 		 WIFICMN_IMR_S0_PCU_CAB_NO_MORE_MASK
#define MAC_DMA_IMR_S2_CABEND_STA_0_GET(x) 		 WIFICMN_IMR_S0_PCU_CAB_NO_MORE_GET(x)
#define MAC_DMA_IMR_S2_CABEND_STA_0_SET(x) 		 WIFICMN_IMR_S0_PCU_CAB_NO_MORE_SET(x)
#define MAC_DMA_IMR_S2_CABEND_STA_0_RESET 		 WIFICMN_IMR_S0_PCU_CAB_NO_MORE_RESET
#define MAC_DMA_IMR_S2_TIM_STA_0_MSB 		 MCMN_IMR_S5_RX_TIM_MSB
#define MAC_DMA_IMR_S2_TIM_STA_0_LSB 		 MCMN_IMR_S5_RX_TIM_LSB
#define MAC_DMA_IMR_S2_TIM_STA_0_MASK 		 MCMN_IMR_S5_RX_TIM_MASK
#define MAC_DMA_IMR_S2_TIM_STA_0_GET(x) 		 MCMN_IMR_S5_RX_TIM_GET(x)
#define MAC_DMA_IMR_S2_TIM_STA_0_SET(x) 		 MCMN_IMR_S5_RX_TIM_SET(x)
#define MAC_DMA_IMR_S2_TIM_STA_0_RESET 		 MCMN_IMR_S5_RX_TIM_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S2_GTT_MSB 		 MAC_DMA_IMR_S2_GTT_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S2_GTT_LSB 		 MAC_DMA_IMR_S2_GTT_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S2_GTT_MASK 		 MAC_DMA_IMR_S2_GTT_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S2_GTT_GET(x) 		 MAC_DMA_IMR_S2_GTT_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S2_GTT_SET(x) 		 MAC_DMA_IMR_S2_GTT_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S2_GTT_RESET 		 MAC_DMA_IMR_S2_GTT_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S2_CST_MSB 		 MAC_DMA_IMR_S2_CST_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S2_CST_LSB 		 MAC_DMA_IMR_S2_CST_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S2_CST_MASK 		 MAC_DMA_IMR_S2_CST_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S2_CST_GET(x) 		 MAC_DMA_IMR_S2_CST_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S2_CST_SET(x) 		 MAC_DMA_IMR_S2_CST_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S2_CST_RESET 		 MAC_DMA_IMR_S2_CST_RESET
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_IMR_S2_TBTT_TIME_STA_1_MSB 		 MAC_DMA_IMR_S2_TBTT_TIME_STA_1_MSB
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_IMR_S2_TBTT_TIME_STA_1_LSB 		 MAC_DMA_IMR_S2_TBTT_TIME_STA_1_LSB
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_IMR_S2_TBTT_TIME_STA_1_MASK 		 MAC_DMA_IMR_S2_TBTT_TIME_STA_1_MASK
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_IMR_S2_TBTT_TIME_STA_1_GET(x) 		 MAC_DMA_IMR_S2_TBTT_TIME_STA_1_GET(x)
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_IMR_S2_TBTT_TIME_STA_1_SET(x) 		 MAC_DMA_IMR_S2_TBTT_TIME_STA_1_SET(x)
// Reason:TODO: Just confirm that this is supported by PCU_GEN_TIMER_TRIGGER? 	 #define MAC_DMA_IMR_S2_TBTT_TIME_STA_1_RESET 		 MAC_DMA_IMR_S2_TBTT_TIME_STA_1_RESET
#define MAC_DMA_IMR_S2_TSFOOR_STA_1_MSB 		 WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_MSB
#define MAC_DMA_IMR_S2_TSFOOR_STA_1_LSB 		 WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_LSB
#define MAC_DMA_IMR_S2_TSFOOR_STA_1_MASK 		 WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_MASK
#define MAC_DMA_IMR_S2_TSFOOR_STA_1_GET(x) 		 WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_GET(x)
#define MAC_DMA_IMR_S2_TSFOOR_STA_1_SET(x) 		 WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_SET(x)
#define MAC_DMA_IMR_S2_TSFOOR_STA_1_RESET 		 WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_RESET
#define MAC_DMA_IMR_S2_DTIM_STA_1_MSB 		 MCMN_IMR_S5_RX_DTIM_MSB
#define MAC_DMA_IMR_S2_DTIM_STA_1_LSB 		 MCMN_IMR_S5_RX_DTIM_LSB
#define MAC_DMA_IMR_S2_DTIM_STA_1_MASK 		 MCMN_IMR_S5_RX_DTIM_MASK
#define MAC_DMA_IMR_S2_DTIM_STA_1_GET(x) 		 MCMN_IMR_S5_RX_DTIM_GET(x)
#define MAC_DMA_IMR_S2_DTIM_STA_1_SET(x) 		 MCMN_IMR_S5_RX_DTIM_SET(x)
#define MAC_DMA_IMR_S2_DTIM_STA_1_RESET 		 MCMN_IMR_S5_RX_DTIM_RESET
#define MAC_DMA_IMR_S2_CABTO_STA_1_MSB 		 WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_MSB
#define MAC_DMA_IMR_S2_CABTO_STA_1_LSB 		 WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_LSB
#define MAC_DMA_IMR_S2_CABTO_STA_1_MASK 		 WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_MASK
#define MAC_DMA_IMR_S2_CABTO_STA_1_GET(x) 		 WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_GET(x)
#define MAC_DMA_IMR_S2_CABTO_STA_1_SET(x) 		 WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_SET(x)
#define MAC_DMA_IMR_S2_CABTO_STA_1_RESET 		 WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_RESET
#define MAC_DMA_IMR_S2_BCNTO_STA_1_MSB 		 WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_MSB
#define MAC_DMA_IMR_S2_BCNTO_STA_1_LSB 		 WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_LSB
#define MAC_DMA_IMR_S2_BCNTO_STA_1_MASK 		 WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_MASK
#define MAC_DMA_IMR_S2_BCNTO_STA_1_GET(x) 		 WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_GET(x)
#define MAC_DMA_IMR_S2_BCNTO_STA_1_SET(x) 		 WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_SET(x)
#define MAC_DMA_IMR_S2_BCNTO_STA_1_RESET 		 WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_RESET
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_1_MSB 		 WIFICMN_IMR_S0_PCU_DTIM_SYNC_MSB
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_1_LSB 		 WIFICMN_IMR_S0_PCU_DTIM_SYNC_LSB
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_1_MASK 		 WIFICMN_IMR_S0_PCU_DTIM_SYNC_MASK
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_1_GET(x) 		 WIFICMN_IMR_S0_PCU_DTIM_SYNC_GET(x)
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_1_SET(x) 		 WIFICMN_IMR_S0_PCU_DTIM_SYNC_SET(x)
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_1_RESET 		 WIFICMN_IMR_S0_PCU_DTIM_SYNC_RESET
#define MAC_DMA_IMR_S2_CABEND_STA_1_MSB 		 WIFICMN_IMR_S0_PCU_CAB_NO_MORE_MSB
#define MAC_DMA_IMR_S2_CABEND_STA_1_LSB 		 WIFICMN_IMR_S0_PCU_CAB_NO_MORE_LSB
#define MAC_DMA_IMR_S2_CABEND_STA_1_MASK 		 WIFICMN_IMR_S0_PCU_CAB_NO_MORE_MASK
#define MAC_DMA_IMR_S2_CABEND_STA_1_GET(x) 		 WIFICMN_IMR_S0_PCU_CAB_NO_MORE_GET(x)
#define MAC_DMA_IMR_S2_CABEND_STA_1_SET(x) 		 WIFICMN_IMR_S0_PCU_CAB_NO_MORE_SET(x)
#define MAC_DMA_IMR_S2_CABEND_STA_1_RESET 		 WIFICMN_IMR_S0_PCU_CAB_NO_MORE_RESET
#define MAC_DMA_IMR_S2_TIM_STA_1_MSB 		 MCMN_IMR_S5_RX_TIM_MSB
#define MAC_DMA_IMR_S2_TIM_STA_1_LSB 		 MCMN_IMR_S5_RX_TIM_LSB
#define MAC_DMA_IMR_S2_TIM_STA_1_MASK 		 MCMN_IMR_S5_RX_TIM_MASK
#define MAC_DMA_IMR_S2_TIM_STA_1_GET(x) 		 MCMN_IMR_S5_RX_TIM_GET(x)
#define MAC_DMA_IMR_S2_TIM_STA_1_SET(x) 		 MCMN_IMR_S5_RX_TIM_SET(x)
#define MAC_DMA_IMR_S2_TIM_STA_1_RESET 		 MCMN_IMR_S5_RX_TIM_RESET
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_MSB 		 MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_MSB
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_LSB 		 MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_LSB
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_MASK 		 MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_MASK
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_GET(x) 		 MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_SET(x) 		 MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_RESET 		 MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_RESET
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_MSB 		 MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_MSB
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_LSB 		 MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_LSB
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_MASK 		 MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_MASK
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_GET(x) 		 MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_SET(x) 		 MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_RESET 		 MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_RESET
#define MAC_DMA_IMR_S2_TXURN_MSB 		 MCMN_IMR_S4_DATA_URUN_MSB
#define MAC_DMA_IMR_S2_TXURN_LSB 		 MCMN_IMR_S4_DATA_URUN_LSB
#define MAC_DMA_IMR_S2_TXURN_MASK 		 MCMN_IMR_S4_DATA_URUN_MASK
#define MAC_DMA_IMR_S2_TXURN_GET(x) 		 MCMN_IMR_S4_DATA_URUN_GET(x)
#define MAC_DMA_IMR_S2_TXURN_SET(x) 		 MCMN_IMR_S4_DATA_URUN_SET(x)
#define MAC_DMA_IMR_S2_TXURN_RESET 		 MCMN_IMR_S4_DATA_URUN_RESET
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_ADDRESS 		 MAC_DMA_IMR_S2_ADDRESS
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_OFFSET 		 MAC_DMA_IMR_S2_OFFSET
// SW modifiable bits
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_SW_MASK 		 MAC_DMA_IMR_S2_SW_MASK
// bits defined at reset
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_RSTMASK 		 MAC_DMA_IMR_S2_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S2_RESET 		 MAC_DMA_IMR_S2_RESET

// 32'h00b0 (MAC_DMA_IMR_S3)
#define MAC_DMA_IMR_S3_BMISS_STA_1_MSB 		 MCMN_IMR_S5_BCON_MISS_MSB
#define MAC_DMA_IMR_S3_BMISS_STA_1_LSB 		 MCMN_IMR_S5_BCON_MISS_LSB
#define MAC_DMA_IMR_S3_BMISS_STA_1_MASK 		 MCMN_IMR_S5_BCON_MISS_MASK
#define MAC_DMA_IMR_S3_BMISS_STA_1_GET(x) 		 MCMN_IMR_S5_BCON_MISS_GET(x)
#define MAC_DMA_IMR_S3_BMISS_STA_1_SET(x) 		 MCMN_IMR_S5_BCON_MISS_SET(x)
#define MAC_DMA_IMR_S3_BMISS_STA_1_RESET 		 MCMN_IMR_S5_BCON_MISS_RESET
#define MAC_DMA_IMR_S3_BMISS_STA_0_MSB 		 MCMN_IMR_S5_BCON_MISS_MSB
#define MAC_DMA_IMR_S3_BMISS_STA_0_LSB 		 MCMN_IMR_S5_BCON_MISS_LSB
#define MAC_DMA_IMR_S3_BMISS_STA_0_MASK 		 MCMN_IMR_S5_BCON_MISS_MASK
#define MAC_DMA_IMR_S3_BMISS_STA_0_GET(x) 		 MCMN_IMR_S5_BCON_MISS_GET(x)
#define MAC_DMA_IMR_S3_BMISS_STA_0_SET(x) 		 MCMN_IMR_S5_BCON_MISS_SET(x)
#define MAC_DMA_IMR_S3_BMISS_STA_0_RESET 		 MCMN_IMR_S5_BCON_MISS_RESET
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_MSB 		 MCMN_IMR_S5_RSSI_LOW_MSB
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_LSB 		 MCMN_IMR_S5_RSSI_LOW_LSB
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_MASK 		 MCMN_IMR_S5_RSSI_LOW_MASK
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_GET(x) 		 MCMN_IMR_S5_RSSI_LOW_GET(x)
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_SET(x) 		 MCMN_IMR_S5_RSSI_LOW_SET(x)
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_RESET 		 MCMN_IMR_S5_RSSI_LOW_RESET
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_MSB 		 MCMN_IMR_S5_RSSI_HIGH_MSB
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_LSB 		 MCMN_IMR_S5_RSSI_HIGH_LSB
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_MASK 		 MCMN_IMR_S5_RSSI_HIGH_MASK
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_GET(x) 		 MCMN_IMR_S5_RSSI_HIGH_GET(x)
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_SET(x) 		 MCMN_IMR_S5_RSSI_HIGH_SET(x)
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_RESET 		 MCMN_IMR_S5_RSSI_HIGH_RESET
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_MSB 		 MCMN_IMR_S5_RSSI_LOW_MSB
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_LSB 		 MCMN_IMR_S5_RSSI_LOW_LSB
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_MASK 		 MCMN_IMR_S5_RSSI_LOW_MASK
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_GET(x) 		 MCMN_IMR_S5_RSSI_LOW_GET(x)
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_SET(x) 		 MCMN_IMR_S5_RSSI_LOW_SET(x)
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_RESET 		 MCMN_IMR_S5_RSSI_LOW_RESET
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_MSB 		 MCMN_IMR_S5_RSSI_HIGH_MSB
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_LSB 		 MCMN_IMR_S5_RSSI_HIGH_LSB
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_MASK 		 MCMN_IMR_S5_RSSI_HIGH_MASK
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_GET(x) 		 MCMN_IMR_S5_RSSI_HIGH_GET(x)
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_SET(x) 		 MCMN_IMR_S5_RSSI_HIGH_SET(x)
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_RESET 		 MCMN_IMR_S5_RSSI_HIGH_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S3_QCBRURN_MSB 		 MAC_DMA_IMR_S3_QCBRURN_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S3_QCBRURN_LSB 		 MAC_DMA_IMR_S3_QCBRURN_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S3_QCBRURN_MASK 		 MAC_DMA_IMR_S3_QCBRURN_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S3_QCBRURN_GET(x) 		 MAC_DMA_IMR_S3_QCBRURN_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S3_QCBRURN_SET(x) 		 MAC_DMA_IMR_S3_QCBRURN_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S3_QCBRURN_RESET 		 MAC_DMA_IMR_S3_QCBRURN_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_MSB 		 MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_LSB 		 MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_MASK 		 MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_GET(x) 		 MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_SET(x) 		 MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_RESET 		 MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_RESET
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_MSB 		 MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_MSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_LSB 		 MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_LSB
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_MASK 		 MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_MASK
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_GET(x) 		 MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_GET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_SET(x) 		 MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_SET(x)
// Reason:Obsolete even in Peregrine 	 #define MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_RESET 		 MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S3_QCBROVF_MSB 		 MAC_DMA_IMR_S3_QCBROVF_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S3_QCBROVF_LSB 		 MAC_DMA_IMR_S3_QCBROVF_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S3_QCBROVF_MASK 		 MAC_DMA_IMR_S3_QCBROVF_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S3_QCBROVF_GET(x) 		 MAC_DMA_IMR_S3_QCBROVF_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S3_QCBROVF_SET(x) 		 MAC_DMA_IMR_S3_QCBROVF_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S3_QCBROVF_RESET 		 MAC_DMA_IMR_S3_QCBROVF_RESET
// Reason:Obsolete 	 #define MAC_DMA_IMR_S3_ADDRESS 		 MAC_DMA_IMR_S3_ADDRESS
// Reason:Obsolete 	 #define MAC_DMA_IMR_S3_OFFSET 		 MAC_DMA_IMR_S3_OFFSET
// SW modifiable bits
// Reason:Obsolete 	 #define MAC_DMA_IMR_S3_SW_MASK 		 MAC_DMA_IMR_S3_SW_MASK
// bits defined at reset
// Reason:Obsolete 	 #define MAC_DMA_IMR_S3_RSTMASK 		 MAC_DMA_IMR_S3_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S3_RESET 		 MAC_DMA_IMR_S3_RESET

// 32'h00b4 (MAC_DMA_IMR_S4)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RSVD_2_MSB 		 MAC_DMA_IMR_S4_RSVD_2_MSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RSVD_2_LSB 		 MAC_DMA_IMR_S4_RSVD_2_LSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RSVD_2_MASK 		 MAC_DMA_IMR_S4_RSVD_2_MASK
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RSVD_2_GET(x) 		 MAC_DMA_IMR_S4_RSVD_2_GET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RSVD_2_SET(x) 		 MAC_DMA_IMR_S4_RSVD_2_SET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RSVD_2_RESET 		 MAC_DMA_IMR_S4_RSVD_2_RESET
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_TXDP_FIFO_OVF_MSB 		 MAC_DMA_IMR_S4_TXDP_FIFO_OVF_MSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_TXDP_FIFO_OVF_LSB 		 MAC_DMA_IMR_S4_TXDP_FIFO_OVF_LSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_TXDP_FIFO_OVF_MASK 		 MAC_DMA_IMR_S4_TXDP_FIFO_OVF_MASK
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_TXDP_FIFO_OVF_GET(x) 		 MAC_DMA_IMR_S4_TXDP_FIFO_OVF_GET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_TXDP_FIFO_OVF_SET(x) 		 MAC_DMA_IMR_S4_TXDP_FIFO_OVF_SET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_TXDP_FIFO_OVF_RESET 		 MAC_DMA_IMR_S4_TXDP_FIFO_OVF_RESET
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RSVD_1_MSB 		 MAC_DMA_IMR_S4_RSVD_1_MSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RSVD_1_LSB 		 MAC_DMA_IMR_S4_RSVD_1_LSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RSVD_1_MASK 		 MAC_DMA_IMR_S4_RSVD_1_MASK
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RSVD_1_GET(x) 		 MAC_DMA_IMR_S4_RSVD_1_GET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RSVD_1_SET(x) 		 MAC_DMA_IMR_S4_RSVD_1_SET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RSVD_1_RESET 		 MAC_DMA_IMR_S4_RSVD_1_RESET
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_QTRIG_MSB 		 MAC_DMA_IMR_S4_QTRIG_MSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_QTRIG_LSB 		 MAC_DMA_IMR_S4_QTRIG_LSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_QTRIG_MASK 		 MAC_DMA_IMR_S4_QTRIG_MASK
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_QTRIG_GET(x) 		 MAC_DMA_IMR_S4_QTRIG_GET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_QTRIG_SET(x) 		 MAC_DMA_IMR_S4_QTRIG_SET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_QTRIG_RESET 		 MAC_DMA_IMR_S4_QTRIG_RESET
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_ADDRESS 		 MAC_DMA_IMR_S4_ADDRESS
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_OFFSET 		 MAC_DMA_IMR_S4_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_SW_MASK 		 MAC_DMA_IMR_S4_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RSTMASK 		 MAC_DMA_IMR_S4_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_IMR_S4_RESET 		 MAC_DMA_IMR_S4_RESET

// 32'h00b8 (MAC_DMA_IMR_S5)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_MSB 		 WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_MSB
#define MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_LSB 		 WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_LSB
#define MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_MASK 		 WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_MASK
#define MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_GET(x) 		 WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_GET(x)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_SET(x) 		 WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_SET(x)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_RESET 		 WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_RESET
#define MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_MSB 		 WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_MSB
#define MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_LSB 		 WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_LSB
#define MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_MASK 		 WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_MASK
#define MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_GET(x) 		 WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_GET(x)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_SET(x) 		 WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_SET(x)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_RESET 		 WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_RESET
#define MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_MSB 		 WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_MSB
#define MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_LSB 		 WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_LSB
#define MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_MASK 		 WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_MASK
#define MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_GET(x) 		 WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_GET(x)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_SET(x) 		 WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_SET(x)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_RESET 		 WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_RESET
// Reason:Obsolete 	 #define MAC_DMA_IMR_S5_ADDRESS 		 MAC_DMA_IMR_S5_ADDRESS
// Reason:Obsolete 	 #define MAC_DMA_IMR_S5_OFFSET 		 MAC_DMA_IMR_S5_OFFSET
// SW modifiable bits
// Reason:Obsolete 	 #define MAC_DMA_IMR_S5_SW_MASK 		 MAC_DMA_IMR_S5_SW_MASK
// bits defined at reset
// Reason:Obsolete 	 #define MAC_DMA_IMR_S5_RSTMASK 		 MAC_DMA_IMR_S5_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S5_RESET 		 MAC_DMA_IMR_S5_RESET

// 32'h00bc (MAC_DMA_IMR_S6)
#define MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_MSB 		 MCMN_IMR_S5_CONFIG_PHY_ERR_MSB
#define MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_LSB 		 MCMN_IMR_S5_CONFIG_PHY_ERR_LSB
#define MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_MASK 		 MCMN_IMR_S5_CONFIG_PHY_ERR_MASK
#define MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_GET(x) 		 MCMN_IMR_S5_CONFIG_PHY_ERR_GET(x)
#define MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_SET(x) 		 MCMN_IMR_S5_CONFIG_PHY_ERR_SET(x)
#define MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_RESET 		 MCMN_IMR_S5_CONFIG_PHY_ERR_RESET
#define MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_MSB 		 MCMN_IMR_S2_UNEX_NUL_PTR_MSB
#define MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_LSB 		 MCMN_IMR_S2_UNEX_NUL_PTR_LSB
#define MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_MASK 		 MCMN_IMR_S2_UNEX_NUL_PTR_MASK
#define MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_GET(x) 		 MCMN_IMR_S2_UNEX_NUL_PTR_GET(x)
#define MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_SET(x) 		 MCMN_IMR_S2_UNEX_NUL_PTR_SET(x)
#define MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_RESET 		 MCMN_IMR_S2_UNEX_NUL_PTR_RESET
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MSB 		 MCMN_IMR_S3_NON_PKT_BUF_MSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_LSB 		 MCMN_IMR_S3_NON_PKT_BUF_LSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MASK 		 MCMN_IMR_S3_NON_PKT_BUF_MASK
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_GET(x) 		 MCMN_IMR_S3_NON_PKT_BUF_GET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_SET(x) 		 MCMN_IMR_S3_NON_PKT_BUF_SET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_RESET 		 MCMN_IMR_S3_NON_PKT_BUF_RESET
#define MAC_DMA_IMR_S6_RX_DMA_RING_LWM_MSB 		 MCMN_IMR_S3_RXDMA_RNG_LWM_MSB
#define MAC_DMA_IMR_S6_RX_DMA_RING_LWM_LSB 		 MCMN_IMR_S3_RXDMA_RNG_LWM_LSB
#define MAC_DMA_IMR_S6_RX_DMA_RING_LWM_MASK 		 MCMN_IMR_S3_RXDMA_RNG_LWM_MASK
#define MAC_DMA_IMR_S6_RX_DMA_RING_LWM_GET(x) 		 MCMN_IMR_S3_RXDMA_RNG_LWM_GET(x)
#define MAC_DMA_IMR_S6_RX_DMA_RING_LWM_SET(x) 		 MCMN_IMR_S3_RXDMA_RNG_LWM_SET(x)
#define MAC_DMA_IMR_S6_RX_DMA_RING_LWM_RESET 		 MCMN_IMR_S3_RXDMA_RNG_LWM_RESET
#define MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_MSB 		 MCMN_IMR_S3_MDAT_TLV_MSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_LSB 		 MCMN_IMR_S3_MDAT_TLV_LSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_MASK 		 MCMN_IMR_S3_MDAT_TLV_MASK
#define MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_GET(x) 		 MCMN_IMR_S3_MDAT_TLV_GET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_SET(x) 		 MCMN_IMR_S3_MDAT_TLV_SET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_RESET 		 MCMN_IMR_S3_MDAT_TLV_RESET
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_MSB 		 MCMN_IMR_S3_NULL_RNG_MSK_MSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_LSB 		 MCMN_IMR_S3_NULL_RNG_MSK_LSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_MASK 		 MCMN_IMR_S3_NULL_RNG_MSK_MASK
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_GET(x) 		 MCMN_IMR_S3_NULL_RNG_MSK_GET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_SET(x) 		 MCMN_IMR_S3_NULL_RNG_MSK_SET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_RESET 		 MCMN_IMR_S3_NULL_RNG_MSK_RESET
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_MSB 		 MCMN_IMR_S3_INVAL_TAG_ID_MSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_LSB 		 MCMN_IMR_S3_INVAL_TAG_ID_LSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_MASK 		 MCMN_IMR_S3_INVAL_TAG_ID_MASK
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_GET(x) 		 MCMN_IMR_S3_INVAL_TAG_ID_GET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_SET(x) 		 MCMN_IMR_S3_INVAL_TAG_ID_SET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_RESET 		 MCMN_IMR_S3_INVAL_TAG_ID_RESET
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_MSB 		 MCMN_IMR_S3_INVAL_TAG_SEG_MSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_LSB 		 MCMN_IMR_S3_INVAL_TAG_SEG_LSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_MASK 		 MCMN_IMR_S3_INVAL_TAG_SEG_MASK
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_GET(x) 		 MCMN_IMR_S3_INVAL_TAG_SEG_GET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_SET(x) 		 MCMN_IMR_S3_INVAL_TAG_SEG_SET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_RESET 		 MCMN_IMR_S3_INVAL_TAG_SEG_RESET
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_MSB 		 MCMN_IMR_S3_TLV_SHORT_MSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_LSB 		 MCMN_IMR_S3_TLV_SHORT_LSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_MASK 		 MCMN_IMR_S3_TLV_SHORT_MASK
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_GET(x) 		 MCMN_IMR_S3_TLV_SHORT_GET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_SET(x) 		 MCMN_IMR_S3_TLV_SHORT_SET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_RESET 		 MCMN_IMR_S3_TLV_SHORT_RESET
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_MSB 		 MCMN_IMR_S3_TLV_FRME_ERR_MSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_LSB 		 MCMN_IMR_S3_TLV_FRME_ERR_LSB
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_MASK 		 MCMN_IMR_S3_TLV_FRME_ERR_MASK
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_GET(x) 		 MCMN_IMR_S3_TLV_FRME_ERR_GET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_SET(x) 		 MCMN_IMR_S3_TLV_FRME_ERR_SET(x)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_RESET 		 MCMN_IMR_S3_TLV_FRME_ERR_RESET
#define MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_MSB 		 WIFICMN_IMR_S2_PTA_BT_PRIORITY_RISE_MSB
#define MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_LSB 		 WIFICMN_IMR_S2_PTA_BT_PRIORITY_RISE_LSB
#define MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_MASK 		 WIFICMN_IMR_S2_PTA_BT_PRIORITY_RISE_MASK
#define MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_GET(x) 		 WIFICMN_IMR_S2_PTA_BT_PRIORITY_RISE_GET(x)
#define MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_SET(x) 		 WIFICMN_IMR_S2_PTA_BT_PRIORITY_RISE_SET(x)
#define MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_RESET 		 WIFICMN_IMR_S2_PTA_BT_PRIORITY_RISE_RESET
#define MAC_DMA_IMR_S6_BT_PRIORITY_RISING_MSB 		 WIFICMN_IMR_S2_PTA_BT_PRIORITY_RISE_MSB
#define MAC_DMA_IMR_S6_BT_PRIORITY_RISING_LSB 		 WIFICMN_IMR_S2_PTA_BT_PRIORITY_RISE_LSB
#define MAC_DMA_IMR_S6_BT_PRIORITY_RISING_MASK 		 WIFICMN_IMR_S2_PTA_BT_PRIORITY_RISE_MASK
#define MAC_DMA_IMR_S6_BT_PRIORITY_RISING_GET(x) 		 WIFICMN_IMR_S2_PTA_BT_PRIORITY_RISE_GET(x)
#define MAC_DMA_IMR_S6_BT_PRIORITY_RISING_SET(x) 		 WIFICMN_IMR_S2_PTA_BT_PRIORITY_RISE_SET(x)
#define MAC_DMA_IMR_S6_BT_PRIORITY_RISING_RESET 		 WIFICMN_IMR_S2_PTA_BT_PRIORITY_RISE_RESET
#define MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_MSB 		 WIFICMN_IMR_S2_PTA_BT_ACTIVE_FALL_MSB
#define MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_LSB 		 WIFICMN_IMR_S2_PTA_BT_ACTIVE_FALL_LSB
#define MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_MASK 		 WIFICMN_IMR_S2_PTA_BT_ACTIVE_FALL_MASK
#define MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_GET(x) 		 WIFICMN_IMR_S2_PTA_BT_ACTIVE_FALL_GET(x)
#define MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_SET(x) 		 WIFICMN_IMR_S2_PTA_BT_ACTIVE_FALL_SET(x)
#define MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_RESET 		 WIFICMN_IMR_S2_PTA_BT_ACTIVE_FALL_RESET
#define MAC_DMA_IMR_S6_BT_ACTIVE_RISING_MSB 		 WIFICMN_IMR_S2_PTA_BT_ACTIVE_RISE_MSB
#define MAC_DMA_IMR_S6_BT_ACTIVE_RISING_LSB 		 WIFICMN_IMR_S2_PTA_BT_ACTIVE_RISE_LSB
#define MAC_DMA_IMR_S6_BT_ACTIVE_RISING_MASK 		 WIFICMN_IMR_S2_PTA_BT_ACTIVE_RISE_MASK
#define MAC_DMA_IMR_S6_BT_ACTIVE_RISING_GET(x) 		 WIFICMN_IMR_S2_PTA_BT_ACTIVE_RISE_GET(x)
#define MAC_DMA_IMR_S6_BT_ACTIVE_RISING_SET(x) 		 WIFICMN_IMR_S2_PTA_BT_ACTIVE_RISE_SET(x)
#define MAC_DMA_IMR_S6_BT_ACTIVE_RISING_RESET 		 WIFICMN_IMR_S2_PTA_BT_ACTIVE_RISE_RESET
#define MAC_DMA_IMR_S6_WL_STOMPED_MSB 		 WIFICMN_IMR_S2_PTA_WL_STOMPED_MSB
#define MAC_DMA_IMR_S6_WL_STOMPED_LSB 		 WIFICMN_IMR_S2_PTA_WL_STOMPED_LSB
#define MAC_DMA_IMR_S6_WL_STOMPED_MASK 		 WIFICMN_IMR_S2_PTA_WL_STOMPED_MASK
#define MAC_DMA_IMR_S6_WL_STOMPED_GET(x) 		 WIFICMN_IMR_S2_PTA_WL_STOMPED_GET(x)
#define MAC_DMA_IMR_S6_WL_STOMPED_SET(x) 		 WIFICMN_IMR_S2_PTA_WL_STOMPED_SET(x)
#define MAC_DMA_IMR_S6_WL_STOMPED_RESET 		 WIFICMN_IMR_S2_PTA_WL_STOMPED_RESET
#define MAC_DMA_IMR_S6_BT_STOMPED_MSB 		 WIFICMN_IMR_S2_PTA_BT_STOMPED_MSB
#define MAC_DMA_IMR_S6_BT_STOMPED_LSB 		 WIFICMN_IMR_S2_PTA_BT_STOMPED_LSB
#define MAC_DMA_IMR_S6_BT_STOMPED_MASK 		 WIFICMN_IMR_S2_PTA_BT_STOMPED_MASK
#define MAC_DMA_IMR_S6_BT_STOMPED_GET(x) 		 WIFICMN_IMR_S2_PTA_BT_STOMPED_GET(x)
#define MAC_DMA_IMR_S6_BT_STOMPED_SET(x) 		 WIFICMN_IMR_S2_PTA_BT_STOMPED_SET(x)
#define MAC_DMA_IMR_S6_BT_STOMPED_RESET 		 WIFICMN_IMR_S2_PTA_BT_STOMPED_RESET
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_MSB 		 WIFICMN_IMR_S2_PTA_BT_LOW_PRTY_FALL_MSB
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_LSB 		 WIFICMN_IMR_S2_PTA_BT_LOW_PRTY_FALL_LSB
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_MASK 		 WIFICMN_IMR_S2_PTA_BT_LOW_PRTY_FALL_MASK
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_GET(x) 		 WIFICMN_IMR_S2_PTA_BT_LOW_PRTY_FALL_GET(x)
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_SET(x) 		 WIFICMN_IMR_S2_PTA_BT_LOW_PRTY_FALL_SET(x)
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_RESET 		 WIFICMN_IMR_S2_PTA_BT_LOW_PRTY_FALL_RESET
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_MSB 		 WIFICMN_IMR_S2_PTA_BT_LOW_PRTY_RISE_MSB
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_LSB 		 WIFICMN_IMR_S2_PTA_BT_LOW_PRTY_RISE_LSB
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_MASK 		 WIFICMN_IMR_S2_PTA_BT_LOW_PRTY_RISE_MASK
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_GET(x) 		 WIFICMN_IMR_S2_PTA_BT_LOW_PRTY_RISE_GET(x)
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_SET(x) 		 WIFICMN_IMR_S2_PTA_BT_LOW_PRTY_RISE_SET(x)
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_RESET 		 WIFICMN_IMR_S2_PTA_BT_LOW_PRTY_RISE_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S6_BB_PANIC_IRQ_MSB 		 MAC_DMA_IMR_S6_BB_PANIC_IRQ_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S6_BB_PANIC_IRQ_LSB 		 MAC_DMA_IMR_S6_BB_PANIC_IRQ_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S6_BB_PANIC_IRQ_MASK 		 MAC_DMA_IMR_S6_BB_PANIC_IRQ_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S6_BB_PANIC_IRQ_GET(x) 		 MAC_DMA_IMR_S6_BB_PANIC_IRQ_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S6_BB_PANIC_IRQ_SET(x) 		 MAC_DMA_IMR_S6_BB_PANIC_IRQ_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S6_BB_PANIC_IRQ_RESET 		 MAC_DMA_IMR_S6_BB_PANIC_IRQ_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_MSB 		 MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_LSB 		 MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_MASK 		 MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_GET(x) 		 MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_SET(x) 		 MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_RESET 		 MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_RESET
// Reason:Obsolete 	 #define MAC_DMA_IMR_S6_ADDRESS 		 MAC_DMA_IMR_S6_ADDRESS
// Reason:Obsolete 	 #define MAC_DMA_IMR_S6_OFFSET 		 MAC_DMA_IMR_S6_OFFSET
// SW modifiable bits
// Reason:Obsolete 	 #define MAC_DMA_IMR_S6_SW_MASK 		 MAC_DMA_IMR_S6_SW_MASK
// bits defined at reset
// Reason:Obsolete 	 #define MAC_DMA_IMR_S6_RSTMASK 		 MAC_DMA_IMR_S6_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S6_RESET 		 MAC_DMA_IMR_S6_RESET

// 32'h00c0 (MAC_DMA_ISR_P_RAC)
// Reason:Obsolete: RAC is not used any more. 	 #define MAC_DMA_ISR_P_RAC_DATA_MSB 		 MAC_DMA_ISR_P_RAC_DATA_MSB
// Reason:Obsolete: RAC is not used any more. 	 #define MAC_DMA_ISR_P_RAC_DATA_LSB 		 MAC_DMA_ISR_P_RAC_DATA_LSB
// Reason:Obsolete: RAC is not used any more. 	 #define MAC_DMA_ISR_P_RAC_DATA_MASK 		 MAC_DMA_ISR_P_RAC_DATA_MASK
// Reason:Obsolete: RAC is not used any more. 	 #define MAC_DMA_ISR_P_RAC_DATA_GET(x) 		 MAC_DMA_ISR_P_RAC_DATA_GET(x)
// Reason:Obsolete: RAC is not used any more. 	 #define MAC_DMA_ISR_P_RAC_DATA_SET(x) 		 MAC_DMA_ISR_P_RAC_DATA_SET(x)
// Reason:Obsolete: RAC is not used any more. 	 #define MAC_DMA_ISR_P_RAC_DATA_RESET 		 MAC_DMA_ISR_P_RAC_DATA_RESET
// Reason:Obsolete: RAC is not used any more. 	 #define MAC_DMA_ISR_P_RAC_ADDRESS 		 MAC_DMA_ISR_P_RAC_ADDRESS
// Reason:Obsolete: RAC is not used any more. 	 #define MAC_DMA_ISR_P_RAC_OFFSET 		 MAC_DMA_ISR_P_RAC_OFFSET
// SW modifiable bits
// Reason:Obsolete: RAC is not used any more. 	 #define MAC_DMA_ISR_P_RAC_SW_MASK 		 MAC_DMA_ISR_P_RAC_SW_MASK
// bits defined at reset
// Reason:Obsolete: RAC is not used any more. 	 #define MAC_DMA_ISR_P_RAC_RSTMASK 		 MAC_DMA_ISR_P_RAC_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: RAC is not used any more. 	 #define MAC_DMA_ISR_P_RAC_RESET 		 MAC_DMA_ISR_P_RAC_RESET

// 32'h00c8 (MAC_DMA_ISR_S1_S)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RSVD_2_MSB 		 MAC_DMA_ISR_S1_S_RSVD_2_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RSVD_2_MSB 		 MAC_DMA_ISR_S1_S_RSVD_2_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RSVD_2_LSB 		 MAC_DMA_ISR_S1_S_RSVD_2_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RSVD_2_LSB 		 MAC_DMA_ISR_S1_S_RSVD_2_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RSVD_2_MASK 		 MAC_DMA_ISR_S1_S_RSVD_2_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RSVD_2_MASK 		 MAC_DMA_ISR_S1_S_RSVD_2_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RSVD_2_GET(x) 		 MAC_DMA_ISR_S1_S_RSVD_2_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RSVD_2_GET(x) 		 MAC_DMA_ISR_S1_S_RSVD_2_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RSVD_2_SET(x) 		 MAC_DMA_ISR_S1_S_RSVD_2_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RSVD_2_SET(x) 		 MAC_DMA_ISR_S1_S_RSVD_2_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RSVD_2_RESET 		 MAC_DMA_ISR_S1_S_RSVD_2_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RSVD_2_RESET 		 MAC_DMA_ISR_S1_S_RSVD_2_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_TXEOL_MSB 		 MAC_DMA_ISR_S1_S_TXEOL_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_TXEOL_MSB 		 MAC_DMA_ISR_S1_S_TXEOL_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_TXEOL_LSB 		 MAC_DMA_ISR_S1_S_TXEOL_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_TXEOL_LSB 		 MAC_DMA_ISR_S1_S_TXEOL_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_TXEOL_MASK 		 MAC_DMA_ISR_S1_S_TXEOL_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_TXEOL_MASK 		 MAC_DMA_ISR_S1_S_TXEOL_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_TXEOL_GET(x) 		 MAC_DMA_ISR_S1_S_TXEOL_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_TXEOL_GET(x) 		 MAC_DMA_ISR_S1_S_TXEOL_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_TXEOL_SET(x) 		 MAC_DMA_ISR_S1_S_TXEOL_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_TXEOL_SET(x) 		 MAC_DMA_ISR_S1_S_TXEOL_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_TXEOL_RESET 		 MAC_DMA_ISR_S1_S_TXEOL_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_TXEOL_RESET 		 MAC_DMA_ISR_S1_S_TXEOL_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RSVD_1_MSB 		 MAC_DMA_ISR_S1_S_RSVD_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RSVD_1_MSB 		 MAC_DMA_ISR_S1_S_RSVD_1_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RSVD_1_LSB 		 MAC_DMA_ISR_S1_S_RSVD_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RSVD_1_LSB 		 MAC_DMA_ISR_S1_S_RSVD_1_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RSVD_1_MASK 		 MAC_DMA_ISR_S1_S_RSVD_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RSVD_1_MASK 		 MAC_DMA_ISR_S1_S_RSVD_1_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RSVD_1_GET(x) 		 MAC_DMA_ISR_S1_S_RSVD_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RSVD_1_GET(x) 		 MAC_DMA_ISR_S1_S_RSVD_1_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RSVD_1_SET(x) 		 MAC_DMA_ISR_S1_S_RSVD_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RSVD_1_SET(x) 		 MAC_DMA_ISR_S1_S_RSVD_1_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RSVD_1_RESET 		 MAC_DMA_ISR_S1_S_RSVD_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RSVD_1_RESET 		 MAC_DMA_ISR_S1_S_RSVD_1_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_TXERR_MSB 		 MAC_DMA_ISR_S1_S_TXERR_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_TXERR_MSB 		 MAC_DMA_ISR_S1_S_TXERR_MSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_TXERR_LSB 		 MAC_DMA_ISR_S1_S_TXERR_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_TXERR_LSB 		 MAC_DMA_ISR_S1_S_TXERR_LSB
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_TXERR_MASK 		 MAC_DMA_ISR_S1_S_TXERR_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_TXERR_MASK 		 MAC_DMA_ISR_S1_S_TXERR_MASK
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_TXERR_GET(x) 		 MAC_DMA_ISR_S1_S_TXERR_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_TXERR_GET(x) 		 MAC_DMA_ISR_S1_S_TXERR_GET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_TXERR_SET(x) 		 MAC_DMA_ISR_S1_S_TXERR_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_TXERR_SET(x) 		 MAC_DMA_ISR_S1_S_TXERR_SET(x)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_TXERR_RESET 		 MAC_DMA_ISR_S1_S_TXERR_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_TXERR_RESET 		 MAC_DMA_ISR_S1_S_TXERR_RESET
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_ADDRESS 		 MAC_DMA_ISR_S1_S_ADDRESS
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_ADDRESS 		 MAC_DMA_ISR_S1_S_ADDRESS
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_OFFSET 		 MAC_DMA_ISR_S1_S_OFFSET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_OFFSET 		 MAC_DMA_ISR_S1_S_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_SW_MASK 		 MAC_DMA_ISR_S1_S_SW_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_SW_MASK 		 MAC_DMA_ISR_S1_S_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RSTMASK 		 MAC_DMA_ISR_S1_S_RSTMASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RSTMASK 		 MAC_DMA_ISR_S1_S_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change - use wmac_wcpu_intr_2(tx) 	 #define MAC_DMA_ISR_S1_S_RESET 		 MAC_DMA_ISR_S1_S_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S1_S_RESET 		 MAC_DMA_ISR_S1_S_RESET

// 32'h00cc (MAC_DMA_ISR_S6_S)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RSVD_MSB 		 MAC_DMA_ISR_S6_S_RSVD_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RSVD_LSB 		 MAC_DMA_ISR_S6_S_RSVD_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RSVD_MASK 		 MAC_DMA_ISR_S6_S_RSVD_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RSVD_GET(x) 		 MAC_DMA_ISR_S6_S_RSVD_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RSVD_SET(x) 		 MAC_DMA_ISR_S6_S_RSVD_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RSVD_RESET 		 MAC_DMA_ISR_S6_S_RSVD_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_MSB 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_LSB 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_MASK 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_GET(x) 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_SET(x) 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_RESET 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_MSB 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_LSB 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_MASK 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_GET(x) 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_SET(x) 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_RESET 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_MSB 		 MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_LSB 		 MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_MASK 		 MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_GET(x) 		 MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_SET(x) 		 MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_RESET 		 MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_MSB 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_LSB 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_MASK 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_GET(x) 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_SET(x) 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_RESET 		 MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_LSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MASK 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_GET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_SET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_RESET 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_MSB 		 MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_LSB 		 MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_MASK 		 MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_GET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_SET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_RESET 		 MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_MSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_LSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_MASK 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_GET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_SET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_RESET 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_MSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_LSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_MASK 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_GET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_SET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_RESET 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_MSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_LSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_MASK 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_GET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_SET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_RESET 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_MSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_LSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_MASK 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_GET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_SET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_RESET 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_MSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_LSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_MASK 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_GET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_SET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_RESET 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_MSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_LSB 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_MASK 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_GET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_SET(x) 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_RESET 		 MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_MSB 		 MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_LSB 		 MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_MASK 		 MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_GET(x) 		 MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_SET(x) 		 MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_RESET 		 MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_MSB 		 MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_LSB 		 MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_MASK 		 MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_GET(x) 		 MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_SET(x) 		 MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_RESET 		 MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_MSB 		 MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_LSB 		 MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_MASK 		 MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_GET(x) 		 MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_SET(x) 		 MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_RESET 		 MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_MSB 		 MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_LSB 		 MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_MASK 		 MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_GET(x) 		 MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_SET(x) 		 MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_RESET 		 MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_WL_STOMPED_MSB 		 MAC_DMA_ISR_S6_S_WL_STOMPED_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_WL_STOMPED_LSB 		 MAC_DMA_ISR_S6_S_WL_STOMPED_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_WL_STOMPED_MASK 		 MAC_DMA_ISR_S6_S_WL_STOMPED_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_WL_STOMPED_GET(x) 		 MAC_DMA_ISR_S6_S_WL_STOMPED_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_WL_STOMPED_SET(x) 		 MAC_DMA_ISR_S6_S_WL_STOMPED_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_WL_STOMPED_RESET 		 MAC_DMA_ISR_S6_S_WL_STOMPED_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_STOMPED_MSB 		 MAC_DMA_ISR_S6_S_BT_STOMPED_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_STOMPED_LSB 		 MAC_DMA_ISR_S6_S_BT_STOMPED_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_STOMPED_MASK 		 MAC_DMA_ISR_S6_S_BT_STOMPED_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_STOMPED_GET(x) 		 MAC_DMA_ISR_S6_S_BT_STOMPED_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_STOMPED_SET(x) 		 MAC_DMA_ISR_S6_S_BT_STOMPED_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_STOMPED_RESET 		 MAC_DMA_ISR_S6_S_BT_STOMPED_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_MSB 		 MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_LSB 		 MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_MASK 		 MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_GET(x) 		 MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_SET(x) 		 MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_RESET 		 MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_MSB 		 MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_LSB 		 MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_MASK 		 MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_GET(x) 		 MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_SET(x) 		 MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_RESET 		 MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_MSB 		 MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_LSB 		 MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_MASK 		 MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_GET(x) 		 MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_SET(x) 		 MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_RESET 		 MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_MSB 		 MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_LSB 		 MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_MASK 		 MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_GET(x) 		 MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_SET(x) 		 MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_RESET 		 MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_ADDRESS 		 MAC_DMA_ISR_S6_S_ADDRESS
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_OFFSET 		 MAC_DMA_ISR_S6_S_OFFSET
// SW modifiable bits
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_SW_MASK 		 MAC_DMA_ISR_S6_S_SW_MASK
// bits defined at reset
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RSTMASK 		 MAC_DMA_ISR_S6_S_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S6_S_RESET 		 MAC_DMA_ISR_S6_S_RESET

// 32'h00d0 (MAC_DMA_ISR_S2_S)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_RSVD_MSB 		 MAC_DMA_ISR_S2_S_RSVD_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_RSVD_LSB 		 MAC_DMA_ISR_S2_S_RSVD_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_RSVD_MASK 		 MAC_DMA_ISR_S2_S_RSVD_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_RSVD_GET(x) 		 MAC_DMA_ISR_S2_S_RSVD_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_RSVD_SET(x) 		 MAC_DMA_ISR_S2_S_RSVD_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_RSVD_RESET 		 MAC_DMA_ISR_S2_S_RSVD_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_MSB 		 MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_LSB 		 MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_MASK 		 MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_GET(x) 		 MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_SET(x) 		 MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_RESET 		 MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TSFOOR_STA_0_MSB 		 MAC_DMA_ISR_S2_S_TSFOOR_STA_0_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TSFOOR_STA_0_LSB 		 MAC_DMA_ISR_S2_S_TSFOOR_STA_0_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TSFOOR_STA_0_MASK 		 MAC_DMA_ISR_S2_S_TSFOOR_STA_0_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TSFOOR_STA_0_GET(x) 		 MAC_DMA_ISR_S2_S_TSFOOR_STA_0_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TSFOOR_STA_0_SET(x) 		 MAC_DMA_ISR_S2_S_TSFOOR_STA_0_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TSFOOR_STA_0_RESET 		 MAC_DMA_ISR_S2_S_TSFOOR_STA_0_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIM_STA_0_MSB 		 MAC_DMA_ISR_S2_S_DTIM_STA_0_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIM_STA_0_LSB 		 MAC_DMA_ISR_S2_S_DTIM_STA_0_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIM_STA_0_MASK 		 MAC_DMA_ISR_S2_S_DTIM_STA_0_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIM_STA_0_GET(x) 		 MAC_DMA_ISR_S2_S_DTIM_STA_0_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIM_STA_0_SET(x) 		 MAC_DMA_ISR_S2_S_DTIM_STA_0_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIM_STA_0_RESET 		 MAC_DMA_ISR_S2_S_DTIM_STA_0_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABTO_STA_0_MSB 		 MAC_DMA_ISR_S2_S_CABTO_STA_0_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABTO_STA_0_LSB 		 MAC_DMA_ISR_S2_S_CABTO_STA_0_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABTO_STA_0_MASK 		 MAC_DMA_ISR_S2_S_CABTO_STA_0_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABTO_STA_0_GET(x) 		 MAC_DMA_ISR_S2_S_CABTO_STA_0_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABTO_STA_0_SET(x) 		 MAC_DMA_ISR_S2_S_CABTO_STA_0_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABTO_STA_0_RESET 		 MAC_DMA_ISR_S2_S_CABTO_STA_0_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_BCNTO_STA_0_MSB 		 MAC_DMA_ISR_S2_S_BCNTO_STA_0_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_BCNTO_STA_0_LSB 		 MAC_DMA_ISR_S2_S_BCNTO_STA_0_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_BCNTO_STA_0_MASK 		 MAC_DMA_ISR_S2_S_BCNTO_STA_0_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_BCNTO_STA_0_GET(x) 		 MAC_DMA_ISR_S2_S_BCNTO_STA_0_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_BCNTO_STA_0_SET(x) 		 MAC_DMA_ISR_S2_S_BCNTO_STA_0_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_BCNTO_STA_0_RESET 		 MAC_DMA_ISR_S2_S_BCNTO_STA_0_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_MSB 		 MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_LSB 		 MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_MASK 		 MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_GET(x) 		 MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_SET(x) 		 MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_RESET 		 MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABEND_STA_0_MSB 		 MAC_DMA_ISR_S2_S_CABEND_STA_0_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABEND_STA_0_LSB 		 MAC_DMA_ISR_S2_S_CABEND_STA_0_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABEND_STA_0_MASK 		 MAC_DMA_ISR_S2_S_CABEND_STA_0_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABEND_STA_0_GET(x) 		 MAC_DMA_ISR_S2_S_CABEND_STA_0_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABEND_STA_0_SET(x) 		 MAC_DMA_ISR_S2_S_CABEND_STA_0_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABEND_STA_0_RESET 		 MAC_DMA_ISR_S2_S_CABEND_STA_0_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TIM_STA_0_MSB 		 MAC_DMA_ISR_S2_S_TIM_STA_0_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TIM_STA_0_LSB 		 MAC_DMA_ISR_S2_S_TIM_STA_0_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TIM_STA_0_MASK 		 MAC_DMA_ISR_S2_S_TIM_STA_0_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TIM_STA_0_GET(x) 		 MAC_DMA_ISR_S2_S_TIM_STA_0_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TIM_STA_0_SET(x) 		 MAC_DMA_ISR_S2_S_TIM_STA_0_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TIM_STA_0_RESET 		 MAC_DMA_ISR_S2_S_TIM_STA_0_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_GTT_MSB 		 MAC_DMA_ISR_S2_S_GTT_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_GTT_LSB 		 MAC_DMA_ISR_S2_S_GTT_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_GTT_MASK 		 MAC_DMA_ISR_S2_S_GTT_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_GTT_GET(x) 		 MAC_DMA_ISR_S2_S_GTT_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_GTT_SET(x) 		 MAC_DMA_ISR_S2_S_GTT_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_GTT_RESET 		 MAC_DMA_ISR_S2_S_GTT_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CST_MSB 		 MAC_DMA_ISR_S2_S_CST_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CST_LSB 		 MAC_DMA_ISR_S2_S_CST_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CST_MASK 		 MAC_DMA_ISR_S2_S_CST_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CST_GET(x) 		 MAC_DMA_ISR_S2_S_CST_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CST_SET(x) 		 MAC_DMA_ISR_S2_S_CST_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CST_RESET 		 MAC_DMA_ISR_S2_S_CST_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_MSB 		 MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_LSB 		 MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_MASK 		 MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_GET(x) 		 MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_SET(x) 		 MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_RESET 		 MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TSFOOR_STA_1_MSB 		 MAC_DMA_ISR_S2_S_TSFOOR_STA_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TSFOOR_STA_1_LSB 		 MAC_DMA_ISR_S2_S_TSFOOR_STA_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TSFOOR_STA_1_MASK 		 MAC_DMA_ISR_S2_S_TSFOOR_STA_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TSFOOR_STA_1_GET(x) 		 MAC_DMA_ISR_S2_S_TSFOOR_STA_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TSFOOR_STA_1_SET(x) 		 MAC_DMA_ISR_S2_S_TSFOOR_STA_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TSFOOR_STA_1_RESET 		 MAC_DMA_ISR_S2_S_TSFOOR_STA_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIM_STA_1_MSB 		 MAC_DMA_ISR_S2_S_DTIM_STA_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIM_STA_1_LSB 		 MAC_DMA_ISR_S2_S_DTIM_STA_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIM_STA_1_MASK 		 MAC_DMA_ISR_S2_S_DTIM_STA_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIM_STA_1_GET(x) 		 MAC_DMA_ISR_S2_S_DTIM_STA_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIM_STA_1_SET(x) 		 MAC_DMA_ISR_S2_S_DTIM_STA_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIM_STA_1_RESET 		 MAC_DMA_ISR_S2_S_DTIM_STA_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABTO_STA_1_MSB 		 MAC_DMA_ISR_S2_S_CABTO_STA_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABTO_STA_1_LSB 		 MAC_DMA_ISR_S2_S_CABTO_STA_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABTO_STA_1_MASK 		 MAC_DMA_ISR_S2_S_CABTO_STA_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABTO_STA_1_GET(x) 		 MAC_DMA_ISR_S2_S_CABTO_STA_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABTO_STA_1_SET(x) 		 MAC_DMA_ISR_S2_S_CABTO_STA_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABTO_STA_1_RESET 		 MAC_DMA_ISR_S2_S_CABTO_STA_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_BCNTO_STA_1_MSB 		 MAC_DMA_ISR_S2_S_BCNTO_STA_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_BCNTO_STA_1_LSB 		 MAC_DMA_ISR_S2_S_BCNTO_STA_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_BCNTO_STA_1_MASK 		 MAC_DMA_ISR_S2_S_BCNTO_STA_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_BCNTO_STA_1_GET(x) 		 MAC_DMA_ISR_S2_S_BCNTO_STA_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_BCNTO_STA_1_SET(x) 		 MAC_DMA_ISR_S2_S_BCNTO_STA_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_BCNTO_STA_1_RESET 		 MAC_DMA_ISR_S2_S_BCNTO_STA_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_MSB 		 MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_LSB 		 MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_MASK 		 MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_GET(x) 		 MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_SET(x) 		 MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_RESET 		 MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABEND_STA_1_MSB 		 MAC_DMA_ISR_S2_S_CABEND_STA_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABEND_STA_1_LSB 		 MAC_DMA_ISR_S2_S_CABEND_STA_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABEND_STA_1_MASK 		 MAC_DMA_ISR_S2_S_CABEND_STA_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABEND_STA_1_GET(x) 		 MAC_DMA_ISR_S2_S_CABEND_STA_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABEND_STA_1_SET(x) 		 MAC_DMA_ISR_S2_S_CABEND_STA_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_CABEND_STA_1_RESET 		 MAC_DMA_ISR_S2_S_CABEND_STA_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TIM_STA_1_MSB 		 MAC_DMA_ISR_S2_S_TIM_STA_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TIM_STA_1_LSB 		 MAC_DMA_ISR_S2_S_TIM_STA_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TIM_STA_1_MASK 		 MAC_DMA_ISR_S2_S_TIM_STA_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TIM_STA_1_GET(x) 		 MAC_DMA_ISR_S2_S_TIM_STA_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TIM_STA_1_SET(x) 		 MAC_DMA_ISR_S2_S_TIM_STA_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TIM_STA_1_RESET 		 MAC_DMA_ISR_S2_S_TIM_STA_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_MSB 		 MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_LSB 		 MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_MASK 		 MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_GET(x) 		 MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_SET(x) 		 MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_RESET 		 MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TDMA_APSYNC_MSB 		 MAC_DMA_ISR_S2_S_TDMA_APSYNC_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TDMA_APSYNC_LSB 		 MAC_DMA_ISR_S2_S_TDMA_APSYNC_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TDMA_APSYNC_MASK 		 MAC_DMA_ISR_S2_S_TDMA_APSYNC_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TDMA_APSYNC_GET(x) 		 MAC_DMA_ISR_S2_S_TDMA_APSYNC_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TDMA_APSYNC_SET(x) 		 MAC_DMA_ISR_S2_S_TDMA_APSYNC_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TDMA_APSYNC_RESET 		 MAC_DMA_ISR_S2_S_TDMA_APSYNC_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_MSB 		 MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_LSB 		 MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_MASK 		 MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_GET(x) 		 MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_SET(x) 		 MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_RESET 		 MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TXURN_MSB 		 MAC_DMA_ISR_S2_S_TXURN_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TXURN_LSB 		 MAC_DMA_ISR_S2_S_TXURN_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TXURN_MASK 		 MAC_DMA_ISR_S2_S_TXURN_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TXURN_GET(x) 		 MAC_DMA_ISR_S2_S_TXURN_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TXURN_SET(x) 		 MAC_DMA_ISR_S2_S_TXURN_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_TXURN_RESET 		 MAC_DMA_ISR_S2_S_TXURN_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_ADDRESS 		 MAC_DMA_ISR_S2_S_ADDRESS
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_OFFSET 		 MAC_DMA_ISR_S2_S_OFFSET
// SW modifiable bits
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_SW_MASK 		 MAC_DMA_ISR_S2_S_SW_MASK
// bits defined at reset
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_RSTMASK 		 MAC_DMA_ISR_S2_S_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S2_S_RESET 		 MAC_DMA_ISR_S2_S_RESET

// 32'h00d4 (MAC_DMA_ISR_S3_S)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_BMISS_STA_1_MSB 		 MAC_DMA_ISR_S3_S_BMISS_STA_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_BMISS_STA_1_LSB 		 MAC_DMA_ISR_S3_S_BMISS_STA_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_BMISS_STA_1_MASK 		 MAC_DMA_ISR_S3_S_BMISS_STA_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_BMISS_STA_1_GET(x) 		 MAC_DMA_ISR_S3_S_BMISS_STA_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_BMISS_STA_1_SET(x) 		 MAC_DMA_ISR_S3_S_BMISS_STA_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_BMISS_STA_1_RESET 		 MAC_DMA_ISR_S3_S_BMISS_STA_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_BMISS_STA_0_MSB 		 MAC_DMA_ISR_S3_S_BMISS_STA_0_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_BMISS_STA_0_LSB 		 MAC_DMA_ISR_S3_S_BMISS_STA_0_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_BMISS_STA_0_MASK 		 MAC_DMA_ISR_S3_S_BMISS_STA_0_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_BMISS_STA_0_GET(x) 		 MAC_DMA_ISR_S3_S_BMISS_STA_0_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_BMISS_STA_0_SET(x) 		 MAC_DMA_ISR_S3_S_BMISS_STA_0_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_BMISS_STA_0_RESET 		 MAC_DMA_ISR_S3_S_BMISS_STA_0_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_MSB 		 MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_LSB 		 MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_MASK 		 MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_GET(x) 		 MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_SET(x) 		 MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_RESET 		 MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_MSB 		 MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_LSB 		 MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_MASK 		 MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_GET(x) 		 MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_SET(x) 		 MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_RESET 		 MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_MSB 		 MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_LSB 		 MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_MASK 		 MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_GET(x) 		 MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_SET(x) 		 MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_RESET 		 MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_MSB 		 MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_LSB 		 MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_MASK 		 MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_GET(x) 		 MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_SET(x) 		 MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_RESET 		 MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_QCBRURN_MSB 		 MAC_DMA_ISR_S3_S_QCBRURN_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_QCBRURN_LSB 		 MAC_DMA_ISR_S3_S_QCBRURN_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_QCBRURN_MASK 		 MAC_DMA_ISR_S3_S_QCBRURN_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_QCBRURN_GET(x) 		 MAC_DMA_ISR_S3_S_QCBRURN_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_QCBRURN_SET(x) 		 MAC_DMA_ISR_S3_S_QCBRURN_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_QCBRURN_RESET 		 MAC_DMA_ISR_S3_S_QCBRURN_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_MSB 		 MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_LSB 		 MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_MASK 		 MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_GET(x) 		 MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_SET(x) 		 MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_RESET 		 MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_MSB 		 MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_LSB 		 MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_MASK 		 MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_GET(x) 		 MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_SET(x) 		 MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_RESET 		 MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RSVD_MSB 		 MAC_DMA_ISR_S3_S_RSVD_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RSVD_LSB 		 MAC_DMA_ISR_S3_S_RSVD_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RSVD_MASK 		 MAC_DMA_ISR_S3_S_RSVD_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RSVD_GET(x) 		 MAC_DMA_ISR_S3_S_RSVD_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RSVD_SET(x) 		 MAC_DMA_ISR_S3_S_RSVD_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RSVD_RESET 		 MAC_DMA_ISR_S3_S_RSVD_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_QCBROVF_MSB 		 MAC_DMA_ISR_S3_S_QCBROVF_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_QCBROVF_LSB 		 MAC_DMA_ISR_S3_S_QCBROVF_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_QCBROVF_MASK 		 MAC_DMA_ISR_S3_S_QCBROVF_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_QCBROVF_GET(x) 		 MAC_DMA_ISR_S3_S_QCBROVF_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_QCBROVF_SET(x) 		 MAC_DMA_ISR_S3_S_QCBROVF_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_QCBROVF_RESET 		 MAC_DMA_ISR_S3_S_QCBROVF_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_ADDRESS 		 MAC_DMA_ISR_S3_S_ADDRESS
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_OFFSET 		 MAC_DMA_ISR_S3_S_OFFSET
// SW modifiable bits
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_SW_MASK 		 MAC_DMA_ISR_S3_S_SW_MASK
// bits defined at reset
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RSTMASK 		 MAC_DMA_ISR_S3_S_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S3_S_RESET 		 MAC_DMA_ISR_S3_S_RESET

// 32'h00d8 (MAC_DMA_ISR_S4_S)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RSVD_2_MSB 		 MAC_DMA_ISR_S4_S_RSVD_2_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RSVD_2_MSB 		 MAC_DMA_ISR_S4_S_RSVD_2_MSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RSVD_2_LSB 		 MAC_DMA_ISR_S4_S_RSVD_2_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RSVD_2_LSB 		 MAC_DMA_ISR_S4_S_RSVD_2_LSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RSVD_2_MASK 		 MAC_DMA_ISR_S4_S_RSVD_2_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RSVD_2_MASK 		 MAC_DMA_ISR_S4_S_RSVD_2_MASK
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RSVD_2_GET(x) 		 MAC_DMA_ISR_S4_S_RSVD_2_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RSVD_2_GET(x) 		 MAC_DMA_ISR_S4_S_RSVD_2_GET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RSVD_2_SET(x) 		 MAC_DMA_ISR_S4_S_RSVD_2_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RSVD_2_SET(x) 		 MAC_DMA_ISR_S4_S_RSVD_2_SET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RSVD_2_RESET 		 MAC_DMA_ISR_S4_S_RSVD_2_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RSVD_2_RESET 		 MAC_DMA_ISR_S4_S_RSVD_2_RESET
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_MSB 		 MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_MSB 		 MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_MSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_LSB 		 MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_LSB 		 MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_LSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_MASK 		 MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_MASK 		 MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_MASK
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_GET(x) 		 MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_GET(x) 		 MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_GET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_SET(x) 		 MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_SET(x) 		 MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_SET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_RESET 		 MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_RESET 		 MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_RESET
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RSVD_1_MSB 		 MAC_DMA_ISR_S4_S_RSVD_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RSVD_1_MSB 		 MAC_DMA_ISR_S4_S_RSVD_1_MSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RSVD_1_LSB 		 MAC_DMA_ISR_S4_S_RSVD_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RSVD_1_LSB 		 MAC_DMA_ISR_S4_S_RSVD_1_LSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RSVD_1_MASK 		 MAC_DMA_ISR_S4_S_RSVD_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RSVD_1_MASK 		 MAC_DMA_ISR_S4_S_RSVD_1_MASK
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RSVD_1_GET(x) 		 MAC_DMA_ISR_S4_S_RSVD_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RSVD_1_GET(x) 		 MAC_DMA_ISR_S4_S_RSVD_1_GET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RSVD_1_SET(x) 		 MAC_DMA_ISR_S4_S_RSVD_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RSVD_1_SET(x) 		 MAC_DMA_ISR_S4_S_RSVD_1_SET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RSVD_1_RESET 		 MAC_DMA_ISR_S4_S_RSVD_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RSVD_1_RESET 		 MAC_DMA_ISR_S4_S_RSVD_1_RESET
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_QTRIG_MSB 		 MAC_DMA_ISR_S4_S_QTRIG_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_QTRIG_MSB 		 MAC_DMA_ISR_S4_S_QTRIG_MSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_QTRIG_LSB 		 MAC_DMA_ISR_S4_S_QTRIG_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_QTRIG_LSB 		 MAC_DMA_ISR_S4_S_QTRIG_LSB
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_QTRIG_MASK 		 MAC_DMA_ISR_S4_S_QTRIG_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_QTRIG_MASK 		 MAC_DMA_ISR_S4_S_QTRIG_MASK
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_QTRIG_GET(x) 		 MAC_DMA_ISR_S4_S_QTRIG_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_QTRIG_GET(x) 		 MAC_DMA_ISR_S4_S_QTRIG_GET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_QTRIG_SET(x) 		 MAC_DMA_ISR_S4_S_QTRIG_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_QTRIG_SET(x) 		 MAC_DMA_ISR_S4_S_QTRIG_SET(x)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_QTRIG_RESET 		 MAC_DMA_ISR_S4_S_QTRIG_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_QTRIG_RESET 		 MAC_DMA_ISR_S4_S_QTRIG_RESET
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_ADDRESS 		 MAC_DMA_ISR_S4_S_ADDRESS
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_ADDRESS 		 MAC_DMA_ISR_S4_S_ADDRESS
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_OFFSET 		 MAC_DMA_ISR_S4_S_OFFSET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_OFFSET 		 MAC_DMA_ISR_S4_S_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_SW_MASK 		 MAC_DMA_ISR_S4_S_SW_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_SW_MASK 		 MAC_DMA_ISR_S4_S_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RSTMASK 		 MAC_DMA_ISR_S4_S_RSTMASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RSTMASK 		 MAC_DMA_ISR_S4_S_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change. 	 #define MAC_DMA_ISR_S4_S_RESET 		 MAC_DMA_ISR_S4_S_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S4_S_RESET 		 MAC_DMA_ISR_S4_S_RESET

// 32'h00dc (MAC_DMA_ISR_S5_S)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_MSB 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_LSB 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_MASK 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_GET(x) 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_SET(x) 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_RESET 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_MSB 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_LSB 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_MASK 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_GET(x) 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_SET(x) 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_RESET 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_MSB 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_LSB 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_MASK 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_GET(x) 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_SET(x) 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_RESET 		 MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_ADDRESS 		 MAC_DMA_ISR_S5_S_ADDRESS
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_OFFSET 		 MAC_DMA_ISR_S5_S_OFFSET
// SW modifiable bits
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_SW_MASK 		 MAC_DMA_ISR_S5_S_SW_MASK
// bits defined at reset
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_RSTMASK 		 MAC_DMA_ISR_S5_S_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S5_S_RESET 		 MAC_DMA_ISR_S5_S_RESET

// 32'h00e0 (MAC_DMA_DMADBG_0)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_0_DATA_MSB 		 MAC_DMA_DMADBG_0_DATA_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_0_DATA_LSB 		 MAC_DMA_DMADBG_0_DATA_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_0_DATA_MASK 		 MAC_DMA_DMADBG_0_DATA_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_0_DATA_GET(x) 		 MAC_DMA_DMADBG_0_DATA_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_0_DATA_SET(x) 		 MAC_DMA_DMADBG_0_DATA_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_0_DATA_RESET 		 MAC_DMA_DMADBG_0_DATA_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_0_ADDRESS 		 MAC_DMA_DMADBG_0_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_0_OFFSET 		 MAC_DMA_DMADBG_0_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_0_SW_MASK 		 MAC_DMA_DMADBG_0_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_0_RSTMASK 		 MAC_DMA_DMADBG_0_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_0_RESET 		 MAC_DMA_DMADBG_0_RESET

// 32'h00e4 (MAC_DMA_DMADBG_1)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_1_DATA_MSB 		 MAC_DMA_DMADBG_1_DATA_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_1_DATA_LSB 		 MAC_DMA_DMADBG_1_DATA_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_1_DATA_MASK 		 MAC_DMA_DMADBG_1_DATA_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_1_DATA_GET(x) 		 MAC_DMA_DMADBG_1_DATA_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_1_DATA_SET(x) 		 MAC_DMA_DMADBG_1_DATA_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_1_DATA_RESET 		 MAC_DMA_DMADBG_1_DATA_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_1_ADDRESS 		 MAC_DMA_DMADBG_1_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_1_OFFSET 		 MAC_DMA_DMADBG_1_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_1_SW_MASK 		 MAC_DMA_DMADBG_1_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_1_RSTMASK 		 MAC_DMA_DMADBG_1_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_1_RESET 		 MAC_DMA_DMADBG_1_RESET

// 32'h00e8 (MAC_DMA_DMADBG_2)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_2_DATA_MSB 		 MAC_DMA_DMADBG_2_DATA_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_2_DATA_LSB 		 MAC_DMA_DMADBG_2_DATA_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_2_DATA_MASK 		 MAC_DMA_DMADBG_2_DATA_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_2_DATA_GET(x) 		 MAC_DMA_DMADBG_2_DATA_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_2_DATA_SET(x) 		 MAC_DMA_DMADBG_2_DATA_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_2_DATA_RESET 		 MAC_DMA_DMADBG_2_DATA_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_2_ADDRESS 		 MAC_DMA_DMADBG_2_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_2_OFFSET 		 MAC_DMA_DMADBG_2_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_2_SW_MASK 		 MAC_DMA_DMADBG_2_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_2_RSTMASK 		 MAC_DMA_DMADBG_2_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_2_RESET 		 MAC_DMA_DMADBG_2_RESET

// 32'h00ec (MAC_DMA_DMADBG_3)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_3_DATA_MSB 		 MAC_DMA_DMADBG_3_DATA_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_3_DATA_LSB 		 MAC_DMA_DMADBG_3_DATA_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_3_DATA_MASK 		 MAC_DMA_DMADBG_3_DATA_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_3_DATA_GET(x) 		 MAC_DMA_DMADBG_3_DATA_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_3_DATA_SET(x) 		 MAC_DMA_DMADBG_3_DATA_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_3_DATA_RESET 		 MAC_DMA_DMADBG_3_DATA_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_3_ADDRESS 		 MAC_DMA_DMADBG_3_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_3_OFFSET 		 MAC_DMA_DMADBG_3_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_3_SW_MASK 		 MAC_DMA_DMADBG_3_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_3_RSTMASK 		 MAC_DMA_DMADBG_3_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_3_RESET 		 MAC_DMA_DMADBG_3_RESET

// 32'h00f0 (MAC_DMA_DMADBG_4)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_4_DATA_MSB 		 MAC_DMA_DMADBG_4_DATA_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_4_DATA_LSB 		 MAC_DMA_DMADBG_4_DATA_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_4_DATA_MASK 		 MAC_DMA_DMADBG_4_DATA_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_4_DATA_GET(x) 		 MAC_DMA_DMADBG_4_DATA_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_4_DATA_SET(x) 		 MAC_DMA_DMADBG_4_DATA_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_4_DATA_RESET 		 MAC_DMA_DMADBG_4_DATA_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_4_ADDRESS 		 MAC_DMA_DMADBG_4_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_4_OFFSET 		 MAC_DMA_DMADBG_4_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_4_SW_MASK 		 MAC_DMA_DMADBG_4_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_4_RSTMASK 		 MAC_DMA_DMADBG_4_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_4_RESET 		 MAC_DMA_DMADBG_4_RESET

// 32'h00f4 (MAC_DMA_DMADBG_5)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_5_DATA_MSB 		 MAC_DMA_DMADBG_5_DATA_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_5_DATA_LSB 		 MAC_DMA_DMADBG_5_DATA_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_5_DATA_MASK 		 MAC_DMA_DMADBG_5_DATA_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_5_DATA_GET(x) 		 MAC_DMA_DMADBG_5_DATA_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_5_DATA_SET(x) 		 MAC_DMA_DMADBG_5_DATA_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_5_DATA_RESET 		 MAC_DMA_DMADBG_5_DATA_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_5_ADDRESS 		 MAC_DMA_DMADBG_5_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_5_OFFSET 		 MAC_DMA_DMADBG_5_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_5_SW_MASK 		 MAC_DMA_DMADBG_5_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_5_RSTMASK 		 MAC_DMA_DMADBG_5_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_5_RESET 		 MAC_DMA_DMADBG_5_RESET

// 32'h00f8 (MAC_DMA_DMADBG_6)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_6_DATA_MSB 		 MAC_DMA_DMADBG_6_DATA_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_6_DATA_LSB 		 MAC_DMA_DMADBG_6_DATA_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_6_DATA_MASK 		 MAC_DMA_DMADBG_6_DATA_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_6_DATA_GET(x) 		 MAC_DMA_DMADBG_6_DATA_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_6_DATA_SET(x) 		 MAC_DMA_DMADBG_6_DATA_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_6_DATA_RESET 		 MAC_DMA_DMADBG_6_DATA_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_6_ADDRESS 		 MAC_DMA_DMADBG_6_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_6_OFFSET 		 MAC_DMA_DMADBG_6_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_6_SW_MASK 		 MAC_DMA_DMADBG_6_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_6_RSTMASK 		 MAC_DMA_DMADBG_6_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_6_RESET 		 MAC_DMA_DMADBG_6_RESET

// 32'h00fc (MAC_DMA_DMADBG_7)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_7_DATA_MSB 		 MAC_DMA_DMADBG_7_DATA_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_7_DATA_LSB 		 MAC_DMA_DMADBG_7_DATA_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_7_DATA_MASK 		 MAC_DMA_DMADBG_7_DATA_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_7_DATA_GET(x) 		 MAC_DMA_DMADBG_7_DATA_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_7_DATA_SET(x) 		 MAC_DMA_DMADBG_7_DATA_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_7_DATA_RESET 		 MAC_DMA_DMADBG_7_DATA_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_7_ADDRESS 		 MAC_DMA_DMADBG_7_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_7_OFFSET 		 MAC_DMA_DMADBG_7_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_7_SW_MASK 		 MAC_DMA_DMADBG_7_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_7_RSTMASK 		 MAC_DMA_DMADBG_7_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_DMADBG_7_RESET 		 MAC_DMA_DMADBG_7_RESET

// 32'h0100 (MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_MSB 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_LSB 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_MASK 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_GET(x) 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_SET(x) 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_RESET 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_ADDRESS 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_OFFSET 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_SW_MASK 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_RSTMASK 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_RESET 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_RESET

// 32'h0104 (MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_MSB 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_LSB 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_MASK 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_GET(x) 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_SET(x) 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_RESET 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_ADDRESS 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_OFFSET 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_SW_MASK 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_RSTMASK 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_RESET 		 MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_RESET

// 32'h0108 (MAC_DMA_ISR_S7)
#define MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_MSB 		 MCMN_ISR_S0_RX_WMAC_ERR_MSB
#define MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_LSB 		 MCMN_ISR_S0_RX_WMAC_ERR_LSB
#define MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_MASK 		 MCMN_ISR_S0_RX_WMAC_ERR_MASK
#define MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_GET(x) 		 MCMN_ISR_S0_RX_WMAC_ERR_GET(x)
#define MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_SET(x) 		 MCMN_ISR_S0_RX_WMAC_ERR_SET(x)
#define MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_RESET 		 MCMN_ISR_S0_RX_WMAC_ERR_RESET
#define MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_MSB 		 MCMN_ISR_S0_RX_ETH_ERR_MSB
#define MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_LSB 		 MCMN_ISR_S0_RX_ETH_ERR_LSB
#define MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_MASK 		 MCMN_ISR_S0_RX_ETH_ERR_MASK
#define MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_GET(x) 		 MCMN_ISR_S0_RX_ETH_ERR_GET(x)
#define MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_SET(x) 		 MCMN_ISR_S0_RX_ETH_ERR_SET(x)
#define MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_RESET 		 MCMN_ISR_S0_RX_ETH_ERR_RESET
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_MSB 		 MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_MSB
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_LSB 		 MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_LSB
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_MASK 		 MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_MASK
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_GET(x) 		 MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_SET(x) 		 MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_RESET 		 MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_RESET
#define MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_MSB 		 MCMN_ISR_S0_RX_MSDU_LEN_MSB
#define MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_LSB 		 MCMN_ISR_S0_RX_MSDU_LEN_LSB
#define MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_MASK 		 MCMN_ISR_S0_RX_MSDU_LEN_MASK
#define MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_GET(x) 		 MCMN_ISR_S0_RX_MSDU_LEN_GET(x)
#define MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_SET(x) 		 MCMN_ISR_S0_RX_MSDU_LEN_SET(x)
#define MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_RESET 		 MCMN_ISR_S0_RX_MSDU_LEN_RESET
#define MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_MSB 		 MCMN_ISR_S0_TX_ILLEGAL_MSB
#define MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_LSB 		 MCMN_ISR_S0_TX_ILLEGAL_LSB
#define MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_MASK 		 MCMN_ISR_S0_TX_ILLEGAL_MASK
#define MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_GET(x) 		 MCMN_ISR_S0_TX_ILLEGAL_GET(x)
#define MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_SET(x) 		 MCMN_ISR_S0_TX_ILLEGAL_SET(x)
#define MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_RESET 		 MCMN_ISR_S0_TX_ILLEGAL_RESET
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_MSB 		 MCMN_ISR_S0_TX_UNKN_LLC_MSB
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_LSB 		 MCMN_ISR_S0_TX_UNKN_LLC_LSB
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_MASK 		 MCMN_ISR_S0_TX_UNKN_LLC_MASK
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_GET(x) 		 MCMN_ISR_S0_TX_UNKN_LLC_GET(x)
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_SET(x) 		 MCMN_ISR_S0_TX_UNKN_LLC_SET(x)
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_RESET 		 MCMN_ISR_S0_TX_UNKN_LLC_RESET
#define MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_MSB 		 MCMN_ISR_S0_TX_VLAN_LLC_MSB
#define MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_LSB 		 MCMN_ISR_S0_TX_VLAN_LLC_LSB
#define MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_MASK 		 MCMN_ISR_S0_TX_VLAN_LLC_MASK
#define MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_GET(x) 		 MCMN_ISR_S0_TX_VLAN_LLC_GET(x)
#define MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_SET(x) 		 MCMN_ISR_S0_TX_VLAN_LLC_SET(x)
#define MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_RESET 		 MCMN_ISR_S0_TX_VLAN_LLC_RESET
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MSB 		 MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MSB
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_LSB 		 MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_LSB
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MASK 		 MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MASK
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_GET(x) 		 MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_SET(x) 		 MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_RESET 		 MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_RESET
#define MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_MSB 		 MCMN_ISR_S0_TX_SEQ_BM_ERR_MSB
#define MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_LSB 		 MCMN_ISR_S0_TX_SEQ_BM_ERR_LSB
#define MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_MASK 		 MCMN_ISR_S0_TX_SEQ_BM_ERR_MASK
#define MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_GET(x) 		 MCMN_ISR_S0_TX_SEQ_BM_ERR_GET(x)
#define MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_SET(x) 		 MCMN_ISR_S0_TX_SEQ_BM_ERR_SET(x)
#define MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_RESET 		 MCMN_ISR_S0_TX_SEQ_BM_ERR_RESET
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_MSB 		 MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_MSB
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_LSB 		 MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_LSB
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_MASK 		 MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_MASK
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_GET(x) 		 MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_SET(x) 		 MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_RESET 		 MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_RESET
#define MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_MSB 		 MCMN_ISR_S0_AMSDU_FRM_ERR_MSB
#define MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_LSB 		 MCMN_ISR_S0_AMSDU_FRM_ERR_LSB
#define MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_MASK 		 MCMN_ISR_S0_AMSDU_FRM_ERR_MASK
#define MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_GET(x) 		 MCMN_ISR_S0_AMSDU_FRM_ERR_GET(x)
#define MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_SET(x) 		 MCMN_ISR_S0_AMSDU_FRM_ERR_SET(x)
#define MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_RESET 		 MCMN_ISR_S0_AMSDU_FRM_ERR_RESET
#define MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_MSB 		 MCMN_ISR_S0_WEP_KEY_ERR_MSB
#define MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_LSB 		 MCMN_ISR_S0_WEP_KEY_ERR_LSB
#define MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_MASK 		 MCMN_ISR_S0_WEP_KEY_ERR_MASK
#define MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_GET(x) 		 MCMN_ISR_S0_WEP_KEY_ERR_GET(x)
#define MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_SET(x) 		 MCMN_ISR_S0_WEP_KEY_ERR_SET(x)
#define MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_RESET 		 MCMN_ISR_S0_WEP_KEY_ERR_RESET
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_MSB 		 MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_MSB
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_LSB 		 MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_LSB
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_MASK 		 MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_MASK
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_GET(x) 		 MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_SET(x) 		 MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_RESET 		 MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_RESET
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_ADDRESS 		 MAC_DMA_ISR_S7_ADDRESS
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_OFFSET 		 MAC_DMA_ISR_S7_OFFSET
// SW modifiable bits
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_SW_MASK 		 MAC_DMA_ISR_S7_SW_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_SW_MASK 		 MAC_DMA_ISR_S7_SW_MASK
// bits defined at reset
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_RSTMASK 		 MAC_DMA_ISR_S7_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete 	 #define MAC_DMA_ISR_S7_RESET 		 MAC_DMA_ISR_S7_RESET

// 32'h010c (MAC_DMA_IMR_S7)
#define MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_MSB 		 MCMN_IMR_S0_RX_WMAC_ERR_MSB
#define MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_LSB 		 MCMN_IMR_S0_RX_WMAC_ERR_LSB
#define MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_MASK 		 MCMN_IMR_S0_RX_WMAC_ERR_MASK
#define MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_GET(x) 		 MCMN_IMR_S0_RX_WMAC_ERR_GET(x)
#define MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_SET(x) 		 MCMN_IMR_S0_RX_WMAC_ERR_SET(x)
#define MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_RESET 		 MCMN_IMR_S0_RX_WMAC_ERR_RESET
#define MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_MSB 		 MCMN_IMR_S0_RX_ETH_ERR_MSB
#define MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_LSB 		 MCMN_IMR_S0_RX_ETH_ERR_LSB
#define MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_MASK 		 MCMN_IMR_S0_RX_ETH_ERR_MASK
#define MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_GET(x) 		 MCMN_IMR_S0_RX_ETH_ERR_GET(x)
#define MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_SET(x) 		 MCMN_IMR_S0_RX_ETH_ERR_SET(x)
#define MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_RESET 		 MCMN_IMR_S0_RX_ETH_ERR_RESET
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_MSB 		 MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_MSB
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_LSB 		 MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_LSB
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_MASK 		 MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_MASK
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_GET(x) 		 MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_SET(x) 		 MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_RESET 		 MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_RESET
#define MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_MSB 		 MCMN_IMR_S0_RX_MSDU_LEN_MSB
#define MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_LSB 		 MCMN_IMR_S0_RX_MSDU_LEN_LSB
#define MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_MASK 		 MCMN_IMR_S0_RX_MSDU_LEN_MASK
#define MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_GET(x) 		 MCMN_IMR_S0_RX_MSDU_LEN_GET(x)
#define MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_SET(x) 		 MCMN_IMR_S0_RX_MSDU_LEN_SET(x)
#define MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_RESET 		 MCMN_IMR_S0_RX_MSDU_LEN_RESET
#define MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_MSB 		 MCMN_IMR_S0_TX_ILLEGAL_MSB
#define MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_LSB 		 MCMN_IMR_S0_TX_ILLEGAL_LSB
#define MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_MASK 		 MCMN_IMR_S0_TX_ILLEGAL_MASK
#define MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_GET(x) 		 MCMN_IMR_S0_TX_ILLEGAL_GET(x)
#define MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_SET(x) 		 MCMN_IMR_S0_TX_ILLEGAL_SET(x)
#define MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_RESET 		 MCMN_IMR_S0_TX_ILLEGAL_RESET
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_MSB 		 MCMN_IMR_S0_TX_UNKN_LLC_MSB
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_LSB 		 MCMN_IMR_S0_TX_UNKN_LLC_LSB
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_MASK 		 MCMN_IMR_S0_TX_UNKN_LLC_MASK
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_GET(x) 		 MCMN_IMR_S0_TX_UNKN_LLC_GET(x)
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_SET(x) 		 MCMN_IMR_S0_TX_UNKN_LLC_SET(x)
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_RESET 		 MCMN_IMR_S0_TX_UNKN_LLC_RESET
#define MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_MSB 		 MCMN_IMR_S0_TX_VLAN_LLC_MSB
#define MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_LSB 		 MCMN_IMR_S0_TX_VLAN_LLC_LSB
#define MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_MASK 		 MCMN_IMR_S0_TX_VLAN_LLC_MASK
#define MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_GET(x) 		 MCMN_IMR_S0_TX_VLAN_LLC_GET(x)
#define MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_SET(x) 		 MCMN_IMR_S0_TX_VLAN_LLC_SET(x)
#define MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_RESET 		 MCMN_IMR_S0_TX_VLAN_LLC_RESET
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MSB 		 MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MSB
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_LSB 		 MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_LSB
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MASK 		 MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MASK
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_GET(x) 		 MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_SET(x) 		 MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_RESET 		 MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_RESET
#define MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_MSB 		 MCMN_IMR_S0_TX_SEQ_BM_ERR_MSB
#define MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_LSB 		 MCMN_IMR_S0_TX_SEQ_BM_ERR_LSB
#define MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_MASK 		 MCMN_IMR_S0_TX_SEQ_BM_ERR_MASK
#define MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_GET(x) 		 MCMN_IMR_S0_TX_SEQ_BM_ERR_GET(x)
#define MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_SET(x) 		 MCMN_IMR_S0_TX_SEQ_BM_ERR_SET(x)
#define MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_RESET 		 MCMN_IMR_S0_TX_SEQ_BM_ERR_RESET
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_MSB 		 MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_MSB
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_LSB 		 MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_LSB
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_MASK 		 MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_MASK
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_GET(x) 		 MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_SET(x) 		 MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_RESET 		 MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_RESET
#define MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_MSB 		 MCMN_IMR_S0_AMSDU_FRM_ERR_MSB
#define MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_LSB 		 MCMN_IMR_S0_AMSDU_FRM_ERR_LSB
#define MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_MASK 		 MCMN_IMR_S0_AMSDU_FRM_ERR_MASK
#define MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_GET(x) 		 MCMN_IMR_S0_AMSDU_FRM_ERR_GET(x)
#define MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_SET(x) 		 MCMN_IMR_S0_AMSDU_FRM_ERR_SET(x)
#define MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_RESET 		 MCMN_IMR_S0_AMSDU_FRM_ERR_RESET
#define MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_MSB 		 MCMN_IMR_S0_WEP_KEY_ERR_MSB
#define MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_LSB 		 MCMN_IMR_S0_WEP_KEY_ERR_LSB
#define MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_MASK 		 MCMN_IMR_S0_WEP_KEY_ERR_MASK
#define MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_GET(x) 		 MCMN_IMR_S0_WEP_KEY_ERR_GET(x)
#define MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_SET(x) 		 MCMN_IMR_S0_WEP_KEY_ERR_SET(x)
#define MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_RESET 		 MCMN_IMR_S0_WEP_KEY_ERR_RESET
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_MSB 		 MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_MSB
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_LSB 		 MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_LSB
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_MASK 		 MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_MASK
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_GET(x) 		 MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_GET(x)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_SET(x) 		 MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_SET(x)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_RESET 		 MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_RESET
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_ADDRESS 		 MAC_DMA_IMR_S7_ADDRESS
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_OFFSET 		 MAC_DMA_IMR_S7_OFFSET
// SW modifiable bits
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_SW_MASK 		 MAC_DMA_IMR_S7_SW_MASK
// bits defined at reset
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_RSTMASK 		 MAC_DMA_IMR_S7_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete 	 #define MAC_DMA_IMR_S7_RESET 		 MAC_DMA_IMR_S7_RESET

// 32'h0110 (MAC_DMA_ISR_S7_S)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RESERVED_1_MSB 		 MAC_DMA_ISR_S7_S_RESERVED_1_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RESERVED_1_LSB 		 MAC_DMA_ISR_S7_S_RESERVED_1_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RESERVED_1_MASK 		 MAC_DMA_ISR_S7_S_RESERVED_1_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RESERVED_1_GET(x) 		 MAC_DMA_ISR_S7_S_RESERVED_1_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RESERVED_1_SET(x) 		 MAC_DMA_ISR_S7_S_RESERVED_1_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RESERVED_1_RESET 		 MAC_DMA_ISR_S7_S_RESERVED_1_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_MSB 		 MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_LSB 		 MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_MASK 		 MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_GET(x) 		 MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_SET(x) 		 MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_RESET 		 MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_MSB 		 MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_LSB 		 MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_MASK 		 MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_GET(x) 		 MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_SET(x) 		 MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_RESET 		 MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_MSB 		 MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_LSB 		 MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_MASK 		 MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_GET(x) 		 MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_SET(x) 		 MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_RESET 		 MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_MSB 		 MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_LSB 		 MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_MASK 		 MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_GET(x) 		 MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_SET(x) 		 MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_RESET 		 MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RESERVED_0_MSB 		 MAC_DMA_ISR_S7_S_RESERVED_0_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RESERVED_0_LSB 		 MAC_DMA_ISR_S7_S_RESERVED_0_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RESERVED_0_MASK 		 MAC_DMA_ISR_S7_S_RESERVED_0_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RESERVED_0_GET(x) 		 MAC_DMA_ISR_S7_S_RESERVED_0_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RESERVED_0_SET(x) 		 MAC_DMA_ISR_S7_S_RESERVED_0_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RESERVED_0_RESET 		 MAC_DMA_ISR_S7_S_RESERVED_0_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_MSB 		 MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_LSB 		 MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_MASK 		 MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_GET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_SET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_RESET 		 MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_MSB 		 MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_LSB 		 MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_MASK 		 MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_GET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_SET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_RESET 		 MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_MSB 		 MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_LSB 		 MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_MASK 		 MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_GET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_SET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_RESET 		 MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_MSB 		 MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_LSB 		 MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_MASK 		 MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_GET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_SET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_RESET 		 MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_MSB 		 MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_LSB 		 MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_MASK 		 MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_GET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_SET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_RESET 		 MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_MSB 		 MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_LSB 		 MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_MASK 		 MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_GET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_SET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_RESET 		 MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_MSB 		 MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_LSB 		 MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_MASK 		 MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_GET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_SET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_RESET 		 MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_MSB 		 MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_LSB 		 MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_MASK 		 MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_GET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_SET(x) 		 MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_RESET 		 MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_MSB 		 MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_MSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_LSB 		 MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_LSB
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_MASK 		 MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_MASK
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_GET(x) 		 MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_GET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_SET(x) 		 MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_SET(x)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_RESET 		 MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_RESET
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_ADDRESS 		 MAC_DMA_ISR_S7_S_ADDRESS
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_OFFSET 		 MAC_DMA_ISR_S7_S_OFFSET
// SW modifiable bits
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_SW_MASK 		 MAC_DMA_ISR_S7_S_SW_MASK
// bits defined at reset
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RSTMASK 		 MAC_DMA_ISR_S7_S_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: shadow interrupt is not used any more. 	 #define MAC_DMA_ISR_S7_S_RESET 		 MAC_DMA_ISR_S7_S_RESET

// 32'h012c (MAC_DMA_CHKACC)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CHKACC_CHKSUM_SEL_MSB 		 MAC_DMA_CHKACC_CHKSUM_SEL_MSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CHKACC_CHKSUM_SEL_LSB 		 MAC_DMA_CHKACC_CHKSUM_SEL_LSB
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CHKACC_CHKSUM_SEL_MASK 		 MAC_DMA_CHKACC_CHKSUM_SEL_MASK
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CHKACC_CHKSUM_SEL_GET(x) 		 MAC_DMA_CHKACC_CHKSUM_SEL_GET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CHKACC_CHKSUM_SEL_SET(x) 		 MAC_DMA_CHKACC_CHKSUM_SEL_SET(x)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CHKACC_CHKSUM_SEL_RESET 		 MAC_DMA_CHKACC_CHKSUM_SEL_RESET
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CHKACC_ADDRESS 		 MAC_DMA_CHKACC_ADDRESS
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CHKACC_OFFSET 		 MAC_DMA_CHKACC_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CHKACC_SW_MASK 		 MAC_DMA_CHKACC_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CHKACC_RSTMASK 		 MAC_DMA_CHKACC_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change 	 #define MAC_DMA_CHKACC_RESET 		 MAC_DMA_CHKACC_RESET

// 32'h0138 (MAC_DMA_AXI_CFG_0)
#define MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_MSB 		 MXI_CFG_1_WIFI_MEM_BASE_ADDR_MSB
#define MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_LSB 		 MXI_CFG_1_WIFI_MEM_BASE_ADDR_LSB
#define MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_MASK 		 MXI_CFG_1_WIFI_MEM_BASE_ADDR_MASK
#define MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_GET(x) 		 MXI_CFG_1_WIFI_MEM_BASE_ADDR_GET(x)
#define MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_SET(x) 		 MXI_CFG_1_WIFI_MEM_BASE_ADDR_SET(x)
#define MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_RESET 		 MXI_CFG_1_WIFI_MEM_BASE_ADDR_RESET
#define MAC_DMA_AXI_CFG_0_ADDRESS 		 MXI_BASE_ADDRESS+MXI_CFG_1_ADDRESS
#define MAC_DMA_AXI_CFG_0_OFFSET 		 MXI_BASE_ADDRESS+MXI_CFG_1_OFFSET
// SW modifiable bits
#define MAC_DMA_AXI_CFG_0_SW_MASK 		 MXI_CFG_1_SW_MASK
// bits defined at reset
#define MAC_DMA_AXI_CFG_0_RSTMASK 		 MXI_CFG_1_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_AXI_CFG_0_RESET 		 MXI_CFG_1_RESET

// 32'h013c (MAC_DMA_AXI_CFG_1)
#define MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_MSB 		 MXI_CFG_2_WIFI_MEM_MASK_MSB
#define MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_LSB 		 MXI_CFG_2_WIFI_MEM_MASK_LSB
#define MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_MASK 		 MXI_CFG_2_WIFI_MEM_MASK_MASK
#define MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_GET(x) 		 MXI_CFG_2_WIFI_MEM_MASK_GET(x)
#define MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_SET(x) 		 MXI_CFG_2_WIFI_MEM_MASK_SET(x)
#define MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_RESET 		 MXI_CFG_2_WIFI_MEM_MASK_RESET
#define MAC_DMA_AXI_CFG_1_ADDRESS 		 MXI_BASE_ADDRESS+MXI_CFG_2_ADDRESS
#define MAC_DMA_AXI_CFG_1_OFFSET 		 MXI_BASE_ADDRESS+MXI_CFG_2_OFFSET
// SW modifiable bits
#define MAC_DMA_AXI_CFG_1_SW_MASK 		 MXI_CFG_2_SW_MASK
// bits defined at reset
#define MAC_DMA_AXI_CFG_1_RSTMASK 		 MXI_CFG_2_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_AXI_CFG_1_RESET 		 MXI_CFG_2_RESET

// 32'h0140 (MAC_DMA_AXI_CFG_2)
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_MSB 		 MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_MSB
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_LSB 		 MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_LSB
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_MASK 		 MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_MASK
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_GET(x) 		 MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_GET(x)
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_SET(x) 		 MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_SET(x)
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_RESET 		 MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_RESET
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_MSB 		 MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_MSB
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_LSB 		 MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_LSB
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_MASK 		 MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_MASK
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_GET(x) 		 MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_GET(x)
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_SET(x) 		 MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_SET(x)
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_RESET 		 MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_RESET
// Reason:Obsolete 	 #define MAC_DMA_AXI_CFG_2_ADDRESS 		 MAC_DMA_AXI_CFG_2_ADDRESS
// Reason:Obsolete 	 #define MAC_DMA_AXI_CFG_2_OFFSET 		 MAC_DMA_AXI_CFG_2_OFFSET
// SW modifiable bits
// Reason:Obsolete 	 #define MAC_DMA_AXI_CFG_2_SW_MASK 		 MAC_DMA_AXI_CFG_2_SW_MASK
// bits defined at reset
// Reason:Obsolete 	 #define MAC_DMA_AXI_CFG_2_RSTMASK 		 MAC_DMA_AXI_CFG_2_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete 	 #define MAC_DMA_AXI_CFG_2_RESET 		 MAC_DMA_AXI_CFG_2_RESET

// 32'h0200 (MAC_DMA_RCV_CFG_RING0_0)
#define MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_MSB 		 RXDMA_CFG_RING0_0_BASE_ADDR_MSB
#define MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_LSB 		 RXDMA_CFG_RING0_0_BASE_ADDR_LSB
#define MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_MASK 		 RXDMA_CFG_RING0_0_BASE_ADDR_MASK
#define MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_GET(x) 		 RXDMA_CFG_RING0_0_BASE_ADDR_GET(x)
#define MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_SET(x) 		 RXDMA_CFG_RING0_0_BASE_ADDR_SET(x)
#define MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_RESET 		 RXDMA_CFG_RING0_0_BASE_ADDR_RESET
#define MAC_DMA_RCV_CFG_RING0_0_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_0_ADDRESS)
#define MAC_DMA_RCV_CFG_RING0_0_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_0_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING0_0_SW_MASK 		 RXDMA_CFG_RING0_0_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING0_0_RSTMASK 		 RXDMA_CFG_RING0_0_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING0_0_RESET 		 RXDMA_CFG_RING0_0_RESET

// 32'h0204 (MAC_DMA_RCV_CFG_RING0_1)
#define MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_MSB 		 RXDMA_CFG_RING0_1_BUF_SIZE_MSB
#define MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_LSB 		 RXDMA_CFG_RING0_1_BUF_SIZE_LSB
#define MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_MASK 		 RXDMA_CFG_RING0_1_BUF_SIZE_MASK
#define MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_GET(x) 		 RXDMA_CFG_RING0_1_BUF_SIZE_GET(x)
#define MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_SET(x) 		 RXDMA_CFG_RING0_1_BUF_SIZE_SET(x)
#define MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_RESET 		 RXDMA_CFG_RING0_1_BUF_SIZE_RESET
#define MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_MSB 		 RXDMA_CFG_RING0_1_NUM_DESCS_MSB
#define MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_LSB 		 RXDMA_CFG_RING0_1_NUM_DESCS_LSB
#define MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_MASK 		 RXDMA_CFG_RING0_1_NUM_DESCS_MASK
#define MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_GET(x) 		 RXDMA_CFG_RING0_1_NUM_DESCS_GET(x)
#define MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_SET(x) 		 RXDMA_CFG_RING0_1_NUM_DESCS_SET(x)
#define MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_RESET 		 RXDMA_CFG_RING0_1_NUM_DESCS_RESET
#define MAC_DMA_RCV_CFG_RING0_1_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_1_ADDRESS)
#define MAC_DMA_RCV_CFG_RING0_1_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_1_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING0_1_SW_MASK 		 RXDMA_CFG_RING0_1_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING0_1_RSTMASK 		 RXDMA_CFG_RING0_1_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING0_1_RESET 		 RXDMA_CFG_RING0_1_RESET

// 32'h0208 (MAC_DMA_RCV_CFG_RING0_2)
#define MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_MSB 		 RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_LSB 		 RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_MASK 		 RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_GET(x) 		 RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_SET(x) 		 RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_RESET 		 RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_MSB 		 RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_LSB 		 RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_MASK 		 RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_GET(x) 		 RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_SET(x) 		 RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_RESET 		 RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_MSB 		 RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_LSB 		 RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_MASK 		 RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_GET(x) 		 RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_SET(x) 		 RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_RESET 		 RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_MSB 		 RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_LSB 		 RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_MASK 		 RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_GET(x) 		 RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_SET(x) 		 RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_RESET 		 RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_MSB 		 RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_LSB 		 RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_MASK 		 RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_GET(x) 		 RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_SET(x) 		 RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_RESET 		 RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_MSB 		 RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_LSB 		 RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_MASK 		 RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_GET(x) 		 RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_SET(x) 		 RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_RESET 		 RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_MSB 		 RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_LSB 		 RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_MASK 		 RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_GET(x) 		 RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_SET(x) 		 RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_RESET 		 RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_MSB 		 RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_LSB 		 RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_MASK 		 RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_GET(x) 		 RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_SET(x) 		 RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_RESET 		 RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_MSB 		 RXDMA_CFG_RING0_2_RX_PACKET_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_LSB 		 RXDMA_CFG_RING0_2_RX_PACKET_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_MASK 		 RXDMA_CFG_RING0_2_RX_PACKET_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_GET(x) 		 RXDMA_CFG_RING0_2_RX_PACKET_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_SET(x) 		 RXDMA_CFG_RING0_2_RX_PACKET_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_RESET 		 RXDMA_CFG_RING0_2_RX_PACKET_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_MSB 		 RXDMA_CFG_RING0_2_RX_HEADER_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_LSB 		 RXDMA_CFG_RING0_2_RX_HEADER_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_MASK 		 RXDMA_CFG_RING0_2_RX_HEADER_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_GET(x) 		 RXDMA_CFG_RING0_2_RX_HEADER_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_SET(x) 		 RXDMA_CFG_RING0_2_RX_HEADER_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_RESET 		 RXDMA_CFG_RING0_2_RX_HEADER_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_MSB 		 RXDMA_CFG_RING0_2_INTR_LWM_THRESH_MSB
#define MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_LSB 		 RXDMA_CFG_RING0_2_INTR_LWM_THRESH_LSB
#define MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_MASK 		 RXDMA_CFG_RING0_2_INTR_LWM_THRESH_MASK
#define MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_GET(x) 		 RXDMA_CFG_RING0_2_INTR_LWM_THRESH_GET(x)
#define MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_SET(x) 		 RXDMA_CFG_RING0_2_INTR_LWM_THRESH_SET(x)
#define MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_RESET 		 RXDMA_CFG_RING0_2_INTR_LWM_THRESH_RESET
#define MAC_DMA_RCV_CFG_RING0_2_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_2_ADDRESS)
#define MAC_DMA_RCV_CFG_RING0_2_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_2_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING0_2_SW_MASK 		 RXDMA_CFG_RING0_2_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING0_2_RSTMASK 		 RXDMA_CFG_RING0_2_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING0_2_RESET 		 RXDMA_CFG_RING0_2_RESET

// 32'h020c (MAC_DMA_RCV_CFG_RING0_3)
#define MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_MSB 		 RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_LSB 		 RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_MASK 		 RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_GET(x) 		 RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_SET(x) 		 RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_RESET 		 RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_MSB 		 RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_LSB 		 RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_MASK 		 RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_GET(x) 		 RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_SET(x) 		 RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_RESET 		 RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING0_3_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_3_ADDRESS)
#define MAC_DMA_RCV_CFG_RING0_3_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_3_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING0_3_SW_MASK 		 RXDMA_CFG_RING0_3_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING0_3_RSTMASK 		 RXDMA_CFG_RING0_3_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING0_3_RESET 		 RXDMA_CFG_RING0_3_RESET

// 32'h0210 (MAC_DMA_RCV_CFG_RING0_4)
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_MSB 		 RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_LSB 		 RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_MASK 		 RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_GET(x) 		 RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_SET(x) 		 RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_RESET 		 RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_MSB 		 RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_LSB 		 RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_MASK 		 RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_GET(x) 		 RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_SET(x) 		 RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_RESET 		 RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING0_4_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_4_ADDRESS)
#define MAC_DMA_RCV_CFG_RING0_4_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_4_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING0_4_SW_MASK 		 RXDMA_CFG_RING0_4_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING0_4_RSTMASK 		 RXDMA_CFG_RING0_4_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING0_4_RESET 		 RXDMA_CFG_RING0_4_RESET

// 32'h0214 (MAC_DMA_RCV_CFG_RING0_5)
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_MSB 		 RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_LSB 		 RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_MASK 		 RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_GET(x) 		 RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_SET(x) 		 RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_RESET 		 RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_MSB 		 RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_LSB 		 RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_MASK 		 RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_GET(x) 		 RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_SET(x) 		 RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_RESET 		 RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING0_5_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_5_ADDRESS)
#define MAC_DMA_RCV_CFG_RING0_5_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_5_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING0_5_SW_MASK 		 RXDMA_CFG_RING0_5_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING0_5_RSTMASK 		 RXDMA_CFG_RING0_5_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING0_5_RESET 		 RXDMA_CFG_RING0_5_RESET

// 32'h0218 (MAC_DMA_RCV_CFG_RING0_6)
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_MSB 		 RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_LSB 		 RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_MASK 		 RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_GET(x) 		 RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_SET(x) 		 RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_RESET 		 RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_MSB 		 RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_LSB 		 RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_MASK 		 RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_GET(x) 		 RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_SET(x) 		 RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_RESET 		 RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING0_6_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_6_ADDRESS)
#define MAC_DMA_RCV_CFG_RING0_6_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_6_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING0_6_SW_MASK 		 RXDMA_CFG_RING0_6_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING0_6_RSTMASK 		 RXDMA_CFG_RING0_6_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING0_6_RESET 		 RXDMA_CFG_RING0_6_RESET

// 32'h021c (MAC_DMA_RCV_CFG_RING0_7)
#define MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_MSB 		 RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_LSB 		 RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_MASK 		 RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_GET(x) 		 RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_SET(x) 		 RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_RESET 		 RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_MSB 		 RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_LSB 		 RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_MASK 		 RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_GET(x) 		 RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_SET(x) 		 RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_RESET 		 RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING0_7_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_7_ADDRESS)
#define MAC_DMA_RCV_CFG_RING0_7_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING0_7_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING0_7_SW_MASK 		 RXDMA_CFG_RING0_7_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING0_7_RSTMASK 		 RXDMA_CFG_RING0_7_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING0_7_RESET 		 RXDMA_CFG_RING0_7_RESET

// 32'h0230 (MAC_DMA_RCV_CFG_RING1_0)
#define MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_MSB 		 RXDMA_CFG_RING1_0_BASE_ADDR_MSB
#define MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_LSB 		 RXDMA_CFG_RING1_0_BASE_ADDR_LSB
#define MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_MASK 		 RXDMA_CFG_RING1_0_BASE_ADDR_MASK
#define MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_GET(x) 		 RXDMA_CFG_RING1_0_BASE_ADDR_GET(x)
#define MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_SET(x) 		 RXDMA_CFG_RING1_0_BASE_ADDR_SET(x)
#define MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_RESET 		 RXDMA_CFG_RING1_0_BASE_ADDR_RESET
#define MAC_DMA_RCV_CFG_RING1_0_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_0_ADDRESS)
#define MAC_DMA_RCV_CFG_RING1_0_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_0_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING1_0_SW_MASK 		 RXDMA_CFG_RING1_0_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING1_0_RSTMASK 		 RXDMA_CFG_RING1_0_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING1_0_RESET 		 RXDMA_CFG_RING1_0_RESET

// 32'h0234 (MAC_DMA_RCV_CFG_RING1_1)
#define MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_MSB 		 RXDMA_CFG_RING1_1_BUF_SIZE_MSB
#define MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_LSB 		 RXDMA_CFG_RING1_1_BUF_SIZE_LSB
#define MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_MASK 		 RXDMA_CFG_RING1_1_BUF_SIZE_MASK
#define MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_GET(x) 		 RXDMA_CFG_RING1_1_BUF_SIZE_GET(x)
#define MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_SET(x) 		 RXDMA_CFG_RING1_1_BUF_SIZE_SET(x)
#define MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_RESET 		 RXDMA_CFG_RING1_1_BUF_SIZE_RESET
#define MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_MSB 		 RXDMA_CFG_RING1_1_NUM_DESCS_MSB
#define MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_LSB 		 RXDMA_CFG_RING1_1_NUM_DESCS_LSB
#define MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_MASK 		 RXDMA_CFG_RING1_1_NUM_DESCS_MASK
#define MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_GET(x) 		 RXDMA_CFG_RING1_1_NUM_DESCS_GET(x)
#define MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_SET(x) 		 RXDMA_CFG_RING1_1_NUM_DESCS_SET(x)
#define MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_RESET 		 RXDMA_CFG_RING1_1_NUM_DESCS_RESET
#define MAC_DMA_RCV_CFG_RING1_1_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_1_ADDRESS)
#define MAC_DMA_RCV_CFG_RING1_1_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_1_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING1_1_SW_MASK 		 RXDMA_CFG_RING1_1_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING1_1_RSTMASK 		 RXDMA_CFG_RING1_1_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING1_1_RESET 		 RXDMA_CFG_RING1_1_RESET

// 32'h0238 (MAC_DMA_RCV_CFG_RING1_2)
#define MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_MSB 		 RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_LSB 		 RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_MASK 		 RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_GET(x) 		 RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_SET(x) 		 RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_RESET 		 RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_MSB 		 RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_LSB 		 RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_MASK 		 RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_GET(x) 		 RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_SET(x) 		 RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_RESET 		 RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_MSB 		 RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_LSB 		 RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_MASK 		 RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_GET(x) 		 RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_SET(x) 		 RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_RESET 		 RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_MSB 		 RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_LSB 		 RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_MASK 		 RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_GET(x) 		 RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_SET(x) 		 RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_RESET 		 RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_MSB 		 RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_LSB 		 RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_MASK 		 RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_GET(x) 		 RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_SET(x) 		 RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_RESET 		 RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_MSB 		 RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_LSB 		 RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_MASK 		 RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_GET(x) 		 RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_SET(x) 		 RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_RESET 		 RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_MSB 		 RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_LSB 		 RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_MASK 		 RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_GET(x) 		 RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_SET(x) 		 RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_RESET 		 RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_MSB 		 RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_LSB 		 RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_MASK 		 RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_GET(x) 		 RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_SET(x) 		 RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_RESET 		 RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_MSB 		 RXDMA_CFG_RING1_2_RX_PACKET_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_LSB 		 RXDMA_CFG_RING1_2_RX_PACKET_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_MASK 		 RXDMA_CFG_RING1_2_RX_PACKET_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_GET(x) 		 RXDMA_CFG_RING1_2_RX_PACKET_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_SET(x) 		 RXDMA_CFG_RING1_2_RX_PACKET_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_RESET 		 RXDMA_CFG_RING1_2_RX_PACKET_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_MSB 		 RXDMA_CFG_RING1_2_RX_HEADER_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_LSB 		 RXDMA_CFG_RING1_2_RX_HEADER_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_MASK 		 RXDMA_CFG_RING1_2_RX_HEADER_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_GET(x) 		 RXDMA_CFG_RING1_2_RX_HEADER_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_SET(x) 		 RXDMA_CFG_RING1_2_RX_HEADER_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_RESET 		 RXDMA_CFG_RING1_2_RX_HEADER_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_MSB 		 RXDMA_CFG_RING1_2_INTR_LWM_THRESH_MSB
#define MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_LSB 		 RXDMA_CFG_RING1_2_INTR_LWM_THRESH_LSB
#define MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_MASK 		 RXDMA_CFG_RING1_2_INTR_LWM_THRESH_MASK
#define MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_GET(x) 		 RXDMA_CFG_RING1_2_INTR_LWM_THRESH_GET(x)
#define MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_SET(x) 		 RXDMA_CFG_RING1_2_INTR_LWM_THRESH_SET(x)
#define MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_RESET 		 RXDMA_CFG_RING1_2_INTR_LWM_THRESH_RESET
#define MAC_DMA_RCV_CFG_RING1_2_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_2_ADDRESS)
#define MAC_DMA_RCV_CFG_RING1_2_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_2_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING1_2_SW_MASK 		 RXDMA_CFG_RING1_2_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING1_2_RSTMASK 		 RXDMA_CFG_RING1_2_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING1_2_RESET 		 RXDMA_CFG_RING1_2_RESET

// 32'h023c (MAC_DMA_RCV_CFG_RING1_3)
#define MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_MSB 		 RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_LSB 		 RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_MASK 		 RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_GET(x) 		 RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_SET(x) 		 RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_RESET 		 RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_MSB 		 RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_LSB 		 RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_MASK 		 RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_GET(x) 		 RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_SET(x) 		 RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_RESET 		 RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING1_3_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_3_ADDRESS)
#define MAC_DMA_RCV_CFG_RING1_3_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_3_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING1_3_SW_MASK 		 RXDMA_CFG_RING1_3_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING1_3_RSTMASK 		 RXDMA_CFG_RING1_3_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING1_3_RESET 		 RXDMA_CFG_RING1_3_RESET

// 32'h0240 (MAC_DMA_RCV_CFG_RING1_4)
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_MSB 		 RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_LSB 		 RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_MASK 		 RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_GET(x) 		 RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_SET(x) 		 RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_RESET 		 RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_MSB 		 RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_LSB 		 RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_MASK 		 RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_GET(x) 		 RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_SET(x) 		 RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_RESET 		 RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING1_4_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_4_ADDRESS)
#define MAC_DMA_RCV_CFG_RING1_4_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_4_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING1_4_SW_MASK 		 RXDMA_CFG_RING1_4_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING1_4_RSTMASK 		 RXDMA_CFG_RING1_4_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING1_4_RESET 		 RXDMA_CFG_RING1_4_RESET

// 32'h0244 (MAC_DMA_RCV_CFG_RING1_5)
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_MSB 		 RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_LSB 		 RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_MASK 		 RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_GET(x) 		 RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_SET(x) 		 RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_RESET 		 RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_MSB 		 RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_LSB 		 RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_MASK 		 RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_GET(x) 		 RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_SET(x) 		 RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_RESET 		 RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING1_5_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_5_ADDRESS)
#define MAC_DMA_RCV_CFG_RING1_5_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_5_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING1_5_SW_MASK 		 RXDMA_CFG_RING1_5_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING1_5_RSTMASK 		 RXDMA_CFG_RING1_5_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING1_5_RESET 		 RXDMA_CFG_RING1_5_RESET

// 32'h0248 (MAC_DMA_RCV_CFG_RING1_6)
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_MSB 		 RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_LSB 		 RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_MASK 		 RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_GET(x) 		 RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_SET(x) 		 RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_RESET 		 RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_MSB 		 RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_LSB 		 RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_MASK 		 RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_GET(x) 		 RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_SET(x) 		 RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_RESET 		 RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING1_6_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_6_ADDRESS)
#define MAC_DMA_RCV_CFG_RING1_6_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_6_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING1_6_SW_MASK 		 RXDMA_CFG_RING1_6_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING1_6_RSTMASK 		 RXDMA_CFG_RING1_6_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING1_6_RESET 		 RXDMA_CFG_RING1_6_RESET

// 32'h024c (MAC_DMA_RCV_CFG_RING1_7)
#define MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_MSB 		 RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_LSB 		 RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_MASK 		 RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_GET(x) 		 RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_SET(x) 		 RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_RESET 		 RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_MSB 		 RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_LSB 		 RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_MASK 		 RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_GET(x) 		 RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_SET(x) 		 RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_RESET 		 RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING1_7_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_7_ADDRESS)
#define MAC_DMA_RCV_CFG_RING1_7_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING1_7_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING1_7_SW_MASK 		 RXDMA_CFG_RING1_7_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING1_7_RSTMASK 		 RXDMA_CFG_RING1_7_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING1_7_RESET 		 RXDMA_CFG_RING1_7_RESET

// 32'h0260 (MAC_DMA_RCV_CFG_RING2_0)
#define MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_MSB 		 RXDMA_CFG_RING2_0_BASE_ADDR_MSB
#define MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_LSB 		 RXDMA_CFG_RING2_0_BASE_ADDR_LSB
#define MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_MASK 		 RXDMA_CFG_RING2_0_BASE_ADDR_MASK
#define MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_GET(x) 		 RXDMA_CFG_RING2_0_BASE_ADDR_GET(x)
#define MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_SET(x) 		 RXDMA_CFG_RING2_0_BASE_ADDR_SET(x)
#define MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_RESET 		 RXDMA_CFG_RING2_0_BASE_ADDR_RESET
#define MAC_DMA_RCV_CFG_RING2_0_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_0_ADDRESS)
#define MAC_DMA_RCV_CFG_RING2_0_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_0_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING2_0_SW_MASK 		 RXDMA_CFG_RING2_0_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING2_0_RSTMASK 		 RXDMA_CFG_RING2_0_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING2_0_RESET 		 RXDMA_CFG_RING2_0_RESET

// 32'h0264 (MAC_DMA_RCV_CFG_RING2_1)
#define MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_MSB 		 RXDMA_CFG_RING2_1_BUF_SIZE_MSB
#define MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_LSB 		 RXDMA_CFG_RING2_1_BUF_SIZE_LSB
#define MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_MASK 		 RXDMA_CFG_RING2_1_BUF_SIZE_MASK
#define MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_GET(x) 		 RXDMA_CFG_RING2_1_BUF_SIZE_GET(x)
#define MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_SET(x) 		 RXDMA_CFG_RING2_1_BUF_SIZE_SET(x)
#define MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_RESET 		 RXDMA_CFG_RING2_1_BUF_SIZE_RESET
#define MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_MSB 		 RXDMA_CFG_RING2_1_NUM_DESCS_MSB
#define MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_LSB 		 RXDMA_CFG_RING2_1_NUM_DESCS_LSB
#define MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_MASK 		 RXDMA_CFG_RING2_1_NUM_DESCS_MASK
#define MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_GET(x) 		 RXDMA_CFG_RING2_1_NUM_DESCS_GET(x)
#define MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_SET(x) 		 RXDMA_CFG_RING2_1_NUM_DESCS_SET(x)
#define MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_RESET 		 RXDMA_CFG_RING2_1_NUM_DESCS_RESET
#define MAC_DMA_RCV_CFG_RING2_1_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_1_ADDRESS)
#define MAC_DMA_RCV_CFG_RING2_1_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_1_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING2_1_SW_MASK 		 RXDMA_CFG_RING2_1_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING2_1_RSTMASK 		 RXDMA_CFG_RING2_1_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING2_1_RESET 		 RXDMA_CFG_RING2_1_RESET

// 32'h0268 (MAC_DMA_RCV_CFG_RING2_2)
#define MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_MSB 		 RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_LSB 		 RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_MASK 		 RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_GET(x) 		 RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_SET(x) 		 RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_RESET 		 RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_MSB 		 RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_LSB 		 RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_MASK 		 RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_GET(x) 		 RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_SET(x) 		 RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_RESET 		 RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_MSB 		 RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_LSB 		 RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_MASK 		 RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_GET(x) 		 RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_SET(x) 		 RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_RESET 		 RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_MSB 		 RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_LSB 		 RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_MASK 		 RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_GET(x) 		 RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_SET(x) 		 RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_RESET 		 RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_MSB 		 RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_LSB 		 RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_MASK 		 RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_GET(x) 		 RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_SET(x) 		 RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_RESET 		 RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_MSB 		 RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_LSB 		 RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_MASK 		 RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_GET(x) 		 RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_SET(x) 		 RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_RESET 		 RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_MSB 		 RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_LSB 		 RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_MASK 		 RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_GET(x) 		 RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_SET(x) 		 RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_RESET 		 RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_MSB 		 RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_LSB 		 RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_MASK 		 RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_GET(x) 		 RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_SET(x) 		 RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_RESET 		 RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_MSB 		 RXDMA_CFG_RING2_2_RX_PACKET_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_LSB 		 RXDMA_CFG_RING2_2_RX_PACKET_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_MASK 		 RXDMA_CFG_RING2_2_RX_PACKET_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_GET(x) 		 RXDMA_CFG_RING2_2_RX_PACKET_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_SET(x) 		 RXDMA_CFG_RING2_2_RX_PACKET_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_RESET 		 RXDMA_CFG_RING2_2_RX_PACKET_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_MSB 		 RXDMA_CFG_RING2_2_RX_HEADER_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_LSB 		 RXDMA_CFG_RING2_2_RX_HEADER_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_MASK 		 RXDMA_CFG_RING2_2_RX_HEADER_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_GET(x) 		 RXDMA_CFG_RING2_2_RX_HEADER_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_SET(x) 		 RXDMA_CFG_RING2_2_RX_HEADER_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_RESET 		 RXDMA_CFG_RING2_2_RX_HEADER_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_MSB 		 RXDMA_CFG_RING2_2_INTR_LWM_THRESH_MSB
#define MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_LSB 		 RXDMA_CFG_RING2_2_INTR_LWM_THRESH_LSB
#define MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_MASK 		 RXDMA_CFG_RING2_2_INTR_LWM_THRESH_MASK
#define MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_GET(x) 		 RXDMA_CFG_RING2_2_INTR_LWM_THRESH_GET(x)
#define MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_SET(x) 		 RXDMA_CFG_RING2_2_INTR_LWM_THRESH_SET(x)
#define MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_RESET 		 RXDMA_CFG_RING2_2_INTR_LWM_THRESH_RESET
#define MAC_DMA_RCV_CFG_RING2_2_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_2_ADDRESS)
#define MAC_DMA_RCV_CFG_RING2_2_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_2_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING2_2_SW_MASK 		 RXDMA_CFG_RING2_2_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING2_2_RSTMASK 		 RXDMA_CFG_RING2_2_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING2_2_RESET 		 RXDMA_CFG_RING2_2_RESET

// 32'h026c (MAC_DMA_RCV_CFG_RING2_3)
#define MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_MSB 		 RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_LSB 		 RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_MASK 		 RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_GET(x) 		 RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_SET(x) 		 RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_RESET 		 RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_MSB 		 RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_LSB 		 RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_MASK 		 RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_GET(x) 		 RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_SET(x) 		 RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_RESET 		 RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING2_3_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_3_ADDRESS)
#define MAC_DMA_RCV_CFG_RING2_3_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_3_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING2_3_SW_MASK 		 RXDMA_CFG_RING2_3_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING2_3_RSTMASK 		 RXDMA_CFG_RING2_3_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING2_3_RESET 		 RXDMA_CFG_RING2_3_RESET

// 32'h0270 (MAC_DMA_RCV_CFG_RING2_4)
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_MSB 		 RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_LSB 		 RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_MASK 		 RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_GET(x) 		 RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_SET(x) 		 RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_RESET 		 RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_MSB 		 RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_LSB 		 RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_MASK 		 RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_GET(x) 		 RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_SET(x) 		 RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_RESET 		 RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING2_4_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_4_ADDRESS)
#define MAC_DMA_RCV_CFG_RING2_4_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_4_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING2_4_SW_MASK 		 RXDMA_CFG_RING2_4_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING2_4_RSTMASK 		 RXDMA_CFG_RING2_4_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING2_4_RESET 		 RXDMA_CFG_RING2_4_RESET

// 32'h0274 (MAC_DMA_RCV_CFG_RING2_5)
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_MSB 		 RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_LSB 		 RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_MASK 		 RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_GET(x) 		 RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_SET(x) 		 RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_RESET 		 RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_MSB 		 RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_LSB 		 RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_MASK 		 RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_GET(x) 		 RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_SET(x) 		 RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_RESET 		 RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING2_5_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_5_ADDRESS)
#define MAC_DMA_RCV_CFG_RING2_5_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_5_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING2_5_SW_MASK 		 RXDMA_CFG_RING2_5_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING2_5_RSTMASK 		 RXDMA_CFG_RING2_5_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING2_5_RESET 		 RXDMA_CFG_RING2_5_RESET

// 32'h0278 (MAC_DMA_RCV_CFG_RING2_6)
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_MSB 		 RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_LSB 		 RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_MASK 		 RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_GET(x) 		 RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_SET(x) 		 RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_RESET 		 RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_MSB 		 RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_LSB 		 RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_MASK 		 RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_GET(x) 		 RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_SET(x) 		 RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_RESET 		 RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING2_6_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_6_ADDRESS)
#define MAC_DMA_RCV_CFG_RING2_6_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_6_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING2_6_SW_MASK 		 RXDMA_CFG_RING2_6_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING2_6_RSTMASK 		 RXDMA_CFG_RING2_6_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING2_6_RESET 		 RXDMA_CFG_RING2_6_RESET

// 32'h027c (MAC_DMA_RCV_CFG_RING2_7)
#define MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_MSB 		 RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_LSB 		 RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_MASK 		 RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_GET(x) 		 RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_SET(x) 		 RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_RESET 		 RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_MSB 		 RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_LSB 		 RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_MASK 		 RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_GET(x) 		 RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_SET(x) 		 RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_RESET 		 RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING2_7_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_7_ADDRESS)
#define MAC_DMA_RCV_CFG_RING2_7_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING2_7_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING2_7_SW_MASK 		 RXDMA_CFG_RING2_7_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING2_7_RSTMASK 		 RXDMA_CFG_RING2_7_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING2_7_RESET 		 RXDMA_CFG_RING2_7_RESET

// 32'h0290 (MAC_DMA_RCV_CFG_RING3_0)
#define MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_MSB 		 RXDMA_CFG_RING3_0_BASE_ADDR_MSB
#define MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_LSB 		 RXDMA_CFG_RING3_0_BASE_ADDR_LSB
#define MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_MASK 		 RXDMA_CFG_RING3_0_BASE_ADDR_MASK
#define MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_GET(x) 		 RXDMA_CFG_RING3_0_BASE_ADDR_GET(x)
#define MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_SET(x) 		 RXDMA_CFG_RING3_0_BASE_ADDR_SET(x)
#define MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_RESET 		 RXDMA_CFG_RING3_0_BASE_ADDR_RESET
#define MAC_DMA_RCV_CFG_RING3_0_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_0_ADDRESS)
#define MAC_DMA_RCV_CFG_RING3_0_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_0_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING3_0_SW_MASK 		 RXDMA_CFG_RING3_0_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING3_0_RSTMASK 		 RXDMA_CFG_RING3_0_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING3_0_RESET 		 RXDMA_CFG_RING3_0_RESET

// 32'h0294 (MAC_DMA_RCV_CFG_RING3_1)
#define MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_MSB 		 RXDMA_CFG_RING3_1_BUF_SIZE_MSB
#define MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_LSB 		 RXDMA_CFG_RING3_1_BUF_SIZE_LSB
#define MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_MASK 		 RXDMA_CFG_RING3_1_BUF_SIZE_MASK
#define MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_GET(x) 		 RXDMA_CFG_RING3_1_BUF_SIZE_GET(x)
#define MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_SET(x) 		 RXDMA_CFG_RING3_1_BUF_SIZE_SET(x)
#define MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_RESET 		 RXDMA_CFG_RING3_1_BUF_SIZE_RESET
#define MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_MSB 		 RXDMA_CFG_RING3_1_NUM_DESCS_MSB
#define MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_LSB 		 RXDMA_CFG_RING3_1_NUM_DESCS_LSB
#define MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_MASK 		 RXDMA_CFG_RING3_1_NUM_DESCS_MASK
#define MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_GET(x) 		 RXDMA_CFG_RING3_1_NUM_DESCS_GET(x)
#define MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_SET(x) 		 RXDMA_CFG_RING3_1_NUM_DESCS_SET(x)
#define MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_RESET 		 RXDMA_CFG_RING3_1_NUM_DESCS_RESET
#define MAC_DMA_RCV_CFG_RING3_1_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_1_ADDRESS)
#define MAC_DMA_RCV_CFG_RING3_1_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_1_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING3_1_SW_MASK 		 RXDMA_CFG_RING3_1_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING3_1_RSTMASK 		 RXDMA_CFG_RING3_1_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING3_1_RESET 		 RXDMA_CFG_RING3_1_RESET

// 32'h0298 (MAC_DMA_RCV_CFG_RING3_2)
#define MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_MSB 		 RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_LSB 		 RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_MASK 		 RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_GET(x) 		 RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_SET(x) 		 RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_RESET 		 RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_MSB 		 RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_LSB 		 RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_MASK 		 RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_GET(x) 		 RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_SET(x) 		 RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_RESET 		 RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_MSB 		 RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_LSB 		 RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_MASK 		 RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_GET(x) 		 RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_SET(x) 		 RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_RESET 		 RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_MSB 		 RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_LSB 		 RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_MASK 		 RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_GET(x) 		 RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_SET(x) 		 RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_RESET 		 RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_MSB 		 RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_LSB 		 RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_MASK 		 RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_GET(x) 		 RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_SET(x) 		 RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_RESET 		 RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_MSB 		 RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_LSB 		 RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_MASK 		 RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_GET(x) 		 RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_SET(x) 		 RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_RESET 		 RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_MSB 		 RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_LSB 		 RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_MASK 		 RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_GET(x) 		 RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_SET(x) 		 RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_RESET 		 RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_MSB 		 RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_LSB 		 RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_MASK 		 RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_GET(x) 		 RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_SET(x) 		 RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_RESET 		 RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_MSB 		 RXDMA_CFG_RING3_2_RX_PACKET_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_LSB 		 RXDMA_CFG_RING3_2_RX_PACKET_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_MASK 		 RXDMA_CFG_RING3_2_RX_PACKET_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_GET(x) 		 RXDMA_CFG_RING3_2_RX_PACKET_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_SET(x) 		 RXDMA_CFG_RING3_2_RX_PACKET_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_RESET 		 RXDMA_CFG_RING3_2_RX_PACKET_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_MSB 		 RXDMA_CFG_RING3_2_RX_HEADER_SWAP_MSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_LSB 		 RXDMA_CFG_RING3_2_RX_HEADER_SWAP_LSB
#define MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_MASK 		 RXDMA_CFG_RING3_2_RX_HEADER_SWAP_MASK
#define MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_GET(x) 		 RXDMA_CFG_RING3_2_RX_HEADER_SWAP_GET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_SET(x) 		 RXDMA_CFG_RING3_2_RX_HEADER_SWAP_SET(x)
#define MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_RESET 		 RXDMA_CFG_RING3_2_RX_HEADER_SWAP_RESET
#define MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_MSB 		 RXDMA_CFG_RING3_2_INTR_LWM_THRESH_MSB
#define MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_LSB 		 RXDMA_CFG_RING3_2_INTR_LWM_THRESH_LSB
#define MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_MASK 		 RXDMA_CFG_RING3_2_INTR_LWM_THRESH_MASK
#define MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_GET(x) 		 RXDMA_CFG_RING3_2_INTR_LWM_THRESH_GET(x)
#define MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_SET(x) 		 RXDMA_CFG_RING3_2_INTR_LWM_THRESH_SET(x)
#define MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_RESET 		 RXDMA_CFG_RING3_2_INTR_LWM_THRESH_RESET
#define MAC_DMA_RCV_CFG_RING3_2_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_2_ADDRESS)
#define MAC_DMA_RCV_CFG_RING3_2_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_2_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING3_2_SW_MASK 		 RXDMA_CFG_RING3_2_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING3_2_RSTMASK 		 RXDMA_CFG_RING3_2_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING3_2_RESET 		 RXDMA_CFG_RING3_2_RESET

// 32'h029c (MAC_DMA_RCV_CFG_RING3_3)
#define MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_MSB 		 RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_LSB 		 RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_MASK 		 RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_GET(x) 		 RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_SET(x) 		 RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_RESET 		 RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_MSB 		 RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_LSB 		 RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_MASK 		 RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_GET(x) 		 RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_SET(x) 		 RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_RESET 		 RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING3_3_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_3_ADDRESS)
#define MAC_DMA_RCV_CFG_RING3_3_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_3_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING3_3_SW_MASK 		 RXDMA_CFG_RING3_3_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING3_3_RSTMASK 		 RXDMA_CFG_RING3_3_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING3_3_RESET 		 RXDMA_CFG_RING3_3_RESET

// 32'h02a0 (MAC_DMA_RCV_CFG_RING3_4)
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_MSB 		 RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_LSB 		 RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_MASK 		 RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_GET(x) 		 RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_SET(x) 		 RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_RESET 		 RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_MSB 		 RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_LSB 		 RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_MASK 		 RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_GET(x) 		 RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_SET(x) 		 RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_RESET 		 RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING3_4_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_4_ADDRESS)
#define MAC_DMA_RCV_CFG_RING3_4_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_4_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING3_4_SW_MASK 		 RXDMA_CFG_RING3_4_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING3_4_RSTMASK 		 RXDMA_CFG_RING3_4_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING3_4_RESET 		 RXDMA_CFG_RING3_4_RESET

// 32'h02a4 (MAC_DMA_RCV_CFG_RING3_5)
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_MSB 		 RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_LSB 		 RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_MASK 		 RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_GET(x) 		 RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_SET(x) 		 RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_RESET 		 RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_MSB 		 RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_LSB 		 RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_MASK 		 RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_GET(x) 		 RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_SET(x) 		 RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_RESET 		 RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING3_5_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_5_ADDRESS)
#define MAC_DMA_RCV_CFG_RING3_5_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_5_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING3_5_SW_MASK 		 RXDMA_CFG_RING3_5_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING3_5_RSTMASK 		 RXDMA_CFG_RING3_5_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING3_5_RESET 		 RXDMA_CFG_RING3_5_RESET

// 32'h02a8 (MAC_DMA_RCV_CFG_RING3_6)
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_MSB 		 RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_LSB 		 RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_MASK 		 RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_GET(x) 		 RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_SET(x) 		 RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_RESET 		 RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_MSB 		 RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_LSB 		 RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_MASK 		 RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_GET(x) 		 RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_SET(x) 		 RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_RESET 		 RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING3_6_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_6_ADDRESS)
#define MAC_DMA_RCV_CFG_RING3_6_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_6_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING3_6_SW_MASK 		 RXDMA_CFG_RING3_6_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING3_6_RSTMASK 		 RXDMA_CFG_RING3_6_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING3_6_RESET 		 RXDMA_CFG_RING3_6_RESET

// 32'h02ac (MAC_DMA_RCV_CFG_RING3_7)
#define MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_MSB 		 RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_LSB 		 RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_MASK 		 RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_GET(x) 		 RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_SET(x) 		 RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_RESET 		 RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_MSB 		 RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_MSB
#define MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_LSB 		 RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_LSB
#define MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_MASK 		 RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_MASK
#define MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_GET(x) 		 RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_GET(x)
#define MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_SET(x) 		 RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_SET(x)
#define MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_RESET 		 RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_RESET
#define MAC_DMA_RCV_CFG_RING3_7_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_7_ADDRESS)
#define MAC_DMA_RCV_CFG_RING3_7_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_RING3_7_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_RING3_7_SW_MASK 		 RXDMA_CFG_RING3_7_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_RING3_7_RSTMASK 		 RXDMA_CFG_RING3_7_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_RING3_7_RESET 		 RXDMA_CFG_RING3_7_RESET

// 32'h02c0 (MAC_DMA_RCV_EN_ACT_0)
#define MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_MSB 		 RXDMA_EN_ACT_0_RING_ACTIVE_MSB
#define MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_LSB 		 RXDMA_EN_ACT_0_RING_ACTIVE_LSB
#define MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_MASK 		 RXDMA_EN_ACT_0_RING_ACTIVE_MASK
#define MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_GET(x) 		 RXDMA_EN_ACT_0_RING_ACTIVE_GET(x)
#define MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_SET(x) 		 RXDMA_EN_ACT_0_RING_ACTIVE_SET(x)
#define MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_RESET 		 RXDMA_EN_ACT_0_RING_ACTIVE_RESET
#define MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_MSB 		 RXDMA_EN_ACT_0_RING_ENABLE_MSB
#define MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_LSB 		 RXDMA_EN_ACT_0_RING_ENABLE_LSB
#define MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_MASK 		 RXDMA_EN_ACT_0_RING_ENABLE_MASK
#define MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_GET(x) 		 RXDMA_EN_ACT_0_RING_ENABLE_GET(x)
#define MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_SET(x) 		 RXDMA_EN_ACT_0_RING_ENABLE_SET(x)
#define MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_RESET 		 RXDMA_EN_ACT_0_RING_ENABLE_RESET
#define MAC_DMA_RCV_EN_ACT_0_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_EN_ACT_0_ADDRESS)
#define MAC_DMA_RCV_EN_ACT_0_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_EN_ACT_0_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_EN_ACT_0_SW_MASK 		 RXDMA_EN_ACT_0_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_EN_ACT_0_RSTMASK 		 RXDMA_EN_ACT_0_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_EN_ACT_0_RESET 		 RXDMA_EN_ACT_0_RESET

// 32'h02c4 (MAC_DMA_RCV_EN_ACT_1)
#define MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_MSB 		 RXDMA_EN_ACT_1_RING_ACTIVE_MSB
#define MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_LSB 		 RXDMA_EN_ACT_1_RING_ACTIVE_LSB
#define MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_MASK 		 RXDMA_EN_ACT_1_RING_ACTIVE_MASK
#define MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_GET(x) 		 RXDMA_EN_ACT_1_RING_ACTIVE_GET(x)
#define MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_SET(x) 		 RXDMA_EN_ACT_1_RING_ACTIVE_SET(x)
#define MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_RESET 		 RXDMA_EN_ACT_1_RING_ACTIVE_RESET
#define MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_MSB 		 RXDMA_EN_ACT_1_RING_ENABLE_MSB
#define MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_LSB 		 RXDMA_EN_ACT_1_RING_ENABLE_LSB
#define MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_MASK 		 RXDMA_EN_ACT_1_RING_ENABLE_MASK
#define MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_GET(x) 		 RXDMA_EN_ACT_1_RING_ENABLE_GET(x)
#define MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_SET(x) 		 RXDMA_EN_ACT_1_RING_ENABLE_SET(x)
#define MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_RESET 		 RXDMA_EN_ACT_1_RING_ENABLE_RESET
#define MAC_DMA_RCV_EN_ACT_1_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_EN_ACT_1_ADDRESS)
#define MAC_DMA_RCV_EN_ACT_1_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_EN_ACT_1_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_EN_ACT_1_SW_MASK 		 RXDMA_EN_ACT_1_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_EN_ACT_1_RSTMASK 		 RXDMA_EN_ACT_1_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_EN_ACT_1_RESET 		 RXDMA_EN_ACT_1_RESET

// 32'h02c8 (MAC_DMA_RCV_EN_ACT_2)
#define MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_MSB 		 RXDMA_EN_ACT_2_RING_ACTIVE_MSB
#define MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_LSB 		 RXDMA_EN_ACT_2_RING_ACTIVE_LSB
#define MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_MASK 		 RXDMA_EN_ACT_2_RING_ACTIVE_MASK
#define MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_GET(x) 		 RXDMA_EN_ACT_2_RING_ACTIVE_GET(x)
#define MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_SET(x) 		 RXDMA_EN_ACT_2_RING_ACTIVE_SET(x)
#define MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_RESET 		 RXDMA_EN_ACT_2_RING_ACTIVE_RESET
#define MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_MSB 		 RXDMA_EN_ACT_2_RING_ENABLE_MSB
#define MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_LSB 		 RXDMA_EN_ACT_2_RING_ENABLE_LSB
#define MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_MASK 		 RXDMA_EN_ACT_2_RING_ENABLE_MASK
#define MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_GET(x) 		 RXDMA_EN_ACT_2_RING_ENABLE_GET(x)
#define MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_SET(x) 		 RXDMA_EN_ACT_2_RING_ENABLE_SET(x)
#define MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_RESET 		 RXDMA_EN_ACT_2_RING_ENABLE_RESET
#define MAC_DMA_RCV_EN_ACT_2_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_EN_ACT_2_ADDRESS)
#define MAC_DMA_RCV_EN_ACT_2_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_EN_ACT_2_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_EN_ACT_2_SW_MASK 		 RXDMA_EN_ACT_2_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_EN_ACT_2_RSTMASK 		 RXDMA_EN_ACT_2_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_EN_ACT_2_RESET 		 RXDMA_EN_ACT_2_RESET

// 32'h02cc (MAC_DMA_RCV_EN_ACT_3)
#define MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_MSB 		 RXDMA_EN_ACT_3_RING_ACTIVE_MSB
#define MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_LSB 		 RXDMA_EN_ACT_3_RING_ACTIVE_LSB
#define MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_MASK 		 RXDMA_EN_ACT_3_RING_ACTIVE_MASK
#define MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_GET(x) 		 RXDMA_EN_ACT_3_RING_ACTIVE_GET(x)
#define MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_SET(x) 		 RXDMA_EN_ACT_3_RING_ACTIVE_SET(x)
#define MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_RESET 		 RXDMA_EN_ACT_3_RING_ACTIVE_RESET
#define MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_MSB 		 RXDMA_EN_ACT_3_RING_ENABLE_MSB
#define MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_LSB 		 RXDMA_EN_ACT_3_RING_ENABLE_LSB
#define MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_MASK 		 RXDMA_EN_ACT_3_RING_ENABLE_MASK
#define MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_GET(x) 		 RXDMA_EN_ACT_3_RING_ENABLE_GET(x)
#define MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_SET(x) 		 RXDMA_EN_ACT_3_RING_ENABLE_SET(x)
#define MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_RESET 		 RXDMA_EN_ACT_3_RING_ENABLE_RESET
#define MAC_DMA_RCV_EN_ACT_3_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_EN_ACT_3_ADDRESS)
#define MAC_DMA_RCV_EN_ACT_3_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_EN_ACT_3_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_EN_ACT_3_SW_MASK 		 RXDMA_EN_ACT_3_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_EN_ACT_3_RSTMASK 		 RXDMA_EN_ACT_3_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_EN_ACT_3_RESET 		 RXDMA_EN_ACT_3_RESET

// 32'h02d0 (MAC_DMA_RCV_CFG_MISC_0)
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_MSB 		 RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_MSB
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_LSB 		 RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_LSB
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_MASK 		 RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_MASK
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_GET(x) 		 RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_GET(x)
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_SET(x) 		 RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_SET(x)
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_RESET 		 RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_RESET
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_MSB 		 RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_MSB
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_LSB 		 RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_LSB
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_MASK 		 RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_MASK
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_GET(x) 		 RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_GET(x)
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_SET(x) 		 RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_SET(x)
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_RESET 		 RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_RESET
#define MAC_DMA_RCV_CFG_MISC_0_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_MISC_0_ADDRESS)
#define MAC_DMA_RCV_CFG_MISC_0_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_MISC_0_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_MISC_0_SW_MASK 		 RXDMA_CFG_MISC_0_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_MISC_0_RSTMASK 		 RXDMA_CFG_MISC_0_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_MISC_0_RESET 		 RXDMA_CFG_MISC_0_RESET

// 32'h02d4 (MAC_DMA_RCV_CFG_MISC_1)
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_MSB 		 RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_MSB
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_LSB 		 RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_LSB
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_MASK 		 RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_MASK
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_GET(x) 		 RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_GET(x)
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_SET(x) 		 RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_SET(x)
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_RESET 		 RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_RESET
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_MSB 		 RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_MSB
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_LSB 		 RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_LSB
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_MASK 		 RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_MASK
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_GET(x) 		 RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_GET(x)
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_SET(x) 		 RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_SET(x)
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_RESET 		 RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_RESET
#define MAC_DMA_RCV_CFG_MISC_1_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_MISC_1_ADDRESS)
#define MAC_DMA_RCV_CFG_MISC_1_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_MISC_1_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_MISC_1_SW_MASK 		 RXDMA_CFG_MISC_1_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_MISC_1_RSTMASK 		 RXDMA_CFG_MISC_1_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_MISC_1_RESET 		 RXDMA_CFG_MISC_1_RESET

// 32'h02d8 (MAC_DMA_RCV_CFG_MISC_2)
#define MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_MSB 		 RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_MSB
#define MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_LSB 		 RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_LSB
#define MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_MASK 		 RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_MASK
#define MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_GET(x) 		 RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_GET(x)
#define MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_SET(x) 		 RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_SET(x)
#define MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_RESET 		 RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_RESET
#define MAC_DMA_RCV_CFG_MISC_2_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_MISC_2_ADDRESS)
#define MAC_DMA_RCV_CFG_MISC_2_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_CFG_MISC_2_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_CFG_MISC_2_SW_MASK 		 RXDMA_CFG_MISC_2_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_CFG_MISC_2_RSTMASK 		 RXDMA_CFG_MISC_2_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_CFG_MISC_2_RESET 		 RXDMA_CFG_MISC_2_RESET

// 32'h02e0 (MAC_DMA_RCV_IDX_0)
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_MSB 		 RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_MSB
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_LSB 		 RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_LSB
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_MASK 		 RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_MASK
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_GET(x) 		 RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_GET(x)
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_SET(x) 		 RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_SET(x)
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_RESET 		 RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_RESET
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_MSB 		 RXDMA_IDX_0_RING_HW_IDX_MSB
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_LSB 		 RXDMA_IDX_0_RING_HW_IDX_LSB
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_MASK 		 RXDMA_IDX_0_RING_HW_IDX_MASK
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_GET(x) 		 RXDMA_IDX_0_RING_HW_IDX_GET(x)
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_SET(x) 		 RXDMA_IDX_0_RING_HW_IDX_SET(x)
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_RESET 		 RXDMA_IDX_0_RING_HW_IDX_RESET
#define MAC_DMA_RCV_IDX_0_RING_FW_IDX_MSB 		 RXDMA_IDX_0_RING_FW_IDX_MSB
#define MAC_DMA_RCV_IDX_0_RING_FW_IDX_LSB 		 RXDMA_IDX_0_RING_FW_IDX_LSB
#define MAC_DMA_RCV_IDX_0_RING_FW_IDX_MASK 		 RXDMA_IDX_0_RING_FW_IDX_MASK
#define MAC_DMA_RCV_IDX_0_RING_FW_IDX_GET(x) 		 RXDMA_IDX_0_RING_FW_IDX_GET(x)
#define MAC_DMA_RCV_IDX_0_RING_FW_IDX_SET(x) 		 RXDMA_IDX_0_RING_FW_IDX_SET(x)
#define MAC_DMA_RCV_IDX_0_RING_FW_IDX_RESET 		 RXDMA_IDX_0_RING_FW_IDX_RESET
#define MAC_DMA_RCV_IDX_0_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_IDX_0_ADDRESS)
#define MAC_DMA_RCV_IDX_0_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_IDX_0_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_IDX_0_SW_MASK 		 RXDMA_IDX_0_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_IDX_0_RSTMASK 		 RXDMA_IDX_0_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_IDX_0_RESET 		 RXDMA_IDX_0_RESET

// 32'h02e4 (MAC_DMA_RCV_IDX_1)
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_MSB 		 RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_MSB
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_LSB 		 RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_LSB
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_MASK 		 RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_MASK
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_GET(x) 		 RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_GET(x)
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_SET(x) 		 RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_SET(x)
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_RESET 		 RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_RESET
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_MSB 		 RXDMA_IDX_1_RING_HW_IDX_MSB
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_LSB 		 RXDMA_IDX_1_RING_HW_IDX_LSB
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_MASK 		 RXDMA_IDX_1_RING_HW_IDX_MASK
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_GET(x) 		 RXDMA_IDX_1_RING_HW_IDX_GET(x)
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_SET(x) 		 RXDMA_IDX_1_RING_HW_IDX_SET(x)
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_RESET 		 RXDMA_IDX_1_RING_HW_IDX_RESET
#define MAC_DMA_RCV_IDX_1_RING_FW_IDX_MSB 		 RXDMA_IDX_1_RING_FW_IDX_MSB
#define MAC_DMA_RCV_IDX_1_RING_FW_IDX_LSB 		 RXDMA_IDX_1_RING_FW_IDX_LSB
#define MAC_DMA_RCV_IDX_1_RING_FW_IDX_MASK 		 RXDMA_IDX_1_RING_FW_IDX_MASK
#define MAC_DMA_RCV_IDX_1_RING_FW_IDX_GET(x) 		 RXDMA_IDX_1_RING_FW_IDX_GET(x)
#define MAC_DMA_RCV_IDX_1_RING_FW_IDX_SET(x) 		 RXDMA_IDX_1_RING_FW_IDX_SET(x)
#define MAC_DMA_RCV_IDX_1_RING_FW_IDX_RESET 		 RXDMA_IDX_1_RING_FW_IDX_RESET
#define MAC_DMA_RCV_IDX_1_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_IDX_1_ADDRESS)
#define MAC_DMA_RCV_IDX_1_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_IDX_1_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_IDX_1_SW_MASK 		 RXDMA_IDX_1_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_IDX_1_RSTMASK 		 RXDMA_IDX_1_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_IDX_1_RESET 		 RXDMA_IDX_1_RESET

// 32'h02e8 (MAC_DMA_RCV_IDX_2)
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_MSB 		 RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_MSB
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_LSB 		 RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_LSB
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_MASK 		 RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_MASK
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_GET(x) 		 RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_GET(x)
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_SET(x) 		 RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_SET(x)
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_RESET 		 RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_RESET
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_MSB 		 RXDMA_IDX_2_RING_HW_IDX_MSB
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_LSB 		 RXDMA_IDX_2_RING_HW_IDX_LSB
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_MASK 		 RXDMA_IDX_2_RING_HW_IDX_MASK
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_GET(x) 		 RXDMA_IDX_2_RING_HW_IDX_GET(x)
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_SET(x) 		 RXDMA_IDX_2_RING_HW_IDX_SET(x)
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_RESET 		 RXDMA_IDX_2_RING_HW_IDX_RESET
#define MAC_DMA_RCV_IDX_2_RING_FW_IDX_MSB 		 RXDMA_IDX_2_RING_FW_IDX_MSB
#define MAC_DMA_RCV_IDX_2_RING_FW_IDX_LSB 		 RXDMA_IDX_2_RING_FW_IDX_LSB
#define MAC_DMA_RCV_IDX_2_RING_FW_IDX_MASK 		 RXDMA_IDX_2_RING_FW_IDX_MASK
#define MAC_DMA_RCV_IDX_2_RING_FW_IDX_GET(x) 		 RXDMA_IDX_2_RING_FW_IDX_GET(x)
#define MAC_DMA_RCV_IDX_2_RING_FW_IDX_SET(x) 		 RXDMA_IDX_2_RING_FW_IDX_SET(x)
#define MAC_DMA_RCV_IDX_2_RING_FW_IDX_RESET 		 RXDMA_IDX_2_RING_FW_IDX_RESET
#define MAC_DMA_RCV_IDX_2_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_IDX_2_ADDRESS)
#define MAC_DMA_RCV_IDX_2_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_IDX_2_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_IDX_2_SW_MASK 		 RXDMA_IDX_2_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_IDX_2_RSTMASK 		 RXDMA_IDX_2_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_IDX_2_RESET 		 RXDMA_IDX_2_RESET

// 32'h02ec (MAC_DMA_RCV_IDX_3)
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_MSB 		 RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_MSB
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_LSB 		 RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_LSB
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_MASK 		 RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_MASK
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_GET(x) 		 RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_GET(x)
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_SET(x) 		 RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_SET(x)
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_RESET 		 RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_RESET
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_MSB 		 RXDMA_IDX_3_RING_HW_IDX_MSB
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_LSB 		 RXDMA_IDX_3_RING_HW_IDX_LSB
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_MASK 		 RXDMA_IDX_3_RING_HW_IDX_MASK
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_GET(x) 		 RXDMA_IDX_3_RING_HW_IDX_GET(x)
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_SET(x) 		 RXDMA_IDX_3_RING_HW_IDX_SET(x)
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_RESET 		 RXDMA_IDX_3_RING_HW_IDX_RESET
#define MAC_DMA_RCV_IDX_3_RING_FW_IDX_MSB 		 RXDMA_IDX_3_RING_FW_IDX_MSB
#define MAC_DMA_RCV_IDX_3_RING_FW_IDX_LSB 		 RXDMA_IDX_3_RING_FW_IDX_LSB
#define MAC_DMA_RCV_IDX_3_RING_FW_IDX_MASK 		 RXDMA_IDX_3_RING_FW_IDX_MASK
#define MAC_DMA_RCV_IDX_3_RING_FW_IDX_GET(x) 		 RXDMA_IDX_3_RING_FW_IDX_GET(x)
#define MAC_DMA_RCV_IDX_3_RING_FW_IDX_SET(x) 		 RXDMA_IDX_3_RING_FW_IDX_SET(x)
#define MAC_DMA_RCV_IDX_3_RING_FW_IDX_RESET 		 RXDMA_IDX_3_RING_FW_IDX_RESET
#define MAC_DMA_RCV_IDX_3_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_IDX_3_ADDRESS)
#define MAC_DMA_RCV_IDX_3_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_IDX_3_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_IDX_3_SW_MASK 		 RXDMA_IDX_3_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_IDX_3_RSTMASK 		 RXDMA_IDX_3_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_IDX_3_RESET 		 RXDMA_IDX_3_RESET

// 32'h02f0 (MAC_DMA_RCV_GLOBAL_RER)
#define MAC_DMA_RCV_GLOBAL_RER_ENABLE_MSB 		 RXDMA_GLOBAL_RER_ENABLE_MSB
#define MAC_DMA_RCV_GLOBAL_RER_ENABLE_LSB 		 RXDMA_GLOBAL_RER_ENABLE_LSB
#define MAC_DMA_RCV_GLOBAL_RER_ENABLE_MASK 		 RXDMA_GLOBAL_RER_ENABLE_MASK
#define MAC_DMA_RCV_GLOBAL_RER_ENABLE_GET(x) 		 RXDMA_GLOBAL_RER_ENABLE_GET(x)
#define MAC_DMA_RCV_GLOBAL_RER_ENABLE_SET(x) 		 RXDMA_GLOBAL_RER_ENABLE_SET(x)
#define MAC_DMA_RCV_GLOBAL_RER_ENABLE_RESET 		 RXDMA_GLOBAL_RER_ENABLE_RESET
#define MAC_DMA_RCV_GLOBAL_RER_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_GLOBAL_RER_ADDRESS)
#define MAC_DMA_RCV_GLOBAL_RER_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_GLOBAL_RER_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_GLOBAL_RER_SW_MASK 		 RXDMA_GLOBAL_RER_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_GLOBAL_RER_RSTMASK 		 RXDMA_GLOBAL_RER_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_GLOBAL_RER_RESET 		 RXDMA_GLOBAL_RER_RESET

// 32'h02fc (MAC_DMA_RCV_OBS_BUS)
#define MAC_DMA_RCV_OBS_BUS_VALUE_MSB 		 RXDMA_TESTBUS_SAMPLE_VALUE_MSB
#define MAC_DMA_RCV_OBS_BUS_VALUE_LSB 		 RXDMA_TESTBUS_SAMPLE_VALUE_LSB
#define MAC_DMA_RCV_OBS_BUS_VALUE_MASK 		 RXDMA_TESTBUS_SAMPLE_VALUE_MASK
#define MAC_DMA_RCV_OBS_BUS_VALUE_GET(x) 		 RXDMA_TESTBUS_SAMPLE_VALUE_GET(x)
#define MAC_DMA_RCV_OBS_BUS_VALUE_SET(x) 		 RXDMA_TESTBUS_SAMPLE_VALUE_SET(x)
#define MAC_DMA_RCV_OBS_BUS_VALUE_RESET 		 RXDMA_TESTBUS_SAMPLE_VALUE_RESET
#define MAC_DMA_RCV_OBS_BUS_ADDRESS 		 (RXDMA_BASE_ADDRESS+RXDMA_TESTBUS_SAMPLE_ADDRESS)
#define MAC_DMA_RCV_OBS_BUS_OFFSET 		 (RXDMA_BASE_ADDRESS+RXDMA_TESTBUS_SAMPLE_OFFSET)
// SW modifiable bits
#define MAC_DMA_RCV_OBS_BUS_SW_MASK 		 RXDMA_TESTBUS_SAMPLE_SW_MASK
// bits defined at reset
#define MAC_DMA_RCV_OBS_BUS_RSTMASK 		 RXDMA_TESTBUS_SAMPLE_RSTMASK
// reset value (ignore bits undefined at reset)
#define MAC_DMA_RCV_OBS_BUS_RESET 		 RXDMA_TESTBUS_SAMPLE_RESET

// 32'h0300 (MAC_TRC)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_OBS_BUS_SEL_MSB 		 MAC_TRC_OBS_BUS_SEL_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_OBS_BUS_SEL_LSB 		 MAC_TRC_OBS_BUS_SEL_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_OBS_BUS_SEL_MASK 		 MAC_TRC_OBS_BUS_SEL_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_OBS_BUS_SEL_GET(x) 		 MAC_TRC_OBS_BUS_SEL_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_OBS_BUS_SEL_SET(x) 		 MAC_TRC_OBS_BUS_SEL_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_OBS_BUS_SEL_RESET 		 MAC_TRC_OBS_BUS_SEL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_MAC_MODULE_SEL_MSB 		 MAC_TRC_MAC_MODULE_SEL_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_MAC_MODULE_SEL_LSB 		 MAC_TRC_MAC_MODULE_SEL_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_MAC_MODULE_SEL_MASK 		 MAC_TRC_MAC_MODULE_SEL_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_MAC_MODULE_SEL_GET(x) 		 MAC_TRC_MAC_MODULE_SEL_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_MAC_MODULE_SEL_SET(x) 		 MAC_TRC_MAC_MODULE_SEL_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_MAC_MODULE_SEL_RESET 		 MAC_TRC_MAC_MODULE_SEL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ACCESS_EN_VALUE_MSB 		 MAC_TRC_CPU_ACCESS_EN_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ACCESS_EN_VALUE_LSB 		 MAC_TRC_CPU_ACCESS_EN_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ACCESS_EN_VALUE_MASK 		 MAC_TRC_CPU_ACCESS_EN_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ACCESS_EN_VALUE_GET(x) 		 MAC_TRC_CPU_ACCESS_EN_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ACCESS_EN_VALUE_SET(x) 		 MAC_TRC_CPU_ACCESS_EN_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ACCESS_EN_VALUE_RESET 		 MAC_TRC_CPU_ACCESS_EN_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_CFG_VALUE_MSB 		 MAC_TRC_BUF_CFG_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_CFG_VALUE_LSB 		 MAC_TRC_BUF_CFG_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_CFG_VALUE_MASK 		 MAC_TRC_BUF_CFG_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_CFG_VALUE_GET(x) 		 MAC_TRC_BUF_CFG_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_CFG_VALUE_SET(x) 		 MAC_TRC_BUF_CFG_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_CFG_VALUE_RESET 		 MAC_TRC_BUF_CFG_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ENABLE_VALUE_MSB 		 MAC_TRC_ENABLE_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ENABLE_VALUE_LSB 		 MAC_TRC_ENABLE_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ENABLE_VALUE_MASK 		 MAC_TRC_ENABLE_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ENABLE_VALUE_GET(x) 		 MAC_TRC_ENABLE_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ENABLE_VALUE_SET(x) 		 MAC_TRC_ENABLE_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ENABLE_VALUE_RESET 		 MAC_TRC_ENABLE_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDRESS 		 MAC_TRC_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDRESS 		 MAC_TRC_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_OFFSET 		 MAC_TRC_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_SW_MASK 		 MAC_TRC_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_RSTMASK 		 MAC_TRC_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_RESET 		 MAC_TRC_RESET

// 32'h0304 (MAC_TRC_BUF_INIT)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_VALUE_MSB 		 MAC_TRC_BUF_INIT_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_VALUE_MSB 		 MAC_TRC_BUF_INIT_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_VALUE_LSB 		 MAC_TRC_BUF_INIT_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_VALUE_LSB 		 MAC_TRC_BUF_INIT_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_VALUE_MASK 		 MAC_TRC_BUF_INIT_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_VALUE_MASK 		 MAC_TRC_BUF_INIT_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_VALUE_GET(x) 		 MAC_TRC_BUF_INIT_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_VALUE_GET(x) 		 MAC_TRC_BUF_INIT_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_VALUE_SET(x) 		 MAC_TRC_BUF_INIT_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_VALUE_SET(x) 		 MAC_TRC_BUF_INIT_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_VALUE_RESET 		 MAC_TRC_BUF_INIT_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_VALUE_RESET 		 MAC_TRC_BUF_INIT_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_ADDRESS 		 MAC_TRC_BUF_INIT_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_ADDRESS 		 MAC_TRC_BUF_INIT_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_OFFSET 		 MAC_TRC_BUF_INIT_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_OFFSET 		 MAC_TRC_BUF_INIT_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_SW_MASK 		 MAC_TRC_BUF_INIT_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_SW_MASK 		 MAC_TRC_BUF_INIT_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_RSTMASK 		 MAC_TRC_BUF_INIT_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_RSTMASK 		 MAC_TRC_BUF_INIT_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_RESET 		 MAC_TRC_BUF_INIT_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_BUF_INIT_RESET 		 MAC_TRC_BUF_INIT_RESET

// 32'h0308 (MAC_TRC_ADDR)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_END_VALUE_MSB 		 MAC_TRC_ADDR_END_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_END_VALUE_MSB 		 MAC_TRC_ADDR_END_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_END_VALUE_LSB 		 MAC_TRC_ADDR_END_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_END_VALUE_LSB 		 MAC_TRC_ADDR_END_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_END_VALUE_MASK 		 MAC_TRC_ADDR_END_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_END_VALUE_MASK 		 MAC_TRC_ADDR_END_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_END_VALUE_GET(x) 		 MAC_TRC_ADDR_END_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_END_VALUE_GET(x) 		 MAC_TRC_ADDR_END_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_END_VALUE_SET(x) 		 MAC_TRC_ADDR_END_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_END_VALUE_SET(x) 		 MAC_TRC_ADDR_END_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_END_VALUE_RESET 		 MAC_TRC_ADDR_END_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_END_VALUE_RESET 		 MAC_TRC_ADDR_END_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_START_VALUE_MSB 		 MAC_TRC_ADDR_START_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_START_VALUE_MSB 		 MAC_TRC_ADDR_START_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_START_VALUE_LSB 		 MAC_TRC_ADDR_START_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_START_VALUE_LSB 		 MAC_TRC_ADDR_START_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_START_VALUE_MASK 		 MAC_TRC_ADDR_START_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_START_VALUE_MASK 		 MAC_TRC_ADDR_START_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_START_VALUE_GET(x) 		 MAC_TRC_ADDR_START_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_START_VALUE_GET(x) 		 MAC_TRC_ADDR_START_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_START_VALUE_SET(x) 		 MAC_TRC_ADDR_START_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_START_VALUE_SET(x) 		 MAC_TRC_ADDR_START_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_START_VALUE_RESET 		 MAC_TRC_ADDR_START_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_START_VALUE_RESET 		 MAC_TRC_ADDR_START_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_ADDRESS 		 MAC_TRC_ADDR_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_ADDRESS 		 MAC_TRC_ADDR_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_OFFSET 		 MAC_TRC_ADDR_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_OFFSET 		 MAC_TRC_ADDR_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_SW_MASK 		 MAC_TRC_ADDR_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_SW_MASK 		 MAC_TRC_ADDR_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_RSTMASK 		 MAC_TRC_ADDR_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_RSTMASK 		 MAC_TRC_ADDR_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_RESET 		 MAC_TRC_ADDR_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_ADDR_RESET 		 MAC_TRC_ADDR_RESET

// 32'h030c (MAC_TRC_WFT_CAPTURE_CTRL)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_MSB 		 MAC_TRC_WFT_CAPTURE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_MSB 		 MAC_TRC_WFT_CAPTURE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_LSB 		 MAC_TRC_WFT_CAPTURE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_LSB 		 MAC_TRC_WFT_CAPTURE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_MASK 		 MAC_TRC_WFT_CAPTURE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_MASK 		 MAC_TRC_WFT_CAPTURE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_GET(x) 		 MAC_TRC_WFT_CAPTURE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_GET(x) 		 MAC_TRC_WFT_CAPTURE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_SET(x) 		 MAC_TRC_WFT_CAPTURE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_SET(x) 		 MAC_TRC_WFT_CAPTURE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_RESET 		 MAC_TRC_WFT_CAPTURE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_RESET 		 MAC_TRC_WFT_CAPTURE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_ADDRESS 		 MAC_TRC_WFT_CAPTURE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_ADDRESS 		 MAC_TRC_WFT_CAPTURE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_OFFSET 		 MAC_TRC_WFT_CAPTURE_CTRL_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_OFFSET 		 MAC_TRC_WFT_CAPTURE_CTRL_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_SW_MASK 		 MAC_TRC_WFT_CAPTURE_CTRL_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_SW_MASK 		 MAC_TRC_WFT_CAPTURE_CTRL_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_RSTMASK 		 MAC_TRC_WFT_CAPTURE_CTRL_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_RSTMASK 		 MAC_TRC_WFT_CAPTURE_CTRL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_RESET 		 MAC_TRC_WFT_CAPTURE_CTRL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_CAPTURE_CTRL_RESET 		 MAC_TRC_WFT_CAPTURE_CTRL_RESET

// 32'h0310 (MAC_TRC_WFT_STATE_CTRL)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_VALUE_MSB 		 MAC_TRC_WFT_STATE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_VALUE_MSB 		 MAC_TRC_WFT_STATE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_VALUE_LSB 		 MAC_TRC_WFT_STATE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_VALUE_LSB 		 MAC_TRC_WFT_STATE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_VALUE_MASK 		 MAC_TRC_WFT_STATE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_VALUE_MASK 		 MAC_TRC_WFT_STATE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_VALUE_GET(x) 		 MAC_TRC_WFT_STATE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_VALUE_GET(x) 		 MAC_TRC_WFT_STATE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_VALUE_SET(x) 		 MAC_TRC_WFT_STATE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_VALUE_SET(x) 		 MAC_TRC_WFT_STATE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_VALUE_RESET 		 MAC_TRC_WFT_STATE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_VALUE_RESET 		 MAC_TRC_WFT_STATE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_ADDRESS 		 MAC_TRC_WFT_STATE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_ADDRESS 		 MAC_TRC_WFT_STATE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_OFFSET 		 MAC_TRC_WFT_STATE_CTRL_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_OFFSET 		 MAC_TRC_WFT_STATE_CTRL_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_SW_MASK 		 MAC_TRC_WFT_STATE_CTRL_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_SW_MASK 		 MAC_TRC_WFT_STATE_CTRL_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_RSTMASK 		 MAC_TRC_WFT_STATE_CTRL_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_RSTMASK 		 MAC_TRC_WFT_STATE_CTRL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_RESET 		 MAC_TRC_WFT_STATE_CTRL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_WFT_STATE_CTRL_RESET 		 MAC_TRC_WFT_STATE_CTRL_RESET

// 32'h0314 (MAC_TRC_TS1_CAPTURE_CTRL)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_MSB 		 MAC_TRC_TS1_CAPTURE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_MSB 		 MAC_TRC_TS1_CAPTURE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_LSB 		 MAC_TRC_TS1_CAPTURE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_LSB 		 MAC_TRC_TS1_CAPTURE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_MASK 		 MAC_TRC_TS1_CAPTURE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_MASK 		 MAC_TRC_TS1_CAPTURE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS1_CAPTURE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS1_CAPTURE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS1_CAPTURE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS1_CAPTURE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_RESET 		 MAC_TRC_TS1_CAPTURE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_RESET 		 MAC_TRC_TS1_CAPTURE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_ADDRESS 		 MAC_TRC_TS1_CAPTURE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_ADDRESS 		 MAC_TRC_TS1_CAPTURE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_OFFSET 		 MAC_TRC_TS1_CAPTURE_CTRL_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_OFFSET 		 MAC_TRC_TS1_CAPTURE_CTRL_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_SW_MASK 		 MAC_TRC_TS1_CAPTURE_CTRL_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_SW_MASK 		 MAC_TRC_TS1_CAPTURE_CTRL_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_RSTMASK 		 MAC_TRC_TS1_CAPTURE_CTRL_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_RSTMASK 		 MAC_TRC_TS1_CAPTURE_CTRL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_RESET 		 MAC_TRC_TS1_CAPTURE_CTRL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_CAPTURE_CTRL_RESET 		 MAC_TRC_TS1_CAPTURE_CTRL_RESET

// 32'h0318 (MAC_TRC_TS1_STATE_CTRL)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_VALUE_MSB 		 MAC_TRC_TS1_STATE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_VALUE_MSB 		 MAC_TRC_TS1_STATE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_VALUE_LSB 		 MAC_TRC_TS1_STATE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_VALUE_LSB 		 MAC_TRC_TS1_STATE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_VALUE_MASK 		 MAC_TRC_TS1_STATE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_VALUE_MASK 		 MAC_TRC_TS1_STATE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS1_STATE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS1_STATE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS1_STATE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS1_STATE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_VALUE_RESET 		 MAC_TRC_TS1_STATE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_VALUE_RESET 		 MAC_TRC_TS1_STATE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_ADDRESS 		 MAC_TRC_TS1_STATE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_ADDRESS 		 MAC_TRC_TS1_STATE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_OFFSET 		 MAC_TRC_TS1_STATE_CTRL_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_OFFSET 		 MAC_TRC_TS1_STATE_CTRL_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_SW_MASK 		 MAC_TRC_TS1_STATE_CTRL_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_SW_MASK 		 MAC_TRC_TS1_STATE_CTRL_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_RSTMASK 		 MAC_TRC_TS1_STATE_CTRL_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_RSTMASK 		 MAC_TRC_TS1_STATE_CTRL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_RESET 		 MAC_TRC_TS1_STATE_CTRL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_STATE_CTRL_RESET 		 MAC_TRC_TS1_STATE_CTRL_RESET

// 32'h031c (MAC_TRC_TS1_TRIG_MASK)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS1_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS1_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS1_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS1_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS1_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS1_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS1_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS1_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS1_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS1_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS1_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS1_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS1_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS1_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS1_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS1_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS1_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS1_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_ADDRESS 		 MAC_TRC_TS1_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_ADDRESS 		 MAC_TRC_TS1_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_ADDRESS 		 MAC_TRC_TS1_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_OFFSET 		 MAC_TRC_TS1_TRIG_MASK_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_OFFSET 		 MAC_TRC_TS1_TRIG_MASK_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_OFFSET 		 MAC_TRC_TS1_TRIG_MASK_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_SW_MASK 		 MAC_TRC_TS1_TRIG_MASK_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_SW_MASK 		 MAC_TRC_TS1_TRIG_MASK_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_SW_MASK 		 MAC_TRC_TS1_TRIG_MASK_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_RSTMASK 		 MAC_TRC_TS1_TRIG_MASK_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_RSTMASK 		 MAC_TRC_TS1_TRIG_MASK_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_RSTMASK 		 MAC_TRC_TS1_TRIG_MASK_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_RESET 		 MAC_TRC_TS1_TRIG_MASK_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_RESET 		 MAC_TRC_TS1_TRIG_MASK_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_MASK_RESET 		 MAC_TRC_TS1_TRIG_MASK_RESET

// 32'h0320 (MAC_TRC_TS1_TRIG)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_VALUE_MSB 		 MAC_TRC_TS1_TRIG_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_VALUE_MSB 		 MAC_TRC_TS1_TRIG_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_VALUE_LSB 		 MAC_TRC_TS1_TRIG_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_VALUE_LSB 		 MAC_TRC_TS1_TRIG_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_VALUE_MASK 		 MAC_TRC_TS1_TRIG_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_VALUE_MASK 		 MAC_TRC_TS1_TRIG_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_VALUE_GET(x) 		 MAC_TRC_TS1_TRIG_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_VALUE_GET(x) 		 MAC_TRC_TS1_TRIG_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_VALUE_SET(x) 		 MAC_TRC_TS1_TRIG_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_VALUE_SET(x) 		 MAC_TRC_TS1_TRIG_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_VALUE_RESET 		 MAC_TRC_TS1_TRIG_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_VALUE_RESET 		 MAC_TRC_TS1_TRIG_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_ADDRESS 		 MAC_TRC_TS1_TRIG_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_ADDRESS 		 MAC_TRC_TS1_TRIG_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_OFFSET 		 MAC_TRC_TS1_TRIG_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_OFFSET 		 MAC_TRC_TS1_TRIG_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_SW_MASK 		 MAC_TRC_TS1_TRIG_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_SW_MASK 		 MAC_TRC_TS1_TRIG_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_RSTMASK 		 MAC_TRC_TS1_TRIG_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_RSTMASK 		 MAC_TRC_TS1_TRIG_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_RESET 		 MAC_TRC_TS1_TRIG_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS1_TRIG_RESET 		 MAC_TRC_TS1_TRIG_RESET

// 32'h0324 (MAC_TRC_TS2_CAPTURE_CTRL)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_MSB 		 MAC_TRC_TS2_CAPTURE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_MSB 		 MAC_TRC_TS2_CAPTURE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_LSB 		 MAC_TRC_TS2_CAPTURE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_LSB 		 MAC_TRC_TS2_CAPTURE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_MASK 		 MAC_TRC_TS2_CAPTURE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_MASK 		 MAC_TRC_TS2_CAPTURE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS2_CAPTURE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS2_CAPTURE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS2_CAPTURE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS2_CAPTURE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_RESET 		 MAC_TRC_TS2_CAPTURE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_RESET 		 MAC_TRC_TS2_CAPTURE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_ADDRESS 		 MAC_TRC_TS2_CAPTURE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_ADDRESS 		 MAC_TRC_TS2_CAPTURE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_OFFSET 		 MAC_TRC_TS2_CAPTURE_CTRL_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_OFFSET 		 MAC_TRC_TS2_CAPTURE_CTRL_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_SW_MASK 		 MAC_TRC_TS2_CAPTURE_CTRL_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_SW_MASK 		 MAC_TRC_TS2_CAPTURE_CTRL_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_RSTMASK 		 MAC_TRC_TS2_CAPTURE_CTRL_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_RSTMASK 		 MAC_TRC_TS2_CAPTURE_CTRL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_RESET 		 MAC_TRC_TS2_CAPTURE_CTRL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_CAPTURE_CTRL_RESET 		 MAC_TRC_TS2_CAPTURE_CTRL_RESET

// 32'h0328 (MAC_TRC_TS2_STATE_CTRL)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_VALUE_MSB 		 MAC_TRC_TS2_STATE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_VALUE_MSB 		 MAC_TRC_TS2_STATE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_VALUE_LSB 		 MAC_TRC_TS2_STATE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_VALUE_LSB 		 MAC_TRC_TS2_STATE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_VALUE_MASK 		 MAC_TRC_TS2_STATE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_VALUE_MASK 		 MAC_TRC_TS2_STATE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS2_STATE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS2_STATE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS2_STATE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS2_STATE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_VALUE_RESET 		 MAC_TRC_TS2_STATE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_VALUE_RESET 		 MAC_TRC_TS2_STATE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_ADDRESS 		 MAC_TRC_TS2_STATE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_ADDRESS 		 MAC_TRC_TS2_STATE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_OFFSET 		 MAC_TRC_TS2_STATE_CTRL_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_OFFSET 		 MAC_TRC_TS2_STATE_CTRL_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_SW_MASK 		 MAC_TRC_TS2_STATE_CTRL_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_SW_MASK 		 MAC_TRC_TS2_STATE_CTRL_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_RSTMASK 		 MAC_TRC_TS2_STATE_CTRL_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_RSTMASK 		 MAC_TRC_TS2_STATE_CTRL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_RESET 		 MAC_TRC_TS2_STATE_CTRL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_STATE_CTRL_RESET 		 MAC_TRC_TS2_STATE_CTRL_RESET

// 32'h032c (MAC_TRC_TS2_TRIG_MASK)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS2_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS2_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS2_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS2_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS2_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS2_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS2_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS2_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS2_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS2_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS2_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS2_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS2_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS2_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS2_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS2_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS2_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS2_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_ADDRESS 		 MAC_TRC_TS2_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_ADDRESS 		 MAC_TRC_TS2_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_ADDRESS 		 MAC_TRC_TS2_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_OFFSET 		 MAC_TRC_TS2_TRIG_MASK_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_OFFSET 		 MAC_TRC_TS2_TRIG_MASK_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_OFFSET 		 MAC_TRC_TS2_TRIG_MASK_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_SW_MASK 		 MAC_TRC_TS2_TRIG_MASK_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_SW_MASK 		 MAC_TRC_TS2_TRIG_MASK_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_SW_MASK 		 MAC_TRC_TS2_TRIG_MASK_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_RSTMASK 		 MAC_TRC_TS2_TRIG_MASK_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_RSTMASK 		 MAC_TRC_TS2_TRIG_MASK_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_RSTMASK 		 MAC_TRC_TS2_TRIG_MASK_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_RESET 		 MAC_TRC_TS2_TRIG_MASK_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_RESET 		 MAC_TRC_TS2_TRIG_MASK_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_MASK_RESET 		 MAC_TRC_TS2_TRIG_MASK_RESET

// 32'h0330 (MAC_TRC_TS2_TRIG)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_VALUE_MSB 		 MAC_TRC_TS2_TRIG_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_VALUE_MSB 		 MAC_TRC_TS2_TRIG_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_VALUE_LSB 		 MAC_TRC_TS2_TRIG_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_VALUE_LSB 		 MAC_TRC_TS2_TRIG_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_VALUE_MASK 		 MAC_TRC_TS2_TRIG_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_VALUE_MASK 		 MAC_TRC_TS2_TRIG_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_VALUE_GET(x) 		 MAC_TRC_TS2_TRIG_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_VALUE_GET(x) 		 MAC_TRC_TS2_TRIG_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_VALUE_SET(x) 		 MAC_TRC_TS2_TRIG_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_VALUE_SET(x) 		 MAC_TRC_TS2_TRIG_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_VALUE_RESET 		 MAC_TRC_TS2_TRIG_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_VALUE_RESET 		 MAC_TRC_TS2_TRIG_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_ADDRESS 		 MAC_TRC_TS2_TRIG_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_ADDRESS 		 MAC_TRC_TS2_TRIG_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_OFFSET 		 MAC_TRC_TS2_TRIG_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_OFFSET 		 MAC_TRC_TS2_TRIG_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_SW_MASK 		 MAC_TRC_TS2_TRIG_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_SW_MASK 		 MAC_TRC_TS2_TRIG_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_RSTMASK 		 MAC_TRC_TS2_TRIG_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_RSTMASK 		 MAC_TRC_TS2_TRIG_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_RESET 		 MAC_TRC_TS2_TRIG_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS2_TRIG_RESET 		 MAC_TRC_TS2_TRIG_RESET

// 32'h0334 (MAC_TRC_TS3_CAPTURE_CTRL)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_MSB 		 MAC_TRC_TS3_CAPTURE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_MSB 		 MAC_TRC_TS3_CAPTURE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_LSB 		 MAC_TRC_TS3_CAPTURE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_LSB 		 MAC_TRC_TS3_CAPTURE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_MASK 		 MAC_TRC_TS3_CAPTURE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_MASK 		 MAC_TRC_TS3_CAPTURE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS3_CAPTURE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS3_CAPTURE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS3_CAPTURE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS3_CAPTURE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_RESET 		 MAC_TRC_TS3_CAPTURE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_RESET 		 MAC_TRC_TS3_CAPTURE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_ADDRESS 		 MAC_TRC_TS3_CAPTURE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_ADDRESS 		 MAC_TRC_TS3_CAPTURE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_OFFSET 		 MAC_TRC_TS3_CAPTURE_CTRL_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_OFFSET 		 MAC_TRC_TS3_CAPTURE_CTRL_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_SW_MASK 		 MAC_TRC_TS3_CAPTURE_CTRL_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_SW_MASK 		 MAC_TRC_TS3_CAPTURE_CTRL_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_RSTMASK 		 MAC_TRC_TS3_CAPTURE_CTRL_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_RSTMASK 		 MAC_TRC_TS3_CAPTURE_CTRL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_RESET 		 MAC_TRC_TS3_CAPTURE_CTRL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_CAPTURE_CTRL_RESET 		 MAC_TRC_TS3_CAPTURE_CTRL_RESET

// 32'h0338 (MAC_TRC_TS3_STATE_CTRL)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_VALUE_MSB 		 MAC_TRC_TS3_STATE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_VALUE_MSB 		 MAC_TRC_TS3_STATE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_VALUE_LSB 		 MAC_TRC_TS3_STATE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_VALUE_LSB 		 MAC_TRC_TS3_STATE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_VALUE_MASK 		 MAC_TRC_TS3_STATE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_VALUE_MASK 		 MAC_TRC_TS3_STATE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS3_STATE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS3_STATE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS3_STATE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS3_STATE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_VALUE_RESET 		 MAC_TRC_TS3_STATE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_VALUE_RESET 		 MAC_TRC_TS3_STATE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_ADDRESS 		 MAC_TRC_TS3_STATE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_ADDRESS 		 MAC_TRC_TS3_STATE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_OFFSET 		 MAC_TRC_TS3_STATE_CTRL_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_OFFSET 		 MAC_TRC_TS3_STATE_CTRL_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_SW_MASK 		 MAC_TRC_TS3_STATE_CTRL_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_SW_MASK 		 MAC_TRC_TS3_STATE_CTRL_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_RSTMASK 		 MAC_TRC_TS3_STATE_CTRL_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_RSTMASK 		 MAC_TRC_TS3_STATE_CTRL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_RESET 		 MAC_TRC_TS3_STATE_CTRL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_STATE_CTRL_RESET 		 MAC_TRC_TS3_STATE_CTRL_RESET

// 32'h033c (MAC_TRC_TS3_TRIG_MASK)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS3_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS3_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS3_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS3_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS3_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS3_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS3_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS3_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS3_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS3_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS3_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS3_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS3_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS3_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS3_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS3_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS3_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS3_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_ADDRESS 		 MAC_TRC_TS3_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_ADDRESS 		 MAC_TRC_TS3_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_ADDRESS 		 MAC_TRC_TS3_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_OFFSET 		 MAC_TRC_TS3_TRIG_MASK_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_OFFSET 		 MAC_TRC_TS3_TRIG_MASK_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_OFFSET 		 MAC_TRC_TS3_TRIG_MASK_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_SW_MASK 		 MAC_TRC_TS3_TRIG_MASK_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_SW_MASK 		 MAC_TRC_TS3_TRIG_MASK_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_SW_MASK 		 MAC_TRC_TS3_TRIG_MASK_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_RSTMASK 		 MAC_TRC_TS3_TRIG_MASK_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_RSTMASK 		 MAC_TRC_TS3_TRIG_MASK_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_RSTMASK 		 MAC_TRC_TS3_TRIG_MASK_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_RESET 		 MAC_TRC_TS3_TRIG_MASK_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_RESET 		 MAC_TRC_TS3_TRIG_MASK_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_MASK_RESET 		 MAC_TRC_TS3_TRIG_MASK_RESET

// 32'h0340 (MAC_TRC_TS3_TRIG)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_VALUE_MSB 		 MAC_TRC_TS3_TRIG_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_VALUE_MSB 		 MAC_TRC_TS3_TRIG_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_VALUE_LSB 		 MAC_TRC_TS3_TRIG_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_VALUE_LSB 		 MAC_TRC_TS3_TRIG_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_VALUE_MASK 		 MAC_TRC_TS3_TRIG_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_VALUE_MASK 		 MAC_TRC_TS3_TRIG_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_VALUE_GET(x) 		 MAC_TRC_TS3_TRIG_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_VALUE_GET(x) 		 MAC_TRC_TS3_TRIG_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_VALUE_SET(x) 		 MAC_TRC_TS3_TRIG_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_VALUE_SET(x) 		 MAC_TRC_TS3_TRIG_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_VALUE_RESET 		 MAC_TRC_TS3_TRIG_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_VALUE_RESET 		 MAC_TRC_TS3_TRIG_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_ADDRESS 		 MAC_TRC_TS3_TRIG_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_ADDRESS 		 MAC_TRC_TS3_TRIG_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_OFFSET 		 MAC_TRC_TS3_TRIG_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_OFFSET 		 MAC_TRC_TS3_TRIG_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_SW_MASK 		 MAC_TRC_TS3_TRIG_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_SW_MASK 		 MAC_TRC_TS3_TRIG_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_RSTMASK 		 MAC_TRC_TS3_TRIG_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_RSTMASK 		 MAC_TRC_TS3_TRIG_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_RESET 		 MAC_TRC_TS3_TRIG_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS3_TRIG_RESET 		 MAC_TRC_TS3_TRIG_RESET

// 32'h0344 (MAC_TRC_TS4_CAPTURE_CTRL)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_MSB 		 MAC_TRC_TS4_CAPTURE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_MSB 		 MAC_TRC_TS4_CAPTURE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_LSB 		 MAC_TRC_TS4_CAPTURE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_LSB 		 MAC_TRC_TS4_CAPTURE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_MASK 		 MAC_TRC_TS4_CAPTURE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_MASK 		 MAC_TRC_TS4_CAPTURE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS4_CAPTURE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS4_CAPTURE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS4_CAPTURE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS4_CAPTURE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_RESET 		 MAC_TRC_TS4_CAPTURE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_RESET 		 MAC_TRC_TS4_CAPTURE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_ADDRESS 		 MAC_TRC_TS4_CAPTURE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_ADDRESS 		 MAC_TRC_TS4_CAPTURE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_OFFSET 		 MAC_TRC_TS4_CAPTURE_CTRL_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_OFFSET 		 MAC_TRC_TS4_CAPTURE_CTRL_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_SW_MASK 		 MAC_TRC_TS4_CAPTURE_CTRL_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_SW_MASK 		 MAC_TRC_TS4_CAPTURE_CTRL_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_RSTMASK 		 MAC_TRC_TS4_CAPTURE_CTRL_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_RSTMASK 		 MAC_TRC_TS4_CAPTURE_CTRL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_RESET 		 MAC_TRC_TS4_CAPTURE_CTRL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_CAPTURE_CTRL_RESET 		 MAC_TRC_TS4_CAPTURE_CTRL_RESET

// 32'h0348 (MAC_TRC_TS4_STATE_CTRL)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_VALUE_MSB 		 MAC_TRC_TS4_STATE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_VALUE_MSB 		 MAC_TRC_TS4_STATE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_VALUE_LSB 		 MAC_TRC_TS4_STATE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_VALUE_LSB 		 MAC_TRC_TS4_STATE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_VALUE_MASK 		 MAC_TRC_TS4_STATE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_VALUE_MASK 		 MAC_TRC_TS4_STATE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS4_STATE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS4_STATE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS4_STATE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS4_STATE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_VALUE_RESET 		 MAC_TRC_TS4_STATE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_VALUE_RESET 		 MAC_TRC_TS4_STATE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_ADDRESS 		 MAC_TRC_TS4_STATE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_ADDRESS 		 MAC_TRC_TS4_STATE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_OFFSET 		 MAC_TRC_TS4_STATE_CTRL_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_OFFSET 		 MAC_TRC_TS4_STATE_CTRL_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_SW_MASK 		 MAC_TRC_TS4_STATE_CTRL_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_SW_MASK 		 MAC_TRC_TS4_STATE_CTRL_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_RSTMASK 		 MAC_TRC_TS4_STATE_CTRL_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_RSTMASK 		 MAC_TRC_TS4_STATE_CTRL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_RESET 		 MAC_TRC_TS4_STATE_CTRL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_STATE_CTRL_RESET 		 MAC_TRC_TS4_STATE_CTRL_RESET

// 32'h034c (MAC_TRC_TS4_TRIG_MASK)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS4_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS4_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS4_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS4_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS4_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS4_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS4_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS4_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS4_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS4_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS4_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS4_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS4_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS4_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS4_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS4_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS4_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS4_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_ADDRESS 		 MAC_TRC_TS4_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_ADDRESS 		 MAC_TRC_TS4_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_ADDRESS 		 MAC_TRC_TS4_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_OFFSET 		 MAC_TRC_TS4_TRIG_MASK_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_OFFSET 		 MAC_TRC_TS4_TRIG_MASK_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_OFFSET 		 MAC_TRC_TS4_TRIG_MASK_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_SW_MASK 		 MAC_TRC_TS4_TRIG_MASK_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_SW_MASK 		 MAC_TRC_TS4_TRIG_MASK_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_SW_MASK 		 MAC_TRC_TS4_TRIG_MASK_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_RSTMASK 		 MAC_TRC_TS4_TRIG_MASK_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_RSTMASK 		 MAC_TRC_TS4_TRIG_MASK_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_RSTMASK 		 MAC_TRC_TS4_TRIG_MASK_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_RESET 		 MAC_TRC_TS4_TRIG_MASK_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_RESET 		 MAC_TRC_TS4_TRIG_MASK_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_MASK_RESET 		 MAC_TRC_TS4_TRIG_MASK_RESET

// 32'h0350 (MAC_TRC_TS4_TRIG)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_VALUE_MSB 		 MAC_TRC_TS4_TRIG_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_VALUE_MSB 		 MAC_TRC_TS4_TRIG_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_VALUE_LSB 		 MAC_TRC_TS4_TRIG_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_VALUE_LSB 		 MAC_TRC_TS4_TRIG_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_VALUE_MASK 		 MAC_TRC_TS4_TRIG_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_VALUE_MASK 		 MAC_TRC_TS4_TRIG_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_VALUE_GET(x) 		 MAC_TRC_TS4_TRIG_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_VALUE_GET(x) 		 MAC_TRC_TS4_TRIG_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_VALUE_SET(x) 		 MAC_TRC_TS4_TRIG_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_VALUE_SET(x) 		 MAC_TRC_TS4_TRIG_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_VALUE_RESET 		 MAC_TRC_TS4_TRIG_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_VALUE_RESET 		 MAC_TRC_TS4_TRIG_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_ADDRESS 		 MAC_TRC_TS4_TRIG_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_ADDRESS 		 MAC_TRC_TS4_TRIG_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_OFFSET 		 MAC_TRC_TS4_TRIG_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_OFFSET 		 MAC_TRC_TS4_TRIG_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_SW_MASK 		 MAC_TRC_TS4_TRIG_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_SW_MASK 		 MAC_TRC_TS4_TRIG_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_RSTMASK 		 MAC_TRC_TS4_TRIG_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_RSTMASK 		 MAC_TRC_TS4_TRIG_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_RESET 		 MAC_TRC_TS4_TRIG_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS4_TRIG_RESET 		 MAC_TRC_TS4_TRIG_RESET

// 32'h0354 (MAC_TRC_TS5_CAPTURE_CTRL)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_MSB 		 MAC_TRC_TS5_CAPTURE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_MSB 		 MAC_TRC_TS5_CAPTURE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_LSB 		 MAC_TRC_TS5_CAPTURE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_LSB 		 MAC_TRC_TS5_CAPTURE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_MASK 		 MAC_TRC_TS5_CAPTURE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_MASK 		 MAC_TRC_TS5_CAPTURE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS5_CAPTURE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS5_CAPTURE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS5_CAPTURE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS5_CAPTURE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_RESET 		 MAC_TRC_TS5_CAPTURE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_RESET 		 MAC_TRC_TS5_CAPTURE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_ADDRESS 		 MAC_TRC_TS5_CAPTURE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_ADDRESS 		 MAC_TRC_TS5_CAPTURE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_OFFSET 		 MAC_TRC_TS5_CAPTURE_CTRL_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_OFFSET 		 MAC_TRC_TS5_CAPTURE_CTRL_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_SW_MASK 		 MAC_TRC_TS5_CAPTURE_CTRL_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_SW_MASK 		 MAC_TRC_TS5_CAPTURE_CTRL_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_RSTMASK 		 MAC_TRC_TS5_CAPTURE_CTRL_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_RSTMASK 		 MAC_TRC_TS5_CAPTURE_CTRL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_RESET 		 MAC_TRC_TS5_CAPTURE_CTRL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_CAPTURE_CTRL_RESET 		 MAC_TRC_TS5_CAPTURE_CTRL_RESET

// 32'h0358 (MAC_TRC_TS5_STATE_CTRL)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_VALUE_MSB 		 MAC_TRC_TS5_STATE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_VALUE_MSB 		 MAC_TRC_TS5_STATE_CTRL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_VALUE_LSB 		 MAC_TRC_TS5_STATE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_VALUE_LSB 		 MAC_TRC_TS5_STATE_CTRL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_VALUE_MASK 		 MAC_TRC_TS5_STATE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_VALUE_MASK 		 MAC_TRC_TS5_STATE_CTRL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS5_STATE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_VALUE_GET(x) 		 MAC_TRC_TS5_STATE_CTRL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS5_STATE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_VALUE_SET(x) 		 MAC_TRC_TS5_STATE_CTRL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_VALUE_RESET 		 MAC_TRC_TS5_STATE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_VALUE_RESET 		 MAC_TRC_TS5_STATE_CTRL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_ADDRESS 		 MAC_TRC_TS5_STATE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_ADDRESS 		 MAC_TRC_TS5_STATE_CTRL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_OFFSET 		 MAC_TRC_TS5_STATE_CTRL_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_OFFSET 		 MAC_TRC_TS5_STATE_CTRL_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_SW_MASK 		 MAC_TRC_TS5_STATE_CTRL_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_SW_MASK 		 MAC_TRC_TS5_STATE_CTRL_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_RSTMASK 		 MAC_TRC_TS5_STATE_CTRL_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_RSTMASK 		 MAC_TRC_TS5_STATE_CTRL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_RESET 		 MAC_TRC_TS5_STATE_CTRL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_STATE_CTRL_RESET 		 MAC_TRC_TS5_STATE_CTRL_RESET

// 32'h035c (MAC_TRC_TS5_TRIG_MASK)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS5_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS5_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_MSB 		 MAC_TRC_TS5_TRIG_MASK_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS5_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS5_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_LSB 		 MAC_TRC_TS5_TRIG_MASK_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS5_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS5_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_MASK 		 MAC_TRC_TS5_TRIG_MASK_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS5_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS5_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_GET(x) 		 MAC_TRC_TS5_TRIG_MASK_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS5_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS5_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_SET(x) 		 MAC_TRC_TS5_TRIG_MASK_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS5_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS5_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_VALUE_RESET 		 MAC_TRC_TS5_TRIG_MASK_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_ADDRESS 		 MAC_TRC_TS5_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_ADDRESS 		 MAC_TRC_TS5_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_ADDRESS 		 MAC_TRC_TS5_TRIG_MASK_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_OFFSET 		 MAC_TRC_TS5_TRIG_MASK_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_OFFSET 		 MAC_TRC_TS5_TRIG_MASK_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_OFFSET 		 MAC_TRC_TS5_TRIG_MASK_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_SW_MASK 		 MAC_TRC_TS5_TRIG_MASK_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_SW_MASK 		 MAC_TRC_TS5_TRIG_MASK_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_SW_MASK 		 MAC_TRC_TS5_TRIG_MASK_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_RSTMASK 		 MAC_TRC_TS5_TRIG_MASK_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_RSTMASK 		 MAC_TRC_TS5_TRIG_MASK_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_RSTMASK 		 MAC_TRC_TS5_TRIG_MASK_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_RESET 		 MAC_TRC_TS5_TRIG_MASK_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_RESET 		 MAC_TRC_TS5_TRIG_MASK_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_MASK_RESET 		 MAC_TRC_TS5_TRIG_MASK_RESET

// 32'h0360 (MAC_TRC_TS5_TRIG)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_VALUE_MSB 		 MAC_TRC_TS5_TRIG_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_VALUE_MSB 		 MAC_TRC_TS5_TRIG_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_VALUE_LSB 		 MAC_TRC_TS5_TRIG_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_VALUE_LSB 		 MAC_TRC_TS5_TRIG_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_VALUE_MASK 		 MAC_TRC_TS5_TRIG_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_VALUE_MASK 		 MAC_TRC_TS5_TRIG_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_VALUE_GET(x) 		 MAC_TRC_TS5_TRIG_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_VALUE_GET(x) 		 MAC_TRC_TS5_TRIG_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_VALUE_SET(x) 		 MAC_TRC_TS5_TRIG_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_VALUE_SET(x) 		 MAC_TRC_TS5_TRIG_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_VALUE_RESET 		 MAC_TRC_TS5_TRIG_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_VALUE_RESET 		 MAC_TRC_TS5_TRIG_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_ADDRESS 		 MAC_TRC_TS5_TRIG_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_ADDRESS 		 MAC_TRC_TS5_TRIG_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_OFFSET 		 MAC_TRC_TS5_TRIG_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_OFFSET 		 MAC_TRC_TS5_TRIG_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_SW_MASK 		 MAC_TRC_TS5_TRIG_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_SW_MASK 		 MAC_TRC_TS5_TRIG_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_RSTMASK 		 MAC_TRC_TS5_TRIG_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_RSTMASK 		 MAC_TRC_TS5_TRIG_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_RESET 		 MAC_TRC_TS5_TRIG_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_TS5_TRIG_RESET 		 MAC_TRC_TS5_TRIG_RESET

// 32'h0364 (MAC_TRC_CPU_ADDR)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_READ_VALUE_MSB 		 MAC_TRC_CPU_ADDR_READ_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_READ_VALUE_MSB 		 MAC_TRC_CPU_ADDR_READ_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_READ_VALUE_LSB 		 MAC_TRC_CPU_ADDR_READ_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_READ_VALUE_LSB 		 MAC_TRC_CPU_ADDR_READ_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_READ_VALUE_MASK 		 MAC_TRC_CPU_ADDR_READ_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_READ_VALUE_MASK 		 MAC_TRC_CPU_ADDR_READ_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_READ_VALUE_GET(x) 		 MAC_TRC_CPU_ADDR_READ_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_READ_VALUE_GET(x) 		 MAC_TRC_CPU_ADDR_READ_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_READ_VALUE_SET(x) 		 MAC_TRC_CPU_ADDR_READ_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_READ_VALUE_SET(x) 		 MAC_TRC_CPU_ADDR_READ_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_READ_VALUE_RESET 		 MAC_TRC_CPU_ADDR_READ_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_READ_VALUE_RESET 		 MAC_TRC_CPU_ADDR_READ_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_ADDRESS 		 MAC_TRC_CPU_ADDR_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_ADDRESS 		 MAC_TRC_CPU_ADDR_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_OFFSET 		 MAC_TRC_CPU_ADDR_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_OFFSET 		 MAC_TRC_CPU_ADDR_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_SW_MASK 		 MAC_TRC_CPU_ADDR_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_SW_MASK 		 MAC_TRC_CPU_ADDR_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_RSTMASK 		 MAC_TRC_CPU_ADDR_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_RSTMASK 		 MAC_TRC_CPU_ADDR_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_RESET 		 MAC_TRC_CPU_ADDR_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_ADDR_RESET 		 MAC_TRC_CPU_ADDR_RESET

// 32'h0368 (MAC_TRC_CPU_DATA)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_VALUE_MSB 		 MAC_TRC_CPU_DATA_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_VALUE_MSB 		 MAC_TRC_CPU_DATA_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_VALUE_LSB 		 MAC_TRC_CPU_DATA_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_VALUE_LSB 		 MAC_TRC_CPU_DATA_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_VALUE_MASK 		 MAC_TRC_CPU_DATA_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_VALUE_MASK 		 MAC_TRC_CPU_DATA_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_VALUE_GET(x) 		 MAC_TRC_CPU_DATA_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_VALUE_GET(x) 		 MAC_TRC_CPU_DATA_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_VALUE_SET(x) 		 MAC_TRC_CPU_DATA_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_VALUE_SET(x) 		 MAC_TRC_CPU_DATA_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_VALUE_RESET 		 MAC_TRC_CPU_DATA_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_VALUE_RESET 		 MAC_TRC_CPU_DATA_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_ADDRESS 		 MAC_TRC_CPU_DATA_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_ADDRESS 		 MAC_TRC_CPU_DATA_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_OFFSET 		 MAC_TRC_CPU_DATA_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_OFFSET 		 MAC_TRC_CPU_DATA_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_SW_MASK 		 MAC_TRC_CPU_DATA_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_SW_MASK 		 MAC_TRC_CPU_DATA_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_RSTMASK 		 MAC_TRC_CPU_DATA_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_RSTMASK 		 MAC_TRC_CPU_DATA_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_RESET 		 MAC_TRC_CPU_DATA_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_CPU_DATA_RESET 		 MAC_TRC_CPU_DATA_RESET

// 32'h036c (MAC_TRC_STATUS_0)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_INIT_DONE_MSB 		 MAC_TRC_STATUS_0_BUF_INIT_DONE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_INIT_DONE_MSB 		 MAC_TRC_STATUS_0_BUF_INIT_DONE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_INIT_DONE_LSB 		 MAC_TRC_STATUS_0_BUF_INIT_DONE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_INIT_DONE_LSB 		 MAC_TRC_STATUS_0_BUF_INIT_DONE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_INIT_DONE_MASK 		 MAC_TRC_STATUS_0_BUF_INIT_DONE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_INIT_DONE_MASK 		 MAC_TRC_STATUS_0_BUF_INIT_DONE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_INIT_DONE_GET(x) 		 MAC_TRC_STATUS_0_BUF_INIT_DONE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_INIT_DONE_GET(x) 		 MAC_TRC_STATUS_0_BUF_INIT_DONE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_INIT_DONE_SET(x) 		 MAC_TRC_STATUS_0_BUF_INIT_DONE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_INIT_DONE_SET(x) 		 MAC_TRC_STATUS_0_BUF_INIT_DONE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_INIT_DONE_RESET 		 MAC_TRC_STATUS_0_BUF_INIT_DONE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_INIT_DONE_RESET 		 MAC_TRC_STATUS_0_BUF_INIT_DONE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_FULL_MSB 		 MAC_TRC_STATUS_0_BUF_FULL_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_FULL_MSB 		 MAC_TRC_STATUS_0_BUF_FULL_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_FULL_LSB 		 MAC_TRC_STATUS_0_BUF_FULL_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_FULL_LSB 		 MAC_TRC_STATUS_0_BUF_FULL_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_FULL_MASK 		 MAC_TRC_STATUS_0_BUF_FULL_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_FULL_MASK 		 MAC_TRC_STATUS_0_BUF_FULL_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_FULL_GET(x) 		 MAC_TRC_STATUS_0_BUF_FULL_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_FULL_GET(x) 		 MAC_TRC_STATUS_0_BUF_FULL_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_FULL_SET(x) 		 MAC_TRC_STATUS_0_BUF_FULL_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_FULL_SET(x) 		 MAC_TRC_STATUS_0_BUF_FULL_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_FULL_RESET 		 MAC_TRC_STATUS_0_BUF_FULL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_BUF_FULL_RESET 		 MAC_TRC_STATUS_0_BUF_FULL_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_ADDRESS 		 MAC_TRC_STATUS_0_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_ADDRESS 		 MAC_TRC_STATUS_0_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_OFFSET 		 MAC_TRC_STATUS_0_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_OFFSET 		 MAC_TRC_STATUS_0_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_SW_MASK 		 MAC_TRC_STATUS_0_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_SW_MASK 		 MAC_TRC_STATUS_0_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_RSTMASK 		 MAC_TRC_STATUS_0_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_RSTMASK 		 MAC_TRC_STATUS_0_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_RESET 		 MAC_TRC_STATUS_0_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_0_RESET 		 MAC_TRC_STATUS_0_RESET

// 32'h0370 (MAC_TRC_STATUS_1)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MSB 		 MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MSB 		 MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_LSB 		 MAC_TRC_STATUS_1_BUF_RD_END_ADDR_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_LSB 		 MAC_TRC_STATUS_1_BUF_RD_END_ADDR_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MASK 		 MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MASK 		 MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_GET(x) 		 MAC_TRC_STATUS_1_BUF_RD_END_ADDR_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_GET(x) 		 MAC_TRC_STATUS_1_BUF_RD_END_ADDR_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_SET(x) 		 MAC_TRC_STATUS_1_BUF_RD_END_ADDR_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_SET(x) 		 MAC_TRC_STATUS_1_BUF_RD_END_ADDR_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_RESET 		 MAC_TRC_STATUS_1_BUF_RD_END_ADDR_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_RESET 		 MAC_TRC_STATUS_1_BUF_RD_END_ADDR_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MSB 		 MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MSB 		 MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_LSB 		 MAC_TRC_STATUS_1_BUF_RD_START_ADDR_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_LSB 		 MAC_TRC_STATUS_1_BUF_RD_START_ADDR_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MASK 		 MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MASK 		 MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_GET(x) 		 MAC_TRC_STATUS_1_BUF_RD_START_ADDR_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_GET(x) 		 MAC_TRC_STATUS_1_BUF_RD_START_ADDR_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_SET(x) 		 MAC_TRC_STATUS_1_BUF_RD_START_ADDR_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_SET(x) 		 MAC_TRC_STATUS_1_BUF_RD_START_ADDR_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_RESET 		 MAC_TRC_STATUS_1_BUF_RD_START_ADDR_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_RESET 		 MAC_TRC_STATUS_1_BUF_RD_START_ADDR_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_ADDRESS 		 MAC_TRC_STATUS_1_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_ADDRESS 		 MAC_TRC_STATUS_1_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_OFFSET 		 MAC_TRC_STATUS_1_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_OFFSET 		 MAC_TRC_STATUS_1_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_SW_MASK 		 MAC_TRC_STATUS_1_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_SW_MASK 		 MAC_TRC_STATUS_1_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_RSTMASK 		 MAC_TRC_STATUS_1_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_RSTMASK 		 MAC_TRC_STATUS_1_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_RESET 		 MAC_TRC_STATUS_1_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_1_RESET 		 MAC_TRC_STATUS_1_RESET

// 32'h0374 (MAC_TRC_STATUS_2)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MSB 		 MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MSB 		 MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_LSB 		 MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_LSB 		 MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MASK 		 MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MASK 		 MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_GET(x) 		 MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_GET(x) 		 MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_SET(x) 		 MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_SET(x) 		 MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_RESET 		 MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_RESET 		 MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_MAIN_CTL_STATE_MSB 		 MAC_TRC_STATUS_2_MAIN_CTL_STATE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_MAIN_CTL_STATE_MSB 		 MAC_TRC_STATUS_2_MAIN_CTL_STATE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_MAIN_CTL_STATE_LSB 		 MAC_TRC_STATUS_2_MAIN_CTL_STATE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_MAIN_CTL_STATE_LSB 		 MAC_TRC_STATUS_2_MAIN_CTL_STATE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_MAIN_CTL_STATE_MASK 		 MAC_TRC_STATUS_2_MAIN_CTL_STATE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_MAIN_CTL_STATE_MASK 		 MAC_TRC_STATUS_2_MAIN_CTL_STATE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_MAIN_CTL_STATE_GET(x) 		 MAC_TRC_STATUS_2_MAIN_CTL_STATE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_MAIN_CTL_STATE_GET(x) 		 MAC_TRC_STATUS_2_MAIN_CTL_STATE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_MAIN_CTL_STATE_SET(x) 		 MAC_TRC_STATUS_2_MAIN_CTL_STATE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_MAIN_CTL_STATE_SET(x) 		 MAC_TRC_STATUS_2_MAIN_CTL_STATE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_MAIN_CTL_STATE_RESET 		 MAC_TRC_STATUS_2_MAIN_CTL_STATE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_MAIN_CTL_STATE_RESET 		 MAC_TRC_STATUS_2_MAIN_CTL_STATE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_WRCTL_STATE_MSB 		 MAC_TRC_STATUS_2_WRCTL_STATE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_WRCTL_STATE_MSB 		 MAC_TRC_STATUS_2_WRCTL_STATE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_WRCTL_STATE_LSB 		 MAC_TRC_STATUS_2_WRCTL_STATE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_WRCTL_STATE_LSB 		 MAC_TRC_STATUS_2_WRCTL_STATE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_WRCTL_STATE_MASK 		 MAC_TRC_STATUS_2_WRCTL_STATE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_WRCTL_STATE_MASK 		 MAC_TRC_STATUS_2_WRCTL_STATE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_WRCTL_STATE_GET(x) 		 MAC_TRC_STATUS_2_WRCTL_STATE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_WRCTL_STATE_GET(x) 		 MAC_TRC_STATUS_2_WRCTL_STATE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_WRCTL_STATE_SET(x) 		 MAC_TRC_STATUS_2_WRCTL_STATE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_WRCTL_STATE_SET(x) 		 MAC_TRC_STATUS_2_WRCTL_STATE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_WRCTL_STATE_RESET 		 MAC_TRC_STATUS_2_WRCTL_STATE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_WRCTL_STATE_RESET 		 MAC_TRC_STATUS_2_WRCTL_STATE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_ADDRESS 		 MAC_TRC_STATUS_2_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_ADDRESS 		 MAC_TRC_STATUS_2_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_OFFSET 		 MAC_TRC_STATUS_2_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_OFFSET 		 MAC_TRC_STATUS_2_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_SW_MASK 		 MAC_TRC_STATUS_2_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_SW_MASK 		 MAC_TRC_STATUS_2_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_RSTMASK 		 MAC_TRC_STATUS_2_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_RSTMASK 		 MAC_TRC_STATUS_2_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_RESET 		 MAC_TRC_STATUS_2_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_2_RESET 		 MAC_TRC_STATUS_2_RESET

// 32'h0378 (MAC_TRC_STATUS_3)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_TRIG_SAMPLE_MSB 		 MAC_TRC_STATUS_3_TRIG_SAMPLE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_TRIG_SAMPLE_MSB 		 MAC_TRC_STATUS_3_TRIG_SAMPLE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_TRIG_SAMPLE_LSB 		 MAC_TRC_STATUS_3_TRIG_SAMPLE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_TRIG_SAMPLE_LSB 		 MAC_TRC_STATUS_3_TRIG_SAMPLE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_TRIG_SAMPLE_MASK 		 MAC_TRC_STATUS_3_TRIG_SAMPLE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_TRIG_SAMPLE_MASK 		 MAC_TRC_STATUS_3_TRIG_SAMPLE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_TRIG_SAMPLE_GET(x) 		 MAC_TRC_STATUS_3_TRIG_SAMPLE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_TRIG_SAMPLE_GET(x) 		 MAC_TRC_STATUS_3_TRIG_SAMPLE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_TRIG_SAMPLE_SET(x) 		 MAC_TRC_STATUS_3_TRIG_SAMPLE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_TRIG_SAMPLE_SET(x) 		 MAC_TRC_STATUS_3_TRIG_SAMPLE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_TRIG_SAMPLE_RESET 		 MAC_TRC_STATUS_3_TRIG_SAMPLE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_TRIG_SAMPLE_RESET 		 MAC_TRC_STATUS_3_TRIG_SAMPLE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_ADDRESS 		 MAC_TRC_STATUS_3_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_ADDRESS 		 MAC_TRC_STATUS_3_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_OFFSET 		 MAC_TRC_STATUS_3_OFFSET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_OFFSET 		 MAC_TRC_STATUS_3_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_SW_MASK 		 MAC_TRC_STATUS_3_SW_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_SW_MASK 		 MAC_TRC_STATUS_3_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_RSTMASK 		 MAC_TRC_STATUS_3_RSTMASK
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_RSTMASK 		 MAC_TRC_STATUS_3_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_RESET 		 MAC_TRC_STATUS_3_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_TRC_STATUS_3_RESET 		 MAC_TRC_STATUS_3_RESET

// 32'h0380 (MAC_BB_OBS_BUS_SEL)
// Reason:Exactly same register in MCMN 	 #define MAC_BB_OBS_BUS_SEL_VALUE_MSB 		 MAC_BB_OBS_BUS_SEL_VALUE_MSB
// Reason:Exactly same register in MCMN 	 #define MAC_BB_OBS_BUS_SEL_VALUE_LSB 		 MAC_BB_OBS_BUS_SEL_VALUE_LSB
// Reason:Exactly same register in MCMN 	 #define MAC_BB_OBS_BUS_SEL_VALUE_MASK 		 MAC_BB_OBS_BUS_SEL_VALUE_MASK
// Reason:Exactly same register in MCMN 	 #define MAC_BB_OBS_BUS_SEL_VALUE_GET(x) 		 MAC_BB_OBS_BUS_SEL_VALUE_GET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_BB_OBS_BUS_SEL_VALUE_SET(x) 		 MAC_BB_OBS_BUS_SEL_VALUE_SET(x)
// Reason:Exactly same register in MCMN 	 #define MAC_BB_OBS_BUS_SEL_VALUE_RESET 		 MAC_BB_OBS_BUS_SEL_VALUE_RESET
// Reason:Exactly same register in MCMN 	 #define MAC_BB_OBS_BUS_SEL_ADDRESS 		 MAC_BB_OBS_BUS_SEL_ADDRESS
// Reason:Exactly same register in MCMN 	 #define MAC_BB_OBS_BUS_SEL_OFFSET 		 MAC_BB_OBS_BUS_SEL_OFFSET
// SW modifiable bits
// Reason:Exactly same register in MCMN 	 #define MAC_BB_OBS_BUS_SEL_SW_MASK 		 MAC_BB_OBS_BUS_SEL_SW_MASK
// bits defined at reset
// Reason:Exactly same register in MCMN 	 #define MAC_BB_OBS_BUS_SEL_RSTMASK 		 MAC_BB_OBS_BUS_SEL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Exactly same register in MCMN 	 #define MAC_BB_OBS_BUS_SEL_RESET 		 MAC_BB_OBS_BUS_SEL_RESET

// 32'h0384 (MAC_DMA_OBS_MUX_CONTROL)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_VALUE_MSB 		 MAC_DMA_OBS_MUX_CONTROL_VALUE_MSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_VALUE_LSB 		 MAC_DMA_OBS_MUX_CONTROL_VALUE_LSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_VALUE_MASK 		 MAC_DMA_OBS_MUX_CONTROL_VALUE_MASK
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_VALUE_GET(x) 		 MAC_DMA_OBS_MUX_CONTROL_VALUE_GET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_VALUE_SET(x) 		 MAC_DMA_OBS_MUX_CONTROL_VALUE_SET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_VALUE_RESET 		 MAC_DMA_OBS_MUX_CONTROL_VALUE_RESET
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_MSB 		 MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_MSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_LSB 		 MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_LSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_MASK 		 MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_MASK
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_GET(x) 		 MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_GET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_SET(x) 		 MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_SET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_RESET 		 MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_RESET
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_QCU_MSB 		 MAC_DMA_OBS_MUX_CONTROL_QCU_MSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_QCU_LSB 		 MAC_DMA_OBS_MUX_CONTROL_QCU_LSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_QCU_MASK 		 MAC_DMA_OBS_MUX_CONTROL_QCU_MASK
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_QCU_GET(x) 		 MAC_DMA_OBS_MUX_CONTROL_QCU_GET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_QCU_SET(x) 		 MAC_DMA_OBS_MUX_CONTROL_QCU_SET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_QCU_RESET 		 MAC_DMA_OBS_MUX_CONTROL_QCU_RESET
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_MSB 		 MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_MSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_LSB 		 MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_LSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_MASK 		 MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_MASK
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_GET(x) 		 MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_GET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_SET(x) 		 MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_SET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_RESET 		 MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_RESET
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_DCU_MSB 		 MAC_DMA_OBS_MUX_CONTROL_DCU_MSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_DCU_LSB 		 MAC_DMA_OBS_MUX_CONTROL_DCU_LSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_DCU_MASK 		 MAC_DMA_OBS_MUX_CONTROL_DCU_MASK
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_DCU_GET(x) 		 MAC_DMA_OBS_MUX_CONTROL_DCU_GET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_DCU_SET(x) 		 MAC_DMA_OBS_MUX_CONTROL_DCU_SET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_DCU_RESET 		 MAC_DMA_OBS_MUX_CONTROL_DCU_RESET
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_ADDRESS 		 MAC_DMA_OBS_MUX_CONTROL_ADDRESS
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_OFFSET 		 MAC_DMA_OBS_MUX_CONTROL_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_SW_MASK 		 MAC_DMA_OBS_MUX_CONTROL_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_RSTMASK 		 MAC_DMA_OBS_MUX_CONTROL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_DMA_OBS_MUX_CONTROL_RESET 		 MAC_DMA_OBS_MUX_CONTROL_RESET

// 32'h0388 (MAC_OLE_OBS_MUX_CONTROL)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_MSB 		 MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_MSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_LSB 		 MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_LSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_MASK 		 MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_MASK
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_GET(x) 		 MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_GET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_SET(x) 		 MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_SET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_RESET 		 MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_RESET
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_SEL_MSB 		 MAC_OLE_OBS_MUX_CONTROL_SEL_MSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_SEL_LSB 		 MAC_OLE_OBS_MUX_CONTROL_SEL_LSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_SEL_MASK 		 MAC_OLE_OBS_MUX_CONTROL_SEL_MASK
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_SEL_GET(x) 		 MAC_OLE_OBS_MUX_CONTROL_SEL_GET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_SEL_SET(x) 		 MAC_OLE_OBS_MUX_CONTROL_SEL_SET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_SEL_RESET 		 MAC_OLE_OBS_MUX_CONTROL_SEL_RESET
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_ADDRESS 		 MAC_OLE_OBS_MUX_CONTROL_ADDRESS
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_OFFSET 		 MAC_OLE_OBS_MUX_CONTROL_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_SW_MASK 		 MAC_OLE_OBS_MUX_CONTROL_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_RSTMASK 		 MAC_OLE_OBS_MUX_CONTROL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_OLE_OBS_MUX_CONTROL_RESET 		 MAC_OLE_OBS_MUX_CONTROL_RESET

// 32'h038c (MAC_PCU_OBS_MUX_CONTROL)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_VALUE_MSB 		 MAC_PCU_OBS_MUX_CONTROL_VALUE_MSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_VALUE_LSB 		 MAC_PCU_OBS_MUX_CONTROL_VALUE_LSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_VALUE_MASK 		 MAC_PCU_OBS_MUX_CONTROL_VALUE_MASK
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_VALUE_GET(x) 		 MAC_PCU_OBS_MUX_CONTROL_VALUE_GET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_VALUE_SET(x) 		 MAC_PCU_OBS_MUX_CONTROL_VALUE_SET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_VALUE_RESET 		 MAC_PCU_OBS_MUX_CONTROL_VALUE_RESET
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_MSB 		 MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_MSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_LSB 		 MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_LSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_MASK 		 MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_MASK
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_GET(x) 		 MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_GET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_SET(x) 		 MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_SET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_RESET 		 MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_RESET
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_RX_MSB 		 MAC_PCU_OBS_MUX_CONTROL_PCU_RX_MSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_RX_LSB 		 MAC_PCU_OBS_MUX_CONTROL_PCU_RX_LSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_RX_MASK 		 MAC_PCU_OBS_MUX_CONTROL_PCU_RX_MASK
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_RX_GET(x) 		 MAC_PCU_OBS_MUX_CONTROL_PCU_RX_GET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_RX_SET(x) 		 MAC_PCU_OBS_MUX_CONTROL_PCU_RX_SET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_RX_RESET 		 MAC_PCU_OBS_MUX_CONTROL_PCU_RX_RESET
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_MSB 		 MAC_PCU_OBS_MUX_CONTROL_PCU_TX_MSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_LSB 		 MAC_PCU_OBS_MUX_CONTROL_PCU_TX_LSB
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_MASK 		 MAC_PCU_OBS_MUX_CONTROL_PCU_TX_MASK
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_GET(x) 		 MAC_PCU_OBS_MUX_CONTROL_PCU_TX_GET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_SET(x) 		 MAC_PCU_OBS_MUX_CONTROL_PCU_TX_SET(x)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_RESET 		 MAC_PCU_OBS_MUX_CONTROL_PCU_TX_RESET
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_ADDRESS 		 MAC_PCU_OBS_MUX_CONTROL_ADDRESS
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_OFFSET 		 MAC_PCU_OBS_MUX_CONTROL_OFFSET
// SW modifiable bits
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_SW_MASK 		 MAC_PCU_OBS_MUX_CONTROL_SW_MASK
// bits defined at reset
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_RSTMASK 		 MAC_PCU_OBS_MUX_CONTROL_RSTMASK
// reset value (ignore bits undefined at reset)
// Reason:Obsolete: architecture change. Each submodule has its own control. 	 #define MAC_PCU_OBS_MUX_CONTROL_RESET 		 MAC_PCU_OBS_MUX_CONTROL_RESET


#endif /* _MAC_DMA_REG_H_ */
