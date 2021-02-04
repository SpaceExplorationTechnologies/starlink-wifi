//                                                                             
// File:       ./rtc_wlan_reg.vrh                                              
// Creator:    shung                                                           
// Time:       Monday Apr 23, 2012 [6:26:25 pm]                                
//                                                                             
// Path:       /trees/shung/shung-dev/chips/peregrine/1.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux/blueprint -odir . -codegen   
//             ath_vrh.codegen -ath_vrh -Wdesc -I                              
//             /trees/shung/shung-dev/chips/peregrine/1.0/blueprint/sysconfig  
//             rtc_wlan_reg.rdl                                                
//                                                                             
// Sources:    /trees/shung/shung-dev/chips/peregrine/1.0/ip/athr/wifi/rtl/mac/rtl/dev/rtc/blueprint/rtc_wlan_reg.rdl
//             /trees/shung/shung-dev/chips/peregrine/1.0/env/blueprint/ath_vrh.pm
//             /cad/local/lib/perl/Pinfo.pm                                    
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


#ifndef _RTC_WLAN_REG_H_
#define _RTC_WLAN_REG_H_
// 0x0000 (WLAN_RESET_CONTROL)
#define WLAN_RESET_CONTROL_MCI_RESET_MSB                             7
#define WLAN_RESET_CONTROL_MCI_RESET_LSB                             7
#define WLAN_RESET_CONTROL_MCI_RESET_MASK                            0x00000080
#define WLAN_RESET_CONTROL_MCI_RESET_GET(x)                          (((x) & WLAN_RESET_CONTROL_MCI_RESET_MASK) >> WLAN_RESET_CONTROL_MCI_RESET_LSB)
#define WLAN_RESET_CONTROL_MCI_RESET_SET(x)                          (((0 | (x)) << WLAN_RESET_CONTROL_MCI_RESET_LSB) & WLAN_RESET_CONTROL_MCI_RESET_MASK)
#define WLAN_RESET_CONTROL_MCI_RESET_RESET                           0
#define WLAN_RESET_CONTROL_RADIO_SRESET_MSB                          6
#define WLAN_RESET_CONTROL_RADIO_SRESET_LSB                          6
#define WLAN_RESET_CONTROL_RADIO_SRESET_MASK                         0x00000040
#define WLAN_RESET_CONTROL_RADIO_SRESET_GET(x)                       (((x) & WLAN_RESET_CONTROL_RADIO_SRESET_MASK) >> WLAN_RESET_CONTROL_RADIO_SRESET_LSB)
#define WLAN_RESET_CONTROL_RADIO_SRESET_SET(x)                       (((0 | (x)) << WLAN_RESET_CONTROL_RADIO_SRESET_LSB) & WLAN_RESET_CONTROL_RADIO_SRESET_MASK)
#define WLAN_RESET_CONTROL_RADIO_SRESET_RESET                        1
#define WLAN_RESET_CONTROL_BB_COLD_RST_MSB                           5
#define WLAN_RESET_CONTROL_BB_COLD_RST_LSB                           5
#define WLAN_RESET_CONTROL_BB_COLD_RST_MASK                          0x00000020
#define WLAN_RESET_CONTROL_BB_COLD_RST_GET(x)                        (((x) & WLAN_RESET_CONTROL_BB_COLD_RST_MASK) >> WLAN_RESET_CONTROL_BB_COLD_RST_LSB)
#define WLAN_RESET_CONTROL_BB_COLD_RST_SET(x)                        (((0 | (x)) << WLAN_RESET_CONTROL_BB_COLD_RST_LSB) & WLAN_RESET_CONTROL_BB_COLD_RST_MASK)
#define WLAN_RESET_CONTROL_BB_COLD_RST_RESET                         1
#define WLAN_RESET_CONTROL_BB_WARM_RST_MSB                           4
#define WLAN_RESET_CONTROL_BB_WARM_RST_LSB                           4
#define WLAN_RESET_CONTROL_BB_WARM_RST_MASK                          0x00000010
#define WLAN_RESET_CONTROL_BB_WARM_RST_GET(x)                        (((x) & WLAN_RESET_CONTROL_BB_WARM_RST_MASK) >> WLAN_RESET_CONTROL_BB_WARM_RST_LSB)
#define WLAN_RESET_CONTROL_BB_WARM_RST_SET(x)                        (((0 | (x)) << WLAN_RESET_CONTROL_BB_WARM_RST_LSB) & WLAN_RESET_CONTROL_BB_WARM_RST_MASK)
#define WLAN_RESET_CONTROL_BB_WARM_RST_RESET                         1
#define WLAN_RESET_CONTROL_COLD_RST_MSB                              3
#define WLAN_RESET_CONTROL_COLD_RST_LSB                              3
#define WLAN_RESET_CONTROL_COLD_RST_MASK                             0x00000008
#define WLAN_RESET_CONTROL_COLD_RST_GET(x)                           (((x) & WLAN_RESET_CONTROL_COLD_RST_MASK) >> WLAN_RESET_CONTROL_COLD_RST_LSB)
#define WLAN_RESET_CONTROL_COLD_RST_SET(x)                           (((0 | (x)) << WLAN_RESET_CONTROL_COLD_RST_LSB) & WLAN_RESET_CONTROL_COLD_RST_MASK)
#define WLAN_RESET_CONTROL_COLD_RST_RESET                            0
#define WLAN_RESET_CONTROL_WARM_RST_MSB                              2
#define WLAN_RESET_CONTROL_WARM_RST_LSB                              2
#define WLAN_RESET_CONTROL_WARM_RST_MASK                             0x00000004
#define WLAN_RESET_CONTROL_WARM_RST_GET(x)                           (((x) & WLAN_RESET_CONTROL_WARM_RST_MASK) >> WLAN_RESET_CONTROL_WARM_RST_LSB)
#define WLAN_RESET_CONTROL_WARM_RST_SET(x)                           (((0 | (x)) << WLAN_RESET_CONTROL_WARM_RST_LSB) & WLAN_RESET_CONTROL_WARM_RST_MASK)
#define WLAN_RESET_CONTROL_WARM_RST_RESET                            0
#define WLAN_RESET_CONTROL_MAC_COLD_RST_MSB                          1
#define WLAN_RESET_CONTROL_MAC_COLD_RST_LSB                          1
#define WLAN_RESET_CONTROL_MAC_COLD_RST_MASK                         0x00000002
#define WLAN_RESET_CONTROL_MAC_COLD_RST_GET(x)                       (((x) & WLAN_RESET_CONTROL_MAC_COLD_RST_MASK) >> WLAN_RESET_CONTROL_MAC_COLD_RST_LSB)
#define WLAN_RESET_CONTROL_MAC_COLD_RST_SET(x)                       (((0 | (x)) << WLAN_RESET_CONTROL_MAC_COLD_RST_LSB) & WLAN_RESET_CONTROL_MAC_COLD_RST_MASK)
#define WLAN_RESET_CONTROL_MAC_COLD_RST_RESET                        1
#define WLAN_RESET_CONTROL_MAC_WARM_RST_MSB                          0
#define WLAN_RESET_CONTROL_MAC_WARM_RST_LSB                          0
#define WLAN_RESET_CONTROL_MAC_WARM_RST_MASK                         0x00000001
#define WLAN_RESET_CONTROL_MAC_WARM_RST_GET(x)                       (((x) & WLAN_RESET_CONTROL_MAC_WARM_RST_MASK) >> WLAN_RESET_CONTROL_MAC_WARM_RST_LSB)
#define WLAN_RESET_CONTROL_MAC_WARM_RST_SET(x)                       (((0 | (x)) << WLAN_RESET_CONTROL_MAC_WARM_RST_LSB) & WLAN_RESET_CONTROL_MAC_WARM_RST_MASK)
#define WLAN_RESET_CONTROL_MAC_WARM_RST_RESET                        1
#define WLAN_RESET_CONTROL_ADDRESS                                   0x0000
#define WLAN_RESET_CONTROL_HW_MASK                                   0x000000ff
#define WLAN_RESET_CONTROL_SW_MASK                                   0x000000ff
#define WLAN_RESET_CONTROL_HW_WRITE_MASK                             0x00000006
#define WLAN_RESET_CONTROL_SW_WRITE_MASK                             0x000000ff
#define WLAN_RESET_CONTROL_RSTMASK                                   0xffffffff
#define WLAN_RESET_CONTROL_RESET                                     0x00000073

// 0x0004 (WLAN_XTAL_CONTROL)
#define WLAN_XTAL_CONTROL_TCXO_MSB                                   0
#define WLAN_XTAL_CONTROL_TCXO_LSB                                   0
#define WLAN_XTAL_CONTROL_TCXO_MASK                                  0x00000001
#define WLAN_XTAL_CONTROL_TCXO_GET(x)                                (((x) & WLAN_XTAL_CONTROL_TCXO_MASK) >> WLAN_XTAL_CONTROL_TCXO_LSB)
#define WLAN_XTAL_CONTROL_TCXO_SET(x)                                (((0 | (x)) << WLAN_XTAL_CONTROL_TCXO_LSB) & WLAN_XTAL_CONTROL_TCXO_MASK)
#define WLAN_XTAL_CONTROL_TCXO_RESET                                 0
#define WLAN_XTAL_CONTROL_ADDRESS                                    0x0004
#define WLAN_XTAL_CONTROL_HW_MASK                                    0x00000001
#define WLAN_XTAL_CONTROL_SW_MASK                                    0x00000001
#define WLAN_XTAL_CONTROL_HW_WRITE_MASK                              0x00000000
#define WLAN_XTAL_CONTROL_SW_WRITE_MASK                              0x00000001
#define WLAN_XTAL_CONTROL_RSTMASK                                    0xffffffff
#define WLAN_XTAL_CONTROL_RESET                                      0x00000000

// 0x0008 (WLAN_REG_CONTROL0)
#define WLAN_REG_CONTROL0_SWREG_BITS_MSB                             31
#define WLAN_REG_CONTROL0_SWREG_BITS_LSB                             0
#define WLAN_REG_CONTROL0_SWREG_BITS_MASK                            0xffffffff
#define WLAN_REG_CONTROL0_SWREG_BITS_GET(x)                          (((x) & WLAN_REG_CONTROL0_SWREG_BITS_MASK) >> WLAN_REG_CONTROL0_SWREG_BITS_LSB)
#define WLAN_REG_CONTROL0_SWREG_BITS_SET(x)                          (((0 | (x)) << WLAN_REG_CONTROL0_SWREG_BITS_LSB) & WLAN_REG_CONTROL0_SWREG_BITS_MASK)
#define WLAN_REG_CONTROL0_SWREG_BITS_RESET                           0
#define WLAN_REG_CONTROL0_ADDRESS                                    0x0008
#define WLAN_REG_CONTROL0_HW_MASK                                    0xffffffff
#define WLAN_REG_CONTROL0_SW_MASK                                    0xffffffff
#define WLAN_REG_CONTROL0_HW_WRITE_MASK                              0x00000000
#define WLAN_REG_CONTROL0_SW_WRITE_MASK                              0xffffffff
#define WLAN_REG_CONTROL0_RSTMASK                                    0xffffffff
#define WLAN_REG_CONTROL0_RESET                                      0x00000000

