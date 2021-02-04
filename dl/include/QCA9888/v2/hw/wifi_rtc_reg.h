/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _WIFI_RTC_REG_H_
#define _WIFI_RTC_REG_H_


#ifndef __WIFI_RTC_REG_BASE_ADDRESS
#define __WIFI_RTC_REG_BASE_ADDRESS (0x45000)
#endif


// 0x0 (WIFI_RESET_CONTROL)
#define WIFI_RESET_CONTROL_APB_SRIF_RESET_LSB                                  9
#define WIFI_RESET_CONTROL_APB_SRIF_RESET_MSB                                  9
#define WIFI_RESET_CONTROL_APB_SRIF_RESET_MASK                                 0x200
#define WIFI_RESET_CONTROL_APB_SRIF_RESET_GET(x)                               (((x) & WIFI_RESET_CONTROL_APB_SRIF_RESET_MASK) >> WIFI_RESET_CONTROL_APB_SRIF_RESET_LSB)
#define WIFI_RESET_CONTROL_APB_SRIF_RESET_SET(x)                               (((0 | (x)) << WIFI_RESET_CONTROL_APB_SRIF_RESET_LSB) & WIFI_RESET_CONTROL_APB_SRIF_RESET_MASK)
#define WIFI_RESET_CONTROL_APB_SRIF_RESET_RESET                                0x0
#define WIFI_RESET_CONTROL_CE_RESET_LSB                                        8
#define WIFI_RESET_CONTROL_CE_RESET_MSB                                        8
#define WIFI_RESET_CONTROL_CE_RESET_MASK                                       0x100
#define WIFI_RESET_CONTROL_CE_RESET_GET(x)                                     (((x) & WIFI_RESET_CONTROL_CE_RESET_MASK) >> WIFI_RESET_CONTROL_CE_RESET_LSB)
#define WIFI_RESET_CONTROL_CE_RESET_SET(x)                                     (((0 | (x)) << WIFI_RESET_CONTROL_CE_RESET_LSB) & WIFI_RESET_CONTROL_CE_RESET_MASK)
#define WIFI_RESET_CONTROL_CE_RESET_RESET                                      0x0
#define WIFI_RESET_CONTROL_MCI_RESET_LSB                                       7
#define WIFI_RESET_CONTROL_MCI_RESET_MSB                                       7
#define WIFI_RESET_CONTROL_MCI_RESET_MASK                                      0x80
#define WIFI_RESET_CONTROL_MCI_RESET_GET(x)                                    (((x) & WIFI_RESET_CONTROL_MCI_RESET_MASK) >> WIFI_RESET_CONTROL_MCI_RESET_LSB)
#define WIFI_RESET_CONTROL_MCI_RESET_SET(x)                                    (((0 | (x)) << WIFI_RESET_CONTROL_MCI_RESET_LSB) & WIFI_RESET_CONTROL_MCI_RESET_MASK)
#define WIFI_RESET_CONTROL_MCI_RESET_RESET                                     0x0
#define WIFI_RESET_CONTROL_RADIO_SRESET_LSB                                    6
#define WIFI_RESET_CONTROL_RADIO_SRESET_MSB                                    6
#define WIFI_RESET_CONTROL_RADIO_SRESET_MASK                                   0x40
#define WIFI_RESET_CONTROL_RADIO_SRESET_GET(x)                                 (((x) & WIFI_RESET_CONTROL_RADIO_SRESET_MASK) >> WIFI_RESET_CONTROL_RADIO_SRESET_LSB)
#define WIFI_RESET_CONTROL_RADIO_SRESET_SET(x)                                 (((0 | (x)) << WIFI_RESET_CONTROL_RADIO_SRESET_LSB) & WIFI_RESET_CONTROL_RADIO_SRESET_MASK)
#define WIFI_RESET_CONTROL_RADIO_SRESET_RESET                                  0x1
#define WIFI_RESET_CONTROL_BB_COLD_RST_LSB                                     5
#define WIFI_RESET_CONTROL_BB_COLD_RST_MSB                                     5
#define WIFI_RESET_CONTROL_BB_COLD_RST_MASK                                    0x20
#define WIFI_RESET_CONTROL_BB_COLD_RST_GET(x)                                  (((x) & WIFI_RESET_CONTROL_BB_COLD_RST_MASK) >> WIFI_RESET_CONTROL_BB_COLD_RST_LSB)
#define WIFI_RESET_CONTROL_BB_COLD_RST_SET(x)                                  (((0 | (x)) << WIFI_RESET_CONTROL_BB_COLD_RST_LSB) & WIFI_RESET_CONTROL_BB_COLD_RST_MASK)
#define WIFI_RESET_CONTROL_BB_COLD_RST_RESET                                   0x1
#define WIFI_RESET_CONTROL_BB_WARM_RST_LSB                                     4
#define WIFI_RESET_CONTROL_BB_WARM_RST_MSB                                     4
#define WIFI_RESET_CONTROL_BB_WARM_RST_MASK                                    0x10
#define WIFI_RESET_CONTROL_BB_WARM_RST_GET(x)                                  (((x) & WIFI_RESET_CONTROL_BB_WARM_RST_MASK) >> WIFI_RESET_CONTROL_BB_WARM_RST_LSB)
#define WIFI_RESET_CONTROL_BB_WARM_RST_SET(x)                                  (((0 | (x)) << WIFI_RESET_CONTROL_BB_WARM_RST_LSB) & WIFI_RESET_CONTROL_BB_WARM_RST_MASK)
#define WIFI_RESET_CONTROL_BB_WARM_RST_RESET                                   0x1
#define WIFI_RESET_CONTROL_MAC_SM_RST_LSB                                      2
#define WIFI_RESET_CONTROL_MAC_SM_RST_MSB                                      2
#define WIFI_RESET_CONTROL_MAC_SM_RST_MASK                                     0x4
#define WIFI_RESET_CONTROL_MAC_SM_RST_GET(x)                                   (((x) & WIFI_RESET_CONTROL_MAC_SM_RST_MASK) >> WIFI_RESET_CONTROL_MAC_SM_RST_LSB)
#define WIFI_RESET_CONTROL_MAC_SM_RST_SET(x)                                   (((0 | (x)) << WIFI_RESET_CONTROL_MAC_SM_RST_LSB) & WIFI_RESET_CONTROL_MAC_SM_RST_MASK)
#define WIFI_RESET_CONTROL_MAC_SM_RST_RESET                                    0x0
#define WIFI_RESET_CONTROL_MAC_COLD_RST_LSB                                    1
#define WIFI_RESET_CONTROL_MAC_COLD_RST_MSB                                    1
#define WIFI_RESET_CONTROL_MAC_COLD_RST_MASK                                   0x2
#define WIFI_RESET_CONTROL_MAC_COLD_RST_GET(x)                                 (((x) & WIFI_RESET_CONTROL_MAC_COLD_RST_MASK) >> WIFI_RESET_CONTROL_MAC_COLD_RST_LSB)
#define WIFI_RESET_CONTROL_MAC_COLD_RST_SET(x)                                 (((0 | (x)) << WIFI_RESET_CONTROL_MAC_COLD_RST_LSB) & WIFI_RESET_CONTROL_MAC_COLD_RST_MASK)
#define WIFI_RESET_CONTROL_MAC_COLD_RST_RESET                                  0x1
#define WIFI_RESET_CONTROL_MAC_WARM_RST_LSB                                    0
#define WIFI_RESET_CONTROL_MAC_WARM_RST_MSB                                    0
#define WIFI_RESET_CONTROL_MAC_WARM_RST_MASK                                   0x1
#define WIFI_RESET_CONTROL_MAC_WARM_RST_GET(x)                                 (((x) & WIFI_RESET_CONTROL_MAC_WARM_RST_MASK) >> WIFI_RESET_CONTROL_MAC_WARM_RST_LSB)
#define WIFI_RESET_CONTROL_MAC_WARM_RST_SET(x)                                 (((0 | (x)) << WIFI_RESET_CONTROL_MAC_WARM_RST_LSB) & WIFI_RESET_CONTROL_MAC_WARM_RST_MASK)
#define WIFI_RESET_CONTROL_MAC_WARM_RST_RESET                                  0x1
#define WIFI_RESET_CONTROL_ADDRESS                                             (0x0 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_RESET_CONTROL_RSTMASK                                             0x3f7
#define WIFI_RESET_CONTROL_RESET                                               0x73

// 0x4 (WIFI_XTAL_CONTROL)
#define WIFI_XTAL_CONTROL_TCXO_LSB                                             0
#define WIFI_XTAL_CONTROL_TCXO_MSB                                             0
#define WIFI_XTAL_CONTROL_TCXO_MASK                                            0x1
#define WIFI_XTAL_CONTROL_TCXO_GET(x)                                          (((x) & WIFI_XTAL_CONTROL_TCXO_MASK) >> WIFI_XTAL_CONTROL_TCXO_LSB)
#define WIFI_XTAL_CONTROL_TCXO_SET(x)                                          (((0 | (x)) << WIFI_XTAL_CONTROL_TCXO_LSB) & WIFI_XTAL_CONTROL_TCXO_MASK)
#define WIFI_XTAL_CONTROL_TCXO_RESET                                           0x0
#define WIFI_XTAL_CONTROL_ADDRESS                                              (0x4 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_XTAL_CONTROL_RSTMASK                                              0x1
#define WIFI_XTAL_CONTROL_RESET                                                0x0

