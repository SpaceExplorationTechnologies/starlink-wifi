/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _EMU_PHY_REG_H_
#define _EMU_PHY_REG_H_


#ifndef __EMU_PHY_REG_BASE_ADDRESS
#define __EMU_PHY_REG_BASE_ADDRESS (0x1fe00)
#endif


// 0x0 (PHY_CTRL_0)
#define PHY_CTRL_0_RSVD_1_LSB                                                  29
#define PHY_CTRL_0_RSVD_1_MSB                                                  31
#define PHY_CTRL_0_RSVD_1_MASK                                                 0xe0000000
#define PHY_CTRL_0_RSVD_1_GET(x)                                               (((x) & PHY_CTRL_0_RSVD_1_MASK) >> PHY_CTRL_0_RSVD_1_LSB)
#define PHY_CTRL_0_RSVD_1_SET(x)                                               (((0 | (x)) << PHY_CTRL_0_RSVD_1_LSB) & PHY_CTRL_0_RSVD_1_MASK)
#define PHY_CTRL_0_RSVD_1_RESET                                                0x0
#define PHY_CTRL_0_PKT_USR_TLV_LEN_LSB                                         28
#define PHY_CTRL_0_PKT_USR_TLV_LEN_MSB                                         28
#define PHY_CTRL_0_PKT_USR_TLV_LEN_MASK                                        0x10000000
#define PHY_CTRL_0_PKT_USR_TLV_LEN_GET(x)                                      (((x) & PHY_CTRL_0_PKT_USR_TLV_LEN_MASK) >> PHY_CTRL_0_PKT_USR_TLV_LEN_LSB)
#define PHY_CTRL_0_PKT_USR_TLV_LEN_SET(x)                                      (((0 | (x)) << PHY_CTRL_0_PKT_USR_TLV_LEN_LSB) & PHY_CTRL_0_PKT_USR_TLV_LEN_MASK)
#define PHY_CTRL_0_PKT_USR_TLV_LEN_RESET                                       0x1
#define PHY_CTRL_0_NDP_DROP_ENABLE_LSB                                         27
#define PHY_CTRL_0_NDP_DROP_ENABLE_MSB                                         27
#define PHY_CTRL_0_NDP_DROP_ENABLE_MASK                                        0x8000000
#define PHY_CTRL_0_NDP_DROP_ENABLE_GET(x)                                      (((x) & PHY_CTRL_0_NDP_DROP_ENABLE_MASK) >> PHY_CTRL_0_NDP_DROP_ENABLE_LSB)
#define PHY_CTRL_0_NDP_DROP_ENABLE_SET(x)                                      (((0 | (x)) << PHY_CTRL_0_NDP_DROP_ENABLE_LSB) & PHY_CTRL_0_NDP_DROP_ENABLE_MASK)
#define PHY_CTRL_0_NDP_DROP_ENABLE_RESET                                       0x0
#define PHY_CTRL_0_VEC_FRAG_BW_OVERRIDE_LSB                                    26
#define PHY_CTRL_0_VEC_FRAG_BW_OVERRIDE_MSB                                    26
#define PHY_CTRL_0_VEC_FRAG_BW_OVERRIDE_MASK                                   0x4000000
#define PHY_CTRL_0_VEC_FRAG_BW_OVERRIDE_GET(x)                                 (((x) & PHY_CTRL_0_VEC_FRAG_BW_OVERRIDE_MASK) >> PHY_CTRL_0_VEC_FRAG_BW_OVERRIDE_LSB)
#define PHY_CTRL_0_VEC_FRAG_BW_OVERRIDE_SET(x)                                 (((0 | (x)) << PHY_CTRL_0_VEC_FRAG_BW_OVERRIDE_LSB) & PHY_CTRL_0_VEC_FRAG_BW_OVERRIDE_MASK)
#define PHY_CTRL_0_VEC_FRAG_BW_OVERRIDE_RESET                                  0x0
#define PHY_CTRL_0_VEC_FRAG_BW_LSB                                             24
#define PHY_CTRL_0_VEC_FRAG_BW_MSB                                             25
#define PHY_CTRL_0_VEC_FRAG_BW_MASK                                            0x3000000
#define PHY_CTRL_0_VEC_FRAG_BW_GET(x)                                          (((x) & PHY_CTRL_0_VEC_FRAG_BW_MASK) >> PHY_CTRL_0_VEC_FRAG_BW_LSB)
#define PHY_CTRL_0_VEC_FRAG_BW_SET(x)                                          (((0 | (x)) << PHY_CTRL_0_VEC_FRAG_BW_LSB) & PHY_CTRL_0_VEC_FRAG_BW_MASK)
#define PHY_CTRL_0_VEC_FRAG_BW_RESET                                           0x0
#define PHY_CTRL_0_VEC_FRAG_NR_OVERRIDE_LSB                                    23
#define PHY_CTRL_0_VEC_FRAG_NR_OVERRIDE_MSB                                    23
#define PHY_CTRL_0_VEC_FRAG_NR_OVERRIDE_MASK                                   0x800000
#define PHY_CTRL_0_VEC_FRAG_NR_OVERRIDE_GET(x)                                 (((x) & PHY_CTRL_0_VEC_FRAG_NR_OVERRIDE_MASK) >> PHY_CTRL_0_VEC_FRAG_NR_OVERRIDE_LSB)
#define PHY_CTRL_0_VEC_FRAG_NR_OVERRIDE_SET(x)                                 (((0 | (x)) << PHY_CTRL_0_VEC_FRAG_NR_OVERRIDE_LSB) & PHY_CTRL_0_VEC_FRAG_NR_OVERRIDE_MASK)
#define PHY_CTRL_0_VEC_FRAG_NR_OVERRIDE_RESET                                  0x0
#define PHY_CTRL_0_VEC_FRAG_NR_LSB                                             20
#define PHY_CTRL_0_VEC_FRAG_NR_MSB                                             22
#define PHY_CTRL_0_VEC_FRAG_NR_MASK                                            0x700000
#define PHY_CTRL_0_VEC_FRAG_NR_GET(x)                                          (((x) & PHY_CTRL_0_VEC_FRAG_NR_MASK) >> PHY_CTRL_0_VEC_FRAG_NR_LSB)
#define PHY_CTRL_0_VEC_FRAG_NR_SET(x)                                          (((0 | (x)) << PHY_CTRL_0_VEC_FRAG_NR_LSB) & PHY_CTRL_0_VEC_FRAG_NR_MASK)
#define PHY_CTRL_0_VEC_FRAG_NR_RESET                                           0x0
#define PHY_CTRL_0_VEC_FRAG_NC_OVERRIDE_LSB                                    19
#define PHY_CTRL_0_VEC_FRAG_NC_OVERRIDE_MSB                                    19
#define PHY_CTRL_0_VEC_FRAG_NC_OVERRIDE_MASK                                   0x80000
#define PHY_CTRL_0_VEC_FRAG_NC_OVERRIDE_GET(x)                                 (((x) & PHY_CTRL_0_VEC_FRAG_NC_OVERRIDE_MASK) >> PHY_CTRL_0_VEC_FRAG_NC_OVERRIDE_LSB)
#define PHY_CTRL_0_VEC_FRAG_NC_OVERRIDE_SET(x)                                 (((0 | (x)) << PHY_CTRL_0_VEC_FRAG_NC_OVERRIDE_LSB) & PHY_CTRL_0_VEC_FRAG_NC_OVERRIDE_MASK)
#define PHY_CTRL_0_VEC_FRAG_NC_OVERRIDE_RESET                                  0x0
#define PHY_CTRL_0_VEC_FRAG_NC_LSB                                             16
#define PHY_CTRL_0_VEC_FRAG_NC_MSB                                             18
#define PHY_CTRL_0_VEC_FRAG_NC_MASK                                            0x70000
#define PHY_CTRL_0_VEC_FRAG_NC_GET(x)                                          (((x) & PHY_CTRL_0_VEC_FRAG_NC_MASK) >> PHY_CTRL_0_VEC_FRAG_NC_LSB)
#define PHY_CTRL_0_VEC_FRAG_NC_SET(x)                                          (((0 | (x)) << PHY_CTRL_0_VEC_FRAG_NC_LSB) & PHY_CTRL_0_VEC_FRAG_NC_MASK)
#define PHY_CTRL_0_VEC_FRAG_NC_RESET                                           0x0
#define PHY_CTRL_0_RSVD_0_LSB                                                  12
#define PHY_CTRL_0_RSVD_0_MSB                                                  15
#define PHY_CTRL_0_RSVD_0_MASK                                                 0xf000
#define PHY_CTRL_0_RSVD_0_GET(x)                                               (((x) & PHY_CTRL_0_RSVD_0_MASK) >> PHY_CTRL_0_RSVD_0_LSB)
#define PHY_CTRL_0_RSVD_0_SET(x)                                               (((0 | (x)) << PHY_CTRL_0_RSVD_0_LSB) & PHY_CTRL_0_RSVD_0_MASK)
#define PHY_CTRL_0_RSVD_0_RESET                                                0x0
#define PHY_CTRL_0_RX_CLR_STOMP_EN_LSB                                         8
#define PHY_CTRL_0_RX_CLR_STOMP_EN_MSB                                         11
#define PHY_CTRL_0_RX_CLR_STOMP_EN_MASK                                        0xf00
#define PHY_CTRL_0_RX_CLR_STOMP_EN_GET(x)                                      (((x) & PHY_CTRL_0_RX_CLR_STOMP_EN_MASK) >> PHY_CTRL_0_RX_CLR_STOMP_EN_LSB)
#define PHY_CTRL_0_RX_CLR_STOMP_EN_SET(x)                                      (((0 | (x)) << PHY_CTRL_0_RX_CLR_STOMP_EN_LSB) & PHY_CTRL_0_RX_CLR_STOMP_EN_MASK)
#define PHY_CTRL_0_RX_CLR_STOMP_EN_RESET                                       0x0
#define PHY_CTRL_0_RX_DELAY_LSB                                                4
#define PHY_CTRL_0_RX_DELAY_MSB                                                7
#define PHY_CTRL_0_RX_DELAY_MASK                                               0xf0
#define PHY_CTRL_0_RX_DELAY_GET(x)                                             (((x) & PHY_CTRL_0_RX_DELAY_MASK) >> PHY_CTRL_0_RX_DELAY_LSB)
#define PHY_CTRL_0_RX_DELAY_SET(x)                                             (((0 | (x)) << PHY_CTRL_0_RX_DELAY_LSB) & PHY_CTRL_0_RX_DELAY_MASK)
#define PHY_CTRL_0_RX_DELAY_RESET                                              0x0
#define PHY_CTRL_0_TX_DELAY_LSB                                                0
#define PHY_CTRL_0_TX_DELAY_MSB                                                3
#define PHY_CTRL_0_TX_DELAY_MASK                                               0xf
#define PHY_CTRL_0_TX_DELAY_GET(x)                                             (((x) & PHY_CTRL_0_TX_DELAY_MASK) >> PHY_CTRL_0_TX_DELAY_LSB)
#define PHY_CTRL_0_TX_DELAY_SET(x)                                             (((0 | (x)) << PHY_CTRL_0_TX_DELAY_LSB) & PHY_CTRL_0_TX_DELAY_MASK)
#define PHY_CTRL_0_TX_DELAY_RESET                                              0x2
#define PHY_CTRL_0_ADDRESS                                                     (0x0 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_CTRL_0_RSTMASK                                                     0xffffffff
#define PHY_CTRL_0_RESET                                                       0x10000002

