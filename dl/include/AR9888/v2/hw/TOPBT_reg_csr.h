//                                                                             
// File:       ./TOPBT_reg_csr.vrh                                             
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:42:39 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             TOPBT_reg_csr.rdl                                               
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/radio_peregrine/rtl/srif/blueprint/TOPBT_reg.rdl
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


#ifndef _TOPBT_REG_CSR_H_
#define _TOPBT_REG_CSR_H_
// 0x0000 (TOPBT1)
#define TOPBT1_ADC_ATB_MSB                                           31
#define TOPBT1_ADC_ATB_LSB                                           28
#define TOPBT1_ADC_ATB_MASK                                          0xf0000000
#define TOPBT1_ADC_ATB_GET(x)                                        (((x) & TOPBT1_ADC_ATB_MASK) >> TOPBT1_ADC_ATB_LSB)
#define TOPBT1_ADC_ATB_SET(x)                                        (((0 | (x)) << TOPBT1_ADC_ATB_LSB) & TOPBT1_ADC_ATB_MASK)
#define TOPBT1_ADC_ATB_RESET                                         0
#define TOPBT1_ADC_CLKDLY_MSB                                        27
#define TOPBT1_ADC_CLKDLY_LSB                                        27
#define TOPBT1_ADC_CLKDLY_MASK                                       0x08000000
#define TOPBT1_ADC_CLKDLY_GET(x)                                     (((x) & TOPBT1_ADC_CLKDLY_MASK) >> TOPBT1_ADC_CLKDLY_LSB)
#define TOPBT1_ADC_CLKDLY_SET(x)                                     (((0 | (x)) << TOPBT1_ADC_CLKDLY_LSB) & TOPBT1_ADC_CLKDLY_MASK)
#define TOPBT1_ADC_CLKDLY_RESET                                      0
#define TOPBT1_ADC_IAMP1C_MSB                                        26
#define TOPBT1_ADC_IAMP1C_LSB                                        24
#define TOPBT1_ADC_IAMP1C_MASK                                       0x07000000
#define TOPBT1_ADC_IAMP1C_GET(x)                                     (((x) & TOPBT1_ADC_IAMP1C_MASK) >> TOPBT1_ADC_IAMP1C_LSB)
#define TOPBT1_ADC_IAMP1C_SET(x)                                     (((0 | (x)) << TOPBT1_ADC_IAMP1C_LSB) & TOPBT1_ADC_IAMP1C_MASK)
#define TOPBT1_ADC_IAMP1C_RESET                                      4
#define TOPBT1_ADC_IAMP2C_MSB                                        23
#define TOPBT1_ADC_IAMP2C_LSB                                        21
#define TOPBT1_ADC_IAMP2C_MASK                                       0x00e00000
#define TOPBT1_ADC_IAMP2C_GET(x)                                     (((x) & TOPBT1_ADC_IAMP2C_MASK) >> TOPBT1_ADC_IAMP2C_LSB)
#define TOPBT1_ADC_IAMP2C_SET(x)                                     (((0 | (x)) << TOPBT1_ADC_IAMP2C_LSB) & TOPBT1_ADC_IAMP2C_MASK)
#define TOPBT1_ADC_IAMP2C_RESET                                      4
#define TOPBT1_ADC_IAMP3C_MSB                                        20
#define TOPBT1_ADC_IAMP3C_LSB                                        18
#define TOPBT1_ADC_IAMP3C_MASK                                       0x001c0000
#define TOPBT1_ADC_IAMP3C_GET(x)                                     (((x) & TOPBT1_ADC_IAMP3C_MASK) >> TOPBT1_ADC_IAMP3C_LSB)
#define TOPBT1_ADC_IAMP3C_SET(x)                                     (((0 | (x)) << TOPBT1_ADC_IAMP3C_LSB) & TOPBT1_ADC_IAMP3C_MASK)
#define TOPBT1_ADC_IAMP3C_RESET                                      4
#define TOPBT1_ADC_IREFC_MSB                                         17
#define TOPBT1_ADC_IREFC_LSB                                         15
#define TOPBT1_ADC_IREFC_MASK                                        0x00038000
#define TOPBT1_ADC_IREFC_GET(x)                                      (((x) & TOPBT1_ADC_IREFC_MASK) >> TOPBT1_ADC_IREFC_LSB)
#define TOPBT1_ADC_IREFC_SET(x)                                      (((0 | (x)) << TOPBT1_ADC_IREFC_LSB) & TOPBT1_ADC_IREFC_MASK)
#define TOPBT1_ADC_IREFC_RESET                                       4
#define TOPBT1_ADC_NEG2OUT_MSB                                       14
#define TOPBT1_ADC_NEG2OUT_LSB                                       14
#define TOPBT1_ADC_NEG2OUT_MASK                                      0x00004000
#define TOPBT1_ADC_NEG2OUT_GET(x)                                    (((x) & TOPBT1_ADC_NEG2OUT_MASK) >> TOPBT1_ADC_NEG2OUT_LSB)
#define TOPBT1_ADC_NEG2OUT_SET(x)                                    (((0 | (x)) << TOPBT1_ADC_NEG2OUT_LSB) & TOPBT1_ADC_NEG2OUT_MASK)
#define TOPBT1_ADC_NEG2OUT_RESET                                     0
#define TOPBT1_ADC_NEGOUT_MSB                                        13
#define TOPBT1_ADC_NEGOUT_LSB                                        13
#define TOPBT1_ADC_NEGOUT_MASK                                       0x00002000
#define TOPBT1_ADC_NEGOUT_GET(x)                                     (((x) & TOPBT1_ADC_NEGOUT_MASK) >> TOPBT1_ADC_NEGOUT_LSB)
#define TOPBT1_ADC_NEGOUT_SET(x)                                     (((0 | (x)) << TOPBT1_ADC_NEGOUT_LSB) & TOPBT1_ADC_NEGOUT_MASK)
#define TOPBT1_ADC_NEGOUT_RESET                                      0
#define TOPBT1_ADC_PWD_MSB                                           12
#define TOPBT1_ADC_PWD_LSB                                           12
#define TOPBT1_ADC_PWD_MASK                                          0x00001000
#define TOPBT1_ADC_PWD_GET(x)                                        (((x) & TOPBT1_ADC_PWD_MASK) >> TOPBT1_ADC_PWD_LSB)
#define TOPBT1_ADC_PWD_SET(x)                                        (((0 | (x)) << TOPBT1_ADC_PWD_LSB) & TOPBT1_ADC_PWD_MASK)
#define TOPBT1_ADC_PWD_RESET                                         0
#define TOPBT1_ADC_PWDQ_MSB                                          11
#define TOPBT1_ADC_PWDQ_LSB                                          11
#define TOPBT1_ADC_PWDQ_MASK                                         0x00000800
#define TOPBT1_ADC_PWDQ_GET(x)                                       (((x) & TOPBT1_ADC_PWDQ_MASK) >> TOPBT1_ADC_PWDQ_LSB)
#define TOPBT1_ADC_PWDQ_SET(x)                                       (((0 | (x)) << TOPBT1_ADC_PWDQ_LSB) & TOPBT1_ADC_PWDQ_MASK)
#define TOPBT1_ADC_PWDQ_RESET                                        0
#define TOPBT1_ADC_PWDSD21_MSB                                       10
#define TOPBT1_ADC_PWDSD21_LSB                                       10
#define TOPBT1_ADC_PWDSD21_MASK                                      0x00000400
#define TOPBT1_ADC_PWDSD21_GET(x)                                    (((x) & TOPBT1_ADC_PWDSD21_MASK) >> TOPBT1_ADC_PWDSD21_LSB)
#define TOPBT1_ADC_PWDSD21_SET(x)                                    (((0 | (x)) << TOPBT1_ADC_PWDSD21_LSB) & TOPBT1_ADC_PWDSD21_MASK)
#define TOPBT1_ADC_PWDSD21_RESET                                     0
#define TOPBT1_ADC_RST_MSB                                           9
#define TOPBT1_ADC_RST_LSB                                           9
#define TOPBT1_ADC_RST_MASK                                          0x00000200
#define TOPBT1_ADC_RST_GET(x)                                        (((x) & TOPBT1_ADC_RST_MASK) >> TOPBT1_ADC_RST_LSB)
#define TOPBT1_ADC_RST_SET(x)                                        (((0 | (x)) << TOPBT1_ADC_RST_LSB) & TOPBT1_ADC_RST_MASK)
#define TOPBT1_ADC_RST_RESET                                         0
#define TOPBT1_ADC_SHORTREFFILT_MSB                                  8
#define TOPBT1_ADC_SHORTREFFILT_LSB                                  8
#define TOPBT1_ADC_SHORTREFFILT_MASK                                 0x00000100
#define TOPBT1_ADC_SHORTREFFILT_GET(x)                               (((x) & TOPBT1_ADC_SHORTREFFILT_MASK) >> TOPBT1_ADC_SHORTREFFILT_LSB)
#define TOPBT1_ADC_SHORTREFFILT_SET(x)                               (((0 | (x)) << TOPBT1_ADC_SHORTREFFILT_LSB) & TOPBT1_ADC_SHORTREFFILT_MASK)
#define TOPBT1_ADC_SHORTREFFILT_RESET                                0
#define TOPBT1_PWDPLL_MSB                                            7
#define TOPBT1_PWDPLL_LSB                                            7
#define TOPBT1_PWDPLL_MASK                                           0x00000080
#define TOPBT1_PWDPLL_GET(x)                                         (((x) & TOPBT1_PWDPLL_MASK) >> TOPBT1_PWDPLL_LSB)
#define TOPBT1_PWDPLL_SET(x)                                         (((0 | (x)) << TOPBT1_PWDPLL_LSB) & TOPBT1_PWDPLL_MASK)
#define TOPBT1_PWDPLL_RESET                                          0
#define TOPBT1_ATB_INT2GND_MSB                                       6
#define TOPBT1_ATB_INT2GND_LSB                                       6
#define TOPBT1_ATB_INT2GND_MASK                                      0x00000040
#define TOPBT1_ATB_INT2GND_GET(x)                                    (((x) & TOPBT1_ATB_INT2GND_MASK) >> TOPBT1_ATB_INT2GND_LSB)
#define TOPBT1_ATB_INT2GND_SET(x)                                    (((0 | (x)) << TOPBT1_ATB_INT2GND_LSB) & TOPBT1_ATB_INT2GND_MASK)
#define TOPBT1_ATB_INT2GND_RESET                                     1
#define TOPBT1_ATB_INT2PAD_MSB                                       5
#define TOPBT1_ATB_INT2PAD_LSB                                       5
#define TOPBT1_ATB_INT2PAD_MASK                                      0x00000020
#define TOPBT1_ATB_INT2PAD_GET(x)                                    (((x) & TOPBT1_ATB_INT2PAD_MASK) >> TOPBT1_ATB_INT2PAD_LSB)
#define TOPBT1_ATB_INT2PAD_SET(x)                                    (((0 | (x)) << TOPBT1_ATB_INT2PAD_LSB) & TOPBT1_ATB_INT2PAD_MASK)
#define TOPBT1_ATB_INT2PAD_RESET                                     0
#define TOPBT1_ATB_INTH2GND_MSB                                      4
#define TOPBT1_ATB_INTH2GND_LSB                                      4
#define TOPBT1_ATB_INTH2GND_MASK                                     0x00000010
#define TOPBT1_ATB_INTH2GND_GET(x)                                   (((x) & TOPBT1_ATB_INTH2GND_MASK) >> TOPBT1_ATB_INTH2GND_LSB)
#define TOPBT1_ATB_INTH2GND_SET(x)                                   (((0 | (x)) << TOPBT1_ATB_INTH2GND_LSB) & TOPBT1_ATB_INTH2GND_MASK)
#define TOPBT1_ATB_INTH2GND_RESET                                    1
#define TOPBT1_ATB_INTH2PAD_MSB                                      3
#define TOPBT1_ATB_INTH2PAD_LSB                                      3
#define TOPBT1_ATB_INTH2PAD_MASK                                     0x00000008
#define TOPBT1_ATB_INTH2PAD_GET(x)                                   (((x) & TOPBT1_ATB_INTH2PAD_MASK) >> TOPBT1_ATB_INTH2PAD_LSB)
#define TOPBT1_ATB_INTH2PAD_SET(x)                                   (((0 | (x)) << TOPBT1_ATB_INTH2PAD_LSB) & TOPBT1_ATB_INTH2PAD_MASK)
#define TOPBT1_ATB_INTH2PAD_RESET                                    0
#define TOPBT1_ATB_PAD2GND_MSB                                       2
#define TOPBT1_ATB_PAD2GND_LSB                                       2
#define TOPBT1_ATB_PAD2GND_MASK                                      0x00000004
#define TOPBT1_ATB_PAD2GND_GET(x)                                    (((x) & TOPBT1_ATB_PAD2GND_MASK) >> TOPBT1_ATB_PAD2GND_LSB)
#define TOPBT1_ATB_PAD2GND_SET(x)                                    (((0 | (x)) << TOPBT1_ATB_PAD2GND_LSB) & TOPBT1_ATB_PAD2GND_MASK)
#define TOPBT1_ATB_PAD2GND_RESET                                     0
#define TOPBT1_PWDLPO_MSB                                            1
#define TOPBT1_PWDLPO_LSB                                            1
#define TOPBT1_PWDLPO_MASK                                           0x00000002
#define TOPBT1_PWDLPO_GET(x)                                         (((x) & TOPBT1_PWDLPO_MASK) >> TOPBT1_PWDLPO_LSB)
#define TOPBT1_PWDLPO_SET(x)                                         (((0 | (x)) << TOPBT1_PWDLPO_LSB) & TOPBT1_PWDLPO_MASK)
#define TOPBT1_PWDLPO_RESET                                          0
#define TOPBT1_PWDSHPA_MSB                                           0
#define TOPBT1_PWDSHPA_LSB                                           0
#define TOPBT1_PWDSHPA_MASK                                          0x00000001
#define TOPBT1_PWDSHPA_GET(x)                                        (((x) & TOPBT1_PWDSHPA_MASK) >> TOPBT1_PWDSHPA_LSB)
#define TOPBT1_PWDSHPA_SET(x)                                        (((0 | (x)) << TOPBT1_PWDSHPA_LSB) & TOPBT1_PWDSHPA_MASK)
#define TOPBT1_PWDSHPA_RESET                                         0
#define TOPBT1_ADDRESS                                               0x0000
#define TOPBT1_HW_MASK                                               0xffffffff
#define TOPBT1_SW_MASK                                               0xffffffff
#define TOPBT1_HW_WRITE_MASK                                         0x00000000
#define TOPBT1_SW_WRITE_MASK                                         0xffffffff
#define TOPBT1_RSTMASK                                               0xffffffff
#define TOPBT1_RESET                                                 0x04920050