// 0x10 (WIFI_QUADRATURE)
#define WIFI_QUADRATURE_ADC_LSB                                                4
#define WIFI_QUADRATURE_ADC_MSB                                                7
#define WIFI_QUADRATURE_ADC_MASK                                               0xf0
#define WIFI_QUADRATURE_ADC_GET(x)                                             (((x) & WIFI_QUADRATURE_ADC_MASK) >> WIFI_QUADRATURE_ADC_LSB)
#define WIFI_QUADRATURE_ADC_SET(x)                                             (((0 | (x)) << WIFI_QUADRATURE_ADC_LSB) & WIFI_QUADRATURE_ADC_MASK)
#define WIFI_QUADRATURE_ADC_RESET                                              0x0
#define WIFI_QUADRATURE_DAC_LSB                                                0
#define WIFI_QUADRATURE_DAC_MSB                                                2
#define WIFI_QUADRATURE_DAC_MASK                                               0x7
#define WIFI_QUADRATURE_DAC_GET(x)                                             (((x) & WIFI_QUADRATURE_DAC_MASK) >> WIFI_QUADRATURE_DAC_LSB)
#define WIFI_QUADRATURE_DAC_SET(x)                                             (((0 | (x)) << WIFI_QUADRATURE_DAC_LSB) & WIFI_QUADRATURE_DAC_MASK)
#define WIFI_QUADRATURE_DAC_RESET                                              0x0
#define WIFI_QUADRATURE_ADDRESS                                                (0x10 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_QUADRATURE_RSTMASK                                                0xf7
#define WIFI_QUADRATURE_RESET                                                  0x0

// 0x14 (WIFI_PLL_CONTROL)
#define WIFI_PLL_CONTROL_DIG_TEST_CLK_LSB                                      20
#define WIFI_PLL_CONTROL_DIG_TEST_CLK_MSB                                      20
#define WIFI_PLL_CONTROL_DIG_TEST_CLK_MASK                                     0x100000
#define WIFI_PLL_CONTROL_DIG_TEST_CLK_GET(x)                                   (((x) & WIFI_PLL_CONTROL_DIG_TEST_CLK_MASK) >> WIFI_PLL_CONTROL_DIG_TEST_CLK_LSB)
#define WIFI_PLL_CONTROL_DIG_TEST_CLK_SET(x)                                   (((0 | (x)) << WIFI_PLL_CONTROL_DIG_TEST_CLK_LSB) & WIFI_PLL_CONTROL_DIG_TEST_CLK_MASK)
#define WIFI_PLL_CONTROL_DIG_TEST_CLK_RESET                                    0x0
#define WIFI_PLL_CONTROL_MAC_OVERRIDE_LSB                                      19
#define WIFI_PLL_CONTROL_MAC_OVERRIDE_MSB                                      19
#define WIFI_PLL_CONTROL_MAC_OVERRIDE_MASK                                     0x80000
#define WIFI_PLL_CONTROL_MAC_OVERRIDE_GET(x)                                   (((x) & WIFI_PLL_CONTROL_MAC_OVERRIDE_MASK) >> WIFI_PLL_CONTROL_MAC_OVERRIDE_LSB)
#define WIFI_PLL_CONTROL_MAC_OVERRIDE_SET(x)                                   (((0 | (x)) << WIFI_PLL_CONTROL_MAC_OVERRIDE_LSB) & WIFI_PLL_CONTROL_MAC_OVERRIDE_MASK)
#define WIFI_PLL_CONTROL_MAC_OVERRIDE_RESET                                    0x0
#define WIFI_PLL_CONTROL_NOPWD_LSB                                             18
#define WIFI_PLL_CONTROL_NOPWD_MSB                                             18
#define WIFI_PLL_CONTROL_NOPWD_MASK                                            0x40000
#define WIFI_PLL_CONTROL_NOPWD_GET(x)                                          (((x) & WIFI_PLL_CONTROL_NOPWD_MASK) >> WIFI_PLL_CONTROL_NOPWD_LSB)
#define WIFI_PLL_CONTROL_NOPWD_SET(x)                                          (((0 | (x)) << WIFI_PLL_CONTROL_NOPWD_LSB) & WIFI_PLL_CONTROL_NOPWD_MASK)
#define WIFI_PLL_CONTROL_NOPWD_RESET                                           0x0
#define WIFI_PLL_CONTROL_UPDATING_LSB                                          17
#define WIFI_PLL_CONTROL_UPDATING_MSB                                          17
#define WIFI_PLL_CONTROL_UPDATING_MASK                                         0x20000
#define WIFI_PLL_CONTROL_UPDATING_GET(x)                                       (((x) & WIFI_PLL_CONTROL_UPDATING_MASK) >> WIFI_PLL_CONTROL_UPDATING_LSB)
#define WIFI_PLL_CONTROL_UPDATING_SET(x)                                       (((0 | (x)) << WIFI_PLL_CONTROL_UPDATING_LSB) & WIFI_PLL_CONTROL_UPDATING_MASK)
#define WIFI_PLL_CONTROL_UPDATING_RESET                                        0x0
#define WIFI_PLL_CONTROL_BYPASS_LSB                                            16
#define WIFI_PLL_CONTROL_BYPASS_MSB                                            16
#define WIFI_PLL_CONTROL_BYPASS_MASK                                           0x10000
#define WIFI_PLL_CONTROL_BYPASS_GET(x)                                         (((x) & WIFI_PLL_CONTROL_BYPASS_MASK) >> WIFI_PLL_CONTROL_BYPASS_LSB)
#define WIFI_PLL_CONTROL_BYPASS_SET(x)                                         (((0 | (x)) << WIFI_PLL_CONTROL_BYPASS_LSB) & WIFI_PLL_CONTROL_BYPASS_MASK)
#define WIFI_PLL_CONTROL_BYPASS_RESET                                          0x1
#define WIFI_PLL_CONTROL_CLK_SEL_LSB                                           14
#define WIFI_PLL_CONTROL_CLK_SEL_MSB                                           15
#define WIFI_PLL_CONTROL_CLK_SEL_MASK                                          0xc000
#define WIFI_PLL_CONTROL_CLK_SEL_GET(x)                                        (((x) & WIFI_PLL_CONTROL_CLK_SEL_MASK) >> WIFI_PLL_CONTROL_CLK_SEL_LSB)
#define WIFI_PLL_CONTROL_CLK_SEL_SET(x)                                        (((0 | (x)) << WIFI_PLL_CONTROL_CLK_SEL_LSB) & WIFI_PLL_CONTROL_CLK_SEL_MASK)
#define WIFI_PLL_CONTROL_CLK_SEL_RESET                                         0x0
#define WIFI_PLL_CONTROL_REFDIV_LSB                                            10
#define WIFI_PLL_CONTROL_REFDIV_MSB                                            13
#define WIFI_PLL_CONTROL_REFDIV_MASK                                           0x3c00
#define WIFI_PLL_CONTROL_REFDIV_GET(x)                                         (((x) & WIFI_PLL_CONTROL_REFDIV_MASK) >> WIFI_PLL_CONTROL_REFDIV_LSB)
#define WIFI_PLL_CONTROL_REFDIV_SET(x)                                         (((0 | (x)) << WIFI_PLL_CONTROL_REFDIV_LSB) & WIFI_PLL_CONTROL_REFDIV_MASK)
#define WIFI_PLL_CONTROL_REFDIV_RESET                                          0x5
#define WIFI_PLL_CONTROL_DIV_LSB                                               0
#define WIFI_PLL_CONTROL_DIV_MSB                                               9
#define WIFI_PLL_CONTROL_DIV_MASK                                              0x3ff
#define WIFI_PLL_CONTROL_DIV_GET(x)                                            (((x) & WIFI_PLL_CONTROL_DIV_MASK) >> WIFI_PLL_CONTROL_DIV_LSB)
#define WIFI_PLL_CONTROL_DIV_SET(x)                                            (((0 | (x)) << WIFI_PLL_CONTROL_DIV_LSB) & WIFI_PLL_CONTROL_DIV_MASK)
#define WIFI_PLL_CONTROL_DIV_RESET                                             0x58
#define WIFI_PLL_CONTROL_ADDRESS                                               (0x14 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_PLL_CONTROL_RSTMASK                                               0x1fffff
#define WIFI_PLL_CONTROL_RESET                                                 0x11458