// 0x000c (WLAN_REG_CONTROL1)
#define WLAN_REG_CONTROL1_OTPREG_LVL_MSB                             2
#define WLAN_REG_CONTROL1_OTPREG_LVL_LSB                             1
#define WLAN_REG_CONTROL1_OTPREG_LVL_MASK                            0x00000006
#define WLAN_REG_CONTROL1_OTPREG_LVL_GET(x)                          (((x) & WLAN_REG_CONTROL1_OTPREG_LVL_MASK) >> WLAN_REG_CONTROL1_OTPREG_LVL_LSB)
#define WLAN_REG_CONTROL1_OTPREG_LVL_SET(x)                          (((0 | (x)) << WLAN_REG_CONTROL1_OTPREG_LVL_LSB) & WLAN_REG_CONTROL1_OTPREG_LVL_MASK)
#define WLAN_REG_CONTROL1_OTPREG_LVL_RESET                           0
#define WLAN_REG_CONTROL1_SWREG_PROGRAM_MSB                          0
#define WLAN_REG_CONTROL1_SWREG_PROGRAM_LSB                          0
#define WLAN_REG_CONTROL1_SWREG_PROGRAM_MASK                         0x00000001
#define WLAN_REG_CONTROL1_SWREG_PROGRAM_GET(x)                       (((x) & WLAN_REG_CONTROL1_SWREG_PROGRAM_MASK) >> WLAN_REG_CONTROL1_SWREG_PROGRAM_LSB)
#define WLAN_REG_CONTROL1_SWREG_PROGRAM_SET(x)                       (((0 | (x)) << WLAN_REG_CONTROL1_SWREG_PROGRAM_LSB) & WLAN_REG_CONTROL1_SWREG_PROGRAM_MASK)
#define WLAN_REG_CONTROL1_SWREG_PROGRAM_RESET                        0
#define WLAN_REG_CONTROL1_ADDRESS                                    0x000c
#define WLAN_REG_CONTROL1_HW_MASK                                    0x00000007
#define WLAN_REG_CONTROL1_SW_MASK                                    0x00000007
#define WLAN_REG_CONTROL1_HW_WRITE_MASK                              0x00000000
#define WLAN_REG_CONTROL1_SW_WRITE_MASK                              0x00000007
#define WLAN_REG_CONTROL1_RSTMASK                                    0xfffffffe
#define WLAN_REG_CONTROL1_RESET                                      0x00000000

// 0x0010 (WLAN_QUADRATURE)
#define WLAN_QUADRATURE_ADC_MSB                                      7
#define WLAN_QUADRATURE_ADC_LSB                                      4
#define WLAN_QUADRATURE_ADC_MASK                                     0x000000f0
#define WLAN_QUADRATURE_ADC_GET(x)                                   (((x) & WLAN_QUADRATURE_ADC_MASK) >> WLAN_QUADRATURE_ADC_LSB)
#define WLAN_QUADRATURE_ADC_SET(x)                                   (((0 | (x)) << WLAN_QUADRATURE_ADC_LSB) & WLAN_QUADRATURE_ADC_MASK)
#define WLAN_QUADRATURE_ADC_RESET                                    0
#define WLAN_QUADRATURE_DAC_MSB                                      2
#define WLAN_QUADRATURE_DAC_LSB                                      0
#define WLAN_QUADRATURE_DAC_MASK                                     0x00000007
#define WLAN_QUADRATURE_DAC_GET(x)                                   (((x) & WLAN_QUADRATURE_DAC_MASK) >> WLAN_QUADRATURE_DAC_LSB)
#define WLAN_QUADRATURE_DAC_SET(x)                                   (((0 | (x)) << WLAN_QUADRATURE_DAC_LSB) & WLAN_QUADRATURE_DAC_MASK)
#define WLAN_QUADRATURE_DAC_RESET                                    0
#define WLAN_QUADRATURE_ADDRESS                                      0x0010
#define WLAN_QUADRATURE_HW_MASK                                      0x000000f7
#define WLAN_QUADRATURE_SW_MASK                                      0x000000f7
#define WLAN_QUADRATURE_HW_WRITE_MASK                                0x00000000
#define WLAN_QUADRATURE_SW_WRITE_MASK                                0x000000f7
#define WLAN_QUADRATURE_RSTMASK                                      0xffffffff
#define WLAN_QUADRATURE_RESET                                        0x00000000

// 0x0014 (WLAN_PLL_CONTROL)
#define WLAN_PLL_CONTROL_DIG_TEST_CLK_MSB                            20
#define WLAN_PLL_CONTROL_DIG_TEST_CLK_LSB                            20
#define WLAN_PLL_CONTROL_DIG_TEST_CLK_MASK                           0x00100000
#define WLAN_PLL_CONTROL_DIG_TEST_CLK_GET(x)                         (((x) & WLAN_PLL_CONTROL_DIG_TEST_CLK_MASK) >> WLAN_PLL_CONTROL_DIG_TEST_CLK_LSB)
#define WLAN_PLL_CONTROL_DIG_TEST_CLK_SET(x)                         (((0 | (x)) << WLAN_PLL_CONTROL_DIG_TEST_CLK_LSB) & WLAN_PLL_CONTROL_DIG_TEST_CLK_MASK)
#define WLAN_PLL_CONTROL_DIG_TEST_CLK_RESET                          0
#define WLAN_PLL_CONTROL_MAC_OVERRIDE_MSB                            19
#define WLAN_PLL_CONTROL_MAC_OVERRIDE_LSB                            19
#define WLAN_PLL_CONTROL_MAC_OVERRIDE_MASK                           0x00080000
#define WLAN_PLL_CONTROL_MAC_OVERRIDE_GET(x)                         (((x) & WLAN_PLL_CONTROL_MAC_OVERRIDE_MASK) >> WLAN_PLL_CONTROL_MAC_OVERRIDE_LSB)
#define WLAN_PLL_CONTROL_MAC_OVERRIDE_SET(x)                         (((0 | (x)) << WLAN_PLL_CONTROL_MAC_OVERRIDE_LSB) & WLAN_PLL_CONTROL_MAC_OVERRIDE_MASK)
#define WLAN_PLL_CONTROL_MAC_OVERRIDE_RESET                          0
#define WLAN_PLL_CONTROL_NOPWD_MSB                                   18
#define WLAN_PLL_CONTROL_NOPWD_LSB                                   18
#define WLAN_PLL_CONTROL_NOPWD_MASK                                  0x00040000
#define WLAN_PLL_CONTROL_NOPWD_GET(x)                                (((x) & WLAN_PLL_CONTROL_NOPWD_MASK) >> WLAN_PLL_CONTROL_NOPWD_LSB)
#define WLAN_PLL_CONTROL_NOPWD_SET(x)                                (((0 | (x)) << WLAN_PLL_CONTROL_NOPWD_LSB) & WLAN_PLL_CONTROL_NOPWD_MASK)
#define WLAN_PLL_CONTROL_NOPWD_RESET                                 0
#define WLAN_PLL_CONTROL_UPDATING_MSB                                17
#define WLAN_PLL_CONTROL_UPDATING_LSB                                17
#define WLAN_PLL_CONTROL_UPDATING_MASK                               0x00020000
#define WLAN_PLL_CONTROL_UPDATING_GET(x)                             (((x) & WLAN_PLL_CONTROL_UPDATING_MASK) >> WLAN_PLL_CONTROL_UPDATING_LSB)
#define WLAN_PLL_CONTROL_UPDATING_SET(x)                             (((0 | (x)) << WLAN_PLL_CONTROL_UPDATING_LSB) & WLAN_PLL_CONTROL_UPDATING_MASK)
#define WLAN_PLL_CONTROL_UPDATING_RESET                              0
#define WLAN_PLL_CONTROL_BYPASS_MSB                                  16
#define WLAN_PLL_CONTROL_BYPASS_LSB                                  16
#define WLAN_PLL_CONTROL_BYPASS_MASK                                 0x00010000
#define WLAN_PLL_CONTROL_BYPASS_GET(x)                               (((x) & WLAN_PLL_CONTROL_BYPASS_MASK) >> WLAN_PLL_CONTROL_BYPASS_LSB)
#define WLAN_PLL_CONTROL_BYPASS_SET(x)                               (((0 | (x)) << WLAN_PLL_CONTROL_BYPASS_LSB) & WLAN_PLL_CONTROL_BYPASS_MASK)
#define WLAN_PLL_CONTROL_BYPASS_RESET                                1
#define WLAN_PLL_CONTROL_CLK_SEL_MSB                                 15
#define WLAN_PLL_CONTROL_CLK_SEL_LSB                                 14
#define WLAN_PLL_CONTROL_CLK_SEL_MASK                                0x0000c000
#define WLAN_PLL_CONTROL_CLK_SEL_GET(x)                              (((x) & WLAN_PLL_CONTROL_CLK_SEL_MASK) >> WLAN_PLL_CONTROL_CLK_SEL_LSB)
#define WLAN_PLL_CONTROL_CLK_SEL_SET(x)                              (((0 | (x)) << WLAN_PLL_CONTROL_CLK_SEL_LSB) & WLAN_PLL_CONTROL_CLK_SEL_MASK)
#define WLAN_PLL_CONTROL_CLK_SEL_RESET                               0
#define WLAN_PLL_CONTROL_REFDIV_MSB                                  13
#define WLAN_PLL_CONTROL_REFDIV_LSB                                  10
#define WLAN_PLL_CONTROL_REFDIV_MASK                                 0x00003c00
#define WLAN_PLL_CONTROL_REFDIV_GET(x)                               (((x) & WLAN_PLL_CONTROL_REFDIV_MASK) >> WLAN_PLL_CONTROL_REFDIV_LSB)
#define WLAN_PLL_CONTROL_REFDIV_SET(x)                               (((0 | (x)) << WLAN_PLL_CONTROL_REFDIV_LSB) & WLAN_PLL_CONTROL_REFDIV_MASK)
#define WLAN_PLL_CONTROL_REFDIV_RESET                                5
#define WLAN_PLL_CONTROL_DIV_MSB                                     9
#define WLAN_PLL_CONTROL_DIV_LSB                                     0
#define WLAN_PLL_CONTROL_DIV_MASK                                    0x000003ff
#define WLAN_PLL_CONTROL_DIV_GET(x)                                  (((x) & WLAN_PLL_CONTROL_DIV_MASK) >> WLAN_PLL_CONTROL_DIV_LSB)
#define WLAN_PLL_CONTROL_DIV_SET(x)                                  (((0 | (x)) << WLAN_PLL_CONTROL_DIV_LSB) & WLAN_PLL_CONTROL_DIV_MASK)
#define WLAN_PLL_CONTROL_DIV_RESET                                   88
#define WLAN_PLL_CONTROL_ADDRESS                                     0x0014
#define WLAN_PLL_CONTROL_HW_MASK                                     0x001fffff
#define WLAN_PLL_CONTROL_SW_MASK                                     0x001fffff
#define WLAN_PLL_CONTROL_HW_WRITE_MASK                               0x00020000
#define WLAN_PLL_CONTROL_SW_WRITE_MASK                               0x001dffff
#define WLAN_PLL_CONTROL_RSTMASK                                     0xffffffff
#define WLAN_PLL_CONTROL_RESET                                       0x00011458

