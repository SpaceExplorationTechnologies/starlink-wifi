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

#ifndef __MAC_DMA_REG_SW_H
#define __MAC_DMA_REG_SW_H
// THIS IS A SOFTWARE WRAPPER HEADER FILE
#include "../../hw/mac_dma_reg.h"
#include "../../hw/mac_qcu_reg.h"
#include "../../hw/mac_dcu_reg.h"

/* Primary Interrupt Status Register */
#define MAC_DMA_ISR_ADDRESS                                MAC_DMA_ISR_P_ADDRESS
#define MAC_DMA_ISR_RING_LWM_MASK                          0x00000001 // At least one RX ring running below water mark
#define MAC_DMA_ISR_RXERR_MASK                             0x00000002 // Receive error interrupt
#define MAC_DMA_ISR_UNUSED_2                               0x00000004 // Unused
#define MAC_DMA_ISR_UNUSED_3                               0x00000008 // Unused
#define MAC_DMA_ISR_UNUSED_4                               0x00000010 // Unused
#define MAC_DMA_ISR_RXORN_MASK                             0x00000020 // Receive FIFO overrun interrupt
#define MAC_DMA_ISR_UNUSED_6                               0x00000040 // Unused
#define MAC_DMA_ISR_BTINT_MASK                             0x00000080 // BT interrupt
#define MAC_DMA_ISR_TXERR_MASK                             0x00000100 // Transmit error interrupt
#define MAC_DMA_ISR_TXNOPKT_MASK                           0x00000200 // No frame transmitted interrupt
#define MAC_DMA_ISR_TXEOL_MASK                             0x00000400 // Transmit descriptor empty interrupt
#define MAC_DMA_ISR_TXURN_MASK                             0x00000800 // Transmit FIFO underrun interrupt
#define MAC_DMA_ISR_MIB_MASK                               0x00001000 // MIB interrupt - see MIBC
#define MAC_DMA_ISR_SWI_MASK                               0x00002000 // Software interrupt
#define MAC_DMA_ISR_UNUSED_14                              0x00004000 // Unused
#define MAC_DMA_ISR_UNUSED_15                              0x00008000 // Unused
#define MAC_DMA_ISR_SWBA_MASK                              0x00010000 // Software beacon alert interrupt
#define MAC_DMA_ISR_BRSSI_MASK                             0x00020000 // Beacon threshold interrupt
#define MAC_DMA_ISR_BMISS_MASK                             0x00040000 // Beacon missed interrupt
#define MAC_DMA_ISR_UNUSED_19                              0x00080000 // Unused
#define MAC_DMA_ISR_BNR_MASK                               0x00100000 // Beacon not ready interrupt
#define MAC_DMA_ISR_RXINT_MASK                             0x00200000 // Rx interrupt directly from PCU
#define MAC_DMA_ISR_UNUSED_22                              0x00400000 // Unused
#define MAC_DMA_ISR_BCNMISC_MASK                           0x00800000 // CST, GTT, TIM, CABEND, DTIMSYNC, BCNTO, CABTO,
// TSFOOR, DTIM, and TBTT_TIME bits bits from ISR_S2
#define MAC_DMA_ISR_TIM_MASK                               0x00800000 // TIM interrupt
#define MAC_DMA_ISR_UNUSED_24                              0x01000000 // Unused
#define MAC_DMA_ISR_QCBROVF_MASK                           0x02000000 // QCU CBR overflow interrupt
#define MAC_DMA_ISR_QCBRURN_MASK                           0x04000000 // QCU CBR underrun interrupt
#define MAC_DMA_ISR_QTRIG_MASK                             0x08000000 // QCU scheduling trigger interrupt
#define MAC_DMA_ISR_TIMER_MASK                             0x10000000 // OR of generic timer bits in ISR 5
#define MAC_DMA_ISR_UNUSED_29                              0x20000000 // Unused 
#define MAC_DMA_ISR_UNUSED_30                              0x40000000 // Unused 
#define MAC_DMA_ISR_UNUSED_31                              0x80000000 // Unused

