/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _MAC_RXDMA_REG_H_
#define _MAC_RXDMA_REG_H_


#ifndef __MAC_RXDMA_REG_BASE_ADDRESS
#define __MAC_RXDMA_REG_BASE_ADDRESS (0x30800)
#endif


// 0x0 (RXDMA_CFG_RING0_0)
#define RXDMA_CFG_RING0_0_BASE_ADDR_LSB                                        0
#define RXDMA_CFG_RING0_0_BASE_ADDR_MSB                                        31
#define RXDMA_CFG_RING0_0_BASE_ADDR_MASK                                       0xffffffff
#define RXDMA_CFG_RING0_0_BASE_ADDR_GET(x)                                     (((x) & RXDMA_CFG_RING0_0_BASE_ADDR_MASK) >> RXDMA_CFG_RING0_0_BASE_ADDR_LSB)
#define RXDMA_CFG_RING0_0_BASE_ADDR_SET(x)                                     (((0 | (x)) << RXDMA_CFG_RING0_0_BASE_ADDR_LSB) & RXDMA_CFG_RING0_0_BASE_ADDR_MASK)
#define RXDMA_CFG_RING0_0_BASE_ADDR_RESET                                      0x0
#define RXDMA_CFG_RING0_0_ADDRESS                                              (0x0 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING0_0_RSTMASK                                              0xffffffff
#define RXDMA_CFG_RING0_0_RESET                                                0x0

// 0x4 (RXDMA_CFG_RING0_1)
#define RXDMA_CFG_RING0_1_BUF_SIZE_LSB                                         16
#define RXDMA_CFG_RING0_1_BUF_SIZE_MSB                                         31
#define RXDMA_CFG_RING0_1_BUF_SIZE_MASK                                        0xffff0000
#define RXDMA_CFG_RING0_1_BUF_SIZE_GET(x)                                      (((x) & RXDMA_CFG_RING0_1_BUF_SIZE_MASK) >> RXDMA_CFG_RING0_1_BUF_SIZE_LSB)
#define RXDMA_CFG_RING0_1_BUF_SIZE_SET(x)                                      (((0 | (x)) << RXDMA_CFG_RING0_1_BUF_SIZE_LSB) & RXDMA_CFG_RING0_1_BUF_SIZE_MASK)
#define RXDMA_CFG_RING0_1_BUF_SIZE_RESET                                       0x0
#define RXDMA_CFG_RING0_1_NUM_DESCS_LSB                                        0
#define RXDMA_CFG_RING0_1_NUM_DESCS_MSB                                        15
#define RXDMA_CFG_RING0_1_NUM_DESCS_MASK                                       0xffff
#define RXDMA_CFG_RING0_1_NUM_DESCS_GET(x)                                     (((x) & RXDMA_CFG_RING0_1_NUM_DESCS_MASK) >> RXDMA_CFG_RING0_1_NUM_DESCS_LSB)
#define RXDMA_CFG_RING0_1_NUM_DESCS_SET(x)                                     (((0 | (x)) << RXDMA_CFG_RING0_1_NUM_DESCS_LSB) & RXDMA_CFG_RING0_1_NUM_DESCS_MASK)
#define RXDMA_CFG_RING0_1_NUM_DESCS_RESET                                      0x0
#define RXDMA_CFG_RING0_1_ADDRESS                                              (0x4 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING0_1_RSTMASK                                              0xffffffff
#define RXDMA_CFG_RING0_1_RESET                                                0x0

// 0x8 (RXDMA_CFG_RING0_2)
#define RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_LSB                                 25
#define RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_MSB                                 25
#define RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_MASK                                0x2000000
#define RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_MASK) >> RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_LSB)
#define RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_LSB) & RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_MASK)
#define RXDMA_CFG_RING0_2_RX_FRAGINFO_SWAP_RESET                               0x0
#define RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_LSB                                24
#define RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_MSB                                24
#define RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_MASK                               0x1000000
#define RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_GET(x)                             (((x) & RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_MASK) >> RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_LSB)
#define RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_SET(x)                             (((0 | (x)) << RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_LSB) & RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_MASK)
#define RXDMA_CFG_RING0_2_RX_ATTENTION_SWAP_RESET                              0x0
#define RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_LSB                                 23
#define RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_MSB                                 23
#define RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_MASK                                0x800000
#define RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_MASK) >> RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_LSB)
#define RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_LSB) & RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_MASK)
#define RXDMA_CFG_RING0_2_RX_MSDU_END_SWAP_RESET                               0x0
#define RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_LSB                               22
#define RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_MSB                               22
#define RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_MASK                              0x400000
#define RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_GET(x)                            (((x) & RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_MASK) >> RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_LSB)
#define RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_LSB) & RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_MASK)
#define RXDMA_CFG_RING0_2_RX_MSDU_START_SWAP_RESET                             0x0
#define RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_LSB                                 21
#define RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_MSB                                 21
#define RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_MASK                                0x200000
#define RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_MASK) >> RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_LSB)
#define RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_LSB) & RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_MASK)
#define RXDMA_CFG_RING0_2_RX_MPDU_END_SWAP_RESET                               0x0
#define RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_LSB                               20
#define RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_MSB                               20
#define RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_MASK                              0x100000
#define RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_GET(x)                            (((x) & RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_MASK) >> RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_LSB)
#define RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_LSB) & RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_MASK)
#define RXDMA_CFG_RING0_2_RX_MPDU_START_SWAP_RESET                             0x0
#define RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_LSB                                 19
#define RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_MSB                                 19
#define RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_MASK                                0x80000
#define RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_MASK) >> RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_LSB)
#define RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_LSB) & RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_MASK)
#define RXDMA_CFG_RING0_2_RX_PPDU_END_SWAP_RESET                               0x0
#define RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_LSB                               18
#define RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_MSB                               18
#define RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_MASK                              0x40000
#define RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_GET(x)                            (((x) & RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_MASK) >> RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_LSB)
#define RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_LSB) & RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_MASK)
#define RXDMA_CFG_RING0_2_RX_PPDU_START_SWAP_RESET                             0x0
#define RXDMA_CFG_RING0_2_RX_PACKET_SWAP_LSB                                   17
#define RXDMA_CFG_RING0_2_RX_PACKET_SWAP_MSB                                   17
#define RXDMA_CFG_RING0_2_RX_PACKET_SWAP_MASK                                  0x20000
#define RXDMA_CFG_RING0_2_RX_PACKET_SWAP_GET(x)                                (((x) & RXDMA_CFG_RING0_2_RX_PACKET_SWAP_MASK) >> RXDMA_CFG_RING0_2_RX_PACKET_SWAP_LSB)
#define RXDMA_CFG_RING0_2_RX_PACKET_SWAP_SET(x)                                (((0 | (x)) << RXDMA_CFG_RING0_2_RX_PACKET_SWAP_LSB) & RXDMA_CFG_RING0_2_RX_PACKET_SWAP_MASK)
#define RXDMA_CFG_RING0_2_RX_PACKET_SWAP_RESET                                 0x0
#define RXDMA_CFG_RING0_2_RX_HEADER_SWAP_LSB                                   16
#define RXDMA_CFG_RING0_2_RX_HEADER_SWAP_MSB                                   16
#define RXDMA_CFG_RING0_2_RX_HEADER_SWAP_MASK                                  0x10000
#define RXDMA_CFG_RING0_2_RX_HEADER_SWAP_GET(x)                                (((x) & RXDMA_CFG_RING0_2_RX_HEADER_SWAP_MASK) >> RXDMA_CFG_RING0_2_RX_HEADER_SWAP_LSB)
#define RXDMA_CFG_RING0_2_RX_HEADER_SWAP_SET(x)                                (((0 | (x)) << RXDMA_CFG_RING0_2_RX_HEADER_SWAP_LSB) & RXDMA_CFG_RING0_2_RX_HEADER_SWAP_MASK)
#define RXDMA_CFG_RING0_2_RX_HEADER_SWAP_RESET                                 0x0
#define RXDMA_CFG_RING0_2_INTR_LWM_THRESH_LSB                                  0
#define RXDMA_CFG_RING0_2_INTR_LWM_THRESH_MSB                                  7
#define RXDMA_CFG_RING0_2_INTR_LWM_THRESH_MASK                                 0xff
#define RXDMA_CFG_RING0_2_INTR_LWM_THRESH_GET(x)                               (((x) & RXDMA_CFG_RING0_2_INTR_LWM_THRESH_MASK) >> RXDMA_CFG_RING0_2_INTR_LWM_THRESH_LSB)
#define RXDMA_CFG_RING0_2_INTR_LWM_THRESH_SET(x)                               (((0 | (x)) << RXDMA_CFG_RING0_2_INTR_LWM_THRESH_LSB) & RXDMA_CFG_RING0_2_INTR_LWM_THRESH_MASK)
#define RXDMA_CFG_RING0_2_INTR_LWM_THRESH_RESET                                0x5
#define RXDMA_CFG_RING0_2_ADDRESS                                              (0x8 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING0_2_RSTMASK                                              0x3ff00ff
#define RXDMA_CFG_RING0_2_RESET                                                0x5

// 0xc (RXDMA_CFG_RING0_3)
#define RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_LSB                                 18
#define RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_MSB                                 25
#define RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_MASK                                0x3fc0000
#define RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_GET(x)                              (((x) & RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_MASK) >> RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_LSB)
#define RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_LSB) & RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_MASK)
#define RXDMA_CFG_RING0_3_RX_PACKET_OFFSET_RESET                               0x0
#define RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_LSB                                 2
#define RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_MSB                                 9
#define RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_MASK                                0x3fc
#define RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_GET(x)                              (((x) & RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_MASK) >> RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_LSB)
#define RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_LSB) & RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_MASK)
#define RXDMA_CFG_RING0_3_RX_HEADER_OFFSET_RESET                               0x0
#define RXDMA_CFG_RING0_3_ADDRESS                                              (0xc + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING0_3_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING0_3_RESET                                                0x0

// 0x10 (RXDMA_CFG_RING0_4)
#define RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_LSB                               18
#define RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_MSB                               25
#define RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_MASK) >> RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_LSB)
#define RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_LSB) & RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_MASK)
#define RXDMA_CFG_RING0_4_RX_PPDU_END_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_LSB                             2
#define RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_MSB                             9
#define RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_MASK                            0x3fc
#define RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_GET(x)                          (((x) & RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_MASK) >> RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_LSB)
#define RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_SET(x)                          (((0 | (x)) << RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_LSB) & RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_MASK)
#define RXDMA_CFG_RING0_4_RX_PPDU_START_OFFSET_RESET                           0x0
#define RXDMA_CFG_RING0_4_ADDRESS                                              (0x10 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING0_4_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING0_4_RESET                                                0x0

