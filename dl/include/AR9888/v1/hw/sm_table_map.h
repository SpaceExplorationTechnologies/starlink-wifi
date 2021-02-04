// ------------------------------------------------------------------
// Copyright (c) 2004-2012 Qualcomm Atheros.  All rights reserved.
// $ATH_LICENSE_TARGET_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Qualcomm Atheros"
//===================================================================



#ifndef _SM_TABLE_MAP_H_
#define _SM_TABLE_MAP_H_


/* macros for BB_aic_srams_b0 */
#define BB_SM_TIER_AIC_SRAMS_B0_ADDRESS                                                           0x00000000
#define BB_SM_TIER_AIC_SRAMS_B0_OFFSET                                                            0x00000000
#define BB_SM_TIER_AIC_SRAMS_B0_AIC_WORD_MSB                                                              19
#define BB_SM_TIER_AIC_SRAMS_B0_AIC_WORD_LSB                                                               0
#define BB_SM_TIER_AIC_SRAMS_B0_AIC_WORD_MASK                                                     0x000fffff
#define BB_SM_TIER_AIC_SRAMS_B0_AIC_WORD_GET(x)                                    (((x) & 0x000fffff) >> 0)
#define BB_SM_TIER_AIC_SRAMS_B0_AIC_WORD_SET(x)                                    (((x) << 0) & 0x000fffff)

/* macros for BB_aic_cal_srams_b0 */
#define BB_SM_TIER_AIC_CAL_SRAMS_B0_ADDRESS                                                       0x00000140
#define BB_SM_TIER_AIC_CAL_SRAMS_B0_OFFSET                                                        0x00000140
#define BB_SM_TIER_AIC_CAL_SRAMS_B0_AIC_WORD_MSB                                                          28
#define BB_SM_TIER_AIC_CAL_SRAMS_B0_AIC_WORD_LSB                                                           0
#define BB_SM_TIER_AIC_CAL_SRAMS_B0_AIC_WORD_MASK                                                 0x1fffffff
#define BB_SM_TIER_AIC_CAL_SRAMS_B0_AIC_WORD_GET(x)                                (((x) & 0x1fffffff) >> 0)
#define BB_SM_TIER_AIC_CAL_SRAMS_B0_AIC_WORD_SET(x)                                (((x) << 0) & 0x1fffffff)

/* macros for BB_aic_gain_tab_b0 */
#define BB_SM_TIER_AIC_GAIN_TAB_B0_ADDRESS                                                        0x00000280
#define BB_SM_TIER_AIC_GAIN_TAB_B0_OFFSET                                                         0x00000280
#define BB_SM_TIER_AIC_GAIN_TAB_B0_AIC_ATTEN_MSB                                                          17
#define BB_SM_TIER_AIC_GAIN_TAB_B0_AIC_ATTEN_LSB                                                           0
#define BB_SM_TIER_AIC_GAIN_TAB_B0_AIC_ATTEN_MASK                                                 0x0003ffff
#define BB_SM_TIER_AIC_GAIN_TAB_B0_AIC_ATTEN_GET(x)                                (((x) & 0x0003ffff) >> 0)
#define BB_SM_TIER_AIC_GAIN_TAB_B0_AIC_ATTEN_SET(x)                                (((x) << 0) & 0x0003ffff)

