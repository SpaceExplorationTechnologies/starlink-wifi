//                                                                             
// File:       ./dpll_reg_csr.vrh                                              
// Creator:    shung                                                           
// Time:       Monday Apr 23, 2012 [6:25:47 pm]                                
//                                                                             
// Path:       /trees/shung/shung-dev/chips/peregrine/1.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux/blueprint -odir . -codegen   
//             ath_vrh.codegen -ath_vrh -Wdesc -I                              
//             /trees/shung/shung-dev/chips/peregrine/1.0/blueprint/sysconfig  
//             dpll_reg_csr.rdl                                                
//                                                                             
// Sources:    /trees/shung/shung-dev/chips/peregrine/1.0/ip/radio_peregrine/rtl/srif/blueprint/dpll_reg.rdl
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


#ifndef _DPLL_REG_CSR_H_
#define _DPLL_REG_CSR_H_
// 0x0000 (DPLL1)
#define DPLL1_REFDIV_MSB                                             31
#define DPLL1_REFDIV_LSB                                             27
#define DPLL1_REFDIV_MASK                                            0xf8000000
#define DPLL1_REFDIV_GET(x)                                          (((x) & DPLL1_REFDIV_MASK) >> DPLL1_REFDIV_LSB)
#define DPLL1_REFDIV_SET(x)                                          (((0 | (x)) << DPLL1_REFDIV_LSB) & DPLL1_REFDIV_MASK)
#define DPLL1_REFDIV_RESET                                           1
#define DPLL1_NINT_MSB                                               26
#define DPLL1_NINT_LSB                                               18
#define DPLL1_NINT_MASK                                              0x07fc0000
#define DPLL1_NINT_GET(x)                                            (((x) & DPLL1_NINT_MASK) >> DPLL1_NINT_LSB)
#define DPLL1_NINT_SET(x)                                            (((0 | (x)) << DPLL1_NINT_LSB) & DPLL1_NINT_MASK)
#define DPLL1_NINT_RESET                                             16
#define DPLL1_NFRAC_MSB                                              17
#define DPLL1_NFRAC_LSB                                              0
#define DPLL1_NFRAC_MASK                                             0x0003ffff
#define DPLL1_NFRAC_GET(x)                                           (((x) & DPLL1_NFRAC_MASK) >> DPLL1_NFRAC_LSB)
#define DPLL1_NFRAC_SET(x)                                           (((0 | (x)) << DPLL1_NFRAC_LSB) & DPLL1_NFRAC_MASK)
#define DPLL1_NFRAC_RESET                                            0
#define DPLL1_ADDRESS                                                0x0000
#define DPLL1_HW_MASK                                                0xffffffff
#define DPLL1_SW_MASK                                                0xffffffff
#define DPLL1_HW_WRITE_MASK                                          0x00000000
#define DPLL1_SW_WRITE_MASK                                          0xffffffff
#define DPLL1_RSTMASK                                                0xffffffff
#define DPLL1_RESET                                                  0x08400000

