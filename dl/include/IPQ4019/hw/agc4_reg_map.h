/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _PHY_AGC4_REG_MAP_H_
#define _PHY_AGC4_REG_MAP_H_


#ifndef __PHY_AGC4_REG_MAP_BASE_ADDRESS
#define __PHY_AGC4_REG_MAP_BASE_ADDRESS (0x14000)
#endif


// 0x0 (PHY_BB_DUMMY_AGC_BCAST)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_LSB                                       0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_MSB                                       31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_MASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_GET(x)                                    (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_SET(x)                                    (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_RESET                                     0x0
#define PHY_BB_DUMMY_AGC_BCAST_ADDRESS                                         (0x0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_RSTMASK                                         0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_RESET                                           0x0

// 0x0 (PHY_BB_DUMMY_AGC_BCAST_0)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_0_LSB                                     0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_0_MSB                                     31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_0_MASK                                    0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_0_GET(x)                                  (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_0_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_0_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_0_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_0_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_0_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_0_RESET                                   0x0
#define PHY_BB_DUMMY_AGC_BCAST_0_ADDRESS                                       (0x0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_0_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_0_RESET                                         0x0

// 0x4 (PHY_BB_DUMMY_AGC_BCAST_1)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_1_LSB                                     0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_1_MSB                                     31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_1_MASK                                    0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_1_GET(x)                                  (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_1_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_1_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_1_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_1_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_1_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_1_RESET                                   0x0
#define PHY_BB_DUMMY_AGC_BCAST_1_ADDRESS                                       (0x4 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_1_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_1_RESET                                         0x0

// 0x8 (PHY_BB_DUMMY_AGC_BCAST_2)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_2_LSB                                     0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_2_MSB                                     31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_2_MASK                                    0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_2_GET(x)                                  (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_2_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_2_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_2_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_2_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_2_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_2_RESET                                   0x0
#define PHY_BB_DUMMY_AGC_BCAST_2_ADDRESS                                       (0x8 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_2_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_2_RESET                                         0x0

// 0xc (PHY_BB_DUMMY_AGC_BCAST_3)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_3_LSB                                     0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_3_MSB                                     31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_3_MASK                                    0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_3_GET(x)                                  (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_3_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_3_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_3_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_3_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_3_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_3_RESET                                   0x0
#define PHY_BB_DUMMY_AGC_BCAST_3_ADDRESS                                       (0xc + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_3_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_3_RESET                                         0x0

// 0x10 (PHY_BB_DUMMY_AGC_BCAST_4)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_4_LSB                                     0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_4_MSB                                     31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_4_MASK                                    0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_4_GET(x)                                  (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_4_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_4_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_4_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_4_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_4_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_4_RESET                                   0x0
#define PHY_BB_DUMMY_AGC_BCAST_4_ADDRESS                                       (0x10 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_4_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_4_RESET                                         0x0

// 0x14 (PHY_BB_DUMMY_AGC_BCAST_5)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_5_LSB                                     0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_5_MSB                                     31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_5_MASK                                    0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_5_GET(x)                                  (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_5_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_5_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_5_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_5_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_5_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_5_RESET                                   0x0
#define PHY_BB_DUMMY_AGC_BCAST_5_ADDRESS                                       (0x14 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_5_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_5_RESET                                         0x0

// 0x18 (PHY_BB_DUMMY_AGC_BCAST_6)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_6_LSB                                     0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_6_MSB                                     31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_6_MASK                                    0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_6_GET(x)                                  (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_6_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_6_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_6_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_6_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_6_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_6_RESET                                   0x0
#define PHY_BB_DUMMY_AGC_BCAST_6_ADDRESS                                       (0x18 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_6_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_6_RESET                                         0x0

// 0x1c (PHY_BB_DUMMY_AGC_BCAST_7)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_7_LSB                                     0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_7_MSB                                     31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_7_MASK                                    0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_7_GET(x)                                  (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_7_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_7_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_7_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_7_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_7_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_7_RESET                                   0x0
#define PHY_BB_DUMMY_AGC_BCAST_7_ADDRESS                                       (0x1c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_7_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_7_RESET                                         0x0

// 0x20 (PHY_BB_DUMMY_AGC_BCAST_8)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_8_LSB                                     0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_8_MSB                                     31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_8_MASK                                    0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_8_GET(x)                                  (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_8_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_8_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_8_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_8_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_8_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_8_RESET                                   0x0
#define PHY_BB_DUMMY_AGC_BCAST_8_ADDRESS                                       (0x20 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_8_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_8_RESET                                         0x0