// 0x0018 (WLAN_PLL_SETTLE)
#define WLAN_PLL_SETTLE_TIME_MSB                                     10
#define WLAN_PLL_SETTLE_TIME_LSB                                     0
#define WLAN_PLL_SETTLE_TIME_MASK                                    0x000007ff
#define WLAN_PLL_SETTLE_TIME_GET(x)                                  (((x) & WLAN_PLL_SETTLE_TIME_MASK) >> WLAN_PLL_SETTLE_TIME_LSB)
#define WLAN_PLL_SETTLE_TIME_SET(x)                                  (((0 | (x)) << WLAN_PLL_SETTLE_TIME_LSB) & WLAN_PLL_SETTLE_TIME_MASK)
#define WLAN_PLL_SETTLE_TIME_RESET                                   1024
#define WLAN_PLL_SETTLE_ADDRESS                                      0x0018
#define WLAN_PLL_SETTLE_HW_MASK                                      0x000007ff
#define WLAN_PLL_SETTLE_SW_MASK                                      0x000007ff
#define WLAN_PLL_SETTLE_HW_WRITE_MASK                                0x00000000
#define WLAN_PLL_SETTLE_SW_WRITE_MASK                                0x000007ff
#define WLAN_PLL_SETTLE_RSTMASK                                      0xffffffff
#define WLAN_PLL_SETTLE_RESET                                        0x00000400

// 0x001c (WLAN_XTAL_SETTLE)
#define WLAN_XTAL_SETTLE_TIME_MSB                                    6
#define WLAN_XTAL_SETTLE_TIME_LSB                                    0
#define WLAN_XTAL_SETTLE_TIME_MASK                                   0x0000007f
#define WLAN_XTAL_SETTLE_TIME_GET(x)                                 (((x) & WLAN_XTAL_SETTLE_TIME_MASK) >> WLAN_XTAL_SETTLE_TIME_LSB)
#define WLAN_XTAL_SETTLE_TIME_SET(x)                                 (((0 | (x)) << WLAN_XTAL_SETTLE_TIME_LSB) & WLAN_XTAL_SETTLE_TIME_MASK)
#define WLAN_XTAL_SETTLE_TIME_RESET                                  124
#define WLAN_XTAL_SETTLE_ADDRESS                                     0x001c
#define WLAN_XTAL_SETTLE_HW_MASK                                     0x0000007f
#define WLAN_XTAL_SETTLE_SW_MASK                                     0x0000007f
#define WLAN_XTAL_SETTLE_HW_WRITE_MASK                               0x0000007f
#define WLAN_XTAL_SETTLE_SW_WRITE_MASK                               0x0000007f
#define WLAN_XTAL_SETTLE_RSTMASK                                     0xffffffff
#define WLAN_XTAL_SETTLE_RESET                                       0x0000007c

// 0x0020 (WLAN_CLOCK_OUT)
#define WLAN_CLOCK_OUT_DELAY_MSB                                     6
#define WLAN_CLOCK_OUT_DELAY_LSB                                     4
#define WLAN_CLOCK_OUT_DELAY_MASK                                    0x00000070
#define WLAN_CLOCK_OUT_DELAY_GET(x)                                  (((x) & WLAN_CLOCK_OUT_DELAY_MASK) >> WLAN_CLOCK_OUT_DELAY_LSB)
#define WLAN_CLOCK_OUT_DELAY_SET(x)                                  (((0 | (x)) << WLAN_CLOCK_OUT_DELAY_LSB) & WLAN_CLOCK_OUT_DELAY_MASK)
#define WLAN_CLOCK_OUT_DELAY_RESET                                   0
#define WLAN_CLOCK_OUT_SELECT_MSB                                    3
#define WLAN_CLOCK_OUT_SELECT_LSB                                    0
#define WLAN_CLOCK_OUT_SELECT_MASK                                   0x0000000f
#define WLAN_CLOCK_OUT_SELECT_GET(x)                                 (((x) & WLAN_CLOCK_OUT_SELECT_MASK) >> WLAN_CLOCK_OUT_SELECT_LSB)
#define WLAN_CLOCK_OUT_SELECT_SET(x)                                 (((0 | (x)) << WLAN_CLOCK_OUT_SELECT_LSB) & WLAN_CLOCK_OUT_SELECT_MASK)
#define WLAN_CLOCK_OUT_SELECT_RESET                                  0
#define WLAN_CLOCK_OUT_ADDRESS                                       0x0020
#define WLAN_CLOCK_OUT_HW_MASK                                       0x0000007f
#define WLAN_CLOCK_OUT_SW_MASK                                       0x0000007f
#define WLAN_CLOCK_OUT_HW_WRITE_MASK                                 0x00000000
#define WLAN_CLOCK_OUT_SW_WRITE_MASK                                 0x0000007f
#define WLAN_CLOCK_OUT_RSTMASK                                       0xffffffff
#define WLAN_CLOCK_OUT_RESET                                         0x00000000

// 0x0024 (WLAN_BIAS_OVERRIDE)
#define WLAN_BIAS_OVERRIDE_ON_MSB                                    0
#define WLAN_BIAS_OVERRIDE_ON_LSB                                    0
#define WLAN_BIAS_OVERRIDE_ON_MASK                                   0x00000001
#define WLAN_BIAS_OVERRIDE_ON_GET(x)                                 (((x) & WLAN_BIAS_OVERRIDE_ON_MASK) >> WLAN_BIAS_OVERRIDE_ON_LSB)
#define WLAN_BIAS_OVERRIDE_ON_SET(x)                                 (((0 | (x)) << WLAN_BIAS_OVERRIDE_ON_LSB) & WLAN_BIAS_OVERRIDE_ON_MASK)
#define WLAN_BIAS_OVERRIDE_ON_RESET                                  0
#define WLAN_BIAS_OVERRIDE_ADDRESS                                   0x0024
#define WLAN_BIAS_OVERRIDE_HW_MASK                                   0x00000001
#define WLAN_BIAS_OVERRIDE_SW_MASK                                   0x00000001
#define WLAN_BIAS_OVERRIDE_HW_WRITE_MASK                             0x00000000
#define WLAN_BIAS_OVERRIDE_SW_WRITE_MASK                             0x00000001
#define WLAN_BIAS_OVERRIDE_RSTMASK                                   0xffffffff
#define WLAN_BIAS_OVERRIDE_RESET                                     0x00000000

// 0x0028 (WLAN_RESET_CAUSE)
#define WLAN_RESET_CAUSE_LAST_MSB                                    2
#define WLAN_RESET_CAUSE_LAST_LSB                                    0
#define WLAN_RESET_CAUSE_LAST_MASK                                   0x00000007
#define WLAN_RESET_CAUSE_LAST_GET(x)                                 (((x) & WLAN_RESET_CAUSE_LAST_MASK) >> WLAN_RESET_CAUSE_LAST_LSB)
#define WLAN_RESET_CAUSE_LAST_SET(x)                                 (((0 | (x)) << WLAN_RESET_CAUSE_LAST_LSB) & WLAN_RESET_CAUSE_LAST_MASK)
#define WLAN_RESET_CAUSE_LAST_RESET                                  0
#define WLAN_RESET_CAUSE_ADDRESS                                     0x0028
#define WLAN_RESET_CAUSE_HW_MASK                                     0x00000007
#define WLAN_RESET_CAUSE_SW_MASK                                     0x00000007
#define WLAN_RESET_CAUSE_HW_WRITE_MASK                               0x00000007
#define WLAN_RESET_CAUSE_SW_WRITE_MASK                               0x00000000
#define WLAN_RESET_CAUSE_RSTMASK                                     0xffffffff
#define WLAN_RESET_CAUSE_RESET                                       0x00000000

// 0x002c (WLAN_SYSTEM_SLEEP)
#define WLAN_SYSTEM_SLEEP_MAC_IF_MSB                                 2
#define WLAN_SYSTEM_SLEEP_MAC_IF_LSB                                 2
#define WLAN_SYSTEM_SLEEP_MAC_IF_MASK                                0x00000004
#define WLAN_SYSTEM_SLEEP_MAC_IF_GET(x)                              (((x) & WLAN_SYSTEM_SLEEP_MAC_IF_MASK) >> WLAN_SYSTEM_SLEEP_MAC_IF_LSB)
#define WLAN_SYSTEM_SLEEP_MAC_IF_SET(x)                              (((0 | (x)) << WLAN_SYSTEM_SLEEP_MAC_IF_LSB) & WLAN_SYSTEM_SLEEP_MAC_IF_MASK)
#define WLAN_SYSTEM_SLEEP_MAC_IF_RESET                               1
#define WLAN_SYSTEM_SLEEP_LIGHT_MSB                                  1
#define WLAN_SYSTEM_SLEEP_LIGHT_LSB                                  1
#define WLAN_SYSTEM_SLEEP_LIGHT_MASK                                 0x00000002
#define WLAN_SYSTEM_SLEEP_LIGHT_GET(x)                               (((x) & WLAN_SYSTEM_SLEEP_LIGHT_MASK) >> WLAN_SYSTEM_SLEEP_LIGHT_LSB)
#define WLAN_SYSTEM_SLEEP_LIGHT_SET(x)                               (((0 | (x)) << WLAN_SYSTEM_SLEEP_LIGHT_LSB) & WLAN_SYSTEM_SLEEP_LIGHT_MASK)
#define WLAN_SYSTEM_SLEEP_LIGHT_RESET                                0
#define WLAN_SYSTEM_SLEEP_DISABLE_MSB                                0
#define WLAN_SYSTEM_SLEEP_DISABLE_LSB                                0
#define WLAN_SYSTEM_SLEEP_DISABLE_MASK                               0x00000001
#define WLAN_SYSTEM_SLEEP_DISABLE_GET(x)                             (((x) & WLAN_SYSTEM_SLEEP_DISABLE_MASK) >> WLAN_SYSTEM_SLEEP_DISABLE_LSB)
#define WLAN_SYSTEM_SLEEP_DISABLE_SET(x)                             (((0 | (x)) << WLAN_SYSTEM_SLEEP_DISABLE_LSB) & WLAN_SYSTEM_SLEEP_DISABLE_MASK)
#define WLAN_SYSTEM_SLEEP_DISABLE_RESET                              1
#define WLAN_SYSTEM_SLEEP_ADDRESS                                    0x002c
#define WLAN_SYSTEM_SLEEP_HW_MASK                                    0x00000007
#define WLAN_SYSTEM_SLEEP_SW_MASK                                    0x00000007
#define WLAN_SYSTEM_SLEEP_HW_WRITE_MASK                              0x00000004
#define WLAN_SYSTEM_SLEEP_SW_WRITE_MASK                              0x00000003
#define WLAN_SYSTEM_SLEEP_RSTMASK                                    0xffffffff
#define WLAN_SYSTEM_SLEEP_RESET                                      0x00000005

