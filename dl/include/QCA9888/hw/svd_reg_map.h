/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _PHY_SVD_REG_MAP_H_
#define _PHY_SVD_REG_MAP_H_


#ifndef __PHY_SVD_REG_MAP_BASE_ADDRESS
#define __PHY_SVD_REG_MAP_BASE_ADDRESS (0x15000)
#endif


// 0x0 (PHY_BB_TXBF_DBG)
#define PHY_BB_TXBF_DBG_SVD_CLK_FREE_RUN_LSB                                   20
#define PHY_BB_TXBF_DBG_SVD_CLK_FREE_RUN_MSB                                   31
#define PHY_BB_TXBF_DBG_SVD_CLK_FREE_RUN_MASK                                  0xfff00000
#define PHY_BB_TXBF_DBG_SVD_CLK_FREE_RUN_GET(x)                                (((x) & PHY_BB_TXBF_DBG_SVD_CLK_FREE_RUN_MASK) >> PHY_BB_TXBF_DBG_SVD_CLK_FREE_RUN_LSB)
#define PHY_BB_TXBF_DBG_SVD_CLK_FREE_RUN_SET(x)                                (((0 | (x)) << PHY_BB_TXBF_DBG_SVD_CLK_FREE_RUN_LSB) & PHY_BB_TXBF_DBG_SVD_CLK_FREE_RUN_MASK)
#define PHY_BB_TXBF_DBG_SVD_CLK_FREE_RUN_RESET                                 0x0
#define PHY_BB_TXBF_DBG_SVD_TXBF_READY_REG_LSB                                 16
#define PHY_BB_TXBF_DBG_SVD_TXBF_READY_REG_MSB                                 16
#define PHY_BB_TXBF_DBG_SVD_TXBF_READY_REG_MASK                                0x10000
#define PHY_BB_TXBF_DBG_SVD_TXBF_READY_REG_GET(x)                              (((x) & PHY_BB_TXBF_DBG_SVD_TXBF_READY_REG_MASK) >> PHY_BB_TXBF_DBG_SVD_TXBF_READY_REG_LSB)
#define PHY_BB_TXBF_DBG_SVD_TXBF_READY_REG_SET(x)                              (((0 | (x)) << PHY_BB_TXBF_DBG_SVD_TXBF_READY_REG_LSB) & PHY_BB_TXBF_DBG_SVD_TXBF_READY_REG_MASK)
#define PHY_BB_TXBF_DBG_SVD_TXBF_READY_REG_RESET                               0x0
#define PHY_BB_TXBF_DBG_SVD_REG_RESET_LSB                                      15
#define PHY_BB_TXBF_DBG_SVD_REG_RESET_MSB                                      15
#define PHY_BB_TXBF_DBG_SVD_REG_RESET_MASK                                     0x8000
#define PHY_BB_TXBF_DBG_SVD_REG_RESET_GET(x)                                   (((x) & PHY_BB_TXBF_DBG_SVD_REG_RESET_MASK) >> PHY_BB_TXBF_DBG_SVD_REG_RESET_LSB)
#define PHY_BB_TXBF_DBG_SVD_REG_RESET_SET(x)                                   (((0 | (x)) << PHY_BB_TXBF_DBG_SVD_REG_RESET_LSB) & PHY_BB_TXBF_DBG_SVD_REG_RESET_MASK)
#define PHY_BB_TXBF_DBG_SVD_REG_RESET_RESET                                    0x0
#define PHY_BB_TXBF_DBG_SVD_UPLOAD_H_LSB                                       14
#define PHY_BB_TXBF_DBG_SVD_UPLOAD_H_MSB                                       14
#define PHY_BB_TXBF_DBG_SVD_UPLOAD_H_MASK                                      0x4000
#define PHY_BB_TXBF_DBG_SVD_UPLOAD_H_GET(x)                                    (((x) & PHY_BB_TXBF_DBG_SVD_UPLOAD_H_MASK) >> PHY_BB_TXBF_DBG_SVD_UPLOAD_H_LSB)
#define PHY_BB_TXBF_DBG_SVD_UPLOAD_H_SET(x)                                    (((0 | (x)) << PHY_BB_TXBF_DBG_SVD_UPLOAD_H_LSB) & PHY_BB_TXBF_DBG_SVD_UPLOAD_H_MASK)
#define PHY_BB_TXBF_DBG_SVD_UPLOAD_H_RESET                                     0x0
#define PHY_BB_TXBF_DBG_UPLOAD_H_TONE_OFFSET_LSB                               5
#define PHY_BB_TXBF_DBG_UPLOAD_H_TONE_OFFSET_MSB                               13
#define PHY_BB_TXBF_DBG_UPLOAD_H_TONE_OFFSET_MASK                              0x3fe0
#define PHY_BB_TXBF_DBG_UPLOAD_H_TONE_OFFSET_GET(x)                            (((x) & PHY_BB_TXBF_DBG_UPLOAD_H_TONE_OFFSET_MASK) >> PHY_BB_TXBF_DBG_UPLOAD_H_TONE_OFFSET_LSB)
#define PHY_BB_TXBF_DBG_UPLOAD_H_TONE_OFFSET_SET(x)                            (((0 | (x)) << PHY_BB_TXBF_DBG_UPLOAD_H_TONE_OFFSET_LSB) & PHY_BB_TXBF_DBG_UPLOAD_H_TONE_OFFSET_MASK)
#define PHY_BB_TXBF_DBG_UPLOAD_H_TONE_OFFSET_RESET                             0x0
#define PHY_BB_TXBF_DBG_DEBUG_MODE_LSB                                         0
#define PHY_BB_TXBF_DBG_DEBUG_MODE_MSB                                         4
#define PHY_BB_TXBF_DBG_DEBUG_MODE_MASK                                        0x1f
#define PHY_BB_TXBF_DBG_DEBUG_MODE_GET(x)                                      (((x) & PHY_BB_TXBF_DBG_DEBUG_MODE_MASK) >> PHY_BB_TXBF_DBG_DEBUG_MODE_LSB)
#define PHY_BB_TXBF_DBG_DEBUG_MODE_SET(x)                                      (((0 | (x)) << PHY_BB_TXBF_DBG_DEBUG_MODE_LSB) & PHY_BB_TXBF_DBG_DEBUG_MODE_MASK)
#define PHY_BB_TXBF_DBG_DEBUG_MODE_RESET                                       0x0
#define PHY_BB_TXBF_DBG_ADDRESS                                                (0x0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF_DBG_RSTMASK                                                0xfff1ffff
#define PHY_BB_TXBF_DBG_RESET                                                  0x0

// 0x4 (PHY_BB_TXBF)
#define PHY_BB_TXBF_EXPECT_CBF_SELF_RST_LSB                                    31
#define PHY_BB_TXBF_EXPECT_CBF_SELF_RST_MSB                                    31
#define PHY_BB_TXBF_EXPECT_CBF_SELF_RST_MASK                                   0x80000000
#define PHY_BB_TXBF_EXPECT_CBF_SELF_RST_GET(x)                                 (((x) & PHY_BB_TXBF_EXPECT_CBF_SELF_RST_MASK) >> PHY_BB_TXBF_EXPECT_CBF_SELF_RST_LSB)
#define PHY_BB_TXBF_EXPECT_CBF_SELF_RST_SET(x)                                 (((0 | (x)) << PHY_BB_TXBF_EXPECT_CBF_SELF_RST_LSB) & PHY_BB_TXBF_EXPECT_CBF_SELF_RST_MASK)
#define PHY_BB_TXBF_EXPECT_CBF_SELF_RST_RESET                                  0x0
#define PHY_BB_TXBF_SVD_NORM_MU_MAX_LSB                                        28
#define PHY_BB_TXBF_SVD_NORM_MU_MAX_MSB                                        30
#define PHY_BB_TXBF_SVD_NORM_MU_MAX_MASK                                       0x70000000
#define PHY_BB_TXBF_SVD_NORM_MU_MAX_GET(x)                                     (((x) & PHY_BB_TXBF_SVD_NORM_MU_MAX_MASK) >> PHY_BB_TXBF_SVD_NORM_MU_MAX_LSB)
#define PHY_BB_TXBF_SVD_NORM_MU_MAX_SET(x)                                     (((0 | (x)) << PHY_BB_TXBF_SVD_NORM_MU_MAX_LSB) & PHY_BB_TXBF_SVD_NORM_MU_MAX_MASK)
#define PHY_BB_TXBF_SVD_NORM_MU_MAX_RESET                                      0x5
#define PHY_BB_TXBF_SVD_NORM_MU_MIN_LSB                                        26
#define PHY_BB_TXBF_SVD_NORM_MU_MIN_MSB                                        27
#define PHY_BB_TXBF_SVD_NORM_MU_MIN_MASK                                       0xc000000
#define PHY_BB_TXBF_SVD_NORM_MU_MIN_GET(x)                                     (((x) & PHY_BB_TXBF_SVD_NORM_MU_MIN_MASK) >> PHY_BB_TXBF_SVD_NORM_MU_MIN_LSB)
#define PHY_BB_TXBF_SVD_NORM_MU_MIN_SET(x)                                     (((0 | (x)) << PHY_BB_TXBF_SVD_NORM_MU_MIN_LSB) & PHY_BB_TXBF_SVD_NORM_MU_MIN_MASK)
#define PHY_BB_TXBF_SVD_NORM_MU_MIN_RESET                                      0x1
#define PHY_BB_TXBF_ALLOW_LDPC_NDP_LSB                                         25
#define PHY_BB_TXBF_ALLOW_LDPC_NDP_MSB                                         25
#define PHY_BB_TXBF_ALLOW_LDPC_NDP_MASK                                        0x2000000
#define PHY_BB_TXBF_ALLOW_LDPC_NDP_GET(x)                                      (((x) & PHY_BB_TXBF_ALLOW_LDPC_NDP_MASK) >> PHY_BB_TXBF_ALLOW_LDPC_NDP_LSB)
#define PHY_BB_TXBF_ALLOW_LDPC_NDP_SET(x)                                      (((0 | (x)) << PHY_BB_TXBF_ALLOW_LDPC_NDP_LSB) & PHY_BB_TXBF_ALLOW_LDPC_NDP_MASK)
#define PHY_BB_TXBF_ALLOW_LDPC_NDP_RESET                                       0x1
#define PHY_BB_TXBF_SVD_HALF_RATE_MODE_LSB                                     17
#define PHY_BB_TXBF_SVD_HALF_RATE_MODE_MSB                                     17
#define PHY_BB_TXBF_SVD_HALF_RATE_MODE_MASK                                    0x20000
#define PHY_BB_TXBF_SVD_HALF_RATE_MODE_GET(x)                                  (((x) & PHY_BB_TXBF_SVD_HALF_RATE_MODE_MASK) >> PHY_BB_TXBF_SVD_HALF_RATE_MODE_LSB)
#define PHY_BB_TXBF_SVD_HALF_RATE_MODE_SET(x)                                  (((0 | (x)) << PHY_BB_TXBF_SVD_HALF_RATE_MODE_LSB) & PHY_BB_TXBF_SVD_HALF_RATE_MODE_MASK)
#define PHY_BB_TXBF_SVD_HALF_RATE_MODE_RESET                                   0x0
#define PHY_BB_TXBF_DISABLE_TXBF_THR_LSB                                       12
#define PHY_BB_TXBF_DISABLE_TXBF_THR_MSB                                       16
#define PHY_BB_TXBF_DISABLE_TXBF_THR_MASK                                      0x1f000
#define PHY_BB_TXBF_DISABLE_TXBF_THR_GET(x)                                    (((x) & PHY_BB_TXBF_DISABLE_TXBF_THR_MASK) >> PHY_BB_TXBF_DISABLE_TXBF_THR_LSB)
#define PHY_BB_TXBF_DISABLE_TXBF_THR_SET(x)                                    (((0 | (x)) << PHY_BB_TXBF_DISABLE_TXBF_THR_LSB) & PHY_BB_TXBF_DISABLE_TXBF_THR_MASK)
#define PHY_BB_TXBF_DISABLE_TXBF_THR_RESET                                     0x0
#define PHY_BB_TXBF_TXCV_BFWEIGHT_METHOD_LSB                                   9
#define PHY_BB_TXBF_TXCV_BFWEIGHT_METHOD_MSB                                   10
#define PHY_BB_TXBF_TXCV_BFWEIGHT_METHOD_MASK                                  0x600
#define PHY_BB_TXBF_TXCV_BFWEIGHT_METHOD_GET(x)                                (((x) & PHY_BB_TXBF_TXCV_BFWEIGHT_METHOD_MASK) >> PHY_BB_TXBF_TXCV_BFWEIGHT_METHOD_LSB)
#define PHY_BB_TXBF_TXCV_BFWEIGHT_METHOD_SET(x)                                (((0 | (x)) << PHY_BB_TXBF_TXCV_BFWEIGHT_METHOD_LSB) & PHY_BB_TXBF_TXCV_BFWEIGHT_METHOD_MASK)
#define PHY_BB_TXBF_TXCV_BFWEIGHT_METHOD_RESET                                 0x0
#define PHY_BB_TXBF_FB_MAX_NC_LSB                                              6
#define PHY_BB_TXBF_FB_MAX_NC_MSB                                              6
#define PHY_BB_TXBF_FB_MAX_NC_MASK                                             0x40
#define PHY_BB_TXBF_FB_MAX_NC_GET(x)                                           (((x) & PHY_BB_TXBF_FB_MAX_NC_MASK) >> PHY_BB_TXBF_FB_MAX_NC_LSB)
#define PHY_BB_TXBF_FB_MAX_NC_SET(x)                                           (((0 | (x)) << PHY_BB_TXBF_FB_MAX_NC_LSB) & PHY_BB_TXBF_FB_MAX_NC_MASK)
#define PHY_BB_TXBF_FB_MAX_NC_RESET                                            0x0
#define PHY_BB_TXBF_NG_IDX_RPT_TX_LSB                                          4
#define PHY_BB_TXBF_NG_IDX_RPT_TX_MSB                                          5
#define PHY_BB_TXBF_NG_IDX_RPT_TX_MASK                                         0x30
#define PHY_BB_TXBF_NG_IDX_RPT_TX_GET(x)                                       (((x) & PHY_BB_TXBF_NG_IDX_RPT_TX_MASK) >> PHY_BB_TXBF_NG_IDX_RPT_TX_LSB)
#define PHY_BB_TXBF_NG_IDX_RPT_TX_SET(x)                                       (((0 | (x)) << PHY_BB_TXBF_NG_IDX_RPT_TX_LSB) & PHY_BB_TXBF_NG_IDX_RPT_TX_MASK)
#define PHY_BB_TXBF_NG_IDX_RPT_TX_RESET                                        0x0
#define PHY_BB_TXBF_CB_INFO_TX_LSB                                             0
#define PHY_BB_TXBF_CB_INFO_TX_MSB                                             1
#define PHY_BB_TXBF_CB_INFO_TX_MASK                                            0x3
#define PHY_BB_TXBF_CB_INFO_TX_GET(x)                                          (((x) & PHY_BB_TXBF_CB_INFO_TX_MASK) >> PHY_BB_TXBF_CB_INFO_TX_LSB)
#define PHY_BB_TXBF_CB_INFO_TX_SET(x)                                          (((0 | (x)) << PHY_BB_TXBF_CB_INFO_TX_LSB) & PHY_BB_TXBF_CB_INFO_TX_MASK)
#define PHY_BB_TXBF_CB_INFO_TX_RESET                                           0x3
#define PHY_BB_TXBF_ADDRESS                                                    (0x4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF_RSTMASK                                                    0xfe03f673
#define PHY_BB_TXBF_RESET                                                      0x56000003

// 0x8 (PHY_BB_TXBF_PREMMSE_CTRL)
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_NO_CSD_LSB                               24
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_NO_CSD_MSB                               24
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_NO_CSD_MASK                              0x1000000
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_NO_CSD_GET(x)                            (((x) & PHY_BB_TXBF_PREMMSE_CTRL_TXBF_NO_CSD_MASK) >> PHY_BB_TXBF_PREMMSE_CTRL_TXBF_NO_CSD_LSB)
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_NO_CSD_SET(x)                            (((0 | (x)) << PHY_BB_TXBF_PREMMSE_CTRL_TXBF_NO_CSD_LSB) & PHY_BB_TXBF_PREMMSE_CTRL_TXBF_NO_CSD_MASK)
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_NO_CSD_RESET                             0x0
#define PHY_BB_TXBF_PREMMSE_CTRL_MU_PSN_FACTOR_LSB                             19
#define PHY_BB_TXBF_PREMMSE_CTRL_MU_PSN_FACTOR_MSB                             23
#define PHY_BB_TXBF_PREMMSE_CTRL_MU_PSN_FACTOR_MASK                            0xf80000
#define PHY_BB_TXBF_PREMMSE_CTRL_MU_PSN_FACTOR_GET(x)                          (((x) & PHY_BB_TXBF_PREMMSE_CTRL_MU_PSN_FACTOR_MASK) >> PHY_BB_TXBF_PREMMSE_CTRL_MU_PSN_FACTOR_LSB)
#define PHY_BB_TXBF_PREMMSE_CTRL_MU_PSN_FACTOR_SET(x)                          (((0 | (x)) << PHY_BB_TXBF_PREMMSE_CTRL_MU_PSN_FACTOR_LSB) & PHY_BB_TXBF_PREMMSE_CTRL_MU_PSN_FACTOR_MASK)
#define PHY_BB_TXBF_PREMMSE_CTRL_MU_PSN_FACTOR_RESET                           0xa
#define PHY_BB_TXBF_PREMMSE_CTRL_MU_REG_FACTOR_LSB                             14
#define PHY_BB_TXBF_PREMMSE_CTRL_MU_REG_FACTOR_MSB                             18
#define PHY_BB_TXBF_PREMMSE_CTRL_MU_REG_FACTOR_MASK                            0x7c000
#define PHY_BB_TXBF_PREMMSE_CTRL_MU_REG_FACTOR_GET(x)                          (((x) & PHY_BB_TXBF_PREMMSE_CTRL_MU_REG_FACTOR_MASK) >> PHY_BB_TXBF_PREMMSE_CTRL_MU_REG_FACTOR_LSB)
#define PHY_BB_TXBF_PREMMSE_CTRL_MU_REG_FACTOR_SET(x)                          (((0 | (x)) << PHY_BB_TXBF_PREMMSE_CTRL_MU_REG_FACTOR_LSB) & PHY_BB_TXBF_PREMMSE_CTRL_MU_REG_FACTOR_MASK)
#define PHY_BB_TXBF_PREMMSE_CTRL_MU_REG_FACTOR_RESET                           0x4
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_V_SMOOTH_LSB                             13
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_V_SMOOTH_MSB                             13
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_V_SMOOTH_MASK                            0x2000
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_V_SMOOTH_GET(x)                          (((x) & PHY_BB_TXBF_PREMMSE_CTRL_TXBF_V_SMOOTH_MASK) >> PHY_BB_TXBF_PREMMSE_CTRL_TXBF_V_SMOOTH_LSB)
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_V_SMOOTH_SET(x)                          (((0 | (x)) << PHY_BB_TXBF_PREMMSE_CTRL_TXBF_V_SMOOTH_LSB) & PHY_BB_TXBF_PREMMSE_CTRL_TXBF_V_SMOOTH_MASK)
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_V_SMOOTH_RESET                           0x0
#define PHY_BB_TXBF_PREMMSE_CTRL_PREMMSE_NOISE_LSB                             5
#define PHY_BB_TXBF_PREMMSE_CTRL_PREMMSE_NOISE_MSB                             12
#define PHY_BB_TXBF_PREMMSE_CTRL_PREMMSE_NOISE_MASK                            0x1fe0
#define PHY_BB_TXBF_PREMMSE_CTRL_PREMMSE_NOISE_GET(x)                          (((x) & PHY_BB_TXBF_PREMMSE_CTRL_PREMMSE_NOISE_MASK) >> PHY_BB_TXBF_PREMMSE_CTRL_PREMMSE_NOISE_LSB)
#define PHY_BB_TXBF_PREMMSE_CTRL_PREMMSE_NOISE_SET(x)                          (((0 | (x)) << PHY_BB_TXBF_PREMMSE_CTRL_PREMMSE_NOISE_LSB) & PHY_BB_TXBF_PREMMSE_CTRL_PREMMSE_NOISE_MASK)
#define PHY_BB_TXBF_PREMMSE_CTRL_PREMMSE_NOISE_RESET                           0x4d
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_NSS_LSB                          3
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_NSS_MSB                          4
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_NSS_MASK                         0x18
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_NSS_GET(x)                       (((x) & PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_NSS_MASK) >> PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_NSS_LSB)
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_NSS_SET(x)                       (((0 | (x)) << PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_NSS_LSB) & PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_NSS_MASK)
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_NSS_RESET                        0x0
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_LSB                              0
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_MSB                              2
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_MASK                             0x7
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_GET(x)                           (((x) & PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_MASK) >> PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_LSB)
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_SET(x)                           (((0 | (x)) << PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_LSB) & PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_MASK)
#define PHY_BB_TXBF_PREMMSE_CTRL_TXBF_PREMMSE_RESET                            0x0
#define PHY_BB_TXBF_PREMMSE_CTRL_ADDRESS                                       (0x8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF_PREMMSE_CTRL_RSTMASK                                       0x1ffffff
#define PHY_BB_TXBF_PREMMSE_CTRL_RESET                                         0x5109a0

// 0xc (PHY_BB_TXBF_PREMMSE_SNR)
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C2_LSB                             16
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C2_MSB                             23
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C2_MASK                            0xff0000
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C2_GET(x)                          (((x) & PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C2_MASK) >> PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C2_LSB)
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C2_SET(x)                          (((0 | (x)) << PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C2_LSB) & PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C2_MASK)
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C2_RESET                           0x40
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C1_LSB                             8
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C1_MSB                             15
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C1_MASK                            0xff00
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C1_GET(x)                          (((x) & PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C1_MASK) >> PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C1_LSB)
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C1_SET(x)                          (((0 | (x)) << PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C1_LSB) & PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C1_MASK)
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C1_RESET                           0xa8
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C0_LSB                             0
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C0_MSB                             7
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C0_MASK                            0xff
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C0_GET(x)                          (((x) & PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C0_MASK) >> PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C0_LSB)
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C0_SET(x)                          (((0 | (x)) << PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C0_LSB) & PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C0_MASK)
#define PHY_BB_TXBF_PREMMSE_SNR_PREMMSE_SNR_C0_RESET                           0xc0
#define PHY_BB_TXBF_PREMMSE_SNR_ADDRESS                                        (0xc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF_PREMMSE_SNR_RSTMASK                                        0xffffff
#define PHY_BB_TXBF_PREMMSE_SNR_RESET                                          0x40a8c0

// 0x10 (PHY_BB_TXBF_BFEE_RX_CTRL)
#define PHY_BB_TXBF_BFEE_RX_CTRL_TXBF_SNR_BIAS_LSB                             18
#define PHY_BB_TXBF_BFEE_RX_CTRL_TXBF_SNR_BIAS_MSB                             21
#define PHY_BB_TXBF_BFEE_RX_CTRL_TXBF_SNR_BIAS_MASK                            0x3c0000
#define PHY_BB_TXBF_BFEE_RX_CTRL_TXBF_SNR_BIAS_GET(x)                          (((x) & PHY_BB_TXBF_BFEE_RX_CTRL_TXBF_SNR_BIAS_MASK) >> PHY_BB_TXBF_BFEE_RX_CTRL_TXBF_SNR_BIAS_LSB)
#define PHY_BB_TXBF_BFEE_RX_CTRL_TXBF_SNR_BIAS_SET(x)                          (((0 | (x)) << PHY_BB_TXBF_BFEE_RX_CTRL_TXBF_SNR_BIAS_LSB) & PHY_BB_TXBF_BFEE_RX_CTRL_TXBF_SNR_BIAS_MASK)
#define PHY_BB_TXBF_BFEE_RX_CTRL_TXBF_SNR_BIAS_RESET                           0x0
#define PHY_BB_TXBF_BFEE_RX_CTRL_RM_HCSD4SVD_LSB                               3
#define PHY_BB_TXBF_BFEE_RX_CTRL_RM_HCSD4SVD_MSB                               3
#define PHY_BB_TXBF_BFEE_RX_CTRL_RM_HCSD4SVD_MASK                              0x8
#define PHY_BB_TXBF_BFEE_RX_CTRL_RM_HCSD4SVD_GET(x)                            (((x) & PHY_BB_TXBF_BFEE_RX_CTRL_RM_HCSD4SVD_MASK) >> PHY_BB_TXBF_BFEE_RX_CTRL_RM_HCSD4SVD_LSB)
#define PHY_BB_TXBF_BFEE_RX_CTRL_RM_HCSD4SVD_SET(x)                            (((0 | (x)) << PHY_BB_TXBF_BFEE_RX_CTRL_RM_HCSD4SVD_LSB) & PHY_BB_TXBF_BFEE_RX_CTRL_RM_HCSD4SVD_MASK)
#define PHY_BB_TXBF_BFEE_RX_CTRL_RM_HCSD4SVD_RESET                             0x1
#define PHY_BB_TXBF_BFEE_RX_CTRL_RX_SOUNDING_ENABLE_REG_LSB                    2
#define PHY_BB_TXBF_BFEE_RX_CTRL_RX_SOUNDING_ENABLE_REG_MSB                    2
#define PHY_BB_TXBF_BFEE_RX_CTRL_RX_SOUNDING_ENABLE_REG_MASK                   0x4
#define PHY_BB_TXBF_BFEE_RX_CTRL_RX_SOUNDING_ENABLE_REG_GET(x)                 (((x) & PHY_BB_TXBF_BFEE_RX_CTRL_RX_SOUNDING_ENABLE_REG_MASK) >> PHY_BB_TXBF_BFEE_RX_CTRL_RX_SOUNDING_ENABLE_REG_LSB)
#define PHY_BB_TXBF_BFEE_RX_CTRL_RX_SOUNDING_ENABLE_REG_SET(x)                 (((0 | (x)) << PHY_BB_TXBF_BFEE_RX_CTRL_RX_SOUNDING_ENABLE_REG_LSB) & PHY_BB_TXBF_BFEE_RX_CTRL_RX_SOUNDING_ENABLE_REG_MASK)
#define PHY_BB_TXBF_BFEE_RX_CTRL_RX_SOUNDING_ENABLE_REG_RESET                  0x1
#define PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_SEND_CHAN_LSB                          1
#define PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_SEND_CHAN_MSB                          1
#define PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_SEND_CHAN_MASK                         0x2
#define PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_SEND_CHAN_GET(x)                       (((x) & PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_SEND_CHAN_MASK) >> PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_SEND_CHAN_LSB)
#define PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_SEND_CHAN_SET(x)                       (((0 | (x)) << PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_SEND_CHAN_LSB) & PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_SEND_CHAN_MASK)
#define PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_SEND_CHAN_RESET                        0x0
#define PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_FLT_SVD_LSB                            0
#define PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_FLT_SVD_MSB                            0
#define PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_FLT_SVD_MASK                           0x1
#define PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_FLT_SVD_GET(x)                         (((x) & PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_FLT_SVD_MASK) >> PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_FLT_SVD_LSB)
#define PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_FLT_SVD_SET(x)                         (((0 | (x)) << PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_FLT_SVD_LSB) & PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_FLT_SVD_MASK)
#define PHY_BB_TXBF_BFEE_RX_CTRL_ENABLE_FLT_SVD_RESET                          0x1
#define PHY_BB_TXBF_BFEE_RX_CTRL_ADDRESS                                       (0x10 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF_BFEE_RX_CTRL_RSTMASK                                       0x3c000f
#define PHY_BB_TXBF_BFEE_RX_CTRL_RESET                                         0xd

