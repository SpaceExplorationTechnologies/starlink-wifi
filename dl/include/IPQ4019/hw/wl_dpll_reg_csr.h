/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _WL_DPLL_REG_CSR_H_
#define _WL_DPLL_REG_CSR_H_


#ifndef __WL_DPLL_REG_CSR_BASE_ADDRESS
#define __WL_DPLL_REG_CSR_BASE_ADDRESS (0x49b40)
#endif


// 0x0 (BBPLL1)
#define BBPLL1_RNG_LSB                                                         30
#define BBPLL1_RNG_MSB                                                         31
#define BBPLL1_RNG_MASK                                                        0xc0000000
#define BBPLL1_RNG_GET(x)                                                      (((x) & BBPLL1_RNG_MASK) >> BBPLL1_RNG_LSB)
#define BBPLL1_RNG_SET(x)                                                      (((0 | (x)) << BBPLL1_RNG_LSB) & BBPLL1_RNG_MASK)
#define BBPLL1_RNG_RESET                                                       0x0
#define BBPLL1_REFDIV_LSB                                                      27
#define BBPLL1_REFDIV_MSB                                                      29
#define BBPLL1_REFDIV_MASK                                                     0x38000000
#define BBPLL1_REFDIV_GET(x)                                                   (((x) & BBPLL1_REFDIV_MASK) >> BBPLL1_REFDIV_LSB)
#define BBPLL1_REFDIV_SET(x)                                                   (((0 | (x)) << BBPLL1_REFDIV_LSB) & BBPLL1_REFDIV_MASK)
#define BBPLL1_REFDIV_RESET                                                    0x0
#define BBPLL1_NINT_LSB                                                        18
#define BBPLL1_NINT_MSB                                                        26
#define BBPLL1_NINT_MASK                                                       0x7fc0000
#define BBPLL1_NINT_GET(x)                                                     (((x) & BBPLL1_NINT_MASK) >> BBPLL1_NINT_LSB)
#define BBPLL1_NINT_SET(x)                                                     (((0 | (x)) << BBPLL1_NINT_LSB) & BBPLL1_NINT_MASK)
#define BBPLL1_NINT_RESET                                                      0x10
#define BBPLL1_NFRAC_LSB                                                       0
#define BBPLL1_NFRAC_MSB                                                       17
#define BBPLL1_NFRAC_MASK                                                      0x3ffff
#define BBPLL1_NFRAC_GET(x)                                                    (((x) & BBPLL1_NFRAC_MASK) >> BBPLL1_NFRAC_LSB)
#define BBPLL1_NFRAC_SET(x)                                                    (((0 | (x)) << BBPLL1_NFRAC_LSB) & BBPLL1_NFRAC_MASK)
#define BBPLL1_NFRAC_RESET                                                     0x0
#define BBPLL1_ADDRESS                                                         (0x0 + __WL_DPLL_REG_CSR_BASE_ADDRESS)
#define BBPLL1_RSTMASK                                                         0xffffffff
#define BBPLL1_RESET                                                           0x400000

