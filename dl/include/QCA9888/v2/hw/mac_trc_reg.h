/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _MAC_TRC_REG_H_
#define _MAC_TRC_REG_H_


#ifndef __MAC_TRC_REG_BASE_ADDRESS
#define __MAC_TRC_REG_BASE_ADDRESS (0x31c00)
#endif


// 0x0 (MAC_TRC)
#define MAC_TRC_OBS_BUS_SEL_LSB                                                10
#define MAC_TRC_OBS_BUS_SEL_MSB                                                11
#define MAC_TRC_OBS_BUS_SEL_MASK                                               0xc00
#define MAC_TRC_OBS_BUS_SEL_GET(x)                                             (((x) & MAC_TRC_OBS_BUS_SEL_MASK) >> MAC_TRC_OBS_BUS_SEL_LSB)
#define MAC_TRC_OBS_BUS_SEL_SET(x)                                             (((0 | (x)) << MAC_TRC_OBS_BUS_SEL_LSB) & MAC_TRC_OBS_BUS_SEL_MASK)
#define MAC_TRC_OBS_BUS_SEL_RESET                                              0x0
#define MAC_TRC_MAC_MODULE_SEL_LSB                                             8
#define MAC_TRC_MAC_MODULE_SEL_MSB                                             9
#define MAC_TRC_MAC_MODULE_SEL_MASK                                            0x300
#define MAC_TRC_MAC_MODULE_SEL_GET(x)                                          (((x) & MAC_TRC_MAC_MODULE_SEL_MASK) >> MAC_TRC_MAC_MODULE_SEL_LSB)
#define MAC_TRC_MAC_MODULE_SEL_SET(x)                                          (((0 | (x)) << MAC_TRC_MAC_MODULE_SEL_LSB) & MAC_TRC_MAC_MODULE_SEL_MASK)
#define MAC_TRC_MAC_MODULE_SEL_RESET                                           0x0
#define MAC_TRC_CPU_ACCESS_EN_VALUE_LSB                                        4
#define MAC_TRC_CPU_ACCESS_EN_VALUE_MSB                                        4
#define MAC_TRC_CPU_ACCESS_EN_VALUE_MASK                                       0x10
#define MAC_TRC_CPU_ACCESS_EN_VALUE_GET(x)                                     (((x) & MAC_TRC_CPU_ACCESS_EN_VALUE_MASK) >> MAC_TRC_CPU_ACCESS_EN_VALUE_LSB)
#define MAC_TRC_CPU_ACCESS_EN_VALUE_SET(x)                                     (((0 | (x)) << MAC_TRC_CPU_ACCESS_EN_VALUE_LSB) & MAC_TRC_CPU_ACCESS_EN_VALUE_MASK)
#define MAC_TRC_CPU_ACCESS_EN_VALUE_RESET                                      0x0
#define MAC_TRC_BUF_CFG_VALUE_LSB                                              1
#define MAC_TRC_BUF_CFG_VALUE_MSB                                              1
#define MAC_TRC_BUF_CFG_VALUE_MASK                                             0x2
#define MAC_TRC_BUF_CFG_VALUE_GET(x)                                           (((x) & MAC_TRC_BUF_CFG_VALUE_MASK) >> MAC_TRC_BUF_CFG_VALUE_LSB)
#define MAC_TRC_BUF_CFG_VALUE_SET(x)                                           (((0 | (x)) << MAC_TRC_BUF_CFG_VALUE_LSB) & MAC_TRC_BUF_CFG_VALUE_MASK)
#define MAC_TRC_BUF_CFG_VALUE_RESET                                            0x0
#define MAC_TRC_ENABLE_VALUE_LSB                                               0
#define MAC_TRC_ENABLE_VALUE_MSB                                               0
#define MAC_TRC_ENABLE_VALUE_MASK                                              0x1
#define MAC_TRC_ENABLE_VALUE_GET(x)                                            (((x) & MAC_TRC_ENABLE_VALUE_MASK) >> MAC_TRC_ENABLE_VALUE_LSB)
#define MAC_TRC_ENABLE_VALUE_SET(x)                                            (((0 | (x)) << MAC_TRC_ENABLE_VALUE_LSB) & MAC_TRC_ENABLE_VALUE_MASK)
#define MAC_TRC_ENABLE_VALUE_RESET                                             0x0
#define MAC_TRC_ADDRESS                                                        (0x0 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_RSTMASK                                                        0xf13
#define MAC_TRC_RESET                                                          0x0

// 0x4 (MAC_TRC_BUF_INIT)
#define MAC_TRC_BUF_INIT_VALUE_LSB                                             0
#define MAC_TRC_BUF_INIT_VALUE_MSB                                             0
#define MAC_TRC_BUF_INIT_VALUE_MASK                                            0x1
#define MAC_TRC_BUF_INIT_VALUE_GET(x)                                          (((x) & MAC_TRC_BUF_INIT_VALUE_MASK) >> MAC_TRC_BUF_INIT_VALUE_LSB)
#define MAC_TRC_BUF_INIT_VALUE_SET(x)                                          (((0 | (x)) << MAC_TRC_BUF_INIT_VALUE_LSB) & MAC_TRC_BUF_INIT_VALUE_MASK)
#define MAC_TRC_BUF_INIT_VALUE_RESET                                           0x0
#define MAC_TRC_BUF_INIT_ADDRESS                                               (0x4 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_BUF_INIT_RSTMASK                                               0x1
#define MAC_TRC_BUF_INIT_RESET                                                 0x0

// 0x8 (MAC_TRC_ADDR)
#define MAC_TRC_ADDR_END_VALUE_LSB                                             16
#define MAC_TRC_ADDR_END_VALUE_MSB                                             29
#define MAC_TRC_ADDR_END_VALUE_MASK                                            0x3fff0000
#define MAC_TRC_ADDR_END_VALUE_GET(x)                                          (((x) & MAC_TRC_ADDR_END_VALUE_MASK) >> MAC_TRC_ADDR_END_VALUE_LSB)
#define MAC_TRC_ADDR_END_VALUE_SET(x)                                          (((0 | (x)) << MAC_TRC_ADDR_END_VALUE_LSB) & MAC_TRC_ADDR_END_VALUE_MASK)
#define MAC_TRC_ADDR_END_VALUE_RESET                                           0x0
#define MAC_TRC_ADDR_START_VALUE_LSB                                           0
#define MAC_TRC_ADDR_START_VALUE_MSB                                           13
#define MAC_TRC_ADDR_START_VALUE_MASK                                          0x3fff
#define MAC_TRC_ADDR_START_VALUE_GET(x)                                        (((x) & MAC_TRC_ADDR_START_VALUE_MASK) >> MAC_TRC_ADDR_START_VALUE_LSB)
#define MAC_TRC_ADDR_START_VALUE_SET(x)                                        (((0 | (x)) << MAC_TRC_ADDR_START_VALUE_LSB) & MAC_TRC_ADDR_START_VALUE_MASK)
#define MAC_TRC_ADDR_START_VALUE_RESET                                         0x0
#define MAC_TRC_ADDR_ADDRESS                                                   (0x8 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_ADDR_RSTMASK                                                   0x3fff3fff
#define MAC_TRC_ADDR_RESET                                                     0x0

