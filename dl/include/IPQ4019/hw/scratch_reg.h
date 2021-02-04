/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _SCRATCH_REG_H_
#define _SCRATCH_REG_H_


#ifndef __SCRATCH_REG_BASE_ADDRESS
#define __SCRATCH_REG_BASE_ADDRESS (0x4f000)
#endif


// 0x0 (WIFI_SCRATCH_0)
#define WIFI_SCRATCH_0_VAL_LSB                                                 0
#define WIFI_SCRATCH_0_VAL_MSB                                                 31
#define WIFI_SCRATCH_0_VAL_MASK                                                0xffffffff
#define WIFI_SCRATCH_0_VAL_GET(x)                                              (((x) & WIFI_SCRATCH_0_VAL_MASK) >> WIFI_SCRATCH_0_VAL_LSB)
#define WIFI_SCRATCH_0_VAL_SET(x)                                              (((0 | (x)) << WIFI_SCRATCH_0_VAL_LSB) & WIFI_SCRATCH_0_VAL_MASK)
#define WIFI_SCRATCH_0_VAL_RESET                                               0x0
#define WIFI_SCRATCH_0_ADDRESS                                                 (0x0 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_0_RSTMASK                                                 0xffffffff
#define WIFI_SCRATCH_0_RESET                                                   0x0

// 0x4 (WIFI_SCRATCH_1)
#define WIFI_SCRATCH_1_VAL_LSB                                                 0
#define WIFI_SCRATCH_1_VAL_MSB                                                 31
#define WIFI_SCRATCH_1_VAL_MASK                                                0xffffffff
#define WIFI_SCRATCH_1_VAL_GET(x)                                              (((x) & WIFI_SCRATCH_1_VAL_MASK) >> WIFI_SCRATCH_1_VAL_LSB)
#define WIFI_SCRATCH_1_VAL_SET(x)                                              (((0 | (x)) << WIFI_SCRATCH_1_VAL_LSB) & WIFI_SCRATCH_1_VAL_MASK)
#define WIFI_SCRATCH_1_VAL_RESET                                               0x0
#define WIFI_SCRATCH_1_ADDRESS                                                 (0x4 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_1_RSTMASK                                                 0xffffffff
#define WIFI_SCRATCH_1_RESET                                                   0x0

// 0x8 (WIFI_SCRATCH_2)
#define WIFI_SCRATCH_2_VAL_LSB                                                 0
#define WIFI_SCRATCH_2_VAL_MSB                                                 31
#define WIFI_SCRATCH_2_VAL_MASK                                                0xffffffff
#define WIFI_SCRATCH_2_VAL_GET(x)                                              (((x) & WIFI_SCRATCH_2_VAL_MASK) >> WIFI_SCRATCH_2_VAL_LSB)
#define WIFI_SCRATCH_2_VAL_SET(x)                                              (((0 | (x)) << WIFI_SCRATCH_2_VAL_LSB) & WIFI_SCRATCH_2_VAL_MASK)
#define WIFI_SCRATCH_2_VAL_RESET                                               0x0
#define WIFI_SCRATCH_2_ADDRESS                                                 (0x8 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_2_RSTMASK                                                 0xffffffff
#define WIFI_SCRATCH_2_RESET                                                   0x0

// 0xc (WIFI_SCRATCH_3)
#define WIFI_SCRATCH_3_VAL_LSB                                                 0
#define WIFI_SCRATCH_3_VAL_MSB                                                 31
#define WIFI_SCRATCH_3_VAL_MASK                                                0xffffffff
#define WIFI_SCRATCH_3_VAL_GET(x)                                              (((x) & WIFI_SCRATCH_3_VAL_MASK) >> WIFI_SCRATCH_3_VAL_LSB)
#define WIFI_SCRATCH_3_VAL_SET(x)                                              (((0 | (x)) << WIFI_SCRATCH_3_VAL_LSB) & WIFI_SCRATCH_3_VAL_MASK)
#define WIFI_SCRATCH_3_VAL_RESET                                               0x0
#define WIFI_SCRATCH_3_ADDRESS                                                 (0xc + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_3_RSTMASK                                                 0xffffffff
#define WIFI_SCRATCH_3_RESET                                                   0x0