// 0x18 (WIFI_PLL_SETTLE)
#define WIFI_PLL_SETTLE_TIME_LSB                                               0
#define WIFI_PLL_SETTLE_TIME_MSB                                               10
#define WIFI_PLL_SETTLE_TIME_MASK                                              0x7ff
#define WIFI_PLL_SETTLE_TIME_GET(x)                                            (((x) & WIFI_PLL_SETTLE_TIME_MASK) >> WIFI_PLL_SETTLE_TIME_LSB)
#define WIFI_PLL_SETTLE_TIME_SET(x)                                            (((0 | (x)) << WIFI_PLL_SETTLE_TIME_LSB) & WIFI_PLL_SETTLE_TIME_MASK)
#define WIFI_PLL_SETTLE_TIME_RESET                                             0x400
#define WIFI_PLL_SETTLE_ADDRESS                                                (0x18 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_PLL_SETTLE_RSTMASK                                                0x7ff
#define WIFI_PLL_SETTLE_RESET                                                  0x400

// 0x1c (WIFI_XTAL_SETTLE)
#define WIFI_XTAL_SETTLE_TIME_LSB                                              0
#define WIFI_XTAL_SETTLE_TIME_MSB                                              6
#define WIFI_XTAL_SETTLE_TIME_MASK                                             0x7f
#define WIFI_XTAL_SETTLE_TIME_GET(x)                                           (((x) & WIFI_XTAL_SETTLE_TIME_MASK) >> WIFI_XTAL_SETTLE_TIME_LSB)
#define WIFI_XTAL_SETTLE_TIME_SET(x)                                           (((0 | (x)) << WIFI_XTAL_SETTLE_TIME_LSB) & WIFI_XTAL_SETTLE_TIME_MASK)
#define WIFI_XTAL_SETTLE_TIME_RESET                                            0x42
#define WIFI_XTAL_SETTLE_ADDRESS                                               (0x1c + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_XTAL_SETTLE_RSTMASK                                               0x7f
#define WIFI_XTAL_SETTLE_RESET                                                 0x42

// 0x20 (WIFI_CLOCK_OUT)
#define WIFI_CLOCK_OUT_DELAY_LSB                                               4
#define WIFI_CLOCK_OUT_DELAY_MSB                                               6
#define WIFI_CLOCK_OUT_DELAY_MASK                                              0x70
#define WIFI_CLOCK_OUT_DELAY_GET(x)                                            (((x) & WIFI_CLOCK_OUT_DELAY_MASK) >> WIFI_CLOCK_OUT_DELAY_LSB)
#define WIFI_CLOCK_OUT_DELAY_SET(x)                                            (((0 | (x)) << WIFI_CLOCK_OUT_DELAY_LSB) & WIFI_CLOCK_OUT_DELAY_MASK)
#define WIFI_CLOCK_OUT_DELAY_RESET                                             0x0
#define WIFI_CLOCK_OUT_SELECT_LSB                                              0
#define WIFI_CLOCK_OUT_SELECT_MSB                                              3
#define WIFI_CLOCK_OUT_SELECT_MASK                                             0xf
#define WIFI_CLOCK_OUT_SELECT_GET(x)                                           (((x) & WIFI_CLOCK_OUT_SELECT_MASK) >> WIFI_CLOCK_OUT_SELECT_LSB)
#define WIFI_CLOCK_OUT_SELECT_SET(x)                                           (((0 | (x)) << WIFI_CLOCK_OUT_SELECT_LSB) & WIFI_CLOCK_OUT_SELECT_MASK)
#define WIFI_CLOCK_OUT_SELECT_RESET                                            0x0
#define WIFI_CLOCK_OUT_ADDRESS                                                 (0x20 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_CLOCK_OUT_RSTMASK                                                 0x7f
#define WIFI_CLOCK_OUT_RESET                                                   0x0

// 0x24 (WIFI_BIAS_OVERRIDE)
#define WIFI_BIAS_OVERRIDE_ON_LSB                                              0
#define WIFI_BIAS_OVERRIDE_ON_MSB                                              0
#define WIFI_BIAS_OVERRIDE_ON_MASK                                             0x1
#define WIFI_BIAS_OVERRIDE_ON_GET(x)                                           (((x) & WIFI_BIAS_OVERRIDE_ON_MASK) >> WIFI_BIAS_OVERRIDE_ON_LSB)
#define WIFI_BIAS_OVERRIDE_ON_SET(x)                                           (((0 | (x)) << WIFI_BIAS_OVERRIDE_ON_LSB) & WIFI_BIAS_OVERRIDE_ON_MASK)
#define WIFI_BIAS_OVERRIDE_ON_RESET                                            0x0
#define WIFI_BIAS_OVERRIDE_ADDRESS                                             (0x24 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_BIAS_OVERRIDE_RSTMASK                                             0x1
#define WIFI_BIAS_OVERRIDE_RESET                                               0x0

// 0x28 (WIFI_RESET_CAUSE)
#define WIFI_RESET_CAUSE_LAST_LSB                                              0
#define WIFI_RESET_CAUSE_LAST_MSB                                              2
#define WIFI_RESET_CAUSE_LAST_MASK                                             0x7
#define WIFI_RESET_CAUSE_LAST_GET(x)                                           (((x) & WIFI_RESET_CAUSE_LAST_MASK) >> WIFI_RESET_CAUSE_LAST_LSB)
#define WIFI_RESET_CAUSE_LAST_SET(x)                                           (((0 | (x)) << WIFI_RESET_CAUSE_LAST_LSB) & WIFI_RESET_CAUSE_LAST_MASK)
#define WIFI_RESET_CAUSE_LAST_RESET                                            0x0
#define WIFI_RESET_CAUSE_ADDRESS                                               (0x28 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_RESET_CAUSE_RSTMASK                                               0x7
#define WIFI_RESET_CAUSE_RESET                                                 0x0

// 0x2c (WIFI_SYSTEM_SLEEP)
#define WIFI_SYSTEM_SLEEP_MAC_IF_LSB                                           2
#define WIFI_SYSTEM_SLEEP_MAC_IF_MSB                                           2
#define WIFI_SYSTEM_SLEEP_MAC_IF_MASK                                          0x4
#define WIFI_SYSTEM_SLEEP_MAC_IF_GET(x)                                        (((x) & WIFI_SYSTEM_SLEEP_MAC_IF_MASK) >> WIFI_SYSTEM_SLEEP_MAC_IF_LSB)
#define WIFI_SYSTEM_SLEEP_MAC_IF_SET(x)                                        (((0 | (x)) << WIFI_SYSTEM_SLEEP_MAC_IF_LSB) & WIFI_SYSTEM_SLEEP_MAC_IF_MASK)
#define WIFI_SYSTEM_SLEEP_MAC_IF_RESET                                         0x1
#define WIFI_SYSTEM_SLEEP_LIGHT_LSB                                            1
#define WIFI_SYSTEM_SLEEP_LIGHT_MSB                                            1
#define WIFI_SYSTEM_SLEEP_LIGHT_MASK                                           0x2
#define WIFI_SYSTEM_SLEEP_LIGHT_GET(x)                                         (((x) & WIFI_SYSTEM_SLEEP_LIGHT_MASK) >> WIFI_SYSTEM_SLEEP_LIGHT_LSB)
#define WIFI_SYSTEM_SLEEP_LIGHT_SET(x)                                         (((0 | (x)) << WIFI_SYSTEM_SLEEP_LIGHT_LSB) & WIFI_SYSTEM_SLEEP_LIGHT_MASK)
#define WIFI_SYSTEM_SLEEP_LIGHT_RESET                                          0x0
#define WIFI_SYSTEM_SLEEP_DISABLE_LSB                                          0
#define WIFI_SYSTEM_SLEEP_DISABLE_MSB                                          0
#define WIFI_SYSTEM_SLEEP_DISABLE_MASK                                         0x1
#define WIFI_SYSTEM_SLEEP_DISABLE_GET(x)                                       (((x) & WIFI_SYSTEM_SLEEP_DISABLE_MASK) >> WIFI_SYSTEM_SLEEP_DISABLE_LSB)
#define WIFI_SYSTEM_SLEEP_DISABLE_SET(x)                                       (((0 | (x)) << WIFI_SYSTEM_SLEEP_DISABLE_LSB) & WIFI_SYSTEM_SLEEP_DISABLE_MASK)
#define WIFI_SYSTEM_SLEEP_DISABLE_RESET                                        0x1
#define WIFI_SYSTEM_SLEEP_ADDRESS                                              (0x2c + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_SYSTEM_SLEEP_RSTMASK                                              0x7
#define WIFI_SYSTEM_SLEEP_RESET                                                0x5