// 0x4 (PHY_CTRL_1)
#define PHY_CTRL_1_RSVD_2_LSB                                                  29
#define PHY_CTRL_1_RSVD_2_MSB                                                  31
#define PHY_CTRL_1_RSVD_2_MASK                                                 0xe0000000
#define PHY_CTRL_1_RSVD_2_GET(x)                                               (((x) & PHY_CTRL_1_RSVD_2_MASK) >> PHY_CTRL_1_RSVD_2_LSB)
#define PHY_CTRL_1_RSVD_2_SET(x)                                               (((0 | (x)) << PHY_CTRL_1_RSVD_2_LSB) & PHY_CTRL_1_RSVD_2_MASK)
#define PHY_CTRL_1_RSVD_2_RESET                                                0x0
#define PHY_CTRL_1_RX_CLR_SWP_OVERRIDE_LSB                                     28
#define PHY_CTRL_1_RX_CLR_SWP_OVERRIDE_MSB                                     28
#define PHY_CTRL_1_RX_CLR_SWP_OVERRIDE_MASK                                    0x10000000
#define PHY_CTRL_1_RX_CLR_SWP_OVERRIDE_GET(x)                                  (((x) & PHY_CTRL_1_RX_CLR_SWP_OVERRIDE_MASK) >> PHY_CTRL_1_RX_CLR_SWP_OVERRIDE_LSB)
#define PHY_CTRL_1_RX_CLR_SWP_OVERRIDE_SET(x)                                  (((0 | (x)) << PHY_CTRL_1_RX_CLR_SWP_OVERRIDE_LSB) & PHY_CTRL_1_RX_CLR_SWP_OVERRIDE_MASK)
#define PHY_CTRL_1_RX_CLR_SWP_OVERRIDE_RESET                                   0x1
#define PHY_CTRL_1_RX_CLR_S80_OVERRIDE_LSB                                     27
#define PHY_CTRL_1_RX_CLR_S80_OVERRIDE_MSB                                     27
#define PHY_CTRL_1_RX_CLR_S80_OVERRIDE_MASK                                    0x8000000
#define PHY_CTRL_1_RX_CLR_S80_OVERRIDE_GET(x)                                  (((x) & PHY_CTRL_1_RX_CLR_S80_OVERRIDE_MASK) >> PHY_CTRL_1_RX_CLR_S80_OVERRIDE_LSB)
#define PHY_CTRL_1_RX_CLR_S80_OVERRIDE_SET(x)                                  (((0 | (x)) << PHY_CTRL_1_RX_CLR_S80_OVERRIDE_LSB) & PHY_CTRL_1_RX_CLR_S80_OVERRIDE_MASK)
#define PHY_CTRL_1_RX_CLR_S80_OVERRIDE_RESET                                   0x1
#define PHY_CTRL_1_RX_CLR_S40_OVERRIDE_LSB                                     26
#define PHY_CTRL_1_RX_CLR_S40_OVERRIDE_MSB                                     26
#define PHY_CTRL_1_RX_CLR_S40_OVERRIDE_MASK                                    0x4000000
#define PHY_CTRL_1_RX_CLR_S40_OVERRIDE_GET(x)                                  (((x) & PHY_CTRL_1_RX_CLR_S40_OVERRIDE_MASK) >> PHY_CTRL_1_RX_CLR_S40_OVERRIDE_LSB)
#define PHY_CTRL_1_RX_CLR_S40_OVERRIDE_SET(x)                                  (((0 | (x)) << PHY_CTRL_1_RX_CLR_S40_OVERRIDE_LSB) & PHY_CTRL_1_RX_CLR_S40_OVERRIDE_MASK)
#define PHY_CTRL_1_RX_CLR_S40_OVERRIDE_RESET                                   0x1
#define PHY_CTRL_1_RX_CLR_S20_OVERRIDE_LSB                                     25
#define PHY_CTRL_1_RX_CLR_S20_OVERRIDE_MSB                                     25
#define PHY_CTRL_1_RX_CLR_S20_OVERRIDE_MASK                                    0x2000000
#define PHY_CTRL_1_RX_CLR_S20_OVERRIDE_GET(x)                                  (((x) & PHY_CTRL_1_RX_CLR_S20_OVERRIDE_MASK) >> PHY_CTRL_1_RX_CLR_S20_OVERRIDE_LSB)
#define PHY_CTRL_1_RX_CLR_S20_OVERRIDE_SET(x)                                  (((0 | (x)) << PHY_CTRL_1_RX_CLR_S20_OVERRIDE_LSB) & PHY_CTRL_1_RX_CLR_S20_OVERRIDE_MASK)
#define PHY_CTRL_1_RX_CLR_S20_OVERRIDE_RESET                                   0x1
#define PHY_CTRL_1_RX_CLR_PRI_OVERRIDE_LSB                                     24
#define PHY_CTRL_1_RX_CLR_PRI_OVERRIDE_MSB                                     24
#define PHY_CTRL_1_RX_CLR_PRI_OVERRIDE_MASK                                    0x1000000
#define PHY_CTRL_1_RX_CLR_PRI_OVERRIDE_GET(x)                                  (((x) & PHY_CTRL_1_RX_CLR_PRI_OVERRIDE_MASK) >> PHY_CTRL_1_RX_CLR_PRI_OVERRIDE_LSB)
#define PHY_CTRL_1_RX_CLR_PRI_OVERRIDE_SET(x)                                  (((0 | (x)) << PHY_CTRL_1_RX_CLR_PRI_OVERRIDE_LSB) & PHY_CTRL_1_RX_CLR_PRI_OVERRIDE_MASK)
#define PHY_CTRL_1_RX_CLR_PRI_OVERRIDE_RESET                                   0x1
#define PHY_CTRL_1_PPDU_END_NON_ERR_RATE_LSB                                   16
#define PHY_CTRL_1_PPDU_END_NON_ERR_RATE_MSB                                   23
#define PHY_CTRL_1_PPDU_END_NON_ERR_RATE_MASK                                  0xff0000
#define PHY_CTRL_1_PPDU_END_NON_ERR_RATE_GET(x)                                (((x) & PHY_CTRL_1_PPDU_END_NON_ERR_RATE_MASK) >> PHY_CTRL_1_PPDU_END_NON_ERR_RATE_LSB)
#define PHY_CTRL_1_PPDU_END_NON_ERR_RATE_SET(x)                                (((0 | (x)) << PHY_CTRL_1_PPDU_END_NON_ERR_RATE_LSB) & PHY_CTRL_1_PPDU_END_NON_ERR_RATE_MASK)
#define PHY_CTRL_1_PPDU_END_NON_ERR_RATE_RESET                                 0x3
#define PHY_CTRL_1_PKT_END_NON_ERR_RATE_LSB                                    8
#define PHY_CTRL_1_PKT_END_NON_ERR_RATE_MSB                                    15
#define PHY_CTRL_1_PKT_END_NON_ERR_RATE_MASK                                   0xff00
#define PHY_CTRL_1_PKT_END_NON_ERR_RATE_GET(x)                                 (((x) & PHY_CTRL_1_PKT_END_NON_ERR_RATE_MASK) >> PHY_CTRL_1_PKT_END_NON_ERR_RATE_LSB)
#define PHY_CTRL_1_PKT_END_NON_ERR_RATE_SET(x)                                 (((0 | (x)) << PHY_CTRL_1_PKT_END_NON_ERR_RATE_LSB) & PHY_CTRL_1_PKT_END_NON_ERR_RATE_MASK)
#define PHY_CTRL_1_PKT_END_NON_ERR_RATE_RESET                                  0x4
#define PHY_CTRL_1_RSVD_1_LSB                                                  6
#define PHY_CTRL_1_RSVD_1_MSB                                                  7
#define PHY_CTRL_1_RSVD_1_MASK                                                 0xc0
#define PHY_CTRL_1_RSVD_1_GET(x)                                               (((x) & PHY_CTRL_1_RSVD_1_MASK) >> PHY_CTRL_1_RSVD_1_LSB)
#define PHY_CTRL_1_RSVD_1_SET(x)                                               (((0 | (x)) << PHY_CTRL_1_RSVD_1_LSB) & PHY_CTRL_1_RSVD_1_MASK)
#define PHY_CTRL_1_RSVD_1_RESET                                                0x0
#define PHY_CTRL_1_PPDU_END_ERR_INJECT_ENABLE_LSB                              5
#define PHY_CTRL_1_PPDU_END_ERR_INJECT_ENABLE_MSB                              5
#define PHY_CTRL_1_PPDU_END_ERR_INJECT_ENABLE_MASK                             0x20
#define PHY_CTRL_1_PPDU_END_ERR_INJECT_ENABLE_GET(x)                           (((x) & PHY_CTRL_1_PPDU_END_ERR_INJECT_ENABLE_MASK) >> PHY_CTRL_1_PPDU_END_ERR_INJECT_ENABLE_LSB)
#define PHY_CTRL_1_PPDU_END_ERR_INJECT_ENABLE_SET(x)                           (((0 | (x)) << PHY_CTRL_1_PPDU_END_ERR_INJECT_ENABLE_LSB) & PHY_CTRL_1_PPDU_END_ERR_INJECT_ENABLE_MASK)
#define PHY_CTRL_1_PPDU_END_ERR_INJECT_ENABLE_RESET                            0x0
#define PHY_CTRL_1_PKT_END_ERR_INJECT_ENABLE_LSB                               4
#define PHY_CTRL_1_PKT_END_ERR_INJECT_ENABLE_MSB                               4
#define PHY_CTRL_1_PKT_END_ERR_INJECT_ENABLE_MASK                              0x10
#define PHY_CTRL_1_PKT_END_ERR_INJECT_ENABLE_GET(x)                            (((x) & PHY_CTRL_1_PKT_END_ERR_INJECT_ENABLE_MASK) >> PHY_CTRL_1_PKT_END_ERR_INJECT_ENABLE_LSB)
#define PHY_CTRL_1_PKT_END_ERR_INJECT_ENABLE_SET(x)                            (((0 | (x)) << PHY_CTRL_1_PKT_END_ERR_INJECT_ENABLE_LSB) & PHY_CTRL_1_PKT_END_ERR_INJECT_ENABLE_MASK)
#define PHY_CTRL_1_PKT_END_ERR_INJECT_ENABLE_RESET                             0x0
#define PHY_CTRL_1_RSVD_0_LSB                                                  2
#define PHY_CTRL_1_RSVD_0_MSB                                                  3
#define PHY_CTRL_1_RSVD_0_MASK                                                 0xc
#define PHY_CTRL_1_RSVD_0_GET(x)                                               (((x) & PHY_CTRL_1_RSVD_0_MASK) >> PHY_CTRL_1_RSVD_0_LSB)
#define PHY_CTRL_1_RSVD_0_SET(x)                                               (((0 | (x)) << PHY_CTRL_1_RSVD_0_LSB) & PHY_CTRL_1_RSVD_0_MASK)
#define PHY_CTRL_1_RSVD_0_RESET                                                0x0
#define PHY_CTRL_1_VEC_FRAG_OPT_H_LSB                                          1
#define PHY_CTRL_1_VEC_FRAG_OPT_H_MSB                                          1
#define PHY_CTRL_1_VEC_FRAG_OPT_H_MASK                                         0x2
#define PHY_CTRL_1_VEC_FRAG_OPT_H_GET(x)                                       (((x) & PHY_CTRL_1_VEC_FRAG_OPT_H_MASK) >> PHY_CTRL_1_VEC_FRAG_OPT_H_LSB)
#define PHY_CTRL_1_VEC_FRAG_OPT_H_SET(x)                                       (((0 | (x)) << PHY_CTRL_1_VEC_FRAG_OPT_H_LSB) & PHY_CTRL_1_VEC_FRAG_OPT_H_MASK)
#define PHY_CTRL_1_VEC_FRAG_OPT_H_RESET                                        0x0
#define PHY_CTRL_1_IMPLICIT_BF_SOUNDING_LSB                                    0
#define PHY_CTRL_1_IMPLICIT_BF_SOUNDING_MSB                                    0
#define PHY_CTRL_1_IMPLICIT_BF_SOUNDING_MASK                                   0x1
#define PHY_CTRL_1_IMPLICIT_BF_SOUNDING_GET(x)                                 (((x) & PHY_CTRL_1_IMPLICIT_BF_SOUNDING_MASK) >> PHY_CTRL_1_IMPLICIT_BF_SOUNDING_LSB)
#define PHY_CTRL_1_IMPLICIT_BF_SOUNDING_SET(x)                                 (((0 | (x)) << PHY_CTRL_1_IMPLICIT_BF_SOUNDING_LSB) & PHY_CTRL_1_IMPLICIT_BF_SOUNDING_MASK)
#define PHY_CTRL_1_IMPLICIT_BF_SOUNDING_RESET                                  0x0
#define PHY_CTRL_1_ADDRESS                                                     (0x4 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_CTRL_1_RSTMASK                                                     0xffffffff
#define PHY_CTRL_1_RESET                                                       0x1f030400

// 0x8 (PHY_CTRL_2)
#define PHY_CTRL_2_RSVD_LSB                                                    8
#define PHY_CTRL_2_RSVD_MSB                                                    31
#define PHY_CTRL_2_RSVD_MASK                                                   0xffffff00
#define PHY_CTRL_2_RSVD_GET(x)                                                 (((x) & PHY_CTRL_2_RSVD_MASK) >> PHY_CTRL_2_RSVD_LSB)
#define PHY_CTRL_2_RSVD_SET(x)                                                 (((0 | (x)) << PHY_CTRL_2_RSVD_LSB) & PHY_CTRL_2_RSVD_MASK)
#define PHY_CTRL_2_RSVD_RESET                                                  0x0
#define PHY_CTRL_2_PKT_END_ERR_MASK_LSB                                        0
#define PHY_CTRL_2_PKT_END_ERR_MASK_MSB                                        7
#define PHY_CTRL_2_PKT_END_ERR_MASK_MASK                                       0xff
#define PHY_CTRL_2_PKT_END_ERR_MASK_GET(x)                                     (((x) & PHY_CTRL_2_PKT_END_ERR_MASK_MASK) >> PHY_CTRL_2_PKT_END_ERR_MASK_LSB)
#define PHY_CTRL_2_PKT_END_ERR_MASK_SET(x)                                     (((0 | (x)) << PHY_CTRL_2_PKT_END_ERR_MASK_LSB) & PHY_CTRL_2_PKT_END_ERR_MASK_MASK)
#define PHY_CTRL_2_PKT_END_ERR_MASK_RESET                                      0xf8
#define PHY_CTRL_2_ADDRESS                                                     (0x8 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_CTRL_2_RSTMASK                                                     0xffffffff
#define PHY_CTRL_2_RESET                                                       0xf8