/* MAC TXRX interrupt status register */
/* The HW defn provides the bit functionality */
#define MAC_DMA_TXRX_ISR_TXOK_MASK                         MAC_DMA_TXRX_IMR_TXOK_MASK
#define MAC_DMA_TXRX_ISR_TXOK_LSB                          MAC_DMA_TXRX_IMR_TXOK_LSB

/* MAC Secondary interrupt status register 1 */
#define MAC_DMA_ISR_S1_QCU_TXERR_MASK                      0x000003FF // Mask for TXERR (QCU 0-9)
#define MAC_DMA_ISR_S1_QCU_TXERR_LSB                       0          // Shift for TXERR (QCU 0-9)
#define MAC_DMA_ISR_S1_QCU_TXEOL_MASK                      0x03FF0000 // Mask for TXEOL (QCU 0-9)
#define MAC_DMA_ISR_S1_QCU_TXEOL_LSB                       16         // Shift for TXEOL (QCU 0-9)

/* MAC Secondary interrupt status register 2 */
#define MAC_DMA_ISR_S2_QCU_TXURN_MASK                      0x000003FF // Mask for TXURN (QCU 0-9)
#define MAC_DMA_ISR_S2_QCU_TXURN_LSB                       0          // Shift for TXURN (QCU 0-9)
#define MAC_DMA_ISR_S2_TDMA_START_ERR_MASK                 0x00000400 // TDMA start time error interrupt
#define MAC_DMA_ISR_S2_TDMA_TX_AP_PULSE_MASK               0x00000800 // TDMA Tx AP SYNC PULSE
#define MAC_DMA_ISR_S2_RX_PTR_BAD_MASK                     0x00001000 // If PCU RX FIFO read pointer crosses PCU RX FIFO write pointer
#define MAC_DMA_ISR_S2_TIM2_MASK                           0x00002000 // TIM2
#define MAC_DMA_ISR_S2_CAB2END_MASK                        0x00004000 // CAB2END
#define MAC_DMA_ISR_S2_DTIM2SYNC_MASK                      0x00008000 // DTIM2SYNC
#define MAC_DMA_ISR_S2_BCN2TO_MASK                         0x00010000 // BCN2TO
#define MAC_DMA_ISR_S2_CAB2TO_MASK                         0x00020000 // CAB2TO
#define MAC_DMA_ISR_S2_DTIM2_MASK                          0x00040000 // DTIM2
#define MAC_DMA_ISR_S2_TSF2OOR_MASK                        0x00080000 // Rx TSF2 out of range
#define MAC_DMA_ISR_S2_TBTT2_TIME_MASK                     0x00100000 // TBTT2-referenced timer
#define MAC_DMA_ISR_S2_CST_MASK                            0x00200000 // Carrier sense timeout
#define MAC_DMA_ISR_S2_GTT_MASK                            0x00400000 // Global transmit timeout
#define MAC_DMA_ISR_S2_TIM_MASK                            0x00800000 // TIM
#define MAC_DMA_ISR_S2_CABEND_MASK                         0x01000000 // CABEND
#define MAC_DMA_ISR_S2_DTIMSYNC_MASK                       0x02000000 // DTIMSYNC
#define MAC_DMA_ISR_S2_BCNTO_MASK                          0x04000000 // BCNTO
#define MAC_DMA_ISR_S2_CABTO_MASK                          0x08000000 // CABTO
#define MAC_DMA_ISR_S2_DTIM_MASK                           0x10000000 // DTIM
#define MAC_DMA_ISR_S2_TSFOOR_MASK                         0x20000000 // Rx TSF out of range
#define MAC_DMA_ISR_S2_TBTT_TIME_MASK                      0x40000000 // TBTT-referenced timer

