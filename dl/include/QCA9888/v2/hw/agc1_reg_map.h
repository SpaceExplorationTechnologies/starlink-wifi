/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _PHY_AGC1_REG_MAP_H_
#define _PHY_AGC1_REG_MAP_H_


#ifndef __PHY_AGC1_REG_MAP_BASE_ADDRESS
#define __PHY_AGC1_REG_MAP_BASE_ADDRESS (0x11000)
#endif


// 0x4 (PHY_BB_GAIN_FORCE_MAX_GAINS_B1)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_HYST_MARGIN_1_LSB               25
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_HYST_MARGIN_1_MSB               31
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_HYST_MARGIN_1_MASK              0xfe000000
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_HYST_MARGIN_1_GET(x)            (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_HYST_MARGIN_1_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_HYST_MARGIN_1_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_HYST_MARGIN_1_SET(x)            (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_HYST_MARGIN_1_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_HYST_MARGIN_1_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_HYST_MARGIN_1_RESET             0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_HYST_MARGIN_1_LSB               18
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_HYST_MARGIN_1_MSB               24
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_HYST_MARGIN_1_MASK              0x1fc0000
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_HYST_MARGIN_1_GET(x)            (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_HYST_MARGIN_1_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_HYST_MARGIN_1_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_HYST_MARGIN_1_SET(x)            (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_HYST_MARGIN_1_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_HYST_MARGIN_1_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_HYST_MARGIN_1_RESET             0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_SW_F_1_LSB                      17
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_SW_F_1_MSB                      17
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_SW_F_1_MASK                     0x20000
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_SW_F_1_GET(x)                   (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_SW_F_1_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_SW_F_1_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_SW_F_1_SET(x)                   (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_SW_F_1_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_SW_F_1_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN2_SW_F_1_RESET                    0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_SW_F_1_LSB                      16
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_SW_F_1_MSB                      16
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_SW_F_1_MASK                     0x10000
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_SW_F_1_GET(x)                   (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_SW_F_1_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_SW_F_1_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_SW_F_1_SET(x)                   (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_SW_F_1_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_SW_F_1_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_XATTEN1_SW_F_1_RESET                    0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_MB_GAIN_F_1_LSB                         8
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_MB_GAIN_F_1_MSB                         15
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_MB_GAIN_F_1_MASK                        0xff00
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_MB_GAIN_F_1_GET(x)                      (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B1_MB_GAIN_F_1_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B1_MB_GAIN_F_1_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_MB_GAIN_F_1_SET(x)                      (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B1_MB_GAIN_F_1_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B1_MB_GAIN_F_1_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_MB_GAIN_F_1_RESET                       0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_RF_GAIN_F_1_LSB                         0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_RF_GAIN_F_1_MSB                         7
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_RF_GAIN_F_1_MASK                        0xff
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_RF_GAIN_F_1_GET(x)                      (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B1_RF_GAIN_F_1_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B1_RF_GAIN_F_1_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_RF_GAIN_F_1_SET(x)                      (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B1_RF_GAIN_F_1_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B1_RF_GAIN_F_1_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_RF_GAIN_F_1_RESET                       0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_ADDRESS                                 (0x4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_RSTMASK                                 0xffffffff
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B1_RESET                                   0x0

// 0x18 (PHY_BB_EXT_ATTEN_SWITCH_CTL_B1)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XLNA_GAIN_DB_1_LSB                      24
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XLNA_GAIN_DB_1_MSB                      28
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XLNA_GAIN_DB_1_MASK                     0x1f000000
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XLNA_GAIN_DB_1_GET(x)                   (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XLNA_GAIN_DB_1_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XLNA_GAIN_DB_1_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XLNA_GAIN_DB_1_SET(x)                   (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XLNA_GAIN_DB_1_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XLNA_GAIN_DB_1_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XLNA_GAIN_DB_1_RESET                    0x0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_MARGIN_1_LSB                    18
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_MARGIN_1_MSB                    23
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_MARGIN_1_MASK                   0xfc0000
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_MARGIN_1_GET(x)                 (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_MARGIN_1_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_MARGIN_1_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_MARGIN_1_SET(x)                 (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_MARGIN_1_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_MARGIN_1_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_MARGIN_1_RESET                  0x0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_MARGIN_1_LSB                    12
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_MARGIN_1_MSB                    17
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_MARGIN_1_MASK                   0x3f000
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_MARGIN_1_GET(x)                 (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_MARGIN_1_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_MARGIN_1_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_MARGIN_1_SET(x)                 (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_MARGIN_1_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_MARGIN_1_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_MARGIN_1_RESET                  0x32
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_DB_1_LSB                        6
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_DB_1_MSB                        11
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_DB_1_MASK                       0xfc0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_DB_1_GET(x)                     (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_DB_1_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_DB_1_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_DB_1_SET(x)                     (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_DB_1_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_DB_1_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN2_DB_1_RESET                      0x0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_DB_1_LSB                        0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_DB_1_MSB                        5
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_DB_1_MASK                       0x3f
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_DB_1_GET(x)                     (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_DB_1_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_DB_1_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_DB_1_SET(x)                     (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_DB_1_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_DB_1_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_XATTEN1_DB_1_RESET                      0x0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_ADDRESS                                 (0x18 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_RSTMASK                                 0x1fffffff
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B1_RESET                                   0x32000

// 0x1c (PHY_BB_CCA_B1)
#define PHY_BB_CCA_B1_MINCCAPWR_1_LSB                                          20
#define PHY_BB_CCA_B1_MINCCAPWR_1_MSB                                          28
#define PHY_BB_CCA_B1_MINCCAPWR_1_MASK                                         0x1ff00000
#define PHY_BB_CCA_B1_MINCCAPWR_1_GET(x)                                       (((x) & PHY_BB_CCA_B1_MINCCAPWR_1_MASK) >> PHY_BB_CCA_B1_MINCCAPWR_1_LSB)
#define PHY_BB_CCA_B1_MINCCAPWR_1_SET(x)                                       (((0 | (x)) << PHY_BB_CCA_B1_MINCCAPWR_1_LSB) & PHY_BB_CCA_B1_MINCCAPWR_1_MASK)
#define PHY_BB_CCA_B1_MINCCAPWR_1_RESET                                        0x0
#define PHY_BB_CCA_B1_CF_MAXCCAPWR_1_LSB                                       0
#define PHY_BB_CCA_B1_CF_MAXCCAPWR_1_MSB                                       8
#define PHY_BB_CCA_B1_CF_MAXCCAPWR_1_MASK                                      0x1ff
#define PHY_BB_CCA_B1_CF_MAXCCAPWR_1_GET(x)                                    (((x) & PHY_BB_CCA_B1_CF_MAXCCAPWR_1_MASK) >> PHY_BB_CCA_B1_CF_MAXCCAPWR_1_LSB)
#define PHY_BB_CCA_B1_CF_MAXCCAPWR_1_SET(x)                                    (((0 | (x)) << PHY_BB_CCA_B1_CF_MAXCCAPWR_1_LSB) & PHY_BB_CCA_B1_CF_MAXCCAPWR_1_MASK)
#define PHY_BB_CCA_B1_CF_MAXCCAPWR_1_RESET                                     0x0
#define PHY_BB_CCA_B1_ADDRESS                                                  (0x1c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CCA_B1_RSTMASK                                                  0x1ff001ff
#define PHY_BB_CCA_B1_RESET                                                    0x0

// 0x20 (PHY_BB_CCA_CTRL_2_B1)
#define PHY_BB_CCA_CTRL_2_B1_NF_GAIN_COMP_1_LSB                                10
#define PHY_BB_CCA_CTRL_2_B1_NF_GAIN_COMP_1_MSB                                17
#define PHY_BB_CCA_CTRL_2_B1_NF_GAIN_COMP_1_MASK                               0x3fc00
#define PHY_BB_CCA_CTRL_2_B1_NF_GAIN_COMP_1_GET(x)                             (((x) & PHY_BB_CCA_CTRL_2_B1_NF_GAIN_COMP_1_MASK) >> PHY_BB_CCA_CTRL_2_B1_NF_GAIN_COMP_1_LSB)
#define PHY_BB_CCA_CTRL_2_B1_NF_GAIN_COMP_1_SET(x)                             (((0 | (x)) << PHY_BB_CCA_CTRL_2_B1_NF_GAIN_COMP_1_LSB) & PHY_BB_CCA_CTRL_2_B1_NF_GAIN_COMP_1_MASK)
#define PHY_BB_CCA_CTRL_2_B1_NF_GAIN_COMP_1_RESET                              0x0
#define PHY_BB_CCA_CTRL_2_B1_MINCCAPWR_THR_1_LSB                               0
#define PHY_BB_CCA_CTRL_2_B1_MINCCAPWR_THR_1_MSB                               8
#define PHY_BB_CCA_CTRL_2_B1_MINCCAPWR_THR_1_MASK                              0x1ff
#define PHY_BB_CCA_CTRL_2_B1_MINCCAPWR_THR_1_GET(x)                            (((x) & PHY_BB_CCA_CTRL_2_B1_MINCCAPWR_THR_1_MASK) >> PHY_BB_CCA_CTRL_2_B1_MINCCAPWR_THR_1_LSB)
#define PHY_BB_CCA_CTRL_2_B1_MINCCAPWR_THR_1_SET(x)                            (((0 | (x)) << PHY_BB_CCA_CTRL_2_B1_MINCCAPWR_THR_1_LSB) & PHY_BB_CCA_CTRL_2_B1_MINCCAPWR_THR_1_MASK)
#define PHY_BB_CCA_CTRL_2_B1_MINCCAPWR_THR_1_RESET                             0x0
#define PHY_BB_CCA_CTRL_2_B1_ADDRESS                                           (0x20 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CCA_CTRL_2_B1_RSTMASK                                           0x3fdff
#define PHY_BB_CCA_CTRL_2_B1_RESET                                             0x0

// 0x24 (PHY_BB_CCA_EXT80_B1)
#define PHY_BB_CCA_EXT80_B1_MINCCAPWR_EXT80_1_LSB                              20
#define PHY_BB_CCA_EXT80_B1_MINCCAPWR_EXT80_1_MSB                              28
#define PHY_BB_CCA_EXT80_B1_MINCCAPWR_EXT80_1_MASK                             0x1ff00000
#define PHY_BB_CCA_EXT80_B1_MINCCAPWR_EXT80_1_GET(x)                           (((x) & PHY_BB_CCA_EXT80_B1_MINCCAPWR_EXT80_1_MASK) >> PHY_BB_CCA_EXT80_B1_MINCCAPWR_EXT80_1_LSB)
#define PHY_BB_CCA_EXT80_B1_MINCCAPWR_EXT80_1_SET(x)                           (((0 | (x)) << PHY_BB_CCA_EXT80_B1_MINCCAPWR_EXT80_1_LSB) & PHY_BB_CCA_EXT80_B1_MINCCAPWR_EXT80_1_MASK)
#define PHY_BB_CCA_EXT80_B1_MINCCAPWR_EXT80_1_RESET                            0x0
#define PHY_BB_CCA_EXT80_B1_CF_MAXCCAPWR_EXT80_1_LSB                           0
#define PHY_BB_CCA_EXT80_B1_CF_MAXCCAPWR_EXT80_1_MSB                           8
#define PHY_BB_CCA_EXT80_B1_CF_MAXCCAPWR_EXT80_1_MASK                          0x1ff
#define PHY_BB_CCA_EXT80_B1_CF_MAXCCAPWR_EXT80_1_GET(x)                        (((x) & PHY_BB_CCA_EXT80_B1_CF_MAXCCAPWR_EXT80_1_MASK) >> PHY_BB_CCA_EXT80_B1_CF_MAXCCAPWR_EXT80_1_LSB)
#define PHY_BB_CCA_EXT80_B1_CF_MAXCCAPWR_EXT80_1_SET(x)                        (((0 | (x)) << PHY_BB_CCA_EXT80_B1_CF_MAXCCAPWR_EXT80_1_LSB) & PHY_BB_CCA_EXT80_B1_CF_MAXCCAPWR_EXT80_1_MASK)
#define PHY_BB_CCA_EXT80_B1_CF_MAXCCAPWR_EXT80_1_RESET                         0x0
#define PHY_BB_CCA_EXT80_B1_ADDRESS                                            (0x24 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CCA_EXT80_B1_RSTMASK                                            0x1ff001ff
#define PHY_BB_CCA_EXT80_B1_RESET                                              0x0

// 0x180 (PHY_BB_RSSI_B1)
#define PHY_BB_RSSI_B1_RSSI_EXT80_1_LSB                                        24
#define PHY_BB_RSSI_B1_RSSI_EXT80_1_MSB                                        31
#define PHY_BB_RSSI_B1_RSSI_EXT80_1_MASK                                       0xff000000
#define PHY_BB_RSSI_B1_RSSI_EXT80_1_GET(x)                                     (((x) & PHY_BB_RSSI_B1_RSSI_EXT80_1_MASK) >> PHY_BB_RSSI_B1_RSSI_EXT80_1_LSB)
#define PHY_BB_RSSI_B1_RSSI_EXT80_1_SET(x)                                     (((0 | (x)) << PHY_BB_RSSI_B1_RSSI_EXT80_1_LSB) & PHY_BB_RSSI_B1_RSSI_EXT80_1_MASK)
#define PHY_BB_RSSI_B1_RSSI_EXT80_1_RESET                                      0x0
#define PHY_BB_RSSI_B1_RSSI_EXT40_1_LSB                                        16
#define PHY_BB_RSSI_B1_RSSI_EXT40_1_MSB                                        23
#define PHY_BB_RSSI_B1_RSSI_EXT40_1_MASK                                       0xff0000
#define PHY_BB_RSSI_B1_RSSI_EXT40_1_GET(x)                                     (((x) & PHY_BB_RSSI_B1_RSSI_EXT40_1_MASK) >> PHY_BB_RSSI_B1_RSSI_EXT40_1_LSB)
#define PHY_BB_RSSI_B1_RSSI_EXT40_1_SET(x)                                     (((0 | (x)) << PHY_BB_RSSI_B1_RSSI_EXT40_1_LSB) & PHY_BB_RSSI_B1_RSSI_EXT40_1_MASK)
#define PHY_BB_RSSI_B1_RSSI_EXT40_1_RESET                                      0x0
#define PHY_BB_RSSI_B1_RSSI_EXT20_1_LSB                                        8
#define PHY_BB_RSSI_B1_RSSI_EXT20_1_MSB                                        15
#define PHY_BB_RSSI_B1_RSSI_EXT20_1_MASK                                       0xff00
#define PHY_BB_RSSI_B1_RSSI_EXT20_1_GET(x)                                     (((x) & PHY_BB_RSSI_B1_RSSI_EXT20_1_MASK) >> PHY_BB_RSSI_B1_RSSI_EXT20_1_LSB)
#define PHY_BB_RSSI_B1_RSSI_EXT20_1_SET(x)                                     (((0 | (x)) << PHY_BB_RSSI_B1_RSSI_EXT20_1_LSB) & PHY_BB_RSSI_B1_RSSI_EXT20_1_MASK)
#define PHY_BB_RSSI_B1_RSSI_EXT20_1_RESET                                      0x0
#define PHY_BB_RSSI_B1_RSSI_PRI20_1_LSB                                        0
#define PHY_BB_RSSI_B1_RSSI_PRI20_1_MSB                                        7
#define PHY_BB_RSSI_B1_RSSI_PRI20_1_MASK                                       0xff
#define PHY_BB_RSSI_B1_RSSI_PRI20_1_GET(x)                                     (((x) & PHY_BB_RSSI_B1_RSSI_PRI20_1_MASK) >> PHY_BB_RSSI_B1_RSSI_PRI20_1_LSB)
#define PHY_BB_RSSI_B1_RSSI_PRI20_1_SET(x)                                     (((0 | (x)) << PHY_BB_RSSI_B1_RSSI_PRI20_1_LSB) & PHY_BB_RSSI_B1_RSSI_PRI20_1_MASK)
#define PHY_BB_RSSI_B1_RSSI_PRI20_1_RESET                                      0x0
#define PHY_BB_RSSI_B1_ADDRESS                                                 (0x180 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RSSI_B1_RSTMASK                                                 0xffffffff
#define PHY_BB_RSSI_B1_RESET                                                   0x0

// 0x188 (PHY_BB_AGC_DIG_DC_STATUS_B1)
#define PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_Q_1_LSB                 10
#define PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_Q_1_MSB                 19
#define PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_Q_1_MASK                0xffc00
#define PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_Q_1_GET(x)              (((x) & PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_Q_1_MASK) >> PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_Q_1_LSB)
#define PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_Q_1_SET(x)              (((0 | (x)) << PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_Q_1_LSB) & PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_Q_1_MASK)
#define PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_Q_1_RESET               0x0
#define PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_I_1_LSB                 0
#define PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_I_1_MSB                 9
#define PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_I_1_MASK                0x3ff
#define PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_I_1_GET(x)              (((x) & PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_I_1_MASK) >> PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_I_1_LSB)
#define PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_I_1_SET(x)              (((0 | (x)) << PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_I_1_LSB) & PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_I_1_MASK)
#define PHY_BB_AGC_DIG_DC_STATUS_B1_DC_CAL_RESIDUAL_DC_I_1_RESET               0x0
#define PHY_BB_AGC_DIG_DC_STATUS_B1_ADDRESS                                    (0x188 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_AGC_DIG_DC_STATUS_B1_RSTMASK                                    0xfffff
#define PHY_BB_AGC_DIG_DC_STATUS_B1_RESET                                      0x0

// 0x1a0 (PHY_BB_DC_CAL_STATUS_B1)
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC2Q_1_LSB                                24
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC2Q_1_MSB                                31
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC2Q_1_MASK                               0xff000000
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC2Q_1_GET(x)                             (((x) & PHY_BB_DC_CAL_STATUS_B1_OFFSETC2Q_1_MASK) >> PHY_BB_DC_CAL_STATUS_B1_OFFSETC2Q_1_LSB)
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC2Q_1_SET(x)                             (((0 | (x)) << PHY_BB_DC_CAL_STATUS_B1_OFFSETC2Q_1_LSB) & PHY_BB_DC_CAL_STATUS_B1_OFFSETC2Q_1_MASK)
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC2Q_1_RESET                              0x0
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC2I_1_LSB                                16
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC2I_1_MSB                                23
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC2I_1_MASK                               0xff0000
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC2I_1_GET(x)                             (((x) & PHY_BB_DC_CAL_STATUS_B1_OFFSETC2I_1_MASK) >> PHY_BB_DC_CAL_STATUS_B1_OFFSETC2I_1_LSB)
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC2I_1_SET(x)                             (((0 | (x)) << PHY_BB_DC_CAL_STATUS_B1_OFFSETC2I_1_LSB) & PHY_BB_DC_CAL_STATUS_B1_OFFSETC2I_1_MASK)
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC2I_1_RESET                              0x0
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC1Q_1_LSB                                8
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC1Q_1_MSB                                15
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC1Q_1_MASK                               0xff00
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC1Q_1_GET(x)                             (((x) & PHY_BB_DC_CAL_STATUS_B1_OFFSETC1Q_1_MASK) >> PHY_BB_DC_CAL_STATUS_B1_OFFSETC1Q_1_LSB)
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC1Q_1_SET(x)                             (((0 | (x)) << PHY_BB_DC_CAL_STATUS_B1_OFFSETC1Q_1_LSB) & PHY_BB_DC_CAL_STATUS_B1_OFFSETC1Q_1_MASK)
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC1Q_1_RESET                              0x0
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC1I_1_LSB                                0
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC1I_1_MSB                                7
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC1I_1_MASK                               0xff
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC1I_1_GET(x)                             (((x) & PHY_BB_DC_CAL_STATUS_B1_OFFSETC1I_1_MASK) >> PHY_BB_DC_CAL_STATUS_B1_OFFSETC1I_1_LSB)
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC1I_1_SET(x)                             (((0 | (x)) << PHY_BB_DC_CAL_STATUS_B1_OFFSETC1I_1_LSB) & PHY_BB_DC_CAL_STATUS_B1_OFFSETC1I_1_MASK)
#define PHY_BB_DC_CAL_STATUS_B1_OFFSETC1I_1_RESET                              0x0
#define PHY_BB_DC_CAL_STATUS_B1_ADDRESS                                        (0x1a0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DC_CAL_STATUS_B1_RSTMASK                                        0xffffffff
#define PHY_BB_DC_CAL_STATUS_B1_RESET                                          0x0

// 0x1a4 (PHY_BB_DC_CAL_STATUS_2_B1)
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4Q_1_LSB                              24
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4Q_1_MSB                              31
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4Q_1_MASK                             0xff000000
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4Q_1_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4Q_1_MASK) >> PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4Q_1_LSB)
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4Q_1_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4Q_1_LSB) & PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4Q_1_MASK)
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4Q_1_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4I_1_LSB                              16
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4I_1_MSB                              23
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4I_1_MASK                             0xff0000
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4I_1_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4I_1_MASK) >> PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4I_1_LSB)
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4I_1_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4I_1_LSB) & PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4I_1_MASK)
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC4I_1_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3Q_1_LSB                              8
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3Q_1_MSB                              15
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3Q_1_MASK                             0xff00
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3Q_1_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3Q_1_MASK) >> PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3Q_1_LSB)
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3Q_1_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3Q_1_LSB) & PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3Q_1_MASK)
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3Q_1_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3I_1_LSB                              0
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3I_1_MSB                              7
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3I_1_MASK                             0xff
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3I_1_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3I_1_MASK) >> PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3I_1_LSB)
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3I_1_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3I_1_LSB) & PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3I_1_MASK)
#define PHY_BB_DC_CAL_STATUS_2_B1_OFFSETC3I_1_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_2_B1_ADDRESS                                      (0x1a4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DC_CAL_STATUS_2_B1_RSTMASK                                      0xffffffff
#define PHY_BB_DC_CAL_STATUS_2_B1_RESET                                        0x0

// 0x1a8 (PHY_BB_DC_CAL_STATUS_3_B1)
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6Q_1_LSB                              24
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6Q_1_MSB                              31
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6Q_1_MASK                             0xff000000
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6Q_1_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6Q_1_MASK) >> PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6Q_1_LSB)
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6Q_1_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6Q_1_LSB) & PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6Q_1_MASK)
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6Q_1_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6I_1_LSB                              16
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6I_1_MSB                              23
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6I_1_MASK                             0xff0000
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6I_1_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6I_1_MASK) >> PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6I_1_LSB)
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6I_1_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6I_1_LSB) & PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6I_1_MASK)
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC6I_1_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5Q_1_LSB                              8
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5Q_1_MSB                              15
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5Q_1_MASK                             0xff00
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5Q_1_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5Q_1_MASK) >> PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5Q_1_LSB)
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5Q_1_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5Q_1_LSB) & PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5Q_1_MASK)
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5Q_1_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5I_1_LSB                              0
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5I_1_MSB                              7
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5I_1_MASK                             0xff
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5I_1_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5I_1_MASK) >> PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5I_1_LSB)
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5I_1_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5I_1_LSB) & PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5I_1_MASK)
#define PHY_BB_DC_CAL_STATUS_3_B1_OFFSETC5I_1_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_3_B1_ADDRESS                                      (0x1a8 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DC_CAL_STATUS_3_B1_RSTMASK                                      0xffffffff
#define PHY_BB_DC_CAL_STATUS_3_B1_RESET                                        0x0

