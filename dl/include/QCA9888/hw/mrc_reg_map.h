/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _PHY_MRC_REG_MAP_H_
#define _PHY_MRC_REG_MAP_H_


#ifndef __PHY_MRC_REG_MAP_BASE_ADDRESS
#define __PHY_MRC_REG_MAP_BASE_ADDRESS (0x18000)
#endif


// 0x0 (PHY_BB_TIMING_CONTROL_3A)
#define PHY_BB_TIMING_CONTROL_3A_STE_TO_LONG1_VH_RSSI_LSB                      25
#define PHY_BB_TIMING_CONTROL_3A_STE_TO_LONG1_VH_RSSI_MSB                      30
#define PHY_BB_TIMING_CONTROL_3A_STE_TO_LONG1_VH_RSSI_MASK                     0x7e000000
#define PHY_BB_TIMING_CONTROL_3A_STE_TO_LONG1_VH_RSSI_GET(x)                   (((x) & PHY_BB_TIMING_CONTROL_3A_STE_TO_LONG1_VH_RSSI_MASK) >> PHY_BB_TIMING_CONTROL_3A_STE_TO_LONG1_VH_RSSI_LSB)
#define PHY_BB_TIMING_CONTROL_3A_STE_TO_LONG1_VH_RSSI_SET(x)                   (((0 | (x)) << PHY_BB_TIMING_CONTROL_3A_STE_TO_LONG1_VH_RSSI_LSB) & PHY_BB_TIMING_CONTROL_3A_STE_TO_LONG1_VH_RSSI_MASK)
#define PHY_BB_TIMING_CONTROL_3A_STE_TO_LONG1_VH_RSSI_RESET                    0x1c
#define PHY_BB_TIMING_CONTROL_3A_STE_THR_VH_RSSI_LSB                           18
#define PHY_BB_TIMING_CONTROL_3A_STE_THR_VH_RSSI_MSB                           24
#define PHY_BB_TIMING_CONTROL_3A_STE_THR_VH_RSSI_MASK                          0x1fc0000
#define PHY_BB_TIMING_CONTROL_3A_STE_THR_VH_RSSI_GET(x)                        (((x) & PHY_BB_TIMING_CONTROL_3A_STE_THR_VH_RSSI_MASK) >> PHY_BB_TIMING_CONTROL_3A_STE_THR_VH_RSSI_LSB)
#define PHY_BB_TIMING_CONTROL_3A_STE_THR_VH_RSSI_SET(x)                        (((0 | (x)) << PHY_BB_TIMING_CONTROL_3A_STE_THR_VH_RSSI_LSB) & PHY_BB_TIMING_CONTROL_3A_STE_THR_VH_RSSI_MASK)
#define PHY_BB_TIMING_CONTROL_3A_STE_THR_VH_RSSI_RESET                         0x7d
#define PHY_BB_TIMING_CONTROL_3A_VH_RSSI_THRESH_LSB                            11
#define PHY_BB_TIMING_CONTROL_3A_VH_RSSI_THRESH_MSB                            17
#define PHY_BB_TIMING_CONTROL_3A_VH_RSSI_THRESH_MASK                           0x3f800
#define PHY_BB_TIMING_CONTROL_3A_VH_RSSI_THRESH_GET(x)                         (((x) & PHY_BB_TIMING_CONTROL_3A_VH_RSSI_THRESH_MASK) >> PHY_BB_TIMING_CONTROL_3A_VH_RSSI_THRESH_LSB)
#define PHY_BB_TIMING_CONTROL_3A_VH_RSSI_THRESH_SET(x)                         (((0 | (x)) << PHY_BB_TIMING_CONTROL_3A_VH_RSSI_THRESH_LSB) & PHY_BB_TIMING_CONTROL_3A_VH_RSSI_THRESH_MASK)
#define PHY_BB_TIMING_CONTROL_3A_VH_RSSI_THRESH_RESET                          0x1a
#define PHY_BB_TIMING_CONTROL_3A_DISABLE_FTE_HIGH_SNR_LSB                      10
#define PHY_BB_TIMING_CONTROL_3A_DISABLE_FTE_HIGH_SNR_MSB                      10
#define PHY_BB_TIMING_CONTROL_3A_DISABLE_FTE_HIGH_SNR_MASK                     0x400
#define PHY_BB_TIMING_CONTROL_3A_DISABLE_FTE_HIGH_SNR_GET(x)                   (((x) & PHY_BB_TIMING_CONTROL_3A_DISABLE_FTE_HIGH_SNR_MASK) >> PHY_BB_TIMING_CONTROL_3A_DISABLE_FTE_HIGH_SNR_LSB)
#define PHY_BB_TIMING_CONTROL_3A_DISABLE_FTE_HIGH_SNR_SET(x)                   (((0 | (x)) << PHY_BB_TIMING_CONTROL_3A_DISABLE_FTE_HIGH_SNR_LSB) & PHY_BB_TIMING_CONTROL_3A_DISABLE_FTE_HIGH_SNR_MASK)
#define PHY_BB_TIMING_CONTROL_3A_DISABLE_FTE_HIGH_SNR_RESET                    0x0
#define PHY_BB_TIMING_CONTROL_3A_USE_NON_HT_BW_FOR_CCA_LSB                     9
#define PHY_BB_TIMING_CONTROL_3A_USE_NON_HT_BW_FOR_CCA_MSB                     9
#define PHY_BB_TIMING_CONTROL_3A_USE_NON_HT_BW_FOR_CCA_MASK                    0x200
#define PHY_BB_TIMING_CONTROL_3A_USE_NON_HT_BW_FOR_CCA_GET(x)                  (((x) & PHY_BB_TIMING_CONTROL_3A_USE_NON_HT_BW_FOR_CCA_MASK) >> PHY_BB_TIMING_CONTROL_3A_USE_NON_HT_BW_FOR_CCA_LSB)
#define PHY_BB_TIMING_CONTROL_3A_USE_NON_HT_BW_FOR_CCA_SET(x)                  (((0 | (x)) << PHY_BB_TIMING_CONTROL_3A_USE_NON_HT_BW_FOR_CCA_LSB) & PHY_BB_TIMING_CONTROL_3A_USE_NON_HT_BW_FOR_CCA_MASK)
#define PHY_BB_TIMING_CONTROL_3A_USE_NON_HT_BW_FOR_CCA_RESET                   0x0
#define PHY_BB_TIMING_CONTROL_3A_USE_VHT_BW_FOR_CCA_LSB                        8
#define PHY_BB_TIMING_CONTROL_3A_USE_VHT_BW_FOR_CCA_MSB                        8
#define PHY_BB_TIMING_CONTROL_3A_USE_VHT_BW_FOR_CCA_MASK                       0x100
#define PHY_BB_TIMING_CONTROL_3A_USE_VHT_BW_FOR_CCA_GET(x)                     (((x) & PHY_BB_TIMING_CONTROL_3A_USE_VHT_BW_FOR_CCA_MASK) >> PHY_BB_TIMING_CONTROL_3A_USE_VHT_BW_FOR_CCA_LSB)
#define PHY_BB_TIMING_CONTROL_3A_USE_VHT_BW_FOR_CCA_SET(x)                     (((0 | (x)) << PHY_BB_TIMING_CONTROL_3A_USE_VHT_BW_FOR_CCA_LSB) & PHY_BB_TIMING_CONTROL_3A_USE_VHT_BW_FOR_CCA_MASK)
#define PHY_BB_TIMING_CONTROL_3A_USE_VHT_BW_FOR_CCA_RESET                      0x1
#define PHY_BB_TIMING_CONTROL_3A_STE_THR_HI_RSSI_LSB                           0
#define PHY_BB_TIMING_CONTROL_3A_STE_THR_HI_RSSI_MSB                           6
#define PHY_BB_TIMING_CONTROL_3A_STE_THR_HI_RSSI_MASK                          0x7f
#define PHY_BB_TIMING_CONTROL_3A_STE_THR_HI_RSSI_GET(x)                        (((x) & PHY_BB_TIMING_CONTROL_3A_STE_THR_HI_RSSI_MASK) >> PHY_BB_TIMING_CONTROL_3A_STE_THR_HI_RSSI_LSB)
#define PHY_BB_TIMING_CONTROL_3A_STE_THR_HI_RSSI_SET(x)                        (((0 | (x)) << PHY_BB_TIMING_CONTROL_3A_STE_THR_HI_RSSI_LSB) & PHY_BB_TIMING_CONTROL_3A_STE_THR_HI_RSSI_MASK)
#define PHY_BB_TIMING_CONTROL_3A_STE_THR_HI_RSSI_RESET                         0x0
#define PHY_BB_TIMING_CONTROL_3A_ADDRESS                                       (0x0 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TIMING_CONTROL_3A_RSTMASK                                       0x7fffff7f
#define PHY_BB_TIMING_CONTROL_3A_RESET                                         0x39f4d100

// 0x4 (PHY_BB_LDPC_CNTL1)
#define PHY_BB_LDPC_CNTL1_LDPC_LLR_SCALING0_LSB                                0
#define PHY_BB_LDPC_CNTL1_LDPC_LLR_SCALING0_MSB                                31
#define PHY_BB_LDPC_CNTL1_LDPC_LLR_SCALING0_MASK                               0xffffffff
#define PHY_BB_LDPC_CNTL1_LDPC_LLR_SCALING0_GET(x)                             (((x) & PHY_BB_LDPC_CNTL1_LDPC_LLR_SCALING0_MASK) >> PHY_BB_LDPC_CNTL1_LDPC_LLR_SCALING0_LSB)
#define PHY_BB_LDPC_CNTL1_LDPC_LLR_SCALING0_SET(x)                             (((0 | (x)) << PHY_BB_LDPC_CNTL1_LDPC_LLR_SCALING0_LSB) & PHY_BB_LDPC_CNTL1_LDPC_LLR_SCALING0_MASK)
#define PHY_BB_LDPC_CNTL1_LDPC_LLR_SCALING0_RESET                              0x15ffd55
#define PHY_BB_LDPC_CNTL1_ADDRESS                                              (0x4 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_LDPC_CNTL1_RSTMASK                                              0xffffffff
#define PHY_BB_LDPC_CNTL1_RESET                                                0x15ffd55

// 0x8 (PHY_BB_LDPC_CNTL2)
#define PHY_BB_LDPC_CNTL2_DISABLE_LDPC_MEM_PD_LSB                              29
#define PHY_BB_LDPC_CNTL2_DISABLE_LDPC_MEM_PD_MSB                              29
#define PHY_BB_LDPC_CNTL2_DISABLE_LDPC_MEM_PD_MASK                             0x20000000
#define PHY_BB_LDPC_CNTL2_DISABLE_LDPC_MEM_PD_GET(x)                           (((x) & PHY_BB_LDPC_CNTL2_DISABLE_LDPC_MEM_PD_MASK) >> PHY_BB_LDPC_CNTL2_DISABLE_LDPC_MEM_PD_LSB)
#define PHY_BB_LDPC_CNTL2_DISABLE_LDPC_MEM_PD_SET(x)                           (((0 | (x)) << PHY_BB_LDPC_CNTL2_DISABLE_LDPC_MEM_PD_LSB) & PHY_BB_LDPC_CNTL2_DISABLE_LDPC_MEM_PD_MASK)
#define PHY_BB_LDPC_CNTL2_DISABLE_LDPC_MEM_PD_RESET                            0x0
#define PHY_BB_LDPC_CNTL2_ENABLE_ITER_CAL_LSB                                  28
#define PHY_BB_LDPC_CNTL2_ENABLE_ITER_CAL_MSB                                  28
#define PHY_BB_LDPC_CNTL2_ENABLE_ITER_CAL_MASK                                 0x10000000
#define PHY_BB_LDPC_CNTL2_ENABLE_ITER_CAL_GET(x)                               (((x) & PHY_BB_LDPC_CNTL2_ENABLE_ITER_CAL_MASK) >> PHY_BB_LDPC_CNTL2_ENABLE_ITER_CAL_LSB)
#define PHY_BB_LDPC_CNTL2_ENABLE_ITER_CAL_SET(x)                               (((0 | (x)) << PHY_BB_LDPC_CNTL2_ENABLE_ITER_CAL_LSB) & PHY_BB_LDPC_CNTL2_ENABLE_ITER_CAL_MASK)
#define PHY_BB_LDPC_CNTL2_ENABLE_ITER_CAL_RESET                                0x0
#define PHY_BB_LDPC_CNTL2_DISABLE_LDPC_DEC_LSB                                 27
#define PHY_BB_LDPC_CNTL2_DISABLE_LDPC_DEC_MSB                                 27
#define PHY_BB_LDPC_CNTL2_DISABLE_LDPC_DEC_MASK                                0x8000000
#define PHY_BB_LDPC_CNTL2_DISABLE_LDPC_DEC_GET(x)                              (((x) & PHY_BB_LDPC_CNTL2_DISABLE_LDPC_DEC_MASK) >> PHY_BB_LDPC_CNTL2_DISABLE_LDPC_DEC_LSB)
#define PHY_BB_LDPC_CNTL2_DISABLE_LDPC_DEC_SET(x)                              (((0 | (x)) << PHY_BB_LDPC_CNTL2_DISABLE_LDPC_DEC_LSB) & PHY_BB_LDPC_CNTL2_DISABLE_LDPC_DEC_MASK)
#define PHY_BB_LDPC_CNTL2_DISABLE_LDPC_DEC_RESET                               0x0
#define PHY_BB_LDPC_CNTL2_LDPC_LATENCY_LASTCW_LSB                              16
#define PHY_BB_LDPC_CNTL2_LDPC_LATENCY_LASTCW_MSB                              26
#define PHY_BB_LDPC_CNTL2_LDPC_LATENCY_LASTCW_MASK                             0x7ff0000
#define PHY_BB_LDPC_CNTL2_LDPC_LATENCY_LASTCW_GET(x)                           (((x) & PHY_BB_LDPC_CNTL2_LDPC_LATENCY_LASTCW_MASK) >> PHY_BB_LDPC_CNTL2_LDPC_LATENCY_LASTCW_LSB)
#define PHY_BB_LDPC_CNTL2_LDPC_LATENCY_LASTCW_SET(x)                           (((0 | (x)) << PHY_BB_LDPC_CNTL2_LDPC_LATENCY_LASTCW_LSB) & PHY_BB_LDPC_CNTL2_LDPC_LATENCY_LASTCW_MASK)
#define PHY_BB_LDPC_CNTL2_LDPC_LATENCY_LASTCW_RESET                            0x320
#define PHY_BB_LDPC_CNTL2_LDPC_LLR_SCALING1_LSB                                0
#define PHY_BB_LDPC_CNTL2_LDPC_LLR_SCALING1_MSB                                15
#define PHY_BB_LDPC_CNTL2_LDPC_LLR_SCALING1_MASK                               0xffff
#define PHY_BB_LDPC_CNTL2_LDPC_LLR_SCALING1_GET(x)                             (((x) & PHY_BB_LDPC_CNTL2_LDPC_LLR_SCALING1_MASK) >> PHY_BB_LDPC_CNTL2_LDPC_LLR_SCALING1_LSB)
#define PHY_BB_LDPC_CNTL2_LDPC_LLR_SCALING1_SET(x)                             (((0 | (x)) << PHY_BB_LDPC_CNTL2_LDPC_LLR_SCALING1_LSB) & PHY_BB_LDPC_CNTL2_LDPC_LLR_SCALING1_MASK)
#define PHY_BB_LDPC_CNTL2_LDPC_LLR_SCALING1_RESET                              0x0
#define PHY_BB_LDPC_CNTL2_ADDRESS                                              (0x8 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_LDPC_CNTL2_RSTMASK                                              0x3fffffff
#define PHY_BB_LDPC_CNTL2_RESET                                                0x3200000