/* MAC Secondary interrupt status register 3 */
#define MAC_DMA_ISR_S3_QCU_QCBROVF_MASK                    0x000003FF // Mask for QCBROVF (QCU 0-9)
#define MAC_DMA_ISR_S3_RX_LP_Q_OVF_MASK                    0x00004000 // Rxdp  LPQ overflow
#define MAC_DMA_ISR_S3_RX_HP_Q_OVF_MASK                    0x00008000 // Rxdp  HPQ overflow
#define MAC_DMA_ISR_S3_QCU_QCBRURN_MASK                    0x03FF0000 // Mask for QCBRURN (QCU 0-9)
#define MAC_DMA_ISR_S3_BRSSI_LO_MASK                       0x04000000 // RSSI HI of a beacon threshold 
#define MAC_DMA_ISR_S3_BRSSI_HI_MASK                       0x08000000 // RSSI LO of a beacon threshold 
#define MAC_DMA_ISR_S3_BRSSI_LO2_MASK                      0x10000000 // RSSI HI2 of a beacon threshold 
#define MAC_DMA_ISR_S3_BRSSI_HI2_MASK                      0x20000000 // RSSI LO2 of a beacon threshold
#define MAC_DMA_ISR_S3_BMISS_MASK                          0x40000000 // Beacon miss 
#define MAC_DMA_ISR_S3_BMISS2_MASK                         0x80000000 // Beacon miss2

/* MAC Secondary interrupt status register 4 */
#define MAC_DMA_ISR_S4_QCU_QTRIG_MASK                      0x000003FF // Mask for QTRIG (QCU 0-9)

/* MAC Secondary interrupt status register 5 */
#define MAC_DMA_ISR_S5_TBTT_TIMER_TRIGGER_MASK             0x00000001
#define MAC_DMA_ISR_S5_DBA_TIMER_TRIGGER_MASK              0x00000002
#define MAC_DMA_ISR_S5_SBA_TIMER_TRIGGER_MASK              0x00000004
#define MAC_DMA_ISR_S5_HCF_TIMER_TRIGGER_MASK              0x00000008
#define MAC_DMA_ISR_S5_TIM_TIMER_TRIGGER_MASK              0x00000010
#define MAC_DMA_ISR_S5_DTIM_TIMER_TRIGGER_MASK             0x00000020
#define MAC_DMA_ISR_S5_QUIET_TIMER_TRIGGER_MASK            0x00000040
#define MAC_DMA_ISR_S5_NDP_TIMER_TRIGGER_MASK              0x00000080
#define MAC_DMA_ISR_S5_GENERIC_TIMER2_TRIGGER_MASK         0x0000FF00
#define MAC_DMA_ISR_S5_GENERIC_TIMER2_TRIGGER_LSB          8
#define MAC_DMA_ISR_S5_GENERIC_TIMER2_TRIGGER(_i)          (0x00000100 << (_i))
#define MAC_DMA_ISR_S5_TIMER_OVERFLOW_MASK                 0x00010000
#define MAC_DMA_ISR_S5_DBA_TIMER_THRESHOLD_MASK            0x00020000
#define MAC_DMA_ISR_S5_SBA_TIMER_THRESHOLD_MASK            0x00040000
#define MAC_DMA_ISR_S5_HCF_TIMER_THRESHOLD_MASK            0x00080000
#define MAC_DMA_ISR_S5_TIM_TIMER_THRESHOLD_MASK            0x00100000
#define MAC_DMA_ISR_S5_DTIM_TIMER_THRESHOLD_MASK           0x00200000
#define MAC_DMA_ISR_S5_QUIET_TIMER_THRESHOLD_MASK          0x00400000
#define MAC_DMA_ISR_S5_NDP_TIMER_THRESHOLD_MASK            0x00800000
#define MAC_DMA_ISR_S5_GENERIC_TIMER2_THRESHOLD_MASK       0xFF000000
#define MAC_DMA_ISR_S5_GENERIC_TIMER2_THRESHOLD_LSB        24
#define MAC_DMA_ISR_S5_GENERIC_TIMER2_THRESHOLD(_i)        (0x01000000 << (_i))

