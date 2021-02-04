/*
 *  * Copyright (c) 2014, 2016-2017 Qualcomm Atheros, Inc.
 *  * All Rights Reserved.
 *  * Qualcomm Atheros Confidential and Proprietary.
 *  * $ATH_LICENSE_TARGET_C$
 *  *
*/

#include "osapi.h"

#define txd_gpio                                                     8
#define rxd_gpio                                                     9
#define TLMM_BASE                                                    0x01000000
#define TLMM_BASE_INOUT                                              0x01000004
#define TLMM_CSR_REG_BASE                                           (TLMM_BASE      + 0x00000000)
#define TLMM_IN_OUT_REG_BASE                                        (TLMM_BASE_INOUT + 0x00000000)
#define HWIO_TLMM_GPIO_CFGn_ADDR(n)                                 (TLMM_CSR_REG_BASE      + 0x00000000 + 0x1000 * (n))
#define HWIO_TLMM_GPIO_CFGn_GPIO_OE_SHFT                             0x9
#define HWIO_TLMM_GPIO_CFGn_DRV_STRENGTH_SHFT                        0x6
#define HWIO_TLMM_GPIO_CFGn_FUNC_SEL_SHFT                            0x2
#define HWIO_TLMM_GPIO_CFGn_GPIO_PULL_SHFT                           0x0
#define HWIO_TLMM_GPIO_INOUTn_ADDR(n)                               (TLMM_IN_OUT_REG_BASE   + 0x00000000 + 0x1000 * (n))
#define HWIO_TLMM_GPIO_OUT_SHFT                                      0x1
#define HWIO_TLMM_GPIO_IN_SHFT                                       0x0

/**
 *  * @brief   Pull values for GPIO.
 *   */
typedef enum GpioPullValues
{
     GPIO_PULL_NONE,
     GPIO_PULL_DOWN,
     GPIO_PULL_UP,
     GPIO_PULL_KEEPER,
} GpioPullValues;

/**
 *  * @brief   Drive strength values for GPIO.
 *   */
typedef enum GpioDriveSrength
{
     GPIO_DRV_STR_2_mA,
     GPIO_DRV_STR_4_mA,
     GPIO_DRV_STR_6_mA,
     GPIO_DRV_STR_8_mA,
     GPIO_DRV_STR_10_mA,
     GPIO_DRV_STR_12_mA,
     GPIO_DRV_STR_14_mA,
     GPIO_DRV_STR_16_mA
} GpioDriveSrength;