// 0x0004 (TOPBT2)
#define TOPBT2_BIAS_RBIAS_MSB                                        31
#define TOPBT2_BIAS_RBIAS_LSB                                        26
#define TOPBT2_BIAS_RBIAS_MASK                                       0xfc000000
#define TOPBT2_BIAS_RBIAS_GET(x)                                     (((x) & TOPBT2_BIAS_RBIAS_MASK) >> TOPBT2_BIAS_RBIAS_LSB)
#define TOPBT2_BIAS_RBIAS_SET(x)                                     (((0 | (x)) << TOPBT2_BIAS_RBIAS_LSB) & TOPBT2_BIAS_RBIAS_MASK)
#define TOPBT2_BIAS_RBIAS_RESET                                      0
#define TOPBT2_BIAS_PWDBG_MSB                                        25
#define TOPBT2_BIAS_PWDBG_LSB                                        25
#define TOPBT2_BIAS_PWDBG_MASK                                       0x02000000
#define TOPBT2_BIAS_PWDBG_GET(x)                                     (((x) & TOPBT2_BIAS_PWDBG_MASK) >> TOPBT2_BIAS_PWDBG_LSB)
#define TOPBT2_BIAS_PWDBG_SET(x)                                     (((0 | (x)) << TOPBT2_BIAS_PWDBG_LSB) & TOPBT2_BIAS_PWDBG_MASK)
#define TOPBT2_BIAS_PWDBG_RESET                                      0
#define TOPBT2_BIAS_PWDCGM_MSB                                       24
#define TOPBT2_BIAS_PWDCGM_LSB                                       24
#define TOPBT2_BIAS_PWDCGM_MASK                                      0x01000000
#define TOPBT2_BIAS_PWDCGM_GET(x)                                    (((x) & TOPBT2_BIAS_PWDCGM_MASK) >> TOPBT2_BIAS_PWDCGM_LSB)
#define TOPBT2_BIAS_PWDCGM_SET(x)                                    (((0 | (x)) << TOPBT2_BIAS_PWDCGM_LSB) & TOPBT2_BIAS_PWDCGM_MASK)
#define TOPBT2_BIAS_PWDCGM_RESET                                     0
#define TOPBT2_BIAS_PWDMIRRORS_MSB                                   23
#define TOPBT2_BIAS_PWDMIRRORS_LSB                                   23
#define TOPBT2_BIAS_PWDMIRRORS_MASK                                  0x00800000
#define TOPBT2_BIAS_PWDMIRRORS_GET(x)                                (((x) & TOPBT2_BIAS_PWDMIRRORS_MASK) >> TOPBT2_BIAS_PWDMIRRORS_LSB)
#define TOPBT2_BIAS_PWDMIRRORS_SET(x)                                (((0 | (x)) << TOPBT2_BIAS_PWDMIRRORS_LSB) & TOPBT2_BIAS_PWDMIRRORS_MASK)
#define TOPBT2_BIAS_PWDMIRRORS_RESET                                 0
#define TOPBT2_BIAS_PWDV2I_MSB                                       22
#define TOPBT2_BIAS_PWDV2I_LSB                                       22
#define TOPBT2_BIAS_PWDV2I_MASK                                      0x00400000
#define TOPBT2_BIAS_PWDV2I_GET(x)                                    (((x) & TOPBT2_BIAS_PWDV2I_MASK) >> TOPBT2_BIAS_PWDV2I_LSB)
#define TOPBT2_BIAS_PWDV2I_SET(x)                                    (((0 | (x)) << TOPBT2_BIAS_PWDV2I_LSB) & TOPBT2_BIAS_PWDV2I_MASK)
#define TOPBT2_BIAS_PWDV2I_RESET                                     0
#define TOPBT2_CALTX_MSB                                             21
#define TOPBT2_CALTX_LSB                                             21
#define TOPBT2_CALTX_MASK                                            0x00200000
#define TOPBT2_CALTX_GET(x)                                          (((x) & TOPBT2_CALTX_MASK) >> TOPBT2_CALTX_LSB)
#define TOPBT2_CALTX_SET(x)                                          (((0 | (x)) << TOPBT2_CALTX_LSB) & TOPBT2_CALTX_MASK)
#define TOPBT2_CALTX_RESET                                           0
#define TOPBT2_CALPA_MSB                                             20
#define TOPBT2_CALPA_LSB                                             20
#define TOPBT2_CALPA_MASK                                            0x00100000
#define TOPBT2_CALPA_GET(x)                                          (((x) & TOPBT2_CALPA_MASK) >> TOPBT2_CALPA_LSB)
#define TOPBT2_CALPA_SET(x)                                          (((0 | (x)) << TOPBT2_CALPA_LSB) & TOPBT2_CALPA_MASK)
#define TOPBT2_CALPA_RESET                                           0
#define TOPBT2_FE_ATB_MSB                                            19
#define TOPBT2_FE_ATB_LSB                                            17
#define TOPBT2_FE_ATB_MASK                                           0x000e0000
#define TOPBT2_FE_ATB_GET(x)                                         (((x) & TOPBT2_FE_ATB_MASK) >> TOPBT2_FE_ATB_LSB)
#define TOPBT2_FE_ATB_SET(x)                                         (((0 | (x)) << TOPBT2_FE_ATB_LSB) & TOPBT2_FE_ATB_MASK)
#define TOPBT2_FE_ATB_RESET                                          0
#define TOPBT2_FE_TXMOD_MSB                                          16
#define TOPBT2_FE_TXMOD_LSB                                          15
#define TOPBT2_FE_TXMOD_MASK                                         0x00018000
#define TOPBT2_FE_TXMOD_GET(x)                                       (((x) & TOPBT2_FE_TXMOD_MASK) >> TOPBT2_FE_TXMOD_LSB)
#define TOPBT2_FE_TXMOD_SET(x)                                       (((0 | (x)) << TOPBT2_FE_TXMOD_LSB) & TOPBT2_FE_TXMOD_MASK)
#define TOPBT2_FE_TXMOD_RESET                                        0
#define TOPBT2_FE_DB0_MSB                                            14
#define TOPBT2_FE_DB0_LSB                                            12
#define TOPBT2_FE_DB0_MASK                                           0x00007000
#define TOPBT2_FE_DB0_GET(x)                                         (((x) & TOPBT2_FE_DB0_MASK) >> TOPBT2_FE_DB0_LSB)
#define TOPBT2_FE_DB0_SET(x)                                         (((0 | (x)) << TOPBT2_FE_DB0_LSB) & TOPBT2_FE_DB0_MASK)
#define TOPBT2_FE_DB0_RESET                                          4
#define TOPBT2_FE_DB1_MSB                                            11
#define TOPBT2_FE_DB1_LSB                                            9
#define TOPBT2_FE_DB1_MASK                                           0x00000e00
#define TOPBT2_FE_DB1_GET(x)                                         (((x) & TOPBT2_FE_DB1_MASK) >> TOPBT2_FE_DB1_LSB)
#define TOPBT2_FE_DB1_SET(x)                                         (((0 | (x)) << TOPBT2_FE_DB1_LSB) & TOPBT2_FE_DB1_MASK)
#define TOPBT2_FE_DB1_RESET                                          4
#define TOPBT2_FE_DB2_MSB                                            8
#define TOPBT2_FE_DB2_LSB                                            6
#define TOPBT2_FE_DB2_MASK                                           0x000001c0
#define TOPBT2_FE_DB2_GET(x)                                         (((x) & TOPBT2_FE_DB2_MASK) >> TOPBT2_FE_DB2_LSB)
#define TOPBT2_FE_DB2_SET(x)                                         (((0 | (x)) << TOPBT2_FE_DB2_LSB) & TOPBT2_FE_DB2_MASK)
#define TOPBT2_FE_DB2_RESET                                          4
#define TOPBT2_FE_DB3_MSB                                            5
#define TOPBT2_FE_DB3_LSB                                            3
#define TOPBT2_FE_DB3_MASK                                           0x00000038
#define TOPBT2_FE_DB3_GET(x)                                         (((x) & TOPBT2_FE_DB3_MASK) >> TOPBT2_FE_DB3_LSB)
#define TOPBT2_FE_DB3_SET(x)                                         (((0 | (x)) << TOPBT2_FE_DB3_LSB) & TOPBT2_FE_DB3_MASK)
#define TOPBT2_FE_DB3_RESET                                          4
#define TOPBT2_SHLNAGN_MSB                                           2
#define TOPBT2_SHLNAGN_LSB                                           0
#define TOPBT2_SHLNAGN_MASK                                          0x00000007
#define TOPBT2_SHLNAGN_GET(x)                                        (((x) & TOPBT2_SHLNAGN_MASK) >> TOPBT2_SHLNAGN_LSB)
#define TOPBT2_SHLNAGN_SET(x)                                        (((0 | (x)) << TOPBT2_SHLNAGN_LSB) & TOPBT2_SHLNAGN_MASK)
#define TOPBT2_SHLNAGN_RESET                                         7
#define TOPBT2_ADDRESS                                               0x0004
#define TOPBT2_HW_MASK                                               0xffffffff
#define TOPBT2_SW_MASK                                               0xffffffff
#define TOPBT2_HW_WRITE_MASK                                         0x00000000
#define TOPBT2_SW_WRITE_MASK                                         0xffffffff
#define TOPBT2_RSTMASK                                               0xffffffff
#define TOPBT2_RESET                                                 0x00004927