#define MAC_DMA_IMR_MASK_MSB                               MAC_DMA_IMR_P_MASK_MSB    
#define MAC_DMA_IMR_MASK_LSB                               MAC_DMA_IMR_P_MASK_LSB   
#define MAC_DMA_IMR_MASK_MASK                              MAC_DMA_IMR_P_MASK_MASK  
#define MAC_DMA_IMR_MASK_GET(x)                            MAC_DMA_IMR_P_MASK_GET(x)
#define MAC_DMA_IMR_MASK_SET(x)                            MAC_DMA_IMR_P_MASK_SET(x)
#define MAC_DMA_IMR_ADDRESS                                MAC_DMA_IMR_P_ADDRESS    

/* Primary Interrupt mask Register */
#define MAC_DMA_IMR_RING_LWM_MASK                        MAC_DMA_ISR_RING_LWM_MASK
#define MAC_DMA_IMR_RXERR_MASK                           MAC_DMA_ISR_RXERR_MASK
#define MAC_DMA_IMR_UNUSED_2                             MAC_DMA_ISR_UNUSED_2
#define MAC_DMA_IMR_UNUSED_3                             MAC_DMA_ISR_UNUSED_3
#define MAC_DMA_IMR_UNUSED_4                             MAC_DMA_ISR_UNUSED_4
#define MAC_DMA_IMR_RXORN_MASK                           MAC_DMA_ISR_RXORN_MASK
#define MAC_DMA_IMR_UNUSED_6                             MAC_DMA_ISR_UNUSED_6
#define MAC_DMA_IMR_BTINT_MASK                           MAC_DMA_ISR_BTINT_MASK
#define MAC_DMA_IMR_TXERR_MASK                           MAC_DMA_ISR_TXERR_MASK
#define MAC_DMA_IMR_TXNOPKT_MASK                         MAC_DMA_ISR_TXNOPKT_MASK
#define MAC_DMA_IMR_TXEOL_MASK                           MAC_DMA_ISR_TXEOL_MASK
#define MAC_DMA_IMR_TXURN_MASK                           MAC_DMA_ISR_TXURN_MASK
#define MAC_DMA_IMR_MIB_MASK                             MAC_DMA_ISR_MIB_MASK
#define MAC_DMA_IMR_SWI_MASK                             MAC_DMA_ISR_SWI_MASK
#define MAC_DMA_IMR_UNUSED_14                            MAC_DMA_ISR_UNUSED_14
#define MAC_DMA_IMR_UNUSED_15                            MAC_DMA_ISR_UNUSED_15
#define MAC_DMA_IMR_SWBA_MASK                            MAC_DMA_ISR_SWBA_MASK
#define MAC_DMA_IMR_BRSSI_MASK                           MAC_DMA_ISR_BRSSI_MASK
#define MAC_DMA_IMR_BMISS_MASK                           MAC_DMA_ISR_BMISS_MASK
#define MAC_DMA_IMR_UNUSED_19                            MAC_DMA_ISR_UNUSED_19
#define MAC_DMA_IMR_BNR_MASK                             MAC_DMA_ISR_BNR_MASK
#define MAC_DMA_IMR_RXINT_MASK                           MAC_DMA_ISR_RXINT_MASK
#define MAC_DMA_IMR_UNUSED_22                            MAC_DMA_ISR_UNUSED_22
#define MAC_DMA_IMR_BCNMISC_MASK                         MAC_DMA_ISR_BCNMISC_MASK
#define MAC_DMA_IMR_TIM_MASK                             MAC_DMA_ISR_TIM_MASK
#define MAC_DMA_IMR_UNUSED_24                            MAC_DMA_ISR_UNUSED_24
#define MAC_DMA_IMR_QCBROVF_MASK                         MAC_DMA_ISR_QCBROVF_MASK
#define MAC_DMA_IMR_QCBRURN_MASK                         MAC_DMA_ISR_QCBRURN_MASK
#define MAC_DMA_IMR_QTRIG_MASK                           MAC_DMA_ISR_QTRIG_MASK
#define MAC_DMA_IMR_TIMER_MASK                           MAC_DMA_ISR_TIMER_MASK
#define MAC_DMA_IMR_UNUSED_29                            MAC_DMA_ISR_UNUSED_29
#define MAC_DMA_IMR_UNUSED_30                            MAC_DMA_ISR_UNUSED_30
#define MAC_DMA_IMR_UNUSED_31                            MAC_DMA_ISR_UNUSED_31

