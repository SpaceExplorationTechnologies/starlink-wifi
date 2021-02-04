//                                                                             
// File:       ./mac_qcu_reg.vrh                                               
// Creator:    shung                                                           
// Time:       Monday Apr 23, 2012 [6:26:02 pm]                                
//                                                                             
// Path:       /trees/shung/shung-dev/chips/peregrine/1.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux/blueprint -odir . -codegen   
//             ath_vrh.codegen -ath_vrh -Wdesc -I                              
//             /trees/shung/shung-dev/chips/peregrine/1.0/blueprint/sysconfig  
//             mac_qcu_reg.rdl                                                 
//                                                                             
// Sources:    /trees/shung/shung-dev/chips/peregrine/1.0/ip/athr/wifi/rtl/./mac/rtl/dev/mac/rtl/mac_dma/blueprint/mac_qcu_reg.rdl
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


#ifndef _MAC_QCU_REG_H_
#define _MAC_QCU_REG_H_
// 0x0800 (MAC_QCU_TXDP_0)
#define MAC_QCU_TXDP_0_DATA_MSB                                      31
#define MAC_QCU_TXDP_0_DATA_LSB                                      0
#define MAC_QCU_TXDP_0_DATA_MASK                                     0xffffffff
#define MAC_QCU_TXDP_0_DATA_GET(x)                                   (((x) & MAC_QCU_TXDP_0_DATA_MASK) >> MAC_QCU_TXDP_0_DATA_LSB)
#define MAC_QCU_TXDP_0_DATA_SET(x)                                   (((0 | (x)) << MAC_QCU_TXDP_0_DATA_LSB) & MAC_QCU_TXDP_0_DATA_MASK)
#define MAC_QCU_TXDP_0_DATA_RESET                                    0
#define MAC_QCU_TXDP_0_ADDRESS                                       0x0800
#define MAC_QCU_TXDP_ADDRESS                                         MAC_QCU_TXDP_0_ADDRESS
#define MAC_QCU_TXDP_0_HW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_0_SW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_0_HW_WRITE_MASK                                 0x00000000
#define MAC_QCU_TXDP_0_SW_WRITE_MASK                                 0xffffffff
#define MAC_QCU_TXDP_0_RSTMASK                                       0xffffffff
#define MAC_QCU_TXDP_0_RESET                                         0x00000000

// 0x0804 (MAC_QCU_TXDP_1)
#define MAC_QCU_TXDP_1_DATA_MSB                                      31
#define MAC_QCU_TXDP_1_DATA_LSB                                      0
#define MAC_QCU_TXDP_1_DATA_MASK                                     0xffffffff
#define MAC_QCU_TXDP_1_DATA_GET(x)                                   (((x) & MAC_QCU_TXDP_1_DATA_MASK) >> MAC_QCU_TXDP_1_DATA_LSB)
#define MAC_QCU_TXDP_1_DATA_SET(x)                                   (((0 | (x)) << MAC_QCU_TXDP_1_DATA_LSB) & MAC_QCU_TXDP_1_DATA_MASK)
#define MAC_QCU_TXDP_1_DATA_RESET                                    0
#define MAC_QCU_TXDP_1_ADDRESS                                       0x0804
#define MAC_QCU_TXDP_1_HW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_1_SW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_1_HW_WRITE_MASK                                 0x00000000
#define MAC_QCU_TXDP_1_SW_WRITE_MASK                                 0xffffffff
#define MAC_QCU_TXDP_1_RSTMASK                                       0xffffffff
#define MAC_QCU_TXDP_1_RESET                                         0x00000000

// 0x0808 (MAC_QCU_TXDP_2)
#define MAC_QCU_TXDP_2_DATA_MSB                                      31
#define MAC_QCU_TXDP_2_DATA_LSB                                      0
#define MAC_QCU_TXDP_2_DATA_MASK                                     0xffffffff
#define MAC_QCU_TXDP_2_DATA_GET(x)                                   (((x) & MAC_QCU_TXDP_2_DATA_MASK) >> MAC_QCU_TXDP_2_DATA_LSB)
#define MAC_QCU_TXDP_2_DATA_SET(x)                                   (((0 | (x)) << MAC_QCU_TXDP_2_DATA_LSB) & MAC_QCU_TXDP_2_DATA_MASK)
#define MAC_QCU_TXDP_2_DATA_RESET                                    0
#define MAC_QCU_TXDP_2_ADDRESS                                       0x0808
#define MAC_QCU_TXDP_2_HW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_2_SW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_2_HW_WRITE_MASK                                 0x00000000
#define MAC_QCU_TXDP_2_SW_WRITE_MASK                                 0xffffffff
#define MAC_QCU_TXDP_2_RSTMASK                                       0xffffffff
#define MAC_QCU_TXDP_2_RESET                                         0x00000000

// 0x080c (MAC_QCU_TXDP_3)
#define MAC_QCU_TXDP_3_DATA_MSB                                      31
#define MAC_QCU_TXDP_3_DATA_LSB                                      0
#define MAC_QCU_TXDP_3_DATA_MASK                                     0xffffffff
#define MAC_QCU_TXDP_3_DATA_GET(x)                                   (((x) & MAC_QCU_TXDP_3_DATA_MASK) >> MAC_QCU_TXDP_3_DATA_LSB)
#define MAC_QCU_TXDP_3_DATA_SET(x)                                   (((0 | (x)) << MAC_QCU_TXDP_3_DATA_LSB) & MAC_QCU_TXDP_3_DATA_MASK)
#define MAC_QCU_TXDP_3_DATA_RESET                                    0
#define MAC_QCU_TXDP_3_ADDRESS                                       0x080c
#define MAC_QCU_TXDP_3_HW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_3_SW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_3_HW_WRITE_MASK                                 0x00000000
#define MAC_QCU_TXDP_3_SW_WRITE_MASK                                 0xffffffff
#define MAC_QCU_TXDP_3_RSTMASK                                       0xffffffff
#define MAC_QCU_TXDP_3_RESET                                         0x00000000

// 0x0810 (MAC_QCU_TXDP_4)
#define MAC_QCU_TXDP_4_DATA_MSB                                      31
#define MAC_QCU_TXDP_4_DATA_LSB                                      0
#define MAC_QCU_TXDP_4_DATA_MASK                                     0xffffffff
#define MAC_QCU_TXDP_4_DATA_GET(x)                                   (((x) & MAC_QCU_TXDP_4_DATA_MASK) >> MAC_QCU_TXDP_4_DATA_LSB)
#define MAC_QCU_TXDP_4_DATA_SET(x)                                   (((0 | (x)) << MAC_QCU_TXDP_4_DATA_LSB) & MAC_QCU_TXDP_4_DATA_MASK)
#define MAC_QCU_TXDP_4_DATA_RESET                                    0
#define MAC_QCU_TXDP_4_ADDRESS                                       0x0810
#define MAC_QCU_TXDP_4_HW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_4_SW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_4_HW_WRITE_MASK                                 0x00000000
#define MAC_QCU_TXDP_4_SW_WRITE_MASK                                 0xffffffff
#define MAC_QCU_TXDP_4_RSTMASK                                       0xffffffff
#define MAC_QCU_TXDP_4_RESET                                         0x00000000

// 0x0814 (MAC_QCU_TXDP_5)
#define MAC_QCU_TXDP_5_DATA_MSB                                      31
#define MAC_QCU_TXDP_5_DATA_LSB                                      0
#define MAC_QCU_TXDP_5_DATA_MASK                                     0xffffffff
#define MAC_QCU_TXDP_5_DATA_GET(x)                                   (((x) & MAC_QCU_TXDP_5_DATA_MASK) >> MAC_QCU_TXDP_5_DATA_LSB)
#define MAC_QCU_TXDP_5_DATA_SET(x)                                   (((0 | (x)) << MAC_QCU_TXDP_5_DATA_LSB) & MAC_QCU_TXDP_5_DATA_MASK)
#define MAC_QCU_TXDP_5_DATA_RESET                                    0
#define MAC_QCU_TXDP_5_ADDRESS                                       0x0814
#define MAC_QCU_TXDP_5_HW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_5_SW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_5_HW_WRITE_MASK                                 0x00000000
#define MAC_QCU_TXDP_5_SW_WRITE_MASK                                 0xffffffff
#define MAC_QCU_TXDP_5_RSTMASK                                       0xffffffff
#define MAC_QCU_TXDP_5_RESET                                         0x00000000

// 0x0818 (MAC_QCU_TXDP_6)
#define MAC_QCU_TXDP_6_DATA_MSB                                      31
#define MAC_QCU_TXDP_6_DATA_LSB                                      0
#define MAC_QCU_TXDP_6_DATA_MASK                                     0xffffffff
#define MAC_QCU_TXDP_6_DATA_GET(x)                                   (((x) & MAC_QCU_TXDP_6_DATA_MASK) >> MAC_QCU_TXDP_6_DATA_LSB)
#define MAC_QCU_TXDP_6_DATA_SET(x)                                   (((0 | (x)) << MAC_QCU_TXDP_6_DATA_LSB) & MAC_QCU_TXDP_6_DATA_MASK)
#define MAC_QCU_TXDP_6_DATA_RESET                                    0
#define MAC_QCU_TXDP_6_ADDRESS                                       0x0818
#define MAC_QCU_TXDP_6_HW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_6_SW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_6_HW_WRITE_MASK                                 0x00000000
#define MAC_QCU_TXDP_6_SW_WRITE_MASK                                 0xffffffff
#define MAC_QCU_TXDP_6_RSTMASK                                       0xffffffff
#define MAC_QCU_TXDP_6_RESET                                         0x00000000

// 0x081c (MAC_QCU_TXDP_7)
#define MAC_QCU_TXDP_7_DATA_MSB                                      31
#define MAC_QCU_TXDP_7_DATA_LSB                                      0
#define MAC_QCU_TXDP_7_DATA_MASK                                     0xffffffff
#define MAC_QCU_TXDP_7_DATA_GET(x)                                   (((x) & MAC_QCU_TXDP_7_DATA_MASK) >> MAC_QCU_TXDP_7_DATA_LSB)
#define MAC_QCU_TXDP_7_DATA_SET(x)                                   (((0 | (x)) << MAC_QCU_TXDP_7_DATA_LSB) & MAC_QCU_TXDP_7_DATA_MASK)
#define MAC_QCU_TXDP_7_DATA_RESET                                    0
#define MAC_QCU_TXDP_7_ADDRESS                                       0x081c
#define MAC_QCU_TXDP_7_HW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_7_SW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_7_HW_WRITE_MASK                                 0x00000000
#define MAC_QCU_TXDP_7_SW_WRITE_MASK                                 0xffffffff
#define MAC_QCU_TXDP_7_RSTMASK                                       0xffffffff
#define MAC_QCU_TXDP_7_RESET                                         0x00000000

// 0x0820 (MAC_QCU_TXDP_8)
#define MAC_QCU_TXDP_8_DATA_MSB                                      31
#define MAC_QCU_TXDP_8_DATA_LSB                                      0
#define MAC_QCU_TXDP_8_DATA_MASK                                     0xffffffff
#define MAC_QCU_TXDP_8_DATA_GET(x)                                   (((x) & MAC_QCU_TXDP_8_DATA_MASK) >> MAC_QCU_TXDP_8_DATA_LSB)
#define MAC_QCU_TXDP_8_DATA_SET(x)                                   (((0 | (x)) << MAC_QCU_TXDP_8_DATA_LSB) & MAC_QCU_TXDP_8_DATA_MASK)
#define MAC_QCU_TXDP_8_DATA_RESET                                    0
#define MAC_QCU_TXDP_8_ADDRESS                                       0x0820
#define MAC_QCU_TXDP_8_HW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_8_SW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_8_HW_WRITE_MASK                                 0x00000000
#define MAC_QCU_TXDP_8_SW_WRITE_MASK                                 0xffffffff
#define MAC_QCU_TXDP_8_RSTMASK                                       0xffffffff
#define MAC_QCU_TXDP_8_RESET                                         0x00000000

// 0x0824 (MAC_QCU_TXDP_9)
#define MAC_QCU_TXDP_9_DATA_MSB                                      31
#define MAC_QCU_TXDP_9_DATA_LSB                                      0
#define MAC_QCU_TXDP_9_DATA_MASK                                     0xffffffff
#define MAC_QCU_TXDP_9_DATA_GET(x)                                   (((x) & MAC_QCU_TXDP_9_DATA_MASK) >> MAC_QCU_TXDP_9_DATA_LSB)
#define MAC_QCU_TXDP_9_DATA_SET(x)                                   (((0 | (x)) << MAC_QCU_TXDP_9_DATA_LSB) & MAC_QCU_TXDP_9_DATA_MASK)
#define MAC_QCU_TXDP_9_DATA_RESET                                    0
#define MAC_QCU_TXDP_9_ADDRESS                                       0x0824
#define MAC_QCU_TXDP_9_HW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_9_SW_MASK                                       0xffffffff
#define MAC_QCU_TXDP_9_HW_WRITE_MASK                                 0x00000000
#define MAC_QCU_TXDP_9_SW_WRITE_MASK                                 0xffffffff
#define MAC_QCU_TXDP_9_RSTMASK                                       0xffffffff
#define MAC_QCU_TXDP_9_RESET                                         0x00000000

// 0x0840 (MAC_QCU_TXE)
#define MAC_QCU_TXE_DATA_MSB                                         9
#define MAC_QCU_TXE_DATA_LSB                                         0
#define MAC_QCU_TXE_DATA_MASK                                        0x000003ff
#define MAC_QCU_TXE_DATA_GET(x)                                      (((x) & MAC_QCU_TXE_DATA_MASK) >> MAC_QCU_TXE_DATA_LSB)
#define MAC_QCU_TXE_DATA_SET(x)                                      (((0 | (x)) << MAC_QCU_TXE_DATA_LSB) & MAC_QCU_TXE_DATA_MASK)
#define MAC_QCU_TXE_DATA_RESET                                       0
#define MAC_QCU_TXE_ADDRESS                                          0x0840
#define MAC_QCU_TXE_HW_MASK                                          0x000003ff
#define MAC_QCU_TXE_SW_MASK                                          0x000003ff
#define MAC_QCU_TXE_HW_WRITE_MASK                                    0x000003ff
#define MAC_QCU_TXE_SW_WRITE_MASK                                    0x00000000
#define MAC_QCU_TXE_RSTMASK                                          0xffffffff
#define MAC_QCU_TXE_RESET                                            0x00000000

// 0x0880 (MAC_QCU_TXD)
#define MAC_QCU_TXD_DATA_MSB                                         9
#define MAC_QCU_TXD_DATA_LSB                                         0
#define MAC_QCU_TXD_DATA_MASK                                        0x000003ff
#define MAC_QCU_TXD_DATA_GET(x)                                      (((x) & MAC_QCU_TXD_DATA_MASK) >> MAC_QCU_TXD_DATA_LSB)
#define MAC_QCU_TXD_DATA_SET(x)                                      (((0 | (x)) << MAC_QCU_TXD_DATA_LSB) & MAC_QCU_TXD_DATA_MASK)
#define MAC_QCU_TXD_DATA_RESET                                       0
#define MAC_QCU_TXD_ADDRESS                                          0x0880
#define MAC_QCU_TXD_HW_MASK                                          0x000003ff
#define MAC_QCU_TXD_SW_MASK                                          0x000003ff
#define MAC_QCU_TXD_HW_WRITE_MASK                                    0x00000000
#define MAC_QCU_TXD_SW_WRITE_MASK                                    0x000003ff
#define MAC_QCU_TXD_RSTMASK                                          0xffffffff
#define MAC_QCU_TXD_RESET                                            0x00000000

// 0x08c0 (MAC_QCU_CBR_0)
#define MAC_QCU_CBR_0_OVF_THRESH_MSB                                 31
#define MAC_QCU_CBR_0_OVF_THRESH_LSB                                 24
#define MAC_QCU_CBR_0_OVF_THRESH_MASK                                0xff000000
#define MAC_QCU_CBR_0_OVF_THRESH_GET(x)                              (((x) & MAC_QCU_CBR_0_OVF_THRESH_MASK) >> MAC_QCU_CBR_0_OVF_THRESH_LSB)
#define MAC_QCU_CBR_0_OVF_THRESH_SET(x)                              (((0 | (x)) << MAC_QCU_CBR_0_OVF_THRESH_LSB) & MAC_QCU_CBR_0_OVF_THRESH_MASK)
#define MAC_QCU_CBR_0_OVF_THRESH_RESET                               0
#define MAC_QCU_CBR_0_INTERVAL_MSB                                   23
#define MAC_QCU_CBR_0_INTERVAL_LSB                                   0
#define MAC_QCU_CBR_0_INTERVAL_MASK                                  0x00ffffff
#define MAC_QCU_CBR_0_INTERVAL_GET(x)                                (((x) & MAC_QCU_CBR_0_INTERVAL_MASK) >> MAC_QCU_CBR_0_INTERVAL_LSB)
#define MAC_QCU_CBR_0_INTERVAL_SET(x)                                (((0 | (x)) << MAC_QCU_CBR_0_INTERVAL_LSB) & MAC_QCU_CBR_0_INTERVAL_MASK)
#define MAC_QCU_CBR_0_INTERVAL_RESET                                 0
#define MAC_QCU_CBR_0_ADDRESS                                        0x08c0
#define MAC_QCU_CBR_ADDRESS                                          MAC_QCU_CBR_0_ADDRESS
#define MAC_QCU_CBR_0_HW_MASK                                        0xffffffff
#define MAC_QCU_CBR_0_SW_MASK                                        0xffffffff
#define MAC_QCU_CBR_0_HW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CBR_0_SW_WRITE_MASK                                  0xffffffff
#define MAC_QCU_CBR_0_RSTMASK                                        0xffffffff
#define MAC_QCU_CBR_0_RESET                                          0x00000000

// 0x08c4 (MAC_QCU_CBR_1)
#define MAC_QCU_CBR_1_OVF_THRESH_MSB                                 31
#define MAC_QCU_CBR_1_OVF_THRESH_LSB                                 24
#define MAC_QCU_CBR_1_OVF_THRESH_MASK                                0xff000000
#define MAC_QCU_CBR_1_OVF_THRESH_GET(x)                              (((x) & MAC_QCU_CBR_1_OVF_THRESH_MASK) >> MAC_QCU_CBR_1_OVF_THRESH_LSB)
#define MAC_QCU_CBR_1_OVF_THRESH_SET(x)                              (((0 | (x)) << MAC_QCU_CBR_1_OVF_THRESH_LSB) & MAC_QCU_CBR_1_OVF_THRESH_MASK)
#define MAC_QCU_CBR_1_OVF_THRESH_RESET                               0
#define MAC_QCU_CBR_1_INTERVAL_MSB                                   23
#define MAC_QCU_CBR_1_INTERVAL_LSB                                   0
#define MAC_QCU_CBR_1_INTERVAL_MASK                                  0x00ffffff
#define MAC_QCU_CBR_1_INTERVAL_GET(x)                                (((x) & MAC_QCU_CBR_1_INTERVAL_MASK) >> MAC_QCU_CBR_1_INTERVAL_LSB)
#define MAC_QCU_CBR_1_INTERVAL_SET(x)                                (((0 | (x)) << MAC_QCU_CBR_1_INTERVAL_LSB) & MAC_QCU_CBR_1_INTERVAL_MASK)
#define MAC_QCU_CBR_1_INTERVAL_RESET                                 0
#define MAC_QCU_CBR_1_ADDRESS                                        0x08c4
#define MAC_QCU_CBR_1_HW_MASK                                        0xffffffff
#define MAC_QCU_CBR_1_SW_MASK                                        0xffffffff
#define MAC_QCU_CBR_1_HW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CBR_1_SW_WRITE_MASK                                  0xffffffff
#define MAC_QCU_CBR_1_RSTMASK                                        0xffffffff
#define MAC_QCU_CBR_1_RESET                                          0x00000000

// 0x08c8 (MAC_QCU_CBR_2)
#define MAC_QCU_CBR_2_OVF_THRESH_MSB                                 31
#define MAC_QCU_CBR_2_OVF_THRESH_LSB                                 24
#define MAC_QCU_CBR_2_OVF_THRESH_MASK                                0xff000000
#define MAC_QCU_CBR_2_OVF_THRESH_GET(x)                              (((x) & MAC_QCU_CBR_2_OVF_THRESH_MASK) >> MAC_QCU_CBR_2_OVF_THRESH_LSB)
#define MAC_QCU_CBR_2_OVF_THRESH_SET(x)                              (((0 | (x)) << MAC_QCU_CBR_2_OVF_THRESH_LSB) & MAC_QCU_CBR_2_OVF_THRESH_MASK)
#define MAC_QCU_CBR_2_OVF_THRESH_RESET                               0
#define MAC_QCU_CBR_2_INTERVAL_MSB                                   23
#define MAC_QCU_CBR_2_INTERVAL_LSB                                   0
#define MAC_QCU_CBR_2_INTERVAL_MASK                                  0x00ffffff
#define MAC_QCU_CBR_2_INTERVAL_GET(x)                                (((x) & MAC_QCU_CBR_2_INTERVAL_MASK) >> MAC_QCU_CBR_2_INTERVAL_LSB)
#define MAC_QCU_CBR_2_INTERVAL_SET(x)                                (((0 | (x)) << MAC_QCU_CBR_2_INTERVAL_LSB) & MAC_QCU_CBR_2_INTERVAL_MASK)
#define MAC_QCU_CBR_2_INTERVAL_RESET                                 0
#define MAC_QCU_CBR_2_ADDRESS                                        0x08c8
#define MAC_QCU_CBR_2_HW_MASK                                        0xffffffff
#define MAC_QCU_CBR_2_SW_MASK                                        0xffffffff
#define MAC_QCU_CBR_2_HW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CBR_2_SW_WRITE_MASK                                  0xffffffff
#define MAC_QCU_CBR_2_RSTMASK                                        0xffffffff
#define MAC_QCU_CBR_2_RESET                                          0x00000000