// 0x4 (BBPLL2)
#define BBPLL2_LOCAL_PLL_LSB                                                   31
#define BBPLL2_LOCAL_PLL_MSB                                                   31
#define BBPLL2_LOCAL_PLL_MASK                                                  0x80000000
#define BBPLL2_LOCAL_PLL_GET(x)                                                (((x) & BBPLL2_LOCAL_PLL_MASK) >> BBPLL2_LOCAL_PLL_LSB)
#define BBPLL2_LOCAL_PLL_SET(x)                                                (((0 | (x)) << BBPLL2_LOCAL_PLL_LSB) & BBPLL2_LOCAL_PLL_MASK)
#define BBPLL2_LOCAL_PLL_RESET                                                 0x0
#define BBPLL2_KI_LSB                                                          29
#define BBPLL2_KI_MSB                                                          30
#define BBPLL2_KI_MASK                                                         0x60000000
#define BBPLL2_KI_GET(x)                                                       (((x) & BBPLL2_KI_MASK) >> BBPLL2_KI_LSB)
#define BBPLL2_KI_SET(x)                                                       (((0 | (x)) << BBPLL2_KI_LSB) & BBPLL2_KI_MASK)
#define BBPLL2_KI_RESET                                                        0x1
#define BBPLL2_KD_LSB                                                          25
#define BBPLL2_KD_MSB                                                          28
#define BBPLL2_KD_MASK                                                         0x1e000000
#define BBPLL2_KD_GET(x)                                                       (((x) & BBPLL2_KD_MASK) >> BBPLL2_KD_LSB)
#define BBPLL2_KD_SET(x)                                                       (((0 | (x)) << BBPLL2_KD_LSB) & BBPLL2_KD_MASK)
#define BBPLL2_KD_RESET                                                        0x8
#define BBPLL2_EN_NEGTRIG_LSB                                                  24
#define BBPLL2_EN_NEGTRIG_MSB                                                  24
#define BBPLL2_EN_NEGTRIG_MASK                                                 0x1000000
#define BBPLL2_EN_NEGTRIG_GET(x)                                               (((x) & BBPLL2_EN_NEGTRIG_MASK) >> BBPLL2_EN_NEGTRIG_LSB)
#define BBPLL2_EN_NEGTRIG_SET(x)                                               (((0 | (x)) << BBPLL2_EN_NEGTRIG_LSB) & BBPLL2_EN_NEGTRIG_MASK)
#define BBPLL2_EN_NEGTRIG_RESET                                                0x0
#define BBPLL2_LOCAL_PLL_PWD_LSB                                               23
#define BBPLL2_LOCAL_PLL_PWD_MSB                                               23
#define BBPLL2_LOCAL_PLL_PWD_MASK                                              0x800000
#define BBPLL2_LOCAL_PLL_PWD_GET(x)                                            (((x) & BBPLL2_LOCAL_PLL_PWD_MASK) >> BBPLL2_LOCAL_PLL_PWD_LSB)
#define BBPLL2_LOCAL_PLL_PWD_SET(x)                                            (((0 | (x)) << BBPLL2_LOCAL_PLL_PWD_LSB) & BBPLL2_LOCAL_PLL_PWD_MASK)
#define BBPLL2_LOCAL_PLL_PWD_RESET                                             0x0
#define BBPLL2_PLL_PWD_LSB                                                     22
#define BBPLL2_PLL_PWD_MSB                                                     22
#define BBPLL2_PLL_PWD_MASK                                                    0x400000
#define BBPLL2_PLL_PWD_GET(x)                                                  (((x) & BBPLL2_PLL_PWD_MASK) >> BBPLL2_PLL_PWD_LSB)
#define BBPLL2_PLL_PWD_SET(x)                                                  (((0 | (x)) << BBPLL2_PLL_PWD_LSB) & BBPLL2_PLL_PWD_MASK)
#define BBPLL2_PLL_PWD_RESET                                                   0x1
#define BBPLL2_OUTDIV_LSB                                                      19
#define BBPLL2_OUTDIV_MSB                                                      21
#define BBPLL2_OUTDIV_MASK                                                     0x380000
#define BBPLL2_OUTDIV_GET(x)                                                   (((x) & BBPLL2_OUTDIV_MASK) >> BBPLL2_OUTDIV_LSB)
#define BBPLL2_OUTDIV_SET(x)                                                   (((0 | (x)) << BBPLL2_OUTDIV_LSB) & BBPLL2_OUTDIV_MASK)
#define BBPLL2_OUTDIV_RESET                                                    0x1
#define BBPLL2_PHASE_SHIFT_LSB                                                 12
#define BBPLL2_PHASE_SHIFT_MSB                                                 18
#define BBPLL2_PHASE_SHIFT_MASK                                                0x7f000
#define BBPLL2_PHASE_SHIFT_GET(x)                                              (((x) & BBPLL2_PHASE_SHIFT_MASK) >> BBPLL2_PHASE_SHIFT_LSB)
#define BBPLL2_PHASE_SHIFT_SET(x)                                              (((0 | (x)) << BBPLL2_PHASE_SHIFT_LSB) & BBPLL2_PHASE_SHIFT_MASK)
#define BBPLL2_PHASE_SHIFT_RESET                                               0x0
#define BBPLL2_TESTIN_LSB                                                      2
#define BBPLL2_TESTIN_MSB                                                      11
#define BBPLL2_TESTIN_MASK                                                     0xffc
#define BBPLL2_TESTIN_GET(x)                                                   (((x) & BBPLL2_TESTIN_MASK) >> BBPLL2_TESTIN_LSB)
#define BBPLL2_TESTIN_SET(x)                                                   (((0 | (x)) << BBPLL2_TESTIN_LSB) & BBPLL2_TESTIN_MASK)
#define BBPLL2_TESTIN_RESET                                                    0x0
#define BBPLL2_SEL_COUNT_LSB                                                   1
#define BBPLL2_SEL_COUNT_MSB                                                   1
#define BBPLL2_SEL_COUNT_MASK                                                  0x2
#define BBPLL2_SEL_COUNT_GET(x)                                                (((x) & BBPLL2_SEL_COUNT_MASK) >> BBPLL2_SEL_COUNT_LSB)
#define BBPLL2_SEL_COUNT_SET(x)                                                (((0 | (x)) << BBPLL2_SEL_COUNT_LSB) & BBPLL2_SEL_COUNT_MASK)
#define BBPLL2_SEL_COUNT_RESET                                                 0x0
#define BBPLL2_RESET_TEST_LSB                                                  0
#define BBPLL2_RESET_TEST_MSB                                                  0
#define BBPLL2_RESET_TEST_MASK                                                 0x1
#define BBPLL2_RESET_TEST_GET(x)                                               (((x) & BBPLL2_RESET_TEST_MASK) >> BBPLL2_RESET_TEST_LSB)
#define BBPLL2_RESET_TEST_SET(x)                                               (((0 | (x)) << BBPLL2_RESET_TEST_LSB) & BBPLL2_RESET_TEST_MASK)
#define BBPLL2_RESET_TEST_RESET                                                0x0
#define BBPLL2_ADDRESS                                                         (0x4 + __WL_DPLL_REG_CSR_BASE_ADDRESS)
#define BBPLL2_RSTMASK                                                         0xffffffff
#define BBPLL2_RESET                                                           0x30480000

