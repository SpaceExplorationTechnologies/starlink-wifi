//                                                                             
// File:       ./pcie_local_reg.vrh                                            
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:45:39 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             pcie_local_reg.rdl                                              
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/rtl/wlan/pcie_wrap/blueprint/pcie_local_reg.rdl
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    sjod-chinghwa                                                   
// OS:         Linux 2.6.18-308.8.2.el5                                        
// Description:                                                                
//                                                                             
// No Description Provided                                                     
/*
 * Copyright (c) 2012-14 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */


#ifndef _PCIE_LOCAL_REG_H_
#define _PCIE_LOCAL_REG_H_
// 0x0000 (RTC_STATE)
#define RTC_STATE_COLD_RESET_MSB                                     10
#define RTC_STATE_COLD_RESET_LSB                                     10
#define RTC_STATE_COLD_RESET_MASK                                    0x00000400
#define RTC_STATE_COLD_RESET_GET(x)                                  (((x) & RTC_STATE_COLD_RESET_MASK) >> RTC_STATE_COLD_RESET_LSB)
#define RTC_STATE_COLD_RESET_SET(x)                                  (((0 | (x)) << RTC_STATE_COLD_RESET_LSB) & RTC_STATE_COLD_RESET_MASK)
#define RTC_STATE_COLD_RESET_RESET                                   0
#define RTC_STATE_XTAL_COUNT_MSB                                     9
#define RTC_STATE_XTAL_COUNT_LSB                                     3
#define RTC_STATE_XTAL_COUNT_MASK                                    0x000003f8
#define RTC_STATE_XTAL_COUNT_GET(x)                                  (((x) & RTC_STATE_XTAL_COUNT_MASK) >> RTC_STATE_XTAL_COUNT_LSB)
#define RTC_STATE_XTAL_COUNT_SET(x)                                  (((0 | (x)) << RTC_STATE_XTAL_COUNT_LSB) & RTC_STATE_XTAL_COUNT_MASK)
#define RTC_STATE_XTAL_COUNT_RESET                                   0
#define RTC_STATE_V_MSB                                              2
#define RTC_STATE_V_LSB                                              0
#define RTC_STATE_V_MASK                                             0x00000007
#define RTC_STATE_V_GET(x)                                           (((x) & RTC_STATE_V_MASK) >> RTC_STATE_V_LSB)
#define RTC_STATE_V_SET(x)                                           (((0 | (x)) << RTC_STATE_V_LSB) & RTC_STATE_V_MASK)
#define RTC_STATE_V_RESET                                            0
#define RTC_STATE_ADDRESS                                            0x0000
#define RTC_STATE_HW_MASK                                            0x000007ff
#define RTC_STATE_SW_MASK                                            0x000007ff
#define RTC_STATE_HW_WRITE_MASK                                      0x000007ff
#define RTC_STATE_SW_WRITE_MASK                                      0x00000000
#define RTC_STATE_RSTMASK                                            0xffffffff
#define RTC_STATE_RESET                                              0x00000000

// 0x0004 (PCIE_SOC_WAKE)
#define PCIE_SOC_WAKE_V_MSB                                          0
#define PCIE_SOC_WAKE_V_LSB                                          0
#define PCIE_SOC_WAKE_V_MASK                                         0x00000001
#define PCIE_SOC_WAKE_V_GET(x)                                       (((x) & PCIE_SOC_WAKE_V_MASK) >> PCIE_SOC_WAKE_V_LSB)
#define PCIE_SOC_WAKE_V_SET(x)                                       (((0 | (x)) << PCIE_SOC_WAKE_V_LSB) & PCIE_SOC_WAKE_V_MASK)
#define PCIE_SOC_WAKE_V_RESET                                        0
#define PCIE_SOC_WAKE_ADDRESS                                        0x0004
#define PCIE_SOC_WAKE_HW_MASK                                        0x00000001
#define PCIE_SOC_WAKE_SW_MASK                                        0x00000001
#define PCIE_SOC_WAKE_HW_WRITE_MASK                                  0x00000000
#define PCIE_SOC_WAKE_SW_WRITE_MASK                                  0x00000001
#define PCIE_SOC_WAKE_RSTMASK                                        0xffffffff
#define PCIE_SOC_WAKE_RESET                                          0x00000000