// 0x08cc (MAC_QCU_CBR_3)
#define MAC_QCU_CBR_3_OVF_THRESH_MSB                                 31
#define MAC_QCU_CBR_3_OVF_THRESH_LSB                                 24
#define MAC_QCU_CBR_3_OVF_THRESH_MASK                                0xff000000
#define MAC_QCU_CBR_3_OVF_THRESH_GET(x)                              (((x) & MAC_QCU_CBR_3_OVF_THRESH_MASK) >> MAC_QCU_CBR_3_OVF_THRESH_LSB)
#define MAC_QCU_CBR_3_OVF_THRESH_SET(x)                              (((0 | (x)) << MAC_QCU_CBR_3_OVF_THRESH_LSB) & MAC_QCU_CBR_3_OVF_THRESH_MASK)
#define MAC_QCU_CBR_3_OVF_THRESH_RESET                               0
#define MAC_QCU_CBR_3_INTERVAL_MSB                                   23
#define MAC_QCU_CBR_3_INTERVAL_LSB                                   0
#define MAC_QCU_CBR_3_INTERVAL_MASK                                  0x00ffffff
#define MAC_QCU_CBR_3_INTERVAL_GET(x)                                (((x) & MAC_QCU_CBR_3_INTERVAL_MASK) >> MAC_QCU_CBR_3_INTERVAL_LSB)
#define MAC_QCU_CBR_3_INTERVAL_SET(x)                                (((0 | (x)) << MAC_QCU_CBR_3_INTERVAL_LSB) & MAC_QCU_CBR_3_INTERVAL_MASK)
#define MAC_QCU_CBR_3_INTERVAL_RESET                                 0
#define MAC_QCU_CBR_3_ADDRESS                                        0x08cc
#define MAC_QCU_CBR_3_HW_MASK                                        0xffffffff
#define MAC_QCU_CBR_3_SW_MASK                                        0xffffffff
#define MAC_QCU_CBR_3_HW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CBR_3_SW_WRITE_MASK                                  0xffffffff
#define MAC_QCU_CBR_3_RSTMASK                                        0xffffffff
#define MAC_QCU_CBR_3_RESET                                          0x00000000

// 0x08d0 (MAC_QCU_CBR_4)
#define MAC_QCU_CBR_4_OVF_THRESH_MSB                                 31
#define MAC_QCU_CBR_4_OVF_THRESH_LSB                                 24
#define MAC_QCU_CBR_4_OVF_THRESH_MASK                                0xff000000
#define MAC_QCU_CBR_4_OVF_THRESH_GET(x)                              (((x) & MAC_QCU_CBR_4_OVF_THRESH_MASK) >> MAC_QCU_CBR_4_OVF_THRESH_LSB)
#define MAC_QCU_CBR_4_OVF_THRESH_SET(x)                              (((0 | (x)) << MAC_QCU_CBR_4_OVF_THRESH_LSB) & MAC_QCU_CBR_4_OVF_THRESH_MASK)
#define MAC_QCU_CBR_4_OVF_THRESH_RESET                               0
#define MAC_QCU_CBR_4_INTERVAL_MSB                                   23
#define MAC_QCU_CBR_4_INTERVAL_LSB                                   0
#define MAC_QCU_CBR_4_INTERVAL_MASK                                  0x00ffffff
#define MAC_QCU_CBR_4_INTERVAL_GET(x)                                (((x) & MAC_QCU_CBR_4_INTERVAL_MASK) >> MAC_QCU_CBR_4_INTERVAL_LSB)
#define MAC_QCU_CBR_4_INTERVAL_SET(x)                                (((0 | (x)) << MAC_QCU_CBR_4_INTERVAL_LSB) & MAC_QCU_CBR_4_INTERVAL_MASK)
#define MAC_QCU_CBR_4_INTERVAL_RESET                                 0
#define MAC_QCU_CBR_4_ADDRESS                                        0x08d0
#define MAC_QCU_CBR_4_HW_MASK                                        0xffffffff
#define MAC_QCU_CBR_4_SW_MASK                                        0xffffffff
#define MAC_QCU_CBR_4_HW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CBR_4_SW_WRITE_MASK                                  0xffffffff
#define MAC_QCU_CBR_4_RSTMASK                                        0xffffffff
#define MAC_QCU_CBR_4_RESET                                          0x00000000

// 0x08d4 (MAC_QCU_CBR_5)
#define MAC_QCU_CBR_5_OVF_THRESH_MSB                                 31
#define MAC_QCU_CBR_5_OVF_THRESH_LSB                                 24
#define MAC_QCU_CBR_5_OVF_THRESH_MASK                                0xff000000
#define MAC_QCU_CBR_5_OVF_THRESH_GET(x)                              (((x) & MAC_QCU_CBR_5_OVF_THRESH_MASK) >> MAC_QCU_CBR_5_OVF_THRESH_LSB)
#define MAC_QCU_CBR_5_OVF_THRESH_SET(x)                              (((0 | (x)) << MAC_QCU_CBR_5_OVF_THRESH_LSB) & MAC_QCU_CBR_5_OVF_THRESH_MASK)
#define MAC_QCU_CBR_5_OVF_THRESH_RESET                               0
#define MAC_QCU_CBR_5_INTERVAL_MSB                                   23
#define MAC_QCU_CBR_5_INTERVAL_LSB                                   0
#define MAC_QCU_CBR_5_INTERVAL_MASK                                  0x00ffffff
#define MAC_QCU_CBR_5_INTERVAL_GET(x)                                (((x) & MAC_QCU_CBR_5_INTERVAL_MASK) >> MAC_QCU_CBR_5_INTERVAL_LSB)
#define MAC_QCU_CBR_5_INTERVAL_SET(x)                                (((0 | (x)) << MAC_QCU_CBR_5_INTERVAL_LSB) & MAC_QCU_CBR_5_INTERVAL_MASK)
#define MAC_QCU_CBR_5_INTERVAL_RESET                                 0
#define MAC_QCU_CBR_5_ADDRESS                                        0x08d4
#define MAC_QCU_CBR_5_HW_MASK                                        0xffffffff
#define MAC_QCU_CBR_5_SW_MASK                                        0xffffffff
#define MAC_QCU_CBR_5_HW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CBR_5_SW_WRITE_MASK                                  0xffffffff
#define MAC_QCU_CBR_5_RSTMASK                                        0xffffffff
#define MAC_QCU_CBR_5_RESET                                          0x00000000

// 0x08d8 (MAC_QCU_CBR_6)
#define MAC_QCU_CBR_6_OVF_THRESH_MSB                                 31
#define MAC_QCU_CBR_6_OVF_THRESH_LSB                                 24
#define MAC_QCU_CBR_6_OVF_THRESH_MASK                                0xff000000
#define MAC_QCU_CBR_6_OVF_THRESH_GET(x)                              (((x) & MAC_QCU_CBR_6_OVF_THRESH_MASK) >> MAC_QCU_CBR_6_OVF_THRESH_LSB)
#define MAC_QCU_CBR_6_OVF_THRESH_SET(x)                              (((0 | (x)) << MAC_QCU_CBR_6_OVF_THRESH_LSB) & MAC_QCU_CBR_6_OVF_THRESH_MASK)
#define MAC_QCU_CBR_6_OVF_THRESH_RESET                               0
#define MAC_QCU_CBR_6_INTERVAL_MSB                                   23
#define MAC_QCU_CBR_6_INTERVAL_LSB                                   0
#define MAC_QCU_CBR_6_INTERVAL_MASK                                  0x00ffffff
#define MAC_QCU_CBR_6_INTERVAL_GET(x)                                (((x) & MAC_QCU_CBR_6_INTERVAL_MASK) >> MAC_QCU_CBR_6_INTERVAL_LSB)
#define MAC_QCU_CBR_6_INTERVAL_SET(x)                                (((0 | (x)) << MAC_QCU_CBR_6_INTERVAL_LSB) & MAC_QCU_CBR_6_INTERVAL_MASK)
#define MAC_QCU_CBR_6_INTERVAL_RESET                                 0
#define MAC_QCU_CBR_6_ADDRESS                                        0x08d8
#define MAC_QCU_CBR_6_HW_MASK                                        0xffffffff
#define MAC_QCU_CBR_6_SW_MASK                                        0xffffffff
#define MAC_QCU_CBR_6_HW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CBR_6_SW_WRITE_MASK                                  0xffffffff
#define MAC_QCU_CBR_6_RSTMASK                                        0xffffffff
#define MAC_QCU_CBR_6_RESET                                          0x00000000

// 0x08dc (MAC_QCU_CBR_7)
#define MAC_QCU_CBR_7_OVF_THRESH_MSB                                 31
#define MAC_QCU_CBR_7_OVF_THRESH_LSB                                 24
#define MAC_QCU_CBR_7_OVF_THRESH_MASK                                0xff000000
#define MAC_QCU_CBR_7_OVF_THRESH_GET(x)                              (((x) & MAC_QCU_CBR_7_OVF_THRESH_MASK) >> MAC_QCU_CBR_7_OVF_THRESH_LSB)
#define MAC_QCU_CBR_7_OVF_THRESH_SET(x)                              (((0 | (x)) << MAC_QCU_CBR_7_OVF_THRESH_LSB) & MAC_QCU_CBR_7_OVF_THRESH_MASK)
#define MAC_QCU_CBR_7_OVF_THRESH_RESET                               0
#define MAC_QCU_CBR_7_INTERVAL_MSB                                   23
#define MAC_QCU_CBR_7_INTERVAL_LSB                                   0
#define MAC_QCU_CBR_7_INTERVAL_MASK                                  0x00ffffff
#define MAC_QCU_CBR_7_INTERVAL_GET(x)                                (((x) & MAC_QCU_CBR_7_INTERVAL_MASK) >> MAC_QCU_CBR_7_INTERVAL_LSB)
#define MAC_QCU_CBR_7_INTERVAL_SET(x)                                (((0 | (x)) << MAC_QCU_CBR_7_INTERVAL_LSB) & MAC_QCU_CBR_7_INTERVAL_MASK)
#define MAC_QCU_CBR_7_INTERVAL_RESET                                 0
#define MAC_QCU_CBR_7_ADDRESS                                        0x08dc
#define MAC_QCU_CBR_7_HW_MASK                                        0xffffffff
#define MAC_QCU_CBR_7_SW_MASK                                        0xffffffff
#define MAC_QCU_CBR_7_HW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CBR_7_SW_WRITE_MASK                                  0xffffffff
#define MAC_QCU_CBR_7_RSTMASK                                        0xffffffff
#define MAC_QCU_CBR_7_RESET                                          0x00000000

// 0x08e0 (MAC_QCU_CBR_8)
#define MAC_QCU_CBR_8_OVF_THRESH_MSB                                 31
#define MAC_QCU_CBR_8_OVF_THRESH_LSB                                 24
#define MAC_QCU_CBR_8_OVF_THRESH_MASK                                0xff000000
#define MAC_QCU_CBR_8_OVF_THRESH_GET(x)                              (((x) & MAC_QCU_CBR_8_OVF_THRESH_MASK) >> MAC_QCU_CBR_8_OVF_THRESH_LSB)
#define MAC_QCU_CBR_8_OVF_THRESH_SET(x)                              (((0 | (x)) << MAC_QCU_CBR_8_OVF_THRESH_LSB) & MAC_QCU_CBR_8_OVF_THRESH_MASK)
#define MAC_QCU_CBR_8_OVF_THRESH_RESET                               0
#define MAC_QCU_CBR_8_INTERVAL_MSB                                   23
#define MAC_QCU_CBR_8_INTERVAL_LSB                                   0
#define MAC_QCU_CBR_8_INTERVAL_MASK                                  0x00ffffff
#define MAC_QCU_CBR_8_INTERVAL_GET(x)                                (((x) & MAC_QCU_CBR_8_INTERVAL_MASK) >> MAC_QCU_CBR_8_INTERVAL_LSB)
#define MAC_QCU_CBR_8_INTERVAL_SET(x)                                (((0 | (x)) << MAC_QCU_CBR_8_INTERVAL_LSB) & MAC_QCU_CBR_8_INTERVAL_MASK)
#define MAC_QCU_CBR_8_INTERVAL_RESET                                 0
#define MAC_QCU_CBR_8_ADDRESS                                        0x08e0
#define MAC_QCU_CBR_8_HW_MASK                                        0xffffffff
#define MAC_QCU_CBR_8_SW_MASK                                        0xffffffff
#define MAC_QCU_CBR_8_HW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CBR_8_SW_WRITE_MASK                                  0xffffffff
#define MAC_QCU_CBR_8_RSTMASK                                        0xffffffff
#define MAC_QCU_CBR_8_RESET                                          0x00000000

// 0x08e4 (MAC_QCU_CBR_9)
#define MAC_QCU_CBR_9_OVF_THRESH_MSB                                 31
#define MAC_QCU_CBR_9_OVF_THRESH_LSB                                 24
#define MAC_QCU_CBR_9_OVF_THRESH_MASK                                0xff000000
#define MAC_QCU_CBR_9_OVF_THRESH_GET(x)                              (((x) & MAC_QCU_CBR_9_OVF_THRESH_MASK) >> MAC_QCU_CBR_9_OVF_THRESH_LSB)
#define MAC_QCU_CBR_9_OVF_THRESH_SET(x)                              (((0 | (x)) << MAC_QCU_CBR_9_OVF_THRESH_LSB) & MAC_QCU_CBR_9_OVF_THRESH_MASK)
#define MAC_QCU_CBR_9_OVF_THRESH_RESET                               0
#define MAC_QCU_CBR_9_INTERVAL_MSB                                   23
#define MAC_QCU_CBR_9_INTERVAL_LSB                                   0
#define MAC_QCU_CBR_9_INTERVAL_MASK                                  0x00ffffff
#define MAC_QCU_CBR_9_INTERVAL_GET(x)                                (((x) & MAC_QCU_CBR_9_INTERVAL_MASK) >> MAC_QCU_CBR_9_INTERVAL_LSB)
#define MAC_QCU_CBR_9_INTERVAL_SET(x)                                (((0 | (x)) << MAC_QCU_CBR_9_INTERVAL_LSB) & MAC_QCU_CBR_9_INTERVAL_MASK)
#define MAC_QCU_CBR_9_INTERVAL_RESET                                 0
#define MAC_QCU_CBR_9_ADDRESS                                        0x08e4
#define MAC_QCU_CBR_9_HW_MASK                                        0xffffffff
#define MAC_QCU_CBR_9_SW_MASK                                        0xffffffff
#define MAC_QCU_CBR_9_HW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CBR_9_SW_WRITE_MASK                                  0xffffffff
#define MAC_QCU_CBR_9_RSTMASK                                        0xffffffff
#define MAC_QCU_CBR_9_RESET                                          0x00000000

// 0x0900 (MAC_QCU_RDYTIME_0)
#define MAC_QCU_RDYTIME_0_EN_MSB                                     24
#define MAC_QCU_RDYTIME_0_EN_LSB                                     24
#define MAC_QCU_RDYTIME_0_EN_MASK                                    0x01000000
#define MAC_QCU_RDYTIME_0_EN_GET(x)                                  (((x) & MAC_QCU_RDYTIME_0_EN_MASK) >> MAC_QCU_RDYTIME_0_EN_LSB)
#define MAC_QCU_RDYTIME_0_EN_SET(x)                                  (((0 | (x)) << MAC_QCU_RDYTIME_0_EN_LSB) & MAC_QCU_RDYTIME_0_EN_MASK)
#define MAC_QCU_RDYTIME_0_EN_RESET                                   0
#define MAC_QCU_RDYTIME_0_DURATION_MSB                               23
#define MAC_QCU_RDYTIME_0_DURATION_LSB                               0
#define MAC_QCU_RDYTIME_0_DURATION_MASK                              0x00ffffff
#define MAC_QCU_RDYTIME_0_DURATION_GET(x)                            (((x) & MAC_QCU_RDYTIME_0_DURATION_MASK) >> MAC_QCU_RDYTIME_0_DURATION_LSB)
#define MAC_QCU_RDYTIME_0_DURATION_SET(x)                            (((0 | (x)) << MAC_QCU_RDYTIME_0_DURATION_LSB) & MAC_QCU_RDYTIME_0_DURATION_MASK)
#define MAC_QCU_RDYTIME_0_DURATION_RESET                             0
#define MAC_QCU_RDYTIME_0_ADDRESS                                    0x0900
#define MAC_QCU_RDYTIME_ADDRESS                                      MAC_QCU_RDYTIME_0_ADDRESS
#define MAC_QCU_RDYTIME_0_HW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_0_SW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_0_HW_WRITE_MASK                              0x00000000
#define MAC_QCU_RDYTIME_0_SW_WRITE_MASK                              0x01ffffff
#define MAC_QCU_RDYTIME_0_RSTMASK                                    0xffffffff
#define MAC_QCU_RDYTIME_0_RESET                                      0x00000000

// 0x0904 (MAC_QCU_RDYTIME_1)
#define MAC_QCU_RDYTIME_1_EN_MSB                                     24
#define MAC_QCU_RDYTIME_1_EN_LSB                                     24
#define MAC_QCU_RDYTIME_1_EN_MASK                                    0x01000000
#define MAC_QCU_RDYTIME_1_EN_GET(x)                                  (((x) & MAC_QCU_RDYTIME_1_EN_MASK) >> MAC_QCU_RDYTIME_1_EN_LSB)
#define MAC_QCU_RDYTIME_1_EN_SET(x)                                  (((0 | (x)) << MAC_QCU_RDYTIME_1_EN_LSB) & MAC_QCU_RDYTIME_1_EN_MASK)
#define MAC_QCU_RDYTIME_1_EN_RESET                                   0
#define MAC_QCU_RDYTIME_1_DURATION_MSB                               23
#define MAC_QCU_RDYTIME_1_DURATION_LSB                               0
#define MAC_QCU_RDYTIME_1_DURATION_MASK                              0x00ffffff
#define MAC_QCU_RDYTIME_1_DURATION_GET(x)                            (((x) & MAC_QCU_RDYTIME_1_DURATION_MASK) >> MAC_QCU_RDYTIME_1_DURATION_LSB)
#define MAC_QCU_RDYTIME_1_DURATION_SET(x)                            (((0 | (x)) << MAC_QCU_RDYTIME_1_DURATION_LSB) & MAC_QCU_RDYTIME_1_DURATION_MASK)
#define MAC_QCU_RDYTIME_1_DURATION_RESET                             0
#define MAC_QCU_RDYTIME_1_ADDRESS                                    0x0904
#define MAC_QCU_RDYTIME_1_HW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_1_SW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_1_HW_WRITE_MASK                              0x00000000
#define MAC_QCU_RDYTIME_1_SW_WRITE_MASK                              0x01ffffff
#define MAC_QCU_RDYTIME_1_RSTMASK                                    0xffffffff
#define MAC_QCU_RDYTIME_1_RESET                                      0x00000000

// 0x0908 (MAC_QCU_RDYTIME_2)
#define MAC_QCU_RDYTIME_2_EN_MSB                                     24
#define MAC_QCU_RDYTIME_2_EN_LSB                                     24
#define MAC_QCU_RDYTIME_2_EN_MASK                                    0x01000000
#define MAC_QCU_RDYTIME_2_EN_GET(x)                                  (((x) & MAC_QCU_RDYTIME_2_EN_MASK) >> MAC_QCU_RDYTIME_2_EN_LSB)
#define MAC_QCU_RDYTIME_2_EN_SET(x)                                  (((0 | (x)) << MAC_QCU_RDYTIME_2_EN_LSB) & MAC_QCU_RDYTIME_2_EN_MASK)
#define MAC_QCU_RDYTIME_2_EN_RESET                                   0
#define MAC_QCU_RDYTIME_2_DURATION_MSB                               23
#define MAC_QCU_RDYTIME_2_DURATION_LSB                               0
#define MAC_QCU_RDYTIME_2_DURATION_MASK                              0x00ffffff
#define MAC_QCU_RDYTIME_2_DURATION_GET(x)                            (((x) & MAC_QCU_RDYTIME_2_DURATION_MASK) >> MAC_QCU_RDYTIME_2_DURATION_LSB)
#define MAC_QCU_RDYTIME_2_DURATION_SET(x)                            (((0 | (x)) << MAC_QCU_RDYTIME_2_DURATION_LSB) & MAC_QCU_RDYTIME_2_DURATION_MASK)
#define MAC_QCU_RDYTIME_2_DURATION_RESET                             0
#define MAC_QCU_RDYTIME_2_ADDRESS                                    0x0908
#define MAC_QCU_RDYTIME_2_HW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_2_SW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_2_HW_WRITE_MASK                              0x00000000
#define MAC_QCU_RDYTIME_2_SW_WRITE_MASK                              0x01ffffff
#define MAC_QCU_RDYTIME_2_RSTMASK                                    0xffffffff
#define MAC_QCU_RDYTIME_2_RESET                                      0x00000000

// 0x090c (MAC_QCU_RDYTIME_3)
#define MAC_QCU_RDYTIME_3_EN_MSB                                     24
#define MAC_QCU_RDYTIME_3_EN_LSB                                     24
#define MAC_QCU_RDYTIME_3_EN_MASK                                    0x01000000
#define MAC_QCU_RDYTIME_3_EN_GET(x)                                  (((x) & MAC_QCU_RDYTIME_3_EN_MASK) >> MAC_QCU_RDYTIME_3_EN_LSB)
#define MAC_QCU_RDYTIME_3_EN_SET(x)                                  (((0 | (x)) << MAC_QCU_RDYTIME_3_EN_LSB) & MAC_QCU_RDYTIME_3_EN_MASK)
#define MAC_QCU_RDYTIME_3_EN_RESET                                   0
#define MAC_QCU_RDYTIME_3_DURATION_MSB                               23
#define MAC_QCU_RDYTIME_3_DURATION_LSB                               0
#define MAC_QCU_RDYTIME_3_DURATION_MASK                              0x00ffffff
#define MAC_QCU_RDYTIME_3_DURATION_GET(x)                            (((x) & MAC_QCU_RDYTIME_3_DURATION_MASK) >> MAC_QCU_RDYTIME_3_DURATION_LSB)
#define MAC_QCU_RDYTIME_3_DURATION_SET(x)                            (((0 | (x)) << MAC_QCU_RDYTIME_3_DURATION_LSB) & MAC_QCU_RDYTIME_3_DURATION_MASK)
#define MAC_QCU_RDYTIME_3_DURATION_RESET                             0
#define MAC_QCU_RDYTIME_3_ADDRESS                                    0x090c
#define MAC_QCU_RDYTIME_3_HW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_3_SW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_3_HW_WRITE_MASK                              0x00000000
#define MAC_QCU_RDYTIME_3_SW_WRITE_MASK                              0x01ffffff
#define MAC_QCU_RDYTIME_3_RSTMASK                                    0xffffffff
#define MAC_QCU_RDYTIME_3_RESET                                      0x00000000

