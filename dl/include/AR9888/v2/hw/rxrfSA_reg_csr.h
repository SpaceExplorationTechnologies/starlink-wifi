//                                                                             
// File:       ./rxrfSA_reg_csr.vrh                                            
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:47:12 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             rxrfSA_reg_csr.rdl                                              
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/radio_peregrine/rtl/srif/blueprint/rxrfSA_reg.rdl
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
                                                                             


#ifndef _RXRFSA_REG_CSR_H_
#define _RXRFSA_REG_CSR_H_
// 0x0000 (RXRFSA_BIAS1)
#define RXRFSA_BIAS1_PWD_BIAS_MSB                                    31
#define RXRFSA_BIAS1_PWD_BIAS_LSB                                    31
#define RXRFSA_BIAS1_PWD_BIAS_MASK                                   0x80000000
#define RXRFSA_BIAS1_PWD_BIAS_GET(x)                                 (((x) & RXRFSA_BIAS1_PWD_BIAS_MASK) >> RXRFSA_BIAS1_PWD_BIAS_LSB)
#define RXRFSA_BIAS1_PWD_BIAS_SET(x)                                 (((0 | (x)) << RXRFSA_BIAS1_PWD_BIAS_LSB) & RXRFSA_BIAS1_PWD_BIAS_MASK)
#define RXRFSA_BIAS1_PWD_BIAS_RESET                                  0
#define RXRFSA_BIAS1_PWD_IC75LNA2G_MSB                               30
#define RXRFSA_BIAS1_PWD_IC75LNA2G_LSB                               28
#define RXRFSA_BIAS1_PWD_IC75LNA2G_MASK                              0x70000000
#define RXRFSA_BIAS1_PWD_IC75LNA2G_GET(x)                            (((x) & RXRFSA_BIAS1_PWD_IC75LNA2G_MASK) >> RXRFSA_BIAS1_PWD_IC75LNA2G_LSB)
#define RXRFSA_BIAS1_PWD_IC75LNA2G_SET(x)                            (((0 | (x)) << RXRFSA_BIAS1_PWD_IC75LNA2G_LSB) & RXRFSA_BIAS1_PWD_IC75LNA2G_MASK)
#define RXRFSA_BIAS1_PWD_IC75LNA2G_RESET                             3
#define RXRFSA_BIAS1_PWD_IC25MXR2GH_MSB                              27
#define RXRFSA_BIAS1_PWD_IC25MXR2GH_LSB                              25
#define RXRFSA_BIAS1_PWD_IC25MXR2GH_MASK                             0x0e000000
#define RXRFSA_BIAS1_PWD_IC25MXR2GH_GET(x)                           (((x) & RXRFSA_BIAS1_PWD_IC25MXR2GH_MASK) >> RXRFSA_BIAS1_PWD_IC25MXR2GH_LSB)
#define RXRFSA_BIAS1_PWD_IC25MXR2GH_SET(x)                           (((0 | (x)) << RXRFSA_BIAS1_PWD_IC25MXR2GH_LSB) & RXRFSA_BIAS1_PWD_IC25MXR2GH_MASK)
#define RXRFSA_BIAS1_PWD_IC25MXR2GH_RESET                            3
#define RXRFSA_BIAS1_PWD_IR25LO24_MSB                                24
#define RXRFSA_BIAS1_PWD_IR25LO24_LSB                                22
#define RXRFSA_BIAS1_PWD_IR25LO24_MASK                               0x01c00000
#define RXRFSA_BIAS1_PWD_IR25LO24_GET(x)                             (((x) & RXRFSA_BIAS1_PWD_IR25LO24_MASK) >> RXRFSA_BIAS1_PWD_IR25LO24_LSB)
#define RXRFSA_BIAS1_PWD_IR25LO24_SET(x)                             (((0 | (x)) << RXRFSA_BIAS1_PWD_IR25LO24_LSB) & RXRFSA_BIAS1_PWD_IR25LO24_MASK)
#define RXRFSA_BIAS1_PWD_IR25LO24_RESET                              3
#define RXRFSA_BIAS1_PWD_IC75LNA5G_MSB                               21
#define RXRFSA_BIAS1_PWD_IC75LNA5G_LSB                               19
#define RXRFSA_BIAS1_PWD_IC75LNA5G_MASK                              0x00380000
#define RXRFSA_BIAS1_PWD_IC75LNA5G_GET(x)                            (((x) & RXRFSA_BIAS1_PWD_IC75LNA5G_MASK) >> RXRFSA_BIAS1_PWD_IC75LNA5G_LSB)
#define RXRFSA_BIAS1_PWD_IC75LNA5G_SET(x)                            (((0 | (x)) << RXRFSA_BIAS1_PWD_IC75LNA5G_LSB) & RXRFSA_BIAS1_PWD_IC75LNA5G_MASK)
#define RXRFSA_BIAS1_PWD_IC75LNA5G_RESET                             3
#define RXRFSA_BIAS1_PWD_IC25VGA5G_MSB                               18
#define RXRFSA_BIAS1_PWD_IC25VGA5G_LSB                               16
#define RXRFSA_BIAS1_PWD_IC25VGA5G_MASK                              0x00070000
#define RXRFSA_BIAS1_PWD_IC25VGA5G_GET(x)                            (((x) & RXRFSA_BIAS1_PWD_IC25VGA5G_MASK) >> RXRFSA_BIAS1_PWD_IC25VGA5G_LSB)
#define RXRFSA_BIAS1_PWD_IC25VGA5G_SET(x)                            (((0 | (x)) << RXRFSA_BIAS1_PWD_IC25VGA5G_LSB) & RXRFSA_BIAS1_PWD_IC25VGA5G_MASK)
#define RXRFSA_BIAS1_PWD_IC25VGA5G_RESET                             3
#define RXRFSA_BIAS1_PWD_IC25MXR5GH_MSB                              15
#define RXRFSA_BIAS1_PWD_IC25MXR5GH_LSB                              13
#define RXRFSA_BIAS1_PWD_IC25MXR5GH_MASK                             0x0000e000
#define RXRFSA_BIAS1_PWD_IC25MXR5GH_GET(x)                           (((x) & RXRFSA_BIAS1_PWD_IC25MXR5GH_MASK) >> RXRFSA_BIAS1_PWD_IC25MXR5GH_LSB)
#define RXRFSA_BIAS1_PWD_IC25MXR5GH_SET(x)                           (((0 | (x)) << RXRFSA_BIAS1_PWD_IC25MXR5GH_LSB) & RXRFSA_BIAS1_PWD_IC25MXR5GH_MASK)
#define RXRFSA_BIAS1_PWD_IC25MXR5GH_RESET                            3
#define RXRFSA_BIAS1_PWD_IC25MXR2_5GH_MSB                            12
#define RXRFSA_BIAS1_PWD_IC25MXR2_5GH_LSB                            10
#define RXRFSA_BIAS1_PWD_IC25MXR2_5GH_MASK                           0x00001c00
#define RXRFSA_BIAS1_PWD_IC25MXR2_5GH_GET(x)                         (((x) & RXRFSA_BIAS1_PWD_IC25MXR2_5GH_MASK) >> RXRFSA_BIAS1_PWD_IC25MXR2_5GH_LSB)
#define RXRFSA_BIAS1_PWD_IC25MXR2_5GH_SET(x)                         (((0 | (x)) << RXRFSA_BIAS1_PWD_IC25MXR2_5GH_LSB) & RXRFSA_BIAS1_PWD_IC25MXR2_5GH_MASK)
#define RXRFSA_BIAS1_PWD_IC25MXR2_5GH_RESET                          3
#define RXRFSA_BIAS1_PWD_IC25LO36_MSB                                9
#define RXRFSA_BIAS1_PWD_IC25LO36_LSB                                7
#define RXRFSA_BIAS1_PWD_IC25LO36_MASK                               0x00000380
#define RXRFSA_BIAS1_PWD_IC25LO36_GET(x)                             (((x) & RXRFSA_BIAS1_PWD_IC25LO36_MASK) >> RXRFSA_BIAS1_PWD_IC25LO36_LSB)
#define RXRFSA_BIAS1_PWD_IC25LO36_SET(x)                             (((0 | (x)) << RXRFSA_BIAS1_PWD_IC25LO36_LSB) & RXRFSA_BIAS1_PWD_IC25LO36_MASK)
#define RXRFSA_BIAS1_PWD_IC25LO36_RESET                              3
#define RXRFSA_BIAS1_PWD_IR25LO18_MSB                                6
#define RXRFSA_BIAS1_PWD_IR25LO18_LSB                                4
#define RXRFSA_BIAS1_PWD_IR25LO18_MASK                               0x00000070
#define RXRFSA_BIAS1_PWD_IR25LO18_GET(x)                             (((x) & RXRFSA_BIAS1_PWD_IR25LO18_MASK) >> RXRFSA_BIAS1_PWD_IR25LO18_LSB)
#define RXRFSA_BIAS1_PWD_IR25LO18_SET(x)                             (((0 | (x)) << RXRFSA_BIAS1_PWD_IR25LO18_LSB) & RXRFSA_BIAS1_PWD_IR25LO18_MASK)
#define RXRFSA_BIAS1_PWD_IR25LO18_RESET                              3
#define RXRFSA_BIAS1_PWD_IR25SPARE_MSB                               3
#define RXRFSA_BIAS1_PWD_IR25SPARE_LSB                               1
#define RXRFSA_BIAS1_PWD_IR25SPARE_MASK                              0x0000000e
#define RXRFSA_BIAS1_PWD_IR25SPARE_GET(x)                            (((x) & RXRFSA_BIAS1_PWD_IR25SPARE_MASK) >> RXRFSA_BIAS1_PWD_IR25SPARE_LSB)
#define RXRFSA_BIAS1_PWD_IR25SPARE_SET(x)                            (((0 | (x)) << RXRFSA_BIAS1_PWD_IR25SPARE_LSB) & RXRFSA_BIAS1_PWD_IR25SPARE_MASK)
#define RXRFSA_BIAS1_PWD_IR25SPARE_RESET                             3
#define RXRFSA_BIAS1_SPARE_MSB                                       0
#define RXRFSA_BIAS1_SPARE_LSB                                       0
#define RXRFSA_BIAS1_SPARE_MASK                                      0x00000001
#define RXRFSA_BIAS1_SPARE_GET(x)                                    (((x) & RXRFSA_BIAS1_SPARE_MASK) >> RXRFSA_BIAS1_SPARE_LSB)
#define RXRFSA_BIAS1_SPARE_SET(x)                                    (((0 | (x)) << RXRFSA_BIAS1_SPARE_LSB) & RXRFSA_BIAS1_SPARE_MASK)
#define RXRFSA_BIAS1_SPARE_RESET                                     0
#define RXRFSA_BIAS1_ADDRESS                                         0x0000
#define RXRFSA_BIAS1_HW_MASK                                         0xffffffff
#define RXRFSA_BIAS1_SW_MASK                                         0xffffffff
#define RXRFSA_BIAS1_HW_WRITE_MASK                                   0x00000000
#define RXRFSA_BIAS1_SW_WRITE_MASK                                   0xffffffff
#define RXRFSA_BIAS1_RSTMASK                                         0xffffffff
#define RXRFSA_BIAS1_RESET                                           0x36db6db6

