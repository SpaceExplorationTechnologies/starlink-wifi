//                                                                             
// File:       ./rbist_regfile.vrh                                             
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:46:41 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             rbist_regfile.rdl                                               
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/rtl/wlan/rbist/blueprint/rtl/rbist_regfile.rdl
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
 */

#ifndef _RBIST_REGFILE_H_
#define _RBIST_REGFILE_H_
// 0x0000 (RBIST_CNTRL)
#define RBIST_CNTRL_ATE_ADC_CLK_INVERT_MSB                           17
#define RBIST_CNTRL_ATE_ADC_CLK_INVERT_LSB                           17
#define RBIST_CNTRL_ATE_ADC_CLK_INVERT_MASK                          0x00020000
#define RBIST_CNTRL_ATE_ADC_CLK_INVERT_GET(x)                        (((x) & RBIST_CNTRL_ATE_ADC_CLK_INVERT_MASK) >> RBIST_CNTRL_ATE_ADC_CLK_INVERT_LSB)
#define RBIST_CNTRL_ATE_ADC_CLK_INVERT_SET(x)                        (((0 | (x)) << RBIST_CNTRL_ATE_ADC_CLK_INVERT_LSB) & RBIST_CNTRL_ATE_ADC_CLK_INVERT_MASK)
#define RBIST_CNTRL_ATE_ADC_CLK_INVERT_RESET                         0
#define RBIST_CNTRL_ATE_RBIST_ENABLE_MSB                             16
#define RBIST_CNTRL_ATE_RBIST_ENABLE_LSB                             16
#define RBIST_CNTRL_ATE_RBIST_ENABLE_MASK                            0x00010000
#define RBIST_CNTRL_ATE_RBIST_ENABLE_GET(x)                          (((x) & RBIST_CNTRL_ATE_RBIST_ENABLE_MASK) >> RBIST_CNTRL_ATE_RBIST_ENABLE_LSB)
#define RBIST_CNTRL_ATE_RBIST_ENABLE_SET(x)                          (((0 | (x)) << RBIST_CNTRL_ATE_RBIST_ENABLE_LSB) & RBIST_CNTRL_ATE_RBIST_ENABLE_MASK)
#define RBIST_CNTRL_ATE_RBIST_ENABLE_RESET                           0
#define RBIST_CNTRL_ATE_RXDAC_CALIBRATE_MSB                          15
#define RBIST_CNTRL_ATE_RXDAC_CALIBRATE_LSB                          15
#define RBIST_CNTRL_ATE_RXDAC_CALIBRATE_MASK                         0x00008000
#define RBIST_CNTRL_ATE_RXDAC_CALIBRATE_GET(x)                       (((x) & RBIST_CNTRL_ATE_RXDAC_CALIBRATE_MASK) >> RBIST_CNTRL_ATE_RXDAC_CALIBRATE_LSB)
#define RBIST_CNTRL_ATE_RXDAC_CALIBRATE_SET(x)                       (((0 | (x)) << RBIST_CNTRL_ATE_RXDAC_CALIBRATE_LSB) & RBIST_CNTRL_ATE_RXDAC_CALIBRATE_MASK)
#define RBIST_CNTRL_ATE_RXDAC_CALIBRATE_RESET                        0
#define RBIST_CNTRL_ATE_CMAC_POWER_HPF_ENABLE_MSB                    14
#define RBIST_CNTRL_ATE_CMAC_POWER_HPF_ENABLE_LSB                    14
#define RBIST_CNTRL_ATE_CMAC_POWER_HPF_ENABLE_MASK                   0x00004000
#define RBIST_CNTRL_ATE_CMAC_POWER_HPF_ENABLE_GET(x)                 (((x) & RBIST_CNTRL_ATE_CMAC_POWER_HPF_ENABLE_MASK) >> RBIST_CNTRL_ATE_CMAC_POWER_HPF_ENABLE_LSB)
#define RBIST_CNTRL_ATE_CMAC_POWER_HPF_ENABLE_SET(x)                 (((0 | (x)) << RBIST_CNTRL_ATE_CMAC_POWER_HPF_ENABLE_LSB) & RBIST_CNTRL_ATE_CMAC_POWER_HPF_ENABLE_MASK)
#define RBIST_CNTRL_ATE_CMAC_POWER_HPF_ENABLE_RESET                  0
#define RBIST_CNTRL_ATE_CMAC_I2Q2_ENABLE_MSB                         13
#define RBIST_CNTRL_ATE_CMAC_I2Q2_ENABLE_LSB                         13
#define RBIST_CNTRL_ATE_CMAC_I2Q2_ENABLE_MASK                        0x00002000
#define RBIST_CNTRL_ATE_CMAC_I2Q2_ENABLE_GET(x)                      (((x) & RBIST_CNTRL_ATE_CMAC_I2Q2_ENABLE_MASK) >> RBIST_CNTRL_ATE_CMAC_I2Q2_ENABLE_LSB)
#define RBIST_CNTRL_ATE_CMAC_I2Q2_ENABLE_SET(x)                      (((0 | (x)) << RBIST_CNTRL_ATE_CMAC_I2Q2_ENABLE_LSB) & RBIST_CNTRL_ATE_CMAC_I2Q2_ENABLE_MASK)
#define RBIST_CNTRL_ATE_CMAC_I2Q2_ENABLE_RESET                       0
#define RBIST_CNTRL_ATE_CMAC_IQ_ENABLE_MSB                           12
#define RBIST_CNTRL_ATE_CMAC_IQ_ENABLE_LSB                           12
#define RBIST_CNTRL_ATE_CMAC_IQ_ENABLE_MASK                          0x00001000
#define RBIST_CNTRL_ATE_CMAC_IQ_ENABLE_GET(x)                        (((x) & RBIST_CNTRL_ATE_CMAC_IQ_ENABLE_MASK) >> RBIST_CNTRL_ATE_CMAC_IQ_ENABLE_LSB)
#define RBIST_CNTRL_ATE_CMAC_IQ_ENABLE_SET(x)                        (((0 | (x)) << RBIST_CNTRL_ATE_CMAC_IQ_ENABLE_LSB) & RBIST_CNTRL_ATE_CMAC_IQ_ENABLE_MASK)
#define RBIST_CNTRL_ATE_CMAC_IQ_ENABLE_RESET                         0
#define RBIST_CNTRL_ATE_CMAC_POWER_ENABLE_MSB                        11
#define RBIST_CNTRL_ATE_CMAC_POWER_ENABLE_LSB                        11
#define RBIST_CNTRL_ATE_CMAC_POWER_ENABLE_MASK                       0x00000800
#define RBIST_CNTRL_ATE_CMAC_POWER_ENABLE_GET(x)                     (((x) & RBIST_CNTRL_ATE_CMAC_POWER_ENABLE_MASK) >> RBIST_CNTRL_ATE_CMAC_POWER_ENABLE_LSB)
#define RBIST_CNTRL_ATE_CMAC_POWER_ENABLE_SET(x)                     (((0 | (x)) << RBIST_CNTRL_ATE_CMAC_POWER_ENABLE_LSB) & RBIST_CNTRL_ATE_CMAC_POWER_ENABLE_MASK)
#define RBIST_CNTRL_ATE_CMAC_POWER_ENABLE_RESET                      0
#define RBIST_CNTRL_ATE_CMAC_CORR_ENABLE_MSB                         10
#define RBIST_CNTRL_ATE_CMAC_CORR_ENABLE_LSB                         10
#define RBIST_CNTRL_ATE_CMAC_CORR_ENABLE_MASK                        0x00000400
#define RBIST_CNTRL_ATE_CMAC_CORR_ENABLE_GET(x)                      (((x) & RBIST_CNTRL_ATE_CMAC_CORR_ENABLE_MASK) >> RBIST_CNTRL_ATE_CMAC_CORR_ENABLE_LSB)
#define RBIST_CNTRL_ATE_CMAC_CORR_ENABLE_SET(x)                      (((0 | (x)) << RBIST_CNTRL_ATE_CMAC_CORR_ENABLE_LSB) & RBIST_CNTRL_ATE_CMAC_CORR_ENABLE_MASK)
#define RBIST_CNTRL_ATE_CMAC_CORR_ENABLE_RESET                       0
#define RBIST_CNTRL_ATE_CMAC_DC_ENABLE_MSB                           9
#define RBIST_CNTRL_ATE_CMAC_DC_ENABLE_LSB                           9
#define RBIST_CNTRL_ATE_CMAC_DC_ENABLE_MASK                          0x00000200
#define RBIST_CNTRL_ATE_CMAC_DC_ENABLE_GET(x)                        (((x) & RBIST_CNTRL_ATE_CMAC_DC_ENABLE_MASK) >> RBIST_CNTRL_ATE_CMAC_DC_ENABLE_LSB)
#define RBIST_CNTRL_ATE_CMAC_DC_ENABLE_SET(x)                        (((0 | (x)) << RBIST_CNTRL_ATE_CMAC_DC_ENABLE_LSB) & RBIST_CNTRL_ATE_CMAC_DC_ENABLE_MASK)
#define RBIST_CNTRL_ATE_CMAC_DC_ENABLE_RESET                         0
#define RBIST_CNTRL_ATE_CMAC_DC_WRITE_TO_CANCEL_MSB                  8
#define RBIST_CNTRL_ATE_CMAC_DC_WRITE_TO_CANCEL_LSB                  8
#define RBIST_CNTRL_ATE_CMAC_DC_WRITE_TO_CANCEL_MASK                 0x00000100
#define RBIST_CNTRL_ATE_CMAC_DC_WRITE_TO_CANCEL_GET(x)               (((x) & RBIST_CNTRL_ATE_CMAC_DC_WRITE_TO_CANCEL_MASK) >> RBIST_CNTRL_ATE_CMAC_DC_WRITE_TO_CANCEL_LSB)
#define RBIST_CNTRL_ATE_CMAC_DC_WRITE_TO_CANCEL_SET(x)               (((0 | (x)) << RBIST_CNTRL_ATE_CMAC_DC_WRITE_TO_CANCEL_LSB) & RBIST_CNTRL_ATE_CMAC_DC_WRITE_TO_CANCEL_MASK)
#define RBIST_CNTRL_ATE_CMAC_DC_WRITE_TO_CANCEL_RESET                0
#define RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_Q_MSB                    7
#define RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_Q_LSB                    7
#define RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_Q_MASK                   0x00000080
#define RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_Q_GET(x)                 (((x) & RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_Q_MASK) >> RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_Q_LSB)
#define RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_Q_SET(x)                 (((0 | (x)) << RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_Q_LSB) & RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_Q_MASK)
#define RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_Q_RESET                  0
#define RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_I_MSB                    6
#define RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_I_LSB                    6
#define RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_I_MASK                   0x00000040
#define RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_I_GET(x)                 (((x) & RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_I_MASK) >> RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_I_LSB)
#define RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_I_SET(x)                 (((0 | (x)) << RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_I_LSB) & RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_I_MASK)
#define RBIST_CNTRL_ATE_TONEGEN_PRBS_ENABLE_I_RESET                  0
#define RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_Q_MSB                 5
#define RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_Q_LSB                 5
#define RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_Q_MASK                0x00000020
#define RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_Q_GET(x)              (((x) & RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_Q_MASK) >> RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_Q_LSB)
#define RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_Q_SET(x)              (((0 | (x)) << RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_Q_LSB) & RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_Q_MASK)
#define RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_Q_RESET               0
#define RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_I_MSB                 4
#define RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_I_LSB                 4
#define RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_I_MASK                0x00000010
#define RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_I_GET(x)              (((x) & RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_I_MASK) >> RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_I_LSB)
#define RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_I_SET(x)              (((0 | (x)) << RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_I_LSB) & RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_I_MASK)
#define RBIST_CNTRL_ATE_TONEGEN_LINRAMP_ENABLE_I_RESET               0
#define RBIST_CNTRL_ATE_TONEGEN_LFTONE0_ENABLE_MSB                   3
#define RBIST_CNTRL_ATE_TONEGEN_LFTONE0_ENABLE_LSB                   3
#define RBIST_CNTRL_ATE_TONEGEN_LFTONE0_ENABLE_MASK                  0x00000008
#define RBIST_CNTRL_ATE_TONEGEN_LFTONE0_ENABLE_GET(x)                (((x) & RBIST_CNTRL_ATE_TONEGEN_LFTONE0_ENABLE_MASK) >> RBIST_CNTRL_ATE_TONEGEN_LFTONE0_ENABLE_LSB)
#define RBIST_CNTRL_ATE_TONEGEN_LFTONE0_ENABLE_SET(x)                (((0 | (x)) << RBIST_CNTRL_ATE_TONEGEN_LFTONE0_ENABLE_LSB) & RBIST_CNTRL_ATE_TONEGEN_LFTONE0_ENABLE_MASK)
#define RBIST_CNTRL_ATE_TONEGEN_LFTONE0_ENABLE_RESET                 0
#define RBIST_CNTRL_ATE_TONEGEN_TONE1_ENABLE_MSB                     2
#define RBIST_CNTRL_ATE_TONEGEN_TONE1_ENABLE_LSB                     2
#define RBIST_CNTRL_ATE_TONEGEN_TONE1_ENABLE_MASK                    0x00000004
#define RBIST_CNTRL_ATE_TONEGEN_TONE1_ENABLE_GET(x)                  (((x) & RBIST_CNTRL_ATE_TONEGEN_TONE1_ENABLE_MASK) >> RBIST_CNTRL_ATE_TONEGEN_TONE1_ENABLE_LSB)
#define RBIST_CNTRL_ATE_TONEGEN_TONE1_ENABLE_SET(x)                  (((0 | (x)) << RBIST_CNTRL_ATE_TONEGEN_TONE1_ENABLE_LSB) & RBIST_CNTRL_ATE_TONEGEN_TONE1_ENABLE_MASK)
#define RBIST_CNTRL_ATE_TONEGEN_TONE1_ENABLE_RESET                   0
#define RBIST_CNTRL_ATE_TONEGEN_TONE0_ENABLE_MSB                     1
#define RBIST_CNTRL_ATE_TONEGEN_TONE0_ENABLE_LSB                     1
#define RBIST_CNTRL_ATE_TONEGEN_TONE0_ENABLE_MASK                    0x00000002
#define RBIST_CNTRL_ATE_TONEGEN_TONE0_ENABLE_GET(x)                  (((x) & RBIST_CNTRL_ATE_TONEGEN_TONE0_ENABLE_MASK) >> RBIST_CNTRL_ATE_TONEGEN_TONE0_ENABLE_LSB)
#define RBIST_CNTRL_ATE_TONEGEN_TONE0_ENABLE_SET(x)                  (((0 | (x)) << RBIST_CNTRL_ATE_TONEGEN_TONE0_ENABLE_LSB) & RBIST_CNTRL_ATE_TONEGEN_TONE0_ENABLE_MASK)
#define RBIST_CNTRL_ATE_TONEGEN_TONE0_ENABLE_RESET                   0
#define RBIST_CNTRL_ATE_TONEGEN_DC_ENABLE_MSB                        0
#define RBIST_CNTRL_ATE_TONEGEN_DC_ENABLE_LSB                        0
#define RBIST_CNTRL_ATE_TONEGEN_DC_ENABLE_MASK                       0x00000001
#define RBIST_CNTRL_ATE_TONEGEN_DC_ENABLE_GET(x)                     (((x) & RBIST_CNTRL_ATE_TONEGEN_DC_ENABLE_MASK) >> RBIST_CNTRL_ATE_TONEGEN_DC_ENABLE_LSB)
#define RBIST_CNTRL_ATE_TONEGEN_DC_ENABLE_SET(x)                     (((0 | (x)) << RBIST_CNTRL_ATE_TONEGEN_DC_ENABLE_LSB) & RBIST_CNTRL_ATE_TONEGEN_DC_ENABLE_MASK)
#define RBIST_CNTRL_ATE_TONEGEN_DC_ENABLE_RESET                      0
#define RBIST_CNTRL_ADDRESS                                          0x0000
#define RBIST_CNTRL_HW_MASK                                          0x0003ffff
#define RBIST_CNTRL_SW_MASK                                          0x0003ffff
#define RBIST_CNTRL_HW_WRITE_MASK                                    0x00000000
#define RBIST_CNTRL_SW_WRITE_MASK                                    0x0003ffff
#define RBIST_CNTRL_RSTMASK                                          0xffffffff
#define RBIST_CNTRL_RESET                                            0x00000000