// 0x0008 (SOC_GLOBAL_RESET)
#define SOC_GLOBAL_RESET_V_MSB                                       0
#define SOC_GLOBAL_RESET_V_LSB                                       0
#define SOC_GLOBAL_RESET_V_MASK                                      0x00000001
#define SOC_GLOBAL_RESET_V_GET(x)                                    (((x) & SOC_GLOBAL_RESET_V_MASK) >> SOC_GLOBAL_RESET_V_LSB)
#define SOC_GLOBAL_RESET_V_SET(x)                                    (((0 | (x)) << SOC_GLOBAL_RESET_V_LSB) & SOC_GLOBAL_RESET_V_MASK)
#define SOC_GLOBAL_RESET_V_RESET                                     0
#define SOC_GLOBAL_RESET_ADDRESS                                     0x0008
#define SOC_GLOBAL_RESET_HW_MASK                                     0x00000001
#define SOC_GLOBAL_RESET_SW_MASK                                     0x00000001
#define SOC_GLOBAL_RESET_HW_WRITE_MASK                               0x00000000
#define SOC_GLOBAL_RESET_SW_WRITE_MASK                               0x00000001
#define SOC_GLOBAL_RESET_RSTMASK                                     0xffffffff
#define SOC_GLOBAL_RESET_RESET                                       0x00000000

// 0x000c (PCIE_OBS1)
#define PCIE_OBS1_V_MSB                                              17
#define PCIE_OBS1_V_LSB                                              0
#define PCIE_OBS1_V_MASK                                             0x0003ffff
#define PCIE_OBS1_V_GET(x)                                           (((x) & PCIE_OBS1_V_MASK) >> PCIE_OBS1_V_LSB)
#define PCIE_OBS1_V_SET(x)                                           (((0 | (x)) << PCIE_OBS1_V_LSB) & PCIE_OBS1_V_MASK)
#define PCIE_OBS1_V_RESET                                            0
#define PCIE_OBS1_ADDRESS                                            0x000c
#define PCIE_OBS1_HW_MASK                                            0x0003ffff
#define PCIE_OBS1_SW_MASK                                            0x0003ffff
#define PCIE_OBS1_HW_WRITE_MASK                                      0x0003ffff
#define PCIE_OBS1_SW_WRITE_MASK                                      0x00000000
#define PCIE_OBS1_RSTMASK                                            0xffffffff
#define PCIE_OBS1_RESET                                              0x00000000

// 0x0010 (PCIE_OBS2)
#define PCIE_OBS2_V_MSB                                              17
#define PCIE_OBS2_V_LSB                                              0
#define PCIE_OBS2_V_MASK                                             0x0003ffff
#define PCIE_OBS2_V_GET(x)                                           (((x) & PCIE_OBS2_V_MASK) >> PCIE_OBS2_V_LSB)
#define PCIE_OBS2_V_SET(x)                                           (((0 | (x)) << PCIE_OBS2_V_LSB) & PCIE_OBS2_V_MASK)
#define PCIE_OBS2_V_RESET                                            0
#define PCIE_OBS2_ADDRESS                                            0x0010
#define PCIE_OBS2_HW_MASK                                            0x0003ffff
#define PCIE_OBS2_SW_MASK                                            0x0003ffff
#define PCIE_OBS2_HW_WRITE_MASK                                      0x0003ffff
#define PCIE_OBS2_SW_WRITE_MASK                                      0x00000000
#define PCIE_OBS2_RSTMASK                                            0xffffffff
#define PCIE_OBS2_RESET                                              0x00000000

// 0x0014 (PCIE_OBS3)
#define PCIE_OBS3_V_MSB                                              17
#define PCIE_OBS3_V_LSB                                              0
#define PCIE_OBS3_V_MASK                                             0x0003ffff
#define PCIE_OBS3_V_GET(x)                                           (((x) & PCIE_OBS3_V_MASK) >> PCIE_OBS3_V_LSB)
#define PCIE_OBS3_V_SET(x)                                           (((0 | (x)) << PCIE_OBS3_V_LSB) & PCIE_OBS3_V_MASK)
#define PCIE_OBS3_V_RESET                                            0
#define PCIE_OBS3_ADDRESS                                            0x0014
#define PCIE_OBS3_HW_MASK                                            0x0003ffff
#define PCIE_OBS3_SW_MASK                                            0x0003ffff
#define PCIE_OBS3_HW_WRITE_MASK                                      0x0003ffff
#define PCIE_OBS3_SW_WRITE_MASK                                      0x00000000
#define PCIE_OBS3_RSTMASK                                            0xffffffff
#define PCIE_OBS3_RESET                                              0x00000000