/* macros for BB_green_tx_gain_tab_1 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_1_ADDRESS                                                    0x000002cc
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_1_OFFSET                                                     0x000002cc
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_1_GREEN_TG_TABLE1_MSB                                                 6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_1_GREEN_TG_TABLE1_LSB                                                 0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_1_GREEN_TG_TABLE1_MASK                                       0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_1_GREEN_TG_TABLE1_GET(x)                      (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_1_GREEN_TG_TABLE1_SET(x)                      (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_2 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_2_ADDRESS                                                    0x000002d0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_2_OFFSET                                                     0x000002d0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_2_GREEN_TG_TABLE2_MSB                                                 6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_2_GREEN_TG_TABLE2_LSB                                                 0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_2_GREEN_TG_TABLE2_MASK                                       0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_2_GREEN_TG_TABLE2_GET(x)                      (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_2_GREEN_TG_TABLE2_SET(x)                      (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_3 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_3_ADDRESS                                                    0x000002d4
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_3_OFFSET                                                     0x000002d4
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_3_GREEN_TG_TABLE3_MSB                                                 6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_3_GREEN_TG_TABLE3_LSB                                                 0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_3_GREEN_TG_TABLE3_MASK                                       0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_3_GREEN_TG_TABLE3_GET(x)                      (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_3_GREEN_TG_TABLE3_SET(x)                      (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_4 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_4_ADDRESS                                                    0x000002d8
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_4_OFFSET                                                     0x000002d8
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_4_GREEN_TG_TABLE4_MSB                                                 6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_4_GREEN_TG_TABLE4_LSB                                                 0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_4_GREEN_TG_TABLE4_MASK                                       0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_4_GREEN_TG_TABLE4_GET(x)                      (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_4_GREEN_TG_TABLE4_SET(x)                      (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_5 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_5_ADDRESS                                                    0x000002dc
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_5_OFFSET                                                     0x000002dc
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_5_GREEN_TG_TABLE5_MSB                                                 6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_5_GREEN_TG_TABLE5_LSB                                                 0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_5_GREEN_TG_TABLE5_MASK                                       0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_5_GREEN_TG_TABLE5_GET(x)                      (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_5_GREEN_TG_TABLE5_SET(x)                      (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_6 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_6_ADDRESS                                                    0x000002e0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_6_OFFSET                                                     0x000002e0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_6_GREEN_TG_TABLE6_MSB                                                 6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_6_GREEN_TG_TABLE6_LSB                                                 0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_6_GREEN_TG_TABLE6_MASK                                       0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_6_GREEN_TG_TABLE6_GET(x)                      (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_6_GREEN_TG_TABLE6_SET(x)                      (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_7 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_7_ADDRESS                                                    0x000002e4
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_7_OFFSET                                                     0x000002e4
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_7_GREEN_TG_TABLE7_MSB                                                 6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_7_GREEN_TG_TABLE7_LSB                                                 0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_7_GREEN_TG_TABLE7_MASK                                       0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_7_GREEN_TG_TABLE7_GET(x)                      (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_7_GREEN_TG_TABLE7_SET(x)                      (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_8 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_8_ADDRESS                                                    0x000002e8
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_8_OFFSET                                                     0x000002e8
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_8_GREEN_TG_TABLE8_MSB                                                 6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_8_GREEN_TG_TABLE8_LSB                                                 0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_8_GREEN_TG_TABLE8_MASK                                       0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_8_GREEN_TG_TABLE8_GET(x)                      (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_8_GREEN_TG_TABLE8_SET(x)                      (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_9 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_9_ADDRESS                                                    0x000002ec
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_9_OFFSET                                                     0x000002ec
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_9_GREEN_TG_TABLE9_MSB                                                 6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_9_GREEN_TG_TABLE9_LSB                                                 0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_9_GREEN_TG_TABLE9_MASK                                       0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_9_GREEN_TG_TABLE9_GET(x)                      (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_9_GREEN_TG_TABLE9_SET(x)                      (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_10 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_10_ADDRESS                                                   0x000002f0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_10_OFFSET                                                    0x000002f0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_10_GREEN_TG_TABLE10_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_10_GREEN_TG_TABLE10_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_10_GREEN_TG_TABLE10_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_10_GREEN_TG_TABLE10_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_10_GREEN_TG_TABLE10_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_11 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_11_ADDRESS                                                   0x000002f4
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_11_OFFSET                                                    0x000002f4
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_11_GREEN_TG_TABLE11_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_11_GREEN_TG_TABLE11_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_11_GREEN_TG_TABLE11_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_11_GREEN_TG_TABLE11_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_11_GREEN_TG_TABLE11_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_12 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_12_ADDRESS                                                   0x000002f8
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_12_OFFSET                                                    0x000002f8
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_12_GREEN_TG_TABLE12_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_12_GREEN_TG_TABLE12_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_12_GREEN_TG_TABLE12_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_12_GREEN_TG_TABLE12_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_12_GREEN_TG_TABLE12_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_13 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_13_ADDRESS                                                   0x000002fc
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_13_OFFSET                                                    0x000002fc
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_13_GREEN_TG_TABLE13_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_13_GREEN_TG_TABLE13_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_13_GREEN_TG_TABLE13_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_13_GREEN_TG_TABLE13_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_13_GREEN_TG_TABLE13_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_14 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_14_ADDRESS                                                   0x00000300
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_14_OFFSET                                                    0x00000300
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_14_GREEN_TG_TABLE14_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_14_GREEN_TG_TABLE14_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_14_GREEN_TG_TABLE14_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_14_GREEN_TG_TABLE14_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_14_GREEN_TG_TABLE14_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_15 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_15_ADDRESS                                                   0x00000304
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_15_OFFSET                                                    0x00000304
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_15_GREEN_TG_TABLE15_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_15_GREEN_TG_TABLE15_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_15_GREEN_TG_TABLE15_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_15_GREEN_TG_TABLE15_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_15_GREEN_TG_TABLE15_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_16 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_16_ADDRESS                                                   0x00000308
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_16_OFFSET                                                    0x00000308
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_16_GREEN_TG_TABLE16_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_16_GREEN_TG_TABLE16_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_16_GREEN_TG_TABLE16_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_16_GREEN_TG_TABLE16_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_16_GREEN_TG_TABLE16_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_17 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_17_ADDRESS                                                   0x0000030c
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_17_OFFSET                                                    0x0000030c
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_17_GREEN_TG_TABLE17_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_17_GREEN_TG_TABLE17_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_17_GREEN_TG_TABLE17_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_17_GREEN_TG_TABLE17_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_17_GREEN_TG_TABLE17_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_18 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_18_ADDRESS                                                   0x00000310
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_18_OFFSET                                                    0x00000310
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_18_GREEN_TG_TABLE18_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_18_GREEN_TG_TABLE18_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_18_GREEN_TG_TABLE18_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_18_GREEN_TG_TABLE18_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_18_GREEN_TG_TABLE18_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_19 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_19_ADDRESS                                                   0x00000314
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_19_OFFSET                                                    0x00000314
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_19_GREEN_TG_TABLE19_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_19_GREEN_TG_TABLE19_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_19_GREEN_TG_TABLE19_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_19_GREEN_TG_TABLE19_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_19_GREEN_TG_TABLE19_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_20 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_20_ADDRESS                                                   0x00000318
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_20_OFFSET                                                    0x00000318
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_20_GREEN_TG_TABLE20_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_20_GREEN_TG_TABLE20_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_20_GREEN_TG_TABLE20_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_20_GREEN_TG_TABLE20_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_20_GREEN_TG_TABLE20_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_21 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_21_ADDRESS                                                   0x0000031c
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_21_OFFSET                                                    0x0000031c
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_21_GREEN_TG_TABLE21_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_21_GREEN_TG_TABLE21_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_21_GREEN_TG_TABLE21_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_21_GREEN_TG_TABLE21_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_21_GREEN_TG_TABLE21_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_22 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_22_ADDRESS                                                   0x00000320
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_22_OFFSET                                                    0x00000320
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_22_GREEN_TG_TABLE22_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_22_GREEN_TG_TABLE22_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_22_GREEN_TG_TABLE22_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_22_GREEN_TG_TABLE22_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_22_GREEN_TG_TABLE22_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_23 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_23_ADDRESS                                                   0x00000324
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_23_OFFSET                                                    0x00000324
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_23_GREEN_TG_TABLE23_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_23_GREEN_TG_TABLE23_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_23_GREEN_TG_TABLE23_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_23_GREEN_TG_TABLE23_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_23_GREEN_TG_TABLE23_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_24 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_24_ADDRESS                                                   0x00000328
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_24_OFFSET                                                    0x00000328
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_24_GREEN_TG_TABLE24_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_24_GREEN_TG_TABLE24_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_24_GREEN_TG_TABLE24_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_24_GREEN_TG_TABLE24_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_24_GREEN_TG_TABLE24_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_25 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_25_ADDRESS                                                   0x0000032c
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_25_OFFSET                                                    0x0000032c
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_25_GREEN_TG_TABLE25_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_25_GREEN_TG_TABLE25_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_25_GREEN_TG_TABLE25_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_25_GREEN_TG_TABLE25_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_25_GREEN_TG_TABLE25_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_26 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_26_ADDRESS                                                   0x00000330
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_26_OFFSET                                                    0x00000330
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_26_GREEN_TG_TABLE26_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_26_GREEN_TG_TABLE26_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_26_GREEN_TG_TABLE26_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_26_GREEN_TG_TABLE26_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_26_GREEN_TG_TABLE26_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_27 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_27_ADDRESS                                                   0x00000334
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_27_OFFSET                                                    0x00000334
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_27_GREEN_TG_TABLE27_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_27_GREEN_TG_TABLE27_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_27_GREEN_TG_TABLE27_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_27_GREEN_TG_TABLE27_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_27_GREEN_TG_TABLE27_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_28 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_28_ADDRESS                                                   0x00000338
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_28_OFFSET                                                    0x00000338
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_28_GREEN_TG_TABLE28_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_28_GREEN_TG_TABLE28_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_28_GREEN_TG_TABLE28_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_28_GREEN_TG_TABLE28_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_28_GREEN_TG_TABLE28_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_29 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_29_ADDRESS                                                   0x0000033c
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_29_OFFSET                                                    0x0000033c
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_29_GREEN_TG_TABLE29_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_29_GREEN_TG_TABLE29_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_29_GREEN_TG_TABLE29_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_29_GREEN_TG_TABLE29_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_29_GREEN_TG_TABLE29_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_30 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_30_ADDRESS                                                   0x00000340
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_30_OFFSET                                                    0x00000340
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_30_GREEN_TG_TABLE30_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_30_GREEN_TG_TABLE30_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_30_GREEN_TG_TABLE30_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_30_GREEN_TG_TABLE30_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_30_GREEN_TG_TABLE30_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_31 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_31_ADDRESS                                                   0x00000344
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_31_OFFSET                                                    0x00000344
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_31_GREEN_TG_TABLE31_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_31_GREEN_TG_TABLE31_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_31_GREEN_TG_TABLE31_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_31_GREEN_TG_TABLE31_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_31_GREEN_TG_TABLE31_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_green_tx_gain_tab_32 */
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_32_ADDRESS                                                   0x00000348
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_32_OFFSET                                                    0x00000348
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_32_GREEN_TG_TABLE32_MSB                                               6
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_32_GREEN_TG_TABLE32_LSB                                               0
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_32_GREEN_TG_TABLE32_MASK                                     0x0000007f
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_32_GREEN_TG_TABLE32_GET(x)                    (((x) & 0x0000007f) >> 0)
#define BB_SM_TIER_GREEN_TX_GAIN_TAB_32_GREEN_TG_TABLE32_SET(x)                    (((x) << 0) & 0x0000007f)

