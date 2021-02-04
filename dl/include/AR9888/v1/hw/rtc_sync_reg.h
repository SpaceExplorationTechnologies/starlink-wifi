//                                                                             
// File:       ./rtc_sync_reg.vrh                                              
// Creator:    shung                                                           
// Time:       Monday Apr 23, 2012 [6:26:21 pm]                                
//                                                                             
// Path:       /trees/shung/shung-dev/chips/peregrine/1.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux/blueprint -odir . -codegen   
//             ath_vrh.codegen -ath_vrh -Wdesc -I                              
//             /trees/shung/shung-dev/chips/peregrine/1.0/blueprint/sysconfig  
//             rtc_sync_reg.rdl                                                
//                                                                             
// Sources:    /trees/shung/shung-dev/chips/peregrine/1.0/ip/athr/wifi/rtl/mac/rtl/dev/rtc_wmac/blueprint/rtc_sync_reg.rdl
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


#ifndef _RTC_SYNC_REG_H_
#define _RTC_SYNC_REG_H_
// 0x0240 (RTC_SYNC_RESET)
#define RTC_SYNC_RESET_RESET_L_MSB                                   0
#define RTC_SYNC_RESET_RESET_L_LSB                                   0
#define RTC_SYNC_RESET_RESET_L_MASK                                  0x00000001
#define RTC_SYNC_RESET_RESET_L_GET(x)                                (((x) & RTC_SYNC_RESET_RESET_L_MASK) >> RTC_SYNC_RESET_RESET_L_LSB)
#define RTC_SYNC_RESET_RESET_L_SET(x)                                (((0 | (x)) << RTC_SYNC_RESET_RESET_L_LSB) & RTC_SYNC_RESET_RESET_L_MASK)
#define RTC_SYNC_RESET_RESET_L_RESET                                 0
#define RTC_SYNC_RESET_ADDRESS                                       0x0240
#define RTC_SYNC_RESET_HW_MASK                                       0x00000001
#define RTC_SYNC_RESET_SW_MASK                                       0x00000001
#define RTC_SYNC_RESET_HW_WRITE_MASK                                 0x00000000
#define RTC_SYNC_RESET_SW_WRITE_MASK                                 0x00000001
#define RTC_SYNC_RESET_RSTMASK                                       0xffffffff
#define RTC_SYNC_RESET_RESET                                         0x00000000

