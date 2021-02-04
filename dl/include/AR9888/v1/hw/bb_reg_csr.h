//                                                                             
// File:       ./bb_reg_csr.vrh                                                
// Creator:    shung                                                           
// Time:       Monday Apr 23, 2012 [6:25:17 pm]                                
//                                                                             
// Path:       /trees/shung/shung-dev/chips/peregrine/1.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux/blueprint -odir . -codegen   
//             ath_vrh.codegen -ath_vrh -Wdesc -I                              
//             /trees/shung/shung-dev/chips/peregrine/1.0/blueprint/sysconfig  
//             bb_reg_csr.rdl                                                  
//                                                                             
// Sources:    /trees/shung/shung-dev/chips/peregrine/1.0/ip/radio_peregrine/rtl/srif/blueprint/bb_reg.rdl
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


#ifndef _BB_REG_CSR_H_
#define _BB_REG_CSR_H_
// 0x0000 (BB1)
#define BB1_RANGE_OSDAC_MSB                                          31
#define BB1_RANGE_OSDAC_LSB                                          30
#define BB1_RANGE_OSDAC_MASK                                         0xc0000000
#define BB1_RANGE_OSDAC_GET(x)                                       (((x) & BB1_RANGE_OSDAC_MASK) >> BB1_RANGE_OSDAC_LSB)
#define BB1_RANGE_OSDAC_SET(x)                                       (((0 | (x)) << BB1_RANGE_OSDAC_LSB) & BB1_RANGE_OSDAC_MASK)
#define BB1_RANGE_OSDAC_RESET                                        0
#define BB1_LOCALOFFSET_MSB                                          29
#define BB1_LOCALOFFSET_LSB                                          29
#define BB1_LOCALOFFSET_MASK                                         0x20000000
#define BB1_LOCALOFFSET_GET(x)                                       (((x) & BB1_LOCALOFFSET_MASK) >> BB1_LOCALOFFSET_LSB)
#define BB1_LOCALOFFSET_SET(x)                                       (((0 | (x)) << BB1_LOCALOFFSET_LSB) & BB1_LOCALOFFSET_MASK)
#define BB1_LOCALOFFSET_RESET                                        0
#define BB1_OFSTCORRI2VI_MSB                                         28
#define BB1_OFSTCORRI2VI_LSB                                         24
#define BB1_OFSTCORRI2VI_MASK                                        0x1f000000
#define BB1_OFSTCORRI2VI_GET(x)                                      (((x) & BB1_OFSTCORRI2VI_MASK) >> BB1_OFSTCORRI2VI_LSB)
#define BB1_OFSTCORRI2VI_SET(x)                                      (((0 | (x)) << BB1_OFSTCORRI2VI_LSB) & BB1_OFSTCORRI2VI_MASK)
#define BB1_OFSTCORRI2VI_RESET                                       16
#define BB1_OFSTCORRI2VQ_MSB                                         23
#define BB1_OFSTCORRI2VQ_LSB                                         19
#define BB1_OFSTCORRI2VQ_MASK                                        0x00f80000
#define BB1_OFSTCORRI2VQ_GET(x)                                      (((x) & BB1_OFSTCORRI2VQ_MASK) >> BB1_OFSTCORRI2VQ_LSB)
#define BB1_OFSTCORRI2VQ_SET(x)                                      (((0 | (x)) << BB1_OFSTCORRI2VQ_LSB) & BB1_OFSTCORRI2VQ_MASK)
#define BB1_OFSTCORRI2VQ_RESET                                       16
#define BB1_ATBSEL_MSB                                               18
#define BB1_ATBSEL_LSB                                               16
#define BB1_ATBSEL_MASK                                              0x00070000
#define BB1_ATBSEL_GET(x)                                            (((x) & BB1_ATBSEL_MASK) >> BB1_ATBSEL_LSB)
#define BB1_ATBSEL_SET(x)                                            (((0 | (x)) << BB1_ATBSEL_LSB) & BB1_ATBSEL_MASK)
#define BB1_ATBSEL_RESET                                             0
#define BB1_CMSEL1_MSB                                               15
#define BB1_CMSEL1_LSB                                               13
#define BB1_CMSEL1_MASK                                              0x0000e000
#define BB1_CMSEL1_GET(x)                                            (((x) & BB1_CMSEL1_MASK) >> BB1_CMSEL1_LSB)
#define BB1_CMSEL1_SET(x)                                            (((0 | (x)) << BB1_CMSEL1_LSB) & BB1_CMSEL1_MASK)
#define BB1_CMSEL1_RESET                                             2
#define BB1_CMSEL2_MSB                                               12
#define BB1_CMSEL2_LSB                                               10
#define BB1_CMSEL2_MASK                                              0x00001c00
#define BB1_CMSEL2_GET(x)                                            (((x) & BB1_CMSEL2_MASK) >> BB1_CMSEL2_LSB)
#define BB1_CMSEL2_SET(x)                                            (((0 | (x)) << BB1_CMSEL2_LSB) & BB1_CMSEL2_MASK)
#define BB1_CMSEL2_RESET                                             2
#define BB1_PWD_RCFILT_OVR_MSB                                       9
#define BB1_PWD_RCFILT_OVR_LSB                                       9
#define BB1_PWD_RCFILT_OVR_MASK                                      0x00000200
#define BB1_PWD_RCFILT_OVR_GET(x)                                    (((x) & BB1_PWD_RCFILT_OVR_MASK) >> BB1_PWD_RCFILT_OVR_LSB)
#define BB1_PWD_RCFILT_OVR_SET(x)                                    (((0 | (x)) << BB1_PWD_RCFILT_OVR_LSB) & BB1_PWD_RCFILT_OVR_MASK)
#define BB1_PWD_RCFILT_OVR_RESET                                     0
#define BB1_PWD_RCFILT_MSB                                           8
#define BB1_PWD_RCFILT_LSB                                           8
#define BB1_PWD_RCFILT_MASK                                          0x00000100
#define BB1_PWD_RCFILT_GET(x)                                        (((x) & BB1_PWD_RCFILT_MASK) >> BB1_PWD_RCFILT_LSB)
#define BB1_PWD_RCFILT_SET(x)                                        (((0 | (x)) << BB1_PWD_RCFILT_LSB) & BB1_PWD_RCFILT_MASK)
#define BB1_PWD_RCFILT_RESET                                         0
#define BB1_PWD_V2I_OVR_MSB                                          7
#define BB1_PWD_V2I_OVR_LSB                                          7
#define BB1_PWD_V2I_OVR_MASK                                         0x00000080
#define BB1_PWD_V2I_OVR_GET(x)                                       (((x) & BB1_PWD_V2I_OVR_MASK) >> BB1_PWD_V2I_OVR_LSB)
#define BB1_PWD_V2I_OVR_SET(x)                                       (((0 | (x)) << BB1_PWD_V2I_OVR_LSB) & BB1_PWD_V2I_OVR_MASK)
#define BB1_PWD_V2I_OVR_RESET                                        0
#define BB1_PWD_V2I_MSB                                              6
#define BB1_PWD_V2I_LSB                                              6
#define BB1_PWD_V2I_MASK                                             0x00000040
#define BB1_PWD_V2I_GET(x)                                           (((x) & BB1_PWD_V2I_MASK) >> BB1_PWD_V2I_LSB)
#define BB1_PWD_V2I_SET(x)                                           (((0 | (x)) << BB1_PWD_V2I_LSB) & BB1_PWD_V2I_MASK)
#define BB1_PWD_V2I_RESET                                            0
#define BB1_PWD_OSDAC_OVR_MSB                                        5
#define BB1_PWD_OSDAC_OVR_LSB                                        5
#define BB1_PWD_OSDAC_OVR_MASK                                       0x00000020
#define BB1_PWD_OSDAC_OVR_GET(x)                                     (((x) & BB1_PWD_OSDAC_OVR_MASK) >> BB1_PWD_OSDAC_OVR_LSB)
#define BB1_PWD_OSDAC_OVR_SET(x)                                     (((0 | (x)) << BB1_PWD_OSDAC_OVR_LSB) & BB1_PWD_OSDAC_OVR_MASK)
#define BB1_PWD_OSDAC_OVR_RESET                                      0
#define BB1_PWD_OSDAC_MSB                                            4
#define BB1_PWD_OSDAC_LSB                                            4
#define BB1_PWD_OSDAC_MASK                                           0x00000010
#define BB1_PWD_OSDAC_GET(x)                                         (((x) & BB1_PWD_OSDAC_MASK) >> BB1_PWD_OSDAC_LSB)
#define BB1_PWD_OSDAC_SET(x)                                         (((0 | (x)) << BB1_PWD_OSDAC_LSB) & BB1_PWD_OSDAC_MASK)
#define BB1_PWD_OSDAC_RESET                                          0
#define BB1_PWD_BIQUAD1_OVR_MSB                                      3
#define BB1_PWD_BIQUAD1_OVR_LSB                                      3
#define BB1_PWD_BIQUAD1_OVR_MASK                                     0x00000008
#define BB1_PWD_BIQUAD1_OVR_GET(x)                                   (((x) & BB1_PWD_BIQUAD1_OVR_MASK) >> BB1_PWD_BIQUAD1_OVR_LSB)
#define BB1_PWD_BIQUAD1_OVR_SET(x)                                   (((0 | (x)) << BB1_PWD_BIQUAD1_OVR_LSB) & BB1_PWD_BIQUAD1_OVR_MASK)
#define BB1_PWD_BIQUAD1_OVR_RESET                                    0
#define BB1_PWD_BIQUAD1_MSB                                          2
#define BB1_PWD_BIQUAD1_LSB                                          2
#define BB1_PWD_BIQUAD1_MASK                                         0x00000004
#define BB1_PWD_BIQUAD1_GET(x)                                       (((x) & BB1_PWD_BIQUAD1_MASK) >> BB1_PWD_BIQUAD1_LSB)
#define BB1_PWD_BIQUAD1_SET(x)                                       (((0 | (x)) << BB1_PWD_BIQUAD1_LSB) & BB1_PWD_BIQUAD1_MASK)
#define BB1_PWD_BIQUAD1_RESET                                        0
#define BB1_PWD_BIQUAD2_OVR_MSB                                      1
#define BB1_PWD_BIQUAD2_OVR_LSB                                      1
#define BB1_PWD_BIQUAD2_OVR_MASK                                     0x00000002
#define BB1_PWD_BIQUAD2_OVR_GET(x)                                   (((x) & BB1_PWD_BIQUAD2_OVR_MASK) >> BB1_PWD_BIQUAD2_OVR_LSB)
#define BB1_PWD_BIQUAD2_OVR_SET(x)                                   (((0 | (x)) << BB1_PWD_BIQUAD2_OVR_LSB) & BB1_PWD_BIQUAD2_OVR_MASK)
#define BB1_PWD_BIQUAD2_OVR_RESET                                    0
#define BB1_PWD_BIQUAD2_MSB                                          0
#define BB1_PWD_BIQUAD2_LSB                                          0
#define BB1_PWD_BIQUAD2_MASK                                         0x00000001
#define BB1_PWD_BIQUAD2_GET(x)                                       (((x) & BB1_PWD_BIQUAD2_MASK) >> BB1_PWD_BIQUAD2_LSB)
#define BB1_PWD_BIQUAD2_SET(x)                                       (((0 | (x)) << BB1_PWD_BIQUAD2_LSB) & BB1_PWD_BIQUAD2_MASK)
#define BB1_PWD_BIQUAD2_RESET                                        0
#define BB1_ADDRESS                                                  0x0000
#define BB1_HW_MASK                                                  0xffffffff
#define BB1_SW_MASK                                                  0xffffffff
#define BB1_HW_WRITE_MASK                                            0x00000000
#define BB1_SW_WRITE_MASK                                            0xffffffff
#define BB1_RSTMASK                                                  0xffffffff
#define BB1_RESET                                                    0x10804800