// 0x0910 (MAC_QCU_RDYTIME_4)
#define MAC_QCU_RDYTIME_4_EN_MSB                                     24
#define MAC_QCU_RDYTIME_4_EN_LSB                                     24
#define MAC_QCU_RDYTIME_4_EN_MASK                                    0x01000000
#define MAC_QCU_RDYTIME_4_EN_GET(x)                                  (((x) & MAC_QCU_RDYTIME_4_EN_MASK) >> MAC_QCU_RDYTIME_4_EN_LSB)
#define MAC_QCU_RDYTIME_4_EN_SET(x)                                  (((0 | (x)) << MAC_QCU_RDYTIME_4_EN_LSB) & MAC_QCU_RDYTIME_4_EN_MASK)
#define MAC_QCU_RDYTIME_4_EN_RESET                                   0
#define MAC_QCU_RDYTIME_4_DURATION_MSB                               23
#define MAC_QCU_RDYTIME_4_DURATION_LSB                               0
#define MAC_QCU_RDYTIME_4_DURATION_MASK                              0x00ffffff
#define MAC_QCU_RDYTIME_4_DURATION_GET(x)                            (((x) & MAC_QCU_RDYTIME_4_DURATION_MASK) >> MAC_QCU_RDYTIME_4_DURATION_LSB)
#define MAC_QCU_RDYTIME_4_DURATION_SET(x)                            (((0 | (x)) << MAC_QCU_RDYTIME_4_DURATION_LSB) & MAC_QCU_RDYTIME_4_DURATION_MASK)
#define MAC_QCU_RDYTIME_4_DURATION_RESET                             0
#define MAC_QCU_RDYTIME_4_ADDRESS                                    0x0910
#define MAC_QCU_RDYTIME_4_HW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_4_SW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_4_HW_WRITE_MASK                              0x00000000
#define MAC_QCU_RDYTIME_4_SW_WRITE_MASK                              0x01ffffff
#define MAC_QCU_RDYTIME_4_RSTMASK                                    0xffffffff
#define MAC_QCU_RDYTIME_4_RESET                                      0x00000000

// 0x0914 (MAC_QCU_RDYTIME_5)
#define MAC_QCU_RDYTIME_5_EN_MSB                                     24
#define MAC_QCU_RDYTIME_5_EN_LSB                                     24
#define MAC_QCU_RDYTIME_5_EN_MASK                                    0x01000000
#define MAC_QCU_RDYTIME_5_EN_GET(x)                                  (((x) & MAC_QCU_RDYTIME_5_EN_MASK) >> MAC_QCU_RDYTIME_5_EN_LSB)
#define MAC_QCU_RDYTIME_5_EN_SET(x)                                  (((0 | (x)) << MAC_QCU_RDYTIME_5_EN_LSB) & MAC_QCU_RDYTIME_5_EN_MASK)
#define MAC_QCU_RDYTIME_5_EN_RESET                                   0
#define MAC_QCU_RDYTIME_5_DURATION_MSB                               23
#define MAC_QCU_RDYTIME_5_DURATION_LSB                               0
#define MAC_QCU_RDYTIME_5_DURATION_MASK                              0x00ffffff
#define MAC_QCU_RDYTIME_5_DURATION_GET(x)                            (((x) & MAC_QCU_RDYTIME_5_DURATION_MASK) >> MAC_QCU_RDYTIME_5_DURATION_LSB)
#define MAC_QCU_RDYTIME_5_DURATION_SET(x)                            (((0 | (x)) << MAC_QCU_RDYTIME_5_DURATION_LSB) & MAC_QCU_RDYTIME_5_DURATION_MASK)
#define MAC_QCU_RDYTIME_5_DURATION_RESET                             0
#define MAC_QCU_RDYTIME_5_ADDRESS                                    0x0914
#define MAC_QCU_RDYTIME_5_HW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_5_SW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_5_HW_WRITE_MASK                              0x00000000
#define MAC_QCU_RDYTIME_5_SW_WRITE_MASK                              0x01ffffff
#define MAC_QCU_RDYTIME_5_RSTMASK                                    0xffffffff
#define MAC_QCU_RDYTIME_5_RESET                                      0x00000000

// 0x0918 (MAC_QCU_RDYTIME_6)
#define MAC_QCU_RDYTIME_6_EN_MSB                                     24
#define MAC_QCU_RDYTIME_6_EN_LSB                                     24
#define MAC_QCU_RDYTIME_6_EN_MASK                                    0x01000000
#define MAC_QCU_RDYTIME_6_EN_GET(x)                                  (((x) & MAC_QCU_RDYTIME_6_EN_MASK) >> MAC_QCU_RDYTIME_6_EN_LSB)
#define MAC_QCU_RDYTIME_6_EN_SET(x)                                  (((0 | (x)) << MAC_QCU_RDYTIME_6_EN_LSB) & MAC_QCU_RDYTIME_6_EN_MASK)
#define MAC_QCU_RDYTIME_6_EN_RESET                                   0
#define MAC_QCU_RDYTIME_6_DURATION_MSB                               23
#define MAC_QCU_RDYTIME_6_DURATION_LSB                               0
#define MAC_QCU_RDYTIME_6_DURATION_MASK                              0x00ffffff
#define MAC_QCU_RDYTIME_6_DURATION_GET(x)                            (((x) & MAC_QCU_RDYTIME_6_DURATION_MASK) >> MAC_QCU_RDYTIME_6_DURATION_LSB)
#define MAC_QCU_RDYTIME_6_DURATION_SET(x)                            (((0 | (x)) << MAC_QCU_RDYTIME_6_DURATION_LSB) & MAC_QCU_RDYTIME_6_DURATION_MASK)
#define MAC_QCU_RDYTIME_6_DURATION_RESET                             0
#define MAC_QCU_RDYTIME_6_ADDRESS                                    0x0918
#define MAC_QCU_RDYTIME_6_HW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_6_SW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_6_HW_WRITE_MASK                              0x00000000
#define MAC_QCU_RDYTIME_6_SW_WRITE_MASK                              0x01ffffff
#define MAC_QCU_RDYTIME_6_RSTMASK                                    0xffffffff
#define MAC_QCU_RDYTIME_6_RESET                                      0x00000000

// 0x091c (MAC_QCU_RDYTIME_7)
#define MAC_QCU_RDYTIME_7_EN_MSB                                     24
#define MAC_QCU_RDYTIME_7_EN_LSB                                     24
#define MAC_QCU_RDYTIME_7_EN_MASK                                    0x01000000
#define MAC_QCU_RDYTIME_7_EN_GET(x)                                  (((x) & MAC_QCU_RDYTIME_7_EN_MASK) >> MAC_QCU_RDYTIME_7_EN_LSB)
#define MAC_QCU_RDYTIME_7_EN_SET(x)                                  (((0 | (x)) << MAC_QCU_RDYTIME_7_EN_LSB) & MAC_QCU_RDYTIME_7_EN_MASK)
#define MAC_QCU_RDYTIME_7_EN_RESET                                   0
#define MAC_QCU_RDYTIME_7_DURATION_MSB                               23
#define MAC_QCU_RDYTIME_7_DURATION_LSB                               0
#define MAC_QCU_RDYTIME_7_DURATION_MASK                              0x00ffffff
#define MAC_QCU_RDYTIME_7_DURATION_GET(x)                            (((x) & MAC_QCU_RDYTIME_7_DURATION_MASK) >> MAC_QCU_RDYTIME_7_DURATION_LSB)
#define MAC_QCU_RDYTIME_7_DURATION_SET(x)                            (((0 | (x)) << MAC_QCU_RDYTIME_7_DURATION_LSB) & MAC_QCU_RDYTIME_7_DURATION_MASK)
#define MAC_QCU_RDYTIME_7_DURATION_RESET                             0
#define MAC_QCU_RDYTIME_7_ADDRESS                                    0x091c
#define MAC_QCU_RDYTIME_7_HW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_7_SW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_7_HW_WRITE_MASK                              0x00000000
#define MAC_QCU_RDYTIME_7_SW_WRITE_MASK                              0x01ffffff
#define MAC_QCU_RDYTIME_7_RSTMASK                                    0xffffffff
#define MAC_QCU_RDYTIME_7_RESET                                      0x00000000

// 0x0920 (MAC_QCU_RDYTIME_8)
#define MAC_QCU_RDYTIME_8_EN_MSB                                     24
#define MAC_QCU_RDYTIME_8_EN_LSB                                     24
#define MAC_QCU_RDYTIME_8_EN_MASK                                    0x01000000
#define MAC_QCU_RDYTIME_8_EN_GET(x)                                  (((x) & MAC_QCU_RDYTIME_8_EN_MASK) >> MAC_QCU_RDYTIME_8_EN_LSB)
#define MAC_QCU_RDYTIME_8_EN_SET(x)                                  (((0 | (x)) << MAC_QCU_RDYTIME_8_EN_LSB) & MAC_QCU_RDYTIME_8_EN_MASK)
#define MAC_QCU_RDYTIME_8_EN_RESET                                   0
#define MAC_QCU_RDYTIME_8_DURATION_MSB                               23
#define MAC_QCU_RDYTIME_8_DURATION_LSB                               0
#define MAC_QCU_RDYTIME_8_DURATION_MASK                              0x00ffffff
#define MAC_QCU_RDYTIME_8_DURATION_GET(x)                            (((x) & MAC_QCU_RDYTIME_8_DURATION_MASK) >> MAC_QCU_RDYTIME_8_DURATION_LSB)
#define MAC_QCU_RDYTIME_8_DURATION_SET(x)                            (((0 | (x)) << MAC_QCU_RDYTIME_8_DURATION_LSB) & MAC_QCU_RDYTIME_8_DURATION_MASK)
#define MAC_QCU_RDYTIME_8_DURATION_RESET                             0
#define MAC_QCU_RDYTIME_8_ADDRESS                                    0x0920
#define MAC_QCU_RDYTIME_8_HW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_8_SW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_8_HW_WRITE_MASK                              0x00000000
#define MAC_QCU_RDYTIME_8_SW_WRITE_MASK                              0x01ffffff
#define MAC_QCU_RDYTIME_8_RSTMASK                                    0xffffffff
#define MAC_QCU_RDYTIME_8_RESET                                      0x00000000

// 0x0924 (MAC_QCU_RDYTIME_9)
#define MAC_QCU_RDYTIME_9_EN_MSB                                     24
#define MAC_QCU_RDYTIME_9_EN_LSB                                     24
#define MAC_QCU_RDYTIME_9_EN_MASK                                    0x01000000
#define MAC_QCU_RDYTIME_9_EN_GET(x)                                  (((x) & MAC_QCU_RDYTIME_9_EN_MASK) >> MAC_QCU_RDYTIME_9_EN_LSB)
#define MAC_QCU_RDYTIME_9_EN_SET(x)                                  (((0 | (x)) << MAC_QCU_RDYTIME_9_EN_LSB) & MAC_QCU_RDYTIME_9_EN_MASK)
#define MAC_QCU_RDYTIME_9_EN_RESET                                   0
#define MAC_QCU_RDYTIME_9_DURATION_MSB                               23
#define MAC_QCU_RDYTIME_9_DURATION_LSB                               0
#define MAC_QCU_RDYTIME_9_DURATION_MASK                              0x00ffffff
#define MAC_QCU_RDYTIME_9_DURATION_GET(x)                            (((x) & MAC_QCU_RDYTIME_9_DURATION_MASK) >> MAC_QCU_RDYTIME_9_DURATION_LSB)
#define MAC_QCU_RDYTIME_9_DURATION_SET(x)                            (((0 | (x)) << MAC_QCU_RDYTIME_9_DURATION_LSB) & MAC_QCU_RDYTIME_9_DURATION_MASK)
#define MAC_QCU_RDYTIME_9_DURATION_RESET                             0
#define MAC_QCU_RDYTIME_9_ADDRESS                                    0x0924
#define MAC_QCU_RDYTIME_9_HW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_9_SW_MASK                                    0x01ffffff
#define MAC_QCU_RDYTIME_9_HW_WRITE_MASK                              0x00000000
#define MAC_QCU_RDYTIME_9_SW_WRITE_MASK                              0x01ffffff
#define MAC_QCU_RDYTIME_9_RSTMASK                                    0xffffffff
#define MAC_QCU_RDYTIME_9_RESET                                      0x00000000

// 0x0940 (MAC_QCU_ONESHOT_ARM_SC)
#define MAC_QCU_ONESHOT_ARM_SC_SET_MSB                               9
#define MAC_QCU_ONESHOT_ARM_SC_SET_LSB                               0
#define MAC_QCU_ONESHOT_ARM_SC_SET_MASK                              0x000003ff
#define MAC_QCU_ONESHOT_ARM_SC_SET_GET(x)                            (((x) & MAC_QCU_ONESHOT_ARM_SC_SET_MASK) >> MAC_QCU_ONESHOT_ARM_SC_SET_LSB)
#define MAC_QCU_ONESHOT_ARM_SC_SET_SET(x)                            (((0 | (x)) << MAC_QCU_ONESHOT_ARM_SC_SET_LSB) & MAC_QCU_ONESHOT_ARM_SC_SET_MASK)
#define MAC_QCU_ONESHOT_ARM_SC_SET_RESET                             0
#define MAC_QCU_ONESHOT_ARM_SC_ADDRESS                               0x0940
#define MAC_QCU_ONESHOT_ARM_SC_HW_MASK                               0x000003ff
#define MAC_QCU_ONESHOT_ARM_SC_SW_MASK                               0x000003ff
#define MAC_QCU_ONESHOT_ARM_SC_HW_WRITE_MASK                         0x00000000
#define MAC_QCU_ONESHOT_ARM_SC_SW_WRITE_MASK                         0x000003ff
#define MAC_QCU_ONESHOT_ARM_SC_RSTMASK                               0xffffffff
#define MAC_QCU_ONESHOT_ARM_SC_RESET                                 0x00000000

// 0x0980 (MAC_QCU_ONESHOT_ARM_CC)
#define MAC_QCU_ONESHOT_ARM_CC_CLEAR_MSB                             9
#define MAC_QCU_ONESHOT_ARM_CC_CLEAR_LSB                             0
#define MAC_QCU_ONESHOT_ARM_CC_CLEAR_MASK                            0x000003ff
#define MAC_QCU_ONESHOT_ARM_CC_CLEAR_GET(x)                          (((x) & MAC_QCU_ONESHOT_ARM_CC_CLEAR_MASK) >> MAC_QCU_ONESHOT_ARM_CC_CLEAR_LSB)
#define MAC_QCU_ONESHOT_ARM_CC_CLEAR_SET(x)                          (((0 | (x)) << MAC_QCU_ONESHOT_ARM_CC_CLEAR_LSB) & MAC_QCU_ONESHOT_ARM_CC_CLEAR_MASK)
#define MAC_QCU_ONESHOT_ARM_CC_CLEAR_RESET                           0
#define MAC_QCU_ONESHOT_ARM_CC_ADDRESS                               0x0980
#define MAC_QCU_ONESHOT_ARM_CC_HW_MASK                               0x000003ff
#define MAC_QCU_ONESHOT_ARM_CC_SW_MASK                               0x000003ff
#define MAC_QCU_ONESHOT_ARM_CC_HW_WRITE_MASK                         0x00000000
#define MAC_QCU_ONESHOT_ARM_CC_SW_WRITE_MASK                         0x000003ff
#define MAC_QCU_ONESHOT_ARM_CC_RSTMASK                               0xffffffff
#define MAC_QCU_ONESHOT_ARM_CC_RESET                                 0x00000000

// 0x09c0 (MAC_QCU_MISC_0)
#define MAC_QCU_MISC_0_NON_ASAP_FRAME_BURST_MSB                      12
#define MAC_QCU_MISC_0_NON_ASAP_FRAME_BURST_LSB                      12
#define MAC_QCU_MISC_0_NON_ASAP_FRAME_BURST_MASK                     0x00001000
#define MAC_QCU_MISC_0_NON_ASAP_FRAME_BURST_GET(x)                   (((x) & MAC_QCU_MISC_0_NON_ASAP_FRAME_BURST_MASK) >> MAC_QCU_MISC_0_NON_ASAP_FRAME_BURST_LSB)
#define MAC_QCU_MISC_0_NON_ASAP_FRAME_BURST_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_0_NON_ASAP_FRAME_BURST_LSB) & MAC_QCU_MISC_0_NON_ASAP_FRAME_BURST_MASK)
#define MAC_QCU_MISC_0_NON_ASAP_FRAME_BURST_RESET                    0
#define MAC_QCU_MISC_0_FR_ABORT_REQ_EN_MSB                           11
#define MAC_QCU_MISC_0_FR_ABORT_REQ_EN_LSB                           11
#define MAC_QCU_MISC_0_FR_ABORT_REQ_EN_MASK                          0x00000800
#define MAC_QCU_MISC_0_FR_ABORT_REQ_EN_GET(x)                        (((x) & MAC_QCU_MISC_0_FR_ABORT_REQ_EN_MASK) >> MAC_QCU_MISC_0_FR_ABORT_REQ_EN_LSB)
#define MAC_QCU_MISC_0_FR_ABORT_REQ_EN_SET(x)                        (((0 | (x)) << MAC_QCU_MISC_0_FR_ABORT_REQ_EN_LSB) & MAC_QCU_MISC_0_FR_ABORT_REQ_EN_MASK)
#define MAC_QCU_MISC_0_FR_ABORT_REQ_EN_RESET                         1
#define MAC_QCU_MISC_0_MMR_CBR_EXP_CNT_CLR_EN_MSB                    10
#define MAC_QCU_MISC_0_MMR_CBR_EXP_CNT_CLR_EN_LSB                    10
#define MAC_QCU_MISC_0_MMR_CBR_EXP_CNT_CLR_EN_MASK                   0x00000400
#define MAC_QCU_MISC_0_MMR_CBR_EXP_CNT_CLR_EN_GET(x)                 (((x) & MAC_QCU_MISC_0_MMR_CBR_EXP_CNT_CLR_EN_MASK) >> MAC_QCU_MISC_0_MMR_CBR_EXP_CNT_CLR_EN_LSB)
#define MAC_QCU_MISC_0_MMR_CBR_EXP_CNT_CLR_EN_SET(x)                 (((0 | (x)) << MAC_QCU_MISC_0_MMR_CBR_EXP_CNT_CLR_EN_LSB) & MAC_QCU_MISC_0_MMR_CBR_EXP_CNT_CLR_EN_MASK)
#define MAC_QCU_MISC_0_MMR_CBR_EXP_CNT_CLR_EN_RESET                  0
#define MAC_QCU_MISC_0_TXE_CLR_ON_CBR_END_MSB                        9
#define MAC_QCU_MISC_0_TXE_CLR_ON_CBR_END_LSB                        9
#define MAC_QCU_MISC_0_TXE_CLR_ON_CBR_END_MASK                       0x00000200
#define MAC_QCU_MISC_0_TXE_CLR_ON_CBR_END_GET(x)                     (((x) & MAC_QCU_MISC_0_TXE_CLR_ON_CBR_END_MASK) >> MAC_QCU_MISC_0_TXE_CLR_ON_CBR_END_LSB)
#define MAC_QCU_MISC_0_TXE_CLR_ON_CBR_END_SET(x)                     (((0 | (x)) << MAC_QCU_MISC_0_TXE_CLR_ON_CBR_END_LSB) & MAC_QCU_MISC_0_TXE_CLR_ON_CBR_END_MASK)
#define MAC_QCU_MISC_0_TXE_CLR_ON_CBR_END_RESET                      0
#define MAC_QCU_MISC_0_CBR_EXP_INC_LIMIT_MSB                         8
#define MAC_QCU_MISC_0_CBR_EXP_INC_LIMIT_LSB                         8
#define MAC_QCU_MISC_0_CBR_EXP_INC_LIMIT_MASK                        0x00000100
#define MAC_QCU_MISC_0_CBR_EXP_INC_LIMIT_GET(x)                      (((x) & MAC_QCU_MISC_0_CBR_EXP_INC_LIMIT_MASK) >> MAC_QCU_MISC_0_CBR_EXP_INC_LIMIT_LSB)
#define MAC_QCU_MISC_0_CBR_EXP_INC_LIMIT_SET(x)                      (((0 | (x)) << MAC_QCU_MISC_0_CBR_EXP_INC_LIMIT_LSB) & MAC_QCU_MISC_0_CBR_EXP_INC_LIMIT_MASK)
#define MAC_QCU_MISC_0_CBR_EXP_INC_LIMIT_RESET                       0
#define MAC_QCU_MISC_0_IS_BCN_MSB                                    7
#define MAC_QCU_MISC_0_IS_BCN_LSB                                    7
#define MAC_QCU_MISC_0_IS_BCN_MASK                                   0x00000080
#define MAC_QCU_MISC_0_IS_BCN_GET(x)                                 (((x) & MAC_QCU_MISC_0_IS_BCN_MASK) >> MAC_QCU_MISC_0_IS_BCN_LSB)
#define MAC_QCU_MISC_0_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_QCU_MISC_0_IS_BCN_LSB) & MAC_QCU_MISC_0_IS_BCN_MASK)
#define MAC_QCU_MISC_0_IS_BCN_RESET                                  0
#define MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOBCNFR_MSB                   6
#define MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOBCNFR_LSB                   6
#define MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOBCNFR_MASK                  0x00000040
#define MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOBCNFR_GET(x)                (((x) & MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOBCNFR_MASK) >> MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOBCNFR_LSB)
#define MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOBCNFR_SET(x)                (((0 | (x)) << MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOBCNFR_LSB) & MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOBCNFR_MASK)
#define MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOBCNFR_RESET                 0
#define MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOFR_MSB                      5
#define MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOFR_LSB                      5
#define MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOFR_MASK                     0x00000020
#define MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOFR_GET(x)                   (((x) & MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOFR_MASK) >> MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOFR_LSB)
#define MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOFR_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOFR_LSB) & MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOFR_MASK)
#define MAC_QCU_MISC_0_CBR_EXP_INC_DIS_NOFR_RESET                    0
#define MAC_QCU_MISC_0_ONESHOT_EN_MSB                                4
#define MAC_QCU_MISC_0_ONESHOT_EN_LSB                                4
#define MAC_QCU_MISC_0_ONESHOT_EN_MASK                               0x00000010
#define MAC_QCU_MISC_0_ONESHOT_EN_GET(x)                             (((x) & MAC_QCU_MISC_0_ONESHOT_EN_MASK) >> MAC_QCU_MISC_0_ONESHOT_EN_LSB)
#define MAC_QCU_MISC_0_ONESHOT_EN_SET(x)                             (((0 | (x)) << MAC_QCU_MISC_0_ONESHOT_EN_LSB) & MAC_QCU_MISC_0_ONESHOT_EN_MASK)
#define MAC_QCU_MISC_0_ONESHOT_EN_RESET                              0
#define MAC_QCU_MISC_0_FSP_MSB                                       3
#define MAC_QCU_MISC_0_FSP_LSB                                       0
#define MAC_QCU_MISC_0_FSP_MASK                                      0x0000000f
#define MAC_QCU_MISC_0_FSP_GET(x)                                    (((x) & MAC_QCU_MISC_0_FSP_MASK) >> MAC_QCU_MISC_0_FSP_LSB)
#define MAC_QCU_MISC_0_FSP_SET(x)                                    (((0 | (x)) << MAC_QCU_MISC_0_FSP_LSB) & MAC_QCU_MISC_0_FSP_MASK)
#define MAC_QCU_MISC_0_FSP_RESET                                     0
#define MAC_QCU_MISC_0_ADDRESS                                       0x09c0
#define MAC_QCU_MISC_ADDRESS                                         MAC_QCU_MISC_0_ADDRESS
#define MAC_QCU_MISC_0_HW_MASK                                       0x00001fff
#define MAC_QCU_MISC_0_SW_MASK                                       0x00001fff
#define MAC_QCU_MISC_0_HW_WRITE_MASK                                 0x00000400
#define MAC_QCU_MISC_0_SW_WRITE_MASK                                 0x00001fff
#define MAC_QCU_MISC_0_RSTMASK                                       0xffffffff
#define MAC_QCU_MISC_0_RESET                                         0x00000800

