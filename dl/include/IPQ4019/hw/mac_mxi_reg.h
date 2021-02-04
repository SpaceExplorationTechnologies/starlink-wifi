/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _MAC_MXI_REG_H_
#define _MAC_MXI_REG_H_


#ifndef __MAC_MXI_REG_BASE_ADDRESS
#define __MAC_MXI_REG_BASE_ADDRESS (0x3fc00)
#endif


// 0x0 (MXI_CFG_1)
#define MXI_CFG_1_WIFI_MEM_BASE_ADDR_LSB                                       0
#define MXI_CFG_1_WIFI_MEM_BASE_ADDR_MSB                                       31
#define MXI_CFG_1_WIFI_MEM_BASE_ADDR_MASK                                      0xffffffff
#define MXI_CFG_1_WIFI_MEM_BASE_ADDR_GET(x)                                    (((x) & MXI_CFG_1_WIFI_MEM_BASE_ADDR_MASK) >> MXI_CFG_1_WIFI_MEM_BASE_ADDR_LSB)
#define MXI_CFG_1_WIFI_MEM_BASE_ADDR_SET(x)                                    (((0 | (x)) << MXI_CFG_1_WIFI_MEM_BASE_ADDR_LSB) & MXI_CFG_1_WIFI_MEM_BASE_ADDR_MASK)
#define MXI_CFG_1_WIFI_MEM_BASE_ADDR_RESET                                     0x0
#define MXI_CFG_1_ADDRESS                                                      (0x0 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_CFG_1_RSTMASK                                                      0xffffffff
#define MXI_CFG_1_RESET                                                        0x0

// 0x4 (MXI_CFG_2)
#define MXI_CFG_2_WIFI_MEM_BASE_ADDR_MASK_LSB                                  0
#define MXI_CFG_2_WIFI_MEM_BASE_ADDR_MASK_MSB                                  31
#define MXI_CFG_2_WIFI_MEM_BASE_ADDR_MASK_MASK                                 0xffffffff
#define MXI_CFG_2_WIFI_MEM_BASE_ADDR_MASK_GET(x)                               (((x) & MXI_CFG_2_WIFI_MEM_BASE_ADDR_MASK_MASK) >> MXI_CFG_2_WIFI_MEM_BASE_ADDR_MASK_LSB)
#define MXI_CFG_2_WIFI_MEM_BASE_ADDR_MASK_SET(x)                               (((0 | (x)) << MXI_CFG_2_WIFI_MEM_BASE_ADDR_MASK_LSB) & MXI_CFG_2_WIFI_MEM_BASE_ADDR_MASK_MASK)
#define MXI_CFG_2_WIFI_MEM_BASE_ADDR_MASK_RESET                                0x0
#define MXI_CFG_2_ADDRESS                                                      (0x4 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_CFG_2_RSTMASK                                                      0xffffffff
#define MXI_CFG_2_RESET                                                        0x0

// 0x8 (MXI_CFG_3)
#define MXI_CFG_3_APB_BASE_ADDR_LSB                                            0
#define MXI_CFG_3_APB_BASE_ADDR_MSB                                            31
#define MXI_CFG_3_APB_BASE_ADDR_MASK                                           0xffffffff
#define MXI_CFG_3_APB_BASE_ADDR_GET(x)                                         (((x) & MXI_CFG_3_APB_BASE_ADDR_MASK) >> MXI_CFG_3_APB_BASE_ADDR_LSB)
#define MXI_CFG_3_APB_BASE_ADDR_SET(x)                                         (((0 | (x)) << MXI_CFG_3_APB_BASE_ADDR_LSB) & MXI_CFG_3_APB_BASE_ADDR_MASK)
#define MXI_CFG_3_APB_BASE_ADDR_RESET                                          0x0
#define MXI_CFG_3_ADDRESS                                                      (0x8 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_CFG_3_RSTMASK                                                      0xffffffff
#define MXI_CFG_3_RESET                                                        0x0

