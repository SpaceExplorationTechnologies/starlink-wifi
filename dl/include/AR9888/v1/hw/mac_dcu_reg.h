//                                                                             
// File:       ./mac_dcu_reg.vrh                                               
// Creator:    shung                                                           
// Time:       Monday Apr 23, 2012 [6:25:49 pm]                                
//                                                                             
// Path:       /trees/shung/shung-dev/chips/peregrine/1.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux/blueprint -odir . -codegen   
//             ath_vrh.codegen -ath_vrh -Wdesc -I                              
//             /trees/shung/shung-dev/chips/peregrine/1.0/blueprint/sysconfig  
//             mac_dcu_reg.rdl                                                 
//                                                                             
// Sources:    /trees/shung/shung-dev/chips/peregrine/1.0/ip/athr/wifi/rtl/./mac/shared/blueprint/mac_dcu_reg.rdl
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


#ifndef _MAC_DCU_REG_H_
#define _MAC_DCU_REG_H_
// 0x1000 (MAC_DCU_QCUMASK_0)
#define MAC_DCU_QCUMASK_0_DATA_MSB                                   9
#define MAC_DCU_QCUMASK_0_DATA_LSB                                   0
#define MAC_DCU_QCUMASK_0_DATA_MASK                                  0x000003ff
#define MAC_DCU_QCUMASK_0_DATA_GET(x)                                (((x) & MAC_DCU_QCUMASK_0_DATA_MASK) >> MAC_DCU_QCUMASK_0_DATA_LSB)
#define MAC_DCU_QCUMASK_0_DATA_SET(x)                                (((0 | (x)) << MAC_DCU_QCUMASK_0_DATA_LSB) & MAC_DCU_QCUMASK_0_DATA_MASK)
#define MAC_DCU_QCUMASK_0_DATA_RESET                                 0
#define MAC_DCU_QCUMASK_0_ADDRESS                                    0x1000
#define MAC_DCU_QCUMASK_ADDRESS                                      MAC_DCU_QCUMASK_0_ADDRESS
#define MAC_DCU_QCUMASK_0_HW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_0_SW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_0_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_QCUMASK_0_SW_WRITE_MASK                              0x000003ff
#define MAC_DCU_QCUMASK_0_RSTMASK                                    0xffffffff
#define MAC_DCU_QCUMASK_0_RESET                                      0x00000000

// 0x1004 (MAC_DCU_QCUMASK_1)
#define MAC_DCU_QCUMASK_1_DATA_MSB                                   9
#define MAC_DCU_QCUMASK_1_DATA_LSB                                   0
#define MAC_DCU_QCUMASK_1_DATA_MASK                                  0x000003ff
#define MAC_DCU_QCUMASK_1_DATA_GET(x)                                (((x) & MAC_DCU_QCUMASK_1_DATA_MASK) >> MAC_DCU_QCUMASK_1_DATA_LSB)
#define MAC_DCU_QCUMASK_1_DATA_SET(x)                                (((0 | (x)) << MAC_DCU_QCUMASK_1_DATA_LSB) & MAC_DCU_QCUMASK_1_DATA_MASK)
#define MAC_DCU_QCUMASK_1_DATA_RESET                                 0
#define MAC_DCU_QCUMASK_1_ADDRESS                                    0x1004
#define MAC_DCU_QCUMASK_1_HW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_1_SW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_1_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_QCUMASK_1_SW_WRITE_MASK                              0x000003ff
#define MAC_DCU_QCUMASK_1_RSTMASK                                    0xffffffff
#define MAC_DCU_QCUMASK_1_RESET                                      0x00000000

// 0x1008 (MAC_DCU_QCUMASK_2)
#define MAC_DCU_QCUMASK_2_DATA_MSB                                   9
#define MAC_DCU_QCUMASK_2_DATA_LSB                                   0
#define MAC_DCU_QCUMASK_2_DATA_MASK                                  0x000003ff
#define MAC_DCU_QCUMASK_2_DATA_GET(x)                                (((x) & MAC_DCU_QCUMASK_2_DATA_MASK) >> MAC_DCU_QCUMASK_2_DATA_LSB)
#define MAC_DCU_QCUMASK_2_DATA_SET(x)                                (((0 | (x)) << MAC_DCU_QCUMASK_2_DATA_LSB) & MAC_DCU_QCUMASK_2_DATA_MASK)
#define MAC_DCU_QCUMASK_2_DATA_RESET                                 0
#define MAC_DCU_QCUMASK_2_ADDRESS                                    0x1008
#define MAC_DCU_QCUMASK_2_HW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_2_SW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_2_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_QCUMASK_2_SW_WRITE_MASK                              0x000003ff
#define MAC_DCU_QCUMASK_2_RSTMASK                                    0xffffffff
#define MAC_DCU_QCUMASK_2_RESET                                      0x00000000

// 0x100c (MAC_DCU_QCUMASK_3)
#define MAC_DCU_QCUMASK_3_DATA_MSB                                   9
#define MAC_DCU_QCUMASK_3_DATA_LSB                                   0
#define MAC_DCU_QCUMASK_3_DATA_MASK                                  0x000003ff
#define MAC_DCU_QCUMASK_3_DATA_GET(x)                                (((x) & MAC_DCU_QCUMASK_3_DATA_MASK) >> MAC_DCU_QCUMASK_3_DATA_LSB)
#define MAC_DCU_QCUMASK_3_DATA_SET(x)                                (((0 | (x)) << MAC_DCU_QCUMASK_3_DATA_LSB) & MAC_DCU_QCUMASK_3_DATA_MASK)
#define MAC_DCU_QCUMASK_3_DATA_RESET                                 0
#define MAC_DCU_QCUMASK_3_ADDRESS                                    0x100c
#define MAC_DCU_QCUMASK_3_HW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_3_SW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_3_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_QCUMASK_3_SW_WRITE_MASK                              0x000003ff
#define MAC_DCU_QCUMASK_3_RSTMASK                                    0xffffffff
#define MAC_DCU_QCUMASK_3_RESET                                      0x00000000

// 0x1010 (MAC_DCU_QCUMASK_4)
#define MAC_DCU_QCUMASK_4_DATA_MSB                                   9
#define MAC_DCU_QCUMASK_4_DATA_LSB                                   0
#define MAC_DCU_QCUMASK_4_DATA_MASK                                  0x000003ff
#define MAC_DCU_QCUMASK_4_DATA_GET(x)                                (((x) & MAC_DCU_QCUMASK_4_DATA_MASK) >> MAC_DCU_QCUMASK_4_DATA_LSB)
#define MAC_DCU_QCUMASK_4_DATA_SET(x)                                (((0 | (x)) << MAC_DCU_QCUMASK_4_DATA_LSB) & MAC_DCU_QCUMASK_4_DATA_MASK)
#define MAC_DCU_QCUMASK_4_DATA_RESET                                 0
#define MAC_DCU_QCUMASK_4_ADDRESS                                    0x1010
#define MAC_DCU_QCUMASK_4_HW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_4_SW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_4_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_QCUMASK_4_SW_WRITE_MASK                              0x000003ff
#define MAC_DCU_QCUMASK_4_RSTMASK                                    0xffffffff
#define MAC_DCU_QCUMASK_4_RESET                                      0x00000000

// 0x1014 (MAC_DCU_QCUMASK_5)
#define MAC_DCU_QCUMASK_5_DATA_MSB                                   9
#define MAC_DCU_QCUMASK_5_DATA_LSB                                   0
#define MAC_DCU_QCUMASK_5_DATA_MASK                                  0x000003ff
#define MAC_DCU_QCUMASK_5_DATA_GET(x)                                (((x) & MAC_DCU_QCUMASK_5_DATA_MASK) >> MAC_DCU_QCUMASK_5_DATA_LSB)
#define MAC_DCU_QCUMASK_5_DATA_SET(x)                                (((0 | (x)) << MAC_DCU_QCUMASK_5_DATA_LSB) & MAC_DCU_QCUMASK_5_DATA_MASK)
#define MAC_DCU_QCUMASK_5_DATA_RESET                                 0
#define MAC_DCU_QCUMASK_5_ADDRESS                                    0x1014
#define MAC_DCU_QCUMASK_5_HW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_5_SW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_5_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_QCUMASK_5_SW_WRITE_MASK                              0x000003ff
#define MAC_DCU_QCUMASK_5_RSTMASK                                    0xffffffff
#define MAC_DCU_QCUMASK_5_RESET                                      0x00000000

// 0x1018 (MAC_DCU_QCUMASK_6)
#define MAC_DCU_QCUMASK_6_DATA_MSB                                   9
#define MAC_DCU_QCUMASK_6_DATA_LSB                                   0
#define MAC_DCU_QCUMASK_6_DATA_MASK                                  0x000003ff
#define MAC_DCU_QCUMASK_6_DATA_GET(x)                                (((x) & MAC_DCU_QCUMASK_6_DATA_MASK) >> MAC_DCU_QCUMASK_6_DATA_LSB)
#define MAC_DCU_QCUMASK_6_DATA_SET(x)                                (((0 | (x)) << MAC_DCU_QCUMASK_6_DATA_LSB) & MAC_DCU_QCUMASK_6_DATA_MASK)
#define MAC_DCU_QCUMASK_6_DATA_RESET                                 0
#define MAC_DCU_QCUMASK_6_ADDRESS                                    0x1018
#define MAC_DCU_QCUMASK_6_HW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_6_SW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_6_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_QCUMASK_6_SW_WRITE_MASK                              0x000003ff
#define MAC_DCU_QCUMASK_6_RSTMASK                                    0xffffffff
#define MAC_DCU_QCUMASK_6_RESET                                      0x00000000

// 0x101c (MAC_DCU_QCUMASK_7)
#define MAC_DCU_QCUMASK_7_DATA_MSB                                   9
#define MAC_DCU_QCUMASK_7_DATA_LSB                                   0
#define MAC_DCU_QCUMASK_7_DATA_MASK                                  0x000003ff
#define MAC_DCU_QCUMASK_7_DATA_GET(x)                                (((x) & MAC_DCU_QCUMASK_7_DATA_MASK) >> MAC_DCU_QCUMASK_7_DATA_LSB)
#define MAC_DCU_QCUMASK_7_DATA_SET(x)                                (((0 | (x)) << MAC_DCU_QCUMASK_7_DATA_LSB) & MAC_DCU_QCUMASK_7_DATA_MASK)
#define MAC_DCU_QCUMASK_7_DATA_RESET                                 0
#define MAC_DCU_QCUMASK_7_ADDRESS                                    0x101c
#define MAC_DCU_QCUMASK_7_HW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_7_SW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_7_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_QCUMASK_7_SW_WRITE_MASK                              0x000003ff
#define MAC_DCU_QCUMASK_7_RSTMASK                                    0xffffffff
#define MAC_DCU_QCUMASK_7_RESET                                      0x00000000

// 0x1020 (MAC_DCU_QCUMASK_8)
#define MAC_DCU_QCUMASK_8_DATA_MSB                                   9
#define MAC_DCU_QCUMASK_8_DATA_LSB                                   0
#define MAC_DCU_QCUMASK_8_DATA_MASK                                  0x000003ff
#define MAC_DCU_QCUMASK_8_DATA_GET(x)                                (((x) & MAC_DCU_QCUMASK_8_DATA_MASK) >> MAC_DCU_QCUMASK_8_DATA_LSB)
#define MAC_DCU_QCUMASK_8_DATA_SET(x)                                (((0 | (x)) << MAC_DCU_QCUMASK_8_DATA_LSB) & MAC_DCU_QCUMASK_8_DATA_MASK)
#define MAC_DCU_QCUMASK_8_DATA_RESET                                 0
#define MAC_DCU_QCUMASK_8_ADDRESS                                    0x1020
#define MAC_DCU_QCUMASK_8_HW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_8_SW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_8_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_QCUMASK_8_SW_WRITE_MASK                              0x000003ff
#define MAC_DCU_QCUMASK_8_RSTMASK                                    0xffffffff
#define MAC_DCU_QCUMASK_8_RESET                                      0x00000000

// 0x1024 (MAC_DCU_QCUMASK_9)
#define MAC_DCU_QCUMASK_9_DATA_MSB                                   9
#define MAC_DCU_QCUMASK_9_DATA_LSB                                   0
#define MAC_DCU_QCUMASK_9_DATA_MASK                                  0x000003ff
#define MAC_DCU_QCUMASK_9_DATA_GET(x)                                (((x) & MAC_DCU_QCUMASK_9_DATA_MASK) >> MAC_DCU_QCUMASK_9_DATA_LSB)
#define MAC_DCU_QCUMASK_9_DATA_SET(x)                                (((0 | (x)) << MAC_DCU_QCUMASK_9_DATA_LSB) & MAC_DCU_QCUMASK_9_DATA_MASK)
#define MAC_DCU_QCUMASK_9_DATA_RESET                                 0
#define MAC_DCU_QCUMASK_9_ADDRESS                                    0x1024
#define MAC_DCU_QCUMASK_9_HW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_9_SW_MASK                                    0x000003ff
#define MAC_DCU_QCUMASK_9_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_QCUMASK_9_SW_WRITE_MASK                              0x000003ff
#define MAC_DCU_QCUMASK_9_RSTMASK                                    0xffffffff
#define MAC_DCU_QCUMASK_9_RESET                                      0x00000000

// 0x1030 (MAC_DCU_GBL_IFS_SIFS)
#define MAC_DCU_GBL_IFS_SIFS_DURATION_MSB                            15
#define MAC_DCU_GBL_IFS_SIFS_DURATION_LSB                            0
#define MAC_DCU_GBL_IFS_SIFS_DURATION_MASK                           0x0000ffff
#define MAC_DCU_GBL_IFS_SIFS_DURATION_GET(x)                         (((x) & MAC_DCU_GBL_IFS_SIFS_DURATION_MASK) >> MAC_DCU_GBL_IFS_SIFS_DURATION_LSB)
#define MAC_DCU_GBL_IFS_SIFS_DURATION_SET(x)                         (((0 | (x)) << MAC_DCU_GBL_IFS_SIFS_DURATION_LSB) & MAC_DCU_GBL_IFS_SIFS_DURATION_MASK)
#define MAC_DCU_GBL_IFS_SIFS_DURATION_RESET                          640
#define MAC_DCU_GBL_IFS_SIFS_ADDRESS                                 0x1030
#define MAC_DCU_GBL_IFS_SIFS_HW_MASK                                 0x0000ffff
#define MAC_DCU_GBL_IFS_SIFS_SW_MASK                                 0x0000ffff
#define MAC_DCU_GBL_IFS_SIFS_HW_WRITE_MASK                           0x00000000
#define MAC_DCU_GBL_IFS_SIFS_SW_WRITE_MASK                           0x0000ffff
#define MAC_DCU_GBL_IFS_SIFS_RSTMASK                                 0xffffffff
#define MAC_DCU_GBL_IFS_SIFS_RESET                                   0x00000280

// 0x1038 (MAC_DCU_TXFILTER_DCU0_31_0)
#define MAC_DCU_TXFILTER_DCU0_31_0_DATA_MSB                          31
#define MAC_DCU_TXFILTER_DCU0_31_0_DATA_LSB                          0
#define MAC_DCU_TXFILTER_DCU0_31_0_DATA_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU0_31_0_DATA_GET(x)                       (((x) & MAC_DCU_TXFILTER_DCU0_31_0_DATA_MASK) >> MAC_DCU_TXFILTER_DCU0_31_0_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU0_31_0_DATA_SET(x)                       (((0 | (x)) << MAC_DCU_TXFILTER_DCU0_31_0_DATA_LSB) & MAC_DCU_TXFILTER_DCU0_31_0_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU0_31_0_DATA_RESET                        0
#define MAC_DCU_TXFILTER_DCU0_31_0_ADDRESS                           0x1038
#define MAC_DCU_TXFILTER_DCU0_31_0_HW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU0_31_0_SW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU0_31_0_HW_WRITE_MASK                     0x00000000
#define MAC_DCU_TXFILTER_DCU0_31_0_SW_WRITE_MASK                     0xffffffff
#define MAC_DCU_TXFILTER_DCU0_31_0_RSTMASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU0_31_0_RESET                             0x00000000

// 0x103c (MAC_DCU_TXFILTER_DCU8_31_0)
#define MAC_DCU_TXFILTER_DCU8_31_0_DATA_MSB                          31
#define MAC_DCU_TXFILTER_DCU8_31_0_DATA_LSB                          0
#define MAC_DCU_TXFILTER_DCU8_31_0_DATA_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU8_31_0_DATA_GET(x)                       (((x) & MAC_DCU_TXFILTER_DCU8_31_0_DATA_MASK) >> MAC_DCU_TXFILTER_DCU8_31_0_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU8_31_0_DATA_SET(x)                       (((0 | (x)) << MAC_DCU_TXFILTER_DCU8_31_0_DATA_LSB) & MAC_DCU_TXFILTER_DCU8_31_0_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU8_31_0_DATA_RESET                        0
#define MAC_DCU_TXFILTER_DCU8_31_0_ADDRESS                           0x103c
#define MAC_DCU_TXFILTER_DCU8_31_0_HW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU8_31_0_SW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU8_31_0_HW_WRITE_MASK                     0xffffffff
#define MAC_DCU_TXFILTER_DCU8_31_0_SW_WRITE_MASK                     0x00000000
#define MAC_DCU_TXFILTER_DCU8_31_0_RSTMASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU8_31_0_RESET                             0x00000000

// 0x1040 (MAC_DCU_LCL_IFS_0)
#define MAC_DCU_LCL_IFS_0_LONG_AIFS_MSB                              28
#define MAC_DCU_LCL_IFS_0_LONG_AIFS_LSB                              28
#define MAC_DCU_LCL_IFS_0_LONG_AIFS_MASK                             0x10000000
#define MAC_DCU_LCL_IFS_0_LONG_AIFS_GET(x)                           (((x) & MAC_DCU_LCL_IFS_0_LONG_AIFS_MASK) >> MAC_DCU_LCL_IFS_0_LONG_AIFS_LSB)
#define MAC_DCU_LCL_IFS_0_LONG_AIFS_SET(x)                           (((0 | (x)) << MAC_DCU_LCL_IFS_0_LONG_AIFS_LSB) & MAC_DCU_LCL_IFS_0_LONG_AIFS_MASK)
#define MAC_DCU_LCL_IFS_0_LONG_AIFS_RESET                            0
#define MAC_DCU_LCL_IFS_0_AIFS_MSB                                   27
#define MAC_DCU_LCL_IFS_0_AIFS_LSB                                   20
#define MAC_DCU_LCL_IFS_0_AIFS_MASK                                  0x0ff00000
#define MAC_DCU_LCL_IFS_0_AIFS_GET(x)                                (((x) & MAC_DCU_LCL_IFS_0_AIFS_MASK) >> MAC_DCU_LCL_IFS_0_AIFS_LSB)
#define MAC_DCU_LCL_IFS_0_AIFS_SET(x)                                (((0 | (x)) << MAC_DCU_LCL_IFS_0_AIFS_LSB) & MAC_DCU_LCL_IFS_0_AIFS_MASK)
#define MAC_DCU_LCL_IFS_0_AIFS_RESET                                 0
#define MAC_DCU_LCL_IFS_0_CW_MAX_MSB                                 19
#define MAC_DCU_LCL_IFS_0_CW_MAX_LSB                                 10
#define MAC_DCU_LCL_IFS_0_CW_MAX_MASK                                0x000ffc00
#define MAC_DCU_LCL_IFS_0_CW_MAX_GET(x)                              (((x) & MAC_DCU_LCL_IFS_0_CW_MAX_MASK) >> MAC_DCU_LCL_IFS_0_CW_MAX_LSB)
#define MAC_DCU_LCL_IFS_0_CW_MAX_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_0_CW_MAX_LSB) & MAC_DCU_LCL_IFS_0_CW_MAX_MASK)
#define MAC_DCU_LCL_IFS_0_CW_MAX_RESET                               0
#define MAC_DCU_LCL_IFS_0_CW_MIN_MSB                                 9
#define MAC_DCU_LCL_IFS_0_CW_MIN_LSB                                 0
#define MAC_DCU_LCL_IFS_0_CW_MIN_MASK                                0x000003ff
#define MAC_DCU_LCL_IFS_0_CW_MIN_GET(x)                              (((x) & MAC_DCU_LCL_IFS_0_CW_MIN_MASK) >> MAC_DCU_LCL_IFS_0_CW_MIN_LSB)
#define MAC_DCU_LCL_IFS_0_CW_MIN_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_0_CW_MIN_LSB) & MAC_DCU_LCL_IFS_0_CW_MIN_MASK)
#define MAC_DCU_LCL_IFS_0_CW_MIN_RESET                               0
#define MAC_DCU_LCL_IFS_0_ADDRESS                                    0x1040
#define MAC_DCU_LCL_IFS_ADDRESS                                      MAC_DCU_LCL_IFS_0_ADDRESS
#define MAC_DCU_LCL_IFS_0_HW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_0_SW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_0_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_LCL_IFS_0_SW_WRITE_MASK                              0x1fffffff
#define MAC_DCU_LCL_IFS_0_RSTMASK                                    0xffffffff
#define MAC_DCU_LCL_IFS_0_RESET                                      0x00000000

// 0x1044 (MAC_DCU_LCL_IFS_1)
#define MAC_DCU_LCL_IFS_1_LONG_AIFS_MSB                              28
#define MAC_DCU_LCL_IFS_1_LONG_AIFS_LSB                              28
#define MAC_DCU_LCL_IFS_1_LONG_AIFS_MASK                             0x10000000
#define MAC_DCU_LCL_IFS_1_LONG_AIFS_GET(x)                           (((x) & MAC_DCU_LCL_IFS_1_LONG_AIFS_MASK) >> MAC_DCU_LCL_IFS_1_LONG_AIFS_LSB)
#define MAC_DCU_LCL_IFS_1_LONG_AIFS_SET(x)                           (((0 | (x)) << MAC_DCU_LCL_IFS_1_LONG_AIFS_LSB) & MAC_DCU_LCL_IFS_1_LONG_AIFS_MASK)
#define MAC_DCU_LCL_IFS_1_LONG_AIFS_RESET                            0
#define MAC_DCU_LCL_IFS_1_AIFS_MSB                                   27
#define MAC_DCU_LCL_IFS_1_AIFS_LSB                                   20
#define MAC_DCU_LCL_IFS_1_AIFS_MASK                                  0x0ff00000
#define MAC_DCU_LCL_IFS_1_AIFS_GET(x)                                (((x) & MAC_DCU_LCL_IFS_1_AIFS_MASK) >> MAC_DCU_LCL_IFS_1_AIFS_LSB)
#define MAC_DCU_LCL_IFS_1_AIFS_SET(x)                                (((0 | (x)) << MAC_DCU_LCL_IFS_1_AIFS_LSB) & MAC_DCU_LCL_IFS_1_AIFS_MASK)
#define MAC_DCU_LCL_IFS_1_AIFS_RESET                                 0
#define MAC_DCU_LCL_IFS_1_CW_MAX_MSB                                 19
#define MAC_DCU_LCL_IFS_1_CW_MAX_LSB                                 10
#define MAC_DCU_LCL_IFS_1_CW_MAX_MASK                                0x000ffc00
#define MAC_DCU_LCL_IFS_1_CW_MAX_GET(x)                              (((x) & MAC_DCU_LCL_IFS_1_CW_MAX_MASK) >> MAC_DCU_LCL_IFS_1_CW_MAX_LSB)
#define MAC_DCU_LCL_IFS_1_CW_MAX_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_1_CW_MAX_LSB) & MAC_DCU_LCL_IFS_1_CW_MAX_MASK)
#define MAC_DCU_LCL_IFS_1_CW_MAX_RESET                               0
#define MAC_DCU_LCL_IFS_1_CW_MIN_MSB                                 9
#define MAC_DCU_LCL_IFS_1_CW_MIN_LSB                                 0
#define MAC_DCU_LCL_IFS_1_CW_MIN_MASK                                0x000003ff
#define MAC_DCU_LCL_IFS_1_CW_MIN_GET(x)                              (((x) & MAC_DCU_LCL_IFS_1_CW_MIN_MASK) >> MAC_DCU_LCL_IFS_1_CW_MIN_LSB)
#define MAC_DCU_LCL_IFS_1_CW_MIN_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_1_CW_MIN_LSB) & MAC_DCU_LCL_IFS_1_CW_MIN_MASK)
#define MAC_DCU_LCL_IFS_1_CW_MIN_RESET                               0
#define MAC_DCU_LCL_IFS_1_ADDRESS                                    0x1044
#define MAC_DCU_LCL_IFS_1_HW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_1_SW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_1_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_LCL_IFS_1_SW_WRITE_MASK                              0x1fffffff
#define MAC_DCU_LCL_IFS_1_RSTMASK                                    0xffffffff
#define MAC_DCU_LCL_IFS_1_RESET                                      0x00000000

// 0x1048 (MAC_DCU_LCL_IFS_2)
#define MAC_DCU_LCL_IFS_2_LONG_AIFS_MSB                              28
#define MAC_DCU_LCL_IFS_2_LONG_AIFS_LSB                              28
#define MAC_DCU_LCL_IFS_2_LONG_AIFS_MASK                             0x10000000
#define MAC_DCU_LCL_IFS_2_LONG_AIFS_GET(x)                           (((x) & MAC_DCU_LCL_IFS_2_LONG_AIFS_MASK) >> MAC_DCU_LCL_IFS_2_LONG_AIFS_LSB)
#define MAC_DCU_LCL_IFS_2_LONG_AIFS_SET(x)                           (((0 | (x)) << MAC_DCU_LCL_IFS_2_LONG_AIFS_LSB) & MAC_DCU_LCL_IFS_2_LONG_AIFS_MASK)
#define MAC_DCU_LCL_IFS_2_LONG_AIFS_RESET                            0
#define MAC_DCU_LCL_IFS_2_AIFS_MSB                                   27
#define MAC_DCU_LCL_IFS_2_AIFS_LSB                                   20
#define MAC_DCU_LCL_IFS_2_AIFS_MASK                                  0x0ff00000
#define MAC_DCU_LCL_IFS_2_AIFS_GET(x)                                (((x) & MAC_DCU_LCL_IFS_2_AIFS_MASK) >> MAC_DCU_LCL_IFS_2_AIFS_LSB)
#define MAC_DCU_LCL_IFS_2_AIFS_SET(x)                                (((0 | (x)) << MAC_DCU_LCL_IFS_2_AIFS_LSB) & MAC_DCU_LCL_IFS_2_AIFS_MASK)
#define MAC_DCU_LCL_IFS_2_AIFS_RESET                                 0
#define MAC_DCU_LCL_IFS_2_CW_MAX_MSB                                 19
#define MAC_DCU_LCL_IFS_2_CW_MAX_LSB                                 10
#define MAC_DCU_LCL_IFS_2_CW_MAX_MASK                                0x000ffc00
#define MAC_DCU_LCL_IFS_2_CW_MAX_GET(x)                              (((x) & MAC_DCU_LCL_IFS_2_CW_MAX_MASK) >> MAC_DCU_LCL_IFS_2_CW_MAX_LSB)
#define MAC_DCU_LCL_IFS_2_CW_MAX_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_2_CW_MAX_LSB) & MAC_DCU_LCL_IFS_2_CW_MAX_MASK)
#define MAC_DCU_LCL_IFS_2_CW_MAX_RESET                               0
#define MAC_DCU_LCL_IFS_2_CW_MIN_MSB                                 9
#define MAC_DCU_LCL_IFS_2_CW_MIN_LSB                                 0
#define MAC_DCU_LCL_IFS_2_CW_MIN_MASK                                0x000003ff
#define MAC_DCU_LCL_IFS_2_CW_MIN_GET(x)                              (((x) & MAC_DCU_LCL_IFS_2_CW_MIN_MASK) >> MAC_DCU_LCL_IFS_2_CW_MIN_LSB)
#define MAC_DCU_LCL_IFS_2_CW_MIN_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_2_CW_MIN_LSB) & MAC_DCU_LCL_IFS_2_CW_MIN_MASK)
#define MAC_DCU_LCL_IFS_2_CW_MIN_RESET                               0
#define MAC_DCU_LCL_IFS_2_ADDRESS                                    0x1048
#define MAC_DCU_LCL_IFS_2_HW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_2_SW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_2_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_LCL_IFS_2_SW_WRITE_MASK                              0x1fffffff
#define MAC_DCU_LCL_IFS_2_RSTMASK                                    0xffffffff
#define MAC_DCU_LCL_IFS_2_RESET                                      0x00000000

// 0x104c (MAC_DCU_LCL_IFS_3)
#define MAC_DCU_LCL_IFS_3_LONG_AIFS_MSB                              28
#define MAC_DCU_LCL_IFS_3_LONG_AIFS_LSB                              28
#define MAC_DCU_LCL_IFS_3_LONG_AIFS_MASK                             0x10000000
#define MAC_DCU_LCL_IFS_3_LONG_AIFS_GET(x)                           (((x) & MAC_DCU_LCL_IFS_3_LONG_AIFS_MASK) >> MAC_DCU_LCL_IFS_3_LONG_AIFS_LSB)
#define MAC_DCU_LCL_IFS_3_LONG_AIFS_SET(x)                           (((0 | (x)) << MAC_DCU_LCL_IFS_3_LONG_AIFS_LSB) & MAC_DCU_LCL_IFS_3_LONG_AIFS_MASK)
#define MAC_DCU_LCL_IFS_3_LONG_AIFS_RESET                            0
#define MAC_DCU_LCL_IFS_3_AIFS_MSB                                   27
#define MAC_DCU_LCL_IFS_3_AIFS_LSB                                   20
#define MAC_DCU_LCL_IFS_3_AIFS_MASK                                  0x0ff00000
#define MAC_DCU_LCL_IFS_3_AIFS_GET(x)                                (((x) & MAC_DCU_LCL_IFS_3_AIFS_MASK) >> MAC_DCU_LCL_IFS_3_AIFS_LSB)
#define MAC_DCU_LCL_IFS_3_AIFS_SET(x)                                (((0 | (x)) << MAC_DCU_LCL_IFS_3_AIFS_LSB) & MAC_DCU_LCL_IFS_3_AIFS_MASK)
#define MAC_DCU_LCL_IFS_3_AIFS_RESET                                 0
#define MAC_DCU_LCL_IFS_3_CW_MAX_MSB                                 19
#define MAC_DCU_LCL_IFS_3_CW_MAX_LSB                                 10
#define MAC_DCU_LCL_IFS_3_CW_MAX_MASK                                0x000ffc00
#define MAC_DCU_LCL_IFS_3_CW_MAX_GET(x)                              (((x) & MAC_DCU_LCL_IFS_3_CW_MAX_MASK) >> MAC_DCU_LCL_IFS_3_CW_MAX_LSB)
#define MAC_DCU_LCL_IFS_3_CW_MAX_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_3_CW_MAX_LSB) & MAC_DCU_LCL_IFS_3_CW_MAX_MASK)
#define MAC_DCU_LCL_IFS_3_CW_MAX_RESET                               0
#define MAC_DCU_LCL_IFS_3_CW_MIN_MSB                                 9
#define MAC_DCU_LCL_IFS_3_CW_MIN_LSB                                 0
#define MAC_DCU_LCL_IFS_3_CW_MIN_MASK                                0x000003ff
#define MAC_DCU_LCL_IFS_3_CW_MIN_GET(x)                              (((x) & MAC_DCU_LCL_IFS_3_CW_MIN_MASK) >> MAC_DCU_LCL_IFS_3_CW_MIN_LSB)
#define MAC_DCU_LCL_IFS_3_CW_MIN_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_3_CW_MIN_LSB) & MAC_DCU_LCL_IFS_3_CW_MIN_MASK)
#define MAC_DCU_LCL_IFS_3_CW_MIN_RESET                               0
#define MAC_DCU_LCL_IFS_3_ADDRESS                                    0x104c
#define MAC_DCU_LCL_IFS_3_HW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_3_SW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_3_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_LCL_IFS_3_SW_WRITE_MASK                              0x1fffffff
#define MAC_DCU_LCL_IFS_3_RSTMASK                                    0xffffffff
#define MAC_DCU_LCL_IFS_3_RESET                                      0x00000000

// 0x1050 (MAC_DCU_LCL_IFS_4)
#define MAC_DCU_LCL_IFS_4_LONG_AIFS_MSB                              28
#define MAC_DCU_LCL_IFS_4_LONG_AIFS_LSB                              28
#define MAC_DCU_LCL_IFS_4_LONG_AIFS_MASK                             0x10000000
#define MAC_DCU_LCL_IFS_4_LONG_AIFS_GET(x)                           (((x) & MAC_DCU_LCL_IFS_4_LONG_AIFS_MASK) >> MAC_DCU_LCL_IFS_4_LONG_AIFS_LSB)
#define MAC_DCU_LCL_IFS_4_LONG_AIFS_SET(x)                           (((0 | (x)) << MAC_DCU_LCL_IFS_4_LONG_AIFS_LSB) & MAC_DCU_LCL_IFS_4_LONG_AIFS_MASK)
#define MAC_DCU_LCL_IFS_4_LONG_AIFS_RESET                            0
#define MAC_DCU_LCL_IFS_4_AIFS_MSB                                   27
#define MAC_DCU_LCL_IFS_4_AIFS_LSB                                   20
#define MAC_DCU_LCL_IFS_4_AIFS_MASK                                  0x0ff00000
#define MAC_DCU_LCL_IFS_4_AIFS_GET(x)                                (((x) & MAC_DCU_LCL_IFS_4_AIFS_MASK) >> MAC_DCU_LCL_IFS_4_AIFS_LSB)
#define MAC_DCU_LCL_IFS_4_AIFS_SET(x)                                (((0 | (x)) << MAC_DCU_LCL_IFS_4_AIFS_LSB) & MAC_DCU_LCL_IFS_4_AIFS_MASK)
#define MAC_DCU_LCL_IFS_4_AIFS_RESET                                 0
#define MAC_DCU_LCL_IFS_4_CW_MAX_MSB                                 19
#define MAC_DCU_LCL_IFS_4_CW_MAX_LSB                                 10
#define MAC_DCU_LCL_IFS_4_CW_MAX_MASK                                0x000ffc00
#define MAC_DCU_LCL_IFS_4_CW_MAX_GET(x)                              (((x) & MAC_DCU_LCL_IFS_4_CW_MAX_MASK) >> MAC_DCU_LCL_IFS_4_CW_MAX_LSB)
#define MAC_DCU_LCL_IFS_4_CW_MAX_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_4_CW_MAX_LSB) & MAC_DCU_LCL_IFS_4_CW_MAX_MASK)
#define MAC_DCU_LCL_IFS_4_CW_MAX_RESET                               0
#define MAC_DCU_LCL_IFS_4_CW_MIN_MSB                                 9
#define MAC_DCU_LCL_IFS_4_CW_MIN_LSB                                 0
#define MAC_DCU_LCL_IFS_4_CW_MIN_MASK                                0x000003ff
#define MAC_DCU_LCL_IFS_4_CW_MIN_GET(x)                              (((x) & MAC_DCU_LCL_IFS_4_CW_MIN_MASK) >> MAC_DCU_LCL_IFS_4_CW_MIN_LSB)
#define MAC_DCU_LCL_IFS_4_CW_MIN_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_4_CW_MIN_LSB) & MAC_DCU_LCL_IFS_4_CW_MIN_MASK)
#define MAC_DCU_LCL_IFS_4_CW_MIN_RESET                               0
#define MAC_DCU_LCL_IFS_4_ADDRESS                                    0x1050
#define MAC_DCU_LCL_IFS_4_HW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_4_SW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_4_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_LCL_IFS_4_SW_WRITE_MASK                              0x1fffffff
#define MAC_DCU_LCL_IFS_4_RSTMASK                                    0xffffffff
#define MAC_DCU_LCL_IFS_4_RESET                                      0x00000000

// 0x1054 (MAC_DCU_LCL_IFS_5)
#define MAC_DCU_LCL_IFS_5_LONG_AIFS_MSB                              28
#define MAC_DCU_LCL_IFS_5_LONG_AIFS_LSB                              28
#define MAC_DCU_LCL_IFS_5_LONG_AIFS_MASK                             0x10000000
#define MAC_DCU_LCL_IFS_5_LONG_AIFS_GET(x)                           (((x) & MAC_DCU_LCL_IFS_5_LONG_AIFS_MASK) >> MAC_DCU_LCL_IFS_5_LONG_AIFS_LSB)
#define MAC_DCU_LCL_IFS_5_LONG_AIFS_SET(x)                           (((0 | (x)) << MAC_DCU_LCL_IFS_5_LONG_AIFS_LSB) & MAC_DCU_LCL_IFS_5_LONG_AIFS_MASK)
#define MAC_DCU_LCL_IFS_5_LONG_AIFS_RESET                            0
#define MAC_DCU_LCL_IFS_5_AIFS_MSB                                   27
#define MAC_DCU_LCL_IFS_5_AIFS_LSB                                   20
#define MAC_DCU_LCL_IFS_5_AIFS_MASK                                  0x0ff00000
#define MAC_DCU_LCL_IFS_5_AIFS_GET(x)                                (((x) & MAC_DCU_LCL_IFS_5_AIFS_MASK) >> MAC_DCU_LCL_IFS_5_AIFS_LSB)
#define MAC_DCU_LCL_IFS_5_AIFS_SET(x)                                (((0 | (x)) << MAC_DCU_LCL_IFS_5_AIFS_LSB) & MAC_DCU_LCL_IFS_5_AIFS_MASK)
#define MAC_DCU_LCL_IFS_5_AIFS_RESET                                 0
#define MAC_DCU_LCL_IFS_5_CW_MAX_MSB                                 19
#define MAC_DCU_LCL_IFS_5_CW_MAX_LSB                                 10
#define MAC_DCU_LCL_IFS_5_CW_MAX_MASK                                0x000ffc00
#define MAC_DCU_LCL_IFS_5_CW_MAX_GET(x)                              (((x) & MAC_DCU_LCL_IFS_5_CW_MAX_MASK) >> MAC_DCU_LCL_IFS_5_CW_MAX_LSB)
#define MAC_DCU_LCL_IFS_5_CW_MAX_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_5_CW_MAX_LSB) & MAC_DCU_LCL_IFS_5_CW_MAX_MASK)
#define MAC_DCU_LCL_IFS_5_CW_MAX_RESET                               0
#define MAC_DCU_LCL_IFS_5_CW_MIN_MSB                                 9
#define MAC_DCU_LCL_IFS_5_CW_MIN_LSB                                 0
#define MAC_DCU_LCL_IFS_5_CW_MIN_MASK                                0x000003ff
#define MAC_DCU_LCL_IFS_5_CW_MIN_GET(x)                              (((x) & MAC_DCU_LCL_IFS_5_CW_MIN_MASK) >> MAC_DCU_LCL_IFS_5_CW_MIN_LSB)
#define MAC_DCU_LCL_IFS_5_CW_MIN_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_5_CW_MIN_LSB) & MAC_DCU_LCL_IFS_5_CW_MIN_MASK)
#define MAC_DCU_LCL_IFS_5_CW_MIN_RESET                               0
#define MAC_DCU_LCL_IFS_5_ADDRESS                                    0x1054
#define MAC_DCU_LCL_IFS_5_HW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_5_SW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_5_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_LCL_IFS_5_SW_WRITE_MASK                              0x1fffffff
#define MAC_DCU_LCL_IFS_5_RSTMASK                                    0xffffffff
#define MAC_DCU_LCL_IFS_5_RESET                                      0x00000000

// 0x1058 (MAC_DCU_LCL_IFS_6)
#define MAC_DCU_LCL_IFS_6_LONG_AIFS_MSB                              28
#define MAC_DCU_LCL_IFS_6_LONG_AIFS_LSB                              28
#define MAC_DCU_LCL_IFS_6_LONG_AIFS_MASK                             0x10000000
#define MAC_DCU_LCL_IFS_6_LONG_AIFS_GET(x)                           (((x) & MAC_DCU_LCL_IFS_6_LONG_AIFS_MASK) >> MAC_DCU_LCL_IFS_6_LONG_AIFS_LSB)
#define MAC_DCU_LCL_IFS_6_LONG_AIFS_SET(x)                           (((0 | (x)) << MAC_DCU_LCL_IFS_6_LONG_AIFS_LSB) & MAC_DCU_LCL_IFS_6_LONG_AIFS_MASK)
#define MAC_DCU_LCL_IFS_6_LONG_AIFS_RESET                            0
#define MAC_DCU_LCL_IFS_6_AIFS_MSB                                   27
#define MAC_DCU_LCL_IFS_6_AIFS_LSB                                   20
#define MAC_DCU_LCL_IFS_6_AIFS_MASK                                  0x0ff00000
#define MAC_DCU_LCL_IFS_6_AIFS_GET(x)                                (((x) & MAC_DCU_LCL_IFS_6_AIFS_MASK) >> MAC_DCU_LCL_IFS_6_AIFS_LSB)
#define MAC_DCU_LCL_IFS_6_AIFS_SET(x)                                (((0 | (x)) << MAC_DCU_LCL_IFS_6_AIFS_LSB) & MAC_DCU_LCL_IFS_6_AIFS_MASK)
#define MAC_DCU_LCL_IFS_6_AIFS_RESET                                 0
#define MAC_DCU_LCL_IFS_6_CW_MAX_MSB                                 19
#define MAC_DCU_LCL_IFS_6_CW_MAX_LSB                                 10
#define MAC_DCU_LCL_IFS_6_CW_MAX_MASK                                0x000ffc00
#define MAC_DCU_LCL_IFS_6_CW_MAX_GET(x)                              (((x) & MAC_DCU_LCL_IFS_6_CW_MAX_MASK) >> MAC_DCU_LCL_IFS_6_CW_MAX_LSB)
#define MAC_DCU_LCL_IFS_6_CW_MAX_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_6_CW_MAX_LSB) & MAC_DCU_LCL_IFS_6_CW_MAX_MASK)
#define MAC_DCU_LCL_IFS_6_CW_MAX_RESET                               0
#define MAC_DCU_LCL_IFS_6_CW_MIN_MSB                                 9
#define MAC_DCU_LCL_IFS_6_CW_MIN_LSB                                 0
#define MAC_DCU_LCL_IFS_6_CW_MIN_MASK                                0x000003ff
#define MAC_DCU_LCL_IFS_6_CW_MIN_GET(x)                              (((x) & MAC_DCU_LCL_IFS_6_CW_MIN_MASK) >> MAC_DCU_LCL_IFS_6_CW_MIN_LSB)
#define MAC_DCU_LCL_IFS_6_CW_MIN_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_6_CW_MIN_LSB) & MAC_DCU_LCL_IFS_6_CW_MIN_MASK)
#define MAC_DCU_LCL_IFS_6_CW_MIN_RESET                               0
#define MAC_DCU_LCL_IFS_6_ADDRESS                                    0x1058
#define MAC_DCU_LCL_IFS_6_HW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_6_SW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_6_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_LCL_IFS_6_SW_WRITE_MASK                              0x1fffffff
#define MAC_DCU_LCL_IFS_6_RSTMASK                                    0xffffffff
#define MAC_DCU_LCL_IFS_6_RESET                                      0x00000000

// 0x105c (MAC_DCU_LCL_IFS_7)
#define MAC_DCU_LCL_IFS_7_LONG_AIFS_MSB                              28
#define MAC_DCU_LCL_IFS_7_LONG_AIFS_LSB                              28
#define MAC_DCU_LCL_IFS_7_LONG_AIFS_MASK                             0x10000000
#define MAC_DCU_LCL_IFS_7_LONG_AIFS_GET(x)                           (((x) & MAC_DCU_LCL_IFS_7_LONG_AIFS_MASK) >> MAC_DCU_LCL_IFS_7_LONG_AIFS_LSB)
#define MAC_DCU_LCL_IFS_7_LONG_AIFS_SET(x)                           (((0 | (x)) << MAC_DCU_LCL_IFS_7_LONG_AIFS_LSB) & MAC_DCU_LCL_IFS_7_LONG_AIFS_MASK)
#define MAC_DCU_LCL_IFS_7_LONG_AIFS_RESET                            0
#define MAC_DCU_LCL_IFS_7_AIFS_MSB                                   27
#define MAC_DCU_LCL_IFS_7_AIFS_LSB                                   20
#define MAC_DCU_LCL_IFS_7_AIFS_MASK                                  0x0ff00000
#define MAC_DCU_LCL_IFS_7_AIFS_GET(x)                                (((x) & MAC_DCU_LCL_IFS_7_AIFS_MASK) >> MAC_DCU_LCL_IFS_7_AIFS_LSB)
#define MAC_DCU_LCL_IFS_7_AIFS_SET(x)                                (((0 | (x)) << MAC_DCU_LCL_IFS_7_AIFS_LSB) & MAC_DCU_LCL_IFS_7_AIFS_MASK)
#define MAC_DCU_LCL_IFS_7_AIFS_RESET                                 0
#define MAC_DCU_LCL_IFS_7_CW_MAX_MSB                                 19
#define MAC_DCU_LCL_IFS_7_CW_MAX_LSB                                 10
#define MAC_DCU_LCL_IFS_7_CW_MAX_MASK                                0x000ffc00
#define MAC_DCU_LCL_IFS_7_CW_MAX_GET(x)                              (((x) & MAC_DCU_LCL_IFS_7_CW_MAX_MASK) >> MAC_DCU_LCL_IFS_7_CW_MAX_LSB)
#define MAC_DCU_LCL_IFS_7_CW_MAX_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_7_CW_MAX_LSB) & MAC_DCU_LCL_IFS_7_CW_MAX_MASK)
#define MAC_DCU_LCL_IFS_7_CW_MAX_RESET                               0
#define MAC_DCU_LCL_IFS_7_CW_MIN_MSB                                 9
#define MAC_DCU_LCL_IFS_7_CW_MIN_LSB                                 0
#define MAC_DCU_LCL_IFS_7_CW_MIN_MASK                                0x000003ff
#define MAC_DCU_LCL_IFS_7_CW_MIN_GET(x)                              (((x) & MAC_DCU_LCL_IFS_7_CW_MIN_MASK) >> MAC_DCU_LCL_IFS_7_CW_MIN_LSB)
#define MAC_DCU_LCL_IFS_7_CW_MIN_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_7_CW_MIN_LSB) & MAC_DCU_LCL_IFS_7_CW_MIN_MASK)
#define MAC_DCU_LCL_IFS_7_CW_MIN_RESET                               0
#define MAC_DCU_LCL_IFS_7_ADDRESS                                    0x105c
#define MAC_DCU_LCL_IFS_7_HW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_7_SW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_7_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_LCL_IFS_7_SW_WRITE_MASK                              0x1fffffff
#define MAC_DCU_LCL_IFS_7_RSTMASK                                    0xffffffff
#define MAC_DCU_LCL_IFS_7_RESET                                      0x00000000

// 0x1060 (MAC_DCU_LCL_IFS_8)
#define MAC_DCU_LCL_IFS_8_LONG_AIFS_MSB                              28
#define MAC_DCU_LCL_IFS_8_LONG_AIFS_LSB                              28
#define MAC_DCU_LCL_IFS_8_LONG_AIFS_MASK                             0x10000000
#define MAC_DCU_LCL_IFS_8_LONG_AIFS_GET(x)                           (((x) & MAC_DCU_LCL_IFS_8_LONG_AIFS_MASK) >> MAC_DCU_LCL_IFS_8_LONG_AIFS_LSB)
#define MAC_DCU_LCL_IFS_8_LONG_AIFS_SET(x)                           (((0 | (x)) << MAC_DCU_LCL_IFS_8_LONG_AIFS_LSB) & MAC_DCU_LCL_IFS_8_LONG_AIFS_MASK)
#define MAC_DCU_LCL_IFS_8_LONG_AIFS_RESET                            0
#define MAC_DCU_LCL_IFS_8_AIFS_MSB                                   27
#define MAC_DCU_LCL_IFS_8_AIFS_LSB                                   20
#define MAC_DCU_LCL_IFS_8_AIFS_MASK                                  0x0ff00000
#define MAC_DCU_LCL_IFS_8_AIFS_GET(x)                                (((x) & MAC_DCU_LCL_IFS_8_AIFS_MASK) >> MAC_DCU_LCL_IFS_8_AIFS_LSB)
#define MAC_DCU_LCL_IFS_8_AIFS_SET(x)                                (((0 | (x)) << MAC_DCU_LCL_IFS_8_AIFS_LSB) & MAC_DCU_LCL_IFS_8_AIFS_MASK)
#define MAC_DCU_LCL_IFS_8_AIFS_RESET                                 0
#define MAC_DCU_LCL_IFS_8_CW_MAX_MSB                                 19
#define MAC_DCU_LCL_IFS_8_CW_MAX_LSB                                 10
#define MAC_DCU_LCL_IFS_8_CW_MAX_MASK                                0x000ffc00
#define MAC_DCU_LCL_IFS_8_CW_MAX_GET(x)                              (((x) & MAC_DCU_LCL_IFS_8_CW_MAX_MASK) >> MAC_DCU_LCL_IFS_8_CW_MAX_LSB)
#define MAC_DCU_LCL_IFS_8_CW_MAX_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_8_CW_MAX_LSB) & MAC_DCU_LCL_IFS_8_CW_MAX_MASK)
#define MAC_DCU_LCL_IFS_8_CW_MAX_RESET                               0
#define MAC_DCU_LCL_IFS_8_CW_MIN_MSB                                 9
#define MAC_DCU_LCL_IFS_8_CW_MIN_LSB                                 0
#define MAC_DCU_LCL_IFS_8_CW_MIN_MASK                                0x000003ff
#define MAC_DCU_LCL_IFS_8_CW_MIN_GET(x)                              (((x) & MAC_DCU_LCL_IFS_8_CW_MIN_MASK) >> MAC_DCU_LCL_IFS_8_CW_MIN_LSB)
#define MAC_DCU_LCL_IFS_8_CW_MIN_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_8_CW_MIN_LSB) & MAC_DCU_LCL_IFS_8_CW_MIN_MASK)
#define MAC_DCU_LCL_IFS_8_CW_MIN_RESET                               0
#define MAC_DCU_LCL_IFS_8_ADDRESS                                    0x1060
#define MAC_DCU_LCL_IFS_8_HW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_8_SW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_8_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_LCL_IFS_8_SW_WRITE_MASK                              0x1fffffff
#define MAC_DCU_LCL_IFS_8_RSTMASK                                    0xffffffff
#define MAC_DCU_LCL_IFS_8_RESET                                      0x00000000

// 0x1064 (MAC_DCU_LCL_IFS_9)
#define MAC_DCU_LCL_IFS_9_LONG_AIFS_MSB                              28
#define MAC_DCU_LCL_IFS_9_LONG_AIFS_LSB                              28
#define MAC_DCU_LCL_IFS_9_LONG_AIFS_MASK                             0x10000000
#define MAC_DCU_LCL_IFS_9_LONG_AIFS_GET(x)                           (((x) & MAC_DCU_LCL_IFS_9_LONG_AIFS_MASK) >> MAC_DCU_LCL_IFS_9_LONG_AIFS_LSB)
#define MAC_DCU_LCL_IFS_9_LONG_AIFS_SET(x)                           (((0 | (x)) << MAC_DCU_LCL_IFS_9_LONG_AIFS_LSB) & MAC_DCU_LCL_IFS_9_LONG_AIFS_MASK)
#define MAC_DCU_LCL_IFS_9_LONG_AIFS_RESET                            0
#define MAC_DCU_LCL_IFS_9_AIFS_MSB                                   27
#define MAC_DCU_LCL_IFS_9_AIFS_LSB                                   20
#define MAC_DCU_LCL_IFS_9_AIFS_MASK                                  0x0ff00000
#define MAC_DCU_LCL_IFS_9_AIFS_GET(x)                                (((x) & MAC_DCU_LCL_IFS_9_AIFS_MASK) >> MAC_DCU_LCL_IFS_9_AIFS_LSB)
#define MAC_DCU_LCL_IFS_9_AIFS_SET(x)                                (((0 | (x)) << MAC_DCU_LCL_IFS_9_AIFS_LSB) & MAC_DCU_LCL_IFS_9_AIFS_MASK)
#define MAC_DCU_LCL_IFS_9_AIFS_RESET                                 0
#define MAC_DCU_LCL_IFS_9_CW_MAX_MSB                                 19
#define MAC_DCU_LCL_IFS_9_CW_MAX_LSB                                 10
#define MAC_DCU_LCL_IFS_9_CW_MAX_MASK                                0x000ffc00
#define MAC_DCU_LCL_IFS_9_CW_MAX_GET(x)                              (((x) & MAC_DCU_LCL_IFS_9_CW_MAX_MASK) >> MAC_DCU_LCL_IFS_9_CW_MAX_LSB)
#define MAC_DCU_LCL_IFS_9_CW_MAX_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_9_CW_MAX_LSB) & MAC_DCU_LCL_IFS_9_CW_MAX_MASK)
#define MAC_DCU_LCL_IFS_9_CW_MAX_RESET                               0
#define MAC_DCU_LCL_IFS_9_CW_MIN_MSB                                 9
#define MAC_DCU_LCL_IFS_9_CW_MIN_LSB                                 0
#define MAC_DCU_LCL_IFS_9_CW_MIN_MASK                                0x000003ff
#define MAC_DCU_LCL_IFS_9_CW_MIN_GET(x)                              (((x) & MAC_DCU_LCL_IFS_9_CW_MIN_MASK) >> MAC_DCU_LCL_IFS_9_CW_MIN_LSB)
#define MAC_DCU_LCL_IFS_9_CW_MIN_SET(x)                              (((0 | (x)) << MAC_DCU_LCL_IFS_9_CW_MIN_LSB) & MAC_DCU_LCL_IFS_9_CW_MIN_MASK)
#define MAC_DCU_LCL_IFS_9_CW_MIN_RESET                               0
#define MAC_DCU_LCL_IFS_9_ADDRESS                                    0x1064
#define MAC_DCU_LCL_IFS_9_HW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_9_SW_MASK                                    0x1fffffff
#define MAC_DCU_LCL_IFS_9_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_LCL_IFS_9_SW_WRITE_MASK                              0x1fffffff
#define MAC_DCU_LCL_IFS_9_RSTMASK                                    0xffffffff
#define MAC_DCU_LCL_IFS_9_RESET                                      0x00000000

// 0x1070 (MAC_DCU_GBL_IFS_SLOT)
#define MAC_DCU_GBL_IFS_SLOT_DURATION_MSB                            15
#define MAC_DCU_GBL_IFS_SLOT_DURATION_LSB                            0
#define MAC_DCU_GBL_IFS_SLOT_DURATION_MASK                           0x0000ffff
#define MAC_DCU_GBL_IFS_SLOT_DURATION_GET(x)                         (((x) & MAC_DCU_GBL_IFS_SLOT_DURATION_MASK) >> MAC_DCU_GBL_IFS_SLOT_DURATION_LSB)
#define MAC_DCU_GBL_IFS_SLOT_DURATION_SET(x)                         (((0 | (x)) << MAC_DCU_GBL_IFS_SLOT_DURATION_LSB) & MAC_DCU_GBL_IFS_SLOT_DURATION_MASK)
#define MAC_DCU_GBL_IFS_SLOT_DURATION_RESET                          360
#define MAC_DCU_GBL_IFS_SLOT_ADDRESS                                 0x1070
#define MAC_DCU_GBL_IFS_SLOT_HW_MASK                                 0x0000ffff
#define MAC_DCU_GBL_IFS_SLOT_SW_MASK                                 0x0000ffff
#define MAC_DCU_GBL_IFS_SLOT_HW_WRITE_MASK                           0x00000000
#define MAC_DCU_GBL_IFS_SLOT_SW_WRITE_MASK                           0x0000ffff
#define MAC_DCU_GBL_IFS_SLOT_RSTMASK                                 0xffffffff
#define MAC_DCU_GBL_IFS_SLOT_RESET                                   0x00000168

// 0x1078 (MAC_DCU_TXFILTER_DCU0_63_32)
#define MAC_DCU_TXFILTER_DCU0_63_32_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU0_63_32_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU0_63_32_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU0_63_32_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU0_63_32_DATA_MASK) >> MAC_DCU_TXFILTER_DCU0_63_32_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU0_63_32_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU0_63_32_DATA_LSB) & MAC_DCU_TXFILTER_DCU0_63_32_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU0_63_32_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU0_63_32_ADDRESS                          0x1078
#define MAC_DCU_TXFILTER_DCU0_63_32_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU0_63_32_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU0_63_32_HW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU0_63_32_SW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU0_63_32_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU0_63_32_RESET                            0x00000000

// 0x107c (MAC_DCU_TXFILTER_DCU8_63_32)
#define MAC_DCU_TXFILTER_DCU8_63_32_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU8_63_32_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU8_63_32_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU8_63_32_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU8_63_32_DATA_MASK) >> MAC_DCU_TXFILTER_DCU8_63_32_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU8_63_32_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU8_63_32_DATA_LSB) & MAC_DCU_TXFILTER_DCU8_63_32_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU8_63_32_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU8_63_32_ADDRESS                          0x107c
#define MAC_DCU_TXFILTER_DCU8_63_32_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU8_63_32_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU8_63_32_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU8_63_32_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU8_63_32_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU8_63_32_RESET                            0x00000000

// 0x1080 (MAC_DCU_RETRY_LIMIT_0)
#define MAC_DCU_RETRY_LIMIT_0_SDFL_MSB                               19
#define MAC_DCU_RETRY_LIMIT_0_SDFL_LSB                               14
#define MAC_DCU_RETRY_LIMIT_0_SDFL_MASK                              0x000fc000
#define MAC_DCU_RETRY_LIMIT_0_SDFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_0_SDFL_MASK) >> MAC_DCU_RETRY_LIMIT_0_SDFL_LSB)
#define MAC_DCU_RETRY_LIMIT_0_SDFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_0_SDFL_LSB) & MAC_DCU_RETRY_LIMIT_0_SDFL_MASK)
#define MAC_DCU_RETRY_LIMIT_0_SDFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_0_SRFL_MSB                               13
#define MAC_DCU_RETRY_LIMIT_0_SRFL_LSB                               8
#define MAC_DCU_RETRY_LIMIT_0_SRFL_MASK                              0x00003f00
#define MAC_DCU_RETRY_LIMIT_0_SRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_0_SRFL_MASK) >> MAC_DCU_RETRY_LIMIT_0_SRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_0_SRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_0_SRFL_LSB) & MAC_DCU_RETRY_LIMIT_0_SRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_0_SRFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_0_FRFL_MSB                               3
#define MAC_DCU_RETRY_LIMIT_0_FRFL_LSB                               0
#define MAC_DCU_RETRY_LIMIT_0_FRFL_MASK                              0x0000000f
#define MAC_DCU_RETRY_LIMIT_0_FRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_0_FRFL_MASK) >> MAC_DCU_RETRY_LIMIT_0_FRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_0_FRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_0_FRFL_LSB) & MAC_DCU_RETRY_LIMIT_0_FRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_0_FRFL_RESET                             4
#define MAC_DCU_RETRY_LIMIT_0_ADDRESS                                0x1080
#define MAC_DCU_RETRY_LIMIT_ADDRESS                                  MAC_DCU_RETRY_LIMIT_0_ADDRESS
#define MAC_DCU_RETRY_LIMIT_0_HW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_0_SW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_0_HW_WRITE_MASK                          0x00000000
#define MAC_DCU_RETRY_LIMIT_0_SW_WRITE_MASK                          0x000fff0f
#define MAC_DCU_RETRY_LIMIT_0_RSTMASK                                0xffffffff
#define MAC_DCU_RETRY_LIMIT_0_RESET                                  0x00082004

// 0x1084 (MAC_DCU_RETRY_LIMIT_1)
#define MAC_DCU_RETRY_LIMIT_1_SDFL_MSB                               19
#define MAC_DCU_RETRY_LIMIT_1_SDFL_LSB                               14
#define MAC_DCU_RETRY_LIMIT_1_SDFL_MASK                              0x000fc000
#define MAC_DCU_RETRY_LIMIT_1_SDFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_1_SDFL_MASK) >> MAC_DCU_RETRY_LIMIT_1_SDFL_LSB)
#define MAC_DCU_RETRY_LIMIT_1_SDFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_1_SDFL_LSB) & MAC_DCU_RETRY_LIMIT_1_SDFL_MASK)
#define MAC_DCU_RETRY_LIMIT_1_SDFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_1_SRFL_MSB                               13
#define MAC_DCU_RETRY_LIMIT_1_SRFL_LSB                               8
#define MAC_DCU_RETRY_LIMIT_1_SRFL_MASK                              0x00003f00
#define MAC_DCU_RETRY_LIMIT_1_SRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_1_SRFL_MASK) >> MAC_DCU_RETRY_LIMIT_1_SRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_1_SRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_1_SRFL_LSB) & MAC_DCU_RETRY_LIMIT_1_SRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_1_SRFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_1_FRFL_MSB                               3
#define MAC_DCU_RETRY_LIMIT_1_FRFL_LSB                               0
#define MAC_DCU_RETRY_LIMIT_1_FRFL_MASK                              0x0000000f
#define MAC_DCU_RETRY_LIMIT_1_FRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_1_FRFL_MASK) >> MAC_DCU_RETRY_LIMIT_1_FRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_1_FRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_1_FRFL_LSB) & MAC_DCU_RETRY_LIMIT_1_FRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_1_FRFL_RESET                             4
#define MAC_DCU_RETRY_LIMIT_1_ADDRESS                                0x1084
#define MAC_DCU_RETRY_LIMIT_1_HW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_1_SW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_1_HW_WRITE_MASK                          0x00000000
#define MAC_DCU_RETRY_LIMIT_1_SW_WRITE_MASK                          0x000fff0f
#define MAC_DCU_RETRY_LIMIT_1_RSTMASK                                0xffffffff
#define MAC_DCU_RETRY_LIMIT_1_RESET                                  0x00082004

// 0x1088 (MAC_DCU_RETRY_LIMIT_2)
#define MAC_DCU_RETRY_LIMIT_2_SDFL_MSB                               19
#define MAC_DCU_RETRY_LIMIT_2_SDFL_LSB                               14
#define MAC_DCU_RETRY_LIMIT_2_SDFL_MASK                              0x000fc000
#define MAC_DCU_RETRY_LIMIT_2_SDFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_2_SDFL_MASK) >> MAC_DCU_RETRY_LIMIT_2_SDFL_LSB)
#define MAC_DCU_RETRY_LIMIT_2_SDFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_2_SDFL_LSB) & MAC_DCU_RETRY_LIMIT_2_SDFL_MASK)
#define MAC_DCU_RETRY_LIMIT_2_SDFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_2_SRFL_MSB                               13
#define MAC_DCU_RETRY_LIMIT_2_SRFL_LSB                               8
#define MAC_DCU_RETRY_LIMIT_2_SRFL_MASK                              0x00003f00
#define MAC_DCU_RETRY_LIMIT_2_SRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_2_SRFL_MASK) >> MAC_DCU_RETRY_LIMIT_2_SRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_2_SRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_2_SRFL_LSB) & MAC_DCU_RETRY_LIMIT_2_SRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_2_SRFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_2_FRFL_MSB                               3
#define MAC_DCU_RETRY_LIMIT_2_FRFL_LSB                               0
#define MAC_DCU_RETRY_LIMIT_2_FRFL_MASK                              0x0000000f
#define MAC_DCU_RETRY_LIMIT_2_FRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_2_FRFL_MASK) >> MAC_DCU_RETRY_LIMIT_2_FRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_2_FRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_2_FRFL_LSB) & MAC_DCU_RETRY_LIMIT_2_FRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_2_FRFL_RESET                             4
#define MAC_DCU_RETRY_LIMIT_2_ADDRESS                                0x1088
#define MAC_DCU_RETRY_LIMIT_2_HW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_2_SW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_2_HW_WRITE_MASK                          0x00000000
#define MAC_DCU_RETRY_LIMIT_2_SW_WRITE_MASK                          0x000fff0f
#define MAC_DCU_RETRY_LIMIT_2_RSTMASK                                0xffffffff
#define MAC_DCU_RETRY_LIMIT_2_RESET                                  0x00082004

// 0x108c (MAC_DCU_RETRY_LIMIT_3)
#define MAC_DCU_RETRY_LIMIT_3_SDFL_MSB                               19
#define MAC_DCU_RETRY_LIMIT_3_SDFL_LSB                               14
#define MAC_DCU_RETRY_LIMIT_3_SDFL_MASK                              0x000fc000
#define MAC_DCU_RETRY_LIMIT_3_SDFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_3_SDFL_MASK) >> MAC_DCU_RETRY_LIMIT_3_SDFL_LSB)
#define MAC_DCU_RETRY_LIMIT_3_SDFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_3_SDFL_LSB) & MAC_DCU_RETRY_LIMIT_3_SDFL_MASK)
#define MAC_DCU_RETRY_LIMIT_3_SDFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_3_SRFL_MSB                               13
#define MAC_DCU_RETRY_LIMIT_3_SRFL_LSB                               8
#define MAC_DCU_RETRY_LIMIT_3_SRFL_MASK                              0x00003f00
#define MAC_DCU_RETRY_LIMIT_3_SRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_3_SRFL_MASK) >> MAC_DCU_RETRY_LIMIT_3_SRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_3_SRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_3_SRFL_LSB) & MAC_DCU_RETRY_LIMIT_3_SRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_3_SRFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_3_FRFL_MSB                               3
#define MAC_DCU_RETRY_LIMIT_3_FRFL_LSB                               0
#define MAC_DCU_RETRY_LIMIT_3_FRFL_MASK                              0x0000000f
#define MAC_DCU_RETRY_LIMIT_3_FRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_3_FRFL_MASK) >> MAC_DCU_RETRY_LIMIT_3_FRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_3_FRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_3_FRFL_LSB) & MAC_DCU_RETRY_LIMIT_3_FRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_3_FRFL_RESET                             4
#define MAC_DCU_RETRY_LIMIT_3_ADDRESS                                0x108c
#define MAC_DCU_RETRY_LIMIT_3_HW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_3_SW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_3_HW_WRITE_MASK                          0x00000000
#define MAC_DCU_RETRY_LIMIT_3_SW_WRITE_MASK                          0x000fff0f
#define MAC_DCU_RETRY_LIMIT_3_RSTMASK                                0xffffffff
#define MAC_DCU_RETRY_LIMIT_3_RESET                                  0x00082004

// 0x1090 (MAC_DCU_RETRY_LIMIT_4)
#define MAC_DCU_RETRY_LIMIT_4_SDFL_MSB                               19
#define MAC_DCU_RETRY_LIMIT_4_SDFL_LSB                               14
#define MAC_DCU_RETRY_LIMIT_4_SDFL_MASK                              0x000fc000
#define MAC_DCU_RETRY_LIMIT_4_SDFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_4_SDFL_MASK) >> MAC_DCU_RETRY_LIMIT_4_SDFL_LSB)
#define MAC_DCU_RETRY_LIMIT_4_SDFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_4_SDFL_LSB) & MAC_DCU_RETRY_LIMIT_4_SDFL_MASK)
#define MAC_DCU_RETRY_LIMIT_4_SDFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_4_SRFL_MSB                               13
#define MAC_DCU_RETRY_LIMIT_4_SRFL_LSB                               8
#define MAC_DCU_RETRY_LIMIT_4_SRFL_MASK                              0x00003f00
#define MAC_DCU_RETRY_LIMIT_4_SRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_4_SRFL_MASK) >> MAC_DCU_RETRY_LIMIT_4_SRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_4_SRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_4_SRFL_LSB) & MAC_DCU_RETRY_LIMIT_4_SRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_4_SRFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_4_FRFL_MSB                               3
#define MAC_DCU_RETRY_LIMIT_4_FRFL_LSB                               0
#define MAC_DCU_RETRY_LIMIT_4_FRFL_MASK                              0x0000000f
#define MAC_DCU_RETRY_LIMIT_4_FRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_4_FRFL_MASK) >> MAC_DCU_RETRY_LIMIT_4_FRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_4_FRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_4_FRFL_LSB) & MAC_DCU_RETRY_LIMIT_4_FRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_4_FRFL_RESET                             4
#define MAC_DCU_RETRY_LIMIT_4_ADDRESS                                0x1090
#define MAC_DCU_RETRY_LIMIT_4_HW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_4_SW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_4_HW_WRITE_MASK                          0x00000000
#define MAC_DCU_RETRY_LIMIT_4_SW_WRITE_MASK                          0x000fff0f
#define MAC_DCU_RETRY_LIMIT_4_RSTMASK                                0xffffffff
#define MAC_DCU_RETRY_LIMIT_4_RESET                                  0x00082004

// 0x1094 (MAC_DCU_RETRY_LIMIT_5)
#define MAC_DCU_RETRY_LIMIT_5_SDFL_MSB                               19
#define MAC_DCU_RETRY_LIMIT_5_SDFL_LSB                               14
#define MAC_DCU_RETRY_LIMIT_5_SDFL_MASK                              0x000fc000
#define MAC_DCU_RETRY_LIMIT_5_SDFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_5_SDFL_MASK) >> MAC_DCU_RETRY_LIMIT_5_SDFL_LSB)
#define MAC_DCU_RETRY_LIMIT_5_SDFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_5_SDFL_LSB) & MAC_DCU_RETRY_LIMIT_5_SDFL_MASK)
#define MAC_DCU_RETRY_LIMIT_5_SDFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_5_SRFL_MSB                               13
#define MAC_DCU_RETRY_LIMIT_5_SRFL_LSB                               8
#define MAC_DCU_RETRY_LIMIT_5_SRFL_MASK                              0x00003f00
#define MAC_DCU_RETRY_LIMIT_5_SRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_5_SRFL_MASK) >> MAC_DCU_RETRY_LIMIT_5_SRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_5_SRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_5_SRFL_LSB) & MAC_DCU_RETRY_LIMIT_5_SRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_5_SRFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_5_FRFL_MSB                               3
#define MAC_DCU_RETRY_LIMIT_5_FRFL_LSB                               0
#define MAC_DCU_RETRY_LIMIT_5_FRFL_MASK                              0x0000000f
#define MAC_DCU_RETRY_LIMIT_5_FRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_5_FRFL_MASK) >> MAC_DCU_RETRY_LIMIT_5_FRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_5_FRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_5_FRFL_LSB) & MAC_DCU_RETRY_LIMIT_5_FRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_5_FRFL_RESET                             4
#define MAC_DCU_RETRY_LIMIT_5_ADDRESS                                0x1094
#define MAC_DCU_RETRY_LIMIT_5_HW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_5_SW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_5_HW_WRITE_MASK                          0x00000000
#define MAC_DCU_RETRY_LIMIT_5_SW_WRITE_MASK                          0x000fff0f
#define MAC_DCU_RETRY_LIMIT_5_RSTMASK                                0xffffffff
#define MAC_DCU_RETRY_LIMIT_5_RESET                                  0x00082004

// 0x1098 (MAC_DCU_RETRY_LIMIT_6)
#define MAC_DCU_RETRY_LIMIT_6_SDFL_MSB                               19
#define MAC_DCU_RETRY_LIMIT_6_SDFL_LSB                               14
#define MAC_DCU_RETRY_LIMIT_6_SDFL_MASK                              0x000fc000
#define MAC_DCU_RETRY_LIMIT_6_SDFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_6_SDFL_MASK) >> MAC_DCU_RETRY_LIMIT_6_SDFL_LSB)
#define MAC_DCU_RETRY_LIMIT_6_SDFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_6_SDFL_LSB) & MAC_DCU_RETRY_LIMIT_6_SDFL_MASK)
#define MAC_DCU_RETRY_LIMIT_6_SDFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_6_SRFL_MSB                               13
#define MAC_DCU_RETRY_LIMIT_6_SRFL_LSB                               8
#define MAC_DCU_RETRY_LIMIT_6_SRFL_MASK                              0x00003f00
#define MAC_DCU_RETRY_LIMIT_6_SRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_6_SRFL_MASK) >> MAC_DCU_RETRY_LIMIT_6_SRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_6_SRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_6_SRFL_LSB) & MAC_DCU_RETRY_LIMIT_6_SRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_6_SRFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_6_FRFL_MSB                               3
#define MAC_DCU_RETRY_LIMIT_6_FRFL_LSB                               0
#define MAC_DCU_RETRY_LIMIT_6_FRFL_MASK                              0x0000000f
#define MAC_DCU_RETRY_LIMIT_6_FRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_6_FRFL_MASK) >> MAC_DCU_RETRY_LIMIT_6_FRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_6_FRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_6_FRFL_LSB) & MAC_DCU_RETRY_LIMIT_6_FRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_6_FRFL_RESET                             4
#define MAC_DCU_RETRY_LIMIT_6_ADDRESS                                0x1098
#define MAC_DCU_RETRY_LIMIT_6_HW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_6_SW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_6_HW_WRITE_MASK                          0x00000000
#define MAC_DCU_RETRY_LIMIT_6_SW_WRITE_MASK                          0x000fff0f
#define MAC_DCU_RETRY_LIMIT_6_RSTMASK                                0xffffffff
#define MAC_DCU_RETRY_LIMIT_6_RESET                                  0x00082004

// 0x109c (MAC_DCU_RETRY_LIMIT_7)
#define MAC_DCU_RETRY_LIMIT_7_SDFL_MSB                               19
#define MAC_DCU_RETRY_LIMIT_7_SDFL_LSB                               14
#define MAC_DCU_RETRY_LIMIT_7_SDFL_MASK                              0x000fc000
#define MAC_DCU_RETRY_LIMIT_7_SDFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_7_SDFL_MASK) >> MAC_DCU_RETRY_LIMIT_7_SDFL_LSB)
#define MAC_DCU_RETRY_LIMIT_7_SDFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_7_SDFL_LSB) & MAC_DCU_RETRY_LIMIT_7_SDFL_MASK)
#define MAC_DCU_RETRY_LIMIT_7_SDFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_7_SRFL_MSB                               13
#define MAC_DCU_RETRY_LIMIT_7_SRFL_LSB                               8
#define MAC_DCU_RETRY_LIMIT_7_SRFL_MASK                              0x00003f00
#define MAC_DCU_RETRY_LIMIT_7_SRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_7_SRFL_MASK) >> MAC_DCU_RETRY_LIMIT_7_SRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_7_SRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_7_SRFL_LSB) & MAC_DCU_RETRY_LIMIT_7_SRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_7_SRFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_7_FRFL_MSB                               3
#define MAC_DCU_RETRY_LIMIT_7_FRFL_LSB                               0
#define MAC_DCU_RETRY_LIMIT_7_FRFL_MASK                              0x0000000f
#define MAC_DCU_RETRY_LIMIT_7_FRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_7_FRFL_MASK) >> MAC_DCU_RETRY_LIMIT_7_FRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_7_FRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_7_FRFL_LSB) & MAC_DCU_RETRY_LIMIT_7_FRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_7_FRFL_RESET                             4
#define MAC_DCU_RETRY_LIMIT_7_ADDRESS                                0x109c
#define MAC_DCU_RETRY_LIMIT_7_HW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_7_SW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_7_HW_WRITE_MASK                          0x00000000
#define MAC_DCU_RETRY_LIMIT_7_SW_WRITE_MASK                          0x000fff0f
#define MAC_DCU_RETRY_LIMIT_7_RSTMASK                                0xffffffff
#define MAC_DCU_RETRY_LIMIT_7_RESET                                  0x00082004

// 0x10a0 (MAC_DCU_RETRY_LIMIT_8)
#define MAC_DCU_RETRY_LIMIT_8_SDFL_MSB                               19
#define MAC_DCU_RETRY_LIMIT_8_SDFL_LSB                               14
#define MAC_DCU_RETRY_LIMIT_8_SDFL_MASK                              0x000fc000
#define MAC_DCU_RETRY_LIMIT_8_SDFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_8_SDFL_MASK) >> MAC_DCU_RETRY_LIMIT_8_SDFL_LSB)
#define MAC_DCU_RETRY_LIMIT_8_SDFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_8_SDFL_LSB) & MAC_DCU_RETRY_LIMIT_8_SDFL_MASK)
#define MAC_DCU_RETRY_LIMIT_8_SDFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_8_SRFL_MSB                               13
#define MAC_DCU_RETRY_LIMIT_8_SRFL_LSB                               8
#define MAC_DCU_RETRY_LIMIT_8_SRFL_MASK                              0x00003f00
#define MAC_DCU_RETRY_LIMIT_8_SRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_8_SRFL_MASK) >> MAC_DCU_RETRY_LIMIT_8_SRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_8_SRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_8_SRFL_LSB) & MAC_DCU_RETRY_LIMIT_8_SRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_8_SRFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_8_FRFL_MSB                               3
#define MAC_DCU_RETRY_LIMIT_8_FRFL_LSB                               0
#define MAC_DCU_RETRY_LIMIT_8_FRFL_MASK                              0x0000000f
#define MAC_DCU_RETRY_LIMIT_8_FRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_8_FRFL_MASK) >> MAC_DCU_RETRY_LIMIT_8_FRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_8_FRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_8_FRFL_LSB) & MAC_DCU_RETRY_LIMIT_8_FRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_8_FRFL_RESET                             4
#define MAC_DCU_RETRY_LIMIT_8_ADDRESS                                0x10a0
#define MAC_DCU_RETRY_LIMIT_8_HW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_8_SW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_8_HW_WRITE_MASK                          0x00000000
#define MAC_DCU_RETRY_LIMIT_8_SW_WRITE_MASK                          0x000fff0f
#define MAC_DCU_RETRY_LIMIT_8_RSTMASK                                0xffffffff
#define MAC_DCU_RETRY_LIMIT_8_RESET                                  0x00082004

// 0x10a4 (MAC_DCU_RETRY_LIMIT_9)
#define MAC_DCU_RETRY_LIMIT_9_SDFL_MSB                               19
#define MAC_DCU_RETRY_LIMIT_9_SDFL_LSB                               14
#define MAC_DCU_RETRY_LIMIT_9_SDFL_MASK                              0x000fc000
#define MAC_DCU_RETRY_LIMIT_9_SDFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_9_SDFL_MASK) >> MAC_DCU_RETRY_LIMIT_9_SDFL_LSB)
#define MAC_DCU_RETRY_LIMIT_9_SDFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_9_SDFL_LSB) & MAC_DCU_RETRY_LIMIT_9_SDFL_MASK)
#define MAC_DCU_RETRY_LIMIT_9_SDFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_9_SRFL_MSB                               13
#define MAC_DCU_RETRY_LIMIT_9_SRFL_LSB                               8
#define MAC_DCU_RETRY_LIMIT_9_SRFL_MASK                              0x00003f00
#define MAC_DCU_RETRY_LIMIT_9_SRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_9_SRFL_MASK) >> MAC_DCU_RETRY_LIMIT_9_SRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_9_SRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_9_SRFL_LSB) & MAC_DCU_RETRY_LIMIT_9_SRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_9_SRFL_RESET                             32
#define MAC_DCU_RETRY_LIMIT_9_FRFL_MSB                               3
#define MAC_DCU_RETRY_LIMIT_9_FRFL_LSB                               0
#define MAC_DCU_RETRY_LIMIT_9_FRFL_MASK                              0x0000000f
#define MAC_DCU_RETRY_LIMIT_9_FRFL_GET(x)                            (((x) & MAC_DCU_RETRY_LIMIT_9_FRFL_MASK) >> MAC_DCU_RETRY_LIMIT_9_FRFL_LSB)
#define MAC_DCU_RETRY_LIMIT_9_FRFL_SET(x)                            (((0 | (x)) << MAC_DCU_RETRY_LIMIT_9_FRFL_LSB) & MAC_DCU_RETRY_LIMIT_9_FRFL_MASK)
#define MAC_DCU_RETRY_LIMIT_9_FRFL_RESET                             4
#define MAC_DCU_RETRY_LIMIT_9_ADDRESS                                0x10a4
#define MAC_DCU_RETRY_LIMIT_9_HW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_9_SW_MASK                                0x000fff0f
#define MAC_DCU_RETRY_LIMIT_9_HW_WRITE_MASK                          0x00000000
#define MAC_DCU_RETRY_LIMIT_9_SW_WRITE_MASK                          0x000fff0f
#define MAC_DCU_RETRY_LIMIT_9_RSTMASK                                0xffffffff
#define MAC_DCU_RETRY_LIMIT_9_RESET                                  0x00082004

// 0x10b0 (MAC_DCU_GBL_IFS_EIFS)
#define MAC_DCU_GBL_IFS_EIFS_DURATION_MSB                            15
#define MAC_DCU_GBL_IFS_EIFS_DURATION_LSB                            0
#define MAC_DCU_GBL_IFS_EIFS_DURATION_MASK                           0x0000ffff
#define MAC_DCU_GBL_IFS_EIFS_DURATION_GET(x)                         (((x) & MAC_DCU_GBL_IFS_EIFS_DURATION_MASK) >> MAC_DCU_GBL_IFS_EIFS_DURATION_LSB)
#define MAC_DCU_GBL_IFS_EIFS_DURATION_SET(x)                         (((0 | (x)) << MAC_DCU_GBL_IFS_EIFS_DURATION_LSB) & MAC_DCU_GBL_IFS_EIFS_DURATION_MASK)
#define MAC_DCU_GBL_IFS_EIFS_DURATION_RESET                          360
#define MAC_DCU_GBL_IFS_EIFS_ADDRESS                                 0x10b0
#define MAC_DCU_GBL_IFS_EIFS_HW_MASK                                 0x0000ffff
#define MAC_DCU_GBL_IFS_EIFS_SW_MASK                                 0x0000ffff
#define MAC_DCU_GBL_IFS_EIFS_HW_WRITE_MASK                           0x00000000
#define MAC_DCU_GBL_IFS_EIFS_SW_WRITE_MASK                           0x0000ffff
#define MAC_DCU_GBL_IFS_EIFS_RSTMASK                                 0xffffffff
#define MAC_DCU_GBL_IFS_EIFS_RESET                                   0x00000168

// 0x10b8 (MAC_DCU_TXFILTER_DCU0_95_64)
#define MAC_DCU_TXFILTER_DCU0_95_64_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU0_95_64_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU0_95_64_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU0_95_64_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU0_95_64_DATA_MASK) >> MAC_DCU_TXFILTER_DCU0_95_64_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU0_95_64_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU0_95_64_DATA_LSB) & MAC_DCU_TXFILTER_DCU0_95_64_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU0_95_64_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU0_95_64_ADDRESS                          0x10b8
#define MAC_DCU_TXFILTER_DCU0_95_64_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU0_95_64_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU0_95_64_HW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU0_95_64_SW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU0_95_64_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU0_95_64_RESET                            0x00000000

// 0x10bc (MAC_DCU_TXFILTER_DCU8_95_64)
#define MAC_DCU_TXFILTER_DCU8_95_64_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU8_95_64_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU8_95_64_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU8_95_64_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU8_95_64_DATA_MASK) >> MAC_DCU_TXFILTER_DCU8_95_64_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU8_95_64_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU8_95_64_DATA_LSB) & MAC_DCU_TXFILTER_DCU8_95_64_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU8_95_64_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU8_95_64_ADDRESS                          0x10bc
#define MAC_DCU_TXFILTER_DCU8_95_64_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU8_95_64_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU8_95_64_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU8_95_64_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU8_95_64_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU8_95_64_RESET                            0x00000000

// 0x10c0 (MAC_DCU_CHANNEL_TIME_0)
#define MAC_DCU_CHANNEL_TIME_0_ENABLE_MSB                            20
#define MAC_DCU_CHANNEL_TIME_0_ENABLE_LSB                            20
#define MAC_DCU_CHANNEL_TIME_0_ENABLE_MASK                           0x00100000
#define MAC_DCU_CHANNEL_TIME_0_ENABLE_GET(x)                         (((x) & MAC_DCU_CHANNEL_TIME_0_ENABLE_MASK) >> MAC_DCU_CHANNEL_TIME_0_ENABLE_LSB)
#define MAC_DCU_CHANNEL_TIME_0_ENABLE_SET(x)                         (((0 | (x)) << MAC_DCU_CHANNEL_TIME_0_ENABLE_LSB) & MAC_DCU_CHANNEL_TIME_0_ENABLE_MASK)
#define MAC_DCU_CHANNEL_TIME_0_ENABLE_RESET                          0
#define MAC_DCU_CHANNEL_TIME_0_DURATION_MSB                          19
#define MAC_DCU_CHANNEL_TIME_0_DURATION_LSB                          0
#define MAC_DCU_CHANNEL_TIME_0_DURATION_MASK                         0x000fffff
#define MAC_DCU_CHANNEL_TIME_0_DURATION_GET(x)                       (((x) & MAC_DCU_CHANNEL_TIME_0_DURATION_MASK) >> MAC_DCU_CHANNEL_TIME_0_DURATION_LSB)
#define MAC_DCU_CHANNEL_TIME_0_DURATION_SET(x)                       (((0 | (x)) << MAC_DCU_CHANNEL_TIME_0_DURATION_LSB) & MAC_DCU_CHANNEL_TIME_0_DURATION_MASK)
#define MAC_DCU_CHANNEL_TIME_0_DURATION_RESET                        0
#define MAC_DCU_CHANNEL_TIME_0_ADDRESS                               0x10c0
#define MAC_DCU_CHANNEL_TIME_ADDRESS                                 MAC_DCU_CHANNEL_TIME_0_ADDRESS
#define MAC_DCU_CHANNEL_TIME_0_HW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_0_SW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_0_HW_WRITE_MASK                         0x00000000
#define MAC_DCU_CHANNEL_TIME_0_SW_WRITE_MASK                         0x001fffff
#define MAC_DCU_CHANNEL_TIME_0_RSTMASK                               0xffffffff
#define MAC_DCU_CHANNEL_TIME_0_RESET                                 0x00000000

// 0x10c4 (MAC_DCU_CHANNEL_TIME_1)
#define MAC_DCU_CHANNEL_TIME_1_ENABLE_MSB                            20
#define MAC_DCU_CHANNEL_TIME_1_ENABLE_LSB                            20
#define MAC_DCU_CHANNEL_TIME_1_ENABLE_MASK                           0x00100000
#define MAC_DCU_CHANNEL_TIME_1_ENABLE_GET(x)                         (((x) & MAC_DCU_CHANNEL_TIME_1_ENABLE_MASK) >> MAC_DCU_CHANNEL_TIME_1_ENABLE_LSB)
#define MAC_DCU_CHANNEL_TIME_1_ENABLE_SET(x)                         (((0 | (x)) << MAC_DCU_CHANNEL_TIME_1_ENABLE_LSB) & MAC_DCU_CHANNEL_TIME_1_ENABLE_MASK)
#define MAC_DCU_CHANNEL_TIME_1_ENABLE_RESET                          0
#define MAC_DCU_CHANNEL_TIME_1_DURATION_MSB                          19
#define MAC_DCU_CHANNEL_TIME_1_DURATION_LSB                          0
#define MAC_DCU_CHANNEL_TIME_1_DURATION_MASK                         0x000fffff
#define MAC_DCU_CHANNEL_TIME_1_DURATION_GET(x)                       (((x) & MAC_DCU_CHANNEL_TIME_1_DURATION_MASK) >> MAC_DCU_CHANNEL_TIME_1_DURATION_LSB)
#define MAC_DCU_CHANNEL_TIME_1_DURATION_SET(x)                       (((0 | (x)) << MAC_DCU_CHANNEL_TIME_1_DURATION_LSB) & MAC_DCU_CHANNEL_TIME_1_DURATION_MASK)
#define MAC_DCU_CHANNEL_TIME_1_DURATION_RESET                        0
#define MAC_DCU_CHANNEL_TIME_1_ADDRESS                               0x10c4
#define MAC_DCU_CHANNEL_TIME_1_HW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_1_SW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_1_HW_WRITE_MASK                         0x00000000
#define MAC_DCU_CHANNEL_TIME_1_SW_WRITE_MASK                         0x001fffff
#define MAC_DCU_CHANNEL_TIME_1_RSTMASK                               0xffffffff
#define MAC_DCU_CHANNEL_TIME_1_RESET                                 0x00000000

// 0x10c8 (MAC_DCU_CHANNEL_TIME_2)
#define MAC_DCU_CHANNEL_TIME_2_ENABLE_MSB                            20
#define MAC_DCU_CHANNEL_TIME_2_ENABLE_LSB                            20
#define MAC_DCU_CHANNEL_TIME_2_ENABLE_MASK                           0x00100000
#define MAC_DCU_CHANNEL_TIME_2_ENABLE_GET(x)                         (((x) & MAC_DCU_CHANNEL_TIME_2_ENABLE_MASK) >> MAC_DCU_CHANNEL_TIME_2_ENABLE_LSB)
#define MAC_DCU_CHANNEL_TIME_2_ENABLE_SET(x)                         (((0 | (x)) << MAC_DCU_CHANNEL_TIME_2_ENABLE_LSB) & MAC_DCU_CHANNEL_TIME_2_ENABLE_MASK)
#define MAC_DCU_CHANNEL_TIME_2_ENABLE_RESET                          0
#define MAC_DCU_CHANNEL_TIME_2_DURATION_MSB                          19
#define MAC_DCU_CHANNEL_TIME_2_DURATION_LSB                          0
#define MAC_DCU_CHANNEL_TIME_2_DURATION_MASK                         0x000fffff
#define MAC_DCU_CHANNEL_TIME_2_DURATION_GET(x)                       (((x) & MAC_DCU_CHANNEL_TIME_2_DURATION_MASK) >> MAC_DCU_CHANNEL_TIME_2_DURATION_LSB)
#define MAC_DCU_CHANNEL_TIME_2_DURATION_SET(x)                       (((0 | (x)) << MAC_DCU_CHANNEL_TIME_2_DURATION_LSB) & MAC_DCU_CHANNEL_TIME_2_DURATION_MASK)
#define MAC_DCU_CHANNEL_TIME_2_DURATION_RESET                        0
#define MAC_DCU_CHANNEL_TIME_2_ADDRESS                               0x10c8
#define MAC_DCU_CHANNEL_TIME_2_HW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_2_SW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_2_HW_WRITE_MASK                         0x00000000
#define MAC_DCU_CHANNEL_TIME_2_SW_WRITE_MASK                         0x001fffff
#define MAC_DCU_CHANNEL_TIME_2_RSTMASK                               0xffffffff
#define MAC_DCU_CHANNEL_TIME_2_RESET                                 0x00000000

// 0x10cc (MAC_DCU_CHANNEL_TIME_3)
#define MAC_DCU_CHANNEL_TIME_3_ENABLE_MSB                            20
#define MAC_DCU_CHANNEL_TIME_3_ENABLE_LSB                            20
#define MAC_DCU_CHANNEL_TIME_3_ENABLE_MASK                           0x00100000
#define MAC_DCU_CHANNEL_TIME_3_ENABLE_GET(x)                         (((x) & MAC_DCU_CHANNEL_TIME_3_ENABLE_MASK) >> MAC_DCU_CHANNEL_TIME_3_ENABLE_LSB)
#define MAC_DCU_CHANNEL_TIME_3_ENABLE_SET(x)                         (((0 | (x)) << MAC_DCU_CHANNEL_TIME_3_ENABLE_LSB) & MAC_DCU_CHANNEL_TIME_3_ENABLE_MASK)
#define MAC_DCU_CHANNEL_TIME_3_ENABLE_RESET                          0
#define MAC_DCU_CHANNEL_TIME_3_DURATION_MSB                          19
#define MAC_DCU_CHANNEL_TIME_3_DURATION_LSB                          0
#define MAC_DCU_CHANNEL_TIME_3_DURATION_MASK                         0x000fffff
#define MAC_DCU_CHANNEL_TIME_3_DURATION_GET(x)                       (((x) & MAC_DCU_CHANNEL_TIME_3_DURATION_MASK) >> MAC_DCU_CHANNEL_TIME_3_DURATION_LSB)
#define MAC_DCU_CHANNEL_TIME_3_DURATION_SET(x)                       (((0 | (x)) << MAC_DCU_CHANNEL_TIME_3_DURATION_LSB) & MAC_DCU_CHANNEL_TIME_3_DURATION_MASK)
#define MAC_DCU_CHANNEL_TIME_3_DURATION_RESET                        0
#define MAC_DCU_CHANNEL_TIME_3_ADDRESS                               0x10cc
#define MAC_DCU_CHANNEL_TIME_3_HW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_3_SW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_3_HW_WRITE_MASK                         0x00000000
#define MAC_DCU_CHANNEL_TIME_3_SW_WRITE_MASK                         0x001fffff
#define MAC_DCU_CHANNEL_TIME_3_RSTMASK                               0xffffffff
#define MAC_DCU_CHANNEL_TIME_3_RESET                                 0x00000000

// 0x10d0 (MAC_DCU_CHANNEL_TIME_4)
#define MAC_DCU_CHANNEL_TIME_4_ENABLE_MSB                            20
#define MAC_DCU_CHANNEL_TIME_4_ENABLE_LSB                            20
#define MAC_DCU_CHANNEL_TIME_4_ENABLE_MASK                           0x00100000
#define MAC_DCU_CHANNEL_TIME_4_ENABLE_GET(x)                         (((x) & MAC_DCU_CHANNEL_TIME_4_ENABLE_MASK) >> MAC_DCU_CHANNEL_TIME_4_ENABLE_LSB)
#define MAC_DCU_CHANNEL_TIME_4_ENABLE_SET(x)                         (((0 | (x)) << MAC_DCU_CHANNEL_TIME_4_ENABLE_LSB) & MAC_DCU_CHANNEL_TIME_4_ENABLE_MASK)
#define MAC_DCU_CHANNEL_TIME_4_ENABLE_RESET                          0
#define MAC_DCU_CHANNEL_TIME_4_DURATION_MSB                          19
#define MAC_DCU_CHANNEL_TIME_4_DURATION_LSB                          0
#define MAC_DCU_CHANNEL_TIME_4_DURATION_MASK                         0x000fffff
#define MAC_DCU_CHANNEL_TIME_4_DURATION_GET(x)                       (((x) & MAC_DCU_CHANNEL_TIME_4_DURATION_MASK) >> MAC_DCU_CHANNEL_TIME_4_DURATION_LSB)
#define MAC_DCU_CHANNEL_TIME_4_DURATION_SET(x)                       (((0 | (x)) << MAC_DCU_CHANNEL_TIME_4_DURATION_LSB) & MAC_DCU_CHANNEL_TIME_4_DURATION_MASK)
#define MAC_DCU_CHANNEL_TIME_4_DURATION_RESET                        0
#define MAC_DCU_CHANNEL_TIME_4_ADDRESS                               0x10d0
#define MAC_DCU_CHANNEL_TIME_4_HW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_4_SW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_4_HW_WRITE_MASK                         0x00000000
#define MAC_DCU_CHANNEL_TIME_4_SW_WRITE_MASK                         0x001fffff
#define MAC_DCU_CHANNEL_TIME_4_RSTMASK                               0xffffffff
#define MAC_DCU_CHANNEL_TIME_4_RESET                                 0x00000000

// 0x10d4 (MAC_DCU_CHANNEL_TIME_5)
#define MAC_DCU_CHANNEL_TIME_5_ENABLE_MSB                            20
#define MAC_DCU_CHANNEL_TIME_5_ENABLE_LSB                            20
#define MAC_DCU_CHANNEL_TIME_5_ENABLE_MASK                           0x00100000
#define MAC_DCU_CHANNEL_TIME_5_ENABLE_GET(x)                         (((x) & MAC_DCU_CHANNEL_TIME_5_ENABLE_MASK) >> MAC_DCU_CHANNEL_TIME_5_ENABLE_LSB)
#define MAC_DCU_CHANNEL_TIME_5_ENABLE_SET(x)                         (((0 | (x)) << MAC_DCU_CHANNEL_TIME_5_ENABLE_LSB) & MAC_DCU_CHANNEL_TIME_5_ENABLE_MASK)
#define MAC_DCU_CHANNEL_TIME_5_ENABLE_RESET                          0
#define MAC_DCU_CHANNEL_TIME_5_DURATION_MSB                          19
#define MAC_DCU_CHANNEL_TIME_5_DURATION_LSB                          0
#define MAC_DCU_CHANNEL_TIME_5_DURATION_MASK                         0x000fffff
#define MAC_DCU_CHANNEL_TIME_5_DURATION_GET(x)                       (((x) & MAC_DCU_CHANNEL_TIME_5_DURATION_MASK) >> MAC_DCU_CHANNEL_TIME_5_DURATION_LSB)
#define MAC_DCU_CHANNEL_TIME_5_DURATION_SET(x)                       (((0 | (x)) << MAC_DCU_CHANNEL_TIME_5_DURATION_LSB) & MAC_DCU_CHANNEL_TIME_5_DURATION_MASK)
#define MAC_DCU_CHANNEL_TIME_5_DURATION_RESET                        0
#define MAC_DCU_CHANNEL_TIME_5_ADDRESS                               0x10d4
#define MAC_DCU_CHANNEL_TIME_5_HW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_5_SW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_5_HW_WRITE_MASK                         0x00000000
#define MAC_DCU_CHANNEL_TIME_5_SW_WRITE_MASK                         0x001fffff
#define MAC_DCU_CHANNEL_TIME_5_RSTMASK                               0xffffffff
#define MAC_DCU_CHANNEL_TIME_5_RESET                                 0x00000000

// 0x10d8 (MAC_DCU_CHANNEL_TIME_6)
#define MAC_DCU_CHANNEL_TIME_6_ENABLE_MSB                            20
#define MAC_DCU_CHANNEL_TIME_6_ENABLE_LSB                            20
#define MAC_DCU_CHANNEL_TIME_6_ENABLE_MASK                           0x00100000
#define MAC_DCU_CHANNEL_TIME_6_ENABLE_GET(x)                         (((x) & MAC_DCU_CHANNEL_TIME_6_ENABLE_MASK) >> MAC_DCU_CHANNEL_TIME_6_ENABLE_LSB)
#define MAC_DCU_CHANNEL_TIME_6_ENABLE_SET(x)                         (((0 | (x)) << MAC_DCU_CHANNEL_TIME_6_ENABLE_LSB) & MAC_DCU_CHANNEL_TIME_6_ENABLE_MASK)
#define MAC_DCU_CHANNEL_TIME_6_ENABLE_RESET                          0
#define MAC_DCU_CHANNEL_TIME_6_DURATION_MSB                          19
#define MAC_DCU_CHANNEL_TIME_6_DURATION_LSB                          0
#define MAC_DCU_CHANNEL_TIME_6_DURATION_MASK                         0x000fffff
#define MAC_DCU_CHANNEL_TIME_6_DURATION_GET(x)                       (((x) & MAC_DCU_CHANNEL_TIME_6_DURATION_MASK) >> MAC_DCU_CHANNEL_TIME_6_DURATION_LSB)
#define MAC_DCU_CHANNEL_TIME_6_DURATION_SET(x)                       (((0 | (x)) << MAC_DCU_CHANNEL_TIME_6_DURATION_LSB) & MAC_DCU_CHANNEL_TIME_6_DURATION_MASK)
#define MAC_DCU_CHANNEL_TIME_6_DURATION_RESET                        0
#define MAC_DCU_CHANNEL_TIME_6_ADDRESS                               0x10d8
#define MAC_DCU_CHANNEL_TIME_6_HW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_6_SW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_6_HW_WRITE_MASK                         0x00000000
#define MAC_DCU_CHANNEL_TIME_6_SW_WRITE_MASK                         0x001fffff
#define MAC_DCU_CHANNEL_TIME_6_RSTMASK                               0xffffffff
#define MAC_DCU_CHANNEL_TIME_6_RESET                                 0x00000000

// 0x10dc (MAC_DCU_CHANNEL_TIME_7)
#define MAC_DCU_CHANNEL_TIME_7_ENABLE_MSB                            20
#define MAC_DCU_CHANNEL_TIME_7_ENABLE_LSB                            20
#define MAC_DCU_CHANNEL_TIME_7_ENABLE_MASK                           0x00100000
#define MAC_DCU_CHANNEL_TIME_7_ENABLE_GET(x)                         (((x) & MAC_DCU_CHANNEL_TIME_7_ENABLE_MASK) >> MAC_DCU_CHANNEL_TIME_7_ENABLE_LSB)
#define MAC_DCU_CHANNEL_TIME_7_ENABLE_SET(x)                         (((0 | (x)) << MAC_DCU_CHANNEL_TIME_7_ENABLE_LSB) & MAC_DCU_CHANNEL_TIME_7_ENABLE_MASK)
#define MAC_DCU_CHANNEL_TIME_7_ENABLE_RESET                          0
#define MAC_DCU_CHANNEL_TIME_7_DURATION_MSB                          19
#define MAC_DCU_CHANNEL_TIME_7_DURATION_LSB                          0
#define MAC_DCU_CHANNEL_TIME_7_DURATION_MASK                         0x000fffff
#define MAC_DCU_CHANNEL_TIME_7_DURATION_GET(x)                       (((x) & MAC_DCU_CHANNEL_TIME_7_DURATION_MASK) >> MAC_DCU_CHANNEL_TIME_7_DURATION_LSB)
#define MAC_DCU_CHANNEL_TIME_7_DURATION_SET(x)                       (((0 | (x)) << MAC_DCU_CHANNEL_TIME_7_DURATION_LSB) & MAC_DCU_CHANNEL_TIME_7_DURATION_MASK)
#define MAC_DCU_CHANNEL_TIME_7_DURATION_RESET                        0
#define MAC_DCU_CHANNEL_TIME_7_ADDRESS                               0x10dc
#define MAC_DCU_CHANNEL_TIME_7_HW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_7_SW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_7_HW_WRITE_MASK                         0x00000000
#define MAC_DCU_CHANNEL_TIME_7_SW_WRITE_MASK                         0x001fffff
#define MAC_DCU_CHANNEL_TIME_7_RSTMASK                               0xffffffff
#define MAC_DCU_CHANNEL_TIME_7_RESET                                 0x00000000

// 0x10e0 (MAC_DCU_CHANNEL_TIME_8)
#define MAC_DCU_CHANNEL_TIME_8_ENABLE_MSB                            20
#define MAC_DCU_CHANNEL_TIME_8_ENABLE_LSB                            20
#define MAC_DCU_CHANNEL_TIME_8_ENABLE_MASK                           0x00100000
#define MAC_DCU_CHANNEL_TIME_8_ENABLE_GET(x)                         (((x) & MAC_DCU_CHANNEL_TIME_8_ENABLE_MASK) >> MAC_DCU_CHANNEL_TIME_8_ENABLE_LSB)
#define MAC_DCU_CHANNEL_TIME_8_ENABLE_SET(x)                         (((0 | (x)) << MAC_DCU_CHANNEL_TIME_8_ENABLE_LSB) & MAC_DCU_CHANNEL_TIME_8_ENABLE_MASK)
#define MAC_DCU_CHANNEL_TIME_8_ENABLE_RESET                          0
#define MAC_DCU_CHANNEL_TIME_8_DURATION_MSB                          19
#define MAC_DCU_CHANNEL_TIME_8_DURATION_LSB                          0
#define MAC_DCU_CHANNEL_TIME_8_DURATION_MASK                         0x000fffff
#define MAC_DCU_CHANNEL_TIME_8_DURATION_GET(x)                       (((x) & MAC_DCU_CHANNEL_TIME_8_DURATION_MASK) >> MAC_DCU_CHANNEL_TIME_8_DURATION_LSB)
#define MAC_DCU_CHANNEL_TIME_8_DURATION_SET(x)                       (((0 | (x)) << MAC_DCU_CHANNEL_TIME_8_DURATION_LSB) & MAC_DCU_CHANNEL_TIME_8_DURATION_MASK)
#define MAC_DCU_CHANNEL_TIME_8_DURATION_RESET                        0
#define MAC_DCU_CHANNEL_TIME_8_ADDRESS                               0x10e0
#define MAC_DCU_CHANNEL_TIME_8_HW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_8_SW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_8_HW_WRITE_MASK                         0x00000000
#define MAC_DCU_CHANNEL_TIME_8_SW_WRITE_MASK                         0x001fffff
#define MAC_DCU_CHANNEL_TIME_8_RSTMASK                               0xffffffff
#define MAC_DCU_CHANNEL_TIME_8_RESET                                 0x00000000

// 0x10e4 (MAC_DCU_CHANNEL_TIME_9)
#define MAC_DCU_CHANNEL_TIME_9_ENABLE_MSB                            20
#define MAC_DCU_CHANNEL_TIME_9_ENABLE_LSB                            20
#define MAC_DCU_CHANNEL_TIME_9_ENABLE_MASK                           0x00100000
#define MAC_DCU_CHANNEL_TIME_9_ENABLE_GET(x)                         (((x) & MAC_DCU_CHANNEL_TIME_9_ENABLE_MASK) >> MAC_DCU_CHANNEL_TIME_9_ENABLE_LSB)
#define MAC_DCU_CHANNEL_TIME_9_ENABLE_SET(x)                         (((0 | (x)) << MAC_DCU_CHANNEL_TIME_9_ENABLE_LSB) & MAC_DCU_CHANNEL_TIME_9_ENABLE_MASK)
#define MAC_DCU_CHANNEL_TIME_9_ENABLE_RESET                          0
#define MAC_DCU_CHANNEL_TIME_9_DURATION_MSB                          19
#define MAC_DCU_CHANNEL_TIME_9_DURATION_LSB                          0
#define MAC_DCU_CHANNEL_TIME_9_DURATION_MASK                         0x000fffff
#define MAC_DCU_CHANNEL_TIME_9_DURATION_GET(x)                       (((x) & MAC_DCU_CHANNEL_TIME_9_DURATION_MASK) >> MAC_DCU_CHANNEL_TIME_9_DURATION_LSB)
#define MAC_DCU_CHANNEL_TIME_9_DURATION_SET(x)                       (((0 | (x)) << MAC_DCU_CHANNEL_TIME_9_DURATION_LSB) & MAC_DCU_CHANNEL_TIME_9_DURATION_MASK)
#define MAC_DCU_CHANNEL_TIME_9_DURATION_RESET                        0
#define MAC_DCU_CHANNEL_TIME_9_ADDRESS                               0x10e4
#define MAC_DCU_CHANNEL_TIME_9_HW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_9_SW_MASK                               0x001fffff
#define MAC_DCU_CHANNEL_TIME_9_HW_WRITE_MASK                         0x00000000
#define MAC_DCU_CHANNEL_TIME_9_SW_WRITE_MASK                         0x001fffff
#define MAC_DCU_CHANNEL_TIME_9_RSTMASK                               0xffffffff
#define MAC_DCU_CHANNEL_TIME_9_RESET                                 0x00000000

// 0x10f0 (MAC_DCU_GBL_IFS_MISC)
#define MAC_DCU_GBL_IFS_MISC_SLOT_COUNT_RST_UNCOND_MSB               29
#define MAC_DCU_GBL_IFS_MISC_SLOT_COUNT_RST_UNCOND_LSB               29
#define MAC_DCU_GBL_IFS_MISC_SLOT_COUNT_RST_UNCOND_MASK              0x20000000
#define MAC_DCU_GBL_IFS_MISC_SLOT_COUNT_RST_UNCOND_GET(x)            (((x) & MAC_DCU_GBL_IFS_MISC_SLOT_COUNT_RST_UNCOND_MASK) >> MAC_DCU_GBL_IFS_MISC_SLOT_COUNT_RST_UNCOND_LSB)
#define MAC_DCU_GBL_IFS_MISC_SLOT_COUNT_RST_UNCOND_SET(x)            (((0 | (x)) << MAC_DCU_GBL_IFS_MISC_SLOT_COUNT_RST_UNCOND_LSB) & MAC_DCU_GBL_IFS_MISC_SLOT_COUNT_RST_UNCOND_MASK)
#define MAC_DCU_GBL_IFS_MISC_SLOT_COUNT_RST_UNCOND_RESET             0
#define MAC_DCU_GBL_IFS_MISC_IGNORE_BACKOFF_MSB                      28
#define MAC_DCU_GBL_IFS_MISC_IGNORE_BACKOFF_LSB                      28
#define MAC_DCU_GBL_IFS_MISC_IGNORE_BACKOFF_MASK                     0x10000000
#define MAC_DCU_GBL_IFS_MISC_IGNORE_BACKOFF_GET(x)                   (((x) & MAC_DCU_GBL_IFS_MISC_IGNORE_BACKOFF_MASK) >> MAC_DCU_GBL_IFS_MISC_IGNORE_BACKOFF_LSB)
#define MAC_DCU_GBL_IFS_MISC_IGNORE_BACKOFF_SET(x)                   (((0 | (x)) << MAC_DCU_GBL_IFS_MISC_IGNORE_BACKOFF_LSB) & MAC_DCU_GBL_IFS_MISC_IGNORE_BACKOFF_MASK)
#define MAC_DCU_GBL_IFS_MISC_IGNORE_BACKOFF_RESET                    0
#define MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_ALWAYS_MSB                    27
#define MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_ALWAYS_LSB                    27
#define MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_ALWAYS_MASK                   0x08000000
#define MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_ALWAYS_GET(x)                 (((x) & MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_ALWAYS_MASK) >> MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_ALWAYS_LSB)
#define MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_ALWAYS_SET(x)                 (((0 | (x)) << MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_ALWAYS_LSB) & MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_ALWAYS_MASK)
#define MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_ALWAYS_RESET                  0
#define MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_WIN_DUR_MSB                   26
#define MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_WIN_DUR_LSB                   25
#define MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_WIN_DUR_MASK                  0x06000000
#define MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_WIN_DUR_GET(x)                (((x) & MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_WIN_DUR_MASK) >> MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_WIN_DUR_LSB)
#define MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_WIN_DUR_SET(x)                (((0 | (x)) << MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_WIN_DUR_LSB) & MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_WIN_DUR_MASK)
#define MAC_DCU_GBL_IFS_MISC_CHAN_SLOT_WIN_DUR_RESET                 0
#define MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_RANDOM_DIS_MSB               24
#define MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_RANDOM_DIS_LSB               24
#define MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_RANDOM_DIS_MASK              0x01000000
#define MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_RANDOM_DIS_GET(x)            (((x) & MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_RANDOM_DIS_MASK) >> MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_RANDOM_DIS_LSB)
#define MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_RANDOM_DIS_SET(x)            (((0 | (x)) << MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_RANDOM_DIS_LSB) & MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_RANDOM_DIS_MASK)
#define MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_RANDOM_DIS_RESET             0
#define MAC_DCU_GBL_IFS_MISC_AIFS_RST_UNCOND_MSB                     23
#define MAC_DCU_GBL_IFS_MISC_AIFS_RST_UNCOND_LSB                     23
#define MAC_DCU_GBL_IFS_MISC_AIFS_RST_UNCOND_MASK                    0x00800000
#define MAC_DCU_GBL_IFS_MISC_AIFS_RST_UNCOND_GET(x)                  (((x) & MAC_DCU_GBL_IFS_MISC_AIFS_RST_UNCOND_MASK) >> MAC_DCU_GBL_IFS_MISC_AIFS_RST_UNCOND_LSB)
#define MAC_DCU_GBL_IFS_MISC_AIFS_RST_UNCOND_SET(x)                  (((0 | (x)) << MAC_DCU_GBL_IFS_MISC_AIFS_RST_UNCOND_LSB) & MAC_DCU_GBL_IFS_MISC_AIFS_RST_UNCOND_MASK)
#define MAC_DCU_GBL_IFS_MISC_AIFS_RST_UNCOND_RESET                   0
#define MAC_DCU_GBL_IFS_MISC_SIFS_RST_UNCOND_MSB                     22
#define MAC_DCU_GBL_IFS_MISC_SIFS_RST_UNCOND_LSB                     22
#define MAC_DCU_GBL_IFS_MISC_SIFS_RST_UNCOND_MASK                    0x00400000
#define MAC_DCU_GBL_IFS_MISC_SIFS_RST_UNCOND_GET(x)                  (((x) & MAC_DCU_GBL_IFS_MISC_SIFS_RST_UNCOND_MASK) >> MAC_DCU_GBL_IFS_MISC_SIFS_RST_UNCOND_LSB)
#define MAC_DCU_GBL_IFS_MISC_SIFS_RST_UNCOND_SET(x)                  (((0 | (x)) << MAC_DCU_GBL_IFS_MISC_SIFS_RST_UNCOND_LSB) & MAC_DCU_GBL_IFS_MISC_SIFS_RST_UNCOND_MASK)
#define MAC_DCU_GBL_IFS_MISC_SIFS_RST_UNCOND_RESET                   0
#define MAC_DCU_GBL_IFS_MISC_ARB_DLY_MSB                             21
#define MAC_DCU_GBL_IFS_MISC_ARB_DLY_LSB                             20
#define MAC_DCU_GBL_IFS_MISC_ARB_DLY_MASK                            0x00300000
#define MAC_DCU_GBL_IFS_MISC_ARB_DLY_GET(x)                          (((x) & MAC_DCU_GBL_IFS_MISC_ARB_DLY_MASK) >> MAC_DCU_GBL_IFS_MISC_ARB_DLY_LSB)
#define MAC_DCU_GBL_IFS_MISC_ARB_DLY_SET(x)                          (((0 | (x)) << MAC_DCU_GBL_IFS_MISC_ARB_DLY_LSB) & MAC_DCU_GBL_IFS_MISC_ARB_DLY_MASK)
#define MAC_DCU_GBL_IFS_MISC_ARB_DLY_RESET                           0
#define MAC_DCU_GBL_IFS_MISC_SIFS_DUR_USEC_MSB                       9
#define MAC_DCU_GBL_IFS_MISC_SIFS_DUR_USEC_LSB                       4
#define MAC_DCU_GBL_IFS_MISC_SIFS_DUR_USEC_MASK                      0x000003f0
#define MAC_DCU_GBL_IFS_MISC_SIFS_DUR_USEC_GET(x)                    (((x) & MAC_DCU_GBL_IFS_MISC_SIFS_DUR_USEC_MASK) >> MAC_DCU_GBL_IFS_MISC_SIFS_DUR_USEC_LSB)
#define MAC_DCU_GBL_IFS_MISC_SIFS_DUR_USEC_SET(x)                    (((0 | (x)) << MAC_DCU_GBL_IFS_MISC_SIFS_DUR_USEC_LSB) & MAC_DCU_GBL_IFS_MISC_SIFS_DUR_USEC_MASK)
#define MAC_DCU_GBL_IFS_MISC_SIFS_DUR_USEC_RESET                     16
#define MAC_DCU_GBL_IFS_MISC_TURBO_MODE_MSB                          3
#define MAC_DCU_GBL_IFS_MISC_TURBO_MODE_LSB                          3
#define MAC_DCU_GBL_IFS_MISC_TURBO_MODE_MASK                         0x00000008
#define MAC_DCU_GBL_IFS_MISC_TURBO_MODE_GET(x)                       (((x) & MAC_DCU_GBL_IFS_MISC_TURBO_MODE_MASK) >> MAC_DCU_GBL_IFS_MISC_TURBO_MODE_LSB)
#define MAC_DCU_GBL_IFS_MISC_TURBO_MODE_SET(x)                       (((0 | (x)) << MAC_DCU_GBL_IFS_MISC_TURBO_MODE_LSB) & MAC_DCU_GBL_IFS_MISC_TURBO_MODE_MASK)
#define MAC_DCU_GBL_IFS_MISC_TURBO_MODE_RESET                        0
#define MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_SEL_MSB                      2
#define MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_SEL_LSB                      0
#define MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_SEL_MASK                     0x00000007
#define MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_SEL_GET(x)                   (((x) & MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_SEL_MASK) >> MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_SEL_LSB)
#define MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_SEL_SET(x)                   (((0 | (x)) << MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_SEL_LSB) & MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_SEL_MASK)
#define MAC_DCU_GBL_IFS_MISC_LFSR_SLICE_SEL_RESET                    0
#define MAC_DCU_GBL_IFS_MISC_ADDRESS                                 0x10f0
#define MAC_DCU_GBL_IFS_MISC_HW_MASK                                 0x3ff003ff
#define MAC_DCU_GBL_IFS_MISC_SW_MASK                                 0x3ff003ff
#define MAC_DCU_GBL_IFS_MISC_HW_WRITE_MASK                           0x00000000
#define MAC_DCU_GBL_IFS_MISC_SW_WRITE_MASK                           0x3ff003ff
#define MAC_DCU_GBL_IFS_MISC_RSTMASK                                 0xffffffff
#define MAC_DCU_GBL_IFS_MISC_RESET                                   0x00000100

// 0x10f8 (MAC_DCU_TXFILTER_DCU0_127_96)
#define MAC_DCU_TXFILTER_DCU0_127_96_DATA_MSB                        31
#define MAC_DCU_TXFILTER_DCU0_127_96_DATA_LSB                        0
#define MAC_DCU_TXFILTER_DCU0_127_96_DATA_MASK                       0xffffffff
#define MAC_DCU_TXFILTER_DCU0_127_96_DATA_GET(x)                     (((x) & MAC_DCU_TXFILTER_DCU0_127_96_DATA_MASK) >> MAC_DCU_TXFILTER_DCU0_127_96_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU0_127_96_DATA_SET(x)                     (((0 | (x)) << MAC_DCU_TXFILTER_DCU0_127_96_DATA_LSB) & MAC_DCU_TXFILTER_DCU0_127_96_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU0_127_96_DATA_RESET                      0
#define MAC_DCU_TXFILTER_DCU0_127_96_ADDRESS                         0x10f8
#define MAC_DCU_TXFILTER_DCU0_127_96_HW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU0_127_96_SW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU0_127_96_HW_WRITE_MASK                   0x00000000
#define MAC_DCU_TXFILTER_DCU0_127_96_SW_WRITE_MASK                   0xffffffff
#define MAC_DCU_TXFILTER_DCU0_127_96_RSTMASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU0_127_96_RESET                           0x00000000

// 0x10fc (MAC_DCU_TXFILTER_DCU8_127_96)
#define MAC_DCU_TXFILTER_DCU8_127_96_DATA_MSB                        31
#define MAC_DCU_TXFILTER_DCU8_127_96_DATA_LSB                        0
#define MAC_DCU_TXFILTER_DCU8_127_96_DATA_MASK                       0xffffffff
#define MAC_DCU_TXFILTER_DCU8_127_96_DATA_GET(x)                     (((x) & MAC_DCU_TXFILTER_DCU8_127_96_DATA_MASK) >> MAC_DCU_TXFILTER_DCU8_127_96_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU8_127_96_DATA_SET(x)                     (((0 | (x)) << MAC_DCU_TXFILTER_DCU8_127_96_DATA_LSB) & MAC_DCU_TXFILTER_DCU8_127_96_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU8_127_96_DATA_RESET                      0
#define MAC_DCU_TXFILTER_DCU8_127_96_ADDRESS                         0x10fc
#define MAC_DCU_TXFILTER_DCU8_127_96_HW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU8_127_96_SW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU8_127_96_HW_WRITE_MASK                   0xffffffff
#define MAC_DCU_TXFILTER_DCU8_127_96_SW_WRITE_MASK                   0x00000000
#define MAC_DCU_TXFILTER_DCU8_127_96_RSTMASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU8_127_96_RESET                           0x00000000

// 0x1100 (MAC_DCU_MISC_0)
#define MAC_DCU_MISC_0_SIFS_BURST_CHAN_BUSY_IGNORE_MSB               24
#define MAC_DCU_MISC_0_SIFS_BURST_CHAN_BUSY_IGNORE_LSB               24
#define MAC_DCU_MISC_0_SIFS_BURST_CHAN_BUSY_IGNORE_MASK              0x01000000
#define MAC_DCU_MISC_0_SIFS_BURST_CHAN_BUSY_IGNORE_GET(x)            (((x) & MAC_DCU_MISC_0_SIFS_BURST_CHAN_BUSY_IGNORE_MASK) >> MAC_DCU_MISC_0_SIFS_BURST_CHAN_BUSY_IGNORE_LSB)
#define MAC_DCU_MISC_0_SIFS_BURST_CHAN_BUSY_IGNORE_SET(x)            (((0 | (x)) << MAC_DCU_MISC_0_SIFS_BURST_CHAN_BUSY_IGNORE_LSB) & MAC_DCU_MISC_0_SIFS_BURST_CHAN_BUSY_IGNORE_MASK)
#define MAC_DCU_MISC_0_SIFS_BURST_CHAN_BUSY_IGNORE_RESET             1
#define MAC_DCU_MISC_0_RETRY_ON_BLOWN_IFS_EN_MSB                     23
#define MAC_DCU_MISC_0_RETRY_ON_BLOWN_IFS_EN_LSB                     23
#define MAC_DCU_MISC_0_RETRY_ON_BLOWN_IFS_EN_MASK                    0x00800000
#define MAC_DCU_MISC_0_RETRY_ON_BLOWN_IFS_EN_GET(x)                  (((x) & MAC_DCU_MISC_0_RETRY_ON_BLOWN_IFS_EN_MASK) >> MAC_DCU_MISC_0_RETRY_ON_BLOWN_IFS_EN_LSB)
#define MAC_DCU_MISC_0_RETRY_ON_BLOWN_IFS_EN_SET(x)                  (((0 | (x)) << MAC_DCU_MISC_0_RETRY_ON_BLOWN_IFS_EN_LSB) & MAC_DCU_MISC_0_RETRY_ON_BLOWN_IFS_EN_MASK)
#define MAC_DCU_MISC_0_RETRY_ON_BLOWN_IFS_EN_RESET                   0
#define MAC_DCU_MISC_0_VIRT_COLL_CW_INC_EN_MSB                       22
#define MAC_DCU_MISC_0_VIRT_COLL_CW_INC_EN_LSB                       22
#define MAC_DCU_MISC_0_VIRT_COLL_CW_INC_EN_MASK                      0x00400000
#define MAC_DCU_MISC_0_VIRT_COLL_CW_INC_EN_GET(x)                    (((x) & MAC_DCU_MISC_0_VIRT_COLL_CW_INC_EN_MASK) >> MAC_DCU_MISC_0_VIRT_COLL_CW_INC_EN_LSB)
#define MAC_DCU_MISC_0_VIRT_COLL_CW_INC_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_0_VIRT_COLL_CW_INC_EN_LSB) & MAC_DCU_MISC_0_VIRT_COLL_CW_INC_EN_MASK)
#define MAC_DCU_MISC_0_VIRT_COLL_CW_INC_EN_RESET                     0
#define MAC_DCU_MISC_0_POST_BKOFF_SKIP_MSB                           21
#define MAC_DCU_MISC_0_POST_BKOFF_SKIP_LSB                           21
#define MAC_DCU_MISC_0_POST_BKOFF_SKIP_MASK                          0x00200000
#define MAC_DCU_MISC_0_POST_BKOFF_SKIP_GET(x)                        (((x) & MAC_DCU_MISC_0_POST_BKOFF_SKIP_MASK) >> MAC_DCU_MISC_0_POST_BKOFF_SKIP_LSB)
#define MAC_DCU_MISC_0_POST_BKOFF_SKIP_SET(x)                        (((0 | (x)) << MAC_DCU_MISC_0_POST_BKOFF_SKIP_LSB) & MAC_DCU_MISC_0_POST_BKOFF_SKIP_MASK)
#define MAC_DCU_MISC_0_POST_BKOFF_SKIP_RESET                         0
#define MAC_DCU_MISC_0_SEQNUM_FREEZE_MSB                             20
#define MAC_DCU_MISC_0_SEQNUM_FREEZE_LSB                             20
#define MAC_DCU_MISC_0_SEQNUM_FREEZE_MASK                            0x00100000
#define MAC_DCU_MISC_0_SEQNUM_FREEZE_GET(x)                          (((x) & MAC_DCU_MISC_0_SEQNUM_FREEZE_MASK) >> MAC_DCU_MISC_0_SEQNUM_FREEZE_LSB)
#define MAC_DCU_MISC_0_SEQNUM_FREEZE_SET(x)                          (((0 | (x)) << MAC_DCU_MISC_0_SEQNUM_FREEZE_LSB) & MAC_DCU_MISC_0_SEQNUM_FREEZE_MASK)
#define MAC_DCU_MISC_0_SEQNUM_FREEZE_RESET                           0
#define MAC_DCU_MISC_0_LOCKOUT_IGNORE_MSB                            19
#define MAC_DCU_MISC_0_LOCKOUT_IGNORE_LSB                            19
#define MAC_DCU_MISC_0_LOCKOUT_IGNORE_MASK                           0x00080000
#define MAC_DCU_MISC_0_LOCKOUT_IGNORE_GET(x)                         (((x) & MAC_DCU_MISC_0_LOCKOUT_IGNORE_MASK) >> MAC_DCU_MISC_0_LOCKOUT_IGNORE_LSB)
#define MAC_DCU_MISC_0_LOCKOUT_IGNORE_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_0_LOCKOUT_IGNORE_LSB) & MAC_DCU_MISC_0_LOCKOUT_IGNORE_MASK)
#define MAC_DCU_MISC_0_LOCKOUT_IGNORE_RESET                          0
#define MAC_DCU_MISC_0_LOCKOUT_GBL_EN_MSB                            18
#define MAC_DCU_MISC_0_LOCKOUT_GBL_EN_LSB                            18
#define MAC_DCU_MISC_0_LOCKOUT_GBL_EN_MASK                           0x00040000
#define MAC_DCU_MISC_0_LOCKOUT_GBL_EN_GET(x)                         (((x) & MAC_DCU_MISC_0_LOCKOUT_GBL_EN_MASK) >> MAC_DCU_MISC_0_LOCKOUT_GBL_EN_LSB)
#define MAC_DCU_MISC_0_LOCKOUT_GBL_EN_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_0_LOCKOUT_GBL_EN_LSB) & MAC_DCU_MISC_0_LOCKOUT_GBL_EN_MASK)
#define MAC_DCU_MISC_0_LOCKOUT_GBL_EN_RESET                          0
#define MAC_DCU_MISC_0_ARB_LOCKOUT_IF_EN_MSB                         17
#define MAC_DCU_MISC_0_ARB_LOCKOUT_IF_EN_LSB                         17
#define MAC_DCU_MISC_0_ARB_LOCKOUT_IF_EN_MASK                        0x00020000
#define MAC_DCU_MISC_0_ARB_LOCKOUT_IF_EN_GET(x)                      (((x) & MAC_DCU_MISC_0_ARB_LOCKOUT_IF_EN_MASK) >> MAC_DCU_MISC_0_ARB_LOCKOUT_IF_EN_LSB)
#define MAC_DCU_MISC_0_ARB_LOCKOUT_IF_EN_SET(x)                      (((0 | (x)) << MAC_DCU_MISC_0_ARB_LOCKOUT_IF_EN_LSB) & MAC_DCU_MISC_0_ARB_LOCKOUT_IF_EN_MASK)
#define MAC_DCU_MISC_0_ARB_LOCKOUT_IF_EN_RESET                       0
#define MAC_DCU_MISC_0_IS_BCN_MSB                                    16
#define MAC_DCU_MISC_0_IS_BCN_LSB                                    16
#define MAC_DCU_MISC_0_IS_BCN_MASK                                   0x00010000
#define MAC_DCU_MISC_0_IS_BCN_GET(x)                                 (((x) & MAC_DCU_MISC_0_IS_BCN_MASK) >> MAC_DCU_MISC_0_IS_BCN_LSB)
#define MAC_DCU_MISC_0_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_DCU_MISC_0_IS_BCN_LSB) & MAC_DCU_MISC_0_IS_BCN_MASK)
#define MAC_DCU_MISC_0_IS_BCN_RESET                                  0
#define MAC_DCU_MISC_0_VIRT_COLL_POLICY_MSB                          15
#define MAC_DCU_MISC_0_VIRT_COLL_POLICY_LSB                          14
#define MAC_DCU_MISC_0_VIRT_COLL_POLICY_MASK                         0x0000c000
#define MAC_DCU_MISC_0_VIRT_COLL_POLICY_GET(x)                       (((x) & MAC_DCU_MISC_0_VIRT_COLL_POLICY_MASK) >> MAC_DCU_MISC_0_VIRT_COLL_POLICY_LSB)
#define MAC_DCU_MISC_0_VIRT_COLL_POLICY_SET(x)                       (((0 | (x)) << MAC_DCU_MISC_0_VIRT_COLL_POLICY_LSB) & MAC_DCU_MISC_0_VIRT_COLL_POLICY_MASK)
#define MAC_DCU_MISC_0_VIRT_COLL_POLICY_RESET                        0
#define MAC_DCU_MISC_0_BKOFF_PF_MSB                                  12
#define MAC_DCU_MISC_0_BKOFF_PF_LSB                                  12
#define MAC_DCU_MISC_0_BKOFF_PF_MASK                                 0x00001000
#define MAC_DCU_MISC_0_BKOFF_PF_GET(x)                               (((x) & MAC_DCU_MISC_0_BKOFF_PF_MASK) >> MAC_DCU_MISC_0_BKOFF_PF_LSB)
#define MAC_DCU_MISC_0_BKOFF_PF_SET(x)                               (((0 | (x)) << MAC_DCU_MISC_0_BKOFF_PF_LSB) & MAC_DCU_MISC_0_BKOFF_PF_MASK)
#define MAC_DCU_MISC_0_BKOFF_PF_RESET                                0
#define MAC_DCU_MISC_0_HCF_POLL_EN_MSB                               11
#define MAC_DCU_MISC_0_HCF_POLL_EN_LSB                               11
#define MAC_DCU_MISC_0_HCF_POLL_EN_MASK                              0x00000800
#define MAC_DCU_MISC_0_HCF_POLL_EN_GET(x)                            (((x) & MAC_DCU_MISC_0_HCF_POLL_EN_MASK) >> MAC_DCU_MISC_0_HCF_POLL_EN_LSB)
#define MAC_DCU_MISC_0_HCF_POLL_EN_SET(x)                            (((0 | (x)) << MAC_DCU_MISC_0_HCF_POLL_EN_LSB) & MAC_DCU_MISC_0_HCF_POLL_EN_MASK)
#define MAC_DCU_MISC_0_HCF_POLL_EN_RESET                             0
#define MAC_DCU_MISC_0_FRAG_BURST_BKOFF_EN_MSB                       9
#define MAC_DCU_MISC_0_FRAG_BURST_BKOFF_EN_LSB                       9
#define MAC_DCU_MISC_0_FRAG_BURST_BKOFF_EN_MASK                      0x00000200
#define MAC_DCU_MISC_0_FRAG_BURST_BKOFF_EN_GET(x)                    (((x) & MAC_DCU_MISC_0_FRAG_BURST_BKOFF_EN_MASK) >> MAC_DCU_MISC_0_FRAG_BURST_BKOFF_EN_LSB)
#define MAC_DCU_MISC_0_FRAG_BURST_BKOFF_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_0_FRAG_BURST_BKOFF_EN_LSB) & MAC_DCU_MISC_0_FRAG_BURST_BKOFF_EN_MASK)
#define MAC_DCU_MISC_0_FRAG_BURST_BKOFF_EN_RESET                     0
#define MAC_DCU_MISC_0_FRAG_BURST_WAIT_QCU_EN_MSB                    8
#define MAC_DCU_MISC_0_FRAG_BURST_WAIT_QCU_EN_LSB                    8
#define MAC_DCU_MISC_0_FRAG_BURST_WAIT_QCU_EN_MASK                   0x00000100
#define MAC_DCU_MISC_0_FRAG_BURST_WAIT_QCU_EN_GET(x)                 (((x) & MAC_DCU_MISC_0_FRAG_BURST_WAIT_QCU_EN_MASK) >> MAC_DCU_MISC_0_FRAG_BURST_WAIT_QCU_EN_LSB)
#define MAC_DCU_MISC_0_FRAG_BURST_WAIT_QCU_EN_SET(x)                 (((0 | (x)) << MAC_DCU_MISC_0_FRAG_BURST_WAIT_QCU_EN_LSB) & MAC_DCU_MISC_0_FRAG_BURST_WAIT_QCU_EN_MASK)
#define MAC_DCU_MISC_0_FRAG_BURST_WAIT_QCU_EN_RESET                  0
#define MAC_DCU_MISC_0_CW_RST_AT_TS_END_DIS_MSB                      7
#define MAC_DCU_MISC_0_CW_RST_AT_TS_END_DIS_LSB                      7
#define MAC_DCU_MISC_0_CW_RST_AT_TS_END_DIS_MASK                     0x00000080
#define MAC_DCU_MISC_0_CW_RST_AT_TS_END_DIS_GET(x)                   (((x) & MAC_DCU_MISC_0_CW_RST_AT_TS_END_DIS_MASK) >> MAC_DCU_MISC_0_CW_RST_AT_TS_END_DIS_LSB)
#define MAC_DCU_MISC_0_CW_RST_AT_TS_END_DIS_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_0_CW_RST_AT_TS_END_DIS_LSB) & MAC_DCU_MISC_0_CW_RST_AT_TS_END_DIS_MASK)
#define MAC_DCU_MISC_0_CW_RST_AT_TS_END_DIS_RESET                    0
#define MAC_DCU_MISC_0_SFC_RST_AT_TS_END_EN_MSB                      6
#define MAC_DCU_MISC_0_SFC_RST_AT_TS_END_EN_LSB                      6
#define MAC_DCU_MISC_0_SFC_RST_AT_TS_END_EN_MASK                     0x00000040
#define MAC_DCU_MISC_0_SFC_RST_AT_TS_END_EN_GET(x)                   (((x) & MAC_DCU_MISC_0_SFC_RST_AT_TS_END_EN_MASK) >> MAC_DCU_MISC_0_SFC_RST_AT_TS_END_EN_LSB)
#define MAC_DCU_MISC_0_SFC_RST_AT_TS_END_EN_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_0_SFC_RST_AT_TS_END_EN_LSB) & MAC_DCU_MISC_0_SFC_RST_AT_TS_END_EN_MASK)
#define MAC_DCU_MISC_0_SFC_RST_AT_TS_END_EN_RESET                    0
#define MAC_DCU_MISC_0_BKOFF_THRESH_MSB                              5
#define MAC_DCU_MISC_0_BKOFF_THRESH_LSB                              0
#define MAC_DCU_MISC_0_BKOFF_THRESH_MASK                             0x0000003f
#define MAC_DCU_MISC_0_BKOFF_THRESH_GET(x)                           (((x) & MAC_DCU_MISC_0_BKOFF_THRESH_MASK) >> MAC_DCU_MISC_0_BKOFF_THRESH_LSB)
#define MAC_DCU_MISC_0_BKOFF_THRESH_SET(x)                           (((0 | (x)) << MAC_DCU_MISC_0_BKOFF_THRESH_LSB) & MAC_DCU_MISC_0_BKOFF_THRESH_MASK)
#define MAC_DCU_MISC_0_BKOFF_THRESH_RESET                            0
#define MAC_DCU_MISC_0_ADDRESS                                       0x1100
#define MAC_DCU_MISC_ADDRESS                                         MAC_DCU_MISC_0_ADDRESS
#define MAC_DCU_MISC_0_HW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_0_SW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_0_HW_WRITE_MASK                                 0x00000000
#define MAC_DCU_MISC_0_SW_WRITE_MASK                                 0x01ffdbff
#define MAC_DCU_MISC_0_RSTMASK                                       0xffffffff
#define MAC_DCU_MISC_0_RESET                                         0x01000000

// 0x1104 (MAC_DCU_MISC_1)
#define MAC_DCU_MISC_1_SIFS_BURST_CHAN_BUSY_IGNORE_MSB               24
#define MAC_DCU_MISC_1_SIFS_BURST_CHAN_BUSY_IGNORE_LSB               24
#define MAC_DCU_MISC_1_SIFS_BURST_CHAN_BUSY_IGNORE_MASK              0x01000000
#define MAC_DCU_MISC_1_SIFS_BURST_CHAN_BUSY_IGNORE_GET(x)            (((x) & MAC_DCU_MISC_1_SIFS_BURST_CHAN_BUSY_IGNORE_MASK) >> MAC_DCU_MISC_1_SIFS_BURST_CHAN_BUSY_IGNORE_LSB)
#define MAC_DCU_MISC_1_SIFS_BURST_CHAN_BUSY_IGNORE_SET(x)            (((0 | (x)) << MAC_DCU_MISC_1_SIFS_BURST_CHAN_BUSY_IGNORE_LSB) & MAC_DCU_MISC_1_SIFS_BURST_CHAN_BUSY_IGNORE_MASK)
#define MAC_DCU_MISC_1_SIFS_BURST_CHAN_BUSY_IGNORE_RESET             1
#define MAC_DCU_MISC_1_RETRY_ON_BLOWN_IFS_EN_MSB                     23
#define MAC_DCU_MISC_1_RETRY_ON_BLOWN_IFS_EN_LSB                     23
#define MAC_DCU_MISC_1_RETRY_ON_BLOWN_IFS_EN_MASK                    0x00800000
#define MAC_DCU_MISC_1_RETRY_ON_BLOWN_IFS_EN_GET(x)                  (((x) & MAC_DCU_MISC_1_RETRY_ON_BLOWN_IFS_EN_MASK) >> MAC_DCU_MISC_1_RETRY_ON_BLOWN_IFS_EN_LSB)
#define MAC_DCU_MISC_1_RETRY_ON_BLOWN_IFS_EN_SET(x)                  (((0 | (x)) << MAC_DCU_MISC_1_RETRY_ON_BLOWN_IFS_EN_LSB) & MAC_DCU_MISC_1_RETRY_ON_BLOWN_IFS_EN_MASK)
#define MAC_DCU_MISC_1_RETRY_ON_BLOWN_IFS_EN_RESET                   0
#define MAC_DCU_MISC_1_VIRT_COLL_CW_INC_EN_MSB                       22
#define MAC_DCU_MISC_1_VIRT_COLL_CW_INC_EN_LSB                       22
#define MAC_DCU_MISC_1_VIRT_COLL_CW_INC_EN_MASK                      0x00400000
#define MAC_DCU_MISC_1_VIRT_COLL_CW_INC_EN_GET(x)                    (((x) & MAC_DCU_MISC_1_VIRT_COLL_CW_INC_EN_MASK) >> MAC_DCU_MISC_1_VIRT_COLL_CW_INC_EN_LSB)
#define MAC_DCU_MISC_1_VIRT_COLL_CW_INC_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_1_VIRT_COLL_CW_INC_EN_LSB) & MAC_DCU_MISC_1_VIRT_COLL_CW_INC_EN_MASK)
#define MAC_DCU_MISC_1_VIRT_COLL_CW_INC_EN_RESET                     0
#define MAC_DCU_MISC_1_POST_BKOFF_SKIP_MSB                           21
#define MAC_DCU_MISC_1_POST_BKOFF_SKIP_LSB                           21
#define MAC_DCU_MISC_1_POST_BKOFF_SKIP_MASK                          0x00200000
#define MAC_DCU_MISC_1_POST_BKOFF_SKIP_GET(x)                        (((x) & MAC_DCU_MISC_1_POST_BKOFF_SKIP_MASK) >> MAC_DCU_MISC_1_POST_BKOFF_SKIP_LSB)
#define MAC_DCU_MISC_1_POST_BKOFF_SKIP_SET(x)                        (((0 | (x)) << MAC_DCU_MISC_1_POST_BKOFF_SKIP_LSB) & MAC_DCU_MISC_1_POST_BKOFF_SKIP_MASK)
#define MAC_DCU_MISC_1_POST_BKOFF_SKIP_RESET                         0
#define MAC_DCU_MISC_1_SEQNUM_FREEZE_MSB                             20
#define MAC_DCU_MISC_1_SEQNUM_FREEZE_LSB                             20
#define MAC_DCU_MISC_1_SEQNUM_FREEZE_MASK                            0x00100000
#define MAC_DCU_MISC_1_SEQNUM_FREEZE_GET(x)                          (((x) & MAC_DCU_MISC_1_SEQNUM_FREEZE_MASK) >> MAC_DCU_MISC_1_SEQNUM_FREEZE_LSB)
#define MAC_DCU_MISC_1_SEQNUM_FREEZE_SET(x)                          (((0 | (x)) << MAC_DCU_MISC_1_SEQNUM_FREEZE_LSB) & MAC_DCU_MISC_1_SEQNUM_FREEZE_MASK)
#define MAC_DCU_MISC_1_SEQNUM_FREEZE_RESET                           0
#define MAC_DCU_MISC_1_LOCKOUT_IGNORE_MSB                            19
#define MAC_DCU_MISC_1_LOCKOUT_IGNORE_LSB                            19
#define MAC_DCU_MISC_1_LOCKOUT_IGNORE_MASK                           0x00080000
#define MAC_DCU_MISC_1_LOCKOUT_IGNORE_GET(x)                         (((x) & MAC_DCU_MISC_1_LOCKOUT_IGNORE_MASK) >> MAC_DCU_MISC_1_LOCKOUT_IGNORE_LSB)
#define MAC_DCU_MISC_1_LOCKOUT_IGNORE_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_1_LOCKOUT_IGNORE_LSB) & MAC_DCU_MISC_1_LOCKOUT_IGNORE_MASK)
#define MAC_DCU_MISC_1_LOCKOUT_IGNORE_RESET                          0
#define MAC_DCU_MISC_1_LOCKOUT_GBL_EN_MSB                            18
#define MAC_DCU_MISC_1_LOCKOUT_GBL_EN_LSB                            18
#define MAC_DCU_MISC_1_LOCKOUT_GBL_EN_MASK                           0x00040000
#define MAC_DCU_MISC_1_LOCKOUT_GBL_EN_GET(x)                         (((x) & MAC_DCU_MISC_1_LOCKOUT_GBL_EN_MASK) >> MAC_DCU_MISC_1_LOCKOUT_GBL_EN_LSB)
#define MAC_DCU_MISC_1_LOCKOUT_GBL_EN_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_1_LOCKOUT_GBL_EN_LSB) & MAC_DCU_MISC_1_LOCKOUT_GBL_EN_MASK)
#define MAC_DCU_MISC_1_LOCKOUT_GBL_EN_RESET                          0
#define MAC_DCU_MISC_1_ARB_LOCKOUT_IF_EN_MSB                         17
#define MAC_DCU_MISC_1_ARB_LOCKOUT_IF_EN_LSB                         17
#define MAC_DCU_MISC_1_ARB_LOCKOUT_IF_EN_MASK                        0x00020000
#define MAC_DCU_MISC_1_ARB_LOCKOUT_IF_EN_GET(x)                      (((x) & MAC_DCU_MISC_1_ARB_LOCKOUT_IF_EN_MASK) >> MAC_DCU_MISC_1_ARB_LOCKOUT_IF_EN_LSB)
#define MAC_DCU_MISC_1_ARB_LOCKOUT_IF_EN_SET(x)                      (((0 | (x)) << MAC_DCU_MISC_1_ARB_LOCKOUT_IF_EN_LSB) & MAC_DCU_MISC_1_ARB_LOCKOUT_IF_EN_MASK)
#define MAC_DCU_MISC_1_ARB_LOCKOUT_IF_EN_RESET                       0
#define MAC_DCU_MISC_1_IS_BCN_MSB                                    16
#define MAC_DCU_MISC_1_IS_BCN_LSB                                    16
#define MAC_DCU_MISC_1_IS_BCN_MASK                                   0x00010000
#define MAC_DCU_MISC_1_IS_BCN_GET(x)                                 (((x) & MAC_DCU_MISC_1_IS_BCN_MASK) >> MAC_DCU_MISC_1_IS_BCN_LSB)
#define MAC_DCU_MISC_1_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_DCU_MISC_1_IS_BCN_LSB) & MAC_DCU_MISC_1_IS_BCN_MASK)
#define MAC_DCU_MISC_1_IS_BCN_RESET                                  0
#define MAC_DCU_MISC_1_VIRT_COLL_POLICY_MSB                          15
#define MAC_DCU_MISC_1_VIRT_COLL_POLICY_LSB                          14
#define MAC_DCU_MISC_1_VIRT_COLL_POLICY_MASK                         0x0000c000
#define MAC_DCU_MISC_1_VIRT_COLL_POLICY_GET(x)                       (((x) & MAC_DCU_MISC_1_VIRT_COLL_POLICY_MASK) >> MAC_DCU_MISC_1_VIRT_COLL_POLICY_LSB)
#define MAC_DCU_MISC_1_VIRT_COLL_POLICY_SET(x)                       (((0 | (x)) << MAC_DCU_MISC_1_VIRT_COLL_POLICY_LSB) & MAC_DCU_MISC_1_VIRT_COLL_POLICY_MASK)
#define MAC_DCU_MISC_1_VIRT_COLL_POLICY_RESET                        0
#define MAC_DCU_MISC_1_BKOFF_PF_MSB                                  12
#define MAC_DCU_MISC_1_BKOFF_PF_LSB                                  12
#define MAC_DCU_MISC_1_BKOFF_PF_MASK                                 0x00001000
#define MAC_DCU_MISC_1_BKOFF_PF_GET(x)                               (((x) & MAC_DCU_MISC_1_BKOFF_PF_MASK) >> MAC_DCU_MISC_1_BKOFF_PF_LSB)
#define MAC_DCU_MISC_1_BKOFF_PF_SET(x)                               (((0 | (x)) << MAC_DCU_MISC_1_BKOFF_PF_LSB) & MAC_DCU_MISC_1_BKOFF_PF_MASK)
#define MAC_DCU_MISC_1_BKOFF_PF_RESET                                0
#define MAC_DCU_MISC_1_HCF_POLL_EN_MSB                               11
#define MAC_DCU_MISC_1_HCF_POLL_EN_LSB                               11
#define MAC_DCU_MISC_1_HCF_POLL_EN_MASK                              0x00000800
#define MAC_DCU_MISC_1_HCF_POLL_EN_GET(x)                            (((x) & MAC_DCU_MISC_1_HCF_POLL_EN_MASK) >> MAC_DCU_MISC_1_HCF_POLL_EN_LSB)
#define MAC_DCU_MISC_1_HCF_POLL_EN_SET(x)                            (((0 | (x)) << MAC_DCU_MISC_1_HCF_POLL_EN_LSB) & MAC_DCU_MISC_1_HCF_POLL_EN_MASK)
#define MAC_DCU_MISC_1_HCF_POLL_EN_RESET                             0
#define MAC_DCU_MISC_1_FRAG_BURST_BKOFF_EN_MSB                       9
#define MAC_DCU_MISC_1_FRAG_BURST_BKOFF_EN_LSB                       9
#define MAC_DCU_MISC_1_FRAG_BURST_BKOFF_EN_MASK                      0x00000200
#define MAC_DCU_MISC_1_FRAG_BURST_BKOFF_EN_GET(x)                    (((x) & MAC_DCU_MISC_1_FRAG_BURST_BKOFF_EN_MASK) >> MAC_DCU_MISC_1_FRAG_BURST_BKOFF_EN_LSB)
#define MAC_DCU_MISC_1_FRAG_BURST_BKOFF_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_1_FRAG_BURST_BKOFF_EN_LSB) & MAC_DCU_MISC_1_FRAG_BURST_BKOFF_EN_MASK)
#define MAC_DCU_MISC_1_FRAG_BURST_BKOFF_EN_RESET                     0
#define MAC_DCU_MISC_1_FRAG_BURST_WAIT_QCU_EN_MSB                    8
#define MAC_DCU_MISC_1_FRAG_BURST_WAIT_QCU_EN_LSB                    8
#define MAC_DCU_MISC_1_FRAG_BURST_WAIT_QCU_EN_MASK                   0x00000100
#define MAC_DCU_MISC_1_FRAG_BURST_WAIT_QCU_EN_GET(x)                 (((x) & MAC_DCU_MISC_1_FRAG_BURST_WAIT_QCU_EN_MASK) >> MAC_DCU_MISC_1_FRAG_BURST_WAIT_QCU_EN_LSB)
#define MAC_DCU_MISC_1_FRAG_BURST_WAIT_QCU_EN_SET(x)                 (((0 | (x)) << MAC_DCU_MISC_1_FRAG_BURST_WAIT_QCU_EN_LSB) & MAC_DCU_MISC_1_FRAG_BURST_WAIT_QCU_EN_MASK)
#define MAC_DCU_MISC_1_FRAG_BURST_WAIT_QCU_EN_RESET                  0
#define MAC_DCU_MISC_1_CW_RST_AT_TS_END_DIS_MSB                      7
#define MAC_DCU_MISC_1_CW_RST_AT_TS_END_DIS_LSB                      7
#define MAC_DCU_MISC_1_CW_RST_AT_TS_END_DIS_MASK                     0x00000080
#define MAC_DCU_MISC_1_CW_RST_AT_TS_END_DIS_GET(x)                   (((x) & MAC_DCU_MISC_1_CW_RST_AT_TS_END_DIS_MASK) >> MAC_DCU_MISC_1_CW_RST_AT_TS_END_DIS_LSB)
#define MAC_DCU_MISC_1_CW_RST_AT_TS_END_DIS_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_1_CW_RST_AT_TS_END_DIS_LSB) & MAC_DCU_MISC_1_CW_RST_AT_TS_END_DIS_MASK)
#define MAC_DCU_MISC_1_CW_RST_AT_TS_END_DIS_RESET                    0
#define MAC_DCU_MISC_1_SFC_RST_AT_TS_END_EN_MSB                      6
#define MAC_DCU_MISC_1_SFC_RST_AT_TS_END_EN_LSB                      6
#define MAC_DCU_MISC_1_SFC_RST_AT_TS_END_EN_MASK                     0x00000040
#define MAC_DCU_MISC_1_SFC_RST_AT_TS_END_EN_GET(x)                   (((x) & MAC_DCU_MISC_1_SFC_RST_AT_TS_END_EN_MASK) >> MAC_DCU_MISC_1_SFC_RST_AT_TS_END_EN_LSB)
#define MAC_DCU_MISC_1_SFC_RST_AT_TS_END_EN_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_1_SFC_RST_AT_TS_END_EN_LSB) & MAC_DCU_MISC_1_SFC_RST_AT_TS_END_EN_MASK)
#define MAC_DCU_MISC_1_SFC_RST_AT_TS_END_EN_RESET                    0
#define MAC_DCU_MISC_1_BKOFF_THRESH_MSB                              5
#define MAC_DCU_MISC_1_BKOFF_THRESH_LSB                              0
#define MAC_DCU_MISC_1_BKOFF_THRESH_MASK                             0x0000003f
#define MAC_DCU_MISC_1_BKOFF_THRESH_GET(x)                           (((x) & MAC_DCU_MISC_1_BKOFF_THRESH_MASK) >> MAC_DCU_MISC_1_BKOFF_THRESH_LSB)
#define MAC_DCU_MISC_1_BKOFF_THRESH_SET(x)                           (((0 | (x)) << MAC_DCU_MISC_1_BKOFF_THRESH_LSB) & MAC_DCU_MISC_1_BKOFF_THRESH_MASK)
#define MAC_DCU_MISC_1_BKOFF_THRESH_RESET                            0
#define MAC_DCU_MISC_1_ADDRESS                                       0x1104
#define MAC_DCU_MISC_1_HW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_1_SW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_1_HW_WRITE_MASK                                 0x00000000
#define MAC_DCU_MISC_1_SW_WRITE_MASK                                 0x01ffdbff
#define MAC_DCU_MISC_1_RSTMASK                                       0xffffffff
#define MAC_DCU_MISC_1_RESET                                         0x01000000

// 0x1108 (MAC_DCU_MISC_2)
#define MAC_DCU_MISC_2_SIFS_BURST_CHAN_BUSY_IGNORE_MSB               24
#define MAC_DCU_MISC_2_SIFS_BURST_CHAN_BUSY_IGNORE_LSB               24
#define MAC_DCU_MISC_2_SIFS_BURST_CHAN_BUSY_IGNORE_MASK              0x01000000
#define MAC_DCU_MISC_2_SIFS_BURST_CHAN_BUSY_IGNORE_GET(x)            (((x) & MAC_DCU_MISC_2_SIFS_BURST_CHAN_BUSY_IGNORE_MASK) >> MAC_DCU_MISC_2_SIFS_BURST_CHAN_BUSY_IGNORE_LSB)
#define MAC_DCU_MISC_2_SIFS_BURST_CHAN_BUSY_IGNORE_SET(x)            (((0 | (x)) << MAC_DCU_MISC_2_SIFS_BURST_CHAN_BUSY_IGNORE_LSB) & MAC_DCU_MISC_2_SIFS_BURST_CHAN_BUSY_IGNORE_MASK)
#define MAC_DCU_MISC_2_SIFS_BURST_CHAN_BUSY_IGNORE_RESET             1
#define MAC_DCU_MISC_2_RETRY_ON_BLOWN_IFS_EN_MSB                     23
#define MAC_DCU_MISC_2_RETRY_ON_BLOWN_IFS_EN_LSB                     23
#define MAC_DCU_MISC_2_RETRY_ON_BLOWN_IFS_EN_MASK                    0x00800000
#define MAC_DCU_MISC_2_RETRY_ON_BLOWN_IFS_EN_GET(x)                  (((x) & MAC_DCU_MISC_2_RETRY_ON_BLOWN_IFS_EN_MASK) >> MAC_DCU_MISC_2_RETRY_ON_BLOWN_IFS_EN_LSB)
#define MAC_DCU_MISC_2_RETRY_ON_BLOWN_IFS_EN_SET(x)                  (((0 | (x)) << MAC_DCU_MISC_2_RETRY_ON_BLOWN_IFS_EN_LSB) & MAC_DCU_MISC_2_RETRY_ON_BLOWN_IFS_EN_MASK)
#define MAC_DCU_MISC_2_RETRY_ON_BLOWN_IFS_EN_RESET                   0
#define MAC_DCU_MISC_2_VIRT_COLL_CW_INC_EN_MSB                       22
#define MAC_DCU_MISC_2_VIRT_COLL_CW_INC_EN_LSB                       22
#define MAC_DCU_MISC_2_VIRT_COLL_CW_INC_EN_MASK                      0x00400000
#define MAC_DCU_MISC_2_VIRT_COLL_CW_INC_EN_GET(x)                    (((x) & MAC_DCU_MISC_2_VIRT_COLL_CW_INC_EN_MASK) >> MAC_DCU_MISC_2_VIRT_COLL_CW_INC_EN_LSB)
#define MAC_DCU_MISC_2_VIRT_COLL_CW_INC_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_2_VIRT_COLL_CW_INC_EN_LSB) & MAC_DCU_MISC_2_VIRT_COLL_CW_INC_EN_MASK)
#define MAC_DCU_MISC_2_VIRT_COLL_CW_INC_EN_RESET                     0
#define MAC_DCU_MISC_2_POST_BKOFF_SKIP_MSB                           21
#define MAC_DCU_MISC_2_POST_BKOFF_SKIP_LSB                           21
#define MAC_DCU_MISC_2_POST_BKOFF_SKIP_MASK                          0x00200000
#define MAC_DCU_MISC_2_POST_BKOFF_SKIP_GET(x)                        (((x) & MAC_DCU_MISC_2_POST_BKOFF_SKIP_MASK) >> MAC_DCU_MISC_2_POST_BKOFF_SKIP_LSB)
#define MAC_DCU_MISC_2_POST_BKOFF_SKIP_SET(x)                        (((0 | (x)) << MAC_DCU_MISC_2_POST_BKOFF_SKIP_LSB) & MAC_DCU_MISC_2_POST_BKOFF_SKIP_MASK)
#define MAC_DCU_MISC_2_POST_BKOFF_SKIP_RESET                         0
#define MAC_DCU_MISC_2_SEQNUM_FREEZE_MSB                             20
#define MAC_DCU_MISC_2_SEQNUM_FREEZE_LSB                             20
#define MAC_DCU_MISC_2_SEQNUM_FREEZE_MASK                            0x00100000
#define MAC_DCU_MISC_2_SEQNUM_FREEZE_GET(x)                          (((x) & MAC_DCU_MISC_2_SEQNUM_FREEZE_MASK) >> MAC_DCU_MISC_2_SEQNUM_FREEZE_LSB)
#define MAC_DCU_MISC_2_SEQNUM_FREEZE_SET(x)                          (((0 | (x)) << MAC_DCU_MISC_2_SEQNUM_FREEZE_LSB) & MAC_DCU_MISC_2_SEQNUM_FREEZE_MASK)
#define MAC_DCU_MISC_2_SEQNUM_FREEZE_RESET                           0
#define MAC_DCU_MISC_2_LOCKOUT_IGNORE_MSB                            19
#define MAC_DCU_MISC_2_LOCKOUT_IGNORE_LSB                            19
#define MAC_DCU_MISC_2_LOCKOUT_IGNORE_MASK                           0x00080000
#define MAC_DCU_MISC_2_LOCKOUT_IGNORE_GET(x)                         (((x) & MAC_DCU_MISC_2_LOCKOUT_IGNORE_MASK) >> MAC_DCU_MISC_2_LOCKOUT_IGNORE_LSB)
#define MAC_DCU_MISC_2_LOCKOUT_IGNORE_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_2_LOCKOUT_IGNORE_LSB) & MAC_DCU_MISC_2_LOCKOUT_IGNORE_MASK)
#define MAC_DCU_MISC_2_LOCKOUT_IGNORE_RESET                          0
#define MAC_DCU_MISC_2_LOCKOUT_GBL_EN_MSB                            18
#define MAC_DCU_MISC_2_LOCKOUT_GBL_EN_LSB                            18
#define MAC_DCU_MISC_2_LOCKOUT_GBL_EN_MASK                           0x00040000
#define MAC_DCU_MISC_2_LOCKOUT_GBL_EN_GET(x)                         (((x) & MAC_DCU_MISC_2_LOCKOUT_GBL_EN_MASK) >> MAC_DCU_MISC_2_LOCKOUT_GBL_EN_LSB)
#define MAC_DCU_MISC_2_LOCKOUT_GBL_EN_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_2_LOCKOUT_GBL_EN_LSB) & MAC_DCU_MISC_2_LOCKOUT_GBL_EN_MASK)
#define MAC_DCU_MISC_2_LOCKOUT_GBL_EN_RESET                          0
#define MAC_DCU_MISC_2_ARB_LOCKOUT_IF_EN_MSB                         17
#define MAC_DCU_MISC_2_ARB_LOCKOUT_IF_EN_LSB                         17
#define MAC_DCU_MISC_2_ARB_LOCKOUT_IF_EN_MASK                        0x00020000
#define MAC_DCU_MISC_2_ARB_LOCKOUT_IF_EN_GET(x)                      (((x) & MAC_DCU_MISC_2_ARB_LOCKOUT_IF_EN_MASK) >> MAC_DCU_MISC_2_ARB_LOCKOUT_IF_EN_LSB)
#define MAC_DCU_MISC_2_ARB_LOCKOUT_IF_EN_SET(x)                      (((0 | (x)) << MAC_DCU_MISC_2_ARB_LOCKOUT_IF_EN_LSB) & MAC_DCU_MISC_2_ARB_LOCKOUT_IF_EN_MASK)
#define MAC_DCU_MISC_2_ARB_LOCKOUT_IF_EN_RESET                       0
#define MAC_DCU_MISC_2_IS_BCN_MSB                                    16
#define MAC_DCU_MISC_2_IS_BCN_LSB                                    16
#define MAC_DCU_MISC_2_IS_BCN_MASK                                   0x00010000
#define MAC_DCU_MISC_2_IS_BCN_GET(x)                                 (((x) & MAC_DCU_MISC_2_IS_BCN_MASK) >> MAC_DCU_MISC_2_IS_BCN_LSB)
#define MAC_DCU_MISC_2_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_DCU_MISC_2_IS_BCN_LSB) & MAC_DCU_MISC_2_IS_BCN_MASK)
#define MAC_DCU_MISC_2_IS_BCN_RESET                                  0
#define MAC_DCU_MISC_2_VIRT_COLL_POLICY_MSB                          15
#define MAC_DCU_MISC_2_VIRT_COLL_POLICY_LSB                          14
#define MAC_DCU_MISC_2_VIRT_COLL_POLICY_MASK                         0x0000c000
#define MAC_DCU_MISC_2_VIRT_COLL_POLICY_GET(x)                       (((x) & MAC_DCU_MISC_2_VIRT_COLL_POLICY_MASK) >> MAC_DCU_MISC_2_VIRT_COLL_POLICY_LSB)
#define MAC_DCU_MISC_2_VIRT_COLL_POLICY_SET(x)                       (((0 | (x)) << MAC_DCU_MISC_2_VIRT_COLL_POLICY_LSB) & MAC_DCU_MISC_2_VIRT_COLL_POLICY_MASK)
#define MAC_DCU_MISC_2_VIRT_COLL_POLICY_RESET                        0
#define MAC_DCU_MISC_2_BKOFF_PF_MSB                                  12
#define MAC_DCU_MISC_2_BKOFF_PF_LSB                                  12
#define MAC_DCU_MISC_2_BKOFF_PF_MASK                                 0x00001000
#define MAC_DCU_MISC_2_BKOFF_PF_GET(x)                               (((x) & MAC_DCU_MISC_2_BKOFF_PF_MASK) >> MAC_DCU_MISC_2_BKOFF_PF_LSB)
#define MAC_DCU_MISC_2_BKOFF_PF_SET(x)                               (((0 | (x)) << MAC_DCU_MISC_2_BKOFF_PF_LSB) & MAC_DCU_MISC_2_BKOFF_PF_MASK)
#define MAC_DCU_MISC_2_BKOFF_PF_RESET                                0
#define MAC_DCU_MISC_2_HCF_POLL_EN_MSB                               11
#define MAC_DCU_MISC_2_HCF_POLL_EN_LSB                               11
#define MAC_DCU_MISC_2_HCF_POLL_EN_MASK                              0x00000800
#define MAC_DCU_MISC_2_HCF_POLL_EN_GET(x)                            (((x) & MAC_DCU_MISC_2_HCF_POLL_EN_MASK) >> MAC_DCU_MISC_2_HCF_POLL_EN_LSB)
#define MAC_DCU_MISC_2_HCF_POLL_EN_SET(x)                            (((0 | (x)) << MAC_DCU_MISC_2_HCF_POLL_EN_LSB) & MAC_DCU_MISC_2_HCF_POLL_EN_MASK)
#define MAC_DCU_MISC_2_HCF_POLL_EN_RESET                             0
#define MAC_DCU_MISC_2_FRAG_BURST_BKOFF_EN_MSB                       9
#define MAC_DCU_MISC_2_FRAG_BURST_BKOFF_EN_LSB                       9
#define MAC_DCU_MISC_2_FRAG_BURST_BKOFF_EN_MASK                      0x00000200
#define MAC_DCU_MISC_2_FRAG_BURST_BKOFF_EN_GET(x)                    (((x) & MAC_DCU_MISC_2_FRAG_BURST_BKOFF_EN_MASK) >> MAC_DCU_MISC_2_FRAG_BURST_BKOFF_EN_LSB)
#define MAC_DCU_MISC_2_FRAG_BURST_BKOFF_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_2_FRAG_BURST_BKOFF_EN_LSB) & MAC_DCU_MISC_2_FRAG_BURST_BKOFF_EN_MASK)
#define MAC_DCU_MISC_2_FRAG_BURST_BKOFF_EN_RESET                     0
#define MAC_DCU_MISC_2_FRAG_BURST_WAIT_QCU_EN_MSB                    8
#define MAC_DCU_MISC_2_FRAG_BURST_WAIT_QCU_EN_LSB                    8
#define MAC_DCU_MISC_2_FRAG_BURST_WAIT_QCU_EN_MASK                   0x00000100
#define MAC_DCU_MISC_2_FRAG_BURST_WAIT_QCU_EN_GET(x)                 (((x) & MAC_DCU_MISC_2_FRAG_BURST_WAIT_QCU_EN_MASK) >> MAC_DCU_MISC_2_FRAG_BURST_WAIT_QCU_EN_LSB)
#define MAC_DCU_MISC_2_FRAG_BURST_WAIT_QCU_EN_SET(x)                 (((0 | (x)) << MAC_DCU_MISC_2_FRAG_BURST_WAIT_QCU_EN_LSB) & MAC_DCU_MISC_2_FRAG_BURST_WAIT_QCU_EN_MASK)
#define MAC_DCU_MISC_2_FRAG_BURST_WAIT_QCU_EN_RESET                  0
#define MAC_DCU_MISC_2_CW_RST_AT_TS_END_DIS_MSB                      7
#define MAC_DCU_MISC_2_CW_RST_AT_TS_END_DIS_LSB                      7
#define MAC_DCU_MISC_2_CW_RST_AT_TS_END_DIS_MASK                     0x00000080
#define MAC_DCU_MISC_2_CW_RST_AT_TS_END_DIS_GET(x)                   (((x) & MAC_DCU_MISC_2_CW_RST_AT_TS_END_DIS_MASK) >> MAC_DCU_MISC_2_CW_RST_AT_TS_END_DIS_LSB)
#define MAC_DCU_MISC_2_CW_RST_AT_TS_END_DIS_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_2_CW_RST_AT_TS_END_DIS_LSB) & MAC_DCU_MISC_2_CW_RST_AT_TS_END_DIS_MASK)
#define MAC_DCU_MISC_2_CW_RST_AT_TS_END_DIS_RESET                    0
#define MAC_DCU_MISC_2_SFC_RST_AT_TS_END_EN_MSB                      6
#define MAC_DCU_MISC_2_SFC_RST_AT_TS_END_EN_LSB                      6
#define MAC_DCU_MISC_2_SFC_RST_AT_TS_END_EN_MASK                     0x00000040
#define MAC_DCU_MISC_2_SFC_RST_AT_TS_END_EN_GET(x)                   (((x) & MAC_DCU_MISC_2_SFC_RST_AT_TS_END_EN_MASK) >> MAC_DCU_MISC_2_SFC_RST_AT_TS_END_EN_LSB)
#define MAC_DCU_MISC_2_SFC_RST_AT_TS_END_EN_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_2_SFC_RST_AT_TS_END_EN_LSB) & MAC_DCU_MISC_2_SFC_RST_AT_TS_END_EN_MASK)
#define MAC_DCU_MISC_2_SFC_RST_AT_TS_END_EN_RESET                    0
#define MAC_DCU_MISC_2_BKOFF_THRESH_MSB                              5
#define MAC_DCU_MISC_2_BKOFF_THRESH_LSB                              0
#define MAC_DCU_MISC_2_BKOFF_THRESH_MASK                             0x0000003f
#define MAC_DCU_MISC_2_BKOFF_THRESH_GET(x)                           (((x) & MAC_DCU_MISC_2_BKOFF_THRESH_MASK) >> MAC_DCU_MISC_2_BKOFF_THRESH_LSB)
#define MAC_DCU_MISC_2_BKOFF_THRESH_SET(x)                           (((0 | (x)) << MAC_DCU_MISC_2_BKOFF_THRESH_LSB) & MAC_DCU_MISC_2_BKOFF_THRESH_MASK)
#define MAC_DCU_MISC_2_BKOFF_THRESH_RESET                            0
#define MAC_DCU_MISC_2_ADDRESS                                       0x1108
#define MAC_DCU_MISC_2_HW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_2_SW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_2_HW_WRITE_MASK                                 0x00000000
#define MAC_DCU_MISC_2_SW_WRITE_MASK                                 0x01ffdbff
#define MAC_DCU_MISC_2_RSTMASK                                       0xffffffff
#define MAC_DCU_MISC_2_RESET                                         0x01000000

// 0x110c (MAC_DCU_MISC_3)
#define MAC_DCU_MISC_3_SIFS_BURST_CHAN_BUSY_IGNORE_MSB               24
#define MAC_DCU_MISC_3_SIFS_BURST_CHAN_BUSY_IGNORE_LSB               24
#define MAC_DCU_MISC_3_SIFS_BURST_CHAN_BUSY_IGNORE_MASK              0x01000000
#define MAC_DCU_MISC_3_SIFS_BURST_CHAN_BUSY_IGNORE_GET(x)            (((x) & MAC_DCU_MISC_3_SIFS_BURST_CHAN_BUSY_IGNORE_MASK) >> MAC_DCU_MISC_3_SIFS_BURST_CHAN_BUSY_IGNORE_LSB)
#define MAC_DCU_MISC_3_SIFS_BURST_CHAN_BUSY_IGNORE_SET(x)            (((0 | (x)) << MAC_DCU_MISC_3_SIFS_BURST_CHAN_BUSY_IGNORE_LSB) & MAC_DCU_MISC_3_SIFS_BURST_CHAN_BUSY_IGNORE_MASK)
#define MAC_DCU_MISC_3_SIFS_BURST_CHAN_BUSY_IGNORE_RESET             1
#define MAC_DCU_MISC_3_RETRY_ON_BLOWN_IFS_EN_MSB                     23
#define MAC_DCU_MISC_3_RETRY_ON_BLOWN_IFS_EN_LSB                     23
#define MAC_DCU_MISC_3_RETRY_ON_BLOWN_IFS_EN_MASK                    0x00800000
#define MAC_DCU_MISC_3_RETRY_ON_BLOWN_IFS_EN_GET(x)                  (((x) & MAC_DCU_MISC_3_RETRY_ON_BLOWN_IFS_EN_MASK) >> MAC_DCU_MISC_3_RETRY_ON_BLOWN_IFS_EN_LSB)
#define MAC_DCU_MISC_3_RETRY_ON_BLOWN_IFS_EN_SET(x)                  (((0 | (x)) << MAC_DCU_MISC_3_RETRY_ON_BLOWN_IFS_EN_LSB) & MAC_DCU_MISC_3_RETRY_ON_BLOWN_IFS_EN_MASK)
#define MAC_DCU_MISC_3_RETRY_ON_BLOWN_IFS_EN_RESET                   0
#define MAC_DCU_MISC_3_VIRT_COLL_CW_INC_EN_MSB                       22
#define MAC_DCU_MISC_3_VIRT_COLL_CW_INC_EN_LSB                       22
#define MAC_DCU_MISC_3_VIRT_COLL_CW_INC_EN_MASK                      0x00400000
#define MAC_DCU_MISC_3_VIRT_COLL_CW_INC_EN_GET(x)                    (((x) & MAC_DCU_MISC_3_VIRT_COLL_CW_INC_EN_MASK) >> MAC_DCU_MISC_3_VIRT_COLL_CW_INC_EN_LSB)
#define MAC_DCU_MISC_3_VIRT_COLL_CW_INC_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_3_VIRT_COLL_CW_INC_EN_LSB) & MAC_DCU_MISC_3_VIRT_COLL_CW_INC_EN_MASK)
#define MAC_DCU_MISC_3_VIRT_COLL_CW_INC_EN_RESET                     0
#define MAC_DCU_MISC_3_POST_BKOFF_SKIP_MSB                           21
#define MAC_DCU_MISC_3_POST_BKOFF_SKIP_LSB                           21
#define MAC_DCU_MISC_3_POST_BKOFF_SKIP_MASK                          0x00200000
#define MAC_DCU_MISC_3_POST_BKOFF_SKIP_GET(x)                        (((x) & MAC_DCU_MISC_3_POST_BKOFF_SKIP_MASK) >> MAC_DCU_MISC_3_POST_BKOFF_SKIP_LSB)
#define MAC_DCU_MISC_3_POST_BKOFF_SKIP_SET(x)                        (((0 | (x)) << MAC_DCU_MISC_3_POST_BKOFF_SKIP_LSB) & MAC_DCU_MISC_3_POST_BKOFF_SKIP_MASK)
#define MAC_DCU_MISC_3_POST_BKOFF_SKIP_RESET                         0
#define MAC_DCU_MISC_3_SEQNUM_FREEZE_MSB                             20
#define MAC_DCU_MISC_3_SEQNUM_FREEZE_LSB                             20
#define MAC_DCU_MISC_3_SEQNUM_FREEZE_MASK                            0x00100000
#define MAC_DCU_MISC_3_SEQNUM_FREEZE_GET(x)                          (((x) & MAC_DCU_MISC_3_SEQNUM_FREEZE_MASK) >> MAC_DCU_MISC_3_SEQNUM_FREEZE_LSB)
#define MAC_DCU_MISC_3_SEQNUM_FREEZE_SET(x)                          (((0 | (x)) << MAC_DCU_MISC_3_SEQNUM_FREEZE_LSB) & MAC_DCU_MISC_3_SEQNUM_FREEZE_MASK)
#define MAC_DCU_MISC_3_SEQNUM_FREEZE_RESET                           0
#define MAC_DCU_MISC_3_LOCKOUT_IGNORE_MSB                            19
#define MAC_DCU_MISC_3_LOCKOUT_IGNORE_LSB                            19
#define MAC_DCU_MISC_3_LOCKOUT_IGNORE_MASK                           0x00080000
#define MAC_DCU_MISC_3_LOCKOUT_IGNORE_GET(x)                         (((x) & MAC_DCU_MISC_3_LOCKOUT_IGNORE_MASK) >> MAC_DCU_MISC_3_LOCKOUT_IGNORE_LSB)
#define MAC_DCU_MISC_3_LOCKOUT_IGNORE_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_3_LOCKOUT_IGNORE_LSB) & MAC_DCU_MISC_3_LOCKOUT_IGNORE_MASK)
#define MAC_DCU_MISC_3_LOCKOUT_IGNORE_RESET                          0
#define MAC_DCU_MISC_3_LOCKOUT_GBL_EN_MSB                            18
#define MAC_DCU_MISC_3_LOCKOUT_GBL_EN_LSB                            18
#define MAC_DCU_MISC_3_LOCKOUT_GBL_EN_MASK                           0x00040000
#define MAC_DCU_MISC_3_LOCKOUT_GBL_EN_GET(x)                         (((x) & MAC_DCU_MISC_3_LOCKOUT_GBL_EN_MASK) >> MAC_DCU_MISC_3_LOCKOUT_GBL_EN_LSB)
#define MAC_DCU_MISC_3_LOCKOUT_GBL_EN_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_3_LOCKOUT_GBL_EN_LSB) & MAC_DCU_MISC_3_LOCKOUT_GBL_EN_MASK)
#define MAC_DCU_MISC_3_LOCKOUT_GBL_EN_RESET                          0
#define MAC_DCU_MISC_3_ARB_LOCKOUT_IF_EN_MSB                         17
#define MAC_DCU_MISC_3_ARB_LOCKOUT_IF_EN_LSB                         17
#define MAC_DCU_MISC_3_ARB_LOCKOUT_IF_EN_MASK                        0x00020000
#define MAC_DCU_MISC_3_ARB_LOCKOUT_IF_EN_GET(x)                      (((x) & MAC_DCU_MISC_3_ARB_LOCKOUT_IF_EN_MASK) >> MAC_DCU_MISC_3_ARB_LOCKOUT_IF_EN_LSB)
#define MAC_DCU_MISC_3_ARB_LOCKOUT_IF_EN_SET(x)                      (((0 | (x)) << MAC_DCU_MISC_3_ARB_LOCKOUT_IF_EN_LSB) & MAC_DCU_MISC_3_ARB_LOCKOUT_IF_EN_MASK)
#define MAC_DCU_MISC_3_ARB_LOCKOUT_IF_EN_RESET                       0
#define MAC_DCU_MISC_3_IS_BCN_MSB                                    16
#define MAC_DCU_MISC_3_IS_BCN_LSB                                    16
#define MAC_DCU_MISC_3_IS_BCN_MASK                                   0x00010000
#define MAC_DCU_MISC_3_IS_BCN_GET(x)                                 (((x) & MAC_DCU_MISC_3_IS_BCN_MASK) >> MAC_DCU_MISC_3_IS_BCN_LSB)
#define MAC_DCU_MISC_3_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_DCU_MISC_3_IS_BCN_LSB) & MAC_DCU_MISC_3_IS_BCN_MASK)
#define MAC_DCU_MISC_3_IS_BCN_RESET                                  0
#define MAC_DCU_MISC_3_VIRT_COLL_POLICY_MSB                          15
#define MAC_DCU_MISC_3_VIRT_COLL_POLICY_LSB                          14
#define MAC_DCU_MISC_3_VIRT_COLL_POLICY_MASK                         0x0000c000
#define MAC_DCU_MISC_3_VIRT_COLL_POLICY_GET(x)                       (((x) & MAC_DCU_MISC_3_VIRT_COLL_POLICY_MASK) >> MAC_DCU_MISC_3_VIRT_COLL_POLICY_LSB)
#define MAC_DCU_MISC_3_VIRT_COLL_POLICY_SET(x)                       (((0 | (x)) << MAC_DCU_MISC_3_VIRT_COLL_POLICY_LSB) & MAC_DCU_MISC_3_VIRT_COLL_POLICY_MASK)
#define MAC_DCU_MISC_3_VIRT_COLL_POLICY_RESET                        0
#define MAC_DCU_MISC_3_BKOFF_PF_MSB                                  12
#define MAC_DCU_MISC_3_BKOFF_PF_LSB                                  12
#define MAC_DCU_MISC_3_BKOFF_PF_MASK                                 0x00001000
#define MAC_DCU_MISC_3_BKOFF_PF_GET(x)                               (((x) & MAC_DCU_MISC_3_BKOFF_PF_MASK) >> MAC_DCU_MISC_3_BKOFF_PF_LSB)
#define MAC_DCU_MISC_3_BKOFF_PF_SET(x)                               (((0 | (x)) << MAC_DCU_MISC_3_BKOFF_PF_LSB) & MAC_DCU_MISC_3_BKOFF_PF_MASK)
#define MAC_DCU_MISC_3_BKOFF_PF_RESET                                0
#define MAC_DCU_MISC_3_HCF_POLL_EN_MSB                               11
#define MAC_DCU_MISC_3_HCF_POLL_EN_LSB                               11
#define MAC_DCU_MISC_3_HCF_POLL_EN_MASK                              0x00000800
#define MAC_DCU_MISC_3_HCF_POLL_EN_GET(x)                            (((x) & MAC_DCU_MISC_3_HCF_POLL_EN_MASK) >> MAC_DCU_MISC_3_HCF_POLL_EN_LSB)
#define MAC_DCU_MISC_3_HCF_POLL_EN_SET(x)                            (((0 | (x)) << MAC_DCU_MISC_3_HCF_POLL_EN_LSB) & MAC_DCU_MISC_3_HCF_POLL_EN_MASK)
#define MAC_DCU_MISC_3_HCF_POLL_EN_RESET                             0
#define MAC_DCU_MISC_3_FRAG_BURST_BKOFF_EN_MSB                       9
#define MAC_DCU_MISC_3_FRAG_BURST_BKOFF_EN_LSB                       9
#define MAC_DCU_MISC_3_FRAG_BURST_BKOFF_EN_MASK                      0x00000200
#define MAC_DCU_MISC_3_FRAG_BURST_BKOFF_EN_GET(x)                    (((x) & MAC_DCU_MISC_3_FRAG_BURST_BKOFF_EN_MASK) >> MAC_DCU_MISC_3_FRAG_BURST_BKOFF_EN_LSB)
#define MAC_DCU_MISC_3_FRAG_BURST_BKOFF_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_3_FRAG_BURST_BKOFF_EN_LSB) & MAC_DCU_MISC_3_FRAG_BURST_BKOFF_EN_MASK)
#define MAC_DCU_MISC_3_FRAG_BURST_BKOFF_EN_RESET                     0
#define MAC_DCU_MISC_3_FRAG_BURST_WAIT_QCU_EN_MSB                    8
#define MAC_DCU_MISC_3_FRAG_BURST_WAIT_QCU_EN_LSB                    8
#define MAC_DCU_MISC_3_FRAG_BURST_WAIT_QCU_EN_MASK                   0x00000100
#define MAC_DCU_MISC_3_FRAG_BURST_WAIT_QCU_EN_GET(x)                 (((x) & MAC_DCU_MISC_3_FRAG_BURST_WAIT_QCU_EN_MASK) >> MAC_DCU_MISC_3_FRAG_BURST_WAIT_QCU_EN_LSB)
#define MAC_DCU_MISC_3_FRAG_BURST_WAIT_QCU_EN_SET(x)                 (((0 | (x)) << MAC_DCU_MISC_3_FRAG_BURST_WAIT_QCU_EN_LSB) & MAC_DCU_MISC_3_FRAG_BURST_WAIT_QCU_EN_MASK)
#define MAC_DCU_MISC_3_FRAG_BURST_WAIT_QCU_EN_RESET                  0
#define MAC_DCU_MISC_3_CW_RST_AT_TS_END_DIS_MSB                      7
#define MAC_DCU_MISC_3_CW_RST_AT_TS_END_DIS_LSB                      7
#define MAC_DCU_MISC_3_CW_RST_AT_TS_END_DIS_MASK                     0x00000080
#define MAC_DCU_MISC_3_CW_RST_AT_TS_END_DIS_GET(x)                   (((x) & MAC_DCU_MISC_3_CW_RST_AT_TS_END_DIS_MASK) >> MAC_DCU_MISC_3_CW_RST_AT_TS_END_DIS_LSB)
#define MAC_DCU_MISC_3_CW_RST_AT_TS_END_DIS_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_3_CW_RST_AT_TS_END_DIS_LSB) & MAC_DCU_MISC_3_CW_RST_AT_TS_END_DIS_MASK)
#define MAC_DCU_MISC_3_CW_RST_AT_TS_END_DIS_RESET                    0
#define MAC_DCU_MISC_3_SFC_RST_AT_TS_END_EN_MSB                      6
#define MAC_DCU_MISC_3_SFC_RST_AT_TS_END_EN_LSB                      6
#define MAC_DCU_MISC_3_SFC_RST_AT_TS_END_EN_MASK                     0x00000040
#define MAC_DCU_MISC_3_SFC_RST_AT_TS_END_EN_GET(x)                   (((x) & MAC_DCU_MISC_3_SFC_RST_AT_TS_END_EN_MASK) >> MAC_DCU_MISC_3_SFC_RST_AT_TS_END_EN_LSB)
#define MAC_DCU_MISC_3_SFC_RST_AT_TS_END_EN_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_3_SFC_RST_AT_TS_END_EN_LSB) & MAC_DCU_MISC_3_SFC_RST_AT_TS_END_EN_MASK)
#define MAC_DCU_MISC_3_SFC_RST_AT_TS_END_EN_RESET                    0
#define MAC_DCU_MISC_3_BKOFF_THRESH_MSB                              5
#define MAC_DCU_MISC_3_BKOFF_THRESH_LSB                              0
#define MAC_DCU_MISC_3_BKOFF_THRESH_MASK                             0x0000003f
#define MAC_DCU_MISC_3_BKOFF_THRESH_GET(x)                           (((x) & MAC_DCU_MISC_3_BKOFF_THRESH_MASK) >> MAC_DCU_MISC_3_BKOFF_THRESH_LSB)
#define MAC_DCU_MISC_3_BKOFF_THRESH_SET(x)                           (((0 | (x)) << MAC_DCU_MISC_3_BKOFF_THRESH_LSB) & MAC_DCU_MISC_3_BKOFF_THRESH_MASK)
#define MAC_DCU_MISC_3_BKOFF_THRESH_RESET                            0
#define MAC_DCU_MISC_3_ADDRESS                                       0x110c
#define MAC_DCU_MISC_3_HW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_3_SW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_3_HW_WRITE_MASK                                 0x00000000
#define MAC_DCU_MISC_3_SW_WRITE_MASK                                 0x01ffdbff
#define MAC_DCU_MISC_3_RSTMASK                                       0xffffffff
#define MAC_DCU_MISC_3_RESET                                         0x01000000

// 0x1110 (MAC_DCU_MISC_4)
#define MAC_DCU_MISC_4_SIFS_BURST_CHAN_BUSY_IGNORE_MSB               24
#define MAC_DCU_MISC_4_SIFS_BURST_CHAN_BUSY_IGNORE_LSB               24
#define MAC_DCU_MISC_4_SIFS_BURST_CHAN_BUSY_IGNORE_MASK              0x01000000
#define MAC_DCU_MISC_4_SIFS_BURST_CHAN_BUSY_IGNORE_GET(x)            (((x) & MAC_DCU_MISC_4_SIFS_BURST_CHAN_BUSY_IGNORE_MASK) >> MAC_DCU_MISC_4_SIFS_BURST_CHAN_BUSY_IGNORE_LSB)
#define MAC_DCU_MISC_4_SIFS_BURST_CHAN_BUSY_IGNORE_SET(x)            (((0 | (x)) << MAC_DCU_MISC_4_SIFS_BURST_CHAN_BUSY_IGNORE_LSB) & MAC_DCU_MISC_4_SIFS_BURST_CHAN_BUSY_IGNORE_MASK)
#define MAC_DCU_MISC_4_SIFS_BURST_CHAN_BUSY_IGNORE_RESET             1
#define MAC_DCU_MISC_4_RETRY_ON_BLOWN_IFS_EN_MSB                     23
#define MAC_DCU_MISC_4_RETRY_ON_BLOWN_IFS_EN_LSB                     23
#define MAC_DCU_MISC_4_RETRY_ON_BLOWN_IFS_EN_MASK                    0x00800000
#define MAC_DCU_MISC_4_RETRY_ON_BLOWN_IFS_EN_GET(x)                  (((x) & MAC_DCU_MISC_4_RETRY_ON_BLOWN_IFS_EN_MASK) >> MAC_DCU_MISC_4_RETRY_ON_BLOWN_IFS_EN_LSB)
#define MAC_DCU_MISC_4_RETRY_ON_BLOWN_IFS_EN_SET(x)                  (((0 | (x)) << MAC_DCU_MISC_4_RETRY_ON_BLOWN_IFS_EN_LSB) & MAC_DCU_MISC_4_RETRY_ON_BLOWN_IFS_EN_MASK)
#define MAC_DCU_MISC_4_RETRY_ON_BLOWN_IFS_EN_RESET                   0
#define MAC_DCU_MISC_4_VIRT_COLL_CW_INC_EN_MSB                       22
#define MAC_DCU_MISC_4_VIRT_COLL_CW_INC_EN_LSB                       22
#define MAC_DCU_MISC_4_VIRT_COLL_CW_INC_EN_MASK                      0x00400000
#define MAC_DCU_MISC_4_VIRT_COLL_CW_INC_EN_GET(x)                    (((x) & MAC_DCU_MISC_4_VIRT_COLL_CW_INC_EN_MASK) >> MAC_DCU_MISC_4_VIRT_COLL_CW_INC_EN_LSB)
#define MAC_DCU_MISC_4_VIRT_COLL_CW_INC_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_4_VIRT_COLL_CW_INC_EN_LSB) & MAC_DCU_MISC_4_VIRT_COLL_CW_INC_EN_MASK)
#define MAC_DCU_MISC_4_VIRT_COLL_CW_INC_EN_RESET                     0
#define MAC_DCU_MISC_4_POST_BKOFF_SKIP_MSB                           21
#define MAC_DCU_MISC_4_POST_BKOFF_SKIP_LSB                           21
#define MAC_DCU_MISC_4_POST_BKOFF_SKIP_MASK                          0x00200000
#define MAC_DCU_MISC_4_POST_BKOFF_SKIP_GET(x)                        (((x) & MAC_DCU_MISC_4_POST_BKOFF_SKIP_MASK) >> MAC_DCU_MISC_4_POST_BKOFF_SKIP_LSB)
#define MAC_DCU_MISC_4_POST_BKOFF_SKIP_SET(x)                        (((0 | (x)) << MAC_DCU_MISC_4_POST_BKOFF_SKIP_LSB) & MAC_DCU_MISC_4_POST_BKOFF_SKIP_MASK)
#define MAC_DCU_MISC_4_POST_BKOFF_SKIP_RESET                         0
#define MAC_DCU_MISC_4_SEQNUM_FREEZE_MSB                             20
#define MAC_DCU_MISC_4_SEQNUM_FREEZE_LSB                             20
#define MAC_DCU_MISC_4_SEQNUM_FREEZE_MASK                            0x00100000
#define MAC_DCU_MISC_4_SEQNUM_FREEZE_GET(x)                          (((x) & MAC_DCU_MISC_4_SEQNUM_FREEZE_MASK) >> MAC_DCU_MISC_4_SEQNUM_FREEZE_LSB)
#define MAC_DCU_MISC_4_SEQNUM_FREEZE_SET(x)                          (((0 | (x)) << MAC_DCU_MISC_4_SEQNUM_FREEZE_LSB) & MAC_DCU_MISC_4_SEQNUM_FREEZE_MASK)
#define MAC_DCU_MISC_4_SEQNUM_FREEZE_RESET                           0
#define MAC_DCU_MISC_4_LOCKOUT_IGNORE_MSB                            19
#define MAC_DCU_MISC_4_LOCKOUT_IGNORE_LSB                            19
#define MAC_DCU_MISC_4_LOCKOUT_IGNORE_MASK                           0x00080000
#define MAC_DCU_MISC_4_LOCKOUT_IGNORE_GET(x)                         (((x) & MAC_DCU_MISC_4_LOCKOUT_IGNORE_MASK) >> MAC_DCU_MISC_4_LOCKOUT_IGNORE_LSB)
#define MAC_DCU_MISC_4_LOCKOUT_IGNORE_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_4_LOCKOUT_IGNORE_LSB) & MAC_DCU_MISC_4_LOCKOUT_IGNORE_MASK)
#define MAC_DCU_MISC_4_LOCKOUT_IGNORE_RESET                          0
#define MAC_DCU_MISC_4_LOCKOUT_GBL_EN_MSB                            18
#define MAC_DCU_MISC_4_LOCKOUT_GBL_EN_LSB                            18
#define MAC_DCU_MISC_4_LOCKOUT_GBL_EN_MASK                           0x00040000
#define MAC_DCU_MISC_4_LOCKOUT_GBL_EN_GET(x)                         (((x) & MAC_DCU_MISC_4_LOCKOUT_GBL_EN_MASK) >> MAC_DCU_MISC_4_LOCKOUT_GBL_EN_LSB)
#define MAC_DCU_MISC_4_LOCKOUT_GBL_EN_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_4_LOCKOUT_GBL_EN_LSB) & MAC_DCU_MISC_4_LOCKOUT_GBL_EN_MASK)
#define MAC_DCU_MISC_4_LOCKOUT_GBL_EN_RESET                          0
#define MAC_DCU_MISC_4_ARB_LOCKOUT_IF_EN_MSB                         17
#define MAC_DCU_MISC_4_ARB_LOCKOUT_IF_EN_LSB                         17
#define MAC_DCU_MISC_4_ARB_LOCKOUT_IF_EN_MASK                        0x00020000
#define MAC_DCU_MISC_4_ARB_LOCKOUT_IF_EN_GET(x)                      (((x) & MAC_DCU_MISC_4_ARB_LOCKOUT_IF_EN_MASK) >> MAC_DCU_MISC_4_ARB_LOCKOUT_IF_EN_LSB)
#define MAC_DCU_MISC_4_ARB_LOCKOUT_IF_EN_SET(x)                      (((0 | (x)) << MAC_DCU_MISC_4_ARB_LOCKOUT_IF_EN_LSB) & MAC_DCU_MISC_4_ARB_LOCKOUT_IF_EN_MASK)
#define MAC_DCU_MISC_4_ARB_LOCKOUT_IF_EN_RESET                       0
#define MAC_DCU_MISC_4_IS_BCN_MSB                                    16
#define MAC_DCU_MISC_4_IS_BCN_LSB                                    16
#define MAC_DCU_MISC_4_IS_BCN_MASK                                   0x00010000
#define MAC_DCU_MISC_4_IS_BCN_GET(x)                                 (((x) & MAC_DCU_MISC_4_IS_BCN_MASK) >> MAC_DCU_MISC_4_IS_BCN_LSB)
#define MAC_DCU_MISC_4_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_DCU_MISC_4_IS_BCN_LSB) & MAC_DCU_MISC_4_IS_BCN_MASK)
#define MAC_DCU_MISC_4_IS_BCN_RESET                                  0
#define MAC_DCU_MISC_4_VIRT_COLL_POLICY_MSB                          15
#define MAC_DCU_MISC_4_VIRT_COLL_POLICY_LSB                          14
#define MAC_DCU_MISC_4_VIRT_COLL_POLICY_MASK                         0x0000c000
#define MAC_DCU_MISC_4_VIRT_COLL_POLICY_GET(x)                       (((x) & MAC_DCU_MISC_4_VIRT_COLL_POLICY_MASK) >> MAC_DCU_MISC_4_VIRT_COLL_POLICY_LSB)
#define MAC_DCU_MISC_4_VIRT_COLL_POLICY_SET(x)                       (((0 | (x)) << MAC_DCU_MISC_4_VIRT_COLL_POLICY_LSB) & MAC_DCU_MISC_4_VIRT_COLL_POLICY_MASK)
#define MAC_DCU_MISC_4_VIRT_COLL_POLICY_RESET                        0
#define MAC_DCU_MISC_4_BKOFF_PF_MSB                                  12
#define MAC_DCU_MISC_4_BKOFF_PF_LSB                                  12
#define MAC_DCU_MISC_4_BKOFF_PF_MASK                                 0x00001000
#define MAC_DCU_MISC_4_BKOFF_PF_GET(x)                               (((x) & MAC_DCU_MISC_4_BKOFF_PF_MASK) >> MAC_DCU_MISC_4_BKOFF_PF_LSB)
#define MAC_DCU_MISC_4_BKOFF_PF_SET(x)                               (((0 | (x)) << MAC_DCU_MISC_4_BKOFF_PF_LSB) & MAC_DCU_MISC_4_BKOFF_PF_MASK)
#define MAC_DCU_MISC_4_BKOFF_PF_RESET                                0
#define MAC_DCU_MISC_4_HCF_POLL_EN_MSB                               11
#define MAC_DCU_MISC_4_HCF_POLL_EN_LSB                               11
#define MAC_DCU_MISC_4_HCF_POLL_EN_MASK                              0x00000800
#define MAC_DCU_MISC_4_HCF_POLL_EN_GET(x)                            (((x) & MAC_DCU_MISC_4_HCF_POLL_EN_MASK) >> MAC_DCU_MISC_4_HCF_POLL_EN_LSB)
#define MAC_DCU_MISC_4_HCF_POLL_EN_SET(x)                            (((0 | (x)) << MAC_DCU_MISC_4_HCF_POLL_EN_LSB) & MAC_DCU_MISC_4_HCF_POLL_EN_MASK)
#define MAC_DCU_MISC_4_HCF_POLL_EN_RESET                             0
#define MAC_DCU_MISC_4_FRAG_BURST_BKOFF_EN_MSB                       9
#define MAC_DCU_MISC_4_FRAG_BURST_BKOFF_EN_LSB                       9
#define MAC_DCU_MISC_4_FRAG_BURST_BKOFF_EN_MASK                      0x00000200
#define MAC_DCU_MISC_4_FRAG_BURST_BKOFF_EN_GET(x)                    (((x) & MAC_DCU_MISC_4_FRAG_BURST_BKOFF_EN_MASK) >> MAC_DCU_MISC_4_FRAG_BURST_BKOFF_EN_LSB)
#define MAC_DCU_MISC_4_FRAG_BURST_BKOFF_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_4_FRAG_BURST_BKOFF_EN_LSB) & MAC_DCU_MISC_4_FRAG_BURST_BKOFF_EN_MASK)
#define MAC_DCU_MISC_4_FRAG_BURST_BKOFF_EN_RESET                     0
#define MAC_DCU_MISC_4_FRAG_BURST_WAIT_QCU_EN_MSB                    8
#define MAC_DCU_MISC_4_FRAG_BURST_WAIT_QCU_EN_LSB                    8
#define MAC_DCU_MISC_4_FRAG_BURST_WAIT_QCU_EN_MASK                   0x00000100
#define MAC_DCU_MISC_4_FRAG_BURST_WAIT_QCU_EN_GET(x)                 (((x) & MAC_DCU_MISC_4_FRAG_BURST_WAIT_QCU_EN_MASK) >> MAC_DCU_MISC_4_FRAG_BURST_WAIT_QCU_EN_LSB)
#define MAC_DCU_MISC_4_FRAG_BURST_WAIT_QCU_EN_SET(x)                 (((0 | (x)) << MAC_DCU_MISC_4_FRAG_BURST_WAIT_QCU_EN_LSB) & MAC_DCU_MISC_4_FRAG_BURST_WAIT_QCU_EN_MASK)
#define MAC_DCU_MISC_4_FRAG_BURST_WAIT_QCU_EN_RESET                  0
#define MAC_DCU_MISC_4_CW_RST_AT_TS_END_DIS_MSB                      7
#define MAC_DCU_MISC_4_CW_RST_AT_TS_END_DIS_LSB                      7
#define MAC_DCU_MISC_4_CW_RST_AT_TS_END_DIS_MASK                     0x00000080
#define MAC_DCU_MISC_4_CW_RST_AT_TS_END_DIS_GET(x)                   (((x) & MAC_DCU_MISC_4_CW_RST_AT_TS_END_DIS_MASK) >> MAC_DCU_MISC_4_CW_RST_AT_TS_END_DIS_LSB)
#define MAC_DCU_MISC_4_CW_RST_AT_TS_END_DIS_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_4_CW_RST_AT_TS_END_DIS_LSB) & MAC_DCU_MISC_4_CW_RST_AT_TS_END_DIS_MASK)
#define MAC_DCU_MISC_4_CW_RST_AT_TS_END_DIS_RESET                    0
#define MAC_DCU_MISC_4_SFC_RST_AT_TS_END_EN_MSB                      6
#define MAC_DCU_MISC_4_SFC_RST_AT_TS_END_EN_LSB                      6
#define MAC_DCU_MISC_4_SFC_RST_AT_TS_END_EN_MASK                     0x00000040
#define MAC_DCU_MISC_4_SFC_RST_AT_TS_END_EN_GET(x)                   (((x) & MAC_DCU_MISC_4_SFC_RST_AT_TS_END_EN_MASK) >> MAC_DCU_MISC_4_SFC_RST_AT_TS_END_EN_LSB)
#define MAC_DCU_MISC_4_SFC_RST_AT_TS_END_EN_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_4_SFC_RST_AT_TS_END_EN_LSB) & MAC_DCU_MISC_4_SFC_RST_AT_TS_END_EN_MASK)
#define MAC_DCU_MISC_4_SFC_RST_AT_TS_END_EN_RESET                    0
#define MAC_DCU_MISC_4_BKOFF_THRESH_MSB                              5
#define MAC_DCU_MISC_4_BKOFF_THRESH_LSB                              0
#define MAC_DCU_MISC_4_BKOFF_THRESH_MASK                             0x0000003f
#define MAC_DCU_MISC_4_BKOFF_THRESH_GET(x)                           (((x) & MAC_DCU_MISC_4_BKOFF_THRESH_MASK) >> MAC_DCU_MISC_4_BKOFF_THRESH_LSB)
#define MAC_DCU_MISC_4_BKOFF_THRESH_SET(x)                           (((0 | (x)) << MAC_DCU_MISC_4_BKOFF_THRESH_LSB) & MAC_DCU_MISC_4_BKOFF_THRESH_MASK)
#define MAC_DCU_MISC_4_BKOFF_THRESH_RESET                            0
#define MAC_DCU_MISC_4_ADDRESS                                       0x1110
#define MAC_DCU_MISC_4_HW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_4_SW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_4_HW_WRITE_MASK                                 0x00000000
#define MAC_DCU_MISC_4_SW_WRITE_MASK                                 0x01ffdbff
#define MAC_DCU_MISC_4_RSTMASK                                       0xffffffff
#define MAC_DCU_MISC_4_RESET                                         0x01000000

// 0x1114 (MAC_DCU_MISC_5)
#define MAC_DCU_MISC_5_SIFS_BURST_CHAN_BUSY_IGNORE_MSB               24
#define MAC_DCU_MISC_5_SIFS_BURST_CHAN_BUSY_IGNORE_LSB               24
#define MAC_DCU_MISC_5_SIFS_BURST_CHAN_BUSY_IGNORE_MASK              0x01000000
#define MAC_DCU_MISC_5_SIFS_BURST_CHAN_BUSY_IGNORE_GET(x)            (((x) & MAC_DCU_MISC_5_SIFS_BURST_CHAN_BUSY_IGNORE_MASK) >> MAC_DCU_MISC_5_SIFS_BURST_CHAN_BUSY_IGNORE_LSB)
#define MAC_DCU_MISC_5_SIFS_BURST_CHAN_BUSY_IGNORE_SET(x)            (((0 | (x)) << MAC_DCU_MISC_5_SIFS_BURST_CHAN_BUSY_IGNORE_LSB) & MAC_DCU_MISC_5_SIFS_BURST_CHAN_BUSY_IGNORE_MASK)
#define MAC_DCU_MISC_5_SIFS_BURST_CHAN_BUSY_IGNORE_RESET             1
#define MAC_DCU_MISC_5_RETRY_ON_BLOWN_IFS_EN_MSB                     23
#define MAC_DCU_MISC_5_RETRY_ON_BLOWN_IFS_EN_LSB                     23
#define MAC_DCU_MISC_5_RETRY_ON_BLOWN_IFS_EN_MASK                    0x00800000
#define MAC_DCU_MISC_5_RETRY_ON_BLOWN_IFS_EN_GET(x)                  (((x) & MAC_DCU_MISC_5_RETRY_ON_BLOWN_IFS_EN_MASK) >> MAC_DCU_MISC_5_RETRY_ON_BLOWN_IFS_EN_LSB)
#define MAC_DCU_MISC_5_RETRY_ON_BLOWN_IFS_EN_SET(x)                  (((0 | (x)) << MAC_DCU_MISC_5_RETRY_ON_BLOWN_IFS_EN_LSB) & MAC_DCU_MISC_5_RETRY_ON_BLOWN_IFS_EN_MASK)
#define MAC_DCU_MISC_5_RETRY_ON_BLOWN_IFS_EN_RESET                   0
#define MAC_DCU_MISC_5_VIRT_COLL_CW_INC_EN_MSB                       22
#define MAC_DCU_MISC_5_VIRT_COLL_CW_INC_EN_LSB                       22
#define MAC_DCU_MISC_5_VIRT_COLL_CW_INC_EN_MASK                      0x00400000
#define MAC_DCU_MISC_5_VIRT_COLL_CW_INC_EN_GET(x)                    (((x) & MAC_DCU_MISC_5_VIRT_COLL_CW_INC_EN_MASK) >> MAC_DCU_MISC_5_VIRT_COLL_CW_INC_EN_LSB)
#define MAC_DCU_MISC_5_VIRT_COLL_CW_INC_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_5_VIRT_COLL_CW_INC_EN_LSB) & MAC_DCU_MISC_5_VIRT_COLL_CW_INC_EN_MASK)
#define MAC_DCU_MISC_5_VIRT_COLL_CW_INC_EN_RESET                     0
#define MAC_DCU_MISC_5_POST_BKOFF_SKIP_MSB                           21
#define MAC_DCU_MISC_5_POST_BKOFF_SKIP_LSB                           21
#define MAC_DCU_MISC_5_POST_BKOFF_SKIP_MASK                          0x00200000
#define MAC_DCU_MISC_5_POST_BKOFF_SKIP_GET(x)                        (((x) & MAC_DCU_MISC_5_POST_BKOFF_SKIP_MASK) >> MAC_DCU_MISC_5_POST_BKOFF_SKIP_LSB)
#define MAC_DCU_MISC_5_POST_BKOFF_SKIP_SET(x)                        (((0 | (x)) << MAC_DCU_MISC_5_POST_BKOFF_SKIP_LSB) & MAC_DCU_MISC_5_POST_BKOFF_SKIP_MASK)
#define MAC_DCU_MISC_5_POST_BKOFF_SKIP_RESET                         0
#define MAC_DCU_MISC_5_SEQNUM_FREEZE_MSB                             20
#define MAC_DCU_MISC_5_SEQNUM_FREEZE_LSB                             20
#define MAC_DCU_MISC_5_SEQNUM_FREEZE_MASK                            0x00100000
#define MAC_DCU_MISC_5_SEQNUM_FREEZE_GET(x)                          (((x) & MAC_DCU_MISC_5_SEQNUM_FREEZE_MASK) >> MAC_DCU_MISC_5_SEQNUM_FREEZE_LSB)
#define MAC_DCU_MISC_5_SEQNUM_FREEZE_SET(x)                          (((0 | (x)) << MAC_DCU_MISC_5_SEQNUM_FREEZE_LSB) & MAC_DCU_MISC_5_SEQNUM_FREEZE_MASK)
#define MAC_DCU_MISC_5_SEQNUM_FREEZE_RESET                           0
#define MAC_DCU_MISC_5_LOCKOUT_IGNORE_MSB                            19
#define MAC_DCU_MISC_5_LOCKOUT_IGNORE_LSB                            19
#define MAC_DCU_MISC_5_LOCKOUT_IGNORE_MASK                           0x00080000
#define MAC_DCU_MISC_5_LOCKOUT_IGNORE_GET(x)                         (((x) & MAC_DCU_MISC_5_LOCKOUT_IGNORE_MASK) >> MAC_DCU_MISC_5_LOCKOUT_IGNORE_LSB)
#define MAC_DCU_MISC_5_LOCKOUT_IGNORE_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_5_LOCKOUT_IGNORE_LSB) & MAC_DCU_MISC_5_LOCKOUT_IGNORE_MASK)
#define MAC_DCU_MISC_5_LOCKOUT_IGNORE_RESET                          0
#define MAC_DCU_MISC_5_LOCKOUT_GBL_EN_MSB                            18
#define MAC_DCU_MISC_5_LOCKOUT_GBL_EN_LSB                            18
#define MAC_DCU_MISC_5_LOCKOUT_GBL_EN_MASK                           0x00040000
#define MAC_DCU_MISC_5_LOCKOUT_GBL_EN_GET(x)                         (((x) & MAC_DCU_MISC_5_LOCKOUT_GBL_EN_MASK) >> MAC_DCU_MISC_5_LOCKOUT_GBL_EN_LSB)
#define MAC_DCU_MISC_5_LOCKOUT_GBL_EN_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_5_LOCKOUT_GBL_EN_LSB) & MAC_DCU_MISC_5_LOCKOUT_GBL_EN_MASK)
#define MAC_DCU_MISC_5_LOCKOUT_GBL_EN_RESET                          0
#define MAC_DCU_MISC_5_ARB_LOCKOUT_IF_EN_MSB                         17
#define MAC_DCU_MISC_5_ARB_LOCKOUT_IF_EN_LSB                         17
#define MAC_DCU_MISC_5_ARB_LOCKOUT_IF_EN_MASK                        0x00020000
#define MAC_DCU_MISC_5_ARB_LOCKOUT_IF_EN_GET(x)                      (((x) & MAC_DCU_MISC_5_ARB_LOCKOUT_IF_EN_MASK) >> MAC_DCU_MISC_5_ARB_LOCKOUT_IF_EN_LSB)
#define MAC_DCU_MISC_5_ARB_LOCKOUT_IF_EN_SET(x)                      (((0 | (x)) << MAC_DCU_MISC_5_ARB_LOCKOUT_IF_EN_LSB) & MAC_DCU_MISC_5_ARB_LOCKOUT_IF_EN_MASK)
#define MAC_DCU_MISC_5_ARB_LOCKOUT_IF_EN_RESET                       0
#define MAC_DCU_MISC_5_IS_BCN_MSB                                    16
#define MAC_DCU_MISC_5_IS_BCN_LSB                                    16
#define MAC_DCU_MISC_5_IS_BCN_MASK                                   0x00010000
#define MAC_DCU_MISC_5_IS_BCN_GET(x)                                 (((x) & MAC_DCU_MISC_5_IS_BCN_MASK) >> MAC_DCU_MISC_5_IS_BCN_LSB)
#define MAC_DCU_MISC_5_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_DCU_MISC_5_IS_BCN_LSB) & MAC_DCU_MISC_5_IS_BCN_MASK)
#define MAC_DCU_MISC_5_IS_BCN_RESET                                  0
#define MAC_DCU_MISC_5_VIRT_COLL_POLICY_MSB                          15
#define MAC_DCU_MISC_5_VIRT_COLL_POLICY_LSB                          14
#define MAC_DCU_MISC_5_VIRT_COLL_POLICY_MASK                         0x0000c000
#define MAC_DCU_MISC_5_VIRT_COLL_POLICY_GET(x)                       (((x) & MAC_DCU_MISC_5_VIRT_COLL_POLICY_MASK) >> MAC_DCU_MISC_5_VIRT_COLL_POLICY_LSB)
#define MAC_DCU_MISC_5_VIRT_COLL_POLICY_SET(x)                       (((0 | (x)) << MAC_DCU_MISC_5_VIRT_COLL_POLICY_LSB) & MAC_DCU_MISC_5_VIRT_COLL_POLICY_MASK)
#define MAC_DCU_MISC_5_VIRT_COLL_POLICY_RESET                        0
#define MAC_DCU_MISC_5_BKOFF_PF_MSB                                  12
#define MAC_DCU_MISC_5_BKOFF_PF_LSB                                  12
#define MAC_DCU_MISC_5_BKOFF_PF_MASK                                 0x00001000
#define MAC_DCU_MISC_5_BKOFF_PF_GET(x)                               (((x) & MAC_DCU_MISC_5_BKOFF_PF_MASK) >> MAC_DCU_MISC_5_BKOFF_PF_LSB)
#define MAC_DCU_MISC_5_BKOFF_PF_SET(x)                               (((0 | (x)) << MAC_DCU_MISC_5_BKOFF_PF_LSB) & MAC_DCU_MISC_5_BKOFF_PF_MASK)
#define MAC_DCU_MISC_5_BKOFF_PF_RESET                                0
#define MAC_DCU_MISC_5_HCF_POLL_EN_MSB                               11
#define MAC_DCU_MISC_5_HCF_POLL_EN_LSB                               11
#define MAC_DCU_MISC_5_HCF_POLL_EN_MASK                              0x00000800
#define MAC_DCU_MISC_5_HCF_POLL_EN_GET(x)                            (((x) & MAC_DCU_MISC_5_HCF_POLL_EN_MASK) >> MAC_DCU_MISC_5_HCF_POLL_EN_LSB)
#define MAC_DCU_MISC_5_HCF_POLL_EN_SET(x)                            (((0 | (x)) << MAC_DCU_MISC_5_HCF_POLL_EN_LSB) & MAC_DCU_MISC_5_HCF_POLL_EN_MASK)
#define MAC_DCU_MISC_5_HCF_POLL_EN_RESET                             0
#define MAC_DCU_MISC_5_FRAG_BURST_BKOFF_EN_MSB                       9
#define MAC_DCU_MISC_5_FRAG_BURST_BKOFF_EN_LSB                       9
#define MAC_DCU_MISC_5_FRAG_BURST_BKOFF_EN_MASK                      0x00000200
#define MAC_DCU_MISC_5_FRAG_BURST_BKOFF_EN_GET(x)                    (((x) & MAC_DCU_MISC_5_FRAG_BURST_BKOFF_EN_MASK) >> MAC_DCU_MISC_5_FRAG_BURST_BKOFF_EN_LSB)
#define MAC_DCU_MISC_5_FRAG_BURST_BKOFF_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_5_FRAG_BURST_BKOFF_EN_LSB) & MAC_DCU_MISC_5_FRAG_BURST_BKOFF_EN_MASK)
#define MAC_DCU_MISC_5_FRAG_BURST_BKOFF_EN_RESET                     0
#define MAC_DCU_MISC_5_FRAG_BURST_WAIT_QCU_EN_MSB                    8
#define MAC_DCU_MISC_5_FRAG_BURST_WAIT_QCU_EN_LSB                    8
#define MAC_DCU_MISC_5_FRAG_BURST_WAIT_QCU_EN_MASK                   0x00000100
#define MAC_DCU_MISC_5_FRAG_BURST_WAIT_QCU_EN_GET(x)                 (((x) & MAC_DCU_MISC_5_FRAG_BURST_WAIT_QCU_EN_MASK) >> MAC_DCU_MISC_5_FRAG_BURST_WAIT_QCU_EN_LSB)
#define MAC_DCU_MISC_5_FRAG_BURST_WAIT_QCU_EN_SET(x)                 (((0 | (x)) << MAC_DCU_MISC_5_FRAG_BURST_WAIT_QCU_EN_LSB) & MAC_DCU_MISC_5_FRAG_BURST_WAIT_QCU_EN_MASK)
#define MAC_DCU_MISC_5_FRAG_BURST_WAIT_QCU_EN_RESET                  0
#define MAC_DCU_MISC_5_CW_RST_AT_TS_END_DIS_MSB                      7
#define MAC_DCU_MISC_5_CW_RST_AT_TS_END_DIS_LSB                      7
#define MAC_DCU_MISC_5_CW_RST_AT_TS_END_DIS_MASK                     0x00000080
#define MAC_DCU_MISC_5_CW_RST_AT_TS_END_DIS_GET(x)                   (((x) & MAC_DCU_MISC_5_CW_RST_AT_TS_END_DIS_MASK) >> MAC_DCU_MISC_5_CW_RST_AT_TS_END_DIS_LSB)
#define MAC_DCU_MISC_5_CW_RST_AT_TS_END_DIS_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_5_CW_RST_AT_TS_END_DIS_LSB) & MAC_DCU_MISC_5_CW_RST_AT_TS_END_DIS_MASK)
#define MAC_DCU_MISC_5_CW_RST_AT_TS_END_DIS_RESET                    0
#define MAC_DCU_MISC_5_SFC_RST_AT_TS_END_EN_MSB                      6
#define MAC_DCU_MISC_5_SFC_RST_AT_TS_END_EN_LSB                      6
#define MAC_DCU_MISC_5_SFC_RST_AT_TS_END_EN_MASK                     0x00000040
#define MAC_DCU_MISC_5_SFC_RST_AT_TS_END_EN_GET(x)                   (((x) & MAC_DCU_MISC_5_SFC_RST_AT_TS_END_EN_MASK) >> MAC_DCU_MISC_5_SFC_RST_AT_TS_END_EN_LSB)
#define MAC_DCU_MISC_5_SFC_RST_AT_TS_END_EN_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_5_SFC_RST_AT_TS_END_EN_LSB) & MAC_DCU_MISC_5_SFC_RST_AT_TS_END_EN_MASK)
#define MAC_DCU_MISC_5_SFC_RST_AT_TS_END_EN_RESET                    0
#define MAC_DCU_MISC_5_BKOFF_THRESH_MSB                              5
#define MAC_DCU_MISC_5_BKOFF_THRESH_LSB                              0
#define MAC_DCU_MISC_5_BKOFF_THRESH_MASK                             0x0000003f
#define MAC_DCU_MISC_5_BKOFF_THRESH_GET(x)                           (((x) & MAC_DCU_MISC_5_BKOFF_THRESH_MASK) >> MAC_DCU_MISC_5_BKOFF_THRESH_LSB)
#define MAC_DCU_MISC_5_BKOFF_THRESH_SET(x)                           (((0 | (x)) << MAC_DCU_MISC_5_BKOFF_THRESH_LSB) & MAC_DCU_MISC_5_BKOFF_THRESH_MASK)
#define MAC_DCU_MISC_5_BKOFF_THRESH_RESET                            0
#define MAC_DCU_MISC_5_ADDRESS                                       0x1114
#define MAC_DCU_MISC_5_HW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_5_SW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_5_HW_WRITE_MASK                                 0x00000000
#define MAC_DCU_MISC_5_SW_WRITE_MASK                                 0x01ffdbff
#define MAC_DCU_MISC_5_RSTMASK                                       0xffffffff
#define MAC_DCU_MISC_5_RESET                                         0x01000000

// 0x1118 (MAC_DCU_MISC_6)
#define MAC_DCU_MISC_6_SIFS_BURST_CHAN_BUSY_IGNORE_MSB               24
#define MAC_DCU_MISC_6_SIFS_BURST_CHAN_BUSY_IGNORE_LSB               24
#define MAC_DCU_MISC_6_SIFS_BURST_CHAN_BUSY_IGNORE_MASK              0x01000000
#define MAC_DCU_MISC_6_SIFS_BURST_CHAN_BUSY_IGNORE_GET(x)            (((x) & MAC_DCU_MISC_6_SIFS_BURST_CHAN_BUSY_IGNORE_MASK) >> MAC_DCU_MISC_6_SIFS_BURST_CHAN_BUSY_IGNORE_LSB)
#define MAC_DCU_MISC_6_SIFS_BURST_CHAN_BUSY_IGNORE_SET(x)            (((0 | (x)) << MAC_DCU_MISC_6_SIFS_BURST_CHAN_BUSY_IGNORE_LSB) & MAC_DCU_MISC_6_SIFS_BURST_CHAN_BUSY_IGNORE_MASK)
#define MAC_DCU_MISC_6_SIFS_BURST_CHAN_BUSY_IGNORE_RESET             1
#define MAC_DCU_MISC_6_RETRY_ON_BLOWN_IFS_EN_MSB                     23
#define MAC_DCU_MISC_6_RETRY_ON_BLOWN_IFS_EN_LSB                     23
#define MAC_DCU_MISC_6_RETRY_ON_BLOWN_IFS_EN_MASK                    0x00800000
#define MAC_DCU_MISC_6_RETRY_ON_BLOWN_IFS_EN_GET(x)                  (((x) & MAC_DCU_MISC_6_RETRY_ON_BLOWN_IFS_EN_MASK) >> MAC_DCU_MISC_6_RETRY_ON_BLOWN_IFS_EN_LSB)
#define MAC_DCU_MISC_6_RETRY_ON_BLOWN_IFS_EN_SET(x)                  (((0 | (x)) << MAC_DCU_MISC_6_RETRY_ON_BLOWN_IFS_EN_LSB) & MAC_DCU_MISC_6_RETRY_ON_BLOWN_IFS_EN_MASK)
#define MAC_DCU_MISC_6_RETRY_ON_BLOWN_IFS_EN_RESET                   0
#define MAC_DCU_MISC_6_VIRT_COLL_CW_INC_EN_MSB                       22
#define MAC_DCU_MISC_6_VIRT_COLL_CW_INC_EN_LSB                       22
#define MAC_DCU_MISC_6_VIRT_COLL_CW_INC_EN_MASK                      0x00400000
#define MAC_DCU_MISC_6_VIRT_COLL_CW_INC_EN_GET(x)                    (((x) & MAC_DCU_MISC_6_VIRT_COLL_CW_INC_EN_MASK) >> MAC_DCU_MISC_6_VIRT_COLL_CW_INC_EN_LSB)
#define MAC_DCU_MISC_6_VIRT_COLL_CW_INC_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_6_VIRT_COLL_CW_INC_EN_LSB) & MAC_DCU_MISC_6_VIRT_COLL_CW_INC_EN_MASK)
#define MAC_DCU_MISC_6_VIRT_COLL_CW_INC_EN_RESET                     0
#define MAC_DCU_MISC_6_POST_BKOFF_SKIP_MSB                           21
#define MAC_DCU_MISC_6_POST_BKOFF_SKIP_LSB                           21
#define MAC_DCU_MISC_6_POST_BKOFF_SKIP_MASK                          0x00200000
#define MAC_DCU_MISC_6_POST_BKOFF_SKIP_GET(x)                        (((x) & MAC_DCU_MISC_6_POST_BKOFF_SKIP_MASK) >> MAC_DCU_MISC_6_POST_BKOFF_SKIP_LSB)
#define MAC_DCU_MISC_6_POST_BKOFF_SKIP_SET(x)                        (((0 | (x)) << MAC_DCU_MISC_6_POST_BKOFF_SKIP_LSB) & MAC_DCU_MISC_6_POST_BKOFF_SKIP_MASK)
#define MAC_DCU_MISC_6_POST_BKOFF_SKIP_RESET                         0
#define MAC_DCU_MISC_6_SEQNUM_FREEZE_MSB                             20
#define MAC_DCU_MISC_6_SEQNUM_FREEZE_LSB                             20
#define MAC_DCU_MISC_6_SEQNUM_FREEZE_MASK                            0x00100000
#define MAC_DCU_MISC_6_SEQNUM_FREEZE_GET(x)                          (((x) & MAC_DCU_MISC_6_SEQNUM_FREEZE_MASK) >> MAC_DCU_MISC_6_SEQNUM_FREEZE_LSB)
#define MAC_DCU_MISC_6_SEQNUM_FREEZE_SET(x)                          (((0 | (x)) << MAC_DCU_MISC_6_SEQNUM_FREEZE_LSB) & MAC_DCU_MISC_6_SEQNUM_FREEZE_MASK)
#define MAC_DCU_MISC_6_SEQNUM_FREEZE_RESET                           0
#define MAC_DCU_MISC_6_LOCKOUT_IGNORE_MSB                            19
#define MAC_DCU_MISC_6_LOCKOUT_IGNORE_LSB                            19
#define MAC_DCU_MISC_6_LOCKOUT_IGNORE_MASK                           0x00080000
#define MAC_DCU_MISC_6_LOCKOUT_IGNORE_GET(x)                         (((x) & MAC_DCU_MISC_6_LOCKOUT_IGNORE_MASK) >> MAC_DCU_MISC_6_LOCKOUT_IGNORE_LSB)
#define MAC_DCU_MISC_6_LOCKOUT_IGNORE_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_6_LOCKOUT_IGNORE_LSB) & MAC_DCU_MISC_6_LOCKOUT_IGNORE_MASK)
#define MAC_DCU_MISC_6_LOCKOUT_IGNORE_RESET                          0
#define MAC_DCU_MISC_6_LOCKOUT_GBL_EN_MSB                            18
#define MAC_DCU_MISC_6_LOCKOUT_GBL_EN_LSB                            18
#define MAC_DCU_MISC_6_LOCKOUT_GBL_EN_MASK                           0x00040000
#define MAC_DCU_MISC_6_LOCKOUT_GBL_EN_GET(x)                         (((x) & MAC_DCU_MISC_6_LOCKOUT_GBL_EN_MASK) >> MAC_DCU_MISC_6_LOCKOUT_GBL_EN_LSB)
#define MAC_DCU_MISC_6_LOCKOUT_GBL_EN_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_6_LOCKOUT_GBL_EN_LSB) & MAC_DCU_MISC_6_LOCKOUT_GBL_EN_MASK)
#define MAC_DCU_MISC_6_LOCKOUT_GBL_EN_RESET                          0
#define MAC_DCU_MISC_6_ARB_LOCKOUT_IF_EN_MSB                         17
#define MAC_DCU_MISC_6_ARB_LOCKOUT_IF_EN_LSB                         17
#define MAC_DCU_MISC_6_ARB_LOCKOUT_IF_EN_MASK                        0x00020000
#define MAC_DCU_MISC_6_ARB_LOCKOUT_IF_EN_GET(x)                      (((x) & MAC_DCU_MISC_6_ARB_LOCKOUT_IF_EN_MASK) >> MAC_DCU_MISC_6_ARB_LOCKOUT_IF_EN_LSB)
#define MAC_DCU_MISC_6_ARB_LOCKOUT_IF_EN_SET(x)                      (((0 | (x)) << MAC_DCU_MISC_6_ARB_LOCKOUT_IF_EN_LSB) & MAC_DCU_MISC_6_ARB_LOCKOUT_IF_EN_MASK)
#define MAC_DCU_MISC_6_ARB_LOCKOUT_IF_EN_RESET                       0
#define MAC_DCU_MISC_6_IS_BCN_MSB                                    16
#define MAC_DCU_MISC_6_IS_BCN_LSB                                    16
#define MAC_DCU_MISC_6_IS_BCN_MASK                                   0x00010000
#define MAC_DCU_MISC_6_IS_BCN_GET(x)                                 (((x) & MAC_DCU_MISC_6_IS_BCN_MASK) >> MAC_DCU_MISC_6_IS_BCN_LSB)
#define MAC_DCU_MISC_6_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_DCU_MISC_6_IS_BCN_LSB) & MAC_DCU_MISC_6_IS_BCN_MASK)
#define MAC_DCU_MISC_6_IS_BCN_RESET                                  0
#define MAC_DCU_MISC_6_VIRT_COLL_POLICY_MSB                          15
#define MAC_DCU_MISC_6_VIRT_COLL_POLICY_LSB                          14
#define MAC_DCU_MISC_6_VIRT_COLL_POLICY_MASK                         0x0000c000
#define MAC_DCU_MISC_6_VIRT_COLL_POLICY_GET(x)                       (((x) & MAC_DCU_MISC_6_VIRT_COLL_POLICY_MASK) >> MAC_DCU_MISC_6_VIRT_COLL_POLICY_LSB)
#define MAC_DCU_MISC_6_VIRT_COLL_POLICY_SET(x)                       (((0 | (x)) << MAC_DCU_MISC_6_VIRT_COLL_POLICY_LSB) & MAC_DCU_MISC_6_VIRT_COLL_POLICY_MASK)
#define MAC_DCU_MISC_6_VIRT_COLL_POLICY_RESET                        0
#define MAC_DCU_MISC_6_BKOFF_PF_MSB                                  12
#define MAC_DCU_MISC_6_BKOFF_PF_LSB                                  12
#define MAC_DCU_MISC_6_BKOFF_PF_MASK                                 0x00001000
#define MAC_DCU_MISC_6_BKOFF_PF_GET(x)                               (((x) & MAC_DCU_MISC_6_BKOFF_PF_MASK) >> MAC_DCU_MISC_6_BKOFF_PF_LSB)
#define MAC_DCU_MISC_6_BKOFF_PF_SET(x)                               (((0 | (x)) << MAC_DCU_MISC_6_BKOFF_PF_LSB) & MAC_DCU_MISC_6_BKOFF_PF_MASK)
#define MAC_DCU_MISC_6_BKOFF_PF_RESET                                0
#define MAC_DCU_MISC_6_HCF_POLL_EN_MSB                               11
#define MAC_DCU_MISC_6_HCF_POLL_EN_LSB                               11
#define MAC_DCU_MISC_6_HCF_POLL_EN_MASK                              0x00000800
#define MAC_DCU_MISC_6_HCF_POLL_EN_GET(x)                            (((x) & MAC_DCU_MISC_6_HCF_POLL_EN_MASK) >> MAC_DCU_MISC_6_HCF_POLL_EN_LSB)
#define MAC_DCU_MISC_6_HCF_POLL_EN_SET(x)                            (((0 | (x)) << MAC_DCU_MISC_6_HCF_POLL_EN_LSB) & MAC_DCU_MISC_6_HCF_POLL_EN_MASK)
#define MAC_DCU_MISC_6_HCF_POLL_EN_RESET                             0
#define MAC_DCU_MISC_6_FRAG_BURST_BKOFF_EN_MSB                       9
#define MAC_DCU_MISC_6_FRAG_BURST_BKOFF_EN_LSB                       9
#define MAC_DCU_MISC_6_FRAG_BURST_BKOFF_EN_MASK                      0x00000200
#define MAC_DCU_MISC_6_FRAG_BURST_BKOFF_EN_GET(x)                    (((x) & MAC_DCU_MISC_6_FRAG_BURST_BKOFF_EN_MASK) >> MAC_DCU_MISC_6_FRAG_BURST_BKOFF_EN_LSB)
#define MAC_DCU_MISC_6_FRAG_BURST_BKOFF_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_6_FRAG_BURST_BKOFF_EN_LSB) & MAC_DCU_MISC_6_FRAG_BURST_BKOFF_EN_MASK)
#define MAC_DCU_MISC_6_FRAG_BURST_BKOFF_EN_RESET                     0
#define MAC_DCU_MISC_6_FRAG_BURST_WAIT_QCU_EN_MSB                    8
#define MAC_DCU_MISC_6_FRAG_BURST_WAIT_QCU_EN_LSB                    8
#define MAC_DCU_MISC_6_FRAG_BURST_WAIT_QCU_EN_MASK                   0x00000100
#define MAC_DCU_MISC_6_FRAG_BURST_WAIT_QCU_EN_GET(x)                 (((x) & MAC_DCU_MISC_6_FRAG_BURST_WAIT_QCU_EN_MASK) >> MAC_DCU_MISC_6_FRAG_BURST_WAIT_QCU_EN_LSB)
#define MAC_DCU_MISC_6_FRAG_BURST_WAIT_QCU_EN_SET(x)                 (((0 | (x)) << MAC_DCU_MISC_6_FRAG_BURST_WAIT_QCU_EN_LSB) & MAC_DCU_MISC_6_FRAG_BURST_WAIT_QCU_EN_MASK)
#define MAC_DCU_MISC_6_FRAG_BURST_WAIT_QCU_EN_RESET                  0
#define MAC_DCU_MISC_6_CW_RST_AT_TS_END_DIS_MSB                      7
#define MAC_DCU_MISC_6_CW_RST_AT_TS_END_DIS_LSB                      7
#define MAC_DCU_MISC_6_CW_RST_AT_TS_END_DIS_MASK                     0x00000080
#define MAC_DCU_MISC_6_CW_RST_AT_TS_END_DIS_GET(x)                   (((x) & MAC_DCU_MISC_6_CW_RST_AT_TS_END_DIS_MASK) >> MAC_DCU_MISC_6_CW_RST_AT_TS_END_DIS_LSB)
#define MAC_DCU_MISC_6_CW_RST_AT_TS_END_DIS_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_6_CW_RST_AT_TS_END_DIS_LSB) & MAC_DCU_MISC_6_CW_RST_AT_TS_END_DIS_MASK)
#define MAC_DCU_MISC_6_CW_RST_AT_TS_END_DIS_RESET                    0
#define MAC_DCU_MISC_6_SFC_RST_AT_TS_END_EN_MSB                      6
#define MAC_DCU_MISC_6_SFC_RST_AT_TS_END_EN_LSB                      6
#define MAC_DCU_MISC_6_SFC_RST_AT_TS_END_EN_MASK                     0x00000040
#define MAC_DCU_MISC_6_SFC_RST_AT_TS_END_EN_GET(x)                   (((x) & MAC_DCU_MISC_6_SFC_RST_AT_TS_END_EN_MASK) >> MAC_DCU_MISC_6_SFC_RST_AT_TS_END_EN_LSB)
#define MAC_DCU_MISC_6_SFC_RST_AT_TS_END_EN_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_6_SFC_RST_AT_TS_END_EN_LSB) & MAC_DCU_MISC_6_SFC_RST_AT_TS_END_EN_MASK)
#define MAC_DCU_MISC_6_SFC_RST_AT_TS_END_EN_RESET                    0
#define MAC_DCU_MISC_6_BKOFF_THRESH_MSB                              5
#define MAC_DCU_MISC_6_BKOFF_THRESH_LSB                              0
#define MAC_DCU_MISC_6_BKOFF_THRESH_MASK                             0x0000003f
#define MAC_DCU_MISC_6_BKOFF_THRESH_GET(x)                           (((x) & MAC_DCU_MISC_6_BKOFF_THRESH_MASK) >> MAC_DCU_MISC_6_BKOFF_THRESH_LSB)
#define MAC_DCU_MISC_6_BKOFF_THRESH_SET(x)                           (((0 | (x)) << MAC_DCU_MISC_6_BKOFF_THRESH_LSB) & MAC_DCU_MISC_6_BKOFF_THRESH_MASK)
#define MAC_DCU_MISC_6_BKOFF_THRESH_RESET                            0
#define MAC_DCU_MISC_6_ADDRESS                                       0x1118
#define MAC_DCU_MISC_6_HW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_6_SW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_6_HW_WRITE_MASK                                 0x00000000
#define MAC_DCU_MISC_6_SW_WRITE_MASK                                 0x01ffdbff
#define MAC_DCU_MISC_6_RSTMASK                                       0xffffffff
#define MAC_DCU_MISC_6_RESET                                         0x01000000

// 0x111c (MAC_DCU_MISC_7)
#define MAC_DCU_MISC_7_SIFS_BURST_CHAN_BUSY_IGNORE_MSB               24
#define MAC_DCU_MISC_7_SIFS_BURST_CHAN_BUSY_IGNORE_LSB               24
#define MAC_DCU_MISC_7_SIFS_BURST_CHAN_BUSY_IGNORE_MASK              0x01000000
#define MAC_DCU_MISC_7_SIFS_BURST_CHAN_BUSY_IGNORE_GET(x)            (((x) & MAC_DCU_MISC_7_SIFS_BURST_CHAN_BUSY_IGNORE_MASK) >> MAC_DCU_MISC_7_SIFS_BURST_CHAN_BUSY_IGNORE_LSB)
#define MAC_DCU_MISC_7_SIFS_BURST_CHAN_BUSY_IGNORE_SET(x)            (((0 | (x)) << MAC_DCU_MISC_7_SIFS_BURST_CHAN_BUSY_IGNORE_LSB) & MAC_DCU_MISC_7_SIFS_BURST_CHAN_BUSY_IGNORE_MASK)
#define MAC_DCU_MISC_7_SIFS_BURST_CHAN_BUSY_IGNORE_RESET             1
#define MAC_DCU_MISC_7_RETRY_ON_BLOWN_IFS_EN_MSB                     23
#define MAC_DCU_MISC_7_RETRY_ON_BLOWN_IFS_EN_LSB                     23
#define MAC_DCU_MISC_7_RETRY_ON_BLOWN_IFS_EN_MASK                    0x00800000
#define MAC_DCU_MISC_7_RETRY_ON_BLOWN_IFS_EN_GET(x)                  (((x) & MAC_DCU_MISC_7_RETRY_ON_BLOWN_IFS_EN_MASK) >> MAC_DCU_MISC_7_RETRY_ON_BLOWN_IFS_EN_LSB)
#define MAC_DCU_MISC_7_RETRY_ON_BLOWN_IFS_EN_SET(x)                  (((0 | (x)) << MAC_DCU_MISC_7_RETRY_ON_BLOWN_IFS_EN_LSB) & MAC_DCU_MISC_7_RETRY_ON_BLOWN_IFS_EN_MASK)
#define MAC_DCU_MISC_7_RETRY_ON_BLOWN_IFS_EN_RESET                   0
#define MAC_DCU_MISC_7_VIRT_COLL_CW_INC_EN_MSB                       22
#define MAC_DCU_MISC_7_VIRT_COLL_CW_INC_EN_LSB                       22
#define MAC_DCU_MISC_7_VIRT_COLL_CW_INC_EN_MASK                      0x00400000
#define MAC_DCU_MISC_7_VIRT_COLL_CW_INC_EN_GET(x)                    (((x) & MAC_DCU_MISC_7_VIRT_COLL_CW_INC_EN_MASK) >> MAC_DCU_MISC_7_VIRT_COLL_CW_INC_EN_LSB)
#define MAC_DCU_MISC_7_VIRT_COLL_CW_INC_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_7_VIRT_COLL_CW_INC_EN_LSB) & MAC_DCU_MISC_7_VIRT_COLL_CW_INC_EN_MASK)
#define MAC_DCU_MISC_7_VIRT_COLL_CW_INC_EN_RESET                     0
#define MAC_DCU_MISC_7_POST_BKOFF_SKIP_MSB                           21
#define MAC_DCU_MISC_7_POST_BKOFF_SKIP_LSB                           21
#define MAC_DCU_MISC_7_POST_BKOFF_SKIP_MASK                          0x00200000
#define MAC_DCU_MISC_7_POST_BKOFF_SKIP_GET(x)                        (((x) & MAC_DCU_MISC_7_POST_BKOFF_SKIP_MASK) >> MAC_DCU_MISC_7_POST_BKOFF_SKIP_LSB)
#define MAC_DCU_MISC_7_POST_BKOFF_SKIP_SET(x)                        (((0 | (x)) << MAC_DCU_MISC_7_POST_BKOFF_SKIP_LSB) & MAC_DCU_MISC_7_POST_BKOFF_SKIP_MASK)
#define MAC_DCU_MISC_7_POST_BKOFF_SKIP_RESET                         0
#define MAC_DCU_MISC_7_SEQNUM_FREEZE_MSB                             20
#define MAC_DCU_MISC_7_SEQNUM_FREEZE_LSB                             20
#define MAC_DCU_MISC_7_SEQNUM_FREEZE_MASK                            0x00100000
#define MAC_DCU_MISC_7_SEQNUM_FREEZE_GET(x)                          (((x) & MAC_DCU_MISC_7_SEQNUM_FREEZE_MASK) >> MAC_DCU_MISC_7_SEQNUM_FREEZE_LSB)
#define MAC_DCU_MISC_7_SEQNUM_FREEZE_SET(x)                          (((0 | (x)) << MAC_DCU_MISC_7_SEQNUM_FREEZE_LSB) & MAC_DCU_MISC_7_SEQNUM_FREEZE_MASK)
#define MAC_DCU_MISC_7_SEQNUM_FREEZE_RESET                           0
#define MAC_DCU_MISC_7_LOCKOUT_IGNORE_MSB                            19
#define MAC_DCU_MISC_7_LOCKOUT_IGNORE_LSB                            19
#define MAC_DCU_MISC_7_LOCKOUT_IGNORE_MASK                           0x00080000
#define MAC_DCU_MISC_7_LOCKOUT_IGNORE_GET(x)                         (((x) & MAC_DCU_MISC_7_LOCKOUT_IGNORE_MASK) >> MAC_DCU_MISC_7_LOCKOUT_IGNORE_LSB)
#define MAC_DCU_MISC_7_LOCKOUT_IGNORE_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_7_LOCKOUT_IGNORE_LSB) & MAC_DCU_MISC_7_LOCKOUT_IGNORE_MASK)
#define MAC_DCU_MISC_7_LOCKOUT_IGNORE_RESET                          0
#define MAC_DCU_MISC_7_LOCKOUT_GBL_EN_MSB                            18
#define MAC_DCU_MISC_7_LOCKOUT_GBL_EN_LSB                            18
#define MAC_DCU_MISC_7_LOCKOUT_GBL_EN_MASK                           0x00040000
#define MAC_DCU_MISC_7_LOCKOUT_GBL_EN_GET(x)                         (((x) & MAC_DCU_MISC_7_LOCKOUT_GBL_EN_MASK) >> MAC_DCU_MISC_7_LOCKOUT_GBL_EN_LSB)
#define MAC_DCU_MISC_7_LOCKOUT_GBL_EN_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_7_LOCKOUT_GBL_EN_LSB) & MAC_DCU_MISC_7_LOCKOUT_GBL_EN_MASK)
#define MAC_DCU_MISC_7_LOCKOUT_GBL_EN_RESET                          0
#define MAC_DCU_MISC_7_ARB_LOCKOUT_IF_EN_MSB                         17
#define MAC_DCU_MISC_7_ARB_LOCKOUT_IF_EN_LSB                         17
#define MAC_DCU_MISC_7_ARB_LOCKOUT_IF_EN_MASK                        0x00020000
#define MAC_DCU_MISC_7_ARB_LOCKOUT_IF_EN_GET(x)                      (((x) & MAC_DCU_MISC_7_ARB_LOCKOUT_IF_EN_MASK) >> MAC_DCU_MISC_7_ARB_LOCKOUT_IF_EN_LSB)
#define MAC_DCU_MISC_7_ARB_LOCKOUT_IF_EN_SET(x)                      (((0 | (x)) << MAC_DCU_MISC_7_ARB_LOCKOUT_IF_EN_LSB) & MAC_DCU_MISC_7_ARB_LOCKOUT_IF_EN_MASK)
#define MAC_DCU_MISC_7_ARB_LOCKOUT_IF_EN_RESET                       0
#define MAC_DCU_MISC_7_IS_BCN_MSB                                    16
#define MAC_DCU_MISC_7_IS_BCN_LSB                                    16
#define MAC_DCU_MISC_7_IS_BCN_MASK                                   0x00010000
#define MAC_DCU_MISC_7_IS_BCN_GET(x)                                 (((x) & MAC_DCU_MISC_7_IS_BCN_MASK) >> MAC_DCU_MISC_7_IS_BCN_LSB)
#define MAC_DCU_MISC_7_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_DCU_MISC_7_IS_BCN_LSB) & MAC_DCU_MISC_7_IS_BCN_MASK)
#define MAC_DCU_MISC_7_IS_BCN_RESET                                  0
#define MAC_DCU_MISC_7_VIRT_COLL_POLICY_MSB                          15
#define MAC_DCU_MISC_7_VIRT_COLL_POLICY_LSB                          14
#define MAC_DCU_MISC_7_VIRT_COLL_POLICY_MASK                         0x0000c000
#define MAC_DCU_MISC_7_VIRT_COLL_POLICY_GET(x)                       (((x) & MAC_DCU_MISC_7_VIRT_COLL_POLICY_MASK) >> MAC_DCU_MISC_7_VIRT_COLL_POLICY_LSB)
#define MAC_DCU_MISC_7_VIRT_COLL_POLICY_SET(x)                       (((0 | (x)) << MAC_DCU_MISC_7_VIRT_COLL_POLICY_LSB) & MAC_DCU_MISC_7_VIRT_COLL_POLICY_MASK)
#define MAC_DCU_MISC_7_VIRT_COLL_POLICY_RESET                        0
#define MAC_DCU_MISC_7_BKOFF_PF_MSB                                  12
#define MAC_DCU_MISC_7_BKOFF_PF_LSB                                  12
#define MAC_DCU_MISC_7_BKOFF_PF_MASK                                 0x00001000
#define MAC_DCU_MISC_7_BKOFF_PF_GET(x)                               (((x) & MAC_DCU_MISC_7_BKOFF_PF_MASK) >> MAC_DCU_MISC_7_BKOFF_PF_LSB)
#define MAC_DCU_MISC_7_BKOFF_PF_SET(x)                               (((0 | (x)) << MAC_DCU_MISC_7_BKOFF_PF_LSB) & MAC_DCU_MISC_7_BKOFF_PF_MASK)
#define MAC_DCU_MISC_7_BKOFF_PF_RESET                                0
#define MAC_DCU_MISC_7_HCF_POLL_EN_MSB                               11
#define MAC_DCU_MISC_7_HCF_POLL_EN_LSB                               11
#define MAC_DCU_MISC_7_HCF_POLL_EN_MASK                              0x00000800
#define MAC_DCU_MISC_7_HCF_POLL_EN_GET(x)                            (((x) & MAC_DCU_MISC_7_HCF_POLL_EN_MASK) >> MAC_DCU_MISC_7_HCF_POLL_EN_LSB)
#define MAC_DCU_MISC_7_HCF_POLL_EN_SET(x)                            (((0 | (x)) << MAC_DCU_MISC_7_HCF_POLL_EN_LSB) & MAC_DCU_MISC_7_HCF_POLL_EN_MASK)
#define MAC_DCU_MISC_7_HCF_POLL_EN_RESET                             0
#define MAC_DCU_MISC_7_FRAG_BURST_BKOFF_EN_MSB                       9
#define MAC_DCU_MISC_7_FRAG_BURST_BKOFF_EN_LSB                       9
#define MAC_DCU_MISC_7_FRAG_BURST_BKOFF_EN_MASK                      0x00000200
#define MAC_DCU_MISC_7_FRAG_BURST_BKOFF_EN_GET(x)                    (((x) & MAC_DCU_MISC_7_FRAG_BURST_BKOFF_EN_MASK) >> MAC_DCU_MISC_7_FRAG_BURST_BKOFF_EN_LSB)
#define MAC_DCU_MISC_7_FRAG_BURST_BKOFF_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_7_FRAG_BURST_BKOFF_EN_LSB) & MAC_DCU_MISC_7_FRAG_BURST_BKOFF_EN_MASK)
#define MAC_DCU_MISC_7_FRAG_BURST_BKOFF_EN_RESET                     0
#define MAC_DCU_MISC_7_FRAG_BURST_WAIT_QCU_EN_MSB                    8
#define MAC_DCU_MISC_7_FRAG_BURST_WAIT_QCU_EN_LSB                    8
#define MAC_DCU_MISC_7_FRAG_BURST_WAIT_QCU_EN_MASK                   0x00000100
#define MAC_DCU_MISC_7_FRAG_BURST_WAIT_QCU_EN_GET(x)                 (((x) & MAC_DCU_MISC_7_FRAG_BURST_WAIT_QCU_EN_MASK) >> MAC_DCU_MISC_7_FRAG_BURST_WAIT_QCU_EN_LSB)
#define MAC_DCU_MISC_7_FRAG_BURST_WAIT_QCU_EN_SET(x)                 (((0 | (x)) << MAC_DCU_MISC_7_FRAG_BURST_WAIT_QCU_EN_LSB) & MAC_DCU_MISC_7_FRAG_BURST_WAIT_QCU_EN_MASK)
#define MAC_DCU_MISC_7_FRAG_BURST_WAIT_QCU_EN_RESET                  0
#define MAC_DCU_MISC_7_CW_RST_AT_TS_END_DIS_MSB                      7
#define MAC_DCU_MISC_7_CW_RST_AT_TS_END_DIS_LSB                      7
#define MAC_DCU_MISC_7_CW_RST_AT_TS_END_DIS_MASK                     0x00000080
#define MAC_DCU_MISC_7_CW_RST_AT_TS_END_DIS_GET(x)                   (((x) & MAC_DCU_MISC_7_CW_RST_AT_TS_END_DIS_MASK) >> MAC_DCU_MISC_7_CW_RST_AT_TS_END_DIS_LSB)
#define MAC_DCU_MISC_7_CW_RST_AT_TS_END_DIS_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_7_CW_RST_AT_TS_END_DIS_LSB) & MAC_DCU_MISC_7_CW_RST_AT_TS_END_DIS_MASK)
#define MAC_DCU_MISC_7_CW_RST_AT_TS_END_DIS_RESET                    0
#define MAC_DCU_MISC_7_SFC_RST_AT_TS_END_EN_MSB                      6
#define MAC_DCU_MISC_7_SFC_RST_AT_TS_END_EN_LSB                      6
#define MAC_DCU_MISC_7_SFC_RST_AT_TS_END_EN_MASK                     0x00000040
#define MAC_DCU_MISC_7_SFC_RST_AT_TS_END_EN_GET(x)                   (((x) & MAC_DCU_MISC_7_SFC_RST_AT_TS_END_EN_MASK) >> MAC_DCU_MISC_7_SFC_RST_AT_TS_END_EN_LSB)
#define MAC_DCU_MISC_7_SFC_RST_AT_TS_END_EN_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_7_SFC_RST_AT_TS_END_EN_LSB) & MAC_DCU_MISC_7_SFC_RST_AT_TS_END_EN_MASK)
#define MAC_DCU_MISC_7_SFC_RST_AT_TS_END_EN_RESET                    0
#define MAC_DCU_MISC_7_BKOFF_THRESH_MSB                              5
#define MAC_DCU_MISC_7_BKOFF_THRESH_LSB                              0
#define MAC_DCU_MISC_7_BKOFF_THRESH_MASK                             0x0000003f
#define MAC_DCU_MISC_7_BKOFF_THRESH_GET(x)                           (((x) & MAC_DCU_MISC_7_BKOFF_THRESH_MASK) >> MAC_DCU_MISC_7_BKOFF_THRESH_LSB)
#define MAC_DCU_MISC_7_BKOFF_THRESH_SET(x)                           (((0 | (x)) << MAC_DCU_MISC_7_BKOFF_THRESH_LSB) & MAC_DCU_MISC_7_BKOFF_THRESH_MASK)
#define MAC_DCU_MISC_7_BKOFF_THRESH_RESET                            0
#define MAC_DCU_MISC_7_ADDRESS                                       0x111c
#define MAC_DCU_MISC_7_HW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_7_SW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_7_HW_WRITE_MASK                                 0x00000000
#define MAC_DCU_MISC_7_SW_WRITE_MASK                                 0x01ffdbff
#define MAC_DCU_MISC_7_RSTMASK                                       0xffffffff
#define MAC_DCU_MISC_7_RESET                                         0x01000000

// 0x1120 (MAC_DCU_MISC_8)
#define MAC_DCU_MISC_8_SIFS_BURST_CHAN_BUSY_IGNORE_MSB               24
#define MAC_DCU_MISC_8_SIFS_BURST_CHAN_BUSY_IGNORE_LSB               24
#define MAC_DCU_MISC_8_SIFS_BURST_CHAN_BUSY_IGNORE_MASK              0x01000000
#define MAC_DCU_MISC_8_SIFS_BURST_CHAN_BUSY_IGNORE_GET(x)            (((x) & MAC_DCU_MISC_8_SIFS_BURST_CHAN_BUSY_IGNORE_MASK) >> MAC_DCU_MISC_8_SIFS_BURST_CHAN_BUSY_IGNORE_LSB)
#define MAC_DCU_MISC_8_SIFS_BURST_CHAN_BUSY_IGNORE_SET(x)            (((0 | (x)) << MAC_DCU_MISC_8_SIFS_BURST_CHAN_BUSY_IGNORE_LSB) & MAC_DCU_MISC_8_SIFS_BURST_CHAN_BUSY_IGNORE_MASK)
#define MAC_DCU_MISC_8_SIFS_BURST_CHAN_BUSY_IGNORE_RESET             1
#define MAC_DCU_MISC_8_RETRY_ON_BLOWN_IFS_EN_MSB                     23
#define MAC_DCU_MISC_8_RETRY_ON_BLOWN_IFS_EN_LSB                     23
#define MAC_DCU_MISC_8_RETRY_ON_BLOWN_IFS_EN_MASK                    0x00800000
#define MAC_DCU_MISC_8_RETRY_ON_BLOWN_IFS_EN_GET(x)                  (((x) & MAC_DCU_MISC_8_RETRY_ON_BLOWN_IFS_EN_MASK) >> MAC_DCU_MISC_8_RETRY_ON_BLOWN_IFS_EN_LSB)
#define MAC_DCU_MISC_8_RETRY_ON_BLOWN_IFS_EN_SET(x)                  (((0 | (x)) << MAC_DCU_MISC_8_RETRY_ON_BLOWN_IFS_EN_LSB) & MAC_DCU_MISC_8_RETRY_ON_BLOWN_IFS_EN_MASK)
#define MAC_DCU_MISC_8_RETRY_ON_BLOWN_IFS_EN_RESET                   0
#define MAC_DCU_MISC_8_VIRT_COLL_CW_INC_EN_MSB                       22
#define MAC_DCU_MISC_8_VIRT_COLL_CW_INC_EN_LSB                       22
#define MAC_DCU_MISC_8_VIRT_COLL_CW_INC_EN_MASK                      0x00400000
#define MAC_DCU_MISC_8_VIRT_COLL_CW_INC_EN_GET(x)                    (((x) & MAC_DCU_MISC_8_VIRT_COLL_CW_INC_EN_MASK) >> MAC_DCU_MISC_8_VIRT_COLL_CW_INC_EN_LSB)
#define MAC_DCU_MISC_8_VIRT_COLL_CW_INC_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_8_VIRT_COLL_CW_INC_EN_LSB) & MAC_DCU_MISC_8_VIRT_COLL_CW_INC_EN_MASK)
#define MAC_DCU_MISC_8_VIRT_COLL_CW_INC_EN_RESET                     0
#define MAC_DCU_MISC_8_POST_BKOFF_SKIP_MSB                           21
#define MAC_DCU_MISC_8_POST_BKOFF_SKIP_LSB                           21
#define MAC_DCU_MISC_8_POST_BKOFF_SKIP_MASK                          0x00200000
#define MAC_DCU_MISC_8_POST_BKOFF_SKIP_GET(x)                        (((x) & MAC_DCU_MISC_8_POST_BKOFF_SKIP_MASK) >> MAC_DCU_MISC_8_POST_BKOFF_SKIP_LSB)
#define MAC_DCU_MISC_8_POST_BKOFF_SKIP_SET(x)                        (((0 | (x)) << MAC_DCU_MISC_8_POST_BKOFF_SKIP_LSB) & MAC_DCU_MISC_8_POST_BKOFF_SKIP_MASK)
#define MAC_DCU_MISC_8_POST_BKOFF_SKIP_RESET                         0
#define MAC_DCU_MISC_8_SEQNUM_FREEZE_MSB                             20
#define MAC_DCU_MISC_8_SEQNUM_FREEZE_LSB                             20
#define MAC_DCU_MISC_8_SEQNUM_FREEZE_MASK                            0x00100000
#define MAC_DCU_MISC_8_SEQNUM_FREEZE_GET(x)                          (((x) & MAC_DCU_MISC_8_SEQNUM_FREEZE_MASK) >> MAC_DCU_MISC_8_SEQNUM_FREEZE_LSB)
#define MAC_DCU_MISC_8_SEQNUM_FREEZE_SET(x)                          (((0 | (x)) << MAC_DCU_MISC_8_SEQNUM_FREEZE_LSB) & MAC_DCU_MISC_8_SEQNUM_FREEZE_MASK)
#define MAC_DCU_MISC_8_SEQNUM_FREEZE_RESET                           0
#define MAC_DCU_MISC_8_LOCKOUT_IGNORE_MSB                            19
#define MAC_DCU_MISC_8_LOCKOUT_IGNORE_LSB                            19
#define MAC_DCU_MISC_8_LOCKOUT_IGNORE_MASK                           0x00080000
#define MAC_DCU_MISC_8_LOCKOUT_IGNORE_GET(x)                         (((x) & MAC_DCU_MISC_8_LOCKOUT_IGNORE_MASK) >> MAC_DCU_MISC_8_LOCKOUT_IGNORE_LSB)
#define MAC_DCU_MISC_8_LOCKOUT_IGNORE_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_8_LOCKOUT_IGNORE_LSB) & MAC_DCU_MISC_8_LOCKOUT_IGNORE_MASK)
#define MAC_DCU_MISC_8_LOCKOUT_IGNORE_RESET                          0
#define MAC_DCU_MISC_8_LOCKOUT_GBL_EN_MSB                            18
#define MAC_DCU_MISC_8_LOCKOUT_GBL_EN_LSB                            18
#define MAC_DCU_MISC_8_LOCKOUT_GBL_EN_MASK                           0x00040000
#define MAC_DCU_MISC_8_LOCKOUT_GBL_EN_GET(x)                         (((x) & MAC_DCU_MISC_8_LOCKOUT_GBL_EN_MASK) >> MAC_DCU_MISC_8_LOCKOUT_GBL_EN_LSB)
#define MAC_DCU_MISC_8_LOCKOUT_GBL_EN_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_8_LOCKOUT_GBL_EN_LSB) & MAC_DCU_MISC_8_LOCKOUT_GBL_EN_MASK)
#define MAC_DCU_MISC_8_LOCKOUT_GBL_EN_RESET                          0
#define MAC_DCU_MISC_8_ARB_LOCKOUT_IF_EN_MSB                         17
#define MAC_DCU_MISC_8_ARB_LOCKOUT_IF_EN_LSB                         17
#define MAC_DCU_MISC_8_ARB_LOCKOUT_IF_EN_MASK                        0x00020000
#define MAC_DCU_MISC_8_ARB_LOCKOUT_IF_EN_GET(x)                      (((x) & MAC_DCU_MISC_8_ARB_LOCKOUT_IF_EN_MASK) >> MAC_DCU_MISC_8_ARB_LOCKOUT_IF_EN_LSB)
#define MAC_DCU_MISC_8_ARB_LOCKOUT_IF_EN_SET(x)                      (((0 | (x)) << MAC_DCU_MISC_8_ARB_LOCKOUT_IF_EN_LSB) & MAC_DCU_MISC_8_ARB_LOCKOUT_IF_EN_MASK)
#define MAC_DCU_MISC_8_ARB_LOCKOUT_IF_EN_RESET                       0
#define MAC_DCU_MISC_8_IS_BCN_MSB                                    16
#define MAC_DCU_MISC_8_IS_BCN_LSB                                    16
#define MAC_DCU_MISC_8_IS_BCN_MASK                                   0x00010000
#define MAC_DCU_MISC_8_IS_BCN_GET(x)                                 (((x) & MAC_DCU_MISC_8_IS_BCN_MASK) >> MAC_DCU_MISC_8_IS_BCN_LSB)
#define MAC_DCU_MISC_8_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_DCU_MISC_8_IS_BCN_LSB) & MAC_DCU_MISC_8_IS_BCN_MASK)
#define MAC_DCU_MISC_8_IS_BCN_RESET                                  0
#define MAC_DCU_MISC_8_VIRT_COLL_POLICY_MSB                          15
#define MAC_DCU_MISC_8_VIRT_COLL_POLICY_LSB                          14
#define MAC_DCU_MISC_8_VIRT_COLL_POLICY_MASK                         0x0000c000
#define MAC_DCU_MISC_8_VIRT_COLL_POLICY_GET(x)                       (((x) & MAC_DCU_MISC_8_VIRT_COLL_POLICY_MASK) >> MAC_DCU_MISC_8_VIRT_COLL_POLICY_LSB)
#define MAC_DCU_MISC_8_VIRT_COLL_POLICY_SET(x)                       (((0 | (x)) << MAC_DCU_MISC_8_VIRT_COLL_POLICY_LSB) & MAC_DCU_MISC_8_VIRT_COLL_POLICY_MASK)
#define MAC_DCU_MISC_8_VIRT_COLL_POLICY_RESET                        0
#define MAC_DCU_MISC_8_BKOFF_PF_MSB                                  12
#define MAC_DCU_MISC_8_BKOFF_PF_LSB                                  12
#define MAC_DCU_MISC_8_BKOFF_PF_MASK                                 0x00001000
#define MAC_DCU_MISC_8_BKOFF_PF_GET(x)                               (((x) & MAC_DCU_MISC_8_BKOFF_PF_MASK) >> MAC_DCU_MISC_8_BKOFF_PF_LSB)
#define MAC_DCU_MISC_8_BKOFF_PF_SET(x)                               (((0 | (x)) << MAC_DCU_MISC_8_BKOFF_PF_LSB) & MAC_DCU_MISC_8_BKOFF_PF_MASK)
#define MAC_DCU_MISC_8_BKOFF_PF_RESET                                0
#define MAC_DCU_MISC_8_HCF_POLL_EN_MSB                               11
#define MAC_DCU_MISC_8_HCF_POLL_EN_LSB                               11
#define MAC_DCU_MISC_8_HCF_POLL_EN_MASK                              0x00000800
#define MAC_DCU_MISC_8_HCF_POLL_EN_GET(x)                            (((x) & MAC_DCU_MISC_8_HCF_POLL_EN_MASK) >> MAC_DCU_MISC_8_HCF_POLL_EN_LSB)
#define MAC_DCU_MISC_8_HCF_POLL_EN_SET(x)                            (((0 | (x)) << MAC_DCU_MISC_8_HCF_POLL_EN_LSB) & MAC_DCU_MISC_8_HCF_POLL_EN_MASK)
#define MAC_DCU_MISC_8_HCF_POLL_EN_RESET                             0
#define MAC_DCU_MISC_8_FRAG_BURST_BKOFF_EN_MSB                       9
#define MAC_DCU_MISC_8_FRAG_BURST_BKOFF_EN_LSB                       9
#define MAC_DCU_MISC_8_FRAG_BURST_BKOFF_EN_MASK                      0x00000200
#define MAC_DCU_MISC_8_FRAG_BURST_BKOFF_EN_GET(x)                    (((x) & MAC_DCU_MISC_8_FRAG_BURST_BKOFF_EN_MASK) >> MAC_DCU_MISC_8_FRAG_BURST_BKOFF_EN_LSB)
#define MAC_DCU_MISC_8_FRAG_BURST_BKOFF_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_8_FRAG_BURST_BKOFF_EN_LSB) & MAC_DCU_MISC_8_FRAG_BURST_BKOFF_EN_MASK)
#define MAC_DCU_MISC_8_FRAG_BURST_BKOFF_EN_RESET                     0
#define MAC_DCU_MISC_8_FRAG_BURST_WAIT_QCU_EN_MSB                    8
#define MAC_DCU_MISC_8_FRAG_BURST_WAIT_QCU_EN_LSB                    8
#define MAC_DCU_MISC_8_FRAG_BURST_WAIT_QCU_EN_MASK                   0x00000100
#define MAC_DCU_MISC_8_FRAG_BURST_WAIT_QCU_EN_GET(x)                 (((x) & MAC_DCU_MISC_8_FRAG_BURST_WAIT_QCU_EN_MASK) >> MAC_DCU_MISC_8_FRAG_BURST_WAIT_QCU_EN_LSB)
#define MAC_DCU_MISC_8_FRAG_BURST_WAIT_QCU_EN_SET(x)                 (((0 | (x)) << MAC_DCU_MISC_8_FRAG_BURST_WAIT_QCU_EN_LSB) & MAC_DCU_MISC_8_FRAG_BURST_WAIT_QCU_EN_MASK)
#define MAC_DCU_MISC_8_FRAG_BURST_WAIT_QCU_EN_RESET                  0
#define MAC_DCU_MISC_8_CW_RST_AT_TS_END_DIS_MSB                      7
#define MAC_DCU_MISC_8_CW_RST_AT_TS_END_DIS_LSB                      7
#define MAC_DCU_MISC_8_CW_RST_AT_TS_END_DIS_MASK                     0x00000080
#define MAC_DCU_MISC_8_CW_RST_AT_TS_END_DIS_GET(x)                   (((x) & MAC_DCU_MISC_8_CW_RST_AT_TS_END_DIS_MASK) >> MAC_DCU_MISC_8_CW_RST_AT_TS_END_DIS_LSB)
#define MAC_DCU_MISC_8_CW_RST_AT_TS_END_DIS_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_8_CW_RST_AT_TS_END_DIS_LSB) & MAC_DCU_MISC_8_CW_RST_AT_TS_END_DIS_MASK)
#define MAC_DCU_MISC_8_CW_RST_AT_TS_END_DIS_RESET                    0
#define MAC_DCU_MISC_8_SFC_RST_AT_TS_END_EN_MSB                      6
#define MAC_DCU_MISC_8_SFC_RST_AT_TS_END_EN_LSB                      6
#define MAC_DCU_MISC_8_SFC_RST_AT_TS_END_EN_MASK                     0x00000040
#define MAC_DCU_MISC_8_SFC_RST_AT_TS_END_EN_GET(x)                   (((x) & MAC_DCU_MISC_8_SFC_RST_AT_TS_END_EN_MASK) >> MAC_DCU_MISC_8_SFC_RST_AT_TS_END_EN_LSB)
#define MAC_DCU_MISC_8_SFC_RST_AT_TS_END_EN_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_8_SFC_RST_AT_TS_END_EN_LSB) & MAC_DCU_MISC_8_SFC_RST_AT_TS_END_EN_MASK)
#define MAC_DCU_MISC_8_SFC_RST_AT_TS_END_EN_RESET                    0
#define MAC_DCU_MISC_8_BKOFF_THRESH_MSB                              5
#define MAC_DCU_MISC_8_BKOFF_THRESH_LSB                              0
#define MAC_DCU_MISC_8_BKOFF_THRESH_MASK                             0x0000003f
#define MAC_DCU_MISC_8_BKOFF_THRESH_GET(x)                           (((x) & MAC_DCU_MISC_8_BKOFF_THRESH_MASK) >> MAC_DCU_MISC_8_BKOFF_THRESH_LSB)
#define MAC_DCU_MISC_8_BKOFF_THRESH_SET(x)                           (((0 | (x)) << MAC_DCU_MISC_8_BKOFF_THRESH_LSB) & MAC_DCU_MISC_8_BKOFF_THRESH_MASK)
#define MAC_DCU_MISC_8_BKOFF_THRESH_RESET                            0
#define MAC_DCU_MISC_8_ADDRESS                                       0x1120
#define MAC_DCU_MISC_8_HW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_8_SW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_8_HW_WRITE_MASK                                 0x00000000
#define MAC_DCU_MISC_8_SW_WRITE_MASK                                 0x01ffdbff
#define MAC_DCU_MISC_8_RSTMASK                                       0xffffffff
#define MAC_DCU_MISC_8_RESET                                         0x01000000

// 0x1124 (MAC_DCU_MISC_9)
#define MAC_DCU_MISC_9_SIFS_BURST_CHAN_BUSY_IGNORE_MSB               24
#define MAC_DCU_MISC_9_SIFS_BURST_CHAN_BUSY_IGNORE_LSB               24
#define MAC_DCU_MISC_9_SIFS_BURST_CHAN_BUSY_IGNORE_MASK              0x01000000
#define MAC_DCU_MISC_9_SIFS_BURST_CHAN_BUSY_IGNORE_GET(x)            (((x) & MAC_DCU_MISC_9_SIFS_BURST_CHAN_BUSY_IGNORE_MASK) >> MAC_DCU_MISC_9_SIFS_BURST_CHAN_BUSY_IGNORE_LSB)
#define MAC_DCU_MISC_9_SIFS_BURST_CHAN_BUSY_IGNORE_SET(x)            (((0 | (x)) << MAC_DCU_MISC_9_SIFS_BURST_CHAN_BUSY_IGNORE_LSB) & MAC_DCU_MISC_9_SIFS_BURST_CHAN_BUSY_IGNORE_MASK)
#define MAC_DCU_MISC_9_SIFS_BURST_CHAN_BUSY_IGNORE_RESET             1
#define MAC_DCU_MISC_9_RETRY_ON_BLOWN_IFS_EN_MSB                     23
#define MAC_DCU_MISC_9_RETRY_ON_BLOWN_IFS_EN_LSB                     23
#define MAC_DCU_MISC_9_RETRY_ON_BLOWN_IFS_EN_MASK                    0x00800000
#define MAC_DCU_MISC_9_RETRY_ON_BLOWN_IFS_EN_GET(x)                  (((x) & MAC_DCU_MISC_9_RETRY_ON_BLOWN_IFS_EN_MASK) >> MAC_DCU_MISC_9_RETRY_ON_BLOWN_IFS_EN_LSB)
#define MAC_DCU_MISC_9_RETRY_ON_BLOWN_IFS_EN_SET(x)                  (((0 | (x)) << MAC_DCU_MISC_9_RETRY_ON_BLOWN_IFS_EN_LSB) & MAC_DCU_MISC_9_RETRY_ON_BLOWN_IFS_EN_MASK)
#define MAC_DCU_MISC_9_RETRY_ON_BLOWN_IFS_EN_RESET                   0
#define MAC_DCU_MISC_9_VIRT_COLL_CW_INC_EN_MSB                       22
#define MAC_DCU_MISC_9_VIRT_COLL_CW_INC_EN_LSB                       22
#define MAC_DCU_MISC_9_VIRT_COLL_CW_INC_EN_MASK                      0x00400000
#define MAC_DCU_MISC_9_VIRT_COLL_CW_INC_EN_GET(x)                    (((x) & MAC_DCU_MISC_9_VIRT_COLL_CW_INC_EN_MASK) >> MAC_DCU_MISC_9_VIRT_COLL_CW_INC_EN_LSB)
#define MAC_DCU_MISC_9_VIRT_COLL_CW_INC_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_9_VIRT_COLL_CW_INC_EN_LSB) & MAC_DCU_MISC_9_VIRT_COLL_CW_INC_EN_MASK)
#define MAC_DCU_MISC_9_VIRT_COLL_CW_INC_EN_RESET                     0
#define MAC_DCU_MISC_9_POST_BKOFF_SKIP_MSB                           21
#define MAC_DCU_MISC_9_POST_BKOFF_SKIP_LSB                           21
#define MAC_DCU_MISC_9_POST_BKOFF_SKIP_MASK                          0x00200000
#define MAC_DCU_MISC_9_POST_BKOFF_SKIP_GET(x)                        (((x) & MAC_DCU_MISC_9_POST_BKOFF_SKIP_MASK) >> MAC_DCU_MISC_9_POST_BKOFF_SKIP_LSB)
#define MAC_DCU_MISC_9_POST_BKOFF_SKIP_SET(x)                        (((0 | (x)) << MAC_DCU_MISC_9_POST_BKOFF_SKIP_LSB) & MAC_DCU_MISC_9_POST_BKOFF_SKIP_MASK)
#define MAC_DCU_MISC_9_POST_BKOFF_SKIP_RESET                         0
#define MAC_DCU_MISC_9_SEQNUM_FREEZE_MSB                             20
#define MAC_DCU_MISC_9_SEQNUM_FREEZE_LSB                             20
#define MAC_DCU_MISC_9_SEQNUM_FREEZE_MASK                            0x00100000
#define MAC_DCU_MISC_9_SEQNUM_FREEZE_GET(x)                          (((x) & MAC_DCU_MISC_9_SEQNUM_FREEZE_MASK) >> MAC_DCU_MISC_9_SEQNUM_FREEZE_LSB)
#define MAC_DCU_MISC_9_SEQNUM_FREEZE_SET(x)                          (((0 | (x)) << MAC_DCU_MISC_9_SEQNUM_FREEZE_LSB) & MAC_DCU_MISC_9_SEQNUM_FREEZE_MASK)
#define MAC_DCU_MISC_9_SEQNUM_FREEZE_RESET                           0
#define MAC_DCU_MISC_9_LOCKOUT_IGNORE_MSB                            19
#define MAC_DCU_MISC_9_LOCKOUT_IGNORE_LSB                            19
#define MAC_DCU_MISC_9_LOCKOUT_IGNORE_MASK                           0x00080000
#define MAC_DCU_MISC_9_LOCKOUT_IGNORE_GET(x)                         (((x) & MAC_DCU_MISC_9_LOCKOUT_IGNORE_MASK) >> MAC_DCU_MISC_9_LOCKOUT_IGNORE_LSB)
#define MAC_DCU_MISC_9_LOCKOUT_IGNORE_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_9_LOCKOUT_IGNORE_LSB) & MAC_DCU_MISC_9_LOCKOUT_IGNORE_MASK)
#define MAC_DCU_MISC_9_LOCKOUT_IGNORE_RESET                          0
#define MAC_DCU_MISC_9_LOCKOUT_GBL_EN_MSB                            18
#define MAC_DCU_MISC_9_LOCKOUT_GBL_EN_LSB                            18
#define MAC_DCU_MISC_9_LOCKOUT_GBL_EN_MASK                           0x00040000
#define MAC_DCU_MISC_9_LOCKOUT_GBL_EN_GET(x)                         (((x) & MAC_DCU_MISC_9_LOCKOUT_GBL_EN_MASK) >> MAC_DCU_MISC_9_LOCKOUT_GBL_EN_LSB)
#define MAC_DCU_MISC_9_LOCKOUT_GBL_EN_SET(x)                         (((0 | (x)) << MAC_DCU_MISC_9_LOCKOUT_GBL_EN_LSB) & MAC_DCU_MISC_9_LOCKOUT_GBL_EN_MASK)
#define MAC_DCU_MISC_9_LOCKOUT_GBL_EN_RESET                          0
#define MAC_DCU_MISC_9_ARB_LOCKOUT_IF_EN_MSB                         17
#define MAC_DCU_MISC_9_ARB_LOCKOUT_IF_EN_LSB                         17
#define MAC_DCU_MISC_9_ARB_LOCKOUT_IF_EN_MASK                        0x00020000
#define MAC_DCU_MISC_9_ARB_LOCKOUT_IF_EN_GET(x)                      (((x) & MAC_DCU_MISC_9_ARB_LOCKOUT_IF_EN_MASK) >> MAC_DCU_MISC_9_ARB_LOCKOUT_IF_EN_LSB)
#define MAC_DCU_MISC_9_ARB_LOCKOUT_IF_EN_SET(x)                      (((0 | (x)) << MAC_DCU_MISC_9_ARB_LOCKOUT_IF_EN_LSB) & MAC_DCU_MISC_9_ARB_LOCKOUT_IF_EN_MASK)
#define MAC_DCU_MISC_9_ARB_LOCKOUT_IF_EN_RESET                       0
#define MAC_DCU_MISC_9_IS_BCN_MSB                                    16
#define MAC_DCU_MISC_9_IS_BCN_LSB                                    16
#define MAC_DCU_MISC_9_IS_BCN_MASK                                   0x00010000
#define MAC_DCU_MISC_9_IS_BCN_GET(x)                                 (((x) & MAC_DCU_MISC_9_IS_BCN_MASK) >> MAC_DCU_MISC_9_IS_BCN_LSB)
#define MAC_DCU_MISC_9_IS_BCN_SET(x)                                 (((0 | (x)) << MAC_DCU_MISC_9_IS_BCN_LSB) & MAC_DCU_MISC_9_IS_BCN_MASK)
#define MAC_DCU_MISC_9_IS_BCN_RESET                                  0
#define MAC_DCU_MISC_9_VIRT_COLL_POLICY_MSB                          15
#define MAC_DCU_MISC_9_VIRT_COLL_POLICY_LSB                          14
#define MAC_DCU_MISC_9_VIRT_COLL_POLICY_MASK                         0x0000c000
#define MAC_DCU_MISC_9_VIRT_COLL_POLICY_GET(x)                       (((x) & MAC_DCU_MISC_9_VIRT_COLL_POLICY_MASK) >> MAC_DCU_MISC_9_VIRT_COLL_POLICY_LSB)
#define MAC_DCU_MISC_9_VIRT_COLL_POLICY_SET(x)                       (((0 | (x)) << MAC_DCU_MISC_9_VIRT_COLL_POLICY_LSB) & MAC_DCU_MISC_9_VIRT_COLL_POLICY_MASK)
#define MAC_DCU_MISC_9_VIRT_COLL_POLICY_RESET                        0
#define MAC_DCU_MISC_9_BKOFF_PF_MSB                                  12
#define MAC_DCU_MISC_9_BKOFF_PF_LSB                                  12
#define MAC_DCU_MISC_9_BKOFF_PF_MASK                                 0x00001000
#define MAC_DCU_MISC_9_BKOFF_PF_GET(x)                               (((x) & MAC_DCU_MISC_9_BKOFF_PF_MASK) >> MAC_DCU_MISC_9_BKOFF_PF_LSB)
#define MAC_DCU_MISC_9_BKOFF_PF_SET(x)                               (((0 | (x)) << MAC_DCU_MISC_9_BKOFF_PF_LSB) & MAC_DCU_MISC_9_BKOFF_PF_MASK)
#define MAC_DCU_MISC_9_BKOFF_PF_RESET                                0
#define MAC_DCU_MISC_9_HCF_POLL_EN_MSB                               11
#define MAC_DCU_MISC_9_HCF_POLL_EN_LSB                               11
#define MAC_DCU_MISC_9_HCF_POLL_EN_MASK                              0x00000800
#define MAC_DCU_MISC_9_HCF_POLL_EN_GET(x)                            (((x) & MAC_DCU_MISC_9_HCF_POLL_EN_MASK) >> MAC_DCU_MISC_9_HCF_POLL_EN_LSB)
#define MAC_DCU_MISC_9_HCF_POLL_EN_SET(x)                            (((0 | (x)) << MAC_DCU_MISC_9_HCF_POLL_EN_LSB) & MAC_DCU_MISC_9_HCF_POLL_EN_MASK)
#define MAC_DCU_MISC_9_HCF_POLL_EN_RESET                             0
#define MAC_DCU_MISC_9_FRAG_BURST_BKOFF_EN_MSB                       9
#define MAC_DCU_MISC_9_FRAG_BURST_BKOFF_EN_LSB                       9
#define MAC_DCU_MISC_9_FRAG_BURST_BKOFF_EN_MASK                      0x00000200
#define MAC_DCU_MISC_9_FRAG_BURST_BKOFF_EN_GET(x)                    (((x) & MAC_DCU_MISC_9_FRAG_BURST_BKOFF_EN_MASK) >> MAC_DCU_MISC_9_FRAG_BURST_BKOFF_EN_LSB)
#define MAC_DCU_MISC_9_FRAG_BURST_BKOFF_EN_SET(x)                    (((0 | (x)) << MAC_DCU_MISC_9_FRAG_BURST_BKOFF_EN_LSB) & MAC_DCU_MISC_9_FRAG_BURST_BKOFF_EN_MASK)
#define MAC_DCU_MISC_9_FRAG_BURST_BKOFF_EN_RESET                     0
#define MAC_DCU_MISC_9_FRAG_BURST_WAIT_QCU_EN_MSB                    8
#define MAC_DCU_MISC_9_FRAG_BURST_WAIT_QCU_EN_LSB                    8
#define MAC_DCU_MISC_9_FRAG_BURST_WAIT_QCU_EN_MASK                   0x00000100
#define MAC_DCU_MISC_9_FRAG_BURST_WAIT_QCU_EN_GET(x)                 (((x) & MAC_DCU_MISC_9_FRAG_BURST_WAIT_QCU_EN_MASK) >> MAC_DCU_MISC_9_FRAG_BURST_WAIT_QCU_EN_LSB)
#define MAC_DCU_MISC_9_FRAG_BURST_WAIT_QCU_EN_SET(x)                 (((0 | (x)) << MAC_DCU_MISC_9_FRAG_BURST_WAIT_QCU_EN_LSB) & MAC_DCU_MISC_9_FRAG_BURST_WAIT_QCU_EN_MASK)
#define MAC_DCU_MISC_9_FRAG_BURST_WAIT_QCU_EN_RESET                  0
#define MAC_DCU_MISC_9_CW_RST_AT_TS_END_DIS_MSB                      7
#define MAC_DCU_MISC_9_CW_RST_AT_TS_END_DIS_LSB                      7
#define MAC_DCU_MISC_9_CW_RST_AT_TS_END_DIS_MASK                     0x00000080
#define MAC_DCU_MISC_9_CW_RST_AT_TS_END_DIS_GET(x)                   (((x) & MAC_DCU_MISC_9_CW_RST_AT_TS_END_DIS_MASK) >> MAC_DCU_MISC_9_CW_RST_AT_TS_END_DIS_LSB)
#define MAC_DCU_MISC_9_CW_RST_AT_TS_END_DIS_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_9_CW_RST_AT_TS_END_DIS_LSB) & MAC_DCU_MISC_9_CW_RST_AT_TS_END_DIS_MASK)
#define MAC_DCU_MISC_9_CW_RST_AT_TS_END_DIS_RESET                    0
#define MAC_DCU_MISC_9_SFC_RST_AT_TS_END_EN_MSB                      6
#define MAC_DCU_MISC_9_SFC_RST_AT_TS_END_EN_LSB                      6
#define MAC_DCU_MISC_9_SFC_RST_AT_TS_END_EN_MASK                     0x00000040
#define MAC_DCU_MISC_9_SFC_RST_AT_TS_END_EN_GET(x)                   (((x) & MAC_DCU_MISC_9_SFC_RST_AT_TS_END_EN_MASK) >> MAC_DCU_MISC_9_SFC_RST_AT_TS_END_EN_LSB)
#define MAC_DCU_MISC_9_SFC_RST_AT_TS_END_EN_SET(x)                   (((0 | (x)) << MAC_DCU_MISC_9_SFC_RST_AT_TS_END_EN_LSB) & MAC_DCU_MISC_9_SFC_RST_AT_TS_END_EN_MASK)
#define MAC_DCU_MISC_9_SFC_RST_AT_TS_END_EN_RESET                    0
#define MAC_DCU_MISC_9_BKOFF_THRESH_MSB                              5
#define MAC_DCU_MISC_9_BKOFF_THRESH_LSB                              0
#define MAC_DCU_MISC_9_BKOFF_THRESH_MASK                             0x0000003f
#define MAC_DCU_MISC_9_BKOFF_THRESH_GET(x)                           (((x) & MAC_DCU_MISC_9_BKOFF_THRESH_MASK) >> MAC_DCU_MISC_9_BKOFF_THRESH_LSB)
#define MAC_DCU_MISC_9_BKOFF_THRESH_SET(x)                           (((0 | (x)) << MAC_DCU_MISC_9_BKOFF_THRESH_LSB) & MAC_DCU_MISC_9_BKOFF_THRESH_MASK)
#define MAC_DCU_MISC_9_BKOFF_THRESH_RESET                            0
#define MAC_DCU_MISC_9_ADDRESS                                       0x1124
#define MAC_DCU_MISC_9_HW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_9_SW_MASK                                       0x01ffdbff
#define MAC_DCU_MISC_9_HW_WRITE_MASK                                 0x00000000
#define MAC_DCU_MISC_9_SW_WRITE_MASK                                 0x01ffdbff
#define MAC_DCU_MISC_9_RSTMASK                                       0xffffffff
#define MAC_DCU_MISC_9_RESET                                         0x01000000

// 0x1138 (MAC_DCU_TXFILTER_DCU1_31_0)
#define MAC_DCU_TXFILTER_DCU1_31_0_DATA_MSB                          31
#define MAC_DCU_TXFILTER_DCU1_31_0_DATA_LSB                          0
#define MAC_DCU_TXFILTER_DCU1_31_0_DATA_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU1_31_0_DATA_GET(x)                       (((x) & MAC_DCU_TXFILTER_DCU1_31_0_DATA_MASK) >> MAC_DCU_TXFILTER_DCU1_31_0_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU1_31_0_DATA_SET(x)                       (((0 | (x)) << MAC_DCU_TXFILTER_DCU1_31_0_DATA_LSB) & MAC_DCU_TXFILTER_DCU1_31_0_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU1_31_0_DATA_RESET                        0
#define MAC_DCU_TXFILTER_DCU1_31_0_ADDRESS                           0x1138
#define MAC_DCU_TXFILTER_DCU1_31_0_HW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU1_31_0_SW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU1_31_0_HW_WRITE_MASK                     0xffffffff
#define MAC_DCU_TXFILTER_DCU1_31_0_SW_WRITE_MASK                     0x00000000
#define MAC_DCU_TXFILTER_DCU1_31_0_RSTMASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU1_31_0_RESET                             0x00000000

// 0x113c (MAC_DCU_TXFILTER_DCU9_31_0)
#define MAC_DCU_TXFILTER_DCU9_31_0_DATA_MSB                          31
#define MAC_DCU_TXFILTER_DCU9_31_0_DATA_LSB                          0
#define MAC_DCU_TXFILTER_DCU9_31_0_DATA_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU9_31_0_DATA_GET(x)                       (((x) & MAC_DCU_TXFILTER_DCU9_31_0_DATA_MASK) >> MAC_DCU_TXFILTER_DCU9_31_0_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU9_31_0_DATA_SET(x)                       (((0 | (x)) << MAC_DCU_TXFILTER_DCU9_31_0_DATA_LSB) & MAC_DCU_TXFILTER_DCU9_31_0_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU9_31_0_DATA_RESET                        0
#define MAC_DCU_TXFILTER_DCU9_31_0_ADDRESS                           0x113c
#define MAC_DCU_TXFILTER_DCU9_31_0_HW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU9_31_0_SW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU9_31_0_HW_WRITE_MASK                     0xffffffff
#define MAC_DCU_TXFILTER_DCU9_31_0_SW_WRITE_MASK                     0x00000000
#define MAC_DCU_TXFILTER_DCU9_31_0_RSTMASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU9_31_0_RESET                             0x00000000

// 0x1140 (MAC_DCU_SEQ)
#define MAC_DCU_SEQ_NUM_MSB                                          31
#define MAC_DCU_SEQ_NUM_LSB                                          0
#define MAC_DCU_SEQ_NUM_MASK                                         0xffffffff
#define MAC_DCU_SEQ_NUM_GET(x)                                       (((x) & MAC_DCU_SEQ_NUM_MASK) >> MAC_DCU_SEQ_NUM_LSB)
#define MAC_DCU_SEQ_NUM_SET(x)                                       (((0 | (x)) << MAC_DCU_SEQ_NUM_LSB) & MAC_DCU_SEQ_NUM_MASK)
#define MAC_DCU_SEQ_NUM_RESET                                        0
#define MAC_DCU_SEQ_ADDRESS                                          0x1140
#define MAC_DCU_SEQ_HW_MASK                                          0xffffffff
#define MAC_DCU_SEQ_SW_MASK                                          0xffffffff
#define MAC_DCU_SEQ_HW_WRITE_MASK                                    0x00000000
#define MAC_DCU_SEQ_SW_WRITE_MASK                                    0xffffffff
#define MAC_DCU_SEQ_RSTMASK                                          0xffffffff
#define MAC_DCU_SEQ_RESET                                            0x00000000

// 0x1178 (MAC_DCU_TXFILTER_DCU1_63_32)
#define MAC_DCU_TXFILTER_DCU1_63_32_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU1_63_32_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU1_63_32_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU1_63_32_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU1_63_32_DATA_MASK) >> MAC_DCU_TXFILTER_DCU1_63_32_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU1_63_32_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU1_63_32_DATA_LSB) & MAC_DCU_TXFILTER_DCU1_63_32_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU1_63_32_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU1_63_32_ADDRESS                          0x1178
#define MAC_DCU_TXFILTER_DCU1_63_32_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU1_63_32_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU1_63_32_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU1_63_32_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU1_63_32_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU1_63_32_RESET                            0x00000000

// 0x117c (MAC_DCU_TXFILTER_DCU9_63_32)
#define MAC_DCU_TXFILTER_DCU9_63_32_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU9_63_32_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU9_63_32_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU9_63_32_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU9_63_32_DATA_MASK) >> MAC_DCU_TXFILTER_DCU9_63_32_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU9_63_32_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU9_63_32_DATA_LSB) & MAC_DCU_TXFILTER_DCU9_63_32_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU9_63_32_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU9_63_32_ADDRESS                          0x117c
#define MAC_DCU_TXFILTER_DCU9_63_32_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU9_63_32_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU9_63_32_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU9_63_32_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU9_63_32_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU9_63_32_RESET                            0x00000000

// 0x11b8 (MAC_DCU_TXFILTER_DCU1_95_64)
#define MAC_DCU_TXFILTER_DCU1_95_64_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU1_95_64_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU1_95_64_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU1_95_64_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU1_95_64_DATA_MASK) >> MAC_DCU_TXFILTER_DCU1_95_64_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU1_95_64_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU1_95_64_DATA_LSB) & MAC_DCU_TXFILTER_DCU1_95_64_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU1_95_64_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU1_95_64_ADDRESS                          0x11b8
#define MAC_DCU_TXFILTER_DCU1_95_64_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU1_95_64_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU1_95_64_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU1_95_64_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU1_95_64_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU1_95_64_RESET                            0x00000000

// 0x11bc (MAC_DCU_TXFILTER_DCU9_95_64)
#define MAC_DCU_TXFILTER_DCU9_95_64_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU9_95_64_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU9_95_64_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU9_95_64_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU9_95_64_DATA_MASK) >> MAC_DCU_TXFILTER_DCU9_95_64_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU9_95_64_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU9_95_64_DATA_LSB) & MAC_DCU_TXFILTER_DCU9_95_64_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU9_95_64_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU9_95_64_ADDRESS                          0x11bc
#define MAC_DCU_TXFILTER_DCU9_95_64_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU9_95_64_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU9_95_64_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU9_95_64_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU9_95_64_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU9_95_64_RESET                            0x00000000

// 0x11f8 (MAC_DCU_TXFILTER_DCU1_127_96)
#define MAC_DCU_TXFILTER_DCU1_127_96_DATA_MSB                        31
#define MAC_DCU_TXFILTER_DCU1_127_96_DATA_LSB                        0
#define MAC_DCU_TXFILTER_DCU1_127_96_DATA_MASK                       0xffffffff
#define MAC_DCU_TXFILTER_DCU1_127_96_DATA_GET(x)                     (((x) & MAC_DCU_TXFILTER_DCU1_127_96_DATA_MASK) >> MAC_DCU_TXFILTER_DCU1_127_96_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU1_127_96_DATA_SET(x)                     (((0 | (x)) << MAC_DCU_TXFILTER_DCU1_127_96_DATA_LSB) & MAC_DCU_TXFILTER_DCU1_127_96_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU1_127_96_DATA_RESET                      0
#define MAC_DCU_TXFILTER_DCU1_127_96_ADDRESS                         0x11f8
#define MAC_DCU_TXFILTER_DCU1_127_96_HW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU1_127_96_SW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU1_127_96_HW_WRITE_MASK                   0xffffffff
#define MAC_DCU_TXFILTER_DCU1_127_96_SW_WRITE_MASK                   0x00000000
#define MAC_DCU_TXFILTER_DCU1_127_96_RSTMASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU1_127_96_RESET                           0x00000000

// 0x11fc (MAC_DCU_TXFILTER_DCU9_127_96)
#define MAC_DCU_TXFILTER_DCU9_127_96_DATA_MSB                        31
#define MAC_DCU_TXFILTER_DCU9_127_96_DATA_LSB                        0
#define MAC_DCU_TXFILTER_DCU9_127_96_DATA_MASK                       0xffffffff
#define MAC_DCU_TXFILTER_DCU9_127_96_DATA_GET(x)                     (((x) & MAC_DCU_TXFILTER_DCU9_127_96_DATA_MASK) >> MAC_DCU_TXFILTER_DCU9_127_96_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU9_127_96_DATA_SET(x)                     (((0 | (x)) << MAC_DCU_TXFILTER_DCU9_127_96_DATA_LSB) & MAC_DCU_TXFILTER_DCU9_127_96_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU9_127_96_DATA_RESET                      0
#define MAC_DCU_TXFILTER_DCU9_127_96_ADDRESS                         0x11fc
#define MAC_DCU_TXFILTER_DCU9_127_96_HW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU9_127_96_SW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU9_127_96_HW_WRITE_MASK                   0xffffffff
#define MAC_DCU_TXFILTER_DCU9_127_96_SW_WRITE_MASK                   0x00000000
#define MAC_DCU_TXFILTER_DCU9_127_96_RSTMASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU9_127_96_RESET                           0x00000000

// 0x1238 (MAC_DCU_TXFILTER_DCU2_31_0)
#define MAC_DCU_TXFILTER_DCU2_31_0_DATA_MSB                          31
#define MAC_DCU_TXFILTER_DCU2_31_0_DATA_LSB                          0
#define MAC_DCU_TXFILTER_DCU2_31_0_DATA_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU2_31_0_DATA_GET(x)                       (((x) & MAC_DCU_TXFILTER_DCU2_31_0_DATA_MASK) >> MAC_DCU_TXFILTER_DCU2_31_0_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU2_31_0_DATA_SET(x)                       (((0 | (x)) << MAC_DCU_TXFILTER_DCU2_31_0_DATA_LSB) & MAC_DCU_TXFILTER_DCU2_31_0_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU2_31_0_DATA_RESET                        0
#define MAC_DCU_TXFILTER_DCU2_31_0_ADDRESS                           0x1238
#define MAC_DCU_TXFILTER_DCU2_31_0_HW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU2_31_0_SW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU2_31_0_HW_WRITE_MASK                     0xffffffff
#define MAC_DCU_TXFILTER_DCU2_31_0_SW_WRITE_MASK                     0x00000000
#define MAC_DCU_TXFILTER_DCU2_31_0_RSTMASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU2_31_0_RESET                             0x00000000

// 0x1270 (MAC_DCU_PAUSE)
#define MAC_DCU_PAUSE_STATUS_MSB                                     16
#define MAC_DCU_PAUSE_STATUS_LSB                                     16
#define MAC_DCU_PAUSE_STATUS_MASK                                    0x00010000
#define MAC_DCU_PAUSE_STATUS_GET(x)                                  (((x) & MAC_DCU_PAUSE_STATUS_MASK) >> MAC_DCU_PAUSE_STATUS_LSB)
#define MAC_DCU_PAUSE_STATUS_SET(x)                                  (((0 | (x)) << MAC_DCU_PAUSE_STATUS_LSB) & MAC_DCU_PAUSE_STATUS_MASK)
#define MAC_DCU_PAUSE_STATUS_RESET                                   1
#define MAC_DCU_PAUSE_REQUEST_MSB                                    9
#define MAC_DCU_PAUSE_REQUEST_LSB                                    0
#define MAC_DCU_PAUSE_REQUEST_MASK                                   0x000003ff
#define MAC_DCU_PAUSE_REQUEST_GET(x)                                 (((x) & MAC_DCU_PAUSE_REQUEST_MASK) >> MAC_DCU_PAUSE_REQUEST_LSB)
#define MAC_DCU_PAUSE_REQUEST_SET(x)                                 (((0 | (x)) << MAC_DCU_PAUSE_REQUEST_LSB) & MAC_DCU_PAUSE_REQUEST_MASK)
#define MAC_DCU_PAUSE_REQUEST_RESET                                  0
#define MAC_DCU_PAUSE_ADDRESS                                        0x1270
#define MAC_DCU_PAUSE_HW_MASK                                        0x000103ff
#define MAC_DCU_PAUSE_SW_MASK                                        0x000103ff
#define MAC_DCU_PAUSE_HW_WRITE_MASK                                  0x00010000
#define MAC_DCU_PAUSE_SW_WRITE_MASK                                  0x000003ff
#define MAC_DCU_PAUSE_RSTMASK                                        0xffffffff
#define MAC_DCU_PAUSE_RESET                                          0x00010000

// 0x1278 (MAC_DCU_TXFILTER_DCU2_63_32)
#define MAC_DCU_TXFILTER_DCU2_63_32_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU2_63_32_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU2_63_32_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU2_63_32_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU2_63_32_DATA_MASK) >> MAC_DCU_TXFILTER_DCU2_63_32_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU2_63_32_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU2_63_32_DATA_LSB) & MAC_DCU_TXFILTER_DCU2_63_32_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU2_63_32_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU2_63_32_ADDRESS                          0x1278
#define MAC_DCU_TXFILTER_DCU2_63_32_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU2_63_32_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU2_63_32_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU2_63_32_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU2_63_32_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU2_63_32_RESET                            0x00000000

// 0x12b0 (MAC_DCU_WOW_KACFG)
#define MAC_DCU_WOW_KACFG_RX_TIMEOUT_CNT_MSB                         23
#define MAC_DCU_WOW_KACFG_RX_TIMEOUT_CNT_LSB                         12
#define MAC_DCU_WOW_KACFG_RX_TIMEOUT_CNT_MASK                        0x00fff000
#define MAC_DCU_WOW_KACFG_RX_TIMEOUT_CNT_GET(x)                      (((x) & MAC_DCU_WOW_KACFG_RX_TIMEOUT_CNT_MASK) >> MAC_DCU_WOW_KACFG_RX_TIMEOUT_CNT_LSB)
#define MAC_DCU_WOW_KACFG_RX_TIMEOUT_CNT_SET(x)                      (((0 | (x)) << MAC_DCU_WOW_KACFG_RX_TIMEOUT_CNT_LSB) & MAC_DCU_WOW_KACFG_RX_TIMEOUT_CNT_MASK)
#define MAC_DCU_WOW_KACFG_RX_TIMEOUT_CNT_RESET                       0
#define MAC_DCU_WOW_KACFG_BCN_CNT_MSB                                11
#define MAC_DCU_WOW_KACFG_BCN_CNT_LSB                                4
#define MAC_DCU_WOW_KACFG_BCN_CNT_MASK                               0x00000ff0
#define MAC_DCU_WOW_KACFG_BCN_CNT_GET(x)                             (((x) & MAC_DCU_WOW_KACFG_BCN_CNT_MASK) >> MAC_DCU_WOW_KACFG_BCN_CNT_LSB)
#define MAC_DCU_WOW_KACFG_BCN_CNT_SET(x)                             (((0 | (x)) << MAC_DCU_WOW_KACFG_BCN_CNT_LSB) & MAC_DCU_WOW_KACFG_BCN_CNT_MASK)
#define MAC_DCU_WOW_KACFG_BCN_CNT_RESET                              0
#define MAC_DCU_WOW_KACFG_TIM_EN_MSB                                 1
#define MAC_DCU_WOW_KACFG_TIM_EN_LSB                                 1
#define MAC_DCU_WOW_KACFG_TIM_EN_MASK                                0x00000002
#define MAC_DCU_WOW_KACFG_TIM_EN_GET(x)                              (((x) & MAC_DCU_WOW_KACFG_TIM_EN_MASK) >> MAC_DCU_WOW_KACFG_TIM_EN_LSB)
#define MAC_DCU_WOW_KACFG_TIM_EN_SET(x)                              (((0 | (x)) << MAC_DCU_WOW_KACFG_TIM_EN_LSB) & MAC_DCU_WOW_KACFG_TIM_EN_MASK)
#define MAC_DCU_WOW_KACFG_TIM_EN_RESET                               0
#define MAC_DCU_WOW_KACFG_TX_EN_MSB                                  0
#define MAC_DCU_WOW_KACFG_TX_EN_LSB                                  0
#define MAC_DCU_WOW_KACFG_TX_EN_MASK                                 0x00000001
#define MAC_DCU_WOW_KACFG_TX_EN_GET(x)                               (((x) & MAC_DCU_WOW_KACFG_TX_EN_MASK) >> MAC_DCU_WOW_KACFG_TX_EN_LSB)
#define MAC_DCU_WOW_KACFG_TX_EN_SET(x)                               (((0 | (x)) << MAC_DCU_WOW_KACFG_TX_EN_LSB) & MAC_DCU_WOW_KACFG_TX_EN_MASK)
#define MAC_DCU_WOW_KACFG_TX_EN_RESET                                0
#define MAC_DCU_WOW_KACFG_ADDRESS                                    0x12b0
#define MAC_DCU_WOW_KACFG_HW_MASK                                    0x00fffff3
#define MAC_DCU_WOW_KACFG_SW_MASK                                    0x00fffff3
#define MAC_DCU_WOW_KACFG_HW_WRITE_MASK                              0x00000000
#define MAC_DCU_WOW_KACFG_SW_WRITE_MASK                              0x00fffff3
#define MAC_DCU_WOW_KACFG_RSTMASK                                    0xffffffff
#define MAC_DCU_WOW_KACFG_RESET                                      0x00000000

// 0x12b8 (MAC_DCU_TXFILTER_DCU2_95_64)
#define MAC_DCU_TXFILTER_DCU2_95_64_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU2_95_64_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU2_95_64_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU2_95_64_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU2_95_64_DATA_MASK) >> MAC_DCU_TXFILTER_DCU2_95_64_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU2_95_64_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU2_95_64_DATA_LSB) & MAC_DCU_TXFILTER_DCU2_95_64_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU2_95_64_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU2_95_64_ADDRESS                          0x12b8
#define MAC_DCU_TXFILTER_DCU2_95_64_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU2_95_64_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU2_95_64_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU2_95_64_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU2_95_64_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU2_95_64_RESET                            0x00000000

// 0x12f0 (MAC_DCU_TXSLOT)
#define MAC_DCU_TXSLOT_MASK_MSB                                      15
#define MAC_DCU_TXSLOT_MASK_LSB                                      0
#define MAC_DCU_TXSLOT_MASK_MASK                                     0x0000ffff
#define MAC_DCU_TXSLOT_MASK_GET(x)                                   (((x) & MAC_DCU_TXSLOT_MASK_MASK) >> MAC_DCU_TXSLOT_MASK_LSB)
#define MAC_DCU_TXSLOT_MASK_SET(x)                                   (((0 | (x)) << MAC_DCU_TXSLOT_MASK_LSB) & MAC_DCU_TXSLOT_MASK_MASK)
#define MAC_DCU_TXSLOT_MASK_RESET                                    0
#define MAC_DCU_TXSLOT_ADDRESS                                       0x12f0
#define MAC_DCU_TXSLOT_HW_MASK                                       0x0000ffff
#define MAC_DCU_TXSLOT_SW_MASK                                       0x0000ffff
#define MAC_DCU_TXSLOT_HW_WRITE_MASK                                 0x00000000
#define MAC_DCU_TXSLOT_SW_WRITE_MASK                                 0x0000ffff
#define MAC_DCU_TXSLOT_RSTMASK                                       0xffffffff
#define MAC_DCU_TXSLOT_RESET                                         0x00000000

// 0x12f8 (MAC_DCU_TXFILTER_DCU2_127_96)
#define MAC_DCU_TXFILTER_DCU2_127_96_DATA_MSB                        31
#define MAC_DCU_TXFILTER_DCU2_127_96_DATA_LSB                        0
#define MAC_DCU_TXFILTER_DCU2_127_96_DATA_MASK                       0xffffffff
#define MAC_DCU_TXFILTER_DCU2_127_96_DATA_GET(x)                     (((x) & MAC_DCU_TXFILTER_DCU2_127_96_DATA_MASK) >> MAC_DCU_TXFILTER_DCU2_127_96_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU2_127_96_DATA_SET(x)                     (((0 | (x)) << MAC_DCU_TXFILTER_DCU2_127_96_DATA_LSB) & MAC_DCU_TXFILTER_DCU2_127_96_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU2_127_96_DATA_RESET                      0
#define MAC_DCU_TXFILTER_DCU2_127_96_ADDRESS                         0x12f8
#define MAC_DCU_TXFILTER_DCU2_127_96_HW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU2_127_96_SW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU2_127_96_HW_WRITE_MASK                   0xffffffff
#define MAC_DCU_TXFILTER_DCU2_127_96_SW_WRITE_MASK                   0x00000000
#define MAC_DCU_TXFILTER_DCU2_127_96_RSTMASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU2_127_96_RESET                           0x00000000

// 0x1338 (MAC_DCU_TXFILTER_DCU3_31_0)
#define MAC_DCU_TXFILTER_DCU3_31_0_DATA_MSB                          31
#define MAC_DCU_TXFILTER_DCU3_31_0_DATA_LSB                          0
#define MAC_DCU_TXFILTER_DCU3_31_0_DATA_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU3_31_0_DATA_GET(x)                       (((x) & MAC_DCU_TXFILTER_DCU3_31_0_DATA_MASK) >> MAC_DCU_TXFILTER_DCU3_31_0_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU3_31_0_DATA_SET(x)                       (((0 | (x)) << MAC_DCU_TXFILTER_DCU3_31_0_DATA_LSB) & MAC_DCU_TXFILTER_DCU3_31_0_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU3_31_0_DATA_RESET                        0
#define MAC_DCU_TXFILTER_DCU3_31_0_ADDRESS                           0x1338
#define MAC_DCU_TXFILTER_DCU3_31_0_HW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU3_31_0_SW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU3_31_0_HW_WRITE_MASK                     0xffffffff
#define MAC_DCU_TXFILTER_DCU3_31_0_SW_WRITE_MASK                     0x00000000
#define MAC_DCU_TXFILTER_DCU3_31_0_RSTMASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU3_31_0_RESET                             0x00000000

// 0x1378 (MAC_DCU_TXFILTER_DCU3_63_32)
#define MAC_DCU_TXFILTER_DCU3_63_32_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU3_63_32_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU3_63_32_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU3_63_32_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU3_63_32_DATA_MASK) >> MAC_DCU_TXFILTER_DCU3_63_32_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU3_63_32_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU3_63_32_DATA_LSB) & MAC_DCU_TXFILTER_DCU3_63_32_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU3_63_32_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU3_63_32_ADDRESS                          0x1378
#define MAC_DCU_TXFILTER_DCU3_63_32_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU3_63_32_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU3_63_32_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU3_63_32_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU3_63_32_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU3_63_32_RESET                            0x00000000

// 0x13b8 (MAC_DCU_TXFILTER_DCU3_95_64)
#define MAC_DCU_TXFILTER_DCU3_95_64_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU3_95_64_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU3_95_64_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU3_95_64_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU3_95_64_DATA_MASK) >> MAC_DCU_TXFILTER_DCU3_95_64_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU3_95_64_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU3_95_64_DATA_LSB) & MAC_DCU_TXFILTER_DCU3_95_64_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU3_95_64_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU3_95_64_ADDRESS                          0x13b8
#define MAC_DCU_TXFILTER_DCU3_95_64_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU3_95_64_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU3_95_64_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU3_95_64_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU3_95_64_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU3_95_64_RESET                            0x00000000

// 0x13f8 (MAC_DCU_TXFILTER_DCU3_127_96)
#define MAC_DCU_TXFILTER_DCU3_127_96_DATA_MSB                        31
#define MAC_DCU_TXFILTER_DCU3_127_96_DATA_LSB                        0
#define MAC_DCU_TXFILTER_DCU3_127_96_DATA_MASK                       0xffffffff
#define MAC_DCU_TXFILTER_DCU3_127_96_DATA_GET(x)                     (((x) & MAC_DCU_TXFILTER_DCU3_127_96_DATA_MASK) >> MAC_DCU_TXFILTER_DCU3_127_96_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU3_127_96_DATA_SET(x)                     (((0 | (x)) << MAC_DCU_TXFILTER_DCU3_127_96_DATA_LSB) & MAC_DCU_TXFILTER_DCU3_127_96_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU3_127_96_DATA_RESET                      0
#define MAC_DCU_TXFILTER_DCU3_127_96_ADDRESS                         0x13f8
#define MAC_DCU_TXFILTER_DCU3_127_96_HW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU3_127_96_SW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU3_127_96_HW_WRITE_MASK                   0xffffffff
#define MAC_DCU_TXFILTER_DCU3_127_96_SW_WRITE_MASK                   0x00000000
#define MAC_DCU_TXFILTER_DCU3_127_96_RSTMASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU3_127_96_RESET                           0x00000000

// 0x1438 (MAC_DCU_TXFILTER_DCU4_31_0)
#define MAC_DCU_TXFILTER_DCU4_31_0_DATA_MSB                          31
#define MAC_DCU_TXFILTER_DCU4_31_0_DATA_LSB                          0
#define MAC_DCU_TXFILTER_DCU4_31_0_DATA_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU4_31_0_DATA_GET(x)                       (((x) & MAC_DCU_TXFILTER_DCU4_31_0_DATA_MASK) >> MAC_DCU_TXFILTER_DCU4_31_0_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU4_31_0_DATA_SET(x)                       (((0 | (x)) << MAC_DCU_TXFILTER_DCU4_31_0_DATA_LSB) & MAC_DCU_TXFILTER_DCU4_31_0_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU4_31_0_DATA_RESET                        0
#define MAC_DCU_TXFILTER_DCU4_31_0_ADDRESS                           0x1438
#define MAC_DCU_TXFILTER_DCU4_31_0_HW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU4_31_0_SW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU4_31_0_HW_WRITE_MASK                     0xffffffff
#define MAC_DCU_TXFILTER_DCU4_31_0_SW_WRITE_MASK                     0x00000000
#define MAC_DCU_TXFILTER_DCU4_31_0_RSTMASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU4_31_0_RESET                             0x00000000

// 0x143c (MAC_DCU_TXFILTER_CLEAR)
#define MAC_DCU_TXFILTER_CLEAR_DATA_MSB                              31
#define MAC_DCU_TXFILTER_CLEAR_DATA_LSB                              0
#define MAC_DCU_TXFILTER_CLEAR_DATA_MASK                             0xffffffff
#define MAC_DCU_TXFILTER_CLEAR_DATA_GET(x)                           (((x) & MAC_DCU_TXFILTER_CLEAR_DATA_MASK) >> MAC_DCU_TXFILTER_CLEAR_DATA_LSB)
#define MAC_DCU_TXFILTER_CLEAR_DATA_SET(x)                           (((0 | (x)) << MAC_DCU_TXFILTER_CLEAR_DATA_LSB) & MAC_DCU_TXFILTER_CLEAR_DATA_MASK)
#define MAC_DCU_TXFILTER_CLEAR_DATA_RESET                            0
#define MAC_DCU_TXFILTER_CLEAR_ADDRESS                               0x143c
#define MAC_DCU_TXFILTER_CLEAR_HW_MASK                               0xffffffff
#define MAC_DCU_TXFILTER_CLEAR_SW_MASK                               0xffffffff
#define MAC_DCU_TXFILTER_CLEAR_HW_WRITE_MASK                         0x00000000
#define MAC_DCU_TXFILTER_CLEAR_SW_WRITE_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_CLEAR_RSTMASK                               0xffffffff
#define MAC_DCU_TXFILTER_CLEAR_RESET                                 0x00000000

// 0x1478 (MAC_DCU_TXFILTER_DCU4_63_32)
#define MAC_DCU_TXFILTER_DCU4_63_32_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU4_63_32_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU4_63_32_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU4_63_32_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU4_63_32_DATA_MASK) >> MAC_DCU_TXFILTER_DCU4_63_32_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU4_63_32_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU4_63_32_DATA_LSB) & MAC_DCU_TXFILTER_DCU4_63_32_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU4_63_32_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU4_63_32_ADDRESS                          0x1478
#define MAC_DCU_TXFILTER_DCU4_63_32_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU4_63_32_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU4_63_32_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU4_63_32_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU4_63_32_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU4_63_32_RESET                            0x00000000

// 0x147c (MAC_DCU_TXFILTER_SET)
#define MAC_DCU_TXFILTER_SET_DATA_MSB                                31
#define MAC_DCU_TXFILTER_SET_DATA_LSB                                0
#define MAC_DCU_TXFILTER_SET_DATA_MASK                               0xffffffff
#define MAC_DCU_TXFILTER_SET_DATA_GET(x)                             (((x) & MAC_DCU_TXFILTER_SET_DATA_MASK) >> MAC_DCU_TXFILTER_SET_DATA_LSB)
#define MAC_DCU_TXFILTER_SET_DATA_SET(x)                             (((0 | (x)) << MAC_DCU_TXFILTER_SET_DATA_LSB) & MAC_DCU_TXFILTER_SET_DATA_MASK)
#define MAC_DCU_TXFILTER_SET_DATA_RESET                              0
#define MAC_DCU_TXFILTER_SET_ADDRESS                                 0x147c
#define MAC_DCU_TXFILTER_SET_HW_MASK                                 0xffffffff
#define MAC_DCU_TXFILTER_SET_SW_MASK                                 0xffffffff
#define MAC_DCU_TXFILTER_SET_HW_WRITE_MASK                           0x00000000
#define MAC_DCU_TXFILTER_SET_SW_WRITE_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_SET_RSTMASK                                 0xffffffff
#define MAC_DCU_TXFILTER_SET_RESET                                   0x00000000

// 0x14b8 (MAC_DCU_TXFILTER_DCU4_95_64)
#define MAC_DCU_TXFILTER_DCU4_95_64_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU4_95_64_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU4_95_64_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU4_95_64_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU4_95_64_DATA_MASK) >> MAC_DCU_TXFILTER_DCU4_95_64_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU4_95_64_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU4_95_64_DATA_LSB) & MAC_DCU_TXFILTER_DCU4_95_64_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU4_95_64_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU4_95_64_ADDRESS                          0x14b8
#define MAC_DCU_TXFILTER_DCU4_95_64_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU4_95_64_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU4_95_64_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU4_95_64_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU4_95_64_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU4_95_64_RESET                            0x00000000

// 0x14f8 (MAC_DCU_TXFILTER_DCU4_127_96)
#define MAC_DCU_TXFILTER_DCU4_127_96_DATA_MSB                        31
#define MAC_DCU_TXFILTER_DCU4_127_96_DATA_LSB                        0
#define MAC_DCU_TXFILTER_DCU4_127_96_DATA_MASK                       0xffffffff
#define MAC_DCU_TXFILTER_DCU4_127_96_DATA_GET(x)                     (((x) & MAC_DCU_TXFILTER_DCU4_127_96_DATA_MASK) >> MAC_DCU_TXFILTER_DCU4_127_96_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU4_127_96_DATA_SET(x)                     (((0 | (x)) << MAC_DCU_TXFILTER_DCU4_127_96_DATA_LSB) & MAC_DCU_TXFILTER_DCU4_127_96_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU4_127_96_DATA_RESET                      0
#define MAC_DCU_TXFILTER_DCU4_127_96_ADDRESS                         0x14f8
#define MAC_DCU_TXFILTER_DCU4_127_96_HW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU4_127_96_SW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU4_127_96_HW_WRITE_MASK                   0xffffffff
#define MAC_DCU_TXFILTER_DCU4_127_96_SW_WRITE_MASK                   0x00000000
#define MAC_DCU_TXFILTER_DCU4_127_96_RSTMASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU4_127_96_RESET                           0x00000000

// 0x1538 (MAC_DCU_TXFILTER_DCU5_31_0)
#define MAC_DCU_TXFILTER_DCU5_31_0_DATA_MSB                          31
#define MAC_DCU_TXFILTER_DCU5_31_0_DATA_LSB                          0
#define MAC_DCU_TXFILTER_DCU5_31_0_DATA_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU5_31_0_DATA_GET(x)                       (((x) & MAC_DCU_TXFILTER_DCU5_31_0_DATA_MASK) >> MAC_DCU_TXFILTER_DCU5_31_0_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU5_31_0_DATA_SET(x)                       (((0 | (x)) << MAC_DCU_TXFILTER_DCU5_31_0_DATA_LSB) & MAC_DCU_TXFILTER_DCU5_31_0_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU5_31_0_DATA_RESET                        0
#define MAC_DCU_TXFILTER_DCU5_31_0_ADDRESS                           0x1538
#define MAC_DCU_TXFILTER_DCU5_31_0_HW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU5_31_0_SW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU5_31_0_HW_WRITE_MASK                     0xffffffff
#define MAC_DCU_TXFILTER_DCU5_31_0_SW_WRITE_MASK                     0x00000000
#define MAC_DCU_TXFILTER_DCU5_31_0_RSTMASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU5_31_0_RESET                             0x00000000

// 0x1578 (MAC_DCU_TXFILTER_DCU5_63_32)
#define MAC_DCU_TXFILTER_DCU5_63_32_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU5_63_32_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU5_63_32_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU5_63_32_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU5_63_32_DATA_MASK) >> MAC_DCU_TXFILTER_DCU5_63_32_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU5_63_32_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU5_63_32_DATA_LSB) & MAC_DCU_TXFILTER_DCU5_63_32_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU5_63_32_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU5_63_32_ADDRESS                          0x1578
#define MAC_DCU_TXFILTER_DCU5_63_32_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU5_63_32_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU5_63_32_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU5_63_32_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU5_63_32_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU5_63_32_RESET                            0x00000000

// 0x15b8 (MAC_DCU_TXFILTER_DCU5_95_64)
#define MAC_DCU_TXFILTER_DCU5_95_64_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU5_95_64_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU5_95_64_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU5_95_64_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU5_95_64_DATA_MASK) >> MAC_DCU_TXFILTER_DCU5_95_64_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU5_95_64_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU5_95_64_DATA_LSB) & MAC_DCU_TXFILTER_DCU5_95_64_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU5_95_64_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU5_95_64_ADDRESS                          0x15b8
#define MAC_DCU_TXFILTER_DCU5_95_64_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU5_95_64_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU5_95_64_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU5_95_64_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU5_95_64_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU5_95_64_RESET                            0x00000000

// 0x15f8 (MAC_DCU_TXFILTER_DCU5_127_96)
#define MAC_DCU_TXFILTER_DCU5_127_96_DATA_MSB                        31
#define MAC_DCU_TXFILTER_DCU5_127_96_DATA_LSB                        0
#define MAC_DCU_TXFILTER_DCU5_127_96_DATA_MASK                       0xffffffff
#define MAC_DCU_TXFILTER_DCU5_127_96_DATA_GET(x)                     (((x) & MAC_DCU_TXFILTER_DCU5_127_96_DATA_MASK) >> MAC_DCU_TXFILTER_DCU5_127_96_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU5_127_96_DATA_SET(x)                     (((0 | (x)) << MAC_DCU_TXFILTER_DCU5_127_96_DATA_LSB) & MAC_DCU_TXFILTER_DCU5_127_96_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU5_127_96_DATA_RESET                      0
#define MAC_DCU_TXFILTER_DCU5_127_96_ADDRESS                         0x15f8
#define MAC_DCU_TXFILTER_DCU5_127_96_HW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU5_127_96_SW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU5_127_96_HW_WRITE_MASK                   0xffffffff
#define MAC_DCU_TXFILTER_DCU5_127_96_SW_WRITE_MASK                   0x00000000
#define MAC_DCU_TXFILTER_DCU5_127_96_RSTMASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU5_127_96_RESET                           0x00000000

// 0x1638 (MAC_DCU_TXFILTER_DCU6_31_0)
#define MAC_DCU_TXFILTER_DCU6_31_0_DATA_MSB                          31
#define MAC_DCU_TXFILTER_DCU6_31_0_DATA_LSB                          0
#define MAC_DCU_TXFILTER_DCU6_31_0_DATA_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU6_31_0_DATA_GET(x)                       (((x) & MAC_DCU_TXFILTER_DCU6_31_0_DATA_MASK) >> MAC_DCU_TXFILTER_DCU6_31_0_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU6_31_0_DATA_SET(x)                       (((0 | (x)) << MAC_DCU_TXFILTER_DCU6_31_0_DATA_LSB) & MAC_DCU_TXFILTER_DCU6_31_0_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU6_31_0_DATA_RESET                        0
#define MAC_DCU_TXFILTER_DCU6_31_0_ADDRESS                           0x1638
#define MAC_DCU_TXFILTER_DCU6_31_0_HW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU6_31_0_SW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU6_31_0_HW_WRITE_MASK                     0xffffffff
#define MAC_DCU_TXFILTER_DCU6_31_0_SW_WRITE_MASK                     0x00000000
#define MAC_DCU_TXFILTER_DCU6_31_0_RSTMASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU6_31_0_RESET                             0x00000000

// 0x1678 (MAC_DCU_TXFILTER_DCU6_63_32)
#define MAC_DCU_TXFILTER_DCU6_63_32_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU6_63_32_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU6_63_32_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU6_63_32_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU6_63_32_DATA_MASK) >> MAC_DCU_TXFILTER_DCU6_63_32_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU6_63_32_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU6_63_32_DATA_LSB) & MAC_DCU_TXFILTER_DCU6_63_32_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU6_63_32_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU6_63_32_ADDRESS                          0x1678
#define MAC_DCU_TXFILTER_DCU6_63_32_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU6_63_32_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU6_63_32_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU6_63_32_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU6_63_32_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU6_63_32_RESET                            0x00000000

// 0x16b8 (MAC_DCU_TXFILTER_DCU6_95_64)
#define MAC_DCU_TXFILTER_DCU6_95_64_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU6_95_64_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU6_95_64_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU6_95_64_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU6_95_64_DATA_MASK) >> MAC_DCU_TXFILTER_DCU6_95_64_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU6_95_64_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU6_95_64_DATA_LSB) & MAC_DCU_TXFILTER_DCU6_95_64_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU6_95_64_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU6_95_64_ADDRESS                          0x16b8
#define MAC_DCU_TXFILTER_DCU6_95_64_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU6_95_64_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU6_95_64_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU6_95_64_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU6_95_64_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU6_95_64_RESET                            0x00000000

// 0x16f8 (MAC_DCU_TXFILTER_DCU6_127_96)
#define MAC_DCU_TXFILTER_DCU6_127_96_DATA_MSB                        31
#define MAC_DCU_TXFILTER_DCU6_127_96_DATA_LSB                        0
#define MAC_DCU_TXFILTER_DCU6_127_96_DATA_MASK                       0xffffffff
#define MAC_DCU_TXFILTER_DCU6_127_96_DATA_GET(x)                     (((x) & MAC_DCU_TXFILTER_DCU6_127_96_DATA_MASK) >> MAC_DCU_TXFILTER_DCU6_127_96_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU6_127_96_DATA_SET(x)                     (((0 | (x)) << MAC_DCU_TXFILTER_DCU6_127_96_DATA_LSB) & MAC_DCU_TXFILTER_DCU6_127_96_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU6_127_96_DATA_RESET                      0
#define MAC_DCU_TXFILTER_DCU6_127_96_ADDRESS                         0x16f8
#define MAC_DCU_TXFILTER_DCU6_127_96_HW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU6_127_96_SW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU6_127_96_HW_WRITE_MASK                   0xffffffff
#define MAC_DCU_TXFILTER_DCU6_127_96_SW_WRITE_MASK                   0x00000000
#define MAC_DCU_TXFILTER_DCU6_127_96_RSTMASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU6_127_96_RESET                           0x00000000

// 0x1738 (MAC_DCU_TXFILTER_DCU7_31_0)
#define MAC_DCU_TXFILTER_DCU7_31_0_DATA_MSB                          31
#define MAC_DCU_TXFILTER_DCU7_31_0_DATA_LSB                          0
#define MAC_DCU_TXFILTER_DCU7_31_0_DATA_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU7_31_0_DATA_GET(x)                       (((x) & MAC_DCU_TXFILTER_DCU7_31_0_DATA_MASK) >> MAC_DCU_TXFILTER_DCU7_31_0_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU7_31_0_DATA_SET(x)                       (((0 | (x)) << MAC_DCU_TXFILTER_DCU7_31_0_DATA_LSB) & MAC_DCU_TXFILTER_DCU7_31_0_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU7_31_0_DATA_RESET                        0
#define MAC_DCU_TXFILTER_DCU7_31_0_ADDRESS                           0x1738
#define MAC_DCU_TXFILTER_DCU7_31_0_HW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU7_31_0_SW_MASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU7_31_0_HW_WRITE_MASK                     0xffffffff
#define MAC_DCU_TXFILTER_DCU7_31_0_SW_WRITE_MASK                     0x00000000
#define MAC_DCU_TXFILTER_DCU7_31_0_RSTMASK                           0xffffffff
#define MAC_DCU_TXFILTER_DCU7_31_0_RESET                             0x00000000

// 0x1778 (MAC_DCU_TXFILTER_DCU7_63_32)
#define MAC_DCU_TXFILTER_DCU7_63_32_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU7_63_32_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU7_63_32_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU7_63_32_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU7_63_32_DATA_MASK) >> MAC_DCU_TXFILTER_DCU7_63_32_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU7_63_32_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU7_63_32_DATA_LSB) & MAC_DCU_TXFILTER_DCU7_63_32_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU7_63_32_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU7_63_32_ADDRESS                          0x1778
#define MAC_DCU_TXFILTER_DCU7_63_32_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU7_63_32_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU7_63_32_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU7_63_32_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU7_63_32_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU7_63_32_RESET                            0x00000000

// 0x17b8 (MAC_DCU_TXFILTER_DCU7_95_64)
#define MAC_DCU_TXFILTER_DCU7_95_64_DATA_MSB                         31
#define MAC_DCU_TXFILTER_DCU7_95_64_DATA_LSB                         0
#define MAC_DCU_TXFILTER_DCU7_95_64_DATA_MASK                        0xffffffff
#define MAC_DCU_TXFILTER_DCU7_95_64_DATA_GET(x)                      (((x) & MAC_DCU_TXFILTER_DCU7_95_64_DATA_MASK) >> MAC_DCU_TXFILTER_DCU7_95_64_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU7_95_64_DATA_SET(x)                      (((0 | (x)) << MAC_DCU_TXFILTER_DCU7_95_64_DATA_LSB) & MAC_DCU_TXFILTER_DCU7_95_64_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU7_95_64_DATA_RESET                       0
#define MAC_DCU_TXFILTER_DCU7_95_64_ADDRESS                          0x17b8
#define MAC_DCU_TXFILTER_DCU7_95_64_HW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU7_95_64_SW_MASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU7_95_64_HW_WRITE_MASK                    0xffffffff
#define MAC_DCU_TXFILTER_DCU7_95_64_SW_WRITE_MASK                    0x00000000
#define MAC_DCU_TXFILTER_DCU7_95_64_RSTMASK                          0xffffffff
#define MAC_DCU_TXFILTER_DCU7_95_64_RESET                            0x00000000

// 0x17f8 (MAC_DCU_TXFILTER_DCU7_127_96)
#define MAC_DCU_TXFILTER_DCU7_127_96_DATA_MSB                        31
#define MAC_DCU_TXFILTER_DCU7_127_96_DATA_LSB                        0
#define MAC_DCU_TXFILTER_DCU7_127_96_DATA_MASK                       0xffffffff
#define MAC_DCU_TXFILTER_DCU7_127_96_DATA_GET(x)                     (((x) & MAC_DCU_TXFILTER_DCU7_127_96_DATA_MASK) >> MAC_DCU_TXFILTER_DCU7_127_96_DATA_LSB)
#define MAC_DCU_TXFILTER_DCU7_127_96_DATA_SET(x)                     (((0 | (x)) << MAC_DCU_TXFILTER_DCU7_127_96_DATA_LSB) & MAC_DCU_TXFILTER_DCU7_127_96_DATA_MASK)
#define MAC_DCU_TXFILTER_DCU7_127_96_DATA_RESET                      0
#define MAC_DCU_TXFILTER_DCU7_127_96_ADDRESS                         0x17f8
#define MAC_DCU_TXFILTER_DCU7_127_96_HW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU7_127_96_SW_MASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU7_127_96_HW_WRITE_MASK                   0xffffffff
#define MAC_DCU_TXFILTER_DCU7_127_96_SW_WRITE_MASK                   0x00000000
#define MAC_DCU_TXFILTER_DCU7_127_96_RSTMASK                         0xffffffff
#define MAC_DCU_TXFILTER_DCU7_127_96_RESET                           0x00000000


#endif /* _MAC_DCU_REG_H_ */
