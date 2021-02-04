//                                                                             
// File:       ./wlan_coex_reg.vrh                                             
// Creator:    jhou                                                            
// Time:       Wednesday Oct 3, 2012 [2:42:33 pm]                              
//                                                                             
// Path:       /trees/jhou/jhou-dev/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/jhou/jhou-dev/chips/peregrine/2.0/blueprint/sysconfig    
//             wlan_coex_reg.rdl                                               
//                                                                             
// Sources:    /trees/jhou/jhou-dev/chips/peregrine/2.0/ip/athr/wifi/rtl/./mac/rtl/dev/mac_coex/blueprint/wlan_coex_reg.rdl
//             /trees/jhou/jhou-dev/chips/peregrine/2.0/env/blueprint/ath_vrh.pm
//             /cad/local/lib/perl/Pinfo.pm                                    
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    zeus                                                            
// OS:         Linux 2.6.9-78.0.5.ELsmp                                        
// Description:                                                                
//                                                                             
// No Description Provided                                                     
/*
 * Copyright (c) 2012-14 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */


#ifndef _WLAN_COEX_REG_H_
#define _WLAN_COEX_REG_H_
// 0x0000 (MCI_COMMAND0)
#define MCI_COMMAND0_DISABLE_TIMESTAMP_MSB                           13
#define MCI_COMMAND0_DISABLE_TIMESTAMP_LSB                           13
#define MCI_COMMAND0_DISABLE_TIMESTAMP_MASK                          0x00002000
#define MCI_COMMAND0_DISABLE_TIMESTAMP_GET(x)                        (((x) & MCI_COMMAND0_DISABLE_TIMESTAMP_MASK) >> MCI_COMMAND0_DISABLE_TIMESTAMP_LSB)
#define MCI_COMMAND0_DISABLE_TIMESTAMP_SET(x)                        (((0 | (x)) << MCI_COMMAND0_DISABLE_TIMESTAMP_LSB) & MCI_COMMAND0_DISABLE_TIMESTAMP_MASK)
#define MCI_COMMAND0_DISABLE_TIMESTAMP_RESET                         0
#define MCI_COMMAND0_LEN_MSB                                         12
#define MCI_COMMAND0_LEN_LSB                                         8
#define MCI_COMMAND0_LEN_MASK                                        0x00001f00
#define MCI_COMMAND0_LEN_GET(x)                                      (((x) & MCI_COMMAND0_LEN_MASK) >> MCI_COMMAND0_LEN_LSB)
#define MCI_COMMAND0_LEN_SET(x)                                      (((0 | (x)) << MCI_COMMAND0_LEN_LSB) & MCI_COMMAND0_LEN_MASK)
#define MCI_COMMAND0_LEN_RESET                                       0
#define MCI_COMMAND0_HEADER_MSB                                      7
#define MCI_COMMAND0_HEADER_LSB                                      0
#define MCI_COMMAND0_HEADER_MASK                                     0x000000ff
#define MCI_COMMAND0_HEADER_GET(x)                                   (((x) & MCI_COMMAND0_HEADER_MASK) >> MCI_COMMAND0_HEADER_LSB)
#define MCI_COMMAND0_HEADER_SET(x)                                   (((0 | (x)) << MCI_COMMAND0_HEADER_LSB) & MCI_COMMAND0_HEADER_MASK)
#define MCI_COMMAND0_HEADER_RESET                                    0
#define MCI_COMMAND0_ADDRESS                                         0x0000
#define MCI_COMMAND0_HW_MASK                                         0x00003fff
#define MCI_COMMAND0_SW_MASK                                         0x00003fff
#define MCI_COMMAND0_HW_WRITE_MASK                                   0x00000000
#define MCI_COMMAND0_SW_WRITE_MASK                                   0x00003fff
#define MCI_COMMAND0_RSTMASK                                         0xffffffff
#define MCI_COMMAND0_RESET                                           0x00000000

// 0x0004 (MCI_COMMAND1)
#define MCI_COMMAND1_ADDR_MSB                                        31
#define MCI_COMMAND1_ADDR_LSB                                        0
#define MCI_COMMAND1_ADDR_MASK                                       0xffffffff
#define MCI_COMMAND1_ADDR_GET(x)                                     (((x) & MCI_COMMAND1_ADDR_MASK) >> MCI_COMMAND1_ADDR_LSB)
#define MCI_COMMAND1_ADDR_SET(x)                                     (((0 | (x)) << MCI_COMMAND1_ADDR_LSB) & MCI_COMMAND1_ADDR_MASK)
#define MCI_COMMAND1_ADDR_RESET                                      0
#define MCI_COMMAND1_ADDRESS                                         0x0004
#define MCI_COMMAND1_HW_MASK                                         0xffffffff
#define MCI_COMMAND1_SW_MASK                                         0xffffffff
#define MCI_COMMAND1_HW_WRITE_MASK                                   0x00000000
#define MCI_COMMAND1_SW_WRITE_MASK                                   0xffffffff
#define MCI_COMMAND1_RSTMASK                                         0xffffffff
#define MCI_COMMAND1_RESET                                           0x00000000

// 0x0008 (MCI_COMMAND2)
#define MCI_COMMAND2_RESET_REQ_WAKEUP_MSB                            10
#define MCI_COMMAND2_RESET_REQ_WAKEUP_LSB                            10
#define MCI_COMMAND2_RESET_REQ_WAKEUP_MASK                           0x00000400
#define MCI_COMMAND2_RESET_REQ_WAKEUP_GET(x)                         (((x) & MCI_COMMAND2_RESET_REQ_WAKEUP_MASK) >> MCI_COMMAND2_RESET_REQ_WAKEUP_LSB)
#define MCI_COMMAND2_RESET_REQ_WAKEUP_SET(x)                         (((0 | (x)) << MCI_COMMAND2_RESET_REQ_WAKEUP_LSB) & MCI_COMMAND2_RESET_REQ_WAKEUP_MASK)
#define MCI_COMMAND2_RESET_REQ_WAKEUP_RESET                          0
#define MCI_COMMAND2_RESET_RX_NUM_CYCLES_MSB                         9
#define MCI_COMMAND2_RESET_RX_NUM_CYCLES_LSB                         2
#define MCI_COMMAND2_RESET_RX_NUM_CYCLES_MASK                        0x000003fc
#define MCI_COMMAND2_RESET_RX_NUM_CYCLES_GET(x)                      (((x) & MCI_COMMAND2_RESET_RX_NUM_CYCLES_MASK) >> MCI_COMMAND2_RESET_RX_NUM_CYCLES_LSB)
#define MCI_COMMAND2_RESET_RX_NUM_CYCLES_SET(x)                      (((0 | (x)) << MCI_COMMAND2_RESET_RX_NUM_CYCLES_LSB) & MCI_COMMAND2_RESET_RX_NUM_CYCLES_MASK)
#define MCI_COMMAND2_RESET_RX_NUM_CYCLES_RESET                       255
#define MCI_COMMAND2_RESET_RX_MSB                                    1
#define MCI_COMMAND2_RESET_RX_LSB                                    1
#define MCI_COMMAND2_RESET_RX_MASK                                   0x00000002
#define MCI_COMMAND2_RESET_RX_GET(x)                                 (((x) & MCI_COMMAND2_RESET_RX_MASK) >> MCI_COMMAND2_RESET_RX_LSB)
#define MCI_COMMAND2_RESET_RX_SET(x)                                 (((0 | (x)) << MCI_COMMAND2_RESET_RX_LSB) & MCI_COMMAND2_RESET_RX_MASK)
#define MCI_COMMAND2_RESET_RX_RESET                                  0
#define MCI_COMMAND2_RESET_TX_MSB                                    0
#define MCI_COMMAND2_RESET_TX_LSB                                    0
#define MCI_COMMAND2_RESET_TX_MASK                                   0x00000001
#define MCI_COMMAND2_RESET_TX_GET(x)                                 (((x) & MCI_COMMAND2_RESET_TX_MASK) >> MCI_COMMAND2_RESET_TX_LSB)
#define MCI_COMMAND2_RESET_TX_SET(x)                                 (((0 | (x)) << MCI_COMMAND2_RESET_TX_LSB) & MCI_COMMAND2_RESET_TX_MASK)
#define MCI_COMMAND2_RESET_TX_RESET                                  0
#define MCI_COMMAND2_ADDRESS                                         0x0008
#define MCI_COMMAND2_HW_MASK                                         0x000007ff
#define MCI_COMMAND2_SW_MASK                                         0x000007ff
#define MCI_COMMAND2_HW_WRITE_MASK                                   0x00000000
#define MCI_COMMAND2_SW_WRITE_MASK                                   0x000007ff
#define MCI_COMMAND2_RSTMASK                                         0xffffffff
#define MCI_COMMAND2_RESET                                           0x000003fc

// 0x000c (MCI_RX_CTRL)
#define MCI_RX_CTRL_HDR_RX_TIMEOUT_EN_MSB                            2
#define MCI_RX_CTRL_HDR_RX_TIMEOUT_EN_LSB                            2
#define MCI_RX_CTRL_HDR_RX_TIMEOUT_EN_MASK                           0x00000004
#define MCI_RX_CTRL_HDR_RX_TIMEOUT_EN_GET(x)                         (((x) & MCI_RX_CTRL_HDR_RX_TIMEOUT_EN_MASK) >> MCI_RX_CTRL_HDR_RX_TIMEOUT_EN_LSB)
#define MCI_RX_CTRL_HDR_RX_TIMEOUT_EN_SET(x)                         (((0 | (x)) << MCI_RX_CTRL_HDR_RX_TIMEOUT_EN_LSB) & MCI_RX_CTRL_HDR_RX_TIMEOUT_EN_MASK)
#define MCI_RX_CTRL_HDR_RX_TIMEOUT_EN_RESET                          0
#define MCI_RX_CTRL_DISABLE_MAXGAIN_RESET_MSB                        1
#define MCI_RX_CTRL_DISABLE_MAXGAIN_RESET_LSB                        1
#define MCI_RX_CTRL_DISABLE_MAXGAIN_RESET_MASK                       0x00000002
#define MCI_RX_CTRL_DISABLE_MAXGAIN_RESET_GET(x)                     (((x) & MCI_RX_CTRL_DISABLE_MAXGAIN_RESET_MASK) >> MCI_RX_CTRL_DISABLE_MAXGAIN_RESET_LSB)
#define MCI_RX_CTRL_DISABLE_MAXGAIN_RESET_SET(x)                     (((0 | (x)) << MCI_RX_CTRL_DISABLE_MAXGAIN_RESET_LSB) & MCI_RX_CTRL_DISABLE_MAXGAIN_RESET_MASK)
#define MCI_RX_CTRL_DISABLE_MAXGAIN_RESET_RESET                      0
#define MCI_RX_CTRL_DISABLE_TIMESTAMP_MSB                            0
#define MCI_RX_CTRL_DISABLE_TIMESTAMP_LSB                            0
#define MCI_RX_CTRL_DISABLE_TIMESTAMP_MASK                           0x00000001
#define MCI_RX_CTRL_DISABLE_TIMESTAMP_GET(x)                         (((x) & MCI_RX_CTRL_DISABLE_TIMESTAMP_MASK) >> MCI_RX_CTRL_DISABLE_TIMESTAMP_LSB)
#define MCI_RX_CTRL_DISABLE_TIMESTAMP_SET(x)                         (((0 | (x)) << MCI_RX_CTRL_DISABLE_TIMESTAMP_LSB) & MCI_RX_CTRL_DISABLE_TIMESTAMP_MASK)
#define MCI_RX_CTRL_DISABLE_TIMESTAMP_RESET                          0
#define MCI_RX_CTRL_ADDRESS                                          0x000c
#define MCI_RX_CTRL_HW_MASK                                          0x00000007
#define MCI_RX_CTRL_SW_MASK                                          0x00000007
#define MCI_RX_CTRL_HW_WRITE_MASK                                    0x00000000
#define MCI_RX_CTRL_SW_WRITE_MASK                                    0x00000007
#define MCI_RX_CTRL_RSTMASK                                          0xffffffff
#define MCI_RX_CTRL_RESET                                            0x00000000

// 0x0010 (MCI_TX_CTRL)
#define MCI_TX_CTRL_GAIN_UPDATE_NUM_MSB                              27
#define MCI_TX_CTRL_GAIN_UPDATE_NUM_LSB                              24
#define MCI_TX_CTRL_GAIN_UPDATE_NUM_MASK                             0x0f000000
#define MCI_TX_CTRL_GAIN_UPDATE_NUM_GET(x)                           (((x) & MCI_TX_CTRL_GAIN_UPDATE_NUM_MASK) >> MCI_TX_CTRL_GAIN_UPDATE_NUM_LSB)
#define MCI_TX_CTRL_GAIN_UPDATE_NUM_SET(x)                           (((0 | (x)) << MCI_TX_CTRL_GAIN_UPDATE_NUM_LSB) & MCI_TX_CTRL_GAIN_UPDATE_NUM_MASK)
#define MCI_TX_CTRL_GAIN_UPDATE_NUM_RESET                            15
#define MCI_TX_CTRL_GAIN_UPDATE_FREQ_MSB                             23
#define MCI_TX_CTRL_GAIN_UPDATE_FREQ_LSB                             3
#define MCI_TX_CTRL_GAIN_UPDATE_FREQ_MASK                            0x00fffff8
#define MCI_TX_CTRL_GAIN_UPDATE_FREQ_GET(x)                          (((x) & MCI_TX_CTRL_GAIN_UPDATE_FREQ_MASK) >> MCI_TX_CTRL_GAIN_UPDATE_FREQ_LSB)
#define MCI_TX_CTRL_GAIN_UPDATE_FREQ_SET(x)                          (((0 | (x)) << MCI_TX_CTRL_GAIN_UPDATE_FREQ_LSB) & MCI_TX_CTRL_GAIN_UPDATE_FREQ_MASK)
#define MCI_TX_CTRL_GAIN_UPDATE_FREQ_RESET                           0
#define MCI_TX_CTRL_DISABLE_LNA_UPDATES_MSB                          2
#define MCI_TX_CTRL_DISABLE_LNA_UPDATES_LSB                          2
#define MCI_TX_CTRL_DISABLE_LNA_UPDATES_MASK                         0x00000004
#define MCI_TX_CTRL_DISABLE_LNA_UPDATES_GET(x)                       (((x) & MCI_TX_CTRL_DISABLE_LNA_UPDATES_MASK) >> MCI_TX_CTRL_DISABLE_LNA_UPDATES_LSB)
#define MCI_TX_CTRL_DISABLE_LNA_UPDATES_SET(x)                       (((0 | (x)) << MCI_TX_CTRL_DISABLE_LNA_UPDATES_LSB) & MCI_TX_CTRL_DISABLE_LNA_UPDATES_MASK)
#define MCI_TX_CTRL_DISABLE_LNA_UPDATES_RESET                        1
#define MCI_TX_CTRL_CLK_DIV_MSB                                      1
#define MCI_TX_CTRL_CLK_DIV_LSB                                      0
#define MCI_TX_CTRL_CLK_DIV_MASK                                     0x00000003
#define MCI_TX_CTRL_CLK_DIV_GET(x)                                   (((x) & MCI_TX_CTRL_CLK_DIV_MASK) >> MCI_TX_CTRL_CLK_DIV_LSB)
#define MCI_TX_CTRL_CLK_DIV_SET(x)                                   (((0 | (x)) << MCI_TX_CTRL_CLK_DIV_LSB) & MCI_TX_CTRL_CLK_DIV_MASK)
#define MCI_TX_CTRL_CLK_DIV_RESET                                    0
#define MCI_TX_CTRL_ADDRESS                                          0x0010
#define MCI_TX_CTRL_HW_MASK                                          0x0fffffff
#define MCI_TX_CTRL_SW_MASK                                          0x0fffffff
#define MCI_TX_CTRL_HW_WRITE_MASK                                    0x00000000
#define MCI_TX_CTRL_SW_WRITE_MASK                                    0x0fffffff
#define MCI_TX_CTRL_RSTMASK                                          0xffffffff
#define MCI_TX_CTRL_RESET                                            0x0f000004

// 0x0014 (MCI_MSG_ATTRIBUTES_TABLE)
#define MCI_MSG_ATTRIBUTES_TABLE_INVALID_HDR_MSB                     31
#define MCI_MSG_ATTRIBUTES_TABLE_INVALID_HDR_LSB                     16
#define MCI_MSG_ATTRIBUTES_TABLE_INVALID_HDR_MASK                    0xffff0000
#define MCI_MSG_ATTRIBUTES_TABLE_INVALID_HDR_GET(x)                  (((x) & MCI_MSG_ATTRIBUTES_TABLE_INVALID_HDR_MASK) >> MCI_MSG_ATTRIBUTES_TABLE_INVALID_HDR_LSB)
#define MCI_MSG_ATTRIBUTES_TABLE_INVALID_HDR_SET(x)                  (((0 | (x)) << MCI_MSG_ATTRIBUTES_TABLE_INVALID_HDR_LSB) & MCI_MSG_ATTRIBUTES_TABLE_INVALID_HDR_MASK)
#define MCI_MSG_ATTRIBUTES_TABLE_INVALID_HDR_RESET                   59909
#define MCI_MSG_ATTRIBUTES_TABLE_CHECKSUM_EN_MSB                     15
#define MCI_MSG_ATTRIBUTES_TABLE_CHECKSUM_EN_LSB                     0
#define MCI_MSG_ATTRIBUTES_TABLE_CHECKSUM_EN_MASK                    0x0000ffff
#define MCI_MSG_ATTRIBUTES_TABLE_CHECKSUM_EN_GET(x)                  (((x) & MCI_MSG_ATTRIBUTES_TABLE_CHECKSUM_EN_MASK) >> MCI_MSG_ATTRIBUTES_TABLE_CHECKSUM_EN_LSB)
#define MCI_MSG_ATTRIBUTES_TABLE_CHECKSUM_EN_SET(x)                  (((0 | (x)) << MCI_MSG_ATTRIBUTES_TABLE_CHECKSUM_EN_LSB) & MCI_MSG_ATTRIBUTES_TABLE_CHECKSUM_EN_MASK)
#define MCI_MSG_ATTRIBUTES_TABLE_CHECKSUM_EN_RESET                   65534
#define MCI_MSG_ATTRIBUTES_TABLE_ADDRESS                             0x0014
#define MCI_MSG_ATTRIBUTES_TABLE_HW_MASK                             0xffffffff
#define MCI_MSG_ATTRIBUTES_TABLE_SW_MASK                             0xffffffff
#define MCI_MSG_ATTRIBUTES_TABLE_HW_WRITE_MASK                       0x00000000
#define MCI_MSG_ATTRIBUTES_TABLE_SW_WRITE_MASK                       0xffffffff
#define MCI_MSG_ATTRIBUTES_TABLE_RSTMASK                             0xffffffff
#define MCI_MSG_ATTRIBUTES_TABLE_RESET                               0xea05fffe

// 0x0018 (MCI_SCHD_TABLE_0)
#define MCI_SCHD_TABLE_0_BASE_ADDR_MSB                               31
#define MCI_SCHD_TABLE_0_BASE_ADDR_LSB                               0
#define MCI_SCHD_TABLE_0_BASE_ADDR_MASK                              0xffffffff
#define MCI_SCHD_TABLE_0_BASE_ADDR_GET(x)                            (((x) & MCI_SCHD_TABLE_0_BASE_ADDR_MASK) >> MCI_SCHD_TABLE_0_BASE_ADDR_LSB)
#define MCI_SCHD_TABLE_0_BASE_ADDR_SET(x)                            (((0 | (x)) << MCI_SCHD_TABLE_0_BASE_ADDR_LSB) & MCI_SCHD_TABLE_0_BASE_ADDR_MASK)
#define MCI_SCHD_TABLE_0_BASE_ADDR_RESET                             0
#define MCI_SCHD_TABLE_0_ADDRESS                                     0x0018
#define MCI_SCHD_TABLE_0_HW_MASK                                     0xffffffff
#define MCI_SCHD_TABLE_0_SW_MASK                                     0xffffffff
#define MCI_SCHD_TABLE_0_HW_WRITE_MASK                               0x00000000
#define MCI_SCHD_TABLE_0_SW_WRITE_MASK                               0xffffffff
#define MCI_SCHD_TABLE_0_RSTMASK                                     0xffffffff
#define MCI_SCHD_TABLE_0_RESET                                       0x00000000

// 0x001c (MCI_SCHD_TABLE_1)
#define MCI_SCHD_TABLE_1_SW_REQ_OWN_MSB                              31
#define MCI_SCHD_TABLE_1_SW_REQ_OWN_LSB                              16
#define MCI_SCHD_TABLE_1_SW_REQ_OWN_MASK                             0xffff0000
#define MCI_SCHD_TABLE_1_SW_REQ_OWN_GET(x)                           (((x) & MCI_SCHD_TABLE_1_SW_REQ_OWN_MASK) >> MCI_SCHD_TABLE_1_SW_REQ_OWN_LSB)
#define MCI_SCHD_TABLE_1_SW_REQ_OWN_SET(x)                           (((0 | (x)) << MCI_SCHD_TABLE_1_SW_REQ_OWN_LSB) & MCI_SCHD_TABLE_1_SW_REQ_OWN_MASK)
#define MCI_SCHD_TABLE_1_SW_REQ_OWN_RESET                            0
#define MCI_SCHD_TABLE_1_OWN_MSB                                     15
#define MCI_SCHD_TABLE_1_OWN_LSB                                     0
#define MCI_SCHD_TABLE_1_OWN_MASK                                    0x0000ffff
#define MCI_SCHD_TABLE_1_OWN_GET(x)                                  (((x) & MCI_SCHD_TABLE_1_OWN_MASK) >> MCI_SCHD_TABLE_1_OWN_LSB)
#define MCI_SCHD_TABLE_1_OWN_SET(x)                                  (((0 | (x)) << MCI_SCHD_TABLE_1_OWN_LSB) & MCI_SCHD_TABLE_1_OWN_MASK)
#define MCI_SCHD_TABLE_1_OWN_RESET                                   0
#define MCI_SCHD_TABLE_1_ADDRESS                                     0x001c
#define MCI_SCHD_TABLE_1_HW_MASK                                     0xffffffff
#define MCI_SCHD_TABLE_1_SW_MASK                                     0xffffffff
#define MCI_SCHD_TABLE_1_HW_WRITE_MASK                               0x0000ffff
#define MCI_SCHD_TABLE_1_SW_WRITE_MASK                               0xffffffff
#define MCI_SCHD_TABLE_1_RSTMASK                                     0xffffffff
#define MCI_SCHD_TABLE_1_RESET                                       0x00000000

// 0x0020 (MCI_GPM_0)
#define MCI_GPM_0_START_ADDR_MSB                                     31
#define MCI_GPM_0_START_ADDR_LSB                                     0
#define MCI_GPM_0_START_ADDR_MASK                                    0xffffffff
#define MCI_GPM_0_START_ADDR_GET(x)                                  (((x) & MCI_GPM_0_START_ADDR_MASK) >> MCI_GPM_0_START_ADDR_LSB)
#define MCI_GPM_0_START_ADDR_SET(x)                                  (((0 | (x)) << MCI_GPM_0_START_ADDR_LSB) & MCI_GPM_0_START_ADDR_MASK)
#define MCI_GPM_0_START_ADDR_RESET                                   0
#define MCI_GPM_0_ADDRESS                                            0x0020
#define MCI_GPM_0_HW_MASK                                            0xffffffff
#define MCI_GPM_0_SW_MASK                                            0xffffffff
#define MCI_GPM_0_HW_WRITE_MASK                                      0x00000000
#define MCI_GPM_0_SW_WRITE_MASK                                      0xffffffff
#define MCI_GPM_0_RSTMASK                                            0xffffffff
#define MCI_GPM_0_RESET                                              0x00000000

// 0x0024 (MCI_GPM_1)
#define MCI_GPM_1_WRITE_PTR_MSB                                      31
#define MCI_GPM_1_WRITE_PTR_LSB                                      16
#define MCI_GPM_1_WRITE_PTR_MASK                                     0xffff0000
#define MCI_GPM_1_WRITE_PTR_GET(x)                                   (((x) & MCI_GPM_1_WRITE_PTR_MASK) >> MCI_GPM_1_WRITE_PTR_LSB)
#define MCI_GPM_1_WRITE_PTR_SET(x)                                   (((0 | (x)) << MCI_GPM_1_WRITE_PTR_LSB) & MCI_GPM_1_WRITE_PTR_MASK)
#define MCI_GPM_1_WRITE_PTR_RESET                                    0
#define MCI_GPM_1_LEN_MSB                                            15
#define MCI_GPM_1_LEN_LSB                                            0
#define MCI_GPM_1_LEN_MASK                                           0x0000ffff
#define MCI_GPM_1_LEN_GET(x)                                         (((x) & MCI_GPM_1_LEN_MASK) >> MCI_GPM_1_LEN_LSB)
#define MCI_GPM_1_LEN_SET(x)                                         (((0 | (x)) << MCI_GPM_1_LEN_LSB) & MCI_GPM_1_LEN_MASK)
#define MCI_GPM_1_LEN_RESET                                          255
#define MCI_GPM_1_ADDRESS                                            0x0024
#define MCI_GPM_1_HW_MASK                                            0xffffffff
#define MCI_GPM_1_SW_MASK                                            0xffffffff
#define MCI_GPM_1_HW_WRITE_MASK                                      0xffff0000
#define MCI_GPM_1_SW_WRITE_MASK                                      0x0000ffff
#define MCI_GPM_1_RSTMASK                                            0xffffffff
#define MCI_GPM_1_RESET                                              0x000000ff