// 0x0030 (WLAN_MAC_SLEEP_CONTROL)
#define WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_MSB                  2
#define WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_LSB                  2
#define WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_MASK                 0x00000004
#define WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_GET(x)               (((x) & WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_MASK) >> WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_LSB)
#define WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_SET(x)               (((0 | (x)) << WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_LSB) & WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_MASK)
#define WLAN_MAC_SLEEP_CONTROL_HSEL_WMAC_ENABLE_RESET                1
#define WLAN_MAC_SLEEP_CONTROL_RESERVED_MSB                          1
#define WLAN_MAC_SLEEP_CONTROL_RESERVED_LSB                          1
#define WLAN_MAC_SLEEP_CONTROL_RESERVED_MASK                         0x00000002
#define WLAN_MAC_SLEEP_CONTROL_RESERVED_GET(x)                       (((x) & WLAN_MAC_SLEEP_CONTROL_RESERVED_MASK) >> WLAN_MAC_SLEEP_CONTROL_RESERVED_LSB)
#define WLAN_MAC_SLEEP_CONTROL_RESERVED_SET(x)                       (((0 | (x)) << WLAN_MAC_SLEEP_CONTROL_RESERVED_LSB) & WLAN_MAC_SLEEP_CONTROL_RESERVED_MASK)
#define WLAN_MAC_SLEEP_CONTROL_RESERVED_RESET                        0
#define WLAN_MAC_SLEEP_CONTROL_ENABLE_MSB                            0
#define WLAN_MAC_SLEEP_CONTROL_ENABLE_LSB                            0
#define WLAN_MAC_SLEEP_CONTROL_ENABLE_MASK                           0x00000001
#define WLAN_MAC_SLEEP_CONTROL_ENABLE_GET(x)                         (((x) & WLAN_MAC_SLEEP_CONTROL_ENABLE_MASK) >> WLAN_MAC_SLEEP_CONTROL_ENABLE_LSB)
#define WLAN_MAC_SLEEP_CONTROL_ENABLE_SET(x)                         (((0 | (x)) << WLAN_MAC_SLEEP_CONTROL_ENABLE_LSB) & WLAN_MAC_SLEEP_CONTROL_ENABLE_MASK)
#define WLAN_MAC_SLEEP_CONTROL_ENABLE_RESET                          0
#define WLAN_MAC_SLEEP_CONTROL_ADDRESS                               0x0030
#define WLAN_MAC_SLEEP_CONTROL_HW_MASK                               0x00000007
#define WLAN_MAC_SLEEP_CONTROL_SW_MASK                               0x00000007
#define WLAN_MAC_SLEEP_CONTROL_HW_WRITE_MASK                         0x00000000
#define WLAN_MAC_SLEEP_CONTROL_SW_WRITE_MASK                         0x00000007
#define WLAN_MAC_SLEEP_CONTROL_RSTMASK                               0xffffffff
#define WLAN_MAC_SLEEP_CONTROL_RESET                                 0x00000004

// 0x0034 (WLAN_KEEP_AWAKE)
#define WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_MSB                        15
#define WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_LSB                        8
#define WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_MASK                       0x0000ff00
#define WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_GET(x)                     (((x) & WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_MASK) >> WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_LSB)
#define WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_SET(x)                     (((0 | (x)) << WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_LSB) & WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_MASK)
#define WLAN_KEEP_AWAKE_MAC_CLK_REQ_COUNT_RESET                      3
#define WLAN_KEEP_AWAKE_COUNT_MSB                                    7
#define WLAN_KEEP_AWAKE_COUNT_LSB                                    0
#define WLAN_KEEP_AWAKE_COUNT_MASK                                   0x000000ff
#define WLAN_KEEP_AWAKE_COUNT_GET(x)                                 (((x) & WLAN_KEEP_AWAKE_COUNT_MASK) >> WLAN_KEEP_AWAKE_COUNT_LSB)
#define WLAN_KEEP_AWAKE_COUNT_SET(x)                                 (((0 | (x)) << WLAN_KEEP_AWAKE_COUNT_LSB) & WLAN_KEEP_AWAKE_COUNT_MASK)
#define WLAN_KEEP_AWAKE_COUNT_RESET                                  3
#define WLAN_KEEP_AWAKE_ADDRESS                                      0x0034
#define WLAN_KEEP_AWAKE_HW_MASK                                      0x0000ffff
#define WLAN_KEEP_AWAKE_SW_MASK                                      0x0000ffff
#define WLAN_KEEP_AWAKE_HW_WRITE_MASK                                0x00000000
#define WLAN_KEEP_AWAKE_SW_WRITE_MASK                                0x0000ffff
#define WLAN_KEEP_AWAKE_RSTMASK                                      0xffffffff
#define WLAN_KEEP_AWAKE_RESET                                        0x00000303

// 0x0038 (WLAN_DERIVED_RTC_CLK)
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_MSB                  20
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_LSB                  20
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_MASK                 0x00100000
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_GET(x)               (((x) & WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_MASK) >> WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_LSB)
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_SET(x)               (((0 | (x)) << WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_LSB) & WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_MASK)
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_RESET                1
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_MSB                     18
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_LSB                     18
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_MASK                    0x00040000
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_GET(x)                  (((x) & WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_MASK) >> WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_LSB)
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_SET(x)                  (((0 | (x)) << WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_LSB) & WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_MASK)
#define WLAN_DERIVED_RTC_CLK_EXTERNAL_DETECT_RESET                   0
#define WLAN_DERIVED_RTC_CLK_PERIOD_MSB                              15
#define WLAN_DERIVED_RTC_CLK_PERIOD_LSB                              1
#define WLAN_DERIVED_RTC_CLK_PERIOD_MASK                             0x0000fffe
#define WLAN_DERIVED_RTC_CLK_PERIOD_GET(x)                           (((x) & WLAN_DERIVED_RTC_CLK_PERIOD_MASK) >> WLAN_DERIVED_RTC_CLK_PERIOD_LSB)
#define WLAN_DERIVED_RTC_CLK_PERIOD_SET(x)                           (((0 | (x)) << WLAN_DERIVED_RTC_CLK_PERIOD_LSB) & WLAN_DERIVED_RTC_CLK_PERIOD_MASK)
#define WLAN_DERIVED_RTC_CLK_PERIOD_RESET                            610
#define WLAN_DERIVED_RTC_CLK_ADDRESS                                 0x0038
#define WLAN_DERIVED_RTC_CLK_HW_MASK                                 0x0014fffe
#define WLAN_DERIVED_RTC_CLK_SW_MASK                                 0x0014fffe
#define WLAN_DERIVED_RTC_CLK_HW_WRITE_MASK                           0x00040000
#define WLAN_DERIVED_RTC_CLK_SW_WRITE_MASK                           0x0010fffe
#define WLAN_DERIVED_RTC_CLK_RSTMASK                                 0xfffbffff
#define WLAN_DERIVED_RTC_CLK_RESET                                   0x001004c4

// 0x003c (MAC_PCU_SLP32_MODE)
#define MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_MSB                     24
#define MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_LSB                     24
#define MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_MASK                    0x01000000
#define MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_GET(x)                  (((x) & MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_MASK) >> MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_LSB)
#define MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_SET(x)                  (((0 | (x)) << MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_LSB) & MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_MASK)
#define MAC_PCU_SLP32_MODE_TSF2_WRITE_STATUS_RESET                   1
#define MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_MSB                   23
#define MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_LSB                   23
#define MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_MASK                  0x00800000
#define MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_GET(x)                (((x) & MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_MASK) >> MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_LSB)
#define MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_SET(x)                (((0 | (x)) << MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_LSB) & MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_MASK)
#define MAC_PCU_SLP32_MODE_FORCE_BIAS_BLOCK_ON_RESET                 0
#define MAC_PCU_SLP32_MODE_DISABLE_32KHZ_MSB                         22
#define MAC_PCU_SLP32_MODE_DISABLE_32KHZ_LSB                         22
#define MAC_PCU_SLP32_MODE_DISABLE_32KHZ_MASK                        0x00400000
#define MAC_PCU_SLP32_MODE_DISABLE_32KHZ_GET(x)                      (((x) & MAC_PCU_SLP32_MODE_DISABLE_32KHZ_MASK) >> MAC_PCU_SLP32_MODE_DISABLE_32KHZ_LSB)
#define MAC_PCU_SLP32_MODE_DISABLE_32KHZ_SET(x)                      (((0 | (x)) << MAC_PCU_SLP32_MODE_DISABLE_32KHZ_LSB) & MAC_PCU_SLP32_MODE_DISABLE_32KHZ_MASK)
#define MAC_PCU_SLP32_MODE_DISABLE_32KHZ_RESET                       0
#define MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_MSB                      21
#define MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_LSB                      21
#define MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_MASK                     0x00200000
#define MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_GET(x)                   (((x) & MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_MASK) >> MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_LSB)
#define MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_SET(x)                   (((0 | (x)) << MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_LSB) & MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_MASK)
#define MAC_PCU_SLP32_MODE_TSF_WRITE_STATUS_RESET                    1
#define MAC_PCU_SLP32_MODE_ENABLE_MSB                                20
#define MAC_PCU_SLP32_MODE_ENABLE_LSB                                20
#define MAC_PCU_SLP32_MODE_ENABLE_MASK                               0x00100000
#define MAC_PCU_SLP32_MODE_ENABLE_GET(x)                             (((x) & MAC_PCU_SLP32_MODE_ENABLE_MASK) >> MAC_PCU_SLP32_MODE_ENABLE_LSB)
#define MAC_PCU_SLP32_MODE_ENABLE_SET(x)                             (((0 | (x)) << MAC_PCU_SLP32_MODE_ENABLE_LSB) & MAC_PCU_SLP32_MODE_ENABLE_MASK)
#define MAC_PCU_SLP32_MODE_ENABLE_RESET                              1
#define MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_MSB                      19
#define MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_LSB                      0
#define MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_MASK                     0x000fffff
#define MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_GET(x)                   (((x) & MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_MASK) >> MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_LSB)
#define MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_SET(x)                   (((0 | (x)) << MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_LSB) & MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_MASK)
#define MAC_PCU_SLP32_MODE_HALF_CLK_LATENCY_RESET                    62500
#define MAC_PCU_SLP32_MODE_ADDRESS                                   0x003c
#define MAC_PCU_SLP32_MODE_HW_MASK                                   0x01ffffff
#define MAC_PCU_SLP32_MODE_SW_MASK                                   0x01ffffff
#define MAC_PCU_SLP32_MODE_HW_WRITE_MASK                             0x01200000
#define MAC_PCU_SLP32_MODE_SW_WRITE_MASK                             0x00dfffff
#define MAC_PCU_SLP32_MODE_RSTMASK                                   0xffffffff
#define MAC_PCU_SLP32_MODE_RESET                                     0x0130f424

// 0x0040 (MAC_PCU_SLP32_WAKE)
#define MAC_PCU_SLP32_WAKE_XTL_TIME_MSB                              15
#define MAC_PCU_SLP32_WAKE_XTL_TIME_LSB                              0
#define MAC_PCU_SLP32_WAKE_XTL_TIME_MASK                             0x0000ffff
#define MAC_PCU_SLP32_WAKE_XTL_TIME_GET(x)                           (((x) & MAC_PCU_SLP32_WAKE_XTL_TIME_MASK) >> MAC_PCU_SLP32_WAKE_XTL_TIME_LSB)
#define MAC_PCU_SLP32_WAKE_XTL_TIME_SET(x)                           (((0 | (x)) << MAC_PCU_SLP32_WAKE_XTL_TIME_LSB) & MAC_PCU_SLP32_WAKE_XTL_TIME_MASK)
#define MAC_PCU_SLP32_WAKE_XTL_TIME_RESET                            2048
#define MAC_PCU_SLP32_WAKE_ADDRESS                                   0x0040
#define MAC_PCU_SLP32_WAKE_HW_MASK                                   0x0000ffff
#define MAC_PCU_SLP32_WAKE_SW_MASK                                   0x0000ffff
#define MAC_PCU_SLP32_WAKE_HW_WRITE_MASK                             0x00000000
#define MAC_PCU_SLP32_WAKE_SW_WRITE_MASK                             0x0000ffff
#define MAC_PCU_SLP32_WAKE_RSTMASK                                   0xffffffff
#define MAC_PCU_SLP32_WAKE_RESET                                     0x00000800

