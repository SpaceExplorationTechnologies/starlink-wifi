//                                                                             
// File:       ./CLK_reg_csr.vrh                                               
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:42:28 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             CLK_reg_csr.rdl                                                 
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/radio_peregrine/rtl/srif/blueprint/CLK_reg.rdl
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


#ifndef _CLK_REG_CSR_H_
#define _CLK_REG_CSR_H_
// 0x0000 (CLK1)
#define CLK1_CLKMOD_ADC_CLK_DIV2_MSB                                 31
#define CLK1_CLKMOD_ADC_CLK_DIV2_LSB                                 31
#define CLK1_CLKMOD_ADC_CLK_DIV2_MASK                                0x80000000
#define CLK1_CLKMOD_ADC_CLK_DIV2_GET(x)                              (((x) & CLK1_CLKMOD_ADC_CLK_DIV2_MASK) >> CLK1_CLKMOD_ADC_CLK_DIV2_LSB)
#define CLK1_CLKMOD_ADC_CLK_DIV2_SET(x)                              (((0 | (x)) << CLK1_CLKMOD_ADC_CLK_DIV2_LSB) & CLK1_CLKMOD_ADC_CLK_DIV2_MASK)
#define CLK1_CLKMOD_ADC_CLK_DIV2_RESET                               0
#define CLK1_CLKMOD_ADC_CLK_PHASE_MSB                                30
#define CLK1_CLKMOD_ADC_CLK_PHASE_LSB                                29
#define CLK1_CLKMOD_ADC_CLK_PHASE_MASK                               0x60000000
#define CLK1_CLKMOD_ADC_CLK_PHASE_GET(x)                             (((x) & CLK1_CLKMOD_ADC_CLK_PHASE_MASK) >> CLK1_CLKMOD_ADC_CLK_PHASE_LSB)
#define CLK1_CLKMOD_ADC_CLK_PHASE_SET(x)                             (((0 | (x)) << CLK1_CLKMOD_ADC_CLK_PHASE_LSB) & CLK1_CLKMOD_ADC_CLK_PHASE_MASK)
#define CLK1_CLKMOD_ADC_CLK_PHASE_RESET                              0
#define CLK1_CLKMOD_ADC_CLK_SEL_MSB                                  28
#define CLK1_CLKMOD_ADC_CLK_SEL_LSB                                  28
#define CLK1_CLKMOD_ADC_CLK_SEL_MASK                                 0x10000000
#define CLK1_CLKMOD_ADC_CLK_SEL_GET(x)                               (((x) & CLK1_CLKMOD_ADC_CLK_SEL_MASK) >> CLK1_CLKMOD_ADC_CLK_SEL_LSB)
#define CLK1_CLKMOD_ADC_CLK_SEL_SET(x)                               (((0 | (x)) << CLK1_CLKMOD_ADC_CLK_SEL_LSB) & CLK1_CLKMOD_ADC_CLK_SEL_MASK)
#define CLK1_CLKMOD_ADC_CLK_SEL_RESET                                0
#define CLK1_CLKMOD_ADCCLKDUTY_MSB                                   27
#define CLK1_CLKMOD_ADCCLKDUTY_LSB                                   27
#define CLK1_CLKMOD_ADCCLKDUTY_MASK                                  0x08000000
#define CLK1_CLKMOD_ADCCLKDUTY_GET(x)                                (((x) & CLK1_CLKMOD_ADCCLKDUTY_MASK) >> CLK1_CLKMOD_ADCCLKDUTY_LSB)
#define CLK1_CLKMOD_ADCCLKDUTY_SET(x)                                (((0 | (x)) << CLK1_CLKMOD_ADCCLKDUTY_LSB) & CLK1_CLKMOD_ADCCLKDUTY_MASK)
#define CLK1_CLKMOD_ADCCLKDUTY_RESET                                 0
#define CLK1_CLKMOD_DAC_CLK_DIV2_MSB                                 26
#define CLK1_CLKMOD_DAC_CLK_DIV2_LSB                                 26
#define CLK1_CLKMOD_DAC_CLK_DIV2_MASK                                0x04000000
#define CLK1_CLKMOD_DAC_CLK_DIV2_GET(x)                              (((x) & CLK1_CLKMOD_DAC_CLK_DIV2_MASK) >> CLK1_CLKMOD_DAC_CLK_DIV2_LSB)
#define CLK1_CLKMOD_DAC_CLK_DIV2_SET(x)                              (((0 | (x)) << CLK1_CLKMOD_DAC_CLK_DIV2_LSB) & CLK1_CLKMOD_DAC_CLK_DIV2_MASK)
#define CLK1_CLKMOD_DAC_CLK_DIV2_RESET                               0
#define CLK1_CLKMOD_DAC_CLK_PHASE_MSB                                25
#define CLK1_CLKMOD_DAC_CLK_PHASE_LSB                                24
#define CLK1_CLKMOD_DAC_CLK_PHASE_MASK                               0x03000000
#define CLK1_CLKMOD_DAC_CLK_PHASE_GET(x)                             (((x) & CLK1_CLKMOD_DAC_CLK_PHASE_MASK) >> CLK1_CLKMOD_DAC_CLK_PHASE_LSB)
#define CLK1_CLKMOD_DAC_CLK_PHASE_SET(x)                             (((0 | (x)) << CLK1_CLKMOD_DAC_CLK_PHASE_LSB) & CLK1_CLKMOD_DAC_CLK_PHASE_MASK)
#define CLK1_CLKMOD_DAC_CLK_PHASE_RESET                              0
#define CLK1_CLKMOD_SPURFREQ_MSB                                     23
#define CLK1_CLKMOD_SPURFREQ_LSB                                     22
#define CLK1_CLKMOD_SPURFREQ_MASK                                    0x00c00000
#define CLK1_CLKMOD_SPURFREQ_GET(x)                                  (((x) & CLK1_CLKMOD_SPURFREQ_MASK) >> CLK1_CLKMOD_SPURFREQ_LSB)
#define CLK1_CLKMOD_SPURFREQ_SET(x)                                  (((0 | (x)) << CLK1_CLKMOD_SPURFREQ_LSB) & CLK1_CLKMOD_SPURFREQ_MASK)
#define CLK1_CLKMOD_SPURFREQ_RESET                                   0
#define CLK1_CLKMOD_SPURON_MSB                                       21
#define CLK1_CLKMOD_SPURON_LSB                                       21
#define CLK1_CLKMOD_SPURON_MASK                                      0x00200000
#define CLK1_CLKMOD_SPURON_GET(x)                                    (((x) & CLK1_CLKMOD_SPURON_MASK) >> CLK1_CLKMOD_SPURON_LSB)
#define CLK1_CLKMOD_SPURON_SET(x)                                    (((0 | (x)) << CLK1_CLKMOD_SPURON_LSB) & CLK1_CLKMOD_SPURON_MASK)
#define CLK1_CLKMOD_SPURON_RESET                                     0
#define CLK1_CLKMOD_PLLBYPASS_MSB                                    20
#define CLK1_CLKMOD_PLLBYPASS_LSB                                    20
#define CLK1_CLKMOD_PLLBYPASS_MASK                                   0x00100000
#define CLK1_CLKMOD_PLLBYPASS_GET(x)                                 (((x) & CLK1_CLKMOD_PLLBYPASS_MASK) >> CLK1_CLKMOD_PLLBYPASS_LSB)
#define CLK1_CLKMOD_PLLBYPASS_SET(x)                                 (((0 | (x)) << CLK1_CLKMOD_PLLBYPASS_LSB) & CLK1_CLKMOD_PLLBYPASS_MASK)
#define CLK1_CLKMOD_PLLBYPASS_RESET                                  0
#define CLK1_CLKMOD_LOCALMODE_MSB                                    19
#define CLK1_CLKMOD_LOCALMODE_LSB                                    19
#define CLK1_CLKMOD_LOCALMODE_MASK                                   0x00080000
#define CLK1_CLKMOD_LOCALMODE_GET(x)                                 (((x) & CLK1_CLKMOD_LOCALMODE_MASK) >> CLK1_CLKMOD_LOCALMODE_LSB)
#define CLK1_CLKMOD_LOCALMODE_SET(x)                                 (((0 | (x)) << CLK1_CLKMOD_LOCALMODE_LSB) & CLK1_CLKMOD_LOCALMODE_MASK)
#define CLK1_CLKMOD_LOCALMODE_RESET                                  0
#define CLK1_CLKMOD_CODEC_PWD_MSB                                    18
#define CLK1_CLKMOD_CODEC_PWD_LSB                                    18
#define CLK1_CLKMOD_CODEC_PWD_MASK                                   0x00040000
#define CLK1_CLKMOD_CODEC_PWD_GET(x)                                 (((x) & CLK1_CLKMOD_CODEC_PWD_MASK) >> CLK1_CLKMOD_CODEC_PWD_LSB)
#define CLK1_CLKMOD_CODEC_PWD_SET(x)                                 (((0 | (x)) << CLK1_CLKMOD_CODEC_PWD_LSB) & CLK1_CLKMOD_CODEC_PWD_MASK)
#define CLK1_CLKMOD_CODEC_PWD_RESET                                  1
#define CLK1_CLKMOD_CODEC_SRC_MSB                                    17
#define CLK1_CLKMOD_CODEC_SRC_LSB                                    17
#define CLK1_CLKMOD_CODEC_SRC_MASK                                   0x00020000
#define CLK1_CLKMOD_CODEC_SRC_GET(x)                                 (((x) & CLK1_CLKMOD_CODEC_SRC_MASK) >> CLK1_CLKMOD_CODEC_SRC_LSB)
#define CLK1_CLKMOD_CODEC_SRC_SET(x)                                 (((0 | (x)) << CLK1_CLKMOD_CODEC_SRC_LSB) & CLK1_CLKMOD_CODEC_SRC_MASK)
#define CLK1_CLKMOD_CODEC_SRC_RESET                                  0
#define CLK1_CLKMOD_CODEC_MODE_MSB                                   16
#define CLK1_CLKMOD_CODEC_MODE_LSB                                   16
#define CLK1_CLKMOD_CODEC_MODE_MASK                                  0x00010000
#define CLK1_CLKMOD_CODEC_MODE_GET(x)                                (((x) & CLK1_CLKMOD_CODEC_MODE_MASK) >> CLK1_CLKMOD_CODEC_MODE_LSB)
#define CLK1_CLKMOD_CODEC_MODE_SET(x)                                (((0 | (x)) << CLK1_CLKMOD_CODEC_MODE_LSB) & CLK1_CLKMOD_CODEC_MODE_MASK)
#define CLK1_CLKMOD_CODEC_MODE_RESET                                 0
#define CLK1_CLKMOD_TESTCLK_EN_MSB                                   15
#define CLK1_CLKMOD_TESTCLK_EN_LSB                                   15
#define CLK1_CLKMOD_TESTCLK_EN_MASK                                  0x00008000
#define CLK1_CLKMOD_TESTCLK_EN_GET(x)                                (((x) & CLK1_CLKMOD_TESTCLK_EN_MASK) >> CLK1_CLKMOD_TESTCLK_EN_LSB)
#define CLK1_CLKMOD_TESTCLK_EN_SET(x)                                (((0 | (x)) << CLK1_CLKMOD_TESTCLK_EN_LSB) & CLK1_CLKMOD_TESTCLK_EN_MASK)
#define CLK1_CLKMOD_TESTCLK_EN_RESET                                 0
#define CLK1_CLKMOD_TESTCLK_SEL_MSB                                  14
#define CLK1_CLKMOD_TESTCLK_SEL_LSB                                  12
#define CLK1_CLKMOD_TESTCLK_SEL_MASK                                 0x00007000
#define CLK1_CLKMOD_TESTCLK_SEL_GET(x)                               (((x) & CLK1_CLKMOD_TESTCLK_SEL_MASK) >> CLK1_CLKMOD_TESTCLK_SEL_LSB)
#define CLK1_CLKMOD_TESTCLK_SEL_SET(x)                               (((0 | (x)) << CLK1_CLKMOD_TESTCLK_SEL_LSB) & CLK1_CLKMOD_TESTCLK_SEL_MASK)
#define CLK1_CLKMOD_TESTCLK_SEL_RESET                                0
#define CLK1_CLKMOD_USEPLLOUT_MSB                                    11
#define CLK1_CLKMOD_USEPLLOUT_LSB                                    11
#define CLK1_CLKMOD_USEPLLOUT_MASK                                   0x00000800
#define CLK1_CLKMOD_USEPLLOUT_GET(x)                                 (((x) & CLK1_CLKMOD_USEPLLOUT_MASK) >> CLK1_CLKMOD_USEPLLOUT_LSB)
#define CLK1_CLKMOD_USEPLLOUT_SET(x)                                 (((0 | (x)) << CLK1_CLKMOD_USEPLLOUT_LSB) & CLK1_CLKMOD_USEPLLOUT_MASK)
#define CLK1_CLKMOD_USEPLLOUT_RESET                                  0
#define CLK1_CLKMOD_FORCE_EN_MSB                                     10
#define CLK1_CLKMOD_FORCE_EN_LSB                                     10
#define CLK1_CLKMOD_FORCE_EN_MASK                                    0x00000400
#define CLK1_CLKMOD_FORCE_EN_GET(x)                                  (((x) & CLK1_CLKMOD_FORCE_EN_MASK) >> CLK1_CLKMOD_FORCE_EN_LSB)
#define CLK1_CLKMOD_FORCE_EN_SET(x)                                  (((0 | (x)) << CLK1_CLKMOD_FORCE_EN_LSB) & CLK1_CLKMOD_FORCE_EN_MASK)
#define CLK1_CLKMOD_FORCE_EN_RESET                                   0
#define CLK1_PLL_ATB_MSB                                             9
#define CLK1_PLL_ATB_LSB                                             8
#define CLK1_PLL_ATB_MASK                                            0x00000300
#define CLK1_PLL_ATB_GET(x)                                          (((x) & CLK1_PLL_ATB_MASK) >> CLK1_PLL_ATB_LSB)
#define CLK1_PLL_ATB_SET(x)                                          (((0 | (x)) << CLK1_PLL_ATB_LSB) & CLK1_PLL_ATB_MASK)
#define CLK1_PLL_ATB_RESET                                           0
#define CLK1_PLL_ICP_MSB                                             7
#define CLK1_PLL_ICP_LSB                                             5
#define CLK1_PLL_ICP_MASK                                            0x000000e0
#define CLK1_PLL_ICP_GET(x)                                          (((x) & CLK1_PLL_ICP_MASK) >> CLK1_PLL_ICP_LSB)
#define CLK1_PLL_ICP_SET(x)                                          (((0 | (x)) << CLK1_PLL_ICP_LSB) & CLK1_PLL_ICP_MASK)
#define CLK1_PLL_ICP_RESET                                           1
#define CLK1_PLL_FILTER_MSB                                          4
#define CLK1_PLL_FILTER_LSB                                          0
#define CLK1_PLL_FILTER_MASK                                         0x0000001f
#define CLK1_PLL_FILTER_GET(x)                                       (((x) & CLK1_PLL_FILTER_MASK) >> CLK1_PLL_FILTER_LSB)
#define CLK1_PLL_FILTER_SET(x)                                       (((0 | (x)) << CLK1_PLL_FILTER_LSB) & CLK1_PLL_FILTER_MASK)
#define CLK1_PLL_FILTER_RESET                                        7
#define CLK1_ADDRESS                                                 0x0000
#define CLK1_HW_MASK                                                 0xffffffff
#define CLK1_SW_MASK                                                 0xffffffff
#define CLK1_HW_WRITE_MASK                                           0x00000000
#define CLK1_SW_WRITE_MASK                                           0xffffffff
#define CLK1_RSTMASK                                                 0xffffffff
#define CLK1_RESET                                                   0x00040027

