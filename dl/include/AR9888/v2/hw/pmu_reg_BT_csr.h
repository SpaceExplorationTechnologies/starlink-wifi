//                                                                             
// File:       ./pmu_reg_BT_csr.vrh                                            
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:46:01 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             pmu_reg_BT_csr.rdl                                              
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/radio_peregrine/rtl/srif/blueprint/pmu_reg_BT.rdl
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


#ifndef _PMU_REG_BT_CSR_H_
#define _PMU_REG_BT_CSR_H_
// 0x0000 (BT_PMU1)
#define BT_PMU1_SWREG_MSB                                            31
#define BT_PMU1_SWREG_LSB                                            0
#define BT_PMU1_SWREG_MASK                                           0xffffffff
#define BT_PMU1_SWREG_GET(x)                                         (((x) & BT_PMU1_SWREG_MASK) >> BT_PMU1_SWREG_LSB)
#define BT_PMU1_SWREG_SET(x)                                         (((0 | (x)) << BT_PMU1_SWREG_LSB) & BT_PMU1_SWREG_MASK)
#define BT_PMU1_SWREG_RESET                                          805951696
#define BT_PMU1_ADDRESS                                              0x0000
#define BT_PMU1_HW_MASK                                              0xffffffff
#define BT_PMU1_SW_MASK                                              0xffffffff
#define BT_PMU1_HW_WRITE_MASK                                        0x00000000
#define BT_PMU1_SW_WRITE_MASK                                        0xffffffff
#define BT_PMU1_RSTMASK                                              0xffffffff
#define BT_PMU1_RESET                                                0x3009d8d0

// 0x0004 (BT_PMU2)
#define BT_PMU2_SWREGMSB_MSB                                         31
#define BT_PMU2_SWREGMSB_LSB                                         22
#define BT_PMU2_SWREGMSB_MASK                                        0xffc00000
#define BT_PMU2_SWREGMSB_GET(x)                                      (((x) & BT_PMU2_SWREGMSB_MASK) >> BT_PMU2_SWREGMSB_LSB)
#define BT_PMU2_SWREGMSB_SET(x)                                      (((0 | (x)) << BT_PMU2_SWREGMSB_LSB) & BT_PMU2_SWREGMSB_MASK)
#define BT_PMU2_SWREGMSB_RESET                                       0
#define BT_PMU2_PGM_MSB                                              21
#define BT_PMU2_PGM_LSB                                              21
#define BT_PMU2_PGM_MASK                                             0x00200000
#define BT_PMU2_PGM_GET(x)                                           (((x) & BT_PMU2_PGM_MASK) >> BT_PMU2_PGM_LSB)
#define BT_PMU2_PGM_SET(x)                                           (((0 | (x)) << BT_PMU2_PGM_LSB) & BT_PMU2_PGM_MASK)
#define BT_PMU2_PGM_RESET                                            0
#define BT_PMU2_DISC_BIT_LOCAL_MSB                                   20
#define BT_PMU2_DISC_BIT_LOCAL_LSB                                   20
#define BT_PMU2_DISC_BIT_LOCAL_MASK                                  0x00100000
#define BT_PMU2_DISC_BIT_LOCAL_GET(x)                                (((x) & BT_PMU2_DISC_BIT_LOCAL_MASK) >> BT_PMU2_DISC_BIT_LOCAL_LSB)
#define BT_PMU2_DISC_BIT_LOCAL_SET(x)                                (((0 | (x)) << BT_PMU2_DISC_BIT_LOCAL_LSB) & BT_PMU2_DISC_BIT_LOCAL_MASK)
#define BT_PMU2_DISC_BIT_LOCAL_RESET                                 0
#define BT_PMU2_SPARE_MSB                                            19
#define BT_PMU2_SPARE_LSB                                            0
#define BT_PMU2_SPARE_MASK                                           0x000fffff
#define BT_PMU2_SPARE_GET(x)                                         (((x) & BT_PMU2_SPARE_MASK) >> BT_PMU2_SPARE_LSB)
#define BT_PMU2_SPARE_SET(x)                                         (((0 | (x)) << BT_PMU2_SPARE_LSB) & BT_PMU2_SPARE_MASK)
#define BT_PMU2_SPARE_RESET                                          0
#define BT_PMU2_ADDRESS                                              0x0004
#define BT_PMU2_HW_MASK                                              0xffffffff
#define BT_PMU2_SW_MASK                                              0xffffffff
#define BT_PMU2_HW_WRITE_MASK                                        0x00000000
#define BT_PMU2_SW_WRITE_MASK                                        0xffffffff
#define BT_PMU2_RSTMASK                                              0xffffffff
#define BT_PMU2_RESET                                                0x00000000


#endif /* _PMU_REG_BT_CSR_H_ */