// 0x0004 (TX_DC_OFFSET)
#define TX_DC_OFFSET_ATE_TONEGEN_DC_Q_MSB                            26
#define TX_DC_OFFSET_ATE_TONEGEN_DC_Q_LSB                            16
#define TX_DC_OFFSET_ATE_TONEGEN_DC_Q_MASK                           0x07ff0000
#define TX_DC_OFFSET_ATE_TONEGEN_DC_Q_GET(x)                         (((x) & TX_DC_OFFSET_ATE_TONEGEN_DC_Q_MASK) >> TX_DC_OFFSET_ATE_TONEGEN_DC_Q_LSB)
#define TX_DC_OFFSET_ATE_TONEGEN_DC_Q_SET(x)                         (((0 | (x)) << TX_DC_OFFSET_ATE_TONEGEN_DC_Q_LSB) & TX_DC_OFFSET_ATE_TONEGEN_DC_Q_MASK)
#define TX_DC_OFFSET_ATE_TONEGEN_DC_Q_RESET                          0
#define TX_DC_OFFSET_ATE_TONEGEN_DC_I_MSB                            10
#define TX_DC_OFFSET_ATE_TONEGEN_DC_I_LSB                            0
#define TX_DC_OFFSET_ATE_TONEGEN_DC_I_MASK                           0x000007ff
#define TX_DC_OFFSET_ATE_TONEGEN_DC_I_GET(x)                         (((x) & TX_DC_OFFSET_ATE_TONEGEN_DC_I_MASK) >> TX_DC_OFFSET_ATE_TONEGEN_DC_I_LSB)
#define TX_DC_OFFSET_ATE_TONEGEN_DC_I_SET(x)                         (((0 | (x)) << TX_DC_OFFSET_ATE_TONEGEN_DC_I_LSB) & TX_DC_OFFSET_ATE_TONEGEN_DC_I_MASK)
#define TX_DC_OFFSET_ATE_TONEGEN_DC_I_RESET                          0
#define TX_DC_OFFSET_ADDRESS                                         0x0004
#define TX_DC_OFFSET_HW_MASK                                         0x07ff07ff
#define TX_DC_OFFSET_SW_MASK                                         0x07ff07ff
#define TX_DC_OFFSET_HW_WRITE_MASK                                   0x00000000
#define TX_DC_OFFSET_SW_WRITE_MASK                                   0x07ff07ff
#define TX_DC_OFFSET_RSTMASK                                         0xffffffff
#define TX_DC_OFFSET_RESET                                           0x00000000