// 0xc (MXI_CFG_4)
#define MXI_CFG_4_APB_BASE_ADDR_MASK_LSB                                       0
#define MXI_CFG_4_APB_BASE_ADDR_MASK_MSB                                       31
#define MXI_CFG_4_APB_BASE_ADDR_MASK_MASK                                      0xffffffff
#define MXI_CFG_4_APB_BASE_ADDR_MASK_GET(x)                                    (((x) & MXI_CFG_4_APB_BASE_ADDR_MASK_MASK) >> MXI_CFG_4_APB_BASE_ADDR_MASK_LSB)
#define MXI_CFG_4_APB_BASE_ADDR_MASK_SET(x)                                    (((0 | (x)) << MXI_CFG_4_APB_BASE_ADDR_MASK_LSB) & MXI_CFG_4_APB_BASE_ADDR_MASK_MASK)
#define MXI_CFG_4_APB_BASE_ADDR_MASK_RESET                                     0x0
#define MXI_CFG_4_ADDRESS                                                      (0xc + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_CFG_4_RSTMASK                                                      0xffffffff
#define MXI_CFG_4_RESET                                                        0x0

// 0x10 (MXI_CFG_5)
#define MXI_CFG_5_WIFI_MEM_MAX_AXI_RD_BURST_SIZE_LSB                           0
#define MXI_CFG_5_WIFI_MEM_MAX_AXI_RD_BURST_SIZE_MSB                           1
#define MXI_CFG_5_WIFI_MEM_MAX_AXI_RD_BURST_SIZE_MASK                          0x3
#define MXI_CFG_5_WIFI_MEM_MAX_AXI_RD_BURST_SIZE_GET(x)                        (((x) & MXI_CFG_5_WIFI_MEM_MAX_AXI_RD_BURST_SIZE_MASK) >> MXI_CFG_5_WIFI_MEM_MAX_AXI_RD_BURST_SIZE_LSB)
#define MXI_CFG_5_WIFI_MEM_MAX_AXI_RD_BURST_SIZE_SET(x)                        (((0 | (x)) << MXI_CFG_5_WIFI_MEM_MAX_AXI_RD_BURST_SIZE_LSB) & MXI_CFG_5_WIFI_MEM_MAX_AXI_RD_BURST_SIZE_MASK)
#define MXI_CFG_5_WIFI_MEM_MAX_AXI_RD_BURST_SIZE_RESET                         0x0
#define MXI_CFG_5_ADDRESS                                                      (0x10 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_CFG_5_RSTMASK                                                      0x3
#define MXI_CFG_5_RESET                                                        0x0

// 0x14 (MXI_CFG_6)
#define MXI_CFG_6_WIFI_MEM_MAX_AXI_WR_BURST_SIZE_LSB                           0
#define MXI_CFG_6_WIFI_MEM_MAX_AXI_WR_BURST_SIZE_MSB                           1
#define MXI_CFG_6_WIFI_MEM_MAX_AXI_WR_BURST_SIZE_MASK                          0x3
#define MXI_CFG_6_WIFI_MEM_MAX_AXI_WR_BURST_SIZE_GET(x)                        (((x) & MXI_CFG_6_WIFI_MEM_MAX_AXI_WR_BURST_SIZE_MASK) >> MXI_CFG_6_WIFI_MEM_MAX_AXI_WR_BURST_SIZE_LSB)
#define MXI_CFG_6_WIFI_MEM_MAX_AXI_WR_BURST_SIZE_SET(x)                        (((0 | (x)) << MXI_CFG_6_WIFI_MEM_MAX_AXI_WR_BURST_SIZE_LSB) & MXI_CFG_6_WIFI_MEM_MAX_AXI_WR_BURST_SIZE_MASK)
#define MXI_CFG_6_WIFI_MEM_MAX_AXI_WR_BURST_SIZE_RESET                         0x0
#define MXI_CFG_6_ADDRESS                                                      (0x14 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_CFG_6_RSTMASK                                                      0x3
#define MXI_CFG_6_RESET                                                        0x0

// 0x18 (MXI_CFG_7)
#define MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_LSB                           0
#define MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_MSB                           1
#define MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_MASK                          0x3
#define MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_GET(x)                        (((x) & MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_MASK) >> MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_LSB)
#define MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_SET(x)                        (((0 | (x)) << MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_LSB) & MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_MASK)
#define MXI_CFG_7_HOST_MEM_MAX_AXI_RD_BURST_SIZE_RESET                         0x1
#define MXI_CFG_7_ADDRESS                                                      (0x18 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_CFG_7_RSTMASK                                                      0x3
#define MXI_CFG_7_RESET                                                        0x1