// 0x09c4 (MAC_QCU_MISC_1)
#define MAC_QCU_MISC_1_NON_ASAP_FRAME_BURST_MSB                      12
#define MAC_QCU_MISC_1_NON_ASAP_FRAME_BURST_LSB                      12
#define MAC_QCU_MISC_1_NON_ASAP_FRAME_BURST_MASK                     0x00001000
#define MAC_QCU_MISC_1_NON_ASAP_FRAME_BURST_GET(x)                   (((x) & MAC_QCU_MISC_1_NON_ASAP_FRAME_BURST_MASK) >> MAC_QCU_MISC_1_NON_ASAP_FRAME_BURST_LSB)
#define MAC_QCU_MISC_1_NON_ASAP_FRAME_BURST_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_1_NON_ASAP_FRAME_BURST_LSB) & MAC_QCU_MISC_1_NON_ASAP_FRAME_BURST_MASK)
#define MAC_QCU_MISC_1_NON_ASAP_FRAME_BURST_RESET                    0
#define MAC_QCU_MISC_1_FR_ABORT_REQ_EN_MSB                           11
#define MAC_QCU_MISC_1_FR_ABORT_REQ_EN_LSB                           11
#define MAC_QCU_MISC_1_FR_ABORT_REQ_EN_MASK                          0x00000800
#define MAC_QCU_MISC_1_FR_ABORT_REQ_EN_GET(x)                        (((x) & MAC_QCU_MISC_1_FR_ABORT_REQ_EN_MASK) >> MAC_QCU_MISC_1_FR_ABORT_REQ_EN_LSB)
#define MAC_QCU_MISC_1_FR_ABORT_REQ_EN_SET(x)                        (((0 | (x)) << MAC_QCU_MISC_1_FR_ABORT_REQ_EN_LSB) & MAC_QCU_MISC_1_FR_ABORT_REQ_EN_MASK)
#define MAC_QCU_MISC_1_FR_ABORT_REQ_EN_RESET                         1
#define MAC_QCU_MISC_1_MMR_CBR_EXP_CNT_CLR_EN_MSB                    10
#define MAC_QCU_MISC_1_MMR_CBR_EXP_CNT_CLR_EN_LSB                    10
#define MAC_QCU_MISC_1_MMR_CBR_EXP_CNT_CLR_EN_MASK                   0x00000400
#define MAC_QCU_MISC_1_MMR_CBR_EXP_CNT_CLR_EN_GET(x)                 (((x) & MAC_QCU_MISC_1_MMR_CBR_EXP_CNT_CLR_EN_MASK) >> MAC_QCU_MISC_1_MMR_CBR_EXP_CNT_CLR_EN_LSB)
#define MAC_QCU_MISC_1_MMR_CBR_EXP_CNT_CLR_EN_SET(x)                 (((0 | (x)) << MAC_QCU_MISC_1_MMR_CBR_EXP_CNT_CLR_EN_LSB) & MAC_QCU_MISC_1_MMR_CBR_EXP_CNT_CLR_EN_MASK)
#define MAC_QCU_MISC_1_MMR_CBR_EXP_CNT_CLR_EN_RESET                  0
#define MAC_QCU_MISC_1_TXE_CLR_ON_CBR_END_MSB                        9
#define MAC_QCU_MISC_1_TXE_CLR_ON_CBR_END_LSB                        9
#define MAC_QCU_MISC_1_TXE_CLR_ON_CBR_END_MASK                       0x00000200
#define MAC_QCU_MISC_1_TXE_CLR_ON_CBR_END_GET(x)                     (((x) & MAC_QCU_MISC_1_TXE_CLR_ON_CBR_END_MASK) >> MAC_QCU_MISC_1_TXE_CLR_ON_CBR_END_LSB)
#define MAC_QCU_MISC_1_TXE_CLR_ON_CBR_END_SET(x)                     (((0 | (x)) << MAC_QCU_MISC_1_TXE_CLR_ON_CBR_END_LSB) & MAC_QCU_MISC_1_TXE_CLR_ON_CBR_END_MASK)
#define MAC_QCU_MISC_1_TXE_CLR_ON_CBR_END_RESET                      0
#define MAC_QCU_MISC_1_CBR_EXP_INC_LIMIT_MSB                         8
#define MAC_QCU_MISC_1_CBR_EXP_INC_LIMIT_LSB                         8
#define MAC_QCU_MISC_1_CBR_EXP_INC_LIMIT_MASK                        0x00000100
#define MAC_QCU_MISC_1_CBR_EXP_INC_LIMIT_GET(x)                      (((x) & MAC_QCU_MISC_1_CBR_EXP_INC_LIMIT_MASK) >> MAC_QCU_MISC_1_CBR_EXP_INC_LIMIT_LSB)
#define MAC_QCU_MISC_1_CBR_EXP_INC_LIMIT_SET(x)                      (((0 | (x)) << MAC_QCU_MISC_1_CBR_EXP_INC_LIMIT_LSB) & MAC_QCU_MISC_1_CBR_EXP_INC_LIMIT_MASK)
#define MAC_QCU_MISC_1_CBR_EXP_INC_LIMIT_RESET                       0
#define MAC_QCU_MISC_1_IS_BCN_MSB                                    7
#define MAC_QCU_MISC_1_IS_BCN_LSB                                    7
#define MAC_QCU_MISC_1_IS_BCN_MASK                                   0x00000080
#define MAC_QCU_MISC_1_IS_BCN_GET(x)                                 (((x) & MAC_QCU_MISC_1_IS_BCN_MASK) >> MAC_QCU_MISC_1_IS_BCN_LSB)
#define MAC_QCU_MISC_1_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_QCU_MISC_1_IS_BCN_LSB) & MAC_QCU_MISC_1_IS_BCN_MASK)
#define MAC_QCU_MISC_1_IS_BCN_RESET                                  0
#define MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOBCNFR_MSB                   6
#define MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOBCNFR_LSB                   6
#define MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOBCNFR_MASK                  0x00000040
#define MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOBCNFR_GET(x)                (((x) & MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOBCNFR_MASK) >> MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOBCNFR_LSB)
#define MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOBCNFR_SET(x)                (((0 | (x)) << MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOBCNFR_LSB) & MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOBCNFR_MASK)
#define MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOBCNFR_RESET                 0
#define MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOFR_MSB                      5
#define MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOFR_LSB                      5
#define MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOFR_MASK                     0x00000020
#define MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOFR_GET(x)                   (((x) & MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOFR_MASK) >> MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOFR_LSB)
#define MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOFR_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOFR_LSB) & MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOFR_MASK)
#define MAC_QCU_MISC_1_CBR_EXP_INC_DIS_NOFR_RESET                    0
#define MAC_QCU_MISC_1_ONESHOT_EN_MSB                                4
#define MAC_QCU_MISC_1_ONESHOT_EN_LSB                                4
#define MAC_QCU_MISC_1_ONESHOT_EN_MASK                               0x00000010
#define MAC_QCU_MISC_1_ONESHOT_EN_GET(x)                             (((x) & MAC_QCU_MISC_1_ONESHOT_EN_MASK) >> MAC_QCU_MISC_1_ONESHOT_EN_LSB)
#define MAC_QCU_MISC_1_ONESHOT_EN_SET(x)                             (((0 | (x)) << MAC_QCU_MISC_1_ONESHOT_EN_LSB) & MAC_QCU_MISC_1_ONESHOT_EN_MASK)
#define MAC_QCU_MISC_1_ONESHOT_EN_RESET                              0
#define MAC_QCU_MISC_1_FSP_MSB                                       3
#define MAC_QCU_MISC_1_FSP_LSB                                       0
#define MAC_QCU_MISC_1_FSP_MASK                                      0x0000000f
#define MAC_QCU_MISC_1_FSP_GET(x)                                    (((x) & MAC_QCU_MISC_1_FSP_MASK) >> MAC_QCU_MISC_1_FSP_LSB)
#define MAC_QCU_MISC_1_FSP_SET(x)                                    (((0 | (x)) << MAC_QCU_MISC_1_FSP_LSB) & MAC_QCU_MISC_1_FSP_MASK)
#define MAC_QCU_MISC_1_FSP_RESET                                     0
#define MAC_QCU_MISC_1_ADDRESS                                       0x09c4
#define MAC_QCU_MISC_1_HW_MASK                                       0x00001fff
#define MAC_QCU_MISC_1_SW_MASK                                       0x00001fff
#define MAC_QCU_MISC_1_HW_WRITE_MASK                                 0x00000400
#define MAC_QCU_MISC_1_SW_WRITE_MASK                                 0x00001fff
#define MAC_QCU_MISC_1_RSTMASK                                       0xffffffff
#define MAC_QCU_MISC_1_RESET                                         0x00000800

// 0x09c8 (MAC_QCU_MISC_2)
#define MAC_QCU_MISC_2_NON_ASAP_FRAME_BURST_MSB                      12
#define MAC_QCU_MISC_2_NON_ASAP_FRAME_BURST_LSB                      12
#define MAC_QCU_MISC_2_NON_ASAP_FRAME_BURST_MASK                     0x00001000
#define MAC_QCU_MISC_2_NON_ASAP_FRAME_BURST_GET(x)                   (((x) & MAC_QCU_MISC_2_NON_ASAP_FRAME_BURST_MASK) >> MAC_QCU_MISC_2_NON_ASAP_FRAME_BURST_LSB)
#define MAC_QCU_MISC_2_NON_ASAP_FRAME_BURST_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_2_NON_ASAP_FRAME_BURST_LSB) & MAC_QCU_MISC_2_NON_ASAP_FRAME_BURST_MASK)
#define MAC_QCU_MISC_2_NON_ASAP_FRAME_BURST_RESET                    0
#define MAC_QCU_MISC_2_FR_ABORT_REQ_EN_MSB                           11
#define MAC_QCU_MISC_2_FR_ABORT_REQ_EN_LSB                           11
#define MAC_QCU_MISC_2_FR_ABORT_REQ_EN_MASK                          0x00000800
#define MAC_QCU_MISC_2_FR_ABORT_REQ_EN_GET(x)                        (((x) & MAC_QCU_MISC_2_FR_ABORT_REQ_EN_MASK) >> MAC_QCU_MISC_2_FR_ABORT_REQ_EN_LSB)
#define MAC_QCU_MISC_2_FR_ABORT_REQ_EN_SET(x)                        (((0 | (x)) << MAC_QCU_MISC_2_FR_ABORT_REQ_EN_LSB) & MAC_QCU_MISC_2_FR_ABORT_REQ_EN_MASK)
#define MAC_QCU_MISC_2_FR_ABORT_REQ_EN_RESET                         1
#define MAC_QCU_MISC_2_MMR_CBR_EXP_CNT_CLR_EN_MSB                    10
#define MAC_QCU_MISC_2_MMR_CBR_EXP_CNT_CLR_EN_LSB                    10
#define MAC_QCU_MISC_2_MMR_CBR_EXP_CNT_CLR_EN_MASK                   0x00000400
#define MAC_QCU_MISC_2_MMR_CBR_EXP_CNT_CLR_EN_GET(x)                 (((x) & MAC_QCU_MISC_2_MMR_CBR_EXP_CNT_CLR_EN_MASK) >> MAC_QCU_MISC_2_MMR_CBR_EXP_CNT_CLR_EN_LSB)
#define MAC_QCU_MISC_2_MMR_CBR_EXP_CNT_CLR_EN_SET(x)                 (((0 | (x)) << MAC_QCU_MISC_2_MMR_CBR_EXP_CNT_CLR_EN_LSB) & MAC_QCU_MISC_2_MMR_CBR_EXP_CNT_CLR_EN_MASK)
#define MAC_QCU_MISC_2_MMR_CBR_EXP_CNT_CLR_EN_RESET                  0
#define MAC_QCU_MISC_2_TXE_CLR_ON_CBR_END_MSB                        9
#define MAC_QCU_MISC_2_TXE_CLR_ON_CBR_END_LSB                        9
#define MAC_QCU_MISC_2_TXE_CLR_ON_CBR_END_MASK                       0x00000200
#define MAC_QCU_MISC_2_TXE_CLR_ON_CBR_END_GET(x)                     (((x) & MAC_QCU_MISC_2_TXE_CLR_ON_CBR_END_MASK) >> MAC_QCU_MISC_2_TXE_CLR_ON_CBR_END_LSB)
#define MAC_QCU_MISC_2_TXE_CLR_ON_CBR_END_SET(x)                     (((0 | (x)) << MAC_QCU_MISC_2_TXE_CLR_ON_CBR_END_LSB) & MAC_QCU_MISC_2_TXE_CLR_ON_CBR_END_MASK)
#define MAC_QCU_MISC_2_TXE_CLR_ON_CBR_END_RESET                      0
#define MAC_QCU_MISC_2_CBR_EXP_INC_LIMIT_MSB                         8
#define MAC_QCU_MISC_2_CBR_EXP_INC_LIMIT_LSB                         8
#define MAC_QCU_MISC_2_CBR_EXP_INC_LIMIT_MASK                        0x00000100
#define MAC_QCU_MISC_2_CBR_EXP_INC_LIMIT_GET(x)                      (((x) & MAC_QCU_MISC_2_CBR_EXP_INC_LIMIT_MASK) >> MAC_QCU_MISC_2_CBR_EXP_INC_LIMIT_LSB)
#define MAC_QCU_MISC_2_CBR_EXP_INC_LIMIT_SET(x)                      (((0 | (x)) << MAC_QCU_MISC_2_CBR_EXP_INC_LIMIT_LSB) & MAC_QCU_MISC_2_CBR_EXP_INC_LIMIT_MASK)
#define MAC_QCU_MISC_2_CBR_EXP_INC_LIMIT_RESET                       0
#define MAC_QCU_MISC_2_IS_BCN_MSB                                    7
#define MAC_QCU_MISC_2_IS_BCN_LSB                                    7
#define MAC_QCU_MISC_2_IS_BCN_MASK                                   0x00000080
#define MAC_QCU_MISC_2_IS_BCN_GET(x)                                 (((x) & MAC_QCU_MISC_2_IS_BCN_MASK) >> MAC_QCU_MISC_2_IS_BCN_LSB)
#define MAC_QCU_MISC_2_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_QCU_MISC_2_IS_BCN_LSB) & MAC_QCU_MISC_2_IS_BCN_MASK)
#define MAC_QCU_MISC_2_IS_BCN_RESET                                  0
#define MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOBCNFR_MSB                   6
#define MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOBCNFR_LSB                   6
#define MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOBCNFR_MASK                  0x00000040
#define MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOBCNFR_GET(x)                (((x) & MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOBCNFR_MASK) >> MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOBCNFR_LSB)
#define MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOBCNFR_SET(x)                (((0 | (x)) << MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOBCNFR_LSB) & MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOBCNFR_MASK)
#define MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOBCNFR_RESET                 0
#define MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOFR_MSB                      5
#define MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOFR_LSB                      5
#define MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOFR_MASK                     0x00000020
#define MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOFR_GET(x)                   (((x) & MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOFR_MASK) >> MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOFR_LSB)
#define MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOFR_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOFR_LSB) & MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOFR_MASK)
#define MAC_QCU_MISC_2_CBR_EXP_INC_DIS_NOFR_RESET                    0
#define MAC_QCU_MISC_2_ONESHOT_EN_MSB                                4
#define MAC_QCU_MISC_2_ONESHOT_EN_LSB                                4
#define MAC_QCU_MISC_2_ONESHOT_EN_MASK                               0x00000010
#define MAC_QCU_MISC_2_ONESHOT_EN_GET(x)                             (((x) & MAC_QCU_MISC_2_ONESHOT_EN_MASK) >> MAC_QCU_MISC_2_ONESHOT_EN_LSB)
#define MAC_QCU_MISC_2_ONESHOT_EN_SET(x)                             (((0 | (x)) << MAC_QCU_MISC_2_ONESHOT_EN_LSB) & MAC_QCU_MISC_2_ONESHOT_EN_MASK)
#define MAC_QCU_MISC_2_ONESHOT_EN_RESET                              0
#define MAC_QCU_MISC_2_FSP_MSB                                       3
#define MAC_QCU_MISC_2_FSP_LSB                                       0
#define MAC_QCU_MISC_2_FSP_MASK                                      0x0000000f
#define MAC_QCU_MISC_2_FSP_GET(x)                                    (((x) & MAC_QCU_MISC_2_FSP_MASK) >> MAC_QCU_MISC_2_FSP_LSB)
#define MAC_QCU_MISC_2_FSP_SET(x)                                    (((0 | (x)) << MAC_QCU_MISC_2_FSP_LSB) & MAC_QCU_MISC_2_FSP_MASK)
#define MAC_QCU_MISC_2_FSP_RESET                                     0
#define MAC_QCU_MISC_2_ADDRESS                                       0x09c8
#define MAC_QCU_MISC_2_HW_MASK                                       0x00001fff
#define MAC_QCU_MISC_2_SW_MASK                                       0x00001fff
#define MAC_QCU_MISC_2_HW_WRITE_MASK                                 0x00000400
#define MAC_QCU_MISC_2_SW_WRITE_MASK                                 0x00001fff
#define MAC_QCU_MISC_2_RSTMASK                                       0xffffffff
#define MAC_QCU_MISC_2_RESET                                         0x00000800