// 0x1ac (PHY_BB_DC_CAL_STATUS_4_B1)
#define PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7Q_1_LSB                              8
#define PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7Q_1_MSB                              15
#define PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7Q_1_MASK                             0xff00
#define PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7Q_1_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7Q_1_MASK) >> PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7Q_1_LSB)
#define PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7Q_1_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7Q_1_LSB) & PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7Q_1_MASK)
#define PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7Q_1_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7I_1_LSB                              0
#define PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7I_1_MSB                              7
#define PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7I_1_MASK                             0xff
#define PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7I_1_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7I_1_MASK) >> PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7I_1_LSB)
#define PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7I_1_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7I_1_LSB) & PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7I_1_MASK)
#define PHY_BB_DC_CAL_STATUS_4_B1_OFFSETC7I_1_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_4_B1_ADDRESS                                      (0x1ac + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DC_CAL_STATUS_4_B1_RSTMASK                                      0xffff
#define PHY_BB_DC_CAL_STATUS_4_B1_RESET                                        0x0

// 0x1b0 (PHY_BB_RX_GAIN_NF_B1)
#define PHY_BB_RX_GAIN_NF_B1_GAIN_VAL_AFTER_NF_1_LSB                           0
#define PHY_BB_RX_GAIN_NF_B1_GAIN_VAL_AFTER_NF_1_MSB                           16
#define PHY_BB_RX_GAIN_NF_B1_GAIN_VAL_AFTER_NF_1_MASK                          0x1ffff
#define PHY_BB_RX_GAIN_NF_B1_GAIN_VAL_AFTER_NF_1_GET(x)                        (((x) & PHY_BB_RX_GAIN_NF_B1_GAIN_VAL_AFTER_NF_1_MASK) >> PHY_BB_RX_GAIN_NF_B1_GAIN_VAL_AFTER_NF_1_LSB)
#define PHY_BB_RX_GAIN_NF_B1_GAIN_VAL_AFTER_NF_1_SET(x)                        (((0 | (x)) << PHY_BB_RX_GAIN_NF_B1_GAIN_VAL_AFTER_NF_1_LSB) & PHY_BB_RX_GAIN_NF_B1_GAIN_VAL_AFTER_NF_1_MASK)
#define PHY_BB_RX_GAIN_NF_B1_GAIN_VAL_AFTER_NF_1_RESET                         0x0
#define PHY_BB_RX_GAIN_NF_B1_ADDRESS                                           (0x1b0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_GAIN_NF_B1_RSTMASK                                           0x1ffff
#define PHY_BB_RX_GAIN_NF_B1_RESET                                             0x0

