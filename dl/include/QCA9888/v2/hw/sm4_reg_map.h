/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _PHY_SM4_REG_MAP_H_
#define _PHY_SM4_REG_MAP_H_


#ifndef __PHY_SM4_REG_MAP_BASE_ADDRESS
#define __PHY_SM4_REG_MAP_BASE_ADDRESS (0x14600)
#endif


// 0x0 (PHY_BB_DUMMY_SM_BCAST)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_LSB                                        0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_MSB                                        31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_MASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_GET(x)                                     (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_SET(x)                                     (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_RESET                                      0x0
#define PHY_BB_DUMMY_SM_BCAST_ADDRESS                                          (0x0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_RSTMASK                                          0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_RESET                                            0x0

// 0x0 (PHY_BB_DUMMY_SM_BCAST_0)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_0_LSB                                      0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_0_MSB                                      31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_0_MASK                                     0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_0_GET(x)                                   (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_0_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_0_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_0_SET(x)                                   (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_0_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_0_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_0_RESET                                    0x0
#define PHY_BB_DUMMY_SM_BCAST_0_ADDRESS                                        (0x0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_0_RSTMASK                                        0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_0_RESET                                          0x0

// 0x4 (PHY_BB_DUMMY_SM_BCAST_1)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_1_LSB                                      0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_1_MSB                                      31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_1_MASK                                     0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_1_GET(x)                                   (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_1_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_1_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_1_SET(x)                                   (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_1_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_1_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_1_RESET                                    0x0
#define PHY_BB_DUMMY_SM_BCAST_1_ADDRESS                                        (0x4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_1_RSTMASK                                        0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_1_RESET                                          0x0

// 0x8 (PHY_BB_DUMMY_SM_BCAST_2)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_2_LSB                                      0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_2_MSB                                      31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_2_MASK                                     0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_2_GET(x)                                   (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_2_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_2_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_2_SET(x)                                   (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_2_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_2_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_2_RESET                                    0x0
#define PHY_BB_DUMMY_SM_BCAST_2_ADDRESS                                        (0x8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_2_RSTMASK                                        0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_2_RESET                                          0x0

// 0xc (PHY_BB_DUMMY_SM_BCAST_3)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_3_LSB                                      0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_3_MSB                                      31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_3_MASK                                     0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_3_GET(x)                                   (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_3_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_3_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_3_SET(x)                                   (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_3_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_3_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_3_RESET                                    0x0
#define PHY_BB_DUMMY_SM_BCAST_3_ADDRESS                                        (0xc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_3_RSTMASK                                        0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_3_RESET                                          0x0

// 0x10 (PHY_BB_DUMMY_SM_BCAST_4)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_4_LSB                                      0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_4_MSB                                      31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_4_MASK                                     0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_4_GET(x)                                   (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_4_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_4_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_4_SET(x)                                   (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_4_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_4_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_4_RESET                                    0x0
#define PHY_BB_DUMMY_SM_BCAST_4_ADDRESS                                        (0x10 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_4_RSTMASK                                        0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_4_RESET                                          0x0

// 0x14 (PHY_BB_DUMMY_SM_BCAST_5)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_5_LSB                                      0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_5_MSB                                      31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_5_MASK                                     0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_5_GET(x)                                   (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_5_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_5_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_5_SET(x)                                   (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_5_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_5_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_5_RESET                                    0x0
#define PHY_BB_DUMMY_SM_BCAST_5_ADDRESS                                        (0x14 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_5_RSTMASK                                        0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_5_RESET                                          0x0

// 0x18 (PHY_BB_DUMMY_SM_BCAST_6)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_6_LSB                                      0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_6_MSB                                      31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_6_MASK                                     0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_6_GET(x)                                   (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_6_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_6_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_6_SET(x)                                   (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_6_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_6_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_6_RESET                                    0x0
#define PHY_BB_DUMMY_SM_BCAST_6_ADDRESS                                        (0x18 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_6_RSTMASK                                        0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_6_RESET                                          0x0

// 0x1c (PHY_BB_DUMMY_SM_BCAST_7)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_7_LSB                                      0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_7_MSB                                      31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_7_MASK                                     0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_7_GET(x)                                   (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_7_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_7_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_7_SET(x)                                   (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_7_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_7_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_7_RESET                                    0x0
#define PHY_BB_DUMMY_SM_BCAST_7_ADDRESS                                        (0x1c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_7_RSTMASK                                        0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_7_RESET                                          0x0

// 0x20 (PHY_BB_DUMMY_SM_BCAST_8)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_8_LSB                                      0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_8_MSB                                      31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_8_MASK                                     0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_8_GET(x)                                   (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_8_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_8_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_8_SET(x)                                   (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_8_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_8_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_8_RESET                                    0x0
#define PHY_BB_DUMMY_SM_BCAST_8_ADDRESS                                        (0x20 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_8_RSTMASK                                        0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_8_RESET                                          0x0

// 0x24 (PHY_BB_DUMMY_SM_BCAST_9)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_9_LSB                                      0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_9_MSB                                      31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_9_MASK                                     0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_9_GET(x)                                   (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_9_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_9_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_9_SET(x)                                   (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_9_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_9_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_9_RESET                                    0x0
#define PHY_BB_DUMMY_SM_BCAST_9_ADDRESS                                        (0x24 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_9_RSTMASK                                        0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_9_RESET                                          0x0

// 0x28 (PHY_BB_DUMMY_SM_BCAST_10)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_10_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_10_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_10_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_10_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_10_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_10_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_10_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_10_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_10_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_10_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_10_ADDRESS                                       (0x28 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_10_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_10_RESET                                         0x0

// 0x2c (PHY_BB_DUMMY_SM_BCAST_11)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_11_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_11_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_11_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_11_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_11_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_11_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_11_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_11_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_11_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_11_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_11_ADDRESS                                       (0x2c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_11_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_11_RESET                                         0x0

// 0x30 (PHY_BB_DUMMY_SM_BCAST_12)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_12_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_12_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_12_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_12_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_12_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_12_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_12_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_12_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_12_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_12_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_12_ADDRESS                                       (0x30 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_12_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_12_RESET                                         0x0

// 0x34 (PHY_BB_DUMMY_SM_BCAST_13)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_13_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_13_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_13_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_13_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_13_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_13_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_13_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_13_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_13_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_13_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_13_ADDRESS                                       (0x34 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_13_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_13_RESET                                         0x0

// 0x38 (PHY_BB_DUMMY_SM_BCAST_14)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_14_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_14_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_14_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_14_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_14_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_14_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_14_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_14_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_14_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_14_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_14_ADDRESS                                       (0x38 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_14_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_14_RESET                                         0x0

// 0x3c (PHY_BB_DUMMY_SM_BCAST_15)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_15_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_15_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_15_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_15_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_15_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_15_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_15_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_15_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_15_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_15_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_15_ADDRESS                                       (0x3c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_15_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_15_RESET                                         0x0

// 0x40 (PHY_BB_DUMMY_SM_BCAST_16)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_16_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_16_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_16_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_16_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_16_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_16_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_16_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_16_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_16_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_16_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_16_ADDRESS                                       (0x40 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_16_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_16_RESET                                         0x0

// 0x44 (PHY_BB_DUMMY_SM_BCAST_17)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_17_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_17_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_17_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_17_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_17_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_17_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_17_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_17_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_17_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_17_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_17_ADDRESS                                       (0x44 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_17_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_17_RESET                                         0x0

// 0x48 (PHY_BB_DUMMY_SM_BCAST_18)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_18_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_18_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_18_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_18_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_18_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_18_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_18_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_18_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_18_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_18_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_18_ADDRESS                                       (0x48 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_18_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_18_RESET                                         0x0

// 0x4c (PHY_BB_DUMMY_SM_BCAST_19)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_19_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_19_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_19_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_19_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_19_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_19_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_19_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_19_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_19_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_19_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_19_ADDRESS                                       (0x4c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_19_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_19_RESET                                         0x0

// 0x50 (PHY_BB_DUMMY_SM_BCAST_20)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_20_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_20_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_20_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_20_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_20_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_20_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_20_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_20_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_20_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_20_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_20_ADDRESS                                       (0x50 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_20_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_20_RESET                                         0x0

// 0x54 (PHY_BB_DUMMY_SM_BCAST_21)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_21_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_21_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_21_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_21_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_21_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_21_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_21_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_21_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_21_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_21_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_21_ADDRESS                                       (0x54 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_21_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_21_RESET                                         0x0

// 0x58 (PHY_BB_DUMMY_SM_BCAST_22)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_22_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_22_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_22_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_22_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_22_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_22_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_22_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_22_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_22_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_22_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_22_ADDRESS                                       (0x58 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_22_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_22_RESET                                         0x0

// 0x5c (PHY_BB_DUMMY_SM_BCAST_23)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_23_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_23_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_23_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_23_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_23_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_23_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_23_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_23_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_23_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_23_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_23_ADDRESS                                       (0x5c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_23_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_23_RESET                                         0x0

// 0x60 (PHY_BB_DUMMY_SM_BCAST_24)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_24_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_24_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_24_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_24_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_24_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_24_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_24_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_24_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_24_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_24_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_24_ADDRESS                                       (0x60 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_24_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_24_RESET                                         0x0

// 0x64 (PHY_BB_DUMMY_SM_BCAST_25)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_25_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_25_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_25_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_25_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_25_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_25_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_25_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_25_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_25_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_25_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_25_ADDRESS                                       (0x64 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_25_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_25_RESET                                         0x0

// 0x68 (PHY_BB_DUMMY_SM_BCAST_26)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_26_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_26_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_26_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_26_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_26_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_26_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_26_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_26_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_26_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_26_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_26_ADDRESS                                       (0x68 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_26_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_26_RESET                                         0x0

// 0x6c (PHY_BB_DUMMY_SM_BCAST_27)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_27_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_27_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_27_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_27_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_27_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_27_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_27_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_27_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_27_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_27_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_27_ADDRESS                                       (0x6c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_27_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_27_RESET                                         0x0

// 0x70 (PHY_BB_DUMMY_SM_BCAST_28)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_28_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_28_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_28_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_28_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_28_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_28_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_28_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_28_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_28_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_28_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_28_ADDRESS                                       (0x70 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_28_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_28_RESET                                         0x0

// 0x74 (PHY_BB_DUMMY_SM_BCAST_29)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_29_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_29_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_29_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_29_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_29_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_29_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_29_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_29_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_29_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_29_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_29_ADDRESS                                       (0x74 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_29_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_29_RESET                                         0x0

// 0x78 (PHY_BB_DUMMY_SM_BCAST_30)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_30_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_30_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_30_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_30_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_30_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_30_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_30_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_30_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_30_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_30_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_30_ADDRESS                                       (0x78 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_30_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_30_RESET                                         0x0

// 0x7c (PHY_BB_DUMMY_SM_BCAST_31)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_31_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_31_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_31_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_31_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_31_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_31_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_31_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_31_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_31_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_31_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_31_ADDRESS                                       (0x7c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_31_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_31_RESET                                         0x0

// 0x80 (PHY_BB_DUMMY_SM_BCAST_32)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_32_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_32_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_32_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_32_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_32_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_32_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_32_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_32_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_32_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_32_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_32_ADDRESS                                       (0x80 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_32_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_32_RESET                                         0x0

// 0x84 (PHY_BB_DUMMY_SM_BCAST_33)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_33_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_33_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_33_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_33_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_33_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_33_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_33_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_33_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_33_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_33_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_33_ADDRESS                                       (0x84 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_33_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_33_RESET                                         0x0

// 0x88 (PHY_BB_DUMMY_SM_BCAST_34)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_34_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_34_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_34_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_34_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_34_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_34_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_34_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_34_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_34_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_34_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_34_ADDRESS                                       (0x88 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_34_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_34_RESET                                         0x0

// 0x8c (PHY_BB_DUMMY_SM_BCAST_35)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_35_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_35_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_35_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_35_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_35_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_35_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_35_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_35_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_35_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_35_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_35_ADDRESS                                       (0x8c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_35_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_35_RESET                                         0x0

// 0x90 (PHY_BB_DUMMY_SM_BCAST_36)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_36_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_36_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_36_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_36_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_36_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_36_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_36_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_36_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_36_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_36_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_36_ADDRESS                                       (0x90 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_36_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_36_RESET                                         0x0

// 0x94 (PHY_BB_DUMMY_SM_BCAST_37)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_37_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_37_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_37_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_37_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_37_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_37_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_37_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_37_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_37_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_37_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_37_ADDRESS                                       (0x94 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_37_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_37_RESET                                         0x0

// 0x98 (PHY_BB_DUMMY_SM_BCAST_38)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_38_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_38_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_38_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_38_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_38_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_38_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_38_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_38_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_38_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_38_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_38_ADDRESS                                       (0x98 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_38_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_38_RESET                                         0x0

// 0x9c (PHY_BB_DUMMY_SM_BCAST_39)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_39_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_39_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_39_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_39_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_39_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_39_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_39_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_39_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_39_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_39_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_39_ADDRESS                                       (0x9c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_39_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_39_RESET                                         0x0

