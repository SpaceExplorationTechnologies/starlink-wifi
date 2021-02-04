//                                                                             
// File:       ./bt_coex_reg.vrh                                               
// Creator:    jhou                                                            
// Time:       Wednesday Oct 3, 2012 [2:15:48 pm]                              
//                                                                             
// Path:       /trees/jhou/jhou-dev/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/jhou/jhou-dev/chips/peregrine/2.0/blueprint/sysconfig    
//             bt_coex_reg.rdl                                                 
//                                                                             
// Sources:    /trees/jhou/jhou-dev/chips/peregrine/2.0/ip/athr/wifi/rtl/mac/rtl/dev/bt_coex/blueprint/bt_coex_reg.rdl
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


#ifndef _BT_COEX_REG_H_
#define _BT_COEX_REG_H_
// 0x0000 (WLAN_INT_STATUS)
#define WLAN_INT_STATUS_BTCOEX_MSB                                   0
#define WLAN_INT_STATUS_BTCOEX_LSB                                   0
#define WLAN_INT_STATUS_BTCOEX_MASK                                  0x00000001
#define WLAN_INT_STATUS_BTCOEX_GET(x)                                (((x) & WLAN_INT_STATUS_BTCOEX_MASK) >> WLAN_INT_STATUS_BTCOEX_LSB)
#define WLAN_INT_STATUS_BTCOEX_SET(x)                                (((0 | (x)) << WLAN_INT_STATUS_BTCOEX_LSB) & WLAN_INT_STATUS_BTCOEX_MASK)
#define WLAN_INT_STATUS_BTCOEX_RESET                                 0
#define WLAN_INT_STATUS_ADDRESS                                      0x0000
#define WLAN_INT_STATUS_HW_MASK                                      0x00000001
#define WLAN_INT_STATUS_SW_MASK                                      0x00000001
#define WLAN_INT_STATUS_HW_WRITE_MASK                                0x00000001
#define WLAN_INT_STATUS_SW_WRITE_MASK                                0x00000000
#define WLAN_INT_STATUS_RSTMASK                                      0xffffffff
#define WLAN_INT_STATUS_RESET                                        0x00000000

// 0x0004 (BTCOEXCTRL)
#define BTCOEXCTRL_WBSYNC_ON_BEACON_MSB                              25
#define BTCOEXCTRL_WBSYNC_ON_BEACON_LSB                              25
#define BTCOEXCTRL_WBSYNC_ON_BEACON_MASK                             0x02000000
#define BTCOEXCTRL_WBSYNC_ON_BEACON_GET(x)                           (((x) & BTCOEXCTRL_WBSYNC_ON_BEACON_MASK) >> BTCOEXCTRL_WBSYNC_ON_BEACON_LSB)
#define BTCOEXCTRL_WBSYNC_ON_BEACON_SET(x)                           (((0 | (x)) << BTCOEXCTRL_WBSYNC_ON_BEACON_LSB) & BTCOEXCTRL_WBSYNC_ON_BEACON_MASK)
#define BTCOEXCTRL_WBSYNC_ON_BEACON_RESET                            0
#define BTCOEXCTRL_PTA_MODE_MSB                                      24
#define BTCOEXCTRL_PTA_MODE_LSB                                      23
#define BTCOEXCTRL_PTA_MODE_MASK                                     0x01800000
#define BTCOEXCTRL_PTA_MODE_GET(x)                                   (((x) & BTCOEXCTRL_PTA_MODE_MASK) >> BTCOEXCTRL_PTA_MODE_LSB)
#define BTCOEXCTRL_PTA_MODE_SET(x)                                   (((0 | (x)) << BTCOEXCTRL_PTA_MODE_LSB) & BTCOEXCTRL_PTA_MODE_MASK)
#define BTCOEXCTRL_PTA_MODE_RESET                                    0
#define BTCOEXCTRL_FREQ_TIME_MSB                                     22
#define BTCOEXCTRL_FREQ_TIME_LSB                                     18
#define BTCOEXCTRL_FREQ_TIME_MASK                                    0x007c0000
#define BTCOEXCTRL_FREQ_TIME_GET(x)                                  (((x) & BTCOEXCTRL_FREQ_TIME_MASK) >> BTCOEXCTRL_FREQ_TIME_LSB)
#define BTCOEXCTRL_FREQ_TIME_SET(x)                                  (((0 | (x)) << BTCOEXCTRL_FREQ_TIME_LSB) & BTCOEXCTRL_FREQ_TIME_MASK)
#define BTCOEXCTRL_FREQ_TIME_RESET                                   22
#define BTCOEXCTRL_PRIORITY_TIME_MSB                                 17
#define BTCOEXCTRL_PRIORITY_TIME_LSB                                 12
#define BTCOEXCTRL_PRIORITY_TIME_MASK                                0x0003f000
#define BTCOEXCTRL_PRIORITY_TIME_GET(x)                              (((x) & BTCOEXCTRL_PRIORITY_TIME_MASK) >> BTCOEXCTRL_PRIORITY_TIME_LSB)
#define BTCOEXCTRL_PRIORITY_TIME_SET(x)                              (((0 | (x)) << BTCOEXCTRL_PRIORITY_TIME_LSB) & BTCOEXCTRL_PRIORITY_TIME_MASK)
#define BTCOEXCTRL_PRIORITY_TIME_RESET                               36
#define BTCOEXCTRL_SYNC_DET_EN_MSB                                   11
#define BTCOEXCTRL_SYNC_DET_EN_LSB                                   11
#define BTCOEXCTRL_SYNC_DET_EN_MASK                                  0x00000800
#define BTCOEXCTRL_SYNC_DET_EN_GET(x)                                (((x) & BTCOEXCTRL_SYNC_DET_EN_MASK) >> BTCOEXCTRL_SYNC_DET_EN_LSB)
#define BTCOEXCTRL_SYNC_DET_EN_SET(x)                                (((0 | (x)) << BTCOEXCTRL_SYNC_DET_EN_LSB) & BTCOEXCTRL_SYNC_DET_EN_MASK)
#define BTCOEXCTRL_SYNC_DET_EN_RESET                                 0
#define BTCOEXCTRL_IDLE_CNT_EN_MSB                                   10
#define BTCOEXCTRL_IDLE_CNT_EN_LSB                                   10
#define BTCOEXCTRL_IDLE_CNT_EN_MASK                                  0x00000400
#define BTCOEXCTRL_IDLE_CNT_EN_GET(x)                                (((x) & BTCOEXCTRL_IDLE_CNT_EN_MASK) >> BTCOEXCTRL_IDLE_CNT_EN_LSB)
#define BTCOEXCTRL_IDLE_CNT_EN_SET(x)                                (((0 | (x)) << BTCOEXCTRL_IDLE_CNT_EN_LSB) & BTCOEXCTRL_IDLE_CNT_EN_MASK)
#define BTCOEXCTRL_IDLE_CNT_EN_RESET                                 0
#define BTCOEXCTRL_FRAME_CNT_EN_MSB                                  9
#define BTCOEXCTRL_FRAME_CNT_EN_LSB                                  9
#define BTCOEXCTRL_FRAME_CNT_EN_MASK                                 0x00000200
#define BTCOEXCTRL_FRAME_CNT_EN_GET(x)                               (((x) & BTCOEXCTRL_FRAME_CNT_EN_MASK) >> BTCOEXCTRL_FRAME_CNT_EN_LSB)
#define BTCOEXCTRL_FRAME_CNT_EN_SET(x)                               (((0 | (x)) << BTCOEXCTRL_FRAME_CNT_EN_LSB) & BTCOEXCTRL_FRAME_CNT_EN_MASK)
#define BTCOEXCTRL_FRAME_CNT_EN_RESET                                0
#define BTCOEXCTRL_CLK_CNT_EN_MSB                                    8
#define BTCOEXCTRL_CLK_CNT_EN_LSB                                    8
#define BTCOEXCTRL_CLK_CNT_EN_MASK                                   0x00000100
#define BTCOEXCTRL_CLK_CNT_EN_GET(x)                                 (((x) & BTCOEXCTRL_CLK_CNT_EN_MASK) >> BTCOEXCTRL_CLK_CNT_EN_LSB)
#define BTCOEXCTRL_CLK_CNT_EN_SET(x)                                 (((0 | (x)) << BTCOEXCTRL_CLK_CNT_EN_LSB) & BTCOEXCTRL_CLK_CNT_EN_MASK)
#define BTCOEXCTRL_CLK_CNT_EN_RESET                                  0
#define BTCOEXCTRL_GAP_MSB                                           7
#define BTCOEXCTRL_GAP_LSB                                           0
#define BTCOEXCTRL_GAP_MASK                                          0x000000ff
#define BTCOEXCTRL_GAP_GET(x)                                        (((x) & BTCOEXCTRL_GAP_MASK) >> BTCOEXCTRL_GAP_LSB)
#define BTCOEXCTRL_GAP_SET(x)                                        (((0 | (x)) << BTCOEXCTRL_GAP_LSB) & BTCOEXCTRL_GAP_MASK)
#define BTCOEXCTRL_GAP_RESET                                         0
#define BTCOEXCTRL_ADDRESS                                           0x0004
#define BTCOEXCTRL_HW_MASK                                           0x03ffffff
#define BTCOEXCTRL_SW_MASK                                           0x03ffffff
#define BTCOEXCTRL_HW_WRITE_MASK                                     0x00000000
#define BTCOEXCTRL_SW_WRITE_MASK                                     0x03ffffff
#define BTCOEXCTRL_RSTMASK                                           0xffffffff
#define BTCOEXCTRL_RESET                                             0x005a4000