// 0xc (PHY_CTRL_3)
#define PHY_CTRL_3_PPDU_END_ERR_MASK_LO_LSB                                    0
#define PHY_CTRL_3_PPDU_END_ERR_MASK_LO_MSB                                    31
#define PHY_CTRL_3_PPDU_END_ERR_MASK_LO_MASK                                   0xffffffff
#define PHY_CTRL_3_PPDU_END_ERR_MASK_LO_GET(x)                                 (((x) & PHY_CTRL_3_PPDU_END_ERR_MASK_LO_MASK) >> PHY_CTRL_3_PPDU_END_ERR_MASK_LO_LSB)
#define PHY_CTRL_3_PPDU_END_ERR_MASK_LO_SET(x)                                 (((0 | (x)) << PHY_CTRL_3_PPDU_END_ERR_MASK_LO_LSB) & PHY_CTRL_3_PPDU_END_ERR_MASK_LO_MASK)
#define PHY_CTRL_3_PPDU_END_ERR_MASK_LO_RESET                                  0xfff5f5fc
#define PHY_CTRL_3_ADDRESS                                                     (0xc + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_CTRL_3_RSTMASK                                                     0xffffffff
#define PHY_CTRL_3_RESET                                                       0xfff5f5fc

// 0x10 (PHY_CTRL_4)
#define PHY_CTRL_4_PPDU_END_ERR_MASK_HI_LSB                                    0
#define PHY_CTRL_4_PPDU_END_ERR_MASK_HI_MSB                                    31
#define PHY_CTRL_4_PPDU_END_ERR_MASK_HI_MASK                                   0xffffffff
#define PHY_CTRL_4_PPDU_END_ERR_MASK_HI_GET(x)                                 (((x) & PHY_CTRL_4_PPDU_END_ERR_MASK_HI_MASK) >> PHY_CTRL_4_PPDU_END_ERR_MASK_HI_LSB)
#define PHY_CTRL_4_PPDU_END_ERR_MASK_HI_SET(x)                                 (((0 | (x)) << PHY_CTRL_4_PPDU_END_ERR_MASK_HI_LSB) & PHY_CTRL_4_PPDU_END_ERR_MASK_HI_MASK)
#define PHY_CTRL_4_PPDU_END_ERR_MASK_HI_RESET                                  0x3ff
#define PHY_CTRL_4_ADDRESS                                                     (0x10 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_CTRL_4_RSTMASK                                                     0xffffffff
#define PHY_CTRL_4_RESET                                                       0x3ff

// 0x14 (PHY_CTRL_5)
#define PHY_CTRL_5_PPDU_END_ZL_ERR_LO_LSB                                      0
#define PHY_CTRL_5_PPDU_END_ZL_ERR_LO_MSB                                      31
#define PHY_CTRL_5_PPDU_END_ZL_ERR_LO_MASK                                     0xffffffff
#define PHY_CTRL_5_PPDU_END_ZL_ERR_LO_GET(x)                                   (((x) & PHY_CTRL_5_PPDU_END_ZL_ERR_LO_MASK) >> PHY_CTRL_5_PPDU_END_ZL_ERR_LO_LSB)
#define PHY_CTRL_5_PPDU_END_ZL_ERR_LO_SET(x)                                   (((0 | (x)) << PHY_CTRL_5_PPDU_END_ZL_ERR_LO_LSB) & PHY_CTRL_5_PPDU_END_ZL_ERR_LO_MASK)
#define PHY_CTRL_5_PPDU_END_ZL_ERR_LO_RESET                                    0xfaf5f5e0
#define PHY_CTRL_5_ADDRESS                                                     (0x14 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_CTRL_5_RSTMASK                                                     0xffffffff
#define PHY_CTRL_5_RESET                                                       0xfaf5f5e0

// 0x18 (PHY_CTRL_6)
#define PHY_CTRL_6_PPDU_END_ZL_ERR_HI_LSB                                      0
#define PHY_CTRL_6_PPDU_END_ZL_ERR_HI_MSB                                      31
#define PHY_CTRL_6_PPDU_END_ZL_ERR_HI_MASK                                     0xffffffff
#define PHY_CTRL_6_PPDU_END_ZL_ERR_HI_GET(x)                                   (((x) & PHY_CTRL_6_PPDU_END_ZL_ERR_HI_MASK) >> PHY_CTRL_6_PPDU_END_ZL_ERR_HI_LSB)
#define PHY_CTRL_6_PPDU_END_ZL_ERR_HI_SET(x)                                   (((0 | (x)) << PHY_CTRL_6_PPDU_END_ZL_ERR_HI_LSB) & PHY_CTRL_6_PPDU_END_ZL_ERR_HI_MASK)
#define PHY_CTRL_6_PPDU_END_ZL_ERR_HI_RESET                                    0x27f
#define PHY_CTRL_6_ADDRESS                                                     (0x18 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_CTRL_6_RSTMASK                                                     0xffffffff
#define PHY_CTRL_6_RESET                                                       0x27f

// 0x1c (PHY_CTRL_7)
#define PHY_CTRL_7_PPDU_END_NZ_ERR_LO_LSB                                      0
#define PHY_CTRL_7_PPDU_END_NZ_ERR_LO_MSB                                      31
#define PHY_CTRL_7_PPDU_END_NZ_ERR_LO_MASK                                     0xffffffff
#define PHY_CTRL_7_PPDU_END_NZ_ERR_LO_GET(x)                                   (((x) & PHY_CTRL_7_PPDU_END_NZ_ERR_LO_MASK) >> PHY_CTRL_7_PPDU_END_NZ_ERR_LO_LSB)
#define PHY_CTRL_7_PPDU_END_NZ_ERR_LO_SET(x)                                   (((0 | (x)) << PHY_CTRL_7_PPDU_END_NZ_ERR_LO_LSB) & PHY_CTRL_7_PPDU_END_NZ_ERR_LO_MASK)
#define PHY_CTRL_7_PPDU_END_NZ_ERR_LO_RESET                                    0x5000014
#define PHY_CTRL_7_ADDRESS                                                     (0x1c + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_CTRL_7_RSTMASK                                                     0xffffffff
#define PHY_CTRL_7_RESET                                                       0x5000014

// 0x20 (PHY_CTRL_8)
#define PHY_CTRL_8_PPDU_END_NZ_ERR_HI_LSB                                      0
#define PHY_CTRL_8_PPDU_END_NZ_ERR_HI_MSB                                      31
#define PHY_CTRL_8_PPDU_END_NZ_ERR_HI_MASK                                     0xffffffff
#define PHY_CTRL_8_PPDU_END_NZ_ERR_HI_GET(x)                                   (((x) & PHY_CTRL_8_PPDU_END_NZ_ERR_HI_MASK) >> PHY_CTRL_8_PPDU_END_NZ_ERR_HI_LSB)
#define PHY_CTRL_8_PPDU_END_NZ_ERR_HI_SET(x)                                   (((0 | (x)) << PHY_CTRL_8_PPDU_END_NZ_ERR_HI_LSB) & PHY_CTRL_8_PPDU_END_NZ_ERR_HI_MASK)
#define PHY_CTRL_8_PPDU_END_NZ_ERR_HI_RESET                                    0x180
#define PHY_CTRL_8_ADDRESS                                                     (0x20 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_CTRL_8_RSTMASK                                                     0xffffffff
#define PHY_CTRL_8_RESET                                                       0x180

// 0x24 (PHY_STOMP_PRI_CLR)
#define PHY_STOMP_PRI_CLR_CNT_LSB                                              0
#define PHY_STOMP_PRI_CLR_CNT_MSB                                              31
#define PHY_STOMP_PRI_CLR_CNT_MASK                                             0xffffffff
#define PHY_STOMP_PRI_CLR_CNT_GET(x)                                           (((x) & PHY_STOMP_PRI_CLR_CNT_MASK) >> PHY_STOMP_PRI_CLR_CNT_LSB)
#define PHY_STOMP_PRI_CLR_CNT_SET(x)                                           (((0 | (x)) << PHY_STOMP_PRI_CLR_CNT_LSB) & PHY_STOMP_PRI_CLR_CNT_MASK)
#define PHY_STOMP_PRI_CLR_CNT_RESET                                            0x0
#define PHY_STOMP_PRI_CLR_ADDRESS                                              (0x24 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_STOMP_PRI_CLR_RSTMASK                                              0xffffffff
#define PHY_STOMP_PRI_CLR_RESET                                                0x0

// 0x28 (PHY_STOMP_PRI_BUSY)
#define PHY_STOMP_PRI_BUSY_CNT_LSB                                             0
#define PHY_STOMP_PRI_BUSY_CNT_MSB                                             31
#define PHY_STOMP_PRI_BUSY_CNT_MASK                                            0xffffffff
#define PHY_STOMP_PRI_BUSY_CNT_GET(x)                                          (((x) & PHY_STOMP_PRI_BUSY_CNT_MASK) >> PHY_STOMP_PRI_BUSY_CNT_LSB)
#define PHY_STOMP_PRI_BUSY_CNT_SET(x)                                          (((0 | (x)) << PHY_STOMP_PRI_BUSY_CNT_LSB) & PHY_STOMP_PRI_BUSY_CNT_MASK)
#define PHY_STOMP_PRI_BUSY_CNT_RESET                                           0x0
#define PHY_STOMP_PRI_BUSY_ADDRESS                                             (0x28 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_STOMP_PRI_BUSY_RSTMASK                                             0xffffffff
#define PHY_STOMP_PRI_BUSY_RESET                                               0x0

// 0x2c (PHY_STOMP_SEC20_CLR)
#define PHY_STOMP_SEC20_CLR_CNT_LSB                                            0
#define PHY_STOMP_SEC20_CLR_CNT_MSB                                            31
#define PHY_STOMP_SEC20_CLR_CNT_MASK                                           0xffffffff
#define PHY_STOMP_SEC20_CLR_CNT_GET(x)                                         (((x) & PHY_STOMP_SEC20_CLR_CNT_MASK) >> PHY_STOMP_SEC20_CLR_CNT_LSB)
#define PHY_STOMP_SEC20_CLR_CNT_SET(x)                                         (((0 | (x)) << PHY_STOMP_SEC20_CLR_CNT_LSB) & PHY_STOMP_SEC20_CLR_CNT_MASK)
#define PHY_STOMP_SEC20_CLR_CNT_RESET                                          0x0
#define PHY_STOMP_SEC20_CLR_ADDRESS                                            (0x2c + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_STOMP_SEC20_CLR_RSTMASK                                            0xffffffff
#define PHY_STOMP_SEC20_CLR_RESET                                              0x0

// 0x30 (PHY_STOMP_SEC20_BUSY)
#define PHY_STOMP_SEC20_BUSY_CNT_LSB                                           0
#define PHY_STOMP_SEC20_BUSY_CNT_MSB                                           31
#define PHY_STOMP_SEC20_BUSY_CNT_MASK                                          0xffffffff
#define PHY_STOMP_SEC20_BUSY_CNT_GET(x)                                        (((x) & PHY_STOMP_SEC20_BUSY_CNT_MASK) >> PHY_STOMP_SEC20_BUSY_CNT_LSB)
#define PHY_STOMP_SEC20_BUSY_CNT_SET(x)                                        (((0 | (x)) << PHY_STOMP_SEC20_BUSY_CNT_LSB) & PHY_STOMP_SEC20_BUSY_CNT_MASK)
#define PHY_STOMP_SEC20_BUSY_CNT_RESET                                         0x0
#define PHY_STOMP_SEC20_BUSY_ADDRESS                                           (0x30 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_STOMP_SEC20_BUSY_RSTMASK                                           0xffffffff
#define PHY_STOMP_SEC20_BUSY_RESET                                             0x0

// 0x34 (PHY_STOMP_SEC40_CLR)
#define PHY_STOMP_SEC40_CLR_CNT_LSB                                            0
#define PHY_STOMP_SEC40_CLR_CNT_MSB                                            31
#define PHY_STOMP_SEC40_CLR_CNT_MASK                                           0xffffffff
#define PHY_STOMP_SEC40_CLR_CNT_GET(x)                                         (((x) & PHY_STOMP_SEC40_CLR_CNT_MASK) >> PHY_STOMP_SEC40_CLR_CNT_LSB)
#define PHY_STOMP_SEC40_CLR_CNT_SET(x)                                         (((0 | (x)) << PHY_STOMP_SEC40_CLR_CNT_LSB) & PHY_STOMP_SEC40_CLR_CNT_MASK)
#define PHY_STOMP_SEC40_CLR_CNT_RESET                                          0x0
#define PHY_STOMP_SEC40_CLR_ADDRESS                                            (0x34 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_STOMP_SEC40_CLR_RSTMASK                                            0xffffffff
#define PHY_STOMP_SEC40_CLR_RESET                                              0x0