// 0x24 (PHY_BB_DUMMY_AGC_BCAST_9)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_9_LSB                                     0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_9_MSB                                     31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_9_MASK                                    0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_9_GET(x)                                  (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_9_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_9_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_9_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_9_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_9_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_9_RESET                                   0x0
#define PHY_BB_DUMMY_AGC_BCAST_9_ADDRESS                                       (0x24 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_9_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_9_RESET                                         0x0

// 0x28 (PHY_BB_DUMMY_AGC_BCAST_10)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_10_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_10_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_10_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_10_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_10_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_10_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_10_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_10_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_10_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_10_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_10_ADDRESS                                      (0x28 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_10_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_10_RESET                                        0x0

// 0x2c (PHY_BB_DUMMY_AGC_BCAST_11)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_11_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_11_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_11_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_11_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_11_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_11_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_11_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_11_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_11_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_11_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_11_ADDRESS                                      (0x2c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_11_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_11_RESET                                        0x0

// 0x30 (PHY_BB_DUMMY_AGC_BCAST_12)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_12_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_12_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_12_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_12_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_12_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_12_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_12_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_12_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_12_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_12_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_12_ADDRESS                                      (0x30 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_12_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_12_RESET                                        0x0

// 0x34 (PHY_BB_DUMMY_AGC_BCAST_13)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_13_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_13_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_13_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_13_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_13_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_13_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_13_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_13_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_13_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_13_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_13_ADDRESS                                      (0x34 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_13_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_13_RESET                                        0x0

// 0x38 (PHY_BB_DUMMY_AGC_BCAST_14)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_14_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_14_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_14_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_14_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_14_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_14_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_14_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_14_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_14_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_14_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_14_ADDRESS                                      (0x38 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_14_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_14_RESET                                        0x0

// 0x3c (PHY_BB_DUMMY_AGC_BCAST_15)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_15_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_15_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_15_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_15_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_15_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_15_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_15_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_15_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_15_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_15_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_15_ADDRESS                                      (0x3c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_15_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_15_RESET                                        0x0

// 0x40 (PHY_BB_DUMMY_AGC_BCAST_16)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_16_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_16_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_16_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_16_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_16_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_16_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_16_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_16_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_16_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_16_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_16_ADDRESS                                      (0x40 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_16_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_16_RESET                                        0x0

// 0x44 (PHY_BB_DUMMY_AGC_BCAST_17)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_17_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_17_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_17_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_17_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_17_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_17_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_17_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_17_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_17_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_17_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_17_ADDRESS                                      (0x44 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_17_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_17_RESET                                        0x0

// 0x48 (PHY_BB_DUMMY_AGC_BCAST_18)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_18_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_18_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_18_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_18_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_18_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_18_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_18_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_18_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_18_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_18_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_18_ADDRESS                                      (0x48 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_18_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_18_RESET                                        0x0

// 0x4c (PHY_BB_DUMMY_AGC_BCAST_19)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_19_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_19_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_19_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_19_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_19_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_19_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_19_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_19_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_19_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_19_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_19_ADDRESS                                      (0x4c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_19_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_19_RESET                                        0x0

// 0x50 (PHY_BB_DUMMY_AGC_BCAST_20)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_20_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_20_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_20_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_20_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_20_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_20_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_20_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_20_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_20_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_20_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_20_ADDRESS                                      (0x50 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_20_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_20_RESET                                        0x0

// 0x54 (PHY_BB_DUMMY_AGC_BCAST_21)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_21_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_21_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_21_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_21_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_21_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_21_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_21_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_21_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_21_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_21_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_21_ADDRESS                                      (0x54 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_21_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_21_RESET                                        0x0

// 0x58 (PHY_BB_DUMMY_AGC_BCAST_22)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_22_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_22_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_22_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_22_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_22_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_22_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_22_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_22_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_22_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_22_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_22_ADDRESS                                      (0x58 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_22_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_22_RESET                                        0x0

// 0x5c (PHY_BB_DUMMY_AGC_BCAST_23)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_23_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_23_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_23_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_23_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_23_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_23_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_23_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_23_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_23_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_23_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_23_ADDRESS                                      (0x5c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_23_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_23_RESET                                        0x0

// 0x60 (PHY_BB_DUMMY_AGC_BCAST_24)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_24_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_24_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_24_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_24_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_24_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_24_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_24_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_24_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_24_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_24_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_24_ADDRESS                                      (0x60 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_24_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_24_RESET                                        0x0

// 0x64 (PHY_BB_DUMMY_AGC_BCAST_25)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_25_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_25_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_25_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_25_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_25_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_25_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_25_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_25_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_25_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_25_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_25_ADDRESS                                      (0x64 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_25_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_25_RESET                                        0x0

// 0x68 (PHY_BB_DUMMY_AGC_BCAST_26)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_26_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_26_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_26_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_26_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_26_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_26_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_26_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_26_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_26_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_26_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_26_ADDRESS                                      (0x68 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_26_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_26_RESET                                        0x0