// 0x1c (MXI_CFG_8)
#define MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_LSB                           0
#define MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_MSB                           1
#define MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_MASK                          0x3
#define MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_GET(x)                        (((x) & MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_MASK) >> MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_LSB)
#define MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_SET(x)                        (((0 | (x)) << MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_LSB) & MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_MASK)
#define MXI_CFG_8_HOST_MEM_MAX_AXI_WR_BURST_SIZE_RESET                         0x1
#define MXI_CFG_8_ADDRESS                                                      (0x1c + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_CFG_8_RSTMASK                                                      0x3
#define MXI_CFG_8_RESET                                                        0x1

// 0x20 (MXI_CFG_9)
#define MXI_CFG_9_APB_MEM_MAX_AXI_RD_BURST_SIZE_LSB                            0
#define MXI_CFG_9_APB_MEM_MAX_AXI_RD_BURST_SIZE_MSB                            1
#define MXI_CFG_9_APB_MEM_MAX_AXI_RD_BURST_SIZE_MASK                           0x3
#define MXI_CFG_9_APB_MEM_MAX_AXI_RD_BURST_SIZE_GET(x)                         (((x) & MXI_CFG_9_APB_MEM_MAX_AXI_RD_BURST_SIZE_MASK) >> MXI_CFG_9_APB_MEM_MAX_AXI_RD_BURST_SIZE_LSB)
#define MXI_CFG_9_APB_MEM_MAX_AXI_RD_BURST_SIZE_SET(x)                         (((0 | (x)) << MXI_CFG_9_APB_MEM_MAX_AXI_RD_BURST_SIZE_LSB) & MXI_CFG_9_APB_MEM_MAX_AXI_RD_BURST_SIZE_MASK)
#define MXI_CFG_9_APB_MEM_MAX_AXI_RD_BURST_SIZE_RESET                          0x0
#define MXI_CFG_9_ADDRESS                                                      (0x20 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_CFG_9_RSTMASK                                                      0x3
#define MXI_CFG_9_RESET                                                        0x0

// 0x24 (MXI_CFG_10)
#define MXI_CFG_10_APB_MEM_MAX_AXI_WR_BURST_SIZE_LSB                           0
#define MXI_CFG_10_APB_MEM_MAX_AXI_WR_BURST_SIZE_MSB                           1
#define MXI_CFG_10_APB_MEM_MAX_AXI_WR_BURST_SIZE_MASK                          0x3
#define MXI_CFG_10_APB_MEM_MAX_AXI_WR_BURST_SIZE_GET(x)                        (((x) & MXI_CFG_10_APB_MEM_MAX_AXI_WR_BURST_SIZE_MASK) >> MXI_CFG_10_APB_MEM_MAX_AXI_WR_BURST_SIZE_LSB)
#define MXI_CFG_10_APB_MEM_MAX_AXI_WR_BURST_SIZE_SET(x)                        (((0 | (x)) << MXI_CFG_10_APB_MEM_MAX_AXI_WR_BURST_SIZE_LSB) & MXI_CFG_10_APB_MEM_MAX_AXI_WR_BURST_SIZE_MASK)
#define MXI_CFG_10_APB_MEM_MAX_AXI_WR_BURST_SIZE_RESET                         0x0
#define MXI_CFG_10_ADDRESS                                                     (0x24 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_CFG_10_RSTMASK                                                     0x3
#define MXI_CFG_10_RESET                                                       0x0

// 0x28 (MXI_CFG_11)
#define MXI_CFG_11_AXI_TIMER_VALUE_LSB                                         0
#define MXI_CFG_11_AXI_TIMER_VALUE_MSB                                         15
#define MXI_CFG_11_AXI_TIMER_VALUE_MASK                                        0xffff
#define MXI_CFG_11_AXI_TIMER_VALUE_GET(x)                                      (((x) & MXI_CFG_11_AXI_TIMER_VALUE_MASK) >> MXI_CFG_11_AXI_TIMER_VALUE_LSB)
#define MXI_CFG_11_AXI_TIMER_VALUE_SET(x)                                      (((0 | (x)) << MXI_CFG_11_AXI_TIMER_VALUE_LSB) & MXI_CFG_11_AXI_TIMER_VALUE_MASK)
#define MXI_CFG_11_AXI_TIMER_VALUE_RESET                                       0xff
#define MXI_CFG_11_ADDRESS                                                     (0x28 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_CFG_11_RSTMASK                                                     0xffff
#define MXI_CFG_11_RESET                                                       0xff