// 0x30 (WIFI_MAC_SLEEP_CONTROL)
#define WIFI_MAC_SLEEP_CONTROL_FORCE_WAKE_LSB                                  0
#define WIFI_MAC_SLEEP_CONTROL_FORCE_WAKE_MSB                                  0
#define WIFI_MAC_SLEEP_CONTROL_FORCE_WAKE_MASK                                 0x1
#define WIFI_MAC_SLEEP_CONTROL_FORCE_WAKE_GET(x)                               (((x) & WIFI_MAC_SLEEP_CONTROL_FORCE_WAKE_MASK) >> WIFI_MAC_SLEEP_CONTROL_FORCE_WAKE_LSB)
#define WIFI_MAC_SLEEP_CONTROL_FORCE_WAKE_SET(x)                               (((0 | (x)) << WIFI_MAC_SLEEP_CONTROL_FORCE_WAKE_LSB) & WIFI_MAC_SLEEP_CONTROL_FORCE_WAKE_MASK)
#define WIFI_MAC_SLEEP_CONTROL_FORCE_WAKE_RESET                                0x0
#define WIFI_MAC_SLEEP_CONTROL_ADDRESS                                         (0x30 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_MAC_SLEEP_CONTROL_RSTMASK                                         0x1
#define WIFI_MAC_SLEEP_CONTROL_RESET                                           0x0

// 0x34 (WIFI_KEEP_AWAKE)
#define WIFI_KEEP_AWAKE_MAC_CLK_REQ_COUNT_LSB                                  8
#define WIFI_KEEP_AWAKE_MAC_CLK_REQ_COUNT_MSB                                  15
#define WIFI_KEEP_AWAKE_MAC_CLK_REQ_COUNT_MASK                                 0xff00
#define WIFI_KEEP_AWAKE_MAC_CLK_REQ_COUNT_GET(x)                               (((x) & WIFI_KEEP_AWAKE_MAC_CLK_REQ_COUNT_MASK) >> WIFI_KEEP_AWAKE_MAC_CLK_REQ_COUNT_LSB)
#define WIFI_KEEP_AWAKE_MAC_CLK_REQ_COUNT_SET(x)                               (((0 | (x)) << WIFI_KEEP_AWAKE_MAC_CLK_REQ_COUNT_LSB) & WIFI_KEEP_AWAKE_MAC_CLK_REQ_COUNT_MASK)
#define WIFI_KEEP_AWAKE_MAC_CLK_REQ_COUNT_RESET                                0x3
#define WIFI_KEEP_AWAKE_COUNT_LSB                                              0
#define WIFI_KEEP_AWAKE_COUNT_MSB                                              7
#define WIFI_KEEP_AWAKE_COUNT_MASK                                             0xff
#define WIFI_KEEP_AWAKE_COUNT_GET(x)                                           (((x) & WIFI_KEEP_AWAKE_COUNT_MASK) >> WIFI_KEEP_AWAKE_COUNT_LSB)
#define WIFI_KEEP_AWAKE_COUNT_SET(x)                                           (((0 | (x)) << WIFI_KEEP_AWAKE_COUNT_LSB) & WIFI_KEEP_AWAKE_COUNT_MASK)
#define WIFI_KEEP_AWAKE_COUNT_RESET                                            0x3
#define WIFI_KEEP_AWAKE_ADDRESS                                                (0x34 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_KEEP_AWAKE_RSTMASK                                                0xffff
#define WIFI_KEEP_AWAKE_RESET                                                  0x303

// 0x38 (WIFI_DERIVED_RTC_CLK)
#define WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_LSB                            20
#define WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_MSB                            20
#define WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_MASK                           0x100000
#define WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_GET(x)                         (((x) & WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_MASK) >> WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_LSB)
#define WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_SET(x)                         (((0 | (x)) << WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_LSB) & WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_MASK)
#define WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_EN_RESET                          0x1
#define WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_LSB                               18
#define WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_MSB                               18
#define WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_MASK                              0x40000
#define WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_GET(x)                            (((x) & WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_MASK) >> WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_LSB)
#define WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_SET(x)                            (((0 | (x)) << WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_LSB) & WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_MASK)
#define WIFI_DERIVED_RTC_CLK_EXTERNAL_DETECT_RESET                             0x0
#define WIFI_DERIVED_RTC_CLK_PERIOD_LSB                                        1
#define WIFI_DERIVED_RTC_CLK_PERIOD_MSB                                        15
#define WIFI_DERIVED_RTC_CLK_PERIOD_MASK                                       0xfffe
#define WIFI_DERIVED_RTC_CLK_PERIOD_GET(x)                                     (((x) & WIFI_DERIVED_RTC_CLK_PERIOD_MASK) >> WIFI_DERIVED_RTC_CLK_PERIOD_LSB)
#define WIFI_DERIVED_RTC_CLK_PERIOD_SET(x)                                     (((0 | (x)) << WIFI_DERIVED_RTC_CLK_PERIOD_LSB) & WIFI_DERIVED_RTC_CLK_PERIOD_MASK)
#define WIFI_DERIVED_RTC_CLK_PERIOD_RESET                                      0x262
#define WIFI_DERIVED_RTC_CLK_ADDRESS                                           (0x38 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_DERIVED_RTC_CLK_RSTMASK                                           0x14fffe
#define WIFI_DERIVED_RTC_CLK_RESET                                             0x1004c4

// 0x3c (WIFI_RTC_SYNC_DERIVED)
#define WIFI_RTC_SYNC_DERIVED_FORCE_LSB                                        1
#define WIFI_RTC_SYNC_DERIVED_FORCE_MSB                                        1
#define WIFI_RTC_SYNC_DERIVED_FORCE_MASK                                       0x2
#define WIFI_RTC_SYNC_DERIVED_FORCE_GET(x)                                     (((x) & WIFI_RTC_SYNC_DERIVED_FORCE_MASK) >> WIFI_RTC_SYNC_DERIVED_FORCE_LSB)
#define WIFI_RTC_SYNC_DERIVED_FORCE_SET(x)                                     (((0 | (x)) << WIFI_RTC_SYNC_DERIVED_FORCE_LSB) & WIFI_RTC_SYNC_DERIVED_FORCE_MASK)
#define WIFI_RTC_SYNC_DERIVED_FORCE_RESET                                      0x0
#define WIFI_RTC_SYNC_DERIVED_BYPASS_LSB                                       0
#define WIFI_RTC_SYNC_DERIVED_BYPASS_MSB                                       0
#define WIFI_RTC_SYNC_DERIVED_BYPASS_MASK                                      0x1
#define WIFI_RTC_SYNC_DERIVED_BYPASS_GET(x)                                    (((x) & WIFI_RTC_SYNC_DERIVED_BYPASS_MASK) >> WIFI_RTC_SYNC_DERIVED_BYPASS_LSB)
#define WIFI_RTC_SYNC_DERIVED_BYPASS_SET(x)                                    (((0 | (x)) << WIFI_RTC_SYNC_DERIVED_BYPASS_LSB) & WIFI_RTC_SYNC_DERIVED_BYPASS_MASK)
#define WIFI_RTC_SYNC_DERIVED_BYPASS_RESET                                     0x0
#define WIFI_RTC_SYNC_DERIVED_ADDRESS                                          (0x3c + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_RTC_SYNC_DERIVED_RSTMASK                                          0x3
#define WIFI_RTC_SYNC_DERIVED_RESET                                            0x0

// 0x40 (LF_TIMER0)
#define LF_TIMER0_TARGET_LSB                                                   0
#define LF_TIMER0_TARGET_MSB                                                   31
#define LF_TIMER0_TARGET_MASK                                                  0xffffffff
#define LF_TIMER0_TARGET_GET(x)                                                (((x) & LF_TIMER0_TARGET_MASK) >> LF_TIMER0_TARGET_LSB)
#define LF_TIMER0_TARGET_SET(x)                                                (((0 | (x)) << LF_TIMER0_TARGET_LSB) & LF_TIMER0_TARGET_MASK)
#define LF_TIMER0_TARGET_RESET                                                 0x0
#define LF_TIMER0_ADDRESS                                                      (0x40 + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER0_RSTMASK                                                      0xffffffff
#define LF_TIMER0_RESET                                                        0x0

// 0x44 (LF_TIMER_COUNT0)
#define LF_TIMER_COUNT0_VALUE_LSB                                              0
#define LF_TIMER_COUNT0_VALUE_MSB                                              31
#define LF_TIMER_COUNT0_VALUE_MASK                                             0xffffffff
#define LF_TIMER_COUNT0_VALUE_GET(x)                                           (((x) & LF_TIMER_COUNT0_VALUE_MASK) >> LF_TIMER_COUNT0_VALUE_LSB)
#define LF_TIMER_COUNT0_VALUE_SET(x)                                           (((0 | (x)) << LF_TIMER_COUNT0_VALUE_LSB) & LF_TIMER_COUNT0_VALUE_MASK)
#define LF_TIMER_COUNT0_VALUE_RESET                                            0x0
#define LF_TIMER_COUNT0_ADDRESS                                                (0x44 + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER_COUNT0_RSTMASK                                                0xffffffff
#define LF_TIMER_COUNT0_RESET                                                  0x0