// 0x0028 (MCI_INTERRUPT_RAW)
#define MCI_INTERRUPT_RAW_CONT_INFO_TIMEOUT_MSB                      31
#define MCI_INTERRUPT_RAW_CONT_INFO_TIMEOUT_LSB                      31
#define MCI_INTERRUPT_RAW_CONT_INFO_TIMEOUT_MASK                     0x80000000
#define MCI_INTERRUPT_RAW_CONT_INFO_TIMEOUT_GET(x)                   (((x) & MCI_INTERRUPT_RAW_CONT_INFO_TIMEOUT_MASK) >> MCI_INTERRUPT_RAW_CONT_INFO_TIMEOUT_LSB)
#define MCI_INTERRUPT_RAW_CONT_INFO_TIMEOUT_SET(x)                   (((0 | (x)) << MCI_INTERRUPT_RAW_CONT_INFO_TIMEOUT_LSB) & MCI_INTERRUPT_RAW_CONT_INFO_TIMEOUT_MASK)
#define MCI_INTERRUPT_RAW_CONT_INFO_TIMEOUT_RESET                    0
#define MCI_INTERRUPT_RAW_BB_AIC_IRQ_MSB                             30
#define MCI_INTERRUPT_RAW_BB_AIC_IRQ_LSB                             30
#define MCI_INTERRUPT_RAW_BB_AIC_IRQ_MASK                            0x40000000
#define MCI_INTERRUPT_RAW_BB_AIC_IRQ_GET(x)                          (((x) & MCI_INTERRUPT_RAW_BB_AIC_IRQ_MASK) >> MCI_INTERRUPT_RAW_BB_AIC_IRQ_LSB)
#define MCI_INTERRUPT_RAW_BB_AIC_IRQ_SET(x)                          (((0 | (x)) << MCI_INTERRUPT_RAW_BB_AIC_IRQ_LSB) & MCI_INTERRUPT_RAW_BB_AIC_IRQ_MASK)
#define MCI_INTERRUPT_RAW_BB_AIC_IRQ_RESET                           0
#define MCI_INTERRUPT_RAW_BT_STOMP_MSB                               29
#define MCI_INTERRUPT_RAW_BT_STOMP_LSB                               29
#define MCI_INTERRUPT_RAW_BT_STOMP_MASK                              0x20000000
#define MCI_INTERRUPT_RAW_BT_STOMP_GET(x)                            (((x) & MCI_INTERRUPT_RAW_BT_STOMP_MASK) >> MCI_INTERRUPT_RAW_BT_STOMP_LSB)
#define MCI_INTERRUPT_RAW_BT_STOMP_SET(x)                            (((0 | (x)) << MCI_INTERRUPT_RAW_BT_STOMP_LSB) & MCI_INTERRUPT_RAW_BT_STOMP_MASK)
#define MCI_INTERRUPT_RAW_BT_STOMP_RESET                             0
#define MCI_INTERRUPT_RAW_BT_FREQ_MSB                                28
#define MCI_INTERRUPT_RAW_BT_FREQ_LSB                                28
#define MCI_INTERRUPT_RAW_BT_FREQ_MASK                               0x10000000
#define MCI_INTERRUPT_RAW_BT_FREQ_GET(x)                             (((x) & MCI_INTERRUPT_RAW_BT_FREQ_MASK) >> MCI_INTERRUPT_RAW_BT_FREQ_LSB)
#define MCI_INTERRUPT_RAW_BT_FREQ_SET(x)                             (((0 | (x)) << MCI_INTERRUPT_RAW_BT_FREQ_LSB) & MCI_INTERRUPT_RAW_BT_FREQ_MASK)
#define MCI_INTERRUPT_RAW_BT_FREQ_RESET                              0
#define MCI_INTERRUPT_RAW_BT_PRI_THRESH_MSB                          27
#define MCI_INTERRUPT_RAW_BT_PRI_THRESH_LSB                          27
#define MCI_INTERRUPT_RAW_BT_PRI_THRESH_MASK                         0x08000000
#define MCI_INTERRUPT_RAW_BT_PRI_THRESH_GET(x)                       (((x) & MCI_INTERRUPT_RAW_BT_PRI_THRESH_MASK) >> MCI_INTERRUPT_RAW_BT_PRI_THRESH_LSB)
#define MCI_INTERRUPT_RAW_BT_PRI_THRESH_SET(x)                       (((0 | (x)) << MCI_INTERRUPT_RAW_BT_PRI_THRESH_LSB) & MCI_INTERRUPT_RAW_BT_PRI_THRESH_MASK)
#define MCI_INTERRUPT_RAW_BT_PRI_THRESH_RESET                        0
#define MCI_INTERRUPT_RAW_BT_PRI_MSB                                 26
#define MCI_INTERRUPT_RAW_BT_PRI_LSB                                 11
#define MCI_INTERRUPT_RAW_BT_PRI_MASK                                0x07fff800
#define MCI_INTERRUPT_RAW_BT_PRI_GET(x)                              (((x) & MCI_INTERRUPT_RAW_BT_PRI_MASK) >> MCI_INTERRUPT_RAW_BT_PRI_LSB)
#define MCI_INTERRUPT_RAW_BT_PRI_SET(x)                              (((0 | (x)) << MCI_INTERRUPT_RAW_BT_PRI_LSB) & MCI_INTERRUPT_RAW_BT_PRI_MASK)
#define MCI_INTERRUPT_RAW_BT_PRI_RESET                               0
#define MCI_INTERRUPT_RAW_REMOTE_SLEEP_UPDATE_MSB                    10
#define MCI_INTERRUPT_RAW_REMOTE_SLEEP_UPDATE_LSB                    10
#define MCI_INTERRUPT_RAW_REMOTE_SLEEP_UPDATE_MASK                   0x00000400
#define MCI_INTERRUPT_RAW_REMOTE_SLEEP_UPDATE_GET(x)                 (((x) & MCI_INTERRUPT_RAW_REMOTE_SLEEP_UPDATE_MASK) >> MCI_INTERRUPT_RAW_REMOTE_SLEEP_UPDATE_LSB)
#define MCI_INTERRUPT_RAW_REMOTE_SLEEP_UPDATE_SET(x)                 (((0 | (x)) << MCI_INTERRUPT_RAW_REMOTE_SLEEP_UPDATE_LSB) & MCI_INTERRUPT_RAW_REMOTE_SLEEP_UPDATE_MASK)
#define MCI_INTERRUPT_RAW_REMOTE_SLEEP_UPDATE_RESET                  0
#define MCI_INTERRUPT_RAW_RX_MSG_MSB                                 9
#define MCI_INTERRUPT_RAW_RX_MSG_LSB                                 9
#define MCI_INTERRUPT_RAW_RX_MSG_MASK                                0x00000200
#define MCI_INTERRUPT_RAW_RX_MSG_GET(x)                              (((x) & MCI_INTERRUPT_RAW_RX_MSG_MASK) >> MCI_INTERRUPT_RAW_RX_MSG_LSB)
#define MCI_INTERRUPT_RAW_RX_MSG_SET(x)                              (((0 | (x)) << MCI_INTERRUPT_RAW_RX_MSG_LSB) & MCI_INTERRUPT_RAW_RX_MSG_MASK)
#define MCI_INTERRUPT_RAW_RX_MSG_RESET                               0
#define MCI_INTERRUPT_RAW_TX_SW_MSG_FAIL_MSB                         8
#define MCI_INTERRUPT_RAW_TX_SW_MSG_FAIL_LSB                         8
#define MCI_INTERRUPT_RAW_TX_SW_MSG_FAIL_MASK                        0x00000100
#define MCI_INTERRUPT_RAW_TX_SW_MSG_FAIL_GET(x)                      (((x) & MCI_INTERRUPT_RAW_TX_SW_MSG_FAIL_MASK) >> MCI_INTERRUPT_RAW_TX_SW_MSG_FAIL_LSB)
#define MCI_INTERRUPT_RAW_TX_SW_MSG_FAIL_SET(x)                      (((0 | (x)) << MCI_INTERRUPT_RAW_TX_SW_MSG_FAIL_LSB) & MCI_INTERRUPT_RAW_TX_SW_MSG_FAIL_MASK)
#define MCI_INTERRUPT_RAW_TX_SW_MSG_FAIL_RESET                       0
#define MCI_INTERRUPT_RAW_TX_HW_MSG_FAIL_MSB                         7
#define MCI_INTERRUPT_RAW_TX_HW_MSG_FAIL_LSB                         7
#define MCI_INTERRUPT_RAW_TX_HW_MSG_FAIL_MASK                        0x00000080
#define MCI_INTERRUPT_RAW_TX_HW_MSG_FAIL_GET(x)                      (((x) & MCI_INTERRUPT_RAW_TX_HW_MSG_FAIL_MASK) >> MCI_INTERRUPT_RAW_TX_HW_MSG_FAIL_LSB)
#define MCI_INTERRUPT_RAW_TX_HW_MSG_FAIL_SET(x)                      (((0 | (x)) << MCI_INTERRUPT_RAW_TX_HW_MSG_FAIL_LSB) & MCI_INTERRUPT_RAW_TX_HW_MSG_FAIL_MASK)
#define MCI_INTERRUPT_RAW_TX_HW_MSG_FAIL_RESET                       0
#define MCI_INTERRUPT_RAW_RX_ILLEGAL_HDR_MSB                         6
#define MCI_INTERRUPT_RAW_RX_ILLEGAL_HDR_LSB                         6
#define MCI_INTERRUPT_RAW_RX_ILLEGAL_HDR_MASK                        0x00000040
#define MCI_INTERRUPT_RAW_RX_ILLEGAL_HDR_GET(x)                      (((x) & MCI_INTERRUPT_RAW_RX_ILLEGAL_HDR_MASK) >> MCI_INTERRUPT_RAW_RX_ILLEGAL_HDR_LSB)
#define MCI_INTERRUPT_RAW_RX_ILLEGAL_HDR_SET(x)                      (((0 | (x)) << MCI_INTERRUPT_RAW_RX_ILLEGAL_HDR_LSB) & MCI_INTERRUPT_RAW_RX_ILLEGAL_HDR_MASK)
#define MCI_INTERRUPT_RAW_RX_ILLEGAL_HDR_RESET                       0
#define MCI_INTERRUPT_RAW_RX_SW_MSG_FAIL_MSB                         5
#define MCI_INTERRUPT_RAW_RX_SW_MSG_FAIL_LSB                         5
#define MCI_INTERRUPT_RAW_RX_SW_MSG_FAIL_MASK                        0x00000020
#define MCI_INTERRUPT_RAW_RX_SW_MSG_FAIL_GET(x)                      (((x) & MCI_INTERRUPT_RAW_RX_SW_MSG_FAIL_MASK) >> MCI_INTERRUPT_RAW_RX_SW_MSG_FAIL_LSB)
#define MCI_INTERRUPT_RAW_RX_SW_MSG_FAIL_SET(x)                      (((0 | (x)) << MCI_INTERRUPT_RAW_RX_SW_MSG_FAIL_LSB) & MCI_INTERRUPT_RAW_RX_SW_MSG_FAIL_MASK)
#define MCI_INTERRUPT_RAW_RX_SW_MSG_FAIL_RESET                       0
#define MCI_INTERRUPT_RAW_RX_HW_MSG_FAIL_MSB                         4
#define MCI_INTERRUPT_RAW_RX_HW_MSG_FAIL_LSB                         4
#define MCI_INTERRUPT_RAW_RX_HW_MSG_FAIL_MASK                        0x00000010
#define MCI_INTERRUPT_RAW_RX_HW_MSG_FAIL_GET(x)                      (((x) & MCI_INTERRUPT_RAW_RX_HW_MSG_FAIL_MASK) >> MCI_INTERRUPT_RAW_RX_HW_MSG_FAIL_LSB)
#define MCI_INTERRUPT_RAW_RX_HW_MSG_FAIL_SET(x)                      (((0 | (x)) << MCI_INTERRUPT_RAW_RX_HW_MSG_FAIL_LSB) & MCI_INTERRUPT_RAW_RX_HW_MSG_FAIL_MASK)
#define MCI_INTERRUPT_RAW_RX_HW_MSG_FAIL_RESET                       0
#define MCI_INTERRUPT_RAW_RX_INVALID_HDR_MSB                         3
#define MCI_INTERRUPT_RAW_RX_INVALID_HDR_LSB                         3
#define MCI_INTERRUPT_RAW_RX_INVALID_HDR_MASK                        0x00000008
#define MCI_INTERRUPT_RAW_RX_INVALID_HDR_GET(x)                      (((x) & MCI_INTERRUPT_RAW_RX_INVALID_HDR_MASK) >> MCI_INTERRUPT_RAW_RX_INVALID_HDR_LSB)
#define MCI_INTERRUPT_RAW_RX_INVALID_HDR_SET(x)                      (((0 | (x)) << MCI_INTERRUPT_RAW_RX_INVALID_HDR_LSB) & MCI_INTERRUPT_RAW_RX_INVALID_HDR_MASK)
#define MCI_INTERRUPT_RAW_RX_INVALID_HDR_RESET                       0
#define MCI_INTERRUPT_RAW_RX_CKSUM_FAIL_MSB                          2
#define MCI_INTERRUPT_RAW_RX_CKSUM_FAIL_LSB                          2
#define MCI_INTERRUPT_RAW_RX_CKSUM_FAIL_MASK                         0x00000004
#define MCI_INTERRUPT_RAW_RX_CKSUM_FAIL_GET(x)                       (((x) & MCI_INTERRUPT_RAW_RX_CKSUM_FAIL_MASK) >> MCI_INTERRUPT_RAW_RX_CKSUM_FAIL_LSB)
#define MCI_INTERRUPT_RAW_RX_CKSUM_FAIL_SET(x)                       (((0 | (x)) << MCI_INTERRUPT_RAW_RX_CKSUM_FAIL_LSB) & MCI_INTERRUPT_RAW_RX_CKSUM_FAIL_MASK)
#define MCI_INTERRUPT_RAW_RX_CKSUM_FAIL_RESET                        0
#define MCI_INTERRUPT_RAW_CPU_INT_MSG_MSB                            1
#define MCI_INTERRUPT_RAW_CPU_INT_MSG_LSB                            1
#define MCI_INTERRUPT_RAW_CPU_INT_MSG_MASK                           0x00000002
#define MCI_INTERRUPT_RAW_CPU_INT_MSG_GET(x)                         (((x) & MCI_INTERRUPT_RAW_CPU_INT_MSG_MASK) >> MCI_INTERRUPT_RAW_CPU_INT_MSG_LSB)
#define MCI_INTERRUPT_RAW_CPU_INT_MSG_SET(x)                         (((0 | (x)) << MCI_INTERRUPT_RAW_CPU_INT_MSG_LSB) & MCI_INTERRUPT_RAW_CPU_INT_MSG_MASK)
#define MCI_INTERRUPT_RAW_CPU_INT_MSG_RESET                          0
#define MCI_INTERRUPT_RAW_SW_MSG_DONE_MSB                            0
#define MCI_INTERRUPT_RAW_SW_MSG_DONE_LSB                            0
#define MCI_INTERRUPT_RAW_SW_MSG_DONE_MASK                           0x00000001
#define MCI_INTERRUPT_RAW_SW_MSG_DONE_GET(x)                         (((x) & MCI_INTERRUPT_RAW_SW_MSG_DONE_MASK) >> MCI_INTERRUPT_RAW_SW_MSG_DONE_LSB)
#define MCI_INTERRUPT_RAW_SW_MSG_DONE_SET(x)                         (((0 | (x)) << MCI_INTERRUPT_RAW_SW_MSG_DONE_LSB) & MCI_INTERRUPT_RAW_SW_MSG_DONE_MASK)
#define MCI_INTERRUPT_RAW_SW_MSG_DONE_RESET                          0
#define MCI_INTERRUPT_RAW_ADDRESS                                    0x0028
#define MCI_INTERRUPT_RAW_HW_MASK                                    0xffffffff
#define MCI_INTERRUPT_RAW_SW_MASK                                    0xffffffff
#define MCI_INTERRUPT_RAW_HW_WRITE_MASK                              0xffffffff
#define MCI_INTERRUPT_RAW_SW_WRITE_MASK                              0xffffffff
#define MCI_INTERRUPT_RAW_RSTMASK                                    0xffffffff
#define MCI_INTERRUPT_RAW_RESET                                      0x00000000

// 0x002c (MCI_INTERRUPT_EN)
#define MCI_INTERRUPT_EN_CONT_INFO_TIMEOUT_MSB                       31
#define MCI_INTERRUPT_EN_CONT_INFO_TIMEOUT_LSB                       31
#define MCI_INTERRUPT_EN_CONT_INFO_TIMEOUT_MASK                      0x80000000
#define MCI_INTERRUPT_EN_CONT_INFO_TIMEOUT_GET(x)                    (((x) & MCI_INTERRUPT_EN_CONT_INFO_TIMEOUT_MASK) >> MCI_INTERRUPT_EN_CONT_INFO_TIMEOUT_LSB)
#define MCI_INTERRUPT_EN_CONT_INFO_TIMEOUT_SET(x)                    (((0 | (x)) << MCI_INTERRUPT_EN_CONT_INFO_TIMEOUT_LSB) & MCI_INTERRUPT_EN_CONT_INFO_TIMEOUT_MASK)
#define MCI_INTERRUPT_EN_CONT_INFO_TIMEOUT_RESET                     0
#define MCI_INTERRUPT_EN_BB_AIC_IRQ_MSB                              30
#define MCI_INTERRUPT_EN_BB_AIC_IRQ_LSB                              30
#define MCI_INTERRUPT_EN_BB_AIC_IRQ_MASK                             0x40000000
#define MCI_INTERRUPT_EN_BB_AIC_IRQ_GET(x)                           (((x) & MCI_INTERRUPT_EN_BB_AIC_IRQ_MASK) >> MCI_INTERRUPT_EN_BB_AIC_IRQ_LSB)
#define MCI_INTERRUPT_EN_BB_AIC_IRQ_SET(x)                           (((0 | (x)) << MCI_INTERRUPT_EN_BB_AIC_IRQ_LSB) & MCI_INTERRUPT_EN_BB_AIC_IRQ_MASK)
#define MCI_INTERRUPT_EN_BB_AIC_IRQ_RESET                            0
#define MCI_INTERRUPT_EN_BT_STOMP_MSB                                29
#define MCI_INTERRUPT_EN_BT_STOMP_LSB                                29
#define MCI_INTERRUPT_EN_BT_STOMP_MASK                               0x20000000
#define MCI_INTERRUPT_EN_BT_STOMP_GET(x)                             (((x) & MCI_INTERRUPT_EN_BT_STOMP_MASK) >> MCI_INTERRUPT_EN_BT_STOMP_LSB)
#define MCI_INTERRUPT_EN_BT_STOMP_SET(x)                             (((0 | (x)) << MCI_INTERRUPT_EN_BT_STOMP_LSB) & MCI_INTERRUPT_EN_BT_STOMP_MASK)
#define MCI_INTERRUPT_EN_BT_STOMP_RESET                              0
#define MCI_INTERRUPT_EN_BT_FREQ_MSB                                 28
#define MCI_INTERRUPT_EN_BT_FREQ_LSB                                 28
#define MCI_INTERRUPT_EN_BT_FREQ_MASK                                0x10000000
#define MCI_INTERRUPT_EN_BT_FREQ_GET(x)                              (((x) & MCI_INTERRUPT_EN_BT_FREQ_MASK) >> MCI_INTERRUPT_EN_BT_FREQ_LSB)
#define MCI_INTERRUPT_EN_BT_FREQ_SET(x)                              (((0 | (x)) << MCI_INTERRUPT_EN_BT_FREQ_LSB) & MCI_INTERRUPT_EN_BT_FREQ_MASK)
#define MCI_INTERRUPT_EN_BT_FREQ_RESET                               0
#define MCI_INTERRUPT_EN_BT_PRI_THRESH_MSB                           27
#define MCI_INTERRUPT_EN_BT_PRI_THRESH_LSB                           27
#define MCI_INTERRUPT_EN_BT_PRI_THRESH_MASK                          0x08000000
#define MCI_INTERRUPT_EN_BT_PRI_THRESH_GET(x)                        (((x) & MCI_INTERRUPT_EN_BT_PRI_THRESH_MASK) >> MCI_INTERRUPT_EN_BT_PRI_THRESH_LSB)
#define MCI_INTERRUPT_EN_BT_PRI_THRESH_SET(x)                        (((0 | (x)) << MCI_INTERRUPT_EN_BT_PRI_THRESH_LSB) & MCI_INTERRUPT_EN_BT_PRI_THRESH_MASK)
#define MCI_INTERRUPT_EN_BT_PRI_THRESH_RESET                         0
#define MCI_INTERRUPT_EN_BT_PRI_MSB                                  26
#define MCI_INTERRUPT_EN_BT_PRI_LSB                                  11
#define MCI_INTERRUPT_EN_BT_PRI_MASK                                 0x07fff800
#define MCI_INTERRUPT_EN_BT_PRI_GET(x)                               (((x) & MCI_INTERRUPT_EN_BT_PRI_MASK) >> MCI_INTERRUPT_EN_BT_PRI_LSB)
#define MCI_INTERRUPT_EN_BT_PRI_SET(x)                               (((0 | (x)) << MCI_INTERRUPT_EN_BT_PRI_LSB) & MCI_INTERRUPT_EN_BT_PRI_MASK)
#define MCI_INTERRUPT_EN_BT_PRI_RESET                                0
#define MCI_INTERRUPT_EN_REMOTE_SLEEP_UPDATE_MSB                     10
#define MCI_INTERRUPT_EN_REMOTE_SLEEP_UPDATE_LSB                     10
#define MCI_INTERRUPT_EN_REMOTE_SLEEP_UPDATE_MASK                    0x00000400
#define MCI_INTERRUPT_EN_REMOTE_SLEEP_UPDATE_GET(x)                  (((x) & MCI_INTERRUPT_EN_REMOTE_SLEEP_UPDATE_MASK) >> MCI_INTERRUPT_EN_REMOTE_SLEEP_UPDATE_LSB)
#define MCI_INTERRUPT_EN_REMOTE_SLEEP_UPDATE_SET(x)                  (((0 | (x)) << MCI_INTERRUPT_EN_REMOTE_SLEEP_UPDATE_LSB) & MCI_INTERRUPT_EN_REMOTE_SLEEP_UPDATE_MASK)
#define MCI_INTERRUPT_EN_REMOTE_SLEEP_UPDATE_RESET                   0
#define MCI_INTERRUPT_EN_RX_MSG_MSB                                  9
#define MCI_INTERRUPT_EN_RX_MSG_LSB                                  9
#define MCI_INTERRUPT_EN_RX_MSG_MASK                                 0x00000200
#define MCI_INTERRUPT_EN_RX_MSG_GET(x)                               (((x) & MCI_INTERRUPT_EN_RX_MSG_MASK) >> MCI_INTERRUPT_EN_RX_MSG_LSB)
#define MCI_INTERRUPT_EN_RX_MSG_SET(x)                               (((0 | (x)) << MCI_INTERRUPT_EN_RX_MSG_LSB) & MCI_INTERRUPT_EN_RX_MSG_MASK)
#define MCI_INTERRUPT_EN_RX_MSG_RESET                                0
#define MCI_INTERRUPT_EN_TX_SW_MSG_FAIL_MSB                          8
#define MCI_INTERRUPT_EN_TX_SW_MSG_FAIL_LSB                          8
#define MCI_INTERRUPT_EN_TX_SW_MSG_FAIL_MASK                         0x00000100
#define MCI_INTERRUPT_EN_TX_SW_MSG_FAIL_GET(x)                       (((x) & MCI_INTERRUPT_EN_TX_SW_MSG_FAIL_MASK) >> MCI_INTERRUPT_EN_TX_SW_MSG_FAIL_LSB)
#define MCI_INTERRUPT_EN_TX_SW_MSG_FAIL_SET(x)                       (((0 | (x)) << MCI_INTERRUPT_EN_TX_SW_MSG_FAIL_LSB) & MCI_INTERRUPT_EN_TX_SW_MSG_FAIL_MASK)
#define MCI_INTERRUPT_EN_TX_SW_MSG_FAIL_RESET                        0
#define MCI_INTERRUPT_EN_TX_HW_MSG_FAIL_MSB                          7
#define MCI_INTERRUPT_EN_TX_HW_MSG_FAIL_LSB                          7
#define MCI_INTERRUPT_EN_TX_HW_MSG_FAIL_MASK                         0x00000080
#define MCI_INTERRUPT_EN_TX_HW_MSG_FAIL_GET(x)                       (((x) & MCI_INTERRUPT_EN_TX_HW_MSG_FAIL_MASK) >> MCI_INTERRUPT_EN_TX_HW_MSG_FAIL_LSB)
#define MCI_INTERRUPT_EN_TX_HW_MSG_FAIL_SET(x)                       (((0 | (x)) << MCI_INTERRUPT_EN_TX_HW_MSG_FAIL_LSB) & MCI_INTERRUPT_EN_TX_HW_MSG_FAIL_MASK)
#define MCI_INTERRUPT_EN_TX_HW_MSG_FAIL_RESET                        0
#define MCI_INTERRUPT_EN_RX_ILLEGAL_HDR_MSB                          6
#define MCI_INTERRUPT_EN_RX_ILLEGAL_HDR_LSB                          6
#define MCI_INTERRUPT_EN_RX_ILLEGAL_HDR_MASK                         0x00000040
#define MCI_INTERRUPT_EN_RX_ILLEGAL_HDR_GET(x)                       (((x) & MCI_INTERRUPT_EN_RX_ILLEGAL_HDR_MASK) >> MCI_INTERRUPT_EN_RX_ILLEGAL_HDR_LSB)
#define MCI_INTERRUPT_EN_RX_ILLEGAL_HDR_SET(x)                       (((0 | (x)) << MCI_INTERRUPT_EN_RX_ILLEGAL_HDR_LSB) & MCI_INTERRUPT_EN_RX_ILLEGAL_HDR_MASK)
#define MCI_INTERRUPT_EN_RX_ILLEGAL_HDR_RESET                        0
#define MCI_INTERRUPT_EN_RX_SW_MSG_FAIL_MSB                          5
#define MCI_INTERRUPT_EN_RX_SW_MSG_FAIL_LSB                          5
#define MCI_INTERRUPT_EN_RX_SW_MSG_FAIL_MASK                         0x00000020
#define MCI_INTERRUPT_EN_RX_SW_MSG_FAIL_GET(x)                       (((x) & MCI_INTERRUPT_EN_RX_SW_MSG_FAIL_MASK) >> MCI_INTERRUPT_EN_RX_SW_MSG_FAIL_LSB)
#define MCI_INTERRUPT_EN_RX_SW_MSG_FAIL_SET(x)                       (((0 | (x)) << MCI_INTERRUPT_EN_RX_SW_MSG_FAIL_LSB) & MCI_INTERRUPT_EN_RX_SW_MSG_FAIL_MASK)
#define MCI_INTERRUPT_EN_RX_SW_MSG_FAIL_RESET                        0
#define MCI_INTERRUPT_EN_RX_HW_MSG_FAIL_MSB                          4
#define MCI_INTERRUPT_EN_RX_HW_MSG_FAIL_LSB                          4
#define MCI_INTERRUPT_EN_RX_HW_MSG_FAIL_MASK                         0x00000010
#define MCI_INTERRUPT_EN_RX_HW_MSG_FAIL_GET(x)                       (((x) & MCI_INTERRUPT_EN_RX_HW_MSG_FAIL_MASK) >> MCI_INTERRUPT_EN_RX_HW_MSG_FAIL_LSB)
#define MCI_INTERRUPT_EN_RX_HW_MSG_FAIL_SET(x)                       (((0 | (x)) << MCI_INTERRUPT_EN_RX_HW_MSG_FAIL_LSB) & MCI_INTERRUPT_EN_RX_HW_MSG_FAIL_MASK)
#define MCI_INTERRUPT_EN_RX_HW_MSG_FAIL_RESET                        0
#define MCI_INTERRUPT_EN_RX_INVALID_HDR_MSB                          3
#define MCI_INTERRUPT_EN_RX_INVALID_HDR_LSB                          3
#define MCI_INTERRUPT_EN_RX_INVALID_HDR_MASK                         0x00000008
#define MCI_INTERRUPT_EN_RX_INVALID_HDR_GET(x)                       (((x) & MCI_INTERRUPT_EN_RX_INVALID_HDR_MASK) >> MCI_INTERRUPT_EN_RX_INVALID_HDR_LSB)
#define MCI_INTERRUPT_EN_RX_INVALID_HDR_SET(x)                       (((0 | (x)) << MCI_INTERRUPT_EN_RX_INVALID_HDR_LSB) & MCI_INTERRUPT_EN_RX_INVALID_HDR_MASK)
#define MCI_INTERRUPT_EN_RX_INVALID_HDR_RESET                        0
#define MCI_INTERRUPT_EN_RX_CKSUM_FAIL_MSB                           2
#define MCI_INTERRUPT_EN_RX_CKSUM_FAIL_LSB                           2
#define MCI_INTERRUPT_EN_RX_CKSUM_FAIL_MASK                          0x00000004
#define MCI_INTERRUPT_EN_RX_CKSUM_FAIL_GET(x)                        (((x) & MCI_INTERRUPT_EN_RX_CKSUM_FAIL_MASK) >> MCI_INTERRUPT_EN_RX_CKSUM_FAIL_LSB)
#define MCI_INTERRUPT_EN_RX_CKSUM_FAIL_SET(x)                        (((0 | (x)) << MCI_INTERRUPT_EN_RX_CKSUM_FAIL_LSB) & MCI_INTERRUPT_EN_RX_CKSUM_FAIL_MASK)
#define MCI_INTERRUPT_EN_RX_CKSUM_FAIL_RESET                         0
#define MCI_INTERRUPT_EN_CPU_INT_MSG_MSB                             1
#define MCI_INTERRUPT_EN_CPU_INT_MSG_LSB                             1
#define MCI_INTERRUPT_EN_CPU_INT_MSG_MASK                            0x00000002
#define MCI_INTERRUPT_EN_CPU_INT_MSG_GET(x)                          (((x) & MCI_INTERRUPT_EN_CPU_INT_MSG_MASK) >> MCI_INTERRUPT_EN_CPU_INT_MSG_LSB)
#define MCI_INTERRUPT_EN_CPU_INT_MSG_SET(x)                          (((0 | (x)) << MCI_INTERRUPT_EN_CPU_INT_MSG_LSB) & MCI_INTERRUPT_EN_CPU_INT_MSG_MASK)
#define MCI_INTERRUPT_EN_CPU_INT_MSG_RESET                           0
#define MCI_INTERRUPT_EN_SW_MSG_DONE_MSB                             0
#define MCI_INTERRUPT_EN_SW_MSG_DONE_LSB                             0
#define MCI_INTERRUPT_EN_SW_MSG_DONE_MASK                            0x00000001
#define MCI_INTERRUPT_EN_SW_MSG_DONE_GET(x)                          (((x) & MCI_INTERRUPT_EN_SW_MSG_DONE_MASK) >> MCI_INTERRUPT_EN_SW_MSG_DONE_LSB)
#define MCI_INTERRUPT_EN_SW_MSG_DONE_SET(x)                          (((0 | (x)) << MCI_INTERRUPT_EN_SW_MSG_DONE_LSB) & MCI_INTERRUPT_EN_SW_MSG_DONE_MASK)
#define MCI_INTERRUPT_EN_SW_MSG_DONE_RESET                           0
#define MCI_INTERRUPT_EN_ADDRESS                                     0x002c
#define MCI_INTERRUPT_EN_HW_MASK                                     0xffffffff
#define MCI_INTERRUPT_EN_SW_MASK                                     0xffffffff
#define MCI_INTERRUPT_EN_HW_WRITE_MASK                               0x00000000
#define MCI_INTERRUPT_EN_SW_WRITE_MASK                               0xffffffff
#define MCI_INTERRUPT_EN_RSTMASK                                     0xffffffff
#define MCI_INTERRUPT_EN_RESET                                       0x00000000

// 0x0030 (MCI_REMOTE_CPU_INT)
#define MCI_REMOTE_CPU_INT_BODY_MSB                                  31
#define MCI_REMOTE_CPU_INT_BODY_LSB                                  0
#define MCI_REMOTE_CPU_INT_BODY_MASK                                 0xffffffff
#define MCI_REMOTE_CPU_INT_BODY_GET(x)                               (((x) & MCI_REMOTE_CPU_INT_BODY_MASK) >> MCI_REMOTE_CPU_INT_BODY_LSB)
#define MCI_REMOTE_CPU_INT_BODY_SET(x)                               (((0 | (x)) << MCI_REMOTE_CPU_INT_BODY_LSB) & MCI_REMOTE_CPU_INT_BODY_MASK)
#define MCI_REMOTE_CPU_INT_BODY_RESET                                0
#define MCI_REMOTE_CPU_INT_ADDRESS                                   0x0030
#define MCI_REMOTE_CPU_INT_HW_MASK                                   0xffffffff
#define MCI_REMOTE_CPU_INT_SW_MASK                                   0xffffffff
#define MCI_REMOTE_CPU_INT_HW_WRITE_MASK                             0x00000000
#define MCI_REMOTE_CPU_INT_SW_WRITE_MASK                             0xffffffff
#define MCI_REMOTE_CPU_INT_RSTMASK                                   0xffffffff
#define MCI_REMOTE_CPU_INT_RESET                                     0x00000000

// 0x0034 (MCI_REMOTE_CPU_INT_EN)
#define MCI_REMOTE_CPU_INT_EN_BODY_MSB                               31
#define MCI_REMOTE_CPU_INT_EN_BODY_LSB                               0
#define MCI_REMOTE_CPU_INT_EN_BODY_MASK                              0xffffffff
#define MCI_REMOTE_CPU_INT_EN_BODY_GET(x)                            (((x) & MCI_REMOTE_CPU_INT_EN_BODY_MASK) >> MCI_REMOTE_CPU_INT_EN_BODY_LSB)
#define MCI_REMOTE_CPU_INT_EN_BODY_SET(x)                            (((0 | (x)) << MCI_REMOTE_CPU_INT_EN_BODY_LSB) & MCI_REMOTE_CPU_INT_EN_BODY_MASK)
#define MCI_REMOTE_CPU_INT_EN_BODY_RESET                             4294967295
#define MCI_REMOTE_CPU_INT_EN_ADDRESS                                0x0034
#define MCI_REMOTE_CPU_INT_EN_HW_MASK                                0xffffffff
#define MCI_REMOTE_CPU_INT_EN_SW_MASK                                0xffffffff
#define MCI_REMOTE_CPU_INT_EN_HW_WRITE_MASK                          0x00000000
#define MCI_REMOTE_CPU_INT_EN_SW_WRITE_MASK                          0xffffffff
#define MCI_REMOTE_CPU_INT_EN_RSTMASK                                0xffffffff
#define MCI_REMOTE_CPU_INT_EN_RESET                                  0xffffffff