// 0x0004 (BB2)
#define BB2_SWITCH_OVERRIDE_MSB                                      31
#define BB2_SWITCH_OVERRIDE_LSB                                      31
#define BB2_SWITCH_OVERRIDE_MASK                                     0x80000000
#define BB2_SWITCH_OVERRIDE_GET(x)                                   (((x) & BB2_SWITCH_OVERRIDE_MASK) >> BB2_SWITCH_OVERRIDE_LSB)
#define BB2_SWITCH_OVERRIDE_SET(x)                                   (((0 | (x)) << BB2_SWITCH_OVERRIDE_LSB) & BB2_SWITCH_OVERRIDE_MASK)
#define BB2_SWITCH_OVERRIDE_RESET                                    0
#define BB2_RXIN2RC_EN_MSB                                           30
#define BB2_RXIN2RC_EN_LSB                                           30
#define BB2_RXIN2RC_EN_MASK                                          0x40000000
#define BB2_RXIN2RC_EN_GET(x)                                        (((x) & BB2_RXIN2RC_EN_MASK) >> BB2_RXIN2RC_EN_LSB)
#define BB2_RXIN2RC_EN_SET(x)                                        (((0 | (x)) << BB2_RXIN2RC_EN_LSB) & BB2_RXIN2RC_EN_MASK)
#define BB2_RXIN2RC_EN_RESET                                         0
#define BB2_RC2BQ1_EN_MSB                                            29
#define BB2_RC2BQ1_EN_LSB                                            29
#define BB2_RC2BQ1_EN_MASK                                           0x20000000
#define BB2_RC2BQ1_EN_GET(x)                                         (((x) & BB2_RC2BQ1_EN_MASK) >> BB2_RC2BQ1_EN_LSB)
#define BB2_RC2BQ1_EN_SET(x)                                         (((0 | (x)) << BB2_RC2BQ1_EN_LSB) & BB2_RC2BQ1_EN_MASK)
#define BB2_RC2BQ1_EN_RESET                                          0
#define BB2_RC2RXOUT_EN_MSB                                          28
#define BB2_RC2RXOUT_EN_LSB                                          28
#define BB2_RC2RXOUT_EN_MASK                                         0x10000000
#define BB2_RC2RXOUT_EN_GET(x)                                       (((x) & BB2_RC2RXOUT_EN_MASK) >> BB2_RC2RXOUT_EN_LSB)
#define BB2_RC2RXOUT_EN_SET(x)                                       (((0 | (x)) << BB2_RC2RXOUT_EN_LSB) & BB2_RC2RXOUT_EN_MASK)
#define BB2_RC2RXOUT_EN_RESET                                        0
#define BB2_BQ2RXOUT_EN_MSB                                          27
#define BB2_BQ2RXOUT_EN_LSB                                          27
#define BB2_BQ2RXOUT_EN_MASK                                         0x08000000
#define BB2_BQ2RXOUT_EN_GET(x)                                       (((x) & BB2_BQ2RXOUT_EN_MASK) >> BB2_BQ2RXOUT_EN_LSB)
#define BB2_BQ2RXOUT_EN_SET(x)                                       (((0 | (x)) << BB2_BQ2RXOUT_EN_LSB) & BB2_BQ2RXOUT_EN_MASK)
#define BB2_BQ2RXOUT_EN_RESET                                        0
#define BB2_NOTCHON_MSB                                              26
#define BB2_NOTCHON_LSB                                              26
#define BB2_NOTCHON_MASK                                             0x04000000
#define BB2_NOTCHON_GET(x)                                           (((x) & BB2_NOTCHON_MASK) >> BB2_NOTCHON_LSB)
#define BB2_NOTCHON_SET(x)                                           (((0 | (x)) << BB2_NOTCHON_LSB) & BB2_NOTCHON_MASK)
#define BB2_NOTCHON_RESET                                            0
#define BB2_BYPASSBQ1_EN_MSB                                         25
#define BB2_BYPASSBQ1_EN_LSB                                         25
#define BB2_BYPASSBQ1_EN_MASK                                        0x02000000
#define BB2_BYPASSBQ1_EN_GET(x)                                      (((x) & BB2_BYPASSBQ1_EN_MASK) >> BB2_BYPASSBQ1_EN_LSB)
#define BB2_BYPASSBQ1_EN_SET(x)                                      (((0 | (x)) << BB2_BYPASSBQ1_EN_LSB) & BB2_BYPASSBQ1_EN_MASK)
#define BB2_BYPASSBQ1_EN_RESET                                       0
#define BB2_BQ2V2I_EN_MSB                                            24
#define BB2_BQ2V2I_EN_LSB                                            24
#define BB2_BQ2V2I_EN_MASK                                           0x01000000
#define BB2_BQ2V2I_EN_GET(x)                                         (((x) & BB2_BQ2V2I_EN_MASK) >> BB2_BQ2V2I_EN_LSB)
#define BB2_BQ2V2I_EN_SET(x)                                         (((0 | (x)) << BB2_BQ2V2I_EN_LSB) & BB2_BQ2V2I_EN_MASK)
#define BB2_BQ2V2I_EN_RESET                                          0
#define BB2_DAC2V2I_EN_MSB                                           23
#define BB2_DAC2V2I_EN_LSB                                           23
#define BB2_DAC2V2I_EN_MASK                                          0x00800000
#define BB2_DAC2V2I_EN_GET(x)                                        (((x) & BB2_DAC2V2I_EN_MASK) >> BB2_DAC2V2I_EN_LSB)
#define BB2_DAC2V2I_EN_SET(x)                                        (((0 | (x)) << BB2_DAC2V2I_EN_LSB) & BB2_DAC2V2I_EN_MASK)
#define BB2_DAC2V2I_EN_RESET                                         0
#define BB2_FILTERFC_OVR_MSB                                         22
#define BB2_FILTERFC_OVR_LSB                                         22
#define BB2_FILTERFC_OVR_MASK                                        0x00400000
#define BB2_FILTERFC_OVR_GET(x)                                      (((x) & BB2_FILTERFC_OVR_MASK) >> BB2_FILTERFC_OVR_LSB)
#define BB2_FILTERFC_OVR_SET(x)                                      (((0 | (x)) << BB2_FILTERFC_OVR_LSB) & BB2_FILTERFC_OVR_MASK)
#define BB2_FILTERFC_OVR_RESET                                       0
#define BB2_FILTERFC_MSB                                             21
#define BB2_FILTERFC_LSB                                             17
#define BB2_FILTERFC_MASK                                            0x003e0000
#define BB2_FILTERFC_GET(x)                                          (((x) & BB2_FILTERFC_MASK) >> BB2_FILTERFC_LSB)
#define BB2_FILTERFC_SET(x)                                          (((0 | (x)) << BB2_FILTERFC_LSB) & BB2_FILTERFC_MASK)
#define BB2_FILTERFC_RESET                                           16
#define BB2_FNOTCH_OVR_MSB                                           16
#define BB2_FNOTCH_OVR_LSB                                           16
#define BB2_FNOTCH_OVR_MASK                                          0x00010000
#define BB2_FNOTCH_OVR_GET(x)                                        (((x) & BB2_FNOTCH_OVR_MASK) >> BB2_FNOTCH_OVR_LSB)
#define BB2_FNOTCH_OVR_SET(x)                                        (((0 | (x)) << BB2_FNOTCH_OVR_LSB) & BB2_FNOTCH_OVR_MASK)
#define BB2_FNOTCH_OVR_RESET                                         0
#define BB2_FNOTCH_MSB                                               15
#define BB2_FNOTCH_LSB                                               12
#define BB2_FNOTCH_MASK                                              0x0000f000
#define BB2_FNOTCH_GET(x)                                            (((x) & BB2_FNOTCH_MASK) >> BB2_FNOTCH_LSB)
#define BB2_FNOTCH_SET(x)                                            (((0 | (x)) << BB2_FNOTCH_LSB) & BB2_FNOTCH_MASK)
#define BB2_FNOTCH_RESET                                             8
#define BB2_REMOVECAP_RCFILT_OVR_MSB                                 11
#define BB2_REMOVECAP_RCFILT_OVR_LSB                                 11
#define BB2_REMOVECAP_RCFILT_OVR_MASK                                0x00000800
#define BB2_REMOVECAP_RCFILT_OVR_GET(x)                              (((x) & BB2_REMOVECAP_RCFILT_OVR_MASK) >> BB2_REMOVECAP_RCFILT_OVR_LSB)
#define BB2_REMOVECAP_RCFILT_OVR_SET(x)                              (((0 | (x)) << BB2_REMOVECAP_RCFILT_OVR_LSB) & BB2_REMOVECAP_RCFILT_OVR_MASK)
#define BB2_REMOVECAP_RCFILT_OVR_RESET                               0
#define BB2_REMOVECAP_RCFILT_MSB                                     10
#define BB2_REMOVECAP_RCFILT_LSB                                     10
#define BB2_REMOVECAP_RCFILT_MASK                                    0x00000400
#define BB2_REMOVECAP_RCFILT_GET(x)                                  (((x) & BB2_REMOVECAP_RCFILT_MASK) >> BB2_REMOVECAP_RCFILT_LSB)
#define BB2_REMOVECAP_RCFILT_SET(x)                                  (((0 | (x)) << BB2_REMOVECAP_RCFILT_LSB) & BB2_REMOVECAP_RCFILT_MASK)
#define BB2_REMOVECAP_RCFILT_RESET                                   0
#define BB2_SEL_TEST_MSB                                             9
#define BB2_SEL_TEST_LSB                                             0
#define BB2_SEL_TEST_MASK                                            0x000003ff
#define BB2_SEL_TEST_GET(x)                                          (((x) & BB2_SEL_TEST_MASK) >> BB2_SEL_TEST_LSB)
#define BB2_SEL_TEST_SET(x)                                          (((0 | (x)) << BB2_SEL_TEST_LSB) & BB2_SEL_TEST_MASK)
#define BB2_SEL_TEST_RESET                                           0
#define BB2_ADDRESS                                                  0x0004
#define BB2_HW_MASK                                                  0xffffffff
#define BB2_SW_MASK                                                  0xffffffff
#define BB2_HW_WRITE_MASK                                            0x00000000
#define BB2_SW_WRITE_MASK                                            0xffffffff
#define BB2_RSTMASK                                                  0xffffffff
#define BB2_RESET                                                    0x00208000

// 0x0008 (BB3)
#define BB3_TXBBCONSTCUR_EN_MSB                                      31
#define BB3_TXBBCONSTCUR_EN_LSB                                      31
#define BB3_TXBBCONSTCUR_EN_MASK                                     0x80000000
#define BB3_TXBBCONSTCUR_EN_GET(x)                                   (((x) & BB3_TXBBCONSTCUR_EN_MASK) >> BB3_TXBBCONSTCUR_EN_LSB)
#define BB3_TXBBCONSTCUR_EN_SET(x)                                   (((0 | (x)) << BB3_TXBBCONSTCUR_EN_LSB) & BB3_TXBBCONSTCUR_EN_MASK)
#define BB3_TXBBCONSTCUR_EN_RESET                                    0
#define BB3_OFSTCORRI2VI_MSB                                         30
#define BB3_OFSTCORRI2VI_LSB                                         26
#define BB3_OFSTCORRI2VI_MASK                                        0x7c000000
#define BB3_OFSTCORRI2VI_GET(x)                                      (((x) & BB3_OFSTCORRI2VI_MASK) >> BB3_OFSTCORRI2VI_LSB)
#define BB3_OFSTCORRI2VI_SET(x)                                      (((0 | (x)) << BB3_OFSTCORRI2VI_LSB) & BB3_OFSTCORRI2VI_MASK)
#define BB3_OFSTCORRI2VI_RESET                                       0
#define BB3_OFSTCORRI2VQ_MSB                                         25
#define BB3_OFSTCORRI2VQ_LSB                                         21
#define BB3_OFSTCORRI2VQ_MASK                                        0x03e00000
#define BB3_OFSTCORRI2VQ_GET(x)                                      (((x) & BB3_OFSTCORRI2VQ_MASK) >> BB3_OFSTCORRI2VQ_LSB)
#define BB3_OFSTCORRI2VQ_SET(x)                                      (((0 | (x)) << BB3_OFSTCORRI2VQ_LSB) & BB3_OFSTCORRI2VQ_MASK)
#define BB3_OFSTCORRI2VQ_RESET                                       0
#define BB3_FILTERFC_MSB                                             20
#define BB3_FILTERFC_LSB                                             16
#define BB3_FILTERFC_MASK                                            0x001f0000
#define BB3_FILTERFC_GET(x)                                          (((x) & BB3_FILTERFC_MASK) >> BB3_FILTERFC_LSB)
#define BB3_FILTERFC_SET(x)                                          (((0 | (x)) << BB3_FILTERFC_LSB) & BB3_FILTERFC_MASK)
#define BB3_FILTERFC_RESET                                           0
#define BB3_RX_FILTERFC_MSB                                          15
#define BB3_RX_FILTERFC_LSB                                          11
#define BB3_RX_FILTERFC_MASK                                         0x0000f800
#define BB3_RX_FILTERFC_GET(x)                                       (((x) & BB3_RX_FILTERFC_MASK) >> BB3_RX_FILTERFC_LSB)
#define BB3_RX_FILTERFC_SET(x)                                       (((0 | (x)) << BB3_RX_FILTERFC_LSB) & BB3_RX_FILTERFC_MASK)
#define BB3_RX_FILTERFC_RESET                                        16
#define BB3_TX_FILTERFC_MSB                                          10
#define BB3_TX_FILTERFC_LSB                                          6
#define BB3_TX_FILTERFC_MASK                                         0x000007c0
#define BB3_TX_FILTERFC_GET(x)                                       (((x) & BB3_TX_FILTERFC_MASK) >> BB3_TX_FILTERFC_LSB)
#define BB3_TX_FILTERFC_SET(x)                                       (((0 | (x)) << BB3_TX_FILTERFC_LSB) & BB3_TX_FILTERFC_MASK)
#define BB3_TX_FILTERFC_RESET                                        16
#define BB3_SEL_OFST_READBK_MSB                                      5
#define BB3_SEL_OFST_READBK_LSB                                      4
#define BB3_SEL_OFST_READBK_MASK                                     0x00000030
#define BB3_SEL_OFST_READBK_GET(x)                                   (((x) & BB3_SEL_OFST_READBK_MASK) >> BB3_SEL_OFST_READBK_LSB)
#define BB3_SEL_OFST_READBK_SET(x)                                   (((0 | (x)) << BB3_SEL_OFST_READBK_LSB) & BB3_SEL_OFST_READBK_MASK)
#define BB3_SEL_OFST_READBK_RESET                                    0
#define BB3_ADC_COMPBIAS_MSB                                         3
#define BB3_ADC_COMPBIAS_LSB                                         2
#define BB3_ADC_COMPBIAS_MASK                                        0x0000000c
#define BB3_ADC_COMPBIAS_GET(x)                                      (((x) & BB3_ADC_COMPBIAS_MASK) >> BB3_ADC_COMPBIAS_LSB)
#define BB3_ADC_COMPBIAS_SET(x)                                      (((0 | (x)) << BB3_ADC_COMPBIAS_LSB) & BB3_ADC_COMPBIAS_MASK)
#define BB3_ADC_COMPBIAS_RESET                                       3
#define BB3_DOUBLE_RCFILT_CURR_MSB                                   1
#define BB3_DOUBLE_RCFILT_CURR_LSB                                   1
#define BB3_DOUBLE_RCFILT_CURR_MASK                                  0x00000002
#define BB3_DOUBLE_RCFILT_CURR_GET(x)                                (((x) & BB3_DOUBLE_RCFILT_CURR_MASK) >> BB3_DOUBLE_RCFILT_CURR_LSB)
#define BB3_DOUBLE_RCFILT_CURR_SET(x)                                (((0 | (x)) << BB3_DOUBLE_RCFILT_CURR_LSB) & BB3_DOUBLE_RCFILT_CURR_MASK)
#define BB3_DOUBLE_RCFILT_CURR_RESET                                 0
#define BB3_RESERVED_MSB                                             0
#define BB3_RESERVED_LSB                                             0
#define BB3_RESERVED_MASK                                            0x00000001
#define BB3_RESERVED_GET(x)                                          (((x) & BB3_RESERVED_MASK) >> BB3_RESERVED_LSB)
#define BB3_RESERVED_SET(x)                                          (((0 | (x)) << BB3_RESERVED_LSB) & BB3_RESERVED_MASK)
#define BB3_RESERVED_RESET                                           0
#define BB3_ADDRESS                                                  0x0008
#define BB3_HW_MASK                                                  0xffffffff
#define BB3_SW_MASK                                                  0xffffffff
#define BB3_HW_WRITE_MASK                                            0x7fff0000
#define BB3_SW_WRITE_MASK                                            0x8000ffff
#define BB3_RSTMASK                                                  0xffffffff
#define BB3_RESET                                                    0x0000840c