// 0xc (PHY_BB_VIT_SPUR_MASK_A)
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_SEL_LSB                          18
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_SEL_MSB                          18
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_SEL_MASK                         0x40000
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_SEL_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_SEL_MASK) >> PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_SEL_LSB)
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_SEL_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_SEL_LSB) & PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_SEL_MASK)
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_SEL_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_IDX_A_LSB                          10
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_IDX_A_MSB                          17
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_IDX_A_MASK                         0x3fc00
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_IDX_A_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_IDX_A_MASK) >> PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_IDX_A_LSB)
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_IDX_A_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_IDX_A_LSB) & PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_IDX_A_MASK)
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_IDX_A_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_LSB                              0
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_MSB                              9
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_MASK                             0x3ff
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_GET(x)                           (((x) & PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_MASK) >> PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_LSB)
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_SET(x)                           (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_LSB) & PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_MASK)
#define PHY_BB_VIT_SPUR_MASK_A_CF_PUNC_MASK_A_RESET                            0x0
#define PHY_BB_VIT_SPUR_MASK_A_ADDRESS                                         (0xc + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_VIT_SPUR_MASK_A_RSTMASK                                         0x7ffff
#define PHY_BB_VIT_SPUR_MASK_A_RESET                                           0x0

// 0x10 (PHY_BB_VIT_SPUR_MASK_B)
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_SEL_LSB                          18
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_SEL_MSB                          18
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_SEL_MASK                         0x40000
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_SEL_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_SEL_MASK) >> PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_SEL_LSB)
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_SEL_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_SEL_LSB) & PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_SEL_MASK)
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_SEL_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_IDX_B_LSB                          10
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_IDX_B_MSB                          17
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_IDX_B_MASK                         0x3fc00
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_IDX_B_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_IDX_B_MASK) >> PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_IDX_B_LSB)
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_IDX_B_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_IDX_B_LSB) & PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_IDX_B_MASK)
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_IDX_B_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_LSB                              0
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_MSB                              9
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_MASK                             0x3ff
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_GET(x)                           (((x) & PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_MASK) >> PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_LSB)
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_SET(x)                           (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_LSB) & PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_MASK)
#define PHY_BB_VIT_SPUR_MASK_B_CF_PUNC_MASK_B_RESET                            0x0
#define PHY_BB_VIT_SPUR_MASK_B_ADDRESS                                         (0x10 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_VIT_SPUR_MASK_B_RSTMASK                                         0x7ffff
#define PHY_BB_VIT_SPUR_MASK_B_RESET                                           0x0

// 0x14 (PHY_BB_PILOT_SPUR_MASK)
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_SEL_LSB                         27
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_SEL_MSB                         27
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_SEL_MASK                        0x8000000
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_SEL_GET(x)                      (((x) & PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_SEL_MASK) >> PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_SEL_LSB)
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_SEL_SET(x)                      (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_SEL_LSB) & PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_SEL_MASK)
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_SEL_RESET                       0x0
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_SEL_LSB                         26
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_SEL_MSB                         26
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_SEL_MASK                        0x4000000
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_SEL_GET(x)                      (((x) & PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_SEL_MASK) >> PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_SEL_LSB)
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_SEL_SET(x)                      (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_SEL_LSB) & PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_SEL_MASK)
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_SEL_RESET                       0x0
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_B_LSB                         18
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_B_MSB                         25
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_B_MASK                        0x3fc0000
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_B_GET(x)                      (((x) & PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_B_MASK) >> PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_B_LSB)
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_B_SET(x)                      (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_B_LSB) & PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_B_MASK)
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_B_RESET                       0x0
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_LSB                             13
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_MSB                             17
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_MASK                            0x3e000
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_GET(x)                          (((x) & PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_MASK) >> PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_LSB)
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_SET(x)                          (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_LSB) & PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_MASK)
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_B_RESET                           0x0
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_A_LSB                         5
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_A_MSB                         12
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_A_MASK                        0x1fe0
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_A_GET(x)                      (((x) & PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_A_MASK) >> PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_A_LSB)
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_A_SET(x)                      (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_A_LSB) & PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_A_MASK)
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_A_RESET                       0x0
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_LSB                             0
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_MSB                             4
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_MASK                            0x1f
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_GET(x)                          (((x) & PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_MASK) >> PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_LSB)
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_SET(x)                          (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_LSB) & PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_MASK)
#define PHY_BB_PILOT_SPUR_MASK_CF_PILOT_MASK_A_RESET                           0x0
#define PHY_BB_PILOT_SPUR_MASK_ADDRESS                                         (0x14 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_PILOT_SPUR_MASK_RSTMASK                                         0xfffffff
#define PHY_BB_PILOT_SPUR_MASK_RESET                                           0x0

// 0x18 (PHY_BB_CHAN_SPUR_MASK)
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_SEL_LSB                           27
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_SEL_MSB                           27
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_SEL_MASK                          0x8000000
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_SEL_GET(x)                        (((x) & PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_SEL_MASK) >> PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_SEL_LSB)
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_SEL_SET(x)                        (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_SEL_LSB) & PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_SEL_MASK)
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_SEL_RESET                         0x0
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_SEL_LSB                           26
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_SEL_MSB                           26
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_SEL_MASK                          0x4000000
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_SEL_GET(x)                        (((x) & PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_SEL_MASK) >> PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_SEL_LSB)
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_SEL_SET(x)                        (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_SEL_LSB) & PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_SEL_MASK)
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_SEL_RESET                         0x0
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_B_LSB                           18
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_B_MSB                           25
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_B_MASK                          0x3fc0000
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_B_GET(x)                        (((x) & PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_B_MASK) >> PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_B_LSB)
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_B_SET(x)                        (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_B_LSB) & PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_B_MASK)
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_B_RESET                         0x0
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_LSB                               13
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_MSB                               17
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_MASK                              0x3e000
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_GET(x)                            (((x) & PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_MASK) >> PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_LSB)
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_SET(x)                            (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_LSB) & PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_MASK)
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_B_RESET                             0x0
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_A_LSB                           5
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_A_MSB                           12
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_A_MASK                          0x1fe0
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_A_GET(x)                        (((x) & PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_A_MASK) >> PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_A_LSB)
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_A_SET(x)                        (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_A_LSB) & PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_A_MASK)
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_A_RESET                         0x0
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_LSB                               0
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_MSB                               4
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_MASK                              0x1f
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_GET(x)                            (((x) & PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_MASK) >> PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_LSB)
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_SET(x)                            (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_LSB) & PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_MASK)
#define PHY_BB_CHAN_SPUR_MASK_CF_CHAN_MASK_A_RESET                             0x0
#define PHY_BB_CHAN_SPUR_MASK_ADDRESS                                          (0x18 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CHAN_SPUR_MASK_RSTMASK                                          0xfffffff
#define PHY_BB_CHAN_SPUR_MASK_RESET                                            0x0

// 0x1c (PHY_BB_SHORT_GI_DELTA_SLOPE)
#define PHY_BB_SHORT_GI_DELTA_SLOPE_FORCED_LFTE_SKIP_LSB                       19
#define PHY_BB_SHORT_GI_DELTA_SLOPE_FORCED_LFTE_SKIP_MSB                       24
#define PHY_BB_SHORT_GI_DELTA_SLOPE_FORCED_LFTE_SKIP_MASK                      0x1f80000
#define PHY_BB_SHORT_GI_DELTA_SLOPE_FORCED_LFTE_SKIP_GET(x)                    (((x) & PHY_BB_SHORT_GI_DELTA_SLOPE_FORCED_LFTE_SKIP_MASK) >> PHY_BB_SHORT_GI_DELTA_SLOPE_FORCED_LFTE_SKIP_LSB)
#define PHY_BB_SHORT_GI_DELTA_SLOPE_FORCED_LFTE_SKIP_SET(x)                    (((0 | (x)) << PHY_BB_SHORT_GI_DELTA_SLOPE_FORCED_LFTE_SKIP_LSB) & PHY_BB_SHORT_GI_DELTA_SLOPE_FORCED_LFTE_SKIP_MASK)
#define PHY_BB_SHORT_GI_DELTA_SLOPE_FORCED_LFTE_SKIP_RESET                     0x0
#define PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_MAN_SHORT_GI_LSB          4
#define PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_MAN_SHORT_GI_MSB          18
#define PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_MAN_SHORT_GI_MASK         0x7fff0
#define PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_MAN_SHORT_GI_GET(x)       (((x) & PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_MAN_SHORT_GI_MASK) >> PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_MAN_SHORT_GI_LSB)
#define PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_MAN_SHORT_GI_SET(x)       (((0 | (x)) << PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_MAN_SHORT_GI_LSB) & PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_MAN_SHORT_GI_MASK)
#define PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_MAN_SHORT_GI_RESET        0x0
#define PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_EXP_SHORT_GI_LSB          0
#define PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_EXP_SHORT_GI_MSB          3
#define PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_EXP_SHORT_GI_MASK         0xf
#define PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_EXP_SHORT_GI_GET(x)       (((x) & PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_EXP_SHORT_GI_MASK) >> PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_EXP_SHORT_GI_LSB)
#define PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_EXP_SHORT_GI_SET(x)       (((0 | (x)) << PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_EXP_SHORT_GI_LSB) & PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_EXP_SHORT_GI_MASK)
#define PHY_BB_SHORT_GI_DELTA_SLOPE_DELTA_SLOPE_COEF_EXP_SHORT_GI_RESET        0x0
#define PHY_BB_SHORT_GI_DELTA_SLOPE_ADDRESS                                    (0x1c + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_SHORT_GI_DELTA_SLOPE_RSTMASK                                    0x1ffffff
#define PHY_BB_SHORT_GI_DELTA_SLOPE_RESET                                      0x0

// 0x20 (PHY_BB_ML_CNTL1)
#define PHY_BB_ML_CNTL1_CF_IS_FLAT_CH_THR_ML_LSB                               30
#define PHY_BB_ML_CNTL1_CF_IS_FLAT_CH_THR_ML_MSB                               31
#define PHY_BB_ML_CNTL1_CF_IS_FLAT_CH_THR_ML_MASK                              0xc0000000
#define PHY_BB_ML_CNTL1_CF_IS_FLAT_CH_THR_ML_GET(x)                            (((x) & PHY_BB_ML_CNTL1_CF_IS_FLAT_CH_THR_ML_MASK) >> PHY_BB_ML_CNTL1_CF_IS_FLAT_CH_THR_ML_LSB)
#define PHY_BB_ML_CNTL1_CF_IS_FLAT_CH_THR_ML_SET(x)                            (((0 | (x)) << PHY_BB_ML_CNTL1_CF_IS_FLAT_CH_THR_ML_LSB) & PHY_BB_ML_CNTL1_CF_IS_FLAT_CH_THR_ML_MASK)
#define PHY_BB_ML_CNTL1_CF_IS_FLAT_CH_THR_ML_RESET                             0x0
#define PHY_BB_ML_CNTL1_CF_ML_2S_WEIGHT_TABLE_LSB                              0
#define PHY_BB_ML_CNTL1_CF_ML_2S_WEIGHT_TABLE_MSB                              29
#define PHY_BB_ML_CNTL1_CF_ML_2S_WEIGHT_TABLE_MASK                             0x3fffffff
#define PHY_BB_ML_CNTL1_CF_ML_2S_WEIGHT_TABLE_GET(x)                           (((x) & PHY_BB_ML_CNTL1_CF_ML_2S_WEIGHT_TABLE_MASK) >> PHY_BB_ML_CNTL1_CF_ML_2S_WEIGHT_TABLE_LSB)
#define PHY_BB_ML_CNTL1_CF_ML_2S_WEIGHT_TABLE_SET(x)                           (((0 | (x)) << PHY_BB_ML_CNTL1_CF_ML_2S_WEIGHT_TABLE_LSB) & PHY_BB_ML_CNTL1_CF_ML_2S_WEIGHT_TABLE_MASK)
#define PHY_BB_ML_CNTL1_CF_ML_2S_WEIGHT_TABLE_RESET                            0x0
#define PHY_BB_ML_CNTL1_ADDRESS                                                (0x20 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_ML_CNTL1_RSTMASK                                                0xffffffff
#define PHY_BB_ML_CNTL1_RESET                                                  0x0

// 0x24 (PHY_BB_ML_CNTL2)
#define PHY_BB_ML_CNTL2_CF_IS_FLAT_CH_THR_ZF_LSB                               30
#define PHY_BB_ML_CNTL2_CF_IS_FLAT_CH_THR_ZF_MSB                               31
#define PHY_BB_ML_CNTL2_CF_IS_FLAT_CH_THR_ZF_MASK                              0xc0000000
#define PHY_BB_ML_CNTL2_CF_IS_FLAT_CH_THR_ZF_GET(x)                            (((x) & PHY_BB_ML_CNTL2_CF_IS_FLAT_CH_THR_ZF_MASK) >> PHY_BB_ML_CNTL2_CF_IS_FLAT_CH_THR_ZF_LSB)
#define PHY_BB_ML_CNTL2_CF_IS_FLAT_CH_THR_ZF_SET(x)                            (((0 | (x)) << PHY_BB_ML_CNTL2_CF_IS_FLAT_CH_THR_ZF_LSB) & PHY_BB_ML_CNTL2_CF_IS_FLAT_CH_THR_ZF_MASK)
#define PHY_BB_ML_CNTL2_CF_IS_FLAT_CH_THR_ZF_RESET                             0x0
#define PHY_BB_ML_CNTL2_CF_ML_3S_WEIGHT_TABLE_LSB                              0
#define PHY_BB_ML_CNTL2_CF_ML_3S_WEIGHT_TABLE_MSB                              29
#define PHY_BB_ML_CNTL2_CF_ML_3S_WEIGHT_TABLE_MASK                             0x3fffffff
#define PHY_BB_ML_CNTL2_CF_ML_3S_WEIGHT_TABLE_GET(x)                           (((x) & PHY_BB_ML_CNTL2_CF_ML_3S_WEIGHT_TABLE_MASK) >> PHY_BB_ML_CNTL2_CF_ML_3S_WEIGHT_TABLE_LSB)
#define PHY_BB_ML_CNTL2_CF_ML_3S_WEIGHT_TABLE_SET(x)                           (((0 | (x)) << PHY_BB_ML_CNTL2_CF_ML_3S_WEIGHT_TABLE_LSB) & PHY_BB_ML_CNTL2_CF_ML_3S_WEIGHT_TABLE_MASK)
#define PHY_BB_ML_CNTL2_CF_ML_3S_WEIGHT_TABLE_RESET                            0x0
#define PHY_BB_ML_CNTL2_ADDRESS                                                (0x24 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_ML_CNTL2_RSTMASK                                                0xffffffff
#define PHY_BB_ML_CNTL2_RESET                                                  0x0