// 0x0008 (WBSYNC_PRIORITY1)
#define WBSYNC_PRIORITY1_BITMAP_MSB                                  31
#define WBSYNC_PRIORITY1_BITMAP_LSB                                  0
#define WBSYNC_PRIORITY1_BITMAP_MASK                                 0xffffffff
#define WBSYNC_PRIORITY1_BITMAP_GET(x)                               (((x) & WBSYNC_PRIORITY1_BITMAP_MASK) >> WBSYNC_PRIORITY1_BITMAP_LSB)
#define WBSYNC_PRIORITY1_BITMAP_SET(x)                               (((0 | (x)) << WBSYNC_PRIORITY1_BITMAP_LSB) & WBSYNC_PRIORITY1_BITMAP_MASK)
#define WBSYNC_PRIORITY1_BITMAP_RESET                                0
#define WBSYNC_PRIORITY1_ADDRESS                                     0x0008
#define WBSYNC_PRIORITY1_HW_MASK                                     0xffffffff
#define WBSYNC_PRIORITY1_SW_MASK                                     0xffffffff
#define WBSYNC_PRIORITY1_HW_WRITE_MASK                               0x00000000
#define WBSYNC_PRIORITY1_SW_WRITE_MASK                               0xffffffff
#define WBSYNC_PRIORITY1_RSTMASK                                     0xffffffff
#define WBSYNC_PRIORITY1_RESET                                       0x00000000

// 0x000c (WBSYNC_PRIORITY2)
#define WBSYNC_PRIORITY2_BITMAP_MSB                                  31
#define WBSYNC_PRIORITY2_BITMAP_LSB                                  0
#define WBSYNC_PRIORITY2_BITMAP_MASK                                 0xffffffff
#define WBSYNC_PRIORITY2_BITMAP_GET(x)                               (((x) & WBSYNC_PRIORITY2_BITMAP_MASK) >> WBSYNC_PRIORITY2_BITMAP_LSB)
#define WBSYNC_PRIORITY2_BITMAP_SET(x)                               (((0 | (x)) << WBSYNC_PRIORITY2_BITMAP_LSB) & WBSYNC_PRIORITY2_BITMAP_MASK)
#define WBSYNC_PRIORITY2_BITMAP_RESET                                0
#define WBSYNC_PRIORITY2_ADDRESS                                     0x000c
#define WBSYNC_PRIORITY2_HW_MASK                                     0xffffffff
#define WBSYNC_PRIORITY2_SW_MASK                                     0xffffffff
#define WBSYNC_PRIORITY2_HW_WRITE_MASK                               0x00000000
#define WBSYNC_PRIORITY2_SW_WRITE_MASK                               0xffffffff
#define WBSYNC_PRIORITY2_RSTMASK                                     0xffffffff
#define WBSYNC_PRIORITY2_RESET                                       0x00000000

// 0x0010 (WBSYNC_PRIORITY3)
#define WBSYNC_PRIORITY3_BITMAP_MSB                                  31
#define WBSYNC_PRIORITY3_BITMAP_LSB                                  0
#define WBSYNC_PRIORITY3_BITMAP_MASK                                 0xffffffff
#define WBSYNC_PRIORITY3_BITMAP_GET(x)                               (((x) & WBSYNC_PRIORITY3_BITMAP_MASK) >> WBSYNC_PRIORITY3_BITMAP_LSB)
#define WBSYNC_PRIORITY3_BITMAP_SET(x)                               (((0 | (x)) << WBSYNC_PRIORITY3_BITMAP_LSB) & WBSYNC_PRIORITY3_BITMAP_MASK)
#define WBSYNC_PRIORITY3_BITMAP_RESET                                0
#define WBSYNC_PRIORITY3_ADDRESS                                     0x0010
#define WBSYNC_PRIORITY3_HW_MASK                                     0xffffffff
#define WBSYNC_PRIORITY3_SW_MASK                                     0xffffffff
#define WBSYNC_PRIORITY3_HW_WRITE_MASK                               0x00000000
#define WBSYNC_PRIORITY3_SW_WRITE_MASK                               0xffffffff
#define WBSYNC_PRIORITY3_RSTMASK                                     0xffffffff
#define WBSYNC_PRIORITY3_RESET                                       0x00000000

// 0x0014 (BTCOEX0)
#define BTCOEX0_SYNC_DUR_MSB                                         7
#define BTCOEX0_SYNC_DUR_LSB                                         0
#define BTCOEX0_SYNC_DUR_MASK                                        0x000000ff
#define BTCOEX0_SYNC_DUR_GET(x)                                      (((x) & BTCOEX0_SYNC_DUR_MASK) >> BTCOEX0_SYNC_DUR_LSB)
#define BTCOEX0_SYNC_DUR_SET(x)                                      (((0 | (x)) << BTCOEX0_SYNC_DUR_LSB) & BTCOEX0_SYNC_DUR_MASK)
#define BTCOEX0_SYNC_DUR_RESET                                       100
#define BTCOEX0_ADDRESS                                              0x0014
#define BTCOEX0_HW_MASK                                              0x000000ff
#define BTCOEX0_SW_MASK                                              0x000000ff
#define BTCOEX0_HW_WRITE_MASK                                        0x00000000
#define BTCOEX0_SW_WRITE_MASK                                        0x000000ff
#define BTCOEX0_RSTMASK                                              0xffffffff
#define BTCOEX0_RESET                                                0x00000064