// 0x0038 (MCI_INTERRUPT_RX_MSG_RAW)
#define MCI_INTERRUPT_RX_MSG_RAW_REQ_WAKE_MSB                        12
#define MCI_INTERRUPT_RX_MSG_RAW_REQ_WAKE_LSB                        12
#define MCI_INTERRUPT_RX_MSG_RAW_REQ_WAKE_MASK                       0x00001000
#define MCI_INTERRUPT_RX_MSG_RAW_REQ_WAKE_GET(x)                     (((x) & MCI_INTERRUPT_RX_MSG_RAW_REQ_WAKE_MASK) >> MCI_INTERRUPT_RX_MSG_RAW_REQ_WAKE_LSB)
#define MCI_INTERRUPT_RX_MSG_RAW_REQ_WAKE_SET(x)                     (((0 | (x)) << MCI_INTERRUPT_RX_MSG_RAW_REQ_WAKE_LSB) & MCI_INTERRUPT_RX_MSG_RAW_REQ_WAKE_MASK)
#define MCI_INTERRUPT_RX_MSG_RAW_REQ_WAKE_RESET                      0
#define MCI_INTERRUPT_RX_MSG_RAW_SYS_WAKING_MSB                      11
#define MCI_INTERRUPT_RX_MSG_RAW_SYS_WAKING_LSB                      11
#define MCI_INTERRUPT_RX_MSG_RAW_SYS_WAKING_MASK                     0x00000800
#define MCI_INTERRUPT_RX_MSG_RAW_SYS_WAKING_GET(x)                   (((x) & MCI_INTERRUPT_RX_MSG_RAW_SYS_WAKING_MASK) >> MCI_INTERRUPT_RX_MSG_RAW_SYS_WAKING_LSB)
#define MCI_INTERRUPT_RX_MSG_RAW_SYS_WAKING_SET(x)                   (((0 | (x)) << MCI_INTERRUPT_RX_MSG_RAW_SYS_WAKING_LSB) & MCI_INTERRUPT_RX_MSG_RAW_SYS_WAKING_MASK)
#define MCI_INTERRUPT_RX_MSG_RAW_SYS_WAKING_RESET                    0
#define MCI_INTERRUPT_RX_MSG_RAW_SYS_SLEEPING_MSB                    10
#define MCI_INTERRUPT_RX_MSG_RAW_SYS_SLEEPING_LSB                    10
#define MCI_INTERRUPT_RX_MSG_RAW_SYS_SLEEPING_MASK                   0x00000400
#define MCI_INTERRUPT_RX_MSG_RAW_SYS_SLEEPING_GET(x)                 (((x) & MCI_INTERRUPT_RX_MSG_RAW_SYS_SLEEPING_MASK) >> MCI_INTERRUPT_RX_MSG_RAW_SYS_SLEEPING_LSB)
#define MCI_INTERRUPT_RX_MSG_RAW_SYS_SLEEPING_SET(x)                 (((0 | (x)) << MCI_INTERRUPT_RX_MSG_RAW_SYS_SLEEPING_LSB) & MCI_INTERRUPT_RX_MSG_RAW_SYS_SLEEPING_MASK)
#define MCI_INTERRUPT_RX_MSG_RAW_SYS_SLEEPING_RESET                  0
#define MCI_INTERRUPT_RX_MSG_RAW_LNA_INFO_MSB                        9
#define MCI_INTERRUPT_RX_MSG_RAW_LNA_INFO_LSB                        9
#define MCI_INTERRUPT_RX_MSG_RAW_LNA_INFO_MASK                       0x00000200
#define MCI_INTERRUPT_RX_MSG_RAW_LNA_INFO_GET(x)                     (((x) & MCI_INTERRUPT_RX_MSG_RAW_LNA_INFO_MASK) >> MCI_INTERRUPT_RX_MSG_RAW_LNA_INFO_LSB)
#define MCI_INTERRUPT_RX_MSG_RAW_LNA_INFO_SET(x)                     (((0 | (x)) << MCI_INTERRUPT_RX_MSG_RAW_LNA_INFO_LSB) & MCI_INTERRUPT_RX_MSG_RAW_LNA_INFO_MASK)
#define MCI_INTERRUPT_RX_MSG_RAW_LNA_INFO_RESET                      0
#define MCI_INTERRUPT_RX_MSG_RAW_GPM_MSB                             8
#define MCI_INTERRUPT_RX_MSG_RAW_GPM_LSB                             8
#define MCI_INTERRUPT_RX_MSG_RAW_GPM_MASK                            0x00000100
#define MCI_INTERRUPT_RX_MSG_RAW_GPM_GET(x)                          (((x) & MCI_INTERRUPT_RX_MSG_RAW_GPM_MASK) >> MCI_INTERRUPT_RX_MSG_RAW_GPM_LSB)
#define MCI_INTERRUPT_RX_MSG_RAW_GPM_SET(x)                          (((0 | (x)) << MCI_INTERRUPT_RX_MSG_RAW_GPM_LSB) & MCI_INTERRUPT_RX_MSG_RAW_GPM_MASK)
#define MCI_INTERRUPT_RX_MSG_RAW_GPM_RESET                           0
#define MCI_INTERRUPT_RX_MSG_RAW_CPU_INT_MSB                         6
#define MCI_INTERRUPT_RX_MSG_RAW_CPU_INT_LSB                         6
#define MCI_INTERRUPT_RX_MSG_RAW_CPU_INT_MASK                        0x00000040
#define MCI_INTERRUPT_RX_MSG_RAW_CPU_INT_GET(x)                      (((x) & MCI_INTERRUPT_RX_MSG_RAW_CPU_INT_MASK) >> MCI_INTERRUPT_RX_MSG_RAW_CPU_INT_LSB)
#define MCI_INTERRUPT_RX_MSG_RAW_CPU_INT_SET(x)                      (((0 | (x)) << MCI_INTERRUPT_RX_MSG_RAW_CPU_INT_LSB) & MCI_INTERRUPT_RX_MSG_RAW_CPU_INT_MASK)
#define MCI_INTERRUPT_RX_MSG_RAW_CPU_INT_RESET                       0
#define MCI_INTERRUPT_RX_MSG_RAW_SCHD_INFO_MSB                       5
#define MCI_INTERRUPT_RX_MSG_RAW_SCHD_INFO_LSB                       5
#define MCI_INTERRUPT_RX_MSG_RAW_SCHD_INFO_MASK                      0x00000020
#define MCI_INTERRUPT_RX_MSG_RAW_SCHD_INFO_GET(x)                    (((x) & MCI_INTERRUPT_RX_MSG_RAW_SCHD_INFO_MASK) >> MCI_INTERRUPT_RX_MSG_RAW_SCHD_INFO_LSB)
#define MCI_INTERRUPT_RX_MSG_RAW_SCHD_INFO_SET(x)                    (((0 | (x)) << MCI_INTERRUPT_RX_MSG_RAW_SCHD_INFO_LSB) & MCI_INTERRUPT_RX_MSG_RAW_SCHD_INFO_MASK)
#define MCI_INTERRUPT_RX_MSG_RAW_SCHD_INFO_RESET                     0
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_RST_MSB                        4
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_RST_LSB                        4
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_RST_MASK                       0x00000010
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_RST_GET(x)                     (((x) & MCI_INTERRUPT_RX_MSG_RAW_CONT_RST_MASK) >> MCI_INTERRUPT_RX_MSG_RAW_CONT_RST_LSB)
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_RST_SET(x)                     (((0 | (x)) << MCI_INTERRUPT_RX_MSG_RAW_CONT_RST_LSB) & MCI_INTERRUPT_RX_MSG_RAW_CONT_RST_MASK)
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_RST_RESET                      0
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_INFO_MSB                       3
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_INFO_LSB                       3
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_INFO_MASK                      0x00000008
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_INFO_GET(x)                    (((x) & MCI_INTERRUPT_RX_MSG_RAW_CONT_INFO_MASK) >> MCI_INTERRUPT_RX_MSG_RAW_CONT_INFO_LSB)
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_INFO_SET(x)                    (((0 | (x)) << MCI_INTERRUPT_RX_MSG_RAW_CONT_INFO_LSB) & MCI_INTERRUPT_RX_MSG_RAW_CONT_INFO_MASK)
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_INFO_RESET                     0
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_NACK_MSB                       2
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_NACK_LSB                       2
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_NACK_MASK                      0x00000004
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_NACK_GET(x)                    (((x) & MCI_INTERRUPT_RX_MSG_RAW_CONT_NACK_MASK) >> MCI_INTERRUPT_RX_MSG_RAW_CONT_NACK_LSB)
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_NACK_SET(x)                    (((0 | (x)) << MCI_INTERRUPT_RX_MSG_RAW_CONT_NACK_LSB) & MCI_INTERRUPT_RX_MSG_RAW_CONT_NACK_MASK)
#define MCI_INTERRUPT_RX_MSG_RAW_CONT_NACK_RESET                     0
#define MCI_INTERRUPT_RX_MSG_RAW_LNA_CTRL_MSB                        1
#define MCI_INTERRUPT_RX_MSG_RAW_LNA_CTRL_LSB                        1
#define MCI_INTERRUPT_RX_MSG_RAW_LNA_CTRL_MASK                       0x00000002
#define MCI_INTERRUPT_RX_MSG_RAW_LNA_CTRL_GET(x)                     (((x) & MCI_INTERRUPT_RX_MSG_RAW_LNA_CTRL_MASK) >> MCI_INTERRUPT_RX_MSG_RAW_LNA_CTRL_LSB)
#define MCI_INTERRUPT_RX_MSG_RAW_LNA_CTRL_SET(x)                     (((0 | (x)) << MCI_INTERRUPT_RX_MSG_RAW_LNA_CTRL_LSB) & MCI_INTERRUPT_RX_MSG_RAW_LNA_CTRL_MASK)
#define MCI_INTERRUPT_RX_MSG_RAW_LNA_CTRL_RESET                      0
#define MCI_INTERRUPT_RX_MSG_RAW_REMOTE_RESET_MSB                    0
#define MCI_INTERRUPT_RX_MSG_RAW_REMOTE_RESET_LSB                    0
#define MCI_INTERRUPT_RX_MSG_RAW_REMOTE_RESET_MASK                   0x00000001
#define MCI_INTERRUPT_RX_MSG_RAW_REMOTE_RESET_GET(x)                 (((x) & MCI_INTERRUPT_RX_MSG_RAW_REMOTE_RESET_MASK) >> MCI_INTERRUPT_RX_MSG_RAW_REMOTE_RESET_LSB)
#define MCI_INTERRUPT_RX_MSG_RAW_REMOTE_RESET_SET(x)                 (((0 | (x)) << MCI_INTERRUPT_RX_MSG_RAW_REMOTE_RESET_LSB) & MCI_INTERRUPT_RX_MSG_RAW_REMOTE_RESET_MASK)
#define MCI_INTERRUPT_RX_MSG_RAW_REMOTE_RESET_RESET                  0
#define MCI_INTERRUPT_RX_MSG_RAW_ADDRESS                             0x0038
#define MCI_INTERRUPT_RX_MSG_RAW_HW_MASK                             0x00001f7f
#define MCI_INTERRUPT_RX_MSG_RAW_SW_MASK                             0x00001f7f
#define MCI_INTERRUPT_RX_MSG_RAW_HW_WRITE_MASK                       0x00001f7f
#define MCI_INTERRUPT_RX_MSG_RAW_SW_WRITE_MASK                       0x00001f7f
#define MCI_INTERRUPT_RX_MSG_RAW_RSTMASK                             0xffffffff
#define MCI_INTERRUPT_RX_MSG_RAW_RESET                               0x00000000

// 0x003c (MCI_INTERRUPT_RX_MSG_EN)
#define MCI_INTERRUPT_RX_MSG_EN_REQ_WAKE_MSB                         12
#define MCI_INTERRUPT_RX_MSG_EN_REQ_WAKE_LSB                         12
#define MCI_INTERRUPT_RX_MSG_EN_REQ_WAKE_MASK                        0x00001000
#define MCI_INTERRUPT_RX_MSG_EN_REQ_WAKE_GET(x)                      (((x) & MCI_INTERRUPT_RX_MSG_EN_REQ_WAKE_MASK) >> MCI_INTERRUPT_RX_MSG_EN_REQ_WAKE_LSB)
#define MCI_INTERRUPT_RX_MSG_EN_REQ_WAKE_SET(x)                      (((0 | (x)) << MCI_INTERRUPT_RX_MSG_EN_REQ_WAKE_LSB) & MCI_INTERRUPT_RX_MSG_EN_REQ_WAKE_MASK)
#define MCI_INTERRUPT_RX_MSG_EN_REQ_WAKE_RESET                       0
#define MCI_INTERRUPT_RX_MSG_EN_SYS_WAKING_MSB                       11
#define MCI_INTERRUPT_RX_MSG_EN_SYS_WAKING_LSB                       11
#define MCI_INTERRUPT_RX_MSG_EN_SYS_WAKING_MASK                      0x00000800
#define MCI_INTERRUPT_RX_MSG_EN_SYS_WAKING_GET(x)                    (((x) & MCI_INTERRUPT_RX_MSG_EN_SYS_WAKING_MASK) >> MCI_INTERRUPT_RX_MSG_EN_SYS_WAKING_LSB)
#define MCI_INTERRUPT_RX_MSG_EN_SYS_WAKING_SET(x)                    (((0 | (x)) << MCI_INTERRUPT_RX_MSG_EN_SYS_WAKING_LSB) & MCI_INTERRUPT_RX_MSG_EN_SYS_WAKING_MASK)
#define MCI_INTERRUPT_RX_MSG_EN_SYS_WAKING_RESET                     0
#define MCI_INTERRUPT_RX_MSG_EN_SYS_SLEEPING_MSB                     10
#define MCI_INTERRUPT_RX_MSG_EN_SYS_SLEEPING_LSB                     10
#define MCI_INTERRUPT_RX_MSG_EN_SYS_SLEEPING_MASK                    0x00000400
#define MCI_INTERRUPT_RX_MSG_EN_SYS_SLEEPING_GET(x)                  (((x) & MCI_INTERRUPT_RX_MSG_EN_SYS_SLEEPING_MASK) >> MCI_INTERRUPT_RX_MSG_EN_SYS_SLEEPING_LSB)
#define MCI_INTERRUPT_RX_MSG_EN_SYS_SLEEPING_SET(x)                  (((0 | (x)) << MCI_INTERRUPT_RX_MSG_EN_SYS_SLEEPING_LSB) & MCI_INTERRUPT_RX_MSG_EN_SYS_SLEEPING_MASK)
#define MCI_INTERRUPT_RX_MSG_EN_SYS_SLEEPING_RESET                   0
#define MCI_INTERRUPT_RX_MSG_EN_LNA_INFO_MSB                         9
#define MCI_INTERRUPT_RX_MSG_EN_LNA_INFO_LSB                         9
#define MCI_INTERRUPT_RX_MSG_EN_LNA_INFO_MASK                        0x00000200
#define MCI_INTERRUPT_RX_MSG_EN_LNA_INFO_GET(x)                      (((x) & MCI_INTERRUPT_RX_MSG_EN_LNA_INFO_MASK) >> MCI_INTERRUPT_RX_MSG_EN_LNA_INFO_LSB)
#define MCI_INTERRUPT_RX_MSG_EN_LNA_INFO_SET(x)                      (((0 | (x)) << MCI_INTERRUPT_RX_MSG_EN_LNA_INFO_LSB) & MCI_INTERRUPT_RX_MSG_EN_LNA_INFO_MASK)
#define MCI_INTERRUPT_RX_MSG_EN_LNA_INFO_RESET                       0
#define MCI_INTERRUPT_RX_MSG_EN_GPM_MSB                              8
#define MCI_INTERRUPT_RX_MSG_EN_GPM_LSB                              8
#define MCI_INTERRUPT_RX_MSG_EN_GPM_MASK                             0x00000100
#define MCI_INTERRUPT_RX_MSG_EN_GPM_GET(x)                           (((x) & MCI_INTERRUPT_RX_MSG_EN_GPM_MASK) >> MCI_INTERRUPT_RX_MSG_EN_GPM_LSB)
#define MCI_INTERRUPT_RX_MSG_EN_GPM_SET(x)                           (((0 | (x)) << MCI_INTERRUPT_RX_MSG_EN_GPM_LSB) & MCI_INTERRUPT_RX_MSG_EN_GPM_MASK)
#define MCI_INTERRUPT_RX_MSG_EN_GPM_RESET                            0
#define MCI_INTERRUPT_RX_MSG_EN_CPU_INT_MSB                          6
#define MCI_INTERRUPT_RX_MSG_EN_CPU_INT_LSB                          6
#define MCI_INTERRUPT_RX_MSG_EN_CPU_INT_MASK                         0x00000040
#define MCI_INTERRUPT_RX_MSG_EN_CPU_INT_GET(x)                       (((x) & MCI_INTERRUPT_RX_MSG_EN_CPU_INT_MASK) >> MCI_INTERRUPT_RX_MSG_EN_CPU_INT_LSB)
#define MCI_INTERRUPT_RX_MSG_EN_CPU_INT_SET(x)                       (((0 | (x)) << MCI_INTERRUPT_RX_MSG_EN_CPU_INT_LSB) & MCI_INTERRUPT_RX_MSG_EN_CPU_INT_MASK)
#define MCI_INTERRUPT_RX_MSG_EN_CPU_INT_RESET                        0
#define MCI_INTERRUPT_RX_MSG_EN_SCHD_INFO_MSB                        5
#define MCI_INTERRUPT_RX_MSG_EN_SCHD_INFO_LSB                        5
#define MCI_INTERRUPT_RX_MSG_EN_SCHD_INFO_MASK                       0x00000020
#define MCI_INTERRUPT_RX_MSG_EN_SCHD_INFO_GET(x)                     (((x) & MCI_INTERRUPT_RX_MSG_EN_SCHD_INFO_MASK) >> MCI_INTERRUPT_RX_MSG_EN_SCHD_INFO_LSB)
#define MCI_INTERRUPT_RX_MSG_EN_SCHD_INFO_SET(x)                     (((0 | (x)) << MCI_INTERRUPT_RX_MSG_EN_SCHD_INFO_LSB) & MCI_INTERRUPT_RX_MSG_EN_SCHD_INFO_MASK)
#define MCI_INTERRUPT_RX_MSG_EN_SCHD_INFO_RESET                      0
#define MCI_INTERRUPT_RX_MSG_EN_CONT_RST_MSB                         4
#define MCI_INTERRUPT_RX_MSG_EN_CONT_RST_LSB                         4
#define MCI_INTERRUPT_RX_MSG_EN_CONT_RST_MASK                        0x00000010
#define MCI_INTERRUPT_RX_MSG_EN_CONT_RST_GET(x)                      (((x) & MCI_INTERRUPT_RX_MSG_EN_CONT_RST_MASK) >> MCI_INTERRUPT_RX_MSG_EN_CONT_RST_LSB)
#define MCI_INTERRUPT_RX_MSG_EN_CONT_RST_SET(x)                      (((0 | (x)) << MCI_INTERRUPT_RX_MSG_EN_CONT_RST_LSB) & MCI_INTERRUPT_RX_MSG_EN_CONT_RST_MASK)
#define MCI_INTERRUPT_RX_MSG_EN_CONT_RST_RESET                       0
#define MCI_INTERRUPT_RX_MSG_EN_CONT_INFO_MSB                        3
#define MCI_INTERRUPT_RX_MSG_EN_CONT_INFO_LSB                        3
#define MCI_INTERRUPT_RX_MSG_EN_CONT_INFO_MASK                       0x00000008
#define MCI_INTERRUPT_RX_MSG_EN_CONT_INFO_GET(x)                     (((x) & MCI_INTERRUPT_RX_MSG_EN_CONT_INFO_MASK) >> MCI_INTERRUPT_RX_MSG_EN_CONT_INFO_LSB)
#define MCI_INTERRUPT_RX_MSG_EN_CONT_INFO_SET(x)                     (((0 | (x)) << MCI_INTERRUPT_RX_MSG_EN_CONT_INFO_LSB) & MCI_INTERRUPT_RX_MSG_EN_CONT_INFO_MASK)
#define MCI_INTERRUPT_RX_MSG_EN_CONT_INFO_RESET                      0
#define MCI_INTERRUPT_RX_MSG_EN_CONT_NACK_MSB                        2
#define MCI_INTERRUPT_RX_MSG_EN_CONT_NACK_LSB                        2
#define MCI_INTERRUPT_RX_MSG_EN_CONT_NACK_MASK                       0x00000004
#define MCI_INTERRUPT_RX_MSG_EN_CONT_NACK_GET(x)                     (((x) & MCI_INTERRUPT_RX_MSG_EN_CONT_NACK_MASK) >> MCI_INTERRUPT_RX_MSG_EN_CONT_NACK_LSB)
#define MCI_INTERRUPT_RX_MSG_EN_CONT_NACK_SET(x)                     (((0 | (x)) << MCI_INTERRUPT_RX_MSG_EN_CONT_NACK_LSB) & MCI_INTERRUPT_RX_MSG_EN_CONT_NACK_MASK)
#define MCI_INTERRUPT_RX_MSG_EN_CONT_NACK_RESET                      0
#define MCI_INTERRUPT_RX_MSG_EN_LNA_CTRL_MSB                         1
#define MCI_INTERRUPT_RX_MSG_EN_LNA_CTRL_LSB                         1
#define MCI_INTERRUPT_RX_MSG_EN_LNA_CTRL_MASK                        0x00000002
#define MCI_INTERRUPT_RX_MSG_EN_LNA_CTRL_GET(x)                      (((x) & MCI_INTERRUPT_RX_MSG_EN_LNA_CTRL_MASK) >> MCI_INTERRUPT_RX_MSG_EN_LNA_CTRL_LSB)
#define MCI_INTERRUPT_RX_MSG_EN_LNA_CTRL_SET(x)                      (((0 | (x)) << MCI_INTERRUPT_RX_MSG_EN_LNA_CTRL_LSB) & MCI_INTERRUPT_RX_MSG_EN_LNA_CTRL_MASK)
#define MCI_INTERRUPT_RX_MSG_EN_LNA_CTRL_RESET                       0
#define MCI_INTERRUPT_RX_MSG_EN_REMOTE_RESET_MSB                     0
#define MCI_INTERRUPT_RX_MSG_EN_REMOTE_RESET_LSB                     0
#define MCI_INTERRUPT_RX_MSG_EN_REMOTE_RESET_MASK                    0x00000001
#define MCI_INTERRUPT_RX_MSG_EN_REMOTE_RESET_GET(x)                  (((x) & MCI_INTERRUPT_RX_MSG_EN_REMOTE_RESET_MASK) >> MCI_INTERRUPT_RX_MSG_EN_REMOTE_RESET_LSB)
#define MCI_INTERRUPT_RX_MSG_EN_REMOTE_RESET_SET(x)                  (((0 | (x)) << MCI_INTERRUPT_RX_MSG_EN_REMOTE_RESET_LSB) & MCI_INTERRUPT_RX_MSG_EN_REMOTE_RESET_MASK)
#define MCI_INTERRUPT_RX_MSG_EN_REMOTE_RESET_RESET                   0
#define MCI_INTERRUPT_RX_MSG_EN_ADDRESS                              0x003c
#define MCI_INTERRUPT_RX_MSG_EN_HW_MASK                              0x00001f7f
#define MCI_INTERRUPT_RX_MSG_EN_SW_MASK                              0x00001f7f
#define MCI_INTERRUPT_RX_MSG_EN_HW_WRITE_MASK                        0x00000000
#define MCI_INTERRUPT_RX_MSG_EN_SW_WRITE_MASK                        0x00001f7f
#define MCI_INTERRUPT_RX_MSG_EN_RSTMASK                              0xffffffff
#define MCI_INTERRUPT_RX_MSG_EN_RESET                                0x00000000

// 0x0040 (MCI_CPU_INT)
#define MCI_CPU_INT_MSG_MSB                                          31
#define MCI_CPU_INT_MSG_LSB                                          0
#define MCI_CPU_INT_MSG_MASK                                         0xffffffff
#define MCI_CPU_INT_MSG_GET(x)                                       (((x) & MCI_CPU_INT_MSG_MASK) >> MCI_CPU_INT_MSG_LSB)
#define MCI_CPU_INT_MSG_SET(x)                                       (((0 | (x)) << MCI_CPU_INT_MSG_LSB) & MCI_CPU_INT_MSG_MASK)
#define MCI_CPU_INT_MSG_RESET                                        0
#define MCI_CPU_INT_ADDRESS                                          0x0040
#define MCI_CPU_INT_HW_MASK                                          0xffffffff
#define MCI_CPU_INT_SW_MASK                                          0xffffffff
#define MCI_CPU_INT_HW_WRITE_MASK                                    0xffffffff
#define MCI_CPU_INT_SW_WRITE_MASK                                    0xffffffff
#define MCI_CPU_INT_RSTMASK                                          0xffffffff
#define MCI_CPU_INT_RESET                                            0x00000000

// 0x0044 (MCI_RX_STATUS)
#define MCI_RX_STATUS_S2P_COUNT_MSB                                  17
#define MCI_RX_STATUS_S2P_COUNT_LSB                                  14
#define MCI_RX_STATUS_S2P_COUNT_MASK                                 0x0003c000
#define MCI_RX_STATUS_S2P_COUNT_GET(x)                               (((x) & MCI_RX_STATUS_S2P_COUNT_MASK) >> MCI_RX_STATUS_S2P_COUNT_LSB)
#define MCI_RX_STATUS_S2P_COUNT_SET(x)                               (((0 | (x)) << MCI_RX_STATUS_S2P_COUNT_LSB) & MCI_RX_STATUS_S2P_COUNT_MASK)
#define MCI_RX_STATUS_S2P_COUNT_RESET                                0
#define MCI_RX_STATUS_MCI_CLK_REQ_MSB                                13
#define MCI_RX_STATUS_MCI_CLK_REQ_LSB                                13
#define MCI_RX_STATUS_MCI_CLK_REQ_MASK                               0x00002000
#define MCI_RX_STATUS_MCI_CLK_REQ_GET(x)                             (((x) & MCI_RX_STATUS_MCI_CLK_REQ_MASK) >> MCI_RX_STATUS_MCI_CLK_REQ_LSB)
#define MCI_RX_STATUS_MCI_CLK_REQ_SET(x)                             (((0 | (x)) << MCI_RX_STATUS_MCI_CLK_REQ_LSB) & MCI_RX_STATUS_MCI_CLK_REQ_MASK)
#define MCI_RX_STATUS_MCI_CLK_REQ_RESET                              0
#define MCI_RX_STATUS_REMOTE_SLEEP_MSB                               12
#define MCI_RX_STATUS_REMOTE_SLEEP_LSB                               12
#define MCI_RX_STATUS_REMOTE_SLEEP_MASK                              0x00001000
#define MCI_RX_STATUS_REMOTE_SLEEP_GET(x)                            (((x) & MCI_RX_STATUS_REMOTE_SLEEP_MASK) >> MCI_RX_STATUS_REMOTE_SLEEP_LSB)
#define MCI_RX_STATUS_REMOTE_SLEEP_SET(x)                            (((0 | (x)) << MCI_RX_STATUS_REMOTE_SLEEP_LSB) & MCI_RX_STATUS_REMOTE_SLEEP_MASK)
#define MCI_RX_STATUS_REMOTE_SLEEP_RESET                             1
#define MCI_RX_STATUS_SCHD_MSG_INDEX_MSB                             11
#define MCI_RX_STATUS_SCHD_MSG_INDEX_LSB                             8
#define MCI_RX_STATUS_SCHD_MSG_INDEX_MASK                            0x00000f00
#define MCI_RX_STATUS_SCHD_MSG_INDEX_GET(x)                          (((x) & MCI_RX_STATUS_SCHD_MSG_INDEX_MASK) >> MCI_RX_STATUS_SCHD_MSG_INDEX_LSB)
#define MCI_RX_STATUS_SCHD_MSG_INDEX_SET(x)                          (((0 | (x)) << MCI_RX_STATUS_SCHD_MSG_INDEX_LSB) & MCI_RX_STATUS_SCHD_MSG_INDEX_MASK)
#define MCI_RX_STATUS_SCHD_MSG_INDEX_RESET                           0
#define MCI_RX_STATUS_ADDRESS                                        0x0044
#define MCI_RX_STATUS_HW_MASK                                        0x0003ff00
#define MCI_RX_STATUS_SW_MASK                                        0x0003ff00
#define MCI_RX_STATUS_HW_WRITE_MASK                                  0x0003ff00
#define MCI_RX_STATUS_SW_WRITE_MASK                                  0x00000000
#define MCI_RX_STATUS_RSTMASK                                        0xffffffff
#define MCI_RX_STATUS_RESET                                          0x00001000

// 0x0048 (MCI_CONT_STATUS)
#define MCI_CONT_STATUS_OWNER_MSB                                    31
#define MCI_CONT_STATUS_OWNER_LSB                                    28
#define MCI_CONT_STATUS_OWNER_MASK                                   0xf0000000
#define MCI_CONT_STATUS_OWNER_GET(x)                                 (((x) & MCI_CONT_STATUS_OWNER_MASK) >> MCI_CONT_STATUS_OWNER_LSB)
#define MCI_CONT_STATUS_OWNER_SET(x)                                 (((0 | (x)) << MCI_CONT_STATUS_OWNER_LSB) & MCI_CONT_STATUS_OWNER_MASK)
#define MCI_CONT_STATUS_OWNER_RESET                                  15
#define MCI_CONT_STATUS_CHANNEL_MSB                                  27
#define MCI_CONT_STATUS_CHANNEL_LSB                                  21
#define MCI_CONT_STATUS_CHANNEL_MASK                                 0x0fe00000
#define MCI_CONT_STATUS_CHANNEL_GET(x)                               (((x) & MCI_CONT_STATUS_CHANNEL_MASK) >> MCI_CONT_STATUS_CHANNEL_LSB)
#define MCI_CONT_STATUS_CHANNEL_SET(x)                               (((0 | (x)) << MCI_CONT_STATUS_CHANNEL_LSB) & MCI_CONT_STATUS_CHANNEL_MASK)
#define MCI_CONT_STATUS_CHANNEL_RESET                                0
#define MCI_CONT_STATUS_LINKID_MSB                                   20
#define MCI_CONT_STATUS_LINKID_LSB                                   17
#define MCI_CONT_STATUS_LINKID_MASK                                  0x001e0000
#define MCI_CONT_STATUS_LINKID_GET(x)                                (((x) & MCI_CONT_STATUS_LINKID_MASK) >> MCI_CONT_STATUS_LINKID_LSB)
#define MCI_CONT_STATUS_LINKID_SET(x)                                (((0 | (x)) << MCI_CONT_STATUS_LINKID_LSB) & MCI_CONT_STATUS_LINKID_MASK)
#define MCI_CONT_STATUS_LINKID_RESET                                 0
#define MCI_CONT_STATUS_TX_MSB                                       16
#define MCI_CONT_STATUS_TX_LSB                                       16
#define MCI_CONT_STATUS_TX_MASK                                      0x00010000
#define MCI_CONT_STATUS_TX_GET(x)                                    (((x) & MCI_CONT_STATUS_TX_MASK) >> MCI_CONT_STATUS_TX_LSB)
#define MCI_CONT_STATUS_TX_SET(x)                                    (((0 | (x)) << MCI_CONT_STATUS_TX_LSB) & MCI_CONT_STATUS_TX_MASK)
#define MCI_CONT_STATUS_TX_RESET                                     0
#define MCI_CONT_STATUS_PRIORITY_MSB                                 15
#define MCI_CONT_STATUS_PRIORITY_LSB                                 8
#define MCI_CONT_STATUS_PRIORITY_MASK                                0x0000ff00
#define MCI_CONT_STATUS_PRIORITY_GET(x)                              (((x) & MCI_CONT_STATUS_PRIORITY_MASK) >> MCI_CONT_STATUS_PRIORITY_LSB)
#define MCI_CONT_STATUS_PRIORITY_SET(x)                              (((0 | (x)) << MCI_CONT_STATUS_PRIORITY_LSB) & MCI_CONT_STATUS_PRIORITY_MASK)
#define MCI_CONT_STATUS_PRIORITY_RESET                               0
#define MCI_CONT_STATUS_RSSI_POWER_MSB                               7
#define MCI_CONT_STATUS_RSSI_POWER_LSB                               0
#define MCI_CONT_STATUS_RSSI_POWER_MASK                              0x000000ff
#define MCI_CONT_STATUS_RSSI_POWER_GET(x)                            (((x) & MCI_CONT_STATUS_RSSI_POWER_MASK) >> MCI_CONT_STATUS_RSSI_POWER_LSB)
#define MCI_CONT_STATUS_RSSI_POWER_SET(x)                            (((0 | (x)) << MCI_CONT_STATUS_RSSI_POWER_LSB) & MCI_CONT_STATUS_RSSI_POWER_MASK)
#define MCI_CONT_STATUS_RSSI_POWER_RESET                             0
#define MCI_CONT_STATUS_ADDRESS                                      0x0048
#define MCI_CONT_STATUS_HW_MASK                                      0xffffffff
#define MCI_CONT_STATUS_SW_MASK                                      0xffffffff
#define MCI_CONT_STATUS_HW_WRITE_MASK                                0xffffffff
#define MCI_CONT_STATUS_SW_WRITE_MASK                                0x00000000
#define MCI_CONT_STATUS_RSTMASK                                      0xffffffff
#define MCI_CONT_STATUS_RESET                                        0xf0000000