// 0x0004 (RXRFSA_BIAS2)
#define RXRFSA_BIAS2_PWD_IR25VCM_MSB                                 31
#define RXRFSA_BIAS2_PWD_IR25VCM_LSB                                 29
#define RXRFSA_BIAS2_PWD_IR25VCM_MASK                                0xe0000000
#define RXRFSA_BIAS2_PWD_IR25VCM_GET(x)                              (((x) & RXRFSA_BIAS2_PWD_IR25VCM_MASK) >> RXRFSA_BIAS2_PWD_IR25VCM_LSB)
#define RXRFSA_BIAS2_PWD_IR25VCM_SET(x)                              (((0 | (x)) << RXRFSA_BIAS2_PWD_IR25VCM_LSB) & RXRFSA_BIAS2_PWD_IR25VCM_MASK)
#define RXRFSA_BIAS2_PWD_IR25VCM_RESET                               3
#define RXRFSA_BIAS2_PWD_IC25VCMBUF_MSB                              28
#define RXRFSA_BIAS2_PWD_IC25VCMBUF_LSB                              26
#define RXRFSA_BIAS2_PWD_IC25VCMBUF_MASK                             0x1c000000
#define RXRFSA_BIAS2_PWD_IC25VCMBUF_GET(x)                           (((x) & RXRFSA_BIAS2_PWD_IC25VCMBUF_MASK) >> RXRFSA_BIAS2_PWD_IC25VCMBUF_LSB)
#define RXRFSA_BIAS2_PWD_IC25VCMBUF_SET(x)                           (((0 | (x)) << RXRFSA_BIAS2_PWD_IC25VCMBUF_LSB) & RXRFSA_BIAS2_PWD_IC25VCMBUF_MASK)
#define RXRFSA_BIAS2_PWD_IC25VCMBUF_RESET                            3
#define RXRFSA_BIAS2_PWD_IC25AGC_MSB                                 25
#define RXRFSA_BIAS2_PWD_IC25AGC_LSB                                 23
#define RXRFSA_BIAS2_PWD_IC25AGC_MASK                                0x03800000
#define RXRFSA_BIAS2_PWD_IC25AGC_GET(x)                              (((x) & RXRFSA_BIAS2_PWD_IC25AGC_MASK) >> RXRFSA_BIAS2_PWD_IC25AGC_LSB)
#define RXRFSA_BIAS2_PWD_IC25AGC_SET(x)                              (((0 | (x)) << RXRFSA_BIAS2_PWD_IC25AGC_LSB) & RXRFSA_BIAS2_PWD_IC25AGC_MASK)
#define RXRFSA_BIAS2_PWD_IC25AGC_RESET                               3
#define RXRFSA_BIAS2_PWD_IR25AGC_MSB                                 22
#define RXRFSA_BIAS2_PWD_IR25AGC_LSB                                 20
#define RXRFSA_BIAS2_PWD_IR25AGC_MASK                                0x00700000
#define RXRFSA_BIAS2_PWD_IR25AGC_GET(x)                              (((x) & RXRFSA_BIAS2_PWD_IR25AGC_MASK) >> RXRFSA_BIAS2_PWD_IR25AGC_LSB)
#define RXRFSA_BIAS2_PWD_IR25AGC_SET(x)                              (((0 | (x)) << RXRFSA_BIAS2_PWD_IR25AGC_LSB) & RXRFSA_BIAS2_PWD_IR25AGC_MASK)
#define RXRFSA_BIAS2_PWD_IR25AGC_RESET                               3
#define RXRFSA_BIAS2_PWD_IR25AGCH_MSB                                19
#define RXRFSA_BIAS2_PWD_IR25AGCH_LSB                                17
#define RXRFSA_BIAS2_PWD_IR25AGCH_MASK                               0x000e0000
#define RXRFSA_BIAS2_PWD_IR25AGCH_GET(x)                             (((x) & RXRFSA_BIAS2_PWD_IR25AGCH_MASK) >> RXRFSA_BIAS2_PWD_IR25AGCH_LSB)
#define RXRFSA_BIAS2_PWD_IR25AGCH_SET(x)                             (((0 | (x)) << RXRFSA_BIAS2_PWD_IR25AGCH_LSB) & RXRFSA_BIAS2_PWD_IR25AGCH_MASK)
#define RXRFSA_BIAS2_PWD_IR25AGCH_RESET                              3
#define RXRFSA_BIAS2_PWD_IC25LNABUF_MSB                              16
#define RXRFSA_BIAS2_PWD_IC25LNABUF_LSB                              14
#define RXRFSA_BIAS2_PWD_IC25LNABUF_MASK                             0x0001c000
#define RXRFSA_BIAS2_PWD_IC25LNABUF_GET(x)                           (((x) & RXRFSA_BIAS2_PWD_IC25LNABUF_MASK) >> RXRFSA_BIAS2_PWD_IC25LNABUF_LSB)
#define RXRFSA_BIAS2_PWD_IC25LNABUF_SET(x)                           (((0 | (x)) << RXRFSA_BIAS2_PWD_IC25LNABUF_LSB) & RXRFSA_BIAS2_PWD_IC25LNABUF_MASK)
#define RXRFSA_BIAS2_PWD_IC25LNABUF_RESET                            3
#define RXRFSA_BIAS2_PWD_IR25SPARE_MSB                               13
#define RXRFSA_BIAS2_PWD_IR25SPARE_LSB                               11
#define RXRFSA_BIAS2_PWD_IR25SPARE_MASK                              0x00003800
#define RXRFSA_BIAS2_PWD_IR25SPARE_GET(x)                            (((x) & RXRFSA_BIAS2_PWD_IR25SPARE_MASK) >> RXRFSA_BIAS2_PWD_IR25SPARE_LSB)
#define RXRFSA_BIAS2_PWD_IR25SPARE_SET(x)                            (((0 | (x)) << RXRFSA_BIAS2_PWD_IR25SPARE_LSB) & RXRFSA_BIAS2_PWD_IR25SPARE_MASK)
#define RXRFSA_BIAS2_PWD_IR25SPARE_RESET                             3
#define RXRFSA_BIAS2_PWD_IR25SPAREH_MSB                              10
#define RXRFSA_BIAS2_PWD_IR25SPAREH_LSB                              8
#define RXRFSA_BIAS2_PWD_IR25SPAREH_MASK                             0x00000700
#define RXRFSA_BIAS2_PWD_IR25SPAREH_GET(x)                           (((x) & RXRFSA_BIAS2_PWD_IR25SPAREH_MASK) >> RXRFSA_BIAS2_PWD_IR25SPAREH_LSB)
#define RXRFSA_BIAS2_PWD_IR25SPAREH_SET(x)                           (((0 | (x)) << RXRFSA_BIAS2_PWD_IR25SPAREH_LSB) & RXRFSA_BIAS2_PWD_IR25SPAREH_MASK)
#define RXRFSA_BIAS2_PWD_IR25SPAREH_RESET                            3
#define RXRFSA_BIAS2_PWD_VCMBUF_MSB                                  7
#define RXRFSA_BIAS2_PWD_VCMBUF_LSB                                  7
#define RXRFSA_BIAS2_PWD_VCMBUF_MASK                                 0x00000080
#define RXRFSA_BIAS2_PWD_VCMBUF_GET(x)                               (((x) & RXRFSA_BIAS2_PWD_VCMBUF_MASK) >> RXRFSA_BIAS2_PWD_VCMBUF_LSB)
#define RXRFSA_BIAS2_PWD_VCMBUF_SET(x)                               (((0 | (x)) << RXRFSA_BIAS2_PWD_VCMBUF_LSB) & RXRFSA_BIAS2_PWD_VCMBUF_MASK)
#define RXRFSA_BIAS2_PWD_VCMBUF_RESET                                0
#define RXRFSA_BIAS2_VCMVALUE_MSB                                    6
#define RXRFSA_BIAS2_VCMVALUE_LSB                                    4
#define RXRFSA_BIAS2_VCMVALUE_MASK                                   0x00000070
#define RXRFSA_BIAS2_VCMVALUE_GET(x)                                 (((x) & RXRFSA_BIAS2_VCMVALUE_MASK) >> RXRFSA_BIAS2_VCMVALUE_LSB)
#define RXRFSA_BIAS2_VCMVALUE_SET(x)                                 (((0 | (x)) << RXRFSA_BIAS2_VCMVALUE_LSB) & RXRFSA_BIAS2_VCMVALUE_MASK)
#define RXRFSA_BIAS2_VCMVALUE_RESET                                  4
#define RXRFSA_BIAS2_PKEN_MSB                                        3
#define RXRFSA_BIAS2_PKEN_LSB                                        0
#define RXRFSA_BIAS2_PKEN_MASK                                       0x0000000f
#define RXRFSA_BIAS2_PKEN_GET(x)                                     (((x) & RXRFSA_BIAS2_PKEN_MASK) >> RXRFSA_BIAS2_PKEN_LSB)
#define RXRFSA_BIAS2_PKEN_SET(x)                                     (((0 | (x)) << RXRFSA_BIAS2_PKEN_LSB) & RXRFSA_BIAS2_PKEN_MASK)
#define RXRFSA_BIAS2_PKEN_RESET                                      0
#define RXRFSA_BIAS2_ADDRESS                                         0x0004
#define RXRFSA_BIAS2_HW_MASK                                         0xffffffff
#define RXRFSA_BIAS2_SW_MASK                                         0xffffffff
#define RXRFSA_BIAS2_HW_WRITE_MASK                                   0x00000000
#define RXRFSA_BIAS2_SW_WRITE_MASK                                   0xffffffff
#define RXRFSA_BIAS2_RSTMASK                                         0xffffffff
#define RXRFSA_BIAS2_RESET                                           0x6db6db40