// 0x6c (PHY_BB_DUMMY_AGC_BCAST_27)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_27_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_27_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_27_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_27_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_27_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_27_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_27_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_27_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_27_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_27_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_27_ADDRESS                                      (0x6c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_27_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_27_RESET                                        0x0

// 0x70 (PHY_BB_DUMMY_AGC_BCAST_28)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_28_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_28_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_28_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_28_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_28_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_28_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_28_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_28_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_28_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_28_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_28_ADDRESS                                      (0x70 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_28_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_28_RESET                                        0x0

// 0x74 (PHY_BB_DUMMY_AGC_BCAST_29)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_29_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_29_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_29_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_29_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_29_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_29_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_29_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_29_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_29_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_29_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_29_ADDRESS                                      (0x74 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_29_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_29_RESET                                        0x0

// 0x78 (PHY_BB_DUMMY_AGC_BCAST_30)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_30_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_30_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_30_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_30_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_30_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_30_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_30_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_30_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_30_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_30_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_30_ADDRESS                                      (0x78 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_30_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_30_RESET                                        0x0

// 0x7c (PHY_BB_DUMMY_AGC_BCAST_31)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_31_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_31_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_31_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_31_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_31_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_31_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_31_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_31_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_31_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_31_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_31_ADDRESS                                      (0x7c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_31_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_31_RESET                                        0x0

// 0x80 (PHY_BB_DUMMY_AGC_BCAST_32)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_32_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_32_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_32_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_32_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_32_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_32_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_32_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_32_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_32_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_32_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_32_ADDRESS                                      (0x80 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_32_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_32_RESET                                        0x0

// 0x84 (PHY_BB_DUMMY_AGC_BCAST_33)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_33_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_33_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_33_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_33_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_33_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_33_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_33_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_33_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_33_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_33_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_33_ADDRESS                                      (0x84 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_33_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_33_RESET                                        0x0

// 0x88 (PHY_BB_DUMMY_AGC_BCAST_34)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_34_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_34_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_34_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_34_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_34_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_34_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_34_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_34_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_34_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_34_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_34_ADDRESS                                      (0x88 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_34_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_34_RESET                                        0x0

// 0x8c (PHY_BB_DUMMY_AGC_BCAST_35)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_35_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_35_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_35_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_35_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_35_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_35_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_35_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_35_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_35_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_35_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_35_ADDRESS                                      (0x8c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_35_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_35_RESET                                        0x0

// 0x90 (PHY_BB_DUMMY_AGC_BCAST_36)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_36_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_36_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_36_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_36_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_36_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_36_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_36_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_36_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_36_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_36_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_36_ADDRESS                                      (0x90 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_36_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_36_RESET                                        0x0

// 0x94 (PHY_BB_DUMMY_AGC_BCAST_37)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_37_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_37_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_37_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_37_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_37_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_37_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_37_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_37_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_37_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_37_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_37_ADDRESS                                      (0x94 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_37_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_37_RESET                                        0x0

// 0x98 (PHY_BB_DUMMY_AGC_BCAST_38)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_38_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_38_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_38_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_38_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_38_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_38_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_38_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_38_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_38_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_38_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_38_ADDRESS                                      (0x98 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_38_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_38_RESET                                        0x0

// 0x9c (PHY_BB_DUMMY_AGC_BCAST_39)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_39_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_39_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_39_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_39_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_39_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_39_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_39_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_39_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_39_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_39_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_39_ADDRESS                                      (0x9c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_39_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_39_RESET                                        0x0

// 0xa0 (PHY_BB_DUMMY_AGC_BCAST_40)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_40_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_40_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_40_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_40_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_40_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_40_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_40_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_40_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_40_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_40_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_40_ADDRESS                                      (0xa0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_40_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_40_RESET                                        0x0

// 0xa4 (PHY_BB_DUMMY_AGC_BCAST_41)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_41_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_41_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_41_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_41_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_41_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_41_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_41_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_41_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_41_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_41_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_41_ADDRESS                                      (0xa4 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_41_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_41_RESET                                        0x0

// 0xa8 (PHY_BB_DUMMY_AGC_BCAST_42)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_42_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_42_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_42_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_42_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_42_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_42_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_42_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_42_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_42_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_42_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_42_ADDRESS                                      (0xa8 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_42_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_42_RESET                                        0x0

// 0xac (PHY_BB_DUMMY_AGC_BCAST_43)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_43_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_43_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_43_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_43_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_43_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_43_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_43_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_43_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_43_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_43_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_43_ADDRESS                                      (0xac + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_43_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_43_RESET                                        0x0