// 0x004c (MCI_BT_PRI0)
#define MCI_BT_PRI0_VAL3_MSB                                         31
#define MCI_BT_PRI0_VAL3_LSB                                         24
#define MCI_BT_PRI0_VAL3_MASK                                        0xff000000
#define MCI_BT_PRI0_VAL3_GET(x)                                      (((x) & MCI_BT_PRI0_VAL3_MASK) >> MCI_BT_PRI0_VAL3_LSB)
#define MCI_BT_PRI0_VAL3_SET(x)                                      (((0 | (x)) << MCI_BT_PRI0_VAL3_LSB) & MCI_BT_PRI0_VAL3_MASK)
#define MCI_BT_PRI0_VAL3_RESET                                       0
#define MCI_BT_PRI0_VAL2_MSB                                         23
#define MCI_BT_PRI0_VAL2_LSB                                         16
#define MCI_BT_PRI0_VAL2_MASK                                        0x00ff0000
#define MCI_BT_PRI0_VAL2_GET(x)                                      (((x) & MCI_BT_PRI0_VAL2_MASK) >> MCI_BT_PRI0_VAL2_LSB)
#define MCI_BT_PRI0_VAL2_SET(x)                                      (((0 | (x)) << MCI_BT_PRI0_VAL2_LSB) & MCI_BT_PRI0_VAL2_MASK)
#define MCI_BT_PRI0_VAL2_RESET                                       0
#define MCI_BT_PRI0_VAL1_MSB                                         15
#define MCI_BT_PRI0_VAL1_LSB                                         8
#define MCI_BT_PRI0_VAL1_MASK                                        0x0000ff00
#define MCI_BT_PRI0_VAL1_GET(x)                                      (((x) & MCI_BT_PRI0_VAL1_MASK) >> MCI_BT_PRI0_VAL1_LSB)
#define MCI_BT_PRI0_VAL1_SET(x)                                      (((0 | (x)) << MCI_BT_PRI0_VAL1_LSB) & MCI_BT_PRI0_VAL1_MASK)
#define MCI_BT_PRI0_VAL1_RESET                                       0
#define MCI_BT_PRI0_VAL0_MSB                                         7
#define MCI_BT_PRI0_VAL0_LSB                                         0
#define MCI_BT_PRI0_VAL0_MASK                                        0x000000ff
#define MCI_BT_PRI0_VAL0_GET(x)                                      (((x) & MCI_BT_PRI0_VAL0_MASK) >> MCI_BT_PRI0_VAL0_LSB)
#define MCI_BT_PRI0_VAL0_SET(x)                                      (((0 | (x)) << MCI_BT_PRI0_VAL0_LSB) & MCI_BT_PRI0_VAL0_MASK)
#define MCI_BT_PRI0_VAL0_RESET                                       0
#define MCI_BT_PRI0_ADDRESS                                          0x004c
#define MCI_BT_PRI0_HW_MASK                                          0xffffffff
#define MCI_BT_PRI0_SW_MASK                                          0xffffffff
#define MCI_BT_PRI0_HW_WRITE_MASK                                    0x00000000
#define MCI_BT_PRI0_SW_WRITE_MASK                                    0xffffffff
#define MCI_BT_PRI0_RSTMASK                                          0xffffffff
#define MCI_BT_PRI0_RESET                                            0x00000000

// 0x0050 (MCI_BT_PRI1)
#define MCI_BT_PRI1_VAL3_MSB                                         31
#define MCI_BT_PRI1_VAL3_LSB                                         24
#define MCI_BT_PRI1_VAL3_MASK                                        0xff000000
#define MCI_BT_PRI1_VAL3_GET(x)                                      (((x) & MCI_BT_PRI1_VAL3_MASK) >> MCI_BT_PRI1_VAL3_LSB)
#define MCI_BT_PRI1_VAL3_SET(x)                                      (((0 | (x)) << MCI_BT_PRI1_VAL3_LSB) & MCI_BT_PRI1_VAL3_MASK)
#define MCI_BT_PRI1_VAL3_RESET                                       0
#define MCI_BT_PRI1_VAL2_MSB                                         23
#define MCI_BT_PRI1_VAL2_LSB                                         16
#define MCI_BT_PRI1_VAL2_MASK                                        0x00ff0000
#define MCI_BT_PRI1_VAL2_GET(x)                                      (((x) & MCI_BT_PRI1_VAL2_MASK) >> MCI_BT_PRI1_VAL2_LSB)
#define MCI_BT_PRI1_VAL2_SET(x)                                      (((0 | (x)) << MCI_BT_PRI1_VAL2_LSB) & MCI_BT_PRI1_VAL2_MASK)
#define MCI_BT_PRI1_VAL2_RESET                                       0
#define MCI_BT_PRI1_VAL1_MSB                                         15
#define MCI_BT_PRI1_VAL1_LSB                                         8
#define MCI_BT_PRI1_VAL1_MASK                                        0x0000ff00
#define MCI_BT_PRI1_VAL1_GET(x)                                      (((x) & MCI_BT_PRI1_VAL1_MASK) >> MCI_BT_PRI1_VAL1_LSB)
#define MCI_BT_PRI1_VAL1_SET(x)                                      (((0 | (x)) << MCI_BT_PRI1_VAL1_LSB) & MCI_BT_PRI1_VAL1_MASK)
#define MCI_BT_PRI1_VAL1_RESET                                       0
#define MCI_BT_PRI1_VAL0_MSB                                         7
#define MCI_BT_PRI1_VAL0_LSB                                         0
#define MCI_BT_PRI1_VAL0_MASK                                        0x000000ff
#define MCI_BT_PRI1_VAL0_GET(x)                                      (((x) & MCI_BT_PRI1_VAL0_MASK) >> MCI_BT_PRI1_VAL0_LSB)
#define MCI_BT_PRI1_VAL0_SET(x)                                      (((0 | (x)) << MCI_BT_PRI1_VAL0_LSB) & MCI_BT_PRI1_VAL0_MASK)
#define MCI_BT_PRI1_VAL0_RESET                                       0
#define MCI_BT_PRI1_ADDRESS                                          0x0050
#define MCI_BT_PRI1_HW_MASK                                          0xffffffff
#define MCI_BT_PRI1_SW_MASK                                          0xffffffff
#define MCI_BT_PRI1_HW_WRITE_MASK                                    0x00000000
#define MCI_BT_PRI1_SW_WRITE_MASK                                    0xffffffff
#define MCI_BT_PRI1_RSTMASK                                          0xffffffff
#define MCI_BT_PRI1_RESET                                            0x00000000

// 0x0054 (MCI_BT_PRI2)
#define MCI_BT_PRI2_VAL3_MSB                                         31
#define MCI_BT_PRI2_VAL3_LSB                                         24
#define MCI_BT_PRI2_VAL3_MASK                                        0xff000000
#define MCI_BT_PRI2_VAL3_GET(x)                                      (((x) & MCI_BT_PRI2_VAL3_MASK) >> MCI_BT_PRI2_VAL3_LSB)
#define MCI_BT_PRI2_VAL3_SET(x)                                      (((0 | (x)) << MCI_BT_PRI2_VAL3_LSB) & MCI_BT_PRI2_VAL3_MASK)
#define MCI_BT_PRI2_VAL3_RESET                                       0
#define MCI_BT_PRI2_VAL2_MSB                                         23
#define MCI_BT_PRI2_VAL2_LSB                                         16
#define MCI_BT_PRI2_VAL2_MASK                                        0x00ff0000
#define MCI_BT_PRI2_VAL2_GET(x)                                      (((x) & MCI_BT_PRI2_VAL2_MASK) >> MCI_BT_PRI2_VAL2_LSB)
#define MCI_BT_PRI2_VAL2_SET(x)                                      (((0 | (x)) << MCI_BT_PRI2_VAL2_LSB) & MCI_BT_PRI2_VAL2_MASK)
#define MCI_BT_PRI2_VAL2_RESET                                       0
#define MCI_BT_PRI2_VAL1_MSB                                         15
#define MCI_BT_PRI2_VAL1_LSB                                         8
#define MCI_BT_PRI2_VAL1_MASK                                        0x0000ff00
#define MCI_BT_PRI2_VAL1_GET(x)                                      (((x) & MCI_BT_PRI2_VAL1_MASK) >> MCI_BT_PRI2_VAL1_LSB)
#define MCI_BT_PRI2_VAL1_SET(x)                                      (((0 | (x)) << MCI_BT_PRI2_VAL1_LSB) & MCI_BT_PRI2_VAL1_MASK)
#define MCI_BT_PRI2_VAL1_RESET                                       0
#define MCI_BT_PRI2_VAL0_MSB                                         7
#define MCI_BT_PRI2_VAL0_LSB                                         0
#define MCI_BT_PRI2_VAL0_MASK                                        0x000000ff
#define MCI_BT_PRI2_VAL0_GET(x)                                      (((x) & MCI_BT_PRI2_VAL0_MASK) >> MCI_BT_PRI2_VAL0_LSB)
#define MCI_BT_PRI2_VAL0_SET(x)                                      (((0 | (x)) << MCI_BT_PRI2_VAL0_LSB) & MCI_BT_PRI2_VAL0_MASK)
#define MCI_BT_PRI2_VAL0_RESET                                       0
#define MCI_BT_PRI2_ADDRESS                                          0x0054
#define MCI_BT_PRI2_HW_MASK                                          0xffffffff
#define MCI_BT_PRI2_SW_MASK                                          0xffffffff
#define MCI_BT_PRI2_HW_WRITE_MASK                                    0x00000000
#define MCI_BT_PRI2_SW_WRITE_MASK                                    0xffffffff
#define MCI_BT_PRI2_RSTMASK                                          0xffffffff
#define MCI_BT_PRI2_RESET                                            0x00000000

// 0x0058 (MCI_BT_PRI3)
#define MCI_BT_PRI3_VAL3_MSB                                         31
#define MCI_BT_PRI3_VAL3_LSB                                         24
#define MCI_BT_PRI3_VAL3_MASK                                        0xff000000
#define MCI_BT_PRI3_VAL3_GET(x)                                      (((x) & MCI_BT_PRI3_VAL3_MASK) >> MCI_BT_PRI3_VAL3_LSB)
#define MCI_BT_PRI3_VAL3_SET(x)                                      (((0 | (x)) << MCI_BT_PRI3_VAL3_LSB) & MCI_BT_PRI3_VAL3_MASK)
#define MCI_BT_PRI3_VAL3_RESET                                       0
#define MCI_BT_PRI3_VAL2_MSB                                         23
#define MCI_BT_PRI3_VAL2_LSB                                         16
#define MCI_BT_PRI3_VAL2_MASK                                        0x00ff0000
#define MCI_BT_PRI3_VAL2_GET(x)                                      (((x) & MCI_BT_PRI3_VAL2_MASK) >> MCI_BT_PRI3_VAL2_LSB)
#define MCI_BT_PRI3_VAL2_SET(x)                                      (((0 | (x)) << MCI_BT_PRI3_VAL2_LSB) & MCI_BT_PRI3_VAL2_MASK)
#define MCI_BT_PRI3_VAL2_RESET                                       0
#define MCI_BT_PRI3_VAL1_MSB                                         15
#define MCI_BT_PRI3_VAL1_LSB                                         8
#define MCI_BT_PRI3_VAL1_MASK                                        0x0000ff00
#define MCI_BT_PRI3_VAL1_GET(x)                                      (((x) & MCI_BT_PRI3_VAL1_MASK) >> MCI_BT_PRI3_VAL1_LSB)
#define MCI_BT_PRI3_VAL1_SET(x)                                      (((0 | (x)) << MCI_BT_PRI3_VAL1_LSB) & MCI_BT_PRI3_VAL1_MASK)
#define MCI_BT_PRI3_VAL1_RESET                                       0
#define MCI_BT_PRI3_VAL0_MSB                                         7
#define MCI_BT_PRI3_VAL0_LSB                                         0
#define MCI_BT_PRI3_VAL0_MASK                                        0x000000ff
#define MCI_BT_PRI3_VAL0_GET(x)                                      (((x) & MCI_BT_PRI3_VAL0_MASK) >> MCI_BT_PRI3_VAL0_LSB)
#define MCI_BT_PRI3_VAL0_SET(x)                                      (((0 | (x)) << MCI_BT_PRI3_VAL0_LSB) & MCI_BT_PRI3_VAL0_MASK)
#define MCI_BT_PRI3_VAL0_RESET                                       0
#define MCI_BT_PRI3_ADDRESS                                          0x0058
#define MCI_BT_PRI3_HW_MASK                                          0xffffffff
#define MCI_BT_PRI3_SW_MASK                                          0xffffffff
#define MCI_BT_PRI3_HW_WRITE_MASK                                    0x00000000
#define MCI_BT_PRI3_SW_WRITE_MASK                                    0xffffffff
#define MCI_BT_PRI3_RSTMASK                                          0xffffffff
#define MCI_BT_PRI3_RESET                                            0x00000000

// 0x005c (MCI_BT_PRI)
#define MCI_BT_PRI_THRESH_MSB                                        7
#define MCI_BT_PRI_THRESH_LSB                                        0
#define MCI_BT_PRI_THRESH_MASK                                       0x000000ff
#define MCI_BT_PRI_THRESH_GET(x)                                     (((x) & MCI_BT_PRI_THRESH_MASK) >> MCI_BT_PRI_THRESH_LSB)
#define MCI_BT_PRI_THRESH_SET(x)                                     (((0 | (x)) << MCI_BT_PRI_THRESH_LSB) & MCI_BT_PRI_THRESH_MASK)
#define MCI_BT_PRI_THRESH_RESET                                      0
#define MCI_BT_PRI_ADDRESS                                           0x005c
#define MCI_BT_PRI_HW_MASK                                           0x000000ff
#define MCI_BT_PRI_SW_MASK                                           0x000000ff
#define MCI_BT_PRI_HW_WRITE_MASK                                     0x00000000
#define MCI_BT_PRI_SW_WRITE_MASK                                     0x000000ff
#define MCI_BT_PRI_RSTMASK                                           0xffffffff
#define MCI_BT_PRI_RESET                                             0x00000000

// 0x0060 (MCI_WL_FREQ0)
#define MCI_WL_FREQ0_MASK_MSB                                        31
#define MCI_WL_FREQ0_MASK_LSB                                        0
#define MCI_WL_FREQ0_MASK_MASK                                       0xffffffff
#define MCI_WL_FREQ0_MASK_GET(x)                                     (((x) & MCI_WL_FREQ0_MASK_MASK) >> MCI_WL_FREQ0_MASK_LSB)
#define MCI_WL_FREQ0_MASK_SET(x)                                     (((0 | (x)) << MCI_WL_FREQ0_MASK_LSB) & MCI_WL_FREQ0_MASK_MASK)
#define MCI_WL_FREQ0_MASK_RESET                                      0
#define MCI_WL_FREQ0_ADDRESS                                         0x0060
#define MCI_WL_FREQ0_HW_MASK                                         0xffffffff
#define MCI_WL_FREQ0_SW_MASK                                         0xffffffff
#define MCI_WL_FREQ0_HW_WRITE_MASK                                   0x00000000
#define MCI_WL_FREQ0_SW_WRITE_MASK                                   0xffffffff
#define MCI_WL_FREQ0_RSTMASK                                         0xffffffff
#define MCI_WL_FREQ0_RESET                                           0x00000000

// 0x0064 (MCI_WL_FREQ1)
#define MCI_WL_FREQ1_MASK_MSB                                        31
#define MCI_WL_FREQ1_MASK_LSB                                        0
#define MCI_WL_FREQ1_MASK_MASK                                       0xffffffff
#define MCI_WL_FREQ1_MASK_GET(x)                                     (((x) & MCI_WL_FREQ1_MASK_MASK) >> MCI_WL_FREQ1_MASK_LSB)
#define MCI_WL_FREQ1_MASK_SET(x)                                     (((0 | (x)) << MCI_WL_FREQ1_MASK_LSB) & MCI_WL_FREQ1_MASK_MASK)
#define MCI_WL_FREQ1_MASK_RESET                                      0
#define MCI_WL_FREQ1_ADDRESS                                         0x0064
#define MCI_WL_FREQ1_HW_MASK                                         0xffffffff
#define MCI_WL_FREQ1_SW_MASK                                         0xffffffff
#define MCI_WL_FREQ1_HW_WRITE_MASK                                   0x00000000
#define MCI_WL_FREQ1_SW_WRITE_MASK                                   0xffffffff
#define MCI_WL_FREQ1_RSTMASK                                         0xffffffff
#define MCI_WL_FREQ1_RESET                                           0x00000000

// 0x0068 (MCI_WL_FREQ2)
#define MCI_WL_FREQ2_MASK_MSB                                        15
#define MCI_WL_FREQ2_MASK_LSB                                        0
#define MCI_WL_FREQ2_MASK_MASK                                       0x0000ffff
#define MCI_WL_FREQ2_MASK_GET(x)                                     (((x) & MCI_WL_FREQ2_MASK_MASK) >> MCI_WL_FREQ2_MASK_LSB)
#define MCI_WL_FREQ2_MASK_SET(x)                                     (((0 | (x)) << MCI_WL_FREQ2_MASK_LSB) & MCI_WL_FREQ2_MASK_MASK)
#define MCI_WL_FREQ2_MASK_RESET                                      0
#define MCI_WL_FREQ2_ADDRESS                                         0x0068
#define MCI_WL_FREQ2_HW_MASK                                         0x0000ffff
#define MCI_WL_FREQ2_SW_MASK                                         0x0000ffff
#define MCI_WL_FREQ2_HW_WRITE_MASK                                   0x00000000
#define MCI_WL_FREQ2_SW_WRITE_MASK                                   0x0000ffff
#define MCI_WL_FREQ2_RSTMASK                                         0xffffffff
#define MCI_WL_FREQ2_RESET                                           0x00000000

// 0x006c (MCI_GAIN)
#define MCI_GAIN_OFFSET2_MSB                                         15
#define MCI_GAIN_OFFSET2_LSB                                         8
#define MCI_GAIN_OFFSET2_MASK                                        0x0000ff00
#define MCI_GAIN_OFFSET2_GET(x)                                      (((x) & MCI_GAIN_OFFSET2_MASK) >> MCI_GAIN_OFFSET2_LSB)
#define MCI_GAIN_OFFSET2_SET(x)                                      (((0 | (x)) << MCI_GAIN_OFFSET2_LSB) & MCI_GAIN_OFFSET2_MASK)
#define MCI_GAIN_OFFSET2_RESET                                       0
#define MCI_GAIN_OFFSET1_MSB                                         7
#define MCI_GAIN_OFFSET1_LSB                                         0
#define MCI_GAIN_OFFSET1_MASK                                        0x000000ff
#define MCI_GAIN_OFFSET1_GET(x)                                      (((x) & MCI_GAIN_OFFSET1_MASK) >> MCI_GAIN_OFFSET1_LSB)
#define MCI_GAIN_OFFSET1_SET(x)                                      (((0 | (x)) << MCI_GAIN_OFFSET1_LSB) & MCI_GAIN_OFFSET1_MASK)
#define MCI_GAIN_OFFSET1_RESET                                       0
#define MCI_GAIN_ADDRESS                                             0x006c
#define MCI_GAIN_HW_MASK                                             0x0000ffff
#define MCI_GAIN_SW_MASK                                             0x0000ffff
#define MCI_GAIN_HW_WRITE_MASK                                       0x00000000
#define MCI_GAIN_SW_WRITE_MASK                                       0x0000ffff
#define MCI_GAIN_RSTMASK                                             0xffffffff
#define MCI_GAIN_RESET                                               0x00000000

// 0x0070 (MCI_WBTIMER1)
#define MCI_WBTIMER1_TARGET_MSB                                      31
#define MCI_WBTIMER1_TARGET_LSB                                      0
#define MCI_WBTIMER1_TARGET_MASK                                     0xffffffff
#define MCI_WBTIMER1_TARGET_GET(x)                                   (((x) & MCI_WBTIMER1_TARGET_MASK) >> MCI_WBTIMER1_TARGET_LSB)
#define MCI_WBTIMER1_TARGET_SET(x)                                   (((0 | (x)) << MCI_WBTIMER1_TARGET_LSB) & MCI_WBTIMER1_TARGET_MASK)
#define MCI_WBTIMER1_TARGET_RESET                                    0
#define MCI_WBTIMER1_ADDRESS                                         0x0070
#define MCI_WBTIMER1_HW_MASK                                         0xffffffff
#define MCI_WBTIMER1_SW_MASK                                         0xffffffff
#define MCI_WBTIMER1_HW_WRITE_MASK                                   0x00000000
#define MCI_WBTIMER1_SW_WRITE_MASK                                   0xffffffff
#define MCI_WBTIMER1_RSTMASK                                         0xffffffff
#define MCI_WBTIMER1_RESET                                           0x00000000

// 0x0074 (MCI_WBTIMER2)
#define MCI_WBTIMER2_TARGET_MSB                                      31
#define MCI_WBTIMER2_TARGET_LSB                                      0
#define MCI_WBTIMER2_TARGET_MASK                                     0xffffffff
#define MCI_WBTIMER2_TARGET_GET(x)                                   (((x) & MCI_WBTIMER2_TARGET_MASK) >> MCI_WBTIMER2_TARGET_LSB)
#define MCI_WBTIMER2_TARGET_SET(x)                                   (((0 | (x)) << MCI_WBTIMER2_TARGET_LSB) & MCI_WBTIMER2_TARGET_MASK)
#define MCI_WBTIMER2_TARGET_RESET                                    0
#define MCI_WBTIMER2_ADDRESS                                         0x0074
#define MCI_WBTIMER2_HW_MASK                                         0xffffffff
#define MCI_WBTIMER2_SW_MASK                                         0xffffffff
#define MCI_WBTIMER2_HW_WRITE_MASK                                   0x00000000
#define MCI_WBTIMER2_SW_WRITE_MASK                                   0xffffffff
#define MCI_WBTIMER2_RSTMASK                                         0xffffffff
#define MCI_WBTIMER2_RESET                                           0x00000000

// 0x0078 (MCI_WBTIMER3)
#define MCI_WBTIMER3_TARGET_MSB                                      31
#define MCI_WBTIMER3_TARGET_LSB                                      0
#define MCI_WBTIMER3_TARGET_MASK                                     0xffffffff
#define MCI_WBTIMER3_TARGET_GET(x)                                   (((x) & MCI_WBTIMER3_TARGET_MASK) >> MCI_WBTIMER3_TARGET_LSB)
#define MCI_WBTIMER3_TARGET_SET(x)                                   (((0 | (x)) << MCI_WBTIMER3_TARGET_LSB) & MCI_WBTIMER3_TARGET_MASK)
#define MCI_WBTIMER3_TARGET_RESET                                    0
#define MCI_WBTIMER3_ADDRESS                                         0x0078
#define MCI_WBTIMER3_HW_MASK                                         0xffffffff
#define MCI_WBTIMER3_SW_MASK                                         0xffffffff
#define MCI_WBTIMER3_HW_WRITE_MASK                                   0x00000000
#define MCI_WBTIMER3_SW_WRITE_MASK                                   0xffffffff
#define MCI_WBTIMER3_RSTMASK                                         0xffffffff
#define MCI_WBTIMER3_RESET                                           0x00000000

// 0x007c (MCI_WBTIMER4)
#define MCI_WBTIMER4_TARGET_MSB                                      31
#define MCI_WBTIMER4_TARGET_LSB                                      0
#define MCI_WBTIMER4_TARGET_MASK                                     0xffffffff
#define MCI_WBTIMER4_TARGET_GET(x)                                   (((x) & MCI_WBTIMER4_TARGET_MASK) >> MCI_WBTIMER4_TARGET_LSB)
#define MCI_WBTIMER4_TARGET_SET(x)                                   (((0 | (x)) << MCI_WBTIMER4_TARGET_LSB) & MCI_WBTIMER4_TARGET_MASK)
#define MCI_WBTIMER4_TARGET_RESET                                    0
#define MCI_WBTIMER4_ADDRESS                                         0x007c
#define MCI_WBTIMER4_HW_MASK                                         0xffffffff
#define MCI_WBTIMER4_SW_MASK                                         0xffffffff
#define MCI_WBTIMER4_HW_WRITE_MASK                                   0x00000000
#define MCI_WBTIMER4_SW_WRITE_MASK                                   0xffffffff
#define MCI_WBTIMER4_RSTMASK                                         0xffffffff
#define MCI_WBTIMER4_RESET                                           0x00000000

// 0x0080 (MCI_MAXGAIN)
#define MCI_MAXGAIN_GAIN4_MSB                                        31
#define MCI_MAXGAIN_GAIN4_LSB                                        24
#define MCI_MAXGAIN_GAIN4_MASK                                       0xff000000
#define MCI_MAXGAIN_GAIN4_GET(x)                                     (((x) & MCI_MAXGAIN_GAIN4_MASK) >> MCI_MAXGAIN_GAIN4_LSB)
#define MCI_MAXGAIN_GAIN4_SET(x)                                     (((0 | (x)) << MCI_MAXGAIN_GAIN4_LSB) & MCI_MAXGAIN_GAIN4_MASK)
#define MCI_MAXGAIN_GAIN4_RESET                                      0
#define MCI_MAXGAIN_GAIN3_MSB                                        23
#define MCI_MAXGAIN_GAIN3_LSB                                        16
#define MCI_MAXGAIN_GAIN3_MASK                                       0x00ff0000
#define MCI_MAXGAIN_GAIN3_GET(x)                                     (((x) & MCI_MAXGAIN_GAIN3_MASK) >> MCI_MAXGAIN_GAIN3_LSB)
#define MCI_MAXGAIN_GAIN3_SET(x)                                     (((0 | (x)) << MCI_MAXGAIN_GAIN3_LSB) & MCI_MAXGAIN_GAIN3_MASK)
#define MCI_MAXGAIN_GAIN3_RESET                                      0
#define MCI_MAXGAIN_GAIN2_MSB                                        15
#define MCI_MAXGAIN_GAIN2_LSB                                        8
#define MCI_MAXGAIN_GAIN2_MASK                                       0x0000ff00
#define MCI_MAXGAIN_GAIN2_GET(x)                                     (((x) & MCI_MAXGAIN_GAIN2_MASK) >> MCI_MAXGAIN_GAIN2_LSB)
#define MCI_MAXGAIN_GAIN2_SET(x)                                     (((0 | (x)) << MCI_MAXGAIN_GAIN2_LSB) & MCI_MAXGAIN_GAIN2_MASK)
#define MCI_MAXGAIN_GAIN2_RESET                                      0
#define MCI_MAXGAIN_GAIN1_MSB                                        7
#define MCI_MAXGAIN_GAIN1_LSB                                        0
#define MCI_MAXGAIN_GAIN1_MASK                                       0x000000ff
#define MCI_MAXGAIN_GAIN1_GET(x)                                     (((x) & MCI_MAXGAIN_GAIN1_MASK) >> MCI_MAXGAIN_GAIN1_LSB)
#define MCI_MAXGAIN_GAIN1_SET(x)                                     (((0 | (x)) << MCI_MAXGAIN_GAIN1_LSB) & MCI_MAXGAIN_GAIN1_MASK)
#define MCI_MAXGAIN_GAIN1_RESET                                      0
#define MCI_MAXGAIN_ADDRESS                                          0x0080
#define MCI_MAXGAIN_HW_MASK                                          0xffffffff
#define MCI_MAXGAIN_SW_MASK                                          0xffffffff
#define MCI_MAXGAIN_HW_WRITE_MASK                                    0x00000000
#define MCI_MAXGAIN_SW_WRITE_MASK                                    0xffffffff
#define MCI_MAXGAIN_RSTMASK                                          0xffffffff
#define MCI_MAXGAIN_RESET                                            0x00000000