// 0x10 (WIFI_SCRATCH_4)
#define WIFI_SCRATCH_4_VAL_LSB                                                 0
#define WIFI_SCRATCH_4_VAL_MSB                                                 31
#define WIFI_SCRATCH_4_VAL_MASK                                                0xffffffff
#define WIFI_SCRATCH_4_VAL_GET(x)                                              (((x) & WIFI_SCRATCH_4_VAL_MASK) >> WIFI_SCRATCH_4_VAL_LSB)
#define WIFI_SCRATCH_4_VAL_SET(x)                                              (((0 | (x)) << WIFI_SCRATCH_4_VAL_LSB) & WIFI_SCRATCH_4_VAL_MASK)
#define WIFI_SCRATCH_4_VAL_RESET                                               0x0
#define WIFI_SCRATCH_4_ADDRESS                                                 (0x10 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_4_RSTMASK                                                 0xffffffff
#define WIFI_SCRATCH_4_RESET                                                   0x0

// 0x14 (WIFI_SCRATCH_5)
#define WIFI_SCRATCH_5_VAL_LSB                                                 0
#define WIFI_SCRATCH_5_VAL_MSB                                                 31
#define WIFI_SCRATCH_5_VAL_MASK                                                0xffffffff
#define WIFI_SCRATCH_5_VAL_GET(x)                                              (((x) & WIFI_SCRATCH_5_VAL_MASK) >> WIFI_SCRATCH_5_VAL_LSB)
#define WIFI_SCRATCH_5_VAL_SET(x)                                              (((0 | (x)) << WIFI_SCRATCH_5_VAL_LSB) & WIFI_SCRATCH_5_VAL_MASK)
#define WIFI_SCRATCH_5_VAL_RESET                                               0x0
#define WIFI_SCRATCH_5_ADDRESS                                                 (0x14 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_5_RSTMASK                                                 0xffffffff
#define WIFI_SCRATCH_5_RESET                                                   0x0

// 0x18 (WIFI_SCRATCH_6)
#define WIFI_SCRATCH_6_VAL_LSB                                                 0
#define WIFI_SCRATCH_6_VAL_MSB                                                 31
#define WIFI_SCRATCH_6_VAL_MASK                                                0xffffffff
#define WIFI_SCRATCH_6_VAL_GET(x)                                              (((x) & WIFI_SCRATCH_6_VAL_MASK) >> WIFI_SCRATCH_6_VAL_LSB)
#define WIFI_SCRATCH_6_VAL_SET(x)                                              (((0 | (x)) << WIFI_SCRATCH_6_VAL_LSB) & WIFI_SCRATCH_6_VAL_MASK)
#define WIFI_SCRATCH_6_VAL_RESET                                               0x0
#define WIFI_SCRATCH_6_ADDRESS                                                 (0x18 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_6_RSTMASK                                                 0xffffffff
#define WIFI_SCRATCH_6_RESET                                                   0x0

// 0x1c (WIFI_SCRATCH_7)
#define WIFI_SCRATCH_7_VAL_LSB                                                 0
#define WIFI_SCRATCH_7_VAL_MSB                                                 31
#define WIFI_SCRATCH_7_VAL_MASK                                                0xffffffff
#define WIFI_SCRATCH_7_VAL_GET(x)                                              (((x) & WIFI_SCRATCH_7_VAL_MASK) >> WIFI_SCRATCH_7_VAL_LSB)
#define WIFI_SCRATCH_7_VAL_SET(x)                                              (((0 | (x)) << WIFI_SCRATCH_7_VAL_LSB) & WIFI_SCRATCH_7_VAL_MASK)
#define WIFI_SCRATCH_7_VAL_RESET                                               0x0
#define WIFI_SCRATCH_7_ADDRESS                                                 (0x1c + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_7_RSTMASK                                                 0xffffffff
#define WIFI_SCRATCH_7_RESET                                                   0x0