// 0x0044 (MAC_PCU_SLP32_INC)
#define MAC_PCU_SLP32_INC_TSF_INC_MSB                                19
#define MAC_PCU_SLP32_INC_TSF_INC_LSB                                0
#define MAC_PCU_SLP32_INC_TSF_INC_MASK                               0x000fffff
#define MAC_PCU_SLP32_INC_TSF_INC_GET(x)                             (((x) & MAC_PCU_SLP32_INC_TSF_INC_MASK) >> MAC_PCU_SLP32_INC_TSF_INC_LSB)
#define MAC_PCU_SLP32_INC_TSF_INC_SET(x)                             (((0 | (x)) << MAC_PCU_SLP32_INC_TSF_INC_LSB) & MAC_PCU_SLP32_INC_TSF_INC_MASK)
#define MAC_PCU_SLP32_INC_TSF_INC_RESET                              125000
#define MAC_PCU_SLP32_INC_ADDRESS                                    0x0044
#define MAC_PCU_SLP32_INC_HW_MASK                                    0x000fffff
#define MAC_PCU_SLP32_INC_SW_MASK                                    0x000fffff
#define MAC_PCU_SLP32_INC_HW_WRITE_MASK                              0x00000000
#define MAC_PCU_SLP32_INC_SW_WRITE_MASK                              0x000fffff
#define MAC_PCU_SLP32_INC_RSTMASK                                    0xffffffff
#define MAC_PCU_SLP32_INC_RESET                                      0x0001e848

// 0x0048 (MAC_PCU_SLP_MIB1)
#define MAC_PCU_SLP_MIB1_SLEEP_CNT_MSB                               31
#define MAC_PCU_SLP_MIB1_SLEEP_CNT_LSB                               0
#define MAC_PCU_SLP_MIB1_SLEEP_CNT_MASK                              0xffffffff
#define MAC_PCU_SLP_MIB1_SLEEP_CNT_GET(x)                            (((x) & MAC_PCU_SLP_MIB1_SLEEP_CNT_MASK) >> MAC_PCU_SLP_MIB1_SLEEP_CNT_LSB)
#define MAC_PCU_SLP_MIB1_SLEEP_CNT_SET(x)                            (((0 | (x)) << MAC_PCU_SLP_MIB1_SLEEP_CNT_LSB) & MAC_PCU_SLP_MIB1_SLEEP_CNT_MASK)
#define MAC_PCU_SLP_MIB1_SLEEP_CNT_RESET                             0
#define MAC_PCU_SLP_MIB1_ADDRESS                                     0x0048
#define MAC_PCU_SLP_MIB1_HW_MASK                                     0xffffffff
#define MAC_PCU_SLP_MIB1_SW_MASK                                     0xffffffff
#define MAC_PCU_SLP_MIB1_HW_WRITE_MASK                               0xffffffff
#define MAC_PCU_SLP_MIB1_SW_WRITE_MASK                               0xffffffff
#define MAC_PCU_SLP_MIB1_RSTMASK                                     0xffffffff
#define MAC_PCU_SLP_MIB1_RESET                                       0x00000000

// 0x004c (MAC_PCU_SLP_MIB2)
#define MAC_PCU_SLP_MIB2_CYCLE_CNT_MSB                               31
#define MAC_PCU_SLP_MIB2_CYCLE_CNT_LSB                               0
#define MAC_PCU_SLP_MIB2_CYCLE_CNT_MASK                              0xffffffff
#define MAC_PCU_SLP_MIB2_CYCLE_CNT_GET(x)                            (((x) & MAC_PCU_SLP_MIB2_CYCLE_CNT_MASK) >> MAC_PCU_SLP_MIB2_CYCLE_CNT_LSB)
#define MAC_PCU_SLP_MIB2_CYCLE_CNT_SET(x)                            (((0 | (x)) << MAC_PCU_SLP_MIB2_CYCLE_CNT_LSB) & MAC_PCU_SLP_MIB2_CYCLE_CNT_MASK)
#define MAC_PCU_SLP_MIB2_CYCLE_CNT_RESET                             0
#define MAC_PCU_SLP_MIB2_ADDRESS                                     0x004c
#define MAC_PCU_SLP_MIB2_HW_MASK                                     0xffffffff
#define MAC_PCU_SLP_MIB2_SW_MASK                                     0xffffffff
#define MAC_PCU_SLP_MIB2_HW_WRITE_MASK                               0xffffffff
#define MAC_PCU_SLP_MIB2_SW_WRITE_MASK                               0xffffffff
#define MAC_PCU_SLP_MIB2_RSTMASK                                     0xffffffff
#define MAC_PCU_SLP_MIB2_RESET                                       0x00000000

// 0x0050 (MAC_PCU_SLP_MIB3)
#define MAC_PCU_SLP_MIB3_PENDING_MSB                                 1
#define MAC_PCU_SLP_MIB3_PENDING_LSB                                 1
#define MAC_PCU_SLP_MIB3_PENDING_MASK                                0x00000002
#define MAC_PCU_SLP_MIB3_PENDING_GET(x)                              (((x) & MAC_PCU_SLP_MIB3_PENDING_MASK) >> MAC_PCU_SLP_MIB3_PENDING_LSB)
#define MAC_PCU_SLP_MIB3_PENDING_SET(x)                              (((0 | (x)) << MAC_PCU_SLP_MIB3_PENDING_LSB) & MAC_PCU_SLP_MIB3_PENDING_MASK)
#define MAC_PCU_SLP_MIB3_PENDING_RESET                               0
#define MAC_PCU_SLP_MIB3_CLR_CNT_MSB                                 0
#define MAC_PCU_SLP_MIB3_CLR_CNT_LSB                                 0
#define MAC_PCU_SLP_MIB3_CLR_CNT_MASK                                0x00000001
#define MAC_PCU_SLP_MIB3_CLR_CNT_GET(x)                              (((x) & MAC_PCU_SLP_MIB3_CLR_CNT_MASK) >> MAC_PCU_SLP_MIB3_CLR_CNT_LSB)
#define MAC_PCU_SLP_MIB3_CLR_CNT_SET(x)                              (((0 | (x)) << MAC_PCU_SLP_MIB3_CLR_CNT_LSB) & MAC_PCU_SLP_MIB3_CLR_CNT_MASK)
#define MAC_PCU_SLP_MIB3_CLR_CNT_RESET                               0
#define MAC_PCU_SLP_MIB3_ADDRESS                                     0x0050
#define MAC_PCU_SLP_MIB3_HW_MASK                                     0x00000003
#define MAC_PCU_SLP_MIB3_SW_MASK                                     0x00000003
#define MAC_PCU_SLP_MIB3_HW_WRITE_MASK                               0x00000003
#define MAC_PCU_SLP_MIB3_SW_WRITE_MASK                               0x00000001
#define MAC_PCU_SLP_MIB3_RSTMASK                                     0xffffffff
#define MAC_PCU_SLP_MIB3_RESET                                       0x00000000

// 0x0054 (MAC_PCU_TSF_L32)
#define MAC_PCU_TSF_L32_VALUE_MSB                                    31
#define MAC_PCU_TSF_L32_VALUE_LSB                                    0
#define MAC_PCU_TSF_L32_VALUE_MASK                                   0xffffffff
#define MAC_PCU_TSF_L32_VALUE_GET(x)                                 (((x) & MAC_PCU_TSF_L32_VALUE_MASK) >> MAC_PCU_TSF_L32_VALUE_LSB)
#define MAC_PCU_TSF_L32_VALUE_SET(x)                                 (((0 | (x)) << MAC_PCU_TSF_L32_VALUE_LSB) & MAC_PCU_TSF_L32_VALUE_MASK)
#define MAC_PCU_TSF_L32_VALUE_RESET                                  268435455
#define MAC_PCU_TSF_L32_ADDRESS                                      0x0054
#define MAC_PCU_TSF_L32_HW_MASK                                      0xffffffff
#define MAC_PCU_TSF_L32_SW_MASK                                      0xffffffff
#define MAC_PCU_TSF_L32_HW_WRITE_MASK                                0xffffffff
#define MAC_PCU_TSF_L32_SW_WRITE_MASK                                0xffffffff
#define MAC_PCU_TSF_L32_RSTMASK                                      0xffffffff
#define MAC_PCU_TSF_L32_RESET                                        0x0fffffff

// 0x0058 (MAC_PCU_TSF_U32)
#define MAC_PCU_TSF_U32_VALUE_MSB                                    31
#define MAC_PCU_TSF_U32_VALUE_LSB                                    0
#define MAC_PCU_TSF_U32_VALUE_MASK                                   0xffffffff
#define MAC_PCU_TSF_U32_VALUE_GET(x)                                 (((x) & MAC_PCU_TSF_U32_VALUE_MASK) >> MAC_PCU_TSF_U32_VALUE_LSB)
#define MAC_PCU_TSF_U32_VALUE_SET(x)                                 (((0 | (x)) << MAC_PCU_TSF_U32_VALUE_LSB) & MAC_PCU_TSF_U32_VALUE_MASK)
#define MAC_PCU_TSF_U32_VALUE_RESET                                  268435455
#define MAC_PCU_TSF_U32_ADDRESS                                      0x0058
#define MAC_PCU_TSF_U32_HW_MASK                                      0xffffffff
#define MAC_PCU_TSF_U32_SW_MASK                                      0xffffffff
#define MAC_PCU_TSF_U32_HW_WRITE_MASK                                0xffffffff
#define MAC_PCU_TSF_U32_SW_WRITE_MASK                                0xffffffff
#define MAC_PCU_TSF_U32_RSTMASK                                      0xffffffff
#define MAC_PCU_TSF_U32_RESET                                        0x0fffffff

// 0x005c (MAC_PCU_WBTIMER_0)
#define MAC_PCU_WBTIMER_0_ENABLE_MSB                                 0
#define MAC_PCU_WBTIMER_0_ENABLE_LSB                                 0
#define MAC_PCU_WBTIMER_0_ENABLE_MASK                                0x00000001
#define MAC_PCU_WBTIMER_0_ENABLE_GET(x)                              (((x) & MAC_PCU_WBTIMER_0_ENABLE_MASK) >> MAC_PCU_WBTIMER_0_ENABLE_LSB)
#define MAC_PCU_WBTIMER_0_ENABLE_SET(x)                              (((0 | (x)) << MAC_PCU_WBTIMER_0_ENABLE_LSB) & MAC_PCU_WBTIMER_0_ENABLE_MASK)
#define MAC_PCU_WBTIMER_0_ENABLE_RESET                               0
#define MAC_PCU_WBTIMER_0_ADDRESS                                    0x005c
#define MAC_PCU_WBTIMER_0_HW_MASK                                    0x00000001
#define MAC_PCU_WBTIMER_0_SW_MASK                                    0x00000001
#define MAC_PCU_WBTIMER_0_HW_WRITE_MASK                              0x00000000
#define MAC_PCU_WBTIMER_0_SW_WRITE_MASK                              0x00000001
#define MAC_PCU_WBTIMER_0_RSTMASK                                    0xffffffff
#define MAC_PCU_WBTIMER_0_RESET                                      0x00000000

// 0x0060 (MAC_PCU_WBTIMER_1)
#define MAC_PCU_WBTIMER_1_VALUE_MSB                                  31
#define MAC_PCU_WBTIMER_1_VALUE_LSB                                  0
#define MAC_PCU_WBTIMER_1_VALUE_MASK                                 0xffffffff
#define MAC_PCU_WBTIMER_1_VALUE_GET(x)                               (((x) & MAC_PCU_WBTIMER_1_VALUE_MASK) >> MAC_PCU_WBTIMER_1_VALUE_LSB)
#define MAC_PCU_WBTIMER_1_VALUE_SET(x)                               (((0 | (x)) << MAC_PCU_WBTIMER_1_VALUE_LSB) & MAC_PCU_WBTIMER_1_VALUE_MASK)
#define MAC_PCU_WBTIMER_1_VALUE_RESET                                0
#define MAC_PCU_WBTIMER_1_ADDRESS                                    0x0060
#define MAC_PCU_WBTIMER_1_HW_MASK                                    0xffffffff
#define MAC_PCU_WBTIMER_1_SW_MASK                                    0xffffffff
#define MAC_PCU_WBTIMER_1_HW_WRITE_MASK                              0xffffffff
#define MAC_PCU_WBTIMER_1_SW_WRITE_MASK                              0xffffffff
#define MAC_PCU_WBTIMER_1_RSTMASK                                    0xffffffff
#define MAC_PCU_WBTIMER_1_RESET                                      0x00000000