// 0x8 (BBPLL3)
#define BBPLL3_DO_MEAS_LSB                                                     31
#define BBPLL3_DO_MEAS_MSB                                                     31
#define BBPLL3_DO_MEAS_MASK                                                    0x80000000
#define BBPLL3_DO_MEAS_GET(x)                                                  (((x) & BBPLL3_DO_MEAS_MASK) >> BBPLL3_DO_MEAS_LSB)
#define BBPLL3_DO_MEAS_SET(x)                                                  (((0 | (x)) << BBPLL3_DO_MEAS_LSB) & BBPLL3_DO_MEAS_MASK)
#define BBPLL3_DO_MEAS_RESET                                                   0x0
#define BBPLL3_VC_MEAS0_LSB                                                    13
#define BBPLL3_VC_MEAS0_MSB                                                    30
#define BBPLL3_VC_MEAS0_MASK                                                   0x7fffe000
#define BBPLL3_VC_MEAS0_GET(x)                                                 (((x) & BBPLL3_VC_MEAS0_MASK) >> BBPLL3_VC_MEAS0_LSB)
#define BBPLL3_VC_MEAS0_SET(x)                                                 (((0 | (x)) << BBPLL3_VC_MEAS0_LSB) & BBPLL3_VC_MEAS0_MASK)
#define BBPLL3_VC_MEAS0_RESET                                                  0x0
#define BBPLL3_VC_DIFF0_LSB                                                    3
#define BBPLL3_VC_DIFF0_MSB                                                    12
#define BBPLL3_VC_DIFF0_MASK                                                   0x1ff8
#define BBPLL3_VC_DIFF0_GET(x)                                                 (((x) & BBPLL3_VC_DIFF0_MASK) >> BBPLL3_VC_DIFF0_LSB)
#define BBPLL3_VC_DIFF0_SET(x)                                                 (((0 | (x)) << BBPLL3_VC_DIFF0_LSB) & BBPLL3_VC_DIFF0_MASK)
#define BBPLL3_VC_DIFF0_RESET                                                  0x0
#define BBPLL3_REDUCE_R_LSB                                                    2
#define BBPLL3_REDUCE_R_MSB                                                    2
#define BBPLL3_REDUCE_R_MASK                                                   0x4
#define BBPLL3_REDUCE_R_GET(x)                                                 (((x) & BBPLL3_REDUCE_R_MASK) >> BBPLL3_REDUCE_R_LSB)
#define BBPLL3_REDUCE_R_SET(x)                                                 (((0 | (x)) << BBPLL3_REDUCE_R_LSB) & BBPLL3_REDUCE_R_MASK)
#define BBPLL3_REDUCE_R_RESET                                                  0x0
#define BBPLL3_SEL_1SDM_LSB                                                    1
#define BBPLL3_SEL_1SDM_MSB                                                    1
#define BBPLL3_SEL_1SDM_MASK                                                   0x2
#define BBPLL3_SEL_1SDM_GET(x)                                                 (((x) & BBPLL3_SEL_1SDM_MASK) >> BBPLL3_SEL_1SDM_LSB)
#define BBPLL3_SEL_1SDM_SET(x)                                                 (((0 | (x)) << BBPLL3_SEL_1SDM_LSB) & BBPLL3_SEL_1SDM_MASK)
#define BBPLL3_SEL_1SDM_RESET                                                  0x0
#define BBPLL3_DIV2_SEL_LSB                                                    0
#define BBPLL3_DIV2_SEL_MSB                                                    0
#define BBPLL3_DIV2_SEL_MASK                                                   0x1
#define BBPLL3_DIV2_SEL_GET(x)                                                 (((x) & BBPLL3_DIV2_SEL_MASK) >> BBPLL3_DIV2_SEL_LSB)
#define BBPLL3_DIV2_SEL_SET(x)                                                 (((0 | (x)) << BBPLL3_DIV2_SEL_LSB) & BBPLL3_DIV2_SEL_MASK)
#define BBPLL3_DIV2_SEL_RESET                                                  0x0
#define BBPLL3_ADDRESS                                                         (0x8 + __WL_DPLL_REG_CSR_BASE_ADDRESS)
#define BBPLL3_RSTMASK                                                         0xffffffff
#define BBPLL3_RESET                                                           0x0