// 0xb0 (PHY_BB_DUMMY_AGC_BCAST_44)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_44_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_44_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_44_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_44_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_44_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_44_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_44_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_44_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_44_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_44_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_44_ADDRESS                                      (0xb0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_44_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_44_RESET                                        0x0

// 0xb4 (PHY_BB_DUMMY_AGC_BCAST_45)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_45_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_45_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_45_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_45_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_45_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_45_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_45_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_45_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_45_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_45_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_45_ADDRESS                                      (0xb4 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_45_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_45_RESET                                        0x0

// 0xb8 (PHY_BB_DUMMY_AGC_BCAST_46)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_46_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_46_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_46_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_46_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_46_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_46_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_46_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_46_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_46_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_46_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_46_ADDRESS                                      (0xb8 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_46_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_46_RESET                                        0x0

// 0xbc (PHY_BB_DUMMY_AGC_BCAST_47)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_47_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_47_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_47_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_47_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_47_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_47_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_47_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_47_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_47_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_47_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_47_ADDRESS                                      (0xbc + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_47_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_47_RESET                                        0x0

// 0xc0 (PHY_BB_DUMMY_AGC_BCAST_48)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_48_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_48_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_48_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_48_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_48_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_48_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_48_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_48_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_48_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_48_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_48_ADDRESS                                      (0xc0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_48_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_48_RESET                                        0x0

// 0xc4 (PHY_BB_DUMMY_AGC_BCAST_49)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_49_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_49_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_49_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_49_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_49_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_49_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_49_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_49_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_49_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_49_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_49_ADDRESS                                      (0xc4 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_49_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_49_RESET                                        0x0

// 0xc8 (PHY_BB_DUMMY_AGC_BCAST_50)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_50_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_50_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_50_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_50_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_50_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_50_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_50_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_50_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_50_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_50_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_50_ADDRESS                                      (0xc8 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_50_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_50_RESET                                        0x0

// 0xcc (PHY_BB_DUMMY_AGC_BCAST_51)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_51_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_51_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_51_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_51_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_51_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_51_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_51_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_51_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_51_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_51_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_51_ADDRESS                                      (0xcc + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_51_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_51_RESET                                        0x0

// 0xd0 (PHY_BB_DUMMY_AGC_BCAST_52)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_52_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_52_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_52_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_52_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_52_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_52_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_52_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_52_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_52_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_52_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_52_ADDRESS                                      (0xd0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_52_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_52_RESET                                        0x0

// 0xd4 (PHY_BB_DUMMY_AGC_BCAST_53)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_53_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_53_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_53_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_53_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_53_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_53_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_53_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_53_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_53_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_53_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_53_ADDRESS                                      (0xd4 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_53_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_53_RESET                                        0x0

// 0xd8 (PHY_BB_DUMMY_AGC_BCAST_54)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_54_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_54_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_54_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_54_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_54_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_54_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_54_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_54_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_54_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_54_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_54_ADDRESS                                      (0xd8 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_54_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_54_RESET                                        0x0

// 0xdc (PHY_BB_DUMMY_AGC_BCAST_55)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_55_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_55_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_55_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_55_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_55_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_55_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_55_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_55_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_55_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_55_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_55_ADDRESS                                      (0xdc + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_55_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_55_RESET                                        0x0

// 0xe0 (PHY_BB_DUMMY_AGC_BCAST_56)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_56_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_56_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_56_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_56_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_56_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_56_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_56_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_56_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_56_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_56_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_56_ADDRESS                                      (0xe0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_56_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_56_RESET                                        0x0

// 0xe4 (PHY_BB_DUMMY_AGC_BCAST_57)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_57_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_57_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_57_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_57_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_57_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_57_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_57_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_57_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_57_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_57_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_57_ADDRESS                                      (0xe4 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_57_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_57_RESET                                        0x0

// 0xe8 (PHY_BB_DUMMY_AGC_BCAST_58)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_58_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_58_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_58_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_58_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_58_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_58_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_58_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_58_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_58_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_58_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_58_ADDRESS                                      (0xe8 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_58_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_58_RESET                                        0x0

// 0xec (PHY_BB_DUMMY_AGC_BCAST_59)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_59_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_59_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_59_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_59_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_59_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_59_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_59_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_59_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_59_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_59_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_59_ADDRESS                                      (0xec + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_59_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_59_RESET                                        0x0

// 0xf0 (PHY_BB_DUMMY_AGC_BCAST_60)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_60_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_60_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_60_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_60_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_60_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_60_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_60_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_60_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_60_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_60_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_60_ADDRESS                                      (0xf0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_60_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_60_RESET                                        0x0

// 0xf4 (PHY_BB_DUMMY_AGC_BCAST_61)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_61_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_61_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_61_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_61_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_61_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_61_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_61_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_61_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_61_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_61_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_61_ADDRESS                                      (0xf4 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_61_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_61_RESET                                        0x0