// 0x0004 (CLK2)
#define CLK2_PLL_REFDIV_MSB                                          31
#define CLK2_PLL_REFDIV_LSB                                          28
#define CLK2_PLL_REFDIV_MASK                                         0xf0000000
#define CLK2_PLL_REFDIV_GET(x)                                       (((x) & CLK2_PLL_REFDIV_MASK) >> CLK2_PLL_REFDIV_LSB)
#define CLK2_PLL_REFDIV_SET(x)                                       (((0 | (x)) << CLK2_PLL_REFDIV_LSB) & CLK2_PLL_REFDIV_MASK)
#define CLK2_PLL_REFDIV_RESET                                        3
#define CLK2_PLL_DIV_MSB                                             27
#define CLK2_PLL_DIV_LSB                                             18
#define CLK2_PLL_DIV_MASK                                            0x0ffc0000
#define CLK2_PLL_DIV_GET(x)                                          (((x) & CLK2_PLL_DIV_MASK) >> CLK2_PLL_DIV_LSB)
#define CLK2_PLL_DIV_SET(x)                                          (((0 | (x)) << CLK2_PLL_DIV_LSB) & CLK2_PLL_DIV_MASK)
#define CLK2_PLL_DIV_RESET                                           28
#define CLK2_PLL_FRAC_MSB                                            17
#define CLK2_PLL_FRAC_LSB                                            3
#define CLK2_PLL_FRAC_MASK                                           0x0003fff8
#define CLK2_PLL_FRAC_GET(x)                                         (((x) & CLK2_PLL_FRAC_MASK) >> CLK2_PLL_FRAC_LSB)
#define CLK2_PLL_FRAC_SET(x)                                         (((0 | (x)) << CLK2_PLL_FRAC_LSB) & CLK2_PLL_FRAC_MASK)
#define CLK2_PLL_FRAC_RESET                                          26214
#define CLK2_PLL_HIFREQ_EN_MSB                                       2
#define CLK2_PLL_HIFREQ_EN_LSB                                       2
#define CLK2_PLL_HIFREQ_EN_MASK                                      0x00000004
#define CLK2_PLL_HIFREQ_EN_GET(x)                                    (((x) & CLK2_PLL_HIFREQ_EN_MASK) >> CLK2_PLL_HIFREQ_EN_LSB)
#define CLK2_PLL_HIFREQ_EN_SET(x)                                    (((0 | (x)) << CLK2_PLL_HIFREQ_EN_LSB) & CLK2_PLL_HIFREQ_EN_MASK)
#define CLK2_PLL_HIFREQ_EN_RESET                                     0
#define CLK2_PLL_KVCO_MSB                                            1
#define CLK2_PLL_KVCO_LSB                                            0
#define CLK2_PLL_KVCO_MASK                                           0x00000003
#define CLK2_PLL_KVCO_GET(x)                                         (((x) & CLK2_PLL_KVCO_MASK) >> CLK2_PLL_KVCO_LSB)
#define CLK2_PLL_KVCO_SET(x)                                         (((0 | (x)) << CLK2_PLL_KVCO_LSB) & CLK2_PLL_KVCO_MASK)
#define CLK2_PLL_KVCO_RESET                                          0
#define CLK2_ADDRESS                                                 0x0004
#define CLK2_HW_MASK                                                 0xffffffff
#define CLK2_SW_MASK                                                 0xffffffff
#define CLK2_HW_WRITE_MASK                                           0x00000000
#define CLK2_SW_WRITE_MASK                                           0xffffffff
#define CLK2_RSTMASK                                                 0xffffffff
#define CLK2_RESET                                                   0x30733330