// 0x200 (PHY_BB_RX_OCGAIN2)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_LSB                                      0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_MSB                                      31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_MASK                                     0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_GET(x)                                   (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_SET(x)                                   (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_RESET                                    0x0
#define PHY_BB_RX_OCGAIN2_ADDRESS                                              (0x200 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_RSTMASK                                              0xffffffff
#define PHY_BB_RX_OCGAIN2_RESET                                                0x0

// 0x200 (PHY_BB_RX_OCGAIN2_0)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_0_LSB                                    0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_0_MSB                                    31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_0_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_0_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_0_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_0_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_0_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_0_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_0_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_0_RESET                                  0x0
#define PHY_BB_RX_OCGAIN2_0_ADDRESS                                            (0x200 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_0_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN2_0_RESET                                              0x0

// 0x204 (PHY_BB_RX_OCGAIN2_1)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_1_LSB                                    0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_1_MSB                                    31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_1_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_1_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_1_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_1_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_1_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_1_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_1_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_1_RESET                                  0x0
#define PHY_BB_RX_OCGAIN2_1_ADDRESS                                            (0x204 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_1_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN2_1_RESET                                              0x0

// 0x208 (PHY_BB_RX_OCGAIN2_2)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_2_LSB                                    0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_2_MSB                                    31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_2_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_2_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_2_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_2_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_2_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_2_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_2_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_2_RESET                                  0x0
#define PHY_BB_RX_OCGAIN2_2_ADDRESS                                            (0x208 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_2_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN2_2_RESET                                              0x0