// 0x0084 (MCI_HW_SCHD_TBL_CTL)
#define MCI_HW_SCHD_TBL_CTL_PREV_PTR_MSB                             31
#define MCI_HW_SCHD_TBL_CTL_PREV_PTR_LSB                             28
#define MCI_HW_SCHD_TBL_CTL_PREV_PTR_MASK                            0xf0000000
#define MCI_HW_SCHD_TBL_CTL_PREV_PTR_GET(x)                          (((x) & MCI_HW_SCHD_TBL_CTL_PREV_PTR_MASK) >> MCI_HW_SCHD_TBL_CTL_PREV_PTR_LSB)
#define MCI_HW_SCHD_TBL_CTL_PREV_PTR_SET(x)                          (((0 | (x)) << MCI_HW_SCHD_TBL_CTL_PREV_PTR_LSB) & MCI_HW_SCHD_TBL_CTL_PREV_PTR_MASK)
#define MCI_HW_SCHD_TBL_CTL_PREV_PTR_RESET                           0
#define MCI_HW_SCHD_TBL_CTL_NEXT_PTR_MSB                             27
#define MCI_HW_SCHD_TBL_CTL_NEXT_PTR_LSB                             24
#define MCI_HW_SCHD_TBL_CTL_NEXT_PTR_MASK                            0x0f000000
#define MCI_HW_SCHD_TBL_CTL_NEXT_PTR_GET(x)                          (((x) & MCI_HW_SCHD_TBL_CTL_NEXT_PTR_MASK) >> MCI_HW_SCHD_TBL_CTL_NEXT_PTR_LSB)
#define MCI_HW_SCHD_TBL_CTL_NEXT_PTR_SET(x)                          (((0 | (x)) << MCI_HW_SCHD_TBL_CTL_NEXT_PTR_LSB) & MCI_HW_SCHD_TBL_CTL_NEXT_PTR_MASK)
#define MCI_HW_SCHD_TBL_CTL_NEXT_PTR_RESET                           0
#define MCI_HW_SCHD_TBL_CTL_CUR_PTR_MSB                              23
#define MCI_HW_SCHD_TBL_CTL_CUR_PTR_LSB                              20
#define MCI_HW_SCHD_TBL_CTL_CUR_PTR_MASK                             0x00f00000
#define MCI_HW_SCHD_TBL_CTL_CUR_PTR_GET(x)                           (((x) & MCI_HW_SCHD_TBL_CTL_CUR_PTR_MASK) >> MCI_HW_SCHD_TBL_CTL_CUR_PTR_LSB)
#define MCI_HW_SCHD_TBL_CTL_CUR_PTR_SET(x)                           (((0 | (x)) << MCI_HW_SCHD_TBL_CTL_CUR_PTR_LSB) & MCI_HW_SCHD_TBL_CTL_CUR_PTR_MASK)
#define MCI_HW_SCHD_TBL_CTL_CUR_PTR_RESET                            0
#define MCI_HW_SCHD_TBL_CTL_TAIL_PTR_MSB                             19
#define MCI_HW_SCHD_TBL_CTL_TAIL_PTR_LSB                             16
#define MCI_HW_SCHD_TBL_CTL_TAIL_PTR_MASK                            0x000f0000
#define MCI_HW_SCHD_TBL_CTL_TAIL_PTR_GET(x)                          (((x) & MCI_HW_SCHD_TBL_CTL_TAIL_PTR_MASK) >> MCI_HW_SCHD_TBL_CTL_TAIL_PTR_LSB)
#define MCI_HW_SCHD_TBL_CTL_TAIL_PTR_SET(x)                          (((0 | (x)) << MCI_HW_SCHD_TBL_CTL_TAIL_PTR_LSB) & MCI_HW_SCHD_TBL_CTL_TAIL_PTR_MASK)
#define MCI_HW_SCHD_TBL_CTL_TAIL_PTR_RESET                           0
#define MCI_HW_SCHD_TBL_CTL_HEAD_PTR_MSB                             15
#define MCI_HW_SCHD_TBL_CTL_HEAD_PTR_LSB                             12
#define MCI_HW_SCHD_TBL_CTL_HEAD_PTR_MASK                            0x0000f000
#define MCI_HW_SCHD_TBL_CTL_HEAD_PTR_GET(x)                          (((x) & MCI_HW_SCHD_TBL_CTL_HEAD_PTR_MASK) >> MCI_HW_SCHD_TBL_CTL_HEAD_PTR_LSB)
#define MCI_HW_SCHD_TBL_CTL_HEAD_PTR_SET(x)                          (((0 | (x)) << MCI_HW_SCHD_TBL_CTL_HEAD_PTR_LSB) & MCI_HW_SCHD_TBL_CTL_HEAD_PTR_MASK)
#define MCI_HW_SCHD_TBL_CTL_HEAD_PTR_RESET                           0
#define MCI_HW_SCHD_TBL_CTL_TBL_EMPTY_MSB                            11
#define MCI_HW_SCHD_TBL_CTL_TBL_EMPTY_LSB                            11
#define MCI_HW_SCHD_TBL_CTL_TBL_EMPTY_MASK                           0x00000800
#define MCI_HW_SCHD_TBL_CTL_TBL_EMPTY_GET(x)                         (((x) & MCI_HW_SCHD_TBL_CTL_TBL_EMPTY_MASK) >> MCI_HW_SCHD_TBL_CTL_TBL_EMPTY_LSB)
#define MCI_HW_SCHD_TBL_CTL_TBL_EMPTY_SET(x)                         (((0 | (x)) << MCI_HW_SCHD_TBL_CTL_TBL_EMPTY_LSB) & MCI_HW_SCHD_TBL_CTL_TBL_EMPTY_MASK)
#define MCI_HW_SCHD_TBL_CTL_TBL_EMPTY_RESET                          1
#define MCI_HW_SCHD_TBL_CTL_RW_ADDR_MSB                              4
#define MCI_HW_SCHD_TBL_CTL_RW_ADDR_LSB                              1
#define MCI_HW_SCHD_TBL_CTL_RW_ADDR_MASK                             0x0000001e
#define MCI_HW_SCHD_TBL_CTL_RW_ADDR_GET(x)                           (((x) & MCI_HW_SCHD_TBL_CTL_RW_ADDR_MASK) >> MCI_HW_SCHD_TBL_CTL_RW_ADDR_LSB)
#define MCI_HW_SCHD_TBL_CTL_RW_ADDR_SET(x)                           (((0 | (x)) << MCI_HW_SCHD_TBL_CTL_RW_ADDR_LSB) & MCI_HW_SCHD_TBL_CTL_RW_ADDR_MASK)
#define MCI_HW_SCHD_TBL_CTL_RW_ADDR_RESET                            0
#define MCI_HW_SCHD_TBL_CTL_CLEAR_MSB                                0
#define MCI_HW_SCHD_TBL_CTL_CLEAR_LSB                                0
#define MCI_HW_SCHD_TBL_CTL_CLEAR_MASK                               0x00000001
#define MCI_HW_SCHD_TBL_CTL_CLEAR_GET(x)                             (((x) & MCI_HW_SCHD_TBL_CTL_CLEAR_MASK) >> MCI_HW_SCHD_TBL_CTL_CLEAR_LSB)
#define MCI_HW_SCHD_TBL_CTL_CLEAR_SET(x)                             (((0 | (x)) << MCI_HW_SCHD_TBL_CTL_CLEAR_LSB) & MCI_HW_SCHD_TBL_CTL_CLEAR_MASK)
#define MCI_HW_SCHD_TBL_CTL_CLEAR_RESET                              0
#define MCI_HW_SCHD_TBL_CTL_ADDRESS                                  0x0084
#define MCI_HW_SCHD_TBL_CTL_HW_MASK                                  0xfffff81f
#define MCI_HW_SCHD_TBL_CTL_SW_MASK                                  0xfffff81f
#define MCI_HW_SCHD_TBL_CTL_HW_WRITE_MASK                            0xff0ff81f
#define MCI_HW_SCHD_TBL_CTL_SW_WRITE_MASK                            0x00f0001f
#define MCI_HW_SCHD_TBL_CTL_RSTMASK                                  0xffffffff
#define MCI_HW_SCHD_TBL_CTL_RESET                                    0x00000800

// 0x0088 (MCI_HW_SCHD_TBL_D0)
#define MCI_HW_SCHD_TBL_D0_DATA0_MSB                                 31
#define MCI_HW_SCHD_TBL_D0_DATA0_LSB                                 0
#define MCI_HW_SCHD_TBL_D0_DATA0_MASK                                0xffffffff
#define MCI_HW_SCHD_TBL_D0_DATA0_GET(x)                              (((x) & MCI_HW_SCHD_TBL_D0_DATA0_MASK) >> MCI_HW_SCHD_TBL_D0_DATA0_LSB)
#define MCI_HW_SCHD_TBL_D0_DATA0_SET(x)                              (((0 | (x)) << MCI_HW_SCHD_TBL_D0_DATA0_LSB) & MCI_HW_SCHD_TBL_D0_DATA0_MASK)
#define MCI_HW_SCHD_TBL_D0_DATA0_RESET                               0
#define MCI_HW_SCHD_TBL_D0_ADDRESS                                   0x0088
#define MCI_HW_SCHD_TBL_D0_HW_MASK                                   0xffffffff
#define MCI_HW_SCHD_TBL_D0_SW_MASK                                   0xffffffff
#define MCI_HW_SCHD_TBL_D0_HW_WRITE_MASK                             0xffffffff
#define MCI_HW_SCHD_TBL_D0_SW_WRITE_MASK                             0xffffffff
#define MCI_HW_SCHD_TBL_D0_RSTMASK                                   0xffffffff
#define MCI_HW_SCHD_TBL_D0_RESET                                     0x00000000

// 0x008c (MCI_HW_SCHD_TBL_D1)
#define MCI_HW_SCHD_TBL_D1_DATA1_MSB                                 31
#define MCI_HW_SCHD_TBL_D1_DATA1_LSB                                 0
#define MCI_HW_SCHD_TBL_D1_DATA1_MASK                                0xffffffff
#define MCI_HW_SCHD_TBL_D1_DATA1_GET(x)                              (((x) & MCI_HW_SCHD_TBL_D1_DATA1_MASK) >> MCI_HW_SCHD_TBL_D1_DATA1_LSB)
#define MCI_HW_SCHD_TBL_D1_DATA1_SET(x)                              (((0 | (x)) << MCI_HW_SCHD_TBL_D1_DATA1_LSB) & MCI_HW_SCHD_TBL_D1_DATA1_MASK)
#define MCI_HW_SCHD_TBL_D1_DATA1_RESET                               0
#define MCI_HW_SCHD_TBL_D1_ADDRESS                                   0x008c
#define MCI_HW_SCHD_TBL_D1_HW_MASK                                   0xffffffff
#define MCI_HW_SCHD_TBL_D1_SW_MASK                                   0xffffffff
#define MCI_HW_SCHD_TBL_D1_HW_WRITE_MASK                             0xffffffff
#define MCI_HW_SCHD_TBL_D1_SW_WRITE_MASK                             0xffffffff
#define MCI_HW_SCHD_TBL_D1_RSTMASK                                   0xffffffff
#define MCI_HW_SCHD_TBL_D1_RESET                                     0x00000000

// 0x0090 (MCI_HW_SCHD_TBL_D2)
#define MCI_HW_SCHD_TBL_D2_DATA2_MSB                                 31
#define MCI_HW_SCHD_TBL_D2_DATA2_LSB                                 0
#define MCI_HW_SCHD_TBL_D2_DATA2_MASK                                0xffffffff
#define MCI_HW_SCHD_TBL_D2_DATA2_GET(x)                              (((x) & MCI_HW_SCHD_TBL_D2_DATA2_MASK) >> MCI_HW_SCHD_TBL_D2_DATA2_LSB)
#define MCI_HW_SCHD_TBL_D2_DATA2_SET(x)                              (((0 | (x)) << MCI_HW_SCHD_TBL_D2_DATA2_LSB) & MCI_HW_SCHD_TBL_D2_DATA2_MASK)
#define MCI_HW_SCHD_TBL_D2_DATA2_RESET                               0
#define MCI_HW_SCHD_TBL_D2_ADDRESS                                   0x0090
#define MCI_HW_SCHD_TBL_D2_HW_MASK                                   0xffffffff
#define MCI_HW_SCHD_TBL_D2_SW_MASK                                   0xffffffff
#define MCI_HW_SCHD_TBL_D2_HW_WRITE_MASK                             0xffffffff
#define MCI_HW_SCHD_TBL_D2_SW_WRITE_MASK                             0xffffffff
#define MCI_HW_SCHD_TBL_D2_RSTMASK                                   0xffffffff
#define MCI_HW_SCHD_TBL_D2_RESET                                     0x00000000

// 0x0094 (MCI_HW_SCHD_TBL_D3)
#define MCI_HW_SCHD_TBL_D3_DATA3_MSB                                 31
#define MCI_HW_SCHD_TBL_D3_DATA3_LSB                                 0
#define MCI_HW_SCHD_TBL_D3_DATA3_MASK                                0xffffffff
#define MCI_HW_SCHD_TBL_D3_DATA3_GET(x)                              (((x) & MCI_HW_SCHD_TBL_D3_DATA3_MASK) >> MCI_HW_SCHD_TBL_D3_DATA3_LSB)
#define MCI_HW_SCHD_TBL_D3_DATA3_SET(x)                              (((0 | (x)) << MCI_HW_SCHD_TBL_D3_DATA3_LSB) & MCI_HW_SCHD_TBL_D3_DATA3_MASK)
#define MCI_HW_SCHD_TBL_D3_DATA3_RESET                               0
#define MCI_HW_SCHD_TBL_D3_ADDRESS                                   0x0094
#define MCI_HW_SCHD_TBL_D3_HW_MASK                                   0xffffffff
#define MCI_HW_SCHD_TBL_D3_SW_MASK                                   0xffffffff
#define MCI_HW_SCHD_TBL_D3_HW_WRITE_MASK                             0xffffffff
#define MCI_HW_SCHD_TBL_D3_SW_WRITE_MASK                             0xffffffff
#define MCI_HW_SCHD_TBL_D3_RSTMASK                                   0xffffffff
#define MCI_HW_SCHD_TBL_D3_RESET                                     0x00000000

// 0x0098 (MCI_TX_PAYLOAD0)
#define MCI_TX_PAYLOAD0_D0_MSB                                       31
#define MCI_TX_PAYLOAD0_D0_LSB                                       0
#define MCI_TX_PAYLOAD0_D0_MASK                                      0xffffffff
#define MCI_TX_PAYLOAD0_D0_GET(x)                                    (((x) & MCI_TX_PAYLOAD0_D0_MASK) >> MCI_TX_PAYLOAD0_D0_LSB)
#define MCI_TX_PAYLOAD0_D0_SET(x)                                    (((0 | (x)) << MCI_TX_PAYLOAD0_D0_LSB) & MCI_TX_PAYLOAD0_D0_MASK)
#define MCI_TX_PAYLOAD0_D0_RESET                                     0
#define MCI_TX_PAYLOAD0_ADDRESS                                      0x0098
#define MCI_TX_PAYLOAD0_HW_MASK                                      0xffffffff
#define MCI_TX_PAYLOAD0_SW_MASK                                      0xffffffff
#define MCI_TX_PAYLOAD0_HW_WRITE_MASK                                0x00000000
#define MCI_TX_PAYLOAD0_SW_WRITE_MASK                                0xffffffff
#define MCI_TX_PAYLOAD0_RSTMASK                                      0xffffffff
#define MCI_TX_PAYLOAD0_RESET                                        0x00000000

// 0x009c (MCI_TX_PAYLOAD1)
#define MCI_TX_PAYLOAD1_D1_MSB                                       31
#define MCI_TX_PAYLOAD1_D1_LSB                                       0
#define MCI_TX_PAYLOAD1_D1_MASK                                      0xffffffff
#define MCI_TX_PAYLOAD1_D1_GET(x)                                    (((x) & MCI_TX_PAYLOAD1_D1_MASK) >> MCI_TX_PAYLOAD1_D1_LSB)
#define MCI_TX_PAYLOAD1_D1_SET(x)                                    (((0 | (x)) << MCI_TX_PAYLOAD1_D1_LSB) & MCI_TX_PAYLOAD1_D1_MASK)
#define MCI_TX_PAYLOAD1_D1_RESET                                     0
#define MCI_TX_PAYLOAD1_ADDRESS                                      0x009c
#define MCI_TX_PAYLOAD1_HW_MASK                                      0xffffffff
#define MCI_TX_PAYLOAD1_SW_MASK                                      0xffffffff
#define MCI_TX_PAYLOAD1_HW_WRITE_MASK                                0x00000000
#define MCI_TX_PAYLOAD1_SW_WRITE_MASK                                0xffffffff
#define MCI_TX_PAYLOAD1_RSTMASK                                      0xffffffff
#define MCI_TX_PAYLOAD1_RESET                                        0x00000000

// 0x00a0 (MCI_TX_PAYLOAD2)
#define MCI_TX_PAYLOAD2_D2_MSB                                       31
#define MCI_TX_PAYLOAD2_D2_LSB                                       0
#define MCI_TX_PAYLOAD2_D2_MASK                                      0xffffffff
#define MCI_TX_PAYLOAD2_D2_GET(x)                                    (((x) & MCI_TX_PAYLOAD2_D2_MASK) >> MCI_TX_PAYLOAD2_D2_LSB)
#define MCI_TX_PAYLOAD2_D2_SET(x)                                    (((0 | (x)) << MCI_TX_PAYLOAD2_D2_LSB) & MCI_TX_PAYLOAD2_D2_MASK)
#define MCI_TX_PAYLOAD2_D2_RESET                                     0
#define MCI_TX_PAYLOAD2_ADDRESS                                      0x00a0
#define MCI_TX_PAYLOAD2_HW_MASK                                      0xffffffff
#define MCI_TX_PAYLOAD2_SW_MASK                                      0xffffffff
#define MCI_TX_PAYLOAD2_HW_WRITE_MASK                                0x00000000
#define MCI_TX_PAYLOAD2_SW_WRITE_MASK                                0xffffffff
#define MCI_TX_PAYLOAD2_RSTMASK                                      0xffffffff
#define MCI_TX_PAYLOAD2_RESET                                        0x00000000

// 0x00a4 (MCI_TX_PAYLOAD3)
#define MCI_TX_PAYLOAD3_D3_MSB                                       31
#define MCI_TX_PAYLOAD3_D3_LSB                                       0
#define MCI_TX_PAYLOAD3_D3_MASK                                      0xffffffff
#define MCI_TX_PAYLOAD3_D3_GET(x)                                    (((x) & MCI_TX_PAYLOAD3_D3_MASK) >> MCI_TX_PAYLOAD3_D3_LSB)
#define MCI_TX_PAYLOAD3_D3_SET(x)                                    (((0 | (x)) << MCI_TX_PAYLOAD3_D3_LSB) & MCI_TX_PAYLOAD3_D3_MASK)
#define MCI_TX_PAYLOAD3_D3_RESET                                     0
#define MCI_TX_PAYLOAD3_ADDRESS                                      0x00a4
#define MCI_TX_PAYLOAD3_HW_MASK                                      0xffffffff
#define MCI_TX_PAYLOAD3_SW_MASK                                      0xffffffff
#define MCI_TX_PAYLOAD3_HW_WRITE_MASK                                0x00000000
#define MCI_TX_PAYLOAD3_SW_WRITE_MASK                                0xffffffff
#define MCI_TX_PAYLOAD3_RSTMASK                                      0xffffffff
#define MCI_TX_PAYLOAD3_RESET                                        0x00000000

// 0x00a8 (BTCOEX_WBTIMER)
#define BTCOEX_WBTIMER_VALUE_MSB                                     31
#define BTCOEX_WBTIMER_VALUE_LSB                                     0
#define BTCOEX_WBTIMER_VALUE_MASK                                    0xffffffff
#define BTCOEX_WBTIMER_VALUE_GET(x)                                  (((x) & BTCOEX_WBTIMER_VALUE_MASK) >> BTCOEX_WBTIMER_VALUE_LSB)
#define BTCOEX_WBTIMER_VALUE_SET(x)                                  (((0 | (x)) << BTCOEX_WBTIMER_VALUE_LSB) & BTCOEX_WBTIMER_VALUE_MASK)
#define BTCOEX_WBTIMER_VALUE_RESET                                   0
#define BTCOEX_WBTIMER_ADDRESS                                       0x00a8
#define BTCOEX_WBTIMER_HW_MASK                                       0xffffffff
#define BTCOEX_WBTIMER_SW_MASK                                       0xffffffff
#define BTCOEX_WBTIMER_HW_WRITE_MASK                                 0xffffffff
#define BTCOEX_WBTIMER_SW_WRITE_MASK                                 0x00000000
#define BTCOEX_WBTIMER_RSTMASK                                       0xffffffff
#define BTCOEX_WBTIMER_RESET                                         0x00000000

// 0x00ac (BTCOEX_CTRL)
#define BTCOEX_CTRL_REDUCE_TXPWR_ENABLE_MSB                          29
#define BTCOEX_CTRL_REDUCE_TXPWR_ENABLE_LSB                          29
#define BTCOEX_CTRL_REDUCE_TXPWR_ENABLE_MASK                         0x20000000
#define BTCOEX_CTRL_REDUCE_TXPWR_ENABLE_GET(x)                       (((x) & BTCOEX_CTRL_REDUCE_TXPWR_ENABLE_MASK) >> BTCOEX_CTRL_REDUCE_TXPWR_ENABLE_LSB)
#define BTCOEX_CTRL_REDUCE_TXPWR_ENABLE_SET(x)                       (((0 | (x)) << BTCOEX_CTRL_REDUCE_TXPWR_ENABLE_LSB) & BTCOEX_CTRL_REDUCE_TXPWR_ENABLE_MASK)
#define BTCOEX_CTRL_REDUCE_TXPWR_ENABLE_RESET                        0
#define BTCOEX_CTRL_WAIT_BA_MARGIN_MSB                               28
#define BTCOEX_CTRL_WAIT_BA_MARGIN_LSB                               21
#define BTCOEX_CTRL_WAIT_BA_MARGIN_MASK                              0x1fe00000
#define BTCOEX_CTRL_WAIT_BA_MARGIN_GET(x)                            (((x) & BTCOEX_CTRL_WAIT_BA_MARGIN_MASK) >> BTCOEX_CTRL_WAIT_BA_MARGIN_LSB)
#define BTCOEX_CTRL_WAIT_BA_MARGIN_SET(x)                            (((0 | (x)) << BTCOEX_CTRL_WAIT_BA_MARGIN_LSB) & BTCOEX_CTRL_WAIT_BA_MARGIN_MASK)
#define BTCOEX_CTRL_WAIT_BA_MARGIN_RESET                             0
#define BTCOEX_CTRL_USE_1_CHAIN_FOR_ACK_MSB                          20
#define BTCOEX_CTRL_USE_1_CHAIN_FOR_ACK_LSB                          20
#define BTCOEX_CTRL_USE_1_CHAIN_FOR_ACK_MASK                         0x00100000
#define BTCOEX_CTRL_USE_1_CHAIN_FOR_ACK_GET(x)                       (((x) & BTCOEX_CTRL_USE_1_CHAIN_FOR_ACK_MASK) >> BTCOEX_CTRL_USE_1_CHAIN_FOR_ACK_LSB)
#define BTCOEX_CTRL_USE_1_CHAIN_FOR_ACK_SET(x)                       (((0 | (x)) << BTCOEX_CTRL_USE_1_CHAIN_FOR_ACK_LSB) & BTCOEX_CTRL_USE_1_CHAIN_FOR_ACK_MASK)
#define BTCOEX_CTRL_USE_1_CHAIN_FOR_ACK_RESET                        0
#define BTCOEX_CTRL_USE_1_CHAIN_FOR_BCN_MSB                          19
#define BTCOEX_CTRL_USE_1_CHAIN_FOR_BCN_LSB                          19
#define BTCOEX_CTRL_USE_1_CHAIN_FOR_BCN_MASK                         0x00080000
#define BTCOEX_CTRL_USE_1_CHAIN_FOR_BCN_GET(x)                       (((x) & BTCOEX_CTRL_USE_1_CHAIN_FOR_BCN_MASK) >> BTCOEX_CTRL_USE_1_CHAIN_FOR_BCN_LSB)
#define BTCOEX_CTRL_USE_1_CHAIN_FOR_BCN_SET(x)                       (((0 | (x)) << BTCOEX_CTRL_USE_1_CHAIN_FOR_BCN_LSB) & BTCOEX_CTRL_USE_1_CHAIN_FOR_BCN_MASK)
#define BTCOEX_CTRL_USE_1_CHAIN_FOR_BCN_RESET                        0
#define BTCOEX_CTRL_WL_PRIORITY_SW_CTRL_MSB                          18
#define BTCOEX_CTRL_WL_PRIORITY_SW_CTRL_LSB                          15
#define BTCOEX_CTRL_WL_PRIORITY_SW_CTRL_MASK                         0x00078000
#define BTCOEX_CTRL_WL_PRIORITY_SW_CTRL_GET(x)                       (((x) & BTCOEX_CTRL_WL_PRIORITY_SW_CTRL_MASK) >> BTCOEX_CTRL_WL_PRIORITY_SW_CTRL_LSB)
#define BTCOEX_CTRL_WL_PRIORITY_SW_CTRL_SET(x)                       (((0 | (x)) << BTCOEX_CTRL_WL_PRIORITY_SW_CTRL_LSB) & BTCOEX_CTRL_WL_PRIORITY_SW_CTRL_MASK)
#define BTCOEX_CTRL_WL_PRIORITY_SW_CTRL_RESET                        0
#define BTCOEX_CTRL_AGGR_THRESH_MSB                                  14
#define BTCOEX_CTRL_AGGR_THRESH_LSB                                  12
#define BTCOEX_CTRL_AGGR_THRESH_MASK                                 0x00007000
#define BTCOEX_CTRL_AGGR_THRESH_GET(x)                               (((x) & BTCOEX_CTRL_AGGR_THRESH_MASK) >> BTCOEX_CTRL_AGGR_THRESH_LSB)
#define BTCOEX_CTRL_AGGR_THRESH_SET(x)                               (((0 | (x)) << BTCOEX_CTRL_AGGR_THRESH_LSB) & BTCOEX_CTRL_AGGR_THRESH_MASK)
#define BTCOEX_CTRL_AGGR_THRESH_RESET                                0
#define BTCOEX_CTRL_RX_CHAIN_MASK_MSB                                11
#define BTCOEX_CTRL_RX_CHAIN_MASK_LSB                                9
#define BTCOEX_CTRL_RX_CHAIN_MASK_MASK                               0x00000e00
#define BTCOEX_CTRL_RX_CHAIN_MASK_GET(x)                             (((x) & BTCOEX_CTRL_RX_CHAIN_MASK_MASK) >> BTCOEX_CTRL_RX_CHAIN_MASK_LSB)
#define BTCOEX_CTRL_RX_CHAIN_MASK_SET(x)                             (((0 | (x)) << BTCOEX_CTRL_RX_CHAIN_MASK_LSB) & BTCOEX_CTRL_RX_CHAIN_MASK_MASK)
#define BTCOEX_CTRL_RX_CHAIN_MASK_RESET                              0
#define BTCOEX_CTRL_DEDICATED_ANT_MODE_MSB                           7
#define BTCOEX_CTRL_DEDICATED_ANT_MODE_LSB                           7
#define BTCOEX_CTRL_DEDICATED_ANT_MODE_MASK                          0x00000080
#define BTCOEX_CTRL_DEDICATED_ANT_MODE_GET(x)                        (((x) & BTCOEX_CTRL_DEDICATED_ANT_MODE_MASK) >> BTCOEX_CTRL_DEDICATED_ANT_MODE_LSB)
#define BTCOEX_CTRL_DEDICATED_ANT_MODE_SET(x)                        (((0 | (x)) << BTCOEX_CTRL_DEDICATED_ANT_MODE_LSB) & BTCOEX_CTRL_DEDICATED_ANT_MODE_MASK)
#define BTCOEX_CTRL_DEDICATED_ANT_MODE_RESET                         0
#define BTCOEX_CTRL_TIME_TO_NEXT_BT_THRESH_ENABLE_MSB                6
#define BTCOEX_CTRL_TIME_TO_NEXT_BT_THRESH_ENABLE_LSB                6
#define BTCOEX_CTRL_TIME_TO_NEXT_BT_THRESH_ENABLE_MASK               0x00000040
#define BTCOEX_CTRL_TIME_TO_NEXT_BT_THRESH_ENABLE_GET(x)             (((x) & BTCOEX_CTRL_TIME_TO_NEXT_BT_THRESH_ENABLE_MASK) >> BTCOEX_CTRL_TIME_TO_NEXT_BT_THRESH_ENABLE_LSB)
#define BTCOEX_CTRL_TIME_TO_NEXT_BT_THRESH_ENABLE_SET(x)             (((0 | (x)) << BTCOEX_CTRL_TIME_TO_NEXT_BT_THRESH_ENABLE_LSB) & BTCOEX_CTRL_TIME_TO_NEXT_BT_THRESH_ENABLE_MASK)
#define BTCOEX_CTRL_TIME_TO_NEXT_BT_THRESH_ENABLE_RESET              0
#define BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_ENABLE_MSB                   5
#define BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_ENABLE_LSB                   5
#define BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_ENABLE_MASK                  0x00000020
#define BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_ENABLE_GET(x)                (((x) & BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_ENABLE_MASK) >> BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_ENABLE_LSB)
#define BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_ENABLE_SET(x)                (((0 | (x)) << BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_ENABLE_LSB) & BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_ENABLE_MASK)
#define BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_ENABLE_RESET                 0
#define BTCOEX_CTRL_PA_SHARED_MSB                                    4
#define BTCOEX_CTRL_PA_SHARED_LSB                                    4
#define BTCOEX_CTRL_PA_SHARED_MASK                                   0x00000010
#define BTCOEX_CTRL_PA_SHARED_GET(x)                                 (((x) & BTCOEX_CTRL_PA_SHARED_MASK) >> BTCOEX_CTRL_PA_SHARED_LSB)
#define BTCOEX_CTRL_PA_SHARED_SET(x)                                 (((0 | (x)) << BTCOEX_CTRL_PA_SHARED_LSB) & BTCOEX_CTRL_PA_SHARED_MASK)
#define BTCOEX_CTRL_PA_SHARED_RESET                                  0
#define BTCOEX_CTRL_LNA_SHARED_MSB                                   3
#define BTCOEX_CTRL_LNA_SHARED_LSB                                   3
#define BTCOEX_CTRL_LNA_SHARED_MASK                                  0x00000008
#define BTCOEX_CTRL_LNA_SHARED_GET(x)                                (((x) & BTCOEX_CTRL_LNA_SHARED_MASK) >> BTCOEX_CTRL_LNA_SHARED_LSB)
#define BTCOEX_CTRL_LNA_SHARED_SET(x)                                (((0 | (x)) << BTCOEX_CTRL_LNA_SHARED_LSB) & BTCOEX_CTRL_LNA_SHARED_MASK)
#define BTCOEX_CTRL_LNA_SHARED_RESET                                 0
#define BTCOEX_CTRL_MCI_MODE_ENABLE_MSB                              2
#define BTCOEX_CTRL_MCI_MODE_ENABLE_LSB                              2
#define BTCOEX_CTRL_MCI_MODE_ENABLE_MASK                             0x00000004
#define BTCOEX_CTRL_MCI_MODE_ENABLE_GET(x)                           (((x) & BTCOEX_CTRL_MCI_MODE_ENABLE_MASK) >> BTCOEX_CTRL_MCI_MODE_ENABLE_LSB)
#define BTCOEX_CTRL_MCI_MODE_ENABLE_SET(x)                           (((0 | (x)) << BTCOEX_CTRL_MCI_MODE_ENABLE_LSB) & BTCOEX_CTRL_MCI_MODE_ENABLE_MASK)
#define BTCOEX_CTRL_MCI_MODE_ENABLE_RESET                            0
#define BTCOEX_CTRL_WBTIMER_ENABLE_MSB                               1
#define BTCOEX_CTRL_WBTIMER_ENABLE_LSB                               1
#define BTCOEX_CTRL_WBTIMER_ENABLE_MASK                              0x00000002
#define BTCOEX_CTRL_WBTIMER_ENABLE_GET(x)                            (((x) & BTCOEX_CTRL_WBTIMER_ENABLE_MASK) >> BTCOEX_CTRL_WBTIMER_ENABLE_LSB)
#define BTCOEX_CTRL_WBTIMER_ENABLE_SET(x)                            (((0 | (x)) << BTCOEX_CTRL_WBTIMER_ENABLE_LSB) & BTCOEX_CTRL_WBTIMER_ENABLE_MASK)
#define BTCOEX_CTRL_WBTIMER_ENABLE_RESET                             0
#define BTCOEX_CTRL_JUPITER_MODE_MSB                                 0
#define BTCOEX_CTRL_JUPITER_MODE_LSB                                 0
#define BTCOEX_CTRL_JUPITER_MODE_MASK                                0x00000001
#define BTCOEX_CTRL_JUPITER_MODE_GET(x)                              (((x) & BTCOEX_CTRL_JUPITER_MODE_MASK) >> BTCOEX_CTRL_JUPITER_MODE_LSB)
#define BTCOEX_CTRL_JUPITER_MODE_SET(x)                              (((0 | (x)) << BTCOEX_CTRL_JUPITER_MODE_LSB) & BTCOEX_CTRL_JUPITER_MODE_MASK)
#define BTCOEX_CTRL_JUPITER_MODE_RESET                               0
#define BTCOEX_CTRL_ADDRESS                                          0x00ac
#define BTCOEX_CTRL_HW_MASK                                          0x3ffffeff
#define BTCOEX_CTRL_SW_MASK                                          0x3ffffeff
#define BTCOEX_CTRL_HW_WRITE_MASK                                    0x00000002
#define BTCOEX_CTRL_SW_WRITE_MASK                                    0x3ffffeff
#define BTCOEX_CTRL_RSTMASK                                          0xffffffff
#define BTCOEX_CTRL_RESET                                            0x00000000

