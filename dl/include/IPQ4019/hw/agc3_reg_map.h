/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _PHY_AGC3_REG_MAP_H_
#define _PHY_AGC3_REG_MAP_H_


#ifndef __PHY_AGC3_REG_MAP_BASE_ADDRESS
#define __PHY_AGC3_REG_MAP_BASE_ADDRESS (0x13000)
#endif


// 0x4 (PHY_BB_GAIN_FORCE_MAX_GAINS_B3)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_HYST_MARGIN_3_LSB               25
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_HYST_MARGIN_3_MSB               31
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_HYST_MARGIN_3_MASK              0xfe000000
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_HYST_MARGIN_3_GET(x)            (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_HYST_MARGIN_3_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_HYST_MARGIN_3_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_HYST_MARGIN_3_SET(x)            (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_HYST_MARGIN_3_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_HYST_MARGIN_3_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_HYST_MARGIN_3_RESET             0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_HYST_MARGIN_3_LSB               18
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_HYST_MARGIN_3_MSB               24
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_HYST_MARGIN_3_MASK              0x1fc0000
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_HYST_MARGIN_3_GET(x)            (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_HYST_MARGIN_3_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_HYST_MARGIN_3_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_HYST_MARGIN_3_SET(x)            (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_HYST_MARGIN_3_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_HYST_MARGIN_3_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_HYST_MARGIN_3_RESET             0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_SW_F_3_LSB                      17
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_SW_F_3_MSB                      17
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_SW_F_3_MASK                     0x20000
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_SW_F_3_GET(x)                   (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_SW_F_3_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_SW_F_3_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_SW_F_3_SET(x)                   (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_SW_F_3_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_SW_F_3_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN2_SW_F_3_RESET                    0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_SW_F_3_LSB                      16
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_SW_F_3_MSB                      16
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_SW_F_3_MASK                     0x10000
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_SW_F_3_GET(x)                   (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_SW_F_3_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_SW_F_3_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_SW_F_3_SET(x)                   (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_SW_F_3_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_SW_F_3_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_XATTEN1_SW_F_3_RESET                    0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_MB_GAIN_F_3_LSB                         8
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_MB_GAIN_F_3_MSB                         15
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_MB_GAIN_F_3_MASK                        0xff00
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_MB_GAIN_F_3_GET(x)                      (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B3_MB_GAIN_F_3_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B3_MB_GAIN_F_3_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_MB_GAIN_F_3_SET(x)                      (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B3_MB_GAIN_F_3_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B3_MB_GAIN_F_3_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_MB_GAIN_F_3_RESET                       0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_RF_GAIN_F_3_LSB                         0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_RF_GAIN_F_3_MSB                         7
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_RF_GAIN_F_3_MASK                        0xff
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_RF_GAIN_F_3_GET(x)                      (((x) & PHY_BB_GAIN_FORCE_MAX_GAINS_B3_RF_GAIN_F_3_MASK) >> PHY_BB_GAIN_FORCE_MAX_GAINS_B3_RF_GAIN_F_3_LSB)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_RF_GAIN_F_3_SET(x)                      (((0 | (x)) << PHY_BB_GAIN_FORCE_MAX_GAINS_B3_RF_GAIN_F_3_LSB) & PHY_BB_GAIN_FORCE_MAX_GAINS_B3_RF_GAIN_F_3_MASK)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_RF_GAIN_F_3_RESET                       0x0
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_ADDRESS                                 (0x4 + __PHY_AGC3_REG_MAP_BASE_ADDRESS)
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_RSTMASK                                 0xffffffff
#define PHY_BB_GAIN_FORCE_MAX_GAINS_B3_RESET                                   0x0

// 0x18 (PHY_BB_EXT_ATTEN_SWITCH_CTL_B3)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XLNA_GAIN_DB_3_LSB                      24
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XLNA_GAIN_DB_3_MSB                      28
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XLNA_GAIN_DB_3_MASK                     0x1f000000
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XLNA_GAIN_DB_3_GET(x)                   (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XLNA_GAIN_DB_3_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XLNA_GAIN_DB_3_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XLNA_GAIN_DB_3_SET(x)                   (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XLNA_GAIN_DB_3_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XLNA_GAIN_DB_3_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XLNA_GAIN_DB_3_RESET                    0x0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_MARGIN_3_LSB                    18
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_MARGIN_3_MSB                    23
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_MARGIN_3_MASK                   0xfc0000
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_MARGIN_3_GET(x)                 (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_MARGIN_3_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_MARGIN_3_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_MARGIN_3_SET(x)                 (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_MARGIN_3_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_MARGIN_3_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_MARGIN_3_RESET                  0x0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_MARGIN_3_LSB                    12
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_MARGIN_3_MSB                    17
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_MARGIN_3_MASK                   0x3f000
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_MARGIN_3_GET(x)                 (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_MARGIN_3_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_MARGIN_3_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_MARGIN_3_SET(x)                 (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_MARGIN_3_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_MARGIN_3_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_MARGIN_3_RESET                  0x32
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_DB_3_LSB                        6
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_DB_3_MSB                        11
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_DB_3_MASK                       0xfc0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_DB_3_GET(x)                     (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_DB_3_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_DB_3_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_DB_3_SET(x)                     (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_DB_3_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_DB_3_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN2_DB_3_RESET                      0x0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_DB_3_LSB                        0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_DB_3_MSB                        5
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_DB_3_MASK                       0x3f
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_DB_3_GET(x)                     (((x) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_DB_3_MASK) >> PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_DB_3_LSB)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_DB_3_SET(x)                     (((0 | (x)) << PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_DB_3_LSB) & PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_DB_3_MASK)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_XATTEN1_DB_3_RESET                      0x0
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_ADDRESS                                 (0x18 + __PHY_AGC3_REG_MAP_BASE_ADDRESS)
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_RSTMASK                                 0x1fffffff
#define PHY_BB_EXT_ATTEN_SWITCH_CTL_B3_RESET                                   0x32000

// 0x1c (PHY_BB_CCA_B3)
#define PHY_BB_CCA_B3_MINCCAPWR_3_LSB                                          20
#define PHY_BB_CCA_B3_MINCCAPWR_3_MSB                                          28
#define PHY_BB_CCA_B3_MINCCAPWR_3_MASK                                         0x1ff00000
#define PHY_BB_CCA_B3_MINCCAPWR_3_GET(x)                                       (((x) & PHY_BB_CCA_B3_MINCCAPWR_3_MASK) >> PHY_BB_CCA_B3_MINCCAPWR_3_LSB)
#define PHY_BB_CCA_B3_MINCCAPWR_3_SET(x)                                       (((0 | (x)) << PHY_BB_CCA_B3_MINCCAPWR_3_LSB) & PHY_BB_CCA_B3_MINCCAPWR_3_MASK)
#define PHY_BB_CCA_B3_MINCCAPWR_3_RESET                                        0x0
#define PHY_BB_CCA_B3_CF_MAXCCAPWR_3_LSB                                       0
#define PHY_BB_CCA_B3_CF_MAXCCAPWR_3_MSB                                       8
#define PHY_BB_CCA_B3_CF_MAXCCAPWR_3_MASK                                      0x1ff
#define PHY_BB_CCA_B3_CF_MAXCCAPWR_3_GET(x)                                    (((x) & PHY_BB_CCA_B3_CF_MAXCCAPWR_3_MASK) >> PHY_BB_CCA_B3_CF_MAXCCAPWR_3_LSB)
#define PHY_BB_CCA_B3_CF_MAXCCAPWR_3_SET(x)                                    (((0 | (x)) << PHY_BB_CCA_B3_CF_MAXCCAPWR_3_LSB) & PHY_BB_CCA_B3_CF_MAXCCAPWR_3_MASK)
#define PHY_BB_CCA_B3_CF_MAXCCAPWR_3_RESET                                     0x0
#define PHY_BB_CCA_B3_ADDRESS                                                  (0x1c + __PHY_AGC3_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CCA_B3_RSTMASK                                                  0x1ff001ff
#define PHY_BB_CCA_B3_RESET                                                    0x0

// 0x20 (PHY_BB_CCA_CTRL_2_B3)
#define PHY_BB_CCA_CTRL_2_B3_NF_GAIN_COMP_3_LSB                                10
#define PHY_BB_CCA_CTRL_2_B3_NF_GAIN_COMP_3_MSB                                17
#define PHY_BB_CCA_CTRL_2_B3_NF_GAIN_COMP_3_MASK                               0x3fc00
#define PHY_BB_CCA_CTRL_2_B3_NF_GAIN_COMP_3_GET(x)                             (((x) & PHY_BB_CCA_CTRL_2_B3_NF_GAIN_COMP_3_MASK) >> PHY_BB_CCA_CTRL_2_B3_NF_GAIN_COMP_3_LSB)
#define PHY_BB_CCA_CTRL_2_B3_NF_GAIN_COMP_3_SET(x)                             (((0 | (x)) << PHY_BB_CCA_CTRL_2_B3_NF_GAIN_COMP_3_LSB) & PHY_BB_CCA_CTRL_2_B3_NF_GAIN_COMP_3_MASK)
#define PHY_BB_CCA_CTRL_2_B3_NF_GAIN_COMP_3_RESET                              0x0
#define PHY_BB_CCA_CTRL_2_B3_MINCCAPWR_THR_3_LSB                               0
#define PHY_BB_CCA_CTRL_2_B3_MINCCAPWR_THR_3_MSB                               8
#define PHY_BB_CCA_CTRL_2_B3_MINCCAPWR_THR_3_MASK                              0x1ff
#define PHY_BB_CCA_CTRL_2_B3_MINCCAPWR_THR_3_GET(x)                            (((x) & PHY_BB_CCA_CTRL_2_B3_MINCCAPWR_THR_3_MASK) >> PHY_BB_CCA_CTRL_2_B3_MINCCAPWR_THR_3_LSB)
#define PHY_BB_CCA_CTRL_2_B3_MINCCAPWR_THR_3_SET(x)                            (((0 | (x)) << PHY_BB_CCA_CTRL_2_B3_MINCCAPWR_THR_3_LSB) & PHY_BB_CCA_CTRL_2_B3_MINCCAPWR_THR_3_MASK)
#define PHY_BB_CCA_CTRL_2_B3_MINCCAPWR_THR_3_RESET                             0x0
#define PHY_BB_CCA_CTRL_2_B3_ADDRESS                                           (0x20 + __PHY_AGC3_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CCA_CTRL_2_B3_RSTMASK                                           0x3fdff
#define PHY_BB_CCA_CTRL_2_B3_RESET                                             0x0

// 0x180 (PHY_BB_RSSI_B3)
#define PHY_BB_RSSI_B3_RSSI_EXT80_3_LSB                                        24
#define PHY_BB_RSSI_B3_RSSI_EXT80_3_MSB                                        31
#define PHY_BB_RSSI_B3_RSSI_EXT80_3_MASK                                       0xff000000
#define PHY_BB_RSSI_B3_RSSI_EXT80_3_GET(x)                                     (((x) & PHY_BB_RSSI_B3_RSSI_EXT80_3_MASK) >> PHY_BB_RSSI_B3_RSSI_EXT80_3_LSB)
#define PHY_BB_RSSI_B3_RSSI_EXT80_3_SET(x)                                     (((0 | (x)) << PHY_BB_RSSI_B3_RSSI_EXT80_3_LSB) & PHY_BB_RSSI_B3_RSSI_EXT80_3_MASK)
#define PHY_BB_RSSI_B3_RSSI_EXT80_3_RESET                                      0x0
#define PHY_BB_RSSI_B3_RSSI_EXT40_3_LSB                                        16
#define PHY_BB_RSSI_B3_RSSI_EXT40_3_MSB                                        23
#define PHY_BB_RSSI_B3_RSSI_EXT40_3_MASK                                       0xff0000
#define PHY_BB_RSSI_B3_RSSI_EXT40_3_GET(x)                                     (((x) & PHY_BB_RSSI_B3_RSSI_EXT40_3_MASK) >> PHY_BB_RSSI_B3_RSSI_EXT40_3_LSB)
#define PHY_BB_RSSI_B3_RSSI_EXT40_3_SET(x)                                     (((0 | (x)) << PHY_BB_RSSI_B3_RSSI_EXT40_3_LSB) & PHY_BB_RSSI_B3_RSSI_EXT40_3_MASK)
#define PHY_BB_RSSI_B3_RSSI_EXT40_3_RESET                                      0x0
#define PHY_BB_RSSI_B3_RSSI_EXT20_3_LSB                                        8
#define PHY_BB_RSSI_B3_RSSI_EXT20_3_MSB                                        15
#define PHY_BB_RSSI_B3_RSSI_EXT20_3_MASK                                       0xff00
#define PHY_BB_RSSI_B3_RSSI_EXT20_3_GET(x)                                     (((x) & PHY_BB_RSSI_B3_RSSI_EXT20_3_MASK) >> PHY_BB_RSSI_B3_RSSI_EXT20_3_LSB)
#define PHY_BB_RSSI_B3_RSSI_EXT20_3_SET(x)                                     (((0 | (x)) << PHY_BB_RSSI_B3_RSSI_EXT20_3_LSB) & PHY_BB_RSSI_B3_RSSI_EXT20_3_MASK)
#define PHY_BB_RSSI_B3_RSSI_EXT20_3_RESET                                      0x0
#define PHY_BB_RSSI_B3_RSSI_PRI20_3_LSB                                        0
#define PHY_BB_RSSI_B3_RSSI_PRI20_3_MSB                                        7
#define PHY_BB_RSSI_B3_RSSI_PRI20_3_MASK                                       0xff
#define PHY_BB_RSSI_B3_RSSI_PRI20_3_GET(x)                                     (((x) & PHY_BB_RSSI_B3_RSSI_PRI20_3_MASK) >> PHY_BB_RSSI_B3_RSSI_PRI20_3_LSB)
#define PHY_BB_RSSI_B3_RSSI_PRI20_3_SET(x)                                     (((0 | (x)) << PHY_BB_RSSI_B3_RSSI_PRI20_3_LSB) & PHY_BB_RSSI_B3_RSSI_PRI20_3_MASK)
#define PHY_BB_RSSI_B3_RSSI_PRI20_3_RESET                                      0x0
#define PHY_BB_RSSI_B3_ADDRESS                                                 (0x180 + __PHY_AGC3_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RSSI_B3_RSTMASK                                                 0xffffffff
#define PHY_BB_RSSI_B3_RESET                                                   0x0

// 0x188 (PHY_BB_AGC_DIG_DC_STATUS_B3)
#define PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_Q_3_LSB                 10
#define PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_Q_3_MSB                 19
#define PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_Q_3_MASK                0xffc00
#define PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_Q_3_GET(x)              (((x) & PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_Q_3_MASK) >> PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_Q_3_LSB)
#define PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_Q_3_SET(x)              (((0 | (x)) << PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_Q_3_LSB) & PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_Q_3_MASK)
#define PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_Q_3_RESET               0x0
#define PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_I_3_LSB                 0
#define PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_I_3_MSB                 9
#define PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_I_3_MASK                0x3ff
#define PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_I_3_GET(x)              (((x) & PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_I_3_MASK) >> PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_I_3_LSB)
#define PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_I_3_SET(x)              (((0 | (x)) << PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_I_3_LSB) & PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_I_3_MASK)
#define PHY_BB_AGC_DIG_DC_STATUS_B3_DC_CAL_RESIDUAL_DC_I_3_RESET               0x0
#define PHY_BB_AGC_DIG_DC_STATUS_B3_ADDRESS                                    (0x188 + __PHY_AGC3_REG_MAP_BASE_ADDRESS)
#define PHY_BB_AGC_DIG_DC_STATUS_B3_RSTMASK                                    0xfffff
#define PHY_BB_AGC_DIG_DC_STATUS_B3_RESET                                      0x0

// 0x1a0 (PHY_BB_DC_CAL_STATUS_B3)
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC2Q_3_LSB                                24
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC2Q_3_MSB                                31
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC2Q_3_MASK                               0xff000000
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC2Q_3_GET(x)                             (((x) & PHY_BB_DC_CAL_STATUS_B3_OFFSETC2Q_3_MASK) >> PHY_BB_DC_CAL_STATUS_B3_OFFSETC2Q_3_LSB)
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC2Q_3_SET(x)                             (((0 | (x)) << PHY_BB_DC_CAL_STATUS_B3_OFFSETC2Q_3_LSB) & PHY_BB_DC_CAL_STATUS_B3_OFFSETC2Q_3_MASK)
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC2Q_3_RESET                              0x0
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC2I_3_LSB                                16
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC2I_3_MSB                                23
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC2I_3_MASK                               0xff0000
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC2I_3_GET(x)                             (((x) & PHY_BB_DC_CAL_STATUS_B3_OFFSETC2I_3_MASK) >> PHY_BB_DC_CAL_STATUS_B3_OFFSETC2I_3_LSB)
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC2I_3_SET(x)                             (((0 | (x)) << PHY_BB_DC_CAL_STATUS_B3_OFFSETC2I_3_LSB) & PHY_BB_DC_CAL_STATUS_B3_OFFSETC2I_3_MASK)
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC2I_3_RESET                              0x0
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC1Q_3_LSB                                8
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC1Q_3_MSB                                15
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC1Q_3_MASK                               0xff00
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC1Q_3_GET(x)                             (((x) & PHY_BB_DC_CAL_STATUS_B3_OFFSETC1Q_3_MASK) >> PHY_BB_DC_CAL_STATUS_B3_OFFSETC1Q_3_LSB)
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC1Q_3_SET(x)                             (((0 | (x)) << PHY_BB_DC_CAL_STATUS_B3_OFFSETC1Q_3_LSB) & PHY_BB_DC_CAL_STATUS_B3_OFFSETC1Q_3_MASK)
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC1Q_3_RESET                              0x0
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC1I_3_LSB                                0
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC1I_3_MSB                                7
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC1I_3_MASK                               0xff
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC1I_3_GET(x)                             (((x) & PHY_BB_DC_CAL_STATUS_B3_OFFSETC1I_3_MASK) >> PHY_BB_DC_CAL_STATUS_B3_OFFSETC1I_3_LSB)
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC1I_3_SET(x)                             (((0 | (x)) << PHY_BB_DC_CAL_STATUS_B3_OFFSETC1I_3_LSB) & PHY_BB_DC_CAL_STATUS_B3_OFFSETC1I_3_MASK)
#define PHY_BB_DC_CAL_STATUS_B3_OFFSETC1I_3_RESET                              0x0
#define PHY_BB_DC_CAL_STATUS_B3_ADDRESS                                        (0x1a0 + __PHY_AGC3_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DC_CAL_STATUS_B3_RSTMASK                                        0xffffffff
#define PHY_BB_DC_CAL_STATUS_B3_RESET                                          0x0

// 0x1a4 (PHY_BB_DC_CAL_STATUS_2_B3)
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4Q_3_LSB                              24
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4Q_3_MSB                              31
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4Q_3_MASK                             0xff000000
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4Q_3_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4Q_3_MASK) >> PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4Q_3_LSB)
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4Q_3_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4Q_3_LSB) & PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4Q_3_MASK)
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4Q_3_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4I_3_LSB                              16
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4I_3_MSB                              23
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4I_3_MASK                             0xff0000
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4I_3_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4I_3_MASK) >> PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4I_3_LSB)
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4I_3_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4I_3_LSB) & PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4I_3_MASK)
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC4I_3_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3Q_3_LSB                              8
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3Q_3_MSB                              15
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3Q_3_MASK                             0xff00
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3Q_3_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3Q_3_MASK) >> PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3Q_3_LSB)
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3Q_3_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3Q_3_LSB) & PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3Q_3_MASK)
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3Q_3_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3I_3_LSB                              0
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3I_3_MSB                              7
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3I_3_MASK                             0xff
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3I_3_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3I_3_MASK) >> PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3I_3_LSB)
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3I_3_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3I_3_LSB) & PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3I_3_MASK)
#define PHY_BB_DC_CAL_STATUS_2_B3_OFFSETC3I_3_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_2_B3_ADDRESS                                      (0x1a4 + __PHY_AGC3_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DC_CAL_STATUS_2_B3_RSTMASK                                      0xffffffff
#define PHY_BB_DC_CAL_STATUS_2_B3_RESET                                        0x0

// 0x1a8 (PHY_BB_DC_CAL_STATUS_3_B3)
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6Q_3_LSB                              24
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6Q_3_MSB                              31
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6Q_3_MASK                             0xff000000
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6Q_3_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6Q_3_MASK) >> PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6Q_3_LSB)
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6Q_3_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6Q_3_LSB) & PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6Q_3_MASK)
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6Q_3_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6I_3_LSB                              16
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6I_3_MSB                              23
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6I_3_MASK                             0xff0000
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6I_3_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6I_3_MASK) >> PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6I_3_LSB)
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6I_3_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6I_3_LSB) & PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6I_3_MASK)
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC6I_3_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5Q_3_LSB                              8
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5Q_3_MSB                              15
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5Q_3_MASK                             0xff00
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5Q_3_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5Q_3_MASK) >> PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5Q_3_LSB)
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5Q_3_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5Q_3_LSB) & PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5Q_3_MASK)
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5Q_3_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5I_3_LSB                              0
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5I_3_MSB                              7
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5I_3_MASK                             0xff
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5I_3_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5I_3_MASK) >> PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5I_3_LSB)
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5I_3_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5I_3_LSB) & PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5I_3_MASK)
#define PHY_BB_DC_CAL_STATUS_3_B3_OFFSETC5I_3_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_3_B3_ADDRESS                                      (0x1a8 + __PHY_AGC3_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DC_CAL_STATUS_3_B3_RSTMASK                                      0xffffffff
#define PHY_BB_DC_CAL_STATUS_3_B3_RESET                                        0x0