// 0x20c (PHY_BB_RX_OCGAIN2_3)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_3_LSB                                    0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_3_MSB                                    31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_3_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_3_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_3_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_3_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_3_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_3_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_3_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_3_RESET                                  0x0
#define PHY_BB_RX_OCGAIN2_3_ADDRESS                                            (0x20c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_3_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN2_3_RESET                                              0x0

// 0x210 (PHY_BB_RX_OCGAIN2_4)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_4_LSB                                    0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_4_MSB                                    31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_4_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_4_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_4_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_4_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_4_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_4_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_4_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_4_RESET                                  0x0
#define PHY_BB_RX_OCGAIN2_4_ADDRESS                                            (0x210 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_4_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN2_4_RESET                                              0x0

// 0x214 (PHY_BB_RX_OCGAIN2_5)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_5_LSB                                    0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_5_MSB                                    31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_5_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_5_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_5_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_5_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_5_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_5_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_5_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_5_RESET                                  0x0
#define PHY_BB_RX_OCGAIN2_5_ADDRESS                                            (0x214 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_5_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN2_5_RESET                                              0x0

// 0x218 (PHY_BB_RX_OCGAIN2_6)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_6_LSB                                    0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_6_MSB                                    31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_6_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_6_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_6_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_6_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_6_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_6_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_6_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_6_RESET                                  0x0
#define PHY_BB_RX_OCGAIN2_6_ADDRESS                                            (0x218 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_6_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN2_6_RESET                                              0x0

// 0x21c (PHY_BB_RX_OCGAIN2_7)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_7_LSB                                    0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_7_MSB                                    31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_7_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_7_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_7_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_7_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_7_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_7_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_7_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_7_RESET                                  0x0
#define PHY_BB_RX_OCGAIN2_7_ADDRESS                                            (0x21c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_7_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN2_7_RESET                                              0x0

// 0x220 (PHY_BB_RX_OCGAIN2_8)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_8_LSB                                    0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_8_MSB                                    31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_8_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_8_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_8_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_8_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_8_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_8_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_8_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_8_RESET                                  0x0
#define PHY_BB_RX_OCGAIN2_8_ADDRESS                                            (0x220 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_8_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN2_8_RESET                                              0x0

// 0x224 (PHY_BB_RX_OCGAIN2_9)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_9_LSB                                    0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_9_MSB                                    31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_9_MASK                                   0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_9_GET(x)                                 (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_9_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_9_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_9_SET(x)                                 (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_9_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_9_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_9_RESET                                  0x0
#define PHY_BB_RX_OCGAIN2_9_ADDRESS                                            (0x224 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_9_RSTMASK                                            0xffffffff
#define PHY_BB_RX_OCGAIN2_9_RESET                                              0x0

// 0x228 (PHY_BB_RX_OCGAIN2_10)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_10_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_10_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_10_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_10_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_10_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_10_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_10_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_10_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_10_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_10_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_10_ADDRESS                                           (0x228 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_10_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_10_RESET                                             0x0

