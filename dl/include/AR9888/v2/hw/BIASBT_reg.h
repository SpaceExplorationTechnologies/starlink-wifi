//                                                                             
// File:       ./BIASBT_reg_csr.vrh                                            
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:42:07 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             BIASBT_reg_csr.rdl                                              
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/radio_peregrine/rtl/srif/blueprint/BIASBT_reg.rdl
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


#ifndef _BIASBT_REG_CSR_H_
#define _BIASBT_REG_CSR_H_
// 0x0000 (BIASBT1)
#define BIASBT1_BIAS_SEL_MSB                                         31
#define BIASBT1_BIAS_SEL_LSB                                         25
#define BIASBT1_BIAS_SEL_MASK                                        0xfe000000
#define BIASBT1_BIAS_SEL_GET(x)                                      (((x) & BIASBT1_BIAS_SEL_MASK) >> BIASBT1_BIAS_SEL_LSB)
#define BIASBT1_BIAS_SEL_SET(x)                                      (((0 | (x)) << BIASBT1_BIAS_SEL_LSB) & BIASBT1_BIAS_SEL_MASK)
#define BIASBT1_BIAS_SEL_RESET                                       0
#define BIASBT1_SEL_IR25SYN_MSB                                      24
#define BIASBT1_SEL_IR25SYN_LSB                                      24
#define BIASBT1_SEL_IR25SYN_MASK                                     0x01000000
#define BIASBT1_SEL_IR25SYN_GET(x)                                   (((x) & BIASBT1_SEL_IR25SYN_MASK) >> BIASBT1_SEL_IR25SYN_LSB)
#define BIASBT1_SEL_IR25SYN_SET(x)                                   (((0 | (x)) << BIASBT1_SEL_IR25SYN_LSB) & BIASBT1_SEL_IR25SYN_MASK)
#define BIASBT1_SEL_IR25SYN_RESET                                    0
#define BIASBT1_SEL_IR25SAR_MSB                                      23
#define BIASBT1_SEL_IR25SAR_LSB                                      23
#define BIASBT1_SEL_IR25SAR_MASK                                     0x00800000
#define BIASBT1_SEL_IR25SAR_GET(x)                                   (((x) & BIASBT1_SEL_IR25SAR_MASK) >> BIASBT1_SEL_IR25SAR_LSB)
#define BIASBT1_SEL_IR25SAR_SET(x)                                   (((0 | (x)) << BIASBT1_SEL_IR25SAR_LSB) & BIASBT1_SEL_IR25SAR_MASK)
#define BIASBT1_SEL_IR25SAR_RESET                                    0
#define BIASBT1_SEL_IC25TESTIQ_MSB                                   22
#define BIASBT1_SEL_IC25TESTIQ_LSB                                   22
#define BIASBT1_SEL_IC25TESTIQ_MASK                                  0x00400000
#define BIASBT1_SEL_IC25TESTIQ_GET(x)                                (((x) & BIASBT1_SEL_IC25TESTIQ_MASK) >> BIASBT1_SEL_IC25TESTIQ_LSB)
#define BIASBT1_SEL_IC25TESTIQ_SET(x)                                (((0 | (x)) << BIASBT1_SEL_IC25TESTIQ_LSB) & BIASBT1_SEL_IC25TESTIQ_MASK)
#define BIASBT1_SEL_IC25TESTIQ_RESET                                 0
#define BIASBT1_ICBIASCALTOATB_MSB                                   21
#define BIASBT1_ICBIASCALTOATB_LSB                                   21
#define BIASBT1_ICBIASCALTOATB_MASK                                  0x00200000
#define BIASBT1_ICBIASCALTOATB_GET(x)                                (((x) & BIASBT1_ICBIASCALTOATB_MASK) >> BIASBT1_ICBIASCALTOATB_LSB)
#define BIASBT1_ICBIASCALTOATB_SET(x)                                (((0 | (x)) << BIASBT1_ICBIASCALTOATB_LSB) & BIASBT1_ICBIASCALTOATB_MASK)
#define BIASBT1_ICBIASCALTOATB_RESET                                 0
#define BIASBT1_CGM_ICSEL_MSB                                        20
#define BIASBT1_CGM_ICSEL_LSB                                        17
#define BIASBT1_CGM_ICSEL_MASK                                       0x001e0000
#define BIASBT1_CGM_ICSEL_GET(x)                                     (((x) & BIASBT1_CGM_ICSEL_MASK) >> BIASBT1_CGM_ICSEL_LSB)
#define BIASBT1_CGM_ICSEL_SET(x)                                     (((0 | (x)) << BIASBT1_CGM_ICSEL_LSB) & BIASBT1_CGM_ICSEL_MASK)
#define BIASBT1_CGM_ICSEL_RESET                                      4
#define BIASBT1_CGM_IGSEL_MSB                                        16
#define BIASBT1_CGM_IGSEL_LSB                                        13
#define BIASBT1_CGM_IGSEL_MASK                                       0x0001e000
#define BIASBT1_CGM_IGSEL_GET(x)                                     (((x) & BIASBT1_CGM_IGSEL_MASK) >> BIASBT1_CGM_IGSEL_LSB)
#define BIASBT1_CGM_IGSEL_SET(x)                                     (((0 | (x)) << BIASBT1_CGM_IGSEL_LSB) & BIASBT1_CGM_IGSEL_MASK)
#define BIASBT1_CGM_IGSEL_RESET                                      4
#define BIASBT1_PWD_IC25ADC_MSB                                      12
#define BIASBT1_PWD_IC25ADC_LSB                                      10
#define BIASBT1_PWD_IC25ADC_MASK                                     0x00001c00
#define BIASBT1_PWD_IC25ADC_GET(x)                                   (((x) & BIASBT1_PWD_IC25ADC_MASK) >> BIASBT1_PWD_IC25ADC_LSB)
#define BIASBT1_PWD_IC25ADC_SET(x)                                   (((0 | (x)) << BIASBT1_PWD_IC25ADC_LSB) & BIASBT1_PWD_IC25ADC_MASK)
#define BIASBT1_PWD_IC25ADC_RESET                                    3
#define BIASBT1_PWD_IC25CGM_MSB                                      9
#define BIASBT1_PWD_IC25CGM_LSB                                      7
#define BIASBT1_PWD_IC25CGM_MASK                                     0x00000380
#define BIASBT1_PWD_IC25CGM_GET(x)                                   (((x) & BIASBT1_PWD_IC25CGM_MASK) >> BIASBT1_PWD_IC25CGM_LSB)
#define BIASBT1_PWD_IC25CGM_SET(x)                                   (((0 | (x)) << BIASBT1_PWD_IC25CGM_LSB) & BIASBT1_PWD_IC25CGM_MASK)
#define BIASBT1_PWD_IC25CGM_RESET                                    3
#define BIASBT1_PWD_IC25PLLCP2_MSB                                   6
#define BIASBT1_PWD_IC25PLLCP2_LSB                                   4
#define BIASBT1_PWD_IC25PLLCP2_MASK                                  0x00000070
#define BIASBT1_PWD_IC25PLLCP2_GET(x)                                (((x) & BIASBT1_PWD_IC25PLLCP2_MASK) >> BIASBT1_PWD_IC25PLLCP2_LSB)
#define BIASBT1_PWD_IC25PLLCP2_SET(x)                                (((0 | (x)) << BIASBT1_PWD_IC25PLLCP2_LSB) & BIASBT1_PWD_IC25PLLCP2_MASK)
#define BIASBT1_PWD_IC25PLLCP2_RESET                                 3
#define BIASBT1_PWD_IC25PLLCP_MSB                                    3
#define BIASBT1_PWD_IC25PLLCP_LSB                                    1
#define BIASBT1_PWD_IC25PLLCP_MASK                                   0x0000000e
#define BIASBT1_PWD_IC25PLLCP_GET(x)                                 (((x) & BIASBT1_PWD_IC25PLLCP_MASK) >> BIASBT1_PWD_IC25PLLCP_LSB)
#define BIASBT1_PWD_IC25PLLCP_SET(x)                                 (((0 | (x)) << BIASBT1_PWD_IC25PLLCP_LSB) & BIASBT1_PWD_IC25PLLCP_MASK)
#define BIASBT1_PWD_IC25PLLCP_RESET                                  3
#define BIASBT1_SPARE1_MSB                                           0
#define BIASBT1_SPARE1_LSB                                           0
#define BIASBT1_SPARE1_MASK                                          0x00000001
#define BIASBT1_SPARE1_GET(x)                                        (((x) & BIASBT1_SPARE1_MASK) >> BIASBT1_SPARE1_LSB)
#define BIASBT1_SPARE1_SET(x)                                        (((0 | (x)) << BIASBT1_SPARE1_LSB) & BIASBT1_SPARE1_MASK)
#define BIASBT1_SPARE1_RESET                                         0
#define BIASBT1_ADDRESS                                              0x0000
#define BIASBT1_HW_MASK                                              0xffffffff
#define BIASBT1_SW_MASK                                              0xffffffff
#define BIASBT1_HW_WRITE_MASK                                        0x00000000
#define BIASBT1_SW_WRITE_MASK                                        0xffffffff
#define BIASBT1_RSTMASK                                              0xffffffff
#define BIASBT1_RESET                                                0x00088db6