/* macros for BB_dc_dac_mem_b0 */
#define BB_SM_TIER_DC_DAC_MEM_B0_ADDRESS                                                          0x000003c0
#define BB_SM_TIER_DC_DAC_MEM_B0_OFFSET                                                           0x000003c0
#define BB_SM_TIER_DC_DAC_MEM_B0_DC_DAC_SETTING_MSB                                                       19
#define BB_SM_TIER_DC_DAC_MEM_B0_DC_DAC_SETTING_LSB                                                        0
#define BB_SM_TIER_DC_DAC_MEM_B0_DC_DAC_SETTING_MASK                                              0x000fffff
#define BB_SM_TIER_DC_DAC_MEM_B0_DC_DAC_SETTING_GET(x)                             (((x) & 0x000fffff) >> 0)
#define BB_SM_TIER_DC_DAC_MEM_B0_DC_DAC_SETTING_SET(x)                             (((x) << 0) & 0x000fffff)

/* macros for BB_sm_tables_dummy2 */
#define BB_SM_TIER_SM_TABLES_DUMMY2_ADDRESS                                                       0x000005fc
#define BB_SM_TIER_SM_TABLES_DUMMY2_OFFSET                                                        0x000005fc
#define BB_SM_TIER_SM_TABLES_DUMMY2_DUMMY2_MSB                                                            31
#define BB_SM_TIER_SM_TABLES_DUMMY2_DUMMY2_LSB                                                             0
#define BB_SM_TIER_SM_TABLES_DUMMY2_DUMMY2_MASK                                                   0xffffffff
#define BB_SM_TIER_SM_TABLES_DUMMY2_DUMMY2_GET(x)                                  (((x) & 0xffffffff) >> 0)
#define BB_SM_TIER_SM_TABLES_DUMMY2_DUMMY2_SET(x)                                  (((x) << 0) & 0xffffffff)