// 0x20 (WIFI_SCRATCH_8)
#define WIFI_SCRATCH_8_VAL_LSB                                                 0
#define WIFI_SCRATCH_8_VAL_MSB                                                 31
#define WIFI_SCRATCH_8_VAL_MASK                                                0xffffffff
#define WIFI_SCRATCH_8_VAL_GET(x)                                              (((x) & WIFI_SCRATCH_8_VAL_MASK) >> WIFI_SCRATCH_8_VAL_LSB)
#define WIFI_SCRATCH_8_VAL_SET(x)                                              (((0 | (x)) << WIFI_SCRATCH_8_VAL_LSB) & WIFI_SCRATCH_8_VAL_MASK)
#define WIFI_SCRATCH_8_VAL_RESET                                               0x0
#define WIFI_SCRATCH_8_ADDRESS                                                 (0x20 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_8_RSTMASK                                                 0xffffffff
#define WIFI_SCRATCH_8_RESET                                                   0x0

// 0x24 (WIFI_SCRATCH_9)
#define WIFI_SCRATCH_9_VAL_LSB                                                 0
#define WIFI_SCRATCH_9_VAL_MSB                                                 31
#define WIFI_SCRATCH_9_VAL_MASK                                                0xffffffff
#define WIFI_SCRATCH_9_VAL_GET(x)                                              (((x) & WIFI_SCRATCH_9_VAL_MASK) >> WIFI_SCRATCH_9_VAL_LSB)
#define WIFI_SCRATCH_9_VAL_SET(x)                                              (((0 | (x)) << WIFI_SCRATCH_9_VAL_LSB) & WIFI_SCRATCH_9_VAL_MASK)
#define WIFI_SCRATCH_9_VAL_RESET                                               0x0
#define WIFI_SCRATCH_9_ADDRESS                                                 (0x24 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_9_RSTMASK                                                 0xffffffff
#define WIFI_SCRATCH_9_RESET                                                   0x0

// 0x28 (WIFI_SCRATCH_10)
#define WIFI_SCRATCH_10_VAL_LSB                                                0
#define WIFI_SCRATCH_10_VAL_MSB                                                31
#define WIFI_SCRATCH_10_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_10_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_10_VAL_MASK) >> WIFI_SCRATCH_10_VAL_LSB)
#define WIFI_SCRATCH_10_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_10_VAL_LSB) & WIFI_SCRATCH_10_VAL_MASK)
#define WIFI_SCRATCH_10_VAL_RESET                                              0x0
#define WIFI_SCRATCH_10_ADDRESS                                                (0x28 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_10_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_10_RESET                                                  0x0

// 0x2c (WIFI_SCRATCH_11)
#define WIFI_SCRATCH_11_VAL_LSB                                                0
#define WIFI_SCRATCH_11_VAL_MSB                                                31
#define WIFI_SCRATCH_11_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_11_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_11_VAL_MASK) >> WIFI_SCRATCH_11_VAL_LSB)
#define WIFI_SCRATCH_11_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_11_VAL_LSB) & WIFI_SCRATCH_11_VAL_MASK)
#define WIFI_SCRATCH_11_VAL_RESET                                              0x0
#define WIFI_SCRATCH_11_ADDRESS                                                (0x2c + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_11_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_11_RESET                                                  0x0

// 0x30 (WIFI_SCRATCH_12)
#define WIFI_SCRATCH_12_VAL_LSB                                                0
#define WIFI_SCRATCH_12_VAL_MSB                                                31
#define WIFI_SCRATCH_12_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_12_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_12_VAL_MASK) >> WIFI_SCRATCH_12_VAL_LSB)
#define WIFI_SCRATCH_12_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_12_VAL_LSB) & WIFI_SCRATCH_12_VAL_MASK)
#define WIFI_SCRATCH_12_VAL_RESET                                              0x0
#define WIFI_SCRATCH_12_ADDRESS                                                (0x30 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_12_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_12_RESET                                                  0x0

// 0x34 (WIFI_SCRATCH_13)
#define WIFI_SCRATCH_13_VAL_LSB                                                0
#define WIFI_SCRATCH_13_VAL_MSB                                                31
#define WIFI_SCRATCH_13_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_13_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_13_VAL_MASK) >> WIFI_SCRATCH_13_VAL_LSB)
#define WIFI_SCRATCH_13_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_13_VAL_LSB) & WIFI_SCRATCH_13_VAL_MASK)
#define WIFI_SCRATCH_13_VAL_RESET                                              0x0
#define WIFI_SCRATCH_13_ADDRESS                                                (0x34 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_13_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_13_RESET                                                  0x0