// 0x0004 (BIASBT2)
#define BIASBT2_PWD_IC25PLLGM_MSB                                    31
#define BIASBT2_PWD_IC25PLLGM_LSB                                    29
#define BIASBT2_PWD_IC25PLLGM_MASK                                   0xe0000000
#define BIASBT2_PWD_IC25PLLGM_GET(x)                                 (((x) & BIASBT2_PWD_IC25PLLGM_MASK) >> BIASBT2_PWD_IC25PLLGM_LSB)
#define BIASBT2_PWD_IC25PLLGM_SET(x)                                 (((0 | (x)) << BIASBT2_PWD_IC25PLLGM_LSB) & BIASBT2_PWD_IC25PLLGM_MASK)
#define BIASBT2_PWD_IC25PLLGM_RESET                                  3
#define BIASBT2_PWD_IC25PLLREG_MSB                                   28
#define BIASBT2_PWD_IC25PLLREG_LSB                                   26
#define BIASBT2_PWD_IC25PLLREG_MASK                                  0x1c000000
#define BIASBT2_PWD_IC25PLLREG_GET(x)                                (((x) & BIASBT2_PWD_IC25PLLREG_MASK) >> BIASBT2_PWD_IC25PLLREG_LSB)
#define BIASBT2_PWD_IC25PLLREG_SET(x)                                (((0 | (x)) << BIASBT2_PWD_IC25PLLREG_LSB) & BIASBT2_PWD_IC25PLLREG_MASK)
#define BIASBT2_PWD_IC25PLLREG_RESET                                 3
#define BIASBT2_PWD_IC25RXFILTI_MSB                                  25
#define BIASBT2_PWD_IC25RXFILTI_LSB                                  23
#define BIASBT2_PWD_IC25RXFILTI_MASK                                 0x03800000
#define BIASBT2_PWD_IC25RXFILTI_GET(x)                               (((x) & BIASBT2_PWD_IC25RXFILTI_MASK) >> BIASBT2_PWD_IC25RXFILTI_LSB)
#define BIASBT2_PWD_IC25RXFILTI_SET(x)                               (((0 | (x)) << BIASBT2_PWD_IC25RXFILTI_LSB) & BIASBT2_PWD_IC25RXFILTI_MASK)
#define BIASBT2_PWD_IC25RXFILTI_RESET                                3
#define BIASBT2_PWD_IC25RXFILTQ_MSB                                  22
#define BIASBT2_PWD_IC25RXFILTQ_LSB                                  20
#define BIASBT2_PWD_IC25RXFILTQ_MASK                                 0x00700000
#define BIASBT2_PWD_IC25RXFILTQ_GET(x)                               (((x) & BIASBT2_PWD_IC25RXFILTQ_MASK) >> BIASBT2_PWD_IC25RXFILTQ_LSB)
#define BIASBT2_PWD_IC25RXFILTQ_SET(x)                               (((0 | (x)) << BIASBT2_PWD_IC25RXFILTQ_LSB) & BIASBT2_PWD_IC25RXFILTQ_MASK)
#define BIASBT2_PWD_IC25RXFILTQ_RESET                                3
#define BIASBT2_PWD_IC25RXMIX_MSB                                    19
#define BIASBT2_PWD_IC25RXMIX_LSB                                    17
#define BIASBT2_PWD_IC25RXMIX_MASK                                   0x000e0000
#define BIASBT2_PWD_IC25RXMIX_GET(x)                                 (((x) & BIASBT2_PWD_IC25RXMIX_MASK) >> BIASBT2_PWD_IC25RXMIX_LSB)
#define BIASBT2_PWD_IC25RXMIX_SET(x)                                 (((0 | (x)) << BIASBT2_PWD_IC25RXMIX_LSB) & BIASBT2_PWD_IC25RXMIX_MASK)
#define BIASBT2_PWD_IC25RXMIX_RESET                                  3
#define BIASBT2_PWD_IC25PABT_MSB                                     16
#define BIASBT2_PWD_IC25PABT_LSB                                     14
#define BIASBT2_PWD_IC25PABT_MASK                                    0x0001c000
#define BIASBT2_PWD_IC25PABT_GET(x)                                  (((x) & BIASBT2_PWD_IC25PABT_MASK) >> BIASBT2_PWD_IC25PABT_LSB)
#define BIASBT2_PWD_IC25PABT_SET(x)                                  (((0 | (x)) << BIASBT2_PWD_IC25PABT_LSB) & BIASBT2_PWD_IC25PABT_MASK)
#define BIASBT2_PWD_IC25PABT_RESET                                   3
#define BIASBT2_PWD_IC25UAIC_MSB                                     13
#define BIASBT2_PWD_IC25UAIC_LSB                                     11
#define BIASBT2_PWD_IC25UAIC_MASK                                    0x00003800
#define BIASBT2_PWD_IC25UAIC_GET(x)                                  (((x) & BIASBT2_PWD_IC25UAIC_MASK) >> BIASBT2_PWD_IC25UAIC_LSB)
#define BIASBT2_PWD_IC25UAIC_SET(x)                                  (((0 | (x)) << BIASBT2_PWD_IC25UAIC_LSB) & BIASBT2_PWD_IC25UAIC_MASK)
#define BIASBT2_PWD_IC25UAIC_RESET                                   3
#define BIASBT2_PWD_IC25XTAL_MSB                                     10
#define BIASBT2_PWD_IC25XTAL_LSB                                     8
#define BIASBT2_PWD_IC25XTAL_MASK                                    0x00000700
#define BIASBT2_PWD_IC25XTAL_GET(x)                                  (((x) & BIASBT2_PWD_IC25XTAL_MASK) >> BIASBT2_PWD_IC25XTAL_LSB)
#define BIASBT2_PWD_IC25XTAL_SET(x)                                  (((0 | (x)) << BIASBT2_PWD_IC25XTAL_LSB) & BIASBT2_PWD_IC25XTAL_MASK)
#define BIASBT2_PWD_IC25XTAL_RESET                                   3
#define BIASBT2_PWD_IC25XTALREG_MSB                                  7
#define BIASBT2_PWD_IC25XTALREG_LSB                                  5
#define BIASBT2_PWD_IC25XTALREG_MASK                                 0x000000e0
#define BIASBT2_PWD_IC25XTALREG_GET(x)                               (((x) & BIASBT2_PWD_IC25XTALREG_MASK) >> BIASBT2_PWD_IC25XTALREG_LSB)
#define BIASBT2_PWD_IC25XTALREG_SET(x)                               (((0 | (x)) << BIASBT2_PWD_IC25XTALREG_LSB) & BIASBT2_PWD_IC25XTALREG_MASK)
#define BIASBT2_PWD_IC25XTALREG_RESET                                3
#define BIASBT2_PWD_ICG50LNA_MSB                                     4
#define BIASBT2_PWD_ICG50LNA_LSB                                     2
#define BIASBT2_PWD_ICG50LNA_MASK                                    0x0000001c
#define BIASBT2_PWD_ICG50LNA_GET(x)                                  (((x) & BIASBT2_PWD_ICG50LNA_MASK) >> BIASBT2_PWD_ICG50LNA_LSB)
#define BIASBT2_PWD_ICG50LNA_SET(x)                                  (((0 | (x)) << BIASBT2_PWD_ICG50LNA_LSB) & BIASBT2_PWD_ICG50LNA_MASK)
#define BIASBT2_PWD_ICG50LNA_RESET                                   3
#define BIASBT2_SPARE2_MSB                                           1
#define BIASBT2_SPARE2_LSB                                           0
#define BIASBT2_SPARE2_MASK                                          0x00000003
#define BIASBT2_SPARE2_GET(x)                                        (((x) & BIASBT2_SPARE2_MASK) >> BIASBT2_SPARE2_LSB)
#define BIASBT2_SPARE2_SET(x)                                        (((0 | (x)) << BIASBT2_SPARE2_LSB) & BIASBT2_SPARE2_MASK)
#define BIASBT2_SPARE2_RESET                                         0
#define BIASBT2_ADDRESS                                              0x0004
#define BIASBT2_HW_MASK                                              0xffffffff
#define BIASBT2_SW_MASK                                              0xffffffff
#define BIASBT2_HW_WRITE_MASK                                        0x00000000
#define BIASBT2_SW_WRITE_MASK                                        0xffffffff
#define BIASBT2_RSTMASK                                              0xffffffff
#define BIASBT2_RESET                                                0x6db6db6c