// 0xf8 (PHY_BB_DUMMY_AGC_BCAST_62)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_62_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_62_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_62_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_62_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_62_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_62_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_62_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_62_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_62_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_62_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_62_ADDRESS                                      (0xf8 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_62_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_62_RESET                                        0x0

// 0xfc (PHY_BB_DUMMY_AGC_BCAST_63)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_63_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_63_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_63_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_63_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_63_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_63_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_63_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_63_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_63_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_63_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_63_ADDRESS                                      (0xfc + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_63_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_63_RESET                                        0x0

// 0x100 (PHY_BB_DUMMY_AGC_BCAST_64)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_64_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_64_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_64_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_64_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_64_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_64_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_64_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_64_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_64_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_64_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_64_ADDRESS                                      (0x100 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_64_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_64_RESET                                        0x0

// 0x104 (PHY_BB_DUMMY_AGC_BCAST_65)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_65_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_65_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_65_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_65_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_65_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_65_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_65_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_65_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_65_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_65_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_65_ADDRESS                                      (0x104 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_65_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_65_RESET                                        0x0

// 0x108 (PHY_BB_DUMMY_AGC_BCAST_66)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_66_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_66_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_66_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_66_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_66_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_66_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_66_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_66_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_66_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_66_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_66_ADDRESS                                      (0x108 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_66_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_66_RESET                                        0x0

// 0x10c (PHY_BB_DUMMY_AGC_BCAST_67)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_67_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_67_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_67_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_67_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_67_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_67_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_67_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_67_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_67_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_67_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_67_ADDRESS                                      (0x10c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_67_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_67_RESET                                        0x0

// 0x110 (PHY_BB_DUMMY_AGC_BCAST_68)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_68_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_68_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_68_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_68_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_68_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_68_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_68_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_68_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_68_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_68_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_68_ADDRESS                                      (0x110 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_68_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_68_RESET                                        0x0

// 0x114 (PHY_BB_DUMMY_AGC_BCAST_69)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_69_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_69_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_69_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_69_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_69_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_69_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_69_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_69_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_69_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_69_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_69_ADDRESS                                      (0x114 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_69_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_69_RESET                                        0x0

// 0x118 (PHY_BB_DUMMY_AGC_BCAST_70)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_70_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_70_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_70_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_70_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_70_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_70_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_70_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_70_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_70_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_70_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_70_ADDRESS                                      (0x118 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_70_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_70_RESET                                        0x0

// 0x11c (PHY_BB_DUMMY_AGC_BCAST_71)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_71_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_71_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_71_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_71_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_71_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_71_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_71_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_71_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_71_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_71_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_71_ADDRESS                                      (0x11c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_71_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_71_RESET                                        0x0

// 0x120 (PHY_BB_DUMMY_AGC_BCAST_72)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_72_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_72_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_72_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_72_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_72_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_72_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_72_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_72_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_72_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_72_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_72_ADDRESS                                      (0x120 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_72_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_72_RESET                                        0x0

// 0x124 (PHY_BB_DUMMY_AGC_BCAST_73)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_73_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_73_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_73_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_73_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_73_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_73_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_73_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_73_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_73_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_73_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_73_ADDRESS                                      (0x124 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_73_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_73_RESET                                        0x0

// 0x128 (PHY_BB_DUMMY_AGC_BCAST_74)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_74_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_74_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_74_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_74_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_74_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_74_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_74_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_74_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_74_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_74_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_74_ADDRESS                                      (0x128 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_74_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_74_RESET                                        0x0

// 0x12c (PHY_BB_DUMMY_AGC_BCAST_75)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_75_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_75_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_75_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_75_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_75_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_75_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_75_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_75_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_75_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_75_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_75_ADDRESS                                      (0x12c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_75_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_75_RESET                                        0x0

// 0x130 (PHY_BB_DUMMY_AGC_BCAST_76)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_76_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_76_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_76_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_76_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_76_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_76_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_76_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_76_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_76_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_76_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_76_ADDRESS                                      (0x130 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_76_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_76_RESET                                        0x0

// 0x134 (PHY_BB_DUMMY_AGC_BCAST_77)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_77_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_77_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_77_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_77_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_77_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_77_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_77_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_77_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_77_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_77_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_77_ADDRESS                                      (0x134 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_77_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_77_RESET                                        0x0

// 0x138 (PHY_BB_DUMMY_AGC_BCAST_78)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_78_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_78_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_78_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_78_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_78_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_78_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_78_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_78_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_78_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_78_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_78_ADDRESS                                      (0x138 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_78_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_78_RESET                                        0x0