// 0x0244 (RTC_SYNC_STATUS)
#define RTC_SYNC_STATUS_PLL_CHANGING_MSB                             5
#define RTC_SYNC_STATUS_PLL_CHANGING_LSB                             5
#define RTC_SYNC_STATUS_PLL_CHANGING_MASK                            0x00000020
#define RTC_SYNC_STATUS_PLL_CHANGING_GET(x)                          (((x) & RTC_SYNC_STATUS_PLL_CHANGING_MASK) >> RTC_SYNC_STATUS_PLL_CHANGING_LSB)
#define RTC_SYNC_STATUS_PLL_CHANGING_SET(x)                          (((0 | (x)) << RTC_SYNC_STATUS_PLL_CHANGING_LSB) & RTC_SYNC_STATUS_PLL_CHANGING_MASK)
#define RTC_SYNC_STATUS_PLL_CHANGING_RESET                           0
#define RTC_SYNC_STATUS_WRESET_MSB                                   4
#define RTC_SYNC_STATUS_WRESET_LSB                                   4
#define RTC_SYNC_STATUS_WRESET_MASK                                  0x00000010
#define RTC_SYNC_STATUS_WRESET_GET(x)                                (((x) & RTC_SYNC_STATUS_WRESET_MASK) >> RTC_SYNC_STATUS_WRESET_LSB)
#define RTC_SYNC_STATUS_WRESET_SET(x)                                (((0 | (x)) << RTC_SYNC_STATUS_WRESET_LSB) & RTC_SYNC_STATUS_WRESET_MASK)
#define RTC_SYNC_STATUS_WRESET_RESET                                 0
#define RTC_SYNC_STATUS_WAKEUP_STATE_MSB                             3
#define RTC_SYNC_STATUS_WAKEUP_STATE_LSB                             3
#define RTC_SYNC_STATUS_WAKEUP_STATE_MASK                            0x00000008
#define RTC_SYNC_STATUS_WAKEUP_STATE_GET(x)                          (((x) & RTC_SYNC_STATUS_WAKEUP_STATE_MASK) >> RTC_SYNC_STATUS_WAKEUP_STATE_LSB)
#define RTC_SYNC_STATUS_WAKEUP_STATE_SET(x)                          (((0 | (x)) << RTC_SYNC_STATUS_WAKEUP_STATE_LSB) & RTC_SYNC_STATUS_WAKEUP_STATE_MASK)
#define RTC_SYNC_STATUS_WAKEUP_STATE_RESET                           0
#define RTC_SYNC_STATUS_SLEEP_STATE_MSB                              2
#define RTC_SYNC_STATUS_SLEEP_STATE_LSB                              2
#define RTC_SYNC_STATUS_SLEEP_STATE_MASK                             0x00000004
#define RTC_SYNC_STATUS_SLEEP_STATE_GET(x)                           (((x) & RTC_SYNC_STATUS_SLEEP_STATE_MASK) >> RTC_SYNC_STATUS_SLEEP_STATE_LSB)
#define RTC_SYNC_STATUS_SLEEP_STATE_SET(x)                           (((0 | (x)) << RTC_SYNC_STATUS_SLEEP_STATE_LSB) & RTC_SYNC_STATUS_SLEEP_STATE_MASK)
#define RTC_SYNC_STATUS_SLEEP_STATE_RESET                            0
#define RTC_SYNC_STATUS_ON_STATE_MSB                                 1
#define RTC_SYNC_STATUS_ON_STATE_LSB                                 1
#define RTC_SYNC_STATUS_ON_STATE_MASK                                0x00000002
#define RTC_SYNC_STATUS_ON_STATE_GET(x)                              (((x) & RTC_SYNC_STATUS_ON_STATE_MASK) >> RTC_SYNC_STATUS_ON_STATE_LSB)
#define RTC_SYNC_STATUS_ON_STATE_SET(x)                              (((0 | (x)) << RTC_SYNC_STATUS_ON_STATE_LSB) & RTC_SYNC_STATUS_ON_STATE_MASK)
#define RTC_SYNC_STATUS_ON_STATE_RESET                               0
#define RTC_SYNC_STATUS_SHUTDOWN_STATE_MSB                           0
#define RTC_SYNC_STATUS_SHUTDOWN_STATE_LSB                           0
#define RTC_SYNC_STATUS_SHUTDOWN_STATE_MASK                          0x00000001
#define RTC_SYNC_STATUS_SHUTDOWN_STATE_GET(x)                        (((x) & RTC_SYNC_STATUS_SHUTDOWN_STATE_MASK) >> RTC_SYNC_STATUS_SHUTDOWN_STATE_LSB)
#define RTC_SYNC_STATUS_SHUTDOWN_STATE_SET(x)                        (((0 | (x)) << RTC_SYNC_STATUS_SHUTDOWN_STATE_LSB) & RTC_SYNC_STATUS_SHUTDOWN_STATE_MASK)
#define RTC_SYNC_STATUS_SHUTDOWN_STATE_RESET                         0
#define RTC_SYNC_STATUS_ADDRESS                                      0x0244
#define RTC_SYNC_STATUS_HW_MASK                                      0x0000003f
#define RTC_SYNC_STATUS_SW_MASK                                      0x0000003f
#define RTC_SYNC_STATUS_HW_WRITE_MASK                                0x0000003f
#define RTC_SYNC_STATUS_SW_WRITE_MASK                                0x00000000
#define RTC_SYNC_STATUS_RSTMASK                                      0xffffffff
#define RTC_SYNC_STATUS_RESET                                        0x00000000