// 0x14 (RXDMA_CFG_RING0_5)
#define RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_LSB                               18
#define RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_MSB                               25
#define RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_MASK) >> RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_LSB)
#define RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_LSB) & RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_MASK)
#define RXDMA_CFG_RING0_5_RX_MPDU_END_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_LSB                             2
#define RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_MSB                             9
#define RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_MASK                            0x3fc
#define RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_GET(x)                          (((x) & RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_MASK) >> RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_LSB)
#define RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_SET(x)                          (((0 | (x)) << RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_LSB) & RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_MASK)
#define RXDMA_CFG_RING0_5_RX_MPDU_START_OFFSET_RESET                           0x0
#define RXDMA_CFG_RING0_5_ADDRESS                                              (0x14 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING0_5_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING0_5_RESET                                                0x0

// 0x18 (RXDMA_CFG_RING0_6)
#define RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_LSB                               18
#define RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_MSB                               25
#define RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_MASK) >> RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_LSB)
#define RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_LSB) & RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_MASK)
#define RXDMA_CFG_RING0_6_RX_MSDU_END_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_LSB                             2
#define RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_MSB                             9
#define RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_MASK                            0x3fc
#define RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_GET(x)                          (((x) & RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_MASK) >> RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_LSB)
#define RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_SET(x)                          (((0 | (x)) << RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_LSB) & RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_MASK)
#define RXDMA_CFG_RING0_6_RX_MSDU_START_OFFSET_RESET                           0x0
#define RXDMA_CFG_RING0_6_ADDRESS                                              (0x18 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING0_6_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING0_6_RESET                                                0x0

// 0x1c (RXDMA_CFG_RING0_7)
#define RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_LSB                               18
#define RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_MSB                               25
#define RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_MASK) >> RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_LSB)
#define RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_LSB) & RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_MASK)
#define RXDMA_CFG_RING0_7_RX_FRAGINFO_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_LSB                              2
#define RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_MSB                              9
#define RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_MASK                             0x3fc
#define RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_GET(x)                           (((x) & RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_MASK) >> RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_LSB)
#define RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_SET(x)                           (((0 | (x)) << RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_LSB) & RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_MASK)
#define RXDMA_CFG_RING0_7_RX_ATTENTION_OFFSET_RESET                            0x0
#define RXDMA_CFG_RING0_7_ADDRESS                                              (0x1c + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING0_7_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING0_7_RESET                                                0x0

// 0x20 (RXDMA_CFG_RING1_0)
#define RXDMA_CFG_RING1_0_BASE_ADDR_LSB                                        0
#define RXDMA_CFG_RING1_0_BASE_ADDR_MSB                                        31
#define RXDMA_CFG_RING1_0_BASE_ADDR_MASK                                       0xffffffff
#define RXDMA_CFG_RING1_0_BASE_ADDR_GET(x)                                     (((x) & RXDMA_CFG_RING1_0_BASE_ADDR_MASK) >> RXDMA_CFG_RING1_0_BASE_ADDR_LSB)
#define RXDMA_CFG_RING1_0_BASE_ADDR_SET(x)                                     (((0 | (x)) << RXDMA_CFG_RING1_0_BASE_ADDR_LSB) & RXDMA_CFG_RING1_0_BASE_ADDR_MASK)
#define RXDMA_CFG_RING1_0_BASE_ADDR_RESET                                      0x0
#define RXDMA_CFG_RING1_0_ADDRESS                                              (0x20 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING1_0_RSTMASK                                              0xffffffff
#define RXDMA_CFG_RING1_0_RESET                                                0x0

// 0x24 (RXDMA_CFG_RING1_1)
#define RXDMA_CFG_RING1_1_BUF_SIZE_LSB                                         16
#define RXDMA_CFG_RING1_1_BUF_SIZE_MSB                                         31
#define RXDMA_CFG_RING1_1_BUF_SIZE_MASK                                        0xffff0000
#define RXDMA_CFG_RING1_1_BUF_SIZE_GET(x)                                      (((x) & RXDMA_CFG_RING1_1_BUF_SIZE_MASK) >> RXDMA_CFG_RING1_1_BUF_SIZE_LSB)
#define RXDMA_CFG_RING1_1_BUF_SIZE_SET(x)                                      (((0 | (x)) << RXDMA_CFG_RING1_1_BUF_SIZE_LSB) & RXDMA_CFG_RING1_1_BUF_SIZE_MASK)
#define RXDMA_CFG_RING1_1_BUF_SIZE_RESET                                       0x0
#define RXDMA_CFG_RING1_1_NUM_DESCS_LSB                                        0
#define RXDMA_CFG_RING1_1_NUM_DESCS_MSB                                        15
#define RXDMA_CFG_RING1_1_NUM_DESCS_MASK                                       0xffff
#define RXDMA_CFG_RING1_1_NUM_DESCS_GET(x)                                     (((x) & RXDMA_CFG_RING1_1_NUM_DESCS_MASK) >> RXDMA_CFG_RING1_1_NUM_DESCS_LSB)
#define RXDMA_CFG_RING1_1_NUM_DESCS_SET(x)                                     (((0 | (x)) << RXDMA_CFG_RING1_1_NUM_DESCS_LSB) & RXDMA_CFG_RING1_1_NUM_DESCS_MASK)
#define RXDMA_CFG_RING1_1_NUM_DESCS_RESET                                      0x0
#define RXDMA_CFG_RING1_1_ADDRESS                                              (0x24 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING1_1_RSTMASK                                              0xffffffff
#define RXDMA_CFG_RING1_1_RESET                                                0x0

// 0x28 (RXDMA_CFG_RING1_2)
#define RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_LSB                                 25
#define RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_MSB                                 25
#define RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_MASK                                0x2000000
#define RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_MASK) >> RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_LSB)
#define RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_LSB) & RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_MASK)
#define RXDMA_CFG_RING1_2_RX_FRAGINFO_SWAP_RESET                               0x0
#define RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_LSB                                24
#define RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_MSB                                24
#define RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_MASK                               0x1000000
#define RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_GET(x)                             (((x) & RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_MASK) >> RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_LSB)
#define RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_SET(x)                             (((0 | (x)) << RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_LSB) & RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_MASK)
#define RXDMA_CFG_RING1_2_RX_ATTENTION_SWAP_RESET                              0x0
#define RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_LSB                                 23
#define RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_MSB                                 23
#define RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_MASK                                0x800000
#define RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_MASK) >> RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_LSB)
#define RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_LSB) & RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_MASK)
#define RXDMA_CFG_RING1_2_RX_MSDU_END_SWAP_RESET                               0x0
#define RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_LSB                               22
#define RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_MSB                               22
#define RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_MASK                              0x400000
#define RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_GET(x)                            (((x) & RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_MASK) >> RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_LSB)
#define RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_LSB) & RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_MASK)
#define RXDMA_CFG_RING1_2_RX_MSDU_START_SWAP_RESET                             0x0
#define RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_LSB                                 21
#define RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_MSB                                 21
#define RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_MASK                                0x200000
#define RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_MASK) >> RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_LSB)
#define RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_LSB) & RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_MASK)
#define RXDMA_CFG_RING1_2_RX_MPDU_END_SWAP_RESET                               0x0
#define RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_LSB                               20
#define RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_MSB                               20
#define RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_MASK                              0x100000
#define RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_GET(x)                            (((x) & RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_MASK) >> RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_LSB)
#define RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_LSB) & RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_MASK)
#define RXDMA_CFG_RING1_2_RX_MPDU_START_SWAP_RESET                             0x0
#define RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_LSB                                 19
#define RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_MSB                                 19
#define RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_MASK                                0x80000
#define RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_MASK) >> RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_LSB)
#define RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_LSB) & RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_MASK)
#define RXDMA_CFG_RING1_2_RX_PPDU_END_SWAP_RESET                               0x0
#define RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_LSB                               18
#define RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_MSB                               18
#define RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_MASK                              0x40000
#define RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_GET(x)                            (((x) & RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_MASK) >> RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_LSB)
#define RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_LSB) & RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_MASK)
#define RXDMA_CFG_RING1_2_RX_PPDU_START_SWAP_RESET                             0x0
#define RXDMA_CFG_RING1_2_RX_PACKET_SWAP_LSB                                   17
#define RXDMA_CFG_RING1_2_RX_PACKET_SWAP_MSB                                   17
#define RXDMA_CFG_RING1_2_RX_PACKET_SWAP_MASK                                  0x20000
#define RXDMA_CFG_RING1_2_RX_PACKET_SWAP_GET(x)                                (((x) & RXDMA_CFG_RING1_2_RX_PACKET_SWAP_MASK) >> RXDMA_CFG_RING1_2_RX_PACKET_SWAP_LSB)
#define RXDMA_CFG_RING1_2_RX_PACKET_SWAP_SET(x)                                (((0 | (x)) << RXDMA_CFG_RING1_2_RX_PACKET_SWAP_LSB) & RXDMA_CFG_RING1_2_RX_PACKET_SWAP_MASK)
#define RXDMA_CFG_RING1_2_RX_PACKET_SWAP_RESET                                 0x0
#define RXDMA_CFG_RING1_2_RX_HEADER_SWAP_LSB                                   16
#define RXDMA_CFG_RING1_2_RX_HEADER_SWAP_MSB                                   16
#define RXDMA_CFG_RING1_2_RX_HEADER_SWAP_MASK                                  0x10000
#define RXDMA_CFG_RING1_2_RX_HEADER_SWAP_GET(x)                                (((x) & RXDMA_CFG_RING1_2_RX_HEADER_SWAP_MASK) >> RXDMA_CFG_RING1_2_RX_HEADER_SWAP_LSB)
#define RXDMA_CFG_RING1_2_RX_HEADER_SWAP_SET(x)                                (((0 | (x)) << RXDMA_CFG_RING1_2_RX_HEADER_SWAP_LSB) & RXDMA_CFG_RING1_2_RX_HEADER_SWAP_MASK)
#define RXDMA_CFG_RING1_2_RX_HEADER_SWAP_RESET                                 0x0
#define RXDMA_CFG_RING1_2_INTR_LWM_THRESH_LSB                                  0
#define RXDMA_CFG_RING1_2_INTR_LWM_THRESH_MSB                                  7
#define RXDMA_CFG_RING1_2_INTR_LWM_THRESH_MASK                                 0xff
#define RXDMA_CFG_RING1_2_INTR_LWM_THRESH_GET(x)                               (((x) & RXDMA_CFG_RING1_2_INTR_LWM_THRESH_MASK) >> RXDMA_CFG_RING1_2_INTR_LWM_THRESH_LSB)
#define RXDMA_CFG_RING1_2_INTR_LWM_THRESH_SET(x)                               (((0 | (x)) << RXDMA_CFG_RING1_2_INTR_LWM_THRESH_LSB) & RXDMA_CFG_RING1_2_INTR_LWM_THRESH_MASK)
#define RXDMA_CFG_RING1_2_INTR_LWM_THRESH_RESET                                0x5
#define RXDMA_CFG_RING1_2_ADDRESS                                              (0x28 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING1_2_RSTMASK                                              0x3ff00ff
#define RXDMA_CFG_RING1_2_RESET                                                0x5

