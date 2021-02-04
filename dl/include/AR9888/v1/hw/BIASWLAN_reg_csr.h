//                                                                             
// File:       ./BIASWLAN_reg_csr.vrh                                          
// Creator:    shung                                                           
// Time:       Monday Apr 23, 2012 [6:25:30 pm]                                
//                                                                             
// Path:       /trees/shung/shung-dev/chips/peregrine/1.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux/blueprint -odir . -codegen   
//             ath_vrh.codegen -ath_vrh -Wdesc -I                              
//             /trees/shung/shung-dev/chips/peregrine/1.0/blueprint/sysconfig  
//             BIASWLAN_reg_csr.rdl                                            
//                                                                             
// Sources:    /trees/shung/shung-dev/chips/peregrine/1.0/ip/radio_peregrine/rtl/srif/blueprint/BIASWLAN_reg.rdl
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


#ifndef _BIASWLAN_REG_CSR_H_
#define _BIASWLAN_REG_CSR_H_
// 0x0000 (BIASWLAN1)
#define BIASWLAN1_BIAS_SEL_MSB                                       31
#define BIASWLAN1_BIAS_SEL_LSB                                       24
#define BIASWLAN1_BIAS_SEL_MASK                                      0xff000000
#define BIASWLAN1_BIAS_SEL_GET(x)                                    (((x) & BIASWLAN1_BIAS_SEL_MASK) >> BIASWLAN1_BIAS_SEL_LSB)
#define BIASWLAN1_BIAS_SEL_SET(x)                                    (((0 | (x)) << BIASWLAN1_BIAS_SEL_LSB) & BIASWLAN1_BIAS_SEL_MASK)
#define BIASWLAN1_BIAS_SEL_RESET                                     0
#define BIASWLAN1_PWD_IC25ADC_MSB                                    23
#define BIASWLAN1_PWD_IC25ADC_LSB                                    21
#define BIASWLAN1_PWD_IC25ADC_MASK                                   0x00e00000
#define BIASWLAN1_PWD_IC25ADC_GET(x)                                 (((x) & BIASWLAN1_PWD_IC25ADC_MASK) >> BIASWLAN1_PWD_IC25ADC_LSB)
#define BIASWLAN1_PWD_IC25ADC_SET(x)                                 (((0 | (x)) << BIASWLAN1_PWD_IC25ADC_LSB) & BIASWLAN1_PWD_IC25ADC_MASK)
#define BIASWLAN1_PWD_IC25ADC_RESET                                  3
#define BIASWLAN1_PWD_IC25FIR_MSB                                    20
#define BIASWLAN1_PWD_IC25FIR_LSB                                    18
#define BIASWLAN1_PWD_IC25FIR_MASK                                   0x001c0000
#define BIASWLAN1_PWD_IC25FIR_GET(x)                                 (((x) & BIASWLAN1_PWD_IC25FIR_MASK) >> BIASWLAN1_PWD_IC25FIR_LSB)
#define BIASWLAN1_PWD_IC25FIR_SET(x)                                 (((0 | (x)) << BIASWLAN1_PWD_IC25FIR_LSB) & BIASWLAN1_PWD_IC25FIR_MASK)
#define BIASWLAN1_PWD_IC25FIR_RESET                                  3
#define BIASWLAN1_PWD_IC25DAC_MSB                                    17
#define BIASWLAN1_PWD_IC25DAC_LSB                                    15
#define BIASWLAN1_PWD_IC25DAC_MASK                                   0x00038000
#define BIASWLAN1_PWD_IC25DAC_GET(x)                                 (((x) & BIASWLAN1_PWD_IC25DAC_MASK) >> BIASWLAN1_PWD_IC25DAC_LSB)
#define BIASWLAN1_PWD_IC25DAC_SET(x)                                 (((0 | (x)) << BIASWLAN1_PWD_IC25DAC_LSB) & BIASWLAN1_PWD_IC25DAC_MASK)
#define BIASWLAN1_PWD_IC25DAC_RESET                                  3
#define BIASWLAN1_PWD_IC25BB_MSB                                     14
#define BIASWLAN1_PWD_IC25BB_LSB                                     12
#define BIASWLAN1_PWD_IC25BB_MASK                                    0x00007000
#define BIASWLAN1_PWD_IC25BB_GET(x)                                  (((x) & BIASWLAN1_PWD_IC25BB_MASK) >> BIASWLAN1_PWD_IC25BB_LSB)
#define BIASWLAN1_PWD_IC25BB_SET(x)                                  (((0 | (x)) << BIASWLAN1_PWD_IC25BB_LSB) & BIASWLAN1_PWD_IC25BB_MASK)
#define BIASWLAN1_PWD_IC25BB_RESET                                   3
#define BIASWLAN1_PWD_IC25V2II_MSB                                   11
#define BIASWLAN1_PWD_IC25V2II_LSB                                   9
#define BIASWLAN1_PWD_IC25V2II_MASK                                  0x00000e00
#define BIASWLAN1_PWD_IC25V2II_GET(x)                                (((x) & BIASWLAN1_PWD_IC25V2II_MASK) >> BIASWLAN1_PWD_IC25V2II_LSB)
#define BIASWLAN1_PWD_IC25V2II_SET(x)                                (((0 | (x)) << BIASWLAN1_PWD_IC25V2II_LSB) & BIASWLAN1_PWD_IC25V2II_MASK)
#define BIASWLAN1_PWD_IC25V2II_RESET                                 3
#define BIASWLAN1_PWD_IC25V2IQ_MSB                                   8
#define BIASWLAN1_PWD_IC25V2IQ_LSB                                   6
#define BIASWLAN1_PWD_IC25V2IQ_MASK                                  0x000001c0
#define BIASWLAN1_PWD_IC25V2IQ_GET(x)                                (((x) & BIASWLAN1_PWD_IC25V2IQ_MASK) >> BIASWLAN1_PWD_IC25V2IQ_LSB)
#define BIASWLAN1_PWD_IC25V2IQ_SET(x)                                (((0 | (x)) << BIASWLAN1_PWD_IC25V2IQ_LSB) & BIASWLAN1_PWD_IC25V2IQ_MASK)
#define BIASWLAN1_PWD_IC25V2IQ_RESET                                 3
#define BIASWLAN1_PWD_IC100PCIE_MSB                                  5
#define BIASWLAN1_PWD_IC100PCIE_LSB                                  3
#define BIASWLAN1_PWD_IC100PCIE_MASK                                 0x00000038
#define BIASWLAN1_PWD_IC100PCIE_GET(x)                               (((x) & BIASWLAN1_PWD_IC100PCIE_MASK) >> BIASWLAN1_PWD_IC100PCIE_LSB)
#define BIASWLAN1_PWD_IC100PCIE_SET(x)                               (((0 | (x)) << BIASWLAN1_PWD_IC100PCIE_LSB) & BIASWLAN1_PWD_IC100PCIE_MASK)
#define BIASWLAN1_PWD_IC100PCIE_RESET                                2
#define BIASWLAN1_SPARE1_MSB                                         2
#define BIASWLAN1_SPARE1_LSB                                         0
#define BIASWLAN1_SPARE1_MASK                                        0x00000007
#define BIASWLAN1_SPARE1_GET(x)                                      (((x) & BIASWLAN1_SPARE1_MASK) >> BIASWLAN1_SPARE1_LSB)
#define BIASWLAN1_SPARE1_SET(x)                                      (((0 | (x)) << BIASWLAN1_SPARE1_LSB) & BIASWLAN1_SPARE1_MASK)
#define BIASWLAN1_SPARE1_RESET                                       0
#define BIASWLAN1_ADDRESS                                            0x0000
#define BIASWLAN1_HW_MASK                                            0xffffffff
#define BIASWLAN1_SW_MASK                                            0xffffffff
#define BIASWLAN1_HW_WRITE_MASK                                      0x00000000
#define BIASWLAN1_SW_WRITE_MASK                                      0xffffffff
#define BIASWLAN1_RSTMASK                                            0xffffffff
#define BIASWLAN1_RESET                                              0x006db6d0