// 0x0008 (RXRFSA_GAINSTAGES)
#define RXRFSA_GAINSTAGES_RX_OVERRIDE_MSB                            31
#define RXRFSA_GAINSTAGES_RX_OVERRIDE_LSB                            31
#define RXRFSA_GAINSTAGES_RX_OVERRIDE_MASK                           0x80000000
#define RXRFSA_GAINSTAGES_RX_OVERRIDE_GET(x)                         (((x) & RXRFSA_GAINSTAGES_RX_OVERRIDE_MASK) >> RXRFSA_GAINSTAGES_RX_OVERRIDE_LSB)
#define RXRFSA_GAINSTAGES_RX_OVERRIDE_SET(x)                         (((0 | (x)) << RXRFSA_GAINSTAGES_RX_OVERRIDE_LSB) & RXRFSA_GAINSTAGES_RX_OVERRIDE_MASK)
#define RXRFSA_GAINSTAGES_RX_OVERRIDE_RESET                          0
#define RXRFSA_GAINSTAGES_LNA2G_GAIN_OVR_MSB                         30
#define RXRFSA_GAINSTAGES_LNA2G_GAIN_OVR_LSB                         28
#define RXRFSA_GAINSTAGES_LNA2G_GAIN_OVR_MASK                        0x70000000
#define RXRFSA_GAINSTAGES_LNA2G_GAIN_OVR_GET(x)                      (((x) & RXRFSA_GAINSTAGES_LNA2G_GAIN_OVR_MASK) >> RXRFSA_GAINSTAGES_LNA2G_GAIN_OVR_LSB)
#define RXRFSA_GAINSTAGES_LNA2G_GAIN_OVR_SET(x)                      (((0 | (x)) << RXRFSA_GAINSTAGES_LNA2G_GAIN_OVR_LSB) & RXRFSA_GAINSTAGES_LNA2G_GAIN_OVR_MASK)
#define RXRFSA_GAINSTAGES_LNA2G_GAIN_OVR_RESET                       4
#define RXRFSA_GAINSTAGES_MXR2G_GAIN_OVR_MSB                         27
#define RXRFSA_GAINSTAGES_MXR2G_GAIN_OVR_LSB                         26
#define RXRFSA_GAINSTAGES_MXR2G_GAIN_OVR_MASK                        0x0c000000
#define RXRFSA_GAINSTAGES_MXR2G_GAIN_OVR_GET(x)                      (((x) & RXRFSA_GAINSTAGES_MXR2G_GAIN_OVR_MASK) >> RXRFSA_GAINSTAGES_MXR2G_GAIN_OVR_LSB)
#define RXRFSA_GAINSTAGES_MXR2G_GAIN_OVR_SET(x)                      (((0 | (x)) << RXRFSA_GAINSTAGES_MXR2G_GAIN_OVR_LSB) & RXRFSA_GAINSTAGES_MXR2G_GAIN_OVR_MASK)
#define RXRFSA_GAINSTAGES_MXR2G_GAIN_OVR_RESET                       1
#define RXRFSA_GAINSTAGES_LNA5G_GAIN_OVR_MSB                         25
#define RXRFSA_GAINSTAGES_LNA5G_GAIN_OVR_LSB                         23
#define RXRFSA_GAINSTAGES_LNA5G_GAIN_OVR_MASK                        0x03800000
#define RXRFSA_GAINSTAGES_LNA5G_GAIN_OVR_GET(x)                      (((x) & RXRFSA_GAINSTAGES_LNA5G_GAIN_OVR_MASK) >> RXRFSA_GAINSTAGES_LNA5G_GAIN_OVR_LSB)
#define RXRFSA_GAINSTAGES_LNA5G_GAIN_OVR_SET(x)                      (((0 | (x)) << RXRFSA_GAINSTAGES_LNA5G_GAIN_OVR_LSB) & RXRFSA_GAINSTAGES_LNA5G_GAIN_OVR_MASK)
#define RXRFSA_GAINSTAGES_LNA5G_GAIN_OVR_RESET                       4
#define RXRFSA_GAINSTAGES_VGA5G_GAIN_OVR_MSB                         22
#define RXRFSA_GAINSTAGES_VGA5G_GAIN_OVR_LSB                         20
#define RXRFSA_GAINSTAGES_VGA5G_GAIN_OVR_MASK                        0x00700000
#define RXRFSA_GAINSTAGES_VGA5G_GAIN_OVR_GET(x)                      (((x) & RXRFSA_GAINSTAGES_VGA5G_GAIN_OVR_MASK) >> RXRFSA_GAINSTAGES_VGA5G_GAIN_OVR_LSB)
#define RXRFSA_GAINSTAGES_VGA5G_GAIN_OVR_SET(x)                      (((0 | (x)) << RXRFSA_GAINSTAGES_VGA5G_GAIN_OVR_LSB) & RXRFSA_GAINSTAGES_VGA5G_GAIN_OVR_MASK)
#define RXRFSA_GAINSTAGES_VGA5G_GAIN_OVR_RESET                       4
#define RXRFSA_GAINSTAGES_MXR5G_GAIN_OVR_MSB                         19
#define RXRFSA_GAINSTAGES_MXR5G_GAIN_OVR_LSB                         18
#define RXRFSA_GAINSTAGES_MXR5G_GAIN_OVR_MASK                        0x000c0000
#define RXRFSA_GAINSTAGES_MXR5G_GAIN_OVR_GET(x)                      (((x) & RXRFSA_GAINSTAGES_MXR5G_GAIN_OVR_MASK) >> RXRFSA_GAINSTAGES_MXR5G_GAIN_OVR_LSB)
#define RXRFSA_GAINSTAGES_MXR5G_GAIN_OVR_SET(x)                      (((0 | (x)) << RXRFSA_GAINSTAGES_MXR5G_GAIN_OVR_LSB) & RXRFSA_GAINSTAGES_MXR5G_GAIN_OVR_MASK)
#define RXRFSA_GAINSTAGES_MXR5G_GAIN_OVR_RESET                       1
#define RXRFSA_GAINSTAGES_PWD_LNA2G_MSB                              17
#define RXRFSA_GAINSTAGES_PWD_LNA2G_LSB                              17
#define RXRFSA_GAINSTAGES_PWD_LNA2G_MASK                             0x00020000
#define RXRFSA_GAINSTAGES_PWD_LNA2G_GET(x)                           (((x) & RXRFSA_GAINSTAGES_PWD_LNA2G_MASK) >> RXRFSA_GAINSTAGES_PWD_LNA2G_LSB)
#define RXRFSA_GAINSTAGES_PWD_LNA2G_SET(x)                           (((0 | (x)) << RXRFSA_GAINSTAGES_PWD_LNA2G_LSB) & RXRFSA_GAINSTAGES_PWD_LNA2G_MASK)
#define RXRFSA_GAINSTAGES_PWD_LNA2G_RESET                            0
#define RXRFSA_GAINSTAGES_PWD_MXR2G_MSB                              16
#define RXRFSA_GAINSTAGES_PWD_MXR2G_LSB                              16
#define RXRFSA_GAINSTAGES_PWD_MXR2G_MASK                             0x00010000
#define RXRFSA_GAINSTAGES_PWD_MXR2G_GET(x)                           (((x) & RXRFSA_GAINSTAGES_PWD_MXR2G_MASK) >> RXRFSA_GAINSTAGES_PWD_MXR2G_LSB)
#define RXRFSA_GAINSTAGES_PWD_MXR2G_SET(x)                           (((0 | (x)) << RXRFSA_GAINSTAGES_PWD_MXR2G_LSB) & RXRFSA_GAINSTAGES_PWD_MXR2G_MASK)
#define RXRFSA_GAINSTAGES_PWD_MXR2G_RESET                            0
#define RXRFSA_GAINSTAGES_PWD_LO2G_MSB                               15
#define RXRFSA_GAINSTAGES_PWD_LO2G_LSB                               15
#define RXRFSA_GAINSTAGES_PWD_LO2G_MASK                              0x00008000
#define RXRFSA_GAINSTAGES_PWD_LO2G_GET(x)                            (((x) & RXRFSA_GAINSTAGES_PWD_LO2G_MASK) >> RXRFSA_GAINSTAGES_PWD_LO2G_LSB)
#define RXRFSA_GAINSTAGES_PWD_LO2G_SET(x)                            (((0 | (x)) << RXRFSA_GAINSTAGES_PWD_LO2G_LSB) & RXRFSA_GAINSTAGES_PWD_LO2G_MASK)
#define RXRFSA_GAINSTAGES_PWD_LO2G_RESET                             0
#define RXRFSA_GAINSTAGES_LNA2G_LP_MSB                               14
#define RXRFSA_GAINSTAGES_LNA2G_LP_LSB                               14
#define RXRFSA_GAINSTAGES_LNA2G_LP_MASK                              0x00004000
#define RXRFSA_GAINSTAGES_LNA2G_LP_GET(x)                            (((x) & RXRFSA_GAINSTAGES_LNA2G_LP_MASK) >> RXRFSA_GAINSTAGES_LNA2G_LP_LSB)
#define RXRFSA_GAINSTAGES_LNA2G_LP_SET(x)                            (((0 | (x)) << RXRFSA_GAINSTAGES_LNA2G_LP_LSB) & RXRFSA_GAINSTAGES_LNA2G_LP_MASK)
#define RXRFSA_GAINSTAGES_LNA2G_LP_RESET                             0
#define RXRFSA_GAINSTAGES_LNA2G_SHORTINP_MSB                         13
#define RXRFSA_GAINSTAGES_LNA2G_SHORTINP_LSB                         13
#define RXRFSA_GAINSTAGES_LNA2G_SHORTINP_MASK                        0x00002000
#define RXRFSA_GAINSTAGES_LNA2G_SHORTINP_GET(x)                      (((x) & RXRFSA_GAINSTAGES_LNA2G_SHORTINP_MASK) >> RXRFSA_GAINSTAGES_LNA2G_SHORTINP_LSB)
#define RXRFSA_GAINSTAGES_LNA2G_SHORTINP_SET(x)                      (((0 | (x)) << RXRFSA_GAINSTAGES_LNA2G_SHORTINP_LSB) & RXRFSA_GAINSTAGES_LNA2G_SHORTINP_MASK)
#define RXRFSA_GAINSTAGES_LNA2G_SHORTINP_RESET                       0
#define RXRFSA_GAINSTAGES_LNA2G_CAP_MSB                              12
#define RXRFSA_GAINSTAGES_LNA2G_CAP_LSB                              11
#define RXRFSA_GAINSTAGES_LNA2G_CAP_MASK                             0x00001800
#define RXRFSA_GAINSTAGES_LNA2G_CAP_GET(x)                           (((x) & RXRFSA_GAINSTAGES_LNA2G_CAP_MASK) >> RXRFSA_GAINSTAGES_LNA2G_CAP_LSB)
#define RXRFSA_GAINSTAGES_LNA2G_CAP_SET(x)                           (((0 | (x)) << RXRFSA_GAINSTAGES_LNA2G_CAP_LSB) & RXRFSA_GAINSTAGES_LNA2G_CAP_MASK)
#define RXRFSA_GAINSTAGES_LNA2G_CAP_RESET                            0
#define RXRFSA_GAINSTAGES_PWD_LNA5G_MSB                              10
#define RXRFSA_GAINSTAGES_PWD_LNA5G_LSB                              10
#define RXRFSA_GAINSTAGES_PWD_LNA5G_MASK                             0x00000400
#define RXRFSA_GAINSTAGES_PWD_LNA5G_GET(x)                           (((x) & RXRFSA_GAINSTAGES_PWD_LNA5G_MASK) >> RXRFSA_GAINSTAGES_PWD_LNA5G_LSB)
#define RXRFSA_GAINSTAGES_PWD_LNA5G_SET(x)                           (((0 | (x)) << RXRFSA_GAINSTAGES_PWD_LNA5G_LSB) & RXRFSA_GAINSTAGES_PWD_LNA5G_MASK)
#define RXRFSA_GAINSTAGES_PWD_LNA5G_RESET                            0
#define RXRFSA_GAINSTAGES_PWD_MXR5G_MSB                              9
#define RXRFSA_GAINSTAGES_PWD_MXR5G_LSB                              9
#define RXRFSA_GAINSTAGES_PWD_MXR5G_MASK                             0x00000200
#define RXRFSA_GAINSTAGES_PWD_MXR5G_GET(x)                           (((x) & RXRFSA_GAINSTAGES_PWD_MXR5G_MASK) >> RXRFSA_GAINSTAGES_PWD_MXR5G_LSB)
#define RXRFSA_GAINSTAGES_PWD_MXR5G_SET(x)                           (((0 | (x)) << RXRFSA_GAINSTAGES_PWD_MXR5G_LSB) & RXRFSA_GAINSTAGES_PWD_MXR5G_MASK)
#define RXRFSA_GAINSTAGES_PWD_MXR5G_RESET                            0
#define RXRFSA_GAINSTAGES_PWD_VGA5G_MSB                              8
#define RXRFSA_GAINSTAGES_PWD_VGA5G_LSB                              8
#define RXRFSA_GAINSTAGES_PWD_VGA5G_MASK                             0x00000100
#define RXRFSA_GAINSTAGES_PWD_VGA5G_GET(x)                           (((x) & RXRFSA_GAINSTAGES_PWD_VGA5G_MASK) >> RXRFSA_GAINSTAGES_PWD_VGA5G_LSB)
#define RXRFSA_GAINSTAGES_PWD_VGA5G_SET(x)                           (((0 | (x)) << RXRFSA_GAINSTAGES_PWD_VGA5G_LSB) & RXRFSA_GAINSTAGES_PWD_VGA5G_MASK)
#define RXRFSA_GAINSTAGES_PWD_VGA5G_RESET                            0
#define RXRFSA_GAINSTAGES_PWD_LO5G_MSB                               7
#define RXRFSA_GAINSTAGES_PWD_LO5G_LSB                               7
#define RXRFSA_GAINSTAGES_PWD_LO5G_MASK                              0x00000080
#define RXRFSA_GAINSTAGES_PWD_LO5G_GET(x)                            (((x) & RXRFSA_GAINSTAGES_PWD_LO5G_MASK) >> RXRFSA_GAINSTAGES_PWD_LO5G_LSB)
#define RXRFSA_GAINSTAGES_PWD_LO5G_SET(x)                            (((0 | (x)) << RXRFSA_GAINSTAGES_PWD_LO5G_LSB) & RXRFSA_GAINSTAGES_PWD_LO5G_MASK)
#define RXRFSA_GAINSTAGES_PWD_LO5G_RESET                             0
#define RXRFSA_GAINSTAGES_LNA5G_SHORTINP_MSB                         6
#define RXRFSA_GAINSTAGES_LNA5G_SHORTINP_LSB                         6
#define RXRFSA_GAINSTAGES_LNA5G_SHORTINP_MASK                        0x00000040
#define RXRFSA_GAINSTAGES_LNA5G_SHORTINP_GET(x)                      (((x) & RXRFSA_GAINSTAGES_LNA5G_SHORTINP_MASK) >> RXRFSA_GAINSTAGES_LNA5G_SHORTINP_LSB)
#define RXRFSA_GAINSTAGES_LNA5G_SHORTINP_SET(x)                      (((0 | (x)) << RXRFSA_GAINSTAGES_LNA5G_SHORTINP_LSB) & RXRFSA_GAINSTAGES_LNA5G_SHORTINP_MASK)
#define RXRFSA_GAINSTAGES_LNA5G_SHORTINP_RESET                       0
#define RXRFSA_GAINSTAGES_LNA5G_CAP_MSB                              5
#define RXRFSA_GAINSTAGES_LNA5G_CAP_LSB                              4
#define RXRFSA_GAINSTAGES_LNA5G_CAP_MASK                             0x00000030
#define RXRFSA_GAINSTAGES_LNA5G_CAP_GET(x)                           (((x) & RXRFSA_GAINSTAGES_LNA5G_CAP_MASK) >> RXRFSA_GAINSTAGES_LNA5G_CAP_LSB)
#define RXRFSA_GAINSTAGES_LNA5G_CAP_SET(x)                           (((0 | (x)) << RXRFSA_GAINSTAGES_LNA5G_CAP_LSB) & RXRFSA_GAINSTAGES_LNA5G_CAP_MASK)
#define RXRFSA_GAINSTAGES_LNA5G_CAP_RESET                            0
#define RXRFSA_GAINSTAGES_VGA5G_CAP_MSB                              3
#define RXRFSA_GAINSTAGES_VGA5G_CAP_LSB                              2
#define RXRFSA_GAINSTAGES_VGA5G_CAP_MASK                             0x0000000c
#define RXRFSA_GAINSTAGES_VGA5G_CAP_GET(x)                           (((x) & RXRFSA_GAINSTAGES_VGA5G_CAP_MASK) >> RXRFSA_GAINSTAGES_VGA5G_CAP_LSB)
#define RXRFSA_GAINSTAGES_VGA5G_CAP_SET(x)                           (((0 | (x)) << RXRFSA_GAINSTAGES_VGA5G_CAP_LSB) & RXRFSA_GAINSTAGES_VGA5G_CAP_MASK)
#define RXRFSA_GAINSTAGES_VGA5G_CAP_RESET                            0
#define RXRFSA_GAINSTAGES_LNAON_CALDC_MSB                            1
#define RXRFSA_GAINSTAGES_LNAON_CALDC_LSB                            1
#define RXRFSA_GAINSTAGES_LNAON_CALDC_MASK                           0x00000002
#define RXRFSA_GAINSTAGES_LNAON_CALDC_GET(x)                         (((x) & RXRFSA_GAINSTAGES_LNAON_CALDC_MASK) >> RXRFSA_GAINSTAGES_LNAON_CALDC_LSB)
#define RXRFSA_GAINSTAGES_LNAON_CALDC_SET(x)                         (((0 | (x)) << RXRFSA_GAINSTAGES_LNAON_CALDC_LSB) & RXRFSA_GAINSTAGES_LNAON_CALDC_MASK)
#define RXRFSA_GAINSTAGES_LNAON_CALDC_RESET                          0
#define RXRFSA_GAINSTAGES_SPARE_MSB                                  0
#define RXRFSA_GAINSTAGES_SPARE_LSB                                  0
#define RXRFSA_GAINSTAGES_SPARE_MASK                                 0x00000001
#define RXRFSA_GAINSTAGES_SPARE_GET(x)                               (((x) & RXRFSA_GAINSTAGES_SPARE_MASK) >> RXRFSA_GAINSTAGES_SPARE_LSB)
#define RXRFSA_GAINSTAGES_SPARE_SET(x)                               (((0 | (x)) << RXRFSA_GAINSTAGES_SPARE_LSB) & RXRFSA_GAINSTAGES_SPARE_MASK)
#define RXRFSA_GAINSTAGES_SPARE_RESET                                0
#define RXRFSA_GAINSTAGES_ADDRESS                                    0x0008
#define RXRFSA_GAINSTAGES_HW_MASK                                    0xffffffff
#define RXRFSA_GAINSTAGES_SW_MASK                                    0xffffffff
#define RXRFSA_GAINSTAGES_HW_WRITE_MASK                              0x00000000
#define RXRFSA_GAINSTAGES_SW_WRITE_MASK                              0xffffffff
#define RXRFSA_GAINSTAGES_RSTMASK                                    0xffffffff
#define RXRFSA_GAINSTAGES_RESET                                      0x46440000