// 0xa0 (PHY_BB_DUMMY_SM_BCAST_40)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_40_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_40_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_40_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_40_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_40_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_40_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_40_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_40_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_40_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_40_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_40_ADDRESS                                       (0xa0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_40_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_40_RESET                                         0x0

// 0xa4 (PHY_BB_DUMMY_SM_BCAST_41)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_41_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_41_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_41_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_41_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_41_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_41_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_41_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_41_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_41_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_41_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_41_ADDRESS                                       (0xa4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_41_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_41_RESET                                         0x0

// 0xa8 (PHY_BB_DUMMY_SM_BCAST_42)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_42_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_42_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_42_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_42_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_42_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_42_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_42_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_42_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_42_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_42_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_42_ADDRESS                                       (0xa8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_42_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_42_RESET                                         0x0

// 0xac (PHY_BB_DUMMY_SM_BCAST_43)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_43_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_43_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_43_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_43_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_43_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_43_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_43_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_43_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_43_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_43_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_43_ADDRESS                                       (0xac + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_43_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_43_RESET                                         0x0

// 0xb0 (PHY_BB_DUMMY_SM_BCAST_44)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_44_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_44_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_44_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_44_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_44_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_44_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_44_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_44_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_44_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_44_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_44_ADDRESS                                       (0xb0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_44_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_44_RESET                                         0x0

// 0xb4 (PHY_BB_DUMMY_SM_BCAST_45)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_45_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_45_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_45_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_45_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_45_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_45_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_45_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_45_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_45_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_45_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_45_ADDRESS                                       (0xb4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_45_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_45_RESET                                         0x0

// 0xb8 (PHY_BB_DUMMY_SM_BCAST_46)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_46_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_46_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_46_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_46_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_46_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_46_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_46_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_46_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_46_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_46_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_46_ADDRESS                                       (0xb8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_46_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_46_RESET                                         0x0

// 0xbc (PHY_BB_DUMMY_SM_BCAST_47)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_47_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_47_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_47_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_47_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_47_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_47_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_47_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_47_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_47_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_47_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_47_ADDRESS                                       (0xbc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_47_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_47_RESET                                         0x0

// 0xc0 (PHY_BB_DUMMY_SM_BCAST_48)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_48_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_48_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_48_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_48_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_48_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_48_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_48_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_48_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_48_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_48_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_48_ADDRESS                                       (0xc0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_48_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_48_RESET                                         0x0

// 0xc4 (PHY_BB_DUMMY_SM_BCAST_49)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_49_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_49_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_49_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_49_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_49_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_49_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_49_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_49_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_49_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_49_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_49_ADDRESS                                       (0xc4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_49_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_49_RESET                                         0x0

// 0xc8 (PHY_BB_DUMMY_SM_BCAST_50)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_50_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_50_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_50_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_50_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_50_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_50_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_50_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_50_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_50_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_50_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_50_ADDRESS                                       (0xc8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_50_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_50_RESET                                         0x0

// 0xcc (PHY_BB_DUMMY_SM_BCAST_51)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_51_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_51_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_51_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_51_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_51_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_51_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_51_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_51_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_51_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_51_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_51_ADDRESS                                       (0xcc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_51_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_51_RESET                                         0x0

// 0xd0 (PHY_BB_DUMMY_SM_BCAST_52)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_52_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_52_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_52_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_52_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_52_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_52_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_52_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_52_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_52_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_52_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_52_ADDRESS                                       (0xd0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_52_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_52_RESET                                         0x0

// 0xd4 (PHY_BB_DUMMY_SM_BCAST_53)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_53_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_53_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_53_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_53_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_53_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_53_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_53_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_53_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_53_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_53_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_53_ADDRESS                                       (0xd4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_53_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_53_RESET                                         0x0

// 0xd8 (PHY_BB_DUMMY_SM_BCAST_54)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_54_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_54_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_54_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_54_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_54_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_54_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_54_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_54_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_54_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_54_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_54_ADDRESS                                       (0xd8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_54_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_54_RESET                                         0x0

// 0xdc (PHY_BB_DUMMY_SM_BCAST_55)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_55_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_55_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_55_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_55_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_55_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_55_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_55_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_55_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_55_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_55_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_55_ADDRESS                                       (0xdc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_55_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_55_RESET                                         0x0

// 0xe0 (PHY_BB_DUMMY_SM_BCAST_56)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_56_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_56_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_56_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_56_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_56_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_56_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_56_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_56_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_56_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_56_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_56_ADDRESS                                       (0xe0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_56_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_56_RESET                                         0x0

// 0xe4 (PHY_BB_DUMMY_SM_BCAST_57)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_57_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_57_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_57_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_57_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_57_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_57_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_57_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_57_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_57_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_57_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_57_ADDRESS                                       (0xe4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_57_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_57_RESET                                         0x0

// 0xe8 (PHY_BB_DUMMY_SM_BCAST_58)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_58_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_58_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_58_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_58_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_58_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_58_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_58_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_58_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_58_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_58_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_58_ADDRESS                                       (0xe8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_58_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_58_RESET                                         0x0

// 0xec (PHY_BB_DUMMY_SM_BCAST_59)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_59_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_59_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_59_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_59_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_59_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_59_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_59_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_59_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_59_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_59_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_59_ADDRESS                                       (0xec + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_59_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_59_RESET                                         0x0

// 0xf0 (PHY_BB_DUMMY_SM_BCAST_60)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_60_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_60_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_60_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_60_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_60_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_60_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_60_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_60_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_60_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_60_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_60_ADDRESS                                       (0xf0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_60_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_60_RESET                                         0x0

// 0xf4 (PHY_BB_DUMMY_SM_BCAST_61)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_61_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_61_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_61_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_61_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_61_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_61_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_61_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_61_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_61_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_61_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_61_ADDRESS                                       (0xf4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_61_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_61_RESET                                         0x0

// 0xf8 (PHY_BB_DUMMY_SM_BCAST_62)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_62_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_62_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_62_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_62_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_62_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_62_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_62_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_62_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_62_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_62_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_62_ADDRESS                                       (0xf8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_62_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_62_RESET                                         0x0

// 0xfc (PHY_BB_DUMMY_SM_BCAST_63)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_63_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_63_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_63_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_63_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_63_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_63_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_63_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_63_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_63_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_63_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_63_ADDRESS                                       (0xfc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_63_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_63_RESET                                         0x0

// 0x100 (PHY_BB_DUMMY_SM_BCAST_64)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_64_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_64_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_64_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_64_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_64_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_64_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_64_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_64_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_64_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_64_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_64_ADDRESS                                       (0x100 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_64_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_64_RESET                                         0x0

// 0x104 (PHY_BB_DUMMY_SM_BCAST_65)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_65_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_65_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_65_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_65_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_65_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_65_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_65_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_65_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_65_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_65_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_65_ADDRESS                                       (0x104 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_65_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_65_RESET                                         0x0

// 0x108 (PHY_BB_DUMMY_SM_BCAST_66)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_66_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_66_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_66_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_66_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_66_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_66_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_66_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_66_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_66_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_66_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_66_ADDRESS                                       (0x108 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_66_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_66_RESET                                         0x0

// 0x10c (PHY_BB_DUMMY_SM_BCAST_67)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_67_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_67_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_67_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_67_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_67_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_67_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_67_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_67_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_67_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_67_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_67_ADDRESS                                       (0x10c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_67_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_67_RESET                                         0x0

// 0x110 (PHY_BB_DUMMY_SM_BCAST_68)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_68_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_68_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_68_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_68_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_68_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_68_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_68_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_68_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_68_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_68_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_68_ADDRESS                                       (0x110 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_68_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_68_RESET                                         0x0

// 0x114 (PHY_BB_DUMMY_SM_BCAST_69)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_69_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_69_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_69_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_69_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_69_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_69_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_69_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_69_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_69_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_69_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_69_ADDRESS                                       (0x114 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_69_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_69_RESET                                         0x0

// 0x118 (PHY_BB_DUMMY_SM_BCAST_70)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_70_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_70_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_70_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_70_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_70_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_70_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_70_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_70_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_70_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_70_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_70_ADDRESS                                       (0x118 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_70_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_70_RESET                                         0x0

// 0x11c (PHY_BB_DUMMY_SM_BCAST_71)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_71_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_71_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_71_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_71_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_71_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_71_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_71_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_71_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_71_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_71_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_71_ADDRESS                                       (0x11c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_71_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_71_RESET                                         0x0

// 0x120 (PHY_BB_DUMMY_SM_BCAST_72)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_72_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_72_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_72_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_72_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_72_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_72_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_72_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_72_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_72_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_72_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_72_ADDRESS                                       (0x120 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_72_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_72_RESET                                         0x0

// 0x124 (PHY_BB_DUMMY_SM_BCAST_73)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_73_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_73_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_73_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_73_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_73_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_73_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_73_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_73_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_73_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_73_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_73_ADDRESS                                       (0x124 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_73_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_73_RESET                                         0x0

// 0x128 (PHY_BB_DUMMY_SM_BCAST_74)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_74_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_74_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_74_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_74_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_74_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_74_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_74_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_74_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_74_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_74_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_74_ADDRESS                                       (0x128 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_74_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_74_RESET                                         0x0

// 0x12c (PHY_BB_DUMMY_SM_BCAST_75)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_75_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_75_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_75_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_75_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_75_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_75_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_75_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_75_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_75_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_75_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_75_ADDRESS                                       (0x12c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_75_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_75_RESET                                         0x0

// 0x130 (PHY_BB_DUMMY_SM_BCAST_76)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_76_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_76_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_76_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_76_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_76_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_76_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_76_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_76_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_76_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_76_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_76_ADDRESS                                       (0x130 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_76_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_76_RESET                                         0x0

// 0x134 (PHY_BB_DUMMY_SM_BCAST_77)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_77_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_77_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_77_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_77_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_77_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_77_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_77_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_77_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_77_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_77_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_77_ADDRESS                                       (0x134 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_77_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_77_RESET                                         0x0

// 0x138 (PHY_BB_DUMMY_SM_BCAST_78)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_78_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_78_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_78_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_78_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_78_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_78_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_78_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_78_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_78_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_78_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_78_ADDRESS                                       (0x138 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_78_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_78_RESET                                         0x0

// 0x13c (PHY_BB_DUMMY_SM_BCAST_79)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_79_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_79_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_79_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_79_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_79_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_79_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_79_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_79_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_79_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_79_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_79_ADDRESS                                       (0x13c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_79_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_79_RESET                                         0x0

// 0x140 (PHY_BB_DUMMY_SM_BCAST_80)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_80_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_80_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_80_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_80_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_80_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_80_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_80_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_80_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_80_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_80_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_80_ADDRESS                                       (0x140 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_80_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_80_RESET                                         0x0

// 0x144 (PHY_BB_DUMMY_SM_BCAST_81)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_81_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_81_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_81_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_81_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_81_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_81_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_81_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_81_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_81_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_81_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_81_ADDRESS                                       (0x144 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_81_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_81_RESET                                         0x0

// 0x148 (PHY_BB_DUMMY_SM_BCAST_82)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_82_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_82_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_82_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_82_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_82_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_82_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_82_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_82_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_82_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_82_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_82_ADDRESS                                       (0x148 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_82_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_82_RESET                                         0x0

// 0x14c (PHY_BB_DUMMY_SM_BCAST_83)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_83_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_83_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_83_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_83_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_83_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_83_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_83_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_83_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_83_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_83_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_83_ADDRESS                                       (0x14c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_83_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_83_RESET                                         0x0

// 0x150 (PHY_BB_DUMMY_SM_BCAST_84)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_84_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_84_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_84_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_84_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_84_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_84_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_84_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_84_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_84_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_84_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_84_ADDRESS                                       (0x150 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_84_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_84_RESET                                         0x0

// 0x154 (PHY_BB_DUMMY_SM_BCAST_85)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_85_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_85_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_85_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_85_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_85_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_85_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_85_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_85_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_85_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_85_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_85_ADDRESS                                       (0x154 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_85_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_85_RESET                                         0x0

// 0x158 (PHY_BB_DUMMY_SM_BCAST_86)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_86_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_86_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_86_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_86_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_86_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_86_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_86_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_86_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_86_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_86_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_86_ADDRESS                                       (0x158 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_86_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_86_RESET                                         0x0

// 0x15c (PHY_BB_DUMMY_SM_BCAST_87)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_87_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_87_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_87_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_87_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_87_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_87_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_87_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_87_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_87_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_87_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_87_ADDRESS                                       (0x15c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_87_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_87_RESET                                         0x0

// 0x160 (PHY_BB_DUMMY_SM_BCAST_88)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_88_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_88_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_88_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_88_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_88_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_88_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_88_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_88_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_88_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_88_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_88_ADDRESS                                       (0x160 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_88_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_88_RESET                                         0x0

// 0x164 (PHY_BB_DUMMY_SM_BCAST_89)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_89_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_89_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_89_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_89_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_89_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_89_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_89_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_89_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_89_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_89_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_89_ADDRESS                                       (0x164 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_89_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_89_RESET                                         0x0