// 0x38 (PHY_STOMP_SEC40_BUSY)
#define PHY_STOMP_SEC40_BUSY_CNT_LSB                                           0
#define PHY_STOMP_SEC40_BUSY_CNT_MSB                                           31
#define PHY_STOMP_SEC40_BUSY_CNT_MASK                                          0xffffffff
#define PHY_STOMP_SEC40_BUSY_CNT_GET(x)                                        (((x) & PHY_STOMP_SEC40_BUSY_CNT_MASK) >> PHY_STOMP_SEC40_BUSY_CNT_LSB)
#define PHY_STOMP_SEC40_BUSY_CNT_SET(x)                                        (((0 | (x)) << PHY_STOMP_SEC40_BUSY_CNT_LSB) & PHY_STOMP_SEC40_BUSY_CNT_MASK)
#define PHY_STOMP_SEC40_BUSY_CNT_RESET                                         0x0
#define PHY_STOMP_SEC40_BUSY_ADDRESS                                           (0x38 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_STOMP_SEC40_BUSY_RSTMASK                                           0xffffffff
#define PHY_STOMP_SEC40_BUSY_RESET                                             0x0

// 0x3c (PHY_STOMP_SEC80_CLR)
#define PHY_STOMP_SEC80_CLR_CNT_LSB                                            0
#define PHY_STOMP_SEC80_CLR_CNT_MSB                                            31
#define PHY_STOMP_SEC80_CLR_CNT_MASK                                           0xffffffff
#define PHY_STOMP_SEC80_CLR_CNT_GET(x)                                         (((x) & PHY_STOMP_SEC80_CLR_CNT_MASK) >> PHY_STOMP_SEC80_CLR_CNT_LSB)
#define PHY_STOMP_SEC80_CLR_CNT_SET(x)                                         (((0 | (x)) << PHY_STOMP_SEC80_CLR_CNT_LSB) & PHY_STOMP_SEC80_CLR_CNT_MASK)
#define PHY_STOMP_SEC80_CLR_CNT_RESET                                          0x0
#define PHY_STOMP_SEC80_CLR_ADDRESS                                            (0x3c + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_STOMP_SEC80_CLR_RSTMASK                                            0xffffffff
#define PHY_STOMP_SEC80_CLR_RESET                                              0x0

// 0x40 (PHY_STOMP_SEC80_BUSY)
#define PHY_STOMP_SEC80_BUSY_CNT_LSB                                           0
#define PHY_STOMP_SEC80_BUSY_CNT_MSB                                           31
#define PHY_STOMP_SEC80_BUSY_CNT_MASK                                          0xffffffff
#define PHY_STOMP_SEC80_BUSY_CNT_GET(x)                                        (((x) & PHY_STOMP_SEC80_BUSY_CNT_MASK) >> PHY_STOMP_SEC80_BUSY_CNT_LSB)
#define PHY_STOMP_SEC80_BUSY_CNT_SET(x)                                        (((0 | (x)) << PHY_STOMP_SEC80_BUSY_CNT_LSB) & PHY_STOMP_SEC80_BUSY_CNT_MASK)
#define PHY_STOMP_SEC80_BUSY_CNT_RESET                                         0x0
#define PHY_STOMP_SEC80_BUSY_ADDRESS                                           (0x40 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_STOMP_SEC80_BUSY_RSTMASK                                           0xffffffff
#define PHY_STOMP_SEC80_BUSY_RESET                                             0x0

// 0x44 (PHY_DATA_0)
#define PHY_DATA_0_RSSI_LSB                                                    0
#define PHY_DATA_0_RSSI_MSB                                                    31
#define PHY_DATA_0_RSSI_MASK                                                   0xffffffff
#define PHY_DATA_0_RSSI_GET(x)                                                 (((x) & PHY_DATA_0_RSSI_MASK) >> PHY_DATA_0_RSSI_LSB)
#define PHY_DATA_0_RSSI_SET(x)                                                 (((0 | (x)) << PHY_DATA_0_RSSI_LSB) & PHY_DATA_0_RSSI_MASK)
#define PHY_DATA_0_RSSI_RESET                                                  0x43424140
#define PHY_DATA_0_ADDRESS                                                     (0x44 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_0_RSTMASK                                                     0xffffffff
#define PHY_DATA_0_RESET                                                       0x43424140

// 0x48 (PHY_DATA_1)
#define PHY_DATA_1_RSVD_1_LSB                                                  24
#define PHY_DATA_1_RSVD_1_MSB                                                  31
#define PHY_DATA_1_RSVD_1_MASK                                                 0xff000000
#define PHY_DATA_1_RSVD_1_GET(x)                                               (((x) & PHY_DATA_1_RSVD_1_MASK) >> PHY_DATA_1_RSVD_1_LSB)
#define PHY_DATA_1_RSVD_1_SET(x)                                               (((0 | (x)) << PHY_DATA_1_RSVD_1_LSB) & PHY_DATA_1_RSVD_1_MASK)
#define PHY_DATA_1_RSVD_1_RESET                                                0x0
#define PHY_DATA_1_TIMING_OFFSET_LSB                                           12
#define PHY_DATA_1_TIMING_OFFSET_MSB                                           23
#define PHY_DATA_1_TIMING_OFFSET_MASK                                          0xfff000
#define PHY_DATA_1_TIMING_OFFSET_GET(x)                                        (((x) & PHY_DATA_1_TIMING_OFFSET_MASK) >> PHY_DATA_1_TIMING_OFFSET_LSB)
#define PHY_DATA_1_TIMING_OFFSET_SET(x)                                        (((0 | (x)) << PHY_DATA_1_TIMING_OFFSET_LSB) & PHY_DATA_1_TIMING_OFFSET_MASK)
#define PHY_DATA_1_TIMING_OFFSET_RESET                                         0x0
#define PHY_DATA_1_RSVD_0_LSB                                                  10
#define PHY_DATA_1_RSVD_0_MSB                                                  11
#define PHY_DATA_1_RSVD_0_MASK                                                 0xc00
#define PHY_DATA_1_RSVD_0_GET(x)                                               (((x) & PHY_DATA_1_RSVD_0_MASK) >> PHY_DATA_1_RSVD_0_LSB)
#define PHY_DATA_1_RSVD_0_SET(x)                                               (((0 | (x)) << PHY_DATA_1_RSVD_0_LSB) & PHY_DATA_1_RSVD_0_MASK)
#define PHY_DATA_1_RSVD_0_RESET                                                0x0
#define PHY_DATA_1_BANDWIDTH_LSB                                               8
#define PHY_DATA_1_BANDWIDTH_MSB                                               9
#define PHY_DATA_1_BANDWIDTH_MASK                                              0x300
#define PHY_DATA_1_BANDWIDTH_GET(x)                                            (((x) & PHY_DATA_1_BANDWIDTH_MASK) >> PHY_DATA_1_BANDWIDTH_LSB)
#define PHY_DATA_1_BANDWIDTH_SET(x)                                            (((0 | (x)) << PHY_DATA_1_BANDWIDTH_LSB) & PHY_DATA_1_BANDWIDTH_MASK)
#define PHY_DATA_1_BANDWIDTH_RESET                                             0x0
#define PHY_DATA_1_RSSI_COMB_LSB                                               0
#define PHY_DATA_1_RSSI_COMB_MSB                                               7
#define PHY_DATA_1_RSSI_COMB_MASK                                              0xff
#define PHY_DATA_1_RSSI_COMB_GET(x)                                            (((x) & PHY_DATA_1_RSSI_COMB_MASK) >> PHY_DATA_1_RSSI_COMB_LSB)
#define PHY_DATA_1_RSSI_COMB_SET(x)                                            (((0 | (x)) << PHY_DATA_1_RSSI_COMB_LSB) & PHY_DATA_1_RSSI_COMB_MASK)
#define PHY_DATA_1_RSSI_COMB_RESET                                             0x44
#define PHY_DATA_1_ADDRESS                                                     (0x48 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_1_RSTMASK                                                     0xffffffff
#define PHY_DATA_1_RESET                                                       0x44

// 0x4c (PHY_DATA_2)
#define PHY_DATA_2_CV_LENGTH_H_LSB                                             16
#define PHY_DATA_2_CV_LENGTH_H_MSB                                             31
#define PHY_DATA_2_CV_LENGTH_H_MASK                                            0xffff0000
#define PHY_DATA_2_CV_LENGTH_H_GET(x)                                          (((x) & PHY_DATA_2_CV_LENGTH_H_MASK) >> PHY_DATA_2_CV_LENGTH_H_LSB)
#define PHY_DATA_2_CV_LENGTH_H_SET(x)                                          (((0 | (x)) << PHY_DATA_2_CV_LENGTH_H_LSB) & PHY_DATA_2_CV_LENGTH_H_MASK)
#define PHY_DATA_2_CV_LENGTH_H_RESET                                           0x3e8
#define PHY_DATA_2_CV_LENGTH_LSB                                               0
#define PHY_DATA_2_CV_LENGTH_MSB                                               15
#define PHY_DATA_2_CV_LENGTH_MASK                                              0xffff
#define PHY_DATA_2_CV_LENGTH_GET(x)                                            (((x) & PHY_DATA_2_CV_LENGTH_MASK) >> PHY_DATA_2_CV_LENGTH_LSB)
#define PHY_DATA_2_CV_LENGTH_SET(x)                                            (((0 | (x)) << PHY_DATA_2_CV_LENGTH_LSB) & PHY_DATA_2_CV_LENGTH_MASK)
#define PHY_DATA_2_CV_LENGTH_RESET                                             0x374
#define PHY_DATA_2_ADDRESS                                                     (0x4c + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_2_RSTMASK                                                     0xffffffff
#define PHY_DATA_2_RESET                                                       0x3e80374

// 0x50 (PHY_DATA_3)
#define PHY_DATA_3_VEC_FRAG_H_TLV_LSB                                          16
#define PHY_DATA_3_VEC_FRAG_H_TLV_MSB                                          31
#define PHY_DATA_3_VEC_FRAG_H_TLV_MASK                                         0xffff0000
#define PHY_DATA_3_VEC_FRAG_H_TLV_GET(x)                                       (((x) & PHY_DATA_3_VEC_FRAG_H_TLV_MASK) >> PHY_DATA_3_VEC_FRAG_H_TLV_LSB)
#define PHY_DATA_3_VEC_FRAG_H_TLV_SET(x)                                       (((0 | (x)) << PHY_DATA_3_VEC_FRAG_H_TLV_LSB) & PHY_DATA_3_VEC_FRAG_H_TLV_MASK)
#define PHY_DATA_3_VEC_FRAG_H_TLV_RESET                                        0xbbf0
#define PHY_DATA_3_VEC_FRAG_TLV_LSB                                            0
#define PHY_DATA_3_VEC_FRAG_TLV_MSB                                            15
#define PHY_DATA_3_VEC_FRAG_TLV_MASK                                           0xffff
#define PHY_DATA_3_VEC_FRAG_TLV_GET(x)                                         (((x) & PHY_DATA_3_VEC_FRAG_TLV_MASK) >> PHY_DATA_3_VEC_FRAG_TLV_LSB)
#define PHY_DATA_3_VEC_FRAG_TLV_SET(x)                                         (((0 | (x)) << PHY_DATA_3_VEC_FRAG_TLV_LSB) & PHY_DATA_3_VEC_FRAG_TLV_MASK)
#define PHY_DATA_3_VEC_FRAG_TLV_RESET                                          0xbb01
#define PHY_DATA_3_ADDRESS                                                     (0x50 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_3_RSTMASK                                                     0xffffffff
#define PHY_DATA_3_RESET                                                       0xbbf0bb01

// 0x54 (PHY_DATA_4)
#define PHY_DATA_4_VEC_FRAG_2_LSB                                              0
#define PHY_DATA_4_VEC_FRAG_2_MSB                                              31
#define PHY_DATA_4_VEC_FRAG_2_MASK                                             0xffffffff
#define PHY_DATA_4_VEC_FRAG_2_GET(x)                                           (((x) & PHY_DATA_4_VEC_FRAG_2_MASK) >> PHY_DATA_4_VEC_FRAG_2_LSB)
#define PHY_DATA_4_VEC_FRAG_2_SET(x)                                           (((0 | (x)) << PHY_DATA_4_VEC_FRAG_2_LSB) & PHY_DATA_4_VEC_FRAG_2_MASK)
#define PHY_DATA_4_VEC_FRAG_2_RESET                                            0x5000000
#define PHY_DATA_4_ADDRESS                                                     (0x54 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_4_RSTMASK                                                     0xffffffff
#define PHY_DATA_4_RESET                                                       0x5000000

// 0x58 (PHY_DATA_5)
#define PHY_DATA_5_VEC_FRAG_3_LSB                                              0
#define PHY_DATA_5_VEC_FRAG_3_MSB                                              31
#define PHY_DATA_5_VEC_FRAG_3_MASK                                             0xffffffff
#define PHY_DATA_5_VEC_FRAG_3_GET(x)                                           (((x) & PHY_DATA_5_VEC_FRAG_3_MASK) >> PHY_DATA_5_VEC_FRAG_3_LSB)
#define PHY_DATA_5_VEC_FRAG_3_SET(x)                                           (((0 | (x)) << PHY_DATA_5_VEC_FRAG_3_LSB) & PHY_DATA_5_VEC_FRAG_3_MASK)
#define PHY_DATA_5_VEC_FRAG_3_RESET                                            0x20202000
#define PHY_DATA_5_ADDRESS                                                     (0x58 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_5_RSTMASK                                                     0xffffffff
#define PHY_DATA_5_RESET                                                       0x20202000