// 0x0008 (BIASBT3)
#define BIASBT3_PWD_IC50DAC_MSB                                      31
#define BIASBT3_PWD_IC50DAC_LSB                                      29
#define BIASBT3_PWD_IC50DAC_MASK                                     0xe0000000
#define BIASBT3_PWD_IC50DAC_GET(x)                                   (((x) & BIASBT3_PWD_IC50DAC_MASK) >> BIASBT3_PWD_IC50DAC_LSB)
#define BIASBT3_PWD_IC50DAC_SET(x)                                   (((0 | (x)) << BIASBT3_PWD_IC50DAC_LSB) & BIASBT3_PWD_IC50DAC_MASK)
#define BIASBT3_PWD_IC50DAC_RESET                                    3
#define BIASBT3_PWD_IC50V2I_MSB                                      28
#define BIASBT3_PWD_IC50V2I_LSB                                      26
#define BIASBT3_PWD_IC50V2I_MASK                                     0x1c000000
#define BIASBT3_PWD_IC50V2I_GET(x)                                   (((x) & BIASBT3_PWD_IC50V2I_MASK) >> BIASBT3_PWD_IC50V2I_LSB)
#define BIASBT3_PWD_IC50V2I_SET(x)                                   (((0 | (x)) << BIASBT3_PWD_IC50V2I_LSB) & BIASBT3_PWD_IC50V2I_MASK)
#define BIASBT3_PWD_IC50V2I_RESET                                    3
#define BIASBT3_PWD_IC25TEMPSEN_MSB                                  25
#define BIASBT3_PWD_IC25TEMPSEN_LSB                                  23
#define BIASBT3_PWD_IC25TEMPSEN_MASK                                 0x03800000
#define BIASBT3_PWD_IC25TEMPSEN_GET(x)                               (((x) & BIASBT3_PWD_IC25TEMPSEN_MASK) >> BIASBT3_PWD_IC25TEMPSEN_LSB)
#define BIASBT3_PWD_IC25TEMPSEN_SET(x)                               (((0 | (x)) << BIASBT3_PWD_IC25TEMPSEN_LSB) & BIASBT3_PWD_IC25TEMPSEN_MASK)
#define BIASBT3_PWD_IC25TEMPSEN_RESET                                3
#define BIASBT3_PWD_IC25SYNTH_MSB                                    22
#define BIASBT3_PWD_IC25SYNTH_LSB                                    20
#define BIASBT3_PWD_IC25SYNTH_MASK                                   0x00700000
#define BIASBT3_PWD_IC25SYNTH_GET(x)                                 (((x) & BIASBT3_PWD_IC25SYNTH_MASK) >> BIASBT3_PWD_IC25SYNTH_LSB)
#define BIASBT3_PWD_IC25SYNTH_SET(x)                                 (((0 | (x)) << BIASBT3_PWD_IC25SYNTH_LSB) & BIASBT3_PWD_IC25SYNTH_MASK)
#define BIASBT3_PWD_IC25SYNTH_RESET                                  3
#define BIASBT3_PWD_IR12P5SPARE_MSB                                  19
#define BIASBT3_PWD_IR12P5SPARE_LSB                                  19
#define BIASBT3_PWD_IR12P5SPARE_MASK                                 0x00080000
#define BIASBT3_PWD_IR12P5SPARE_GET(x)                               (((x) & BIASBT3_PWD_IR12P5SPARE_MASK) >> BIASBT3_PWD_IR12P5SPARE_LSB)
#define BIASBT3_PWD_IR12P5SPARE_SET(x)                               (((0 | (x)) << BIASBT3_PWD_IR12P5SPARE_LSB) & BIASBT3_PWD_IR12P5SPARE_MASK)
#define BIASBT3_PWD_IR12P5SPARE_RESET                                0
#define BIASBT3_PWD_IC25RXAGC_MSB                                    18
#define BIASBT3_PWD_IC25RXAGC_LSB                                    16
#define BIASBT3_PWD_IC25RXAGC_MASK                                   0x00070000
#define BIASBT3_PWD_IC25RXAGC_GET(x)                                 (((x) & BIASBT3_PWD_IC25RXAGC_MASK) >> BIASBT3_PWD_IC25RXAGC_LSB)
#define BIASBT3_PWD_IC25RXAGC_SET(x)                                 (((0 | (x)) << BIASBT3_PWD_IC25RXAGC_LSB) & BIASBT3_PWD_IC25RXAGC_MASK)
#define BIASBT3_PWD_IC25RXAGC_RESET                                  3
#define BIASBT3_PWD_ICBIASCAL_MSB                                    15
#define BIASBT3_PWD_ICBIASCAL_LSB                                    15
#define BIASBT3_PWD_ICBIASCAL_MASK                                   0x00008000
#define BIASBT3_PWD_ICBIASCAL_GET(x)                                 (((x) & BIASBT3_PWD_ICBIASCAL_MASK) >> BIASBT3_PWD_ICBIASCAL_LSB)
#define BIASBT3_PWD_ICBIASCAL_SET(x)                                 (((0 | (x)) << BIASBT3_PWD_ICBIASCAL_LSB) & BIASBT3_PWD_ICBIASCAL_MASK)
#define BIASBT3_PWD_ICBIASCAL_RESET                                  0
#define BIASBT3_PWD_IC25TESTIQ_MSB                                   14
#define BIASBT3_PWD_IC25TESTIQ_LSB                                   12
#define BIASBT3_PWD_IC25TESTIQ_MASK                                  0x00007000
#define BIASBT3_PWD_IC25TESTIQ_GET(x)                                (((x) & BIASBT3_PWD_IC25TESTIQ_MASK) >> BIASBT3_PWD_IC25TESTIQ_LSB)
#define BIASBT3_PWD_IC25TESTIQ_SET(x)                                (((0 | (x)) << BIASBT3_PWD_IC25TESTIQ_LSB) & BIASBT3_PWD_IC25TESTIQ_MASK)
#define BIASBT3_PWD_IC25TESTIQ_RESET                                 3
#define BIASBT3_PWD_IR25ADC_MSB                                      11
#define BIASBT3_PWD_IR25ADC_LSB                                      9
#define BIASBT3_PWD_IR25ADC_MASK                                     0x00000e00
#define BIASBT3_PWD_IR25ADC_GET(x)                                   (((x) & BIASBT3_PWD_IR25ADC_MASK) >> BIASBT3_PWD_IR25ADC_LSB)
#define BIASBT3_PWD_IR25ADC_SET(x)                                   (((0 | (x)) << BIASBT3_PWD_IR25ADC_LSB) & BIASBT3_PWD_IR25ADC_MASK)
#define BIASBT3_PWD_IR25ADC_RESET                                    3
#define BIASBT3_PWD_IR25CGM_MSB                                      8
#define BIASBT3_PWD_IR25CGM_LSB                                      6
#define BIASBT3_PWD_IR25CGM_MASK                                     0x000001c0
#define BIASBT3_PWD_IR25CGM_GET(x)                                   (((x) & BIASBT3_PWD_IR25CGM_MASK) >> BIASBT3_PWD_IR25CGM_LSB)
#define BIASBT3_PWD_IR25CGM_SET(x)                                   (((0 | (x)) << BIASBT3_PWD_IR25CGM_LSB) & BIASBT3_PWD_IR25CGM_MASK)
#define BIASBT3_PWD_IR25CGM_RESET                                    3
#define BIASBT3_PWD_IR25LO_MSB                                       5
#define BIASBT3_PWD_IR25LO_LSB                                       3
#define BIASBT3_PWD_IR25LO_MASK                                      0x00000038
#define BIASBT3_PWD_IR25LO_GET(x)                                    (((x) & BIASBT3_PWD_IR25LO_MASK) >> BIASBT3_PWD_IR25LO_LSB)
#define BIASBT3_PWD_IR25LO_SET(x)                                    (((0 | (x)) << BIASBT3_PWD_IR25LO_LSB) & BIASBT3_PWD_IR25LO_MASK)
#define BIASBT3_PWD_IR25LO_RESET                                     3
#define BIASBT3_PWD_IR25PA_MSB                                       2
#define BIASBT3_PWD_IR25PA_LSB                                       0
#define BIASBT3_PWD_IR25PA_MASK                                      0x00000007
#define BIASBT3_PWD_IR25PA_GET(x)                                    (((x) & BIASBT3_PWD_IR25PA_MASK) >> BIASBT3_PWD_IR25PA_LSB)
#define BIASBT3_PWD_IR25PA_SET(x)                                    (((0 | (x)) << BIASBT3_PWD_IR25PA_LSB) & BIASBT3_PWD_IR25PA_MASK)
#define BIASBT3_PWD_IR25PA_RESET                                     3
#define BIASBT3_ADDRESS                                              0x0008
#define BIASBT3_HW_MASK                                              0xffffffff
#define BIASBT3_SW_MASK                                              0xffffffff
#define BIASBT3_HW_WRITE_MASK                                        0x00000000
#define BIASBT3_SW_WRITE_MASK                                        0xffffffff
#define BIASBT3_RSTMASK                                              0xffffffff
#define BIASBT3_RESET                                                0x6db336db