// 0x22c (PHY_BB_RX_OCGAIN2_11)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_11_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_11_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_11_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_11_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_11_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_11_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_11_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_11_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_11_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_11_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_11_ADDRESS                                           (0x22c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_11_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_11_RESET                                             0x0

// 0x230 (PHY_BB_RX_OCGAIN2_12)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_12_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_12_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_12_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_12_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_12_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_12_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_12_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_12_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_12_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_12_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_12_ADDRESS                                           (0x230 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_12_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_12_RESET                                             0x0

// 0x234 (PHY_BB_RX_OCGAIN2_13)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_13_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_13_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_13_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_13_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_13_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_13_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_13_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_13_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_13_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_13_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_13_ADDRESS                                           (0x234 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_13_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_13_RESET                                             0x0

// 0x238 (PHY_BB_RX_OCGAIN2_14)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_14_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_14_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_14_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_14_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_14_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_14_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_14_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_14_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_14_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_14_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_14_ADDRESS                                           (0x238 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_14_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_14_RESET                                             0x0

// 0x23c (PHY_BB_RX_OCGAIN2_15)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_15_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_15_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_15_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_15_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_15_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_15_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_15_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_15_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_15_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_15_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_15_ADDRESS                                           (0x23c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_15_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_15_RESET                                             0x0

// 0x240 (PHY_BB_RX_OCGAIN2_16)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_16_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_16_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_16_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_16_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_16_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_16_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_16_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_16_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_16_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_16_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_16_ADDRESS                                           (0x240 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_16_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_16_RESET                                             0x0

// 0x244 (PHY_BB_RX_OCGAIN2_17)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_17_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_17_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_17_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_17_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_17_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_17_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_17_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_17_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_17_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_17_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_17_ADDRESS                                           (0x244 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_17_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_17_RESET                                             0x0

// 0x248 (PHY_BB_RX_OCGAIN2_18)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_18_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_18_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_18_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_18_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_18_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_18_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_18_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_18_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_18_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_18_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_18_ADDRESS                                           (0x248 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_18_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_18_RESET                                             0x0

// 0x24c (PHY_BB_RX_OCGAIN2_19)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_19_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_19_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_19_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_19_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_19_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_19_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_19_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_19_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_19_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_19_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_19_ADDRESS                                           (0x24c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_19_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_19_RESET                                             0x0

// 0x250 (PHY_BB_RX_OCGAIN2_20)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_20_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_20_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_20_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_20_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_20_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_20_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_20_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_20_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_20_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_20_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_20_ADDRESS                                           (0x250 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_20_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_20_RESET                                             0x0

// 0x254 (PHY_BB_RX_OCGAIN2_21)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_21_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_21_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_21_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_21_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_21_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_21_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_21_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_21_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_21_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_21_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_21_ADDRESS                                           (0x254 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_21_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_21_RESET                                             0x0

// 0x258 (PHY_BB_RX_OCGAIN2_22)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_22_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_22_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_22_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_22_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_22_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_22_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_22_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_22_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_22_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_22_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_22_ADDRESS                                           (0x258 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_22_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_22_RESET                                             0x0

// 0x25c (PHY_BB_RX_OCGAIN2_23)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_23_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_23_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_23_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_23_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_23_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_23_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_23_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_23_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_23_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_23_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_23_ADDRESS                                           (0x25c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_23_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_23_RESET                                             0x0

// 0x260 (PHY_BB_RX_OCGAIN2_24)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_24_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_24_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_24_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_24_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_24_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_24_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_24_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_24_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_24_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_24_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_24_ADDRESS                                           (0x260 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_24_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_24_RESET                                             0x0

// 0x264 (PHY_BB_RX_OCGAIN2_25)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_25_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_25_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_25_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_25_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_25_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_25_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_25_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_25_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_25_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_25_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_25_ADDRESS                                           (0x264 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_25_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_25_RESET                                             0x0

// 0x268 (PHY_BB_RX_OCGAIN2_26)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_26_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_26_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_26_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_26_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_26_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_26_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_26_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_26_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_26_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_26_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_26_ADDRESS                                           (0x268 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_26_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_26_RESET                                             0x0

// 0x26c (PHY_BB_RX_OCGAIN2_27)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_27_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_27_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_27_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_27_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_27_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_27_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_27_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_27_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_27_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_27_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_27_ADDRESS                                           (0x26c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_27_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_27_RESET                                             0x0

// 0x270 (PHY_BB_RX_OCGAIN2_28)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_28_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_28_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_28_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_28_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_28_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_28_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_28_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_28_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_28_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_28_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_28_ADDRESS                                           (0x270 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_28_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_28_RESET                                             0x0

// 0x274 (PHY_BB_RX_OCGAIN2_29)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_29_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_29_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_29_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_29_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_29_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_29_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_29_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_29_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_29_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_29_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_29_ADDRESS                                           (0x274 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_29_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_29_RESET                                             0x0

// 0x278 (PHY_BB_RX_OCGAIN2_30)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_30_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_30_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_30_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_30_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_30_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_30_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_30_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_30_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_30_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_30_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_30_ADDRESS                                           (0x278 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_30_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_30_RESET                                             0x0

// 0x27c (PHY_BB_RX_OCGAIN2_31)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_31_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_31_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_31_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_31_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_31_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_31_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_31_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_31_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_31_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_31_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_31_ADDRESS                                           (0x27c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_31_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_31_RESET                                             0x0

// 0x280 (PHY_BB_RX_OCGAIN2_32)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_32_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_32_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_32_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_32_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_32_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_32_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_32_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_32_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_32_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_32_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_32_ADDRESS                                           (0x280 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_32_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_32_RESET                                             0x0

// 0x284 (PHY_BB_RX_OCGAIN2_33)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_33_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_33_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_33_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_33_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_33_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_33_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_33_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_33_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_33_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_33_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_33_ADDRESS                                           (0x284 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_33_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_33_RESET                                             0x0

// 0x288 (PHY_BB_RX_OCGAIN2_34)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_34_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_34_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_34_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_34_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_34_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_34_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_34_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_34_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_34_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_34_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_34_ADDRESS                                           (0x288 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_34_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_34_RESET                                             0x0

// 0x28c (PHY_BB_RX_OCGAIN2_35)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_35_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_35_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_35_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_35_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_35_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_35_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_35_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_35_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_35_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_35_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_35_ADDRESS                                           (0x28c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_35_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_35_RESET                                             0x0

// 0x290 (PHY_BB_RX_OCGAIN2_36)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_36_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_36_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_36_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_36_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_36_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_36_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_36_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_36_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_36_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_36_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_36_ADDRESS                                           (0x290 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_36_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_36_RESET                                             0x0

// 0x294 (PHY_BB_RX_OCGAIN2_37)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_37_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_37_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_37_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_37_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_37_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_37_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_37_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_37_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_37_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_37_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_37_ADDRESS                                           (0x294 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_37_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_37_RESET                                             0x0

// 0x298 (PHY_BB_RX_OCGAIN2_38)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_38_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_38_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_38_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_38_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_38_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_38_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_38_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_38_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_38_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_38_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_38_ADDRESS                                           (0x298 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_38_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_38_RESET                                             0x0

// 0x29c (PHY_BB_RX_OCGAIN2_39)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_39_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_39_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_39_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_39_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_39_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_39_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_39_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_39_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_39_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_39_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_39_ADDRESS                                           (0x29c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_39_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_39_RESET                                             0x0

// 0x2a0 (PHY_BB_RX_OCGAIN2_40)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_40_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_40_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_40_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_40_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_40_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_40_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_40_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_40_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_40_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_40_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_40_ADDRESS                                           (0x2a0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_40_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_40_RESET                                             0x0

// 0x2a4 (PHY_BB_RX_OCGAIN2_41)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_41_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_41_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_41_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_41_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_41_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_41_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_41_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_41_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_41_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_41_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_41_ADDRESS                                           (0x2a4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_41_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_41_RESET                                             0x0