// 0x0018 (BTCOEX1)
#define BTCOEX1_CLK_THRES_MSB                                        20
#define BTCOEX1_CLK_THRES_LSB                                        0
#define BTCOEX1_CLK_THRES_MASK                                       0x001fffff
#define BTCOEX1_CLK_THRES_GET(x)                                     (((x) & BTCOEX1_CLK_THRES_MASK) >> BTCOEX1_CLK_THRES_LSB)
#define BTCOEX1_CLK_THRES_SET(x)                                     (((0 | (x)) << BTCOEX1_CLK_THRES_LSB) & BTCOEX1_CLK_THRES_MASK)
#define BTCOEX1_CLK_THRES_RESET                                      2097151
#define BTCOEX1_ADDRESS                                              0x0018
#define BTCOEX1_HW_MASK                                              0x001fffff
#define BTCOEX1_SW_MASK                                              0x001fffff
#define BTCOEX1_HW_WRITE_MASK                                        0x00000000
#define BTCOEX1_SW_WRITE_MASK                                        0x001fffff
#define BTCOEX1_RSTMASK                                              0xffffffff
#define BTCOEX1_RESET                                                0x001fffff

// 0x001c (BTCOEX2)
#define BTCOEX2_FRAME_THRES_MSB                                      7
#define BTCOEX2_FRAME_THRES_LSB                                      0
#define BTCOEX2_FRAME_THRES_MASK                                     0x000000ff
#define BTCOEX2_FRAME_THRES_GET(x)                                   (((x) & BTCOEX2_FRAME_THRES_MASK) >> BTCOEX2_FRAME_THRES_LSB)
#define BTCOEX2_FRAME_THRES_SET(x)                                   (((0 | (x)) << BTCOEX2_FRAME_THRES_LSB) & BTCOEX2_FRAME_THRES_MASK)
#define BTCOEX2_FRAME_THRES_RESET                                    255
#define BTCOEX2_ADDRESS                                              0x001c
#define BTCOEX2_HW_MASK                                              0x000000ff
#define BTCOEX2_SW_MASK                                              0x000000ff
#define BTCOEX2_HW_WRITE_MASK                                        0x00000000
#define BTCOEX2_SW_WRITE_MASK                                        0x000000ff
#define BTCOEX2_RSTMASK                                              0xffffffff
#define BTCOEX2_RESET                                                0x000000ff

// 0x0020 (BTCOEX3)
#define BTCOEX3_CLK_CNT_MSB                                          20
#define BTCOEX3_CLK_CNT_LSB                                          0
#define BTCOEX3_CLK_CNT_MASK                                         0x001fffff
#define BTCOEX3_CLK_CNT_GET(x)                                       (((x) & BTCOEX3_CLK_CNT_MASK) >> BTCOEX3_CLK_CNT_LSB)
#define BTCOEX3_CLK_CNT_SET(x)                                       (((0 | (x)) << BTCOEX3_CLK_CNT_LSB) & BTCOEX3_CLK_CNT_MASK)
#define BTCOEX3_CLK_CNT_RESET                                        0
#define BTCOEX3_ADDRESS                                              0x0020
#define BTCOEX3_HW_MASK                                              0x001fffff
#define BTCOEX3_SW_MASK                                              0x001fffff
#define BTCOEX3_HW_WRITE_MASK                                        0x001fffff
#define BTCOEX3_SW_WRITE_MASK                                        0x001fffff
#define BTCOEX3_RSTMASK                                              0xffffffff
#define BTCOEX3_RESET                                                0x00000000

// 0x0024 (BTCOEX4)
#define BTCOEX4_FRAME_CNT_MSB                                        7
#define BTCOEX4_FRAME_CNT_LSB                                        0
#define BTCOEX4_FRAME_CNT_MASK                                       0x000000ff
#define BTCOEX4_FRAME_CNT_GET(x)                                     (((x) & BTCOEX4_FRAME_CNT_MASK) >> BTCOEX4_FRAME_CNT_LSB)
#define BTCOEX4_FRAME_CNT_SET(x)                                     (((0 | (x)) << BTCOEX4_FRAME_CNT_LSB) & BTCOEX4_FRAME_CNT_MASK)
#define BTCOEX4_FRAME_CNT_RESET                                      0
#define BTCOEX4_ADDRESS                                              0x0024
#define BTCOEX4_HW_MASK                                              0x000000ff
#define BTCOEX4_SW_MASK                                              0x000000ff
#define BTCOEX4_HW_WRITE_MASK                                        0x000000ff
#define BTCOEX4_SW_WRITE_MASK                                        0x000000ff
#define BTCOEX4_RSTMASK                                              0xffffffff
#define BTCOEX4_RESET                                                0x00000000

// 0x0028 (BTCOEX5)
#define BTCOEX5_IDLE_CNT_MSB                                         15
#define BTCOEX5_IDLE_CNT_LSB                                         0
#define BTCOEX5_IDLE_CNT_MASK                                        0x0000ffff
#define BTCOEX5_IDLE_CNT_GET(x)                                      (((x) & BTCOEX5_IDLE_CNT_MASK) >> BTCOEX5_IDLE_CNT_LSB)
#define BTCOEX5_IDLE_CNT_SET(x)                                      (((0 | (x)) << BTCOEX5_IDLE_CNT_LSB) & BTCOEX5_IDLE_CNT_MASK)
#define BTCOEX5_IDLE_CNT_RESET                                       0
#define BTCOEX5_ADDRESS                                              0x0028
#define BTCOEX5_HW_MASK                                              0x0000ffff
#define BTCOEX5_SW_MASK                                              0x0000ffff
#define BTCOEX5_HW_WRITE_MASK                                        0x0000ffff
#define BTCOEX5_SW_WRITE_MASK                                        0x0000ffff
#define BTCOEX5_RSTMASK                                              0xffffffff
#define BTCOEX5_RESET                                                0x00000000

// 0x002c (BTCOEX6)
#define BTCOEX6_IDLE_RESET_LVL_BITMAP_MSB                            31
#define BTCOEX6_IDLE_RESET_LVL_BITMAP_LSB                            0
#define BTCOEX6_IDLE_RESET_LVL_BITMAP_MASK                           0xffffffff
#define BTCOEX6_IDLE_RESET_LVL_BITMAP_GET(x)                         (((x) & BTCOEX6_IDLE_RESET_LVL_BITMAP_MASK) >> BTCOEX6_IDLE_RESET_LVL_BITMAP_LSB)
#define BTCOEX6_IDLE_RESET_LVL_BITMAP_SET(x)                         (((0 | (x)) << BTCOEX6_IDLE_RESET_LVL_BITMAP_LSB) & BTCOEX6_IDLE_RESET_LVL_BITMAP_MASK)
#define BTCOEX6_IDLE_RESET_LVL_BITMAP_RESET                          4294967295
#define BTCOEX6_ADDRESS                                              0x002c
#define BTCOEX6_HW_MASK                                              0xffffffff
#define BTCOEX6_SW_MASK                                              0xffffffff
#define BTCOEX6_HW_WRITE_MASK                                        0x00000000
#define BTCOEX6_SW_WRITE_MASK                                        0xffffffff
#define BTCOEX6_RSTMASK                                              0xffffffff
#define BTCOEX6_RESET                                                0xffffffff

// 0x0030 (WBSYNC)
#define WBSYNC_BTCLOCK_MSB                                           31
#define WBSYNC_BTCLOCK_LSB                                           0
#define WBSYNC_BTCLOCK_MASK                                          0xffffffff
#define WBSYNC_BTCLOCK_GET(x)                                        (((x) & WBSYNC_BTCLOCK_MASK) >> WBSYNC_BTCLOCK_LSB)
#define WBSYNC_BTCLOCK_SET(x)                                        (((0 | (x)) << WBSYNC_BTCLOCK_LSB) & WBSYNC_BTCLOCK_MASK)
#define WBSYNC_BTCLOCK_RESET                                         0
#define WBSYNC_ADDRESS                                               0x0030
#define WBSYNC_HW_MASK                                               0xffffffff
#define WBSYNC_SW_MASK                                               0xffffffff
#define WBSYNC_HW_WRITE_MASK                                         0xffffffff
#define WBSYNC_SW_WRITE_MASK                                         0x00000000
#define WBSYNC_RSTMASK                                               0xffffffff
#define WBSYNC_RESET                                                 0x00000000