// 0xc (MAC_TRC_WFT_CAPTURE_CTRL)
#define MAC_TRC_WFT_CAPTURE_CTRL_CAP_MODE_LSB                                  30
#define MAC_TRC_WFT_CAPTURE_CTRL_CAP_MODE_MSB                                  31
#define MAC_TRC_WFT_CAPTURE_CTRL_CAP_MODE_MASK                                 0xc0000000
#define MAC_TRC_WFT_CAPTURE_CTRL_CAP_MODE_GET(x)                               (((x) & MAC_TRC_WFT_CAPTURE_CTRL_CAP_MODE_MASK) >> MAC_TRC_WFT_CAPTURE_CTRL_CAP_MODE_LSB)
#define MAC_TRC_WFT_CAPTURE_CTRL_CAP_MODE_SET(x)                               (((0 | (x)) << MAC_TRC_WFT_CAPTURE_CTRL_CAP_MODE_LSB) & MAC_TRC_WFT_CAPTURE_CTRL_CAP_MODE_MASK)
#define MAC_TRC_WFT_CAPTURE_CTRL_CAP_MODE_RESET                                0x0
#define MAC_TRC_WFT_CAPTURE_CTRL_CAP_MASK_LSB                                  0
#define MAC_TRC_WFT_CAPTURE_CTRL_CAP_MASK_MSB                                  29
#define MAC_TRC_WFT_CAPTURE_CTRL_CAP_MASK_MASK                                 0x3fffffff
#define MAC_TRC_WFT_CAPTURE_CTRL_CAP_MASK_GET(x)                               (((x) & MAC_TRC_WFT_CAPTURE_CTRL_CAP_MASK_MASK) >> MAC_TRC_WFT_CAPTURE_CTRL_CAP_MASK_LSB)
#define MAC_TRC_WFT_CAPTURE_CTRL_CAP_MASK_SET(x)                               (((0 | (x)) << MAC_TRC_WFT_CAPTURE_CTRL_CAP_MASK_LSB) & MAC_TRC_WFT_CAPTURE_CTRL_CAP_MASK_MASK)
#define MAC_TRC_WFT_CAPTURE_CTRL_CAP_MASK_RESET                                0x0
#define MAC_TRC_WFT_CAPTURE_CTRL_ADDRESS                                       (0xc + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_WFT_CAPTURE_CTRL_RSTMASK                                       0xffffffff
#define MAC_TRC_WFT_CAPTURE_CTRL_RESET                                         0x0

// 0x10 (MAC_TRC_WFT_STATE_CTRL)
#define MAC_TRC_WFT_STATE_CTRL_MAX_CAP_CNT_LSB                                 16
#define MAC_TRC_WFT_STATE_CTRL_MAX_CAP_CNT_MSB                                 31
#define MAC_TRC_WFT_STATE_CTRL_MAX_CAP_CNT_MASK                                0xffff0000
#define MAC_TRC_WFT_STATE_CTRL_MAX_CAP_CNT_GET(x)                              (((x) & MAC_TRC_WFT_STATE_CTRL_MAX_CAP_CNT_MASK) >> MAC_TRC_WFT_STATE_CTRL_MAX_CAP_CNT_LSB)
#define MAC_TRC_WFT_STATE_CTRL_MAX_CAP_CNT_SET(x)                              (((0 | (x)) << MAC_TRC_WFT_STATE_CTRL_MAX_CAP_CNT_LSB) & MAC_TRC_WFT_STATE_CTRL_MAX_CAP_CNT_MASK)
#define MAC_TRC_WFT_STATE_CTRL_MAX_CAP_CNT_RESET                               0x0
#define MAC_TRC_WFT_STATE_CTRL_NXT_TS_EN_LSB                                   0
#define MAC_TRC_WFT_STATE_CTRL_NXT_TS_EN_MSB                                   4
#define MAC_TRC_WFT_STATE_CTRL_NXT_TS_EN_MASK                                  0x1f
#define MAC_TRC_WFT_STATE_CTRL_NXT_TS_EN_GET(x)                                (((x) & MAC_TRC_WFT_STATE_CTRL_NXT_TS_EN_MASK) >> MAC_TRC_WFT_STATE_CTRL_NXT_TS_EN_LSB)
#define MAC_TRC_WFT_STATE_CTRL_NXT_TS_EN_SET(x)                                (((0 | (x)) << MAC_TRC_WFT_STATE_CTRL_NXT_TS_EN_LSB) & MAC_TRC_WFT_STATE_CTRL_NXT_TS_EN_MASK)
#define MAC_TRC_WFT_STATE_CTRL_NXT_TS_EN_RESET                                 0x0
#define MAC_TRC_WFT_STATE_CTRL_ADDRESS                                         (0x10 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_WFT_STATE_CTRL_RSTMASK                                         0xffff001f
#define MAC_TRC_WFT_STATE_CTRL_RESET                                           0x0

// 0x14 (MAC_TRC_TS1_CAPTURE_CTRL)
#define MAC_TRC_TS1_CAPTURE_CTRL_CAP_MODE_LSB                                  30
#define MAC_TRC_TS1_CAPTURE_CTRL_CAP_MODE_MSB                                  31
#define MAC_TRC_TS1_CAPTURE_CTRL_CAP_MODE_MASK                                 0xc0000000
#define MAC_TRC_TS1_CAPTURE_CTRL_CAP_MODE_GET(x)                               (((x) & MAC_TRC_TS1_CAPTURE_CTRL_CAP_MODE_MASK) >> MAC_TRC_TS1_CAPTURE_CTRL_CAP_MODE_LSB)
#define MAC_TRC_TS1_CAPTURE_CTRL_CAP_MODE_SET(x)                               (((0 | (x)) << MAC_TRC_TS1_CAPTURE_CTRL_CAP_MODE_LSB) & MAC_TRC_TS1_CAPTURE_CTRL_CAP_MODE_MASK)
#define MAC_TRC_TS1_CAPTURE_CTRL_CAP_MODE_RESET                                0x0
#define MAC_TRC_TS1_CAPTURE_CTRL_CAP_MASK_LSB                                  0
#define MAC_TRC_TS1_CAPTURE_CTRL_CAP_MASK_MSB                                  29
#define MAC_TRC_TS1_CAPTURE_CTRL_CAP_MASK_MASK                                 0x3fffffff
#define MAC_TRC_TS1_CAPTURE_CTRL_CAP_MASK_GET(x)                               (((x) & MAC_TRC_TS1_CAPTURE_CTRL_CAP_MASK_MASK) >> MAC_TRC_TS1_CAPTURE_CTRL_CAP_MASK_LSB)
#define MAC_TRC_TS1_CAPTURE_CTRL_CAP_MASK_SET(x)                               (((0 | (x)) << MAC_TRC_TS1_CAPTURE_CTRL_CAP_MASK_LSB) & MAC_TRC_TS1_CAPTURE_CTRL_CAP_MASK_MASK)
#define MAC_TRC_TS1_CAPTURE_CTRL_CAP_MASK_RESET                                0x0
#define MAC_TRC_TS1_CAPTURE_CTRL_ADDRESS                                       (0x14 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS1_CAPTURE_CTRL_RSTMASK                                       0xffffffff
#define MAC_TRC_TS1_CAPTURE_CTRL_RESET                                         0x0

// 0x18 (MAC_TRC_TS1_STATE_CTRL)
#define MAC_TRC_TS1_STATE_CTRL_MAX_CAP_CNT_LSB                                 16
#define MAC_TRC_TS1_STATE_CTRL_MAX_CAP_CNT_MSB                                 31
#define MAC_TRC_TS1_STATE_CTRL_MAX_CAP_CNT_MASK                                0xffff0000
#define MAC_TRC_TS1_STATE_CTRL_MAX_CAP_CNT_GET(x)                              (((x) & MAC_TRC_TS1_STATE_CTRL_MAX_CAP_CNT_MASK) >> MAC_TRC_TS1_STATE_CTRL_MAX_CAP_CNT_LSB)
#define MAC_TRC_TS1_STATE_CTRL_MAX_CAP_CNT_SET(x)                              (((0 | (x)) << MAC_TRC_TS1_STATE_CTRL_MAX_CAP_CNT_LSB) & MAC_TRC_TS1_STATE_CTRL_MAX_CAP_CNT_MASK)
#define MAC_TRC_TS1_STATE_CTRL_MAX_CAP_CNT_RESET                               0x0
#define MAC_TRC_TS1_STATE_CTRL_NXT_TS_EN_LSB                                   0
#define MAC_TRC_TS1_STATE_CTRL_NXT_TS_EN_MSB                                   4
#define MAC_TRC_TS1_STATE_CTRL_NXT_TS_EN_MASK                                  0x1f
#define MAC_TRC_TS1_STATE_CTRL_NXT_TS_EN_GET(x)                                (((x) & MAC_TRC_TS1_STATE_CTRL_NXT_TS_EN_MASK) >> MAC_TRC_TS1_STATE_CTRL_NXT_TS_EN_LSB)
#define MAC_TRC_TS1_STATE_CTRL_NXT_TS_EN_SET(x)                                (((0 | (x)) << MAC_TRC_TS1_STATE_CTRL_NXT_TS_EN_LSB) & MAC_TRC_TS1_STATE_CTRL_NXT_TS_EN_MASK)
#define MAC_TRC_TS1_STATE_CTRL_NXT_TS_EN_RESET                                 0x0
#define MAC_TRC_TS1_STATE_CTRL_ADDRESS                                         (0x18 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS1_STATE_CTRL_RSTMASK                                         0xffff001f
#define MAC_TRC_TS1_STATE_CTRL_RESET                                           0x0