// 0x0004 (DPLL2)
#define DPLL2_LOCAL_PLL_MSB                                          31
#define DPLL2_LOCAL_PLL_LSB                                          31
#define DPLL2_LOCAL_PLL_MASK                                         0x80000000
#define DPLL2_LOCAL_PLL_GET(x)                                       (((x) & DPLL2_LOCAL_PLL_MASK) >> DPLL2_LOCAL_PLL_LSB)
#define DPLL2_LOCAL_PLL_SET(x)                                       (((0 | (x)) << DPLL2_LOCAL_PLL_LSB) & DPLL2_LOCAL_PLL_MASK)
#define DPLL2_LOCAL_PLL_RESET                                        0
#define DPLL2_KI_MSB                                                 30
#define DPLL2_KI_LSB                                                 29
#define DPLL2_KI_MASK                                                0x60000000
#define DPLL2_KI_GET(x)                                              (((x) & DPLL2_KI_MASK) >> DPLL2_KI_LSB)
#define DPLL2_KI_SET(x)                                              (((0 | (x)) << DPLL2_KI_LSB) & DPLL2_KI_MASK)
#define DPLL2_KI_RESET                                               2
#define DPLL2_KD_MSB                                                 28
#define DPLL2_KD_LSB                                                 25
#define DPLL2_KD_MASK                                                0x1e000000
#define DPLL2_KD_GET(x)                                              (((x) & DPLL2_KD_MASK) >> DPLL2_KD_LSB)
#define DPLL2_KD_SET(x)                                              (((0 | (x)) << DPLL2_KD_LSB) & DPLL2_KD_MASK)
#define DPLL2_KD_RESET                                               10
#define DPLL2_EN_NEGTRIG_MSB                                         24
#define DPLL2_EN_NEGTRIG_LSB                                         24
#define DPLL2_EN_NEGTRIG_MASK                                        0x01000000
#define DPLL2_EN_NEGTRIG_GET(x)                                      (((x) & DPLL2_EN_NEGTRIG_MASK) >> DPLL2_EN_NEGTRIG_LSB)
#define DPLL2_EN_NEGTRIG_SET(x)                                      (((0 | (x)) << DPLL2_EN_NEGTRIG_LSB) & DPLL2_EN_NEGTRIG_MASK)
#define DPLL2_EN_NEGTRIG_RESET                                       0
#define DPLL2_SEL_1SDM_MSB                                           23
#define DPLL2_SEL_1SDM_LSB                                           23
#define DPLL2_SEL_1SDM_MASK                                          0x00800000
#define DPLL2_SEL_1SDM_GET(x)                                        (((x) & DPLL2_SEL_1SDM_MASK) >> DPLL2_SEL_1SDM_LSB)
#define DPLL2_SEL_1SDM_SET(x)                                        (((0 | (x)) << DPLL2_SEL_1SDM_LSB) & DPLL2_SEL_1SDM_MASK)
#define DPLL2_SEL_1SDM_RESET                                         0
#define DPLL2_PLL_PWD_MSB                                            22
#define DPLL2_PLL_PWD_LSB                                            22
#define DPLL2_PLL_PWD_MASK                                           0x00400000
#define DPLL2_PLL_PWD_GET(x)                                         (((x) & DPLL2_PLL_PWD_MASK) >> DPLL2_PLL_PWD_LSB)
#define DPLL2_PLL_PWD_SET(x)                                         (((0 | (x)) << DPLL2_PLL_PWD_LSB) & DPLL2_PLL_PWD_MASK)
#define DPLL2_PLL_PWD_RESET                                          1
#define DPLL2_OUTDIV_MSB                                             21
#define DPLL2_OUTDIV_LSB                                             19
#define DPLL2_OUTDIV_MASK                                            0x00380000
#define DPLL2_OUTDIV_GET(x)                                          (((x) & DPLL2_OUTDIV_MASK) >> DPLL2_OUTDIV_LSB)
#define DPLL2_OUTDIV_SET(x)                                          (((0 | (x)) << DPLL2_OUTDIV_LSB) & DPLL2_OUTDIV_MASK)
#define DPLL2_OUTDIV_RESET                                           1
#define DPLL2_PHASE_SHIFT_MSB                                        18
#define DPLL2_PHASE_SHIFT_LSB                                        12
#define DPLL2_PHASE_SHIFT_MASK                                       0x0007f000
#define DPLL2_PHASE_SHIFT_GET(x)                                     (((x) & DPLL2_PHASE_SHIFT_MASK) >> DPLL2_PHASE_SHIFT_LSB)
#define DPLL2_PHASE_SHIFT_SET(x)                                     (((0 | (x)) << DPLL2_PHASE_SHIFT_LSB) & DPLL2_PHASE_SHIFT_MASK)
#define DPLL2_PHASE_SHIFT_RESET                                      0
#define DPLL2_TESTIN_MSB                                             11
#define DPLL2_TESTIN_LSB                                             2
#define DPLL2_TESTIN_MASK                                            0x00000ffc
#define DPLL2_TESTIN_GET(x)                                          (((x) & DPLL2_TESTIN_MASK) >> DPLL2_TESTIN_LSB)
#define DPLL2_TESTIN_SET(x)                                          (((0 | (x)) << DPLL2_TESTIN_LSB) & DPLL2_TESTIN_MASK)
#define DPLL2_TESTIN_RESET                                           0
#define DPLL2_SEL_COUNT_MSB                                          1
#define DPLL2_SEL_COUNT_LSB                                          1
#define DPLL2_SEL_COUNT_MASK                                         0x00000002
#define DPLL2_SEL_COUNT_GET(x)                                       (((x) & DPLL2_SEL_COUNT_MASK) >> DPLL2_SEL_COUNT_LSB)
#define DPLL2_SEL_COUNT_SET(x)                                       (((0 | (x)) << DPLL2_SEL_COUNT_LSB) & DPLL2_SEL_COUNT_MASK)
#define DPLL2_SEL_COUNT_RESET                                        0
#define DPLL2_RESET_TEST_MSB                                         0
#define DPLL2_RESET_TEST_LSB                                         0
#define DPLL2_RESET_TEST_MASK                                        0x00000001
#define DPLL2_RESET_TEST_GET(x)                                      (((x) & DPLL2_RESET_TEST_MASK) >> DPLL2_RESET_TEST_LSB)
#define DPLL2_RESET_TEST_SET(x)                                      (((0 | (x)) << DPLL2_RESET_TEST_LSB) & DPLL2_RESET_TEST_MASK)
#define DPLL2_RESET_TEST_RESET                                       0
#define DPLL2_ADDRESS                                                0x0004
#define DPLL2_HW_MASK                                                0xffffffff
#define DPLL2_SW_MASK                                                0xffffffff
#define DPLL2_HW_WRITE_MASK                                          0x00000000
#define DPLL2_SW_WRITE_MASK                                          0xffffffff
#define DPLL2_RSTMASK                                                0xffffffff
#define DPLL2_RESET                                                  0x54480000