// 0x0004 (BIASWLAN2)
#define BIASWLAN2_PWD_IC25PLLGM_MSB                                  31
#define BIASWLAN2_PWD_IC25PLLGM_LSB                                  29
#define BIASWLAN2_PWD_IC25PLLGM_MASK                                 0xe0000000
#define BIASWLAN2_PWD_IC25PLLGM_GET(x)                               (((x) & BIASWLAN2_PWD_IC25PLLGM_MASK) >> BIASWLAN2_PWD_IC25PLLGM_LSB)
#define BIASWLAN2_PWD_IC25PLLGM_SET(x)                               (((0 | (x)) << BIASWLAN2_PWD_IC25PLLGM_LSB) & BIASWLAN2_PWD_IC25PLLGM_MASK)
#define BIASWLAN2_PWD_IC25PLLGM_RESET                                3
#define BIASWLAN2_PWD_IC25PLLCP_MSB                                  28
#define BIASWLAN2_PWD_IC25PLLCP_LSB                                  26
#define BIASWLAN2_PWD_IC25PLLCP_MASK                                 0x1c000000
#define BIASWLAN2_PWD_IC25PLLCP_GET(x)                               (((x) & BIASWLAN2_PWD_IC25PLLCP_MASK) >> BIASWLAN2_PWD_IC25PLLCP_LSB)
#define BIASWLAN2_PWD_IC25PLLCP_SET(x)                               (((0 | (x)) << BIASWLAN2_PWD_IC25PLLCP_LSB) & BIASWLAN2_PWD_IC25PLLCP_MASK)
#define BIASWLAN2_PWD_IC25PLLCP_RESET                                3
#define BIASWLAN2_PWD_IC25PLLCP2_MSB                                 25
#define BIASWLAN2_PWD_IC25PLLCP2_LSB                                 23
#define BIASWLAN2_PWD_IC25PLLCP2_MASK                                0x03800000
#define BIASWLAN2_PWD_IC25PLLCP2_GET(x)                              (((x) & BIASWLAN2_PWD_IC25PLLCP2_MASK) >> BIASWLAN2_PWD_IC25PLLCP2_LSB)
#define BIASWLAN2_PWD_IC25PLLCP2_SET(x)                              (((0 | (x)) << BIASWLAN2_PWD_IC25PLLCP2_LSB) & BIASWLAN2_PWD_IC25PLLCP2_MASK)
#define BIASWLAN2_PWD_IC25PLLCP2_RESET                               3
#define BIASWLAN2_PWD_IC25PLLREG_MSB                                 22
#define BIASWLAN2_PWD_IC25PLLREG_LSB                                 20
#define BIASWLAN2_PWD_IC25PLLREG_MASK                                0x00700000
#define BIASWLAN2_PWD_IC25PLLREG_GET(x)                              (((x) & BIASWLAN2_PWD_IC25PLLREG_MASK) >> BIASWLAN2_PWD_IC25PLLREG_LSB)
#define BIASWLAN2_PWD_IC25PLLREG_SET(x)                              (((0 | (x)) << BIASWLAN2_PWD_IC25PLLREG_LSB) & BIASWLAN2_PWD_IC25PLLREG_MASK)
#define BIASWLAN2_PWD_IC25PLLREG_RESET                               3
#define BIASWLAN2_PWD_IC25SYNTH_MSB                                  19
#define BIASWLAN2_PWD_IC25SYNTH_LSB                                  17
#define BIASWLAN2_PWD_IC25SYNTH_MASK                                 0x000e0000
#define BIASWLAN2_PWD_IC25SYNTH_GET(x)                               (((x) & BIASWLAN2_PWD_IC25SYNTH_MASK) >> BIASWLAN2_PWD_IC25SYNTH_LSB)
#define BIASWLAN2_PWD_IC25SYNTH_SET(x)                               (((0 | (x)) << BIASWLAN2_PWD_IC25SYNTH_LSB) & BIASWLAN2_PWD_IC25SYNTH_MASK)
#define BIASWLAN2_PWD_IC25SYNTH_RESET                                3
#define BIASWLAN2_PWD_IC25RXRF_MSB                                   16
#define BIASWLAN2_PWD_IC25RXRF_LSB                                   14
#define BIASWLAN2_PWD_IC25RXRF_MASK                                  0x0001c000
#define BIASWLAN2_PWD_IC25RXRF_GET(x)                                (((x) & BIASWLAN2_PWD_IC25RXRF_MASK) >> BIASWLAN2_PWD_IC25RXRF_LSB)
#define BIASWLAN2_PWD_IC25RXRF_SET(x)                                (((0 | (x)) << BIASWLAN2_PWD_IC25RXRF_LSB) & BIASWLAN2_PWD_IC25RXRF_MASK)
#define BIASWLAN2_PWD_IC25RXRF_RESET                                 3
#define BIASWLAN2_PWD_IC25TXRF_MSB                                   13
#define BIASWLAN2_PWD_IC25TXRF_LSB                                   11
#define BIASWLAN2_PWD_IC25TXRF_MASK                                  0x00003800
#define BIASWLAN2_PWD_IC25TXRF_GET(x)                                (((x) & BIASWLAN2_PWD_IC25TXRF_MASK) >> BIASWLAN2_PWD_IC25TXRF_LSB)
#define BIASWLAN2_PWD_IC25TXRF_SET(x)                                (((0 | (x)) << BIASWLAN2_PWD_IC25TXRF_LSB) & BIASWLAN2_PWD_IC25TXRF_MASK)
#define BIASWLAN2_PWD_IC25TXRF_RESET                                 3
#define BIASWLAN2_PWD_IC25XTAL_MSB                                   10
#define BIASWLAN2_PWD_IC25XTAL_LSB                                   8
#define BIASWLAN2_PWD_IC25XTAL_MASK                                  0x00000700
#define BIASWLAN2_PWD_IC25XTAL_GET(x)                                (((x) & BIASWLAN2_PWD_IC25XTAL_MASK) >> BIASWLAN2_PWD_IC25XTAL_LSB)
#define BIASWLAN2_PWD_IC25XTAL_SET(x)                                (((0 | (x)) << BIASWLAN2_PWD_IC25XTAL_LSB) & BIASWLAN2_PWD_IC25XTAL_MASK)
#define BIASWLAN2_PWD_IC25XTAL_RESET                                 3
#define BIASWLAN2_PWD_IC25XTALREG_MSB                                7
#define BIASWLAN2_PWD_IC25XTALREG_LSB                                5
#define BIASWLAN2_PWD_IC25XTALREG_MASK                               0x000000e0
#define BIASWLAN2_PWD_IC25XTALREG_GET(x)                             (((x) & BIASWLAN2_PWD_IC25XTALREG_MASK) >> BIASWLAN2_PWD_IC25XTALREG_LSB)
#define BIASWLAN2_PWD_IC25XTALREG_SET(x)                             (((0 | (x)) << BIASWLAN2_PWD_IC25XTALREG_LSB) & BIASWLAN2_PWD_IC25XTALREG_MASK)
#define BIASWLAN2_PWD_IC25XTALREG_RESET                              3
#define BIASWLAN2_SPARE2_MSB                                         4
#define BIASWLAN2_SPARE2_LSB                                         0
#define BIASWLAN2_SPARE2_MASK                                        0x0000001f
#define BIASWLAN2_SPARE2_GET(x)                                      (((x) & BIASWLAN2_SPARE2_MASK) >> BIASWLAN2_SPARE2_LSB)
#define BIASWLAN2_SPARE2_SET(x)                                      (((0 | (x)) << BIASWLAN2_SPARE2_LSB) & BIASWLAN2_SPARE2_MASK)
#define BIASWLAN2_SPARE2_RESET                                       0
#define BIASWLAN2_ADDRESS                                            0x0004
#define BIASWLAN2_HW_MASK                                            0xffffffff
#define BIASWLAN2_SW_MASK                                            0xffffffff
#define BIASWLAN2_HW_WRITE_MASK                                      0x00000000
#define BIASWLAN2_SW_WRITE_MASK                                      0xffffffff
#define BIASWLAN2_RSTMASK                                            0xffffffff
#define BIASWLAN2_RESET                                              0x6db6db60