// 0x38 (WIFI_SCRATCH_14)
#define WIFI_SCRATCH_14_VAL_LSB                                                0
#define WIFI_SCRATCH_14_VAL_MSB                                                31
#define WIFI_SCRATCH_14_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_14_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_14_VAL_MASK) >> WIFI_SCRATCH_14_VAL_LSB)
#define WIFI_SCRATCH_14_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_14_VAL_LSB) & WIFI_SCRATCH_14_VAL_MASK)
#define WIFI_SCRATCH_14_VAL_RESET                                              0x0
#define WIFI_SCRATCH_14_ADDRESS                                                (0x38 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_14_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_14_RESET                                                  0x0

// 0x3c (WIFI_SCRATCH_15)
#define WIFI_SCRATCH_15_VAL_LSB                                                0
#define WIFI_SCRATCH_15_VAL_MSB                                                31
#define WIFI_SCRATCH_15_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_15_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_15_VAL_MASK) >> WIFI_SCRATCH_15_VAL_LSB)
#define WIFI_SCRATCH_15_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_15_VAL_LSB) & WIFI_SCRATCH_15_VAL_MASK)
#define WIFI_SCRATCH_15_VAL_RESET                                              0x0
#define WIFI_SCRATCH_15_ADDRESS                                                (0x3c + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_15_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_15_RESET                                                  0x0

// 0x40 (WIFI_SCRATCH_16)
#define WIFI_SCRATCH_16_VAL_LSB                                                0
#define WIFI_SCRATCH_16_VAL_MSB                                                31
#define WIFI_SCRATCH_16_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_16_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_16_VAL_MASK) >> WIFI_SCRATCH_16_VAL_LSB)
#define WIFI_SCRATCH_16_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_16_VAL_LSB) & WIFI_SCRATCH_16_VAL_MASK)
#define WIFI_SCRATCH_16_VAL_RESET                                              0x0
#define WIFI_SCRATCH_16_ADDRESS                                                (0x40 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_16_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_16_RESET                                                  0x0

// 0x44 (WIFI_SCRATCH_17)
#define WIFI_SCRATCH_17_VAL_LSB                                                0
#define WIFI_SCRATCH_17_VAL_MSB                                                31
#define WIFI_SCRATCH_17_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_17_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_17_VAL_MASK) >> WIFI_SCRATCH_17_VAL_LSB)
#define WIFI_SCRATCH_17_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_17_VAL_LSB) & WIFI_SCRATCH_17_VAL_MASK)
#define WIFI_SCRATCH_17_VAL_RESET                                              0x0
#define WIFI_SCRATCH_17_ADDRESS                                                (0x44 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_17_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_17_RESET                                                  0x0

// 0x48 (WIFI_SCRATCH_18)
#define WIFI_SCRATCH_18_VAL_LSB                                                0
#define WIFI_SCRATCH_18_VAL_MSB                                                31
#define WIFI_SCRATCH_18_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_18_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_18_VAL_MASK) >> WIFI_SCRATCH_18_VAL_LSB)
#define WIFI_SCRATCH_18_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_18_VAL_LSB) & WIFI_SCRATCH_18_VAL_MASK)
#define WIFI_SCRATCH_18_VAL_RESET                                              0x0
#define WIFI_SCRATCH_18_ADDRESS                                                (0x48 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_18_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_18_RESET                                                  0x0

// 0x4c (WIFI_SCRATCH_19)
#define WIFI_SCRATCH_19_VAL_LSB                                                0
#define WIFI_SCRATCH_19_VAL_MSB                                                31
#define WIFI_SCRATCH_19_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_19_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_19_VAL_MASK) >> WIFI_SCRATCH_19_VAL_LSB)
#define WIFI_SCRATCH_19_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_19_VAL_LSB) & WIFI_SCRATCH_19_VAL_MASK)
#define WIFI_SCRATCH_19_VAL_RESET                                              0x0
#define WIFI_SCRATCH_19_ADDRESS                                                (0x4c + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_19_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_19_RESET                                                  0x0