// 0x0008 (TX_TONEGEN0)
#define TX_TONEGEN0_ATE_TONEGEN_TONE_TAU_K_MSB                       30
#define TX_TONEGEN0_ATE_TONEGEN_TONE_TAU_K_LSB                       24
#define TX_TONEGEN0_ATE_TONEGEN_TONE_TAU_K_MASK                      0x7f000000
#define TX_TONEGEN0_ATE_TONEGEN_TONE_TAU_K_GET(x)                    (((x) & TX_TONEGEN0_ATE_TONEGEN_TONE_TAU_K_MASK) >> TX_TONEGEN0_ATE_TONEGEN_TONE_TAU_K_LSB)
#define TX_TONEGEN0_ATE_TONEGEN_TONE_TAU_K_SET(x)                    (((0 | (x)) << TX_TONEGEN0_ATE_TONEGEN_TONE_TAU_K_LSB) & TX_TONEGEN0_ATE_TONEGEN_TONE_TAU_K_MASK)
#define TX_TONEGEN0_ATE_TONEGEN_TONE_TAU_K_RESET                     0
#define TX_TONEGEN0_ATE_TONEGEN_TONE_A_MAN_MSB                       23
#define TX_TONEGEN0_ATE_TONEGEN_TONE_A_MAN_LSB                       16
#define TX_TONEGEN0_ATE_TONEGEN_TONE_A_MAN_MASK                      0x00ff0000
#define TX_TONEGEN0_ATE_TONEGEN_TONE_A_MAN_GET(x)                    (((x) & TX_TONEGEN0_ATE_TONEGEN_TONE_A_MAN_MASK) >> TX_TONEGEN0_ATE_TONEGEN_TONE_A_MAN_LSB)
#define TX_TONEGEN0_ATE_TONEGEN_TONE_A_MAN_SET(x)                    (((0 | (x)) << TX_TONEGEN0_ATE_TONEGEN_TONE_A_MAN_LSB) & TX_TONEGEN0_ATE_TONEGEN_TONE_A_MAN_MASK)
#define TX_TONEGEN0_ATE_TONEGEN_TONE_A_MAN_RESET                     128
#define TX_TONEGEN0_ATE_TONEGEN_TONE_A_EXP_MSB                       11
#define TX_TONEGEN0_ATE_TONEGEN_TONE_A_EXP_LSB                       8
#define TX_TONEGEN0_ATE_TONEGEN_TONE_A_EXP_MASK                      0x00000f00
#define TX_TONEGEN0_ATE_TONEGEN_TONE_A_EXP_GET(x)                    (((x) & TX_TONEGEN0_ATE_TONEGEN_TONE_A_EXP_MASK) >> TX_TONEGEN0_ATE_TONEGEN_TONE_A_EXP_LSB)
#define TX_TONEGEN0_ATE_TONEGEN_TONE_A_EXP_SET(x)                    (((0 | (x)) << TX_TONEGEN0_ATE_TONEGEN_TONE_A_EXP_LSB) & TX_TONEGEN0_ATE_TONEGEN_TONE_A_EXP_MASK)
#define TX_TONEGEN0_ATE_TONEGEN_TONE_A_EXP_RESET                     7
#define TX_TONEGEN0_ATE_TONEGEN_TONE_FREQ_MSB                        6
#define TX_TONEGEN0_ATE_TONEGEN_TONE_FREQ_LSB                        0
#define TX_TONEGEN0_ATE_TONEGEN_TONE_FREQ_MASK                       0x0000007f
#define TX_TONEGEN0_ATE_TONEGEN_TONE_FREQ_GET(x)                     (((x) & TX_TONEGEN0_ATE_TONEGEN_TONE_FREQ_MASK) >> TX_TONEGEN0_ATE_TONEGEN_TONE_FREQ_LSB)
#define TX_TONEGEN0_ATE_TONEGEN_TONE_FREQ_SET(x)                     (((0 | (x)) << TX_TONEGEN0_ATE_TONEGEN_TONE_FREQ_LSB) & TX_TONEGEN0_ATE_TONEGEN_TONE_FREQ_MASK)
#define TX_TONEGEN0_ATE_TONEGEN_TONE_FREQ_RESET                      0
#define TX_TONEGEN0_ADDRESS                                          0x0008
#define TX_TONEGEN0_HW_MASK                                          0x7fff0f7f
#define TX_TONEGEN0_SW_MASK                                          0x7fff0f7f
#define TX_TONEGEN0_HW_WRITE_MASK                                    0x00000000
#define TX_TONEGEN0_SW_WRITE_MASK                                    0x7fff0f7f
#define TX_TONEGEN0_RSTMASK                                          0xffffffff
#define TX_TONEGEN0_RESET                                            0x00800700