// 0x1c (MAC_TRC_TS1_TRIG_MASK)
#define MAC_TRC_TS1_TRIG_MASK_VALUE_LSB                                        0
#define MAC_TRC_TS1_TRIG_MASK_VALUE_MSB                                        29
#define MAC_TRC_TS1_TRIG_MASK_VALUE_MASK                                       0x3fffffff
#define MAC_TRC_TS1_TRIG_MASK_VALUE_GET(x)                                     (((x) & MAC_TRC_TS1_TRIG_MASK_VALUE_MASK) >> MAC_TRC_TS1_TRIG_MASK_VALUE_LSB)
#define MAC_TRC_TS1_TRIG_MASK_VALUE_SET(x)                                     (((0 | (x)) << MAC_TRC_TS1_TRIG_MASK_VALUE_LSB) & MAC_TRC_TS1_TRIG_MASK_VALUE_MASK)
#define MAC_TRC_TS1_TRIG_MASK_VALUE_RESET                                      0x0
#define MAC_TRC_TS1_TRIG_MASK_ADDRESS                                          (0x1c + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS1_TRIG_MASK_RSTMASK                                          0x3fffffff
#define MAC_TRC_TS1_TRIG_MASK_RESET                                            0x0

// 0x20 (MAC_TRC_TS1_TRIG)
#define MAC_TRC_TS1_TRIG_VALUE_LSB                                             0
#define MAC_TRC_TS1_TRIG_VALUE_MSB                                             29
#define MAC_TRC_TS1_TRIG_VALUE_MASK                                            0x3fffffff
#define MAC_TRC_TS1_TRIG_VALUE_GET(x)                                          (((x) & MAC_TRC_TS1_TRIG_VALUE_MASK) >> MAC_TRC_TS1_TRIG_VALUE_LSB)
#define MAC_TRC_TS1_TRIG_VALUE_SET(x)                                          (((0 | (x)) << MAC_TRC_TS1_TRIG_VALUE_LSB) & MAC_TRC_TS1_TRIG_VALUE_MASK)
#define MAC_TRC_TS1_TRIG_VALUE_RESET                                           0x0
#define MAC_TRC_TS1_TRIG_ADDRESS                                               (0x20 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS1_TRIG_RSTMASK                                               0x3fffffff
#define MAC_TRC_TS1_TRIG_RESET                                                 0x0

// 0x24 (MAC_TRC_TS2_CAPTURE_CTRL)
#define MAC_TRC_TS2_CAPTURE_CTRL_CAP_MODE_LSB                                  30
#define MAC_TRC_TS2_CAPTURE_CTRL_CAP_MODE_MSB                                  31
#define MAC_TRC_TS2_CAPTURE_CTRL_CAP_MODE_MASK                                 0xc0000000
#define MAC_TRC_TS2_CAPTURE_CTRL_CAP_MODE_GET(x)                               (((x) & MAC_TRC_TS2_CAPTURE_CTRL_CAP_MODE_MASK) >> MAC_TRC_TS2_CAPTURE_CTRL_CAP_MODE_LSB)
#define MAC_TRC_TS2_CAPTURE_CTRL_CAP_MODE_SET(x)                               (((0 | (x)) << MAC_TRC_TS2_CAPTURE_CTRL_CAP_MODE_LSB) & MAC_TRC_TS2_CAPTURE_CTRL_CAP_MODE_MASK)
#define MAC_TRC_TS2_CAPTURE_CTRL_CAP_MODE_RESET                                0x0
#define MAC_TRC_TS2_CAPTURE_CTRL_CAP_MASK_LSB                                  0
#define MAC_TRC_TS2_CAPTURE_CTRL_CAP_MASK_MSB                                  29
#define MAC_TRC_TS2_CAPTURE_CTRL_CAP_MASK_MASK                                 0x3fffffff
#define MAC_TRC_TS2_CAPTURE_CTRL_CAP_MASK_GET(x)                               (((x) & MAC_TRC_TS2_CAPTURE_CTRL_CAP_MASK_MASK) >> MAC_TRC_TS2_CAPTURE_CTRL_CAP_MASK_LSB)
#define MAC_TRC_TS2_CAPTURE_CTRL_CAP_MASK_SET(x)                               (((0 | (x)) << MAC_TRC_TS2_CAPTURE_CTRL_CAP_MASK_LSB) & MAC_TRC_TS2_CAPTURE_CTRL_CAP_MASK_MASK)
#define MAC_TRC_TS2_CAPTURE_CTRL_CAP_MASK_RESET                                0x0
#define MAC_TRC_TS2_CAPTURE_CTRL_ADDRESS                                       (0x24 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS2_CAPTURE_CTRL_RSTMASK                                       0xffffffff
#define MAC_TRC_TS2_CAPTURE_CTRL_RESET                                         0x0

// 0x28 (MAC_TRC_TS2_STATE_CTRL)
#define MAC_TRC_TS2_STATE_CTRL_MAX_CAP_CNT_LSB                                 16
#define MAC_TRC_TS2_STATE_CTRL_MAX_CAP_CNT_MSB                                 31
#define MAC_TRC_TS2_STATE_CTRL_MAX_CAP_CNT_MASK                                0xffff0000
#define MAC_TRC_TS2_STATE_CTRL_MAX_CAP_CNT_GET(x)                              (((x) & MAC_TRC_TS2_STATE_CTRL_MAX_CAP_CNT_MASK) >> MAC_TRC_TS2_STATE_CTRL_MAX_CAP_CNT_LSB)
#define MAC_TRC_TS2_STATE_CTRL_MAX_CAP_CNT_SET(x)                              (((0 | (x)) << MAC_TRC_TS2_STATE_CTRL_MAX_CAP_CNT_LSB) & MAC_TRC_TS2_STATE_CTRL_MAX_CAP_CNT_MASK)
#define MAC_TRC_TS2_STATE_CTRL_MAX_CAP_CNT_RESET                               0x0
#define MAC_TRC_TS2_STATE_CTRL_NXT_TS_EN_LSB                                   0
#define MAC_TRC_TS2_STATE_CTRL_NXT_TS_EN_MSB                                   4
#define MAC_TRC_TS2_STATE_CTRL_NXT_TS_EN_MASK                                  0x1f
#define MAC_TRC_TS2_STATE_CTRL_NXT_TS_EN_GET(x)                                (((x) & MAC_TRC_TS2_STATE_CTRL_NXT_TS_EN_MASK) >> MAC_TRC_TS2_STATE_CTRL_NXT_TS_EN_LSB)
#define MAC_TRC_TS2_STATE_CTRL_NXT_TS_EN_SET(x)                                (((0 | (x)) << MAC_TRC_TS2_STATE_CTRL_NXT_TS_EN_LSB) & MAC_TRC_TS2_STATE_CTRL_NXT_TS_EN_MASK)
#define MAC_TRC_TS2_STATE_CTRL_NXT_TS_EN_RESET                                 0x0
#define MAC_TRC_TS2_STATE_CTRL_ADDRESS                                         (0x28 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS2_STATE_CTRL_RSTMASK                                         0xffff001f
#define MAC_TRC_TS2_STATE_CTRL_RESET                                           0x0