// 0x5c (PHY_DATA_6)
#define PHY_DATA_6_VEC_FRAG_REPT_LSB                                           0
#define PHY_DATA_6_VEC_FRAG_REPT_MSB                                           31
#define PHY_DATA_6_VEC_FRAG_REPT_MASK                                          0xffffffff
#define PHY_DATA_6_VEC_FRAG_REPT_GET(x)                                        (((x) & PHY_DATA_6_VEC_FRAG_REPT_MASK) >> PHY_DATA_6_VEC_FRAG_REPT_LSB)
#define PHY_DATA_6_VEC_FRAG_REPT_SET(x)                                        (((0 | (x)) << PHY_DATA_6_VEC_FRAG_REPT_LSB) & PHY_DATA_6_VEC_FRAG_REPT_MASK)
#define PHY_DATA_6_VEC_FRAG_REPT_RESET                                         0xcbcbcbcb
#define PHY_DATA_6_ADDRESS                                                     (0x5c + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_6_RSTMASK                                                     0xffffffff
#define PHY_DATA_6_RESET                                                       0xcbcbcbcb

// 0x60 (PHY_DATA_7)
#define PHY_DATA_7_VEC_FRAG_H_REPT_LSB                                         0
#define PHY_DATA_7_VEC_FRAG_H_REPT_MSB                                         31
#define PHY_DATA_7_VEC_FRAG_H_REPT_MASK                                        0xffffffff
#define PHY_DATA_7_VEC_FRAG_H_REPT_GET(x)                                      (((x) & PHY_DATA_7_VEC_FRAG_H_REPT_MASK) >> PHY_DATA_7_VEC_FRAG_H_REPT_LSB)
#define PHY_DATA_7_VEC_FRAG_H_REPT_SET(x)                                      (((0 | (x)) << PHY_DATA_7_VEC_FRAG_H_REPT_LSB) & PHY_DATA_7_VEC_FRAG_H_REPT_MASK)
#define PHY_DATA_7_VEC_FRAG_H_REPT_RESET                                       0xaaaaaaaa
#define PHY_DATA_7_ADDRESS                                                     (0x60 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_7_RSTMASK                                                     0xffffffff
#define PHY_DATA_7_RESET                                                       0xaaaaaaaa

// 0x64 (PHY_DATA_8)
#define PHY_DATA_8_SVD_RDY_BRST_DLY_LSB                                        16
#define PHY_DATA_8_SVD_RDY_BRST_DLY_MSB                                        31
#define PHY_DATA_8_SVD_RDY_BRST_DLY_MASK                                       0xffff0000
#define PHY_DATA_8_SVD_RDY_BRST_DLY_GET(x)                                     (((x) & PHY_DATA_8_SVD_RDY_BRST_DLY_MASK) >> PHY_DATA_8_SVD_RDY_BRST_DLY_LSB)
#define PHY_DATA_8_SVD_RDY_BRST_DLY_SET(x)                                     (((0 | (x)) << PHY_DATA_8_SVD_RDY_BRST_DLY_LSB) & PHY_DATA_8_SVD_RDY_BRST_DLY_MASK)
#define PHY_DATA_8_SVD_RDY_BRST_DLY_RESET                                      0x0
#define PHY_DATA_8_SVD_RDY_DLY_LSB                                             0
#define PHY_DATA_8_SVD_RDY_DLY_MSB                                             15
#define PHY_DATA_8_SVD_RDY_DLY_MASK                                            0xffff
#define PHY_DATA_8_SVD_RDY_DLY_GET(x)                                          (((x) & PHY_DATA_8_SVD_RDY_DLY_MASK) >> PHY_DATA_8_SVD_RDY_DLY_LSB)
#define PHY_DATA_8_SVD_RDY_DLY_SET(x)                                          (((0 | (x)) << PHY_DATA_8_SVD_RDY_DLY_LSB) & PHY_DATA_8_SVD_RDY_DLY_MASK)
#define PHY_DATA_8_SVD_RDY_DLY_RESET                                           0x78
#define PHY_DATA_8_ADDRESS                                                     (0x64 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_8_RSTMASK                                                     0xffffffff
#define PHY_DATA_8_RESET                                                       0x78

// 0x68 (PHY_DATA_9)
#define PHY_DATA_9_EVM_LSB                                                     0
#define PHY_DATA_9_EVM_MSB                                                     31
#define PHY_DATA_9_EVM_MASK                                                    0xffffffff
#define PHY_DATA_9_EVM_GET(x)                                                  (((x) & PHY_DATA_9_EVM_MASK) >> PHY_DATA_9_EVM_LSB)
#define PHY_DATA_9_EVM_SET(x)                                                  (((0 | (x)) << PHY_DATA_9_EVM_LSB) & PHY_DATA_9_EVM_MASK)
#define PHY_DATA_9_EVM_RESET                                                   0x0
#define PHY_DATA_9_ADDRESS                                                     (0x68 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_9_RSTMASK                                                     0xffffffff
#define PHY_DATA_9_RESET                                                       0x0

// 0x70 (PHY_DATA_GP_USR)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_LSB                                0
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_MSB                                31
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_MASK                               0xffffffff
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_GET(x)                             (((x) & PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_MASK) >> PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_LSB)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_SET(x)                             (((0 | (x)) << PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_LSB) & PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_MASK)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_RESET                              0x0
#define PHY_DATA_GP_USR_ADDRESS                                                (0x70 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_GP_USR_RSTMASK                                                0xffffffff
#define PHY_DATA_GP_USR_RESET                                                  0x0

// 0x70 (PHY_DATA_GP_USR_0)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_0_LSB                              0
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_0_MSB                              31
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_0_MASK                             0xffffffff
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_0_GET(x)                           (((x) & PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_0_MASK) >> PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_0_LSB)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_0_SET(x)                           (((0 | (x)) << PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_0_LSB) & PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_0_MASK)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_0_RESET                            0x0
#define PHY_DATA_GP_USR_0_ADDRESS                                              (0x70 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_GP_USR_0_RSTMASK                                              0xffffffff
#define PHY_DATA_GP_USR_0_RESET                                                0x0

// 0x74 (PHY_DATA_GP_USR_1)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_1_LSB                              0
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_1_MSB                              31
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_1_MASK                             0xffffffff
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_1_GET(x)                           (((x) & PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_1_MASK) >> PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_1_LSB)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_1_SET(x)                           (((0 | (x)) << PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_1_LSB) & PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_1_MASK)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_1_RESET                            0x0
#define PHY_DATA_GP_USR_1_ADDRESS                                              (0x74 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_GP_USR_1_RSTMASK                                              0xffffffff
#define PHY_DATA_GP_USR_1_RESET                                                0x0

// 0x78 (PHY_DATA_GP_USR_2)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_2_LSB                              0
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_2_MSB                              31
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_2_MASK                             0xffffffff
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_2_GET(x)                           (((x) & PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_2_MASK) >> PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_2_LSB)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_2_SET(x)                           (((0 | (x)) << PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_2_LSB) & PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_2_MASK)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_2_RESET                            0x0
#define PHY_DATA_GP_USR_2_ADDRESS                                              (0x78 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_GP_USR_2_RSTMASK                                              0xffffffff
#define PHY_DATA_GP_USR_2_RESET                                                0x0

// 0x7c (PHY_DATA_GP_USR_3)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_3_LSB                              0
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_3_MSB                              31
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_3_MASK                             0xffffffff
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_3_GET(x)                           (((x) & PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_3_MASK) >> PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_3_LSB)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_3_SET(x)                           (((0 | (x)) << PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_3_LSB) & PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_3_MASK)
#define PHY_DATA_GP_USR_GROUP_TO_USER_ENTRY_3_RESET                            0x0
#define PHY_DATA_GP_USR_3_ADDRESS                                              (0x7c + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_DATA_GP_USR_3_RSTMASK                                              0xffffffff
#define PHY_DATA_GP_USR_3_RESET                                                0x0

// 0x80 (PHY_STATUS)
#define PHY_STATUS_RSVD_1_LSB                                                  28
#define PHY_STATUS_RSVD_1_MSB                                                  31
#define PHY_STATUS_RSVD_1_MASK                                                 0xf0000000
#define PHY_STATUS_RSVD_1_GET(x)                                               (((x) & PHY_STATUS_RSVD_1_MASK) >> PHY_STATUS_RSVD_1_LSB)
#define PHY_STATUS_RSVD_1_SET(x)                                               (((0 | (x)) << PHY_STATUS_RSVD_1_LSB) & PHY_STATUS_RSVD_1_MASK)
#define PHY_STATUS_RSVD_1_RESET                                                0x0
#define PHY_STATUS_RX_ABORT_LSB                                                24
#define PHY_STATUS_RX_ABORT_MSB                                                27
#define PHY_STATUS_RX_ABORT_MASK                                               0xf000000
#define PHY_STATUS_RX_ABORT_GET(x)                                             (((x) & PHY_STATUS_RX_ABORT_MASK) >> PHY_STATUS_RX_ABORT_LSB)
#define PHY_STATUS_RX_ABORT_SET(x)                                             (((0 | (x)) << PHY_STATUS_RX_ABORT_LSB) & PHY_STATUS_RX_ABORT_MASK)
#define PHY_STATUS_RX_ABORT_RESET                                              0x0
#define PHY_STATUS_TX_STOMP_RX_LSB                                             20
#define PHY_STATUS_TX_STOMP_RX_MSB                                             23
#define PHY_STATUS_TX_STOMP_RX_MASK                                            0xf00000
#define PHY_STATUS_TX_STOMP_RX_GET(x)                                          (((x) & PHY_STATUS_TX_STOMP_RX_MASK) >> PHY_STATUS_TX_STOMP_RX_LSB)
#define PHY_STATUS_TX_STOMP_RX_SET(x)                                          (((0 | (x)) << PHY_STATUS_TX_STOMP_RX_LSB) & PHY_STATUS_TX_STOMP_RX_MASK)
#define PHY_STATUS_TX_STOMP_RX_RESET                                           0x0
#define PHY_STATUS_TLV_ERR_CNT_LSB                                             16
#define PHY_STATUS_TLV_ERR_CNT_MSB                                             19
#define PHY_STATUS_TLV_ERR_CNT_MASK                                            0xf0000
#define PHY_STATUS_TLV_ERR_CNT_GET(x)                                          (((x) & PHY_STATUS_TLV_ERR_CNT_MASK) >> PHY_STATUS_TLV_ERR_CNT_LSB)
#define PHY_STATUS_TLV_ERR_CNT_SET(x)                                          (((0 | (x)) << PHY_STATUS_TLV_ERR_CNT_LSB) & PHY_STATUS_TLV_ERR_CNT_MASK)
#define PHY_STATUS_TLV_ERR_CNT_RESET                                           0x0
#define PHY_STATUS_RSVD_0_LSB                                                  12
#define PHY_STATUS_RSVD_0_MSB                                                  15
#define PHY_STATUS_RSVD_0_MASK                                                 0xf000
#define PHY_STATUS_RSVD_0_GET(x)                                               (((x) & PHY_STATUS_RSVD_0_MASK) >> PHY_STATUS_RSVD_0_LSB)
#define PHY_STATUS_RSVD_0_SET(x)                                               (((0 | (x)) << PHY_STATUS_RSVD_0_LSB) & PHY_STATUS_RSVD_0_MASK)
#define PHY_STATUS_RSVD_0_RESET                                                0x0
#define PHY_STATUS_TX_UNDERRUN_FIFO_2_LSB                                      8
#define PHY_STATUS_TX_UNDERRUN_FIFO_2_MSB                                      11
#define PHY_STATUS_TX_UNDERRUN_FIFO_2_MASK                                     0xf00
#define PHY_STATUS_TX_UNDERRUN_FIFO_2_GET(x)                                   (((x) & PHY_STATUS_TX_UNDERRUN_FIFO_2_MASK) >> PHY_STATUS_TX_UNDERRUN_FIFO_2_LSB)
#define PHY_STATUS_TX_UNDERRUN_FIFO_2_SET(x)                                   (((0 | (x)) << PHY_STATUS_TX_UNDERRUN_FIFO_2_LSB) & PHY_STATUS_TX_UNDERRUN_FIFO_2_MASK)
#define PHY_STATUS_TX_UNDERRUN_FIFO_2_RESET                                    0x0
#define PHY_STATUS_TX_UNDERRUN_FIFO_1_LSB                                      4
#define PHY_STATUS_TX_UNDERRUN_FIFO_1_MSB                                      7
#define PHY_STATUS_TX_UNDERRUN_FIFO_1_MASK                                     0xf0
#define PHY_STATUS_TX_UNDERRUN_FIFO_1_GET(x)                                   (((x) & PHY_STATUS_TX_UNDERRUN_FIFO_1_MASK) >> PHY_STATUS_TX_UNDERRUN_FIFO_1_LSB)
#define PHY_STATUS_TX_UNDERRUN_FIFO_1_SET(x)                                   (((0 | (x)) << PHY_STATUS_TX_UNDERRUN_FIFO_1_LSB) & PHY_STATUS_TX_UNDERRUN_FIFO_1_MASK)
#define PHY_STATUS_TX_UNDERRUN_FIFO_1_RESET                                    0x0
#define PHY_STATUS_TX_UNDERRUN_FIFO_0_LSB                                      0
#define PHY_STATUS_TX_UNDERRUN_FIFO_0_MSB                                      3
#define PHY_STATUS_TX_UNDERRUN_FIFO_0_MASK                                     0xf
#define PHY_STATUS_TX_UNDERRUN_FIFO_0_GET(x)                                   (((x) & PHY_STATUS_TX_UNDERRUN_FIFO_0_MASK) >> PHY_STATUS_TX_UNDERRUN_FIFO_0_LSB)
#define PHY_STATUS_TX_UNDERRUN_FIFO_0_SET(x)                                   (((0 | (x)) << PHY_STATUS_TX_UNDERRUN_FIFO_0_LSB) & PHY_STATUS_TX_UNDERRUN_FIFO_0_MASK)
#define PHY_STATUS_TX_UNDERRUN_FIFO_0_RESET                                    0x0
#define PHY_STATUS_ADDRESS                                                     (0x80 + __EMU_PHY_REG_BASE_ADDRESS)
#define PHY_STATUS_RSTMASK                                                     0xffffffff
#define PHY_STATUS_RESET                                                       0x0