// 0x28 (PHY_BB_TSTADC)
#define PHY_BB_TSTADC_TSTADC_OUT_I_LSB                                         10
#define PHY_BB_TSTADC_TSTADC_OUT_I_MSB                                         19
#define PHY_BB_TSTADC_TSTADC_OUT_I_MASK                                        0xffc00
#define PHY_BB_TSTADC_TSTADC_OUT_I_GET(x)                                      (((x) & PHY_BB_TSTADC_TSTADC_OUT_I_MASK) >> PHY_BB_TSTADC_TSTADC_OUT_I_LSB)
#define PHY_BB_TSTADC_TSTADC_OUT_I_SET(x)                                      (((0 | (x)) << PHY_BB_TSTADC_TSTADC_OUT_I_LSB) & PHY_BB_TSTADC_TSTADC_OUT_I_MASK)
#define PHY_BB_TSTADC_TSTADC_OUT_I_RESET                                       0x0
#define PHY_BB_TSTADC_TSTADC_OUT_Q_LSB                                         0
#define PHY_BB_TSTADC_TSTADC_OUT_Q_MSB                                         9
#define PHY_BB_TSTADC_TSTADC_OUT_Q_MASK                                        0x3ff
#define PHY_BB_TSTADC_TSTADC_OUT_Q_GET(x)                                      (((x) & PHY_BB_TSTADC_TSTADC_OUT_Q_MASK) >> PHY_BB_TSTADC_TSTADC_OUT_Q_LSB)
#define PHY_BB_TSTADC_TSTADC_OUT_Q_SET(x)                                      (((0 | (x)) << PHY_BB_TSTADC_TSTADC_OUT_Q_LSB) & PHY_BB_TSTADC_TSTADC_OUT_Q_MASK)
#define PHY_BB_TSTADC_TSTADC_OUT_Q_RESET                                       0x0
#define PHY_BB_TSTADC_ADDRESS                                                  (0x28 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_TSTADC_RSTMASK                                                  0xfffff
#define PHY_BB_TSTADC_RESET                                                    0x0

// 0x2c (PHY_BB_VIT_SPUR_MASK_C)
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_SEL_LSB                          18
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_SEL_MSB                          18
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_SEL_MASK                         0x40000
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_SEL_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_SEL_MASK) >> PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_SEL_LSB)
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_SEL_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_SEL_LSB) & PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_SEL_MASK)
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_SEL_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_IDX_C_LSB                          10
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_IDX_C_MSB                          17
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_IDX_C_MASK                         0x3fc00
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_IDX_C_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_IDX_C_MASK) >> PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_IDX_C_LSB)
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_IDX_C_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_IDX_C_LSB) & PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_IDX_C_MASK)
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_IDX_C_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_LSB                              0
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_MSB                              9
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_MASK                             0x3ff
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_GET(x)                           (((x) & PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_MASK) >> PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_LSB)
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_SET(x)                           (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_LSB) & PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_MASK)
#define PHY_BB_VIT_SPUR_MASK_C_CF_PUNC_MASK_C_RESET                            0x0
#define PHY_BB_VIT_SPUR_MASK_C_ADDRESS                                         (0x2c + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_VIT_SPUR_MASK_C_RSTMASK                                         0x7ffff
#define PHY_BB_VIT_SPUR_MASK_C_RESET                                           0x0

// 0x30 (PHY_BB_VIT_SPUR_MASK_D)
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_SEL_LSB                          18
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_SEL_MSB                          18
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_SEL_MASK                         0x40000
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_SEL_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_SEL_MASK) >> PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_SEL_LSB)
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_SEL_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_SEL_LSB) & PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_SEL_MASK)
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_SEL_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_IDX_D_LSB                          10
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_IDX_D_MSB                          17
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_IDX_D_MASK                         0x3fc00
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_IDX_D_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_IDX_D_MASK) >> PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_IDX_D_LSB)
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_IDX_D_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_IDX_D_LSB) & PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_IDX_D_MASK)
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_IDX_D_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_LSB                              0
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_MSB                              9
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_MASK                             0x3ff
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_GET(x)                           (((x) & PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_MASK) >> PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_LSB)
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_SET(x)                           (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_LSB) & PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_MASK)
#define PHY_BB_VIT_SPUR_MASK_D_CF_PUNC_MASK_D_RESET                            0x0
#define PHY_BB_VIT_SPUR_MASK_D_ADDRESS                                         (0x30 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_VIT_SPUR_MASK_D_RSTMASK                                         0x7ffff
#define PHY_BB_VIT_SPUR_MASK_D_RESET                                           0x0

// 0x34 (PHY_BB_PILOT_SPUR_MASK_CD)
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_SEL_LSB                      27
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_SEL_MSB                      27
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_SEL_MASK                     0x8000000
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_SEL_GET(x)                   (((x) & PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_SEL_MASK) >> PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_SEL_LSB)
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_SEL_SET(x)                   (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_SEL_LSB) & PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_SEL_MASK)
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_SEL_RESET                    0x0
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_SEL_LSB                      26
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_SEL_MSB                      26
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_SEL_MASK                     0x4000000
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_SEL_GET(x)                   (((x) & PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_SEL_MASK) >> PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_SEL_LSB)
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_SEL_SET(x)                   (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_SEL_LSB) & PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_SEL_MASK)
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_SEL_RESET                    0x0
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_D_LSB                      18
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_D_MSB                      25
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_D_MASK                     0x3fc0000
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_D_GET(x)                   (((x) & PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_D_MASK) >> PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_D_LSB)
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_D_SET(x)                   (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_D_LSB) & PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_D_MASK)
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_D_RESET                    0x0
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_LSB                          13
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_MSB                          17
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_MASK                         0x3e000
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_GET(x)                       (((x) & PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_MASK) >> PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_LSB)
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_SET(x)                       (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_LSB) & PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_MASK)
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_D_RESET                        0x0
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_C_LSB                      5
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_C_MSB                      12
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_C_MASK                     0x1fe0
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_C_GET(x)                   (((x) & PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_C_MASK) >> PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_C_LSB)
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_C_SET(x)                   (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_C_LSB) & PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_C_MASK)
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_IDX_C_RESET                    0x0
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_LSB                          0
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_MSB                          4
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_MASK                         0x1f
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_GET(x)                       (((x) & PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_MASK) >> PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_LSB)
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_SET(x)                       (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_LSB) & PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_MASK)
#define PHY_BB_PILOT_SPUR_MASK_CD_CF_PILOT_MASK_C_RESET                        0x0
#define PHY_BB_PILOT_SPUR_MASK_CD_ADDRESS                                      (0x34 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_PILOT_SPUR_MASK_CD_RSTMASK                                      0xfffffff
#define PHY_BB_PILOT_SPUR_MASK_CD_RESET                                        0x0

// 0x38 (PHY_BB_CHAN_SPUR_MASK_CD)
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_SEL_LSB                        27
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_SEL_MSB                        27
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_SEL_MASK                       0x8000000
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_SEL_GET(x)                     (((x) & PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_SEL_MASK) >> PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_SEL_LSB)
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_SEL_SET(x)                     (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_SEL_LSB) & PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_SEL_MASK)
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_SEL_RESET                      0x0
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_SEL_LSB                        26
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_SEL_MSB                        26
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_SEL_MASK                       0x4000000
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_SEL_GET(x)                     (((x) & PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_SEL_MASK) >> PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_SEL_LSB)
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_SEL_SET(x)                     (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_SEL_LSB) & PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_SEL_MASK)
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_SEL_RESET                      0x0
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_D_LSB                        18
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_D_MSB                        25
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_D_MASK                       0x3fc0000
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_D_GET(x)                     (((x) & PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_D_MASK) >> PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_D_LSB)
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_D_SET(x)                     (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_D_LSB) & PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_D_MASK)
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_D_RESET                      0x0
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_LSB                            13
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_MSB                            17
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_MASK                           0x3e000
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_GET(x)                         (((x) & PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_MASK) >> PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_LSB)
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_SET(x)                         (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_LSB) & PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_MASK)
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_D_RESET                          0x0
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_C_LSB                        5
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_C_MSB                        12
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_C_MASK                       0x1fe0
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_C_GET(x)                     (((x) & PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_C_MASK) >> PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_C_LSB)
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_C_SET(x)                     (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_C_LSB) & PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_C_MASK)
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_IDX_C_RESET                      0x0
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_LSB                            0
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_MSB                            4
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_MASK                           0x1f
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_GET(x)                         (((x) & PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_MASK) >> PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_LSB)
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_SET(x)                         (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_LSB) & PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_MASK)
#define PHY_BB_CHAN_SPUR_MASK_CD_CF_CHAN_MASK_C_RESET                          0x0
#define PHY_BB_CHAN_SPUR_MASK_CD_ADDRESS                                       (0x38 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CHAN_SPUR_MASK_CD_RSTMASK                                       0xfffffff
#define PHY_BB_CHAN_SPUR_MASK_CD_RESET                                         0x0

// 0x3c (PHY_BB_VIT_SPUR_MASK_E)
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_SEL_LSB                          18
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_SEL_MSB                          18
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_SEL_MASK                         0x40000
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_SEL_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_SEL_MASK) >> PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_SEL_LSB)
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_SEL_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_SEL_LSB) & PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_SEL_MASK)
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_SEL_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_IDX_E_LSB                          10
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_IDX_E_MSB                          17
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_IDX_E_MASK                         0x3fc00
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_IDX_E_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_IDX_E_MASK) >> PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_IDX_E_LSB)
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_IDX_E_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_IDX_E_LSB) & PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_IDX_E_MASK)
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_IDX_E_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_LSB                              0
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_MSB                              9
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_MASK                             0x3ff
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_GET(x)                           (((x) & PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_MASK) >> PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_LSB)
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_SET(x)                           (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_LSB) & PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_MASK)
#define PHY_BB_VIT_SPUR_MASK_E_CF_PUNC_MASK_E_RESET                            0x0
#define PHY_BB_VIT_SPUR_MASK_E_ADDRESS                                         (0x3c + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_VIT_SPUR_MASK_E_RSTMASK                                         0x7ffff
#define PHY_BB_VIT_SPUR_MASK_E_RESET                                           0x0

// 0x40 (PHY_BB_VIT_SPUR_MASK_F)
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_SEL_LSB                          18
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_SEL_MSB                          18
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_SEL_MASK                         0x40000
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_SEL_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_SEL_MASK) >> PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_SEL_LSB)
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_SEL_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_SEL_LSB) & PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_SEL_MASK)
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_SEL_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_IDX_F_LSB                          10
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_IDX_F_MSB                          17
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_IDX_F_MASK                         0x3fc00
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_IDX_F_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_IDX_F_MASK) >> PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_IDX_F_LSB)
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_IDX_F_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_IDX_F_LSB) & PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_IDX_F_MASK)
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_IDX_F_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_LSB                              0
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_MSB                              9
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_MASK                             0x3ff
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_GET(x)                           (((x) & PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_MASK) >> PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_LSB)
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_SET(x)                           (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_LSB) & PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_MASK)
#define PHY_BB_VIT_SPUR_MASK_F_CF_PUNC_MASK_F_RESET                            0x0
#define PHY_BB_VIT_SPUR_MASK_F_ADDRESS                                         (0x40 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_VIT_SPUR_MASK_F_RSTMASK                                         0x7ffff
#define PHY_BB_VIT_SPUR_MASK_F_RESET                                           0x0

// 0x44 (PHY_BB_PILOT_SPUR_MASK_EF)
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_SEL_LSB                      27
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_SEL_MSB                      27
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_SEL_MASK                     0x8000000
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_SEL_GET(x)                   (((x) & PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_SEL_MASK) >> PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_SEL_LSB)
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_SEL_SET(x)                   (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_SEL_LSB) & PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_SEL_MASK)
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_SEL_RESET                    0x0
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_SEL_LSB                      26
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_SEL_MSB                      26
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_SEL_MASK                     0x4000000
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_SEL_GET(x)                   (((x) & PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_SEL_MASK) >> PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_SEL_LSB)
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_SEL_SET(x)                   (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_SEL_LSB) & PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_SEL_MASK)
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_SEL_RESET                    0x0
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_F_LSB                      18
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_F_MSB                      25
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_F_MASK                     0x3fc0000
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_F_GET(x)                   (((x) & PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_F_MASK) >> PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_F_LSB)
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_F_SET(x)                   (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_F_LSB) & PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_F_MASK)
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_F_RESET                    0x0
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_LSB                          13
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_MSB                          17
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_MASK                         0x3e000
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_GET(x)                       (((x) & PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_MASK) >> PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_LSB)
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_SET(x)                       (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_LSB) & PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_MASK)
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_F_RESET                        0x0
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_E_LSB                      5
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_E_MSB                      12
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_E_MASK                     0x1fe0
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_E_GET(x)                   (((x) & PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_E_MASK) >> PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_E_LSB)
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_E_SET(x)                   (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_E_LSB) & PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_E_MASK)
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_IDX_E_RESET                    0x0
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_LSB                          0
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_MSB                          4
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_MASK                         0x1f
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_GET(x)                       (((x) & PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_MASK) >> PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_LSB)
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_SET(x)                       (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_LSB) & PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_MASK)
#define PHY_BB_PILOT_SPUR_MASK_EF_CF_PILOT_MASK_E_RESET                        0x0
#define PHY_BB_PILOT_SPUR_MASK_EF_ADDRESS                                      (0x44 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_PILOT_SPUR_MASK_EF_RSTMASK                                      0xfffffff
#define PHY_BB_PILOT_SPUR_MASK_EF_RESET                                        0x0

// 0x48 (PHY_BB_CHAN_SPUR_MASK_EF)
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_SEL_LSB                        27
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_SEL_MSB                        27
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_SEL_MASK                       0x8000000
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_SEL_GET(x)                     (((x) & PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_SEL_MASK) >> PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_SEL_LSB)
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_SEL_SET(x)                     (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_SEL_LSB) & PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_SEL_MASK)
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_SEL_RESET                      0x0
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_SEL_LSB                        26
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_SEL_MSB                        26
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_SEL_MASK                       0x4000000
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_SEL_GET(x)                     (((x) & PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_SEL_MASK) >> PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_SEL_LSB)
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_SEL_SET(x)                     (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_SEL_LSB) & PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_SEL_MASK)
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_SEL_RESET                      0x0
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_F_LSB                        18
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_F_MSB                        25
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_F_MASK                       0x3fc0000
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_F_GET(x)                     (((x) & PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_F_MASK) >> PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_F_LSB)
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_F_SET(x)                     (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_F_LSB) & PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_F_MASK)
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_F_RESET                      0x0
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_LSB                            13
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_MSB                            17
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_MASK                           0x3e000
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_GET(x)                         (((x) & PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_MASK) >> PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_LSB)
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_SET(x)                         (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_LSB) & PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_MASK)
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_F_RESET                          0x0
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_E_LSB                        5
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_E_MSB                        12
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_E_MASK                       0x1fe0
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_E_GET(x)                     (((x) & PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_E_MASK) >> PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_E_LSB)
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_E_SET(x)                     (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_E_LSB) & PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_E_MASK)
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_IDX_E_RESET                      0x0
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_LSB                            0
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_MSB                            4
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_MASK                           0x1f
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_GET(x)                         (((x) & PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_MASK) >> PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_LSB)
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_SET(x)                         (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_LSB) & PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_MASK)
#define PHY_BB_CHAN_SPUR_MASK_EF_CF_CHAN_MASK_E_RESET                          0x0
#define PHY_BB_CHAN_SPUR_MASK_EF_ADDRESS                                       (0x48 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CHAN_SPUR_MASK_EF_RSTMASK                                       0xfffffff
#define PHY_BB_CHAN_SPUR_MASK_EF_RESET                                         0x0