// 0x50 (WIFI_SCRATCH_20)
#define WIFI_SCRATCH_20_VAL_LSB                                                0
#define WIFI_SCRATCH_20_VAL_MSB                                                31
#define WIFI_SCRATCH_20_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_20_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_20_VAL_MASK) >> WIFI_SCRATCH_20_VAL_LSB)
#define WIFI_SCRATCH_20_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_20_VAL_LSB) & WIFI_SCRATCH_20_VAL_MASK)
#define WIFI_SCRATCH_20_VAL_RESET                                              0x0
#define WIFI_SCRATCH_20_ADDRESS                                                (0x50 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_20_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_20_RESET                                                  0x0

// 0x54 (WIFI_SCRATCH_21)
#define WIFI_SCRATCH_21_VAL_LSB                                                0
#define WIFI_SCRATCH_21_VAL_MSB                                                31
#define WIFI_SCRATCH_21_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_21_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_21_VAL_MASK) >> WIFI_SCRATCH_21_VAL_LSB)
#define WIFI_SCRATCH_21_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_21_VAL_LSB) & WIFI_SCRATCH_21_VAL_MASK)
#define WIFI_SCRATCH_21_VAL_RESET                                              0x0
#define WIFI_SCRATCH_21_ADDRESS                                                (0x54 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_21_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_21_RESET                                                  0x0

// 0x58 (WIFI_SCRATCH_22)
#define WIFI_SCRATCH_22_VAL_LSB                                                0
#define WIFI_SCRATCH_22_VAL_MSB                                                31
#define WIFI_SCRATCH_22_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_22_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_22_VAL_MASK) >> WIFI_SCRATCH_22_VAL_LSB)
#define WIFI_SCRATCH_22_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_22_VAL_LSB) & WIFI_SCRATCH_22_VAL_MASK)
#define WIFI_SCRATCH_22_VAL_RESET                                              0x0
#define WIFI_SCRATCH_22_ADDRESS                                                (0x58 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_22_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_22_RESET                                                  0x0

// 0x5c (WIFI_SCRATCH_23)
#define WIFI_SCRATCH_23_VAL_LSB                                                0
#define WIFI_SCRATCH_23_VAL_MSB                                                31
#define WIFI_SCRATCH_23_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_23_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_23_VAL_MASK) >> WIFI_SCRATCH_23_VAL_LSB)
#define WIFI_SCRATCH_23_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_23_VAL_LSB) & WIFI_SCRATCH_23_VAL_MASK)
#define WIFI_SCRATCH_23_VAL_RESET                                              0x0
#define WIFI_SCRATCH_23_ADDRESS                                                (0x5c + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_23_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_23_RESET                                                  0x0

// 0x60 (WIFI_SCRATCH_24)
#define WIFI_SCRATCH_24_VAL_LSB                                                0
#define WIFI_SCRATCH_24_VAL_MSB                                                31
#define WIFI_SCRATCH_24_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_24_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_24_VAL_MASK) >> WIFI_SCRATCH_24_VAL_LSB)
#define WIFI_SCRATCH_24_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_24_VAL_LSB) & WIFI_SCRATCH_24_VAL_MASK)
#define WIFI_SCRATCH_24_VAL_RESET                                              0x0
#define WIFI_SCRATCH_24_ADDRESS                                                (0x60 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_24_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_24_RESET                                                  0x0

// 0x64 (WIFI_SCRATCH_25)
#define WIFI_SCRATCH_25_VAL_LSB                                                0
#define WIFI_SCRATCH_25_VAL_MSB                                                31
#define WIFI_SCRATCH_25_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_25_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_25_VAL_MASK) >> WIFI_SCRATCH_25_VAL_LSB)
#define WIFI_SCRATCH_25_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_25_VAL_LSB) & WIFI_SCRATCH_25_VAL_MASK)
#define WIFI_SCRATCH_25_VAL_RESET                                              0x0
#define WIFI_SCRATCH_25_ADDRESS                                                (0x64 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_25_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_25_RESET                                                  0x0