// 0x00b0 (BTCOEX_WL_WEIGHTS0)
#define BTCOEX_WL_WEIGHTS0_VALUE3_MSB                                31
#define BTCOEX_WL_WEIGHTS0_VALUE3_LSB                                24
#define BTCOEX_WL_WEIGHTS0_VALUE3_MASK                               0xff000000
#define BTCOEX_WL_WEIGHTS0_VALUE3_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS0_VALUE3_MASK) >> BTCOEX_WL_WEIGHTS0_VALUE3_LSB)
#define BTCOEX_WL_WEIGHTS0_VALUE3_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS0_VALUE3_LSB) & BTCOEX_WL_WEIGHTS0_VALUE3_MASK)
#define BTCOEX_WL_WEIGHTS0_VALUE3_RESET                              0
#define BTCOEX_WL_WEIGHTS0_VALUE2_MSB                                23
#define BTCOEX_WL_WEIGHTS0_VALUE2_LSB                                16
#define BTCOEX_WL_WEIGHTS0_VALUE2_MASK                               0x00ff0000
#define BTCOEX_WL_WEIGHTS0_VALUE2_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS0_VALUE2_MASK) >> BTCOEX_WL_WEIGHTS0_VALUE2_LSB)
#define BTCOEX_WL_WEIGHTS0_VALUE2_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS0_VALUE2_LSB) & BTCOEX_WL_WEIGHTS0_VALUE2_MASK)
#define BTCOEX_WL_WEIGHTS0_VALUE2_RESET                              0
#define BTCOEX_WL_WEIGHTS0_VALUE1_MSB                                15
#define BTCOEX_WL_WEIGHTS0_VALUE1_LSB                                8
#define BTCOEX_WL_WEIGHTS0_VALUE1_MASK                               0x0000ff00
#define BTCOEX_WL_WEIGHTS0_VALUE1_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS0_VALUE1_MASK) >> BTCOEX_WL_WEIGHTS0_VALUE1_LSB)
#define BTCOEX_WL_WEIGHTS0_VALUE1_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS0_VALUE1_LSB) & BTCOEX_WL_WEIGHTS0_VALUE1_MASK)
#define BTCOEX_WL_WEIGHTS0_VALUE1_RESET                              0
#define BTCOEX_WL_WEIGHTS0_VALUE0_MSB                                7
#define BTCOEX_WL_WEIGHTS0_VALUE0_LSB                                0
#define BTCOEX_WL_WEIGHTS0_VALUE0_MASK                               0x000000ff
#define BTCOEX_WL_WEIGHTS0_VALUE0_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS0_VALUE0_MASK) >> BTCOEX_WL_WEIGHTS0_VALUE0_LSB)
#define BTCOEX_WL_WEIGHTS0_VALUE0_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS0_VALUE0_LSB) & BTCOEX_WL_WEIGHTS0_VALUE0_MASK)
#define BTCOEX_WL_WEIGHTS0_VALUE0_RESET                              0
#define BTCOEX_WL_WEIGHTS0_ADDRESS                                   0x00b0
#define BTCOEX_WL_WEIGHTS0_HW_MASK                                   0xffffffff
#define BTCOEX_WL_WEIGHTS0_SW_MASK                                   0xffffffff
#define BTCOEX_WL_WEIGHTS0_HW_WRITE_MASK                             0x00000000
#define BTCOEX_WL_WEIGHTS0_SW_WRITE_MASK                             0xffffffff
#define BTCOEX_WL_WEIGHTS0_RSTMASK                                   0xffffffff
#define BTCOEX_WL_WEIGHTS0_RESET                                     0x00000000

// 0x00b4 (BTCOEX_WL_WEIGHTS1)
#define BTCOEX_WL_WEIGHTS1_VALUE3_MSB                                31
#define BTCOEX_WL_WEIGHTS1_VALUE3_LSB                                24
#define BTCOEX_WL_WEIGHTS1_VALUE3_MASK                               0xff000000
#define BTCOEX_WL_WEIGHTS1_VALUE3_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS1_VALUE3_MASK) >> BTCOEX_WL_WEIGHTS1_VALUE3_LSB)
#define BTCOEX_WL_WEIGHTS1_VALUE3_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS1_VALUE3_LSB) & BTCOEX_WL_WEIGHTS1_VALUE3_MASK)
#define BTCOEX_WL_WEIGHTS1_VALUE3_RESET                              0
#define BTCOEX_WL_WEIGHTS1_VALUE2_MSB                                23
#define BTCOEX_WL_WEIGHTS1_VALUE2_LSB                                16
#define BTCOEX_WL_WEIGHTS1_VALUE2_MASK                               0x00ff0000
#define BTCOEX_WL_WEIGHTS1_VALUE2_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS1_VALUE2_MASK) >> BTCOEX_WL_WEIGHTS1_VALUE2_LSB)
#define BTCOEX_WL_WEIGHTS1_VALUE2_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS1_VALUE2_LSB) & BTCOEX_WL_WEIGHTS1_VALUE2_MASK)
#define BTCOEX_WL_WEIGHTS1_VALUE2_RESET                              0
#define BTCOEX_WL_WEIGHTS1_VALUE1_MSB                                15
#define BTCOEX_WL_WEIGHTS1_VALUE1_LSB                                8
#define BTCOEX_WL_WEIGHTS1_VALUE1_MASK                               0x0000ff00
#define BTCOEX_WL_WEIGHTS1_VALUE1_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS1_VALUE1_MASK) >> BTCOEX_WL_WEIGHTS1_VALUE1_LSB)
#define BTCOEX_WL_WEIGHTS1_VALUE1_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS1_VALUE1_LSB) & BTCOEX_WL_WEIGHTS1_VALUE1_MASK)
#define BTCOEX_WL_WEIGHTS1_VALUE1_RESET                              0
#define BTCOEX_WL_WEIGHTS1_VALUE0_MSB                                7
#define BTCOEX_WL_WEIGHTS1_VALUE0_LSB                                0
#define BTCOEX_WL_WEIGHTS1_VALUE0_MASK                               0x000000ff
#define BTCOEX_WL_WEIGHTS1_VALUE0_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS1_VALUE0_MASK) >> BTCOEX_WL_WEIGHTS1_VALUE0_LSB)
#define BTCOEX_WL_WEIGHTS1_VALUE0_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS1_VALUE0_LSB) & BTCOEX_WL_WEIGHTS1_VALUE0_MASK)
#define BTCOEX_WL_WEIGHTS1_VALUE0_RESET                              0
#define BTCOEX_WL_WEIGHTS1_ADDRESS                                   0x00b4
#define BTCOEX_WL_WEIGHTS1_HW_MASK                                   0xffffffff
#define BTCOEX_WL_WEIGHTS1_SW_MASK                                   0xffffffff
#define BTCOEX_WL_WEIGHTS1_HW_WRITE_MASK                             0x00000000
#define BTCOEX_WL_WEIGHTS1_SW_WRITE_MASK                             0xffffffff
#define BTCOEX_WL_WEIGHTS1_RSTMASK                                   0xffffffff
#define BTCOEX_WL_WEIGHTS1_RESET                                     0x00000000

// 0x00b8 (BTCOEX_WL_WEIGHTS2)
#define BTCOEX_WL_WEIGHTS2_VALUE3_MSB                                31
#define BTCOEX_WL_WEIGHTS2_VALUE3_LSB                                24
#define BTCOEX_WL_WEIGHTS2_VALUE3_MASK                               0xff000000
#define BTCOEX_WL_WEIGHTS2_VALUE3_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS2_VALUE3_MASK) >> BTCOEX_WL_WEIGHTS2_VALUE3_LSB)
#define BTCOEX_WL_WEIGHTS2_VALUE3_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS2_VALUE3_LSB) & BTCOEX_WL_WEIGHTS2_VALUE3_MASK)
#define BTCOEX_WL_WEIGHTS2_VALUE3_RESET                              0
#define BTCOEX_WL_WEIGHTS2_VALUE2_MSB                                23
#define BTCOEX_WL_WEIGHTS2_VALUE2_LSB                                16
#define BTCOEX_WL_WEIGHTS2_VALUE2_MASK                               0x00ff0000
#define BTCOEX_WL_WEIGHTS2_VALUE2_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS2_VALUE2_MASK) >> BTCOEX_WL_WEIGHTS2_VALUE2_LSB)
#define BTCOEX_WL_WEIGHTS2_VALUE2_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS2_VALUE2_LSB) & BTCOEX_WL_WEIGHTS2_VALUE2_MASK)
#define BTCOEX_WL_WEIGHTS2_VALUE2_RESET                              0
#define BTCOEX_WL_WEIGHTS2_VALUE1_MSB                                15
#define BTCOEX_WL_WEIGHTS2_VALUE1_LSB                                8
#define BTCOEX_WL_WEIGHTS2_VALUE1_MASK                               0x0000ff00
#define BTCOEX_WL_WEIGHTS2_VALUE1_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS2_VALUE1_MASK) >> BTCOEX_WL_WEIGHTS2_VALUE1_LSB)
#define BTCOEX_WL_WEIGHTS2_VALUE1_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS2_VALUE1_LSB) & BTCOEX_WL_WEIGHTS2_VALUE1_MASK)
#define BTCOEX_WL_WEIGHTS2_VALUE1_RESET                              0
#define BTCOEX_WL_WEIGHTS2_VALUE0_MSB                                7
#define BTCOEX_WL_WEIGHTS2_VALUE0_LSB                                0
#define BTCOEX_WL_WEIGHTS2_VALUE0_MASK                               0x000000ff
#define BTCOEX_WL_WEIGHTS2_VALUE0_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS2_VALUE0_MASK) >> BTCOEX_WL_WEIGHTS2_VALUE0_LSB)
#define BTCOEX_WL_WEIGHTS2_VALUE0_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS2_VALUE0_LSB) & BTCOEX_WL_WEIGHTS2_VALUE0_MASK)
#define BTCOEX_WL_WEIGHTS2_VALUE0_RESET                              0
#define BTCOEX_WL_WEIGHTS2_ADDRESS                                   0x00b8
#define BTCOEX_WL_WEIGHTS2_HW_MASK                                   0xffffffff
#define BTCOEX_WL_WEIGHTS2_SW_MASK                                   0xffffffff
#define BTCOEX_WL_WEIGHTS2_HW_WRITE_MASK                             0x00000000
#define BTCOEX_WL_WEIGHTS2_SW_WRITE_MASK                             0xffffffff
#define BTCOEX_WL_WEIGHTS2_RSTMASK                                   0xffffffff
#define BTCOEX_WL_WEIGHTS2_RESET                                     0x00000000

// 0x00bc (BTCOEX_WL_WEIGHTS3)
#define BTCOEX_WL_WEIGHTS3_VALUE3_MSB                                31
#define BTCOEX_WL_WEIGHTS3_VALUE3_LSB                                24
#define BTCOEX_WL_WEIGHTS3_VALUE3_MASK                               0xff000000
#define BTCOEX_WL_WEIGHTS3_VALUE3_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS3_VALUE3_MASK) >> BTCOEX_WL_WEIGHTS3_VALUE3_LSB)
#define BTCOEX_WL_WEIGHTS3_VALUE3_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS3_VALUE3_LSB) & BTCOEX_WL_WEIGHTS3_VALUE3_MASK)
#define BTCOEX_WL_WEIGHTS3_VALUE3_RESET                              0
#define BTCOEX_WL_WEIGHTS3_VALUE2_MSB                                23
#define BTCOEX_WL_WEIGHTS3_VALUE2_LSB                                16
#define BTCOEX_WL_WEIGHTS3_VALUE2_MASK                               0x00ff0000
#define BTCOEX_WL_WEIGHTS3_VALUE2_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS3_VALUE2_MASK) >> BTCOEX_WL_WEIGHTS3_VALUE2_LSB)
#define BTCOEX_WL_WEIGHTS3_VALUE2_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS3_VALUE2_LSB) & BTCOEX_WL_WEIGHTS3_VALUE2_MASK)
#define BTCOEX_WL_WEIGHTS3_VALUE2_RESET                              0
#define BTCOEX_WL_WEIGHTS3_VALUE1_MSB                                15
#define BTCOEX_WL_WEIGHTS3_VALUE1_LSB                                8
#define BTCOEX_WL_WEIGHTS3_VALUE1_MASK                               0x0000ff00
#define BTCOEX_WL_WEIGHTS3_VALUE1_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS3_VALUE1_MASK) >> BTCOEX_WL_WEIGHTS3_VALUE1_LSB)
#define BTCOEX_WL_WEIGHTS3_VALUE1_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS3_VALUE1_LSB) & BTCOEX_WL_WEIGHTS3_VALUE1_MASK)
#define BTCOEX_WL_WEIGHTS3_VALUE1_RESET                              0
#define BTCOEX_WL_WEIGHTS3_VALUE0_MSB                                7
#define BTCOEX_WL_WEIGHTS3_VALUE0_LSB                                0
#define BTCOEX_WL_WEIGHTS3_VALUE0_MASK                               0x000000ff
#define BTCOEX_WL_WEIGHTS3_VALUE0_GET(x)                             (((x) & BTCOEX_WL_WEIGHTS3_VALUE0_MASK) >> BTCOEX_WL_WEIGHTS3_VALUE0_LSB)
#define BTCOEX_WL_WEIGHTS3_VALUE0_SET(x)                             (((0 | (x)) << BTCOEX_WL_WEIGHTS3_VALUE0_LSB) & BTCOEX_WL_WEIGHTS3_VALUE0_MASK)
#define BTCOEX_WL_WEIGHTS3_VALUE0_RESET                              0
#define BTCOEX_WL_WEIGHTS3_ADDRESS                                   0x00bc
#define BTCOEX_WL_WEIGHTS3_HW_MASK                                   0xffffffff
#define BTCOEX_WL_WEIGHTS3_SW_MASK                                   0xffffffff
#define BTCOEX_WL_WEIGHTS3_HW_WRITE_MASK                             0x00000000
#define BTCOEX_WL_WEIGHTS3_SW_WRITE_MASK                             0xffffffff
#define BTCOEX_WL_WEIGHTS3_RSTMASK                                   0xffffffff
#define BTCOEX_WL_WEIGHTS3_RESET                                     0x00000000

// 0x00c0 (BTCOEX_MAX_TXPWR_0)
#define BTCOEX_MAX_TXPWR_0_DATA_MSB                                  31
#define BTCOEX_MAX_TXPWR_0_DATA_LSB                                  0
#define BTCOEX_MAX_TXPWR_0_DATA_MASK                                 0xffffffff
#define BTCOEX_MAX_TXPWR_0_DATA_GET(x)                               (((x) & BTCOEX_MAX_TXPWR_0_DATA_MASK) >> BTCOEX_MAX_TXPWR_0_DATA_LSB)
#define BTCOEX_MAX_TXPWR_0_DATA_SET(x)                               (((0 | (x)) << BTCOEX_MAX_TXPWR_0_DATA_LSB) & BTCOEX_MAX_TXPWR_0_DATA_MASK)
#define BTCOEX_MAX_TXPWR_0_DATA_RESET                                0
#define BTCOEX_MAX_TXPWR_0_ADDRESS                                   0x00c0
#define BTCOEX_MAX_TXPWR_ADDRESS                                     BTCOEX_MAX_TXPWR_0_ADDRESS
#define BTCOEX_MAX_TXPWR_0_HW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_0_SW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_0_HW_WRITE_MASK                             0x00000000
#define BTCOEX_MAX_TXPWR_0_SW_WRITE_MASK                             0xffffffff
#define BTCOEX_MAX_TXPWR_0_RSTMASK                                   0x00000000
#define BTCOEX_MAX_TXPWR_0_RESET                                     0x00000000

// 0x00c4 (BTCOEX_MAX_TXPWR_1)
#define BTCOEX_MAX_TXPWR_1_DATA_MSB                                  31
#define BTCOEX_MAX_TXPWR_1_DATA_LSB                                  0
#define BTCOEX_MAX_TXPWR_1_DATA_MASK                                 0xffffffff
#define BTCOEX_MAX_TXPWR_1_DATA_GET(x)                               (((x) & BTCOEX_MAX_TXPWR_1_DATA_MASK) >> BTCOEX_MAX_TXPWR_1_DATA_LSB)
#define BTCOEX_MAX_TXPWR_1_DATA_SET(x)                               (((0 | (x)) << BTCOEX_MAX_TXPWR_1_DATA_LSB) & BTCOEX_MAX_TXPWR_1_DATA_MASK)
#define BTCOEX_MAX_TXPWR_1_DATA_RESET                                0
#define BTCOEX_MAX_TXPWR_1_ADDRESS                                   0x00c4
#define BTCOEX_MAX_TXPWR_1_HW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_1_SW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_1_HW_WRITE_MASK                             0x00000000
#define BTCOEX_MAX_TXPWR_1_SW_WRITE_MASK                             0xffffffff
#define BTCOEX_MAX_TXPWR_1_RSTMASK                                   0x00000000
#define BTCOEX_MAX_TXPWR_1_RESET                                     0x00000000

// 0x00c8 (BTCOEX_MAX_TXPWR_2)
#define BTCOEX_MAX_TXPWR_2_DATA_MSB                                  31
#define BTCOEX_MAX_TXPWR_2_DATA_LSB                                  0
#define BTCOEX_MAX_TXPWR_2_DATA_MASK                                 0xffffffff
#define BTCOEX_MAX_TXPWR_2_DATA_GET(x)                               (((x) & BTCOEX_MAX_TXPWR_2_DATA_MASK) >> BTCOEX_MAX_TXPWR_2_DATA_LSB)
#define BTCOEX_MAX_TXPWR_2_DATA_SET(x)                               (((0 | (x)) << BTCOEX_MAX_TXPWR_2_DATA_LSB) & BTCOEX_MAX_TXPWR_2_DATA_MASK)
#define BTCOEX_MAX_TXPWR_2_DATA_RESET                                0
#define BTCOEX_MAX_TXPWR_2_ADDRESS                                   0x00c8
#define BTCOEX_MAX_TXPWR_2_HW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_2_SW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_2_HW_WRITE_MASK                             0x00000000
#define BTCOEX_MAX_TXPWR_2_SW_WRITE_MASK                             0xffffffff
#define BTCOEX_MAX_TXPWR_2_RSTMASK                                   0x00000000
#define BTCOEX_MAX_TXPWR_2_RESET                                     0x00000000

// 0x00cc (BTCOEX_MAX_TXPWR_3)
#define BTCOEX_MAX_TXPWR_3_DATA_MSB                                  31
#define BTCOEX_MAX_TXPWR_3_DATA_LSB                                  0
#define BTCOEX_MAX_TXPWR_3_DATA_MASK                                 0xffffffff
#define BTCOEX_MAX_TXPWR_3_DATA_GET(x)                               (((x) & BTCOEX_MAX_TXPWR_3_DATA_MASK) >> BTCOEX_MAX_TXPWR_3_DATA_LSB)
#define BTCOEX_MAX_TXPWR_3_DATA_SET(x)                               (((0 | (x)) << BTCOEX_MAX_TXPWR_3_DATA_LSB) & BTCOEX_MAX_TXPWR_3_DATA_MASK)
#define BTCOEX_MAX_TXPWR_3_DATA_RESET                                0
#define BTCOEX_MAX_TXPWR_3_ADDRESS                                   0x00cc
#define BTCOEX_MAX_TXPWR_3_HW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_3_SW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_3_HW_WRITE_MASK                             0x00000000
#define BTCOEX_MAX_TXPWR_3_SW_WRITE_MASK                             0xffffffff
#define BTCOEX_MAX_TXPWR_3_RSTMASK                                   0x00000000
#define BTCOEX_MAX_TXPWR_3_RESET                                     0x00000000

// 0x00d0 (BTCOEX_MAX_TXPWR_4)
#define BTCOEX_MAX_TXPWR_4_DATA_MSB                                  31
#define BTCOEX_MAX_TXPWR_4_DATA_LSB                                  0
#define BTCOEX_MAX_TXPWR_4_DATA_MASK                                 0xffffffff
#define BTCOEX_MAX_TXPWR_4_DATA_GET(x)                               (((x) & BTCOEX_MAX_TXPWR_4_DATA_MASK) >> BTCOEX_MAX_TXPWR_4_DATA_LSB)
#define BTCOEX_MAX_TXPWR_4_DATA_SET(x)                               (((0 | (x)) << BTCOEX_MAX_TXPWR_4_DATA_LSB) & BTCOEX_MAX_TXPWR_4_DATA_MASK)
#define BTCOEX_MAX_TXPWR_4_DATA_RESET                                0
#define BTCOEX_MAX_TXPWR_4_ADDRESS                                   0x00d0
#define BTCOEX_MAX_TXPWR_4_HW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_4_SW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_4_HW_WRITE_MASK                             0x00000000
#define BTCOEX_MAX_TXPWR_4_SW_WRITE_MASK                             0xffffffff
#define BTCOEX_MAX_TXPWR_4_RSTMASK                                   0x00000000
#define BTCOEX_MAX_TXPWR_4_RESET                                     0x00000000

// 0x00d4 (BTCOEX_MAX_TXPWR_5)
#define BTCOEX_MAX_TXPWR_5_DATA_MSB                                  31
#define BTCOEX_MAX_TXPWR_5_DATA_LSB                                  0
#define BTCOEX_MAX_TXPWR_5_DATA_MASK                                 0xffffffff
#define BTCOEX_MAX_TXPWR_5_DATA_GET(x)                               (((x) & BTCOEX_MAX_TXPWR_5_DATA_MASK) >> BTCOEX_MAX_TXPWR_5_DATA_LSB)
#define BTCOEX_MAX_TXPWR_5_DATA_SET(x)                               (((0 | (x)) << BTCOEX_MAX_TXPWR_5_DATA_LSB) & BTCOEX_MAX_TXPWR_5_DATA_MASK)
#define BTCOEX_MAX_TXPWR_5_DATA_RESET                                0
#define BTCOEX_MAX_TXPWR_5_ADDRESS                                   0x00d4
#define BTCOEX_MAX_TXPWR_5_HW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_5_SW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_5_HW_WRITE_MASK                             0x00000000
#define BTCOEX_MAX_TXPWR_5_SW_WRITE_MASK                             0xffffffff
#define BTCOEX_MAX_TXPWR_5_RSTMASK                                   0x00000000
#define BTCOEX_MAX_TXPWR_5_RESET                                     0x00000000

// 0x00d8 (BTCOEX_MAX_TXPWR_6)
#define BTCOEX_MAX_TXPWR_6_DATA_MSB                                  31
#define BTCOEX_MAX_TXPWR_6_DATA_LSB                                  0
#define BTCOEX_MAX_TXPWR_6_DATA_MASK                                 0xffffffff
#define BTCOEX_MAX_TXPWR_6_DATA_GET(x)                               (((x) & BTCOEX_MAX_TXPWR_6_DATA_MASK) >> BTCOEX_MAX_TXPWR_6_DATA_LSB)
#define BTCOEX_MAX_TXPWR_6_DATA_SET(x)                               (((0 | (x)) << BTCOEX_MAX_TXPWR_6_DATA_LSB) & BTCOEX_MAX_TXPWR_6_DATA_MASK)
#define BTCOEX_MAX_TXPWR_6_DATA_RESET                                0
#define BTCOEX_MAX_TXPWR_6_ADDRESS                                   0x00d8
#define BTCOEX_MAX_TXPWR_6_HW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_6_SW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_6_HW_WRITE_MASK                             0x00000000
#define BTCOEX_MAX_TXPWR_6_SW_WRITE_MASK                             0xffffffff
#define BTCOEX_MAX_TXPWR_6_RSTMASK                                   0x00000000
#define BTCOEX_MAX_TXPWR_6_RESET                                     0x00000000

// 0x00dc (BTCOEX_MAX_TXPWR_7)
#define BTCOEX_MAX_TXPWR_7_DATA_MSB                                  31
#define BTCOEX_MAX_TXPWR_7_DATA_LSB                                  0
#define BTCOEX_MAX_TXPWR_7_DATA_MASK                                 0xffffffff
#define BTCOEX_MAX_TXPWR_7_DATA_GET(x)                               (((x) & BTCOEX_MAX_TXPWR_7_DATA_MASK) >> BTCOEX_MAX_TXPWR_7_DATA_LSB)
#define BTCOEX_MAX_TXPWR_7_DATA_SET(x)                               (((0 | (x)) << BTCOEX_MAX_TXPWR_7_DATA_LSB) & BTCOEX_MAX_TXPWR_7_DATA_MASK)
#define BTCOEX_MAX_TXPWR_7_DATA_RESET                                0
#define BTCOEX_MAX_TXPWR_7_ADDRESS                                   0x00dc
#define BTCOEX_MAX_TXPWR_7_HW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_7_SW_MASK                                   0xffffffff
#define BTCOEX_MAX_TXPWR_7_HW_WRITE_MASK                             0x00000000
#define BTCOEX_MAX_TXPWR_7_SW_WRITE_MASK                             0xffffffff
#define BTCOEX_MAX_TXPWR_7_RSTMASK                                   0x00000000
#define BTCOEX_MAX_TXPWR_7_RESET                                     0x00000000

// 0x0140 (BTCOEX_WL_LNA)
#define BTCOEX_WL_LNA_INFO_MSG_LEGACY_MSB                            22
#define BTCOEX_WL_LNA_INFO_MSG_LEGACY_LSB                            22
#define BTCOEX_WL_LNA_INFO_MSG_LEGACY_MASK                           0x00400000
#define BTCOEX_WL_LNA_INFO_MSG_LEGACY_GET(x)                         (((x) & BTCOEX_WL_LNA_INFO_MSG_LEGACY_MASK) >> BTCOEX_WL_LNA_INFO_MSG_LEGACY_LSB)
#define BTCOEX_WL_LNA_INFO_MSG_LEGACY_SET(x)                         (((0 | (x)) << BTCOEX_WL_LNA_INFO_MSG_LEGACY_LSB) & BTCOEX_WL_LNA_INFO_MSG_LEGACY_MASK)
#define BTCOEX_WL_LNA_INFO_MSG_LEGACY_RESET                          0
#define BTCOEX_WL_LNA_STATE_TIMEOUT_MSB                              21
#define BTCOEX_WL_LNA_STATE_TIMEOUT_LSB                              0
#define BTCOEX_WL_LNA_STATE_TIMEOUT_MASK                             0x003fffff
#define BTCOEX_WL_LNA_STATE_TIMEOUT_GET(x)                           (((x) & BTCOEX_WL_LNA_STATE_TIMEOUT_MASK) >> BTCOEX_WL_LNA_STATE_TIMEOUT_LSB)
#define BTCOEX_WL_LNA_STATE_TIMEOUT_SET(x)                           (((0 | (x)) << BTCOEX_WL_LNA_STATE_TIMEOUT_LSB) & BTCOEX_WL_LNA_STATE_TIMEOUT_MASK)
#define BTCOEX_WL_LNA_STATE_TIMEOUT_RESET                            2560000
#define BTCOEX_WL_LNA_ADDRESS                                        0x0140
#define BTCOEX_WL_LNA_HW_MASK                                        0x007fffff
#define BTCOEX_WL_LNA_SW_MASK                                        0x007fffff
#define BTCOEX_WL_LNA_HW_WRITE_MASK                                  0x00000000
#define BTCOEX_WL_LNA_SW_WRITE_MASK                                  0x007fffff
#define BTCOEX_WL_LNA_RSTMASK                                        0xffffffff
#define BTCOEX_WL_LNA_RESET                                          0x00271000

