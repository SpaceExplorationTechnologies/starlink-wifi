//                                                                             
// File:       ./pmu_reg_csr.vrh                                               
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:46:25 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             pmu_reg_csr.rdl                                                 
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/radio_peregrine/rtl/srif/blueprint/pmu_reg.rdl
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


#ifndef _PMU_REG_CSR_H_
#define _PMU_REG_CSR_H_
// 0x0000 (PMU1)
#define PMU1_SWREG_MSB                                               31
#define PMU1_SWREG_LSB                                               0
#define PMU1_SWREG_MASK                                              0xffffffff
#define PMU1_SWREG_GET(x)                                            (((x) & PMU1_SWREG_MASK) >> PMU1_SWREG_LSB)
#define PMU1_SWREG_SET(x)                                            (((0 | (x)) << PMU1_SWREG_LSB) & PMU1_SWREG_MASK)
#define PMU1_SWREG_RESET                                             805951696
#define PMU1_ADDRESS                                                 0x0000
#define PMU1_HW_MASK                                                 0xffffffff
#define PMU1_SW_MASK                                                 0xffffffff
#define PMU1_HW_WRITE_MASK                                           0x00000000
#define PMU1_SW_WRITE_MASK                                           0xffffffff
#define PMU1_RSTMASK                                                 0xffffffff
#define PMU1_RESET                                                   0x3009d8d0

// 0x0004 (PMU2)
#define PMU2_SWREGMSB_MSB                                            31
#define PMU2_SWREGMSB_LSB                                            22
#define PMU2_SWREGMSB_MASK                                           0xffc00000
#define PMU2_SWREGMSB_GET(x)                                         (((x) & PMU2_SWREGMSB_MASK) >> PMU2_SWREGMSB_LSB)
#define PMU2_SWREGMSB_SET(x)                                         (((0 | (x)) << PMU2_SWREGMSB_LSB) & PMU2_SWREGMSB_MASK)
#define PMU2_SWREGMSB_RESET                                          0
#define PMU2_PGM_MSB                                                 21
#define PMU2_PGM_LSB                                                 21
#define PMU2_PGM_MASK                                                0x00200000
#define PMU2_PGM_GET(x)                                              (((x) & PMU2_PGM_MASK) >> PMU2_PGM_LSB)
#define PMU2_PGM_SET(x)                                              (((0 | (x)) << PMU2_PGM_LSB) & PMU2_PGM_MASK)
#define PMU2_PGM_RESET                                               0
#define PMU2_PGM_BT_MSB                                              20
#define PMU2_PGM_BT_LSB                                              20
#define PMU2_PGM_BT_MASK                                             0x00100000
#define PMU2_PGM_BT_GET(x)                                           (((x) & PMU2_PGM_BT_MASK) >> PMU2_PGM_BT_LSB)
#define PMU2_PGM_BT_SET(x)                                           (((0 | (x)) << PMU2_PGM_BT_LSB) & PMU2_PGM_BT_MASK)
#define PMU2_PGM_BT_RESET                                            0
#define PMU2_SWREG_BT_MSB                                            19
#define PMU2_SWREG_BT_LSB                                            0
#define PMU2_SWREG_BT_MASK                                           0x000fffff
#define PMU2_SWREG_BT_GET(x)                                         (((x) & PMU2_SWREG_BT_MASK) >> PMU2_SWREG_BT_LSB)
#define PMU2_SWREG_BT_SET(x)                                         (((0 | (x)) << PMU2_SWREG_BT_LSB) & PMU2_SWREG_BT_MASK)
#define PMU2_SWREG_BT_RESET                                          645328
#define PMU2_ADDRESS                                                 0x0004
#define PMU2_HW_MASK                                                 0xffffffff
#define PMU2_SW_MASK                                                 0xffffffff
#define PMU2_HW_WRITE_MASK                                           0x00000000
#define PMU2_SW_WRITE_MASK                                           0xffffffff
#define PMU2_RSTMASK                                                 0xffffffff
#define PMU2_RESET                                                   0x0009d8d0

// 0x0008 (PMU3)
#define PMU3_SWREGMSB_BT_MSB                                         31
#define PMU3_SWREGMSB_BT_LSB                                         10
#define PMU3_SWREGMSB_BT_MASK                                        0xfffffc00
#define PMU3_SWREGMSB_BT_GET(x)                                      (((x) & PMU3_SWREGMSB_BT_MASK) >> PMU3_SWREGMSB_BT_LSB)
#define PMU3_SWREGMSB_BT_SET(x)                                      (((0 | (x)) << PMU3_SWREGMSB_BT_LSB) & PMU3_SWREGMSB_BT_MASK)
#define PMU3_SWREGMSB_BT_RESET                                       768
#define PMU3_USE_WLAN_BITS_MSB                                       9
#define PMU3_USE_WLAN_BITS_LSB                                       9
#define PMU3_USE_WLAN_BITS_MASK                                      0x00000200
#define PMU3_USE_WLAN_BITS_GET(x)                                    (((x) & PMU3_USE_WLAN_BITS_MASK) >> PMU3_USE_WLAN_BITS_LSB)
#define PMU3_USE_WLAN_BITS_SET(x)                                    (((0 | (x)) << PMU3_USE_WLAN_BITS_LSB) & PMU3_USE_WLAN_BITS_MASK)
#define PMU3_USE_WLAN_BITS_RESET                                     0
#define PMU3_SPARE_MSB                                               8
#define PMU3_SPARE_LSB                                               0
#define PMU3_SPARE_MASK                                              0x000001ff
#define PMU3_SPARE_GET(x)                                            (((x) & PMU3_SPARE_MASK) >> PMU3_SPARE_LSB)
#define PMU3_SPARE_SET(x)                                            (((0 | (x)) << PMU3_SPARE_LSB) & PMU3_SPARE_MASK)
#define PMU3_SPARE_RESET                                             0
#define PMU3_ADDRESS                                                 0x0008
#define PMU3_HW_MASK                                                 0xffffffff
#define PMU3_SW_MASK                                                 0xffffffff
#define PMU3_HW_WRITE_MASK                                           0x00000000
#define PMU3_SW_WRITE_MASK                                           0xffffffff
#define PMU3_RSTMASK                                                 0xffffffff
#define PMU3_RESET                                                   0x000c0000


#endif /* _PMU_REG_CSR_H_ */