// 0x84 (CHN_CTRL_0)
#define CHN_CTRL_0_RSVD_3_LSB                                                  29
#define CHN_CTRL_0_RSVD_3_MSB                                                  31
#define CHN_CTRL_0_RSVD_3_MASK                                                 0xe0000000
#define CHN_CTRL_0_RSVD_3_GET(x)                                               (((x) & CHN_CTRL_0_RSVD_3_MASK) >> CHN_CTRL_0_RSVD_3_LSB)
#define CHN_CTRL_0_RSVD_3_SET(x)                                               (((0 | (x)) << CHN_CTRL_0_RSVD_3_LSB) & CHN_CTRL_0_RSVD_3_MASK)
#define CHN_CTRL_0_RSVD_3_RESET                                                0x0
#define CHN_CTRL_0_MAX_BIT_ERR_3_LSB                                           24
#define CHN_CTRL_0_MAX_BIT_ERR_3_MSB                                           28
#define CHN_CTRL_0_MAX_BIT_ERR_3_MASK                                          0x1f000000
#define CHN_CTRL_0_MAX_BIT_ERR_3_GET(x)                                        (((x) & CHN_CTRL_0_MAX_BIT_ERR_3_MASK) >> CHN_CTRL_0_MAX_BIT_ERR_3_LSB)
#define CHN_CTRL_0_MAX_BIT_ERR_3_SET(x)                                        (((0 | (x)) << CHN_CTRL_0_MAX_BIT_ERR_3_LSB) & CHN_CTRL_0_MAX_BIT_ERR_3_MASK)
#define CHN_CTRL_0_MAX_BIT_ERR_3_RESET                                         0x0
#define CHN_CTRL_0_RSVD_2_LSB                                                  21
#define CHN_CTRL_0_RSVD_2_MSB                                                  23
#define CHN_CTRL_0_RSVD_2_MASK                                                 0xe00000
#define CHN_CTRL_0_RSVD_2_GET(x)                                               (((x) & CHN_CTRL_0_RSVD_2_MASK) >> CHN_CTRL_0_RSVD_2_LSB)
#define CHN_CTRL_0_RSVD_2_SET(x)                                               (((0 | (x)) << CHN_CTRL_0_RSVD_2_LSB) & CHN_CTRL_0_RSVD_2_MASK)
#define CHN_CTRL_0_RSVD_2_RESET                                                0x0
#define CHN_CTRL_0_MAX_BIT_ERR_2_LSB                                           16
#define CHN_CTRL_0_MAX_BIT_ERR_2_MSB                                           20
#define CHN_CTRL_0_MAX_BIT_ERR_2_MASK                                          0x1f0000
#define CHN_CTRL_0_MAX_BIT_ERR_2_GET(x)                                        (((x) & CHN_CTRL_0_MAX_BIT_ERR_2_MASK) >> CHN_CTRL_0_MAX_BIT_ERR_2_LSB)
#define CHN_CTRL_0_MAX_BIT_ERR_2_SET(x)                                        (((0 | (x)) << CHN_CTRL_0_MAX_BIT_ERR_2_LSB) & CHN_CTRL_0_MAX_BIT_ERR_2_MASK)
#define CHN_CTRL_0_MAX_BIT_ERR_2_RESET                                         0x0
#define CHN_CTRL_0_RSVD_1_LSB                                                  13
#define CHN_CTRL_0_RSVD_1_MSB                                                  15
#define CHN_CTRL_0_RSVD_1_MASK                                                 0xe000
#define CHN_CTRL_0_RSVD_1_GET(x)                                               (((x) & CHN_CTRL_0_RSVD_1_MASK) >> CHN_CTRL_0_RSVD_1_LSB)
#define CHN_CTRL_0_RSVD_1_SET(x)                                               (((0 | (x)) << CHN_CTRL_0_RSVD_1_LSB) & CHN_CTRL_0_RSVD_1_MASK)
#define CHN_CTRL_0_RSVD_1_RESET                                                0x0
#define CHN_CTRL_0_MAX_BIT_ERR_1_LSB                                           8
#define CHN_CTRL_0_MAX_BIT_ERR_1_MSB                                           12
#define CHN_CTRL_0_MAX_BIT_ERR_1_MASK                                          0x1f00
#define CHN_CTRL_0_MAX_BIT_ERR_1_GET(x)                                        (((x) & CHN_CTRL_0_MAX_BIT_ERR_1_MASK) >> CHN_CTRL_0_MAX_BIT_ERR_1_LSB)
#define CHN_CTRL_0_MAX_BIT_ERR_1_SET(x)                                        (((0 | (x)) << CHN_CTRL_0_MAX_BIT_ERR_1_LSB) & CHN_CTRL_0_MAX_BIT_ERR_1_MASK)
#define CHN_CTRL_0_MAX_BIT_ERR_1_RESET                                         0x0
#define CHN_CTRL_0_RSVD_0_LSB                                                  5
#define CHN_CTRL_0_RSVD_0_MSB                                                  7
#define CHN_CTRL_0_RSVD_0_MASK                                                 0xe0
#define CHN_CTRL_0_RSVD_0_GET(x)                                               (((x) & CHN_CTRL_0_RSVD_0_MASK) >> CHN_CTRL_0_RSVD_0_LSB)
#define CHN_CTRL_0_RSVD_0_SET(x)                                               (((0 | (x)) << CHN_CTRL_0_RSVD_0_LSB) & CHN_CTRL_0_RSVD_0_MASK)
#define CHN_CTRL_0_RSVD_0_RESET                                                0x0
#define CHN_CTRL_0_MAX_BIT_ERR_0_LSB                                           0
#define CHN_CTRL_0_MAX_BIT_ERR_0_MSB                                           4
#define CHN_CTRL_0_MAX_BIT_ERR_0_MASK                                          0x1f
#define CHN_CTRL_0_MAX_BIT_ERR_0_GET(x)                                        (((x) & CHN_CTRL_0_MAX_BIT_ERR_0_MASK) >> CHN_CTRL_0_MAX_BIT_ERR_0_LSB)
#define CHN_CTRL_0_MAX_BIT_ERR_0_SET(x)                                        (((0 | (x)) << CHN_CTRL_0_MAX_BIT_ERR_0_LSB) & CHN_CTRL_0_MAX_BIT_ERR_0_MASK)
#define CHN_CTRL_0_MAX_BIT_ERR_0_RESET                                         0x0
#define CHN_CTRL_0_ADDRESS                                                     (0x84 + __EMU_PHY_REG_BASE_ADDRESS)
#define CHN_CTRL_0_RSTMASK                                                     0xffffffff
#define CHN_CTRL_0_RESET                                                       0x0

// 0x90 (CHN_CTRL_1)
#define CHN_CTRL_1_LFSR_SPREAD_LSB                                             0
#define CHN_CTRL_1_LFSR_SPREAD_MSB                                             31
#define CHN_CTRL_1_LFSR_SPREAD_MASK                                            0xffffffff
#define CHN_CTRL_1_LFSR_SPREAD_GET(x)                                          (((x) & CHN_CTRL_1_LFSR_SPREAD_MASK) >> CHN_CTRL_1_LFSR_SPREAD_LSB)
#define CHN_CTRL_1_LFSR_SPREAD_SET(x)                                          (((0 | (x)) << CHN_CTRL_1_LFSR_SPREAD_LSB) & CHN_CTRL_1_LFSR_SPREAD_MASK)
#define CHN_CTRL_1_LFSR_SPREAD_RESET                                           0xffffffff
#define CHN_CTRL_1_ADDRESS                                                     (0x90 + __EMU_PHY_REG_BASE_ADDRESS)
#define CHN_CTRL_1_RSTMASK                                                     0xffffffff
#define CHN_CTRL_1_RESET                                                       0xffffffff

// 0x90 (CHN_CTRL_1_0)
#define CHN_CTRL_1_LFSR_SPREAD_0_LSB                                           0
#define CHN_CTRL_1_LFSR_SPREAD_0_MSB                                           31
#define CHN_CTRL_1_LFSR_SPREAD_0_MASK                                          0xffffffff
#define CHN_CTRL_1_LFSR_SPREAD_0_GET(x)                                        (((x) & CHN_CTRL_1_LFSR_SPREAD_0_MASK) >> CHN_CTRL_1_LFSR_SPREAD_0_LSB)
#define CHN_CTRL_1_LFSR_SPREAD_0_SET(x)                                        (((0 | (x)) << CHN_CTRL_1_LFSR_SPREAD_0_LSB) & CHN_CTRL_1_LFSR_SPREAD_0_MASK)
#define CHN_CTRL_1_LFSR_SPREAD_0_RESET                                         0xffffffff
#define CHN_CTRL_1_0_ADDRESS                                                   (0x90 + __EMU_PHY_REG_BASE_ADDRESS)
#define CHN_CTRL_1_0_RSTMASK                                                   0xffffffff
#define CHN_CTRL_1_0_RESET                                                     0xffffffff

// 0x94 (CHN_CTRL_1_1)
#define CHN_CTRL_1_LFSR_SPREAD_1_LSB                                           0
#define CHN_CTRL_1_LFSR_SPREAD_1_MSB                                           31
#define CHN_CTRL_1_LFSR_SPREAD_1_MASK                                          0xffffffff
#define CHN_CTRL_1_LFSR_SPREAD_1_GET(x)                                        (((x) & CHN_CTRL_1_LFSR_SPREAD_1_MASK) >> CHN_CTRL_1_LFSR_SPREAD_1_LSB)
#define CHN_CTRL_1_LFSR_SPREAD_1_SET(x)                                        (((0 | (x)) << CHN_CTRL_1_LFSR_SPREAD_1_LSB) & CHN_CTRL_1_LFSR_SPREAD_1_MASK)
#define CHN_CTRL_1_LFSR_SPREAD_1_RESET                                         0xffffffff
#define CHN_CTRL_1_1_ADDRESS                                                   (0x94 + __EMU_PHY_REG_BASE_ADDRESS)
#define CHN_CTRL_1_1_RSTMASK                                                   0xffffffff
#define CHN_CTRL_1_1_RESET                                                     0xffffffff

// 0x98 (CHN_CTRL_1_2)
#define CHN_CTRL_1_LFSR_SPREAD_2_LSB                                           0
#define CHN_CTRL_1_LFSR_SPREAD_2_MSB                                           31
#define CHN_CTRL_1_LFSR_SPREAD_2_MASK                                          0xffffffff
#define CHN_CTRL_1_LFSR_SPREAD_2_GET(x)                                        (((x) & CHN_CTRL_1_LFSR_SPREAD_2_MASK) >> CHN_CTRL_1_LFSR_SPREAD_2_LSB)
#define CHN_CTRL_1_LFSR_SPREAD_2_SET(x)                                        (((0 | (x)) << CHN_CTRL_1_LFSR_SPREAD_2_LSB) & CHN_CTRL_1_LFSR_SPREAD_2_MASK)
#define CHN_CTRL_1_LFSR_SPREAD_2_RESET                                         0xffffffff
#define CHN_CTRL_1_2_ADDRESS                                                   (0x98 + __EMU_PHY_REG_BASE_ADDRESS)
#define CHN_CTRL_1_2_RSTMASK                                                   0xffffffff
#define CHN_CTRL_1_2_RESET                                                     0xffffffff