// 0x000c (BB4)
#define BB4_RX_RXIN2RC_EN_MSB                                        31
#define BB4_RX_RXIN2RC_EN_LSB                                        31
#define BB4_RX_RXIN2RC_EN_MASK                                       0x80000000
#define BB4_RX_RXIN2RC_EN_GET(x)                                     (((x) & BB4_RX_RXIN2RC_EN_MASK) >> BB4_RX_RXIN2RC_EN_LSB)
#define BB4_RX_RXIN2RC_EN_SET(x)                                     (((0 | (x)) << BB4_RX_RXIN2RC_EN_LSB) & BB4_RX_RXIN2RC_EN_MASK)
#define BB4_RX_RXIN2RC_EN_RESET                                      1
#define BB4_RX_RC2BQ1_EN_MSB                                         30
#define BB4_RX_RC2BQ1_EN_LSB                                         30
#define BB4_RX_RC2BQ1_EN_MASK                                        0x40000000
#define BB4_RX_RC2BQ1_EN_GET(x)                                      (((x) & BB4_RX_RC2BQ1_EN_MASK) >> BB4_RX_RC2BQ1_EN_LSB)
#define BB4_RX_RC2BQ1_EN_SET(x)                                      (((0 | (x)) << BB4_RX_RC2BQ1_EN_LSB) & BB4_RX_RC2BQ1_EN_MASK)
#define BB4_RX_RC2BQ1_EN_RESET                                       1
#define BB4_RX_RC2RXOUT_EN_MSB                                       29
#define BB4_RX_RC2RXOUT_EN_LSB                                       29
#define BB4_RX_RC2RXOUT_EN_MASK                                      0x20000000
#define BB4_RX_RC2RXOUT_EN_GET(x)                                    (((x) & BB4_RX_RC2RXOUT_EN_MASK) >> BB4_RX_RC2RXOUT_EN_LSB)
#define BB4_RX_RC2RXOUT_EN_SET(x)                                    (((0 | (x)) << BB4_RX_RC2RXOUT_EN_LSB) & BB4_RX_RC2RXOUT_EN_MASK)
#define BB4_RX_RC2RXOUT_EN_RESET                                     0
#define BB4_RX_BQ2RXOUT_EN_MSB                                       28
#define BB4_RX_BQ2RXOUT_EN_LSB                                       28
#define BB4_RX_BQ2RXOUT_EN_MASK                                      0x10000000
#define BB4_RX_BQ2RXOUT_EN_GET(x)                                    (((x) & BB4_RX_BQ2RXOUT_EN_MASK) >> BB4_RX_BQ2RXOUT_EN_LSB)
#define BB4_RX_BQ2RXOUT_EN_SET(x)                                    (((0 | (x)) << BB4_RX_BQ2RXOUT_EN_LSB) & BB4_RX_BQ2RXOUT_EN_MASK)
#define BB4_RX_BQ2RXOUT_EN_RESET                                     1
#define BB4_RX_NOTCHON_MSB                                           27
#define BB4_RX_NOTCHON_LSB                                           27
#define BB4_RX_NOTCHON_MASK                                          0x08000000
#define BB4_RX_NOTCHON_GET(x)                                        (((x) & BB4_RX_NOTCHON_MASK) >> BB4_RX_NOTCHON_LSB)
#define BB4_RX_NOTCHON_SET(x)                                        (((0 | (x)) << BB4_RX_NOTCHON_LSB) & BB4_RX_NOTCHON_MASK)
#define BB4_RX_NOTCHON_RESET                                         0
#define BB4_RX_BYPASSBQ1_EN_MSB                                      26
#define BB4_RX_BYPASSBQ1_EN_LSB                                      26
#define BB4_RX_BYPASSBQ1_EN_MASK                                     0x04000000
#define BB4_RX_BYPASSBQ1_EN_GET(x)                                   (((x) & BB4_RX_BYPASSBQ1_EN_MASK) >> BB4_RX_BYPASSBQ1_EN_LSB)
#define BB4_RX_BYPASSBQ1_EN_SET(x)                                   (((0 | (x)) << BB4_RX_BYPASSBQ1_EN_LSB) & BB4_RX_BYPASSBQ1_EN_MASK)
#define BB4_RX_BYPASSBQ1_EN_RESET                                    0
#define BB4_RX_BQ2V2I_EN_MSB                                         25
#define BB4_RX_BQ2V2I_EN_LSB                                         25
#define BB4_RX_BQ2V2I_EN_MASK                                        0x02000000
#define BB4_RX_BQ2V2I_EN_GET(x)                                      (((x) & BB4_RX_BQ2V2I_EN_MASK) >> BB4_RX_BQ2V2I_EN_LSB)
#define BB4_RX_BQ2V2I_EN_SET(x)                                      (((0 | (x)) << BB4_RX_BQ2V2I_EN_LSB) & BB4_RX_BQ2V2I_EN_MASK)
#define BB4_RX_BQ2V2I_EN_RESET                                       0
#define BB4_RX_DAC2V2I_EN_MSB                                        24
#define BB4_RX_DAC2V2I_EN_LSB                                        24
#define BB4_RX_DAC2V2I_EN_MASK                                       0x01000000
#define BB4_RX_DAC2V2I_EN_GET(x)                                     (((x) & BB4_RX_DAC2V2I_EN_MASK) >> BB4_RX_DAC2V2I_EN_LSB)
#define BB4_RX_DAC2V2I_EN_SET(x)                                     (((0 | (x)) << BB4_RX_DAC2V2I_EN_LSB) & BB4_RX_DAC2V2I_EN_MASK)
#define BB4_RX_DAC2V2I_EN_RESET                                      0
#define BB4_RX_PWD_RCFILT_MSB                                        23
#define BB4_RX_PWD_RCFILT_LSB                                        23
#define BB4_RX_PWD_RCFILT_MASK                                       0x00800000
#define BB4_RX_PWD_RCFILT_GET(x)                                     (((x) & BB4_RX_PWD_RCFILT_MASK) >> BB4_RX_PWD_RCFILT_LSB)
#define BB4_RX_PWD_RCFILT_SET(x)                                     (((0 | (x)) << BB4_RX_PWD_RCFILT_LSB) & BB4_RX_PWD_RCFILT_MASK)
#define BB4_RX_PWD_RCFILT_RESET                                      0
#define BB4_RX_PWD_V2I_MSB                                           22
#define BB4_RX_PWD_V2I_LSB                                           22
#define BB4_RX_PWD_V2I_MASK                                          0x00400000
#define BB4_RX_PWD_V2I_GET(x)                                        (((x) & BB4_RX_PWD_V2I_MASK) >> BB4_RX_PWD_V2I_LSB)
#define BB4_RX_PWD_V2I_SET(x)                                        (((0 | (x)) << BB4_RX_PWD_V2I_LSB) & BB4_RX_PWD_V2I_MASK)
#define BB4_RX_PWD_V2I_RESET                                         1
#define BB4_RX_PWD_BIQUAD1_MSB                                       21
#define BB4_RX_PWD_BIQUAD1_LSB                                       21
#define BB4_RX_PWD_BIQUAD1_MASK                                      0x00200000
#define BB4_RX_PWD_BIQUAD1_GET(x)                                    (((x) & BB4_RX_PWD_BIQUAD1_MASK) >> BB4_RX_PWD_BIQUAD1_LSB)
#define BB4_RX_PWD_BIQUAD1_SET(x)                                    (((0 | (x)) << BB4_RX_PWD_BIQUAD1_LSB) & BB4_RX_PWD_BIQUAD1_MASK)
#define BB4_RX_PWD_BIQUAD1_RESET                                     0
#define BB4_RX_PWD_BIQUAD2_MSB                                       20
#define BB4_RX_PWD_BIQUAD2_LSB                                       20
#define BB4_RX_PWD_BIQUAD2_MASK                                      0x00100000
#define BB4_RX_PWD_BIQUAD2_GET(x)                                    (((x) & BB4_RX_PWD_BIQUAD2_MASK) >> BB4_RX_PWD_BIQUAD2_LSB)
#define BB4_RX_PWD_BIQUAD2_SET(x)                                    (((0 | (x)) << BB4_RX_PWD_BIQUAD2_LSB) & BB4_RX_PWD_BIQUAD2_MASK)
#define BB4_RX_PWD_BIQUAD2_RESET                                     0
#define BB4_RX_REMOVECAP_RCFILT_MSB                                  19
#define BB4_RX_REMOVECAP_RCFILT_LSB                                  19
#define BB4_RX_REMOVECAP_RCFILT_MASK                                 0x00080000
#define BB4_RX_REMOVECAP_RCFILT_GET(x)                               (((x) & BB4_RX_REMOVECAP_RCFILT_MASK) >> BB4_RX_REMOVECAP_RCFILT_LSB)
#define BB4_RX_REMOVECAP_RCFILT_SET(x)                               (((0 | (x)) << BB4_RX_REMOVECAP_RCFILT_LSB) & BB4_RX_REMOVECAP_RCFILT_MASK)
#define BB4_RX_REMOVECAP_RCFILT_RESET                                0
#define BB4_RX_NOTCH_HALFBW_MSB                                      18
#define BB4_RX_NOTCH_HALFBW_LSB                                      18
#define BB4_RX_NOTCH_HALFBW_MASK                                     0x00040000
#define BB4_RX_NOTCH_HALFBW_GET(x)                                   (((x) & BB4_RX_NOTCH_HALFBW_MASK) >> BB4_RX_NOTCH_HALFBW_LSB)
#define BB4_RX_NOTCH_HALFBW_SET(x)                                   (((0 | (x)) << BB4_RX_NOTCH_HALFBW_LSB) & BB4_RX_NOTCH_HALFBW_MASK)
#define BB4_RX_NOTCH_HALFBW_RESET                                    0
#define BB4_TX_RXIN2RC_EN_MSB                                        17
#define BB4_TX_RXIN2RC_EN_LSB                                        17
#define BB4_TX_RXIN2RC_EN_MASK                                       0x00020000
#define BB4_TX_RXIN2RC_EN_GET(x)                                     (((x) & BB4_TX_RXIN2RC_EN_MASK) >> BB4_TX_RXIN2RC_EN_LSB)
#define BB4_TX_RXIN2RC_EN_SET(x)                                     (((0 | (x)) << BB4_TX_RXIN2RC_EN_LSB) & BB4_TX_RXIN2RC_EN_MASK)
#define BB4_TX_RXIN2RC_EN_RESET                                      0
#define BB4_TX_RC2BQ1_EN_MSB                                         16
#define BB4_TX_RC2BQ1_EN_LSB                                         16
#define BB4_TX_RC2BQ1_EN_MASK                                        0x00010000
#define BB4_TX_RC2BQ1_EN_GET(x)                                      (((x) & BB4_TX_RC2BQ1_EN_MASK) >> BB4_TX_RC2BQ1_EN_LSB)
#define BB4_TX_RC2BQ1_EN_SET(x)                                      (((0 | (x)) << BB4_TX_RC2BQ1_EN_LSB) & BB4_TX_RC2BQ1_EN_MASK)
#define BB4_TX_RC2BQ1_EN_RESET                                       0
#define BB4_TX_RC2RXOUT_EN_MSB                                       15
#define BB4_TX_RC2RXOUT_EN_LSB                                       15
#define BB4_TX_RC2RXOUT_EN_MASK                                      0x00008000
#define BB4_TX_RC2RXOUT_EN_GET(x)                                    (((x) & BB4_TX_RC2RXOUT_EN_MASK) >> BB4_TX_RC2RXOUT_EN_LSB)
#define BB4_TX_RC2RXOUT_EN_SET(x)                                    (((0 | (x)) << BB4_TX_RC2RXOUT_EN_LSB) & BB4_TX_RC2RXOUT_EN_MASK)
#define BB4_TX_RC2RXOUT_EN_RESET                                     0
#define BB4_TX_BQ2RXOUT_EN_MSB                                       14
#define BB4_TX_BQ2RXOUT_EN_LSB                                       14
#define BB4_TX_BQ2RXOUT_EN_MASK                                      0x00004000
#define BB4_TX_BQ2RXOUT_EN_GET(x)                                    (((x) & BB4_TX_BQ2RXOUT_EN_MASK) >> BB4_TX_BQ2RXOUT_EN_LSB)
#define BB4_TX_BQ2RXOUT_EN_SET(x)                                    (((0 | (x)) << BB4_TX_BQ2RXOUT_EN_LSB) & BB4_TX_BQ2RXOUT_EN_MASK)
#define BB4_TX_BQ2RXOUT_EN_RESET                                     0
#define BB4_TX_NOTCHON_MSB                                           13
#define BB4_TX_NOTCHON_LSB                                           13
#define BB4_TX_NOTCHON_MASK                                          0x00002000
#define BB4_TX_NOTCHON_GET(x)                                        (((x) & BB4_TX_NOTCHON_MASK) >> BB4_TX_NOTCHON_LSB)
#define BB4_TX_NOTCHON_SET(x)                                        (((0 | (x)) << BB4_TX_NOTCHON_LSB) & BB4_TX_NOTCHON_MASK)
#define BB4_TX_NOTCHON_RESET                                         1
#define BB4_TX_BYPASSBQ1_EN_MSB                                      12
#define BB4_TX_BYPASSBQ1_EN_LSB                                      12
#define BB4_TX_BYPASSBQ1_EN_MASK                                     0x00001000
#define BB4_TX_BYPASSBQ1_EN_GET(x)                                   (((x) & BB4_TX_BYPASSBQ1_EN_MASK) >> BB4_TX_BYPASSBQ1_EN_LSB)
#define BB4_TX_BYPASSBQ1_EN_SET(x)                                   (((0 | (x)) << BB4_TX_BYPASSBQ1_EN_LSB) & BB4_TX_BYPASSBQ1_EN_MASK)
#define BB4_TX_BYPASSBQ1_EN_RESET                                    0
#define BB4_TX_BQ2V2I_EN_MSB                                         11
#define BB4_TX_BQ2V2I_EN_LSB                                         11
#define BB4_TX_BQ2V2I_EN_MASK                                        0x00000800
#define BB4_TX_BQ2V2I_EN_GET(x)                                      (((x) & BB4_TX_BQ2V2I_EN_MASK) >> BB4_TX_BQ2V2I_EN_LSB)
#define BB4_TX_BQ2V2I_EN_SET(x)                                      (((0 | (x)) << BB4_TX_BQ2V2I_EN_LSB) & BB4_TX_BQ2V2I_EN_MASK)
#define BB4_TX_BQ2V2I_EN_RESET                                       1
#define BB4_TX_DAC2V2I_EN_MSB                                        10
#define BB4_TX_DAC2V2I_EN_LSB                                        10
#define BB4_TX_DAC2V2I_EN_MASK                                       0x00000400
#define BB4_TX_DAC2V2I_EN_GET(x)                                     (((x) & BB4_TX_DAC2V2I_EN_MASK) >> BB4_TX_DAC2V2I_EN_LSB)
#define BB4_TX_DAC2V2I_EN_SET(x)                                     (((0 | (x)) << BB4_TX_DAC2V2I_EN_LSB) & BB4_TX_DAC2V2I_EN_MASK)
#define BB4_TX_DAC2V2I_EN_RESET                                      0
#define BB4_TX_PWD_RCFILT_MSB                                        9
#define BB4_TX_PWD_RCFILT_LSB                                        9
#define BB4_TX_PWD_RCFILT_MASK                                       0x00000200
#define BB4_TX_PWD_RCFILT_GET(x)                                     (((x) & BB4_TX_PWD_RCFILT_MASK) >> BB4_TX_PWD_RCFILT_LSB)
#define BB4_TX_PWD_RCFILT_SET(x)                                     (((0 | (x)) << BB4_TX_PWD_RCFILT_LSB) & BB4_TX_PWD_RCFILT_MASK)
#define BB4_TX_PWD_RCFILT_RESET                                      1
#define BB4_TX_PWD_V2I_MSB                                           8
#define BB4_TX_PWD_V2I_LSB                                           8
#define BB4_TX_PWD_V2I_MASK                                          0x00000100
#define BB4_TX_PWD_V2I_GET(x)                                        (((x) & BB4_TX_PWD_V2I_MASK) >> BB4_TX_PWD_V2I_LSB)
#define BB4_TX_PWD_V2I_SET(x)                                        (((0 | (x)) << BB4_TX_PWD_V2I_LSB) & BB4_TX_PWD_V2I_MASK)
#define BB4_TX_PWD_V2I_RESET                                         0
#define BB4_TX_PWD_BIQUAD1_MSB                                       7
#define BB4_TX_PWD_BIQUAD1_LSB                                       7
#define BB4_TX_PWD_BIQUAD1_MASK                                      0x00000080
#define BB4_TX_PWD_BIQUAD1_GET(x)                                    (((x) & BB4_TX_PWD_BIQUAD1_MASK) >> BB4_TX_PWD_BIQUAD1_LSB)
#define BB4_TX_PWD_BIQUAD1_SET(x)                                    (((0 | (x)) << BB4_TX_PWD_BIQUAD1_LSB) & BB4_TX_PWD_BIQUAD1_MASK)
#define BB4_TX_PWD_BIQUAD1_RESET                                     0
#define BB4_TX_PWD_BIQUAD2_MSB                                       6
#define BB4_TX_PWD_BIQUAD2_LSB                                       6
#define BB4_TX_PWD_BIQUAD2_MASK                                      0x00000040
#define BB4_TX_PWD_BIQUAD2_GET(x)                                    (((x) & BB4_TX_PWD_BIQUAD2_MASK) >> BB4_TX_PWD_BIQUAD2_LSB)
#define BB4_TX_PWD_BIQUAD2_SET(x)                                    (((0 | (x)) << BB4_TX_PWD_BIQUAD2_LSB) & BB4_TX_PWD_BIQUAD2_MASK)
#define BB4_TX_PWD_BIQUAD2_RESET                                     0
#define BB4_TX_REMOVECAP_RCFILT_MSB                                  5
#define BB4_TX_REMOVECAP_RCFILT_LSB                                  5
#define BB4_TX_REMOVECAP_RCFILT_MASK                                 0x00000020
#define BB4_TX_REMOVECAP_RCFILT_GET(x)                               (((x) & BB4_TX_REMOVECAP_RCFILT_MASK) >> BB4_TX_REMOVECAP_RCFILT_LSB)
#define BB4_TX_REMOVECAP_RCFILT_SET(x)                               (((0 | (x)) << BB4_TX_REMOVECAP_RCFILT_LSB) & BB4_TX_REMOVECAP_RCFILT_MASK)
#define BB4_TX_REMOVECAP_RCFILT_RESET                                0
#define BB4_TX_NOTCH_HALFBW_MSB                                      4
#define BB4_TX_NOTCH_HALFBW_LSB                                      4
#define BB4_TX_NOTCH_HALFBW_MASK                                     0x00000010
#define BB4_TX_NOTCH_HALFBW_GET(x)                                   (((x) & BB4_TX_NOTCH_HALFBW_MASK) >> BB4_TX_NOTCH_HALFBW_LSB)
#define BB4_TX_NOTCH_HALFBW_SET(x)                                   (((0 | (x)) << BB4_TX_NOTCH_HALFBW_LSB) & BB4_TX_NOTCH_HALFBW_MASK)
#define BB4_TX_NOTCH_HALFBW_RESET                                    0
#define BB4_ADC_DEC_DELAYBIAS_MSB                                    3
#define BB4_ADC_DEC_DELAYBIAS_LSB                                    2
#define BB4_ADC_DEC_DELAYBIAS_MASK                                   0x0000000c
#define BB4_ADC_DEC_DELAYBIAS_GET(x)                                 (((x) & BB4_ADC_DEC_DELAYBIAS_MASK) >> BB4_ADC_DEC_DELAYBIAS_LSB)
#define BB4_ADC_DEC_DELAYBIAS_SET(x)                                 (((0 | (x)) << BB4_ADC_DEC_DELAYBIAS_LSB) & BB4_ADC_DEC_DELAYBIAS_MASK)
#define BB4_ADC_DEC_DELAYBIAS_RESET                                  3
#define BB4_ADC_INC_DELAYBIAS_MSB                                    1
#define BB4_ADC_INC_DELAYBIAS_LSB                                    1
#define BB4_ADC_INC_DELAYBIAS_MASK                                   0x00000002
#define BB4_ADC_INC_DELAYBIAS_GET(x)                                 (((x) & BB4_ADC_INC_DELAYBIAS_MASK) >> BB4_ADC_INC_DELAYBIAS_LSB)
#define BB4_ADC_INC_DELAYBIAS_SET(x)                                 (((0 | (x)) << BB4_ADC_INC_DELAYBIAS_LSB) & BB4_ADC_INC_DELAYBIAS_MASK)
#define BB4_ADC_INC_DELAYBIAS_RESET                                  0
#define BB4_ADC_COMP_RESET_MSB                                       0
#define BB4_ADC_COMP_RESET_LSB                                       0
#define BB4_ADC_COMP_RESET_MASK                                      0x00000001
#define BB4_ADC_COMP_RESET_GET(x)                                    (((x) & BB4_ADC_COMP_RESET_MASK) >> BB4_ADC_COMP_RESET_LSB)
#define BB4_ADC_COMP_RESET_SET(x)                                    (((0 | (x)) << BB4_ADC_COMP_RESET_LSB) & BB4_ADC_COMP_RESET_MASK)
#define BB4_ADC_COMP_RESET_RESET                                     0
#define BB4_ADDRESS                                                  0x000c
#define BB4_HW_MASK                                                  0xffffffff
#define BB4_SW_MASK                                                  0xffffffff
#define BB4_HW_WRITE_MASK                                            0x00000000
#define BB4_SW_WRITE_MASK                                            0xffffffff
#define BB4_RSTMASK                                                  0xffffffff
#define BB4_RESET                                                    0xd0402a0c