// 0x48 (LF_TIMER_CONTROL0)
#define LF_TIMER_CONTROL0_ENABLE_LSB                                           2
#define LF_TIMER_CONTROL0_ENABLE_MSB                                           2
#define LF_TIMER_CONTROL0_ENABLE_MASK                                          0x4
#define LF_TIMER_CONTROL0_ENABLE_GET(x)                                        (((x) & LF_TIMER_CONTROL0_ENABLE_MASK) >> LF_TIMER_CONTROL0_ENABLE_LSB)
#define LF_TIMER_CONTROL0_ENABLE_SET(x)                                        (((0 | (x)) << LF_TIMER_CONTROL0_ENABLE_LSB) & LF_TIMER_CONTROL0_ENABLE_MASK)
#define LF_TIMER_CONTROL0_ENABLE_RESET                                         0x0
#define LF_TIMER_CONTROL0_AUTO_RESTART_LSB                                     1
#define LF_TIMER_CONTROL0_AUTO_RESTART_MSB                                     1
#define LF_TIMER_CONTROL0_AUTO_RESTART_MASK                                    0x2
#define LF_TIMER_CONTROL0_AUTO_RESTART_GET(x)                                  (((x) & LF_TIMER_CONTROL0_AUTO_RESTART_MASK) >> LF_TIMER_CONTROL0_AUTO_RESTART_LSB)
#define LF_TIMER_CONTROL0_AUTO_RESTART_SET(x)                                  (((0 | (x)) << LF_TIMER_CONTROL0_AUTO_RESTART_LSB) & LF_TIMER_CONTROL0_AUTO_RESTART_MASK)
#define LF_TIMER_CONTROL0_AUTO_RESTART_RESET                                   0x0
#define LF_TIMER_CONTROL0_RESET_LSB                                            0
#define LF_TIMER_CONTROL0_RESET_MSB                                            0
#define LF_TIMER_CONTROL0_RESET_MASK                                           0x1
#define LF_TIMER_CONTROL0_RESET_GET(x)                                         (((x) & LF_TIMER_CONTROL0_RESET_MASK) >> LF_TIMER_CONTROL0_RESET_LSB)
#define LF_TIMER_CONTROL0_RESET_SET(x)                                         (((0 | (x)) << LF_TIMER_CONTROL0_RESET_LSB) & LF_TIMER_CONTROL0_RESET_MASK)
#define LF_TIMER_CONTROL0_RESET_RESET                                          0x0
#define LF_TIMER_CONTROL0_ADDRESS                                              (0x48 + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER_CONTROL0_RSTMASK                                              0x7
#define LF_TIMER_CONTROL0_RESET                                                0x0

// 0x4c (LF_TIMER_STATUS0)
#define LF_TIMER_STATUS0_INTERRUPT_LSB                                         0
#define LF_TIMER_STATUS0_INTERRUPT_MSB                                         0
#define LF_TIMER_STATUS0_INTERRUPT_MASK                                        0x1
#define LF_TIMER_STATUS0_INTERRUPT_GET(x)                                      (((x) & LF_TIMER_STATUS0_INTERRUPT_MASK) >> LF_TIMER_STATUS0_INTERRUPT_LSB)
#define LF_TIMER_STATUS0_INTERRUPT_SET(x)                                      (((0 | (x)) << LF_TIMER_STATUS0_INTERRUPT_LSB) & LF_TIMER_STATUS0_INTERRUPT_MASK)
#define LF_TIMER_STATUS0_INTERRUPT_RESET                                       0x0
#define LF_TIMER_STATUS0_ADDRESS                                               (0x4c + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER_STATUS0_RSTMASK                                               0x1
#define LF_TIMER_STATUS0_RESET                                                 0x0

// 0x50 (LF_TIMER1)
#define LF_TIMER1_TARGET_LSB                                                   0
#define LF_TIMER1_TARGET_MSB                                                   31
#define LF_TIMER1_TARGET_MASK                                                  0xffffffff
#define LF_TIMER1_TARGET_GET(x)                                                (((x) & LF_TIMER1_TARGET_MASK) >> LF_TIMER1_TARGET_LSB)
#define LF_TIMER1_TARGET_SET(x)                                                (((0 | (x)) << LF_TIMER1_TARGET_LSB) & LF_TIMER1_TARGET_MASK)
#define LF_TIMER1_TARGET_RESET                                                 0x0
#define LF_TIMER1_ADDRESS                                                      (0x50 + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER1_RSTMASK                                                      0xffffffff
#define LF_TIMER1_RESET                                                        0x0

// 0x54 (LF_TIMER_COUNT1)
#define LF_TIMER_COUNT1_VALUE_LSB                                              0
#define LF_TIMER_COUNT1_VALUE_MSB                                              31
#define LF_TIMER_COUNT1_VALUE_MASK                                             0xffffffff
#define LF_TIMER_COUNT1_VALUE_GET(x)                                           (((x) & LF_TIMER_COUNT1_VALUE_MASK) >> LF_TIMER_COUNT1_VALUE_LSB)
#define LF_TIMER_COUNT1_VALUE_SET(x)                                           (((0 | (x)) << LF_TIMER_COUNT1_VALUE_LSB) & LF_TIMER_COUNT1_VALUE_MASK)
#define LF_TIMER_COUNT1_VALUE_RESET                                            0x0
#define LF_TIMER_COUNT1_ADDRESS                                                (0x54 + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER_COUNT1_RSTMASK                                                0xffffffff
#define LF_TIMER_COUNT1_RESET                                                  0x0

// 0x58 (LF_TIMER_CONTROL1)
#define LF_TIMER_CONTROL1_ENABLE_LSB                                           2
#define LF_TIMER_CONTROL1_ENABLE_MSB                                           2
#define LF_TIMER_CONTROL1_ENABLE_MASK                                          0x4
#define LF_TIMER_CONTROL1_ENABLE_GET(x)                                        (((x) & LF_TIMER_CONTROL1_ENABLE_MASK) >> LF_TIMER_CONTROL1_ENABLE_LSB)
#define LF_TIMER_CONTROL1_ENABLE_SET(x)                                        (((0 | (x)) << LF_TIMER_CONTROL1_ENABLE_LSB) & LF_TIMER_CONTROL1_ENABLE_MASK)
#define LF_TIMER_CONTROL1_ENABLE_RESET                                         0x0
#define LF_TIMER_CONTROL1_AUTO_RESTART_LSB                                     1
#define LF_TIMER_CONTROL1_AUTO_RESTART_MSB                                     1
#define LF_TIMER_CONTROL1_AUTO_RESTART_MASK                                    0x2
#define LF_TIMER_CONTROL1_AUTO_RESTART_GET(x)                                  (((x) & LF_TIMER_CONTROL1_AUTO_RESTART_MASK) >> LF_TIMER_CONTROL1_AUTO_RESTART_LSB)
#define LF_TIMER_CONTROL1_AUTO_RESTART_SET(x)                                  (((0 | (x)) << LF_TIMER_CONTROL1_AUTO_RESTART_LSB) & LF_TIMER_CONTROL1_AUTO_RESTART_MASK)
#define LF_TIMER_CONTROL1_AUTO_RESTART_RESET                                   0x0
#define LF_TIMER_CONTROL1_RESET_LSB                                            0
#define LF_TIMER_CONTROL1_RESET_MSB                                            0
#define LF_TIMER_CONTROL1_RESET_MASK                                           0x1
#define LF_TIMER_CONTROL1_RESET_GET(x)                                         (((x) & LF_TIMER_CONTROL1_RESET_MASK) >> LF_TIMER_CONTROL1_RESET_LSB)
#define LF_TIMER_CONTROL1_RESET_SET(x)                                         (((0 | (x)) << LF_TIMER_CONTROL1_RESET_LSB) & LF_TIMER_CONTROL1_RESET_MASK)
#define LF_TIMER_CONTROL1_RESET_RESET                                          0x0
#define LF_TIMER_CONTROL1_ADDRESS                                              (0x58 + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER_CONTROL1_RSTMASK                                              0x7
#define LF_TIMER_CONTROL1_RESET                                                0x0

// 0x5c (LF_TIMER_STATUS1)
#define LF_TIMER_STATUS1_INTERRUPT_LSB                                         0
#define LF_TIMER_STATUS1_INTERRUPT_MSB                                         0
#define LF_TIMER_STATUS1_INTERRUPT_MASK                                        0x1
#define LF_TIMER_STATUS1_INTERRUPT_GET(x)                                      (((x) & LF_TIMER_STATUS1_INTERRUPT_MASK) >> LF_TIMER_STATUS1_INTERRUPT_LSB)
#define LF_TIMER_STATUS1_INTERRUPT_SET(x)                                      (((0 | (x)) << LF_TIMER_STATUS1_INTERRUPT_LSB) & LF_TIMER_STATUS1_INTERRUPT_MASK)
#define LF_TIMER_STATUS1_INTERRUPT_RESET                                       0x0
#define LF_TIMER_STATUS1_ADDRESS                                               (0x5c + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER_STATUS1_RSTMASK                                               0x1
#define LF_TIMER_STATUS1_RESET                                                 0x0

