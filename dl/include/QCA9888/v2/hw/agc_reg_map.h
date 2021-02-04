/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _PHY_AGC_REG_MAP_H_
#define _PHY_AGC_REG_MAP_H_


#ifndef __PHY_AGC_REG_MAP_BASE_ADDRESS
#define __PHY_AGC_REG_MAP_BASE_ADDRESS (0x10000)
#endif


// 0x0 (PHY_BB_SETTLING_TIME)
#define PHY_BB_SETTLING_TIME_LBRESET_ADVANCE_LSB                               26
#define PHY_BB_SETTLING_TIME_LBRESET_ADVANCE_MSB                               29
#define PHY_BB_SETTLING_TIME_LBRESET_ADVANCE_MASK                              0x3c000000
#define PHY_BB_SETTLING_TIME_LBRESET_ADVANCE_GET(x)                            (((x) & PHY_BB_SETTLING_TIME_LBRESET_ADVANCE_MASK) >> PHY_BB_SETTLING_TIME_LBRESET_ADVANCE_LSB)
#define PHY_BB_SETTLING_TIME_LBRESET_ADVANCE_SET(x)                            (((0 | (x)) << PHY_BB_SETTLING_TIME_LBRESET_ADVANCE_LSB) & PHY_BB_SETTLING_TIME_LBRESET_ADVANCE_MASK)
#define PHY_BB_SETTLING_TIME_LBRESET_ADVANCE_RESET                             0x0
#define PHY_BB_SETTLING_TIME_SWITCH_SETTLING_LSB                               7
#define PHY_BB_SETTLING_TIME_SWITCH_SETTLING_MSB                               13
#define PHY_BB_SETTLING_TIME_SWITCH_SETTLING_MASK                              0x3f80
#define PHY_BB_SETTLING_TIME_SWITCH_SETTLING_GET(x)                            (((x) & PHY_BB_SETTLING_TIME_SWITCH_SETTLING_MASK) >> PHY_BB_SETTLING_TIME_SWITCH_SETTLING_LSB)
#define PHY_BB_SETTLING_TIME_SWITCH_SETTLING_SET(x)                            (((0 | (x)) << PHY_BB_SETTLING_TIME_SWITCH_SETTLING_LSB) & PHY_BB_SETTLING_TIME_SWITCH_SETTLING_MASK)
#define PHY_BB_SETTLING_TIME_SWITCH_SETTLING_RESET                             0x0
#define PHY_BB_SETTLING_TIME_AGC_SETTLING_LSB                                  0
#define PHY_BB_SETTLING_TIME_AGC_SETTLING_MSB                                  6
#define PHY_BB_SETTLING_TIME_AGC_SETTLING_MASK                                 0x7f
#define PHY_BB_SETTLING_TIME_AGC_SETTLING_GET(x)                               (((x) & PHY_BB_SETTLING_TIME_AGC_SETTLING_MASK) >> PHY_BB_SETTLING_TIME_AGC_SETTLING_LSB)
#define PHY_BB_SETTLING_TIME_AGC_SETTLING_SET(x)                               (((0 | (x)) << PHY_BB_SETTLING_TIME_AGC_SETTLING_LSB) & PHY_BB_SETTLING_TIME_AGC_SETTLING_MASK)
#define PHY_BB_SETTLING_TIME_AGC_SETTLING_RESET                                0x0
#define PHY_BB_SETTLING_TIME_ADDRESS                                           (0x0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SETTLING_TIME_RSTMASK                                           0x3c003fff
#define PHY_BB_SETTLING_TIME_RESET                                             0x0

// 0x4 (PHY_BB_GAIN_FORCE_MAX_GAINS_B0)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_HYST_MARGIN_0_LSB               25
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_HYST_MARGIN_0_MSB               31
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_HYST_MARGIN_0_MASK              0xfe000000
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_HYST_MARGIN_0_GET(x)            (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_HYST_MARGIN_0_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_HYST_MARGIN_0_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_HYST_MARGIN_0_SET(x)            (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_HYST_MARGIN_0_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_HYST_MARGIN_0_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_HYST_MARGIN_0_RESET             0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_HYST_MARGIN_0_LSB               18
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_HYST_MARGIN_0_MSB               24
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_HYST_MARGIN_0_MASK              0x1fc0000
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_HYST_MARGIN_0_GET(x)            (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_HYST_MARGIN_0_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_HYST_MARGIN_0_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_HYST_MARGIN_0_SET(x)            (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_HYST_MARGIN_0_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_HYST_MARGIN_0_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_HYST_MARGIN_0_RESET             0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_SW_F_0_LSB                      17
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_SW_F_0_MSB                      17
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_SW_F_0_MASK                     0x20000
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_SW_F_0_GET(x)                   (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_SW_F_0_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_SW_F_0_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_SW_F_0_SET(x)                   (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_SW_F_0_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_SW_F_0_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN2_SW_F_0_RESET                    0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_SW_F_0_LSB                      16
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_SW_F_0_MSB                      16
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_SW_F_0_MASK                     0x10000
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_SW_F_0_GET(x)                   (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_SW_F_0_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_SW_F_0_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_SW_F_0_SET(x)                   (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_SW_F_0_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_SW_F_0_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_XATTEN1_SW_F_0_RESET                    0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_MB_GAIN_F_0_LSB                         8
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_MB_GAIN_F_0_MSB                         15
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_MB_GAIN_F_0_MASK                        0xff00
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_MB_GAIN_F_0_GET(x)                      (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B0_MB_GAIN_F_0_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B0_MB_GAIN_F_0_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_MB_GAIN_F_0_SET(x)                      (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B0_MB_GAIN_F_0_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B0_MB_GAIN_F_0_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_MB_GAIN_F_0_RESET                       0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_RF_GAIN_F_0_LSB                         0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_RF_GAIN_F_0_MSB                         7
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_RF_GAIN_F_0_MASK                        0xff
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_RF_GAIN_F_0_GET(x)                      (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B0_RF_GAIN_F_0_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B0_RF_GAIN_F_0_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_RF_GAIN_F_0_SET(x)                      (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B0_RF_GAIN_F_0_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B0_RF_GAIN_F_0_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_RF_GAIN_F_0_RESET                       0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_ADDRESS                                 (0x4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_RSTMASK                                 0xffffffff
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B0_RESET                                   0x0

// 0x8 (PHY_BB_GAINS_MIN_OFFSETS)
#define PHY_BB_GAINS_MIN_OFFSETS_ENABLE_ANT_FAST_GC_CTRL_LSB                   24
#define PHY_BB_GAINS_MIN_OFFSETS_ENABLE_ANT_FAST_GC_CTRL_MSB                   24
#define PHY_BB_GAINS_MIN_OFFSETS_ENABLE_ANT_FAST_GC_CTRL_MASK                  0x1000000
#define PHY_BB_GAINS_MIN_OFFSETS_ENABLE_ANT_FAST_GC_CTRL_GET(x)                (((x) & PHY_BB_GAINS_MIN_OFFSETS_ENABLE_ANT_FAST_GC_CTRL_MASK) >> PHY_BB_GAINS_MIN_OFFSETS_ENABLE_ANT_FAST_GC_CTRL_LSB)
#define PHY_BB_GAINS_MIN_OFFSETS_ENABLE_ANT_FAST_GC_CTRL_SET(x)                (((0 | (x)) << PHY_BB_GAINS_MIN_OFFSETS_ENABLE_ANT_FAST_GC_CTRL_LSB) & PHY_BB_GAINS_MIN_OFFSETS_ENABLE_ANT_FAST_GC_CTRL_MASK)
#define PHY_BB_GAINS_MIN_OFFSETS_ENABLE_ANT_FAST_GC_CTRL_RESET                 0x0
#define PHY_BB_GAINS_MIN_OFFSETS_USE_FIXED_GAIN_LSB                            23
#define PHY_BB_GAINS_MIN_OFFSETS_USE_FIXED_GAIN_MSB                            23
#define PHY_BB_GAINS_MIN_OFFSETS_USE_FIXED_GAIN_MASK                           0x800000
#define PHY_BB_GAINS_MIN_OFFSETS_USE_FIXED_GAIN_GET(x)                         (((x) & PHY_BB_GAINS_MIN_OFFSETS_USE_FIXED_GAIN_MASK) >> PHY_BB_GAINS_MIN_OFFSETS_USE_FIXED_GAIN_LSB)
#define PHY_BB_GAINS_MIN_OFFSETS_USE_FIXED_GAIN_SET(x)                         (((0 | (x)) << PHY_BB_GAINS_MIN_OFFSETS_USE_FIXED_GAIN_LSB) & PHY_BB_GAINS_MIN_OFFSETS_USE_FIXED_GAIN_MASK)
#define PHY_BB_GAINS_MIN_OFFSETS_USE_FIXED_GAIN_RESET                          0x0
#define PHY_BB_GAINS_MIN_OFFSETS_ENABLE_SRCH_START_GAIN_LSB                    22
#define PHY_BB_GAINS_MIN_OFFSETS_ENABLE_SRCH_START_GAIN_MSB                    22
#define PHY_BB_GAINS_MIN_OFFSETS_ENABLE_SRCH_START_GAIN_MASK                   0x400000
#define PHY_BB_GAINS_MIN_OFFSETS_ENABLE_SRCH_START_GAIN_GET(x)                 (((x) & PHY_BB_GAINS_MIN_OFFSETS_ENABLE_SRCH_START_GAIN_MASK) >> PHY_BB_GAINS_MIN_OFFSETS_ENABLE_SRCH_START_GAIN_LSB)
#define PHY_BB_GAINS_MIN_OFFSETS_ENABLE_SRCH_START_GAIN_SET(x)                 (((0 | (x)) << PHY_BB_GAINS_MIN_OFFSETS_ENABLE_SRCH_START_GAIN_LSB) & PHY_BB_GAINS_MIN_OFFSETS_ENABLE_SRCH_START_GAIN_MASK)
#define PHY_BB_GAINS_MIN_OFFSETS_ENABLE_SRCH_START_GAIN_RESET                  0x0
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_PHY_ERR_LSB                       21
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_PHY_ERR_MSB                       21
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_PHY_ERR_MASK                      0x200000
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_PHY_ERR_GET(x)                    (((x) & PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_PHY_ERR_MASK) >> PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_PHY_ERR_LSB)
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_PHY_ERR_SET(x)                    (((0 | (x)) << PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_PHY_ERR_LSB) & PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_PHY_ERR_MASK)
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_PHY_ERR_RESET                     0x0
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_VOTING_LSB                        20
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_VOTING_MSB                        20
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_VOTING_MASK                       0x100000
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_VOTING_GET(x)                     (((x) & PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_VOTING_MASK) >> PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_VOTING_LSB)
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_VOTING_SET(x)                     (((0 | (x)) << PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_VOTING_LSB) & PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_VOTING_MASK)
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_VOTING_RESET                      0x0
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_GC_LSB                            19
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_GC_MSB                            19
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_GC_MASK                           0x80000
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_GC_GET(x)                         (((x) & PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_GC_MASK) >> PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_GC_LSB)
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_GC_SET(x)                         (((0 | (x)) << PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_GC_LSB) & PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_GC_MASK)
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_GC_RESET                          0x0
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_ENABLE_LSB                        18
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_ENABLE_MSB                        18
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_ENABLE_MASK                       0x40000
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_ENABLE_GET(x)                     (((x) & PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_ENABLE_MASK) >> PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_ENABLE_LSB)
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_ENABLE_SET(x)                     (((0 | (x)) << PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_ENABLE_LSB) & PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_ENABLE_MASK)
#define PHY_BB_GAINS_MIN_OFFSETS_CF_AGC_HIST_ENABLE_RESET                      0x0
#define PHY_BB_GAINS_MIN_OFFSETS_GAIN_FORCE_LSB                                17
#define PHY_BB_GAINS_MIN_OFFSETS_GAIN_FORCE_MSB                                17
#define PHY_BB_GAINS_MIN_OFFSETS_GAIN_FORCE_MASK                               0x20000
#define PHY_BB_GAINS_MIN_OFFSETS_GAIN_FORCE_GET(x)                             (((x) & PHY_BB_GAINS_MIN_OFFSETS_GAIN_FORCE_MASK) >> PHY_BB_GAINS_MIN_OFFSETS_GAIN_FORCE_LSB)
#define PHY_BB_GAINS_MIN_OFFSETS_GAIN_FORCE_SET(x)                             (((0 | (x)) << PHY_BB_GAINS_MIN_OFFSETS_GAIN_FORCE_LSB) & PHY_BB_GAINS_MIN_OFFSETS_GAIN_FORCE_MASK)
#define PHY_BB_GAINS_MIN_OFFSETS_GAIN_FORCE_RESET                              0x0
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC3_LSB                                  12
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC3_MSB                                  16
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC3_MASK                                 0x1f000
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC3_GET(x)                               (((x) & PHY_BB_GAINS_MIN_OFFSETS_OFFSETC3_MASK) >> PHY_BB_GAINS_MIN_OFFSETS_OFFSETC3_LSB)
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC3_SET(x)                               (((0 | (x)) << PHY_BB_GAINS_MIN_OFFSETS_OFFSETC3_LSB) & PHY_BB_GAINS_MIN_OFFSETS_OFFSETC3_MASK)
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC3_RESET                                0x0
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC2_LSB                                  7
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC2_MSB                                  11
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC2_MASK                                 0xf80
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC2_GET(x)                               (((x) & PHY_BB_GAINS_MIN_OFFSETS_OFFSETC2_MASK) >> PHY_BB_GAINS_MIN_OFFSETS_OFFSETC2_LSB)
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC2_SET(x)                               (((0 | (x)) << PHY_BB_GAINS_MIN_OFFSETS_OFFSETC2_LSB) & PHY_BB_GAINS_MIN_OFFSETS_OFFSETC2_MASK)
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC2_RESET                                0x0
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC1_LSB                                  0
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC1_MSB                                  6
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC1_MASK                                 0x7f
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC1_GET(x)                               (((x) & PHY_BB_GAINS_MIN_OFFSETS_OFFSETC1_MASK) >> PHY_BB_GAINS_MIN_OFFSETS_OFFSETC1_LSB)
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC1_SET(x)                               (((0 | (x)) << PHY_BB_GAINS_MIN_OFFSETS_OFFSETC1_LSB) & PHY_BB_GAINS_MIN_OFFSETS_OFFSETC1_MASK)
#define PHY_BB_GAINS_MIN_OFFSETS_OFFSETC1_RESET                                0x0
#define PHY_BB_GAINS_MIN_OFFSETS_ADDRESS                                       (0x8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_GAINS_MIN_OFFSETS_RSTMASK                                       0x1ffffff
#define PHY_BB_GAINS_MIN_OFFSETS_RESET                                         0x0

// 0xc (PHY_BB_DESIRED_SIGSIZE)
#define PHY_BB_DESIRED_SIGSIZE_ENA_INIT_GAIN_LSB                               31
#define PHY_BB_DESIRED_SIGSIZE_ENA_INIT_GAIN_MSB                               31
#define PHY_BB_DESIRED_SIGSIZE_ENA_INIT_GAIN_MASK                              0x80000000
#define PHY_BB_DESIRED_SIGSIZE_ENA_INIT_GAIN_GET(x)                            (((x) & PHY_BB_DESIRED_SIGSIZE_ENA_INIT_GAIN_MASK) >> PHY_BB_DESIRED_SIGSIZE_ENA_INIT_GAIN_LSB)
#define PHY_BB_DESIRED_SIGSIZE_ENA_INIT_GAIN_SET(x)                            (((0 | (x)) << PHY_BB_DESIRED_SIGSIZE_ENA_INIT_GAIN_LSB) & PHY_BB_DESIRED_SIGSIZE_ENA_INIT_GAIN_MASK)
#define PHY_BB_DESIRED_SIGSIZE_ENA_INIT_GAIN_RESET                             0x0
#define PHY_BB_DESIRED_SIGSIZE_REDUCE_INIT_GC_COUNT_LSB                        30
#define PHY_BB_DESIRED_SIGSIZE_REDUCE_INIT_GC_COUNT_MSB                        30
#define PHY_BB_DESIRED_SIGSIZE_REDUCE_INIT_GC_COUNT_MASK                       0x40000000
#define PHY_BB_DESIRED_SIGSIZE_REDUCE_INIT_GC_COUNT_GET(x)                     (((x) & PHY_BB_DESIRED_SIGSIZE_REDUCE_INIT_GC_COUNT_MASK) >> PHY_BB_DESIRED_SIGSIZE_REDUCE_INIT_GC_COUNT_LSB)
#define PHY_BB_DESIRED_SIGSIZE_REDUCE_INIT_GC_COUNT_SET(x)                     (((0 | (x)) << PHY_BB_DESIRED_SIGSIZE_REDUCE_INIT_GC_COUNT_LSB) & PHY_BB_DESIRED_SIGSIZE_REDUCE_INIT_GC_COUNT_MASK)
#define PHY_BB_DESIRED_SIGSIZE_REDUCE_INIT_GC_COUNT_RESET                      0x0
#define PHY_BB_DESIRED_SIGSIZE_INIT_GC_COUNT_MAX_LSB                           28
#define PHY_BB_DESIRED_SIGSIZE_INIT_GC_COUNT_MAX_MSB                           29
#define PHY_BB_DESIRED_SIGSIZE_INIT_GC_COUNT_MAX_MASK                          0x30000000
#define PHY_BB_DESIRED_SIGSIZE_INIT_GC_COUNT_MAX_GET(x)                        (((x) & PHY_BB_DESIRED_SIGSIZE_INIT_GC_COUNT_MAX_MASK) >> PHY_BB_DESIRED_SIGSIZE_INIT_GC_COUNT_MAX_LSB)
#define PHY_BB_DESIRED_SIGSIZE_INIT_GC_COUNT_MAX_SET(x)                        (((0 | (x)) << PHY_BB_DESIRED_SIGSIZE_INIT_GC_COUNT_MAX_LSB) & PHY_BB_DESIRED_SIGSIZE_INIT_GC_COUNT_MAX_MASK)
#define PHY_BB_DESIRED_SIGSIZE_INIT_GC_COUNT_MAX_RESET                         0x0
#define PHY_BB_DESIRED_SIGSIZE_TOTAL_DESIRED_LSB                               20
#define PHY_BB_DESIRED_SIGSIZE_TOTAL_DESIRED_MSB                               27
#define PHY_BB_DESIRED_SIGSIZE_TOTAL_DESIRED_MASK                              0xff00000
#define PHY_BB_DESIRED_SIGSIZE_TOTAL_DESIRED_GET(x)                            (((x) & PHY_BB_DESIRED_SIGSIZE_TOTAL_DESIRED_MASK) >> PHY_BB_DESIRED_SIGSIZE_TOTAL_DESIRED_LSB)
#define PHY_BB_DESIRED_SIGSIZE_TOTAL_DESIRED_SET(x)                            (((0 | (x)) << PHY_BB_DESIRED_SIGSIZE_TOTAL_DESIRED_LSB) & PHY_BB_DESIRED_SIGSIZE_TOTAL_DESIRED_MASK)
#define PHY_BB_DESIRED_SIGSIZE_TOTAL_DESIRED_RESET                             0x0
#define PHY_BB_DESIRED_SIGSIZE_DISABLE_FINE_RFSAT_LSB                          8
#define PHY_BB_DESIRED_SIGSIZE_DISABLE_FINE_RFSAT_MSB                          8
#define PHY_BB_DESIRED_SIGSIZE_DISABLE_FINE_RFSAT_MASK                         0x100
#define PHY_BB_DESIRED_SIGSIZE_DISABLE_FINE_RFSAT_GET(x)                       (((x) & PHY_BB_DESIRED_SIGSIZE_DISABLE_FINE_RFSAT_MASK) >> PHY_BB_DESIRED_SIGSIZE_DISABLE_FINE_RFSAT_LSB)
#define PHY_BB_DESIRED_SIGSIZE_DISABLE_FINE_RFSAT_SET(x)                       (((0 | (x)) << PHY_BB_DESIRED_SIGSIZE_DISABLE_FINE_RFSAT_LSB) & PHY_BB_DESIRED_SIGSIZE_DISABLE_FINE_RFSAT_MASK)
#define PHY_BB_DESIRED_SIGSIZE_DISABLE_FINE_RFSAT_RESET                        0x1
#define PHY_BB_DESIRED_SIGSIZE_ADC_DESIRED_SIZE_LSB                            0
#define PHY_BB_DESIRED_SIGSIZE_ADC_DESIRED_SIZE_MSB                            7
#define PHY_BB_DESIRED_SIGSIZE_ADC_DESIRED_SIZE_MASK                           0xff
#define PHY_BB_DESIRED_SIGSIZE_ADC_DESIRED_SIZE_GET(x)                         (((x) & PHY_BB_DESIRED_SIGSIZE_ADC_DESIRED_SIZE_MASK) >> PHY_BB_DESIRED_SIGSIZE_ADC_DESIRED_SIZE_LSB)
#define PHY_BB_DESIRED_SIGSIZE_ADC_DESIRED_SIZE_SET(x)                         (((0 | (x)) << PHY_BB_DESIRED_SIGSIZE_ADC_DESIRED_SIZE_LSB) & PHY_BB_DESIRED_SIGSIZE_ADC_DESIRED_SIZE_MASK)
#define PHY_BB_DESIRED_SIGSIZE_ADC_DESIRED_SIZE_RESET                          0x0
#define PHY_BB_DESIRED_SIGSIZE_ADDRESS                                         (0xc + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DESIRED_SIGSIZE_RSTMASK                                         0xfff001ff
#define PHY_BB_DESIRED_SIGSIZE_RESET                                           0x100

// 0x10 (PHY_BB_FIND_SIGNAL)
#define PHY_BB_FIND_SIGNAL_M1COUNT_MAX_LSB                                     26
#define PHY_BB_FIND_SIGNAL_M1COUNT_MAX_MSB                                     31
#define PHY_BB_FIND_SIGNAL_M1COUNT_MAX_MASK                                    0xfc000000
#define PHY_BB_FIND_SIGNAL_M1COUNT_MAX_GET(x)                                  (((x) & PHY_BB_FIND_SIGNAL_M1COUNT_MAX_MASK) >> PHY_BB_FIND_SIGNAL_M1COUNT_MAX_LSB)
#define PHY_BB_FIND_SIGNAL_M1COUNT_MAX_SET(x)                                  (((0 | (x)) << PHY_BB_FIND_SIGNAL_M1COUNT_MAX_LSB) & PHY_BB_FIND_SIGNAL_M1COUNT_MAX_MASK)
#define PHY_BB_FIND_SIGNAL_M1COUNT_MAX_RESET                                   0x1f
#define PHY_BB_FIND_SIGNAL_FIRPWR_LSB                                          18
#define PHY_BB_FIND_SIGNAL_FIRPWR_MSB                                          25
#define PHY_BB_FIND_SIGNAL_FIRPWR_MASK                                         0x3fc0000
#define PHY_BB_FIND_SIGNAL_FIRPWR_GET(x)                                       (((x) & PHY_BB_FIND_SIGNAL_FIRPWR_MASK) >> PHY_BB_FIND_SIGNAL_FIRPWR_LSB)
#define PHY_BB_FIND_SIGNAL_FIRPWR_SET(x)                                       (((0 | (x)) << PHY_BB_FIND_SIGNAL_FIRPWR_LSB) & PHY_BB_FIND_SIGNAL_FIRPWR_MASK)
#define PHY_BB_FIND_SIGNAL_FIRPWR_RESET                                        0xb2
#define PHY_BB_FIND_SIGNAL_FIRSTEP_LSB                                         12
#define PHY_BB_FIND_SIGNAL_FIRSTEP_MSB                                         17
#define PHY_BB_FIND_SIGNAL_FIRSTEP_MASK                                        0x3f000
#define PHY_BB_FIND_SIGNAL_FIRSTEP_GET(x)                                      (((x) & PHY_BB_FIND_SIGNAL_FIRSTEP_MASK) >> PHY_BB_FIND_SIGNAL_FIRSTEP_LSB)
#define PHY_BB_FIND_SIGNAL_FIRSTEP_SET(x)                                      (((0 | (x)) << PHY_BB_FIND_SIGNAL_FIRSTEP_LSB) & PHY_BB_FIND_SIGNAL_FIRSTEP_MASK)
#define PHY_BB_FIND_SIGNAL_FIRSTEP_RESET                                       0x4
#define PHY_BB_FIND_SIGNAL_RELSTEP_LSB                                         0
#define PHY_BB_FIND_SIGNAL_RELSTEP_MSB                                         5
#define PHY_BB_FIND_SIGNAL_RELSTEP_MASK                                        0x3f
#define PHY_BB_FIND_SIGNAL_RELSTEP_GET(x)                                      (((x) & PHY_BB_FIND_SIGNAL_RELSTEP_MASK) >> PHY_BB_FIND_SIGNAL_RELSTEP_LSB)
#define PHY_BB_FIND_SIGNAL_RELSTEP_SET(x)                                      (((0 | (x)) << PHY_BB_FIND_SIGNAL_RELSTEP_LSB) & PHY_BB_FIND_SIGNAL_RELSTEP_MASK)
#define PHY_BB_FIND_SIGNAL_RELSTEP_RESET                                       0x2e
#define PHY_BB_FIND_SIGNAL_ADDRESS                                             (0x10 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_FIND_SIGNAL_RSTMASK                                             0xfffff03f
#define PHY_BB_FIND_SIGNAL_RESET                                               0x7ec8402e

// 0x14 (PHY_BB_AGC)
#define PHY_BB_AGC_RSSI_OUT_SELECT_LSB                                         30
#define PHY_BB_AGC_RSSI_OUT_SELECT_MSB                                         31
#define PHY_BB_AGC_RSSI_OUT_SELECT_MASK                                        0xc0000000
#define PHY_BB_AGC_RSSI_OUT_SELECT_GET(x)                                      (((x) & PHY_BB_AGC_RSSI_OUT_SELECT_MASK) >> PHY_BB_AGC_RSSI_OUT_SELECT_LSB)
#define PHY_BB_AGC_RSSI_OUT_SELECT_SET(x)                                      (((0 | (x)) << PHY_BB_AGC_RSSI_OUT_SELECT_LSB) & PHY_BB_AGC_RSSI_OUT_SELECT_MASK)
#define PHY_BB_AGC_RSSI_OUT_SELECT_RESET                                       0x0
#define PHY_BB_AGC_PWRLOW_GAIN_THR_LSB                                         22
#define PHY_BB_AGC_PWRLOW_GAIN_THR_MSB                                         29
#define PHY_BB_AGC_PWRLOW_GAIN_THR_MASK                                        0x3fc00000
#define PHY_BB_AGC_PWRLOW_GAIN_THR_GET(x)                                      (((x) & PHY_BB_AGC_PWRLOW_GAIN_THR_MASK) >> PHY_BB_AGC_PWRLOW_GAIN_THR_LSB)
#define PHY_BB_AGC_PWRLOW_GAIN_THR_SET(x)                                      (((0 | (x)) << PHY_BB_AGC_PWRLOW_GAIN_THR_LSB) & PHY_BB_AGC_PWRLOW_GAIN_THR_MASK)
#define PHY_BB_AGC_PWRLOW_GAIN_THR_RESET                                       0x28
#define PHY_BB_AGC_COARSE_HIGH_LSB                                             15
#define PHY_BB_AGC_COARSE_HIGH_MSB                                             21
#define PHY_BB_AGC_COARSE_HIGH_MASK                                            0x3f8000
#define PHY_BB_AGC_COARSE_HIGH_GET(x)                                          (((x) & PHY_BB_AGC_COARSE_HIGH_MASK) >> PHY_BB_AGC_COARSE_HIGH_LSB)
#define PHY_BB_AGC_COARSE_HIGH_SET(x)                                          (((0 | (x)) << PHY_BB_AGC_COARSE_HIGH_LSB) & PHY_BB_AGC_COARSE_HIGH_MASK)
#define PHY_BB_AGC_COARSE_HIGH_RESET                                           0x0
#define PHY_BB_AGC_COARSE_LOW_LSB                                              7
#define PHY_BB_AGC_COARSE_LOW_MSB                                              14
#define PHY_BB_AGC_COARSE_LOW_MASK                                             0x7f80
#define PHY_BB_AGC_COARSE_LOW_GET(x)                                           (((x) & PHY_BB_AGC_COARSE_LOW_MASK) >> PHY_BB_AGC_COARSE_LOW_LSB)
#define PHY_BB_AGC_COARSE_LOW_SET(x)                                           (((0 | (x)) << PHY_BB_AGC_COARSE_LOW_LSB) & PHY_BB_AGC_COARSE_LOW_MASK)
#define PHY_BB_AGC_COARSE_LOW_RESET                                            0x0
#define PHY_BB_AGC_COARSEPWR_CONST_LSB                                         0
#define PHY_BB_AGC_COARSEPWR_CONST_MSB                                         6
#define PHY_BB_AGC_COARSEPWR_CONST_MASK                                        0x7f
#define PHY_BB_AGC_COARSEPWR_CONST_GET(x)                                      (((x) & PHY_BB_AGC_COARSEPWR_CONST_MASK) >> PHY_BB_AGC_COARSEPWR_CONST_LSB)
#define PHY_BB_AGC_COARSEPWR_CONST_SET(x)                                      (((0 | (x)) << PHY_BB_AGC_COARSEPWR_CONST_LSB) & PHY_BB_AGC_COARSEPWR_CONST_MASK)
#define PHY_BB_AGC_COARSEPWR_CONST_RESET                                       0x0
#define PHY_BB_AGC_ADDRESS                                                     (0x14 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_AGC_RSTMASK                                                     0xffffffff
#define PHY_BB_AGC_RESET                                                       0xa000000

// 0x18 (PHY_BB_EXT_ATTEN_SWITCH_CTL_B0)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XLNA_GAIN_DB_0_LSB                      24
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XLNA_GAIN_DB_0_MSB                      28
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XLNA_GAIN_DB_0_MASK                     0x1f000000
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XLNA_GAIN_DB_0_GET(x)                   (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XLNA_GAIN_DB_0_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XLNA_GAIN_DB_0_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XLNA_GAIN_DB_0_SET(x)                   (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XLNA_GAIN_DB_0_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XLNA_GAIN_DB_0_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XLNA_GAIN_DB_0_RESET                    0x0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_MARGIN_0_LSB                    18
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_MARGIN_0_MSB                    23
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_MARGIN_0_MASK                   0xfc0000
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_MARGIN_0_GET(x)                 (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_MARGIN_0_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_MARGIN_0_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_MARGIN_0_SET(x)                 (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_MARGIN_0_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_MARGIN_0_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_MARGIN_0_RESET                  0x0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_MARGIN_0_LSB                    12
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_MARGIN_0_MSB                    17
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_MARGIN_0_MASK                   0x3f000
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_MARGIN_0_GET(x)                 (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_MARGIN_0_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_MARGIN_0_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_MARGIN_0_SET(x)                 (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_MARGIN_0_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_MARGIN_0_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_MARGIN_0_RESET                  0x32
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_DB_0_LSB                        6
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_DB_0_MSB                        11
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_DB_0_MASK                       0xfc0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_DB_0_GET(x)                     (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_DB_0_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_DB_0_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_DB_0_SET(x)                     (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_DB_0_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_DB_0_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN2_DB_0_RESET                      0x0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_DB_0_LSB                        0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_DB_0_MSB                        5
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_DB_0_MASK                       0x3f
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_DB_0_GET(x)                     (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_DB_0_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_DB_0_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_DB_0_SET(x)                     (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_DB_0_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_DB_0_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_XATTEN1_DB_0_RESET                      0x0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_ADDRESS                                 (0x18 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_RSTMASK                                 0x1fffffff
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B0_RESET                                   0x32000

// 0x1c (PHY_BB_CCA_B0)
#define PHY_BB_CCA_B0_MINCCAPWR_0_LSB                                          20
#define PHY_BB_CCA_B0_MINCCAPWR_0_MSB                                          28
#define PHY_BB_CCA_B0_MINCCAPWR_0_MASK                                         0x1ff00000
#define PHY_BB_CCA_B0_MINCCAPWR_0_GET(x)                                       (((x) & PHY_BB_CCA_B0_MINCCAPWR_0_MASK) >> PHY_BB_CCA_B0_MINCCAPWR_0_LSB)
#define PHY_BB_CCA_B0_MINCCAPWR_0_SET(x)                                       (((0 | (x)) << PHY_BB_CCA_B0_MINCCAPWR_0_LSB) & PHY_BB_CCA_B0_MINCCAPWR_0_MASK)
#define PHY_BB_CCA_B0_MINCCAPWR_0_RESET                                        0x0
#define PHY_BB_CCA_B0_THR_CCA_LSB                                              12
#define PHY_BB_CCA_B0_THR_CCA_MSB                                              19
#define PHY_BB_CCA_B0_THR_CCA_MASK                                             0xff000
#define PHY_BB_CCA_B0_THR_CCA_GET(x)                                           (((x) & PHY_BB_CCA_B0_THR_CCA_MASK) >> PHY_BB_CCA_B0_THR_CCA_LSB)
#define PHY_BB_CCA_B0_THR_CCA_SET(x)                                           (((0 | (x)) << PHY_BB_CCA_B0_THR_CCA_LSB) & PHY_BB_CCA_B0_THR_CCA_MASK)
#define PHY_BB_CCA_B0_THR_CCA_RESET                                            0x1c
#define PHY_BB_CCA_B0_CF_CCA_COUNT_MAXC_LSB                                    9
#define PHY_BB_CCA_B0_CF_CCA_COUNT_MAXC_MSB                                    11
#define PHY_BB_CCA_B0_CF_CCA_COUNT_MAXC_MASK                                   0xe00
#define PHY_BB_CCA_B0_CF_CCA_COUNT_MAXC_GET(x)                                 (((x) & PHY_BB_CCA_B0_CF_CCA_COUNT_MAXC_MASK) >> PHY_BB_CCA_B0_CF_CCA_COUNT_MAXC_LSB)
#define PHY_BB_CCA_B0_CF_CCA_COUNT_MAXC_SET(x)                                 (((0 | (x)) << PHY_BB_CCA_B0_CF_CCA_COUNT_MAXC_LSB) & PHY_BB_CCA_B0_CF_CCA_COUNT_MAXC_MASK)
#define PHY_BB_CCA_B0_CF_CCA_COUNT_MAXC_RESET                                  0x3
#define PHY_BB_CCA_B0_CF_MAXCCAPWR_0_LSB                                       0
#define PHY_BB_CCA_B0_CF_MAXCCAPWR_0_MSB                                       8
#define PHY_BB_CCA_B0_CF_MAXCCAPWR_0_MASK                                      0x1ff
#define PHY_BB_CCA_B0_CF_MAXCCAPWR_0_GET(x)                                    (((x) & PHY_BB_CCA_B0_CF_MAXCCAPWR_0_MASK) >> PHY_BB_CCA_B0_CF_MAXCCAPWR_0_LSB)
#define PHY_BB_CCA_B0_CF_MAXCCAPWR_0_SET(x)                                    (((0 | (x)) << PHY_BB_CCA_B0_CF_MAXCCAPWR_0_LSB) & PHY_BB_CCA_B0_CF_MAXCCAPWR_0_MASK)
#define PHY_BB_CCA_B0_CF_MAXCCAPWR_0_RESET                                     0x1a6
#define PHY_BB_CCA_B0_ADDRESS                                                  (0x1c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CCA_B0_RSTMASK                                                  0x1fffffff
#define PHY_BB_CCA_B0_RESET                                                    0x1c7a6

// 0x20 (PHY_BB_CCA_CTRL_2_B0)
#define PHY_BB_CCA_CTRL_2_B0_MINCCA_SAME_PER_SEGMENT_LSB                       28
#define PHY_BB_CCA_CTRL_2_B0_MINCCA_SAME_PER_SEGMENT_MSB                       28
#define PHY_BB_CCA_CTRL_2_B0_MINCCA_SAME_PER_SEGMENT_MASK                      0x10000000
#define PHY_BB_CCA_CTRL_2_B0_MINCCA_SAME_PER_SEGMENT_GET(x)                    (((x) & PHY_BB_CCA_CTRL_2_B0_MINCCA_SAME_PER_SEGMENT_MASK) >> PHY_BB_CCA_CTRL_2_B0_MINCCA_SAME_PER_SEGMENT_LSB)
#define PHY_BB_CCA_CTRL_2_B0_MINCCA_SAME_PER_SEGMENT_SET(x)                    (((0 | (x)) << PHY_BB_CCA_CTRL_2_B0_MINCCA_SAME_PER_SEGMENT_LSB) & PHY_BB_CCA_CTRL_2_B0_MINCCA_SAME_PER_SEGMENT_MASK)
#define PHY_BB_CCA_CTRL_2_B0_MINCCA_SAME_PER_SEGMENT_RESET                     0x0
#define PHY_BB_CCA_CTRL_2_B0_MINCCA_FIRPWR_THR_LSB                             20
#define PHY_BB_CCA_CTRL_2_B0_MINCCA_FIRPWR_THR_MSB                             27
#define PHY_BB_CCA_CTRL_2_B0_MINCCA_FIRPWR_THR_MASK                            0xff00000
#define PHY_BB_CCA_CTRL_2_B0_MINCCA_FIRPWR_THR_GET(x)                          (((x) & PHY_BB_CCA_CTRL_2_B0_MINCCA_FIRPWR_THR_MASK) >> PHY_BB_CCA_CTRL_2_B0_MINCCA_FIRPWR_THR_LSB)
#define PHY_BB_CCA_CTRL_2_B0_MINCCA_FIRPWR_THR_SET(x)                          (((0 | (x)) << PHY_BB_CCA_CTRL_2_B0_MINCCA_FIRPWR_THR_LSB) & PHY_BB_CCA_CTRL_2_B0_MINCCA_FIRPWR_THR_MASK)
#define PHY_BB_CCA_CTRL_2_B0_MINCCA_FIRPWR_THR_RESET                           0xa6
#define PHY_BB_CCA_CTRL_2_B0_CCA_AVG_ENA_LSB                                   19
#define PHY_BB_CCA_CTRL_2_B0_CCA_AVG_ENA_MSB                                   19
#define PHY_BB_CCA_CTRL_2_B0_CCA_AVG_ENA_MASK                                  0x80000
#define PHY_BB_CCA_CTRL_2_B0_CCA_AVG_ENA_GET(x)                                (((x) & PHY_BB_CCA_CTRL_2_B0_CCA_AVG_ENA_MASK) >> PHY_BB_CCA_CTRL_2_B0_CCA_AVG_ENA_LSB)
#define PHY_BB_CCA_CTRL_2_B0_CCA_AVG_ENA_SET(x)                                (((0 | (x)) << PHY_BB_CCA_CTRL_2_B0_CCA_AVG_ENA_LSB) & PHY_BB_CCA_CTRL_2_B0_CCA_AVG_ENA_MASK)
#define PHY_BB_CCA_CTRL_2_B0_CCA_AVG_ENA_RESET                                 0x1
#define PHY_BB_CCA_CTRL_2_B0_THR_CCA_MODE_LSB                                  18
#define PHY_BB_CCA_CTRL_2_B0_THR_CCA_MODE_MSB                                  18
#define PHY_BB_CCA_CTRL_2_B0_THR_CCA_MODE_MASK                                 0x40000
#define PHY_BB_CCA_CTRL_2_B0_THR_CCA_MODE_GET(x)                               (((x) & PHY_BB_CCA_CTRL_2_B0_THR_CCA_MODE_MASK) >> PHY_BB_CCA_CTRL_2_B0_THR_CCA_MODE_LSB)
#define PHY_BB_CCA_CTRL_2_B0_THR_CCA_MODE_SET(x)                               (((0 | (x)) << PHY_BB_CCA_CTRL_2_B0_THR_CCA_MODE_LSB) & PHY_BB_CCA_CTRL_2_B0_THR_CCA_MODE_MASK)
#define PHY_BB_CCA_CTRL_2_B0_THR_CCA_MODE_RESET                                0x0
#define PHY_BB_CCA_CTRL_2_B0_NF_GAIN_COMP_0_LSB                                10
#define PHY_BB_CCA_CTRL_2_B0_NF_GAIN_COMP_0_MSB                                17
#define PHY_BB_CCA_CTRL_2_B0_NF_GAIN_COMP_0_MASK                               0x3fc00
#define PHY_BB_CCA_CTRL_2_B0_NF_GAIN_COMP_0_GET(x)                             (((x) & PHY_BB_CCA_CTRL_2_B0_NF_GAIN_COMP_0_MASK) >> PHY_BB_CCA_CTRL_2_B0_NF_GAIN_COMP_0_LSB)
#define PHY_BB_CCA_CTRL_2_B0_NF_GAIN_COMP_0_SET(x)                             (((0 | (x)) << PHY_BB_CCA_CTRL_2_B0_NF_GAIN_COMP_0_LSB) & PHY_BB_CCA_CTRL_2_B0_NF_GAIN_COMP_0_MASK)
#define PHY_BB_CCA_CTRL_2_B0_NF_GAIN_COMP_0_RESET                              0x0
#define PHY_BB_CCA_CTRL_2_B0_ENABLE_MINCCAPWR_THR_LSB                          9
#define PHY_BB_CCA_CTRL_2_B0_ENABLE_MINCCAPWR_THR_MSB                          9
#define PHY_BB_CCA_CTRL_2_B0_ENABLE_MINCCAPWR_THR_MASK                         0x200
#define PHY_BB_CCA_CTRL_2_B0_ENABLE_MINCCAPWR_THR_GET(x)                       (((x) & PHY_BB_CCA_CTRL_2_B0_ENABLE_MINCCAPWR_THR_MASK) >> PHY_BB_CCA_CTRL_2_B0_ENABLE_MINCCAPWR_THR_LSB)
#define PHY_BB_CCA_CTRL_2_B0_ENABLE_MINCCAPWR_THR_SET(x)                       (((0 | (x)) << PHY_BB_CCA_CTRL_2_B0_ENABLE_MINCCAPWR_THR_LSB) & PHY_BB_CCA_CTRL_2_B0_ENABLE_MINCCAPWR_THR_MASK)
#define PHY_BB_CCA_CTRL_2_B0_ENABLE_MINCCAPWR_THR_RESET                        0x0
#define PHY_BB_CCA_CTRL_2_B0_MINCCAPWR_THR_0_LSB                               0
#define PHY_BB_CCA_CTRL_2_B0_MINCCAPWR_THR_0_MSB                               8
#define PHY_BB_CCA_CTRL_2_B0_MINCCAPWR_THR_0_MASK                              0x1ff
#define PHY_BB_CCA_CTRL_2_B0_MINCCAPWR_THR_0_GET(x)                            (((x) & PHY_BB_CCA_CTRL_2_B0_MINCCAPWR_THR_0_MASK) >> PHY_BB_CCA_CTRL_2_B0_MINCCAPWR_THR_0_LSB)
#define PHY_BB_CCA_CTRL_2_B0_MINCCAPWR_THR_0_SET(x)                            (((0 | (x)) << PHY_BB_CCA_CTRL_2_B0_MINCCAPWR_THR_0_LSB) & PHY_BB_CCA_CTRL_2_B0_MINCCAPWR_THR_0_MASK)
#define PHY_BB_CCA_CTRL_2_B0_MINCCAPWR_THR_0_RESET                             0x0
#define PHY_BB_CCA_CTRL_2_B0_ADDRESS                                           (0x20 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CCA_CTRL_2_B0_RSTMASK                                           0x1fffffff
#define PHY_BB_CCA_CTRL_2_B0_RESET                                             0xa680000

// 0x24 (PHY_BB_RESTART)
#define PHY_BB_RESTART_DFS_RESTART_MODE_LSB                                    31
#define PHY_BB_RESTART_DFS_RESTART_MODE_MSB                                    31
#define PHY_BB_RESTART_DFS_RESTART_MODE_MASK                                   0x80000000
#define PHY_BB_RESTART_DFS_RESTART_MODE_GET(x)                                 (((x) & PHY_BB_RESTART_DFS_RESTART_MODE_MASK) >> PHY_BB_RESTART_DFS_RESTART_MODE_LSB)
#define PHY_BB_RESTART_DFS_RESTART_MODE_SET(x)                                 (((0 | (x)) << PHY_BB_RESTART_DFS_RESTART_MODE_LSB) & PHY_BB_RESTART_DFS_RESTART_MODE_MASK)
#define PHY_BB_RESTART_DFS_RESTART_MODE_RESET                                  0x1
#define PHY_BB_RESTART_DFS_RESTART_ENA_LSB                                     30
#define PHY_BB_RESTART_DFS_RESTART_ENA_MSB                                     30
#define PHY_BB_RESTART_DFS_RESTART_ENA_MASK                                    0x40000000
#define PHY_BB_RESTART_DFS_RESTART_ENA_GET(x)                                  (((x) & PHY_BB_RESTART_DFS_RESTART_ENA_MASK) >> PHY_BB_RESTART_DFS_RESTART_ENA_LSB)
#define PHY_BB_RESTART_DFS_RESTART_ENA_SET(x)                                  (((0 | (x)) << PHY_BB_RESTART_DFS_RESTART_ENA_LSB) & PHY_BB_RESTART_DFS_RESTART_ENA_MASK)
#define PHY_BB_RESTART_DFS_RESTART_ENA_RESET                                   0x1
#define PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_CCK_LSB                             29
#define PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_CCK_MSB                             29
#define PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_CCK_MASK                            0x20000000
#define PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_CCK_GET(x)                          (((x) & PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_CCK_MASK) >> PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_CCK_LSB)
#define PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_CCK_SET(x)                          (((0 | (x)) << PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_CCK_LSB) & PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_CCK_MASK)
#define PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_CCK_RESET                           0x0
#define PHY_BB_RESTART_WEAK_RSSI_VOTE_THR_LSB                                  22
#define PHY_BB_RESTART_WEAK_RSSI_VOTE_THR_MSB                                  28
#define PHY_BB_RESTART_WEAK_RSSI_VOTE_THR_MASK                                 0x1fc00000
#define PHY_BB_RESTART_WEAK_RSSI_VOTE_THR_GET(x)                               (((x) & PHY_BB_RESTART_WEAK_RSSI_VOTE_THR_MASK) >> PHY_BB_RESTART_WEAK_RSSI_VOTE_THR_LSB)
#define PHY_BB_RESTART_WEAK_RSSI_VOTE_THR_SET(x)                               (((0 | (x)) << PHY_BB_RESTART_WEAK_RSSI_VOTE_THR_LSB) & PHY_BB_RESTART_WEAK_RSSI_VOTE_THR_MASK)
#define PHY_BB_RESTART_WEAK_RSSI_VOTE_THR_RESET                                0x0
#define PHY_BB_RESTART_ENABLE_ANT_FAST_DIV_M2FLAG_LSB                          21
#define PHY_BB_RESTART_ENABLE_ANT_FAST_DIV_M2FLAG_MSB                          21
#define PHY_BB_RESTART_ENABLE_ANT_FAST_DIV_M2FLAG_MASK                         0x200000
#define PHY_BB_RESTART_ENABLE_ANT_FAST_DIV_M2FLAG_GET(x)                       (((x) & PHY_BB_RESTART_ENABLE_ANT_FAST_DIV_M2FLAG_MASK) >> PHY_BB_RESTART_ENABLE_ANT_FAST_DIV_M2FLAG_LSB)
#define PHY_BB_RESTART_ENABLE_ANT_FAST_DIV_M2FLAG_SET(x)                       (((0 | (x)) << PHY_BB_RESTART_ENABLE_ANT_FAST_DIV_M2FLAG_LSB) & PHY_BB_RESTART_ENABLE_ANT_FAST_DIV_M2FLAG_MASK)
#define PHY_BB_RESTART_ENABLE_ANT_FAST_DIV_M2FLAG_RESET                        0x0
#define PHY_BB_RESTART_ANT_FAST_DIV_GC_LIMIT_LSB                               18
#define PHY_BB_RESTART_ANT_FAST_DIV_GC_LIMIT_MSB                               20
#define PHY_BB_RESTART_ANT_FAST_DIV_GC_LIMIT_MASK                              0x1c0000
#define PHY_BB_RESTART_ANT_FAST_DIV_GC_LIMIT_GET(x)                            (((x) & PHY_BB_RESTART_ANT_FAST_DIV_GC_LIMIT_MASK) >> PHY_BB_RESTART_ANT_FAST_DIV_GC_LIMIT_LSB)
#define PHY_BB_RESTART_ANT_FAST_DIV_GC_LIMIT_SET(x)                            (((0 | (x)) << PHY_BB_RESTART_ANT_FAST_DIV_GC_LIMIT_LSB) & PHY_BB_RESTART_ANT_FAST_DIV_GC_LIMIT_MASK)
#define PHY_BB_RESTART_ANT_FAST_DIV_GC_LIMIT_RESET                             0x2
#define PHY_BB_RESTART_OFDM_CCK_RSSI_BIAS_LSB                                  12
#define PHY_BB_RESTART_OFDM_CCK_RSSI_BIAS_MSB                                  17
#define PHY_BB_RESTART_OFDM_CCK_RSSI_BIAS_MASK                                 0x3f000
#define PHY_BB_RESTART_OFDM_CCK_RSSI_BIAS_GET(x)                               (((x) & PHY_BB_RESTART_OFDM_CCK_RSSI_BIAS_MASK) >> PHY_BB_RESTART_OFDM_CCK_RSSI_BIAS_LSB)
#define PHY_BB_RESTART_OFDM_CCK_RSSI_BIAS_SET(x)                               (((0 | (x)) << PHY_BB_RESTART_OFDM_CCK_RSSI_BIAS_LSB) & PHY_BB_RESTART_OFDM_CCK_RSSI_BIAS_MASK)
#define PHY_BB_RESTART_OFDM_CCK_RSSI_BIAS_RESET                                0x0
#define PHY_BB_RESTART_PWRDROP_LGFIRPWR_DELTA_LSB                              7
#define PHY_BB_RESTART_PWRDROP_LGFIRPWR_DELTA_MSB                              11
#define PHY_BB_RESTART_PWRDROP_LGFIRPWR_DELTA_MASK                             0xf80
#define PHY_BB_RESTART_PWRDROP_LGFIRPWR_DELTA_GET(x)                           (((x) & PHY_BB_RESTART_PWRDROP_LGFIRPWR_DELTA_MASK) >> PHY_BB_RESTART_PWRDROP_LGFIRPWR_DELTA_LSB)
#define PHY_BB_RESTART_PWRDROP_LGFIRPWR_DELTA_SET(x)                           (((0 | (x)) << PHY_BB_RESTART_PWRDROP_LGFIRPWR_DELTA_LSB) & PHY_BB_RESTART_PWRDROP_LGFIRPWR_DELTA_MASK)
#define PHY_BB_RESTART_PWRDROP_LGFIRPWR_DELTA_RESET                            0xa
#define PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_LSB                                 6
#define PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_MSB                                 6
#define PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_MASK                                0x40
#define PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_GET(x)                              (((x) & PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_MASK) >> PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_LSB)
#define PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_SET(x)                              (((0 | (x)) << PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_LSB) & PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_MASK)
#define PHY_BB_RESTART_ENABLE_PWR_DROP_ERR_RESET                               0x0
#define PHY_BB_RESTART_RESTART_LGFIRPWR_DELTA_LSB                              1
#define PHY_BB_RESTART_RESTART_LGFIRPWR_DELTA_MSB                              5
#define PHY_BB_RESTART_RESTART_LGFIRPWR_DELTA_MASK                             0x3e
#define PHY_BB_RESTART_RESTART_LGFIRPWR_DELTA_GET(x)                           (((x) & PHY_BB_RESTART_RESTART_LGFIRPWR_DELTA_MASK) >> PHY_BB_RESTART_RESTART_LGFIRPWR_DELTA_LSB)
#define PHY_BB_RESTART_RESTART_LGFIRPWR_DELTA_SET(x)                           (((0 | (x)) << PHY_BB_RESTART_RESTART_LGFIRPWR_DELTA_LSB) & PHY_BB_RESTART_RESTART_LGFIRPWR_DELTA_MASK)
#define PHY_BB_RESTART_RESTART_LGFIRPWR_DELTA_RESET                            0xa
#define PHY_BB_RESTART_ENABLE_RESTART_LSB                                      0
#define PHY_BB_RESTART_ENABLE_RESTART_MSB                                      0
#define PHY_BB_RESTART_ENABLE_RESTART_MASK                                     0x1
#define PHY_BB_RESTART_ENABLE_RESTART_GET(x)                                   (((x) & PHY_BB_RESTART_ENABLE_RESTART_MASK) >> PHY_BB_RESTART_ENABLE_RESTART_LSB)
#define PHY_BB_RESTART_ENABLE_RESTART_SET(x)                                   (((0 | (x)) << PHY_BB_RESTART_ENABLE_RESTART_LSB) & PHY_BB_RESTART_ENABLE_RESTART_MASK)
#define PHY_BB_RESTART_ENABLE_RESTART_RESET                                    0x0
#define PHY_BB_RESTART_ADDRESS                                                 (0x24 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RESTART_RSTMASK                                                 0xffffffff
#define PHY_BB_RESTART_RESET                                                   0xc0080514

// 0x28 (PHY_BB_MULTICHAIN_GAIN_CTRL)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_SW_COM_LOCK_LSB                    31
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_SW_COM_LOCK_MSB                    31
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_SW_COM_LOCK_MASK                   0x80000000
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_SW_COM_LOCK_GET(x)                 (((x) & PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_SW_COM_LOCK_MASK) >> PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_SW_COM_LOCK_LSB)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_SW_COM_LOCK_SET(x)                 (((0 | (x)) << PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_SW_COM_LOCK_LSB) & PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_SW_COM_LOCK_MASK)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_SW_COM_LOCK_RESET                  0x0
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_GAINTB_LSB                    30
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_GAINTB_MSB                    30
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_GAINTB_MASK                   0x40000000
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_GAINTB_GET(x)                 (((x) & PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_GAINTB_MASK) >> PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_GAINTB_LSB)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_GAINTB_SET(x)                 (((0 | (x)) << PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_GAINTB_LSB) & PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_GAINTB_MASK)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_GAINTB_RESET                  0x0
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_GAINTB_LSB                     29
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_GAINTB_MSB                     29
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_GAINTB_MASK                    0x20000000
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_GAINTB_GET(x)                  (((x) & PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_GAINTB_MASK) >> PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_GAINTB_LSB)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_GAINTB_SET(x)                  (((0 | (x)) << PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_GAINTB_LSB) & PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_GAINTB_MASK)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_GAINTB_RESET                   0x0
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_LNACONF_LSB                   27
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_LNACONF_MSB                   28
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_LNACONF_MASK                  0x18000000
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_LNACONF_GET(x)                (((x) & PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_LNACONF_MASK) >> PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_LNACONF_LSB)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_LNACONF_SET(x)                (((0 | (x)) << PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_LNACONF_LSB) & PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_LNACONF_MASK)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_MAIN_LNACONF_RESET                 0x2
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_LNACONF_LSB                    25
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_LNACONF_MSB                    26
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_LNACONF_MASK                   0x6000000
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_LNACONF_GET(x)                 (((x) & PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_LNACONF_MASK) >> PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_LNACONF_LSB)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_LNACONF_SET(x)                 (((0 | (x)) << PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_LNACONF_LSB) & PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_LNACONF_MASK)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_DIV_ALT_LNACONF_RESET                  0x1
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_DIV_LNADIV_LSB                  24
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_DIV_LNADIV_MSB                  24
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_DIV_LNADIV_MASK                 0x1000000
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_DIV_LNADIV_GET(x)               (((x) & PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_DIV_LNADIV_MASK) >> PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_DIV_LNADIV_LSB)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_DIV_LNADIV_SET(x)               (((0 | (x)) << PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_DIV_LNADIV_LSB) & PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_DIV_LNADIV_MASK)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_DIV_LNADIV_RESET                0x0
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_SW_RX_PROT_LSB                  23
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_SW_RX_PROT_MSB                  23
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_SW_RX_PROT_MASK                 0x800000
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_SW_RX_PROT_GET(x)               (((x) & PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_SW_RX_PROT_MASK) >> PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_SW_RX_PROT_LSB)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_SW_RX_PROT_SET(x)               (((0 | (x)) << PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_SW_RX_PROT_LSB) & PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_SW_RX_PROT_MASK)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_ANT_SW_RX_PROT_RESET                0x0
#define PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_ENA_LSB                  21
#define PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_ENA_MSB                  21
#define PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_ENA_MASK                 0x200000
#define PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_ENA_GET(x)               (((x) & PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_ENA_MASK) >> PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_ENA_LSB)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_ENA_SET(x)               (((0 | (x)) << PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_ENA_LSB) & PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_ENA_MASK)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_ENA_RESET                0x0
#define PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_DB_LSB                   15
#define PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_DB_MSB                   20
#define PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_DB_MASK                  0x1f8000
#define PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_DB_GET(x)                (((x) & PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_DB_MASK) >> PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_DB_LSB)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_DB_SET(x)                (((0 | (x)) << PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_DB_LSB) & PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_DB_MASK)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_QUANT_NOISE_FLOOR_DB_RESET                 0x0
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_FAST_DIV_BIAS_LSB                      9
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_FAST_DIV_BIAS_MSB                      14
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_FAST_DIV_BIAS_MASK                     0x7e00
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_FAST_DIV_BIAS_GET(x)                   (((x) & PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_FAST_DIV_BIAS_MASK) >> PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_FAST_DIV_BIAS_LSB)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_FAST_DIV_BIAS_SET(x)                   (((0 | (x)) << PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_FAST_DIV_BIAS_LSB) & PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_FAST_DIV_BIAS_MASK)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ANT_FAST_DIV_BIAS_RESET                    0x0
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_CHECK_STRONG_ANT_LSB                8
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_CHECK_STRONG_ANT_MSB                8
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_CHECK_STRONG_ANT_MASK               0x100
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_CHECK_STRONG_ANT_GET(x)             (((x) & PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_CHECK_STRONG_ANT_MASK) >> PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_CHECK_STRONG_ANT_LSB)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_CHECK_STRONG_ANT_SET(x)             (((0 | (x)) << PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_CHECK_STRONG_ANT_LSB) & PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_CHECK_STRONG_ANT_MASK)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ENABLE_CHECK_STRONG_ANT_RESET              0x0
#define PHY_BB_MULTICHAIN_GAIN_CTRL_ADDRESS                                    (0x28 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_MULTICHAIN_GAIN_CTRL_RSTMASK                                    0xffbfff00
#define PHY_BB_MULTICHAIN_GAIN_CTRL_RESET                                      0x12000000

// 0x2c (PHY_BB_EXT_CHAN_PWR_THR_1)
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTANF_LSB                  21
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTANF_MSB                  26
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTANF_MASK                 0x7e00000
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTANF_GET(x)               (((x) & PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTANF_MASK) >> PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTANF_LSB)
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTANF_SET(x)               (((0 | (x)) << PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTANF_LSB) & PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTANF_MASK)
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTANF_RESET                0x0
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTAGAINIDX_LSB             16
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTAGAINIDX_MSB             20
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTAGAINIDX_MASK            0x1f0000
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTAGAINIDX_GET(x)          (((x) & PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTAGAINIDX_MASK) >> PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTAGAINIDX_LSB)
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTAGAINIDX_SET(x)          (((0 | (x)) << PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTAGAINIDX_LSB) & PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTAGAINIDX_MASK)
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_DELTAGAINIDX_RESET           0x0
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_MINGAINIDX_LSB               8
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_MINGAINIDX_MSB               15
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_MINGAINIDX_MASK              0xff00
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_MINGAINIDX_GET(x)            (((x) & PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_MINGAINIDX_MASK) >> PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_MINGAINIDX_LSB)
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_MINGAINIDX_SET(x)            (((0 | (x)) << PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_MINGAINIDX_LSB) & PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_MINGAINIDX_MASK)
#define PHY_BB_EXT_CHAN_PWR_THR_1_ANT_DIV_ALT_ANT_MINGAINIDX_RESET             0x0
#define PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40_LSB                            0
#define PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40_MSB                            7
#define PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40_MASK                           0xff
#define PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40_GET(x)                         (((x) & PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40_MASK) >> PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40_LSB)
#define PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40_SET(x)                         (((0 | (x)) << PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40_LSB) & PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40_MASK)
#define PHY_BB_EXT_CHAN_PWR_THR_1_THR_CCA_EXT40_RESET                          0x0
#define PHY_BB_EXT_CHAN_PWR_THR_1_ADDRESS                                      (0x2c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_EXT_CHAN_PWR_THR_1_RSTMASK                                      0x7ffffff
#define PHY_BB_EXT_CHAN_PWR_THR_1_RESET                                        0x0

// 0x30 (PHY_BB_EXT_BW_PWR_THR)
#define PHY_BB_EXT_BW_PWR_THR_MINCCA_RELPWR_THR_LSB                            18
#define PHY_BB_EXT_BW_PWR_THR_MINCCA_RELPWR_THR_MSB                            25
#define PHY_BB_EXT_BW_PWR_THR_MINCCA_RELPWR_THR_MASK                           0x3fc0000
#define PHY_BB_EXT_BW_PWR_THR_MINCCA_RELPWR_THR_GET(x)                         (((x) & PHY_BB_EXT_BW_PWR_THR_MINCCA_RELPWR_THR_MASK) >> PHY_BB_EXT_BW_PWR_THR_MINCCA_RELPWR_THR_LSB)
#define PHY_BB_EXT_BW_PWR_THR_MINCCA_RELPWR_THR_SET(x)                         (((0 | (x)) << PHY_BB_EXT_BW_PWR_THR_MINCCA_RELPWR_THR_LSB) & PHY_BB_EXT_BW_PWR_THR_MINCCA_RELPWR_THR_MASK)
#define PHY_BB_EXT_BW_PWR_THR_MINCCA_RELPWR_THR_RESET                          0xe0
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT40_MAX_DELTA_DB_LSB                    12
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT40_MAX_DELTA_DB_MSB                    17
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT40_MAX_DELTA_DB_MASK                   0x3f000
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT40_MAX_DELTA_DB_GET(x)                 (((x) & PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT40_MAX_DELTA_DB_MASK) >> PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT40_MAX_DELTA_DB_LSB)
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT40_MAX_DELTA_DB_SET(x)                 (((0 | (x)) << PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT40_MAX_DELTA_DB_LSB) & PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT40_MAX_DELTA_DB_MASK)
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT40_MAX_DELTA_DB_RESET                  0xa
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT20_MAX_DELTA_DB_LSB                    6
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT20_MAX_DELTA_DB_MSB                    11
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT20_MAX_DELTA_DB_MASK                   0xfc0
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT20_MAX_DELTA_DB_GET(x)                 (((x) & PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT20_MAX_DELTA_DB_MASK) >> PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT20_MAX_DELTA_DB_LSB)
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT20_MAX_DELTA_DB_SET(x)                 (((0 | (x)) << PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT20_MAX_DELTA_DB_LSB) & PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT20_MAX_DELTA_DB_MASK)
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_EXT20_MAX_DELTA_DB_RESET                  0xa
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_PRI20_MIN_RSSI_DB_LSB                     0
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_PRI20_MIN_RSSI_DB_MSB                     5
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_PRI20_MIN_RSSI_DB_MASK                    0x3f
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_PRI20_MIN_RSSI_DB_GET(x)                  (((x) & PHY_BB_EXT_BW_PWR_THR_BW_DET_PRI20_MIN_RSSI_DB_MASK) >> PHY_BB_EXT_BW_PWR_THR_BW_DET_PRI20_MIN_RSSI_DB_LSB)
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_PRI20_MIN_RSSI_DB_SET(x)                  (((0 | (x)) << PHY_BB_EXT_BW_PWR_THR_BW_DET_PRI20_MIN_RSSI_DB_LSB) & PHY_BB_EXT_BW_PWR_THR_BW_DET_PRI20_MIN_RSSI_DB_MASK)
#define PHY_BB_EXT_BW_PWR_THR_BW_DET_PRI20_MIN_RSSI_DB_RESET                   0x8
#define PHY_BB_EXT_BW_PWR_THR_ADDRESS                                          (0x30 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_EXT_BW_PWR_THR_RSTMASK                                          0x3ffffff
#define PHY_BB_EXT_BW_PWR_THR_RESET                                            0x380a288

// 0x34 (PHY_BB_EXT_BW_PWR_THR_2)
#define PHY_BB_EXT_BW_PWR_THR_2_THR_CCA_EXT80_LSB                              16
#define PHY_BB_EXT_BW_PWR_THR_2_THR_CCA_EXT80_MSB                              23
#define PHY_BB_EXT_BW_PWR_THR_2_THR_CCA_EXT80_MASK                             0xff0000
#define PHY_BB_EXT_BW_PWR_THR_2_THR_CCA_EXT80_GET(x)                           (((x) & PHY_BB_EXT_BW_PWR_THR_2_THR_CCA_EXT80_MASK) >> PHY_BB_EXT_BW_PWR_THR_2_THR_CCA_EXT80_LSB)
#define PHY_BB_EXT_BW_PWR_THR_2_THR_CCA_EXT80_SET(x)                           (((0 | (x)) << PHY_BB_EXT_BW_PWR_THR_2_THR_CCA_EXT80_LSB) & PHY_BB_EXT_BW_PWR_THR_2_THR_CCA_EXT80_MASK)
#define PHY_BB_EXT_BW_PWR_THR_2_THR_CCA_EXT80_RESET                            0x0
#define PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT40_MIN_RSSI_DB_LSB                   8
#define PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT40_MIN_RSSI_DB_MSB                   13
#define PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT40_MIN_RSSI_DB_MASK                  0x3f00
#define PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT40_MIN_RSSI_DB_GET(x)                (((x) & PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT40_MIN_RSSI_DB_MASK) >> PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT40_MIN_RSSI_DB_LSB)
#define PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT40_MIN_RSSI_DB_SET(x)                (((0 | (x)) << PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT40_MIN_RSSI_DB_LSB) & PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT40_MIN_RSSI_DB_MASK)
#define PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT40_MIN_RSSI_DB_RESET                 0x8
#define PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT20_MIN_RSSI_DB_LSB                   0
#define PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT20_MIN_RSSI_DB_MSB                   5
#define PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT20_MIN_RSSI_DB_MASK                  0x3f
#define PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT20_MIN_RSSI_DB_GET(x)                (((x) & PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT20_MIN_RSSI_DB_MASK) >> PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT20_MIN_RSSI_DB_LSB)
#define PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT20_MIN_RSSI_DB_SET(x)                (((0 | (x)) << PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT20_MIN_RSSI_DB_LSB) & PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT20_MIN_RSSI_DB_MASK)
#define PHY_BB_EXT_BW_PWR_THR_2_BW_DET_EXT20_MIN_RSSI_DB_RESET                 0x5
#define PHY_BB_EXT_BW_PWR_THR_2_ADDRESS                                        (0x34 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_EXT_BW_PWR_THR_2_RSTMASK                                        0xff3f3f
#define PHY_BB_EXT_BW_PWR_THR_2_RESET                                          0x805

// 0x38 (PHY_BB_RIFS_SRCH)
#define PHY_BB_RIFS_SRCH_RIFS_DISABLE_CCK_DET_LSB                              27
#define PHY_BB_RIFS_SRCH_RIFS_DISABLE_CCK_DET_MSB                              27
#define PHY_BB_RIFS_SRCH_RIFS_DISABLE_CCK_DET_MASK                             0x8000000
#define PHY_BB_RIFS_SRCH_RIFS_DISABLE_CCK_DET_GET(x)                           (((x) & PHY_BB_RIFS_SRCH_RIFS_DISABLE_CCK_DET_MASK) >> PHY_BB_RIFS_SRCH_RIFS_DISABLE_CCK_DET_LSB)
#define PHY_BB_RIFS_SRCH_RIFS_DISABLE_CCK_DET_SET(x)                           (((0 | (x)) << PHY_BB_RIFS_SRCH_RIFS_DISABLE_CCK_DET_LSB) & PHY_BB_RIFS_SRCH_RIFS_DISABLE_CCK_DET_MASK)
#define PHY_BB_RIFS_SRCH_RIFS_DISABLE_CCK_DET_RESET                            0x0
#define PHY_BB_RIFS_SRCH_RIFS_DISABLE_PWRLOW_GC_LSB                            26
#define PHY_BB_RIFS_SRCH_RIFS_DISABLE_PWRLOW_GC_MSB                            26
#define PHY_BB_RIFS_SRCH_RIFS_DISABLE_PWRLOW_GC_MASK                           0x4000000
#define PHY_BB_RIFS_SRCH_RIFS_DISABLE_PWRLOW_GC_GET(x)                         (((x) & PHY_BB_RIFS_SRCH_RIFS_DISABLE_PWRLOW_GC_MASK) >> PHY_BB_RIFS_SRCH_RIFS_DISABLE_PWRLOW_GC_LSB)
#define PHY_BB_RIFS_SRCH_RIFS_DISABLE_PWRLOW_GC_SET(x)                         (((0 | (x)) << PHY_BB_RIFS_SRCH_RIFS_DISABLE_PWRLOW_GC_LSB) & PHY_BB_RIFS_SRCH_RIFS_DISABLE_PWRLOW_GC_MASK)
#define PHY_BB_RIFS_SRCH_RIFS_DISABLE_PWRLOW_GC_RESET                          0x1
#define PHY_BB_RIFS_SRCH_RIFS_INIT_DELAY_LSB                                   16
#define PHY_BB_RIFS_SRCH_RIFS_INIT_DELAY_MSB                                   25
#define PHY_BB_RIFS_SRCH_RIFS_INIT_DELAY_MASK                                  0x3ff0000
#define PHY_BB_RIFS_SRCH_RIFS_INIT_DELAY_GET(x)                                (((x) & PHY_BB_RIFS_SRCH_RIFS_INIT_DELAY_MASK) >> PHY_BB_RIFS_SRCH_RIFS_INIT_DELAY_LSB)
#define PHY_BB_RIFS_SRCH_RIFS_INIT_DELAY_SET(x)                                (((0 | (x)) << PHY_BB_RIFS_SRCH_RIFS_INIT_DELAY_LSB) & PHY_BB_RIFS_SRCH_RIFS_INIT_DELAY_MASK)
#define PHY_BB_RIFS_SRCH_RIFS_INIT_DELAY_RESET                                 0x190
#define PHY_BB_RIFS_SRCH_INIT_GAIN_DB_OFFSET_LSB                               8
#define PHY_BB_RIFS_SRCH_INIT_GAIN_DB_OFFSET_MSB                               15
#define PHY_BB_RIFS_SRCH_INIT_GAIN_DB_OFFSET_MASK                              0xff00
#define PHY_BB_RIFS_SRCH_INIT_GAIN_DB_OFFSET_GET(x)                            (((x) & PHY_BB_RIFS_SRCH_INIT_GAIN_DB_OFFSET_MASK) >> PHY_BB_RIFS_SRCH_INIT_GAIN_DB_OFFSET_LSB)
#define PHY_BB_RIFS_SRCH_INIT_GAIN_DB_OFFSET_SET(x)                            (((0 | (x)) << PHY_BB_RIFS_SRCH_INIT_GAIN_DB_OFFSET_LSB) & PHY_BB_RIFS_SRCH_INIT_GAIN_DB_OFFSET_MASK)
#define PHY_BB_RIFS_SRCH_INIT_GAIN_DB_OFFSET_RESET                             0xc
#define PHY_BB_RIFS_SRCH_ADDRESS                                               (0x38 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RIFS_SRCH_RSTMASK                                               0xfffff00
#define PHY_BB_RIFS_SRCH_RESET                                                 0x5900c00

// 0x3c (PHY_BB_PEAK_DET_CTRL_1)
#define PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_RX_LSB                         31
#define PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_RX_MSB                         31
#define PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_RX_MASK                        0x80000000
#define PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_RX_GET(x)                      (((x) & PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_RX_MASK) >> PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_RX_LSB)
#define PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_RX_SET(x)                      (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_RX_LSB) & PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_RX_MASK)
#define PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_RX_RESET                       0x1
#define PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_CAL_LSB                        30
#define PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_CAL_MSB                        30
#define PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_CAL_MASK                       0x40000000
#define PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_CAL_GET(x)                     (((x) & PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_CAL_MASK) >> PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_CAL_LSB)
#define PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_CAL_SET(x)                     (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_CAL_LSB) & PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_CAL_MASK)
#define PHY_BB_PEAK_DET_CTRL_1_PWD_PKDET_DURING_CAL_RESET                      0x1
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_SETTLING_LSB                           23
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_SETTLING_MSB                           29
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_SETTLING_MASK                          0x3f800000
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_SETTLING_GET(x)                        (((x) & PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_SETTLING_MASK) >> PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_SETTLING_LSB)
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_SETTLING_SET(x)                        (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_SETTLING_LSB) & PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_SETTLING_MASK)
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_SETTLING_RESET                         0x1f
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_HIGH_0_LSB                   18
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_HIGH_0_MSB                   22
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_HIGH_0_MASK                  0x7c0000
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_HIGH_0_GET(x)                (((x) & PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_HIGH_0_MASK) >> PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_HIGH_0_LSB)
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_HIGH_0_SET(x)                (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_HIGH_0_LSB) & PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_HIGH_0_MASK)
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_HIGH_0_RESET                 0xf
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_MED_0_LSB                    13
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_MED_0_MSB                    17
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_MED_0_MASK                   0x3e000
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_MED_0_GET(x)                 (((x) & PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_MED_0_MASK) >> PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_MED_0_LSB)
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_MED_0_SET(x)                 (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_MED_0_LSB) & PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_MED_0_MASK)
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_MED_0_RESET                  0xf
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_LOW_0_LSB                    8
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_LOW_0_MSB                    12
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_LOW_0_MASK                   0x1f00
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_LOW_0_GET(x)                 (((x) & PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_LOW_0_MASK) >> PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_LOW_0_LSB)
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_LOW_0_SET(x)                 (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_LOW_0_LSB) & PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_LOW_0_MASK)
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_TALLY_THR_LOW_0_RESET                  0xf
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_WIN_LEN_LSB                            2
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_WIN_LEN_MSB                            7
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_WIN_LEN_MASK                           0xfc
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_WIN_LEN_GET(x)                         (((x) & PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_WIN_LEN_MASK) >> PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_WIN_LEN_LSB)
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_WIN_LEN_SET(x)                         (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_WIN_LEN_LSB) & PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_WIN_LEN_MASK)
#define PHY_BB_PEAK_DET_CTRL_1_PEAK_DET_WIN_LEN_RESET                          0x10
#define PHY_BB_PEAK_DET_CTRL_1_USE_PEAK_DET_LSB                                1
#define PHY_BB_PEAK_DET_CTRL_1_USE_PEAK_DET_MSB                                1
#define PHY_BB_PEAK_DET_CTRL_1_USE_PEAK_DET_MASK                               0x2
#define PHY_BB_PEAK_DET_CTRL_1_USE_PEAK_DET_GET(x)                             (((x) & PHY_BB_PEAK_DET_CTRL_1_USE_PEAK_DET_MASK) >> PHY_BB_PEAK_DET_CTRL_1_USE_PEAK_DET_LSB)
#define PHY_BB_PEAK_DET_CTRL_1_USE_PEAK_DET_SET(x)                             (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_1_USE_PEAK_DET_LSB) & PHY_BB_PEAK_DET_CTRL_1_USE_PEAK_DET_MASK)
#define PHY_BB_PEAK_DET_CTRL_1_USE_PEAK_DET_RESET                              0x1
#define PHY_BB_PEAK_DET_CTRL_1_USE_OC_GAIN_TABLE_LSB                           0
#define PHY_BB_PEAK_DET_CTRL_1_USE_OC_GAIN_TABLE_MSB                           0
#define PHY_BB_PEAK_DET_CTRL_1_USE_OC_GAIN_TABLE_MASK                          0x1
#define PHY_BB_PEAK_DET_CTRL_1_USE_OC_GAIN_TABLE_GET(x)                        (((x) & PHY_BB_PEAK_DET_CTRL_1_USE_OC_GAIN_TABLE_MASK) >> PHY_BB_PEAK_DET_CTRL_1_USE_OC_GAIN_TABLE_LSB)
#define PHY_BB_PEAK_DET_CTRL_1_USE_OC_GAIN_TABLE_SET(x)                        (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_1_USE_OC_GAIN_TABLE_LSB) & PHY_BB_PEAK_DET_CTRL_1_USE_OC_GAIN_TABLE_MASK)
#define PHY_BB_PEAK_DET_CTRL_1_USE_OC_GAIN_TABLE_RESET                         0x0
#define PHY_BB_PEAK_DET_CTRL_1_ADDRESS                                         (0x3c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_PEAK_DET_CTRL_1_RSTMASK                                         0xffffffff
#define PHY_BB_PEAK_DET_CTRL_1_RESET                                           0xcfbdef42

// 0x40 (PHY_BB_PEAK_DET_CTRL_2)
#define PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_STRONG_LSB                         31
#define PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_STRONG_MSB                         31
#define PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_STRONG_MASK                        0x80000000
#define PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_STRONG_GET(x)                      (((x) & PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_STRONG_MASK) >> PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_STRONG_LSB)
#define PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_STRONG_SET(x)                      (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_STRONG_LSB) & PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_STRONG_MASK)
#define PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_STRONG_RESET                       0x1
#define PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_RESTART_LSB                        30
#define PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_RESTART_MSB                        30
#define PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_RESTART_MASK                       0x40000000
#define PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_RESTART_GET(x)                     (((x) & PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_RESTART_MASK) >> PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_RESTART_LSB)
#define PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_RESTART_SET(x)                     (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_RESTART_LSB) & PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_RESTART_MASK)
#define PHY_BB_PEAK_DET_CTRL_2_ENABLE_RFSAT_RESTART_RESET                      0x0
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_NON_0_LSB                       18
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_NON_0_MSB                       22
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_NON_0_MASK                      0x7c0000
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_NON_0_GET(x)                    (((x) & PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_NON_0_MASK) >> PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_NON_0_LSB)
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_NON_0_SET(x)                    (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_NON_0_LSB) & PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_NON_0_MASK)
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_NON_0_RESET                     0xa
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_HIGH_0_LSB                      12
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_HIGH_0_MSB                      16
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_HIGH_0_MASK                     0x1f000
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_HIGH_0_GET(x)                   (((x) & PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_HIGH_0_MASK) >> PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_HIGH_0_LSB)
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_HIGH_0_SET(x)                   (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_HIGH_0_LSB) & PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_HIGH_0_MASK)
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_HIGH_0_RESET                    0x1c
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_MED_0_LSB                       6
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_MED_0_MSB                       10
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_MED_0_MASK                      0x7c0
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_MED_0_GET(x)                    (((x) & PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_MED_0_MASK) >> PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_MED_0_LSB)
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_MED_0_SET(x)                    (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_MED_0_LSB) & PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_MED_0_MASK)
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_MED_0_RESET                     0xc
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_LOW_0_LSB                       0
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_LOW_0_MSB                       4
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_LOW_0_MASK                      0x1f
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_LOW_0_GET(x)                    (((x) & PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_LOW_0_MASK) >> PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_LOW_0_LSB)
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_LOW_0_SET(x)                    (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_LOW_0_LSB) & PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_LOW_0_MASK)
#define PHY_BB_PEAK_DET_CTRL_2_RF_GAIN_DROP_DB_LOW_0_RESET                     0x6
#define PHY_BB_PEAK_DET_CTRL_2_ADDRESS                                         (0x40 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_PEAK_DET_CTRL_2_RSTMASK                                         0xc07df7df
#define PHY_BB_PEAK_DET_CTRL_2_RESET                                           0x8029c306

// 0x44 (PHY_BB_RX_GAIN_BOUNDS_1)
#define PHY_BB_RX_GAIN_BOUNDS_1_RF_MB_GAIN_DELTA_MAX_DB_LSB                    26
#define PHY_BB_RX_GAIN_BOUNDS_1_RF_MB_GAIN_DELTA_MAX_DB_MSB                    31
#define PHY_BB_RX_GAIN_BOUNDS_1_RF_MB_GAIN_DELTA_MAX_DB_MASK                   0xfc000000
#define PHY_BB_RX_GAIN_BOUNDS_1_RF_MB_GAIN_DELTA_MAX_DB_GET(x)                 (((x) & PHY_BB_RX_GAIN_BOUNDS_1_RF_MB_GAIN_DELTA_MAX_DB_MASK) >> PHY_BB_RX_GAIN_BOUNDS_1_RF_MB_GAIN_DELTA_MAX_DB_LSB)
#define PHY_BB_RX_GAIN_BOUNDS_1_RF_MB_GAIN_DELTA_MAX_DB_SET(x)                 (((0 | (x)) << PHY_BB_RX_GAIN_BOUNDS_1_RF_MB_GAIN_DELTA_MAX_DB_LSB) & PHY_BB_RX_GAIN_BOUNDS_1_RF_MB_GAIN_DELTA_MAX_DB_MASK)
#define PHY_BB_RX_GAIN_BOUNDS_1_RF_MB_GAIN_DELTA_MAX_DB_RESET                  0x3f
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_5G_LSB                           25
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_5G_MSB                           25
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_5G_MASK                          0x2000000
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_5G_GET(x)                        (((x) & PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_5G_MASK) >> PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_5G_LSB)
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_5G_SET(x)                        (((0 | (x)) << PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_5G_LSB) & PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_5G_MASK)
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_5G_RESET                         0x0
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_2G_LSB                           24
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_2G_MSB                           24
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_2G_MASK                          0x1000000
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_2G_GET(x)                        (((x) & PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_2G_MASK) >> PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_2G_LSB)
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_2G_SET(x)                        (((0 | (x)) << PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_2G_LSB) & PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_2G_MASK)
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_OCGAIN_SEL_2G_RESET                         0x0
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_LSB                             16
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_MSB                             23
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_MASK                            0xff0000
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_GET(x)                          (((x) & PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_MASK) >> PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_LSB)
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_SET(x)                          (((0 | (x)) << PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_LSB) & PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_MASK)
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_RESET                           0x2e
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_REF_LSB                         8
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_REF_MSB                         15
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_REF_MASK                        0xff00
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_REF_GET(x)                      (((x) & PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_REF_MASK) >> PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_REF_LSB)
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_REF_SET(x)                      (((0 | (x)) << PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_REF_LSB) & PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_REF_MASK)
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_RF_GAIN_REF_RESET                       0x28
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_MB_GAIN_LSB                             0
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_MB_GAIN_MSB                             7
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_MB_GAIN_MASK                            0xff
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_MB_GAIN_GET(x)                          (((x) & PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_MB_GAIN_MASK) >> PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_MB_GAIN_LSB)
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_MB_GAIN_SET(x)                          (((0 | (x)) << PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_MB_GAIN_LSB) & PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_MB_GAIN_MASK)
#define PHY_BB_RX_GAIN_BOUNDS_1_RX_MAX_MB_GAIN_RESET                           0x27
#define PHY_BB_RX_GAIN_BOUNDS_1_ADDRESS                                        (0x44 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_GAIN_BOUNDS_1_RSTMASK                                        0xffffffff
#define PHY_BB_RX_GAIN_BOUNDS_1_RESET                                          0xfc2e2827

// 0x48 (PHY_BB_RX_GAIN_BOUNDS_2)
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_DIV_BASE_ADDR_LSB                      24
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_DIV_BASE_ADDR_MSB                      31
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_DIV_BASE_ADDR_MASK                     0xff000000
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_DIV_BASE_ADDR_GET(x)                   (((x) & PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_DIV_BASE_ADDR_MASK) >> PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_DIV_BASE_ADDR_LSB)
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_DIV_BASE_ADDR_SET(x)                   (((0 | (x)) << PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_DIV_BASE_ADDR_LSB) & PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_DIV_BASE_ADDR_MASK)
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_DIV_BASE_ADDR_RESET                    0x50
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_BASE_ADDR_LSB                          16
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_BASE_ADDR_MSB                          23
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_BASE_ADDR_MASK                         0xff0000
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_BASE_ADDR_GET(x)                       (((x) & PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_BASE_ADDR_MASK) >> PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_BASE_ADDR_LSB)
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_BASE_ADDR_SET(x)                       (((0 | (x)) << PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_BASE_ADDR_LSB) & PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_BASE_ADDR_MASK)
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_BASE_ADDR_RESET                        0x30
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_REF_BASE_ADDR_LSB                      8
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_REF_BASE_ADDR_MSB                      15
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_REF_BASE_ADDR_MASK                     0xff00
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_REF_BASE_ADDR_GET(x)                   (((x) & PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_REF_BASE_ADDR_MASK) >> PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_REF_BASE_ADDR_LSB)
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_REF_BASE_ADDR_SET(x)                   (((0 | (x)) << PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_REF_BASE_ADDR_LSB) & PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_REF_BASE_ADDR_MASK)
#define PHY_BB_RX_GAIN_BOUNDS_2_RF_GAIN_REF_BASE_ADDR_RESET                    0x20
#define PHY_BB_RX_GAIN_BOUNDS_2_GC_RSSI_LOW_DB_LSB                             0
#define PHY_BB_RX_GAIN_BOUNDS_2_GC_RSSI_LOW_DB_MSB                             7
#define PHY_BB_RX_GAIN_BOUNDS_2_GC_RSSI_LOW_DB_MASK                            0xff
#define PHY_BB_RX_GAIN_BOUNDS_2_GC_RSSI_LOW_DB_GET(x)                          (((x) & PHY_BB_RX_GAIN_BOUNDS_2_GC_RSSI_LOW_DB_MASK) >> PHY_BB_RX_GAIN_BOUNDS_2_GC_RSSI_LOW_DB_LSB)
#define PHY_BB_RX_GAIN_BOUNDS_2_GC_RSSI_LOW_DB_SET(x)                          (((0 | (x)) << PHY_BB_RX_GAIN_BOUNDS_2_GC_RSSI_LOW_DB_LSB) & PHY_BB_RX_GAIN_BOUNDS_2_GC_RSSI_LOW_DB_MASK)
#define PHY_BB_RX_GAIN_BOUNDS_2_GC_RSSI_LOW_DB_RESET                           0x3
#define PHY_BB_RX_GAIN_BOUNDS_2_ADDRESS                                        (0x48 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_GAIN_BOUNDS_2_RSTMASK                                        0xffffffff
#define PHY_BB_RX_GAIN_BOUNDS_2_RESET                                          0x50302003

// 0x4c (PHY_BB_PEAK_DET_CAL_CTRL)
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_MEAS_TIME_SEL_LSB                   13
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_MEAS_TIME_SEL_MSB                   14
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_MEAS_TIME_SEL_MASK                  0x6000
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_MEAS_TIME_SEL_GET(x)                (((x) & PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_MEAS_TIME_SEL_MASK) >> PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_MEAS_TIME_SEL_LSB)
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_MEAS_TIME_SEL_SET(x)                (((0 | (x)) << PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_MEAS_TIME_SEL_LSB) & PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_MEAS_TIME_SEL_MASK)
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_MEAS_TIME_SEL_RESET                 0x1
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_BIAS_LSB                            7
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_BIAS_MSB                            12
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_BIAS_MASK                           0x1f80
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_BIAS_GET(x)                         (((x) & PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_BIAS_MASK) >> PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_BIAS_LSB)
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_BIAS_SET(x)                         (((0 | (x)) << PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_BIAS_LSB) & PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_BIAS_MASK)
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_BIAS_RESET                          0x0
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_WIN_THR_LSB                         0
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_WIN_THR_MSB                         6
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_WIN_THR_MASK                        0x7f
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_WIN_THR_GET(x)                      (((x) & PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_WIN_THR_MASK) >> PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_WIN_THR_LSB)
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_WIN_THR_SET(x)                      (((0 | (x)) << PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_WIN_THR_LSB) & PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_WIN_THR_MASK)
#define PHY_BB_PEAK_DET_CAL_CTRL_PKDET_CAL_WIN_THR_RESET                       0x4
#define PHY_BB_PEAK_DET_CAL_CTRL_ADDRESS                                       (0x4c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_PEAK_DET_CAL_CTRL_RSTMASK                                       0x7fff
#define PHY_BB_PEAK_DET_CAL_CTRL_RESET                                         0x2004

// 0x50 (PHY_BB_AGC_DIG_DC_CTRL)
#define PHY_BB_AGC_DIG_DC_CTRL_DIG_DC_SWITCH_CCK_LSB                           10
#define PHY_BB_AGC_DIG_DC_CTRL_DIG_DC_SWITCH_CCK_MSB                           10
#define PHY_BB_AGC_DIG_DC_CTRL_DIG_DC_SWITCH_CCK_MASK                          0x400
#define PHY_BB_AGC_DIG_DC_CTRL_DIG_DC_SWITCH_CCK_GET(x)                        (((x) & PHY_BB_AGC_DIG_DC_CTRL_DIG_DC_SWITCH_CCK_MASK) >> PHY_BB_AGC_DIG_DC_CTRL_DIG_DC_SWITCH_CCK_LSB)
#define PHY_BB_AGC_DIG_DC_CTRL_DIG_DC_SWITCH_CCK_SET(x)                        (((0 | (x)) << PHY_BB_AGC_DIG_DC_CTRL_DIG_DC_SWITCH_CCK_LSB) & PHY_BB_AGC_DIG_DC_CTRL_DIG_DC_SWITCH_CCK_MASK)
#define PHY_BB_AGC_DIG_DC_CTRL_DIG_DC_SWITCH_CCK_RESET                         0x0
#define PHY_BB_AGC_DIG_DC_CTRL_USE_DIG_DC_LSB                                  0
#define PHY_BB_AGC_DIG_DC_CTRL_USE_DIG_DC_MSB                                  0
#define PHY_BB_AGC_DIG_DC_CTRL_USE_DIG_DC_MASK                                 0x1
#define PHY_BB_AGC_DIG_DC_CTRL_USE_DIG_DC_GET(x)                               (((x) & PHY_BB_AGC_DIG_DC_CTRL_USE_DIG_DC_MASK) >> PHY_BB_AGC_DIG_DC_CTRL_USE_DIG_DC_LSB)
#define PHY_BB_AGC_DIG_DC_CTRL_USE_DIG_DC_SET(x)                               (((0 | (x)) << PHY_BB_AGC_DIG_DC_CTRL_USE_DIG_DC_LSB) & PHY_BB_AGC_DIG_DC_CTRL_USE_DIG_DC_MASK)
#define PHY_BB_AGC_DIG_DC_CTRL_USE_DIG_DC_RESET                                0x1
#define PHY_BB_AGC_DIG_DC_CTRL_ADDRESS                                         (0x50 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_AGC_DIG_DC_CTRL_RSTMASK                                         0x401
#define PHY_BB_AGC_DIG_DC_CTRL_RESET                                           0x1

// 0x54 (PHY_BB_BT_COEX_1)
#define PHY_BB_BT_COEX_1_BT_RX_DISABLE_NF_CAL_LSB                              31
#define PHY_BB_BT_COEX_1_BT_RX_DISABLE_NF_CAL_MSB                              31
#define PHY_BB_BT_COEX_1_BT_RX_DISABLE_NF_CAL_MASK                             0x80000000
#define PHY_BB_BT_COEX_1_BT_RX_DISABLE_NF_CAL_GET(x)                           (((x) & PHY_BB_BT_COEX_1_BT_RX_DISABLE_NF_CAL_MASK) >> PHY_BB_BT_COEX_1_BT_RX_DISABLE_NF_CAL_LSB)
#define PHY_BB_BT_COEX_1_BT_RX_DISABLE_NF_CAL_SET(x)                           (((0 | (x)) << PHY_BB_BT_COEX_1_BT_RX_DISABLE_NF_CAL_LSB) & PHY_BB_BT_COEX_1_BT_RX_DISABLE_NF_CAL_MASK)
#define PHY_BB_BT_COEX_1_BT_RX_DISABLE_NF_CAL_RESET                            0x0
#define PHY_BB_BT_COEX_1_BT_TX_DISABLE_NF_CAL_LSB                              30
#define PHY_BB_BT_COEX_1_BT_TX_DISABLE_NF_CAL_MSB                              30
#define PHY_BB_BT_COEX_1_BT_TX_DISABLE_NF_CAL_MASK                             0x40000000
#define PHY_BB_BT_COEX_1_BT_TX_DISABLE_NF_CAL_GET(x)                           (((x) & PHY_BB_BT_COEX_1_BT_TX_DISABLE_NF_CAL_MASK) >> PHY_BB_BT_COEX_1_BT_TX_DISABLE_NF_CAL_LSB)
#define PHY_BB_BT_COEX_1_BT_TX_DISABLE_NF_CAL_SET(x)                           (((0 | (x)) << PHY_BB_BT_COEX_1_BT_TX_DISABLE_NF_CAL_LSB) & PHY_BB_BT_COEX_1_BT_TX_DISABLE_NF_CAL_MASK)
#define PHY_BB_BT_COEX_1_BT_TX_DISABLE_NF_CAL_RESET                            0x0
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_HIGH_1_LSB                            25
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_HIGH_1_MSB                            29
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_HIGH_1_MASK                           0x3e000000
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_HIGH_1_GET(x)                         (((x) & PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_HIGH_1_MASK) >> PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_HIGH_1_LSB)
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_HIGH_1_SET(x)                         (((0 | (x)) << PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_HIGH_1_LSB) & PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_HIGH_1_MASK)
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_HIGH_1_RESET                          0x0
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_MED_1_LSB                             20
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_MED_1_MSB                             24
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_MED_1_MASK                            0x1f00000
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_MED_1_GET(x)                          (((x) & PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_MED_1_MASK) >> PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_MED_1_LSB)
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_MED_1_SET(x)                          (((0 | (x)) << PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_MED_1_LSB) & PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_MED_1_MASK)
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_MED_1_RESET                           0x0
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_LOW_1_LSB                             15
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_LOW_1_MSB                             19
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_LOW_1_MASK                            0xf8000
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_LOW_1_GET(x)                          (((x) & PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_LOW_1_MASK) >> PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_LOW_1_LSB)
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_LOW_1_SET(x)                          (((0 | (x)) << PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_LOW_1_LSB) & PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_LOW_1_MASK)
#define PHY_BB_BT_COEX_1_RF_GAIN_DROP_DB_LOW_1_RESET                           0x0
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_HIGH_1_LSB                         10
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_HIGH_1_MSB                         14
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_HIGH_1_MASK                        0x7c00
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_HIGH_1_GET(x)                      (((x) & PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_HIGH_1_MASK) >> PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_HIGH_1_LSB)
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_HIGH_1_SET(x)                      (((0 | (x)) << PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_HIGH_1_LSB) & PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_HIGH_1_MASK)
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_HIGH_1_RESET                       0x0
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_MED_1_LSB                          5
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_MED_1_MSB                          9
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_MED_1_MASK                         0x3e0
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_MED_1_GET(x)                       (((x) & PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_MED_1_MASK) >> PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_MED_1_LSB)
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_MED_1_SET(x)                       (((0 | (x)) << PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_MED_1_LSB) & PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_MED_1_MASK)
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_MED_1_RESET                        0x0
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_LOW_1_LSB                          0
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_LOW_1_MSB                          4
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_LOW_1_MASK                         0x1f
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_LOW_1_GET(x)                       (((x) & PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_LOW_1_MASK) >> PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_LOW_1_LSB)
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_LOW_1_SET(x)                       (((0 | (x)) << PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_LOW_1_LSB) & PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_LOW_1_MASK)
#define PHY_BB_BT_COEX_1_PEAK_DET_TALLY_THR_LOW_1_RESET                        0x0
#define PHY_BB_BT_COEX_1_ADDRESS                                               (0x54 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_BT_COEX_1_RSTMASK                                               0xffffffff
#define PHY_BB_BT_COEX_1_RESET                                                 0x0

// 0x58 (PHY_BB_BT_COEX_2)
#define PHY_BB_BT_COEX_2_RFSAT_RX_RX_LSB                                       30
#define PHY_BB_BT_COEX_2_RFSAT_RX_RX_MSB                                       31
#define PHY_BB_BT_COEX_2_RFSAT_RX_RX_MASK                                      0xc0000000
#define PHY_BB_BT_COEX_2_RFSAT_RX_RX_GET(x)                                    (((x) & PHY_BB_BT_COEX_2_RFSAT_RX_RX_MASK) >> PHY_BB_BT_COEX_2_RFSAT_RX_RX_LSB)
#define PHY_BB_BT_COEX_2_RFSAT_RX_RX_SET(x)                                    (((0 | (x)) << PHY_BB_BT_COEX_2_RFSAT_RX_RX_LSB) & PHY_BB_BT_COEX_2_RFSAT_RX_RX_MASK)
#define PHY_BB_BT_COEX_2_RFSAT_RX_RX_RESET                                     0x0
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_HIGH_2_LSB                            25
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_HIGH_2_MSB                            29
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_HIGH_2_MASK                           0x3e000000
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_HIGH_2_GET(x)                         (((x) & PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_HIGH_2_MASK) >> PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_HIGH_2_LSB)
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_HIGH_2_SET(x)                         (((0 | (x)) << PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_HIGH_2_LSB) & PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_HIGH_2_MASK)
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_HIGH_2_RESET                          0x0
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_MED_2_LSB                             20
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_MED_2_MSB                             24
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_MED_2_MASK                            0x1f00000
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_MED_2_GET(x)                          (((x) & PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_MED_2_MASK) >> PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_MED_2_LSB)
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_MED_2_SET(x)                          (((0 | (x)) << PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_MED_2_LSB) & PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_MED_2_MASK)
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_MED_2_RESET                           0x0
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_LOW_2_LSB                             15
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_LOW_2_MSB                             19
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_LOW_2_MASK                            0xf8000
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_LOW_2_GET(x)                          (((x) & PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_LOW_2_MASK) >> PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_LOW_2_LSB)
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_LOW_2_SET(x)                          (((0 | (x)) << PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_LOW_2_LSB) & PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_LOW_2_MASK)
#define PHY_BB_BT_COEX_2_RF_GAIN_DROP_DB_LOW_2_RESET                           0x0
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_HIGH_2_LSB                         10
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_HIGH_2_MSB                         14
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_HIGH_2_MASK                        0x7c00
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_HIGH_2_GET(x)                      (((x) & PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_HIGH_2_MASK) >> PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_HIGH_2_LSB)
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_HIGH_2_SET(x)                      (((0 | (x)) << PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_HIGH_2_LSB) & PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_HIGH_2_MASK)
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_HIGH_2_RESET                       0x0
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_MED_2_LSB                          5
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_MED_2_MSB                          9
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_MED_2_MASK                         0x3e0
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_MED_2_GET(x)                       (((x) & PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_MED_2_MASK) >> PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_MED_2_LSB)
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_MED_2_SET(x)                       (((0 | (x)) << PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_MED_2_LSB) & PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_MED_2_MASK)
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_MED_2_RESET                        0x0
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_LOW_2_LSB                          0
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_LOW_2_MSB                          4
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_LOW_2_MASK                         0x1f
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_LOW_2_GET(x)                       (((x) & PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_LOW_2_MASK) >> PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_LOW_2_LSB)
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_LOW_2_SET(x)                       (((0 | (x)) << PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_LOW_2_LSB) & PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_LOW_2_MASK)
#define PHY_BB_BT_COEX_2_PEAK_DET_TALLY_THR_LOW_2_RESET                        0x0
#define PHY_BB_BT_COEX_2_ADDRESS                                               (0x58 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_BT_COEX_2_RSTMASK                                               0xffffffff
#define PHY_BB_BT_COEX_2_RESET                                                 0x0

// 0x5c (PHY_BB_BT_COEX_3)
#define PHY_BB_BT_COEX_3_BT_RX_FIRPWR_INCR_LSB                                 28
#define PHY_BB_BT_COEX_3_BT_RX_FIRPWR_INCR_MSB                                 31
#define PHY_BB_BT_COEX_3_BT_RX_FIRPWR_INCR_MASK                                0xf0000000
#define PHY_BB_BT_COEX_3_BT_RX_FIRPWR_INCR_GET(x)                              (((x) & PHY_BB_BT_COEX_3_BT_RX_FIRPWR_INCR_MASK) >> PHY_BB_BT_COEX_3_BT_RX_FIRPWR_INCR_LSB)
#define PHY_BB_BT_COEX_3_BT_RX_FIRPWR_INCR_SET(x)                              (((0 | (x)) << PHY_BB_BT_COEX_3_BT_RX_FIRPWR_INCR_LSB) & PHY_BB_BT_COEX_3_BT_RX_FIRPWR_INCR_MASK)
#define PHY_BB_BT_COEX_3_BT_RX_FIRPWR_INCR_RESET                               0x0
#define PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_2_LSB                             23
#define PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_2_MSB                             27
#define PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_2_MASK                            0xf800000
#define PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_2_GET(x)                          (((x) & PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_2_MASK) >> PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_2_LSB)
#define PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_2_SET(x)                          (((0 | (x)) << PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_2_LSB) & PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_2_MASK)
#define PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_2_RESET                           0x0
#define PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_1_LSB                             18
#define PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_1_MSB                             22
#define PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_1_MASK                            0x7c0000
#define PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_1_GET(x)                          (((x) & PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_1_MASK) >> PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_1_LSB)
#define PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_1_SET(x)                          (((0 | (x)) << PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_1_LSB) & PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_1_MASK)
#define PHY_BB_BT_COEX_3_RF_GAIN_DROP_DB_NON_1_RESET                           0x0
#define PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_RX_LSB                                  16
#define PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_RX_MSB                                  17
#define PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_RX_MASK                                 0x30000
#define PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_RX_GET(x)                               (((x) & PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_RX_MASK) >> PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_RX_LSB)
#define PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_RX_SET(x)                               (((0 | (x)) << PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_RX_LSB) & PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_RX_MASK)
#define PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_RX_RESET                                0x0
#define PHY_BB_BT_COEX_3_RFSAT_EQ_RX_SRCH_LSB                                  14
#define PHY_BB_BT_COEX_3_RFSAT_EQ_RX_SRCH_MSB                                  15
#define PHY_BB_BT_COEX_3_RFSAT_EQ_RX_SRCH_MASK                                 0xc000
#define PHY_BB_BT_COEX_3_RFSAT_EQ_RX_SRCH_GET(x)                               (((x) & PHY_BB_BT_COEX_3_RFSAT_EQ_RX_SRCH_MASK) >> PHY_BB_BT_COEX_3_RFSAT_EQ_RX_SRCH_LSB)
#define PHY_BB_BT_COEX_3_RFSAT_EQ_RX_SRCH_SET(x)                               (((0 | (x)) << PHY_BB_BT_COEX_3_RFSAT_EQ_RX_SRCH_LSB) & PHY_BB_BT_COEX_3_RFSAT_EQ_RX_SRCH_MASK)
#define PHY_BB_BT_COEX_3_RFSAT_EQ_RX_SRCH_RESET                                0x0
#define PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_SRCH_LSB                                12
#define PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_SRCH_MSB                                13
#define PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_SRCH_MASK                               0x3000
#define PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_SRCH_GET(x)                             (((x) & PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_SRCH_MASK) >> PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_SRCH_LSB)
#define PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_SRCH_SET(x)                             (((0 | (x)) << PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_SRCH_LSB) & PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_SRCH_MASK)
#define PHY_BB_BT_COEX_3_RFSAT_EQ_SRCH_SRCH_RESET                              0x0
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_RX_LSB                                10
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_RX_MSB                                11
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_RX_MASK                               0xc00
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_RX_GET(x)                             (((x) & PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_RX_MASK) >> PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_RX_LSB)
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_RX_SET(x)                             (((0 | (x)) << PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_RX_LSB) & PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_RX_MASK)
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_RX_RESET                              0x0
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_RX_SRCH_LSB                                8
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_RX_SRCH_MSB                                9
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_RX_SRCH_MASK                               0x300
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_RX_SRCH_GET(x)                             (((x) & PHY_BB_BT_COEX_3_RFSAT_WLAN_RX_SRCH_MASK) >> PHY_BB_BT_COEX_3_RFSAT_WLAN_RX_SRCH_LSB)
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_RX_SRCH_SET(x)                             (((0 | (x)) << PHY_BB_BT_COEX_3_RFSAT_WLAN_RX_SRCH_LSB) & PHY_BB_BT_COEX_3_RFSAT_WLAN_RX_SRCH_MASK)
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_RX_SRCH_RESET                              0x0
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_SRCH_LSB                              6
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_SRCH_MSB                              7
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_SRCH_MASK                             0xc0
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_SRCH_GET(x)                           (((x) & PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_SRCH_MASK) >> PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_SRCH_LSB)
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_SRCH_SET(x)                           (((0 | (x)) << PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_SRCH_LSB) & PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_SRCH_MASK)
#define PHY_BB_BT_COEX_3_RFSAT_WLAN_SRCH_SRCH_RESET                            0x0
#define PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_RX_LSB                                  4
#define PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_RX_MSB                                  5
#define PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_RX_MASK                                 0x30
#define PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_RX_GET(x)                               (((x) & PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_RX_MASK) >> PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_RX_LSB)
#define PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_RX_SET(x)                               (((0 | (x)) << PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_RX_LSB) & PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_RX_MASK)
#define PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_RX_RESET                                0x0
#define PHY_BB_BT_COEX_3_RFSAT_BT_RX_SRCH_LSB                                  2
#define PHY_BB_BT_COEX_3_RFSAT_BT_RX_SRCH_MSB                                  3
#define PHY_BB_BT_COEX_3_RFSAT_BT_RX_SRCH_MASK                                 0xc
#define PHY_BB_BT_COEX_3_RFSAT_BT_RX_SRCH_GET(x)                               (((x) & PHY_BB_BT_COEX_3_RFSAT_BT_RX_SRCH_MASK) >> PHY_BB_BT_COEX_3_RFSAT_BT_RX_SRCH_LSB)
#define PHY_BB_BT_COEX_3_RFSAT_BT_RX_SRCH_SET(x)                               (((0 | (x)) << PHY_BB_BT_COEX_3_RFSAT_BT_RX_SRCH_LSB) & PHY_BB_BT_COEX_3_RFSAT_BT_RX_SRCH_MASK)
#define PHY_BB_BT_COEX_3_RFSAT_BT_RX_SRCH_RESET                                0x0
#define PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_SRCH_LSB                                0
#define PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_SRCH_MSB                                1
#define PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_SRCH_MASK                               0x3
#define PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_SRCH_GET(x)                             (((x) & PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_SRCH_MASK) >> PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_SRCH_LSB)
#define PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_SRCH_SET(x)                             (((0 | (x)) << PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_SRCH_LSB) & PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_SRCH_MASK)
#define PHY_BB_BT_COEX_3_RFSAT_BT_SRCH_SRCH_RESET                              0x0
#define PHY_BB_BT_COEX_3_ADDRESS                                               (0x5c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_BT_COEX_3_RSTMASK                                               0xffffffff
#define PHY_BB_BT_COEX_3_RESET                                                 0x0

// 0x60 (PHY_BB_BT_COEX_4)
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_3_LSB                                  24
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_3_MSB                                  31
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_3_MASK                                 0xff000000
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_3_GET(x)                               (((x) & PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_3_MASK) >> PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_3_LSB)
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_3_SET(x)                               (((0 | (x)) << PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_3_LSB) & PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_3_MASK)
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_3_RESET                                0x0
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_2_LSB                                  16
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_2_MSB                                  23
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_2_MASK                                 0xff0000
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_2_GET(x)                               (((x) & PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_2_MASK) >> PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_2_LSB)
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_2_SET(x)                               (((0 | (x)) << PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_2_LSB) & PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_2_MASK)
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_2_RESET                                0x0
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_1_LSB                                  8
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_1_MSB                                  15
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_1_MASK                                 0xff00
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_1_GET(x)                               (((x) & PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_1_MASK) >> PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_1_LSB)
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_1_SET(x)                               (((0 | (x)) << PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_1_LSB) & PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_1_MASK)
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_1_RESET                                0x0
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_0_LSB                                  0
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_0_MSB                                  7
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_0_MASK                                 0xff
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_0_GET(x)                               (((x) & PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_0_MASK) >> PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_0_LSB)
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_0_SET(x)                               (((0 | (x)) << PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_0_LSB) & PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_0_MASK)
#define PHY_BB_BT_COEX_4_RFGAIN_EQV_LNA_0_RESET                                0x0
#define PHY_BB_BT_COEX_4_ADDRESS                                               (0x60 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_BT_COEX_4_RSTMASK                                               0xffffffff
#define PHY_BB_BT_COEX_4_RESET                                                 0x0

// 0x64 (PHY_BB_BT_COEX_5)
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_7_LSB                                  24
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_7_MSB                                  31
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_7_MASK                                 0xff000000
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_7_GET(x)                               (((x) & PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_7_MASK) >> PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_7_LSB)
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_7_SET(x)                               (((0 | (x)) << PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_7_LSB) & PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_7_MASK)
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_7_RESET                                0x0
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_6_LSB                                  16
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_6_MSB                                  23
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_6_MASK                                 0xff0000
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_6_GET(x)                               (((x) & PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_6_MASK) >> PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_6_LSB)
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_6_SET(x)                               (((0 | (x)) << PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_6_LSB) & PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_6_MASK)
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_6_RESET                                0x0
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_5_LSB                                  8
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_5_MSB                                  15
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_5_MASK                                 0xff00
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_5_GET(x)                               (((x) & PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_5_MASK) >> PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_5_LSB)
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_5_SET(x)                               (((0 | (x)) << PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_5_LSB) & PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_5_MASK)
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_5_RESET                                0x0
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_4_LSB                                  0
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_4_MSB                                  7
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_4_MASK                                 0xff
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_4_GET(x)                               (((x) & PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_4_MASK) >> PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_4_LSB)
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_4_SET(x)                               (((0 | (x)) << PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_4_LSB) & PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_4_MASK)
#define PHY_BB_BT_COEX_5_RFGAIN_EQV_LNA_4_RESET                                0x0
#define PHY_BB_BT_COEX_5_ADDRESS                                               (0x64 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_BT_COEX_5_RSTMASK                                               0xffffffff
#define PHY_BB_BT_COEX_5_RESET                                                 0x0

// 0x68 (PHY_BB_DYN_ADC_SIZE_CTRL)
#define PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MIN_DB2_LSB                  24
#define PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MIN_DB2_MSB                  31
#define PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MIN_DB2_MASK                 0xff000000
#define PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MIN_DB2_GET(x)               (((x) & PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MIN_DB2_MASK) >> PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MIN_DB2_LSB)
#define PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MIN_DB2_SET(x)               (((0 | (x)) << PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MIN_DB2_LSB) & PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MIN_DB2_MASK)
#define PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MIN_DB2_RESET                0xb6
#define PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MAX_DB2_LSB                  16
#define PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MAX_DB2_MSB                  23
#define PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MAX_DB2_MASK                 0xff0000
#define PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MAX_DB2_GET(x)               (((x) & PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MAX_DB2_MASK) >> PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MAX_DB2_LSB)
#define PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MAX_DB2_SET(x)               (((0 | (x)) << PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MAX_DB2_LSB) & PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MAX_DB2_MASK)
#define PHY_BB_DYN_ADC_SIZE_CTRL_ADC_SIZE_DESIRED_MAX_DB2_RESET                0xe2
#define PHY_BB_DYN_ADC_SIZE_CTRL_RSSI_PRI_HIGH_THR_LSB                         8
#define PHY_BB_DYN_ADC_SIZE_CTRL_RSSI_PRI_HIGH_THR_MSB                         14
#define PHY_BB_DYN_ADC_SIZE_CTRL_RSSI_PRI_HIGH_THR_MASK                        0x7f00
#define PHY_BB_DYN_ADC_SIZE_CTRL_RSSI_PRI_HIGH_THR_GET(x)                      (((x) & PHY_BB_DYN_ADC_SIZE_CTRL_RSSI_PRI_HIGH_THR_MASK) >> PHY_BB_DYN_ADC_SIZE_CTRL_RSSI_PRI_HIGH_THR_LSB)
#define PHY_BB_DYN_ADC_SIZE_CTRL_RSSI_PRI_HIGH_THR_SET(x)                      (((0 | (x)) << PHY_BB_DYN_ADC_SIZE_CTRL_RSSI_PRI_HIGH_THR_LSB) & PHY_BB_DYN_ADC_SIZE_CTRL_RSSI_PRI_HIGH_THR_MASK)
#define PHY_BB_DYN_ADC_SIZE_CTRL_RSSI_PRI_HIGH_THR_RESET                       0x25
#define PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RELPWR_LSB                     3
#define PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RELPWR_MSB                     4
#define PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RELPWR_MASK                    0x18
#define PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RELPWR_GET(x)                  (((x) & PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RELPWR_MASK) >> PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RELPWR_LSB)
#define PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RELPWR_SET(x)                  (((0 | (x)) << PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RELPWR_LSB) & PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RELPWR_MASK)
#define PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RELPWR_RESET                   0x0
#define PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RSSI_LSB                       1
#define PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RSSI_MSB                       2
#define PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RSSI_MASK                      0x6
#define PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RSSI_GET(x)                    (((x) & PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RSSI_MASK) >> PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RSSI_LSB)
#define PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RSSI_SET(x)                    (((0 | (x)) << PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RSSI_LSB) & PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RSSI_MASK)
#define PHY_BB_DYN_ADC_SIZE_CTRL_ALPHA_ADC_SIZE_RSSI_RESET                     0x1
#define PHY_BB_DYN_ADC_SIZE_CTRL_ENABLE_DYNAMIC_ADC_SIZING_LSB                 0
#define PHY_BB_DYN_ADC_SIZE_CTRL_ENABLE_DYNAMIC_ADC_SIZING_MSB                 0
#define PHY_BB_DYN_ADC_SIZE_CTRL_ENABLE_DYNAMIC_ADC_SIZING_MASK                0x1
#define PHY_BB_DYN_ADC_SIZE_CTRL_ENABLE_DYNAMIC_ADC_SIZING_GET(x)              (((x) & PHY_BB_DYN_ADC_SIZE_CTRL_ENABLE_DYNAMIC_ADC_SIZING_MASK) >> PHY_BB_DYN_ADC_SIZE_CTRL_ENABLE_DYNAMIC_ADC_SIZING_LSB)
#define PHY_BB_DYN_ADC_SIZE_CTRL_ENABLE_DYNAMIC_ADC_SIZING_SET(x)              (((0 | (x)) << PHY_BB_DYN_ADC_SIZE_CTRL_ENABLE_DYNAMIC_ADC_SIZING_LSB) & PHY_BB_DYN_ADC_SIZE_CTRL_ENABLE_DYNAMIC_ADC_SIZING_MASK)
#define PHY_BB_DYN_ADC_SIZE_CTRL_ENABLE_DYNAMIC_ADC_SIZING_RESET               0x0
#define PHY_BB_DYN_ADC_SIZE_CTRL_ADDRESS                                       (0x68 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DYN_ADC_SIZE_CTRL_RSTMASK                                       0xffff7f1f
#define PHY_BB_DYN_ADC_SIZE_CTRL_RESET                                         0xb6e22502

// 0x6c (PHY_BB_RX_LO_DCCAL_CTRL)
#define PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_TXLB_LSB                                3
#define PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_TXLB_MSB                                5
#define PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_TXLB_MASK                               0x38
#define PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_TXLB_GET(x)                             (((x) & PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_TXLB_MASK) >> PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_TXLB_LSB)
#define PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_TXLB_SET(x)                             (((0 | (x)) << PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_TXLB_LSB) & PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_TXLB_MASK)
#define PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_TXLB_RESET                              0x4
#define PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_RX_LSB                                  0
#define PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_RX_MSB                                  2
#define PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_RX_MASK                                 0x7
#define PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_RX_GET(x)                               (((x) & PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_RX_MASK) >> PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_RX_LSB)
#define PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_RX_SET(x)                               (((0 | (x)) << PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_RX_LSB) & PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_RX_MASK)
#define PHY_BB_RX_LO_DCCAL_CTRL_CALNUM_RX_RESET                                0x4
#define PHY_BB_RX_LO_DCCAL_CTRL_ADDRESS                                        (0x6c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_LO_DCCAL_CTRL_RSTMASK                                        0x3f
#define PHY_BB_RX_LO_DCCAL_CTRL_RESET                                          0x24

// 0x70 (PHY_BB_ADC_CAPTURE)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_CHN_IDX_LSB                             22
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_CHN_IDX_MSB                             23
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_CHN_IDX_MASK                            0xc00000
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_CHN_IDX_GET(x)                          (((x) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_CHN_IDX_MASK) >> PHY_BB_ADC_CAPTURE_ADC_CAPTURE_CHN_IDX_LSB)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_CHN_IDX_SET(x)                          (((0 | (x)) << PHY_BB_ADC_CAPTURE_ADC_CAPTURE_CHN_IDX_LSB) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_CHN_IDX_MASK)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_CHN_IDX_RESET                           0x0
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_LENGTH_LSB                              8
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_LENGTH_MSB                              21
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_LENGTH_MASK                             0x3fff00
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_LENGTH_GET(x)                           (((x) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_LENGTH_MASK) >> PHY_BB_ADC_CAPTURE_ADC_CAPTURE_LENGTH_LSB)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_LENGTH_SET(x)                           (((0 | (x)) << PHY_BB_ADC_CAPTURE_ADC_CAPTURE_LENGTH_LSB) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_LENGTH_MASK)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_LENGTH_RESET                            0x800
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SCALE_LSB                               6
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SCALE_MSB                               7
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SCALE_MASK                              0xc0
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SCALE_GET(x)                            (((x) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SCALE_MASK) >> PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SCALE_LSB)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SCALE_SET(x)                            (((0 | (x)) << PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SCALE_LSB) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SCALE_MASK)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SCALE_RESET                             0x0
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_GC_ENA_LSB                              5
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_GC_ENA_MSB                              5
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_GC_ENA_MASK                             0x20
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_GC_ENA_GET(x)                           (((x) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_GC_ENA_MASK) >> PHY_BB_ADC_CAPTURE_ADC_CAPTURE_GC_ENA_LSB)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_GC_ENA_SET(x)                           (((0 | (x)) << PHY_BB_ADC_CAPTURE_ADC_CAPTURE_GC_ENA_LSB) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_GC_ENA_MASK)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_GC_ENA_RESET                            0x1
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_FORMAT_LSB                              4
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_FORMAT_MSB                              4
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_FORMAT_MASK                             0x10
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_FORMAT_GET(x)                           (((x) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_FORMAT_MASK) >> PHY_BB_ADC_CAPTURE_ADC_CAPTURE_FORMAT_LSB)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_FORMAT_SET(x)                           (((0 | (x)) << PHY_BB_ADC_CAPTURE_ADC_CAPTURE_FORMAT_LSB) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_FORMAT_MASK)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_FORMAT_RESET                            0x0
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_OVERRUN_FLAG_LSB                        3
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_OVERRUN_FLAG_MSB                        3
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_OVERRUN_FLAG_MASK                       0x8
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_OVERRUN_FLAG_GET(x)                     (((x) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_OVERRUN_FLAG_MASK) >> PHY_BB_ADC_CAPTURE_ADC_CAPTURE_OVERRUN_FLAG_LSB)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_OVERRUN_FLAG_SET(x)                     (((0 | (x)) << PHY_BB_ADC_CAPTURE_ADC_CAPTURE_OVERRUN_FLAG_LSB) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_OVERRUN_FLAG_MASK)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_OVERRUN_FLAG_RESET                      0x0
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SAT_FLAG_LSB                            2
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SAT_FLAG_MSB                            2
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SAT_FLAG_MASK                           0x4
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SAT_FLAG_GET(x)                         (((x) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SAT_FLAG_MASK) >> PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SAT_FLAG_LSB)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SAT_FLAG_SET(x)                         (((0 | (x)) << PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SAT_FLAG_LSB) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SAT_FLAG_MASK)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_SAT_FLAG_RESET                          0x0
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ERROR_FLAG_LSB                          1
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ERROR_FLAG_MSB                          1
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ERROR_FLAG_MASK                         0x2
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ERROR_FLAG_GET(x)                       (((x) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ERROR_FLAG_MASK) >> PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ERROR_FLAG_LSB)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ERROR_FLAG_SET(x)                       (((0 | (x)) << PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ERROR_FLAG_LSB) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ERROR_FLAG_MASK)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ERROR_FLAG_RESET                        0x0
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ACTIVE_LSB                              0
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ACTIVE_MSB                              0
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ACTIVE_MASK                             0x1
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ACTIVE_GET(x)                           (((x) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ACTIVE_MASK) >> PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ACTIVE_LSB)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ACTIVE_SET(x)                           (((0 | (x)) << PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ACTIVE_LSB) & PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ACTIVE_MASK)
#define PHY_BB_ADC_CAPTURE_ADC_CAPTURE_ACTIVE_RESET                            0x0
#define PHY_BB_ADC_CAPTURE_ADDRESS                                             (0x70 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_ADC_CAPTURE_RSTMASK                                             0xffffff
#define PHY_BB_ADC_CAPTURE_RESET                                               0x80020

// 0x74 (PHY_BB_FIND_SIGNAL_2)
#define PHY_BB_FIND_SIGNAL_2_RSSI_THR1B_LSB                                    25
#define PHY_BB_FIND_SIGNAL_2_RSSI_THR1B_MSB                                    31
#define PHY_BB_FIND_SIGNAL_2_RSSI_THR1B_MASK                                   0xfe000000
#define PHY_BB_FIND_SIGNAL_2_RSSI_THR1B_GET(x)                                 (((x) & PHY_BB_FIND_SIGNAL_2_RSSI_THR1B_MASK) >> PHY_BB_FIND_SIGNAL_2_RSSI_THR1B_LSB)
#define PHY_BB_FIND_SIGNAL_2_RSSI_THR1B_SET(x)                                 (((0 | (x)) << PHY_BB_FIND_SIGNAL_2_RSSI_THR1B_LSB) & PHY_BB_FIND_SIGNAL_2_RSSI_THR1B_MASK)
#define PHY_BB_FIND_SIGNAL_2_RSSI_THR1B_RESET                                  0x0
#define PHY_BB_FIND_SIGNAL_2_ENABLE_RSSI_THR1B_LSB                             24
#define PHY_BB_FIND_SIGNAL_2_ENABLE_RSSI_THR1B_MSB                             24
#define PHY_BB_FIND_SIGNAL_2_ENABLE_RSSI_THR1B_MASK                            0x1000000
#define PHY_BB_FIND_SIGNAL_2_ENABLE_RSSI_THR1B_GET(x)                          (((x) & PHY_BB_FIND_SIGNAL_2_ENABLE_RSSI_THR1B_MASK) >> PHY_BB_FIND_SIGNAL_2_ENABLE_RSSI_THR1B_LSB)
#define PHY_BB_FIND_SIGNAL_2_ENABLE_RSSI_THR1B_SET(x)                          (((0 | (x)) << PHY_BB_FIND_SIGNAL_2_ENABLE_RSSI_THR1B_LSB) & PHY_BB_FIND_SIGNAL_2_ENABLE_RSSI_THR1B_MASK)
#define PHY_BB_FIND_SIGNAL_2_ENABLE_RSSI_THR1B_RESET                           0x0
#define PHY_BB_FIND_SIGNAL_2_AGCSM_SKIP_CAL_AFTER_RESET_LSB                    17
#define PHY_BB_FIND_SIGNAL_2_AGCSM_SKIP_CAL_AFTER_RESET_MSB                    17
#define PHY_BB_FIND_SIGNAL_2_AGCSM_SKIP_CAL_AFTER_RESET_MASK                   0x20000
#define PHY_BB_FIND_SIGNAL_2_AGCSM_SKIP_CAL_AFTER_RESET_GET(x)                 (((x) & PHY_BB_FIND_SIGNAL_2_AGCSM_SKIP_CAL_AFTER_RESET_MASK) >> PHY_BB_FIND_SIGNAL_2_AGCSM_SKIP_CAL_AFTER_RESET_LSB)
#define PHY_BB_FIND_SIGNAL_2_AGCSM_SKIP_CAL_AFTER_RESET_SET(x)                 (((0 | (x)) << PHY_BB_FIND_SIGNAL_2_AGCSM_SKIP_CAL_AFTER_RESET_LSB) & PHY_BB_FIND_SIGNAL_2_AGCSM_SKIP_CAL_AFTER_RESET_MASK)
#define PHY_BB_FIND_SIGNAL_2_AGCSM_SKIP_CAL_AFTER_RESET_RESET                  0x0
#define PHY_BB_FIND_SIGNAL_2_DISABLE_PWR_DROP_LAST_TWO_SYM_VHT_LSB             16
#define PHY_BB_FIND_SIGNAL_2_DISABLE_PWR_DROP_LAST_TWO_SYM_VHT_MSB             16
#define PHY_BB_FIND_SIGNAL_2_DISABLE_PWR_DROP_LAST_TWO_SYM_VHT_MASK            0x10000
#define PHY_BB_FIND_SIGNAL_2_DISABLE_PWR_DROP_LAST_TWO_SYM_VHT_GET(x)          (((x) & PHY_BB_FIND_SIGNAL_2_DISABLE_PWR_DROP_LAST_TWO_SYM_VHT_MASK) >> PHY_BB_FIND_SIGNAL_2_DISABLE_PWR_DROP_LAST_TWO_SYM_VHT_LSB)
#define PHY_BB_FIND_SIGNAL_2_DISABLE_PWR_DROP_LAST_TWO_SYM_VHT_SET(x)          (((0 | (x)) << PHY_BB_FIND_SIGNAL_2_DISABLE_PWR_DROP_LAST_TWO_SYM_VHT_LSB) & PHY_BB_FIND_SIGNAL_2_DISABLE_PWR_DROP_LAST_TWO_SYM_VHT_MASK)
#define PHY_BB_FIND_SIGNAL_2_DISABLE_PWR_DROP_LAST_TWO_SYM_VHT_RESET           0x0
#define PHY_BB_FIND_SIGNAL_2_FOUND_LOW_LSB                                     8
#define PHY_BB_FIND_SIGNAL_2_FOUND_LOW_MSB                                     15
#define PHY_BB_FIND_SIGNAL_2_FOUND_LOW_MASK                                    0xff00
#define PHY_BB_FIND_SIGNAL_2_FOUND_LOW_GET(x)                                  (((x) & PHY_BB_FIND_SIGNAL_2_FOUND_LOW_MASK) >> PHY_BB_FIND_SIGNAL_2_FOUND_LOW_LSB)
#define PHY_BB_FIND_SIGNAL_2_FOUND_LOW_SET(x)                                  (((0 | (x)) << PHY_BB_FIND_SIGNAL_2_FOUND_LOW_LSB) & PHY_BB_FIND_SIGNAL_2_FOUND_LOW_MASK)
#define PHY_BB_FIND_SIGNAL_2_FOUND_LOW_RESET                                   0xc4
#define PHY_BB_FIND_SIGNAL_2_FOUND_LOW_ENA_LSB                                 7
#define PHY_BB_FIND_SIGNAL_2_FOUND_LOW_ENA_MSB                                 7
#define PHY_BB_FIND_SIGNAL_2_FOUND_LOW_ENA_MASK                                0x80
#define PHY_BB_FIND_SIGNAL_2_FOUND_LOW_ENA_GET(x)                              (((x) & PHY_BB_FIND_SIGNAL_2_FOUND_LOW_ENA_MASK) >> PHY_BB_FIND_SIGNAL_2_FOUND_LOW_ENA_LSB)
#define PHY_BB_FIND_SIGNAL_2_FOUND_LOW_ENA_SET(x)                              (((0 | (x)) << PHY_BB_FIND_SIGNAL_2_FOUND_LOW_ENA_LSB) & PHY_BB_FIND_SIGNAL_2_FOUND_LOW_ENA_MASK)
#define PHY_BB_FIND_SIGNAL_2_FOUND_LOW_ENA_RESET                               0x1
#define PHY_BB_FIND_SIGNAL_2_RELPWR_WEAK_DB_LSB                                0
#define PHY_BB_FIND_SIGNAL_2_RELPWR_WEAK_DB_MSB                                5
#define PHY_BB_FIND_SIGNAL_2_RELPWR_WEAK_DB_MASK                               0x3f
#define PHY_BB_FIND_SIGNAL_2_RELPWR_WEAK_DB_GET(x)                             (((x) & PHY_BB_FIND_SIGNAL_2_RELPWR_WEAK_DB_MASK) >> PHY_BB_FIND_SIGNAL_2_RELPWR_WEAK_DB_LSB)
#define PHY_BB_FIND_SIGNAL_2_RELPWR_WEAK_DB_SET(x)                             (((0 | (x)) << PHY_BB_FIND_SIGNAL_2_RELPWR_WEAK_DB_LSB) & PHY_BB_FIND_SIGNAL_2_RELPWR_WEAK_DB_MASK)
#define PHY_BB_FIND_SIGNAL_2_RELPWR_WEAK_DB_RESET                              0x2c
#define PHY_BB_FIND_SIGNAL_2_ADDRESS                                           (0x74 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_FIND_SIGNAL_2_RSTMASK                                           0xff03ffbf
#define PHY_BB_FIND_SIGNAL_2_RESET                                             0xc4ac

// 0x78 (PHY_BB_PEAK_DET_CTRL_3)
#define PHY_BB_PEAK_DET_CTRL_3_FIRST_RFSAT_GAIN_INCREASE_LSB                   30
#define PHY_BB_PEAK_DET_CTRL_3_FIRST_RFSAT_GAIN_INCREASE_MSB                   30
#define PHY_BB_PEAK_DET_CTRL_3_FIRST_RFSAT_GAIN_INCREASE_MASK                  0x40000000
#define PHY_BB_PEAK_DET_CTRL_3_FIRST_RFSAT_GAIN_INCREASE_GET(x)                (((x) & PHY_BB_PEAK_DET_CTRL_3_FIRST_RFSAT_GAIN_INCREASE_MASK) >> PHY_BB_PEAK_DET_CTRL_3_FIRST_RFSAT_GAIN_INCREASE_LSB)
#define PHY_BB_PEAK_DET_CTRL_3_FIRST_RFSAT_GAIN_INCREASE_SET(x)                (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_3_FIRST_RFSAT_GAIN_INCREASE_LSB) & PHY_BB_PEAK_DET_CTRL_3_FIRST_RFSAT_GAIN_INCREASE_MASK)
#define PHY_BB_PEAK_DET_CTRL_3_FIRST_RFSAT_GAIN_INCREASE_RESET                 0x1
#define PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_DB_LSB                            25
#define PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_DB_MSB                            29
#define PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_DB_MASK                           0x3e000000
#define PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_DB_GET(x)                         (((x) & PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_DB_MASK) >> PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_DB_LSB)
#define PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_DB_SET(x)                         (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_DB_LSB) & PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_DB_MASK)
#define PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_DB_RESET                          0xf
#define PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_ENA_LSB                           24
#define PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_ENA_MSB                           24
#define PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_ENA_MASK                          0x1000000
#define PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_ENA_GET(x)                        (((x) & PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_ENA_MASK) >> PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_ENA_LSB)
#define PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_ENA_SET(x)                        (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_ENA_LSB) & PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_ENA_MASK)
#define PHY_BB_PEAK_DET_CTRL_3_XRF_GAIN_DROP_ENA_RESET                         0x1
#define PHY_BB_PEAK_DET_CTRL_3_USE_COMMON_RF_GAIN_DROP_LSB                     23
#define PHY_BB_PEAK_DET_CTRL_3_USE_COMMON_RF_GAIN_DROP_MSB                     23
#define PHY_BB_PEAK_DET_CTRL_3_USE_COMMON_RF_GAIN_DROP_MASK                    0x800000
#define PHY_BB_PEAK_DET_CTRL_3_USE_COMMON_RF_GAIN_DROP_GET(x)                  (((x) & PHY_BB_PEAK_DET_CTRL_3_USE_COMMON_RF_GAIN_DROP_MASK) >> PHY_BB_PEAK_DET_CTRL_3_USE_COMMON_RF_GAIN_DROP_LSB)
#define PHY_BB_PEAK_DET_CTRL_3_USE_COMMON_RF_GAIN_DROP_SET(x)                  (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_3_USE_COMMON_RF_GAIN_DROP_LSB) & PHY_BB_PEAK_DET_CTRL_3_USE_COMMON_RF_GAIN_DROP_MASK)
#define PHY_BB_PEAK_DET_CTRL_3_USE_COMMON_RF_GAIN_DROP_RESET                   0x1
#define PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_THR_LSB                           21
#define PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_THR_MSB                           22
#define PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_THR_MASK                          0x600000
#define PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_THR_GET(x)                        (((x) & PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_THR_MASK) >> PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_THR_LSB)
#define PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_THR_SET(x)                        (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_THR_LSB) & PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_THR_MASK)
#define PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_THR_RESET                         0x0
#define PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_ENA_LSB                           20
#define PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_ENA_MSB                           20
#define PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_ENA_MASK                          0x100000
#define PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_ENA_GET(x)                        (((x) & PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_ENA_MASK) >> PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_ENA_LSB)
#define PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_ENA_SET(x)                        (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_ENA_LSB) & PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_ENA_MASK)
#define PHY_BB_PEAK_DET_CTRL_3_PEAK_DET_4WIN_ENA_RESET                         0x1
#define PHY_BB_PEAK_DET_CTRL_3_RFSAT_2_ADD_RFGAIN_DEL_LSB                      4
#define PHY_BB_PEAK_DET_CTRL_3_RFSAT_2_ADD_RFGAIN_DEL_MSB                      19
#define PHY_BB_PEAK_DET_CTRL_3_RFSAT_2_ADD_RFGAIN_DEL_MASK                     0xffff0
#define PHY_BB_PEAK_DET_CTRL_3_RFSAT_2_ADD_RFGAIN_DEL_GET(x)                   (((x) & PHY_BB_PEAK_DET_CTRL_3_RFSAT_2_ADD_RFGAIN_DEL_MASK) >> PHY_BB_PEAK_DET_CTRL_3_RFSAT_2_ADD_RFGAIN_DEL_LSB)
#define PHY_BB_PEAK_DET_CTRL_3_RFSAT_2_ADD_RFGAIN_DEL_SET(x)                   (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_3_RFSAT_2_ADD_RFGAIN_DEL_LSB) & PHY_BB_PEAK_DET_CTRL_3_RFSAT_2_ADD_RFGAIN_DEL_MASK)
#define PHY_BB_PEAK_DET_CTRL_3_RFSAT_2_ADD_RFGAIN_DEL_RESET                    0x20
#define PHY_BB_PEAK_DET_CTRL_3_AGC_DBDAC_REG_SETTING_LSB                       0
#define PHY_BB_PEAK_DET_CTRL_3_AGC_DBDAC_REG_SETTING_MSB                       3
#define PHY_BB_PEAK_DET_CTRL_3_AGC_DBDAC_REG_SETTING_MASK                      0xf
#define PHY_BB_PEAK_DET_CTRL_3_AGC_DBDAC_REG_SETTING_GET(x)                    (((x) & PHY_BB_PEAK_DET_CTRL_3_AGC_DBDAC_REG_SETTING_MASK) >> PHY_BB_PEAK_DET_CTRL_3_AGC_DBDAC_REG_SETTING_LSB)
#define PHY_BB_PEAK_DET_CTRL_3_AGC_DBDAC_REG_SETTING_SET(x)                    (((0 | (x)) << PHY_BB_PEAK_DET_CTRL_3_AGC_DBDAC_REG_SETTING_LSB) & PHY_BB_PEAK_DET_CTRL_3_AGC_DBDAC_REG_SETTING_MASK)
#define PHY_BB_PEAK_DET_CTRL_3_AGC_DBDAC_REG_SETTING_RESET                     0x0
#define PHY_BB_PEAK_DET_CTRL_3_ADDRESS                                         (0x78 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_PEAK_DET_CTRL_3_RSTMASK                                         0x7fffffff
#define PHY_BB_PEAK_DET_CTRL_3_RESET                                           0x5f900200

// 0x7c (PHY_BB_FIND_SIGNAL2)
#define PHY_BB_FIND_SIGNAL2_RELPWR_LSB                                         0
#define PHY_BB_FIND_SIGNAL2_RELPWR_MSB                                         6
#define PHY_BB_FIND_SIGNAL2_RELPWR_MASK                                        0x7f
#define PHY_BB_FIND_SIGNAL2_RELPWR_GET(x)                                      (((x) & PHY_BB_FIND_SIGNAL2_RELPWR_MASK) >> PHY_BB_FIND_SIGNAL2_RELPWR_LSB)
#define PHY_BB_FIND_SIGNAL2_RELPWR_SET(x)                                      (((0 | (x)) << PHY_BB_FIND_SIGNAL2_RELPWR_LSB) & PHY_BB_FIND_SIGNAL2_RELPWR_MASK)
#define PHY_BB_FIND_SIGNAL2_RELPWR_RESET                                       0x24
#define PHY_BB_FIND_SIGNAL2_ADDRESS                                            (0x7c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_FIND_SIGNAL2_RSTMASK                                            0x7f
#define PHY_BB_FIND_SIGNAL2_RESET                                              0x24

// 0x80 (PHY_BB_SRCH_FFT_CTRL_1)
#define PHY_BB_SRCH_FFT_CTRL_1_PULSE_CHECK_SRCH_FFT_LSB                        31
#define PHY_BB_SRCH_FFT_CTRL_1_PULSE_CHECK_SRCH_FFT_MSB                        31
#define PHY_BB_SRCH_FFT_CTRL_1_PULSE_CHECK_SRCH_FFT_MASK                       0x80000000
#define PHY_BB_SRCH_FFT_CTRL_1_PULSE_CHECK_SRCH_FFT_GET(x)                     (((x) & PHY_BB_SRCH_FFT_CTRL_1_PULSE_CHECK_SRCH_FFT_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_PULSE_CHECK_SRCH_FFT_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_PULSE_CHECK_SRCH_FFT_SET(x)                     (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_PULSE_CHECK_SRCH_FFT_LSB) & PHY_BB_SRCH_FFT_CTRL_1_PULSE_CHECK_SRCH_FFT_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_PULSE_CHECK_SRCH_FFT_RESET                      0x0
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_DBM_ADJ_LSB                       30
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_DBM_ADJ_MSB                       30
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_DBM_ADJ_MASK                      0x40000000
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_DBM_ADJ_GET(x)                    (((x) & PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_DBM_ADJ_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_DBM_ADJ_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_DBM_ADJ_SET(x)                    (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_DBM_ADJ_LSB) & PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_DBM_ADJ_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_DBM_ADJ_RESET                     0x1
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_DBM_ADJ_LSB                           29
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_DBM_ADJ_MSB                           29
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_DBM_ADJ_MASK                          0x20000000
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_DBM_ADJ_GET(x)                        (((x) & PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_DBM_ADJ_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_DBM_ADJ_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_DBM_ADJ_SET(x)                        (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_DBM_ADJ_LSB) & PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_DBM_ADJ_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_DBM_ADJ_RESET                         0x0
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_FINE_ENA_LSB                          28
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_FINE_ENA_MSB                          28
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_FINE_ENA_MASK                         0x10000000
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_FINE_ENA_GET(x)                       (((x) & PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_FINE_ENA_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_FINE_ENA_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_FINE_ENA_SET(x)                       (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_FINE_ENA_LSB) & PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_FINE_ENA_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_FINE_ENA_RESET                        0x0
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_LONG_PERIOD_LSB                       24
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_LONG_PERIOD_MSB                       27
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_LONG_PERIOD_MASK                      0xf000000
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_LONG_PERIOD_GET(x)                    (((x) & PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_LONG_PERIOD_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_LONG_PERIOD_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_LONG_PERIOD_SET(x)                    (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_LONG_PERIOD_LSB) & PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_LONG_PERIOD_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_LONG_PERIOD_RESET                     0x8
#define PHY_BB_SRCH_FFT_CTRL_1_SRCH_FFT_SCALE_VEC_LSB                          12
#define PHY_BB_SRCH_FFT_CTRL_1_SRCH_FFT_SCALE_VEC_MSB                          23
#define PHY_BB_SRCH_FFT_CTRL_1_SRCH_FFT_SCALE_VEC_MASK                         0xfff000
#define PHY_BB_SRCH_FFT_CTRL_1_SRCH_FFT_SCALE_VEC_GET(x)                       (((x) & PHY_BB_SRCH_FFT_CTRL_1_SRCH_FFT_SCALE_VEC_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_SRCH_FFT_SCALE_VEC_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_SRCH_FFT_SCALE_VEC_SET(x)                       (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_SRCH_FFT_SCALE_VEC_LSB) & PHY_BB_SRCH_FFT_CTRL_1_SRCH_FFT_SCALE_VEC_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_SRCH_FFT_SCALE_VEC_RESET                        0xfff
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_BIN_SCALE_LSB                     10
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_BIN_SCALE_MSB                     11
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_BIN_SCALE_MASK                    0xc00
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_BIN_SCALE_GET(x)                  (((x) & PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_BIN_SCALE_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_BIN_SCALE_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_BIN_SCALE_SET(x)                  (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_BIN_SCALE_LSB) & PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_BIN_SCALE_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_BIN_SCALE_RESET                   0x0
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_BIN_SCALE_LSB                         8
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_BIN_SCALE_MSB                         9
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_BIN_SCALE_MASK                        0x300
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_BIN_SCALE_GET(x)                      (((x) & PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_BIN_SCALE_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_BIN_SCALE_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_BIN_SCALE_SET(x)                      (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_BIN_SCALE_LSB) & PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_BIN_SCALE_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_BIN_SCALE_RESET                       0x0
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_RPT_MODE_LSB                      6
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_RPT_MODE_MSB                      7
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_RPT_MODE_MASK                     0xc0
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_RPT_MODE_GET(x)                   (((x) & PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_RPT_MODE_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_RPT_MODE_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_RPT_MODE_SET(x)                   (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_RPT_MODE_LSB) & PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_RPT_MODE_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_RPT_MODE_RESET                    0x2
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_RPT_MODE_LSB                          4
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_RPT_MODE_MSB                          5
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_RPT_MODE_MASK                         0x30
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_RPT_MODE_GET(x)                       (((x) & PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_RPT_MODE_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_RPT_MODE_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_RPT_MODE_SET(x)                       (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_RPT_MODE_LSB) & PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_RPT_MODE_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_RPT_MODE_RESET                        0x1
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_PWR_FORMAT_LSB                    3
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_PWR_FORMAT_MSB                    3
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_PWR_FORMAT_MASK                   0x8
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_PWR_FORMAT_GET(x)                 (((x) & PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_PWR_FORMAT_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_PWR_FORMAT_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_PWR_FORMAT_SET(x)                 (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_PWR_FORMAT_LSB) & PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_PWR_FORMAT_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_SPECTRAL_SCAN_PWR_FORMAT_RESET                  0x1
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_PWR_FORMAT_LSB                        2
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_PWR_FORMAT_MSB                        2
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_PWR_FORMAT_MASK                       0x4
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_PWR_FORMAT_GET(x)                     (((x) & PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_PWR_FORMAT_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_PWR_FORMAT_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_PWR_FORMAT_SET(x)                     (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_PWR_FORMAT_LSB) & PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_PWR_FORMAT_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_RADAR_FFT_PWR_FORMAT_RESET                      0x1
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_RADAR_ENA_LSB                         1
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_RADAR_ENA_MSB                         1
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_RADAR_ENA_MASK                        0x2
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_RADAR_ENA_GET(x)                      (((x) & PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_RADAR_ENA_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_RADAR_ENA_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_RADAR_ENA_SET(x)                      (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_RADAR_ENA_LSB) & PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_RADAR_ENA_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_RADAR_ENA_RESET                       0x0
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_WLAN_ENA_LSB                          0
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_WLAN_ENA_MSB                          0
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_WLAN_ENA_MASK                         0x1
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_WLAN_ENA_GET(x)                       (((x) & PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_WLAN_ENA_MASK) >> PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_WLAN_ENA_LSB)
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_WLAN_ENA_SET(x)                       (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_WLAN_ENA_LSB) & PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_WLAN_ENA_MASK)
#define PHY_BB_SRCH_FFT_CTRL_1_FFT_CHECK_WLAN_ENA_RESET                        0x0
#define PHY_BB_SRCH_FFT_CTRL_1_ADDRESS                                         (0x80 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SRCH_FFT_CTRL_1_RSTMASK                                         0xffffffff
#define PHY_BB_SRCH_FFT_CTRL_1_RESET                                           0x48fff09c

// 0x84 (PHY_BB_SRCH_FFT_CTRL_2)
#define PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_RADAR_LSB                           26
#define PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_RADAR_MSB                           31
#define PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_RADAR_MASK                          0xfc000000
#define PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_RADAR_GET(x)                        (((x) & PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_RADAR_MASK) >> PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_RADAR_LSB)
#define PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_RADAR_SET(x)                        (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_RADAR_LSB) & PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_RADAR_MASK)
#define PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_RADAR_RESET                         0x8
#define PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_WLAN_LSB                            20
#define PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_WLAN_MSB                            25
#define PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_WLAN_MASK                           0x3f00000
#define PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_WLAN_GET(x)                         (((x) & PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_WLAN_MASK) >> PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_WLAN_LSB)
#define PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_WLAN_SET(x)                         (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_WLAN_LSB) & PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_WLAN_MASK)
#define PHY_BB_SRCH_FFT_CTRL_2_STR_BIN_THR_WLAN_RESET                          0xc
#define PHY_BB_SRCH_FFT_CTRL_2_RADAR_FFT_BW_PRIORITY_LSB                       19
#define PHY_BB_SRCH_FFT_CTRL_2_RADAR_FFT_BW_PRIORITY_MSB                       19
#define PHY_BB_SRCH_FFT_CTRL_2_RADAR_FFT_BW_PRIORITY_MASK                      0x80000
#define PHY_BB_SRCH_FFT_CTRL_2_RADAR_FFT_BW_PRIORITY_GET(x)                    (((x) & PHY_BB_SRCH_FFT_CTRL_2_RADAR_FFT_BW_PRIORITY_MASK) >> PHY_BB_SRCH_FFT_CTRL_2_RADAR_FFT_BW_PRIORITY_LSB)
#define PHY_BB_SRCH_FFT_CTRL_2_RADAR_FFT_BW_PRIORITY_SET(x)                    (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_2_RADAR_FFT_BW_PRIORITY_LSB) & PHY_BB_SRCH_FFT_CTRL_2_RADAR_FFT_BW_PRIORITY_MASK)
#define PHY_BB_SRCH_FFT_CTRL_2_RADAR_FFT_BW_PRIORITY_RESET                     0x0
#define PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_IB_THR_LSB                             12
#define PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_IB_THR_MSB                             18
#define PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_IB_THR_MASK                            0x7f000
#define PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_IB_THR_GET(x)                          (((x) & PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_IB_THR_MASK) >> PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_IB_THR_LSB)
#define PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_IB_THR_SET(x)                          (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_IB_THR_LSB) & PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_IB_THR_MASK)
#define PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_IB_THR_RESET                           0x0
#define PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_SB_FREQ_LSB                            0
#define PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_SB_FREQ_MSB                            11
#define PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_SB_FREQ_MASK                           0xfff
#define PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_SB_FREQ_GET(x)                         (((x) & PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_SB_FREQ_MASK) >> PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_SB_FREQ_LSB)
#define PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_SB_FREQ_SET(x)                         (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_SB_FREQ_LSB) & PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_SB_FREQ_MASK)
#define PHY_BB_SRCH_FFT_CTRL_2_SRCH_FFT_SB_FREQ_RESET                          0x3a3
#define PHY_BB_SRCH_FFT_CTRL_2_ADDRESS                                         (0x84 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SRCH_FFT_CTRL_2_RSTMASK                                         0xffffffff
#define PHY_BB_SRCH_FFT_CTRL_2_RESET                                           0x20c003a3

// 0x88 (PHY_BB_SRCH_FFT_CTRL_3)
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_BLK_LSB                       24
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_BLK_MSB                       31
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_BLK_MASK                      0xff000000
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_BLK_GET(x)                    (((x) & PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_BLK_MASK) >> PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_BLK_LSB)
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_BLK_SET(x)                    (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_BLK_LSB) & PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_BLK_MASK)
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_BLK_RESET                     0x14
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_FINE_LSB                      16
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_FINE_MSB                      23
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_FINE_MASK                     0xff0000
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_FINE_GET(x)                   (((x) & PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_FINE_MASK) >> PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_FINE_LSB)
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_FINE_SET(x)                   (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_FINE_LSB) & PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_FINE_MASK)
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_FINE_RESET                    0x8
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_COARSE_LSB                    8
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_COARSE_MSB                    15
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_COARSE_MASK                   0xff00
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_COARSE_GET(x)                 (((x) & PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_COARSE_MASK) >> PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_COARSE_LSB)
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_COARSE_SET(x)                 (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_COARSE_LSB) & PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_COARSE_MASK)
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_RADAR_COARSE_RESET                  0xc
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_WLAN_LSB                            0
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_WLAN_MSB                            7
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_WLAN_MASK                           0xff
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_WLAN_GET(x)                         (((x) & PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_WLAN_MASK) >> PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_WLAN_LSB)
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_WLAN_SET(x)                         (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_WLAN_LSB) & PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_WLAN_MASK)
#define PHY_BB_SRCH_FFT_CTRL_3_NB_TONE_THR_WLAN_RESET                          0x14
#define PHY_BB_SRCH_FFT_CTRL_3_ADDRESS                                         (0x88 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SRCH_FFT_CTRL_3_RSTMASK                                         0xffffffff
#define PHY_BB_SRCH_FFT_CTRL_3_RESET                                           0x14080c14

// 0x8c (PHY_BB_SRCH_FFT_CTRL_4)
#define PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_SHORT_RPT_SEL_LSB                     31
#define PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_SHORT_RPT_SEL_MSB                     31
#define PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_SHORT_RPT_SEL_MASK                    0x80000000
#define PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_SHORT_RPT_SEL_GET(x)                  (((x) & PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_SHORT_RPT_SEL_MASK) >> PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_SHORT_RPT_SEL_LSB)
#define PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_SHORT_RPT_SEL_SET(x)                  (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_SHORT_RPT_SEL_LSB) & PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_SHORT_RPT_SEL_MASK)
#define PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_SHORT_RPT_SEL_RESET                   0x0
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_DC_SCALE_INBAND_LSB                    28
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_DC_SCALE_INBAND_MSB                    30
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_DC_SCALE_INBAND_MASK                   0x70000000
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_DC_SCALE_INBAND_GET(x)                 (((x) & PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_DC_SCALE_INBAND_MASK) >> PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_DC_SCALE_INBAND_LSB)
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_DC_SCALE_INBAND_SET(x)                 (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_DC_SCALE_INBAND_LSB) & PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_DC_SCALE_INBAND_MASK)
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_DC_SCALE_INBAND_RESET                  0x2
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_DROP_RATIO_LSB                     24
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_DROP_RATIO_MSB                     27
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_DROP_RATIO_MASK                    0xf000000
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_DROP_RATIO_GET(x)                  (((x) & PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_DROP_RATIO_MASK) >> PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_DROP_RATIO_LSB)
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_DROP_RATIO_SET(x)                  (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_DROP_RATIO_LSB) & PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_DROP_RATIO_MASK)
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_DROP_RATIO_RESET                   0x3
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_LOW_CAP_LSB                        18
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_LOW_CAP_MSB                        23
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_LOW_CAP_MASK                       0xfc0000
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_LOW_CAP_GET(x)                     (((x) & PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_LOW_CAP_MASK) >> PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_LOW_CAP_LSB)
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_LOW_CAP_SET(x)                     (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_LOW_CAP_LSB) & PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_LOW_CAP_MASK)
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_PWR_LOW_CAP_RESET                      0x19
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_RFSAT_PEAKMAG_THR_LSB                  8
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_RFSAT_PEAKMAG_THR_MSB                  17
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_RFSAT_PEAKMAG_THR_MASK                 0x3ff00
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_RFSAT_PEAKMAG_THR_GET(x)               (((x) & PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_RFSAT_PEAKMAG_THR_MASK) >> PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_RFSAT_PEAKMAG_THR_LSB)
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_RFSAT_PEAKMAG_THR_SET(x)               (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_RFSAT_PEAKMAG_THR_LSB) & PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_RFSAT_PEAKMAG_THR_MASK)
#define PHY_BB_SRCH_FFT_CTRL_4_SRCH_FFT_RFSAT_PEAKMAG_THR_RESET                0xff
#define PHY_BB_SRCH_FFT_CTRL_4_SPECTRAL_SCAN_CHN_MASK_LSB                      4
#define PHY_BB_SRCH_FFT_CTRL_4_SPECTRAL_SCAN_CHN_MASK_MSB                      7
#define PHY_BB_SRCH_FFT_CTRL_4_SPECTRAL_SCAN_CHN_MASK_MASK                     0xf0
#define PHY_BB_SRCH_FFT_CTRL_4_SPECTRAL_SCAN_CHN_MASK_GET(x)                   (((x) & PHY_BB_SRCH_FFT_CTRL_4_SPECTRAL_SCAN_CHN_MASK_MASK) >> PHY_BB_SRCH_FFT_CTRL_4_SPECTRAL_SCAN_CHN_MASK_LSB)
#define PHY_BB_SRCH_FFT_CTRL_4_SPECTRAL_SCAN_CHN_MASK_SET(x)                   (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_4_SPECTRAL_SCAN_CHN_MASK_LSB) & PHY_BB_SRCH_FFT_CTRL_4_SPECTRAL_SCAN_CHN_MASK_MASK)
#define PHY_BB_SRCH_FFT_CTRL_4_SPECTRAL_SCAN_CHN_MASK_RESET                    0x1
#define PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_CHN_MASK_LSB                          0
#define PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_CHN_MASK_MSB                          3
#define PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_CHN_MASK_MASK                         0xf
#define PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_CHN_MASK_GET(x)                       (((x) & PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_CHN_MASK_MASK) >> PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_CHN_MASK_LSB)
#define PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_CHN_MASK_SET(x)                       (((0 | (x)) << PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_CHN_MASK_LSB) & PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_CHN_MASK_MASK)
#define PHY_BB_SRCH_FFT_CTRL_4_RADAR_FFT_CHN_MASK_RESET                        0x1
#define PHY_BB_SRCH_FFT_CTRL_4_ADDRESS                                         (0x8c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SRCH_FFT_CTRL_4_RSTMASK                                         0xffffffff
#define PHY_BB_SRCH_FFT_CTRL_4_RESET                                           0x2364ff11

// 0x90 (PHY_BB_RADAR_CHIRP_DETECT)
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_FFT_BW_CHECK_ENA_LSB                   29
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_FFT_BW_CHECK_ENA_MSB                   29
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_FFT_BW_CHECK_ENA_MASK                  0x20000000
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_FFT_BW_CHECK_ENA_GET(x)                (((x) & PHY_BB_RADAR_CHIRP_DETECT_CHIRP_FFT_BW_CHECK_ENA_MASK) >> PHY_BB_RADAR_CHIRP_DETECT_CHIRP_FFT_BW_CHECK_ENA_LSB)
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_FFT_BW_CHECK_ENA_SET(x)                (((0 | (x)) << PHY_BB_RADAR_CHIRP_DETECT_CHIRP_FFT_BW_CHECK_ENA_LSB) & PHY_BB_RADAR_CHIRP_DETECT_CHIRP_FFT_BW_CHECK_ENA_MASK)
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_FFT_BW_CHECK_ENA_RESET                 0x1
#define PHY_BB_RADAR_CHIRP_DETECT_NONLIN_VEL_CHECK_ENA_LSB                     28
#define PHY_BB_RADAR_CHIRP_DETECT_NONLIN_VEL_CHECK_ENA_MSB                     28
#define PHY_BB_RADAR_CHIRP_DETECT_NONLIN_VEL_CHECK_ENA_MASK                    0x10000000
#define PHY_BB_RADAR_CHIRP_DETECT_NONLIN_VEL_CHECK_ENA_GET(x)                  (((x) & PHY_BB_RADAR_CHIRP_DETECT_NONLIN_VEL_CHECK_ENA_MASK) >> PHY_BB_RADAR_CHIRP_DETECT_NONLIN_VEL_CHECK_ENA_LSB)
#define PHY_BB_RADAR_CHIRP_DETECT_NONLIN_VEL_CHECK_ENA_SET(x)                  (((0 | (x)) << PHY_BB_RADAR_CHIRP_DETECT_NONLIN_VEL_CHECK_ENA_LSB) & PHY_BB_RADAR_CHIRP_DETECT_NONLIN_VEL_CHECK_ENA_MASK)
#define PHY_BB_RADAR_CHIRP_DETECT_NONLIN_VEL_CHECK_ENA_RESET                   0x1
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_FFT_RPT_LSB                    23
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_FFT_RPT_MSB                    27
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_FFT_RPT_MASK                   0xf800000
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_FFT_RPT_GET(x)                 (((x) & PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_FFT_RPT_MASK) >> PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_FFT_RPT_LSB)
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_FFT_RPT_SET(x)                 (((0 | (x)) << PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_FFT_RPT_LSB) & PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_FFT_RPT_MASK)
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_FFT_RPT_RESET                  0x4
#define PHY_BB_RADAR_CHIRP_DETECT_SRCH_FFT_STR_RSSI_THRESH_LSB                 17
#define PHY_BB_RADAR_CHIRP_DETECT_SRCH_FFT_STR_RSSI_THRESH_MSB                 22
#define PHY_BB_RADAR_CHIRP_DETECT_SRCH_FFT_STR_RSSI_THRESH_MASK                0x7e0000
#define PHY_BB_RADAR_CHIRP_DETECT_SRCH_FFT_STR_RSSI_THRESH_GET(x)              (((x) & PHY_BB_RADAR_CHIRP_DETECT_SRCH_FFT_STR_RSSI_THRESH_MASK) >> PHY_BB_RADAR_CHIRP_DETECT_SRCH_FFT_STR_RSSI_THRESH_LSB)
#define PHY_BB_RADAR_CHIRP_DETECT_SRCH_FFT_STR_RSSI_THRESH_SET(x)              (((0 | (x)) << PHY_BB_RADAR_CHIRP_DETECT_SRCH_FFT_STR_RSSI_THRESH_LSB) & PHY_BB_RADAR_CHIRP_DETECT_SRCH_FFT_STR_RSSI_THRESH_MASK)
#define PHY_BB_RADAR_CHIRP_DETECT_SRCH_FFT_STR_RSSI_THRESH_RESET               0xf
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_DIFF_LSB                     13
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_DIFF_MSB                     16
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_DIFF_MASK                    0x1e000
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_DIFF_GET(x)                  (((x) & PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_DIFF_MASK) >> PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_DIFF_LSB)
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_DIFF_SET(x)                  (((0 | (x)) << PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_DIFF_LSB) & PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_DIFF_MASK)
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_DIFF_RESET                   0x2
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_BIN_LSB                      8
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_BIN_MSB                      12
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_BIN_MASK                     0x1f00
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_BIN_GET(x)                   (((x) & PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_BIN_MASK) >> PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_BIN_LSB)
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_BIN_SET(x)                   (((0 | (x)) << PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_BIN_LSB) & PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_BIN_MASK)
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_DELTA_BIN_RESET                    0xb
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MIN_DELTA_BIN_LSB                      3
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MIN_DELTA_BIN_MSB                      7
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MIN_DELTA_BIN_MASK                     0xf8
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MIN_DELTA_BIN_GET(x)                   (((x) & PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MIN_DELTA_BIN_MASK) >> PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MIN_DELTA_BIN_LSB)
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MIN_DELTA_BIN_SET(x)                   (((0 | (x)) << PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MIN_DELTA_BIN_LSB) & PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MIN_DELTA_BIN_MASK)
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MIN_DELTA_BIN_RESET                    0x1
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_DIFF_LSB                       0
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_DIFF_MSB                       2
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_DIFF_MASK                      0x7
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_DIFF_GET(x)                    (((x) & PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_DIFF_MASK) >> PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_DIFF_LSB)
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_DIFF_SET(x)                    (((0 | (x)) << PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_DIFF_LSB) & PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_DIFF_MASK)
#define PHY_BB_RADAR_CHIRP_DETECT_CHIRP_MAX_NUM_DIFF_RESET                     0x3
#define PHY_BB_RADAR_CHIRP_DETECT_ADDRESS                                      (0x90 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RADAR_CHIRP_DETECT_RSTMASK                                      0x3fffffff
#define PHY_BB_RADAR_CHIRP_DETECT_RESET                                        0x321e4b0b

// 0x98 (PHY_BB_SPECTRAL_SCAN_2)
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_RSSI_RPT_MODE_LSB                 31
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_RSSI_RPT_MODE_MSB                 31
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_RSSI_RPT_MODE_MASK                0x80000000
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_RSSI_RPT_MODE_GET(x)              (((x) & PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_RSSI_RPT_MODE_MASK) >> PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_RSSI_RPT_MODE_LSB)
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_RSSI_RPT_MODE_SET(x)              (((0 | (x)) << PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_RSSI_RPT_MODE_LSB) & PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_RSSI_RPT_MODE_MASK)
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_RSSI_RPT_MODE_RESET               0x0
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_WB_RPT_MODE_LSB                   30
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_WB_RPT_MODE_MSB                   30
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_WB_RPT_MODE_MASK                  0x40000000
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_WB_RPT_MODE_GET(x)                (((x) & PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_WB_RPT_MODE_MASK) >> PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_WB_RPT_MODE_LSB)
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_WB_RPT_MODE_SET(x)                (((0 | (x)) << PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_WB_RPT_MODE_LSB) & PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_WB_RPT_MODE_MASK)
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_WB_RPT_MODE_RESET                 0x0
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_STR_BIN_THR_LSB                   24
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_STR_BIN_THR_MSB                   29
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_STR_BIN_THR_MASK                  0x3f000000
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_STR_BIN_THR_GET(x)                (((x) & PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_STR_BIN_THR_MASK) >> PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_STR_BIN_THR_LSB)
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_STR_BIN_THR_SET(x)                (((0 | (x)) << PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_STR_BIN_THR_LSB) & PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_STR_BIN_THR_MASK)
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_STR_BIN_THR_RESET                 0x8
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NB_TONE_THR_LSB                   16
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NB_TONE_THR_MSB                   23
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NB_TONE_THR_MASK                  0xff0000
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NB_TONE_THR_GET(x)                (((x) & PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NB_TONE_THR_MASK) >> PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NB_TONE_THR_LSB)
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NB_TONE_THR_SET(x)                (((0 | (x)) << PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NB_TONE_THR_LSB) & PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NB_TONE_THR_MASK)
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NB_TONE_THR_RESET                 0xc
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_INIT_DELAY_LSB                    8
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_INIT_DELAY_MSB                    14
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_INIT_DELAY_MASK                   0x7f00
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_INIT_DELAY_GET(x)                 (((x) & PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_INIT_DELAY_MASK) >> PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_INIT_DELAY_LSB)
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_INIT_DELAY_SET(x)                 (((0 | (x)) << PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_INIT_DELAY_LSB) & PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_INIT_DELAY_MASK)
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_INIT_DELAY_RESET                  0x50
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NOISE_FLOOR_REF_LSB               0
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NOISE_FLOOR_REF_MSB               7
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NOISE_FLOOR_REF_MASK              0xff
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NOISE_FLOOR_REF_GET(x)            (((x) & PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NOISE_FLOOR_REF_MASK) >> PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NOISE_FLOOR_REF_LSB)
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NOISE_FLOOR_REF_SET(x)            (((0 | (x)) << PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NOISE_FLOOR_REF_LSB) & PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NOISE_FLOOR_REF_MASK)
#define PHY_BB_SPECTRAL_SCAN_2_SPECTRAL_SCAN_NOISE_FLOOR_REF_RESET             0xa0
#define PHY_BB_SPECTRAL_SCAN_2_ADDRESS                                         (0x98 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SPECTRAL_SCAN_2_RSTMASK                                         0xffff7fff
#define PHY_BB_SPECTRAL_SCAN_2_RESET                                           0x80c50a0

// 0x9c (PHY_BB_SPECTRAL_SCAN_3)
#define PHY_BB_SPECTRAL_SCAN_3_SPECTRAL_SCAN_RSSI_THR_LSB                      0
#define PHY_BB_SPECTRAL_SCAN_3_SPECTRAL_SCAN_RSSI_THR_MSB                      7
#define PHY_BB_SPECTRAL_SCAN_3_SPECTRAL_SCAN_RSSI_THR_MASK                     0xff
#define PHY_BB_SPECTRAL_SCAN_3_SPECTRAL_SCAN_RSSI_THR_GET(x)                   (((x) & PHY_BB_SPECTRAL_SCAN_3_SPECTRAL_SCAN_RSSI_THR_MASK) >> PHY_BB_SPECTRAL_SCAN_3_SPECTRAL_SCAN_RSSI_THR_LSB)
#define PHY_BB_SPECTRAL_SCAN_3_SPECTRAL_SCAN_RSSI_THR_SET(x)                   (((0 | (x)) << PHY_BB_SPECTRAL_SCAN_3_SPECTRAL_SCAN_RSSI_THR_LSB) & PHY_BB_SPECTRAL_SCAN_3_SPECTRAL_SCAN_RSSI_THR_MASK)
#define PHY_BB_SPECTRAL_SCAN_3_SPECTRAL_SCAN_RSSI_THR_RESET                    0xf0
#define PHY_BB_SPECTRAL_SCAN_3_ADDRESS                                         (0x9c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SPECTRAL_SCAN_3_RSTMASK                                         0xff
#define PHY_BB_SPECTRAL_SCAN_3_RESET                                           0xf0

// 0xa0 (PHY_BB_AGC_TIMEOUT_1)
#define PHY_BB_AGC_TIMEOUT_1_AGC_HT_STF_SM_TIMEOUT_LSB                         16
#define PHY_BB_AGC_TIMEOUT_1_AGC_HT_STF_SM_TIMEOUT_MSB                         23
#define PHY_BB_AGC_TIMEOUT_1_AGC_HT_STF_SM_TIMEOUT_MASK                        0xff0000
#define PHY_BB_AGC_TIMEOUT_1_AGC_HT_STF_SM_TIMEOUT_GET(x)                      (((x) & PHY_BB_AGC_TIMEOUT_1_AGC_HT_STF_SM_TIMEOUT_MASK) >> PHY_BB_AGC_TIMEOUT_1_AGC_HT_STF_SM_TIMEOUT_LSB)
#define PHY_BB_AGC_TIMEOUT_1_AGC_HT_STF_SM_TIMEOUT_SET(x)                      (((0 | (x)) << PHY_BB_AGC_TIMEOUT_1_AGC_HT_STF_SM_TIMEOUT_LSB) & PHY_BB_AGC_TIMEOUT_1_AGC_HT_STF_SM_TIMEOUT_MASK)
#define PHY_BB_AGC_TIMEOUT_1_AGC_HT_STF_SM_TIMEOUT_RESET                       0x0
#define PHY_BB_AGC_TIMEOUT_1_SSCAN_SM_TIMEOUT_LSB                              8
#define PHY_BB_AGC_TIMEOUT_1_SSCAN_SM_TIMEOUT_MSB                              15
#define PHY_BB_AGC_TIMEOUT_1_SSCAN_SM_TIMEOUT_MASK                             0xff00
#define PHY_BB_AGC_TIMEOUT_1_SSCAN_SM_TIMEOUT_GET(x)                           (((x) & PHY_BB_AGC_TIMEOUT_1_SSCAN_SM_TIMEOUT_MASK) >> PHY_BB_AGC_TIMEOUT_1_SSCAN_SM_TIMEOUT_LSB)
#define PHY_BB_AGC_TIMEOUT_1_SSCAN_SM_TIMEOUT_SET(x)                           (((0 | (x)) << PHY_BB_AGC_TIMEOUT_1_SSCAN_SM_TIMEOUT_LSB) & PHY_BB_AGC_TIMEOUT_1_SSCAN_SM_TIMEOUT_MASK)
#define PHY_BB_AGC_TIMEOUT_1_SSCAN_SM_TIMEOUT_RESET                            0x0
#define PHY_BB_AGC_TIMEOUT_1_RADAR_SM_TIMEOUT_LSB                              0
#define PHY_BB_AGC_TIMEOUT_1_RADAR_SM_TIMEOUT_MSB                              7
#define PHY_BB_AGC_TIMEOUT_1_RADAR_SM_TIMEOUT_MASK                             0xff
#define PHY_BB_AGC_TIMEOUT_1_RADAR_SM_TIMEOUT_GET(x)                           (((x) & PHY_BB_AGC_TIMEOUT_1_RADAR_SM_TIMEOUT_MASK) >> PHY_BB_AGC_TIMEOUT_1_RADAR_SM_TIMEOUT_LSB)
#define PHY_BB_AGC_TIMEOUT_1_RADAR_SM_TIMEOUT_SET(x)                           (((0 | (x)) << PHY_BB_AGC_TIMEOUT_1_RADAR_SM_TIMEOUT_LSB) & PHY_BB_AGC_TIMEOUT_1_RADAR_SM_TIMEOUT_MASK)
#define PHY_BB_AGC_TIMEOUT_1_RADAR_SM_TIMEOUT_RESET                            0x0
#define PHY_BB_AGC_TIMEOUT_1_ADDRESS                                           (0xa0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_AGC_TIMEOUT_1_RSTMASK                                           0xffffff
#define PHY_BB_AGC_TIMEOUT_1_RESET                                             0x0

// 0xa4 (PHY_BB_ADCSAT_CTRL_1)
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CNT_THR_LSB                                21
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CNT_THR_MSB                                25
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CNT_THR_MASK                               0x3e00000
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CNT_THR_GET(x)                             (((x) & PHY_BB_ADCSAT_CTRL_1_ADCSAT_CNT_THR_MASK) >> PHY_BB_ADCSAT_CTRL_1_ADCSAT_CNT_THR_LSB)
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CNT_THR_SET(x)                             (((0 | (x)) << PHY_BB_ADCSAT_CTRL_1_ADCSAT_CNT_THR_LSB) & PHY_BB_ADCSAT_CTRL_1_ADCSAT_CNT_THR_MASK)
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CNT_THR_RESET                              0x8
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_WIN_LEN_LSB                                16
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_WIN_LEN_MSB                                20
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_WIN_LEN_MASK                               0x1f0000
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_WIN_LEN_GET(x)                             (((x) & PHY_BB_ADCSAT_CTRL_1_ADCSAT_WIN_LEN_MASK) >> PHY_BB_ADCSAT_CTRL_1_ADCSAT_WIN_LEN_LSB)
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_WIN_LEN_SET(x)                             (((0 | (x)) << PHY_BB_ADCSAT_CTRL_1_ADCSAT_WIN_LEN_LSB) & PHY_BB_ADCSAT_CTRL_1_ADCSAT_WIN_LEN_MASK)
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_WIN_LEN_RESET                              0x10
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_FOUND_THR_LSB                         8
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_FOUND_THR_MSB                         15
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_FOUND_THR_MASK                        0xff00
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_FOUND_THR_GET(x)                      (((x) & PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_FOUND_THR_MASK) >> PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_FOUND_THR_LSB)
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_FOUND_THR_SET(x)                      (((0 | (x)) << PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_FOUND_THR_LSB) & PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_FOUND_THR_MASK)
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_FOUND_THR_RESET                       0xf7
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_COARSE_THR_LSB                        0
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_COARSE_THR_MSB                        7
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_COARSE_THR_MASK                       0xff
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_COARSE_THR_GET(x)                     (((x) & PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_COARSE_THR_MASK) >> PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_COARSE_THR_LSB)
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_COARSE_THR_SET(x)                     (((0 | (x)) << PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_COARSE_THR_LSB) & PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_COARSE_THR_MASK)
#define PHY_BB_ADCSAT_CTRL_1_ADCSAT_CLIP_COARSE_THR_RESET                      0x91
#define PHY_BB_ADCSAT_CTRL_1_ADDRESS                                           (0xa4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_ADCSAT_CTRL_1_RSTMASK                                           0x3ffffff
#define PHY_BB_ADCSAT_CTRL_1_RESET                                             0x110f791

// 0xa8 (PHY_BB_ADCSAT_CTRL_2)
#define PHY_BB_ADCSAT_CTRL_2_USE_RF_GAIN_FOR_XATTEN_CONTROL_LSB                31
#define PHY_BB_ADCSAT_CTRL_2_USE_RF_GAIN_FOR_XATTEN_CONTROL_MSB                31
#define PHY_BB_ADCSAT_CTRL_2_USE_RF_GAIN_FOR_XATTEN_CONTROL_MASK               0x80000000
#define PHY_BB_ADCSAT_CTRL_2_USE_RF_GAIN_FOR_XATTEN_CONTROL_GET(x)             (((x) & PHY_BB_ADCSAT_CTRL_2_USE_RF_GAIN_FOR_XATTEN_CONTROL_MASK) >> PHY_BB_ADCSAT_CTRL_2_USE_RF_GAIN_FOR_XATTEN_CONTROL_LSB)
#define PHY_BB_ADCSAT_CTRL_2_USE_RF_GAIN_FOR_XATTEN_CONTROL_SET(x)             (((0 | (x)) << PHY_BB_ADCSAT_CTRL_2_USE_RF_GAIN_FOR_XATTEN_CONTROL_LSB) & PHY_BB_ADCSAT_CTRL_2_USE_RF_GAIN_FOR_XATTEN_CONTROL_MASK)
#define PHY_BB_ADCSAT_CTRL_2_USE_RF_GAIN_FOR_XATTEN_CONTROL_RESET              0x0
#define PHY_BB_ADCSAT_CTRL_2_RF_REDUCE_ONLY_GCMODE1_RECENT_RFSAT_LSB           24
#define PHY_BB_ADCSAT_CTRL_2_RF_REDUCE_ONLY_GCMODE1_RECENT_RFSAT_MSB           24
#define PHY_BB_ADCSAT_CTRL_2_RF_REDUCE_ONLY_GCMODE1_RECENT_RFSAT_MASK          0x1000000
#define PHY_BB_ADCSAT_CTRL_2_RF_REDUCE_ONLY_GCMODE1_RECENT_RFSAT_GET(x)        (((x) & PHY_BB_ADCSAT_CTRL_2_RF_REDUCE_ONLY_GCMODE1_RECENT_RFSAT_MASK) >> PHY_BB_ADCSAT_CTRL_2_RF_REDUCE_ONLY_GCMODE1_RECENT_RFSAT_LSB)
#define PHY_BB_ADCSAT_CTRL_2_RF_REDUCE_ONLY_GCMODE1_RECENT_RFSAT_SET(x)        (((0 | (x)) << PHY_BB_ADCSAT_CTRL_2_RF_REDUCE_ONLY_GCMODE1_RECENT_RFSAT_LSB) & PHY_BB_ADCSAT_CTRL_2_RF_REDUCE_ONLY_GCMODE1_RECENT_RFSAT_MASK)
#define PHY_BB_ADCSAT_CTRL_2_RF_REDUCE_ONLY_GCMODE1_RECENT_RFSAT_RESET         0x0
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_OTHER_LSB                               16
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_OTHER_MSB                               23
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_OTHER_MASK                              0xff0000
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_OTHER_GET(x)                            (((x) & PHY_BB_ADCSAT_CTRL_2_QUICKDROP_OTHER_MASK) >> PHY_BB_ADCSAT_CTRL_2_QUICKDROP_OTHER_LSB)
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_OTHER_SET(x)                            (((0 | (x)) << PHY_BB_ADCSAT_CTRL_2_QUICKDROP_OTHER_LSB) & PHY_BB_ADCSAT_CTRL_2_QUICKDROP_OTHER_MASK)
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_OTHER_RESET                             0xec
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_FOUND_LSB                               8
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_FOUND_MSB                               15
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_FOUND_MASK                              0xff00
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_FOUND_GET(x)                            (((x) & PHY_BB_ADCSAT_CTRL_2_QUICKDROP_FOUND_MASK) >> PHY_BB_ADCSAT_CTRL_2_QUICKDROP_FOUND_LSB)
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_FOUND_SET(x)                            (((0 | (x)) << PHY_BB_ADCSAT_CTRL_2_QUICKDROP_FOUND_LSB) & PHY_BB_ADCSAT_CTRL_2_QUICKDROP_FOUND_MASK)
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_FOUND_RESET                             0xd8
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_COARSE_LSB                              0
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_COARSE_MSB                              7
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_COARSE_MASK                             0xff
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_COARSE_GET(x)                           (((x) & PHY_BB_ADCSAT_CTRL_2_QUICKDROP_COARSE_MASK) >> PHY_BB_ADCSAT_CTRL_2_QUICKDROP_COARSE_LSB)
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_COARSE_SET(x)                           (((0 | (x)) << PHY_BB_ADCSAT_CTRL_2_QUICKDROP_COARSE_LSB) & PHY_BB_ADCSAT_CTRL_2_QUICKDROP_COARSE_MASK)
#define PHY_BB_ADCSAT_CTRL_2_QUICKDROP_COARSE_RESET                            0xd8
#define PHY_BB_ADCSAT_CTRL_2_ADDRESS                                           (0xa8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_ADCSAT_CTRL_2_RSTMASK                                           0x81ffffff
#define PHY_BB_ADCSAT_CTRL_2_RESET                                             0xecd8d8

// 0xac (PHY_BB_AGC_SPARE_01)
#define PHY_BB_AGC_SPARE_01_AGC_ECO_CTRL_LSB                                   0
#define PHY_BB_AGC_SPARE_01_AGC_ECO_CTRL_MSB                                   31
#define PHY_BB_AGC_SPARE_01_AGC_ECO_CTRL_MASK                                  0xffffffff
#define PHY_BB_AGC_SPARE_01_AGC_ECO_CTRL_GET(x)                                (((x) & PHY_BB_AGC_SPARE_01_AGC_ECO_CTRL_MASK) >> PHY_BB_AGC_SPARE_01_AGC_ECO_CTRL_LSB)
#define PHY_BB_AGC_SPARE_01_AGC_ECO_CTRL_SET(x)                                (((0 | (x)) << PHY_BB_AGC_SPARE_01_AGC_ECO_CTRL_LSB) & PHY_BB_AGC_SPARE_01_AGC_ECO_CTRL_MASK)
#define PHY_BB_AGC_SPARE_01_AGC_ECO_CTRL_RESET                                 0x0
#define PHY_BB_AGC_SPARE_01_ADDRESS                                            (0xac + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_AGC_SPARE_01_RSTMASK                                            0xffffffff
#define PHY_BB_AGC_SPARE_01_RESET                                              0x0

// 0xb0 (PHY_BB_AGC_HT_STF_CTRL_1)
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_ADC_PWR_LSB                    24
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_ADC_PWR_MSB                    31
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_ADC_PWR_MASK                   0xff000000
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_ADC_PWR_GET(x)                 (((x) & PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_ADC_PWR_MASK) >> PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_ADC_PWR_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_ADC_PWR_SET(x)                 (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_ADC_PWR_LSB) & PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_ADC_PWR_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_ADC_PWR_RESET                  0xe2
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_LSTF_PWR_LSB                   16
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_LSTF_PWR_MSB                   23
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_LSTF_PWR_MASK                  0xff0000
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_LSTF_PWR_GET(x)                (((x) & PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_LSTF_PWR_MASK) >> PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_LSTF_PWR_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_LSTF_PWR_SET(x)                (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_LSTF_PWR_LSB) & PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_LSTF_PWR_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_MIN_LSTF_PWR_RESET                 0xd8
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_WEAK_SIZE_DESIRED_LSB              8
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_WEAK_SIZE_DESIRED_MSB              15
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_WEAK_SIZE_DESIRED_MASK             0xff00
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_WEAK_SIZE_DESIRED_GET(x)           (((x) & PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_WEAK_SIZE_DESIRED_MASK) >> PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_WEAK_SIZE_DESIRED_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_WEAK_SIZE_DESIRED_SET(x)           (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_WEAK_SIZE_DESIRED_LSB) & PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_WEAK_SIZE_DESIRED_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_WEAK_SIZE_DESIRED_RESET            0xc4
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_PWR_DELAY_LSB                      2
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_PWR_DELAY_MSB                      7
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_PWR_DELAY_MASK                     0xfc
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_PWR_DELAY_GET(x)                   (((x) & PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_PWR_DELAY_MASK) >> PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_PWR_DELAY_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_PWR_DELAY_SET(x)                   (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_PWR_DELAY_LSB) & PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_PWR_DELAY_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_PWR_DELAY_RESET                    0x23
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ALLOW_GAIN_INCR_LSB                1
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ALLOW_GAIN_INCR_MSB                1
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ALLOW_GAIN_INCR_MASK               0x2
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ALLOW_GAIN_INCR_GET(x)             (((x) & PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ALLOW_GAIN_INCR_MASK) >> PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ALLOW_GAIN_INCR_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ALLOW_GAIN_INCR_SET(x)             (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ALLOW_GAIN_INCR_LSB) & PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ALLOW_GAIN_INCR_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ALLOW_GAIN_INCR_RESET              0x1
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ENA_LSB                            0
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ENA_MSB                            0
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ENA_MASK                           0x1
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ENA_GET(x)                         (((x) & PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ENA_MASK) >> PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ENA_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ENA_SET(x)                         (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ENA_LSB) & PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ENA_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_1_AGC_HT_STF_ENA_RESET                          0x1
#define PHY_BB_AGC_HT_STF_CTRL_1_ADDRESS                                       (0xb0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_AGC_HT_STF_CTRL_1_RSTMASK                                       0xffffffff
#define PHY_BB_AGC_HT_STF_CTRL_1_RESET                                         0xe2d8c48f

// 0xb4 (PHY_BB_AGC_HT_STF_CTRL_2)
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_SETTLING_LSB                       23
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_SETTLING_MSB                       29
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_SETTLING_MASK                      0x3f800000
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_SETTLING_GET(x)                    (((x) & PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_SETTLING_MASK) >> PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_SETTLING_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_SETTLING_SET(x)                    (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_SETTLING_LSB) & PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_SETTLING_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_SETTLING_RESET                     0x16
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_ALLOW_RF_LSB                       22
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_ALLOW_RF_MSB                       22
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_ALLOW_RF_MASK                      0x400000
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_ALLOW_RF_GET(x)                    (((x) & PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_ALLOW_RF_MASK) >> PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_ALLOW_RF_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_ALLOW_RF_SET(x)                    (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_ALLOW_RF_LSB) & PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_ALLOW_RF_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_ALLOW_RF_RESET                     0x0
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_WIN_SEL_LSB                 21
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_WIN_SEL_MSB                 21
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_WIN_SEL_MASK                0x200000
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_WIN_SEL_GET(x)              (((x) & PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_WIN_SEL_MASK) >> PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_WIN_SEL_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_WIN_SEL_SET(x)              (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_WIN_SEL_LSB) & PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_WIN_SEL_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_WIN_SEL_RESET               0x1
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_ENA_LSB                     20
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_ENA_MSB                     20
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_ENA_MASK                    0x100000
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_ENA_GET(x)                  (((x) & PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_ENA_MASK) >> PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_ENA_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_ENA_SET(x)                  (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_ENA_LSB) & PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_ENA_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_DC_EST_ENA_RESET                   0x1
#define PHY_BB_AGC_HT_STF_CTRL_2_VHT_SYM_DET_NUM_BINS_LSB                      16
#define PHY_BB_AGC_HT_STF_CTRL_2_VHT_SYM_DET_NUM_BINS_MSB                      19
#define PHY_BB_AGC_HT_STF_CTRL_2_VHT_SYM_DET_NUM_BINS_MASK                     0xf0000
#define PHY_BB_AGC_HT_STF_CTRL_2_VHT_SYM_DET_NUM_BINS_GET(x)                   (((x) & PHY_BB_AGC_HT_STF_CTRL_2_VHT_SYM_DET_NUM_BINS_MASK) >> PHY_BB_AGC_HT_STF_CTRL_2_VHT_SYM_DET_NUM_BINS_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_2_VHT_SYM_DET_NUM_BINS_SET(x)                   (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_2_VHT_SYM_DET_NUM_BINS_LSB) & PHY_BB_AGC_HT_STF_CTRL_2_VHT_SYM_DET_NUM_BINS_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_2_VHT_SYM_DET_NUM_BINS_RESET                    0xb
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_LOW_GC_THR_LSB                 8
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_LOW_GC_THR_MSB                 15
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_LOW_GC_THR_MASK                0xff00
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_LOW_GC_THR_GET(x)              (((x) & PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_LOW_GC_THR_MASK) >> PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_LOW_GC_THR_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_LOW_GC_THR_SET(x)              (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_LOW_GC_THR_LSB) & PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_LOW_GC_THR_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_LOW_GC_THR_RESET               0xc
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_HIGH_GC_THR_LSB                0
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_HIGH_GC_THR_MSB                7
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_HIGH_GC_THR_MASK               0xff
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_HIGH_GC_THR_GET(x)             (((x) & PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_HIGH_GC_THR_MASK) >> PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_HIGH_GC_THR_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_HIGH_GC_THR_SET(x)             (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_HIGH_GC_THR_LSB) & PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_HIGH_GC_THR_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_2_AGC_HT_STF_PWR_HIGH_GC_THR_RESET              0xc
#define PHY_BB_AGC_HT_STF_CTRL_2_ADDRESS                                       (0xb4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_AGC_HT_STF_CTRL_2_RSTMASK                                       0x3fffffff
#define PHY_BB_AGC_HT_STF_CTRL_2_RESET                                         0xb3b0c0c

// 0xb8 (PHY_BB_AGC_HT_STF_CTRL_3)
#define PHY_BB_AGC_HT_STF_CTRL_3_AGC_HT_STF_LSIG_LEN_MIN_LSB                   0
#define PHY_BB_AGC_HT_STF_CTRL_3_AGC_HT_STF_LSIG_LEN_MIN_MSB                   7
#define PHY_BB_AGC_HT_STF_CTRL_3_AGC_HT_STF_LSIG_LEN_MIN_MASK                  0xff
#define PHY_BB_AGC_HT_STF_CTRL_3_AGC_HT_STF_LSIG_LEN_MIN_GET(x)                (((x) & PHY_BB_AGC_HT_STF_CTRL_3_AGC_HT_STF_LSIG_LEN_MIN_MASK) >> PHY_BB_AGC_HT_STF_CTRL_3_AGC_HT_STF_LSIG_LEN_MIN_LSB)
#define PHY_BB_AGC_HT_STF_CTRL_3_AGC_HT_STF_LSIG_LEN_MIN_SET(x)                (((0 | (x)) << PHY_BB_AGC_HT_STF_CTRL_3_AGC_HT_STF_LSIG_LEN_MIN_LSB) & PHY_BB_AGC_HT_STF_CTRL_3_AGC_HT_STF_LSIG_LEN_MIN_MASK)
#define PHY_BB_AGC_HT_STF_CTRL_3_AGC_HT_STF_LSIG_LEN_MIN_RESET                 0x8
#define PHY_BB_AGC_HT_STF_CTRL_3_ADDRESS                                       (0xb8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_AGC_HT_STF_CTRL_3_RSTMASK                                       0xff
#define PHY_BB_AGC_HT_STF_CTRL_3_RESET                                         0x8

// 0xbc (PHY_BB_RADAR_LB_CONTROL)
#define PHY_BB_RADAR_LB_CONTROL_FORCE_ADC_LB_BYPASS_LSB                        31
#define PHY_BB_RADAR_LB_CONTROL_FORCE_ADC_LB_BYPASS_MSB                        31
#define PHY_BB_RADAR_LB_CONTROL_FORCE_ADC_LB_BYPASS_MASK                       0x80000000
#define PHY_BB_RADAR_LB_CONTROL_FORCE_ADC_LB_BYPASS_GET(x)                     (((x) & PHY_BB_RADAR_LB_CONTROL_FORCE_ADC_LB_BYPASS_MASK) >> PHY_BB_RADAR_LB_CONTROL_FORCE_ADC_LB_BYPASS_LSB)
#define PHY_BB_RADAR_LB_CONTROL_FORCE_ADC_LB_BYPASS_SET(x)                     (((0 | (x)) << PHY_BB_RADAR_LB_CONTROL_FORCE_ADC_LB_BYPASS_LSB) & PHY_BB_RADAR_LB_CONTROL_FORCE_ADC_LB_BYPASS_MASK)
#define PHY_BB_RADAR_LB_CONTROL_FORCE_ADC_LB_BYPASS_RESET                      0x0
#define PHY_BB_RADAR_LB_CONTROL_FORCE_PWR_LB_BYPASS_LSB                        30
#define PHY_BB_RADAR_LB_CONTROL_FORCE_PWR_LB_BYPASS_MSB                        30
#define PHY_BB_RADAR_LB_CONTROL_FORCE_PWR_LB_BYPASS_MASK                       0x40000000
#define PHY_BB_RADAR_LB_CONTROL_FORCE_PWR_LB_BYPASS_GET(x)                     (((x) & PHY_BB_RADAR_LB_CONTROL_FORCE_PWR_LB_BYPASS_MASK) >> PHY_BB_RADAR_LB_CONTROL_FORCE_PWR_LB_BYPASS_LSB)
#define PHY_BB_RADAR_LB_CONTROL_FORCE_PWR_LB_BYPASS_SET(x)                     (((0 | (x)) << PHY_BB_RADAR_LB_CONTROL_FORCE_PWR_LB_BYPASS_LSB) & PHY_BB_RADAR_LB_CONTROL_FORCE_PWR_LB_BYPASS_MASK)
#define PHY_BB_RADAR_LB_CONTROL_FORCE_PWR_LB_BYPASS_RESET                      0x0
#define PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_INTERVAL_LSB                     24
#define PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_INTERVAL_MSB                     29
#define PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_INTERVAL_MASK                    0x3f000000
#define PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_INTERVAL_GET(x)                  (((x) & PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_INTERVAL_MASK) >> PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_INTERVAL_LSB)
#define PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_INTERVAL_SET(x)                  (((0 | (x)) << PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_INTERVAL_LSB) & PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_INTERVAL_MASK)
#define PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_INTERVAL_RESET                   0x14
#define PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_SKIP_ENA_LSB                     23
#define PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_SKIP_ENA_MSB                     23
#define PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_SKIP_ENA_MASK                    0x800000
#define PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_SKIP_ENA_GET(x)                  (((x) & PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_SKIP_ENA_MASK) >> PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_SKIP_ENA_LSB)
#define PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_SKIP_ENA_SET(x)                  (((0 | (x)) << PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_SKIP_ENA_LSB) & PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_SKIP_ENA_MASK)
#define PHY_BB_RADAR_LB_CONTROL_CHIRP_OVER_DC_SKIP_ENA_RESET                   0x0
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_ADAPT_CMP_THR_LSB                     18
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_ADAPT_CMP_THR_MSB                     22
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_ADAPT_CMP_THR_MASK                    0x7c0000
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_ADAPT_CMP_THR_GET(x)                  (((x) & PHY_BB_RADAR_LB_CONTROL_RADAR_LB_ADAPT_CMP_THR_MASK) >> PHY_BB_RADAR_LB_CONTROL_RADAR_LB_ADAPT_CMP_THR_LSB)
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_ADAPT_CMP_THR_SET(x)                  (((0 | (x)) << PHY_BB_RADAR_LB_CONTROL_RADAR_LB_ADAPT_CMP_THR_LSB) & PHY_BB_RADAR_LB_CONTROL_RADAR_LB_ADAPT_CMP_THR_MASK)
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_ADAPT_CMP_THR_RESET                   0xa
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_CONV_FACTOR_LSB                       10
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_CONV_FACTOR_MSB                       17
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_CONV_FACTOR_MASK                      0x3fc00
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_CONV_FACTOR_GET(x)                    (((x) & PHY_BB_RADAR_LB_CONTROL_RADAR_LB_CONV_FACTOR_MASK) >> PHY_BB_RADAR_LB_CONTROL_RADAR_LB_CONV_FACTOR_LSB)
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_CONV_FACTOR_SET(x)                    (((0 | (x)) << PHY_BB_RADAR_LB_CONTROL_RADAR_LB_CONV_FACTOR_LSB) & PHY_BB_RADAR_LB_CONTROL_RADAR_LB_CONV_FACTOR_MASK)
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_CONV_FACTOR_RESET                     0x64
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_DC_CAP_AT_DC_LSB                      1
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_DC_CAP_AT_DC_MSB                      9
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_DC_CAP_AT_DC_MASK                     0x3fe
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_DC_CAP_AT_DC_GET(x)                   (((x) & PHY_BB_RADAR_LB_CONTROL_RADAR_LB_DC_CAP_AT_DC_MASK) >> PHY_BB_RADAR_LB_CONTROL_RADAR_LB_DC_CAP_AT_DC_LSB)
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_DC_CAP_AT_DC_SET(x)                   (((0 | (x)) << PHY_BB_RADAR_LB_CONTROL_RADAR_LB_DC_CAP_AT_DC_LSB) & PHY_BB_RADAR_LB_CONTROL_RADAR_LB_DC_CAP_AT_DC_MASK)
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_DC_CAP_AT_DC_RESET                    0x14
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_MODE_LSB                              0
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_MODE_MSB                              0
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_MODE_MASK                             0x1
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_MODE_GET(x)                           (((x) & PHY_BB_RADAR_LB_CONTROL_RADAR_LB_MODE_MASK) >> PHY_BB_RADAR_LB_CONTROL_RADAR_LB_MODE_LSB)
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_MODE_SET(x)                           (((0 | (x)) << PHY_BB_RADAR_LB_CONTROL_RADAR_LB_MODE_LSB) & PHY_BB_RADAR_LB_CONTROL_RADAR_LB_MODE_MASK)
#define PHY_BB_RADAR_LB_CONTROL_RADAR_LB_MODE_RESET                            0x1
#define PHY_BB_RADAR_LB_CONTROL_ADDRESS                                        (0xbc + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RADAR_LB_CONTROL_RSTMASK                                        0xffffffff
#define PHY_BB_RADAR_LB_CONTROL_RESET                                          0x14299029

// 0xc0 (PHY_BB_RADAR_PULSE_THRES1)
#define PHY_BB_RADAR_PULSE_THRES1_RADAR_1ST_FFT_DELAY_LSB                      26
#define PHY_BB_RADAR_PULSE_THRES1_RADAR_1ST_FFT_DELAY_MSB                      31
#define PHY_BB_RADAR_PULSE_THRES1_RADAR_1ST_FFT_DELAY_MASK                     0xfc000000
#define PHY_BB_RADAR_PULSE_THRES1_RADAR_1ST_FFT_DELAY_GET(x)                   (((x) & PHY_BB_RADAR_PULSE_THRES1_RADAR_1ST_FFT_DELAY_MASK) >> PHY_BB_RADAR_PULSE_THRES1_RADAR_1ST_FFT_DELAY_LSB)
#define PHY_BB_RADAR_PULSE_THRES1_RADAR_1ST_FFT_DELAY_SET(x)                   (((0 | (x)) << PHY_BB_RADAR_PULSE_THRES1_RADAR_1ST_FFT_DELAY_LSB) & PHY_BB_RADAR_PULSE_THRES1_RADAR_1ST_FFT_DELAY_MASK)
#define PHY_BB_RADAR_PULSE_THRES1_RADAR_1ST_FFT_DELAY_RESET                    0x0
#define PHY_BB_RADAR_PULSE_THRES1_PURSUE_EXT80_RADAR_LSB                       25
#define PHY_BB_RADAR_PULSE_THRES1_PURSUE_EXT80_RADAR_MSB                       25
#define PHY_BB_RADAR_PULSE_THRES1_PURSUE_EXT80_RADAR_MASK                      0x2000000
#define PHY_BB_RADAR_PULSE_THRES1_PURSUE_EXT80_RADAR_GET(x)                    (((x) & PHY_BB_RADAR_PULSE_THRES1_PURSUE_EXT80_RADAR_MASK) >> PHY_BB_RADAR_PULSE_THRES1_PURSUE_EXT80_RADAR_LSB)
#define PHY_BB_RADAR_PULSE_THRES1_PURSUE_EXT80_RADAR_SET(x)                    (((0 | (x)) << PHY_BB_RADAR_PULSE_THRES1_PURSUE_EXT80_RADAR_LSB) & PHY_BB_RADAR_PULSE_THRES1_PURSUE_EXT80_RADAR_MASK)
#define PHY_BB_RADAR_PULSE_THRES1_PURSUE_EXT80_RADAR_RESET                     0x0
#define PHY_BB_RADAR_PULSE_THRES1_RADAR_FFT_80P80_REL_THRSH_LSB                19
#define PHY_BB_RADAR_PULSE_THRES1_RADAR_FFT_80P80_REL_THRSH_MSB                24
#define PHY_BB_RADAR_PULSE_THRES1_RADAR_FFT_80P80_REL_THRSH_MASK               0x1f80000
#define PHY_BB_RADAR_PULSE_THRES1_RADAR_FFT_80P80_REL_THRSH_GET(x)             (((x) & PHY_BB_RADAR_PULSE_THRES1_RADAR_FFT_80P80_REL_THRSH_MASK) >> PHY_BB_RADAR_PULSE_THRES1_RADAR_FFT_80P80_REL_THRSH_LSB)
#define PHY_BB_RADAR_PULSE_THRES1_RADAR_FFT_80P80_REL_THRSH_SET(x)             (((0 | (x)) << PHY_BB_RADAR_PULSE_THRES1_RADAR_FFT_80P80_REL_THRSH_LSB) & PHY_BB_RADAR_PULSE_THRES1_RADAR_FFT_80P80_REL_THRSH_MASK)
#define PHY_BB_RADAR_PULSE_THRES1_RADAR_FFT_80P80_REL_THRSH_RESET              0x0
#define PHY_BB_RADAR_PULSE_THRES1_PULSE_AT_DC_RSSI_THRESH_LSB                  13
#define PHY_BB_RADAR_PULSE_THRES1_PULSE_AT_DC_RSSI_THRESH_MSB                  18
#define PHY_BB_RADAR_PULSE_THRES1_PULSE_AT_DC_RSSI_THRESH_MASK                 0x7e000
#define PHY_BB_RADAR_PULSE_THRES1_PULSE_AT_DC_RSSI_THRESH_GET(x)               (((x) & PHY_BB_RADAR_PULSE_THRES1_PULSE_AT_DC_RSSI_THRESH_MASK) >> PHY_BB_RADAR_PULSE_THRES1_PULSE_AT_DC_RSSI_THRESH_LSB)
#define PHY_BB_RADAR_PULSE_THRES1_PULSE_AT_DC_RSSI_THRESH_SET(x)               (((0 | (x)) << PHY_BB_RADAR_PULSE_THRES1_PULSE_AT_DC_RSSI_THRESH_LSB) & PHY_BB_RADAR_PULSE_THRES1_PULSE_AT_DC_RSSI_THRESH_MASK)
#define PHY_BB_RADAR_PULSE_THRES1_PULSE_AT_DC_RSSI_THRESH_RESET                0xa
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_THRESH_LSB                   7
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_THRESH_MSB                   12
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_THRESH_MASK                  0x1f80
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_THRESH_GET(x)                (((x) & PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_THRESH_MASK) >> PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_THRESH_LSB)
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_THRESH_SET(x)                (((0 | (x)) << PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_THRESH_LSB) & PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_THRESH_MASK)
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_THRESH_RESET                 0xa
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_AT_DC_RSSI_THRESH_LSB             1
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_AT_DC_RSSI_THRESH_MSB             6
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_AT_DC_RSSI_THRESH_MASK            0x7e
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_AT_DC_RSSI_THRESH_GET(x)          (((x) & PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_AT_DC_RSSI_THRESH_MASK) >> PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_AT_DC_RSSI_THRESH_LSB)
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_AT_DC_RSSI_THRESH_SET(x)          (((0 | (x)) << PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_AT_DC_RSSI_THRESH_LSB) & PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_AT_DC_RSSI_THRESH_MASK)
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_AT_DC_RSSI_THRESH_RESET           0xa
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_CHECK_ENA_LSB                0
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_CHECK_ENA_MSB                0
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_CHECK_ENA_MASK               0x1
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_CHECK_ENA_GET(x)             (((x) & PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_CHECK_ENA_MASK) >> PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_CHECK_ENA_LSB)
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_CHECK_ENA_SET(x)             (((0 | (x)) << PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_CHECK_ENA_LSB) & PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_CHECK_ENA_MASK)
#define PHY_BB_RADAR_PULSE_THRES1_LONG_PULSE_RSSI_CHECK_ENA_RESET              0x1
#define PHY_BB_RADAR_PULSE_THRES1_ADDRESS                                      (0xc0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RADAR_PULSE_THRES1_RSTMASK                                      0xffffffff
#define PHY_BB_RADAR_PULSE_THRES1_RESET                                        0x14515

// 0xc4 (PHY_BB_RADAR_PULSE_THRES2)
#define PHY_BB_RADAR_PULSE_THRES2_SRCH_FFT_ADCSAT_PEAKMAG_THR_LSB              20
#define PHY_BB_RADAR_PULSE_THRES2_SRCH_FFT_ADCSAT_PEAKMAG_THR_MSB              29
#define PHY_BB_RADAR_PULSE_THRES2_SRCH_FFT_ADCSAT_PEAKMAG_THR_MASK             0x3ff00000
#define PHY_BB_RADAR_PULSE_THRES2_SRCH_FFT_ADCSAT_PEAKMAG_THR_GET(x)           (((x) & PHY_BB_RADAR_PULSE_THRES2_SRCH_FFT_ADCSAT_PEAKMAG_THR_MASK) >> PHY_BB_RADAR_PULSE_THRES2_SRCH_FFT_ADCSAT_PEAKMAG_THR_LSB)
#define PHY_BB_RADAR_PULSE_THRES2_SRCH_FFT_ADCSAT_PEAKMAG_THR_SET(x)           (((0 | (x)) << PHY_BB_RADAR_PULSE_THRES2_SRCH_FFT_ADCSAT_PEAKMAG_THR_LSB) & PHY_BB_RADAR_PULSE_THRES2_SRCH_FFT_ADCSAT_PEAKMAG_THR_MASK)
#define PHY_BB_RADAR_PULSE_THRES2_SRCH_FFT_ADCSAT_PEAKMAG_THR_RESET            0x64
#define PHY_BB_RADAR_PULSE_THRES2_NB_TONE_THRES_RADAR_CHIRP_LSB                12
#define PHY_BB_RADAR_PULSE_THRES2_NB_TONE_THRES_RADAR_CHIRP_MSB                19
#define PHY_BB_RADAR_PULSE_THRES2_NB_TONE_THRES_RADAR_CHIRP_MASK               0xff000
#define PHY_BB_RADAR_PULSE_THRES2_NB_TONE_THRES_RADAR_CHIRP_GET(x)             (((x) & PHY_BB_RADAR_PULSE_THRES2_NB_TONE_THRES_RADAR_CHIRP_MASK) >> PHY_BB_RADAR_PULSE_THRES2_NB_TONE_THRES_RADAR_CHIRP_LSB)
#define PHY_BB_RADAR_PULSE_THRES2_NB_TONE_THRES_RADAR_CHIRP_SET(x)             (((0 | (x)) << PHY_BB_RADAR_PULSE_THRES2_NB_TONE_THRES_RADAR_CHIRP_LSB) & PHY_BB_RADAR_PULSE_THRES2_NB_TONE_THRES_RADAR_CHIRP_MASK)
#define PHY_BB_RADAR_PULSE_THRES2_NB_TONE_THRES_RADAR_CHIRP_RESET              0x8
#define PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_CHIRP_LSB                  6
#define PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_CHIRP_MSB                  11
#define PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_CHIRP_MASK                 0xfc0
#define PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_CHIRP_GET(x)               (((x) & PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_CHIRP_MASK) >> PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_CHIRP_LSB)
#define PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_CHIRP_SET(x)               (((0 | (x)) << PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_CHIRP_LSB) & PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_CHIRP_MASK)
#define PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_CHIRP_RESET                0x6
#define PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_FINE_LSB                   0
#define PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_FINE_MSB                   5
#define PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_FINE_MASK                  0x3f
#define PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_FINE_GET(x)                (((x) & PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_FINE_MASK) >> PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_FINE_LSB)
#define PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_FINE_SET(x)                (((0 | (x)) << PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_FINE_LSB) & PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_FINE_MASK)
#define PHY_BB_RADAR_PULSE_THRES2_STR_BIN_THR_RADAR_FINE_RESET                 0x6
#define PHY_BB_RADAR_PULSE_THRES2_ADDRESS                                      (0xc4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RADAR_PULSE_THRES2_RSTMASK                                      0x3fffffff
#define PHY_BB_RADAR_PULSE_THRES2_RESET                                        0x6408186

// 0xc8 (PHY_BB_SS_GAIN_CTRL_1)
#define PHY_BB_SS_GAIN_CTRL_1_PURE_GAIN_COPY_LSB                               28
#define PHY_BB_SS_GAIN_CTRL_1_PURE_GAIN_COPY_MSB                               28
#define PHY_BB_SS_GAIN_CTRL_1_PURE_GAIN_COPY_MASK                              0x10000000
#define PHY_BB_SS_GAIN_CTRL_1_PURE_GAIN_COPY_GET(x)                            (((x) & PHY_BB_SS_GAIN_CTRL_1_PURE_GAIN_COPY_MASK) >> PHY_BB_SS_GAIN_CTRL_1_PURE_GAIN_COPY_LSB)
#define PHY_BB_SS_GAIN_CTRL_1_PURE_GAIN_COPY_SET(x)                            (((0 | (x)) << PHY_BB_SS_GAIN_CTRL_1_PURE_GAIN_COPY_LSB) & PHY_BB_SS_GAIN_CTRL_1_PURE_GAIN_COPY_MASK)
#define PHY_BB_SS_GAIN_CTRL_1_PURE_GAIN_COPY_RESET                             0x0
#define PHY_BB_SS_GAIN_CTRL_1_SS_COPY_TARGET_POWER_LSB                         24
#define PHY_BB_SS_GAIN_CTRL_1_SS_COPY_TARGET_POWER_MSB                         24
#define PHY_BB_SS_GAIN_CTRL_1_SS_COPY_TARGET_POWER_MASK                        0x1000000
#define PHY_BB_SS_GAIN_CTRL_1_SS_COPY_TARGET_POWER_GET(x)                      (((x) & PHY_BB_SS_GAIN_CTRL_1_SS_COPY_TARGET_POWER_MASK) >> PHY_BB_SS_GAIN_CTRL_1_SS_COPY_TARGET_POWER_LSB)
#define PHY_BB_SS_GAIN_CTRL_1_SS_COPY_TARGET_POWER_SET(x)                      (((0 | (x)) << PHY_BB_SS_GAIN_CTRL_1_SS_COPY_TARGET_POWER_LSB) & PHY_BB_SS_GAIN_CTRL_1_SS_COPY_TARGET_POWER_MASK)
#define PHY_BB_SS_GAIN_CTRL_1_SS_COPY_TARGET_POWER_RESET                       0x0
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_REDUCE_DB2_LSB                      16
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_REDUCE_DB2_MSB                      21
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_REDUCE_DB2_MASK                     0x3f0000
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_REDUCE_DB2_GET(x)                   (((x) & PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_REDUCE_DB2_MASK) >> PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_REDUCE_DB2_LSB)
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_REDUCE_DB2_SET(x)                   (((0 | (x)) << PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_REDUCE_DB2_LSB) & PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_REDUCE_DB2_MASK)
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_REDUCE_DB2_RESET                    0x0
#define PHY_BB_SS_GAIN_CTRL_1_SS_SETTLE_TIME_LSB                               8
#define PHY_BB_SS_GAIN_CTRL_1_SS_SETTLE_TIME_MSB                               14
#define PHY_BB_SS_GAIN_CTRL_1_SS_SETTLE_TIME_MASK                              0x7f00
#define PHY_BB_SS_GAIN_CTRL_1_SS_SETTLE_TIME_GET(x)                            (((x) & PHY_BB_SS_GAIN_CTRL_1_SS_SETTLE_TIME_MASK) >> PHY_BB_SS_GAIN_CTRL_1_SS_SETTLE_TIME_LSB)
#define PHY_BB_SS_GAIN_CTRL_1_SS_SETTLE_TIME_SET(x)                            (((0 | (x)) << PHY_BB_SS_GAIN_CTRL_1_SS_SETTLE_TIME_LSB) & PHY_BB_SS_GAIN_CTRL_1_SS_SETTLE_TIME_MASK)
#define PHY_BB_SS_GAIN_CTRL_1_SS_SETTLE_TIME_RESET                             0xc
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_GC_MODE_LSB                         4
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_GC_MODE_MSB                         6
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_GC_MODE_MASK                        0x70
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_GC_MODE_GET(x)                      (((x) & PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_GC_MODE_MASK) >> PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_GC_MODE_LSB)
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_GC_MODE_SET(x)                      (((0 | (x)) << PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_GC_MODE_LSB) & PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_GC_MODE_MASK)
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_GC_MODE_RESET                       0x2
#define PHY_BB_SS_GAIN_CTRL_1_SECOND_AGC_USE_16_LSB                            1
#define PHY_BB_SS_GAIN_CTRL_1_SECOND_AGC_USE_16_MSB                            1
#define PHY_BB_SS_GAIN_CTRL_1_SECOND_AGC_USE_16_MASK                           0x2
#define PHY_BB_SS_GAIN_CTRL_1_SECOND_AGC_USE_16_GET(x)                         (((x) & PHY_BB_SS_GAIN_CTRL_1_SECOND_AGC_USE_16_MASK) >> PHY_BB_SS_GAIN_CTRL_1_SECOND_AGC_USE_16_LSB)
#define PHY_BB_SS_GAIN_CTRL_1_SECOND_AGC_USE_16_SET(x)                         (((0 | (x)) << PHY_BB_SS_GAIN_CTRL_1_SECOND_AGC_USE_16_LSB) & PHY_BB_SS_GAIN_CTRL_1_SECOND_AGC_USE_16_MASK)
#define PHY_BB_SS_GAIN_CTRL_1_SECOND_AGC_USE_16_RESET                          0x0
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_ENA_LSB                             0
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_ENA_MSB                             0
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_ENA_MASK                            0x1
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_ENA_GET(x)                          (((x) & PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_ENA_MASK) >> PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_ENA_LSB)
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_ENA_SET(x)                          (((0 | (x)) << PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_ENA_LSB) & PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_ENA_MASK)
#define PHY_BB_SS_GAIN_CTRL_1_SS_GAIN_COPY_ENA_RESET                           0x1
#define PHY_BB_SS_GAIN_CTRL_1_ADDRESS                                          (0xc8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SS_GAIN_CTRL_1_RSTMASK                                          0x113f7f73
#define PHY_BB_SS_GAIN_CTRL_1_RESET                                            0xc21

// 0xcc (PHY_BB_OB_CHIRP_CTRL)
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_FFT_STR_BIN_MAG_THR_LSB                     10
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_FFT_STR_BIN_MAG_THR_MSB                     13
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_FFT_STR_BIN_MAG_THR_MASK                    0x3c00
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_FFT_STR_BIN_MAG_THR_GET(x)                  (((x) & PHY_BB_OB_CHIRP_CTRL_CHIRP_FFT_STR_BIN_MAG_THR_MASK) >> PHY_BB_OB_CHIRP_CTRL_CHIRP_FFT_STR_BIN_MAG_THR_LSB)
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_FFT_STR_BIN_MAG_THR_SET(x)                  (((0 | (x)) << PHY_BB_OB_CHIRP_CTRL_CHIRP_FFT_STR_BIN_MAG_THR_LSB) & PHY_BB_OB_CHIRP_CTRL_CHIRP_FFT_STR_BIN_MAG_THR_MASK)
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_FFT_STR_BIN_MAG_THR_RESET                   0x5
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_END_OB_BIN_NUM_LSB                          6
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_END_OB_BIN_NUM_MSB                          9
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_END_OB_BIN_NUM_MASK                         0x3c0
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_END_OB_BIN_NUM_GET(x)                       (((x) & PHY_BB_OB_CHIRP_CTRL_CHIRP_END_OB_BIN_NUM_MASK) >> PHY_BB_OB_CHIRP_CTRL_CHIRP_END_OB_BIN_NUM_LSB)
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_END_OB_BIN_NUM_SET(x)                       (((0 | (x)) << PHY_BB_OB_CHIRP_CTRL_CHIRP_END_OB_BIN_NUM_LSB) & PHY_BB_OB_CHIRP_CTRL_CHIRP_END_OB_BIN_NUM_MASK)
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_END_OB_BIN_NUM_RESET                        0x8
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_START_OB_BIN_NUM_LSB                        2
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_START_OB_BIN_NUM_MSB                        5
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_START_OB_BIN_NUM_MASK                       0x3c
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_START_OB_BIN_NUM_GET(x)                     (((x) & PHY_BB_OB_CHIRP_CTRL_CHIRP_START_OB_BIN_NUM_MASK) >> PHY_BB_OB_CHIRP_CTRL_CHIRP_START_OB_BIN_NUM_LSB)
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_START_OB_BIN_NUM_SET(x)                     (((0 | (x)) << PHY_BB_OB_CHIRP_CTRL_CHIRP_START_OB_BIN_NUM_LSB) & PHY_BB_OB_CHIRP_CTRL_CHIRP_START_OB_BIN_NUM_MASK)
#define PHY_BB_OB_CHIRP_CTRL_CHIRP_START_OB_BIN_NUM_RESET                      0x8
#define PHY_BB_OB_CHIRP_CTRL_END_OB_CHIRP_DET_ENA_LSB                          1
#define PHY_BB_OB_CHIRP_CTRL_END_OB_CHIRP_DET_ENA_MSB                          1
#define PHY_BB_OB_CHIRP_CTRL_END_OB_CHIRP_DET_ENA_MASK                         0x2
#define PHY_BB_OB_CHIRP_CTRL_END_OB_CHIRP_DET_ENA_GET(x)                       (((x) & PHY_BB_OB_CHIRP_CTRL_END_OB_CHIRP_DET_ENA_MASK) >> PHY_BB_OB_CHIRP_CTRL_END_OB_CHIRP_DET_ENA_LSB)
#define PHY_BB_OB_CHIRP_CTRL_END_OB_CHIRP_DET_ENA_SET(x)                       (((0 | (x)) << PHY_BB_OB_CHIRP_CTRL_END_OB_CHIRP_DET_ENA_LSB) & PHY_BB_OB_CHIRP_CTRL_END_OB_CHIRP_DET_ENA_MASK)
#define PHY_BB_OB_CHIRP_CTRL_END_OB_CHIRP_DET_ENA_RESET                        0x1
#define PHY_BB_OB_CHIRP_CTRL_START_OB_CHIRP_DET_ENA_LSB                        0
#define PHY_BB_OB_CHIRP_CTRL_START_OB_CHIRP_DET_ENA_MSB                        0
#define PHY_BB_OB_CHIRP_CTRL_START_OB_CHIRP_DET_ENA_MASK                       0x1
#define PHY_BB_OB_CHIRP_CTRL_START_OB_CHIRP_DET_ENA_GET(x)                     (((x) & PHY_BB_OB_CHIRP_CTRL_START_OB_CHIRP_DET_ENA_MASK) >> PHY_BB_OB_CHIRP_CTRL_START_OB_CHIRP_DET_ENA_LSB)
#define PHY_BB_OB_CHIRP_CTRL_START_OB_CHIRP_DET_ENA_SET(x)                     (((0 | (x)) << PHY_BB_OB_CHIRP_CTRL_START_OB_CHIRP_DET_ENA_LSB) & PHY_BB_OB_CHIRP_CTRL_START_OB_CHIRP_DET_ENA_MASK)
#define PHY_BB_OB_CHIRP_CTRL_START_OB_CHIRP_DET_ENA_RESET                      0x1
#define PHY_BB_OB_CHIRP_CTRL_ADDRESS                                           (0xcc + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_OB_CHIRP_CTRL_RSTMASK                                           0x3fff
#define PHY_BB_OB_CHIRP_CTRL_RESET                                             0x1623

// 0xd0 (PHY_BB_AGC_RTT_CTRL)
#define PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_EN_LSB                         18
#define PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_EN_MSB                         18
#define PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_EN_MASK                        0x40000
#define PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_EN_GET(x)                      (((x) & PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_EN_MASK) >> PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_EN_LSB)
#define PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_EN_SET(x)                      (((0 | (x)) << PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_EN_LSB) & PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_EN_MASK)
#define PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_EN_RESET                       0x0
#define PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_LSB                            16
#define PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_MSB                            17
#define PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_MASK                           0x30000
#define PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_GET(x)                         (((x) & PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_MASK) >> PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_LSB)
#define PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_SET(x)                         (((0 | (x)) << PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_LSB) & PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_MASK)
#define PHY_BB_AGC_RTT_CTRL_FIXED_STR_CHAIN_RTT_RESET                          0x0
#define PHY_BB_AGC_RTT_CTRL_RTT_CHAIN_SEL_TH_4_LSB                             0
#define PHY_BB_AGC_RTT_CTRL_RTT_CHAIN_SEL_TH_4_MSB                             9
#define PHY_BB_AGC_RTT_CTRL_RTT_CHAIN_SEL_TH_4_MASK                            0x3ff
#define PHY_BB_AGC_RTT_CTRL_RTT_CHAIN_SEL_TH_4_GET(x)                          (((x) & PHY_BB_AGC_RTT_CTRL_RTT_CHAIN_SEL_TH_4_MASK) >> PHY_BB_AGC_RTT_CTRL_RTT_CHAIN_SEL_TH_4_LSB)
#define PHY_BB_AGC_RTT_CTRL_RTT_CHAIN_SEL_TH_4_SET(x)                          (((0 | (x)) << PHY_BB_AGC_RTT_CTRL_RTT_CHAIN_SEL_TH_4_LSB) & PHY_BB_AGC_RTT_CTRL_RTT_CHAIN_SEL_TH_4_MASK)
#define PHY_BB_AGC_RTT_CTRL_RTT_CHAIN_SEL_TH_4_RESET                           0x0
#define PHY_BB_AGC_RTT_CTRL_ADDRESS                                            (0xd0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_AGC_RTT_CTRL_RSTMASK                                            0x703ff
#define PHY_BB_AGC_RTT_CTRL_RESET                                              0x0

// 0x170 (PHY_BB_RX_GAIN_NF_EN)
#define PHY_BB_RX_GAIN_NF_EN_CAPTURE_NF_GAIN_LSB                               0
#define PHY_BB_RX_GAIN_NF_EN_CAPTURE_NF_GAIN_MSB                               0
#define PHY_BB_RX_GAIN_NF_EN_CAPTURE_NF_GAIN_MASK                              0x1
#define PHY_BB_RX_GAIN_NF_EN_CAPTURE_NF_GAIN_GET(x)                            (((x) & PHY_BB_RX_GAIN_NF_EN_CAPTURE_NF_GAIN_MASK) >> PHY_BB_RX_GAIN_NF_EN_CAPTURE_NF_GAIN_LSB)
#define PHY_BB_RX_GAIN_NF_EN_CAPTURE_NF_GAIN_SET(x)                            (((0 | (x)) << PHY_BB_RX_GAIN_NF_EN_CAPTURE_NF_GAIN_LSB) & PHY_BB_RX_GAIN_NF_EN_CAPTURE_NF_GAIN_MASK)
#define PHY_BB_RX_GAIN_NF_EN_CAPTURE_NF_GAIN_RESET                             0x0
#define PHY_BB_RX_GAIN_NF_EN_ADDRESS                                           (0x170 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_GAIN_NF_EN_RSTMASK                                           0x1
#define PHY_BB_RX_GAIN_NF_EN_RESET                                             0x0

// 0x180 (PHY_BB_RSSI_B0)
#define PHY_BB_RSSI_B0_RSSI_EXT80_0_LSB                                        24
#define PHY_BB_RSSI_B0_RSSI_EXT80_0_MSB                                        31
#define PHY_BB_RSSI_B0_RSSI_EXT80_0_MASK                                       0xff000000
#define PHY_BB_RSSI_B0_RSSI_EXT80_0_GET(x)                                     (((x) & PHY_BB_RSSI_B0_RSSI_EXT80_0_MASK) >> PHY_BB_RSSI_B0_RSSI_EXT80_0_LSB)
#define PHY_BB_RSSI_B0_RSSI_EXT80_0_SET(x)                                     (((0 | (x)) << PHY_BB_RSSI_B0_RSSI_EXT80_0_LSB) & PHY_BB_RSSI_B0_RSSI_EXT80_0_MASK)
#define PHY_BB_RSSI_B0_RSSI_EXT80_0_RESET                                      0x0
#define PHY_BB_RSSI_B0_RSSI_EXT40_0_LSB                                        16
#define PHY_BB_RSSI_B0_RSSI_EXT40_0_MSB                                        23
#define PHY_BB_RSSI_B0_RSSI_EXT40_0_MASK                                       0xff0000
#define PHY_BB_RSSI_B0_RSSI_EXT40_0_GET(x)                                     (((x) & PHY_BB_RSSI_B0_RSSI_EXT40_0_MASK) >> PHY_BB_RSSI_B0_RSSI_EXT40_0_LSB)
#define PHY_BB_RSSI_B0_RSSI_EXT40_0_SET(x)                                     (((0 | (x)) << PHY_BB_RSSI_B0_RSSI_EXT40_0_LSB) & PHY_BB_RSSI_B0_RSSI_EXT40_0_MASK)
#define PHY_BB_RSSI_B0_RSSI_EXT40_0_RESET                                      0x0
#define PHY_BB_RSSI_B0_RSSI_EXT20_0_LSB                                        8
#define PHY_BB_RSSI_B0_RSSI_EXT20_0_MSB                                        15
#define PHY_BB_RSSI_B0_RSSI_EXT20_0_MASK                                       0xff00
#define PHY_BB_RSSI_B0_RSSI_EXT20_0_GET(x)                                     (((x) & PHY_BB_RSSI_B0_RSSI_EXT20_0_MASK) >> PHY_BB_RSSI_B0_RSSI_EXT20_0_LSB)
#define PHY_BB_RSSI_B0_RSSI_EXT20_0_SET(x)                                     (((0 | (x)) << PHY_BB_RSSI_B0_RSSI_EXT20_0_LSB) & PHY_BB_RSSI_B0_RSSI_EXT20_0_MASK)
#define PHY_BB_RSSI_B0_RSSI_EXT20_0_RESET                                      0x0
#define PHY_BB_RSSI_B0_RSSI_PRI20_0_LSB                                        0
#define PHY_BB_RSSI_B0_RSSI_PRI20_0_MSB                                        7
#define PHY_BB_RSSI_B0_RSSI_PRI20_0_MASK                                       0xff
#define PHY_BB_RSSI_B0_RSSI_PRI20_0_GET(x)                                     (((x) & PHY_BB_RSSI_B0_RSSI_PRI20_0_MASK) >> PHY_BB_RSSI_B0_RSSI_PRI20_0_LSB)
#define PHY_BB_RSSI_B0_RSSI_PRI20_0_SET(x)                                     (((0 | (x)) << PHY_BB_RSSI_B0_RSSI_PRI20_0_LSB) & PHY_BB_RSSI_B0_RSSI_PRI20_0_MASK)
#define PHY_BB_RSSI_B0_RSSI_PRI20_0_RESET                                      0x0
#define PHY_BB_RSSI_B0_ADDRESS                                                 (0x180 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RSSI_B0_RSTMASK                                                 0xffffffff
#define PHY_BB_RSSI_B0_RESET                                                   0x0

// 0x188 (PHY_BB_AGC_DIG_DC_STATUS_B0)
#define PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_Q_0_LSB                 10
#define PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_Q_0_MSB                 19
#define PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_Q_0_MASK                0xffc00
#define PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_Q_0_GET(x)              (((x) & PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_Q_0_MASK) >> PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_Q_0_LSB)
#define PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_Q_0_SET(x)              (((0 | (x)) << PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_Q_0_LSB) & PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_Q_0_MASK)
#define PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_Q_0_RESET               0x0
#define PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_I_0_LSB                 0
#define PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_I_0_MSB                 9
#define PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_I_0_MASK                0x3ff
#define PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_I_0_GET(x)              (((x) & PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_I_0_MASK) >> PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_I_0_LSB)
#define PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_I_0_SET(x)              (((0 | (x)) << PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_I_0_LSB) & PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_I_0_MASK)
#define PHY_BB_AGC_DIG_DC_STATUS_B0_DC_CAL_RESIDUAL_DC_I_0_RESET               0x0
#define PHY_BB_AGC_DIG_DC_STATUS_B0_ADDRESS                                    (0x188 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_AGC_DIG_DC_STATUS_B0_RSTMASK                                    0xfffff
#define PHY_BB_AGC_DIG_DC_STATUS_B0_RESET                                      0x0

// 0x1a0 (PHY_BB_DC_CAL_STATUS_B0)
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC2Q_0_LSB                                24
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC2Q_0_MSB                                31
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC2Q_0_MASK                               0xff000000
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC2Q_0_GET(x)                             (((x) & PHY_BB_DC_CAL_STATUS_B0_OFFSETC2Q_0_MASK) >> PHY_BB_DC_CAL_STATUS_B0_OFFSETC2Q_0_LSB)
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC2Q_0_SET(x)                             (((0 | (x)) << PHY_BB_DC_CAL_STATUS_B0_OFFSETC2Q_0_LSB) & PHY_BB_DC_CAL_STATUS_B0_OFFSETC2Q_0_MASK)
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC2Q_0_RESET                              0x0
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC2I_0_LSB                                16
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC2I_0_MSB                                23
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC2I_0_MASK                               0xff0000
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC2I_0_GET(x)                             (((x) & PHY_BB_DC_CAL_STATUS_B0_OFFSETC2I_0_MASK) >> PHY_BB_DC_CAL_STATUS_B0_OFFSETC2I_0_LSB)
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC2I_0_SET(x)                             (((0 | (x)) << PHY_BB_DC_CAL_STATUS_B0_OFFSETC2I_0_LSB) & PHY_BB_DC_CAL_STATUS_B0_OFFSETC2I_0_MASK)
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC2I_0_RESET                              0x0
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC1Q_0_LSB                                8
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC1Q_0_MSB                                15
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC1Q_0_MASK                               0xff00
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC1Q_0_GET(x)                             (((x) & PHY_BB_DC_CAL_STATUS_B0_OFFSETC1Q_0_MASK) >> PHY_BB_DC_CAL_STATUS_B0_OFFSETC1Q_0_LSB)
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC1Q_0_SET(x)                             (((0 | (x)) << PHY_BB_DC_CAL_STATUS_B0_OFFSETC1Q_0_LSB) & PHY_BB_DC_CAL_STATUS_B0_OFFSETC1Q_0_MASK)
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC1Q_0_RESET                              0x0
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC1I_0_LSB                                0
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC1I_0_MSB                                7
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC1I_0_MASK                               0xff
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC1I_0_GET(x)                             (((x) & PHY_BB_DC_CAL_STATUS_B0_OFFSETC1I_0_MASK) >> PHY_BB_DC_CAL_STATUS_B0_OFFSETC1I_0_LSB)
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC1I_0_SET(x)                             (((0 | (x)) << PHY_BB_DC_CAL_STATUS_B0_OFFSETC1I_0_LSB) & PHY_BB_DC_CAL_STATUS_B0_OFFSETC1I_0_MASK)
#define PHY_BB_DC_CAL_STATUS_B0_OFFSETC1I_0_RESET                              0x0
#define PHY_BB_DC_CAL_STATUS_B0_ADDRESS                                        (0x1a0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DC_CAL_STATUS_B0_RSTMASK                                        0xffffffff
#define PHY_BB_DC_CAL_STATUS_B0_RESET                                          0x0

// 0x1a4 (PHY_BB_DC_CAL_STATUS_2_B0)
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4Q_0_LSB                              24
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4Q_0_MSB                              31
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4Q_0_MASK                             0xff000000
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4Q_0_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4Q_0_MASK) >> PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4Q_0_LSB)
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4Q_0_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4Q_0_LSB) & PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4Q_0_MASK)
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4Q_0_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4I_0_LSB                              16
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4I_0_MSB                              23
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4I_0_MASK                             0xff0000
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4I_0_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4I_0_MASK) >> PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4I_0_LSB)
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4I_0_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4I_0_LSB) & PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4I_0_MASK)
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC4I_0_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3Q_0_LSB                              8
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3Q_0_MSB                              15
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3Q_0_MASK                             0xff00
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3Q_0_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3Q_0_MASK) >> PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3Q_0_LSB)
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3Q_0_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3Q_0_LSB) & PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3Q_0_MASK)
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3Q_0_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3I_0_LSB                              0
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3I_0_MSB                              7
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3I_0_MASK                             0xff
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3I_0_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3I_0_MASK) >> PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3I_0_LSB)
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3I_0_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3I_0_LSB) & PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3I_0_MASK)
#define PHY_BB_DC_CAL_STATUS_2_B0_OFFSETC3I_0_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_2_B0_ADDRESS                                      (0x1a4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DC_CAL_STATUS_2_B0_RSTMASK                                      0xffffffff
#define PHY_BB_DC_CAL_STATUS_2_B0_RESET                                        0x0

// 0x1a8 (PHY_BB_DC_CAL_STATUS_3_B0)
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6Q_0_LSB                              24
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6Q_0_MSB                              31
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6Q_0_MASK                             0xff000000
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6Q_0_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6Q_0_MASK) >> PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6Q_0_LSB)
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6Q_0_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6Q_0_LSB) & PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6Q_0_MASK)
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6Q_0_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6I_0_LSB                              16
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6I_0_MSB                              23
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6I_0_MASK                             0xff0000
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6I_0_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6I_0_MASK) >> PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6I_0_LSB)
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6I_0_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6I_0_LSB) & PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6I_0_MASK)
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC6I_0_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5Q_0_LSB                              8
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5Q_0_MSB                              15
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5Q_0_MASK                             0xff00
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5Q_0_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5Q_0_MASK) >> PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5Q_0_LSB)
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5Q_0_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5Q_0_LSB) & PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5Q_0_MASK)
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5Q_0_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5I_0_LSB                              0
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5I_0_MSB                              7
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5I_0_MASK                             0xff
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5I_0_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5I_0_MASK) >> PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5I_0_LSB)
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5I_0_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5I_0_LSB) & PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5I_0_MASK)
#define PHY_BB_DC_CAL_STATUS_3_B0_OFFSETC5I_0_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_3_B0_ADDRESS                                      (0x1a8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DC_CAL_STATUS_3_B0_RSTMASK                                      0xffffffff
#define PHY_BB_DC_CAL_STATUS_3_B0_RESET                                        0x0

// 0x1ac (PHY_BB_DC_CAL_STATUS_4_B0)
#define PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7Q_0_LSB                              8
#define PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7Q_0_MSB                              15
#define PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7Q_0_MASK                             0xff00
#define PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7Q_0_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7Q_0_MASK) >> PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7Q_0_LSB)
#define PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7Q_0_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7Q_0_LSB) & PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7Q_0_MASK)
#define PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7Q_0_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7I_0_LSB                              0
#define PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7I_0_MSB                              7
#define PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7I_0_MASK                             0xff
#define PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7I_0_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7I_0_MASK) >> PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7I_0_LSB)
#define PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7I_0_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7I_0_LSB) & PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7I_0_MASK)
#define PHY_BB_DC_CAL_STATUS_4_B0_OFFSETC7I_0_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_4_B0_ADDRESS                                      (0x1ac + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DC_CAL_STATUS_4_B0_RSTMASK                                      0xffff
#define PHY_BB_DC_CAL_STATUS_4_B0_RESET                                        0x0

// 0x1b0 (PHY_BB_RX_GAIN_NF_B0)
#define PHY_BB_RX_GAIN_NF_B0_GAIN_VAL_AFTER_NF_0_LSB                           0
#define PHY_BB_RX_GAIN_NF_B0_GAIN_VAL_AFTER_NF_0_MSB                           16
#define PHY_BB_RX_GAIN_NF_B0_GAIN_VAL_AFTER_NF_0_MASK                          0x1ffff
#define PHY_BB_RX_GAIN_NF_B0_GAIN_VAL_AFTER_NF_0_GET(x)                        (((x) & PHY_BB_RX_GAIN_NF_B0_GAIN_VAL_AFTER_NF_0_MASK) >> PHY_BB_RX_GAIN_NF_B0_GAIN_VAL_AFTER_NF_0_LSB)
#define PHY_BB_RX_GAIN_NF_B0_GAIN_VAL_AFTER_NF_0_SET(x)                        (((0 | (x)) << PHY_BB_RX_GAIN_NF_B0_GAIN_VAL_AFTER_NF_0_LSB) & PHY_BB_RX_GAIN_NF_B0_GAIN_VAL_AFTER_NF_0_MASK)
#define PHY_BB_RX_GAIN_NF_B0_GAIN_VAL_AFTER_NF_0_RESET                         0x0
#define PHY_BB_RX_GAIN_NF_B0_ADDRESS                                           (0x1b0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_GAIN_NF_B0_RSTMASK                                           0x1ffff
#define PHY_BB_RX_GAIN_NF_B0_RESET                                             0x0

// 0x1c0 (PHY_BB_BBB_SIG_DETECT)
#define PHY_BB_BBB_SIG_DETECT_DISABLE_STR_CHAIN_SEL_CCK_LSB                    31
#define PHY_BB_BBB_SIG_DETECT_DISABLE_STR_CHAIN_SEL_CCK_MSB                    31
#define PHY_BB_BBB_SIG_DETECT_DISABLE_STR_CHAIN_SEL_CCK_MASK                   0x80000000
#define PHY_BB_BBB_SIG_DETECT_DISABLE_STR_CHAIN_SEL_CCK_GET(x)                 (((x) & PHY_BB_BBB_SIG_DETECT_DISABLE_STR_CHAIN_SEL_CCK_MASK) >> PHY_BB_BBB_SIG_DETECT_DISABLE_STR_CHAIN_SEL_CCK_LSB)
#define PHY_BB_BBB_SIG_DETECT_DISABLE_STR_CHAIN_SEL_CCK_SET(x)                 (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_DISABLE_STR_CHAIN_SEL_CCK_LSB) & PHY_BB_BBB_SIG_DETECT_DISABLE_STR_CHAIN_SEL_CCK_MASK)
#define PHY_BB_BBB_SIG_DETECT_DISABLE_STR_CHAIN_SEL_CCK_RESET                  0x0
#define PHY_BB_BBB_SIG_DETECT_ENA_DC_EST_BCORR_LSB                             30
#define PHY_BB_BBB_SIG_DETECT_ENA_DC_EST_BCORR_MSB                             30
#define PHY_BB_BBB_SIG_DETECT_ENA_DC_EST_BCORR_MASK                            0x40000000
#define PHY_BB_BBB_SIG_DETECT_ENA_DC_EST_BCORR_GET(x)                          (((x) & PHY_BB_BBB_SIG_DETECT_ENA_DC_EST_BCORR_MASK) >> PHY_BB_BBB_SIG_DETECT_ENA_DC_EST_BCORR_LSB)
#define PHY_BB_BBB_SIG_DETECT_ENA_DC_EST_BCORR_SET(x)                          (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_ENA_DC_EST_BCORR_LSB) & PHY_BB_BBB_SIG_DETECT_ENA_DC_EST_BCORR_MASK)
#define PHY_BB_BBB_SIG_DETECT_ENA_DC_EST_BCORR_RESET                           0x0
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_DCOFF_CCK_LSB                        29
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_DCOFF_CCK_MSB                        29
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_DCOFF_CCK_MASK                       0x20000000
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_DCOFF_CCK_GET(x)                     (((x) & PHY_BB_BBB_SIG_DETECT_DELAY_START_DCOFF_CCK_MASK) >> PHY_BB_BBB_SIG_DETECT_DELAY_START_DCOFF_CCK_LSB)
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_DCOFF_CCK_SET(x)                     (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_DELAY_START_DCOFF_CCK_LSB) & PHY_BB_BBB_SIG_DETECT_DELAY_START_DCOFF_CCK_MASK)
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_DCOFF_CCK_RESET                      0x0
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_SPUR_CCK_LSB                         28
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_SPUR_CCK_MSB                         28
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_SPUR_CCK_MASK                        0x10000000
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_SPUR_CCK_GET(x)                      (((x) & PHY_BB_BBB_SIG_DETECT_DELAY_START_SPUR_CCK_MASK) >> PHY_BB_BBB_SIG_DETECT_DELAY_START_SPUR_CCK_LSB)
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_SPUR_CCK_SET(x)                      (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_DELAY_START_SPUR_CCK_LSB) & PHY_BB_BBB_SIG_DETECT_DELAY_START_SPUR_CCK_MASK)
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_SPUR_CCK_RESET                       0x0
#define PHY_BB_BBB_SIG_DETECT_START_DCOFF_PRIORITY_CCK_LSB                     27
#define PHY_BB_BBB_SIG_DETECT_START_DCOFF_PRIORITY_CCK_MSB                     27
#define PHY_BB_BBB_SIG_DETECT_START_DCOFF_PRIORITY_CCK_MASK                    0x8000000
#define PHY_BB_BBB_SIG_DETECT_START_DCOFF_PRIORITY_CCK_GET(x)                  (((x) & PHY_BB_BBB_SIG_DETECT_START_DCOFF_PRIORITY_CCK_MASK) >> PHY_BB_BBB_SIG_DETECT_START_DCOFF_PRIORITY_CCK_LSB)
#define PHY_BB_BBB_SIG_DETECT_START_DCOFF_PRIORITY_CCK_SET(x)                  (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_START_DCOFF_PRIORITY_CCK_LSB) & PHY_BB_BBB_SIG_DETECT_START_DCOFF_PRIORITY_CCK_MASK)
#define PHY_BB_BBB_SIG_DETECT_START_DCOFF_PRIORITY_CCK_RESET                   0x0
#define PHY_BB_BBB_SIG_DETECT_USE_DC_EST_DURING_SRCH_LSB                       26
#define PHY_BB_BBB_SIG_DETECT_USE_DC_EST_DURING_SRCH_MSB                       26
#define PHY_BB_BBB_SIG_DETECT_USE_DC_EST_DURING_SRCH_MASK                      0x4000000
#define PHY_BB_BBB_SIG_DETECT_USE_DC_EST_DURING_SRCH_GET(x)                    (((x) & PHY_BB_BBB_SIG_DETECT_USE_DC_EST_DURING_SRCH_MASK) >> PHY_BB_BBB_SIG_DETECT_USE_DC_EST_DURING_SRCH_LSB)
#define PHY_BB_BBB_SIG_DETECT_USE_DC_EST_DURING_SRCH_SET(x)                    (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_USE_DC_EST_DURING_SRCH_LSB) & PHY_BB_BBB_SIG_DETECT_USE_DC_EST_DURING_SRCH_MASK)
#define PHY_BB_BBB_SIG_DETECT_USE_DC_EST_DURING_SRCH_RESET                     0x0
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_SYNC_CCK_LSB                         25
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_SYNC_CCK_MSB                         25
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_SYNC_CCK_MASK                        0x2000000
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_SYNC_CCK_GET(x)                      (((x) & PHY_BB_BBB_SIG_DETECT_DELAY_START_SYNC_CCK_MASK) >> PHY_BB_BBB_SIG_DETECT_DELAY_START_SYNC_CCK_LSB)
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_SYNC_CCK_SET(x)                      (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_DELAY_START_SYNC_CCK_LSB) & PHY_BB_BBB_SIG_DETECT_DELAY_START_SYNC_CCK_MASK)
#define PHY_BB_BBB_SIG_DETECT_DELAY_START_SYNC_CCK_RESET                       0x0
#define PHY_BB_BBB_SIG_DETECT_ENABLE_FINE_DC_CCK_LSB                           24
#define PHY_BB_BBB_SIG_DETECT_ENABLE_FINE_DC_CCK_MSB                           24
#define PHY_BB_BBB_SIG_DETECT_ENABLE_FINE_DC_CCK_MASK                          0x1000000
#define PHY_BB_BBB_SIG_DETECT_ENABLE_FINE_DC_CCK_GET(x)                        (((x) & PHY_BB_BBB_SIG_DETECT_ENABLE_FINE_DC_CCK_MASK) >> PHY_BB_BBB_SIG_DETECT_ENABLE_FINE_DC_CCK_LSB)
#define PHY_BB_BBB_SIG_DETECT_ENABLE_FINE_DC_CCK_SET(x)                        (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_ENABLE_FINE_DC_CCK_LSB) & PHY_BB_BBB_SIG_DETECT_ENABLE_FINE_DC_CCK_MASK)
#define PHY_BB_BBB_SIG_DETECT_ENABLE_FINE_DC_CCK_RESET                         0x0
#define PHY_BB_BBB_SIG_DETECT_CYC256_FINE_DC_EST_CCK_LSB                       23
#define PHY_BB_BBB_SIG_DETECT_CYC256_FINE_DC_EST_CCK_MSB                       23
#define PHY_BB_BBB_SIG_DETECT_CYC256_FINE_DC_EST_CCK_MASK                      0x800000
#define PHY_BB_BBB_SIG_DETECT_CYC256_FINE_DC_EST_CCK_GET(x)                    (((x) & PHY_BB_BBB_SIG_DETECT_CYC256_FINE_DC_EST_CCK_MASK) >> PHY_BB_BBB_SIG_DETECT_CYC256_FINE_DC_EST_CCK_LSB)
#define PHY_BB_BBB_SIG_DETECT_CYC256_FINE_DC_EST_CCK_SET(x)                    (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_CYC256_FINE_DC_EST_CCK_LSB) & PHY_BB_BBB_SIG_DETECT_CYC256_FINE_DC_EST_CCK_MASK)
#define PHY_BB_BBB_SIG_DETECT_CYC256_FINE_DC_EST_CCK_RESET                     0x0
#define PHY_BB_BBB_SIG_DETECT_ENABLE_COARSE_DC_CCK_LSB                         22
#define PHY_BB_BBB_SIG_DETECT_ENABLE_COARSE_DC_CCK_MSB                         22
#define PHY_BB_BBB_SIG_DETECT_ENABLE_COARSE_DC_CCK_MASK                        0x400000
#define PHY_BB_BBB_SIG_DETECT_ENABLE_COARSE_DC_CCK_GET(x)                      (((x) & PHY_BB_BBB_SIG_DETECT_ENABLE_COARSE_DC_CCK_MASK) >> PHY_BB_BBB_SIG_DETECT_ENABLE_COARSE_DC_CCK_LSB)
#define PHY_BB_BBB_SIG_DETECT_ENABLE_COARSE_DC_CCK_SET(x)                      (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_ENABLE_COARSE_DC_CCK_LSB) & PHY_BB_BBB_SIG_DETECT_ENABLE_COARSE_DC_CCK_MASK)
#define PHY_BB_BBB_SIG_DETECT_ENABLE_COARSE_DC_CCK_RESET                       0x0
#define PHY_BB_BBB_SIG_DETECT_CYC64_COARSE_DC_EST_CCK_LSB                      21
#define PHY_BB_BBB_SIG_DETECT_CYC64_COARSE_DC_EST_CCK_MSB                      21
#define PHY_BB_BBB_SIG_DETECT_CYC64_COARSE_DC_EST_CCK_MASK                     0x200000
#define PHY_BB_BBB_SIG_DETECT_CYC64_COARSE_DC_EST_CCK_GET(x)                   (((x) & PHY_BB_BBB_SIG_DETECT_CYC64_COARSE_DC_EST_CCK_MASK) >> PHY_BB_BBB_SIG_DETECT_CYC64_COARSE_DC_EST_CCK_LSB)
#define PHY_BB_BBB_SIG_DETECT_CYC64_COARSE_DC_EST_CCK_SET(x)                   (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_CYC64_COARSE_DC_EST_CCK_LSB) & PHY_BB_BBB_SIG_DETECT_CYC64_COARSE_DC_EST_CCK_MASK)
#define PHY_BB_BBB_SIG_DETECT_CYC64_COARSE_DC_EST_CCK_RESET                    0x0
#define PHY_BB_BBB_SIG_DETECT_CYC32_COARSE_DC_EST_CCK_LSB                      20
#define PHY_BB_BBB_SIG_DETECT_CYC32_COARSE_DC_EST_CCK_MSB                      20
#define PHY_BB_BBB_SIG_DETECT_CYC32_COARSE_DC_EST_CCK_MASK                     0x100000
#define PHY_BB_BBB_SIG_DETECT_CYC32_COARSE_DC_EST_CCK_GET(x)                   (((x) & PHY_BB_BBB_SIG_DETECT_CYC32_COARSE_DC_EST_CCK_MASK) >> PHY_BB_BBB_SIG_DETECT_CYC32_COARSE_DC_EST_CCK_LSB)
#define PHY_BB_BBB_SIG_DETECT_CYC32_COARSE_DC_EST_CCK_SET(x)                   (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_CYC32_COARSE_DC_EST_CCK_LSB) & PHY_BB_BBB_SIG_DETECT_CYC32_COARSE_DC_EST_CCK_MASK)
#define PHY_BB_BBB_SIG_DETECT_CYC32_COARSE_DC_EST_CCK_RESET                    0x0
#define PHY_BB_BBB_SIG_DETECT_ANT_SWITCH_TIME_LSB                              13
#define PHY_BB_BBB_SIG_DETECT_ANT_SWITCH_TIME_MSB                              19
#define PHY_BB_BBB_SIG_DETECT_ANT_SWITCH_TIME_MASK                             0xfe000
#define PHY_BB_BBB_SIG_DETECT_ANT_SWITCH_TIME_GET(x)                           (((x) & PHY_BB_BBB_SIG_DETECT_ANT_SWITCH_TIME_MASK) >> PHY_BB_BBB_SIG_DETECT_ANT_SWITCH_TIME_LSB)
#define PHY_BB_BBB_SIG_DETECT_ANT_SWITCH_TIME_SET(x)                           (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_ANT_SWITCH_TIME_LSB) & PHY_BB_BBB_SIG_DETECT_ANT_SWITCH_TIME_MASK)
#define PHY_BB_BBB_SIG_DETECT_ANT_SWITCH_TIME_RESET                            0x0
#define PHY_BB_BBB_SIG_DETECT_AGCREG_CHANNEL_FREQ_LSB                          0
#define PHY_BB_BBB_SIG_DETECT_AGCREG_CHANNEL_FREQ_MSB                          12
#define PHY_BB_BBB_SIG_DETECT_AGCREG_CHANNEL_FREQ_MASK                         0x1fff
#define PHY_BB_BBB_SIG_DETECT_AGCREG_CHANNEL_FREQ_GET(x)                       (((x) & PHY_BB_BBB_SIG_DETECT_AGCREG_CHANNEL_FREQ_MASK) >> PHY_BB_BBB_SIG_DETECT_AGCREG_CHANNEL_FREQ_LSB)
#define PHY_BB_BBB_SIG_DETECT_AGCREG_CHANNEL_FREQ_SET(x)                       (((0 | (x)) << PHY_BB_BBB_SIG_DETECT_AGCREG_CHANNEL_FREQ_LSB) & PHY_BB_BBB_SIG_DETECT_AGCREG_CHANNEL_FREQ_MASK)
#define PHY_BB_BBB_SIG_DETECT_AGCREG_CHANNEL_FREQ_RESET                        0x0
#define PHY_BB_BBB_SIG_DETECT_ADDRESS                                          (0x1c0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_BBB_SIG_DETECT_RSTMASK                                          0xffffffff
#define PHY_BB_BBB_SIG_DETECT_RESET                                            0x0

// 0x1c4 (PHY_BB_BBB_DAGC_CTRL)
#define PHY_BB_BBB_DAGC_CTRL_BK_IN_SCALE_COARSE_LSB                            30
#define PHY_BB_BBB_DAGC_CTRL_BK_IN_SCALE_COARSE_MSB                            31
#define PHY_BB_BBB_DAGC_CTRL_BK_IN_SCALE_COARSE_MASK                           0xc0000000
#define PHY_BB_BBB_DAGC_CTRL_BK_IN_SCALE_COARSE_GET(x)                         (((x) & PHY_BB_BBB_DAGC_CTRL_BK_IN_SCALE_COARSE_MASK) >> PHY_BB_BBB_DAGC_CTRL_BK_IN_SCALE_COARSE_LSB)
#define PHY_BB_BBB_DAGC_CTRL_BK_IN_SCALE_COARSE_SET(x)                         (((0 | (x)) << PHY_BB_BBB_DAGC_CTRL_BK_IN_SCALE_COARSE_LSB) & PHY_BB_BBB_DAGC_CTRL_BK_IN_SCALE_COARSE_MASK)
#define PHY_BB_BBB_DAGC_CTRL_BK_IN_SCALE_COARSE_RESET                          0x0
#define PHY_BB_BBB_DAGC_CTRL_RXB_DET_STRONG_CHN_DEFAULT_LSB                    28
#define PHY_BB_BBB_DAGC_CTRL_RXB_DET_STRONG_CHN_DEFAULT_MSB                    29
#define PHY_BB_BBB_DAGC_CTRL_RXB_DET_STRONG_CHN_DEFAULT_MASK                   0x30000000
#define PHY_BB_BBB_DAGC_CTRL_RXB_DET_STRONG_CHN_DEFAULT_GET(x)                 (((x) & PHY_BB_BBB_DAGC_CTRL_RXB_DET_STRONG_CHN_DEFAULT_MASK) >> PHY_BB_BBB_DAGC_CTRL_RXB_DET_STRONG_CHN_DEFAULT_LSB)
#define PHY_BB_BBB_DAGC_CTRL_RXB_DET_STRONG_CHN_DEFAULT_SET(x)                 (((0 | (x)) << PHY_BB_BBB_DAGC_CTRL_RXB_DET_STRONG_CHN_DEFAULT_LSB) & PHY_BB_BBB_DAGC_CTRL_RXB_DET_STRONG_CHN_DEFAULT_MASK)
#define PHY_BB_BBB_DAGC_CTRL_RXB_DET_STRONG_CHN_DEFAULT_RESET                  0x0
#define PHY_BB_BBB_DAGC_CTRL_FIRSTEP_COUNT_LGMAX_LSB                           24
#define PHY_BB_BBB_DAGC_CTRL_FIRSTEP_COUNT_LGMAX_MSB                           27
#define PHY_BB_BBB_DAGC_CTRL_FIRSTEP_COUNT_LGMAX_MASK                          0xf000000
#define PHY_BB_BBB_DAGC_CTRL_FIRSTEP_COUNT_LGMAX_GET(x)                        (((x) & PHY_BB_BBB_DAGC_CTRL_FIRSTEP_COUNT_LGMAX_MASK) >> PHY_BB_BBB_DAGC_CTRL_FIRSTEP_COUNT_LGMAX_LSB)
#define PHY_BB_BBB_DAGC_CTRL_FIRSTEP_COUNT_LGMAX_SET(x)                        (((0 | (x)) << PHY_BB_BBB_DAGC_CTRL_FIRSTEP_COUNT_LGMAX_LSB) & PHY_BB_BBB_DAGC_CTRL_FIRSTEP_COUNT_LGMAX_MASK)
#define PHY_BB_BBB_DAGC_CTRL_FIRSTEP_COUNT_LGMAX_RESET                         0x0
#define PHY_BB_BBB_DAGC_CTRL_FIRSTEP_2_LSB                                     18
#define PHY_BB_BBB_DAGC_CTRL_FIRSTEP_2_MSB                                     23
#define PHY_BB_BBB_DAGC_CTRL_FIRSTEP_2_MASK                                    0xfc0000
#define PHY_BB_BBB_DAGC_CTRL_FIRSTEP_2_GET(x)                                  (((x) & PHY_BB_BBB_DAGC_CTRL_FIRSTEP_2_MASK) >> PHY_BB_BBB_DAGC_CTRL_FIRSTEP_2_LSB)
#define PHY_BB_BBB_DAGC_CTRL_FIRSTEP_2_SET(x)                                  (((0 | (x)) << PHY_BB_BBB_DAGC_CTRL_FIRSTEP_2_LSB) & PHY_BB_BBB_DAGC_CTRL_FIRSTEP_2_MASK)
#define PHY_BB_BBB_DAGC_CTRL_FIRSTEP_2_RESET                                   0xc
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_FIRSTEP_SEL_LSB                            17
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_FIRSTEP_SEL_MSB                            17
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_FIRSTEP_SEL_MASK                           0x20000
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_FIRSTEP_SEL_GET(x)                         (((x) & PHY_BB_BBB_DAGC_CTRL_ENABLE_FIRSTEP_SEL_MASK) >> PHY_BB_BBB_DAGC_CTRL_ENABLE_FIRSTEP_SEL_LSB)
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_FIRSTEP_SEL_SET(x)                         (((0 | (x)) << PHY_BB_BBB_DAGC_CTRL_ENABLE_FIRSTEP_SEL_LSB) & PHY_BB_BBB_DAGC_CTRL_ENABLE_FIRSTEP_SEL_MASK)
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_FIRSTEP_SEL_RESET                          0x0
#define PHY_BB_BBB_DAGC_CTRL_BARKER_RSSI_THR_LSB                               10
#define PHY_BB_BBB_DAGC_CTRL_BARKER_RSSI_THR_MSB                               16
#define PHY_BB_BBB_DAGC_CTRL_BARKER_RSSI_THR_MASK                              0x1fc00
#define PHY_BB_BBB_DAGC_CTRL_BARKER_RSSI_THR_GET(x)                            (((x) & PHY_BB_BBB_DAGC_CTRL_BARKER_RSSI_THR_MASK) >> PHY_BB_BBB_DAGC_CTRL_BARKER_RSSI_THR_LSB)
#define PHY_BB_BBB_DAGC_CTRL_BARKER_RSSI_THR_SET(x)                            (((0 | (x)) << PHY_BB_BBB_DAGC_CTRL_BARKER_RSSI_THR_LSB) & PHY_BB_BBB_DAGC_CTRL_BARKER_RSSI_THR_MASK)
#define PHY_BB_BBB_DAGC_CTRL_BARKER_RSSI_THR_RESET                             0x0
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_BARKER_RSSI_THR_LSB                        9
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_BARKER_RSSI_THR_MSB                        9
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_BARKER_RSSI_THR_MASK                       0x200
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_BARKER_RSSI_THR_GET(x)                     (((x) & PHY_BB_BBB_DAGC_CTRL_ENABLE_BARKER_RSSI_THR_MASK) >> PHY_BB_BBB_DAGC_CTRL_ENABLE_BARKER_RSSI_THR_LSB)
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_BARKER_RSSI_THR_SET(x)                     (((0 | (x)) << PHY_BB_BBB_DAGC_CTRL_ENABLE_BARKER_RSSI_THR_LSB) & PHY_BB_BBB_DAGC_CTRL_ENABLE_BARKER_RSSI_THR_MASK)
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_BARKER_RSSI_THR_RESET                      0x0
#define PHY_BB_BBB_DAGC_CTRL_DAGC_TARGET_PWR_CCK_LSB                           1
#define PHY_BB_BBB_DAGC_CTRL_DAGC_TARGET_PWR_CCK_MSB                           8
#define PHY_BB_BBB_DAGC_CTRL_DAGC_TARGET_PWR_CCK_MASK                          0x1fe
#define PHY_BB_BBB_DAGC_CTRL_DAGC_TARGET_PWR_CCK_GET(x)                        (((x) & PHY_BB_BBB_DAGC_CTRL_DAGC_TARGET_PWR_CCK_MASK) >> PHY_BB_BBB_DAGC_CTRL_DAGC_TARGET_PWR_CCK_LSB)
#define PHY_BB_BBB_DAGC_CTRL_DAGC_TARGET_PWR_CCK_SET(x)                        (((0 | (x)) << PHY_BB_BBB_DAGC_CTRL_DAGC_TARGET_PWR_CCK_LSB) & PHY_BB_BBB_DAGC_CTRL_DAGC_TARGET_PWR_CCK_MASK)
#define PHY_BB_BBB_DAGC_CTRL_DAGC_TARGET_PWR_CCK_RESET                         0x0
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_DAGC_CCK_LSB                               0
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_DAGC_CCK_MSB                               0
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_DAGC_CCK_MASK                              0x1
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_DAGC_CCK_GET(x)                            (((x) & PHY_BB_BBB_DAGC_CTRL_ENABLE_DAGC_CCK_MASK) >> PHY_BB_BBB_DAGC_CTRL_ENABLE_DAGC_CCK_LSB)
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_DAGC_CCK_SET(x)                            (((0 | (x)) << PHY_BB_BBB_DAGC_CTRL_ENABLE_DAGC_CCK_LSB) & PHY_BB_BBB_DAGC_CTRL_ENABLE_DAGC_CCK_MASK)
#define PHY_BB_BBB_DAGC_CTRL_ENABLE_DAGC_CCK_RESET                             0x0
#define PHY_BB_BBB_DAGC_CTRL_ADDRESS                                           (0x1c4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_BBB_DAGC_CTRL_RSTMASK                                           0xffffffff
#define PHY_BB_BBB_DAGC_CTRL_RESET                                             0x300000

// 0x1c8 (PHY_BB_IQCORR_CTRL_CCK)
#define PHY_BB_IQCORR_CTRL_CCK_CF_CLC_INIT_RFGAIN_LSB                          16
#define PHY_BB_IQCORR_CTRL_CCK_CF_CLC_INIT_RFGAIN_MSB                          20
#define PHY_BB_IQCORR_CTRL_CCK_CF_CLC_INIT_RFGAIN_MASK                         0x1f0000
#define PHY_BB_IQCORR_CTRL_CCK_CF_CLC_INIT_RFGAIN_GET(x)                       (((x) & PHY_BB_IQCORR_CTRL_CCK_CF_CLC_INIT_RFGAIN_MASK) >> PHY_BB_IQCORR_CTRL_CCK_CF_CLC_INIT_RFGAIN_LSB)
#define PHY_BB_IQCORR_CTRL_CCK_CF_CLC_INIT_RFGAIN_SET(x)                       (((0 | (x)) << PHY_BB_IQCORR_CTRL_CCK_CF_CLC_INIT_RFGAIN_LSB) & PHY_BB_IQCORR_CTRL_CCK_CF_CLC_INIT_RFGAIN_MASK)
#define PHY_BB_IQCORR_CTRL_CCK_CF_CLC_INIT_RFGAIN_RESET                        0x2
#define PHY_BB_IQCORR_CTRL_CCK_CLCAL_MEAS_TIME_SEL_LSB                         14
#define PHY_BB_IQCORR_CTRL_CCK_CLCAL_MEAS_TIME_SEL_MSB                         15
#define PHY_BB_IQCORR_CTRL_CCK_CLCAL_MEAS_TIME_SEL_MASK                        0xc000
#define PHY_BB_IQCORR_CTRL_CCK_CLCAL_MEAS_TIME_SEL_GET(x)                      (((x) & PHY_BB_IQCORR_CTRL_CCK_CLCAL_MEAS_TIME_SEL_MASK) >> PHY_BB_IQCORR_CTRL_CCK_CLCAL_MEAS_TIME_SEL_LSB)
#define PHY_BB_IQCORR_CTRL_CCK_CLCAL_MEAS_TIME_SEL_SET(x)                      (((0 | (x)) << PHY_BB_IQCORR_CTRL_CCK_CLCAL_MEAS_TIME_SEL_LSB) & PHY_BB_IQCORR_CTRL_CCK_CLCAL_MEAS_TIME_SEL_MASK)
#define PHY_BB_IQCORR_CTRL_CCK_CLCAL_MEAS_TIME_SEL_RESET                       0x2
#define PHY_BB_IQCORR_CTRL_CCK_RXCAL_MEAS_TIME_SEL_LSB                         12
#define PHY_BB_IQCORR_CTRL_CCK_RXCAL_MEAS_TIME_SEL_MSB                         13
#define PHY_BB_IQCORR_CTRL_CCK_RXCAL_MEAS_TIME_SEL_MASK                        0x3000
#define PHY_BB_IQCORR_CTRL_CCK_RXCAL_MEAS_TIME_SEL_GET(x)                      (((x) & PHY_BB_IQCORR_CTRL_CCK_RXCAL_MEAS_TIME_SEL_MASK) >> PHY_BB_IQCORR_CTRL_CCK_RXCAL_MEAS_TIME_SEL_LSB)
#define PHY_BB_IQCORR_CTRL_CCK_RXCAL_MEAS_TIME_SEL_SET(x)                      (((0 | (x)) << PHY_BB_IQCORR_CTRL_CCK_RXCAL_MEAS_TIME_SEL_LSB) & PHY_BB_IQCORR_CTRL_CCK_RXCAL_MEAS_TIME_SEL_MASK)
#define PHY_BB_IQCORR_CTRL_CCK_RXCAL_MEAS_TIME_SEL_RESET                       0x2
#define PHY_BB_IQCORR_CTRL_CCK_ADDRESS                                         (0x1c8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_IQCORR_CTRL_CCK_RSTMASK                                         0x1ff000
#define PHY_BB_IQCORR_CTRL_CCK_RESET                                           0x2a000

// 0x1cc (PHY_BB_CCK_SPUR_MIT)
#define PHY_BB_CCK_SPUR_MIT_SPUR_FILTER_TYPE_LSB                               29
#define PHY_BB_CCK_SPUR_MIT_SPUR_FILTER_TYPE_MSB                               30
#define PHY_BB_CCK_SPUR_MIT_SPUR_FILTER_TYPE_MASK                              0x60000000
#define PHY_BB_CCK_SPUR_MIT_SPUR_FILTER_TYPE_GET(x)                            (((x) & PHY_BB_CCK_SPUR_MIT_SPUR_FILTER_TYPE_MASK) >> PHY_BB_CCK_SPUR_MIT_SPUR_FILTER_TYPE_LSB)
#define PHY_BB_CCK_SPUR_MIT_SPUR_FILTER_TYPE_SET(x)                            (((0 | (x)) << PHY_BB_CCK_SPUR_MIT_SPUR_FILTER_TYPE_LSB) & PHY_BB_CCK_SPUR_MIT_SPUR_FILTER_TYPE_MASK)
#define PHY_BB_CCK_SPUR_MIT_SPUR_FILTER_TYPE_RESET                             0x0
#define PHY_BB_CCK_SPUR_MIT_CCK_SPUR_FREQ_LSB                                  9
#define PHY_BB_CCK_SPUR_MIT_CCK_SPUR_FREQ_MSB                                  28
#define PHY_BB_CCK_SPUR_MIT_CCK_SPUR_FREQ_MASK                                 0x1ffffe00
#define PHY_BB_CCK_SPUR_MIT_CCK_SPUR_FREQ_GET(x)                               (((x) & PHY_BB_CCK_SPUR_MIT_CCK_SPUR_FREQ_MASK) >> PHY_BB_CCK_SPUR_MIT_CCK_SPUR_FREQ_LSB)
#define PHY_BB_CCK_SPUR_MIT_CCK_SPUR_FREQ_SET(x)                               (((0 | (x)) << PHY_BB_CCK_SPUR_MIT_CCK_SPUR_FREQ_LSB) & PHY_BB_CCK_SPUR_MIT_CCK_SPUR_FREQ_MASK)
#define PHY_BB_CCK_SPUR_MIT_CCK_SPUR_FREQ_RESET                                0x0
#define PHY_BB_CCK_SPUR_MIT_SPUR_RSSI_THR_LSB                                  1
#define PHY_BB_CCK_SPUR_MIT_SPUR_RSSI_THR_MSB                                  8
#define PHY_BB_CCK_SPUR_MIT_SPUR_RSSI_THR_MASK                                 0x1fe
#define PHY_BB_CCK_SPUR_MIT_SPUR_RSSI_THR_GET(x)                               (((x) & PHY_BB_CCK_SPUR_MIT_SPUR_RSSI_THR_MASK) >> PHY_BB_CCK_SPUR_MIT_SPUR_RSSI_THR_LSB)
#define PHY_BB_CCK_SPUR_MIT_SPUR_RSSI_THR_SET(x)                               (((0 | (x)) << PHY_BB_CCK_SPUR_MIT_SPUR_RSSI_THR_LSB) & PHY_BB_CCK_SPUR_MIT_SPUR_RSSI_THR_MASK)
#define PHY_BB_CCK_SPUR_MIT_SPUR_RSSI_THR_RESET                                0x0
#define PHY_BB_CCK_SPUR_MIT_USE_CCK_SPUR_MIT_LSB                               0
#define PHY_BB_CCK_SPUR_MIT_USE_CCK_SPUR_MIT_MSB                               0
#define PHY_BB_CCK_SPUR_MIT_USE_CCK_SPUR_MIT_MASK                              0x1
#define PHY_BB_CCK_SPUR_MIT_USE_CCK_SPUR_MIT_GET(x)                            (((x) & PHY_BB_CCK_SPUR_MIT_USE_CCK_SPUR_MIT_MASK) >> PHY_BB_CCK_SPUR_MIT_USE_CCK_SPUR_MIT_LSB)
#define PHY_BB_CCK_SPUR_MIT_USE_CCK_SPUR_MIT_SET(x)                            (((0 | (x)) << PHY_BB_CCK_SPUR_MIT_USE_CCK_SPUR_MIT_LSB) & PHY_BB_CCK_SPUR_MIT_USE_CCK_SPUR_MIT_MASK)
#define PHY_BB_CCK_SPUR_MIT_USE_CCK_SPUR_MIT_RESET                             0x0
#define PHY_BB_CCK_SPUR_MIT_ADDRESS                                            (0x1cc + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CCK_SPUR_MIT_RSTMASK                                            0x7fffffff
#define PHY_BB_CCK_SPUR_MIT_RESET                                              0x0

// 0x1d0 (PHY_BB_MRC_CCK_CTRL)
#define PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_TF_EST_LSB                          24
#define PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_TF_EST_MSB                          31
#define PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_TF_EST_MASK                         0xff000000
#define PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_TF_EST_GET(x)                       (((x) & PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_TF_EST_MASK) >> PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_TF_EST_LSB)
#define PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_TF_EST_SET(x)                       (((0 | (x)) << PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_TF_EST_LSB) & PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_TF_EST_MASK)
#define PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_TF_EST_RESET                        0x0
#define PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_LSB                                 16
#define PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_MSB                                 23
#define PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_MASK                                0xff0000
#define PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_GET(x)                              (((x) & PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_MASK) >> PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_LSB)
#define PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_SET(x)                              (((0 | (x)) << PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_LSB) & PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_MASK)
#define PHY_BB_MRC_CCK_CTRL_AGCREG_TH_D0_B_RESET                               0x0
#define PHY_BB_MRC_CCK_CTRL_AGCREG_C11BP_LSB                                   8
#define PHY_BB_MRC_CCK_CTRL_AGCREG_C11BP_MSB                                   15
#define PHY_BB_MRC_CCK_CTRL_AGCREG_C11BP_MASK                                  0xff00
#define PHY_BB_MRC_CCK_CTRL_AGCREG_C11BP_GET(x)                                (((x) & PHY_BB_MRC_CCK_CTRL_AGCREG_C11BP_MASK) >> PHY_BB_MRC_CCK_CTRL_AGCREG_C11BP_LSB)
#define PHY_BB_MRC_CCK_CTRL_AGCREG_C11BP_SET(x)                                (((0 | (x)) << PHY_BB_MRC_CCK_CTRL_AGCREG_C11BP_LSB) & PHY_BB_MRC_CCK_CTRL_AGCREG_C11BP_MASK)
#define PHY_BB_MRC_CCK_CTRL_AGCREG_C11BP_RESET                                 0x0
#define PHY_BB_MRC_CCK_CTRL_AGCREG_C11B_LSB                                    0
#define PHY_BB_MRC_CCK_CTRL_AGCREG_C11B_MSB                                    7
#define PHY_BB_MRC_CCK_CTRL_AGCREG_C11B_MASK                                   0xff
#define PHY_BB_MRC_CCK_CTRL_AGCREG_C11B_GET(x)                                 (((x) & PHY_BB_MRC_CCK_CTRL_AGCREG_C11B_MASK) >> PHY_BB_MRC_CCK_CTRL_AGCREG_C11B_LSB)
#define PHY_BB_MRC_CCK_CTRL_AGCREG_C11B_SET(x)                                 (((0 | (x)) << PHY_BB_MRC_CCK_CTRL_AGCREG_C11B_LSB) & PHY_BB_MRC_CCK_CTRL_AGCREG_C11B_MASK)
#define PHY_BB_MRC_CCK_CTRL_AGCREG_C11B_RESET                                  0x0
#define PHY_BB_MRC_CCK_CTRL_ADDRESS                                            (0x1d0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_MRC_CCK_CTRL_RSTMASK                                            0xffffffff
#define PHY_BB_MRC_CCK_CTRL_RESET                                              0x0

// 0x1d4 (PHY_BB_CCK_BLOCKER_DET)
#define PHY_BB_CCK_BLOCKER_DET_CCK_DET_RAMP_THR_LSB                            27
#define PHY_BB_CCK_BLOCKER_DET_CCK_DET_RAMP_THR_MSB                            31
#define PHY_BB_CCK_BLOCKER_DET_CCK_DET_RAMP_THR_MASK                           0xf8000000
#define PHY_BB_CCK_BLOCKER_DET_CCK_DET_RAMP_THR_GET(x)                         (((x) & PHY_BB_CCK_BLOCKER_DET_CCK_DET_RAMP_THR_MASK) >> PHY_BB_CCK_BLOCKER_DET_CCK_DET_RAMP_THR_LSB)
#define PHY_BB_CCK_BLOCKER_DET_CCK_DET_RAMP_THR_SET(x)                         (((0 | (x)) << PHY_BB_CCK_BLOCKER_DET_CCK_DET_RAMP_THR_LSB) & PHY_BB_CCK_BLOCKER_DET_CCK_DET_RAMP_THR_MASK)
#define PHY_BB_CCK_BLOCKER_DET_CCK_DET_RAMP_THR_RESET                          0x0
#define PHY_BB_CCK_BLOCKER_DET_SKIP_RAMP_ENABLE_LSB                            26
#define PHY_BB_CCK_BLOCKER_DET_SKIP_RAMP_ENABLE_MSB                            26
#define PHY_BB_CCK_BLOCKER_DET_SKIP_RAMP_ENABLE_MASK                           0x4000000
#define PHY_BB_CCK_BLOCKER_DET_SKIP_RAMP_ENABLE_GET(x)                         (((x) & PHY_BB_CCK_BLOCKER_DET_SKIP_RAMP_ENABLE_MASK) >> PHY_BB_CCK_BLOCKER_DET_SKIP_RAMP_ENABLE_LSB)
#define PHY_BB_CCK_BLOCKER_DET_SKIP_RAMP_ENABLE_SET(x)                         (((0 | (x)) << PHY_BB_CCK_BLOCKER_DET_SKIP_RAMP_ENABLE_LSB) & PHY_BB_CCK_BLOCKER_DET_SKIP_RAMP_ENABLE_MASK)
#define PHY_BB_CCK_BLOCKER_DET_SKIP_RAMP_ENABLE_RESET                          0x1
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_MONITOR_TIME_LSB                    20
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_MONITOR_TIME_MSB                    25
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_MONITOR_TIME_MASK                   0x3f00000
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_MONITOR_TIME_GET(x)                 (((x) & PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_MONITOR_TIME_MASK) >> PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_MONITOR_TIME_LSB)
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_MONITOR_TIME_SET(x)                 (((0 | (x)) << PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_MONITOR_TIME_LSB) & PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_MONITOR_TIME_MASK)
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_MONITOR_TIME_RESET                  0x0
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_DELAY_THR_LSB                   14
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_DELAY_THR_MSB                   19
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_DELAY_THR_MASK                  0xfc000
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_DELAY_THR_GET(x)                (((x) & PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_DELAY_THR_MASK) >> PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_DELAY_THR_LSB)
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_DELAY_THR_SET(x)                (((0 | (x)) << PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_DELAY_THR_LSB) & PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_DELAY_THR_MASK)
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_DELAY_THR_RESET                 0x0
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_THR_LSB                         9
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_THR_MSB                         13
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_THR_MASK                        0x3e00
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_THR_GET(x)                      (((x) & PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_THR_MASK) >> PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_THR_LSB)
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_THR_SET(x)                      (((0 | (x)) << PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_THR_LSB) & PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_THR_MASK)
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_THR_RESET                       0x0
#define PHY_BB_CCK_BLOCKER_DET_BK_VALID_DELAY_LSB                              6
#define PHY_BB_CCK_BLOCKER_DET_BK_VALID_DELAY_MSB                              8
#define PHY_BB_CCK_BLOCKER_DET_BK_VALID_DELAY_MASK                             0x1c0
#define PHY_BB_CCK_BLOCKER_DET_BK_VALID_DELAY_GET(x)                           (((x) & PHY_BB_CCK_BLOCKER_DET_BK_VALID_DELAY_MASK) >> PHY_BB_CCK_BLOCKER_DET_BK_VALID_DELAY_LSB)
#define PHY_BB_CCK_BLOCKER_DET_BK_VALID_DELAY_SET(x)                           (((0 | (x)) << PHY_BB_CCK_BLOCKER_DET_BK_VALID_DELAY_LSB) & PHY_BB_CCK_BLOCKER_DET_BK_VALID_DELAY_MASK)
#define PHY_BB_CCK_BLOCKER_DET_BK_VALID_DELAY_RESET                            0x0
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_BKSUM_NUM_LSB                   2
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_BKSUM_NUM_MSB                   5
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_BKSUM_NUM_MASK                  0x3c
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_BKSUM_NUM_GET(x)                (((x) & PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_BKSUM_NUM_MASK) >> PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_BKSUM_NUM_LSB)
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_BKSUM_NUM_SET(x)                (((0 | (x)) << PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_BKSUM_NUM_LSB) & PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_BKSUM_NUM_MASK)
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_BKSUM_NUM_RESET                 0x0
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_RESTART_WEAK_SIG_LSB            1
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_RESTART_WEAK_SIG_MSB            1
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_RESTART_WEAK_SIG_MASK           0x2
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_RESTART_WEAK_SIG_GET(x)         (((x) & PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_RESTART_WEAK_SIG_MASK) >> PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_RESTART_WEAK_SIG_LSB)
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_RESTART_WEAK_SIG_SET(x)         (((0 | (x)) << PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_RESTART_WEAK_SIG_LSB) & PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_RESTART_WEAK_SIG_MASK)
#define PHY_BB_CCK_BLOCKER_DET_CCK_BLOCKER_DET_RESTART_WEAK_SIG_RESET          0x0
#define PHY_BB_CCK_BLOCKER_DET_CCK_FREQ_SHIFT_BLOCKER_DETECTION_LSB            0
#define PHY_BB_CCK_BLOCKER_DET_CCK_FREQ_SHIFT_BLOCKER_DETECTION_MSB            0
#define PHY_BB_CCK_BLOCKER_DET_CCK_FREQ_SHIFT_BLOCKER_DETECTION_MASK           0x1
#define PHY_BB_CCK_BLOCKER_DET_CCK_FREQ_SHIFT_BLOCKER_DETECTION_GET(x)         (((x) & PHY_BB_CCK_BLOCKER_DET_CCK_FREQ_SHIFT_BLOCKER_DETECTION_MASK) >> PHY_BB_CCK_BLOCKER_DET_CCK_FREQ_SHIFT_BLOCKER_DETECTION_LSB)
#define PHY_BB_CCK_BLOCKER_DET_CCK_FREQ_SHIFT_BLOCKER_DETECTION_SET(x)         (((0 | (x)) << PHY_BB_CCK_BLOCKER_DET_CCK_FREQ_SHIFT_BLOCKER_DETECTION_LSB) & PHY_BB_CCK_BLOCKER_DET_CCK_FREQ_SHIFT_BLOCKER_DETECTION_MASK)
#define PHY_BB_CCK_BLOCKER_DET_CCK_FREQ_SHIFT_BLOCKER_DETECTION_RESET          0x0
#define PHY_BB_CCK_BLOCKER_DET_ADDRESS                                         (0x1d4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CCK_BLOCKER_DET_RSTMASK                                         0xffffffff
#define PHY_BB_CCK_BLOCKER_DET_RESET                                           0x4000000

// 0x1d8 (PHY_BB_BK_CORR_SETTINGS)
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_SCALE_TF_LSB                             16
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_SCALE_TF_MSB                             18
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_SCALE_TF_MASK                            0x70000
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_SCALE_TF_GET(x)                          (((x) & PHY_BB_BK_CORR_SETTINGS_BK_IN_SCALE_TF_MASK) >> PHY_BB_BK_CORR_SETTINGS_BK_IN_SCALE_TF_LSB)
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_SCALE_TF_SET(x)                          (((0 | (x)) << PHY_BB_BK_CORR_SETTINGS_BK_IN_SCALE_TF_LSB) & PHY_BB_BK_CORR_SETTINGS_BK_IN_SCALE_TF_MASK)
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_SCALE_TF_RESET                           0x2
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_BACKOFF_LSB                              8
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_BACKOFF_MSB                              15
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_BACKOFF_MASK                             0xff00
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_BACKOFF_GET(x)                           (((x) & PHY_BB_BK_CORR_SETTINGS_BK_IN_BACKOFF_MASK) >> PHY_BB_BK_CORR_SETTINGS_BK_IN_BACKOFF_LSB)
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_BACKOFF_SET(x)                           (((0 | (x)) << PHY_BB_BK_CORR_SETTINGS_BK_IN_BACKOFF_LSB) & PHY_BB_BK_CORR_SETTINGS_BK_IN_BACKOFF_MASK)
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_BACKOFF_RESET                            0xba
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_MIN_BACKOFF_LSB                          0
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_MIN_BACKOFF_MSB                          7
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_MIN_BACKOFF_MASK                         0xff
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_MIN_BACKOFF_GET(x)                       (((x) & PHY_BB_BK_CORR_SETTINGS_BK_IN_MIN_BACKOFF_MASK) >> PHY_BB_BK_CORR_SETTINGS_BK_IN_MIN_BACKOFF_LSB)
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_MIN_BACKOFF_SET(x)                       (((0 | (x)) << PHY_BB_BK_CORR_SETTINGS_BK_IN_MIN_BACKOFF_LSB) & PHY_BB_BK_CORR_SETTINGS_BK_IN_MIN_BACKOFF_MASK)
#define PHY_BB_BK_CORR_SETTINGS_BK_IN_MIN_BACKOFF_RESET                        0xa6
#define PHY_BB_BK_CORR_SETTINGS_ADDRESS                                        (0x1d8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_BK_CORR_SETTINGS_RSTMASK                                        0x7ffff
#define PHY_BB_BK_CORR_SETTINGS_RESET                                          0x2baa6

// 0x1e0 (PHY_BB_CCK_BLOCKER_DET2)
#define PHY_BB_CCK_BLOCKER_DET2_DISABLE_M1OK_11B_LSB                           12
#define PHY_BB_CCK_BLOCKER_DET2_DISABLE_M1OK_11B_MSB                           12
#define PHY_BB_CCK_BLOCKER_DET2_DISABLE_M1OK_11B_MASK                          0x1000
#define PHY_BB_CCK_BLOCKER_DET2_DISABLE_M1OK_11B_GET(x)                        (((x) & PHY_BB_CCK_BLOCKER_DET2_DISABLE_M1OK_11B_MASK) >> PHY_BB_CCK_BLOCKER_DET2_DISABLE_M1OK_11B_LSB)
#define PHY_BB_CCK_BLOCKER_DET2_DISABLE_M1OK_11B_SET(x)                        (((0 | (x)) << PHY_BB_CCK_BLOCKER_DET2_DISABLE_M1OK_11B_LSB) & PHY_BB_CCK_BLOCKER_DET2_DISABLE_M1OK_11B_MASK)
#define PHY_BB_CCK_BLOCKER_DET2_DISABLE_M1OK_11B_RESET                         0x0
#define PHY_BB_CCK_BLOCKER_DET2_CCKPDP_VALID_THR_LSB                           8
#define PHY_BB_CCK_BLOCKER_DET2_CCKPDP_VALID_THR_MSB                           10
#define PHY_BB_CCK_BLOCKER_DET2_CCKPDP_VALID_THR_MASK                          0x700
#define PHY_BB_CCK_BLOCKER_DET2_CCKPDP_VALID_THR_GET(x)                        (((x) & PHY_BB_CCK_BLOCKER_DET2_CCKPDP_VALID_THR_MASK) >> PHY_BB_CCK_BLOCKER_DET2_CCKPDP_VALID_THR_LSB)
#define PHY_BB_CCK_BLOCKER_DET2_CCKPDP_VALID_THR_SET(x)                        (((0 | (x)) << PHY_BB_CCK_BLOCKER_DET2_CCKPDP_VALID_THR_LSB) & PHY_BB_CCK_BLOCKER_DET2_CCKPDP_VALID_THR_MASK)
#define PHY_BB_CCK_BLOCKER_DET2_CCKPDP_VALID_THR_RESET                         0x0
#define PHY_BB_CCK_BLOCKER_DET2_FIRPWR_STR_LSB                                 0
#define PHY_BB_CCK_BLOCKER_DET2_FIRPWR_STR_MSB                                 7
#define PHY_BB_CCK_BLOCKER_DET2_FIRPWR_STR_MASK                                0xff
#define PHY_BB_CCK_BLOCKER_DET2_FIRPWR_STR_GET(x)                              (((x) & PHY_BB_CCK_BLOCKER_DET2_FIRPWR_STR_MASK) >> PHY_BB_CCK_BLOCKER_DET2_FIRPWR_STR_LSB)
#define PHY_BB_CCK_BLOCKER_DET2_FIRPWR_STR_SET(x)                              (((0 | (x)) << PHY_BB_CCK_BLOCKER_DET2_FIRPWR_STR_LSB) & PHY_BB_CCK_BLOCKER_DET2_FIRPWR_STR_MASK)
#define PHY_BB_CCK_BLOCKER_DET2_FIRPWR_STR_RESET                               0xa6
#define PHY_BB_CCK_BLOCKER_DET2_ADDRESS                                        (0x1e0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CCK_BLOCKER_DET2_RSTMASK                                        0x17ff
#define PHY_BB_CCK_BLOCKER_DET2_RESET                                          0xa6

// 0x1e4 (PHY_BB_DETECTION_MASK_CNTL)
#define PHY_BB_DETECTION_MASK_CNTL_RSSI_COMB_DM_APPLY_LSB                      7
#define PHY_BB_DETECTION_MASK_CNTL_RSSI_COMB_DM_APPLY_MSB                      7
#define PHY_BB_DETECTION_MASK_CNTL_RSSI_COMB_DM_APPLY_MASK                     0x80
#define PHY_BB_DETECTION_MASK_CNTL_RSSI_COMB_DM_APPLY_GET(x)                   (((x) & PHY_BB_DETECTION_MASK_CNTL_RSSI_COMB_DM_APPLY_MASK) >> PHY_BB_DETECTION_MASK_CNTL_RSSI_COMB_DM_APPLY_LSB)
#define PHY_BB_DETECTION_MASK_CNTL_RSSI_COMB_DM_APPLY_SET(x)                   (((0 | (x)) << PHY_BB_DETECTION_MASK_CNTL_RSSI_COMB_DM_APPLY_LSB) & PHY_BB_DETECTION_MASK_CNTL_RSSI_COMB_DM_APPLY_MASK)
#define PHY_BB_DETECTION_MASK_CNTL_RSSI_COMB_DM_APPLY_RESET                    0x1
#define PHY_BB_DETECTION_MASK_CNTL_FLAG_FIRPWR_DM_APPLY_LSB                    6
#define PHY_BB_DETECTION_MASK_CNTL_FLAG_FIRPWR_DM_APPLY_MSB                    6
#define PHY_BB_DETECTION_MASK_CNTL_FLAG_FIRPWR_DM_APPLY_MASK                   0x40
#define PHY_BB_DETECTION_MASK_CNTL_FLAG_FIRPWR_DM_APPLY_GET(x)                 (((x) & PHY_BB_DETECTION_MASK_CNTL_FLAG_FIRPWR_DM_APPLY_MASK) >> PHY_BB_DETECTION_MASK_CNTL_FLAG_FIRPWR_DM_APPLY_LSB)
#define PHY_BB_DETECTION_MASK_CNTL_FLAG_FIRPWR_DM_APPLY_SET(x)                 (((0 | (x)) << PHY_BB_DETECTION_MASK_CNTL_FLAG_FIRPWR_DM_APPLY_LSB) & PHY_BB_DETECTION_MASK_CNTL_FLAG_FIRPWR_DM_APPLY_MASK)
#define PHY_BB_DETECTION_MASK_CNTL_FLAG_FIRPWR_DM_APPLY_RESET                  0x1
#define PHY_BB_DETECTION_MASK_CNTL_FLAG_RELPWR_DM_APPLY_LSB                    5
#define PHY_BB_DETECTION_MASK_CNTL_FLAG_RELPWR_DM_APPLY_MSB                    5
#define PHY_BB_DETECTION_MASK_CNTL_FLAG_RELPWR_DM_APPLY_MASK                   0x20
#define PHY_BB_DETECTION_MASK_CNTL_FLAG_RELPWR_DM_APPLY_GET(x)                 (((x) & PHY_BB_DETECTION_MASK_CNTL_FLAG_RELPWR_DM_APPLY_MASK) >> PHY_BB_DETECTION_MASK_CNTL_FLAG_RELPWR_DM_APPLY_LSB)
#define PHY_BB_DETECTION_MASK_CNTL_FLAG_RELPWR_DM_APPLY_SET(x)                 (((0 | (x)) << PHY_BB_DETECTION_MASK_CNTL_FLAG_RELPWR_DM_APPLY_LSB) & PHY_BB_DETECTION_MASK_CNTL_FLAG_RELPWR_DM_APPLY_MASK)
#define PHY_BB_DETECTION_MASK_CNTL_FLAG_RELPWR_DM_APPLY_RESET                  0x1
#define PHY_BB_DETECTION_MASK_CNTL_M2FLAG_DM_APPLY_LSB                         4
#define PHY_BB_DETECTION_MASK_CNTL_M2FLAG_DM_APPLY_MSB                         4
#define PHY_BB_DETECTION_MASK_CNTL_M2FLAG_DM_APPLY_MASK                        0x10
#define PHY_BB_DETECTION_MASK_CNTL_M2FLAG_DM_APPLY_GET(x)                      (((x) & PHY_BB_DETECTION_MASK_CNTL_M2FLAG_DM_APPLY_MASK) >> PHY_BB_DETECTION_MASK_CNTL_M2FLAG_DM_APPLY_LSB)
#define PHY_BB_DETECTION_MASK_CNTL_M2FLAG_DM_APPLY_SET(x)                      (((0 | (x)) << PHY_BB_DETECTION_MASK_CNTL_M2FLAG_DM_APPLY_LSB) & PHY_BB_DETECTION_MASK_CNTL_M2FLAG_DM_APPLY_MASK)
#define PHY_BB_DETECTION_MASK_CNTL_M2FLAG_DM_APPLY_RESET                       0x1
#define PHY_BB_DETECTION_MASK_CNTL_IN_RANGE_DM_APPLY_LSB                       3
#define PHY_BB_DETECTION_MASK_CNTL_IN_RANGE_DM_APPLY_MSB                       3
#define PHY_BB_DETECTION_MASK_CNTL_IN_RANGE_DM_APPLY_MASK                      0x8
#define PHY_BB_DETECTION_MASK_CNTL_IN_RANGE_DM_APPLY_GET(x)                    (((x) & PHY_BB_DETECTION_MASK_CNTL_IN_RANGE_DM_APPLY_MASK) >> PHY_BB_DETECTION_MASK_CNTL_IN_RANGE_DM_APPLY_LSB)
#define PHY_BB_DETECTION_MASK_CNTL_IN_RANGE_DM_APPLY_SET(x)                    (((0 | (x)) << PHY_BB_DETECTION_MASK_CNTL_IN_RANGE_DM_APPLY_LSB) & PHY_BB_DETECTION_MASK_CNTL_IN_RANGE_DM_APPLY_MASK)
#define PHY_BB_DETECTION_MASK_CNTL_IN_RANGE_DM_APPLY_RESET                     0x0
#define PHY_BB_DETECTION_MASK_CNTL_GAIN_DROPPED_DM_APPLY_LSB                   2
#define PHY_BB_DETECTION_MASK_CNTL_GAIN_DROPPED_DM_APPLY_MSB                   2
#define PHY_BB_DETECTION_MASK_CNTL_GAIN_DROPPED_DM_APPLY_MASK                  0x4
#define PHY_BB_DETECTION_MASK_CNTL_GAIN_DROPPED_DM_APPLY_GET(x)                (((x) & PHY_BB_DETECTION_MASK_CNTL_GAIN_DROPPED_DM_APPLY_MASK) >> PHY_BB_DETECTION_MASK_CNTL_GAIN_DROPPED_DM_APPLY_LSB)
#define PHY_BB_DETECTION_MASK_CNTL_GAIN_DROPPED_DM_APPLY_SET(x)                (((0 | (x)) << PHY_BB_DETECTION_MASK_CNTL_GAIN_DROPPED_DM_APPLY_LSB) & PHY_BB_DETECTION_MASK_CNTL_GAIN_DROPPED_DM_APPLY_MASK)
#define PHY_BB_DETECTION_MASK_CNTL_GAIN_DROPPED_DM_APPLY_RESET                 0x0
#define PHY_BB_DETECTION_MASK_CNTL_RFSAT_DM_APPLY_LSB                          1
#define PHY_BB_DETECTION_MASK_CNTL_RFSAT_DM_APPLY_MSB                          1
#define PHY_BB_DETECTION_MASK_CNTL_RFSAT_DM_APPLY_MASK                         0x2
#define PHY_BB_DETECTION_MASK_CNTL_RFSAT_DM_APPLY_GET(x)                       (((x) & PHY_BB_DETECTION_MASK_CNTL_RFSAT_DM_APPLY_MASK) >> PHY_BB_DETECTION_MASK_CNTL_RFSAT_DM_APPLY_LSB)
#define PHY_BB_DETECTION_MASK_CNTL_RFSAT_DM_APPLY_SET(x)                       (((0 | (x)) << PHY_BB_DETECTION_MASK_CNTL_RFSAT_DM_APPLY_LSB) & PHY_BB_DETECTION_MASK_CNTL_RFSAT_DM_APPLY_MASK)
#define PHY_BB_DETECTION_MASK_CNTL_RFSAT_DM_APPLY_RESET                        0x0
#define PHY_BB_DETECTION_MASK_CNTL_ADCSAT_DM_APPLY_LSB                         0
#define PHY_BB_DETECTION_MASK_CNTL_ADCSAT_DM_APPLY_MSB                         0
#define PHY_BB_DETECTION_MASK_CNTL_ADCSAT_DM_APPLY_MASK                        0x1
#define PHY_BB_DETECTION_MASK_CNTL_ADCSAT_DM_APPLY_GET(x)                      (((x) & PHY_BB_DETECTION_MASK_CNTL_ADCSAT_DM_APPLY_MASK) >> PHY_BB_DETECTION_MASK_CNTL_ADCSAT_DM_APPLY_LSB)
#define PHY_BB_DETECTION_MASK_CNTL_ADCSAT_DM_APPLY_SET(x)                      (((0 | (x)) << PHY_BB_DETECTION_MASK_CNTL_ADCSAT_DM_APPLY_LSB) & PHY_BB_DETECTION_MASK_CNTL_ADCSAT_DM_APPLY_MASK)
#define PHY_BB_DETECTION_MASK_CNTL_ADCSAT_DM_APPLY_RESET                       0x0
#define PHY_BB_DETECTION_MASK_CNTL_ADDRESS                                     (0x1e4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DETECTION_MASK_CNTL_RSTMASK                                     0xff
#define PHY_BB_DETECTION_MASK_CNTL_RESET                                       0xf0

// 0x200 (PHY_BB_RX_OCGAIN)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_LSB                                        0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_MSB                                        31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_MASK                                       0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_GET(x)                                     (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_SET(x)                                     (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_RESET                                      0x0
#define PHY_BB_RX_OCGAIN_ADDRESS                                               (0x200 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_RSTMASK                                               0xffffffff
#define PHY_BB_RX_OCGAIN_RESET                                                 0x0

// 0x200 (PHY_BB_RX_OCGAIN_0)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_0_LSB                                      0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_0_MSB                                      31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_0_MASK                                     0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_0_GET(x)                                   (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_0_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_0_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_0_SET(x)                                   (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_0_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_0_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_0_RESET                                    0x0
#define PHY_BB_RX_OCGAIN_0_ADDRESS                                             (0x200 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_0_RSTMASK                                             0xffffffff
#define PHY_BB_RX_OCGAIN_0_RESET                                               0x0

// 0x204 (PHY_BB_RX_OCGAIN_1)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_1_LSB                                      0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_1_MSB                                      31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_1_MASK                                     0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_1_GET(x)                                   (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_1_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_1_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_1_SET(x)                                   (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_1_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_1_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_1_RESET                                    0x0
#define PHY_BB_RX_OCGAIN_1_ADDRESS                                             (0x204 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_1_RSTMASK                                             0xffffffff
#define PHY_BB_RX_OCGAIN_1_RESET                                               0x0

// 0x208 (PHY_BB_RX_OCGAIN_2)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_2_LSB                                      0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_2_MSB                                      31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_2_MASK                                     0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_2_GET(x)                                   (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_2_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_2_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_2_SET(x)                                   (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_2_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_2_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_2_RESET                                    0x0
#define PHY_BB_RX_OCGAIN_2_ADDRESS                                             (0x208 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_2_RSTMASK                                             0xffffffff
#define PHY_BB_RX_OCGAIN_2_RESET                                               0x0

// 0x20c (PHY_BB_RX_OCGAIN_3)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_3_LSB                                      0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_3_MSB                                      31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_3_MASK                                     0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_3_GET(x)                                   (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_3_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_3_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_3_SET(x)                                   (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_3_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_3_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_3_RESET                                    0x0
#define PHY_BB_RX_OCGAIN_3_ADDRESS                                             (0x20c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_3_RSTMASK                                             0xffffffff
#define PHY_BB_RX_OCGAIN_3_RESET                                               0x0

// 0x210 (PHY_BB_RX_OCGAIN_4)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_4_LSB                                      0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_4_MSB                                      31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_4_MASK                                     0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_4_GET(x)                                   (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_4_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_4_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_4_SET(x)                                   (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_4_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_4_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_4_RESET                                    0x0
#define PHY_BB_RX_OCGAIN_4_ADDRESS                                             (0x210 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_4_RSTMASK                                             0xffffffff
#define PHY_BB_RX_OCGAIN_4_RESET                                               0x0

// 0x214 (PHY_BB_RX_OCGAIN_5)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_5_LSB                                      0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_5_MSB                                      31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_5_MASK                                     0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_5_GET(x)                                   (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_5_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_5_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_5_SET(x)                                   (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_5_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_5_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_5_RESET                                    0x0
#define PHY_BB_RX_OCGAIN_5_ADDRESS                                             (0x214 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_5_RSTMASK                                             0xffffffff
#define PHY_BB_RX_OCGAIN_5_RESET                                               0x0

// 0x218 (PHY_BB_RX_OCGAIN_6)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_6_LSB                                      0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_6_MSB                                      31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_6_MASK                                     0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_6_GET(x)                                   (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_6_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_6_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_6_SET(x)                                   (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_6_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_6_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_6_RESET                                    0x0
#define PHY_BB_RX_OCGAIN_6_ADDRESS                                             (0x218 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_6_RSTMASK                                             0xffffffff
#define PHY_BB_RX_OCGAIN_6_RESET                                               0x0

// 0x21c (PHY_BB_RX_OCGAIN_7)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_7_LSB                                      0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_7_MSB                                      31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_7_MASK                                     0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_7_GET(x)                                   (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_7_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_7_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_7_SET(x)                                   (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_7_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_7_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_7_RESET                                    0x0
#define PHY_BB_RX_OCGAIN_7_ADDRESS                                             (0x21c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_7_RSTMASK                                             0xffffffff
#define PHY_BB_RX_OCGAIN_7_RESET                                               0x0

// 0x220 (PHY_BB_RX_OCGAIN_8)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_8_LSB                                      0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_8_MSB                                      31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_8_MASK                                     0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_8_GET(x)                                   (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_8_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_8_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_8_SET(x)                                   (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_8_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_8_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_8_RESET                                    0x0
#define PHY_BB_RX_OCGAIN_8_ADDRESS                                             (0x220 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_8_RSTMASK                                             0xffffffff
#define PHY_BB_RX_OCGAIN_8_RESET                                               0x0

// 0x224 (PHY_BB_RX_OCGAIN_9)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_9_LSB                                      0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_9_MSB                                      31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_9_MASK                                     0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_9_GET(x)                                   (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_9_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_9_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_9_SET(x)                                   (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_9_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_9_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_9_RESET                                    0x0
#define PHY_BB_RX_OCGAIN_9_ADDRESS                                             (0x224 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_9_RSTMASK                                             0xffffffff
#define PHY_BB_RX_OCGAIN_9_RESET                                               0x0

// 0x228 (PHY_BB_RX_OCGAIN_10)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_10_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_10_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_10_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_10_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_10_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_10_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_10_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_10_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_10_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_10_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_10_ADDRESS                                            (0x228 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_10_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_10_RESET                                              0x0

// 0x22c (PHY_BB_RX_OCGAIN_11)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_11_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_11_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_11_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_11_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_11_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_11_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_11_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_11_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_11_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_11_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_11_ADDRESS                                            (0x22c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_11_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_11_RESET                                              0x0

// 0x230 (PHY_BB_RX_OCGAIN_12)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_12_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_12_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_12_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_12_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_12_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_12_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_12_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_12_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_12_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_12_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_12_ADDRESS                                            (0x230 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_12_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_12_RESET                                              0x0

// 0x234 (PHY_BB_RX_OCGAIN_13)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_13_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_13_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_13_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_13_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_13_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_13_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_13_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_13_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_13_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_13_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_13_ADDRESS                                            (0x234 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_13_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_13_RESET                                              0x0

// 0x238 (PHY_BB_RX_OCGAIN_14)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_14_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_14_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_14_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_14_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_14_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_14_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_14_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_14_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_14_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_14_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_14_ADDRESS                                            (0x238 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_14_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_14_RESET                                              0x0

// 0x23c (PHY_BB_RX_OCGAIN_15)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_15_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_15_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_15_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_15_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_15_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_15_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_15_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_15_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_15_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_15_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_15_ADDRESS                                            (0x23c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_15_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_15_RESET                                              0x0

// 0x240 (PHY_BB_RX_OCGAIN_16)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_16_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_16_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_16_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_16_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_16_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_16_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_16_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_16_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_16_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_16_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_16_ADDRESS                                            (0x240 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_16_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_16_RESET                                              0x0

// 0x244 (PHY_BB_RX_OCGAIN_17)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_17_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_17_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_17_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_17_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_17_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_17_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_17_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_17_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_17_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_17_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_17_ADDRESS                                            (0x244 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_17_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_17_RESET                                              0x0

// 0x248 (PHY_BB_RX_OCGAIN_18)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_18_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_18_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_18_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_18_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_18_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_18_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_18_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_18_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_18_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_18_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_18_ADDRESS                                            (0x248 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_18_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_18_RESET                                              0x0

// 0x24c (PHY_BB_RX_OCGAIN_19)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_19_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_19_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_19_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_19_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_19_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_19_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_19_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_19_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_19_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_19_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_19_ADDRESS                                            (0x24c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_19_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_19_RESET                                              0x0

// 0x250 (PHY_BB_RX_OCGAIN_20)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_20_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_20_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_20_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_20_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_20_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_20_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_20_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_20_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_20_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_20_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_20_ADDRESS                                            (0x250 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_20_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_20_RESET                                              0x0

// 0x254 (PHY_BB_RX_OCGAIN_21)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_21_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_21_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_21_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_21_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_21_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_21_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_21_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_21_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_21_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_21_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_21_ADDRESS                                            (0x254 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_21_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_21_RESET                                              0x0

// 0x258 (PHY_BB_RX_OCGAIN_22)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_22_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_22_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_22_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_22_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_22_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_22_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_22_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_22_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_22_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_22_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_22_ADDRESS                                            (0x258 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_22_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_22_RESET                                              0x0

// 0x25c (PHY_BB_RX_OCGAIN_23)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_23_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_23_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_23_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_23_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_23_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_23_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_23_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_23_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_23_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_23_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_23_ADDRESS                                            (0x25c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_23_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_23_RESET                                              0x0

// 0x260 (PHY_BB_RX_OCGAIN_24)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_24_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_24_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_24_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_24_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_24_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_24_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_24_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_24_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_24_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_24_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_24_ADDRESS                                            (0x260 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_24_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_24_RESET                                              0x0

// 0x264 (PHY_BB_RX_OCGAIN_25)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_25_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_25_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_25_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_25_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_25_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_25_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_25_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_25_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_25_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_25_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_25_ADDRESS                                            (0x264 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_25_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_25_RESET                                              0x0

// 0x268 (PHY_BB_RX_OCGAIN_26)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_26_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_26_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_26_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_26_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_26_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_26_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_26_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_26_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_26_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_26_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_26_ADDRESS                                            (0x268 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_26_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_26_RESET                                              0x0

// 0x26c (PHY_BB_RX_OCGAIN_27)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_27_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_27_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_27_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_27_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_27_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_27_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_27_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_27_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_27_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_27_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_27_ADDRESS                                            (0x26c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_27_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_27_RESET                                              0x0

// 0x270 (PHY_BB_RX_OCGAIN_28)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_28_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_28_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_28_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_28_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_28_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_28_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_28_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_28_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_28_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_28_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_28_ADDRESS                                            (0x270 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_28_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_28_RESET                                              0x0

// 0x274 (PHY_BB_RX_OCGAIN_29)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_29_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_29_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_29_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_29_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_29_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_29_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_29_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_29_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_29_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_29_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_29_ADDRESS                                            (0x274 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_29_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_29_RESET                                              0x0

// 0x278 (PHY_BB_RX_OCGAIN_30)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_30_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_30_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_30_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_30_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_30_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_30_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_30_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_30_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_30_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_30_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_30_ADDRESS                                            (0x278 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_30_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_30_RESET                                              0x0

// 0x27c (PHY_BB_RX_OCGAIN_31)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_31_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_31_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_31_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_31_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_31_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_31_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_31_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_31_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_31_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_31_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_31_ADDRESS                                            (0x27c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_31_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_31_RESET                                              0x0

// 0x280 (PHY_BB_RX_OCGAIN_32)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_32_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_32_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_32_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_32_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_32_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_32_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_32_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_32_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_32_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_32_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_32_ADDRESS                                            (0x280 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_32_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_32_RESET                                              0x0

// 0x284 (PHY_BB_RX_OCGAIN_33)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_33_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_33_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_33_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_33_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_33_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_33_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_33_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_33_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_33_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_33_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_33_ADDRESS                                            (0x284 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_33_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_33_RESET                                              0x0

// 0x288 (PHY_BB_RX_OCGAIN_34)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_34_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_34_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_34_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_34_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_34_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_34_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_34_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_34_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_34_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_34_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_34_ADDRESS                                            (0x288 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_34_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_34_RESET                                              0x0

// 0x28c (PHY_BB_RX_OCGAIN_35)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_35_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_35_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_35_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_35_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_35_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_35_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_35_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_35_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_35_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_35_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_35_ADDRESS                                            (0x28c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_35_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_35_RESET                                              0x0

// 0x290 (PHY_BB_RX_OCGAIN_36)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_36_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_36_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_36_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_36_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_36_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_36_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_36_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_36_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_36_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_36_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_36_ADDRESS                                            (0x290 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_36_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_36_RESET                                              0x0

// 0x294 (PHY_BB_RX_OCGAIN_37)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_37_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_37_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_37_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_37_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_37_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_37_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_37_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_37_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_37_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_37_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_37_ADDRESS                                            (0x294 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_37_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_37_RESET                                              0x0

// 0x298 (PHY_BB_RX_OCGAIN_38)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_38_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_38_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_38_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_38_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_38_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_38_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_38_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_38_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_38_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_38_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_38_ADDRESS                                            (0x298 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_38_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_38_RESET                                              0x0

// 0x29c (PHY_BB_RX_OCGAIN_39)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_39_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_39_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_39_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_39_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_39_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_39_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_39_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_39_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_39_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_39_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_39_ADDRESS                                            (0x29c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_39_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_39_RESET                                              0x0

// 0x2a0 (PHY_BB_RX_OCGAIN_40)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_40_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_40_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_40_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_40_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_40_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_40_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_40_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_40_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_40_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_40_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_40_ADDRESS                                            (0x2a0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_40_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_40_RESET                                              0x0

// 0x2a4 (PHY_BB_RX_OCGAIN_41)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_41_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_41_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_41_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_41_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_41_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_41_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_41_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_41_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_41_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_41_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_41_ADDRESS                                            (0x2a4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_41_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_41_RESET                                              0x0

// 0x2a8 (PHY_BB_RX_OCGAIN_42)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_42_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_42_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_42_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_42_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_42_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_42_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_42_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_42_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_42_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_42_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_42_ADDRESS                                            (0x2a8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_42_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_42_RESET                                              0x0

// 0x2ac (PHY_BB_RX_OCGAIN_43)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_43_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_43_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_43_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_43_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_43_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_43_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_43_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_43_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_43_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_43_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_43_ADDRESS                                            (0x2ac + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_43_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_43_RESET                                              0x0

// 0x2b0 (PHY_BB_RX_OCGAIN_44)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_44_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_44_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_44_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_44_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_44_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_44_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_44_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_44_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_44_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_44_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_44_ADDRESS                                            (0x2b0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_44_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_44_RESET                                              0x0

// 0x2b4 (PHY_BB_RX_OCGAIN_45)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_45_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_45_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_45_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_45_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_45_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_45_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_45_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_45_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_45_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_45_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_45_ADDRESS                                            (0x2b4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_45_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_45_RESET                                              0x0

// 0x2b8 (PHY_BB_RX_OCGAIN_46)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_46_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_46_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_46_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_46_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_46_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_46_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_46_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_46_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_46_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_46_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_46_ADDRESS                                            (0x2b8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_46_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_46_RESET                                              0x0

// 0x2bc (PHY_BB_RX_OCGAIN_47)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_47_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_47_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_47_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_47_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_47_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_47_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_47_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_47_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_47_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_47_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_47_ADDRESS                                            (0x2bc + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_47_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_47_RESET                                              0x0

// 0x2c0 (PHY_BB_RX_OCGAIN_48)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_48_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_48_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_48_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_48_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_48_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_48_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_48_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_48_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_48_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_48_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_48_ADDRESS                                            (0x2c0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_48_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_48_RESET                                              0x0

// 0x2c4 (PHY_BB_RX_OCGAIN_49)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_49_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_49_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_49_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_49_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_49_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_49_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_49_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_49_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_49_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_49_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_49_ADDRESS                                            (0x2c4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_49_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_49_RESET                                              0x0

// 0x2c8 (PHY_BB_RX_OCGAIN_50)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_50_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_50_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_50_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_50_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_50_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_50_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_50_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_50_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_50_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_50_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_50_ADDRESS                                            (0x2c8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_50_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_50_RESET                                              0x0

// 0x2cc (PHY_BB_RX_OCGAIN_51)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_51_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_51_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_51_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_51_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_51_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_51_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_51_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_51_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_51_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_51_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_51_ADDRESS                                            (0x2cc + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_51_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_51_RESET                                              0x0

// 0x2d0 (PHY_BB_RX_OCGAIN_52)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_52_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_52_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_52_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_52_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_52_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_52_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_52_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_52_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_52_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_52_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_52_ADDRESS                                            (0x2d0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_52_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_52_RESET                                              0x0

// 0x2d4 (PHY_BB_RX_OCGAIN_53)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_53_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_53_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_53_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_53_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_53_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_53_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_53_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_53_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_53_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_53_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_53_ADDRESS                                            (0x2d4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_53_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_53_RESET                                              0x0

// 0x2d8 (PHY_BB_RX_OCGAIN_54)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_54_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_54_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_54_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_54_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_54_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_54_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_54_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_54_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_54_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_54_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_54_ADDRESS                                            (0x2d8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_54_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_54_RESET                                              0x0

// 0x2dc (PHY_BB_RX_OCGAIN_55)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_55_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_55_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_55_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_55_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_55_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_55_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_55_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_55_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_55_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_55_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_55_ADDRESS                                            (0x2dc + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_55_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_55_RESET                                              0x0

// 0x2e0 (PHY_BB_RX_OCGAIN_56)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_56_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_56_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_56_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_56_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_56_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_56_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_56_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_56_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_56_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_56_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_56_ADDRESS                                            (0x2e0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_56_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_56_RESET                                              0x0

// 0x2e4 (PHY_BB_RX_OCGAIN_57)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_57_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_57_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_57_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_57_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_57_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_57_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_57_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_57_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_57_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_57_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_57_ADDRESS                                            (0x2e4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_57_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_57_RESET                                              0x0

// 0x2e8 (PHY_BB_RX_OCGAIN_58)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_58_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_58_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_58_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_58_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_58_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_58_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_58_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_58_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_58_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_58_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_58_ADDRESS                                            (0x2e8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_58_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_58_RESET                                              0x0

// 0x2ec (PHY_BB_RX_OCGAIN_59)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_59_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_59_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_59_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_59_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_59_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_59_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_59_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_59_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_59_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_59_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_59_ADDRESS                                            (0x2ec + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_59_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_59_RESET                                              0x0

// 0x2f0 (PHY_BB_RX_OCGAIN_60)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_60_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_60_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_60_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_60_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_60_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_60_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_60_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_60_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_60_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_60_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_60_ADDRESS                                            (0x2f0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_60_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_60_RESET                                              0x0

// 0x2f4 (PHY_BB_RX_OCGAIN_61)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_61_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_61_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_61_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_61_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_61_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_61_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_61_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_61_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_61_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_61_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_61_ADDRESS                                            (0x2f4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_61_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_61_RESET                                              0x0

// 0x2f8 (PHY_BB_RX_OCGAIN_62)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_62_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_62_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_62_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_62_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_62_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_62_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_62_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_62_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_62_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_62_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_62_ADDRESS                                            (0x2f8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_62_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_62_RESET                                              0x0

// 0x2fc (PHY_BB_RX_OCGAIN_63)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_63_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_63_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_63_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_63_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_63_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_63_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_63_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_63_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_63_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_63_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_63_ADDRESS                                            (0x2fc + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_63_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_63_RESET                                              0x0

// 0x300 (PHY_BB_RX_OCGAIN_64)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_64_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_64_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_64_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_64_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_64_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_64_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_64_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_64_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_64_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_64_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_64_ADDRESS                                            (0x300 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_64_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_64_RESET                                              0x0

// 0x304 (PHY_BB_RX_OCGAIN_65)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_65_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_65_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_65_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_65_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_65_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_65_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_65_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_65_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_65_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_65_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_65_ADDRESS                                            (0x304 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_65_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_65_RESET                                              0x0

// 0x308 (PHY_BB_RX_OCGAIN_66)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_66_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_66_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_66_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_66_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_66_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_66_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_66_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_66_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_66_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_66_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_66_ADDRESS                                            (0x308 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_66_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_66_RESET                                              0x0

// 0x30c (PHY_BB_RX_OCGAIN_67)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_67_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_67_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_67_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_67_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_67_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_67_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_67_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_67_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_67_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_67_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_67_ADDRESS                                            (0x30c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_67_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_67_RESET                                              0x0

// 0x310 (PHY_BB_RX_OCGAIN_68)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_68_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_68_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_68_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_68_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_68_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_68_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_68_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_68_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_68_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_68_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_68_ADDRESS                                            (0x310 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_68_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_68_RESET                                              0x0

// 0x314 (PHY_BB_RX_OCGAIN_69)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_69_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_69_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_69_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_69_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_69_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_69_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_69_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_69_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_69_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_69_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_69_ADDRESS                                            (0x314 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_69_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_69_RESET                                              0x0

// 0x318 (PHY_BB_RX_OCGAIN_70)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_70_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_70_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_70_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_70_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_70_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_70_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_70_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_70_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_70_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_70_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_70_ADDRESS                                            (0x318 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_70_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_70_RESET                                              0x0

// 0x31c (PHY_BB_RX_OCGAIN_71)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_71_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_71_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_71_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_71_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_71_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_71_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_71_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_71_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_71_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_71_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_71_ADDRESS                                            (0x31c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_71_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_71_RESET                                              0x0

// 0x320 (PHY_BB_RX_OCGAIN_72)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_72_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_72_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_72_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_72_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_72_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_72_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_72_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_72_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_72_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_72_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_72_ADDRESS                                            (0x320 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_72_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_72_RESET                                              0x0

// 0x324 (PHY_BB_RX_OCGAIN_73)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_73_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_73_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_73_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_73_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_73_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_73_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_73_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_73_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_73_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_73_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_73_ADDRESS                                            (0x324 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_73_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_73_RESET                                              0x0

// 0x328 (PHY_BB_RX_OCGAIN_74)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_74_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_74_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_74_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_74_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_74_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_74_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_74_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_74_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_74_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_74_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_74_ADDRESS                                            (0x328 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_74_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_74_RESET                                              0x0

// 0x32c (PHY_BB_RX_OCGAIN_75)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_75_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_75_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_75_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_75_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_75_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_75_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_75_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_75_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_75_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_75_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_75_ADDRESS                                            (0x32c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_75_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_75_RESET                                              0x0

// 0x330 (PHY_BB_RX_OCGAIN_76)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_76_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_76_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_76_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_76_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_76_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_76_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_76_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_76_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_76_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_76_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_76_ADDRESS                                            (0x330 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_76_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_76_RESET                                              0x0

// 0x334 (PHY_BB_RX_OCGAIN_77)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_77_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_77_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_77_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_77_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_77_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_77_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_77_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_77_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_77_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_77_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_77_ADDRESS                                            (0x334 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_77_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_77_RESET                                              0x0

// 0x338 (PHY_BB_RX_OCGAIN_78)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_78_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_78_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_78_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_78_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_78_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_78_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_78_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_78_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_78_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_78_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_78_ADDRESS                                            (0x338 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_78_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_78_RESET                                              0x0

// 0x33c (PHY_BB_RX_OCGAIN_79)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_79_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_79_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_79_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_79_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_79_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_79_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_79_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_79_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_79_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_79_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_79_ADDRESS                                            (0x33c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_79_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_79_RESET                                              0x0

// 0x340 (PHY_BB_RX_OCGAIN_80)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_80_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_80_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_80_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_80_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_80_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_80_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_80_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_80_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_80_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_80_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_80_ADDRESS                                            (0x340 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_80_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_80_RESET                                              0x0

// 0x344 (PHY_BB_RX_OCGAIN_81)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_81_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_81_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_81_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_81_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_81_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_81_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_81_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_81_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_81_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_81_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_81_ADDRESS                                            (0x344 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_81_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_81_RESET                                              0x0

// 0x348 (PHY_BB_RX_OCGAIN_82)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_82_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_82_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_82_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_82_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_82_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_82_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_82_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_82_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_82_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_82_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_82_ADDRESS                                            (0x348 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_82_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_82_RESET                                              0x0

// 0x34c (PHY_BB_RX_OCGAIN_83)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_83_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_83_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_83_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_83_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_83_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_83_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_83_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_83_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_83_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_83_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_83_ADDRESS                                            (0x34c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_83_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_83_RESET                                              0x0

// 0x350 (PHY_BB_RX_OCGAIN_84)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_84_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_84_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_84_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_84_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_84_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_84_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_84_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_84_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_84_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_84_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_84_ADDRESS                                            (0x350 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_84_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_84_RESET                                              0x0

// 0x354 (PHY_BB_RX_OCGAIN_85)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_85_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_85_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_85_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_85_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_85_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_85_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_85_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_85_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_85_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_85_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_85_ADDRESS                                            (0x354 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_85_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_85_RESET                                              0x0

// 0x358 (PHY_BB_RX_OCGAIN_86)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_86_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_86_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_86_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_86_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_86_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_86_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_86_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_86_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_86_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_86_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_86_ADDRESS                                            (0x358 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_86_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_86_RESET                                              0x0

// 0x35c (PHY_BB_RX_OCGAIN_87)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_87_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_87_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_87_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_87_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_87_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_87_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_87_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_87_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_87_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_87_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_87_ADDRESS                                            (0x35c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_87_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_87_RESET                                              0x0

// 0x360 (PHY_BB_RX_OCGAIN_88)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_88_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_88_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_88_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_88_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_88_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_88_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_88_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_88_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_88_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_88_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_88_ADDRESS                                            (0x360 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_88_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_88_RESET                                              0x0

// 0x364 (PHY_BB_RX_OCGAIN_89)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_89_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_89_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_89_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_89_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_89_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_89_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_89_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_89_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_89_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_89_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_89_ADDRESS                                            (0x364 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_89_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_89_RESET                                              0x0

// 0x368 (PHY_BB_RX_OCGAIN_90)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_90_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_90_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_90_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_90_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_90_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_90_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_90_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_90_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_90_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_90_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_90_ADDRESS                                            (0x368 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_90_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_90_RESET                                              0x0

// 0x36c (PHY_BB_RX_OCGAIN_91)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_91_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_91_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_91_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_91_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_91_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_91_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_91_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_91_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_91_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_91_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_91_ADDRESS                                            (0x36c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_91_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_91_RESET                                              0x0

// 0x370 (PHY_BB_RX_OCGAIN_92)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_92_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_92_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_92_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_92_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_92_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_92_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_92_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_92_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_92_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_92_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_92_ADDRESS                                            (0x370 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_92_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_92_RESET                                              0x0

// 0x374 (PHY_BB_RX_OCGAIN_93)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_93_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_93_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_93_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_93_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_93_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_93_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_93_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_93_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_93_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_93_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_93_ADDRESS                                            (0x374 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_93_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_93_RESET                                              0x0

// 0x378 (PHY_BB_RX_OCGAIN_94)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_94_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_94_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_94_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_94_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_94_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_94_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_94_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_94_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_94_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_94_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_94_ADDRESS                                            (0x378 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_94_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_94_RESET                                              0x0

// 0x37c (PHY_BB_RX_OCGAIN_95)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_95_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_95_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_95_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_95_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_95_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_95_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_95_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_95_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_95_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_95_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_95_ADDRESS                                            (0x37c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_95_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_95_RESET                                              0x0

// 0x380 (PHY_BB_RX_OCGAIN_96)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_96_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_96_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_96_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_96_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_96_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_96_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_96_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_96_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_96_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_96_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_96_ADDRESS                                            (0x380 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_96_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_96_RESET                                              0x0

// 0x384 (PHY_BB_RX_OCGAIN_97)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_97_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_97_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_97_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_97_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_97_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_97_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_97_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_97_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_97_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_97_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_97_ADDRESS                                            (0x384 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_97_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_97_RESET                                              0x0

// 0x388 (PHY_BB_RX_OCGAIN_98)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_98_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_98_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_98_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_98_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_98_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_98_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_98_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_98_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_98_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_98_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_98_ADDRESS                                            (0x388 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_98_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_98_RESET                                              0x0

// 0x38c (PHY_BB_RX_OCGAIN_99)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_99_LSB                                     0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_99_MSB                                     31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_99_MASK                                    0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_99_GET(x)                                  (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_99_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_99_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_99_SET(x)                                  (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_99_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_99_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_99_RESET                                   0x0
#define PHY_BB_RX_OCGAIN_99_ADDRESS                                            (0x38c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_99_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN_99_RESET                                              0x0

// 0x390 (PHY_BB_RX_OCGAIN_100)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_100_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_100_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_100_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_100_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_100_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_100_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_100_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_100_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_100_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_100_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_100_ADDRESS                                           (0x390 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_100_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_100_RESET                                             0x0

// 0x394 (PHY_BB_RX_OCGAIN_101)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_101_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_101_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_101_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_101_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_101_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_101_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_101_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_101_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_101_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_101_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_101_ADDRESS                                           (0x394 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_101_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_101_RESET                                             0x0

// 0x398 (PHY_BB_RX_OCGAIN_102)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_102_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_102_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_102_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_102_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_102_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_102_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_102_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_102_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_102_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_102_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_102_ADDRESS                                           (0x398 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_102_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_102_RESET                                             0x0

// 0x39c (PHY_BB_RX_OCGAIN_103)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_103_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_103_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_103_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_103_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_103_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_103_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_103_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_103_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_103_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_103_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_103_ADDRESS                                           (0x39c + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_103_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_103_RESET                                             0x0

// 0x3a0 (PHY_BB_RX_OCGAIN_104)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_104_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_104_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_104_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_104_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_104_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_104_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_104_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_104_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_104_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_104_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_104_ADDRESS                                           (0x3a0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_104_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_104_RESET                                             0x0

// 0x3a4 (PHY_BB_RX_OCGAIN_105)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_105_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_105_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_105_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_105_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_105_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_105_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_105_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_105_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_105_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_105_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_105_ADDRESS                                           (0x3a4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_105_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_105_RESET                                             0x0

// 0x3a8 (PHY_BB_RX_OCGAIN_106)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_106_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_106_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_106_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_106_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_106_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_106_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_106_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_106_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_106_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_106_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_106_ADDRESS                                           (0x3a8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_106_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_106_RESET                                             0x0

// 0x3ac (PHY_BB_RX_OCGAIN_107)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_107_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_107_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_107_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_107_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_107_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_107_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_107_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_107_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_107_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_107_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_107_ADDRESS                                           (0x3ac + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_107_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_107_RESET                                             0x0

// 0x3b0 (PHY_BB_RX_OCGAIN_108)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_108_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_108_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_108_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_108_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_108_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_108_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_108_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_108_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_108_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_108_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_108_ADDRESS                                           (0x3b0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_108_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_108_RESET                                             0x0

// 0x3b4 (PHY_BB_RX_OCGAIN_109)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_109_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_109_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_109_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_109_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_109_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_109_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_109_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_109_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_109_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_109_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_109_ADDRESS                                           (0x3b4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_109_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_109_RESET                                             0x0

// 0x3b8 (PHY_BB_RX_OCGAIN_110)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_110_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_110_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_110_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_110_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_110_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_110_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_110_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_110_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_110_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_110_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_110_ADDRESS                                           (0x3b8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_110_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_110_RESET                                             0x0

// 0x3bc (PHY_BB_RX_OCGAIN_111)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_111_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_111_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_111_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_111_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_111_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_111_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_111_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_111_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_111_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_111_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_111_ADDRESS                                           (0x3bc + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_111_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_111_RESET                                             0x0

// 0x3c0 (PHY_BB_RX_OCGAIN_112)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_112_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_112_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_112_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_112_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_112_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_112_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_112_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_112_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_112_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_112_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_112_ADDRESS                                           (0x3c0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_112_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_112_RESET                                             0x0

// 0x3c4 (PHY_BB_RX_OCGAIN_113)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_113_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_113_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_113_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_113_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_113_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_113_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_113_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_113_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_113_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_113_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_113_ADDRESS                                           (0x3c4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_113_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_113_RESET                                             0x0

// 0x3c8 (PHY_BB_RX_OCGAIN_114)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_114_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_114_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_114_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_114_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_114_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_114_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_114_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_114_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_114_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_114_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_114_ADDRESS                                           (0x3c8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_114_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_114_RESET                                             0x0

// 0x3cc (PHY_BB_RX_OCGAIN_115)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_115_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_115_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_115_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_115_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_115_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_115_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_115_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_115_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_115_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_115_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_115_ADDRESS                                           (0x3cc + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_115_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_115_RESET                                             0x0

// 0x3d0 (PHY_BB_RX_OCGAIN_116)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_116_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_116_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_116_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_116_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_116_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_116_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_116_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_116_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_116_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_116_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_116_ADDRESS                                           (0x3d0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_116_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_116_RESET                                             0x0

// 0x3d4 (PHY_BB_RX_OCGAIN_117)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_117_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_117_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_117_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_117_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_117_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_117_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_117_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_117_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_117_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_117_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_117_ADDRESS                                           (0x3d4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_117_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_117_RESET                                             0x0

// 0x3d8 (PHY_BB_RX_OCGAIN_118)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_118_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_118_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_118_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_118_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_118_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_118_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_118_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_118_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_118_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_118_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_118_ADDRESS                                           (0x3d8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_118_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_118_RESET                                             0x0

// 0x3dc (PHY_BB_RX_OCGAIN_119)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_119_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_119_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_119_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_119_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_119_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_119_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_119_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_119_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_119_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_119_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_119_ADDRESS                                           (0x3dc + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_119_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_119_RESET                                             0x0

// 0x3e0 (PHY_BB_RX_OCGAIN_120)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_120_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_120_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_120_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_120_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_120_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_120_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_120_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_120_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_120_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_120_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_120_ADDRESS                                           (0x3e0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_120_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_120_RESET                                             0x0

// 0x3e4 (PHY_BB_RX_OCGAIN_121)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_121_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_121_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_121_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_121_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_121_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_121_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_121_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_121_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_121_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_121_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_121_ADDRESS                                           (0x3e4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_121_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_121_RESET                                             0x0

// 0x3e8 (PHY_BB_RX_OCGAIN_122)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_122_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_122_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_122_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_122_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_122_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_122_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_122_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_122_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_122_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_122_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_122_ADDRESS                                           (0x3e8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_122_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_122_RESET                                             0x0

// 0x3ec (PHY_BB_RX_OCGAIN_123)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_123_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_123_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_123_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_123_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_123_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_123_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_123_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_123_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_123_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_123_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_123_ADDRESS                                           (0x3ec + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_123_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_123_RESET                                             0x0

// 0x3f0 (PHY_BB_RX_OCGAIN_124)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_124_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_124_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_124_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_124_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_124_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_124_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_124_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_124_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_124_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_124_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_124_ADDRESS                                           (0x3f0 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_124_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_124_RESET                                             0x0

// 0x3f4 (PHY_BB_RX_OCGAIN_125)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_125_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_125_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_125_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_125_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_125_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_125_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_125_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_125_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_125_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_125_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_125_ADDRESS                                           (0x3f4 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_125_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_125_RESET                                             0x0

// 0x3f8 (PHY_BB_RX_OCGAIN_126)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_126_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_126_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_126_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_126_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_126_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_126_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_126_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_126_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_126_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_126_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_126_ADDRESS                                           (0x3f8 + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_126_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_126_RESET                                             0x0

// 0x3fc (PHY_BB_RX_OCGAIN_127)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_127_LSB                                    0
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_127_MSB                                    31
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_127_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_127_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_127_MASK) >> PHY_BB_RX_OCGAIN_GAIN_ENTRY_127_LSB)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_127_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN_GAIN_ENTRY_127_LSB) & PHY_BB_RX_OCGAIN_GAIN_ENTRY_127_MASK)
#define PHY_BB_RX_OCGAIN_GAIN_ENTRY_127_RESET                                  0x0
#define PHY_BB_RX_OCGAIN_127_ADDRESS                                           (0x3fc + __PHY_AGC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN_127_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN_127_RESET                                             0x0



#endif /* _PHY_AGC_REG_MAP_H_ */