// 0x9c (CHN_CTRL_1_3)
#define CHN_CTRL_1_LFSR_SPREAD_3_LSB                                           0
#define CHN_CTRL_1_LFSR_SPREAD_3_MSB                                           31
#define CHN_CTRL_1_LFSR_SPREAD_3_MASK                                          0xffffffff
#define CHN_CTRL_1_LFSR_SPREAD_3_GET(x)                                        (((x) & CHN_CTRL_1_LFSR_SPREAD_3_MASK) >> CHN_CTRL_1_LFSR_SPREAD_3_LSB)
#define CHN_CTRL_1_LFSR_SPREAD_3_SET(x)                                        (((0 | (x)) << CHN_CTRL_1_LFSR_SPREAD_3_LSB) & CHN_CTRL_1_LFSR_SPREAD_3_MASK)
#define CHN_CTRL_1_LFSR_SPREAD_3_RESET                                         0xffffffff
#define CHN_CTRL_1_3_ADDRESS                                                   (0x9c + __EMU_PHY_REG_BASE_ADDRESS)
#define CHN_CTRL_1_3_RSTMASK                                                   0xffffffff
#define CHN_CTRL_1_3_RESET                                                     0xffffffff

// 0xa0 (CHN_CTRL_2)
#define CHN_CTRL_2_DNSTY_MASK_LSB                                              0
#define CHN_CTRL_2_DNSTY_MASK_MSB                                              31
#define CHN_CTRL_2_DNSTY_MASK_MASK                                             0xffffffff
#define CHN_CTRL_2_DNSTY_MASK_GET(x)                                           (((x) & CHN_CTRL_2_DNSTY_MASK_MASK) >> CHN_CTRL_2_DNSTY_MASK_LSB)
#define CHN_CTRL_2_DNSTY_MASK_SET(x)                                           (((0 | (x)) << CHN_CTRL_2_DNSTY_MASK_LSB) & CHN_CTRL_2_DNSTY_MASK_MASK)
#define CHN_CTRL_2_DNSTY_MASK_RESET                                            0xffffffff
#define CHN_CTRL_2_ADDRESS                                                     (0xa0 + __EMU_PHY_REG_BASE_ADDRESS)
#define CHN_CTRL_2_RSTMASK                                                     0xffffffff
#define CHN_CTRL_2_RESET                                                       0xffffffff

// 0xa0 (CHN_CTRL_2_0)
#define CHN_CTRL_2_DNSTY_MASK_0_LSB                                            0
#define CHN_CTRL_2_DNSTY_MASK_0_MSB                                            31
#define CHN_CTRL_2_DNSTY_MASK_0_MASK                                           0xffffffff
#define CHN_CTRL_2_DNSTY_MASK_0_GET(x)                                         (((x) & CHN_CTRL_2_DNSTY_MASK_0_MASK) >> CHN_CTRL_2_DNSTY_MASK_0_LSB)
#define CHN_CTRL_2_DNSTY_MASK_0_SET(x)                                         (((0 | (x)) << CHN_CTRL_2_DNSTY_MASK_0_LSB) & CHN_CTRL_2_DNSTY_MASK_0_MASK)
#define CHN_CTRL_2_DNSTY_MASK_0_RESET                                          0xffffffff
#define CHN_CTRL_2_0_ADDRESS                                                   (0xa0 + __EMU_PHY_REG_BASE_ADDRESS)
#define CHN_CTRL_2_0_RSTMASK                                                   0xffffffff
#define CHN_CTRL_2_0_RESET                                                     0xffffffff

// 0xa4 (CHN_CTRL_2_1)
#define CHN_CTRL_2_DNSTY_MASK_1_LSB                                            0
#define CHN_CTRL_2_DNSTY_MASK_1_MSB                                            31
#define CHN_CTRL_2_DNSTY_MASK_1_MASK                                           0xffffffff
#define CHN_CTRL_2_DNSTY_MASK_1_GET(x)                                         (((x) & CHN_CTRL_2_DNSTY_MASK_1_MASK) >> CHN_CTRL_2_DNSTY_MASK_1_LSB)
#define CHN_CTRL_2_DNSTY_MASK_1_SET(x)                                         (((0 | (x)) << CHN_CTRL_2_DNSTY_MASK_1_LSB) & CHN_CTRL_2_DNSTY_MASK_1_MASK)
#define CHN_CTRL_2_DNSTY_MASK_1_RESET                                          0xffffffff
#define CHN_CTRL_2_1_ADDRESS                                                   (0xa4 + __EMU_PHY_REG_BASE_ADDRESS)
#define CHN_CTRL_2_1_RSTMASK                                                   0xffffffff
#define CHN_CTRL_2_1_RESET                                                     0xffffffff

// 0xa8 (CHN_CTRL_2_2)
#define CHN_CTRL_2_DNSTY_MASK_2_LSB                                            0
#define CHN_CTRL_2_DNSTY_MASK_2_MSB                                            31
#define CHN_CTRL_2_DNSTY_MASK_2_MASK                                           0xffffffff
#define CHN_CTRL_2_DNSTY_MASK_2_GET(x)                                         (((x) & CHN_CTRL_2_DNSTY_MASK_2_MASK) >> CHN_CTRL_2_DNSTY_MASK_2_LSB)
#define CHN_CTRL_2_DNSTY_MASK_2_SET(x)                                         (((0 | (x)) << CHN_CTRL_2_DNSTY_MASK_2_LSB) & CHN_CTRL_2_DNSTY_MASK_2_MASK)
#define CHN_CTRL_2_DNSTY_MASK_2_RESET                                          0xffffffff
#define CHN_CTRL_2_2_ADDRESS                                                   (0xa8 + __EMU_PHY_REG_BASE_ADDRESS)
#define CHN_CTRL_2_2_RSTMASK                                                   0xffffffff
#define CHN_CTRL_2_2_RESET                                                     0xffffffff

// 0xac (CHN_CTRL_2_3)
#define CHN_CTRL_2_DNSTY_MASK_3_LSB                                            0
#define CHN_CTRL_2_DNSTY_MASK_3_MSB                                            31
#define CHN_CTRL_2_DNSTY_MASK_3_MASK                                           0xffffffff
#define CHN_CTRL_2_DNSTY_MASK_3_GET(x)                                         (((x) & CHN_CTRL_2_DNSTY_MASK_3_MASK) >> CHN_CTRL_2_DNSTY_MASK_3_LSB)
#define CHN_CTRL_2_DNSTY_MASK_3_SET(x)                                         (((0 | (x)) << CHN_CTRL_2_DNSTY_MASK_3_LSB) & CHN_CTRL_2_DNSTY_MASK_3_MASK)
#define CHN_CTRL_2_DNSTY_MASK_3_RESET                                          0xffffffff
#define CHN_CTRL_2_3_ADDRESS                                                   (0xac + __EMU_PHY_REG_BASE_ADDRESS)
#define CHN_CTRL_2_3_RSTMASK                                                   0xffffffff
#define CHN_CTRL_2_3_RESET                                                     0xffffffff

// 0xb0 (TLVI_TX_PHY_DESC)
#define TLVI_TX_PHY_DESC_CNT_LSB                                               0
#define TLVI_TX_PHY_DESC_CNT_MSB                                               31
#define TLVI_TX_PHY_DESC_CNT_MASK                                              0xffffffff
#define TLVI_TX_PHY_DESC_CNT_GET(x)                                            (((x) & TLVI_TX_PHY_DESC_CNT_MASK) >> TLVI_TX_PHY_DESC_CNT_LSB)
#define TLVI_TX_PHY_DESC_CNT_SET(x)                                            (((0 | (x)) << TLVI_TX_PHY_DESC_CNT_LSB) & TLVI_TX_PHY_DESC_CNT_MASK)
#define TLVI_TX_PHY_DESC_CNT_RESET                                             0x0
#define TLVI_TX_PHY_DESC_ADDRESS                                               (0xb0 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVI_TX_PHY_DESC_RSTMASK                                               0xffffffff
#define TLVI_TX_PHY_DESC_RESET                                                 0x0

// 0xb4 (TLVI_TX_SERVICE)
#define TLVI_TX_SERVICE_CNT_LSB                                                0
#define TLVI_TX_SERVICE_CNT_MSB                                                31
#define TLVI_TX_SERVICE_CNT_MASK                                               0xffffffff
#define TLVI_TX_SERVICE_CNT_GET(x)                                             (((x) & TLVI_TX_SERVICE_CNT_MASK) >> TLVI_TX_SERVICE_CNT_LSB)
#define TLVI_TX_SERVICE_CNT_SET(x)                                             (((0 | (x)) << TLVI_TX_SERVICE_CNT_LSB) & TLVI_TX_SERVICE_CNT_MASK)
#define TLVI_TX_SERVICE_CNT_RESET                                              0x0
#define TLVI_TX_SERVICE_ADDRESS                                                (0xb4 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVI_TX_SERVICE_RSTMASK                                                0xffffffff
#define TLVI_TX_SERVICE_RESET                                                  0x0

// 0xb8 (TLVI_MAC_PKT_END)
#define TLVI_MAC_PKT_END_CNT_LSB                                               0
#define TLVI_MAC_PKT_END_CNT_MSB                                               31
#define TLVI_MAC_PKT_END_CNT_MASK                                              0xffffffff
#define TLVI_MAC_PKT_END_CNT_GET(x)                                            (((x) & TLVI_MAC_PKT_END_CNT_MASK) >> TLVI_MAC_PKT_END_CNT_LSB)
#define TLVI_MAC_PKT_END_CNT_SET(x)                                            (((0 | (x)) << TLVI_MAC_PKT_END_CNT_LSB) & TLVI_MAC_PKT_END_CNT_MASK)
#define TLVI_MAC_PKT_END_CNT_RESET                                             0x0
#define TLVI_MAC_PKT_END_ADDRESS                                               (0xb8 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVI_MAC_PKT_END_RSTMASK                                               0xffffffff
#define TLVI_MAC_PKT_END_RESET                                                 0x0

// 0xbc (TLVI_VECTOR_XFER_START)
#define TLVI_VECTOR_XFER_START_CNT_LSB                                         0
#define TLVI_VECTOR_XFER_START_CNT_MSB                                         31
#define TLVI_VECTOR_XFER_START_CNT_MASK                                        0xffffffff
#define TLVI_VECTOR_XFER_START_CNT_GET(x)                                      (((x) & TLVI_VECTOR_XFER_START_CNT_MASK) >> TLVI_VECTOR_XFER_START_CNT_LSB)
#define TLVI_VECTOR_XFER_START_CNT_SET(x)                                      (((0 | (x)) << TLVI_VECTOR_XFER_START_CNT_LSB) & TLVI_VECTOR_XFER_START_CNT_MASK)
#define TLVI_VECTOR_XFER_START_CNT_RESET                                       0x0
#define TLVI_VECTOR_XFER_START_ADDRESS                                         (0xbc + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVI_VECTOR_XFER_START_RSTMASK                                         0xffffffff
#define TLVI_VECTOR_XFER_START_RESET                                           0x0

// 0xc0 (TLVI_TLV_TERMINATE)
#define TLVI_TLV_TERMINATE_CNT_LSB                                             0
#define TLVI_TLV_TERMINATE_CNT_MSB                                             31
#define TLVI_TLV_TERMINATE_CNT_MASK                                            0xffffffff
#define TLVI_TLV_TERMINATE_CNT_GET(x)                                          (((x) & TLVI_TLV_TERMINATE_CNT_MASK) >> TLVI_TLV_TERMINATE_CNT_LSB)
#define TLVI_TLV_TERMINATE_CNT_SET(x)                                          (((0 | (x)) << TLVI_TLV_TERMINATE_CNT_LSB) & TLVI_TLV_TERMINATE_CNT_MASK)
#define TLVI_TLV_TERMINATE_CNT_RESET                                           0x0
#define TLVI_TLV_TERMINATE_ADDRESS                                             (0xc0 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVI_TLV_TERMINATE_RSTMASK                                             0xffffffff
#define TLVI_TLV_TERMINATE_RESET                                               0x0

// 0xc4 (TLVI_TX_EXPECT_CBF)
#define TLVI_TX_EXPECT_CBF_CNT_LSB                                             0
#define TLVI_TX_EXPECT_CBF_CNT_MSB                                             31
#define TLVI_TX_EXPECT_CBF_CNT_MASK                                            0xffffffff
#define TLVI_TX_EXPECT_CBF_CNT_GET(x)                                          (((x) & TLVI_TX_EXPECT_CBF_CNT_MASK) >> TLVI_TX_EXPECT_CBF_CNT_LSB)
#define TLVI_TX_EXPECT_CBF_CNT_SET(x)                                          (((0 | (x)) << TLVI_TX_EXPECT_CBF_CNT_LSB) & TLVI_TX_EXPECT_CBF_CNT_MASK)
#define TLVI_TX_EXPECT_CBF_CNT_RESET                                           0x0
#define TLVI_TX_EXPECT_CBF_ADDRESS                                             (0xc4 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVI_TX_EXPECT_CBF_RSTMASK                                             0xffffffff
#define TLVI_TX_EXPECT_CBF_RESET                                               0x0