// 0x2c (MAC_TRC_TS2_TRIG_MASK)
#define MAC_TRC_TS2_TRIG_MASK_VALUE_LSB                                        0
#define MAC_TRC_TS2_TRIG_MASK_VALUE_MSB                                        29
#define MAC_TRC_TS2_TRIG_MASK_VALUE_MASK                                       0x3fffffff
#define MAC_TRC_TS2_TRIG_MASK_VALUE_GET(x)                                     (((x) & MAC_TRC_TS2_TRIG_MASK_VALUE_MASK) >> MAC_TRC_TS2_TRIG_MASK_VALUE_LSB)
#define MAC_TRC_TS2_TRIG_MASK_VALUE_SET(x)                                     (((0 | (x)) << MAC_TRC_TS2_TRIG_MASK_VALUE_LSB) & MAC_TRC_TS2_TRIG_MASK_VALUE_MASK)
#define MAC_TRC_TS2_TRIG_MASK_VALUE_RESET                                      0x0
#define MAC_TRC_TS2_TRIG_MASK_ADDRESS                                          (0x2c + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS2_TRIG_MASK_RSTMASK                                          0x3fffffff
#define MAC_TRC_TS2_TRIG_MASK_RESET                                            0x0

// 0x30 (MAC_TRC_TS2_TRIG)
#define MAC_TRC_TS2_TRIG_VALUE_LSB                                             0
#define MAC_TRC_TS2_TRIG_VALUE_MSB                                             29
#define MAC_TRC_TS2_TRIG_VALUE_MASK                                            0x3fffffff
#define MAC_TRC_TS2_TRIG_VALUE_GET(x)                                          (((x) & MAC_TRC_TS2_TRIG_VALUE_MASK) >> MAC_TRC_TS2_TRIG_VALUE_LSB)
#define MAC_TRC_TS2_TRIG_VALUE_SET(x)                                          (((0 | (x)) << MAC_TRC_TS2_TRIG_VALUE_LSB) & MAC_TRC_TS2_TRIG_VALUE_MASK)
#define MAC_TRC_TS2_TRIG_VALUE_RESET                                           0x0
#define MAC_TRC_TS2_TRIG_ADDRESS                                               (0x30 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS2_TRIG_RSTMASK                                               0x3fffffff
#define MAC_TRC_TS2_TRIG_RESET                                                 0x0

// 0x34 (MAC_TRC_TS3_CAPTURE_CTRL)
#define MAC_TRC_TS3_CAPTURE_CTRL_CAP_MODE_LSB                                  30
#define MAC_TRC_TS3_CAPTURE_CTRL_CAP_MODE_MSB                                  31
#define MAC_TRC_TS3_CAPTURE_CTRL_CAP_MODE_MASK                                 0xc0000000
#define MAC_TRC_TS3_CAPTURE_CTRL_CAP_MODE_GET(x)                               (((x) & MAC_TRC_TS3_CAPTURE_CTRL_CAP_MODE_MASK) >> MAC_TRC_TS3_CAPTURE_CTRL_CAP_MODE_LSB)
#define MAC_TRC_TS3_CAPTURE_CTRL_CAP_MODE_SET(x)                               (((0 | (x)) << MAC_TRC_TS3_CAPTURE_CTRL_CAP_MODE_LSB) & MAC_TRC_TS3_CAPTURE_CTRL_CAP_MODE_MASK)
#define MAC_TRC_TS3_CAPTURE_CTRL_CAP_MODE_RESET                                0x0
#define MAC_TRC_TS3_CAPTURE_CTRL_CAP_MASK_LSB                                  0
#define MAC_TRC_TS3_CAPTURE_CTRL_CAP_MASK_MSB                                  29
#define MAC_TRC_TS3_CAPTURE_CTRL_CAP_MASK_MASK                                 0x3fffffff
#define MAC_TRC_TS3_CAPTURE_CTRL_CAP_MASK_GET(x)                               (((x) & MAC_TRC_TS3_CAPTURE_CTRL_CAP_MASK_MASK) >> MAC_TRC_TS3_CAPTURE_CTRL_CAP_MASK_LSB)
#define MAC_TRC_TS3_CAPTURE_CTRL_CAP_MASK_SET(x)                               (((0 | (x)) << MAC_TRC_TS3_CAPTURE_CTRL_CAP_MASK_LSB) & MAC_TRC_TS3_CAPTURE_CTRL_CAP_MASK_MASK)
#define MAC_TRC_TS3_CAPTURE_CTRL_CAP_MASK_RESET                                0x0
#define MAC_TRC_TS3_CAPTURE_CTRL_ADDRESS                                       (0x34 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS3_CAPTURE_CTRL_RSTMASK                                       0xffffffff
#define MAC_TRC_TS3_CAPTURE_CTRL_RESET                                         0x0

// 0x38 (MAC_TRC_TS3_STATE_CTRL)
#define MAC_TRC_TS3_STATE_CTRL_MAX_CAP_CNT_LSB                                 16
#define MAC_TRC_TS3_STATE_CTRL_MAX_CAP_CNT_MSB                                 31
#define MAC_TRC_TS3_STATE_CTRL_MAX_CAP_CNT_MASK                                0xffff0000
#define MAC_TRC_TS3_STATE_CTRL_MAX_CAP_CNT_GET(x)                              (((x) & MAC_TRC_TS3_STATE_CTRL_MAX_CAP_CNT_MASK) >> MAC_TRC_TS3_STATE_CTRL_MAX_CAP_CNT_LSB)
#define MAC_TRC_TS3_STATE_CTRL_MAX_CAP_CNT_SET(x)                              (((0 | (x)) << MAC_TRC_TS3_STATE_CTRL_MAX_CAP_CNT_LSB) & MAC_TRC_TS3_STATE_CTRL_MAX_CAP_CNT_MASK)
#define MAC_TRC_TS3_STATE_CTRL_MAX_CAP_CNT_RESET                               0x0
#define MAC_TRC_TS3_STATE_CTRL_NXT_TS_EN_LSB                                   0
#define MAC_TRC_TS3_STATE_CTRL_NXT_TS_EN_MSB                                   4
#define MAC_TRC_TS3_STATE_CTRL_NXT_TS_EN_MASK                                  0x1f
#define MAC_TRC_TS3_STATE_CTRL_NXT_TS_EN_GET(x)                                (((x) & MAC_TRC_TS3_STATE_CTRL_NXT_TS_EN_MASK) >> MAC_TRC_TS3_STATE_CTRL_NXT_TS_EN_LSB)
#define MAC_TRC_TS3_STATE_CTRL_NXT_TS_EN_SET(x)                                (((0 | (x)) << MAC_TRC_TS3_STATE_CTRL_NXT_TS_EN_LSB) & MAC_TRC_TS3_STATE_CTRL_NXT_TS_EN_MASK)
#define MAC_TRC_TS3_STATE_CTRL_NXT_TS_EN_RESET                                 0x0
#define MAC_TRC_TS3_STATE_CTRL_ADDRESS                                         (0x38 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS3_STATE_CTRL_RSTMASK                                         0xffff001f
#define MAC_TRC_TS3_STATE_CTRL_RESET                                           0x0