// 0x168 (PHY_BB_DUMMY_SM_BCAST_90)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_90_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_90_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_90_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_90_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_90_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_90_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_90_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_90_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_90_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_90_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_90_ADDRESS                                       (0x168 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_90_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_90_RESET                                         0x0

// 0x16c (PHY_BB_DUMMY_SM_BCAST_91)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_91_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_91_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_91_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_91_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_91_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_91_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_91_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_91_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_91_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_91_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_91_ADDRESS                                       (0x16c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_91_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_91_RESET                                         0x0

// 0x170 (PHY_BB_DUMMY_SM_BCAST_92)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_92_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_92_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_92_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_92_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_92_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_92_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_92_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_92_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_92_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_92_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_92_ADDRESS                                       (0x170 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_92_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_92_RESET                                         0x0

// 0x174 (PHY_BB_DUMMY_SM_BCAST_93)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_93_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_93_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_93_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_93_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_93_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_93_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_93_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_93_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_93_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_93_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_93_ADDRESS                                       (0x174 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_93_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_93_RESET                                         0x0

// 0x178 (PHY_BB_DUMMY_SM_BCAST_94)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_94_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_94_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_94_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_94_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_94_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_94_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_94_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_94_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_94_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_94_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_94_ADDRESS                                       (0x178 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_94_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_94_RESET                                         0x0

// 0x17c (PHY_BB_DUMMY_SM_BCAST_95)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_95_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_95_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_95_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_95_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_95_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_95_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_95_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_95_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_95_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_95_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_95_ADDRESS                                       (0x17c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_95_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_95_RESET                                         0x0

// 0x180 (PHY_BB_DUMMY_SM_BCAST_96)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_96_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_96_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_96_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_96_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_96_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_96_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_96_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_96_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_96_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_96_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_96_ADDRESS                                       (0x180 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_96_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_96_RESET                                         0x0

// 0x184 (PHY_BB_DUMMY_SM_BCAST_97)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_97_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_97_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_97_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_97_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_97_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_97_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_97_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_97_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_97_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_97_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_97_ADDRESS                                       (0x184 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_97_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_97_RESET                                         0x0

// 0x188 (PHY_BB_DUMMY_SM_BCAST_98)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_98_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_98_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_98_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_98_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_98_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_98_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_98_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_98_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_98_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_98_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_98_ADDRESS                                       (0x188 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_98_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_98_RESET                                         0x0

// 0x18c (PHY_BB_DUMMY_SM_BCAST_99)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_99_LSB                                     0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_99_MSB                                     31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_99_MASK                                    0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_99_GET(x)                                  (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_99_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_99_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_99_SET(x)                                  (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_99_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_99_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_99_RESET                                   0x0
#define PHY_BB_DUMMY_SM_BCAST_99_ADDRESS                                       (0x18c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_99_RSTMASK                                       0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_99_RESET                                         0x0

// 0x190 (PHY_BB_DUMMY_SM_BCAST_100)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_100_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_100_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_100_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_100_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_100_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_100_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_100_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_100_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_100_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_100_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_100_ADDRESS                                      (0x190 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_100_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_100_RESET                                        0x0

// 0x194 (PHY_BB_DUMMY_SM_BCAST_101)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_101_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_101_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_101_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_101_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_101_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_101_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_101_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_101_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_101_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_101_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_101_ADDRESS                                      (0x194 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_101_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_101_RESET                                        0x0

// 0x198 (PHY_BB_DUMMY_SM_BCAST_102)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_102_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_102_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_102_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_102_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_102_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_102_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_102_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_102_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_102_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_102_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_102_ADDRESS                                      (0x198 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_102_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_102_RESET                                        0x0

// 0x19c (PHY_BB_DUMMY_SM_BCAST_103)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_103_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_103_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_103_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_103_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_103_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_103_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_103_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_103_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_103_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_103_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_103_ADDRESS                                      (0x19c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_103_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_103_RESET                                        0x0

// 0x1a0 (PHY_BB_DUMMY_SM_BCAST_104)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_104_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_104_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_104_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_104_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_104_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_104_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_104_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_104_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_104_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_104_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_104_ADDRESS                                      (0x1a0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_104_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_104_RESET                                        0x0

// 0x1a4 (PHY_BB_DUMMY_SM_BCAST_105)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_105_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_105_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_105_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_105_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_105_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_105_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_105_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_105_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_105_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_105_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_105_ADDRESS                                      (0x1a4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_105_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_105_RESET                                        0x0

// 0x1a8 (PHY_BB_DUMMY_SM_BCAST_106)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_106_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_106_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_106_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_106_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_106_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_106_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_106_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_106_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_106_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_106_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_106_ADDRESS                                      (0x1a8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_106_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_106_RESET                                        0x0

// 0x1ac (PHY_BB_DUMMY_SM_BCAST_107)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_107_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_107_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_107_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_107_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_107_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_107_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_107_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_107_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_107_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_107_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_107_ADDRESS                                      (0x1ac + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_107_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_107_RESET                                        0x0

// 0x1b0 (PHY_BB_DUMMY_SM_BCAST_108)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_108_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_108_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_108_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_108_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_108_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_108_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_108_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_108_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_108_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_108_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_108_ADDRESS                                      (0x1b0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_108_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_108_RESET                                        0x0

// 0x1b4 (PHY_BB_DUMMY_SM_BCAST_109)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_109_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_109_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_109_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_109_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_109_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_109_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_109_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_109_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_109_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_109_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_109_ADDRESS                                      (0x1b4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_109_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_109_RESET                                        0x0

// 0x1b8 (PHY_BB_DUMMY_SM_BCAST_110)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_110_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_110_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_110_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_110_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_110_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_110_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_110_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_110_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_110_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_110_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_110_ADDRESS                                      (0x1b8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_110_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_110_RESET                                        0x0

// 0x1bc (PHY_BB_DUMMY_SM_BCAST_111)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_111_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_111_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_111_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_111_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_111_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_111_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_111_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_111_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_111_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_111_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_111_ADDRESS                                      (0x1bc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_111_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_111_RESET                                        0x0

// 0x1c0 (PHY_BB_DUMMY_SM_BCAST_112)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_112_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_112_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_112_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_112_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_112_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_112_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_112_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_112_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_112_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_112_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_112_ADDRESS                                      (0x1c0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_112_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_112_RESET                                        0x0

// 0x1c4 (PHY_BB_DUMMY_SM_BCAST_113)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_113_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_113_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_113_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_113_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_113_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_113_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_113_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_113_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_113_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_113_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_113_ADDRESS                                      (0x1c4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_113_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_113_RESET                                        0x0

// 0x1c8 (PHY_BB_DUMMY_SM_BCAST_114)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_114_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_114_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_114_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_114_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_114_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_114_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_114_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_114_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_114_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_114_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_114_ADDRESS                                      (0x1c8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_114_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_114_RESET                                        0x0

// 0x1cc (PHY_BB_DUMMY_SM_BCAST_115)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_115_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_115_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_115_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_115_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_115_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_115_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_115_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_115_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_115_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_115_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_115_ADDRESS                                      (0x1cc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_115_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_115_RESET                                        0x0

// 0x1d0 (PHY_BB_DUMMY_SM_BCAST_116)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_116_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_116_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_116_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_116_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_116_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_116_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_116_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_116_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_116_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_116_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_116_ADDRESS                                      (0x1d0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_116_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_116_RESET                                        0x0

// 0x1d4 (PHY_BB_DUMMY_SM_BCAST_117)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_117_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_117_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_117_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_117_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_117_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_117_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_117_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_117_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_117_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_117_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_117_ADDRESS                                      (0x1d4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_117_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_117_RESET                                        0x0

// 0x1d8 (PHY_BB_DUMMY_SM_BCAST_118)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_118_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_118_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_118_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_118_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_118_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_118_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_118_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_118_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_118_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_118_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_118_ADDRESS                                      (0x1d8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_118_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_118_RESET                                        0x0

// 0x1dc (PHY_BB_DUMMY_SM_BCAST_119)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_119_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_119_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_119_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_119_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_119_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_119_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_119_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_119_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_119_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_119_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_119_ADDRESS                                      (0x1dc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_119_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_119_RESET                                        0x0

// 0x1e0 (PHY_BB_DUMMY_SM_BCAST_120)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_120_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_120_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_120_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_120_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_120_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_120_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_120_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_120_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_120_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_120_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_120_ADDRESS                                      (0x1e0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_120_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_120_RESET                                        0x0

// 0x1e4 (PHY_BB_DUMMY_SM_BCAST_121)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_121_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_121_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_121_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_121_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_121_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_121_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_121_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_121_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_121_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_121_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_121_ADDRESS                                      (0x1e4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_121_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_121_RESET                                        0x0

// 0x1e8 (PHY_BB_DUMMY_SM_BCAST_122)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_122_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_122_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_122_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_122_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_122_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_122_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_122_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_122_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_122_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_122_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_122_ADDRESS                                      (0x1e8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_122_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_122_RESET                                        0x0

// 0x1ec (PHY_BB_DUMMY_SM_BCAST_123)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_123_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_123_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_123_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_123_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_123_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_123_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_123_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_123_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_123_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_123_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_123_ADDRESS                                      (0x1ec + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_123_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_123_RESET                                        0x0

// 0x1f0 (PHY_BB_DUMMY_SM_BCAST_124)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_124_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_124_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_124_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_124_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_124_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_124_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_124_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_124_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_124_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_124_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_124_ADDRESS                                      (0x1f0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_124_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_124_RESET                                        0x0

// 0x1f4 (PHY_BB_DUMMY_SM_BCAST_125)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_125_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_125_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_125_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_125_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_125_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_125_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_125_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_125_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_125_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_125_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_125_ADDRESS                                      (0x1f4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_125_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_125_RESET                                        0x0

// 0x1f8 (PHY_BB_DUMMY_SM_BCAST_126)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_126_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_126_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_126_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_126_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_126_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_126_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_126_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_126_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_126_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_126_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_126_ADDRESS                                      (0x1f8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_126_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_126_RESET                                        0x0

// 0x1fc (PHY_BB_DUMMY_SM_BCAST_127)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_127_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_127_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_127_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_127_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_127_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_127_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_127_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_127_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_127_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_127_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_127_ADDRESS                                      (0x1fc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_127_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_127_RESET                                        0x0

// 0x200 (PHY_BB_DUMMY_SM_BCAST_128)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_128_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_128_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_128_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_128_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_128_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_128_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_128_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_128_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_128_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_128_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_128_ADDRESS                                      (0x200 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_128_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_128_RESET                                        0x0

// 0x204 (PHY_BB_DUMMY_SM_BCAST_129)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_129_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_129_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_129_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_129_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_129_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_129_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_129_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_129_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_129_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_129_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_129_ADDRESS                                      (0x204 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_129_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_129_RESET                                        0x0

// 0x208 (PHY_BB_DUMMY_SM_BCAST_130)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_130_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_130_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_130_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_130_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_130_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_130_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_130_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_130_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_130_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_130_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_130_ADDRESS                                      (0x208 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_130_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_130_RESET                                        0x0

// 0x20c (PHY_BB_DUMMY_SM_BCAST_131)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_131_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_131_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_131_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_131_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_131_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_131_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_131_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_131_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_131_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_131_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_131_ADDRESS                                      (0x20c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_131_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_131_RESET                                        0x0

// 0x210 (PHY_BB_DUMMY_SM_BCAST_132)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_132_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_132_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_132_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_132_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_132_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_132_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_132_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_132_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_132_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_132_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_132_ADDRESS                                      (0x210 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_132_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_132_RESET                                        0x0

// 0x214 (PHY_BB_DUMMY_SM_BCAST_133)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_133_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_133_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_133_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_133_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_133_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_133_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_133_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_133_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_133_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_133_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_133_ADDRESS                                      (0x214 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_133_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_133_RESET                                        0x0

// 0x218 (PHY_BB_DUMMY_SM_BCAST_134)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_134_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_134_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_134_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_134_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_134_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_134_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_134_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_134_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_134_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_134_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_134_ADDRESS                                      (0x218 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_134_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_134_RESET                                        0x0

// 0x21c (PHY_BB_DUMMY_SM_BCAST_135)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_135_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_135_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_135_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_135_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_135_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_135_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_135_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_135_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_135_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_135_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_135_ADDRESS                                      (0x21c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_135_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_135_RESET                                        0x0

// 0x220 (PHY_BB_DUMMY_SM_BCAST_136)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_136_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_136_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_136_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_136_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_136_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_136_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_136_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_136_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_136_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_136_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_136_ADDRESS                                      (0x220 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_136_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_136_RESET                                        0x0

// 0x224 (PHY_BB_DUMMY_SM_BCAST_137)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_137_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_137_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_137_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_137_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_137_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_137_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_137_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_137_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_137_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_137_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_137_ADDRESS                                      (0x224 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_137_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_137_RESET                                        0x0

// 0x228 (PHY_BB_DUMMY_SM_BCAST_138)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_138_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_138_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_138_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_138_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_138_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_138_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_138_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_138_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_138_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_138_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_138_ADDRESS                                      (0x228 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_138_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_138_RESET                                        0x0