// 0x60 (LF_TIMER2)
#define LF_TIMER2_TARGET_LSB                                                   0
#define LF_TIMER2_TARGET_MSB                                                   31
#define LF_TIMER2_TARGET_MASK                                                  0xffffffff
#define LF_TIMER2_TARGET_GET(x)                                                (((x) & LF_TIMER2_TARGET_MASK) >> LF_TIMER2_TARGET_LSB)
#define LF_TIMER2_TARGET_SET(x)                                                (((0 | (x)) << LF_TIMER2_TARGET_LSB) & LF_TIMER2_TARGET_MASK)
#define LF_TIMER2_TARGET_RESET                                                 0x0
#define LF_TIMER2_ADDRESS                                                      (0x60 + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER2_RSTMASK                                                      0xffffffff
#define LF_TIMER2_RESET                                                        0x0

// 0x64 (LF_TIMER_COUNT2)
#define LF_TIMER_COUNT2_VALUE_LSB                                              0
#define LF_TIMER_COUNT2_VALUE_MSB                                              31
#define LF_TIMER_COUNT2_VALUE_MASK                                             0xffffffff
#define LF_TIMER_COUNT2_VALUE_GET(x)                                           (((x) & LF_TIMER_COUNT2_VALUE_MASK) >> LF_TIMER_COUNT2_VALUE_LSB)
#define LF_TIMER_COUNT2_VALUE_SET(x)                                           (((0 | (x)) << LF_TIMER_COUNT2_VALUE_LSB) & LF_TIMER_COUNT2_VALUE_MASK)
#define LF_TIMER_COUNT2_VALUE_RESET                                            0x0
#define LF_TIMER_COUNT2_ADDRESS                                                (0x64 + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER_COUNT2_RSTMASK                                                0xffffffff
#define LF_TIMER_COUNT2_RESET                                                  0x0

// 0x68 (LF_TIMER_CONTROL2)
#define LF_TIMER_CONTROL2_ENABLE_LSB                                           2
#define LF_TIMER_CONTROL2_ENABLE_MSB                                           2
#define LF_TIMER_CONTROL2_ENABLE_MASK                                          0x4
#define LF_TIMER_CONTROL2_ENABLE_GET(x)                                        (((x) & LF_TIMER_CONTROL2_ENABLE_MASK) >> LF_TIMER_CONTROL2_ENABLE_LSB)
#define LF_TIMER_CONTROL2_ENABLE_SET(x)                                        (((0 | (x)) << LF_TIMER_CONTROL2_ENABLE_LSB) & LF_TIMER_CONTROL2_ENABLE_MASK)
#define LF_TIMER_CONTROL2_ENABLE_RESET                                         0x0
#define LF_TIMER_CONTROL2_AUTO_RESTART_LSB                                     1
#define LF_TIMER_CONTROL2_AUTO_RESTART_MSB                                     1
#define LF_TIMER_CONTROL2_AUTO_RESTART_MASK                                    0x2
#define LF_TIMER_CONTROL2_AUTO_RESTART_GET(x)                                  (((x) & LF_TIMER_CONTROL2_AUTO_RESTART_MASK) >> LF_TIMER_CONTROL2_AUTO_RESTART_LSB)
#define LF_TIMER_CONTROL2_AUTO_RESTART_SET(x)                                  (((0 | (x)) << LF_TIMER_CONTROL2_AUTO_RESTART_LSB) & LF_TIMER_CONTROL2_AUTO_RESTART_MASK)
#define LF_TIMER_CONTROL2_AUTO_RESTART_RESET                                   0x0
#define LF_TIMER_CONTROL2_RESET_LSB                                            0
#define LF_TIMER_CONTROL2_RESET_MSB                                            0
#define LF_TIMER_CONTROL2_RESET_MASK                                           0x1
#define LF_TIMER_CONTROL2_RESET_GET(x)                                         (((x) & LF_TIMER_CONTROL2_RESET_MASK) >> LF_TIMER_CONTROL2_RESET_LSB)
#define LF_TIMER_CONTROL2_RESET_SET(x)                                         (((0 | (x)) << LF_TIMER_CONTROL2_RESET_LSB) & LF_TIMER_CONTROL2_RESET_MASK)
#define LF_TIMER_CONTROL2_RESET_RESET                                          0x0
#define LF_TIMER_CONTROL2_ADDRESS                                              (0x68 + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER_CONTROL2_RSTMASK                                              0x7
#define LF_TIMER_CONTROL2_RESET                                                0x0

// 0x6c (LF_TIMER_STATUS2)
#define LF_TIMER_STATUS2_INTERRUPT_LSB                                         0
#define LF_TIMER_STATUS2_INTERRUPT_MSB                                         0
#define LF_TIMER_STATUS2_INTERRUPT_MASK                                        0x1
#define LF_TIMER_STATUS2_INTERRUPT_GET(x)                                      (((x) & LF_TIMER_STATUS2_INTERRUPT_MASK) >> LF_TIMER_STATUS2_INTERRUPT_LSB)
#define LF_TIMER_STATUS2_INTERRUPT_SET(x)                                      (((0 | (x)) << LF_TIMER_STATUS2_INTERRUPT_LSB) & LF_TIMER_STATUS2_INTERRUPT_MASK)
#define LF_TIMER_STATUS2_INTERRUPT_RESET                                       0x0
#define LF_TIMER_STATUS2_ADDRESS                                               (0x6c + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER_STATUS2_RSTMASK                                               0x1
#define LF_TIMER_STATUS2_RESET                                                 0x0

// 0x70 (LF_TIMER3)
#define LF_TIMER3_TARGET_LSB                                                   0
#define LF_TIMER3_TARGET_MSB                                                   31
#define LF_TIMER3_TARGET_MASK                                                  0xffffffff
#define LF_TIMER3_TARGET_GET(x)                                                (((x) & LF_TIMER3_TARGET_MASK) >> LF_TIMER3_TARGET_LSB)
#define LF_TIMER3_TARGET_SET(x)                                                (((0 | (x)) << LF_TIMER3_TARGET_LSB) & LF_TIMER3_TARGET_MASK)
#define LF_TIMER3_TARGET_RESET                                                 0x0
#define LF_TIMER3_ADDRESS                                                      (0x70 + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER3_RSTMASK                                                      0xffffffff
#define LF_TIMER3_RESET                                                        0x0

// 0x74 (LF_TIMER_COUNT3)
#define LF_TIMER_COUNT3_VALUE_LSB                                              0
#define LF_TIMER_COUNT3_VALUE_MSB                                              31
#define LF_TIMER_COUNT3_VALUE_MASK                                             0xffffffff
#define LF_TIMER_COUNT3_VALUE_GET(x)                                           (((x) & LF_TIMER_COUNT3_VALUE_MASK) >> LF_TIMER_COUNT3_VALUE_LSB)
#define LF_TIMER_COUNT3_VALUE_SET(x)                                           (((0 | (x)) << LF_TIMER_COUNT3_VALUE_LSB) & LF_TIMER_COUNT3_VALUE_MASK)
#define LF_TIMER_COUNT3_VALUE_RESET                                            0x0
#define LF_TIMER_COUNT3_ADDRESS                                                (0x74 + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER_COUNT3_RSTMASK                                                0xffffffff
#define LF_TIMER_COUNT3_RESET                                                  0x0

// 0x78 (LF_TIMER_CONTROL3)
#define LF_TIMER_CONTROL3_ENABLE_LSB                                           2
#define LF_TIMER_CONTROL3_ENABLE_MSB                                           2
#define LF_TIMER_CONTROL3_ENABLE_MASK                                          0x4
#define LF_TIMER_CONTROL3_ENABLE_GET(x)                                        (((x) & LF_TIMER_CONTROL3_ENABLE_MASK) >> LF_TIMER_CONTROL3_ENABLE_LSB)
#define LF_TIMER_CONTROL3_ENABLE_SET(x)                                        (((0 | (x)) << LF_TIMER_CONTROL3_ENABLE_LSB) & LF_TIMER_CONTROL3_ENABLE_MASK)
#define LF_TIMER_CONTROL3_ENABLE_RESET                                         0x0
#define LF_TIMER_CONTROL3_AUTO_RESTART_LSB                                     1
#define LF_TIMER_CONTROL3_AUTO_RESTART_MSB                                     1
#define LF_TIMER_CONTROL3_AUTO_RESTART_MASK                                    0x2
#define LF_TIMER_CONTROL3_AUTO_RESTART_GET(x)                                  (((x) & LF_TIMER_CONTROL3_AUTO_RESTART_MASK) >> LF_TIMER_CONTROL3_AUTO_RESTART_LSB)
#define LF_TIMER_CONTROL3_AUTO_RESTART_SET(x)                                  (((0 | (x)) << LF_TIMER_CONTROL3_AUTO_RESTART_LSB) & LF_TIMER_CONTROL3_AUTO_RESTART_MASK)
#define LF_TIMER_CONTROL3_AUTO_RESTART_RESET                                   0x0
#define LF_TIMER_CONTROL3_RESET_LSB                                            0
#define LF_TIMER_CONTROL3_RESET_MSB                                            0
#define LF_TIMER_CONTROL3_RESET_MASK                                           0x1
#define LF_TIMER_CONTROL3_RESET_GET(x)                                         (((x) & LF_TIMER_CONTROL3_RESET_MASK) >> LF_TIMER_CONTROL3_RESET_LSB)
#define LF_TIMER_CONTROL3_RESET_SET(x)                                         (((0 | (x)) << LF_TIMER_CONTROL3_RESET_LSB) & LF_TIMER_CONTROL3_RESET_MASK)
#define LF_TIMER_CONTROL3_RESET_RESET                                          0x0
#define LF_TIMER_CONTROL3_ADDRESS                                              (0x78 + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER_CONTROL3_RSTMASK                                              0x7
#define LF_TIMER_CONTROL3_RESET                                                0x0