/* MAC Secondary interrupt mask register 1 */
#define MAC_DMA_IMR_S1_QCU_TXERR_MASK                      MAC_DMA_ISR_S1_QCU_TXERR_MASK
#define MAC_DMA_IMR_S1_QCU_TXERR_LSB                       MAC_DMA_ISR_S1_QCU_TXERR_LSB 
#define MAC_DMA_IMR_S1_QCU_TXEOL_MASK                      MAC_DMA_ISR_S1_QCU_TXEOL_MASK
#define MAC_DMA_IMR_S1_QCU_TXEOL_LSB                       MAC_DMA_ISR_S1_QCU_TXEOL_LSB 

/* MAC Secondary interrupt mask register 2 */
#define MAC_DMA_IMR_S2_QCU_TXURN_MASK                      MAC_DMA_IMR_S2_TXURN_MASK
#define MAC_DMA_IMR_S2_QCU_TXURN_LSB                       MAC_DMA_IMR_S2_TXURN_LSB
#define MAC_DMA_IMR_S2_TDMA_START_ERR_MASK                 MAC_DMA_IMR_S2_TDMA_START_TIME_ERROR_MASK
#define MAC_DMA_IMR_S2_TDMA_TX_AP_PULSE_MASK               MAC_DMA_IMR_S2_TDMA_APSYNC_MASK
#define MAC_DMA_IMR_S2_RX_PTR_BAD_MASK                     MAC_DMA_IMR_S2_PCU_RX_PTR_BAD_MASK
#define MAC_DMA_IMR_S2_TIM2_MASK                           MAC_DMA_IMR_S2_TIM_STA_1_MASK
#define MAC_DMA_IMR_S2_CAB2END_MASK                        MAC_DMA_IMR_S2_CABEND_STA_1_MASK
#define MAC_DMA_IMR_S2_DTIM2SYNC_MASK                      MAC_DMA_IMR_S2_DTIMSYNC_STA_1_MASK
#define MAC_DMA_IMR_S2_BCN2TO_MASK                         MAC_DMA_IMR_S2_BCNTO_STA_1_MASK
#define MAC_DMA_IMR_S2_CAB2TO_MASK                         MAC_DMA_IMR_S2_CABTO_STA_1_MASK
#define MAC_DMA_IMR_S2_DTIM2_MASK                          MAC_DMA_IMR_S2_DTIM_STA_1_MASK
#define MAC_DMA_IMR_S2_TSF2OOR_MASK                        MAC_DMA_IMR_S2_TSFOOR_STA_1_MASK
#define MAC_DMA_IMR_S2_TBTT2_TIME_MASK                     MAC_DMA_IMR_S2_TBTT_TIME_STA_1_MASK
#define MAC_DMA_IMR_S2_TIM_MASK                            MAC_DMA_IMR_S2_TIM_STA_0_MASK
#define MAC_DMA_IMR_S2_CABEND_MASK                         MAC_DMA_IMR_S2_CABEND_STA_0_MASK
#define MAC_DMA_IMR_S2_DTIMSYNC_MASK                       MAC_DMA_IMR_S2_DTIMSYNC_STA_0_MASK
#define MAC_DMA_IMR_S2_BCNTO_MASK                          MAC_DMA_IMR_S2_BCNTO_STA_0_MASK
#define MAC_DMA_IMR_S2_CABTO_MASK                          MAC_DMA_IMR_S2_CABTO_STA_0_MASK
#define MAC_DMA_IMR_S2_DTIM_MASK                           MAC_DMA_IMR_S2_DTIM_STA_0_MASK
#define MAC_DMA_IMR_S2_TSFOOR_MASK                         MAC_DMA_IMR_S2_TSFOOR_STA_0_MASK
#define MAC_DMA_IMR_S2_TBTT_TIME_MASK                      MAC_DMA_IMR_S2_TBTT_TIME_STA_0_MASK