// 0x0064 (MAC_PCU_GENERIC_TIMERS_0)
#define MAC_PCU_GENERIC_TIMERS_0_DATA_MSB                            31
#define MAC_PCU_GENERIC_TIMERS_0_DATA_LSB                            0
#define MAC_PCU_GENERIC_TIMERS_0_DATA_MASK                           0xffffffff
#define MAC_PCU_GENERIC_TIMERS_0_DATA_GET(x)                         (((x) & MAC_PCU_GENERIC_TIMERS_0_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS_0_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS_0_DATA_SET(x)                         (((0 | (x)) << MAC_PCU_GENERIC_TIMERS_0_DATA_LSB) & MAC_PCU_GENERIC_TIMERS_0_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS_0_DATA_RESET                          0
#define MAC_PCU_GENERIC_TIMERS_0_ADDRESS                             0x0064
#define MAC_PCU_GENERIC_TIMERS_ADDRESS                               MAC_PCU_GENERIC_TIMERS_0_ADDRESS
#define MAC_PCU_GENERIC_TIMERS_0_HW_MASK                             0xffffffff
#define MAC_PCU_GENERIC_TIMERS_0_SW_MASK                             0xffffffff
#define MAC_PCU_GENERIC_TIMERS_0_HW_WRITE_MASK                       0xffffffff
#define MAC_PCU_GENERIC_TIMERS_0_SW_WRITE_MASK                       0xffffffff
#define MAC_PCU_GENERIC_TIMERS_0_RSTMASK                             0x00000000
#define MAC_PCU_GENERIC_TIMERS_0_RESET                               0x00000000

// Skip 68 (MAC_PCU_GENERIC_TIMERS_1) - a0 (MAC_PCU_GENERIC_TIMERS_15) for brevity
// 0x00bc (MAC_PCU_GENERIC_TIMERS_MODE)
#define MAC_PCU_GENERIC_TIMERS_MODE_THRESH_MSB                       31
#define MAC_PCU_GENERIC_TIMERS_MODE_THRESH_LSB                       12
#define MAC_PCU_GENERIC_TIMERS_MODE_THRESH_MASK                      0xfffff000
#define MAC_PCU_GENERIC_TIMERS_MODE_THRESH_GET(x)                    (((x) & MAC_PCU_GENERIC_TIMERS_MODE_THRESH_MASK) >> MAC_PCU_GENERIC_TIMERS_MODE_THRESH_LSB)
#define MAC_PCU_GENERIC_TIMERS_MODE_THRESH_SET(x)                    (((0 | (x)) << MAC_PCU_GENERIC_TIMERS_MODE_THRESH_LSB) & MAC_PCU_GENERIC_TIMERS_MODE_THRESH_MASK)
#define MAC_PCU_GENERIC_TIMERS_MODE_THRESH_RESET                     256
#define MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_MSB               10
#define MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_LSB               8
#define MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_MASK              0x00000700
#define MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_GET(x)            (((x) & MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_MASK) >> MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_LSB)
#define MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_SET(x)            (((0 | (x)) << MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_LSB) & MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_MASK)
#define MAC_PCU_GENERIC_TIMERS_MODE_OVERFLOW_INDEX_RESET             0
#define MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_MSB                       7
#define MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_LSB                       0
#define MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_MASK                      0x000000ff
#define MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_GET(x)                    (((x) & MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_MASK) >> MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_LSB)
#define MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_SET(x)                    (((0 | (x)) << MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_LSB) & MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_MASK)
#define MAC_PCU_GENERIC_TIMERS_MODE_ENABLE_RESET                     0
#define MAC_PCU_GENERIC_TIMERS_MODE_ADDRESS                          0x00bc
#define MAC_PCU_GENERIC_TIMERS_MODE_HW_MASK                          0xfffff7ff
#define MAC_PCU_GENERIC_TIMERS_MODE_SW_MASK                          0xfffff7ff
#define MAC_PCU_GENERIC_TIMERS_MODE_HW_WRITE_MASK                    0x000007ff
#define MAC_PCU_GENERIC_TIMERS_MODE_SW_WRITE_MASK                    0xfffff0ff
#define MAC_PCU_GENERIC_TIMERS_MODE_RSTMASK                          0xfffff8ff
#define MAC_PCU_GENERIC_TIMERS_MODE_RESET                            0x00100000

// 0x00c0 (MAC_PCU_SLP1)
#define MAC_PCU_SLP1_CAB_TIMEOUT_MSB                                 31
#define MAC_PCU_SLP1_CAB_TIMEOUT_LSB                                 21
#define MAC_PCU_SLP1_CAB_TIMEOUT_MASK                                0xffe00000
#define MAC_PCU_SLP1_CAB_TIMEOUT_GET(x)                              (((x) & MAC_PCU_SLP1_CAB_TIMEOUT_MASK) >> MAC_PCU_SLP1_CAB_TIMEOUT_LSB)
#define MAC_PCU_SLP1_CAB_TIMEOUT_SET(x)                              (((0 | (x)) << MAC_PCU_SLP1_CAB_TIMEOUT_LSB) & MAC_PCU_SLP1_CAB_TIMEOUT_MASK)
#define MAC_PCU_SLP1_CAB_TIMEOUT_RESET                               5
#define MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_MSB                        20
#define MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_LSB                        20
#define MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_MASK                       0x00100000
#define MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_GET(x)                     (((x) & MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_MASK) >> MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_LSB)
#define MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_SET(x)                     (((0 | (x)) << MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_LSB) & MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_MASK)
#define MAC_PCU_SLP1_BUG_59985_FIX_ENABLE_RESET                      0
#define MAC_PCU_SLP1_ASSUME_DTIM_MSB                                 19
#define MAC_PCU_SLP1_ASSUME_DTIM_LSB                                 19
#define MAC_PCU_SLP1_ASSUME_DTIM_MASK                                0x00080000
#define MAC_PCU_SLP1_ASSUME_DTIM_GET(x)                              (((x) & MAC_PCU_SLP1_ASSUME_DTIM_MASK) >> MAC_PCU_SLP1_ASSUME_DTIM_LSB)
#define MAC_PCU_SLP1_ASSUME_DTIM_SET(x)                              (((0 | (x)) << MAC_PCU_SLP1_ASSUME_DTIM_LSB) & MAC_PCU_SLP1_ASSUME_DTIM_MASK)
#define MAC_PCU_SLP1_ASSUME_DTIM_RESET                               0
#define MAC_PCU_SLP1_CAB_TIMEOUT_EXT_MSB                             4
#define MAC_PCU_SLP1_CAB_TIMEOUT_EXT_LSB                             0
#define MAC_PCU_SLP1_CAB_TIMEOUT_EXT_MASK                            0x0000001f
#define MAC_PCU_SLP1_CAB_TIMEOUT_EXT_GET(x)                          (((x) & MAC_PCU_SLP1_CAB_TIMEOUT_EXT_MASK) >> MAC_PCU_SLP1_CAB_TIMEOUT_EXT_LSB)
#define MAC_PCU_SLP1_CAB_TIMEOUT_EXT_SET(x)                          (((0 | (x)) << MAC_PCU_SLP1_CAB_TIMEOUT_EXT_LSB) & MAC_PCU_SLP1_CAB_TIMEOUT_EXT_MASK)
#define MAC_PCU_SLP1_CAB_TIMEOUT_EXT_RESET                           0
#define MAC_PCU_SLP1_ADDRESS                                         0x00c0
#define MAC_PCU_SLP1_HW_MASK                                         0xfff8001f
#define MAC_PCU_SLP1_SW_MASK                                         0xfff8001f
#define MAC_PCU_SLP1_HW_WRITE_MASK                                   0x00000000
#define MAC_PCU_SLP1_SW_WRITE_MASK                                   0xfff8001f
#define MAC_PCU_SLP1_RSTMASK                                         0xffffffff
#define MAC_PCU_SLP1_RESET                                           0x00a00000

// 0x00c4 (MAC_PCU_SLP2)
#define MAC_PCU_SLP2_BEACON_TIMEOUT_MSB                              31
#define MAC_PCU_SLP2_BEACON_TIMEOUT_LSB                              21
#define MAC_PCU_SLP2_BEACON_TIMEOUT_MASK                             0xffe00000
#define MAC_PCU_SLP2_BEACON_TIMEOUT_GET(x)                           (((x) & MAC_PCU_SLP2_BEACON_TIMEOUT_MASK) >> MAC_PCU_SLP2_BEACON_TIMEOUT_LSB)
#define MAC_PCU_SLP2_BEACON_TIMEOUT_SET(x)                           (((0 | (x)) << MAC_PCU_SLP2_BEACON_TIMEOUT_LSB) & MAC_PCU_SLP2_BEACON_TIMEOUT_MASK)
#define MAC_PCU_SLP2_BEACON_TIMEOUT_RESET                            2
#define MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_MSB                          4
#define MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_LSB                          0
#define MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_MASK                         0x0000001f
#define MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_GET(x)                       (((x) & MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_MASK) >> MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_LSB)
#define MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_SET(x)                       (((0 | (x)) << MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_LSB) & MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_MASK)
#define MAC_PCU_SLP2_BEACON_TIMEOUT_EXT_RESET                        0
#define MAC_PCU_SLP2_ADDRESS                                         0x00c4
#define MAC_PCU_SLP2_HW_MASK                                         0xffe0001f
#define MAC_PCU_SLP2_SW_MASK                                         0xffe0001f
#define MAC_PCU_SLP2_HW_WRITE_MASK                                   0x00000000
#define MAC_PCU_SLP2_SW_WRITE_MASK                                   0xffe0001f
#define MAC_PCU_SLP2_RSTMASK                                         0xffffffff
#define MAC_PCU_SLP2_RESET                                           0x00400000