// 0xc (BBPLL4)
#define BBPLL4_PIN_VC_LSB                                                      31
#define BBPLL4_PIN_VC_MSB                                                      31
#define BBPLL4_PIN_VC_MASK                                                     0x80000000
#define BBPLL4_PIN_VC_GET(x)                                                   (((x) & BBPLL4_PIN_VC_MASK) >> BBPLL4_PIN_VC_LSB)
#define BBPLL4_PIN_VC_SET(x)                                                   (((0 | (x)) << BBPLL4_PIN_VC_LSB) & BBPLL4_PIN_VC_MASK)
#define BBPLL4_PIN_VC_RESET                                                    0x0
#define BBPLL4_VC_IN_LSB                                                       23
#define BBPLL4_VC_IN_MSB                                                       30
#define BBPLL4_VC_IN_MASK                                                      0x7f800000
#define BBPLL4_VC_IN_GET(x)                                                    (((x) & BBPLL4_VC_IN_MASK) >> BBPLL4_VC_IN_LSB)
#define BBPLL4_VC_IN_SET(x)                                                    (((0 | (x)) << BBPLL4_VC_IN_LSB) & BBPLL4_VC_IN_MASK)
#define BBPLL4_VC_IN_RESET                                                     0x80
#define BBPLL4_REG_BYPASS_LSB                                                  22
#define BBPLL4_REG_BYPASS_MSB                                                  22
#define BBPLL4_REG_BYPASS_MASK                                                 0x400000
#define BBPLL4_REG_BYPASS_GET(x)                                               (((x) & BBPLL4_REG_BYPASS_MASK) >> BBPLL4_REG_BYPASS_LSB)
#define BBPLL4_REG_BYPASS_SET(x)                                               (((0 | (x)) << BBPLL4_REG_BYPASS_LSB) & BBPLL4_REG_BYPASS_MASK)
#define BBPLL4_REG_BYPASS_RESET                                                0x0
#define BBPLL4_REG_LVL_LSB                                                     20
#define BBPLL4_REG_LVL_MSB                                                     21
#define BBPLL4_REG_LVL_MASK                                                    0x300000
#define BBPLL4_REG_LVL_GET(x)                                                  (((x) & BBPLL4_REG_LVL_MASK) >> BBPLL4_REG_LVL_LSB)
#define BBPLL4_REG_LVL_SET(x)                                                  (((0 | (x)) << BBPLL4_REG_LVL_LSB) & BBPLL4_REG_LVL_MASK)
#define BBPLL4_REG_LVL_RESET                                                   0x1
#define BBPLL4_LOCAL_REG_PWD_LSB                                               19
#define BBPLL4_LOCAL_REG_PWD_MSB                                               19
#define BBPLL4_LOCAL_REG_PWD_MASK                                              0x80000
#define BBPLL4_LOCAL_REG_PWD_GET(x)                                            (((x) & BBPLL4_LOCAL_REG_PWD_MASK) >> BBPLL4_LOCAL_REG_PWD_LSB)
#define BBPLL4_LOCAL_REG_PWD_SET(x)                                            (((0 | (x)) << BBPLL4_LOCAL_REG_PWD_LSB) & BBPLL4_LOCAL_REG_PWD_MASK)
#define BBPLL4_LOCAL_REG_PWD_RESET                                             0x0
#define BBPLL4_REG_PWD_LSB                                                     18
#define BBPLL4_REG_PWD_MSB                                                     18
#define BBPLL4_REG_PWD_MASK                                                    0x40000
#define BBPLL4_REG_PWD_GET(x)                                                  (((x) & BBPLL4_REG_PWD_MASK) >> BBPLL4_REG_PWD_LSB)
#define BBPLL4_REG_PWD_SET(x)                                                  (((0 | (x)) << BBPLL4_REG_PWD_LSB) & BBPLL4_REG_PWD_MASK)
#define BBPLL4_REG_PWD_RESET                                                   0x1
#define BBPLL4_LOCK_THRESHOLD_LSB                                              13
#define BBPLL4_LOCK_THRESHOLD_MSB                                              17
#define BBPLL4_LOCK_THRESHOLD_MASK                                             0x3e000
#define BBPLL4_LOCK_THRESHOLD_GET(x)                                           (((x) & BBPLL4_LOCK_THRESHOLD_MASK) >> BBPLL4_LOCK_THRESHOLD_LSB)
#define BBPLL4_LOCK_THRESHOLD_SET(x)                                           (((0 | (x)) << BBPLL4_LOCK_THRESHOLD_LSB) & BBPLL4_LOCK_THRESHOLD_MASK)
#define BBPLL4_LOCK_THRESHOLD_RESET                                            0x6
#define BBPLL4_ATBSEL_LSB                                                      12
#define BBPLL4_ATBSEL_MSB                                                      12
#define BBPLL4_ATBSEL_MASK                                                     0x1000
#define BBPLL4_ATBSEL_GET(x)                                                   (((x) & BBPLL4_ATBSEL_MASK) >> BBPLL4_ATBSEL_LSB)
#define BBPLL4_ATBSEL_SET(x)                                                   (((0 | (x)) << BBPLL4_ATBSEL_LSB) & BBPLL4_ATBSEL_MASK)
#define BBPLL4_ATBSEL_RESET                                                    0x0
#define BBPLL4_ATBHSEL_LSB                                                     10
#define BBPLL4_ATBHSEL_MSB                                                     11
#define BBPLL4_ATBHSEL_MASK                                                    0xc00
#define BBPLL4_ATBHSEL_GET(x)                                                  (((x) & BBPLL4_ATBHSEL_MASK) >> BBPLL4_ATBHSEL_LSB)
#define BBPLL4_ATBHSEL_SET(x)                                                  (((0 | (x)) << BBPLL4_ATBHSEL_LSB) & BBPLL4_ATBHSEL_MASK)
#define BBPLL4_ATBHSEL_RESET                                                   0x0
#define BBPLL4_SDMCLK_SEL_LSB                                                  8
#define BBPLL4_SDMCLK_SEL_MSB                                                  9
#define BBPLL4_SDMCLK_SEL_MASK                                                 0x300
#define BBPLL4_SDMCLK_SEL_GET(x)                                               (((x) & BBPLL4_SDMCLK_SEL_MASK) >> BBPLL4_SDMCLK_SEL_LSB)
#define BBPLL4_SDMCLK_SEL_SET(x)                                               (((0 | (x)) << BBPLL4_SDMCLK_SEL_LSB) & BBPLL4_SDMCLK_SEL_MASK)
#define BBPLL4_SDMCLK_SEL_RESET                                                0x0
#define BBPLL4_SPARE_LSB                                                       0
#define BBPLL4_SPARE_MSB                                                       7
#define BBPLL4_SPARE_MASK                                                      0xff
#define BBPLL4_SPARE_GET(x)                                                    (((x) & BBPLL4_SPARE_MASK) >> BBPLL4_SPARE_LSB)
#define BBPLL4_SPARE_SET(x)                                                    (((0 | (x)) << BBPLL4_SPARE_LSB) & BBPLL4_SPARE_MASK)
#define BBPLL4_SPARE_RESET                                                     0x0
#define BBPLL4_ADDRESS                                                         (0xc + __WL_DPLL_REG_CSR_BASE_ADDRESS)
#define BBPLL4_RSTMASK                                                         0xffffffff
#define BBPLL4_RESET                                                           0x4014c000