// 0x09cc (MAC_QCU_MISC_3)
#define MAC_QCU_MISC_3_NON_ASAP_FRAME_BURST_MSB                      12
#define MAC_QCU_MISC_3_NON_ASAP_FRAME_BURST_LSB                      12
#define MAC_QCU_MISC_3_NON_ASAP_FRAME_BURST_MASK                     0x00001000
#define MAC_QCU_MISC_3_NON_ASAP_FRAME_BURST_GET(x)                   (((x) & MAC_QCU_MISC_3_NON_ASAP_FRAME_BURST_MASK) >> MAC_QCU_MISC_3_NON_ASAP_FRAME_BURST_LSB)
#define MAC_QCU_MISC_3_NON_ASAP_FRAME_BURST_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_3_NON_ASAP_FRAME_BURST_LSB) & MAC_QCU_MISC_3_NON_ASAP_FRAME_BURST_MASK)
#define MAC_QCU_MISC_3_NON_ASAP_FRAME_BURST_RESET                    0
#define MAC_QCU_MISC_3_FR_ABORT_REQ_EN_MSB                           11
#define MAC_QCU_MISC_3_FR_ABORT_REQ_EN_LSB                           11
#define MAC_QCU_MISC_3_FR_ABORT_REQ_EN_MASK                          0x00000800
#define MAC_QCU_MISC_3_FR_ABORT_REQ_EN_GET(x)                        (((x) & MAC_QCU_MISC_3_FR_ABORT_REQ_EN_MASK) >> MAC_QCU_MISC_3_FR_ABORT_REQ_EN_LSB)
#define MAC_QCU_MISC_3_FR_ABORT_REQ_EN_SET(x)                        (((0 | (x)) << MAC_QCU_MISC_3_FR_ABORT_REQ_EN_LSB) & MAC_QCU_MISC_3_FR_ABORT_REQ_EN_MASK)
#define MAC_QCU_MISC_3_FR_ABORT_REQ_EN_RESET                         1
#define MAC_QCU_MISC_3_MMR_CBR_EXP_CNT_CLR_EN_MSB                    10
#define MAC_QCU_MISC_3_MMR_CBR_EXP_CNT_CLR_EN_LSB                    10
#define MAC_QCU_MISC_3_MMR_CBR_EXP_CNT_CLR_EN_MASK                   0x00000400
#define MAC_QCU_MISC_3_MMR_CBR_EXP_CNT_CLR_EN_GET(x)                 (((x) & MAC_QCU_MISC_3_MMR_CBR_EXP_CNT_CLR_EN_MASK) >> MAC_QCU_MISC_3_MMR_CBR_EXP_CNT_CLR_EN_LSB)
#define MAC_QCU_MISC_3_MMR_CBR_EXP_CNT_CLR_EN_SET(x)                 (((0 | (x)) << MAC_QCU_MISC_3_MMR_CBR_EXP_CNT_CLR_EN_LSB) & MAC_QCU_MISC_3_MMR_CBR_EXP_CNT_CLR_EN_MASK)
#define MAC_QCU_MISC_3_MMR_CBR_EXP_CNT_CLR_EN_RESET                  0
#define MAC_QCU_MISC_3_TXE_CLR_ON_CBR_END_MSB                        9
#define MAC_QCU_MISC_3_TXE_CLR_ON_CBR_END_LSB                        9
#define MAC_QCU_MISC_3_TXE_CLR_ON_CBR_END_MASK                       0x00000200
#define MAC_QCU_MISC_3_TXE_CLR_ON_CBR_END_GET(x)                     (((x) & MAC_QCU_MISC_3_TXE_CLR_ON_CBR_END_MASK) >> MAC_QCU_MISC_3_TXE_CLR_ON_CBR_END_LSB)
#define MAC_QCU_MISC_3_TXE_CLR_ON_CBR_END_SET(x)                     (((0 | (x)) << MAC_QCU_MISC_3_TXE_CLR_ON_CBR_END_LSB) & MAC_QCU_MISC_3_TXE_CLR_ON_CBR_END_MASK)
#define MAC_QCU_MISC_3_TXE_CLR_ON_CBR_END_RESET                      0
#define MAC_QCU_MISC_3_CBR_EXP_INC_LIMIT_MSB                         8
#define MAC_QCU_MISC_3_CBR_EXP_INC_LIMIT_LSB                         8
#define MAC_QCU_MISC_3_CBR_EXP_INC_LIMIT_MASK                        0x00000100
#define MAC_QCU_MISC_3_CBR_EXP_INC_LIMIT_GET(x)                      (((x) & MAC_QCU_MISC_3_CBR_EXP_INC_LIMIT_MASK) >> MAC_QCU_MISC_3_CBR_EXP_INC_LIMIT_LSB)
#define MAC_QCU_MISC_3_CBR_EXP_INC_LIMIT_SET(x)                      (((0 | (x)) << MAC_QCU_MISC_3_CBR_EXP_INC_LIMIT_LSB) & MAC_QCU_MISC_3_CBR_EXP_INC_LIMIT_MASK)
#define MAC_QCU_MISC_3_CBR_EXP_INC_LIMIT_RESET                       0
#define MAC_QCU_MISC_3_IS_BCN_MSB                                    7
#define MAC_QCU_MISC_3_IS_BCN_LSB                                    7
#define MAC_QCU_MISC_3_IS_BCN_MASK                                   0x00000080
#define MAC_QCU_MISC_3_IS_BCN_GET(x)                                 (((x) & MAC_QCU_MISC_3_IS_BCN_MASK) >> MAC_QCU_MISC_3_IS_BCN_LSB)
#define MAC_QCU_MISC_3_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_QCU_MISC_3_IS_BCN_LSB) & MAC_QCU_MISC_3_IS_BCN_MASK)
#define MAC_QCU_MISC_3_IS_BCN_RESET                                  0
#define MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOBCNFR_MSB                   6
#define MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOBCNFR_LSB                   6
#define MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOBCNFR_MASK                  0x00000040
#define MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOBCNFR_GET(x)                (((x) & MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOBCNFR_MASK) >> MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOBCNFR_LSB)
#define MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOBCNFR_SET(x)                (((0 | (x)) << MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOBCNFR_LSB) & MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOBCNFR_MASK)
#define MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOBCNFR_RESET                 0
#define MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOFR_MSB                      5
#define MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOFR_LSB                      5
#define MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOFR_MASK                     0x00000020
#define MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOFR_GET(x)                   (((x) & MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOFR_MASK) >> MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOFR_LSB)
#define MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOFR_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOFR_LSB) & MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOFR_MASK)
#define MAC_QCU_MISC_3_CBR_EXP_INC_DIS_NOFR_RESET                    0
#define MAC_QCU_MISC_3_ONESHOT_EN_MSB                                4
#define MAC_QCU_MISC_3_ONESHOT_EN_LSB                                4
#define MAC_QCU_MISC_3_ONESHOT_EN_MASK                               0x00000010
#define MAC_QCU_MISC_3_ONESHOT_EN_GET(x)                             (((x) & MAC_QCU_MISC_3_ONESHOT_EN_MASK) >> MAC_QCU_MISC_3_ONESHOT_EN_LSB)
#define MAC_QCU_MISC_3_ONESHOT_EN_SET(x)                             (((0 | (x)) << MAC_QCU_MISC_3_ONESHOT_EN_LSB) & MAC_QCU_MISC_3_ONESHOT_EN_MASK)
#define MAC_QCU_MISC_3_ONESHOT_EN_RESET                              0
#define MAC_QCU_MISC_3_FSP_MSB                                       3
#define MAC_QCU_MISC_3_FSP_LSB                                       0
#define MAC_QCU_MISC_3_FSP_MASK                                      0x0000000f
#define MAC_QCU_MISC_3_FSP_GET(x)                                    (((x) & MAC_QCU_MISC_3_FSP_MASK) >> MAC_QCU_MISC_3_FSP_LSB)
#define MAC_QCU_MISC_3_FSP_SET(x)                                    (((0 | (x)) << MAC_QCU_MISC_3_FSP_LSB) & MAC_QCU_MISC_3_FSP_MASK)
#define MAC_QCU_MISC_3_FSP_RESET                                     0
#define MAC_QCU_MISC_3_ADDRESS                                       0x09cc
#define MAC_QCU_MISC_3_HW_MASK                                       0x00001fff
#define MAC_QCU_MISC_3_SW_MASK                                       0x00001fff
#define MAC_QCU_MISC_3_HW_WRITE_MASK                                 0x00000400
#define MAC_QCU_MISC_3_SW_WRITE_MASK                                 0x00001fff
#define MAC_QCU_MISC_3_RSTMASK                                       0xffffffff
#define MAC_QCU_MISC_3_RESET                                         0x00000800

// 0x09d0 (MAC_QCU_MISC_4)
#define MAC_QCU_MISC_4_NON_ASAP_FRAME_BURST_MSB                      12
#define MAC_QCU_MISC_4_NON_ASAP_FRAME_BURST_LSB                      12
#define MAC_QCU_MISC_4_NON_ASAP_FRAME_BURST_MASK                     0x00001000
#define MAC_QCU_MISC_4_NON_ASAP_FRAME_BURST_GET(x)                   (((x) & MAC_QCU_MISC_4_NON_ASAP_FRAME_BURST_MASK) >> MAC_QCU_MISC_4_NON_ASAP_FRAME_BURST_LSB)
#define MAC_QCU_MISC_4_NON_ASAP_FRAME_BURST_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_4_NON_ASAP_FRAME_BURST_LSB) & MAC_QCU_MISC_4_NON_ASAP_FRAME_BURST_MASK)
#define MAC_QCU_MISC_4_NON_ASAP_FRAME_BURST_RESET                    0
#define MAC_QCU_MISC_4_FR_ABORT_REQ_EN_MSB                           11
#define MAC_QCU_MISC_4_FR_ABORT_REQ_EN_LSB                           11
#define MAC_QCU_MISC_4_FR_ABORT_REQ_EN_MASK                          0x00000800
#define MAC_QCU_MISC_4_FR_ABORT_REQ_EN_GET(x)                        (((x) & MAC_QCU_MISC_4_FR_ABORT_REQ_EN_MASK) >> MAC_QCU_MISC_4_FR_ABORT_REQ_EN_LSB)
#define MAC_QCU_MISC_4_FR_ABORT_REQ_EN_SET(x)                        (((0 | (x)) << MAC_QCU_MISC_4_FR_ABORT_REQ_EN_LSB) & MAC_QCU_MISC_4_FR_ABORT_REQ_EN_MASK)
#define MAC_QCU_MISC_4_FR_ABORT_REQ_EN_RESET                         1
#define MAC_QCU_MISC_4_MMR_CBR_EXP_CNT_CLR_EN_MSB                    10
#define MAC_QCU_MISC_4_MMR_CBR_EXP_CNT_CLR_EN_LSB                    10
#define MAC_QCU_MISC_4_MMR_CBR_EXP_CNT_CLR_EN_MASK                   0x00000400
#define MAC_QCU_MISC_4_MMR_CBR_EXP_CNT_CLR_EN_GET(x)                 (((x) & MAC_QCU_MISC_4_MMR_CBR_EXP_CNT_CLR_EN_MASK) >> MAC_QCU_MISC_4_MMR_CBR_EXP_CNT_CLR_EN_LSB)
#define MAC_QCU_MISC_4_MMR_CBR_EXP_CNT_CLR_EN_SET(x)                 (((0 | (x)) << MAC_QCU_MISC_4_MMR_CBR_EXP_CNT_CLR_EN_LSB) & MAC_QCU_MISC_4_MMR_CBR_EXP_CNT_CLR_EN_MASK)
#define MAC_QCU_MISC_4_MMR_CBR_EXP_CNT_CLR_EN_RESET                  0
#define MAC_QCU_MISC_4_TXE_CLR_ON_CBR_END_MSB                        9
#define MAC_QCU_MISC_4_TXE_CLR_ON_CBR_END_LSB                        9
#define MAC_QCU_MISC_4_TXE_CLR_ON_CBR_END_MASK                       0x00000200
#define MAC_QCU_MISC_4_TXE_CLR_ON_CBR_END_GET(x)                     (((x) & MAC_QCU_MISC_4_TXE_CLR_ON_CBR_END_MASK) >> MAC_QCU_MISC_4_TXE_CLR_ON_CBR_END_LSB)
#define MAC_QCU_MISC_4_TXE_CLR_ON_CBR_END_SET(x)                     (((0 | (x)) << MAC_QCU_MISC_4_TXE_CLR_ON_CBR_END_LSB) & MAC_QCU_MISC_4_TXE_CLR_ON_CBR_END_MASK)
#define MAC_QCU_MISC_4_TXE_CLR_ON_CBR_END_RESET                      0
#define MAC_QCU_MISC_4_CBR_EXP_INC_LIMIT_MSB                         8
#define MAC_QCU_MISC_4_CBR_EXP_INC_LIMIT_LSB                         8
#define MAC_QCU_MISC_4_CBR_EXP_INC_LIMIT_MASK                        0x00000100
#define MAC_QCU_MISC_4_CBR_EXP_INC_LIMIT_GET(x)                      (((x) & MAC_QCU_MISC_4_CBR_EXP_INC_LIMIT_MASK) >> MAC_QCU_MISC_4_CBR_EXP_INC_LIMIT_LSB)
#define MAC_QCU_MISC_4_CBR_EXP_INC_LIMIT_SET(x)                      (((0 | (x)) << MAC_QCU_MISC_4_CBR_EXP_INC_LIMIT_LSB) & MAC_QCU_MISC_4_CBR_EXP_INC_LIMIT_MASK)
#define MAC_QCU_MISC_4_CBR_EXP_INC_LIMIT_RESET                       0
#define MAC_QCU_MISC_4_IS_BCN_MSB                                    7
#define MAC_QCU_MISC_4_IS_BCN_LSB                                    7
#define MAC_QCU_MISC_4_IS_BCN_MASK                                   0x00000080
#define MAC_QCU_MISC_4_IS_BCN_GET(x)                                 (((x) & MAC_QCU_MISC_4_IS_BCN_MASK) >> MAC_QCU_MISC_4_IS_BCN_LSB)
#define MAC_QCU_MISC_4_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_QCU_MISC_4_IS_BCN_LSB) & MAC_QCU_MISC_4_IS_BCN_MASK)
#define MAC_QCU_MISC_4_IS_BCN_RESET                                  0
#define MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOBCNFR_MSB                   6
#define MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOBCNFR_LSB                   6
#define MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOBCNFR_MASK                  0x00000040
#define MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOBCNFR_GET(x)                (((x) & MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOBCNFR_MASK) >> MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOBCNFR_LSB)
#define MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOBCNFR_SET(x)                (((0 | (x)) << MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOBCNFR_LSB) & MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOBCNFR_MASK)
#define MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOBCNFR_RESET                 0
#define MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOFR_MSB                      5
#define MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOFR_LSB                      5
#define MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOFR_MASK                     0x00000020
#define MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOFR_GET(x)                   (((x) & MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOFR_MASK) >> MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOFR_LSB)
#define MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOFR_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOFR_LSB) & MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOFR_MASK)
#define MAC_QCU_MISC_4_CBR_EXP_INC_DIS_NOFR_RESET                    0
#define MAC_QCU_MISC_4_ONESHOT_EN_MSB                                4
#define MAC_QCU_MISC_4_ONESHOT_EN_LSB                                4
#define MAC_QCU_MISC_4_ONESHOT_EN_MASK                               0x00000010
#define MAC_QCU_MISC_4_ONESHOT_EN_GET(x)                             (((x) & MAC_QCU_MISC_4_ONESHOT_EN_MASK) >> MAC_QCU_MISC_4_ONESHOT_EN_LSB)
#define MAC_QCU_MISC_4_ONESHOT_EN_SET(x)                             (((0 | (x)) << MAC_QCU_MISC_4_ONESHOT_EN_LSB) & MAC_QCU_MISC_4_ONESHOT_EN_MASK)
#define MAC_QCU_MISC_4_ONESHOT_EN_RESET                              0
#define MAC_QCU_MISC_4_FSP_MSB                                       3
#define MAC_QCU_MISC_4_FSP_LSB                                       0
#define MAC_QCU_MISC_4_FSP_MASK                                      0x0000000f
#define MAC_QCU_MISC_4_FSP_GET(x)                                    (((x) & MAC_QCU_MISC_4_FSP_MASK) >> MAC_QCU_MISC_4_FSP_LSB)
#define MAC_QCU_MISC_4_FSP_SET(x)                                    (((0 | (x)) << MAC_QCU_MISC_4_FSP_LSB) & MAC_QCU_MISC_4_FSP_MASK)
#define MAC_QCU_MISC_4_FSP_RESET                                     0
#define MAC_QCU_MISC_4_ADDRESS                                       0x09d0
#define MAC_QCU_MISC_4_HW_MASK                                       0x00001fff
#define MAC_QCU_MISC_4_SW_MASK                                       0x00001fff
#define MAC_QCU_MISC_4_HW_WRITE_MASK                                 0x00000400
#define MAC_QCU_MISC_4_SW_WRITE_MASK                                 0x00001fff
#define MAC_QCU_MISC_4_RSTMASK                                       0xffffffff
#define MAC_QCU_MISC_4_RESET                                         0x00000800

// 0x09d4 (MAC_QCU_MISC_5)
#define MAC_QCU_MISC_5_NON_ASAP_FRAME_BURST_MSB                      12
#define MAC_QCU_MISC_5_NON_ASAP_FRAME_BURST_LSB                      12
#define MAC_QCU_MISC_5_NON_ASAP_FRAME_BURST_MASK                     0x00001000
#define MAC_QCU_MISC_5_NON_ASAP_FRAME_BURST_GET(x)                   (((x) & MAC_QCU_MISC_5_NON_ASAP_FRAME_BURST_MASK) >> MAC_QCU_MISC_5_NON_ASAP_FRAME_BURST_LSB)
#define MAC_QCU_MISC_5_NON_ASAP_FRAME_BURST_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_5_NON_ASAP_FRAME_BURST_LSB) & MAC_QCU_MISC_5_NON_ASAP_FRAME_BURST_MASK)
#define MAC_QCU_MISC_5_NON_ASAP_FRAME_BURST_RESET                    0
#define MAC_QCU_MISC_5_FR_ABORT_REQ_EN_MSB                           11
#define MAC_QCU_MISC_5_FR_ABORT_REQ_EN_LSB                           11
#define MAC_QCU_MISC_5_FR_ABORT_REQ_EN_MASK                          0x00000800
#define MAC_QCU_MISC_5_FR_ABORT_REQ_EN_GET(x)                        (((x) & MAC_QCU_MISC_5_FR_ABORT_REQ_EN_MASK) >> MAC_QCU_MISC_5_FR_ABORT_REQ_EN_LSB)
#define MAC_QCU_MISC_5_FR_ABORT_REQ_EN_SET(x)                        (((0 | (x)) << MAC_QCU_MISC_5_FR_ABORT_REQ_EN_LSB) & MAC_QCU_MISC_5_FR_ABORT_REQ_EN_MASK)
#define MAC_QCU_MISC_5_FR_ABORT_REQ_EN_RESET                         1
#define MAC_QCU_MISC_5_MMR_CBR_EXP_CNT_CLR_EN_MSB                    10
#define MAC_QCU_MISC_5_MMR_CBR_EXP_CNT_CLR_EN_LSB                    10
#define MAC_QCU_MISC_5_MMR_CBR_EXP_CNT_CLR_EN_MASK                   0x00000400
#define MAC_QCU_MISC_5_MMR_CBR_EXP_CNT_CLR_EN_GET(x)                 (((x) & MAC_QCU_MISC_5_MMR_CBR_EXP_CNT_CLR_EN_MASK) >> MAC_QCU_MISC_5_MMR_CBR_EXP_CNT_CLR_EN_LSB)
#define MAC_QCU_MISC_5_MMR_CBR_EXP_CNT_CLR_EN_SET(x)                 (((0 | (x)) << MAC_QCU_MISC_5_MMR_CBR_EXP_CNT_CLR_EN_LSB) & MAC_QCU_MISC_5_MMR_CBR_EXP_CNT_CLR_EN_MASK)
#define MAC_QCU_MISC_5_MMR_CBR_EXP_CNT_CLR_EN_RESET                  0
#define MAC_QCU_MISC_5_TXE_CLR_ON_CBR_END_MSB                        9
#define MAC_QCU_MISC_5_TXE_CLR_ON_CBR_END_LSB                        9
#define MAC_QCU_MISC_5_TXE_CLR_ON_CBR_END_MASK                       0x00000200
#define MAC_QCU_MISC_5_TXE_CLR_ON_CBR_END_GET(x)                     (((x) & MAC_QCU_MISC_5_TXE_CLR_ON_CBR_END_MASK) >> MAC_QCU_MISC_5_TXE_CLR_ON_CBR_END_LSB)
#define MAC_QCU_MISC_5_TXE_CLR_ON_CBR_END_SET(x)                     (((0 | (x)) << MAC_QCU_MISC_5_TXE_CLR_ON_CBR_END_LSB) & MAC_QCU_MISC_5_TXE_CLR_ON_CBR_END_MASK)
#define MAC_QCU_MISC_5_TXE_CLR_ON_CBR_END_RESET                      0
#define MAC_QCU_MISC_5_CBR_EXP_INC_LIMIT_MSB                         8
#define MAC_QCU_MISC_5_CBR_EXP_INC_LIMIT_LSB                         8
#define MAC_QCU_MISC_5_CBR_EXP_INC_LIMIT_MASK                        0x00000100
#define MAC_QCU_MISC_5_CBR_EXP_INC_LIMIT_GET(x)                      (((x) & MAC_QCU_MISC_5_CBR_EXP_INC_LIMIT_MASK) >> MAC_QCU_MISC_5_CBR_EXP_INC_LIMIT_LSB)
#define MAC_QCU_MISC_5_CBR_EXP_INC_LIMIT_SET(x)                      (((0 | (x)) << MAC_QCU_MISC_5_CBR_EXP_INC_LIMIT_LSB) & MAC_QCU_MISC_5_CBR_EXP_INC_LIMIT_MASK)
#define MAC_QCU_MISC_5_CBR_EXP_INC_LIMIT_RESET                       0
#define MAC_QCU_MISC_5_IS_BCN_MSB                                    7
#define MAC_QCU_MISC_5_IS_BCN_LSB                                    7
#define MAC_QCU_MISC_5_IS_BCN_MASK                                   0x00000080
#define MAC_QCU_MISC_5_IS_BCN_GET(x)                                 (((x) & MAC_QCU_MISC_5_IS_BCN_MASK) >> MAC_QCU_MISC_5_IS_BCN_LSB)
#define MAC_QCU_MISC_5_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_QCU_MISC_5_IS_BCN_LSB) & MAC_QCU_MISC_5_IS_BCN_MASK)
#define MAC_QCU_MISC_5_IS_BCN_RESET                                  0
#define MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOBCNFR_MSB                   6
#define MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOBCNFR_LSB                   6
#define MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOBCNFR_MASK                  0x00000040
#define MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOBCNFR_GET(x)                (((x) & MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOBCNFR_MASK) >> MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOBCNFR_LSB)
#define MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOBCNFR_SET(x)                (((0 | (x)) << MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOBCNFR_LSB) & MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOBCNFR_MASK)
#define MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOBCNFR_RESET                 0
#define MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOFR_MSB                      5
#define MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOFR_LSB                      5
#define MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOFR_MASK                     0x00000020
#define MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOFR_GET(x)                   (((x) & MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOFR_MASK) >> MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOFR_LSB)
#define MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOFR_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOFR_LSB) & MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOFR_MASK)
#define MAC_QCU_MISC_5_CBR_EXP_INC_DIS_NOFR_RESET                    0
#define MAC_QCU_MISC_5_ONESHOT_EN_MSB                                4
#define MAC_QCU_MISC_5_ONESHOT_EN_LSB                                4
#define MAC_QCU_MISC_5_ONESHOT_EN_MASK                               0x00000010
#define MAC_QCU_MISC_5_ONESHOT_EN_GET(x)                             (((x) & MAC_QCU_MISC_5_ONESHOT_EN_MASK) >> MAC_QCU_MISC_5_ONESHOT_EN_LSB)
#define MAC_QCU_MISC_5_ONESHOT_EN_SET(x)                             (((0 | (x)) << MAC_QCU_MISC_5_ONESHOT_EN_LSB) & MAC_QCU_MISC_5_ONESHOT_EN_MASK)
#define MAC_QCU_MISC_5_ONESHOT_EN_RESET                              0
#define MAC_QCU_MISC_5_FSP_MSB                                       3
#define MAC_QCU_MISC_5_FSP_LSB                                       0
#define MAC_QCU_MISC_5_FSP_MASK                                      0x0000000f
#define MAC_QCU_MISC_5_FSP_GET(x)                                    (((x) & MAC_QCU_MISC_5_FSP_MASK) >> MAC_QCU_MISC_5_FSP_LSB)
#define MAC_QCU_MISC_5_FSP_SET(x)                                    (((0 | (x)) << MAC_QCU_MISC_5_FSP_LSB) & MAC_QCU_MISC_5_FSP_MASK)
#define MAC_QCU_MISC_5_FSP_RESET                                     0
#define MAC_QCU_MISC_5_ADDRESS                                       0x09d4
#define MAC_QCU_MISC_5_HW_MASK                                       0x00001fff
#define MAC_QCU_MISC_5_SW_MASK                                       0x00001fff
#define MAC_QCU_MISC_5_HW_WRITE_MASK                                 0x00000400
#define MAC_QCU_MISC_5_SW_WRITE_MASK                                 0x00001fff
#define MAC_QCU_MISC_5_RSTMASK                                       0xffffffff
#define MAC_QCU_MISC_5_RESET                                         0x00000800