// 0x0144 (BTCOEX_RFGAIN_CTRL)
#define BTCOEX_RFGAIN_CTRL_ANT_ISOLATION_MSB                         18
#define BTCOEX_RFGAIN_CTRL_ANT_ISOLATION_LSB                         13
#define BTCOEX_RFGAIN_CTRL_ANT_ISOLATION_MASK                        0x0007e000
#define BTCOEX_RFGAIN_CTRL_ANT_ISOLATION_GET(x)                      (((x) & BTCOEX_RFGAIN_CTRL_ANT_ISOLATION_MASK) >> BTCOEX_RFGAIN_CTRL_ANT_ISOLATION_LSB)
#define BTCOEX_RFGAIN_CTRL_ANT_ISOLATION_SET(x)                      (((0 | (x)) << BTCOEX_RFGAIN_CTRL_ANT_ISOLATION_LSB) & BTCOEX_RFGAIN_CTRL_ANT_ISOLATION_MASK)
#define BTCOEX_RFGAIN_CTRL_ANT_ISOLATION_RESET                       0
#define BTCOEX_RFGAIN_CTRL_GAIN_CAP_TIME_THRESHOLD_MSB               12
#define BTCOEX_RFGAIN_CTRL_GAIN_CAP_TIME_THRESHOLD_LSB               8
#define BTCOEX_RFGAIN_CTRL_GAIN_CAP_TIME_THRESHOLD_MASK              0x00001f00
#define BTCOEX_RFGAIN_CTRL_GAIN_CAP_TIME_THRESHOLD_GET(x)            (((x) & BTCOEX_RFGAIN_CTRL_GAIN_CAP_TIME_THRESHOLD_MASK) >> BTCOEX_RFGAIN_CTRL_GAIN_CAP_TIME_THRESHOLD_LSB)
#define BTCOEX_RFGAIN_CTRL_GAIN_CAP_TIME_THRESHOLD_SET(x)            (((0 | (x)) << BTCOEX_RFGAIN_CTRL_GAIN_CAP_TIME_THRESHOLD_LSB) & BTCOEX_RFGAIN_CTRL_GAIN_CAP_TIME_THRESHOLD_MASK)
#define BTCOEX_RFGAIN_CTRL_GAIN_CAP_TIME_THRESHOLD_RESET             2
#define BTCOEX_RFGAIN_CTRL_SW_GAIN_CAP_MSB                           7
#define BTCOEX_RFGAIN_CTRL_SW_GAIN_CAP_LSB                           1
#define BTCOEX_RFGAIN_CTRL_SW_GAIN_CAP_MASK                          0x000000fe
#define BTCOEX_RFGAIN_CTRL_SW_GAIN_CAP_GET(x)                        (((x) & BTCOEX_RFGAIN_CTRL_SW_GAIN_CAP_MASK) >> BTCOEX_RFGAIN_CTRL_SW_GAIN_CAP_LSB)
#define BTCOEX_RFGAIN_CTRL_SW_GAIN_CAP_SET(x)                        (((0 | (x)) << BTCOEX_RFGAIN_CTRL_SW_GAIN_CAP_LSB) & BTCOEX_RFGAIN_CTRL_SW_GAIN_CAP_MASK)
#define BTCOEX_RFGAIN_CTRL_SW_GAIN_CAP_RESET                         0
#define BTCOEX_RFGAIN_CTRL_GAIN_CAP_ENABLE_MSB                       0
#define BTCOEX_RFGAIN_CTRL_GAIN_CAP_ENABLE_LSB                       0
#define BTCOEX_RFGAIN_CTRL_GAIN_CAP_ENABLE_MASK                      0x00000001
#define BTCOEX_RFGAIN_CTRL_GAIN_CAP_ENABLE_GET(x)                    (((x) & BTCOEX_RFGAIN_CTRL_GAIN_CAP_ENABLE_MASK) >> BTCOEX_RFGAIN_CTRL_GAIN_CAP_ENABLE_LSB)
#define BTCOEX_RFGAIN_CTRL_GAIN_CAP_ENABLE_SET(x)                    (((0 | (x)) << BTCOEX_RFGAIN_CTRL_GAIN_CAP_ENABLE_LSB) & BTCOEX_RFGAIN_CTRL_GAIN_CAP_ENABLE_MASK)
#define BTCOEX_RFGAIN_CTRL_GAIN_CAP_ENABLE_RESET                     0
#define BTCOEX_RFGAIN_CTRL_ADDRESS                                   0x0144
#define BTCOEX_RFGAIN_CTRL_HW_MASK                                   0x0007ffff
#define BTCOEX_RFGAIN_CTRL_SW_MASK                                   0x0007ffff
#define BTCOEX_RFGAIN_CTRL_HW_WRITE_MASK                             0x00000000
#define BTCOEX_RFGAIN_CTRL_SW_WRITE_MASK                             0x0007ffff
#define BTCOEX_RFGAIN_CTRL_RSTMASK                                   0xffffffff
#define BTCOEX_RFGAIN_CTRL_RESET                                     0x00000200

// 0x0148 (BTCOEX_CTRL2)
#define BTCOEX_CTRL2_RESERVED_MSB                                    31
#define BTCOEX_CTRL2_RESERVED_LSB                                    28
#define BTCOEX_CTRL2_RESERVED_MASK                                   0xf0000000
#define BTCOEX_CTRL2_RESERVED_GET(x)                                 (((x) & BTCOEX_CTRL2_RESERVED_MASK) >> BTCOEX_CTRL2_RESERVED_LSB)
#define BTCOEX_CTRL2_RESERVED_SET(x)                                 (((0 | (x)) << BTCOEX_CTRL2_RESERVED_LSB) & BTCOEX_CTRL2_RESERVED_MASK)
#define BTCOEX_CTRL2_RESERVED_RESET                                  0
#define BTCOEX_CTRL2_BT_RX_ALLOW_WL_UNSHARED_CHAIN_TX_MSB            27
#define BTCOEX_CTRL2_BT_RX_ALLOW_WL_UNSHARED_CHAIN_TX_LSB            27
#define BTCOEX_CTRL2_BT_RX_ALLOW_WL_UNSHARED_CHAIN_TX_MASK           0x08000000
#define BTCOEX_CTRL2_BT_RX_ALLOW_WL_UNSHARED_CHAIN_TX_GET(x)         (((x) & BTCOEX_CTRL2_BT_RX_ALLOW_WL_UNSHARED_CHAIN_TX_MASK) >> BTCOEX_CTRL2_BT_RX_ALLOW_WL_UNSHARED_CHAIN_TX_LSB)
#define BTCOEX_CTRL2_BT_RX_ALLOW_WL_UNSHARED_CHAIN_TX_SET(x)         (((0 | (x)) << BTCOEX_CTRL2_BT_RX_ALLOW_WL_UNSHARED_CHAIN_TX_LSB) & BTCOEX_CTRL2_BT_RX_ALLOW_WL_UNSHARED_CHAIN_TX_MASK)
#define BTCOEX_CTRL2_BT_RX_ALLOW_WL_UNSHARED_CHAIN_TX_RESET          0
#define BTCOEX_CTRL2_WL_2S_RX_ALLOW_BT_TX_MSB                        26
#define BTCOEX_CTRL2_WL_2S_RX_ALLOW_BT_TX_LSB                        26
#define BTCOEX_CTRL2_WL_2S_RX_ALLOW_BT_TX_MASK                       0x04000000
#define BTCOEX_CTRL2_WL_2S_RX_ALLOW_BT_TX_GET(x)                     (((x) & BTCOEX_CTRL2_WL_2S_RX_ALLOW_BT_TX_MASK) >> BTCOEX_CTRL2_WL_2S_RX_ALLOW_BT_TX_LSB)
#define BTCOEX_CTRL2_WL_2S_RX_ALLOW_BT_TX_SET(x)                     (((0 | (x)) << BTCOEX_CTRL2_WL_2S_RX_ALLOW_BT_TX_LSB) & BTCOEX_CTRL2_WL_2S_RX_ALLOW_BT_TX_MASK)
#define BTCOEX_CTRL2_WL_2S_RX_ALLOW_BT_TX_RESET                      0
#define BTCOEX_CTRL2_WL_1S_RX_ALLOW_BT_TX_MSB                        25
#define BTCOEX_CTRL2_WL_1S_RX_ALLOW_BT_TX_LSB                        25
#define BTCOEX_CTRL2_WL_1S_RX_ALLOW_BT_TX_MASK                       0x02000000
#define BTCOEX_CTRL2_WL_1S_RX_ALLOW_BT_TX_GET(x)                     (((x) & BTCOEX_CTRL2_WL_1S_RX_ALLOW_BT_TX_MASK) >> BTCOEX_CTRL2_WL_1S_RX_ALLOW_BT_TX_LSB)
#define BTCOEX_CTRL2_WL_1S_RX_ALLOW_BT_TX_SET(x)                     (((0 | (x)) << BTCOEX_CTRL2_WL_1S_RX_ALLOW_BT_TX_LSB) & BTCOEX_CTRL2_WL_1S_RX_ALLOW_BT_TX_MASK)
#define BTCOEX_CTRL2_WL_1S_RX_ALLOW_BT_TX_RESET                      1
#define BTCOEX_CTRL2_MAC_BB_OBS_SEL_MSB                              24
#define BTCOEX_CTRL2_MAC_BB_OBS_SEL_LSB                              24
#define BTCOEX_CTRL2_MAC_BB_OBS_SEL_MASK                             0x01000000
#define BTCOEX_CTRL2_MAC_BB_OBS_SEL_GET(x)                           (((x) & BTCOEX_CTRL2_MAC_BB_OBS_SEL_MASK) >> BTCOEX_CTRL2_MAC_BB_OBS_SEL_LSB)
#define BTCOEX_CTRL2_MAC_BB_OBS_SEL_SET(x)                           (((0 | (x)) << BTCOEX_CTRL2_MAC_BB_OBS_SEL_LSB) & BTCOEX_CTRL2_MAC_BB_OBS_SEL_MASK)
#define BTCOEX_CTRL2_MAC_BB_OBS_SEL_RESET                            0
#define BTCOEX_CTRL2_GPIO_OBS_SEL_MSB                                23
#define BTCOEX_CTRL2_GPIO_OBS_SEL_LSB                                23
#define BTCOEX_CTRL2_GPIO_OBS_SEL_MASK                               0x00800000
#define BTCOEX_CTRL2_GPIO_OBS_SEL_GET(x)                             (((x) & BTCOEX_CTRL2_GPIO_OBS_SEL_MASK) >> BTCOEX_CTRL2_GPIO_OBS_SEL_LSB)
#define BTCOEX_CTRL2_GPIO_OBS_SEL_SET(x)                             (((0 | (x)) << BTCOEX_CTRL2_GPIO_OBS_SEL_LSB) & BTCOEX_CTRL2_GPIO_OBS_SEL_MASK)
#define BTCOEX_CTRL2_GPIO_OBS_SEL_RESET                              0
#define BTCOEX_CTRL2_DEWEIGHT_RX_ENABLE_MSB                          22
#define BTCOEX_CTRL2_DEWEIGHT_RX_ENABLE_LSB                          22
#define BTCOEX_CTRL2_DEWEIGHT_RX_ENABLE_MASK                         0x00400000
#define BTCOEX_CTRL2_DEWEIGHT_RX_ENABLE_GET(x)                       (((x) & BTCOEX_CTRL2_DEWEIGHT_RX_ENABLE_MASK) >> BTCOEX_CTRL2_DEWEIGHT_RX_ENABLE_LSB)
#define BTCOEX_CTRL2_DEWEIGHT_RX_ENABLE_SET(x)                       (((0 | (x)) << BTCOEX_CTRL2_DEWEIGHT_RX_ENABLE_LSB) & BTCOEX_CTRL2_DEWEIGHT_RX_ENABLE_MASK)
#define BTCOEX_CTRL2_DEWEIGHT_RX_ENABLE_RESET                        0
#define BTCOEX_CTRL2_TX_SHARED_CHAIN_MASK_MSB                        21
#define BTCOEX_CTRL2_TX_SHARED_CHAIN_MASK_LSB                        19
#define BTCOEX_CTRL2_TX_SHARED_CHAIN_MASK_MASK                       0x00380000
#define BTCOEX_CTRL2_TX_SHARED_CHAIN_MASK_GET(x)                     (((x) & BTCOEX_CTRL2_TX_SHARED_CHAIN_MASK_MASK) >> BTCOEX_CTRL2_TX_SHARED_CHAIN_MASK_LSB)
#define BTCOEX_CTRL2_TX_SHARED_CHAIN_MASK_SET(x)                     (((0 | (x)) << BTCOEX_CTRL2_TX_SHARED_CHAIN_MASK_LSB) & BTCOEX_CTRL2_TX_SHARED_CHAIN_MASK_MASK)
#define BTCOEX_CTRL2_TX_SHARED_CHAIN_MASK_RESET                      1
#define BTCOEX_CTRL2_TXPWR_THRESH_MSB                                18
#define BTCOEX_CTRL2_TXPWR_THRESH_LSB                                11
#define BTCOEX_CTRL2_TXPWR_THRESH_MASK                               0x0007f800
#define BTCOEX_CTRL2_TXPWR_THRESH_GET(x)                             (((x) & BTCOEX_CTRL2_TXPWR_THRESH_MASK) >> BTCOEX_CTRL2_TXPWR_THRESH_LSB)
#define BTCOEX_CTRL2_TXPWR_THRESH_SET(x)                             (((0 | (x)) << BTCOEX_CTRL2_TXPWR_THRESH_LSB) & BTCOEX_CTRL2_TXPWR_THRESH_MASK)
#define BTCOEX_CTRL2_TXPWR_THRESH_RESET                              0
#define BTCOEX_CTRL2_OBS_SEL_MSB                                     10
#define BTCOEX_CTRL2_OBS_SEL_LSB                                     8
#define BTCOEX_CTRL2_OBS_SEL_MASK                                    0x00000700
#define BTCOEX_CTRL2_OBS_SEL_GET(x)                                  (((x) & BTCOEX_CTRL2_OBS_SEL_MASK) >> BTCOEX_CTRL2_OBS_SEL_LSB)
#define BTCOEX_CTRL2_OBS_SEL_SET(x)                                  (((0 | (x)) << BTCOEX_CTRL2_OBS_SEL_LSB) & BTCOEX_CTRL2_OBS_SEL_MASK)
#define BTCOEX_CTRL2_OBS_SEL_RESET                                   0
#define BTCOEX_CTRL2_TXTX_RANGE_ENABLE_MSB                           7
#define BTCOEX_CTRL2_TXTX_RANGE_ENABLE_LSB                           7
#define BTCOEX_CTRL2_TXTX_RANGE_ENABLE_MASK                          0x00000080
#define BTCOEX_CTRL2_TXTX_RANGE_ENABLE_GET(x)                        (((x) & BTCOEX_CTRL2_TXTX_RANGE_ENABLE_MASK) >> BTCOEX_CTRL2_TXTX_RANGE_ENABLE_LSB)
#define BTCOEX_CTRL2_TXTX_RANGE_ENABLE_SET(x)                        (((0 | (x)) << BTCOEX_CTRL2_TXTX_RANGE_ENABLE_LSB) & BTCOEX_CTRL2_TXTX_RANGE_ENABLE_MASK)
#define BTCOEX_CTRL2_TXTX_RANGE_ENABLE_RESET                         0
#define BTCOEX_CTRL2_TXRX_RANGE_ENABLE_MSB                           6
#define BTCOEX_CTRL2_TXRX_RANGE_ENABLE_LSB                           6
#define BTCOEX_CTRL2_TXRX_RANGE_ENABLE_MASK                          0x00000040
#define BTCOEX_CTRL2_TXRX_RANGE_ENABLE_GET(x)                        (((x) & BTCOEX_CTRL2_TXRX_RANGE_ENABLE_MASK) >> BTCOEX_CTRL2_TXRX_RANGE_ENABLE_LSB)
#define BTCOEX_CTRL2_TXRX_RANGE_ENABLE_SET(x)                        (((0 | (x)) << BTCOEX_CTRL2_TXRX_RANGE_ENABLE_LSB) & BTCOEX_CTRL2_TXRX_RANGE_ENABLE_MASK)
#define BTCOEX_CTRL2_TXRX_RANGE_ENABLE_RESET                         0
#define BTCOEX_CTRL2_RXTX_RANGE_ENABLE_MSB                           5
#define BTCOEX_CTRL2_RXTX_RANGE_ENABLE_LSB                           5
#define BTCOEX_CTRL2_RXTX_RANGE_ENABLE_MASK                          0x00000020
#define BTCOEX_CTRL2_RXTX_RANGE_ENABLE_GET(x)                        (((x) & BTCOEX_CTRL2_RXTX_RANGE_ENABLE_MASK) >> BTCOEX_CTRL2_RXTX_RANGE_ENABLE_LSB)
#define BTCOEX_CTRL2_RXTX_RANGE_ENABLE_SET(x)                        (((0 | (x)) << BTCOEX_CTRL2_RXTX_RANGE_ENABLE_LSB) & BTCOEX_CTRL2_RXTX_RANGE_ENABLE_MASK)
#define BTCOEX_CTRL2_RXTX_RANGE_ENABLE_RESET                         0
#define BTCOEX_CTRL2_RXRX_RANGE_ENABLE_MSB                           4
#define BTCOEX_CTRL2_RXRX_RANGE_ENABLE_LSB                           4
#define BTCOEX_CTRL2_RXRX_RANGE_ENABLE_MASK                          0x00000010
#define BTCOEX_CTRL2_RXRX_RANGE_ENABLE_GET(x)                        (((x) & BTCOEX_CTRL2_RXRX_RANGE_ENABLE_MASK) >> BTCOEX_CTRL2_RXRX_RANGE_ENABLE_LSB)
#define BTCOEX_CTRL2_RXRX_RANGE_ENABLE_SET(x)                        (((0 | (x)) << BTCOEX_CTRL2_RXRX_RANGE_ENABLE_LSB) & BTCOEX_CTRL2_RXRX_RANGE_ENABLE_MASK)
#define BTCOEX_CTRL2_RXRX_RANGE_ENABLE_RESET                         0
#define BTCOEX_CTRL2_RESERVED2_MSB                                   3
#define BTCOEX_CTRL2_RESERVED2_LSB                                   2
#define BTCOEX_CTRL2_RESERVED2_MASK                                  0x0000000c
#define BTCOEX_CTRL2_RESERVED2_GET(x)                                (((x) & BTCOEX_CTRL2_RESERVED2_MASK) >> BTCOEX_CTRL2_RESERVED2_LSB)
#define BTCOEX_CTRL2_RESERVED2_SET(x)                                (((0 | (x)) << BTCOEX_CTRL2_RESERVED2_LSB) & BTCOEX_CTRL2_RESERVED2_MASK)
#define BTCOEX_CTRL2_RESERVED2_RESET                                 0
#define BTCOEX_CTRL2_IGNORE_RX_FOR_BA_MSB                            1
#define BTCOEX_CTRL2_IGNORE_RX_FOR_BA_LSB                            1
#define BTCOEX_CTRL2_IGNORE_RX_FOR_BA_MASK                           0x00000002
#define BTCOEX_CTRL2_IGNORE_RX_FOR_BA_GET(x)                         (((x) & BTCOEX_CTRL2_IGNORE_RX_FOR_BA_MASK) >> BTCOEX_CTRL2_IGNORE_RX_FOR_BA_LSB)
#define BTCOEX_CTRL2_IGNORE_RX_FOR_BA_SET(x)                         (((0 | (x)) << BTCOEX_CTRL2_IGNORE_RX_FOR_BA_LSB) & BTCOEX_CTRL2_IGNORE_RX_FOR_BA_MASK)
#define BTCOEX_CTRL2_IGNORE_RX_FOR_BA_RESET                          0
#define BTCOEX_CTRL2_FORCE_WAIT_BA_ENABLE_MSB                        0
#define BTCOEX_CTRL2_FORCE_WAIT_BA_ENABLE_LSB                        0
#define BTCOEX_CTRL2_FORCE_WAIT_BA_ENABLE_MASK                       0x00000001
#define BTCOEX_CTRL2_FORCE_WAIT_BA_ENABLE_GET(x)                     (((x) & BTCOEX_CTRL2_FORCE_WAIT_BA_ENABLE_MASK) >> BTCOEX_CTRL2_FORCE_WAIT_BA_ENABLE_LSB)
#define BTCOEX_CTRL2_FORCE_WAIT_BA_ENABLE_SET(x)                     (((0 | (x)) << BTCOEX_CTRL2_FORCE_WAIT_BA_ENABLE_LSB) & BTCOEX_CTRL2_FORCE_WAIT_BA_ENABLE_MASK)
#define BTCOEX_CTRL2_FORCE_WAIT_BA_ENABLE_RESET                      0
#define BTCOEX_CTRL2_ADDRESS                                         0x0148
#define BTCOEX_CTRL2_HW_MASK                                         0xffffffff
#define BTCOEX_CTRL2_SW_MASK                                         0xffffffff
#define BTCOEX_CTRL2_HW_WRITE_MASK                                   0x00000000
#define BTCOEX_CTRL2_SW_WRITE_MASK                                   0xffffffff
#define BTCOEX_CTRL2_RSTMASK                                         0xffffffff
#define BTCOEX_CTRL2_RESET                                           0x02080000

// 0x014c (BTCOEX_RC)
#define BTCOEX_RC_WARM_RST_MSB                                       0
#define BTCOEX_RC_WARM_RST_LSB                                       0
#define BTCOEX_RC_WARM_RST_MASK                                      0x00000001
#define BTCOEX_RC_WARM_RST_GET(x)                                    (((x) & BTCOEX_RC_WARM_RST_MASK) >> BTCOEX_RC_WARM_RST_LSB)
#define BTCOEX_RC_WARM_RST_SET(x)                                    (((0 | (x)) << BTCOEX_RC_WARM_RST_LSB) & BTCOEX_RC_WARM_RST_MASK)
#define BTCOEX_RC_WARM_RST_RESET                                     0
#define BTCOEX_RC_ADDRESS                                            0x014c
#define BTCOEX_RC_HW_MASK                                            0x00000001
#define BTCOEX_RC_SW_MASK                                            0x00000001
#define BTCOEX_RC_HW_WRITE_MASK                                      0x00000000
#define BTCOEX_RC_SW_WRITE_MASK                                      0x00000001
#define BTCOEX_RC_RSTMASK                                            0xffffffff
#define BTCOEX_RC_RESET                                              0x00000000

// 0x0150 (BTCOEX_MAX_RFGAIN_0)
#define BTCOEX_MAX_RFGAIN_0_DATA_MSB                                 31
#define BTCOEX_MAX_RFGAIN_0_DATA_LSB                                 0
#define BTCOEX_MAX_RFGAIN_0_DATA_MASK                                0xffffffff
#define BTCOEX_MAX_RFGAIN_0_DATA_GET(x)                              (((x) & BTCOEX_MAX_RFGAIN_0_DATA_MASK) >> BTCOEX_MAX_RFGAIN_0_DATA_LSB)
#define BTCOEX_MAX_RFGAIN_0_DATA_SET(x)                              (((0 | (x)) << BTCOEX_MAX_RFGAIN_0_DATA_LSB) & BTCOEX_MAX_RFGAIN_0_DATA_MASK)
#define BTCOEX_MAX_RFGAIN_0_DATA_RESET                               0
#define BTCOEX_MAX_RFGAIN_0_ADDRESS                                  0x0150
#define BTCOEX_MAX_RFGAIN_ADDRESS                                    BTCOEX_MAX_RFGAIN_0_ADDRESS
#define BTCOEX_MAX_RFGAIN_0_HW_MASK                                  0xffffffff
#define BTCOEX_MAX_RFGAIN_0_SW_MASK                                  0xffffffff
#define BTCOEX_MAX_RFGAIN_0_HW_WRITE_MASK                            0x00000000
#define BTCOEX_MAX_RFGAIN_0_SW_WRITE_MASK                            0xffffffff
#define BTCOEX_MAX_RFGAIN_0_RSTMASK                                  0x00000000
#define BTCOEX_MAX_RFGAIN_0_RESET                                    0x00000000

// Skip 154 (BTCOEX_MAX_RFGAIN_1) - 18c (BTCOEX_MAX_RFGAIN_15) for brevity
// 0x0250 (BTCOEX_DBG)
#define BTCOEX_DBG_OBS_MSB                                           31
#define BTCOEX_DBG_OBS_LSB                                           0
#define BTCOEX_DBG_OBS_MASK                                          0xffffffff
#define BTCOEX_DBG_OBS_GET(x)                                        (((x) & BTCOEX_DBG_OBS_MASK) >> BTCOEX_DBG_OBS_LSB)
#define BTCOEX_DBG_OBS_SET(x)                                        (((0 | (x)) << BTCOEX_DBG_OBS_LSB) & BTCOEX_DBG_OBS_MASK)
#define BTCOEX_DBG_OBS_RESET                                         0
#define BTCOEX_DBG_ADDRESS                                           0x0250
#define BTCOEX_DBG_HW_MASK                                           0xffffffff
#define BTCOEX_DBG_SW_MASK                                           0xffffffff
#define BTCOEX_DBG_HW_WRITE_MASK                                     0xffffffff
#define BTCOEX_DBG_SW_WRITE_MASK                                     0x00000000
#define BTCOEX_DBG_RSTMASK                                           0xffffffff
#define BTCOEX_DBG_RESET                                             0x00000000

// 0x0254 (MCI_LAST_HW_MSG_HDR)
#define MCI_LAST_HW_MSG_HDR_LEN_MSB                                  10
#define MCI_LAST_HW_MSG_HDR_LEN_LSB                                  8
#define MCI_LAST_HW_MSG_HDR_LEN_MASK                                 0x00000700
#define MCI_LAST_HW_MSG_HDR_LEN_GET(x)                               (((x) & MCI_LAST_HW_MSG_HDR_LEN_MASK) >> MCI_LAST_HW_MSG_HDR_LEN_LSB)
#define MCI_LAST_HW_MSG_HDR_LEN_SET(x)                               (((0 | (x)) << MCI_LAST_HW_MSG_HDR_LEN_LSB) & MCI_LAST_HW_MSG_HDR_LEN_MASK)
#define MCI_LAST_HW_MSG_HDR_LEN_RESET                                0
#define MCI_LAST_HW_MSG_HDR_HDR_MSB                                  7
#define MCI_LAST_HW_MSG_HDR_HDR_LSB                                  0
#define MCI_LAST_HW_MSG_HDR_HDR_MASK                                 0x000000ff
#define MCI_LAST_HW_MSG_HDR_HDR_GET(x)                               (((x) & MCI_LAST_HW_MSG_HDR_HDR_MASK) >> MCI_LAST_HW_MSG_HDR_HDR_LSB)
#define MCI_LAST_HW_MSG_HDR_HDR_SET(x)                               (((0 | (x)) << MCI_LAST_HW_MSG_HDR_HDR_LSB) & MCI_LAST_HW_MSG_HDR_HDR_MASK)
#define MCI_LAST_HW_MSG_HDR_HDR_RESET                                0
#define MCI_LAST_HW_MSG_HDR_ADDRESS                                  0x0254
#define MCI_LAST_HW_MSG_HDR_HW_MASK                                  0x000007ff
#define MCI_LAST_HW_MSG_HDR_SW_MASK                                  0x000007ff
#define MCI_LAST_HW_MSG_HDR_HW_WRITE_MASK                            0x000007ff
#define MCI_LAST_HW_MSG_HDR_SW_WRITE_MASK                            0x00000000
#define MCI_LAST_HW_MSG_HDR_RSTMASK                                  0xffffffff
#define MCI_LAST_HW_MSG_HDR_RESET                                    0x00000000

// 0x0258 (MCI_LAST_HW_MSG_BDY)
#define MCI_LAST_HW_MSG_BDY_BDY_MSB                                  31
#define MCI_LAST_HW_MSG_BDY_BDY_LSB                                  0
#define MCI_LAST_HW_MSG_BDY_BDY_MASK                                 0xffffffff
#define MCI_LAST_HW_MSG_BDY_BDY_GET(x)                               (((x) & MCI_LAST_HW_MSG_BDY_BDY_MASK) >> MCI_LAST_HW_MSG_BDY_BDY_LSB)
#define MCI_LAST_HW_MSG_BDY_BDY_SET(x)                               (((0 | (x)) << MCI_LAST_HW_MSG_BDY_BDY_LSB) & MCI_LAST_HW_MSG_BDY_BDY_MASK)
#define MCI_LAST_HW_MSG_BDY_BDY_RESET                                0
#define MCI_LAST_HW_MSG_BDY_ADDRESS                                  0x0258
#define MCI_LAST_HW_MSG_BDY_HW_MASK                                  0xffffffff
#define MCI_LAST_HW_MSG_BDY_SW_MASK                                  0xffffffff
#define MCI_LAST_HW_MSG_BDY_HW_WRITE_MASK                            0xffffffff
#define MCI_LAST_HW_MSG_BDY_SW_WRITE_MASK                            0x00000000
#define MCI_LAST_HW_MSG_BDY_RSTMASK                                  0xffffffff
#define MCI_LAST_HW_MSG_BDY_RESET                                    0x00000000

// 0x0260 (MCI_SCHD_TABLE_2)
#define MCI_SCHD_TABLE_2_HW_BASED_MSB                                1
#define MCI_SCHD_TABLE_2_HW_BASED_LSB                                1
#define MCI_SCHD_TABLE_2_HW_BASED_MASK                               0x00000002
#define MCI_SCHD_TABLE_2_HW_BASED_GET(x)                             (((x) & MCI_SCHD_TABLE_2_HW_BASED_MASK) >> MCI_SCHD_TABLE_2_HW_BASED_LSB)
#define MCI_SCHD_TABLE_2_HW_BASED_SET(x)                             (((0 | (x)) << MCI_SCHD_TABLE_2_HW_BASED_LSB) & MCI_SCHD_TABLE_2_HW_BASED_MASK)
#define MCI_SCHD_TABLE_2_HW_BASED_RESET                              0
#define MCI_SCHD_TABLE_2_MEM_BASED_MSB                               0
#define MCI_SCHD_TABLE_2_MEM_BASED_LSB                               0
#define MCI_SCHD_TABLE_2_MEM_BASED_MASK                              0x00000001
#define MCI_SCHD_TABLE_2_MEM_BASED_GET(x)                            (((x) & MCI_SCHD_TABLE_2_MEM_BASED_MASK) >> MCI_SCHD_TABLE_2_MEM_BASED_LSB)
#define MCI_SCHD_TABLE_2_MEM_BASED_SET(x)                            (((0 | (x)) << MCI_SCHD_TABLE_2_MEM_BASED_LSB) & MCI_SCHD_TABLE_2_MEM_BASED_MASK)
#define MCI_SCHD_TABLE_2_MEM_BASED_RESET                             1
#define MCI_SCHD_TABLE_2_ADDRESS                                     0x0260
#define MCI_SCHD_TABLE_2_HW_MASK                                     0x00000003
#define MCI_SCHD_TABLE_2_SW_MASK                                     0x00000003
#define MCI_SCHD_TABLE_2_HW_WRITE_MASK                               0x00000000
#define MCI_SCHD_TABLE_2_SW_WRITE_MASK                               0x00000003
#define MCI_SCHD_TABLE_2_RSTMASK                                     0xffffffff
#define MCI_SCHD_TABLE_2_RESET                                       0x00000001