// 0x0018 (PCIE_OBS4)
#define PCIE_OBS4_V_MSB                                              17
#define PCIE_OBS4_V_LSB                                              0
#define PCIE_OBS4_V_MASK                                             0x0003ffff
#define PCIE_OBS4_V_GET(x)                                           (((x) & PCIE_OBS4_V_MASK) >> PCIE_OBS4_V_LSB)
#define PCIE_OBS4_V_SET(x)                                           (((0 | (x)) << PCIE_OBS4_V_LSB) & PCIE_OBS4_V_MASK)
#define PCIE_OBS4_V_RESET                                            0
#define PCIE_OBS4_ADDRESS                                            0x0018
#define PCIE_OBS4_HW_MASK                                            0x0003ffff
#define PCIE_OBS4_SW_MASK                                            0x0003ffff
#define PCIE_OBS4_HW_WRITE_MASK                                      0x0003ffff
#define PCIE_OBS4_SW_WRITE_MASK                                      0x00000000
#define PCIE_OBS4_RSTMASK                                            0xffffffff
#define PCIE_OBS4_RESET                                              0x00000000

// 0x001c (AXI_SLAVE_RD_OBS)
#define AXI_SLAVE_RD_OBS_V_MSB                                       17
#define AXI_SLAVE_RD_OBS_V_LSB                                       0
#define AXI_SLAVE_RD_OBS_V_MASK                                      0x0003ffff
#define AXI_SLAVE_RD_OBS_V_GET(x)                                    (((x) & AXI_SLAVE_RD_OBS_V_MASK) >> AXI_SLAVE_RD_OBS_V_LSB)
#define AXI_SLAVE_RD_OBS_V_SET(x)                                    (((0 | (x)) << AXI_SLAVE_RD_OBS_V_LSB) & AXI_SLAVE_RD_OBS_V_MASK)
#define AXI_SLAVE_RD_OBS_V_RESET                                     0
#define AXI_SLAVE_RD_OBS_ADDRESS                                     0x001c
#define AXI_SLAVE_RD_OBS_HW_MASK                                     0x0003ffff
#define AXI_SLAVE_RD_OBS_SW_MASK                                     0x0003ffff
#define AXI_SLAVE_RD_OBS_HW_WRITE_MASK                               0x0003ffff
#define AXI_SLAVE_RD_OBS_SW_WRITE_MASK                               0x00000000
#define AXI_SLAVE_RD_OBS_RSTMASK                                     0xffffffff
#define AXI_SLAVE_RD_OBS_RESET                                       0x00000000

// 0x0020 (AXI_SLAVE_WR_OBS)
#define AXI_SLAVE_WR_OBS_V_MSB                                       17
#define AXI_SLAVE_WR_OBS_V_LSB                                       0
#define AXI_SLAVE_WR_OBS_V_MASK                                      0x0003ffff
#define AXI_SLAVE_WR_OBS_V_GET(x)                                    (((x) & AXI_SLAVE_WR_OBS_V_MASK) >> AXI_SLAVE_WR_OBS_V_LSB)
#define AXI_SLAVE_WR_OBS_V_SET(x)                                    (((0 | (x)) << AXI_SLAVE_WR_OBS_V_LSB) & AXI_SLAVE_WR_OBS_V_MASK)
#define AXI_SLAVE_WR_OBS_V_RESET                                     0
#define AXI_SLAVE_WR_OBS_ADDRESS                                     0x0020
#define AXI_SLAVE_WR_OBS_HW_MASK                                     0x0003ffff
#define AXI_SLAVE_WR_OBS_SW_MASK                                     0x0003ffff
#define AXI_SLAVE_WR_OBS_HW_WRITE_MASK                               0x0003ffff
#define AXI_SLAVE_WR_OBS_SW_WRITE_MASK                               0x00000000
#define AXI_SLAVE_WR_OBS_RSTMASK                                     0xffffffff
#define AXI_SLAVE_WR_OBS_RESET                                       0x00000000


#endif /* _PCIE_LOCAL_REG_H_ */
