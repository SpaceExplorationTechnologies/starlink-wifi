/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _CHN7_TXFE5GPA_REG_CSR_H_
#define _CHN7_TXFE5GPA_REG_CSR_H_


#ifndef __CHN7_TXFE5GPA_REG_CSR_BASE_ADDRESS
#define __CHN7_TXFE5GPA_REG_CSR_BASE_ADDRESS (0x47c40)
#endif


// 0x0 (CHN7_PA0)
#define CHN7_PA0_PA5_DRV_EN_OVR_LSB                                            30
#define CHN7_PA0_PA5_DRV_EN_OVR_MSB                                            31
#define CHN7_PA0_PA5_DRV_EN_OVR_MASK                                           0xc0000000
#define CHN7_PA0_PA5_DRV_EN_OVR_GET(x)                                         (((x) & CHN7_PA0_PA5_DRV_EN_OVR_MASK) >> CHN7_PA0_PA5_DRV_EN_OVR_LSB)
#define CHN7_PA0_PA5_DRV_EN_OVR_SET(x)                                         (((0 | (x)) << CHN7_PA0_PA5_DRV_EN_OVR_LSB) & CHN7_PA0_PA5_DRV_EN_OVR_MASK)
#define CHN7_PA0_PA5_DRV_EN_OVR_RESET                                          0x0
#define CHN7_PA0_PA5_OUT_EN_OVR_LSB                                            28
#define CHN7_PA0_PA5_OUT_EN_OVR_MSB                                            29
#define CHN7_PA0_PA5_OUT_EN_OVR_MASK                                           0x30000000
#define CHN7_PA0_PA5_OUT_EN_OVR_GET(x)                                         (((x) & CHN7_PA0_PA5_OUT_EN_OVR_MASK) >> CHN7_PA0_PA5_OUT_EN_OVR_LSB)
#define CHN7_PA0_PA5_OUT_EN_OVR_SET(x)                                         (((0 | (x)) << CHN7_PA0_PA5_OUT_EN_OVR_LSB) & CHN7_PA0_PA5_OUT_EN_OVR_MASK)
#define CHN7_PA0_PA5_OUT_EN_OVR_RESET                                          0x0
#define CHN7_PA0_PA5_ICGM_EN_OVR_LSB                                           26
#define CHN7_PA0_PA5_ICGM_EN_OVR_MSB                                           27
#define CHN7_PA0_PA5_ICGM_EN_OVR_MASK                                          0xc000000
#define CHN7_PA0_PA5_ICGM_EN_OVR_GET(x)                                        (((x) & CHN7_PA0_PA5_ICGM_EN_OVR_MASK) >> CHN7_PA0_PA5_ICGM_EN_OVR_LSB)
#define CHN7_PA0_PA5_ICGM_EN_OVR_SET(x)                                        (((0 | (x)) << CHN7_PA0_PA5_ICGM_EN_OVR_LSB) & CHN7_PA0_PA5_ICGM_EN_OVR_MASK)
#define CHN7_PA0_PA5_ICGM_EN_OVR_RESET                                         0x0
#define CHN7_PA0_PA5_DRV_MAIN_EN_LSB                                           25
#define CHN7_PA0_PA5_DRV_MAIN_EN_MSB                                           25
#define CHN7_PA0_PA5_DRV_MAIN_EN_MASK                                          0x2000000
#define CHN7_PA0_PA5_DRV_MAIN_EN_GET(x)                                        (((x) & CHN7_PA0_PA5_DRV_MAIN_EN_MASK) >> CHN7_PA0_PA5_DRV_MAIN_EN_LSB)
#define CHN7_PA0_PA5_DRV_MAIN_EN_SET(x)                                        (((0 | (x)) << CHN7_PA0_PA5_DRV_MAIN_EN_LSB) & CHN7_PA0_PA5_DRV_MAIN_EN_MASK)
#define CHN7_PA0_PA5_DRV_MAIN_EN_RESET                                         0x0
#define CHN7_PA0_PA5_DRV_AUX_EN_LSB                                            24
#define CHN7_PA0_PA5_DRV_AUX_EN_MSB                                            24
#define CHN7_PA0_PA5_DRV_AUX_EN_MASK                                           0x1000000
#define CHN7_PA0_PA5_DRV_AUX_EN_GET(x)                                         (((x) & CHN7_PA0_PA5_DRV_AUX_EN_MASK) >> CHN7_PA0_PA5_DRV_AUX_EN_LSB)
#define CHN7_PA0_PA5_DRV_AUX_EN_SET(x)                                         (((0 | (x)) << CHN7_PA0_PA5_DRV_AUX_EN_LSB) & CHN7_PA0_PA5_DRV_AUX_EN_MASK)
#define CHN7_PA0_PA5_DRV_AUX_EN_RESET                                          0x0
#define CHN7_PA0_PA5_OUT_MAIN_EN_LSB                                           23
#define CHN7_PA0_PA5_OUT_MAIN_EN_MSB                                           23
#define CHN7_PA0_PA5_OUT_MAIN_EN_MASK                                          0x800000
#define CHN7_PA0_PA5_OUT_MAIN_EN_GET(x)                                        (((x) & CHN7_PA0_PA5_OUT_MAIN_EN_MASK) >> CHN7_PA0_PA5_OUT_MAIN_EN_LSB)
#define CHN7_PA0_PA5_OUT_MAIN_EN_SET(x)                                        (((0 | (x)) << CHN7_PA0_PA5_OUT_MAIN_EN_LSB) & CHN7_PA0_PA5_OUT_MAIN_EN_MASK)
#define CHN7_PA0_PA5_OUT_MAIN_EN_RESET                                         0x0
#define CHN7_PA0_PA5_OUT_AUX1_EN_LSB                                           22
#define CHN7_PA0_PA5_OUT_AUX1_EN_MSB                                           22
#define CHN7_PA0_PA5_OUT_AUX1_EN_MASK                                          0x400000
#define CHN7_PA0_PA5_OUT_AUX1_EN_GET(x)                                        (((x) & CHN7_PA0_PA5_OUT_AUX1_EN_MASK) >> CHN7_PA0_PA5_OUT_AUX1_EN_LSB)
#define CHN7_PA0_PA5_OUT_AUX1_EN_SET(x)                                        (((0 | (x)) << CHN7_PA0_PA5_OUT_AUX1_EN_LSB) & CHN7_PA0_PA5_OUT_AUX1_EN_MASK)
#define CHN7_PA0_PA5_OUT_AUX1_EN_RESET                                         0x0
#define CHN7_PA0_PA5_OUT_AUX2_EN_LSB                                           21
#define CHN7_PA0_PA5_OUT_AUX2_EN_MSB                                           21
#define CHN7_PA0_PA5_OUT_AUX2_EN_MASK                                          0x200000
#define CHN7_PA0_PA5_OUT_AUX2_EN_GET(x)                                        (((x) & CHN7_PA0_PA5_OUT_AUX2_EN_MASK) >> CHN7_PA0_PA5_OUT_AUX2_EN_LSB)
#define CHN7_PA0_PA5_OUT_AUX2_EN_SET(x)                                        (((0 | (x)) << CHN7_PA0_PA5_OUT_AUX2_EN_LSB) & CHN7_PA0_PA5_OUT_AUX2_EN_MASK)
#define CHN7_PA0_PA5_OUT_AUX2_EN_RESET                                         0x0
#define CHN7_PA0_SENSE_VDD33_EN_LSB                                            20
#define CHN7_PA0_SENSE_VDD33_EN_MSB                                            20
#define CHN7_PA0_SENSE_VDD33_EN_MASK                                           0x100000
#define CHN7_PA0_SENSE_VDD33_EN_GET(x)                                         (((x) & CHN7_PA0_SENSE_VDD33_EN_MASK) >> CHN7_PA0_SENSE_VDD33_EN_LSB)
#define CHN7_PA0_SENSE_VDD33_EN_SET(x)                                         (((0 | (x)) << CHN7_PA0_SENSE_VDD33_EN_LSB) & CHN7_PA0_SENSE_VDD33_EN_MASK)
#define CHN7_PA0_SENSE_VDD33_EN_RESET                                          0x0
#define CHN7_PA0_RESERVED_0_LSB                                                0
#define CHN7_PA0_RESERVED_0_MSB                                                19
#define CHN7_PA0_RESERVED_0_MASK                                               0xfffff
#define CHN7_PA0_RESERVED_0_GET(x)                                             (((x) & CHN7_PA0_RESERVED_0_MASK) >> CHN7_PA0_RESERVED_0_LSB)
#define CHN7_PA0_RESERVED_0_SET(x)                                             (((0 | (x)) << CHN7_PA0_RESERVED_0_LSB) & CHN7_PA0_RESERVED_0_MASK)
#define CHN7_PA0_RESERVED_0_RESET                                              0x0
#define CHN7_PA0_ADDRESS                                                       (0x0 + __CHN7_TXFE5GPA_REG_CSR_BASE_ADDRESS)
#define CHN7_PA0_RSTMASK                                                       0xffffffff
#define CHN7_PA0_RESET                                                         0x0