// 0x0264 (BTCOEX_CTRL3)
#define BTCOEX_CTRL3_CONT_INFO_TIMEOUT_MSB                           11
#define BTCOEX_CTRL3_CONT_INFO_TIMEOUT_LSB                           0
#define BTCOEX_CTRL3_CONT_INFO_TIMEOUT_MASK                          0x00000fff
#define BTCOEX_CTRL3_CONT_INFO_TIMEOUT_GET(x)                        (((x) & BTCOEX_CTRL3_CONT_INFO_TIMEOUT_MASK) >> BTCOEX_CTRL3_CONT_INFO_TIMEOUT_LSB)
#define BTCOEX_CTRL3_CONT_INFO_TIMEOUT_SET(x)                        (((0 | (x)) << BTCOEX_CTRL3_CONT_INFO_TIMEOUT_LSB) & BTCOEX_CTRL3_CONT_INFO_TIMEOUT_MASK)
#define BTCOEX_CTRL3_CONT_INFO_TIMEOUT_RESET                         4095
#define BTCOEX_CTRL3_ADDRESS                                         0x0264
#define BTCOEX_CTRL3_HW_MASK                                         0x00000fff
#define BTCOEX_CTRL3_SW_MASK                                         0x00000fff
#define BTCOEX_CTRL3_HW_WRITE_MASK                                   0x00000000
#define BTCOEX_CTRL3_SW_WRITE_MASK                                   0x00000fff
#define BTCOEX_CTRL3_RSTMASK                                         0xffffffff
#define BTCOEX_CTRL3_RESET                                           0x00000fff

// 0x026c (MCI_INTERRUPT_1_RAW)
#define MCI_INTERRUPT_1_RAW_BT_TXRX_CNT_LIMIT_MSB                    1
#define MCI_INTERRUPT_1_RAW_BT_TXRX_CNT_LIMIT_LSB                    1
#define MCI_INTERRUPT_1_RAW_BT_TXRX_CNT_LIMIT_MASK                   0x00000002
#define MCI_INTERRUPT_1_RAW_BT_TXRX_CNT_LIMIT_GET(x)                 (((x) & MCI_INTERRUPT_1_RAW_BT_TXRX_CNT_LIMIT_MASK) >> MCI_INTERRUPT_1_RAW_BT_TXRX_CNT_LIMIT_LSB)
#define MCI_INTERRUPT_1_RAW_BT_TXRX_CNT_LIMIT_SET(x)                 (((0 | (x)) << MCI_INTERRUPT_1_RAW_BT_TXRX_CNT_LIMIT_LSB) & MCI_INTERRUPT_1_RAW_BT_TXRX_CNT_LIMIT_MASK)
#define MCI_INTERRUPT_1_RAW_BT_TXRX_CNT_LIMIT_RESET                  0
#define MCI_INTERRUPT_1_RAW_RX_TIMEOUT_RST_MSB                       0
#define MCI_INTERRUPT_1_RAW_RX_TIMEOUT_RST_LSB                       0
#define MCI_INTERRUPT_1_RAW_RX_TIMEOUT_RST_MASK                      0x00000001
#define MCI_INTERRUPT_1_RAW_RX_TIMEOUT_RST_GET(x)                    (((x) & MCI_INTERRUPT_1_RAW_RX_TIMEOUT_RST_MASK) >> MCI_INTERRUPT_1_RAW_RX_TIMEOUT_RST_LSB)
#define MCI_INTERRUPT_1_RAW_RX_TIMEOUT_RST_SET(x)                    (((0 | (x)) << MCI_INTERRUPT_1_RAW_RX_TIMEOUT_RST_LSB) & MCI_INTERRUPT_1_RAW_RX_TIMEOUT_RST_MASK)
#define MCI_INTERRUPT_1_RAW_RX_TIMEOUT_RST_RESET                     0
#define MCI_INTERRUPT_1_RAW_ADDRESS                                  0x026c
#define MCI_INTERRUPT_1_RAW_HW_MASK                                  0x00000003
#define MCI_INTERRUPT_1_RAW_SW_MASK                                  0x00000003
#define MCI_INTERRUPT_1_RAW_HW_WRITE_MASK                            0x00000003
#define MCI_INTERRUPT_1_RAW_SW_WRITE_MASK                            0x00000003
#define MCI_INTERRUPT_1_RAW_RSTMASK                                  0xffffffff
#define MCI_INTERRUPT_1_RAW_RESET                                    0x00000000

// 0x0270 (MCI_INTERRUPT_1_EN)
#define MCI_INTERRUPT_1_EN_BT_TXRX_CNT_LIMIT_MSB                     1
#define MCI_INTERRUPT_1_EN_BT_TXRX_CNT_LIMIT_LSB                     1
#define MCI_INTERRUPT_1_EN_BT_TXRX_CNT_LIMIT_MASK                    0x00000002
#define MCI_INTERRUPT_1_EN_BT_TXRX_CNT_LIMIT_GET(x)                  (((x) & MCI_INTERRUPT_1_EN_BT_TXRX_CNT_LIMIT_MASK) >> MCI_INTERRUPT_1_EN_BT_TXRX_CNT_LIMIT_LSB)
#define MCI_INTERRUPT_1_EN_BT_TXRX_CNT_LIMIT_SET(x)                  (((0 | (x)) << MCI_INTERRUPT_1_EN_BT_TXRX_CNT_LIMIT_LSB) & MCI_INTERRUPT_1_EN_BT_TXRX_CNT_LIMIT_MASK)
#define MCI_INTERRUPT_1_EN_BT_TXRX_CNT_LIMIT_RESET                   0
#define MCI_INTERRUPT_1_EN_RX_TIMEOUT_RST_MSB                        0
#define MCI_INTERRUPT_1_EN_RX_TIMEOUT_RST_LSB                        0
#define MCI_INTERRUPT_1_EN_RX_TIMEOUT_RST_MASK                       0x00000001
#define MCI_INTERRUPT_1_EN_RX_TIMEOUT_RST_GET(x)                     (((x) & MCI_INTERRUPT_1_EN_RX_TIMEOUT_RST_MASK) >> MCI_INTERRUPT_1_EN_RX_TIMEOUT_RST_LSB)
#define MCI_INTERRUPT_1_EN_RX_TIMEOUT_RST_SET(x)                     (((0 | (x)) << MCI_INTERRUPT_1_EN_RX_TIMEOUT_RST_LSB) & MCI_INTERRUPT_1_EN_RX_TIMEOUT_RST_MASK)
#define MCI_INTERRUPT_1_EN_RX_TIMEOUT_RST_RESET                      0
#define MCI_INTERRUPT_1_EN_ADDRESS                                   0x0270
#define MCI_INTERRUPT_1_EN_HW_MASK                                   0x00000003
#define MCI_INTERRUPT_1_EN_SW_MASK                                   0x00000003
#define MCI_INTERRUPT_1_EN_HW_WRITE_MASK                             0x00000000
#define MCI_INTERRUPT_1_EN_SW_WRITE_MASK                             0x00000003
#define MCI_INTERRUPT_1_EN_RSTMASK                                   0xffffffff
#define MCI_INTERRUPT_1_EN_RESET                                     0x00000000

// 0x0274 (MCI_EV_MISC)
#define MCI_EV_MISC_RESERVED_MSB                                     15
#define MCI_EV_MISC_RESERVED_LSB                                     1
#define MCI_EV_MISC_RESERVED_MASK                                    0x0000fffe
#define MCI_EV_MISC_RESERVED_GET(x)                                  (((x) & MCI_EV_MISC_RESERVED_MASK) >> MCI_EV_MISC_RESERVED_LSB)
#define MCI_EV_MISC_RESERVED_SET(x)                                  (((0 | (x)) << MCI_EV_MISC_RESERVED_LSB) & MCI_EV_MISC_RESERVED_MASK)
#define MCI_EV_MISC_RESERVED_RESET                                   0
#define MCI_EV_MISC_EV88239_FIX_EN_MSB                               0
#define MCI_EV_MISC_EV88239_FIX_EN_LSB                               0
#define MCI_EV_MISC_EV88239_FIX_EN_MASK                              0x00000001
#define MCI_EV_MISC_EV88239_FIX_EN_GET(x)                            (((x) & MCI_EV_MISC_EV88239_FIX_EN_MASK) >> MCI_EV_MISC_EV88239_FIX_EN_LSB)
#define MCI_EV_MISC_EV88239_FIX_EN_SET(x)                            (((0 | (x)) << MCI_EV_MISC_EV88239_FIX_EN_LSB) & MCI_EV_MISC_EV88239_FIX_EN_MASK)
#define MCI_EV_MISC_EV88239_FIX_EN_RESET                             0
#define MCI_EV_MISC_ADDRESS                                          0x0274
#define MCI_EV_MISC_HW_MASK                                          0x0000ffff
#define MCI_EV_MISC_SW_MASK                                          0x0000ffff
#define MCI_EV_MISC_HW_WRITE_MASK                                    0x00000000
#define MCI_EV_MISC_SW_WRITE_MASK                                    0x0000ffff
#define MCI_EV_MISC_RSTMASK                                          0xffffffff
#define MCI_EV_MISC_RESET                                            0x00000000

// 0x0278 (BTCOEX_RX_RANGE)
#define BTCOEX_RX_RANGE_BT_MAX_MSB                                   31
#define BTCOEX_RX_RANGE_BT_MAX_LSB                                   24
#define BTCOEX_RX_RANGE_BT_MAX_MASK                                  0xff000000
#define BTCOEX_RX_RANGE_BT_MAX_GET(x)                                (((x) & BTCOEX_RX_RANGE_BT_MAX_MASK) >> BTCOEX_RX_RANGE_BT_MAX_LSB)
#define BTCOEX_RX_RANGE_BT_MAX_SET(x)                                (((0 | (x)) << BTCOEX_RX_RANGE_BT_MAX_LSB) & BTCOEX_RX_RANGE_BT_MAX_MASK)
#define BTCOEX_RX_RANGE_BT_MAX_RESET                                 0
#define BTCOEX_RX_RANGE_BT_MIN_MSB                                   23
#define BTCOEX_RX_RANGE_BT_MIN_LSB                                   16
#define BTCOEX_RX_RANGE_BT_MIN_MASK                                  0x00ff0000
#define BTCOEX_RX_RANGE_BT_MIN_GET(x)                                (((x) & BTCOEX_RX_RANGE_BT_MIN_MASK) >> BTCOEX_RX_RANGE_BT_MIN_LSB)
#define BTCOEX_RX_RANGE_BT_MIN_SET(x)                                (((0 | (x)) << BTCOEX_RX_RANGE_BT_MIN_LSB) & BTCOEX_RX_RANGE_BT_MIN_MASK)
#define BTCOEX_RX_RANGE_BT_MIN_RESET                                 0
#define BTCOEX_RX_RANGE_WL_MAX_MSB                                   15
#define BTCOEX_RX_RANGE_WL_MAX_LSB                                   8
#define BTCOEX_RX_RANGE_WL_MAX_MASK                                  0x0000ff00
#define BTCOEX_RX_RANGE_WL_MAX_GET(x)                                (((x) & BTCOEX_RX_RANGE_WL_MAX_MASK) >> BTCOEX_RX_RANGE_WL_MAX_LSB)
#define BTCOEX_RX_RANGE_WL_MAX_SET(x)                                (((0 | (x)) << BTCOEX_RX_RANGE_WL_MAX_LSB) & BTCOEX_RX_RANGE_WL_MAX_MASK)
#define BTCOEX_RX_RANGE_WL_MAX_RESET                                 0
#define BTCOEX_RX_RANGE_WL_MIN_MSB                                   7
#define BTCOEX_RX_RANGE_WL_MIN_LSB                                   0
#define BTCOEX_RX_RANGE_WL_MIN_MASK                                  0x000000ff
#define BTCOEX_RX_RANGE_WL_MIN_GET(x)                                (((x) & BTCOEX_RX_RANGE_WL_MIN_MASK) >> BTCOEX_RX_RANGE_WL_MIN_LSB)
#define BTCOEX_RX_RANGE_WL_MIN_SET(x)                                (((0 | (x)) << BTCOEX_RX_RANGE_WL_MIN_LSB) & BTCOEX_RX_RANGE_WL_MIN_MASK)
#define BTCOEX_RX_RANGE_WL_MIN_RESET                                 0
#define BTCOEX_RX_RANGE_ADDRESS                                      0x0278
#define BTCOEX_RX_RANGE_HW_MASK                                      0xffffffff
#define BTCOEX_RX_RANGE_SW_MASK                                      0xffffffff
#define BTCOEX_RX_RANGE_HW_WRITE_MASK                                0x00000000
#define BTCOEX_RX_RANGE_SW_WRITE_MASK                                0xffffffff
#define BTCOEX_RX_RANGE_RSTMASK                                      0xffffffff
#define BTCOEX_RX_RANGE_RESET                                        0x00000000

// 0x027c (BTCOEX_TX_RANGE)
#define BTCOEX_TX_RANGE_BT_MAX_MSB                                   31
#define BTCOEX_TX_RANGE_BT_MAX_LSB                                   24
#define BTCOEX_TX_RANGE_BT_MAX_MASK                                  0xff000000
#define BTCOEX_TX_RANGE_BT_MAX_GET(x)                                (((x) & BTCOEX_TX_RANGE_BT_MAX_MASK) >> BTCOEX_TX_RANGE_BT_MAX_LSB)
#define BTCOEX_TX_RANGE_BT_MAX_SET(x)                                (((0 | (x)) << BTCOEX_TX_RANGE_BT_MAX_LSB) & BTCOEX_TX_RANGE_BT_MAX_MASK)
#define BTCOEX_TX_RANGE_BT_MAX_RESET                                 0
#define BTCOEX_TX_RANGE_BT_MIN_MSB                                   23
#define BTCOEX_TX_RANGE_BT_MIN_LSB                                   16
#define BTCOEX_TX_RANGE_BT_MIN_MASK                                  0x00ff0000
#define BTCOEX_TX_RANGE_BT_MIN_GET(x)                                (((x) & BTCOEX_TX_RANGE_BT_MIN_MASK) >> BTCOEX_TX_RANGE_BT_MIN_LSB)
#define BTCOEX_TX_RANGE_BT_MIN_SET(x)                                (((0 | (x)) << BTCOEX_TX_RANGE_BT_MIN_LSB) & BTCOEX_TX_RANGE_BT_MIN_MASK)
#define BTCOEX_TX_RANGE_BT_MIN_RESET                                 0
#define BTCOEX_TX_RANGE_WL_MAX_MSB                                   15
#define BTCOEX_TX_RANGE_WL_MAX_LSB                                   8
#define BTCOEX_TX_RANGE_WL_MAX_MASK                                  0x0000ff00
#define BTCOEX_TX_RANGE_WL_MAX_GET(x)                                (((x) & BTCOEX_TX_RANGE_WL_MAX_MASK) >> BTCOEX_TX_RANGE_WL_MAX_LSB)
#define BTCOEX_TX_RANGE_WL_MAX_SET(x)                                (((0 | (x)) << BTCOEX_TX_RANGE_WL_MAX_LSB) & BTCOEX_TX_RANGE_WL_MAX_MASK)
#define BTCOEX_TX_RANGE_WL_MAX_RESET                                 0
#define BTCOEX_TX_RANGE_WL_MIN_MSB                                   7
#define BTCOEX_TX_RANGE_WL_MIN_LSB                                   0
#define BTCOEX_TX_RANGE_WL_MIN_MASK                                  0x000000ff
#define BTCOEX_TX_RANGE_WL_MIN_GET(x)                                (((x) & BTCOEX_TX_RANGE_WL_MIN_MASK) >> BTCOEX_TX_RANGE_WL_MIN_LSB)
#define BTCOEX_TX_RANGE_WL_MIN_SET(x)                                (((0 | (x)) << BTCOEX_TX_RANGE_WL_MIN_LSB) & BTCOEX_TX_RANGE_WL_MIN_MASK)
#define BTCOEX_TX_RANGE_WL_MIN_RESET                                 0
#define BTCOEX_TX_RANGE_ADDRESS                                      0x027c
#define BTCOEX_TX_RANGE_HW_MASK                                      0xffffffff
#define BTCOEX_TX_RANGE_SW_MASK                                      0xffffffff
#define BTCOEX_TX_RANGE_HW_WRITE_MASK                                0x00000000
#define BTCOEX_TX_RANGE_SW_WRITE_MASK                                0xffffffff
#define BTCOEX_TX_RANGE_RSTMASK                                      0xffffffff
#define BTCOEX_TX_RANGE_RESET                                        0x00000000

// 0x0280 (BTCOEX_CHANNEL_BUSY_CNT)
#define BTCOEX_CHANNEL_BUSY_CNT_VALUE_MSB                            31
#define BTCOEX_CHANNEL_BUSY_CNT_VALUE_LSB                            0
#define BTCOEX_CHANNEL_BUSY_CNT_VALUE_MASK                           0xffffffff
#define BTCOEX_CHANNEL_BUSY_CNT_VALUE_GET(x)                         (((x) & BTCOEX_CHANNEL_BUSY_CNT_VALUE_MASK) >> BTCOEX_CHANNEL_BUSY_CNT_VALUE_LSB)
#define BTCOEX_CHANNEL_BUSY_CNT_VALUE_SET(x)                         (((0 | (x)) << BTCOEX_CHANNEL_BUSY_CNT_VALUE_LSB) & BTCOEX_CHANNEL_BUSY_CNT_VALUE_MASK)
#define BTCOEX_CHANNEL_BUSY_CNT_VALUE_RESET                          0
#define BTCOEX_CHANNEL_BUSY_CNT_ADDRESS                              0x0280
#define BTCOEX_CHANNEL_BUSY_CNT_HW_MASK                              0xffffffff
#define BTCOEX_CHANNEL_BUSY_CNT_SW_MASK                              0xffffffff
#define BTCOEX_CHANNEL_BUSY_CNT_HW_WRITE_MASK                        0xffffffff
#define BTCOEX_CHANNEL_BUSY_CNT_SW_WRITE_MASK                        0xffffffff
#define BTCOEX_CHANNEL_BUSY_CNT_RSTMASK                              0xffffffff
#define BTCOEX_CHANNEL_BUSY_CNT_RESET                                0x00000000

// 0x0284 (BTCOEX_CHANNEL_BUSY_CNT_CTRL)
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_CLEAR_MSB                       1
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_CLEAR_LSB                       1
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_CLEAR_MASK                      0x00000002
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_CLEAR_GET(x)                    (((x) & BTCOEX_CHANNEL_BUSY_CNT_CTRL_CLEAR_MASK) >> BTCOEX_CHANNEL_BUSY_CNT_CTRL_CLEAR_LSB)
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_CLEAR_SET(x)                    (((0 | (x)) << BTCOEX_CHANNEL_BUSY_CNT_CTRL_CLEAR_LSB) & BTCOEX_CHANNEL_BUSY_CNT_CTRL_CLEAR_MASK)
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_CLEAR_RESET                     0
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_ENABLE_MSB                      0
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_ENABLE_LSB                      0
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_ENABLE_MASK                     0x00000001
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_ENABLE_GET(x)                   (((x) & BTCOEX_CHANNEL_BUSY_CNT_CTRL_ENABLE_MASK) >> BTCOEX_CHANNEL_BUSY_CNT_CTRL_ENABLE_LSB)
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_ENABLE_SET(x)                   (((0 | (x)) << BTCOEX_CHANNEL_BUSY_CNT_CTRL_ENABLE_LSB) & BTCOEX_CHANNEL_BUSY_CNT_CTRL_ENABLE_MASK)
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_ENABLE_RESET                    0
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_ADDRESS                         0x0284
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_HW_MASK                         0x00000003
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_SW_MASK                         0x00000003
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_HW_WRITE_MASK                   0x00000002
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_SW_WRITE_MASK                   0x00000003
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_RSTMASK                         0xffffffff
#define BTCOEX_CHANNEL_BUSY_CNT_CTRL_RESET                           0x00000000

// 0x0288 (BTCOEX_BT_TX_CNT)
#define BTCOEX_BT_TX_CNT_VALUE_MSB                                   31
#define BTCOEX_BT_TX_CNT_VALUE_LSB                                   0
#define BTCOEX_BT_TX_CNT_VALUE_MASK                                  0xffffffff
#define BTCOEX_BT_TX_CNT_VALUE_GET(x)                                (((x) & BTCOEX_BT_TX_CNT_VALUE_MASK) >> BTCOEX_BT_TX_CNT_VALUE_LSB)
#define BTCOEX_BT_TX_CNT_VALUE_SET(x)                                (((0 | (x)) << BTCOEX_BT_TX_CNT_VALUE_LSB) & BTCOEX_BT_TX_CNT_VALUE_MASK)
#define BTCOEX_BT_TX_CNT_VALUE_RESET                                 0
#define BTCOEX_BT_TX_CNT_ADDRESS                                     0x0288
#define BTCOEX_BT_TX_CNT_HW_MASK                                     0xffffffff
#define BTCOEX_BT_TX_CNT_SW_MASK                                     0xffffffff
#define BTCOEX_BT_TX_CNT_HW_WRITE_MASK                               0xffffffff
#define BTCOEX_BT_TX_CNT_SW_WRITE_MASK                               0xffffffff
#define BTCOEX_BT_TX_CNT_RSTMASK                                     0xffffffff
#define BTCOEX_BT_TX_CNT_RESET                                       0x00000000

// 0x028c (BTCOEX_BT_RX_CNT)
#define BTCOEX_BT_RX_CNT_VALUE_MSB                                   31
#define BTCOEX_BT_RX_CNT_VALUE_LSB                                   0
#define BTCOEX_BT_RX_CNT_VALUE_MASK                                  0xffffffff
#define BTCOEX_BT_RX_CNT_VALUE_GET(x)                                (((x) & BTCOEX_BT_RX_CNT_VALUE_MASK) >> BTCOEX_BT_RX_CNT_VALUE_LSB)
#define BTCOEX_BT_RX_CNT_VALUE_SET(x)                                (((0 | (x)) << BTCOEX_BT_RX_CNT_VALUE_LSB) & BTCOEX_BT_RX_CNT_VALUE_MASK)
#define BTCOEX_BT_RX_CNT_VALUE_RESET                                 0
#define BTCOEX_BT_RX_CNT_ADDRESS                                     0x028c
#define BTCOEX_BT_RX_CNT_HW_MASK                                     0xffffffff
#define BTCOEX_BT_RX_CNT_SW_MASK                                     0xffffffff
#define BTCOEX_BT_RX_CNT_HW_WRITE_MASK                               0xffffffff
#define BTCOEX_BT_RX_CNT_SW_WRITE_MASK                               0xffffffff
#define BTCOEX_BT_RX_CNT_RSTMASK                                     0xffffffff
#define BTCOEX_BT_RX_CNT_RESET                                       0x00000000

// 0x0290 (BTCOEX_BT_TXRX_CNT_LIMIT)
#define BTCOEX_BT_TXRX_CNT_LIMIT_VALUE_MSB                           31
#define BTCOEX_BT_TXRX_CNT_LIMIT_VALUE_LSB                           0
#define BTCOEX_BT_TXRX_CNT_LIMIT_VALUE_MASK                          0xffffffff
#define BTCOEX_BT_TXRX_CNT_LIMIT_VALUE_GET(x)                        (((x) & BTCOEX_BT_TXRX_CNT_LIMIT_VALUE_MASK) >> BTCOEX_BT_TXRX_CNT_LIMIT_VALUE_LSB)
#define BTCOEX_BT_TXRX_CNT_LIMIT_VALUE_SET(x)                        (((0 | (x)) << BTCOEX_BT_TXRX_CNT_LIMIT_VALUE_LSB) & BTCOEX_BT_TXRX_CNT_LIMIT_VALUE_MASK)
#define BTCOEX_BT_TXRX_CNT_LIMIT_VALUE_RESET                         0
#define BTCOEX_BT_TXRX_CNT_LIMIT_ADDRESS                             0x0290
#define BTCOEX_BT_TXRX_CNT_LIMIT_HW_MASK                             0xffffffff
#define BTCOEX_BT_TXRX_CNT_LIMIT_SW_MASK                             0xffffffff
#define BTCOEX_BT_TXRX_CNT_LIMIT_HW_WRITE_MASK                       0x00000000
#define BTCOEX_BT_TXRX_CNT_LIMIT_SW_WRITE_MASK                       0xffffffff
#define BTCOEX_BT_TXRX_CNT_LIMIT_RSTMASK                             0xffffffff
#define BTCOEX_BT_TXRX_CNT_LIMIT_RESET                               0x00000000

// 0x0294 (BTCOEX_BT_TXRX_CNT_CTRL)
#define BTCOEX_BT_TXRX_CNT_CTRL_LOW_PRI_LIMIT_MSB                    23
#define BTCOEX_BT_TXRX_CNT_CTRL_LOW_PRI_LIMIT_LSB                    16
#define BTCOEX_BT_TXRX_CNT_CTRL_LOW_PRI_LIMIT_MASK                   0x00ff0000
#define BTCOEX_BT_TXRX_CNT_CTRL_LOW_PRI_LIMIT_GET(x)                 (((x) & BTCOEX_BT_TXRX_CNT_CTRL_LOW_PRI_LIMIT_MASK) >> BTCOEX_BT_TXRX_CNT_CTRL_LOW_PRI_LIMIT_LSB)
#define BTCOEX_BT_TXRX_CNT_CTRL_LOW_PRI_LIMIT_SET(x)                 (((0 | (x)) << BTCOEX_BT_TXRX_CNT_CTRL_LOW_PRI_LIMIT_LSB) & BTCOEX_BT_TXRX_CNT_CTRL_LOW_PRI_LIMIT_MASK)
#define BTCOEX_BT_TXRX_CNT_CTRL_LOW_PRI_LIMIT_RESET                  0
#define BTCOEX_BT_TXRX_CNT_CTRL_HIGH_PRI_LIMIT_MSB                   15
#define BTCOEX_BT_TXRX_CNT_CTRL_HIGH_PRI_LIMIT_LSB                   8
#define BTCOEX_BT_TXRX_CNT_CTRL_HIGH_PRI_LIMIT_MASK                  0x0000ff00
#define BTCOEX_BT_TXRX_CNT_CTRL_HIGH_PRI_LIMIT_GET(x)                (((x) & BTCOEX_BT_TXRX_CNT_CTRL_HIGH_PRI_LIMIT_MASK) >> BTCOEX_BT_TXRX_CNT_CTRL_HIGH_PRI_LIMIT_LSB)
#define BTCOEX_BT_TXRX_CNT_CTRL_HIGH_PRI_LIMIT_SET(x)                (((0 | (x)) << BTCOEX_BT_TXRX_CNT_CTRL_HIGH_PRI_LIMIT_LSB) & BTCOEX_BT_TXRX_CNT_CTRL_HIGH_PRI_LIMIT_MASK)
#define BTCOEX_BT_TXRX_CNT_CTRL_HIGH_PRI_LIMIT_RESET                 0
#define BTCOEX_BT_TXRX_CNT_CTRL_RESERVED_MSB                         7
#define BTCOEX_BT_TXRX_CNT_CTRL_RESERVED_LSB                         2
#define BTCOEX_BT_TXRX_CNT_CTRL_RESERVED_MASK                        0x000000fc
#define BTCOEX_BT_TXRX_CNT_CTRL_RESERVED_GET(x)                      (((x) & BTCOEX_BT_TXRX_CNT_CTRL_RESERVED_MASK) >> BTCOEX_BT_TXRX_CNT_CTRL_RESERVED_LSB)
#define BTCOEX_BT_TXRX_CNT_CTRL_RESERVED_SET(x)                      (((0 | (x)) << BTCOEX_BT_TXRX_CNT_CTRL_RESERVED_LSB) & BTCOEX_BT_TXRX_CNT_CTRL_RESERVED_MASK)
#define BTCOEX_BT_TXRX_CNT_CTRL_RESERVED_RESET                       0
#define BTCOEX_BT_TXRX_CNT_CTRL_CLEAR_MSB                            1
#define BTCOEX_BT_TXRX_CNT_CTRL_CLEAR_LSB                            1
#define BTCOEX_BT_TXRX_CNT_CTRL_CLEAR_MASK                           0x00000002
#define BTCOEX_BT_TXRX_CNT_CTRL_CLEAR_GET(x)                         (((x) & BTCOEX_BT_TXRX_CNT_CTRL_CLEAR_MASK) >> BTCOEX_BT_TXRX_CNT_CTRL_CLEAR_LSB)
#define BTCOEX_BT_TXRX_CNT_CTRL_CLEAR_SET(x)                         (((0 | (x)) << BTCOEX_BT_TXRX_CNT_CTRL_CLEAR_LSB) & BTCOEX_BT_TXRX_CNT_CTRL_CLEAR_MASK)
#define BTCOEX_BT_TXRX_CNT_CTRL_CLEAR_RESET                          0
#define BTCOEX_BT_TXRX_CNT_CTRL_ENABLE_MSB                           0
#define BTCOEX_BT_TXRX_CNT_CTRL_ENABLE_LSB                           0
#define BTCOEX_BT_TXRX_CNT_CTRL_ENABLE_MASK                          0x00000001
#define BTCOEX_BT_TXRX_CNT_CTRL_ENABLE_GET(x)                        (((x) & BTCOEX_BT_TXRX_CNT_CTRL_ENABLE_MASK) >> BTCOEX_BT_TXRX_CNT_CTRL_ENABLE_LSB)
#define BTCOEX_BT_TXRX_CNT_CTRL_ENABLE_SET(x)                        (((0 | (x)) << BTCOEX_BT_TXRX_CNT_CTRL_ENABLE_LSB) & BTCOEX_BT_TXRX_CNT_CTRL_ENABLE_MASK)
#define BTCOEX_BT_TXRX_CNT_CTRL_ENABLE_RESET                         0
#define BTCOEX_BT_TXRX_CNT_CTRL_ADDRESS                              0x0294
#define BTCOEX_BT_TXRX_CNT_CTRL_HW_MASK                              0x00ffffff
#define BTCOEX_BT_TXRX_CNT_CTRL_SW_MASK                              0x00ffffff
#define BTCOEX_BT_TXRX_CNT_CTRL_HW_WRITE_MASK                        0x00000002
#define BTCOEX_BT_TXRX_CNT_CTRL_SW_WRITE_MASK                        0x00ffffff
#define BTCOEX_BT_TXRX_CNT_CTRL_RSTMASK                              0xffffffff
#define BTCOEX_BT_TXRX_CNT_CTRL_RESET                                0x00000000


#endif /* _WLAN_COEX_REG_H_ */