// 0x22c (PHY_BB_DUMMY_SM_BCAST_139)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_139_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_139_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_139_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_139_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_139_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_139_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_139_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_139_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_139_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_139_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_139_ADDRESS                                      (0x22c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_139_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_139_RESET                                        0x0

// 0x230 (PHY_BB_DUMMY_SM_BCAST_140)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_140_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_140_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_140_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_140_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_140_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_140_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_140_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_140_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_140_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_140_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_140_ADDRESS                                      (0x230 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_140_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_140_RESET                                        0x0

// 0x234 (PHY_BB_DUMMY_SM_BCAST_141)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_141_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_141_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_141_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_141_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_141_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_141_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_141_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_141_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_141_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_141_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_141_ADDRESS                                      (0x234 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_141_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_141_RESET                                        0x0

// 0x238 (PHY_BB_DUMMY_SM_BCAST_142)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_142_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_142_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_142_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_142_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_142_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_142_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_142_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_142_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_142_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_142_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_142_ADDRESS                                      (0x238 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_142_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_142_RESET                                        0x0

// 0x23c (PHY_BB_DUMMY_SM_BCAST_143)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_143_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_143_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_143_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_143_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_143_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_143_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_143_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_143_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_143_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_143_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_143_ADDRESS                                      (0x23c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_143_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_143_RESET                                        0x0

// 0x240 (PHY_BB_DUMMY_SM_BCAST_144)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_144_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_144_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_144_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_144_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_144_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_144_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_144_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_144_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_144_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_144_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_144_ADDRESS                                      (0x240 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_144_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_144_RESET                                        0x0

// 0x244 (PHY_BB_DUMMY_SM_BCAST_145)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_145_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_145_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_145_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_145_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_145_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_145_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_145_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_145_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_145_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_145_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_145_ADDRESS                                      (0x244 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_145_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_145_RESET                                        0x0

// 0x248 (PHY_BB_DUMMY_SM_BCAST_146)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_146_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_146_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_146_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_146_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_146_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_146_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_146_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_146_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_146_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_146_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_146_ADDRESS                                      (0x248 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_146_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_146_RESET                                        0x0

// 0x24c (PHY_BB_DUMMY_SM_BCAST_147)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_147_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_147_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_147_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_147_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_147_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_147_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_147_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_147_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_147_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_147_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_147_ADDRESS                                      (0x24c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_147_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_147_RESET                                        0x0

// 0x250 (PHY_BB_DUMMY_SM_BCAST_148)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_148_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_148_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_148_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_148_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_148_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_148_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_148_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_148_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_148_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_148_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_148_ADDRESS                                      (0x250 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_148_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_148_RESET                                        0x0

// 0x254 (PHY_BB_DUMMY_SM_BCAST_149)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_149_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_149_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_149_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_149_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_149_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_149_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_149_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_149_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_149_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_149_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_149_ADDRESS                                      (0x254 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_149_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_149_RESET                                        0x0

// 0x258 (PHY_BB_DUMMY_SM_BCAST_150)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_150_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_150_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_150_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_150_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_150_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_150_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_150_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_150_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_150_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_150_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_150_ADDRESS                                      (0x258 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_150_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_150_RESET                                        0x0

// 0x25c (PHY_BB_DUMMY_SM_BCAST_151)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_151_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_151_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_151_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_151_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_151_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_151_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_151_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_151_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_151_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_151_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_151_ADDRESS                                      (0x25c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_151_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_151_RESET                                        0x0

// 0x260 (PHY_BB_DUMMY_SM_BCAST_152)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_152_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_152_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_152_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_152_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_152_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_152_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_152_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_152_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_152_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_152_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_152_ADDRESS                                      (0x260 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_152_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_152_RESET                                        0x0

// 0x264 (PHY_BB_DUMMY_SM_BCAST_153)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_153_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_153_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_153_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_153_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_153_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_153_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_153_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_153_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_153_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_153_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_153_ADDRESS                                      (0x264 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_153_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_153_RESET                                        0x0

// 0x268 (PHY_BB_DUMMY_SM_BCAST_154)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_154_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_154_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_154_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_154_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_154_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_154_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_154_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_154_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_154_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_154_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_154_ADDRESS                                      (0x268 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_154_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_154_RESET                                        0x0

// 0x26c (PHY_BB_DUMMY_SM_BCAST_155)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_155_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_155_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_155_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_155_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_155_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_155_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_155_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_155_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_155_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_155_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_155_ADDRESS                                      (0x26c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_155_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_155_RESET                                        0x0

// 0x270 (PHY_BB_DUMMY_SM_BCAST_156)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_156_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_156_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_156_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_156_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_156_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_156_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_156_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_156_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_156_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_156_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_156_ADDRESS                                      (0x270 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_156_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_156_RESET                                        0x0

// 0x274 (PHY_BB_DUMMY_SM_BCAST_157)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_157_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_157_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_157_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_157_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_157_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_157_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_157_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_157_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_157_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_157_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_157_ADDRESS                                      (0x274 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_157_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_157_RESET                                        0x0

// 0x278 (PHY_BB_DUMMY_SM_BCAST_158)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_158_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_158_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_158_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_158_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_158_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_158_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_158_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_158_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_158_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_158_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_158_ADDRESS                                      (0x278 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_158_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_158_RESET                                        0x0

// 0x27c (PHY_BB_DUMMY_SM_BCAST_159)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_159_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_159_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_159_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_159_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_159_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_159_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_159_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_159_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_159_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_159_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_159_ADDRESS                                      (0x27c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_159_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_159_RESET                                        0x0

// 0x280 (PHY_BB_DUMMY_SM_BCAST_160)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_160_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_160_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_160_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_160_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_160_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_160_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_160_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_160_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_160_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_160_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_160_ADDRESS                                      (0x280 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_160_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_160_RESET                                        0x0

// 0x284 (PHY_BB_DUMMY_SM_BCAST_161)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_161_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_161_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_161_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_161_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_161_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_161_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_161_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_161_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_161_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_161_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_161_ADDRESS                                      (0x284 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_161_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_161_RESET                                        0x0

// 0x288 (PHY_BB_DUMMY_SM_BCAST_162)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_162_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_162_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_162_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_162_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_162_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_162_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_162_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_162_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_162_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_162_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_162_ADDRESS                                      (0x288 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_162_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_162_RESET                                        0x0

// 0x28c (PHY_BB_DUMMY_SM_BCAST_163)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_163_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_163_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_163_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_163_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_163_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_163_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_163_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_163_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_163_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_163_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_163_ADDRESS                                      (0x28c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_163_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_163_RESET                                        0x0

// 0x290 (PHY_BB_DUMMY_SM_BCAST_164)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_164_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_164_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_164_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_164_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_164_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_164_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_164_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_164_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_164_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_164_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_164_ADDRESS                                      (0x290 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_164_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_164_RESET                                        0x0

// 0x294 (PHY_BB_DUMMY_SM_BCAST_165)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_165_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_165_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_165_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_165_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_165_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_165_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_165_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_165_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_165_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_165_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_165_ADDRESS                                      (0x294 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_165_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_165_RESET                                        0x0

// 0x298 (PHY_BB_DUMMY_SM_BCAST_166)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_166_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_166_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_166_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_166_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_166_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_166_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_166_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_166_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_166_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_166_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_166_ADDRESS                                      (0x298 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_166_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_166_RESET                                        0x0

// 0x29c (PHY_BB_DUMMY_SM_BCAST_167)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_167_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_167_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_167_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_167_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_167_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_167_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_167_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_167_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_167_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_167_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_167_ADDRESS                                      (0x29c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_167_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_167_RESET                                        0x0

// 0x2a0 (PHY_BB_DUMMY_SM_BCAST_168)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_168_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_168_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_168_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_168_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_168_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_168_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_168_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_168_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_168_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_168_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_168_ADDRESS                                      (0x2a0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_168_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_168_RESET                                        0x0

// 0x2a4 (PHY_BB_DUMMY_SM_BCAST_169)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_169_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_169_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_169_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_169_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_169_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_169_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_169_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_169_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_169_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_169_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_169_ADDRESS                                      (0x2a4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_169_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_169_RESET                                        0x0

// 0x2a8 (PHY_BB_DUMMY_SM_BCAST_170)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_170_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_170_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_170_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_170_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_170_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_170_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_170_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_170_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_170_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_170_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_170_ADDRESS                                      (0x2a8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_170_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_170_RESET                                        0x0

// 0x2ac (PHY_BB_DUMMY_SM_BCAST_171)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_171_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_171_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_171_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_171_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_171_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_171_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_171_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_171_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_171_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_171_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_171_ADDRESS                                      (0x2ac + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_171_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_171_RESET                                        0x0

// 0x2b0 (PHY_BB_DUMMY_SM_BCAST_172)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_172_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_172_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_172_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_172_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_172_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_172_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_172_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_172_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_172_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_172_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_172_ADDRESS                                      (0x2b0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_172_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_172_RESET                                        0x0

// 0x2b4 (PHY_BB_DUMMY_SM_BCAST_173)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_173_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_173_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_173_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_173_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_173_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_173_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_173_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_173_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_173_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_173_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_173_ADDRESS                                      (0x2b4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_173_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_173_RESET                                        0x0

// 0x2b8 (PHY_BB_DUMMY_SM_BCAST_174)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_174_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_174_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_174_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_174_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_174_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_174_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_174_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_174_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_174_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_174_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_174_ADDRESS                                      (0x2b8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_174_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_174_RESET                                        0x0

// 0x2bc (PHY_BB_DUMMY_SM_BCAST_175)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_175_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_175_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_175_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_175_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_175_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_175_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_175_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_175_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_175_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_175_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_175_ADDRESS                                      (0x2bc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_175_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_175_RESET                                        0x0

// 0x2c0 (PHY_BB_DUMMY_SM_BCAST_176)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_176_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_176_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_176_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_176_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_176_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_176_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_176_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_176_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_176_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_176_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_176_ADDRESS                                      (0x2c0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_176_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_176_RESET                                        0x0

// 0x2c4 (PHY_BB_DUMMY_SM_BCAST_177)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_177_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_177_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_177_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_177_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_177_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_177_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_177_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_177_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_177_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_177_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_177_ADDRESS                                      (0x2c4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_177_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_177_RESET                                        0x0

// 0x2c8 (PHY_BB_DUMMY_SM_BCAST_178)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_178_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_178_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_178_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_178_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_178_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_178_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_178_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_178_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_178_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_178_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_178_ADDRESS                                      (0x2c8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_178_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_178_RESET                                        0x0

// 0x2cc (PHY_BB_DUMMY_SM_BCAST_179)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_179_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_179_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_179_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_179_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_179_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_179_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_179_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_179_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_179_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_179_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_179_ADDRESS                                      (0x2cc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_179_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_179_RESET                                        0x0

// 0x2d0 (PHY_BB_DUMMY_SM_BCAST_180)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_180_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_180_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_180_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_180_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_180_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_180_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_180_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_180_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_180_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_180_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_180_ADDRESS                                      (0x2d0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_180_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_180_RESET                                        0x0

// 0x2d4 (PHY_BB_DUMMY_SM_BCAST_181)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_181_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_181_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_181_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_181_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_181_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_181_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_181_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_181_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_181_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_181_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_181_ADDRESS                                      (0x2d4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_181_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_181_RESET                                        0x0

// 0x2d8 (PHY_BB_DUMMY_SM_BCAST_182)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_182_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_182_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_182_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_182_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_182_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_182_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_182_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_182_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_182_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_182_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_182_ADDRESS                                      (0x2d8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_182_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_182_RESET                                        0x0

// 0x2dc (PHY_BB_DUMMY_SM_BCAST_183)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_183_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_183_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_183_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_183_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_183_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_183_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_183_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_183_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_183_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_183_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_183_ADDRESS                                      (0x2dc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_183_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_183_RESET                                        0x0

// 0x2e0 (PHY_BB_DUMMY_SM_BCAST_184)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_184_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_184_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_184_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_184_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_184_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_184_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_184_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_184_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_184_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_184_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_184_ADDRESS                                      (0x2e0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_184_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_184_RESET                                        0x0

// 0x2e4 (PHY_BB_DUMMY_SM_BCAST_185)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_185_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_185_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_185_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_185_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_185_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_185_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_185_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_185_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_185_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_185_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_185_ADDRESS                                      (0x2e4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_185_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_185_RESET                                        0x0

// 0x2e8 (PHY_BB_DUMMY_SM_BCAST_186)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_186_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_186_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_186_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_186_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_186_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_186_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_186_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_186_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_186_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_186_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_186_ADDRESS                                      (0x2e8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_186_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_186_RESET                                        0x0

// 0x2ec (PHY_BB_DUMMY_SM_BCAST_187)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_187_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_187_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_187_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_187_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_187_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_187_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_187_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_187_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_187_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_187_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_187_ADDRESS                                      (0x2ec + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_187_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_187_RESET                                        0x0