// 0x000c (TX_TONEGEN1)
#define TX_TONEGEN1_ATE_TONEGEN_TONE_TAU_K_MSB                       30
#define TX_TONEGEN1_ATE_TONEGEN_TONE_TAU_K_LSB                       24
#define TX_TONEGEN1_ATE_TONEGEN_TONE_TAU_K_MASK                      0x7f000000
#define TX_TONEGEN1_ATE_TONEGEN_TONE_TAU_K_GET(x)                    (((x) & TX_TONEGEN1_ATE_TONEGEN_TONE_TAU_K_MASK) >> TX_TONEGEN1_ATE_TONEGEN_TONE_TAU_K_LSB)
#define TX_TONEGEN1_ATE_TONEGEN_TONE_TAU_K_SET(x)                    (((0 | (x)) << TX_TONEGEN1_ATE_TONEGEN_TONE_TAU_K_LSB) & TX_TONEGEN1_ATE_TONEGEN_TONE_TAU_K_MASK)
#define TX_TONEGEN1_ATE_TONEGEN_TONE_TAU_K_RESET                     0
#define TX_TONEGEN1_ATE_TONEGEN_TONE_A_MAN_MSB                       23
#define TX_TONEGEN1_ATE_TONEGEN_TONE_A_MAN_LSB                       16
#define TX_TONEGEN1_ATE_TONEGEN_TONE_A_MAN_MASK                      0x00ff0000
#define TX_TONEGEN1_ATE_TONEGEN_TONE_A_MAN_GET(x)                    (((x) & TX_TONEGEN1_ATE_TONEGEN_TONE_A_MAN_MASK) >> TX_TONEGEN1_ATE_TONEGEN_TONE_A_MAN_LSB)
#define TX_TONEGEN1_ATE_TONEGEN_TONE_A_MAN_SET(x)                    (((0 | (x)) << TX_TONEGEN1_ATE_TONEGEN_TONE_A_MAN_LSB) & TX_TONEGEN1_ATE_TONEGEN_TONE_A_MAN_MASK)
#define TX_TONEGEN1_ATE_TONEGEN_TONE_A_MAN_RESET                     128
#define TX_TONEGEN1_ATE_TONEGEN_TONE_A_EXP_MSB                       11
#define TX_TONEGEN1_ATE_TONEGEN_TONE_A_EXP_LSB                       8
#define TX_TONEGEN1_ATE_TONEGEN_TONE_A_EXP_MASK                      0x00000f00
#define TX_TONEGEN1_ATE_TONEGEN_TONE_A_EXP_GET(x)                    (((x) & TX_TONEGEN1_ATE_TONEGEN_TONE_A_EXP_MASK) >> TX_TONEGEN1_ATE_TONEGEN_TONE_A_EXP_LSB)
#define TX_TONEGEN1_ATE_TONEGEN_TONE_A_EXP_SET(x)                    (((0 | (x)) << TX_TONEGEN1_ATE_TONEGEN_TONE_A_EXP_LSB) & TX_TONEGEN1_ATE_TONEGEN_TONE_A_EXP_MASK)
#define TX_TONEGEN1_ATE_TONEGEN_TONE_A_EXP_RESET                     7
#define TX_TONEGEN1_ATE_TONEGEN_TONE_FREQ_MSB                        6
#define TX_TONEGEN1_ATE_TONEGEN_TONE_FREQ_LSB                        0
#define TX_TONEGEN1_ATE_TONEGEN_TONE_FREQ_MASK                       0x0000007f
#define TX_TONEGEN1_ATE_TONEGEN_TONE_FREQ_GET(x)                     (((x) & TX_TONEGEN1_ATE_TONEGEN_TONE_FREQ_MASK) >> TX_TONEGEN1_ATE_TONEGEN_TONE_FREQ_LSB)
#define TX_TONEGEN1_ATE_TONEGEN_TONE_FREQ_SET(x)                     (((0 | (x)) << TX_TONEGEN1_ATE_TONEGEN_TONE_FREQ_LSB) & TX_TONEGEN1_ATE_TONEGEN_TONE_FREQ_MASK)
#define TX_TONEGEN1_ATE_TONEGEN_TONE_FREQ_RESET                      0
#define TX_TONEGEN1_ADDRESS                                          0x000c
#define TX_TONEGEN1_HW_MASK                                          0x7fff0f7f
#define TX_TONEGEN1_SW_MASK                                          0x7fff0f7f
#define TX_TONEGEN1_HW_WRITE_MASK                                    0x00000000
#define TX_TONEGEN1_SW_WRITE_MASK                                    0x7fff0f7f
#define TX_TONEGEN1_RSTMASK                                          0xffffffff
#define TX_TONEGEN1_RESET                                            0x00800700

// 0x0010 (TX_LFTONEGEN0)
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_TAU_K_MSB                     30
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_TAU_K_LSB                     24
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_TAU_K_MASK                    0x7f000000
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_TAU_K_GET(x)                  (((x) & TX_LFTONEGEN0_ATE_TONEGEN_TONE_TAU_K_MASK) >> TX_LFTONEGEN0_ATE_TONEGEN_TONE_TAU_K_LSB)
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_TAU_K_SET(x)                  (((0 | (x)) << TX_LFTONEGEN0_ATE_TONEGEN_TONE_TAU_K_LSB) & TX_LFTONEGEN0_ATE_TONEGEN_TONE_TAU_K_MASK)
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_TAU_K_RESET                   10
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_MAN_MSB                     23
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_MAN_LSB                     16
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_MAN_MASK                    0x00ff0000
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_MAN_GET(x)                  (((x) & TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_MAN_MASK) >> TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_MAN_LSB)
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_MAN_SET(x)                  (((0 | (x)) << TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_MAN_LSB) & TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_MAN_MASK)
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_MAN_RESET                   128
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_EXP_MSB                     11
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_EXP_LSB                     8
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_EXP_MASK                    0x00000f00
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_EXP_GET(x)                  (((x) & TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_EXP_MASK) >> TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_EXP_LSB)
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_EXP_SET(x)                  (((0 | (x)) << TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_EXP_LSB) & TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_EXP_MASK)
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_A_EXP_RESET                   7
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_FREQ_MSB                      6
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_FREQ_LSB                      0
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_FREQ_MASK                     0x0000007f
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_FREQ_GET(x)                   (((x) & TX_LFTONEGEN0_ATE_TONEGEN_TONE_FREQ_MASK) >> TX_LFTONEGEN0_ATE_TONEGEN_TONE_FREQ_LSB)
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_FREQ_SET(x)                   (((0 | (x)) << TX_LFTONEGEN0_ATE_TONEGEN_TONE_FREQ_LSB) & TX_LFTONEGEN0_ATE_TONEGEN_TONE_FREQ_MASK)
#define TX_LFTONEGEN0_ATE_TONEGEN_TONE_FREQ_RESET                    0
#define TX_LFTONEGEN0_ADDRESS                                        0x0010
#define TX_LFTONEGEN0_HW_MASK                                        0x7fff0f7f
#define TX_LFTONEGEN0_SW_MASK                                        0x7fff0f7f
#define TX_LFTONEGEN0_HW_WRITE_MASK                                  0x00000000
#define TX_LFTONEGEN0_SW_WRITE_MASK                                  0x7fff0f7f
#define TX_LFTONEGEN0_RSTMASK                                        0xffffffff
#define TX_LFTONEGEN0_RESET                                          0x0a800700

// 0x0014 (TX_LINEAR_RAMP_I)
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_STEP_MSB                29
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_STEP_LSB                24
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_STEP_MASK               0x3f000000
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_STEP_GET(x)             (((x) & TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_STEP_MASK) >> TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_STEP_LSB)
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_STEP_SET(x)             (((0 | (x)) << TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_STEP_LSB) & TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_STEP_MASK)
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_STEP_RESET              0
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_DWELL_MSB               21
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_DWELL_LSB               12
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_DWELL_MASK              0x003ff000
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_DWELL_GET(x)            (((x) & TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_DWELL_MASK) >> TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_DWELL_LSB)
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_DWELL_SET(x)            (((0 | (x)) << TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_DWELL_LSB) & TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_DWELL_MASK)
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_DWELL_RESET             0
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_INIT_MSB                10
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_INIT_LSB                0
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_INIT_MASK               0x000007ff
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_INIT_GET(x)             (((x) & TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_INIT_MASK) >> TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_INIT_LSB)
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_INIT_SET(x)             (((0 | (x)) << TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_INIT_LSB) & TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_INIT_MASK)
#define TX_LINEAR_RAMP_I_ATE_TONEGEN_LINRAMP_INIT_RESET              0
#define TX_LINEAR_RAMP_I_ADDRESS                                     0x0014
#define TX_LINEAR_RAMP_I_HW_MASK                                     0x3f3ff7ff
#define TX_LINEAR_RAMP_I_SW_MASK                                     0x3f3ff7ff
#define TX_LINEAR_RAMP_I_HW_WRITE_MASK                               0x00000000
#define TX_LINEAR_RAMP_I_SW_WRITE_MASK                               0x3f3ff7ff
#define TX_LINEAR_RAMP_I_RSTMASK                                     0xffffffff
#define TX_LINEAR_RAMP_I_RESET                                       0x00000000