// 0x09d8 (MAC_QCU_MISC_6)
#define MAC_QCU_MISC_6_NON_ASAP_FRAME_BURST_MSB                      12
#define MAC_QCU_MISC_6_NON_ASAP_FRAME_BURST_LSB                      12
#define MAC_QCU_MISC_6_NON_ASAP_FRAME_BURST_MASK                     0x00001000
#define MAC_QCU_MISC_6_NON_ASAP_FRAME_BURST_GET(x)                   (((x) & MAC_QCU_MISC_6_NON_ASAP_FRAME_BURST_MASK) >> MAC_QCU_MISC_6_NON_ASAP_FRAME_BURST_LSB)
#define MAC_QCU_MISC_6_NON_ASAP_FRAME_BURST_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_6_NON_ASAP_FRAME_BURST_LSB) & MAC_QCU_MISC_6_NON_ASAP_FRAME_BURST_MASK)
#define MAC_QCU_MISC_6_NON_ASAP_FRAME_BURST_RESET                    0
#define MAC_QCU_MISC_6_FR_ABORT_REQ_EN_MSB                           11
#define MAC_QCU_MISC_6_FR_ABORT_REQ_EN_LSB                           11
#define MAC_QCU_MISC_6_FR_ABORT_REQ_EN_MASK                          0x00000800
#define MAC_QCU_MISC_6_FR_ABORT_REQ_EN_GET(x)                        (((x) & MAC_QCU_MISC_6_FR_ABORT_REQ_EN_MASK) >> MAC_QCU_MISC_6_FR_ABORT_REQ_EN_LSB)
#define MAC_QCU_MISC_6_FR_ABORT_REQ_EN_SET(x)                        (((0 | (x)) << MAC_QCU_MISC_6_FR_ABORT_REQ_EN_LSB) & MAC_QCU_MISC_6_FR_ABORT_REQ_EN_MASK)
#define MAC_QCU_MISC_6_FR_ABORT_REQ_EN_RESET                         1
#define MAC_QCU_MISC_6_MMR_CBR_EXP_CNT_CLR_EN_MSB                    10
#define MAC_QCU_MISC_6_MMR_CBR_EXP_CNT_CLR_EN_LSB                    10
#define MAC_QCU_MISC_6_MMR_CBR_EXP_CNT_CLR_EN_MASK                   0x00000400
#define MAC_QCU_MISC_6_MMR_CBR_EXP_CNT_CLR_EN_GET(x)                 (((x) & MAC_QCU_MISC_6_MMR_CBR_EXP_CNT_CLR_EN_MASK) >> MAC_QCU_MISC_6_MMR_CBR_EXP_CNT_CLR_EN_LSB)
#define MAC_QCU_MISC_6_MMR_CBR_EXP_CNT_CLR_EN_SET(x)                 (((0 | (x)) << MAC_QCU_MISC_6_MMR_CBR_EXP_CNT_CLR_EN_LSB) & MAC_QCU_MISC_6_MMR_CBR_EXP_CNT_CLR_EN_MASK)
#define MAC_QCU_MISC_6_MMR_CBR_EXP_CNT_CLR_EN_RESET                  0
#define MAC_QCU_MISC_6_TXE_CLR_ON_CBR_END_MSB                        9
#define MAC_QCU_MISC_6_TXE_CLR_ON_CBR_END_LSB                        9
#define MAC_QCU_MISC_6_TXE_CLR_ON_CBR_END_MASK                       0x00000200
#define MAC_QCU_MISC_6_TXE_CLR_ON_CBR_END_GET(x)                     (((x) & MAC_QCU_MISC_6_TXE_CLR_ON_CBR_END_MASK) >> MAC_QCU_MISC_6_TXE_CLR_ON_CBR_END_LSB)
#define MAC_QCU_MISC_6_TXE_CLR_ON_CBR_END_SET(x)                     (((0 | (x)) << MAC_QCU_MISC_6_TXE_CLR_ON_CBR_END_LSB) & MAC_QCU_MISC_6_TXE_CLR_ON_CBR_END_MASK)
#define MAC_QCU_MISC_6_TXE_CLR_ON_CBR_END_RESET                      0
#define MAC_QCU_MISC_6_CBR_EXP_INC_LIMIT_MSB                         8
#define MAC_QCU_MISC_6_CBR_EXP_INC_LIMIT_LSB                         8
#define MAC_QCU_MISC_6_CBR_EXP_INC_LIMIT_MASK                        0x00000100
#define MAC_QCU_MISC_6_CBR_EXP_INC_LIMIT_GET(x)                      (((x) & MAC_QCU_MISC_6_CBR_EXP_INC_LIMIT_MASK) >> MAC_QCU_MISC_6_CBR_EXP_INC_LIMIT_LSB)
#define MAC_QCU_MISC_6_CBR_EXP_INC_LIMIT_SET(x)                      (((0 | (x)) << MAC_QCU_MISC_6_CBR_EXP_INC_LIMIT_LSB) & MAC_QCU_MISC_6_CBR_EXP_INC_LIMIT_MASK)
#define MAC_QCU_MISC_6_CBR_EXP_INC_LIMIT_RESET                       0
#define MAC_QCU_MISC_6_IS_BCN_MSB                                    7
#define MAC_QCU_MISC_6_IS_BCN_LSB                                    7
#define MAC_QCU_MISC_6_IS_BCN_MASK                                   0x00000080
#define MAC_QCU_MISC_6_IS_BCN_GET(x)                                 (((x) & MAC_QCU_MISC_6_IS_BCN_MASK) >> MAC_QCU_MISC_6_IS_BCN_LSB)
#define MAC_QCU_MISC_6_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_QCU_MISC_6_IS_BCN_LSB) & MAC_QCU_MISC_6_IS_BCN_MASK)
#define MAC_QCU_MISC_6_IS_BCN_RESET                                  0
#define MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOBCNFR_MSB                   6
#define MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOBCNFR_LSB                   6
#define MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOBCNFR_MASK                  0x00000040
#define MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOBCNFR_GET(x)                (((x) & MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOBCNFR_MASK) >> MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOBCNFR_LSB)
#define MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOBCNFR_SET(x)                (((0 | (x)) << MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOBCNFR_LSB) & MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOBCNFR_MASK)
#define MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOBCNFR_RESET                 0
#define MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOFR_MSB                      5
#define MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOFR_LSB                      5
#define MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOFR_MASK                     0x00000020
#define MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOFR_GET(x)                   (((x) & MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOFR_MASK) >> MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOFR_LSB)
#define MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOFR_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOFR_LSB) & MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOFR_MASK)
#define MAC_QCU_MISC_6_CBR_EXP_INC_DIS_NOFR_RESET                    0
#define MAC_QCU_MISC_6_ONESHOT_EN_MSB                                4
#define MAC_QCU_MISC_6_ONESHOT_EN_LSB                                4
#define MAC_QCU_MISC_6_ONESHOT_EN_MASK                               0x00000010
#define MAC_QCU_MISC_6_ONESHOT_EN_GET(x)                             (((x) & MAC_QCU_MISC_6_ONESHOT_EN_MASK) >> MAC_QCU_MISC_6_ONESHOT_EN_LSB)
#define MAC_QCU_MISC_6_ONESHOT_EN_SET(x)                             (((0 | (x)) << MAC_QCU_MISC_6_ONESHOT_EN_LSB) & MAC_QCU_MISC_6_ONESHOT_EN_MASK)
#define MAC_QCU_MISC_6_ONESHOT_EN_RESET                              0
#define MAC_QCU_MISC_6_FSP_MSB                                       3
#define MAC_QCU_MISC_6_FSP_LSB                                       0
#define MAC_QCU_MISC_6_FSP_MASK                                      0x0000000f
#define MAC_QCU_MISC_6_FSP_GET(x)                                    (((x) & MAC_QCU_MISC_6_FSP_MASK) >> MAC_QCU_MISC_6_FSP_LSB)
#define MAC_QCU_MISC_6_FSP_SET(x)                                    (((0 | (x)) << MAC_QCU_MISC_6_FSP_LSB) & MAC_QCU_MISC_6_FSP_MASK)
#define MAC_QCU_MISC_6_FSP_RESET                                     0
#define MAC_QCU_MISC_6_ADDRESS                                       0x09d8
#define MAC_QCU_MISC_6_HW_MASK                                       0x00001fff
#define MAC_QCU_MISC_6_SW_MASK                                       0x00001fff
#define MAC_QCU_MISC_6_HW_WRITE_MASK                                 0x00000400
#define MAC_QCU_MISC_6_SW_WRITE_MASK                                 0x00001fff
#define MAC_QCU_MISC_6_RSTMASK                                       0xffffffff
#define MAC_QCU_MISC_6_RESET                                         0x00000800

// 0x09dc (MAC_QCU_MISC_7)
#define MAC_QCU_MISC_7_NON_ASAP_FRAME_BURST_MSB                      12
#define MAC_QCU_MISC_7_NON_ASAP_FRAME_BURST_LSB                      12
#define MAC_QCU_MISC_7_NON_ASAP_FRAME_BURST_MASK                     0x00001000
#define MAC_QCU_MISC_7_NON_ASAP_FRAME_BURST_GET(x)                   (((x) & MAC_QCU_MISC_7_NON_ASAP_FRAME_BURST_MASK) >> MAC_QCU_MISC_7_NON_ASAP_FRAME_BURST_LSB)
#define MAC_QCU_MISC_7_NON_ASAP_FRAME_BURST_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_7_NON_ASAP_FRAME_BURST_LSB) & MAC_QCU_MISC_7_NON_ASAP_FRAME_BURST_MASK)
#define MAC_QCU_MISC_7_NON_ASAP_FRAME_BURST_RESET                    0
#define MAC_QCU_MISC_7_FR_ABORT_REQ_EN_MSB                           11
#define MAC_QCU_MISC_7_FR_ABORT_REQ_EN_LSB                           11
#define MAC_QCU_MISC_7_FR_ABORT_REQ_EN_MASK                          0x00000800
#define MAC_QCU_MISC_7_FR_ABORT_REQ_EN_GET(x)                        (((x) & MAC_QCU_MISC_7_FR_ABORT_REQ_EN_MASK) >> MAC_QCU_MISC_7_FR_ABORT_REQ_EN_LSB)
#define MAC_QCU_MISC_7_FR_ABORT_REQ_EN_SET(x)                        (((0 | (x)) << MAC_QCU_MISC_7_FR_ABORT_REQ_EN_LSB) & MAC_QCU_MISC_7_FR_ABORT_REQ_EN_MASK)
#define MAC_QCU_MISC_7_FR_ABORT_REQ_EN_RESET                         1
#define MAC_QCU_MISC_7_MMR_CBR_EXP_CNT_CLR_EN_MSB                    10
#define MAC_QCU_MISC_7_MMR_CBR_EXP_CNT_CLR_EN_LSB                    10
#define MAC_QCU_MISC_7_MMR_CBR_EXP_CNT_CLR_EN_MASK                   0x00000400
#define MAC_QCU_MISC_7_MMR_CBR_EXP_CNT_CLR_EN_GET(x)                 (((x) & MAC_QCU_MISC_7_MMR_CBR_EXP_CNT_CLR_EN_MASK) >> MAC_QCU_MISC_7_MMR_CBR_EXP_CNT_CLR_EN_LSB)
#define MAC_QCU_MISC_7_MMR_CBR_EXP_CNT_CLR_EN_SET(x)                 (((0 | (x)) << MAC_QCU_MISC_7_MMR_CBR_EXP_CNT_CLR_EN_LSB) & MAC_QCU_MISC_7_MMR_CBR_EXP_CNT_CLR_EN_MASK)
#define MAC_QCU_MISC_7_MMR_CBR_EXP_CNT_CLR_EN_RESET                  0
#define MAC_QCU_MISC_7_TXE_CLR_ON_CBR_END_MSB                        9
#define MAC_QCU_MISC_7_TXE_CLR_ON_CBR_END_LSB                        9
#define MAC_QCU_MISC_7_TXE_CLR_ON_CBR_END_MASK                       0x00000200
#define MAC_QCU_MISC_7_TXE_CLR_ON_CBR_END_GET(x)                     (((x) & MAC_QCU_MISC_7_TXE_CLR_ON_CBR_END_MASK) >> MAC_QCU_MISC_7_TXE_CLR_ON_CBR_END_LSB)
#define MAC_QCU_MISC_7_TXE_CLR_ON_CBR_END_SET(x)                     (((0 | (x)) << MAC_QCU_MISC_7_TXE_CLR_ON_CBR_END_LSB) & MAC_QCU_MISC_7_TXE_CLR_ON_CBR_END_MASK)
#define MAC_QCU_MISC_7_TXE_CLR_ON_CBR_END_RESET                      0
#define MAC_QCU_MISC_7_CBR_EXP_INC_LIMIT_MSB                         8
#define MAC_QCU_MISC_7_CBR_EXP_INC_LIMIT_LSB                         8
#define MAC_QCU_MISC_7_CBR_EXP_INC_LIMIT_MASK                        0x00000100
#define MAC_QCU_MISC_7_CBR_EXP_INC_LIMIT_GET(x)                      (((x) & MAC_QCU_MISC_7_CBR_EXP_INC_LIMIT_MASK) >> MAC_QCU_MISC_7_CBR_EXP_INC_LIMIT_LSB)
#define MAC_QCU_MISC_7_CBR_EXP_INC_LIMIT_SET(x)                      (((0 | (x)) << MAC_QCU_MISC_7_CBR_EXP_INC_LIMIT_LSB) & MAC_QCU_MISC_7_CBR_EXP_INC_LIMIT_MASK)
#define MAC_QCU_MISC_7_CBR_EXP_INC_LIMIT_RESET                       0
#define MAC_QCU_MISC_7_IS_BCN_MSB                                    7
#define MAC_QCU_MISC_7_IS_BCN_LSB                                    7
#define MAC_QCU_MISC_7_IS_BCN_MASK                                   0x00000080
#define MAC_QCU_MISC_7_IS_BCN_GET(x)                                 (((x) & MAC_QCU_MISC_7_IS_BCN_MASK) >> MAC_QCU_MISC_7_IS_BCN_LSB)
#define MAC_QCU_MISC_7_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_QCU_MISC_7_IS_BCN_LSB) & MAC_QCU_MISC_7_IS_BCN_MASK)
#define MAC_QCU_MISC_7_IS_BCN_RESET                                  0
#define MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOBCNFR_MSB                   6
#define MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOBCNFR_LSB                   6
#define MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOBCNFR_MASK                  0x00000040
#define MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOBCNFR_GET(x)                (((x) & MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOBCNFR_MASK) >> MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOBCNFR_LSB)
#define MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOBCNFR_SET(x)                (((0 | (x)) << MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOBCNFR_LSB) & MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOBCNFR_MASK)
#define MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOBCNFR_RESET                 0
#define MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOFR_MSB                      5
#define MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOFR_LSB                      5
#define MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOFR_MASK                     0x00000020
#define MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOFR_GET(x)                   (((x) & MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOFR_MASK) >> MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOFR_LSB)
#define MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOFR_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOFR_LSB) & MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOFR_MASK)
#define MAC_QCU_MISC_7_CBR_EXP_INC_DIS_NOFR_RESET                    0
#define MAC_QCU_MISC_7_ONESHOT_EN_MSB                                4
#define MAC_QCU_MISC_7_ONESHOT_EN_LSB                                4
#define MAC_QCU_MISC_7_ONESHOT_EN_MASK                               0x00000010
#define MAC_QCU_MISC_7_ONESHOT_EN_GET(x)                             (((x) & MAC_QCU_MISC_7_ONESHOT_EN_MASK) >> MAC_QCU_MISC_7_ONESHOT_EN_LSB)
#define MAC_QCU_MISC_7_ONESHOT_EN_SET(x)                             (((0 | (x)) << MAC_QCU_MISC_7_ONESHOT_EN_LSB) & MAC_QCU_MISC_7_ONESHOT_EN_MASK)
#define MAC_QCU_MISC_7_ONESHOT_EN_RESET                              0
#define MAC_QCU_MISC_7_FSP_MSB                                       3
#define MAC_QCU_MISC_7_FSP_LSB                                       0
#define MAC_QCU_MISC_7_FSP_MASK                                      0x0000000f
#define MAC_QCU_MISC_7_FSP_GET(x)                                    (((x) & MAC_QCU_MISC_7_FSP_MASK) >> MAC_QCU_MISC_7_FSP_LSB)
#define MAC_QCU_MISC_7_FSP_SET(x)                                    (((0 | (x)) << MAC_QCU_MISC_7_FSP_LSB) & MAC_QCU_MISC_7_FSP_MASK)
#define MAC_QCU_MISC_7_FSP_RESET                                     0
#define MAC_QCU_MISC_7_ADDRESS                                       0x09dc
#define MAC_QCU_MISC_7_HW_MASK                                       0x00001fff
#define MAC_QCU_MISC_7_SW_MASK                                       0x00001fff
#define MAC_QCU_MISC_7_HW_WRITE_MASK                                 0x00000400
#define MAC_QCU_MISC_7_SW_WRITE_MASK                                 0x00001fff
#define MAC_QCU_MISC_7_RSTMASK                                       0xffffffff
#define MAC_QCU_MISC_7_RESET                                         0x00000800

// 0x09e0 (MAC_QCU_MISC_8)
#define MAC_QCU_MISC_8_NON_ASAP_FRAME_BURST_MSB                      12
#define MAC_QCU_MISC_8_NON_ASAP_FRAME_BURST_LSB                      12
#define MAC_QCU_MISC_8_NON_ASAP_FRAME_BURST_MASK                     0x00001000
#define MAC_QCU_MISC_8_NON_ASAP_FRAME_BURST_GET(x)                   (((x) & MAC_QCU_MISC_8_NON_ASAP_FRAME_BURST_MASK) >> MAC_QCU_MISC_8_NON_ASAP_FRAME_BURST_LSB)
#define MAC_QCU_MISC_8_NON_ASAP_FRAME_BURST_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_8_NON_ASAP_FRAME_BURST_LSB) & MAC_QCU_MISC_8_NON_ASAP_FRAME_BURST_MASK)
#define MAC_QCU_MISC_8_NON_ASAP_FRAME_BURST_RESET                    0
#define MAC_QCU_MISC_8_FR_ABORT_REQ_EN_MSB                           11
#define MAC_QCU_MISC_8_FR_ABORT_REQ_EN_LSB                           11
#define MAC_QCU_MISC_8_FR_ABORT_REQ_EN_MASK                          0x00000800
#define MAC_QCU_MISC_8_FR_ABORT_REQ_EN_GET(x)                        (((x) & MAC_QCU_MISC_8_FR_ABORT_REQ_EN_MASK) >> MAC_QCU_MISC_8_FR_ABORT_REQ_EN_LSB)
#define MAC_QCU_MISC_8_FR_ABORT_REQ_EN_SET(x)                        (((0 | (x)) << MAC_QCU_MISC_8_FR_ABORT_REQ_EN_LSB) & MAC_QCU_MISC_8_FR_ABORT_REQ_EN_MASK)
#define MAC_QCU_MISC_8_FR_ABORT_REQ_EN_RESET                         1
#define MAC_QCU_MISC_8_MMR_CBR_EXP_CNT_CLR_EN_MSB                    10
#define MAC_QCU_MISC_8_MMR_CBR_EXP_CNT_CLR_EN_LSB                    10
#define MAC_QCU_MISC_8_MMR_CBR_EXP_CNT_CLR_EN_MASK                   0x00000400
#define MAC_QCU_MISC_8_MMR_CBR_EXP_CNT_CLR_EN_GET(x)                 (((x) & MAC_QCU_MISC_8_MMR_CBR_EXP_CNT_CLR_EN_MASK) >> MAC_QCU_MISC_8_MMR_CBR_EXP_CNT_CLR_EN_LSB)
#define MAC_QCU_MISC_8_MMR_CBR_EXP_CNT_CLR_EN_SET(x)                 (((0 | (x)) << MAC_QCU_MISC_8_MMR_CBR_EXP_CNT_CLR_EN_LSB) & MAC_QCU_MISC_8_MMR_CBR_EXP_CNT_CLR_EN_MASK)
#define MAC_QCU_MISC_8_MMR_CBR_EXP_CNT_CLR_EN_RESET                  0
#define MAC_QCU_MISC_8_TXE_CLR_ON_CBR_END_MSB                        9
#define MAC_QCU_MISC_8_TXE_CLR_ON_CBR_END_LSB                        9
#define MAC_QCU_MISC_8_TXE_CLR_ON_CBR_END_MASK                       0x00000200
#define MAC_QCU_MISC_8_TXE_CLR_ON_CBR_END_GET(x)                     (((x) & MAC_QCU_MISC_8_TXE_CLR_ON_CBR_END_MASK) >> MAC_QCU_MISC_8_TXE_CLR_ON_CBR_END_LSB)
#define MAC_QCU_MISC_8_TXE_CLR_ON_CBR_END_SET(x)                     (((0 | (x)) << MAC_QCU_MISC_8_TXE_CLR_ON_CBR_END_LSB) & MAC_QCU_MISC_8_TXE_CLR_ON_CBR_END_MASK)
#define MAC_QCU_MISC_8_TXE_CLR_ON_CBR_END_RESET                      0
#define MAC_QCU_MISC_8_CBR_EXP_INC_LIMIT_MSB                         8
#define MAC_QCU_MISC_8_CBR_EXP_INC_LIMIT_LSB                         8
#define MAC_QCU_MISC_8_CBR_EXP_INC_LIMIT_MASK                        0x00000100
#define MAC_QCU_MISC_8_CBR_EXP_INC_LIMIT_GET(x)                      (((x) & MAC_QCU_MISC_8_CBR_EXP_INC_LIMIT_MASK) >> MAC_QCU_MISC_8_CBR_EXP_INC_LIMIT_LSB)
#define MAC_QCU_MISC_8_CBR_EXP_INC_LIMIT_SET(x)                      (((0 | (x)) << MAC_QCU_MISC_8_CBR_EXP_INC_LIMIT_LSB) & MAC_QCU_MISC_8_CBR_EXP_INC_LIMIT_MASK)
#define MAC_QCU_MISC_8_CBR_EXP_INC_LIMIT_RESET                       0
#define MAC_QCU_MISC_8_IS_BCN_MSB                                    7
#define MAC_QCU_MISC_8_IS_BCN_LSB                                    7
#define MAC_QCU_MISC_8_IS_BCN_MASK                                   0x00000080
#define MAC_QCU_MISC_8_IS_BCN_GET(x)                                 (((x) & MAC_QCU_MISC_8_IS_BCN_MASK) >> MAC_QCU_MISC_8_IS_BCN_LSB)
#define MAC_QCU_MISC_8_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_QCU_MISC_8_IS_BCN_LSB) & MAC_QCU_MISC_8_IS_BCN_MASK)
#define MAC_QCU_MISC_8_IS_BCN_RESET                                  0
#define MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOBCNFR_MSB                   6
#define MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOBCNFR_LSB                   6
#define MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOBCNFR_MASK                  0x00000040
#define MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOBCNFR_GET(x)                (((x) & MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOBCNFR_MASK) >> MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOBCNFR_LSB)
#define MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOBCNFR_SET(x)                (((0 | (x)) << MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOBCNFR_LSB) & MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOBCNFR_MASK)
#define MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOBCNFR_RESET                 0
#define MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOFR_MSB                      5
#define MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOFR_LSB                      5
#define MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOFR_MASK                     0x00000020
#define MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOFR_GET(x)                   (((x) & MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOFR_MASK) >> MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOFR_LSB)
#define MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOFR_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOFR_LSB) & MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOFR_MASK)
#define MAC_QCU_MISC_8_CBR_EXP_INC_DIS_NOFR_RESET                    0
#define MAC_QCU_MISC_8_ONESHOT_EN_MSB                                4
#define MAC_QCU_MISC_8_ONESHOT_EN_LSB                                4
#define MAC_QCU_MISC_8_ONESHOT_EN_MASK                               0x00000010
#define MAC_QCU_MISC_8_ONESHOT_EN_GET(x)                             (((x) & MAC_QCU_MISC_8_ONESHOT_EN_MASK) >> MAC_QCU_MISC_8_ONESHOT_EN_LSB)
#define MAC_QCU_MISC_8_ONESHOT_EN_SET(x)                             (((0 | (x)) << MAC_QCU_MISC_8_ONESHOT_EN_LSB) & MAC_QCU_MISC_8_ONESHOT_EN_MASK)
#define MAC_QCU_MISC_8_ONESHOT_EN_RESET                              0
#define MAC_QCU_MISC_8_FSP_MSB                                       3
#define MAC_QCU_MISC_8_FSP_LSB                                       0
#define MAC_QCU_MISC_8_FSP_MASK                                      0x0000000f
#define MAC_QCU_MISC_8_FSP_GET(x)                                    (((x) & MAC_QCU_MISC_8_FSP_MASK) >> MAC_QCU_MISC_8_FSP_LSB)
#define MAC_QCU_MISC_8_FSP_SET(x)                                    (((0 | (x)) << MAC_QCU_MISC_8_FSP_LSB) & MAC_QCU_MISC_8_FSP_MASK)
#define MAC_QCU_MISC_8_FSP_RESET                                     0
#define MAC_QCU_MISC_8_ADDRESS                                       0x09e0
#define MAC_QCU_MISC_8_HW_MASK                                       0x00001fff
#define MAC_QCU_MISC_8_SW_MASK                                       0x00001fff
#define MAC_QCU_MISC_8_HW_WRITE_MASK                                 0x00000400
#define MAC_QCU_MISC_8_SW_WRITE_MASK                                 0x00001fff
#define MAC_QCU_MISC_8_RSTMASK                                       0xffffffff
#define MAC_QCU_MISC_8_RESET                                         0x00000800