// 0x13c (PHY_BB_DUMMY_AGC_BCAST_79)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_79_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_79_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_79_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_79_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_79_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_79_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_79_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_79_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_79_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_79_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_79_ADDRESS                                      (0x13c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_79_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_79_RESET                                        0x0

// 0x140 (PHY_BB_DUMMY_AGC_BCAST_80)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_80_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_80_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_80_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_80_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_80_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_80_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_80_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_80_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_80_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_80_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_80_ADDRESS                                      (0x140 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_80_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_80_RESET                                        0x0

// 0x144 (PHY_BB_DUMMY_AGC_BCAST_81)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_81_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_81_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_81_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_81_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_81_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_81_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_81_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_81_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_81_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_81_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_81_ADDRESS                                      (0x144 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_81_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_81_RESET                                        0x0

// 0x148 (PHY_BB_DUMMY_AGC_BCAST_82)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_82_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_82_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_82_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_82_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_82_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_82_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_82_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_82_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_82_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_82_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_82_ADDRESS                                      (0x148 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_82_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_82_RESET                                        0x0

// 0x14c (PHY_BB_DUMMY_AGC_BCAST_83)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_83_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_83_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_83_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_83_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_83_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_83_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_83_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_83_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_83_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_83_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_83_ADDRESS                                      (0x14c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_83_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_83_RESET                                        0x0

// 0x150 (PHY_BB_DUMMY_AGC_BCAST_84)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_84_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_84_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_84_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_84_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_84_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_84_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_84_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_84_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_84_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_84_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_84_ADDRESS                                      (0x150 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_84_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_84_RESET                                        0x0

// 0x154 (PHY_BB_DUMMY_AGC_BCAST_85)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_85_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_85_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_85_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_85_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_85_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_85_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_85_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_85_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_85_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_85_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_85_ADDRESS                                      (0x154 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_85_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_85_RESET                                        0x0

// 0x158 (PHY_BB_DUMMY_AGC_BCAST_86)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_86_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_86_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_86_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_86_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_86_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_86_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_86_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_86_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_86_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_86_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_86_ADDRESS                                      (0x158 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_86_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_86_RESET                                        0x0

// 0x15c (PHY_BB_DUMMY_AGC_BCAST_87)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_87_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_87_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_87_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_87_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_87_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_87_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_87_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_87_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_87_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_87_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_87_ADDRESS                                      (0x15c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_87_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_87_RESET                                        0x0

// 0x160 (PHY_BB_DUMMY_AGC_BCAST_88)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_88_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_88_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_88_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_88_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_88_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_88_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_88_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_88_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_88_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_88_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_88_ADDRESS                                      (0x160 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_88_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_88_RESET                                        0x0

// 0x164 (PHY_BB_DUMMY_AGC_BCAST_89)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_89_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_89_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_89_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_89_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_89_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_89_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_89_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_89_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_89_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_89_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_89_ADDRESS                                      (0x164 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_89_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_89_RESET                                        0x0

// 0x168 (PHY_BB_DUMMY_AGC_BCAST_90)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_90_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_90_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_90_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_90_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_90_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_90_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_90_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_90_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_90_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_90_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_90_ADDRESS                                      (0x168 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_90_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_90_RESET                                        0x0

// 0x16c (PHY_BB_DUMMY_AGC_BCAST_91)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_91_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_91_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_91_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_91_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_91_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_91_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_91_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_91_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_91_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_91_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_91_ADDRESS                                      (0x16c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_91_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_91_RESET                                        0x0

// 0x170 (PHY_BB_DUMMY_AGC_BCAST_92)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_92_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_92_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_92_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_92_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_92_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_92_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_92_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_92_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_92_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_92_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_92_ADDRESS                                      (0x170 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_92_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_92_RESET                                        0x0

// 0x174 (PHY_BB_DUMMY_AGC_BCAST_93)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_93_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_93_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_93_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_93_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_93_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_93_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_93_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_93_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_93_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_93_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_93_ADDRESS                                      (0x174 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_93_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_93_RESET                                        0x0

// 0x178 (PHY_BB_DUMMY_AGC_BCAST_94)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_94_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_94_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_94_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_94_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_94_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_94_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_94_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_94_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_94_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_94_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_94_ADDRESS                                      (0x178 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_94_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_94_RESET                                        0x0

// 0x17c (PHY_BB_DUMMY_AGC_BCAST_95)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_95_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_95_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_95_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_95_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_95_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_95_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_95_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_95_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_95_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_95_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_95_ADDRESS                                      (0x17c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_95_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_95_RESET                                        0x0

// 0x180 (PHY_BB_DUMMY_AGC_BCAST_96)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_96_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_96_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_96_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_96_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_96_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_96_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_96_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_96_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_96_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_96_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_96_ADDRESS                                      (0x180 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_96_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_96_RESET                                        0x0