// 0x2c (RXDMA_CFG_RING1_3)
#define RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_LSB                                 18
#define RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_MSB                                 25
#define RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_MASK                                0x3fc0000
#define RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_GET(x)                              (((x) & RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_MASK) >> RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_LSB)
#define RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_LSB) & RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_MASK)
#define RXDMA_CFG_RING1_3_RX_PACKET_OFFSET_RESET                               0x0
#define RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_LSB                                 2
#define RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_MSB                                 9
#define RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_MASK                                0x3fc
#define RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_GET(x)                              (((x) & RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_MASK) >> RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_LSB)
#define RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_LSB) & RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_MASK)
#define RXDMA_CFG_RING1_3_RX_HEADER_OFFSET_RESET                               0x0
#define RXDMA_CFG_RING1_3_ADDRESS                                              (0x2c + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING1_3_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING1_3_RESET                                                0x0

// 0x30 (RXDMA_CFG_RING1_4)
#define RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_LSB                               18
#define RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_MSB                               25
#define RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_MASK) >> RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_LSB)
#define RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_LSB) & RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_MASK)
#define RXDMA_CFG_RING1_4_RX_PPDU_END_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_LSB                             2
#define RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_MSB                             9
#define RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_MASK                            0x3fc
#define RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_GET(x)                          (((x) & RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_MASK) >> RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_LSB)
#define RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_SET(x)                          (((0 | (x)) << RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_LSB) & RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_MASK)
#define RXDMA_CFG_RING1_4_RX_PPDU_START_OFFSET_RESET                           0x0
#define RXDMA_CFG_RING1_4_ADDRESS                                              (0x30 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING1_4_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING1_4_RESET                                                0x0

// 0x34 (RXDMA_CFG_RING1_5)
#define RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_LSB                               18
#define RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_MSB                               25
#define RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_MASK) >> RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_LSB)
#define RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_LSB) & RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_MASK)
#define RXDMA_CFG_RING1_5_RX_MPDU_END_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_LSB                             2
#define RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_MSB                             9
#define RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_MASK                            0x3fc
#define RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_GET(x)                          (((x) & RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_MASK) >> RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_LSB)
#define RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_SET(x)                          (((0 | (x)) << RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_LSB) & RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_MASK)
#define RXDMA_CFG_RING1_5_RX_MPDU_START_OFFSET_RESET                           0x0
#define RXDMA_CFG_RING1_5_ADDRESS                                              (0x34 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING1_5_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING1_5_RESET                                                0x0

// 0x38 (RXDMA_CFG_RING1_6)
#define RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_LSB                               18
#define RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_MSB                               25
#define RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_MASK) >> RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_LSB)
#define RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_LSB) & RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_MASK)
#define RXDMA_CFG_RING1_6_RX_MSDU_END_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_LSB                             2
#define RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_MSB                             9
#define RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_MASK                            0x3fc
#define RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_GET(x)                          (((x) & RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_MASK) >> RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_LSB)
#define RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_SET(x)                          (((0 | (x)) << RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_LSB) & RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_MASK)
#define RXDMA_CFG_RING1_6_RX_MSDU_START_OFFSET_RESET                           0x0
#define RXDMA_CFG_RING1_6_ADDRESS                                              (0x38 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING1_6_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING1_6_RESET                                                0x0

// 0x3c (RXDMA_CFG_RING1_7)
#define RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_LSB                               18
#define RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_MSB                               25
#define RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_MASK) >> RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_LSB)
#define RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_LSB) & RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_MASK)
#define RXDMA_CFG_RING1_7_RX_FRAGINFO_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_LSB                              2
#define RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_MSB                              9
#define RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_MASK                             0x3fc
#define RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_GET(x)                           (((x) & RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_MASK) >> RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_LSB)
#define RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_SET(x)                           (((0 | (x)) << RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_LSB) & RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_MASK)
#define RXDMA_CFG_RING1_7_RX_ATTENTION_OFFSET_RESET                            0x0
#define RXDMA_CFG_RING1_7_ADDRESS                                              (0x3c + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING1_7_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING1_7_RESET                                                0x0

// 0x40 (RXDMA_CFG_RING2_0)
#define RXDMA_CFG_RING2_0_BASE_ADDR_LSB                                        0
#define RXDMA_CFG_RING2_0_BASE_ADDR_MSB                                        31
#define RXDMA_CFG_RING2_0_BASE_ADDR_MASK                                       0xffffffff
#define RXDMA_CFG_RING2_0_BASE_ADDR_GET(x)                                     (((x) & RXDMA_CFG_RING2_0_BASE_ADDR_MASK) >> RXDMA_CFG_RING2_0_BASE_ADDR_LSB)
#define RXDMA_CFG_RING2_0_BASE_ADDR_SET(x)                                     (((0 | (x)) << RXDMA_CFG_RING2_0_BASE_ADDR_LSB) & RXDMA_CFG_RING2_0_BASE_ADDR_MASK)
#define RXDMA_CFG_RING2_0_BASE_ADDR_RESET                                      0x0
#define RXDMA_CFG_RING2_0_ADDRESS                                              (0x40 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING2_0_RSTMASK                                              0xffffffff
#define RXDMA_CFG_RING2_0_RESET                                                0x0

// 0x44 (RXDMA_CFG_RING2_1)
#define RXDMA_CFG_RING2_1_BUF_SIZE_LSB                                         16
#define RXDMA_CFG_RING2_1_BUF_SIZE_MSB                                         31
#define RXDMA_CFG_RING2_1_BUF_SIZE_MASK                                        0xffff0000
#define RXDMA_CFG_RING2_1_BUF_SIZE_GET(x)                                      (((x) & RXDMA_CFG_RING2_1_BUF_SIZE_MASK) >> RXDMA_CFG_RING2_1_BUF_SIZE_LSB)
#define RXDMA_CFG_RING2_1_BUF_SIZE_SET(x)                                      (((0 | (x)) << RXDMA_CFG_RING2_1_BUF_SIZE_LSB) & RXDMA_CFG_RING2_1_BUF_SIZE_MASK)
#define RXDMA_CFG_RING2_1_BUF_SIZE_RESET                                       0x0
#define RXDMA_CFG_RING2_1_NUM_DESCS_LSB                                        0
#define RXDMA_CFG_RING2_1_NUM_DESCS_MSB                                        15
#define RXDMA_CFG_RING2_1_NUM_DESCS_MASK                                       0xffff
#define RXDMA_CFG_RING2_1_NUM_DESCS_GET(x)                                     (((x) & RXDMA_CFG_RING2_1_NUM_DESCS_MASK) >> RXDMA_CFG_RING2_1_NUM_DESCS_LSB)
#define RXDMA_CFG_RING2_1_NUM_DESCS_SET(x)                                     (((0 | (x)) << RXDMA_CFG_RING2_1_NUM_DESCS_LSB) & RXDMA_CFG_RING2_1_NUM_DESCS_MASK)
#define RXDMA_CFG_RING2_1_NUM_DESCS_RESET                                      0x0
#define RXDMA_CFG_RING2_1_ADDRESS                                              (0x44 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING2_1_RSTMASK                                              0xffffffff
#define RXDMA_CFG_RING2_1_RESET                                                0x0

// 0x48 (RXDMA_CFG_RING2_2)
#define RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_LSB                                 25
#define RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_MSB                                 25
#define RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_MASK                                0x2000000
#define RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_MASK) >> RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_LSB)
#define RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_LSB) & RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_MASK)
#define RXDMA_CFG_RING2_2_RX_FRAGINFO_SWAP_RESET                               0x0
#define RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_LSB                                24
#define RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_MSB                                24
#define RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_MASK                               0x1000000
#define RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_GET(x)                             (((x) & RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_MASK) >> RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_LSB)
#define RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_SET(x)                             (((0 | (x)) << RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_LSB) & RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_MASK)
#define RXDMA_CFG_RING2_2_RX_ATTENTION_SWAP_RESET                              0x0
#define RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_LSB                                 23
#define RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_MSB                                 23
#define RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_MASK                                0x800000
#define RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_MASK) >> RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_LSB)
#define RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_LSB) & RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_MASK)
#define RXDMA_CFG_RING2_2_RX_MSDU_END_SWAP_RESET                               0x0
#define RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_LSB                               22
#define RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_MSB                               22
#define RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_MASK                              0x400000
#define RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_GET(x)                            (((x) & RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_MASK) >> RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_LSB)
#define RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_LSB) & RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_MASK)
#define RXDMA_CFG_RING2_2_RX_MSDU_START_SWAP_RESET                             0x0
#define RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_LSB                                 21
#define RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_MSB                                 21
#define RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_MASK                                0x200000
#define RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_MASK) >> RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_LSB)
#define RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_LSB) & RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_MASK)
#define RXDMA_CFG_RING2_2_RX_MPDU_END_SWAP_RESET                               0x0
#define RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_LSB                               20
#define RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_MSB                               20
#define RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_MASK                              0x100000
#define RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_GET(x)                            (((x) & RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_MASK) >> RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_LSB)
#define RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_LSB) & RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_MASK)
#define RXDMA_CFG_RING2_2_RX_MPDU_START_SWAP_RESET                             0x0
#define RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_LSB                                 19
#define RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_MSB                                 19
#define RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_MASK                                0x80000
#define RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_MASK) >> RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_LSB)
#define RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_LSB) & RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_MASK)
#define RXDMA_CFG_RING2_2_RX_PPDU_END_SWAP_RESET                               0x0
#define RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_LSB                               18
#define RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_MSB                               18
#define RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_MASK                              0x40000
#define RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_GET(x)                            (((x) & RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_MASK) >> RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_LSB)
#define RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_LSB) & RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_MASK)
#define RXDMA_CFG_RING2_2_RX_PPDU_START_SWAP_RESET                             0x0
#define RXDMA_CFG_RING2_2_RX_PACKET_SWAP_LSB                                   17
#define RXDMA_CFG_RING2_2_RX_PACKET_SWAP_MSB                                   17
#define RXDMA_CFG_RING2_2_RX_PACKET_SWAP_MASK                                  0x20000
#define RXDMA_CFG_RING2_2_RX_PACKET_SWAP_GET(x)                                (((x) & RXDMA_CFG_RING2_2_RX_PACKET_SWAP_MASK) >> RXDMA_CFG_RING2_2_RX_PACKET_SWAP_LSB)
#define RXDMA_CFG_RING2_2_RX_PACKET_SWAP_SET(x)                                (((0 | (x)) << RXDMA_CFG_RING2_2_RX_PACKET_SWAP_LSB) & RXDMA_CFG_RING2_2_RX_PACKET_SWAP_MASK)
#define RXDMA_CFG_RING2_2_RX_PACKET_SWAP_RESET                                 0x0
#define RXDMA_CFG_RING2_2_RX_HEADER_SWAP_LSB                                   16
#define RXDMA_CFG_RING2_2_RX_HEADER_SWAP_MSB                                   16
#define RXDMA_CFG_RING2_2_RX_HEADER_SWAP_MASK                                  0x10000
#define RXDMA_CFG_RING2_2_RX_HEADER_SWAP_GET(x)                                (((x) & RXDMA_CFG_RING2_2_RX_HEADER_SWAP_MASK) >> RXDMA_CFG_RING2_2_RX_HEADER_SWAP_LSB)
#define RXDMA_CFG_RING2_2_RX_HEADER_SWAP_SET(x)                                (((0 | (x)) << RXDMA_CFG_RING2_2_RX_HEADER_SWAP_LSB) & RXDMA_CFG_RING2_2_RX_HEADER_SWAP_MASK)
#define RXDMA_CFG_RING2_2_RX_HEADER_SWAP_RESET                                 0x0
#define RXDMA_CFG_RING2_2_INTR_LWM_THRESH_LSB                                  0
#define RXDMA_CFG_RING2_2_INTR_LWM_THRESH_MSB                                  7
#define RXDMA_CFG_RING2_2_INTR_LWM_THRESH_MASK                                 0xff
#define RXDMA_CFG_RING2_2_INTR_LWM_THRESH_GET(x)                               (((x) & RXDMA_CFG_RING2_2_INTR_LWM_THRESH_MASK) >> RXDMA_CFG_RING2_2_INTR_LWM_THRESH_LSB)
#define RXDMA_CFG_RING2_2_INTR_LWM_THRESH_SET(x)                               (((0 | (x)) << RXDMA_CFG_RING2_2_INTR_LWM_THRESH_LSB) & RXDMA_CFG_RING2_2_INTR_LWM_THRESH_MASK)
#define RXDMA_CFG_RING2_2_INTR_LWM_THRESH_RESET                                0x5
#define RXDMA_CFG_RING2_2_ADDRESS                                              (0x48 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING2_2_RSTMASK                                              0x3ff00ff
#define RXDMA_CFG_RING2_2_RESET                                                0x5