// 0x0034 (WBSYNC1)
#define WBSYNC1_BTCLOCK_MSB                                          31
#define WBSYNC1_BTCLOCK_LSB                                          0
#define WBSYNC1_BTCLOCK_MASK                                         0xffffffff
#define WBSYNC1_BTCLOCK_GET(x)                                       (((x) & WBSYNC1_BTCLOCK_MASK) >> WBSYNC1_BTCLOCK_LSB)
#define WBSYNC1_BTCLOCK_SET(x)                                       (((0 | (x)) << WBSYNC1_BTCLOCK_LSB) & WBSYNC1_BTCLOCK_MASK)
#define WBSYNC1_BTCLOCK_RESET                                        0
#define WBSYNC1_ADDRESS                                              0x0034
#define WBSYNC1_HW_MASK                                              0xffffffff
#define WBSYNC1_SW_MASK                                              0xffffffff
#define WBSYNC1_HW_WRITE_MASK                                        0xffffffff
#define WBSYNC1_SW_WRITE_MASK                                        0x00000000
#define WBSYNC1_RSTMASK                                              0xffffffff
#define WBSYNC1_RESET                                                0x00000000

// 0x0038 (WBSYNC2)
#define WBSYNC2_BTCLOCK_MSB                                          31
#define WBSYNC2_BTCLOCK_LSB                                          0
#define WBSYNC2_BTCLOCK_MASK                                         0xffffffff
#define WBSYNC2_BTCLOCK_GET(x)                                       (((x) & WBSYNC2_BTCLOCK_MASK) >> WBSYNC2_BTCLOCK_LSB)
#define WBSYNC2_BTCLOCK_SET(x)                                       (((0 | (x)) << WBSYNC2_BTCLOCK_LSB) & WBSYNC2_BTCLOCK_MASK)
#define WBSYNC2_BTCLOCK_RESET                                        0
#define WBSYNC2_ADDRESS                                              0x0038
#define WBSYNC2_HW_MASK                                              0xffffffff
#define WBSYNC2_SW_MASK                                              0xffffffff
#define WBSYNC2_HW_WRITE_MASK                                        0xffffffff
#define WBSYNC2_SW_WRITE_MASK                                        0x00000000
#define WBSYNC2_RSTMASK                                              0xffffffff
#define WBSYNC2_RESET                                                0x00000000

// 0x003c (WBSYNC3)
#define WBSYNC3_BTCLOCK_MSB                                          31
#define WBSYNC3_BTCLOCK_LSB                                          0
#define WBSYNC3_BTCLOCK_MASK                                         0xffffffff
#define WBSYNC3_BTCLOCK_GET(x)                                       (((x) & WBSYNC3_BTCLOCK_MASK) >> WBSYNC3_BTCLOCK_LSB)
#define WBSYNC3_BTCLOCK_SET(x)                                       (((0 | (x)) << WBSYNC3_BTCLOCK_LSB) & WBSYNC3_BTCLOCK_MASK)
#define WBSYNC3_BTCLOCK_RESET                                        0
#define WBSYNC3_ADDRESS                                              0x003c
#define WBSYNC3_HW_MASK                                              0xffffffff
#define WBSYNC3_SW_MASK                                              0xffffffff
#define WBSYNC3_HW_WRITE_MASK                                        0xffffffff
#define WBSYNC3_SW_WRITE_MASK                                        0x00000000
#define WBSYNC3_RSTMASK                                              0xffffffff
#define WBSYNC3_RESET                                                0x00000000

// 0x0040 (WB_TIMER_TARGET)
#define WB_TIMER_TARGET_VALUE_MSB                                    31
#define WB_TIMER_TARGET_VALUE_LSB                                    0
#define WB_TIMER_TARGET_VALUE_MASK                                   0xffffffff
#define WB_TIMER_TARGET_VALUE_GET(x)                                 (((x) & WB_TIMER_TARGET_VALUE_MASK) >> WB_TIMER_TARGET_VALUE_LSB)
#define WB_TIMER_TARGET_VALUE_SET(x)                                 (((0 | (x)) << WB_TIMER_TARGET_VALUE_LSB) & WB_TIMER_TARGET_VALUE_MASK)
#define WB_TIMER_TARGET_VALUE_RESET                                  0
#define WB_TIMER_TARGET_ADDRESS                                      0x0040
#define WB_TIMER_TARGET_HW_MASK                                      0xffffffff
#define WB_TIMER_TARGET_SW_MASK                                      0xffffffff
#define WB_TIMER_TARGET_HW_WRITE_MASK                                0x00000000
#define WB_TIMER_TARGET_SW_WRITE_MASK                                0xffffffff
#define WB_TIMER_TARGET_RSTMASK                                      0xffffffff
#define WB_TIMER_TARGET_RESET                                        0x00000000

// 0x0044 (WB_TIMER_SLOP)
#define WB_TIMER_SLOP_VALUE_MSB                                      9
#define WB_TIMER_SLOP_VALUE_LSB                                      0
#define WB_TIMER_SLOP_VALUE_MASK                                     0x000003ff
#define WB_TIMER_SLOP_VALUE_GET(x)                                   (((x) & WB_TIMER_SLOP_VALUE_MASK) >> WB_TIMER_SLOP_VALUE_LSB)
#define WB_TIMER_SLOP_VALUE_SET(x)                                   (((0 | (x)) << WB_TIMER_SLOP_VALUE_LSB) & WB_TIMER_SLOP_VALUE_MASK)
#define WB_TIMER_SLOP_VALUE_RESET                                    0
#define WB_TIMER_SLOP_ADDRESS                                        0x0044
#define WB_TIMER_SLOP_HW_MASK                                        0x000003ff
#define WB_TIMER_SLOP_SW_MASK                                        0x000003ff
#define WB_TIMER_SLOP_HW_WRITE_MASK                                  0x00000000
#define WB_TIMER_SLOP_SW_WRITE_MASK                                  0x000003ff
#define WB_TIMER_SLOP_RSTMASK                                        0xffffffff
#define WB_TIMER_SLOP_RESET                                          0x00000000