// 0x10 (BBPLL5)
#define BBPLL5_LOCK_CNT_SET_LSB                                                24
#define BBPLL5_LOCK_CNT_SET_MSB                                                31
#define BBPLL5_LOCK_CNT_SET_MASK                                               0xff000000
#define BBPLL5_LOCK_CNT_SET_GET(x)                                             (((x) & BBPLL5_LOCK_CNT_SET_MASK) >> BBPLL5_LOCK_CNT_SET_LSB)
#define BBPLL5_LOCK_CNT_SET_SET(x)                                             (((0 | (x)) << BBPLL5_LOCK_CNT_SET_LSB) & BBPLL5_LOCK_CNT_SET_MASK)
#define BBPLL5_LOCK_CNT_SET_RESET                                              0x1f
#define BBPLL5_LOCKED_LSB                                                      23
#define BBPLL5_LOCKED_MSB                                                      23
#define BBPLL5_LOCKED_MASK                                                     0x800000
#define BBPLL5_LOCKED_GET(x)                                                   (((x) & BBPLL5_LOCKED_MASK) >> BBPLL5_LOCKED_LSB)
#define BBPLL5_LOCKED_SET(x)                                                   (((0 | (x)) << BBPLL5_LOCKED_LSB) & BBPLL5_LOCKED_MASK)
#define BBPLL5_LOCKED_RESET                                                    0x0
#define BBPLL5_FREQ_MAX_LSB                                                    13
#define BBPLL5_FREQ_MAX_MSB                                                    22
#define BBPLL5_FREQ_MAX_MASK                                                   0x7fe000
#define BBPLL5_FREQ_MAX_GET(x)                                                 (((x) & BBPLL5_FREQ_MAX_MASK) >> BBPLL5_FREQ_MAX_LSB)
#define BBPLL5_FREQ_MAX_SET(x)                                                 (((0 | (x)) << BBPLL5_FREQ_MAX_LSB) & BBPLL5_FREQ_MAX_MASK)
#define BBPLL5_FREQ_MAX_RESET                                                  0x0
#define BBPLL5_FREQ_MIN_LSB                                                    3
#define BBPLL5_FREQ_MIN_MSB                                                    12
#define BBPLL5_FREQ_MIN_MASK                                                   0x1ff8
#define BBPLL5_FREQ_MIN_GET(x)                                                 (((x) & BBPLL5_FREQ_MIN_MASK) >> BBPLL5_FREQ_MIN_LSB)
#define BBPLL5_FREQ_MIN_SET(x)                                                 (((0 | (x)) << BBPLL5_FREQ_MIN_LSB) & BBPLL5_FREQ_MIN_MASK)
#define BBPLL5_FREQ_MIN_RESET                                                  0x0
#define BBPLL5_SPARE_LSB                                                       0
#define BBPLL5_SPARE_MSB                                                       2
#define BBPLL5_SPARE_MASK                                                      0x7
#define BBPLL5_SPARE_GET(x)                                                    (((x) & BBPLL5_SPARE_MASK) >> BBPLL5_SPARE_LSB)
#define BBPLL5_SPARE_SET(x)                                                    (((0 | (x)) << BBPLL5_SPARE_LSB) & BBPLL5_SPARE_MASK)
#define BBPLL5_SPARE_RESET                                                     0x0
#define BBPLL5_ADDRESS                                                         (0x10 + __WL_DPLL_REG_CSR_BASE_ADDRESS)
#define BBPLL5_RSTMASK                                                         0xffffffff
#define BBPLL5_RESET                                                           0x1f000000



#endif /* _WL_DPLL_REG_CSR_H_ */