// 0x7c (LF_TIMER_STATUS3)
#define LF_TIMER_STATUS3_INTERRUPT_LSB                                         0
#define LF_TIMER_STATUS3_INTERRUPT_MSB                                         0
#define LF_TIMER_STATUS3_INTERRUPT_MASK                                        0x1
#define LF_TIMER_STATUS3_INTERRUPT_GET(x)                                      (((x) & LF_TIMER_STATUS3_INTERRUPT_MASK) >> LF_TIMER_STATUS3_INTERRUPT_LSB)
#define LF_TIMER_STATUS3_INTERRUPT_SET(x)                                      (((0 | (x)) << LF_TIMER_STATUS3_INTERRUPT_LSB) & LF_TIMER_STATUS3_INTERRUPT_MASK)
#define LF_TIMER_STATUS3_INTERRUPT_RESET                                       0x0
#define LF_TIMER_STATUS3_ADDRESS                                               (0x7c + __WIFI_RTC_REG_BASE_ADDRESS)
#define LF_TIMER_STATUS3_RSTMASK                                               0x1
#define LF_TIMER_STATUS3_RESET                                                 0x0

// 0x80 (HF_TIMER)
#define HF_TIMER_TARGET_LSB                                                    12
#define HF_TIMER_TARGET_MSB                                                    31
#define HF_TIMER_TARGET_MASK                                                   0xfffff000
#define HF_TIMER_TARGET_GET(x)                                                 (((x) & HF_TIMER_TARGET_MASK) >> HF_TIMER_TARGET_LSB)
#define HF_TIMER_TARGET_SET(x)                                                 (((0 | (x)) << HF_TIMER_TARGET_LSB) & HF_TIMER_TARGET_MASK)
#define HF_TIMER_TARGET_RESET                                                  0x0
#define HF_TIMER_ADDRESS                                                       (0x80 + __WIFI_RTC_REG_BASE_ADDRESS)
#define HF_TIMER_RSTMASK                                                       0xfffff000
#define HF_TIMER_RESET                                                         0x0

// 0x84 (HF_TIMER_COUNT)
#define HF_TIMER_COUNT_VALUE_LSB                                               12
#define HF_TIMER_COUNT_VALUE_MSB                                               31
#define HF_TIMER_COUNT_VALUE_MASK                                              0xfffff000
#define HF_TIMER_COUNT_VALUE_GET(x)                                            (((x) & HF_TIMER_COUNT_VALUE_MASK) >> HF_TIMER_COUNT_VALUE_LSB)
#define HF_TIMER_COUNT_VALUE_SET(x)                                            (((0 | (x)) << HF_TIMER_COUNT_VALUE_LSB) & HF_TIMER_COUNT_VALUE_MASK)
#define HF_TIMER_COUNT_VALUE_RESET                                             0x0
#define HF_TIMER_COUNT_ADDRESS                                                 (0x84 + __WIFI_RTC_REG_BASE_ADDRESS)
#define HF_TIMER_COUNT_RSTMASK                                                 0xfffff000
#define HF_TIMER_COUNT_RESET                                                   0x0

// 0x88 (HF_LF_COUNT)
#define HF_LF_COUNT_VALUE_LSB                                                  0
#define HF_LF_COUNT_VALUE_MSB                                                  31
#define HF_LF_COUNT_VALUE_MASK                                                 0xffffffff
#define HF_LF_COUNT_VALUE_GET(x)                                               (((x) & HF_LF_COUNT_VALUE_MASK) >> HF_LF_COUNT_VALUE_LSB)
#define HF_LF_COUNT_VALUE_SET(x)                                               (((0 | (x)) << HF_LF_COUNT_VALUE_LSB) & HF_LF_COUNT_VALUE_MASK)
#define HF_LF_COUNT_VALUE_RESET                                                0x0
#define HF_LF_COUNT_ADDRESS                                                    (0x88 + __WIFI_RTC_REG_BASE_ADDRESS)
#define HF_LF_COUNT_RSTMASK                                                    0xffffffff
#define HF_LF_COUNT_RESET                                                      0x0

// 0x8c (HF_TIMER_CONTROL)
#define HF_TIMER_CONTROL_ENABLE_LSB                                            3
#define HF_TIMER_CONTROL_ENABLE_MSB                                            3
#define HF_TIMER_CONTROL_ENABLE_MASK                                           0x8
#define HF_TIMER_CONTROL_ENABLE_GET(x)                                         (((x) & HF_TIMER_CONTROL_ENABLE_MASK) >> HF_TIMER_CONTROL_ENABLE_LSB)
#define HF_TIMER_CONTROL_ENABLE_SET(x)                                         (((0 | (x)) << HF_TIMER_CONTROL_ENABLE_LSB) & HF_TIMER_CONTROL_ENABLE_MASK)
#define HF_TIMER_CONTROL_ENABLE_RESET                                          0x1
#define HF_TIMER_CONTROL_ON_LSB                                                2
#define HF_TIMER_CONTROL_ON_MSB                                                2
#define HF_TIMER_CONTROL_ON_MASK                                               0x4
#define HF_TIMER_CONTROL_ON_GET(x)                                             (((x) & HF_TIMER_CONTROL_ON_MASK) >> HF_TIMER_CONTROL_ON_LSB)
#define HF_TIMER_CONTROL_ON_SET(x)                                             (((0 | (x)) << HF_TIMER_CONTROL_ON_LSB) & HF_TIMER_CONTROL_ON_MASK)
#define HF_TIMER_CONTROL_ON_RESET                                              0x0
#define HF_TIMER_CONTROL_AUTO_RESTART_LSB                                      1
#define HF_TIMER_CONTROL_AUTO_RESTART_MSB                                      1
#define HF_TIMER_CONTROL_AUTO_RESTART_MASK                                     0x2
#define HF_TIMER_CONTROL_AUTO_RESTART_GET(x)                                   (((x) & HF_TIMER_CONTROL_AUTO_RESTART_MASK) >> HF_TIMER_CONTROL_AUTO_RESTART_LSB)
#define HF_TIMER_CONTROL_AUTO_RESTART_SET(x)                                   (((0 | (x)) << HF_TIMER_CONTROL_AUTO_RESTART_LSB) & HF_TIMER_CONTROL_AUTO_RESTART_MASK)
#define HF_TIMER_CONTROL_AUTO_RESTART_RESET                                    0x0
#define HF_TIMER_CONTROL_RESET_LSB                                             0
#define HF_TIMER_CONTROL_RESET_MSB                                             0
#define HF_TIMER_CONTROL_RESET_MASK                                            0x1
#define HF_TIMER_CONTROL_RESET_GET(x)                                          (((x) & HF_TIMER_CONTROL_RESET_MASK) >> HF_TIMER_CONTROL_RESET_LSB)
#define HF_TIMER_CONTROL_RESET_SET(x)                                          (((0 | (x)) << HF_TIMER_CONTROL_RESET_LSB) & HF_TIMER_CONTROL_RESET_MASK)
#define HF_TIMER_CONTROL_RESET_RESET                                           0x0
#define HF_TIMER_CONTROL_ADDRESS                                               (0x8c + __WIFI_RTC_REG_BASE_ADDRESS)
#define HF_TIMER_CONTROL_RSTMASK                                               0xf
#define HF_TIMER_CONTROL_RESET                                                 0x8

// 0x90 (HF_TIMER_STATUS)
#define HF_TIMER_STATUS_INTERRUPT_LSB                                          0
#define HF_TIMER_STATUS_INTERRUPT_MSB                                          0
#define HF_TIMER_STATUS_INTERRUPT_MASK                                         0x1
#define HF_TIMER_STATUS_INTERRUPT_GET(x)                                       (((x) & HF_TIMER_STATUS_INTERRUPT_MASK) >> HF_TIMER_STATUS_INTERRUPT_LSB)
#define HF_TIMER_STATUS_INTERRUPT_SET(x)                                       (((0 | (x)) << HF_TIMER_STATUS_INTERRUPT_LSB) & HF_TIMER_STATUS_INTERRUPT_MASK)
#define HF_TIMER_STATUS_INTERRUPT_RESET                                        0x0
#define HF_TIMER_STATUS_ADDRESS                                                (0x90 + __WIFI_RTC_REG_BASE_ADDRESS)
#define HF_TIMER_STATUS_RSTMASK                                                0x1
#define HF_TIMER_STATUS_RESET                                                  0x0