// 0x0048 (BTCOEX_INT_EN)
#define BTCOEX_INT_EN_WB_TIMER_MSB                                   7
#define BTCOEX_INT_EN_WB_TIMER_LSB                                   7
#define BTCOEX_INT_EN_WB_TIMER_MASK                                  0x00000080
#define BTCOEX_INT_EN_WB_TIMER_GET(x)                                (((x) & BTCOEX_INT_EN_WB_TIMER_MASK) >> BTCOEX_INT_EN_WB_TIMER_LSB)
#define BTCOEX_INT_EN_WB_TIMER_SET(x)                                (((0 | (x)) << BTCOEX_INT_EN_WB_TIMER_LSB) & BTCOEX_INT_EN_WB_TIMER_MASK)
#define BTCOEX_INT_EN_WB_TIMER_RESET                                 0
#define BTCOEX_INT_EN_NOSYNC_MSB                                     4
#define BTCOEX_INT_EN_NOSYNC_LSB                                     4
#define BTCOEX_INT_EN_NOSYNC_MASK                                    0x00000010
#define BTCOEX_INT_EN_NOSYNC_GET(x)                                  (((x) & BTCOEX_INT_EN_NOSYNC_MASK) >> BTCOEX_INT_EN_NOSYNC_LSB)
#define BTCOEX_INT_EN_NOSYNC_SET(x)                                  (((0 | (x)) << BTCOEX_INT_EN_NOSYNC_LSB) & BTCOEX_INT_EN_NOSYNC_MASK)
#define BTCOEX_INT_EN_NOSYNC_RESET                                   0
#define BTCOEX_INT_EN_SYNC_MSB                                       3
#define BTCOEX_INT_EN_SYNC_LSB                                       3
#define BTCOEX_INT_EN_SYNC_MASK                                      0x00000008
#define BTCOEX_INT_EN_SYNC_GET(x)                                    (((x) & BTCOEX_INT_EN_SYNC_MASK) >> BTCOEX_INT_EN_SYNC_LSB)
#define BTCOEX_INT_EN_SYNC_SET(x)                                    (((0 | (x)) << BTCOEX_INT_EN_SYNC_LSB) & BTCOEX_INT_EN_SYNC_MASK)
#define BTCOEX_INT_EN_SYNC_RESET                                     0
#define BTCOEX_INT_EN_END_MSB                                        2
#define BTCOEX_INT_EN_END_LSB                                        2
#define BTCOEX_INT_EN_END_MASK                                       0x00000004
#define BTCOEX_INT_EN_END_GET(x)                                     (((x) & BTCOEX_INT_EN_END_MASK) >> BTCOEX_INT_EN_END_LSB)
#define BTCOEX_INT_EN_END_SET(x)                                     (((0 | (x)) << BTCOEX_INT_EN_END_LSB) & BTCOEX_INT_EN_END_MASK)
#define BTCOEX_INT_EN_END_RESET                                      0
#define BTCOEX_INT_EN_FRAME_CNT_MSB                                  1
#define BTCOEX_INT_EN_FRAME_CNT_LSB                                  1
#define BTCOEX_INT_EN_FRAME_CNT_MASK                                 0x00000002
#define BTCOEX_INT_EN_FRAME_CNT_GET(x)                               (((x) & BTCOEX_INT_EN_FRAME_CNT_MASK) >> BTCOEX_INT_EN_FRAME_CNT_LSB)
#define BTCOEX_INT_EN_FRAME_CNT_SET(x)                               (((0 | (x)) << BTCOEX_INT_EN_FRAME_CNT_LSB) & BTCOEX_INT_EN_FRAME_CNT_MASK)
#define BTCOEX_INT_EN_FRAME_CNT_RESET                                0
#define BTCOEX_INT_EN_CLK_CNT_MSB                                    0
#define BTCOEX_INT_EN_CLK_CNT_LSB                                    0
#define BTCOEX_INT_EN_CLK_CNT_MASK                                   0x00000001
#define BTCOEX_INT_EN_CLK_CNT_GET(x)                                 (((x) & BTCOEX_INT_EN_CLK_CNT_MASK) >> BTCOEX_INT_EN_CLK_CNT_LSB)
#define BTCOEX_INT_EN_CLK_CNT_SET(x)                                 (((0 | (x)) << BTCOEX_INT_EN_CLK_CNT_LSB) & BTCOEX_INT_EN_CLK_CNT_MASK)
#define BTCOEX_INT_EN_CLK_CNT_RESET                                  0
#define BTCOEX_INT_EN_ADDRESS                                        0x0048
#define BTCOEX_INT_EN_HW_MASK                                        0x0000009f
#define BTCOEX_INT_EN_SW_MASK                                        0x0000009f
#define BTCOEX_INT_EN_HW_WRITE_MASK                                  0x00000000
#define BTCOEX_INT_EN_SW_WRITE_MASK                                  0x0000009f
#define BTCOEX_INT_EN_RSTMASK                                        0xffffffff
#define BTCOEX_INT_EN_RESET                                          0x00000000

// 0x004c (BTCOEX_INT_STAT)
#define BTCOEX_INT_STAT_MCI_MSB                                      12
#define BTCOEX_INT_STAT_MCI_LSB                                      12
#define BTCOEX_INT_STAT_MCI_MASK                                     0x00001000
#define BTCOEX_INT_STAT_MCI_GET(x)                                   (((x) & BTCOEX_INT_STAT_MCI_MASK) >> BTCOEX_INT_STAT_MCI_LSB)
#define BTCOEX_INT_STAT_MCI_SET(x)                                   (((0 | (x)) << BTCOEX_INT_STAT_MCI_LSB) & BTCOEX_INT_STAT_MCI_MASK)
#define BTCOEX_INT_STAT_MCI_RESET                                    0
#define BTCOEX_INT_STAT_WB_TIMER_MSB                                 7
#define BTCOEX_INT_STAT_WB_TIMER_LSB                                 7
#define BTCOEX_INT_STAT_WB_TIMER_MASK                                0x00000080
#define BTCOEX_INT_STAT_WB_TIMER_GET(x)                              (((x) & BTCOEX_INT_STAT_WB_TIMER_MASK) >> BTCOEX_INT_STAT_WB_TIMER_LSB)
#define BTCOEX_INT_STAT_WB_TIMER_SET(x)                              (((0 | (x)) << BTCOEX_INT_STAT_WB_TIMER_LSB) & BTCOEX_INT_STAT_WB_TIMER_MASK)
#define BTCOEX_INT_STAT_WB_TIMER_RESET                               0
#define BTCOEX_INT_STAT_BTPRIORITY_STOMP_MSB                         6
#define BTCOEX_INT_STAT_BTPRIORITY_STOMP_LSB                         6
#define BTCOEX_INT_STAT_BTPRIORITY_STOMP_MASK                        0x00000040
#define BTCOEX_INT_STAT_BTPRIORITY_STOMP_GET(x)                      (((x) & BTCOEX_INT_STAT_BTPRIORITY_STOMP_MASK) >> BTCOEX_INT_STAT_BTPRIORITY_STOMP_LSB)
#define BTCOEX_INT_STAT_BTPRIORITY_STOMP_SET(x)                      (((0 | (x)) << BTCOEX_INT_STAT_BTPRIORITY_STOMP_LSB) & BTCOEX_INT_STAT_BTPRIORITY_STOMP_MASK)
#define BTCOEX_INT_STAT_BTPRIORITY_STOMP_RESET                       0
#define BTCOEX_INT_STAT_BTPRIORITY_MSB                               5
#define BTCOEX_INT_STAT_BTPRIORITY_LSB                               5
#define BTCOEX_INT_STAT_BTPRIORITY_MASK                              0x00000020
#define BTCOEX_INT_STAT_BTPRIORITY_GET(x)                            (((x) & BTCOEX_INT_STAT_BTPRIORITY_MASK) >> BTCOEX_INT_STAT_BTPRIORITY_LSB)
#define BTCOEX_INT_STAT_BTPRIORITY_SET(x)                            (((0 | (x)) << BTCOEX_INT_STAT_BTPRIORITY_LSB) & BTCOEX_INT_STAT_BTPRIORITY_MASK)
#define BTCOEX_INT_STAT_BTPRIORITY_RESET                             0
#define BTCOEX_INT_STAT_NOSYNC_MSB                                   4
#define BTCOEX_INT_STAT_NOSYNC_LSB                                   4
#define BTCOEX_INT_STAT_NOSYNC_MASK                                  0x00000010
#define BTCOEX_INT_STAT_NOSYNC_GET(x)                                (((x) & BTCOEX_INT_STAT_NOSYNC_MASK) >> BTCOEX_INT_STAT_NOSYNC_LSB)
#define BTCOEX_INT_STAT_NOSYNC_SET(x)                                (((0 | (x)) << BTCOEX_INT_STAT_NOSYNC_LSB) & BTCOEX_INT_STAT_NOSYNC_MASK)
#define BTCOEX_INT_STAT_NOSYNC_RESET                                 0
#define BTCOEX_INT_STAT_SYNC_MSB                                     3
#define BTCOEX_INT_STAT_SYNC_LSB                                     3
#define BTCOEX_INT_STAT_SYNC_MASK                                    0x00000008
#define BTCOEX_INT_STAT_SYNC_GET(x)                                  (((x) & BTCOEX_INT_STAT_SYNC_MASK) >> BTCOEX_INT_STAT_SYNC_LSB)
#define BTCOEX_INT_STAT_SYNC_SET(x)                                  (((0 | (x)) << BTCOEX_INT_STAT_SYNC_LSB) & BTCOEX_INT_STAT_SYNC_MASK)
#define BTCOEX_INT_STAT_SYNC_RESET                                   0
#define BTCOEX_INT_STAT_END_MSB                                      2
#define BTCOEX_INT_STAT_END_LSB                                      2
#define BTCOEX_INT_STAT_END_MASK                                     0x00000004
#define BTCOEX_INT_STAT_END_GET(x)                                   (((x) & BTCOEX_INT_STAT_END_MASK) >> BTCOEX_INT_STAT_END_LSB)
#define BTCOEX_INT_STAT_END_SET(x)                                   (((0 | (x)) << BTCOEX_INT_STAT_END_LSB) & BTCOEX_INT_STAT_END_MASK)
#define BTCOEX_INT_STAT_END_RESET                                    0
#define BTCOEX_INT_STAT_FRAME_CNT_MSB                                1
#define BTCOEX_INT_STAT_FRAME_CNT_LSB                                1
#define BTCOEX_INT_STAT_FRAME_CNT_MASK                               0x00000002
#define BTCOEX_INT_STAT_FRAME_CNT_GET(x)                             (((x) & BTCOEX_INT_STAT_FRAME_CNT_MASK) >> BTCOEX_INT_STAT_FRAME_CNT_LSB)
#define BTCOEX_INT_STAT_FRAME_CNT_SET(x)                             (((0 | (x)) << BTCOEX_INT_STAT_FRAME_CNT_LSB) & BTCOEX_INT_STAT_FRAME_CNT_MASK)
#define BTCOEX_INT_STAT_FRAME_CNT_RESET                              0
#define BTCOEX_INT_STAT_CLK_CNT_MSB                                  0
#define BTCOEX_INT_STAT_CLK_CNT_LSB                                  0
#define BTCOEX_INT_STAT_CLK_CNT_MASK                                 0x00000001
#define BTCOEX_INT_STAT_CLK_CNT_GET(x)                               (((x) & BTCOEX_INT_STAT_CLK_CNT_MASK) >> BTCOEX_INT_STAT_CLK_CNT_LSB)
#define BTCOEX_INT_STAT_CLK_CNT_SET(x)                               (((0 | (x)) << BTCOEX_INT_STAT_CLK_CNT_LSB) & BTCOEX_INT_STAT_CLK_CNT_MASK)
#define BTCOEX_INT_STAT_CLK_CNT_RESET                                0
#define BTCOEX_INT_STAT_ADDRESS                                      0x004c
#define BTCOEX_INT_STAT_HW_MASK                                      0x000010ff
#define BTCOEX_INT_STAT_SW_MASK                                      0x000010ff
#define BTCOEX_INT_STAT_HW_WRITE_MASK                                0x000010ff
#define BTCOEX_INT_STAT_SW_WRITE_MASK                                0x0000009f
#define BTCOEX_INT_STAT_RSTMASK                                      0xffffffff
#define BTCOEX_INT_STAT_RESET                                        0x00000000