// 0x00c8 (MAC_PCU_SLP3)
#define MAC_PCU_SLP3_CAB_AWAKE_ENABLE_MSB                            16
#define MAC_PCU_SLP3_CAB_AWAKE_ENABLE_LSB                            16
#define MAC_PCU_SLP3_CAB_AWAKE_ENABLE_MASK                           0x00010000
#define MAC_PCU_SLP3_CAB_AWAKE_ENABLE_GET(x)                         (((x) & MAC_PCU_SLP3_CAB_AWAKE_ENABLE_MASK) >> MAC_PCU_SLP3_CAB_AWAKE_ENABLE_LSB)
#define MAC_PCU_SLP3_CAB_AWAKE_ENABLE_SET(x)                         (((0 | (x)) << MAC_PCU_SLP3_CAB_AWAKE_ENABLE_LSB) & MAC_PCU_SLP3_CAB_AWAKE_ENABLE_MASK)
#define MAC_PCU_SLP3_CAB_AWAKE_ENABLE_RESET                          0
#define MAC_PCU_SLP3_CAB_AWAKE_DUR_MSB                               15
#define MAC_PCU_SLP3_CAB_AWAKE_DUR_LSB                               0
#define MAC_PCU_SLP3_CAB_AWAKE_DUR_MASK                              0x0000ffff
#define MAC_PCU_SLP3_CAB_AWAKE_DUR_GET(x)                            (((x) & MAC_PCU_SLP3_CAB_AWAKE_DUR_MASK) >> MAC_PCU_SLP3_CAB_AWAKE_DUR_LSB)
#define MAC_PCU_SLP3_CAB_AWAKE_DUR_SET(x)                            (((0 | (x)) << MAC_PCU_SLP3_CAB_AWAKE_DUR_LSB) & MAC_PCU_SLP3_CAB_AWAKE_DUR_MASK)
#define MAC_PCU_SLP3_CAB_AWAKE_DUR_RESET                             5
#define MAC_PCU_SLP3_ADDRESS                                         0x00c8
#define MAC_PCU_SLP3_HW_MASK                                         0x0001ffff
#define MAC_PCU_SLP3_SW_MASK                                         0x0001ffff
#define MAC_PCU_SLP3_HW_WRITE_MASK                                   0x00000000
#define MAC_PCU_SLP3_SW_WRITE_MASK                                   0x0001ffff
#define MAC_PCU_SLP3_RSTMASK                                         0xffffffff
#define MAC_PCU_SLP3_RESET                                           0x00000005

// 0x00cc (MAC_PCU_SLP4)
#define MAC_PCU_SLP4_ASSUME_DTIM2_MSB                                31
#define MAC_PCU_SLP4_ASSUME_DTIM2_LSB                                31
#define MAC_PCU_SLP4_ASSUME_DTIM2_MASK                               0x80000000
#define MAC_PCU_SLP4_ASSUME_DTIM2_GET(x)                             (((x) & MAC_PCU_SLP4_ASSUME_DTIM2_MASK) >> MAC_PCU_SLP4_ASSUME_DTIM2_LSB)
#define MAC_PCU_SLP4_ASSUME_DTIM2_SET(x)                             (((0 | (x)) << MAC_PCU_SLP4_ASSUME_DTIM2_LSB) & MAC_PCU_SLP4_ASSUME_DTIM2_MASK)
#define MAC_PCU_SLP4_ASSUME_DTIM2_RESET                              0
#define MAC_PCU_SLP4_CAB2_TIMEOUT_MSB                                30
#define MAC_PCU_SLP4_CAB2_TIMEOUT_LSB                                16
#define MAC_PCU_SLP4_CAB2_TIMEOUT_MASK                               0x7fff0000
#define MAC_PCU_SLP4_CAB2_TIMEOUT_GET(x)                             (((x) & MAC_PCU_SLP4_CAB2_TIMEOUT_MASK) >> MAC_PCU_SLP4_CAB2_TIMEOUT_LSB)
#define MAC_PCU_SLP4_CAB2_TIMEOUT_SET(x)                             (((0 | (x)) << MAC_PCU_SLP4_CAB2_TIMEOUT_LSB) & MAC_PCU_SLP4_CAB2_TIMEOUT_MASK)
#define MAC_PCU_SLP4_CAB2_TIMEOUT_RESET                              5
#define MAC_PCU_SLP4_BEACON2_TIMEOUT_MSB                             15
#define MAC_PCU_SLP4_BEACON2_TIMEOUT_LSB                             0
#define MAC_PCU_SLP4_BEACON2_TIMEOUT_MASK                            0x0000ffff
#define MAC_PCU_SLP4_BEACON2_TIMEOUT_GET(x)                          (((x) & MAC_PCU_SLP4_BEACON2_TIMEOUT_MASK) >> MAC_PCU_SLP4_BEACON2_TIMEOUT_LSB)
#define MAC_PCU_SLP4_BEACON2_TIMEOUT_SET(x)                          (((0 | (x)) << MAC_PCU_SLP4_BEACON2_TIMEOUT_LSB) & MAC_PCU_SLP4_BEACON2_TIMEOUT_MASK)
#define MAC_PCU_SLP4_BEACON2_TIMEOUT_RESET                           2
#define MAC_PCU_SLP4_ADDRESS                                         0x00cc
#define MAC_PCU_SLP4_HW_MASK                                         0xffffffff
#define MAC_PCU_SLP4_SW_MASK                                         0xffffffff
#define MAC_PCU_SLP4_HW_WRITE_MASK                                   0x00000000
#define MAC_PCU_SLP4_SW_WRITE_MASK                                   0xffffffff
#define MAC_PCU_SLP4_RSTMASK                                         0xffffffff
#define MAC_PCU_SLP4_RESET                                           0x00050002

// 0x00d0 (MAC_PCU_RESET_TSF)
#define MAC_PCU_RESET_TSF_ONE_SHOT2_MSB                              25
#define MAC_PCU_RESET_TSF_ONE_SHOT2_LSB                              25
#define MAC_PCU_RESET_TSF_ONE_SHOT2_MASK                             0x02000000
#define MAC_PCU_RESET_TSF_ONE_SHOT2_GET(x)                           (((x) & MAC_PCU_RESET_TSF_ONE_SHOT2_MASK) >> MAC_PCU_RESET_TSF_ONE_SHOT2_LSB)
#define MAC_PCU_RESET_TSF_ONE_SHOT2_SET(x)                           (((0 | (x)) << MAC_PCU_RESET_TSF_ONE_SHOT2_LSB) & MAC_PCU_RESET_TSF_ONE_SHOT2_MASK)
#define MAC_PCU_RESET_TSF_ONE_SHOT2_RESET                            0
#define MAC_PCU_RESET_TSF_ONE_SHOT_MSB                               24
#define MAC_PCU_RESET_TSF_ONE_SHOT_LSB                               24
#define MAC_PCU_RESET_TSF_ONE_SHOT_MASK                              0x01000000
#define MAC_PCU_RESET_TSF_ONE_SHOT_GET(x)                            (((x) & MAC_PCU_RESET_TSF_ONE_SHOT_MASK) >> MAC_PCU_RESET_TSF_ONE_SHOT_LSB)
#define MAC_PCU_RESET_TSF_ONE_SHOT_SET(x)                            (((0 | (x)) << MAC_PCU_RESET_TSF_ONE_SHOT_LSB) & MAC_PCU_RESET_TSF_ONE_SHOT_MASK)
#define MAC_PCU_RESET_TSF_ONE_SHOT_RESET                             0
#define MAC_PCU_RESET_TSF_ADDRESS                                    0x00d0
#define MAC_PCU_RESET_TSF_HW_MASK                                    0x03000000
#define MAC_PCU_RESET_TSF_SW_MASK                                    0x03000000
#define MAC_PCU_RESET_TSF_HW_WRITE_MASK                              0x03000000
#define MAC_PCU_RESET_TSF_SW_WRITE_MASK                              0x03000000
#define MAC_PCU_RESET_TSF_RSTMASK                                    0xffffffff
#define MAC_PCU_RESET_TSF_RESET                                      0x00000000

// 0x00d4 (MAC_PCU_TSF2_L32)
#define MAC_PCU_TSF2_L32_VALUE_MSB                                   31
#define MAC_PCU_TSF2_L32_VALUE_LSB                                   0
#define MAC_PCU_TSF2_L32_VALUE_MASK                                  0xffffffff
#define MAC_PCU_TSF2_L32_VALUE_GET(x)                                (((x) & MAC_PCU_TSF2_L32_VALUE_MASK) >> MAC_PCU_TSF2_L32_VALUE_LSB)
#define MAC_PCU_TSF2_L32_VALUE_SET(x)                                (((0 | (x)) << MAC_PCU_TSF2_L32_VALUE_LSB) & MAC_PCU_TSF2_L32_VALUE_MASK)
#define MAC_PCU_TSF2_L32_VALUE_RESET                                 268435455
#define MAC_PCU_TSF2_L32_ADDRESS                                     0x00d4
#define MAC_PCU_TSF2_L32_HW_MASK                                     0xffffffff
#define MAC_PCU_TSF2_L32_SW_MASK                                     0xffffffff
#define MAC_PCU_TSF2_L32_HW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TSF2_L32_SW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TSF2_L32_RSTMASK                                     0xffffffff
#define MAC_PCU_TSF2_L32_RESET                                       0x0fffffff

// 0x00d8 (MAC_PCU_TSF2_U32)
#define MAC_PCU_TSF2_U32_VALUE_MSB                                   31
#define MAC_PCU_TSF2_U32_VALUE_LSB                                   0
#define MAC_PCU_TSF2_U32_VALUE_MASK                                  0xffffffff
#define MAC_PCU_TSF2_U32_VALUE_GET(x)                                (((x) & MAC_PCU_TSF2_U32_VALUE_MASK) >> MAC_PCU_TSF2_U32_VALUE_LSB)
#define MAC_PCU_TSF2_U32_VALUE_SET(x)                                (((0 | (x)) << MAC_PCU_TSF2_U32_VALUE_LSB) & MAC_PCU_TSF2_U32_VALUE_MASK)
#define MAC_PCU_TSF2_U32_VALUE_RESET                                 268435455
#define MAC_PCU_TSF2_U32_ADDRESS                                     0x00d8
#define MAC_PCU_TSF2_U32_HW_MASK                                     0xffffffff
#define MAC_PCU_TSF2_U32_SW_MASK                                     0xffffffff
#define MAC_PCU_TSF2_U32_HW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TSF2_U32_SW_WRITE_MASK                               0xffffffff
#define MAC_PCU_TSF2_U32_RSTMASK                                     0xffffffff
#define MAC_PCU_TSF2_U32_RESET                                       0x0fffffff

// 0x00dc (MAC_PCU_GENERIC_TIMERS2_0)
#define MAC_PCU_GENERIC_TIMERS2_0_DATA_MSB                           31
#define MAC_PCU_GENERIC_TIMERS2_0_DATA_LSB                           0
#define MAC_PCU_GENERIC_TIMERS2_0_DATA_MASK                          0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_0_DATA_GET(x)                        (((x) & MAC_PCU_GENERIC_TIMERS2_0_DATA_MASK) >> MAC_PCU_GENERIC_TIMERS2_0_DATA_LSB)
#define MAC_PCU_GENERIC_TIMERS2_0_DATA_SET(x)                        (((0 | (x)) << MAC_PCU_GENERIC_TIMERS2_0_DATA_LSB) & MAC_PCU_GENERIC_TIMERS2_0_DATA_MASK)
#define MAC_PCU_GENERIC_TIMERS2_0_DATA_RESET                         0
#define MAC_PCU_GENERIC_TIMERS2_0_ADDRESS                            0x00dc
#define MAC_PCU_GENERIC_TIMERS2_ADDRESS                              MAC_PCU_GENERIC_TIMERS2_0_ADDRESS
#define MAC_PCU_GENERIC_TIMERS2_0_HW_MASK                            0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_0_SW_MASK                            0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_0_HW_WRITE_MASK                      0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_0_SW_WRITE_MASK                      0xffffffff
#define MAC_PCU_GENERIC_TIMERS2_0_RSTMASK                            0x00000000
#define MAC_PCU_GENERIC_TIMERS2_0_RESET                              0x00000000