// 0x2c (MXI_CFG_12)
#define MXI_CFG_12_HALT_REQ_LSB                                                0
#define MXI_CFG_12_HALT_REQ_MSB                                                0
#define MXI_CFG_12_HALT_REQ_MASK                                               0x1
#define MXI_CFG_12_HALT_REQ_GET(x)                                             (((x) & MXI_CFG_12_HALT_REQ_MASK) >> MXI_CFG_12_HALT_REQ_LSB)
#define MXI_CFG_12_HALT_REQ_SET(x)                                             (((0 | (x)) << MXI_CFG_12_HALT_REQ_LSB) & MXI_CFG_12_HALT_REQ_MASK)
#define MXI_CFG_12_HALT_REQ_RESET                                              0x0
#define MXI_CFG_12_ADDRESS                                                     (0x2c + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_CFG_12_RSTMASK                                                     0x1
#define MXI_CFG_12_RESET                                                       0x0

// 0x30 (MXI_STATUS)
#define MXI_STATUS_HALT_ACK_LSB                                                0
#define MXI_STATUS_HALT_ACK_MSB                                                0
#define MXI_STATUS_HALT_ACK_MASK                                               0x1
#define MXI_STATUS_HALT_ACK_GET(x)                                             (((x) & MXI_STATUS_HALT_ACK_MASK) >> MXI_STATUS_HALT_ACK_LSB)
#define MXI_STATUS_HALT_ACK_SET(x)                                             (((0 | (x)) << MXI_STATUS_HALT_ACK_LSB) & MXI_STATUS_HALT_ACK_MASK)
#define MXI_STATUS_HALT_ACK_RESET                                              0x0
#define MXI_STATUS_ADDRESS                                                     (0x30 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_STATUS_RSTMASK                                                     0x1
#define MXI_STATUS_RESET                                                       0x0

// 0x34 (MXI_RD_ERR_RESP)
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_CAUSE_LSB                              8
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_CAUSE_MSB                              9
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_CAUSE_MASK                             0x300
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_CAUSE_GET(x)                           (((x) & MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_CAUSE_MASK) >> MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_CAUSE_LSB)
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_CAUSE_SET(x)                           (((0 | (x)) << MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_CAUSE_LSB) & MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_CAUSE_MASK)
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_CAUSE_RESET                            0x0
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_ID_LSB                            3
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_ID_MSB                            7
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_ID_MASK                           0xf8
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_ID_GET(x)                         (((x) & MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_ID_MASK) >> MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_ID_LSB)
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_ID_SET(x)                         (((0 | (x)) << MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_ID_LSB) & MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_ID_MASK)
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_ID_RESET                          0x0
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_MASTER_LSB                        0
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_MASTER_MSB                        2
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_MASTER_MASK                       0x7
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_MASTER_GET(x)                     (((x) & MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_MASTER_MASK) >> MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_MASTER_LSB)
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_MASTER_SET(x)                     (((0 | (x)) << MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_MASTER_LSB) & MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_MASTER_MASK)
#define MXI_RD_ERR_RESP_AXI_RD_RESP_ERR_ORIG_MASTER_RESET                      0x0
#define MXI_RD_ERR_RESP_ADDRESS                                                (0x34 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_RD_ERR_RESP_RSTMASK                                                0x3ff
#define MXI_RD_ERR_RESP_RESET                                                  0x0

// 0x38 (MXI_WR_ERR_RESP)
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_CAUSE_LSB                              5
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_CAUSE_MSB                              6
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_CAUSE_MASK                             0x60
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_CAUSE_GET(x)                           (((x) & MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_CAUSE_MASK) >> MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_CAUSE_LSB)
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_CAUSE_SET(x)                           (((0 | (x)) << MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_CAUSE_LSB) & MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_CAUSE_MASK)
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_CAUSE_RESET                            0x0
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_ID_LSB                            2
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_ID_MSB                            4
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_ID_MASK                           0x1c
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_ID_GET(x)                         (((x) & MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_ID_MASK) >> MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_ID_LSB)
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_ID_SET(x)                         (((0 | (x)) << MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_ID_LSB) & MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_ID_MASK)
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_ID_RESET                          0x0
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_MASTER_LSB                        0
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_MASTER_MSB                        1
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_MASTER_MASK                       0x3
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_MASTER_GET(x)                     (((x) & MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_MASTER_MASK) >> MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_MASTER_LSB)
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_MASTER_SET(x)                     (((0 | (x)) << MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_MASTER_LSB) & MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_MASTER_MASK)
#define MXI_WR_ERR_RESP_AXI_WR_RESP_ERR_ORIG_MASTER_RESET                      0x0
#define MXI_WR_ERR_RESP_ADDRESS                                                (0x38 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_WR_ERR_RESP_RSTMASK                                                0x7f
#define MXI_WR_ERR_RESP_RESET                                                  0x0