// 0x2a8 (PHY_BB_RX_OCGAIN2_42)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_42_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_42_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_42_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_42_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_42_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_42_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_42_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_42_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_42_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_42_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_42_ADDRESS                                           (0x2a8 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_42_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_42_RESET                                             0x0

// 0x2ac (PHY_BB_RX_OCGAIN2_43)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_43_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_43_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_43_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_43_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_43_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_43_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_43_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_43_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_43_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_43_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_43_ADDRESS                                           (0x2ac + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_43_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_43_RESET                                             0x0

// 0x2b0 (PHY_BB_RX_OCGAIN2_44)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_44_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_44_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_44_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_44_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_44_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_44_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_44_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_44_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_44_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_44_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_44_ADDRESS                                           (0x2b0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_44_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_44_RESET                                             0x0

// 0x2b4 (PHY_BB_RX_OCGAIN2_45)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_45_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_45_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_45_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_45_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_45_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_45_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_45_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_45_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_45_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_45_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_45_ADDRESS                                           (0x2b4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_45_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_45_RESET                                             0x0

// 0x2b8 (PHY_BB_RX_OCGAIN2_46)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_46_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_46_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_46_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_46_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_46_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_46_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_46_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_46_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_46_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_46_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_46_ADDRESS                                           (0x2b8 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_46_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_46_RESET                                             0x0

// 0x2bc (PHY_BB_RX_OCGAIN2_47)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_47_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_47_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_47_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_47_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_47_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_47_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_47_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_47_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_47_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_47_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_47_ADDRESS                                           (0x2bc + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_47_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_47_RESET                                             0x0

// 0x2c0 (PHY_BB_RX_OCGAIN2_48)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_48_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_48_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_48_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_48_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_48_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_48_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_48_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_48_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_48_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_48_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_48_ADDRESS                                           (0x2c0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_48_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_48_RESET                                             0x0

// 0x2c4 (PHY_BB_RX_OCGAIN2_49)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_49_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_49_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_49_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_49_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_49_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_49_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_49_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_49_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_49_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_49_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_49_ADDRESS                                           (0x2c4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_49_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_49_RESET                                             0x0

// 0x2c8 (PHY_BB_RX_OCGAIN2_50)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_50_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_50_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_50_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_50_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_50_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_50_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_50_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_50_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_50_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_50_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_50_ADDRESS                                           (0x2c8 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_50_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_50_RESET                                             0x0

// 0x2cc (PHY_BB_RX_OCGAIN2_51)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_51_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_51_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_51_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_51_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_51_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_51_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_51_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_51_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_51_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_51_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_51_ADDRESS                                           (0x2cc + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_51_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_51_RESET                                             0x0

// 0x2d0 (PHY_BB_RX_OCGAIN2_52)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_52_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_52_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_52_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_52_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_52_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_52_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_52_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_52_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_52_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_52_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_52_ADDRESS                                           (0x2d0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_52_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_52_RESET                                             0x0

// 0x2d4 (PHY_BB_RX_OCGAIN2_53)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_53_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_53_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_53_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_53_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_53_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_53_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_53_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_53_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_53_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_53_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_53_ADDRESS                                           (0x2d4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_53_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_53_RESET                                             0x0

// 0x2d8 (PHY_BB_RX_OCGAIN2_54)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_54_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_54_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_54_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_54_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_54_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_54_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_54_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_54_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_54_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_54_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_54_ADDRESS                                           (0x2d8 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_54_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_54_RESET                                             0x0

// 0x2dc (PHY_BB_RX_OCGAIN2_55)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_55_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_55_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_55_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_55_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_55_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_55_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_55_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_55_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_55_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_55_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_55_ADDRESS                                           (0x2dc + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_55_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_55_RESET                                             0x0

// 0x2e0 (PHY_BB_RX_OCGAIN2_56)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_56_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_56_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_56_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_56_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_56_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_56_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_56_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_56_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_56_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_56_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_56_ADDRESS                                           (0x2e0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_56_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_56_RESET                                             0x0

// 0x2e4 (PHY_BB_RX_OCGAIN2_57)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_57_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_57_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_57_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_57_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_57_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_57_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_57_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_57_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_57_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_57_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_57_ADDRESS                                           (0x2e4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_57_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_57_RESET                                             0x0

// 0x2e8 (PHY_BB_RX_OCGAIN2_58)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_58_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_58_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_58_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_58_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_58_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_58_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_58_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_58_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_58_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_58_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_58_ADDRESS                                           (0x2e8 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_58_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_58_RESET                                             0x0

// 0x2ec (PHY_BB_RX_OCGAIN2_59)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_59_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_59_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_59_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_59_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_59_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_59_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_59_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_59_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_59_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_59_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_59_ADDRESS                                           (0x2ec + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_59_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_59_RESET                                             0x0

// 0x2f0 (PHY_BB_RX_OCGAIN2_60)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_60_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_60_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_60_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_60_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_60_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_60_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_60_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_60_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_60_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_60_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_60_ADDRESS                                           (0x2f0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_60_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_60_RESET                                             0x0

// 0x2f4 (PHY_BB_RX_OCGAIN2_61)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_61_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_61_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_61_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_61_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_61_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_61_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_61_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_61_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_61_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_61_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_61_ADDRESS                                           (0x2f4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_61_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_61_RESET                                             0x0

// 0x2f8 (PHY_BB_RX_OCGAIN2_62)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_62_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_62_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_62_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_62_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_62_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_62_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_62_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_62_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_62_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_62_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_62_ADDRESS                                           (0x2f8 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_62_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_62_RESET                                             0x0

// 0x2fc (PHY_BB_RX_OCGAIN2_63)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_63_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_63_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_63_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_63_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_63_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_63_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_63_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_63_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_63_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_63_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_63_ADDRESS                                           (0x2fc + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_63_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_63_RESET                                             0x0

// 0x300 (PHY_BB_RX_OCGAIN2_64)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_64_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_64_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_64_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_64_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_64_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_64_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_64_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_64_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_64_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_64_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_64_ADDRESS                                           (0x300 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_64_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_64_RESET                                             0x0

// 0x304 (PHY_BB_RX_OCGAIN2_65)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_65_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_65_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_65_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_65_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_65_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_65_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_65_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_65_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_65_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_65_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_65_ADDRESS                                           (0x304 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_65_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_65_RESET                                             0x0

// 0x308 (PHY_BB_RX_OCGAIN2_66)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_66_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_66_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_66_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_66_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_66_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_66_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_66_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_66_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_66_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_66_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_66_ADDRESS                                           (0x308 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_66_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_66_RESET                                             0x0

// 0x30c (PHY_BB_RX_OCGAIN2_67)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_67_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_67_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_67_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_67_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_67_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_67_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_67_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_67_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_67_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_67_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_67_ADDRESS                                           (0x30c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_67_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_67_RESET                                             0x0

// 0x310 (PHY_BB_RX_OCGAIN2_68)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_68_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_68_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_68_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_68_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_68_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_68_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_68_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_68_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_68_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_68_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_68_ADDRESS                                           (0x310 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_68_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_68_RESET                                             0x0

// 0x314 (PHY_BB_RX_OCGAIN2_69)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_69_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_69_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_69_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_69_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_69_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_69_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_69_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_69_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_69_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_69_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_69_ADDRESS                                           (0x314 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_69_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_69_RESET                                             0x0

// 0x318 (PHY_BB_RX_OCGAIN2_70)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_70_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_70_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_70_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_70_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_70_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_70_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_70_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_70_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_70_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_70_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_70_ADDRESS                                           (0x318 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_70_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_70_RESET                                             0x0