// 0xc8 (TLVI_TX_CBF_OFFSET)
#define TLVI_TX_CBF_OFFSET_CNT_LSB                                             0
#define TLVI_TX_CBF_OFFSET_CNT_MSB                                             31
#define TLVI_TX_CBF_OFFSET_CNT_MASK                                            0xffffffff
#define TLVI_TX_CBF_OFFSET_CNT_GET(x)                                          (((x) & TLVI_TX_CBF_OFFSET_CNT_MASK) >> TLVI_TX_CBF_OFFSET_CNT_LSB)
#define TLVI_TX_CBF_OFFSET_CNT_SET(x)                                          (((0 | (x)) << TLVI_TX_CBF_OFFSET_CNT_LSB) & TLVI_TX_CBF_OFFSET_CNT_MASK)
#define TLVI_TX_CBF_OFFSET_CNT_RESET                                           0x0
#define TLVI_TX_CBF_OFFSET_ADDRESS                                             (0xc8 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVI_TX_CBF_OFFSET_RSTMASK                                             0xffffffff
#define TLVI_TX_CBF_OFFSET_RESET                                               0x0

// 0xcc (TLVI_TX_BF_PARAMS)
#define TLVI_TX_BF_PARAMS_CNT_LSB                                              0
#define TLVI_TX_BF_PARAMS_CNT_MSB                                              31
#define TLVI_TX_BF_PARAMS_CNT_MASK                                             0xffffffff
#define TLVI_TX_BF_PARAMS_CNT_GET(x)                                           (((x) & TLVI_TX_BF_PARAMS_CNT_MASK) >> TLVI_TX_BF_PARAMS_CNT_LSB)
#define TLVI_TX_BF_PARAMS_CNT_SET(x)                                           (((0 | (x)) << TLVI_TX_BF_PARAMS_CNT_LSB) & TLVI_TX_BF_PARAMS_CNT_MASK)
#define TLVI_TX_BF_PARAMS_CNT_RESET                                            0x0
#define TLVI_TX_BF_PARAMS_ADDRESS                                              (0xcc + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVI_TX_BF_PARAMS_RSTMASK                                              0xffffffff
#define TLVI_TX_BF_PARAMS_RESET                                                0x0

// 0xd0 (TLVI_TX_EXPECT_NDP)
#define TLVI_TX_EXPECT_NDP_CNT_LSB                                             0
#define TLVI_TX_EXPECT_NDP_CNT_MSB                                             31
#define TLVI_TX_EXPECT_NDP_CNT_MASK                                            0xffffffff
#define TLVI_TX_EXPECT_NDP_CNT_GET(x)                                          (((x) & TLVI_TX_EXPECT_NDP_CNT_MASK) >> TLVI_TX_EXPECT_NDP_CNT_LSB)
#define TLVI_TX_EXPECT_NDP_CNT_SET(x)                                          (((0 | (x)) << TLVI_TX_EXPECT_NDP_CNT_LSB) & TLVI_TX_EXPECT_NDP_CNT_MASK)
#define TLVI_TX_EXPECT_NDP_CNT_RESET                                           0x0
#define TLVI_TX_EXPECT_NDP_ADDRESS                                             (0xd0 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVI_TX_EXPECT_NDP_RSTMASK                                             0xffffffff
#define TLVI_TX_EXPECT_NDP_RESET                                               0x0

// 0xd4 (TLVI_PHY_OFF)
#define TLVI_PHY_OFF_CNT_LSB                                                   0
#define TLVI_PHY_OFF_CNT_MSB                                                   31
#define TLVI_PHY_OFF_CNT_MASK                                                  0xffffffff
#define TLVI_PHY_OFF_CNT_GET(x)                                                (((x) & TLVI_PHY_OFF_CNT_MASK) >> TLVI_PHY_OFF_CNT_LSB)
#define TLVI_PHY_OFF_CNT_SET(x)                                                (((0 | (x)) << TLVI_PHY_OFF_CNT_LSB) & TLVI_PHY_OFF_CNT_MASK)
#define TLVI_PHY_OFF_CNT_RESET                                                 0x0
#define TLVI_PHY_OFF_ADDRESS                                                   (0xd4 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVI_PHY_OFF_RSTMASK                                                   0xffffffff
#define TLVI_PHY_OFF_RESET                                                     0x0

// 0xd8 (TLVI_PHY_ON)
#define TLVI_PHY_ON_CNT_LSB                                                    0
#define TLVI_PHY_ON_CNT_MSB                                                    31
#define TLVI_PHY_ON_CNT_MASK                                                   0xffffffff
#define TLVI_PHY_ON_CNT_GET(x)                                                 (((x) & TLVI_PHY_ON_CNT_MASK) >> TLVI_PHY_ON_CNT_LSB)
#define TLVI_PHY_ON_CNT_SET(x)                                                 (((0 | (x)) << TLVI_PHY_ON_CNT_LSB) & TLVI_PHY_ON_CNT_MASK)
#define TLVI_PHY_ON_CNT_RESET                                                  0x0
#define TLVI_PHY_ON_ADDRESS                                                    (0xd8 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVI_PHY_ON_RSTMASK                                                    0xffffffff
#define TLVI_PHY_ON_RESET                                                      0x0

// 0xdc (TLVO_SVD_READY)
#define TLVO_SVD_READY_CNT_LSB                                                 0
#define TLVO_SVD_READY_CNT_MSB                                                 31
#define TLVO_SVD_READY_CNT_MASK                                                0xffffffff
#define TLVO_SVD_READY_CNT_GET(x)                                              (((x) & TLVO_SVD_READY_CNT_MASK) >> TLVO_SVD_READY_CNT_LSB)
#define TLVO_SVD_READY_CNT_SET(x)                                              (((0 | (x)) << TLVO_SVD_READY_CNT_LSB) & TLVO_SVD_READY_CNT_MASK)
#define TLVO_SVD_READY_CNT_RESET                                               0x0
#define TLVO_SVD_READY_ADDRESS                                                 (0xdc + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVO_SVD_READY_RSTMASK                                                 0xffffffff
#define TLVO_SVD_READY_RESET                                                   0x0

// 0xe0 (TLVO_VECTOR_FRAGMENT)
#define TLVO_VECTOR_FRAGMENT_CNT_LSB                                           0
#define TLVO_VECTOR_FRAGMENT_CNT_MSB                                           31
#define TLVO_VECTOR_FRAGMENT_CNT_MASK                                          0xffffffff
#define TLVO_VECTOR_FRAGMENT_CNT_GET(x)                                        (((x) & TLVO_VECTOR_FRAGMENT_CNT_MASK) >> TLVO_VECTOR_FRAGMENT_CNT_LSB)
#define TLVO_VECTOR_FRAGMENT_CNT_SET(x)                                        (((0 | (x)) << TLVO_VECTOR_FRAGMENT_CNT_LSB) & TLVO_VECTOR_FRAGMENT_CNT_MASK)
#define TLVO_VECTOR_FRAGMENT_CNT_RESET                                         0x0
#define TLVO_VECTOR_FRAGMENT_ADDRESS                                           (0xe0 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVO_VECTOR_FRAGMENT_RSTMASK                                           0xffffffff
#define TLVO_VECTOR_FRAGMENT_RESET                                             0x0

// 0xe4 (TLVO_RX_PHY_PPDU_END)
#define TLVO_RX_PHY_PPDU_END_CNT_LSB                                           0
#define TLVO_RX_PHY_PPDU_END_CNT_MSB                                           31
#define TLVO_RX_PHY_PPDU_END_CNT_MASK                                          0xffffffff
#define TLVO_RX_PHY_PPDU_END_CNT_GET(x)                                        (((x) & TLVO_RX_PHY_PPDU_END_CNT_MASK) >> TLVO_RX_PHY_PPDU_END_CNT_LSB)
#define TLVO_RX_PHY_PPDU_END_CNT_SET(x)                                        (((0 | (x)) << TLVO_RX_PHY_PPDU_END_CNT_LSB) & TLVO_RX_PHY_PPDU_END_CNT_MASK)
#define TLVO_RX_PHY_PPDU_END_CNT_RESET                                         0x0
#define TLVO_RX_PHY_PPDU_END_ADDRESS                                           (0xe4 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVO_RX_PHY_PPDU_END_RSTMASK                                           0xffffffff
#define TLVO_RX_PHY_PPDU_END_RESET                                             0x0

// 0xe8 (TLVO_RX_PKT_END)
#define TLVO_RX_PKT_END_CNT_LSB                                                0
#define TLVO_RX_PKT_END_CNT_MSB                                                31
#define TLVO_RX_PKT_END_CNT_MASK                                               0xffffffff
#define TLVO_RX_PKT_END_CNT_GET(x)                                             (((x) & TLVO_RX_PKT_END_CNT_MASK) >> TLVO_RX_PKT_END_CNT_LSB)
#define TLVO_RX_PKT_END_CNT_SET(x)                                             (((0 | (x)) << TLVO_RX_PKT_END_CNT_LSB) & TLVO_RX_PKT_END_CNT_MASK)
#define TLVO_RX_PKT_END_CNT_RESET                                              0x0
#define TLVO_RX_PKT_END_ADDRESS                                                (0xe8 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVO_RX_PKT_END_RSTMASK                                                0xffffffff
#define TLVO_RX_PKT_END_RESET                                                  0x0

// 0xec (TLVO_RX_SERVICE)
#define TLVO_RX_SERVICE_CNT_LSB                                                0
#define TLVO_RX_SERVICE_CNT_MSB                                                31
#define TLVO_RX_SERVICE_CNT_MASK                                               0xffffffff
#define TLVO_RX_SERVICE_CNT_GET(x)                                             (((x) & TLVO_RX_SERVICE_CNT_MASK) >> TLVO_RX_SERVICE_CNT_LSB)
#define TLVO_RX_SERVICE_CNT_SET(x)                                             (((0 | (x)) << TLVO_RX_SERVICE_CNT_LSB) & TLVO_RX_SERVICE_CNT_MASK)
#define TLVO_RX_SERVICE_CNT_RESET                                              0x0
#define TLVO_RX_SERVICE_ADDRESS                                                (0xec + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVO_RX_SERVICE_RSTMASK                                                0xffffffff
#define TLVO_RX_SERVICE_RESET                                                  0x0

// 0xf0 (TLVO_RX_EVM)
#define TLVO_RX_EVM_CNT_LSB                                                    0
#define TLVO_RX_EVM_CNT_MSB                                                    31
#define TLVO_RX_EVM_CNT_MASK                                                   0xffffffff
#define TLVO_RX_EVM_CNT_GET(x)                                                 (((x) & TLVO_RX_EVM_CNT_MASK) >> TLVO_RX_EVM_CNT_LSB)
#define TLVO_RX_EVM_CNT_SET(x)                                                 (((0 | (x)) << TLVO_RX_EVM_CNT_LSB) & TLVO_RX_EVM_CNT_MASK)
#define TLVO_RX_EVM_CNT_RESET                                                  0x0
#define TLVO_RX_EVM_ADDRESS                                                    (0xf0 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVO_RX_EVM_RSTMASK                                                    0xffffffff
#define TLVO_RX_EVM_RESET                                                      0x0

// 0xf4 (TLVO_RX_RSSI_HT)
#define TLVO_RX_RSSI_HT_CNT_LSB                                                0
#define TLVO_RX_RSSI_HT_CNT_MSB                                                31
#define TLVO_RX_RSSI_HT_CNT_MASK                                               0xffffffff
#define TLVO_RX_RSSI_HT_CNT_GET(x)                                             (((x) & TLVO_RX_RSSI_HT_CNT_MASK) >> TLVO_RX_RSSI_HT_CNT_LSB)
#define TLVO_RX_RSSI_HT_CNT_SET(x)                                             (((0 | (x)) << TLVO_RX_RSSI_HT_CNT_LSB) & TLVO_RX_RSSI_HT_CNT_MASK)
#define TLVO_RX_RSSI_HT_CNT_RESET                                              0x0
#define TLVO_RX_RSSI_HT_ADDRESS                                                (0xf4 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVO_RX_RSSI_HT_RSTMASK                                                0xffffffff
#define TLVO_RX_RSSI_HT_RESET                                                  0x0

// 0xf8 (TLVO_RX_RSSI_LEGACY)
#define TLVO_RX_RSSI_LEGACY_CNT_LSB                                            0
#define TLVO_RX_RSSI_LEGACY_CNT_MSB                                            31
#define TLVO_RX_RSSI_LEGACY_CNT_MASK                                           0xffffffff
#define TLVO_RX_RSSI_LEGACY_CNT_GET(x)                                         (((x) & TLVO_RX_RSSI_LEGACY_CNT_MASK) >> TLVO_RX_RSSI_LEGACY_CNT_LSB)
#define TLVO_RX_RSSI_LEGACY_CNT_SET(x)                                         (((0 | (x)) << TLVO_RX_RSSI_LEGACY_CNT_LSB) & TLVO_RX_RSSI_LEGACY_CNT_MASK)
#define TLVO_RX_RSSI_LEGACY_CNT_RESET                                          0x0
#define TLVO_RX_RSSI_LEGACY_ADDRESS                                            (0xf8 + __EMU_PHY_REG_BASE_ADDRESS)
#define TLVO_RX_RSSI_LEGACY_RSTMASK                                            0xffffffff
#define TLVO_RX_RSSI_LEGACY_RESET                                              0x0



#endif /* _EMU_PHY_REG_H_ */