// 0x4 (CHN7_PA1)
#define CHN7_PA1_USE_IPTAT_BIAS_LSB                                            31
#define CHN7_PA1_USE_IPTAT_BIAS_MSB                                            31
#define CHN7_PA1_USE_IPTAT_BIAS_MASK                                           0x80000000
#define CHN7_PA1_USE_IPTAT_BIAS_GET(x)                                         (((x) & CHN7_PA1_USE_IPTAT_BIAS_MASK) >> CHN7_PA1_USE_IPTAT_BIAS_LSB)
#define CHN7_PA1_USE_IPTAT_BIAS_SET(x)                                         (((0 | (x)) << CHN7_PA1_USE_IPTAT_BIAS_LSB) & CHN7_PA1_USE_IPTAT_BIAS_MASK)
#define CHN7_PA1_USE_IPTAT_BIAS_RESET                                          0x0
#define CHN7_PA1_PA5_ICGM_SLOPE_TUNE_LSB                                       28
#define CHN7_PA1_PA5_ICGM_SLOPE_TUNE_MSB                                       30
#define CHN7_PA1_PA5_ICGM_SLOPE_TUNE_MASK                                      0x70000000
#define CHN7_PA1_PA5_ICGM_SLOPE_TUNE_GET(x)                                    (((x) & CHN7_PA1_PA5_ICGM_SLOPE_TUNE_MASK) >> CHN7_PA1_PA5_ICGM_SLOPE_TUNE_LSB)
#define CHN7_PA1_PA5_ICGM_SLOPE_TUNE_SET(x)                                    (((0 | (x)) << CHN7_PA1_PA5_ICGM_SLOPE_TUNE_LSB) & CHN7_PA1_PA5_ICGM_SLOPE_TUNE_MASK)
#define CHN7_PA1_PA5_ICGM_SLOPE_TUNE_RESET                                     0x6
#define CHN7_PA1_PA5_ICGM_UP_TUNE_LSB                                          26
#define CHN7_PA1_PA5_ICGM_UP_TUNE_MSB                                          27
#define CHN7_PA1_PA5_ICGM_UP_TUNE_MASK                                         0xc000000
#define CHN7_PA1_PA5_ICGM_UP_TUNE_GET(x)                                       (((x) & CHN7_PA1_PA5_ICGM_UP_TUNE_MASK) >> CHN7_PA1_PA5_ICGM_UP_TUNE_LSB)
#define CHN7_PA1_PA5_ICGM_UP_TUNE_SET(x)                                       (((0 | (x)) << CHN7_PA1_PA5_ICGM_UP_TUNE_LSB) & CHN7_PA1_PA5_ICGM_UP_TUNE_MASK)
#define CHN7_PA1_PA5_ICGM_UP_TUNE_RESET                                        0x3
#define CHN7_PA1_PA5_ICGM_LOW_TUNE_LSB                                         24
#define CHN7_PA1_PA5_ICGM_LOW_TUNE_MSB                                         25
#define CHN7_PA1_PA5_ICGM_LOW_TUNE_MASK                                        0x3000000
#define CHN7_PA1_PA5_ICGM_LOW_TUNE_GET(x)                                      (((x) & CHN7_PA1_PA5_ICGM_LOW_TUNE_MASK) >> CHN7_PA1_PA5_ICGM_LOW_TUNE_LSB)
#define CHN7_PA1_PA5_ICGM_LOW_TUNE_SET(x)                                      (((0 | (x)) << CHN7_PA1_PA5_ICGM_LOW_TUNE_LSB) & CHN7_PA1_PA5_ICGM_LOW_TUNE_MASK)
#define CHN7_PA1_PA5_ICGM_LOW_TUNE_RESET                                       0x0
#define CHN7_PA1_PA5_ICGM_PA5_TUNE_LSB                                         20
#define CHN7_PA1_PA5_ICGM_PA5_TUNE_MSB                                         23
#define CHN7_PA1_PA5_ICGM_PA5_TUNE_MASK                                        0xf00000
#define CHN7_PA1_PA5_ICGM_PA5_TUNE_GET(x)                                      (((x) & CHN7_PA1_PA5_ICGM_PA5_TUNE_MASK) >> CHN7_PA1_PA5_ICGM_PA5_TUNE_LSB)
#define CHN7_PA1_PA5_ICGM_PA5_TUNE_SET(x)                                      (((0 | (x)) << CHN7_PA1_PA5_ICGM_PA5_TUNE_LSB) & CHN7_PA1_PA5_ICGM_PA5_TUNE_MASK)
#define CHN7_PA1_PA5_ICGM_PA5_TUNE_RESET                                       0xc
#define CHN7_PA1_UPPERLIM_EN_LSB                                               19
#define CHN7_PA1_UPPERLIM_EN_MSB                                               19
#define CHN7_PA1_UPPERLIM_EN_MASK                                              0x80000
#define CHN7_PA1_UPPERLIM_EN_GET(x)                                            (((x) & CHN7_PA1_UPPERLIM_EN_MASK) >> CHN7_PA1_UPPERLIM_EN_LSB)
#define CHN7_PA1_UPPERLIM_EN_SET(x)                                            (((0 | (x)) << CHN7_PA1_UPPERLIM_EN_LSB) & CHN7_PA1_UPPERLIM_EN_MASK)
#define CHN7_PA1_UPPERLIM_EN_RESET                                             0x0
#define CHN7_PA1_LOWERLIM_EN_LSB                                               18
#define CHN7_PA1_LOWERLIM_EN_MSB                                               18
#define CHN7_PA1_LOWERLIM_EN_MASK                                              0x40000
#define CHN7_PA1_LOWERLIM_EN_GET(x)                                            (((x) & CHN7_PA1_LOWERLIM_EN_MASK) >> CHN7_PA1_LOWERLIM_EN_LSB)
#define CHN7_PA1_LOWERLIM_EN_SET(x)                                            (((0 | (x)) << CHN7_PA1_LOWERLIM_EN_LSB) & CHN7_PA1_LOWERLIM_EN_MASK)
#define CHN7_PA1_LOWERLIM_EN_RESET                                             0x0
#define CHN7_PA1_RESERVED_0_LSB                                                16
#define CHN7_PA1_RESERVED_0_MSB                                                17
#define CHN7_PA1_RESERVED_0_MASK                                               0x30000
#define CHN7_PA1_RESERVED_0_GET(x)                                             (((x) & CHN7_PA1_RESERVED_0_MASK) >> CHN7_PA1_RESERVED_0_LSB)
#define CHN7_PA1_RESERVED_0_SET(x)                                             (((0 | (x)) << CHN7_PA1_RESERVED_0_LSB) & CHN7_PA1_RESERVED_0_MASK)
#define CHN7_PA1_RESERVED_0_RESET                                              0x0
#define CHN7_PA1_PA5_DRV_IBN_TUNE_LSB                                          10
#define CHN7_PA1_PA5_DRV_IBN_TUNE_MSB                                          15
#define CHN7_PA1_PA5_DRV_IBN_TUNE_MASK                                         0xfc00
#define CHN7_PA1_PA5_DRV_IBN_TUNE_GET(x)                                       (((x) & CHN7_PA1_PA5_DRV_IBN_TUNE_MASK) >> CHN7_PA1_PA5_DRV_IBN_TUNE_LSB)
#define CHN7_PA1_PA5_DRV_IBN_TUNE_SET(x)                                       (((0 | (x)) << CHN7_PA1_PA5_DRV_IBN_TUNE_LSB) & CHN7_PA1_PA5_DRV_IBN_TUNE_MASK)
#define CHN7_PA1_PA5_DRV_IBN_TUNE_RESET                                        0x32
#define CHN7_PA1_PA5_DRV_IB2_TUNE_LSB                                          5
#define CHN7_PA1_PA5_DRV_IB2_TUNE_MSB                                          9
#define CHN7_PA1_PA5_DRV_IB2_TUNE_MASK                                         0x3e0
#define CHN7_PA1_PA5_DRV_IB2_TUNE_GET(x)                                       (((x) & CHN7_PA1_PA5_DRV_IB2_TUNE_MASK) >> CHN7_PA1_PA5_DRV_IB2_TUNE_LSB)
#define CHN7_PA1_PA5_DRV_IB2_TUNE_SET(x)                                       (((0 | (x)) << CHN7_PA1_PA5_DRV_IB2_TUNE_LSB) & CHN7_PA1_PA5_DRV_IB2_TUNE_MASK)
#define CHN7_PA1_PA5_DRV_IB2_TUNE_RESET                                        0x6
#define CHN7_PA1_PA5_DRV_VCAS_LSB                                              2
#define CHN7_PA1_PA5_DRV_VCAS_MSB                                              4
#define CHN7_PA1_PA5_DRV_VCAS_MASK                                             0x1c
#define CHN7_PA1_PA5_DRV_VCAS_GET(x)                                           (((x) & CHN7_PA1_PA5_DRV_VCAS_MASK) >> CHN7_PA1_PA5_DRV_VCAS_LSB)
#define CHN7_PA1_PA5_DRV_VCAS_SET(x)                                           (((0 | (x)) << CHN7_PA1_PA5_DRV_VCAS_LSB) & CHN7_PA1_PA5_DRV_VCAS_MASK)
#define CHN7_PA1_PA5_DRV_VCAS_RESET                                            0x3
#define CHN7_PA1_PA5_DRV_VCAS_OFF_LEVEL_LSB                                    0
#define CHN7_PA1_PA5_DRV_VCAS_OFF_LEVEL_MSB                                    1
#define CHN7_PA1_PA5_DRV_VCAS_OFF_LEVEL_MASK                                   0x3
#define CHN7_PA1_PA5_DRV_VCAS_OFF_LEVEL_GET(x)                                 (((x) & CHN7_PA1_PA5_DRV_VCAS_OFF_LEVEL_MASK) >> CHN7_PA1_PA5_DRV_VCAS_OFF_LEVEL_LSB)
#define CHN7_PA1_PA5_DRV_VCAS_OFF_LEVEL_SET(x)                                 (((0 | (x)) << CHN7_PA1_PA5_DRV_VCAS_OFF_LEVEL_LSB) & CHN7_PA1_PA5_DRV_VCAS_OFF_LEVEL_MASK)
#define CHN7_PA1_PA5_DRV_VCAS_OFF_LEVEL_RESET                                  0x1
#define CHN7_PA1_ADDRESS                                                       (0x4 + __CHN7_TXFE5GPA_REG_CSR_BASE_ADDRESS)
#define CHN7_PA1_RSTMASK                                                       0xffffffff
#define CHN7_PA1_RESET                                                         0x6cc0c8cd