// 0x94 (WDT_CONTROL)
#define WDT_CONTROL_ACTION_LSB                                                 0
#define WDT_CONTROL_ACTION_MSB                                                 2
#define WDT_CONTROL_ACTION_MASK                                                0x7
#define WDT_CONTROL_ACTION_GET(x)                                              (((x) & WDT_CONTROL_ACTION_MASK) >> WDT_CONTROL_ACTION_LSB)
#define WDT_CONTROL_ACTION_SET(x)                                              (((0 | (x)) << WDT_CONTROL_ACTION_LSB) & WDT_CONTROL_ACTION_MASK)
#define WDT_CONTROL_ACTION_RESET                                               0x2
#define WDT_CONTROL_ADDRESS                                                    (0x94 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WDT_CONTROL_RSTMASK                                                    0x7
#define WDT_CONTROL_RESET                                                      0x2

// 0x98 (WDT_STATUS)
#define WDT_STATUS_INTERRUPT_LSB                                               0
#define WDT_STATUS_INTERRUPT_MSB                                               0
#define WDT_STATUS_INTERRUPT_MASK                                              0x1
#define WDT_STATUS_INTERRUPT_GET(x)                                            (((x) & WDT_STATUS_INTERRUPT_MASK) >> WDT_STATUS_INTERRUPT_LSB)
#define WDT_STATUS_INTERRUPT_SET(x)                                            (((0 | (x)) << WDT_STATUS_INTERRUPT_LSB) & WDT_STATUS_INTERRUPT_MASK)
#define WDT_STATUS_INTERRUPT_RESET                                             0x0
#define WDT_STATUS_ADDRESS                                                     (0x98 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WDT_STATUS_RSTMASK                                                     0x1
#define WDT_STATUS_RESET                                                       0x0

// 0x9c (WDT)
#define WDT_TARGET_LSB                                                         0
#define WDT_TARGET_MSB                                                         21
#define WDT_TARGET_MASK                                                        0x3fffff
#define WDT_TARGET_GET(x)                                                      (((x) & WDT_TARGET_MASK) >> WDT_TARGET_LSB)
#define WDT_TARGET_SET(x)                                                      (((0 | (x)) << WDT_TARGET_LSB) & WDT_TARGET_MASK)
#define WDT_TARGET_RESET                                                       0x3fffff
#define WDT_ADDRESS                                                            (0x9c + __WIFI_RTC_REG_BASE_ADDRESS)
#define WDT_RSTMASK                                                            0x3fffff
#define WDT_RESET                                                              0x3fffff

// 0xa00 (WDT_COUNT)
#define WDT_COUNT_VALUE_LSB                                                    0
#define WDT_COUNT_VALUE_MSB                                                    21
#define WDT_COUNT_VALUE_MASK                                                   0x3fffff
#define WDT_COUNT_VALUE_GET(x)                                                 (((x) & WDT_COUNT_VALUE_MASK) >> WDT_COUNT_VALUE_LSB)
#define WDT_COUNT_VALUE_SET(x)                                                 (((0 | (x)) << WDT_COUNT_VALUE_LSB) & WDT_COUNT_VALUE_MASK)
#define WDT_COUNT_VALUE_RESET                                                  0x0
#define WDT_COUNT_ADDRESS                                                      (0xa00 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WDT_COUNT_RSTMASK                                                      0x3fffff
#define WDT_COUNT_RESET                                                        0x0

// 0xa04 (WDT_RESET)
#define WDT_RESET_VALUE_LSB                                                    0
#define WDT_RESET_VALUE_MSB                                                    0
#define WDT_RESET_VALUE_MASK                                                   0x1
#define WDT_RESET_VALUE_GET(x)                                                 (((x) & WDT_RESET_VALUE_MASK) >> WDT_RESET_VALUE_LSB)
#define WDT_RESET_VALUE_SET(x)                                                 (((0 | (x)) << WDT_RESET_VALUE_LSB) & WDT_RESET_VALUE_MASK)
#define WDT_RESET_VALUE_RESET                                                  0x0
#define WDT_RESET_ADDRESS                                                      (0xa04 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WDT_RESET_RSTMASK                                                      0x1
#define WDT_RESET_RESET                                                        0x0

// 0xa08 (WIFI_SLEEP_OVERRIDE)
#define WIFI_SLEEP_OVERRIDE_VALUE_LSB                                          0
#define WIFI_SLEEP_OVERRIDE_VALUE_MSB                                          31
#define WIFI_SLEEP_OVERRIDE_VALUE_MASK                                         0xffffffff
#define WIFI_SLEEP_OVERRIDE_VALUE_GET(x)                                       (((x) & WIFI_SLEEP_OVERRIDE_VALUE_MASK) >> WIFI_SLEEP_OVERRIDE_VALUE_LSB)
#define WIFI_SLEEP_OVERRIDE_VALUE_SET(x)                                       (((0 | (x)) << WIFI_SLEEP_OVERRIDE_VALUE_LSB) & WIFI_SLEEP_OVERRIDE_VALUE_MASK)
#define WIFI_SLEEP_OVERRIDE_VALUE_RESET                                        0x0
#define WIFI_SLEEP_OVERRIDE_ADDRESS                                            (0xa08 + __WIFI_RTC_REG_BASE_ADDRESS)
#define WIFI_SLEEP_OVERRIDE_RSTMASK                                            0xffffffff
#define WIFI_SLEEP_OVERRIDE_RESET                                              0x0

// 0xa0c (WMAC_SLEEP_OVERRIDE)
#define WMAC_SLEEP_OVERRIDE_VALUE_LSB                                          0
#define WMAC_SLEEP_OVERRIDE_VALUE_MSB                                          31
#define WMAC_SLEEP_OVERRIDE_VALUE_MASK                                         0xffffffff
#define WMAC_SLEEP_OVERRIDE_VALUE_GET(x)                                       (((x) & WMAC_SLEEP_OVERRIDE_VALUE_MASK) >> WMAC_SLEEP_OVERRIDE_VALUE_LSB)
#define WMAC_SLEEP_OVERRIDE_VALUE_SET(x)                                       (((0 | (x)) << WMAC_SLEEP_OVERRIDE_VALUE_LSB) & WMAC_SLEEP_OVERRIDE_VALUE_MASK)
#define WMAC_SLEEP_OVERRIDE_VALUE_RESET                                        0x0
#define WMAC_SLEEP_OVERRIDE_ADDRESS                                            (0xa0c + __WIFI_RTC_REG_BASE_ADDRESS)
#define WMAC_SLEEP_OVERRIDE_RSTMASK                                            0xffffffff
#define WMAC_SLEEP_OVERRIDE_RESET                                              0x0

// 0xa10 (BB_PLL_CONFIG)
#define BB_PLL_CONFIG_OUTDIV_LSB                                               18
#define BB_PLL_CONFIG_OUTDIV_MSB                                               20
#define BB_PLL_CONFIG_OUTDIV_MASK                                              0x1c0000
#define BB_PLL_CONFIG_OUTDIV_GET(x)                                            (((x) & BB_PLL_CONFIG_OUTDIV_MASK) >> BB_PLL_CONFIG_OUTDIV_LSB)
#define BB_PLL_CONFIG_OUTDIV_SET(x)                                            (((0 | (x)) << BB_PLL_CONFIG_OUTDIV_LSB) & BB_PLL_CONFIG_OUTDIV_MASK)
#define BB_PLL_CONFIG_OUTDIV_RESET                                             0x1
#define BB_PLL_CONFIG_FRAC_LSB                                                 0
#define BB_PLL_CONFIG_FRAC_MSB                                                 17
#define BB_PLL_CONFIG_FRAC_MASK                                                0x3ffff
#define BB_PLL_CONFIG_FRAC_GET(x)                                              (((x) & BB_PLL_CONFIG_FRAC_MASK) >> BB_PLL_CONFIG_FRAC_LSB)
#define BB_PLL_CONFIG_FRAC_SET(x)                                              (((0 | (x)) << BB_PLL_CONFIG_FRAC_LSB) & BB_PLL_CONFIG_FRAC_MASK)
#define BB_PLL_CONFIG_FRAC_RESET                                               0x1
#define BB_PLL_CONFIG_ADDRESS                                                  (0xa10 + __WIFI_RTC_REG_BASE_ADDRESS)
#define BB_PLL_CONFIG_RSTMASK                                                  0x1fffff
#define BB_PLL_CONFIG_RESET                                                    0x40001



#endif /* _WIFI_RTC_REG_H_ */