// 0x4c (PHY_BB_VIT_SPUR_MASK_G)
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_SEL_LSB                          18
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_SEL_MSB                          18
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_SEL_MASK                         0x40000
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_SEL_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_SEL_MASK) >> PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_SEL_LSB)
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_SEL_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_SEL_LSB) & PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_SEL_MASK)
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_SEL_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_IDX_G_LSB                          10
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_IDX_G_MSB                          17
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_IDX_G_MASK                         0x3fc00
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_IDX_G_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_IDX_G_MASK) >> PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_IDX_G_LSB)
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_IDX_G_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_IDX_G_LSB) & PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_IDX_G_MASK)
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_IDX_G_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_LSB                              0
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_MSB                              9
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_MASK                             0x3ff
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_GET(x)                           (((x) & PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_MASK) >> PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_LSB)
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_SET(x)                           (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_LSB) & PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_MASK)
#define PHY_BB_VIT_SPUR_MASK_G_CF_PUNC_MASK_G_RESET                            0x0
#define PHY_BB_VIT_SPUR_MASK_G_ADDRESS                                         (0x4c + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_VIT_SPUR_MASK_G_RSTMASK                                         0x7ffff
#define PHY_BB_VIT_SPUR_MASK_G_RESET                                           0x0

// 0x50 (PHY_BB_VIT_SPUR_MASK_H)
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_SEL_LSB                          18
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_SEL_MSB                          18
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_SEL_MASK                         0x40000
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_SEL_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_SEL_MASK) >> PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_SEL_LSB)
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_SEL_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_SEL_LSB) & PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_SEL_MASK)
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_SEL_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_IDX_H_LSB                          10
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_IDX_H_MSB                          17
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_IDX_H_MASK                         0x3fc00
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_IDX_H_GET(x)                       (((x) & PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_IDX_H_MASK) >> PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_IDX_H_LSB)
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_IDX_H_SET(x)                       (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_IDX_H_LSB) & PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_IDX_H_MASK)
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_IDX_H_RESET                        0x0
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_LSB                              0
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_MSB                              9
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_MASK                             0x3ff
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_GET(x)                           (((x) & PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_MASK) >> PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_LSB)
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_SET(x)                           (((0 | (x)) << PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_LSB) & PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_MASK)
#define PHY_BB_VIT_SPUR_MASK_H_CF_PUNC_MASK_H_RESET                            0x0
#define PHY_BB_VIT_SPUR_MASK_H_ADDRESS                                         (0x50 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_VIT_SPUR_MASK_H_RSTMASK                                         0x7ffff
#define PHY_BB_VIT_SPUR_MASK_H_RESET                                           0x0

// 0x54 (PHY_BB_PILOT_SPUR_MASK_GH)
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_SEL_LSB                      27
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_SEL_MSB                      27
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_SEL_MASK                     0x8000000
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_SEL_GET(x)                   (((x) & PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_SEL_MASK) >> PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_SEL_LSB)
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_SEL_SET(x)                   (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_SEL_LSB) & PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_SEL_MASK)
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_SEL_RESET                    0x0
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_SEL_LSB                      26
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_SEL_MSB                      26
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_SEL_MASK                     0x4000000
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_SEL_GET(x)                   (((x) & PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_SEL_MASK) >> PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_SEL_LSB)
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_SEL_SET(x)                   (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_SEL_LSB) & PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_SEL_MASK)
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_SEL_RESET                    0x0
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_H_LSB                      18
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_H_MSB                      25
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_H_MASK                     0x3fc0000
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_H_GET(x)                   (((x) & PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_H_MASK) >> PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_H_LSB)
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_H_SET(x)                   (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_H_LSB) & PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_H_MASK)
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_H_RESET                    0x0
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_LSB                          13
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_MSB                          17
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_MASK                         0x3e000
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_GET(x)                       (((x) & PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_MASK) >> PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_LSB)
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_SET(x)                       (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_LSB) & PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_MASK)
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_H_RESET                        0x0
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_G_LSB                      5
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_G_MSB                      12
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_G_MASK                     0x1fe0
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_G_GET(x)                   (((x) & PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_G_MASK) >> PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_G_LSB)
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_G_SET(x)                   (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_G_LSB) & PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_G_MASK)
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_IDX_G_RESET                    0x0
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_LSB                          0
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_MSB                          4
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_MASK                         0x1f
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_GET(x)                       (((x) & PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_MASK) >> PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_LSB)
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_SET(x)                       (((0 | (x)) << PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_LSB) & PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_MASK)
#define PHY_BB_PILOT_SPUR_MASK_GH_CF_PILOT_MASK_G_RESET                        0x0
#define PHY_BB_PILOT_SPUR_MASK_GH_ADDRESS                                      (0x54 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_PILOT_SPUR_MASK_GH_RSTMASK                                      0xfffffff
#define PHY_BB_PILOT_SPUR_MASK_GH_RESET                                        0x0

// 0x58 (PHY_BB_CHAN_SPUR_MASK_GH)
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_SEL_LSB                        27
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_SEL_MSB                        27
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_SEL_MASK                       0x8000000
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_SEL_GET(x)                     (((x) & PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_SEL_MASK) >> PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_SEL_LSB)
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_SEL_SET(x)                     (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_SEL_LSB) & PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_SEL_MASK)
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_SEL_RESET                      0x0
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_SEL_LSB                        26
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_SEL_MSB                        26
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_SEL_MASK                       0x4000000
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_SEL_GET(x)                     (((x) & PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_SEL_MASK) >> PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_SEL_LSB)
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_SEL_SET(x)                     (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_SEL_LSB) & PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_SEL_MASK)
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_SEL_RESET                      0x0
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_H_LSB                        18
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_H_MSB                        25
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_H_MASK                       0x3fc0000
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_H_GET(x)                     (((x) & PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_H_MASK) >> PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_H_LSB)
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_H_SET(x)                     (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_H_LSB) & PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_H_MASK)
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_H_RESET                      0x0
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_LSB                            13
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_MSB                            17
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_MASK                           0x3e000
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_GET(x)                         (((x) & PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_MASK) >> PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_LSB)
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_SET(x)                         (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_LSB) & PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_MASK)
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_H_RESET                          0x0
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_G_LSB                        5
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_G_MSB                        12
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_G_MASK                       0x1fe0
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_G_GET(x)                     (((x) & PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_G_MASK) >> PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_G_LSB)
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_G_SET(x)                     (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_G_LSB) & PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_G_MASK)
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_IDX_G_RESET                      0x0
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_LSB                            0
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_MSB                            4
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_MASK                           0x1f
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_GET(x)                         (((x) & PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_MASK) >> PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_LSB)
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_SET(x)                         (((0 | (x)) << PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_LSB) & PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_MASK)
#define PHY_BB_CHAN_SPUR_MASK_GH_CF_CHAN_MASK_G_RESET                          0x0
#define PHY_BB_CHAN_SPUR_MASK_GH_ADDRESS                                       (0x58 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CHAN_SPUR_MASK_GH_RSTMASK                                       0xfffffff
#define PHY_BB_CHAN_SPUR_MASK_GH_RESET                                         0x0

// 0x5c (PHY_BB_LDPC_CNTL3)
#define PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE2_LSB                            21
#define PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE2_MSB                            31
#define PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE2_MASK                           0xffe00000
#define PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE2_GET(x)                         (((x) & PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE2_MASK) >> PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE2_LSB)
#define PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE2_SET(x)                         (((0 | (x)) << PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE2_LSB) & PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE2_MASK)
#define PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE2_RESET                          0x46
#define PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE_LSB                             10
#define PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE_MSB                             20
#define PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE_MASK                            0x1ffc00
#define PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE_GET(x)                          (((x) & PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE_MASK) >> PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE_LSB)
#define PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE_SET(x)                          (((0 | (x)) << PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE_LSB) & PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE_MASK)
#define PHY_BB_LDPC_CNTL3_LDPC_LATENCY_GAP_PRE_RESET                           0x32
#define PHY_BB_LDPC_CNTL3_LDPC_TIMEOUT_THRESH_LSB                              0
#define PHY_BB_LDPC_CNTL3_LDPC_TIMEOUT_THRESH_MSB                              9
#define PHY_BB_LDPC_CNTL3_LDPC_TIMEOUT_THRESH_MASK                             0x3ff
#define PHY_BB_LDPC_CNTL3_LDPC_TIMEOUT_THRESH_GET(x)                           (((x) & PHY_BB_LDPC_CNTL3_LDPC_TIMEOUT_THRESH_MASK) >> PHY_BB_LDPC_CNTL3_LDPC_TIMEOUT_THRESH_LSB)
#define PHY_BB_LDPC_CNTL3_LDPC_TIMEOUT_THRESH_SET(x)                           (((0 | (x)) << PHY_BB_LDPC_CNTL3_LDPC_TIMEOUT_THRESH_LSB) & PHY_BB_LDPC_CNTL3_LDPC_TIMEOUT_THRESH_MASK)
#define PHY_BB_LDPC_CNTL3_LDPC_TIMEOUT_THRESH_RESET                            0x14a
#define PHY_BB_LDPC_CNTL3_ADDRESS                                              (0x5c + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_LDPC_CNTL3_RSTMASK                                              0xffffffff
#define PHY_BB_LDPC_CNTL3_RESET                                                0x8c0c94a

// 0x60 (PHY_BB_LDPC_CNTL4)
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE2_LSB                            26
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE2_MSB                            30
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE2_MASK                           0x7c000000
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE2_GET(x)                         (((x) & PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE2_MASK) >> PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE2_LSB)
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE2_SET(x)                         (((0 | (x)) << PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE2_LSB) & PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE2_MASK)
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE2_RESET                          0xc
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE1_LSB                            21
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE1_MSB                            25
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE1_MASK                           0x3e00000
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE1_GET(x)                         (((x) & PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE1_MASK) >> PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE1_LSB)
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE1_SET(x)                         (((0 | (x)) << PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE1_LSB) & PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE1_MASK)
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE1_RESET                          0x10
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE0_LSB                            15
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE0_MSB                            20
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE0_MASK                           0x1f8000
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE0_GET(x)                         (((x) & PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE0_MASK) >> PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE0_LSB)
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE0_SET(x)                         (((0 | (x)) << PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE0_LSB) & PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE0_MASK)
#define PHY_BB_LDPC_CNTL4_LDPC_PARITY_WIN_RATE0_RESET                          0x18
#define PHY_BB_LDPC_CNTL4_LDPC_IFS_CNT_LSB                                     13
#define PHY_BB_LDPC_CNTL4_LDPC_IFS_CNT_MSB                                     14
#define PHY_BB_LDPC_CNTL4_LDPC_IFS_CNT_MASK                                    0x6000
#define PHY_BB_LDPC_CNTL4_LDPC_IFS_CNT_GET(x)                                  (((x) & PHY_BB_LDPC_CNTL4_LDPC_IFS_CNT_MASK) >> PHY_BB_LDPC_CNTL4_LDPC_IFS_CNT_LSB)
#define PHY_BB_LDPC_CNTL4_LDPC_IFS_CNT_SET(x)                                  (((0 | (x)) << PHY_BB_LDPC_CNTL4_LDPC_IFS_CNT_LSB) & PHY_BB_LDPC_CNTL4_LDPC_IFS_CNT_MASK)
#define PHY_BB_LDPC_CNTL4_LDPC_IFS_CNT_RESET                                   0x0
#define PHY_BB_LDPC_CNTL4_LDPC_FAST_INBUF_NEAR_RDY_LSB                         12
#define PHY_BB_LDPC_CNTL4_LDPC_FAST_INBUF_NEAR_RDY_MSB                         12
#define PHY_BB_LDPC_CNTL4_LDPC_FAST_INBUF_NEAR_RDY_MASK                        0x1000
#define PHY_BB_LDPC_CNTL4_LDPC_FAST_INBUF_NEAR_RDY_GET(x)                      (((x) & PHY_BB_LDPC_CNTL4_LDPC_FAST_INBUF_NEAR_RDY_MASK) >> PHY_BB_LDPC_CNTL4_LDPC_FAST_INBUF_NEAR_RDY_LSB)
#define PHY_BB_LDPC_CNTL4_LDPC_FAST_INBUF_NEAR_RDY_SET(x)                      (((0 | (x)) << PHY_BB_LDPC_CNTL4_LDPC_FAST_INBUF_NEAR_RDY_LSB) & PHY_BB_LDPC_CNTL4_LDPC_FAST_INBUF_NEAR_RDY_MASK)
#define PHY_BB_LDPC_CNTL4_LDPC_FAST_INBUF_NEAR_RDY_RESET                       0x0
#define PHY_BB_LDPC_CNTL4_LDPC_INBUF_NEAR_RDY_THRESH_LSB                       0
#define PHY_BB_LDPC_CNTL4_LDPC_INBUF_NEAR_RDY_THRESH_MSB                       11
#define PHY_BB_LDPC_CNTL4_LDPC_INBUF_NEAR_RDY_THRESH_MASK                      0xfff
#define PHY_BB_LDPC_CNTL4_LDPC_INBUF_NEAR_RDY_THRESH_GET(x)                    (((x) & PHY_BB_LDPC_CNTL4_LDPC_INBUF_NEAR_RDY_THRESH_MASK) >> PHY_BB_LDPC_CNTL4_LDPC_INBUF_NEAR_RDY_THRESH_LSB)
#define PHY_BB_LDPC_CNTL4_LDPC_INBUF_NEAR_RDY_THRESH_SET(x)                    (((0 | (x)) << PHY_BB_LDPC_CNTL4_LDPC_INBUF_NEAR_RDY_THRESH_LSB) & PHY_BB_LDPC_CNTL4_LDPC_INBUF_NEAR_RDY_THRESH_MASK)
#define PHY_BB_LDPC_CNTL4_LDPC_INBUF_NEAR_RDY_THRESH_RESET                     0x1fe
#define PHY_BB_LDPC_CNTL4_ADDRESS                                              (0x60 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_LDPC_CNTL4_RSTMASK                                              0x7fffffff
#define PHY_BB_LDPC_CNTL4_RESET                                                0x320c01fe