// 0x0008 (TOPBT3)
#define TOPBT3_FE_LNAGN_MSB                                          31
#define TOPBT3_FE_LNAGN_LSB                                          29
#define TOPBT3_FE_LNAGN_MASK                                         0xe0000000
#define TOPBT3_FE_LNAGN_GET(x)                                       (((x) & TOPBT3_FE_LNAGN_MASK) >> TOPBT3_FE_LNAGN_LSB)
#define TOPBT3_FE_LNAGN_SET(x)                                       (((0 | (x)) << TOPBT3_FE_LNAGN_LSB) & TOPBT3_FE_LNAGN_MASK)
#define TOPBT3_FE_LNAGN_RESET                                        7
#define TOPBT3_FE_LNAON_MSB                                          28
#define TOPBT3_FE_LNAON_LSB                                          28
#define TOPBT3_FE_LNAON_MASK                                         0x10000000
#define TOPBT3_FE_LNAON_GET(x)                                       (((x) & TOPBT3_FE_LNAON_MASK) >> TOPBT3_FE_LNAON_LSB)
#define TOPBT3_FE_LNAON_SET(x)                                       (((0 | (x)) << TOPBT3_FE_LNAON_LSB) & TOPBT3_FE_LNAON_MASK)
#define TOPBT3_FE_LNAON_RESET                                        1
#define TOPBT3_FE_SELLNA_MSB                                         27
#define TOPBT3_FE_SELLNA_LSB                                         27
#define TOPBT3_FE_SELLNA_MASK                                        0x08000000
#define TOPBT3_FE_SELLNA_GET(x)                                      (((x) & TOPBT3_FE_SELLNA_MASK) >> TOPBT3_FE_SELLNA_LSB)
#define TOPBT3_FE_SELLNA_SET(x)                                      (((0 | (x)) << TOPBT3_FE_SELLNA_LSB) & TOPBT3_FE_SELLNA_MASK)
#define TOPBT3_FE_SELLNA_RESET                                       0
#define TOPBT3_FE_TRSW_TXEN_MSB                                      26
#define TOPBT3_FE_TRSW_TXEN_LSB                                      26
#define TOPBT3_FE_TRSW_TXEN_MASK                                     0x04000000
#define TOPBT3_FE_TRSW_TXEN_GET(x)                                   (((x) & TOPBT3_FE_TRSW_TXEN_MASK) >> TOPBT3_FE_TRSW_TXEN_LSB)
#define TOPBT3_FE_TRSW_TXEN_SET(x)                                   (((0 | (x)) << TOPBT3_FE_TRSW_TXEN_LSB) & TOPBT3_FE_TRSW_TXEN_MASK)
#define TOPBT3_FE_TRSW_TXEN_RESET                                    1
#define TOPBT3_FE_CREF_MSB                                           25
#define TOPBT3_FE_CREF_LSB                                           24
#define TOPBT3_FE_CREF_MASK                                          0x03000000
#define TOPBT3_FE_CREF_GET(x)                                        (((x) & TOPBT3_FE_CREF_MASK) >> TOPBT3_FE_CREF_LSB)
#define TOPBT3_FE_CREF_SET(x)                                        (((0 | (x)) << TOPBT3_FE_CREF_LSB) & TOPBT3_FE_CREF_MASK)
#define TOPBT3_FE_CREF_RESET                                         2
#define TOPBT3_FE_OB0_MSB                                            23
#define TOPBT3_FE_OB0_LSB                                            21
#define TOPBT3_FE_OB0_MASK                                           0x00e00000
#define TOPBT3_FE_OB0_GET(x)                                         (((x) & TOPBT3_FE_OB0_MASK) >> TOPBT3_FE_OB0_LSB)
#define TOPBT3_FE_OB0_SET(x)                                         (((0 | (x)) << TOPBT3_FE_OB0_LSB) & TOPBT3_FE_OB0_MASK)
#define TOPBT3_FE_OB0_RESET                                          3
#define TOPBT3_FE_OB1_MSB                                            20
#define TOPBT3_FE_OB1_LSB                                            18
#define TOPBT3_FE_OB1_MASK                                           0x001c0000
#define TOPBT3_FE_OB1_GET(x)                                         (((x) & TOPBT3_FE_OB1_MASK) >> TOPBT3_FE_OB1_LSB)
#define TOPBT3_FE_OB1_SET(x)                                         (((0 | (x)) << TOPBT3_FE_OB1_LSB) & TOPBT3_FE_OB1_MASK)
#define TOPBT3_FE_OB1_RESET                                          3
#define TOPBT3_FE_OB2_MSB                                            17
#define TOPBT3_FE_OB2_LSB                                            15
#define TOPBT3_FE_OB2_MASK                                           0x00038000
#define TOPBT3_FE_OB2_GET(x)                                         (((x) & TOPBT3_FE_OB2_MASK) >> TOPBT3_FE_OB2_LSB)
#define TOPBT3_FE_OB2_SET(x)                                         (((0 | (x)) << TOPBT3_FE_OB2_LSB) & TOPBT3_FE_OB2_MASK)
#define TOPBT3_FE_OB2_RESET                                          3
#define TOPBT3_FE_OB3_MSB                                            14
#define TOPBT3_FE_OB3_LSB                                            12
#define TOPBT3_FE_OB3_MASK                                           0x00007000
#define TOPBT3_FE_OB3_GET(x)                                         (((x) & TOPBT3_FE_OB3_MASK) >> TOPBT3_FE_OB3_LSB)
#define TOPBT3_FE_OB3_SET(x)                                         (((0 | (x)) << TOPBT3_FE_OB3_LSB) & TOPBT3_FE_OB3_MASK)
#define TOPBT3_FE_OB3_RESET                                          3
#define TOPBT3_FE_PADRVGN_MSB                                        11
#define TOPBT3_FE_PADRVGN_LSB                                        9
#define TOPBT3_FE_PADRVGN_MASK                                       0x00000e00
#define TOPBT3_FE_PADRVGN_GET(x)                                     (((x) & TOPBT3_FE_PADRVGN_MASK) >> TOPBT3_FE_PADRVGN_LSB)
#define TOPBT3_FE_PADRVGN_SET(x)                                     (((0 | (x)) << TOPBT3_FE_PADRVGN_LSB) & TOPBT3_FE_PADRVGN_MASK)
#define TOPBT3_FE_PADRVGN_RESET                                      7
#define TOPBT3_FE_PAOUTGN_MSB                                        8
#define TOPBT3_FE_PAOUTGN_LSB                                        6
#define TOPBT3_FE_PAOUTGN_MASK                                       0x000001c0
#define TOPBT3_FE_PAOUTGN_GET(x)                                     (((x) & TOPBT3_FE_PAOUTGN_MASK) >> TOPBT3_FE_PAOUTGN_LSB)
#define TOPBT3_FE_PAOUTGN_SET(x)                                     (((0 | (x)) << TOPBT3_FE_PAOUTGN_LSB) & TOPBT3_FE_PAOUTGN_MASK)
#define TOPBT3_FE_PAOUTGN_RESET                                      7
#define TOPBT3_FE_PASUPPLYSWITCH_MSB                                 5
#define TOPBT3_FE_PASUPPLYSWITCH_LSB                                 5
#define TOPBT3_FE_PASUPPLYSWITCH_MASK                                0x00000020
#define TOPBT3_FE_PASUPPLYSWITCH_GET(x)                              (((x) & TOPBT3_FE_PASUPPLYSWITCH_MASK) >> TOPBT3_FE_PASUPPLYSWITCH_LSB)
#define TOPBT3_FE_PASUPPLYSWITCH_SET(x)                              (((0 | (x)) << TOPBT3_FE_PASUPPLYSWITCH_LSB) & TOPBT3_FE_PASUPPLYSWITCH_MASK)
#define TOPBT3_FE_PASUPPLYSWITCH_RESET                               0
#define TOPBT3_FE_PHASE_MSB                                          4
#define TOPBT3_FE_PHASE_LSB                                          4
#define TOPBT3_FE_PHASE_MASK                                         0x00000010
#define TOPBT3_FE_PHASE_GET(x)                                       (((x) & TOPBT3_FE_PHASE_MASK) >> TOPBT3_FE_PHASE_LSB)
#define TOPBT3_FE_PHASE_SET(x)                                       (((0 | (x)) << TOPBT3_FE_PHASE_LSB) & TOPBT3_FE_PHASE_MASK)
#define TOPBT3_FE_PHASE_RESET                                        0
#define TOPBT3_FE_PWDDBIAS_MSB                                       3
#define TOPBT3_FE_PWDDBIAS_LSB                                       3
#define TOPBT3_FE_PWDDBIAS_MASK                                      0x00000008
#define TOPBT3_FE_PWDDBIAS_GET(x)                                    (((x) & TOPBT3_FE_PWDDBIAS_MASK) >> TOPBT3_FE_PWDDBIAS_LSB)
#define TOPBT3_FE_PWDDBIAS_SET(x)                                    (((0 | (x)) << TOPBT3_FE_PWDDBIAS_LSB) & TOPBT3_FE_PWDDBIAS_MASK)
#define TOPBT3_FE_PWDDBIAS_RESET                                     0
#define TOPBT3_FE_PWDDGAIN_MSB                                       2
#define TOPBT3_FE_PWDDGAIN_LSB                                       2
#define TOPBT3_FE_PWDDGAIN_MASK                                      0x00000004
#define TOPBT3_FE_PWDDGAIN_GET(x)                                    (((x) & TOPBT3_FE_PWDDGAIN_MASK) >> TOPBT3_FE_PWDDGAIN_LSB)
#define TOPBT3_FE_PWDDGAIN_SET(x)                                    (((0 | (x)) << TOPBT3_FE_PWDDGAIN_LSB) & TOPBT3_FE_PWDDGAIN_MASK)
#define TOPBT3_FE_PWDDGAIN_RESET                                     0
#define TOPBT3_FE_PWDPAOUT_MSB                                       1
#define TOPBT3_FE_PWDPAOUT_LSB                                       1
#define TOPBT3_FE_PWDPAOUT_MASK                                      0x00000002
#define TOPBT3_FE_PWDPAOUT_GET(x)                                    (((x) & TOPBT3_FE_PWDPAOUT_MASK) >> TOPBT3_FE_PWDPAOUT_LSB)
#define TOPBT3_FE_PWDPAOUT_SET(x)                                    (((0 | (x)) << TOPBT3_FE_PWDPAOUT_LSB) & TOPBT3_FE_PWDPAOUT_MASK)
#define TOPBT3_FE_PWDPAOUT_RESET                                     0
#define TOPBT3_FORCE_OSCON_MSB                                       0
#define TOPBT3_FORCE_OSCON_LSB                                       0
#define TOPBT3_FORCE_OSCON_MASK                                      0x00000001
#define TOPBT3_FORCE_OSCON_GET(x)                                    (((x) & TOPBT3_FORCE_OSCON_MASK) >> TOPBT3_FORCE_OSCON_LSB)
#define TOPBT3_FORCE_OSCON_SET(x)                                    (((0 | (x)) << TOPBT3_FORCE_OSCON_LSB) & TOPBT3_FORCE_OSCON_MASK)
#define TOPBT3_FORCE_OSCON_RESET                                     0
#define TOPBT3_ADDRESS                                               0x0008
#define TOPBT3_HW_MASK                                               0xffffffff
#define TOPBT3_SW_MASK                                               0xffffffff
#define TOPBT3_HW_WRITE_MASK                                         0x00000000
#define TOPBT3_SW_WRITE_MASK                                         0xffffffff
#define TOPBT3_RSTMASK                                               0xffffffff
#define TOPBT3_RESET                                                 0xf66dbfc0

// 0x000c (TOPBT4)
#define TOPBT4_FORCE_RXTXLO_MSB                                      31
#define TOPBT4_FORCE_RXTXLO_LSB                                      31
#define TOPBT4_FORCE_RXTXLO_MASK                                     0x80000000
#define TOPBT4_FORCE_RXTXLO_GET(x)                                   (((x) & TOPBT4_FORCE_RXTXLO_MASK) >> TOPBT4_FORCE_RXTXLO_LSB)
#define TOPBT4_FORCE_RXTXLO_SET(x)                                   (((0 | (x)) << TOPBT4_FORCE_RXTXLO_LSB) & TOPBT4_FORCE_RXTXLO_MASK)
#define TOPBT4_FORCE_RXTXLO_RESET                                    0
#define TOPBT4_FORCE_SCLKEN_MSB                                      30
#define TOPBT4_FORCE_SCLKEN_LSB                                      30
#define TOPBT4_FORCE_SCLKEN_MASK                                     0x40000000
#define TOPBT4_FORCE_SCLKEN_GET(x)                                   (((x) & TOPBT4_FORCE_SCLKEN_MASK) >> TOPBT4_FORCE_SCLKEN_LSB)
#define TOPBT4_FORCE_SCLKEN_SET(x)                                   (((0 | (x)) << TOPBT4_FORCE_SCLKEN_LSB) & TOPBT4_FORCE_SCLKEN_MASK)
#define TOPBT4_FORCE_SCLKEN_RESET                                    0
#define TOPBT4_FORCE_SYNTHON_MSB                                     29
#define TOPBT4_FORCE_SYNTHON_LSB                                     29
#define TOPBT4_FORCE_SYNTHON_MASK                                    0x20000000
#define TOPBT4_FORCE_SYNTHON_GET(x)                                  (((x) & TOPBT4_FORCE_SYNTHON_MASK) >> TOPBT4_FORCE_SYNTHON_LSB)
#define TOPBT4_FORCE_SYNTHON_SET(x)                                  (((0 | (x)) << TOPBT4_FORCE_SYNTHON_LSB) & TOPBT4_FORCE_SYNTHON_MASK)
#define TOPBT4_FORCE_SYNTHON_RESET                                   0
#define TOPBT4_LO_ATB_MSB                                            28
#define TOPBT4_LO_ATB_LSB                                            26
#define TOPBT4_LO_ATB_MASK                                           0x1c000000
#define TOPBT4_LO_ATB_GET(x)                                         (((x) & TOPBT4_LO_ATB_MASK) >> TOPBT4_LO_ATB_LSB)
#define TOPBT4_LO_ATB_SET(x)                                         (((0 | (x)) << TOPBT4_LO_ATB_LSB) & TOPBT4_LO_ATB_MASK)
#define TOPBT4_LO_ATB_RESET                                          0
#define TOPBT4_LO_PWDLORX_MSB                                        25
#define TOPBT4_LO_PWDLORX_LSB                                        25
#define TOPBT4_LO_PWDLORX_MASK                                       0x02000000
#define TOPBT4_LO_PWDLORX_GET(x)                                     (((x) & TOPBT4_LO_PWDLORX_MASK) >> TOPBT4_LO_PWDLORX_LSB)
#define TOPBT4_LO_PWDLORX_SET(x)                                     (((0 | (x)) << TOPBT4_LO_PWDLORX_LSB) & TOPBT4_LO_PWDLORX_MASK)
#define TOPBT4_LO_PWDLORX_RESET                                      0
#define TOPBT4_LO_PWDLOTX_MSB                                        24
#define TOPBT4_LO_PWDLOTX_LSB                                        24
#define TOPBT4_LO_PWDLOTX_MASK                                       0x01000000
#define TOPBT4_LO_PWDLOTX_GET(x)                                     (((x) & TOPBT4_LO_PWDLOTX_MASK) >> TOPBT4_LO_PWDLOTX_LSB)
#define TOPBT4_LO_PWDLOTX_SET(x)                                     (((0 | (x)) << TOPBT4_LO_PWDLOTX_LSB) & TOPBT4_LO_PWDLOTX_MASK)
#define TOPBT4_LO_PWDLOTX_RESET                                      0
#define TOPBT4_LO_DIVON_IF_SYNTHON_MSB                               23
#define TOPBT4_LO_DIVON_IF_SYNTHON_LSB                               23
#define TOPBT4_LO_DIVON_IF_SYNTHON_MASK                              0x00800000
#define TOPBT4_LO_DIVON_IF_SYNTHON_GET(x)                            (((x) & TOPBT4_LO_DIVON_IF_SYNTHON_MASK) >> TOPBT4_LO_DIVON_IF_SYNTHON_LSB)
#define TOPBT4_LO_DIVON_IF_SYNTHON_SET(x)                            (((0 | (x)) << TOPBT4_LO_DIVON_IF_SYNTHON_LSB) & TOPBT4_LO_DIVON_IF_SYNTHON_MASK)
#define TOPBT4_LO_DIVON_IF_SYNTHON_RESET                             0
#define TOPBT4_LOCALADDAC_MSB                                        22
#define TOPBT4_LOCALADDAC_LSB                                        22
#define TOPBT4_LOCALADDAC_MASK                                       0x00400000
#define TOPBT4_LOCALADDAC_GET(x)                                     (((x) & TOPBT4_LOCALADDAC_MASK) >> TOPBT4_LOCALADDAC_LSB)
#define TOPBT4_LOCALADDAC_SET(x)                                     (((0 | (x)) << TOPBT4_LOCALADDAC_LSB) & TOPBT4_LOCALADDAC_MASK)
#define TOPBT4_LOCALADDAC_RESET                                      0
#define TOPBT4_LOCALMODE_MSB                                         21
#define TOPBT4_LOCALMODE_LSB                                         21
#define TOPBT4_LOCALMODE_MASK                                        0x00200000
#define TOPBT4_LOCALMODE_GET(x)                                      (((x) & TOPBT4_LOCALMODE_MASK) >> TOPBT4_LOCALMODE_LSB)
#define TOPBT4_LOCALMODE_SET(x)                                      (((0 | (x)) << TOPBT4_LOCALMODE_LSB) & TOPBT4_LOCALMODE_MASK)
#define TOPBT4_LOCALMODE_RESET                                       0
#define TOPBT4_LOCALRXAGC_MSB                                        20
#define TOPBT4_LOCALRXAGC_LSB                                        20
#define TOPBT4_LOCALRXAGC_MASK                                       0x00100000
#define TOPBT4_LOCALRXAGC_GET(x)                                     (((x) & TOPBT4_LOCALRXAGC_MASK) >> TOPBT4_LOCALRXAGC_LSB)
#define TOPBT4_LOCALRXAGC_SET(x)                                     (((0 | (x)) << TOPBT4_LOCALRXAGC_LSB) & TOPBT4_LOCALRXAGC_MASK)
#define TOPBT4_LOCALRXAGC_RESET                                      0
#define TOPBT4_LOCALRXGAIN_MSB                                       19
#define TOPBT4_LOCALRXGAIN_LSB                                       19
#define TOPBT4_LOCALRXGAIN_MASK                                      0x00080000
#define TOPBT4_LOCALRXGAIN_GET(x)                                    (((x) & TOPBT4_LOCALRXGAIN_MASK) >> TOPBT4_LOCALRXGAIN_LSB)
#define TOPBT4_LOCALRXGAIN_SET(x)                                    (((0 | (x)) << TOPBT4_LOCALRXGAIN_LSB) & TOPBT4_LOCALRXGAIN_MASK)
#define TOPBT4_LOCALRXGAIN_RESET                                     0
#define TOPBT4_LOCALSYNTH_MSB                                        18
#define TOPBT4_LOCALSYNTH_LSB                                        18
#define TOPBT4_LOCALSYNTH_MASK                                       0x00040000
#define TOPBT4_LOCALSYNTH_GET(x)                                     (((x) & TOPBT4_LOCALSYNTH_MASK) >> TOPBT4_LOCALSYNTH_LSB)
#define TOPBT4_LOCALSYNTH_SET(x)                                     (((0 | (x)) << TOPBT4_LOCALSYNTH_LSB) & TOPBT4_LOCALSYNTH_MASK)
#define TOPBT4_LOCALSYNTH_RESET                                      0
#define TOPBT4_LOCALTXGAIN_MSB                                       17
#define TOPBT4_LOCALTXGAIN_LSB                                       17
#define TOPBT4_LOCALTXGAIN_MASK                                      0x00020000
#define TOPBT4_LOCALTXGAIN_GET(x)                                    (((x) & TOPBT4_LOCALTXGAIN_MASK) >> TOPBT4_LOCALTXGAIN_LSB)
#define TOPBT4_LOCALTXGAIN_SET(x)                                    (((0 | (x)) << TOPBT4_LOCALTXGAIN_LSB) & TOPBT4_LOCALTXGAIN_MASK)
#define TOPBT4_LOCALTXGAIN_RESET                                     0
#define TOPBT4_LOCALPWD_MSB                                          16
#define TOPBT4_LOCALPWD_LSB                                          16
#define TOPBT4_LOCALPWD_MASK                                         0x00010000
#define TOPBT4_LOCALPWD_GET(x)                                       (((x) & TOPBT4_LOCALPWD_MASK) >> TOPBT4_LOCALPWD_LSB)
#define TOPBT4_LOCALPWD_SET(x)                                       (((0 | (x)) << TOPBT4_LOCALPWD_LSB) & TOPBT4_LOCALPWD_MASK)
#define TOPBT4_LOCALPWD_RESET                                        0
#define TOPBT4_LOCALTRSW_MSB                                         15
#define TOPBT4_LOCALTRSW_LSB                                         15
#define TOPBT4_LOCALTRSW_MASK                                        0x00008000
#define TOPBT4_LOCALTRSW_GET(x)                                      (((x) & TOPBT4_LOCALTRSW_MASK) >> TOPBT4_LOCALTRSW_LSB)
#define TOPBT4_LOCALTRSW_SET(x)                                      (((0 | (x)) << TOPBT4_LOCALTRSW_LSB) & TOPBT4_LOCALTRSW_MASK)
#define TOPBT4_LOCALTRSW_RESET                                       0
#define TOPBT4_LOCALRBIAS_MSB                                        14
#define TOPBT4_LOCALRBIAS_LSB                                        14
#define TOPBT4_LOCALRBIAS_MASK                                       0x00004000
#define TOPBT4_LOCALRBIAS_GET(x)                                     (((x) & TOPBT4_LOCALRBIAS_MASK) >> TOPBT4_LOCALRBIAS_LSB)
#define TOPBT4_LOCALRBIAS_SET(x)                                     (((0 | (x)) << TOPBT4_LOCALRBIAS_LSB) & TOPBT4_LOCALRBIAS_MASK)
#define TOPBT4_LOCALRBIAS_RESET                                      0
#define TOPBT4_RXAGCPWD_MSB                                          13
#define TOPBT4_RXAGCPWD_LSB                                          13
#define TOPBT4_RXAGCPWD_MASK                                         0x00002000
#define TOPBT4_RXAGCPWD_GET(x)                                       (((x) & TOPBT4_RXAGCPWD_MASK) >> TOPBT4_RXAGCPWD_LSB)
#define TOPBT4_RXAGCPWD_SET(x)                                       (((0 | (x)) << TOPBT4_RXAGCPWD_LSB) & TOPBT4_RXAGCPWD_MASK)
#define TOPBT4_RXAGCPWD_RESET                                        1
#define TOPBT4_RXAGCCAL_MSB                                          12
#define TOPBT4_RXAGCCAL_LSB                                          12
#define TOPBT4_RXAGCCAL_MASK                                         0x00001000
#define TOPBT4_RXAGCCAL_GET(x)                                       (((x) & TOPBT4_RXAGCCAL_MASK) >> TOPBT4_RXAGCCAL_LSB)
#define TOPBT4_RXAGCCAL_SET(x)                                       (((0 | (x)) << TOPBT4_RXAGCCAL_LSB) & TOPBT4_RXAGCCAL_MASK)
#define TOPBT4_RXAGCCAL_RESET                                        0
#define TOPBT4_RXAGCCALTH_MSB                                        11
#define TOPBT4_RXAGCCALTH_LSB                                        6
#define TOPBT4_RXAGCCALTH_MASK                                       0x00000fc0
#define TOPBT4_RXAGCCALTH_GET(x)                                     (((x) & TOPBT4_RXAGCCALTH_MASK) >> TOPBT4_RXAGCCALTH_LSB)
#define TOPBT4_RXAGCCALTH_SET(x)                                     (((0 | (x)) << TOPBT4_RXAGCCALTH_LSB) & TOPBT4_RXAGCCALTH_MASK)
#define TOPBT4_RXAGCCALTH_RESET                                      32
#define TOPBT4_RXAGCFALL_MSB                                         5
#define TOPBT4_RXAGCFALL_LSB                                         4
#define TOPBT4_RXAGCFALL_MASK                                        0x00000030
#define TOPBT4_RXAGCFALL_GET(x)                                      (((x) & TOPBT4_RXAGCFALL_MASK) >> TOPBT4_RXAGCFALL_LSB)
#define TOPBT4_RXAGCFALL_SET(x)                                      (((0 | (x)) << TOPBT4_RXAGCFALL_LSB) & TOPBT4_RXAGCFALL_MASK)
#define TOPBT4_RXAGCFALL_RESET                                       0
#define TOPBT4_RXAGCTARG_MSB                                         3
#define TOPBT4_RXAGCTARG_LSB                                         0
#define TOPBT4_RXAGCTARG_MASK                                        0x0000000f
#define TOPBT4_RXAGCTARG_GET(x)                                      (((x) & TOPBT4_RXAGCTARG_MASK) >> TOPBT4_RXAGCTARG_LSB)
#define TOPBT4_RXAGCTARG_SET(x)                                      (((0 | (x)) << TOPBT4_RXAGCTARG_LSB) & TOPBT4_RXAGCTARG_MASK)
#define TOPBT4_RXAGCTARG_RESET                                       0
#define TOPBT4_ADDRESS                                               0x000c
#define TOPBT4_HW_MASK                                               0xffffffff
#define TOPBT4_SW_MASK                                               0xffffffff
#define TOPBT4_HW_WRITE_MASK                                         0x00000000
#define TOPBT4_SW_WRITE_MASK                                         0xffffffff
#define TOPBT4_RSTMASK                                               0xffffffff
#define TOPBT4_RESET                                                 0x00002800