// 0x0008 (CLK3)
#define CLK3_PLL_SVREG_MSB                                           31
#define CLK3_PLL_SVREG_LSB                                           31
#define CLK3_PLL_SVREG_MASK                                          0x80000000
#define CLK3_PLL_SVREG_GET(x)                                        (((x) & CLK3_PLL_SVREG_MASK) >> CLK3_PLL_SVREG_LSB)
#define CLK3_PLL_SVREG_SET(x)                                        (((0 | (x)) << CLK3_PLL_SVREG_LSB) & CLK3_PLL_SVREG_MASK)
#define CLK3_PLL_SVREG_RESET                                         0
#define CLK3_XTAL_BIAS2X_MSB                                         30
#define CLK3_XTAL_BIAS2X_LSB                                         30
#define CLK3_XTAL_BIAS2X_MASK                                        0x40000000
#define CLK3_XTAL_BIAS2X_GET(x)                                      (((x) & CLK3_XTAL_BIAS2X_MASK) >> CLK3_XTAL_BIAS2X_LSB)
#define CLK3_XTAL_BIAS2X_SET(x)                                      (((0 | (x)) << CLK3_XTAL_BIAS2X_LSB) & CLK3_XTAL_BIAS2X_MASK)
#define CLK3_XTAL_BIAS2X_RESET                                       1
#define CLK3_XTAL_CAPINDAC_MSB                                       29
#define CLK3_XTAL_CAPINDAC_LSB                                       23
#define CLK3_XTAL_CAPINDAC_MASK                                      0x3f800000
#define CLK3_XTAL_CAPINDAC_GET(x)                                    (((x) & CLK3_XTAL_CAPINDAC_MASK) >> CLK3_XTAL_CAPINDAC_LSB)
#define CLK3_XTAL_CAPINDAC_SET(x)                                    (((0 | (x)) << CLK3_XTAL_CAPINDAC_LSB) & CLK3_XTAL_CAPINDAC_MASK)
#define CLK3_XTAL_CAPINDAC_RESET                                     75
#define CLK3_XTAL_CAPOUTDAC_MSB                                      22
#define CLK3_XTAL_CAPOUTDAC_LSB                                      16
#define CLK3_XTAL_CAPOUTDAC_MASK                                     0x007f0000
#define CLK3_XTAL_CAPOUTDAC_GET(x)                                   (((x) & CLK3_XTAL_CAPOUTDAC_MASK) >> CLK3_XTAL_CAPOUTDAC_LSB)
#define CLK3_XTAL_CAPOUTDAC_SET(x)                                   (((0 | (x)) << CLK3_XTAL_CAPOUTDAC_LSB) & CLK3_XTAL_CAPOUTDAC_MASK)
#define CLK3_XTAL_CAPOUTDAC_RESET                                    75
#define CLK3_XTAL_DRVPNR_MSB                                         15
#define CLK3_XTAL_DRVPNR_LSB                                         14
#define CLK3_XTAL_DRVPNR_MASK                                        0x0000c000
#define CLK3_XTAL_DRVPNR_GET(x)                                      (((x) & CLK3_XTAL_DRVPNR_MASK) >> CLK3_XTAL_DRVPNR_LSB)
#define CLK3_XTAL_DRVPNR_SET(x)                                      (((0 | (x)) << CLK3_XTAL_DRVPNR_LSB) & CLK3_XTAL_DRVPNR_MASK)
#define CLK3_XTAL_DRVPNR_RESET                                       1
#define CLK3_XTAL_LOCALBIAS_MSB                                      13
#define CLK3_XTAL_LOCALBIAS_LSB                                      13
#define CLK3_XTAL_LOCALBIAS_MASK                                     0x00002000
#define CLK3_XTAL_LOCALBIAS_GET(x)                                   (((x) & CLK3_XTAL_LOCALBIAS_MASK) >> CLK3_XTAL_LOCALBIAS_LSB)
#define CLK3_XTAL_LOCALBIAS_SET(x)                                   (((0 | (x)) << CLK3_XTAL_LOCALBIAS_LSB) & CLK3_XTAL_LOCALBIAS_MASK)
#define CLK3_XTAL_LOCALBIAS_RESET                                    1
#define CLK3_XTAL_NOTCXODET_MSB                                      12
#define CLK3_XTAL_NOTCXODET_LSB                                      12
#define CLK3_XTAL_NOTCXODET_MASK                                     0x00001000
#define CLK3_XTAL_NOTCXODET_GET(x)                                   (((x) & CLK3_XTAL_NOTCXODET_MASK) >> CLK3_XTAL_NOTCXODET_LSB)
#define CLK3_XTAL_NOTCXODET_SET(x)                                   (((0 | (x)) << CLK3_XTAL_NOTCXODET_LSB) & CLK3_XTAL_NOTCXODET_MASK)
#define CLK3_XTAL_NOTCXODET_RESET                                    0
#define CLK3_XTAL_PWDCLKD_MSB                                        11
#define CLK3_XTAL_PWDCLKD_LSB                                        11
#define CLK3_XTAL_PWDCLKD_MASK                                       0x00000800
#define CLK3_XTAL_PWDCLKD_GET(x)                                     (((x) & CLK3_XTAL_PWDCLKD_MASK) >> CLK3_XTAL_PWDCLKD_LSB)
#define CLK3_XTAL_PWDCLKD_SET(x)                                     (((0 | (x)) << CLK3_XTAL_PWDCLKD_LSB) & CLK3_XTAL_PWDCLKD_MASK)
#define CLK3_XTAL_PWDCLKD_RESET                                      0
#define CLK3_XTAL_SVREG_MSB                                          10
#define CLK3_XTAL_SVREG_LSB                                          10
#define CLK3_XTAL_SVREG_MASK                                         0x00000400
#define CLK3_XTAL_SVREG_GET(x)                                       (((x) & CLK3_XTAL_SVREG_MASK) >> CLK3_XTAL_SVREG_LSB)
#define CLK3_XTAL_SVREG_SET(x)                                       (((0 | (x)) << CLK3_XTAL_SVREG_LSB) & CLK3_XTAL_SVREG_MASK)
#define CLK3_XTAL_SVREG_RESET                                        0
#define CLK3_XTAL_HIGHZ_MSB                                          9
#define CLK3_XTAL_HIGHZ_LSB                                          9
#define CLK3_XTAL_HIGHZ_MASK                                         0x00000200
#define CLK3_XTAL_HIGHZ_GET(x)                                       (((x) & CLK3_XTAL_HIGHZ_MASK) >> CLK3_XTAL_HIGHZ_LSB)
#define CLK3_XTAL_HIGHZ_SET(x)                                       (((0 | (x)) << CLK3_XTAL_HIGHZ_LSB) & CLK3_XTAL_HIGHZ_MASK)
#define CLK3_XTAL_HIGHZ_RESET                                        0
#define CLK3_XTAL_LBIAS2X_MSB                                        8
#define CLK3_XTAL_LBIAS2X_LSB                                        8
#define CLK3_XTAL_LBIAS2X_MASK                                       0x00000100
#define CLK3_XTAL_LBIAS2X_GET(x)                                     (((x) & CLK3_XTAL_LBIAS2X_MASK) >> CLK3_XTAL_LBIAS2X_LSB)
#define CLK3_XTAL_LBIAS2X_SET(x)                                     (((0 | (x)) << CLK3_XTAL_LBIAS2X_LSB) & CLK3_XTAL_LBIAS2X_MASK)
#define CLK3_XTAL_LBIAS2X_RESET                                      0
#define CLK3_REFCLK_TO_ADC_MSB                                       7
#define CLK3_REFCLK_TO_ADC_LSB                                       7
#define CLK3_REFCLK_TO_ADC_MASK                                      0x00000080
#define CLK3_REFCLK_TO_ADC_GET(x)                                    (((x) & CLK3_REFCLK_TO_ADC_MASK) >> CLK3_REFCLK_TO_ADC_LSB)
#define CLK3_REFCLK_TO_ADC_SET(x)                                    (((0 | (x)) << CLK3_REFCLK_TO_ADC_LSB) & CLK3_REFCLK_TO_ADC_MASK)
#define CLK3_REFCLK_TO_ADC_RESET                                     0
#define CLK3_SPARE3_MSB                                              6
#define CLK3_SPARE3_LSB                                              0
#define CLK3_SPARE3_MASK                                             0x0000007f
#define CLK3_SPARE3_GET(x)                                           (((x) & CLK3_SPARE3_MASK) >> CLK3_SPARE3_LSB)
#define CLK3_SPARE3_SET(x)                                           (((0 | (x)) << CLK3_SPARE3_LSB) & CLK3_SPARE3_MASK)
#define CLK3_SPARE3_RESET                                            49
#define CLK3_ADDRESS                                                 0x0008
#define CLK3_HW_MASK                                                 0xffffffff
#define CLK3_SW_MASK                                                 0xffffffff
#define CLK3_HW_WRITE_MASK                                           0x00000000
#define CLK3_SW_WRITE_MASK                                           0xffffffff
#define CLK3_RSTMASK                                                 0xffffffff
#define CLK3_RESET                                                   0x65cb6031


#endif /* _CLK_REG_CSR_H_ */