// 0x184 (PHY_BB_DUMMY_AGC_BCAST_97)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_97_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_97_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_97_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_97_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_97_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_97_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_97_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_97_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_97_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_97_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_97_ADDRESS                                      (0x184 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_97_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_97_RESET                                        0x0

// 0x188 (PHY_BB_DUMMY_AGC_BCAST_98)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_98_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_98_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_98_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_98_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_98_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_98_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_98_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_98_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_98_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_98_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_98_ADDRESS                                      (0x188 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_98_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_98_RESET                                        0x0

// 0x18c (PHY_BB_DUMMY_AGC_BCAST_99)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_99_LSB                                    0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_99_MSB                                    31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_99_MASK                                   0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_99_GET(x)                                 (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_99_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_99_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_99_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_99_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_99_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_99_RESET                                  0x0
#define PHY_BB_DUMMY_AGC_BCAST_99_ADDRESS                                      (0x18c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_99_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_99_RESET                                        0x0

// 0x190 (PHY_BB_DUMMY_AGC_BCAST_100)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_100_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_100_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_100_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_100_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_100_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_100_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_100_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_100_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_100_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_100_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_100_ADDRESS                                     (0x190 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_100_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_100_RESET                                       0x0

// 0x194 (PHY_BB_DUMMY_AGC_BCAST_101)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_101_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_101_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_101_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_101_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_101_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_101_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_101_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_101_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_101_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_101_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_101_ADDRESS                                     (0x194 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_101_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_101_RESET                                       0x0

// 0x198 (PHY_BB_DUMMY_AGC_BCAST_102)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_102_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_102_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_102_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_102_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_102_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_102_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_102_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_102_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_102_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_102_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_102_ADDRESS                                     (0x198 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_102_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_102_RESET                                       0x0

// 0x19c (PHY_BB_DUMMY_AGC_BCAST_103)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_103_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_103_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_103_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_103_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_103_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_103_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_103_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_103_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_103_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_103_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_103_ADDRESS                                     (0x19c + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_103_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_103_RESET                                       0x0

// 0x1a0 (PHY_BB_DUMMY_AGC_BCAST_104)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_104_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_104_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_104_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_104_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_104_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_104_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_104_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_104_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_104_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_104_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_104_ADDRESS                                     (0x1a0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_104_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_104_RESET                                       0x0

// 0x1a4 (PHY_BB_DUMMY_AGC_BCAST_105)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_105_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_105_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_105_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_105_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_105_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_105_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_105_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_105_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_105_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_105_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_105_ADDRESS                                     (0x1a4 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_105_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_105_RESET                                       0x0

// 0x1a8 (PHY_BB_DUMMY_AGC_BCAST_106)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_106_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_106_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_106_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_106_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_106_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_106_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_106_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_106_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_106_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_106_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_106_ADDRESS                                     (0x1a8 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_106_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_106_RESET                                       0x0

// 0x1ac (PHY_BB_DUMMY_AGC_BCAST_107)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_107_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_107_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_107_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_107_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_107_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_107_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_107_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_107_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_107_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_107_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_107_ADDRESS                                     (0x1ac + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_107_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_107_RESET                                       0x0

// 0x1b0 (PHY_BB_DUMMY_AGC_BCAST_108)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_108_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_108_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_108_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_108_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_108_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_108_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_108_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_108_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_108_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_108_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_108_ADDRESS                                     (0x1b0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_108_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_108_RESET                                       0x0

// 0x1b4 (PHY_BB_DUMMY_AGC_BCAST_109)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_109_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_109_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_109_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_109_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_109_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_109_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_109_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_109_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_109_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_109_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_109_ADDRESS                                     (0x1b4 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_109_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_109_RESET                                       0x0

// 0x1b8 (PHY_BB_DUMMY_AGC_BCAST_110)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_110_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_110_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_110_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_110_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_110_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_110_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_110_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_110_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_110_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_110_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_110_ADDRESS                                     (0x1b8 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_110_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_110_RESET                                       0x0

// 0x1bc (PHY_BB_DUMMY_AGC_BCAST_111)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_111_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_111_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_111_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_111_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_111_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_111_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_111_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_111_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_111_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_111_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_111_ADDRESS                                     (0x1bc + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_111_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_111_RESET                                       0x0

// 0x1c0 (PHY_BB_DUMMY_AGC_BCAST_112)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_112_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_112_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_112_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_112_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_112_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_112_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_112_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_112_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_112_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_112_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_112_ADDRESS                                     (0x1c0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_112_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_112_RESET                                       0x0

// 0x1c4 (PHY_BB_DUMMY_AGC_BCAST_113)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_113_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_113_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_113_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_113_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_113_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_113_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_113_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_113_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_113_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_113_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_113_ADDRESS                                     (0x1c4 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_113_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_113_RESET                                       0x0