// 0x0010 (TOPBT5)
#define TOPBT5_RXFILT_GN_MSB                                         31
#define TOPBT5_RXFILT_GN_LSB                                         28
#define TOPBT5_RXFILT_GN_MASK                                        0xf0000000
#define TOPBT5_RXFILT_GN_GET(x)                                      (((x) & TOPBT5_RXFILT_GN_MASK) >> TOPBT5_RXFILT_GN_LSB)
#define TOPBT5_RXFILT_GN_SET(x)                                      (((0 | (x)) << TOPBT5_RXFILT_GN_LSB) & TOPBT5_RXFILT_GN_MASK)
#define TOPBT5_RXFILT_GN_RESET                                       15
#define TOPBT5_RXFILT_PWDI_MSB                                       27
#define TOPBT5_RXFILT_PWDI_LSB                                       27
#define TOPBT5_RXFILT_PWDI_MASK                                      0x08000000
#define TOPBT5_RXFILT_PWDI_GET(x)                                    (((x) & TOPBT5_RXFILT_PWDI_MASK) >> TOPBT5_RXFILT_PWDI_LSB)
#define TOPBT5_RXFILT_PWDI_SET(x)                                    (((0 | (x)) << TOPBT5_RXFILT_PWDI_LSB) & TOPBT5_RXFILT_PWDI_MASK)
#define TOPBT5_RXFILT_PWDI_RESET                                     0
#define TOPBT5_RXFILT_PWDQ_MSB                                       26
#define TOPBT5_RXFILT_PWDQ_LSB                                       26
#define TOPBT5_RXFILT_PWDQ_MASK                                      0x04000000
#define TOPBT5_RXFILT_PWDQ_GET(x)                                    (((x) & TOPBT5_RXFILT_PWDQ_MASK) >> TOPBT5_RXFILT_PWDQ_LSB)
#define TOPBT5_RXFILT_PWDQ_SET(x)                                    (((0 | (x)) << TOPBT5_RXFILT_PWDQ_LSB) & TOPBT5_RXFILT_PWDQ_MASK)
#define TOPBT5_RXFILT_PWDQ_RESET                                     0
#define TOPBT5_RXFILT_BOOSTOPOUT_MSB                                 25
#define TOPBT5_RXFILT_BOOSTOPOUT_LSB                                 25
#define TOPBT5_RXFILT_BOOSTOPOUT_MASK                                0x02000000
#define TOPBT5_RXFILT_BOOSTOPOUT_GET(x)                              (((x) & TOPBT5_RXFILT_BOOSTOPOUT_MASK) >> TOPBT5_RXFILT_BOOSTOPOUT_LSB)
#define TOPBT5_RXFILT_BOOSTOPOUT_SET(x)                              (((0 | (x)) << TOPBT5_RXFILT_BOOSTOPOUT_LSB) & TOPBT5_RXFILT_BOOSTOPOUT_MASK)
#define TOPBT5_RXFILT_BOOSTOPOUT_RESET                               0
#define TOPBT5_RXON_MSB                                              24
#define TOPBT5_RXON_LSB                                              24
#define TOPBT5_RXON_MASK                                             0x01000000
#define TOPBT5_RXON_GET(x)                                           (((x) & TOPBT5_RXON_MASK) >> TOPBT5_RXON_LSB)
#define TOPBT5_RXON_SET(x)                                           (((0 | (x)) << TOPBT5_RXON_LSB) & TOPBT5_RXON_MASK)
#define TOPBT5_RXON_RESET                                            0
#define TOPBT5_RXMIX_ATB_MSB                                         23
#define TOPBT5_RXMIX_ATB_LSB                                         22
#define TOPBT5_RXMIX_ATB_MASK                                        0x00c00000
#define TOPBT5_RXMIX_ATB_GET(x)                                      (((x) & TOPBT5_RXMIX_ATB_MASK) >> TOPBT5_RXMIX_ATB_LSB)
#define TOPBT5_RXMIX_ATB_SET(x)                                      (((0 | (x)) << TOPBT5_RXMIX_ATB_LSB) & TOPBT5_RXMIX_ATB_MASK)
#define TOPBT5_RXMIX_ATB_RESET                                       0
#define TOPBT5_RXMIX_GN_MSB                                          21
#define TOPBT5_RXMIX_GN_LSB                                          20
#define TOPBT5_RXMIX_GN_MASK                                         0x00300000
#define TOPBT5_RXMIX_GN_GET(x)                                       (((x) & TOPBT5_RXMIX_GN_MASK) >> TOPBT5_RXMIX_GN_LSB)
#define TOPBT5_RXMIX_GN_SET(x)                                       (((0 | (x)) << TOPBT5_RXMIX_GN_LSB) & TOPBT5_RXMIX_GN_MASK)
#define TOPBT5_RXMIX_GN_RESET                                        3
#define TOPBT5_RXMIX_PWDI_MSB                                        19
#define TOPBT5_RXMIX_PWDI_LSB                                        19
#define TOPBT5_RXMIX_PWDI_MASK                                       0x00080000
#define TOPBT5_RXMIX_PWDI_GET(x)                                     (((x) & TOPBT5_RXMIX_PWDI_MASK) >> TOPBT5_RXMIX_PWDI_LSB)
#define TOPBT5_RXMIX_PWDI_SET(x)                                     (((0 | (x)) << TOPBT5_RXMIX_PWDI_LSB) & TOPBT5_RXMIX_PWDI_MASK)
#define TOPBT5_RXMIX_PWDI_RESET                                      0
#define TOPBT5_RXMIX_PWDQ_MSB                                        18
#define TOPBT5_RXMIX_PWDQ_LSB                                        18
#define TOPBT5_RXMIX_PWDQ_MASK                                       0x00040000
#define TOPBT5_RXMIX_PWDQ_GET(x)                                     (((x) & TOPBT5_RXMIX_PWDQ_MASK) >> TOPBT5_RXMIX_PWDQ_LSB)
#define TOPBT5_RXMIX_PWDQ_SET(x)                                     (((0 | (x)) << TOPBT5_RXMIX_PWDQ_LSB) & TOPBT5_RXMIX_PWDQ_MASK)
#define TOPBT5_RXMIX_PWDQ_RESET                                      0
#define TOPBT5_SYNTHON_MSB                                           17
#define TOPBT5_SYNTHON_LSB                                           17
#define TOPBT5_SYNTHON_MASK                                          0x00020000
#define TOPBT5_SYNTHON_GET(x)                                        (((x) & TOPBT5_SYNTHON_MASK) >> TOPBT5_SYNTHON_LSB)
#define TOPBT5_SYNTHON_SET(x)                                        (((0 | (x)) << TOPBT5_SYNTHON_LSB) & TOPBT5_SYNTHON_MASK)
#define TOPBT5_SYNTHON_RESET                                         0
#define TOPBT5_SYNTHONTXMODE_MSB                                     16
#define TOPBT5_SYNTHONTXMODE_LSB                                     16
#define TOPBT5_SYNTHONTXMODE_MASK                                    0x00010000
#define TOPBT5_SYNTHONTXMODE_GET(x)                                  (((x) & TOPBT5_SYNTHONTXMODE_MASK) >> TOPBT5_SYNTHONTXMODE_LSB)
#define TOPBT5_SYNTHONTXMODE_SET(x)                                  (((0 | (x)) << TOPBT5_SYNTHONTXMODE_LSB) & TOPBT5_SYNTHONTXMODE_MASK)
#define TOPBT5_SYNTHONTXMODE_RESET                                   0
#define TOPBT5_TESTIQ_BUFEN_MSB                                      15
#define TOPBT5_TESTIQ_BUFEN_LSB                                      15
#define TOPBT5_TESTIQ_BUFEN_MASK                                     0x00008000
#define TOPBT5_TESTIQ_BUFEN_GET(x)                                   (((x) & TOPBT5_TESTIQ_BUFEN_MASK) >> TOPBT5_TESTIQ_BUFEN_LSB)
#define TOPBT5_TESTIQ_BUFEN_SET(x)                                   (((0 | (x)) << TOPBT5_TESTIQ_BUFEN_LSB) & TOPBT5_TESTIQ_BUFEN_MASK)
#define TOPBT5_TESTIQ_BUFEN_RESET                                    0
#define TOPBT5_TESTIQ_S_MSB                                          14
#define TOPBT5_TESTIQ_S_LSB                                          12
#define TOPBT5_TESTIQ_S_MASK                                         0x00007000
#define TOPBT5_TESTIQ_S_GET(x)                                       (((x) & TOPBT5_TESTIQ_S_MASK) >> TOPBT5_TESTIQ_S_LSB)
#define TOPBT5_TESTIQ_S_SET(x)                                       (((0 | (x)) << TOPBT5_TESTIQ_S_LSB) & TOPBT5_TESTIQ_S_MASK)
#define TOPBT5_TESTIQ_S_RESET                                        0
#define TOPBT5_SEL_DIGTESTDATA_MSB                                   11
#define TOPBT5_SEL_DIGTESTDATA_LSB                                   10
#define TOPBT5_SEL_DIGTESTDATA_MASK                                  0x00000c00
#define TOPBT5_SEL_DIGTESTDATA_GET(x)                                (((x) & TOPBT5_SEL_DIGTESTDATA_MASK) >> TOPBT5_SEL_DIGTESTDATA_LSB)
#define TOPBT5_SEL_DIGTESTDATA_SET(x)                                (((0 | (x)) << TOPBT5_SEL_DIGTESTDATA_LSB) & TOPBT5_SEL_DIGTESTDATA_MASK)
#define TOPBT5_SEL_DIGTESTDATA_RESET                                 0
#define TOPBT5_FORCE_TESTIQ_DIG_OEL_MSB                              9
#define TOPBT5_FORCE_TESTIQ_DIG_OEL_LSB                              9
#define TOPBT5_FORCE_TESTIQ_DIG_OEL_MASK                             0x00000200
#define TOPBT5_FORCE_TESTIQ_DIG_OEL_GET(x)                           (((x) & TOPBT5_FORCE_TESTIQ_DIG_OEL_MASK) >> TOPBT5_FORCE_TESTIQ_DIG_OEL_LSB)
#define TOPBT5_FORCE_TESTIQ_DIG_OEL_SET(x)                           (((0 | (x)) << TOPBT5_FORCE_TESTIQ_DIG_OEL_LSB) & TOPBT5_FORCE_TESTIQ_DIG_OEL_MASK)
#define TOPBT5_FORCE_TESTIQ_DIG_OEL_RESET                            1
#define TOPBT5_FORCE_ATB_DIG_OEL_MSB                                 8
#define TOPBT5_FORCE_ATB_DIG_OEL_LSB                                 8
#define TOPBT5_FORCE_ATB_DIG_OEL_MASK                                0x00000100
#define TOPBT5_FORCE_ATB_DIG_OEL_GET(x)                              (((x) & TOPBT5_FORCE_ATB_DIG_OEL_MASK) >> TOPBT5_FORCE_ATB_DIG_OEL_LSB)
#define TOPBT5_FORCE_ATB_DIG_OEL_SET(x)                              (((0 | (x)) << TOPBT5_FORCE_ATB_DIG_OEL_LSB) & TOPBT5_FORCE_ATB_DIG_OEL_MASK)
#define TOPBT5_FORCE_ATB_DIG_OEL_RESET                               1
#define TOPBT5_LDO_LVL_MSB                                           7
#define TOPBT5_LDO_LVL_LSB                                           5
#define TOPBT5_LDO_LVL_MASK                                          0x000000e0
#define TOPBT5_LDO_LVL_GET(x)                                        (((x) & TOPBT5_LDO_LVL_MASK) >> TOPBT5_LDO_LVL_LSB)
#define TOPBT5_LDO_LVL_SET(x)                                        (((0 | (x)) << TOPBT5_LDO_LVL_LSB) & TOPBT5_LDO_LVL_MASK)
#define TOPBT5_LDO_LVL_RESET                                         4
#define TOPBT5_OTPREG_ON_MSB                                         4
#define TOPBT5_OTPREG_ON_LSB                                         4
#define TOPBT5_OTPREG_ON_MASK                                        0x00000010
#define TOPBT5_OTPREG_ON_GET(x)                                      (((x) & TOPBT5_OTPREG_ON_MASK) >> TOPBT5_OTPREG_ON_LSB)
#define TOPBT5_OTPREG_ON_SET(x)                                      (((0 | (x)) << TOPBT5_OTPREG_ON_LSB) & TOPBT5_OTPREG_ON_MASK)
#define TOPBT5_OTPREG_ON_RESET                                       0
#define TOPBT5_OTP_PS_EN_MSB                                         3
#define TOPBT5_OTP_PS_EN_LSB                                         3
#define TOPBT5_OTP_PS_EN_MASK                                        0x00000008
#define TOPBT5_OTP_PS_EN_GET(x)                                      (((x) & TOPBT5_OTP_PS_EN_MASK) >> TOPBT5_OTP_PS_EN_LSB)
#define TOPBT5_OTP_PS_EN_SET(x)                                      (((0 | (x)) << TOPBT5_OTP_PS_EN_LSB) & TOPBT5_OTP_PS_EN_MASK)
#define TOPBT5_OTP_PS_EN_RESET                                       0
#define TOPBT5_OTPREG_LVLCTR_MSB                                     2
#define TOPBT5_OTPREG_LVLCTR_LSB                                     1
#define TOPBT5_OTPREG_LVLCTR_MASK                                    0x00000006
#define TOPBT5_OTPREG_LVLCTR_GET(x)                                  (((x) & TOPBT5_OTPREG_LVLCTR_MASK) >> TOPBT5_OTPREG_LVLCTR_LSB)
#define TOPBT5_OTPREG_LVLCTR_SET(x)                                  (((0 | (x)) << TOPBT5_OTPREG_LVLCTR_LSB) & TOPBT5_OTPREG_LVLCTR_MASK)
#define TOPBT5_OTPREG_LVLCTR_RESET                                   0
#define TOPBT5_LFOSC_TEST_DISABLE_MSB                                0
#define TOPBT5_LFOSC_TEST_DISABLE_LSB                                0
#define TOPBT5_LFOSC_TEST_DISABLE_MASK                               0x00000001
#define TOPBT5_LFOSC_TEST_DISABLE_GET(x)                             (((x) & TOPBT5_LFOSC_TEST_DISABLE_MASK) >> TOPBT5_LFOSC_TEST_DISABLE_LSB)
#define TOPBT5_LFOSC_TEST_DISABLE_SET(x)                             (((0 | (x)) << TOPBT5_LFOSC_TEST_DISABLE_LSB) & TOPBT5_LFOSC_TEST_DISABLE_MASK)
#define TOPBT5_LFOSC_TEST_DISABLE_RESET                              1
#define TOPBT5_ADDRESS                                               0x0010
#define TOPBT5_HW_MASK                                               0xffffffff
#define TOPBT5_SW_MASK                                               0xffffffff
#define TOPBT5_HW_WRITE_MASK                                         0x00000000
#define TOPBT5_SW_WRITE_MASK                                         0xffffffff
#define TOPBT5_RSTMASK                                               0xffffffff
#define TOPBT5_RESET                                                 0xf0300381