// 0x2f0 (PHY_BB_DUMMY_SM_BCAST_188)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_188_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_188_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_188_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_188_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_188_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_188_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_188_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_188_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_188_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_188_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_188_ADDRESS                                      (0x2f0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_188_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_188_RESET                                        0x0

// 0x2f4 (PHY_BB_DUMMY_SM_BCAST_189)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_189_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_189_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_189_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_189_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_189_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_189_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_189_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_189_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_189_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_189_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_189_ADDRESS                                      (0x2f4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_189_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_189_RESET                                        0x0

// 0x2f8 (PHY_BB_DUMMY_SM_BCAST_190)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_190_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_190_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_190_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_190_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_190_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_190_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_190_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_190_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_190_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_190_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_190_ADDRESS                                      (0x2f8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_190_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_190_RESET                                        0x0

// 0x2fc (PHY_BB_DUMMY_SM_BCAST_191)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_191_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_191_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_191_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_191_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_191_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_191_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_191_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_191_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_191_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_191_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_191_ADDRESS                                      (0x2fc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_191_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_191_RESET                                        0x0

// 0x300 (PHY_BB_DUMMY_SM_BCAST_192)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_192_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_192_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_192_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_192_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_192_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_192_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_192_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_192_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_192_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_192_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_192_ADDRESS                                      (0x300 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_192_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_192_RESET                                        0x0

// 0x304 (PHY_BB_DUMMY_SM_BCAST_193)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_193_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_193_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_193_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_193_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_193_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_193_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_193_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_193_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_193_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_193_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_193_ADDRESS                                      (0x304 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_193_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_193_RESET                                        0x0

// 0x308 (PHY_BB_DUMMY_SM_BCAST_194)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_194_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_194_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_194_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_194_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_194_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_194_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_194_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_194_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_194_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_194_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_194_ADDRESS                                      (0x308 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_194_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_194_RESET                                        0x0

// 0x30c (PHY_BB_DUMMY_SM_BCAST_195)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_195_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_195_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_195_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_195_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_195_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_195_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_195_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_195_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_195_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_195_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_195_ADDRESS                                      (0x30c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_195_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_195_RESET                                        0x0

// 0x310 (PHY_BB_DUMMY_SM_BCAST_196)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_196_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_196_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_196_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_196_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_196_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_196_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_196_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_196_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_196_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_196_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_196_ADDRESS                                      (0x310 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_196_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_196_RESET                                        0x0

// 0x314 (PHY_BB_DUMMY_SM_BCAST_197)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_197_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_197_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_197_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_197_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_197_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_197_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_197_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_197_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_197_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_197_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_197_ADDRESS                                      (0x314 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_197_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_197_RESET                                        0x0

// 0x318 (PHY_BB_DUMMY_SM_BCAST_198)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_198_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_198_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_198_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_198_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_198_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_198_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_198_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_198_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_198_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_198_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_198_ADDRESS                                      (0x318 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_198_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_198_RESET                                        0x0

// 0x31c (PHY_BB_DUMMY_SM_BCAST_199)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_199_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_199_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_199_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_199_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_199_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_199_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_199_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_199_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_199_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_199_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_199_ADDRESS                                      (0x31c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_199_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_199_RESET                                        0x0

// 0x320 (PHY_BB_DUMMY_SM_BCAST_200)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_200_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_200_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_200_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_200_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_200_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_200_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_200_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_200_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_200_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_200_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_200_ADDRESS                                      (0x320 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_200_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_200_RESET                                        0x0

// 0x324 (PHY_BB_DUMMY_SM_BCAST_201)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_201_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_201_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_201_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_201_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_201_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_201_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_201_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_201_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_201_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_201_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_201_ADDRESS                                      (0x324 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_201_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_201_RESET                                        0x0

// 0x328 (PHY_BB_DUMMY_SM_BCAST_202)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_202_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_202_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_202_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_202_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_202_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_202_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_202_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_202_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_202_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_202_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_202_ADDRESS                                      (0x328 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_202_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_202_RESET                                        0x0

// 0x32c (PHY_BB_DUMMY_SM_BCAST_203)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_203_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_203_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_203_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_203_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_203_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_203_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_203_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_203_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_203_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_203_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_203_ADDRESS                                      (0x32c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_203_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_203_RESET                                        0x0

// 0x330 (PHY_BB_DUMMY_SM_BCAST_204)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_204_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_204_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_204_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_204_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_204_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_204_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_204_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_204_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_204_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_204_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_204_ADDRESS                                      (0x330 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_204_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_204_RESET                                        0x0

// 0x334 (PHY_BB_DUMMY_SM_BCAST_205)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_205_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_205_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_205_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_205_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_205_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_205_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_205_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_205_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_205_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_205_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_205_ADDRESS                                      (0x334 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_205_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_205_RESET                                        0x0

// 0x338 (PHY_BB_DUMMY_SM_BCAST_206)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_206_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_206_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_206_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_206_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_206_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_206_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_206_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_206_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_206_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_206_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_206_ADDRESS                                      (0x338 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_206_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_206_RESET                                        0x0

// 0x33c (PHY_BB_DUMMY_SM_BCAST_207)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_207_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_207_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_207_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_207_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_207_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_207_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_207_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_207_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_207_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_207_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_207_ADDRESS                                      (0x33c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_207_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_207_RESET                                        0x0

// 0x340 (PHY_BB_DUMMY_SM_BCAST_208)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_208_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_208_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_208_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_208_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_208_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_208_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_208_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_208_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_208_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_208_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_208_ADDRESS                                      (0x340 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_208_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_208_RESET                                        0x0

// 0x344 (PHY_BB_DUMMY_SM_BCAST_209)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_209_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_209_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_209_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_209_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_209_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_209_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_209_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_209_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_209_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_209_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_209_ADDRESS                                      (0x344 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_209_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_209_RESET                                        0x0

// 0x348 (PHY_BB_DUMMY_SM_BCAST_210)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_210_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_210_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_210_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_210_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_210_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_210_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_210_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_210_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_210_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_210_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_210_ADDRESS                                      (0x348 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_210_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_210_RESET                                        0x0

// 0x34c (PHY_BB_DUMMY_SM_BCAST_211)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_211_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_211_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_211_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_211_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_211_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_211_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_211_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_211_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_211_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_211_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_211_ADDRESS                                      (0x34c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_211_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_211_RESET                                        0x0

// 0x350 (PHY_BB_DUMMY_SM_BCAST_212)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_212_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_212_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_212_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_212_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_212_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_212_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_212_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_212_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_212_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_212_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_212_ADDRESS                                      (0x350 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_212_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_212_RESET                                        0x0

// 0x354 (PHY_BB_DUMMY_SM_BCAST_213)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_213_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_213_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_213_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_213_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_213_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_213_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_213_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_213_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_213_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_213_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_213_ADDRESS                                      (0x354 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_213_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_213_RESET                                        0x0

// 0x358 (PHY_BB_DUMMY_SM_BCAST_214)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_214_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_214_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_214_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_214_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_214_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_214_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_214_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_214_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_214_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_214_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_214_ADDRESS                                      (0x358 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_214_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_214_RESET                                        0x0

// 0x35c (PHY_BB_DUMMY_SM_BCAST_215)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_215_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_215_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_215_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_215_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_215_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_215_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_215_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_215_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_215_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_215_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_215_ADDRESS                                      (0x35c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_215_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_215_RESET                                        0x0

// 0x360 (PHY_BB_DUMMY_SM_BCAST_216)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_216_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_216_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_216_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_216_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_216_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_216_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_216_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_216_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_216_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_216_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_216_ADDRESS                                      (0x360 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_216_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_216_RESET                                        0x0

// 0x364 (PHY_BB_DUMMY_SM_BCAST_217)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_217_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_217_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_217_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_217_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_217_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_217_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_217_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_217_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_217_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_217_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_217_ADDRESS                                      (0x364 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_217_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_217_RESET                                        0x0

// 0x368 (PHY_BB_DUMMY_SM_BCAST_218)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_218_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_218_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_218_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_218_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_218_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_218_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_218_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_218_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_218_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_218_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_218_ADDRESS                                      (0x368 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_218_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_218_RESET                                        0x0

// 0x36c (PHY_BB_DUMMY_SM_BCAST_219)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_219_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_219_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_219_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_219_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_219_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_219_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_219_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_219_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_219_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_219_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_219_ADDRESS                                      (0x36c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_219_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_219_RESET                                        0x0

// 0x370 (PHY_BB_DUMMY_SM_BCAST_220)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_220_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_220_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_220_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_220_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_220_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_220_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_220_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_220_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_220_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_220_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_220_ADDRESS                                      (0x370 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_220_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_220_RESET                                        0x0

// 0x374 (PHY_BB_DUMMY_SM_BCAST_221)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_221_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_221_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_221_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_221_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_221_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_221_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_221_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_221_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_221_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_221_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_221_ADDRESS                                      (0x374 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_221_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_221_RESET                                        0x0

// 0x378 (PHY_BB_DUMMY_SM_BCAST_222)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_222_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_222_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_222_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_222_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_222_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_222_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_222_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_222_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_222_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_222_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_222_ADDRESS                                      (0x378 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_222_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_222_RESET                                        0x0

// 0x37c (PHY_BB_DUMMY_SM_BCAST_223)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_223_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_223_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_223_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_223_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_223_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_223_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_223_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_223_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_223_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_223_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_223_ADDRESS                                      (0x37c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_223_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_223_RESET                                        0x0

// 0x380 (PHY_BB_DUMMY_SM_BCAST_224)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_224_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_224_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_224_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_224_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_224_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_224_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_224_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_224_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_224_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_224_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_224_ADDRESS                                      (0x380 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_224_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_224_RESET                                        0x0

// 0x384 (PHY_BB_DUMMY_SM_BCAST_225)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_225_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_225_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_225_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_225_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_225_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_225_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_225_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_225_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_225_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_225_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_225_ADDRESS                                      (0x384 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_225_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_225_RESET                                        0x0

// 0x388 (PHY_BB_DUMMY_SM_BCAST_226)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_226_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_226_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_226_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_226_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_226_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_226_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_226_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_226_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_226_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_226_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_226_ADDRESS                                      (0x388 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_226_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_226_RESET                                        0x0

// 0x38c (PHY_BB_DUMMY_SM_BCAST_227)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_227_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_227_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_227_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_227_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_227_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_227_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_227_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_227_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_227_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_227_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_227_ADDRESS                                      (0x38c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_227_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_227_RESET                                        0x0

// 0x390 (PHY_BB_DUMMY_SM_BCAST_228)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_228_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_228_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_228_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_228_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_228_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_228_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_228_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_228_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_228_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_228_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_228_ADDRESS                                      (0x390 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_228_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_228_RESET                                        0x0

// 0x394 (PHY_BB_DUMMY_SM_BCAST_229)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_229_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_229_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_229_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_229_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_229_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_229_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_229_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_229_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_229_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_229_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_229_ADDRESS                                      (0x394 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_229_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_229_RESET                                        0x0

// 0x398 (PHY_BB_DUMMY_SM_BCAST_230)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_230_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_230_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_230_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_230_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_230_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_230_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_230_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_230_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_230_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_230_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_230_ADDRESS                                      (0x398 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_230_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_230_RESET                                        0x0

// 0x39c (PHY_BB_DUMMY_SM_BCAST_231)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_231_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_231_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_231_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_231_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_231_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_231_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_231_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_231_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_231_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_231_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_231_ADDRESS                                      (0x39c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_231_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_231_RESET                                        0x0

// 0x3a0 (PHY_BB_DUMMY_SM_BCAST_232)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_232_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_232_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_232_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_232_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_232_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_232_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_232_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_232_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_232_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_232_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_232_ADDRESS                                      (0x3a0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_232_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_232_RESET                                        0x0

// 0x3a4 (PHY_BB_DUMMY_SM_BCAST_233)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_233_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_233_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_233_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_233_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_233_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_233_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_233_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_233_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_233_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_233_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_233_ADDRESS                                      (0x3a4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_233_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_233_RESET                                        0x0

// 0x3a8 (PHY_BB_DUMMY_SM_BCAST_234)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_234_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_234_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_234_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_234_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_234_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_234_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_234_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_234_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_234_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_234_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_234_ADDRESS                                      (0x3a8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_234_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_234_RESET                                        0x0

// 0x3ac (PHY_BB_DUMMY_SM_BCAST_235)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_235_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_235_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_235_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_235_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_235_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_235_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_235_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_235_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_235_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_235_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_235_ADDRESS                                      (0x3ac + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_235_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_235_RESET                                        0x0

// 0x3b0 (PHY_BB_DUMMY_SM_BCAST_236)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_236_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_236_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_236_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_236_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_236_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_236_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_236_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_236_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_236_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_236_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_236_ADDRESS                                      (0x3b0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_236_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_236_RESET                                        0x0

// 0x3b4 (PHY_BB_DUMMY_SM_BCAST_237)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_237_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_237_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_237_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_237_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_237_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_237_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_237_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_237_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_237_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_237_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_237_ADDRESS                                      (0x3b4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_237_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_237_RESET                                        0x0