// 0x0248 (RTC_SYNC_DERIVED)
#define RTC_SYNC_DERIVED_FORCE_LPO_PWD_MSB                           3
#define RTC_SYNC_DERIVED_FORCE_LPO_PWD_LSB                           3
#define RTC_SYNC_DERIVED_FORCE_LPO_PWD_MASK                          0x00000008
#define RTC_SYNC_DERIVED_FORCE_LPO_PWD_GET(x)                        (((x) & RTC_SYNC_DERIVED_FORCE_LPO_PWD_MASK) >> RTC_SYNC_DERIVED_FORCE_LPO_PWD_LSB)
#define RTC_SYNC_DERIVED_FORCE_LPO_PWD_SET(x)                        (((0 | (x)) << RTC_SYNC_DERIVED_FORCE_LPO_PWD_LSB) & RTC_SYNC_DERIVED_FORCE_LPO_PWD_MASK)
#define RTC_SYNC_DERIVED_FORCE_LPO_PWD_RESET                         0
#define RTC_SYNC_DERIVED_FORCE_SWREG_PWD_MSB                         2
#define RTC_SYNC_DERIVED_FORCE_SWREG_PWD_LSB                         2
#define RTC_SYNC_DERIVED_FORCE_SWREG_PWD_MASK                        0x00000004
#define RTC_SYNC_DERIVED_FORCE_SWREG_PWD_GET(x)                      (((x) & RTC_SYNC_DERIVED_FORCE_SWREG_PWD_MASK) >> RTC_SYNC_DERIVED_FORCE_SWREG_PWD_LSB)
#define RTC_SYNC_DERIVED_FORCE_SWREG_PWD_SET(x)                      (((0 | (x)) << RTC_SYNC_DERIVED_FORCE_SWREG_PWD_LSB) & RTC_SYNC_DERIVED_FORCE_SWREG_PWD_MASK)
#define RTC_SYNC_DERIVED_FORCE_SWREG_PWD_RESET                       0
#define RTC_SYNC_DERIVED_FORCE_MSB                                   1
#define RTC_SYNC_DERIVED_FORCE_LSB                                   1
#define RTC_SYNC_DERIVED_FORCE_MASK                                  0x00000002
#define RTC_SYNC_DERIVED_FORCE_GET(x)                                (((x) & RTC_SYNC_DERIVED_FORCE_MASK) >> RTC_SYNC_DERIVED_FORCE_LSB)
#define RTC_SYNC_DERIVED_FORCE_SET(x)                                (((0 | (x)) << RTC_SYNC_DERIVED_FORCE_LSB) & RTC_SYNC_DERIVED_FORCE_MASK)
#define RTC_SYNC_DERIVED_FORCE_RESET                                 0
#define RTC_SYNC_DERIVED_BYPASS_MSB                                  0
#define RTC_SYNC_DERIVED_BYPASS_LSB                                  0
#define RTC_SYNC_DERIVED_BYPASS_MASK                                 0x00000001
#define RTC_SYNC_DERIVED_BYPASS_GET(x)                               (((x) & RTC_SYNC_DERIVED_BYPASS_MASK) >> RTC_SYNC_DERIVED_BYPASS_LSB)
#define RTC_SYNC_DERIVED_BYPASS_SET(x)                               (((0 | (x)) << RTC_SYNC_DERIVED_BYPASS_LSB) & RTC_SYNC_DERIVED_BYPASS_MASK)
#define RTC_SYNC_DERIVED_BYPASS_RESET                                0
#define RTC_SYNC_DERIVED_ADDRESS                                     0x0248
#define RTC_SYNC_DERIVED_HW_MASK                                     0x0000000f
#define RTC_SYNC_DERIVED_SW_MASK                                     0x0000000f
#define RTC_SYNC_DERIVED_HW_WRITE_MASK                               0x00000000
#define RTC_SYNC_DERIVED_SW_WRITE_MASK                               0x0000000f
#define RTC_SYNC_DERIVED_RSTMASK                                     0xffffffff
#define RTC_SYNC_DERIVED_RESET                                       0x00000000