// 0x0010 (BB5)
#define BB5_CALRX_RXIN2RC_EN_MSB                                     31
#define BB5_CALRX_RXIN2RC_EN_LSB                                     31
#define BB5_CALRX_RXIN2RC_EN_MASK                                    0x80000000
#define BB5_CALRX_RXIN2RC_EN_GET(x)                                  (((x) & BB5_CALRX_RXIN2RC_EN_MASK) >> BB5_CALRX_RXIN2RC_EN_LSB)
#define BB5_CALRX_RXIN2RC_EN_SET(x)                                  (((0 | (x)) << BB5_CALRX_RXIN2RC_EN_LSB) & BB5_CALRX_RXIN2RC_EN_MASK)
#define BB5_CALRX_RXIN2RC_EN_RESET                                   1
#define BB5_CALRX_RC2BQ1_EN_MSB                                      30
#define BB5_CALRX_RC2BQ1_EN_LSB                                      30
#define BB5_CALRX_RC2BQ1_EN_MASK                                     0x40000000
#define BB5_CALRX_RC2BQ1_EN_GET(x)                                   (((x) & BB5_CALRX_RC2BQ1_EN_MASK) >> BB5_CALRX_RC2BQ1_EN_LSB)
#define BB5_CALRX_RC2BQ1_EN_SET(x)                                   (((0 | (x)) << BB5_CALRX_RC2BQ1_EN_LSB) & BB5_CALRX_RC2BQ1_EN_MASK)
#define BB5_CALRX_RC2BQ1_EN_RESET                                    1
#define BB5_CALRX_RC2RXOUT_EN_MSB                                    29
#define BB5_CALRX_RC2RXOUT_EN_LSB                                    29
#define BB5_CALRX_RC2RXOUT_EN_MASK                                   0x20000000
#define BB5_CALRX_RC2RXOUT_EN_GET(x)                                 (((x) & BB5_CALRX_RC2RXOUT_EN_MASK) >> BB5_CALRX_RC2RXOUT_EN_LSB)
#define BB5_CALRX_RC2RXOUT_EN_SET(x)                                 (((0 | (x)) << BB5_CALRX_RC2RXOUT_EN_LSB) & BB5_CALRX_RC2RXOUT_EN_MASK)
#define BB5_CALRX_RC2RXOUT_EN_RESET                                  0
#define BB5_CALRX_BQ2RXOUT_EN_MSB                                    28
#define BB5_CALRX_BQ2RXOUT_EN_LSB                                    28
#define BB5_CALRX_BQ2RXOUT_EN_MASK                                   0x10000000
#define BB5_CALRX_BQ2RXOUT_EN_GET(x)                                 (((x) & BB5_CALRX_BQ2RXOUT_EN_MASK) >> BB5_CALRX_BQ2RXOUT_EN_LSB)
#define BB5_CALRX_BQ2RXOUT_EN_SET(x)                                 (((0 | (x)) << BB5_CALRX_BQ2RXOUT_EN_LSB) & BB5_CALRX_BQ2RXOUT_EN_MASK)
#define BB5_CALRX_BQ2RXOUT_EN_RESET                                  1
#define BB5_CALRX_NOTCHON_MSB                                        27
#define BB5_CALRX_NOTCHON_LSB                                        27
#define BB5_CALRX_NOTCHON_MASK                                       0x08000000
#define BB5_CALRX_NOTCHON_GET(x)                                     (((x) & BB5_CALRX_NOTCHON_MASK) >> BB5_CALRX_NOTCHON_LSB)
#define BB5_CALRX_NOTCHON_SET(x)                                     (((0 | (x)) << BB5_CALRX_NOTCHON_LSB) & BB5_CALRX_NOTCHON_MASK)
#define BB5_CALRX_NOTCHON_RESET                                      0
#define BB5_CALRX_BYPASSBQ1_EN_MSB                                   26
#define BB5_CALRX_BYPASSBQ1_EN_LSB                                   26
#define BB5_CALRX_BYPASSBQ1_EN_MASK                                  0x04000000
#define BB5_CALRX_BYPASSBQ1_EN_GET(x)                                (((x) & BB5_CALRX_BYPASSBQ1_EN_MASK) >> BB5_CALRX_BYPASSBQ1_EN_LSB)
#define BB5_CALRX_BYPASSBQ1_EN_SET(x)                                (((0 | (x)) << BB5_CALRX_BYPASSBQ1_EN_LSB) & BB5_CALRX_BYPASSBQ1_EN_MASK)
#define BB5_CALRX_BYPASSBQ1_EN_RESET                                 0
#define BB5_CALRX_BQ2V2I_EN_MSB                                      25
#define BB5_CALRX_BQ2V2I_EN_LSB                                      25
#define BB5_CALRX_BQ2V2I_EN_MASK                                     0x02000000
#define BB5_CALRX_BQ2V2I_EN_GET(x)                                   (((x) & BB5_CALRX_BQ2V2I_EN_MASK) >> BB5_CALRX_BQ2V2I_EN_LSB)
#define BB5_CALRX_BQ2V2I_EN_SET(x)                                   (((0 | (x)) << BB5_CALRX_BQ2V2I_EN_LSB) & BB5_CALRX_BQ2V2I_EN_MASK)
#define BB5_CALRX_BQ2V2I_EN_RESET                                    0
#define BB5_CALRX_DAC2V2I_EN_MSB                                     24
#define BB5_CALRX_DAC2V2I_EN_LSB                                     24
#define BB5_CALRX_DAC2V2I_EN_MASK                                    0x01000000
#define BB5_CALRX_DAC2V2I_EN_GET(x)                                  (((x) & BB5_CALRX_DAC2V2I_EN_MASK) >> BB5_CALRX_DAC2V2I_EN_LSB)
#define BB5_CALRX_DAC2V2I_EN_SET(x)                                  (((0 | (x)) << BB5_CALRX_DAC2V2I_EN_LSB) & BB5_CALRX_DAC2V2I_EN_MASK)
#define BB5_CALRX_DAC2V2I_EN_RESET                                   1
#define BB5_CALRX_PWD_RCFILT_MSB                                     23
#define BB5_CALRX_PWD_RCFILT_LSB                                     23
#define BB5_CALRX_PWD_RCFILT_MASK                                    0x00800000
#define BB5_CALRX_PWD_RCFILT_GET(x)                                  (((x) & BB5_CALRX_PWD_RCFILT_MASK) >> BB5_CALRX_PWD_RCFILT_LSB)
#define BB5_CALRX_PWD_RCFILT_SET(x)                                  (((0 | (x)) << BB5_CALRX_PWD_RCFILT_LSB) & BB5_CALRX_PWD_RCFILT_MASK)
#define BB5_CALRX_PWD_RCFILT_RESET                                   0
#define BB5_CALRX_PWD_V2I_MSB                                        22
#define BB5_CALRX_PWD_V2I_LSB                                        22
#define BB5_CALRX_PWD_V2I_MASK                                       0x00400000
#define BB5_CALRX_PWD_V2I_GET(x)                                     (((x) & BB5_CALRX_PWD_V2I_MASK) >> BB5_CALRX_PWD_V2I_LSB)
#define BB5_CALRX_PWD_V2I_SET(x)                                     (((0 | (x)) << BB5_CALRX_PWD_V2I_LSB) & BB5_CALRX_PWD_V2I_MASK)
#define BB5_CALRX_PWD_V2I_RESET                                      0
#define BB5_CALRX_PWD_BIQUAD1_MSB                                    21
#define BB5_CALRX_PWD_BIQUAD1_LSB                                    21
#define BB5_CALRX_PWD_BIQUAD1_MASK                                   0x00200000
#define BB5_CALRX_PWD_BIQUAD1_GET(x)                                 (((x) & BB5_CALRX_PWD_BIQUAD1_MASK) >> BB5_CALRX_PWD_BIQUAD1_LSB)
#define BB5_CALRX_PWD_BIQUAD1_SET(x)                                 (((0 | (x)) << BB5_CALRX_PWD_BIQUAD1_LSB) & BB5_CALRX_PWD_BIQUAD1_MASK)
#define BB5_CALRX_PWD_BIQUAD1_RESET                                  0
#define BB5_CALRX_PWD_BIQUAD2_MSB                                    20
#define BB5_CALRX_PWD_BIQUAD2_LSB                                    20
#define BB5_CALRX_PWD_BIQUAD2_MASK                                   0x00100000
#define BB5_CALRX_PWD_BIQUAD2_GET(x)                                 (((x) & BB5_CALRX_PWD_BIQUAD2_MASK) >> BB5_CALRX_PWD_BIQUAD2_LSB)
#define BB5_CALRX_PWD_BIQUAD2_SET(x)                                 (((0 | (x)) << BB5_CALRX_PWD_BIQUAD2_LSB) & BB5_CALRX_PWD_BIQUAD2_MASK)
#define BB5_CALRX_PWD_BIQUAD2_RESET                                  0
#define BB5_CALRX_REMOVECAP_RCFILT_MSB                               19
#define BB5_CALRX_REMOVECAP_RCFILT_LSB                               19
#define BB5_CALRX_REMOVECAP_RCFILT_MASK                              0x00080000
#define BB5_CALRX_REMOVECAP_RCFILT_GET(x)                            (((x) & BB5_CALRX_REMOVECAP_RCFILT_MASK) >> BB5_CALRX_REMOVECAP_RCFILT_LSB)
#define BB5_CALRX_REMOVECAP_RCFILT_SET(x)                            (((0 | (x)) << BB5_CALRX_REMOVECAP_RCFILT_LSB) & BB5_CALRX_REMOVECAP_RCFILT_MASK)
#define BB5_CALRX_REMOVECAP_RCFILT_RESET                             0
#define BB5_CALRX_NOTCH_HALFBW_MSB                                   18
#define BB5_CALRX_NOTCH_HALFBW_LSB                                   18
#define BB5_CALRX_NOTCH_HALFBW_MASK                                  0x00040000
#define BB5_CALRX_NOTCH_HALFBW_GET(x)                                (((x) & BB5_CALRX_NOTCH_HALFBW_MASK) >> BB5_CALRX_NOTCH_HALFBW_LSB)
#define BB5_CALRX_NOTCH_HALFBW_SET(x)                                (((0 | (x)) << BB5_CALRX_NOTCH_HALFBW_LSB) & BB5_CALRX_NOTCH_HALFBW_MASK)
#define BB5_CALRX_NOTCH_HALFBW_RESET                                 0
#define BB5_CALTX_RXIN2RC_EN_MSB                                     17
#define BB5_CALTX_RXIN2RC_EN_LSB                                     17
#define BB5_CALTX_RXIN2RC_EN_MASK                                    0x00020000
#define BB5_CALTX_RXIN2RC_EN_GET(x)                                  (((x) & BB5_CALTX_RXIN2RC_EN_MASK) >> BB5_CALTX_RXIN2RC_EN_LSB)
#define BB5_CALTX_RXIN2RC_EN_SET(x)                                  (((0 | (x)) << BB5_CALTX_RXIN2RC_EN_LSB) & BB5_CALTX_RXIN2RC_EN_MASK)
#define BB5_CALTX_RXIN2RC_EN_RESET                                   1
#define BB5_CALTX_RC2BQ1_EN_MSB                                      16
#define BB5_CALTX_RC2BQ1_EN_LSB                                      16
#define BB5_CALTX_RC2BQ1_EN_MASK                                     0x00010000
#define BB5_CALTX_RC2BQ1_EN_GET(x)                                   (((x) & BB5_CALTX_RC2BQ1_EN_MASK) >> BB5_CALTX_RC2BQ1_EN_LSB)
#define BB5_CALTX_RC2BQ1_EN_SET(x)                                   (((0 | (x)) << BB5_CALTX_RC2BQ1_EN_LSB) & BB5_CALTX_RC2BQ1_EN_MASK)
#define BB5_CALTX_RC2BQ1_EN_RESET                                    0
#define BB5_CALTX_RC2RXOUT_EN_MSB                                    15
#define BB5_CALTX_RC2RXOUT_EN_LSB                                    15
#define BB5_CALTX_RC2RXOUT_EN_MASK                                   0x00008000
#define BB5_CALTX_RC2RXOUT_EN_GET(x)                                 (((x) & BB5_CALTX_RC2RXOUT_EN_MASK) >> BB5_CALTX_RC2RXOUT_EN_LSB)
#define BB5_CALTX_RC2RXOUT_EN_SET(x)                                 (((0 | (x)) << BB5_CALTX_RC2RXOUT_EN_LSB) & BB5_CALTX_RC2RXOUT_EN_MASK)
#define BB5_CALTX_RC2RXOUT_EN_RESET                                  1
#define BB5_CALTX_BQ2RXOUT_EN_MSB                                    14
#define BB5_CALTX_BQ2RXOUT_EN_LSB                                    14
#define BB5_CALTX_BQ2RXOUT_EN_MASK                                   0x00004000
#define BB5_CALTX_BQ2RXOUT_EN_GET(x)                                 (((x) & BB5_CALTX_BQ2RXOUT_EN_MASK) >> BB5_CALTX_BQ2RXOUT_EN_LSB)
#define BB5_CALTX_BQ2RXOUT_EN_SET(x)                                 (((0 | (x)) << BB5_CALTX_BQ2RXOUT_EN_LSB) & BB5_CALTX_BQ2RXOUT_EN_MASK)
#define BB5_CALTX_BQ2RXOUT_EN_RESET                                  0
#define BB5_CALTX_NOTCHON_MSB                                        13
#define BB5_CALTX_NOTCHON_LSB                                        13
#define BB5_CALTX_NOTCHON_MASK                                       0x00002000
#define BB5_CALTX_NOTCHON_GET(x)                                     (((x) & BB5_CALTX_NOTCHON_MASK) >> BB5_CALTX_NOTCHON_LSB)
#define BB5_CALTX_NOTCHON_SET(x)                                     (((0 | (x)) << BB5_CALTX_NOTCHON_LSB) & BB5_CALTX_NOTCHON_MASK)
#define BB5_CALTX_NOTCHON_RESET                                      1
#define BB5_CALTX_BYPASSBQ1_EN_MSB                                   12
#define BB5_CALTX_BYPASSBQ1_EN_LSB                                   12
#define BB5_CALTX_BYPASSBQ1_EN_MASK                                  0x00001000
#define BB5_CALTX_BYPASSBQ1_EN_GET(x)                                (((x) & BB5_CALTX_BYPASSBQ1_EN_MASK) >> BB5_CALTX_BYPASSBQ1_EN_LSB)
#define BB5_CALTX_BYPASSBQ1_EN_SET(x)                                (((0 | (x)) << BB5_CALTX_BYPASSBQ1_EN_LSB) & BB5_CALTX_BYPASSBQ1_EN_MASK)
#define BB5_CALTX_BYPASSBQ1_EN_RESET                                 0
#define BB5_CALTX_BQ2V2I_EN_MSB                                      11
#define BB5_CALTX_BQ2V2I_EN_LSB                                      11
#define BB5_CALTX_BQ2V2I_EN_MASK                                     0x00000800
#define BB5_CALTX_BQ2V2I_EN_GET(x)                                   (((x) & BB5_CALTX_BQ2V2I_EN_MASK) >> BB5_CALTX_BQ2V2I_EN_LSB)
#define BB5_CALTX_BQ2V2I_EN_SET(x)                                   (((0 | (x)) << BB5_CALTX_BQ2V2I_EN_LSB) & BB5_CALTX_BQ2V2I_EN_MASK)
#define BB5_CALTX_BQ2V2I_EN_RESET                                    1
#define BB5_CALTX_DAC2V2I_EN_MSB                                     10
#define BB5_CALTX_DAC2V2I_EN_LSB                                     10
#define BB5_CALTX_DAC2V2I_EN_MASK                                    0x00000400
#define BB5_CALTX_DAC2V2I_EN_GET(x)                                  (((x) & BB5_CALTX_DAC2V2I_EN_MASK) >> BB5_CALTX_DAC2V2I_EN_LSB)
#define BB5_CALTX_DAC2V2I_EN_SET(x)                                  (((0 | (x)) << BB5_CALTX_DAC2V2I_EN_LSB) & BB5_CALTX_DAC2V2I_EN_MASK)
#define BB5_CALTX_DAC2V2I_EN_RESET                                   0
#define BB5_CALTX_PWD_RCFILT_MSB                                     9
#define BB5_CALTX_PWD_RCFILT_LSB                                     9
#define BB5_CALTX_PWD_RCFILT_MASK                                    0x00000200
#define BB5_CALTX_PWD_RCFILT_GET(x)                                  (((x) & BB5_CALTX_PWD_RCFILT_MASK) >> BB5_CALTX_PWD_RCFILT_LSB)
#define BB5_CALTX_PWD_RCFILT_SET(x)                                  (((0 | (x)) << BB5_CALTX_PWD_RCFILT_LSB) & BB5_CALTX_PWD_RCFILT_MASK)
#define BB5_CALTX_PWD_RCFILT_RESET                                   0
#define BB5_CALTX_PWD_V2I_MSB                                        8
#define BB5_CALTX_PWD_V2I_LSB                                        8
#define BB5_CALTX_PWD_V2I_MASK                                       0x00000100
#define BB5_CALTX_PWD_V2I_GET(x)                                     (((x) & BB5_CALTX_PWD_V2I_MASK) >> BB5_CALTX_PWD_V2I_LSB)
#define BB5_CALTX_PWD_V2I_SET(x)                                     (((0 | (x)) << BB5_CALTX_PWD_V2I_LSB) & BB5_CALTX_PWD_V2I_MASK)
#define BB5_CALTX_PWD_V2I_RESET                                      0
#define BB5_CALTX_PWD_BIQUAD1_MSB                                    7
#define BB5_CALTX_PWD_BIQUAD1_LSB                                    7
#define BB5_CALTX_PWD_BIQUAD1_MASK                                   0x00000080
#define BB5_CALTX_PWD_BIQUAD1_GET(x)                                 (((x) & BB5_CALTX_PWD_BIQUAD1_MASK) >> BB5_CALTX_PWD_BIQUAD1_LSB)
#define BB5_CALTX_PWD_BIQUAD1_SET(x)                                 (((0 | (x)) << BB5_CALTX_PWD_BIQUAD1_LSB) & BB5_CALTX_PWD_BIQUAD1_MASK)
#define BB5_CALTX_PWD_BIQUAD1_RESET                                  0
#define BB5_CALTX_PWD_BIQUAD2_MSB                                    6
#define BB5_CALTX_PWD_BIQUAD2_LSB                                    6
#define BB5_CALTX_PWD_BIQUAD2_MASK                                   0x00000040
#define BB5_CALTX_PWD_BIQUAD2_GET(x)                                 (((x) & BB5_CALTX_PWD_BIQUAD2_MASK) >> BB5_CALTX_PWD_BIQUAD2_LSB)
#define BB5_CALTX_PWD_BIQUAD2_SET(x)                                 (((0 | (x)) << BB5_CALTX_PWD_BIQUAD2_LSB) & BB5_CALTX_PWD_BIQUAD2_MASK)
#define BB5_CALTX_PWD_BIQUAD2_RESET                                  0
#define BB5_CALTX_REMOVECAP_RCFILT_MSB                               5
#define BB5_CALTX_REMOVECAP_RCFILT_LSB                               5
#define BB5_CALTX_REMOVECAP_RCFILT_MASK                              0x00000020
#define BB5_CALTX_REMOVECAP_RCFILT_GET(x)                            (((x) & BB5_CALTX_REMOVECAP_RCFILT_MASK) >> BB5_CALTX_REMOVECAP_RCFILT_LSB)
#define BB5_CALTX_REMOVECAP_RCFILT_SET(x)                            (((0 | (x)) << BB5_CALTX_REMOVECAP_RCFILT_LSB) & BB5_CALTX_REMOVECAP_RCFILT_MASK)
#define BB5_CALTX_REMOVECAP_RCFILT_RESET                             1
#define BB5_CALTX_NOTCH_HALFBW_MSB                                   4
#define BB5_CALTX_NOTCH_HALFBW_LSB                                   4
#define BB5_CALTX_NOTCH_HALFBW_MASK                                  0x00000010
#define BB5_CALTX_NOTCH_HALFBW_GET(x)                                (((x) & BB5_CALTX_NOTCH_HALFBW_MASK) >> BB5_CALTX_NOTCH_HALFBW_LSB)
#define BB5_CALTX_NOTCH_HALFBW_SET(x)                                (((0 | (x)) << BB5_CALTX_NOTCH_HALFBW_LSB) & BB5_CALTX_NOTCH_HALFBW_MASK)
#define BB5_CALTX_NOTCH_HALFBW_RESET                                 0
#define BB5_ADC_REFBIAS_MSB                                          3
#define BB5_ADC_REFBIAS_LSB                                          2
#define BB5_ADC_REFBIAS_MASK                                         0x0000000c
#define BB5_ADC_REFBIAS_GET(x)                                       (((x) & BB5_ADC_REFBIAS_MASK) >> BB5_ADC_REFBIAS_LSB)
#define BB5_ADC_REFBIAS_SET(x)                                       (((0 | (x)) << BB5_ADC_REFBIAS_LSB) & BB5_ADC_REFBIAS_MASK)
#define BB5_ADC_REFBIAS_RESET                                        3
#define BB5_ADC_REFINC_MSB                                           1
#define BB5_ADC_REFINC_LSB                                           1
#define BB5_ADC_REFINC_MASK                                          0x00000002
#define BB5_ADC_REFINC_GET(x)                                        (((x) & BB5_ADC_REFINC_MASK) >> BB5_ADC_REFINC_LSB)
#define BB5_ADC_REFINC_SET(x)                                        (((0 | (x)) << BB5_ADC_REFINC_LSB) & BB5_ADC_REFINC_MASK)
#define BB5_ADC_REFINC_RESET                                         0
#define BB5_ADC_SWAP_MSB                                             0
#define BB5_ADC_SWAP_LSB                                             0
#define BB5_ADC_SWAP_MASK                                            0x00000001
#define BB5_ADC_SWAP_GET(x)                                          (((x) & BB5_ADC_SWAP_MASK) >> BB5_ADC_SWAP_LSB)
#define BB5_ADC_SWAP_SET(x)                                          (((0 | (x)) << BB5_ADC_SWAP_LSB) & BB5_ADC_SWAP_MASK)
#define BB5_ADC_SWAP_RESET                                           0
#define BB5_ADDRESS                                                  0x0010
#define BB5_HW_MASK                                                  0xffffffff
#define BB5_SW_MASK                                                  0xffffffff
#define BB5_HW_WRITE_MASK                                            0x00000000
#define BB5_SW_WRITE_MASK                                            0xffffffff
#define BB5_RSTMASK                                                  0xffffffff
#define BB5_RESET                                                    0xd102a82c