// 0x000c (RXRFSA_AGC)
#define RXRFSA_AGC_AGC_OVERRIDE_MSB                                  31
#define RXRFSA_AGC_AGC_OVERRIDE_LSB                                  31
#define RXRFSA_AGC_AGC_OVERRIDE_MASK                                 0x80000000
#define RXRFSA_AGC_AGC_OVERRIDE_GET(x)                               (((x) & RXRFSA_AGC_AGC_OVERRIDE_MASK) >> RXRFSA_AGC_AGC_OVERRIDE_LSB)
#define RXRFSA_AGC_AGC_OVERRIDE_SET(x)                               (((0 | (x)) << RXRFSA_AGC_AGC_OVERRIDE_LSB) & RXRFSA_AGC_AGC_OVERRIDE_MASK)
#define RXRFSA_AGC_AGC_OVERRIDE_RESET                                0
#define RXRFSA_AGC_AGC_ON_OVR_MSB                                    30
#define RXRFSA_AGC_AGC_ON_OVR_LSB                                    30
#define RXRFSA_AGC_AGC_ON_OVR_MASK                                   0x40000000
#define RXRFSA_AGC_AGC_ON_OVR_GET(x)                                 (((x) & RXRFSA_AGC_AGC_ON_OVR_MASK) >> RXRFSA_AGC_AGC_ON_OVR_LSB)
#define RXRFSA_AGC_AGC_ON_OVR_SET(x)                                 (((0 | (x)) << RXRFSA_AGC_AGC_ON_OVR_LSB) & RXRFSA_AGC_AGC_ON_OVR_MASK)
#define RXRFSA_AGC_AGC_ON_OVR_RESET                                  0
#define RXRFSA_AGC_AGC_CAL_OVR_MSB                                   29
#define RXRFSA_AGC_AGC_CAL_OVR_LSB                                   29
#define RXRFSA_AGC_AGC_CAL_OVR_MASK                                  0x20000000
#define RXRFSA_AGC_AGC_CAL_OVR_GET(x)                                (((x) & RXRFSA_AGC_AGC_CAL_OVR_MASK) >> RXRFSA_AGC_AGC_CAL_OVR_LSB)
#define RXRFSA_AGC_AGC_CAL_OVR_SET(x)                                (((0 | (x)) << RXRFSA_AGC_AGC_CAL_OVR_LSB) & RXRFSA_AGC_AGC_CAL_OVR_MASK)
#define RXRFSA_AGC_AGC_CAL_OVR_RESET                                 0
#define RXRFSA_AGC_AGC2G_DBDAC_OVR_MSB                               28
#define RXRFSA_AGC_AGC2G_DBDAC_OVR_LSB                               25
#define RXRFSA_AGC_AGC2G_DBDAC_OVR_MASK                              0x1e000000
#define RXRFSA_AGC_AGC2G_DBDAC_OVR_GET(x)                            (((x) & RXRFSA_AGC_AGC2G_DBDAC_OVR_MASK) >> RXRFSA_AGC_AGC2G_DBDAC_OVR_LSB)
#define RXRFSA_AGC_AGC2G_DBDAC_OVR_SET(x)                            (((0 | (x)) << RXRFSA_AGC_AGC2G_DBDAC_OVR_LSB) & RXRFSA_AGC_AGC2G_DBDAC_OVR_MASK)
#define RXRFSA_AGC_AGC2G_DBDAC_OVR_RESET                             0
#define RXRFSA_AGC_AGC2G_CALDAC_OVR_MSB                              24
#define RXRFSA_AGC_AGC2G_CALDAC_OVR_LSB                              19
#define RXRFSA_AGC_AGC2G_CALDAC_OVR_MASK                             0x01f80000
#define RXRFSA_AGC_AGC2G_CALDAC_OVR_GET(x)                           (((x) & RXRFSA_AGC_AGC2G_CALDAC_OVR_MASK) >> RXRFSA_AGC_AGC2G_CALDAC_OVR_LSB)
#define RXRFSA_AGC_AGC2G_CALDAC_OVR_SET(x)                           (((0 | (x)) << RXRFSA_AGC_AGC2G_CALDAC_OVR_LSB) & RXRFSA_AGC_AGC2G_CALDAC_OVR_MASK)
#define RXRFSA_AGC_AGC2G_CALDAC_OVR_RESET                            0
#define RXRFSA_AGC_AGC5G_DBDAC_OVR_MSB                               18
#define RXRFSA_AGC_AGC5G_DBDAC_OVR_LSB                               15
#define RXRFSA_AGC_AGC5G_DBDAC_OVR_MASK                              0x00078000
#define RXRFSA_AGC_AGC5G_DBDAC_OVR_GET(x)                            (((x) & RXRFSA_AGC_AGC5G_DBDAC_OVR_MASK) >> RXRFSA_AGC_AGC5G_DBDAC_OVR_LSB)
#define RXRFSA_AGC_AGC5G_DBDAC_OVR_SET(x)                            (((0 | (x)) << RXRFSA_AGC_AGC5G_DBDAC_OVR_LSB) & RXRFSA_AGC_AGC5G_DBDAC_OVR_MASK)
#define RXRFSA_AGC_AGC5G_DBDAC_OVR_RESET                             0
#define RXRFSA_AGC_AGC5G_CALDAC_OVR_MSB                              14
#define RXRFSA_AGC_AGC5G_CALDAC_OVR_LSB                              9
#define RXRFSA_AGC_AGC5G_CALDAC_OVR_MASK                             0x00007e00
#define RXRFSA_AGC_AGC5G_CALDAC_OVR_GET(x)                           (((x) & RXRFSA_AGC_AGC5G_CALDAC_OVR_MASK) >> RXRFSA_AGC_AGC5G_CALDAC_OVR_LSB)
#define RXRFSA_AGC_AGC5G_CALDAC_OVR_SET(x)                           (((0 | (x)) << RXRFSA_AGC_AGC5G_CALDAC_OVR_LSB) & RXRFSA_AGC_AGC5G_CALDAC_OVR_MASK)
#define RXRFSA_AGC_AGC5G_CALDAC_OVR_RESET                            0
#define RXRFSA_AGC_AGC_FALL_CTRL_MSB                                 8
#define RXRFSA_AGC_AGC_FALL_CTRL_LSB                                 6
#define RXRFSA_AGC_AGC_FALL_CTRL_MASK                                0x000001c0
#define RXRFSA_AGC_AGC_FALL_CTRL_GET(x)                              (((x) & RXRFSA_AGC_AGC_FALL_CTRL_MASK) >> RXRFSA_AGC_AGC_FALL_CTRL_LSB)
#define RXRFSA_AGC_AGC_FALL_CTRL_SET(x)                              (((0 | (x)) << RXRFSA_AGC_AGC_FALL_CTRL_LSB) & RXRFSA_AGC_AGC_FALL_CTRL_MASK)
#define RXRFSA_AGC_AGC_FALL_CTRL_RESET                               0
#define RXRFSA_AGC_PWD_LNABUF_MSB                                    5
#define RXRFSA_AGC_PWD_LNABUF_LSB                                    5
#define RXRFSA_AGC_PWD_LNABUF_MASK                                   0x00000020
#define RXRFSA_AGC_PWD_LNABUF_GET(x)                                 (((x) & RXRFSA_AGC_PWD_LNABUF_MASK) >> RXRFSA_AGC_PWD_LNABUF_LSB)
#define RXRFSA_AGC_PWD_LNABUF_SET(x)                                 (((0 | (x)) << RXRFSA_AGC_PWD_LNABUF_LSB) & RXRFSA_AGC_PWD_LNABUF_MASK)
#define RXRFSA_AGC_PWD_LNABUF_RESET                                  0
#define RXRFSA_AGC_LNABUF_PWD_OVR_MSB                                4
#define RXRFSA_AGC_LNABUF_PWD_OVR_LSB                                4
#define RXRFSA_AGC_LNABUF_PWD_OVR_MASK                               0x00000010
#define RXRFSA_AGC_LNABUF_PWD_OVR_GET(x)                             (((x) & RXRFSA_AGC_LNABUF_PWD_OVR_MASK) >> RXRFSA_AGC_LNABUF_PWD_OVR_LSB)
#define RXRFSA_AGC_LNABUF_PWD_OVR_SET(x)                             (((0 | (x)) << RXRFSA_AGC_LNABUF_PWD_OVR_LSB) & RXRFSA_AGC_LNABUF_PWD_OVR_MASK)
#define RXRFSA_AGC_LNABUF_PWD_OVR_RESET                              0
#define RXRFSA_AGC_LNABUFGAIN2X_MSB                                  3
#define RXRFSA_AGC_LNABUFGAIN2X_LSB                                  3
#define RXRFSA_AGC_LNABUFGAIN2X_MASK                                 0x00000008
#define RXRFSA_AGC_LNABUFGAIN2X_GET(x)                               (((x) & RXRFSA_AGC_LNABUFGAIN2X_MASK) >> RXRFSA_AGC_LNABUFGAIN2X_LSB)
#define RXRFSA_AGC_LNABUFGAIN2X_SET(x)                               (((0 | (x)) << RXRFSA_AGC_LNABUFGAIN2X_LSB) & RXRFSA_AGC_LNABUFGAIN2X_MASK)
#define RXRFSA_AGC_LNABUFGAIN2X_RESET                                0
#define RXRFSA_AGC_AGC_OUT_MSB                                       2
#define RXRFSA_AGC_AGC_OUT_LSB                                       2
#define RXRFSA_AGC_AGC_OUT_MASK                                      0x00000004
#define RXRFSA_AGC_AGC_OUT_GET(x)                                    (((x) & RXRFSA_AGC_AGC_OUT_MASK) >> RXRFSA_AGC_AGC_OUT_LSB)
#define RXRFSA_AGC_AGC_OUT_SET(x)                                    (((0 | (x)) << RXRFSA_AGC_AGC_OUT_LSB) & RXRFSA_AGC_AGC_OUT_MASK)
#define RXRFSA_AGC_AGC_OUT_RESET                                     0
#define RXRFSA_AGC_RF2G_ON_DURING_CALPA_MSB                          1
#define RXRFSA_AGC_RF2G_ON_DURING_CALPA_LSB                          1
#define RXRFSA_AGC_RF2G_ON_DURING_CALPA_MASK                         0x00000002
#define RXRFSA_AGC_RF2G_ON_DURING_CALPA_GET(x)                       (((x) & RXRFSA_AGC_RF2G_ON_DURING_CALPA_MASK) >> RXRFSA_AGC_RF2G_ON_DURING_CALPA_LSB)
#define RXRFSA_AGC_RF2G_ON_DURING_CALPA_SET(x)                       (((0 | (x)) << RXRFSA_AGC_RF2G_ON_DURING_CALPA_LSB) & RXRFSA_AGC_RF2G_ON_DURING_CALPA_MASK)
#define RXRFSA_AGC_RF2G_ON_DURING_CALPA_RESET                        0
#define RXRFSA_AGC_RF5G_ON_DURING_CALPA_MSB                          0
#define RXRFSA_AGC_RF5G_ON_DURING_CALPA_LSB                          0
#define RXRFSA_AGC_RF5G_ON_DURING_CALPA_MASK                         0x00000001
#define RXRFSA_AGC_RF5G_ON_DURING_CALPA_GET(x)                       (((x) & RXRFSA_AGC_RF5G_ON_DURING_CALPA_MASK) >> RXRFSA_AGC_RF5G_ON_DURING_CALPA_LSB)
#define RXRFSA_AGC_RF5G_ON_DURING_CALPA_SET(x)                       (((0 | (x)) << RXRFSA_AGC_RF5G_ON_DURING_CALPA_LSB) & RXRFSA_AGC_RF5G_ON_DURING_CALPA_MASK)
#define RXRFSA_AGC_RF5G_ON_DURING_CALPA_RESET                        0
#define RXRFSA_AGC_ADDRESS                                           0x000c
#define RXRFSA_AGC_HW_MASK                                           0xffffffff
#define RXRFSA_AGC_SW_MASK                                           0xffffffff
#define RXRFSA_AGC_HW_WRITE_MASK                                     0x00000004
#define RXRFSA_AGC_SW_WRITE_MASK                                     0xfffffffb
#define RXRFSA_AGC_RSTMASK                                           0xffffffff
#define RXRFSA_AGC_RESET                                             0x00000000