// 0x3c (MXI_DEBUG_CUR_RD_MASTER)
#define MXI_DEBUG_CUR_RD_MASTER_CUR_MXI_RD_MAS_LSB                             0
#define MXI_DEBUG_CUR_RD_MASTER_CUR_MXI_RD_MAS_MSB                             2
#define MXI_DEBUG_CUR_RD_MASTER_CUR_MXI_RD_MAS_MASK                            0x7
#define MXI_DEBUG_CUR_RD_MASTER_CUR_MXI_RD_MAS_GET(x)                          (((x) & MXI_DEBUG_CUR_RD_MASTER_CUR_MXI_RD_MAS_MASK) >> MXI_DEBUG_CUR_RD_MASTER_CUR_MXI_RD_MAS_LSB)
#define MXI_DEBUG_CUR_RD_MASTER_CUR_MXI_RD_MAS_SET(x)                          (((0 | (x)) << MXI_DEBUG_CUR_RD_MASTER_CUR_MXI_RD_MAS_LSB) & MXI_DEBUG_CUR_RD_MASTER_CUR_MXI_RD_MAS_MASK)
#define MXI_DEBUG_CUR_RD_MASTER_CUR_MXI_RD_MAS_RESET                           0x0
#define MXI_DEBUG_CUR_RD_MASTER_ADDRESS                                        (0x3c + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_DEBUG_CUR_RD_MASTER_RSTMASK                                        0x7
#define MXI_DEBUG_CUR_RD_MASTER_RESET                                          0x0

// 0x40 (MXI_DEBUG_CUR_WR_MASTER)
#define MXI_DEBUG_CUR_WR_MASTER_CUR_MXI_WR_MAS_LSB                             0
#define MXI_DEBUG_CUR_WR_MASTER_CUR_MXI_WR_MAS_MSB                             1
#define MXI_DEBUG_CUR_WR_MASTER_CUR_MXI_WR_MAS_MASK                            0x3
#define MXI_DEBUG_CUR_WR_MASTER_CUR_MXI_WR_MAS_GET(x)                          (((x) & MXI_DEBUG_CUR_WR_MASTER_CUR_MXI_WR_MAS_MASK) >> MXI_DEBUG_CUR_WR_MASTER_CUR_MXI_WR_MAS_LSB)
#define MXI_DEBUG_CUR_WR_MASTER_CUR_MXI_WR_MAS_SET(x)                          (((0 | (x)) << MXI_DEBUG_CUR_WR_MASTER_CUR_MXI_WR_MAS_LSB) & MXI_DEBUG_CUR_WR_MASTER_CUR_MXI_WR_MAS_MASK)
#define MXI_DEBUG_CUR_WR_MASTER_CUR_MXI_WR_MAS_RESET                           0x0
#define MXI_DEBUG_CUR_WR_MASTER_ADDRESS                                        (0x40 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_DEBUG_CUR_WR_MASTER_RSTMASK                                        0x3
#define MXI_DEBUG_CUR_WR_MASTER_RESET                                          0x0

// 0x44 (MXI_CLOCK_GATE_DISABLE)
#define MXI_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_LSB                          0
#define MXI_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_MSB                          0
#define MXI_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_MASK                         0x1
#define MXI_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_GET(x)                       (((x) & MXI_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_MASK) >> MXI_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_LSB)
#define MXI_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_SET(x)                       (((0 | (x)) << MXI_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_LSB) & MXI_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_MASK)
#define MXI_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_RESET                        0x1
#define MXI_CLOCK_GATE_DISABLE_ADDRESS                                         (0x44 + __MAC_MXI_REG_BASE_ADDRESS)
#define MXI_CLOCK_GATE_DISABLE_RSTMASK                                         0x1
#define MXI_CLOCK_GATE_DISABLE_RESET                                           0x1



#endif /* _MAC_MXI_REG_H_ */