// 0x3b8 (PHY_BB_DUMMY_SM_BCAST_238)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_238_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_238_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_238_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_238_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_238_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_238_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_238_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_238_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_238_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_238_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_238_ADDRESS                                      (0x3b8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_238_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_238_RESET                                        0x0

// 0x3bc (PHY_BB_DUMMY_SM_BCAST_239)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_239_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_239_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_239_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_239_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_239_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_239_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_239_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_239_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_239_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_239_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_239_ADDRESS                                      (0x3bc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_239_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_239_RESET                                        0x0

// 0x3c0 (PHY_BB_DUMMY_SM_BCAST_240)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_240_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_240_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_240_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_240_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_240_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_240_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_240_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_240_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_240_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_240_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_240_ADDRESS                                      (0x3c0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_240_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_240_RESET                                        0x0

// 0x3c4 (PHY_BB_DUMMY_SM_BCAST_241)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_241_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_241_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_241_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_241_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_241_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_241_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_241_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_241_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_241_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_241_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_241_ADDRESS                                      (0x3c4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_241_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_241_RESET                                        0x0

// 0x3c8 (PHY_BB_DUMMY_SM_BCAST_242)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_242_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_242_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_242_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_242_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_242_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_242_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_242_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_242_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_242_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_242_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_242_ADDRESS                                      (0x3c8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_242_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_242_RESET                                        0x0

// 0x3cc (PHY_BB_DUMMY_SM_BCAST_243)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_243_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_243_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_243_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_243_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_243_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_243_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_243_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_243_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_243_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_243_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_243_ADDRESS                                      (0x3cc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_243_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_243_RESET                                        0x0

// 0x3d0 (PHY_BB_DUMMY_SM_BCAST_244)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_244_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_244_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_244_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_244_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_244_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_244_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_244_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_244_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_244_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_244_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_244_ADDRESS                                      (0x3d0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_244_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_244_RESET                                        0x0

// 0x3d4 (PHY_BB_DUMMY_SM_BCAST_245)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_245_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_245_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_245_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_245_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_245_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_245_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_245_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_245_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_245_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_245_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_245_ADDRESS                                      (0x3d4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_245_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_245_RESET                                        0x0

// 0x3d8 (PHY_BB_DUMMY_SM_BCAST_246)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_246_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_246_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_246_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_246_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_246_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_246_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_246_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_246_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_246_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_246_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_246_ADDRESS                                      (0x3d8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_246_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_246_RESET                                        0x0

// 0x3dc (PHY_BB_DUMMY_SM_BCAST_247)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_247_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_247_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_247_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_247_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_247_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_247_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_247_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_247_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_247_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_247_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_247_ADDRESS                                      (0x3dc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_247_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_247_RESET                                        0x0

// 0x3e0 (PHY_BB_DUMMY_SM_BCAST_248)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_248_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_248_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_248_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_248_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_248_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_248_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_248_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_248_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_248_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_248_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_248_ADDRESS                                      (0x3e0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_248_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_248_RESET                                        0x0

// 0x3e4 (PHY_BB_DUMMY_SM_BCAST_249)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_249_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_249_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_249_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_249_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_249_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_249_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_249_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_249_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_249_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_249_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_249_ADDRESS                                      (0x3e4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_249_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_249_RESET                                        0x0

// 0x3e8 (PHY_BB_DUMMY_SM_BCAST_250)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_250_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_250_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_250_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_250_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_250_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_250_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_250_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_250_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_250_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_250_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_250_ADDRESS                                      (0x3e8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_250_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_250_RESET                                        0x0

// 0x3ec (PHY_BB_DUMMY_SM_BCAST_251)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_251_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_251_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_251_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_251_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_251_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_251_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_251_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_251_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_251_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_251_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_251_ADDRESS                                      (0x3ec + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_251_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_251_RESET                                        0x0

// 0x3f0 (PHY_BB_DUMMY_SM_BCAST_252)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_252_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_252_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_252_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_252_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_252_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_252_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_252_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_252_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_252_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_252_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_252_ADDRESS                                      (0x3f0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_252_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_252_RESET                                        0x0

// 0x3f4 (PHY_BB_DUMMY_SM_BCAST_253)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_253_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_253_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_253_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_253_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_253_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_253_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_253_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_253_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_253_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_253_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_253_ADDRESS                                      (0x3f4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_253_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_253_RESET                                        0x0

// 0x3f8 (PHY_BB_DUMMY_SM_BCAST_254)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_254_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_254_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_254_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_254_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_254_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_254_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_254_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_254_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_254_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_254_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_254_ADDRESS                                      (0x3f8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_254_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_254_RESET                                        0x0

// 0x3fc (PHY_BB_DUMMY_SM_BCAST_255)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_255_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_255_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_255_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_255_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_255_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_255_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_255_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_255_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_255_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_255_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_255_ADDRESS                                      (0x3fc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_255_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_255_RESET                                        0x0

// 0x400 (PHY_BB_DUMMY_SM_BCAST_256)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_256_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_256_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_256_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_256_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_256_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_256_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_256_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_256_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_256_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_256_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_256_ADDRESS                                      (0x400 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_256_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_256_RESET                                        0x0

// 0x404 (PHY_BB_DUMMY_SM_BCAST_257)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_257_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_257_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_257_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_257_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_257_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_257_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_257_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_257_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_257_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_257_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_257_ADDRESS                                      (0x404 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_257_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_257_RESET                                        0x0

// 0x408 (PHY_BB_DUMMY_SM_BCAST_258)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_258_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_258_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_258_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_258_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_258_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_258_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_258_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_258_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_258_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_258_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_258_ADDRESS                                      (0x408 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_258_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_258_RESET                                        0x0

// 0x40c (PHY_BB_DUMMY_SM_BCAST_259)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_259_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_259_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_259_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_259_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_259_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_259_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_259_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_259_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_259_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_259_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_259_ADDRESS                                      (0x40c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_259_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_259_RESET                                        0x0

// 0x410 (PHY_BB_DUMMY_SM_BCAST_260)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_260_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_260_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_260_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_260_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_260_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_260_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_260_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_260_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_260_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_260_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_260_ADDRESS                                      (0x410 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_260_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_260_RESET                                        0x0

// 0x414 (PHY_BB_DUMMY_SM_BCAST_261)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_261_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_261_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_261_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_261_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_261_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_261_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_261_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_261_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_261_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_261_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_261_ADDRESS                                      (0x414 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_261_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_261_RESET                                        0x0

// 0x418 (PHY_BB_DUMMY_SM_BCAST_262)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_262_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_262_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_262_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_262_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_262_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_262_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_262_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_262_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_262_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_262_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_262_ADDRESS                                      (0x418 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_262_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_262_RESET                                        0x0

// 0x41c (PHY_BB_DUMMY_SM_BCAST_263)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_263_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_263_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_263_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_263_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_263_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_263_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_263_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_263_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_263_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_263_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_263_ADDRESS                                      (0x41c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_263_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_263_RESET                                        0x0

// 0x420 (PHY_BB_DUMMY_SM_BCAST_264)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_264_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_264_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_264_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_264_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_264_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_264_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_264_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_264_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_264_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_264_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_264_ADDRESS                                      (0x420 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_264_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_264_RESET                                        0x0

// 0x424 (PHY_BB_DUMMY_SM_BCAST_265)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_265_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_265_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_265_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_265_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_265_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_265_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_265_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_265_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_265_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_265_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_265_ADDRESS                                      (0x424 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_265_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_265_RESET                                        0x0

// 0x428 (PHY_BB_DUMMY_SM_BCAST_266)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_266_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_266_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_266_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_266_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_266_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_266_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_266_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_266_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_266_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_266_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_266_ADDRESS                                      (0x428 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_266_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_266_RESET                                        0x0

// 0x42c (PHY_BB_DUMMY_SM_BCAST_267)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_267_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_267_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_267_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_267_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_267_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_267_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_267_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_267_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_267_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_267_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_267_ADDRESS                                      (0x42c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_267_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_267_RESET                                        0x0

// 0x430 (PHY_BB_DUMMY_SM_BCAST_268)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_268_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_268_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_268_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_268_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_268_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_268_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_268_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_268_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_268_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_268_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_268_ADDRESS                                      (0x430 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_268_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_268_RESET                                        0x0

// 0x434 (PHY_BB_DUMMY_SM_BCAST_269)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_269_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_269_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_269_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_269_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_269_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_269_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_269_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_269_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_269_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_269_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_269_ADDRESS                                      (0x434 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_269_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_269_RESET                                        0x0

// 0x438 (PHY_BB_DUMMY_SM_BCAST_270)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_270_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_270_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_270_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_270_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_270_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_270_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_270_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_270_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_270_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_270_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_270_ADDRESS                                      (0x438 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_270_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_270_RESET                                        0x0

// 0x43c (PHY_BB_DUMMY_SM_BCAST_271)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_271_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_271_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_271_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_271_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_271_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_271_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_271_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_271_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_271_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_271_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_271_ADDRESS                                      (0x43c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_271_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_271_RESET                                        0x0

// 0x440 (PHY_BB_DUMMY_SM_BCAST_272)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_272_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_272_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_272_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_272_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_272_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_272_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_272_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_272_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_272_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_272_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_272_ADDRESS                                      (0x440 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_272_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_272_RESET                                        0x0

// 0x444 (PHY_BB_DUMMY_SM_BCAST_273)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_273_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_273_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_273_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_273_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_273_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_273_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_273_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_273_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_273_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_273_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_273_ADDRESS                                      (0x444 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_273_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_273_RESET                                        0x0

// 0x448 (PHY_BB_DUMMY_SM_BCAST_274)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_274_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_274_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_274_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_274_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_274_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_274_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_274_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_274_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_274_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_274_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_274_ADDRESS                                      (0x448 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_274_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_274_RESET                                        0x0

// 0x44c (PHY_BB_DUMMY_SM_BCAST_275)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_275_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_275_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_275_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_275_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_275_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_275_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_275_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_275_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_275_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_275_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_275_ADDRESS                                      (0x44c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_275_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_275_RESET                                        0x0

// 0x450 (PHY_BB_DUMMY_SM_BCAST_276)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_276_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_276_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_276_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_276_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_276_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_276_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_276_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_276_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_276_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_276_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_276_ADDRESS                                      (0x450 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_276_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_276_RESET                                        0x0

// 0x454 (PHY_BB_DUMMY_SM_BCAST_277)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_277_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_277_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_277_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_277_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_277_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_277_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_277_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_277_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_277_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_277_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_277_ADDRESS                                      (0x454 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_277_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_277_RESET                                        0x0

// 0x458 (PHY_BB_DUMMY_SM_BCAST_278)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_278_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_278_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_278_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_278_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_278_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_278_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_278_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_278_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_278_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_278_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_278_ADDRESS                                      (0x458 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_278_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_278_RESET                                        0x0

// 0x45c (PHY_BB_DUMMY_SM_BCAST_279)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_279_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_279_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_279_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_279_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_279_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_279_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_279_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_279_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_279_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_279_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_279_ADDRESS                                      (0x45c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_279_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_279_RESET                                        0x0

// 0x460 (PHY_BB_DUMMY_SM_BCAST_280)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_280_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_280_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_280_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_280_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_280_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_280_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_280_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_280_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_280_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_280_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_280_ADDRESS                                      (0x460 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_280_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_280_RESET                                        0x0

// 0x464 (PHY_BB_DUMMY_SM_BCAST_281)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_281_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_281_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_281_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_281_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_281_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_281_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_281_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_281_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_281_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_281_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_281_ADDRESS                                      (0x464 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_281_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_281_RESET                                        0x0

// 0x468 (PHY_BB_DUMMY_SM_BCAST_282)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_282_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_282_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_282_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_282_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_282_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_282_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_282_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_282_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_282_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_282_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_282_ADDRESS                                      (0x468 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_282_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_282_RESET                                        0x0

// 0x46c (PHY_BB_DUMMY_SM_BCAST_283)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_283_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_283_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_283_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_283_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_283_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_283_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_283_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_283_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_283_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_283_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_283_ADDRESS                                      (0x46c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_283_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_283_RESET                                        0x0

// 0x470 (PHY_BB_DUMMY_SM_BCAST_284)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_284_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_284_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_284_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_284_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_284_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_284_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_284_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_284_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_284_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_284_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_284_ADDRESS                                      (0x470 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_284_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_284_RESET                                        0x0

// 0x474 (PHY_BB_DUMMY_SM_BCAST_285)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_285_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_285_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_285_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_285_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_285_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_285_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_285_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_285_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_285_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_285_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_285_ADDRESS                                      (0x474 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_285_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_285_RESET                                        0x0

// 0x478 (PHY_BB_DUMMY_SM_BCAST_286)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_286_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_286_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_286_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_286_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_286_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_286_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_286_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_286_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_286_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_286_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_286_ADDRESS                                      (0x478 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_286_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_286_RESET                                        0x0

// 0x47c (PHY_BB_DUMMY_SM_BCAST_287)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_287_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_287_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_287_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_287_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_287_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_287_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_287_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_287_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_287_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_287_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_287_ADDRESS                                      (0x47c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_287_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_287_RESET                                        0x0