/* MAC Secondary interrupt mask register 3 */
#define MAC_DMA_IMR_S3_QCU_QCBROVF_MASK                    MAC_DMA_ISR_S3_QCU_QCBROVF_MASK
#define MAC_DMA_IMR_S3_RX_LP_Q_OVF_MASK                    MAC_DMA_ISR_S3_RX_LP_Q_OVF_MASK
#define MAC_DMA_IMR_S3_RX_HP_Q_OVF_MASK                    MAC_DMA_ISR_S3_RX_HP_Q_OVF_MASK
#define MAC_DMA_IMR_S3_QCU_QCBRURN_MASK                    MAC_DMA_ISR_S3_QCU_QCBRURN_MASK
#define MAC_DMA_IMR_S3_BRSSI_LO_MASK                       MAC_DMA_ISR_S3_BRSSI_LO_MASK   
#define MAC_DMA_IMR_S3_BRSSI_HI_MASK                       MAC_DMA_ISR_S3_BRSSI_HI_MASK   
#define MAC_DMA_IMR_S3_BRSSI_LO2_MASK                      MAC_DMA_ISR_S3_BRSSI_LO2_MASK  
#define MAC_DMA_IMR_S3_BRSSI_HI2_MASK                      MAC_DMA_ISR_S3_BRSSI_HI2_MASK  
#define MAC_DMA_IMR_S3_BMISS_MASK                          MAC_DMA_ISR_S3_BMISS_MASK      
#define MAC_DMA_IMR_S3_BMISS2_MASK                         MAC_DMA_ISR_S3_BMISS2_MASK     

/* MAC Secondary interrupt mask register 4 */
#define MAC_DMA_IMR_S4_QCU_QTRIG_MASK                      MAC_DMA_ISR_S4_QCU_QTRIG_MASK      
#define MAC_DMA_IMR_S4_QCU_QTXDP_OVF_MASK                  MAC_DMA_ISR_S4_QCU_QTXDP_OVF_MASK  
#define MAC_DMA_IMR_S4_QCU_TXDP_TH_INT_MASK                MAC_DMA_ISR_S4_QCU_TXDP_TH_INT_MASK