// 0x68 (WIFI_SCRATCH_26)
#define WIFI_SCRATCH_26_VAL_LSB                                                0
#define WIFI_SCRATCH_26_VAL_MSB                                                31
#define WIFI_SCRATCH_26_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_26_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_26_VAL_MASK) >> WIFI_SCRATCH_26_VAL_LSB)
#define WIFI_SCRATCH_26_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_26_VAL_LSB) & WIFI_SCRATCH_26_VAL_MASK)
#define WIFI_SCRATCH_26_VAL_RESET                                              0x0
#define WIFI_SCRATCH_26_ADDRESS                                                (0x68 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_26_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_26_RESET                                                  0x0

// 0x6c (WIFI_SCRATCH_27)
#define WIFI_SCRATCH_27_VAL_LSB                                                0
#define WIFI_SCRATCH_27_VAL_MSB                                                31
#define WIFI_SCRATCH_27_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_27_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_27_VAL_MASK) >> WIFI_SCRATCH_27_VAL_LSB)
#define WIFI_SCRATCH_27_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_27_VAL_LSB) & WIFI_SCRATCH_27_VAL_MASK)
#define WIFI_SCRATCH_27_VAL_RESET                                              0x0
#define WIFI_SCRATCH_27_ADDRESS                                                (0x6c + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_27_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_27_RESET                                                  0x0

// 0x70 (WIFI_SCRATCH_28)
#define WIFI_SCRATCH_28_VAL_LSB                                                0
#define WIFI_SCRATCH_28_VAL_MSB                                                31
#define WIFI_SCRATCH_28_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_28_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_28_VAL_MASK) >> WIFI_SCRATCH_28_VAL_LSB)
#define WIFI_SCRATCH_28_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_28_VAL_LSB) & WIFI_SCRATCH_28_VAL_MASK)
#define WIFI_SCRATCH_28_VAL_RESET                                              0x0
#define WIFI_SCRATCH_28_ADDRESS                                                (0x70 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_28_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_28_RESET                                                  0x0

// 0x74 (WIFI_SCRATCH_29)
#define WIFI_SCRATCH_29_VAL_LSB                                                0
#define WIFI_SCRATCH_29_VAL_MSB                                                31
#define WIFI_SCRATCH_29_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_29_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_29_VAL_MASK) >> WIFI_SCRATCH_29_VAL_LSB)
#define WIFI_SCRATCH_29_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_29_VAL_LSB) & WIFI_SCRATCH_29_VAL_MASK)
#define WIFI_SCRATCH_29_VAL_RESET                                              0x0
#define WIFI_SCRATCH_29_ADDRESS                                                (0x74 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_29_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_29_RESET                                                  0x0

// 0x78 (WIFI_SCRATCH_30)
#define WIFI_SCRATCH_30_VAL_LSB                                                0
#define WIFI_SCRATCH_30_VAL_MSB                                                31
#define WIFI_SCRATCH_30_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_30_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_30_VAL_MASK) >> WIFI_SCRATCH_30_VAL_LSB)
#define WIFI_SCRATCH_30_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_30_VAL_LSB) & WIFI_SCRATCH_30_VAL_MASK)
#define WIFI_SCRATCH_30_VAL_RESET                                              0x0
#define WIFI_SCRATCH_30_ADDRESS                                                (0x78 + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_30_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_30_RESET                                                  0x0

// 0x7c (WIFI_SCRATCH_31)
#define WIFI_SCRATCH_31_VAL_LSB                                                0
#define WIFI_SCRATCH_31_VAL_MSB                                                31
#define WIFI_SCRATCH_31_VAL_MASK                                               0xffffffff
#define WIFI_SCRATCH_31_VAL_GET(x)                                             (((x) & WIFI_SCRATCH_31_VAL_MASK) >> WIFI_SCRATCH_31_VAL_LSB)
#define WIFI_SCRATCH_31_VAL_SET(x)                                             (((0 | (x)) << WIFI_SCRATCH_31_VAL_LSB) & WIFI_SCRATCH_31_VAL_MASK)
#define WIFI_SCRATCH_31_VAL_RESET                                              0x0
#define WIFI_SCRATCH_31_ADDRESS                                                (0x7c + __SCRATCH_REG_BASE_ADDRESS)
#define WIFI_SCRATCH_31_RSTMASK                                                0xffffffff
#define WIFI_SCRATCH_31_RESET                                                  0x0



#endif /* _SCRATCH_REG_H_ */