// 0x480 (PHY_BB_DUMMY_SM_BCAST_288)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_288_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_288_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_288_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_288_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_288_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_288_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_288_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_288_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_288_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_288_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_288_ADDRESS                                      (0x480 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_288_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_288_RESET                                        0x0

// 0x484 (PHY_BB_DUMMY_SM_BCAST_289)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_289_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_289_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_289_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_289_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_289_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_289_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_289_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_289_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_289_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_289_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_289_ADDRESS                                      (0x484 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_289_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_289_RESET                                        0x0

// 0x488 (PHY_BB_DUMMY_SM_BCAST_290)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_290_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_290_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_290_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_290_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_290_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_290_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_290_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_290_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_290_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_290_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_290_ADDRESS                                      (0x488 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_290_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_290_RESET                                        0x0

// 0x48c (PHY_BB_DUMMY_SM_BCAST_291)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_291_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_291_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_291_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_291_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_291_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_291_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_291_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_291_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_291_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_291_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_291_ADDRESS                                      (0x48c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_291_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_291_RESET                                        0x0

// 0x490 (PHY_BB_DUMMY_SM_BCAST_292)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_292_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_292_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_292_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_292_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_292_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_292_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_292_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_292_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_292_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_292_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_292_ADDRESS                                      (0x490 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_292_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_292_RESET                                        0x0

// 0x494 (PHY_BB_DUMMY_SM_BCAST_293)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_293_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_293_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_293_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_293_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_293_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_293_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_293_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_293_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_293_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_293_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_293_ADDRESS                                      (0x494 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_293_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_293_RESET                                        0x0

// 0x498 (PHY_BB_DUMMY_SM_BCAST_294)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_294_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_294_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_294_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_294_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_294_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_294_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_294_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_294_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_294_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_294_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_294_ADDRESS                                      (0x498 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_294_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_294_RESET                                        0x0

// 0x49c (PHY_BB_DUMMY_SM_BCAST_295)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_295_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_295_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_295_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_295_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_295_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_295_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_295_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_295_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_295_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_295_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_295_ADDRESS                                      (0x49c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_295_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_295_RESET                                        0x0

// 0x4a0 (PHY_BB_DUMMY_SM_BCAST_296)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_296_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_296_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_296_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_296_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_296_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_296_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_296_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_296_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_296_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_296_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_296_ADDRESS                                      (0x4a0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_296_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_296_RESET                                        0x0

// 0x4a4 (PHY_BB_DUMMY_SM_BCAST_297)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_297_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_297_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_297_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_297_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_297_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_297_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_297_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_297_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_297_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_297_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_297_ADDRESS                                      (0x4a4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_297_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_297_RESET                                        0x0

// 0x4a8 (PHY_BB_DUMMY_SM_BCAST_298)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_298_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_298_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_298_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_298_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_298_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_298_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_298_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_298_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_298_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_298_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_298_ADDRESS                                      (0x4a8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_298_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_298_RESET                                        0x0

// 0x4ac (PHY_BB_DUMMY_SM_BCAST_299)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_299_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_299_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_299_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_299_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_299_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_299_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_299_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_299_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_299_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_299_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_299_ADDRESS                                      (0x4ac + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_299_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_299_RESET                                        0x0

// 0x4b0 (PHY_BB_DUMMY_SM_BCAST_300)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_300_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_300_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_300_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_300_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_300_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_300_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_300_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_300_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_300_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_300_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_300_ADDRESS                                      (0x4b0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_300_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_300_RESET                                        0x0

// 0x4b4 (PHY_BB_DUMMY_SM_BCAST_301)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_301_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_301_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_301_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_301_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_301_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_301_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_301_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_301_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_301_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_301_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_301_ADDRESS                                      (0x4b4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_301_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_301_RESET                                        0x0

// 0x4b8 (PHY_BB_DUMMY_SM_BCAST_302)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_302_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_302_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_302_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_302_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_302_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_302_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_302_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_302_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_302_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_302_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_302_ADDRESS                                      (0x4b8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_302_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_302_RESET                                        0x0

// 0x4bc (PHY_BB_DUMMY_SM_BCAST_303)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_303_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_303_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_303_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_303_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_303_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_303_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_303_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_303_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_303_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_303_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_303_ADDRESS                                      (0x4bc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_303_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_303_RESET                                        0x0

// 0x4c0 (PHY_BB_DUMMY_SM_BCAST_304)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_304_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_304_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_304_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_304_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_304_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_304_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_304_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_304_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_304_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_304_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_304_ADDRESS                                      (0x4c0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_304_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_304_RESET                                        0x0

// 0x4c4 (PHY_BB_DUMMY_SM_BCAST_305)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_305_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_305_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_305_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_305_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_305_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_305_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_305_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_305_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_305_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_305_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_305_ADDRESS                                      (0x4c4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_305_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_305_RESET                                        0x0

// 0x4c8 (PHY_BB_DUMMY_SM_BCAST_306)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_306_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_306_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_306_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_306_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_306_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_306_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_306_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_306_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_306_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_306_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_306_ADDRESS                                      (0x4c8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_306_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_306_RESET                                        0x0

// 0x4cc (PHY_BB_DUMMY_SM_BCAST_307)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_307_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_307_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_307_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_307_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_307_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_307_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_307_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_307_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_307_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_307_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_307_ADDRESS                                      (0x4cc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_307_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_307_RESET                                        0x0

// 0x4d0 (PHY_BB_DUMMY_SM_BCAST_308)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_308_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_308_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_308_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_308_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_308_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_308_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_308_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_308_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_308_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_308_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_308_ADDRESS                                      (0x4d0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_308_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_308_RESET                                        0x0

// 0x4d4 (PHY_BB_DUMMY_SM_BCAST_309)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_309_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_309_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_309_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_309_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_309_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_309_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_309_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_309_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_309_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_309_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_309_ADDRESS                                      (0x4d4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_309_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_309_RESET                                        0x0

// 0x4d8 (PHY_BB_DUMMY_SM_BCAST_310)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_310_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_310_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_310_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_310_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_310_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_310_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_310_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_310_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_310_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_310_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_310_ADDRESS                                      (0x4d8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_310_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_310_RESET                                        0x0

// 0x4dc (PHY_BB_DUMMY_SM_BCAST_311)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_311_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_311_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_311_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_311_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_311_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_311_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_311_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_311_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_311_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_311_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_311_ADDRESS                                      (0x4dc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_311_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_311_RESET                                        0x0

// 0x4e0 (PHY_BB_DUMMY_SM_BCAST_312)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_312_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_312_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_312_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_312_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_312_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_312_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_312_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_312_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_312_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_312_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_312_ADDRESS                                      (0x4e0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_312_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_312_RESET                                        0x0

// 0x4e4 (PHY_BB_DUMMY_SM_BCAST_313)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_313_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_313_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_313_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_313_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_313_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_313_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_313_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_313_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_313_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_313_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_313_ADDRESS                                      (0x4e4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_313_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_313_RESET                                        0x0

// 0x4e8 (PHY_BB_DUMMY_SM_BCAST_314)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_314_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_314_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_314_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_314_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_314_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_314_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_314_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_314_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_314_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_314_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_314_ADDRESS                                      (0x4e8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_314_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_314_RESET                                        0x0

// 0x4ec (PHY_BB_DUMMY_SM_BCAST_315)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_315_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_315_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_315_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_315_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_315_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_315_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_315_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_315_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_315_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_315_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_315_ADDRESS                                      (0x4ec + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_315_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_315_RESET                                        0x0

// 0x4f0 (PHY_BB_DUMMY_SM_BCAST_316)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_316_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_316_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_316_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_316_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_316_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_316_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_316_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_316_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_316_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_316_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_316_ADDRESS                                      (0x4f0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_316_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_316_RESET                                        0x0

// 0x4f4 (PHY_BB_DUMMY_SM_BCAST_317)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_317_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_317_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_317_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_317_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_317_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_317_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_317_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_317_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_317_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_317_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_317_ADDRESS                                      (0x4f4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_317_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_317_RESET                                        0x0

// 0x4f8 (PHY_BB_DUMMY_SM_BCAST_318)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_318_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_318_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_318_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_318_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_318_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_318_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_318_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_318_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_318_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_318_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_318_ADDRESS                                      (0x4f8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_318_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_318_RESET                                        0x0

// 0x4fc (PHY_BB_DUMMY_SM_BCAST_319)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_319_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_319_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_319_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_319_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_319_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_319_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_319_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_319_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_319_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_319_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_319_ADDRESS                                      (0x4fc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_319_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_319_RESET                                        0x0

// 0x500 (PHY_BB_DUMMY_SM_BCAST_320)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_320_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_320_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_320_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_320_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_320_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_320_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_320_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_320_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_320_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_320_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_320_ADDRESS                                      (0x500 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_320_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_320_RESET                                        0x0

// 0x504 (PHY_BB_DUMMY_SM_BCAST_321)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_321_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_321_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_321_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_321_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_321_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_321_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_321_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_321_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_321_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_321_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_321_ADDRESS                                      (0x504 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_321_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_321_RESET                                        0x0

// 0x508 (PHY_BB_DUMMY_SM_BCAST_322)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_322_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_322_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_322_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_322_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_322_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_322_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_322_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_322_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_322_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_322_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_322_ADDRESS                                      (0x508 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_322_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_322_RESET                                        0x0

// 0x50c (PHY_BB_DUMMY_SM_BCAST_323)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_323_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_323_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_323_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_323_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_323_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_323_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_323_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_323_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_323_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_323_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_323_ADDRESS                                      (0x50c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_323_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_323_RESET                                        0x0

// 0x510 (PHY_BB_DUMMY_SM_BCAST_324)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_324_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_324_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_324_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_324_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_324_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_324_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_324_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_324_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_324_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_324_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_324_ADDRESS                                      (0x510 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_324_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_324_RESET                                        0x0

// 0x514 (PHY_BB_DUMMY_SM_BCAST_325)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_325_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_325_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_325_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_325_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_325_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_325_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_325_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_325_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_325_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_325_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_325_ADDRESS                                      (0x514 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_325_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_325_RESET                                        0x0

// 0x518 (PHY_BB_DUMMY_SM_BCAST_326)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_326_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_326_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_326_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_326_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_326_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_326_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_326_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_326_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_326_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_326_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_326_ADDRESS                                      (0x518 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_326_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_326_RESET                                        0x0

// 0x51c (PHY_BB_DUMMY_SM_BCAST_327)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_327_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_327_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_327_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_327_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_327_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_327_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_327_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_327_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_327_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_327_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_327_ADDRESS                                      (0x51c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_327_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_327_RESET                                        0x0

// 0x520 (PHY_BB_DUMMY_SM_BCAST_328)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_328_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_328_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_328_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_328_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_328_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_328_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_328_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_328_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_328_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_328_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_328_ADDRESS                                      (0x520 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_328_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_328_RESET                                        0x0

// 0x524 (PHY_BB_DUMMY_SM_BCAST_329)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_329_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_329_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_329_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_329_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_329_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_329_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_329_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_329_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_329_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_329_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_329_ADDRESS                                      (0x524 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_329_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_329_RESET                                        0x0

// 0x528 (PHY_BB_DUMMY_SM_BCAST_330)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_330_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_330_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_330_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_330_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_330_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_330_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_330_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_330_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_330_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_330_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_330_ADDRESS                                      (0x528 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_330_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_330_RESET                                        0x0

// 0x52c (PHY_BB_DUMMY_SM_BCAST_331)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_331_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_331_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_331_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_331_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_331_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_331_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_331_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_331_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_331_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_331_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_331_ADDRESS                                      (0x52c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_331_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_331_RESET                                        0x0

// 0x530 (PHY_BB_DUMMY_SM_BCAST_332)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_332_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_332_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_332_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_332_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_332_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_332_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_332_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_332_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_332_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_332_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_332_ADDRESS                                      (0x530 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_332_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_332_RESET                                        0x0

// 0x534 (PHY_BB_DUMMY_SM_BCAST_333)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_333_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_333_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_333_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_333_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_333_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_333_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_333_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_333_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_333_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_333_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_333_ADDRESS                                      (0x534 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_333_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_333_RESET                                        0x0

// 0x538 (PHY_BB_DUMMY_SM_BCAST_334)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_334_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_334_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_334_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_334_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_334_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_334_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_334_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_334_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_334_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_334_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_334_ADDRESS                                      (0x538 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_334_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_334_RESET                                        0x0

// 0x53c (PHY_BB_DUMMY_SM_BCAST_335)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_335_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_335_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_335_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_335_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_335_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_335_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_335_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_335_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_335_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_335_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_335_ADDRESS                                      (0x53c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_335_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_335_RESET                                        0x0

// 0x540 (PHY_BB_DUMMY_SM_BCAST_336)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_336_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_336_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_336_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_336_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_336_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_336_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_336_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_336_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_336_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_336_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_336_ADDRESS                                      (0x540 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_336_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_336_RESET                                        0x0

// 0x544 (PHY_BB_DUMMY_SM_BCAST_337)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_337_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_337_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_337_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_337_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_337_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_337_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_337_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_337_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_337_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_337_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_337_ADDRESS                                      (0x544 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_337_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_337_RESET                                        0x0