// 0x024c (RTC_SYNC_FORCE_WAKE)
#define RTC_SYNC_FORCE_WAKE_LEGACY_MODE_MSB                          3
#define RTC_SYNC_FORCE_WAKE_LEGACY_MODE_LSB                          3
#define RTC_SYNC_FORCE_WAKE_LEGACY_MODE_MASK                         0x00000008
#define RTC_SYNC_FORCE_WAKE_LEGACY_MODE_GET(x)                       (((x) & RTC_SYNC_FORCE_WAKE_LEGACY_MODE_MASK) >> RTC_SYNC_FORCE_WAKE_LEGACY_MODE_LSB)
#define RTC_SYNC_FORCE_WAKE_LEGACY_MODE_SET(x)                       (((0 | (x)) << RTC_SYNC_FORCE_WAKE_LEGACY_MODE_LSB) & RTC_SYNC_FORCE_WAKE_LEGACY_MODE_MASK)
#define RTC_SYNC_FORCE_WAKE_LEGACY_MODE_RESET                        0
#define RTC_SYNC_FORCE_WAKE_STATE_MSB                                2
#define RTC_SYNC_FORCE_WAKE_STATE_LSB                                2
#define RTC_SYNC_FORCE_WAKE_STATE_MASK                               0x00000004
#define RTC_SYNC_FORCE_WAKE_STATE_GET(x)                             (((x) & RTC_SYNC_FORCE_WAKE_STATE_MASK) >> RTC_SYNC_FORCE_WAKE_STATE_LSB)
#define RTC_SYNC_FORCE_WAKE_STATE_SET(x)                             (((0 | (x)) << RTC_SYNC_FORCE_WAKE_STATE_LSB) & RTC_SYNC_FORCE_WAKE_STATE_MASK)
#define RTC_SYNC_FORCE_WAKE_STATE_RESET                              0
#define RTC_SYNC_FORCE_WAKE_INTR_MSB                                 1
#define RTC_SYNC_FORCE_WAKE_INTR_LSB                                 1
#define RTC_SYNC_FORCE_WAKE_INTR_MASK                                0x00000002
#define RTC_SYNC_FORCE_WAKE_INTR_GET(x)                              (((x) & RTC_SYNC_FORCE_WAKE_INTR_MASK) >> RTC_SYNC_FORCE_WAKE_INTR_LSB)
#define RTC_SYNC_FORCE_WAKE_INTR_SET(x)                              (((0 | (x)) << RTC_SYNC_FORCE_WAKE_INTR_LSB) & RTC_SYNC_FORCE_WAKE_INTR_MASK)
#define RTC_SYNC_FORCE_WAKE_INTR_RESET                               1
#define RTC_SYNC_FORCE_WAKE_ENABLE_MSB                               0
#define RTC_SYNC_FORCE_WAKE_ENABLE_LSB                               0
#define RTC_SYNC_FORCE_WAKE_ENABLE_MASK                              0x00000001
#define RTC_SYNC_FORCE_WAKE_ENABLE_GET(x)                            (((x) & RTC_SYNC_FORCE_WAKE_ENABLE_MASK) >> RTC_SYNC_FORCE_WAKE_ENABLE_LSB)
#define RTC_SYNC_FORCE_WAKE_ENABLE_SET(x)                            (((0 | (x)) << RTC_SYNC_FORCE_WAKE_ENABLE_LSB) & RTC_SYNC_FORCE_WAKE_ENABLE_MASK)
#define RTC_SYNC_FORCE_WAKE_ENABLE_RESET                             0
#define RTC_SYNC_FORCE_WAKE_ADDRESS                                  0x024c
#define RTC_SYNC_FORCE_WAKE_HW_MASK                                  0x0000000f
#define RTC_SYNC_FORCE_WAKE_SW_MASK                                  0x0000000f
#define RTC_SYNC_FORCE_WAKE_HW_WRITE_MASK                            0x00000005
#define RTC_SYNC_FORCE_WAKE_SW_WRITE_MASK                            0x0000000a
#define RTC_SYNC_FORCE_WAKE_RSTMASK                                  0xffffffff
#define RTC_SYNC_FORCE_WAKE_RESET                                    0x00000002