// 0x0010 (RXRFSA_BIAS3)
#define RXRFSA_BIAS3_PWD_IC50AIC_MSB                                 31
#define RXRFSA_BIAS3_PWD_IC50AIC_LSB                                 29
#define RXRFSA_BIAS3_PWD_IC50AIC_MASK                                0xe0000000
#define RXRFSA_BIAS3_PWD_IC50AIC_GET(x)                              (((x) & RXRFSA_BIAS3_PWD_IC50AIC_MASK) >> RXRFSA_BIAS3_PWD_IC50AIC_LSB)
#define RXRFSA_BIAS3_PWD_IC50AIC_SET(x)                              (((0 | (x)) << RXRFSA_BIAS3_PWD_IC50AIC_LSB) & RXRFSA_BIAS3_PWD_IC50AIC_MASK)
#define RXRFSA_BIAS3_PWD_IC50AIC_RESET                               3
#define RXRFSA_BIAS3_PWD_IC50LNABUF2G_MSB                            28
#define RXRFSA_BIAS3_PWD_IC50LNABUF2G_LSB                            26
#define RXRFSA_BIAS3_PWD_IC50LNABUF2G_MASK                           0x1c000000
#define RXRFSA_BIAS3_PWD_IC50LNABUF2G_GET(x)                         (((x) & RXRFSA_BIAS3_PWD_IC50LNABUF2G_MASK) >> RXRFSA_BIAS3_PWD_IC50LNABUF2G_LSB)
#define RXRFSA_BIAS3_PWD_IC50LNABUF2G_SET(x)                         (((0 | (x)) << RXRFSA_BIAS3_PWD_IC50LNABUF2G_LSB) & RXRFSA_BIAS3_PWD_IC50LNABUF2G_MASK)
#define RXRFSA_BIAS3_PWD_IC50LNABUF2G_RESET                          3
#define RXRFSA_BIAS3_PWD_IC25SPARE_MSB                               25
#define RXRFSA_BIAS3_PWD_IC25SPARE_LSB                               23
#define RXRFSA_BIAS3_PWD_IC25SPARE_MASK                              0x03800000
#define RXRFSA_BIAS3_PWD_IC25SPARE_GET(x)                            (((x) & RXRFSA_BIAS3_PWD_IC25SPARE_MASK) >> RXRFSA_BIAS3_PWD_IC25SPARE_LSB)
#define RXRFSA_BIAS3_PWD_IC25SPARE_SET(x)                            (((0 | (x)) << RXRFSA_BIAS3_PWD_IC25SPARE_LSB) & RXRFSA_BIAS3_PWD_IC25SPARE_MASK)
#define RXRFSA_BIAS3_PWD_IC25SPARE_RESET                             3
#define RXRFSA_BIAS3_MXRFORCEDON_MSB                                 22
#define RXRFSA_BIAS3_MXRFORCEDON_LSB                                 22
#define RXRFSA_BIAS3_MXRFORCEDON_MASK                                0x00400000
#define RXRFSA_BIAS3_MXRFORCEDON_GET(x)                              (((x) & RXRFSA_BIAS3_MXRFORCEDON_MASK) >> RXRFSA_BIAS3_MXRFORCEDON_LSB)
#define RXRFSA_BIAS3_MXRFORCEDON_SET(x)                              (((0 | (x)) << RXRFSA_BIAS3_MXRFORCEDON_LSB) & RXRFSA_BIAS3_MXRFORCEDON_MASK)
#define RXRFSA_BIAS3_MXRFORCEDON_RESET                               0
#define RXRFSA_BIAS3_BT_LNA_CNT_OVR_MSB                              21
#define RXRFSA_BIAS3_BT_LNA_CNT_OVR_LSB                              21
#define RXRFSA_BIAS3_BT_LNA_CNT_OVR_MASK                             0x00200000
#define RXRFSA_BIAS3_BT_LNA_CNT_OVR_GET(x)                           (((x) & RXRFSA_BIAS3_BT_LNA_CNT_OVR_MASK) >> RXRFSA_BIAS3_BT_LNA_CNT_OVR_LSB)
#define RXRFSA_BIAS3_BT_LNA_CNT_OVR_SET(x)                           (((0 | (x)) << RXRFSA_BIAS3_BT_LNA_CNT_OVR_LSB) & RXRFSA_BIAS3_BT_LNA_CNT_OVR_MASK)
#define RXRFSA_BIAS3_BT_LNA_CNT_OVR_RESET                            0
#define RXRFSA_BIAS3_USE_BT_LNA_MSB                                  20
#define RXRFSA_BIAS3_USE_BT_LNA_LSB                                  20
#define RXRFSA_BIAS3_USE_BT_LNA_MASK                                 0x00100000
#define RXRFSA_BIAS3_USE_BT_LNA_GET(x)                               (((x) & RXRFSA_BIAS3_USE_BT_LNA_MASK) >> RXRFSA_BIAS3_USE_BT_LNA_LSB)
#define RXRFSA_BIAS3_USE_BT_LNA_SET(x)                               (((0 | (x)) << RXRFSA_BIAS3_USE_BT_LNA_LSB) & RXRFSA_BIAS3_USE_BT_LNA_MASK)
#define RXRFSA_BIAS3_USE_BT_LNA_RESET                                0
#define RXRFSA_BIAS3_PWD_AICGM_MSB                                   19
#define RXRFSA_BIAS3_PWD_AICGM_LSB                                   19
#define RXRFSA_BIAS3_PWD_AICGM_MASK                                  0x00080000
#define RXRFSA_BIAS3_PWD_AICGM_GET(x)                                (((x) & RXRFSA_BIAS3_PWD_AICGM_MASK) >> RXRFSA_BIAS3_PWD_AICGM_LSB)
#define RXRFSA_BIAS3_PWD_AICGM_SET(x)                                (((0 | (x)) << RXRFSA_BIAS3_PWD_AICGM_LSB) & RXRFSA_BIAS3_PWD_AICGM_MASK)
#define RXRFSA_BIAS3_PWD_AICGM_RESET                                 0
#define RXRFSA_BIAS3_PWD_AICGM_OVR_MSB                               18
#define RXRFSA_BIAS3_PWD_AICGM_OVR_LSB                               18
#define RXRFSA_BIAS3_PWD_AICGM_OVR_MASK                              0x00040000
#define RXRFSA_BIAS3_PWD_AICGM_OVR_GET(x)                            (((x) & RXRFSA_BIAS3_PWD_AICGM_OVR_MASK) >> RXRFSA_BIAS3_PWD_AICGM_OVR_LSB)
#define RXRFSA_BIAS3_PWD_AICGM_OVR_SET(x)                            (((0 | (x)) << RXRFSA_BIAS3_PWD_AICGM_OVR_LSB) & RXRFSA_BIAS3_PWD_AICGM_OVR_MASK)
#define RXRFSA_BIAS3_PWD_AICGM_OVR_RESET                             0
#define RXRFSA_BIAS3_AICSTBY_ENABLE_MSB                              17
#define RXRFSA_BIAS3_AICSTBY_ENABLE_LSB                              17
#define RXRFSA_BIAS3_AICSTBY_ENABLE_MASK                             0x00020000
#define RXRFSA_BIAS3_AICSTBY_ENABLE_GET(x)                           (((x) & RXRFSA_BIAS3_AICSTBY_ENABLE_MASK) >> RXRFSA_BIAS3_AICSTBY_ENABLE_LSB)
#define RXRFSA_BIAS3_AICSTBY_ENABLE_SET(x)                           (((0 | (x)) << RXRFSA_BIAS3_AICSTBY_ENABLE_LSB) & RXRFSA_BIAS3_AICSTBY_ENABLE_MASK)
#define RXRFSA_BIAS3_AICSTBY_ENABLE_RESET                            1
#define RXRFSA_BIAS3_AICSTBY_VGAON_ENABLE_MSB                        16
#define RXRFSA_BIAS3_AICSTBY_VGAON_ENABLE_LSB                        16
#define RXRFSA_BIAS3_AICSTBY_VGAON_ENABLE_MASK                       0x00010000
#define RXRFSA_BIAS3_AICSTBY_VGAON_ENABLE_GET(x)                     (((x) & RXRFSA_BIAS3_AICSTBY_VGAON_ENABLE_MASK) >> RXRFSA_BIAS3_AICSTBY_VGAON_ENABLE_LSB)
#define RXRFSA_BIAS3_AICSTBY_VGAON_ENABLE_SET(x)                     (((0 | (x)) << RXRFSA_BIAS3_AICSTBY_VGAON_ENABLE_LSB) & RXRFSA_BIAS3_AICSTBY_VGAON_ENABLE_MASK)
#define RXRFSA_BIAS3_AICSTBY_VGAON_ENABLE_RESET                      0
#define RXRFSA_BIAS3_KEEPLNABUF2GCASCON_MSB                          15
#define RXRFSA_BIAS3_KEEPLNABUF2GCASCON_LSB                          15
#define RXRFSA_BIAS3_KEEPLNABUF2GCASCON_MASK                         0x00008000
#define RXRFSA_BIAS3_KEEPLNABUF2GCASCON_GET(x)                       (((x) & RXRFSA_BIAS3_KEEPLNABUF2GCASCON_MASK) >> RXRFSA_BIAS3_KEEPLNABUF2GCASCON_LSB)
#define RXRFSA_BIAS3_KEEPLNABUF2GCASCON_SET(x)                       (((0 | (x)) << RXRFSA_BIAS3_KEEPLNABUF2GCASCON_LSB) & RXRFSA_BIAS3_KEEPLNABUF2GCASCON_MASK)
#define RXRFSA_BIAS3_KEEPLNABUF2GCASCON_RESET                        0
#define RXRFSA_BIAS3_CONTROLSPARE_MSB                                14
#define RXRFSA_BIAS3_CONTROLSPARE_LSB                                0
#define RXRFSA_BIAS3_CONTROLSPARE_MASK                               0x00007fff
#define RXRFSA_BIAS3_CONTROLSPARE_GET(x)                             (((x) & RXRFSA_BIAS3_CONTROLSPARE_MASK) >> RXRFSA_BIAS3_CONTROLSPARE_LSB)
#define RXRFSA_BIAS3_CONTROLSPARE_SET(x)                             (((0 | (x)) << RXRFSA_BIAS3_CONTROLSPARE_LSB) & RXRFSA_BIAS3_CONTROLSPARE_MASK)
#define RXRFSA_BIAS3_CONTROLSPARE_RESET                              1
#define RXRFSA_BIAS3_ADDRESS                                         0x0010
#define RXRFSA_BIAS3_HW_MASK                                         0xffffffff
#define RXRFSA_BIAS3_SW_MASK                                         0xffffffff
#define RXRFSA_BIAS3_HW_WRITE_MASK                                   0x00000000
#define RXRFSA_BIAS3_SW_WRITE_MASK                                   0xffffffff
#define RXRFSA_BIAS3_RSTMASK                                         0xffffffff
#define RXRFSA_BIAS3_RESET                                           0x6d820001


#endif /* _RXRFSA_REG_CSR_H_ */