// 0x0014 (TOPBT6)
#define TOPBT6_TX_ATB_MSB                                            31
#define TOPBT6_TX_ATB_LSB                                            28
#define TOPBT6_TX_ATB_MASK                                           0xf0000000
#define TOPBT6_TX_ATB_GET(x)                                         (((x) & TOPBT6_TX_ATB_MASK) >> TOPBT6_TX_ATB_LSB)
#define TOPBT6_TX_ATB_SET(x)                                         (((0 | (x)) << TOPBT6_TX_ATB_LSB) & TOPBT6_TX_ATB_MASK)
#define TOPBT6_TX_ATB_RESET                                          0
#define TOPBT6_TX_DACPWD_MSB                                         27
#define TOPBT6_TX_DACPWD_LSB                                         27
#define TOPBT6_TX_DACPWD_MASK                                        0x08000000
#define TOPBT6_TX_DACPWD_GET(x)                                      (((x) & TOPBT6_TX_DACPWD_MASK) >> TOPBT6_TX_DACPWD_LSB)
#define TOPBT6_TX_DACPWD_SET(x)                                      (((0 | (x)) << TOPBT6_TX_DACPWD_LSB) & TOPBT6_TX_DACPWD_MASK)
#define TOPBT6_TX_DACPWD_RESET                                       0
#define TOPBT6_TX_DACRESOLUTION_MSB                                  26
#define TOPBT6_TX_DACRESOLUTION_LSB                                  25
#define TOPBT6_TX_DACRESOLUTION_MASK                                 0x06000000
#define TOPBT6_TX_DACRESOLUTION_GET(x)                               (((x) & TOPBT6_TX_DACRESOLUTION_MASK) >> TOPBT6_TX_DACRESOLUTION_LSB)
#define TOPBT6_TX_DACRESOLUTION_SET(x)                               (((0 | (x)) << TOPBT6_TX_DACRESOLUTION_LSB) & TOPBT6_TX_DACRESOLUTION_MASK)
#define TOPBT6_TX_DACRESOLUTION_RESET                                0
#define TOPBT6_TX_DACRSTB_MSB                                        24
#define TOPBT6_TX_DACRSTB_LSB                                        24
#define TOPBT6_TX_DACRSTB_MASK                                       0x01000000
#define TOPBT6_TX_DACRSTB_GET(x)                                     (((x) & TOPBT6_TX_DACRSTB_MASK) >> TOPBT6_TX_DACRSTB_LSB)
#define TOPBT6_TX_DACRSTB_SET(x)                                     (((0 | (x)) << TOPBT6_TX_DACRSTB_LSB) & TOPBT6_TX_DACRSTB_MASK)
#define TOPBT6_TX_DACRSTB_RESET                                      1
#define TOPBT6_TX_FORCEDACFULLSCALE_MSB                              23
#define TOPBT6_TX_FORCEDACFULLSCALE_LSB                              23
#define TOPBT6_TX_FORCEDACFULLSCALE_MASK                             0x00800000
#define TOPBT6_TX_FORCEDACFULLSCALE_GET(x)                           (((x) & TOPBT6_TX_FORCEDACFULLSCALE_MASK) >> TOPBT6_TX_FORCEDACFULLSCALE_LSB)
#define TOPBT6_TX_FORCEDACFULLSCALE_SET(x)                           (((0 | (x)) << TOPBT6_TX_FORCEDACFULLSCALE_LSB) & TOPBT6_TX_FORCEDACFULLSCALE_MASK)
#define TOPBT6_TX_FORCEDACFULLSCALE_RESET                            0
#define TOPBT6_PAON_MSB                                              22
#define TOPBT6_PAON_LSB                                              22
#define TOPBT6_PAON_MASK                                             0x00400000
#define TOPBT6_PAON_GET(x)                                           (((x) & TOPBT6_PAON_MASK) >> TOPBT6_PAON_LSB)
#define TOPBT6_PAON_SET(x)                                           (((0 | (x)) << TOPBT6_PAON_LSB) & TOPBT6_PAON_MASK)
#define TOPBT6_PAON_RESET                                            0
#define TOPBT6_TXON_MSB                                              21
#define TOPBT6_TXON_LSB                                              21
#define TOPBT6_TXON_MASK                                             0x00200000
#define TOPBT6_TXON_GET(x)                                           (((x) & TOPBT6_TXON_MASK) >> TOPBT6_TXON_LSB)
#define TOPBT6_TXON_SET(x)                                           (((0 | (x)) << TOPBT6_TXON_LSB) & TOPBT6_TXON_MASK)
#define TOPBT6_TXON_RESET                                            0
#define TOPBT6_TX_PWDMIX_MSB                                         20
#define TOPBT6_TX_PWDMIX_LSB                                         20
#define TOPBT6_TX_PWDMIX_MASK                                        0x00100000
#define TOPBT6_TX_PWDMIX_GET(x)                                      (((x) & TOPBT6_TX_PWDMIX_MASK) >> TOPBT6_TX_PWDMIX_LSB)
#define TOPBT6_TX_PWDMIX_SET(x)                                      (((0 | (x)) << TOPBT6_TX_PWDMIX_LSB) & TOPBT6_TX_PWDMIX_MASK)
#define TOPBT6_TX_PWDMIX_RESET                                       0
#define TOPBT6_TX_V2IGN_MSB                                          19
#define TOPBT6_TX_V2IGN_LSB                                          18
#define TOPBT6_TX_V2IGN_MASK                                         0x000c0000
#define TOPBT6_TX_V2IGN_GET(x)                                       (((x) & TOPBT6_TX_V2IGN_MASK) >> TOPBT6_TX_V2IGN_LSB)
#define TOPBT6_TX_V2IGN_SET(x)                                       (((0 | (x)) << TOPBT6_TX_V2IGN_LSB) & TOPBT6_TX_V2IGN_MASK)
#define TOPBT6_TX_V2IGN_RESET                                        3
#define TOPBT6_XTAL_OSCON_MSB                                        17
#define TOPBT6_XTAL_OSCON_LSB                                        17
#define TOPBT6_XTAL_OSCON_MASK                                       0x00020000
#define TOPBT6_XTAL_OSCON_GET(x)                                     (((x) & TOPBT6_XTAL_OSCON_MASK) >> TOPBT6_XTAL_OSCON_LSB)
#define TOPBT6_XTAL_OSCON_SET(x)                                     (((0 | (x)) << TOPBT6_XTAL_OSCON_LSB) & TOPBT6_XTAL_OSCON_MASK)
#define TOPBT6_XTAL_OSCON_RESET                                      1
#define TOPBT6_VDDHSENSE_ON_MSB                                      16
#define TOPBT6_VDDHSENSE_ON_LSB                                      16
#define TOPBT6_VDDHSENSE_ON_MASK                                     0x00010000
#define TOPBT6_VDDHSENSE_ON_GET(x)                                   (((x) & TOPBT6_VDDHSENSE_ON_MASK) >> TOPBT6_VDDHSENSE_ON_LSB)
#define TOPBT6_VDDHSENSE_ON_SET(x)                                   (((0 | (x)) << TOPBT6_VDDHSENSE_ON_LSB) & TOPBT6_VDDHSENSE_ON_MASK)
#define TOPBT6_VDDHSENSE_ON_RESET                                    0
#define TOPBT6_LOCALTHERM_MSB                                        15
#define TOPBT6_LOCALTHERM_LSB                                        15
#define TOPBT6_LOCALTHERM_MASK                                       0x00008000
#define TOPBT6_LOCALTHERM_GET(x)                                     (((x) & TOPBT6_LOCALTHERM_MASK) >> TOPBT6_LOCALTHERM_LSB)
#define TOPBT6_LOCALTHERM_SET(x)                                     (((0 | (x)) << TOPBT6_LOCALTHERM_LSB) & TOPBT6_LOCALTHERM_MASK)
#define TOPBT6_LOCALTHERM_RESET                                      0
#define TOPBT6_THERM_ON_MSB                                          14
#define TOPBT6_THERM_ON_LSB                                          14
#define TOPBT6_THERM_ON_MASK                                         0x00004000
#define TOPBT6_THERM_ON_GET(x)                                       (((x) & TOPBT6_THERM_ON_MASK) >> TOPBT6_THERM_ON_LSB)
#define TOPBT6_THERM_ON_SET(x)                                       (((0 | (x)) << TOPBT6_THERM_ON_LSB) & TOPBT6_THERM_ON_MASK)
#define TOPBT6_THERM_ON_RESET                                        0
#define TOPBT6_THERM_START_MSB                                       13
#define TOPBT6_THERM_START_LSB                                       13
#define TOPBT6_THERM_START_MASK                                      0x00002000
#define TOPBT6_THERM_START_GET(x)                                    (((x) & TOPBT6_THERM_START_MASK) >> TOPBT6_THERM_START_LSB)
#define TOPBT6_THERM_START_SET(x)                                    (((0 | (x)) << TOPBT6_THERM_START_LSB) & TOPBT6_THERM_START_MASK)
#define TOPBT6_THERM_START_RESET                                     0
#define TOPBT6_THERM_SEL_MSB                                         12
#define TOPBT6_THERM_SEL_LSB                                         11
#define TOPBT6_THERM_SEL_MASK                                        0x00001800
#define TOPBT6_THERM_SEL_GET(x)                                      (((x) & TOPBT6_THERM_SEL_MASK) >> TOPBT6_THERM_SEL_LSB)
#define TOPBT6_THERM_SEL_SET(x)                                      (((0 | (x)) << TOPBT6_THERM_SEL_LSB) & TOPBT6_THERM_SEL_MASK)
#define TOPBT6_THERM_SEL_RESET                                       0
#define TOPBT6_THERM_SLOW_MSB                                        10
#define TOPBT6_THERM_SLOW_LSB                                        10
#define TOPBT6_THERM_SLOW_MASK                                       0x00000400
#define TOPBT6_THERM_SLOW_GET(x)                                     (((x) & TOPBT6_THERM_SLOW_MASK) >> TOPBT6_THERM_SLOW_LSB)
#define TOPBT6_THERM_SLOW_SET(x)                                     (((0 | (x)) << TOPBT6_THERM_SLOW_LSB) & TOPBT6_THERM_SLOW_MASK)
#define TOPBT6_THERM_SLOW_RESET                                      0
#define TOPBT6_THERM_AUTOPWD_EN_MSB                                  9
#define TOPBT6_THERM_AUTOPWD_EN_LSB                                  9
#define TOPBT6_THERM_AUTOPWD_EN_MASK                                 0x00000200
#define TOPBT6_THERM_AUTOPWD_EN_GET(x)                               (((x) & TOPBT6_THERM_AUTOPWD_EN_MASK) >> TOPBT6_THERM_AUTOPWD_EN_LSB)
#define TOPBT6_THERM_AUTOPWD_EN_SET(x)                               (((0 | (x)) << TOPBT6_THERM_AUTOPWD_EN_LSB) & TOPBT6_THERM_AUTOPWD_EN_MASK)
#define TOPBT6_THERM_AUTOPWD_EN_RESET                                1
#define TOPBT6_THERM_ADCCAL_EN_MSB                                   8
#define TOPBT6_THERM_ADCCAL_EN_LSB                                   8
#define TOPBT6_THERM_ADCCAL_EN_MASK                                  0x00000100
#define TOPBT6_THERM_ADCCAL_EN_GET(x)                                (((x) & TOPBT6_THERM_ADCCAL_EN_MASK) >> TOPBT6_THERM_ADCCAL_EN_LSB)
#define TOPBT6_THERM_ADCCAL_EN_SET(x)                                (((0 | (x)) << TOPBT6_THERM_ADCCAL_EN_LSB) & TOPBT6_THERM_ADCCAL_EN_MASK)
#define TOPBT6_THERM_ADCCAL_EN_RESET                                 0
#define TOPBT6_THERM_DACTEST_EN_MSB                                  7
#define TOPBT6_THERM_DACTEST_EN_LSB                                  7
#define TOPBT6_THERM_DACTEST_EN_MASK                                 0x00000080
#define TOPBT6_THERM_DACTEST_EN_GET(x)                               (((x) & TOPBT6_THERM_DACTEST_EN_MASK) >> TOPBT6_THERM_DACTEST_EN_LSB)
#define TOPBT6_THERM_DACTEST_EN_SET(x)                               (((0 | (x)) << TOPBT6_THERM_DACTEST_EN_LSB) & TOPBT6_THERM_DACTEST_EN_MASK)
#define TOPBT6_THERM_DACTEST_EN_RESET                                0
#define TOPBT6_SEL_MULABUS_MSB                                       6
#define TOPBT6_SEL_MULABUS_LSB                                       4
#define TOPBT6_SEL_MULABUS_MASK                                      0x00000070
#define TOPBT6_SEL_MULABUS_GET(x)                                    (((x) & TOPBT6_SEL_MULABUS_MASK) >> TOPBT6_SEL_MULABUS_LSB)
#define TOPBT6_SEL_MULABUS_SET(x)                                    (((0 | (x)) << TOPBT6_SEL_MULABUS_LSB) & TOPBT6_SEL_MULABUS_MASK)
#define TOPBT6_SEL_MULABUS_RESET                                     0
#define TOPBT6_RESERVED_MSB                                          3
#define TOPBT6_RESERVED_LSB                                          0
#define TOPBT6_RESERVED_MASK                                         0x0000000f
#define TOPBT6_RESERVED_GET(x)                                       (((x) & TOPBT6_RESERVED_MASK) >> TOPBT6_RESERVED_LSB)
#define TOPBT6_RESERVED_SET(x)                                       (((0 | (x)) << TOPBT6_RESERVED_LSB) & TOPBT6_RESERVED_MASK)
#define TOPBT6_RESERVED_RESET                                        0
#define TOPBT6_ADDRESS                                               0x0014
#define TOPBT6_HW_MASK                                               0xffffffff
#define TOPBT6_SW_MASK                                               0xffffffff
#define TOPBT6_HW_WRITE_MASK                                         0x00000000
#define TOPBT6_SW_WRITE_MASK                                         0xffffffff
#define TOPBT6_RSTMASK                                               0xffffffff
#define TOPBT6_RESET                                                 0x010e0200