// 0x548 (PHY_BB_DUMMY_SM_BCAST_338)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_338_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_338_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_338_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_338_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_338_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_338_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_338_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_338_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_338_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_338_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_338_ADDRESS                                      (0x548 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_338_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_338_RESET                                        0x0

// 0x54c (PHY_BB_DUMMY_SM_BCAST_339)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_339_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_339_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_339_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_339_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_339_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_339_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_339_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_339_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_339_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_339_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_339_ADDRESS                                      (0x54c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_339_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_339_RESET                                        0x0

// 0x550 (PHY_BB_DUMMY_SM_BCAST_340)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_340_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_340_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_340_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_340_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_340_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_340_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_340_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_340_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_340_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_340_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_340_ADDRESS                                      (0x550 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_340_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_340_RESET                                        0x0

// 0x554 (PHY_BB_DUMMY_SM_BCAST_341)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_341_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_341_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_341_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_341_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_341_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_341_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_341_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_341_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_341_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_341_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_341_ADDRESS                                      (0x554 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_341_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_341_RESET                                        0x0

// 0x558 (PHY_BB_DUMMY_SM_BCAST_342)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_342_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_342_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_342_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_342_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_342_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_342_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_342_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_342_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_342_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_342_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_342_ADDRESS                                      (0x558 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_342_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_342_RESET                                        0x0

// 0x55c (PHY_BB_DUMMY_SM_BCAST_343)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_343_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_343_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_343_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_343_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_343_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_343_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_343_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_343_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_343_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_343_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_343_ADDRESS                                      (0x55c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_343_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_343_RESET                                        0x0

// 0x560 (PHY_BB_DUMMY_SM_BCAST_344)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_344_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_344_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_344_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_344_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_344_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_344_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_344_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_344_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_344_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_344_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_344_ADDRESS                                      (0x560 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_344_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_344_RESET                                        0x0

// 0x564 (PHY_BB_DUMMY_SM_BCAST_345)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_345_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_345_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_345_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_345_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_345_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_345_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_345_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_345_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_345_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_345_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_345_ADDRESS                                      (0x564 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_345_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_345_RESET                                        0x0

// 0x568 (PHY_BB_DUMMY_SM_BCAST_346)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_346_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_346_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_346_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_346_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_346_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_346_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_346_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_346_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_346_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_346_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_346_ADDRESS                                      (0x568 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_346_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_346_RESET                                        0x0

// 0x56c (PHY_BB_DUMMY_SM_BCAST_347)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_347_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_347_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_347_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_347_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_347_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_347_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_347_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_347_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_347_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_347_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_347_ADDRESS                                      (0x56c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_347_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_347_RESET                                        0x0

// 0x570 (PHY_BB_DUMMY_SM_BCAST_348)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_348_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_348_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_348_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_348_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_348_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_348_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_348_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_348_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_348_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_348_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_348_ADDRESS                                      (0x570 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_348_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_348_RESET                                        0x0

// 0x574 (PHY_BB_DUMMY_SM_BCAST_349)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_349_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_349_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_349_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_349_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_349_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_349_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_349_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_349_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_349_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_349_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_349_ADDRESS                                      (0x574 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_349_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_349_RESET                                        0x0

// 0x578 (PHY_BB_DUMMY_SM_BCAST_350)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_350_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_350_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_350_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_350_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_350_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_350_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_350_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_350_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_350_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_350_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_350_ADDRESS                                      (0x578 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_350_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_350_RESET                                        0x0

// 0x57c (PHY_BB_DUMMY_SM_BCAST_351)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_351_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_351_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_351_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_351_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_351_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_351_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_351_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_351_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_351_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_351_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_351_ADDRESS                                      (0x57c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_351_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_351_RESET                                        0x0

// 0x580 (PHY_BB_DUMMY_SM_BCAST_352)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_352_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_352_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_352_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_352_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_352_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_352_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_352_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_352_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_352_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_352_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_352_ADDRESS                                      (0x580 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_352_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_352_RESET                                        0x0

// 0x584 (PHY_BB_DUMMY_SM_BCAST_353)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_353_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_353_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_353_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_353_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_353_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_353_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_353_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_353_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_353_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_353_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_353_ADDRESS                                      (0x584 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_353_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_353_RESET                                        0x0

// 0x588 (PHY_BB_DUMMY_SM_BCAST_354)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_354_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_354_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_354_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_354_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_354_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_354_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_354_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_354_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_354_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_354_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_354_ADDRESS                                      (0x588 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_354_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_354_RESET                                        0x0

// 0x58c (PHY_BB_DUMMY_SM_BCAST_355)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_355_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_355_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_355_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_355_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_355_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_355_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_355_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_355_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_355_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_355_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_355_ADDRESS                                      (0x58c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_355_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_355_RESET                                        0x0

// 0x590 (PHY_BB_DUMMY_SM_BCAST_356)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_356_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_356_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_356_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_356_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_356_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_356_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_356_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_356_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_356_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_356_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_356_ADDRESS                                      (0x590 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_356_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_356_RESET                                        0x0

// 0x594 (PHY_BB_DUMMY_SM_BCAST_357)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_357_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_357_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_357_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_357_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_357_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_357_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_357_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_357_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_357_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_357_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_357_ADDRESS                                      (0x594 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_357_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_357_RESET                                        0x0

// 0x598 (PHY_BB_DUMMY_SM_BCAST_358)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_358_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_358_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_358_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_358_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_358_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_358_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_358_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_358_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_358_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_358_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_358_ADDRESS                                      (0x598 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_358_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_358_RESET                                        0x0

// 0x59c (PHY_BB_DUMMY_SM_BCAST_359)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_359_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_359_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_359_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_359_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_359_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_359_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_359_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_359_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_359_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_359_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_359_ADDRESS                                      (0x59c + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_359_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_359_RESET                                        0x0

// 0x5a0 (PHY_BB_DUMMY_SM_BCAST_360)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_360_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_360_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_360_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_360_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_360_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_360_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_360_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_360_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_360_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_360_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_360_ADDRESS                                      (0x5a0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_360_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_360_RESET                                        0x0

// 0x5a4 (PHY_BB_DUMMY_SM_BCAST_361)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_361_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_361_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_361_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_361_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_361_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_361_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_361_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_361_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_361_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_361_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_361_ADDRESS                                      (0x5a4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_361_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_361_RESET                                        0x0

// 0x5a8 (PHY_BB_DUMMY_SM_BCAST_362)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_362_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_362_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_362_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_362_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_362_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_362_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_362_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_362_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_362_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_362_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_362_ADDRESS                                      (0x5a8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_362_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_362_RESET                                        0x0

// 0x5ac (PHY_BB_DUMMY_SM_BCAST_363)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_363_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_363_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_363_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_363_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_363_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_363_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_363_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_363_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_363_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_363_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_363_ADDRESS                                      (0x5ac + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_363_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_363_RESET                                        0x0

// 0x5b0 (PHY_BB_DUMMY_SM_BCAST_364)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_364_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_364_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_364_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_364_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_364_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_364_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_364_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_364_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_364_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_364_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_364_ADDRESS                                      (0x5b0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_364_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_364_RESET                                        0x0

// 0x5b4 (PHY_BB_DUMMY_SM_BCAST_365)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_365_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_365_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_365_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_365_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_365_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_365_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_365_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_365_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_365_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_365_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_365_ADDRESS                                      (0x5b4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_365_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_365_RESET                                        0x0

// 0x5b8 (PHY_BB_DUMMY_SM_BCAST_366)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_366_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_366_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_366_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_366_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_366_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_366_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_366_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_366_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_366_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_366_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_366_ADDRESS                                      (0x5b8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_366_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_366_RESET                                        0x0

// 0x5bc (PHY_BB_DUMMY_SM_BCAST_367)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_367_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_367_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_367_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_367_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_367_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_367_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_367_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_367_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_367_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_367_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_367_ADDRESS                                      (0x5bc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_367_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_367_RESET                                        0x0

// 0x5c0 (PHY_BB_DUMMY_SM_BCAST_368)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_368_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_368_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_368_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_368_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_368_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_368_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_368_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_368_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_368_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_368_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_368_ADDRESS                                      (0x5c0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_368_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_368_RESET                                        0x0

// 0x5c4 (PHY_BB_DUMMY_SM_BCAST_369)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_369_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_369_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_369_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_369_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_369_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_369_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_369_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_369_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_369_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_369_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_369_ADDRESS                                      (0x5c4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_369_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_369_RESET                                        0x0

// 0x5c8 (PHY_BB_DUMMY_SM_BCAST_370)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_370_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_370_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_370_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_370_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_370_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_370_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_370_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_370_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_370_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_370_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_370_ADDRESS                                      (0x5c8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_370_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_370_RESET                                        0x0

// 0x5cc (PHY_BB_DUMMY_SM_BCAST_371)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_371_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_371_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_371_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_371_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_371_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_371_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_371_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_371_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_371_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_371_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_371_ADDRESS                                      (0x5cc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_371_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_371_RESET                                        0x0

// 0x5d0 (PHY_BB_DUMMY_SM_BCAST_372)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_372_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_372_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_372_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_372_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_372_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_372_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_372_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_372_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_372_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_372_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_372_ADDRESS                                      (0x5d0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_372_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_372_RESET                                        0x0

// 0x5d4 (PHY_BB_DUMMY_SM_BCAST_373)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_373_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_373_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_373_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_373_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_373_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_373_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_373_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_373_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_373_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_373_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_373_ADDRESS                                      (0x5d4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_373_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_373_RESET                                        0x0

// 0x5d8 (PHY_BB_DUMMY_SM_BCAST_374)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_374_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_374_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_374_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_374_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_374_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_374_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_374_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_374_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_374_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_374_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_374_ADDRESS                                      (0x5d8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_374_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_374_RESET                                        0x0

// 0x5dc (PHY_BB_DUMMY_SM_BCAST_375)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_375_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_375_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_375_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_375_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_375_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_375_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_375_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_375_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_375_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_375_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_375_ADDRESS                                      (0x5dc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_375_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_375_RESET                                        0x0

// 0x5e0 (PHY_BB_DUMMY_SM_BCAST_376)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_376_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_376_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_376_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_376_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_376_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_376_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_376_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_376_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_376_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_376_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_376_ADDRESS                                      (0x5e0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_376_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_376_RESET                                        0x0

// 0x5e4 (PHY_BB_DUMMY_SM_BCAST_377)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_377_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_377_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_377_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_377_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_377_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_377_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_377_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_377_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_377_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_377_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_377_ADDRESS                                      (0x5e4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_377_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_377_RESET                                        0x0

// 0x5e8 (PHY_BB_DUMMY_SM_BCAST_378)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_378_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_378_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_378_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_378_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_378_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_378_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_378_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_378_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_378_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_378_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_378_ADDRESS                                      (0x5e8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_378_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_378_RESET                                        0x0

// 0x5ec (PHY_BB_DUMMY_SM_BCAST_379)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_379_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_379_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_379_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_379_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_379_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_379_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_379_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_379_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_379_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_379_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_379_ADDRESS                                      (0x5ec + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_379_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_379_RESET                                        0x0

// 0x5f0 (PHY_BB_DUMMY_SM_BCAST_380)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_380_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_380_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_380_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_380_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_380_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_380_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_380_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_380_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_380_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_380_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_380_ADDRESS                                      (0x5f0 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_380_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_380_RESET                                        0x0

// 0x5f4 (PHY_BB_DUMMY_SM_BCAST_381)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_381_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_381_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_381_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_381_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_381_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_381_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_381_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_381_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_381_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_381_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_381_ADDRESS                                      (0x5f4 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_381_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_381_RESET                                        0x0

// 0x5f8 (PHY_BB_DUMMY_SM_BCAST_382)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_382_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_382_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_382_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_382_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_382_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_382_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_382_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_382_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_382_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_382_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_382_ADDRESS                                      (0x5f8 + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_382_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_382_RESET                                        0x0

// 0x5fc (PHY_BB_DUMMY_SM_BCAST_383)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_383_LSB                                    0
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_383_MSB                                    31
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_383_MASK                                   0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_383_GET(x)                                 (((x) & PHY_BB_DUMMY_SM_BCAST_DUMMY_383_MASK) >> PHY_BB_DUMMY_SM_BCAST_DUMMY_383_LSB)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_383_SET(x)                                 (((0 | (x)) << PHY_BB_DUMMY_SM_BCAST_DUMMY_383_LSB) & PHY_BB_DUMMY_SM_BCAST_DUMMY_383_MASK)
#define PHY_BB_DUMMY_SM_BCAST_DUMMY_383_RESET                                  0x0
#define PHY_BB_DUMMY_SM_BCAST_383_ADDRESS                                      (0x5fc + __PHY_SM4_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DUMMY_SM_BCAST_383_RSTMASK                                      0xffffffff
#define PHY_BB_DUMMY_SM_BCAST_383_RESET                                        0x0



#endif /* _PHY_SM4_REG_MAP_H_ */