/* MAC Secondary interrupt mask register 5 */
#define MAC_DMA_IMR_S5_TBTT_TIMER_TRIGGER_MASK             MAC_DMA_ISR_S5_TBTT_TIMER_TRIGGER_MASK      
#define MAC_DMA_IMR_S5_DBA_TIMER_TRIGGER_MASK              MAC_DMA_ISR_S5_DBA_TIMER_TRIGGER_MASK       
#define MAC_DMA_IMR_S5_SBA_TIMER_TRIGGER_MASK              MAC_DMA_ISR_S5_SBA_TIMER_TRIGGER_MASK       
#define MAC_DMA_IMR_S5_HCF_TIMER_TRIGGER_MASK              MAC_DMA_ISR_S5_HCF_TIMER_TRIGGER_MASK       
#define MAC_DMA_IMR_S5_TIM_TIMER_TRIGGER_MASK              MAC_DMA_ISR_S5_TIM_TIMER_TRIGGER_MASK       
#define MAC_DMA_IMR_S5_DTIM_TIMER_TRIGGER_MASK             MAC_DMA_ISR_S5_DTIM_TIMER_TRIGGER_MASK      
#define MAC_DMA_IMR_S5_QUIET_TIMER_TRIGGER_MASK            MAC_DMA_ISR_S5_QUIET_TIMER_TRIGGER_MASK     
#define MAC_DMA_IMR_S5_NDP_TIMER_TRIGGER_MASK              MAC_DMA_ISR_S5_NDP_TIMER_TRIGGER_MASK       
#define MAC_DMA_IMR_S5_GENERIC_TIMER2_TRIGGER_MASK         MAC_DMA_ISR_S5_GENERIC_TIMER2_TRIGGER_MASK  
#define MAC_DMA_IMR_S5_GENERIC_TIMER2_TRIGGER_LSB          MAC_DMA_ISR_S5_GENERIC_TIMER2_TRIGGER_LSB   
#define MAC_DMA_IMR_S5_GENERIC_TIMER2_TRIGGER(_i)          MAC_DMA_ISR_S5_GENERIC_TIMER2_TRIGGER(_i)   
#define MAC_DMA_IMR_S5_TIMER_OVERFLOW_MASK                 MAC_DMA_ISR_S5_TIMER_OVERFLOW_MASK          
#define MAC_DMA_IMR_S5_DBA_TIMER_THRESHOLD_MASK            MAC_DMA_ISR_S5_DBA_TIMER_THRESHOLD_MASK     
#define MAC_DMA_IMR_S5_SBA_TIMER_THRESHOLD_MASK            MAC_DMA_ISR_S5_SBA_TIMER_THRESHOLD_MASK     
#define MAC_DMA_IMR_S5_HCF_TIMER_THRESHOLD_MASK            MAC_DMA_ISR_S5_HCF_TIMER_THRESHOLD_MASK     
#define MAC_DMA_IMR_S5_TIM_TIMER_THRESHOLD_MASK            MAC_DMA_ISR_S5_TIM_TIMER_THRESHOLD_MASK     
#define MAC_DMA_IMR_S5_DTIM_TIMER_THRESHOLD_MASK           MAC_DMA_ISR_S5_DTIM_TIMER_THRESHOLD_MASK    
#define MAC_DMA_IMR_S5_QUIET_TIMER_THRESHOLD_MASK          MAC_DMA_ISR_S5_QUIET_TIMER_THRESHOLD_MASK   
#define MAC_DMA_IMR_S5_NDP_TIMER_THRESHOLD_MASK            MAC_DMA_ISR_S5_NDP_TIMER_THRESHOLD_MASK     
#define MAC_DMA_IMR_S5_GENERIC_TIMER2_THRESHOLD_MASK       MAC_DMA_ISR_S5_GENERIC_TIMER2_THRESHOLD_MASK
#define MAC_DMA_IMR_S5_GENERIC_TIMER2_THRESHOLD_LSB        MAC_DMA_ISR_S5_GENERIC_TIMER2_THRESHOLD_LSB 
#define MAC_DMA_IMR_S5_GENERIC_TIMER2_THRESHOLD(_i)        MAC_DMA_ISR_S5_GENERIC_TIMER2_THRESHOLD(_i) 

#define MAC_DMA_TIMT_TX_FIRST_PKT_THRESH_LSB               MAC_DMA_TIMT_0_TX_FIRST_PKT_THRESH_LSB 
#define MAC_DMA_TIMT_TX_FIRST_PKT_THRESH_MASK              MAC_DMA_TIMT_0_TX_FIRST_PKT_THRESH_MASK
#define MAC_DMA_TIMT_TX_LAST_PKT_THRESH_LSB                MAC_DMA_TIMT_0_TX_LAST_PKT_THRESH_LSB
#define MAC_DMA_TIMT_TX_LAST_PKT_THRESH_MASK               MAC_DMA_TIMT_0_TX_LAST_PKT_THRESH_MASK
#define MAC_DMA_TIMT_ADDRESS                               MAC_DMA_TIMT_0_ADDRESS
#define MAC_DMA_TIMT_ADDR(_i)                              (MAC_DMA_TIMT_0_ADDRESS + ((_i)<<2))
                                                           
#define MAC_QCU_CNT_ADDR(_i)                               (MAC_QCU_CNT_ADDRESS + ((_i)<<2))
                                                           
#define MAC_DCU_MISC_ADDR(_i)                              (MAC_DCU_MISC_ADDRESS + ((_i)<<2))
#define MAC_DCU_MISC_FRAG_BURST_WAIT_EN_MASK               MAC_DCU_MISC_0_FRAG_BURST_WAIT_QCU_EN_MASK
                                                           
#define MAC_QCU_TXDP_ADDR(_i)                              (MAC_QCU_TXDP_ADDRESS + ((_i)<<2))
                                                           
#define MAC_DCU_QCUMASK_ADDR(_i)                           (MAC_DCU_QCUMASK_ADDRESS + ((_i)<<2))
                                                           
#define MAC_DCU_LCL_IFS_ADDR(_i)                           (MAC_DCU_LCL_IFS_ADDRESS + ((_i)<<2))
                                                           