// 0x4c (RXDMA_CFG_RING2_3)
#define RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_LSB                                 18
#define RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_MSB                                 25
#define RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_MASK                                0x3fc0000
#define RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_GET(x)                              (((x) & RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_MASK) >> RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_LSB)
#define RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_LSB) & RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_MASK)
#define RXDMA_CFG_RING2_3_RX_PACKET_OFFSET_RESET                               0x0
#define RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_LSB                                 2
#define RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_MSB                                 9
#define RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_MASK                                0x3fc
#define RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_GET(x)                              (((x) & RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_MASK) >> RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_LSB)
#define RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_LSB) & RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_MASK)
#define RXDMA_CFG_RING2_3_RX_HEADER_OFFSET_RESET                               0x0
#define RXDMA_CFG_RING2_3_ADDRESS                                              (0x4c + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING2_3_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING2_3_RESET                                                0x0

// 0x50 (RXDMA_CFG_RING2_4)
#define RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_LSB                               18
#define RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_MSB                               25
#define RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_MASK) >> RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_LSB)
#define RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_LSB) & RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_MASK)
#define RXDMA_CFG_RING2_4_RX_PPDU_END_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_LSB                             2
#define RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_MSB                             9
#define RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_MASK                            0x3fc
#define RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_GET(x)                          (((x) & RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_MASK) >> RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_LSB)
#define RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_SET(x)                          (((0 | (x)) << RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_LSB) & RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_MASK)
#define RXDMA_CFG_RING2_4_RX_PPDU_START_OFFSET_RESET                           0x0
#define RXDMA_CFG_RING2_4_ADDRESS                                              (0x50 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING2_4_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING2_4_RESET                                                0x0

// 0x54 (RXDMA_CFG_RING2_5)
#define RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_LSB                               18
#define RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_MSB                               25
#define RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_MASK) >> RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_LSB)
#define RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_LSB) & RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_MASK)
#define RXDMA_CFG_RING2_5_RX_MPDU_END_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_LSB                             2
#define RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_MSB                             9
#define RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_MASK                            0x3fc
#define RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_GET(x)                          (((x) & RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_MASK) >> RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_LSB)
#define RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_SET(x)                          (((0 | (x)) << RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_LSB) & RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_MASK)
#define RXDMA_CFG_RING2_5_RX_MPDU_START_OFFSET_RESET                           0x0
#define RXDMA_CFG_RING2_5_ADDRESS                                              (0x54 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING2_5_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING2_5_RESET                                                0x0

// 0x58 (RXDMA_CFG_RING2_6)
#define RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_LSB                               18
#define RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_MSB                               25
#define RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_MASK) >> RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_LSB)
#define RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_LSB) & RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_MASK)
#define RXDMA_CFG_RING2_6_RX_MSDU_END_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_LSB                             2
#define RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_MSB                             9
#define RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_MASK                            0x3fc
#define RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_GET(x)                          (((x) & RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_MASK) >> RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_LSB)
#define RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_SET(x)                          (((0 | (x)) << RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_LSB) & RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_MASK)
#define RXDMA_CFG_RING2_6_RX_MSDU_START_OFFSET_RESET                           0x0
#define RXDMA_CFG_RING2_6_ADDRESS                                              (0x58 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING2_6_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING2_6_RESET                                                0x0

// 0x5c (RXDMA_CFG_RING2_7)
#define RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_LSB                               18
#define RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_MSB                               25
#define RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_MASK) >> RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_LSB)
#define RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_LSB) & RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_MASK)
#define RXDMA_CFG_RING2_7_RX_FRAGINFO_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_LSB                              2
#define RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_MSB                              9
#define RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_MASK                             0x3fc
#define RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_GET(x)                           (((x) & RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_MASK) >> RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_LSB)
#define RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_SET(x)                           (((0 | (x)) << RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_LSB) & RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_MASK)
#define RXDMA_CFG_RING2_7_RX_ATTENTION_OFFSET_RESET                            0x0
#define RXDMA_CFG_RING2_7_ADDRESS                                              (0x5c + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING2_7_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING2_7_RESET                                                0x0

// 0x60 (RXDMA_CFG_RING3_0)
#define RXDMA_CFG_RING3_0_BASE_ADDR_LSB                                        0
#define RXDMA_CFG_RING3_0_BASE_ADDR_MSB                                        31
#define RXDMA_CFG_RING3_0_BASE_ADDR_MASK                                       0xffffffff
#define RXDMA_CFG_RING3_0_BASE_ADDR_GET(x)                                     (((x) & RXDMA_CFG_RING3_0_BASE_ADDR_MASK) >> RXDMA_CFG_RING3_0_BASE_ADDR_LSB)
#define RXDMA_CFG_RING3_0_BASE_ADDR_SET(x)                                     (((0 | (x)) << RXDMA_CFG_RING3_0_BASE_ADDR_LSB) & RXDMA_CFG_RING3_0_BASE_ADDR_MASK)
#define RXDMA_CFG_RING3_0_BASE_ADDR_RESET                                      0x0
#define RXDMA_CFG_RING3_0_ADDRESS                                              (0x60 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING3_0_RSTMASK                                              0xffffffff
#define RXDMA_CFG_RING3_0_RESET                                                0x0

// 0x64 (RXDMA_CFG_RING3_1)
#define RXDMA_CFG_RING3_1_BUF_SIZE_LSB                                         16
#define RXDMA_CFG_RING3_1_BUF_SIZE_MSB                                         31
#define RXDMA_CFG_RING3_1_BUF_SIZE_MASK                                        0xffff0000
#define RXDMA_CFG_RING3_1_BUF_SIZE_GET(x)                                      (((x) & RXDMA_CFG_RING3_1_BUF_SIZE_MASK) >> RXDMA_CFG_RING3_1_BUF_SIZE_LSB)
#define RXDMA_CFG_RING3_1_BUF_SIZE_SET(x)                                      (((0 | (x)) << RXDMA_CFG_RING3_1_BUF_SIZE_LSB) & RXDMA_CFG_RING3_1_BUF_SIZE_MASK)
#define RXDMA_CFG_RING3_1_BUF_SIZE_RESET                                       0x0
#define RXDMA_CFG_RING3_1_NUM_DESCS_LSB                                        0
#define RXDMA_CFG_RING3_1_NUM_DESCS_MSB                                        15
#define RXDMA_CFG_RING3_1_NUM_DESCS_MASK                                       0xffff
#define RXDMA_CFG_RING3_1_NUM_DESCS_GET(x)                                     (((x) & RXDMA_CFG_RING3_1_NUM_DESCS_MASK) >> RXDMA_CFG_RING3_1_NUM_DESCS_LSB)
#define RXDMA_CFG_RING3_1_NUM_DESCS_SET(x)                                     (((0 | (x)) << RXDMA_CFG_RING3_1_NUM_DESCS_LSB) & RXDMA_CFG_RING3_1_NUM_DESCS_MASK)
#define RXDMA_CFG_RING3_1_NUM_DESCS_RESET                                      0x0
#define RXDMA_CFG_RING3_1_ADDRESS                                              (0x64 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING3_1_RSTMASK                                              0xffffffff
#define RXDMA_CFG_RING3_1_RESET                                                0x0