// 0x0018 (TX_LINEAR_RAMP_Q)
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_STEP_MSB                29
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_STEP_LSB                24
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_STEP_MASK               0x3f000000
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_STEP_GET(x)             (((x) & TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_STEP_MASK) >> TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_STEP_LSB)
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_STEP_SET(x)             (((0 | (x)) << TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_STEP_LSB) & TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_STEP_MASK)
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_STEP_RESET              0
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_DWELL_MSB               21
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_DWELL_LSB               12
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_DWELL_MASK              0x003ff000
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_DWELL_GET(x)            (((x) & TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_DWELL_MASK) >> TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_DWELL_LSB)
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_DWELL_SET(x)            (((0 | (x)) << TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_DWELL_LSB) & TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_DWELL_MASK)
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_DWELL_RESET             0
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_INIT_MSB                10
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_INIT_LSB                0
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_INIT_MASK               0x000007ff
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_INIT_GET(x)             (((x) & TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_INIT_MASK) >> TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_INIT_LSB)
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_INIT_SET(x)             (((0 | (x)) << TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_INIT_LSB) & TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_INIT_MASK)
#define TX_LINEAR_RAMP_Q_ATE_TONEGEN_LINRAMP_INIT_RESET              0
#define TX_LINEAR_RAMP_Q_ADDRESS                                     0x0018
#define TX_LINEAR_RAMP_Q_HW_MASK                                     0x3f3ff7ff
#define TX_LINEAR_RAMP_Q_SW_MASK                                     0x3f3ff7ff
#define TX_LINEAR_RAMP_Q_HW_WRITE_MASK                               0x00000000
#define TX_LINEAR_RAMP_Q_SW_WRITE_MASK                               0x3f3ff7ff
#define TX_LINEAR_RAMP_Q_RSTMASK                                     0xffffffff
#define TX_LINEAR_RAMP_Q_RESET                                       0x00000000

// 0x001c (TX_PRBS_MAG)
#define TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_Q_MSB                 25
#define TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_Q_LSB                 16
#define TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_Q_MASK                0x03ff0000
#define TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_Q_GET(x)              (((x) & TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_Q_MASK) >> TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_Q_LSB)
#define TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_Q_SET(x)              (((0 | (x)) << TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_Q_LSB) & TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_Q_MASK)
#define TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_Q_RESET               0
#define TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_I_MSB                 9
#define TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_I_LSB                 0
#define TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_I_MASK                0x000003ff
#define TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_I_GET(x)              (((x) & TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_I_MASK) >> TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_I_LSB)
#define TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_I_SET(x)              (((0 | (x)) << TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_I_LSB) & TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_I_MASK)
#define TX_PRBS_MAG_ATE_TONEGEN_PRBS_MAGNITUDE_I_RESET               0
#define TX_PRBS_MAG_ADDRESS                                          0x001c
#define TX_PRBS_MAG_HW_MASK                                          0x03ff03ff
#define TX_PRBS_MAG_SW_MASK                                          0x03ff03ff
#define TX_PRBS_MAG_HW_WRITE_MASK                                    0x00000000
#define TX_PRBS_MAG_SW_WRITE_MASK                                    0x03ff03ff
#define TX_PRBS_MAG_RSTMASK                                          0xffffffff
#define TX_PRBS_MAG_RESET                                            0x00000000

// 0x0020 (TX_PRBS_SEED_I)
#define TX_PRBS_SEED_I_ATE_TONEGEN_PRBS_SEED_MSB                     30
#define TX_PRBS_SEED_I_ATE_TONEGEN_PRBS_SEED_LSB                     0
#define TX_PRBS_SEED_I_ATE_TONEGEN_PRBS_SEED_MASK                    0x7fffffff
#define TX_PRBS_SEED_I_ATE_TONEGEN_PRBS_SEED_GET(x)                  (((x) & TX_PRBS_SEED_I_ATE_TONEGEN_PRBS_SEED_MASK) >> TX_PRBS_SEED_I_ATE_TONEGEN_PRBS_SEED_LSB)
#define TX_PRBS_SEED_I_ATE_TONEGEN_PRBS_SEED_SET(x)                  (((0 | (x)) << TX_PRBS_SEED_I_ATE_TONEGEN_PRBS_SEED_LSB) & TX_PRBS_SEED_I_ATE_TONEGEN_PRBS_SEED_MASK)
#define TX_PRBS_SEED_I_ATE_TONEGEN_PRBS_SEED_RESET                   1
#define TX_PRBS_SEED_I_ADDRESS                                       0x0020
#define TX_PRBS_SEED_I_HW_MASK                                       0x7fffffff
#define TX_PRBS_SEED_I_SW_MASK                                       0x7fffffff
#define TX_PRBS_SEED_I_HW_WRITE_MASK                                 0x00000000
#define TX_PRBS_SEED_I_SW_WRITE_MASK                                 0x7fffffff
#define TX_PRBS_SEED_I_RSTMASK                                       0xffffffff
#define TX_PRBS_SEED_I_RESET                                         0x00000001

// 0x0024 (TX_PRBS_SEED_Q)
#define TX_PRBS_SEED_Q_ATE_TONEGEN_PRBS_SEED_MSB                     30
#define TX_PRBS_SEED_Q_ATE_TONEGEN_PRBS_SEED_LSB                     0
#define TX_PRBS_SEED_Q_ATE_TONEGEN_PRBS_SEED_MASK                    0x7fffffff
#define TX_PRBS_SEED_Q_ATE_TONEGEN_PRBS_SEED_GET(x)                  (((x) & TX_PRBS_SEED_Q_ATE_TONEGEN_PRBS_SEED_MASK) >> TX_PRBS_SEED_Q_ATE_TONEGEN_PRBS_SEED_LSB)
#define TX_PRBS_SEED_Q_ATE_TONEGEN_PRBS_SEED_SET(x)                  (((0 | (x)) << TX_PRBS_SEED_Q_ATE_TONEGEN_PRBS_SEED_LSB) & TX_PRBS_SEED_Q_ATE_TONEGEN_PRBS_SEED_MASK)
#define TX_PRBS_SEED_Q_ATE_TONEGEN_PRBS_SEED_RESET                   1
#define TX_PRBS_SEED_Q_ADDRESS                                       0x0024
#define TX_PRBS_SEED_Q_HW_MASK                                       0x7fffffff
#define TX_PRBS_SEED_Q_SW_MASK                                       0x7fffffff
#define TX_PRBS_SEED_Q_HW_WRITE_MASK                                 0x00000000
#define TX_PRBS_SEED_Q_SW_WRITE_MASK                                 0x7fffffff
#define TX_PRBS_SEED_Q_RSTMASK                                       0xffffffff
#define TX_PRBS_SEED_Q_RESET                                         0x00000001

// 0x0028 (CMAC_DC_CANCEL)
#define CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_Q_MSB                      25
#define CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_Q_LSB                      16
#define CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_Q_MASK                     0x03ff0000
#define CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_Q_GET(x)                   (((x) & CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_Q_MASK) >> CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_Q_LSB)
#define CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_Q_SET(x)                   (((0 | (x)) << CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_Q_LSB) & CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_Q_MASK)
#define CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_Q_RESET                    0
#define CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_I_MSB                      9
#define CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_I_LSB                      0
#define CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_I_MASK                     0x000003ff
#define CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_I_GET(x)                   (((x) & CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_I_MASK) >> CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_I_LSB)
#define CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_I_SET(x)                   (((0 | (x)) << CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_I_LSB) & CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_I_MASK)
#define CMAC_DC_CANCEL_ATE_CMAC_DC_CANCEL_I_RESET                    0
#define CMAC_DC_CANCEL_ADDRESS                                       0x0028
#define CMAC_DC_CANCEL_HW_MASK                                       0x03ff03ff
#define CMAC_DC_CANCEL_SW_MASK                                       0x03ff03ff
#define CMAC_DC_CANCEL_HW_WRITE_MASK                                 0x03ff03ff
#define CMAC_DC_CANCEL_SW_WRITE_MASK                                 0x03ff03ff
#define CMAC_DC_CANCEL_RSTMASK                                       0xffffffff
#define CMAC_DC_CANCEL_RESET                                         0x00000000