// 0x0018 (TOPBT7)
#define TOPBT7_THERM_DACTEST_CODE_MSB                                31
#define TOPBT7_THERM_DACTEST_CODE_LSB                                24
#define TOPBT7_THERM_DACTEST_CODE_MASK                               0xff000000
#define TOPBT7_THERM_DACTEST_CODE_GET(x)                             (((x) & TOPBT7_THERM_DACTEST_CODE_MASK) >> TOPBT7_THERM_DACTEST_CODE_LSB)
#define TOPBT7_THERM_DACTEST_CODE_SET(x)                             (((0 | (x)) << TOPBT7_THERM_DACTEST_CODE_LSB) & TOPBT7_THERM_DACTEST_CODE_MASK)
#define TOPBT7_THERM_DACTEST_CODE_RESET                              128
#define TOPBT7_XTAL_OSCON_MSB                                        23
#define TOPBT7_XTAL_OSCON_LSB                                        23
#define TOPBT7_XTAL_OSCON_MASK                                       0x00800000
#define TOPBT7_XTAL_OSCON_GET(x)                                     (((x) & TOPBT7_XTAL_OSCON_MASK) >> TOPBT7_XTAL_OSCON_LSB)
#define TOPBT7_XTAL_OSCON_SET(x)                                     (((0 | (x)) << TOPBT7_XTAL_OSCON_LSB) & TOPBT7_XTAL_OSCON_MASK)
#define TOPBT7_XTAL_OSCON_RESET                                      0
#define TOPBT7_SYNTHON_MSB                                           22
#define TOPBT7_SYNTHON_LSB                                           22
#define TOPBT7_SYNTHON_MASK                                          0x00400000
#define TOPBT7_SYNTHON_GET(x)                                        (((x) & TOPBT7_SYNTHON_MASK) >> TOPBT7_SYNTHON_LSB)
#define TOPBT7_SYNTHON_SET(x)                                        (((0 | (x)) << TOPBT7_SYNTHON_LSB) & TOPBT7_SYNTHON_MASK)
#define TOPBT7_SYNTHON_RESET                                         0
#define TOPBT7_SYNTHONTXMODE_MSB                                     21
#define TOPBT7_SYNTHONTXMODE_LSB                                     21
#define TOPBT7_SYNTHONTXMODE_MASK                                    0x00200000
#define TOPBT7_SYNTHONTXMODE_GET(x)                                  (((x) & TOPBT7_SYNTHONTXMODE_MASK) >> TOPBT7_SYNTHONTXMODE_LSB)
#define TOPBT7_SYNTHONTXMODE_SET(x)                                  (((0 | (x)) << TOPBT7_SYNTHONTXMODE_LSB) & TOPBT7_SYNTHONTXMODE_MASK)
#define TOPBT7_SYNTHONTXMODE_RESET                                   0
#define TOPBT7_RXON_MSB                                              20
#define TOPBT7_RXON_LSB                                              20
#define TOPBT7_RXON_MASK                                             0x00100000
#define TOPBT7_RXON_GET(x)                                           (((x) & TOPBT7_RXON_MASK) >> TOPBT7_RXON_LSB)
#define TOPBT7_RXON_SET(x)                                           (((0 | (x)) << TOPBT7_RXON_LSB) & TOPBT7_RXON_MASK)
#define TOPBT7_RXON_RESET                                            0
#define TOPBT7_TXON_MSB                                              19
#define TOPBT7_TXON_LSB                                              19
#define TOPBT7_TXON_MASK                                             0x00080000
#define TOPBT7_TXON_GET(x)                                           (((x) & TOPBT7_TXON_MASK) >> TOPBT7_TXON_LSB)
#define TOPBT7_TXON_SET(x)                                           (((0 | (x)) << TOPBT7_TXON_LSB) & TOPBT7_TXON_MASK)
#define TOPBT7_TXON_RESET                                            0
#define TOPBT7_PAON_MSB                                              18
#define TOPBT7_PAON_LSB                                              18
#define TOPBT7_PAON_MASK                                             0x00040000
#define TOPBT7_PAON_GET(x)                                           (((x) & TOPBT7_PAON_MASK) >> TOPBT7_PAON_LSB)
#define TOPBT7_PAON_SET(x)                                           (((0 | (x)) << TOPBT7_PAON_LSB) & TOPBT7_PAON_MASK)
#define TOPBT7_PAON_RESET                                            0
#define TOPBT7_CALTX_MSB                                             17
#define TOPBT7_CALTX_LSB                                             17
#define TOPBT7_CALTX_MASK                                            0x00020000
#define TOPBT7_CALTX_GET(x)                                          (((x) & TOPBT7_CALTX_MASK) >> TOPBT7_CALTX_LSB)
#define TOPBT7_CALTX_SET(x)                                          (((0 | (x)) << TOPBT7_CALTX_LSB) & TOPBT7_CALTX_MASK)
#define TOPBT7_CALTX_RESET                                           0
#define TOPBT7_CALPA_MSB                                             16
#define TOPBT7_CALPA_LSB                                             16
#define TOPBT7_CALPA_MASK                                            0x00010000
#define TOPBT7_CALPA_GET(x)                                          (((x) & TOPBT7_CALPA_MASK) >> TOPBT7_CALPA_LSB)
#define TOPBT7_CALPA_SET(x)                                          (((0 | (x)) << TOPBT7_CALPA_LSB) & TOPBT7_CALPA_MASK)
#define TOPBT7_CALPA_RESET                                           0
#define TOPBT7_FE_PHASE_MSB                                          15
#define TOPBT7_FE_PHASE_LSB                                          15
#define TOPBT7_FE_PHASE_MASK                                         0x00008000
#define TOPBT7_FE_PHASE_GET(x)                                       (((x) & TOPBT7_FE_PHASE_MASK) >> TOPBT7_FE_PHASE_LSB)
#define TOPBT7_FE_PHASE_SET(x)                                       (((0 | (x)) << TOPBT7_FE_PHASE_LSB) & TOPBT7_FE_PHASE_MASK)
#define TOPBT7_FE_PHASE_RESET                                        0
#define TOPBT7_FE_LNAGN_MSB                                          14
#define TOPBT7_FE_LNAGN_LSB                                          12
#define TOPBT7_FE_LNAGN_MASK                                         0x00007000
#define TOPBT7_FE_LNAGN_GET(x)                                       (((x) & TOPBT7_FE_LNAGN_MASK) >> TOPBT7_FE_LNAGN_LSB)
#define TOPBT7_FE_LNAGN_SET(x)                                       (((0 | (x)) << TOPBT7_FE_LNAGN_LSB) & TOPBT7_FE_LNAGN_MASK)
#define TOPBT7_FE_LNAGN_RESET                                        0
#define TOPBT7_FE_LNAON_MSB                                          11
#define TOPBT7_FE_LNAON_LSB                                          11
#define TOPBT7_FE_LNAON_MASK                                         0x00000800
#define TOPBT7_FE_LNAON_GET(x)                                       (((x) & TOPBT7_FE_LNAON_MASK) >> TOPBT7_FE_LNAON_LSB)
#define TOPBT7_FE_LNAON_SET(x)                                       (((0 | (x)) << TOPBT7_FE_LNAON_LSB) & TOPBT7_FE_LNAON_MASK)
#define TOPBT7_FE_LNAON_RESET                                        0
#define TOPBT7_FE_SELLNA_MSB                                         10
#define TOPBT7_FE_SELLNA_LSB                                         10
#define TOPBT7_FE_SELLNA_MASK                                        0x00000400
#define TOPBT7_FE_SELLNA_GET(x)                                      (((x) & TOPBT7_FE_SELLNA_MASK) >> TOPBT7_FE_SELLNA_LSB)
#define TOPBT7_FE_SELLNA_SET(x)                                      (((0 | (x)) << TOPBT7_FE_SELLNA_LSB) & TOPBT7_FE_SELLNA_MASK)
#define TOPBT7_FE_SELLNA_RESET                                       0
#define TOPBT7_FE_TXMOD_MSB                                          9
#define TOPBT7_FE_TXMOD_LSB                                          8
#define TOPBT7_FE_TXMOD_MASK                                         0x00000300
#define TOPBT7_FE_TXMOD_GET(x)                                       (((x) & TOPBT7_FE_TXMOD_MASK) >> TOPBT7_FE_TXMOD_LSB)
#define TOPBT7_FE_TXMOD_SET(x)                                       (((0 | (x)) << TOPBT7_FE_TXMOD_LSB) & TOPBT7_FE_TXMOD_MASK)
#define TOPBT7_FE_TXMOD_RESET                                        0
#define TOPBT7_FE_PADRVGN_MSB                                        7
#define TOPBT7_FE_PADRVGN_LSB                                        5
#define TOPBT7_FE_PADRVGN_MASK                                       0x000000e0
#define TOPBT7_FE_PADRVGN_GET(x)                                     (((x) & TOPBT7_FE_PADRVGN_MASK) >> TOPBT7_FE_PADRVGN_LSB)
#define TOPBT7_FE_PADRVGN_SET(x)                                     (((0 | (x)) << TOPBT7_FE_PADRVGN_LSB) & TOPBT7_FE_PADRVGN_MASK)
#define TOPBT7_FE_PADRVGN_RESET                                      0
#define TOPBT7_FE_PAOUTGN_MSB                                        4
#define TOPBT7_FE_PAOUTGN_LSB                                        2
#define TOPBT7_FE_PAOUTGN_MASK                                       0x0000001c
#define TOPBT7_FE_PAOUTGN_GET(x)                                     (((x) & TOPBT7_FE_PAOUTGN_MASK) >> TOPBT7_FE_PAOUTGN_LSB)
#define TOPBT7_FE_PAOUTGN_SET(x)                                     (((0 | (x)) << TOPBT7_FE_PAOUTGN_LSB) & TOPBT7_FE_PAOUTGN_MASK)
#define TOPBT7_FE_PAOUTGN_RESET                                      0
#define TOPBT7_PWDPLL_MSB                                            1
#define TOPBT7_PWDPLL_LSB                                            1
#define TOPBT7_PWDPLL_MASK                                           0x00000002
#define TOPBT7_PWDPLL_GET(x)                                         (((x) & TOPBT7_PWDPLL_MASK) >> TOPBT7_PWDPLL_LSB)
#define TOPBT7_PWDPLL_SET(x)                                         (((0 | (x)) << TOPBT7_PWDPLL_LSB) & TOPBT7_PWDPLL_MASK)
#define TOPBT7_PWDPLL_RESET                                          0
#define TOPBT7_RXAGCPWD_MSB                                          0
#define TOPBT7_RXAGCPWD_LSB                                          0
#define TOPBT7_RXAGCPWD_MASK                                         0x00000001
#define TOPBT7_RXAGCPWD_GET(x)                                       (((x) & TOPBT7_RXAGCPWD_MASK) >> TOPBT7_RXAGCPWD_LSB)
#define TOPBT7_RXAGCPWD_SET(x)                                       (((0 | (x)) << TOPBT7_RXAGCPWD_LSB) & TOPBT7_RXAGCPWD_MASK)
#define TOPBT7_RXAGCPWD_RESET                                        0
#define TOPBT7_ADDRESS                                               0x0018
#define TOPBT7_HW_MASK                                               0xffffffff
#define TOPBT7_SW_MASK                                               0xffffffff
#define TOPBT7_HW_WRITE_MASK                                         0x00ffffff
#define TOPBT7_SW_WRITE_MASK                                         0xff000000
#define TOPBT7_RSTMASK                                               0xffffffff
#define TOPBT7_RESET                                                 0x80000000