#define MAC_DCU_RETRY_LIMIT_ADDR(_i)                       (MAC_DCU_RETRY_LIMIT_ADDRESS + ((_i)<<2))

#define MAC_QCU_MISC_ADDR(_i)                              (MAC_QCU_MISC_ADDRESS + ((_i)<<2))
#define MAC_QCU_MISC_FSP_ASAP                              0          // ASAP
#define MAC_QCU_MISC_FSP_CBR                               1          // CBR
#define MAC_QCU_MISC_FSP_DBA_GATED                         2          // DMA Beacon Alert gated
#define MAC_QCU_MISC_FSP_TIM_GATED                         3          // TIM gated
#define MAC_QCU_MISC_FSP_BEACON_SENT_GATED                 4          // Beacon-sent-gated
#define MAC_QCU_MISC_FSP_BEACON_RCVD_GATED                 5          // Beacon-received-gated

#define MAC_DCU_MISC_ADDR(_i)                              (MAC_DCU_MISC_ADDRESS + ((_i)<<2))
#define MAC_DCU_MISC_VIR_COL_HANDLING_DEFAULT              0   // Normal
#define MAC_DCU_MISC_VIR_COL_HANDLING_IGNORE               1   // Ignore

#define MAC_QCU_CBR_ADDR(_i)                               (MAC_QCU_CBR_ADDRESS + ((_i)<<2))

#define MAC_QCU_RDYTIME_ADDR(_i)                           (MAC_QCU_RDYTIME_ADDRESS + ((_i)<<2))

#define MAC_DMA_MIBC_MCS_MSB                               MAC_DMA_MIBC_STROBE_MSB    
#define MAC_DMA_MIBC_MCS_LSB                               MAC_DMA_MIBC_STROBE_LSB    
#define MAC_DMA_MIBC_MCS_MASK                              MAC_DMA_MIBC_STROBE_MASK   
#define MAC_DMA_MIBC_MCS_GET(x)                            MAC_DMA_MIBC_STROBE_GET(x) 
#define MAC_DMA_MIBC_MCS_SET(x)                            MAC_DMA_MIBC_STROBE_SET(x) 
#define MAC_DMA_MIBC_CMC_MSB                               MAC_DMA_MIBC_CLEAR_MSB     
#define MAC_DMA_MIBC_CMC_LSB                               MAC_DMA_MIBC_CLEAR_LSB     
#define MAC_DMA_MIBC_CMC_MASK                              MAC_DMA_MIBC_CLEAR_MASK    
#define MAC_DMA_MIBC_CMC_GET(x)                            MAC_DMA_MIBC_CLEAR_GET(x)  
#define MAC_DMA_MIBC_CMC_SET(x)                            MAC_DMA_MIBC_CLEAR_SET(x)  
#define MAC_DMA_MIBC_FMC_MSB                               MAC_DMA_MIBC_FREEZE_MSB    
#define MAC_DMA_MIBC_FMC_LSB                               MAC_DMA_MIBC_FREEZE_LSB    
#define MAC_DMA_MIBC_FMC_MASK                              MAC_DMA_MIBC_FREEZE_MASK   
#define MAC_DMA_MIBC_FMC_GET(x)                            MAC_DMA_MIBC_FREEZE_GET(x) 
#define MAC_DMA_MIBC_FMC_SET(x)                            MAC_DMA_MIBC_FREEZE_SET(x) 
#define MAC_DMA_MIBC_COW_MSB                               MAC_DMA_MIBC_WARNING_MSB   
#define MAC_DMA_MIBC_COW_LSB                               MAC_DMA_MIBC_WARNING_LSB   
#define MAC_DMA_MIBC_COW_MASK                              MAC_DMA_MIBC_WARNING_MASK  
#define MAC_DMA_MIBC_COW_GET(x)                            MAC_DMA_MIBC_WARNING_GET(x)
#define MAC_DMA_MIBC_COW_SET(x)                            MAC_DMA_MIBC_WARNING_SET(x)

#endif /*__MAC_DMA_REG_SW_H */