// 0x002c (CMAC_DC_OFFSET)
#define CMAC_DC_OFFSET_ATE_CMAC_DC_CYCLES_MSB                        3
#define CMAC_DC_OFFSET_ATE_CMAC_DC_CYCLES_LSB                        0
#define CMAC_DC_OFFSET_ATE_CMAC_DC_CYCLES_MASK                       0x0000000f
#define CMAC_DC_OFFSET_ATE_CMAC_DC_CYCLES_GET(x)                     (((x) & CMAC_DC_OFFSET_ATE_CMAC_DC_CYCLES_MASK) >> CMAC_DC_OFFSET_ATE_CMAC_DC_CYCLES_LSB)
#define CMAC_DC_OFFSET_ATE_CMAC_DC_CYCLES_SET(x)                     (((0 | (x)) << CMAC_DC_OFFSET_ATE_CMAC_DC_CYCLES_LSB) & CMAC_DC_OFFSET_ATE_CMAC_DC_CYCLES_MASK)
#define CMAC_DC_OFFSET_ATE_CMAC_DC_CYCLES_RESET                      0
#define CMAC_DC_OFFSET_ADDRESS                                       0x002c
#define CMAC_DC_OFFSET_HW_MASK                                       0x0000000f
#define CMAC_DC_OFFSET_SW_MASK                                       0x0000000f
#define CMAC_DC_OFFSET_HW_WRITE_MASK                                 0x00000000
#define CMAC_DC_OFFSET_SW_WRITE_MASK                                 0x0000000f
#define CMAC_DC_OFFSET_RSTMASK                                       0xffffffff
#define CMAC_DC_OFFSET_RESET                                         0x00000000

// 0x0030 (CMAC_CORR)
#define CMAC_CORR_ATE_CMAC_CORR_FREQ_MSB                             13
#define CMAC_CORR_ATE_CMAC_CORR_FREQ_LSB                             8
#define CMAC_CORR_ATE_CMAC_CORR_FREQ_MASK                            0x00003f00
#define CMAC_CORR_ATE_CMAC_CORR_FREQ_GET(x)                          (((x) & CMAC_CORR_ATE_CMAC_CORR_FREQ_MASK) >> CMAC_CORR_ATE_CMAC_CORR_FREQ_LSB)
#define CMAC_CORR_ATE_CMAC_CORR_FREQ_SET(x)                          (((0 | (x)) << CMAC_CORR_ATE_CMAC_CORR_FREQ_LSB) & CMAC_CORR_ATE_CMAC_CORR_FREQ_MASK)
#define CMAC_CORR_ATE_CMAC_CORR_FREQ_RESET                           0
#define CMAC_CORR_ATE_CMAC_CORR_CYCLES_MSB                           4
#define CMAC_CORR_ATE_CMAC_CORR_CYCLES_LSB                           0
#define CMAC_CORR_ATE_CMAC_CORR_CYCLES_MASK                          0x0000001f
#define CMAC_CORR_ATE_CMAC_CORR_CYCLES_GET(x)                        (((x) & CMAC_CORR_ATE_CMAC_CORR_CYCLES_MASK) >> CMAC_CORR_ATE_CMAC_CORR_CYCLES_LSB)
#define CMAC_CORR_ATE_CMAC_CORR_CYCLES_SET(x)                        (((0 | (x)) << CMAC_CORR_ATE_CMAC_CORR_CYCLES_LSB) & CMAC_CORR_ATE_CMAC_CORR_CYCLES_MASK)
#define CMAC_CORR_ATE_CMAC_CORR_CYCLES_RESET                         0
#define CMAC_CORR_ADDRESS                                            0x0030
#define CMAC_CORR_HW_MASK                                            0x00003f1f
#define CMAC_CORR_SW_MASK                                            0x00003f1f
#define CMAC_CORR_HW_WRITE_MASK                                      0x00000000
#define CMAC_CORR_SW_WRITE_MASK                                      0x00003f1f
#define CMAC_CORR_RSTMASK                                            0xffffffff
#define CMAC_CORR_RESET                                              0x00000000

// 0x0034 (CMAC_POWER)
#define CMAC_POWER_ATE_CMAC_POWER_CYCLES_MSB                         3
#define CMAC_POWER_ATE_CMAC_POWER_CYCLES_LSB                         0
#define CMAC_POWER_ATE_CMAC_POWER_CYCLES_MASK                        0x0000000f
#define CMAC_POWER_ATE_CMAC_POWER_CYCLES_GET(x)                      (((x) & CMAC_POWER_ATE_CMAC_POWER_CYCLES_MASK) >> CMAC_POWER_ATE_CMAC_POWER_CYCLES_LSB)
#define CMAC_POWER_ATE_CMAC_POWER_CYCLES_SET(x)                      (((0 | (x)) << CMAC_POWER_ATE_CMAC_POWER_CYCLES_LSB) & CMAC_POWER_ATE_CMAC_POWER_CYCLES_MASK)
#define CMAC_POWER_ATE_CMAC_POWER_CYCLES_RESET                       0
#define CMAC_POWER_ADDRESS                                           0x0034
#define CMAC_POWER_HW_MASK                                           0x0000000f
#define CMAC_POWER_SW_MASK                                           0x0000000f
#define CMAC_POWER_HW_WRITE_MASK                                     0x00000000
#define CMAC_POWER_SW_WRITE_MASK                                     0x0000000f
#define CMAC_POWER_RSTMASK                                           0xffffffff
#define CMAC_POWER_RESET                                             0x00000000

// 0x0038 (CMAC_CROSS_CORR)
#define CMAC_CROSS_CORR_ATE_CMAC_IQ_CYCLES_MSB                       3
#define CMAC_CROSS_CORR_ATE_CMAC_IQ_CYCLES_LSB                       0
#define CMAC_CROSS_CORR_ATE_CMAC_IQ_CYCLES_MASK                      0x0000000f
#define CMAC_CROSS_CORR_ATE_CMAC_IQ_CYCLES_GET(x)                    (((x) & CMAC_CROSS_CORR_ATE_CMAC_IQ_CYCLES_MASK) >> CMAC_CROSS_CORR_ATE_CMAC_IQ_CYCLES_LSB)
#define CMAC_CROSS_CORR_ATE_CMAC_IQ_CYCLES_SET(x)                    (((0 | (x)) << CMAC_CROSS_CORR_ATE_CMAC_IQ_CYCLES_LSB) & CMAC_CROSS_CORR_ATE_CMAC_IQ_CYCLES_MASK)
#define CMAC_CROSS_CORR_ATE_CMAC_IQ_CYCLES_RESET                     0
#define CMAC_CROSS_CORR_ADDRESS                                      0x0038
#define CMAC_CROSS_CORR_HW_MASK                                      0x0000000f
#define CMAC_CROSS_CORR_SW_MASK                                      0x0000000f
#define CMAC_CROSS_CORR_HW_WRITE_MASK                                0x00000000
#define CMAC_CROSS_CORR_SW_WRITE_MASK                                0x0000000f
#define CMAC_CROSS_CORR_RSTMASK                                      0xffffffff
#define CMAC_CROSS_CORR_RESET                                        0x00000000

// 0x003c (CMAC_I2Q2)
#define CMAC_I2Q2_ATE_CMAC_I2Q2_CYCLES_MSB                           3
#define CMAC_I2Q2_ATE_CMAC_I2Q2_CYCLES_LSB                           0
#define CMAC_I2Q2_ATE_CMAC_I2Q2_CYCLES_MASK                          0x0000000f
#define CMAC_I2Q2_ATE_CMAC_I2Q2_CYCLES_GET(x)                        (((x) & CMAC_I2Q2_ATE_CMAC_I2Q2_CYCLES_MASK) >> CMAC_I2Q2_ATE_CMAC_I2Q2_CYCLES_LSB)
#define CMAC_I2Q2_ATE_CMAC_I2Q2_CYCLES_SET(x)                        (((0 | (x)) << CMAC_I2Q2_ATE_CMAC_I2Q2_CYCLES_LSB) & CMAC_I2Q2_ATE_CMAC_I2Q2_CYCLES_MASK)
#define CMAC_I2Q2_ATE_CMAC_I2Q2_CYCLES_RESET                         0
#define CMAC_I2Q2_ADDRESS                                            0x003c
#define CMAC_I2Q2_HW_MASK                                            0x0000000f
#define CMAC_I2Q2_SW_MASK                                            0x0000000f
#define CMAC_I2Q2_HW_WRITE_MASK                                      0x00000000
#define CMAC_I2Q2_SW_WRITE_MASK                                      0x0000000f
#define CMAC_I2Q2_RSTMASK                                            0xffffffff
#define CMAC_I2Q2_RESET                                              0x00000000