// 0x0250 (RTC_SYNC_INTR_CAUSE)
#define RTC_SYNC_INTR_CAUSE_PLL_CHANGING_MSB                         5
#define RTC_SYNC_INTR_CAUSE_PLL_CHANGING_LSB                         5
#define RTC_SYNC_INTR_CAUSE_PLL_CHANGING_MASK                        0x00000020
#define RTC_SYNC_INTR_CAUSE_PLL_CHANGING_GET(x)                      (((x) & RTC_SYNC_INTR_CAUSE_PLL_CHANGING_MASK) >> RTC_SYNC_INTR_CAUSE_PLL_CHANGING_LSB)
#define RTC_SYNC_INTR_CAUSE_PLL_CHANGING_SET(x)                      (((0 | (x)) << RTC_SYNC_INTR_CAUSE_PLL_CHANGING_LSB) & RTC_SYNC_INTR_CAUSE_PLL_CHANGING_MASK)
#define RTC_SYNC_INTR_CAUSE_PLL_CHANGING_RESET                       0
#define RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_MSB                         4
#define RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_LSB                         4
#define RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_MASK                        0x00000010
#define RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_GET(x)                      (((x) & RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_MASK) >> RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_LSB)
#define RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_SET(x)                      (((0 | (x)) << RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_LSB) & RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_MASK)
#define RTC_SYNC_INTR_CAUSE_SLEEP_ACCESS_RESET                       0
#define RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_MSB                         3
#define RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_LSB                         3
#define RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_MASK                        0x00000008
#define RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_GET(x)                      (((x) & RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_MASK) >> RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_LSB)
#define RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_SET(x)                      (((0 | (x)) << RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_LSB) & RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_MASK)
#define RTC_SYNC_INTR_CAUSE_WAKEUP_STATE_RESET                       0
#define RTC_SYNC_INTR_CAUSE_SLEEP_STATE_MSB                          2
#define RTC_SYNC_INTR_CAUSE_SLEEP_STATE_LSB                          2
#define RTC_SYNC_INTR_CAUSE_SLEEP_STATE_MASK                         0x00000004
#define RTC_SYNC_INTR_CAUSE_SLEEP_STATE_GET(x)                       (((x) & RTC_SYNC_INTR_CAUSE_SLEEP_STATE_MASK) >> RTC_SYNC_INTR_CAUSE_SLEEP_STATE_LSB)
#define RTC_SYNC_INTR_CAUSE_SLEEP_STATE_SET(x)                       (((0 | (x)) << RTC_SYNC_INTR_CAUSE_SLEEP_STATE_LSB) & RTC_SYNC_INTR_CAUSE_SLEEP_STATE_MASK)
#define RTC_SYNC_INTR_CAUSE_SLEEP_STATE_RESET                        0
#define RTC_SYNC_INTR_CAUSE_ON_STATE_MSB                             1
#define RTC_SYNC_INTR_CAUSE_ON_STATE_LSB                             1
#define RTC_SYNC_INTR_CAUSE_ON_STATE_MASK                            0x00000002
#define RTC_SYNC_INTR_CAUSE_ON_STATE_GET(x)                          (((x) & RTC_SYNC_INTR_CAUSE_ON_STATE_MASK) >> RTC_SYNC_INTR_CAUSE_ON_STATE_LSB)
#define RTC_SYNC_INTR_CAUSE_ON_STATE_SET(x)                          (((0 | (x)) << RTC_SYNC_INTR_CAUSE_ON_STATE_LSB) & RTC_SYNC_INTR_CAUSE_ON_STATE_MASK)
#define RTC_SYNC_INTR_CAUSE_ON_STATE_RESET                           0
#define RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_MSB                       0
#define RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_LSB                       0
#define RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_MASK                      0x00000001
#define RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_GET(x)                    (((x) & RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_MASK) >> RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_LSB)
#define RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_SET(x)                    (((0 | (x)) << RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_LSB) & RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_MASK)
#define RTC_SYNC_INTR_CAUSE_SHUTDOWN_STATE_RESET                     0
#define RTC_SYNC_INTR_CAUSE_ADDRESS                                  0x0250
#define RTC_SYNC_INTR_CAUSE_HW_MASK                                  0x0000003f
#define RTC_SYNC_INTR_CAUSE_SW_MASK                                  0x0000003f
#define RTC_SYNC_INTR_CAUSE_HW_WRITE_MASK                            0x0000003f
#define RTC_SYNC_INTR_CAUSE_SW_WRITE_MASK                            0x0000003f
#define RTC_SYNC_INTR_CAUSE_RSTMASK                                  0xffffffc0
#define RTC_SYNC_INTR_CAUSE_RESET                                    0x00000000