// 0x1ac (PHY_BB_DC_CAL_STATUS_4_B3)
#define PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7Q_3_LSB                              8
#define PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7Q_3_MSB                              15
#define PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7Q_3_MASK                             0xff00
#define PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7Q_3_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7Q_3_MASK) >> PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7Q_3_LSB)
#define PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7Q_3_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7Q_3_LSB) & PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7Q_3_MASK)
#define PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7Q_3_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7I_3_LSB                              0
#define PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7I_3_MSB                              7
#define PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7I_3_MASK                             0xff
#define PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7I_3_GET(x)                           (((x) & PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7I_3_MASK) >> PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7I_3_LSB)
#define PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7I_3_SET(x)                           (((0 | (x)) << PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7I_3_LSB) & PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7I_3_MASK)
#define PHY_BB_DC_CAL_STATUS_4_B3_OFFSETC7I_3_RESET                            0x0
#define PHY_BB_DC_CAL_STATUS_4_B3_ADDRESS                                      (0x1ac + __PHY_AGC3_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DC_CAL_STATUS_4_B3_RSTMASK                                      0xffff
#define PHY_BB_DC_CAL_STATUS_4_B3_RESET                                        0x0

// 0x1b0 (PHY_BB_RX_GAIN_NF_B3)
#define PHY_BB_RX_GAIN_NF_B3_GAIN_VAL_AFTER_NF_3_LSB                           0
#define PHY_BB_RX_GAIN_NF_B3_GAIN_VAL_AFTER_NF_3_MSB                           16
#define PHY_BB_RX_GAIN_NF_B3_GAIN_VAL_AFTER_NF_3_MASK                          0x1ffff
#define PHY_BB_RX_GAIN_NF_B3_GAIN_VAL_AFTER_NF_3_GET(x)                        (((x) & PHY_BB_RX_GAIN_NF_B3_GAIN_VAL_AFTER_NF_3_MASK) >> PHY_BB_RX_GAIN_NF_B3_GAIN_VAL_AFTER_NF_3_LSB)
#define PHY_BB_RX_GAIN_NF_B3_GAIN_VAL_AFTER_NF_3_SET(x)                        (((0 | (x)) << PHY_BB_RX_GAIN_NF_B3_GAIN_VAL_AFTER_NF_3_LSB) & PHY_BB_RX_GAIN_NF_B3_GAIN_VAL_AFTER_NF_3_MASK)
#define PHY_BB_RX_GAIN_NF_B3_GAIN_VAL_AFTER_NF_3_RESET                         0x0
#define PHY_BB_RX_GAIN_NF_B3_ADDRESS                                           (0x1b0 + __PHY_AGC3_REG_MAP_BASE_ADDRESS)
#define PHY_BB_RX_GAIN_NF_B3_RSTMASK                                           0x1ffff
#define PHY_BB_RX_GAIN_NF_B3_RESET                                             0x0



#endif /* _PHY_AGC3_REG_MAP_H_ */