// 0x0014 (BB6)
#define BB6_CALPA_RXIN2RC_EN_MSB                                     31
#define BB6_CALPA_RXIN2RC_EN_LSB                                     31
#define BB6_CALPA_RXIN2RC_EN_MASK                                    0x80000000
#define BB6_CALPA_RXIN2RC_EN_GET(x)                                  (((x) & BB6_CALPA_RXIN2RC_EN_MASK) >> BB6_CALPA_RXIN2RC_EN_LSB)
#define BB6_CALPA_RXIN2RC_EN_SET(x)                                  (((0 | (x)) << BB6_CALPA_RXIN2RC_EN_LSB) & BB6_CALPA_RXIN2RC_EN_MASK)
#define BB6_CALPA_RXIN2RC_EN_RESET                                   1
#define BB6_CALPA_RC2BQ1_EN_MSB                                      30
#define BB6_CALPA_RC2BQ1_EN_LSB                                      30
#define BB6_CALPA_RC2BQ1_EN_MASK                                     0x40000000
#define BB6_CALPA_RC2BQ1_EN_GET(x)                                   (((x) & BB6_CALPA_RC2BQ1_EN_MASK) >> BB6_CALPA_RC2BQ1_EN_LSB)
#define BB6_CALPA_RC2BQ1_EN_SET(x)                                   (((0 | (x)) << BB6_CALPA_RC2BQ1_EN_LSB) & BB6_CALPA_RC2BQ1_EN_MASK)
#define BB6_CALPA_RC2BQ1_EN_RESET                                    0
#define BB6_CALPA_RC2RXOUT_EN_MSB                                    29
#define BB6_CALPA_RC2RXOUT_EN_LSB                                    29
#define BB6_CALPA_RC2RXOUT_EN_MASK                                   0x20000000
#define BB6_CALPA_RC2RXOUT_EN_GET(x)                                 (((x) & BB6_CALPA_RC2RXOUT_EN_MASK) >> BB6_CALPA_RC2RXOUT_EN_LSB)
#define BB6_CALPA_RC2RXOUT_EN_SET(x)                                 (((0 | (x)) << BB6_CALPA_RC2RXOUT_EN_LSB) & BB6_CALPA_RC2RXOUT_EN_MASK)
#define BB6_CALPA_RC2RXOUT_EN_RESET                                  1
#define BB6_CALPA_BQ2RXOUT_EN_MSB                                    28
#define BB6_CALPA_BQ2RXOUT_EN_LSB                                    28
#define BB6_CALPA_BQ2RXOUT_EN_MASK                                   0x10000000
#define BB6_CALPA_BQ2RXOUT_EN_GET(x)                                 (((x) & BB6_CALPA_BQ2RXOUT_EN_MASK) >> BB6_CALPA_BQ2RXOUT_EN_LSB)
#define BB6_CALPA_BQ2RXOUT_EN_SET(x)                                 (((0 | (x)) << BB6_CALPA_BQ2RXOUT_EN_LSB) & BB6_CALPA_BQ2RXOUT_EN_MASK)
#define BB6_CALPA_BQ2RXOUT_EN_RESET                                  0
#define BB6_CALPA_NOTCHON_MSB                                        27
#define BB6_CALPA_NOTCHON_LSB                                        27
#define BB6_CALPA_NOTCHON_MASK                                       0x08000000
#define BB6_CALPA_NOTCHON_GET(x)                                     (((x) & BB6_CALPA_NOTCHON_MASK) >> BB6_CALPA_NOTCHON_LSB)
#define BB6_CALPA_NOTCHON_SET(x)                                     (((0 | (x)) << BB6_CALPA_NOTCHON_LSB) & BB6_CALPA_NOTCHON_MASK)
#define BB6_CALPA_NOTCHON_RESET                                      1
#define BB6_CALPA_BYPASSBQ1_EN_MSB                                   26
#define BB6_CALPA_BYPASSBQ1_EN_LSB                                   26
#define BB6_CALPA_BYPASSBQ1_EN_MASK                                  0x04000000
#define BB6_CALPA_BYPASSBQ1_EN_GET(x)                                (((x) & BB6_CALPA_BYPASSBQ1_EN_MASK) >> BB6_CALPA_BYPASSBQ1_EN_LSB)
#define BB6_CALPA_BYPASSBQ1_EN_SET(x)                                (((0 | (x)) << BB6_CALPA_BYPASSBQ1_EN_LSB) & BB6_CALPA_BYPASSBQ1_EN_MASK)
#define BB6_CALPA_BYPASSBQ1_EN_RESET                                 0
#define BB6_CALPA_BQ2V2I_EN_MSB                                      25
#define BB6_CALPA_BQ2V2I_EN_LSB                                      25
#define BB6_CALPA_BQ2V2I_EN_MASK                                     0x02000000
#define BB6_CALPA_BQ2V2I_EN_GET(x)                                   (((x) & BB6_CALPA_BQ2V2I_EN_MASK) >> BB6_CALPA_BQ2V2I_EN_LSB)
#define BB6_CALPA_BQ2V2I_EN_SET(x)                                   (((0 | (x)) << BB6_CALPA_BQ2V2I_EN_LSB) & BB6_CALPA_BQ2V2I_EN_MASK)
#define BB6_CALPA_BQ2V2I_EN_RESET                                    1
#define BB6_CALPA_DAC2V2I_EN_MSB                                     24
#define BB6_CALPA_DAC2V2I_EN_LSB                                     24
#define BB6_CALPA_DAC2V2I_EN_MASK                                    0x01000000
#define BB6_CALPA_DAC2V2I_EN_GET(x)                                  (((x) & BB6_CALPA_DAC2V2I_EN_MASK) >> BB6_CALPA_DAC2V2I_EN_LSB)
#define BB6_CALPA_DAC2V2I_EN_SET(x)                                  (((0 | (x)) << BB6_CALPA_DAC2V2I_EN_LSB) & BB6_CALPA_DAC2V2I_EN_MASK)
#define BB6_CALPA_DAC2V2I_EN_RESET                                   0
#define BB6_CALPA_PWD_RCFILT_MSB                                     23
#define BB6_CALPA_PWD_RCFILT_LSB                                     23
#define BB6_CALPA_PWD_RCFILT_MASK                                    0x00800000
#define BB6_CALPA_PWD_RCFILT_GET(x)                                  (((x) & BB6_CALPA_PWD_RCFILT_MASK) >> BB6_CALPA_PWD_RCFILT_LSB)
#define BB6_CALPA_PWD_RCFILT_SET(x)                                  (((0 | (x)) << BB6_CALPA_PWD_RCFILT_LSB) & BB6_CALPA_PWD_RCFILT_MASK)
#define BB6_CALPA_PWD_RCFILT_RESET                                   0
#define BB6_CALPA_PWD_V2I_MSB                                        22
#define BB6_CALPA_PWD_V2I_LSB                                        22
#define BB6_CALPA_PWD_V2I_MASK                                       0x00400000
#define BB6_CALPA_PWD_V2I_GET(x)                                     (((x) & BB6_CALPA_PWD_V2I_MASK) >> BB6_CALPA_PWD_V2I_LSB)
#define BB6_CALPA_PWD_V2I_SET(x)                                     (((0 | (x)) << BB6_CALPA_PWD_V2I_LSB) & BB6_CALPA_PWD_V2I_MASK)
#define BB6_CALPA_PWD_V2I_RESET                                      0
#define BB6_CALPA_PWD_BIQUAD1_MSB                                    21
#define BB6_CALPA_PWD_BIQUAD1_LSB                                    21
#define BB6_CALPA_PWD_BIQUAD1_MASK                                   0x00200000
#define BB6_CALPA_PWD_BIQUAD1_GET(x)                                 (((x) & BB6_CALPA_PWD_BIQUAD1_MASK) >> BB6_CALPA_PWD_BIQUAD1_LSB)
#define BB6_CALPA_PWD_BIQUAD1_SET(x)                                 (((0 | (x)) << BB6_CALPA_PWD_BIQUAD1_LSB) & BB6_CALPA_PWD_BIQUAD1_MASK)
#define BB6_CALPA_PWD_BIQUAD1_RESET                                  0
#define BB6_CALPA_PWD_BIQUAD2_MSB                                    20
#define BB6_CALPA_PWD_BIQUAD2_LSB                                    20
#define BB6_CALPA_PWD_BIQUAD2_MASK                                   0x00100000
#define BB6_CALPA_PWD_BIQUAD2_GET(x)                                 (((x) & BB6_CALPA_PWD_BIQUAD2_MASK) >> BB6_CALPA_PWD_BIQUAD2_LSB)
#define BB6_CALPA_PWD_BIQUAD2_SET(x)                                 (((0 | (x)) << BB6_CALPA_PWD_BIQUAD2_LSB) & BB6_CALPA_PWD_BIQUAD2_MASK)
#define BB6_CALPA_PWD_BIQUAD2_RESET                                  0
#define BB6_CALPA_REMOVECAP_RCFILT_MSB                               19
#define BB6_CALPA_REMOVECAP_RCFILT_LSB                               19
#define BB6_CALPA_REMOVECAP_RCFILT_MASK                              0x00080000
#define BB6_CALPA_REMOVECAP_RCFILT_GET(x)                            (((x) & BB6_CALPA_REMOVECAP_RCFILT_MASK) >> BB6_CALPA_REMOVECAP_RCFILT_LSB)
#define BB6_CALPA_REMOVECAP_RCFILT_SET(x)                            (((0 | (x)) << BB6_CALPA_REMOVECAP_RCFILT_LSB) & BB6_CALPA_REMOVECAP_RCFILT_MASK)
#define BB6_CALPA_REMOVECAP_RCFILT_RESET                             1
#define BB6_CALPA_NOTCH_HALFBW_MSB                                   18
#define BB6_CALPA_NOTCH_HALFBW_LSB                                   18
#define BB6_CALPA_NOTCH_HALFBW_MASK                                  0x00040000
#define BB6_CALPA_NOTCH_HALFBW_GET(x)                                (((x) & BB6_CALPA_NOTCH_HALFBW_MASK) >> BB6_CALPA_NOTCH_HALFBW_LSB)
#define BB6_CALPA_NOTCH_HALFBW_SET(x)                                (((0 | (x)) << BB6_CALPA_NOTCH_HALFBW_LSB) & BB6_CALPA_NOTCH_HALFBW_MASK)
#define BB6_CALPA_NOTCH_HALFBW_RESET                                 0
#define BB6_CALFC_RXIN2RC_EN_MSB                                     17
#define BB6_CALFC_RXIN2RC_EN_LSB                                     17
#define BB6_CALFC_RXIN2RC_EN_MASK                                    0x00020000
#define BB6_CALFC_RXIN2RC_EN_GET(x)                                  (((x) & BB6_CALFC_RXIN2RC_EN_MASK) >> BB6_CALFC_RXIN2RC_EN_LSB)
#define BB6_CALFC_RXIN2RC_EN_SET(x)                                  (((0 | (x)) << BB6_CALFC_RXIN2RC_EN_LSB) & BB6_CALFC_RXIN2RC_EN_MASK)
#define BB6_CALFC_RXIN2RC_EN_RESET                                   0
#define BB6_CALFC_RC2BQ1_EN_MSB                                      16
#define BB6_CALFC_RC2BQ1_EN_LSB                                      16
#define BB6_CALFC_RC2BQ1_EN_MASK                                     0x00010000
#define BB6_CALFC_RC2BQ1_EN_GET(x)                                   (((x) & BB6_CALFC_RC2BQ1_EN_MASK) >> BB6_CALFC_RC2BQ1_EN_LSB)
#define BB6_CALFC_RC2BQ1_EN_SET(x)                                   (((0 | (x)) << BB6_CALFC_RC2BQ1_EN_LSB) & BB6_CALFC_RC2BQ1_EN_MASK)
#define BB6_CALFC_RC2BQ1_EN_RESET                                    0
#define BB6_CALFC_RC2RXOUT_EN_MSB                                    15
#define BB6_CALFC_RC2RXOUT_EN_LSB                                    15
#define BB6_CALFC_RC2RXOUT_EN_MASK                                   0x00008000
#define BB6_CALFC_RC2RXOUT_EN_GET(x)                                 (((x) & BB6_CALFC_RC2RXOUT_EN_MASK) >> BB6_CALFC_RC2RXOUT_EN_LSB)
#define BB6_CALFC_RC2RXOUT_EN_SET(x)                                 (((0 | (x)) << BB6_CALFC_RC2RXOUT_EN_LSB) & BB6_CALFC_RC2RXOUT_EN_MASK)
#define BB6_CALFC_RC2RXOUT_EN_RESET                                  0
#define BB6_CALFC_BQ2RXOUT_EN_MSB                                    14
#define BB6_CALFC_BQ2RXOUT_EN_LSB                                    14
#define BB6_CALFC_BQ2RXOUT_EN_MASK                                   0x00004000
#define BB6_CALFC_BQ2RXOUT_EN_GET(x)                                 (((x) & BB6_CALFC_BQ2RXOUT_EN_MASK) >> BB6_CALFC_BQ2RXOUT_EN_LSB)
#define BB6_CALFC_BQ2RXOUT_EN_SET(x)                                 (((0 | (x)) << BB6_CALFC_BQ2RXOUT_EN_LSB) & BB6_CALFC_BQ2RXOUT_EN_MASK)
#define BB6_CALFC_BQ2RXOUT_EN_RESET                                  1
#define BB6_CALFC_NOTCHON_MSB                                        13
#define BB6_CALFC_NOTCHON_LSB                                        13
#define BB6_CALFC_NOTCHON_MASK                                       0x00002000
#define BB6_CALFC_NOTCHON_GET(x)                                     (((x) & BB6_CALFC_NOTCHON_MASK) >> BB6_CALFC_NOTCHON_LSB)
#define BB6_CALFC_NOTCHON_SET(x)                                     (((0 | (x)) << BB6_CALFC_NOTCHON_LSB) & BB6_CALFC_NOTCHON_MASK)
#define BB6_CALFC_NOTCHON_RESET                                      1
#define BB6_CALFC_BYPASSBQ1_EN_MSB                                   12
#define BB6_CALFC_BYPASSBQ1_EN_LSB                                   12
#define BB6_CALFC_BYPASSBQ1_EN_MASK                                  0x00001000
#define BB6_CALFC_BYPASSBQ1_EN_GET(x)                                (((x) & BB6_CALFC_BYPASSBQ1_EN_MASK) >> BB6_CALFC_BYPASSBQ1_EN_LSB)
#define BB6_CALFC_BYPASSBQ1_EN_SET(x)                                (((0 | (x)) << BB6_CALFC_BYPASSBQ1_EN_LSB) & BB6_CALFC_BYPASSBQ1_EN_MASK)
#define BB6_CALFC_BYPASSBQ1_EN_RESET                                 0
#define BB6_CALFC_BQ2V2I_EN_MSB                                      11
#define BB6_CALFC_BQ2V2I_EN_LSB                                      11
#define BB6_CALFC_BQ2V2I_EN_MASK                                     0x00000800
#define BB6_CALFC_BQ2V2I_EN_GET(x)                                   (((x) & BB6_CALFC_BQ2V2I_EN_MASK) >> BB6_CALFC_BQ2V2I_EN_LSB)
#define BB6_CALFC_BQ2V2I_EN_SET(x)                                   (((0 | (x)) << BB6_CALFC_BQ2V2I_EN_LSB) & BB6_CALFC_BQ2V2I_EN_MASK)
#define BB6_CALFC_BQ2V2I_EN_RESET                                    0
#define BB6_CALFC_DAC2V2I_EN_MSB                                     10
#define BB6_CALFC_DAC2V2I_EN_LSB                                     10
#define BB6_CALFC_DAC2V2I_EN_MASK                                    0x00000400
#define BB6_CALFC_DAC2V2I_EN_GET(x)                                  (((x) & BB6_CALFC_DAC2V2I_EN_MASK) >> BB6_CALFC_DAC2V2I_EN_LSB)
#define BB6_CALFC_DAC2V2I_EN_SET(x)                                  (((0 | (x)) << BB6_CALFC_DAC2V2I_EN_LSB) & BB6_CALFC_DAC2V2I_EN_MASK)
#define BB6_CALFC_DAC2V2I_EN_RESET                                   0
#define BB6_CALFC_PWD_RCFILT_MSB                                     9
#define BB6_CALFC_PWD_RCFILT_LSB                                     9
#define BB6_CALFC_PWD_RCFILT_MASK                                    0x00000200
#define BB6_CALFC_PWD_RCFILT_GET(x)                                  (((x) & BB6_CALFC_PWD_RCFILT_MASK) >> BB6_CALFC_PWD_RCFILT_LSB)
#define BB6_CALFC_PWD_RCFILT_SET(x)                                  (((0 | (x)) << BB6_CALFC_PWD_RCFILT_LSB) & BB6_CALFC_PWD_RCFILT_MASK)
#define BB6_CALFC_PWD_RCFILT_RESET                                   1
#define BB6_CALFC_PWD_V2I_MSB                                        8
#define BB6_CALFC_PWD_V2I_LSB                                        8
#define BB6_CALFC_PWD_V2I_MASK                                       0x00000100
#define BB6_CALFC_PWD_V2I_GET(x)                                     (((x) & BB6_CALFC_PWD_V2I_MASK) >> BB6_CALFC_PWD_V2I_LSB)
#define BB6_CALFC_PWD_V2I_SET(x)                                     (((0 | (x)) << BB6_CALFC_PWD_V2I_LSB) & BB6_CALFC_PWD_V2I_MASK)
#define BB6_CALFC_PWD_V2I_RESET                                      1
#define BB6_CALFC_PWD_BIQUAD1_MSB                                    7
#define BB6_CALFC_PWD_BIQUAD1_LSB                                    7
#define BB6_CALFC_PWD_BIQUAD1_MASK                                   0x00000080
#define BB6_CALFC_PWD_BIQUAD1_GET(x)                                 (((x) & BB6_CALFC_PWD_BIQUAD1_MASK) >> BB6_CALFC_PWD_BIQUAD1_LSB)
#define BB6_CALFC_PWD_BIQUAD1_SET(x)                                 (((0 | (x)) << BB6_CALFC_PWD_BIQUAD1_LSB) & BB6_CALFC_PWD_BIQUAD1_MASK)
#define BB6_CALFC_PWD_BIQUAD1_RESET                                  0
#define BB6_CALFC_PWD_BIQUAD2_MSB                                    6
#define BB6_CALFC_PWD_BIQUAD2_LSB                                    6
#define BB6_CALFC_PWD_BIQUAD2_MASK                                   0x00000040
#define BB6_CALFC_PWD_BIQUAD2_GET(x)                                 (((x) & BB6_CALFC_PWD_BIQUAD2_MASK) >> BB6_CALFC_PWD_BIQUAD2_LSB)
#define BB6_CALFC_PWD_BIQUAD2_SET(x)                                 (((0 | (x)) << BB6_CALFC_PWD_BIQUAD2_LSB) & BB6_CALFC_PWD_BIQUAD2_MASK)
#define BB6_CALFC_PWD_BIQUAD2_RESET                                  0
#define BB6_CALFC_REMOVECAP_RCFILT_MSB                               5
#define BB6_CALFC_REMOVECAP_RCFILT_LSB                               5
#define BB6_CALFC_REMOVECAP_RCFILT_MASK                              0x00000020
#define BB6_CALFC_REMOVECAP_RCFILT_GET(x)                            (((x) & BB6_CALFC_REMOVECAP_RCFILT_MASK) >> BB6_CALFC_REMOVECAP_RCFILT_LSB)
#define BB6_CALFC_REMOVECAP_RCFILT_SET(x)                            (((0 | (x)) << BB6_CALFC_REMOVECAP_RCFILT_LSB) & BB6_CALFC_REMOVECAP_RCFILT_MASK)
#define BB6_CALFC_REMOVECAP_RCFILT_RESET                             0
#define BB6_CALFC_NOTCH_HALFBW_MSB                                   4
#define BB6_CALFC_NOTCH_HALFBW_LSB                                   4
#define BB6_CALFC_NOTCH_HALFBW_MASK                                  0x00000010
#define BB6_CALFC_NOTCH_HALFBW_GET(x)                                (((x) & BB6_CALFC_NOTCH_HALFBW_MASK) >> BB6_CALFC_NOTCH_HALFBW_LSB)
#define BB6_CALFC_NOTCH_HALFBW_SET(x)                                (((0 | (x)) << BB6_CALFC_NOTCH_HALFBW_LSB) & BB6_CALFC_NOTCH_HALFBW_MASK)
#define BB6_CALFC_NOTCH_HALFBW_RESET                                 0
#define BB6_PWD_BIAS_MSB                                             3
#define BB6_PWD_BIAS_LSB                                             3
#define BB6_PWD_BIAS_MASK                                            0x00000008
#define BB6_PWD_BIAS_GET(x)                                          (((x) & BB6_PWD_BIAS_MASK) >> BB6_PWD_BIAS_LSB)
#define BB6_PWD_BIAS_SET(x)                                          (((0 | (x)) << BB6_PWD_BIAS_LSB) & BB6_PWD_BIAS_MASK)
#define BB6_PWD_BIAS_RESET                                           0
#define BB6_DRV_STR_MSB                                              2
#define BB6_DRV_STR_LSB                                              0
#define BB6_DRV_STR_MASK                                             0x00000007
#define BB6_DRV_STR_GET(x)                                           (((x) & BB6_DRV_STR_MASK) >> BB6_DRV_STR_LSB)
#define BB6_DRV_STR_SET(x)                                           (((0 | (x)) << BB6_DRV_STR_LSB) & BB6_DRV_STR_MASK)
#define BB6_DRV_STR_RESET                                            0
#define BB6_ADDRESS                                                  0x0014
#define BB6_HW_MASK                                                  0xffffffff
#define BB6_SW_MASK                                                  0xffffffff
#define BB6_HW_WRITE_MASK                                            0x00000000
#define BB6_SW_WRITE_MASK                                            0xffffffff
#define BB6_RSTMASK                                                  0xffffffff
#define BB6_RESET                                                    0xaa086300