#ifndef __ASSEMBLER__

typedef struct sm_table_map_reg_s {
  volatile unsigned int BB_SM_TIER_aic_srams_b0[80];                           /*        0x0 - 0x140      */
  volatile unsigned int BB_SM_TIER_aic_cal_srams_b0[80];                       /*      0x140 - 0x280      */
  volatile unsigned int BB_SM_TIER_aic_gain_tab_b0[19];                        /*      0x280 - 0x2cc      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_1;                        /*      0x2cc - 0x2d0      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_2;                        /*      0x2d0 - 0x2d4      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_3;                        /*      0x2d4 - 0x2d8      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_4;                        /*      0x2d8 - 0x2dc      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_5;                        /*      0x2dc - 0x2e0      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_6;                        /*      0x2e0 - 0x2e4      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_7;                        /*      0x2e4 - 0x2e8      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_8;                        /*      0x2e8 - 0x2ec      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_9;                        /*      0x2ec - 0x2f0      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_10;                       /*      0x2f0 - 0x2f4      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_11;                       /*      0x2f4 - 0x2f8      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_12;                       /*      0x2f8 - 0x2fc      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_13;                       /*      0x2fc - 0x300      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_14;                       /*      0x300 - 0x304      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_15;                       /*      0x304 - 0x308      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_16;                       /*      0x308 - 0x30c      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_17;                       /*      0x30c - 0x310      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_18;                       /*      0x310 - 0x314      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_19;                       /*      0x314 - 0x318      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_20;                       /*      0x318 - 0x31c      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_21;                       /*      0x31c - 0x320      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_22;                       /*      0x320 - 0x324      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_23;                       /*      0x324 - 0x328      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_24;                       /*      0x328 - 0x32c      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_25;                       /*      0x32c - 0x330      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_26;                       /*      0x330 - 0x334      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_27;                       /*      0x334 - 0x338      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_28;                       /*      0x338 - 0x33c      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_29;                       /*      0x33c - 0x340      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_30;                       /*      0x340 - 0x344      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_31;                       /*      0x344 - 0x348      */
  volatile unsigned int BB_SM_TIER_green_tx_gain_tab_32;                       /*      0x348 - 0x34c      */
  volatile char pad__0[0x74];                                          /*      0x34c - 0x3c0      */
  volatile unsigned int BB_SM_TIER_dc_dac_mem_b0[4];                           /*      0x3c0 - 0x3d0      */
  volatile char pad__1[0x22c];                                         /*      0x3d0 - 0x5fc      */
  volatile unsigned int BB_SM_TIER_sm_tables_dummy2;                           /*      0x5fc - 0x600      */
} sm_table_map_reg_t;

#endif /* __ASSEMBLER__ */

#endif /* _SM_TABLE_MAP_H_ */