// 0x0040 (CMAC_POWER_HPF)
#define CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_WAIT_MSB                   7
#define CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_WAIT_LSB                   4
#define CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_WAIT_MASK                  0x000000f0
#define CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_WAIT_GET(x)                (((x) & CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_WAIT_MASK) >> CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_WAIT_LSB)
#define CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_WAIT_SET(x)                (((0 | (x)) << CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_WAIT_LSB) & CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_WAIT_MASK)
#define CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_WAIT_RESET                 10
#define CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_CYCLES_MSB                 3
#define CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_CYCLES_LSB                 0
#define CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_CYCLES_MASK                0x0000000f
#define CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_CYCLES_GET(x)              (((x) & CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_CYCLES_MASK) >> CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_CYCLES_LSB)
#define CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_CYCLES_SET(x)              (((0 | (x)) << CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_CYCLES_LSB) & CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_CYCLES_MASK)
#define CMAC_POWER_HPF_ATE_CMAC_POWER_HPF_CYCLES_RESET               0
#define CMAC_POWER_HPF_ADDRESS                                       0x0040
#define CMAC_POWER_HPF_HW_MASK                                       0x000000ff
#define CMAC_POWER_HPF_SW_MASK                                       0x000000ff
#define CMAC_POWER_HPF_HW_WRITE_MASK                                 0x00000000
#define CMAC_POWER_HPF_SW_WRITE_MASK                                 0x000000ff
#define CMAC_POWER_HPF_RSTMASK                                       0xffffffff
#define CMAC_POWER_HPF_RESET                                         0x000000a0

// 0x0044 (RXDAC_SET1)
#define RXDAC_SET1_ATE_RXDAC_CAL_MEASURE_TIME_MSB                    19
#define RXDAC_SET1_ATE_RXDAC_CAL_MEASURE_TIME_LSB                    16
#define RXDAC_SET1_ATE_RXDAC_CAL_MEASURE_TIME_MASK                   0x000f0000
#define RXDAC_SET1_ATE_RXDAC_CAL_MEASURE_TIME_GET(x)                 (((x) & RXDAC_SET1_ATE_RXDAC_CAL_MEASURE_TIME_MASK) >> RXDAC_SET1_ATE_RXDAC_CAL_MEASURE_TIME_LSB)
#define RXDAC_SET1_ATE_RXDAC_CAL_MEASURE_TIME_SET(x)                 (((0 | (x)) << RXDAC_SET1_ATE_RXDAC_CAL_MEASURE_TIME_LSB) & RXDAC_SET1_ATE_RXDAC_CAL_MEASURE_TIME_MASK)
#define RXDAC_SET1_ATE_RXDAC_CAL_MEASURE_TIME_RESET                  12
#define RXDAC_SET1_ATE_RXDAC_CAL_WAIT_MSB                            13
#define RXDAC_SET1_ATE_RXDAC_CAL_WAIT_LSB                            8
#define RXDAC_SET1_ATE_RXDAC_CAL_WAIT_MASK                           0x00003f00
#define RXDAC_SET1_ATE_RXDAC_CAL_WAIT_GET(x)                         (((x) & RXDAC_SET1_ATE_RXDAC_CAL_WAIT_MASK) >> RXDAC_SET1_ATE_RXDAC_CAL_WAIT_LSB)
#define RXDAC_SET1_ATE_RXDAC_CAL_WAIT_SET(x)                         (((0 | (x)) << RXDAC_SET1_ATE_RXDAC_CAL_WAIT_LSB) & RXDAC_SET1_ATE_RXDAC_CAL_WAIT_MASK)
#define RXDAC_SET1_ATE_RXDAC_CAL_WAIT_RESET                          0
#define RXDAC_SET1_ATE_RXDAC_HI_GAIN_MSB                             4
#define RXDAC_SET1_ATE_RXDAC_HI_GAIN_LSB                             4
#define RXDAC_SET1_ATE_RXDAC_HI_GAIN_MASK                            0x00000010
#define RXDAC_SET1_ATE_RXDAC_HI_GAIN_GET(x)                          (((x) & RXDAC_SET1_ATE_RXDAC_HI_GAIN_MASK) >> RXDAC_SET1_ATE_RXDAC_HI_GAIN_LSB)
#define RXDAC_SET1_ATE_RXDAC_HI_GAIN_SET(x)                          (((0 | (x)) << RXDAC_SET1_ATE_RXDAC_HI_GAIN_LSB) & RXDAC_SET1_ATE_RXDAC_HI_GAIN_MASK)
#define RXDAC_SET1_ATE_RXDAC_HI_GAIN_RESET                           0
#define RXDAC_SET1_ATE_RXDAC_MUX_MSB                                 1
#define RXDAC_SET1_ATE_RXDAC_MUX_LSB                                 0
#define RXDAC_SET1_ATE_RXDAC_MUX_MASK                                0x00000003
#define RXDAC_SET1_ATE_RXDAC_MUX_GET(x)                              (((x) & RXDAC_SET1_ATE_RXDAC_MUX_MASK) >> RXDAC_SET1_ATE_RXDAC_MUX_LSB)
#define RXDAC_SET1_ATE_RXDAC_MUX_SET(x)                              (((0 | (x)) << RXDAC_SET1_ATE_RXDAC_MUX_LSB) & RXDAC_SET1_ATE_RXDAC_MUX_MASK)
#define RXDAC_SET1_ATE_RXDAC_MUX_RESET                               0
#define RXDAC_SET1_ADDRESS                                           0x0044
#define RXDAC_SET1_HW_MASK                                           0x000f3f13
#define RXDAC_SET1_SW_MASK                                           0x000f3f13
#define RXDAC_SET1_HW_WRITE_MASK                                     0x00000000
#define RXDAC_SET1_SW_WRITE_MASK                                     0x000f3f13
#define RXDAC_SET1_RSTMASK                                           0xffffffff
#define RXDAC_SET1_RESET                                             0x000c0000