// 0x31c (PHY_BB_RX_OCGAIN2_71)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_71_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_71_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_71_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_71_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_71_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_71_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_71_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_71_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_71_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_71_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_71_ADDRESS                                           (0x31c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_71_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_71_RESET                                             0x0

// 0x320 (PHY_BB_RX_OCGAIN2_72)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_72_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_72_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_72_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_72_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_72_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_72_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_72_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_72_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_72_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_72_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_72_ADDRESS                                           (0x320 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_72_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_72_RESET                                             0x0

// 0x324 (PHY_BB_RX_OCGAIN2_73)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_73_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_73_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_73_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_73_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_73_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_73_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_73_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_73_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_73_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_73_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_73_ADDRESS                                           (0x324 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_73_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_73_RESET                                             0x0

// 0x328 (PHY_BB_RX_OCGAIN2_74)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_74_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_74_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_74_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_74_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_74_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_74_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_74_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_74_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_74_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_74_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_74_ADDRESS                                           (0x328 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_74_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_74_RESET                                             0x0

// 0x32c (PHY_BB_RX_OCGAIN2_75)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_75_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_75_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_75_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_75_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_75_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_75_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_75_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_75_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_75_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_75_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_75_ADDRESS                                           (0x32c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_75_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_75_RESET                                             0x0

// 0x330 (PHY_BB_RX_OCGAIN2_76)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_76_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_76_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_76_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_76_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_76_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_76_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_76_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_76_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_76_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_76_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_76_ADDRESS                                           (0x330 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_76_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_76_RESET                                             0x0

// 0x334 (PHY_BB_RX_OCGAIN2_77)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_77_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_77_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_77_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_77_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_77_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_77_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_77_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_77_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_77_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_77_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_77_ADDRESS                                           (0x334 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_77_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_77_RESET                                             0x0

// 0x338 (PHY_BB_RX_OCGAIN2_78)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_78_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_78_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_78_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_78_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_78_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_78_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_78_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_78_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_78_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_78_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_78_ADDRESS                                           (0x338 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_78_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_78_RESET                                             0x0

// 0x33c (PHY_BB_RX_OCGAIN2_79)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_79_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_79_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_79_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_79_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_79_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_79_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_79_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_79_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_79_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_79_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_79_ADDRESS                                           (0x33c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_79_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_79_RESET                                             0x0

// 0x340 (PHY_BB_RX_OCGAIN2_80)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_80_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_80_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_80_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_80_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_80_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_80_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_80_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_80_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_80_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_80_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_80_ADDRESS                                           (0x340 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_80_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_80_RESET                                             0x0

// 0x344 (PHY_BB_RX_OCGAIN2_81)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_81_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_81_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_81_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_81_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_81_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_81_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_81_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_81_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_81_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_81_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_81_ADDRESS                                           (0x344 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_81_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_81_RESET                                             0x0

// 0x348 (PHY_BB_RX_OCGAIN2_82)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_82_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_82_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_82_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_82_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_82_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_82_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_82_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_82_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_82_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_82_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_82_ADDRESS                                           (0x348 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_82_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_82_RESET                                             0x0

// 0x34c (PHY_BB_RX_OCGAIN2_83)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_83_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_83_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_83_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_83_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_83_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_83_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_83_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_83_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_83_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_83_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_83_ADDRESS                                           (0x34c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_83_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_83_RESET                                             0x0

// 0x350 (PHY_BB_RX_OCGAIN2_84)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_84_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_84_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_84_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_84_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_84_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_84_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_84_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_84_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_84_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_84_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_84_ADDRESS                                           (0x350 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_84_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_84_RESET                                             0x0

// 0x354 (PHY_BB_RX_OCGAIN2_85)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_85_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_85_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_85_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_85_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_85_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_85_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_85_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_85_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_85_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_85_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_85_ADDRESS                                           (0x354 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_85_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_85_RESET                                             0x0

// 0x358 (PHY_BB_RX_OCGAIN2_86)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_86_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_86_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_86_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_86_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_86_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_86_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_86_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_86_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_86_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_86_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_86_ADDRESS                                           (0x358 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_86_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_86_RESET                                             0x0

// 0x35c (PHY_BB_RX_OCGAIN2_87)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_87_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_87_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_87_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_87_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_87_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_87_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_87_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_87_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_87_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_87_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_87_ADDRESS                                           (0x35c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_87_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_87_RESET                                             0x0

// 0x360 (PHY_BB_RX_OCGAIN2_88)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_88_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_88_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_88_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_88_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_88_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_88_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_88_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_88_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_88_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_88_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_88_ADDRESS                                           (0x360 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_88_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_88_RESET                                             0x0

// 0x364 (PHY_BB_RX_OCGAIN2_89)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_89_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_89_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_89_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_89_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_89_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_89_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_89_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_89_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_89_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_89_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_89_ADDRESS                                           (0x364 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_89_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_89_RESET                                             0x0

// 0x368 (PHY_BB_RX_OCGAIN2_90)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_90_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_90_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_90_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_90_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_90_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_90_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_90_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_90_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_90_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_90_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_90_ADDRESS                                           (0x368 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_90_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_90_RESET                                             0x0

// 0x36c (PHY_BB_RX_OCGAIN2_91)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_91_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_91_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_91_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_91_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_91_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_91_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_91_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_91_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_91_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_91_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_91_ADDRESS                                           (0x36c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_91_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_91_RESET                                             0x0

// 0x370 (PHY_BB_RX_OCGAIN2_92)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_92_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_92_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_92_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_92_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_92_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_92_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_92_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_92_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_92_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_92_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_92_ADDRESS                                           (0x370 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_92_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_92_RESET                                             0x0

// 0x374 (PHY_BB_RX_OCGAIN2_93)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_93_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_93_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_93_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_93_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_93_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_93_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_93_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_93_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_93_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_93_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_93_ADDRESS                                           (0x374 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_93_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_93_RESET                                             0x0

// 0x378 (PHY_BB_RX_OCGAIN2_94)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_94_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_94_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_94_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_94_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_94_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_94_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_94_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_94_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_94_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_94_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_94_ADDRESS                                           (0x378 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_94_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_94_RESET                                             0x0

// 0x37c (PHY_BB_RX_OCGAIN2_95)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_95_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_95_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_95_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_95_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_95_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_95_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_95_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_95_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_95_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_95_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_95_ADDRESS                                           (0x37c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_95_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_95_RESET                                             0x0

// 0x380 (PHY_BB_RX_OCGAIN2_96)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_96_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_96_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_96_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_96_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_96_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_96_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_96_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_96_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_96_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_96_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_96_ADDRESS                                           (0x380 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_96_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_96_RESET                                             0x0

// 0x384 (PHY_BB_RX_OCGAIN2_97)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_97_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_97_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_97_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_97_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_97_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_97_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_97_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_97_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_97_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_97_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_97_ADDRESS                                           (0x384 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_97_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_97_RESET                                             0x0

// 0x388 (PHY_BB_RX_OCGAIN2_98)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_98_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_98_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_98_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_98_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_98_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_98_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_98_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_98_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_98_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_98_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_98_ADDRESS                                           (0x388 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_98_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_98_RESET                                             0x0

// 0x38c (PHY_BB_RX_OCGAIN2_99)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_99_LSB                                   0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_99_MSB                                   31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_99_MASK                                  0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_99_GET(x)                                (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_99_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_99_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_99_SET(x)                                (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_99_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_99_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_99_RESET                                 0x0
#define PHY_BB_RX_OCGAIN2_99_ADDRESS                                           (0x38c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_99_RSTMASK                                           0xffffffff
#define PHY_BB_RX_OCGAIN2_99_RESET                                             0x0

// 0x390 (PHY_BB_RX_OCGAIN2_100)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_100_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_100_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_100_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_100_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_100_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_100_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_100_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_100_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_100_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_100_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_100_ADDRESS                                          (0x390 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_100_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_100_RESET                                            0x0