// 0x14 (PHY_BB_TXBF_IMPLICIT_RX_CTRL)
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_APPLY_IBF_COEF_LSB                        2
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_APPLY_IBF_COEF_MSB                        2
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_APPLY_IBF_COEF_MASK                       0x4
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_APPLY_IBF_COEF_GET(x)                     (((x) & PHY_BB_TXBF_IMPLICIT_RX_CTRL_APPLY_IBF_COEF_MASK) >> PHY_BB_TXBF_IMPLICIT_RX_CTRL_APPLY_IBF_COEF_LSB)
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_APPLY_IBF_COEF_SET(x)                     (((0 | (x)) << PHY_BB_TXBF_IMPLICIT_RX_CTRL_APPLY_IBF_COEF_LSB) & PHY_BB_TXBF_IMPLICIT_RX_CTRL_APPLY_IBF_COEF_MASK)
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_APPLY_IBF_COEF_RESET                      0x1
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_TXBF_IMPLICIT_LEGACY_ONLY_LSB             1
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_TXBF_IMPLICIT_LEGACY_ONLY_MSB             1
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_TXBF_IMPLICIT_LEGACY_ONLY_MASK            0x2
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_TXBF_IMPLICIT_LEGACY_ONLY_GET(x)          (((x) & PHY_BB_TXBF_IMPLICIT_RX_CTRL_TXBF_IMPLICIT_LEGACY_ONLY_MASK) >> PHY_BB_TXBF_IMPLICIT_RX_CTRL_TXBF_IMPLICIT_LEGACY_ONLY_LSB)
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_TXBF_IMPLICIT_LEGACY_ONLY_SET(x)          (((0 | (x)) << PHY_BB_TXBF_IMPLICIT_RX_CTRL_TXBF_IMPLICIT_LEGACY_ONLY_LSB) & PHY_BB_TXBF_IMPLICIT_RX_CTRL_TXBF_IMPLICIT_LEGACY_ONLY_MASK)
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_TXBF_IMPLICIT_LEGACY_ONLY_RESET           0x0
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_IMPLICIT_FB_ALL_RX_PKTS_LSB               0
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_IMPLICIT_FB_ALL_RX_PKTS_MSB               0
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_IMPLICIT_FB_ALL_RX_PKTS_MASK              0x1
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_IMPLICIT_FB_ALL_RX_PKTS_GET(x)            (((x) & PHY_BB_TXBF_IMPLICIT_RX_CTRL_IMPLICIT_FB_ALL_RX_PKTS_MASK) >> PHY_BB_TXBF_IMPLICIT_RX_CTRL_IMPLICIT_FB_ALL_RX_PKTS_LSB)
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_IMPLICIT_FB_ALL_RX_PKTS_SET(x)            (((0 | (x)) << PHY_BB_TXBF_IMPLICIT_RX_CTRL_IMPLICIT_FB_ALL_RX_PKTS_LSB) & PHY_BB_TXBF_IMPLICIT_RX_CTRL_IMPLICIT_FB_ALL_RX_PKTS_MASK)
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_IMPLICIT_FB_ALL_RX_PKTS_RESET             0x0
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_ADDRESS                                   (0x14 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_RSTMASK                                   0x7
#define PHY_BB_TXBF_IMPLICIT_RX_CTRL_RESET                                     0x4

// 0x100 (PHY_BB_TXBF_SM)
#define PHY_BB_TXBF_SM_TXBF_SM_OBS_LSB                                         0
#define PHY_BB_TXBF_SM_TXBF_SM_OBS_MSB                                         31
#define PHY_BB_TXBF_SM_TXBF_SM_OBS_MASK                                        0xffffffff
#define PHY_BB_TXBF_SM_TXBF_SM_OBS_GET(x)                                      (((x) & PHY_BB_TXBF_SM_TXBF_SM_OBS_MASK) >> PHY_BB_TXBF_SM_TXBF_SM_OBS_LSB)
#define PHY_BB_TXBF_SM_TXBF_SM_OBS_SET(x)                                      (((0 | (x)) << PHY_BB_TXBF_SM_TXBF_SM_OBS_LSB) & PHY_BB_TXBF_SM_TXBF_SM_OBS_MASK)
#define PHY_BB_TXBF_SM_TXBF_SM_OBS_RESET                                       0x0
#define PHY_BB_TXBF_SM_ADDRESS                                                 (0x100 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF_SM_RSTMASK                                                 0xffffffff
#define PHY_BB_TXBF_SM_RESET                                                   0x0

// 0x104 (PHY_BB_TXBF1_CNTL)
#define PHY_BB_TXBF1_CNTL_TXBF1_CNTL_OBS_LSB                                   0
#define PHY_BB_TXBF1_CNTL_TXBF1_CNTL_OBS_MSB                                   31
#define PHY_BB_TXBF1_CNTL_TXBF1_CNTL_OBS_MASK                                  0xffffffff
#define PHY_BB_TXBF1_CNTL_TXBF1_CNTL_OBS_GET(x)                                (((x) & PHY_BB_TXBF1_CNTL_TXBF1_CNTL_OBS_MASK) >> PHY_BB_TXBF1_CNTL_TXBF1_CNTL_OBS_LSB)
#define PHY_BB_TXBF1_CNTL_TXBF1_CNTL_OBS_SET(x)                                (((0 | (x)) << PHY_BB_TXBF1_CNTL_TXBF1_CNTL_OBS_LSB) & PHY_BB_TXBF1_CNTL_TXBF1_CNTL_OBS_MASK)
#define PHY_BB_TXBF1_CNTL_TXBF1_CNTL_OBS_RESET                                 0x0
#define PHY_BB_TXBF1_CNTL_ADDRESS                                              (0x104 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF1_CNTL_RSTMASK                                              0xffffffff
#define PHY_BB_TXBF1_CNTL_RESET                                                0x0

// 0x108 (PHY_BB_TXBF2_CNTL)
#define PHY_BB_TXBF2_CNTL_TXBF2_CNTL_OBS_LSB                                   0
#define PHY_BB_TXBF2_CNTL_TXBF2_CNTL_OBS_MSB                                   31
#define PHY_BB_TXBF2_CNTL_TXBF2_CNTL_OBS_MASK                                  0xffffffff
#define PHY_BB_TXBF2_CNTL_TXBF2_CNTL_OBS_GET(x)                                (((x) & PHY_BB_TXBF2_CNTL_TXBF2_CNTL_OBS_MASK) >> PHY_BB_TXBF2_CNTL_TXBF2_CNTL_OBS_LSB)
#define PHY_BB_TXBF2_CNTL_TXBF2_CNTL_OBS_SET(x)                                (((0 | (x)) << PHY_BB_TXBF2_CNTL_TXBF2_CNTL_OBS_LSB) & PHY_BB_TXBF2_CNTL_TXBF2_CNTL_OBS_MASK)
#define PHY_BB_TXBF2_CNTL_TXBF2_CNTL_OBS_RESET                                 0x8000
#define PHY_BB_TXBF2_CNTL_ADDRESS                                              (0x108 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF2_CNTL_RSTMASK                                              0xffffffff
#define PHY_BB_TXBF2_CNTL_RESET                                                0x8000

// 0x10c (PHY_BB_TXBF3_CNTL)
#define PHY_BB_TXBF3_CNTL_TXBF3_CNTL_OBS_LSB                                   0
#define PHY_BB_TXBF3_CNTL_TXBF3_CNTL_OBS_MSB                                   31
#define PHY_BB_TXBF3_CNTL_TXBF3_CNTL_OBS_MASK                                  0xffffffff
#define PHY_BB_TXBF3_CNTL_TXBF3_CNTL_OBS_GET(x)                                (((x) & PHY_BB_TXBF3_CNTL_TXBF3_CNTL_OBS_MASK) >> PHY_BB_TXBF3_CNTL_TXBF3_CNTL_OBS_LSB)
#define PHY_BB_TXBF3_CNTL_TXBF3_CNTL_OBS_SET(x)                                (((0 | (x)) << PHY_BB_TXBF3_CNTL_TXBF3_CNTL_OBS_LSB) & PHY_BB_TXBF3_CNTL_TXBF3_CNTL_OBS_MASK)
#define PHY_BB_TXBF3_CNTL_TXBF3_CNTL_OBS_RESET                                 0x200033
#define PHY_BB_TXBF3_CNTL_ADDRESS                                              (0x10c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF3_CNTL_RSTMASK                                              0xffffffff
#define PHY_BB_TXBF3_CNTL_RESET                                                0x200033

// 0x110 (PHY_BB_TXBF4_CNTL)
#define PHY_BB_TXBF4_CNTL_TXBF4_CNTL_OBS_LSB                                   0
#define PHY_BB_TXBF4_CNTL_TXBF4_CNTL_OBS_MSB                                   31
#define PHY_BB_TXBF4_CNTL_TXBF4_CNTL_OBS_MASK                                  0xffffffff
#define PHY_BB_TXBF4_CNTL_TXBF4_CNTL_OBS_GET(x)                                (((x) & PHY_BB_TXBF4_CNTL_TXBF4_CNTL_OBS_MASK) >> PHY_BB_TXBF4_CNTL_TXBF4_CNTL_OBS_LSB)
#define PHY_BB_TXBF4_CNTL_TXBF4_CNTL_OBS_SET(x)                                (((0 | (x)) << PHY_BB_TXBF4_CNTL_TXBF4_CNTL_OBS_LSB) & PHY_BB_TXBF4_CNTL_TXBF4_CNTL_OBS_MASK)
#define PHY_BB_TXBF4_CNTL_TXBF4_CNTL_OBS_RESET                                 0x0
#define PHY_BB_TXBF4_CNTL_ADDRESS                                              (0x110 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF4_CNTL_RSTMASK                                              0xffffffff
#define PHY_BB_TXBF4_CNTL_RESET                                                0x0

// 0x114 (PHY_BB_TXBF5_CNTL)
#define PHY_BB_TXBF5_CNTL_TXBF5_CNTL_OBS_LSB                                   0
#define PHY_BB_TXBF5_CNTL_TXBF5_CNTL_OBS_MSB                                   31
#define PHY_BB_TXBF5_CNTL_TXBF5_CNTL_OBS_MASK                                  0xffffffff
#define PHY_BB_TXBF5_CNTL_TXBF5_CNTL_OBS_GET(x)                                (((x) & PHY_BB_TXBF5_CNTL_TXBF5_CNTL_OBS_MASK) >> PHY_BB_TXBF5_CNTL_TXBF5_CNTL_OBS_LSB)
#define PHY_BB_TXBF5_CNTL_TXBF5_CNTL_OBS_SET(x)                                (((0 | (x)) << PHY_BB_TXBF5_CNTL_TXBF5_CNTL_OBS_LSB) & PHY_BB_TXBF5_CNTL_TXBF5_CNTL_OBS_MASK)
#define PHY_BB_TXBF5_CNTL_TXBF5_CNTL_OBS_RESET                                 0x0
#define PHY_BB_TXBF5_CNTL_ADDRESS                                              (0x114 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF5_CNTL_RSTMASK                                              0xffffffff
#define PHY_BB_TXBF5_CNTL_RESET                                                0x0

// 0x118 (PHY_BB_TXBF6_CNTL)
#define PHY_BB_TXBF6_CNTL_TXBF6_CNTL_OBS_LSB                                   0
#define PHY_BB_TXBF6_CNTL_TXBF6_CNTL_OBS_MSB                                   31
#define PHY_BB_TXBF6_CNTL_TXBF6_CNTL_OBS_MASK                                  0xffffffff
#define PHY_BB_TXBF6_CNTL_TXBF6_CNTL_OBS_GET(x)                                (((x) & PHY_BB_TXBF6_CNTL_TXBF6_CNTL_OBS_MASK) >> PHY_BB_TXBF6_CNTL_TXBF6_CNTL_OBS_LSB)
#define PHY_BB_TXBF6_CNTL_TXBF6_CNTL_OBS_SET(x)                                (((0 | (x)) << PHY_BB_TXBF6_CNTL_TXBF6_CNTL_OBS_LSB) & PHY_BB_TXBF6_CNTL_TXBF6_CNTL_OBS_MASK)
#define PHY_BB_TXBF6_CNTL_TXBF6_CNTL_OBS_RESET                                 0x0
#define PHY_BB_TXBF6_CNTL_ADDRESS                                              (0x118 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF6_CNTL_RSTMASK                                              0xffffffff
#define PHY_BB_TXBF6_CNTL_RESET                                                0x0

// 0x11c (PHY_BB_TXBF7_CNTL)
#define PHY_BB_TXBF7_CNTL_TXBF7_CNTL_OBS_LSB                                   0
#define PHY_BB_TXBF7_CNTL_TXBF7_CNTL_OBS_MSB                                   31
#define PHY_BB_TXBF7_CNTL_TXBF7_CNTL_OBS_MASK                                  0xffffffff
#define PHY_BB_TXBF7_CNTL_TXBF7_CNTL_OBS_GET(x)                                (((x) & PHY_BB_TXBF7_CNTL_TXBF7_CNTL_OBS_MASK) >> PHY_BB_TXBF7_CNTL_TXBF7_CNTL_OBS_LSB)
#define PHY_BB_TXBF7_CNTL_TXBF7_CNTL_OBS_SET(x)                                (((0 | (x)) << PHY_BB_TXBF7_CNTL_TXBF7_CNTL_OBS_LSB) & PHY_BB_TXBF7_CNTL_TXBF7_CNTL_OBS_MASK)
#define PHY_BB_TXBF7_CNTL_TXBF7_CNTL_OBS_RESET                                 0x0
#define PHY_BB_TXBF7_CNTL_ADDRESS                                              (0x11c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF7_CNTL_RSTMASK                                              0xffffffff
#define PHY_BB_TXBF7_CNTL_RESET                                                0x0

// 0x120 (PHY_BB_TXBF8_CNTL)
#define PHY_BB_TXBF8_CNTL_TXBF8_CNTL_OBS_LSB                                   0
#define PHY_BB_TXBF8_CNTL_TXBF8_CNTL_OBS_MSB                                   31
#define PHY_BB_TXBF8_CNTL_TXBF8_CNTL_OBS_MASK                                  0xffffffff
#define PHY_BB_TXBF8_CNTL_TXBF8_CNTL_OBS_GET(x)                                (((x) & PHY_BB_TXBF8_CNTL_TXBF8_CNTL_OBS_MASK) >> PHY_BB_TXBF8_CNTL_TXBF8_CNTL_OBS_LSB)
#define PHY_BB_TXBF8_CNTL_TXBF8_CNTL_OBS_SET(x)                                (((0 | (x)) << PHY_BB_TXBF8_CNTL_TXBF8_CNTL_OBS_LSB) & PHY_BB_TXBF8_CNTL_TXBF8_CNTL_OBS_MASK)
#define PHY_BB_TXBF8_CNTL_TXBF8_CNTL_OBS_RESET                                 0x0
#define PHY_BB_TXBF8_CNTL_ADDRESS                                              (0x120 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF8_CNTL_RSTMASK                                              0xffffffff
#define PHY_BB_TXBF8_CNTL_RESET                                                0x0

// 0x124 (PHY_BB_TXBF_DBG2)
#define PHY_BB_TXBF_DBG2_SVD_CBF_RESET_TIMER_LSB                               12
#define PHY_BB_TXBF_DBG2_SVD_CBF_RESET_TIMER_MSB                               19
#define PHY_BB_TXBF_DBG2_SVD_CBF_RESET_TIMER_MASK                              0xff000
#define PHY_BB_TXBF_DBG2_SVD_CBF_RESET_TIMER_GET(x)                            (((x) & PHY_BB_TXBF_DBG2_SVD_CBF_RESET_TIMER_MASK) >> PHY_BB_TXBF_DBG2_SVD_CBF_RESET_TIMER_LSB)
#define PHY_BB_TXBF_DBG2_SVD_CBF_RESET_TIMER_SET(x)                            (((0 | (x)) << PHY_BB_TXBF_DBG2_SVD_CBF_RESET_TIMER_LSB) & PHY_BB_TXBF_DBG2_SVD_CBF_RESET_TIMER_MASK)
#define PHY_BB_TXBF_DBG2_SVD_CBF_RESET_TIMER_RESET                             0x0
#define PHY_BB_TXBF_DBG2_SVD_RX_RESET_TIMER_LSB                                5
#define PHY_BB_TXBF_DBG2_SVD_RX_RESET_TIMER_MSB                                11
#define PHY_BB_TXBF_DBG2_SVD_RX_RESET_TIMER_MASK                               0xfe0
#define PHY_BB_TXBF_DBG2_SVD_RX_RESET_TIMER_GET(x)                             (((x) & PHY_BB_TXBF_DBG2_SVD_RX_RESET_TIMER_MASK) >> PHY_BB_TXBF_DBG2_SVD_RX_RESET_TIMER_LSB)
#define PHY_BB_TXBF_DBG2_SVD_RX_RESET_TIMER_SET(x)                             (((0 | (x)) << PHY_BB_TXBF_DBG2_SVD_RX_RESET_TIMER_LSB) & PHY_BB_TXBF_DBG2_SVD_RX_RESET_TIMER_MASK)
#define PHY_BB_TXBF_DBG2_SVD_RX_RESET_TIMER_RESET                              0x0
#define PHY_BB_TXBF_DBG2_SVD_DBG_BUS_SEL_LSB                                   0
#define PHY_BB_TXBF_DBG2_SVD_DBG_BUS_SEL_MSB                                   4
#define PHY_BB_TXBF_DBG2_SVD_DBG_BUS_SEL_MASK                                  0x1f
#define PHY_BB_TXBF_DBG2_SVD_DBG_BUS_SEL_GET(x)                                (((x) & PHY_BB_TXBF_DBG2_SVD_DBG_BUS_SEL_MASK) >> PHY_BB_TXBF_DBG2_SVD_DBG_BUS_SEL_LSB)
#define PHY_BB_TXBF_DBG2_SVD_DBG_BUS_SEL_SET(x)                                (((0 | (x)) << PHY_BB_TXBF_DBG2_SVD_DBG_BUS_SEL_LSB) & PHY_BB_TXBF_DBG2_SVD_DBG_BUS_SEL_MASK)
#define PHY_BB_TXBF_DBG2_SVD_DBG_BUS_SEL_RESET                                 0x0
#define PHY_BB_TXBF_DBG2_ADDRESS                                               (0x124 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TXBF_DBG2_RSTMASK                                               0xfffff
#define PHY_BB_TXBF_DBG2_RESET                                                 0x0

// 0x1400 (PHY_BB_SVD_MEM0)
#define PHY_BB_SVD_MEM0_SVD_MEM0_LSB                                           0
#define PHY_BB_SVD_MEM0_SVD_MEM0_MSB                                           31
#define PHY_BB_SVD_MEM0_SVD_MEM0_MASK                                          0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_GET(x)                                        (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_SET(x)                                        (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_RESET                                         0x0
#define PHY_BB_SVD_MEM0_ADDRESS                                                (0x1400 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_RSTMASK                                                0xffffffff
#define PHY_BB_SVD_MEM0_RESET                                                  0x0

// 0x1400 (PHY_BB_SVD_MEM0_0)
#define PHY_BB_SVD_MEM0_SVD_MEM0_0_LSB                                         0
#define PHY_BB_SVD_MEM0_SVD_MEM0_0_MSB                                         31
#define PHY_BB_SVD_MEM0_SVD_MEM0_0_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_0_GET(x)                                      (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_0_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_0_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_0_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_0_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_0_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_0_RESET                                       0x0
#define PHY_BB_SVD_MEM0_0_ADDRESS                                              (0x1400 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_0_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM0_0_RESET                                                0x0

// 0x1404 (PHY_BB_SVD_MEM0_1)
#define PHY_BB_SVD_MEM0_SVD_MEM0_1_LSB                                         0
#define PHY_BB_SVD_MEM0_SVD_MEM0_1_MSB                                         31
#define PHY_BB_SVD_MEM0_SVD_MEM0_1_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_1_GET(x)                                      (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_1_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_1_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_1_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_1_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_1_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_1_RESET                                       0x0
#define PHY_BB_SVD_MEM0_1_ADDRESS                                              (0x1404 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_1_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM0_1_RESET                                                0x0

// 0x1408 (PHY_BB_SVD_MEM0_2)
#define PHY_BB_SVD_MEM0_SVD_MEM0_2_LSB                                         0
#define PHY_BB_SVD_MEM0_SVD_MEM0_2_MSB                                         31
#define PHY_BB_SVD_MEM0_SVD_MEM0_2_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_2_GET(x)                                      (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_2_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_2_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_2_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_2_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_2_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_2_RESET                                       0x0
#define PHY_BB_SVD_MEM0_2_ADDRESS                                              (0x1408 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_2_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM0_2_RESET                                                0x0

// 0x140c (PHY_BB_SVD_MEM0_3)
#define PHY_BB_SVD_MEM0_SVD_MEM0_3_LSB                                         0
#define PHY_BB_SVD_MEM0_SVD_MEM0_3_MSB                                         31
#define PHY_BB_SVD_MEM0_SVD_MEM0_3_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_3_GET(x)                                      (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_3_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_3_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_3_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_3_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_3_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_3_RESET                                       0x0
#define PHY_BB_SVD_MEM0_3_ADDRESS                                              (0x140c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_3_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM0_3_RESET                                                0x0

// 0x1410 (PHY_BB_SVD_MEM0_4)
#define PHY_BB_SVD_MEM0_SVD_MEM0_4_LSB                                         0
#define PHY_BB_SVD_MEM0_SVD_MEM0_4_MSB                                         31
#define PHY_BB_SVD_MEM0_SVD_MEM0_4_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_4_GET(x)                                      (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_4_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_4_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_4_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_4_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_4_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_4_RESET                                       0x0
#define PHY_BB_SVD_MEM0_4_ADDRESS                                              (0x1410 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_4_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM0_4_RESET                                                0x0

// 0x1414 (PHY_BB_SVD_MEM0_5)
#define PHY_BB_SVD_MEM0_SVD_MEM0_5_LSB                                         0
#define PHY_BB_SVD_MEM0_SVD_MEM0_5_MSB                                         31
#define PHY_BB_SVD_MEM0_SVD_MEM0_5_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_5_GET(x)                                      (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_5_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_5_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_5_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_5_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_5_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_5_RESET                                       0x0
#define PHY_BB_SVD_MEM0_5_ADDRESS                                              (0x1414 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_5_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM0_5_RESET                                                0x0

// 0x1418 (PHY_BB_SVD_MEM0_6)
#define PHY_BB_SVD_MEM0_SVD_MEM0_6_LSB                                         0
#define PHY_BB_SVD_MEM0_SVD_MEM0_6_MSB                                         31
#define PHY_BB_SVD_MEM0_SVD_MEM0_6_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_6_GET(x)                                      (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_6_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_6_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_6_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_6_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_6_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_6_RESET                                       0x0
#define PHY_BB_SVD_MEM0_6_ADDRESS                                              (0x1418 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_6_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM0_6_RESET                                                0x0

// 0x141c (PHY_BB_SVD_MEM0_7)
#define PHY_BB_SVD_MEM0_SVD_MEM0_7_LSB                                         0
#define PHY_BB_SVD_MEM0_SVD_MEM0_7_MSB                                         31
#define PHY_BB_SVD_MEM0_SVD_MEM0_7_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_7_GET(x)                                      (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_7_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_7_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_7_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_7_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_7_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_7_RESET                                       0x0
#define PHY_BB_SVD_MEM0_7_ADDRESS                                              (0x141c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_7_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM0_7_RESET                                                0x0

// 0x1420 (PHY_BB_SVD_MEM0_8)
#define PHY_BB_SVD_MEM0_SVD_MEM0_8_LSB                                         0
#define PHY_BB_SVD_MEM0_SVD_MEM0_8_MSB                                         31
#define PHY_BB_SVD_MEM0_SVD_MEM0_8_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_8_GET(x)                                      (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_8_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_8_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_8_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_8_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_8_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_8_RESET                                       0x0
#define PHY_BB_SVD_MEM0_8_ADDRESS                                              (0x1420 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_8_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM0_8_RESET                                                0x0

// 0x1424 (PHY_BB_SVD_MEM0_9)
#define PHY_BB_SVD_MEM0_SVD_MEM0_9_LSB                                         0
#define PHY_BB_SVD_MEM0_SVD_MEM0_9_MSB                                         31
#define PHY_BB_SVD_MEM0_SVD_MEM0_9_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_9_GET(x)                                      (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_9_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_9_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_9_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_9_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_9_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_9_RESET                                       0x0
#define PHY_BB_SVD_MEM0_9_ADDRESS                                              (0x1424 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_9_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM0_9_RESET                                                0x0

// 0x1428 (PHY_BB_SVD_MEM0_10)
#define PHY_BB_SVD_MEM0_SVD_MEM0_10_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_10_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_10_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_10_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_10_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_10_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_10_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_10_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_10_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_10_RESET                                      0x0
#define PHY_BB_SVD_MEM0_10_ADDRESS                                             (0x1428 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_10_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_10_RESET                                               0x0

// 0x142c (PHY_BB_SVD_MEM0_11)
#define PHY_BB_SVD_MEM0_SVD_MEM0_11_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_11_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_11_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_11_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_11_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_11_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_11_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_11_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_11_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_11_RESET                                      0x0
#define PHY_BB_SVD_MEM0_11_ADDRESS                                             (0x142c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_11_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_11_RESET                                               0x0

// 0x1430 (PHY_BB_SVD_MEM0_12)
#define PHY_BB_SVD_MEM0_SVD_MEM0_12_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_12_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_12_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_12_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_12_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_12_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_12_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_12_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_12_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_12_RESET                                      0x0
#define PHY_BB_SVD_MEM0_12_ADDRESS                                             (0x1430 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_12_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_12_RESET                                               0x0

// 0x1434 (PHY_BB_SVD_MEM0_13)
#define PHY_BB_SVD_MEM0_SVD_MEM0_13_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_13_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_13_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_13_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_13_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_13_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_13_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_13_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_13_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_13_RESET                                      0x0
#define PHY_BB_SVD_MEM0_13_ADDRESS                                             (0x1434 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_13_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_13_RESET                                               0x0

// 0x1438 (PHY_BB_SVD_MEM0_14)
#define PHY_BB_SVD_MEM0_SVD_MEM0_14_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_14_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_14_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_14_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_14_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_14_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_14_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_14_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_14_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_14_RESET                                      0x0
#define PHY_BB_SVD_MEM0_14_ADDRESS                                             (0x1438 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_14_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_14_RESET                                               0x0

// 0x143c (PHY_BB_SVD_MEM0_15)
#define PHY_BB_SVD_MEM0_SVD_MEM0_15_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_15_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_15_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_15_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_15_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_15_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_15_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_15_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_15_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_15_RESET                                      0x0
#define PHY_BB_SVD_MEM0_15_ADDRESS                                             (0x143c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_15_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_15_RESET                                               0x0

// 0x1440 (PHY_BB_SVD_MEM0_16)
#define PHY_BB_SVD_MEM0_SVD_MEM0_16_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_16_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_16_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_16_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_16_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_16_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_16_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_16_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_16_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_16_RESET                                      0x0
#define PHY_BB_SVD_MEM0_16_ADDRESS                                             (0x1440 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_16_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_16_RESET                                               0x0

// 0x1444 (PHY_BB_SVD_MEM0_17)
#define PHY_BB_SVD_MEM0_SVD_MEM0_17_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_17_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_17_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_17_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_17_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_17_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_17_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_17_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_17_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_17_RESET                                      0x0
#define PHY_BB_SVD_MEM0_17_ADDRESS                                             (0x1444 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_17_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_17_RESET                                               0x0

// 0x1448 (PHY_BB_SVD_MEM0_18)
#define PHY_BB_SVD_MEM0_SVD_MEM0_18_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_18_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_18_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_18_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_18_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_18_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_18_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_18_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_18_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_18_RESET                                      0x0
#define PHY_BB_SVD_MEM0_18_ADDRESS                                             (0x1448 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_18_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_18_RESET                                               0x0

// 0x144c (PHY_BB_SVD_MEM0_19)
#define PHY_BB_SVD_MEM0_SVD_MEM0_19_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_19_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_19_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_19_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_19_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_19_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_19_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_19_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_19_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_19_RESET                                      0x0
#define PHY_BB_SVD_MEM0_19_ADDRESS                                             (0x144c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_19_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_19_RESET                                               0x0

// 0x1450 (PHY_BB_SVD_MEM0_20)
#define PHY_BB_SVD_MEM0_SVD_MEM0_20_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_20_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_20_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_20_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_20_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_20_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_20_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_20_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_20_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_20_RESET                                      0x0
#define PHY_BB_SVD_MEM0_20_ADDRESS                                             (0x1450 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_20_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_20_RESET                                               0x0

// 0x1454 (PHY_BB_SVD_MEM0_21)
#define PHY_BB_SVD_MEM0_SVD_MEM0_21_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_21_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_21_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_21_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_21_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_21_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_21_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_21_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_21_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_21_RESET                                      0x0
#define PHY_BB_SVD_MEM0_21_ADDRESS                                             (0x1454 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_21_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_21_RESET                                               0x0

// 0x1458 (PHY_BB_SVD_MEM0_22)
#define PHY_BB_SVD_MEM0_SVD_MEM0_22_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_22_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_22_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_22_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_22_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_22_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_22_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_22_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_22_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_22_RESET                                      0x0
#define PHY_BB_SVD_MEM0_22_ADDRESS                                             (0x1458 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_22_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_22_RESET                                               0x0

// 0x145c (PHY_BB_SVD_MEM0_23)
#define PHY_BB_SVD_MEM0_SVD_MEM0_23_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_23_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_23_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_23_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_23_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_23_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_23_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_23_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_23_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_23_RESET                                      0x0
#define PHY_BB_SVD_MEM0_23_ADDRESS                                             (0x145c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_23_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_23_RESET                                               0x0

// 0x1460 (PHY_BB_SVD_MEM0_24)
#define PHY_BB_SVD_MEM0_SVD_MEM0_24_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_24_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_24_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_24_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_24_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_24_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_24_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_24_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_24_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_24_RESET                                      0x0
#define PHY_BB_SVD_MEM0_24_ADDRESS                                             (0x1460 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_24_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_24_RESET                                               0x0

// 0x1464 (PHY_BB_SVD_MEM0_25)
#define PHY_BB_SVD_MEM0_SVD_MEM0_25_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_25_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_25_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_25_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_25_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_25_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_25_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_25_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_25_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_25_RESET                                      0x0
#define PHY_BB_SVD_MEM0_25_ADDRESS                                             (0x1464 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_25_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_25_RESET                                               0x0

// 0x1468 (PHY_BB_SVD_MEM0_26)
#define PHY_BB_SVD_MEM0_SVD_MEM0_26_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_26_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_26_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_26_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_26_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_26_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_26_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_26_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_26_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_26_RESET                                      0x0
#define PHY_BB_SVD_MEM0_26_ADDRESS                                             (0x1468 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_26_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_26_RESET                                               0x0

// 0x146c (PHY_BB_SVD_MEM0_27)
#define PHY_BB_SVD_MEM0_SVD_MEM0_27_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_27_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_27_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_27_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_27_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_27_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_27_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_27_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_27_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_27_RESET                                      0x0
#define PHY_BB_SVD_MEM0_27_ADDRESS                                             (0x146c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_27_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_27_RESET                                               0x0

// 0x1470 (PHY_BB_SVD_MEM0_28)
#define PHY_BB_SVD_MEM0_SVD_MEM0_28_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_28_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_28_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_28_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_28_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_28_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_28_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_28_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_28_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_28_RESET                                      0x0
#define PHY_BB_SVD_MEM0_28_ADDRESS                                             (0x1470 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_28_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_28_RESET                                               0x0

// 0x1474 (PHY_BB_SVD_MEM0_29)
#define PHY_BB_SVD_MEM0_SVD_MEM0_29_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_29_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_29_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_29_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_29_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_29_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_29_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_29_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_29_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_29_RESET                                      0x0
#define PHY_BB_SVD_MEM0_29_ADDRESS                                             (0x1474 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_29_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_29_RESET                                               0x0

// 0x1478 (PHY_BB_SVD_MEM0_30)
#define PHY_BB_SVD_MEM0_SVD_MEM0_30_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_30_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_30_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_30_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_30_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_30_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_30_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_30_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_30_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_30_RESET                                      0x0
#define PHY_BB_SVD_MEM0_30_ADDRESS                                             (0x1478 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_30_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_30_RESET                                               0x0

// 0x147c (PHY_BB_SVD_MEM0_31)
#define PHY_BB_SVD_MEM0_SVD_MEM0_31_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_31_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_31_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_31_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_31_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_31_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_31_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_31_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_31_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_31_RESET                                      0x0
#define PHY_BB_SVD_MEM0_31_ADDRESS                                             (0x147c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_31_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_31_RESET                                               0x0

// 0x1480 (PHY_BB_SVD_MEM0_32)
#define PHY_BB_SVD_MEM0_SVD_MEM0_32_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_32_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_32_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_32_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_32_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_32_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_32_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_32_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_32_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_32_RESET                                      0x0
#define PHY_BB_SVD_MEM0_32_ADDRESS                                             (0x1480 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_32_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_32_RESET                                               0x0

// 0x1484 (PHY_BB_SVD_MEM0_33)
#define PHY_BB_SVD_MEM0_SVD_MEM0_33_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_33_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_33_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_33_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_33_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_33_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_33_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_33_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_33_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_33_RESET                                      0x0
#define PHY_BB_SVD_MEM0_33_ADDRESS                                             (0x1484 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_33_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_33_RESET                                               0x0

// 0x1488 (PHY_BB_SVD_MEM0_34)
#define PHY_BB_SVD_MEM0_SVD_MEM0_34_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_34_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_34_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_34_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_34_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_34_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_34_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_34_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_34_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_34_RESET                                      0x0
#define PHY_BB_SVD_MEM0_34_ADDRESS                                             (0x1488 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_34_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_34_RESET                                               0x0

// 0x148c (PHY_BB_SVD_MEM0_35)
#define PHY_BB_SVD_MEM0_SVD_MEM0_35_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_35_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_35_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_35_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_35_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_35_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_35_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_35_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_35_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_35_RESET                                      0x0
#define PHY_BB_SVD_MEM0_35_ADDRESS                                             (0x148c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_35_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_35_RESET                                               0x0

// 0x1490 (PHY_BB_SVD_MEM0_36)
#define PHY_BB_SVD_MEM0_SVD_MEM0_36_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_36_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_36_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_36_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_36_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_36_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_36_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_36_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_36_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_36_RESET                                      0x0
#define PHY_BB_SVD_MEM0_36_ADDRESS                                             (0x1490 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_36_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_36_RESET                                               0x0

// 0x1494 (PHY_BB_SVD_MEM0_37)
#define PHY_BB_SVD_MEM0_SVD_MEM0_37_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_37_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_37_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_37_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_37_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_37_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_37_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_37_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_37_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_37_RESET                                      0x0
#define PHY_BB_SVD_MEM0_37_ADDRESS                                             (0x1494 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_37_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_37_RESET                                               0x0

// 0x1498 (PHY_BB_SVD_MEM0_38)
#define PHY_BB_SVD_MEM0_SVD_MEM0_38_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_38_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_38_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_38_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_38_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_38_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_38_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_38_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_38_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_38_RESET                                      0x0
#define PHY_BB_SVD_MEM0_38_ADDRESS                                             (0x1498 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_38_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_38_RESET                                               0x0

// 0x149c (PHY_BB_SVD_MEM0_39)
#define PHY_BB_SVD_MEM0_SVD_MEM0_39_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_39_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_39_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_39_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_39_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_39_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_39_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_39_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_39_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_39_RESET                                      0x0
#define PHY_BB_SVD_MEM0_39_ADDRESS                                             (0x149c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_39_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_39_RESET                                               0x0

// 0x14a0 (PHY_BB_SVD_MEM0_40)
#define PHY_BB_SVD_MEM0_SVD_MEM0_40_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_40_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_40_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_40_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_40_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_40_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_40_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_40_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_40_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_40_RESET                                      0x0
#define PHY_BB_SVD_MEM0_40_ADDRESS                                             (0x14a0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_40_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_40_RESET                                               0x0

// 0x14a4 (PHY_BB_SVD_MEM0_41)
#define PHY_BB_SVD_MEM0_SVD_MEM0_41_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_41_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_41_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_41_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_41_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_41_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_41_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_41_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_41_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_41_RESET                                      0x0
#define PHY_BB_SVD_MEM0_41_ADDRESS                                             (0x14a4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_41_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_41_RESET                                               0x0

// 0x14a8 (PHY_BB_SVD_MEM0_42)
#define PHY_BB_SVD_MEM0_SVD_MEM0_42_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_42_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_42_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_42_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_42_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_42_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_42_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_42_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_42_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_42_RESET                                      0x0
#define PHY_BB_SVD_MEM0_42_ADDRESS                                             (0x14a8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_42_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_42_RESET                                               0x0

// 0x14ac (PHY_BB_SVD_MEM0_43)
#define PHY_BB_SVD_MEM0_SVD_MEM0_43_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_43_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_43_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_43_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_43_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_43_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_43_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_43_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_43_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_43_RESET                                      0x0
#define PHY_BB_SVD_MEM0_43_ADDRESS                                             (0x14ac + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_43_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_43_RESET                                               0x0

// 0x14b0 (PHY_BB_SVD_MEM0_44)
#define PHY_BB_SVD_MEM0_SVD_MEM0_44_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_44_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_44_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_44_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_44_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_44_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_44_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_44_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_44_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_44_RESET                                      0x0
#define PHY_BB_SVD_MEM0_44_ADDRESS                                             (0x14b0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_44_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_44_RESET                                               0x0

// 0x14b4 (PHY_BB_SVD_MEM0_45)
#define PHY_BB_SVD_MEM0_SVD_MEM0_45_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_45_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_45_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_45_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_45_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_45_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_45_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_45_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_45_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_45_RESET                                      0x0
#define PHY_BB_SVD_MEM0_45_ADDRESS                                             (0x14b4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_45_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_45_RESET                                               0x0

// 0x14b8 (PHY_BB_SVD_MEM0_46)
#define PHY_BB_SVD_MEM0_SVD_MEM0_46_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_46_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_46_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_46_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_46_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_46_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_46_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_46_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_46_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_46_RESET                                      0x0
#define PHY_BB_SVD_MEM0_46_ADDRESS                                             (0x14b8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_46_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_46_RESET                                               0x0

// 0x14bc (PHY_BB_SVD_MEM0_47)
#define PHY_BB_SVD_MEM0_SVD_MEM0_47_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_47_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_47_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_47_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_47_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_47_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_47_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_47_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_47_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_47_RESET                                      0x0
#define PHY_BB_SVD_MEM0_47_ADDRESS                                             (0x14bc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_47_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_47_RESET                                               0x0

// 0x14c0 (PHY_BB_SVD_MEM0_48)
#define PHY_BB_SVD_MEM0_SVD_MEM0_48_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_48_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_48_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_48_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_48_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_48_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_48_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_48_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_48_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_48_RESET                                      0x0
#define PHY_BB_SVD_MEM0_48_ADDRESS                                             (0x14c0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_48_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_48_RESET                                               0x0

// 0x14c4 (PHY_BB_SVD_MEM0_49)
#define PHY_BB_SVD_MEM0_SVD_MEM0_49_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_49_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_49_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_49_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_49_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_49_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_49_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_49_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_49_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_49_RESET                                      0x0
#define PHY_BB_SVD_MEM0_49_ADDRESS                                             (0x14c4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_49_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_49_RESET                                               0x0

// 0x14c8 (PHY_BB_SVD_MEM0_50)
#define PHY_BB_SVD_MEM0_SVD_MEM0_50_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_50_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_50_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_50_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_50_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_50_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_50_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_50_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_50_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_50_RESET                                      0x0
#define PHY_BB_SVD_MEM0_50_ADDRESS                                             (0x14c8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_50_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_50_RESET                                               0x0

// 0x14cc (PHY_BB_SVD_MEM0_51)
#define PHY_BB_SVD_MEM0_SVD_MEM0_51_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_51_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_51_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_51_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_51_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_51_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_51_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_51_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_51_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_51_RESET                                      0x0
#define PHY_BB_SVD_MEM0_51_ADDRESS                                             (0x14cc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_51_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_51_RESET                                               0x0

// 0x14d0 (PHY_BB_SVD_MEM0_52)
#define PHY_BB_SVD_MEM0_SVD_MEM0_52_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_52_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_52_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_52_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_52_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_52_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_52_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_52_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_52_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_52_RESET                                      0x0
#define PHY_BB_SVD_MEM0_52_ADDRESS                                             (0x14d0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_52_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_52_RESET                                               0x0

// 0x14d4 (PHY_BB_SVD_MEM0_53)
#define PHY_BB_SVD_MEM0_SVD_MEM0_53_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_53_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_53_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_53_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_53_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_53_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_53_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_53_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_53_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_53_RESET                                      0x0
#define PHY_BB_SVD_MEM0_53_ADDRESS                                             (0x14d4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_53_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_53_RESET                                               0x0

// 0x14d8 (PHY_BB_SVD_MEM0_54)
#define PHY_BB_SVD_MEM0_SVD_MEM0_54_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_54_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_54_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_54_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_54_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_54_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_54_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_54_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_54_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_54_RESET                                      0x0
#define PHY_BB_SVD_MEM0_54_ADDRESS                                             (0x14d8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_54_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_54_RESET                                               0x0

// 0x14dc (PHY_BB_SVD_MEM0_55)
#define PHY_BB_SVD_MEM0_SVD_MEM0_55_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_55_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_55_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_55_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_55_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_55_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_55_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_55_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_55_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_55_RESET                                      0x0
#define PHY_BB_SVD_MEM0_55_ADDRESS                                             (0x14dc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_55_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_55_RESET                                               0x0

// 0x14e0 (PHY_BB_SVD_MEM0_56)
#define PHY_BB_SVD_MEM0_SVD_MEM0_56_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_56_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_56_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_56_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_56_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_56_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_56_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_56_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_56_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_56_RESET                                      0x0
#define PHY_BB_SVD_MEM0_56_ADDRESS                                             (0x14e0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_56_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_56_RESET                                               0x0

// 0x14e4 (PHY_BB_SVD_MEM0_57)
#define PHY_BB_SVD_MEM0_SVD_MEM0_57_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_57_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_57_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_57_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_57_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_57_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_57_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_57_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_57_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_57_RESET                                      0x0
#define PHY_BB_SVD_MEM0_57_ADDRESS                                             (0x14e4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_57_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_57_RESET                                               0x0

// 0x14e8 (PHY_BB_SVD_MEM0_58)
#define PHY_BB_SVD_MEM0_SVD_MEM0_58_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_58_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_58_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_58_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_58_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_58_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_58_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_58_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_58_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_58_RESET                                      0x0
#define PHY_BB_SVD_MEM0_58_ADDRESS                                             (0x14e8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_58_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_58_RESET                                               0x0

// 0x14ec (PHY_BB_SVD_MEM0_59)
#define PHY_BB_SVD_MEM0_SVD_MEM0_59_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_59_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_59_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_59_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_59_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_59_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_59_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_59_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_59_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_59_RESET                                      0x0
#define PHY_BB_SVD_MEM0_59_ADDRESS                                             (0x14ec + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_59_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_59_RESET                                               0x0

// 0x14f0 (PHY_BB_SVD_MEM0_60)
#define PHY_BB_SVD_MEM0_SVD_MEM0_60_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_60_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_60_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_60_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_60_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_60_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_60_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_60_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_60_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_60_RESET                                      0x0
#define PHY_BB_SVD_MEM0_60_ADDRESS                                             (0x14f0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_60_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_60_RESET                                               0x0

// 0x14f4 (PHY_BB_SVD_MEM0_61)
#define PHY_BB_SVD_MEM0_SVD_MEM0_61_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_61_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_61_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_61_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_61_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_61_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_61_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_61_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_61_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_61_RESET                                      0x0
#define PHY_BB_SVD_MEM0_61_ADDRESS                                             (0x14f4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_61_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_61_RESET                                               0x0

// 0x14f8 (PHY_BB_SVD_MEM0_62)
#define PHY_BB_SVD_MEM0_SVD_MEM0_62_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_62_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_62_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_62_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_62_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_62_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_62_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_62_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_62_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_62_RESET                                      0x0
#define PHY_BB_SVD_MEM0_62_ADDRESS                                             (0x14f8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_62_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_62_RESET                                               0x0

// 0x14fc (PHY_BB_SVD_MEM0_63)
#define PHY_BB_SVD_MEM0_SVD_MEM0_63_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_63_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_63_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_63_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_63_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_63_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_63_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_63_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_63_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_63_RESET                                      0x0
#define PHY_BB_SVD_MEM0_63_ADDRESS                                             (0x14fc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_63_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_63_RESET                                               0x0

// 0x1500 (PHY_BB_SVD_MEM0_64)
#define PHY_BB_SVD_MEM0_SVD_MEM0_64_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_64_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_64_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_64_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_64_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_64_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_64_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_64_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_64_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_64_RESET                                      0x0
#define PHY_BB_SVD_MEM0_64_ADDRESS                                             (0x1500 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_64_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_64_RESET                                               0x0

// 0x1504 (PHY_BB_SVD_MEM0_65)
#define PHY_BB_SVD_MEM0_SVD_MEM0_65_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_65_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_65_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_65_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_65_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_65_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_65_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_65_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_65_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_65_RESET                                      0x0
#define PHY_BB_SVD_MEM0_65_ADDRESS                                             (0x1504 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_65_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_65_RESET                                               0x0

// 0x1508 (PHY_BB_SVD_MEM0_66)
#define PHY_BB_SVD_MEM0_SVD_MEM0_66_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_66_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_66_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_66_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_66_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_66_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_66_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_66_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_66_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_66_RESET                                      0x0
#define PHY_BB_SVD_MEM0_66_ADDRESS                                             (0x1508 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_66_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_66_RESET                                               0x0

// 0x150c (PHY_BB_SVD_MEM0_67)
#define PHY_BB_SVD_MEM0_SVD_MEM0_67_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_67_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_67_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_67_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_67_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_67_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_67_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_67_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_67_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_67_RESET                                      0x0
#define PHY_BB_SVD_MEM0_67_ADDRESS                                             (0x150c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_67_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_67_RESET                                               0x0

// 0x1510 (PHY_BB_SVD_MEM0_68)
#define PHY_BB_SVD_MEM0_SVD_MEM0_68_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_68_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_68_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_68_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_68_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_68_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_68_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_68_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_68_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_68_RESET                                      0x0
#define PHY_BB_SVD_MEM0_68_ADDRESS                                             (0x1510 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_68_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_68_RESET                                               0x0

// 0x1514 (PHY_BB_SVD_MEM0_69)
#define PHY_BB_SVD_MEM0_SVD_MEM0_69_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_69_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_69_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_69_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_69_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_69_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_69_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_69_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_69_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_69_RESET                                      0x0
#define PHY_BB_SVD_MEM0_69_ADDRESS                                             (0x1514 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_69_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_69_RESET                                               0x0

// 0x1518 (PHY_BB_SVD_MEM0_70)
#define PHY_BB_SVD_MEM0_SVD_MEM0_70_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_70_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_70_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_70_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_70_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_70_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_70_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_70_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_70_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_70_RESET                                      0x0
#define PHY_BB_SVD_MEM0_70_ADDRESS                                             (0x1518 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_70_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_70_RESET                                               0x0

// 0x151c (PHY_BB_SVD_MEM0_71)
#define PHY_BB_SVD_MEM0_SVD_MEM0_71_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_71_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_71_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_71_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_71_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_71_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_71_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_71_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_71_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_71_RESET                                      0x0
#define PHY_BB_SVD_MEM0_71_ADDRESS                                             (0x151c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_71_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_71_RESET                                               0x0

// 0x1520 (PHY_BB_SVD_MEM0_72)
#define PHY_BB_SVD_MEM0_SVD_MEM0_72_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_72_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_72_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_72_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_72_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_72_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_72_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_72_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_72_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_72_RESET                                      0x0
#define PHY_BB_SVD_MEM0_72_ADDRESS                                             (0x1520 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_72_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_72_RESET                                               0x0

// 0x1524 (PHY_BB_SVD_MEM0_73)
#define PHY_BB_SVD_MEM0_SVD_MEM0_73_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_73_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_73_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_73_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_73_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_73_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_73_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_73_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_73_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_73_RESET                                      0x0
#define PHY_BB_SVD_MEM0_73_ADDRESS                                             (0x1524 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_73_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_73_RESET                                               0x0

// 0x1528 (PHY_BB_SVD_MEM0_74)
#define PHY_BB_SVD_MEM0_SVD_MEM0_74_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_74_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_74_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_74_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_74_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_74_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_74_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_74_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_74_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_74_RESET                                      0x0
#define PHY_BB_SVD_MEM0_74_ADDRESS                                             (0x1528 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_74_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_74_RESET                                               0x0

// 0x152c (PHY_BB_SVD_MEM0_75)
#define PHY_BB_SVD_MEM0_SVD_MEM0_75_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_75_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_75_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_75_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_75_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_75_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_75_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_75_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_75_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_75_RESET                                      0x0
#define PHY_BB_SVD_MEM0_75_ADDRESS                                             (0x152c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_75_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_75_RESET                                               0x0

// 0x1530 (PHY_BB_SVD_MEM0_76)
#define PHY_BB_SVD_MEM0_SVD_MEM0_76_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_76_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_76_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_76_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_76_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_76_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_76_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_76_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_76_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_76_RESET                                      0x0
#define PHY_BB_SVD_MEM0_76_ADDRESS                                             (0x1530 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_76_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_76_RESET                                               0x0

// 0x1534 (PHY_BB_SVD_MEM0_77)
#define PHY_BB_SVD_MEM0_SVD_MEM0_77_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_77_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_77_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_77_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_77_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_77_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_77_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_77_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_77_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_77_RESET                                      0x0
#define PHY_BB_SVD_MEM0_77_ADDRESS                                             (0x1534 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_77_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_77_RESET                                               0x0

// 0x1538 (PHY_BB_SVD_MEM0_78)
#define PHY_BB_SVD_MEM0_SVD_MEM0_78_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_78_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_78_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_78_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_78_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_78_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_78_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_78_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_78_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_78_RESET                                      0x0
#define PHY_BB_SVD_MEM0_78_ADDRESS                                             (0x1538 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_78_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_78_RESET                                               0x0

// 0x153c (PHY_BB_SVD_MEM0_79)
#define PHY_BB_SVD_MEM0_SVD_MEM0_79_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_79_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_79_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_79_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_79_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_79_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_79_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_79_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_79_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_79_RESET                                      0x0
#define PHY_BB_SVD_MEM0_79_ADDRESS                                             (0x153c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_79_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_79_RESET                                               0x0

// 0x1540 (PHY_BB_SVD_MEM0_80)
#define PHY_BB_SVD_MEM0_SVD_MEM0_80_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_80_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_80_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_80_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_80_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_80_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_80_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_80_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_80_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_80_RESET                                      0x0
#define PHY_BB_SVD_MEM0_80_ADDRESS                                             (0x1540 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_80_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_80_RESET                                               0x0

// 0x1544 (PHY_BB_SVD_MEM0_81)
#define PHY_BB_SVD_MEM0_SVD_MEM0_81_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_81_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_81_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_81_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_81_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_81_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_81_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_81_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_81_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_81_RESET                                      0x0
#define PHY_BB_SVD_MEM0_81_ADDRESS                                             (0x1544 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_81_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_81_RESET                                               0x0

// 0x1548 (PHY_BB_SVD_MEM0_82)
#define PHY_BB_SVD_MEM0_SVD_MEM0_82_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_82_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_82_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_82_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_82_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_82_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_82_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_82_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_82_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_82_RESET                                      0x0
#define PHY_BB_SVD_MEM0_82_ADDRESS                                             (0x1548 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_82_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_82_RESET                                               0x0

// 0x154c (PHY_BB_SVD_MEM0_83)
#define PHY_BB_SVD_MEM0_SVD_MEM0_83_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_83_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_83_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_83_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_83_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_83_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_83_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_83_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_83_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_83_RESET                                      0x0
#define PHY_BB_SVD_MEM0_83_ADDRESS                                             (0x154c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_83_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_83_RESET                                               0x0

// 0x1550 (PHY_BB_SVD_MEM0_84)
#define PHY_BB_SVD_MEM0_SVD_MEM0_84_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_84_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_84_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_84_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_84_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_84_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_84_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_84_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_84_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_84_RESET                                      0x0
#define PHY_BB_SVD_MEM0_84_ADDRESS                                             (0x1550 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_84_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_84_RESET                                               0x0

// 0x1554 (PHY_BB_SVD_MEM0_85)
#define PHY_BB_SVD_MEM0_SVD_MEM0_85_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_85_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_85_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_85_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_85_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_85_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_85_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_85_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_85_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_85_RESET                                      0x0
#define PHY_BB_SVD_MEM0_85_ADDRESS                                             (0x1554 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_85_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_85_RESET                                               0x0

// 0x1558 (PHY_BB_SVD_MEM0_86)
#define PHY_BB_SVD_MEM0_SVD_MEM0_86_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_86_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_86_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_86_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_86_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_86_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_86_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_86_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_86_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_86_RESET                                      0x0
#define PHY_BB_SVD_MEM0_86_ADDRESS                                             (0x1558 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_86_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_86_RESET                                               0x0

// 0x155c (PHY_BB_SVD_MEM0_87)
#define PHY_BB_SVD_MEM0_SVD_MEM0_87_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_87_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_87_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_87_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_87_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_87_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_87_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_87_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_87_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_87_RESET                                      0x0
#define PHY_BB_SVD_MEM0_87_ADDRESS                                             (0x155c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_87_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_87_RESET                                               0x0

// 0x1560 (PHY_BB_SVD_MEM0_88)
#define PHY_BB_SVD_MEM0_SVD_MEM0_88_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_88_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_88_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_88_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_88_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_88_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_88_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_88_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_88_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_88_RESET                                      0x0
#define PHY_BB_SVD_MEM0_88_ADDRESS                                             (0x1560 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_88_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_88_RESET                                               0x0

// 0x1564 (PHY_BB_SVD_MEM0_89)
#define PHY_BB_SVD_MEM0_SVD_MEM0_89_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_89_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_89_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_89_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_89_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_89_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_89_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_89_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_89_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_89_RESET                                      0x0
#define PHY_BB_SVD_MEM0_89_ADDRESS                                             (0x1564 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_89_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_89_RESET                                               0x0

// 0x1568 (PHY_BB_SVD_MEM0_90)
#define PHY_BB_SVD_MEM0_SVD_MEM0_90_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_90_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_90_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_90_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_90_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_90_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_90_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_90_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_90_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_90_RESET                                      0x0
#define PHY_BB_SVD_MEM0_90_ADDRESS                                             (0x1568 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_90_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_90_RESET                                               0x0

// 0x156c (PHY_BB_SVD_MEM0_91)
#define PHY_BB_SVD_MEM0_SVD_MEM0_91_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_91_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_91_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_91_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_91_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_91_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_91_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_91_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_91_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_91_RESET                                      0x0
#define PHY_BB_SVD_MEM0_91_ADDRESS                                             (0x156c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_91_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_91_RESET                                               0x0

// 0x1570 (PHY_BB_SVD_MEM0_92)
#define PHY_BB_SVD_MEM0_SVD_MEM0_92_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_92_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_92_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_92_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_92_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_92_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_92_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_92_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_92_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_92_RESET                                      0x0
#define PHY_BB_SVD_MEM0_92_ADDRESS                                             (0x1570 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_92_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_92_RESET                                               0x0

// 0x1574 (PHY_BB_SVD_MEM0_93)
#define PHY_BB_SVD_MEM0_SVD_MEM0_93_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_93_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_93_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_93_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_93_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_93_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_93_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_93_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_93_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_93_RESET                                      0x0
#define PHY_BB_SVD_MEM0_93_ADDRESS                                             (0x1574 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_93_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_93_RESET                                               0x0

// 0x1578 (PHY_BB_SVD_MEM0_94)
#define PHY_BB_SVD_MEM0_SVD_MEM0_94_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_94_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_94_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_94_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_94_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_94_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_94_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_94_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_94_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_94_RESET                                      0x0
#define PHY_BB_SVD_MEM0_94_ADDRESS                                             (0x1578 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_94_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_94_RESET                                               0x0

// 0x157c (PHY_BB_SVD_MEM0_95)
#define PHY_BB_SVD_MEM0_SVD_MEM0_95_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_95_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_95_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_95_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_95_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_95_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_95_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_95_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_95_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_95_RESET                                      0x0
#define PHY_BB_SVD_MEM0_95_ADDRESS                                             (0x157c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_95_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_95_RESET                                               0x0

// 0x1580 (PHY_BB_SVD_MEM0_96)
#define PHY_BB_SVD_MEM0_SVD_MEM0_96_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_96_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_96_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_96_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_96_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_96_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_96_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_96_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_96_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_96_RESET                                      0x0
#define PHY_BB_SVD_MEM0_96_ADDRESS                                             (0x1580 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_96_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_96_RESET                                               0x0

// 0x1584 (PHY_BB_SVD_MEM0_97)
#define PHY_BB_SVD_MEM0_SVD_MEM0_97_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_97_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_97_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_97_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_97_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_97_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_97_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_97_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_97_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_97_RESET                                      0x0
#define PHY_BB_SVD_MEM0_97_ADDRESS                                             (0x1584 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_97_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_97_RESET                                               0x0

// 0x1588 (PHY_BB_SVD_MEM0_98)
#define PHY_BB_SVD_MEM0_SVD_MEM0_98_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_98_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_98_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_98_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_98_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_98_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_98_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_98_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_98_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_98_RESET                                      0x0
#define PHY_BB_SVD_MEM0_98_ADDRESS                                             (0x1588 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_98_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_98_RESET                                               0x0

// 0x158c (PHY_BB_SVD_MEM0_99)
#define PHY_BB_SVD_MEM0_SVD_MEM0_99_LSB                                        0
#define PHY_BB_SVD_MEM0_SVD_MEM0_99_MSB                                        31
#define PHY_BB_SVD_MEM0_SVD_MEM0_99_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_99_GET(x)                                     (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_99_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_99_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_99_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_99_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_99_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_99_RESET                                      0x0
#define PHY_BB_SVD_MEM0_99_ADDRESS                                             (0x158c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_99_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM0_99_RESET                                               0x0

// 0x1590 (PHY_BB_SVD_MEM0_100)
#define PHY_BB_SVD_MEM0_SVD_MEM0_100_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_100_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_100_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_100_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_100_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_100_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_100_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_100_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_100_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_100_RESET                                     0x0
#define PHY_BB_SVD_MEM0_100_ADDRESS                                            (0x1590 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_100_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_100_RESET                                              0x0

// 0x1594 (PHY_BB_SVD_MEM0_101)
#define PHY_BB_SVD_MEM0_SVD_MEM0_101_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_101_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_101_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_101_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_101_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_101_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_101_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_101_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_101_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_101_RESET                                     0x0
#define PHY_BB_SVD_MEM0_101_ADDRESS                                            (0x1594 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_101_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_101_RESET                                              0x0

// 0x1598 (PHY_BB_SVD_MEM0_102)
#define PHY_BB_SVD_MEM0_SVD_MEM0_102_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_102_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_102_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_102_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_102_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_102_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_102_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_102_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_102_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_102_RESET                                     0x0
#define PHY_BB_SVD_MEM0_102_ADDRESS                                            (0x1598 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_102_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_102_RESET                                              0x0

// 0x159c (PHY_BB_SVD_MEM0_103)
#define PHY_BB_SVD_MEM0_SVD_MEM0_103_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_103_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_103_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_103_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_103_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_103_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_103_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_103_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_103_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_103_RESET                                     0x0
#define PHY_BB_SVD_MEM0_103_ADDRESS                                            (0x159c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_103_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_103_RESET                                              0x0

// 0x15a0 (PHY_BB_SVD_MEM0_104)
#define PHY_BB_SVD_MEM0_SVD_MEM0_104_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_104_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_104_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_104_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_104_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_104_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_104_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_104_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_104_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_104_RESET                                     0x0
#define PHY_BB_SVD_MEM0_104_ADDRESS                                            (0x15a0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_104_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_104_RESET                                              0x0

// 0x15a4 (PHY_BB_SVD_MEM0_105)
#define PHY_BB_SVD_MEM0_SVD_MEM0_105_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_105_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_105_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_105_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_105_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_105_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_105_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_105_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_105_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_105_RESET                                     0x0
#define PHY_BB_SVD_MEM0_105_ADDRESS                                            (0x15a4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_105_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_105_RESET                                              0x0

// 0x15a8 (PHY_BB_SVD_MEM0_106)
#define PHY_BB_SVD_MEM0_SVD_MEM0_106_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_106_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_106_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_106_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_106_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_106_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_106_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_106_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_106_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_106_RESET                                     0x0
#define PHY_BB_SVD_MEM0_106_ADDRESS                                            (0x15a8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_106_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_106_RESET                                              0x0

// 0x15ac (PHY_BB_SVD_MEM0_107)
#define PHY_BB_SVD_MEM0_SVD_MEM0_107_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_107_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_107_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_107_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_107_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_107_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_107_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_107_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_107_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_107_RESET                                     0x0
#define PHY_BB_SVD_MEM0_107_ADDRESS                                            (0x15ac + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_107_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_107_RESET                                              0x0

// 0x15b0 (PHY_BB_SVD_MEM0_108)
#define PHY_BB_SVD_MEM0_SVD_MEM0_108_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_108_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_108_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_108_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_108_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_108_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_108_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_108_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_108_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_108_RESET                                     0x0
#define PHY_BB_SVD_MEM0_108_ADDRESS                                            (0x15b0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_108_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_108_RESET                                              0x0

// 0x15b4 (PHY_BB_SVD_MEM0_109)
#define PHY_BB_SVD_MEM0_SVD_MEM0_109_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_109_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_109_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_109_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_109_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_109_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_109_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_109_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_109_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_109_RESET                                     0x0
#define PHY_BB_SVD_MEM0_109_ADDRESS                                            (0x15b4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_109_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_109_RESET                                              0x0

// 0x15b8 (PHY_BB_SVD_MEM0_110)
#define PHY_BB_SVD_MEM0_SVD_MEM0_110_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_110_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_110_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_110_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_110_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_110_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_110_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_110_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_110_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_110_RESET                                     0x0
#define PHY_BB_SVD_MEM0_110_ADDRESS                                            (0x15b8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_110_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_110_RESET                                              0x0

// 0x15bc (PHY_BB_SVD_MEM0_111)
#define PHY_BB_SVD_MEM0_SVD_MEM0_111_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_111_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_111_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_111_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_111_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_111_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_111_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_111_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_111_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_111_RESET                                     0x0
#define PHY_BB_SVD_MEM0_111_ADDRESS                                            (0x15bc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_111_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_111_RESET                                              0x0

// 0x15c0 (PHY_BB_SVD_MEM0_112)
#define PHY_BB_SVD_MEM0_SVD_MEM0_112_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_112_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_112_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_112_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_112_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_112_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_112_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_112_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_112_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_112_RESET                                     0x0
#define PHY_BB_SVD_MEM0_112_ADDRESS                                            (0x15c0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_112_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_112_RESET                                              0x0

// 0x15c4 (PHY_BB_SVD_MEM0_113)
#define PHY_BB_SVD_MEM0_SVD_MEM0_113_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_113_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_113_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_113_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_113_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_113_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_113_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_113_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_113_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_113_RESET                                     0x0
#define PHY_BB_SVD_MEM0_113_ADDRESS                                            (0x15c4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_113_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_113_RESET                                              0x0

// 0x15c8 (PHY_BB_SVD_MEM0_114)
#define PHY_BB_SVD_MEM0_SVD_MEM0_114_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_114_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_114_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_114_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_114_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_114_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_114_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_114_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_114_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_114_RESET                                     0x0
#define PHY_BB_SVD_MEM0_114_ADDRESS                                            (0x15c8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_114_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_114_RESET                                              0x0

// 0x15cc (PHY_BB_SVD_MEM0_115)
#define PHY_BB_SVD_MEM0_SVD_MEM0_115_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_115_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_115_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_115_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_115_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_115_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_115_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_115_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_115_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_115_RESET                                     0x0
#define PHY_BB_SVD_MEM0_115_ADDRESS                                            (0x15cc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_115_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_115_RESET                                              0x0

// 0x15d0 (PHY_BB_SVD_MEM0_116)
#define PHY_BB_SVD_MEM0_SVD_MEM0_116_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_116_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_116_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_116_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_116_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_116_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_116_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_116_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_116_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_116_RESET                                     0x0
#define PHY_BB_SVD_MEM0_116_ADDRESS                                            (0x15d0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_116_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_116_RESET                                              0x0

// 0x15d4 (PHY_BB_SVD_MEM0_117)
#define PHY_BB_SVD_MEM0_SVD_MEM0_117_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_117_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_117_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_117_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_117_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_117_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_117_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_117_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_117_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_117_RESET                                     0x0
#define PHY_BB_SVD_MEM0_117_ADDRESS                                            (0x15d4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_117_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_117_RESET                                              0x0

// 0x15d8 (PHY_BB_SVD_MEM0_118)
#define PHY_BB_SVD_MEM0_SVD_MEM0_118_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_118_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_118_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_118_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_118_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_118_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_118_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_118_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_118_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_118_RESET                                     0x0
#define PHY_BB_SVD_MEM0_118_ADDRESS                                            (0x15d8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_118_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_118_RESET                                              0x0

// 0x15dc (PHY_BB_SVD_MEM0_119)
#define PHY_BB_SVD_MEM0_SVD_MEM0_119_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_119_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_119_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_119_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_119_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_119_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_119_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_119_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_119_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_119_RESET                                     0x0
#define PHY_BB_SVD_MEM0_119_ADDRESS                                            (0x15dc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_119_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_119_RESET                                              0x0

// 0x15e0 (PHY_BB_SVD_MEM0_120)
#define PHY_BB_SVD_MEM0_SVD_MEM0_120_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_120_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_120_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_120_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_120_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_120_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_120_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_120_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_120_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_120_RESET                                     0x0
#define PHY_BB_SVD_MEM0_120_ADDRESS                                            (0x15e0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_120_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_120_RESET                                              0x0

// 0x15e4 (PHY_BB_SVD_MEM0_121)
#define PHY_BB_SVD_MEM0_SVD_MEM0_121_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_121_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_121_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_121_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_121_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_121_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_121_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_121_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_121_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_121_RESET                                     0x0
#define PHY_BB_SVD_MEM0_121_ADDRESS                                            (0x15e4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_121_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_121_RESET                                              0x0

// 0x15e8 (PHY_BB_SVD_MEM0_122)
#define PHY_BB_SVD_MEM0_SVD_MEM0_122_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_122_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_122_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_122_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_122_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_122_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_122_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_122_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_122_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_122_RESET                                     0x0
#define PHY_BB_SVD_MEM0_122_ADDRESS                                            (0x15e8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_122_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_122_RESET                                              0x0

// 0x15ec (PHY_BB_SVD_MEM0_123)
#define PHY_BB_SVD_MEM0_SVD_MEM0_123_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_123_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_123_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_123_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_123_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_123_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_123_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_123_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_123_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_123_RESET                                     0x0
#define PHY_BB_SVD_MEM0_123_ADDRESS                                            (0x15ec + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_123_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_123_RESET                                              0x0

// 0x15f0 (PHY_BB_SVD_MEM0_124)
#define PHY_BB_SVD_MEM0_SVD_MEM0_124_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_124_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_124_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_124_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_124_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_124_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_124_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_124_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_124_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_124_RESET                                     0x0
#define PHY_BB_SVD_MEM0_124_ADDRESS                                            (0x15f0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_124_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_124_RESET                                              0x0

// 0x15f4 (PHY_BB_SVD_MEM0_125)
#define PHY_BB_SVD_MEM0_SVD_MEM0_125_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_125_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_125_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_125_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_125_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_125_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_125_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_125_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_125_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_125_RESET                                     0x0
#define PHY_BB_SVD_MEM0_125_ADDRESS                                            (0x15f4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_125_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_125_RESET                                              0x0

// 0x15f8 (PHY_BB_SVD_MEM0_126)
#define PHY_BB_SVD_MEM0_SVD_MEM0_126_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_126_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_126_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_126_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_126_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_126_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_126_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_126_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_126_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_126_RESET                                     0x0
#define PHY_BB_SVD_MEM0_126_ADDRESS                                            (0x15f8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_126_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_126_RESET                                              0x0

// 0x15fc (PHY_BB_SVD_MEM0_127)
#define PHY_BB_SVD_MEM0_SVD_MEM0_127_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_127_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_127_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_127_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_127_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_127_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_127_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_127_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_127_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_127_RESET                                     0x0
#define PHY_BB_SVD_MEM0_127_ADDRESS                                            (0x15fc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_127_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_127_RESET                                              0x0

// 0x1600 (PHY_BB_SVD_MEM0_128)
#define PHY_BB_SVD_MEM0_SVD_MEM0_128_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_128_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_128_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_128_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_128_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_128_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_128_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_128_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_128_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_128_RESET                                     0x0
#define PHY_BB_SVD_MEM0_128_ADDRESS                                            (0x1600 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_128_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_128_RESET                                              0x0

// 0x1604 (PHY_BB_SVD_MEM0_129)
#define PHY_BB_SVD_MEM0_SVD_MEM0_129_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_129_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_129_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_129_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_129_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_129_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_129_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_129_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_129_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_129_RESET                                     0x0
#define PHY_BB_SVD_MEM0_129_ADDRESS                                            (0x1604 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_129_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_129_RESET                                              0x0

// 0x1608 (PHY_BB_SVD_MEM0_130)
#define PHY_BB_SVD_MEM0_SVD_MEM0_130_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_130_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_130_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_130_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_130_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_130_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_130_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_130_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_130_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_130_RESET                                     0x0
#define PHY_BB_SVD_MEM0_130_ADDRESS                                            (0x1608 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_130_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_130_RESET                                              0x0

// 0x160c (PHY_BB_SVD_MEM0_131)
#define PHY_BB_SVD_MEM0_SVD_MEM0_131_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_131_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_131_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_131_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_131_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_131_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_131_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_131_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_131_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_131_RESET                                     0x0
#define PHY_BB_SVD_MEM0_131_ADDRESS                                            (0x160c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_131_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_131_RESET                                              0x0

// 0x1610 (PHY_BB_SVD_MEM0_132)
#define PHY_BB_SVD_MEM0_SVD_MEM0_132_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_132_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_132_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_132_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_132_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_132_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_132_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_132_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_132_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_132_RESET                                     0x0
#define PHY_BB_SVD_MEM0_132_ADDRESS                                            (0x1610 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_132_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_132_RESET                                              0x0

// 0x1614 (PHY_BB_SVD_MEM0_133)
#define PHY_BB_SVD_MEM0_SVD_MEM0_133_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_133_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_133_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_133_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_133_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_133_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_133_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_133_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_133_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_133_RESET                                     0x0
#define PHY_BB_SVD_MEM0_133_ADDRESS                                            (0x1614 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_133_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_133_RESET                                              0x0

// 0x1618 (PHY_BB_SVD_MEM0_134)
#define PHY_BB_SVD_MEM0_SVD_MEM0_134_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_134_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_134_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_134_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_134_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_134_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_134_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_134_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_134_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_134_RESET                                     0x0
#define PHY_BB_SVD_MEM0_134_ADDRESS                                            (0x1618 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_134_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_134_RESET                                              0x0

// 0x161c (PHY_BB_SVD_MEM0_135)
#define PHY_BB_SVD_MEM0_SVD_MEM0_135_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_135_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_135_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_135_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_135_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_135_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_135_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_135_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_135_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_135_RESET                                     0x0
#define PHY_BB_SVD_MEM0_135_ADDRESS                                            (0x161c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_135_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_135_RESET                                              0x0

// 0x1620 (PHY_BB_SVD_MEM0_136)
#define PHY_BB_SVD_MEM0_SVD_MEM0_136_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_136_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_136_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_136_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_136_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_136_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_136_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_136_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_136_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_136_RESET                                     0x0
#define PHY_BB_SVD_MEM0_136_ADDRESS                                            (0x1620 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_136_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_136_RESET                                              0x0

// 0x1624 (PHY_BB_SVD_MEM0_137)
#define PHY_BB_SVD_MEM0_SVD_MEM0_137_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_137_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_137_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_137_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_137_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_137_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_137_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_137_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_137_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_137_RESET                                     0x0
#define PHY_BB_SVD_MEM0_137_ADDRESS                                            (0x1624 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_137_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_137_RESET                                              0x0

// 0x1628 (PHY_BB_SVD_MEM0_138)
#define PHY_BB_SVD_MEM0_SVD_MEM0_138_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_138_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_138_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_138_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_138_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_138_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_138_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_138_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_138_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_138_RESET                                     0x0
#define PHY_BB_SVD_MEM0_138_ADDRESS                                            (0x1628 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_138_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_138_RESET                                              0x0

// 0x162c (PHY_BB_SVD_MEM0_139)
#define PHY_BB_SVD_MEM0_SVD_MEM0_139_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_139_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_139_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_139_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_139_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_139_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_139_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_139_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_139_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_139_RESET                                     0x0
#define PHY_BB_SVD_MEM0_139_ADDRESS                                            (0x162c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_139_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_139_RESET                                              0x0

// 0x1630 (PHY_BB_SVD_MEM0_140)
#define PHY_BB_SVD_MEM0_SVD_MEM0_140_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_140_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_140_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_140_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_140_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_140_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_140_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_140_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_140_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_140_RESET                                     0x0
#define PHY_BB_SVD_MEM0_140_ADDRESS                                            (0x1630 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_140_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_140_RESET                                              0x0

// 0x1634 (PHY_BB_SVD_MEM0_141)
#define PHY_BB_SVD_MEM0_SVD_MEM0_141_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_141_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_141_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_141_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_141_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_141_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_141_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_141_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_141_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_141_RESET                                     0x0
#define PHY_BB_SVD_MEM0_141_ADDRESS                                            (0x1634 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_141_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_141_RESET                                              0x0

// 0x1638 (PHY_BB_SVD_MEM0_142)
#define PHY_BB_SVD_MEM0_SVD_MEM0_142_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_142_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_142_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_142_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_142_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_142_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_142_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_142_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_142_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_142_RESET                                     0x0
#define PHY_BB_SVD_MEM0_142_ADDRESS                                            (0x1638 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_142_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_142_RESET                                              0x0

// 0x163c (PHY_BB_SVD_MEM0_143)
#define PHY_BB_SVD_MEM0_SVD_MEM0_143_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_143_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_143_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_143_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_143_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_143_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_143_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_143_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_143_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_143_RESET                                     0x0
#define PHY_BB_SVD_MEM0_143_ADDRESS                                            (0x163c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_143_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_143_RESET                                              0x0

// 0x1640 (PHY_BB_SVD_MEM0_144)
#define PHY_BB_SVD_MEM0_SVD_MEM0_144_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_144_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_144_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_144_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_144_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_144_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_144_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_144_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_144_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_144_RESET                                     0x0
#define PHY_BB_SVD_MEM0_144_ADDRESS                                            (0x1640 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_144_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_144_RESET                                              0x0

// 0x1644 (PHY_BB_SVD_MEM0_145)
#define PHY_BB_SVD_MEM0_SVD_MEM0_145_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_145_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_145_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_145_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_145_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_145_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_145_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_145_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_145_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_145_RESET                                     0x0
#define PHY_BB_SVD_MEM0_145_ADDRESS                                            (0x1644 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_145_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_145_RESET                                              0x0

// 0x1648 (PHY_BB_SVD_MEM0_146)
#define PHY_BB_SVD_MEM0_SVD_MEM0_146_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_146_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_146_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_146_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_146_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_146_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_146_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_146_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_146_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_146_RESET                                     0x0
#define PHY_BB_SVD_MEM0_146_ADDRESS                                            (0x1648 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_146_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_146_RESET                                              0x0

// 0x164c (PHY_BB_SVD_MEM0_147)
#define PHY_BB_SVD_MEM0_SVD_MEM0_147_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_147_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_147_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_147_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_147_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_147_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_147_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_147_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_147_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_147_RESET                                     0x0
#define PHY_BB_SVD_MEM0_147_ADDRESS                                            (0x164c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_147_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_147_RESET                                              0x0

// 0x1650 (PHY_BB_SVD_MEM0_148)
#define PHY_BB_SVD_MEM0_SVD_MEM0_148_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_148_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_148_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_148_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_148_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_148_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_148_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_148_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_148_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_148_RESET                                     0x0
#define PHY_BB_SVD_MEM0_148_ADDRESS                                            (0x1650 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_148_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_148_RESET                                              0x0

// 0x1654 (PHY_BB_SVD_MEM0_149)
#define PHY_BB_SVD_MEM0_SVD_MEM0_149_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_149_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_149_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_149_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_149_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_149_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_149_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_149_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_149_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_149_RESET                                     0x0
#define PHY_BB_SVD_MEM0_149_ADDRESS                                            (0x1654 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_149_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_149_RESET                                              0x0

// 0x1658 (PHY_BB_SVD_MEM0_150)
#define PHY_BB_SVD_MEM0_SVD_MEM0_150_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_150_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_150_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_150_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_150_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_150_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_150_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_150_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_150_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_150_RESET                                     0x0
#define PHY_BB_SVD_MEM0_150_ADDRESS                                            (0x1658 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_150_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_150_RESET                                              0x0

// 0x165c (PHY_BB_SVD_MEM0_151)
#define PHY_BB_SVD_MEM0_SVD_MEM0_151_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_151_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_151_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_151_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_151_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_151_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_151_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_151_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_151_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_151_RESET                                     0x0
#define PHY_BB_SVD_MEM0_151_ADDRESS                                            (0x165c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_151_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_151_RESET                                              0x0

// 0x1660 (PHY_BB_SVD_MEM0_152)
#define PHY_BB_SVD_MEM0_SVD_MEM0_152_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_152_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_152_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_152_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_152_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_152_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_152_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_152_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_152_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_152_RESET                                     0x0
#define PHY_BB_SVD_MEM0_152_ADDRESS                                            (0x1660 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_152_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_152_RESET                                              0x0

// 0x1664 (PHY_BB_SVD_MEM0_153)
#define PHY_BB_SVD_MEM0_SVD_MEM0_153_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_153_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_153_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_153_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_153_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_153_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_153_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_153_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_153_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_153_RESET                                     0x0
#define PHY_BB_SVD_MEM0_153_ADDRESS                                            (0x1664 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_153_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_153_RESET                                              0x0

// 0x1668 (PHY_BB_SVD_MEM0_154)
#define PHY_BB_SVD_MEM0_SVD_MEM0_154_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_154_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_154_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_154_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_154_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_154_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_154_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_154_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_154_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_154_RESET                                     0x0
#define PHY_BB_SVD_MEM0_154_ADDRESS                                            (0x1668 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_154_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_154_RESET                                              0x0

// 0x166c (PHY_BB_SVD_MEM0_155)
#define PHY_BB_SVD_MEM0_SVD_MEM0_155_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_155_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_155_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_155_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_155_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_155_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_155_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_155_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_155_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_155_RESET                                     0x0
#define PHY_BB_SVD_MEM0_155_ADDRESS                                            (0x166c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_155_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_155_RESET                                              0x0

// 0x1670 (PHY_BB_SVD_MEM0_156)
#define PHY_BB_SVD_MEM0_SVD_MEM0_156_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_156_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_156_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_156_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_156_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_156_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_156_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_156_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_156_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_156_RESET                                     0x0
#define PHY_BB_SVD_MEM0_156_ADDRESS                                            (0x1670 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_156_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_156_RESET                                              0x0

// 0x1674 (PHY_BB_SVD_MEM0_157)
#define PHY_BB_SVD_MEM0_SVD_MEM0_157_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_157_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_157_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_157_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_157_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_157_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_157_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_157_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_157_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_157_RESET                                     0x0
#define PHY_BB_SVD_MEM0_157_ADDRESS                                            (0x1674 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_157_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_157_RESET                                              0x0

// 0x1678 (PHY_BB_SVD_MEM0_158)
#define PHY_BB_SVD_MEM0_SVD_MEM0_158_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_158_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_158_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_158_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_158_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_158_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_158_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_158_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_158_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_158_RESET                                     0x0
#define PHY_BB_SVD_MEM0_158_ADDRESS                                            (0x1678 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_158_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_158_RESET                                              0x0

// 0x167c (PHY_BB_SVD_MEM0_159)
#define PHY_BB_SVD_MEM0_SVD_MEM0_159_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_159_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_159_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_159_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_159_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_159_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_159_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_159_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_159_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_159_RESET                                     0x0
#define PHY_BB_SVD_MEM0_159_ADDRESS                                            (0x167c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_159_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_159_RESET                                              0x0

// 0x1680 (PHY_BB_SVD_MEM0_160)
#define PHY_BB_SVD_MEM0_SVD_MEM0_160_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_160_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_160_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_160_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_160_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_160_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_160_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_160_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_160_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_160_RESET                                     0x0
#define PHY_BB_SVD_MEM0_160_ADDRESS                                            (0x1680 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_160_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_160_RESET                                              0x0

// 0x1684 (PHY_BB_SVD_MEM0_161)
#define PHY_BB_SVD_MEM0_SVD_MEM0_161_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_161_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_161_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_161_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_161_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_161_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_161_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_161_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_161_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_161_RESET                                     0x0
#define PHY_BB_SVD_MEM0_161_ADDRESS                                            (0x1684 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_161_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_161_RESET                                              0x0

// 0x1688 (PHY_BB_SVD_MEM0_162)
#define PHY_BB_SVD_MEM0_SVD_MEM0_162_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_162_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_162_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_162_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_162_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_162_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_162_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_162_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_162_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_162_RESET                                     0x0
#define PHY_BB_SVD_MEM0_162_ADDRESS                                            (0x1688 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_162_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_162_RESET                                              0x0

// 0x168c (PHY_BB_SVD_MEM0_163)
#define PHY_BB_SVD_MEM0_SVD_MEM0_163_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_163_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_163_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_163_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_163_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_163_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_163_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_163_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_163_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_163_RESET                                     0x0
#define PHY_BB_SVD_MEM0_163_ADDRESS                                            (0x168c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_163_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_163_RESET                                              0x0

// 0x1690 (PHY_BB_SVD_MEM0_164)
#define PHY_BB_SVD_MEM0_SVD_MEM0_164_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_164_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_164_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_164_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_164_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_164_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_164_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_164_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_164_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_164_RESET                                     0x0
#define PHY_BB_SVD_MEM0_164_ADDRESS                                            (0x1690 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_164_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_164_RESET                                              0x0

// 0x1694 (PHY_BB_SVD_MEM0_165)
#define PHY_BB_SVD_MEM0_SVD_MEM0_165_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_165_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_165_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_165_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_165_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_165_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_165_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_165_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_165_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_165_RESET                                     0x0
#define PHY_BB_SVD_MEM0_165_ADDRESS                                            (0x1694 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_165_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_165_RESET                                              0x0

// 0x1698 (PHY_BB_SVD_MEM0_166)
#define PHY_BB_SVD_MEM0_SVD_MEM0_166_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_166_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_166_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_166_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_166_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_166_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_166_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_166_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_166_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_166_RESET                                     0x0
#define PHY_BB_SVD_MEM0_166_ADDRESS                                            (0x1698 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_166_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_166_RESET                                              0x0

// 0x169c (PHY_BB_SVD_MEM0_167)
#define PHY_BB_SVD_MEM0_SVD_MEM0_167_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_167_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_167_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_167_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_167_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_167_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_167_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_167_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_167_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_167_RESET                                     0x0
#define PHY_BB_SVD_MEM0_167_ADDRESS                                            (0x169c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_167_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_167_RESET                                              0x0

// 0x16a0 (PHY_BB_SVD_MEM0_168)
#define PHY_BB_SVD_MEM0_SVD_MEM0_168_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_168_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_168_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_168_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_168_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_168_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_168_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_168_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_168_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_168_RESET                                     0x0
#define PHY_BB_SVD_MEM0_168_ADDRESS                                            (0x16a0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_168_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_168_RESET                                              0x0

// 0x16a4 (PHY_BB_SVD_MEM0_169)
#define PHY_BB_SVD_MEM0_SVD_MEM0_169_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_169_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_169_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_169_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_169_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_169_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_169_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_169_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_169_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_169_RESET                                     0x0
#define PHY_BB_SVD_MEM0_169_ADDRESS                                            (0x16a4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_169_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_169_RESET                                              0x0

// 0x16a8 (PHY_BB_SVD_MEM0_170)
#define PHY_BB_SVD_MEM0_SVD_MEM0_170_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_170_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_170_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_170_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_170_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_170_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_170_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_170_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_170_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_170_RESET                                     0x0
#define PHY_BB_SVD_MEM0_170_ADDRESS                                            (0x16a8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_170_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_170_RESET                                              0x0

// 0x16ac (PHY_BB_SVD_MEM0_171)
#define PHY_BB_SVD_MEM0_SVD_MEM0_171_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_171_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_171_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_171_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_171_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_171_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_171_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_171_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_171_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_171_RESET                                     0x0
#define PHY_BB_SVD_MEM0_171_ADDRESS                                            (0x16ac + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_171_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_171_RESET                                              0x0

// 0x16b0 (PHY_BB_SVD_MEM0_172)
#define PHY_BB_SVD_MEM0_SVD_MEM0_172_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_172_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_172_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_172_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_172_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_172_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_172_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_172_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_172_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_172_RESET                                     0x0
#define PHY_BB_SVD_MEM0_172_ADDRESS                                            (0x16b0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_172_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_172_RESET                                              0x0

// 0x16b4 (PHY_BB_SVD_MEM0_173)
#define PHY_BB_SVD_MEM0_SVD_MEM0_173_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_173_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_173_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_173_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_173_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_173_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_173_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_173_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_173_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_173_RESET                                     0x0
#define PHY_BB_SVD_MEM0_173_ADDRESS                                            (0x16b4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_173_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_173_RESET                                              0x0

// 0x16b8 (PHY_BB_SVD_MEM0_174)
#define PHY_BB_SVD_MEM0_SVD_MEM0_174_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_174_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_174_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_174_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_174_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_174_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_174_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_174_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_174_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_174_RESET                                     0x0
#define PHY_BB_SVD_MEM0_174_ADDRESS                                            (0x16b8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_174_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_174_RESET                                              0x0

// 0x16bc (PHY_BB_SVD_MEM0_175)
#define PHY_BB_SVD_MEM0_SVD_MEM0_175_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_175_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_175_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_175_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_175_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_175_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_175_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_175_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_175_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_175_RESET                                     0x0
#define PHY_BB_SVD_MEM0_175_ADDRESS                                            (0x16bc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_175_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_175_RESET                                              0x0

// 0x16c0 (PHY_BB_SVD_MEM0_176)
#define PHY_BB_SVD_MEM0_SVD_MEM0_176_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_176_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_176_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_176_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_176_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_176_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_176_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_176_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_176_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_176_RESET                                     0x0
#define PHY_BB_SVD_MEM0_176_ADDRESS                                            (0x16c0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_176_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_176_RESET                                              0x0

// 0x16c4 (PHY_BB_SVD_MEM0_177)
#define PHY_BB_SVD_MEM0_SVD_MEM0_177_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_177_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_177_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_177_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_177_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_177_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_177_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_177_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_177_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_177_RESET                                     0x0
#define PHY_BB_SVD_MEM0_177_ADDRESS                                            (0x16c4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_177_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_177_RESET                                              0x0

// 0x16c8 (PHY_BB_SVD_MEM0_178)
#define PHY_BB_SVD_MEM0_SVD_MEM0_178_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_178_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_178_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_178_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_178_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_178_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_178_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_178_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_178_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_178_RESET                                     0x0
#define PHY_BB_SVD_MEM0_178_ADDRESS                                            (0x16c8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_178_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_178_RESET                                              0x0

// 0x16cc (PHY_BB_SVD_MEM0_179)
#define PHY_BB_SVD_MEM0_SVD_MEM0_179_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_179_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_179_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_179_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_179_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_179_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_179_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_179_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_179_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_179_RESET                                     0x0
#define PHY_BB_SVD_MEM0_179_ADDRESS                                            (0x16cc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_179_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_179_RESET                                              0x0

// 0x16d0 (PHY_BB_SVD_MEM0_180)
#define PHY_BB_SVD_MEM0_SVD_MEM0_180_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_180_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_180_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_180_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_180_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_180_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_180_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_180_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_180_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_180_RESET                                     0x0
#define PHY_BB_SVD_MEM0_180_ADDRESS                                            (0x16d0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_180_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_180_RESET                                              0x0

// 0x16d4 (PHY_BB_SVD_MEM0_181)
#define PHY_BB_SVD_MEM0_SVD_MEM0_181_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_181_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_181_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_181_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_181_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_181_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_181_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_181_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_181_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_181_RESET                                     0x0
#define PHY_BB_SVD_MEM0_181_ADDRESS                                            (0x16d4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_181_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_181_RESET                                              0x0

// 0x16d8 (PHY_BB_SVD_MEM0_182)
#define PHY_BB_SVD_MEM0_SVD_MEM0_182_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_182_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_182_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_182_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_182_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_182_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_182_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_182_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_182_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_182_RESET                                     0x0
#define PHY_BB_SVD_MEM0_182_ADDRESS                                            (0x16d8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_182_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_182_RESET                                              0x0

// 0x16dc (PHY_BB_SVD_MEM0_183)
#define PHY_BB_SVD_MEM0_SVD_MEM0_183_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_183_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_183_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_183_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_183_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_183_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_183_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_183_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_183_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_183_RESET                                     0x0
#define PHY_BB_SVD_MEM0_183_ADDRESS                                            (0x16dc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_183_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_183_RESET                                              0x0

// 0x16e0 (PHY_BB_SVD_MEM0_184)
#define PHY_BB_SVD_MEM0_SVD_MEM0_184_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_184_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_184_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_184_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_184_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_184_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_184_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_184_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_184_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_184_RESET                                     0x0
#define PHY_BB_SVD_MEM0_184_ADDRESS                                            (0x16e0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_184_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_184_RESET                                              0x0

// 0x16e4 (PHY_BB_SVD_MEM0_185)
#define PHY_BB_SVD_MEM0_SVD_MEM0_185_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_185_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_185_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_185_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_185_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_185_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_185_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_185_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_185_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_185_RESET                                     0x0
#define PHY_BB_SVD_MEM0_185_ADDRESS                                            (0x16e4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_185_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_185_RESET                                              0x0

// 0x16e8 (PHY_BB_SVD_MEM0_186)
#define PHY_BB_SVD_MEM0_SVD_MEM0_186_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_186_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_186_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_186_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_186_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_186_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_186_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_186_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_186_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_186_RESET                                     0x0
#define PHY_BB_SVD_MEM0_186_ADDRESS                                            (0x16e8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_186_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_186_RESET                                              0x0

// 0x16ec (PHY_BB_SVD_MEM0_187)
#define PHY_BB_SVD_MEM0_SVD_MEM0_187_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_187_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_187_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_187_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_187_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_187_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_187_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_187_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_187_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_187_RESET                                     0x0
#define PHY_BB_SVD_MEM0_187_ADDRESS                                            (0x16ec + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_187_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_187_RESET                                              0x0

// 0x16f0 (PHY_BB_SVD_MEM0_188)
#define PHY_BB_SVD_MEM0_SVD_MEM0_188_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_188_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_188_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_188_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_188_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_188_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_188_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_188_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_188_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_188_RESET                                     0x0
#define PHY_BB_SVD_MEM0_188_ADDRESS                                            (0x16f0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_188_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_188_RESET                                              0x0

// 0x16f4 (PHY_BB_SVD_MEM0_189)
#define PHY_BB_SVD_MEM0_SVD_MEM0_189_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_189_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_189_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_189_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_189_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_189_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_189_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_189_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_189_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_189_RESET                                     0x0
#define PHY_BB_SVD_MEM0_189_ADDRESS                                            (0x16f4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_189_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_189_RESET                                              0x0

// 0x16f8 (PHY_BB_SVD_MEM0_190)
#define PHY_BB_SVD_MEM0_SVD_MEM0_190_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_190_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_190_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_190_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_190_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_190_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_190_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_190_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_190_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_190_RESET                                     0x0
#define PHY_BB_SVD_MEM0_190_ADDRESS                                            (0x16f8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_190_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_190_RESET                                              0x0

// 0x16fc (PHY_BB_SVD_MEM0_191)
#define PHY_BB_SVD_MEM0_SVD_MEM0_191_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_191_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_191_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_191_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_191_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_191_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_191_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_191_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_191_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_191_RESET                                     0x0
#define PHY_BB_SVD_MEM0_191_ADDRESS                                            (0x16fc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_191_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_191_RESET                                              0x0

// 0x1700 (PHY_BB_SVD_MEM0_192)
#define PHY_BB_SVD_MEM0_SVD_MEM0_192_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_192_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_192_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_192_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_192_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_192_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_192_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_192_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_192_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_192_RESET                                     0x0
#define PHY_BB_SVD_MEM0_192_ADDRESS                                            (0x1700 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_192_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_192_RESET                                              0x0

// 0x1704 (PHY_BB_SVD_MEM0_193)
#define PHY_BB_SVD_MEM0_SVD_MEM0_193_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_193_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_193_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_193_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_193_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_193_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_193_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_193_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_193_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_193_RESET                                     0x0
#define PHY_BB_SVD_MEM0_193_ADDRESS                                            (0x1704 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_193_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_193_RESET                                              0x0

// 0x1708 (PHY_BB_SVD_MEM0_194)
#define PHY_BB_SVD_MEM0_SVD_MEM0_194_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_194_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_194_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_194_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_194_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_194_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_194_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_194_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_194_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_194_RESET                                     0x0
#define PHY_BB_SVD_MEM0_194_ADDRESS                                            (0x1708 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_194_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_194_RESET                                              0x0

// 0x170c (PHY_BB_SVD_MEM0_195)
#define PHY_BB_SVD_MEM0_SVD_MEM0_195_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_195_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_195_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_195_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_195_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_195_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_195_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_195_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_195_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_195_RESET                                     0x0
#define PHY_BB_SVD_MEM0_195_ADDRESS                                            (0x170c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_195_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_195_RESET                                              0x0

// 0x1710 (PHY_BB_SVD_MEM0_196)
#define PHY_BB_SVD_MEM0_SVD_MEM0_196_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_196_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_196_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_196_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_196_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_196_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_196_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_196_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_196_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_196_RESET                                     0x0
#define PHY_BB_SVD_MEM0_196_ADDRESS                                            (0x1710 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_196_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_196_RESET                                              0x0

// 0x1714 (PHY_BB_SVD_MEM0_197)
#define PHY_BB_SVD_MEM0_SVD_MEM0_197_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_197_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_197_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_197_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_197_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_197_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_197_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_197_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_197_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_197_RESET                                     0x0
#define PHY_BB_SVD_MEM0_197_ADDRESS                                            (0x1714 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_197_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_197_RESET                                              0x0

// 0x1718 (PHY_BB_SVD_MEM0_198)
#define PHY_BB_SVD_MEM0_SVD_MEM0_198_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_198_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_198_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_198_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_198_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_198_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_198_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_198_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_198_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_198_RESET                                     0x0
#define PHY_BB_SVD_MEM0_198_ADDRESS                                            (0x1718 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_198_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_198_RESET                                              0x0

// 0x171c (PHY_BB_SVD_MEM0_199)
#define PHY_BB_SVD_MEM0_SVD_MEM0_199_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_199_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_199_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_199_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_199_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_199_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_199_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_199_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_199_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_199_RESET                                     0x0
#define PHY_BB_SVD_MEM0_199_ADDRESS                                            (0x171c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_199_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_199_RESET                                              0x0

// 0x1720 (PHY_BB_SVD_MEM0_200)
#define PHY_BB_SVD_MEM0_SVD_MEM0_200_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_200_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_200_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_200_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_200_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_200_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_200_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_200_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_200_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_200_RESET                                     0x0
#define PHY_BB_SVD_MEM0_200_ADDRESS                                            (0x1720 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_200_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_200_RESET                                              0x0

// 0x1724 (PHY_BB_SVD_MEM0_201)
#define PHY_BB_SVD_MEM0_SVD_MEM0_201_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_201_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_201_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_201_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_201_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_201_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_201_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_201_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_201_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_201_RESET                                     0x0
#define PHY_BB_SVD_MEM0_201_ADDRESS                                            (0x1724 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_201_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_201_RESET                                              0x0

// 0x1728 (PHY_BB_SVD_MEM0_202)
#define PHY_BB_SVD_MEM0_SVD_MEM0_202_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_202_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_202_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_202_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_202_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_202_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_202_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_202_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_202_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_202_RESET                                     0x0
#define PHY_BB_SVD_MEM0_202_ADDRESS                                            (0x1728 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_202_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_202_RESET                                              0x0

// 0x172c (PHY_BB_SVD_MEM0_203)
#define PHY_BB_SVD_MEM0_SVD_MEM0_203_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_203_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_203_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_203_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_203_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_203_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_203_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_203_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_203_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_203_RESET                                     0x0
#define PHY_BB_SVD_MEM0_203_ADDRESS                                            (0x172c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_203_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_203_RESET                                              0x0

// 0x1730 (PHY_BB_SVD_MEM0_204)
#define PHY_BB_SVD_MEM0_SVD_MEM0_204_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_204_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_204_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_204_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_204_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_204_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_204_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_204_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_204_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_204_RESET                                     0x0
#define PHY_BB_SVD_MEM0_204_ADDRESS                                            (0x1730 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_204_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_204_RESET                                              0x0

// 0x1734 (PHY_BB_SVD_MEM0_205)
#define PHY_BB_SVD_MEM0_SVD_MEM0_205_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_205_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_205_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_205_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_205_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_205_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_205_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_205_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_205_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_205_RESET                                     0x0
#define PHY_BB_SVD_MEM0_205_ADDRESS                                            (0x1734 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_205_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_205_RESET                                              0x0

// 0x1738 (PHY_BB_SVD_MEM0_206)
#define PHY_BB_SVD_MEM0_SVD_MEM0_206_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_206_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_206_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_206_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_206_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_206_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_206_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_206_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_206_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_206_RESET                                     0x0
#define PHY_BB_SVD_MEM0_206_ADDRESS                                            (0x1738 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_206_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_206_RESET                                              0x0

// 0x173c (PHY_BB_SVD_MEM0_207)
#define PHY_BB_SVD_MEM0_SVD_MEM0_207_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_207_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_207_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_207_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_207_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_207_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_207_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_207_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_207_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_207_RESET                                     0x0
#define PHY_BB_SVD_MEM0_207_ADDRESS                                            (0x173c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_207_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_207_RESET                                              0x0

// 0x1740 (PHY_BB_SVD_MEM0_208)
#define PHY_BB_SVD_MEM0_SVD_MEM0_208_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_208_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_208_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_208_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_208_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_208_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_208_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_208_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_208_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_208_RESET                                     0x0
#define PHY_BB_SVD_MEM0_208_ADDRESS                                            (0x1740 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_208_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_208_RESET                                              0x0

// 0x1744 (PHY_BB_SVD_MEM0_209)
#define PHY_BB_SVD_MEM0_SVD_MEM0_209_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_209_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_209_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_209_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_209_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_209_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_209_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_209_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_209_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_209_RESET                                     0x0
#define PHY_BB_SVD_MEM0_209_ADDRESS                                            (0x1744 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_209_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_209_RESET                                              0x0

// 0x1748 (PHY_BB_SVD_MEM0_210)
#define PHY_BB_SVD_MEM0_SVD_MEM0_210_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_210_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_210_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_210_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_210_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_210_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_210_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_210_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_210_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_210_RESET                                     0x0
#define PHY_BB_SVD_MEM0_210_ADDRESS                                            (0x1748 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_210_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_210_RESET                                              0x0

// 0x174c (PHY_BB_SVD_MEM0_211)
#define PHY_BB_SVD_MEM0_SVD_MEM0_211_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_211_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_211_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_211_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_211_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_211_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_211_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_211_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_211_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_211_RESET                                     0x0
#define PHY_BB_SVD_MEM0_211_ADDRESS                                            (0x174c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_211_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_211_RESET                                              0x0

// 0x1750 (PHY_BB_SVD_MEM0_212)
#define PHY_BB_SVD_MEM0_SVD_MEM0_212_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_212_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_212_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_212_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_212_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_212_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_212_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_212_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_212_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_212_RESET                                     0x0
#define PHY_BB_SVD_MEM0_212_ADDRESS                                            (0x1750 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_212_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_212_RESET                                              0x0

// 0x1754 (PHY_BB_SVD_MEM0_213)
#define PHY_BB_SVD_MEM0_SVD_MEM0_213_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_213_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_213_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_213_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_213_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_213_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_213_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_213_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_213_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_213_RESET                                     0x0
#define PHY_BB_SVD_MEM0_213_ADDRESS                                            (0x1754 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_213_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_213_RESET                                              0x0

// 0x1758 (PHY_BB_SVD_MEM0_214)
#define PHY_BB_SVD_MEM0_SVD_MEM0_214_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_214_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_214_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_214_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_214_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_214_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_214_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_214_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_214_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_214_RESET                                     0x0
#define PHY_BB_SVD_MEM0_214_ADDRESS                                            (0x1758 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_214_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_214_RESET                                              0x0

// 0x175c (PHY_BB_SVD_MEM0_215)
#define PHY_BB_SVD_MEM0_SVD_MEM0_215_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_215_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_215_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_215_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_215_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_215_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_215_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_215_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_215_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_215_RESET                                     0x0
#define PHY_BB_SVD_MEM0_215_ADDRESS                                            (0x175c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_215_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_215_RESET                                              0x0

// 0x1760 (PHY_BB_SVD_MEM0_216)
#define PHY_BB_SVD_MEM0_SVD_MEM0_216_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_216_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_216_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_216_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_216_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_216_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_216_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_216_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_216_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_216_RESET                                     0x0
#define PHY_BB_SVD_MEM0_216_ADDRESS                                            (0x1760 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_216_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_216_RESET                                              0x0

// 0x1764 (PHY_BB_SVD_MEM0_217)
#define PHY_BB_SVD_MEM0_SVD_MEM0_217_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_217_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_217_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_217_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_217_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_217_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_217_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_217_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_217_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_217_RESET                                     0x0
#define PHY_BB_SVD_MEM0_217_ADDRESS                                            (0x1764 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_217_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_217_RESET                                              0x0

// 0x1768 (PHY_BB_SVD_MEM0_218)
#define PHY_BB_SVD_MEM0_SVD_MEM0_218_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_218_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_218_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_218_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_218_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_218_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_218_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_218_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_218_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_218_RESET                                     0x0
#define PHY_BB_SVD_MEM0_218_ADDRESS                                            (0x1768 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_218_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_218_RESET                                              0x0

// 0x176c (PHY_BB_SVD_MEM0_219)
#define PHY_BB_SVD_MEM0_SVD_MEM0_219_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_219_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_219_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_219_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_219_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_219_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_219_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_219_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_219_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_219_RESET                                     0x0
#define PHY_BB_SVD_MEM0_219_ADDRESS                                            (0x176c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_219_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_219_RESET                                              0x0

// 0x1770 (PHY_BB_SVD_MEM0_220)
#define PHY_BB_SVD_MEM0_SVD_MEM0_220_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_220_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_220_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_220_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_220_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_220_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_220_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_220_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_220_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_220_RESET                                     0x0
#define PHY_BB_SVD_MEM0_220_ADDRESS                                            (0x1770 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_220_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_220_RESET                                              0x0

// 0x1774 (PHY_BB_SVD_MEM0_221)
#define PHY_BB_SVD_MEM0_SVD_MEM0_221_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_221_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_221_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_221_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_221_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_221_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_221_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_221_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_221_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_221_RESET                                     0x0
#define PHY_BB_SVD_MEM0_221_ADDRESS                                            (0x1774 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_221_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_221_RESET                                              0x0

// 0x1778 (PHY_BB_SVD_MEM0_222)
#define PHY_BB_SVD_MEM0_SVD_MEM0_222_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_222_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_222_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_222_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_222_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_222_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_222_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_222_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_222_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_222_RESET                                     0x0
#define PHY_BB_SVD_MEM0_222_ADDRESS                                            (0x1778 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_222_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_222_RESET                                              0x0

// 0x177c (PHY_BB_SVD_MEM0_223)
#define PHY_BB_SVD_MEM0_SVD_MEM0_223_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_223_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_223_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_223_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_223_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_223_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_223_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_223_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_223_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_223_RESET                                     0x0
#define PHY_BB_SVD_MEM0_223_ADDRESS                                            (0x177c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_223_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_223_RESET                                              0x0

// 0x1780 (PHY_BB_SVD_MEM0_224)
#define PHY_BB_SVD_MEM0_SVD_MEM0_224_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_224_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_224_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_224_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_224_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_224_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_224_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_224_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_224_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_224_RESET                                     0x0
#define PHY_BB_SVD_MEM0_224_ADDRESS                                            (0x1780 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_224_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_224_RESET                                              0x0

// 0x1784 (PHY_BB_SVD_MEM0_225)
#define PHY_BB_SVD_MEM0_SVD_MEM0_225_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_225_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_225_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_225_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_225_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_225_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_225_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_225_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_225_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_225_RESET                                     0x0
#define PHY_BB_SVD_MEM0_225_ADDRESS                                            (0x1784 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_225_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_225_RESET                                              0x0

// 0x1788 (PHY_BB_SVD_MEM0_226)
#define PHY_BB_SVD_MEM0_SVD_MEM0_226_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_226_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_226_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_226_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_226_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_226_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_226_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_226_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_226_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_226_RESET                                     0x0
#define PHY_BB_SVD_MEM0_226_ADDRESS                                            (0x1788 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_226_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_226_RESET                                              0x0

// 0x178c (PHY_BB_SVD_MEM0_227)
#define PHY_BB_SVD_MEM0_SVD_MEM0_227_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_227_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_227_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_227_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_227_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_227_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_227_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_227_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_227_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_227_RESET                                     0x0
#define PHY_BB_SVD_MEM0_227_ADDRESS                                            (0x178c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_227_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_227_RESET                                              0x0

// 0x1790 (PHY_BB_SVD_MEM0_228)
#define PHY_BB_SVD_MEM0_SVD_MEM0_228_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_228_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_228_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_228_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_228_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_228_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_228_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_228_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_228_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_228_RESET                                     0x0
#define PHY_BB_SVD_MEM0_228_ADDRESS                                            (0x1790 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_228_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_228_RESET                                              0x0

// 0x1794 (PHY_BB_SVD_MEM0_229)
#define PHY_BB_SVD_MEM0_SVD_MEM0_229_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_229_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_229_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_229_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_229_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_229_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_229_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_229_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_229_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_229_RESET                                     0x0
#define PHY_BB_SVD_MEM0_229_ADDRESS                                            (0x1794 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_229_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_229_RESET                                              0x0

// 0x1798 (PHY_BB_SVD_MEM0_230)
#define PHY_BB_SVD_MEM0_SVD_MEM0_230_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_230_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_230_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_230_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_230_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_230_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_230_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_230_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_230_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_230_RESET                                     0x0
#define PHY_BB_SVD_MEM0_230_ADDRESS                                            (0x1798 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_230_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_230_RESET                                              0x0

// 0x179c (PHY_BB_SVD_MEM0_231)
#define PHY_BB_SVD_MEM0_SVD_MEM0_231_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_231_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_231_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_231_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_231_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_231_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_231_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_231_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_231_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_231_RESET                                     0x0
#define PHY_BB_SVD_MEM0_231_ADDRESS                                            (0x179c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_231_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_231_RESET                                              0x0

// 0x17a0 (PHY_BB_SVD_MEM0_232)
#define PHY_BB_SVD_MEM0_SVD_MEM0_232_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_232_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_232_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_232_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_232_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_232_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_232_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_232_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_232_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_232_RESET                                     0x0
#define PHY_BB_SVD_MEM0_232_ADDRESS                                            (0x17a0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_232_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_232_RESET                                              0x0

// 0x17a4 (PHY_BB_SVD_MEM0_233)
#define PHY_BB_SVD_MEM0_SVD_MEM0_233_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_233_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_233_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_233_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_233_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_233_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_233_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_233_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_233_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_233_RESET                                     0x0
#define PHY_BB_SVD_MEM0_233_ADDRESS                                            (0x17a4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_233_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_233_RESET                                              0x0

// 0x17a8 (PHY_BB_SVD_MEM0_234)
#define PHY_BB_SVD_MEM0_SVD_MEM0_234_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_234_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_234_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_234_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_234_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_234_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_234_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_234_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_234_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_234_RESET                                     0x0
#define PHY_BB_SVD_MEM0_234_ADDRESS                                            (0x17a8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_234_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_234_RESET                                              0x0

// 0x17ac (PHY_BB_SVD_MEM0_235)
#define PHY_BB_SVD_MEM0_SVD_MEM0_235_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_235_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_235_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_235_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_235_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_235_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_235_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_235_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_235_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_235_RESET                                     0x0
#define PHY_BB_SVD_MEM0_235_ADDRESS                                            (0x17ac + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_235_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_235_RESET                                              0x0

// 0x17b0 (PHY_BB_SVD_MEM0_236)
#define PHY_BB_SVD_MEM0_SVD_MEM0_236_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_236_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_236_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_236_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_236_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_236_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_236_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_236_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_236_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_236_RESET                                     0x0
#define PHY_BB_SVD_MEM0_236_ADDRESS                                            (0x17b0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_236_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_236_RESET                                              0x0

// 0x17b4 (PHY_BB_SVD_MEM0_237)
#define PHY_BB_SVD_MEM0_SVD_MEM0_237_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_237_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_237_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_237_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_237_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_237_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_237_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_237_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_237_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_237_RESET                                     0x0
#define PHY_BB_SVD_MEM0_237_ADDRESS                                            (0x17b4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_237_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_237_RESET                                              0x0

// 0x17b8 (PHY_BB_SVD_MEM0_238)
#define PHY_BB_SVD_MEM0_SVD_MEM0_238_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_238_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_238_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_238_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_238_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_238_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_238_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_238_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_238_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_238_RESET                                     0x0
#define PHY_BB_SVD_MEM0_238_ADDRESS                                            (0x17b8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_238_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_238_RESET                                              0x0

// 0x17bc (PHY_BB_SVD_MEM0_239)
#define PHY_BB_SVD_MEM0_SVD_MEM0_239_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_239_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_239_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_239_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_239_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_239_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_239_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_239_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_239_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_239_RESET                                     0x0
#define PHY_BB_SVD_MEM0_239_ADDRESS                                            (0x17bc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_239_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_239_RESET                                              0x0

// 0x17c0 (PHY_BB_SVD_MEM0_240)
#define PHY_BB_SVD_MEM0_SVD_MEM0_240_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_240_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_240_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_240_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_240_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_240_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_240_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_240_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_240_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_240_RESET                                     0x0
#define PHY_BB_SVD_MEM0_240_ADDRESS                                            (0x17c0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_240_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_240_RESET                                              0x0

// 0x17c4 (PHY_BB_SVD_MEM0_241)
#define PHY_BB_SVD_MEM0_SVD_MEM0_241_LSB                                       0
#define PHY_BB_SVD_MEM0_SVD_MEM0_241_MSB                                       31
#define PHY_BB_SVD_MEM0_SVD_MEM0_241_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM0_SVD_MEM0_241_GET(x)                                    (((x) & PHY_BB_SVD_MEM0_SVD_MEM0_241_MASK) >> PHY_BB_SVD_MEM0_SVD_MEM0_241_LSB)
#define PHY_BB_SVD_MEM0_SVD_MEM0_241_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM0_SVD_MEM0_241_LSB) & PHY_BB_SVD_MEM0_SVD_MEM0_241_MASK)
#define PHY_BB_SVD_MEM0_SVD_MEM0_241_RESET                                     0x0
#define PHY_BB_SVD_MEM0_241_ADDRESS                                            (0x17c4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM0_241_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM0_241_RESET                                              0x0

// 0x1800 (PHY_BB_SVD_MEM1)
#define PHY_BB_SVD_MEM1_SVD_MEM1_LSB                                           0
#define PHY_BB_SVD_MEM1_SVD_MEM1_MSB                                           31
#define PHY_BB_SVD_MEM1_SVD_MEM1_MASK                                          0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_GET(x)                                        (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_SET(x)                                        (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_RESET                                         0x0
#define PHY_BB_SVD_MEM1_ADDRESS                                                (0x1800 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_RSTMASK                                                0xffffffff
#define PHY_BB_SVD_MEM1_RESET                                                  0x0

// 0x1800 (PHY_BB_SVD_MEM1_0)
#define PHY_BB_SVD_MEM1_SVD_MEM1_0_LSB                                         0
#define PHY_BB_SVD_MEM1_SVD_MEM1_0_MSB                                         31
#define PHY_BB_SVD_MEM1_SVD_MEM1_0_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_0_GET(x)                                      (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_0_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_0_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_0_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_0_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_0_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_0_RESET                                       0x0
#define PHY_BB_SVD_MEM1_0_ADDRESS                                              (0x1800 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_0_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM1_0_RESET                                                0x0

// 0x1804 (PHY_BB_SVD_MEM1_1)
#define PHY_BB_SVD_MEM1_SVD_MEM1_1_LSB                                         0
#define PHY_BB_SVD_MEM1_SVD_MEM1_1_MSB                                         31
#define PHY_BB_SVD_MEM1_SVD_MEM1_1_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_1_GET(x)                                      (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_1_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_1_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_1_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_1_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_1_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_1_RESET                                       0x0
#define PHY_BB_SVD_MEM1_1_ADDRESS                                              (0x1804 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_1_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM1_1_RESET                                                0x0

// 0x1808 (PHY_BB_SVD_MEM1_2)
#define PHY_BB_SVD_MEM1_SVD_MEM1_2_LSB                                         0
#define PHY_BB_SVD_MEM1_SVD_MEM1_2_MSB                                         31
#define PHY_BB_SVD_MEM1_SVD_MEM1_2_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_2_GET(x)                                      (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_2_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_2_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_2_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_2_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_2_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_2_RESET                                       0x0
#define PHY_BB_SVD_MEM1_2_ADDRESS                                              (0x1808 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_2_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM1_2_RESET                                                0x0

// 0x180c (PHY_BB_SVD_MEM1_3)
#define PHY_BB_SVD_MEM1_SVD_MEM1_3_LSB                                         0
#define PHY_BB_SVD_MEM1_SVD_MEM1_3_MSB                                         31
#define PHY_BB_SVD_MEM1_SVD_MEM1_3_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_3_GET(x)                                      (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_3_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_3_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_3_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_3_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_3_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_3_RESET                                       0x0
#define PHY_BB_SVD_MEM1_3_ADDRESS                                              (0x180c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_3_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM1_3_RESET                                                0x0

// 0x1810 (PHY_BB_SVD_MEM1_4)
#define PHY_BB_SVD_MEM1_SVD_MEM1_4_LSB                                         0
#define PHY_BB_SVD_MEM1_SVD_MEM1_4_MSB                                         31
#define PHY_BB_SVD_MEM1_SVD_MEM1_4_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_4_GET(x)                                      (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_4_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_4_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_4_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_4_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_4_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_4_RESET                                       0x0
#define PHY_BB_SVD_MEM1_4_ADDRESS                                              (0x1810 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_4_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM1_4_RESET                                                0x0

// 0x1814 (PHY_BB_SVD_MEM1_5)
#define PHY_BB_SVD_MEM1_SVD_MEM1_5_LSB                                         0
#define PHY_BB_SVD_MEM1_SVD_MEM1_5_MSB                                         31
#define PHY_BB_SVD_MEM1_SVD_MEM1_5_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_5_GET(x)                                      (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_5_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_5_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_5_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_5_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_5_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_5_RESET                                       0x0
#define PHY_BB_SVD_MEM1_5_ADDRESS                                              (0x1814 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_5_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM1_5_RESET                                                0x0

// 0x1818 (PHY_BB_SVD_MEM1_6)
#define PHY_BB_SVD_MEM1_SVD_MEM1_6_LSB                                         0
#define PHY_BB_SVD_MEM1_SVD_MEM1_6_MSB                                         31
#define PHY_BB_SVD_MEM1_SVD_MEM1_6_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_6_GET(x)                                      (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_6_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_6_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_6_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_6_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_6_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_6_RESET                                       0x0
#define PHY_BB_SVD_MEM1_6_ADDRESS                                              (0x1818 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_6_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM1_6_RESET                                                0x0

// 0x181c (PHY_BB_SVD_MEM1_7)
#define PHY_BB_SVD_MEM1_SVD_MEM1_7_LSB                                         0
#define PHY_BB_SVD_MEM1_SVD_MEM1_7_MSB                                         31
#define PHY_BB_SVD_MEM1_SVD_MEM1_7_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_7_GET(x)                                      (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_7_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_7_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_7_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_7_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_7_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_7_RESET                                       0x0
#define PHY_BB_SVD_MEM1_7_ADDRESS                                              (0x181c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_7_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM1_7_RESET                                                0x0

// 0x1820 (PHY_BB_SVD_MEM1_8)
#define PHY_BB_SVD_MEM1_SVD_MEM1_8_LSB                                         0
#define PHY_BB_SVD_MEM1_SVD_MEM1_8_MSB                                         31
#define PHY_BB_SVD_MEM1_SVD_MEM1_8_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_8_GET(x)                                      (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_8_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_8_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_8_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_8_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_8_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_8_RESET                                       0x0
#define PHY_BB_SVD_MEM1_8_ADDRESS                                              (0x1820 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_8_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM1_8_RESET                                                0x0

// 0x1824 (PHY_BB_SVD_MEM1_9)
#define PHY_BB_SVD_MEM1_SVD_MEM1_9_LSB                                         0
#define PHY_BB_SVD_MEM1_SVD_MEM1_9_MSB                                         31
#define PHY_BB_SVD_MEM1_SVD_MEM1_9_MASK                                        0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_9_GET(x)                                      (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_9_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_9_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_9_SET(x)                                      (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_9_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_9_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_9_RESET                                       0x0
#define PHY_BB_SVD_MEM1_9_ADDRESS                                              (0x1824 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_9_RSTMASK                                              0xffffffff
#define PHY_BB_SVD_MEM1_9_RESET                                                0x0

// 0x1828 (PHY_BB_SVD_MEM1_10)
#define PHY_BB_SVD_MEM1_SVD_MEM1_10_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_10_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_10_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_10_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_10_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_10_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_10_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_10_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_10_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_10_RESET                                      0x0
#define PHY_BB_SVD_MEM1_10_ADDRESS                                             (0x1828 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_10_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_10_RESET                                               0x0

// 0x182c (PHY_BB_SVD_MEM1_11)
#define PHY_BB_SVD_MEM1_SVD_MEM1_11_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_11_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_11_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_11_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_11_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_11_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_11_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_11_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_11_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_11_RESET                                      0x0
#define PHY_BB_SVD_MEM1_11_ADDRESS                                             (0x182c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_11_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_11_RESET                                               0x0

// 0x1830 (PHY_BB_SVD_MEM1_12)
#define PHY_BB_SVD_MEM1_SVD_MEM1_12_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_12_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_12_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_12_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_12_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_12_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_12_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_12_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_12_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_12_RESET                                      0x0
#define PHY_BB_SVD_MEM1_12_ADDRESS                                             (0x1830 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_12_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_12_RESET                                               0x0

// 0x1834 (PHY_BB_SVD_MEM1_13)
#define PHY_BB_SVD_MEM1_SVD_MEM1_13_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_13_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_13_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_13_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_13_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_13_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_13_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_13_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_13_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_13_RESET                                      0x0
#define PHY_BB_SVD_MEM1_13_ADDRESS                                             (0x1834 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_13_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_13_RESET                                               0x0

// 0x1838 (PHY_BB_SVD_MEM1_14)
#define PHY_BB_SVD_MEM1_SVD_MEM1_14_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_14_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_14_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_14_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_14_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_14_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_14_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_14_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_14_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_14_RESET                                      0x0
#define PHY_BB_SVD_MEM1_14_ADDRESS                                             (0x1838 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_14_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_14_RESET                                               0x0

// 0x183c (PHY_BB_SVD_MEM1_15)
#define PHY_BB_SVD_MEM1_SVD_MEM1_15_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_15_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_15_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_15_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_15_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_15_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_15_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_15_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_15_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_15_RESET                                      0x0
#define PHY_BB_SVD_MEM1_15_ADDRESS                                             (0x183c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_15_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_15_RESET                                               0x0

// 0x1840 (PHY_BB_SVD_MEM1_16)
#define PHY_BB_SVD_MEM1_SVD_MEM1_16_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_16_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_16_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_16_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_16_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_16_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_16_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_16_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_16_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_16_RESET                                      0x0
#define PHY_BB_SVD_MEM1_16_ADDRESS                                             (0x1840 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_16_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_16_RESET                                               0x0

// 0x1844 (PHY_BB_SVD_MEM1_17)
#define PHY_BB_SVD_MEM1_SVD_MEM1_17_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_17_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_17_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_17_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_17_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_17_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_17_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_17_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_17_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_17_RESET                                      0x0
#define PHY_BB_SVD_MEM1_17_ADDRESS                                             (0x1844 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_17_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_17_RESET                                               0x0

// 0x1848 (PHY_BB_SVD_MEM1_18)
#define PHY_BB_SVD_MEM1_SVD_MEM1_18_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_18_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_18_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_18_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_18_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_18_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_18_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_18_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_18_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_18_RESET                                      0x0
#define PHY_BB_SVD_MEM1_18_ADDRESS                                             (0x1848 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_18_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_18_RESET                                               0x0

// 0x184c (PHY_BB_SVD_MEM1_19)
#define PHY_BB_SVD_MEM1_SVD_MEM1_19_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_19_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_19_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_19_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_19_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_19_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_19_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_19_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_19_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_19_RESET                                      0x0
#define PHY_BB_SVD_MEM1_19_ADDRESS                                             (0x184c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_19_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_19_RESET                                               0x0

// 0x1850 (PHY_BB_SVD_MEM1_20)
#define PHY_BB_SVD_MEM1_SVD_MEM1_20_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_20_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_20_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_20_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_20_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_20_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_20_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_20_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_20_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_20_RESET                                      0x0
#define PHY_BB_SVD_MEM1_20_ADDRESS                                             (0x1850 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_20_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_20_RESET                                               0x0

// 0x1854 (PHY_BB_SVD_MEM1_21)
#define PHY_BB_SVD_MEM1_SVD_MEM1_21_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_21_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_21_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_21_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_21_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_21_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_21_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_21_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_21_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_21_RESET                                      0x0
#define PHY_BB_SVD_MEM1_21_ADDRESS                                             (0x1854 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_21_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_21_RESET                                               0x0

// 0x1858 (PHY_BB_SVD_MEM1_22)
#define PHY_BB_SVD_MEM1_SVD_MEM1_22_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_22_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_22_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_22_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_22_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_22_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_22_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_22_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_22_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_22_RESET                                      0x0
#define PHY_BB_SVD_MEM1_22_ADDRESS                                             (0x1858 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_22_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_22_RESET                                               0x0

// 0x185c (PHY_BB_SVD_MEM1_23)
#define PHY_BB_SVD_MEM1_SVD_MEM1_23_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_23_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_23_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_23_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_23_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_23_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_23_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_23_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_23_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_23_RESET                                      0x0
#define PHY_BB_SVD_MEM1_23_ADDRESS                                             (0x185c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_23_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_23_RESET                                               0x0

// 0x1860 (PHY_BB_SVD_MEM1_24)
#define PHY_BB_SVD_MEM1_SVD_MEM1_24_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_24_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_24_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_24_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_24_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_24_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_24_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_24_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_24_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_24_RESET                                      0x0
#define PHY_BB_SVD_MEM1_24_ADDRESS                                             (0x1860 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_24_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_24_RESET                                               0x0

// 0x1864 (PHY_BB_SVD_MEM1_25)
#define PHY_BB_SVD_MEM1_SVD_MEM1_25_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_25_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_25_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_25_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_25_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_25_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_25_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_25_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_25_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_25_RESET                                      0x0
#define PHY_BB_SVD_MEM1_25_ADDRESS                                             (0x1864 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_25_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_25_RESET                                               0x0

// 0x1868 (PHY_BB_SVD_MEM1_26)
#define PHY_BB_SVD_MEM1_SVD_MEM1_26_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_26_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_26_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_26_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_26_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_26_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_26_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_26_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_26_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_26_RESET                                      0x0
#define PHY_BB_SVD_MEM1_26_ADDRESS                                             (0x1868 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_26_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_26_RESET                                               0x0

// 0x186c (PHY_BB_SVD_MEM1_27)
#define PHY_BB_SVD_MEM1_SVD_MEM1_27_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_27_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_27_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_27_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_27_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_27_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_27_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_27_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_27_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_27_RESET                                      0x0
#define PHY_BB_SVD_MEM1_27_ADDRESS                                             (0x186c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_27_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_27_RESET                                               0x0

// 0x1870 (PHY_BB_SVD_MEM1_28)
#define PHY_BB_SVD_MEM1_SVD_MEM1_28_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_28_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_28_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_28_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_28_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_28_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_28_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_28_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_28_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_28_RESET                                      0x0
#define PHY_BB_SVD_MEM1_28_ADDRESS                                             (0x1870 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_28_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_28_RESET                                               0x0

// 0x1874 (PHY_BB_SVD_MEM1_29)
#define PHY_BB_SVD_MEM1_SVD_MEM1_29_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_29_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_29_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_29_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_29_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_29_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_29_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_29_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_29_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_29_RESET                                      0x0
#define PHY_BB_SVD_MEM1_29_ADDRESS                                             (0x1874 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_29_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_29_RESET                                               0x0

// 0x1878 (PHY_BB_SVD_MEM1_30)
#define PHY_BB_SVD_MEM1_SVD_MEM1_30_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_30_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_30_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_30_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_30_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_30_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_30_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_30_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_30_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_30_RESET                                      0x0
#define PHY_BB_SVD_MEM1_30_ADDRESS                                             (0x1878 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_30_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_30_RESET                                               0x0

// 0x187c (PHY_BB_SVD_MEM1_31)
#define PHY_BB_SVD_MEM1_SVD_MEM1_31_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_31_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_31_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_31_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_31_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_31_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_31_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_31_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_31_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_31_RESET                                      0x0
#define PHY_BB_SVD_MEM1_31_ADDRESS                                             (0x187c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_31_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_31_RESET                                               0x0

// 0x1880 (PHY_BB_SVD_MEM1_32)
#define PHY_BB_SVD_MEM1_SVD_MEM1_32_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_32_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_32_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_32_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_32_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_32_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_32_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_32_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_32_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_32_RESET                                      0x0
#define PHY_BB_SVD_MEM1_32_ADDRESS                                             (0x1880 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_32_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_32_RESET                                               0x0

// 0x1884 (PHY_BB_SVD_MEM1_33)
#define PHY_BB_SVD_MEM1_SVD_MEM1_33_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_33_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_33_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_33_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_33_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_33_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_33_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_33_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_33_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_33_RESET                                      0x0
#define PHY_BB_SVD_MEM1_33_ADDRESS                                             (0x1884 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_33_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_33_RESET                                               0x0

// 0x1888 (PHY_BB_SVD_MEM1_34)
#define PHY_BB_SVD_MEM1_SVD_MEM1_34_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_34_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_34_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_34_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_34_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_34_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_34_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_34_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_34_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_34_RESET                                      0x0
#define PHY_BB_SVD_MEM1_34_ADDRESS                                             (0x1888 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_34_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_34_RESET                                               0x0

// 0x188c (PHY_BB_SVD_MEM1_35)
#define PHY_BB_SVD_MEM1_SVD_MEM1_35_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_35_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_35_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_35_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_35_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_35_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_35_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_35_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_35_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_35_RESET                                      0x0
#define PHY_BB_SVD_MEM1_35_ADDRESS                                             (0x188c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_35_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_35_RESET                                               0x0

// 0x1890 (PHY_BB_SVD_MEM1_36)
#define PHY_BB_SVD_MEM1_SVD_MEM1_36_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_36_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_36_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_36_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_36_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_36_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_36_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_36_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_36_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_36_RESET                                      0x0
#define PHY_BB_SVD_MEM1_36_ADDRESS                                             (0x1890 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_36_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_36_RESET                                               0x0

// 0x1894 (PHY_BB_SVD_MEM1_37)
#define PHY_BB_SVD_MEM1_SVD_MEM1_37_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_37_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_37_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_37_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_37_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_37_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_37_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_37_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_37_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_37_RESET                                      0x0
#define PHY_BB_SVD_MEM1_37_ADDRESS                                             (0x1894 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_37_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_37_RESET                                               0x0

// 0x1898 (PHY_BB_SVD_MEM1_38)
#define PHY_BB_SVD_MEM1_SVD_MEM1_38_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_38_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_38_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_38_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_38_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_38_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_38_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_38_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_38_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_38_RESET                                      0x0
#define PHY_BB_SVD_MEM1_38_ADDRESS                                             (0x1898 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_38_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_38_RESET                                               0x0

// 0x189c (PHY_BB_SVD_MEM1_39)
#define PHY_BB_SVD_MEM1_SVD_MEM1_39_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_39_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_39_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_39_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_39_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_39_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_39_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_39_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_39_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_39_RESET                                      0x0
#define PHY_BB_SVD_MEM1_39_ADDRESS                                             (0x189c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_39_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_39_RESET                                               0x0

// 0x18a0 (PHY_BB_SVD_MEM1_40)
#define PHY_BB_SVD_MEM1_SVD_MEM1_40_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_40_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_40_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_40_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_40_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_40_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_40_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_40_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_40_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_40_RESET                                      0x0
#define PHY_BB_SVD_MEM1_40_ADDRESS                                             (0x18a0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_40_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_40_RESET                                               0x0

// 0x18a4 (PHY_BB_SVD_MEM1_41)
#define PHY_BB_SVD_MEM1_SVD_MEM1_41_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_41_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_41_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_41_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_41_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_41_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_41_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_41_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_41_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_41_RESET                                      0x0
#define PHY_BB_SVD_MEM1_41_ADDRESS                                             (0x18a4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_41_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_41_RESET                                               0x0

// 0x18a8 (PHY_BB_SVD_MEM1_42)
#define PHY_BB_SVD_MEM1_SVD_MEM1_42_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_42_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_42_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_42_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_42_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_42_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_42_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_42_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_42_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_42_RESET                                      0x0
#define PHY_BB_SVD_MEM1_42_ADDRESS                                             (0x18a8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_42_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_42_RESET                                               0x0

// 0x18ac (PHY_BB_SVD_MEM1_43)
#define PHY_BB_SVD_MEM1_SVD_MEM1_43_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_43_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_43_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_43_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_43_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_43_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_43_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_43_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_43_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_43_RESET                                      0x0
#define PHY_BB_SVD_MEM1_43_ADDRESS                                             (0x18ac + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_43_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_43_RESET                                               0x0

// 0x18b0 (PHY_BB_SVD_MEM1_44)
#define PHY_BB_SVD_MEM1_SVD_MEM1_44_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_44_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_44_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_44_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_44_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_44_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_44_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_44_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_44_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_44_RESET                                      0x0
#define PHY_BB_SVD_MEM1_44_ADDRESS                                             (0x18b0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_44_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_44_RESET                                               0x0

// 0x18b4 (PHY_BB_SVD_MEM1_45)
#define PHY_BB_SVD_MEM1_SVD_MEM1_45_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_45_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_45_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_45_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_45_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_45_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_45_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_45_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_45_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_45_RESET                                      0x0
#define PHY_BB_SVD_MEM1_45_ADDRESS                                             (0x18b4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_45_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_45_RESET                                               0x0

// 0x18b8 (PHY_BB_SVD_MEM1_46)
#define PHY_BB_SVD_MEM1_SVD_MEM1_46_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_46_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_46_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_46_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_46_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_46_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_46_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_46_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_46_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_46_RESET                                      0x0
#define PHY_BB_SVD_MEM1_46_ADDRESS                                             (0x18b8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_46_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_46_RESET                                               0x0

// 0x18bc (PHY_BB_SVD_MEM1_47)
#define PHY_BB_SVD_MEM1_SVD_MEM1_47_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_47_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_47_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_47_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_47_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_47_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_47_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_47_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_47_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_47_RESET                                      0x0
#define PHY_BB_SVD_MEM1_47_ADDRESS                                             (0x18bc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_47_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_47_RESET                                               0x0

// 0x18c0 (PHY_BB_SVD_MEM1_48)
#define PHY_BB_SVD_MEM1_SVD_MEM1_48_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_48_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_48_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_48_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_48_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_48_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_48_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_48_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_48_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_48_RESET                                      0x0
#define PHY_BB_SVD_MEM1_48_ADDRESS                                             (0x18c0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_48_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_48_RESET                                               0x0

// 0x18c4 (PHY_BB_SVD_MEM1_49)
#define PHY_BB_SVD_MEM1_SVD_MEM1_49_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_49_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_49_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_49_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_49_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_49_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_49_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_49_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_49_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_49_RESET                                      0x0
#define PHY_BB_SVD_MEM1_49_ADDRESS                                             (0x18c4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_49_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_49_RESET                                               0x0

// 0x18c8 (PHY_BB_SVD_MEM1_50)
#define PHY_BB_SVD_MEM1_SVD_MEM1_50_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_50_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_50_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_50_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_50_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_50_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_50_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_50_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_50_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_50_RESET                                      0x0
#define PHY_BB_SVD_MEM1_50_ADDRESS                                             (0x18c8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_50_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_50_RESET                                               0x0

// 0x18cc (PHY_BB_SVD_MEM1_51)
#define PHY_BB_SVD_MEM1_SVD_MEM1_51_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_51_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_51_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_51_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_51_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_51_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_51_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_51_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_51_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_51_RESET                                      0x0
#define PHY_BB_SVD_MEM1_51_ADDRESS                                             (0x18cc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_51_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_51_RESET                                               0x0

// 0x18d0 (PHY_BB_SVD_MEM1_52)
#define PHY_BB_SVD_MEM1_SVD_MEM1_52_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_52_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_52_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_52_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_52_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_52_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_52_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_52_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_52_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_52_RESET                                      0x0
#define PHY_BB_SVD_MEM1_52_ADDRESS                                             (0x18d0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_52_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_52_RESET                                               0x0

// 0x18d4 (PHY_BB_SVD_MEM1_53)
#define PHY_BB_SVD_MEM1_SVD_MEM1_53_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_53_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_53_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_53_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_53_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_53_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_53_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_53_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_53_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_53_RESET                                      0x0
#define PHY_BB_SVD_MEM1_53_ADDRESS                                             (0x18d4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_53_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_53_RESET                                               0x0

// 0x18d8 (PHY_BB_SVD_MEM1_54)
#define PHY_BB_SVD_MEM1_SVD_MEM1_54_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_54_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_54_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_54_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_54_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_54_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_54_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_54_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_54_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_54_RESET                                      0x0
#define PHY_BB_SVD_MEM1_54_ADDRESS                                             (0x18d8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_54_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_54_RESET                                               0x0

// 0x18dc (PHY_BB_SVD_MEM1_55)
#define PHY_BB_SVD_MEM1_SVD_MEM1_55_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_55_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_55_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_55_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_55_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_55_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_55_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_55_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_55_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_55_RESET                                      0x0
#define PHY_BB_SVD_MEM1_55_ADDRESS                                             (0x18dc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_55_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_55_RESET                                               0x0

// 0x18e0 (PHY_BB_SVD_MEM1_56)
#define PHY_BB_SVD_MEM1_SVD_MEM1_56_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_56_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_56_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_56_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_56_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_56_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_56_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_56_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_56_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_56_RESET                                      0x0
#define PHY_BB_SVD_MEM1_56_ADDRESS                                             (0x18e0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_56_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_56_RESET                                               0x0

// 0x18e4 (PHY_BB_SVD_MEM1_57)
#define PHY_BB_SVD_MEM1_SVD_MEM1_57_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_57_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_57_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_57_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_57_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_57_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_57_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_57_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_57_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_57_RESET                                      0x0
#define PHY_BB_SVD_MEM1_57_ADDRESS                                             (0x18e4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_57_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_57_RESET                                               0x0

// 0x18e8 (PHY_BB_SVD_MEM1_58)
#define PHY_BB_SVD_MEM1_SVD_MEM1_58_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_58_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_58_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_58_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_58_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_58_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_58_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_58_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_58_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_58_RESET                                      0x0
#define PHY_BB_SVD_MEM1_58_ADDRESS                                             (0x18e8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_58_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_58_RESET                                               0x0

// 0x18ec (PHY_BB_SVD_MEM1_59)
#define PHY_BB_SVD_MEM1_SVD_MEM1_59_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_59_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_59_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_59_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_59_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_59_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_59_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_59_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_59_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_59_RESET                                      0x0
#define PHY_BB_SVD_MEM1_59_ADDRESS                                             (0x18ec + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_59_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_59_RESET                                               0x0

// 0x18f0 (PHY_BB_SVD_MEM1_60)
#define PHY_BB_SVD_MEM1_SVD_MEM1_60_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_60_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_60_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_60_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_60_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_60_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_60_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_60_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_60_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_60_RESET                                      0x0
#define PHY_BB_SVD_MEM1_60_ADDRESS                                             (0x18f0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_60_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_60_RESET                                               0x0

// 0x18f4 (PHY_BB_SVD_MEM1_61)
#define PHY_BB_SVD_MEM1_SVD_MEM1_61_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_61_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_61_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_61_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_61_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_61_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_61_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_61_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_61_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_61_RESET                                      0x0
#define PHY_BB_SVD_MEM1_61_ADDRESS                                             (0x18f4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_61_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_61_RESET                                               0x0

// 0x18f8 (PHY_BB_SVD_MEM1_62)
#define PHY_BB_SVD_MEM1_SVD_MEM1_62_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_62_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_62_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_62_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_62_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_62_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_62_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_62_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_62_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_62_RESET                                      0x0
#define PHY_BB_SVD_MEM1_62_ADDRESS                                             (0x18f8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_62_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_62_RESET                                               0x0

// 0x18fc (PHY_BB_SVD_MEM1_63)
#define PHY_BB_SVD_MEM1_SVD_MEM1_63_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_63_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_63_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_63_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_63_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_63_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_63_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_63_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_63_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_63_RESET                                      0x0
#define PHY_BB_SVD_MEM1_63_ADDRESS                                             (0x18fc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_63_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_63_RESET                                               0x0

// 0x1900 (PHY_BB_SVD_MEM1_64)
#define PHY_BB_SVD_MEM1_SVD_MEM1_64_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_64_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_64_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_64_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_64_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_64_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_64_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_64_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_64_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_64_RESET                                      0x0
#define PHY_BB_SVD_MEM1_64_ADDRESS                                             (0x1900 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_64_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_64_RESET                                               0x0

// 0x1904 (PHY_BB_SVD_MEM1_65)
#define PHY_BB_SVD_MEM1_SVD_MEM1_65_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_65_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_65_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_65_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_65_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_65_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_65_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_65_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_65_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_65_RESET                                      0x0
#define PHY_BB_SVD_MEM1_65_ADDRESS                                             (0x1904 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_65_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_65_RESET                                               0x0

// 0x1908 (PHY_BB_SVD_MEM1_66)
#define PHY_BB_SVD_MEM1_SVD_MEM1_66_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_66_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_66_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_66_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_66_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_66_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_66_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_66_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_66_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_66_RESET                                      0x0
#define PHY_BB_SVD_MEM1_66_ADDRESS                                             (0x1908 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_66_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_66_RESET                                               0x0

// 0x190c (PHY_BB_SVD_MEM1_67)
#define PHY_BB_SVD_MEM1_SVD_MEM1_67_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_67_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_67_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_67_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_67_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_67_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_67_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_67_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_67_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_67_RESET                                      0x0
#define PHY_BB_SVD_MEM1_67_ADDRESS                                             (0x190c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_67_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_67_RESET                                               0x0

// 0x1910 (PHY_BB_SVD_MEM1_68)
#define PHY_BB_SVD_MEM1_SVD_MEM1_68_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_68_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_68_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_68_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_68_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_68_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_68_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_68_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_68_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_68_RESET                                      0x0
#define PHY_BB_SVD_MEM1_68_ADDRESS                                             (0x1910 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_68_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_68_RESET                                               0x0

// 0x1914 (PHY_BB_SVD_MEM1_69)
#define PHY_BB_SVD_MEM1_SVD_MEM1_69_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_69_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_69_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_69_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_69_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_69_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_69_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_69_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_69_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_69_RESET                                      0x0
#define PHY_BB_SVD_MEM1_69_ADDRESS                                             (0x1914 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_69_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_69_RESET                                               0x0

// 0x1918 (PHY_BB_SVD_MEM1_70)
#define PHY_BB_SVD_MEM1_SVD_MEM1_70_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_70_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_70_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_70_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_70_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_70_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_70_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_70_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_70_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_70_RESET                                      0x0
#define PHY_BB_SVD_MEM1_70_ADDRESS                                             (0x1918 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_70_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_70_RESET                                               0x0

// 0x191c (PHY_BB_SVD_MEM1_71)
#define PHY_BB_SVD_MEM1_SVD_MEM1_71_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_71_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_71_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_71_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_71_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_71_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_71_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_71_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_71_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_71_RESET                                      0x0
#define PHY_BB_SVD_MEM1_71_ADDRESS                                             (0x191c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_71_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_71_RESET                                               0x0

// 0x1920 (PHY_BB_SVD_MEM1_72)
#define PHY_BB_SVD_MEM1_SVD_MEM1_72_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_72_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_72_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_72_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_72_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_72_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_72_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_72_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_72_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_72_RESET                                      0x0
#define PHY_BB_SVD_MEM1_72_ADDRESS                                             (0x1920 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_72_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_72_RESET                                               0x0

// 0x1924 (PHY_BB_SVD_MEM1_73)
#define PHY_BB_SVD_MEM1_SVD_MEM1_73_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_73_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_73_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_73_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_73_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_73_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_73_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_73_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_73_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_73_RESET                                      0x0
#define PHY_BB_SVD_MEM1_73_ADDRESS                                             (0x1924 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_73_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_73_RESET                                               0x0

// 0x1928 (PHY_BB_SVD_MEM1_74)
#define PHY_BB_SVD_MEM1_SVD_MEM1_74_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_74_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_74_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_74_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_74_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_74_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_74_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_74_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_74_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_74_RESET                                      0x0
#define PHY_BB_SVD_MEM1_74_ADDRESS                                             (0x1928 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_74_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_74_RESET                                               0x0

// 0x192c (PHY_BB_SVD_MEM1_75)
#define PHY_BB_SVD_MEM1_SVD_MEM1_75_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_75_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_75_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_75_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_75_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_75_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_75_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_75_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_75_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_75_RESET                                      0x0
#define PHY_BB_SVD_MEM1_75_ADDRESS                                             (0x192c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_75_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_75_RESET                                               0x0

// 0x1930 (PHY_BB_SVD_MEM1_76)
#define PHY_BB_SVD_MEM1_SVD_MEM1_76_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_76_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_76_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_76_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_76_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_76_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_76_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_76_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_76_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_76_RESET                                      0x0
#define PHY_BB_SVD_MEM1_76_ADDRESS                                             (0x1930 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_76_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_76_RESET                                               0x0

// 0x1934 (PHY_BB_SVD_MEM1_77)
#define PHY_BB_SVD_MEM1_SVD_MEM1_77_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_77_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_77_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_77_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_77_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_77_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_77_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_77_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_77_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_77_RESET                                      0x0
#define PHY_BB_SVD_MEM1_77_ADDRESS                                             (0x1934 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_77_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_77_RESET                                               0x0

// 0x1938 (PHY_BB_SVD_MEM1_78)
#define PHY_BB_SVD_MEM1_SVD_MEM1_78_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_78_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_78_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_78_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_78_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_78_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_78_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_78_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_78_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_78_RESET                                      0x0
#define PHY_BB_SVD_MEM1_78_ADDRESS                                             (0x1938 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_78_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_78_RESET                                               0x0

// 0x193c (PHY_BB_SVD_MEM1_79)
#define PHY_BB_SVD_MEM1_SVD_MEM1_79_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_79_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_79_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_79_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_79_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_79_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_79_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_79_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_79_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_79_RESET                                      0x0
#define PHY_BB_SVD_MEM1_79_ADDRESS                                             (0x193c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_79_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_79_RESET                                               0x0

// 0x1940 (PHY_BB_SVD_MEM1_80)
#define PHY_BB_SVD_MEM1_SVD_MEM1_80_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_80_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_80_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_80_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_80_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_80_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_80_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_80_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_80_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_80_RESET                                      0x0
#define PHY_BB_SVD_MEM1_80_ADDRESS                                             (0x1940 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_80_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_80_RESET                                               0x0

// 0x1944 (PHY_BB_SVD_MEM1_81)
#define PHY_BB_SVD_MEM1_SVD_MEM1_81_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_81_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_81_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_81_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_81_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_81_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_81_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_81_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_81_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_81_RESET                                      0x0
#define PHY_BB_SVD_MEM1_81_ADDRESS                                             (0x1944 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_81_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_81_RESET                                               0x0

// 0x1948 (PHY_BB_SVD_MEM1_82)
#define PHY_BB_SVD_MEM1_SVD_MEM1_82_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_82_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_82_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_82_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_82_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_82_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_82_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_82_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_82_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_82_RESET                                      0x0
#define PHY_BB_SVD_MEM1_82_ADDRESS                                             (0x1948 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_82_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_82_RESET                                               0x0

// 0x194c (PHY_BB_SVD_MEM1_83)
#define PHY_BB_SVD_MEM1_SVD_MEM1_83_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_83_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_83_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_83_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_83_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_83_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_83_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_83_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_83_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_83_RESET                                      0x0
#define PHY_BB_SVD_MEM1_83_ADDRESS                                             (0x194c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_83_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_83_RESET                                               0x0

// 0x1950 (PHY_BB_SVD_MEM1_84)
#define PHY_BB_SVD_MEM1_SVD_MEM1_84_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_84_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_84_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_84_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_84_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_84_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_84_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_84_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_84_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_84_RESET                                      0x0
#define PHY_BB_SVD_MEM1_84_ADDRESS                                             (0x1950 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_84_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_84_RESET                                               0x0

// 0x1954 (PHY_BB_SVD_MEM1_85)
#define PHY_BB_SVD_MEM1_SVD_MEM1_85_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_85_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_85_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_85_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_85_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_85_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_85_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_85_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_85_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_85_RESET                                      0x0
#define PHY_BB_SVD_MEM1_85_ADDRESS                                             (0x1954 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_85_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_85_RESET                                               0x0

// 0x1958 (PHY_BB_SVD_MEM1_86)
#define PHY_BB_SVD_MEM1_SVD_MEM1_86_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_86_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_86_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_86_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_86_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_86_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_86_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_86_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_86_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_86_RESET                                      0x0
#define PHY_BB_SVD_MEM1_86_ADDRESS                                             (0x1958 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_86_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_86_RESET                                               0x0

// 0x195c (PHY_BB_SVD_MEM1_87)
#define PHY_BB_SVD_MEM1_SVD_MEM1_87_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_87_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_87_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_87_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_87_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_87_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_87_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_87_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_87_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_87_RESET                                      0x0
#define PHY_BB_SVD_MEM1_87_ADDRESS                                             (0x195c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_87_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_87_RESET                                               0x0

// 0x1960 (PHY_BB_SVD_MEM1_88)
#define PHY_BB_SVD_MEM1_SVD_MEM1_88_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_88_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_88_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_88_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_88_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_88_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_88_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_88_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_88_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_88_RESET                                      0x0
#define PHY_BB_SVD_MEM1_88_ADDRESS                                             (0x1960 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_88_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_88_RESET                                               0x0

// 0x1964 (PHY_BB_SVD_MEM1_89)
#define PHY_BB_SVD_MEM1_SVD_MEM1_89_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_89_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_89_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_89_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_89_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_89_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_89_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_89_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_89_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_89_RESET                                      0x0
#define PHY_BB_SVD_MEM1_89_ADDRESS                                             (0x1964 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_89_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_89_RESET                                               0x0

// 0x1968 (PHY_BB_SVD_MEM1_90)
#define PHY_BB_SVD_MEM1_SVD_MEM1_90_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_90_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_90_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_90_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_90_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_90_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_90_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_90_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_90_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_90_RESET                                      0x0
#define PHY_BB_SVD_MEM1_90_ADDRESS                                             (0x1968 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_90_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_90_RESET                                               0x0

// 0x196c (PHY_BB_SVD_MEM1_91)
#define PHY_BB_SVD_MEM1_SVD_MEM1_91_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_91_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_91_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_91_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_91_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_91_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_91_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_91_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_91_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_91_RESET                                      0x0
#define PHY_BB_SVD_MEM1_91_ADDRESS                                             (0x196c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_91_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_91_RESET                                               0x0

// 0x1970 (PHY_BB_SVD_MEM1_92)
#define PHY_BB_SVD_MEM1_SVD_MEM1_92_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_92_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_92_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_92_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_92_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_92_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_92_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_92_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_92_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_92_RESET                                      0x0
#define PHY_BB_SVD_MEM1_92_ADDRESS                                             (0x1970 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_92_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_92_RESET                                               0x0

// 0x1974 (PHY_BB_SVD_MEM1_93)
#define PHY_BB_SVD_MEM1_SVD_MEM1_93_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_93_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_93_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_93_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_93_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_93_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_93_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_93_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_93_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_93_RESET                                      0x0
#define PHY_BB_SVD_MEM1_93_ADDRESS                                             (0x1974 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_93_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_93_RESET                                               0x0

// 0x1978 (PHY_BB_SVD_MEM1_94)
#define PHY_BB_SVD_MEM1_SVD_MEM1_94_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_94_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_94_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_94_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_94_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_94_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_94_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_94_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_94_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_94_RESET                                      0x0
#define PHY_BB_SVD_MEM1_94_ADDRESS                                             (0x1978 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_94_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_94_RESET                                               0x0

// 0x197c (PHY_BB_SVD_MEM1_95)
#define PHY_BB_SVD_MEM1_SVD_MEM1_95_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_95_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_95_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_95_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_95_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_95_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_95_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_95_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_95_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_95_RESET                                      0x0
#define PHY_BB_SVD_MEM1_95_ADDRESS                                             (0x197c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_95_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_95_RESET                                               0x0

// 0x1980 (PHY_BB_SVD_MEM1_96)
#define PHY_BB_SVD_MEM1_SVD_MEM1_96_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_96_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_96_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_96_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_96_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_96_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_96_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_96_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_96_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_96_RESET                                      0x0
#define PHY_BB_SVD_MEM1_96_ADDRESS                                             (0x1980 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_96_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_96_RESET                                               0x0

// 0x1984 (PHY_BB_SVD_MEM1_97)
#define PHY_BB_SVD_MEM1_SVD_MEM1_97_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_97_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_97_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_97_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_97_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_97_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_97_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_97_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_97_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_97_RESET                                      0x0
#define PHY_BB_SVD_MEM1_97_ADDRESS                                             (0x1984 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_97_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_97_RESET                                               0x0

// 0x1988 (PHY_BB_SVD_MEM1_98)
#define PHY_BB_SVD_MEM1_SVD_MEM1_98_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_98_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_98_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_98_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_98_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_98_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_98_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_98_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_98_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_98_RESET                                      0x0
#define PHY_BB_SVD_MEM1_98_ADDRESS                                             (0x1988 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_98_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_98_RESET                                               0x0

// 0x198c (PHY_BB_SVD_MEM1_99)
#define PHY_BB_SVD_MEM1_SVD_MEM1_99_LSB                                        0
#define PHY_BB_SVD_MEM1_SVD_MEM1_99_MSB                                        31
#define PHY_BB_SVD_MEM1_SVD_MEM1_99_MASK                                       0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_99_GET(x)                                     (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_99_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_99_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_99_SET(x)                                     (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_99_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_99_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_99_RESET                                      0x0
#define PHY_BB_SVD_MEM1_99_ADDRESS                                             (0x198c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_99_RSTMASK                                             0xffffffff
#define PHY_BB_SVD_MEM1_99_RESET                                               0x0

// 0x1990 (PHY_BB_SVD_MEM1_100)
#define PHY_BB_SVD_MEM1_SVD_MEM1_100_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_100_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_100_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_100_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_100_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_100_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_100_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_100_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_100_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_100_RESET                                     0x0
#define PHY_BB_SVD_MEM1_100_ADDRESS                                            (0x1990 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_100_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_100_RESET                                              0x0

// 0x1994 (PHY_BB_SVD_MEM1_101)
#define PHY_BB_SVD_MEM1_SVD_MEM1_101_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_101_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_101_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_101_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_101_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_101_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_101_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_101_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_101_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_101_RESET                                     0x0
#define PHY_BB_SVD_MEM1_101_ADDRESS                                            (0x1994 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_101_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_101_RESET                                              0x0

// 0x1998 (PHY_BB_SVD_MEM1_102)
#define PHY_BB_SVD_MEM1_SVD_MEM1_102_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_102_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_102_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_102_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_102_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_102_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_102_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_102_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_102_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_102_RESET                                     0x0
#define PHY_BB_SVD_MEM1_102_ADDRESS                                            (0x1998 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_102_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_102_RESET                                              0x0

// 0x199c (PHY_BB_SVD_MEM1_103)
#define PHY_BB_SVD_MEM1_SVD_MEM1_103_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_103_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_103_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_103_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_103_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_103_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_103_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_103_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_103_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_103_RESET                                     0x0
#define PHY_BB_SVD_MEM1_103_ADDRESS                                            (0x199c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_103_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_103_RESET                                              0x0

// 0x19a0 (PHY_BB_SVD_MEM1_104)
#define PHY_BB_SVD_MEM1_SVD_MEM1_104_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_104_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_104_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_104_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_104_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_104_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_104_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_104_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_104_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_104_RESET                                     0x0
#define PHY_BB_SVD_MEM1_104_ADDRESS                                            (0x19a0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_104_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_104_RESET                                              0x0

// 0x19a4 (PHY_BB_SVD_MEM1_105)
#define PHY_BB_SVD_MEM1_SVD_MEM1_105_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_105_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_105_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_105_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_105_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_105_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_105_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_105_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_105_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_105_RESET                                     0x0
#define PHY_BB_SVD_MEM1_105_ADDRESS                                            (0x19a4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_105_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_105_RESET                                              0x0

// 0x19a8 (PHY_BB_SVD_MEM1_106)
#define PHY_BB_SVD_MEM1_SVD_MEM1_106_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_106_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_106_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_106_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_106_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_106_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_106_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_106_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_106_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_106_RESET                                     0x0
#define PHY_BB_SVD_MEM1_106_ADDRESS                                            (0x19a8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_106_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_106_RESET                                              0x0

// 0x19ac (PHY_BB_SVD_MEM1_107)
#define PHY_BB_SVD_MEM1_SVD_MEM1_107_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_107_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_107_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_107_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_107_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_107_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_107_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_107_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_107_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_107_RESET                                     0x0
#define PHY_BB_SVD_MEM1_107_ADDRESS                                            (0x19ac + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_107_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_107_RESET                                              0x0

// 0x19b0 (PHY_BB_SVD_MEM1_108)
#define PHY_BB_SVD_MEM1_SVD_MEM1_108_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_108_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_108_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_108_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_108_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_108_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_108_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_108_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_108_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_108_RESET                                     0x0
#define PHY_BB_SVD_MEM1_108_ADDRESS                                            (0x19b0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_108_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_108_RESET                                              0x0

// 0x19b4 (PHY_BB_SVD_MEM1_109)
#define PHY_BB_SVD_MEM1_SVD_MEM1_109_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_109_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_109_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_109_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_109_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_109_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_109_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_109_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_109_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_109_RESET                                     0x0
#define PHY_BB_SVD_MEM1_109_ADDRESS                                            (0x19b4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_109_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_109_RESET                                              0x0

// 0x19b8 (PHY_BB_SVD_MEM1_110)
#define PHY_BB_SVD_MEM1_SVD_MEM1_110_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_110_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_110_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_110_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_110_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_110_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_110_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_110_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_110_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_110_RESET                                     0x0
#define PHY_BB_SVD_MEM1_110_ADDRESS                                            (0x19b8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_110_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_110_RESET                                              0x0

// 0x19bc (PHY_BB_SVD_MEM1_111)
#define PHY_BB_SVD_MEM1_SVD_MEM1_111_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_111_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_111_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_111_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_111_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_111_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_111_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_111_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_111_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_111_RESET                                     0x0
#define PHY_BB_SVD_MEM1_111_ADDRESS                                            (0x19bc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_111_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_111_RESET                                              0x0

// 0x19c0 (PHY_BB_SVD_MEM1_112)
#define PHY_BB_SVD_MEM1_SVD_MEM1_112_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_112_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_112_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_112_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_112_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_112_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_112_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_112_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_112_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_112_RESET                                     0x0
#define PHY_BB_SVD_MEM1_112_ADDRESS                                            (0x19c0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_112_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_112_RESET                                              0x0

// 0x19c4 (PHY_BB_SVD_MEM1_113)
#define PHY_BB_SVD_MEM1_SVD_MEM1_113_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_113_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_113_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_113_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_113_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_113_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_113_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_113_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_113_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_113_RESET                                     0x0
#define PHY_BB_SVD_MEM1_113_ADDRESS                                            (0x19c4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_113_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_113_RESET                                              0x0

// 0x19c8 (PHY_BB_SVD_MEM1_114)
#define PHY_BB_SVD_MEM1_SVD_MEM1_114_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_114_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_114_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_114_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_114_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_114_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_114_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_114_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_114_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_114_RESET                                     0x0
#define PHY_BB_SVD_MEM1_114_ADDRESS                                            (0x19c8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_114_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_114_RESET                                              0x0

// 0x19cc (PHY_BB_SVD_MEM1_115)
#define PHY_BB_SVD_MEM1_SVD_MEM1_115_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_115_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_115_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_115_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_115_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_115_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_115_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_115_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_115_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_115_RESET                                     0x0
#define PHY_BB_SVD_MEM1_115_ADDRESS                                            (0x19cc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_115_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_115_RESET                                              0x0

// 0x19d0 (PHY_BB_SVD_MEM1_116)
#define PHY_BB_SVD_MEM1_SVD_MEM1_116_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_116_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_116_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_116_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_116_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_116_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_116_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_116_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_116_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_116_RESET                                     0x0
#define PHY_BB_SVD_MEM1_116_ADDRESS                                            (0x19d0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_116_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_116_RESET                                              0x0

// 0x19d4 (PHY_BB_SVD_MEM1_117)
#define PHY_BB_SVD_MEM1_SVD_MEM1_117_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_117_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_117_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_117_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_117_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_117_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_117_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_117_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_117_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_117_RESET                                     0x0
#define PHY_BB_SVD_MEM1_117_ADDRESS                                            (0x19d4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_117_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_117_RESET                                              0x0

// 0x19d8 (PHY_BB_SVD_MEM1_118)
#define PHY_BB_SVD_MEM1_SVD_MEM1_118_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_118_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_118_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_118_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_118_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_118_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_118_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_118_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_118_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_118_RESET                                     0x0
#define PHY_BB_SVD_MEM1_118_ADDRESS                                            (0x19d8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_118_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_118_RESET                                              0x0

// 0x19dc (PHY_BB_SVD_MEM1_119)
#define PHY_BB_SVD_MEM1_SVD_MEM1_119_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_119_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_119_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_119_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_119_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_119_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_119_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_119_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_119_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_119_RESET                                     0x0
#define PHY_BB_SVD_MEM1_119_ADDRESS                                            (0x19dc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_119_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_119_RESET                                              0x0

// 0x19e0 (PHY_BB_SVD_MEM1_120)
#define PHY_BB_SVD_MEM1_SVD_MEM1_120_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_120_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_120_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_120_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_120_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_120_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_120_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_120_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_120_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_120_RESET                                     0x0
#define PHY_BB_SVD_MEM1_120_ADDRESS                                            (0x19e0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_120_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_120_RESET                                              0x0

// 0x19e4 (PHY_BB_SVD_MEM1_121)
#define PHY_BB_SVD_MEM1_SVD_MEM1_121_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_121_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_121_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_121_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_121_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_121_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_121_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_121_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_121_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_121_RESET                                     0x0
#define PHY_BB_SVD_MEM1_121_ADDRESS                                            (0x19e4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_121_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_121_RESET                                              0x0

// 0x19e8 (PHY_BB_SVD_MEM1_122)
#define PHY_BB_SVD_MEM1_SVD_MEM1_122_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_122_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_122_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_122_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_122_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_122_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_122_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_122_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_122_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_122_RESET                                     0x0
#define PHY_BB_SVD_MEM1_122_ADDRESS                                            (0x19e8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_122_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_122_RESET                                              0x0

// 0x19ec (PHY_BB_SVD_MEM1_123)
#define PHY_BB_SVD_MEM1_SVD_MEM1_123_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_123_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_123_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_123_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_123_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_123_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_123_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_123_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_123_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_123_RESET                                     0x0
#define PHY_BB_SVD_MEM1_123_ADDRESS                                            (0x19ec + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_123_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_123_RESET                                              0x0

// 0x19f0 (PHY_BB_SVD_MEM1_124)
#define PHY_BB_SVD_MEM1_SVD_MEM1_124_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_124_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_124_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_124_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_124_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_124_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_124_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_124_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_124_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_124_RESET                                     0x0
#define PHY_BB_SVD_MEM1_124_ADDRESS                                            (0x19f0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_124_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_124_RESET                                              0x0

// 0x19f4 (PHY_BB_SVD_MEM1_125)
#define PHY_BB_SVD_MEM1_SVD_MEM1_125_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_125_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_125_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_125_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_125_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_125_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_125_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_125_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_125_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_125_RESET                                     0x0
#define PHY_BB_SVD_MEM1_125_ADDRESS                                            (0x19f4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_125_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_125_RESET                                              0x0

// 0x19f8 (PHY_BB_SVD_MEM1_126)
#define PHY_BB_SVD_MEM1_SVD_MEM1_126_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_126_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_126_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_126_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_126_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_126_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_126_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_126_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_126_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_126_RESET                                     0x0
#define PHY_BB_SVD_MEM1_126_ADDRESS                                            (0x19f8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_126_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_126_RESET                                              0x0

// 0x19fc (PHY_BB_SVD_MEM1_127)
#define PHY_BB_SVD_MEM1_SVD_MEM1_127_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_127_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_127_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_127_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_127_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_127_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_127_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_127_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_127_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_127_RESET                                     0x0
#define PHY_BB_SVD_MEM1_127_ADDRESS                                            (0x19fc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_127_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_127_RESET                                              0x0

// 0x1a00 (PHY_BB_SVD_MEM1_128)
#define PHY_BB_SVD_MEM1_SVD_MEM1_128_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_128_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_128_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_128_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_128_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_128_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_128_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_128_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_128_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_128_RESET                                     0x0
#define PHY_BB_SVD_MEM1_128_ADDRESS                                            (0x1a00 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_128_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_128_RESET                                              0x0

// 0x1a04 (PHY_BB_SVD_MEM1_129)
#define PHY_BB_SVD_MEM1_SVD_MEM1_129_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_129_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_129_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_129_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_129_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_129_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_129_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_129_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_129_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_129_RESET                                     0x0
#define PHY_BB_SVD_MEM1_129_ADDRESS                                            (0x1a04 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_129_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_129_RESET                                              0x0

// 0x1a08 (PHY_BB_SVD_MEM1_130)
#define PHY_BB_SVD_MEM1_SVD_MEM1_130_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_130_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_130_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_130_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_130_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_130_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_130_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_130_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_130_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_130_RESET                                     0x0
#define PHY_BB_SVD_MEM1_130_ADDRESS                                            (0x1a08 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_130_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_130_RESET                                              0x0

// 0x1a0c (PHY_BB_SVD_MEM1_131)
#define PHY_BB_SVD_MEM1_SVD_MEM1_131_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_131_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_131_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_131_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_131_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_131_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_131_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_131_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_131_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_131_RESET                                     0x0
#define PHY_BB_SVD_MEM1_131_ADDRESS                                            (0x1a0c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_131_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_131_RESET                                              0x0

// 0x1a10 (PHY_BB_SVD_MEM1_132)
#define PHY_BB_SVD_MEM1_SVD_MEM1_132_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_132_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_132_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_132_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_132_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_132_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_132_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_132_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_132_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_132_RESET                                     0x0
#define PHY_BB_SVD_MEM1_132_ADDRESS                                            (0x1a10 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_132_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_132_RESET                                              0x0

// 0x1a14 (PHY_BB_SVD_MEM1_133)
#define PHY_BB_SVD_MEM1_SVD_MEM1_133_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_133_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_133_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_133_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_133_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_133_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_133_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_133_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_133_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_133_RESET                                     0x0
#define PHY_BB_SVD_MEM1_133_ADDRESS                                            (0x1a14 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_133_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_133_RESET                                              0x0

// 0x1a18 (PHY_BB_SVD_MEM1_134)
#define PHY_BB_SVD_MEM1_SVD_MEM1_134_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_134_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_134_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_134_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_134_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_134_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_134_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_134_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_134_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_134_RESET                                     0x0
#define PHY_BB_SVD_MEM1_134_ADDRESS                                            (0x1a18 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_134_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_134_RESET                                              0x0

// 0x1a1c (PHY_BB_SVD_MEM1_135)
#define PHY_BB_SVD_MEM1_SVD_MEM1_135_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_135_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_135_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_135_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_135_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_135_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_135_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_135_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_135_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_135_RESET                                     0x0
#define PHY_BB_SVD_MEM1_135_ADDRESS                                            (0x1a1c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_135_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_135_RESET                                              0x0

// 0x1a20 (PHY_BB_SVD_MEM1_136)
#define PHY_BB_SVD_MEM1_SVD_MEM1_136_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_136_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_136_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_136_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_136_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_136_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_136_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_136_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_136_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_136_RESET                                     0x0
#define PHY_BB_SVD_MEM1_136_ADDRESS                                            (0x1a20 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_136_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_136_RESET                                              0x0

// 0x1a24 (PHY_BB_SVD_MEM1_137)
#define PHY_BB_SVD_MEM1_SVD_MEM1_137_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_137_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_137_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_137_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_137_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_137_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_137_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_137_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_137_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_137_RESET                                     0x0
#define PHY_BB_SVD_MEM1_137_ADDRESS                                            (0x1a24 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_137_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_137_RESET                                              0x0

// 0x1a28 (PHY_BB_SVD_MEM1_138)
#define PHY_BB_SVD_MEM1_SVD_MEM1_138_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_138_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_138_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_138_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_138_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_138_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_138_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_138_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_138_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_138_RESET                                     0x0
#define PHY_BB_SVD_MEM1_138_ADDRESS                                            (0x1a28 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_138_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_138_RESET                                              0x0

// 0x1a2c (PHY_BB_SVD_MEM1_139)
#define PHY_BB_SVD_MEM1_SVD_MEM1_139_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_139_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_139_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_139_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_139_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_139_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_139_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_139_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_139_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_139_RESET                                     0x0
#define PHY_BB_SVD_MEM1_139_ADDRESS                                            (0x1a2c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_139_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_139_RESET                                              0x0

// 0x1a30 (PHY_BB_SVD_MEM1_140)
#define PHY_BB_SVD_MEM1_SVD_MEM1_140_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_140_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_140_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_140_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_140_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_140_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_140_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_140_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_140_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_140_RESET                                     0x0
#define PHY_BB_SVD_MEM1_140_ADDRESS                                            (0x1a30 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_140_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_140_RESET                                              0x0

// 0x1a34 (PHY_BB_SVD_MEM1_141)
#define PHY_BB_SVD_MEM1_SVD_MEM1_141_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_141_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_141_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_141_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_141_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_141_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_141_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_141_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_141_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_141_RESET                                     0x0
#define PHY_BB_SVD_MEM1_141_ADDRESS                                            (0x1a34 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_141_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_141_RESET                                              0x0

// 0x1a38 (PHY_BB_SVD_MEM1_142)
#define PHY_BB_SVD_MEM1_SVD_MEM1_142_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_142_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_142_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_142_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_142_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_142_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_142_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_142_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_142_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_142_RESET                                     0x0
#define PHY_BB_SVD_MEM1_142_ADDRESS                                            (0x1a38 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_142_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_142_RESET                                              0x0

// 0x1a3c (PHY_BB_SVD_MEM1_143)
#define PHY_BB_SVD_MEM1_SVD_MEM1_143_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_143_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_143_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_143_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_143_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_143_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_143_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_143_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_143_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_143_RESET                                     0x0
#define PHY_BB_SVD_MEM1_143_ADDRESS                                            (0x1a3c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_143_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_143_RESET                                              0x0

// 0x1a40 (PHY_BB_SVD_MEM1_144)
#define PHY_BB_SVD_MEM1_SVD_MEM1_144_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_144_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_144_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_144_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_144_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_144_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_144_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_144_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_144_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_144_RESET                                     0x0
#define PHY_BB_SVD_MEM1_144_ADDRESS                                            (0x1a40 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_144_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_144_RESET                                              0x0

// 0x1a44 (PHY_BB_SVD_MEM1_145)
#define PHY_BB_SVD_MEM1_SVD_MEM1_145_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_145_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_145_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_145_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_145_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_145_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_145_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_145_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_145_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_145_RESET                                     0x0
#define PHY_BB_SVD_MEM1_145_ADDRESS                                            (0x1a44 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_145_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_145_RESET                                              0x0

// 0x1a48 (PHY_BB_SVD_MEM1_146)
#define PHY_BB_SVD_MEM1_SVD_MEM1_146_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_146_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_146_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_146_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_146_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_146_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_146_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_146_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_146_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_146_RESET                                     0x0
#define PHY_BB_SVD_MEM1_146_ADDRESS                                            (0x1a48 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_146_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_146_RESET                                              0x0

// 0x1a4c (PHY_BB_SVD_MEM1_147)
#define PHY_BB_SVD_MEM1_SVD_MEM1_147_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_147_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_147_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_147_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_147_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_147_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_147_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_147_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_147_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_147_RESET                                     0x0
#define PHY_BB_SVD_MEM1_147_ADDRESS                                            (0x1a4c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_147_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_147_RESET                                              0x0

// 0x1a50 (PHY_BB_SVD_MEM1_148)
#define PHY_BB_SVD_MEM1_SVD_MEM1_148_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_148_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_148_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_148_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_148_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_148_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_148_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_148_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_148_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_148_RESET                                     0x0
#define PHY_BB_SVD_MEM1_148_ADDRESS                                            (0x1a50 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_148_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_148_RESET                                              0x0

// 0x1a54 (PHY_BB_SVD_MEM1_149)
#define PHY_BB_SVD_MEM1_SVD_MEM1_149_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_149_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_149_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_149_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_149_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_149_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_149_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_149_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_149_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_149_RESET                                     0x0
#define PHY_BB_SVD_MEM1_149_ADDRESS                                            (0x1a54 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_149_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_149_RESET                                              0x0

// 0x1a58 (PHY_BB_SVD_MEM1_150)
#define PHY_BB_SVD_MEM1_SVD_MEM1_150_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_150_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_150_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_150_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_150_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_150_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_150_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_150_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_150_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_150_RESET                                     0x0
#define PHY_BB_SVD_MEM1_150_ADDRESS                                            (0x1a58 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_150_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_150_RESET                                              0x0

// 0x1a5c (PHY_BB_SVD_MEM1_151)
#define PHY_BB_SVD_MEM1_SVD_MEM1_151_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_151_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_151_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_151_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_151_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_151_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_151_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_151_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_151_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_151_RESET                                     0x0
#define PHY_BB_SVD_MEM1_151_ADDRESS                                            (0x1a5c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_151_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_151_RESET                                              0x0

// 0x1a60 (PHY_BB_SVD_MEM1_152)
#define PHY_BB_SVD_MEM1_SVD_MEM1_152_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_152_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_152_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_152_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_152_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_152_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_152_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_152_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_152_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_152_RESET                                     0x0
#define PHY_BB_SVD_MEM1_152_ADDRESS                                            (0x1a60 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_152_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_152_RESET                                              0x0

// 0x1a64 (PHY_BB_SVD_MEM1_153)
#define PHY_BB_SVD_MEM1_SVD_MEM1_153_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_153_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_153_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_153_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_153_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_153_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_153_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_153_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_153_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_153_RESET                                     0x0
#define PHY_BB_SVD_MEM1_153_ADDRESS                                            (0x1a64 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_153_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_153_RESET                                              0x0

// 0x1a68 (PHY_BB_SVD_MEM1_154)
#define PHY_BB_SVD_MEM1_SVD_MEM1_154_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_154_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_154_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_154_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_154_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_154_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_154_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_154_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_154_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_154_RESET                                     0x0
#define PHY_BB_SVD_MEM1_154_ADDRESS                                            (0x1a68 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_154_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_154_RESET                                              0x0

// 0x1a6c (PHY_BB_SVD_MEM1_155)
#define PHY_BB_SVD_MEM1_SVD_MEM1_155_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_155_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_155_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_155_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_155_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_155_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_155_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_155_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_155_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_155_RESET                                     0x0
#define PHY_BB_SVD_MEM1_155_ADDRESS                                            (0x1a6c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_155_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_155_RESET                                              0x0

// 0x1a70 (PHY_BB_SVD_MEM1_156)
#define PHY_BB_SVD_MEM1_SVD_MEM1_156_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_156_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_156_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_156_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_156_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_156_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_156_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_156_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_156_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_156_RESET                                     0x0
#define PHY_BB_SVD_MEM1_156_ADDRESS                                            (0x1a70 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_156_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_156_RESET                                              0x0

// 0x1a74 (PHY_BB_SVD_MEM1_157)
#define PHY_BB_SVD_MEM1_SVD_MEM1_157_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_157_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_157_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_157_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_157_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_157_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_157_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_157_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_157_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_157_RESET                                     0x0
#define PHY_BB_SVD_MEM1_157_ADDRESS                                            (0x1a74 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_157_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_157_RESET                                              0x0

// 0x1a78 (PHY_BB_SVD_MEM1_158)
#define PHY_BB_SVD_MEM1_SVD_MEM1_158_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_158_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_158_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_158_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_158_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_158_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_158_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_158_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_158_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_158_RESET                                     0x0
#define PHY_BB_SVD_MEM1_158_ADDRESS                                            (0x1a78 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_158_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_158_RESET                                              0x0

// 0x1a7c (PHY_BB_SVD_MEM1_159)
#define PHY_BB_SVD_MEM1_SVD_MEM1_159_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_159_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_159_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_159_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_159_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_159_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_159_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_159_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_159_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_159_RESET                                     0x0
#define PHY_BB_SVD_MEM1_159_ADDRESS                                            (0x1a7c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_159_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_159_RESET                                              0x0

// 0x1a80 (PHY_BB_SVD_MEM1_160)
#define PHY_BB_SVD_MEM1_SVD_MEM1_160_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_160_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_160_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_160_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_160_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_160_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_160_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_160_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_160_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_160_RESET                                     0x0
#define PHY_BB_SVD_MEM1_160_ADDRESS                                            (0x1a80 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_160_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_160_RESET                                              0x0

// 0x1a84 (PHY_BB_SVD_MEM1_161)
#define PHY_BB_SVD_MEM1_SVD_MEM1_161_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_161_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_161_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_161_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_161_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_161_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_161_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_161_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_161_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_161_RESET                                     0x0
#define PHY_BB_SVD_MEM1_161_ADDRESS                                            (0x1a84 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_161_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_161_RESET                                              0x0

// 0x1a88 (PHY_BB_SVD_MEM1_162)
#define PHY_BB_SVD_MEM1_SVD_MEM1_162_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_162_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_162_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_162_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_162_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_162_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_162_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_162_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_162_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_162_RESET                                     0x0
#define PHY_BB_SVD_MEM1_162_ADDRESS                                            (0x1a88 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_162_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_162_RESET                                              0x0

// 0x1a8c (PHY_BB_SVD_MEM1_163)
#define PHY_BB_SVD_MEM1_SVD_MEM1_163_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_163_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_163_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_163_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_163_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_163_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_163_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_163_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_163_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_163_RESET                                     0x0
#define PHY_BB_SVD_MEM1_163_ADDRESS                                            (0x1a8c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_163_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_163_RESET                                              0x0

// 0x1a90 (PHY_BB_SVD_MEM1_164)
#define PHY_BB_SVD_MEM1_SVD_MEM1_164_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_164_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_164_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_164_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_164_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_164_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_164_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_164_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_164_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_164_RESET                                     0x0
#define PHY_BB_SVD_MEM1_164_ADDRESS                                            (0x1a90 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_164_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_164_RESET                                              0x0

// 0x1a94 (PHY_BB_SVD_MEM1_165)
#define PHY_BB_SVD_MEM1_SVD_MEM1_165_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_165_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_165_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_165_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_165_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_165_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_165_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_165_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_165_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_165_RESET                                     0x0
#define PHY_BB_SVD_MEM1_165_ADDRESS                                            (0x1a94 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_165_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_165_RESET                                              0x0

// 0x1a98 (PHY_BB_SVD_MEM1_166)
#define PHY_BB_SVD_MEM1_SVD_MEM1_166_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_166_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_166_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_166_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_166_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_166_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_166_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_166_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_166_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_166_RESET                                     0x0
#define PHY_BB_SVD_MEM1_166_ADDRESS                                            (0x1a98 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_166_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_166_RESET                                              0x0

// 0x1a9c (PHY_BB_SVD_MEM1_167)
#define PHY_BB_SVD_MEM1_SVD_MEM1_167_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_167_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_167_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_167_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_167_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_167_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_167_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_167_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_167_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_167_RESET                                     0x0
#define PHY_BB_SVD_MEM1_167_ADDRESS                                            (0x1a9c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_167_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_167_RESET                                              0x0

// 0x1aa0 (PHY_BB_SVD_MEM1_168)
#define PHY_BB_SVD_MEM1_SVD_MEM1_168_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_168_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_168_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_168_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_168_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_168_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_168_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_168_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_168_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_168_RESET                                     0x0
#define PHY_BB_SVD_MEM1_168_ADDRESS                                            (0x1aa0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_168_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_168_RESET                                              0x0

// 0x1aa4 (PHY_BB_SVD_MEM1_169)
#define PHY_BB_SVD_MEM1_SVD_MEM1_169_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_169_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_169_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_169_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_169_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_169_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_169_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_169_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_169_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_169_RESET                                     0x0
#define PHY_BB_SVD_MEM1_169_ADDRESS                                            (0x1aa4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_169_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_169_RESET                                              0x0

// 0x1aa8 (PHY_BB_SVD_MEM1_170)
#define PHY_BB_SVD_MEM1_SVD_MEM1_170_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_170_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_170_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_170_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_170_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_170_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_170_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_170_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_170_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_170_RESET                                     0x0
#define PHY_BB_SVD_MEM1_170_ADDRESS                                            (0x1aa8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_170_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_170_RESET                                              0x0

// 0x1aac (PHY_BB_SVD_MEM1_171)
#define PHY_BB_SVD_MEM1_SVD_MEM1_171_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_171_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_171_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_171_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_171_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_171_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_171_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_171_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_171_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_171_RESET                                     0x0
#define PHY_BB_SVD_MEM1_171_ADDRESS                                            (0x1aac + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_171_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_171_RESET                                              0x0

// 0x1ab0 (PHY_BB_SVD_MEM1_172)
#define PHY_BB_SVD_MEM1_SVD_MEM1_172_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_172_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_172_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_172_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_172_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_172_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_172_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_172_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_172_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_172_RESET                                     0x0
#define PHY_BB_SVD_MEM1_172_ADDRESS                                            (0x1ab0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_172_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_172_RESET                                              0x0

// 0x1ab4 (PHY_BB_SVD_MEM1_173)
#define PHY_BB_SVD_MEM1_SVD_MEM1_173_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_173_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_173_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_173_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_173_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_173_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_173_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_173_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_173_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_173_RESET                                     0x0
#define PHY_BB_SVD_MEM1_173_ADDRESS                                            (0x1ab4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_173_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_173_RESET                                              0x0

// 0x1ab8 (PHY_BB_SVD_MEM1_174)
#define PHY_BB_SVD_MEM1_SVD_MEM1_174_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_174_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_174_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_174_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_174_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_174_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_174_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_174_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_174_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_174_RESET                                     0x0
#define PHY_BB_SVD_MEM1_174_ADDRESS                                            (0x1ab8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_174_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_174_RESET                                              0x0

// 0x1abc (PHY_BB_SVD_MEM1_175)
#define PHY_BB_SVD_MEM1_SVD_MEM1_175_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_175_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_175_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_175_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_175_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_175_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_175_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_175_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_175_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_175_RESET                                     0x0
#define PHY_BB_SVD_MEM1_175_ADDRESS                                            (0x1abc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_175_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_175_RESET                                              0x0

// 0x1ac0 (PHY_BB_SVD_MEM1_176)
#define PHY_BB_SVD_MEM1_SVD_MEM1_176_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_176_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_176_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_176_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_176_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_176_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_176_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_176_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_176_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_176_RESET                                     0x0
#define PHY_BB_SVD_MEM1_176_ADDRESS                                            (0x1ac0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_176_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_176_RESET                                              0x0

// 0x1ac4 (PHY_BB_SVD_MEM1_177)
#define PHY_BB_SVD_MEM1_SVD_MEM1_177_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_177_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_177_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_177_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_177_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_177_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_177_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_177_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_177_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_177_RESET                                     0x0
#define PHY_BB_SVD_MEM1_177_ADDRESS                                            (0x1ac4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_177_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_177_RESET                                              0x0

// 0x1ac8 (PHY_BB_SVD_MEM1_178)
#define PHY_BB_SVD_MEM1_SVD_MEM1_178_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_178_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_178_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_178_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_178_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_178_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_178_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_178_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_178_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_178_RESET                                     0x0
#define PHY_BB_SVD_MEM1_178_ADDRESS                                            (0x1ac8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_178_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_178_RESET                                              0x0

// 0x1acc (PHY_BB_SVD_MEM1_179)
#define PHY_BB_SVD_MEM1_SVD_MEM1_179_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_179_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_179_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_179_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_179_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_179_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_179_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_179_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_179_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_179_RESET                                     0x0
#define PHY_BB_SVD_MEM1_179_ADDRESS                                            (0x1acc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_179_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_179_RESET                                              0x0

// 0x1ad0 (PHY_BB_SVD_MEM1_180)
#define PHY_BB_SVD_MEM1_SVD_MEM1_180_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_180_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_180_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_180_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_180_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_180_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_180_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_180_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_180_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_180_RESET                                     0x0
#define PHY_BB_SVD_MEM1_180_ADDRESS                                            (0x1ad0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_180_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_180_RESET                                              0x0

// 0x1ad4 (PHY_BB_SVD_MEM1_181)
#define PHY_BB_SVD_MEM1_SVD_MEM1_181_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_181_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_181_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_181_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_181_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_181_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_181_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_181_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_181_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_181_RESET                                     0x0
#define PHY_BB_SVD_MEM1_181_ADDRESS                                            (0x1ad4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_181_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_181_RESET                                              0x0

// 0x1ad8 (PHY_BB_SVD_MEM1_182)
#define PHY_BB_SVD_MEM1_SVD_MEM1_182_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_182_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_182_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_182_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_182_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_182_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_182_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_182_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_182_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_182_RESET                                     0x0
#define PHY_BB_SVD_MEM1_182_ADDRESS                                            (0x1ad8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_182_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_182_RESET                                              0x0

// 0x1adc (PHY_BB_SVD_MEM1_183)
#define PHY_BB_SVD_MEM1_SVD_MEM1_183_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_183_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_183_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_183_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_183_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_183_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_183_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_183_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_183_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_183_RESET                                     0x0
#define PHY_BB_SVD_MEM1_183_ADDRESS                                            (0x1adc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_183_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_183_RESET                                              0x0

// 0x1ae0 (PHY_BB_SVD_MEM1_184)
#define PHY_BB_SVD_MEM1_SVD_MEM1_184_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_184_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_184_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_184_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_184_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_184_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_184_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_184_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_184_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_184_RESET                                     0x0
#define PHY_BB_SVD_MEM1_184_ADDRESS                                            (0x1ae0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_184_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_184_RESET                                              0x0

// 0x1ae4 (PHY_BB_SVD_MEM1_185)
#define PHY_BB_SVD_MEM1_SVD_MEM1_185_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_185_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_185_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_185_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_185_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_185_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_185_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_185_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_185_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_185_RESET                                     0x0
#define PHY_BB_SVD_MEM1_185_ADDRESS                                            (0x1ae4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_185_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_185_RESET                                              0x0

// 0x1ae8 (PHY_BB_SVD_MEM1_186)
#define PHY_BB_SVD_MEM1_SVD_MEM1_186_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_186_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_186_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_186_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_186_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_186_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_186_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_186_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_186_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_186_RESET                                     0x0
#define PHY_BB_SVD_MEM1_186_ADDRESS                                            (0x1ae8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_186_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_186_RESET                                              0x0

// 0x1aec (PHY_BB_SVD_MEM1_187)
#define PHY_BB_SVD_MEM1_SVD_MEM1_187_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_187_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_187_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_187_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_187_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_187_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_187_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_187_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_187_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_187_RESET                                     0x0
#define PHY_BB_SVD_MEM1_187_ADDRESS                                            (0x1aec + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_187_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_187_RESET                                              0x0

// 0x1af0 (PHY_BB_SVD_MEM1_188)
#define PHY_BB_SVD_MEM1_SVD_MEM1_188_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_188_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_188_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_188_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_188_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_188_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_188_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_188_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_188_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_188_RESET                                     0x0
#define PHY_BB_SVD_MEM1_188_ADDRESS                                            (0x1af0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_188_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_188_RESET                                              0x0

// 0x1af4 (PHY_BB_SVD_MEM1_189)
#define PHY_BB_SVD_MEM1_SVD_MEM1_189_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_189_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_189_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_189_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_189_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_189_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_189_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_189_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_189_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_189_RESET                                     0x0
#define PHY_BB_SVD_MEM1_189_ADDRESS                                            (0x1af4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_189_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_189_RESET                                              0x0

// 0x1af8 (PHY_BB_SVD_MEM1_190)
#define PHY_BB_SVD_MEM1_SVD_MEM1_190_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_190_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_190_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_190_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_190_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_190_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_190_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_190_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_190_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_190_RESET                                     0x0
#define PHY_BB_SVD_MEM1_190_ADDRESS                                            (0x1af8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_190_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_190_RESET                                              0x0

// 0x1afc (PHY_BB_SVD_MEM1_191)
#define PHY_BB_SVD_MEM1_SVD_MEM1_191_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_191_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_191_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_191_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_191_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_191_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_191_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_191_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_191_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_191_RESET                                     0x0
#define PHY_BB_SVD_MEM1_191_ADDRESS                                            (0x1afc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_191_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_191_RESET                                              0x0

// 0x1b00 (PHY_BB_SVD_MEM1_192)
#define PHY_BB_SVD_MEM1_SVD_MEM1_192_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_192_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_192_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_192_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_192_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_192_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_192_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_192_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_192_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_192_RESET                                     0x0
#define PHY_BB_SVD_MEM1_192_ADDRESS                                            (0x1b00 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_192_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_192_RESET                                              0x0

// 0x1b04 (PHY_BB_SVD_MEM1_193)
#define PHY_BB_SVD_MEM1_SVD_MEM1_193_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_193_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_193_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_193_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_193_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_193_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_193_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_193_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_193_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_193_RESET                                     0x0
#define PHY_BB_SVD_MEM1_193_ADDRESS                                            (0x1b04 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_193_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_193_RESET                                              0x0

// 0x1b08 (PHY_BB_SVD_MEM1_194)
#define PHY_BB_SVD_MEM1_SVD_MEM1_194_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_194_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_194_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_194_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_194_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_194_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_194_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_194_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_194_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_194_RESET                                     0x0
#define PHY_BB_SVD_MEM1_194_ADDRESS                                            (0x1b08 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_194_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_194_RESET                                              0x0

// 0x1b0c (PHY_BB_SVD_MEM1_195)
#define PHY_BB_SVD_MEM1_SVD_MEM1_195_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_195_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_195_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_195_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_195_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_195_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_195_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_195_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_195_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_195_RESET                                     0x0
#define PHY_BB_SVD_MEM1_195_ADDRESS                                            (0x1b0c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_195_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_195_RESET                                              0x0

// 0x1b10 (PHY_BB_SVD_MEM1_196)
#define PHY_BB_SVD_MEM1_SVD_MEM1_196_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_196_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_196_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_196_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_196_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_196_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_196_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_196_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_196_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_196_RESET                                     0x0
#define PHY_BB_SVD_MEM1_196_ADDRESS                                            (0x1b10 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_196_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_196_RESET                                              0x0

// 0x1b14 (PHY_BB_SVD_MEM1_197)
#define PHY_BB_SVD_MEM1_SVD_MEM1_197_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_197_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_197_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_197_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_197_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_197_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_197_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_197_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_197_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_197_RESET                                     0x0
#define PHY_BB_SVD_MEM1_197_ADDRESS                                            (0x1b14 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_197_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_197_RESET                                              0x0

// 0x1b18 (PHY_BB_SVD_MEM1_198)
#define PHY_BB_SVD_MEM1_SVD_MEM1_198_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_198_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_198_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_198_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_198_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_198_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_198_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_198_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_198_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_198_RESET                                     0x0
#define PHY_BB_SVD_MEM1_198_ADDRESS                                            (0x1b18 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_198_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_198_RESET                                              0x0

// 0x1b1c (PHY_BB_SVD_MEM1_199)
#define PHY_BB_SVD_MEM1_SVD_MEM1_199_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_199_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_199_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_199_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_199_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_199_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_199_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_199_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_199_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_199_RESET                                     0x0
#define PHY_BB_SVD_MEM1_199_ADDRESS                                            (0x1b1c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_199_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_199_RESET                                              0x0

// 0x1b20 (PHY_BB_SVD_MEM1_200)
#define PHY_BB_SVD_MEM1_SVD_MEM1_200_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_200_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_200_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_200_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_200_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_200_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_200_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_200_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_200_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_200_RESET                                     0x0
#define PHY_BB_SVD_MEM1_200_ADDRESS                                            (0x1b20 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_200_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_200_RESET                                              0x0

// 0x1b24 (PHY_BB_SVD_MEM1_201)
#define PHY_BB_SVD_MEM1_SVD_MEM1_201_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_201_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_201_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_201_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_201_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_201_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_201_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_201_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_201_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_201_RESET                                     0x0
#define PHY_BB_SVD_MEM1_201_ADDRESS                                            (0x1b24 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_201_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_201_RESET                                              0x0

// 0x1b28 (PHY_BB_SVD_MEM1_202)
#define PHY_BB_SVD_MEM1_SVD_MEM1_202_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_202_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_202_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_202_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_202_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_202_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_202_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_202_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_202_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_202_RESET                                     0x0
#define PHY_BB_SVD_MEM1_202_ADDRESS                                            (0x1b28 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_202_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_202_RESET                                              0x0

// 0x1b2c (PHY_BB_SVD_MEM1_203)
#define PHY_BB_SVD_MEM1_SVD_MEM1_203_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_203_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_203_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_203_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_203_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_203_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_203_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_203_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_203_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_203_RESET                                     0x0
#define PHY_BB_SVD_MEM1_203_ADDRESS                                            (0x1b2c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_203_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_203_RESET                                              0x0

// 0x1b30 (PHY_BB_SVD_MEM1_204)
#define PHY_BB_SVD_MEM1_SVD_MEM1_204_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_204_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_204_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_204_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_204_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_204_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_204_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_204_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_204_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_204_RESET                                     0x0
#define PHY_BB_SVD_MEM1_204_ADDRESS                                            (0x1b30 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_204_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_204_RESET                                              0x0

// 0x1b34 (PHY_BB_SVD_MEM1_205)
#define PHY_BB_SVD_MEM1_SVD_MEM1_205_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_205_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_205_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_205_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_205_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_205_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_205_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_205_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_205_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_205_RESET                                     0x0
#define PHY_BB_SVD_MEM1_205_ADDRESS                                            (0x1b34 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_205_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_205_RESET                                              0x0

// 0x1b38 (PHY_BB_SVD_MEM1_206)
#define PHY_BB_SVD_MEM1_SVD_MEM1_206_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_206_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_206_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_206_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_206_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_206_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_206_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_206_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_206_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_206_RESET                                     0x0
#define PHY_BB_SVD_MEM1_206_ADDRESS                                            (0x1b38 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_206_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_206_RESET                                              0x0

// 0x1b3c (PHY_BB_SVD_MEM1_207)
#define PHY_BB_SVD_MEM1_SVD_MEM1_207_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_207_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_207_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_207_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_207_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_207_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_207_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_207_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_207_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_207_RESET                                     0x0
#define PHY_BB_SVD_MEM1_207_ADDRESS                                            (0x1b3c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_207_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_207_RESET                                              0x0

// 0x1b40 (PHY_BB_SVD_MEM1_208)
#define PHY_BB_SVD_MEM1_SVD_MEM1_208_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_208_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_208_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_208_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_208_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_208_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_208_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_208_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_208_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_208_RESET                                     0x0
#define PHY_BB_SVD_MEM1_208_ADDRESS                                            (0x1b40 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_208_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_208_RESET                                              0x0

// 0x1b44 (PHY_BB_SVD_MEM1_209)
#define PHY_BB_SVD_MEM1_SVD_MEM1_209_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_209_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_209_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_209_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_209_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_209_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_209_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_209_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_209_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_209_RESET                                     0x0
#define PHY_BB_SVD_MEM1_209_ADDRESS                                            (0x1b44 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_209_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_209_RESET                                              0x0

// 0x1b48 (PHY_BB_SVD_MEM1_210)
#define PHY_BB_SVD_MEM1_SVD_MEM1_210_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_210_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_210_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_210_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_210_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_210_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_210_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_210_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_210_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_210_RESET                                     0x0
#define PHY_BB_SVD_MEM1_210_ADDRESS                                            (0x1b48 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_210_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_210_RESET                                              0x0

// 0x1b4c (PHY_BB_SVD_MEM1_211)
#define PHY_BB_SVD_MEM1_SVD_MEM1_211_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_211_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_211_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_211_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_211_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_211_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_211_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_211_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_211_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_211_RESET                                     0x0
#define PHY_BB_SVD_MEM1_211_ADDRESS                                            (0x1b4c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_211_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_211_RESET                                              0x0

// 0x1b50 (PHY_BB_SVD_MEM1_212)
#define PHY_BB_SVD_MEM1_SVD_MEM1_212_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_212_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_212_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_212_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_212_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_212_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_212_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_212_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_212_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_212_RESET                                     0x0
#define PHY_BB_SVD_MEM1_212_ADDRESS                                            (0x1b50 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_212_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_212_RESET                                              0x0

// 0x1b54 (PHY_BB_SVD_MEM1_213)
#define PHY_BB_SVD_MEM1_SVD_MEM1_213_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_213_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_213_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_213_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_213_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_213_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_213_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_213_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_213_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_213_RESET                                     0x0
#define PHY_BB_SVD_MEM1_213_ADDRESS                                            (0x1b54 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_213_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_213_RESET                                              0x0

// 0x1b58 (PHY_BB_SVD_MEM1_214)
#define PHY_BB_SVD_MEM1_SVD_MEM1_214_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_214_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_214_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_214_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_214_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_214_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_214_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_214_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_214_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_214_RESET                                     0x0
#define PHY_BB_SVD_MEM1_214_ADDRESS                                            (0x1b58 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_214_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_214_RESET                                              0x0

// 0x1b5c (PHY_BB_SVD_MEM1_215)
#define PHY_BB_SVD_MEM1_SVD_MEM1_215_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_215_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_215_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_215_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_215_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_215_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_215_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_215_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_215_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_215_RESET                                     0x0
#define PHY_BB_SVD_MEM1_215_ADDRESS                                            (0x1b5c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_215_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_215_RESET                                              0x0

// 0x1b60 (PHY_BB_SVD_MEM1_216)
#define PHY_BB_SVD_MEM1_SVD_MEM1_216_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_216_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_216_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_216_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_216_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_216_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_216_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_216_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_216_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_216_RESET                                     0x0
#define PHY_BB_SVD_MEM1_216_ADDRESS                                            (0x1b60 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_216_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_216_RESET                                              0x0

// 0x1b64 (PHY_BB_SVD_MEM1_217)
#define PHY_BB_SVD_MEM1_SVD_MEM1_217_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_217_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_217_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_217_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_217_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_217_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_217_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_217_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_217_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_217_RESET                                     0x0
#define PHY_BB_SVD_MEM1_217_ADDRESS                                            (0x1b64 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_217_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_217_RESET                                              0x0

// 0x1b68 (PHY_BB_SVD_MEM1_218)
#define PHY_BB_SVD_MEM1_SVD_MEM1_218_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_218_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_218_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_218_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_218_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_218_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_218_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_218_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_218_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_218_RESET                                     0x0
#define PHY_BB_SVD_MEM1_218_ADDRESS                                            (0x1b68 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_218_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_218_RESET                                              0x0

// 0x1b6c (PHY_BB_SVD_MEM1_219)
#define PHY_BB_SVD_MEM1_SVD_MEM1_219_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_219_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_219_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_219_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_219_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_219_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_219_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_219_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_219_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_219_RESET                                     0x0
#define PHY_BB_SVD_MEM1_219_ADDRESS                                            (0x1b6c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_219_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_219_RESET                                              0x0

// 0x1b70 (PHY_BB_SVD_MEM1_220)
#define PHY_BB_SVD_MEM1_SVD_MEM1_220_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_220_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_220_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_220_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_220_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_220_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_220_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_220_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_220_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_220_RESET                                     0x0
#define PHY_BB_SVD_MEM1_220_ADDRESS                                            (0x1b70 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_220_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_220_RESET                                              0x0

// 0x1b74 (PHY_BB_SVD_MEM1_221)
#define PHY_BB_SVD_MEM1_SVD_MEM1_221_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_221_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_221_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_221_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_221_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_221_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_221_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_221_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_221_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_221_RESET                                     0x0
#define PHY_BB_SVD_MEM1_221_ADDRESS                                            (0x1b74 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_221_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_221_RESET                                              0x0

// 0x1b78 (PHY_BB_SVD_MEM1_222)
#define PHY_BB_SVD_MEM1_SVD_MEM1_222_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_222_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_222_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_222_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_222_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_222_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_222_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_222_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_222_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_222_RESET                                     0x0
#define PHY_BB_SVD_MEM1_222_ADDRESS                                            (0x1b78 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_222_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_222_RESET                                              0x0

// 0x1b7c (PHY_BB_SVD_MEM1_223)
#define PHY_BB_SVD_MEM1_SVD_MEM1_223_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_223_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_223_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_223_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_223_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_223_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_223_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_223_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_223_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_223_RESET                                     0x0
#define PHY_BB_SVD_MEM1_223_ADDRESS                                            (0x1b7c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_223_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_223_RESET                                              0x0

// 0x1b80 (PHY_BB_SVD_MEM1_224)
#define PHY_BB_SVD_MEM1_SVD_MEM1_224_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_224_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_224_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_224_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_224_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_224_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_224_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_224_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_224_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_224_RESET                                     0x0
#define PHY_BB_SVD_MEM1_224_ADDRESS                                            (0x1b80 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_224_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_224_RESET                                              0x0

// 0x1b84 (PHY_BB_SVD_MEM1_225)
#define PHY_BB_SVD_MEM1_SVD_MEM1_225_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_225_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_225_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_225_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_225_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_225_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_225_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_225_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_225_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_225_RESET                                     0x0
#define PHY_BB_SVD_MEM1_225_ADDRESS                                            (0x1b84 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_225_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_225_RESET                                              0x0

// 0x1b88 (PHY_BB_SVD_MEM1_226)
#define PHY_BB_SVD_MEM1_SVD_MEM1_226_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_226_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_226_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_226_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_226_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_226_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_226_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_226_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_226_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_226_RESET                                     0x0
#define PHY_BB_SVD_MEM1_226_ADDRESS                                            (0x1b88 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_226_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_226_RESET                                              0x0

// 0x1b8c (PHY_BB_SVD_MEM1_227)
#define PHY_BB_SVD_MEM1_SVD_MEM1_227_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_227_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_227_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_227_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_227_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_227_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_227_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_227_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_227_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_227_RESET                                     0x0
#define PHY_BB_SVD_MEM1_227_ADDRESS                                            (0x1b8c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_227_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_227_RESET                                              0x0

// 0x1b90 (PHY_BB_SVD_MEM1_228)
#define PHY_BB_SVD_MEM1_SVD_MEM1_228_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_228_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_228_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_228_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_228_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_228_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_228_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_228_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_228_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_228_RESET                                     0x0
#define PHY_BB_SVD_MEM1_228_ADDRESS                                            (0x1b90 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_228_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_228_RESET                                              0x0

// 0x1b94 (PHY_BB_SVD_MEM1_229)
#define PHY_BB_SVD_MEM1_SVD_MEM1_229_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_229_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_229_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_229_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_229_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_229_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_229_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_229_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_229_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_229_RESET                                     0x0
#define PHY_BB_SVD_MEM1_229_ADDRESS                                            (0x1b94 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_229_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_229_RESET                                              0x0

// 0x1b98 (PHY_BB_SVD_MEM1_230)
#define PHY_BB_SVD_MEM1_SVD_MEM1_230_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_230_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_230_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_230_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_230_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_230_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_230_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_230_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_230_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_230_RESET                                     0x0
#define PHY_BB_SVD_MEM1_230_ADDRESS                                            (0x1b98 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_230_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_230_RESET                                              0x0

// 0x1b9c (PHY_BB_SVD_MEM1_231)
#define PHY_BB_SVD_MEM1_SVD_MEM1_231_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_231_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_231_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_231_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_231_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_231_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_231_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_231_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_231_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_231_RESET                                     0x0
#define PHY_BB_SVD_MEM1_231_ADDRESS                                            (0x1b9c + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_231_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_231_RESET                                              0x0

// 0x1ba0 (PHY_BB_SVD_MEM1_232)
#define PHY_BB_SVD_MEM1_SVD_MEM1_232_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_232_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_232_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_232_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_232_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_232_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_232_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_232_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_232_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_232_RESET                                     0x0
#define PHY_BB_SVD_MEM1_232_ADDRESS                                            (0x1ba0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_232_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_232_RESET                                              0x0

// 0x1ba4 (PHY_BB_SVD_MEM1_233)
#define PHY_BB_SVD_MEM1_SVD_MEM1_233_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_233_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_233_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_233_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_233_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_233_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_233_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_233_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_233_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_233_RESET                                     0x0
#define PHY_BB_SVD_MEM1_233_ADDRESS                                            (0x1ba4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_233_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_233_RESET                                              0x0

// 0x1ba8 (PHY_BB_SVD_MEM1_234)
#define PHY_BB_SVD_MEM1_SVD_MEM1_234_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_234_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_234_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_234_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_234_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_234_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_234_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_234_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_234_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_234_RESET                                     0x0
#define PHY_BB_SVD_MEM1_234_ADDRESS                                            (0x1ba8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_234_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_234_RESET                                              0x0

// 0x1bac (PHY_BB_SVD_MEM1_235)
#define PHY_BB_SVD_MEM1_SVD_MEM1_235_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_235_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_235_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_235_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_235_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_235_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_235_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_235_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_235_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_235_RESET                                     0x0
#define PHY_BB_SVD_MEM1_235_ADDRESS                                            (0x1bac + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_235_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_235_RESET                                              0x0

// 0x1bb0 (PHY_BB_SVD_MEM1_236)
#define PHY_BB_SVD_MEM1_SVD_MEM1_236_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_236_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_236_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_236_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_236_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_236_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_236_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_236_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_236_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_236_RESET                                     0x0
#define PHY_BB_SVD_MEM1_236_ADDRESS                                            (0x1bb0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_236_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_236_RESET                                              0x0

// 0x1bb4 (PHY_BB_SVD_MEM1_237)
#define PHY_BB_SVD_MEM1_SVD_MEM1_237_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_237_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_237_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_237_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_237_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_237_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_237_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_237_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_237_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_237_RESET                                     0x0
#define PHY_BB_SVD_MEM1_237_ADDRESS                                            (0x1bb4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_237_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_237_RESET                                              0x0

// 0x1bb8 (PHY_BB_SVD_MEM1_238)
#define PHY_BB_SVD_MEM1_SVD_MEM1_238_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_238_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_238_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_238_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_238_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_238_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_238_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_238_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_238_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_238_RESET                                     0x0
#define PHY_BB_SVD_MEM1_238_ADDRESS                                            (0x1bb8 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_238_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_238_RESET                                              0x0

// 0x1bbc (PHY_BB_SVD_MEM1_239)
#define PHY_BB_SVD_MEM1_SVD_MEM1_239_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_239_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_239_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_239_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_239_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_239_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_239_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_239_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_239_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_239_RESET                                     0x0
#define PHY_BB_SVD_MEM1_239_ADDRESS                                            (0x1bbc + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_239_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_239_RESET                                              0x0

// 0x1bc0 (PHY_BB_SVD_MEM1_240)
#define PHY_BB_SVD_MEM1_SVD_MEM1_240_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_240_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_240_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_240_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_240_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_240_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_240_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_240_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_240_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_240_RESET                                     0x0
#define PHY_BB_SVD_MEM1_240_ADDRESS                                            (0x1bc0 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_240_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_240_RESET                                              0x0

// 0x1bc4 (PHY_BB_SVD_MEM1_241)
#define PHY_BB_SVD_MEM1_SVD_MEM1_241_LSB                                       0
#define PHY_BB_SVD_MEM1_SVD_MEM1_241_MSB                                       31
#define PHY_BB_SVD_MEM1_SVD_MEM1_241_MASK                                      0xffffffff
#define PHY_BB_SVD_MEM1_SVD_MEM1_241_GET(x)                                    (((x) & PHY_BB_SVD_MEM1_SVD_MEM1_241_MASK) >> PHY_BB_SVD_MEM1_SVD_MEM1_241_LSB)
#define PHY_BB_SVD_MEM1_SVD_MEM1_241_SET(x)                                    (((0 | (x)) << PHY_BB_SVD_MEM1_SVD_MEM1_241_LSB) & PHY_BB_SVD_MEM1_SVD_MEM1_241_MASK)
#define PHY_BB_SVD_MEM1_SVD_MEM1_241_RESET                                     0x0
#define PHY_BB_SVD_MEM1_241_ADDRESS                                            (0x1bc4 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_MEM1_241_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_MEM1_241_RESET                                              0x0

// 0x2000 (PHY_BB_SVD_SPARE_01)
#define PHY_BB_SVD_SPARE_01_SVD_ECO_CTRL_LSB                                   5
#define PHY_BB_SVD_SPARE_01_SVD_ECO_CTRL_MSB                                   31
#define PHY_BB_SVD_SPARE_01_SVD_ECO_CTRL_MASK                                  0xffffffe0
#define PHY_BB_SVD_SPARE_01_SVD_ECO_CTRL_GET(x)                                (((x) & PHY_BB_SVD_SPARE_01_SVD_ECO_CTRL_MASK) >> PHY_BB_SVD_SPARE_01_SVD_ECO_CTRL_LSB)
#define PHY_BB_SVD_SPARE_01_SVD_ECO_CTRL_SET(x)                                (((0 | (x)) << PHY_BB_SVD_SPARE_01_SVD_ECO_CTRL_LSB) & PHY_BB_SVD_SPARE_01_SVD_ECO_CTRL_MASK)
#define PHY_BB_SVD_SPARE_01_SVD_ECO_CTRL_RESET                                 0x0
#define PHY_BB_SVD_SPARE_01_CVMEM_NUM_EXTRA_WRITES_LSB                         0
#define PHY_BB_SVD_SPARE_01_CVMEM_NUM_EXTRA_WRITES_MSB                         4
#define PHY_BB_SVD_SPARE_01_CVMEM_NUM_EXTRA_WRITES_MASK                        0x1f
#define PHY_BB_SVD_SPARE_01_CVMEM_NUM_EXTRA_WRITES_GET(x)                      (((x) & PHY_BB_SVD_SPARE_01_CVMEM_NUM_EXTRA_WRITES_MASK) >> PHY_BB_SVD_SPARE_01_CVMEM_NUM_EXTRA_WRITES_LSB)
#define PHY_BB_SVD_SPARE_01_CVMEM_NUM_EXTRA_WRITES_SET(x)                      (((0 | (x)) << PHY_BB_SVD_SPARE_01_CVMEM_NUM_EXTRA_WRITES_LSB) & PHY_BB_SVD_SPARE_01_CVMEM_NUM_EXTRA_WRITES_MASK)
#define PHY_BB_SVD_SPARE_01_CVMEM_NUM_EXTRA_WRITES_RESET                       0x4
#define PHY_BB_SVD_SPARE_01_ADDRESS                                            (0x2000 + __PHY_SVD_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SVD_SPARE_01_RSTMASK                                            0xffffffff
#define PHY_BB_SVD_SPARE_01_RESET                                              0x4



#endif /* _PHY_SVD_REG_MAP_H_ */