// 0x09e4 (MAC_QCU_MISC_9)
#define MAC_QCU_MISC_9_NON_ASAP_FRAME_BURST_MSB                      12
#define MAC_QCU_MISC_9_NON_ASAP_FRAME_BURST_LSB                      12
#define MAC_QCU_MISC_9_NON_ASAP_FRAME_BURST_MASK                     0x00001000
#define MAC_QCU_MISC_9_NON_ASAP_FRAME_BURST_GET(x)                   (((x) & MAC_QCU_MISC_9_NON_ASAP_FRAME_BURST_MASK) >> MAC_QCU_MISC_9_NON_ASAP_FRAME_BURST_LSB)
#define MAC_QCU_MISC_9_NON_ASAP_FRAME_BURST_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_9_NON_ASAP_FRAME_BURST_LSB) & MAC_QCU_MISC_9_NON_ASAP_FRAME_BURST_MASK)
#define MAC_QCU_MISC_9_NON_ASAP_FRAME_BURST_RESET                    0
#define MAC_QCU_MISC_9_FR_ABORT_REQ_EN_MSB                           11
#define MAC_QCU_MISC_9_FR_ABORT_REQ_EN_LSB                           11
#define MAC_QCU_MISC_9_FR_ABORT_REQ_EN_MASK                          0x00000800
#define MAC_QCU_MISC_9_FR_ABORT_REQ_EN_GET(x)                        (((x) & MAC_QCU_MISC_9_FR_ABORT_REQ_EN_MASK) >> MAC_QCU_MISC_9_FR_ABORT_REQ_EN_LSB)
#define MAC_QCU_MISC_9_FR_ABORT_REQ_EN_SET(x)                        (((0 | (x)) << MAC_QCU_MISC_9_FR_ABORT_REQ_EN_LSB) & MAC_QCU_MISC_9_FR_ABORT_REQ_EN_MASK)
#define MAC_QCU_MISC_9_FR_ABORT_REQ_EN_RESET                         1
#define MAC_QCU_MISC_9_MMR_CBR_EXP_CNT_CLR_EN_MSB                    10
#define MAC_QCU_MISC_9_MMR_CBR_EXP_CNT_CLR_EN_LSB                    10
#define MAC_QCU_MISC_9_MMR_CBR_EXP_CNT_CLR_EN_MASK                   0x00000400
#define MAC_QCU_MISC_9_MMR_CBR_EXP_CNT_CLR_EN_GET(x)                 (((x) & MAC_QCU_MISC_9_MMR_CBR_EXP_CNT_CLR_EN_MASK) >> MAC_QCU_MISC_9_MMR_CBR_EXP_CNT_CLR_EN_LSB)
#define MAC_QCU_MISC_9_MMR_CBR_EXP_CNT_CLR_EN_SET(x)                 (((0 | (x)) << MAC_QCU_MISC_9_MMR_CBR_EXP_CNT_CLR_EN_LSB) & MAC_QCU_MISC_9_MMR_CBR_EXP_CNT_CLR_EN_MASK)
#define MAC_QCU_MISC_9_MMR_CBR_EXP_CNT_CLR_EN_RESET                  0
#define MAC_QCU_MISC_9_TXE_CLR_ON_CBR_END_MSB                        9
#define MAC_QCU_MISC_9_TXE_CLR_ON_CBR_END_LSB                        9
#define MAC_QCU_MISC_9_TXE_CLR_ON_CBR_END_MASK                       0x00000200
#define MAC_QCU_MISC_9_TXE_CLR_ON_CBR_END_GET(x)                     (((x) & MAC_QCU_MISC_9_TXE_CLR_ON_CBR_END_MASK) >> MAC_QCU_MISC_9_TXE_CLR_ON_CBR_END_LSB)
#define MAC_QCU_MISC_9_TXE_CLR_ON_CBR_END_SET(x)                     (((0 | (x)) << MAC_QCU_MISC_9_TXE_CLR_ON_CBR_END_LSB) & MAC_QCU_MISC_9_TXE_CLR_ON_CBR_END_MASK)
#define MAC_QCU_MISC_9_TXE_CLR_ON_CBR_END_RESET                      0
#define MAC_QCU_MISC_9_CBR_EXP_INC_LIMIT_MSB                         8
#define MAC_QCU_MISC_9_CBR_EXP_INC_LIMIT_LSB                         8
#define MAC_QCU_MISC_9_CBR_EXP_INC_LIMIT_MASK                        0x00000100
#define MAC_QCU_MISC_9_CBR_EXP_INC_LIMIT_GET(x)                      (((x) & MAC_QCU_MISC_9_CBR_EXP_INC_LIMIT_MASK) >> MAC_QCU_MISC_9_CBR_EXP_INC_LIMIT_LSB)
#define MAC_QCU_MISC_9_CBR_EXP_INC_LIMIT_SET(x)                      (((0 | (x)) << MAC_QCU_MISC_9_CBR_EXP_INC_LIMIT_LSB) & MAC_QCU_MISC_9_CBR_EXP_INC_LIMIT_MASK)
#define MAC_QCU_MISC_9_CBR_EXP_INC_LIMIT_RESET                       0
#define MAC_QCU_MISC_9_IS_BCN_MSB                                    7
#define MAC_QCU_MISC_9_IS_BCN_LSB                                    7
#define MAC_QCU_MISC_9_IS_BCN_MASK                                   0x00000080
#define MAC_QCU_MISC_9_IS_BCN_GET(x)                                 (((x) & MAC_QCU_MISC_9_IS_BCN_MASK) >> MAC_QCU_MISC_9_IS_BCN_LSB)
#define MAC_QCU_MISC_9_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_QCU_MISC_9_IS_BCN_LSB) & MAC_QCU_MISC_9_IS_BCN_MASK)
#define MAC_QCU_MISC_9_IS_BCN_RESET                                  0
#define MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOBCNFR_MSB                   6
#define MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOBCNFR_LSB                   6
#define MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOBCNFR_MASK                  0x00000040
#define MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOBCNFR_GET(x)                (((x) & MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOBCNFR_MASK) >> MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOBCNFR_LSB)
#define MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOBCNFR_SET(x)                (((0 | (x)) << MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOBCNFR_LSB) & MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOBCNFR_MASK)
#define MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOBCNFR_RESET                 0
#define MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOFR_MSB                      5
#define MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOFR_LSB                      5
#define MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOFR_MASK                     0x00000020
#define MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOFR_GET(x)                   (((x) & MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOFR_MASK) >> MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOFR_LSB)
#define MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOFR_SET(x)                   (((0 | (x)) << MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOFR_LSB) & MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOFR_MASK)
#define MAC_QCU_MISC_9_CBR_EXP_INC_DIS_NOFR_RESET                    0
#define MAC_QCU_MISC_9_ONESHOT_EN_MSB                                4
#define MAC_QCU_MISC_9_ONESHOT_EN_LSB                                4
#define MAC_QCU_MISC_9_ONESHOT_EN_MASK                               0x00000010
#define MAC_QCU_MISC_9_ONESHOT_EN_GET(x)                             (((x) & MAC_QCU_MISC_9_ONESHOT_EN_MASK) >> MAC_QCU_MISC_9_ONESHOT_EN_LSB)
#define MAC_QCU_MISC_9_ONESHOT_EN_SET(x)                             (((0 | (x)) << MAC_QCU_MISC_9_ONESHOT_EN_LSB) & MAC_QCU_MISC_9_ONESHOT_EN_MASK)
#define MAC_QCU_MISC_9_ONESHOT_EN_RESET                              0
#define MAC_QCU_MISC_9_FSP_MSB                                       3
#define MAC_QCU_MISC_9_FSP_LSB                                       0
#define MAC_QCU_MISC_9_FSP_MASK                                      0x0000000f
#define MAC_QCU_MISC_9_FSP_GET(x)                                    (((x) & MAC_QCU_MISC_9_FSP_MASK) >> MAC_QCU_MISC_9_FSP_LSB)
#define MAC_QCU_MISC_9_FSP_SET(x)                                    (((0 | (x)) << MAC_QCU_MISC_9_FSP_LSB) & MAC_QCU_MISC_9_FSP_MASK)
#define MAC_QCU_MISC_9_FSP_RESET                                     0
#define MAC_QCU_MISC_9_ADDRESS                                       0x09e4
#define MAC_QCU_MISC_9_HW_MASK                                       0x00001fff
#define MAC_QCU_MISC_9_SW_MASK                                       0x00001fff
#define MAC_QCU_MISC_9_HW_WRITE_MASK                                 0x00000400
#define MAC_QCU_MISC_9_SW_WRITE_MASK                                 0x00001fff
#define MAC_QCU_MISC_9_RSTMASK                                       0xffffffff
#define MAC_QCU_MISC_9_RESET                                         0x00000800

// 0x0a00 (MAC_QCU_CNT_0)
#define MAC_QCU_CNT_0_CBR_EXP_MSB                                    15
#define MAC_QCU_CNT_0_CBR_EXP_LSB                                    8
#define MAC_QCU_CNT_0_CBR_EXP_MASK                                   0x0000ff00
#define MAC_QCU_CNT_0_CBR_EXP_GET(x)                                 (((x) & MAC_QCU_CNT_0_CBR_EXP_MASK) >> MAC_QCU_CNT_0_CBR_EXP_LSB)
#define MAC_QCU_CNT_0_CBR_EXP_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_0_CBR_EXP_LSB) & MAC_QCU_CNT_0_CBR_EXP_MASK)
#define MAC_QCU_CNT_0_CBR_EXP_RESET                                  0
#define MAC_QCU_CNT_0_FR_PEND_MSB                                    1
#define MAC_QCU_CNT_0_FR_PEND_LSB                                    0
#define MAC_QCU_CNT_0_FR_PEND_MASK                                   0x00000003
#define MAC_QCU_CNT_0_FR_PEND_GET(x)                                 (((x) & MAC_QCU_CNT_0_FR_PEND_MASK) >> MAC_QCU_CNT_0_FR_PEND_LSB)
#define MAC_QCU_CNT_0_FR_PEND_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_0_FR_PEND_LSB) & MAC_QCU_CNT_0_FR_PEND_MASK)
#define MAC_QCU_CNT_0_FR_PEND_RESET                                  0
#define MAC_QCU_CNT_0_ADDRESS                                        0x0a00
#define MAC_QCU_CNT_ADDRESS                                          MAC_QCU_CNT_0_ADDRESS
#define MAC_QCU_CNT_0_HW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_0_SW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_0_HW_WRITE_MASK                                  0x0000ff03
#define MAC_QCU_CNT_0_SW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CNT_0_RSTMASK                                        0xffffffff
#define MAC_QCU_CNT_0_RESET                                          0x00000000

// 0x0a04 (MAC_QCU_CNT_1)
#define MAC_QCU_CNT_1_CBR_EXP_MSB                                    15
#define MAC_QCU_CNT_1_CBR_EXP_LSB                                    8
#define MAC_QCU_CNT_1_CBR_EXP_MASK                                   0x0000ff00
#define MAC_QCU_CNT_1_CBR_EXP_GET(x)                                 (((x) & MAC_QCU_CNT_1_CBR_EXP_MASK) >> MAC_QCU_CNT_1_CBR_EXP_LSB)
#define MAC_QCU_CNT_1_CBR_EXP_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_1_CBR_EXP_LSB) & MAC_QCU_CNT_1_CBR_EXP_MASK)
#define MAC_QCU_CNT_1_CBR_EXP_RESET                                  0
#define MAC_QCU_CNT_1_FR_PEND_MSB                                    1
#define MAC_QCU_CNT_1_FR_PEND_LSB                                    0
#define MAC_QCU_CNT_1_FR_PEND_MASK                                   0x00000003
#define MAC_QCU_CNT_1_FR_PEND_GET(x)                                 (((x) & MAC_QCU_CNT_1_FR_PEND_MASK) >> MAC_QCU_CNT_1_FR_PEND_LSB)
#define MAC_QCU_CNT_1_FR_PEND_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_1_FR_PEND_LSB) & MAC_QCU_CNT_1_FR_PEND_MASK)
#define MAC_QCU_CNT_1_FR_PEND_RESET                                  0
#define MAC_QCU_CNT_1_ADDRESS                                        0x0a04
#define MAC_QCU_CNT_1_HW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_1_SW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_1_HW_WRITE_MASK                                  0x0000ff03
#define MAC_QCU_CNT_1_SW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CNT_1_RSTMASK                                        0xffffffff
#define MAC_QCU_CNT_1_RESET                                          0x00000000

// 0x0a08 (MAC_QCU_CNT_2)
#define MAC_QCU_CNT_2_CBR_EXP_MSB                                    15
#define MAC_QCU_CNT_2_CBR_EXP_LSB                                    8
#define MAC_QCU_CNT_2_CBR_EXP_MASK                                   0x0000ff00
#define MAC_QCU_CNT_2_CBR_EXP_GET(x)                                 (((x) & MAC_QCU_CNT_2_CBR_EXP_MASK) >> MAC_QCU_CNT_2_CBR_EXP_LSB)
#define MAC_QCU_CNT_2_CBR_EXP_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_2_CBR_EXP_LSB) & MAC_QCU_CNT_2_CBR_EXP_MASK)
#define MAC_QCU_CNT_2_CBR_EXP_RESET                                  0
#define MAC_QCU_CNT_2_FR_PEND_MSB                                    1
#define MAC_QCU_CNT_2_FR_PEND_LSB                                    0
#define MAC_QCU_CNT_2_FR_PEND_MASK                                   0x00000003
#define MAC_QCU_CNT_2_FR_PEND_GET(x)                                 (((x) & MAC_QCU_CNT_2_FR_PEND_MASK) >> MAC_QCU_CNT_2_FR_PEND_LSB)
#define MAC_QCU_CNT_2_FR_PEND_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_2_FR_PEND_LSB) & MAC_QCU_CNT_2_FR_PEND_MASK)
#define MAC_QCU_CNT_2_FR_PEND_RESET                                  0
#define MAC_QCU_CNT_2_ADDRESS                                        0x0a08
#define MAC_QCU_CNT_2_HW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_2_SW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_2_HW_WRITE_MASK                                  0x0000ff03
#define MAC_QCU_CNT_2_SW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CNT_2_RSTMASK                                        0xffffffff
#define MAC_QCU_CNT_2_RESET                                          0x00000000

// 0x0a0c (MAC_QCU_CNT_3)
#define MAC_QCU_CNT_3_CBR_EXP_MSB                                    15
#define MAC_QCU_CNT_3_CBR_EXP_LSB                                    8
#define MAC_QCU_CNT_3_CBR_EXP_MASK                                   0x0000ff00
#define MAC_QCU_CNT_3_CBR_EXP_GET(x)                                 (((x) & MAC_QCU_CNT_3_CBR_EXP_MASK) >> MAC_QCU_CNT_3_CBR_EXP_LSB)
#define MAC_QCU_CNT_3_CBR_EXP_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_3_CBR_EXP_LSB) & MAC_QCU_CNT_3_CBR_EXP_MASK)
#define MAC_QCU_CNT_3_CBR_EXP_RESET                                  0
#define MAC_QCU_CNT_3_FR_PEND_MSB                                    1
#define MAC_QCU_CNT_3_FR_PEND_LSB                                    0
#define MAC_QCU_CNT_3_FR_PEND_MASK                                   0x00000003
#define MAC_QCU_CNT_3_FR_PEND_GET(x)                                 (((x) & MAC_QCU_CNT_3_FR_PEND_MASK) >> MAC_QCU_CNT_3_FR_PEND_LSB)
#define MAC_QCU_CNT_3_FR_PEND_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_3_FR_PEND_LSB) & MAC_QCU_CNT_3_FR_PEND_MASK)
#define MAC_QCU_CNT_3_FR_PEND_RESET                                  0
#define MAC_QCU_CNT_3_ADDRESS                                        0x0a0c
#define MAC_QCU_CNT_3_HW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_3_SW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_3_HW_WRITE_MASK                                  0x0000ff03
#define MAC_QCU_CNT_3_SW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CNT_3_RSTMASK                                        0xffffffff
#define MAC_QCU_CNT_3_RESET                                          0x00000000

// 0x0a10 (MAC_QCU_CNT_4)
#define MAC_QCU_CNT_4_CBR_EXP_MSB                                    15
#define MAC_QCU_CNT_4_CBR_EXP_LSB                                    8
#define MAC_QCU_CNT_4_CBR_EXP_MASK                                   0x0000ff00
#define MAC_QCU_CNT_4_CBR_EXP_GET(x)                                 (((x) & MAC_QCU_CNT_4_CBR_EXP_MASK) >> MAC_QCU_CNT_4_CBR_EXP_LSB)
#define MAC_QCU_CNT_4_CBR_EXP_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_4_CBR_EXP_LSB) & MAC_QCU_CNT_4_CBR_EXP_MASK)
#define MAC_QCU_CNT_4_CBR_EXP_RESET                                  0
#define MAC_QCU_CNT_4_FR_PEND_MSB                                    1
#define MAC_QCU_CNT_4_FR_PEND_LSB                                    0
#define MAC_QCU_CNT_4_FR_PEND_MASK                                   0x00000003
#define MAC_QCU_CNT_4_FR_PEND_GET(x)                                 (((x) & MAC_QCU_CNT_4_FR_PEND_MASK) >> MAC_QCU_CNT_4_FR_PEND_LSB)
#define MAC_QCU_CNT_4_FR_PEND_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_4_FR_PEND_LSB) & MAC_QCU_CNT_4_FR_PEND_MASK)
#define MAC_QCU_CNT_4_FR_PEND_RESET                                  0
#define MAC_QCU_CNT_4_ADDRESS                                        0x0a10
#define MAC_QCU_CNT_4_HW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_4_SW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_4_HW_WRITE_MASK                                  0x0000ff03
#define MAC_QCU_CNT_4_SW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CNT_4_RSTMASK                                        0xffffffff
#define MAC_QCU_CNT_4_RESET                                          0x00000000