// 0x0050 (BTPRIORITY_INT_EN)
#define BTPRIORITY_INT_EN_BITMAP_MSB                                 31
#define BTPRIORITY_INT_EN_BITMAP_LSB                                 0
#define BTPRIORITY_INT_EN_BITMAP_MASK                                0xffffffff
#define BTPRIORITY_INT_EN_BITMAP_GET(x)                              (((x) & BTPRIORITY_INT_EN_BITMAP_MASK) >> BTPRIORITY_INT_EN_BITMAP_LSB)
#define BTPRIORITY_INT_EN_BITMAP_SET(x)                              (((0 | (x)) << BTPRIORITY_INT_EN_BITMAP_LSB) & BTPRIORITY_INT_EN_BITMAP_MASK)
#define BTPRIORITY_INT_EN_BITMAP_RESET                               0
#define BTPRIORITY_INT_EN_ADDRESS                                    0x0050
#define BTPRIORITY_INT_EN_HW_MASK                                    0xffffffff
#define BTPRIORITY_INT_EN_SW_MASK                                    0xffffffff
#define BTPRIORITY_INT_EN_HW_WRITE_MASK                              0x00000000
#define BTPRIORITY_INT_EN_SW_WRITE_MASK                              0xffffffff
#define BTPRIORITY_INT_EN_RSTMASK                                    0xffffffff
#define BTPRIORITY_INT_EN_RESET                                      0x00000000

// 0x0054 (BTPRIORITY_INT_STAT)
#define BTPRIORITY_INT_STAT_BITMAP_MSB                               31
#define BTPRIORITY_INT_STAT_BITMAP_LSB                               0
#define BTPRIORITY_INT_STAT_BITMAP_MASK                              0xffffffff
#define BTPRIORITY_INT_STAT_BITMAP_GET(x)                            (((x) & BTPRIORITY_INT_STAT_BITMAP_MASK) >> BTPRIORITY_INT_STAT_BITMAP_LSB)
#define BTPRIORITY_INT_STAT_BITMAP_SET(x)                            (((0 | (x)) << BTPRIORITY_INT_STAT_BITMAP_LSB) & BTPRIORITY_INT_STAT_BITMAP_MASK)
#define BTPRIORITY_INT_STAT_BITMAP_RESET                             0
#define BTPRIORITY_INT_STAT_ADDRESS                                  0x0054
#define BTPRIORITY_INT_STAT_HW_MASK                                  0xffffffff
#define BTPRIORITY_INT_STAT_SW_MASK                                  0xffffffff
#define BTPRIORITY_INT_STAT_HW_WRITE_MASK                            0xffffffff
#define BTPRIORITY_INT_STAT_SW_WRITE_MASK                            0xffffffff
#define BTPRIORITY_INT_STAT_RSTMASK                                  0xffffffff
#define BTPRIORITY_INT_STAT_RESET                                    0x00000000

// 0x0058 (BTPRIORITY_STOMP_INT_EN)
#define BTPRIORITY_STOMP_INT_EN_BITMAP_MSB                           31
#define BTPRIORITY_STOMP_INT_EN_BITMAP_LSB                           0
#define BTPRIORITY_STOMP_INT_EN_BITMAP_MASK                          0xffffffff
#define BTPRIORITY_STOMP_INT_EN_BITMAP_GET(x)                        (((x) & BTPRIORITY_STOMP_INT_EN_BITMAP_MASK) >> BTPRIORITY_STOMP_INT_EN_BITMAP_LSB)
#define BTPRIORITY_STOMP_INT_EN_BITMAP_SET(x)                        (((0 | (x)) << BTPRIORITY_STOMP_INT_EN_BITMAP_LSB) & BTPRIORITY_STOMP_INT_EN_BITMAP_MASK)
#define BTPRIORITY_STOMP_INT_EN_BITMAP_RESET                         0
#define BTPRIORITY_STOMP_INT_EN_ADDRESS                              0x0058
#define BTPRIORITY_STOMP_INT_EN_HW_MASK                              0xffffffff
#define BTPRIORITY_STOMP_INT_EN_SW_MASK                              0xffffffff
#define BTPRIORITY_STOMP_INT_EN_HW_WRITE_MASK                        0x00000000
#define BTPRIORITY_STOMP_INT_EN_SW_WRITE_MASK                        0xffffffff
#define BTPRIORITY_STOMP_INT_EN_RSTMASK                              0xffffffff
#define BTPRIORITY_STOMP_INT_EN_RESET                                0x00000000