// 0x0018 (BB7)
#define BB7_LPRX_RXIN2RC_EN_MSB                                      31
#define BB7_LPRX_RXIN2RC_EN_LSB                                      31
#define BB7_LPRX_RXIN2RC_EN_MASK                                     0x80000000
#define BB7_LPRX_RXIN2RC_EN_GET(x)                                   (((x) & BB7_LPRX_RXIN2RC_EN_MASK) >> BB7_LPRX_RXIN2RC_EN_LSB)
#define BB7_LPRX_RXIN2RC_EN_SET(x)                                   (((0 | (x)) << BB7_LPRX_RXIN2RC_EN_LSB) & BB7_LPRX_RXIN2RC_EN_MASK)
#define BB7_LPRX_RXIN2RC_EN_RESET                                    1
#define BB7_LPRX_RC2BQ1_EN_MSB                                       30
#define BB7_LPRX_RC2BQ1_EN_LSB                                       30
#define BB7_LPRX_RC2BQ1_EN_MASK                                      0x40000000
#define BB7_LPRX_RC2BQ1_EN_GET(x)                                    (((x) & BB7_LPRX_RC2BQ1_EN_MASK) >> BB7_LPRX_RC2BQ1_EN_LSB)
#define BB7_LPRX_RC2BQ1_EN_SET(x)                                    (((0 | (x)) << BB7_LPRX_RC2BQ1_EN_LSB) & BB7_LPRX_RC2BQ1_EN_MASK)
#define BB7_LPRX_RC2BQ1_EN_RESET                                     0
#define BB7_LPRX_RC2RXOUT_EN_MSB                                     29
#define BB7_LPRX_RC2RXOUT_EN_LSB                                     29
#define BB7_LPRX_RC2RXOUT_EN_MASK                                    0x20000000
#define BB7_LPRX_RC2RXOUT_EN_GET(x)                                  (((x) & BB7_LPRX_RC2RXOUT_EN_MASK) >> BB7_LPRX_RC2RXOUT_EN_LSB)
#define BB7_LPRX_RC2RXOUT_EN_SET(x)                                  (((0 | (x)) << BB7_LPRX_RC2RXOUT_EN_LSB) & BB7_LPRX_RC2RXOUT_EN_MASK)
#define BB7_LPRX_RC2RXOUT_EN_RESET                                   1
#define BB7_LPRX_BQ2RXOUT_EN_MSB                                     28
#define BB7_LPRX_BQ2RXOUT_EN_LSB                                     28
#define BB7_LPRX_BQ2RXOUT_EN_MASK                                    0x10000000
#define BB7_LPRX_BQ2RXOUT_EN_GET(x)                                  (((x) & BB7_LPRX_BQ2RXOUT_EN_MASK) >> BB7_LPRX_BQ2RXOUT_EN_LSB)
#define BB7_LPRX_BQ2RXOUT_EN_SET(x)                                  (((0 | (x)) << BB7_LPRX_BQ2RXOUT_EN_LSB) & BB7_LPRX_BQ2RXOUT_EN_MASK)
#define BB7_LPRX_BQ2RXOUT_EN_RESET                                   0
#define BB7_LPRX_NOTCHON_MSB                                         27
#define BB7_LPRX_NOTCHON_LSB                                         27
#define BB7_LPRX_NOTCHON_MASK                                        0x08000000
#define BB7_LPRX_NOTCHON_GET(x)                                      (((x) & BB7_LPRX_NOTCHON_MASK) >> BB7_LPRX_NOTCHON_LSB)
#define BB7_LPRX_NOTCHON_SET(x)                                      (((0 | (x)) << BB7_LPRX_NOTCHON_LSB) & BB7_LPRX_NOTCHON_MASK)
#define BB7_LPRX_NOTCHON_RESET                                       0
#define BB7_LPRX_BYPASSBQ1_EN_MSB                                    26
#define BB7_LPRX_BYPASSBQ1_EN_LSB                                    26
#define BB7_LPRX_BYPASSBQ1_EN_MASK                                   0x04000000
#define BB7_LPRX_BYPASSBQ1_EN_GET(x)                                 (((x) & BB7_LPRX_BYPASSBQ1_EN_MASK) >> BB7_LPRX_BYPASSBQ1_EN_LSB)
#define BB7_LPRX_BYPASSBQ1_EN_SET(x)                                 (((0 | (x)) << BB7_LPRX_BYPASSBQ1_EN_LSB) & BB7_LPRX_BYPASSBQ1_EN_MASK)
#define BB7_LPRX_BYPASSBQ1_EN_RESET                                  0
#define BB7_LPRX_BQ2V2I_EN_MSB                                       25
#define BB7_LPRX_BQ2V2I_EN_LSB                                       25
#define BB7_LPRX_BQ2V2I_EN_MASK                                      0x02000000
#define BB7_LPRX_BQ2V2I_EN_GET(x)                                    (((x) & BB7_LPRX_BQ2V2I_EN_MASK) >> BB7_LPRX_BQ2V2I_EN_LSB)
#define BB7_LPRX_BQ2V2I_EN_SET(x)                                    (((0 | (x)) << BB7_LPRX_BQ2V2I_EN_LSB) & BB7_LPRX_BQ2V2I_EN_MASK)
#define BB7_LPRX_BQ2V2I_EN_RESET                                     0
#define BB7_LPRX_DAC2V2I_EN_MSB                                      24
#define BB7_LPRX_DAC2V2I_EN_LSB                                      24
#define BB7_LPRX_DAC2V2I_EN_MASK                                     0x01000000
#define BB7_LPRX_DAC2V2I_EN_GET(x)                                   (((x) & BB7_LPRX_DAC2V2I_EN_MASK) >> BB7_LPRX_DAC2V2I_EN_LSB)
#define BB7_LPRX_DAC2V2I_EN_SET(x)                                   (((0 | (x)) << BB7_LPRX_DAC2V2I_EN_LSB) & BB7_LPRX_DAC2V2I_EN_MASK)
#define BB7_LPRX_DAC2V2I_EN_RESET                                    0
#define BB7_LPRX_PWD_RCFILT_MSB                                      23
#define BB7_LPRX_PWD_RCFILT_LSB                                      23
#define BB7_LPRX_PWD_RCFILT_MASK                                     0x00800000
#define BB7_LPRX_PWD_RCFILT_GET(x)                                   (((x) & BB7_LPRX_PWD_RCFILT_MASK) >> BB7_LPRX_PWD_RCFILT_LSB)
#define BB7_LPRX_PWD_RCFILT_SET(x)                                   (((0 | (x)) << BB7_LPRX_PWD_RCFILT_LSB) & BB7_LPRX_PWD_RCFILT_MASK)
#define BB7_LPRX_PWD_RCFILT_RESET                                    0
#define BB7_LPRX_PWD_V2I_MSB                                         22
#define BB7_LPRX_PWD_V2I_LSB                                         22
#define BB7_LPRX_PWD_V2I_MASK                                        0x00400000
#define BB7_LPRX_PWD_V2I_GET(x)                                      (((x) & BB7_LPRX_PWD_V2I_MASK) >> BB7_LPRX_PWD_V2I_LSB)
#define BB7_LPRX_PWD_V2I_SET(x)                                      (((0 | (x)) << BB7_LPRX_PWD_V2I_LSB) & BB7_LPRX_PWD_V2I_MASK)
#define BB7_LPRX_PWD_V2I_RESET                                       1
#define BB7_LPRX_PWD_BIQUAD1_MSB                                     21
#define BB7_LPRX_PWD_BIQUAD1_LSB                                     21
#define BB7_LPRX_PWD_BIQUAD1_MASK                                    0x00200000
#define BB7_LPRX_PWD_BIQUAD1_GET(x)                                  (((x) & BB7_LPRX_PWD_BIQUAD1_MASK) >> BB7_LPRX_PWD_BIQUAD1_LSB)
#define BB7_LPRX_PWD_BIQUAD1_SET(x)                                  (((0 | (x)) << BB7_LPRX_PWD_BIQUAD1_LSB) & BB7_LPRX_PWD_BIQUAD1_MASK)
#define BB7_LPRX_PWD_BIQUAD1_RESET                                   1
#define BB7_LPRX_PWD_BIQUAD2_MSB                                     20
#define BB7_LPRX_PWD_BIQUAD2_LSB                                     20
#define BB7_LPRX_PWD_BIQUAD2_MASK                                    0x00100000
#define BB7_LPRX_PWD_BIQUAD2_GET(x)                                  (((x) & BB7_LPRX_PWD_BIQUAD2_MASK) >> BB7_LPRX_PWD_BIQUAD2_LSB)
#define BB7_LPRX_PWD_BIQUAD2_SET(x)                                  (((0 | (x)) << BB7_LPRX_PWD_BIQUAD2_LSB) & BB7_LPRX_PWD_BIQUAD2_MASK)
#define BB7_LPRX_PWD_BIQUAD2_RESET                                   1
#define BB7_LPRX_REMOVECAP_RCFILT_MSB                                19
#define BB7_LPRX_REMOVECAP_RCFILT_LSB                                19
#define BB7_LPRX_REMOVECAP_RCFILT_MASK                               0x00080000
#define BB7_LPRX_REMOVECAP_RCFILT_GET(x)                             (((x) & BB7_LPRX_REMOVECAP_RCFILT_MASK) >> BB7_LPRX_REMOVECAP_RCFILT_LSB)
#define BB7_LPRX_REMOVECAP_RCFILT_SET(x)                             (((0 | (x)) << BB7_LPRX_REMOVECAP_RCFILT_LSB) & BB7_LPRX_REMOVECAP_RCFILT_MASK)
#define BB7_LPRX_REMOVECAP_RCFILT_RESET                              0
#define BB7_LPRX_NOTCH_HALFBW_MSB                                    18
#define BB7_LPRX_NOTCH_HALFBW_LSB                                    18
#define BB7_LPRX_NOTCH_HALFBW_MASK                                   0x00040000
#define BB7_LPRX_NOTCH_HALFBW_GET(x)                                 (((x) & BB7_LPRX_NOTCH_HALFBW_MASK) >> BB7_LPRX_NOTCH_HALFBW_LSB)
#define BB7_LPRX_NOTCH_HALFBW_SET(x)                                 (((0 | (x)) << BB7_LPRX_NOTCH_HALFBW_LSB) & BB7_LPRX_NOTCH_HALFBW_MASK)
#define BB7_LPRX_NOTCH_HALFBW_RESET                                  0
#define BB7_LPRX_FILTERFC_MSB                                        17
#define BB7_LPRX_FILTERFC_LSB                                        13
#define BB7_LPRX_FILTERFC_MASK                                       0x0003e000
#define BB7_LPRX_FILTERFC_GET(x)                                     (((x) & BB7_LPRX_FILTERFC_MASK) >> BB7_LPRX_FILTERFC_LSB)
#define BB7_LPRX_FILTERFC_SET(x)                                     (((0 | (x)) << BB7_LPRX_FILTERFC_LSB) & BB7_LPRX_FILTERFC_MASK)
#define BB7_LPRX_FILTERFC_RESET                                      16
#define BB7_PWD_OSDAC_CAL_MSB                                        12
#define BB7_PWD_OSDAC_CAL_LSB                                        10
#define BB7_PWD_OSDAC_CAL_MASK                                       0x00001c00
#define BB7_PWD_OSDAC_CAL_GET(x)                                     (((x) & BB7_PWD_OSDAC_CAL_MASK) >> BB7_PWD_OSDAC_CAL_LSB)
#define BB7_PWD_OSDAC_CAL_SET(x)                                     (((0 | (x)) << BB7_PWD_OSDAC_CAL_LSB) & BB7_PWD_OSDAC_CAL_MASK)
#define BB7_PWD_OSDAC_CAL_RESET                                      0
#define BB7_NOTCH_HALFBW_MSB                                         9
#define BB7_NOTCH_HALFBW_LSB                                         9
#define BB7_NOTCH_HALFBW_MASK                                        0x00000200
#define BB7_NOTCH_HALFBW_GET(x)                                      (((x) & BB7_NOTCH_HALFBW_MASK) >> BB7_NOTCH_HALFBW_LSB)
#define BB7_NOTCH_HALFBW_SET(x)                                      (((0 | (x)) << BB7_NOTCH_HALFBW_LSB) & BB7_NOTCH_HALFBW_MASK)
#define BB7_NOTCH_HALFBW_RESET                                       0
#define BB7_RX_FILTERFC_OVR_MSB                                      8
#define BB7_RX_FILTERFC_OVR_LSB                                      8
#define BB7_RX_FILTERFC_OVR_MASK                                     0x00000100
#define BB7_RX_FILTERFC_OVR_GET(x)                                   (((x) & BB7_RX_FILTERFC_OVR_MASK) >> BB7_RX_FILTERFC_OVR_LSB)
#define BB7_RX_FILTERFC_OVR_SET(x)                                   (((0 | (x)) << BB7_RX_FILTERFC_OVR_LSB) & BB7_RX_FILTERFC_OVR_MASK)
#define BB7_RX_FILTERFC_OVR_RESET                                    0
#define BB7_TX_FILTERFC_OVR_MSB                                      7
#define BB7_TX_FILTERFC_OVR_LSB                                      7
#define BB7_TX_FILTERFC_OVR_MASK                                     0x00000080
#define BB7_TX_FILTERFC_OVR_GET(x)                                   (((x) & BB7_TX_FILTERFC_OVR_MASK) >> BB7_TX_FILTERFC_OVR_LSB)
#define BB7_TX_FILTERFC_OVR_SET(x)                                   (((0 | (x)) << BB7_TX_FILTERFC_OVR_LSB) & BB7_TX_FILTERFC_OVR_MASK)
#define BB7_TX_FILTERFC_OVR_RESET                                    0
#define BB7_LPRX_FILTERFC_OVR_MSB                                    6
#define BB7_LPRX_FILTERFC_OVR_LSB                                    6
#define BB7_LPRX_FILTERFC_OVR_MASK                                   0x00000040
#define BB7_LPRX_FILTERFC_OVR_GET(x)                                 (((x) & BB7_LPRX_FILTERFC_OVR_MASK) >> BB7_LPRX_FILTERFC_OVR_LSB)
#define BB7_LPRX_FILTERFC_OVR_SET(x)                                 (((0 | (x)) << BB7_LPRX_FILTERFC_OVR_LSB) & BB7_LPRX_FILTERFC_OVR_MASK)
#define BB7_LPRX_FILTERFC_OVR_RESET                                  0
#define BB7_ADCSHORT_MSB                                             5
#define BB7_ADCSHORT_LSB                                             5
#define BB7_ADCSHORT_MASK                                            0x00000020
#define BB7_ADCSHORT_GET(x)                                          (((x) & BB7_ADCSHORT_MASK) >> BB7_ADCSHORT_LSB)
#define BB7_ADCSHORT_SET(x)                                          (((0 | (x)) << BB7_ADCSHORT_LSB) & BB7_ADCSHORT_MASK)
#define BB7_ADCSHORT_RESET                                           0
#define BB7_ADCSHORT_OVR_MSB                                         4
#define BB7_ADCSHORT_OVR_LSB                                         4
#define BB7_ADCSHORT_OVR_MASK                                        0x00000010
#define BB7_ADCSHORT_OVR_GET(x)                                      (((x) & BB7_ADCSHORT_OVR_MASK) >> BB7_ADCSHORT_OVR_LSB)
#define BB7_ADCSHORT_OVR_SET(x)                                      (((0 | (x)) << BB7_ADCSHORT_OVR_LSB) & BB7_ADCSHORT_OVR_MASK)
#define BB7_ADCSHORT_OVR_RESET                                       0
#define BB7_ADDACLOOPBACK_MSB                                        3
#define BB7_ADDACLOOPBACK_LSB                                        3
#define BB7_ADDACLOOPBACK_MASK                                       0x00000008
#define BB7_ADDACLOOPBACK_GET(x)                                     (((x) & BB7_ADDACLOOPBACK_MASK) >> BB7_ADDACLOOPBACK_LSB)
#define BB7_ADDACLOOPBACK_SET(x)                                     (((0 | (x)) << BB7_ADDACLOOPBACK_LSB) & BB7_ADDACLOOPBACK_MASK)
#define BB7_ADDACLOOPBACK_RESET                                      0
#define BB7_DACFULLSCALE_MSB                                         2
#define BB7_DACFULLSCALE_LSB                                         2
#define BB7_DACFULLSCALE_MASK                                        0x00000004
#define BB7_DACFULLSCALE_GET(x)                                      (((x) & BB7_DACFULLSCALE_MASK) >> BB7_DACFULLSCALE_LSB)
#define BB7_DACFULLSCALE_SET(x)                                      (((0 | (x)) << BB7_DACFULLSCALE_LSB) & BB7_DACFULLSCALE_MASK)
#define BB7_DACFULLSCALE_RESET                                       0
#define BB7_LOWPWRLISTEN_OVR_MSB                                     1
#define BB7_LOWPWRLISTEN_OVR_LSB                                     1
#define BB7_LOWPWRLISTEN_OVR_MASK                                    0x00000002
#define BB7_LOWPWRLISTEN_OVR_GET(x)                                  (((x) & BB7_LOWPWRLISTEN_OVR_MASK) >> BB7_LOWPWRLISTEN_OVR_LSB)
#define BB7_LOWPWRLISTEN_OVR_SET(x)                                  (((0 | (x)) << BB7_LOWPWRLISTEN_OVR_LSB) & BB7_LOWPWRLISTEN_OVR_MASK)
#define BB7_LOWPWRLISTEN_OVR_RESET                                   0
#define BB7_LOWPWRLISTEN_MSB                                         0
#define BB7_LOWPWRLISTEN_LSB                                         0
#define BB7_LOWPWRLISTEN_MASK                                        0x00000001
#define BB7_LOWPWRLISTEN_GET(x)                                      (((x) & BB7_LOWPWRLISTEN_MASK) >> BB7_LOWPWRLISTEN_LSB)
#define BB7_LOWPWRLISTEN_SET(x)                                      (((0 | (x)) << BB7_LOWPWRLISTEN_LSB) & BB7_LOWPWRLISTEN_MASK)
#define BB7_LOWPWRLISTEN_RESET                                       0
#define BB7_ADDRESS                                                  0x0018
#define BB7_HW_MASK                                                  0xffffffff
#define BB7_SW_MASK                                                  0xffffffff
#define BB7_HW_WRITE_MASK                                            0x00000000
#define BB7_SW_WRITE_MASK                                            0xffffffff
#define BB7_RSTMASK                                                  0xffffffff
#define BB7_RESET                                                    0xa0720000