// 0x1c8 (PHY_BB_DUMMY_AGC_BCAST_114)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_114_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_114_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_114_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_114_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_114_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_114_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_114_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_114_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_114_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_114_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_114_ADDRESS                                     (0x1c8 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_114_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_114_RESET                                       0x0

// 0x1cc (PHY_BB_DUMMY_AGC_BCAST_115)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_115_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_115_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_115_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_115_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_115_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_115_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_115_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_115_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_115_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_115_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_115_ADDRESS                                     (0x1cc + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_115_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_115_RESET                                       0x0

// 0x1d0 (PHY_BB_DUMMY_AGC_BCAST_116)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_116_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_116_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_116_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_116_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_116_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_116_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_116_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_116_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_116_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_116_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_116_ADDRESS                                     (0x1d0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_116_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_116_RESET                                       0x0

// 0x1d4 (PHY_BB_DUMMY_AGC_BCAST_117)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_117_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_117_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_117_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_117_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_117_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_117_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_117_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_117_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_117_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_117_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_117_ADDRESS                                     (0x1d4 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_117_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_117_RESET                                       0x0

// 0x1d8 (PHY_BB_DUMMY_AGC_BCAST_118)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_118_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_118_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_118_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_118_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_118_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_118_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_118_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_118_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_118_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_118_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_118_ADDRESS                                     (0x1d8 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_118_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_118_RESET                                       0x0

// 0x1dc (PHY_BB_DUMMY_AGC_BCAST_119)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_119_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_119_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_119_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_119_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_119_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_119_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_119_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_119_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_119_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_119_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_119_ADDRESS                                     (0x1dc + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_119_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_119_RESET                                       0x0

// 0x1e0 (PHY_BB_DUMMY_AGC_BCAST_120)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_120_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_120_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_120_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_120_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_120_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_120_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_120_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_120_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_120_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_120_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_120_ADDRESS                                     (0x1e0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_120_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_120_RESET                                       0x0

// 0x1e4 (PHY_BB_DUMMY_AGC_BCAST_121)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_121_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_121_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_121_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_121_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_121_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_121_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_121_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_121_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_121_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_121_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_121_ADDRESS                                     (0x1e4 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_121_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_121_RESET                                       0x0

// 0x1e8 (PHY_BB_DUMMY_AGC_BCAST_122)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_122_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_122_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_122_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_122_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_122_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_122_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_122_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_122_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_122_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_122_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_122_ADDRESS                                     (0x1e8 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_122_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_122_RESET                                       0x0

// 0x1ec (PHY_BB_DUMMY_AGC_BCAST_123)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_123_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_123_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_123_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_123_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_123_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_123_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_123_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_123_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_123_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_123_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_123_ADDRESS                                     (0x1ec + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_123_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_123_RESET                                       0x0

// 0x1f0 (PHY_BB_DUMMY_AGC_BCAST_124)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_124_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_124_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_124_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_124_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_124_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_124_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_124_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_124_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_124_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_124_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_124_ADDRESS                                     (0x1f0 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_124_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_124_RESET                                       0x0

// 0x1f4 (PHY_BB_DUMMY_AGC_BCAST_125)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_125_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_125_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_125_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_125_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_125_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_125_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_125_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_125_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_125_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_125_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_125_ADDRESS                                     (0x1f4 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_125_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_125_RESET                                       0x0

// 0x1f8 (PHY_BB_DUMMY_AGC_BCAST_126)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_126_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_126_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_126_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_126_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_126_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_126_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_126_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_126_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_126_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_126_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_126_ADDRESS                                     (0x1f8 + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_126_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_126_RESET                                       0x0

// 0x1fc (PHY_BB_DUMMY_AGC_BCAST_127)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_127_LSB                                   0
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_127_MSB                                   31
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_127_MASK                                  0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_127_GET(x)                                (((x) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_127_MASK) >> PHY_BB_DUMMY_AGC_BCAST_DUMMY_127_LSB)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_127_SET(x)                                (((0 | (x)) << PHY_BB_DUMMY_AGC_BCAST_DUMMY_127_LSB) & PHY_BB_DUMMY_AGC_BCAST_DUMMY_127_MASK)
#define PHY_BB_DUMMY_AGC_BCAST_DUMMY_127_RESET                                 0x0
#define PHY_BB_DUMMY_AGC_BCAST_127_ADDRESS                                     (0x1fc + __PHY_AGC4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_AGC_BCAST_127_RSTMASK                                     0xffffffff
#define PHY_BB_DUMMY_AGC_BCAST_127_RESET                                       0x0



#endif /* _PHY_AGC4_REG_MAP_H_ */