// 0x394 (PHY_BB_RX_OCGAIN2_101)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_101_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_101_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_101_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_101_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_101_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_101_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_101_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_101_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_101_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_101_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_101_ADDRESS                                          (0x394 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_101_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_101_RESET                                            0x0

// 0x398 (PHY_BB_RX_OCGAIN2_102)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_102_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_102_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_102_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_102_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_102_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_102_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_102_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_102_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_102_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_102_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_102_ADDRESS                                          (0x398 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_102_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_102_RESET                                            0x0

// 0x39c (PHY_BB_RX_OCGAIN2_103)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_103_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_103_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_103_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_103_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_103_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_103_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_103_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_103_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_103_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_103_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_103_ADDRESS                                          (0x39c + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_103_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_103_RESET                                            0x0

// 0x3a0 (PHY_BB_RX_OCGAIN2_104)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_104_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_104_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_104_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_104_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_104_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_104_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_104_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_104_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_104_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_104_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_104_ADDRESS                                          (0x3a0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_104_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_104_RESET                                            0x0

// 0x3a4 (PHY_BB_RX_OCGAIN2_105)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_105_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_105_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_105_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_105_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_105_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_105_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_105_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_105_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_105_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_105_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_105_ADDRESS                                          (0x3a4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_105_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_105_RESET                                            0x0

// 0x3a8 (PHY_BB_RX_OCGAIN2_106)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_106_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_106_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_106_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_106_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_106_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_106_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_106_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_106_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_106_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_106_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_106_ADDRESS                                          (0x3a8 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_106_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_106_RESET                                            0x0

// 0x3ac (PHY_BB_RX_OCGAIN2_107)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_107_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_107_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_107_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_107_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_107_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_107_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_107_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_107_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_107_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_107_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_107_ADDRESS                                          (0x3ac + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_107_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_107_RESET                                            0x0

// 0x3b0 (PHY_BB_RX_OCGAIN2_108)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_108_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_108_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_108_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_108_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_108_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_108_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_108_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_108_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_108_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_108_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_108_ADDRESS                                          (0x3b0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_108_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_108_RESET                                            0x0

// 0x3b4 (PHY_BB_RX_OCGAIN2_109)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_109_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_109_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_109_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_109_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_109_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_109_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_109_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_109_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_109_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_109_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_109_ADDRESS                                          (0x3b4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_109_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_109_RESET                                            0x0

// 0x3b8 (PHY_BB_RX_OCGAIN2_110)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_110_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_110_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_110_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_110_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_110_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_110_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_110_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_110_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_110_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_110_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_110_ADDRESS                                          (0x3b8 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_110_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_110_RESET                                            0x0

// 0x3bc (PHY_BB_RX_OCGAIN2_111)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_111_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_111_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_111_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_111_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_111_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_111_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_111_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_111_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_111_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_111_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_111_ADDRESS                                          (0x3bc + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_111_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_111_RESET                                            0x0

// 0x3c0 (PHY_BB_RX_OCGAIN2_112)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_112_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_112_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_112_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_112_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_112_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_112_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_112_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_112_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_112_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_112_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_112_ADDRESS                                          (0x3c0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_112_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_112_RESET                                            0x0

// 0x3c4 (PHY_BB_RX_OCGAIN2_113)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_113_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_113_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_113_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_113_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_113_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_113_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_113_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_113_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_113_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_113_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_113_ADDRESS                                          (0x3c4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_113_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_113_RESET                                            0x0

// 0x3c8 (PHY_BB_RX_OCGAIN2_114)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_114_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_114_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_114_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_114_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_114_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_114_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_114_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_114_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_114_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_114_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_114_ADDRESS                                          (0x3c8 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_114_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_114_RESET                                            0x0

// 0x3cc (PHY_BB_RX_OCGAIN2_115)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_115_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_115_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_115_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_115_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_115_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_115_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_115_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_115_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_115_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_115_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_115_ADDRESS                                          (0x3cc + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_115_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_115_RESET                                            0x0

// 0x3d0 (PHY_BB_RX_OCGAIN2_116)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_116_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_116_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_116_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_116_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_116_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_116_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_116_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_116_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_116_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_116_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_116_ADDRESS                                          (0x3d0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_116_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_116_RESET                                            0x0

// 0x3d4 (PHY_BB_RX_OCGAIN2_117)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_117_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_117_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_117_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_117_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_117_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_117_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_117_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_117_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_117_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_117_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_117_ADDRESS                                          (0x3d4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_117_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_117_RESET                                            0x0

// 0x3d8 (PHY_BB_RX_OCGAIN2_118)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_118_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_118_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_118_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_118_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_118_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_118_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_118_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_118_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_118_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_118_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_118_ADDRESS                                          (0x3d8 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_118_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_118_RESET                                            0x0

// 0x3dc (PHY_BB_RX_OCGAIN2_119)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_119_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_119_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_119_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_119_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_119_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_119_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_119_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_119_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_119_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_119_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_119_ADDRESS                                          (0x3dc + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_119_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_119_RESET                                            0x0

// 0x3e0 (PHY_BB_RX_OCGAIN2_120)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_120_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_120_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_120_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_120_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_120_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_120_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_120_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_120_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_120_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_120_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_120_ADDRESS                                          (0x3e0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_120_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_120_RESET                                            0x0

// 0x3e4 (PHY_BB_RX_OCGAIN2_121)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_121_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_121_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_121_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_121_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_121_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_121_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_121_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_121_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_121_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_121_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_121_ADDRESS                                          (0x3e4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_121_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_121_RESET                                            0x0

// 0x3e8 (PHY_BB_RX_OCGAIN2_122)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_122_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_122_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_122_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_122_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_122_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_122_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_122_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_122_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_122_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_122_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_122_ADDRESS                                          (0x3e8 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_122_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_122_RESET                                            0x0

// 0x3ec (PHY_BB_RX_OCGAIN2_123)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_123_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_123_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_123_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_123_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_123_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_123_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_123_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_123_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_123_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_123_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_123_ADDRESS                                          (0x3ec + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_123_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_123_RESET                                            0x0

// 0x3f0 (PHY_BB_RX_OCGAIN2_124)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_124_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_124_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_124_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_124_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_124_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_124_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_124_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_124_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_124_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_124_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_124_ADDRESS                                          (0x3f0 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_124_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_124_RESET                                            0x0

// 0x3f4 (PHY_BB_RX_OCGAIN2_125)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_125_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_125_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_125_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_125_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_125_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_125_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_125_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_125_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_125_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_125_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_125_ADDRESS                                          (0x3f4 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_125_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_125_RESET                                            0x0

// 0x3f8 (PHY_BB_RX_OCGAIN2_126)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_126_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_126_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_126_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_126_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_126_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_126_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_126_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_126_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_126_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_126_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_126_ADDRESS                                          (0x3f8 + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_126_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_126_RESET                                            0x0

// 0x3fc (PHY_BB_RX_OCGAIN2_127)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_127_LSB                                  0
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_127_MSB                                  31
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_127_MASK                                 0xffffffff
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_127_GET(x)                               (((x) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_127_MASK) >> PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_127_LSB)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_127_SET(x)                               (((0 | (x)) << PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_127_LSB) & PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_127_MASK)
#define PHY_BB_RX_OCGAIN2_GAIN_ENTRY2_127_RESET                                0x0
#define PHY_BB_RX_OCGAIN2_127_ADDRESS                                          (0x3fc + __PHY_AGC1_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_OCGAIN2_127_RSTMASK                                          0xffffffff
#define PHY_BB_RX_OCGAIN2_127_RESET                                            0x0



#endif /* _PHY_AGC1_REG_MAP_H_ */