// 0x001c (TOPBT8)
#define TOPBT8_RXAGCCAL_MSB                                          31
#define TOPBT8_RXAGCCAL_LSB                                          31
#define TOPBT8_RXAGCCAL_MASK                                         0x80000000
#define TOPBT8_RXAGCCAL_GET(x)                                       (((x) & TOPBT8_RXAGCCAL_MASK) >> TOPBT8_RXAGCCAL_LSB)
#define TOPBT8_RXAGCCAL_SET(x)                                       (((0 | (x)) << TOPBT8_RXAGCCAL_LSB) & TOPBT8_RXAGCCAL_MASK)
#define TOPBT8_RXAGCCAL_RESET                                        0
#define TOPBT8_RXAGCCALTH_MSB                                        30
#define TOPBT8_RXAGCCALTH_LSB                                        25
#define TOPBT8_RXAGCCALTH_MASK                                       0x7e000000
#define TOPBT8_RXAGCCALTH_GET(x)                                     (((x) & TOPBT8_RXAGCCALTH_MASK) >> TOPBT8_RXAGCCALTH_LSB)
#define TOPBT8_RXAGCCALTH_SET(x)                                     (((0 | (x)) << TOPBT8_RXAGCCALTH_LSB) & TOPBT8_RXAGCCALTH_MASK)
#define TOPBT8_RXAGCCALTH_RESET                                      0
#define TOPBT8_RXAGCFALL_MSB                                         24
#define TOPBT8_RXAGCFALL_LSB                                         23
#define TOPBT8_RXAGCFALL_MASK                                        0x01800000
#define TOPBT8_RXAGCFALL_GET(x)                                      (((x) & TOPBT8_RXAGCFALL_MASK) >> TOPBT8_RXAGCFALL_LSB)
#define TOPBT8_RXAGCFALL_SET(x)                                      (((0 | (x)) << TOPBT8_RXAGCFALL_LSB) & TOPBT8_RXAGCFALL_MASK)
#define TOPBT8_RXAGCFALL_RESET                                       0
#define TOPBT8_RXAGCTARG_MSB                                         22
#define TOPBT8_RXAGCTARG_LSB                                         19
#define TOPBT8_RXAGCTARG_MASK                                        0x00780000
#define TOPBT8_RXAGCTARG_GET(x)                                      (((x) & TOPBT8_RXAGCTARG_MASK) >> TOPBT8_RXAGCTARG_LSB)
#define TOPBT8_RXAGCTARG_SET(x)                                      (((0 | (x)) << TOPBT8_RXAGCTARG_LSB) & TOPBT8_RXAGCTARG_MASK)
#define TOPBT8_RXAGCTARG_RESET                                       0
#define TOPBT8_RXFILT_GN_MSB                                         18
#define TOPBT8_RXFILT_GN_LSB                                         15
#define TOPBT8_RXFILT_GN_MASK                                        0x00078000
#define TOPBT8_RXFILT_GN_GET(x)                                      (((x) & TOPBT8_RXFILT_GN_MASK) >> TOPBT8_RXFILT_GN_LSB)
#define TOPBT8_RXFILT_GN_SET(x)                                      (((0 | (x)) << TOPBT8_RXFILT_GN_LSB) & TOPBT8_RXFILT_GN_MASK)
#define TOPBT8_RXFILT_GN_RESET                                       0
#define TOPBT8_RXMIX_GN_MSB                                          14
#define TOPBT8_RXMIX_GN_LSB                                          13
#define TOPBT8_RXMIX_GN_MASK                                         0x00006000
#define TOPBT8_RXMIX_GN_GET(x)                                       (((x) & TOPBT8_RXMIX_GN_MASK) >> TOPBT8_RXMIX_GN_LSB)
#define TOPBT8_RXMIX_GN_SET(x)                                       (((0 | (x)) << TOPBT8_RXMIX_GN_LSB) & TOPBT8_RXMIX_GN_MASK)
#define TOPBT8_RXMIX_GN_RESET                                        0
#define TOPBT8_TX_DACRESOLUTION_MSB                                  12
#define TOPBT8_TX_DACRESOLUTION_LSB                                  11
#define TOPBT8_TX_DACRESOLUTION_MASK                                 0x00001800
#define TOPBT8_TX_DACRESOLUTION_GET(x)                               (((x) & TOPBT8_TX_DACRESOLUTION_MASK) >> TOPBT8_TX_DACRESOLUTION_LSB)
#define TOPBT8_TX_DACRESOLUTION_SET(x)                               (((0 | (x)) << TOPBT8_TX_DACRESOLUTION_LSB) & TOPBT8_TX_DACRESOLUTION_MASK)
#define TOPBT8_TX_DACRESOLUTION_RESET                                0
#define TOPBT8_TX_V2IGN_MSB                                          10
#define TOPBT8_TX_V2IGN_LSB                                          9
#define TOPBT8_TX_V2IGN_MASK                                         0x00000600
#define TOPBT8_TX_V2IGN_GET(x)                                       (((x) & TOPBT8_TX_V2IGN_MASK) >> TOPBT8_TX_V2IGN_LSB)
#define TOPBT8_TX_V2IGN_SET(x)                                       (((0 | (x)) << TOPBT8_TX_V2IGN_LSB) & TOPBT8_TX_V2IGN_MASK)
#define TOPBT8_TX_V2IGN_RESET                                        0
#define TOPBT8_VDDHSENSE_ON_MSB                                      8
#define TOPBT8_VDDHSENSE_ON_LSB                                      8
#define TOPBT8_VDDHSENSE_ON_MASK                                     0x00000100
#define TOPBT8_VDDHSENSE_ON_GET(x)                                   (((x) & TOPBT8_VDDHSENSE_ON_MASK) >> TOPBT8_VDDHSENSE_ON_LSB)
#define TOPBT8_VDDHSENSE_ON_SET(x)                                   (((0 | (x)) << TOPBT8_VDDHSENSE_ON_LSB) & TOPBT8_VDDHSENSE_ON_MASK)
#define TOPBT8_VDDHSENSE_ON_RESET                                    0
#define TOPBT8_THERM_ON_MSB                                          7
#define TOPBT8_THERM_ON_LSB                                          7
#define TOPBT8_THERM_ON_MASK                                         0x00000080
#define TOPBT8_THERM_ON_GET(x)                                       (((x) & TOPBT8_THERM_ON_MASK) >> TOPBT8_THERM_ON_LSB)
#define TOPBT8_THERM_ON_SET(x)                                       (((0 | (x)) << TOPBT8_THERM_ON_LSB) & TOPBT8_THERM_ON_MASK)
#define TOPBT8_THERM_ON_RESET                                        0
#define TOPBT8_THERM_START_MSB                                       6
#define TOPBT8_THERM_START_LSB                                       6
#define TOPBT8_THERM_START_MASK                                      0x00000040
#define TOPBT8_THERM_START_GET(x)                                    (((x) & TOPBT8_THERM_START_MASK) >> TOPBT8_THERM_START_LSB)
#define TOPBT8_THERM_START_SET(x)                                    (((0 | (x)) << TOPBT8_THERM_START_LSB) & TOPBT8_THERM_START_MASK)
#define TOPBT8_THERM_START_RESET                                     0
#define TOPBT8_THERM_SEL_MSB                                         5
#define TOPBT8_THERM_SEL_LSB                                         4
#define TOPBT8_THERM_SEL_MASK                                        0x00000030
#define TOPBT8_THERM_SEL_GET(x)                                      (((x) & TOPBT8_THERM_SEL_MASK) >> TOPBT8_THERM_SEL_LSB)
#define TOPBT8_THERM_SEL_SET(x)                                      (((0 | (x)) << TOPBT8_THERM_SEL_LSB) & TOPBT8_THERM_SEL_MASK)
#define TOPBT8_THERM_SEL_RESET                                       0
#define TOPBT8_THERM_DONE_MSB                                        3
#define TOPBT8_THERM_DONE_LSB                                        3
#define TOPBT8_THERM_DONE_MASK                                       0x00000008
#define TOPBT8_THERM_DONE_GET(x)                                     (((x) & TOPBT8_THERM_DONE_MASK) >> TOPBT8_THERM_DONE_LSB)
#define TOPBT8_THERM_DONE_SET(x)                                     (((0 | (x)) << TOPBT8_THERM_DONE_LSB) & TOPBT8_THERM_DONE_MASK)
#define TOPBT8_THERM_DONE_RESET                                      0
#define TOPBT8_LNAAGCOUT_MSB                                         2
#define TOPBT8_LNAAGCOUT_LSB                                         2
#define TOPBT8_LNAAGCOUT_MASK                                        0x00000004
#define TOPBT8_LNAAGCOUT_GET(x)                                      (((x) & TOPBT8_LNAAGCOUT_MASK) >> TOPBT8_LNAAGCOUT_LSB)
#define TOPBT8_LNAAGCOUT_SET(x)                                      (((0 | (x)) << TOPBT8_LNAAGCOUT_LSB) & TOPBT8_LNAAGCOUT_MASK)
#define TOPBT8_LNAAGCOUT_RESET                                       0
#define TOPBT8_RESERVED_MSB                                          1
#define TOPBT8_RESERVED_LSB                                          0
#define TOPBT8_RESERVED_MASK                                         0x00000003
#define TOPBT8_RESERVED_GET(x)                                       (((x) & TOPBT8_RESERVED_MASK) >> TOPBT8_RESERVED_LSB)
#define TOPBT8_RESERVED_SET(x)                                       (((0 | (x)) << TOPBT8_RESERVED_LSB) & TOPBT8_RESERVED_MASK)
#define TOPBT8_RESERVED_RESET                                        0
#define TOPBT8_ADDRESS                                               0x001c
#define TOPBT8_HW_MASK                                               0xffffffff
#define TOPBT8_SW_MASK                                               0xffffffff
#define TOPBT8_HW_WRITE_MASK                                         0xfffffffc
#define TOPBT8_SW_WRITE_MASK                                         0x00000003
#define TOPBT8_RSTMASK                                               0xffffffff
#define TOPBT8_RESET                                                 0x00000000