// 0x0254 (RTC_SYNC_INTR_ENABLE)
#define RTC_SYNC_INTR_ENABLE_PLL_CHANGING_MSB                        5
#define RTC_SYNC_INTR_ENABLE_PLL_CHANGING_LSB                        5
#define RTC_SYNC_INTR_ENABLE_PLL_CHANGING_MASK                       0x00000020
#define RTC_SYNC_INTR_ENABLE_PLL_CHANGING_GET(x)                     (((x) & RTC_SYNC_INTR_ENABLE_PLL_CHANGING_MASK) >> RTC_SYNC_INTR_ENABLE_PLL_CHANGING_LSB)
#define RTC_SYNC_INTR_ENABLE_PLL_CHANGING_SET(x)                     (((0 | (x)) << RTC_SYNC_INTR_ENABLE_PLL_CHANGING_LSB) & RTC_SYNC_INTR_ENABLE_PLL_CHANGING_MASK)
#define RTC_SYNC_INTR_ENABLE_PLL_CHANGING_RESET                      0
#define RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_MSB                        4
#define RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_LSB                        4
#define RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_MASK                       0x00000010
#define RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_GET(x)                     (((x) & RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_MASK) >> RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_LSB)
#define RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_SET(x)                     (((0 | (x)) << RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_LSB) & RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_MASK)
#define RTC_SYNC_INTR_ENABLE_SLEEP_ACCESS_RESET                      0
#define RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_MSB                        3
#define RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_LSB                        3
#define RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_MASK                       0x00000008
#define RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_GET(x)                     (((x) & RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_MASK) >> RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_LSB)
#define RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_SET(x)                     (((0 | (x)) << RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_LSB) & RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_MASK)
#define RTC_SYNC_INTR_ENABLE_WAKEUP_STATE_RESET                      0
#define RTC_SYNC_INTR_ENABLE_SLEEP_STATE_MSB                         2
#define RTC_SYNC_INTR_ENABLE_SLEEP_STATE_LSB                         2
#define RTC_SYNC_INTR_ENABLE_SLEEP_STATE_MASK                        0x00000004
#define RTC_SYNC_INTR_ENABLE_SLEEP_STATE_GET(x)                      (((x) & RTC_SYNC_INTR_ENABLE_SLEEP_STATE_MASK) >> RTC_SYNC_INTR_ENABLE_SLEEP_STATE_LSB)
#define RTC_SYNC_INTR_ENABLE_SLEEP_STATE_SET(x)                      (((0 | (x)) << RTC_SYNC_INTR_ENABLE_SLEEP_STATE_LSB) & RTC_SYNC_INTR_ENABLE_SLEEP_STATE_MASK)
#define RTC_SYNC_INTR_ENABLE_SLEEP_STATE_RESET                       0
#define RTC_SYNC_INTR_ENABLE_ON_STATE_MSB                            1
#define RTC_SYNC_INTR_ENABLE_ON_STATE_LSB                            1
#define RTC_SYNC_INTR_ENABLE_ON_STATE_MASK                           0x00000002
#define RTC_SYNC_INTR_ENABLE_ON_STATE_GET(x)                         (((x) & RTC_SYNC_INTR_ENABLE_ON_STATE_MASK) >> RTC_SYNC_INTR_ENABLE_ON_STATE_LSB)
#define RTC_SYNC_INTR_ENABLE_ON_STATE_SET(x)                         (((0 | (x)) << RTC_SYNC_INTR_ENABLE_ON_STATE_LSB) & RTC_SYNC_INTR_ENABLE_ON_STATE_MASK)
#define RTC_SYNC_INTR_ENABLE_ON_STATE_RESET                          0
#define RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_MSB                      0
#define RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_LSB                      0
#define RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_MASK                     0x00000001
#define RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_GET(x)                   (((x) & RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_MASK) >> RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_LSB)
#define RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_SET(x)                   (((0 | (x)) << RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_LSB) & RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_MASK)
#define RTC_SYNC_INTR_ENABLE_SHUTDOWN_STATE_RESET                    0
#define RTC_SYNC_INTR_ENABLE_ADDRESS                                 0x0254
#define RTC_SYNC_INTR_ENABLE_HW_MASK                                 0x0000003f
#define RTC_SYNC_INTR_ENABLE_SW_MASK                                 0x0000003f
#define RTC_SYNC_INTR_ENABLE_HW_WRITE_MASK                           0x00000000
#define RTC_SYNC_INTR_ENABLE_SW_WRITE_MASK                           0x0000003f
#define RTC_SYNC_INTR_ENABLE_RSTMASK                                 0xffffffff
#define RTC_SYNC_INTR_ENABLE_RESET                                   0x00000000