// 0x68 (RXDMA_CFG_RING3_2)
#define RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_LSB                                 25
#define RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_MSB                                 25
#define RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_MASK                                0x2000000
#define RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_MASK) >> RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_LSB)
#define RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_LSB) & RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_MASK)
#define RXDMA_CFG_RING3_2_RX_FRAGINFO_SWAP_RESET                               0x0
#define RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_LSB                                24
#define RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_MSB                                24
#define RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_MASK                               0x1000000
#define RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_GET(x)                             (((x) & RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_MASK) >> RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_LSB)
#define RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_SET(x)                             (((0 | (x)) << RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_LSB) & RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_MASK)
#define RXDMA_CFG_RING3_2_RX_ATTENTION_SWAP_RESET                              0x0
#define RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_LSB                                 23
#define RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_MSB                                 23
#define RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_MASK                                0x800000
#define RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_MASK) >> RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_LSB)
#define RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_LSB) & RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_MASK)
#define RXDMA_CFG_RING3_2_RX_MSDU_END_SWAP_RESET                               0x0
#define RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_LSB                               22
#define RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_MSB                               22
#define RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_MASK                              0x400000
#define RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_GET(x)                            (((x) & RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_MASK) >> RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_LSB)
#define RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_LSB) & RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_MASK)
#define RXDMA_CFG_RING3_2_RX_MSDU_START_SWAP_RESET                             0x0
#define RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_LSB                                 21
#define RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_MSB                                 21
#define RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_MASK                                0x200000
#define RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_MASK) >> RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_LSB)
#define RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_LSB) & RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_MASK)
#define RXDMA_CFG_RING3_2_RX_MPDU_END_SWAP_RESET                               0x0
#define RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_LSB                               20
#define RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_MSB                               20
#define RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_MASK                              0x100000
#define RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_GET(x)                            (((x) & RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_MASK) >> RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_LSB)
#define RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_LSB) & RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_MASK)
#define RXDMA_CFG_RING3_2_RX_MPDU_START_SWAP_RESET                             0x0
#define RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_LSB                                 19
#define RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_MSB                                 19
#define RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_MASK                                0x80000
#define RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_GET(x)                              (((x) & RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_MASK) >> RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_LSB)
#define RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_LSB) & RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_MASK)
#define RXDMA_CFG_RING3_2_RX_PPDU_END_SWAP_RESET                               0x0
#define RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_LSB                               18
#define RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_MSB                               18
#define RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_MASK                              0x40000
#define RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_GET(x)                            (((x) & RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_MASK) >> RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_LSB)
#define RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_LSB) & RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_MASK)
#define RXDMA_CFG_RING3_2_RX_PPDU_START_SWAP_RESET                             0x0
#define RXDMA_CFG_RING3_2_RX_PACKET_SWAP_LSB                                   17
#define RXDMA_CFG_RING3_2_RX_PACKET_SWAP_MSB                                   17
#define RXDMA_CFG_RING3_2_RX_PACKET_SWAP_MASK                                  0x20000
#define RXDMA_CFG_RING3_2_RX_PACKET_SWAP_GET(x)                                (((x) & RXDMA_CFG_RING3_2_RX_PACKET_SWAP_MASK) >> RXDMA_CFG_RING3_2_RX_PACKET_SWAP_LSB)
#define RXDMA_CFG_RING3_2_RX_PACKET_SWAP_SET(x)                                (((0 | (x)) << RXDMA_CFG_RING3_2_RX_PACKET_SWAP_LSB) & RXDMA_CFG_RING3_2_RX_PACKET_SWAP_MASK)
#define RXDMA_CFG_RING3_2_RX_PACKET_SWAP_RESET                                 0x0
#define RXDMA_CFG_RING3_2_RX_HEADER_SWAP_LSB                                   16
#define RXDMA_CFG_RING3_2_RX_HEADER_SWAP_MSB                                   16
#define RXDMA_CFG_RING3_2_RX_HEADER_SWAP_MASK                                  0x10000
#define RXDMA_CFG_RING3_2_RX_HEADER_SWAP_GET(x)                                (((x) & RXDMA_CFG_RING3_2_RX_HEADER_SWAP_MASK) >> RXDMA_CFG_RING3_2_RX_HEADER_SWAP_LSB)
#define RXDMA_CFG_RING3_2_RX_HEADER_SWAP_SET(x)                                (((0 | (x)) << RXDMA_CFG_RING3_2_RX_HEADER_SWAP_LSB) & RXDMA_CFG_RING3_2_RX_HEADER_SWAP_MASK)
#define RXDMA_CFG_RING3_2_RX_HEADER_SWAP_RESET                                 0x0
#define RXDMA_CFG_RING3_2_INTR_LWM_THRESH_LSB                                  0
#define RXDMA_CFG_RING3_2_INTR_LWM_THRESH_MSB                                  7
#define RXDMA_CFG_RING3_2_INTR_LWM_THRESH_MASK                                 0xff
#define RXDMA_CFG_RING3_2_INTR_LWM_THRESH_GET(x)                               (((x) & RXDMA_CFG_RING3_2_INTR_LWM_THRESH_MASK) >> RXDMA_CFG_RING3_2_INTR_LWM_THRESH_LSB)
#define RXDMA_CFG_RING3_2_INTR_LWM_THRESH_SET(x)                               (((0 | (x)) << RXDMA_CFG_RING3_2_INTR_LWM_THRESH_LSB) & RXDMA_CFG_RING3_2_INTR_LWM_THRESH_MASK)
#define RXDMA_CFG_RING3_2_INTR_LWM_THRESH_RESET                                0x5
#define RXDMA_CFG_RING3_2_ADDRESS                                              (0x68 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING3_2_RSTMASK                                              0x3ff00ff
#define RXDMA_CFG_RING3_2_RESET                                                0x5

// 0x6c (RXDMA_CFG_RING3_3)
#define RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_LSB                                 18
#define RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_MSB                                 25
#define RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_MASK                                0x3fc0000
#define RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_GET(x)                              (((x) & RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_MASK) >> RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_LSB)
#define RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_LSB) & RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_MASK)
#define RXDMA_CFG_RING3_3_RX_PACKET_OFFSET_RESET                               0x0
#define RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_LSB                                 2
#define RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_MSB                                 9
#define RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_MASK                                0x3fc
#define RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_GET(x)                              (((x) & RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_MASK) >> RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_LSB)
#define RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_SET(x)                              (((0 | (x)) << RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_LSB) & RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_MASK)
#define RXDMA_CFG_RING3_3_RX_HEADER_OFFSET_RESET                               0x0
#define RXDMA_CFG_RING3_3_ADDRESS                                              (0x6c + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING3_3_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING3_3_RESET                                                0x0

// 0x70 (RXDMA_CFG_RING3_4)
#define RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_LSB                               18
#define RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_MSB                               25
#define RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_MASK) >> RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_LSB)
#define RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_LSB) & RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_MASK)
#define RXDMA_CFG_RING3_4_RX_PPDU_END_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_LSB                             2
#define RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_MSB                             9
#define RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_MASK                            0x3fc
#define RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_GET(x)                          (((x) & RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_MASK) >> RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_LSB)
#define RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_SET(x)                          (((0 | (x)) << RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_LSB) & RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_MASK)
#define RXDMA_CFG_RING3_4_RX_PPDU_START_OFFSET_RESET                           0x0
#define RXDMA_CFG_RING3_4_ADDRESS                                              (0x70 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING3_4_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING3_4_RESET                                                0x0

// 0x74 (RXDMA_CFG_RING3_5)
#define RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_LSB                               18
#define RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_MSB                               25
#define RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_MASK) >> RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_LSB)
#define RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_LSB) & RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_MASK)
#define RXDMA_CFG_RING3_5_RX_MPDU_END_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_LSB                             2
#define RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_MSB                             9
#define RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_MASK                            0x3fc
#define RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_GET(x)                          (((x) & RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_MASK) >> RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_LSB)
#define RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_SET(x)                          (((0 | (x)) << RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_LSB) & RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_MASK)
#define RXDMA_CFG_RING3_5_RX_MPDU_START_OFFSET_RESET                           0x0
#define RXDMA_CFG_RING3_5_ADDRESS                                              (0x74 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING3_5_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING3_5_RESET                                                0x0

// 0x78 (RXDMA_CFG_RING3_6)
#define RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_LSB                               18
#define RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_MSB                               25
#define RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_MASK) >> RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_LSB)
#define RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_LSB) & RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_MASK)
#define RXDMA_CFG_RING3_6_RX_MSDU_END_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_LSB                             2
#define RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_MSB                             9
#define RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_MASK                            0x3fc
#define RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_GET(x)                          (((x) & RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_MASK) >> RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_LSB)
#define RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_SET(x)                          (((0 | (x)) << RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_LSB) & RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_MASK)
#define RXDMA_CFG_RING3_6_RX_MSDU_START_OFFSET_RESET                           0x0
#define RXDMA_CFG_RING3_6_ADDRESS                                              (0x78 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING3_6_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING3_6_RESET                                                0x0

// 0x7c (RXDMA_CFG_RING3_7)
#define RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_LSB                               18
#define RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_MSB                               25
#define RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_MASK                              0x3fc0000
#define RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_GET(x)                            (((x) & RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_MASK) >> RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_LSB)
#define RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_SET(x)                            (((0 | (x)) << RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_LSB) & RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_MASK)
#define RXDMA_CFG_RING3_7_RX_FRAGINFO_OFFSET_RESET                             0x0
#define RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_LSB                              2
#define RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_MSB                              9
#define RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_MASK                             0x3fc
#define RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_GET(x)                           (((x) & RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_MASK) >> RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_LSB)
#define RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_SET(x)                           (((0 | (x)) << RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_LSB) & RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_MASK)
#define RXDMA_CFG_RING3_7_RX_ATTENTION_OFFSET_RESET                            0x0
#define RXDMA_CFG_RING3_7_ADDRESS                                              (0x7c + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_RING3_7_RSTMASK                                              0x3fc03fc
#define RXDMA_CFG_RING3_7_RESET                                                0x0

// 0x80 (RXDMA_EN_ACT_0)
#define RXDMA_EN_ACT_0_RING_ACTIVE_LSB                                         1
#define RXDMA_EN_ACT_0_RING_ACTIVE_MSB                                         1
#define RXDMA_EN_ACT_0_RING_ACTIVE_MASK                                        0x2
#define RXDMA_EN_ACT_0_RING_ACTIVE_GET(x)                                      (((x) & RXDMA_EN_ACT_0_RING_ACTIVE_MASK) >> RXDMA_EN_ACT_0_RING_ACTIVE_LSB)
#define RXDMA_EN_ACT_0_RING_ACTIVE_SET(x)                                      (((0 | (x)) << RXDMA_EN_ACT_0_RING_ACTIVE_LSB) & RXDMA_EN_ACT_0_RING_ACTIVE_MASK)
#define RXDMA_EN_ACT_0_RING_ACTIVE_RESET                                       0x0
#define RXDMA_EN_ACT_0_RING_ENABLE_LSB                                         0
#define RXDMA_EN_ACT_0_RING_ENABLE_MSB                                         0
#define RXDMA_EN_ACT_0_RING_ENABLE_MASK                                        0x1
#define RXDMA_EN_ACT_0_RING_ENABLE_GET(x)                                      (((x) & RXDMA_EN_ACT_0_RING_ENABLE_MASK) >> RXDMA_EN_ACT_0_RING_ENABLE_LSB)
#define RXDMA_EN_ACT_0_RING_ENABLE_SET(x)                                      (((0 | (x)) << RXDMA_EN_ACT_0_RING_ENABLE_LSB) & RXDMA_EN_ACT_0_RING_ENABLE_MASK)
#define RXDMA_EN_ACT_0_RING_ENABLE_RESET                                       0x0
#define RXDMA_EN_ACT_0_ADDRESS                                                 (0x80 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_EN_ACT_0_RSTMASK                                                 0x3
#define RXDMA_EN_ACT_0_RESET                                                   0x0