// 0x8 (CHN7_PA2)
#define CHN7_PA2_PA5_OUT_IBN_TUNE_LSB                                          26
#define CHN7_PA2_PA5_OUT_IBN_TUNE_MSB                                          31
#define CHN7_PA2_PA5_OUT_IBN_TUNE_MASK                                         0xfc000000
#define CHN7_PA2_PA5_OUT_IBN_TUNE_GET(x)                                       (((x) & CHN7_PA2_PA5_OUT_IBN_TUNE_MASK) >> CHN7_PA2_PA5_OUT_IBN_TUNE_LSB)
#define CHN7_PA2_PA5_OUT_IBN_TUNE_SET(x)                                       (((0 | (x)) << CHN7_PA2_PA5_OUT_IBN_TUNE_LSB) & CHN7_PA2_PA5_OUT_IBN_TUNE_MASK)
#define CHN7_PA2_PA5_OUT_IBN_TUNE_RESET                                        0x32
#define CHN7_PA2_PA5_OUT_IB2_TUNE_LSB                                          21
#define CHN7_PA2_PA5_OUT_IB2_TUNE_MSB                                          25
#define CHN7_PA2_PA5_OUT_IB2_TUNE_MASK                                         0x3e00000
#define CHN7_PA2_PA5_OUT_IB2_TUNE_GET(x)                                       (((x) & CHN7_PA2_PA5_OUT_IB2_TUNE_MASK) >> CHN7_PA2_PA5_OUT_IB2_TUNE_LSB)
#define CHN7_PA2_PA5_OUT_IB2_TUNE_SET(x)                                       (((0 | (x)) << CHN7_PA2_PA5_OUT_IB2_TUNE_LSB) & CHN7_PA2_PA5_OUT_IB2_TUNE_MASK)
#define CHN7_PA2_PA5_OUT_IB2_TUNE_RESET                                        0x4
#define CHN7_PA2_PA5_OUT_VCAS_LSB                                              18
#define CHN7_PA2_PA5_OUT_VCAS_MSB                                              20
#define CHN7_PA2_PA5_OUT_VCAS_MASK                                             0x1c0000
#define CHN7_PA2_PA5_OUT_VCAS_GET(x)                                           (((x) & CHN7_PA2_PA5_OUT_VCAS_MASK) >> CHN7_PA2_PA5_OUT_VCAS_LSB)
#define CHN7_PA2_PA5_OUT_VCAS_SET(x)                                           (((0 | (x)) << CHN7_PA2_PA5_OUT_VCAS_LSB) & CHN7_PA2_PA5_OUT_VCAS_MASK)
#define CHN7_PA2_PA5_OUT_VCAS_RESET                                            0x3
#define CHN7_PA2_PA5_OUT_VCAS_OFF_LEVEL_LSB                                    16
#define CHN7_PA2_PA5_OUT_VCAS_OFF_LEVEL_MSB                                    17
#define CHN7_PA2_PA5_OUT_VCAS_OFF_LEVEL_MASK                                   0x30000
#define CHN7_PA2_PA5_OUT_VCAS_OFF_LEVEL_GET(x)                                 (((x) & CHN7_PA2_PA5_OUT_VCAS_OFF_LEVEL_MASK) >> CHN7_PA2_PA5_OUT_VCAS_OFF_LEVEL_LSB)
#define CHN7_PA2_PA5_OUT_VCAS_OFF_LEVEL_SET(x)                                 (((0 | (x)) << CHN7_PA2_PA5_OUT_VCAS_OFF_LEVEL_LSB) & CHN7_PA2_PA5_OUT_VCAS_OFF_LEVEL_MASK)
#define CHN7_PA2_PA5_OUT_VCAS_OFF_LEVEL_RESET                                  0x1
#define CHN7_PA2_PA5_OUT_VCAS_SEL_LSB                                          15
#define CHN7_PA2_PA5_OUT_VCAS_SEL_MSB                                          15
#define CHN7_PA2_PA5_OUT_VCAS_SEL_MASK                                         0x8000
#define CHN7_PA2_PA5_OUT_VCAS_SEL_GET(x)                                       (((x) & CHN7_PA2_PA5_OUT_VCAS_SEL_MASK) >> CHN7_PA2_PA5_OUT_VCAS_SEL_LSB)
#define CHN7_PA2_PA5_OUT_VCAS_SEL_SET(x)                                       (((0 | (x)) << CHN7_PA2_PA5_OUT_VCAS_SEL_LSB) & CHN7_PA2_PA5_OUT_VCAS_SEL_MASK)
#define CHN7_PA2_PA5_OUT_VCAS_SEL_RESET                                        0x0
#define CHN7_PA2_PA5_OUT_AUX1_VOFFSET_LSB                                      12
#define CHN7_PA2_PA5_OUT_AUX1_VOFFSET_MSB                                      14
#define CHN7_PA2_PA5_OUT_AUX1_VOFFSET_MASK                                     0x7000
#define CHN7_PA2_PA5_OUT_AUX1_VOFFSET_GET(x)                                   (((x) & CHN7_PA2_PA5_OUT_AUX1_VOFFSET_MASK) >> CHN7_PA2_PA5_OUT_AUX1_VOFFSET_LSB)
#define CHN7_PA2_PA5_OUT_AUX1_VOFFSET_SET(x)                                   (((0 | (x)) << CHN7_PA2_PA5_OUT_AUX1_VOFFSET_LSB) & CHN7_PA2_PA5_OUT_AUX1_VOFFSET_MASK)
#define CHN7_PA2_PA5_OUT_AUX1_VOFFSET_RESET                                    0x3
#define CHN7_PA2_PA5_OUT_AUX2_VOFFSET_LSB                                      9
#define CHN7_PA2_PA5_OUT_AUX2_VOFFSET_MSB                                      11
#define CHN7_PA2_PA5_OUT_AUX2_VOFFSET_MASK                                     0xe00
#define CHN7_PA2_PA5_OUT_AUX2_VOFFSET_GET(x)                                   (((x) & CHN7_PA2_PA5_OUT_AUX2_VOFFSET_MASK) >> CHN7_PA2_PA5_OUT_AUX2_VOFFSET_LSB)
#define CHN7_PA2_PA5_OUT_AUX2_VOFFSET_SET(x)                                   (((0 | (x)) << CHN7_PA2_PA5_OUT_AUX2_VOFFSET_LSB) & CHN7_PA2_PA5_OUT_AUX2_VOFFSET_MASK)
#define CHN7_PA2_PA5_OUT_AUX2_VOFFSET_RESET                                    0x7
#define CHN7_PA2_RESERVED_0_LSB                                                0
#define CHN7_PA2_RESERVED_0_MSB                                                7
#define CHN7_PA2_RESERVED_0_MASK                                               0xff
#define CHN7_PA2_RESERVED_0_GET(x)                                             (((x) & CHN7_PA2_RESERVED_0_MASK) >> CHN7_PA2_RESERVED_0_LSB)
#define CHN7_PA2_RESERVED_0_SET(x)                                             (((0 | (x)) << CHN7_PA2_RESERVED_0_LSB) & CHN7_PA2_RESERVED_0_MASK)
#define CHN7_PA2_RESERVED_0_RESET                                              0x0
#define CHN7_PA2_ADDRESS                                                       (0x8 + __CHN7_TXFE5GPA_REG_CSR_BASE_ADDRESS)
#define CHN7_PA2_RSTMASK                                                       0xfffffeff
#define CHN7_PA2_RESET                                                         0xc88d3e00