// 0x0008 (BIASWLAN3)
#define BIASWLAN3_PWD_IR50ADC_MSB                                    31
#define BIASWLAN3_PWD_IR50ADC_LSB                                    29
#define BIASWLAN3_PWD_IR50ADC_MASK                                   0xe0000000
#define BIASWLAN3_PWD_IR50ADC_GET(x)                                 (((x) & BIASWLAN3_PWD_IR50ADC_MASK) >> BIASWLAN3_PWD_IR50ADC_LSB)
#define BIASWLAN3_PWD_IR50ADC_SET(x)                                 (((0 | (x)) << BIASWLAN3_PWD_IR50ADC_LSB) & BIASWLAN3_PWD_IR50ADC_MASK)
#define BIASWLAN3_PWD_IR50ADC_RESET                                  3
#define BIASWLAN3_PWD_IR25FIR_MSB                                    28
#define BIASWLAN3_PWD_IR25FIR_LSB                                    26
#define BIASWLAN3_PWD_IR25FIR_MASK                                   0x1c000000
#define BIASWLAN3_PWD_IR25FIR_GET(x)                                 (((x) & BIASWLAN3_PWD_IR25FIR_MASK) >> BIASWLAN3_PWD_IR25FIR_LSB)
#define BIASWLAN3_PWD_IR25FIR_SET(x)                                 (((0 | (x)) << BIASWLAN3_PWD_IR25FIR_LSB) & BIASWLAN3_PWD_IR25FIR_MASK)
#define BIASWLAN3_PWD_IR25FIR_RESET                                  3
#define BIASWLAN3_PWD_IR25DAC_MSB                                    25
#define BIASWLAN3_PWD_IR25DAC_LSB                                    23
#define BIASWLAN3_PWD_IR25DAC_MASK                                   0x03800000
#define BIASWLAN3_PWD_IR25DAC_GET(x)                                 (((x) & BIASWLAN3_PWD_IR25DAC_MASK) >> BIASWLAN3_PWD_IR25DAC_LSB)
#define BIASWLAN3_PWD_IR25DAC_SET(x)                                 (((0 | (x)) << BIASWLAN3_PWD_IR25DAC_LSB) & BIASWLAN3_PWD_IR25DAC_MASK)
#define BIASWLAN3_PWD_IR25DAC_RESET                                  3
#define BIASWLAN3_PWD_IR50DAC_MSB                                    22
#define BIASWLAN3_PWD_IR50DAC_LSB                                    20
#define BIASWLAN3_PWD_IR50DAC_MASK                                   0x00700000
#define BIASWLAN3_PWD_IR50DAC_GET(x)                                 (((x) & BIASWLAN3_PWD_IR50DAC_MASK) >> BIASWLAN3_PWD_IR50DAC_LSB)
#define BIASWLAN3_PWD_IR50DAC_SET(x)                                 (((0 | (x)) << BIASWLAN3_PWD_IR50DAC_LSB) & BIASWLAN3_PWD_IR50DAC_MASK)
#define BIASWLAN3_PWD_IR50DAC_RESET                                  3
#define BIASWLAN3_PWD_IR25BB_MSB                                     19
#define BIASWLAN3_PWD_IR25BB_LSB                                     17
#define BIASWLAN3_PWD_IR25BB_MASK                                    0x000e0000
#define BIASWLAN3_PWD_IR25BB_GET(x)                                  (((x) & BIASWLAN3_PWD_IR25BB_MASK) >> BIASWLAN3_PWD_IR25BB_LSB)
#define BIASWLAN3_PWD_IR25BB_SET(x)                                  (((0 | (x)) << BIASWLAN3_PWD_IR25BB_LSB) & BIASWLAN3_PWD_IR25BB_MASK)
#define BIASWLAN3_PWD_IR25BB_RESET                                   3
#define BIASWLAN3_PWD_IR25PLLREG_MSB                                 16
#define BIASWLAN3_PWD_IR25PLLREG_LSB                                 14
#define BIASWLAN3_PWD_IR25PLLREG_MASK                                0x0001c000
#define BIASWLAN3_PWD_IR25PLLREG_GET(x)                              (((x) & BIASWLAN3_PWD_IR25PLLREG_MASK) >> BIASWLAN3_PWD_IR25PLLREG_LSB)
#define BIASWLAN3_PWD_IR25PLLREG_SET(x)                              (((0 | (x)) << BIASWLAN3_PWD_IR25PLLREG_LSB) & BIASWLAN3_PWD_IR25PLLREG_MASK)
#define BIASWLAN3_PWD_IR25PLLREG_RESET                               3
#define BIASWLAN3_PWD_IR25SYNTH_MSB                                  13
#define BIASWLAN3_PWD_IR25SYNTH_LSB                                  11
#define BIASWLAN3_PWD_IR25SYNTH_MASK                                 0x00003800
#define BIASWLAN3_PWD_IR25SYNTH_GET(x)                               (((x) & BIASWLAN3_PWD_IR25SYNTH_MASK) >> BIASWLAN3_PWD_IR25SYNTH_LSB)
#define BIASWLAN3_PWD_IR25SYNTH_SET(x)                               (((0 | (x)) << BIASWLAN3_PWD_IR25SYNTH_LSB) & BIASWLAN3_PWD_IR25SYNTH_MASK)
#define BIASWLAN3_PWD_IR25SYNTH_RESET                                3
#define BIASWLAN3_PWD_IR25RXRF_MSB                                   10
#define BIASWLAN3_PWD_IR25RXRF_LSB                                   8
#define BIASWLAN3_PWD_IR25RXRF_MASK                                  0x00000700
#define BIASWLAN3_PWD_IR25RXRF_GET(x)                                (((x) & BIASWLAN3_PWD_IR25RXRF_MASK) >> BIASWLAN3_PWD_IR25RXRF_LSB)
#define BIASWLAN3_PWD_IR25RXRF_SET(x)                                (((0 | (x)) << BIASWLAN3_PWD_IR25RXRF_LSB) & BIASWLAN3_PWD_IR25RXRF_MASK)
#define BIASWLAN3_PWD_IR25RXRF_RESET                                 3
#define BIASWLAN3_PWD_IR25TXRF_MSB                                   7
#define BIASWLAN3_PWD_IR25TXRF_LSB                                   5
#define BIASWLAN3_PWD_IR25TXRF_MASK                                  0x000000e0
#define BIASWLAN3_PWD_IR25TXRF_GET(x)                                (((x) & BIASWLAN3_PWD_IR25TXRF_MASK) >> BIASWLAN3_PWD_IR25TXRF_LSB)
#define BIASWLAN3_PWD_IR25TXRF_SET(x)                                (((0 | (x)) << BIASWLAN3_PWD_IR25TXRF_LSB) & BIASWLAN3_PWD_IR25TXRF_MASK)
#define BIASWLAN3_PWD_IR25TXRF_RESET                                 3
#define BIASWLAN3_PWD_IR25XTALREG_MSB                                4
#define BIASWLAN3_PWD_IR25XTALREG_LSB                                2
#define BIASWLAN3_PWD_IR25XTALREG_MASK                               0x0000001c
#define BIASWLAN3_PWD_IR25XTALREG_GET(x)                             (((x) & BIASWLAN3_PWD_IR25XTALREG_MASK) >> BIASWLAN3_PWD_IR25XTALREG_LSB)
#define BIASWLAN3_PWD_IR25XTALREG_SET(x)                             (((0 | (x)) << BIASWLAN3_PWD_IR25XTALREG_LSB) & BIASWLAN3_PWD_IR25XTALREG_MASK)
#define BIASWLAN3_PWD_IR25XTALREG_RESET                              3
#define BIASWLAN3_SPARE3_MSB                                         1
#define BIASWLAN3_SPARE3_LSB                                         0
#define BIASWLAN3_SPARE3_MASK                                        0x00000003
#define BIASWLAN3_SPARE3_GET(x)                                      (((x) & BIASWLAN3_SPARE3_MASK) >> BIASWLAN3_SPARE3_LSB)
#define BIASWLAN3_SPARE3_SET(x)                                      (((0 | (x)) << BIASWLAN3_SPARE3_LSB) & BIASWLAN3_SPARE3_MASK)
#define BIASWLAN3_SPARE3_RESET                                       0
#define BIASWLAN3_ADDRESS                                            0x0008
#define BIASWLAN3_HW_MASK                                            0xffffffff
#define BIASWLAN3_SW_MASK                                            0xffffffff
#define BIASWLAN3_HW_WRITE_MASK                                      0x00000000
#define BIASWLAN3_SW_WRITE_MASK                                      0xffffffff
#define BIASWLAN3_RSTMASK                                            0xffffffff
#define BIASWLAN3_RESET                                              0x6db6db6c