// 0x84 (RXDMA_EN_ACT_1)
#define RXDMA_EN_ACT_1_RING_ACTIVE_LSB                                         1
#define RXDMA_EN_ACT_1_RING_ACTIVE_MSB                                         1
#define RXDMA_EN_ACT_1_RING_ACTIVE_MASK                                        0x2
#define RXDMA_EN_ACT_1_RING_ACTIVE_GET(x)                                      (((x) & RXDMA_EN_ACT_1_RING_ACTIVE_MASK) >> RXDMA_EN_ACT_1_RING_ACTIVE_LSB)
#define RXDMA_EN_ACT_1_RING_ACTIVE_SET(x)                                      (((0 | (x)) << RXDMA_EN_ACT_1_RING_ACTIVE_LSB) & RXDMA_EN_ACT_1_RING_ACTIVE_MASK)
#define RXDMA_EN_ACT_1_RING_ACTIVE_RESET                                       0x0
#define RXDMA_EN_ACT_1_RING_ENABLE_LSB                                         0
#define RXDMA_EN_ACT_1_RING_ENABLE_MSB                                         0
#define RXDMA_EN_ACT_1_RING_ENABLE_MASK                                        0x1
#define RXDMA_EN_ACT_1_RING_ENABLE_GET(x)                                      (((x) & RXDMA_EN_ACT_1_RING_ENABLE_MASK) >> RXDMA_EN_ACT_1_RING_ENABLE_LSB)
#define RXDMA_EN_ACT_1_RING_ENABLE_SET(x)                                      (((0 | (x)) << RXDMA_EN_ACT_1_RING_ENABLE_LSB) & RXDMA_EN_ACT_1_RING_ENABLE_MASK)
#define RXDMA_EN_ACT_1_RING_ENABLE_RESET                                       0x0
#define RXDMA_EN_ACT_1_ADDRESS                                                 (0x84 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_EN_ACT_1_RSTMASK                                                 0x3
#define RXDMA_EN_ACT_1_RESET                                                   0x0

// 0x88 (RXDMA_EN_ACT_2)
#define RXDMA_EN_ACT_2_RING_ACTIVE_LSB                                         1
#define RXDMA_EN_ACT_2_RING_ACTIVE_MSB                                         1
#define RXDMA_EN_ACT_2_RING_ACTIVE_MASK                                        0x2
#define RXDMA_EN_ACT_2_RING_ACTIVE_GET(x)                                      (((x) & RXDMA_EN_ACT_2_RING_ACTIVE_MASK) >> RXDMA_EN_ACT_2_RING_ACTIVE_LSB)
#define RXDMA_EN_ACT_2_RING_ACTIVE_SET(x)                                      (((0 | (x)) << RXDMA_EN_ACT_2_RING_ACTIVE_LSB) & RXDMA_EN_ACT_2_RING_ACTIVE_MASK)
#define RXDMA_EN_ACT_2_RING_ACTIVE_RESET                                       0x0
#define RXDMA_EN_ACT_2_RING_ENABLE_LSB                                         0
#define RXDMA_EN_ACT_2_RING_ENABLE_MSB                                         0
#define RXDMA_EN_ACT_2_RING_ENABLE_MASK                                        0x1
#define RXDMA_EN_ACT_2_RING_ENABLE_GET(x)                                      (((x) & RXDMA_EN_ACT_2_RING_ENABLE_MASK) >> RXDMA_EN_ACT_2_RING_ENABLE_LSB)
#define RXDMA_EN_ACT_2_RING_ENABLE_SET(x)                                      (((0 | (x)) << RXDMA_EN_ACT_2_RING_ENABLE_LSB) & RXDMA_EN_ACT_2_RING_ENABLE_MASK)
#define RXDMA_EN_ACT_2_RING_ENABLE_RESET                                       0x0
#define RXDMA_EN_ACT_2_ADDRESS                                                 (0x88 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_EN_ACT_2_RSTMASK                                                 0x3
#define RXDMA_EN_ACT_2_RESET                                                   0x0

// 0x8c (RXDMA_EN_ACT_3)
#define RXDMA_EN_ACT_3_RING_ACTIVE_LSB                                         1
#define RXDMA_EN_ACT_3_RING_ACTIVE_MSB                                         1
#define RXDMA_EN_ACT_3_RING_ACTIVE_MASK                                        0x2
#define RXDMA_EN_ACT_3_RING_ACTIVE_GET(x)                                      (((x) & RXDMA_EN_ACT_3_RING_ACTIVE_MASK) >> RXDMA_EN_ACT_3_RING_ACTIVE_LSB)
#define RXDMA_EN_ACT_3_RING_ACTIVE_SET(x)                                      (((0 | (x)) << RXDMA_EN_ACT_3_RING_ACTIVE_LSB) & RXDMA_EN_ACT_3_RING_ACTIVE_MASK)
#define RXDMA_EN_ACT_3_RING_ACTIVE_RESET                                       0x0
#define RXDMA_EN_ACT_3_RING_ENABLE_LSB                                         0
#define RXDMA_EN_ACT_3_RING_ENABLE_MSB                                         0
#define RXDMA_EN_ACT_3_RING_ENABLE_MASK                                        0x1
#define RXDMA_EN_ACT_3_RING_ENABLE_GET(x)                                      (((x) & RXDMA_EN_ACT_3_RING_ENABLE_MASK) >> RXDMA_EN_ACT_3_RING_ENABLE_LSB)
#define RXDMA_EN_ACT_3_RING_ENABLE_SET(x)                                      (((0 | (x)) << RXDMA_EN_ACT_3_RING_ENABLE_LSB) & RXDMA_EN_ACT_3_RING_ENABLE_MASK)
#define RXDMA_EN_ACT_3_RING_ENABLE_RESET                                       0x0
#define RXDMA_EN_ACT_3_ADDRESS                                                 (0x8c + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_EN_ACT_3_RSTMASK                                                 0x3
#define RXDMA_EN_ACT_3_RESET                                                   0x0

// 0x90 (RXDMA_IDX_0)
#define RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_LSB                                  31
#define RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_MSB                                  31
#define RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_MASK                                 0x80000000
#define RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_GET(x)                               (((x) & RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_MASK) >> RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_LSB)
#define RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_SET(x)                               (((0 | (x)) << RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_LSB) & RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_MASK)
#define RXDMA_IDX_0_RING_HW_IDX_OVERWRITE_RESET                                0x0
#define RXDMA_IDX_0_RING_HW_IDX_LSB                                            16
#define RXDMA_IDX_0_RING_HW_IDX_MSB                                            30
#define RXDMA_IDX_0_RING_HW_IDX_MASK                                           0x7fff0000
#define RXDMA_IDX_0_RING_HW_IDX_GET(x)                                         (((x) & RXDMA_IDX_0_RING_HW_IDX_MASK) >> RXDMA_IDX_0_RING_HW_IDX_LSB)
#define RXDMA_IDX_0_RING_HW_IDX_SET(x)                                         (((0 | (x)) << RXDMA_IDX_0_RING_HW_IDX_LSB) & RXDMA_IDX_0_RING_HW_IDX_MASK)
#define RXDMA_IDX_0_RING_HW_IDX_RESET                                          0x0
#define RXDMA_IDX_0_RING_FW_IDX_LSB                                            0
#define RXDMA_IDX_0_RING_FW_IDX_MSB                                            15
#define RXDMA_IDX_0_RING_FW_IDX_MASK                                           0xffff
#define RXDMA_IDX_0_RING_FW_IDX_GET(x)                                         (((x) & RXDMA_IDX_0_RING_FW_IDX_MASK) >> RXDMA_IDX_0_RING_FW_IDX_LSB)
#define RXDMA_IDX_0_RING_FW_IDX_SET(x)                                         (((0 | (x)) << RXDMA_IDX_0_RING_FW_IDX_LSB) & RXDMA_IDX_0_RING_FW_IDX_MASK)
#define RXDMA_IDX_0_RING_FW_IDX_RESET                                          0x0
#define RXDMA_IDX_0_ADDRESS                                                    (0x90 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_IDX_0_RSTMASK                                                    0xffffffff
#define RXDMA_IDX_0_RESET                                                      0x0

// 0x94 (RXDMA_IDX_1)
#define RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_LSB                                  31
#define RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_MSB                                  31
#define RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_MASK                                 0x80000000
#define RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_GET(x)                               (((x) & RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_MASK) >> RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_LSB)
#define RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_SET(x)                               (((0 | (x)) << RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_LSB) & RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_MASK)
#define RXDMA_IDX_1_RING_HW_IDX_OVERWRITE_RESET                                0x0
#define RXDMA_IDX_1_RING_HW_IDX_LSB                                            16
#define RXDMA_IDX_1_RING_HW_IDX_MSB                                            30
#define RXDMA_IDX_1_RING_HW_IDX_MASK                                           0x7fff0000
#define RXDMA_IDX_1_RING_HW_IDX_GET(x)                                         (((x) & RXDMA_IDX_1_RING_HW_IDX_MASK) >> RXDMA_IDX_1_RING_HW_IDX_LSB)
#define RXDMA_IDX_1_RING_HW_IDX_SET(x)                                         (((0 | (x)) << RXDMA_IDX_1_RING_HW_IDX_LSB) & RXDMA_IDX_1_RING_HW_IDX_MASK)
#define RXDMA_IDX_1_RING_HW_IDX_RESET                                          0x0
#define RXDMA_IDX_1_RING_FW_IDX_LSB                                            0
#define RXDMA_IDX_1_RING_FW_IDX_MSB                                            15
#define RXDMA_IDX_1_RING_FW_IDX_MASK                                           0xffff
#define RXDMA_IDX_1_RING_FW_IDX_GET(x)                                         (((x) & RXDMA_IDX_1_RING_FW_IDX_MASK) >> RXDMA_IDX_1_RING_FW_IDX_LSB)
#define RXDMA_IDX_1_RING_FW_IDX_SET(x)                                         (((0 | (x)) << RXDMA_IDX_1_RING_FW_IDX_LSB) & RXDMA_IDX_1_RING_FW_IDX_MASK)
#define RXDMA_IDX_1_RING_FW_IDX_RESET                                          0x0
#define RXDMA_IDX_1_ADDRESS                                                    (0x94 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_IDX_1_RSTMASK                                                    0xffffffff
#define RXDMA_IDX_1_RESET                                                      0x0