// 0x0020 (TOPBT9)
#define TOPBT9_THERM_VAL_MSB                                         31
#define TOPBT9_THERM_VAL_LSB                                         24
#define TOPBT9_THERM_VAL_MASK                                        0xff000000
#define TOPBT9_THERM_VAL_GET(x)                                      (((x) & TOPBT9_THERM_VAL_MASK) >> TOPBT9_THERM_VAL_LSB)
#define TOPBT9_THERM_VAL_SET(x)                                      (((0 | (x)) << TOPBT9_THERM_VAL_LSB) & TOPBT9_THERM_VAL_MASK)
#define TOPBT9_THERM_VAL_RESET                                       0
#define TOPBT9_BIAS_RBIAS_MSB                                        23
#define TOPBT9_BIAS_RBIAS_LSB                                        18
#define TOPBT9_BIAS_RBIAS_MASK                                       0x00fc0000
#define TOPBT9_BIAS_RBIAS_GET(x)                                     (((x) & TOPBT9_BIAS_RBIAS_MASK) >> TOPBT9_BIAS_RBIAS_LSB)
#define TOPBT9_BIAS_RBIAS_SET(x)                                     (((0 | (x)) << TOPBT9_BIAS_RBIAS_LSB) & TOPBT9_BIAS_RBIAS_MASK)
#define TOPBT9_BIAS_RBIAS_RESET                                      0
#define TOPBT9_REVID_MSB                                             17
#define TOPBT9_REVID_LSB                                             15
#define TOPBT9_REVID_MASK                                            0x00038000
#define TOPBT9_REVID_GET(x)                                          (((x) & TOPBT9_REVID_MASK) >> TOPBT9_REVID_LSB)
#define TOPBT9_REVID_SET(x)                                          (((0 | (x)) << TOPBT9_REVID_LSB) & TOPBT9_REVID_MASK)
#define TOPBT9_REVID_RESET                                           0
#define TOPBT9_PAFORCEDONBT_MSB                                      14
#define TOPBT9_PAFORCEDONBT_LSB                                      14
#define TOPBT9_PAFORCEDONBT_MASK                                     0x00004000
#define TOPBT9_PAFORCEDONBT_GET(x)                                   (((x) & TOPBT9_PAFORCEDONBT_MASK) >> TOPBT9_PAFORCEDONBT_LSB)
#define TOPBT9_PAFORCEDONBT_SET(x)                                   (((0 | (x)) << TOPBT9_PAFORCEDONBT_LSB) & TOPBT9_PAFORCEDONBT_MASK)
#define TOPBT9_PAFORCEDONBT_RESET                                    0
#define TOPBT9_OCASBT_MSB                                            13
#define TOPBT9_OCASBT_LSB                                            11
#define TOPBT9_OCASBT_MASK                                           0x00003800
#define TOPBT9_OCASBT_GET(x)                                         (((x) & TOPBT9_OCASBT_MASK) >> TOPBT9_OCASBT_LSB)
#define TOPBT9_OCASBT_SET(x)                                         (((0 | (x)) << TOPBT9_OCASBT_LSB) & TOPBT9_OCASBT_MASK)
#define TOPBT9_OCASBT_RESET                                          3
#define TOPBT9_LNA_LP_BT_MSB                                         10
#define TOPBT9_LNA_LP_BT_LSB                                         10
#define TOPBT9_LNA_LP_BT_MASK                                        0x00000400
#define TOPBT9_LNA_LP_BT_GET(x)                                      (((x) & TOPBT9_LNA_LP_BT_MASK) >> TOPBT9_LNA_LP_BT_LSB)
#define TOPBT9_LNA_LP_BT_SET(x)                                      (((0 | (x)) << TOPBT9_LNA_LP_BT_LSB) & TOPBT9_LNA_LP_BT_MASK)
#define TOPBT9_LNA_LP_BT_RESET                                       0
#define TOPBT9_MXRFORCEDONBT_MSB                                     9
#define TOPBT9_MXRFORCEDONBT_LSB                                     9
#define TOPBT9_MXRFORCEDONBT_MASK                                    0x00000200
#define TOPBT9_MXRFORCEDONBT_GET(x)                                  (((x) & TOPBT9_MXRFORCEDONBT_MASK) >> TOPBT9_MXRFORCEDONBT_LSB)
#define TOPBT9_MXRFORCEDONBT_SET(x)                                  (((0 | (x)) << TOPBT9_MXRFORCEDONBT_LSB) & TOPBT9_MXRFORCEDONBT_MASK)
#define TOPBT9_MXRFORCEDONBT_RESET                                   0
#define TOPBT9_USE_SHARED_PA_MSB                                     8
#define TOPBT9_USE_SHARED_PA_LSB                                     8
#define TOPBT9_USE_SHARED_PA_MASK                                    0x00000100
#define TOPBT9_USE_SHARED_PA_GET(x)                                  (((x) & TOPBT9_USE_SHARED_PA_MASK) >> TOPBT9_USE_SHARED_PA_LSB)
#define TOPBT9_USE_SHARED_PA_SET(x)                                  (((0 | (x)) << TOPBT9_USE_SHARED_PA_LSB) & TOPBT9_USE_SHARED_PA_MASK)
#define TOPBT9_USE_SHARED_PA_RESET                                   0
#define TOPBT9_USE_SHARED_LNA_MSB                                    7
#define TOPBT9_USE_SHARED_LNA_LSB                                    7
#define TOPBT9_USE_SHARED_LNA_MASK                                   0x00000080
#define TOPBT9_USE_SHARED_LNA_GET(x)                                 (((x) & TOPBT9_USE_SHARED_LNA_MASK) >> TOPBT9_USE_SHARED_LNA_LSB)
#define TOPBT9_USE_SHARED_LNA_SET(x)                                 (((0 | (x)) << TOPBT9_USE_SHARED_LNA_LSB) & TOPBT9_USE_SHARED_LNA_MASK)
#define TOPBT9_USE_SHARED_LNA_RESET                                  0
#define TOPBT9_OBPWDBT_MSB                                           6
#define TOPBT9_OBPWDBT_LSB                                           4
#define TOPBT9_OBPWDBT_MASK                                          0x00000070
#define TOPBT9_OBPWDBT_GET(x)                                        (((x) & TOPBT9_OBPWDBT_MASK) >> TOPBT9_OBPWDBT_LSB)
#define TOPBT9_OBPWDBT_SET(x)                                        (((0 | (x)) << TOPBT9_OBPWDBT_LSB) & TOPBT9_OBPWDBT_MASK)
#define TOPBT9_OBPWDBT_RESET                                         0
#define TOPBT9_TESTIQ_RSEL_MSB                                       3
#define TOPBT9_TESTIQ_RSEL_LSB                                       3
#define TOPBT9_TESTIQ_RSEL_MASK                                      0x00000008
#define TOPBT9_TESTIQ_RSEL_GET(x)                                    (((x) & TOPBT9_TESTIQ_RSEL_MASK) >> TOPBT9_TESTIQ_RSEL_LSB)
#define TOPBT9_TESTIQ_RSEL_SET(x)                                    (((0 | (x)) << TOPBT9_TESTIQ_RSEL_LSB) & TOPBT9_TESTIQ_RSEL_MASK)
#define TOPBT9_TESTIQ_RSEL_RESET                                     0
#define TOPBT9_RESERVED_MSB                                          2
#define TOPBT9_RESERVED_LSB                                          1
#define TOPBT9_RESERVED_MASK                                         0x00000006
#define TOPBT9_RESERVED_GET(x)                                       (((x) & TOPBT9_RESERVED_MASK) >> TOPBT9_RESERVED_LSB)
#define TOPBT9_RESERVED_SET(x)                                       (((0 | (x)) << TOPBT9_RESERVED_LSB) & TOPBT9_RESERVED_MASK)
#define TOPBT9_RESERVED_RESET                                        0
#define TOPBT9_ENABLE_LPO2_MSB                                       0
#define TOPBT9_ENABLE_LPO2_LSB                                       0
#define TOPBT9_ENABLE_LPO2_MASK                                      0x00000001
#define TOPBT9_ENABLE_LPO2_GET(x)                                    (((x) & TOPBT9_ENABLE_LPO2_MASK) >> TOPBT9_ENABLE_LPO2_LSB)
#define TOPBT9_ENABLE_LPO2_SET(x)                                    (((0 | (x)) << TOPBT9_ENABLE_LPO2_LSB) & TOPBT9_ENABLE_LPO2_MASK)
#define TOPBT9_ENABLE_LPO2_RESET                                     0
#define TOPBT9_ADDRESS                                               0x0020
#define TOPBT9_HW_MASK                                               0xffffffff
#define TOPBT9_SW_MASK                                               0xffffffff
#define TOPBT9_HW_WRITE_MASK                                         0xffff8000
#define TOPBT9_SW_WRITE_MASK                                         0x00007fff
#define TOPBT9_RSTMASK                                               0xffffffff
#define TOPBT9_RESET                                                 0x00001800

// 0x0024 (TOPBT10)
#define TOPBT10_AICSTANDBY_ENABLE_MSB                                31
#define TOPBT10_AICSTANDBY_ENABLE_LSB                                29
#define TOPBT10_AICSTANDBY_ENABLE_MASK                               0xe0000000
#define TOPBT10_AICSTANDBY_ENABLE_GET(x)                             (((x) & TOPBT10_AICSTANDBY_ENABLE_MASK) >> TOPBT10_AICSTANDBY_ENABLE_LSB)
#define TOPBT10_AICSTANDBY_ENABLE_SET(x)                             (((0 | (x)) << TOPBT10_AICSTANDBY_ENABLE_LSB) & TOPBT10_AICSTANDBY_ENABLE_MASK)
#define TOPBT10_AICSTANDBY_ENABLE_RESET                              0
#define TOPBT10_AIC_FIX_CAPDIV_MSB                                   28
#define TOPBT10_AIC_FIX_CAPDIV_LSB                                   26
#define TOPBT10_AIC_FIX_CAPDIV_MASK                                  0x1c000000
#define TOPBT10_AIC_FIX_CAPDIV_GET(x)                                (((x) & TOPBT10_AIC_FIX_CAPDIV_MASK) >> TOPBT10_AIC_FIX_CAPDIV_LSB)
#define TOPBT10_AIC_FIX_CAPDIV_SET(x)                                (((0 | (x)) << TOPBT10_AIC_FIX_CAPDIV_LSB) & TOPBT10_AIC_FIX_CAPDIV_MASK)
#define TOPBT10_AIC_FIX_CAPDIV_RESET                                 0
#define TOPBT10_AIC_CSTEER_EN_MSB                                    25
#define TOPBT10_AIC_CSTEER_EN_LSB                                    25
#define TOPBT10_AIC_CSTEER_EN_MASK                                   0x02000000
#define TOPBT10_AIC_CSTEER_EN_GET(x)                                 (((x) & TOPBT10_AIC_CSTEER_EN_MASK) >> TOPBT10_AIC_CSTEER_EN_LSB)
#define TOPBT10_AIC_CSTEER_EN_SET(x)                                 (((0 | (x)) << TOPBT10_AIC_CSTEER_EN_LSB) & TOPBT10_AIC_CSTEER_EN_MASK)
#define TOPBT10_AIC_CSTEER_EN_RESET                                  1
#define TOPBT10_PWDAICVGAI_MSB                                       24
#define TOPBT10_PWDAICVGAI_LSB                                       22
#define TOPBT10_PWDAICVGAI_MASK                                      0x01c00000
#define TOPBT10_PWDAICVGAI_GET(x)                                    (((x) & TOPBT10_PWDAICVGAI_MASK) >> TOPBT10_PWDAICVGAI_LSB)
#define TOPBT10_PWDAICVGAI_SET(x)                                    (((0 | (x)) << TOPBT10_PWDAICVGAI_LSB) & TOPBT10_PWDAICVGAI_MASK)
#define TOPBT10_PWDAICVGAI_RESET                                     0
#define TOPBT10_PWDAICVGAQ_MSB                                       21
#define TOPBT10_PWDAICVGAQ_LSB                                       19
#define TOPBT10_PWDAICVGAQ_MASK                                      0x00380000
#define TOPBT10_PWDAICVGAQ_GET(x)                                    (((x) & TOPBT10_PWDAICVGAQ_MASK) >> TOPBT10_PWDAICVGAQ_LSB)
#define TOPBT10_PWDAICVGAQ_SET(x)                                    (((0 | (x)) << TOPBT10_PWDAICVGAQ_LSB) & TOPBT10_PWDAICVGAQ_MASK)
#define TOPBT10_PWDAICVGAQ_RESET                                     0
#define TOPBT10_LOCAL_AICPWD_MSB                                     18
#define TOPBT10_LOCAL_AICPWD_LSB                                     18
#define TOPBT10_LOCAL_AICPWD_MASK                                    0x00040000
#define TOPBT10_LOCAL_AICPWD_GET(x)                                  (((x) & TOPBT10_LOCAL_AICPWD_MASK) >> TOPBT10_LOCAL_AICPWD_LSB)
#define TOPBT10_LOCAL_AICPWD_SET(x)                                  (((0 | (x)) << TOPBT10_LOCAL_AICPWD_LSB) & TOPBT10_LOCAL_AICPWD_MASK)
#define TOPBT10_LOCAL_AICPWD_RESET                                   0
#define TOPBT10_AIC_ATB_MSB                                          17
#define TOPBT10_AIC_ATB_LSB                                          15
#define TOPBT10_AIC_ATB_MASK                                         0x00038000
#define TOPBT10_AIC_ATB_GET(x)                                       (((x) & TOPBT10_AIC_ATB_MASK) >> TOPBT10_AIC_ATB_LSB)
#define TOPBT10_AIC_ATB_SET(x)                                       (((0 | (x)) << TOPBT10_AIC_ATB_LSB) & TOPBT10_AIC_ATB_MASK)
#define TOPBT10_AIC_ATB_RESET                                        0
#define TOPBT10_VREFMUL1_MSB                                         14
#define TOPBT10_VREFMUL1_LSB                                         11
#define TOPBT10_VREFMUL1_MASK                                        0x00007800
#define TOPBT10_VREFMUL1_GET(x)                                      (((x) & TOPBT10_VREFMUL1_MASK) >> TOPBT10_VREFMUL1_LSB)
#define TOPBT10_VREFMUL1_SET(x)                                      (((0 | (x)) << TOPBT10_VREFMUL1_LSB) & TOPBT10_VREFMUL1_MASK)
#define TOPBT10_VREFMUL1_RESET                                       4
#define TOPBT10_VREFMUL2_MSB                                         10
#define TOPBT10_VREFMUL2_LSB                                         7
#define TOPBT10_VREFMUL2_MASK                                        0x00000780
#define TOPBT10_VREFMUL2_GET(x)                                      (((x) & TOPBT10_VREFMUL2_MASK) >> TOPBT10_VREFMUL2_LSB)
#define TOPBT10_VREFMUL2_SET(x)                                      (((0 | (x)) << TOPBT10_VREFMUL2_LSB) & TOPBT10_VREFMUL2_MASK)
#define TOPBT10_VREFMUL2_RESET                                       8
#define TOPBT10_VREFMUL3_MSB                                         6
#define TOPBT10_VREFMUL3_LSB                                         3
#define TOPBT10_VREFMUL3_MASK                                        0x00000078
#define TOPBT10_VREFMUL3_GET(x)                                      (((x) & TOPBT10_VREFMUL3_MASK) >> TOPBT10_VREFMUL3_LSB)
#define TOPBT10_VREFMUL3_SET(x)                                      (((0 | (x)) << TOPBT10_VREFMUL3_LSB) & TOPBT10_VREFMUL3_MASK)
#define TOPBT10_VREFMUL3_RESET                                       12
#define TOPBT10_STRCONT_MSB                                          2
#define TOPBT10_STRCONT_LSB                                          2
#define TOPBT10_STRCONT_MASK                                         0x00000004
#define TOPBT10_STRCONT_GET(x)                                       (((x) & TOPBT10_STRCONT_MASK) >> TOPBT10_STRCONT_LSB)
#define TOPBT10_STRCONT_SET(x)                                       (((0 | (x)) << TOPBT10_STRCONT_LSB) & TOPBT10_STRCONT_MASK)
#define TOPBT10_STRCONT_RESET                                        1
#define TOPBT10_RESERVED_MSB                                         1
#define TOPBT10_RESERVED_LSB                                         0
#define TOPBT10_RESERVED_MASK                                        0x00000003
#define TOPBT10_RESERVED_GET(x)                                      (((x) & TOPBT10_RESERVED_MASK) >> TOPBT10_RESERVED_LSB)
#define TOPBT10_RESERVED_SET(x)                                      (((0 | (x)) << TOPBT10_RESERVED_LSB) & TOPBT10_RESERVED_MASK)
#define TOPBT10_RESERVED_RESET                                       0
#define TOPBT10_ADDRESS                                              0x0024
#define TOPBT10_HW_MASK                                              0xffffffff
#define TOPBT10_SW_MASK                                              0xffffffff
#define TOPBT10_HW_WRITE_MASK                                        0x00000000
#define TOPBT10_SW_WRITE_MASK                                        0xffffffff
#define TOPBT10_RSTMASK                                              0xffffffff
#define TOPBT10_RESET                                                0x02002464


#endif /* _TOPBT_REG_CSR_H_ */