// 0x3c (MAC_TRC_TS3_TRIG_MASK)
#define MAC_TRC_TS3_TRIG_MASK_VALUE_LSB                                        0
#define MAC_TRC_TS3_TRIG_MASK_VALUE_MSB                                        29
#define MAC_TRC_TS3_TRIG_MASK_VALUE_MASK                                       0x3fffffff
#define MAC_TRC_TS3_TRIG_MASK_VALUE_GET(x)                                     (((x) & MAC_TRC_TS3_TRIG_MASK_VALUE_MASK) >> MAC_TRC_TS3_TRIG_MASK_VALUE_LSB)
#define MAC_TRC_TS3_TRIG_MASK_VALUE_SET(x)                                     (((0 | (x)) << MAC_TRC_TS3_TRIG_MASK_VALUE_LSB) & MAC_TRC_TS3_TRIG_MASK_VALUE_MASK)
#define MAC_TRC_TS3_TRIG_MASK_VALUE_RESET                                      0x0
#define MAC_TRC_TS3_TRIG_MASK_ADDRESS                                          (0x3c + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS3_TRIG_MASK_RSTMASK                                          0x3fffffff
#define MAC_TRC_TS3_TRIG_MASK_RESET                                            0x0

// 0x40 (MAC_TRC_TS3_TRIG)
#define MAC_TRC_TS3_TRIG_VALUE_LSB                                             0
#define MAC_TRC_TS3_TRIG_VALUE_MSB                                             29
#define MAC_TRC_TS3_TRIG_VALUE_MASK                                            0x3fffffff
#define MAC_TRC_TS3_TRIG_VALUE_GET(x)                                          (((x) & MAC_TRC_TS3_TRIG_VALUE_MASK) >> MAC_TRC_TS3_TRIG_VALUE_LSB)
#define MAC_TRC_TS3_TRIG_VALUE_SET(x)                                          (((0 | (x)) << MAC_TRC_TS3_TRIG_VALUE_LSB) & MAC_TRC_TS3_TRIG_VALUE_MASK)
#define MAC_TRC_TS3_TRIG_VALUE_RESET                                           0x0
#define MAC_TRC_TS3_TRIG_ADDRESS                                               (0x40 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS3_TRIG_RSTMASK                                               0x3fffffff
#define MAC_TRC_TS3_TRIG_RESET                                                 0x0

// 0x44 (MAC_TRC_TS4_CAPTURE_CTRL)
#define MAC_TRC_TS4_CAPTURE_CTRL_CAP_MODE_LSB                                  30
#define MAC_TRC_TS4_CAPTURE_CTRL_CAP_MODE_MSB                                  31
#define MAC_TRC_TS4_CAPTURE_CTRL_CAP_MODE_MASK                                 0xc0000000
#define MAC_TRC_TS4_CAPTURE_CTRL_CAP_MODE_GET(x)                               (((x) & MAC_TRC_TS4_CAPTURE_CTRL_CAP_MODE_MASK) >> MAC_TRC_TS4_CAPTURE_CTRL_CAP_MODE_LSB)
#define MAC_TRC_TS4_CAPTURE_CTRL_CAP_MODE_SET(x)                               (((0 | (x)) << MAC_TRC_TS4_CAPTURE_CTRL_CAP_MODE_LSB) & MAC_TRC_TS4_CAPTURE_CTRL_CAP_MODE_MASK)
#define MAC_TRC_TS4_CAPTURE_CTRL_CAP_MODE_RESET                                0x0
#define MAC_TRC_TS4_CAPTURE_CTRL_CAP_MASK_LSB                                  0
#define MAC_TRC_TS4_CAPTURE_CTRL_CAP_MASK_MSB                                  29
#define MAC_TRC_TS4_CAPTURE_CTRL_CAP_MASK_MASK                                 0x3fffffff
#define MAC_TRC_TS4_CAPTURE_CTRL_CAP_MASK_GET(x)                               (((x) & MAC_TRC_TS4_CAPTURE_CTRL_CAP_MASK_MASK) >> MAC_TRC_TS4_CAPTURE_CTRL_CAP_MASK_LSB)
#define MAC_TRC_TS4_CAPTURE_CTRL_CAP_MASK_SET(x)                               (((0 | (x)) << MAC_TRC_TS4_CAPTURE_CTRL_CAP_MASK_LSB) & MAC_TRC_TS4_CAPTURE_CTRL_CAP_MASK_MASK)
#define MAC_TRC_TS4_CAPTURE_CTRL_CAP_MASK_RESET                                0x0
#define MAC_TRC_TS4_CAPTURE_CTRL_ADDRESS                                       (0x44 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS4_CAPTURE_CTRL_RSTMASK                                       0xffffffff
#define MAC_TRC_TS4_CAPTURE_CTRL_RESET                                         0x0

// 0x48 (MAC_TRC_TS4_STATE_CTRL)
#define MAC_TRC_TS4_STATE_CTRL_MAX_CAP_CNT_LSB                                 16
#define MAC_TRC_TS4_STATE_CTRL_MAX_CAP_CNT_MSB                                 31
#define MAC_TRC_TS4_STATE_CTRL_MAX_CAP_CNT_MASK                                0xffff0000
#define MAC_TRC_TS4_STATE_CTRL_MAX_CAP_CNT_GET(x)                              (((x) & MAC_TRC_TS4_STATE_CTRL_MAX_CAP_CNT_MASK) >> MAC_TRC_TS4_STATE_CTRL_MAX_CAP_CNT_LSB)
#define MAC_TRC_TS4_STATE_CTRL_MAX_CAP_CNT_SET(x)                              (((0 | (x)) << MAC_TRC_TS4_STATE_CTRL_MAX_CAP_CNT_LSB) & MAC_TRC_TS4_STATE_CTRL_MAX_CAP_CNT_MASK)
#define MAC_TRC_TS4_STATE_CTRL_MAX_CAP_CNT_RESET                               0x0
#define MAC_TRC_TS4_STATE_CTRL_NXT_TS_EN_LSB                                   0
#define MAC_TRC_TS4_STATE_CTRL_NXT_TS_EN_MSB                                   4
#define MAC_TRC_TS4_STATE_CTRL_NXT_TS_EN_MASK                                  0x1f
#define MAC_TRC_TS4_STATE_CTRL_NXT_TS_EN_GET(x)                                (((x) & MAC_TRC_TS4_STATE_CTRL_NXT_TS_EN_MASK) >> MAC_TRC_TS4_STATE_CTRL_NXT_TS_EN_LSB)
#define MAC_TRC_TS4_STATE_CTRL_NXT_TS_EN_SET(x)                                (((0 | (x)) << MAC_TRC_TS4_STATE_CTRL_NXT_TS_EN_LSB) & MAC_TRC_TS4_STATE_CTRL_NXT_TS_EN_MASK)
#define MAC_TRC_TS4_STATE_CTRL_NXT_TS_EN_RESET                                 0x0
#define MAC_TRC_TS4_STATE_CTRL_ADDRESS                                         (0x48 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS4_STATE_CTRL_RSTMASK                                         0xffff001f
#define MAC_TRC_TS4_STATE_CTRL_RESET                                           0x0

// 0x4c (MAC_TRC_TS4_TRIG_MASK)
#define MAC_TRC_TS4_TRIG_MASK_VALUE_LSB                                        0
#define MAC_TRC_TS4_TRIG_MASK_VALUE_MSB                                        29
#define MAC_TRC_TS4_TRIG_MASK_VALUE_MASK                                       0x3fffffff
#define MAC_TRC_TS4_TRIG_MASK_VALUE_GET(x)                                     (((x) & MAC_TRC_TS4_TRIG_MASK_VALUE_MASK) >> MAC_TRC_TS4_TRIG_MASK_VALUE_LSB)
#define MAC_TRC_TS4_TRIG_MASK_VALUE_SET(x)                                     (((0 | (x)) << MAC_TRC_TS4_TRIG_MASK_VALUE_LSB) & MAC_TRC_TS4_TRIG_MASK_VALUE_MASK)
#define MAC_TRC_TS4_TRIG_MASK_VALUE_RESET                                      0x0
#define MAC_TRC_TS4_TRIG_MASK_ADDRESS                                          (0x4c + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS4_TRIG_MASK_RSTMASK                                          0x3fffffff
#define MAC_TRC_TS4_TRIG_MASK_RESET                                            0x0