// 0x000c (BIASBT4)
#define BIASBT4_PWD_IR25PLLREG_MSB                                   31
#define BIASBT4_PWD_IR25PLLREG_LSB                                   29
#define BIASBT4_PWD_IR25PLLREG_MASK                                  0xe0000000
#define BIASBT4_PWD_IR25PLLREG_GET(x)                                (((x) & BIASBT4_PWD_IR25PLLREG_MASK) >> BIASBT4_PWD_IR25PLLREG_LSB)
#define BIASBT4_PWD_IR25PLLREG_SET(x)                                (((0 | (x)) << BIASBT4_PWD_IR25PLLREG_LSB) & BIASBT4_PWD_IR25PLLREG_MASK)
#define BIASBT4_PWD_IR25PLLREG_RESET                                 3
#define BIASBT4_PWD_IR25RXAGC2_MSB                                   28
#define BIASBT4_PWD_IR25RXAGC2_LSB                                   26
#define BIASBT4_PWD_IR25RXAGC2_MASK                                  0x1c000000
#define BIASBT4_PWD_IR25RXAGC2_GET(x)                                (((x) & BIASBT4_PWD_IR25RXAGC2_MASK) >> BIASBT4_PWD_IR25RXAGC2_LSB)
#define BIASBT4_PWD_IR25RXAGC2_SET(x)                                (((0 | (x)) << BIASBT4_PWD_IR25RXAGC2_LSB) & BIASBT4_PWD_IR25RXAGC2_MASK)
#define BIASBT4_PWD_IR25RXAGC2_RESET                                 3
#define BIASBT4_PWD_IR25OTPREG_MSB                                   25
#define BIASBT4_PWD_IR25OTPREG_LSB                                   23
#define BIASBT4_PWD_IR25OTPREG_MASK                                  0x03800000
#define BIASBT4_PWD_IR25OTPREG_GET(x)                                (((x) & BIASBT4_PWD_IR25OTPREG_MASK) >> BIASBT4_PWD_IR25OTPREG_LSB)
#define BIASBT4_PWD_IR25OTPREG_SET(x)                                (((0 | (x)) << BIASBT4_PWD_IR25OTPREG_LSB) & BIASBT4_PWD_IR25OTPREG_MASK)
#define BIASBT4_PWD_IR25OTPREG_RESET                                 6
#define BIASBT4_PWD_IR25TXMIX_MSB                                    22
#define BIASBT4_PWD_IR25TXMIX_LSB                                    20
#define BIASBT4_PWD_IR25TXMIX_MASK                                   0x00700000
#define BIASBT4_PWD_IR25TXMIX_GET(x)                                 (((x) & BIASBT4_PWD_IR25TXMIX_MASK) >> BIASBT4_PWD_IR25TXMIX_LSB)
#define BIASBT4_PWD_IR25TXMIX_SET(x)                                 (((0 | (x)) << BIASBT4_PWD_IR25TXMIX_LSB) & BIASBT4_PWD_IR25TXMIX_MASK)
#define BIASBT4_PWD_IR25TXMIX_RESET                                  3
#define BIASBT4_PWD_IR25XTALREG_MSB                                  19
#define BIASBT4_PWD_IR25XTALREG_LSB                                  17
#define BIASBT4_PWD_IR25XTALREG_MASK                                 0x000e0000
#define BIASBT4_PWD_IR25XTALREG_GET(x)                               (((x) & BIASBT4_PWD_IR25XTALREG_MASK) >> BIASBT4_PWD_IR25XTALREG_LSB)
#define BIASBT4_PWD_IR25XTALREG_SET(x)                               (((0 | (x)) << BIASBT4_PWD_IR25XTALREG_LSB) & BIASBT4_PWD_IR25XTALREG_MASK)
#define BIASBT4_PWD_IR25XTALREG_RESET                                3
#define BIASBT4_PWD_IR25TEMPSEN_MSB                                  16
#define BIASBT4_PWD_IR25TEMPSEN_LSB                                  14
#define BIASBT4_PWD_IR25TEMPSEN_MASK                                 0x0001c000
#define BIASBT4_PWD_IR25TEMPSEN_GET(x)                               (((x) & BIASBT4_PWD_IR25TEMPSEN_MASK) >> BIASBT4_PWD_IR25TEMPSEN_LSB)
#define BIASBT4_PWD_IR25TEMPSEN_SET(x)                               (((0 | (x)) << BIASBT4_PWD_IR25TEMPSEN_LSB) & BIASBT4_PWD_IR25TEMPSEN_MASK)
#define BIASBT4_PWD_IR25TEMPSEN_RESET                                3
#define BIASBT4_PWD_IR25SYNTH_MSB                                    13
#define BIASBT4_PWD_IR25SYNTH_LSB                                    11
#define BIASBT4_PWD_IR25SYNTH_MASK                                   0x00003800
#define BIASBT4_PWD_IR25SYNTH_GET(x)                                 (((x) & BIASBT4_PWD_IR25SYNTH_MASK) >> BIASBT4_PWD_IR25SYNTH_LSB)
#define BIASBT4_PWD_IR25SYNTH_SET(x)                                 (((0 | (x)) << BIASBT4_PWD_IR25SYNTH_LSB) & BIASBT4_PWD_IR25SYNTH_MASK)
#define BIASBT4_PWD_IR25SYNTH_RESET                                  3
#define BIASBT4_PWD_IR25SAR_MSB                                      10
#define BIASBT4_PWD_IR25SAR_LSB                                      8
#define BIASBT4_PWD_IR25SAR_MASK                                     0x00000700
#define BIASBT4_PWD_IR25SAR_GET(x)                                   (((x) & BIASBT4_PWD_IR25SAR_MASK) >> BIASBT4_PWD_IR25SAR_LSB)
#define BIASBT4_PWD_IR25SAR_SET(x)                                   (((0 | (x)) << BIASBT4_PWD_IR25SAR_LSB) & BIASBT4_PWD_IR25SAR_MASK)
#define BIASBT4_PWD_IR25SAR_RESET                                    3
#define BIASBT4_PWD_IR25RXAGC_MSB                                    7
#define BIASBT4_PWD_IR25RXAGC_LSB                                    5
#define BIASBT4_PWD_IR25RXAGC_MASK                                   0x000000e0
#define BIASBT4_PWD_IR25RXAGC_GET(x)                                 (((x) & BIASBT4_PWD_IR25RXAGC_MASK) >> BIASBT4_PWD_IR25RXAGC_LSB)
#define BIASBT4_PWD_IR25RXAGC_SET(x)                                 (((0 | (x)) << BIASBT4_PWD_IR25RXAGC_LSB) & BIASBT4_PWD_IR25RXAGC_MASK)
#define BIASBT4_PWD_IR25RXAGC_RESET                                  3
#define BIASBT4_PWD_IC75LNA2GBT_MSB                                  4
#define BIASBT4_PWD_IC75LNA2GBT_LSB                                  2
#define BIASBT4_PWD_IC75LNA2GBT_MASK                                 0x0000001c
#define BIASBT4_PWD_IC75LNA2GBT_GET(x)                               (((x) & BIASBT4_PWD_IC75LNA2GBT_MASK) >> BIASBT4_PWD_IC75LNA2GBT_LSB)
#define BIASBT4_PWD_IC75LNA2GBT_SET(x)                               (((0 | (x)) << BIASBT4_PWD_IC75LNA2GBT_LSB) & BIASBT4_PWD_IC75LNA2GBT_MASK)
#define BIASBT4_PWD_IC75LNA2GBT_RESET                                3
#define BIASBT4_SPARE4_MSB                                           1
#define BIASBT4_SPARE4_LSB                                           0
#define BIASBT4_SPARE4_MASK                                          0x00000003
#define BIASBT4_SPARE4_GET(x)                                        (((x) & BIASBT4_SPARE4_MASK) >> BIASBT4_SPARE4_LSB)
#define BIASBT4_SPARE4_SET(x)                                        (((0 | (x)) << BIASBT4_SPARE4_LSB) & BIASBT4_SPARE4_MASK)
#define BIASBT4_SPARE4_RESET                                         0
#define BIASBT4_ADDRESS                                              0x000c
#define BIASBT4_HW_MASK                                              0xffffffff
#define BIASBT4_SW_MASK                                              0xffffffff
#define BIASBT4_HW_WRITE_MASK                                        0x00000000
#define BIASBT4_SW_WRITE_MASK                                        0xffffffff
#define BIASBT4_RSTMASK                                              0xffffffff
#define BIASBT4_RESET                                                0x6f36db6c