// 0x005c (BTPRIORITY_STOMP_INT_STAT)
#define BTPRIORITY_STOMP_INT_STAT_BITMAP_MSB                         31
#define BTPRIORITY_STOMP_INT_STAT_BITMAP_LSB                         0
#define BTPRIORITY_STOMP_INT_STAT_BITMAP_MASK                        0xffffffff
#define BTPRIORITY_STOMP_INT_STAT_BITMAP_GET(x)                      (((x) & BTPRIORITY_STOMP_INT_STAT_BITMAP_MASK) >> BTPRIORITY_STOMP_INT_STAT_BITMAP_LSB)
#define BTPRIORITY_STOMP_INT_STAT_BITMAP_SET(x)                      (((0 | (x)) << BTPRIORITY_STOMP_INT_STAT_BITMAP_LSB) & BTPRIORITY_STOMP_INT_STAT_BITMAP_MASK)
#define BTPRIORITY_STOMP_INT_STAT_BITMAP_RESET                       0
#define BTPRIORITY_STOMP_INT_STAT_ADDRESS                            0x005c
#define BTPRIORITY_STOMP_INT_STAT_HW_MASK                            0xffffffff
#define BTPRIORITY_STOMP_INT_STAT_SW_MASK                            0xffffffff
#define BTPRIORITY_STOMP_INT_STAT_HW_WRITE_MASK                      0xffffffff
#define BTPRIORITY_STOMP_INT_STAT_SW_WRITE_MASK                      0xffffffff
#define BTPRIORITY_STOMP_INT_STAT_RSTMASK                            0xffffffff
#define BTPRIORITY_STOMP_INT_STAT_RESET                              0x00000000

// 0x0060 (BTPRIORITY_INT)
#define BTPRIORITY_INT_DELAY_MSB                                     7
#define BTPRIORITY_INT_DELAY_LSB                                     0
#define BTPRIORITY_INT_DELAY_MASK                                    0x000000ff
#define BTPRIORITY_INT_DELAY_GET(x)                                  (((x) & BTPRIORITY_INT_DELAY_MASK) >> BTPRIORITY_INT_DELAY_LSB)
#define BTPRIORITY_INT_DELAY_SET(x)                                  (((0 | (x)) << BTPRIORITY_INT_DELAY_LSB) & BTPRIORITY_INT_DELAY_MASK)
#define BTPRIORITY_INT_DELAY_RESET                                   0
#define BTPRIORITY_INT_ADDRESS                                       0x0060
#define BTPRIORITY_INT_HW_MASK                                       0x000000ff
#define BTPRIORITY_INT_SW_MASK                                       0x000000ff
#define BTPRIORITY_INT_HW_WRITE_MASK                                 0x00000000
#define BTPRIORITY_INT_SW_WRITE_MASK                                 0x000000ff
#define BTPRIORITY_INT_RSTMASK                                       0xffffffff
#define BTPRIORITY_INT_RESET                                         0x00000000

// 0x0064 (SCO_PARAMS)
#define SCO_PARAMS_SLOP_MSB                                          23
#define SCO_PARAMS_SLOP_LSB                                          14
#define SCO_PARAMS_SLOP_MASK                                         0x00ffc000
#define SCO_PARAMS_SLOP_GET(x)                                       (((x) & SCO_PARAMS_SLOP_MASK) >> SCO_PARAMS_SLOP_LSB)
#define SCO_PARAMS_SLOP_SET(x)                                       (((0 | (x)) << SCO_PARAMS_SLOP_LSB) & SCO_PARAMS_SLOP_MASK)
#define SCO_PARAMS_SLOP_RESET                                        0
#define SCO_PARAMS_PERIOD_MSB                                        13
#define SCO_PARAMS_PERIOD_LSB                                        0
#define SCO_PARAMS_PERIOD_MASK                                       0x00003fff
#define SCO_PARAMS_PERIOD_GET(x)                                     (((x) & SCO_PARAMS_PERIOD_MASK) >> SCO_PARAMS_PERIOD_LSB)
#define SCO_PARAMS_PERIOD_SET(x)                                     (((0 | (x)) << SCO_PARAMS_PERIOD_LSB) & SCO_PARAMS_PERIOD_MASK)
#define SCO_PARAMS_PERIOD_RESET                                      0
#define SCO_PARAMS_ADDRESS                                           0x0064
#define SCO_PARAMS_HW_MASK                                           0x00ffffff
#define SCO_PARAMS_SW_MASK                                           0x00ffffff
#define SCO_PARAMS_HW_WRITE_MASK                                     0x00000000
#define SCO_PARAMS_SW_WRITE_MASK                                     0x00ffffff
#define SCO_PARAMS_RSTMASK                                           0xffffffff
#define SCO_PARAMS_RESET                                             0x00000000

// 0x0068 (SCO_PRIORITY)
#define SCO_PRIORITY_BITMAP_MSB                                      31
#define SCO_PRIORITY_BITMAP_LSB                                      0
#define SCO_PRIORITY_BITMAP_MASK                                     0xffffffff
#define SCO_PRIORITY_BITMAP_GET(x)                                   (((x) & SCO_PRIORITY_BITMAP_MASK) >> SCO_PRIORITY_BITMAP_LSB)
#define SCO_PRIORITY_BITMAP_SET(x)                                   (((0 | (x)) << SCO_PRIORITY_BITMAP_LSB) & SCO_PRIORITY_BITMAP_MASK)
#define SCO_PRIORITY_BITMAP_RESET                                    0
#define SCO_PRIORITY_ADDRESS                                         0x0068
#define SCO_PRIORITY_HW_MASK                                         0xffffffff
#define SCO_PRIORITY_SW_MASK                                         0xffffffff
#define SCO_PRIORITY_HW_WRITE_MASK                                   0x00000000
#define SCO_PRIORITY_SW_WRITE_MASK                                   0xffffffff
#define SCO_PRIORITY_RSTMASK                                         0xffffffff
#define SCO_PRIORITY_RESET                                           0x00000000

// 0x006c (SCO_SYNC)
#define SCO_SYNC_BTCLOCK_MSB                                         31
#define SCO_SYNC_BTCLOCK_LSB                                         0
#define SCO_SYNC_BTCLOCK_MASK                                        0xffffffff
#define SCO_SYNC_BTCLOCK_GET(x)                                      (((x) & SCO_SYNC_BTCLOCK_MASK) >> SCO_SYNC_BTCLOCK_LSB)
#define SCO_SYNC_BTCLOCK_SET(x)                                      (((0 | (x)) << SCO_SYNC_BTCLOCK_LSB) & SCO_SYNC_BTCLOCK_MASK)
#define SCO_SYNC_BTCLOCK_RESET                                       0
#define SCO_SYNC_ADDRESS                                             0x006c
#define SCO_SYNC_HW_MASK                                             0xffffffff
#define SCO_SYNC_SW_MASK                                             0xffffffff
#define SCO_SYNC_HW_WRITE_MASK                                       0xffffffff
#define SCO_SYNC_SW_WRITE_MASK                                       0xffffffff
#define SCO_SYNC_RSTMASK                                             0xffffffff
#define SCO_SYNC_RESET                                               0x00000000