// 0x98 (RXDMA_IDX_2)
#define RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_LSB                                  31
#define RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_MSB                                  31
#define RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_MASK                                 0x80000000
#define RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_GET(x)                               (((x) & RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_MASK) >> RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_LSB)
#define RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_SET(x)                               (((0 | (x)) << RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_LSB) & RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_MASK)
#define RXDMA_IDX_2_RING_HW_IDX_OVERWRITE_RESET                                0x0
#define RXDMA_IDX_2_RING_HW_IDX_LSB                                            16
#define RXDMA_IDX_2_RING_HW_IDX_MSB                                            30
#define RXDMA_IDX_2_RING_HW_IDX_MASK                                           0x7fff0000
#define RXDMA_IDX_2_RING_HW_IDX_GET(x)                                         (((x) & RXDMA_IDX_2_RING_HW_IDX_MASK) >> RXDMA_IDX_2_RING_HW_IDX_LSB)
#define RXDMA_IDX_2_RING_HW_IDX_SET(x)                                         (((0 | (x)) << RXDMA_IDX_2_RING_HW_IDX_LSB) & RXDMA_IDX_2_RING_HW_IDX_MASK)
#define RXDMA_IDX_2_RING_HW_IDX_RESET                                          0x0
#define RXDMA_IDX_2_RING_FW_IDX_LSB                                            0
#define RXDMA_IDX_2_RING_FW_IDX_MSB                                            15
#define RXDMA_IDX_2_RING_FW_IDX_MASK                                           0xffff
#define RXDMA_IDX_2_RING_FW_IDX_GET(x)                                         (((x) & RXDMA_IDX_2_RING_FW_IDX_MASK) >> RXDMA_IDX_2_RING_FW_IDX_LSB)
#define RXDMA_IDX_2_RING_FW_IDX_SET(x)                                         (((0 | (x)) << RXDMA_IDX_2_RING_FW_IDX_LSB) & RXDMA_IDX_2_RING_FW_IDX_MASK)
#define RXDMA_IDX_2_RING_FW_IDX_RESET                                          0x0
#define RXDMA_IDX_2_ADDRESS                                                    (0x98 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_IDX_2_RSTMASK                                                    0xffffffff
#define RXDMA_IDX_2_RESET                                                      0x0

// 0x9c (RXDMA_IDX_3)
#define RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_LSB                                  31
#define RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_MSB                                  31
#define RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_MASK                                 0x80000000
#define RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_GET(x)                               (((x) & RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_MASK) >> RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_LSB)
#define RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_SET(x)                               (((0 | (x)) << RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_LSB) & RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_MASK)
#define RXDMA_IDX_3_RING_HW_IDX_OVERWRITE_RESET                                0x0
#define RXDMA_IDX_3_RING_HW_IDX_LSB                                            16
#define RXDMA_IDX_3_RING_HW_IDX_MSB                                            30
#define RXDMA_IDX_3_RING_HW_IDX_MASK                                           0x7fff0000
#define RXDMA_IDX_3_RING_HW_IDX_GET(x)                                         (((x) & RXDMA_IDX_3_RING_HW_IDX_MASK) >> RXDMA_IDX_3_RING_HW_IDX_LSB)
#define RXDMA_IDX_3_RING_HW_IDX_SET(x)                                         (((0 | (x)) << RXDMA_IDX_3_RING_HW_IDX_LSB) & RXDMA_IDX_3_RING_HW_IDX_MASK)
#define RXDMA_IDX_3_RING_HW_IDX_RESET                                          0x0
#define RXDMA_IDX_3_RING_FW_IDX_LSB                                            0
#define RXDMA_IDX_3_RING_FW_IDX_MSB                                            15
#define RXDMA_IDX_3_RING_FW_IDX_MASK                                           0xffff
#define RXDMA_IDX_3_RING_FW_IDX_GET(x)                                         (((x) & RXDMA_IDX_3_RING_FW_IDX_MASK) >> RXDMA_IDX_3_RING_FW_IDX_LSB)
#define RXDMA_IDX_3_RING_FW_IDX_SET(x)                                         (((0 | (x)) << RXDMA_IDX_3_RING_FW_IDX_LSB) & RXDMA_IDX_3_RING_FW_IDX_MASK)
#define RXDMA_IDX_3_RING_FW_IDX_RESET                                          0x0
#define RXDMA_IDX_3_ADDRESS                                                    (0x9c + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_IDX_3_RSTMASK                                                    0xffffffff
#define RXDMA_IDX_3_RESET                                                      0x0

// 0xa0 (RXDMA_CFG_MISC_0)
#define RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_LSB                              16
#define RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_MSB                              31
#define RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_MASK                             0xffff0000
#define RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_GET(x)                           (((x) & RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_MASK) >> RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_LSB)
#define RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_SET(x)                           (((0 | (x)) << RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_LSB) & RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_MASK)
#define RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_1_RESET                            0x80
#define RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_LSB                              0
#define RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_MSB                              15
#define RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_MASK                             0xffff
#define RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_GET(x)                           (((x) & RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_MASK) >> RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_LSB)
#define RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_SET(x)                           (((0 | (x)) << RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_LSB) & RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_MASK)
#define RXDMA_CFG_MISC_0_MEM_BOUNDARY_BYTES_0_RESET                            0x80
#define RXDMA_CFG_MISC_0_ADDRESS                                               (0xa0 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_MISC_0_RSTMASK                                               0xffffffff
#define RXDMA_CFG_MISC_0_RESET                                                 0x800080

// 0xa4 (RXDMA_CFG_MISC_1)
#define RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_LSB                              16
#define RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_MSB                              31
#define RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_MASK                             0xffff0000
#define RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_GET(x)                           (((x) & RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_MASK) >> RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_LSB)
#define RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_SET(x)                           (((0 | (x)) << RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_LSB) & RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_MASK)
#define RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_3_RESET                            0x80
#define RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_LSB                              0
#define RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_MSB                              15
#define RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_MASK                             0xffff
#define RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_GET(x)                           (((x) & RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_MASK) >> RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_LSB)
#define RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_SET(x)                           (((0 | (x)) << RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_LSB) & RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_MASK)
#define RXDMA_CFG_MISC_1_MEM_BOUNDARY_BYTES_2_RESET                            0x80
#define RXDMA_CFG_MISC_1_ADDRESS                                               (0xa4 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_MISC_1_RSTMASK                                               0xffffffff
#define RXDMA_CFG_MISC_1_RESET                                                 0x800080

// 0xa8 (RXDMA_CFG_MISC_2)
#define RXDMA_CFG_MISC_2_ALIGN_TO_BYTE_BOUNDARY_LSB                            1
#define RXDMA_CFG_MISC_2_ALIGN_TO_BYTE_BOUNDARY_MSB                            1
#define RXDMA_CFG_MISC_2_ALIGN_TO_BYTE_BOUNDARY_MASK                           0x2
#define RXDMA_CFG_MISC_2_ALIGN_TO_BYTE_BOUNDARY_GET(x)                         (((x) & RXDMA_CFG_MISC_2_ALIGN_TO_BYTE_BOUNDARY_MASK) >> RXDMA_CFG_MISC_2_ALIGN_TO_BYTE_BOUNDARY_LSB)
#define RXDMA_CFG_MISC_2_ALIGN_TO_BYTE_BOUNDARY_SET(x)                         (((0 | (x)) << RXDMA_CFG_MISC_2_ALIGN_TO_BYTE_BOUNDARY_LSB) & RXDMA_CFG_MISC_2_ALIGN_TO_BYTE_BOUNDARY_MASK)
#define RXDMA_CFG_MISC_2_ALIGN_TO_BYTE_BOUNDARY_RESET                          0x0
#define RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_LSB                            0
#define RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_MSB                            0
#define RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_MASK                           0x1
#define RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_GET(x)                         (((x) & RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_MASK) >> RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_LSB)
#define RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_SET(x)                         (((0 | (x)) << RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_LSB) & RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_MASK)
#define RXDMA_CFG_MISC_2_LONG_DMA_PAUSE_FIX_DIS_RESET                          0x0
#define RXDMA_CFG_MISC_2_ADDRESS                                               (0xa8 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CFG_MISC_2_RSTMASK                                               0x3
#define RXDMA_CFG_MISC_2_RESET                                                 0x0

// 0xac (RXDMA_FETCH_IDX_0)
#define RXDMA_FETCH_IDX_0_RING_HW_FETCH_IDX_LSB                                0
#define RXDMA_FETCH_IDX_0_RING_HW_FETCH_IDX_MSB                                15
#define RXDMA_FETCH_IDX_0_RING_HW_FETCH_IDX_MASK                               0xffff
#define RXDMA_FETCH_IDX_0_RING_HW_FETCH_IDX_GET(x)                             (((x) & RXDMA_FETCH_IDX_0_RING_HW_FETCH_IDX_MASK) >> RXDMA_FETCH_IDX_0_RING_HW_FETCH_IDX_LSB)
#define RXDMA_FETCH_IDX_0_RING_HW_FETCH_IDX_SET(x)                             (((0 | (x)) << RXDMA_FETCH_IDX_0_RING_HW_FETCH_IDX_LSB) & RXDMA_FETCH_IDX_0_RING_HW_FETCH_IDX_MASK)
#define RXDMA_FETCH_IDX_0_RING_HW_FETCH_IDX_RESET                              0x0
#define RXDMA_FETCH_IDX_0_ADDRESS                                              (0xac + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_FETCH_IDX_0_RSTMASK                                              0xffff
#define RXDMA_FETCH_IDX_0_RESET                                                0x0

// 0xb0 (RXDMA_FETCH_IDX_1)
#define RXDMA_FETCH_IDX_1_RING_HW_FETCH_IDX_LSB                                0
#define RXDMA_FETCH_IDX_1_RING_HW_FETCH_IDX_MSB                                15
#define RXDMA_FETCH_IDX_1_RING_HW_FETCH_IDX_MASK                               0xffff
#define RXDMA_FETCH_IDX_1_RING_HW_FETCH_IDX_GET(x)                             (((x) & RXDMA_FETCH_IDX_1_RING_HW_FETCH_IDX_MASK) >> RXDMA_FETCH_IDX_1_RING_HW_FETCH_IDX_LSB)
#define RXDMA_FETCH_IDX_1_RING_HW_FETCH_IDX_SET(x)                             (((0 | (x)) << RXDMA_FETCH_IDX_1_RING_HW_FETCH_IDX_LSB) & RXDMA_FETCH_IDX_1_RING_HW_FETCH_IDX_MASK)
#define RXDMA_FETCH_IDX_1_RING_HW_FETCH_IDX_RESET                              0x0
#define RXDMA_FETCH_IDX_1_ADDRESS                                              (0xb0 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_FETCH_IDX_1_RSTMASK                                              0xffff
#define RXDMA_FETCH_IDX_1_RESET                                                0x0

// 0xb4 (RXDMA_FETCH_IDX_2)
#define RXDMA_FETCH_IDX_2_RING_HW_FETCH_IDX_LSB                                0
#define RXDMA_FETCH_IDX_2_RING_HW_FETCH_IDX_MSB                                15
#define RXDMA_FETCH_IDX_2_RING_HW_FETCH_IDX_MASK                               0xffff
#define RXDMA_FETCH_IDX_2_RING_HW_FETCH_IDX_GET(x)                             (((x) & RXDMA_FETCH_IDX_2_RING_HW_FETCH_IDX_MASK) >> RXDMA_FETCH_IDX_2_RING_HW_FETCH_IDX_LSB)
#define RXDMA_FETCH_IDX_2_RING_HW_FETCH_IDX_SET(x)                             (((0 | (x)) << RXDMA_FETCH_IDX_2_RING_HW_FETCH_IDX_LSB) & RXDMA_FETCH_IDX_2_RING_HW_FETCH_IDX_MASK)
#define RXDMA_FETCH_IDX_2_RING_HW_FETCH_IDX_RESET                              0x0
#define RXDMA_FETCH_IDX_2_ADDRESS                                              (0xb4 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_FETCH_IDX_2_RSTMASK                                              0xffff
#define RXDMA_FETCH_IDX_2_RESET                                                0x0