// 0x50 (MAC_TRC_TS4_TRIG)
#define MAC_TRC_TS4_TRIG_VALUE_LSB                                             0
#define MAC_TRC_TS4_TRIG_VALUE_MSB                                             29
#define MAC_TRC_TS4_TRIG_VALUE_MASK                                            0x3fffffff
#define MAC_TRC_TS4_TRIG_VALUE_GET(x)                                          (((x) & MAC_TRC_TS4_TRIG_VALUE_MASK) >> MAC_TRC_TS4_TRIG_VALUE_LSB)
#define MAC_TRC_TS4_TRIG_VALUE_SET(x)                                          (((0 | (x)) << MAC_TRC_TS4_TRIG_VALUE_LSB) & MAC_TRC_TS4_TRIG_VALUE_MASK)
#define MAC_TRC_TS4_TRIG_VALUE_RESET                                           0x0
#define MAC_TRC_TS4_TRIG_ADDRESS                                               (0x50 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS4_TRIG_RSTMASK                                               0x3fffffff
#define MAC_TRC_TS4_TRIG_RESET                                                 0x0

// 0x54 (MAC_TRC_TS5_CAPTURE_CTRL)
#define MAC_TRC_TS5_CAPTURE_CTRL_CAP_MODE_LSB                                  30
#define MAC_TRC_TS5_CAPTURE_CTRL_CAP_MODE_MSB                                  31
#define MAC_TRC_TS5_CAPTURE_CTRL_CAP_MODE_MASK                                 0xc0000000
#define MAC_TRC_TS5_CAPTURE_CTRL_CAP_MODE_GET(x)                               (((x) & MAC_TRC_TS5_CAPTURE_CTRL_CAP_MODE_MASK) >> MAC_TRC_TS5_CAPTURE_CTRL_CAP_MODE_LSB)
#define MAC_TRC_TS5_CAPTURE_CTRL_CAP_MODE_SET(x)                               (((0 | (x)) << MAC_TRC_TS5_CAPTURE_CTRL_CAP_MODE_LSB) & MAC_TRC_TS5_CAPTURE_CTRL_CAP_MODE_MASK)
#define MAC_TRC_TS5_CAPTURE_CTRL_CAP_MODE_RESET                                0x0
#define MAC_TRC_TS5_CAPTURE_CTRL_CAP_MASK_LSB                                  0
#define MAC_TRC_TS5_CAPTURE_CTRL_CAP_MASK_MSB                                  29
#define MAC_TRC_TS5_CAPTURE_CTRL_CAP_MASK_MASK                                 0x3fffffff
#define MAC_TRC_TS5_CAPTURE_CTRL_CAP_MASK_GET(x)                               (((x) & MAC_TRC_TS5_CAPTURE_CTRL_CAP_MASK_MASK) >> MAC_TRC_TS5_CAPTURE_CTRL_CAP_MASK_LSB)
#define MAC_TRC_TS5_CAPTURE_CTRL_CAP_MASK_SET(x)                               (((0 | (x)) << MAC_TRC_TS5_CAPTURE_CTRL_CAP_MASK_LSB) & MAC_TRC_TS5_CAPTURE_CTRL_CAP_MASK_MASK)
#define MAC_TRC_TS5_CAPTURE_CTRL_CAP_MASK_RESET                                0x0
#define MAC_TRC_TS5_CAPTURE_CTRL_ADDRESS                                       (0x54 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS5_CAPTURE_CTRL_RSTMASK                                       0xffffffff
#define MAC_TRC_TS5_CAPTURE_CTRL_RESET                                         0x0

// 0x58 (MAC_TRC_TS5_STATE_CTRL)
#define MAC_TRC_TS5_STATE_CTRL_MAX_CAP_CNT_LSB                                 16
#define MAC_TRC_TS5_STATE_CTRL_MAX_CAP_CNT_MSB                                 31
#define MAC_TRC_TS5_STATE_CTRL_MAX_CAP_CNT_MASK                                0xffff0000
#define MAC_TRC_TS5_STATE_CTRL_MAX_CAP_CNT_GET(x)                              (((x) & MAC_TRC_TS5_STATE_CTRL_MAX_CAP_CNT_MASK) >> MAC_TRC_TS5_STATE_CTRL_MAX_CAP_CNT_LSB)
#define MAC_TRC_TS5_STATE_CTRL_MAX_CAP_CNT_SET(x)                              (((0 | (x)) << MAC_TRC_TS5_STATE_CTRL_MAX_CAP_CNT_LSB) & MAC_TRC_TS5_STATE_CTRL_MAX_CAP_CNT_MASK)
#define MAC_TRC_TS5_STATE_CTRL_MAX_CAP_CNT_RESET                               0x0
#define MAC_TRC_TS5_STATE_CTRL_NXT_TS_EN_LSB                                   0
#define MAC_TRC_TS5_STATE_CTRL_NXT_TS_EN_MSB                                   4
#define MAC_TRC_TS5_STATE_CTRL_NXT_TS_EN_MASK                                  0x1f
#define MAC_TRC_TS5_STATE_CTRL_NXT_TS_EN_GET(x)                                (((x) & MAC_TRC_TS5_STATE_CTRL_NXT_TS_EN_MASK) >> MAC_TRC_TS5_STATE_CTRL_NXT_TS_EN_LSB)
#define MAC_TRC_TS5_STATE_CTRL_NXT_TS_EN_SET(x)                                (((0 | (x)) << MAC_TRC_TS5_STATE_CTRL_NXT_TS_EN_LSB) & MAC_TRC_TS5_STATE_CTRL_NXT_TS_EN_MASK)
#define MAC_TRC_TS5_STATE_CTRL_NXT_TS_EN_RESET                                 0x0
#define MAC_TRC_TS5_STATE_CTRL_ADDRESS                                         (0x58 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS5_STATE_CTRL_RSTMASK                                         0xffff001f
#define MAC_TRC_TS5_STATE_CTRL_RESET                                           0x0

// 0x5c (MAC_TRC_TS5_TRIG_MASK)
#define MAC_TRC_TS5_TRIG_MASK_VALUE_LSB                                        0
#define MAC_TRC_TS5_TRIG_MASK_VALUE_MSB                                        29
#define MAC_TRC_TS5_TRIG_MASK_VALUE_MASK                                       0x3fffffff
#define MAC_TRC_TS5_TRIG_MASK_VALUE_GET(x)                                     (((x) & MAC_TRC_TS5_TRIG_MASK_VALUE_MASK) >> MAC_TRC_TS5_TRIG_MASK_VALUE_LSB)
#define MAC_TRC_TS5_TRIG_MASK_VALUE_SET(x)                                     (((0 | (x)) << MAC_TRC_TS5_TRIG_MASK_VALUE_LSB) & MAC_TRC_TS5_TRIG_MASK_VALUE_MASK)
#define MAC_TRC_TS5_TRIG_MASK_VALUE_RESET                                      0x0
#define MAC_TRC_TS5_TRIG_MASK_ADDRESS                                          (0x5c + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS5_TRIG_MASK_RSTMASK                                          0x3fffffff
#define MAC_TRC_TS5_TRIG_MASK_RESET                                            0x0

// 0x60 (MAC_TRC_TS5_TRIG)
#define MAC_TRC_TS5_TRIG_VALUE_LSB                                             0
#define MAC_TRC_TS5_TRIG_VALUE_MSB                                             29
#define MAC_TRC_TS5_TRIG_VALUE_MASK                                            0x3fffffff
#define MAC_TRC_TS5_TRIG_VALUE_GET(x)                                          (((x) & MAC_TRC_TS5_TRIG_VALUE_MASK) >> MAC_TRC_TS5_TRIG_VALUE_LSB)
#define MAC_TRC_TS5_TRIG_VALUE_SET(x)                                          (((0 | (x)) << MAC_TRC_TS5_TRIG_VALUE_LSB) & MAC_TRC_TS5_TRIG_VALUE_MASK)
#define MAC_TRC_TS5_TRIG_VALUE_RESET                                           0x0
#define MAC_TRC_TS5_TRIG_ADDRESS                                               (0x60 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TS5_TRIG_RSTMASK                                               0x3fffffff
#define MAC_TRC_TS5_TRIG_RESET                                                 0x0