// 0x0008 (DPLL3)
#define DPLL3_DO_MEAS_MSB                                            31
#define DPLL3_DO_MEAS_LSB                                            31
#define DPLL3_DO_MEAS_MASK                                           0x80000000
#define DPLL3_DO_MEAS_GET(x)                                         (((x) & DPLL3_DO_MEAS_MASK) >> DPLL3_DO_MEAS_LSB)
#define DPLL3_DO_MEAS_SET(x)                                         (((0 | (x)) << DPLL3_DO_MEAS_LSB) & DPLL3_DO_MEAS_MASK)
#define DPLL3_DO_MEAS_RESET                                          0
#define DPLL3_VC_MEAS0_MSB                                           30
#define DPLL3_VC_MEAS0_LSB                                           13
#define DPLL3_VC_MEAS0_MASK                                          0x7fffe000
#define DPLL3_VC_MEAS0_GET(x)                                        (((x) & DPLL3_VC_MEAS0_MASK) >> DPLL3_VC_MEAS0_LSB)
#define DPLL3_VC_MEAS0_SET(x)                                        (((0 | (x)) << DPLL3_VC_MEAS0_LSB) & DPLL3_VC_MEAS0_MASK)
#define DPLL3_VC_MEAS0_RESET                                         0
#define DPLL3_VC_DIFF0_MSB                                           12
#define DPLL3_VC_DIFF0_LSB                                           3
#define DPLL3_VC_DIFF0_MASK                                          0x00001ff8
#define DPLL3_VC_DIFF0_GET(x)                                        (((x) & DPLL3_VC_DIFF0_MASK) >> DPLL3_VC_DIFF0_LSB)
#define DPLL3_VC_DIFF0_SET(x)                                        (((0 | (x)) << DPLL3_VC_DIFF0_LSB) & DPLL3_VC_DIFF0_MASK)
#define DPLL3_VC_DIFF0_RESET                                         0
#define DPLL3_LOCAL_PLL_PWD_MSB                                      2
#define DPLL3_LOCAL_PLL_PWD_LSB                                      2
#define DPLL3_LOCAL_PLL_PWD_MASK                                     0x00000004
#define DPLL3_LOCAL_PLL_PWD_GET(x)                                   (((x) & DPLL3_LOCAL_PLL_PWD_MASK) >> DPLL3_LOCAL_PLL_PWD_LSB)
#define DPLL3_LOCAL_PLL_PWD_SET(x)                                   (((0 | (x)) << DPLL3_LOCAL_PLL_PWD_LSB) & DPLL3_LOCAL_PLL_PWD_MASK)
#define DPLL3_LOCAL_PLL_PWD_RESET                                    0
#define DPLL3_SPARE_MSB                                              1
#define DPLL3_SPARE_LSB                                              0
#define DPLL3_SPARE_MASK                                             0x00000003
#define DPLL3_SPARE_GET(x)                                           (((x) & DPLL3_SPARE_MASK) >> DPLL3_SPARE_LSB)
#define DPLL3_SPARE_SET(x)                                           (((0 | (x)) << DPLL3_SPARE_LSB) & DPLL3_SPARE_MASK)
#define DPLL3_SPARE_RESET                                            0
#define DPLL3_ADDRESS                                                0x0008
#define DPLL3_HW_MASK                                                0xffffffff
#define DPLL3_SW_MASK                                                0xffffffff
#define DPLL3_HW_WRITE_MASK                                          0x7ffffff8
#define DPLL3_SW_WRITE_MASK                                          0x80000007
#define DPLL3_RSTMASK                                                0xffffffff
#define DPLL3_RESET                                                  0x00000000


#endif /* _DPLL_REG_CSR_H_ */