// 0x0010 (BIASBT5)
#define BIASBT5_PWD_IC25SPARE1_MSB                                   31
#define BIASBT5_PWD_IC25SPARE1_LSB                                   29
#define BIASBT5_PWD_IC25SPARE1_MASK                                  0xe0000000
#define BIASBT5_PWD_IC25SPARE1_GET(x)                                (((x) & BIASBT5_PWD_IC25SPARE1_MASK) >> BIASBT5_PWD_IC25SPARE1_LSB)
#define BIASBT5_PWD_IC25SPARE1_SET(x)                                (((0 | (x)) << BIASBT5_PWD_IC25SPARE1_LSB) & BIASBT5_PWD_IC25SPARE1_MASK)
#define BIASBT5_PWD_IC25SPARE1_RESET                                 3
#define BIASBT5_PWD_IC25SPARE2_MSB                                   28
#define BIASBT5_PWD_IC25SPARE2_LSB                                   26
#define BIASBT5_PWD_IC25SPARE2_MASK                                  0x1c000000
#define BIASBT5_PWD_IC25SPARE2_GET(x)                                (((x) & BIASBT5_PWD_IC25SPARE2_MASK) >> BIASBT5_PWD_IC25SPARE2_LSB)
#define BIASBT5_PWD_IC25SPARE2_SET(x)                                (((0 | (x)) << BIASBT5_PWD_IC25SPARE2_LSB) & BIASBT5_PWD_IC25SPARE2_MASK)
#define BIASBT5_PWD_IC25SPARE2_RESET                                 3
#define BIASBT5_PWD_IC25SPARE3_MSB                                   25
#define BIASBT5_PWD_IC25SPARE3_LSB                                   23
#define BIASBT5_PWD_IC25SPARE3_MASK                                  0x03800000
#define BIASBT5_PWD_IC25SPARE3_GET(x)                                (((x) & BIASBT5_PWD_IC25SPARE3_MASK) >> BIASBT5_PWD_IC25SPARE3_LSB)
#define BIASBT5_PWD_IC25SPARE3_SET(x)                                (((0 | (x)) << BIASBT5_PWD_IC25SPARE3_LSB) & BIASBT5_PWD_IC25SPARE3_MASK)
#define BIASBT5_PWD_IC25SPARE3_RESET                                 3
#define BIASBT5_PWD_IR25SPARE1_MSB                                   22
#define BIASBT5_PWD_IR25SPARE1_LSB                                   20
#define BIASBT5_PWD_IR25SPARE1_MASK                                  0x00700000
#define BIASBT5_PWD_IR25SPARE1_GET(x)                                (((x) & BIASBT5_PWD_IR25SPARE1_MASK) >> BIASBT5_PWD_IR25SPARE1_LSB)
#define BIASBT5_PWD_IR25SPARE1_SET(x)                                (((0 | (x)) << BIASBT5_PWD_IR25SPARE1_LSB) & BIASBT5_PWD_IR25SPARE1_MASK)
#define BIASBT5_PWD_IR25SPARE1_RESET                                 3
#define BIASBT5_PWD_IR25SPARE2_MSB                                   19
#define BIASBT5_PWD_IR25SPARE2_LSB                                   17
#define BIASBT5_PWD_IR25SPARE2_MASK                                  0x000e0000
#define BIASBT5_PWD_IR25SPARE2_GET(x)                                (((x) & BIASBT5_PWD_IR25SPARE2_MASK) >> BIASBT5_PWD_IR25SPARE2_LSB)
#define BIASBT5_PWD_IR25SPARE2_SET(x)                                (((0 | (x)) << BIASBT5_PWD_IR25SPARE2_LSB) & BIASBT5_PWD_IR25SPARE2_MASK)
#define BIASBT5_PWD_IR25SPARE2_RESET                                 3
#define BIASBT5_SPARE5_MSB                                           16
#define BIASBT5_SPARE5_LSB                                           0
#define BIASBT5_SPARE5_MASK                                          0x0001ffff
#define BIASBT5_SPARE5_GET(x)                                        (((x) & BIASBT5_SPARE5_MASK) >> BIASBT5_SPARE5_LSB)
#define BIASBT5_SPARE5_SET(x)                                        (((0 | (x)) << BIASBT5_SPARE5_LSB) & BIASBT5_SPARE5_MASK)
#define BIASBT5_SPARE5_RESET                                         0
#define BIASBT5_ADDRESS                                              0x0010
#define BIASBT5_HW_MASK                                              0xffffffff
#define BIASBT5_SW_MASK                                              0xffffffff
#define BIASBT5_HW_WRITE_MASK                                        0x00000000
#define BIASBT5_SW_WRITE_MASK                                        0xffffffff
#define BIASBT5_RSTMASK                                              0xffffffff
#define BIASBT5_RESET                                                0x6db60000


#endif /* _BIASBT_REG_CSR_H_ */