// 0xb8 (RXDMA_FETCH_IDX_3)
#define RXDMA_FETCH_IDX_3_RING_HW_FETCH_IDX_LSB                                0
#define RXDMA_FETCH_IDX_3_RING_HW_FETCH_IDX_MSB                                15
#define RXDMA_FETCH_IDX_3_RING_HW_FETCH_IDX_MASK                               0xffff
#define RXDMA_FETCH_IDX_3_RING_HW_FETCH_IDX_GET(x)                             (((x) & RXDMA_FETCH_IDX_3_RING_HW_FETCH_IDX_MASK) >> RXDMA_FETCH_IDX_3_RING_HW_FETCH_IDX_LSB)
#define RXDMA_FETCH_IDX_3_RING_HW_FETCH_IDX_SET(x)                             (((0 | (x)) << RXDMA_FETCH_IDX_3_RING_HW_FETCH_IDX_LSB) & RXDMA_FETCH_IDX_3_RING_HW_FETCH_IDX_MASK)
#define RXDMA_FETCH_IDX_3_RING_HW_FETCH_IDX_RESET                              0x0
#define RXDMA_FETCH_IDX_3_ADDRESS                                              (0xb8 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_FETCH_IDX_3_RSTMASK                                              0xffff
#define RXDMA_FETCH_IDX_3_RESET                                                0x0

// 0xbc (RXDMA_GLOBAL_RER)
#define RXDMA_GLOBAL_RER_ENABLE_LSB                                            0
#define RXDMA_GLOBAL_RER_ENABLE_MSB                                            0
#define RXDMA_GLOBAL_RER_ENABLE_MASK                                           0x1
#define RXDMA_GLOBAL_RER_ENABLE_GET(x)                                         (((x) & RXDMA_GLOBAL_RER_ENABLE_MASK) >> RXDMA_GLOBAL_RER_ENABLE_LSB)
#define RXDMA_GLOBAL_RER_ENABLE_SET(x)                                         (((0 | (x)) << RXDMA_GLOBAL_RER_ENABLE_LSB) & RXDMA_GLOBAL_RER_ENABLE_MASK)
#define RXDMA_GLOBAL_RER_ENABLE_RESET                                          0x1
#define RXDMA_GLOBAL_RER_ADDRESS                                               (0xbc + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_GLOBAL_RER_RSTMASK                                               0x1
#define RXDMA_GLOBAL_RER_RESET                                                 0x1

// 0xc0 (RXDMA_SOFT_RST)
#define RXDMA_SOFT_RST_SET_LSB                                                 0
#define RXDMA_SOFT_RST_SET_MSB                                                 0
#define RXDMA_SOFT_RST_SET_MASK                                                0x1
#define RXDMA_SOFT_RST_SET_GET(x)                                              (((x) & RXDMA_SOFT_RST_SET_MASK) >> RXDMA_SOFT_RST_SET_LSB)
#define RXDMA_SOFT_RST_SET_SET(x)                                              (((0 | (x)) << RXDMA_SOFT_RST_SET_LSB) & RXDMA_SOFT_RST_SET_MASK)
#define RXDMA_SOFT_RST_SET_RESET                                               0x0
#define RXDMA_SOFT_RST_ADDRESS                                                 (0xc0 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_SOFT_RST_RSTMASK                                                 0x1
#define RXDMA_SOFT_RST_RESET                                                   0x0

// 0xc4 (RXDMA_WDOG)
#define RXDMA_WDOG_STATUS_LSB                                                  16
#define RXDMA_WDOG_STATUS_MSB                                                  31
#define RXDMA_WDOG_STATUS_MASK                                                 0xffff0000
#define RXDMA_WDOG_STATUS_GET(x)                                               (((x) & RXDMA_WDOG_STATUS_MASK) >> RXDMA_WDOG_STATUS_LSB)
#define RXDMA_WDOG_STATUS_SET(x)                                               (((0 | (x)) << RXDMA_WDOG_STATUS_LSB) & RXDMA_WDOG_STATUS_MASK)
#define RXDMA_WDOG_STATUS_RESET                                                0x0
#define RXDMA_WDOG_LIMIT_LSB                                                   0
#define RXDMA_WDOG_LIMIT_MSB                                                   15
#define RXDMA_WDOG_LIMIT_MASK                                                  0xffff
#define RXDMA_WDOG_LIMIT_GET(x)                                                (((x) & RXDMA_WDOG_LIMIT_MASK) >> RXDMA_WDOG_LIMIT_LSB)
#define RXDMA_WDOG_LIMIT_SET(x)                                                (((0 | (x)) << RXDMA_WDOG_LIMIT_LSB) & RXDMA_WDOG_LIMIT_MASK)
#define RXDMA_WDOG_LIMIT_RESET                                                 0xffff
#define RXDMA_WDOG_ADDRESS                                                     (0xc4 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_WDOG_RSTMASK                                                     0xffffffff
#define RXDMA_WDOG_RESET                                                       0xffff

// 0xc8 (RXDMA_TESTBUS_SAMPLE)
#define RXDMA_TESTBUS_SAMPLE_VAL_LSB                                           0
#define RXDMA_TESTBUS_SAMPLE_VAL_MSB                                           31
#define RXDMA_TESTBUS_SAMPLE_VAL_MASK                                          0xffffffff
#define RXDMA_TESTBUS_SAMPLE_VAL_GET(x)                                        (((x) & RXDMA_TESTBUS_SAMPLE_VAL_MASK) >> RXDMA_TESTBUS_SAMPLE_VAL_LSB)
#define RXDMA_TESTBUS_SAMPLE_VAL_SET(x)                                        (((0 | (x)) << RXDMA_TESTBUS_SAMPLE_VAL_LSB) & RXDMA_TESTBUS_SAMPLE_VAL_MASK)
#define RXDMA_TESTBUS_SAMPLE_VAL_RESET                                         0x0
#define RXDMA_TESTBUS_SAMPLE_ADDRESS                                           (0xc8 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_TESTBUS_SAMPLE_RSTMASK                                           0xffffffff
#define RXDMA_TESTBUS_SAMPLE_RESET                                             0x0

// 0xcc (RXDMA_TRACEBUS_CTRL)
#define RXDMA_TRACEBUS_CTRL_EN_LSB                                             2
#define RXDMA_TRACEBUS_CTRL_EN_MSB                                             2
#define RXDMA_TRACEBUS_CTRL_EN_MASK                                            0x4
#define RXDMA_TRACEBUS_CTRL_EN_GET(x)                                          (((x) & RXDMA_TRACEBUS_CTRL_EN_MASK) >> RXDMA_TRACEBUS_CTRL_EN_LSB)
#define RXDMA_TRACEBUS_CTRL_EN_SET(x)                                          (((0 | (x)) << RXDMA_TRACEBUS_CTRL_EN_LSB) & RXDMA_TRACEBUS_CTRL_EN_MASK)
#define RXDMA_TRACEBUS_CTRL_EN_RESET                                           0x1
#define RXDMA_TRACEBUS_CTRL_SELECT_LSB                                         0
#define RXDMA_TRACEBUS_CTRL_SELECT_MSB                                         1
#define RXDMA_TRACEBUS_CTRL_SELECT_MASK                                        0x3
#define RXDMA_TRACEBUS_CTRL_SELECT_GET(x)                                      (((x) & RXDMA_TRACEBUS_CTRL_SELECT_MASK) >> RXDMA_TRACEBUS_CTRL_SELECT_LSB)
#define RXDMA_TRACEBUS_CTRL_SELECT_SET(x)                                      (((0 | (x)) << RXDMA_TRACEBUS_CTRL_SELECT_LSB) & RXDMA_TRACEBUS_CTRL_SELECT_MASK)
#define RXDMA_TRACEBUS_CTRL_SELECT_RESET                                       0x0
#define RXDMA_TRACEBUS_CTRL_ADDRESS                                            (0xcc + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_TRACEBUS_CTRL_RSTMASK                                            0x7
#define RXDMA_TRACEBUS_CTRL_RESET                                              0x4

// 0xd0 (RXDMA_CLOCK_GATE)
#define RXDMA_CLOCK_GATE_DISABLE_LSB                                           0
#define RXDMA_CLOCK_GATE_DISABLE_MSB                                           6
#define RXDMA_CLOCK_GATE_DISABLE_MASK                                          0x7f
#define RXDMA_CLOCK_GATE_DISABLE_GET(x)                                        (((x) & RXDMA_CLOCK_GATE_DISABLE_MASK) >> RXDMA_CLOCK_GATE_DISABLE_LSB)
#define RXDMA_CLOCK_GATE_DISABLE_SET(x)                                        (((0 | (x)) << RXDMA_CLOCK_GATE_DISABLE_LSB) & RXDMA_CLOCK_GATE_DISABLE_MASK)
#define RXDMA_CLOCK_GATE_DISABLE_RESET                                         0x7f
#define RXDMA_CLOCK_GATE_ADDRESS                                               (0xd0 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_CLOCK_GATE_RSTMASK                                               0x7f
#define RXDMA_CLOCK_GATE_RESET                                                 0x7f

// 0xd4 (RXDMA_EVENT_MASK_31_0)
#define RXDMA_EVENT_MASK_31_0_EVENT_MASK_31_0_LSB                              0
#define RXDMA_EVENT_MASK_31_0_EVENT_MASK_31_0_MSB                              31
#define RXDMA_EVENT_MASK_31_0_EVENT_MASK_31_0_MASK                             0xffffffff
#define RXDMA_EVENT_MASK_31_0_EVENT_MASK_31_0_GET(x)                           (((x) & RXDMA_EVENT_MASK_31_0_EVENT_MASK_31_0_MASK) >> RXDMA_EVENT_MASK_31_0_EVENT_MASK_31_0_LSB)
#define RXDMA_EVENT_MASK_31_0_EVENT_MASK_31_0_SET(x)                           (((0 | (x)) << RXDMA_EVENT_MASK_31_0_EVENT_MASK_31_0_LSB) & RXDMA_EVENT_MASK_31_0_EVENT_MASK_31_0_MASK)
#define RXDMA_EVENT_MASK_31_0_EVENT_MASK_31_0_RESET                            0x0
#define RXDMA_EVENT_MASK_31_0_ADDRESS                                          (0xd4 + __MAC_RXDMA_REG_BASE_ADDRESS)
#define RXDMA_EVENT_MASK_31_0_RSTMASK                                          0xffffffff
#define RXDMA_EVENT_MASK_31_0_RESET                                            0x0



#endif /* _MAC_RXDMA_REG_H_ */