// 0x64 (MAC_TRC_CPU_ADDR)
#define MAC_TRC_CPU_ADDR_READ_VALUE_LSB                                        0
#define MAC_TRC_CPU_ADDR_READ_VALUE_MSB                                        31
#define MAC_TRC_CPU_ADDR_READ_VALUE_MASK                                       0xffffffff
#define MAC_TRC_CPU_ADDR_READ_VALUE_GET(x)                                     (((x) & MAC_TRC_CPU_ADDR_READ_VALUE_MASK) >> MAC_TRC_CPU_ADDR_READ_VALUE_LSB)
#define MAC_TRC_CPU_ADDR_READ_VALUE_SET(x)                                     (((0 | (x)) << MAC_TRC_CPU_ADDR_READ_VALUE_LSB) & MAC_TRC_CPU_ADDR_READ_VALUE_MASK)
#define MAC_TRC_CPU_ADDR_READ_VALUE_RESET                                      0x0
#define MAC_TRC_CPU_ADDR_ADDRESS                                               (0x64 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_CPU_ADDR_RSTMASK                                               0xffffffff
#define MAC_TRC_CPU_ADDR_RESET                                                 0x0

// 0x68 (MAC_TRC_CPU_DATA)
#define MAC_TRC_CPU_DATA_VALUE_LSB                                             0
#define MAC_TRC_CPU_DATA_VALUE_MSB                                             31
#define MAC_TRC_CPU_DATA_VALUE_MASK                                            0xffffffff
#define MAC_TRC_CPU_DATA_VALUE_GET(x)                                          (((x) & MAC_TRC_CPU_DATA_VALUE_MASK) >> MAC_TRC_CPU_DATA_VALUE_LSB)
#define MAC_TRC_CPU_DATA_VALUE_SET(x)                                          (((0 | (x)) << MAC_TRC_CPU_DATA_VALUE_LSB) & MAC_TRC_CPU_DATA_VALUE_MASK)
#define MAC_TRC_CPU_DATA_VALUE_RESET                                           0x0
#define MAC_TRC_CPU_DATA_ADDRESS                                               (0x68 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_CPU_DATA_RSTMASK                                               0xffffffff
#define MAC_TRC_CPU_DATA_RESET                                                 0x0

// 0x6c (MAC_TRC_STATUS_0)
#define MAC_TRC_STATUS_0_BUF_INIT_DONE_LSB                                     1
#define MAC_TRC_STATUS_0_BUF_INIT_DONE_MSB                                     1
#define MAC_TRC_STATUS_0_BUF_INIT_DONE_MASK                                    0x2
#define MAC_TRC_STATUS_0_BUF_INIT_DONE_GET(x)                                  (((x) & MAC_TRC_STATUS_0_BUF_INIT_DONE_MASK) >> MAC_TRC_STATUS_0_BUF_INIT_DONE_LSB)
#define MAC_TRC_STATUS_0_BUF_INIT_DONE_SET(x)                                  (((0 | (x)) << MAC_TRC_STATUS_0_BUF_INIT_DONE_LSB) & MAC_TRC_STATUS_0_BUF_INIT_DONE_MASK)
#define MAC_TRC_STATUS_0_BUF_INIT_DONE_RESET                                   0x0
#define MAC_TRC_STATUS_0_BUF_FULL_LSB                                          0
#define MAC_TRC_STATUS_0_BUF_FULL_MSB                                          0
#define MAC_TRC_STATUS_0_BUF_FULL_MASK                                         0x1
#define MAC_TRC_STATUS_0_BUF_FULL_GET(x)                                       (((x) & MAC_TRC_STATUS_0_BUF_FULL_MASK) >> MAC_TRC_STATUS_0_BUF_FULL_LSB)
#define MAC_TRC_STATUS_0_BUF_FULL_SET(x)                                       (((0 | (x)) << MAC_TRC_STATUS_0_BUF_FULL_LSB) & MAC_TRC_STATUS_0_BUF_FULL_MASK)
#define MAC_TRC_STATUS_0_BUF_FULL_RESET                                        0x0
#define MAC_TRC_STATUS_0_ADDRESS                                               (0x6c + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_STATUS_0_RSTMASK                                               0x3
#define MAC_TRC_STATUS_0_RESET                                                 0x0

// 0x70 (MAC_TRC_STATUS_1)
#define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_LSB                                   16
#define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MSB                                   29
#define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MASK                                  0x3fff0000
#define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_GET(x)                                (((x) & MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MASK) >> MAC_TRC_STATUS_1_BUF_RD_END_ADDR_LSB)
#define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_SET(x)                                (((0 | (x)) << MAC_TRC_STATUS_1_BUF_RD_END_ADDR_LSB) & MAC_TRC_STATUS_1_BUF_RD_END_ADDR_MASK)
#define MAC_TRC_STATUS_1_BUF_RD_END_ADDR_RESET                                 0x0
#define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_LSB                                 0
#define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MSB                                 13
#define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MASK                                0x3fff
#define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_GET(x)                              (((x) & MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MASK) >> MAC_TRC_STATUS_1_BUF_RD_START_ADDR_LSB)
#define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_SET(x)                              (((0 | (x)) << MAC_TRC_STATUS_1_BUF_RD_START_ADDR_LSB) & MAC_TRC_STATUS_1_BUF_RD_START_ADDR_MASK)
#define MAC_TRC_STATUS_1_BUF_RD_START_ADDR_RESET                               0x0
#define MAC_TRC_STATUS_1_ADDRESS                                               (0x70 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_STATUS_1_RSTMASK                                               0x3fff3fff
#define MAC_TRC_STATUS_1_RESET                                                 0x0

// 0x74 (MAC_TRC_STATUS_2)
#define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_LSB                                  8
#define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MSB                                  12
#define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MASK                                 0x1f00
#define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_GET(x)                               (((x) & MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MASK) >> MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_LSB)
#define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_SET(x)                               (((0 | (x)) << MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_LSB) & MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_MASK)
#define MAC_TRC_STATUS_2_TRIG_EVENT_FLAGS_RESET                                0x0
#define MAC_TRC_STATUS_2_MAIN_CTL_STATE_LSB                                    4
#define MAC_TRC_STATUS_2_MAIN_CTL_STATE_MSB                                    6
#define MAC_TRC_STATUS_2_MAIN_CTL_STATE_MASK                                   0x70
#define MAC_TRC_STATUS_2_MAIN_CTL_STATE_GET(x)                                 (((x) & MAC_TRC_STATUS_2_MAIN_CTL_STATE_MASK) >> MAC_TRC_STATUS_2_MAIN_CTL_STATE_LSB)
#define MAC_TRC_STATUS_2_MAIN_CTL_STATE_SET(x)                                 (((0 | (x)) << MAC_TRC_STATUS_2_MAIN_CTL_STATE_LSB) & MAC_TRC_STATUS_2_MAIN_CTL_STATE_MASK)
#define MAC_TRC_STATUS_2_MAIN_CTL_STATE_RESET                                  0x0
#define MAC_TRC_STATUS_2_WRCTL_STATE_LSB                                       0
#define MAC_TRC_STATUS_2_WRCTL_STATE_MSB                                       2
#define MAC_TRC_STATUS_2_WRCTL_STATE_MASK                                      0x7
#define MAC_TRC_STATUS_2_WRCTL_STATE_GET(x)                                    (((x) & MAC_TRC_STATUS_2_WRCTL_STATE_MASK) >> MAC_TRC_STATUS_2_WRCTL_STATE_LSB)
#define MAC_TRC_STATUS_2_WRCTL_STATE_SET(x)                                    (((0 | (x)) << MAC_TRC_STATUS_2_WRCTL_STATE_LSB) & MAC_TRC_STATUS_2_WRCTL_STATE_MASK)
#define MAC_TRC_STATUS_2_WRCTL_STATE_RESET                                     0x0
#define MAC_TRC_STATUS_2_ADDRESS                                               (0x74 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_STATUS_2_RSTMASK                                               0x1f77
#define MAC_TRC_STATUS_2_RESET                                                 0x0