// 0x64 (PHY_BB_GID_UPA_ENTRY_0_TO_15)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_15_LSB                   30
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_15_MSB                   31
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_15_MASK                  0xc0000000
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_15_GET(x)                (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_15_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_15_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_15_SET(x)                (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_15_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_15_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_15_RESET                 0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_14_LSB                   28
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_14_MSB                   29
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_14_MASK                  0x30000000
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_14_GET(x)                (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_14_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_14_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_14_SET(x)                (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_14_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_14_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_14_RESET                 0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_13_LSB                   26
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_13_MSB                   27
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_13_MASK                  0xc000000
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_13_GET(x)                (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_13_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_13_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_13_SET(x)                (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_13_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_13_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_13_RESET                 0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_12_LSB                   24
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_12_MSB                   25
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_12_MASK                  0x3000000
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_12_GET(x)                (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_12_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_12_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_12_SET(x)                (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_12_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_12_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_12_RESET                 0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_11_LSB                   22
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_11_MSB                   23
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_11_MASK                  0xc00000
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_11_GET(x)                (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_11_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_11_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_11_SET(x)                (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_11_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_11_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_11_RESET                 0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_10_LSB                   20
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_10_MSB                   21
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_10_MASK                  0x300000
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_10_GET(x)                (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_10_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_10_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_10_SET(x)                (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_10_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_10_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_10_RESET                 0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_9_LSB                    18
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_9_MSB                    19
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_9_MASK                   0xc0000
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_9_GET(x)                 (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_9_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_9_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_9_SET(x)                 (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_9_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_9_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_9_RESET                  0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_8_LSB                    16
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_8_MSB                    17
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_8_MASK                   0x30000
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_8_GET(x)                 (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_8_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_8_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_8_SET(x)                 (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_8_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_8_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_8_RESET                  0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_7_LSB                    14
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_7_MSB                    15
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_7_MASK                   0xc000
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_7_GET(x)                 (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_7_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_7_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_7_SET(x)                 (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_7_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_7_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_7_RESET                  0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_6_LSB                    12
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_6_MSB                    13
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_6_MASK                   0x3000
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_6_GET(x)                 (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_6_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_6_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_6_SET(x)                 (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_6_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_6_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_6_RESET                  0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_5_LSB                    10
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_5_MSB                    11
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_5_MASK                   0xc00
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_5_GET(x)                 (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_5_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_5_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_5_SET(x)                 (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_5_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_5_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_5_RESET                  0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_4_LSB                    8
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_4_MSB                    9
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_4_MASK                   0x300
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_4_GET(x)                 (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_4_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_4_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_4_SET(x)                 (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_4_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_4_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_4_RESET                  0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_3_LSB                    6
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_3_MSB                    7
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_3_MASK                   0xc0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_3_GET(x)                 (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_3_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_3_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_3_SET(x)                 (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_3_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_3_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_3_RESET                  0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_2_LSB                    4
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_2_MSB                    5
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_2_MASK                   0x30
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_2_GET(x)                 (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_2_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_2_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_2_SET(x)                 (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_2_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_2_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_2_RESET                  0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_1_LSB                    2
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_1_MSB                    3
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_1_MASK                   0xc
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_1_GET(x)                 (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_1_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_1_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_1_SET(x)                 (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_1_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_1_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_1_RESET                  0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_0_LSB                    0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_0_MSB                    1
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_0_MASK                   0x3
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_0_GET(x)                 (((x) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_0_MASK) >> PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_0_LSB)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_0_SET(x)                 (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_0_LSB) & PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_0_MASK)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_CF_GID_UPA_ENTRY_0_RESET                  0x0
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_ADDRESS                                   (0x64 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_RSTMASK                                   0xffffffff
#define PHY_BB_GID_UPA_ENTRY_0_TO_15_RESET                                     0x0

// 0x68 (PHY_BB_GID_UPA_ENTRY_16_TO_31)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_31_LSB                  30
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_31_MSB                  31
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_31_MASK                 0xc0000000
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_31_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_31_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_31_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_31_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_31_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_31_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_31_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_30_LSB                  28
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_30_MSB                  29
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_30_MASK                 0x30000000
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_30_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_30_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_30_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_30_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_30_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_30_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_30_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_29_LSB                  26
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_29_MSB                  27
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_29_MASK                 0xc000000
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_29_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_29_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_29_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_29_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_29_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_29_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_29_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_28_LSB                  24
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_28_MSB                  25
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_28_MASK                 0x3000000
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_28_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_28_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_28_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_28_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_28_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_28_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_28_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_27_LSB                  22
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_27_MSB                  23
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_27_MASK                 0xc00000
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_27_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_27_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_27_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_27_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_27_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_27_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_27_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_26_LSB                  20
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_26_MSB                  21
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_26_MASK                 0x300000
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_26_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_26_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_26_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_26_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_26_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_26_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_26_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_25_LSB                  18
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_25_MSB                  19
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_25_MASK                 0xc0000
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_25_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_25_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_25_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_25_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_25_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_25_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_25_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_24_LSB                  16
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_24_MSB                  17
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_24_MASK                 0x30000
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_24_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_24_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_24_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_24_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_24_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_24_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_24_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_23_LSB                  14
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_23_MSB                  15
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_23_MASK                 0xc000
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_23_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_23_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_23_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_23_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_23_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_23_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_23_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_22_LSB                  12
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_22_MSB                  13
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_22_MASK                 0x3000
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_22_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_22_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_22_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_22_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_22_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_22_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_22_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_21_LSB                  10
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_21_MSB                  11
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_21_MASK                 0xc00
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_21_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_21_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_21_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_21_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_21_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_21_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_21_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_20_LSB                  8
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_20_MSB                  9
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_20_MASK                 0x300
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_20_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_20_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_20_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_20_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_20_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_20_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_20_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_19_LSB                  6
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_19_MSB                  7
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_19_MASK                 0xc0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_19_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_19_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_19_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_19_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_19_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_19_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_19_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_18_LSB                  4
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_18_MSB                  5
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_18_MASK                 0x30
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_18_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_18_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_18_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_18_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_18_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_18_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_18_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_17_LSB                  2
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_17_MSB                  3
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_17_MASK                 0xc
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_17_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_17_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_17_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_17_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_17_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_17_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_17_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_16_LSB                  0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_16_MSB                  1
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_16_MASK                 0x3
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_16_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_16_MASK) >> PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_16_LSB)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_16_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_16_LSB) & PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_16_MASK)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_CF_GID_UPA_ENTRY_16_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_ADDRESS                                  (0x68 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_RSTMASK                                  0xffffffff
#define PHY_BB_GID_UPA_ENTRY_16_TO_31_RESET                                    0x0

// 0x6c (PHY_BB_GID_UPA_ENTRY_32_TO_47)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_47_LSB                  30
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_47_MSB                  31
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_47_MASK                 0xc0000000
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_47_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_47_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_47_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_47_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_47_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_47_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_47_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_46_LSB                  28
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_46_MSB                  29
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_46_MASK                 0x30000000
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_46_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_46_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_46_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_46_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_46_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_46_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_46_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_45_LSB                  26
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_45_MSB                  27
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_45_MASK                 0xc000000
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_45_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_45_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_45_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_45_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_45_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_45_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_45_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_44_LSB                  24
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_44_MSB                  25
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_44_MASK                 0x3000000
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_44_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_44_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_44_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_44_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_44_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_44_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_44_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_43_LSB                  22
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_43_MSB                  23
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_43_MASK                 0xc00000
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_43_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_43_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_43_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_43_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_43_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_43_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_43_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_42_LSB                  20
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_42_MSB                  21
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_42_MASK                 0x300000
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_42_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_42_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_42_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_42_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_42_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_42_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_42_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_41_LSB                  18
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_41_MSB                  19
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_41_MASK                 0xc0000
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_41_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_41_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_41_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_41_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_41_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_41_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_41_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_40_LSB                  16
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_40_MSB                  17
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_40_MASK                 0x30000
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_40_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_40_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_40_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_40_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_40_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_40_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_40_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_39_LSB                  14
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_39_MSB                  15
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_39_MASK                 0xc000
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_39_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_39_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_39_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_39_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_39_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_39_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_39_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_38_LSB                  12
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_38_MSB                  13
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_38_MASK                 0x3000
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_38_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_38_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_38_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_38_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_38_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_38_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_38_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_37_LSB                  10
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_37_MSB                  11
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_37_MASK                 0xc00
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_37_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_37_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_37_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_37_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_37_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_37_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_37_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_36_LSB                  8
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_36_MSB                  9
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_36_MASK                 0x300
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_36_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_36_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_36_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_36_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_36_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_36_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_36_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_35_LSB                  6
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_35_MSB                  7
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_35_MASK                 0xc0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_35_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_35_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_35_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_35_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_35_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_35_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_35_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_34_LSB                  4
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_34_MSB                  5
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_34_MASK                 0x30
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_34_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_34_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_34_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_34_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_34_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_34_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_34_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_33_LSB                  2
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_33_MSB                  3
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_33_MASK                 0xc
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_33_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_33_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_33_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_33_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_33_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_33_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_33_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_32_LSB                  0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_32_MSB                  1
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_32_MASK                 0x3
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_32_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_32_MASK) >> PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_32_LSB)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_32_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_32_LSB) & PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_32_MASK)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_CF_GID_UPA_ENTRY_32_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_ADDRESS                                  (0x6c + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_RSTMASK                                  0xffffffff
#define PHY_BB_GID_UPA_ENTRY_32_TO_47_RESET                                    0x0

// 0x70 (PHY_BB_GID_UPA_ENTRY_48_TO_63)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_63_LSB                  30
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_63_MSB                  31
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_63_MASK                 0xc0000000
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_63_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_63_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_63_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_63_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_63_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_63_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_63_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_62_LSB                  28
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_62_MSB                  29
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_62_MASK                 0x30000000
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_62_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_62_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_62_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_62_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_62_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_62_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_62_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_61_LSB                  26
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_61_MSB                  27
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_61_MASK                 0xc000000
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_61_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_61_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_61_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_61_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_61_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_61_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_61_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_60_LSB                  24
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_60_MSB                  25
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_60_MASK                 0x3000000
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_60_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_60_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_60_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_60_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_60_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_60_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_60_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_59_LSB                  22
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_59_MSB                  23
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_59_MASK                 0xc00000
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_59_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_59_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_59_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_59_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_59_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_59_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_59_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_58_LSB                  20
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_58_MSB                  21
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_58_MASK                 0x300000
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_58_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_58_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_58_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_58_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_58_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_58_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_58_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_57_LSB                  18
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_57_MSB                  19
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_57_MASK                 0xc0000
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_57_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_57_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_57_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_57_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_57_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_57_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_57_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_56_LSB                  16
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_56_MSB                  17
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_56_MASK                 0x30000
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_56_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_56_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_56_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_56_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_56_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_56_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_56_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_55_LSB                  14
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_55_MSB                  15
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_55_MASK                 0xc000
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_55_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_55_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_55_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_55_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_55_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_55_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_55_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_54_LSB                  12
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_54_MSB                  13
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_54_MASK                 0x3000
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_54_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_54_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_54_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_54_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_54_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_54_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_54_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_53_LSB                  10
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_53_MSB                  11
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_53_MASK                 0xc00
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_53_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_53_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_53_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_53_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_53_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_53_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_53_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_52_LSB                  8
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_52_MSB                  9
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_52_MASK                 0x300
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_52_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_52_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_52_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_52_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_52_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_52_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_52_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_51_LSB                  6
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_51_MSB                  7
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_51_MASK                 0xc0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_51_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_51_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_51_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_51_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_51_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_51_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_51_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_50_LSB                  4
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_50_MSB                  5
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_50_MASK                 0x30
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_50_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_50_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_50_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_50_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_50_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_50_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_50_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_49_LSB                  2
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_49_MSB                  3
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_49_MASK                 0xc
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_49_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_49_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_49_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_49_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_49_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_49_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_49_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_48_LSB                  0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_48_MSB                  1
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_48_MASK                 0x3
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_48_GET(x)               (((x) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_48_MASK) >> PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_48_LSB)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_48_SET(x)               (((0 | (x)) << PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_48_LSB) & PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_48_MASK)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_CF_GID_UPA_ENTRY_48_RESET                0x0
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_ADDRESS                                  (0x70 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_RSTMASK                                  0xffffffff
#define PHY_BB_GID_UPA_ENTRY_48_TO_63_RESET                                    0x0

// 0x74 (PHY_BB_LSIG_RELIABILITY_CNTL)
#define PHY_BB_LSIG_RELIABILITY_CNTL_ENABLE_LSIG_VIT_CHECK_LSB                 31
#define PHY_BB_LSIG_RELIABILITY_CNTL_ENABLE_LSIG_VIT_CHECK_MSB                 31
#define PHY_BB_LSIG_RELIABILITY_CNTL_ENABLE_LSIG_VIT_CHECK_MASK                0x80000000
#define PHY_BB_LSIG_RELIABILITY_CNTL_ENABLE_LSIG_VIT_CHECK_GET(x)              (((x) & PHY_BB_LSIG_RELIABILITY_CNTL_ENABLE_LSIG_VIT_CHECK_MASK) >> PHY_BB_LSIG_RELIABILITY_CNTL_ENABLE_LSIG_VIT_CHECK_LSB)
#define PHY_BB_LSIG_RELIABILITY_CNTL_ENABLE_LSIG_VIT_CHECK_SET(x)              (((0 | (x)) << PHY_BB_LSIG_RELIABILITY_CNTL_ENABLE_LSIG_VIT_CHECK_LSB) & PHY_BB_LSIG_RELIABILITY_CNTL_ENABLE_LSIG_VIT_CHECK_MASK)
#define PHY_BB_LSIG_RELIABILITY_CNTL_ENABLE_LSIG_VIT_CHECK_RESET               0x1
#define PHY_BB_LSIG_RELIABILITY_CNTL_ENH_VIT_INIT_LSB                          30
#define PHY_BB_LSIG_RELIABILITY_CNTL_ENH_VIT_INIT_MSB                          30
#define PHY_BB_LSIG_RELIABILITY_CNTL_ENH_VIT_INIT_MASK                         0x40000000
#define PHY_BB_LSIG_RELIABILITY_CNTL_ENH_VIT_INIT_GET(x)                       (((x) & PHY_BB_LSIG_RELIABILITY_CNTL_ENH_VIT_INIT_MASK) >> PHY_BB_LSIG_RELIABILITY_CNTL_ENH_VIT_INIT_LSB)
#define PHY_BB_LSIG_RELIABILITY_CNTL_ENH_VIT_INIT_SET(x)                       (((0 | (x)) << PHY_BB_LSIG_RELIABILITY_CNTL_ENH_VIT_INIT_LSB) & PHY_BB_LSIG_RELIABILITY_CNTL_ENH_VIT_INIT_MASK)
#define PHY_BB_LSIG_RELIABILITY_CNTL_ENH_VIT_INIT_RESET                        0x1
#define PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_SU_LSB                 29
#define PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_SU_MSB                 29
#define PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_SU_MASK                0x20000000
#define PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_SU_GET(x)              (((x) & PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_SU_MASK) >> PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_SU_LSB)
#define PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_SU_SET(x)              (((0 | (x)) << PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_SU_LSB) & PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_SU_MASK)
#define PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_SU_RESET               0x0
#define PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_MU_LSB                 28
#define PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_MU_MSB                 28
#define PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_MU_MASK                0x10000000
#define PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_MU_GET(x)              (((x) & PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_MU_MASK) >> PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_MU_LSB)
#define PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_MU_SET(x)              (((0 | (x)) << PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_MU_LSB) & PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_MU_MASK)
#define PHY_BB_LSIG_RELIABILITY_CNTL_EN_VHTSIGB_CRC_CHK_MU_RESET               0x0
#define PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MIN_S0_63_DIFF_THR_LSB               8
#define PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MIN_S0_63_DIFF_THR_MSB               18
#define PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MIN_S0_63_DIFF_THR_MASK              0x7ff00
#define PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MIN_S0_63_DIFF_THR_GET(x)            (((x) & PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MIN_S0_63_DIFF_THR_MASK) >> PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MIN_S0_63_DIFF_THR_LSB)
#define PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MIN_S0_63_DIFF_THR_SET(x)            (((0 | (x)) << PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MIN_S0_63_DIFF_THR_LSB) & PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MIN_S0_63_DIFF_THR_MASK)
#define PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MIN_S0_63_DIFF_THR_RESET             0x4
#define PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MAX_S0_THR_LSB                       0
#define PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MAX_S0_THR_MSB                       7
#define PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MAX_S0_THR_MASK                      0xff
#define PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MAX_S0_THR_GET(x)                    (((x) & PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MAX_S0_THR_MASK) >> PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MAX_S0_THR_LSB)
#define PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MAX_S0_THR_SET(x)                    (((0 | (x)) << PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MAX_S0_THR_LSB) & PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MAX_S0_THR_MASK)
#define PHY_BB_LSIG_RELIABILITY_CNTL_LSIG_MAX_S0_THR_RESET                     0x1c
#define PHY_BB_LSIG_RELIABILITY_CNTL_ADDRESS                                   (0x74 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_LSIG_RELIABILITY_CNTL_RSTMASK                                   0xf007ffff
#define PHY_BB_LSIG_RELIABILITY_CNTL_RESET                                     0xc000041c

// 0x78 (PHY_BB_MMSE_CNTL)
#define PHY_BB_MMSE_CNTL_SEC_MMSE_IS_NOISE_PWR_EXP_SHIFT_LSB                   17
#define PHY_BB_MMSE_CNTL_SEC_MMSE_IS_NOISE_PWR_EXP_SHIFT_MSB                   20
#define PHY_BB_MMSE_CNTL_SEC_MMSE_IS_NOISE_PWR_EXP_SHIFT_MASK                  0x1e0000
#define PHY_BB_MMSE_CNTL_SEC_MMSE_IS_NOISE_PWR_EXP_SHIFT_GET(x)                (((x) & PHY_BB_MMSE_CNTL_SEC_MMSE_IS_NOISE_PWR_EXP_SHIFT_MASK) >> PHY_BB_MMSE_CNTL_SEC_MMSE_IS_NOISE_PWR_EXP_SHIFT_LSB)
#define PHY_BB_MMSE_CNTL_SEC_MMSE_IS_NOISE_PWR_EXP_SHIFT_SET(x)                (((0 | (x)) << PHY_BB_MMSE_CNTL_SEC_MMSE_IS_NOISE_PWR_EXP_SHIFT_LSB) & PHY_BB_MMSE_CNTL_SEC_MMSE_IS_NOISE_PWR_EXP_SHIFT_MASK)
#define PHY_BB_MMSE_CNTL_SEC_MMSE_IS_NOISE_PWR_EXP_SHIFT_RESET                 0xf
#define PHY_BB_MMSE_CNTL_CF_MMSE_DBG_EN_LSB                                    16
#define PHY_BB_MMSE_CNTL_CF_MMSE_DBG_EN_MSB                                    16
#define PHY_BB_MMSE_CNTL_CF_MMSE_DBG_EN_MASK                                   0x10000
#define PHY_BB_MMSE_CNTL_CF_MMSE_DBG_EN_GET(x)                                 (((x) & PHY_BB_MMSE_CNTL_CF_MMSE_DBG_EN_MASK) >> PHY_BB_MMSE_CNTL_CF_MMSE_DBG_EN_LSB)
#define PHY_BB_MMSE_CNTL_CF_MMSE_DBG_EN_SET(x)                                 (((0 | (x)) << PHY_BB_MMSE_CNTL_CF_MMSE_DBG_EN_LSB) & PHY_BB_MMSE_CNTL_CF_MMSE_DBG_EN_MASK)
#define PHY_BB_MMSE_CNTL_CF_MMSE_DBG_EN_RESET                                  0x0
#define PHY_BB_MMSE_CNTL_USE_SU_ZF_LSB                                         15
#define PHY_BB_MMSE_CNTL_USE_SU_ZF_MSB                                         15
#define PHY_BB_MMSE_CNTL_USE_SU_ZF_MASK                                        0x8000
#define PHY_BB_MMSE_CNTL_USE_SU_ZF_GET(x)                                      (((x) & PHY_BB_MMSE_CNTL_USE_SU_ZF_MASK) >> PHY_BB_MMSE_CNTL_USE_SU_ZF_LSB)
#define PHY_BB_MMSE_CNTL_USE_SU_ZF_SET(x)                                      (((0 | (x)) << PHY_BB_MMSE_CNTL_USE_SU_ZF_LSB) & PHY_BB_MMSE_CNTL_USE_SU_ZF_MASK)
#define PHY_BB_MMSE_CNTL_USE_SU_ZF_RESET                                       0x0
#define PHY_BB_MMSE_CNTL_MMSE_IS_NOISE_PWR_EXP_SHIFT_LSB                       11
#define PHY_BB_MMSE_CNTL_MMSE_IS_NOISE_PWR_EXP_SHIFT_MSB                       14
#define PHY_BB_MMSE_CNTL_MMSE_IS_NOISE_PWR_EXP_SHIFT_MASK                      0x7800
#define PHY_BB_MMSE_CNTL_MMSE_IS_NOISE_PWR_EXP_SHIFT_GET(x)                    (((x) & PHY_BB_MMSE_CNTL_MMSE_IS_NOISE_PWR_EXP_SHIFT_MASK) >> PHY_BB_MMSE_CNTL_MMSE_IS_NOISE_PWR_EXP_SHIFT_LSB)
#define PHY_BB_MMSE_CNTL_MMSE_IS_NOISE_PWR_EXP_SHIFT_SET(x)                    (((0 | (x)) << PHY_BB_MMSE_CNTL_MMSE_IS_NOISE_PWR_EXP_SHIFT_LSB) & PHY_BB_MMSE_CNTL_MMSE_IS_NOISE_PWR_EXP_SHIFT_MASK)
#define PHY_BB_MMSE_CNTL_MMSE_IS_NOISE_PWR_EXP_SHIFT_RESET                     0xf
#define PHY_BB_MMSE_CNTL_MMSE_IS_MAX_SNR_LEVEL_LSB                             9
#define PHY_BB_MMSE_CNTL_MMSE_IS_MAX_SNR_LEVEL_MSB                             10
#define PHY_BB_MMSE_CNTL_MMSE_IS_MAX_SNR_LEVEL_MASK                            0x600
#define PHY_BB_MMSE_CNTL_MMSE_IS_MAX_SNR_LEVEL_GET(x)                          (((x) & PHY_BB_MMSE_CNTL_MMSE_IS_MAX_SNR_LEVEL_MASK) >> PHY_BB_MMSE_CNTL_MMSE_IS_MAX_SNR_LEVEL_LSB)
#define PHY_BB_MMSE_CNTL_MMSE_IS_MAX_SNR_LEVEL_SET(x)                          (((0 | (x)) << PHY_BB_MMSE_CNTL_MMSE_IS_MAX_SNR_LEVEL_LSB) & PHY_BB_MMSE_CNTL_MMSE_IS_MAX_SNR_LEVEL_MASK)
#define PHY_BB_MMSE_CNTL_MMSE_IS_MAX_SNR_LEVEL_RESET                           0x0
#define PHY_BB_MMSE_CNTL_MMSE_IS_SNR_CORR_FACTOR_LSB                           6
#define PHY_BB_MMSE_CNTL_MMSE_IS_SNR_CORR_FACTOR_MSB                           8
#define PHY_BB_MMSE_CNTL_MMSE_IS_SNR_CORR_FACTOR_MASK                          0x1c0
#define PHY_BB_MMSE_CNTL_MMSE_IS_SNR_CORR_FACTOR_GET(x)                        (((x) & PHY_BB_MMSE_CNTL_MMSE_IS_SNR_CORR_FACTOR_MASK) >> PHY_BB_MMSE_CNTL_MMSE_IS_SNR_CORR_FACTOR_LSB)
#define PHY_BB_MMSE_CNTL_MMSE_IS_SNR_CORR_FACTOR_SET(x)                        (((0 | (x)) << PHY_BB_MMSE_CNTL_MMSE_IS_SNR_CORR_FACTOR_LSB) & PHY_BB_MMSE_CNTL_MMSE_IS_SNR_CORR_FACTOR_MASK)
#define PHY_BB_MMSE_CNTL_MMSE_IS_SNR_CORR_FACTOR_RESET                         0x3
#define PHY_BB_MMSE_CNTL_MMSE_IS_FORCED_SNR_LSB                                1
#define PHY_BB_MMSE_CNTL_MMSE_IS_FORCED_SNR_MSB                                5
#define PHY_BB_MMSE_CNTL_MMSE_IS_FORCED_SNR_MASK                               0x3e
#define PHY_BB_MMSE_CNTL_MMSE_IS_FORCED_SNR_GET(x)                             (((x) & PHY_BB_MMSE_CNTL_MMSE_IS_FORCED_SNR_MASK) >> PHY_BB_MMSE_CNTL_MMSE_IS_FORCED_SNR_LSB)
#define PHY_BB_MMSE_CNTL_MMSE_IS_FORCED_SNR_SET(x)                             (((0 | (x)) << PHY_BB_MMSE_CNTL_MMSE_IS_FORCED_SNR_LSB) & PHY_BB_MMSE_CNTL_MMSE_IS_FORCED_SNR_MASK)
#define PHY_BB_MMSE_CNTL_MMSE_IS_FORCED_SNR_RESET                              0x0
#define PHY_BB_MMSE_CNTL_USE_MMSE_IC_LSB                                       0
#define PHY_BB_MMSE_CNTL_USE_MMSE_IC_MSB                                       0
#define PHY_BB_MMSE_CNTL_USE_MMSE_IC_MASK                                      0x1
#define PHY_BB_MMSE_CNTL_USE_MMSE_IC_GET(x)                                    (((x) & PHY_BB_MMSE_CNTL_USE_MMSE_IC_MASK) >> PHY_BB_MMSE_CNTL_USE_MMSE_IC_LSB)
#define PHY_BB_MMSE_CNTL_USE_MMSE_IC_SET(x)                                    (((0 | (x)) << PHY_BB_MMSE_CNTL_USE_MMSE_IC_LSB) & PHY_BB_MMSE_CNTL_USE_MMSE_IC_MASK)
#define PHY_BB_MMSE_CNTL_USE_MMSE_IC_RESET                                     0x1
#define PHY_BB_MMSE_CNTL_ADDRESS                                               (0x78 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_MMSE_CNTL_RSTMASK                                               0x1fffff
#define PHY_BB_MMSE_CNTL_RESET                                                 0x1e78c1

// 0x7c (PHY_BB_LDPC_CNTL5)
#define PHY_BB_LDPC_CNTL5_LDPC_PARITY_WIN_RATE3_LSB                            25
#define PHY_BB_LDPC_CNTL5_LDPC_PARITY_WIN_RATE3_MSB                            28
#define PHY_BB_LDPC_CNTL5_LDPC_PARITY_WIN_RATE3_MASK                           0x1e000000
#define PHY_BB_LDPC_CNTL5_LDPC_PARITY_WIN_RATE3_GET(x)                         (((x) & PHY_BB_LDPC_CNTL5_LDPC_PARITY_WIN_RATE3_MASK) >> PHY_BB_LDPC_CNTL5_LDPC_PARITY_WIN_RATE3_LSB)
#define PHY_BB_LDPC_CNTL5_LDPC_PARITY_WIN_RATE3_SET(x)                         (((0 | (x)) << PHY_BB_LDPC_CNTL5_LDPC_PARITY_WIN_RATE3_LSB) & PHY_BB_LDPC_CNTL5_LDPC_PARITY_WIN_RATE3_MASK)
#define PHY_BB_LDPC_CNTL5_LDPC_PARITY_WIN_RATE3_RESET                          0x8
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_SEL_LSB                                 24
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_SEL_MSB                                 24
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_SEL_MASK                                0x1000000
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_SEL_GET(x)                              (((x) & PHY_BB_LDPC_CNTL5_LDPC_LATENCY_SEL_MASK) >> PHY_BB_LDPC_CNTL5_LDPC_LATENCY_SEL_LSB)
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_SEL_SET(x)                              (((0 | (x)) << PHY_BB_LDPC_CNTL5_LDPC_LATENCY_SEL_LSB) & PHY_BB_LDPC_CNTL5_LDPC_LATENCY_SEL_MASK)
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_SEL_RESET                               0x1
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_LSB                        12
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_MSB                        23
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_MASK                       0xfff000
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_GET(x)                     (((x) & PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_MASK) >> PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_LSB)
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_SET(x)                     (((0 | (x)) << PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_LSB) & PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_MASK)
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_RESET                      0x840
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_STBC_LSB                   0
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_STBC_MSB                   11
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_STBC_MASK                  0xfff
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_STBC_GET(x)                (((x) & PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_STBC_MASK) >> PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_STBC_LSB)
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_STBC_SET(x)                (((0 | (x)) << PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_STBC_LSB) & PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_STBC_MASK)
#define PHY_BB_LDPC_CNTL5_LDPC_LATENCY_LASTCW_RXCLR_STBC_RESET                 0x9a0
#define PHY_BB_LDPC_CNTL5_ADDRESS                                              (0x7c + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_LDPC_CNTL5_RSTMASK                                              0x1fffffff
#define PHY_BB_LDPC_CNTL5_RESET                                                0x118409a0

// 0x80 (PHY_BB_MMSE_CNTL2)
#define PHY_BB_MMSE_CNTL2_MMSE_MU_NSS_USER_LSB                                 30
#define PHY_BB_MMSE_CNTL2_MMSE_MU_NSS_USER_MSB                                 31
#define PHY_BB_MMSE_CNTL2_MMSE_MU_NSS_USER_MASK                                0xc0000000
#define PHY_BB_MMSE_CNTL2_MMSE_MU_NSS_USER_GET(x)                              (((x) & PHY_BB_MMSE_CNTL2_MMSE_MU_NSS_USER_MASK) >> PHY_BB_MMSE_CNTL2_MMSE_MU_NSS_USER_LSB)
#define PHY_BB_MMSE_CNTL2_MMSE_MU_NSS_USER_SET(x)                              (((0 | (x)) << PHY_BB_MMSE_CNTL2_MMSE_MU_NSS_USER_LSB) & PHY_BB_MMSE_CNTL2_MMSE_MU_NSS_USER_MASK)
#define PHY_BB_MMSE_CNTL2_MMSE_MU_NSS_USER_RESET                               0x0
#define PHY_BB_MMSE_CNTL2_MMSE_TURBO_MODE_LSB                                  28
#define PHY_BB_MMSE_CNTL2_MMSE_TURBO_MODE_MSB                                  29
#define PHY_BB_MMSE_CNTL2_MMSE_TURBO_MODE_MASK                                 0x30000000
#define PHY_BB_MMSE_CNTL2_MMSE_TURBO_MODE_GET(x)                               (((x) & PHY_BB_MMSE_CNTL2_MMSE_TURBO_MODE_MASK) >> PHY_BB_MMSE_CNTL2_MMSE_TURBO_MODE_LSB)
#define PHY_BB_MMSE_CNTL2_MMSE_TURBO_MODE_SET(x)                               (((0 | (x)) << PHY_BB_MMSE_CNTL2_MMSE_TURBO_MODE_LSB) & PHY_BB_MMSE_CNTL2_MMSE_TURBO_MODE_MASK)
#define PHY_BB_MMSE_CNTL2_MMSE_TURBO_MODE_RESET                                0x0
#define PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS2_LSB                                  14
#define PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS2_MSB                                  27
#define PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS2_MASK                                 0xfffc000
#define PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS2_GET(x)                               (((x) & PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS2_MASK) >> PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS2_LSB)
#define PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS2_SET(x)                               (((0 | (x)) << PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS2_LSB) & PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS2_MASK)
#define PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS2_RESET                                0x0
#define PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS1_LSB                                  0
#define PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS1_MSB                                  13
#define PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS1_MASK                                 0x3fff
#define PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS1_GET(x)                               (((x) & PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS1_MASK) >> PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS1_LSB)
#define PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS1_SET(x)                               (((0 | (x)) << PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS1_LSB) & PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS1_MASK)
#define PHY_BB_MMSE_CNTL2_MMSE_SIR_DB_SS1_RESET                                0x0
#define PHY_BB_MMSE_CNTL2_ADDRESS                                              (0x80 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_MMSE_CNTL2_RSTMASK                                              0xffffffff
#define PHY_BB_MMSE_CNTL2_RESET                                                0x0

// 0x84 (PHY_BB_MMSE_CNTL3)
#define PHY_BB_MMSE_CNTL3_MMSE_IS_NOISE_PWR_LSB                                6
#define PHY_BB_MMSE_CNTL3_MMSE_IS_NOISE_PWR_MSB                                19
#define PHY_BB_MMSE_CNTL3_MMSE_IS_NOISE_PWR_MASK                               0xfffc0
#define PHY_BB_MMSE_CNTL3_MMSE_IS_NOISE_PWR_GET(x)                             (((x) & PHY_BB_MMSE_CNTL3_MMSE_IS_NOISE_PWR_MASK) >> PHY_BB_MMSE_CNTL3_MMSE_IS_NOISE_PWR_LSB)
#define PHY_BB_MMSE_CNTL3_MMSE_IS_NOISE_PWR_SET(x)                             (((0 | (x)) << PHY_BB_MMSE_CNTL3_MMSE_IS_NOISE_PWR_LSB) & PHY_BB_MMSE_CNTL3_MMSE_IS_NOISE_PWR_MASK)
#define PHY_BB_MMSE_CNTL3_MMSE_IS_NOISE_PWR_RESET                              0x0
#define PHY_BB_MMSE_CNTL3_SNR_EST_MMSE_IS_LSB                                  0
#define PHY_BB_MMSE_CNTL3_SNR_EST_MMSE_IS_MSB                                  5
#define PHY_BB_MMSE_CNTL3_SNR_EST_MMSE_IS_MASK                                 0x3f
#define PHY_BB_MMSE_CNTL3_SNR_EST_MMSE_IS_GET(x)                               (((x) & PHY_BB_MMSE_CNTL3_SNR_EST_MMSE_IS_MASK) >> PHY_BB_MMSE_CNTL3_SNR_EST_MMSE_IS_LSB)
#define PHY_BB_MMSE_CNTL3_SNR_EST_MMSE_IS_SET(x)                               (((0 | (x)) << PHY_BB_MMSE_CNTL3_SNR_EST_MMSE_IS_LSB) & PHY_BB_MMSE_CNTL3_SNR_EST_MMSE_IS_MASK)
#define PHY_BB_MMSE_CNTL3_SNR_EST_MMSE_IS_RESET                                0x0
#define PHY_BB_MMSE_CNTL3_ADDRESS                                              (0x84 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_MMSE_CNTL3_RSTMASK                                              0xfffff
#define PHY_BB_MMSE_CNTL3_RESET                                                0x0

// 0x88 (PHY_BB_PACKET_BW_DET_CNTL)
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_DET_BW_FAIL_LSB                       16
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_DET_BW_FAIL_MSB                       31
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_DET_BW_FAIL_MASK                      0xffff0000
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_DET_BW_FAIL_GET(x)                    (((x) & PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_DET_BW_FAIL_MASK) >> PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_DET_BW_FAIL_LSB)
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_DET_BW_FAIL_SET(x)                    (((0 | (x)) << PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_DET_BW_FAIL_LSB) & PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_DET_BW_FAIL_MASK)
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_DET_BW_FAIL_RESET                     0x0
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_EN_LSB             12
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_EN_MSB             12
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_EN_MASK            0x1000
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_EN_GET(x)          (((x) & PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_EN_MASK) >> PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_EN_LSB)
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_EN_SET(x)          (((0 | (x)) << PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_EN_LSB) & PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_EN_MASK)
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_EN_RESET           0x0
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_LSB                10
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_MSB                11
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_MASK               0xc00
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_GET(x)             (((x) & PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_MASK) >> PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_LSB)
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_SET(x)             (((0 | (x)) << PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_LSB) & PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_MASK)
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_DET_BW_FORCE_RESET              0x0
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_PWR_THR_LSB                     6
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_PWR_THR_MSB                     9
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_PWR_THR_MASK                    0x3c0
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_PWR_THR_GET(x)                  (((x) & PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_PWR_THR_MASK) >> PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_PWR_THR_LSB)
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_PWR_THR_SET(x)                  (((0 | (x)) << PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_PWR_THR_LSB) & PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_PWR_THR_MASK)
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_PWR_THR_RESET                   0x2
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THN_LSB                         3
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THN_MSB                         5
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THN_MASK                        0x38
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THN_GET(x)                      (((x) & PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THN_MASK) >> PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THN_LSB)
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THN_SET(x)                      (((0 | (x)) << PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THN_LSB) & PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THN_MASK)
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THN_RESET                       0x5
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THP_LSB                         0
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THP_MSB                         2
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THP_MASK                        0x7
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THP_GET(x)                      (((x) & PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THP_MASK) >> PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THP_LSB)
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THP_SET(x)                      (((0 | (x)) << PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THP_LSB) & PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THP_MASK)
#define PHY_BB_PACKET_BW_DET_CNTL_MRCAPB_PBDBE_THP_RESET                       0x5
#define PHY_BB_PACKET_BW_DET_CNTL_ADDRESS                                      (0x88 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_PACKET_BW_DET_CNTL_RSTMASK                                      0xffff1fff
#define PHY_BB_PACKET_BW_DET_CNTL_RESET                                        0xad

// 0x8c (PHY_BB_ML_CNTL3)
#define PHY_BB_ML_CNTL3_CF_ML_4S_WEIGHT_TABLE_LSB                              0
#define PHY_BB_ML_CNTL3_CF_ML_4S_WEIGHT_TABLE_MSB                              29
#define PHY_BB_ML_CNTL3_CF_ML_4S_WEIGHT_TABLE_MASK                             0x3fffffff
#define PHY_BB_ML_CNTL3_CF_ML_4S_WEIGHT_TABLE_GET(x)                           (((x) & PHY_BB_ML_CNTL3_CF_ML_4S_WEIGHT_TABLE_MASK) >> PHY_BB_ML_CNTL3_CF_ML_4S_WEIGHT_TABLE_LSB)
#define PHY_BB_ML_CNTL3_CF_ML_4S_WEIGHT_TABLE_SET(x)                           (((0 | (x)) << PHY_BB_ML_CNTL3_CF_ML_4S_WEIGHT_TABLE_LSB) & PHY_BB_ML_CNTL3_CF_ML_4S_WEIGHT_TABLE_MASK)
#define PHY_BB_ML_CNTL3_CF_ML_4S_WEIGHT_TABLE_RESET                            0x0
#define PHY_BB_ML_CNTL3_ADDRESS                                                (0x8c + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_ML_CNTL3_RSTMASK                                                0x3fffffff
#define PHY_BB_ML_CNTL3_RESET                                                  0x0

// 0x90 (PHY_BB_PBS_CNTL)
#define PHY_BB_PBS_CNTL_RXWIN_ROLLOFF_LSB                                      1
#define PHY_BB_PBS_CNTL_RXWIN_ROLLOFF_MSB                                      2
#define PHY_BB_PBS_CNTL_RXWIN_ROLLOFF_MASK                                     0x6
#define PHY_BB_PBS_CNTL_RXWIN_ROLLOFF_GET(x)                                   (((x) & PHY_BB_PBS_CNTL_RXWIN_ROLLOFF_MASK) >> PHY_BB_PBS_CNTL_RXWIN_ROLLOFF_LSB)
#define PHY_BB_PBS_CNTL_RXWIN_ROLLOFF_SET(x)                                   (((0 | (x)) << PHY_BB_PBS_CNTL_RXWIN_ROLLOFF_LSB) & PHY_BB_PBS_CNTL_RXWIN_ROLLOFF_MASK)
#define PHY_BB_PBS_CNTL_RXWIN_ROLLOFF_RESET                                    0x0
#define PHY_BB_PBS_CNTL_PBS_DISABLE_LSB                                        0
#define PHY_BB_PBS_CNTL_PBS_DISABLE_MSB                                        0
#define PHY_BB_PBS_CNTL_PBS_DISABLE_MASK                                       0x1
#define PHY_BB_PBS_CNTL_PBS_DISABLE_GET(x)                                     (((x) & PHY_BB_PBS_CNTL_PBS_DISABLE_MASK) >> PHY_BB_PBS_CNTL_PBS_DISABLE_LSB)
#define PHY_BB_PBS_CNTL_PBS_DISABLE_SET(x)                                     (((0 | (x)) << PHY_BB_PBS_CNTL_PBS_DISABLE_LSB) & PHY_BB_PBS_CNTL_PBS_DISABLE_MASK)
#define PHY_BB_PBS_CNTL_PBS_DISABLE_RESET                                      0x0
#define PHY_BB_PBS_CNTL_ADDRESS                                                (0x90 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_PBS_CNTL_RSTMASK                                                0x7
#define PHY_BB_PBS_CNTL_RESET                                                  0x0

// 0x94 (PHY_BB_STE_COARSE_TIM_CNTL_1)
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_4_LSB                   24
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_4_MSB                   31
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_4_MASK                  0xff000000
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_4_GET(x)                (((x) & PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_4_MASK) >> PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_4_LSB)
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_4_SET(x)                (((0 | (x)) << PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_4_LSB) & PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_4_MASK)
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_4_RESET                 0xd4
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_3_LSB                   16
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_3_MSB                   23
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_3_MASK                  0xff0000
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_3_GET(x)                (((x) & PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_3_MASK) >> PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_3_LSB)
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_3_SET(x)                (((0 | (x)) << PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_3_LSB) & PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_3_MASK)
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_3_RESET                 0xfc
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_2_LSB                   8
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_2_MSB                   15
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_2_MASK                  0xff00
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_2_GET(x)                (((x) & PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_2_MASK) >> PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_2_LSB)
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_2_SET(x)                (((0 | (x)) << PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_2_LSB) & PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_2_MASK)
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_2_RESET                 0xe6
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_1_LSB                   0
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_1_MSB                   7
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_1_MASK                  0xff
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_1_GET(x)                (((x) & PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_1_MASK) >> PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_1_LSB)
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_1_SET(x)                (((0 | (x)) << PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_1_LSB) & PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_1_MASK)
#define PHY_BB_STE_COARSE_TIM_CNTL_1_CF_COARSE_TIM_THR_1_RESET                 0xe6
#define PHY_BB_STE_COARSE_TIM_CNTL_1_ADDRESS                                   (0x94 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_STE_COARSE_TIM_CNTL_1_RSTMASK                                   0xffffffff
#define PHY_BB_STE_COARSE_TIM_CNTL_1_RESET                                     0xd4fce6e6

// 0x98 (PHY_BB_STE_COARSE_TIM_CNTL_2)
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_8_LSB                   24
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_8_MSB                   31
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_8_MASK                  0xff000000
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_8_GET(x)                (((x) & PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_8_MASK) >> PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_8_LSB)
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_8_SET(x)                (((0 | (x)) << PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_8_LSB) & PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_8_MASK)
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_8_RESET                 0x9a
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_7_LSB                   16
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_7_MSB                   23
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_7_MASK                  0xff0000
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_7_GET(x)                (((x) & PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_7_MASK) >> PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_7_LSB)
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_7_SET(x)                (((0 | (x)) << PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_7_LSB) & PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_7_MASK)
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_7_RESET                 0x66
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_6_LSB                   8
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_6_MSB                   15
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_6_MASK                  0xff00
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_6_GET(x)                (((x) & PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_6_MASK) >> PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_6_LSB)
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_6_SET(x)                (((0 | (x)) << PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_6_LSB) & PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_6_MASK)
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_6_RESET                 0xe6
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_5_LSB                   0
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_5_MSB                   7
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_5_MASK                  0xff
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_5_GET(x)                (((x) & PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_5_MASK) >> PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_5_LSB)
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_5_SET(x)                (((0 | (x)) << PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_5_LSB) & PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_5_MASK)
#define PHY_BB_STE_COARSE_TIM_CNTL_2_CF_COARSE_TIM_THR_5_RESET                 0xdf
#define PHY_BB_STE_COARSE_TIM_CNTL_2_ADDRESS                                   (0x98 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_STE_COARSE_TIM_CNTL_2_RSTMASK                                   0xffffffff
#define PHY_BB_STE_COARSE_TIM_CNTL_2_RESET                                     0x9a66e6df

// 0x9c (PHY_BB_STE_COARSE_TIM_CNTL_3)
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_3_LSB                12
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_3_MSB                17
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_3_MASK               0x3f000
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_3_GET(x)             (((x) & PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_3_MASK) >> PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_3_LSB)
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_3_SET(x)             (((0 | (x)) << PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_3_LSB) & PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_3_MASK)
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_3_RESET              0x0
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_2_LSB                6
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_2_MSB                11
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_2_MASK               0xfc0
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_2_GET(x)             (((x) & PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_2_MASK) >> PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_2_LSB)
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_2_SET(x)             (((0 | (x)) << PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_2_LSB) & PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_2_MASK)
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_2_RESET              0x14
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_1_LSB                0
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_1_MSB                5
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_1_MASK               0x3f
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_1_GET(x)             (((x) & PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_1_MASK) >> PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_1_LSB)
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_1_SET(x)             (((0 | (x)) << PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_1_LSB) & PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_1_MASK)
#define PHY_BB_STE_COARSE_TIM_CNTL_3_CF_COARSE_TIM_OFFSET_1_RESET              0x18
#define PHY_BB_STE_COARSE_TIM_CNTL_3_ADDRESS                                   (0x9c + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_STE_COARSE_TIM_CNTL_3_RSTMASK                                   0x3ffff
#define PHY_BB_STE_COARSE_TIM_CNTL_3_RESET                                     0x518

// 0xa0 (PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI40_CORR_SG_LSB 23
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI40_CORR_SG_MSB 31
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI40_CORR_SG_MASK 0xff800000
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI40_CORR_SG_GET(x) (((x) & PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI40_CORR_SG_MASK) >> PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI40_CORR_SG_LSB)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI40_CORR_SG_SET(x) (((0 | (x)) << PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI40_CORR_SG_LSB) & PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI40_CORR_SG_MASK)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI40_CORR_SG_RESET 0x0
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI80_CORR_SG_LSB 13
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI80_CORR_SG_MSB 22
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI80_CORR_SG_MASK 0x7fe000
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI80_CORR_SG_GET(x) (((x) & PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI80_CORR_SG_MASK) >> PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI80_CORR_SG_LSB)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI80_CORR_SG_SET(x) (((0 | (x)) << PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI80_CORR_SG_LSB) & PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI80_CORR_SG_MASK)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_PRI80_CORR_SG_RESET 0x0
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_EXT80_CORR_SG_LSB 0
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_EXT80_CORR_SG_MSB 12
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_EXT80_CORR_SG_MASK 0x1fff
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_EXT80_CORR_SG_GET(x) (((x) & PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_EXT80_CORR_SG_MASK) >> PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_EXT80_CORR_SG_LSB)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_EXT80_CORR_SG_SET(x) (((0 | (x)) << PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_EXT80_CORR_SG_LSB) & PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_EXT80_CORR_SG_MASK)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_DELTA_SLOPE_COEF_MAN_EXT80_CORR_SG_RESET 0x0
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_ADDRESS                            (0xa0 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_RSTMASK                            0xffffffff
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_SG_RESET                              0x0

// 0xa4 (PHY_BB_DELTA_SLOPE_COEF_MAN_CORR)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI40_CORR_LSB   23
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI40_CORR_MSB   31
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI40_CORR_MASK  0xff800000
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI40_CORR_GET(x) (((x) & PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI40_CORR_MASK) >> PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI40_CORR_LSB)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI40_CORR_SET(x) (((0 | (x)) << PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI40_CORR_LSB) & PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI40_CORR_MASK)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI40_CORR_RESET 0x0
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI80_CORR_LSB   13
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI80_CORR_MSB   22
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI80_CORR_MASK  0x7fe000
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI80_CORR_GET(x) (((x) & PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI80_CORR_MASK) >> PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI80_CORR_LSB)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI80_CORR_SET(x) (((0 | (x)) << PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI80_CORR_LSB) & PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI80_CORR_MASK)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_PRI80_CORR_RESET 0x0
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_EXT80_CORR_LSB   0
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_EXT80_CORR_MSB   12
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_EXT80_CORR_MASK  0x1fff
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_EXT80_CORR_GET(x) (((x) & PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_EXT80_CORR_MASK) >> PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_EXT80_CORR_LSB)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_EXT80_CORR_SET(x) (((0 | (x)) << PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_EXT80_CORR_LSB) & PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_EXT80_CORR_MASK)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_DELTA_SLOPE_COEF_MAN_EXT80_CORR_RESET 0x0
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_ADDRESS                               (0xa4 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_RSTMASK                               0xffffffff
#define PHY_BB_DELTA_SLOPE_COEF_MAN_CORR_RESET                                 0x0

// 0xa8 (PHY_BB_CFO_CORR_SCALE_FRAC)
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EN_LSB                  21
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EN_MSB                  21
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EN_MASK                 0x200000
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EN_GET(x)               (((x) & PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EN_MASK) >> PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EN_LSB)
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EN_SET(x)               (((0 | (x)) << PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EN_LSB) & PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EN_MASK)
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EN_RESET                0x0
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI40_LSB               16
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI40_MSB               20
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI40_MASK              0x1f0000
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI40_GET(x)            (((x) & PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI40_MASK) >> PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI40_LSB)
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI40_SET(x)            (((0 | (x)) << PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI40_LSB) & PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI40_MASK)
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI40_RESET             0x0
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI80_LSB               10
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI80_MSB               15
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI80_MASK              0xfc00
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI80_GET(x)            (((x) & PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI80_MASK) >> PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI80_LSB)
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI80_SET(x)            (((0 | (x)) << PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI80_LSB) & PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI80_MASK)
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_PRI80_RESET             0x0
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EXT80_LSB               0
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EXT80_MSB               9
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EXT80_MASK              0x3ff
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EXT80_GET(x)            (((x) & PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EXT80_MASK) >> PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EXT80_LSB)
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EXT80_SET(x)            (((0 | (x)) << PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EXT80_LSB) & PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EXT80_MASK)
#define PHY_BB_CFO_CORR_SCALE_FRAC_CFO_CORR_SCALE_FRAC_EXT80_RESET             0x0
#define PHY_BB_CFO_CORR_SCALE_FRAC_ADDRESS                                     (0xa8 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_CFO_CORR_SCALE_FRAC_RSTMASK                                     0x3fffff
#define PHY_BB_CFO_CORR_SCALE_FRAC_RESET                                       0x0

// 0xac (PHY_BB_GAIN_RATIO_CNTL)
#define PHY_BB_GAIN_RATIO_CNTL_AGC_HT_STF_GAIN_RATIO_ENA_LSB                   0
#define PHY_BB_GAIN_RATIO_CNTL_AGC_HT_STF_GAIN_RATIO_ENA_MSB                   0
#define PHY_BB_GAIN_RATIO_CNTL_AGC_HT_STF_GAIN_RATIO_ENA_MASK                  0x1
#define PHY_BB_GAIN_RATIO_CNTL_AGC_HT_STF_GAIN_RATIO_ENA_GET(x)                (((x) & PHY_BB_GAIN_RATIO_CNTL_AGC_HT_STF_GAIN_RATIO_ENA_MASK) >> PHY_BB_GAIN_RATIO_CNTL_AGC_HT_STF_GAIN_RATIO_ENA_LSB)
#define PHY_BB_GAIN_RATIO_CNTL_AGC_HT_STF_GAIN_RATIO_ENA_SET(x)                (((0 | (x)) << PHY_BB_GAIN_RATIO_CNTL_AGC_HT_STF_GAIN_RATIO_ENA_LSB) & PHY_BB_GAIN_RATIO_CNTL_AGC_HT_STF_GAIN_RATIO_ENA_MASK)
#define PHY_BB_GAIN_RATIO_CNTL_AGC_HT_STF_GAIN_RATIO_ENA_RESET                 0x0
#define PHY_BB_GAIN_RATIO_CNTL_ADDRESS                                         (0xac + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_GAIN_RATIO_CNTL_RSTMASK                                         0x1
#define PHY_BB_GAIN_RATIO_CNTL_RESET                                           0x0

// 0x100 (PHY_BB_LDPC_CNTL6)
#define PHY_BB_LDPC_CNTL6_LDPC_LATENCY_GAP_PRE3_LSB                            0
#define PHY_BB_LDPC_CNTL6_LDPC_LATENCY_GAP_PRE3_MSB                            10
#define PHY_BB_LDPC_CNTL6_LDPC_LATENCY_GAP_PRE3_MASK                           0x7ff
#define PHY_BB_LDPC_CNTL6_LDPC_LATENCY_GAP_PRE3_GET(x)                         (((x) & PHY_BB_LDPC_CNTL6_LDPC_LATENCY_GAP_PRE3_MASK) >> PHY_BB_LDPC_CNTL6_LDPC_LATENCY_GAP_PRE3_LSB)
#define PHY_BB_LDPC_CNTL6_LDPC_LATENCY_GAP_PRE3_SET(x)                         (((0 | (x)) << PHY_BB_LDPC_CNTL6_LDPC_LATENCY_GAP_PRE3_LSB) & PHY_BB_LDPC_CNTL6_LDPC_LATENCY_GAP_PRE3_MASK)
#define PHY_BB_LDPC_CNTL6_LDPC_LATENCY_GAP_PRE3_RESET                          0x5a
#define PHY_BB_LDPC_CNTL6_ADDRESS                                              (0x100 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_LDPC_CNTL6_RSTMASK                                              0x7ff
#define PHY_BB_LDPC_CNTL6_RESET                                                0x5a

// 0x104 (PHY_BB_LDPC_CNTL7)
#define PHY_BB_LDPC_CNTL7_LDPC_MS_OFFSET_LSB                                   1
#define PHY_BB_LDPC_CNTL7_LDPC_MS_OFFSET_MSB                                   1
#define PHY_BB_LDPC_CNTL7_LDPC_MS_OFFSET_MASK                                  0x2
#define PHY_BB_LDPC_CNTL7_LDPC_MS_OFFSET_GET(x)                                (((x) & PHY_BB_LDPC_CNTL7_LDPC_MS_OFFSET_MASK) >> PHY_BB_LDPC_CNTL7_LDPC_MS_OFFSET_LSB)
#define PHY_BB_LDPC_CNTL7_LDPC_MS_OFFSET_SET(x)                                (((0 | (x)) << PHY_BB_LDPC_CNTL7_LDPC_MS_OFFSET_LSB) & PHY_BB_LDPC_CNTL7_LDPC_MS_OFFSET_MASK)
#define PHY_BB_LDPC_CNTL7_LDPC_MS_OFFSET_RESET                                 0x1
#define PHY_BB_LDPC_CNTL7_LDPC_MS_SCALE_LSB                                    0
#define PHY_BB_LDPC_CNTL7_LDPC_MS_SCALE_MSB                                    0
#define PHY_BB_LDPC_CNTL7_LDPC_MS_SCALE_MASK                                   0x1
#define PHY_BB_LDPC_CNTL7_LDPC_MS_SCALE_GET(x)                                 (((x) & PHY_BB_LDPC_CNTL7_LDPC_MS_SCALE_MASK) >> PHY_BB_LDPC_CNTL7_LDPC_MS_SCALE_LSB)
#define PHY_BB_LDPC_CNTL7_LDPC_MS_SCALE_SET(x)                                 (((0 | (x)) << PHY_BB_LDPC_CNTL7_LDPC_MS_SCALE_LSB) & PHY_BB_LDPC_CNTL7_LDPC_MS_SCALE_MASK)
#define PHY_BB_LDPC_CNTL7_LDPC_MS_SCALE_RESET                                  0x1
#define PHY_BB_LDPC_CNTL7_ADDRESS                                              (0x104 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_LDPC_CNTL7_RSTMASK                                              0x3
#define PHY_BB_LDPC_CNTL7_RESET                                                0x3

// 0x108 (PHY_BB_LDPC_CNTL8)
#define PHY_BB_LDPC_CNTL8_HIGH_PRECISION_LDPC_LLR_SCALING0_LSB                 0
#define PHY_BB_LDPC_CNTL8_HIGH_PRECISION_LDPC_LLR_SCALING0_MSB                 29
#define PHY_BB_LDPC_CNTL8_HIGH_PRECISION_LDPC_LLR_SCALING0_MASK                0x3fffffff
#define PHY_BB_LDPC_CNTL8_HIGH_PRECISION_LDPC_LLR_SCALING0_GET(x)              (((x) & PHY_BB_LDPC_CNTL8_HIGH_PRECISION_LDPC_LLR_SCALING0_MASK) >> PHY_BB_LDPC_CNTL8_HIGH_PRECISION_LDPC_LLR_SCALING0_LSB)
#define PHY_BB_LDPC_CNTL8_HIGH_PRECISION_LDPC_LLR_SCALING0_SET(x)              (((0 | (x)) << PHY_BB_LDPC_CNTL8_HIGH_PRECISION_LDPC_LLR_SCALING0_LSB) & PHY_BB_LDPC_CNTL8_HIGH_PRECISION_LDPC_LLR_SCALING0_MASK)
#define PHY_BB_LDPC_CNTL8_HIGH_PRECISION_LDPC_LLR_SCALING0_RESET               0x36db2492
#define PHY_BB_LDPC_CNTL8_ADDRESS                                              (0x108 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_LDPC_CNTL8_RSTMASK                                              0x3fffffff
#define PHY_BB_LDPC_CNTL8_RESET                                                0x36db2492

// 0x10c (PHY_BB_LDPC_CNTL9)
#define PHY_BB_LDPC_CNTL9_EN_HIGH_PRECISION_LDPC_LLR_SCALING_LSB               30
#define PHY_BB_LDPC_CNTL9_EN_HIGH_PRECISION_LDPC_LLR_SCALING_MSB               30
#define PHY_BB_LDPC_CNTL9_EN_HIGH_PRECISION_LDPC_LLR_SCALING_MASK              0x40000000
#define PHY_BB_LDPC_CNTL9_EN_HIGH_PRECISION_LDPC_LLR_SCALING_GET(x)            (((x) & PHY_BB_LDPC_CNTL9_EN_HIGH_PRECISION_LDPC_LLR_SCALING_MASK) >> PHY_BB_LDPC_CNTL9_EN_HIGH_PRECISION_LDPC_LLR_SCALING_LSB)
#define PHY_BB_LDPC_CNTL9_EN_HIGH_PRECISION_LDPC_LLR_SCALING_SET(x)            (((0 | (x)) << PHY_BB_LDPC_CNTL9_EN_HIGH_PRECISION_LDPC_LLR_SCALING_LSB) & PHY_BB_LDPC_CNTL9_EN_HIGH_PRECISION_LDPC_LLR_SCALING_MASK)
#define PHY_BB_LDPC_CNTL9_EN_HIGH_PRECISION_LDPC_LLR_SCALING_RESET             0x0
#define PHY_BB_LDPC_CNTL9_HIGH_PRECISION_LDPC_LLR_SCALING1_LSB                 0
#define PHY_BB_LDPC_CNTL9_HIGH_PRECISION_LDPC_LLR_SCALING1_MSB                 29
#define PHY_BB_LDPC_CNTL9_HIGH_PRECISION_LDPC_LLR_SCALING1_MASK                0x3fffffff
#define PHY_BB_LDPC_CNTL9_HIGH_PRECISION_LDPC_LLR_SCALING1_GET(x)              (((x) & PHY_BB_LDPC_CNTL9_HIGH_PRECISION_LDPC_LLR_SCALING1_MASK) >> PHY_BB_LDPC_CNTL9_HIGH_PRECISION_LDPC_LLR_SCALING1_LSB)
#define PHY_BB_LDPC_CNTL9_HIGH_PRECISION_LDPC_LLR_SCALING1_SET(x)              (((0 | (x)) << PHY_BB_LDPC_CNTL9_HIGH_PRECISION_LDPC_LLR_SCALING1_LSB) & PHY_BB_LDPC_CNTL9_HIGH_PRECISION_LDPC_LLR_SCALING1_MASK)
#define PHY_BB_LDPC_CNTL9_HIGH_PRECISION_LDPC_LLR_SCALING1_RESET               0x92
#define PHY_BB_LDPC_CNTL9_ADDRESS                                              (0x10c + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_LDPC_CNTL9_RSTMASK                                              0x7fffffff
#define PHY_BB_LDPC_CNTL9_RESET                                                0x92

// 0x110 (PHY_BB_MRC_SPARE_01)
#define PHY_BB_MRC_SPARE_01_MRC_ECO_CTRL_LSB                                   0
#define PHY_BB_MRC_SPARE_01_MRC_ECO_CTRL_MSB                                   31
#define PHY_BB_MRC_SPARE_01_MRC_ECO_CTRL_MASK                                  0xffffffff
#define PHY_BB_MRC_SPARE_01_MRC_ECO_CTRL_GET(x)                                (((x) & PHY_BB_MRC_SPARE_01_MRC_ECO_CTRL_MASK) >> PHY_BB_MRC_SPARE_01_MRC_ECO_CTRL_LSB)
#define PHY_BB_MRC_SPARE_01_MRC_ECO_CTRL_SET(x)                                (((0 | (x)) << PHY_BB_MRC_SPARE_01_MRC_ECO_CTRL_LSB) & PHY_BB_MRC_SPARE_01_MRC_ECO_CTRL_MASK)
#define PHY_BB_MRC_SPARE_01_MRC_ECO_CTRL_RESET                                 0x0
#define PHY_BB_MRC_SPARE_01_ADDRESS                                            (0x110 + __PHY_MRC_REG_MAP_BASE_ADDRESS)
#define PHY_BB_MRC_SPARE_01_RSTMASK                                            0xffffffff
#define PHY_BB_MRC_SPARE_01_RESET                                              0x0



#endif /* _PHY_MRC_REG_MAP_H_ */