// 0x0258 (RTC_SYNC_INTR_MASK)
#define RTC_SYNC_INTR_MASK_PLL_CHANGING_MSB                          5
#define RTC_SYNC_INTR_MASK_PLL_CHANGING_LSB                          5
#define RTC_SYNC_INTR_MASK_PLL_CHANGING_MASK                         0x00000020
#define RTC_SYNC_INTR_MASK_PLL_CHANGING_GET(x)                       (((x) & RTC_SYNC_INTR_MASK_PLL_CHANGING_MASK) >> RTC_SYNC_INTR_MASK_PLL_CHANGING_LSB)
#define RTC_SYNC_INTR_MASK_PLL_CHANGING_SET(x)                       (((0 | (x)) << RTC_SYNC_INTR_MASK_PLL_CHANGING_LSB) & RTC_SYNC_INTR_MASK_PLL_CHANGING_MASK)
#define RTC_SYNC_INTR_MASK_PLL_CHANGING_RESET                        0
#define RTC_SYNC_INTR_MASK_SLEEP_ACCESS_MSB                          4
#define RTC_SYNC_INTR_MASK_SLEEP_ACCESS_LSB                          4
#define RTC_SYNC_INTR_MASK_SLEEP_ACCESS_MASK                         0x00000010
#define RTC_SYNC_INTR_MASK_SLEEP_ACCESS_GET(x)                       (((x) & RTC_SYNC_INTR_MASK_SLEEP_ACCESS_MASK) >> RTC_SYNC_INTR_MASK_SLEEP_ACCESS_LSB)
#define RTC_SYNC_INTR_MASK_SLEEP_ACCESS_SET(x)                       (((0 | (x)) << RTC_SYNC_INTR_MASK_SLEEP_ACCESS_LSB) & RTC_SYNC_INTR_MASK_SLEEP_ACCESS_MASK)
#define RTC_SYNC_INTR_MASK_SLEEP_ACCESS_RESET                        0
#define RTC_SYNC_INTR_MASK_WAKEUP_STATE_MSB                          3
#define RTC_SYNC_INTR_MASK_WAKEUP_STATE_LSB                          3
#define RTC_SYNC_INTR_MASK_WAKEUP_STATE_MASK                         0x00000008
#define RTC_SYNC_INTR_MASK_WAKEUP_STATE_GET(x)                       (((x) & RTC_SYNC_INTR_MASK_WAKEUP_STATE_MASK) >> RTC_SYNC_INTR_MASK_WAKEUP_STATE_LSB)
#define RTC_SYNC_INTR_MASK_WAKEUP_STATE_SET(x)                       (((0 | (x)) << RTC_SYNC_INTR_MASK_WAKEUP_STATE_LSB) & RTC_SYNC_INTR_MASK_WAKEUP_STATE_MASK)
#define RTC_SYNC_INTR_MASK_WAKEUP_STATE_RESET                        0
#define RTC_SYNC_INTR_MASK_SLEEP_STATE_MSB                           2
#define RTC_SYNC_INTR_MASK_SLEEP_STATE_LSB                           2
#define RTC_SYNC_INTR_MASK_SLEEP_STATE_MASK                          0x00000004
#define RTC_SYNC_INTR_MASK_SLEEP_STATE_GET(x)                        (((x) & RTC_SYNC_INTR_MASK_SLEEP_STATE_MASK) >> RTC_SYNC_INTR_MASK_SLEEP_STATE_LSB)
#define RTC_SYNC_INTR_MASK_SLEEP_STATE_SET(x)                        (((0 | (x)) << RTC_SYNC_INTR_MASK_SLEEP_STATE_LSB) & RTC_SYNC_INTR_MASK_SLEEP_STATE_MASK)
#define RTC_SYNC_INTR_MASK_SLEEP_STATE_RESET                         0
#define RTC_SYNC_INTR_MASK_ON_STATE_MSB                              1
#define RTC_SYNC_INTR_MASK_ON_STATE_LSB                              1
#define RTC_SYNC_INTR_MASK_ON_STATE_MASK                             0x00000002
#define RTC_SYNC_INTR_MASK_ON_STATE_GET(x)                           (((x) & RTC_SYNC_INTR_MASK_ON_STATE_MASK) >> RTC_SYNC_INTR_MASK_ON_STATE_LSB)
#define RTC_SYNC_INTR_MASK_ON_STATE_SET(x)                           (((0 | (x)) << RTC_SYNC_INTR_MASK_ON_STATE_LSB) & RTC_SYNC_INTR_MASK_ON_STATE_MASK)
#define RTC_SYNC_INTR_MASK_ON_STATE_RESET                            0
#define RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_MSB                        0
#define RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_LSB                        0
#define RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_MASK                       0x00000001
#define RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_GET(x)                     (((x) & RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_MASK) >> RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_LSB)
#define RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_SET(x)                     (((0 | (x)) << RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_LSB) & RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_MASK)
#define RTC_SYNC_INTR_MASK_SHUTDOWN_STATE_RESET                      0
#define RTC_SYNC_INTR_MASK_ADDRESS                                   0x0258
#define RTC_SYNC_INTR_MASK_HW_MASK                                   0x0000003f
#define RTC_SYNC_INTR_MASK_SW_MASK                                   0x0000003f
#define RTC_SYNC_INTR_MASK_HW_WRITE_MASK                             0x00000000
#define RTC_SYNC_INTR_MASK_SW_WRITE_MASK                             0x0000003f
#define RTC_SYNC_INTR_MASK_RSTMASK                                   0xffffffff
#define RTC_SYNC_INTR_MASK_RESET                                     0x00000000


#endif /* _RTC_SYNC_REG_H_ */