// Skip e0 (MAC_PCU_GENERIC_TIMERS2_1) - 118 (MAC_PCU_GENERIC_TIMERS2_15) for brevity
// 0x0134 (MAC_PCU_GENERIC_TIMERS_MODE2)
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_MSB             15
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_LSB             12
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_MASK            0x0000f000
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_GET(x)          (((x) & MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_MASK) >> MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_LSB)
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_SET(x)          (((0 | (x)) << MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_LSB) & MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_MASK)
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX2_RESET           0
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_MSB              11
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_LSB              8
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_MASK             0x00000f00
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_GET(x)           (((x) & MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_MASK) >> MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_LSB)
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_SET(x)           (((0 | (x)) << MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_LSB) & MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_MASK)
#define MAC_PCU_GENERIC_TIMERS_MODE2_OVERFLOW_INDEX_RESET            0
#define MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_MSB                      7
#define MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_LSB                      0
#define MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_MASK                     0x000000ff
#define MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_GET(x)                   (((x) & MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_MASK) >> MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_LSB)
#define MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_SET(x)                   (((0 | (x)) << MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_LSB) & MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_MASK)
#define MAC_PCU_GENERIC_TIMERS_MODE2_ENABLE_RESET                    0
#define MAC_PCU_GENERIC_TIMERS_MODE2_ADDRESS                         0x0134
#define MAC_PCU_GENERIC_TIMERS_MODE2_HW_MASK                         0x0000ffff
#define MAC_PCU_GENERIC_TIMERS_MODE2_SW_MASK                         0x0000ffff
#define MAC_PCU_GENERIC_TIMERS_MODE2_HW_WRITE_MASK                   0x0000ffff
#define MAC_PCU_GENERIC_TIMERS_MODE2_SW_WRITE_MASK                   0x000000ff
#define MAC_PCU_GENERIC_TIMERS_MODE2_RSTMASK                         0xffff00ff
#define MAC_PCU_GENERIC_TIMERS_MODE2_RESET                           0x00000000

// 0x0144 (MAC_PCU_TSF_THRESHOLD)
#define MAC_PCU_TSF_THRESHOLD_VALUE_MSB                              15
#define MAC_PCU_TSF_THRESHOLD_VALUE_LSB                              0
#define MAC_PCU_TSF_THRESHOLD_VALUE_MASK                             0x0000ffff
#define MAC_PCU_TSF_THRESHOLD_VALUE_GET(x)                           (((x) & MAC_PCU_TSF_THRESHOLD_VALUE_MASK) >> MAC_PCU_TSF_THRESHOLD_VALUE_LSB)
#define MAC_PCU_TSF_THRESHOLD_VALUE_SET(x)                           (((0 | (x)) << MAC_PCU_TSF_THRESHOLD_VALUE_LSB) & MAC_PCU_TSF_THRESHOLD_VALUE_MASK)
#define MAC_PCU_TSF_THRESHOLD_VALUE_RESET                            65535
#define MAC_PCU_TSF_THRESHOLD_ADDRESS                                0x0144
#define MAC_PCU_TSF_THRESHOLD_HW_MASK                                0x0000ffff
#define MAC_PCU_TSF_THRESHOLD_SW_MASK                                0x0000ffff
#define MAC_PCU_TSF_THRESHOLD_HW_WRITE_MASK                          0x00000000
#define MAC_PCU_TSF_THRESHOLD_SW_WRITE_MASK                          0x0000ffff
#define MAC_PCU_TSF_THRESHOLD_RSTMASK                                0xffffffff
#define MAC_PCU_TSF_THRESHOLD_RESET                                  0x0000ffff

// 0x0148 (WLAN_HT)
#define WLAN_HT_MODE_MSB                                             0
#define WLAN_HT_MODE_LSB                                             0
#define WLAN_HT_MODE_MASK                                            0x00000001
#define WLAN_HT_MODE_GET(x)                                          (((x) & WLAN_HT_MODE_MASK) >> WLAN_HT_MODE_LSB)
#define WLAN_HT_MODE_SET(x)                                          (((0 | (x)) << WLAN_HT_MODE_LSB) & WLAN_HT_MODE_MASK)
#define WLAN_HT_MODE_RESET                                           0
#define WLAN_HT_ADDRESS                                              0x0148
#define WLAN_HT_HW_MASK                                              0x00000001
#define WLAN_HT_SW_MASK                                              0x00000001
#define WLAN_HT_HW_WRITE_MASK                                        0x00000000
#define WLAN_HT_SW_WRITE_MASK                                        0x00000001
#define WLAN_HT_RSTMASK                                              0xffffffff
#define WLAN_HT_RESET                                                0x00000000

// 0x0150 (MAC_PCU_GENERIC_TIMERS_TSF_SEL)
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_MSB                     15
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_LSB                     0
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_MASK                    0x0000ffff
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_GET(x)                  (((x) & MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_MASK) >> MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_LSB)
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_SET(x)                  (((0 | (x)) << MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_LSB) & MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_MASK)
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_VALUE_RESET                   0
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_ADDRESS                       0x0150
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_HW_MASK                       0x0000ffff
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_SW_MASK                       0x0000ffff
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_HW_WRITE_MASK                 0x0000ffff
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_SW_WRITE_MASK                 0x0000ffff
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_RSTMASK                       0xffffffff
#define MAC_PCU_GENERIC_TIMERS_TSF_SEL_RESET                         0x00000000

// 0x0154 (MAC_PCU_BMISS_TIMEOUT)
#define MAC_PCU_BMISS_TIMEOUT_ENABLE_MSB                             24
#define MAC_PCU_BMISS_TIMEOUT_ENABLE_LSB                             24
#define MAC_PCU_BMISS_TIMEOUT_ENABLE_MASK                            0x01000000
#define MAC_PCU_BMISS_TIMEOUT_ENABLE_GET(x)                          (((x) & MAC_PCU_BMISS_TIMEOUT_ENABLE_MASK) >> MAC_PCU_BMISS_TIMEOUT_ENABLE_LSB)
#define MAC_PCU_BMISS_TIMEOUT_ENABLE_SET(x)                          (((0 | (x)) << MAC_PCU_BMISS_TIMEOUT_ENABLE_LSB) & MAC_PCU_BMISS_TIMEOUT_ENABLE_MASK)
#define MAC_PCU_BMISS_TIMEOUT_ENABLE_RESET                           0
#define MAC_PCU_BMISS_TIMEOUT_VALUE_MSB                              23
#define MAC_PCU_BMISS_TIMEOUT_VALUE_LSB                              0
#define MAC_PCU_BMISS_TIMEOUT_VALUE_MASK                             0x00ffffff
#define MAC_PCU_BMISS_TIMEOUT_VALUE_GET(x)                           (((x) & MAC_PCU_BMISS_TIMEOUT_VALUE_MASK) >> MAC_PCU_BMISS_TIMEOUT_VALUE_LSB)
#define MAC_PCU_BMISS_TIMEOUT_VALUE_SET(x)                           (((0 | (x)) << MAC_PCU_BMISS_TIMEOUT_VALUE_LSB) & MAC_PCU_BMISS_TIMEOUT_VALUE_MASK)
#define MAC_PCU_BMISS_TIMEOUT_VALUE_RESET                            16777215
#define MAC_PCU_BMISS_TIMEOUT_ADDRESS                                0x0154
#define MAC_PCU_BMISS_TIMEOUT_HW_MASK                                0x01ffffff
#define MAC_PCU_BMISS_TIMEOUT_SW_MASK                                0x01ffffff
#define MAC_PCU_BMISS_TIMEOUT_HW_WRITE_MASK                          0x00000000
#define MAC_PCU_BMISS_TIMEOUT_SW_WRITE_MASK                          0x01ffffff
#define MAC_PCU_BMISS_TIMEOUT_RSTMASK                                0xffffffff
#define MAC_PCU_BMISS_TIMEOUT_RESET                                  0x00ffffff

// 0x0158 (MAC_PCU_BMISS2_TIMEOUT)
#define MAC_PCU_BMISS2_TIMEOUT_ENABLE_MSB                            24
#define MAC_PCU_BMISS2_TIMEOUT_ENABLE_LSB                            24
#define MAC_PCU_BMISS2_TIMEOUT_ENABLE_MASK                           0x01000000
#define MAC_PCU_BMISS2_TIMEOUT_ENABLE_GET(x)                         (((x) & MAC_PCU_BMISS2_TIMEOUT_ENABLE_MASK) >> MAC_PCU_BMISS2_TIMEOUT_ENABLE_LSB)
#define MAC_PCU_BMISS2_TIMEOUT_ENABLE_SET(x)                         (((0 | (x)) << MAC_PCU_BMISS2_TIMEOUT_ENABLE_LSB) & MAC_PCU_BMISS2_TIMEOUT_ENABLE_MASK)
#define MAC_PCU_BMISS2_TIMEOUT_ENABLE_RESET                          0
#define MAC_PCU_BMISS2_TIMEOUT_VALUE_MSB                             23
#define MAC_PCU_BMISS2_TIMEOUT_VALUE_LSB                             0
#define MAC_PCU_BMISS2_TIMEOUT_VALUE_MASK                            0x00ffffff
#define MAC_PCU_BMISS2_TIMEOUT_VALUE_GET(x)                          (((x) & MAC_PCU_BMISS2_TIMEOUT_VALUE_MASK) >> MAC_PCU_BMISS2_TIMEOUT_VALUE_LSB)
#define MAC_PCU_BMISS2_TIMEOUT_VALUE_SET(x)                          (((0 | (x)) << MAC_PCU_BMISS2_TIMEOUT_VALUE_LSB) & MAC_PCU_BMISS2_TIMEOUT_VALUE_MASK)
#define MAC_PCU_BMISS2_TIMEOUT_VALUE_RESET                           16777215
#define MAC_PCU_BMISS2_TIMEOUT_ADDRESS                               0x0158
#define MAC_PCU_BMISS2_TIMEOUT_HW_MASK                               0x01ffffff
#define MAC_PCU_BMISS2_TIMEOUT_SW_MASK                               0x01ffffff
#define MAC_PCU_BMISS2_TIMEOUT_HW_WRITE_MASK                         0x00000000
#define MAC_PCU_BMISS2_TIMEOUT_SW_WRITE_MASK                         0x01ffffff
#define MAC_PCU_BMISS2_TIMEOUT_RSTMASK                               0xffffffff
#define MAC_PCU_BMISS2_TIMEOUT_RESET                                 0x00ffffff

// 0x0160 (UNIFIED_MAC_REVID)
#define UNIFIED_MAC_REVID_VALUE_MSB                                  31
#define UNIFIED_MAC_REVID_VALUE_LSB                                  0
#define UNIFIED_MAC_REVID_VALUE_MASK                                 0xffffffff
#define UNIFIED_MAC_REVID_VALUE_GET(x)                               (((x) & UNIFIED_MAC_REVID_VALUE_MASK) >> UNIFIED_MAC_REVID_VALUE_LSB)
#define UNIFIED_MAC_REVID_VALUE_SET(x)                               (((0 | (x)) << UNIFIED_MAC_REVID_VALUE_LSB) & UNIFIED_MAC_REVID_VALUE_MASK)
#define UNIFIED_MAC_REVID_VALUE_RESET                                0
#define UNIFIED_MAC_REVID_ADDRESS                                    0x0160
#define UNIFIED_MAC_REVID_HW_MASK                                    0xffffffff
#define UNIFIED_MAC_REVID_SW_MASK                                    0xffffffff
#define UNIFIED_MAC_REVID_HW_WRITE_MASK                              0xffffffff
#define UNIFIED_MAC_REVID_SW_WRITE_MASK                              0x00000000
#define UNIFIED_MAC_REVID_RSTMASK                                    0x00000000
#define UNIFIED_MAC_REVID_RESET                                      0x00000000


#endif /* _RTC_WLAN_REG_H_ */