// 0x0a14 (MAC_QCU_CNT_5)
#define MAC_QCU_CNT_5_CBR_EXP_MSB                                    15
#define MAC_QCU_CNT_5_CBR_EXP_LSB                                    8
#define MAC_QCU_CNT_5_CBR_EXP_MASK                                   0x0000ff00
#define MAC_QCU_CNT_5_CBR_EXP_GET(x)                                 (((x) & MAC_QCU_CNT_5_CBR_EXP_MASK) >> MAC_QCU_CNT_5_CBR_EXP_LSB)
#define MAC_QCU_CNT_5_CBR_EXP_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_5_CBR_EXP_LSB) & MAC_QCU_CNT_5_CBR_EXP_MASK)
#define MAC_QCU_CNT_5_CBR_EXP_RESET                                  0
#define MAC_QCU_CNT_5_FR_PEND_MSB                                    1
#define MAC_QCU_CNT_5_FR_PEND_LSB                                    0
#define MAC_QCU_CNT_5_FR_PEND_MASK                                   0x00000003
#define MAC_QCU_CNT_5_FR_PEND_GET(x)                                 (((x) & MAC_QCU_CNT_5_FR_PEND_MASK) >> MAC_QCU_CNT_5_FR_PEND_LSB)
#define MAC_QCU_CNT_5_FR_PEND_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_5_FR_PEND_LSB) & MAC_QCU_CNT_5_FR_PEND_MASK)
#define MAC_QCU_CNT_5_FR_PEND_RESET                                  0
#define MAC_QCU_CNT_5_ADDRESS                                        0x0a14
#define MAC_QCU_CNT_5_HW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_5_SW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_5_HW_WRITE_MASK                                  0x0000ff03
#define MAC_QCU_CNT_5_SW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CNT_5_RSTMASK                                        0xffffffff
#define MAC_QCU_CNT_5_RESET                                          0x00000000

// 0x0a18 (MAC_QCU_CNT_6)
#define MAC_QCU_CNT_6_CBR_EXP_MSB                                    15
#define MAC_QCU_CNT_6_CBR_EXP_LSB                                    8
#define MAC_QCU_CNT_6_CBR_EXP_MASK                                   0x0000ff00
#define MAC_QCU_CNT_6_CBR_EXP_GET(x)                                 (((x) & MAC_QCU_CNT_6_CBR_EXP_MASK) >> MAC_QCU_CNT_6_CBR_EXP_LSB)
#define MAC_QCU_CNT_6_CBR_EXP_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_6_CBR_EXP_LSB) & MAC_QCU_CNT_6_CBR_EXP_MASK)
#define MAC_QCU_CNT_6_CBR_EXP_RESET                                  0
#define MAC_QCU_CNT_6_FR_PEND_MSB                                    1
#define MAC_QCU_CNT_6_FR_PEND_LSB                                    0
#define MAC_QCU_CNT_6_FR_PEND_MASK                                   0x00000003
#define MAC_QCU_CNT_6_FR_PEND_GET(x)                                 (((x) & MAC_QCU_CNT_6_FR_PEND_MASK) >> MAC_QCU_CNT_6_FR_PEND_LSB)
#define MAC_QCU_CNT_6_FR_PEND_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_6_FR_PEND_LSB) & MAC_QCU_CNT_6_FR_PEND_MASK)
#define MAC_QCU_CNT_6_FR_PEND_RESET                                  0
#define MAC_QCU_CNT_6_ADDRESS                                        0x0a18
#define MAC_QCU_CNT_6_HW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_6_SW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_6_HW_WRITE_MASK                                  0x0000ff03
#define MAC_QCU_CNT_6_SW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CNT_6_RSTMASK                                        0xffffffff
#define MAC_QCU_CNT_6_RESET                                          0x00000000

// 0x0a1c (MAC_QCU_CNT_7)
#define MAC_QCU_CNT_7_CBR_EXP_MSB                                    15
#define MAC_QCU_CNT_7_CBR_EXP_LSB                                    8
#define MAC_QCU_CNT_7_CBR_EXP_MASK                                   0x0000ff00
#define MAC_QCU_CNT_7_CBR_EXP_GET(x)                                 (((x) & MAC_QCU_CNT_7_CBR_EXP_MASK) >> MAC_QCU_CNT_7_CBR_EXP_LSB)
#define MAC_QCU_CNT_7_CBR_EXP_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_7_CBR_EXP_LSB) & MAC_QCU_CNT_7_CBR_EXP_MASK)
#define MAC_QCU_CNT_7_CBR_EXP_RESET                                  0
#define MAC_QCU_CNT_7_FR_PEND_MSB                                    1
#define MAC_QCU_CNT_7_FR_PEND_LSB                                    0
#define MAC_QCU_CNT_7_FR_PEND_MASK                                   0x00000003
#define MAC_QCU_CNT_7_FR_PEND_GET(x)                                 (((x) & MAC_QCU_CNT_7_FR_PEND_MASK) >> MAC_QCU_CNT_7_FR_PEND_LSB)
#define MAC_QCU_CNT_7_FR_PEND_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_7_FR_PEND_LSB) & MAC_QCU_CNT_7_FR_PEND_MASK)
#define MAC_QCU_CNT_7_FR_PEND_RESET                                  0
#define MAC_QCU_CNT_7_ADDRESS                                        0x0a1c
#define MAC_QCU_CNT_7_HW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_7_SW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_7_HW_WRITE_MASK                                  0x0000ff03
#define MAC_QCU_CNT_7_SW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CNT_7_RSTMASK                                        0xffffffff
#define MAC_QCU_CNT_7_RESET                                          0x00000000

// 0x0a20 (MAC_QCU_CNT_8)
#define MAC_QCU_CNT_8_CBR_EXP_MSB                                    15
#define MAC_QCU_CNT_8_CBR_EXP_LSB                                    8
#define MAC_QCU_CNT_8_CBR_EXP_MASK                                   0x0000ff00
#define MAC_QCU_CNT_8_CBR_EXP_GET(x)                                 (((x) & MAC_QCU_CNT_8_CBR_EXP_MASK) >> MAC_QCU_CNT_8_CBR_EXP_LSB)
#define MAC_QCU_CNT_8_CBR_EXP_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_8_CBR_EXP_LSB) & MAC_QCU_CNT_8_CBR_EXP_MASK)
#define MAC_QCU_CNT_8_CBR_EXP_RESET                                  0
#define MAC_QCU_CNT_8_FR_PEND_MSB                                    1
#define MAC_QCU_CNT_8_FR_PEND_LSB                                    0
#define MAC_QCU_CNT_8_FR_PEND_MASK                                   0x00000003
#define MAC_QCU_CNT_8_FR_PEND_GET(x)                                 (((x) & MAC_QCU_CNT_8_FR_PEND_MASK) >> MAC_QCU_CNT_8_FR_PEND_LSB)
#define MAC_QCU_CNT_8_FR_PEND_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_8_FR_PEND_LSB) & MAC_QCU_CNT_8_FR_PEND_MASK)
#define MAC_QCU_CNT_8_FR_PEND_RESET                                  0
#define MAC_QCU_CNT_8_ADDRESS                                        0x0a20
#define MAC_QCU_CNT_8_HW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_8_SW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_8_HW_WRITE_MASK                                  0x0000ff03
#define MAC_QCU_CNT_8_SW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CNT_8_RSTMASK                                        0xffffffff
#define MAC_QCU_CNT_8_RESET                                          0x00000000

// 0x0a24 (MAC_QCU_CNT_9)
#define MAC_QCU_CNT_9_CBR_EXP_MSB                                    15
#define MAC_QCU_CNT_9_CBR_EXP_LSB                                    8
#define MAC_QCU_CNT_9_CBR_EXP_MASK                                   0x0000ff00
#define MAC_QCU_CNT_9_CBR_EXP_GET(x)                                 (((x) & MAC_QCU_CNT_9_CBR_EXP_MASK) >> MAC_QCU_CNT_9_CBR_EXP_LSB)
#define MAC_QCU_CNT_9_CBR_EXP_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_9_CBR_EXP_LSB) & MAC_QCU_CNT_9_CBR_EXP_MASK)
#define MAC_QCU_CNT_9_CBR_EXP_RESET                                  0
#define MAC_QCU_CNT_9_FR_PEND_MSB                                    1
#define MAC_QCU_CNT_9_FR_PEND_LSB                                    0
#define MAC_QCU_CNT_9_FR_PEND_MASK                                   0x00000003
#define MAC_QCU_CNT_9_FR_PEND_GET(x)                                 (((x) & MAC_QCU_CNT_9_FR_PEND_MASK) >> MAC_QCU_CNT_9_FR_PEND_LSB)
#define MAC_QCU_CNT_9_FR_PEND_SET(x)                                 (((0 | (x)) << MAC_QCU_CNT_9_FR_PEND_LSB) & MAC_QCU_CNT_9_FR_PEND_MASK)
#define MAC_QCU_CNT_9_FR_PEND_RESET                                  0
#define MAC_QCU_CNT_9_ADDRESS                                        0x0a24
#define MAC_QCU_CNT_9_HW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_9_SW_MASK                                        0x0000ff03
#define MAC_QCU_CNT_9_HW_WRITE_MASK                                  0x0000ff03
#define MAC_QCU_CNT_9_SW_WRITE_MASK                                  0x00000000
#define MAC_QCU_CNT_9_RSTMASK                                        0xffffffff
#define MAC_QCU_CNT_9_RESET                                          0x00000000

// 0x0a40 (MAC_QCU_RDYTIME_SHDN)
#define MAC_QCU_RDYTIME_SHDN_SHUTDOWN_MSB                            9
#define MAC_QCU_RDYTIME_SHDN_SHUTDOWN_LSB                            0
#define MAC_QCU_RDYTIME_SHDN_SHUTDOWN_MASK                           0x000003ff
#define MAC_QCU_RDYTIME_SHDN_SHUTDOWN_GET(x)                         (((x) & MAC_QCU_RDYTIME_SHDN_SHUTDOWN_MASK) >> MAC_QCU_RDYTIME_SHDN_SHUTDOWN_LSB)
#define MAC_QCU_RDYTIME_SHDN_SHUTDOWN_SET(x)                         (((0 | (x)) << MAC_QCU_RDYTIME_SHDN_SHUTDOWN_LSB) & MAC_QCU_RDYTIME_SHDN_SHUTDOWN_MASK)
#define MAC_QCU_RDYTIME_SHDN_SHUTDOWN_RESET                          0
#define MAC_QCU_RDYTIME_SHDN_ADDRESS                                 0x0a40
#define MAC_QCU_RDYTIME_SHDN_HW_MASK                                 0x000003ff
#define MAC_QCU_RDYTIME_SHDN_SW_MASK                                 0x000003ff
#define MAC_QCU_RDYTIME_SHDN_HW_WRITE_MASK                           0x000003ff
#define MAC_QCU_RDYTIME_SHDN_SW_WRITE_MASK                           0x000003ff
#define MAC_QCU_RDYTIME_SHDN_RSTMASK                                 0xffffffff
#define MAC_QCU_RDYTIME_SHDN_RESET                                   0x00000000

// 0x0a44 (MAC_QCU_DESC_CRC_CHK)
#define MAC_QCU_DESC_CRC_CHK_EN_MSB                                  0
#define MAC_QCU_DESC_CRC_CHK_EN_LSB                                  0
#define MAC_QCU_DESC_CRC_CHK_EN_MASK                                 0x00000001
#define MAC_QCU_DESC_CRC_CHK_EN_GET(x)                               (((x) & MAC_QCU_DESC_CRC_CHK_EN_MASK) >> MAC_QCU_DESC_CRC_CHK_EN_LSB)
#define MAC_QCU_DESC_CRC_CHK_EN_SET(x)                               (((0 | (x)) << MAC_QCU_DESC_CRC_CHK_EN_LSB) & MAC_QCU_DESC_CRC_CHK_EN_MASK)
#define MAC_QCU_DESC_CRC_CHK_EN_RESET                                1
#define MAC_QCU_DESC_CRC_CHK_ADDRESS                                 0x0a44
#define MAC_QCU_DESC_CRC_CHK_HW_MASK                                 0x00000001
#define MAC_QCU_DESC_CRC_CHK_SW_MASK                                 0x00000001
#define MAC_QCU_DESC_CRC_CHK_HW_WRITE_MASK                           0x00000000
#define MAC_QCU_DESC_CRC_CHK_SW_WRITE_MASK                           0x00000001
#define MAC_QCU_DESC_CRC_CHK_RSTMASK                                 0xffffffff
#define MAC_QCU_DESC_CRC_CHK_RESET                                   0x00000001

// 0x0a48 (MAC_QCU_EOL)
#define MAC_QCU_EOL_DUR_CAL_EN_MSB                                   9
#define MAC_QCU_EOL_DUR_CAL_EN_LSB                                   0
#define MAC_QCU_EOL_DUR_CAL_EN_MASK                                  0x000003ff
#define MAC_QCU_EOL_DUR_CAL_EN_GET(x)                                (((x) & MAC_QCU_EOL_DUR_CAL_EN_MASK) >> MAC_QCU_EOL_DUR_CAL_EN_LSB)
#define MAC_QCU_EOL_DUR_CAL_EN_SET(x)                                (((0 | (x)) << MAC_QCU_EOL_DUR_CAL_EN_LSB) & MAC_QCU_EOL_DUR_CAL_EN_MASK)
#define MAC_QCU_EOL_DUR_CAL_EN_RESET                                 1023
#define MAC_QCU_EOL_ADDRESS                                          0x0a48
#define MAC_QCU_EOL_HW_MASK                                          0x000003ff
#define MAC_QCU_EOL_SW_MASK                                          0x000003ff
#define MAC_QCU_EOL_HW_WRITE_MASK                                    0x00000000
#define MAC_QCU_EOL_SW_WRITE_MASK                                    0x000003ff
#define MAC_QCU_EOL_RSTMASK                                          0xffffffff
#define MAC_QCU_EOL_RESET                                            0x000003ff

// 0x0a4c (MAC_QCU_TXQ_PAUSE)
#define MAC_QCU_TXQ_PAUSE_Q9_MSB                                     9
#define MAC_QCU_TXQ_PAUSE_Q9_LSB                                     9
#define MAC_QCU_TXQ_PAUSE_Q9_MASK                                    0x00000200
#define MAC_QCU_TXQ_PAUSE_Q9_GET(x)                                  (((x) & MAC_QCU_TXQ_PAUSE_Q9_MASK) >> MAC_QCU_TXQ_PAUSE_Q9_LSB)
#define MAC_QCU_TXQ_PAUSE_Q9_SET(x)                                  (((0 | (x)) << MAC_QCU_TXQ_PAUSE_Q9_LSB) & MAC_QCU_TXQ_PAUSE_Q9_MASK)
#define MAC_QCU_TXQ_PAUSE_Q9_RESET                                   0
#define MAC_QCU_TXQ_PAUSE_Q8_MSB                                     8
#define MAC_QCU_TXQ_PAUSE_Q8_LSB                                     8
#define MAC_QCU_TXQ_PAUSE_Q8_MASK                                    0x00000100
#define MAC_QCU_TXQ_PAUSE_Q8_GET(x)                                  (((x) & MAC_QCU_TXQ_PAUSE_Q8_MASK) >> MAC_QCU_TXQ_PAUSE_Q8_LSB)
#define MAC_QCU_TXQ_PAUSE_Q8_SET(x)                                  (((0 | (x)) << MAC_QCU_TXQ_PAUSE_Q8_LSB) & MAC_QCU_TXQ_PAUSE_Q8_MASK)
#define MAC_QCU_TXQ_PAUSE_Q8_RESET                                   0
#define MAC_QCU_TXQ_PAUSE_Q7_MSB                                     7
#define MAC_QCU_TXQ_PAUSE_Q7_LSB                                     7
#define MAC_QCU_TXQ_PAUSE_Q7_MASK                                    0x00000080
#define MAC_QCU_TXQ_PAUSE_Q7_GET(x)                                  (((x) & MAC_QCU_TXQ_PAUSE_Q7_MASK) >> MAC_QCU_TXQ_PAUSE_Q7_LSB)
#define MAC_QCU_TXQ_PAUSE_Q7_SET(x)                                  (((0 | (x)) << MAC_QCU_TXQ_PAUSE_Q7_LSB) & MAC_QCU_TXQ_PAUSE_Q7_MASK)
#define MAC_QCU_TXQ_PAUSE_Q7_RESET                                   0
#define MAC_QCU_TXQ_PAUSE_Q6_MSB                                     6
#define MAC_QCU_TXQ_PAUSE_Q6_LSB                                     6
#define MAC_QCU_TXQ_PAUSE_Q6_MASK                                    0x00000040
#define MAC_QCU_TXQ_PAUSE_Q6_GET(x)                                  (((x) & MAC_QCU_TXQ_PAUSE_Q6_MASK) >> MAC_QCU_TXQ_PAUSE_Q6_LSB)
#define MAC_QCU_TXQ_PAUSE_Q6_SET(x)                                  (((0 | (x)) << MAC_QCU_TXQ_PAUSE_Q6_LSB) & MAC_QCU_TXQ_PAUSE_Q6_MASK)
#define MAC_QCU_TXQ_PAUSE_Q6_RESET                                   0
#define MAC_QCU_TXQ_PAUSE_Q5_MSB                                     5
#define MAC_QCU_TXQ_PAUSE_Q5_LSB                                     5
#define MAC_QCU_TXQ_PAUSE_Q5_MASK                                    0x00000020
#define MAC_QCU_TXQ_PAUSE_Q5_GET(x)                                  (((x) & MAC_QCU_TXQ_PAUSE_Q5_MASK) >> MAC_QCU_TXQ_PAUSE_Q5_LSB)
#define MAC_QCU_TXQ_PAUSE_Q5_SET(x)                                  (((0 | (x)) << MAC_QCU_TXQ_PAUSE_Q5_LSB) & MAC_QCU_TXQ_PAUSE_Q5_MASK)
#define MAC_QCU_TXQ_PAUSE_Q5_RESET                                   0
#define MAC_QCU_TXQ_PAUSE_Q4_MSB                                     4
#define MAC_QCU_TXQ_PAUSE_Q4_LSB                                     4
#define MAC_QCU_TXQ_PAUSE_Q4_MASK                                    0x00000010
#define MAC_QCU_TXQ_PAUSE_Q4_GET(x)                                  (((x) & MAC_QCU_TXQ_PAUSE_Q4_MASK) >> MAC_QCU_TXQ_PAUSE_Q4_LSB)
#define MAC_QCU_TXQ_PAUSE_Q4_SET(x)                                  (((0 | (x)) << MAC_QCU_TXQ_PAUSE_Q4_LSB) & MAC_QCU_TXQ_PAUSE_Q4_MASK)
#define MAC_QCU_TXQ_PAUSE_Q4_RESET                                   0
#define MAC_QCU_TXQ_PAUSE_Q3_MSB                                     3
#define MAC_QCU_TXQ_PAUSE_Q3_LSB                                     3
#define MAC_QCU_TXQ_PAUSE_Q3_MASK                                    0x00000008
#define MAC_QCU_TXQ_PAUSE_Q3_GET(x)                                  (((x) & MAC_QCU_TXQ_PAUSE_Q3_MASK) >> MAC_QCU_TXQ_PAUSE_Q3_LSB)
#define MAC_QCU_TXQ_PAUSE_Q3_SET(x)                                  (((0 | (x)) << MAC_QCU_TXQ_PAUSE_Q3_LSB) & MAC_QCU_TXQ_PAUSE_Q3_MASK)
#define MAC_QCU_TXQ_PAUSE_Q3_RESET                                   0
#define MAC_QCU_TXQ_PAUSE_Q2_MSB                                     2
#define MAC_QCU_TXQ_PAUSE_Q2_LSB                                     2
#define MAC_QCU_TXQ_PAUSE_Q2_MASK                                    0x00000004
#define MAC_QCU_TXQ_PAUSE_Q2_GET(x)                                  (((x) & MAC_QCU_TXQ_PAUSE_Q2_MASK) >> MAC_QCU_TXQ_PAUSE_Q2_LSB)
#define MAC_QCU_TXQ_PAUSE_Q2_SET(x)                                  (((0 | (x)) << MAC_QCU_TXQ_PAUSE_Q2_LSB) & MAC_QCU_TXQ_PAUSE_Q2_MASK)
#define MAC_QCU_TXQ_PAUSE_Q2_RESET                                   0
#define MAC_QCU_TXQ_PAUSE_Q1_MSB                                     1
#define MAC_QCU_TXQ_PAUSE_Q1_LSB                                     1
#define MAC_QCU_TXQ_PAUSE_Q1_MASK                                    0x00000002
#define MAC_QCU_TXQ_PAUSE_Q1_GET(x)                                  (((x) & MAC_QCU_TXQ_PAUSE_Q1_MASK) >> MAC_QCU_TXQ_PAUSE_Q1_LSB)
#define MAC_QCU_TXQ_PAUSE_Q1_SET(x)                                  (((0 | (x)) << MAC_QCU_TXQ_PAUSE_Q1_LSB) & MAC_QCU_TXQ_PAUSE_Q1_MASK)
#define MAC_QCU_TXQ_PAUSE_Q1_RESET                                   0
#define MAC_QCU_TXQ_PAUSE_Q0_MSB                                     0
#define MAC_QCU_TXQ_PAUSE_Q0_LSB                                     0
#define MAC_QCU_TXQ_PAUSE_Q0_MASK                                    0x00000001
#define MAC_QCU_TXQ_PAUSE_Q0_GET(x)                                  (((x) & MAC_QCU_TXQ_PAUSE_Q0_MASK) >> MAC_QCU_TXQ_PAUSE_Q0_LSB)
#define MAC_QCU_TXQ_PAUSE_Q0_SET(x)                                  (((0 | (x)) << MAC_QCU_TXQ_PAUSE_Q0_LSB) & MAC_QCU_TXQ_PAUSE_Q0_MASK)
#define MAC_QCU_TXQ_PAUSE_Q0_RESET                                   0
#define MAC_QCU_TXQ_PAUSE_ADDRESS                                    0x0a4c
#define MAC_QCU_TXQ_PAUSE_HW_MASK                                    0x000003ff
#define MAC_QCU_TXQ_PAUSE_SW_MASK                                    0x000003ff
#define MAC_QCU_TXQ_PAUSE_HW_WRITE_MASK                              0x000003ff
#define MAC_QCU_TXQ_PAUSE_SW_WRITE_MASK                              0x000003ff
#define MAC_QCU_TXQ_PAUSE_RSTMASK                                    0xffffffff
#define MAC_QCU_TXQ_PAUSE_RESET                                      0x00000000


#endif /* _MAC_QCU_REG_H_ */