// 0x000c (BIASWLAN4)
#define BIASWLAN4_PWD_IC25SPAREA_MSB                                 31
#define BIASWLAN4_PWD_IC25SPAREA_LSB                                 29
#define BIASWLAN4_PWD_IC25SPAREA_MASK                                0xe0000000
#define BIASWLAN4_PWD_IC25SPAREA_GET(x)                              (((x) & BIASWLAN4_PWD_IC25SPAREA_MASK) >> BIASWLAN4_PWD_IC25SPAREA_LSB)
#define BIASWLAN4_PWD_IC25SPAREA_SET(x)                              (((0 | (x)) << BIASWLAN4_PWD_IC25SPAREA_LSB) & BIASWLAN4_PWD_IC25SPAREA_MASK)
#define BIASWLAN4_PWD_IC25SPAREA_RESET                               3
#define BIASWLAN4_PWD_IC25TESTTXIQ_MSB                               28
#define BIASWLAN4_PWD_IC25TESTTXIQ_LSB                               26
#define BIASWLAN4_PWD_IC25TESTTXIQ_MASK                              0x1c000000
#define BIASWLAN4_PWD_IC25TESTTXIQ_GET(x)                            (((x) & BIASWLAN4_PWD_IC25TESTTXIQ_MASK) >> BIASWLAN4_PWD_IC25TESTTXIQ_LSB)
#define BIASWLAN4_PWD_IC25TESTTXIQ_SET(x)                            (((0 | (x)) << BIASWLAN4_PWD_IC25TESTTXIQ_LSB) & BIASWLAN4_PWD_IC25TESTTXIQ_MASK)
#define BIASWLAN4_PWD_IC25TESTTXIQ_RESET                             3
#define BIASWLAN4_PWD_IC25XPABIAS_MSB                                25
#define BIASWLAN4_PWD_IC25XPABIAS_LSB                                23
#define BIASWLAN4_PWD_IC25XPABIAS_MASK                               0x03800000
#define BIASWLAN4_PWD_IC25XPABIAS_GET(x)                             (((x) & BIASWLAN4_PWD_IC25XPABIAS_MASK) >> BIASWLAN4_PWD_IC25XPABIAS_LSB)
#define BIASWLAN4_PWD_IC25XPABIAS_SET(x)                             (((0 | (x)) << BIASWLAN4_PWD_IC25XPABIAS_LSB) & BIASWLAN4_PWD_IC25XPABIAS_MASK)
#define BIASWLAN4_PWD_IC25XPABIAS_RESET                              3
#define BIASWLAN4_PWD_IR25OTPREG_MSB                                 22
#define BIASWLAN4_PWD_IR25OTPREG_LSB                                 20
#define BIASWLAN4_PWD_IR25OTPREG_MASK                                0x00700000
#define BIASWLAN4_PWD_IR25OTPREG_GET(x)                              (((x) & BIASWLAN4_PWD_IR25OTPREG_MASK) >> BIASWLAN4_PWD_IR25OTPREG_LSB)
#define BIASWLAN4_PWD_IR25OTPREG_SET(x)                              (((0 | (x)) << BIASWLAN4_PWD_IR25OTPREG_LSB) & BIASWLAN4_PWD_IR25OTPREG_MASK)
#define BIASWLAN4_PWD_IR25OTPREG_RESET                               6
#define BIASWLAN4_PWD_IR25THERMADC_MSB                               19
#define BIASWLAN4_PWD_IR25THERMADC_LSB                               17
#define BIASWLAN4_PWD_IR25THERMADC_MASK                              0x000e0000
#define BIASWLAN4_PWD_IR25THERMADC_GET(x)                            (((x) & BIASWLAN4_PWD_IR25THERMADC_MASK) >> BIASWLAN4_PWD_IR25THERMADC_LSB)
#define BIASWLAN4_PWD_IR25THERMADC_SET(x)                            (((0 | (x)) << BIASWLAN4_PWD_IR25THERMADC_LSB) & BIASWLAN4_PWD_IR25THERMADC_MASK)
#define BIASWLAN4_PWD_IR25THERMADC_RESET                             3
#define BIASWLAN4_PWD_IR25XPABIAS_MSB                                16
#define BIASWLAN4_PWD_IR25XPABIAS_LSB                                14
#define BIASWLAN4_PWD_IR25XPABIAS_MASK                               0x0001c000
#define BIASWLAN4_PWD_IR25XPABIAS_GET(x)                             (((x) & BIASWLAN4_PWD_IR25XPABIAS_MASK) >> BIASWLAN4_PWD_IR25XPABIAS_LSB)
#define BIASWLAN4_PWD_IR25XPABIAS_SET(x)                             (((0 | (x)) << BIASWLAN4_PWD_IR25XPABIAS_LSB) & BIASWLAN4_PWD_IR25XPABIAS_MASK)
#define BIASWLAN4_PWD_IR25XPABIAS_RESET                              3
#define BIASWLAN4_PWD_ICBIASCAL_MSB                                  13
#define BIASWLAN4_PWD_ICBIASCAL_LSB                                  13
#define BIASWLAN4_PWD_ICBIASCAL_MASK                                 0x00002000
#define BIASWLAN4_PWD_ICBIASCAL_GET(x)                               (((x) & BIASWLAN4_PWD_ICBIASCAL_MASK) >> BIASWLAN4_PWD_ICBIASCAL_LSB)
#define BIASWLAN4_PWD_ICBIASCAL_SET(x)                               (((0 | (x)) << BIASWLAN4_PWD_ICBIASCAL_LSB) & BIASWLAN4_PWD_ICBIASCAL_MASK)
#define BIASWLAN4_PWD_ICBIASCAL_RESET                                0
#define BIASWLAN4_ICBIASCALTOATB_MSB                                 12
#define BIASWLAN4_ICBIASCALTOATB_LSB                                 12
#define BIASWLAN4_ICBIASCALTOATB_MASK                                0x00001000
#define BIASWLAN4_ICBIASCALTOATB_GET(x)                              (((x) & BIASWLAN4_ICBIASCALTOATB_MASK) >> BIASWLAN4_ICBIASCALTOATB_LSB)
#define BIASWLAN4_ICBIASCALTOATB_SET(x)                              (((0 | (x)) << BIASWLAN4_ICBIASCALTOATB_LSB) & BIASWLAN4_ICBIASCALTOATB_MASK)
#define BIASWLAN4_ICBIASCALTOATB_RESET                               0
#define BIASWLAN4_KICKBACKFILTER_RSEL_MSB                            11
#define BIASWLAN4_KICKBACKFILTER_RSEL_LSB                            10
#define BIASWLAN4_KICKBACKFILTER_RSEL_MASK                           0x00000c00
#define BIASWLAN4_KICKBACKFILTER_RSEL_GET(x)                         (((x) & BIASWLAN4_KICKBACKFILTER_RSEL_MASK) >> BIASWLAN4_KICKBACKFILTER_RSEL_LSB)
#define BIASWLAN4_KICKBACKFILTER_RSEL_SET(x)                         (((0 | (x)) << BIASWLAN4_KICKBACKFILTER_RSEL_LSB) & BIASWLAN4_KICKBACKFILTER_RSEL_MASK)
#define BIASWLAN4_KICKBACKFILTER_RSEL_RESET                          0
#define BIASWLAN4_PWD_IC25SPAREB_MSB                                 9
#define BIASWLAN4_PWD_IC25SPAREB_LSB                                 7
#define BIASWLAN4_PWD_IC25SPAREB_MASK                                0x00000380
#define BIASWLAN4_PWD_IC25SPAREB_GET(x)                              (((x) & BIASWLAN4_PWD_IC25SPAREB_MASK) >> BIASWLAN4_PWD_IC25SPAREB_LSB)
#define BIASWLAN4_PWD_IC25SPAREB_SET(x)                              (((0 | (x)) << BIASWLAN4_PWD_IC25SPAREB_LSB) & BIASWLAN4_PWD_IC25SPAREB_MASK)
#define BIASWLAN4_PWD_IC25SPAREB_RESET                               3
#define BIASWLAN4_PWD_IR25SPARE_MSB                                  6
#define BIASWLAN4_PWD_IR25SPARE_LSB                                  4
#define BIASWLAN4_PWD_IR25SPARE_MASK                                 0x00000070
#define BIASWLAN4_PWD_IR25SPARE_GET(x)                               (((x) & BIASWLAN4_PWD_IR25SPARE_MASK) >> BIASWLAN4_PWD_IR25SPARE_LSB)
#define BIASWLAN4_PWD_IR25SPARE_SET(x)                               (((0 | (x)) << BIASWLAN4_PWD_IR25SPARE_LSB) & BIASWLAN4_PWD_IR25SPARE_MASK)
#define BIASWLAN4_PWD_IR25SPARE_RESET                                3
#define BIASWLAN4_SPARE4_MSB                                         3
#define BIASWLAN4_SPARE4_LSB                                         0
#define BIASWLAN4_SPARE4_MASK                                        0x0000000f
#define BIASWLAN4_SPARE4_GET(x)                                      (((x) & BIASWLAN4_SPARE4_MASK) >> BIASWLAN4_SPARE4_LSB)
#define BIASWLAN4_SPARE4_SET(x)                                      (((0 | (x)) << BIASWLAN4_SPARE4_LSB) & BIASWLAN4_SPARE4_MASK)
#define BIASWLAN4_SPARE4_RESET                                       0
#define BIASWLAN4_ADDRESS                                            0x000c
#define BIASWLAN4_HW_MASK                                            0xffffffff
#define BIASWLAN4_SW_MASK                                            0xffffffff
#define BIASWLAN4_HW_WRITE_MASK                                      0x00000000
#define BIASWLAN4_SW_WRITE_MASK                                      0xffffffff
#define BIASWLAN4_RSTMASK                                            0xffffffff
#define BIASWLAN4_RESET                                              0x6de6c1b0


#endif /* _BIASWLAN_REG_CSR_H_ */