// 0x78 (MAC_TRC_STATUS_3)
#define MAC_TRC_STATUS_3_TRIG_SAMPLE_LSB                                       0
#define MAC_TRC_STATUS_3_TRIG_SAMPLE_MSB                                       29
#define MAC_TRC_STATUS_3_TRIG_SAMPLE_MASK                                      0x3fffffff
#define MAC_TRC_STATUS_3_TRIG_SAMPLE_GET(x)                                    (((x) & MAC_TRC_STATUS_3_TRIG_SAMPLE_MASK) >> MAC_TRC_STATUS_3_TRIG_SAMPLE_LSB)
#define MAC_TRC_STATUS_3_TRIG_SAMPLE_SET(x)                                    (((0 | (x)) << MAC_TRC_STATUS_3_TRIG_SAMPLE_LSB) & MAC_TRC_STATUS_3_TRIG_SAMPLE_MASK)
#define MAC_TRC_STATUS_3_TRIG_SAMPLE_RESET                                     0x0
#define MAC_TRC_STATUS_3_ADDRESS                                               (0x78 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_STATUS_3_RSTMASK                                               0x3fffffff
#define MAC_TRC_STATUS_3_RESET                                                 0x0

// 0x7c (MAC_BB_OBS_BUS_SEL)
#define MAC_BB_OBS_BUS_SEL_VALUE_LSB                                           0
#define MAC_BB_OBS_BUS_SEL_VALUE_MSB                                           31
#define MAC_BB_OBS_BUS_SEL_VALUE_MASK                                          0xffffffff
#define MAC_BB_OBS_BUS_SEL_VALUE_GET(x)                                        (((x) & MAC_BB_OBS_BUS_SEL_VALUE_MASK) >> MAC_BB_OBS_BUS_SEL_VALUE_LSB)
#define MAC_BB_OBS_BUS_SEL_VALUE_SET(x)                                        (((0 | (x)) << MAC_BB_OBS_BUS_SEL_VALUE_LSB) & MAC_BB_OBS_BUS_SEL_VALUE_MASK)
#define MAC_BB_OBS_BUS_SEL_VALUE_RESET                                         0x0
#define MAC_BB_OBS_BUS_SEL_ADDRESS                                             (0x7c + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_BB_OBS_BUS_SEL_RSTMASK                                             0xffffffff
#define MAC_BB_OBS_BUS_SEL_RESET                                               0x0

// 0x80 (MAC_TRC_CPU_DATA_READ_DATA_SEL)
#define MAC_TRC_CPU_DATA_READ_DATA_SEL_VALUE_LSB                               0
#define MAC_TRC_CPU_DATA_READ_DATA_SEL_VALUE_MSB                               0
#define MAC_TRC_CPU_DATA_READ_DATA_SEL_VALUE_MASK                              0x1
#define MAC_TRC_CPU_DATA_READ_DATA_SEL_VALUE_GET(x)                            (((x) & MAC_TRC_CPU_DATA_READ_DATA_SEL_VALUE_MASK) >> MAC_TRC_CPU_DATA_READ_DATA_SEL_VALUE_LSB)
#define MAC_TRC_CPU_DATA_READ_DATA_SEL_VALUE_SET(x)                            (((0 | (x)) << MAC_TRC_CPU_DATA_READ_DATA_SEL_VALUE_LSB) & MAC_TRC_CPU_DATA_READ_DATA_SEL_VALUE_MASK)
#define MAC_TRC_CPU_DATA_READ_DATA_SEL_VALUE_RESET                             0x0
#define MAC_TRC_CPU_DATA_READ_DATA_SEL_ADDRESS                                 (0x80 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_CPU_DATA_READ_DATA_SEL_RSTMASK                                 0x1
#define MAC_TRC_CPU_DATA_READ_DATA_SEL_RESET                                   0x0

// 0x84 (MAC_TRC_LANE_SWAP)
#define MAC_TRC_LANE_SWAP_SEL_LSB                                              0
#define MAC_TRC_LANE_SWAP_SEL_MSB                                              4
#define MAC_TRC_LANE_SWAP_SEL_MASK                                             0x1f
#define MAC_TRC_LANE_SWAP_SEL_GET(x)                                           (((x) & MAC_TRC_LANE_SWAP_SEL_MASK) >> MAC_TRC_LANE_SWAP_SEL_LSB)
#define MAC_TRC_LANE_SWAP_SEL_SET(x)                                           (((0 | (x)) << MAC_TRC_LANE_SWAP_SEL_LSB) & MAC_TRC_LANE_SWAP_SEL_MASK)
#define MAC_TRC_LANE_SWAP_SEL_RESET                                            0xf
#define MAC_TRC_LANE_SWAP_ADDRESS                                              (0x84 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_LANE_SWAP_RSTMASK                                              0x1f
#define MAC_TRC_LANE_SWAP_RESET                                                0xf

// 0x88 (MAC_TRC_CLK_GATE_DISABLE)
#define MAC_TRC_CLK_GATE_DISABLE_VAL_LSB                                       0
#define MAC_TRC_CLK_GATE_DISABLE_VAL_MSB                                       0
#define MAC_TRC_CLK_GATE_DISABLE_VAL_MASK                                      0x1
#define MAC_TRC_CLK_GATE_DISABLE_VAL_GET(x)                                    (((x) & MAC_TRC_CLK_GATE_DISABLE_VAL_MASK) >> MAC_TRC_CLK_GATE_DISABLE_VAL_LSB)
#define MAC_TRC_CLK_GATE_DISABLE_VAL_SET(x)                                    (((0 | (x)) << MAC_TRC_CLK_GATE_DISABLE_VAL_LSB) & MAC_TRC_CLK_GATE_DISABLE_VAL_MASK)
#define MAC_TRC_CLK_GATE_DISABLE_VAL_RESET                                     0x1
#define MAC_TRC_CLK_GATE_DISABLE_ADDRESS                                       (0x88 + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_CLK_GATE_DISABLE_RSTMASK                                       0x1
#define MAC_TRC_CLK_GATE_DISABLE_RESET                                         0x1

// 0x8c (MAC_TRC_TIME_STAMP)
#define MAC_TRC_TIME_STAMP_SEL_LSB                                             0
#define MAC_TRC_TIME_STAMP_SEL_MSB                                             0
#define MAC_TRC_TIME_STAMP_SEL_MASK                                            0x1
#define MAC_TRC_TIME_STAMP_SEL_GET(x)                                          (((x) & MAC_TRC_TIME_STAMP_SEL_MASK) >> MAC_TRC_TIME_STAMP_SEL_LSB)
#define MAC_TRC_TIME_STAMP_SEL_SET(x)                                          (((0 | (x)) << MAC_TRC_TIME_STAMP_SEL_LSB) & MAC_TRC_TIME_STAMP_SEL_MASK)
#define MAC_TRC_TIME_STAMP_SEL_RESET                                           0x0
#define MAC_TRC_TIME_STAMP_ADDRESS                                             (0x8c + __MAC_TRC_REG_BASE_ADDRESS)
#define MAC_TRC_TIME_STAMP_RSTMASK                                             0x1
#define MAC_TRC_TIME_STAMP_RESET                                               0x0



#endif /* _MAC_TRC_REG_H_ */
