//                                                                             
// File:       ./mac_dma_reg.vrh                                               
// Creator:    shung                                                           
// Time:       Monday Apr 23, 2012 [6:25:52 pm]                                
//                                                                             
// Path:       /trees/shung/shung-dev/chips/peregrine/1.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux/blueprint -odir . -codegen   
//             ath_vrh.codegen -ath_vrh -Wdesc -I                              
//             /trees/shung/shung-dev/chips/peregrine/1.0/blueprint/sysconfig  
//             mac_dma_reg.rdl                                                 
//                                                                             
// Sources:    /trees/shung/shung-dev/chips/peregrine/1.0/ip/athr/wifi/rtl/mac/rtl/dev/mac/rtl/mac_dma/blueprint/mac_dma_reg.rdl
//             /trees/shung/shung-dev/chips/peregrine/1.0/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Tue Jun 23 00:17:01 PDT 2009)                           
// Machine:    vnc2                                                            
// OS:         Linux 2.4.21-40.ELsmp                                           
// Description:                                                                
//                                                                             
// No Description Provided                                                     
/*
 * Copyright (c) 2012-14 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */


#ifndef _MAC_DMA_REG_H_
#define _MAC_DMA_REG_H_
// 0x0008 (MAC_DMA_CR)
#define MAC_DMA_CR_SWI_MSB                                           6
#define MAC_DMA_CR_SWI_LSB                                           6
#define MAC_DMA_CR_SWI_MASK                                          0x00000040
#define MAC_DMA_CR_SWI_GET(x)                                        (((x) & MAC_DMA_CR_SWI_MASK) >> MAC_DMA_CR_SWI_LSB)
#define MAC_DMA_CR_SWI_SET(x)                                        (((0 | (x)) << MAC_DMA_CR_SWI_LSB) & MAC_DMA_CR_SWI_MASK)
#define MAC_DMA_CR_SWI_RESET                                         0
#define MAC_DMA_CR_RXD_MSB                                           5
#define MAC_DMA_CR_RXD_LSB                                           5
#define MAC_DMA_CR_RXD_MASK                                          0x00000020
#define MAC_DMA_CR_RXD_GET(x)                                        (((x) & MAC_DMA_CR_RXD_MASK) >> MAC_DMA_CR_RXD_LSB)
#define MAC_DMA_CR_RXD_SET(x)                                        (((0 | (x)) << MAC_DMA_CR_RXD_LSB) & MAC_DMA_CR_RXD_MASK)
#define MAC_DMA_CR_RXD_RESET                                         0
#define MAC_DMA_CR_ADDRESS                                           0x0008
#define MAC_DMA_CR_HW_MASK                                           0x00000060
#define MAC_DMA_CR_SW_MASK                                           0x00000060
#define MAC_DMA_CR_HW_WRITE_MASK                                     0x00000040
#define MAC_DMA_CR_SW_WRITE_MASK                                     0x00000020
#define MAC_DMA_CR_RSTMASK                                           0xffffffff
#define MAC_DMA_CR_RESET                                             0x00000000

// 0x0014 (MAC_DMA_CFG)
#define MAC_DMA_CFG_TX_PPDU_END_SWAP_MSB                             31
#define MAC_DMA_CFG_TX_PPDU_END_SWAP_LSB                             31
#define MAC_DMA_CFG_TX_PPDU_END_SWAP_MASK                            0x80000000
#define MAC_DMA_CFG_TX_PPDU_END_SWAP_GET(x)                          (((x) & MAC_DMA_CFG_TX_PPDU_END_SWAP_MASK) >> MAC_DMA_CFG_TX_PPDU_END_SWAP_LSB)
#define MAC_DMA_CFG_TX_PPDU_END_SWAP_SET(x)                          (((0 | (x)) << MAC_DMA_CFG_TX_PPDU_END_SWAP_LSB) & MAC_DMA_CFG_TX_PPDU_END_SWAP_MASK)
#define MAC_DMA_CFG_TX_PPDU_END_SWAP_RESET                           0
#define MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_MSB                       30
#define MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_LSB                       27
#define MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_MASK                      0x78000000
#define MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_GET(x)                    (((x) & MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_MASK) >> MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_LSB)
#define MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_SET(x)                    (((0 | (x)) << MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_LSB) & MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_MASK)
#define MAC_DMA_CFG_MAX_FRAG_TABLE_ENTRIES_RESET                     10
#define MAC_DMA_CFG_TX_PACKET_SWAP_MSB                               26
#define MAC_DMA_CFG_TX_PACKET_SWAP_LSB                               26
#define MAC_DMA_CFG_TX_PACKET_SWAP_MASK                              0x04000000
#define MAC_DMA_CFG_TX_PACKET_SWAP_GET(x)                            (((x) & MAC_DMA_CFG_TX_PACKET_SWAP_MASK) >> MAC_DMA_CFG_TX_PACKET_SWAP_LSB)
#define MAC_DMA_CFG_TX_PACKET_SWAP_SET(x)                            (((0 | (x)) << MAC_DMA_CFG_TX_PACKET_SWAP_LSB) & MAC_DMA_CFG_TX_PACKET_SWAP_MASK)
#define MAC_DMA_CFG_TX_PACKET_SWAP_RESET                             0
#define MAC_DMA_CFG_CV_ENTRY_SWAP_MSB                                25
#define MAC_DMA_CFG_CV_ENTRY_SWAP_LSB                                25
#define MAC_DMA_CFG_CV_ENTRY_SWAP_MASK                               0x02000000
#define MAC_DMA_CFG_CV_ENTRY_SWAP_GET(x)                             (((x) & MAC_DMA_CFG_CV_ENTRY_SWAP_MASK) >> MAC_DMA_CFG_CV_ENTRY_SWAP_LSB)
#define MAC_DMA_CFG_CV_ENTRY_SWAP_SET(x)                             (((0 | (x)) << MAC_DMA_CFG_CV_ENTRY_SWAP_LSB) & MAC_DMA_CFG_CV_ENTRY_SWAP_MASK)
#define MAC_DMA_CFG_CV_ENTRY_SWAP_RESET                              0
#define MAC_DMA_CFG_PEER_ENTRY_SWAP_MSB                              24
#define MAC_DMA_CFG_PEER_ENTRY_SWAP_LSB                              24
#define MAC_DMA_CFG_PEER_ENTRY_SWAP_MASK                             0x01000000
#define MAC_DMA_CFG_PEER_ENTRY_SWAP_GET(x)                           (((x) & MAC_DMA_CFG_PEER_ENTRY_SWAP_MASK) >> MAC_DMA_CFG_PEER_ENTRY_SWAP_LSB)
#define MAC_DMA_CFG_PEER_ENTRY_SWAP_SET(x)                           (((0 | (x)) << MAC_DMA_CFG_PEER_ENTRY_SWAP_LSB) & MAC_DMA_CFG_PEER_ENTRY_SWAP_MASK)
#define MAC_DMA_CFG_PEER_ENTRY_SWAP_RESET                            0
#define MAC_DMA_CFG_TX_MSDU_START_SWAP_MSB                           23
#define MAC_DMA_CFG_TX_MSDU_START_SWAP_LSB                           23
#define MAC_DMA_CFG_TX_MSDU_START_SWAP_MASK                          0x00800000
#define MAC_DMA_CFG_TX_MSDU_START_SWAP_GET(x)                        (((x) & MAC_DMA_CFG_TX_MSDU_START_SWAP_MASK) >> MAC_DMA_CFG_TX_MSDU_START_SWAP_LSB)
#define MAC_DMA_CFG_TX_MSDU_START_SWAP_SET(x)                        (((0 | (x)) << MAC_DMA_CFG_TX_MSDU_START_SWAP_LSB) & MAC_DMA_CFG_TX_MSDU_START_SWAP_MASK)
#define MAC_DMA_CFG_TX_MSDU_START_SWAP_RESET                         0
#define MAC_DMA_CFG_TX_PPDU_START_SWAP_MSB                           22
#define MAC_DMA_CFG_TX_PPDU_START_SWAP_LSB                           22
#define MAC_DMA_CFG_TX_PPDU_START_SWAP_MASK                          0x00400000
#define MAC_DMA_CFG_TX_PPDU_START_SWAP_GET(x)                        (((x) & MAC_DMA_CFG_TX_PPDU_START_SWAP_MASK) >> MAC_DMA_CFG_TX_PPDU_START_SWAP_LSB)
#define MAC_DMA_CFG_TX_PPDU_START_SWAP_SET(x)                        (((0 | (x)) << MAC_DMA_CFG_TX_PPDU_START_SWAP_LSB) & MAC_DMA_CFG_TX_PPDU_START_SWAP_MASK)
#define MAC_DMA_CFG_TX_PPDU_START_SWAP_RESET                         0
#define MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_MSB            21
#define MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_LSB            14
#define MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_MASK           0x003fc000
#define MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_GET(x)         (((x) & MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_MASK) >> MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_LSB)
#define MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_SET(x)         (((0 | (x)) << MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_LSB) & MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_MASK)
#define MAC_DMA_CFG_MARGIN_NUM_FRAME_DWORDS_IN_FLIGHT_RESET          64
#define MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_MSB              13
#define MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_LSB              13
#define MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_MASK             0x00002000
#define MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_GET(x)           (((x) & MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_MASK) >> MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_LSB)
#define MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_SET(x)           (((0 | (x)) << MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_LSB) & MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_MASK)
#define MAC_DMA_CFG_DISABLE_TXBUF_SPACE_AWARE_TXDMA_RESET            0
#define MAC_DMA_CFG_HALT_ACK_MSB                                     12
#define MAC_DMA_CFG_HALT_ACK_LSB                                     12
#define MAC_DMA_CFG_HALT_ACK_MASK                                    0x00001000
#define MAC_DMA_CFG_HALT_ACK_GET(x)                                  (((x) & MAC_DMA_CFG_HALT_ACK_MASK) >> MAC_DMA_CFG_HALT_ACK_LSB)
#define MAC_DMA_CFG_HALT_ACK_SET(x)                                  (((0 | (x)) << MAC_DMA_CFG_HALT_ACK_LSB) & MAC_DMA_CFG_HALT_ACK_MASK)
#define MAC_DMA_CFG_HALT_ACK_RESET                                   0
#define MAC_DMA_CFG_HALT_REQ_MSB                                     11
#define MAC_DMA_CFG_HALT_REQ_LSB                                     11
#define MAC_DMA_CFG_HALT_REQ_MASK                                    0x00000800
#define MAC_DMA_CFG_HALT_REQ_GET(x)                                  (((x) & MAC_DMA_CFG_HALT_REQ_MASK) >> MAC_DMA_CFG_HALT_REQ_LSB)
#define MAC_DMA_CFG_HALT_REQ_SET(x)                                  (((0 | (x)) << MAC_DMA_CFG_HALT_REQ_LSB) & MAC_DMA_CFG_HALT_REQ_MASK)
#define MAC_DMA_CFG_HALT_REQ_RESET                                   0
#define MAC_DMA_CFG_CLKGATE_DIS_MSB                                  10
#define MAC_DMA_CFG_CLKGATE_DIS_LSB                                  10
#define MAC_DMA_CFG_CLKGATE_DIS_MASK                                 0x00000400
#define MAC_DMA_CFG_CLKGATE_DIS_GET(x)                               (((x) & MAC_DMA_CFG_CLKGATE_DIS_MASK) >> MAC_DMA_CFG_CLKGATE_DIS_LSB)
#define MAC_DMA_CFG_CLKGATE_DIS_SET(x)                               (((0 | (x)) << MAC_DMA_CFG_CLKGATE_DIS_LSB) & MAC_DMA_CFG_CLKGATE_DIS_MASK)
#define MAC_DMA_CFG_CLKGATE_DIS_RESET                                0
#define MAC_DMA_CFG_EEPROM_BUSY_MSB                                  9
#define MAC_DMA_CFG_EEPROM_BUSY_LSB                                  9
#define MAC_DMA_CFG_EEPROM_BUSY_MASK                                 0x00000200
#define MAC_DMA_CFG_EEPROM_BUSY_GET(x)                               (((x) & MAC_DMA_CFG_EEPROM_BUSY_MASK) >> MAC_DMA_CFG_EEPROM_BUSY_LSB)
#define MAC_DMA_CFG_EEPROM_BUSY_SET(x)                               (((0 | (x)) << MAC_DMA_CFG_EEPROM_BUSY_LSB) & MAC_DMA_CFG_EEPROM_BUSY_MASK)
#define MAC_DMA_CFG_EEPROM_BUSY_RESET                                0
#define MAC_DMA_CFG_PHY_OK_MSB                                       8
#define MAC_DMA_CFG_PHY_OK_LSB                                       8
#define MAC_DMA_CFG_PHY_OK_MASK                                      0x00000100
#define MAC_DMA_CFG_PHY_OK_GET(x)                                    (((x) & MAC_DMA_CFG_PHY_OK_MASK) >> MAC_DMA_CFG_PHY_OK_LSB)
#define MAC_DMA_CFG_PHY_OK_SET(x)                                    (((0 | (x)) << MAC_DMA_CFG_PHY_OK_LSB) & MAC_DMA_CFG_PHY_OK_MASK)
#define MAC_DMA_CFG_PHY_OK_RESET                                     0
#define MAC_DMA_CFG_ADHOC_MSB                                        5
#define MAC_DMA_CFG_ADHOC_LSB                                        5
#define MAC_DMA_CFG_ADHOC_MASK                                       0x00000020
#define MAC_DMA_CFG_ADHOC_GET(x)                                     (((x) & MAC_DMA_CFG_ADHOC_MASK) >> MAC_DMA_CFG_ADHOC_LSB)
#define MAC_DMA_CFG_ADHOC_SET(x)                                     (((0 | (x)) << MAC_DMA_CFG_ADHOC_LSB) & MAC_DMA_CFG_ADHOC_MASK)
#define MAC_DMA_CFG_ADHOC_RESET                                      0
#define MAC_DMA_CFG_BE_MODE_MMR_MSB                                  4
#define MAC_DMA_CFG_BE_MODE_MMR_LSB                                  4
#define MAC_DMA_CFG_BE_MODE_MMR_MASK                                 0x00000010
#define MAC_DMA_CFG_BE_MODE_MMR_GET(x)                               (((x) & MAC_DMA_CFG_BE_MODE_MMR_MASK) >> MAC_DMA_CFG_BE_MODE_MMR_LSB)
#define MAC_DMA_CFG_BE_MODE_MMR_SET(x)                               (((0 | (x)) << MAC_DMA_CFG_BE_MODE_MMR_LSB) & MAC_DMA_CFG_BE_MODE_MMR_MASK)
#define MAC_DMA_CFG_BE_MODE_MMR_RESET                                0
#define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_MSB                          3
#define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_LSB                          3
#define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_MASK                         0x00000008
#define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_GET(x)                       (((x) & MAC_DMA_CFG_RESET_INT_MIT_CNTRS_MASK) >> MAC_DMA_CFG_RESET_INT_MIT_CNTRS_LSB)
#define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_SET(x)                       (((0 | (x)) << MAC_DMA_CFG_RESET_INT_MIT_CNTRS_LSB) & MAC_DMA_CFG_RESET_INT_MIT_CNTRS_MASK)
#define MAC_DMA_CFG_RESET_INT_MIT_CNTRS_RESET                        0
#define MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_MSB                   2
#define MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_LSB                   2
#define MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_MASK                  0x00000004
#define MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_GET(x)                (((x) & MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_MASK) >> MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_LSB)
#define MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_SET(x)                (((0 | (x)) << MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_LSB) & MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_MASK)
#define MAC_DMA_CFG_LEGACY_INT_MIT_MODE_ENABLE_RESET                 0
#define MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_MSB                         1
#define MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_LSB                         0
#define MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_MASK                        0x00000003
#define MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_GET(x)                      (((x) & MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_MASK) >> MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_LSB)
#define MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_SET(x)                      (((0 | (x)) << MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_LSB) & MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_MASK)
#define MAC_DMA_CFG_REQ_Q_FULL_THRESHOLD_RESET                       0
#define MAC_DMA_CFG_ADDRESS                                          0x0014
#define MAC_DMA_CFG_HW_MASK                                          0xffffff3f
#define MAC_DMA_CFG_SW_MASK                                          0xffffff3f
#define MAC_DMA_CFG_HW_WRITE_MASK                                    0x00001300
#define MAC_DMA_CFG_SW_WRITE_MASK                                    0xffffec3f
#define MAC_DMA_CFG_RSTMASK                                          0xffffffff
#define MAC_DMA_CFG_RESET                                            0x50100000

// 0x001c (MAC_DMA_TXDPPTR_THRESH)
#define MAC_DMA_TXDPPTR_THRESH_DATA_MSB                              3
#define MAC_DMA_TXDPPTR_THRESH_DATA_LSB                              0
#define MAC_DMA_TXDPPTR_THRESH_DATA_MASK                             0x0000000f
#define MAC_DMA_TXDPPTR_THRESH_DATA_GET(x)                           (((x) & MAC_DMA_TXDPPTR_THRESH_DATA_MASK) >> MAC_DMA_TXDPPTR_THRESH_DATA_LSB)
#define MAC_DMA_TXDPPTR_THRESH_DATA_SET(x)                           (((0 | (x)) << MAC_DMA_TXDPPTR_THRESH_DATA_LSB) & MAC_DMA_TXDPPTR_THRESH_DATA_MASK)
#define MAC_DMA_TXDPPTR_THRESH_DATA_RESET                            0
#define MAC_DMA_TXDPPTR_THRESH_ADDRESS                               0x001c
#define MAC_DMA_TXDPPTR_THRESH_HW_MASK                               0x0000000f
#define MAC_DMA_TXDPPTR_THRESH_SW_MASK                               0x0000000f
#define MAC_DMA_TXDPPTR_THRESH_HW_WRITE_MASK                         0x00000000
#define MAC_DMA_TXDPPTR_THRESH_SW_WRITE_MASK                         0x0000000f
#define MAC_DMA_TXDPPTR_THRESH_RSTMASK                               0xffffffff
#define MAC_DMA_TXDPPTR_THRESH_RESET                                 0x00000000

// 0x0024 (MAC_DMA_GLOBAL_IER)
#define MAC_DMA_GLOBAL_IER_ENABLE_MSB                                0
#define MAC_DMA_GLOBAL_IER_ENABLE_LSB                                0
#define MAC_DMA_GLOBAL_IER_ENABLE_MASK                               0x00000001
#define MAC_DMA_GLOBAL_IER_ENABLE_GET(x)                             (((x) & MAC_DMA_GLOBAL_IER_ENABLE_MASK) >> MAC_DMA_GLOBAL_IER_ENABLE_LSB)
#define MAC_DMA_GLOBAL_IER_ENABLE_SET(x)                             (((0 | (x)) << MAC_DMA_GLOBAL_IER_ENABLE_LSB) & MAC_DMA_GLOBAL_IER_ENABLE_MASK)
#define MAC_DMA_GLOBAL_IER_ENABLE_RESET                              0
#define MAC_DMA_GLOBAL_IER_ADDRESS                                   0x0024
#define MAC_DMA_GLOBAL_IER_HW_MASK                                   0x00000001
#define MAC_DMA_GLOBAL_IER_SW_MASK                                   0x00000001
#define MAC_DMA_GLOBAL_IER_HW_WRITE_MASK                             0x00000001
#define MAC_DMA_GLOBAL_IER_SW_WRITE_MASK                             0x00000001
#define MAC_DMA_GLOBAL_IER_RSTMASK                                   0xfffffffe
#define MAC_DMA_GLOBAL_IER_RESET                                     0x00000000

// 0x0030 (MAC_DMA_TXCFG)
#define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_MSB          31
#define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_LSB          31
#define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_MASK         0x80000000
#define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_GET(x)       (((x) & MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_MASK) >> MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_LSB)
#define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_SET(x)       (((0 | (x)) << MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_LSB) & MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_MASK)
#define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_RESP_CH_TIMEOUT_RESET        0
#define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_MSB           30
#define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_LSB           30
#define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_MASK          0x40000000
#define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_GET(x)        (((x) & MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_MASK) >> MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_LSB)
#define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_SET(x)        (((0 | (x)) << MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_LSB) & MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_MASK)
#define MAC_DMA_TXCFG_DISABLE_TXDMA_AXI_REQ_CH_TIMEOUT_RESET         0
#define MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_MSB                    29
#define MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_LSB                    24
#define MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_MASK                   0x3f000000
#define MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_GET(x)                 (((x) & MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_MASK) >> MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_LSB)
#define MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_SET(x)                 (((0 | (x)) << MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_LSB) & MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_MASK)
#define MAC_DMA_TXCFG_TXDMA_OLE_TIMEOUT_LIMIT_RESET                  16
#define MAC_DMA_TXCFG_TXDMA_AXI_TIMEOUT_LIMIT_MSB                    23
#define MAC_DMA_TXCFG_TXDMA_AXI_TIMEOUT_LIMIT_LSB                    16
#define MAC_DMA_TXCFG_TXDMA_AXI_TIMEOUT_LIMIT_MASK                   0x00ff0000
#define MAC_DMA_TXCFG_TXDMA_AXI_TIMEOUT_LIMIT_GET(x)                 (((x) & MAC_DMA_TXCFG_TXDMA_AXI_TIMEOUT_LIMIT_MASK) >> MAC_DMA_TXCFG_TXDMA_AXI_TIMEOUT_LIMIT_LSB)
#define MAC_DMA_TXCFG_TXDMA_AXI_TIMEOUT_LIMIT_SET(x)                 (((0 | (x)) << MAC_DMA_TXCFG_TXDMA_AXI_TIMEOUT_LIMIT_LSB) & MAC_DMA_TXCFG_TXDMA_AXI_TIMEOUT_LIMIT_MASK)
#define MAC_DMA_TXCFG_TXDMA_AXI_TIMEOUT_LIMIT_RESET                  127
#define MAC_DMA_TXCFG_RTCI_DIS_MSB                                   14
#define MAC_DMA_TXCFG_RTCI_DIS_LSB                                   14
#define MAC_DMA_TXCFG_RTCI_DIS_MASK                                  0x00004000
#define MAC_DMA_TXCFG_RTCI_DIS_GET(x)                                (((x) & MAC_DMA_TXCFG_RTCI_DIS_MASK) >> MAC_DMA_TXCFG_RTCI_DIS_LSB)
#define MAC_DMA_TXCFG_RTCI_DIS_SET(x)                                (((0 | (x)) << MAC_DMA_TXCFG_RTCI_DIS_LSB) & MAC_DMA_TXCFG_RTCI_DIS_MASK)
#define MAC_DMA_TXCFG_RTCI_DIS_RESET                                 0
#define MAC_DMA_TXCFG_ATIM_DEFER_DIS_MSB                             12
#define MAC_DMA_TXCFG_ATIM_DEFER_DIS_LSB                             12
#define MAC_DMA_TXCFG_ATIM_DEFER_DIS_MASK                            0x00001000
#define MAC_DMA_TXCFG_ATIM_DEFER_DIS_GET(x)                          (((x) & MAC_DMA_TXCFG_ATIM_DEFER_DIS_MASK) >> MAC_DMA_TXCFG_ATIM_DEFER_DIS_LSB)
#define MAC_DMA_TXCFG_ATIM_DEFER_DIS_SET(x)                          (((0 | (x)) << MAC_DMA_TXCFG_ATIM_DEFER_DIS_LSB) & MAC_DMA_TXCFG_ATIM_DEFER_DIS_MASK)
#define MAC_DMA_TXCFG_ATIM_DEFER_DIS_RESET                           0
#define MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_MSB                          11
#define MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_LSB                          11
#define MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_MASK                         0x00000800
#define MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_GET(x)                       (((x) & MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_MASK) >> MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_LSB)
#define MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_SET(x)                       (((0 | (x)) << MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_LSB) & MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_MASK)
#define MAC_DMA_TXCFG_BCN_PAST_ATIM_DIS_RESET                        0
#define MAC_DMA_TXCFG_JUMBO_EN_MSB                                   10
#define MAC_DMA_TXCFG_JUMBO_EN_LSB                                   10
#define MAC_DMA_TXCFG_JUMBO_EN_MASK                                  0x00000400
#define MAC_DMA_TXCFG_JUMBO_EN_GET(x)                                (((x) & MAC_DMA_TXCFG_JUMBO_EN_MASK) >> MAC_DMA_TXCFG_JUMBO_EN_LSB)
#define MAC_DMA_TXCFG_JUMBO_EN_SET(x)                                (((0 | (x)) << MAC_DMA_TXCFG_JUMBO_EN_LSB) & MAC_DMA_TXCFG_JUMBO_EN_MASK)
#define MAC_DMA_TXCFG_JUMBO_EN_RESET                                 0
#define MAC_DMA_TXCFG_TRIGLVL_MSB                                    9
#define MAC_DMA_TXCFG_TRIGLVL_LSB                                    4
#define MAC_DMA_TXCFG_TRIGLVL_MASK                                   0x000003f0
#define MAC_DMA_TXCFG_TRIGLVL_GET(x)                                 (((x) & MAC_DMA_TXCFG_TRIGLVL_MASK) >> MAC_DMA_TXCFG_TRIGLVL_LSB)
#define MAC_DMA_TXCFG_TRIGLVL_SET(x)                                 (((0 | (x)) << MAC_DMA_TXCFG_TRIGLVL_LSB) & MAC_DMA_TXCFG_TRIGLVL_MASK)
#define MAC_DMA_TXCFG_TRIGLVL_RESET                                  8
#define MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_MSB                 3
#define MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_LSB                 3
#define MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_MASK                0x00000008
#define MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_GET(x)              (((x) & MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_MASK) >> MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_LSB)
#define MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_SET(x)              (((0 | (x)) << MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_LSB) & MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_MASK)
#define MAC_DMA_TXCFG_RTS_FAIL_EXCESSIVE_RETRIES_RESET               1
#define MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_MSB                      2
#define MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_LSB                      2
#define MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_MASK                     0x00000004
#define MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_GET(x)                   (((x) & MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_MASK) >> MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_LSB)
#define MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_SET(x)                   (((0 | (x)) << MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_LSB) & MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_MASK)
#define MAC_DMA_TXCFG_DIS_CW_INC_QUIET_COLL_RESET                    0
#define MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_MSB                         1
#define MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_LSB                         1
#define MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_MASK                        0x00000002
#define MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_GET(x)                      (((x) & MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_MASK) >> MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_LSB)
#define MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_SET(x)                      (((0 | (x)) << MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_LSB) & MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_MASK)
#define MAC_DMA_TXCFG_DIS_RETRY_UNDERRUN_RESET                       1
#define MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_MSB                      0
#define MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_LSB                      0
#define MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_MASK                     0x00000001
#define MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_GET(x)                   (((x) & MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_MASK) >> MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_LSB)
#define MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_SET(x)                   (((0 | (x)) << MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_LSB) & MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_MASK)
#define MAC_DMA_TXCFG_MAX_BUF_DMA_BLOCKSIZE_RESET                    0
#define MAC_DMA_TXCFG_ADDRESS                                        0x0030
#define MAC_DMA_TXCFG_HW_MASK                                        0xffff5fff
#define MAC_DMA_TXCFG_SW_MASK                                        0xffff5fff
#define MAC_DMA_TXCFG_HW_WRITE_MASK                                  0x00000000
#define MAC_DMA_TXCFG_SW_WRITE_MASK                                  0xffff5fff
#define MAC_DMA_TXCFG_RSTMASK                                        0xffffffff
#define MAC_DMA_TXCFG_RESET                                          0x107f008a

// 0x0040 (MAC_DMA_MIBC)
#define MAC_DMA_MIBC_STROBE_MSB                                      3
#define MAC_DMA_MIBC_STROBE_LSB                                      3
#define MAC_DMA_MIBC_STROBE_MASK                                     0x00000008
#define MAC_DMA_MIBC_STROBE_GET(x)                                   (((x) & MAC_DMA_MIBC_STROBE_MASK) >> MAC_DMA_MIBC_STROBE_LSB)
#define MAC_DMA_MIBC_STROBE_SET(x)                                   (((0 | (x)) << MAC_DMA_MIBC_STROBE_LSB) & MAC_DMA_MIBC_STROBE_MASK)
#define MAC_DMA_MIBC_STROBE_RESET                                    0
#define MAC_DMA_MIBC_CLEAR_MSB                                       2
#define MAC_DMA_MIBC_CLEAR_LSB                                       2
#define MAC_DMA_MIBC_CLEAR_MASK                                      0x00000004
#define MAC_DMA_MIBC_CLEAR_GET(x)                                    (((x) & MAC_DMA_MIBC_CLEAR_MASK) >> MAC_DMA_MIBC_CLEAR_LSB)
#define MAC_DMA_MIBC_CLEAR_SET(x)                                    (((0 | (x)) << MAC_DMA_MIBC_CLEAR_LSB) & MAC_DMA_MIBC_CLEAR_MASK)
#define MAC_DMA_MIBC_CLEAR_RESET                                     1
#define MAC_DMA_MIBC_FREEZE_MSB                                      1
#define MAC_DMA_MIBC_FREEZE_LSB                                      1
#define MAC_DMA_MIBC_FREEZE_MASK                                     0x00000002
#define MAC_DMA_MIBC_FREEZE_GET(x)                                   (((x) & MAC_DMA_MIBC_FREEZE_MASK) >> MAC_DMA_MIBC_FREEZE_LSB)
#define MAC_DMA_MIBC_FREEZE_SET(x)                                   (((0 | (x)) << MAC_DMA_MIBC_FREEZE_LSB) & MAC_DMA_MIBC_FREEZE_MASK)
#define MAC_DMA_MIBC_FREEZE_RESET                                    1
#define MAC_DMA_MIBC_WARNING_MSB                                     0
#define MAC_DMA_MIBC_WARNING_LSB                                     0
#define MAC_DMA_MIBC_WARNING_MASK                                    0x00000001
#define MAC_DMA_MIBC_WARNING_GET(x)                                  (((x) & MAC_DMA_MIBC_WARNING_MASK) >> MAC_DMA_MIBC_WARNING_LSB)
#define MAC_DMA_MIBC_WARNING_SET(x)                                  (((0 | (x)) << MAC_DMA_MIBC_WARNING_LSB) & MAC_DMA_MIBC_WARNING_MASK)
#define MAC_DMA_MIBC_WARNING_RESET                                   0
#define MAC_DMA_MIBC_ADDRESS                                         0x0040
#define MAC_DMA_MIBC_HW_MASK                                         0x0000000f
#define MAC_DMA_MIBC_SW_MASK                                         0x0000000f
#define MAC_DMA_MIBC_HW_WRITE_MASK                                   0x00000009
#define MAC_DMA_MIBC_SW_WRITE_MASK                                   0x00000006
#define MAC_DMA_MIBC_RSTMASK                                         0xffffffff
#define MAC_DMA_MIBC_RESET                                           0x00000006

// 0x0044 (MAC_DMA_TOPS)
#define MAC_DMA_TOPS_TIMEOUT_MSB                                     15
#define MAC_DMA_TOPS_TIMEOUT_LSB                                     0
#define MAC_DMA_TOPS_TIMEOUT_MASK                                    0x0000ffff
#define MAC_DMA_TOPS_TIMEOUT_GET(x)                                  (((x) & MAC_DMA_TOPS_TIMEOUT_MASK) >> MAC_DMA_TOPS_TIMEOUT_LSB)
#define MAC_DMA_TOPS_TIMEOUT_SET(x)                                  (((0 | (x)) << MAC_DMA_TOPS_TIMEOUT_LSB) & MAC_DMA_TOPS_TIMEOUT_MASK)
#define MAC_DMA_TOPS_TIMEOUT_RESET                                   0
#define MAC_DMA_TOPS_ADDRESS                                         0x0044
#define MAC_DMA_TOPS_HW_MASK                                         0x0000ffff
#define MAC_DMA_TOPS_SW_MASK                                         0x0000ffff
#define MAC_DMA_TOPS_HW_WRITE_MASK                                   0x00000000
#define MAC_DMA_TOPS_SW_WRITE_MASK                                   0x0000ffff
#define MAC_DMA_TOPS_RSTMASK                                         0xffffffff
#define MAC_DMA_TOPS_RESET                                           0x00000000

// 0x0048 (MAC_DMA_RXNPTO)
#define MAC_DMA_RXNPTO_TIMEOUT_MSB                                   9
#define MAC_DMA_RXNPTO_TIMEOUT_LSB                                   0
#define MAC_DMA_RXNPTO_TIMEOUT_MASK                                  0x000003ff
#define MAC_DMA_RXNPTO_TIMEOUT_GET(x)                                (((x) & MAC_DMA_RXNPTO_TIMEOUT_MASK) >> MAC_DMA_RXNPTO_TIMEOUT_LSB)
#define MAC_DMA_RXNPTO_TIMEOUT_SET(x)                                (((0 | (x)) << MAC_DMA_RXNPTO_TIMEOUT_LSB) & MAC_DMA_RXNPTO_TIMEOUT_MASK)
#define MAC_DMA_RXNPTO_TIMEOUT_RESET                                 0
#define MAC_DMA_RXNPTO_ADDRESS                                       0x0048
#define MAC_DMA_RXNPTO_HW_MASK                                       0x000003ff
#define MAC_DMA_RXNPTO_SW_MASK                                       0x000003ff
#define MAC_DMA_RXNPTO_HW_WRITE_MASK                                 0x00000000
#define MAC_DMA_RXNPTO_SW_WRITE_MASK                                 0x000003ff
#define MAC_DMA_RXNPTO_RSTMASK                                       0xffffffff
#define MAC_DMA_RXNPTO_RESET                                         0x00000000

// 0x004c (MAC_DMA_TXNPTO)
#define MAC_DMA_TXNPTO_MASK_MSB                                      19
#define MAC_DMA_TXNPTO_MASK_LSB                                      10
#define MAC_DMA_TXNPTO_MASK_MASK                                     0x000ffc00
#define MAC_DMA_TXNPTO_MASK_GET(x)                                   (((x) & MAC_DMA_TXNPTO_MASK_MASK) >> MAC_DMA_TXNPTO_MASK_LSB)
#define MAC_DMA_TXNPTO_MASK_SET(x)                                   (((0 | (x)) << MAC_DMA_TXNPTO_MASK_LSB) & MAC_DMA_TXNPTO_MASK_MASK)
#define MAC_DMA_TXNPTO_MASK_RESET                                    0
#define MAC_DMA_TXNPTO_TIMEOUT_MSB                                   9
#define MAC_DMA_TXNPTO_TIMEOUT_LSB                                   0
#define MAC_DMA_TXNPTO_TIMEOUT_MASK                                  0x000003ff
#define MAC_DMA_TXNPTO_TIMEOUT_GET(x)                                (((x) & MAC_DMA_TXNPTO_TIMEOUT_MASK) >> MAC_DMA_TXNPTO_TIMEOUT_LSB)
#define MAC_DMA_TXNPTO_TIMEOUT_SET(x)                                (((0 | (x)) << MAC_DMA_TXNPTO_TIMEOUT_LSB) & MAC_DMA_TXNPTO_TIMEOUT_MASK)
#define MAC_DMA_TXNPTO_TIMEOUT_RESET                                 0
#define MAC_DMA_TXNPTO_ADDRESS                                       0x004c
#define MAC_DMA_TXNPTO_HW_MASK                                       0x000fffff
#define MAC_DMA_TXNPTO_SW_MASK                                       0x000fffff
#define MAC_DMA_TXNPTO_HW_WRITE_MASK                                 0x00000000
#define MAC_DMA_TXNPTO_SW_WRITE_MASK                                 0x000fffff
#define MAC_DMA_TXNPTO_RSTMASK                                       0xffffffff
#define MAC_DMA_TXNPTO_RESET                                         0x00000000

// 0x0050 (MAC_DMA_RPGTO)
#define MAC_DMA_RPGTO_TIMEOUT_MSB                                    9
#define MAC_DMA_RPGTO_TIMEOUT_LSB                                    0
#define MAC_DMA_RPGTO_TIMEOUT_MASK                                   0x000003ff
#define MAC_DMA_RPGTO_TIMEOUT_GET(x)                                 (((x) & MAC_DMA_RPGTO_TIMEOUT_MASK) >> MAC_DMA_RPGTO_TIMEOUT_LSB)
#define MAC_DMA_RPGTO_TIMEOUT_SET(x)                                 (((0 | (x)) << MAC_DMA_RPGTO_TIMEOUT_LSB) & MAC_DMA_RPGTO_TIMEOUT_MASK)
#define MAC_DMA_RPGTO_TIMEOUT_RESET                                  0
#define MAC_DMA_RPGTO_ADDRESS                                        0x0050
#define MAC_DMA_RPGTO_HW_MASK                                        0x000003ff
#define MAC_DMA_RPGTO_SW_MASK                                        0x000003ff
#define MAC_DMA_RPGTO_HW_WRITE_MASK                                  0x00000000
#define MAC_DMA_RPGTO_SW_WRITE_MASK                                  0x000003ff
#define MAC_DMA_RPGTO_RSTMASK                                        0xffffffff
#define MAC_DMA_RPGTO_RESET                                          0x00000000

// 0x0058 (MAC_DMA_MACMISC)
#define MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_MSB                    18
#define MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_LSB                    18
#define MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_MASK                   0x00040000
#define MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_GET(x)                 (((x) & MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_MASK) >> MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_LSB)
#define MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_SET(x)                 (((0 | (x)) << MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_LSB) & MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_MASK)
#define MAC_DMA_MACMISC_TXERR_INT_FIX_DISABLE_RESET                  0
#define MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_MSB                  17
#define MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_LSB                  15
#define MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_MASK                 0x00038000
#define MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_GET(x)               (((x) & MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_MASK) >> MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_LSB)
#define MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_SET(x)               (((0 | (x)) << MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_LSB) & MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_MASK)
#define MAC_DMA_MACMISC_MISC_F2_OBS_HIGH_MUXSEL_RESET                0
#define MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_MSB                   14
#define MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_LSB                   12
#define MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_MASK                  0x00007000
#define MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_GET(x)                (((x) & MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_MASK) >> MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_LSB)
#define MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_SET(x)                (((0 | (x)) << MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_LSB) & MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_MASK)
#define MAC_DMA_MACMISC_MISC_F2_OBS_LOW_MUXSEL_RESET                 0
#define MAC_DMA_MACMISC_MISC_OBS_MUXSEL_MSB                          11
#define MAC_DMA_MACMISC_MISC_OBS_MUXSEL_LSB                          9
#define MAC_DMA_MACMISC_MISC_OBS_MUXSEL_MASK                         0x00000e00
#define MAC_DMA_MACMISC_MISC_OBS_MUXSEL_GET(x)                       (((x) & MAC_DMA_MACMISC_MISC_OBS_MUXSEL_MASK) >> MAC_DMA_MACMISC_MISC_OBS_MUXSEL_LSB)
#define MAC_DMA_MACMISC_MISC_OBS_MUXSEL_SET(x)                       (((0 | (x)) << MAC_DMA_MACMISC_MISC_OBS_MUXSEL_LSB) & MAC_DMA_MACMISC_MISC_OBS_MUXSEL_MASK)
#define MAC_DMA_MACMISC_MISC_OBS_MUXSEL_RESET                        0
#define MAC_DMA_MACMISC_DMA_OBS_MUXSEL_MSB                           8
#define MAC_DMA_MACMISC_DMA_OBS_MUXSEL_LSB                           5
#define MAC_DMA_MACMISC_DMA_OBS_MUXSEL_MASK                          0x000001e0
#define MAC_DMA_MACMISC_DMA_OBS_MUXSEL_GET(x)                        (((x) & MAC_DMA_MACMISC_DMA_OBS_MUXSEL_MASK) >> MAC_DMA_MACMISC_DMA_OBS_MUXSEL_LSB)
#define MAC_DMA_MACMISC_DMA_OBS_MUXSEL_SET(x)                        (((0 | (x)) << MAC_DMA_MACMISC_DMA_OBS_MUXSEL_LSB) & MAC_DMA_MACMISC_DMA_OBS_MUXSEL_MASK)
#define MAC_DMA_MACMISC_DMA_OBS_MUXSEL_RESET                         0
#define MAC_DMA_MACMISC_FORCE_PCI_EXT_MSB                            4
#define MAC_DMA_MACMISC_FORCE_PCI_EXT_LSB                            4
#define MAC_DMA_MACMISC_FORCE_PCI_EXT_MASK                           0x00000010
#define MAC_DMA_MACMISC_FORCE_PCI_EXT_GET(x)                         (((x) & MAC_DMA_MACMISC_FORCE_PCI_EXT_MASK) >> MAC_DMA_MACMISC_FORCE_PCI_EXT_LSB)
#define MAC_DMA_MACMISC_FORCE_PCI_EXT_SET(x)                         (((0 | (x)) << MAC_DMA_MACMISC_FORCE_PCI_EXT_LSB) & MAC_DMA_MACMISC_FORCE_PCI_EXT_MASK)
#define MAC_DMA_MACMISC_FORCE_PCI_EXT_RESET                          0
#define MAC_DMA_MACMISC_ADDRESS                                      0x0058
#define MAC_DMA_MACMISC_HW_MASK                                      0x0007fff0
#define MAC_DMA_MACMISC_SW_MASK                                      0x0007fff0
#define MAC_DMA_MACMISC_HW_WRITE_MASK                                0x00000000
#define MAC_DMA_MACMISC_SW_WRITE_MASK                                0x0007fff0
#define MAC_DMA_MACMISC_RSTMASK                                      0xffffffff
#define MAC_DMA_MACMISC_RESET                                        0x00000000

// 0x005c (MAC_DMA_INTER)
#define MAC_DMA_INTER_MSI_TX_SRC_MSB                                 4
#define MAC_DMA_INTER_MSI_TX_SRC_LSB                                 3
#define MAC_DMA_INTER_MSI_TX_SRC_MASK                                0x00000018
#define MAC_DMA_INTER_MSI_TX_SRC_GET(x)                              (((x) & MAC_DMA_INTER_MSI_TX_SRC_MASK) >> MAC_DMA_INTER_MSI_TX_SRC_LSB)
#define MAC_DMA_INTER_MSI_TX_SRC_SET(x)                              (((0 | (x)) << MAC_DMA_INTER_MSI_TX_SRC_LSB) & MAC_DMA_INTER_MSI_TX_SRC_MASK)
#define MAC_DMA_INTER_MSI_TX_SRC_RESET                               0
#define MAC_DMA_INTER_MSI_RX_SRC_MSB                                 2
#define MAC_DMA_INTER_MSI_RX_SRC_LSB                                 1
#define MAC_DMA_INTER_MSI_RX_SRC_MASK                                0x00000006
#define MAC_DMA_INTER_MSI_RX_SRC_GET(x)                              (((x) & MAC_DMA_INTER_MSI_RX_SRC_MASK) >> MAC_DMA_INTER_MSI_RX_SRC_LSB)
#define MAC_DMA_INTER_MSI_RX_SRC_SET(x)                              (((0 | (x)) << MAC_DMA_INTER_MSI_RX_SRC_LSB) & MAC_DMA_INTER_MSI_RX_SRC_MASK)
#define MAC_DMA_INTER_MSI_RX_SRC_RESET                               0
#define MAC_DMA_INTER_REQ_MSB                                        0
#define MAC_DMA_INTER_REQ_LSB                                        0
#define MAC_DMA_INTER_REQ_MASK                                       0x00000001
#define MAC_DMA_INTER_REQ_GET(x)                                     (((x) & MAC_DMA_INTER_REQ_MASK) >> MAC_DMA_INTER_REQ_LSB)
#define MAC_DMA_INTER_REQ_SET(x)                                     (((0 | (x)) << MAC_DMA_INTER_REQ_LSB) & MAC_DMA_INTER_REQ_MASK)
#define MAC_DMA_INTER_REQ_RESET                                      1
#define MAC_DMA_INTER_ADDRESS                                        0x005c
#define MAC_DMA_INTER_HW_MASK                                        0x0000001f
#define MAC_DMA_INTER_SW_MASK                                        0x0000001f
#define MAC_DMA_INTER_HW_WRITE_MASK                                  0x00000000
#define MAC_DMA_INTER_SW_WRITE_MASK                                  0x0000001f
#define MAC_DMA_INTER_RSTMASK                                        0xffffffff
#define MAC_DMA_INTER_RESET                                          0x00000001

// 0x0060 (MAC_DMA_DATABUF)
#define MAC_DMA_DATABUF_LEN_MSB                                      11
#define MAC_DMA_DATABUF_LEN_LSB                                      0
#define MAC_DMA_DATABUF_LEN_MASK                                     0x00000fff
#define MAC_DMA_DATABUF_LEN_GET(x)                                   (((x) & MAC_DMA_DATABUF_LEN_MASK) >> MAC_DMA_DATABUF_LEN_LSB)
#define MAC_DMA_DATABUF_LEN_SET(x)                                   (((0 | (x)) << MAC_DMA_DATABUF_LEN_LSB) & MAC_DMA_DATABUF_LEN_MASK)
#define MAC_DMA_DATABUF_LEN_RESET                                    4095
#define MAC_DMA_DATABUF_ADDRESS                                      0x0060
#define MAC_DMA_DATABUF_HW_MASK                                      0x00000fff
#define MAC_DMA_DATABUF_SW_MASK                                      0x00000fff
#define MAC_DMA_DATABUF_HW_WRITE_MASK                                0x00000000
#define MAC_DMA_DATABUF_SW_WRITE_MASK                                0x00000fff
#define MAC_DMA_DATABUF_RSTMASK                                      0xffffffff
#define MAC_DMA_DATABUF_RESET                                        0x00000fff

// 0x0064 (MAC_DMA_GTT)
#define MAC_DMA_GTT_LIMIT_MSB                                        31
#define MAC_DMA_GTT_LIMIT_LSB                                        16
#define MAC_DMA_GTT_LIMIT_MASK                                       0xffff0000
#define MAC_DMA_GTT_LIMIT_GET(x)                                     (((x) & MAC_DMA_GTT_LIMIT_MASK) >> MAC_DMA_GTT_LIMIT_LSB)
#define MAC_DMA_GTT_LIMIT_SET(x)                                     (((0 | (x)) << MAC_DMA_GTT_LIMIT_LSB) & MAC_DMA_GTT_LIMIT_MASK)
#define MAC_DMA_GTT_LIMIT_RESET                                      25
#define MAC_DMA_GTT_COUNT_MSB                                        15
#define MAC_DMA_GTT_COUNT_LSB                                        0
#define MAC_DMA_GTT_COUNT_MASK                                       0x0000ffff
#define MAC_DMA_GTT_COUNT_GET(x)                                     (((x) & MAC_DMA_GTT_COUNT_MASK) >> MAC_DMA_GTT_COUNT_LSB)
#define MAC_DMA_GTT_COUNT_SET(x)                                     (((0 | (x)) << MAC_DMA_GTT_COUNT_LSB) & MAC_DMA_GTT_COUNT_MASK)
#define MAC_DMA_GTT_COUNT_RESET                                      0
#define MAC_DMA_GTT_ADDRESS                                          0x0064
#define MAC_DMA_GTT_HW_MASK                                          0xffffffff
#define MAC_DMA_GTT_SW_MASK                                          0xffffffff
#define MAC_DMA_GTT_HW_WRITE_MASK                                    0x0000ffff
#define MAC_DMA_GTT_SW_WRITE_MASK                                    0xffffffff
#define MAC_DMA_GTT_RSTMASK                                          0xffffffff
#define MAC_DMA_GTT_RESET                                            0x00190000

// 0x0068 (MAC_DMA_GTTM)
#define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_MSB                    5
#define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_LSB                    5
#define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_MASK                   0x00000020
#define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_GET(x)                 (((x) & MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_MASK) >> MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_LSB)
#define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_SET(x)                 (((0 | (x)) << MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_LSB) & MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_MASK)
#define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_BT_RESET                  0
#define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_MSB                   4
#define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_LSB                   4
#define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_MASK                  0x00000010
#define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_GET(x)                (((x) & MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_MASK) >> MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_LSB)
#define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_SET(x)                (((0 | (x)) << MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_LSB) & MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_MASK)
#define MAC_DMA_GTTM_DISABLE_QCU_FR_ACTIVE_GTT_RESET                 0
#define MAC_DMA_GTTM_CST_USEC_STROBE_MSB                             3
#define MAC_DMA_GTTM_CST_USEC_STROBE_LSB                             3
#define MAC_DMA_GTTM_CST_USEC_STROBE_MASK                            0x00000008
#define MAC_DMA_GTTM_CST_USEC_STROBE_GET(x)                          (((x) & MAC_DMA_GTTM_CST_USEC_STROBE_MASK) >> MAC_DMA_GTTM_CST_USEC_STROBE_LSB)
#define MAC_DMA_GTTM_CST_USEC_STROBE_SET(x)                          (((0 | (x)) << MAC_DMA_GTTM_CST_USEC_STROBE_LSB) & MAC_DMA_GTTM_CST_USEC_STROBE_MASK)
#define MAC_DMA_GTTM_CST_USEC_STROBE_RESET                           0
#define MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_MSB                          2
#define MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_LSB                          2
#define MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_MASK                         0x00000004
#define MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_GET(x)                       (((x) & MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_MASK) >> MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_LSB)
#define MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_SET(x)                       (((0 | (x)) << MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_LSB) & MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_MASK)
#define MAC_DMA_GTTM_RESET_ON_CHAN_IDLE_RESET                        0
#define MAC_DMA_GTTM_IGNORE_CHAN_IDLE_MSB                            1
#define MAC_DMA_GTTM_IGNORE_CHAN_IDLE_LSB                            1
#define MAC_DMA_GTTM_IGNORE_CHAN_IDLE_MASK                           0x00000002
#define MAC_DMA_GTTM_IGNORE_CHAN_IDLE_GET(x)                         (((x) & MAC_DMA_GTTM_IGNORE_CHAN_IDLE_MASK) >> MAC_DMA_GTTM_IGNORE_CHAN_IDLE_LSB)
#define MAC_DMA_GTTM_IGNORE_CHAN_IDLE_SET(x)                         (((0 | (x)) << MAC_DMA_GTTM_IGNORE_CHAN_IDLE_LSB) & MAC_DMA_GTTM_IGNORE_CHAN_IDLE_MASK)
#define MAC_DMA_GTTM_IGNORE_CHAN_IDLE_RESET                          0
#define MAC_DMA_GTTM_USEC_STROBE_MSB                                 0
#define MAC_DMA_GTTM_USEC_STROBE_LSB                                 0
#define MAC_DMA_GTTM_USEC_STROBE_MASK                                0x00000001
#define MAC_DMA_GTTM_USEC_STROBE_GET(x)                              (((x) & MAC_DMA_GTTM_USEC_STROBE_MASK) >> MAC_DMA_GTTM_USEC_STROBE_LSB)
#define MAC_DMA_GTTM_USEC_STROBE_SET(x)                              (((0 | (x)) << MAC_DMA_GTTM_USEC_STROBE_LSB) & MAC_DMA_GTTM_USEC_STROBE_MASK)
#define MAC_DMA_GTTM_USEC_STROBE_RESET                               0
#define MAC_DMA_GTTM_ADDRESS                                         0x0068
#define MAC_DMA_GTTM_HW_MASK                                         0x0000003f
#define MAC_DMA_GTTM_SW_MASK                                         0x0000003f
#define MAC_DMA_GTTM_HW_WRITE_MASK                                   0x00000000
#define MAC_DMA_GTTM_SW_WRITE_MASK                                   0x0000003f
#define MAC_DMA_GTTM_RSTMASK                                         0xffffffff
#define MAC_DMA_GTTM_RESET                                           0x00000000

// 0x006c (MAC_DMA_CST)
#define MAC_DMA_CST_LIMIT_MSB                                        31
#define MAC_DMA_CST_LIMIT_LSB                                        16
#define MAC_DMA_CST_LIMIT_MASK                                       0xffff0000
#define MAC_DMA_CST_LIMIT_GET(x)                                     (((x) & MAC_DMA_CST_LIMIT_MASK) >> MAC_DMA_CST_LIMIT_LSB)
#define MAC_DMA_CST_LIMIT_SET(x)                                     (((0 | (x)) << MAC_DMA_CST_LIMIT_LSB) & MAC_DMA_CST_LIMIT_MASK)
#define MAC_DMA_CST_LIMIT_RESET                                      0
#define MAC_DMA_CST_COUNT_MSB                                        15
#define MAC_DMA_CST_COUNT_LSB                                        0
#define MAC_DMA_CST_COUNT_MASK                                       0x0000ffff
#define MAC_DMA_CST_COUNT_GET(x)                                     (((x) & MAC_DMA_CST_COUNT_MASK) >> MAC_DMA_CST_COUNT_LSB)
#define MAC_DMA_CST_COUNT_SET(x)                                     (((0 | (x)) << MAC_DMA_CST_COUNT_LSB) & MAC_DMA_CST_COUNT_MASK)
#define MAC_DMA_CST_COUNT_RESET                                      0
#define MAC_DMA_CST_ADDRESS                                          0x006c
#define MAC_DMA_CST_HW_MASK                                          0xffffffff
#define MAC_DMA_CST_SW_MASK                                          0xffffffff
#define MAC_DMA_CST_HW_WRITE_MASK                                    0x0000ffff
#define MAC_DMA_CST_SW_WRITE_MASK                                    0xffffffff
#define MAC_DMA_CST_RSTMASK                                          0xffffffff
#define MAC_DMA_CST_RESET                                            0x00000000

// 0x0070 (MAC_DMA_RXDP_SIZE)
#define MAC_DMA_RXDP_SIZE_HP_MSB                                     12
#define MAC_DMA_RXDP_SIZE_HP_LSB                                     8
#define MAC_DMA_RXDP_SIZE_HP_MASK                                    0x00001f00
#define MAC_DMA_RXDP_SIZE_HP_GET(x)                                  (((x) & MAC_DMA_RXDP_SIZE_HP_MASK) >> MAC_DMA_RXDP_SIZE_HP_LSB)
#define MAC_DMA_RXDP_SIZE_HP_SET(x)                                  (((0 | (x)) << MAC_DMA_RXDP_SIZE_HP_LSB) & MAC_DMA_RXDP_SIZE_HP_MASK)
#define MAC_DMA_RXDP_SIZE_HP_RESET                                   0
#define MAC_DMA_RXDP_SIZE_LP_MSB                                     7
#define MAC_DMA_RXDP_SIZE_LP_LSB                                     0
#define MAC_DMA_RXDP_SIZE_LP_MASK                                    0x000000ff
#define MAC_DMA_RXDP_SIZE_LP_GET(x)                                  (((x) & MAC_DMA_RXDP_SIZE_LP_MASK) >> MAC_DMA_RXDP_SIZE_LP_LSB)
#define MAC_DMA_RXDP_SIZE_LP_SET(x)                                  (((0 | (x)) << MAC_DMA_RXDP_SIZE_LP_LSB) & MAC_DMA_RXDP_SIZE_LP_MASK)
#define MAC_DMA_RXDP_SIZE_LP_RESET                                   0
#define MAC_DMA_RXDP_SIZE_ADDRESS                                    0x0070
#define MAC_DMA_RXDP_SIZE_HW_MASK                                    0x00001fff
#define MAC_DMA_RXDP_SIZE_SW_MASK                                    0x00001fff
#define MAC_DMA_RXDP_SIZE_HW_WRITE_MASK                              0x00001fff
#define MAC_DMA_RXDP_SIZE_SW_WRITE_MASK                              0x00000000
#define MAC_DMA_RXDP_SIZE_RSTMASK                                    0xffffffff
#define MAC_DMA_RXDP_SIZE_RESET                                      0x00000000

// 0x0074 (MAC_DMA_RX_QUEUE_HP_RXDP)
#define MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_MSB                            31
#define MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_LSB                            0
#define MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_MASK                           0xffffffff
#define MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_GET(x)                         (((x) & MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_MASK) >> MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_LSB)
#define MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_SET(x)                         (((0 | (x)) << MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_LSB) & MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_MASK)
#define MAC_DMA_RX_QUEUE_HP_RXDP_ADDR_RESET                          0
#define MAC_DMA_RX_QUEUE_HP_RXDP_ADDRESS                             0x0074
#define MAC_DMA_RX_QUEUE_HP_RXDP_HW_MASK                             0xffffffff
#define MAC_DMA_RX_QUEUE_HP_RXDP_SW_MASK                             0xffffffff
#define MAC_DMA_RX_QUEUE_HP_RXDP_HW_WRITE_MASK                       0x00000000
#define MAC_DMA_RX_QUEUE_HP_RXDP_SW_WRITE_MASK                       0xffffffff
#define MAC_DMA_RX_QUEUE_HP_RXDP_RSTMASK                             0xffffffff
#define MAC_DMA_RX_QUEUE_HP_RXDP_RESET                               0x00000000

// 0x0078 (MAC_DMA_RX_QUEUE_LP_RXDP)
#define MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_MSB                            31
#define MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_LSB                            0
#define MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_MASK                           0xffffffff
#define MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_GET(x)                         (((x) & MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_MASK) >> MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_LSB)
#define MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_SET(x)                         (((0 | (x)) << MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_LSB) & MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_MASK)
#define MAC_DMA_RX_QUEUE_LP_RXDP_ADDR_RESET                          0
#define MAC_DMA_RX_QUEUE_LP_RXDP_ADDRESS                             0x0078
#define MAC_DMA_RX_QUEUE_LP_RXDP_HW_MASK                             0xffffffff
#define MAC_DMA_RX_QUEUE_LP_RXDP_SW_MASK                             0xffffffff
#define MAC_DMA_RX_QUEUE_LP_RXDP_HW_WRITE_MASK                       0x00000000
#define MAC_DMA_RX_QUEUE_LP_RXDP_SW_WRITE_MASK                       0xffffffff
#define MAC_DMA_RX_QUEUE_LP_RXDP_RSTMASK                             0xffffffff
#define MAC_DMA_RX_QUEUE_LP_RXDP_RESET                               0x00000000

// 0x0080 (MAC_DMA_ISR_P)
#define MAC_DMA_ISR_P_BIT_31_MSB                                     31
#define MAC_DMA_ISR_P_BIT_31_LSB                                     31
#define MAC_DMA_ISR_P_BIT_31_MASK                                    0x80000000
#define MAC_DMA_ISR_P_BIT_31_GET(x)                                  (((x) & MAC_DMA_ISR_P_BIT_31_MASK) >> MAC_DMA_ISR_P_BIT_31_LSB)
#define MAC_DMA_ISR_P_BIT_31_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_P_BIT_31_LSB) & MAC_DMA_ISR_P_BIT_31_MASK)
#define MAC_DMA_ISR_P_BIT_31_RESET                                   0
#define MAC_DMA_ISR_P_BIT_30_MSB                                     30
#define MAC_DMA_ISR_P_BIT_30_LSB                                     30
#define MAC_DMA_ISR_P_BIT_30_MASK                                    0x40000000
#define MAC_DMA_ISR_P_BIT_30_GET(x)                                  (((x) & MAC_DMA_ISR_P_BIT_30_MASK) >> MAC_DMA_ISR_P_BIT_30_LSB)
#define MAC_DMA_ISR_P_BIT_30_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_P_BIT_30_LSB) & MAC_DMA_ISR_P_BIT_30_MASK)
#define MAC_DMA_ISR_P_BIT_30_RESET                                   0
#define MAC_DMA_ISR_P_BIT_29_MSB                                     29
#define MAC_DMA_ISR_P_BIT_29_LSB                                     29
#define MAC_DMA_ISR_P_BIT_29_MASK                                    0x20000000
#define MAC_DMA_ISR_P_BIT_29_GET(x)                                  (((x) & MAC_DMA_ISR_P_BIT_29_MASK) >> MAC_DMA_ISR_P_BIT_29_LSB)
#define MAC_DMA_ISR_P_BIT_29_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_P_BIT_29_LSB) & MAC_DMA_ISR_P_BIT_29_MASK)
#define MAC_DMA_ISR_P_BIT_29_RESET                                   0
#define MAC_DMA_ISR_P_GENTMR_MSB                                     28
#define MAC_DMA_ISR_P_GENTMR_LSB                                     28
#define MAC_DMA_ISR_P_GENTMR_MASK                                    0x10000000
#define MAC_DMA_ISR_P_GENTMR_GET(x)                                  (((x) & MAC_DMA_ISR_P_GENTMR_MASK) >> MAC_DMA_ISR_P_GENTMR_LSB)
#define MAC_DMA_ISR_P_GENTMR_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_P_GENTMR_LSB) & MAC_DMA_ISR_P_GENTMR_MASK)
#define MAC_DMA_ISR_P_GENTMR_RESET                                   0
#define MAC_DMA_ISR_P_QTRIG_MSB                                      27
#define MAC_DMA_ISR_P_QTRIG_LSB                                      27
#define MAC_DMA_ISR_P_QTRIG_MASK                                     0x08000000
#define MAC_DMA_ISR_P_QTRIG_GET(x)                                   (((x) & MAC_DMA_ISR_P_QTRIG_MASK) >> MAC_DMA_ISR_P_QTRIG_LSB)
#define MAC_DMA_ISR_P_QTRIG_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_P_QTRIG_LSB) & MAC_DMA_ISR_P_QTRIG_MASK)
#define MAC_DMA_ISR_P_QTRIG_RESET                                    0
#define MAC_DMA_ISR_P_QCBRURN_MSB                                    26
#define MAC_DMA_ISR_P_QCBRURN_LSB                                    26
#define MAC_DMA_ISR_P_QCBRURN_MASK                                   0x04000000
#define MAC_DMA_ISR_P_QCBRURN_GET(x)                                 (((x) & MAC_DMA_ISR_P_QCBRURN_MASK) >> MAC_DMA_ISR_P_QCBRURN_LSB)
#define MAC_DMA_ISR_P_QCBRURN_SET(x)                                 (((0 | (x)) << MAC_DMA_ISR_P_QCBRURN_LSB) & MAC_DMA_ISR_P_QCBRURN_MASK)
#define MAC_DMA_ISR_P_QCBRURN_RESET                                  0
#define MAC_DMA_ISR_P_QCBROVF_MSB                                    25
#define MAC_DMA_ISR_P_QCBROVF_LSB                                    25
#define MAC_DMA_ISR_P_QCBROVF_MASK                                   0x02000000
#define MAC_DMA_ISR_P_QCBROVF_GET(x)                                 (((x) & MAC_DMA_ISR_P_QCBROVF_MASK) >> MAC_DMA_ISR_P_QCBROVF_LSB)
#define MAC_DMA_ISR_P_QCBROVF_SET(x)                                 (((0 | (x)) << MAC_DMA_ISR_P_QCBROVF_LSB) & MAC_DMA_ISR_P_QCBROVF_MASK)
#define MAC_DMA_ISR_P_QCBROVF_RESET                                  0
#define MAC_DMA_ISR_P_BB_INT_MSB                                     24
#define MAC_DMA_ISR_P_BB_INT_LSB                                     24
#define MAC_DMA_ISR_P_BB_INT_MASK                                    0x01000000
#define MAC_DMA_ISR_P_BB_INT_GET(x)                                  (((x) & MAC_DMA_ISR_P_BB_INT_MASK) >> MAC_DMA_ISR_P_BB_INT_LSB)
#define MAC_DMA_ISR_P_BB_INT_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_P_BB_INT_LSB) & MAC_DMA_ISR_P_BB_INT_MASK)
#define MAC_DMA_ISR_P_BB_INT_RESET                                   0
#define MAC_DMA_ISR_P_BCNMISC_MSB                                    23
#define MAC_DMA_ISR_P_BCNMISC_LSB                                    23
#define MAC_DMA_ISR_P_BCNMISC_MASK                                   0x00800000
#define MAC_DMA_ISR_P_BCNMISC_GET(x)                                 (((x) & MAC_DMA_ISR_P_BCNMISC_MASK) >> MAC_DMA_ISR_P_BCNMISC_LSB)
#define MAC_DMA_ISR_P_BCNMISC_SET(x)                                 (((0 | (x)) << MAC_DMA_ISR_P_BCNMISC_LSB) & MAC_DMA_ISR_P_BCNMISC_MASK)
#define MAC_DMA_ISR_P_BCNMISC_RESET                                  0
#define MAC_DMA_ISR_P_OLE_INT_MSB                                    22
#define MAC_DMA_ISR_P_OLE_INT_LSB                                    22
#define MAC_DMA_ISR_P_OLE_INT_MASK                                   0x00400000
#define MAC_DMA_ISR_P_OLE_INT_GET(x)                                 (((x) & MAC_DMA_ISR_P_OLE_INT_MASK) >> MAC_DMA_ISR_P_OLE_INT_LSB)
#define MAC_DMA_ISR_P_OLE_INT_SET(x)                                 (((0 | (x)) << MAC_DMA_ISR_P_OLE_INT_LSB) & MAC_DMA_ISR_P_OLE_INT_MASK)
#define MAC_DMA_ISR_P_OLE_INT_RESET                                  0
#define MAC_DMA_ISR_P_RXINT_MSB                                      21
#define MAC_DMA_ISR_P_RXINT_LSB                                      21
#define MAC_DMA_ISR_P_RXINT_MASK                                     0x00200000
#define MAC_DMA_ISR_P_RXINT_GET(x)                                   (((x) & MAC_DMA_ISR_P_RXINT_MASK) >> MAC_DMA_ISR_P_RXINT_LSB)
#define MAC_DMA_ISR_P_RXINT_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_P_RXINT_LSB) & MAC_DMA_ISR_P_RXINT_MASK)
#define MAC_DMA_ISR_P_RXINT_RESET                                    0
#define MAC_DMA_ISR_P_BNR_MSB                                        20
#define MAC_DMA_ISR_P_BNR_LSB                                        20
#define MAC_DMA_ISR_P_BNR_MASK                                       0x00100000
#define MAC_DMA_ISR_P_BNR_GET(x)                                     (((x) & MAC_DMA_ISR_P_BNR_MASK) >> MAC_DMA_ISR_P_BNR_LSB)
#define MAC_DMA_ISR_P_BNR_SET(x)                                     (((0 | (x)) << MAC_DMA_ISR_P_BNR_LSB) & MAC_DMA_ISR_P_BNR_MASK)
#define MAC_DMA_ISR_P_BNR_RESET                                      0
#define MAC_DMA_ISR_P_BIT_19_MSB                                     19
#define MAC_DMA_ISR_P_BIT_19_LSB                                     19
#define MAC_DMA_ISR_P_BIT_19_MASK                                    0x00080000
#define MAC_DMA_ISR_P_BIT_19_GET(x)                                  (((x) & MAC_DMA_ISR_P_BIT_19_MASK) >> MAC_DMA_ISR_P_BIT_19_LSB)
#define MAC_DMA_ISR_P_BIT_19_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_P_BIT_19_LSB) & MAC_DMA_ISR_P_BIT_19_MASK)
#define MAC_DMA_ISR_P_BIT_19_RESET                                   0
#define MAC_DMA_ISR_P_BMISS_MSB                                      18
#define MAC_DMA_ISR_P_BMISS_LSB                                      18
#define MAC_DMA_ISR_P_BMISS_MASK                                     0x00040000
#define MAC_DMA_ISR_P_BMISS_GET(x)                                   (((x) & MAC_DMA_ISR_P_BMISS_MASK) >> MAC_DMA_ISR_P_BMISS_LSB)
#define MAC_DMA_ISR_P_BMISS_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_P_BMISS_LSB) & MAC_DMA_ISR_P_BMISS_MASK)
#define MAC_DMA_ISR_P_BMISS_RESET                                    0
#define MAC_DMA_ISR_P_BRSSI_MSB                                      17
#define MAC_DMA_ISR_P_BRSSI_LSB                                      17
#define MAC_DMA_ISR_P_BRSSI_MASK                                     0x00020000
#define MAC_DMA_ISR_P_BRSSI_GET(x)                                   (((x) & MAC_DMA_ISR_P_BRSSI_MASK) >> MAC_DMA_ISR_P_BRSSI_LSB)
#define MAC_DMA_ISR_P_BRSSI_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_P_BRSSI_LSB) & MAC_DMA_ISR_P_BRSSI_MASK)
#define MAC_DMA_ISR_P_BRSSI_RESET                                    0
#define MAC_DMA_ISR_P_SWBA_MSB                                       16
#define MAC_DMA_ISR_P_SWBA_LSB                                       16
#define MAC_DMA_ISR_P_SWBA_MASK                                      0x00010000
#define MAC_DMA_ISR_P_SWBA_GET(x)                                    (((x) & MAC_DMA_ISR_P_SWBA_MASK) >> MAC_DMA_ISR_P_SWBA_LSB)
#define MAC_DMA_ISR_P_SWBA_SET(x)                                    (((0 | (x)) << MAC_DMA_ISR_P_SWBA_LSB) & MAC_DMA_ISR_P_SWBA_MASK)
#define MAC_DMA_ISR_P_SWBA_RESET                                     0
#define MAC_DMA_ISR_P_BIT_15_MSB                                     15
#define MAC_DMA_ISR_P_BIT_15_LSB                                     15
#define MAC_DMA_ISR_P_BIT_15_MASK                                    0x00008000
#define MAC_DMA_ISR_P_BIT_15_GET(x)                                  (((x) & MAC_DMA_ISR_P_BIT_15_MASK) >> MAC_DMA_ISR_P_BIT_15_LSB)
#define MAC_DMA_ISR_P_BIT_15_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_P_BIT_15_LSB) & MAC_DMA_ISR_P_BIT_15_MASK)
#define MAC_DMA_ISR_P_BIT_15_RESET                                   0
#define MAC_DMA_ISR_P_BIT_14_MSB                                     14
#define MAC_DMA_ISR_P_BIT_14_LSB                                     14
#define MAC_DMA_ISR_P_BIT_14_MASK                                    0x00004000
#define MAC_DMA_ISR_P_BIT_14_GET(x)                                  (((x) & MAC_DMA_ISR_P_BIT_14_MASK) >> MAC_DMA_ISR_P_BIT_14_LSB)
#define MAC_DMA_ISR_P_BIT_14_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_P_BIT_14_LSB) & MAC_DMA_ISR_P_BIT_14_MASK)
#define MAC_DMA_ISR_P_BIT_14_RESET                                   0
#define MAC_DMA_ISR_P_SWI_MSB                                        13
#define MAC_DMA_ISR_P_SWI_LSB                                        13
#define MAC_DMA_ISR_P_SWI_MASK                                       0x00002000
#define MAC_DMA_ISR_P_SWI_GET(x)                                     (((x) & MAC_DMA_ISR_P_SWI_MASK) >> MAC_DMA_ISR_P_SWI_LSB)
#define MAC_DMA_ISR_P_SWI_SET(x)                                     (((0 | (x)) << MAC_DMA_ISR_P_SWI_LSB) & MAC_DMA_ISR_P_SWI_MASK)
#define MAC_DMA_ISR_P_SWI_RESET                                      0
#define MAC_DMA_ISR_P_MIB_MSB                                        12
#define MAC_DMA_ISR_P_MIB_LSB                                        12
#define MAC_DMA_ISR_P_MIB_MASK                                       0x00001000
#define MAC_DMA_ISR_P_MIB_GET(x)                                     (((x) & MAC_DMA_ISR_P_MIB_MASK) >> MAC_DMA_ISR_P_MIB_LSB)
#define MAC_DMA_ISR_P_MIB_SET(x)                                     (((0 | (x)) << MAC_DMA_ISR_P_MIB_LSB) & MAC_DMA_ISR_P_MIB_MASK)
#define MAC_DMA_ISR_P_MIB_RESET                                      0
#define MAC_DMA_ISR_P_TXURN_MSB                                      11
#define MAC_DMA_ISR_P_TXURN_LSB                                      11
#define MAC_DMA_ISR_P_TXURN_MASK                                     0x00000800
#define MAC_DMA_ISR_P_TXURN_GET(x)                                   (((x) & MAC_DMA_ISR_P_TXURN_MASK) >> MAC_DMA_ISR_P_TXURN_LSB)
#define MAC_DMA_ISR_P_TXURN_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_P_TXURN_LSB) & MAC_DMA_ISR_P_TXURN_MASK)
#define MAC_DMA_ISR_P_TXURN_RESET                                    0
#define MAC_DMA_ISR_P_TXEOL_MSB                                      10
#define MAC_DMA_ISR_P_TXEOL_LSB                                      10
#define MAC_DMA_ISR_P_TXEOL_MASK                                     0x00000400
#define MAC_DMA_ISR_P_TXEOL_GET(x)                                   (((x) & MAC_DMA_ISR_P_TXEOL_MASK) >> MAC_DMA_ISR_P_TXEOL_LSB)
#define MAC_DMA_ISR_P_TXEOL_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_P_TXEOL_LSB) & MAC_DMA_ISR_P_TXEOL_MASK)
#define MAC_DMA_ISR_P_TXEOL_RESET                                    0
#define MAC_DMA_ISR_P_TXNOFR_MSB                                     9
#define MAC_DMA_ISR_P_TXNOFR_LSB                                     9
#define MAC_DMA_ISR_P_TXNOFR_MASK                                    0x00000200
#define MAC_DMA_ISR_P_TXNOFR_GET(x)                                  (((x) & MAC_DMA_ISR_P_TXNOFR_MASK) >> MAC_DMA_ISR_P_TXNOFR_LSB)
#define MAC_DMA_ISR_P_TXNOFR_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_P_TXNOFR_LSB) & MAC_DMA_ISR_P_TXNOFR_MASK)
#define MAC_DMA_ISR_P_TXNOFR_RESET                                   0
#define MAC_DMA_ISR_P_TXERR_MSB                                      8
#define MAC_DMA_ISR_P_TXERR_LSB                                      8
#define MAC_DMA_ISR_P_TXERR_MASK                                     0x00000100
#define MAC_DMA_ISR_P_TXERR_GET(x)                                   (((x) & MAC_DMA_ISR_P_TXERR_MASK) >> MAC_DMA_ISR_P_TXERR_LSB)
#define MAC_DMA_ISR_P_TXERR_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_P_TXERR_LSB) & MAC_DMA_ISR_P_TXERR_MASK)
#define MAC_DMA_ISR_P_TXERR_RESET                                    0
#define MAC_DMA_ISR_P_BTINT_MSB                                      7
#define MAC_DMA_ISR_P_BTINT_LSB                                      7
#define MAC_DMA_ISR_P_BTINT_MASK                                     0x00000080
#define MAC_DMA_ISR_P_BTINT_GET(x)                                   (((x) & MAC_DMA_ISR_P_BTINT_MASK) >> MAC_DMA_ISR_P_BTINT_LSB)
#define MAC_DMA_ISR_P_BTINT_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_P_BTINT_LSB) & MAC_DMA_ISR_P_BTINT_MASK)
#define MAC_DMA_ISR_P_BTINT_RESET                                    0
#define MAC_DMA_ISR_P_TX_DMA_ERR_MSB                                 6
#define MAC_DMA_ISR_P_TX_DMA_ERR_LSB                                 6
#define MAC_DMA_ISR_P_TX_DMA_ERR_MASK                                0x00000040
#define MAC_DMA_ISR_P_TX_DMA_ERR_GET(x)                              (((x) & MAC_DMA_ISR_P_TX_DMA_ERR_MASK) >> MAC_DMA_ISR_P_TX_DMA_ERR_LSB)
#define MAC_DMA_ISR_P_TX_DMA_ERR_SET(x)                              (((0 | (x)) << MAC_DMA_ISR_P_TX_DMA_ERR_LSB) & MAC_DMA_ISR_P_TX_DMA_ERR_MASK)
#define MAC_DMA_ISR_P_TX_DMA_ERR_RESET                               0
#define MAC_DMA_ISR_P_RXORN_MSB                                      5
#define MAC_DMA_ISR_P_RXORN_LSB                                      5
#define MAC_DMA_ISR_P_RXORN_MASK                                     0x00000020
#define MAC_DMA_ISR_P_RXORN_GET(x)                                   (((x) & MAC_DMA_ISR_P_RXORN_MASK) >> MAC_DMA_ISR_P_RXORN_LSB)
#define MAC_DMA_ISR_P_RXORN_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_P_RXORN_LSB) & MAC_DMA_ISR_P_RXORN_MASK)
#define MAC_DMA_ISR_P_RXORN_RESET                                    0
#define MAC_DMA_ISR_P_BIT_4_MSB                                      4
#define MAC_DMA_ISR_P_BIT_4_LSB                                      4
#define MAC_DMA_ISR_P_BIT_4_MASK                                     0x00000010
#define MAC_DMA_ISR_P_BIT_4_GET(x)                                   (((x) & MAC_DMA_ISR_P_BIT_4_MASK) >> MAC_DMA_ISR_P_BIT_4_LSB)
#define MAC_DMA_ISR_P_BIT_4_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_P_BIT_4_LSB) & MAC_DMA_ISR_P_BIT_4_MASK)
#define MAC_DMA_ISR_P_BIT_4_RESET                                    0
#define MAC_DMA_ISR_P_BIT_3_MSB                                      3
#define MAC_DMA_ISR_P_BIT_3_LSB                                      3
#define MAC_DMA_ISR_P_BIT_3_MASK                                     0x00000008
#define MAC_DMA_ISR_P_BIT_3_GET(x)                                   (((x) & MAC_DMA_ISR_P_BIT_3_MASK) >> MAC_DMA_ISR_P_BIT_3_LSB)
#define MAC_DMA_ISR_P_BIT_3_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_P_BIT_3_LSB) & MAC_DMA_ISR_P_BIT_3_MASK)
#define MAC_DMA_ISR_P_BIT_3_RESET                                    0
#define MAC_DMA_ISR_P_BIT_2_MSB                                      2
#define MAC_DMA_ISR_P_BIT_2_LSB                                      2
#define MAC_DMA_ISR_P_BIT_2_MASK                                     0x00000004
#define MAC_DMA_ISR_P_BIT_2_GET(x)                                   (((x) & MAC_DMA_ISR_P_BIT_2_MASK) >> MAC_DMA_ISR_P_BIT_2_LSB)
#define MAC_DMA_ISR_P_BIT_2_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_P_BIT_2_LSB) & MAC_DMA_ISR_P_BIT_2_MASK)
#define MAC_DMA_ISR_P_BIT_2_RESET                                    0
#define MAC_DMA_ISR_P_RX_DMA_ERR_MSB                                 1
#define MAC_DMA_ISR_P_RX_DMA_ERR_LSB                                 1
#define MAC_DMA_ISR_P_RX_DMA_ERR_MASK                                0x00000002
#define MAC_DMA_ISR_P_RX_DMA_ERR_GET(x)                              (((x) & MAC_DMA_ISR_P_RX_DMA_ERR_MASK) >> MAC_DMA_ISR_P_RX_DMA_ERR_LSB)
#define MAC_DMA_ISR_P_RX_DMA_ERR_SET(x)                              (((0 | (x)) << MAC_DMA_ISR_P_RX_DMA_ERR_LSB) & MAC_DMA_ISR_P_RX_DMA_ERR_MASK)
#define MAC_DMA_ISR_P_RX_DMA_ERR_RESET                               0
#define MAC_DMA_ISR_P_RX_DMA_RING_LWM_MSB                            0
#define MAC_DMA_ISR_P_RX_DMA_RING_LWM_LSB                            0
#define MAC_DMA_ISR_P_RX_DMA_RING_LWM_MASK                           0x00000001
#define MAC_DMA_ISR_P_RX_DMA_RING_LWM_GET(x)                         (((x) & MAC_DMA_ISR_P_RX_DMA_RING_LWM_MASK) >> MAC_DMA_ISR_P_RX_DMA_RING_LWM_LSB)
#define MAC_DMA_ISR_P_RX_DMA_RING_LWM_SET(x)                         (((0 | (x)) << MAC_DMA_ISR_P_RX_DMA_RING_LWM_LSB) & MAC_DMA_ISR_P_RX_DMA_RING_LWM_MASK)
#define MAC_DMA_ISR_P_RX_DMA_RING_LWM_RESET                          0
#define MAC_DMA_ISR_P_ADDRESS                                        0x0080
#define MAC_DMA_ISR_P_HW_MASK                                        0xffffffff
#define MAC_DMA_ISR_P_SW_MASK                                        0xffffffff
#define MAC_DMA_ISR_P_HW_WRITE_MASK                                  0xffffffff
#define MAC_DMA_ISR_P_SW_WRITE_MASK                                  0xffffffff
#define MAC_DMA_ISR_P_RSTMASK                                        0xffffffff
#define MAC_DMA_ISR_P_RESET                                          0x00000000

// 0x0084 (MAC_DMA_TXRX_ISR)
#define MAC_DMA_TXRX_ISR_RXOK_HP_MSB                                 13
#define MAC_DMA_TXRX_ISR_RXOK_HP_LSB                                 13
#define MAC_DMA_TXRX_ISR_RXOK_HP_MASK                                0x00002000
#define MAC_DMA_TXRX_ISR_RXOK_HP_GET(x)                              (((x) & MAC_DMA_TXRX_ISR_RXOK_HP_MASK) >> MAC_DMA_TXRX_ISR_RXOK_HP_LSB)
#define MAC_DMA_TXRX_ISR_RXOK_HP_SET(x)                              (((0 | (x)) << MAC_DMA_TXRX_ISR_RXOK_HP_LSB) & MAC_DMA_TXRX_ISR_RXOK_HP_MASK)
#define MAC_DMA_TXRX_ISR_RXOK_HP_RESET                               0
#define MAC_DMA_TXRX_ISR_RXOK_PPDU_MSB                               12
#define MAC_DMA_TXRX_ISR_RXOK_PPDU_LSB                               12
#define MAC_DMA_TXRX_ISR_RXOK_PPDU_MASK                              0x00001000
#define MAC_DMA_TXRX_ISR_RXOK_PPDU_GET(x)                            (((x) & MAC_DMA_TXRX_ISR_RXOK_PPDU_MASK) >> MAC_DMA_TXRX_ISR_RXOK_PPDU_LSB)
#define MAC_DMA_TXRX_ISR_RXOK_PPDU_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_ISR_RXOK_PPDU_LSB) & MAC_DMA_TXRX_ISR_RXOK_PPDU_MASK)
#define MAC_DMA_TXRX_ISR_RXOK_PPDU_RESET                             0
#define MAC_DMA_TXRX_ISR_RXOK_MPDU_MSB                               11
#define MAC_DMA_TXRX_ISR_RXOK_MPDU_LSB                               11
#define MAC_DMA_TXRX_ISR_RXOK_MPDU_MASK                              0x00000800
#define MAC_DMA_TXRX_ISR_RXOK_MPDU_GET(x)                            (((x) & MAC_DMA_TXRX_ISR_RXOK_MPDU_MASK) >> MAC_DMA_TXRX_ISR_RXOK_MPDU_LSB)
#define MAC_DMA_TXRX_ISR_RXOK_MPDU_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_ISR_RXOK_MPDU_LSB) & MAC_DMA_TXRX_ISR_RXOK_MPDU_MASK)
#define MAC_DMA_TXRX_ISR_RXOK_MPDU_RESET                             0
#define MAC_DMA_TXRX_ISR_RXOK_MSDU_MSB                               10
#define MAC_DMA_TXRX_ISR_RXOK_MSDU_LSB                               10
#define MAC_DMA_TXRX_ISR_RXOK_MSDU_MASK                              0x00000400
#define MAC_DMA_TXRX_ISR_RXOK_MSDU_GET(x)                            (((x) & MAC_DMA_TXRX_ISR_RXOK_MSDU_MASK) >> MAC_DMA_TXRX_ISR_RXOK_MSDU_LSB)
#define MAC_DMA_TXRX_ISR_RXOK_MSDU_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_ISR_RXOK_MSDU_LSB) & MAC_DMA_TXRX_ISR_RXOK_MSDU_MASK)
#define MAC_DMA_TXRX_ISR_RXOK_MSDU_RESET                             0
#define MAC_DMA_TXRX_ISR_TXOK_QCU9_MSB                               9
#define MAC_DMA_TXRX_ISR_TXOK_QCU9_LSB                               9
#define MAC_DMA_TXRX_ISR_TXOK_QCU9_MASK                              0x00000200
#define MAC_DMA_TXRX_ISR_TXOK_QCU9_GET(x)                            (((x) & MAC_DMA_TXRX_ISR_TXOK_QCU9_MASK) >> MAC_DMA_TXRX_ISR_TXOK_QCU9_LSB)
#define MAC_DMA_TXRX_ISR_TXOK_QCU9_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_ISR_TXOK_QCU9_LSB) & MAC_DMA_TXRX_ISR_TXOK_QCU9_MASK)
#define MAC_DMA_TXRX_ISR_TXOK_QCU9_RESET                             0
#define MAC_DMA_TXRX_ISR_TXOK_QCU8_MSB                               8
#define MAC_DMA_TXRX_ISR_TXOK_QCU8_LSB                               8
#define MAC_DMA_TXRX_ISR_TXOK_QCU8_MASK                              0x00000100
#define MAC_DMA_TXRX_ISR_TXOK_QCU8_GET(x)                            (((x) & MAC_DMA_TXRX_ISR_TXOK_QCU8_MASK) >> MAC_DMA_TXRX_ISR_TXOK_QCU8_LSB)
#define MAC_DMA_TXRX_ISR_TXOK_QCU8_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_ISR_TXOK_QCU8_LSB) & MAC_DMA_TXRX_ISR_TXOK_QCU8_MASK)
#define MAC_DMA_TXRX_ISR_TXOK_QCU8_RESET                             0
#define MAC_DMA_TXRX_ISR_TXOK_QCU7_MSB                               7
#define MAC_DMA_TXRX_ISR_TXOK_QCU7_LSB                               7
#define MAC_DMA_TXRX_ISR_TXOK_QCU7_MASK                              0x00000080
#define MAC_DMA_TXRX_ISR_TXOK_QCU7_GET(x)                            (((x) & MAC_DMA_TXRX_ISR_TXOK_QCU7_MASK) >> MAC_DMA_TXRX_ISR_TXOK_QCU7_LSB)
#define MAC_DMA_TXRX_ISR_TXOK_QCU7_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_ISR_TXOK_QCU7_LSB) & MAC_DMA_TXRX_ISR_TXOK_QCU7_MASK)
#define MAC_DMA_TXRX_ISR_TXOK_QCU7_RESET                             0
#define MAC_DMA_TXRX_ISR_TXOK_QCU6_MSB                               6
#define MAC_DMA_TXRX_ISR_TXOK_QCU6_LSB                               6
#define MAC_DMA_TXRX_ISR_TXOK_QCU6_MASK                              0x00000040
#define MAC_DMA_TXRX_ISR_TXOK_QCU6_GET(x)                            (((x) & MAC_DMA_TXRX_ISR_TXOK_QCU6_MASK) >> MAC_DMA_TXRX_ISR_TXOK_QCU6_LSB)
#define MAC_DMA_TXRX_ISR_TXOK_QCU6_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_ISR_TXOK_QCU6_LSB) & MAC_DMA_TXRX_ISR_TXOK_QCU6_MASK)
#define MAC_DMA_TXRX_ISR_TXOK_QCU6_RESET                             0
#define MAC_DMA_TXRX_ISR_TXOK_QCU5_MSB                               5
#define MAC_DMA_TXRX_ISR_TXOK_QCU5_LSB                               5
#define MAC_DMA_TXRX_ISR_TXOK_QCU5_MASK                              0x00000020
#define MAC_DMA_TXRX_ISR_TXOK_QCU5_GET(x)                            (((x) & MAC_DMA_TXRX_ISR_TXOK_QCU5_MASK) >> MAC_DMA_TXRX_ISR_TXOK_QCU5_LSB)
#define MAC_DMA_TXRX_ISR_TXOK_QCU5_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_ISR_TXOK_QCU5_LSB) & MAC_DMA_TXRX_ISR_TXOK_QCU5_MASK)
#define MAC_DMA_TXRX_ISR_TXOK_QCU5_RESET                             0
#define MAC_DMA_TXRX_ISR_TXOK_QCU4_MSB                               4
#define MAC_DMA_TXRX_ISR_TXOK_QCU4_LSB                               4
#define MAC_DMA_TXRX_ISR_TXOK_QCU4_MASK                              0x00000010
#define MAC_DMA_TXRX_ISR_TXOK_QCU4_GET(x)                            (((x) & MAC_DMA_TXRX_ISR_TXOK_QCU4_MASK) >> MAC_DMA_TXRX_ISR_TXOK_QCU4_LSB)
#define MAC_DMA_TXRX_ISR_TXOK_QCU4_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_ISR_TXOK_QCU4_LSB) & MAC_DMA_TXRX_ISR_TXOK_QCU4_MASK)
#define MAC_DMA_TXRX_ISR_TXOK_QCU4_RESET                             0
#define MAC_DMA_TXRX_ISR_TXOK_QCU3_MSB                               3
#define MAC_DMA_TXRX_ISR_TXOK_QCU3_LSB                               3
#define MAC_DMA_TXRX_ISR_TXOK_QCU3_MASK                              0x00000008
#define MAC_DMA_TXRX_ISR_TXOK_QCU3_GET(x)                            (((x) & MAC_DMA_TXRX_ISR_TXOK_QCU3_MASK) >> MAC_DMA_TXRX_ISR_TXOK_QCU3_LSB)
#define MAC_DMA_TXRX_ISR_TXOK_QCU3_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_ISR_TXOK_QCU3_LSB) & MAC_DMA_TXRX_ISR_TXOK_QCU3_MASK)
#define MAC_DMA_TXRX_ISR_TXOK_QCU3_RESET                             0
#define MAC_DMA_TXRX_ISR_TXOK_QCU2_MSB                               2
#define MAC_DMA_TXRX_ISR_TXOK_QCU2_LSB                               2
#define MAC_DMA_TXRX_ISR_TXOK_QCU2_MASK                              0x00000004
#define MAC_DMA_TXRX_ISR_TXOK_QCU2_GET(x)                            (((x) & MAC_DMA_TXRX_ISR_TXOK_QCU2_MASK) >> MAC_DMA_TXRX_ISR_TXOK_QCU2_LSB)
#define MAC_DMA_TXRX_ISR_TXOK_QCU2_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_ISR_TXOK_QCU2_LSB) & MAC_DMA_TXRX_ISR_TXOK_QCU2_MASK)
#define MAC_DMA_TXRX_ISR_TXOK_QCU2_RESET                             0
#define MAC_DMA_TXRX_ISR_TXOK_QCU1_MSB                               1
#define MAC_DMA_TXRX_ISR_TXOK_QCU1_LSB                               1
#define MAC_DMA_TXRX_ISR_TXOK_QCU1_MASK                              0x00000002
#define MAC_DMA_TXRX_ISR_TXOK_QCU1_GET(x)                            (((x) & MAC_DMA_TXRX_ISR_TXOK_QCU1_MASK) >> MAC_DMA_TXRX_ISR_TXOK_QCU1_LSB)
#define MAC_DMA_TXRX_ISR_TXOK_QCU1_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_ISR_TXOK_QCU1_LSB) & MAC_DMA_TXRX_ISR_TXOK_QCU1_MASK)
#define MAC_DMA_TXRX_ISR_TXOK_QCU1_RESET                             0
#define MAC_DMA_TXRX_ISR_TXOK_QCU0_MSB                               0
#define MAC_DMA_TXRX_ISR_TXOK_QCU0_LSB                               0
#define MAC_DMA_TXRX_ISR_TXOK_QCU0_MASK                              0x00000001
#define MAC_DMA_TXRX_ISR_TXOK_QCU0_GET(x)                            (((x) & MAC_DMA_TXRX_ISR_TXOK_QCU0_MASK) >> MAC_DMA_TXRX_ISR_TXOK_QCU0_LSB)
#define MAC_DMA_TXRX_ISR_TXOK_QCU0_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_ISR_TXOK_QCU0_LSB) & MAC_DMA_TXRX_ISR_TXOK_QCU0_MASK)
#define MAC_DMA_TXRX_ISR_TXOK_QCU0_RESET                             0
#define MAC_DMA_TXRX_ISR_ADDRESS                                     0x0084
#define MAC_DMA_TXRX_ISR_HW_MASK                                     0x00003fff
#define MAC_DMA_TXRX_ISR_SW_MASK                                     0x00003fff
#define MAC_DMA_TXRX_ISR_HW_WRITE_MASK                               0x00003fff
#define MAC_DMA_TXRX_ISR_SW_WRITE_MASK                               0x00003fff
#define MAC_DMA_TXRX_ISR_RSTMASK                                     0xffffffff
#define MAC_DMA_TXRX_ISR_RESET                                       0x00000000

// 0x0088 (MAC_DMA_ISR_S1)
#define MAC_DMA_ISR_S1_RSVD_2_MSB                                    31
#define MAC_DMA_ISR_S1_RSVD_2_LSB                                    26
#define MAC_DMA_ISR_S1_RSVD_2_MASK                                   0xfc000000
#define MAC_DMA_ISR_S1_RSVD_2_GET(x)                                 (((x) & MAC_DMA_ISR_S1_RSVD_2_MASK) >> MAC_DMA_ISR_S1_RSVD_2_LSB)
#define MAC_DMA_ISR_S1_RSVD_2_SET(x)                                 (((0 | (x)) << MAC_DMA_ISR_S1_RSVD_2_LSB) & MAC_DMA_ISR_S1_RSVD_2_MASK)
#define MAC_DMA_ISR_S1_RSVD_2_RESET                                  0
#define MAC_DMA_ISR_S1_TXEOL_MSB                                     25
#define MAC_DMA_ISR_S1_TXEOL_LSB                                     16
#define MAC_DMA_ISR_S1_TXEOL_MASK                                    0x03ff0000
#define MAC_DMA_ISR_S1_TXEOL_GET(x)                                  (((x) & MAC_DMA_ISR_S1_TXEOL_MASK) >> MAC_DMA_ISR_S1_TXEOL_LSB)
#define MAC_DMA_ISR_S1_TXEOL_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_S1_TXEOL_LSB) & MAC_DMA_ISR_S1_TXEOL_MASK)
#define MAC_DMA_ISR_S1_TXEOL_RESET                                   0
#define MAC_DMA_ISR_S1_RSVD_1_MSB                                    15
#define MAC_DMA_ISR_S1_RSVD_1_LSB                                    10
#define MAC_DMA_ISR_S1_RSVD_1_MASK                                   0x0000fc00
#define MAC_DMA_ISR_S1_RSVD_1_GET(x)                                 (((x) & MAC_DMA_ISR_S1_RSVD_1_MASK) >> MAC_DMA_ISR_S1_RSVD_1_LSB)
#define MAC_DMA_ISR_S1_RSVD_1_SET(x)                                 (((0 | (x)) << MAC_DMA_ISR_S1_RSVD_1_LSB) & MAC_DMA_ISR_S1_RSVD_1_MASK)
#define MAC_DMA_ISR_S1_RSVD_1_RESET                                  0
#define MAC_DMA_ISR_S1_TXERR_MSB                                     9
#define MAC_DMA_ISR_S1_TXERR_LSB                                     0
#define MAC_DMA_ISR_S1_TXERR_MASK                                    0x000003ff
#define MAC_DMA_ISR_S1_TXERR_GET(x)                                  (((x) & MAC_DMA_ISR_S1_TXERR_MASK) >> MAC_DMA_ISR_S1_TXERR_LSB)
#define MAC_DMA_ISR_S1_TXERR_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_S1_TXERR_LSB) & MAC_DMA_ISR_S1_TXERR_MASK)
#define MAC_DMA_ISR_S1_TXERR_RESET                                   0
#define MAC_DMA_ISR_S1_ADDRESS                                       0x0088
#define MAC_DMA_ISR_S1_HW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S1_SW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S1_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S1_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S1_RSTMASK                                       0xffffffff
#define MAC_DMA_ISR_S1_RESET                                         0x00000000

// 0x008c (MAC_DMA_ISR_S2)
#define MAC_DMA_ISR_S2_RSVD_MSB                                      31
#define MAC_DMA_ISR_S2_RSVD_LSB                                      31
#define MAC_DMA_ISR_S2_RSVD_MASK                                     0x80000000
#define MAC_DMA_ISR_S2_RSVD_GET(x)                                   (((x) & MAC_DMA_ISR_S2_RSVD_MASK) >> MAC_DMA_ISR_S2_RSVD_LSB)
#define MAC_DMA_ISR_S2_RSVD_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_S2_RSVD_LSB) & MAC_DMA_ISR_S2_RSVD_MASK)
#define MAC_DMA_ISR_S2_RSVD_RESET                                    0
#define MAC_DMA_ISR_S2_TBTT_TIME_STA_0_MSB                           30
#define MAC_DMA_ISR_S2_TBTT_TIME_STA_0_LSB                           30
#define MAC_DMA_ISR_S2_TBTT_TIME_STA_0_MASK                          0x40000000
#define MAC_DMA_ISR_S2_TBTT_TIME_STA_0_GET(x)                        (((x) & MAC_DMA_ISR_S2_TBTT_TIME_STA_0_MASK) >> MAC_DMA_ISR_S2_TBTT_TIME_STA_0_LSB)
#define MAC_DMA_ISR_S2_TBTT_TIME_STA_0_SET(x)                        (((0 | (x)) << MAC_DMA_ISR_S2_TBTT_TIME_STA_0_LSB) & MAC_DMA_ISR_S2_TBTT_TIME_STA_0_MASK)
#define MAC_DMA_ISR_S2_TBTT_TIME_STA_0_RESET                         0
#define MAC_DMA_ISR_S2_TSFOOR_STA_0_MSB                              29
#define MAC_DMA_ISR_S2_TSFOOR_STA_0_LSB                              29
#define MAC_DMA_ISR_S2_TSFOOR_STA_0_MASK                             0x20000000
#define MAC_DMA_ISR_S2_TSFOOR_STA_0_GET(x)                           (((x) & MAC_DMA_ISR_S2_TSFOOR_STA_0_MASK) >> MAC_DMA_ISR_S2_TSFOOR_STA_0_LSB)
#define MAC_DMA_ISR_S2_TSFOOR_STA_0_SET(x)                           (((0 | (x)) << MAC_DMA_ISR_S2_TSFOOR_STA_0_LSB) & MAC_DMA_ISR_S2_TSFOOR_STA_0_MASK)
#define MAC_DMA_ISR_S2_TSFOOR_STA_0_RESET                            0
#define MAC_DMA_ISR_S2_DTIM_STA_0_MSB                                28
#define MAC_DMA_ISR_S2_DTIM_STA_0_LSB                                28
#define MAC_DMA_ISR_S2_DTIM_STA_0_MASK                               0x10000000
#define MAC_DMA_ISR_S2_DTIM_STA_0_GET(x)                             (((x) & MAC_DMA_ISR_S2_DTIM_STA_0_MASK) >> MAC_DMA_ISR_S2_DTIM_STA_0_LSB)
#define MAC_DMA_ISR_S2_DTIM_STA_0_SET(x)                             (((0 | (x)) << MAC_DMA_ISR_S2_DTIM_STA_0_LSB) & MAC_DMA_ISR_S2_DTIM_STA_0_MASK)
#define MAC_DMA_ISR_S2_DTIM_STA_0_RESET                              0
#define MAC_DMA_ISR_S2_CABTO_STA_0_MSB                               27
#define MAC_DMA_ISR_S2_CABTO_STA_0_LSB                               27
#define MAC_DMA_ISR_S2_CABTO_STA_0_MASK                              0x08000000
#define MAC_DMA_ISR_S2_CABTO_STA_0_GET(x)                            (((x) & MAC_DMA_ISR_S2_CABTO_STA_0_MASK) >> MAC_DMA_ISR_S2_CABTO_STA_0_LSB)
#define MAC_DMA_ISR_S2_CABTO_STA_0_SET(x)                            (((0 | (x)) << MAC_DMA_ISR_S2_CABTO_STA_0_LSB) & MAC_DMA_ISR_S2_CABTO_STA_0_MASK)
#define MAC_DMA_ISR_S2_CABTO_STA_0_RESET                             0
#define MAC_DMA_ISR_S2_BCNTO_STA_0_MSB                               26
#define MAC_DMA_ISR_S2_BCNTO_STA_0_LSB                               26
#define MAC_DMA_ISR_S2_BCNTO_STA_0_MASK                              0x04000000
#define MAC_DMA_ISR_S2_BCNTO_STA_0_GET(x)                            (((x) & MAC_DMA_ISR_S2_BCNTO_STA_0_MASK) >> MAC_DMA_ISR_S2_BCNTO_STA_0_LSB)
#define MAC_DMA_ISR_S2_BCNTO_STA_0_SET(x)                            (((0 | (x)) << MAC_DMA_ISR_S2_BCNTO_STA_0_LSB) & MAC_DMA_ISR_S2_BCNTO_STA_0_MASK)
#define MAC_DMA_ISR_S2_BCNTO_STA_0_RESET                             0
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_0_MSB                            25
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_0_LSB                            25
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_0_MASK                           0x02000000
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_0_GET(x)                         (((x) & MAC_DMA_ISR_S2_DTIMSYNC_STA_0_MASK) >> MAC_DMA_ISR_S2_DTIMSYNC_STA_0_LSB)
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_0_SET(x)                         (((0 | (x)) << MAC_DMA_ISR_S2_DTIMSYNC_STA_0_LSB) & MAC_DMA_ISR_S2_DTIMSYNC_STA_0_MASK)
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_0_RESET                          0
#define MAC_DMA_ISR_S2_CABEND_STA_0_MSB                              24
#define MAC_DMA_ISR_S2_CABEND_STA_0_LSB                              24
#define MAC_DMA_ISR_S2_CABEND_STA_0_MASK                             0x01000000
#define MAC_DMA_ISR_S2_CABEND_STA_0_GET(x)                           (((x) & MAC_DMA_ISR_S2_CABEND_STA_0_MASK) >> MAC_DMA_ISR_S2_CABEND_STA_0_LSB)
#define MAC_DMA_ISR_S2_CABEND_STA_0_SET(x)                           (((0 | (x)) << MAC_DMA_ISR_S2_CABEND_STA_0_LSB) & MAC_DMA_ISR_S2_CABEND_STA_0_MASK)
#define MAC_DMA_ISR_S2_CABEND_STA_0_RESET                            0
#define MAC_DMA_ISR_S2_TIM_STA_0_MSB                                 23
#define MAC_DMA_ISR_S2_TIM_STA_0_LSB                                 23
#define MAC_DMA_ISR_S2_TIM_STA_0_MASK                                0x00800000
#define MAC_DMA_ISR_S2_TIM_STA_0_GET(x)                              (((x) & MAC_DMA_ISR_S2_TIM_STA_0_MASK) >> MAC_DMA_ISR_S2_TIM_STA_0_LSB)
#define MAC_DMA_ISR_S2_TIM_STA_0_SET(x)                              (((0 | (x)) << MAC_DMA_ISR_S2_TIM_STA_0_LSB) & MAC_DMA_ISR_S2_TIM_STA_0_MASK)
#define MAC_DMA_ISR_S2_TIM_STA_0_RESET                               0
#define MAC_DMA_ISR_S2_GTT_MSB                                       22
#define MAC_DMA_ISR_S2_GTT_LSB                                       22
#define MAC_DMA_ISR_S2_GTT_MASK                                      0x00400000
#define MAC_DMA_ISR_S2_GTT_GET(x)                                    (((x) & MAC_DMA_ISR_S2_GTT_MASK) >> MAC_DMA_ISR_S2_GTT_LSB)
#define MAC_DMA_ISR_S2_GTT_SET(x)                                    (((0 | (x)) << MAC_DMA_ISR_S2_GTT_LSB) & MAC_DMA_ISR_S2_GTT_MASK)
#define MAC_DMA_ISR_S2_GTT_RESET                                     0
#define MAC_DMA_ISR_S2_CST_MSB                                       21
#define MAC_DMA_ISR_S2_CST_LSB                                       21
#define MAC_DMA_ISR_S2_CST_MASK                                      0x00200000
#define MAC_DMA_ISR_S2_CST_GET(x)                                    (((x) & MAC_DMA_ISR_S2_CST_MASK) >> MAC_DMA_ISR_S2_CST_LSB)
#define MAC_DMA_ISR_S2_CST_SET(x)                                    (((0 | (x)) << MAC_DMA_ISR_S2_CST_LSB) & MAC_DMA_ISR_S2_CST_MASK)
#define MAC_DMA_ISR_S2_CST_RESET                                     0
#define MAC_DMA_ISR_S2_TBTT_TIME_STA_1_MSB                           20
#define MAC_DMA_ISR_S2_TBTT_TIME_STA_1_LSB                           20
#define MAC_DMA_ISR_S2_TBTT_TIME_STA_1_MASK                          0x00100000
#define MAC_DMA_ISR_S2_TBTT_TIME_STA_1_GET(x)                        (((x) & MAC_DMA_ISR_S2_TBTT_TIME_STA_1_MASK) >> MAC_DMA_ISR_S2_TBTT_TIME_STA_1_LSB)
#define MAC_DMA_ISR_S2_TBTT_TIME_STA_1_SET(x)                        (((0 | (x)) << MAC_DMA_ISR_S2_TBTT_TIME_STA_1_LSB) & MAC_DMA_ISR_S2_TBTT_TIME_STA_1_MASK)
#define MAC_DMA_ISR_S2_TBTT_TIME_STA_1_RESET                         0
#define MAC_DMA_ISR_S2_TSFOOR_STA_1_MSB                              19
#define MAC_DMA_ISR_S2_TSFOOR_STA_1_LSB                              19
#define MAC_DMA_ISR_S2_TSFOOR_STA_1_MASK                             0x00080000
#define MAC_DMA_ISR_S2_TSFOOR_STA_1_GET(x)                           (((x) & MAC_DMA_ISR_S2_TSFOOR_STA_1_MASK) >> MAC_DMA_ISR_S2_TSFOOR_STA_1_LSB)
#define MAC_DMA_ISR_S2_TSFOOR_STA_1_SET(x)                           (((0 | (x)) << MAC_DMA_ISR_S2_TSFOOR_STA_1_LSB) & MAC_DMA_ISR_S2_TSFOOR_STA_1_MASK)
#define MAC_DMA_ISR_S2_TSFOOR_STA_1_RESET                            0
#define MAC_DMA_ISR_S2_DTIM_STA_1_MSB                                18
#define MAC_DMA_ISR_S2_DTIM_STA_1_LSB                                18
#define MAC_DMA_ISR_S2_DTIM_STA_1_MASK                               0x00040000
#define MAC_DMA_ISR_S2_DTIM_STA_1_GET(x)                             (((x) & MAC_DMA_ISR_S2_DTIM_STA_1_MASK) >> MAC_DMA_ISR_S2_DTIM_STA_1_LSB)
#define MAC_DMA_ISR_S2_DTIM_STA_1_SET(x)                             (((0 | (x)) << MAC_DMA_ISR_S2_DTIM_STA_1_LSB) & MAC_DMA_ISR_S2_DTIM_STA_1_MASK)
#define MAC_DMA_ISR_S2_DTIM_STA_1_RESET                              0
#define MAC_DMA_ISR_S2_CABTO_STA_1_MSB                               17
#define MAC_DMA_ISR_S2_CABTO_STA_1_LSB                               17
#define MAC_DMA_ISR_S2_CABTO_STA_1_MASK                              0x00020000
#define MAC_DMA_ISR_S2_CABTO_STA_1_GET(x)                            (((x) & MAC_DMA_ISR_S2_CABTO_STA_1_MASK) >> MAC_DMA_ISR_S2_CABTO_STA_1_LSB)
#define MAC_DMA_ISR_S2_CABTO_STA_1_SET(x)                            (((0 | (x)) << MAC_DMA_ISR_S2_CABTO_STA_1_LSB) & MAC_DMA_ISR_S2_CABTO_STA_1_MASK)
#define MAC_DMA_ISR_S2_CABTO_STA_1_RESET                             0
#define MAC_DMA_ISR_S2_BCNTO_STA_1_MSB                               16
#define MAC_DMA_ISR_S2_BCNTO_STA_1_LSB                               16
#define MAC_DMA_ISR_S2_BCNTO_STA_1_MASK                              0x00010000
#define MAC_DMA_ISR_S2_BCNTO_STA_1_GET(x)                            (((x) & MAC_DMA_ISR_S2_BCNTO_STA_1_MASK) >> MAC_DMA_ISR_S2_BCNTO_STA_1_LSB)
#define MAC_DMA_ISR_S2_BCNTO_STA_1_SET(x)                            (((0 | (x)) << MAC_DMA_ISR_S2_BCNTO_STA_1_LSB) & MAC_DMA_ISR_S2_BCNTO_STA_1_MASK)
#define MAC_DMA_ISR_S2_BCNTO_STA_1_RESET                             0
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_1_MSB                            15
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_1_LSB                            15
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_1_MASK                           0x00008000
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_1_GET(x)                         (((x) & MAC_DMA_ISR_S2_DTIMSYNC_STA_1_MASK) >> MAC_DMA_ISR_S2_DTIMSYNC_STA_1_LSB)
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_1_SET(x)                         (((0 | (x)) << MAC_DMA_ISR_S2_DTIMSYNC_STA_1_LSB) & MAC_DMA_ISR_S2_DTIMSYNC_STA_1_MASK)
#define MAC_DMA_ISR_S2_DTIMSYNC_STA_1_RESET                          0
#define MAC_DMA_ISR_S2_CABEND_STA_1_MSB                              14
#define MAC_DMA_ISR_S2_CABEND_STA_1_LSB                              14
#define MAC_DMA_ISR_S2_CABEND_STA_1_MASK                             0x00004000
#define MAC_DMA_ISR_S2_CABEND_STA_1_GET(x)                           (((x) & MAC_DMA_ISR_S2_CABEND_STA_1_MASK) >> MAC_DMA_ISR_S2_CABEND_STA_1_LSB)
#define MAC_DMA_ISR_S2_CABEND_STA_1_SET(x)                           (((0 | (x)) << MAC_DMA_ISR_S2_CABEND_STA_1_LSB) & MAC_DMA_ISR_S2_CABEND_STA_1_MASK)
#define MAC_DMA_ISR_S2_CABEND_STA_1_RESET                            0
#define MAC_DMA_ISR_S2_TIM_STA_1_MSB                                 13
#define MAC_DMA_ISR_S2_TIM_STA_1_LSB                                 13
#define MAC_DMA_ISR_S2_TIM_STA_1_MASK                                0x00002000
#define MAC_DMA_ISR_S2_TIM_STA_1_GET(x)                              (((x) & MAC_DMA_ISR_S2_TIM_STA_1_MASK) >> MAC_DMA_ISR_S2_TIM_STA_1_LSB)
#define MAC_DMA_ISR_S2_TIM_STA_1_SET(x)                              (((0 | (x)) << MAC_DMA_ISR_S2_TIM_STA_1_LSB) & MAC_DMA_ISR_S2_TIM_STA_1_MASK)
#define MAC_DMA_ISR_S2_TIM_STA_1_RESET                               0
#define MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_MSB                            12
#define MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_LSB                            12
#define MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_MASK                           0x00001000
#define MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_GET(x)                         (((x) & MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_MASK) >> MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_LSB)
#define MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_SET(x)                         (((0 | (x)) << MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_LSB) & MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_MASK)
#define MAC_DMA_ISR_S2_PCU_RX_PTR_BAD_RESET                          0
#define MAC_DMA_ISR_S2_TDMA_APSYNC_MSB                               11
#define MAC_DMA_ISR_S2_TDMA_APSYNC_LSB                               11
#define MAC_DMA_ISR_S2_TDMA_APSYNC_MASK                              0x00000800
#define MAC_DMA_ISR_S2_TDMA_APSYNC_GET(x)                            (((x) & MAC_DMA_ISR_S2_TDMA_APSYNC_MASK) >> MAC_DMA_ISR_S2_TDMA_APSYNC_LSB)
#define MAC_DMA_ISR_S2_TDMA_APSYNC_SET(x)                            (((0 | (x)) << MAC_DMA_ISR_S2_TDMA_APSYNC_LSB) & MAC_DMA_ISR_S2_TDMA_APSYNC_MASK)
#define MAC_DMA_ISR_S2_TDMA_APSYNC_RESET                             0
#define MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_MSB                     10
#define MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_LSB                     10
#define MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_MASK                    0x00000400
#define MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_GET(x)                  (((x) & MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_MASK) >> MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_LSB)
#define MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_SET(x)                  (((0 | (x)) << MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_LSB) & MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_MASK)
#define MAC_DMA_ISR_S2_TDMA_START_TIME_ERROR_RESET                   0
#define MAC_DMA_ISR_S2_TXURN_MSB                                     9
#define MAC_DMA_ISR_S2_TXURN_LSB                                     0
#define MAC_DMA_ISR_S2_TXURN_MASK                                    0x000003ff
#define MAC_DMA_ISR_S2_TXURN_GET(x)                                  (((x) & MAC_DMA_ISR_S2_TXURN_MASK) >> MAC_DMA_ISR_S2_TXURN_LSB)
#define MAC_DMA_ISR_S2_TXURN_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_S2_TXURN_LSB) & MAC_DMA_ISR_S2_TXURN_MASK)
#define MAC_DMA_ISR_S2_TXURN_RESET                                   0
#define MAC_DMA_ISR_S2_ADDRESS                                       0x008c
#define MAC_DMA_ISR_S2_HW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S2_SW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S2_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S2_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S2_RSTMASK                                       0xffffffff
#define MAC_DMA_ISR_S2_RESET                                         0x00000000

// 0x0090 (MAC_DMA_ISR_S3)
#define MAC_DMA_ISR_S3_BMISS_STA_1_MSB                               31
#define MAC_DMA_ISR_S3_BMISS_STA_1_LSB                               31
#define MAC_DMA_ISR_S3_BMISS_STA_1_MASK                              0x80000000
#define MAC_DMA_ISR_S3_BMISS_STA_1_GET(x)                            (((x) & MAC_DMA_ISR_S3_BMISS_STA_1_MASK) >> MAC_DMA_ISR_S3_BMISS_STA_1_LSB)
#define MAC_DMA_ISR_S3_BMISS_STA_1_SET(x)                            (((0 | (x)) << MAC_DMA_ISR_S3_BMISS_STA_1_LSB) & MAC_DMA_ISR_S3_BMISS_STA_1_MASK)
#define MAC_DMA_ISR_S3_BMISS_STA_1_RESET                             0
#define MAC_DMA_ISR_S3_BMISS_STA_0_MSB                               30
#define MAC_DMA_ISR_S3_BMISS_STA_0_LSB                               30
#define MAC_DMA_ISR_S3_BMISS_STA_0_MASK                              0x40000000
#define MAC_DMA_ISR_S3_BMISS_STA_0_GET(x)                            (((x) & MAC_DMA_ISR_S3_BMISS_STA_0_MASK) >> MAC_DMA_ISR_S3_BMISS_STA_0_LSB)
#define MAC_DMA_ISR_S3_BMISS_STA_0_SET(x)                            (((0 | (x)) << MAC_DMA_ISR_S3_BMISS_STA_0_LSB) & MAC_DMA_ISR_S3_BMISS_STA_0_MASK)
#define MAC_DMA_ISR_S3_BMISS_STA_0_RESET                             0
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_MSB                        29
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_LSB                        29
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_MASK                       0x20000000
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_GET(x)                     (((x) & MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_MASK) >> MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_LSB)
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_SET(x)                     (((0 | (x)) << MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_LSB) & MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_MASK)
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_1_RESET                      0
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_MSB                       28
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_LSB                       28
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_MASK                      0x10000000
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_GET(x)                    (((x) & MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_MASK) >> MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_LSB)
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_SET(x)                    (((0 | (x)) << MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_LSB) & MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_MASK)
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_1_RESET                     0
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_MSB                        27
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_LSB                        27
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_MASK                       0x08000000
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_GET(x)                     (((x) & MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_MASK) >> MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_LSB)
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_SET(x)                     (((0 | (x)) << MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_LSB) & MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_MASK)
#define MAC_DMA_ISR_S3_PCU_RSSI_LOW_STA_0_RESET                      0
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_MSB                       26
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_LSB                       26
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_MASK                      0x04000000
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_GET(x)                    (((x) & MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_MASK) >> MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_LSB)
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_SET(x)                    (((0 | (x)) << MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_LSB) & MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_MASK)
#define MAC_DMA_ISR_S3_PCU_RSSI_HIGH_STA_0_RESET                     0
#define MAC_DMA_ISR_S3_QCBRURN_MSB                                   25
#define MAC_DMA_ISR_S3_QCBRURN_LSB                                   16
#define MAC_DMA_ISR_S3_QCBRURN_MASK                                  0x03ff0000
#define MAC_DMA_ISR_S3_QCBRURN_GET(x)                                (((x) & MAC_DMA_ISR_S3_QCBRURN_MASK) >> MAC_DMA_ISR_S3_QCBRURN_LSB)
#define MAC_DMA_ISR_S3_QCBRURN_SET(x)                                (((0 | (x)) << MAC_DMA_ISR_S3_QCBRURN_LSB) & MAC_DMA_ISR_S3_QCBRURN_MASK)
#define MAC_DMA_ISR_S3_QCBRURN_RESET                                 0
#define MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_MSB                           15
#define MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_LSB                           15
#define MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_MASK                          0x00008000
#define MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_GET(x)                        (((x) & MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_MASK) >> MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_LSB)
#define MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_SET(x)                        (((0 | (x)) << MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_LSB) & MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_MASK)
#define MAC_DMA_ISR_S3_RXDMA_HP_DP_OVF_RESET                         0
#define MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_MSB                           14
#define MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_LSB                           14
#define MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_MASK                          0x00004000
#define MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_GET(x)                        (((x) & MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_MASK) >> MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_LSB)
#define MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_SET(x)                        (((0 | (x)) << MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_LSB) & MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_MASK)
#define MAC_DMA_ISR_S3_RXDMA_LP_DP_OVF_RESET                         0
#define MAC_DMA_ISR_S3_RSVD_MSB                                      13
#define MAC_DMA_ISR_S3_RSVD_LSB                                      10
#define MAC_DMA_ISR_S3_RSVD_MASK                                     0x00003c00
#define MAC_DMA_ISR_S3_RSVD_GET(x)                                   (((x) & MAC_DMA_ISR_S3_RSVD_MASK) >> MAC_DMA_ISR_S3_RSVD_LSB)
#define MAC_DMA_ISR_S3_RSVD_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_S3_RSVD_LSB) & MAC_DMA_ISR_S3_RSVD_MASK)
#define MAC_DMA_ISR_S3_RSVD_RESET                                    0
#define MAC_DMA_ISR_S3_QCBROVF_MSB                                   9
#define MAC_DMA_ISR_S3_QCBROVF_LSB                                   0
#define MAC_DMA_ISR_S3_QCBROVF_MASK                                  0x000003ff
#define MAC_DMA_ISR_S3_QCBROVF_GET(x)                                (((x) & MAC_DMA_ISR_S3_QCBROVF_MASK) >> MAC_DMA_ISR_S3_QCBROVF_LSB)
#define MAC_DMA_ISR_S3_QCBROVF_SET(x)                                (((0 | (x)) << MAC_DMA_ISR_S3_QCBROVF_LSB) & MAC_DMA_ISR_S3_QCBROVF_MASK)
#define MAC_DMA_ISR_S3_QCBROVF_RESET                                 0
#define MAC_DMA_ISR_S3_ADDRESS                                       0x0090
#define MAC_DMA_ISR_S3_HW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S3_SW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S3_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S3_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S3_RSTMASK                                       0xffffffff
#define MAC_DMA_ISR_S3_RESET                                         0x00000000

// 0x0094 (MAC_DMA_ISR_S4)
#define MAC_DMA_ISR_S4_RSVD_2_MSB                                    31
#define MAC_DMA_ISR_S4_RSVD_2_LSB                                    26
#define MAC_DMA_ISR_S4_RSVD_2_MASK                                   0xfc000000
#define MAC_DMA_ISR_S4_RSVD_2_GET(x)                                 (((x) & MAC_DMA_ISR_S4_RSVD_2_MASK) >> MAC_DMA_ISR_S4_RSVD_2_LSB)
#define MAC_DMA_ISR_S4_RSVD_2_SET(x)                                 (((0 | (x)) << MAC_DMA_ISR_S4_RSVD_2_LSB) & MAC_DMA_ISR_S4_RSVD_2_MASK)
#define MAC_DMA_ISR_S4_RSVD_2_RESET                                  0
#define MAC_DMA_ISR_S4_TXDP_FIFO_OVF_MSB                             25
#define MAC_DMA_ISR_S4_TXDP_FIFO_OVF_LSB                             16
#define MAC_DMA_ISR_S4_TXDP_FIFO_OVF_MASK                            0x03ff0000
#define MAC_DMA_ISR_S4_TXDP_FIFO_OVF_GET(x)                          (((x) & MAC_DMA_ISR_S4_TXDP_FIFO_OVF_MASK) >> MAC_DMA_ISR_S4_TXDP_FIFO_OVF_LSB)
#define MAC_DMA_ISR_S4_TXDP_FIFO_OVF_SET(x)                          (((0 | (x)) << MAC_DMA_ISR_S4_TXDP_FIFO_OVF_LSB) & MAC_DMA_ISR_S4_TXDP_FIFO_OVF_MASK)
#define MAC_DMA_ISR_S4_TXDP_FIFO_OVF_RESET                           0
#define MAC_DMA_ISR_S4_RSVD_1_MSB                                    15
#define MAC_DMA_ISR_S4_RSVD_1_LSB                                    10
#define MAC_DMA_ISR_S4_RSVD_1_MASK                                   0x0000fc00
#define MAC_DMA_ISR_S4_RSVD_1_GET(x)                                 (((x) & MAC_DMA_ISR_S4_RSVD_1_MASK) >> MAC_DMA_ISR_S4_RSVD_1_LSB)
#define MAC_DMA_ISR_S4_RSVD_1_SET(x)                                 (((0 | (x)) << MAC_DMA_ISR_S4_RSVD_1_LSB) & MAC_DMA_ISR_S4_RSVD_1_MASK)
#define MAC_DMA_ISR_S4_RSVD_1_RESET                                  0
#define MAC_DMA_ISR_S4_QTRIG_MSB                                     9
#define MAC_DMA_ISR_S4_QTRIG_LSB                                     0
#define MAC_DMA_ISR_S4_QTRIG_MASK                                    0x000003ff
#define MAC_DMA_ISR_S4_QTRIG_GET(x)                                  (((x) & MAC_DMA_ISR_S4_QTRIG_MASK) >> MAC_DMA_ISR_S4_QTRIG_LSB)
#define MAC_DMA_ISR_S4_QTRIG_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_S4_QTRIG_LSB) & MAC_DMA_ISR_S4_QTRIG_MASK)
#define MAC_DMA_ISR_S4_QTRIG_RESET                                   0
#define MAC_DMA_ISR_S4_ADDRESS                                       0x0094
#define MAC_DMA_ISR_S4_HW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S4_SW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S4_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S4_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S4_RSTMASK                                       0xffffffff
#define MAC_DMA_ISR_S4_RESET                                         0x00000000

// 0x0098 (MAC_DMA_ISR_S5)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_MSB                      31
#define MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_LSB                      17
#define MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_MASK                     0xfffe0000
#define MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_GET(x)                   (((x) & MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_MASK) >> MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_LSB)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_SET(x)                   (((0 | (x)) << MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_LSB) & MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_MASK)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_THRESH_RESET                    0
#define MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_MSB                         16
#define MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_LSB                         16
#define MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_MASK                        0x00010000
#define MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_GET(x)                      (((x) & MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_MASK) >> MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_LSB)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_SET(x)                      (((0 | (x)) << MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_LSB) & MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_MASK)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_OVF_RESET                       0
#define MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_MSB                     15
#define MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_LSB                     0
#define MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_MASK                    0x0000ffff
#define MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_GET(x)                  (((x) & MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_MASK) >> MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_LSB)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_SET(x)                  (((0 | (x)) << MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_LSB) & MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_MASK)
#define MAC_DMA_ISR_S5_GENERIC_TIMER_TRIGGER_RESET                   0
#define MAC_DMA_ISR_S5_ADDRESS                                       0x0098
#define MAC_DMA_ISR_S5_HW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S5_SW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S5_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S5_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S5_RSTMASK                                       0xffffffff
#define MAC_DMA_ISR_S5_RESET                                         0x00000000

// 0x009c (MAC_DMA_ISR_S6)
#define MAC_DMA_ISR_S6_RSVD_MSB                                      31
#define MAC_DMA_ISR_S6_RSVD_LSB                                      25
#define MAC_DMA_ISR_S6_RSVD_MASK                                     0xfe000000
#define MAC_DMA_ISR_S6_RSVD_GET(x)                                   (((x) & MAC_DMA_ISR_S6_RSVD_MASK) >> MAC_DMA_ISR_S6_RSVD_LSB)
#define MAC_DMA_ISR_S6_RSVD_SET(x)                                   (((0 | (x)) << MAC_DMA_ISR_S6_RSVD_LSB) & MAC_DMA_ISR_S6_RSVD_MASK)
#define MAC_DMA_ISR_S6_RSVD_RESET                                    0
#define MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_MSB                24
#define MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_LSB                24
#define MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_MASK               0x01000000
#define MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_GET(x)             (((x) & MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_MASK) >> MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_LSB)
#define MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_SET(x)             (((0 | (x)) << MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_LSB) & MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_MASK)
#define MAC_DMA_ISR_S6_TX_DMA_ERR_OLE_RDY_TIMEOUT_RESET              0
#define MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_MSB                    23
#define MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_LSB                    23
#define MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_MASK                   0x00800000
#define MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_GET(x)                 (((x) & MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_MASK) >> MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_LSB)
#define MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_SET(x)                 (((0 | (x)) << MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_LSB) & MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_MASK)
#define MAC_DMA_ISR_S6_TX_DMA_ERR_AXI_TIMEOUT_RESET                  0
#define MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_MSB                         22
#define MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_LSB                         22
#define MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_MASK                        0x00400000
#define MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_GET(x)                      (((x) & MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_MASK) >> MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_LSB)
#define MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_SET(x)                      (((0 | (x)) << MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_LSB) & MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_MASK)
#define MAC_DMA_ISR_S6_TX_CONFIG_PHY_ERR_RESET                       0
#define MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_MSB                21
#define MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_LSB                21
#define MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_MASK               0x00200000
#define MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_GET(x)             (((x) & MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_MASK) >> MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_LSB)
#define MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_SET(x)             (((0 | (x)) << MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_LSB) & MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_MASK)
#define MAC_DMA_ISR_S6_TX_DMA_ERR_UNEXPECTED_NULL_RESET              0
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MSB        20
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_LSB        20
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MASK       0x00100000
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_GET(x)     (((x) & MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MASK) >> MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_LSB)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_SET(x)     (((0 | (x)) << MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_LSB) & MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MASK)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_RESET      0
#define MAC_DMA_ISR_S6_RX_DMA_RING_LWM_MSB                           19
#define MAC_DMA_ISR_S6_RX_DMA_RING_LWM_LSB                           16
#define MAC_DMA_ISR_S6_RX_DMA_RING_LWM_MASK                          0x000f0000
#define MAC_DMA_ISR_S6_RX_DMA_RING_LWM_GET(x)                        (((x) & MAC_DMA_ISR_S6_RX_DMA_RING_LWM_MASK) >> MAC_DMA_ISR_S6_RX_DMA_RING_LWM_LSB)
#define MAC_DMA_ISR_S6_RX_DMA_RING_LWM_SET(x)                        (((0 | (x)) << MAC_DMA_ISR_S6_RX_DMA_RING_LWM_LSB) & MAC_DMA_ISR_S6_RX_DMA_RING_LWM_MASK)
#define MAC_DMA_ISR_S6_RX_DMA_RING_LWM_RESET                         0
#define MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_MSB                15
#define MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_LSB                15
#define MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_MASK               0x00008000
#define MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_GET(x)             (((x) & MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_MASK) >> MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_LSB)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_SET(x)             (((0 | (x)) << MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_LSB) & MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_MASK)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_RESET              0
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_MSB                 14
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_LSB                 14
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_MASK                0x00004000
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_GET(x)              (((x) & MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_MASK) >> MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_LSB)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_SET(x)              (((0 | (x)) << MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_LSB) & MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_MASK)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_NULL_RING_MASK_RESET               0
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_MSB                 13
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_LSB                 13
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_MASK                0x00002000
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_GET(x)              (((x) & MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_MASK) >> MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_LSB)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_SET(x)              (((0 | (x)) << MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_LSB) & MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_MASK)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_ID_RESET               0
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_MSB                12
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_LSB                12
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_MASK               0x00001000
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_GET(x)             (((x) & MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_MASK) >> MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_LSB)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_SET(x)             (((0 | (x)) << MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_LSB) & MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_MASK)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_INVALID_TAG_SIG_RESET              0
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_MSB                  11
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_LSB                  11
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_MASK                 0x00000800
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_GET(x)               (((x) & MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_MASK) >> MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_LSB)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_SET(x)               (((0 | (x)) << MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_LSB) & MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_MASK)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_TOO_SHORT_RESET                0
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_MSB                    10
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_LSB                    10
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_MASK                   0x00000400
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_GET(x)                 (((x) & MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_MASK) >> MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_LSB)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_SET(x)                 (((0 | (x)) << MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_LSB) & MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_MASK)
#define MAC_DMA_ISR_S6_RX_DMA_ERR_TLV_FRAMING_RESET                  0
#define MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_MSB                       9
#define MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_LSB                       9
#define MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_MASK                      0x00000200
#define MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_GET(x)                    (((x) & MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_MASK) >> MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_LSB)
#define MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_SET(x)                    (((0 | (x)) << MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_LSB) & MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_MASK)
#define MAC_DMA_ISR_S6_BT_PRIORITY_FALLING_RESET                     0
#define MAC_DMA_ISR_S6_BT_PRIORITY_RISING_MSB                        8
#define MAC_DMA_ISR_S6_BT_PRIORITY_RISING_LSB                        8
#define MAC_DMA_ISR_S6_BT_PRIORITY_RISING_MASK                       0x00000100
#define MAC_DMA_ISR_S6_BT_PRIORITY_RISING_GET(x)                     (((x) & MAC_DMA_ISR_S6_BT_PRIORITY_RISING_MASK) >> MAC_DMA_ISR_S6_BT_PRIORITY_RISING_LSB)
#define MAC_DMA_ISR_S6_BT_PRIORITY_RISING_SET(x)                     (((0 | (x)) << MAC_DMA_ISR_S6_BT_PRIORITY_RISING_LSB) & MAC_DMA_ISR_S6_BT_PRIORITY_RISING_MASK)
#define MAC_DMA_ISR_S6_BT_PRIORITY_RISING_RESET                      0
#define MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_MSB                         7
#define MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_LSB                         7
#define MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_MASK                        0x00000080
#define MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_GET(x)                      (((x) & MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_MASK) >> MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_LSB)
#define MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_SET(x)                      (((0 | (x)) << MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_LSB) & MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_MASK)
#define MAC_DMA_ISR_S6_BT_ACTIVE_FALLING_RESET                       0
#define MAC_DMA_ISR_S6_BT_ACTIVE_RISING_MSB                          6
#define MAC_DMA_ISR_S6_BT_ACTIVE_RISING_LSB                          6
#define MAC_DMA_ISR_S6_BT_ACTIVE_RISING_MASK                         0x00000040
#define MAC_DMA_ISR_S6_BT_ACTIVE_RISING_GET(x)                       (((x) & MAC_DMA_ISR_S6_BT_ACTIVE_RISING_MASK) >> MAC_DMA_ISR_S6_BT_ACTIVE_RISING_LSB)
#define MAC_DMA_ISR_S6_BT_ACTIVE_RISING_SET(x)                       (((0 | (x)) << MAC_DMA_ISR_S6_BT_ACTIVE_RISING_LSB) & MAC_DMA_ISR_S6_BT_ACTIVE_RISING_MASK)
#define MAC_DMA_ISR_S6_BT_ACTIVE_RISING_RESET                        0
#define MAC_DMA_ISR_S6_WL_STOMPED_MSB                                5
#define MAC_DMA_ISR_S6_WL_STOMPED_LSB                                5
#define MAC_DMA_ISR_S6_WL_STOMPED_MASK                               0x00000020
#define MAC_DMA_ISR_S6_WL_STOMPED_GET(x)                             (((x) & MAC_DMA_ISR_S6_WL_STOMPED_MASK) >> MAC_DMA_ISR_S6_WL_STOMPED_LSB)
#define MAC_DMA_ISR_S6_WL_STOMPED_SET(x)                             (((0 | (x)) << MAC_DMA_ISR_S6_WL_STOMPED_LSB) & MAC_DMA_ISR_S6_WL_STOMPED_MASK)
#define MAC_DMA_ISR_S6_WL_STOMPED_RESET                              0
#define MAC_DMA_ISR_S6_BT_STOMPED_MSB                                4
#define MAC_DMA_ISR_S6_BT_STOMPED_LSB                                4
#define MAC_DMA_ISR_S6_BT_STOMPED_MASK                               0x00000010
#define MAC_DMA_ISR_S6_BT_STOMPED_GET(x)                             (((x) & MAC_DMA_ISR_S6_BT_STOMPED_MASK) >> MAC_DMA_ISR_S6_BT_STOMPED_LSB)
#define MAC_DMA_ISR_S6_BT_STOMPED_SET(x)                             (((0 | (x)) << MAC_DMA_ISR_S6_BT_STOMPED_LSB) & MAC_DMA_ISR_S6_BT_STOMPED_MASK)
#define MAC_DMA_ISR_S6_BT_STOMPED_RESET                              0
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_MSB                   3
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_LSB                   3
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_MASK                  0x00000008
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_GET(x)                (((x) & MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_MASK) >> MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_LSB)
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_SET(x)                (((0 | (x)) << MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_LSB) & MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_MASK)
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_FALLING_RESET                 0
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_MSB                    2
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_LSB                    2
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_MASK                   0x00000004
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_GET(x)                 (((x) & MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_MASK) >> MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_LSB)
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_SET(x)                 (((0 | (x)) << MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_LSB) & MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_MASK)
#define MAC_DMA_ISR_S6_BT_LOW_PRIORITY_RISING_RESET                  0
#define MAC_DMA_ISR_S6_BB_PANIC_IRQ_MSB                              1
#define MAC_DMA_ISR_S6_BB_PANIC_IRQ_LSB                              1
#define MAC_DMA_ISR_S6_BB_PANIC_IRQ_MASK                             0x00000002
#define MAC_DMA_ISR_S6_BB_PANIC_IRQ_GET(x)                           (((x) & MAC_DMA_ISR_S6_BB_PANIC_IRQ_MASK) >> MAC_DMA_ISR_S6_BB_PANIC_IRQ_LSB)
#define MAC_DMA_ISR_S6_BB_PANIC_IRQ_SET(x)                           (((0 | (x)) << MAC_DMA_ISR_S6_BB_PANIC_IRQ_LSB) & MAC_DMA_ISR_S6_BB_PANIC_IRQ_MASK)
#define MAC_DMA_ISR_S6_BB_PANIC_IRQ_RESET                            0
#define MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_MSB                        0
#define MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_LSB                        0
#define MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_MASK                       0x00000001
#define MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_GET(x)                     (((x) & MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_MASK) >> MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_LSB)
#define MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_SET(x)                     (((0 | (x)) << MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_LSB) & MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_MASK)
#define MAC_DMA_ISR_S6_BB_MAC_TEMP_SENSOR_RESET                      0
#define MAC_DMA_ISR_S6_ADDRESS                                       0x009c
#define MAC_DMA_ISR_S6_HW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S6_SW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S6_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S6_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S6_RSTMASK                                       0xffffffff
#define MAC_DMA_ISR_S6_RESET                                         0x00000000

// 0x00a0 (MAC_DMA_IMR_P)
#define MAC_DMA_IMR_P_BIT_31_MSB                                     31
#define MAC_DMA_IMR_P_BIT_31_LSB                                     31
#define MAC_DMA_IMR_P_BIT_31_MASK                                    0x80000000
#define MAC_DMA_IMR_P_BIT_31_GET(x)                                  (((x) & MAC_DMA_IMR_P_BIT_31_MASK) >> MAC_DMA_IMR_P_BIT_31_LSB)
#define MAC_DMA_IMR_P_BIT_31_SET(x)                                  (((0 | (x)) << MAC_DMA_IMR_P_BIT_31_LSB) & MAC_DMA_IMR_P_BIT_31_MASK)
#define MAC_DMA_IMR_P_BIT_31_RESET                                   0
#define MAC_DMA_IMR_P_BIT_30_MSB                                     30
#define MAC_DMA_IMR_P_BIT_30_LSB                                     30
#define MAC_DMA_IMR_P_BIT_30_MASK                                    0x40000000
#define MAC_DMA_IMR_P_BIT_30_GET(x)                                  (((x) & MAC_DMA_IMR_P_BIT_30_MASK) >> MAC_DMA_IMR_P_BIT_30_LSB)
#define MAC_DMA_IMR_P_BIT_30_SET(x)                                  (((0 | (x)) << MAC_DMA_IMR_P_BIT_30_LSB) & MAC_DMA_IMR_P_BIT_30_MASK)
#define MAC_DMA_IMR_P_BIT_30_RESET                                   0
#define MAC_DMA_IMR_P_BIT_29_MSB                                     29
#define MAC_DMA_IMR_P_BIT_29_LSB                                     29
#define MAC_DMA_IMR_P_BIT_29_MASK                                    0x20000000
#define MAC_DMA_IMR_P_BIT_29_GET(x)                                  (((x) & MAC_DMA_IMR_P_BIT_29_MASK) >> MAC_DMA_IMR_P_BIT_29_LSB)
#define MAC_DMA_IMR_P_BIT_29_SET(x)                                  (((0 | (x)) << MAC_DMA_IMR_P_BIT_29_LSB) & MAC_DMA_IMR_P_BIT_29_MASK)
#define MAC_DMA_IMR_P_BIT_29_RESET                                   0
#define MAC_DMA_IMR_P_GENTMR_MSB                                     28
#define MAC_DMA_IMR_P_GENTMR_LSB                                     28
#define MAC_DMA_IMR_P_GENTMR_MASK                                    0x10000000
#define MAC_DMA_IMR_P_GENTMR_GET(x)                                  (((x) & MAC_DMA_IMR_P_GENTMR_MASK) >> MAC_DMA_IMR_P_GENTMR_LSB)
#define MAC_DMA_IMR_P_GENTMR_SET(x)                                  (((0 | (x)) << MAC_DMA_IMR_P_GENTMR_LSB) & MAC_DMA_IMR_P_GENTMR_MASK)
#define MAC_DMA_IMR_P_GENTMR_RESET                                   0
#define MAC_DMA_IMR_P_QTRIG_MSB                                      27
#define MAC_DMA_IMR_P_QTRIG_LSB                                      27
#define MAC_DMA_IMR_P_QTRIG_MASK                                     0x08000000
#define MAC_DMA_IMR_P_QTRIG_GET(x)                                   (((x) & MAC_DMA_IMR_P_QTRIG_MASK) >> MAC_DMA_IMR_P_QTRIG_LSB)
#define MAC_DMA_IMR_P_QTRIG_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_P_QTRIG_LSB) & MAC_DMA_IMR_P_QTRIG_MASK)
#define MAC_DMA_IMR_P_QTRIG_RESET                                    0
#define MAC_DMA_IMR_P_QCBRURN_MSB                                    26
#define MAC_DMA_IMR_P_QCBRURN_LSB                                    26
#define MAC_DMA_IMR_P_QCBRURN_MASK                                   0x04000000
#define MAC_DMA_IMR_P_QCBRURN_GET(x)                                 (((x) & MAC_DMA_IMR_P_QCBRURN_MASK) >> MAC_DMA_IMR_P_QCBRURN_LSB)
#define MAC_DMA_IMR_P_QCBRURN_SET(x)                                 (((0 | (x)) << MAC_DMA_IMR_P_QCBRURN_LSB) & MAC_DMA_IMR_P_QCBRURN_MASK)
#define MAC_DMA_IMR_P_QCBRURN_RESET                                  0
#define MAC_DMA_IMR_P_QCBROVF_MSB                                    25
#define MAC_DMA_IMR_P_QCBROVF_LSB                                    25
#define MAC_DMA_IMR_P_QCBROVF_MASK                                   0x02000000
#define MAC_DMA_IMR_P_QCBROVF_GET(x)                                 (((x) & MAC_DMA_IMR_P_QCBROVF_MASK) >> MAC_DMA_IMR_P_QCBROVF_LSB)
#define MAC_DMA_IMR_P_QCBROVF_SET(x)                                 (((0 | (x)) << MAC_DMA_IMR_P_QCBROVF_LSB) & MAC_DMA_IMR_P_QCBROVF_MASK)
#define MAC_DMA_IMR_P_QCBROVF_RESET                                  0
#define MAC_DMA_IMR_P_BB_INT_MSB                                     24
#define MAC_DMA_IMR_P_BB_INT_LSB                                     24
#define MAC_DMA_IMR_P_BB_INT_MASK                                    0x01000000
#define MAC_DMA_IMR_P_BB_INT_GET(x)                                  (((x) & MAC_DMA_IMR_P_BB_INT_MASK) >> MAC_DMA_IMR_P_BB_INT_LSB)
#define MAC_DMA_IMR_P_BB_INT_SET(x)                                  (((0 | (x)) << MAC_DMA_IMR_P_BB_INT_LSB) & MAC_DMA_IMR_P_BB_INT_MASK)
#define MAC_DMA_IMR_P_BB_INT_RESET                                   0
#define MAC_DMA_IMR_P_BCNMISC_MSB                                    23
#define MAC_DMA_IMR_P_BCNMISC_LSB                                    23
#define MAC_DMA_IMR_P_BCNMISC_MASK                                   0x00800000
#define MAC_DMA_IMR_P_BCNMISC_GET(x)                                 (((x) & MAC_DMA_IMR_P_BCNMISC_MASK) >> MAC_DMA_IMR_P_BCNMISC_LSB)
#define MAC_DMA_IMR_P_BCNMISC_SET(x)                                 (((0 | (x)) << MAC_DMA_IMR_P_BCNMISC_LSB) & MAC_DMA_IMR_P_BCNMISC_MASK)
#define MAC_DMA_IMR_P_BCNMISC_RESET                                  0
#define MAC_DMA_IMR_P_OLE_INT_MSB                                    22
#define MAC_DMA_IMR_P_OLE_INT_LSB                                    22
#define MAC_DMA_IMR_P_OLE_INT_MASK                                   0x00400000
#define MAC_DMA_IMR_P_OLE_INT_GET(x)                                 (((x) & MAC_DMA_IMR_P_OLE_INT_MASK) >> MAC_DMA_IMR_P_OLE_INT_LSB)
#define MAC_DMA_IMR_P_OLE_INT_SET(x)                                 (((0 | (x)) << MAC_DMA_IMR_P_OLE_INT_LSB) & MAC_DMA_IMR_P_OLE_INT_MASK)
#define MAC_DMA_IMR_P_OLE_INT_RESET                                  0
#define MAC_DMA_IMR_P_RXINT_MSB                                      21
#define MAC_DMA_IMR_P_RXINT_LSB                                      21
#define MAC_DMA_IMR_P_RXINT_MASK                                     0x00200000
#define MAC_DMA_IMR_P_RXINT_GET(x)                                   (((x) & MAC_DMA_IMR_P_RXINT_MASK) >> MAC_DMA_IMR_P_RXINT_LSB)
#define MAC_DMA_IMR_P_RXINT_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_P_RXINT_LSB) & MAC_DMA_IMR_P_RXINT_MASK)
#define MAC_DMA_IMR_P_RXINT_RESET                                    0
#define MAC_DMA_IMR_P_BNR_MSB                                        20
#define MAC_DMA_IMR_P_BNR_LSB                                        20
#define MAC_DMA_IMR_P_BNR_MASK                                       0x00100000
#define MAC_DMA_IMR_P_BNR_GET(x)                                     (((x) & MAC_DMA_IMR_P_BNR_MASK) >> MAC_DMA_IMR_P_BNR_LSB)
#define MAC_DMA_IMR_P_BNR_SET(x)                                     (((0 | (x)) << MAC_DMA_IMR_P_BNR_LSB) & MAC_DMA_IMR_P_BNR_MASK)
#define MAC_DMA_IMR_P_BNR_RESET                                      0
#define MAC_DMA_IMR_P_BIT_19_MSB                                     19
#define MAC_DMA_IMR_P_BIT_19_LSB                                     19
#define MAC_DMA_IMR_P_BIT_19_MASK                                    0x00080000
#define MAC_DMA_IMR_P_BIT_19_GET(x)                                  (((x) & MAC_DMA_IMR_P_BIT_19_MASK) >> MAC_DMA_IMR_P_BIT_19_LSB)
#define MAC_DMA_IMR_P_BIT_19_SET(x)                                  (((0 | (x)) << MAC_DMA_IMR_P_BIT_19_LSB) & MAC_DMA_IMR_P_BIT_19_MASK)
#define MAC_DMA_IMR_P_BIT_19_RESET                                   0
#define MAC_DMA_IMR_P_BMISS_MSB                                      18
#define MAC_DMA_IMR_P_BMISS_LSB                                      18
#define MAC_DMA_IMR_P_BMISS_MASK                                     0x00040000
#define MAC_DMA_IMR_P_BMISS_GET(x)                                   (((x) & MAC_DMA_IMR_P_BMISS_MASK) >> MAC_DMA_IMR_P_BMISS_LSB)
#define MAC_DMA_IMR_P_BMISS_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_P_BMISS_LSB) & MAC_DMA_IMR_P_BMISS_MASK)
#define MAC_DMA_IMR_P_BMISS_RESET                                    0
#define MAC_DMA_IMR_P_BRSSI_MSB                                      17
#define MAC_DMA_IMR_P_BRSSI_LSB                                      17
#define MAC_DMA_IMR_P_BRSSI_MASK                                     0x00020000
#define MAC_DMA_IMR_P_BRSSI_GET(x)                                   (((x) & MAC_DMA_IMR_P_BRSSI_MASK) >> MAC_DMA_IMR_P_BRSSI_LSB)
#define MAC_DMA_IMR_P_BRSSI_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_P_BRSSI_LSB) & MAC_DMA_IMR_P_BRSSI_MASK)
#define MAC_DMA_IMR_P_BRSSI_RESET                                    0
#define MAC_DMA_IMR_P_SWBA_MSB                                       16
#define MAC_DMA_IMR_P_SWBA_LSB                                       16
#define MAC_DMA_IMR_P_SWBA_MASK                                      0x00010000
#define MAC_DMA_IMR_P_SWBA_GET(x)                                    (((x) & MAC_DMA_IMR_P_SWBA_MASK) >> MAC_DMA_IMR_P_SWBA_LSB)
#define MAC_DMA_IMR_P_SWBA_SET(x)                                    (((0 | (x)) << MAC_DMA_IMR_P_SWBA_LSB) & MAC_DMA_IMR_P_SWBA_MASK)
#define MAC_DMA_IMR_P_SWBA_RESET                                     0
#define MAC_DMA_IMR_P_BIT_15_MSB                                     15
#define MAC_DMA_IMR_P_BIT_15_LSB                                     15
#define MAC_DMA_IMR_P_BIT_15_MASK                                    0x00008000
#define MAC_DMA_IMR_P_BIT_15_GET(x)                                  (((x) & MAC_DMA_IMR_P_BIT_15_MASK) >> MAC_DMA_IMR_P_BIT_15_LSB)
#define MAC_DMA_IMR_P_BIT_15_SET(x)                                  (((0 | (x)) << MAC_DMA_IMR_P_BIT_15_LSB) & MAC_DMA_IMR_P_BIT_15_MASK)
#define MAC_DMA_IMR_P_BIT_15_RESET                                   0
#define MAC_DMA_IMR_P_BIT_14_MSB                                     14
#define MAC_DMA_IMR_P_BIT_14_LSB                                     14
#define MAC_DMA_IMR_P_BIT_14_MASK                                    0x00004000
#define MAC_DMA_IMR_P_BIT_14_GET(x)                                  (((x) & MAC_DMA_IMR_P_BIT_14_MASK) >> MAC_DMA_IMR_P_BIT_14_LSB)
#define MAC_DMA_IMR_P_BIT_14_SET(x)                                  (((0 | (x)) << MAC_DMA_IMR_P_BIT_14_LSB) & MAC_DMA_IMR_P_BIT_14_MASK)
#define MAC_DMA_IMR_P_BIT_14_RESET                                   0
#define MAC_DMA_IMR_P_SWI_MSB                                        13
#define MAC_DMA_IMR_P_SWI_LSB                                        13
#define MAC_DMA_IMR_P_SWI_MASK                                       0x00002000
#define MAC_DMA_IMR_P_SWI_GET(x)                                     (((x) & MAC_DMA_IMR_P_SWI_MASK) >> MAC_DMA_IMR_P_SWI_LSB)
#define MAC_DMA_IMR_P_SWI_SET(x)                                     (((0 | (x)) << MAC_DMA_IMR_P_SWI_LSB) & MAC_DMA_IMR_P_SWI_MASK)
#define MAC_DMA_IMR_P_SWI_RESET                                      0
#define MAC_DMA_IMR_P_MIB_MSB                                        12
#define MAC_DMA_IMR_P_MIB_LSB                                        12
#define MAC_DMA_IMR_P_MIB_MASK                                       0x00001000
#define MAC_DMA_IMR_P_MIB_GET(x)                                     (((x) & MAC_DMA_IMR_P_MIB_MASK) >> MAC_DMA_IMR_P_MIB_LSB)
#define MAC_DMA_IMR_P_MIB_SET(x)                                     (((0 | (x)) << MAC_DMA_IMR_P_MIB_LSB) & MAC_DMA_IMR_P_MIB_MASK)
#define MAC_DMA_IMR_P_MIB_RESET                                      0
#define MAC_DMA_IMR_P_TXURN_MSB                                      11
#define MAC_DMA_IMR_P_TXURN_LSB                                      11
#define MAC_DMA_IMR_P_TXURN_MASK                                     0x00000800
#define MAC_DMA_IMR_P_TXURN_GET(x)                                   (((x) & MAC_DMA_IMR_P_TXURN_MASK) >> MAC_DMA_IMR_P_TXURN_LSB)
#define MAC_DMA_IMR_P_TXURN_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_P_TXURN_LSB) & MAC_DMA_IMR_P_TXURN_MASK)
#define MAC_DMA_IMR_P_TXURN_RESET                                    0
#define MAC_DMA_IMR_P_TXEOL_MSB                                      10
#define MAC_DMA_IMR_P_TXEOL_LSB                                      10
#define MAC_DMA_IMR_P_TXEOL_MASK                                     0x00000400
#define MAC_DMA_IMR_P_TXEOL_GET(x)                                   (((x) & MAC_DMA_IMR_P_TXEOL_MASK) >> MAC_DMA_IMR_P_TXEOL_LSB)
#define MAC_DMA_IMR_P_TXEOL_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_P_TXEOL_LSB) & MAC_DMA_IMR_P_TXEOL_MASK)
#define MAC_DMA_IMR_P_TXEOL_RESET                                    0
#define MAC_DMA_IMR_P_TXNOFR_MSB                                     9
#define MAC_DMA_IMR_P_TXNOFR_LSB                                     9
#define MAC_DMA_IMR_P_TXNOFR_MASK                                    0x00000200
#define MAC_DMA_IMR_P_TXNOFR_GET(x)                                  (((x) & MAC_DMA_IMR_P_TXNOFR_MASK) >> MAC_DMA_IMR_P_TXNOFR_LSB)
#define MAC_DMA_IMR_P_TXNOFR_SET(x)                                  (((0 | (x)) << MAC_DMA_IMR_P_TXNOFR_LSB) & MAC_DMA_IMR_P_TXNOFR_MASK)
#define MAC_DMA_IMR_P_TXNOFR_RESET                                   0
#define MAC_DMA_IMR_P_TXERR_MSB                                      8
#define MAC_DMA_IMR_P_TXERR_LSB                                      8
#define MAC_DMA_IMR_P_TXERR_MASK                                     0x00000100
#define MAC_DMA_IMR_P_TXERR_GET(x)                                   (((x) & MAC_DMA_IMR_P_TXERR_MASK) >> MAC_DMA_IMR_P_TXERR_LSB)
#define MAC_DMA_IMR_P_TXERR_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_P_TXERR_LSB) & MAC_DMA_IMR_P_TXERR_MASK)
#define MAC_DMA_IMR_P_TXERR_RESET                                    0
#define MAC_DMA_IMR_P_BTINT_MSB                                      7
#define MAC_DMA_IMR_P_BTINT_LSB                                      7
#define MAC_DMA_IMR_P_BTINT_MASK                                     0x00000080
#define MAC_DMA_IMR_P_BTINT_GET(x)                                   (((x) & MAC_DMA_IMR_P_BTINT_MASK) >> MAC_DMA_IMR_P_BTINT_LSB)
#define MAC_DMA_IMR_P_BTINT_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_P_BTINT_LSB) & MAC_DMA_IMR_P_BTINT_MASK)
#define MAC_DMA_IMR_P_BTINT_RESET                                    0
#define MAC_DMA_IMR_P_TX_DMA_ERR_MSB                                 6
#define MAC_DMA_IMR_P_TX_DMA_ERR_LSB                                 6
#define MAC_DMA_IMR_P_TX_DMA_ERR_MASK                                0x00000040
#define MAC_DMA_IMR_P_TX_DMA_ERR_GET(x)                              (((x) & MAC_DMA_IMR_P_TX_DMA_ERR_MASK) >> MAC_DMA_IMR_P_TX_DMA_ERR_LSB)
#define MAC_DMA_IMR_P_TX_DMA_ERR_SET(x)                              (((0 | (x)) << MAC_DMA_IMR_P_TX_DMA_ERR_LSB) & MAC_DMA_IMR_P_TX_DMA_ERR_MASK)
#define MAC_DMA_IMR_P_TX_DMA_ERR_RESET                               0
#define MAC_DMA_IMR_P_RXORN_MSB                                      5
#define MAC_DMA_IMR_P_RXORN_LSB                                      5
#define MAC_DMA_IMR_P_RXORN_MASK                                     0x00000020
#define MAC_DMA_IMR_P_RXORN_GET(x)                                   (((x) & MAC_DMA_IMR_P_RXORN_MASK) >> MAC_DMA_IMR_P_RXORN_LSB)
#define MAC_DMA_IMR_P_RXORN_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_P_RXORN_LSB) & MAC_DMA_IMR_P_RXORN_MASK)
#define MAC_DMA_IMR_P_RXORN_RESET                                    0
#define MAC_DMA_IMR_P_BIT_4_MSB                                      4
#define MAC_DMA_IMR_P_BIT_4_LSB                                      4
#define MAC_DMA_IMR_P_BIT_4_MASK                                     0x00000010
#define MAC_DMA_IMR_P_BIT_4_GET(x)                                   (((x) & MAC_DMA_IMR_P_BIT_4_MASK) >> MAC_DMA_IMR_P_BIT_4_LSB)
#define MAC_DMA_IMR_P_BIT_4_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_P_BIT_4_LSB) & MAC_DMA_IMR_P_BIT_4_MASK)
#define MAC_DMA_IMR_P_BIT_4_RESET                                    0
#define MAC_DMA_IMR_P_BIT_3_MSB                                      3
#define MAC_DMA_IMR_P_BIT_3_LSB                                      3
#define MAC_DMA_IMR_P_BIT_3_MASK                                     0x00000008
#define MAC_DMA_IMR_P_BIT_3_GET(x)                                   (((x) & MAC_DMA_IMR_P_BIT_3_MASK) >> MAC_DMA_IMR_P_BIT_3_LSB)
#define MAC_DMA_IMR_P_BIT_3_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_P_BIT_3_LSB) & MAC_DMA_IMR_P_BIT_3_MASK)
#define MAC_DMA_IMR_P_BIT_3_RESET                                    0
#define MAC_DMA_IMR_P_BIT_2_MSB                                      2
#define MAC_DMA_IMR_P_BIT_2_LSB                                      2
#define MAC_DMA_IMR_P_BIT_2_MASK                                     0x00000004
#define MAC_DMA_IMR_P_BIT_2_GET(x)                                   (((x) & MAC_DMA_IMR_P_BIT_2_MASK) >> MAC_DMA_IMR_P_BIT_2_LSB)
#define MAC_DMA_IMR_P_BIT_2_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_P_BIT_2_LSB) & MAC_DMA_IMR_P_BIT_2_MASK)
#define MAC_DMA_IMR_P_BIT_2_RESET                                    0
#define MAC_DMA_IMR_P_RX_DMA_ERR_MSB                                 1
#define MAC_DMA_IMR_P_RX_DMA_ERR_LSB                                 1
#define MAC_DMA_IMR_P_RX_DMA_ERR_MASK                                0x00000002
#define MAC_DMA_IMR_P_RX_DMA_ERR_GET(x)                              (((x) & MAC_DMA_IMR_P_RX_DMA_ERR_MASK) >> MAC_DMA_IMR_P_RX_DMA_ERR_LSB)
#define MAC_DMA_IMR_P_RX_DMA_ERR_SET(x)                              (((0 | (x)) << MAC_DMA_IMR_P_RX_DMA_ERR_LSB) & MAC_DMA_IMR_P_RX_DMA_ERR_MASK)
#define MAC_DMA_IMR_P_RX_DMA_ERR_RESET                               0
#define MAC_DMA_IMR_P_RX_DMA_RING_LWM_MSB                            0
#define MAC_DMA_IMR_P_RX_DMA_RING_LWM_LSB                            0
#define MAC_DMA_IMR_P_RX_DMA_RING_LWM_MASK                           0x00000001
#define MAC_DMA_IMR_P_RX_DMA_RING_LWM_GET(x)                         (((x) & MAC_DMA_IMR_P_RX_DMA_RING_LWM_MASK) >> MAC_DMA_IMR_P_RX_DMA_RING_LWM_LSB)
#define MAC_DMA_IMR_P_RX_DMA_RING_LWM_SET(x)                         (((0 | (x)) << MAC_DMA_IMR_P_RX_DMA_RING_LWM_LSB) & MAC_DMA_IMR_P_RX_DMA_RING_LWM_MASK)
#define MAC_DMA_IMR_P_RX_DMA_RING_LWM_RESET                          0
#define MAC_DMA_IMR_P_ADDRESS                                        0x00a0
#define MAC_DMA_IMR_P_HW_MASK                                        0xffffffff
#define MAC_DMA_IMR_P_SW_MASK                                        0xffffffff
#define MAC_DMA_IMR_P_HW_WRITE_MASK                                  0xffffffff
#define MAC_DMA_IMR_P_SW_WRITE_MASK                                  0xffffffff
#define MAC_DMA_IMR_P_RSTMASK                                        0xffffffff
#define MAC_DMA_IMR_P_RESET                                          0x00000000

// 0x00a4 (MAC_DMA_TXRX_IMR)
#define MAC_DMA_TXRX_IMR_RXOK_HP_MSB                                 13
#define MAC_DMA_TXRX_IMR_RXOK_HP_LSB                                 13
#define MAC_DMA_TXRX_IMR_RXOK_HP_MASK                                0x00002000
#define MAC_DMA_TXRX_IMR_RXOK_HP_GET(x)                              (((x) & MAC_DMA_TXRX_IMR_RXOK_HP_MASK) >> MAC_DMA_TXRX_IMR_RXOK_HP_LSB)
#define MAC_DMA_TXRX_IMR_RXOK_HP_SET(x)                              (((0 | (x)) << MAC_DMA_TXRX_IMR_RXOK_HP_LSB) & MAC_DMA_TXRX_IMR_RXOK_HP_MASK)
#define MAC_DMA_TXRX_IMR_RXOK_HP_RESET                               0
#define MAC_DMA_TXRX_IMR_RXOK_PPDU_MSB                               12
#define MAC_DMA_TXRX_IMR_RXOK_PPDU_LSB                               12
#define MAC_DMA_TXRX_IMR_RXOK_PPDU_MASK                              0x00001000
#define MAC_DMA_TXRX_IMR_RXOK_PPDU_GET(x)                            (((x) & MAC_DMA_TXRX_IMR_RXOK_PPDU_MASK) >> MAC_DMA_TXRX_IMR_RXOK_PPDU_LSB)
#define MAC_DMA_TXRX_IMR_RXOK_PPDU_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_IMR_RXOK_PPDU_LSB) & MAC_DMA_TXRX_IMR_RXOK_PPDU_MASK)
#define MAC_DMA_TXRX_IMR_RXOK_PPDU_RESET                             0
#define MAC_DMA_TXRX_IMR_RXOK_MPDU_MSB                               11
#define MAC_DMA_TXRX_IMR_RXOK_MPDU_LSB                               11
#define MAC_DMA_TXRX_IMR_RXOK_MPDU_MASK                              0x00000800
#define MAC_DMA_TXRX_IMR_RXOK_MPDU_GET(x)                            (((x) & MAC_DMA_TXRX_IMR_RXOK_MPDU_MASK) >> MAC_DMA_TXRX_IMR_RXOK_MPDU_LSB)
#define MAC_DMA_TXRX_IMR_RXOK_MPDU_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_IMR_RXOK_MPDU_LSB) & MAC_DMA_TXRX_IMR_RXOK_MPDU_MASK)
#define MAC_DMA_TXRX_IMR_RXOK_MPDU_RESET                             1
#define MAC_DMA_TXRX_IMR_RXOK_MSDU_MSB                               10
#define MAC_DMA_TXRX_IMR_RXOK_MSDU_LSB                               10
#define MAC_DMA_TXRX_IMR_RXOK_MSDU_MASK                              0x00000400
#define MAC_DMA_TXRX_IMR_RXOK_MSDU_GET(x)                            (((x) & MAC_DMA_TXRX_IMR_RXOK_MSDU_MASK) >> MAC_DMA_TXRX_IMR_RXOK_MSDU_LSB)
#define MAC_DMA_TXRX_IMR_RXOK_MSDU_SET(x)                            (((0 | (x)) << MAC_DMA_TXRX_IMR_RXOK_MSDU_LSB) & MAC_DMA_TXRX_IMR_RXOK_MSDU_MASK)
#define MAC_DMA_TXRX_IMR_RXOK_MSDU_RESET                             0
#define MAC_DMA_TXRX_IMR_TXOK_MSB                                    9
#define MAC_DMA_TXRX_IMR_TXOK_LSB                                    0
#define MAC_DMA_TXRX_IMR_TXOK_MASK                                   0x000003ff
#define MAC_DMA_TXRX_IMR_TXOK_GET(x)                                 (((x) & MAC_DMA_TXRX_IMR_TXOK_MASK) >> MAC_DMA_TXRX_IMR_TXOK_LSB)
#define MAC_DMA_TXRX_IMR_TXOK_SET(x)                                 (((0 | (x)) << MAC_DMA_TXRX_IMR_TXOK_LSB) & MAC_DMA_TXRX_IMR_TXOK_MASK)
#define MAC_DMA_TXRX_IMR_TXOK_RESET                                  1023
#define MAC_DMA_TXRX_IMR_ADDRESS                                     0x00a4
#define MAC_DMA_TXRX_IMR_HW_MASK                                     0x00003fff
#define MAC_DMA_TXRX_IMR_SW_MASK                                     0x00003fff
#define MAC_DMA_TXRX_IMR_HW_WRITE_MASK                               0x00000000
#define MAC_DMA_TXRX_IMR_SW_WRITE_MASK                               0x00003fff
#define MAC_DMA_TXRX_IMR_RSTMASK                                     0xffffffff
#define MAC_DMA_TXRX_IMR_RESET                                       0x00000bff

// 0x00a8 (MAC_DMA_IMR_S1)
#define MAC_DMA_IMR_S1_RSVD_2_MSB                                    31
#define MAC_DMA_IMR_S1_RSVD_2_LSB                                    26
#define MAC_DMA_IMR_S1_RSVD_2_MASK                                   0xfc000000
#define MAC_DMA_IMR_S1_RSVD_2_GET(x)                                 (((x) & MAC_DMA_IMR_S1_RSVD_2_MASK) >> MAC_DMA_IMR_S1_RSVD_2_LSB)
#define MAC_DMA_IMR_S1_RSVD_2_SET(x)                                 (((0 | (x)) << MAC_DMA_IMR_S1_RSVD_2_LSB) & MAC_DMA_IMR_S1_RSVD_2_MASK)
#define MAC_DMA_IMR_S1_RSVD_2_RESET                                  0
#define MAC_DMA_IMR_S1_TXEOL_MSB                                     25
#define MAC_DMA_IMR_S1_TXEOL_LSB                                     16
#define MAC_DMA_IMR_S1_TXEOL_MASK                                    0x03ff0000
#define MAC_DMA_IMR_S1_TXEOL_GET(x)                                  (((x) & MAC_DMA_IMR_S1_TXEOL_MASK) >> MAC_DMA_IMR_S1_TXEOL_LSB)
#define MAC_DMA_IMR_S1_TXEOL_SET(x)                                  (((0 | (x)) << MAC_DMA_IMR_S1_TXEOL_LSB) & MAC_DMA_IMR_S1_TXEOL_MASK)
#define MAC_DMA_IMR_S1_TXEOL_RESET                                   0
#define MAC_DMA_IMR_S1_RSVD_1_MSB                                    15
#define MAC_DMA_IMR_S1_RSVD_1_LSB                                    10
#define MAC_DMA_IMR_S1_RSVD_1_MASK                                   0x0000fc00
#define MAC_DMA_IMR_S1_RSVD_1_GET(x)                                 (((x) & MAC_DMA_IMR_S1_RSVD_1_MASK) >> MAC_DMA_IMR_S1_RSVD_1_LSB)
#define MAC_DMA_IMR_S1_RSVD_1_SET(x)                                 (((0 | (x)) << MAC_DMA_IMR_S1_RSVD_1_LSB) & MAC_DMA_IMR_S1_RSVD_1_MASK)
#define MAC_DMA_IMR_S1_RSVD_1_RESET                                  0
#define MAC_DMA_IMR_S1_TXERR_MSB                                     9
#define MAC_DMA_IMR_S1_TXERR_LSB                                     0
#define MAC_DMA_IMR_S1_TXERR_MASK                                    0x000003ff
#define MAC_DMA_IMR_S1_TXERR_GET(x)                                  (((x) & MAC_DMA_IMR_S1_TXERR_MASK) >> MAC_DMA_IMR_S1_TXERR_LSB)
#define MAC_DMA_IMR_S1_TXERR_SET(x)                                  (((0 | (x)) << MAC_DMA_IMR_S1_TXERR_LSB) & MAC_DMA_IMR_S1_TXERR_MASK)
#define MAC_DMA_IMR_S1_TXERR_RESET                                   0
#define MAC_DMA_IMR_S1_ADDRESS                                       0x00a8
#define MAC_DMA_IMR_S1_HW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S1_SW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S1_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S1_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S1_RSTMASK                                       0xffffffff
#define MAC_DMA_IMR_S1_RESET                                         0x00000000

// 0x00ac (MAC_DMA_IMR_S2)
#define MAC_DMA_IMR_S2_RSVD_MSB                                      31
#define MAC_DMA_IMR_S2_RSVD_LSB                                      31
#define MAC_DMA_IMR_S2_RSVD_MASK                                     0x80000000
#define MAC_DMA_IMR_S2_RSVD_GET(x)                                   (((x) & MAC_DMA_IMR_S2_RSVD_MASK) >> MAC_DMA_IMR_S2_RSVD_LSB)
#define MAC_DMA_IMR_S2_RSVD_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_S2_RSVD_LSB) & MAC_DMA_IMR_S2_RSVD_MASK)
#define MAC_DMA_IMR_S2_RSVD_RESET                                    0
#define MAC_DMA_IMR_S2_TBTT_TIME_STA_0_MSB                           30
#define MAC_DMA_IMR_S2_TBTT_TIME_STA_0_LSB                           30
#define MAC_DMA_IMR_S2_TBTT_TIME_STA_0_MASK                          0x40000000
#define MAC_DMA_IMR_S2_TBTT_TIME_STA_0_GET(x)                        (((x) & MAC_DMA_IMR_S2_TBTT_TIME_STA_0_MASK) >> MAC_DMA_IMR_S2_TBTT_TIME_STA_0_LSB)
#define MAC_DMA_IMR_S2_TBTT_TIME_STA_0_SET(x)                        (((0 | (x)) << MAC_DMA_IMR_S2_TBTT_TIME_STA_0_LSB) & MAC_DMA_IMR_S2_TBTT_TIME_STA_0_MASK)
#define MAC_DMA_IMR_S2_TBTT_TIME_STA_0_RESET                         0
#define MAC_DMA_IMR_S2_TSFOOR_STA_0_MSB                              29
#define MAC_DMA_IMR_S2_TSFOOR_STA_0_LSB                              29
#define MAC_DMA_IMR_S2_TSFOOR_STA_0_MASK                             0x20000000
#define MAC_DMA_IMR_S2_TSFOOR_STA_0_GET(x)                           (((x) & MAC_DMA_IMR_S2_TSFOOR_STA_0_MASK) >> MAC_DMA_IMR_S2_TSFOOR_STA_0_LSB)
#define MAC_DMA_IMR_S2_TSFOOR_STA_0_SET(x)                           (((0 | (x)) << MAC_DMA_IMR_S2_TSFOOR_STA_0_LSB) & MAC_DMA_IMR_S2_TSFOOR_STA_0_MASK)
#define MAC_DMA_IMR_S2_TSFOOR_STA_0_RESET                            0
#define MAC_DMA_IMR_S2_DTIM_STA_0_MSB                                28
#define MAC_DMA_IMR_S2_DTIM_STA_0_LSB                                28
#define MAC_DMA_IMR_S2_DTIM_STA_0_MASK                               0x10000000
#define MAC_DMA_IMR_S2_DTIM_STA_0_GET(x)                             (((x) & MAC_DMA_IMR_S2_DTIM_STA_0_MASK) >> MAC_DMA_IMR_S2_DTIM_STA_0_LSB)
#define MAC_DMA_IMR_S2_DTIM_STA_0_SET(x)                             (((0 | (x)) << MAC_DMA_IMR_S2_DTIM_STA_0_LSB) & MAC_DMA_IMR_S2_DTIM_STA_0_MASK)
#define MAC_DMA_IMR_S2_DTIM_STA_0_RESET                              0
#define MAC_DMA_IMR_S2_CABTO_STA_0_MSB                               27
#define MAC_DMA_IMR_S2_CABTO_STA_0_LSB                               27
#define MAC_DMA_IMR_S2_CABTO_STA_0_MASK                              0x08000000
#define MAC_DMA_IMR_S2_CABTO_STA_0_GET(x)                            (((x) & MAC_DMA_IMR_S2_CABTO_STA_0_MASK) >> MAC_DMA_IMR_S2_CABTO_STA_0_LSB)
#define MAC_DMA_IMR_S2_CABTO_STA_0_SET(x)                            (((0 | (x)) << MAC_DMA_IMR_S2_CABTO_STA_0_LSB) & MAC_DMA_IMR_S2_CABTO_STA_0_MASK)
#define MAC_DMA_IMR_S2_CABTO_STA_0_RESET                             0
#define MAC_DMA_IMR_S2_BCNTO_STA_0_MSB                               26
#define MAC_DMA_IMR_S2_BCNTO_STA_0_LSB                               26
#define MAC_DMA_IMR_S2_BCNTO_STA_0_MASK                              0x04000000
#define MAC_DMA_IMR_S2_BCNTO_STA_0_GET(x)                            (((x) & MAC_DMA_IMR_S2_BCNTO_STA_0_MASK) >> MAC_DMA_IMR_S2_BCNTO_STA_0_LSB)
#define MAC_DMA_IMR_S2_BCNTO_STA_0_SET(x)                            (((0 | (x)) << MAC_DMA_IMR_S2_BCNTO_STA_0_LSB) & MAC_DMA_IMR_S2_BCNTO_STA_0_MASK)
#define MAC_DMA_IMR_S2_BCNTO_STA_0_RESET                             0
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_0_MSB                            25
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_0_LSB                            25
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_0_MASK                           0x02000000
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_0_GET(x)                         (((x) & MAC_DMA_IMR_S2_DTIMSYNC_STA_0_MASK) >> MAC_DMA_IMR_S2_DTIMSYNC_STA_0_LSB)
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_0_SET(x)                         (((0 | (x)) << MAC_DMA_IMR_S2_DTIMSYNC_STA_0_LSB) & MAC_DMA_IMR_S2_DTIMSYNC_STA_0_MASK)
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_0_RESET                          0
#define MAC_DMA_IMR_S2_CABEND_STA_0_MSB                              24
#define MAC_DMA_IMR_S2_CABEND_STA_0_LSB                              24
#define MAC_DMA_IMR_S2_CABEND_STA_0_MASK                             0x01000000
#define MAC_DMA_IMR_S2_CABEND_STA_0_GET(x)                           (((x) & MAC_DMA_IMR_S2_CABEND_STA_0_MASK) >> MAC_DMA_IMR_S2_CABEND_STA_0_LSB)
#define MAC_DMA_IMR_S2_CABEND_STA_0_SET(x)                           (((0 | (x)) << MAC_DMA_IMR_S2_CABEND_STA_0_LSB) & MAC_DMA_IMR_S2_CABEND_STA_0_MASK)
#define MAC_DMA_IMR_S2_CABEND_STA_0_RESET                            0
#define MAC_DMA_IMR_S2_TIM_STA_0_MSB                                 23
#define MAC_DMA_IMR_S2_TIM_STA_0_LSB                                 23
#define MAC_DMA_IMR_S2_TIM_STA_0_MASK                                0x00800000
#define MAC_DMA_IMR_S2_TIM_STA_0_GET(x)                              (((x) & MAC_DMA_IMR_S2_TIM_STA_0_MASK) >> MAC_DMA_IMR_S2_TIM_STA_0_LSB)
#define MAC_DMA_IMR_S2_TIM_STA_0_SET(x)                              (((0 | (x)) << MAC_DMA_IMR_S2_TIM_STA_0_LSB) & MAC_DMA_IMR_S2_TIM_STA_0_MASK)
#define MAC_DMA_IMR_S2_TIM_STA_0_RESET                               0
#define MAC_DMA_IMR_S2_GTT_MSB                                       22
#define MAC_DMA_IMR_S2_GTT_LSB                                       22
#define MAC_DMA_IMR_S2_GTT_MASK                                      0x00400000
#define MAC_DMA_IMR_S2_GTT_GET(x)                                    (((x) & MAC_DMA_IMR_S2_GTT_MASK) >> MAC_DMA_IMR_S2_GTT_LSB)
#define MAC_DMA_IMR_S2_GTT_SET(x)                                    (((0 | (x)) << MAC_DMA_IMR_S2_GTT_LSB) & MAC_DMA_IMR_S2_GTT_MASK)
#define MAC_DMA_IMR_S2_GTT_RESET                                     0
#define MAC_DMA_IMR_S2_CST_MSB                                       21
#define MAC_DMA_IMR_S2_CST_LSB                                       21
#define MAC_DMA_IMR_S2_CST_MASK                                      0x00200000
#define MAC_DMA_IMR_S2_CST_GET(x)                                    (((x) & MAC_DMA_IMR_S2_CST_MASK) >> MAC_DMA_IMR_S2_CST_LSB)
#define MAC_DMA_IMR_S2_CST_SET(x)                                    (((0 | (x)) << MAC_DMA_IMR_S2_CST_LSB) & MAC_DMA_IMR_S2_CST_MASK)
#define MAC_DMA_IMR_S2_CST_RESET                                     0
#define MAC_DMA_IMR_S2_TBTT_TIME_STA_1_MSB                           20
#define MAC_DMA_IMR_S2_TBTT_TIME_STA_1_LSB                           20
#define MAC_DMA_IMR_S2_TBTT_TIME_STA_1_MASK                          0x00100000
#define MAC_DMA_IMR_S2_TBTT_TIME_STA_1_GET(x)                        (((x) & MAC_DMA_IMR_S2_TBTT_TIME_STA_1_MASK) >> MAC_DMA_IMR_S2_TBTT_TIME_STA_1_LSB)
#define MAC_DMA_IMR_S2_TBTT_TIME_STA_1_SET(x)                        (((0 | (x)) << MAC_DMA_IMR_S2_TBTT_TIME_STA_1_LSB) & MAC_DMA_IMR_S2_TBTT_TIME_STA_1_MASK)
#define MAC_DMA_IMR_S2_TBTT_TIME_STA_1_RESET                         0
#define MAC_DMA_IMR_S2_TSFOOR_STA_1_MSB                              19
#define MAC_DMA_IMR_S2_TSFOOR_STA_1_LSB                              19
#define MAC_DMA_IMR_S2_TSFOOR_STA_1_MASK                             0x00080000
#define MAC_DMA_IMR_S2_TSFOOR_STA_1_GET(x)                           (((x) & MAC_DMA_IMR_S2_TSFOOR_STA_1_MASK) >> MAC_DMA_IMR_S2_TSFOOR_STA_1_LSB)
#define MAC_DMA_IMR_S2_TSFOOR_STA_1_SET(x)                           (((0 | (x)) << MAC_DMA_IMR_S2_TSFOOR_STA_1_LSB) & MAC_DMA_IMR_S2_TSFOOR_STA_1_MASK)
#define MAC_DMA_IMR_S2_TSFOOR_STA_1_RESET                            0
#define MAC_DMA_IMR_S2_DTIM_STA_1_MSB                                18
#define MAC_DMA_IMR_S2_DTIM_STA_1_LSB                                18
#define MAC_DMA_IMR_S2_DTIM_STA_1_MASK                               0x00040000
#define MAC_DMA_IMR_S2_DTIM_STA_1_GET(x)                             (((x) & MAC_DMA_IMR_S2_DTIM_STA_1_MASK) >> MAC_DMA_IMR_S2_DTIM_STA_1_LSB)
#define MAC_DMA_IMR_S2_DTIM_STA_1_SET(x)                             (((0 | (x)) << MAC_DMA_IMR_S2_DTIM_STA_1_LSB) & MAC_DMA_IMR_S2_DTIM_STA_1_MASK)
#define MAC_DMA_IMR_S2_DTIM_STA_1_RESET                              0
#define MAC_DMA_IMR_S2_CABTO_STA_1_MSB                               17
#define MAC_DMA_IMR_S2_CABTO_STA_1_LSB                               17
#define MAC_DMA_IMR_S2_CABTO_STA_1_MASK                              0x00020000
#define MAC_DMA_IMR_S2_CABTO_STA_1_GET(x)                            (((x) & MAC_DMA_IMR_S2_CABTO_STA_1_MASK) >> MAC_DMA_IMR_S2_CABTO_STA_1_LSB)
#define MAC_DMA_IMR_S2_CABTO_STA_1_SET(x)                            (((0 | (x)) << MAC_DMA_IMR_S2_CABTO_STA_1_LSB) & MAC_DMA_IMR_S2_CABTO_STA_1_MASK)
#define MAC_DMA_IMR_S2_CABTO_STA_1_RESET                             0
#define MAC_DMA_IMR_S2_BCNTO_STA_1_MSB                               16
#define MAC_DMA_IMR_S2_BCNTO_STA_1_LSB                               16
#define MAC_DMA_IMR_S2_BCNTO_STA_1_MASK                              0x00010000
#define MAC_DMA_IMR_S2_BCNTO_STA_1_GET(x)                            (((x) & MAC_DMA_IMR_S2_BCNTO_STA_1_MASK) >> MAC_DMA_IMR_S2_BCNTO_STA_1_LSB)
#define MAC_DMA_IMR_S2_BCNTO_STA_1_SET(x)                            (((0 | (x)) << MAC_DMA_IMR_S2_BCNTO_STA_1_LSB) & MAC_DMA_IMR_S2_BCNTO_STA_1_MASK)
#define MAC_DMA_IMR_S2_BCNTO_STA_1_RESET                             0
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_1_MSB                            15
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_1_LSB                            15
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_1_MASK                           0x00008000
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_1_GET(x)                         (((x) & MAC_DMA_IMR_S2_DTIMSYNC_STA_1_MASK) >> MAC_DMA_IMR_S2_DTIMSYNC_STA_1_LSB)
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_1_SET(x)                         (((0 | (x)) << MAC_DMA_IMR_S2_DTIMSYNC_STA_1_LSB) & MAC_DMA_IMR_S2_DTIMSYNC_STA_1_MASK)
#define MAC_DMA_IMR_S2_DTIMSYNC_STA_1_RESET                          0
#define MAC_DMA_IMR_S2_CABEND_STA_1_MSB                              14
#define MAC_DMA_IMR_S2_CABEND_STA_1_LSB                              14
#define MAC_DMA_IMR_S2_CABEND_STA_1_MASK                             0x00004000
#define MAC_DMA_IMR_S2_CABEND_STA_1_GET(x)                           (((x) & MAC_DMA_IMR_S2_CABEND_STA_1_MASK) >> MAC_DMA_IMR_S2_CABEND_STA_1_LSB)
#define MAC_DMA_IMR_S2_CABEND_STA_1_SET(x)                           (((0 | (x)) << MAC_DMA_IMR_S2_CABEND_STA_1_LSB) & MAC_DMA_IMR_S2_CABEND_STA_1_MASK)
#define MAC_DMA_IMR_S2_CABEND_STA_1_RESET                            0
#define MAC_DMA_IMR_S2_TIM_STA_1_MSB                                 13
#define MAC_DMA_IMR_S2_TIM_STA_1_LSB                                 13
#define MAC_DMA_IMR_S2_TIM_STA_1_MASK                                0x00002000
#define MAC_DMA_IMR_S2_TIM_STA_1_GET(x)                              (((x) & MAC_DMA_IMR_S2_TIM_STA_1_MASK) >> MAC_DMA_IMR_S2_TIM_STA_1_LSB)
#define MAC_DMA_IMR_S2_TIM_STA_1_SET(x)                              (((0 | (x)) << MAC_DMA_IMR_S2_TIM_STA_1_LSB) & MAC_DMA_IMR_S2_TIM_STA_1_MASK)
#define MAC_DMA_IMR_S2_TIM_STA_1_RESET                               0
#define MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_MSB                            12
#define MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_LSB                            12
#define MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_MASK                           0x00001000
#define MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_GET(x)                         (((x) & MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_MASK) >> MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_LSB)
#define MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_SET(x)                         (((0 | (x)) << MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_LSB) & MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_MASK)
#define MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_RESET                          0
#define MAC_DMA_IMR_S2_TDMA_APSYNC_MSB                               11
#define MAC_DMA_IMR_S2_TDMA_APSYNC_LSB                               11
#define MAC_DMA_IMR_S2_TDMA_APSYNC_MASK                              0x00000800
#define MAC_DMA_IMR_S2_TDMA_APSYNC_GET(x)                            (((x) & MAC_DMA_IMR_S2_TDMA_APSYNC_MASK) >> MAC_DMA_IMR_S2_TDMA_APSYNC_LSB)
#define MAC_DMA_IMR_S2_TDMA_APSYNC_SET(x)                            (((0 | (x)) << MAC_DMA_IMR_S2_TDMA_APSYNC_LSB) & MAC_DMA_IMR_S2_TDMA_APSYNC_MASK)
#define MAC_DMA_IMR_S2_TDMA_APSYNC_RESET                             0
#define MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_MSB                     10
#define MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_LSB                     10
#define MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_MASK                    0x00000400
#define MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_GET(x)                  (((x) & MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_MASK) >> MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_LSB)
#define MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_SET(x)                  (((0 | (x)) << MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_LSB) & MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_MASK)
#define MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_RESET                   0
#define MAC_DMA_IMR_S2_TXURN_MSB                                     9
#define MAC_DMA_IMR_S2_TXURN_LSB                                     0
#define MAC_DMA_IMR_S2_TXURN_MASK                                    0x000003ff
#define MAC_DMA_IMR_S2_TXURN_GET(x)                                  (((x) & MAC_DMA_IMR_S2_TXURN_MASK) >> MAC_DMA_IMR_S2_TXURN_LSB)
#define MAC_DMA_IMR_S2_TXURN_SET(x)                                  (((0 | (x)) << MAC_DMA_IMR_S2_TXURN_LSB) & MAC_DMA_IMR_S2_TXURN_MASK)
#define MAC_DMA_IMR_S2_TXURN_RESET                                   0
#define MAC_DMA_IMR_S2_ADDRESS                                       0x00ac
#define MAC_DMA_IMR_S2_HW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S2_SW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S2_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S2_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S2_RSTMASK                                       0xffffffff
#define MAC_DMA_IMR_S2_RESET                                         0x00000000

// 0x00b0 (MAC_DMA_IMR_S3)
#define MAC_DMA_IMR_S3_BMISS_STA_1_MSB                               31
#define MAC_DMA_IMR_S3_BMISS_STA_1_LSB                               31
#define MAC_DMA_IMR_S3_BMISS_STA_1_MASK                              0x80000000
#define MAC_DMA_IMR_S3_BMISS_STA_1_GET(x)                            (((x) & MAC_DMA_IMR_S3_BMISS_STA_1_MASK) >> MAC_DMA_IMR_S3_BMISS_STA_1_LSB)
#define MAC_DMA_IMR_S3_BMISS_STA_1_SET(x)                            (((0 | (x)) << MAC_DMA_IMR_S3_BMISS_STA_1_LSB) & MAC_DMA_IMR_S3_BMISS_STA_1_MASK)
#define MAC_DMA_IMR_S3_BMISS_STA_1_RESET                             0
#define MAC_DMA_IMR_S3_BMISS_STA_0_MSB                               30
#define MAC_DMA_IMR_S3_BMISS_STA_0_LSB                               30
#define MAC_DMA_IMR_S3_BMISS_STA_0_MASK                              0x40000000
#define MAC_DMA_IMR_S3_BMISS_STA_0_GET(x)                            (((x) & MAC_DMA_IMR_S3_BMISS_STA_0_MASK) >> MAC_DMA_IMR_S3_BMISS_STA_0_LSB)
#define MAC_DMA_IMR_S3_BMISS_STA_0_SET(x)                            (((0 | (x)) << MAC_DMA_IMR_S3_BMISS_STA_0_LSB) & MAC_DMA_IMR_S3_BMISS_STA_0_MASK)
#define MAC_DMA_IMR_S3_BMISS_STA_0_RESET                             0
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_MSB                        29
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_LSB                        29
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_MASK                       0x20000000
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_GET(x)                     (((x) & MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_MASK) >> MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_LSB)
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_SET(x)                     (((0 | (x)) << MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_LSB) & MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_MASK)
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_1_RESET                      0
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_MSB                       28
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_LSB                       28
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_MASK                      0x10000000
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_GET(x)                    (((x) & MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_MASK) >> MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_LSB)
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_SET(x)                    (((0 | (x)) << MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_LSB) & MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_MASK)
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_1_RESET                     0
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_MSB                        27
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_LSB                        27
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_MASK                       0x08000000
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_GET(x)                     (((x) & MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_MASK) >> MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_LSB)
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_SET(x)                     (((0 | (x)) << MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_LSB) & MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_MASK)
#define MAC_DMA_IMR_S3_PCU_RSSI_LOW_STA_0_RESET                      0
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_MSB                       26
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_LSB                       26
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_MASK                      0x04000000
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_GET(x)                    (((x) & MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_MASK) >> MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_LSB)
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_SET(x)                    (((0 | (x)) << MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_LSB) & MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_MASK)
#define MAC_DMA_IMR_S3_PCU_RSSI_HIGH_STA_0_RESET                     0
#define MAC_DMA_IMR_S3_QCBRURN_MSB                                   25
#define MAC_DMA_IMR_S3_QCBRURN_LSB                                   16
#define MAC_DMA_IMR_S3_QCBRURN_MASK                                  0x03ff0000
#define MAC_DMA_IMR_S3_QCBRURN_GET(x)                                (((x) & MAC_DMA_IMR_S3_QCBRURN_MASK) >> MAC_DMA_IMR_S3_QCBRURN_LSB)
#define MAC_DMA_IMR_S3_QCBRURN_SET(x)                                (((0 | (x)) << MAC_DMA_IMR_S3_QCBRURN_LSB) & MAC_DMA_IMR_S3_QCBRURN_MASK)
#define MAC_DMA_IMR_S3_QCBRURN_RESET                                 0
#define MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_MSB                           15
#define MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_LSB                           15
#define MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_MASK                          0x00008000
#define MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_GET(x)                        (((x) & MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_MASK) >> MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_LSB)
#define MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_SET(x)                        (((0 | (x)) << MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_LSB) & MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_MASK)
#define MAC_DMA_IMR_S3_RXDMA_HP_DP_OVF_RESET                         0
#define MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_MSB                           14
#define MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_LSB                           14
#define MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_MASK                          0x00004000
#define MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_GET(x)                        (((x) & MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_MASK) >> MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_LSB)
#define MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_SET(x)                        (((0 | (x)) << MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_LSB) & MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_MASK)
#define MAC_DMA_IMR_S3_RXDMA_LP_DP_OVF_RESET                         0
#define MAC_DMA_IMR_S3_RSVD_MSB                                      13
#define MAC_DMA_IMR_S3_RSVD_LSB                                      10
#define MAC_DMA_IMR_S3_RSVD_MASK                                     0x00003c00
#define MAC_DMA_IMR_S3_RSVD_GET(x)                                   (((x) & MAC_DMA_IMR_S3_RSVD_MASK) >> MAC_DMA_IMR_S3_RSVD_LSB)
#define MAC_DMA_IMR_S3_RSVD_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_S3_RSVD_LSB) & MAC_DMA_IMR_S3_RSVD_MASK)
#define MAC_DMA_IMR_S3_RSVD_RESET                                    0
#define MAC_DMA_IMR_S3_QCBROVF_MSB                                   9
#define MAC_DMA_IMR_S3_QCBROVF_LSB                                   0
#define MAC_DMA_IMR_S3_QCBROVF_MASK                                  0x000003ff
#define MAC_DMA_IMR_S3_QCBROVF_GET(x)                                (((x) & MAC_DMA_IMR_S3_QCBROVF_MASK) >> MAC_DMA_IMR_S3_QCBROVF_LSB)
#define MAC_DMA_IMR_S3_QCBROVF_SET(x)                                (((0 | (x)) << MAC_DMA_IMR_S3_QCBROVF_LSB) & MAC_DMA_IMR_S3_QCBROVF_MASK)
#define MAC_DMA_IMR_S3_QCBROVF_RESET                                 0
#define MAC_DMA_IMR_S3_ADDRESS                                       0x00b0
#define MAC_DMA_IMR_S3_HW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S3_SW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S3_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S3_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S3_RSTMASK                                       0xffffffff
#define MAC_DMA_IMR_S3_RESET                                         0x00000000

// 0x00b4 (MAC_DMA_IMR_S4)
#define MAC_DMA_IMR_S4_RSVD_2_MSB                                    31
#define MAC_DMA_IMR_S4_RSVD_2_LSB                                    26
#define MAC_DMA_IMR_S4_RSVD_2_MASK                                   0xfc000000
#define MAC_DMA_IMR_S4_RSVD_2_GET(x)                                 (((x) & MAC_DMA_IMR_S4_RSVD_2_MASK) >> MAC_DMA_IMR_S4_RSVD_2_LSB)
#define MAC_DMA_IMR_S4_RSVD_2_SET(x)                                 (((0 | (x)) << MAC_DMA_IMR_S4_RSVD_2_LSB) & MAC_DMA_IMR_S4_RSVD_2_MASK)
#define MAC_DMA_IMR_S4_RSVD_2_RESET                                  0
#define MAC_DMA_IMR_S4_TXDP_FIFO_OVF_MSB                             25
#define MAC_DMA_IMR_S4_TXDP_FIFO_OVF_LSB                             16
#define MAC_DMA_IMR_S4_TXDP_FIFO_OVF_MASK                            0x03ff0000
#define MAC_DMA_IMR_S4_TXDP_FIFO_OVF_GET(x)                          (((x) & MAC_DMA_IMR_S4_TXDP_FIFO_OVF_MASK) >> MAC_DMA_IMR_S4_TXDP_FIFO_OVF_LSB)
#define MAC_DMA_IMR_S4_TXDP_FIFO_OVF_SET(x)                          (((0 | (x)) << MAC_DMA_IMR_S4_TXDP_FIFO_OVF_LSB) & MAC_DMA_IMR_S4_TXDP_FIFO_OVF_MASK)
#define MAC_DMA_IMR_S4_TXDP_FIFO_OVF_RESET                           0
#define MAC_DMA_IMR_S4_RSVD_1_MSB                                    15
#define MAC_DMA_IMR_S4_RSVD_1_LSB                                    10
#define MAC_DMA_IMR_S4_RSVD_1_MASK                                   0x0000fc00
#define MAC_DMA_IMR_S4_RSVD_1_GET(x)                                 (((x) & MAC_DMA_IMR_S4_RSVD_1_MASK) >> MAC_DMA_IMR_S4_RSVD_1_LSB)
#define MAC_DMA_IMR_S4_RSVD_1_SET(x)                                 (((0 | (x)) << MAC_DMA_IMR_S4_RSVD_1_LSB) & MAC_DMA_IMR_S4_RSVD_1_MASK)
#define MAC_DMA_IMR_S4_RSVD_1_RESET                                  0
#define MAC_DMA_IMR_S4_QTRIG_MSB                                     9
#define MAC_DMA_IMR_S4_QTRIG_LSB                                     0
#define MAC_DMA_IMR_S4_QTRIG_MASK                                    0x000003ff
#define MAC_DMA_IMR_S4_QTRIG_GET(x)                                  (((x) & MAC_DMA_IMR_S4_QTRIG_MASK) >> MAC_DMA_IMR_S4_QTRIG_LSB)
#define MAC_DMA_IMR_S4_QTRIG_SET(x)                                  (((0 | (x)) << MAC_DMA_IMR_S4_QTRIG_LSB) & MAC_DMA_IMR_S4_QTRIG_MASK)
#define MAC_DMA_IMR_S4_QTRIG_RESET                                   0
#define MAC_DMA_IMR_S4_ADDRESS                                       0x00b4
#define MAC_DMA_IMR_S4_HW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S4_SW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S4_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S4_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S4_RSTMASK                                       0xffffffff
#define MAC_DMA_IMR_S4_RESET                                         0x00000000

// 0x00b8 (MAC_DMA_IMR_S5)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_MSB                      31
#define MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_LSB                      17
#define MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_MASK                     0xfffe0000
#define MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_GET(x)                   (((x) & MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_MASK) >> MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_LSB)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_SET(x)                   (((0 | (x)) << MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_LSB) & MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_MASK)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_THRESH_RESET                    0
#define MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_MSB                         16
#define MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_LSB                         16
#define MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_MASK                        0x00010000
#define MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_GET(x)                      (((x) & MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_MASK) >> MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_LSB)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_SET(x)                      (((0 | (x)) << MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_LSB) & MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_MASK)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_OVF_RESET                       0
#define MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_MSB                     15
#define MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_LSB                     0
#define MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_MASK                    0x0000ffff
#define MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_GET(x)                  (((x) & MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_MASK) >> MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_LSB)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_SET(x)                  (((0 | (x)) << MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_LSB) & MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_MASK)
#define MAC_DMA_IMR_S5_GENERIC_TIMER_TRIGGER_RESET                   0
#define MAC_DMA_IMR_S5_ADDRESS                                       0x00b8
#define MAC_DMA_IMR_S5_HW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S5_SW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S5_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S5_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S5_RSTMASK                                       0xffffffff
#define MAC_DMA_IMR_S5_RESET                                         0x00000000

// 0x00bc (MAC_DMA_IMR_S6)
#define MAC_DMA_IMR_S6_RSVD_MSB                                      31
#define MAC_DMA_IMR_S6_RSVD_LSB                                      23
#define MAC_DMA_IMR_S6_RSVD_MASK                                     0xff800000
#define MAC_DMA_IMR_S6_RSVD_GET(x)                                   (((x) & MAC_DMA_IMR_S6_RSVD_MASK) >> MAC_DMA_IMR_S6_RSVD_LSB)
#define MAC_DMA_IMR_S6_RSVD_SET(x)                                   (((0 | (x)) << MAC_DMA_IMR_S6_RSVD_LSB) & MAC_DMA_IMR_S6_RSVD_MASK)
#define MAC_DMA_IMR_S6_RSVD_RESET                                    0
#define MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_MSB                         22
#define MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_LSB                         22
#define MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_MASK                        0x00400000
#define MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_GET(x)                      (((x) & MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_MASK) >> MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_LSB)
#define MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_SET(x)                      (((0 | (x)) << MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_LSB) & MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_MASK)
#define MAC_DMA_IMR_S6_TX_CONFIG_PHY_ERR_RESET                       0
#define MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_MSB                21
#define MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_LSB                21
#define MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_MASK               0x00200000
#define MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_GET(x)             (((x) & MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_MASK) >> MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_LSB)
#define MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_SET(x)             (((0 | (x)) << MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_LSB) & MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_MASK)
#define MAC_DMA_IMR_S6_TX_DMA_ERR_UNEXPECTED_NULL_RESET              0
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MSB        20
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_LSB        20
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MASK       0x00100000
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_GET(x)     (((x) & MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MASK) >> MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_LSB)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_SET(x)     (((0 | (x)) << MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_LSB) & MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MASK)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_RESET      0
#define MAC_DMA_IMR_S6_RX_DMA_RING_LWM_MSB                           19
#define MAC_DMA_IMR_S6_RX_DMA_RING_LWM_LSB                           16
#define MAC_DMA_IMR_S6_RX_DMA_RING_LWM_MASK                          0x000f0000
#define MAC_DMA_IMR_S6_RX_DMA_RING_LWM_GET(x)                        (((x) & MAC_DMA_IMR_S6_RX_DMA_RING_LWM_MASK) >> MAC_DMA_IMR_S6_RX_DMA_RING_LWM_LSB)
#define MAC_DMA_IMR_S6_RX_DMA_RING_LWM_SET(x)                        (((0 | (x)) << MAC_DMA_IMR_S6_RX_DMA_RING_LWM_LSB) & MAC_DMA_IMR_S6_RX_DMA_RING_LWM_MASK)
#define MAC_DMA_IMR_S6_RX_DMA_RING_LWM_RESET                         0
#define MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_MSB                15
#define MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_LSB                15
#define MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_MASK               0x00008000
#define MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_GET(x)             (((x) & MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_MASK) >> MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_LSB)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_SET(x)             (((0 | (x)) << MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_LSB) & MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_MASK)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_MULTI_DATA_TLVS_RESET              0
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_MSB                 14
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_LSB                 14
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_MASK                0x00004000
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_GET(x)              (((x) & MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_MASK) >> MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_LSB)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_SET(x)              (((0 | (x)) << MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_LSB) & MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_MASK)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_NULL_RING_MASK_RESET               0
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_MSB                 13
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_LSB                 13
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_MASK                0x00002000
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_GET(x)              (((x) & MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_MASK) >> MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_LSB)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_SET(x)              (((0 | (x)) << MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_LSB) & MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_MASK)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_ID_RESET               0
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_MSB                12
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_LSB                12
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_MASK               0x00001000
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_GET(x)             (((x) & MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_MASK) >> MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_LSB)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_SET(x)             (((0 | (x)) << MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_LSB) & MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_MASK)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_INVALID_TAG_SIG_RESET              0
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_MSB                  11
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_LSB                  11
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_MASK                 0x00000800
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_GET(x)               (((x) & MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_MASK) >> MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_LSB)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_SET(x)               (((0 | (x)) << MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_LSB) & MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_MASK)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_TOO_SHORT_RESET                0
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_MSB                    10
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_LSB                    10
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_MASK                   0x00000400
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_GET(x)                 (((x) & MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_MASK) >> MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_LSB)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_SET(x)                 (((0 | (x)) << MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_LSB) & MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_MASK)
#define MAC_DMA_IMR_S6_RX_DMA_ERR_TLV_FRAMING_RESET                  0
#define MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_MSB                       9
#define MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_LSB                       9
#define MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_MASK                      0x00000200
#define MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_GET(x)                    (((x) & MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_MASK) >> MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_LSB)
#define MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_SET(x)                    (((0 | (x)) << MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_LSB) & MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_MASK)
#define MAC_DMA_IMR_S6_BT_PRIORITY_FALLING_RESET                     0
#define MAC_DMA_IMR_S6_BT_PRIORITY_RISING_MSB                        8
#define MAC_DMA_IMR_S6_BT_PRIORITY_RISING_LSB                        8
#define MAC_DMA_IMR_S6_BT_PRIORITY_RISING_MASK                       0x00000100
#define MAC_DMA_IMR_S6_BT_PRIORITY_RISING_GET(x)                     (((x) & MAC_DMA_IMR_S6_BT_PRIORITY_RISING_MASK) >> MAC_DMA_IMR_S6_BT_PRIORITY_RISING_LSB)
#define MAC_DMA_IMR_S6_BT_PRIORITY_RISING_SET(x)                     (((0 | (x)) << MAC_DMA_IMR_S6_BT_PRIORITY_RISING_LSB) & MAC_DMA_IMR_S6_BT_PRIORITY_RISING_MASK)
#define MAC_DMA_IMR_S6_BT_PRIORITY_RISING_RESET                      0
#define MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_MSB                         7
#define MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_LSB                         7
#define MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_MASK                        0x00000080
#define MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_GET(x)                      (((x) & MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_MASK) >> MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_LSB)
#define MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_SET(x)                      (((0 | (x)) << MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_LSB) & MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_MASK)
#define MAC_DMA_IMR_S6_BT_ACTIVE_FALLING_RESET                       0
#define MAC_DMA_IMR_S6_BT_ACTIVE_RISING_MSB                          6
#define MAC_DMA_IMR_S6_BT_ACTIVE_RISING_LSB                          6
#define MAC_DMA_IMR_S6_BT_ACTIVE_RISING_MASK                         0x00000040
#define MAC_DMA_IMR_S6_BT_ACTIVE_RISING_GET(x)                       (((x) & MAC_DMA_IMR_S6_BT_ACTIVE_RISING_MASK) >> MAC_DMA_IMR_S6_BT_ACTIVE_RISING_LSB)
#define MAC_DMA_IMR_S6_BT_ACTIVE_RISING_SET(x)                       (((0 | (x)) << MAC_DMA_IMR_S6_BT_ACTIVE_RISING_LSB) & MAC_DMA_IMR_S6_BT_ACTIVE_RISING_MASK)
#define MAC_DMA_IMR_S6_BT_ACTIVE_RISING_RESET                        0
#define MAC_DMA_IMR_S6_WL_STOMPED_MSB                                5
#define MAC_DMA_IMR_S6_WL_STOMPED_LSB                                5
#define MAC_DMA_IMR_S6_WL_STOMPED_MASK                               0x00000020
#define MAC_DMA_IMR_S6_WL_STOMPED_GET(x)                             (((x) & MAC_DMA_IMR_S6_WL_STOMPED_MASK) >> MAC_DMA_IMR_S6_WL_STOMPED_LSB)
#define MAC_DMA_IMR_S6_WL_STOMPED_SET(x)                             (((0 | (x)) << MAC_DMA_IMR_S6_WL_STOMPED_LSB) & MAC_DMA_IMR_S6_WL_STOMPED_MASK)
#define MAC_DMA_IMR_S6_WL_STOMPED_RESET                              0
#define MAC_DMA_IMR_S6_BT_STOMPED_MSB                                4
#define MAC_DMA_IMR_S6_BT_STOMPED_LSB                                4
#define MAC_DMA_IMR_S6_BT_STOMPED_MASK                               0x00000010
#define MAC_DMA_IMR_S6_BT_STOMPED_GET(x)                             (((x) & MAC_DMA_IMR_S6_BT_STOMPED_MASK) >> MAC_DMA_IMR_S6_BT_STOMPED_LSB)
#define MAC_DMA_IMR_S6_BT_STOMPED_SET(x)                             (((0 | (x)) << MAC_DMA_IMR_S6_BT_STOMPED_LSB) & MAC_DMA_IMR_S6_BT_STOMPED_MASK)
#define MAC_DMA_IMR_S6_BT_STOMPED_RESET                              0
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_MSB                   3
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_LSB                   3
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_MASK                  0x00000008
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_GET(x)                (((x) & MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_MASK) >> MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_LSB)
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_SET(x)                (((0 | (x)) << MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_LSB) & MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_MASK)
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_FALLING_RESET                 0
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_MSB                    2
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_LSB                    2
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_MASK                   0x00000004
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_GET(x)                 (((x) & MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_MASK) >> MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_LSB)
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_SET(x)                 (((0 | (x)) << MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_LSB) & MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_MASK)
#define MAC_DMA_IMR_S6_BT_LOW_PRIORITY_RISING_RESET                  0
#define MAC_DMA_IMR_S6_BB_PANIC_IRQ_MSB                              1
#define MAC_DMA_IMR_S6_BB_PANIC_IRQ_LSB                              1
#define MAC_DMA_IMR_S6_BB_PANIC_IRQ_MASK                             0x00000002
#define MAC_DMA_IMR_S6_BB_PANIC_IRQ_GET(x)                           (((x) & MAC_DMA_IMR_S6_BB_PANIC_IRQ_MASK) >> MAC_DMA_IMR_S6_BB_PANIC_IRQ_LSB)
#define MAC_DMA_IMR_S6_BB_PANIC_IRQ_SET(x)                           (((0 | (x)) << MAC_DMA_IMR_S6_BB_PANIC_IRQ_LSB) & MAC_DMA_IMR_S6_BB_PANIC_IRQ_MASK)
#define MAC_DMA_IMR_S6_BB_PANIC_IRQ_RESET                            0
#define MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_MSB                        0
#define MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_LSB                        0
#define MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_MASK                       0x00000001
#define MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_GET(x)                     (((x) & MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_MASK) >> MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_LSB)
#define MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_SET(x)                     (((0 | (x)) << MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_LSB) & MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_MASK)
#define MAC_DMA_IMR_S6_BB_MAC_TEMP_SENSOR_RESET                      0
#define MAC_DMA_IMR_S6_ADDRESS                                       0x00bc
#define MAC_DMA_IMR_S6_HW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S6_SW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S6_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S6_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S6_RSTMASK                                       0xffffffff
#define MAC_DMA_IMR_S6_RESET                                         0x00000000

// 0x00c0 (MAC_DMA_ISR_P_RAC)
#define MAC_DMA_ISR_P_RAC_DATA_MSB                                   31
#define MAC_DMA_ISR_P_RAC_DATA_LSB                                   0
#define MAC_DMA_ISR_P_RAC_DATA_MASK                                  0xffffffff
#define MAC_DMA_ISR_P_RAC_DATA_GET(x)                                (((x) & MAC_DMA_ISR_P_RAC_DATA_MASK) >> MAC_DMA_ISR_P_RAC_DATA_LSB)
#define MAC_DMA_ISR_P_RAC_DATA_SET(x)                                (((0 | (x)) << MAC_DMA_ISR_P_RAC_DATA_LSB) & MAC_DMA_ISR_P_RAC_DATA_MASK)
#define MAC_DMA_ISR_P_RAC_DATA_RESET                                 0
#define MAC_DMA_ISR_P_RAC_ADDRESS                                    0x00c0
#define MAC_DMA_ISR_P_RAC_HW_MASK                                    0xffffffff
#define MAC_DMA_ISR_P_RAC_SW_MASK                                    0xffffffff
#define MAC_DMA_ISR_P_RAC_HW_WRITE_MASK                              0xffffffff
#define MAC_DMA_ISR_P_RAC_SW_WRITE_MASK                              0x00000000
#define MAC_DMA_ISR_P_RAC_RSTMASK                                    0xffffffff
#define MAC_DMA_ISR_P_RAC_RESET                                      0x00000000

// 0x00c8 (MAC_DMA_ISR_S1_S)
#define MAC_DMA_ISR_S1_S_RSVD_2_MSB                                  31
#define MAC_DMA_ISR_S1_S_RSVD_2_LSB                                  26
#define MAC_DMA_ISR_S1_S_RSVD_2_MASK                                 0xfc000000
#define MAC_DMA_ISR_S1_S_RSVD_2_GET(x)                               (((x) & MAC_DMA_ISR_S1_S_RSVD_2_MASK) >> MAC_DMA_ISR_S1_S_RSVD_2_LSB)
#define MAC_DMA_ISR_S1_S_RSVD_2_SET(x)                               (((0 | (x)) << MAC_DMA_ISR_S1_S_RSVD_2_LSB) & MAC_DMA_ISR_S1_S_RSVD_2_MASK)
#define MAC_DMA_ISR_S1_S_RSVD_2_RESET                                0
#define MAC_DMA_ISR_S1_S_TXEOL_MSB                                   25
#define MAC_DMA_ISR_S1_S_TXEOL_LSB                                   16
#define MAC_DMA_ISR_S1_S_TXEOL_MASK                                  0x03ff0000
#define MAC_DMA_ISR_S1_S_TXEOL_GET(x)                                (((x) & MAC_DMA_ISR_S1_S_TXEOL_MASK) >> MAC_DMA_ISR_S1_S_TXEOL_LSB)
#define MAC_DMA_ISR_S1_S_TXEOL_SET(x)                                (((0 | (x)) << MAC_DMA_ISR_S1_S_TXEOL_LSB) & MAC_DMA_ISR_S1_S_TXEOL_MASK)
#define MAC_DMA_ISR_S1_S_TXEOL_RESET                                 0
#define MAC_DMA_ISR_S1_S_RSVD_1_MSB                                  15
#define MAC_DMA_ISR_S1_S_RSVD_1_LSB                                  10
#define MAC_DMA_ISR_S1_S_RSVD_1_MASK                                 0x0000fc00
#define MAC_DMA_ISR_S1_S_RSVD_1_GET(x)                               (((x) & MAC_DMA_ISR_S1_S_RSVD_1_MASK) >> MAC_DMA_ISR_S1_S_RSVD_1_LSB)
#define MAC_DMA_ISR_S1_S_RSVD_1_SET(x)                               (((0 | (x)) << MAC_DMA_ISR_S1_S_RSVD_1_LSB) & MAC_DMA_ISR_S1_S_RSVD_1_MASK)
#define MAC_DMA_ISR_S1_S_RSVD_1_RESET                                0
#define MAC_DMA_ISR_S1_S_TXERR_MSB                                   9
#define MAC_DMA_ISR_S1_S_TXERR_LSB                                   0
#define MAC_DMA_ISR_S1_S_TXERR_MASK                                  0x000003ff
#define MAC_DMA_ISR_S1_S_TXERR_GET(x)                                (((x) & MAC_DMA_ISR_S1_S_TXERR_MASK) >> MAC_DMA_ISR_S1_S_TXERR_LSB)
#define MAC_DMA_ISR_S1_S_TXERR_SET(x)                                (((0 | (x)) << MAC_DMA_ISR_S1_S_TXERR_LSB) & MAC_DMA_ISR_S1_S_TXERR_MASK)
#define MAC_DMA_ISR_S1_S_TXERR_RESET                                 0
#define MAC_DMA_ISR_S1_S_ADDRESS                                     0x00c8
#define MAC_DMA_ISR_S1_S_HW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S1_S_SW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S1_S_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S1_S_SW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S1_S_RSTMASK                                     0xffffffff
#define MAC_DMA_ISR_S1_S_RESET                                       0x00000000

// 0x00cc (MAC_DMA_ISR_S6_S)
#define MAC_DMA_ISR_S6_S_RSVD_MSB                                    31
#define MAC_DMA_ISR_S6_S_RSVD_LSB                                    25
#define MAC_DMA_ISR_S6_S_RSVD_MASK                                   0xfe000000
#define MAC_DMA_ISR_S6_S_RSVD_GET(x)                                 (((x) & MAC_DMA_ISR_S6_S_RSVD_MASK) >> MAC_DMA_ISR_S6_S_RSVD_LSB)
#define MAC_DMA_ISR_S6_S_RSVD_SET(x)                                 (((0 | (x)) << MAC_DMA_ISR_S6_S_RSVD_LSB) & MAC_DMA_ISR_S6_S_RSVD_MASK)
#define MAC_DMA_ISR_S6_S_RSVD_RESET                                  0
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_MSB              24
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_LSB              24
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_MASK             0x01000000
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_GET(x)           (((x) & MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_MASK) >> MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_LSB)
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_SET(x)           (((0 | (x)) << MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_LSB) & MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_MASK)
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_OLE_RDY_TIMEOUT_RESET            0
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_MSB                  23
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_LSB                  23
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_MASK                 0x00800000
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_GET(x)               (((x) & MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_MASK) >> MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_LSB)
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_SET(x)               (((0 | (x)) << MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_LSB) & MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_MASK)
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_AXI_TIMEOUT_RESET                0
#define MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_MSB                       22
#define MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_LSB                       22
#define MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_MASK                      0x00400000
#define MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_GET(x)                    (((x) & MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_MASK) >> MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_LSB)
#define MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_SET(x)                    (((0 | (x)) << MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_LSB) & MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_MASK)
#define MAC_DMA_ISR_S6_S_TX_CONFIG_PHY_ERR_RESET                     0
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_MSB              21
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_LSB              21
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_MASK             0x00200000
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_GET(x)           (((x) & MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_MASK) >> MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_LSB)
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_SET(x)           (((0 | (x)) << MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_LSB) & MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_MASK)
#define MAC_DMA_ISR_S6_S_TX_DMA_ERR_UNEXPECTED_NULL_RESET            0
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MSB      20
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_LSB      20
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MASK     0x00100000
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_GET(x)   (((x) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MASK) >> MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_LSB)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_SET(x)   (((0 | (x)) << MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_LSB) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_MASK)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NONPKT_TLV_PAST_BUF_END_RESET    0
#define MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_MSB                         19
#define MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_LSB                         16
#define MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_MASK                        0x000f0000
#define MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_GET(x)                      (((x) & MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_MASK) >> MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_LSB)
#define MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_SET(x)                      (((0 | (x)) << MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_LSB) & MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_MASK)
#define MAC_DMA_ISR_S6_S_RX_DMA_RING_LWM_RESET                       0
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_MSB              15
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_LSB              15
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_MASK             0x00008000
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_GET(x)           (((x) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_MASK) >> MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_LSB)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_SET(x)           (((0 | (x)) << MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_LSB) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_MASK)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_MULTI_DATA_TLVS_RESET            0
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_MSB               14
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_LSB               14
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_MASK              0x00004000
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_GET(x)            (((x) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_MASK) >> MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_LSB)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_SET(x)            (((0 | (x)) << MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_LSB) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_MASK)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_NULL_RING_MASK_RESET             0
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_MSB               13
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_LSB               13
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_MASK              0x00002000
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_GET(x)            (((x) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_MASK) >> MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_LSB)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_SET(x)            (((0 | (x)) << MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_LSB) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_MASK)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_ID_RESET             0
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_MSB              12
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_LSB              12
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_MASK             0x00001000
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_GET(x)           (((x) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_MASK) >> MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_LSB)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_SET(x)           (((0 | (x)) << MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_LSB) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_MASK)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_INVALID_TAG_SIG_RESET            0
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_MSB                11
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_LSB                11
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_MASK               0x00000800
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_GET(x)             (((x) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_MASK) >> MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_LSB)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_SET(x)             (((0 | (x)) << MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_LSB) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_MASK)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_TOO_SHORT_RESET              0
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_MSB                  10
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_LSB                  10
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_MASK                 0x00000400
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_GET(x)               (((x) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_MASK) >> MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_LSB)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_SET(x)               (((0 | (x)) << MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_LSB) & MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_MASK)
#define MAC_DMA_ISR_S6_S_RX_DMA_ERR_TLV_FRAMING_RESET                0
#define MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_MSB                     9
#define MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_LSB                     9
#define MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_MASK                    0x00000200
#define MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_GET(x)                  (((x) & MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_MASK) >> MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_LSB)
#define MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_SET(x)                  (((0 | (x)) << MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_LSB) & MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_MASK)
#define MAC_DMA_ISR_S6_S_BT_PRIORITY_FALLING_RESET                   0
#define MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_MSB                      8
#define MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_LSB                      8
#define MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_MASK                     0x00000100
#define MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_GET(x)                   (((x) & MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_MASK) >> MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_LSB)
#define MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_SET(x)                   (((0 | (x)) << MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_LSB) & MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_MASK)
#define MAC_DMA_ISR_S6_S_BT_PRIORITY_RISING_RESET                    0
#define MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_MSB                       7
#define MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_LSB                       7
#define MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_MASK                      0x00000080
#define MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_GET(x)                    (((x) & MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_MASK) >> MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_LSB)
#define MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_SET(x)                    (((0 | (x)) << MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_LSB) & MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_MASK)
#define MAC_DMA_ISR_S6_S_BT_ACTIVE_FALLING_RESET                     0
#define MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_MSB                        6
#define MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_LSB                        6
#define MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_MASK                       0x00000040
#define MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_GET(x)                     (((x) & MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_MASK) >> MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_LSB)
#define MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_SET(x)                     (((0 | (x)) << MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_LSB) & MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_MASK)
#define MAC_DMA_ISR_S6_S_BT_ACTIVE_RISING_RESET                      0
#define MAC_DMA_ISR_S6_S_WL_STOMPED_MSB                              5
#define MAC_DMA_ISR_S6_S_WL_STOMPED_LSB                              5
#define MAC_DMA_ISR_S6_S_WL_STOMPED_MASK                             0x00000020
#define MAC_DMA_ISR_S6_S_WL_STOMPED_GET(x)                           (((x) & MAC_DMA_ISR_S6_S_WL_STOMPED_MASK) >> MAC_DMA_ISR_S6_S_WL_STOMPED_LSB)
#define MAC_DMA_ISR_S6_S_WL_STOMPED_SET(x)                           (((0 | (x)) << MAC_DMA_ISR_S6_S_WL_STOMPED_LSB) & MAC_DMA_ISR_S6_S_WL_STOMPED_MASK)
#define MAC_DMA_ISR_S6_S_WL_STOMPED_RESET                            0
#define MAC_DMA_ISR_S6_S_BT_STOMPED_MSB                              4
#define MAC_DMA_ISR_S6_S_BT_STOMPED_LSB                              4
#define MAC_DMA_ISR_S6_S_BT_STOMPED_MASK                             0x00000010
#define MAC_DMA_ISR_S6_S_BT_STOMPED_GET(x)                           (((x) & MAC_DMA_ISR_S6_S_BT_STOMPED_MASK) >> MAC_DMA_ISR_S6_S_BT_STOMPED_LSB)
#define MAC_DMA_ISR_S6_S_BT_STOMPED_SET(x)                           (((0 | (x)) << MAC_DMA_ISR_S6_S_BT_STOMPED_LSB) & MAC_DMA_ISR_S6_S_BT_STOMPED_MASK)
#define MAC_DMA_ISR_S6_S_BT_STOMPED_RESET                            0
#define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_MSB                 3
#define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_LSB                 3
#define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_MASK                0x00000008
#define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_GET(x)              (((x) & MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_MASK) >> MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_LSB)
#define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_SET(x)              (((0 | (x)) << MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_LSB) & MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_MASK)
#define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_FALLING_RESET               0
#define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_MSB                  2
#define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_LSB                  2
#define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_MASK                 0x00000004
#define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_GET(x)               (((x) & MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_MASK) >> MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_LSB)
#define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_SET(x)               (((0 | (x)) << MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_LSB) & MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_MASK)
#define MAC_DMA_ISR_S6_S_BT_LOW_PRIORITY_RISING_RESET                0
#define MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_MSB                            1
#define MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_LSB                            1
#define MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_MASK                           0x00000002
#define MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_GET(x)                         (((x) & MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_MASK) >> MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_LSB)
#define MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_SET(x)                         (((0 | (x)) << MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_LSB) & MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_MASK)
#define MAC_DMA_ISR_S6_S_BB_PANIC_IRQ_RESET                          0
#define MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_MSB                      0
#define MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_LSB                      0
#define MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_MASK                     0x00000001
#define MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_GET(x)                   (((x) & MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_MASK) >> MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_LSB)
#define MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_SET(x)                   (((0 | (x)) << MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_LSB) & MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_MASK)
#define MAC_DMA_ISR_S6_S_BB_MAC_TEMP_SENSOR_RESET                    0
#define MAC_DMA_ISR_S6_S_ADDRESS                                     0x00cc
#define MAC_DMA_ISR_S6_S_HW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S6_S_SW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S6_S_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S6_S_SW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S6_S_RSTMASK                                     0xffffffff
#define MAC_DMA_ISR_S6_S_RESET                                       0x00000000

// 0x00d0 (MAC_DMA_ISR_S2_S)
#define MAC_DMA_ISR_S2_S_RSVD_MSB                                    31
#define MAC_DMA_ISR_S2_S_RSVD_LSB                                    31
#define MAC_DMA_ISR_S2_S_RSVD_MASK                                   0x80000000
#define MAC_DMA_ISR_S2_S_RSVD_GET(x)                                 (((x) & MAC_DMA_ISR_S2_S_RSVD_MASK) >> MAC_DMA_ISR_S2_S_RSVD_LSB)
#define MAC_DMA_ISR_S2_S_RSVD_SET(x)                                 (((0 | (x)) << MAC_DMA_ISR_S2_S_RSVD_LSB) & MAC_DMA_ISR_S2_S_RSVD_MASK)
#define MAC_DMA_ISR_S2_S_RSVD_RESET                                  0
#define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_MSB                         30
#define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_LSB                         30
#define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_MASK                        0x40000000
#define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_GET(x)                      (((x) & MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_MASK) >> MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_LSB)
#define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_SET(x)                      (((0 | (x)) << MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_LSB) & MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_MASK)
#define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_0_RESET                       0
#define MAC_DMA_ISR_S2_S_TSFOOR_STA_0_MSB                            29
#define MAC_DMA_ISR_S2_S_TSFOOR_STA_0_LSB                            29
#define MAC_DMA_ISR_S2_S_TSFOOR_STA_0_MASK                           0x20000000
#define MAC_DMA_ISR_S2_S_TSFOOR_STA_0_GET(x)                         (((x) & MAC_DMA_ISR_S2_S_TSFOOR_STA_0_MASK) >> MAC_DMA_ISR_S2_S_TSFOOR_STA_0_LSB)
#define MAC_DMA_ISR_S2_S_TSFOOR_STA_0_SET(x)                         (((0 | (x)) << MAC_DMA_ISR_S2_S_TSFOOR_STA_0_LSB) & MAC_DMA_ISR_S2_S_TSFOOR_STA_0_MASK)
#define MAC_DMA_ISR_S2_S_TSFOOR_STA_0_RESET                          0
#define MAC_DMA_ISR_S2_S_DTIM_STA_0_MSB                              28
#define MAC_DMA_ISR_S2_S_DTIM_STA_0_LSB                              28
#define MAC_DMA_ISR_S2_S_DTIM_STA_0_MASK                             0x10000000
#define MAC_DMA_ISR_S2_S_DTIM_STA_0_GET(x)                           (((x) & MAC_DMA_ISR_S2_S_DTIM_STA_0_MASK) >> MAC_DMA_ISR_S2_S_DTIM_STA_0_LSB)
#define MAC_DMA_ISR_S2_S_DTIM_STA_0_SET(x)                           (((0 | (x)) << MAC_DMA_ISR_S2_S_DTIM_STA_0_LSB) & MAC_DMA_ISR_S2_S_DTIM_STA_0_MASK)
#define MAC_DMA_ISR_S2_S_DTIM_STA_0_RESET                            0
#define MAC_DMA_ISR_S2_S_CABTO_STA_0_MSB                             27
#define MAC_DMA_ISR_S2_S_CABTO_STA_0_LSB                             27
#define MAC_DMA_ISR_S2_S_CABTO_STA_0_MASK                            0x08000000
#define MAC_DMA_ISR_S2_S_CABTO_STA_0_GET(x)                          (((x) & MAC_DMA_ISR_S2_S_CABTO_STA_0_MASK) >> MAC_DMA_ISR_S2_S_CABTO_STA_0_LSB)
#define MAC_DMA_ISR_S2_S_CABTO_STA_0_SET(x)                          (((0 | (x)) << MAC_DMA_ISR_S2_S_CABTO_STA_0_LSB) & MAC_DMA_ISR_S2_S_CABTO_STA_0_MASK)
#define MAC_DMA_ISR_S2_S_CABTO_STA_0_RESET                           0
#define MAC_DMA_ISR_S2_S_BCNTO_STA_0_MSB                             26
#define MAC_DMA_ISR_S2_S_BCNTO_STA_0_LSB                             26
#define MAC_DMA_ISR_S2_S_BCNTO_STA_0_MASK                            0x04000000
#define MAC_DMA_ISR_S2_S_BCNTO_STA_0_GET(x)                          (((x) & MAC_DMA_ISR_S2_S_BCNTO_STA_0_MASK) >> MAC_DMA_ISR_S2_S_BCNTO_STA_0_LSB)
#define MAC_DMA_ISR_S2_S_BCNTO_STA_0_SET(x)                          (((0 | (x)) << MAC_DMA_ISR_S2_S_BCNTO_STA_0_LSB) & MAC_DMA_ISR_S2_S_BCNTO_STA_0_MASK)
#define MAC_DMA_ISR_S2_S_BCNTO_STA_0_RESET                           0
#define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_MSB                          25
#define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_LSB                          25
#define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_MASK                         0x02000000
#define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_GET(x)                       (((x) & MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_MASK) >> MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_LSB)
#define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_SET(x)                       (((0 | (x)) << MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_LSB) & MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_MASK)
#define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_0_RESET                        0
#define MAC_DMA_ISR_S2_S_CABEND_STA_0_MSB                            24
#define MAC_DMA_ISR_S2_S_CABEND_STA_0_LSB                            24
#define MAC_DMA_ISR_S2_S_CABEND_STA_0_MASK                           0x01000000
#define MAC_DMA_ISR_S2_S_CABEND_STA_0_GET(x)                         (((x) & MAC_DMA_ISR_S2_S_CABEND_STA_0_MASK) >> MAC_DMA_ISR_S2_S_CABEND_STA_0_LSB)
#define MAC_DMA_ISR_S2_S_CABEND_STA_0_SET(x)                         (((0 | (x)) << MAC_DMA_ISR_S2_S_CABEND_STA_0_LSB) & MAC_DMA_ISR_S2_S_CABEND_STA_0_MASK)
#define MAC_DMA_ISR_S2_S_CABEND_STA_0_RESET                          0
#define MAC_DMA_ISR_S2_S_TIM_STA_0_MSB                               23
#define MAC_DMA_ISR_S2_S_TIM_STA_0_LSB                               23
#define MAC_DMA_ISR_S2_S_TIM_STA_0_MASK                              0x00800000
#define MAC_DMA_ISR_S2_S_TIM_STA_0_GET(x)                            (((x) & MAC_DMA_ISR_S2_S_TIM_STA_0_MASK) >> MAC_DMA_ISR_S2_S_TIM_STA_0_LSB)
#define MAC_DMA_ISR_S2_S_TIM_STA_0_SET(x)                            (((0 | (x)) << MAC_DMA_ISR_S2_S_TIM_STA_0_LSB) & MAC_DMA_ISR_S2_S_TIM_STA_0_MASK)
#define MAC_DMA_ISR_S2_S_TIM_STA_0_RESET                             0
#define MAC_DMA_ISR_S2_S_GTT_MSB                                     22
#define MAC_DMA_ISR_S2_S_GTT_LSB                                     22
#define MAC_DMA_ISR_S2_S_GTT_MASK                                    0x00400000
#define MAC_DMA_ISR_S2_S_GTT_GET(x)                                  (((x) & MAC_DMA_ISR_S2_S_GTT_MASK) >> MAC_DMA_ISR_S2_S_GTT_LSB)
#define MAC_DMA_ISR_S2_S_GTT_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_S2_S_GTT_LSB) & MAC_DMA_ISR_S2_S_GTT_MASK)
#define MAC_DMA_ISR_S2_S_GTT_RESET                                   0
#define MAC_DMA_ISR_S2_S_CST_MSB                                     21
#define MAC_DMA_ISR_S2_S_CST_LSB                                     21
#define MAC_DMA_ISR_S2_S_CST_MASK                                    0x00200000
#define MAC_DMA_ISR_S2_S_CST_GET(x)                                  (((x) & MAC_DMA_ISR_S2_S_CST_MASK) >> MAC_DMA_ISR_S2_S_CST_LSB)
#define MAC_DMA_ISR_S2_S_CST_SET(x)                                  (((0 | (x)) << MAC_DMA_ISR_S2_S_CST_LSB) & MAC_DMA_ISR_S2_S_CST_MASK)
#define MAC_DMA_ISR_S2_S_CST_RESET                                   0
#define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_MSB                         20
#define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_LSB                         20
#define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_MASK                        0x00100000
#define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_GET(x)                      (((x) & MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_MASK) >> MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_LSB)
#define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_SET(x)                      (((0 | (x)) << MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_LSB) & MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_MASK)
#define MAC_DMA_ISR_S2_S_TBTT_TIME_STA_1_RESET                       0
#define MAC_DMA_ISR_S2_S_TSFOOR_STA_1_MSB                            19
#define MAC_DMA_ISR_S2_S_TSFOOR_STA_1_LSB                            19
#define MAC_DMA_ISR_S2_S_TSFOOR_STA_1_MASK                           0x00080000
#define MAC_DMA_ISR_S2_S_TSFOOR_STA_1_GET(x)                         (((x) & MAC_DMA_ISR_S2_S_TSFOOR_STA_1_MASK) >> MAC_DMA_ISR_S2_S_TSFOOR_STA_1_LSB)
#define MAC_DMA_ISR_S2_S_TSFOOR_STA_1_SET(x)                         (((0 | (x)) << MAC_DMA_ISR_S2_S_TSFOOR_STA_1_LSB) & MAC_DMA_ISR_S2_S_TSFOOR_STA_1_MASK)
#define MAC_DMA_ISR_S2_S_TSFOOR_STA_1_RESET                          0
#define MAC_DMA_ISR_S2_S_DTIM_STA_1_MSB                              18
#define MAC_DMA_ISR_S2_S_DTIM_STA_1_LSB                              18
#define MAC_DMA_ISR_S2_S_DTIM_STA_1_MASK                             0x00040000
#define MAC_DMA_ISR_S2_S_DTIM_STA_1_GET(x)                           (((x) & MAC_DMA_ISR_S2_S_DTIM_STA_1_MASK) >> MAC_DMA_ISR_S2_S_DTIM_STA_1_LSB)
#define MAC_DMA_ISR_S2_S_DTIM_STA_1_SET(x)                           (((0 | (x)) << MAC_DMA_ISR_S2_S_DTIM_STA_1_LSB) & MAC_DMA_ISR_S2_S_DTIM_STA_1_MASK)
#define MAC_DMA_ISR_S2_S_DTIM_STA_1_RESET                            0
#define MAC_DMA_ISR_S2_S_CABTO_STA_1_MSB                             17
#define MAC_DMA_ISR_S2_S_CABTO_STA_1_LSB                             17
#define MAC_DMA_ISR_S2_S_CABTO_STA_1_MASK                            0x00020000
#define MAC_DMA_ISR_S2_S_CABTO_STA_1_GET(x)                          (((x) & MAC_DMA_ISR_S2_S_CABTO_STA_1_MASK) >> MAC_DMA_ISR_S2_S_CABTO_STA_1_LSB)
#define MAC_DMA_ISR_S2_S_CABTO_STA_1_SET(x)                          (((0 | (x)) << MAC_DMA_ISR_S2_S_CABTO_STA_1_LSB) & MAC_DMA_ISR_S2_S_CABTO_STA_1_MASK)
#define MAC_DMA_ISR_S2_S_CABTO_STA_1_RESET                           0
#define MAC_DMA_ISR_S2_S_BCNTO_STA_1_MSB                             16
#define MAC_DMA_ISR_S2_S_BCNTO_STA_1_LSB                             16
#define MAC_DMA_ISR_S2_S_BCNTO_STA_1_MASK                            0x00010000
#define MAC_DMA_ISR_S2_S_BCNTO_STA_1_GET(x)                          (((x) & MAC_DMA_ISR_S2_S_BCNTO_STA_1_MASK) >> MAC_DMA_ISR_S2_S_BCNTO_STA_1_LSB)
#define MAC_DMA_ISR_S2_S_BCNTO_STA_1_SET(x)                          (((0 | (x)) << MAC_DMA_ISR_S2_S_BCNTO_STA_1_LSB) & MAC_DMA_ISR_S2_S_BCNTO_STA_1_MASK)
#define MAC_DMA_ISR_S2_S_BCNTO_STA_1_RESET                           0
#define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_MSB                          15
#define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_LSB                          15
#define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_MASK                         0x00008000
#define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_GET(x)                       (((x) & MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_MASK) >> MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_LSB)
#define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_SET(x)                       (((0 | (x)) << MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_LSB) & MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_MASK)
#define MAC_DMA_ISR_S2_S_DTIMSYNC_STA_1_RESET                        0
#define MAC_DMA_ISR_S2_S_CABEND_STA_1_MSB                            14
#define MAC_DMA_ISR_S2_S_CABEND_STA_1_LSB                            14
#define MAC_DMA_ISR_S2_S_CABEND_STA_1_MASK                           0x00004000
#define MAC_DMA_ISR_S2_S_CABEND_STA_1_GET(x)                         (((x) & MAC_DMA_ISR_S2_S_CABEND_STA_1_MASK) >> MAC_DMA_ISR_S2_S_CABEND_STA_1_LSB)
#define MAC_DMA_ISR_S2_S_CABEND_STA_1_SET(x)                         (((0 | (x)) << MAC_DMA_ISR_S2_S_CABEND_STA_1_LSB) & MAC_DMA_ISR_S2_S_CABEND_STA_1_MASK)
#define MAC_DMA_ISR_S2_S_CABEND_STA_1_RESET                          0
#define MAC_DMA_ISR_S2_S_TIM_STA_1_MSB                               13
#define MAC_DMA_ISR_S2_S_TIM_STA_1_LSB                               13
#define MAC_DMA_ISR_S2_S_TIM_STA_1_MASK                              0x00002000
#define MAC_DMA_ISR_S2_S_TIM_STA_1_GET(x)                            (((x) & MAC_DMA_ISR_S2_S_TIM_STA_1_MASK) >> MAC_DMA_ISR_S2_S_TIM_STA_1_LSB)
#define MAC_DMA_ISR_S2_S_TIM_STA_1_SET(x)                            (((0 | (x)) << MAC_DMA_ISR_S2_S_TIM_STA_1_LSB) & MAC_DMA_ISR_S2_S_TIM_STA_1_MASK)
#define MAC_DMA_ISR_S2_S_TIM_STA_1_RESET                             0
#define MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_MSB                          12
#define MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_LSB                          12
#define MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_MASK                         0x00001000
#define MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_GET(x)                       (((x) & MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_MASK) >> MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_LSB)
#define MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_SET(x)                       (((0 | (x)) << MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_LSB) & MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_MASK)
#define MAC_DMA_ISR_S2_S_PCU_RX_PTR_BAD_RESET                        0
#define MAC_DMA_ISR_S2_S_TDMA_APSYNC_MSB                             11
#define MAC_DMA_ISR_S2_S_TDMA_APSYNC_LSB                             11
#define MAC_DMA_ISR_S2_S_TDMA_APSYNC_MASK                            0x00000800
#define MAC_DMA_ISR_S2_S_TDMA_APSYNC_GET(x)                          (((x) & MAC_DMA_ISR_S2_S_TDMA_APSYNC_MASK) >> MAC_DMA_ISR_S2_S_TDMA_APSYNC_LSB)
#define MAC_DMA_ISR_S2_S_TDMA_APSYNC_SET(x)                          (((0 | (x)) << MAC_DMA_ISR_S2_S_TDMA_APSYNC_LSB) & MAC_DMA_ISR_S2_S_TDMA_APSYNC_MASK)
#define MAC_DMA_ISR_S2_S_TDMA_APSYNC_RESET                           0
#define MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_MSB                   10
#define MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_LSB                   10
#define MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_MASK                  0x00000400
#define MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_GET(x)                (((x) & MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_MASK) >> MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_LSB)
#define MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_SET(x)                (((0 | (x)) << MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_LSB) & MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_MASK)
#define MAC_DMA_ISR_S2_S_TDMA_START_TIME_ERROR_RESET                 0
#define MAC_DMA_ISR_S2_S_TXURN_MSB                                   9
#define MAC_DMA_ISR_S2_S_TXURN_LSB                                   0
#define MAC_DMA_ISR_S2_S_TXURN_MASK                                  0x000003ff
#define MAC_DMA_ISR_S2_S_TXURN_GET(x)                                (((x) & MAC_DMA_ISR_S2_S_TXURN_MASK) >> MAC_DMA_ISR_S2_S_TXURN_LSB)
#define MAC_DMA_ISR_S2_S_TXURN_SET(x)                                (((0 | (x)) << MAC_DMA_ISR_S2_S_TXURN_LSB) & MAC_DMA_ISR_S2_S_TXURN_MASK)
#define MAC_DMA_ISR_S2_S_TXURN_RESET                                 0
#define MAC_DMA_ISR_S2_S_ADDRESS                                     0x00d0
#define MAC_DMA_ISR_S2_S_HW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S2_S_SW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S2_S_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S2_S_SW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S2_S_RSTMASK                                     0xffffffff
#define MAC_DMA_ISR_S2_S_RESET                                       0x00000000

// 0x00d4 (MAC_DMA_ISR_S3_S)
#define MAC_DMA_ISR_S3_S_BMISS_STA_1_MSB                             31
#define MAC_DMA_ISR_S3_S_BMISS_STA_1_LSB                             31
#define MAC_DMA_ISR_S3_S_BMISS_STA_1_MASK                            0x80000000
#define MAC_DMA_ISR_S3_S_BMISS_STA_1_GET(x)                          (((x) & MAC_DMA_ISR_S3_S_BMISS_STA_1_MASK) >> MAC_DMA_ISR_S3_S_BMISS_STA_1_LSB)
#define MAC_DMA_ISR_S3_S_BMISS_STA_1_SET(x)                          (((0 | (x)) << MAC_DMA_ISR_S3_S_BMISS_STA_1_LSB) & MAC_DMA_ISR_S3_S_BMISS_STA_1_MASK)
#define MAC_DMA_ISR_S3_S_BMISS_STA_1_RESET                           0
#define MAC_DMA_ISR_S3_S_BMISS_STA_0_MSB                             30
#define MAC_DMA_ISR_S3_S_BMISS_STA_0_LSB                             30
#define MAC_DMA_ISR_S3_S_BMISS_STA_0_MASK                            0x40000000
#define MAC_DMA_ISR_S3_S_BMISS_STA_0_GET(x)                          (((x) & MAC_DMA_ISR_S3_S_BMISS_STA_0_MASK) >> MAC_DMA_ISR_S3_S_BMISS_STA_0_LSB)
#define MAC_DMA_ISR_S3_S_BMISS_STA_0_SET(x)                          (((0 | (x)) << MAC_DMA_ISR_S3_S_BMISS_STA_0_LSB) & MAC_DMA_ISR_S3_S_BMISS_STA_0_MASK)
#define MAC_DMA_ISR_S3_S_BMISS_STA_0_RESET                           0
#define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_MSB                      29
#define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_LSB                      29
#define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_MASK                     0x20000000
#define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_GET(x)                   (((x) & MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_MASK) >> MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_LSB)
#define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_SET(x)                   (((0 | (x)) << MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_LSB) & MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_MASK)
#define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_1_RESET                    0
#define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_MSB                     28
#define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_LSB                     28
#define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_MASK                    0x10000000
#define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_GET(x)                  (((x) & MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_MASK) >> MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_LSB)
#define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_SET(x)                  (((0 | (x)) << MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_LSB) & MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_MASK)
#define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_1_RESET                   0
#define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_MSB                      27
#define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_LSB                      27
#define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_MASK                     0x08000000
#define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_GET(x)                   (((x) & MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_MASK) >> MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_LSB)
#define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_SET(x)                   (((0 | (x)) << MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_LSB) & MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_MASK)
#define MAC_DMA_ISR_S3_S_PCU_RSSI_LOW_STA_0_RESET                    0
#define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_MSB                     26
#define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_LSB                     26
#define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_MASK                    0x04000000
#define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_GET(x)                  (((x) & MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_MASK) >> MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_LSB)
#define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_SET(x)                  (((0 | (x)) << MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_LSB) & MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_MASK)
#define MAC_DMA_ISR_S3_S_PCU_RSSI_HIGH_STA_0_RESET                   0
#define MAC_DMA_ISR_S3_S_QCBRURN_MSB                                 25
#define MAC_DMA_ISR_S3_S_QCBRURN_LSB                                 16
#define MAC_DMA_ISR_S3_S_QCBRURN_MASK                                0x03ff0000
#define MAC_DMA_ISR_S3_S_QCBRURN_GET(x)                              (((x) & MAC_DMA_ISR_S3_S_QCBRURN_MASK) >> MAC_DMA_ISR_S3_S_QCBRURN_LSB)
#define MAC_DMA_ISR_S3_S_QCBRURN_SET(x)                              (((0 | (x)) << MAC_DMA_ISR_S3_S_QCBRURN_LSB) & MAC_DMA_ISR_S3_S_QCBRURN_MASK)
#define MAC_DMA_ISR_S3_S_QCBRURN_RESET                               0
#define MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_MSB                         15
#define MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_LSB                         15
#define MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_MASK                        0x00008000
#define MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_GET(x)                      (((x) & MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_MASK) >> MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_LSB)
#define MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_SET(x)                      (((0 | (x)) << MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_LSB) & MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_MASK)
#define MAC_DMA_ISR_S3_S_RXDMA_HP_DP_OVF_RESET                       0
#define MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_MSB                         14
#define MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_LSB                         14
#define MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_MASK                        0x00004000
#define MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_GET(x)                      (((x) & MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_MASK) >> MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_LSB)
#define MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_SET(x)                      (((0 | (x)) << MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_LSB) & MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_MASK)
#define MAC_DMA_ISR_S3_S_RXDMA_LP_DP_OVF_RESET                       0
#define MAC_DMA_ISR_S3_S_RSVD_MSB                                    13
#define MAC_DMA_ISR_S3_S_RSVD_LSB                                    10
#define MAC_DMA_ISR_S3_S_RSVD_MASK                                   0x00003c00
#define MAC_DMA_ISR_S3_S_RSVD_GET(x)                                 (((x) & MAC_DMA_ISR_S3_S_RSVD_MASK) >> MAC_DMA_ISR_S3_S_RSVD_LSB)
#define MAC_DMA_ISR_S3_S_RSVD_SET(x)                                 (((0 | (x)) << MAC_DMA_ISR_S3_S_RSVD_LSB) & MAC_DMA_ISR_S3_S_RSVD_MASK)
#define MAC_DMA_ISR_S3_S_RSVD_RESET                                  0
#define MAC_DMA_ISR_S3_S_QCBROVF_MSB                                 9
#define MAC_DMA_ISR_S3_S_QCBROVF_LSB                                 0
#define MAC_DMA_ISR_S3_S_QCBROVF_MASK                                0x000003ff
#define MAC_DMA_ISR_S3_S_QCBROVF_GET(x)                              (((x) & MAC_DMA_ISR_S3_S_QCBROVF_MASK) >> MAC_DMA_ISR_S3_S_QCBROVF_LSB)
#define MAC_DMA_ISR_S3_S_QCBROVF_SET(x)                              (((0 | (x)) << MAC_DMA_ISR_S3_S_QCBROVF_LSB) & MAC_DMA_ISR_S3_S_QCBROVF_MASK)
#define MAC_DMA_ISR_S3_S_QCBROVF_RESET                               0
#define MAC_DMA_ISR_S3_S_ADDRESS                                     0x00d4
#define MAC_DMA_ISR_S3_S_HW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S3_S_SW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S3_S_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S3_S_SW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S3_S_RSTMASK                                     0xffffffff
#define MAC_DMA_ISR_S3_S_RESET                                       0x00000000

// 0x00d8 (MAC_DMA_ISR_S4_S)
#define MAC_DMA_ISR_S4_S_RSVD_2_MSB                                  31
#define MAC_DMA_ISR_S4_S_RSVD_2_LSB                                  26
#define MAC_DMA_ISR_S4_S_RSVD_2_MASK                                 0xfc000000
#define MAC_DMA_ISR_S4_S_RSVD_2_GET(x)                               (((x) & MAC_DMA_ISR_S4_S_RSVD_2_MASK) >> MAC_DMA_ISR_S4_S_RSVD_2_LSB)
#define MAC_DMA_ISR_S4_S_RSVD_2_SET(x)                               (((0 | (x)) << MAC_DMA_ISR_S4_S_RSVD_2_LSB) & MAC_DMA_ISR_S4_S_RSVD_2_MASK)
#define MAC_DMA_ISR_S4_S_RSVD_2_RESET                                0
#define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_MSB                           25
#define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_LSB                           16
#define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_MASK                          0x03ff0000
#define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_GET(x)                        (((x) & MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_MASK) >> MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_LSB)
#define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_SET(x)                        (((0 | (x)) << MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_LSB) & MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_MASK)
#define MAC_DMA_ISR_S4_S_TXDP_FIFO_OVF_RESET                         0
#define MAC_DMA_ISR_S4_S_RSVD_1_MSB                                  15
#define MAC_DMA_ISR_S4_S_RSVD_1_LSB                                  10
#define MAC_DMA_ISR_S4_S_RSVD_1_MASK                                 0x0000fc00
#define MAC_DMA_ISR_S4_S_RSVD_1_GET(x)                               (((x) & MAC_DMA_ISR_S4_S_RSVD_1_MASK) >> MAC_DMA_ISR_S4_S_RSVD_1_LSB)
#define MAC_DMA_ISR_S4_S_RSVD_1_SET(x)                               (((0 | (x)) << MAC_DMA_ISR_S4_S_RSVD_1_LSB) & MAC_DMA_ISR_S4_S_RSVD_1_MASK)
#define MAC_DMA_ISR_S4_S_RSVD_1_RESET                                0
#define MAC_DMA_ISR_S4_S_QTRIG_MSB                                   9
#define MAC_DMA_ISR_S4_S_QTRIG_LSB                                   0
#define MAC_DMA_ISR_S4_S_QTRIG_MASK                                  0x000003ff
#define MAC_DMA_ISR_S4_S_QTRIG_GET(x)                                (((x) & MAC_DMA_ISR_S4_S_QTRIG_MASK) >> MAC_DMA_ISR_S4_S_QTRIG_LSB)
#define MAC_DMA_ISR_S4_S_QTRIG_SET(x)                                (((0 | (x)) << MAC_DMA_ISR_S4_S_QTRIG_LSB) & MAC_DMA_ISR_S4_S_QTRIG_MASK)
#define MAC_DMA_ISR_S4_S_QTRIG_RESET                                 0
#define MAC_DMA_ISR_S4_S_ADDRESS                                     0x00d8
#define MAC_DMA_ISR_S4_S_HW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S4_S_SW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S4_S_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S4_S_SW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S4_S_RSTMASK                                     0xffffffff
#define MAC_DMA_ISR_S4_S_RESET                                       0x00000000

// 0x00dc (MAC_DMA_ISR_S5_S)
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_MSB                    31
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_LSB                    17
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_MASK                   0xfffe0000
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_GET(x)                 (((x) & MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_MASK) >> MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_LSB)
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_SET(x)                 (((0 | (x)) << MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_LSB) & MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_MASK)
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_THRESH_RESET                  0
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_MSB                       16
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_LSB                       16
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_MASK                      0x00010000
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_GET(x)                    (((x) & MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_MASK) >> MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_LSB)
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_SET(x)                    (((0 | (x)) << MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_LSB) & MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_MASK)
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_OVF_RESET                     0
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_MSB                   15
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_LSB                   0
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_MASK                  0x0000ffff
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_GET(x)                (((x) & MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_MASK) >> MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_LSB)
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_SET(x)                (((0 | (x)) << MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_LSB) & MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_MASK)
#define MAC_DMA_ISR_S5_S_GENERIC_TIMER_TRIGGER_RESET                 0
#define MAC_DMA_ISR_S5_S_ADDRESS                                     0x00dc
#define MAC_DMA_ISR_S5_S_HW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S5_S_SW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S5_S_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S5_S_SW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S5_S_RSTMASK                                     0xffffffff
#define MAC_DMA_ISR_S5_S_RESET                                       0x00000000

// 0x00e0 (MAC_DMA_DMADBG_0)
#define MAC_DMA_DMADBG_0_DATA_MSB                                    31
#define MAC_DMA_DMADBG_0_DATA_LSB                                    0
#define MAC_DMA_DMADBG_0_DATA_MASK                                   0xffffffff
#define MAC_DMA_DMADBG_0_DATA_GET(x)                                 (((x) & MAC_DMA_DMADBG_0_DATA_MASK) >> MAC_DMA_DMADBG_0_DATA_LSB)
#define MAC_DMA_DMADBG_0_DATA_SET(x)                                 (((0 | (x)) << MAC_DMA_DMADBG_0_DATA_LSB) & MAC_DMA_DMADBG_0_DATA_MASK)
#define MAC_DMA_DMADBG_0_DATA_RESET                                  0
#define MAC_DMA_DMADBG_0_ADDRESS                                     0x00e0
#define MAC_DMA_DMADBG_0_HW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_0_SW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_0_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_DMADBG_0_SW_WRITE_MASK                               0x00000000
#define MAC_DMA_DMADBG_0_RSTMASK                                     0xffffffff
#define MAC_DMA_DMADBG_0_RESET                                       0x00000000

// 0x00e4 (MAC_DMA_DMADBG_1)
#define MAC_DMA_DMADBG_1_DATA_MSB                                    31
#define MAC_DMA_DMADBG_1_DATA_LSB                                    0
#define MAC_DMA_DMADBG_1_DATA_MASK                                   0xffffffff
#define MAC_DMA_DMADBG_1_DATA_GET(x)                                 (((x) & MAC_DMA_DMADBG_1_DATA_MASK) >> MAC_DMA_DMADBG_1_DATA_LSB)
#define MAC_DMA_DMADBG_1_DATA_SET(x)                                 (((0 | (x)) << MAC_DMA_DMADBG_1_DATA_LSB) & MAC_DMA_DMADBG_1_DATA_MASK)
#define MAC_DMA_DMADBG_1_DATA_RESET                                  0
#define MAC_DMA_DMADBG_1_ADDRESS                                     0x00e4
#define MAC_DMA_DMADBG_1_HW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_1_SW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_1_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_DMADBG_1_SW_WRITE_MASK                               0x00000000
#define MAC_DMA_DMADBG_1_RSTMASK                                     0xffffffff
#define MAC_DMA_DMADBG_1_RESET                                       0x00000000

// 0x00e8 (MAC_DMA_DMADBG_2)
#define MAC_DMA_DMADBG_2_DATA_MSB                                    31
#define MAC_DMA_DMADBG_2_DATA_LSB                                    0
#define MAC_DMA_DMADBG_2_DATA_MASK                                   0xffffffff
#define MAC_DMA_DMADBG_2_DATA_GET(x)                                 (((x) & MAC_DMA_DMADBG_2_DATA_MASK) >> MAC_DMA_DMADBG_2_DATA_LSB)
#define MAC_DMA_DMADBG_2_DATA_SET(x)                                 (((0 | (x)) << MAC_DMA_DMADBG_2_DATA_LSB) & MAC_DMA_DMADBG_2_DATA_MASK)
#define MAC_DMA_DMADBG_2_DATA_RESET                                  0
#define MAC_DMA_DMADBG_2_ADDRESS                                     0x00e8
#define MAC_DMA_DMADBG_2_HW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_2_SW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_2_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_DMADBG_2_SW_WRITE_MASK                               0x00000000
#define MAC_DMA_DMADBG_2_RSTMASK                                     0xffffffff
#define MAC_DMA_DMADBG_2_RESET                                       0x00000000

// 0x00ec (MAC_DMA_DMADBG_3)
#define MAC_DMA_DMADBG_3_DATA_MSB                                    31
#define MAC_DMA_DMADBG_3_DATA_LSB                                    0
#define MAC_DMA_DMADBG_3_DATA_MASK                                   0xffffffff
#define MAC_DMA_DMADBG_3_DATA_GET(x)                                 (((x) & MAC_DMA_DMADBG_3_DATA_MASK) >> MAC_DMA_DMADBG_3_DATA_LSB)
#define MAC_DMA_DMADBG_3_DATA_SET(x)                                 (((0 | (x)) << MAC_DMA_DMADBG_3_DATA_LSB) & MAC_DMA_DMADBG_3_DATA_MASK)
#define MAC_DMA_DMADBG_3_DATA_RESET                                  0
#define MAC_DMA_DMADBG_3_ADDRESS                                     0x00ec
#define MAC_DMA_DMADBG_3_HW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_3_SW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_3_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_DMADBG_3_SW_WRITE_MASK                               0x00000000
#define MAC_DMA_DMADBG_3_RSTMASK                                     0xffffffff
#define MAC_DMA_DMADBG_3_RESET                                       0x00000000

// 0x00f0 (MAC_DMA_DMADBG_4)
#define MAC_DMA_DMADBG_4_DATA_MSB                                    31
#define MAC_DMA_DMADBG_4_DATA_LSB                                    0
#define MAC_DMA_DMADBG_4_DATA_MASK                                   0xffffffff
#define MAC_DMA_DMADBG_4_DATA_GET(x)                                 (((x) & MAC_DMA_DMADBG_4_DATA_MASK) >> MAC_DMA_DMADBG_4_DATA_LSB)
#define MAC_DMA_DMADBG_4_DATA_SET(x)                                 (((0 | (x)) << MAC_DMA_DMADBG_4_DATA_LSB) & MAC_DMA_DMADBG_4_DATA_MASK)
#define MAC_DMA_DMADBG_4_DATA_RESET                                  0
#define MAC_DMA_DMADBG_4_ADDRESS                                     0x00f0
#define MAC_DMA_DMADBG_4_HW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_4_SW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_4_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_DMADBG_4_SW_WRITE_MASK                               0x00000000
#define MAC_DMA_DMADBG_4_RSTMASK                                     0xffffffff
#define MAC_DMA_DMADBG_4_RESET                                       0x00000000

// 0x00f4 (MAC_DMA_DMADBG_5)
#define MAC_DMA_DMADBG_5_DATA_MSB                                    31
#define MAC_DMA_DMADBG_5_DATA_LSB                                    0
#define MAC_DMA_DMADBG_5_DATA_MASK                                   0xffffffff
#define MAC_DMA_DMADBG_5_DATA_GET(x)                                 (((x) & MAC_DMA_DMADBG_5_DATA_MASK) >> MAC_DMA_DMADBG_5_DATA_LSB)
#define MAC_DMA_DMADBG_5_DATA_SET(x)                                 (((0 | (x)) << MAC_DMA_DMADBG_5_DATA_LSB) & MAC_DMA_DMADBG_5_DATA_MASK)
#define MAC_DMA_DMADBG_5_DATA_RESET                                  0
#define MAC_DMA_DMADBG_5_ADDRESS                                     0x00f4
#define MAC_DMA_DMADBG_5_HW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_5_SW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_5_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_DMADBG_5_SW_WRITE_MASK                               0x00000000
#define MAC_DMA_DMADBG_5_RSTMASK                                     0xffffffff
#define MAC_DMA_DMADBG_5_RESET                                       0x00000000

// 0x00f8 (MAC_DMA_DMADBG_6)
#define MAC_DMA_DMADBG_6_DATA_MSB                                    31
#define MAC_DMA_DMADBG_6_DATA_LSB                                    0
#define MAC_DMA_DMADBG_6_DATA_MASK                                   0xffffffff
#define MAC_DMA_DMADBG_6_DATA_GET(x)                                 (((x) & MAC_DMA_DMADBG_6_DATA_MASK) >> MAC_DMA_DMADBG_6_DATA_LSB)
#define MAC_DMA_DMADBG_6_DATA_SET(x)                                 (((0 | (x)) << MAC_DMA_DMADBG_6_DATA_LSB) & MAC_DMA_DMADBG_6_DATA_MASK)
#define MAC_DMA_DMADBG_6_DATA_RESET                                  0
#define MAC_DMA_DMADBG_6_ADDRESS                                     0x00f8
#define MAC_DMA_DMADBG_6_HW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_6_SW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_6_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_DMADBG_6_SW_WRITE_MASK                               0x00000000
#define MAC_DMA_DMADBG_6_RSTMASK                                     0xffffffff
#define MAC_DMA_DMADBG_6_RESET                                       0x00000000

// 0x00fc (MAC_DMA_DMADBG_7)
#define MAC_DMA_DMADBG_7_DATA_MSB                                    31
#define MAC_DMA_DMADBG_7_DATA_LSB                                    0
#define MAC_DMA_DMADBG_7_DATA_MASK                                   0xffffffff
#define MAC_DMA_DMADBG_7_DATA_GET(x)                                 (((x) & MAC_DMA_DMADBG_7_DATA_MASK) >> MAC_DMA_DMADBG_7_DATA_LSB)
#define MAC_DMA_DMADBG_7_DATA_SET(x)                                 (((0 | (x)) << MAC_DMA_DMADBG_7_DATA_LSB) & MAC_DMA_DMADBG_7_DATA_MASK)
#define MAC_DMA_DMADBG_7_DATA_RESET                                  0
#define MAC_DMA_DMADBG_7_ADDRESS                                     0x00fc
#define MAC_DMA_DMADBG_7_HW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_7_SW_MASK                                     0xffffffff
#define MAC_DMA_DMADBG_7_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_DMADBG_7_SW_WRITE_MASK                               0x00000000
#define MAC_DMA_DMADBG_7_RSTMASK                                     0xffffffff
#define MAC_DMA_DMADBG_7_RESET                                       0x00000000

// 0x0100 (MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0)
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_MSB                  31
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_LSB                  0
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_MASK                 0xffffffff
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_GET(x)               (((x) & MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_MASK) >> MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_LSB)
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_SET(x)               (((0 | (x)) << MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_LSB) & MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_MASK)
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_DATA_RESET                0
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_ADDRESS                   0x0100
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_HW_MASK                   0xffffffff
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_SW_MASK                   0xffffffff
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_HW_WRITE_MASK             0xffffffff
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_SW_WRITE_MASK             0x00000000
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_RSTMASK                   0xffffffff
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0_RESET                     0x00000000

// 0x0104 (MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8)
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_MSB                  7
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_LSB                  0
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_MASK                 0x000000ff
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_GET(x)               (((x) & MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_MASK) >> MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_LSB)
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_SET(x)               (((0 | (x)) << MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_LSB) & MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_MASK)
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_DATA_RESET                0
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_ADDRESS                   0x0104
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_HW_MASK                   0x000000ff
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_SW_MASK                   0x000000ff
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_HW_WRITE_MASK             0x000000ff
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_SW_WRITE_MASK             0x00000000
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_RSTMASK                   0xffffffff
#define MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8_RESET                     0x00000000

// 0x0108 (MAC_DMA_ISR_S7)
#define MAC_DMA_ISR_S7_RESERVED_1_MSB                                31
#define MAC_DMA_ISR_S7_RESERVED_1_LSB                                20
#define MAC_DMA_ISR_S7_RESERVED_1_MASK                               0xfff00000
#define MAC_DMA_ISR_S7_RESERVED_1_GET(x)                             (((x) & MAC_DMA_ISR_S7_RESERVED_1_MASK) >> MAC_DMA_ISR_S7_RESERVED_1_LSB)
#define MAC_DMA_ISR_S7_RESERVED_1_SET(x)                             (((0 | (x)) << MAC_DMA_ISR_S7_RESERVED_1_LSB) & MAC_DMA_ISR_S7_RESERVED_1_MASK)
#define MAC_DMA_ISR_S7_RESERVED_1_RESET                              0
#define MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_MSB                    19
#define MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_LSB                    19
#define MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_MASK                   0x00080000
#define MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_GET(x)                 (((x) & MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_MASK) >> MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_LSB)
#define MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_SET(x)                 (((0 | (x)) << MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_LSB) & MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_MASK)
#define MAC_DMA_ISR_S7_OLE_RX_WMAC_PARSER_ERR_RESET                  0
#define MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_MSB                     18
#define MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_LSB                     18
#define MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_MASK                    0x00040000
#define MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_GET(x)                  (((x) & MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_MASK) >> MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_LSB)
#define MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_SET(x)                  (((0 | (x)) << MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_LSB) & MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_MASK)
#define MAC_DMA_ISR_S7_OLE_RX_ETH_PARSER_ERR_RESET                   0
#define MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_MSB                     17
#define MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_LSB                     17
#define MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_MASK                    0x00020000
#define MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_GET(x)                  (((x) & MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_MASK) >> MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_LSB)
#define MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_SET(x)                  (((0 | (x)) << MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_LSB) & MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_MASK)
#define MAC_DMA_ISR_S7_OLE_RX_MPDU_PKT_ABORT_RESET                   0
#define MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_MSB                       16
#define MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_LSB                       16
#define MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_MASK                      0x00010000
#define MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_GET(x)                    (((x) & MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_MASK) >> MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_LSB)
#define MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_SET(x)                    (((0 | (x)) << MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_LSB) & MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_MASK)
#define MAC_DMA_ISR_S7_OLE_RX_MSDU_LEN_ERR_RESET                     0
#define MAC_DMA_ISR_S7_RESERVED_0_MSB                                15
#define MAC_DMA_ISR_S7_RESERVED_0_LSB                                9
#define MAC_DMA_ISR_S7_RESERVED_0_MASK                               0x0000fe00
#define MAC_DMA_ISR_S7_RESERVED_0_GET(x)                             (((x) & MAC_DMA_ISR_S7_RESERVED_0_MASK) >> MAC_DMA_ISR_S7_RESERVED_0_LSB)
#define MAC_DMA_ISR_S7_RESERVED_0_SET(x)                             (((0 | (x)) << MAC_DMA_ISR_S7_RESERVED_0_LSB) & MAC_DMA_ISR_S7_RESERVED_0_MASK)
#define MAC_DMA_ISR_S7_RESERVED_0_RESET                              0
#define MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_MSB                      8
#define MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_LSB                      8
#define MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_MASK                     0x00000100
#define MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_GET(x)                   (((x) & MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_MASK) >> MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_LSB)
#define MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_SET(x)                   (((0 | (x)) << MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_LSB) & MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_MASK)
#define MAC_DMA_ISR_S7_OLE_TX_ILLEGAL_FRAME_RESET                    0
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_MSB                        7
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_LSB                        7
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_MASK                       0x00000080
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_GET(x)                     (((x) & MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_MASK) >> MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_LSB)
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_SET(x)                     (((0 | (x)) << MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_LSB) & MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_MASK)
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_LLC_RESET                      0
#define MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_MSB                6
#define MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_LSB                6
#define MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_MASK               0x00000040
#define MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_GET(x)             (((x) & MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_MASK) >> MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_LSB)
#define MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_SET(x)             (((0 | (x)) << MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_LSB) & MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_MASK)
#define MAC_DMA_ISR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_RESET              0
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MSB                   5
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_LSB                   5
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MASK                  0x00000020
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_GET(x)                (((x) & MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MASK) >> MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_LSB)
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_SET(x)                (((0 | (x)) << MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_LSB) & MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MASK)
#define MAC_DMA_ISR_S7_OLE_TX_UNKNOWN_TYPE_ERR_RESET                 0
#define MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_MSB                 4
#define MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_LSB                 4
#define MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_MASK                0x00000010
#define MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_GET(x)              (((x) & MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_MASK) >> MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_LSB)
#define MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_SET(x)              (((0 | (x)) << MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_LSB) & MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_MASK)
#define MAC_DMA_ISR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_RESET               0
#define MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_MSB                      3
#define MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_LSB                      3
#define MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_MASK                     0x00000008
#define MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_GET(x)                   (((x) & MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_MASK) >> MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_LSB)
#define MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_SET(x)                   (((0 | (x)) << MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_LSB) & MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_MASK)
#define MAC_DMA_ISR_S7_OLE_TX_PN_BITMAP_ERR_RESET                    0
#define MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_MSB                    2
#define MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_LSB                    2
#define MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_MASK                   0x00000004
#define MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_GET(x)                 (((x) & MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_MASK) >> MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_LSB)
#define MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_SET(x)                 (((0 | (x)) << MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_LSB) & MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_MASK)
#define MAC_DMA_ISR_S7_OLE_TX_AMSDU_FRAME_ERR_RESET                  0
#define MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_MSB                      1
#define MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_LSB                      1
#define MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_MASK                     0x00000002
#define MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_GET(x)                   (((x) & MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_MASK) >> MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_LSB)
#define MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_SET(x)                   (((0 | (x)) << MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_LSB) & MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_MASK)
#define MAC_DMA_ISR_S7_OLE_TX_WEP_KTYPE_ERR_RESET                    0
#define MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_MSB                          0
#define MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_LSB                          0
#define MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_MASK                         0x00000001
#define MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_GET(x)                       (((x) & MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_MASK) >> MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_LSB)
#define MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_SET(x)                       (((0 | (x)) << MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_LSB) & MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_MASK)
#define MAC_DMA_ISR_S7_DMA_OLE_TX_ABORT_RESET                        0
#define MAC_DMA_ISR_S7_ADDRESS                                       0x0108
#define MAC_DMA_ISR_S7_HW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S7_SW_MASK                                       0xffffffff
#define MAC_DMA_ISR_S7_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S7_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_ISR_S7_RSTMASK                                       0xffffffff
#define MAC_DMA_ISR_S7_RESET                                         0x00000000

// 0x010c (MAC_DMA_IMR_S7)
#define MAC_DMA_IMR_S7_RESERVED_1_MSB                                31
#define MAC_DMA_IMR_S7_RESERVED_1_LSB                                20
#define MAC_DMA_IMR_S7_RESERVED_1_MASK                               0xfff00000
#define MAC_DMA_IMR_S7_RESERVED_1_GET(x)                             (((x) & MAC_DMA_IMR_S7_RESERVED_1_MASK) >> MAC_DMA_IMR_S7_RESERVED_1_LSB)
#define MAC_DMA_IMR_S7_RESERVED_1_SET(x)                             (((0 | (x)) << MAC_DMA_IMR_S7_RESERVED_1_LSB) & MAC_DMA_IMR_S7_RESERVED_1_MASK)
#define MAC_DMA_IMR_S7_RESERVED_1_RESET                              0
#define MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_MSB                    19
#define MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_LSB                    19
#define MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_MASK                   0x00080000
#define MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_GET(x)                 (((x) & MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_MASK) >> MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_LSB)
#define MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_SET(x)                 (((0 | (x)) << MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_LSB) & MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_MASK)
#define MAC_DMA_IMR_S7_OLE_RX_WMAC_PARSER_ERR_RESET                  0
#define MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_MSB                     18
#define MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_LSB                     18
#define MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_MASK                    0x00040000
#define MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_GET(x)                  (((x) & MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_MASK) >> MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_LSB)
#define MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_SET(x)                  (((0 | (x)) << MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_LSB) & MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_MASK)
#define MAC_DMA_IMR_S7_OLE_RX_ETH_PARSER_ERR_RESET                   0
#define MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_MSB                     17
#define MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_LSB                     17
#define MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_MASK                    0x00020000
#define MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_GET(x)                  (((x) & MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_MASK) >> MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_LSB)
#define MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_SET(x)                  (((0 | (x)) << MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_LSB) & MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_MASK)
#define MAC_DMA_IMR_S7_OLE_RX_MPDU_PKT_ABORT_RESET                   0
#define MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_MSB                       16
#define MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_LSB                       16
#define MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_MASK                      0x00010000
#define MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_GET(x)                    (((x) & MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_MASK) >> MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_LSB)
#define MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_SET(x)                    (((0 | (x)) << MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_LSB) & MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_MASK)
#define MAC_DMA_IMR_S7_OLE_RX_MSDU_LEN_ERR_RESET                     0
#define MAC_DMA_IMR_S7_RESERVED_0_MSB                                15
#define MAC_DMA_IMR_S7_RESERVED_0_LSB                                9
#define MAC_DMA_IMR_S7_RESERVED_0_MASK                               0x0000fe00
#define MAC_DMA_IMR_S7_RESERVED_0_GET(x)                             (((x) & MAC_DMA_IMR_S7_RESERVED_0_MASK) >> MAC_DMA_IMR_S7_RESERVED_0_LSB)
#define MAC_DMA_IMR_S7_RESERVED_0_SET(x)                             (((0 | (x)) << MAC_DMA_IMR_S7_RESERVED_0_LSB) & MAC_DMA_IMR_S7_RESERVED_0_MASK)
#define MAC_DMA_IMR_S7_RESERVED_0_RESET                              0
#define MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_MSB                      8
#define MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_LSB                      8
#define MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_MASK                     0x00000100
#define MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_GET(x)                   (((x) & MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_MASK) >> MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_LSB)
#define MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_SET(x)                   (((0 | (x)) << MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_LSB) & MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_MASK)
#define MAC_DMA_IMR_S7_OLE_TX_ILLEGAL_FRAME_RESET                    0
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_MSB                        7
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_LSB                        7
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_MASK                       0x00000080
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_GET(x)                     (((x) & MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_MASK) >> MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_LSB)
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_SET(x)                     (((0 | (x)) << MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_LSB) & MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_MASK)
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_LLC_RESET                      0
#define MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_MSB                6
#define MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_LSB                6
#define MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_MASK               0x00000040
#define MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_GET(x)             (((x) & MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_MASK) >> MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_LSB)
#define MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_SET(x)             (((0 | (x)) << MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_LSB) & MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_MASK)
#define MAC_DMA_IMR_S7_OLE_TX_INCOMPLETE_VLAN_LLC_RESET              0
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MSB                   5
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_LSB                   5
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MASK                  0x00000020
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_GET(x)                (((x) & MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MASK) >> MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_LSB)
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_SET(x)                (((0 | (x)) << MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_LSB) & MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_MASK)
#define MAC_DMA_IMR_S7_OLE_TX_UNKNOWN_TYPE_ERR_RESET                 0
#define MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_MSB                 4
#define MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_LSB                 4
#define MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_MASK                0x00000010
#define MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_GET(x)              (((x) & MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_MASK) >> MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_LSB)
#define MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_SET(x)              (((0 | (x)) << MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_LSB) & MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_MASK)
#define MAC_DMA_IMR_S7_OLE_TX_SEQ_NUM_BITMAP_ERR_RESET               0
#define MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_MSB                      3
#define MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_LSB                      3
#define MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_MASK                     0x00000008
#define MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_GET(x)                   (((x) & MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_MASK) >> MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_LSB)
#define MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_SET(x)                   (((0 | (x)) << MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_LSB) & MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_MASK)
#define MAC_DMA_IMR_S7_OLE_TX_PN_BITMAP_ERR_RESET                    0
#define MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_MSB                    2
#define MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_LSB                    2
#define MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_MASK                   0x00000004
#define MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_GET(x)                 (((x) & MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_MASK) >> MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_LSB)
#define MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_SET(x)                 (((0 | (x)) << MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_LSB) & MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_MASK)
#define MAC_DMA_IMR_S7_OLE_TX_AMSDU_FRAME_ERR_RESET                  0
#define MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_MSB                      1
#define MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_LSB                      1
#define MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_MASK                     0x00000002
#define MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_GET(x)                   (((x) & MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_MASK) >> MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_LSB)
#define MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_SET(x)                   (((0 | (x)) << MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_LSB) & MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_MASK)
#define MAC_DMA_IMR_S7_OLE_TX_WEP_KTYPE_ERR_RESET                    0
#define MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_MSB                          0
#define MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_LSB                          0
#define MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_MASK                         0x00000001
#define MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_GET(x)                       (((x) & MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_MASK) >> MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_LSB)
#define MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_SET(x)                       (((0 | (x)) << MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_LSB) & MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_MASK)
#define MAC_DMA_IMR_S7_DMA_OLE_TX_ABORT_RESET                        0
#define MAC_DMA_IMR_S7_ADDRESS                                       0x010c
#define MAC_DMA_IMR_S7_HW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S7_SW_MASK                                       0xffffffff
#define MAC_DMA_IMR_S7_HW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S7_SW_WRITE_MASK                                 0xffffffff
#define MAC_DMA_IMR_S7_RSTMASK                                       0xffffffff
#define MAC_DMA_IMR_S7_RESET                                         0x00000000

// 0x0110 (MAC_DMA_ISR_S7_S)
#define MAC_DMA_ISR_S7_S_RESERVED_1_MSB                              31
#define MAC_DMA_ISR_S7_S_RESERVED_1_LSB                              20
#define MAC_DMA_ISR_S7_S_RESERVED_1_MASK                             0xfff00000
#define MAC_DMA_ISR_S7_S_RESERVED_1_GET(x)                           (((x) & MAC_DMA_ISR_S7_S_RESERVED_1_MASK) >> MAC_DMA_ISR_S7_S_RESERVED_1_LSB)
#define MAC_DMA_ISR_S7_S_RESERVED_1_SET(x)                           (((0 | (x)) << MAC_DMA_ISR_S7_S_RESERVED_1_LSB) & MAC_DMA_ISR_S7_S_RESERVED_1_MASK)
#define MAC_DMA_ISR_S7_S_RESERVED_1_RESET                            0
#define MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_MSB                  19
#define MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_LSB                  19
#define MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_MASK                 0x00080000
#define MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_GET(x)               (((x) & MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_MASK) >> MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_LSB)
#define MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_SET(x)               (((0 | (x)) << MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_LSB) & MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_MASK)
#define MAC_DMA_ISR_S7_S_OLE_RX_WMAC_PARSER_ERR_RESET                0
#define MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_MSB                   18
#define MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_LSB                   18
#define MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_MASK                  0x00040000
#define MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_GET(x)                (((x) & MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_MASK) >> MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_LSB)
#define MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_SET(x)                (((0 | (x)) << MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_LSB) & MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_MASK)
#define MAC_DMA_ISR_S7_S_OLE_RX_ETH_PARSER_ERR_RESET                 0
#define MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_MSB                   17
#define MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_LSB                   17
#define MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_MASK                  0x00020000
#define MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_GET(x)                (((x) & MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_MASK) >> MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_LSB)
#define MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_SET(x)                (((0 | (x)) << MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_LSB) & MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_MASK)
#define MAC_DMA_ISR_S7_S_OLE_RX_MPDU_PKT_ABORT_RESET                 0
#define MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_MSB                     16
#define MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_LSB                     16
#define MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_MASK                    0x00010000
#define MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_GET(x)                  (((x) & MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_MASK) >> MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_LSB)
#define MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_SET(x)                  (((0 | (x)) << MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_LSB) & MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_MASK)
#define MAC_DMA_ISR_S7_S_OLE_RX_MSDU_LEN_ERR_RESET                   0
#define MAC_DMA_ISR_S7_S_RESERVED_0_MSB                              15
#define MAC_DMA_ISR_S7_S_RESERVED_0_LSB                              9
#define MAC_DMA_ISR_S7_S_RESERVED_0_MASK                             0x0000fe00
#define MAC_DMA_ISR_S7_S_RESERVED_0_GET(x)                           (((x) & MAC_DMA_ISR_S7_S_RESERVED_0_MASK) >> MAC_DMA_ISR_S7_S_RESERVED_0_LSB)
#define MAC_DMA_ISR_S7_S_RESERVED_0_SET(x)                           (((0 | (x)) << MAC_DMA_ISR_S7_S_RESERVED_0_LSB) & MAC_DMA_ISR_S7_S_RESERVED_0_MASK)
#define MAC_DMA_ISR_S7_S_RESERVED_0_RESET                            0
#define MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_MSB                    8
#define MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_LSB                    8
#define MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_MASK                   0x00000100
#define MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_GET(x)                 (((x) & MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_MASK) >> MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_LSB)
#define MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_SET(x)                 (((0 | (x)) << MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_LSB) & MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_MASK)
#define MAC_DMA_ISR_S7_S_OLE_TX_ILLEGAL_FRAME_RESET                  0
#define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_MSB                      7
#define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_LSB                      7
#define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_MASK                     0x00000080
#define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_GET(x)                   (((x) & MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_MASK) >> MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_LSB)
#define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_SET(x)                   (((0 | (x)) << MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_LSB) & MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_MASK)
#define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_LLC_RESET                    0
#define MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_MSB              6
#define MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_LSB              6
#define MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_MASK             0x00000040
#define MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_GET(x)           (((x) & MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_MASK) >> MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_LSB)
#define MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_SET(x)           (((0 | (x)) << MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_LSB) & MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_MASK)
#define MAC_DMA_ISR_S7_S_OLE_TX_INCOMPLETE_VLAN_LLC_RESET            0
#define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_MSB                 5
#define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_LSB                 5
#define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_MASK                0x00000020
#define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_GET(x)              (((x) & MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_MASK) >> MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_LSB)
#define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_SET(x)              (((0 | (x)) << MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_LSB) & MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_MASK)
#define MAC_DMA_ISR_S7_S_OLE_TX_UNKNOWN_TYPE_ERR_RESET               0
#define MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_MSB               4
#define MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_LSB               4
#define MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_MASK              0x00000010
#define MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_GET(x)            (((x) & MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_MASK) >> MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_LSB)
#define MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_SET(x)            (((0 | (x)) << MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_LSB) & MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_MASK)
#define MAC_DMA_ISR_S7_S_OLE_TX_SEQ_NUM_BITMAP_ERR_RESET             0
#define MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_MSB                    3
#define MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_LSB                    3
#define MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_MASK                   0x00000008
#define MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_GET(x)                 (((x) & MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_MASK) >> MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_LSB)
#define MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_SET(x)                 (((0 | (x)) << MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_LSB) & MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_MASK)
#define MAC_DMA_ISR_S7_S_OLE_TX_PN_BITMAP_ERR_RESET                  0
#define MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_MSB                  2
#define MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_LSB                  2
#define MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_MASK                 0x00000004
#define MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_GET(x)               (((x) & MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_MASK) >> MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_LSB)
#define MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_SET(x)               (((0 | (x)) << MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_LSB) & MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_MASK)
#define MAC_DMA_ISR_S7_S_OLE_TX_AMSDU_FRAME_ERR_RESET                0
#define MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_MSB                    1
#define MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_LSB                    1
#define MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_MASK                   0x00000002
#define MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_GET(x)                 (((x) & MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_MASK) >> MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_LSB)
#define MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_SET(x)                 (((0 | (x)) << MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_LSB) & MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_MASK)
#define MAC_DMA_ISR_S7_S_OLE_TX_WEP_KTYPE_ERR_RESET                  0
#define MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_MSB                        0
#define MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_LSB                        0
#define MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_MASK                       0x00000001
#define MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_GET(x)                     (((x) & MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_MASK) >> MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_LSB)
#define MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_SET(x)                     (((0 | (x)) << MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_LSB) & MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_MASK)
#define MAC_DMA_ISR_S7_S_DMA_OLE_TX_ABORT_RESET                      0
#define MAC_DMA_ISR_S7_S_ADDRESS                                     0x0110
#define MAC_DMA_ISR_S7_S_HW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S7_S_SW_MASK                                     0xffffffff
#define MAC_DMA_ISR_S7_S_HW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S7_S_SW_WRITE_MASK                               0xffffffff
#define MAC_DMA_ISR_S7_S_RSTMASK                                     0xffffffff
#define MAC_DMA_ISR_S7_S_RESET                                       0x00000000

// 0x012c (MAC_DMA_CHKACC)
#define MAC_DMA_CHKACC_CHKSUM_SEL_MSB                                0
#define MAC_DMA_CHKACC_CHKSUM_SEL_LSB                                0
#define MAC_DMA_CHKACC_CHKSUM_SEL_MASK                               0x00000001
#define MAC_DMA_CHKACC_CHKSUM_SEL_GET(x)                             (((x) & MAC_DMA_CHKACC_CHKSUM_SEL_MASK) >> MAC_DMA_CHKACC_CHKSUM_SEL_LSB)
#define MAC_DMA_CHKACC_CHKSUM_SEL_SET(x)                             (((0 | (x)) << MAC_DMA_CHKACC_CHKSUM_SEL_LSB) & MAC_DMA_CHKACC_CHKSUM_SEL_MASK)
#define MAC_DMA_CHKACC_CHKSUM_SEL_RESET                              0
#define MAC_DMA_CHKACC_ADDRESS                                       0x012c
#define MAC_DMA_CHKACC_HW_MASK                                       0x00000001
#define MAC_DMA_CHKACC_SW_MASK                                       0x00000001
#define MAC_DMA_CHKACC_HW_WRITE_MASK                                 0x00000000
#define MAC_DMA_CHKACC_SW_WRITE_MASK                                 0x00000001
#define MAC_DMA_CHKACC_RSTMASK                                       0xffffffff
#define MAC_DMA_CHKACC_RESET                                         0x00000000

// 0x0138 (MAC_DMA_AXI_CFG_0)
#define MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_MSB                     31
#define MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_LSB                     0
#define MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_MASK                    0xffffffff
#define MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_GET(x)                  (((x) & MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_MASK) >> MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_LSB)
#define MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_SET(x)                  (((0 | (x)) << MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_LSB) & MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_MASK)
#define MAC_DMA_AXI_CFG_0_WIFI_MEM_BASE_ADDR_RESET                   0
#define MAC_DMA_AXI_CFG_0_ADDRESS                                    0x0138
#define MAC_DMA_AXI_CFG_0_HW_MASK                                    0xffffffff
#define MAC_DMA_AXI_CFG_0_SW_MASK                                    0xffffffff
#define MAC_DMA_AXI_CFG_0_HW_WRITE_MASK                              0x00000000
#define MAC_DMA_AXI_CFG_0_SW_WRITE_MASK                              0xffffffff
#define MAC_DMA_AXI_CFG_0_RSTMASK                                    0xffffffff
#define MAC_DMA_AXI_CFG_0_RESET                                      0x00000000

// 0x013c (MAC_DMA_AXI_CFG_1)
#define MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_MSB                          31
#define MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_LSB                          0
#define MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_MASK                         0xffffffff
#define MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_GET(x)                       (((x) & MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_MASK) >> MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_LSB)
#define MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_SET(x)                       (((0 | (x)) << MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_LSB) & MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_MASK)
#define MAC_DMA_AXI_CFG_1_WIFI_MEM_MASK_RESET                        0
#define MAC_DMA_AXI_CFG_1_ADDRESS                                    0x013c
#define MAC_DMA_AXI_CFG_1_HW_MASK                                    0xffffffff
#define MAC_DMA_AXI_CFG_1_SW_MASK                                    0xffffffff
#define MAC_DMA_AXI_CFG_1_HW_WRITE_MASK                              0x00000000
#define MAC_DMA_AXI_CFG_1_SW_WRITE_MASK                              0xffffffff
#define MAC_DMA_AXI_CFG_1_RSTMASK                                    0xffffffff
#define MAC_DMA_AXI_CFG_1_RESET                                      0x00000000

// 0x0140 (MAC_DMA_AXI_CFG_2)
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_MSB                    3
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_LSB                    2
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_MASK                   0x0000000c
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_GET(x)                 (((x) & MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_MASK) >> MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_LSB)
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_SET(x)                 (((0 | (x)) << MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_LSB) & MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_MASK)
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_WRITE_SIZE_RESET                  0
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_MSB                     1
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_LSB                     0
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_MASK                    0x00000003
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_GET(x)                  (((x) & MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_MASK) >> MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_LSB)
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_SET(x)                  (((0 | (x)) << MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_LSB) & MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_MASK)
#define MAC_DMA_AXI_CFG_2_WIFI_MEM_READ_SIZE_RESET                   0
#define MAC_DMA_AXI_CFG_2_ADDRESS                                    0x0140
#define MAC_DMA_AXI_CFG_2_HW_MASK                                    0x0000000f
#define MAC_DMA_AXI_CFG_2_SW_MASK                                    0x0000000f
#define MAC_DMA_AXI_CFG_2_HW_WRITE_MASK                              0x00000000
#define MAC_DMA_AXI_CFG_2_SW_WRITE_MASK                              0x0000000f
#define MAC_DMA_AXI_CFG_2_RSTMASK                                    0xffffffff
#define MAC_DMA_AXI_CFG_2_RESET                                      0x00000000

// 0x0200 (MAC_DMA_RCV_CFG_RING0_0)
#define MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_MSB                        31
#define MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_LSB                        0
#define MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_MASK                       0xffffffff
#define MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_GET(x)                     (((x) & MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_MASK) >> MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_LSB)
#define MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_SET(x)                     (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_LSB) & MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_MASK)
#define MAC_DMA_RCV_CFG_RING0_0_BASE_ADDR_RESET                      0
#define MAC_DMA_RCV_CFG_RING0_0_ADDRESS                              0x0200
#define MAC_DMA_RCV_CFG_RING0_0_HW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING0_0_SW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING0_0_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING0_0_SW_WRITE_MASK                        0xffffffff
#define MAC_DMA_RCV_CFG_RING0_0_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING0_0_RESET                                0x00000000

// 0x0204 (MAC_DMA_RCV_CFG_RING0_1)
#define MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_MSB                         31
#define MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_LSB                         16
#define MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_MASK                        0xffff0000
#define MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_GET(x)                      (((x) & MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_MASK) >> MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_LSB)
#define MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_SET(x)                      (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_LSB) & MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_MASK)
#define MAC_DMA_RCV_CFG_RING0_1_BUF_SIZE_RESET                       0
#define MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_MSB                        14
#define MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_LSB                        0
#define MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_MASK                       0x00007fff
#define MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_GET(x)                     (((x) & MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_MASK) >> MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_LSB)
#define MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_SET(x)                     (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_LSB) & MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_MASK)
#define MAC_DMA_RCV_CFG_RING0_1_NUM_DESCS_RESET                      0
#define MAC_DMA_RCV_CFG_RING0_1_ADDRESS                              0x0204
#define MAC_DMA_RCV_CFG_RING0_1_HW_MASK                              0xffff7fff
#define MAC_DMA_RCV_CFG_RING0_1_SW_MASK                              0xffff7fff
#define MAC_DMA_RCV_CFG_RING0_1_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING0_1_SW_WRITE_MASK                        0xffff7fff
#define MAC_DMA_RCV_CFG_RING0_1_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING0_1_RESET                                0x00000000

// 0x0208 (MAC_DMA_RCV_CFG_RING0_2)
#define MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_MSB                 25
#define MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_LSB                 25
#define MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_MASK                0x02000000
#define MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_LSB) & MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING0_2_RX_FRAGINFO_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_MSB                24
#define MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_LSB                24
#define MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_MASK               0x01000000
#define MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_GET(x)             (((x) & MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_SET(x)             (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_LSB) & MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING0_2_RX_ATTENTION_SWAP_RESET              0
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_MSB                 23
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_LSB                 23
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_MASK                0x00800000
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_LSB) & MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_END_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_MSB               22
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_LSB               22
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_MASK              0x00400000
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_LSB) & MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MSDU_START_SWAP_RESET             0
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_MSB                 21
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_LSB                 21
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_MASK                0x00200000
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_LSB) & MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_END_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_MSB               20
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_LSB               20
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_MASK              0x00100000
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_LSB) & MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING0_2_RX_MPDU_START_SWAP_RESET             0
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_MSB                 19
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_LSB                 19
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_MASK                0x00080000
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_LSB) & MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_END_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_MSB               18
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_LSB               18
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_MASK              0x00040000
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_LSB) & MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING0_2_RX_PPDU_START_SWAP_RESET             0
#define MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_MSB                   17
#define MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_LSB                   17
#define MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_MASK                  0x00020000
#define MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_GET(x)                (((x) & MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_SET(x)                (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_LSB) & MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING0_2_RX_PACKET_SWAP_RESET                 0
#define MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_MSB                   16
#define MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_LSB                   16
#define MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_MASK                  0x00010000
#define MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_GET(x)                (((x) & MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_SET(x)                (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_LSB) & MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING0_2_RX_HEADER_SWAP_RESET                 0
#define MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_MSB                  7
#define MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_LSB                  0
#define MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_MASK                 0x000000ff
#define MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_GET(x)               (((x) & MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_MASK) >> MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_LSB)
#define MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_SET(x)               (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_LSB) & MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_MASK)
#define MAC_DMA_RCV_CFG_RING0_2_INTR_LWM_THRESH_RESET                5
#define MAC_DMA_RCV_CFG_RING0_2_ADDRESS                              0x0208
#define MAC_DMA_RCV_CFG_RING0_2_HW_MASK                              0x03ff00ff
#define MAC_DMA_RCV_CFG_RING0_2_SW_MASK                              0x03ff00ff
#define MAC_DMA_RCV_CFG_RING0_2_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING0_2_SW_WRITE_MASK                        0x03ff00ff
#define MAC_DMA_RCV_CFG_RING0_2_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING0_2_RESET                                0x00000005

// 0x020c (MAC_DMA_RCV_CFG_RING0_3)
#define MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_MSB                 25
#define MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_LSB                 18
#define MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_MASK                0x03fc0000
#define MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING0_3_RX_PACKET_OFFSET_RESET               0
#define MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_MSB                 9
#define MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_LSB                 2
#define MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_MASK                0x000003fc
#define MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING0_3_RX_HEADER_OFFSET_RESET               0
#define MAC_DMA_RCV_CFG_RING0_3_ADDRESS                              0x020c
#define MAC_DMA_RCV_CFG_RING0_3_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_3_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_3_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING0_3_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_3_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING0_3_RESET                                0x00000000

// 0x0210 (MAC_DMA_RCV_CFG_RING0_4)
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_END_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_MSB             9
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_LSB             2
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_MASK            0x000003fc
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_GET(x)          (((x) & MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_SET(x)          (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING0_4_RX_PPDU_START_OFFSET_RESET           0
#define MAC_DMA_RCV_CFG_RING0_4_ADDRESS                              0x0210
#define MAC_DMA_RCV_CFG_RING0_4_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_4_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_4_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING0_4_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_4_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING0_4_RESET                                0x00000000

// 0x0214 (MAC_DMA_RCV_CFG_RING0_5)
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_END_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_MSB             9
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_LSB             2
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_MASK            0x000003fc
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_GET(x)          (((x) & MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_SET(x)          (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING0_5_RX_MPDU_START_OFFSET_RESET           0
#define MAC_DMA_RCV_CFG_RING0_5_ADDRESS                              0x0214
#define MAC_DMA_RCV_CFG_RING0_5_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_5_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_5_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING0_5_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_5_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING0_5_RESET                                0x00000000

// 0x0218 (MAC_DMA_RCV_CFG_RING0_6)
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_END_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_MSB             9
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_LSB             2
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_MASK            0x000003fc
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_GET(x)          (((x) & MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_SET(x)          (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING0_6_RX_MSDU_START_OFFSET_RESET           0
#define MAC_DMA_RCV_CFG_RING0_6_ADDRESS                              0x0218
#define MAC_DMA_RCV_CFG_RING0_6_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_6_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_6_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING0_6_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_6_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING0_6_RESET                                0x00000000

// 0x021c (MAC_DMA_RCV_CFG_RING0_7)
#define MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING0_7_RX_FRAGINFO_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_MSB              9
#define MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_LSB              2
#define MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_MASK             0x000003fc
#define MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_GET(x)           (((x) & MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_SET(x)           (((0 | (x)) << MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING0_7_RX_ATTENTION_OFFSET_RESET            0
#define MAC_DMA_RCV_CFG_RING0_7_ADDRESS                              0x021c
#define MAC_DMA_RCV_CFG_RING0_7_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_7_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_7_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING0_7_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING0_7_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING0_7_RESET                                0x00000000

// 0x0230 (MAC_DMA_RCV_CFG_RING1_0)
#define MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_MSB                        31
#define MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_LSB                        0
#define MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_MASK                       0xffffffff
#define MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_GET(x)                     (((x) & MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_MASK) >> MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_LSB)
#define MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_SET(x)                     (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_LSB) & MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_MASK)
#define MAC_DMA_RCV_CFG_RING1_0_BASE_ADDR_RESET                      0
#define MAC_DMA_RCV_CFG_RING1_0_ADDRESS                              0x0230
#define MAC_DMA_RCV_CFG_RING1_0_HW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING1_0_SW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING1_0_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING1_0_SW_WRITE_MASK                        0xffffffff
#define MAC_DMA_RCV_CFG_RING1_0_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING1_0_RESET                                0x00000000

// 0x0234 (MAC_DMA_RCV_CFG_RING1_1)
#define MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_MSB                         31
#define MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_LSB                         16
#define MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_MASK                        0xffff0000
#define MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_GET(x)                      (((x) & MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_MASK) >> MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_LSB)
#define MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_SET(x)                      (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_LSB) & MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_MASK)
#define MAC_DMA_RCV_CFG_RING1_1_BUF_SIZE_RESET                       0
#define MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_MSB                        15
#define MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_LSB                        0
#define MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_MASK                       0x0000ffff
#define MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_GET(x)                     (((x) & MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_MASK) >> MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_LSB)
#define MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_SET(x)                     (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_LSB) & MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_MASK)
#define MAC_DMA_RCV_CFG_RING1_1_NUM_DESCS_RESET                      0
#define MAC_DMA_RCV_CFG_RING1_1_ADDRESS                              0x0234
#define MAC_DMA_RCV_CFG_RING1_1_HW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING1_1_SW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING1_1_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING1_1_SW_WRITE_MASK                        0xffffffff
#define MAC_DMA_RCV_CFG_RING1_1_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING1_1_RESET                                0x00000000

// 0x0238 (MAC_DMA_RCV_CFG_RING1_2)
#define MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_MSB                 25
#define MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_LSB                 25
#define MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_MASK                0x02000000
#define MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_LSB) & MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING1_2_RX_FRAGINFO_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_MSB                24
#define MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_LSB                24
#define MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_MASK               0x01000000
#define MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_GET(x)             (((x) & MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_SET(x)             (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_LSB) & MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING1_2_RX_ATTENTION_SWAP_RESET              0
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_MSB                 23
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_LSB                 23
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_MASK                0x00800000
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_LSB) & MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_END_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_MSB               22
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_LSB               22
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_MASK              0x00400000
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_LSB) & MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MSDU_START_SWAP_RESET             0
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_MSB                 21
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_LSB                 21
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_MASK                0x00200000
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_LSB) & MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_END_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_MSB               20
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_LSB               20
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_MASK              0x00100000
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_LSB) & MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING1_2_RX_MPDU_START_SWAP_RESET             0
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_MSB                 19
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_LSB                 19
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_MASK                0x00080000
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_LSB) & MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_END_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_MSB               18
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_LSB               18
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_MASK              0x00040000
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_LSB) & MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING1_2_RX_PPDU_START_SWAP_RESET             0
#define MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_MSB                   17
#define MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_LSB                   17
#define MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_MASK                  0x00020000
#define MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_GET(x)                (((x) & MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_SET(x)                (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_LSB) & MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING1_2_RX_PACKET_SWAP_RESET                 0
#define MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_MSB                   16
#define MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_LSB                   16
#define MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_MASK                  0x00010000
#define MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_GET(x)                (((x) & MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_SET(x)                (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_LSB) & MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING1_2_RX_HEADER_SWAP_RESET                 0
#define MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_MSB                  7
#define MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_LSB                  0
#define MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_MASK                 0x000000ff
#define MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_GET(x)               (((x) & MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_MASK) >> MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_LSB)
#define MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_SET(x)               (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_LSB) & MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_MASK)
#define MAC_DMA_RCV_CFG_RING1_2_INTR_LWM_THRESH_RESET                5
#define MAC_DMA_RCV_CFG_RING1_2_ADDRESS                              0x0238
#define MAC_DMA_RCV_CFG_RING1_2_HW_MASK                              0x03ff00ff
#define MAC_DMA_RCV_CFG_RING1_2_SW_MASK                              0x03ff00ff
#define MAC_DMA_RCV_CFG_RING1_2_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING1_2_SW_WRITE_MASK                        0x03ff00ff
#define MAC_DMA_RCV_CFG_RING1_2_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING1_2_RESET                                0x00000005

// 0x023c (MAC_DMA_RCV_CFG_RING1_3)
#define MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_MSB                 25
#define MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_LSB                 18
#define MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_MASK                0x03fc0000
#define MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING1_3_RX_PACKET_OFFSET_RESET               0
#define MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_MSB                 9
#define MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_LSB                 2
#define MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_MASK                0x000003fc
#define MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING1_3_RX_HEADER_OFFSET_RESET               0
#define MAC_DMA_RCV_CFG_RING1_3_ADDRESS                              0x023c
#define MAC_DMA_RCV_CFG_RING1_3_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_3_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_3_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING1_3_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_3_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING1_3_RESET                                0x00000000

// 0x0240 (MAC_DMA_RCV_CFG_RING1_4)
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_END_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_MSB             9
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_LSB             2
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_MASK            0x000003fc
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_GET(x)          (((x) & MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_SET(x)          (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING1_4_RX_PPDU_START_OFFSET_RESET           0
#define MAC_DMA_RCV_CFG_RING1_4_ADDRESS                              0x0240
#define MAC_DMA_RCV_CFG_RING1_4_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_4_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_4_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING1_4_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_4_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING1_4_RESET                                0x00000000

// 0x0244 (MAC_DMA_RCV_CFG_RING1_5)
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_END_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_MSB             9
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_LSB             2
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_MASK            0x000003fc
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_GET(x)          (((x) & MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_SET(x)          (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING1_5_RX_MPDU_START_OFFSET_RESET           0
#define MAC_DMA_RCV_CFG_RING1_5_ADDRESS                              0x0244
#define MAC_DMA_RCV_CFG_RING1_5_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_5_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_5_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING1_5_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_5_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING1_5_RESET                                0x00000000

// 0x0248 (MAC_DMA_RCV_CFG_RING1_6)
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_END_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_MSB             9
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_LSB             2
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_MASK            0x000003fc
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_GET(x)          (((x) & MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_SET(x)          (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING1_6_RX_MSDU_START_OFFSET_RESET           0
#define MAC_DMA_RCV_CFG_RING1_6_ADDRESS                              0x0248
#define MAC_DMA_RCV_CFG_RING1_6_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_6_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_6_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING1_6_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_6_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING1_6_RESET                                0x00000000

// 0x024c (MAC_DMA_RCV_CFG_RING1_7)
#define MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING1_7_RX_FRAGINFO_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_MSB              9
#define MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_LSB              2
#define MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_MASK             0x000003fc
#define MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_GET(x)           (((x) & MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_SET(x)           (((0 | (x)) << MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING1_7_RX_ATTENTION_OFFSET_RESET            0
#define MAC_DMA_RCV_CFG_RING1_7_ADDRESS                              0x024c
#define MAC_DMA_RCV_CFG_RING1_7_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_7_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_7_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING1_7_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING1_7_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING1_7_RESET                                0x00000000

// 0x0260 (MAC_DMA_RCV_CFG_RING2_0)
#define MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_MSB                        31
#define MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_LSB                        0
#define MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_MASK                       0xffffffff
#define MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_GET(x)                     (((x) & MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_MASK) >> MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_LSB)
#define MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_SET(x)                     (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_LSB) & MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_MASK)
#define MAC_DMA_RCV_CFG_RING2_0_BASE_ADDR_RESET                      0
#define MAC_DMA_RCV_CFG_RING2_0_ADDRESS                              0x0260
#define MAC_DMA_RCV_CFG_RING2_0_HW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING2_0_SW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING2_0_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING2_0_SW_WRITE_MASK                        0xffffffff
#define MAC_DMA_RCV_CFG_RING2_0_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING2_0_RESET                                0x00000000

// 0x0264 (MAC_DMA_RCV_CFG_RING2_1)
#define MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_MSB                         31
#define MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_LSB                         16
#define MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_MASK                        0xffff0000
#define MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_GET(x)                      (((x) & MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_MASK) >> MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_LSB)
#define MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_SET(x)                      (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_LSB) & MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_MASK)
#define MAC_DMA_RCV_CFG_RING2_1_BUF_SIZE_RESET                       0
#define MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_MSB                        15
#define MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_LSB                        0
#define MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_MASK                       0x0000ffff
#define MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_GET(x)                     (((x) & MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_MASK) >> MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_LSB)
#define MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_SET(x)                     (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_LSB) & MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_MASK)
#define MAC_DMA_RCV_CFG_RING2_1_NUM_DESCS_RESET                      0
#define MAC_DMA_RCV_CFG_RING2_1_ADDRESS                              0x0264
#define MAC_DMA_RCV_CFG_RING2_1_HW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING2_1_SW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING2_1_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING2_1_SW_WRITE_MASK                        0xffffffff
#define MAC_DMA_RCV_CFG_RING2_1_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING2_1_RESET                                0x00000000

// 0x0268 (MAC_DMA_RCV_CFG_RING2_2)
#define MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_MSB                 25
#define MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_LSB                 25
#define MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_MASK                0x02000000
#define MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_LSB) & MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING2_2_RX_FRAGINFO_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_MSB                24
#define MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_LSB                24
#define MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_MASK               0x01000000
#define MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_GET(x)             (((x) & MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_SET(x)             (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_LSB) & MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING2_2_RX_ATTENTION_SWAP_RESET              0
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_MSB                 23
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_LSB                 23
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_MASK                0x00800000
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_LSB) & MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_END_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_MSB               22
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_LSB               22
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_MASK              0x00400000
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_LSB) & MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MSDU_START_SWAP_RESET             0
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_MSB                 21
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_LSB                 21
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_MASK                0x00200000
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_LSB) & MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_END_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_MSB               20
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_LSB               20
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_MASK              0x00100000
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_LSB) & MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING2_2_RX_MPDU_START_SWAP_RESET             0
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_MSB                 19
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_LSB                 19
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_MASK                0x00080000
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_LSB) & MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_END_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_MSB               18
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_LSB               18
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_MASK              0x00040000
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_LSB) & MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING2_2_RX_PPDU_START_SWAP_RESET             0
#define MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_MSB                   17
#define MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_LSB                   17
#define MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_MASK                  0x00020000
#define MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_GET(x)                (((x) & MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_SET(x)                (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_LSB) & MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING2_2_RX_PACKET_SWAP_RESET                 0
#define MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_MSB                   16
#define MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_LSB                   16
#define MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_MASK                  0x00010000
#define MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_GET(x)                (((x) & MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_SET(x)                (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_LSB) & MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING2_2_RX_HEADER_SWAP_RESET                 0
#define MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_MSB                  7
#define MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_LSB                  0
#define MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_MASK                 0x000000ff
#define MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_GET(x)               (((x) & MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_MASK) >> MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_LSB)
#define MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_SET(x)               (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_LSB) & MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_MASK)
#define MAC_DMA_RCV_CFG_RING2_2_INTR_LWM_THRESH_RESET                5
#define MAC_DMA_RCV_CFG_RING2_2_ADDRESS                              0x0268
#define MAC_DMA_RCV_CFG_RING2_2_HW_MASK                              0x03ff00ff
#define MAC_DMA_RCV_CFG_RING2_2_SW_MASK                              0x03ff00ff
#define MAC_DMA_RCV_CFG_RING2_2_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING2_2_SW_WRITE_MASK                        0x03ff00ff
#define MAC_DMA_RCV_CFG_RING2_2_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING2_2_RESET                                0x00000005

// 0x026c (MAC_DMA_RCV_CFG_RING2_3)
#define MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_MSB                 25
#define MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_LSB                 18
#define MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_MASK                0x03fc0000
#define MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING2_3_RX_PACKET_OFFSET_RESET               0
#define MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_MSB                 9
#define MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_LSB                 2
#define MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_MASK                0x000003fc
#define MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING2_3_RX_HEADER_OFFSET_RESET               0
#define MAC_DMA_RCV_CFG_RING2_3_ADDRESS                              0x026c
#define MAC_DMA_RCV_CFG_RING2_3_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_3_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_3_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING2_3_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_3_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING2_3_RESET                                0x00000000

// 0x0270 (MAC_DMA_RCV_CFG_RING2_4)
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_END_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_MSB             9
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_LSB             2
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_MASK            0x000003fc
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_GET(x)          (((x) & MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_SET(x)          (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING2_4_RX_PPDU_START_OFFSET_RESET           0
#define MAC_DMA_RCV_CFG_RING2_4_ADDRESS                              0x0270
#define MAC_DMA_RCV_CFG_RING2_4_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_4_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_4_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING2_4_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_4_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING2_4_RESET                                0x00000000

// 0x0274 (MAC_DMA_RCV_CFG_RING2_5)
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_END_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_MSB             9
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_LSB             2
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_MASK            0x000003fc
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_GET(x)          (((x) & MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_SET(x)          (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING2_5_RX_MPDU_START_OFFSET_RESET           0
#define MAC_DMA_RCV_CFG_RING2_5_ADDRESS                              0x0274
#define MAC_DMA_RCV_CFG_RING2_5_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_5_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_5_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING2_5_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_5_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING2_5_RESET                                0x00000000

// 0x0278 (MAC_DMA_RCV_CFG_RING2_6)
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_END_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_MSB             9
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_LSB             2
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_MASK            0x000003fc
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_GET(x)          (((x) & MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_SET(x)          (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING2_6_RX_MSDU_START_OFFSET_RESET           0
#define MAC_DMA_RCV_CFG_RING2_6_ADDRESS                              0x0278
#define MAC_DMA_RCV_CFG_RING2_6_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_6_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_6_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING2_6_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_6_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING2_6_RESET                                0x00000000

// 0x027c (MAC_DMA_RCV_CFG_RING2_7)
#define MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING2_7_RX_FRAGINFO_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_MSB              9
#define MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_LSB              2
#define MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_MASK             0x000003fc
#define MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_GET(x)           (((x) & MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_SET(x)           (((0 | (x)) << MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING2_7_RX_ATTENTION_OFFSET_RESET            0
#define MAC_DMA_RCV_CFG_RING2_7_ADDRESS                              0x027c
#define MAC_DMA_RCV_CFG_RING2_7_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_7_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_7_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING2_7_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING2_7_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING2_7_RESET                                0x00000000

// 0x0290 (MAC_DMA_RCV_CFG_RING3_0)
#define MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_MSB                        31
#define MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_LSB                        0
#define MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_MASK                       0xffffffff
#define MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_GET(x)                     (((x) & MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_MASK) >> MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_LSB)
#define MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_SET(x)                     (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_LSB) & MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_MASK)
#define MAC_DMA_RCV_CFG_RING3_0_BASE_ADDR_RESET                      0
#define MAC_DMA_RCV_CFG_RING3_0_ADDRESS                              0x0290
#define MAC_DMA_RCV_CFG_RING3_0_HW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING3_0_SW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING3_0_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING3_0_SW_WRITE_MASK                        0xffffffff
#define MAC_DMA_RCV_CFG_RING3_0_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING3_0_RESET                                0x00000000

// 0x0294 (MAC_DMA_RCV_CFG_RING3_1)
#define MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_MSB                         31
#define MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_LSB                         16
#define MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_MASK                        0xffff0000
#define MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_GET(x)                      (((x) & MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_MASK) >> MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_LSB)
#define MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_SET(x)                      (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_LSB) & MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_MASK)
#define MAC_DMA_RCV_CFG_RING3_1_BUF_SIZE_RESET                       0
#define MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_MSB                        15
#define MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_LSB                        0
#define MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_MASK                       0x0000ffff
#define MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_GET(x)                     (((x) & MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_MASK) >> MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_LSB)
#define MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_SET(x)                     (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_LSB) & MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_MASK)
#define MAC_DMA_RCV_CFG_RING3_1_NUM_DESCS_RESET                      0
#define MAC_DMA_RCV_CFG_RING3_1_ADDRESS                              0x0294
#define MAC_DMA_RCV_CFG_RING3_1_HW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING3_1_SW_MASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING3_1_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING3_1_SW_WRITE_MASK                        0xffffffff
#define MAC_DMA_RCV_CFG_RING3_1_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING3_1_RESET                                0x00000000

// 0x0298 (MAC_DMA_RCV_CFG_RING3_2)
#define MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_MSB                 25
#define MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_LSB                 25
#define MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_MASK                0x02000000
#define MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_LSB) & MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING3_2_RX_FRAGINFO_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_MSB                24
#define MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_LSB                24
#define MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_MASK               0x01000000
#define MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_GET(x)             (((x) & MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_SET(x)             (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_LSB) & MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING3_2_RX_ATTENTION_SWAP_RESET              0
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_MSB                 23
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_LSB                 23
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_MASK                0x00800000
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_LSB) & MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_END_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_MSB               22
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_LSB               22
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_MASK              0x00400000
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_LSB) & MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MSDU_START_SWAP_RESET             0
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_MSB                 21
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_LSB                 21
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_MASK                0x00200000
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_LSB) & MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_END_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_MSB               20
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_LSB               20
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_MASK              0x00100000
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_LSB) & MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING3_2_RX_MPDU_START_SWAP_RESET             0
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_MSB                 19
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_LSB                 19
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_MASK                0x00080000
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_LSB) & MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_END_SWAP_RESET               0
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_MSB               18
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_LSB               18
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_MASK              0x00040000
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_LSB) & MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING3_2_RX_PPDU_START_SWAP_RESET             0
#define MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_MSB                   17
#define MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_LSB                   17
#define MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_MASK                  0x00020000
#define MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_GET(x)                (((x) & MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_SET(x)                (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_LSB) & MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING3_2_RX_PACKET_SWAP_RESET                 0
#define MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_MSB                   16
#define MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_LSB                   16
#define MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_MASK                  0x00010000
#define MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_GET(x)                (((x) & MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_MASK) >> MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_LSB)
#define MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_SET(x)                (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_LSB) & MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_MASK)
#define MAC_DMA_RCV_CFG_RING3_2_RX_HEADER_SWAP_RESET                 0
#define MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_MSB                  7
#define MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_LSB                  0
#define MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_MASK                 0x000000ff
#define MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_GET(x)               (((x) & MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_MASK) >> MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_LSB)
#define MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_SET(x)               (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_LSB) & MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_MASK)
#define MAC_DMA_RCV_CFG_RING3_2_INTR_LWM_THRESH_RESET                5
#define MAC_DMA_RCV_CFG_RING3_2_ADDRESS                              0x0298
#define MAC_DMA_RCV_CFG_RING3_2_HW_MASK                              0x03ff00ff
#define MAC_DMA_RCV_CFG_RING3_2_SW_MASK                              0x03ff00ff
#define MAC_DMA_RCV_CFG_RING3_2_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING3_2_SW_WRITE_MASK                        0x03ff00ff
#define MAC_DMA_RCV_CFG_RING3_2_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING3_2_RESET                                0x00000005

// 0x029c (MAC_DMA_RCV_CFG_RING3_3)
#define MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_MSB                 25
#define MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_LSB                 18
#define MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_MASK                0x03fc0000
#define MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING3_3_RX_PACKET_OFFSET_RESET               0
#define MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_MSB                 9
#define MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_LSB                 2
#define MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_MASK                0x000003fc
#define MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_GET(x)              (((x) & MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_SET(x)              (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING3_3_RX_HEADER_OFFSET_RESET               0
#define MAC_DMA_RCV_CFG_RING3_3_ADDRESS                              0x029c
#define MAC_DMA_RCV_CFG_RING3_3_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_3_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_3_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING3_3_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_3_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING3_3_RESET                                0x00000000

// 0x02a0 (MAC_DMA_RCV_CFG_RING3_4)
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_END_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_MSB             9
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_LSB             2
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_MASK            0x000003fc
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_GET(x)          (((x) & MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_SET(x)          (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING3_4_RX_PPDU_START_OFFSET_RESET           0
#define MAC_DMA_RCV_CFG_RING3_4_ADDRESS                              0x02a0
#define MAC_DMA_RCV_CFG_RING3_4_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_4_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_4_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING3_4_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_4_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING3_4_RESET                                0x00000000

// 0x02a4 (MAC_DMA_RCV_CFG_RING3_5)
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_END_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_MSB             9
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_LSB             2
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_MASK            0x000003fc
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_GET(x)          (((x) & MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_SET(x)          (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING3_5_RX_MPDU_START_OFFSET_RESET           0
#define MAC_DMA_RCV_CFG_RING3_5_ADDRESS                              0x02a4
#define MAC_DMA_RCV_CFG_RING3_5_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_5_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_5_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING3_5_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_5_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING3_5_RESET                                0x00000000

// 0x02a8 (MAC_DMA_RCV_CFG_RING3_6)
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_END_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_MSB             9
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_LSB             2
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_MASK            0x000003fc
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_GET(x)          (((x) & MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_SET(x)          (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING3_6_RX_MSDU_START_OFFSET_RESET           0
#define MAC_DMA_RCV_CFG_RING3_6_ADDRESS                              0x02a8
#define MAC_DMA_RCV_CFG_RING3_6_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_6_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_6_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING3_6_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_6_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING3_6_RESET                                0x00000000

// 0x02ac (MAC_DMA_RCV_CFG_RING3_7)
#define MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_MSB               25
#define MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_LSB               18
#define MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_MASK              0x03fc0000
#define MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_GET(x)            (((x) & MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_SET(x)            (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING3_7_RX_FRAGINFO_OFFSET_RESET             0
#define MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_MSB              9
#define MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_LSB              2
#define MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_MASK             0x000003fc
#define MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_GET(x)           (((x) & MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_MASK) >> MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_LSB)
#define MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_SET(x)           (((0 | (x)) << MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_LSB) & MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_MASK)
#define MAC_DMA_RCV_CFG_RING3_7_RX_ATTENTION_OFFSET_RESET            0
#define MAC_DMA_RCV_CFG_RING3_7_ADDRESS                              0x02ac
#define MAC_DMA_RCV_CFG_RING3_7_HW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_7_SW_MASK                              0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_7_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_RCV_CFG_RING3_7_SW_WRITE_MASK                        0x03fc03fc
#define MAC_DMA_RCV_CFG_RING3_7_RSTMASK                              0xffffffff
#define MAC_DMA_RCV_CFG_RING3_7_RESET                                0x00000000

// 0x02c0 (MAC_DMA_RCV_EN_ACT_0)
#define MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_MSB                         1
#define MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_LSB                         1
#define MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_MASK                        0x00000002
#define MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_GET(x)                      (((x) & MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_MASK) >> MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_LSB)
#define MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_SET(x)                      (((0 | (x)) << MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_LSB) & MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_MASK)
#define MAC_DMA_RCV_EN_ACT_0_RING_ACTIVE_RESET                       0
#define MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_MSB                         0
#define MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_LSB                         0
#define MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_MASK                        0x00000001
#define MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_GET(x)                      (((x) & MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_MASK) >> MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_LSB)
#define MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_SET(x)                      (((0 | (x)) << MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_LSB) & MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_MASK)
#define MAC_DMA_RCV_EN_ACT_0_RING_ENABLE_RESET                       0
#define MAC_DMA_RCV_EN_ACT_0_ADDRESS                                 0x02c0
#define MAC_DMA_RCV_EN_ACT_0_HW_MASK                                 0x00000003
#define MAC_DMA_RCV_EN_ACT_0_SW_MASK                                 0x00000003
#define MAC_DMA_RCV_EN_ACT_0_HW_WRITE_MASK                           0x00000002
#define MAC_DMA_RCV_EN_ACT_0_SW_WRITE_MASK                           0x00000001
#define MAC_DMA_RCV_EN_ACT_0_RSTMASK                                 0xffffffff
#define MAC_DMA_RCV_EN_ACT_0_RESET                                   0x00000000

// 0x02c4 (MAC_DMA_RCV_EN_ACT_1)
#define MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_MSB                         1
#define MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_LSB                         1
#define MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_MASK                        0x00000002
#define MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_GET(x)                      (((x) & MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_MASK) >> MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_LSB)
#define MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_SET(x)                      (((0 | (x)) << MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_LSB) & MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_MASK)
#define MAC_DMA_RCV_EN_ACT_1_RING_ACTIVE_RESET                       0
#define MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_MSB                         0
#define MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_LSB                         0
#define MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_MASK                        0x00000001
#define MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_GET(x)                      (((x) & MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_MASK) >> MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_LSB)
#define MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_SET(x)                      (((0 | (x)) << MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_LSB) & MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_MASK)
#define MAC_DMA_RCV_EN_ACT_1_RING_ENABLE_RESET                       0
#define MAC_DMA_RCV_EN_ACT_1_ADDRESS                                 0x02c4
#define MAC_DMA_RCV_EN_ACT_1_HW_MASK                                 0x00000003
#define MAC_DMA_RCV_EN_ACT_1_SW_MASK                                 0x00000003
#define MAC_DMA_RCV_EN_ACT_1_HW_WRITE_MASK                           0x00000002
#define MAC_DMA_RCV_EN_ACT_1_SW_WRITE_MASK                           0x00000001
#define MAC_DMA_RCV_EN_ACT_1_RSTMASK                                 0xffffffff
#define MAC_DMA_RCV_EN_ACT_1_RESET                                   0x00000000

// 0x02c8 (MAC_DMA_RCV_EN_ACT_2)
#define MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_MSB                         1
#define MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_LSB                         1
#define MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_MASK                        0x00000002
#define MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_GET(x)                      (((x) & MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_MASK) >> MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_LSB)
#define MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_SET(x)                      (((0 | (x)) << MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_LSB) & MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_MASK)
#define MAC_DMA_RCV_EN_ACT_2_RING_ACTIVE_RESET                       0
#define MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_MSB                         0
#define MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_LSB                         0
#define MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_MASK                        0x00000001
#define MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_GET(x)                      (((x) & MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_MASK) >> MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_LSB)
#define MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_SET(x)                      (((0 | (x)) << MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_LSB) & MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_MASK)
#define MAC_DMA_RCV_EN_ACT_2_RING_ENABLE_RESET                       0
#define MAC_DMA_RCV_EN_ACT_2_ADDRESS                                 0x02c8
#define MAC_DMA_RCV_EN_ACT_2_HW_MASK                                 0x00000003
#define MAC_DMA_RCV_EN_ACT_2_SW_MASK                                 0x00000003
#define MAC_DMA_RCV_EN_ACT_2_HW_WRITE_MASK                           0x00000002
#define MAC_DMA_RCV_EN_ACT_2_SW_WRITE_MASK                           0x00000001
#define MAC_DMA_RCV_EN_ACT_2_RSTMASK                                 0xffffffff
#define MAC_DMA_RCV_EN_ACT_2_RESET                                   0x00000000

// 0x02cc (MAC_DMA_RCV_EN_ACT_3)
#define MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_MSB                         1
#define MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_LSB                         1
#define MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_MASK                        0x00000002
#define MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_GET(x)                      (((x) & MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_MASK) >> MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_LSB)
#define MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_SET(x)                      (((0 | (x)) << MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_LSB) & MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_MASK)
#define MAC_DMA_RCV_EN_ACT_3_RING_ACTIVE_RESET                       0
#define MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_MSB                         0
#define MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_LSB                         0
#define MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_MASK                        0x00000001
#define MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_GET(x)                      (((x) & MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_MASK) >> MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_LSB)
#define MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_SET(x)                      (((0 | (x)) << MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_LSB) & MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_MASK)
#define MAC_DMA_RCV_EN_ACT_3_RING_ENABLE_RESET                       0
#define MAC_DMA_RCV_EN_ACT_3_ADDRESS                                 0x02cc
#define MAC_DMA_RCV_EN_ACT_3_HW_MASK                                 0x00000003
#define MAC_DMA_RCV_EN_ACT_3_SW_MASK                                 0x00000003
#define MAC_DMA_RCV_EN_ACT_3_HW_WRITE_MASK                           0x00000002
#define MAC_DMA_RCV_EN_ACT_3_SW_WRITE_MASK                           0x00000001
#define MAC_DMA_RCV_EN_ACT_3_RSTMASK                                 0xffffffff
#define MAC_DMA_RCV_EN_ACT_3_RESET                                   0x00000000

// 0x02d0 (MAC_DMA_RCV_CFG_MISC_0)
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_MSB              31
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_LSB              16
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_MASK             0xffff0000
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_GET(x)           (((x) & MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_MASK) >> MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_LSB)
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_SET(x)           (((0 | (x)) << MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_LSB) & MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_MASK)
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_RESET            128
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_MSB              15
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_LSB              0
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_MASK             0x0000ffff
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_GET(x)           (((x) & MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_MASK) >> MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_LSB)
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_SET(x)           (((0 | (x)) << MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_LSB) & MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_MASK)
#define MAC_DMA_RCV_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_RESET            128
#define MAC_DMA_RCV_CFG_MISC_0_ADDRESS                               0x02d0
#define MAC_DMA_RCV_CFG_MISC_0_HW_MASK                               0xffffffff
#define MAC_DMA_RCV_CFG_MISC_0_SW_MASK                               0xffffffff
#define MAC_DMA_RCV_CFG_MISC_0_HW_WRITE_MASK                         0x00000000
#define MAC_DMA_RCV_CFG_MISC_0_SW_WRITE_MASK                         0xffffffff
#define MAC_DMA_RCV_CFG_MISC_0_RSTMASK                               0xffffffff
#define MAC_DMA_RCV_CFG_MISC_0_RESET                                 0x00800080

// 0x02d4 (MAC_DMA_RCV_CFG_MISC_1)
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_MSB              31
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_LSB              16
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_MASK             0xffff0000
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_GET(x)           (((x) & MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_MASK) >> MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_LSB)
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_SET(x)           (((0 | (x)) << MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_LSB) & MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_MASK)
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_RESET            128
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_MSB              15
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_LSB              0
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_MASK             0x0000ffff
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_GET(x)           (((x) & MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_MASK) >> MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_LSB)
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_SET(x)           (((0 | (x)) << MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_LSB) & MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_MASK)
#define MAC_DMA_RCV_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_RESET            128
#define MAC_DMA_RCV_CFG_MISC_1_ADDRESS                               0x02d4
#define MAC_DMA_RCV_CFG_MISC_1_HW_MASK                               0xffffffff
#define MAC_DMA_RCV_CFG_MISC_1_SW_MASK                               0xffffffff
#define MAC_DMA_RCV_CFG_MISC_1_HW_WRITE_MASK                         0x00000000
#define MAC_DMA_RCV_CFG_MISC_1_SW_WRITE_MASK                         0xffffffff
#define MAC_DMA_RCV_CFG_MISC_1_RSTMASK                               0xffffffff
#define MAC_DMA_RCV_CFG_MISC_1_RESET                                 0x00800080

// 0x02d8 (MAC_DMA_RCV_CFG_MISC_2)
#define MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_MSB            0
#define MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_LSB            0
#define MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_MASK           0x00000001
#define MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_GET(x)         (((x) & MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_MASK) >> MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_LSB)
#define MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_SET(x)         (((0 | (x)) << MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_LSB) & MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_MASK)
#define MAC_DMA_RCV_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_RESET          0
#define MAC_DMA_RCV_CFG_MISC_2_ADDRESS                               0x02d8
#define MAC_DMA_RCV_CFG_MISC_2_HW_MASK                               0x00000001
#define MAC_DMA_RCV_CFG_MISC_2_SW_MASK                               0x00000001
#define MAC_DMA_RCV_CFG_MISC_2_HW_WRITE_MASK                         0x00000000
#define MAC_DMA_RCV_CFG_MISC_2_SW_WRITE_MASK                         0x00000001
#define MAC_DMA_RCV_CFG_MISC_2_RSTMASK                               0xffffffff
#define MAC_DMA_RCV_CFG_MISC_2_RESET                                 0x00000000

// 0x02e0 (MAC_DMA_RCV_IDX_0)
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_MSB                  31
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_LSB                  31
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_MASK                 0x80000000
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_GET(x)               (((x) & MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_MASK) >> MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_LSB)
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_SET(x)               (((0 | (x)) << MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_LSB) & MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_MASK)
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_OVERWRITE_RESET                0
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_MSB                            30
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_LSB                            16
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_MASK                           0x7fff0000
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_GET(x)                         (((x) & MAC_DMA_RCV_IDX_0_RING_HW_IDX_MASK) >> MAC_DMA_RCV_IDX_0_RING_HW_IDX_LSB)
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_SET(x)                         (((0 | (x)) << MAC_DMA_RCV_IDX_0_RING_HW_IDX_LSB) & MAC_DMA_RCV_IDX_0_RING_HW_IDX_MASK)
#define MAC_DMA_RCV_IDX_0_RING_HW_IDX_RESET                          0
#define MAC_DMA_RCV_IDX_0_RING_FW_IDX_MSB                            14
#define MAC_DMA_RCV_IDX_0_RING_FW_IDX_LSB                            0
#define MAC_DMA_RCV_IDX_0_RING_FW_IDX_MASK                           0x00007fff
#define MAC_DMA_RCV_IDX_0_RING_FW_IDX_GET(x)                         (((x) & MAC_DMA_RCV_IDX_0_RING_FW_IDX_MASK) >> MAC_DMA_RCV_IDX_0_RING_FW_IDX_LSB)
#define MAC_DMA_RCV_IDX_0_RING_FW_IDX_SET(x)                         (((0 | (x)) << MAC_DMA_RCV_IDX_0_RING_FW_IDX_LSB) & MAC_DMA_RCV_IDX_0_RING_FW_IDX_MASK)
#define MAC_DMA_RCV_IDX_0_RING_FW_IDX_RESET                          0
#define MAC_DMA_RCV_IDX_0_ADDRESS                                    0x02e0
#define MAC_DMA_RCV_IDX_0_HW_MASK                                    0xffff7fff
#define MAC_DMA_RCV_IDX_0_SW_MASK                                    0xffff7fff
#define MAC_DMA_RCV_IDX_0_HW_WRITE_MASK                              0x7fff0000
#define MAC_DMA_RCV_IDX_0_SW_WRITE_MASK                              0xffff7fff
#define MAC_DMA_RCV_IDX_0_RSTMASK                                    0xffffffff
#define MAC_DMA_RCV_IDX_0_RESET                                      0x00000000

// 0x02e4 (MAC_DMA_RCV_IDX_1)
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_MSB                  31
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_LSB                  31
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_MASK                 0x80000000
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_GET(x)               (((x) & MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_MASK) >> MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_LSB)
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_SET(x)               (((0 | (x)) << MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_LSB) & MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_MASK)
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_OVERWRITE_RESET                0
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_MSB                            30
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_LSB                            16
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_MASK                           0x7fff0000
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_GET(x)                         (((x) & MAC_DMA_RCV_IDX_1_RING_HW_IDX_MASK) >> MAC_DMA_RCV_IDX_1_RING_HW_IDX_LSB)
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_SET(x)                         (((0 | (x)) << MAC_DMA_RCV_IDX_1_RING_HW_IDX_LSB) & MAC_DMA_RCV_IDX_1_RING_HW_IDX_MASK)
#define MAC_DMA_RCV_IDX_1_RING_HW_IDX_RESET                          0
#define MAC_DMA_RCV_IDX_1_RING_FW_IDX_MSB                            14
#define MAC_DMA_RCV_IDX_1_RING_FW_IDX_LSB                            0
#define MAC_DMA_RCV_IDX_1_RING_FW_IDX_MASK                           0x00007fff
#define MAC_DMA_RCV_IDX_1_RING_FW_IDX_GET(x)                         (((x) & MAC_DMA_RCV_IDX_1_RING_FW_IDX_MASK) >> MAC_DMA_RCV_IDX_1_RING_FW_IDX_LSB)
#define MAC_DMA_RCV_IDX_1_RING_FW_IDX_SET(x)                         (((0 | (x)) << MAC_DMA_RCV_IDX_1_RING_FW_IDX_LSB) & MAC_DMA_RCV_IDX_1_RING_FW_IDX_MASK)
#define MAC_DMA_RCV_IDX_1_RING_FW_IDX_RESET                          0
#define MAC_DMA_RCV_IDX_1_ADDRESS                                    0x02e4
#define MAC_DMA_RCV_IDX_1_HW_MASK                                    0xffff7fff
#define MAC_DMA_RCV_IDX_1_SW_MASK                                    0xffff7fff
#define MAC_DMA_RCV_IDX_1_HW_WRITE_MASK                              0x7fff0000
#define MAC_DMA_RCV_IDX_1_SW_WRITE_MASK                              0xffff7fff
#define MAC_DMA_RCV_IDX_1_RSTMASK                                    0xffffffff
#define MAC_DMA_RCV_IDX_1_RESET                                      0x00000000

// 0x02e8 (MAC_DMA_RCV_IDX_2)
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_MSB                  31
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_LSB                  31
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_MASK                 0x80000000
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_GET(x)               (((x) & MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_MASK) >> MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_LSB)
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_SET(x)               (((0 | (x)) << MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_LSB) & MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_MASK)
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_OVERWRITE_RESET                0
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_MSB                            30
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_LSB                            16
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_MASK                           0x7fff0000
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_GET(x)                         (((x) & MAC_DMA_RCV_IDX_2_RING_HW_IDX_MASK) >> MAC_DMA_RCV_IDX_2_RING_HW_IDX_LSB)
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_SET(x)                         (((0 | (x)) << MAC_DMA_RCV_IDX_2_RING_HW_IDX_LSB) & MAC_DMA_RCV_IDX_2_RING_HW_IDX_MASK)
#define MAC_DMA_RCV_IDX_2_RING_HW_IDX_RESET                          0
#define MAC_DMA_RCV_IDX_2_RING_FW_IDX_MSB                            14
#define MAC_DMA_RCV_IDX_2_RING_FW_IDX_LSB                            0
#define MAC_DMA_RCV_IDX_2_RING_FW_IDX_MASK                           0x00007fff
#define MAC_DMA_RCV_IDX_2_RING_FW_IDX_GET(x)                         (((x) & MAC_DMA_RCV_IDX_2_RING_FW_IDX_MASK) >> MAC_DMA_RCV_IDX_2_RING_FW_IDX_LSB)
#define MAC_DMA_RCV_IDX_2_RING_FW_IDX_SET(x)                         (((0 | (x)) << MAC_DMA_RCV_IDX_2_RING_FW_IDX_LSB) & MAC_DMA_RCV_IDX_2_RING_FW_IDX_MASK)
#define MAC_DMA_RCV_IDX_2_RING_FW_IDX_RESET                          0
#define MAC_DMA_RCV_IDX_2_ADDRESS                                    0x02e8
#define MAC_DMA_RCV_IDX_2_HW_MASK                                    0xffff7fff
#define MAC_DMA_RCV_IDX_2_SW_MASK                                    0xffff7fff
#define MAC_DMA_RCV_IDX_2_HW_WRITE_MASK                              0x7fff0000
#define MAC_DMA_RCV_IDX_2_SW_WRITE_MASK                              0xffff7fff
#define MAC_DMA_RCV_IDX_2_RSTMASK                                    0xffffffff
#define MAC_DMA_RCV_IDX_2_RESET                                      0x00000000

// 0x02ec (MAC_DMA_RCV_IDX_3)
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_MSB                  31
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_LSB                  31
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_MASK                 0x80000000
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_GET(x)               (((x) & MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_MASK) >> MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_LSB)
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_SET(x)               (((0 | (x)) << MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_LSB) & MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_MASK)
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_OVERWRITE_RESET                0
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_MSB                            30
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_LSB                            16
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_MASK                           0x7fff0000
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_GET(x)                         (((x) & MAC_DMA_RCV_IDX_3_RING_HW_IDX_MASK) >> MAC_DMA_RCV_IDX_3_RING_HW_IDX_LSB)
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_SET(x)                         (((0 | (x)) << MAC_DMA_RCV_IDX_3_RING_HW_IDX_LSB) & MAC_DMA_RCV_IDX_3_RING_HW_IDX_MASK)
#define MAC_DMA_RCV_IDX_3_RING_HW_IDX_RESET                          0
#define MAC_DMA_RCV_IDX_3_RING_FW_IDX_MSB                            14
#define MAC_DMA_RCV_IDX_3_RING_FW_IDX_LSB                            0
#define MAC_DMA_RCV_IDX_3_RING_FW_IDX_MASK                           0x00007fff
#define MAC_DMA_RCV_IDX_3_RING_FW_IDX_GET(x)                         (((x) & MAC_DMA_RCV_IDX_3_RING_FW_IDX_MASK) >> MAC_DMA_RCV_IDX_3_RING_FW_IDX_LSB)
#define MAC_DMA_RCV_IDX_3_RING_FW_IDX_SET(x)                         (((0 | (x)) << MAC_DMA_RCV_IDX_3_RING_FW_IDX_LSB) & MAC_DMA_RCV_IDX_3_RING_FW_IDX_MASK)
#define MAC_DMA_RCV_IDX_3_RING_FW_IDX_RESET                          0
#define MAC_DMA_RCV_IDX_3_ADDRESS                                    0x02ec
#define MAC_DMA_RCV_IDX_3_HW_MASK                                    0xffff7fff
#define MAC_DMA_RCV_IDX_3_SW_MASK                                    0xffff7fff
#define MAC_DMA_RCV_IDX_3_HW_WRITE_MASK                              0x7fff0000
#define MAC_DMA_RCV_IDX_3_SW_WRITE_MASK                              0xffff7fff
#define MAC_DMA_RCV_IDX_3_RSTMASK                                    0xffffffff
#define MAC_DMA_RCV_IDX_3_RESET                                      0x00000000

// 0x02f0 (MAC_DMA_RCV_GLOBAL_RER)
#define MAC_DMA_RCV_GLOBAL_RER_ENABLE_MSB                            0
#define MAC_DMA_RCV_GLOBAL_RER_ENABLE_LSB                            0
#define MAC_DMA_RCV_GLOBAL_RER_ENABLE_MASK                           0x00000001
#define MAC_DMA_RCV_GLOBAL_RER_ENABLE_GET(x)                         (((x) & MAC_DMA_RCV_GLOBAL_RER_ENABLE_MASK) >> MAC_DMA_RCV_GLOBAL_RER_ENABLE_LSB)
#define MAC_DMA_RCV_GLOBAL_RER_ENABLE_SET(x)                         (((0 | (x)) << MAC_DMA_RCV_GLOBAL_RER_ENABLE_LSB) & MAC_DMA_RCV_GLOBAL_RER_ENABLE_MASK)
#define MAC_DMA_RCV_GLOBAL_RER_ENABLE_RESET                          1
#define MAC_DMA_RCV_GLOBAL_RER_ADDRESS                               0x02f0
#define MAC_DMA_RCV_GLOBAL_RER_HW_MASK                               0x00000001
#define MAC_DMA_RCV_GLOBAL_RER_SW_MASK                               0x00000001
#define MAC_DMA_RCV_GLOBAL_RER_HW_WRITE_MASK                         0x00000000
#define MAC_DMA_RCV_GLOBAL_RER_SW_WRITE_MASK                         0x00000001
#define MAC_DMA_RCV_GLOBAL_RER_RSTMASK                               0xffffffff
#define MAC_DMA_RCV_GLOBAL_RER_RESET                                 0x00000001

// 0x02fc (MAC_DMA_RCV_OBS_BUS)
#define MAC_DMA_RCV_OBS_BUS_VALUE_MSB                                31
#define MAC_DMA_RCV_OBS_BUS_VALUE_LSB                                0
#define MAC_DMA_RCV_OBS_BUS_VALUE_MASK                               0xffffffff
#define MAC_DMA_RCV_OBS_BUS_VALUE_GET(x)                             (((x) & MAC_DMA_RCV_OBS_BUS_VALUE_MASK) >> MAC_DMA_RCV_OBS_BUS_VALUE_LSB)
#define MAC_DMA_RCV_OBS_BUS_VALUE_SET(x)                             (((0 | (x)) << MAC_DMA_RCV_OBS_BUS_VALUE_LSB) & MAC_DMA_RCV_OBS_BUS_VALUE_MASK)
#define MAC_DMA_RCV_OBS_BUS_VALUE_RESET                              0
#define MAC_DMA_RCV_OBS_BUS_ADDRESS                                  0x02fc
#define MAC_DMA_RCV_OBS_BUS_HW_MASK                                  0xffffffff
#define MAC_DMA_RCV_OBS_BUS_SW_MASK                                  0xffffffff
#define MAC_DMA_RCV_OBS_BUS_HW_WRITE_MASK                            0xffffffff
#define MAC_DMA_RCV_OBS_BUS_SW_WRITE_MASK                            0x00000000
#define MAC_DMA_RCV_OBS_BUS_RSTMASK                                  0xffffffff
#define MAC_DMA_RCV_OBS_BUS_RESET                                    0x00000000

// 0x0300 (MAC_TRC)
#define MAC_TRC_OBS_BUS_SEL_MSB                                      11
#define MAC_TRC_OBS_BUS_SEL_LSB                                      10
#define MAC_TRC_OBS_BUS_SEL_MASK                                     0x00000c00
#define MAC_TRC_OBS_BUS_SEL_GET(x)                                   (((x) & MAC_TRC_OBS_BUS_SEL_MASK) >> MAC_TRC_OBS_BUS_SEL_LSB)
#define MAC_TRC_OBS_BUS_SEL_SET(x)                                   (((0 | (x)) << MAC_TRC_OBS_BUS_SEL_LSB) & MAC_TRC_OBS_BUS_SEL_MASK)
#define MAC_TRC_OBS_BUS_SEL_RESET                                    0
#define MAC_TRC_MAC_MODULE_SEL_MSB                                   9
#define MAC_TRC_MAC_MODULE_SEL_LSB                                   8
#define MAC_TRC_MAC_MODULE_SEL_MASK                                  0x00000300
#define MAC_TRC_MAC_MODULE_SEL_GET(x)                                (((x) & MAC_TRC_MAC_MODULE_SEL_MASK) >> MAC_TRC_MAC_MODULE_SEL_LSB)
#define MAC_TRC_MAC_MODULE_SEL_SET(x)                                (((0 | (x)) << MAC_TRC_MAC_MODULE_SEL_LSB) & MAC_TRC_MAC_MODULE_SEL_MASK)
#define MAC_TRC_MAC_MODULE_SEL_RESET                                 0
#define MAC_TRC_CPU_ACCESS_EN_VALUE_MSB                              4
#define MAC_TRC_CPU_ACCESS_EN_VALUE_LSB                              4
#define MAC_TRC_CPU_ACCESS_EN_VALUE_MASK                             0x00000010
#define MAC_TRC_CPU_ACCESS_EN_VALUE_GET(x)                           (((x) & MAC_TRC_CPU_ACCESS_EN_VALUE_MASK) >> MAC_TRC_CPU_ACCESS_EN_VALUE_LSB)
#define MAC_TRC_CPU_ACCESS_EN_VALUE_SET(x)                           (((0 | (x)) << MAC_TRC_CPU_ACCESS_EN_VALUE_LSB) & MAC_TRC_CPU_ACCESS_EN_VALUE_MASK)
#define MAC_TRC_CPU_ACCESS_EN_VALUE_RESET                            0
#define MAC_TRC_BUF_CFG_VALUE_MSB                                    1
#define MAC_TRC_BUF_CFG_VALUE_LSB                                    1
#define MAC_TRC_BUF_CFG_VALUE_MASK                                   0x00000002
#define MAC_TRC_BUF_CFG_VALUE_GET(x)                                 (((x) & MAC_TRC_BUF_CFG_VALUE_MASK) >> MAC_TRC_BUF_CFG_VALUE_LSB)
#define MAC_TRC_BUF_CFG_VALUE_SET(x)                                 (((0 | (x)) << MAC_TRC_BUF_CFG_VALUE_LSB) & MAC_TRC_BUF_CFG_VALUE_MASK)
#define MAC_TRC_BUF_CFG_VALUE_RESET                                  0
#define MAC_TRC_ENABLE_VALUE_MSB                                     0
#define MAC_TRC_ENABLE_VALUE_LSB                                     0
#define MAC_TRC_ENABLE_VALUE_MASK                                    0x00000001
#define MAC_TRC_ENABLE_VALUE_GET(x)                                  (((x) & MAC_TRC_ENABLE_VALUE_MASK) >> MAC_TRC_ENABLE_VALUE_LSB)
#define MAC_TRC_ENABLE_VALUE_SET(x)                                  (((0 | (x)) << MAC_TRC_ENABLE_VALUE_LSB) & MAC_TRC_ENABLE_VALUE_MASK)
#define MAC_TRC_ENABLE_VALUE_RESET                                   0
#define MAC_TRC_ADDRESS                                              0x0300
#define MAC_TRC_HW_MASK                                              0x00000f13
#define MAC_TRC_SW_MASK                                              0x00000f13
#define MAC_TRC_HW_WRITE_MASK                                        0x00000000
#define MAC_TRC_SW_WRITE_MASK                                        0x00000f13
#define MAC_TRC_RSTMASK                                              0xffffffff
#define MAC_TRC_RESET                                                0x00000000

// 0x0304 (MAC_TRC_BUF_INIT)
#define MAC_TRC_BUF_INIT_VALUE_MSB                                   0
#define MAC_TRC_BUF_INIT_VALUE_LSB                                   0
#define MAC_TRC_BUF_INIT_VALUE_MASK                                  0x00000001
#define MAC_TRC_BUF_INIT_VALUE_GET(x)                                (((x) & MAC_TRC_BUF_INIT_VALUE_MASK) >> MAC_TRC_BUF_INIT_VALUE_LSB)
#define MAC_TRC_BUF_INIT_VALUE_SET(x)                                (((0 | (x)) << MAC_TRC_BUF_INIT_VALUE_LSB) & MAC_TRC_BUF_INIT_VALUE_MASK)
#define MAC_TRC_BUF_INIT_VALUE_RESET                                 0
#define MAC_TRC_BUF_INIT_ADDRESS                                     0x0304
#define MAC_TRC_BUF_INIT_HW_MASK                                     0x00000001
#define MAC_TRC_BUF_INIT_SW_MASK                                     0x00000001
#define MAC_TRC_BUF_INIT_HW_WRITE_MASK                               0x00000000
#define MAC_TRC_BUF_INIT_SW_WRITE_MASK                               0x00000001
#define MAC_TRC_BUF_INIT_RSTMASK                                     0xffffffff
#define MAC_TRC_BUF_INIT_RESET                                       0x00000000

// 0x0308 (MAC_TRC_ADDR)
#define MAC_TRC_ADDR_END_VALUE_MSB                                   29
#define MAC_TRC_ADDR_END_VALUE_LSB                                   16
#define MAC_TRC_ADDR_END_VALUE_MASK                                  0x3fff0000
#define MAC_TRC_ADDR_END_VALUE_GET(x)                                (((x) & MAC_TRC_ADDR_END_VALUE_MASK) >> MAC_TRC_ADDR_END_VALUE_LSB)
#define MAC_TRC_ADDR_END_VALUE_SET(x)                                (((0 | (x)) << MAC_TRC_ADDR_END_VALUE_LSB) & MAC_TRC_ADDR_END_VALUE_MASK)
#define MAC_TRC_ADDR_END_VALUE_RESET                                 0
#define MAC_TRC_ADDR_START_VALUE_MSB                                 13
#define MAC_TRC_ADDR_START_VALUE_LSB                                 0
#define MAC_TRC_ADDR_START_VALUE_MASK                                0x00003fff
#define MAC_TRC_ADDR_START_VALUE_GET(x)                              (((x) & MAC_TRC_ADDR_START_VALUE_MASK) >> MAC_TRC_ADDR_START_VALUE_LSB)
#define MAC_TRC_ADDR_START_VALUE_SET(x)                              (((0 | (x)) << MAC_TRC_ADDR_START_VALUE_LSB) & MAC_TRC_ADDR_START_VALUE_MASK)
#define MAC_TRC_ADDR_START_VALUE_RESET                               0
#define MAC_TRC_ADDR_ADDRESS                                         0x0308
#define MAC_TRC_ADDR_HW_MASK                                         0x3fff3fff
#define MAC_TRC_ADDR_SW_MASK                                         0x3fff3fff
#define MAC_TRC_ADDR_HW_WRITE_MASK                                   0x00000000
#define MAC_TRC_ADDR_SW_WRITE_MASK                                   0x3fff3fff
#define MAC_TRC_ADDR_RSTMASK                                         0xffffffff
#define MAC_TRC_ADDR_RESET                                           0x00000000

// 0x030c (MAC_TRC_WFT_CAPTURE_CTRL)
#define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_MSB                           31
#define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_LSB                           0
#define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_MASK                          0xffffffff
#define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_GET(x)                        (((x) & MAC_TRC_WFT_CAPTURE_CTRL_VALUE_MASK) >> MAC_TRC_WFT_CAPTURE_CTRL_VALUE_LSB)
#define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_SET(x)                        (((0 | (x)) << MAC_TRC_WFT_CAPTURE_CTRL_VALUE_LSB) & MAC_TRC_WFT_CAPTURE_CTRL_VALUE_MASK)
#define MAC_TRC_WFT_CAPTURE_CTRL_VALUE_RESET                         0
#define MAC_TRC_WFT_CAPTURE_CTRL_ADDRESS                             0x030c
#define MAC_TRC_WFT_CAPTURE_CTRL_HW_MASK                             0xffffffff
#define MAC_TRC_WFT_CAPTURE_CTRL_SW_MASK                             0xffffffff
#define MAC_TRC_WFT_CAPTURE_CTRL_HW_WRITE_MASK                       0x00000000
#define MAC_TRC_WFT_CAPTURE_CTRL_SW_WRITE_MASK                       0xffffffff
#define MAC_TRC_WFT_CAPTURE_CTRL_RSTMASK                             0xffffffff
#define MAC_TRC_WFT_CAPTURE_CTRL_RESET                               0x00000000

// 0x0310 (MAC_TRC_WFT_STATE_CTRL)
#define MAC_TRC_WFT_STATE_CTRL_VALUE_MSB                             31
#define MAC_TRC_WFT_STATE_CTRL_VALUE_LSB                             0
#define MAC_TRC_WFT_STATE_CTRL_VALUE_MASK                            0xffffffff
#define MAC_TRC_WFT_STATE_CTRL_VALUE_GET(x)                          (((x) & MAC_TRC_WFT_STATE_CTRL_VALUE_MASK) >> MAC_TRC_WFT_STATE_CTRL_VALUE_LSB)
#define MAC_TRC_WFT_STATE_CTRL_VALUE_SET(x)                          (((0 | (x)) << MAC_TRC_WFT_STATE_CTRL_VALUE_LSB) & MAC_TRC_WFT_STATE_CTRL_VALUE_MASK)
#define MAC_TRC_WFT_STATE_CTRL_VALUE_RESET                           0
#define MAC_TRC_WFT_STATE_CTRL_ADDRESS                               0x0310
#define MAC_TRC_WFT_STATE_CTRL_HW_MASK                               0xffffffff
#define MAC_TRC_WFT_STATE_CTRL_SW_MASK                               0xffffffff
#define MAC_TRC_WFT_STATE_CTRL_HW_WRITE_MASK                         0x00000000
#define MAC_TRC_WFT_STATE_CTRL_SW_WRITE_MASK                         0xffffffff
#define MAC_TRC_WFT_STATE_CTRL_RSTMASK                               0xffffffff
#define MAC_TRC_WFT_STATE_CTRL_RESET                                 0x00000000

// 0x0314 (MAC_TRC_TS1_CAPTURE_CTRL)
#define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_MSB                           31
#define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_LSB                           0
#define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_MASK                          0xffffffff
#define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_GET(x)                        (((x) & MAC_TRC_TS1_CAPTURE_CTRL_VALUE_MASK) >> MAC_TRC_TS1_CAPTURE_CTRL_VALUE_LSB)
#define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_SET(x)                        (((0 | (x)) << MAC_TRC_TS1_CAPTURE_CTRL_VALUE_LSB) & MAC_TRC_TS1_CAPTURE_CTRL_VALUE_MASK)
#define MAC_TRC_TS1_CAPTURE_CTRL_VALUE_RESET                         0
#define MAC_TRC_TS1_CAPTURE_CTRL_ADDRESS                             0x0314
#define MAC_TRC_TS1_CAPTURE_CTRL_HW_MASK                             0xffffffff
#define MAC_TRC_TS1_CAPTURE_CTRL_SW_MASK                             0xffffffff
#define MAC_TRC_TS1_CAPTURE_CTRL_HW_WRITE_MASK                       0x00000000
#define MAC_TRC_TS1_CAPTURE_CTRL_SW_WRITE_MASK                       0xffffffff
#define MAC_TRC_TS1_CAPTURE_CTRL_RSTMASK                             0xffffffff
#define MAC_TRC_TS1_CAPTURE_CTRL_RESET                               0x00000000

// 0x0318 (MAC_TRC_TS1_STATE_CTRL)
#define MAC_TRC_TS1_STATE_CTRL_VALUE_MSB                             31
#define MAC_TRC_TS1_STATE_CTRL_VALUE_LSB                             0
#define MAC_TRC_TS1_STATE_CTRL_VALUE_MASK                            0xffffffff
#define MAC_TRC_TS1_STATE_CTRL_VALUE_GET(x)                          (((x) & MAC_TRC_TS1_STATE_CTRL_VALUE_MASK) >> MAC_TRC_TS1_STATE_CTRL_VALUE_LSB)
#define MAC_TRC_TS1_STATE_CTRL_VALUE_SET(x)                          (((0 | (x)) << MAC_TRC_TS1_STATE_CTRL_VALUE_LSB) & MAC_TRC_TS1_STATE_CTRL_VALUE_MASK)
#define MAC_TRC_TS1_STATE_CTRL_VALUE_RESET                           0
#define MAC_TRC_TS1_STATE_CTRL_ADDRESS                               0x0318
#define MAC_TRC_TS1_STATE_CTRL_HW_MASK                               0xffffffff
#define MAC_TRC_TS1_STATE_CTRL_SW_MASK                               0xffffffff
#define MAC_TRC_TS1_STATE_CTRL_HW_WRITE_MASK                         0x00000000
#define MAC_TRC_TS1_STATE_CTRL_SW_WRITE_MASK                         0xffffffff
#define MAC_TRC_TS1_STATE_CTRL_RSTMASK                               0xffffffff
#define MAC_TRC_TS1_STATE_CTRL_RESET                                 0x00000000

// 0x031c (MAC_TRC_TS1_TRIG_MASK)
#define MAC_TRC_TS1_TRIG_MASK_VALUE_MSB                              31
#define MAC_TRC_TS1_TRIG_MASK_VALUE_LSB                              0
#define MAC_TRC_TS1_TRIG_MASK_VALUE_MASK                             0xffffffff
#define MAC_TRC_TS1_TRIG_MASK_VALUE_GET(x)                           (((x) & MAC_TRC_TS1_TRIG_MASK_VALUE_MASK) >> MAC_TRC_TS1_TRIG_MASK_VALUE_LSB)
#define MAC_TRC_TS1_TRIG_MASK_VALUE_SET(x)                           (((0 | (x)) << MAC_TRC_TS1_TRIG_MASK_VALUE_LSB) & MAC_TRC_TS1_TRIG_MASK_VALUE_MASK)
#define MAC_TRC_TS1_TRIG_MASK_VALUE_RESET                            0
#define MAC_TRC_TS1_TRIG_MASK_ADDRESS                                0x031c
#define MAC_TRC_TS1_TRIG_MASK_HW_MASK                                0xffffffff
#define MAC_TRC_TS1_TRIG_MASK_SW_MASK                                0xffffffff
#define MAC_TRC_TS1_TRIG_MASK_HW_WRITE_MASK                          0x00000000
#define MAC_TRC_TS1_TRIG_MASK_SW_WRITE_MASK                          0xffffffff
#define MAC_TRC_TS1_TRIG_MASK_RSTMASK                                0xffffffff
#define MAC_TRC_TS1_TRIG_MASK_RESET                                  0x00000000

// 0x0320 (MAC_TRC_TS1_TRIG)
#define MAC_TRC_TS1_TRIG_VALUE_MSB                                   31
#define MAC_TRC_TS1_TRIG_VALUE_LSB                                   0
#define MAC_TRC_TS1_TRIG_VALUE_MASK                                  0xffffffff
#define MAC_TRC_TS1_TRIG_VALUE_GET(x)                                (((x) & MAC_TRC_TS1_TRIG_VALUE_MASK) >> MAC_TRC_TS1_TRIG_VALUE_LSB)
#define MAC_TRC_TS1_TRIG_VALUE_SET(x)                                (((0 | (x)) << MAC_TRC_TS1_TRIG_VALUE_LSB) & MAC_TRC_TS1_TRIG_VALUE_MASK)
#define MAC_TRC_TS1_TRIG_VALUE_RESET                                 0
#define MAC_TRC_TS1_TRIG_ADDRESS                                     0x0320
#define MAC_TRC_TS1_TRIG_HW_MASK                                     0xffffffff
#define MAC_TRC_TS1_TRIG_SW_MASK                                     0xffffffff
#define MAC_TRC_TS1_TRIG_HW_WRITE_MASK                               0x00000000
#define MAC_TRC_TS1_TRIG_SW_WRITE_MASK                               0xffffffff
#define MAC_TRC_TS1_TRIG_RSTMASK                                     0xffffffff
#define MAC_TRC_TS1_TRIG_RESET                                       0x00000000

// 0x0324 (MAC_TRC_TS2_CAPTURE_CTRL)
#define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_MSB                           31
#define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_LSB                           0
#define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_MASK                          0xffffffff
#define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_GET(x)                        (((x) & MAC_TRC_TS2_CAPTURE_CTRL_VALUE_MASK) >> MAC_TRC_TS2_CAPTURE_CTRL_VALUE_LSB)
#define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_SET(x)                        (((0 | (x)) << MAC_TRC_TS2_CAPTURE_CTRL_VALUE_LSB) & MAC_TRC_TS2_CAPTURE_CTRL_VALUE_MASK)
#define MAC_TRC_TS2_CAPTURE_CTRL_VALUE_RESET                         0
#define MAC_TRC_TS2_CAPTURE_CTRL_ADDRESS                             0x0324
#define MAC_TRC_TS2_CAPTURE_CTRL_HW_MASK                             0xffffffff
#define MAC_TRC_TS2_CAPTURE_CTRL_SW_MASK                             0xffffffff
#define MAC_TRC_TS2_CAPTURE_CTRL_HW_WRITE_MASK                       0x00000000
#define MAC_TRC_TS2_CAPTURE_CTRL_SW_WRITE_MASK                       0xffffffff
#define MAC_TRC_TS2_CAPTURE_CTRL_RSTMASK                             0xffffffff
#define MAC_TRC_TS2_CAPTURE_CTRL_RESET                               0x00000000

// 0x0328 (MAC_TRC_TS2_STATE_CTRL)
#define MAC_TRC_TS2_STATE_CTRL_VALUE_MSB                             31
#define MAC_TRC_TS2_STATE_CTRL_VALUE_LSB                             0
#define MAC_TRC_TS2_STATE_CTRL_VALUE_MASK                            0xffffffff
#define MAC_TRC_TS2_STATE_CTRL_VALUE_GET(x)                          (((x) & MAC_TRC_TS2_STATE_CTRL_VALUE_MASK) >> MAC_TRC_TS2_STATE_CTRL_VALUE_LSB)
#define MAC_TRC_TS2_STATE_CTRL_VALUE_SET(x)                          (((0 | (x)) << MAC_TRC_TS2_STATE_CTRL_VALUE_LSB) & MAC_TRC_TS2_STATE_CTRL_VALUE_MASK)
#define MAC_TRC_TS2_STATE_CTRL_VALUE_RESET                           0
#define MAC_TRC_TS2_STATE_CTRL_ADDRESS                               0x0328
#define MAC_TRC_TS2_STATE_CTRL_HW_MASK                               0xffffffff
#define MAC_TRC_TS2_STATE_CTRL_SW_MASK                               0xffffffff
#define MAC_TRC_TS2_STATE_CTRL_HW_WRITE_MASK                         0x00000000
#define MAC_TRC_TS2_STATE_CTRL_SW_WRITE_MASK                         0xffffffff
#define MAC_TRC_TS2_STATE_CTRL_RSTMASK                               0xffffffff
#define MAC_TRC_TS2_STATE_CTRL_RESET                                 0x00000000

// 0x032c (MAC_TRC_TS2_TRIG_MASK)
#define MAC_TRC_TS2_TRIG_MASK_VALUE_MSB                              31
#define MAC_TRC_TS2_TRIG_MASK_VALUE_LSB                              0
#define MAC_TRC_TS2_TRIG_MASK_VALUE_MASK                             0xffffffff
#define MAC_TRC_TS2_TRIG_MASK_VALUE_GET(x)                           (((x) & MAC_TRC_TS2_TRIG_MASK_VALUE_MASK) >> MAC_TRC_TS2_TRIG_MASK_VALUE_LSB)
#define MAC_TRC_TS2_TRIG_MASK_VALUE_SET(x)                           (((0 | (x)) << MAC_TRC_TS2_TRIG_MASK_VALUE_LSB) & MAC_TRC_TS2_TRIG_MASK_VALUE_MASK)
#define MAC_TRC_TS2_TRIG_MASK_VALUE_RESET                            0
#define MAC_TRC_TS2_TRIG_MASK_ADDRESS                                0x032c
#define MAC_TRC_TS2_TRIG_MASK_HW_MASK                                0xffffffff
#define MAC_TRC_TS2_TRIG_MASK_SW_MASK                                0xffffffff
#define MAC_TRC_TS2_TRIG_MASK_HW_WRITE_MASK                          0x00000000
#define MAC_TRC_TS2_TRIG_MASK_SW_WRITE_MASK                          0xffffffff
#define MAC_TRC_TS2_TRIG_MASK_RSTMASK                                0xffffffff
#define MAC_TRC_TS2_TRIG_MASK_RESET                                  0x00000000

// 0x0330 (MAC_TRC_TS2_TRIG)
#define MAC_TRC_TS2_TRIG_VALUE_MSB                                   31
#define MAC_TRC_TS2_TRIG_VALUE_LSB                                   0
#define MAC_TRC_TS2_TRIG_VALUE_MASK                                  0xffffffff
#define MAC_TRC_TS2_TRIG_VALUE_GET(x)                                (((x) & MAC_TRC_TS2_TRIG_VALUE_MASK) >> MAC_TRC_TS2_TRIG_VALUE_LSB)
#define MAC_TRC_TS2_TRIG_VALUE_SET(x)                                (((0 | (x)) << MAC_TRC_TS2_TRIG_VALUE_LSB) & MAC_TRC_TS2_TRIG_VALUE_MASK)
#define MAC_TRC_TS2_TRIG_VALUE_RESET                                 0
#define MAC_TRC_TS2_TRIG_ADDRESS                                     0x0330
#define MAC_TRC_TS2_TRIG_HW_MASK                                     0xffffffff
#define MAC_TRC_TS2_TRIG_SW_MASK                                     0xffffffff
#define MAC_TRC_TS2_TRIG_HW_WRITE_MASK                               0x00000000
#define MAC_TRC_TS2_TRIG_SW_WRITE_MASK                               0xffffffff
#define MAC_TRC_TS2_TRIG_RSTMASK                                     0xffffffff
#define MAC_TRC_TS2_TRIG_RESET                                       0x00000000

// 0x0334 (MAC_TRC_TS3_CAPTURE_CTRL)
#define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_MSB                           31
#define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_LSB                           0
#define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_MASK                          0xffffffff
#define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_GET(x)                        (((x) & MAC_TRC_TS3_CAPTURE_CTRL_VALUE_MASK) >> MAC_TRC_TS3_CAPTURE_CTRL_VALUE_LSB)
#define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_SET(x)                        (((0 | (x)) << MAC_TRC_TS3_CAPTURE_CTRL_VALUE_LSB) & MAC_TRC_TS3_CAPTURE_CTRL_VALUE_MASK)
#define MAC_TRC_TS3_CAPTURE_CTRL_VALUE_RESET                         0
#define MAC_TRC_TS3_CAPTURE_CTRL_ADDRESS                             0x0334
#define MAC_TRC_TS3_CAPTURE_CTRL_HW_MASK                             0xffffffff
#define MAC_TRC_TS3_CAPTURE_CTRL_SW_MASK                             0xffffffff
#define MAC_TRC_TS3_CAPTURE_CTRL_HW_WRITE_MASK                       0x00000000
#define MAC_TRC_TS3_CAPTURE_CTRL_SW_WRITE_MASK                       0xffffffff
#define MAC_TRC_TS3_CAPTURE_CTRL_RSTMASK                             0xffffffff
#define MAC_TRC_TS3_CAPTURE_CTRL_RESET                               0x00000000

// 0x0338 (MAC_TRC_TS3_STATE_CTRL)
#define MAC_TRC_TS3_STATE_CTRL_VALUE_MSB                             31
#define MAC_TRC_TS3_STATE_CTRL_VALUE_LSB                             0
#define MAC_TRC_TS3_STATE_CTRL_VALUE_MASK                            0xffffffff
#define MAC_TRC_TS3_STATE_CTRL_VALUE_GET(x)                          (((x) & MAC_TRC_TS3_STATE_CTRL_VALUE_MASK) >> MAC_TRC_TS3_STATE_CTRL_VALUE_LSB)
#define MAC_TRC_TS3_STATE_CTRL_VALUE_SET(x)                          (((0 | (x)) << MAC_TRC_TS3_STATE_CTRL_VALUE_LSB) & MAC_TRC_TS3_STATE_CTRL_VALUE_MASK)
#define MAC_TRC_TS3_STATE_CTRL_VALUE_RESET                           0
#define MAC_TRC_TS3_STATE_CTRL_ADDRESS                               0x0338
#define MAC_TRC_TS3_STATE_CTRL_HW_MASK                               0xffffffff
#define MAC_TRC_TS3_STATE_CTRL_SW_MASK                               0xffffffff
#define MAC_TRC_TS3_STATE_CTRL_HW_WRITE_MASK                         0x00000000
#define MAC_TRC_TS3_STATE_CTRL_SW_WRITE_MASK                         0xffffffff
#define MAC_TRC_TS3_STATE_CTRL_RSTMASK                               0xffffffff
#define MAC_TRC_TS3_STATE_CTRL_RESET                                 0x00000000

// 0x033c (MAC_TRC_TS3_TRIG_MASK)
#define MAC_TRC_TS3_TRIG_MASK_VALUE_MSB                              31
#define MAC_TRC_TS3_TRIG_MASK_VALUE_LSB                              0
#define MAC_TRC_TS3_TRIG_MASK_VALUE_MASK                             0xffffffff
#define MAC_TRC_TS3_TRIG_MASK_VALUE_GET(x)                           (((x) & MAC_TRC_TS3_TRIG_MASK_VALUE_MASK) >> MAC_TRC_TS3_TRIG_MASK_VALUE_LSB)
#define MAC_TRC_TS3_TRIG_MASK_VALUE_SET(x)                           (((0 | (x)) << MAC_TRC_TS3_TRIG_MASK_VALUE_LSB) & MAC_TRC_TS3_TRIG_MASK_VALUE_MASK)
#define MAC_TRC_TS3_TRIG_MASK_VALUE_RESET                            0
#define MAC_TRC_TS3_TRIG_MASK_ADDRESS                                0x033c
#define MAC_TRC_TS3_TRIG_MASK_HW_MASK                                0xffffffff
#define MAC_TRC_TS3_TRIG_MASK_SW_MASK                                0xffffffff
#define MAC_TRC_TS3_TRIG_MASK_HW_WRITE_MASK                          0x00000000
#define MAC_TRC_TS3_TRIG_MASK_SW_WRITE_MASK                          0xffffffff
#define MAC_TRC_TS3_TRIG_MASK_RSTMASK                                0xffffffff
#define MAC_TRC_TS3_TRIG_MASK_RESET                                  0x00000000

// 0x0340 (MAC_TRC_TS3_TRIG)
#define MAC_TRC_TS3_TRIG_VALUE_MSB                                   31
#define MAC_TRC_TS3_TRIG_VALUE_LSB                                   0
#define MAC_TRC_TS3_TRIG_VALUE_MASK                                  0xffffffff
#define MAC_TRC_TS3_TRIG_VALUE_GET(x)                                (((x) & MAC_TRC_TS3_TRIG_VALUE_MASK) >> MAC_TRC_TS3_TRIG_VALUE_LSB)
#define MAC_TRC_TS3_TRIG_VALUE_SET(x)                                (((0 | (x)) << MAC_TRC_TS3_TRIG_VALUE_LSB) & MAC_TRC_TS3_TRIG_VALUE_MASK)
#define MAC_TRC_TS3_TRIG_VALUE_RESET                                 0
#define MAC_TRC_TS3_TRIG_ADDRESS                                     0x0340
#define MAC_TRC_TS3_TRIG_HW_MASK                                     0xffffffff
#define MAC_TRC_TS3_TRIG_SW_MASK                                     0xffffffff
#define MAC_TRC_TS3_TRIG_HW_WRITE_MASK                               0x00000000
#define MAC_TRC_TS3_TRIG_SW_WRITE_MASK                               0xffffffff
#define MAC_TRC_TS3_TRIG_RSTMASK                                     0xffffffff
#define MAC_TRC_TS3_TRIG_RESET                                       0x00000000

// 0x0344 (MAC_TRC_TS4_CAPTURE_CTRL)
#define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_MSB                           31
#define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_LSB                           0
#define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_MASK                          0xffffffff
#define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_GET(x)                        (((x) & MAC_TRC_TS4_CAPTURE_CTRL_VALUE_MASK) >> MAC_TRC_TS4_CAPTURE_CTRL_VALUE_LSB)
#define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_SET(x)                        (((0 | (x)) << MAC_TRC_TS4_CAPTURE_CTRL_VALUE_LSB) & MAC_TRC_TS4_CAPTURE_CTRL_VALUE_MASK)
#define MAC_TRC_TS4_CAPTURE_CTRL_VALUE_RESET                         0
#define MAC_TRC_TS4_CAPTURE_CTRL_ADDRESS                             0x0344
#define MAC_TRC_TS4_CAPTURE_CTRL_HW_MASK                             0xffffffff
#define MAC_TRC_TS4_CAPTURE_CTRL_SW_MASK                             0xffffffff
#define MAC_TRC_TS4_CAPTURE_CTRL_HW_WRITE_MASK                       0x00000000
#define MAC_TRC_TS4_CAPTURE_CTRL_SW_WRITE_MASK                       0xffffffff
#define MAC_TRC_TS4_CAPTURE_CTRL_RSTMASK                             0xffffffff
#define MAC_TRC_TS4_CAPTURE_CTRL_RESET                               0x00000000

// 0x0348 (MAC_TRC_TS4_STATE_CTRL)
#define MAC_TRC_TS4_STATE_CTRL_VALUE_MSB                             31
#define MAC_TRC_TS4_STATE_CTRL_VALUE_LSB                             0
#define MAC_TRC_TS4_STATE_CTRL_VALUE_MASK                            0xffffffff
#define MAC_TRC_TS4_STATE_CTRL_VALUE_GET(x)                          (((x) & MAC_TRC_TS4_STATE_CTRL_VALUE_MASK) >> MAC_TRC_TS4_STATE_CTRL_VALUE_LSB)
#define MAC_TRC_TS4_STATE_CTRL_VALUE_SET(x)                          (((0 | (x)) << MAC_TRC_TS4_STATE_CTRL_VALUE_LSB) & MAC_TRC_TS4_STATE_CTRL_VALUE_MASK)
#define MAC_TRC_TS4_STATE_CTRL_VALUE_RESET                           0
#define MAC_TRC_TS4_STATE_CTRL_ADDRESS                               0x0348
#define MAC_TRC_TS4_STATE_CTRL_HW_MASK                               0xffffffff
#define MAC_TRC_TS4_STATE_CTRL_SW_MASK                               0xffffffff
#define MAC_TRC_TS4_STATE_CTRL_HW_WRITE_MASK                         0x00000000
#define MAC_TRC_TS4_STATE_CTRL_SW_WRITE_MASK                         0xffffffff
#define MAC_TRC_TS4_STATE_CTRL_RSTMASK                               0xffffffff
#define MAC_TRC_TS4_STATE_CTRL_RESET                                 0x00000000

// 0x034c (MAC_TRC_TS4_TRIG_MASK)
#define MAC_TRC_TS4_TRIG_MASK_VALUE_MSB                              31
#define MAC_TRC_TS4_TRIG_MASK_VALUE_LSB                              0
#define MAC_TRC_TS4_TRIG_MASK_VALUE_MASK                             0xffffffff
#define MAC_TRC_TS4_TRIG_MASK_VALUE_GET(x)                           (((x) & MAC_TRC_TS4_TRIG_MASK_VALUE_MASK) >> MAC_TRC_TS4_TRIG_MASK_VALUE_LSB)
#define MAC_TRC_TS4_TRIG_MASK_VALUE_SET(x)                           (((0 | (x)) << MAC_TRC_TS4_TRIG_MASK_VALUE_LSB) & MAC_TRC_TS4_TRIG_MASK_VALUE_MASK)
#define MAC_TRC_TS4_TRIG_MASK_VALUE_RESET                            0
#define MAC_TRC_TS4_TRIG_MASK_ADDRESS                                0x034c
#define MAC_TRC_TS4_TRIG_MASK_HW_MASK                                0xffffffff
#define MAC_TRC_TS4_TRIG_MASK_SW_MASK                                0xffffffff
#define MAC_TRC_TS4_TRIG_MASK_HW_WRITE_MASK                          0x00000000
#define MAC_TRC_TS4_TRIG_MASK_SW_WRITE_MASK                          0xffffffff
#define MAC_TRC_TS4_TRIG_MASK_RSTMASK                                0xffffffff
#define MAC_TRC_TS4_TRIG_MASK_RESET                                  0x00000000

// 0x0350 (MAC_TRC_TS4_TRIG)
#define MAC_TRC_TS4_TRIG_VALUE_MSB                                   31
#define MAC_TRC_TS4_TRIG_VALUE_LSB                                   0
#define MAC_TRC_TS4_TRIG_VALUE_MASK                                  0xffffffff
#define MAC_TRC_TS4_TRIG_VALUE_GET(x)                                (((x) & MAC_TRC_TS4_TRIG_VALUE_MASK) >> MAC_TRC_TS4_TRIG_VALUE_LSB)
#define MAC_TRC_TS4_TRIG_VALUE_SET(x)                                (((0 | (x)) << MAC_TRC_TS4_TRIG_VALUE_LSB) & MAC_TRC_TS4_TRIG_VALUE_MASK)
#define MAC_TRC_TS4_TRIG_VALUE_RESET                                 0
#define MAC_TRC_TS4_TRIG_ADDRESS                                     0x0350
#define MAC_TRC_TS4_TRIG_HW_MASK                                     0xffffffff
#define MAC_TRC_TS4_TRIG_SW_MASK                                     0xffffffff
#define MAC_TRC_TS4_TRIG_HW_WRITE_MASK                               0x00000000
#define MAC_TRC_TS4_TRIG_SW_WRITE_MASK                               0xffffffff
#define MAC_TRC_TS4_TRIG_RSTMASK                                     0xffffffff
#define MAC_TRC_TS4_TRIG_RESET                                       0x00000000

// 0x0354 (MAC_TRC_TS5_CAPTURE_CTRL)
#define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_MSB                           31
#define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_LSB                           0
#define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_MASK                          0xffffffff
#define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_GET(x)                        (((x) & MAC_TRC_TS5_CAPTURE_CTRL_VALUE_MASK) >> MAC_TRC_TS5_CAPTURE_CTRL_VALUE_LSB)
#define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_SET(x)                        (((0 | (x)) << MAC_TRC_TS5_CAPTURE_CTRL_VALUE_LSB) & MAC_TRC_TS5_CAPTURE_CTRL_VALUE_MASK)
#define MAC_TRC_TS5_CAPTURE_CTRL_VALUE_RESET                         0
#define MAC_TRC_TS5_CAPTURE_CTRL_ADDRESS                             0x0354
#define MAC_TRC_TS5_CAPTURE_CTRL_HW_MASK                             0xffffffff
#define MAC_TRC_TS5_CAPTURE_CTRL_SW_MASK                             0xffffffff
#define MAC_TRC_TS5_CAPTURE_CTRL_HW_WRITE_MASK                       0x00000000
#define MAC_TRC_TS5_CAPTURE_CTRL_SW_WRITE_MASK                       0xffffffff
#define MAC_TRC_TS5_CAPTURE_CTRL_RSTMASK                             0xffffffff
#define MAC_TRC_TS5_CAPTURE_CTRL_RESET                               0x00000000

// 0x0358 (MAC_TRC_TS5_STATE_CTRL)
#define MAC_TRC_TS5_STATE_CTRL_VALUE_MSB                             31
#define MAC_TRC_TS5_STATE_CTRL_VALUE_LSB                             0
#define MAC_TRC_TS5_STATE_CTRL_VALUE_MASK                            0xffffffff
#define MAC_TRC_TS5_STATE_CTRL_VALUE_GET(x)                          (((x) & MAC_TRC_TS5_STATE_CTRL_VALUE_MASK) >> MAC_TRC_TS5_STATE_CTRL_VALUE_LSB)
#define MAC_TRC_TS5_STATE_CTRL_VALUE_SET(x)                          (((0 | (x)) << MAC_TRC_TS5_STATE_CTRL_VALUE_LSB) & MAC_TRC_TS5_STATE_CTRL_VALUE_MASK)
#define MAC_TRC_TS5_STATE_CTRL_VALUE_RESET                           0
#define MAC_TRC_TS5_STATE_CTRL_ADDRESS                               0x0358
#define MAC_TRC_TS5_STATE_CTRL_HW_MASK                               0xffffffff
#define MAC_TRC_TS5_STATE_CTRL_SW_MASK                               0xffffffff
#define MAC_TRC_TS5_STATE_CTRL_HW_WRITE_MASK                         0x00000000
#define MAC_TRC_TS5_STATE_CTRL_SW_WRITE_MASK                         0xffffffff
#define MAC_TRC_TS5_STATE_CTRL_RSTMASK                               0xffffffff
#define MAC_TRC_TS5_STATE_CTRL_RESET                                 0x00000000

// 0x035c (MAC_TRC_TS5_TRIG_MASK)
#define MAC_TRC_TS5_TRIG_MASK_VALUE_MSB                              31
#define MAC_TRC_TS5_TRIG_MASK_VALUE_LSB                              0
#define MAC_TRC_TS5_TRIG_MASK_VALUE_MASK                             0xffffffff
#define MAC_TRC_TS5_TRIG_MASK_VALUE_GET(x)                           (((x) & MAC_TRC_TS5_TRIG_MASK_VALUE_MASK) >> MAC_TRC_TS5_TRIG_MASK_VALUE_LSB)
#define MAC_TRC_TS5_TRIG_MASK_VALUE_SET(x)                           (((0 | (x)) << MAC_TRC_TS5_TRIG_MASK_VALUE_LSB) & MAC_TRC_TS5_TRIG_MASK_VALUE_MASK)
#define MAC_TRC_TS5_TRIG_MASK_VALUE_RESET                            0
#define MAC_TRC_TS5_TRIG_MASK_ADDRESS                                0x035c
#define MAC_TRC_TS5_TRIG_MASK_HW_MASK                                0xffffffff
#define MAC_TRC_TS5_TRIG_MASK_SW_MASK                                0xffffffff
#define MAC_TRC_TS5_TRIG_MASK_HW_WRITE_MASK                          0x00000000
#define MAC_TRC_TS5_TRIG_MASK_SW_WRITE_MASK                          0xffffffff
#define MAC_TRC_TS5_TRIG_MASK_RSTMASK                                0xffffffff
#define MAC_TRC_TS5_TRIG_MASK_RESET                                  0x00000000

// 0x0360 (MAC_TRC_TS5_TRIG)
#define MAC_TRC_TS5_TRIG_VALUE_MSB                                   31
#define MAC_TRC_TS5_TRIG_VALUE_LSB                                   0
#define MAC_TRC_TS5_TRIG_VALUE_MASK                                  0xffffffff
#define MAC_TRC_TS5_TRIG_VALUE_GET(x)                                (((x) & MAC_TRC_TS5_TRIG_VALUE_MASK) >> MAC_TRC_TS5_TRIG_VALUE_LSB)
#define MAC_TRC_TS5_TRIG_VALUE_SET(x)                                (((0 | (x)) << MAC_TRC_TS5_TRIG_VALUE_LSB) & MAC_TRC_TS5_TRIG_VALUE_MASK)
#define MAC_TRC_TS5_TRIG_VALUE_RESET                                 0
#define MAC_TRC_TS5_TRIG_ADDRESS                                     0x0360
#define MAC_TRC_TS5_TRIG_HW_MASK                                     0xffffffff
#define MAC_TRC_TS5_TRIG_SW_MASK                                     0xffffffff
#define MAC_TRC_TS5_TRIG_HW_WRITE_MASK                               0x00000000
#define MAC_TRC_TS5_TRIG_SW_WRITE_MASK                               0xffffffff
#define MAC_TRC_TS5_TRIG_RSTMASK                                     0xffffffff
#define MAC_TRC_TS5_TRIG_RESET                                       0x00000000

// 0x0364 (MAC_TRC_CPU_ADDR)
#define MAC_TRC_CPU_ADDR_READ_VALUE_MSB                              31
#define MAC_TRC_CPU_ADDR_READ_VALUE_LSB                              0
#define MAC_TRC_CPU_ADDR_READ_VALUE_MASK                             0xffffffff
#define MAC_TRC_CPU_ADDR_READ_VALUE_GET(x)                           (((x) & MAC_TRC_CPU_ADDR_READ_VALUE_MASK) >> MAC_TRC_CPU_ADDR_READ_VALUE_LSB)
#define MAC_TRC_CPU_ADDR_READ_VALUE_SET(x)                           (((0 | (x)) << MAC_TRC_CPU_ADDR_READ_VALUE_LSB) & MAC_TRC_CPU_ADDR_READ_VALUE_MASK)
#define MAC_TRC_CPU_ADDR_READ_VALUE_RESET                            0
#define MAC_TRC_CPU_ADDR_ADDRESS                                     0x0364
#define MAC_TRC_CPU_ADDR_HW_MASK                                     0xffffffff
#define MAC_TRC_CPU_ADDR_SW_MASK                                     0xffffffff
#define MAC_TRC_CPU_ADDR_HW_WRITE_MASK                               0x00000000
#define MAC_TRC_CPU_ADDR_SW_WRITE_MASK                               0xffffffff
#define MAC_TRC_CPU_ADDR_RSTMASK                                     0xffffffff
#define MAC_TRC_CPU_ADDR_RESET                                       0x00000000

// 0x0368 (MAC_TRC_CPU_DATA)
#define MAC_TRC_CPU_DATA_VALUE_MSB                                   31
#define MAC_TRC_CPU_DATA_VALUE_LSB                                   0
#define MAC_TRC_CPU_DATA_VALUE_MASK                                  0xffffffff
#define MAC_TRC_CPU_DATA_VALUE_GET(x)                                (((x) & MAC_TRC_CPU_DATA_VALUE_MASK) >> MAC_TRC_CPU_DATA_VALUE_LSB)
#define MAC_TRC_CPU_DATA_VALUE_SET(x)                                (((0 | (x)) << MAC_TRC_CPU_DATA_VALUE_LSB) & MAC_TRC_CPU_DATA_VALUE_MASK)
#define MAC_TRC_CPU_DATA_VALUE_RESET                                 0
#define MAC_TRC_CPU_DATA_ADDRESS                                     0x0368
#define MAC_TRC_CPU_DATA_HW_MASK                                     0xffffffff
#define MAC_TRC_CPU_DATA_SW_MASK                                     0xffffffff
#define MAC_TRC_CPU_DATA_HW_WRITE_MASK                               0xffffffff
#define MAC_TRC_CPU_DATA_SW_WRITE_MASK                               0x00000000
#define MAC_TRC_CPU_DATA_RSTMASK                                     0xffffffff
#define MAC_TRC_CPU_DATA_RESET                                       0x00000000

// 0x036c (MAC_TRC_STATUS_0)
#define MAC_TRC_STATUS_0_BUF_INIT_DONE_MSB                           1
#define MAC_TRC_STATUS_0_BUF_INIT_DONE_LSB                           1
#define MAC_TRC_STATUS_0_BUF_INIT_DONE_MASK                          0x00000002
#define MAC_TRC_STATUS_0_BUF_INIT_DONE_GET(x)                        (((x) & MAC_TRC_STATUS_0_BUF_INIT_DONE_MASK) >> MAC_TRC_STATUS_0_BUF_INIT_DONE_LSB)
#define MAC_TRC_STATUS_0_BUF_INIT_DONE_SET(x)                        (((0 | (x)) << MAC_TRC_STATUS_0_BUF_INIT_DONE_LSB) & MAC_TRC_STATUS_0_BUF_INIT_DONE_MASK)
#define MAC_TRC_STATUS_0_BUF_INIT_DONE_RESET                         0
#define MAC_TRC_STATUS_0_BUF_FULL_MSB                                0
#define MAC_TRC_STATUS_0_BUF_FULL_LSB                                0
#define MAC_TRC_STATUS_0_BUF_FULL_MASK                               0x00000001
#define MAC_TRC_STATUS_0_BUF_FULL_GET(x)                             (((x) & MAC_TRC_STATUS_0_BUF_FULL_MASK) >> MAC_TRC_STATUS_0_BUF_FULL_LSB)
#define MAC_TRC_STATUS_0_BUF_FULL_SET(x)                             (((0 | (x)) << MAC_TRC_STATUS_0_BUF_FULL_LSB) & MAC_TRC_STATUS_0_BUF_FULL_MASK)
#define MAC_TRC_STATUS_0_BUF_FULL_RESET                              0
#define MAC_TRC_STATUS_0_ADDRESS                                     0x036c
#define MAC_TRC_STATUS_0_HW_MASK                                     0x00000003
#define MAC_TRC_STATUS_0_SW_MASK                                     0x00000003
#define MAC_TRC_STATUS_0_HW_WRITE_MASK                               0x00000003
#define MAC_TRC_STATUS_0_SW_WRITE_MASK                               0x00000000
#define MAC_TRC_STATUS_0_RSTMASK                                     0xffffffff
#define MAC_TRC_STATUS_0_RESET                                       0x00000000

// 0x0370 (MAC_TRC_STATUS_1)
#define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MSB                         29
#define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_LSB                         16
#define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MASK                        0x3fff0000
#define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_GET(x)                      (((x) & MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MASK) >> MAC_TRC_STATUS_1_BUF_RD_END_ADDR_LSB)
#define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_SET(x)                      (((0 | (x)) << MAC_TRC_STATUS_1_BUF_RD_END_ADDR_LSB) & MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MASK)
#define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_RESET                       0
#define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MSB                       13
#define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_LSB                       0
#define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MASK                      0x00003fff
#define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_GET(x)                    (((x) & MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MASK) >> MAC_TRC_STATUS_1_BUF_RD_START_ADDR_LSB)
#define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_SET(x)                    (((0 | (x)) << MAC_TRC_STATUS_1_BUF_RD_START_ADDR_LSB) & MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MASK)
#define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_RESET                     0
#define MAC_TRC_STATUS_1_ADDRESS                                     0x0370
#define MAC_TRC_STATUS_1_HW_MASK                                     0x3fff3fff
#define MAC_TRC_STATUS_1_SW_MASK                                     0x3fff3fff
#define MAC_TRC_STATUS_1_HW_WRITE_MASK                               0x3fff3fff
#define MAC_TRC_STATUS_1_SW_WRITE_MASK                               0x00000000
#define MAC_TRC_STATUS_1_RSTMASK                                     0xffffffff
#define MAC_TRC_STATUS_1_RESET                                       0x00000000

// 0x0374 (MAC_TRC_STATUS_2)
#define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MSB                        12
#define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_LSB                        8
#define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MASK                       0x00001f00
#define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_GET(x)                     (((x) & MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MASK) >> MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_LSB)
#define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_SET(x)                     (((0 | (x)) << MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_LSB) & MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MASK)
#define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_RESET                      0
#define MAC_TRC_STATUS_2_MAIN_CTL_STATE_MSB                          6
#define MAC_TRC_STATUS_2_MAIN_CTL_STATE_LSB                          4
#define MAC_TRC_STATUS_2_MAIN_CTL_STATE_MASK                         0x00000070
#define MAC_TRC_STATUS_2_MAIN_CTL_STATE_GET(x)                       (((x) & MAC_TRC_STATUS_2_MAIN_CTL_STATE_MASK) >> MAC_TRC_STATUS_2_MAIN_CTL_STATE_LSB)
#define MAC_TRC_STATUS_2_MAIN_CTL_STATE_SET(x)                       (((0 | (x)) << MAC_TRC_STATUS_2_MAIN_CTL_STATE_LSB) & MAC_TRC_STATUS_2_MAIN_CTL_STATE_MASK)
#define MAC_TRC_STATUS_2_MAIN_CTL_STATE_RESET                        0
#define MAC_TRC_STATUS_2_WRCTL_STATE_MSB                             2
#define MAC_TRC_STATUS_2_WRCTL_STATE_LSB                             0
#define MAC_TRC_STATUS_2_WRCTL_STATE_MASK                            0x00000007
#define MAC_TRC_STATUS_2_WRCTL_STATE_GET(x)                          (((x) & MAC_TRC_STATUS_2_WRCTL_STATE_MASK) >> MAC_TRC_STATUS_2_WRCTL_STATE_LSB)
#define MAC_TRC_STATUS_2_WRCTL_STATE_SET(x)                          (((0 | (x)) << MAC_TRC_STATUS_2_WRCTL_STATE_LSB) & MAC_TRC_STATUS_2_WRCTL_STATE_MASK)
#define MAC_TRC_STATUS_2_WRCTL_STATE_RESET                           0
#define MAC_TRC_STATUS_2_ADDRESS                                     0x0374
#define MAC_TRC_STATUS_2_HW_MASK                                     0x00001f77
#define MAC_TRC_STATUS_2_SW_MASK                                     0x00001f77
#define MAC_TRC_STATUS_2_HW_WRITE_MASK                               0x00001f77
#define MAC_TRC_STATUS_2_SW_WRITE_MASK                               0x00000000
#define MAC_TRC_STATUS_2_RSTMASK                                     0xffffffff
#define MAC_TRC_STATUS_2_RESET                                       0x00000000

// 0x0378 (MAC_TRC_STATUS_3)
#define MAC_TRC_STATUS_3_TRIG_SAMPLE_MSB                             29
#define MAC_TRC_STATUS_3_TRIG_SAMPLE_LSB                             0
#define MAC_TRC_STATUS_3_TRIG_SAMPLE_MASK                            0x3fffffff
#define MAC_TRC_STATUS_3_TRIG_SAMPLE_GET(x)                          (((x) & MAC_TRC_STATUS_3_TRIG_SAMPLE_MASK) >> MAC_TRC_STATUS_3_TRIG_SAMPLE_LSB)
#define MAC_TRC_STATUS_3_TRIG_SAMPLE_SET(x)                          (((0 | (x)) << MAC_TRC_STATUS_3_TRIG_SAMPLE_LSB) & MAC_TRC_STATUS_3_TRIG_SAMPLE_MASK)
#define MAC_TRC_STATUS_3_TRIG_SAMPLE_RESET                           0
#define MAC_TRC_STATUS_3_ADDRESS                                     0x0378
#define MAC_TRC_STATUS_3_HW_MASK                                     0x3fffffff
#define MAC_TRC_STATUS_3_SW_MASK                                     0x3fffffff
#define MAC_TRC_STATUS_3_HW_WRITE_MASK                               0x3fffffff
#define MAC_TRC_STATUS_3_SW_WRITE_MASK                               0x00000000
#define MAC_TRC_STATUS_3_RSTMASK                                     0xffffffff
#define MAC_TRC_STATUS_3_RESET                                       0x00000000

// 0x0380 (MAC_BB_OBS_BUS_SEL)
#define MAC_BB_OBS_BUS_SEL_VALUE_MSB                                 31
#define MAC_BB_OBS_BUS_SEL_VALUE_LSB                                 0
#define MAC_BB_OBS_BUS_SEL_VALUE_MASK                                0xffffffff
#define MAC_BB_OBS_BUS_SEL_VALUE_GET(x)                              (((x) & MAC_BB_OBS_BUS_SEL_VALUE_MASK) >> MAC_BB_OBS_BUS_SEL_VALUE_LSB)
#define MAC_BB_OBS_BUS_SEL_VALUE_SET(x)                              (((0 | (x)) << MAC_BB_OBS_BUS_SEL_VALUE_LSB) & MAC_BB_OBS_BUS_SEL_VALUE_MASK)
#define MAC_BB_OBS_BUS_SEL_VALUE_RESET                               0
#define MAC_BB_OBS_BUS_SEL_ADDRESS                                   0x0380
#define MAC_BB_OBS_BUS_SEL_HW_MASK                                   0xffffffff
#define MAC_BB_OBS_BUS_SEL_SW_MASK                                   0xffffffff
#define MAC_BB_OBS_BUS_SEL_HW_WRITE_MASK                             0x00000000
#define MAC_BB_OBS_BUS_SEL_SW_WRITE_MASK                             0xffffffff
#define MAC_BB_OBS_BUS_SEL_RSTMASK                                   0xffffffff
#define MAC_BB_OBS_BUS_SEL_RESET                                     0x00000000

// 0x0384 (MAC_DMA_OBS_MUX_CONTROL)
#define MAC_DMA_OBS_MUX_CONTROL_VALUE_MSB                            19
#define MAC_DMA_OBS_MUX_CONTROL_VALUE_LSB                            16
#define MAC_DMA_OBS_MUX_CONTROL_VALUE_MASK                           0x000f0000
#define MAC_DMA_OBS_MUX_CONTROL_VALUE_GET(x)                         (((x) & MAC_DMA_OBS_MUX_CONTROL_VALUE_MASK) >> MAC_DMA_OBS_MUX_CONTROL_VALUE_LSB)
#define MAC_DMA_OBS_MUX_CONTROL_VALUE_SET(x)                         (((0 | (x)) << MAC_DMA_OBS_MUX_CONTROL_VALUE_LSB) & MAC_DMA_OBS_MUX_CONTROL_VALUE_MASK)
#define MAC_DMA_OBS_MUX_CONTROL_VALUE_RESET                          0
#define MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_MSB                          15
#define MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_LSB                          12
#define MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_MASK                         0x0000f000
#define MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_GET(x)                       (((x) & MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_MASK) >> MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_LSB)
#define MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_SET(x)                       (((0 | (x)) << MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_LSB) & MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_MASK)
#define MAC_DMA_OBS_MUX_CONTROL_RCV_DMA_RESET                        0
#define MAC_DMA_OBS_MUX_CONTROL_QCU_MSB                              11
#define MAC_DMA_OBS_MUX_CONTROL_QCU_LSB                              8
#define MAC_DMA_OBS_MUX_CONTROL_QCU_MASK                             0x00000f00
#define MAC_DMA_OBS_MUX_CONTROL_QCU_GET(x)                           (((x) & MAC_DMA_OBS_MUX_CONTROL_QCU_MASK) >> MAC_DMA_OBS_MUX_CONTROL_QCU_LSB)
#define MAC_DMA_OBS_MUX_CONTROL_QCU_SET(x)                           (((0 | (x)) << MAC_DMA_OBS_MUX_CONTROL_QCU_LSB) & MAC_DMA_OBS_MUX_CONTROL_QCU_MASK)
#define MAC_DMA_OBS_MUX_CONTROL_QCU_RESET                            0
#define MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_MSB                          7
#define MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_LSB                          4
#define MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_MASK                         0x000000f0
#define MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_GET(x)                       (((x) & MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_MASK) >> MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_LSB)
#define MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_SET(x)                       (((0 | (x)) << MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_LSB) & MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_MASK)
#define MAC_DMA_OBS_MUX_CONTROL_AXI_ARB_RESET                        0
#define MAC_DMA_OBS_MUX_CONTROL_DCU_MSB                              3
#define MAC_DMA_OBS_MUX_CONTROL_DCU_LSB                              0
#define MAC_DMA_OBS_MUX_CONTROL_DCU_MASK                             0x0000000f
#define MAC_DMA_OBS_MUX_CONTROL_DCU_GET(x)                           (((x) & MAC_DMA_OBS_MUX_CONTROL_DCU_MASK) >> MAC_DMA_OBS_MUX_CONTROL_DCU_LSB)
#define MAC_DMA_OBS_MUX_CONTROL_DCU_SET(x)                           (((0 | (x)) << MAC_DMA_OBS_MUX_CONTROL_DCU_LSB) & MAC_DMA_OBS_MUX_CONTROL_DCU_MASK)
#define MAC_DMA_OBS_MUX_CONTROL_DCU_RESET                            0
#define MAC_DMA_OBS_MUX_CONTROL_ADDRESS                              0x0384
#define MAC_DMA_OBS_MUX_CONTROL_HW_MASK                              0x000fffff
#define MAC_DMA_OBS_MUX_CONTROL_SW_MASK                              0x000fffff
#define MAC_DMA_OBS_MUX_CONTROL_HW_WRITE_MASK                        0x00000000
#define MAC_DMA_OBS_MUX_CONTROL_SW_WRITE_MASK                        0x000fffff
#define MAC_DMA_OBS_MUX_CONTROL_RSTMASK                              0xffffffff
#define MAC_DMA_OBS_MUX_CONTROL_RESET                                0x00000000

// 0x0388 (MAC_OLE_OBS_MUX_CONTROL)
#define MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_MSB                         3
#define MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_LSB                         3
#define MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_MASK                        0x00000008
#define MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_GET(x)                      (((x) & MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_MASK) >> MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_LSB)
#define MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_SET(x)                      (((0 | (x)) << MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_LSB) & MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_MASK)
#define MAC_OLE_OBS_MUX_CONTROL_DATA_SEL_RESET                       0
#define MAC_OLE_OBS_MUX_CONTROL_SEL_MSB                              2
#define MAC_OLE_OBS_MUX_CONTROL_SEL_LSB                              0
#define MAC_OLE_OBS_MUX_CONTROL_SEL_MASK                             0x00000007
#define MAC_OLE_OBS_MUX_CONTROL_SEL_GET(x)                           (((x) & MAC_OLE_OBS_MUX_CONTROL_SEL_MASK) >> MAC_OLE_OBS_MUX_CONTROL_SEL_LSB)
#define MAC_OLE_OBS_MUX_CONTROL_SEL_SET(x)                           (((0 | (x)) << MAC_OLE_OBS_MUX_CONTROL_SEL_LSB) & MAC_OLE_OBS_MUX_CONTROL_SEL_MASK)
#define MAC_OLE_OBS_MUX_CONTROL_SEL_RESET                            0
#define MAC_OLE_OBS_MUX_CONTROL_ADDRESS                              0x0388
#define MAC_OLE_OBS_MUX_CONTROL_HW_MASK                              0x0000000f
#define MAC_OLE_OBS_MUX_CONTROL_SW_MASK                              0x0000000f
#define MAC_OLE_OBS_MUX_CONTROL_HW_WRITE_MASK                        0x00000000
#define MAC_OLE_OBS_MUX_CONTROL_SW_WRITE_MASK                        0x0000000f
#define MAC_OLE_OBS_MUX_CONTROL_RSTMASK                              0xffffffff
#define MAC_OLE_OBS_MUX_CONTROL_RESET                                0x00000000

// 0x038c (MAC_PCU_OBS_MUX_CONTROL)
#define MAC_PCU_OBS_MUX_CONTROL_VALUE_MSB                            19
#define MAC_PCU_OBS_MUX_CONTROL_VALUE_LSB                            16
#define MAC_PCU_OBS_MUX_CONTROL_VALUE_MASK                           0x000f0000
#define MAC_PCU_OBS_MUX_CONTROL_VALUE_GET(x)                         (((x) & MAC_PCU_OBS_MUX_CONTROL_VALUE_MASK) >> MAC_PCU_OBS_MUX_CONTROL_VALUE_LSB)
#define MAC_PCU_OBS_MUX_CONTROL_VALUE_SET(x)                         (((0 | (x)) << MAC_PCU_OBS_MUX_CONTROL_VALUE_LSB) & MAC_PCU_OBS_MUX_CONTROL_VALUE_MASK)
#define MAC_PCU_OBS_MUX_CONTROL_VALUE_RESET                          0
#define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_MSB                       11
#define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_LSB                       8
#define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_MASK                      0x00000f00
#define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_GET(x)                    (((x) & MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_MASK) >> MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_LSB)
#define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_SET(x)                    (((0 | (x)) << MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_LSB) & MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_MASK)
#define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_TLV_RESET                     0
#define MAC_PCU_OBS_MUX_CONTROL_PCU_RX_MSB                           7
#define MAC_PCU_OBS_MUX_CONTROL_PCU_RX_LSB                           4
#define MAC_PCU_OBS_MUX_CONTROL_PCU_RX_MASK                          0x000000f0
#define MAC_PCU_OBS_MUX_CONTROL_PCU_RX_GET(x)                        (((x) & MAC_PCU_OBS_MUX_CONTROL_PCU_RX_MASK) >> MAC_PCU_OBS_MUX_CONTROL_PCU_RX_LSB)
#define MAC_PCU_OBS_MUX_CONTROL_PCU_RX_SET(x)                        (((0 | (x)) << MAC_PCU_OBS_MUX_CONTROL_PCU_RX_LSB) & MAC_PCU_OBS_MUX_CONTROL_PCU_RX_MASK)
#define MAC_PCU_OBS_MUX_CONTROL_PCU_RX_RESET                         0
#define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_MSB                           3
#define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_LSB                           0
#define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_MASK                          0x0000000f
#define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_GET(x)                        (((x) & MAC_PCU_OBS_MUX_CONTROL_PCU_TX_MASK) >> MAC_PCU_OBS_MUX_CONTROL_PCU_TX_LSB)
#define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_SET(x)                        (((0 | (x)) << MAC_PCU_OBS_MUX_CONTROL_PCU_TX_LSB) & MAC_PCU_OBS_MUX_CONTROL_PCU_TX_MASK)
#define MAC_PCU_OBS_MUX_CONTROL_PCU_TX_RESET                         0
#define MAC_PCU_OBS_MUX_CONTROL_ADDRESS                              0x038c
#define MAC_PCU_OBS_MUX_CONTROL_HW_MASK                              0x000f0fff
#define MAC_PCU_OBS_MUX_CONTROL_SW_MASK                              0x000f0fff
#define MAC_PCU_OBS_MUX_CONTROL_HW_WRITE_MASK                        0x00000000
#define MAC_PCU_OBS_MUX_CONTROL_SW_WRITE_MASK                        0x000f0fff
#define MAC_PCU_OBS_MUX_CONTROL_RSTMASK                              0xffffffff
#define MAC_PCU_OBS_MUX_CONTROL_RESET                                0x00000000


#endif /* _MAC_DMA_REG_H_ */