// 0x001c (BB8)
#define BB8_RX1DB_BIQUAD_MSB                                         31
#define BB8_RX1DB_BIQUAD_LSB                                         29
#define BB8_RX1DB_BIQUAD_MASK                                        0xe0000000
#define BB8_RX1DB_BIQUAD_GET(x)                                      (((x) & BB8_RX1DB_BIQUAD_MASK) >> BB8_RX1DB_BIQUAD_LSB)
#define BB8_RX1DB_BIQUAD_SET(x)                                      (((0 | (x)) << BB8_RX1DB_BIQUAD_LSB) & BB8_RX1DB_BIQUAD_MASK)
#define BB8_RX1DB_BIQUAD_RESET                                       3
#define BB8_RX6DB_BIQUAD1_MSB                                        28
#define BB8_RX6DB_BIQUAD1_LSB                                        27
#define BB8_RX6DB_BIQUAD1_MASK                                       0x18000000
#define BB8_RX6DB_BIQUAD1_GET(x)                                     (((x) & BB8_RX6DB_BIQUAD1_MASK) >> BB8_RX6DB_BIQUAD1_LSB)
#define BB8_RX6DB_BIQUAD1_SET(x)                                     (((0 | (x)) << BB8_RX6DB_BIQUAD1_LSB) & BB8_RX6DB_BIQUAD1_MASK)
#define BB8_RX6DB_BIQUAD1_RESET                                      0
#define BB8_RX6DB_BIQUAD2_MSB                                        26
#define BB8_RX6DB_BIQUAD2_LSB                                        25
#define BB8_RX6DB_BIQUAD2_MASK                                       0x06000000
#define BB8_RX6DB_BIQUAD2_GET(x)                                     (((x) & BB8_RX6DB_BIQUAD2_MASK) >> BB8_RX6DB_BIQUAD2_LSB)
#define BB8_RX6DB_BIQUAD2_SET(x)                                     (((0 | (x)) << BB8_RX6DB_BIQUAD2_LSB) & BB8_RX6DB_BIQUAD2_MASK)
#define BB8_RX6DB_BIQUAD2_RESET                                      0
#define BB8_TX1DB_BIQUAD_MSB                                         24
#define BB8_TX1DB_BIQUAD_LSB                                         22
#define BB8_TX1DB_BIQUAD_MASK                                        0x01c00000
#define BB8_TX1DB_BIQUAD_GET(x)                                      (((x) & BB8_TX1DB_BIQUAD_MASK) >> BB8_TX1DB_BIQUAD_LSB)
#define BB8_TX1DB_BIQUAD_SET(x)                                      (((0 | (x)) << BB8_TX1DB_BIQUAD_LSB) & BB8_TX1DB_BIQUAD_MASK)
#define BB8_TX1DB_BIQUAD_RESET                                       3
#define BB8_TX6DB_BIQUAD1_MSB                                        21
#define BB8_TX6DB_BIQUAD1_LSB                                        20
#define BB8_TX6DB_BIQUAD1_MASK                                       0x00300000
#define BB8_TX6DB_BIQUAD1_GET(x)                                     (((x) & BB8_TX6DB_BIQUAD1_MASK) >> BB8_TX6DB_BIQUAD1_LSB)
#define BB8_TX6DB_BIQUAD1_SET(x)                                     (((0 | (x)) << BB8_TX6DB_BIQUAD1_LSB) & BB8_TX6DB_BIQUAD1_MASK)
#define BB8_TX6DB_BIQUAD1_RESET                                      0
#define BB8_TX6DB_BIQUAD2_MSB                                        19
#define BB8_TX6DB_BIQUAD2_LSB                                        18
#define BB8_TX6DB_BIQUAD2_MASK                                       0x000c0000
#define BB8_TX6DB_BIQUAD2_GET(x)                                     (((x) & BB8_TX6DB_BIQUAD2_MASK) >> BB8_TX6DB_BIQUAD2_LSB)
#define BB8_TX6DB_BIQUAD2_SET(x)                                     (((0 | (x)) << BB8_TX6DB_BIQUAD2_LSB) & BB8_TX6DB_BIQUAD2_MASK)
#define BB8_TX6DB_BIQUAD2_RESET                                      0
#define BB8_TXBB_GC_MSB                                              17
#define BB8_TXBB_GC_LSB                                              14
#define BB8_TXBB_GC_MASK                                             0x0003c000
#define BB8_TXBB_GC_GET(x)                                           (((x) & BB8_TXBB_GC_MASK) >> BB8_TXBB_GC_LSB)
#define BB8_TXBB_GC_SET(x)                                           (((0 | (x)) << BB8_TXBB_GC_LSB) & BB8_TXBB_GC_MASK)
#define BB8_TXBB_GC_RESET                                            1
#define BB8_DACRSTB_MSB                                              13
#define BB8_DACRSTB_LSB                                              13
#define BB8_DACRSTB_MASK                                             0x00002000
#define BB8_DACRSTB_GET(x)                                           (((x) & BB8_DACRSTB_MASK) >> BB8_DACRSTB_LSB)
#define BB8_DACRSTB_SET(x)                                           (((0 | (x)) << BB8_DACRSTB_LSB) & BB8_DACRSTB_MASK)
#define BB8_DACRSTB_RESET                                            1
#define BB8_INV_CLK320_ADC_MSB                                       12
#define BB8_INV_CLK320_ADC_LSB                                       12
#define BB8_INV_CLK320_ADC_MASK                                      0x00001000
#define BB8_INV_CLK320_ADC_GET(x)                                    (((x) & BB8_INV_CLK320_ADC_MASK) >> BB8_INV_CLK320_ADC_LSB)
#define BB8_INV_CLK320_ADC_SET(x)                                    (((0 | (x)) << BB8_INV_CLK320_ADC_LSB) & BB8_INV_CLK320_ADC_MASK)
#define BB8_INV_CLK320_ADC_RESET                                     0
#define BB8_LOCAL_DACPWD_MSB                                         11
#define BB8_LOCAL_DACPWD_LSB                                         11
#define BB8_LOCAL_DACPWD_MASK                                        0x00000800
#define BB8_LOCAL_DACPWD_GET(x)                                      (((x) & BB8_LOCAL_DACPWD_MASK) >> BB8_LOCAL_DACPWD_LSB)
#define BB8_LOCAL_DACPWD_SET(x)                                      (((0 | (x)) << BB8_LOCAL_DACPWD_LSB) & BB8_LOCAL_DACPWD_MASK)
#define BB8_LOCAL_DACPWD_RESET                                       0
#define BB8_DACPWD_MSB                                               10
#define BB8_DACPWD_LSB                                               10
#define BB8_DACPWD_MASK                                              0x00000400
#define BB8_DACPWD_GET(x)                                            (((x) & BB8_DACPWD_MASK) >> BB8_DACPWD_LSB)
#define BB8_DACPWD_SET(x)                                            (((0 | (x)) << BB8_DACPWD_LSB) & BB8_DACPWD_MASK)
#define BB8_DACPWD_RESET                                             0
#define BB8_DACCLKPWD_MSB                                            9
#define BB8_DACCLKPWD_LSB                                            9
#define BB8_DACCLKPWD_MASK                                           0x00000200
#define BB8_DACCLKPWD_GET(x)                                         (((x) & BB8_DACCLKPWD_MASK) >> BB8_DACCLKPWD_LSB)
#define BB8_DACCLKPWD_SET(x)                                         (((0 | (x)) << BB8_DACCLKPWD_LSB) & BB8_DACCLKPWD_MASK)
#define BB8_DACCLKPWD_RESET                                          0
#define BB8_LOCAL_ADCPWD_MSB                                         8
#define BB8_LOCAL_ADCPWD_LSB                                         8
#define BB8_LOCAL_ADCPWD_MASK                                        0x00000100
#define BB8_LOCAL_ADCPWD_GET(x)                                      (((x) & BB8_LOCAL_ADCPWD_MASK) >> BB8_LOCAL_ADCPWD_LSB)
#define BB8_LOCAL_ADCPWD_SET(x)                                      (((0 | (x)) << BB8_LOCAL_ADCPWD_LSB) & BB8_LOCAL_ADCPWD_MASK)
#define BB8_LOCAL_ADCPWD_RESET                                       0
#define BB8_ADCPWD_MSB                                               7
#define BB8_ADCPWD_LSB                                               7
#define BB8_ADCPWD_MASK                                              0x00000080
#define BB8_ADCPWD_GET(x)                                            (((x) & BB8_ADCPWD_MASK) >> BB8_ADCPWD_LSB)
#define BB8_ADCPWD_SET(x)                                            (((0 | (x)) << BB8_ADCPWD_LSB) & BB8_ADCPWD_MASK)
#define BB8_ADCPWD_RESET                                             0
#define BB8_ADCCLKPWD_MSB                                            6
#define BB8_ADCCLKPWD_LSB                                            6
#define BB8_ADCCLKPWD_MASK                                           0x00000040
#define BB8_ADCCLKPWD_GET(x)                                         (((x) & BB8_ADCCLKPWD_MASK) >> BB8_ADCCLKPWD_LSB)
#define BB8_ADCCLKPWD_SET(x)                                         (((0 | (x)) << BB8_ADCCLKPWD_LSB) & BB8_ADCCLKPWD_MASK)
#define BB8_ADCCLKPWD_RESET                                          0
#define BB8_LOCAL_CLKMODAADDAC_MSB                                   5
#define BB8_LOCAL_CLKMODAADDAC_LSB                                   5
#define BB8_LOCAL_CLKMODAADDAC_MASK                                  0x00000020
#define BB8_LOCAL_CLKMODAADDAC_GET(x)                                (((x) & BB8_LOCAL_CLKMODAADDAC_MASK) >> BB8_LOCAL_CLKMODAADDAC_LSB)
#define BB8_LOCAL_CLKMODAADDAC_SET(x)                                (((0 | (x)) << BB8_LOCAL_CLKMODAADDAC_LSB) & BB8_LOCAL_CLKMODAADDAC_MASK)
#define BB8_LOCAL_CLKMODAADDAC_RESET                                 0
#define BB8_DAC_CLK_SEL_MSB                                          4
#define BB8_DAC_CLK_SEL_LSB                                          4
#define BB8_DAC_CLK_SEL_MASK                                         0x00000010
#define BB8_DAC_CLK_SEL_GET(x)                                       (((x) & BB8_DAC_CLK_SEL_MASK) >> BB8_DAC_CLK_SEL_LSB)
#define BB8_DAC_CLK_SEL_SET(x)                                       (((0 | (x)) << BB8_DAC_CLK_SEL_LSB) & BB8_DAC_CLK_SEL_MASK)
#define BB8_DAC_CLK_SEL_RESET                                        0
#define BB8_ADC_CLK_SEL_MSB                                          3
#define BB8_ADC_CLK_SEL_LSB                                          2
#define BB8_ADC_CLK_SEL_MASK                                         0x0000000c
#define BB8_ADC_CLK_SEL_GET(x)                                       (((x) & BB8_ADC_CLK_SEL_MASK) >> BB8_ADC_CLK_SEL_LSB)
#define BB8_ADC_CLK_SEL_SET(x)                                       (((0 | (x)) << BB8_ADC_CLK_SEL_LSB) & BB8_ADC_CLK_SEL_MASK)
#define BB8_ADC_CLK_SEL_RESET                                        0
#define BB8_DACTERMRESSW_MSB                                         1
#define BB8_DACTERMRESSW_LSB                                         0
#define BB8_DACTERMRESSW_MASK                                        0x00000003
#define BB8_DACTERMRESSW_GET(x)                                      (((x) & BB8_DACTERMRESSW_MASK) >> BB8_DACTERMRESSW_LSB)
#define BB8_DACTERMRESSW_SET(x)                                      (((0 | (x)) << BB8_DACTERMRESSW_LSB) & BB8_DACTERMRESSW_MASK)
#define BB8_DACTERMRESSW_RESET                                       2
#define BB8_ADDRESS                                                  0x001c
#define BB8_HW_MASK                                                  0xffffffff
#define BB8_SW_MASK                                                  0xffffffff
#define BB8_HW_WRITE_MASK                                            0x00000000
#define BB8_SW_WRITE_MASK                                            0xffffffff
#define BB8_RSTMASK                                                  0xffffffff
#define BB8_RESET                                                    0x60c06002


#endif /* _BB_REG_CSR_H_ */