// 0x0048 (RXDAC_SET2)
#define RXDAC_SET2_ATE_RXDAC_Q_LOW_MSB                               28
#define RXDAC_SET2_ATE_RXDAC_Q_LOW_LSB                               24
#define RXDAC_SET2_ATE_RXDAC_Q_LOW_MASK                              0x1f000000
#define RXDAC_SET2_ATE_RXDAC_Q_LOW_GET(x)                            (((x) & RXDAC_SET2_ATE_RXDAC_Q_LOW_MASK) >> RXDAC_SET2_ATE_RXDAC_Q_LOW_LSB)
#define RXDAC_SET2_ATE_RXDAC_Q_LOW_SET(x)                            (((0 | (x)) << RXDAC_SET2_ATE_RXDAC_Q_LOW_LSB) & RXDAC_SET2_ATE_RXDAC_Q_LOW_MASK)
#define RXDAC_SET2_ATE_RXDAC_Q_LOW_RESET                             20
#define RXDAC_SET2_ATE_RXDAC_I_LOW_MSB                               20
#define RXDAC_SET2_ATE_RXDAC_I_LOW_LSB                               16
#define RXDAC_SET2_ATE_RXDAC_I_LOW_MASK                              0x001f0000
#define RXDAC_SET2_ATE_RXDAC_I_LOW_GET(x)                            (((x) & RXDAC_SET2_ATE_RXDAC_I_LOW_MASK) >> RXDAC_SET2_ATE_RXDAC_I_LOW_LSB)
#define RXDAC_SET2_ATE_RXDAC_I_LOW_SET(x)                            (((0 | (x)) << RXDAC_SET2_ATE_RXDAC_I_LOW_LSB) & RXDAC_SET2_ATE_RXDAC_I_LOW_MASK)
#define RXDAC_SET2_ATE_RXDAC_I_LOW_RESET                             2
#define RXDAC_SET2_ATE_RXDAC_Q_HI_MSB                                12
#define RXDAC_SET2_ATE_RXDAC_Q_HI_LSB                                8
#define RXDAC_SET2_ATE_RXDAC_Q_HI_MASK                               0x00001f00
#define RXDAC_SET2_ATE_RXDAC_Q_HI_GET(x)                             (((x) & RXDAC_SET2_ATE_RXDAC_Q_HI_MASK) >> RXDAC_SET2_ATE_RXDAC_Q_HI_LSB)
#define RXDAC_SET2_ATE_RXDAC_Q_HI_SET(x)                             (((0 | (x)) << RXDAC_SET2_ATE_RXDAC_Q_HI_LSB) & RXDAC_SET2_ATE_RXDAC_Q_HI_MASK)
#define RXDAC_SET2_ATE_RXDAC_Q_HI_RESET                              20
#define RXDAC_SET2_ATE_RXDAC_I_HI_MSB                                4
#define RXDAC_SET2_ATE_RXDAC_I_HI_LSB                                0
#define RXDAC_SET2_ATE_RXDAC_I_HI_MASK                               0x0000001f
#define RXDAC_SET2_ATE_RXDAC_I_HI_GET(x)                             (((x) & RXDAC_SET2_ATE_RXDAC_I_HI_MASK) >> RXDAC_SET2_ATE_RXDAC_I_HI_LSB)
#define RXDAC_SET2_ATE_RXDAC_I_HI_SET(x)                             (((0 | (x)) << RXDAC_SET2_ATE_RXDAC_I_HI_LSB) & RXDAC_SET2_ATE_RXDAC_I_HI_MASK)
#define RXDAC_SET2_ATE_RXDAC_I_HI_RESET                              2
#define RXDAC_SET2_ADDRESS                                           0x0048
#define RXDAC_SET2_HW_MASK                                           0x1f1f1f1f
#define RXDAC_SET2_SW_MASK                                           0x1f1f1f1f
#define RXDAC_SET2_HW_WRITE_MASK                                     0x1f1f1f1f
#define RXDAC_SET2_SW_WRITE_MASK                                     0x1f1f1f1f
#define RXDAC_SET2_RSTMASK                                           0xffffffff
#define RXDAC_SET2_RESET                                             0x14021402

// 0x004c (RXDAC_LONG_SHIFT)
#define RXDAC_LONG_SHIFT_ATE_RXDAC_Q_STATIC_MSB                      12
#define RXDAC_LONG_SHIFT_ATE_RXDAC_Q_STATIC_LSB                      8
#define RXDAC_LONG_SHIFT_ATE_RXDAC_Q_STATIC_MASK                     0x00001f00
#define RXDAC_LONG_SHIFT_ATE_RXDAC_Q_STATIC_GET(x)                   (((x) & RXDAC_LONG_SHIFT_ATE_RXDAC_Q_STATIC_MASK) >> RXDAC_LONG_SHIFT_ATE_RXDAC_Q_STATIC_LSB)
#define RXDAC_LONG_SHIFT_ATE_RXDAC_Q_STATIC_SET(x)                   (((0 | (x)) << RXDAC_LONG_SHIFT_ATE_RXDAC_Q_STATIC_LSB) & RXDAC_LONG_SHIFT_ATE_RXDAC_Q_STATIC_MASK)
#define RXDAC_LONG_SHIFT_ATE_RXDAC_Q_STATIC_RESET                    20
#define RXDAC_LONG_SHIFT_ATE_RXDAC_I_STATIC_MSB                      4
#define RXDAC_LONG_SHIFT_ATE_RXDAC_I_STATIC_LSB                      0
#define RXDAC_LONG_SHIFT_ATE_RXDAC_I_STATIC_MASK                     0x0000001f
#define RXDAC_LONG_SHIFT_ATE_RXDAC_I_STATIC_GET(x)                   (((x) & RXDAC_LONG_SHIFT_ATE_RXDAC_I_STATIC_MASK) >> RXDAC_LONG_SHIFT_ATE_RXDAC_I_STATIC_LSB)
#define RXDAC_LONG_SHIFT_ATE_RXDAC_I_STATIC_SET(x)                   (((0 | (x)) << RXDAC_LONG_SHIFT_ATE_RXDAC_I_STATIC_LSB) & RXDAC_LONG_SHIFT_ATE_RXDAC_I_STATIC_MASK)
#define RXDAC_LONG_SHIFT_ATE_RXDAC_I_STATIC_RESET                    2
#define RXDAC_LONG_SHIFT_ADDRESS                                     0x004c
#define RXDAC_LONG_SHIFT_HW_MASK                                     0x00001f1f
#define RXDAC_LONG_SHIFT_SW_MASK                                     0x00001f1f
#define RXDAC_LONG_SHIFT_HW_WRITE_MASK                               0x00000000
#define RXDAC_LONG_SHIFT_SW_WRITE_MASK                               0x00001f1f
#define RXDAC_LONG_SHIFT_RSTMASK                                     0xffffffff
#define RXDAC_LONG_SHIFT_RESET                                       0x00001402

// 0x0050 (CMAC_RESULTS_I)
#define CMAC_RESULTS_I_ATE_CMAC_RESULTS_MSB                          31
#define CMAC_RESULTS_I_ATE_CMAC_RESULTS_LSB                          0
#define CMAC_RESULTS_I_ATE_CMAC_RESULTS_MASK                         0xffffffff
#define CMAC_RESULTS_I_ATE_CMAC_RESULTS_GET(x)                       (((x) & CMAC_RESULTS_I_ATE_CMAC_RESULTS_MASK) >> CMAC_RESULTS_I_ATE_CMAC_RESULTS_LSB)
#define CMAC_RESULTS_I_ATE_CMAC_RESULTS_SET(x)                       (((0 | (x)) << CMAC_RESULTS_I_ATE_CMAC_RESULTS_LSB) & CMAC_RESULTS_I_ATE_CMAC_RESULTS_MASK)
#define CMAC_RESULTS_I_ATE_CMAC_RESULTS_RESET                        0
#define CMAC_RESULTS_I_ADDRESS                                       0x0050
#define CMAC_RESULTS_I_HW_MASK                                       0xffffffff
#define CMAC_RESULTS_I_SW_MASK                                       0xffffffff
#define CMAC_RESULTS_I_HW_WRITE_MASK                                 0xffffffff
#define CMAC_RESULTS_I_SW_WRITE_MASK                                 0xffffffff
#define CMAC_RESULTS_I_RSTMASK                                       0xffffffff
#define CMAC_RESULTS_I_RESET                                         0x00000000

// 0x0054 (CMAC_RESULTS_Q)
#define CMAC_RESULTS_Q_ATE_CMAC_RESULTS_MSB                          31
#define CMAC_RESULTS_Q_ATE_CMAC_RESULTS_LSB                          0
#define CMAC_RESULTS_Q_ATE_CMAC_RESULTS_MASK                         0xffffffff
#define CMAC_RESULTS_Q_ATE_CMAC_RESULTS_GET(x)                       (((x) & CMAC_RESULTS_Q_ATE_CMAC_RESULTS_MASK) >> CMAC_RESULTS_Q_ATE_CMAC_RESULTS_LSB)
#define CMAC_RESULTS_Q_ATE_CMAC_RESULTS_SET(x)                       (((0 | (x)) << CMAC_RESULTS_Q_ATE_CMAC_RESULTS_LSB) & CMAC_RESULTS_Q_ATE_CMAC_RESULTS_MASK)
#define CMAC_RESULTS_Q_ATE_CMAC_RESULTS_RESET                        0
#define CMAC_RESULTS_Q_ADDRESS                                       0x0054
#define CMAC_RESULTS_Q_HW_MASK                                       0xffffffff
#define CMAC_RESULTS_Q_SW_MASK                                       0xffffffff
#define CMAC_RESULTS_Q_HW_WRITE_MASK                                 0xffffffff
#define CMAC_RESULTS_Q_SW_WRITE_MASK                                 0xffffffff
#define CMAC_RESULTS_Q_RSTMASK                                       0xffffffff
#define CMAC_RESULTS_Q_RESET                                         0x00000000


#endif /* _RBIST_REGFILE_H_ */