// 0xc (CHN7_PA3)
#define CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_EN_LSB                                  31
#define CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_EN_MSB                                  31
#define CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_EN_MASK                                 0x80000000
#define CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_EN_GET(x)                               (((x) & CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_EN_MASK) >> CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_EN_LSB)
#define CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_EN_SET(x)                               (((0 | (x)) << CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_EN_LSB) & CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_EN_MASK)
#define CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_EN_RESET                                0x0
#define CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_VAL_LSB                                 28
#define CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_VAL_MSB                                 30
#define CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_VAL_MASK                                0x70000000
#define CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_VAL_GET(x)                              (((x) & CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_VAL_MASK) >> CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_VAL_LSB)
#define CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_VAL_SET(x)                              (((0 | (x)) << CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_VAL_LSB) & CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_VAL_MASK)
#define CHN7_PA3_PA5_DRV_CTUNE_SEL_OVR_VAL_RESET                               0x0
#define CHN7_PA3_PA5_DRV_CTUNE_0_LSB                                           24
#define CHN7_PA3_PA5_DRV_CTUNE_0_MSB                                           27
#define CHN7_PA3_PA5_DRV_CTUNE_0_MASK                                          0xf000000
#define CHN7_PA3_PA5_DRV_CTUNE_0_GET(x)                                        (((x) & CHN7_PA3_PA5_DRV_CTUNE_0_MASK) >> CHN7_PA3_PA5_DRV_CTUNE_0_LSB)
#define CHN7_PA3_PA5_DRV_CTUNE_0_SET(x)                                        (((0 | (x)) << CHN7_PA3_PA5_DRV_CTUNE_0_LSB) & CHN7_PA3_PA5_DRV_CTUNE_0_MASK)
#define CHN7_PA3_PA5_DRV_CTUNE_0_RESET                                         0xd
#define CHN7_PA3_PA5_DRV_CTUNE_1_LSB                                           20
#define CHN7_PA3_PA5_DRV_CTUNE_1_MSB                                           23
#define CHN7_PA3_PA5_DRV_CTUNE_1_MASK                                          0xf00000
#define CHN7_PA3_PA5_DRV_CTUNE_1_GET(x)                                        (((x) & CHN7_PA3_PA5_DRV_CTUNE_1_MASK) >> CHN7_PA3_PA5_DRV_CTUNE_1_LSB)
#define CHN7_PA3_PA5_DRV_CTUNE_1_SET(x)                                        (((0 | (x)) << CHN7_PA3_PA5_DRV_CTUNE_1_LSB) & CHN7_PA3_PA5_DRV_CTUNE_1_MASK)
#define CHN7_PA3_PA5_DRV_CTUNE_1_RESET                                         0xc
#define CHN7_PA3_PA5_DRV_CTUNE_2_LSB                                           16
#define CHN7_PA3_PA5_DRV_CTUNE_2_MSB                                           19
#define CHN7_PA3_PA5_DRV_CTUNE_2_MASK                                          0xf0000
#define CHN7_PA3_PA5_DRV_CTUNE_2_GET(x)                                        (((x) & CHN7_PA3_PA5_DRV_CTUNE_2_MASK) >> CHN7_PA3_PA5_DRV_CTUNE_2_LSB)
#define CHN7_PA3_PA5_DRV_CTUNE_2_SET(x)                                        (((0 | (x)) << CHN7_PA3_PA5_DRV_CTUNE_2_LSB) & CHN7_PA3_PA5_DRV_CTUNE_2_MASK)
#define CHN7_PA3_PA5_DRV_CTUNE_2_RESET                                         0xa
#define CHN7_PA3_PA5_DRV_CTUNE_3_LSB                                           12
#define CHN7_PA3_PA5_DRV_CTUNE_3_MSB                                           15
#define CHN7_PA3_PA5_DRV_CTUNE_3_MASK                                          0xf000
#define CHN7_PA3_PA5_DRV_CTUNE_3_GET(x)                                        (((x) & CHN7_PA3_PA5_DRV_CTUNE_3_MASK) >> CHN7_PA3_PA5_DRV_CTUNE_3_LSB)
#define CHN7_PA3_PA5_DRV_CTUNE_3_SET(x)                                        (((0 | (x)) << CHN7_PA3_PA5_DRV_CTUNE_3_LSB) & CHN7_PA3_PA5_DRV_CTUNE_3_MASK)
#define CHN7_PA3_PA5_DRV_CTUNE_3_RESET                                         0x8
#define CHN7_PA3_PA5_DRV_CTUNE_4_LSB                                           8
#define CHN7_PA3_PA5_DRV_CTUNE_4_MSB                                           11
#define CHN7_PA3_PA5_DRV_CTUNE_4_MASK                                          0xf00
#define CHN7_PA3_PA5_DRV_CTUNE_4_GET(x)                                        (((x) & CHN7_PA3_PA5_DRV_CTUNE_4_MASK) >> CHN7_PA3_PA5_DRV_CTUNE_4_LSB)
#define CHN7_PA3_PA5_DRV_CTUNE_4_SET(x)                                        (((0 | (x)) << CHN7_PA3_PA5_DRV_CTUNE_4_LSB) & CHN7_PA3_PA5_DRV_CTUNE_4_MASK)
#define CHN7_PA3_PA5_DRV_CTUNE_4_RESET                                         0x7
#define CHN7_PA3_PA5_DRV_CTUNE_5_LSB                                           4
#define CHN7_PA3_PA5_DRV_CTUNE_5_MSB                                           7
#define CHN7_PA3_PA5_DRV_CTUNE_5_MASK                                          0xf0
#define CHN7_PA3_PA5_DRV_CTUNE_5_GET(x)                                        (((x) & CHN7_PA3_PA5_DRV_CTUNE_5_MASK) >> CHN7_PA3_PA5_DRV_CTUNE_5_LSB)
#define CHN7_PA3_PA5_DRV_CTUNE_5_SET(x)                                        (((0 | (x)) << CHN7_PA3_PA5_DRV_CTUNE_5_LSB) & CHN7_PA3_PA5_DRV_CTUNE_5_MASK)
#define CHN7_PA3_PA5_DRV_CTUNE_5_RESET                                         0x5
#define CHN7_PA3_PA5_ATB_SEL_LSB                                               0
#define CHN7_PA3_PA5_ATB_SEL_MSB                                               3
#define CHN7_PA3_PA5_ATB_SEL_MASK                                              0xf
#define CHN7_PA3_PA5_ATB_SEL_GET(x)                                            (((x) & CHN7_PA3_PA5_ATB_SEL_MASK) >> CHN7_PA3_PA5_ATB_SEL_LSB)
#define CHN7_PA3_PA5_ATB_SEL_SET(x)                                            (((0 | (x)) << CHN7_PA3_PA5_ATB_SEL_LSB) & CHN7_PA3_PA5_ATB_SEL_MASK)
#define CHN7_PA3_PA5_ATB_SEL_RESET                                             0x0
#define CHN7_PA3_ADDRESS                                                       (0xc + __CHN7_TXFE5GPA_REG_CSR_BASE_ADDRESS)
#define CHN7_PA3_RSTMASK                                                       0xffffffff
#define CHN7_PA3_RESET                                                         0xdca8750

// 0x10 (CHN7_PA4)
#define CHN7_PA4_PA5_SPARE_LSB                                                 0
#define CHN7_PA4_PA5_SPARE_MSB                                                 31
#define CHN7_PA4_PA5_SPARE_MASK                                                0xffffffff
#define CHN7_PA4_PA5_SPARE_GET(x)                                              (((x) & CHN7_PA4_PA5_SPARE_MASK) >> CHN7_PA4_PA5_SPARE_LSB)
#define CHN7_PA4_PA5_SPARE_SET(x)                                              (((0 | (x)) << CHN7_PA4_PA5_SPARE_LSB) & CHN7_PA4_PA5_SPARE_MASK)
#define CHN7_PA4_PA5_SPARE_RESET                                               0x0
#define CHN7_PA4_ADDRESS                                                       (0x10 + __CHN7_TXFE5GPA_REG_CSR_BASE_ADDRESS)
#define CHN7_PA4_RSTMASK                                                       0xffffffff
#define CHN7_PA4_RESET                                                         0x0



#endif /* _CHN7_TXFE5GPA_REG_CSR_H_ */