// 0x0070 (BTCOEX_RAW_STAT)
#define BTCOEX_RAW_STAT_WB_TIMER_MSB                                 7
#define BTCOEX_RAW_STAT_WB_TIMER_LSB                                 7
#define BTCOEX_RAW_STAT_WB_TIMER_MASK                                0x00000080
#define BTCOEX_RAW_STAT_WB_TIMER_GET(x)                              (((x) & BTCOEX_RAW_STAT_WB_TIMER_MASK) >> BTCOEX_RAW_STAT_WB_TIMER_LSB)
#define BTCOEX_RAW_STAT_WB_TIMER_SET(x)                              (((0 | (x)) << BTCOEX_RAW_STAT_WB_TIMER_LSB) & BTCOEX_RAW_STAT_WB_TIMER_MASK)
#define BTCOEX_RAW_STAT_WB_TIMER_RESET                               0
#define BTCOEX_RAW_STAT_NOSYNC_MSB                                   4
#define BTCOEX_RAW_STAT_NOSYNC_LSB                                   4
#define BTCOEX_RAW_STAT_NOSYNC_MASK                                  0x00000010
#define BTCOEX_RAW_STAT_NOSYNC_GET(x)                                (((x) & BTCOEX_RAW_STAT_NOSYNC_MASK) >> BTCOEX_RAW_STAT_NOSYNC_LSB)
#define BTCOEX_RAW_STAT_NOSYNC_SET(x)                                (((0 | (x)) << BTCOEX_RAW_STAT_NOSYNC_LSB) & BTCOEX_RAW_STAT_NOSYNC_MASK)
#define BTCOEX_RAW_STAT_NOSYNC_RESET                                 0
#define BTCOEX_RAW_STAT_SYNC_MSB                                     3
#define BTCOEX_RAW_STAT_SYNC_LSB                                     3
#define BTCOEX_RAW_STAT_SYNC_MASK                                    0x00000008
#define BTCOEX_RAW_STAT_SYNC_GET(x)                                  (((x) & BTCOEX_RAW_STAT_SYNC_MASK) >> BTCOEX_RAW_STAT_SYNC_LSB)
#define BTCOEX_RAW_STAT_SYNC_SET(x)                                  (((0 | (x)) << BTCOEX_RAW_STAT_SYNC_LSB) & BTCOEX_RAW_STAT_SYNC_MASK)
#define BTCOEX_RAW_STAT_SYNC_RESET                                   0
#define BTCOEX_RAW_STAT_END_MSB                                      2
#define BTCOEX_RAW_STAT_END_LSB                                      2
#define BTCOEX_RAW_STAT_END_MASK                                     0x00000004
#define BTCOEX_RAW_STAT_END_GET(x)                                   (((x) & BTCOEX_RAW_STAT_END_MASK) >> BTCOEX_RAW_STAT_END_LSB)
#define BTCOEX_RAW_STAT_END_SET(x)                                   (((0 | (x)) << BTCOEX_RAW_STAT_END_LSB) & BTCOEX_RAW_STAT_END_MASK)
#define BTCOEX_RAW_STAT_END_RESET                                    0
#define BTCOEX_RAW_STAT_FRAME_CNT_MSB                                1
#define BTCOEX_RAW_STAT_FRAME_CNT_LSB                                1
#define BTCOEX_RAW_STAT_FRAME_CNT_MASK                               0x00000002
#define BTCOEX_RAW_STAT_FRAME_CNT_GET(x)                             (((x) & BTCOEX_RAW_STAT_FRAME_CNT_MASK) >> BTCOEX_RAW_STAT_FRAME_CNT_LSB)
#define BTCOEX_RAW_STAT_FRAME_CNT_SET(x)                             (((0 | (x)) << BTCOEX_RAW_STAT_FRAME_CNT_LSB) & BTCOEX_RAW_STAT_FRAME_CNT_MASK)
#define BTCOEX_RAW_STAT_FRAME_CNT_RESET                              0
#define BTCOEX_RAW_STAT_CLK_CNT_MSB                                  0
#define BTCOEX_RAW_STAT_CLK_CNT_LSB                                  0
#define BTCOEX_RAW_STAT_CLK_CNT_MASK                                 0x00000001
#define BTCOEX_RAW_STAT_CLK_CNT_GET(x)                               (((x) & BTCOEX_RAW_STAT_CLK_CNT_MASK) >> BTCOEX_RAW_STAT_CLK_CNT_LSB)
#define BTCOEX_RAW_STAT_CLK_CNT_SET(x)                               (((0 | (x)) << BTCOEX_RAW_STAT_CLK_CNT_LSB) & BTCOEX_RAW_STAT_CLK_CNT_MASK)
#define BTCOEX_RAW_STAT_CLK_CNT_RESET                                0
#define BTCOEX_RAW_STAT_ADDRESS                                      0x0070
#define BTCOEX_RAW_STAT_HW_MASK                                      0x0000009f
#define BTCOEX_RAW_STAT_SW_MASK                                      0x0000009f
#define BTCOEX_RAW_STAT_HW_WRITE_MASK                                0x0000009f
#define BTCOEX_RAW_STAT_SW_WRITE_MASK                                0x0000009f
#define BTCOEX_RAW_STAT_RSTMASK                                      0xffffffff
#define BTCOEX_RAW_STAT_RESET                                        0x00000000

// 0x0074 (BTPRIORITY_RAW_STAT)
#define BTPRIORITY_RAW_STAT_BITMAP_MSB                               31
#define BTPRIORITY_RAW_STAT_BITMAP_LSB                               0
#define BTPRIORITY_RAW_STAT_BITMAP_MASK                              0xffffffff
#define BTPRIORITY_RAW_STAT_BITMAP_GET(x)                            (((x) & BTPRIORITY_RAW_STAT_BITMAP_MASK) >> BTPRIORITY_RAW_STAT_BITMAP_LSB)
#define BTPRIORITY_RAW_STAT_BITMAP_SET(x)                            (((0 | (x)) << BTPRIORITY_RAW_STAT_BITMAP_LSB) & BTPRIORITY_RAW_STAT_BITMAP_MASK)
#define BTPRIORITY_RAW_STAT_BITMAP_RESET                             0
#define BTPRIORITY_RAW_STAT_ADDRESS                                  0x0074
#define BTPRIORITY_RAW_STAT_HW_MASK                                  0xffffffff
#define BTPRIORITY_RAW_STAT_SW_MASK                                  0xffffffff
#define BTPRIORITY_RAW_STAT_HW_WRITE_MASK                            0xffffffff
#define BTPRIORITY_RAW_STAT_SW_WRITE_MASK                            0xffffffff
#define BTPRIORITY_RAW_STAT_RSTMASK                                  0xffffffff
#define BTPRIORITY_RAW_STAT_RESET                                    0x00000000

// 0x0078 (BTPRIORITY_STOMP_RAW_STAT)
#define BTPRIORITY_STOMP_RAW_STAT_BITMAP_MSB                         31
#define BTPRIORITY_STOMP_RAW_STAT_BITMAP_LSB                         0
#define BTPRIORITY_STOMP_RAW_STAT_BITMAP_MASK                        0xffffffff
#define BTPRIORITY_STOMP_RAW_STAT_BITMAP_GET(x)                      (((x) & BTPRIORITY_STOMP_RAW_STAT_BITMAP_MASK) >> BTPRIORITY_STOMP_RAW_STAT_BITMAP_LSB)
#define BTPRIORITY_STOMP_RAW_STAT_BITMAP_SET(x)                      (((0 | (x)) << BTPRIORITY_STOMP_RAW_STAT_BITMAP_LSB) & BTPRIORITY_STOMP_RAW_STAT_BITMAP_MASK)
#define BTPRIORITY_STOMP_RAW_STAT_BITMAP_RESET                       0
#define BTPRIORITY_STOMP_RAW_STAT_ADDRESS                            0x0078
#define BTPRIORITY_STOMP_RAW_STAT_HW_MASK                            0xffffffff
#define BTPRIORITY_STOMP_RAW_STAT_SW_MASK                            0xffffffff
#define BTPRIORITY_STOMP_RAW_STAT_HW_WRITE_MASK                      0xffffffff
#define BTPRIORITY_STOMP_RAW_STAT_SW_WRITE_MASK                      0xffffffff
#define BTPRIORITY_STOMP_RAW_STAT_RSTMASK                            0xffffffff
#define BTPRIORITY_STOMP_RAW_STAT_RESET                              0x00000000


#endif /* _BT_COEX_REG_H_ */
