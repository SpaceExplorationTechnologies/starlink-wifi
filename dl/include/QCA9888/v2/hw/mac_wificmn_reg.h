/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _MAC_WIFICMN_REG_H_
#define _MAC_WIFICMN_REG_H_


#ifndef __MAC_WIFICMN_REG_BASE_ADDRESS
#define __MAC_WIFICMN_REG_BASE_ADDRESS (0x40000)
#endif


// 0x0 (WIFICMN_ISR_P)
#define WIFICMN_ISR_P_MEM_ERR_INTR_LSB                                         29
#define WIFICMN_ISR_P_MEM_ERR_INTR_MSB                                         29
#define WIFICMN_ISR_P_MEM_ERR_INTR_MASK                                        0x20000000
#define WIFICMN_ISR_P_MEM_ERR_INTR_GET(x)                                      (((x) & WIFICMN_ISR_P_MEM_ERR_INTR_MASK) >> WIFICMN_ISR_P_MEM_ERR_INTR_LSB)
#define WIFICMN_ISR_P_MEM_ERR_INTR_SET(x)                                      (((0 | (x)) << WIFICMN_ISR_P_MEM_ERR_INTR_LSB) & WIFICMN_ISR_P_MEM_ERR_INTR_MASK)
#define WIFICMN_ISR_P_MEM_ERR_INTR_RESET                                       0x0
#define WIFICMN_ISR_P_CE_WATCHDOG_ERR_INTR_LSB                                 26
#define WIFICMN_ISR_P_CE_WATCHDOG_ERR_INTR_MSB                                 26
#define WIFICMN_ISR_P_CE_WATCHDOG_ERR_INTR_MASK                                0x4000000
#define WIFICMN_ISR_P_CE_WATCHDOG_ERR_INTR_GET(x)                              (((x) & WIFICMN_ISR_P_CE_WATCHDOG_ERR_INTR_MASK) >> WIFICMN_ISR_P_CE_WATCHDOG_ERR_INTR_LSB)
#define WIFICMN_ISR_P_CE_WATCHDOG_ERR_INTR_SET(x)                              (((0 | (x)) << WIFICMN_ISR_P_CE_WATCHDOG_ERR_INTR_LSB) & WIFICMN_ISR_P_CE_WATCHDOG_ERR_INTR_MASK)
#define WIFICMN_ISR_P_CE_WATCHDOG_ERR_INTR_RESET                               0x0
#define WIFICMN_ISR_P_INVALID_BB_INTR_LSB                                      23
#define WIFICMN_ISR_P_INVALID_BB_INTR_MSB                                      23
#define WIFICMN_ISR_P_INVALID_BB_INTR_MASK                                     0x800000
#define WIFICMN_ISR_P_INVALID_BB_INTR_GET(x)                                   (((x) & WIFICMN_ISR_P_INVALID_BB_INTR_MASK) >> WIFICMN_ISR_P_INVALID_BB_INTR_LSB)
#define WIFICMN_ISR_P_INVALID_BB_INTR_SET(x)                                   (((0 | (x)) << WIFICMN_ISR_P_INVALID_BB_INTR_LSB) & WIFICMN_ISR_P_INVALID_BB_INTR_MASK)
#define WIFICMN_ISR_P_INVALID_BB_INTR_RESET                                    0x0
#define WIFICMN_ISR_P_PTA_COEX_INTR_LSB                                        7
#define WIFICMN_ISR_P_PTA_COEX_INTR_MSB                                        7
#define WIFICMN_ISR_P_PTA_COEX_INTR_MASK                                       0x80
#define WIFICMN_ISR_P_PTA_COEX_INTR_GET(x)                                     (((x) & WIFICMN_ISR_P_PTA_COEX_INTR_MASK) >> WIFICMN_ISR_P_PTA_COEX_INTR_LSB)
#define WIFICMN_ISR_P_PTA_COEX_INTR_SET(x)                                     (((0 | (x)) << WIFICMN_ISR_P_PTA_COEX_INTR_LSB) & WIFICMN_ISR_P_PTA_COEX_INTR_MASK)
#define WIFICMN_ISR_P_PTA_COEX_INTR_RESET                                      0x0
#define WIFICMN_ISR_P_WIFI_TIMER_INTR_LSB                                      2
#define WIFICMN_ISR_P_WIFI_TIMER_INTR_MSB                                      2
#define WIFICMN_ISR_P_WIFI_TIMER_INTR_MASK                                     0x4
#define WIFICMN_ISR_P_WIFI_TIMER_INTR_GET(x)                                   (((x) & WIFICMN_ISR_P_WIFI_TIMER_INTR_MASK) >> WIFICMN_ISR_P_WIFI_TIMER_INTR_LSB)
#define WIFICMN_ISR_P_WIFI_TIMER_INTR_SET(x)                                   (((0 | (x)) << WIFICMN_ISR_P_WIFI_TIMER_INTR_LSB) & WIFICMN_ISR_P_WIFI_TIMER_INTR_MASK)
#define WIFICMN_ISR_P_WIFI_TIMER_INTR_RESET                                    0x0
#define WIFICMN_ISR_P_ADDRESS                                                  (0x0 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_ISR_P_RSTMASK                                                  0x24800084
#define WIFICMN_ISR_P_RESET                                                    0x0

// 0x4 (WIFICMN_ISR_S0)
#define WIFICMN_ISR_S0_PCU_DTIM_SYNC_LSB                                       10
#define WIFICMN_ISR_S0_PCU_DTIM_SYNC_MSB                                       11
#define WIFICMN_ISR_S0_PCU_DTIM_SYNC_MASK                                      0xc00
#define WIFICMN_ISR_S0_PCU_DTIM_SYNC_GET(x)                                    (((x) & WIFICMN_ISR_S0_PCU_DTIM_SYNC_MASK) >> WIFICMN_ISR_S0_PCU_DTIM_SYNC_LSB)
#define WIFICMN_ISR_S0_PCU_DTIM_SYNC_SET(x)                                    (((0 | (x)) << WIFICMN_ISR_S0_PCU_DTIM_SYNC_LSB) & WIFICMN_ISR_S0_PCU_DTIM_SYNC_MASK)
#define WIFICMN_ISR_S0_PCU_DTIM_SYNC_RESET                                     0x0
#define WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_LSB                                  8
#define WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_MSB                                  9
#define WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_MASK                                 0x300
#define WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_GET(x)                               (((x) & WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_MASK) >> WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_LSB)
#define WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_SET(x)                               (((0 | (x)) << WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_LSB) & WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_MASK)
#define WIFICMN_ISR_S0_PCU_BEACON_TIMEOUT_RESET                                0x0
#define WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_LSB                                     6
#define WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_MSB                                     7
#define WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_MASK                                    0xc0
#define WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_GET(x)                                  (((x) & WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_MASK) >> WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_LSB)
#define WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_SET(x)                                  (((0 | (x)) << WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_LSB) & WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_MASK)
#define WIFICMN_ISR_S0_PCU_CAB_TIMEOUT_RESET                                   0x0
#define WIFICMN_ISR_S0_PCU_CAB_NO_MORE_LSB                                     4
#define WIFICMN_ISR_S0_PCU_CAB_NO_MORE_MSB                                     5
#define WIFICMN_ISR_S0_PCU_CAB_NO_MORE_MASK                                    0x30
#define WIFICMN_ISR_S0_PCU_CAB_NO_MORE_GET(x)                                  (((x) & WIFICMN_ISR_S0_PCU_CAB_NO_MORE_MASK) >> WIFICMN_ISR_S0_PCU_CAB_NO_MORE_LSB)
#define WIFICMN_ISR_S0_PCU_CAB_NO_MORE_SET(x)                                  (((0 | (x)) << WIFICMN_ISR_S0_PCU_CAB_NO_MORE_LSB) & WIFICMN_ISR_S0_PCU_CAB_NO_MORE_MASK)
#define WIFICMN_ISR_S0_PCU_CAB_NO_MORE_RESET                                   0x0
#define WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_LSB                                2
#define WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_MSB                                3
#define WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_MASK                               0xc
#define WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_GET(x)                             (((x) & WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_MASK) >> WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_LSB)
#define WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_SET(x)                             (((0 | (x)) << WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_LSB) & WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_MASK)
#define WIFICMN_ISR_S0_PCU_TSF_OUT_OF_RANGE_RESET                              0x0
#define WIFICMN_ISR_S0_PCU_SLP32_CYCLE_CNT_LSB                                 1
#define WIFICMN_ISR_S0_PCU_SLP32_CYCLE_CNT_MSB                                 1
#define WIFICMN_ISR_S0_PCU_SLP32_CYCLE_CNT_MASK                                0x2
#define WIFICMN_ISR_S0_PCU_SLP32_CYCLE_CNT_GET(x)                              (((x) & WIFICMN_ISR_S0_PCU_SLP32_CYCLE_CNT_MASK) >> WIFICMN_ISR_S0_PCU_SLP32_CYCLE_CNT_LSB)
#define WIFICMN_ISR_S0_PCU_SLP32_CYCLE_CNT_SET(x)                              (((0 | (x)) << WIFICMN_ISR_S0_PCU_SLP32_CYCLE_CNT_LSB) & WIFICMN_ISR_S0_PCU_SLP32_CYCLE_CNT_MASK)
#define WIFICMN_ISR_S0_PCU_SLP32_CYCLE_CNT_RESET                               0x0
#define WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_LSB                                0
#define WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_MSB                                0
#define WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_MASK                               0x1
#define WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_GET(x)                             (((x) & WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_MASK) >> WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_LSB)
#define WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_SET(x)                             (((0 | (x)) << WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_LSB) & WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_MASK)
#define WIFICMN_ISR_S0_PCU_GEN_TIMER_OVRFLW_RESET                              0x0
#define WIFICMN_ISR_S0_ADDRESS                                                 (0x4 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_ISR_S0_RSTMASK                                                 0xfff
#define WIFICMN_ISR_S0_RESET                                                   0x0

// 0x8 (WIFICMN_ISR_S1)
#define WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_LSB                                16
#define WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_MSB                                31
#define WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_MASK                               0xffff0000
#define WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_GET(x)                             (((x) & WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_MASK) >> WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_LSB)
#define WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_SET(x)                             (((0 | (x)) << WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_LSB) & WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_MASK)
#define WIFICMN_ISR_S1_PCU_GEN_TIMER_THRESH_RESET                              0x0
#define WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_LSB                               0
#define WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_MSB                               15
#define WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_MASK                              0xffff
#define WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_GET(x)                            (((x) & WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_MASK) >> WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_LSB)
#define WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_SET(x)                            (((0 | (x)) << WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_LSB) & WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_MASK)
#define WIFICMN_ISR_S1_PCU_GEN_TIMER_TRIGGER_RESET                             0x0
#define WIFICMN_ISR_S1_ADDRESS                                                 (0x8 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_ISR_S1_RSTMASK                                                 0xffffffff
#define WIFICMN_ISR_S1_RESET                                                   0x0

// 0xc (WIFICMN_ISR_S2)
#define WIFICMN_ISR_S2_INVALID_BB_LSB                                          2
#define WIFICMN_ISR_S2_INVALID_BB_MSB                                          2
#define WIFICMN_ISR_S2_INVALID_BB_MASK                                         0x4
#define WIFICMN_ISR_S2_INVALID_BB_GET(x)                                       (((x) & WIFICMN_ISR_S2_INVALID_BB_MASK) >> WIFICMN_ISR_S2_INVALID_BB_LSB)
#define WIFICMN_ISR_S2_INVALID_BB_SET(x)                                       (((0 | (x)) << WIFICMN_ISR_S2_INVALID_BB_LSB) & WIFICMN_ISR_S2_INVALID_BB_MASK)
#define WIFICMN_ISR_S2_INVALID_BB_RESET                                        0x0
#define WIFICMN_ISR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_LSB                          1
#define WIFICMN_ISR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_MSB                          1
#define WIFICMN_ISR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_MASK                         0x2
#define WIFICMN_ISR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_GET(x)                       (((x) & WIFICMN_ISR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_MASK) >> WIFICMN_ISR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_LSB)
#define WIFICMN_ISR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_SET(x)                       (((0 | (x)) << WIFICMN_ISR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_LSB) & WIFICMN_ISR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_MASK)
#define WIFICMN_ISR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_RESET                        0x0
#define WIFICMN_ISR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_LSB                       0
#define WIFICMN_ISR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_MSB                       0
#define WIFICMN_ISR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_MASK                      0x1
#define WIFICMN_ISR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_GET(x)                    (((x) & WIFICMN_ISR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_MASK) >> WIFICMN_ISR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_LSB)
#define WIFICMN_ISR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_SET(x)                    (((0 | (x)) << WIFICMN_ISR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_LSB) & WIFICMN_ISR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_MASK)
#define WIFICMN_ISR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_RESET                     0x0
#define WIFICMN_ISR_S2_ADDRESS                                                 (0xc + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_ISR_S2_RSTMASK                                                 0x7
#define WIFICMN_ISR_S2_RESET                                                   0x0

// 0x10 (WIFICMN_ISR_S3)
#define WIFICMN_ISR_S3_PTA_WL_STOMPED_LSB                                      7
#define WIFICMN_ISR_S3_PTA_WL_STOMPED_MSB                                      7
#define WIFICMN_ISR_S3_PTA_WL_STOMPED_MASK                                     0x80
#define WIFICMN_ISR_S3_PTA_WL_STOMPED_GET(x)                                   (((x) & WIFICMN_ISR_S3_PTA_WL_STOMPED_MASK) >> WIFICMN_ISR_S3_PTA_WL_STOMPED_LSB)
#define WIFICMN_ISR_S3_PTA_WL_STOMPED_SET(x)                                   (((0 | (x)) << WIFICMN_ISR_S3_PTA_WL_STOMPED_LSB) & WIFICMN_ISR_S3_PTA_WL_STOMPED_MASK)
#define WIFICMN_ISR_S3_PTA_WL_STOMPED_RESET                                    0x0
#define WIFICMN_ISR_S3_PTA_BT_STOMPED_LSB                                      6
#define WIFICMN_ISR_S3_PTA_BT_STOMPED_MSB                                      6
#define WIFICMN_ISR_S3_PTA_BT_STOMPED_MASK                                     0x40
#define WIFICMN_ISR_S3_PTA_BT_STOMPED_GET(x)                                   (((x) & WIFICMN_ISR_S3_PTA_BT_STOMPED_MASK) >> WIFICMN_ISR_S3_PTA_BT_STOMPED_LSB)
#define WIFICMN_ISR_S3_PTA_BT_STOMPED_SET(x)                                   (((0 | (x)) << WIFICMN_ISR_S3_PTA_BT_STOMPED_LSB) & WIFICMN_ISR_S3_PTA_BT_STOMPED_MASK)
#define WIFICMN_ISR_S3_PTA_BT_STOMPED_RESET                                    0x0
#define WIFICMN_ISR_S3_PTA_BT_ACTIVE_RISE_LSB                                  5
#define WIFICMN_ISR_S3_PTA_BT_ACTIVE_RISE_MSB                                  5
#define WIFICMN_ISR_S3_PTA_BT_ACTIVE_RISE_MASK                                 0x20
#define WIFICMN_ISR_S3_PTA_BT_ACTIVE_RISE_GET(x)                               (((x) & WIFICMN_ISR_S3_PTA_BT_ACTIVE_RISE_MASK) >> WIFICMN_ISR_S3_PTA_BT_ACTIVE_RISE_LSB)
#define WIFICMN_ISR_S3_PTA_BT_ACTIVE_RISE_SET(x)                               (((0 | (x)) << WIFICMN_ISR_S3_PTA_BT_ACTIVE_RISE_LSB) & WIFICMN_ISR_S3_PTA_BT_ACTIVE_RISE_MASK)
#define WIFICMN_ISR_S3_PTA_BT_ACTIVE_RISE_RESET                                0x0
#define WIFICMN_ISR_S3_PTA_BT_ACTIVE_FALL_LSB                                  4
#define WIFICMN_ISR_S3_PTA_BT_ACTIVE_FALL_MSB                                  4
#define WIFICMN_ISR_S3_PTA_BT_ACTIVE_FALL_MASK                                 0x10
#define WIFICMN_ISR_S3_PTA_BT_ACTIVE_FALL_GET(x)                               (((x) & WIFICMN_ISR_S3_PTA_BT_ACTIVE_FALL_MASK) >> WIFICMN_ISR_S3_PTA_BT_ACTIVE_FALL_LSB)
#define WIFICMN_ISR_S3_PTA_BT_ACTIVE_FALL_SET(x)                               (((0 | (x)) << WIFICMN_ISR_S3_PTA_BT_ACTIVE_FALL_LSB) & WIFICMN_ISR_S3_PTA_BT_ACTIVE_FALL_MASK)
#define WIFICMN_ISR_S3_PTA_BT_ACTIVE_FALL_RESET                                0x0
#define WIFICMN_ISR_S3_PTA_BT_PRIORITY_RISE_LSB                                3
#define WIFICMN_ISR_S3_PTA_BT_PRIORITY_RISE_MSB                                3
#define WIFICMN_ISR_S3_PTA_BT_PRIORITY_RISE_MASK                               0x8
#define WIFICMN_ISR_S3_PTA_BT_PRIORITY_RISE_GET(x)                             (((x) & WIFICMN_ISR_S3_PTA_BT_PRIORITY_RISE_MASK) >> WIFICMN_ISR_S3_PTA_BT_PRIORITY_RISE_LSB)
#define WIFICMN_ISR_S3_PTA_BT_PRIORITY_RISE_SET(x)                             (((0 | (x)) << WIFICMN_ISR_S3_PTA_BT_PRIORITY_RISE_LSB) & WIFICMN_ISR_S3_PTA_BT_PRIORITY_RISE_MASK)
#define WIFICMN_ISR_S3_PTA_BT_PRIORITY_RISE_RESET                              0x0
#define WIFICMN_ISR_S3_PTA_BT_PRIORITY_FALL_LSB                                2
#define WIFICMN_ISR_S3_PTA_BT_PRIORITY_FALL_MSB                                2
#define WIFICMN_ISR_S3_PTA_BT_PRIORITY_FALL_MASK                               0x4
#define WIFICMN_ISR_S3_PTA_BT_PRIORITY_FALL_GET(x)                             (((x) & WIFICMN_ISR_S3_PTA_BT_PRIORITY_FALL_MASK) >> WIFICMN_ISR_S3_PTA_BT_PRIORITY_FALL_LSB)
#define WIFICMN_ISR_S3_PTA_BT_PRIORITY_FALL_SET(x)                             (((0 | (x)) << WIFICMN_ISR_S3_PTA_BT_PRIORITY_FALL_LSB) & WIFICMN_ISR_S3_PTA_BT_PRIORITY_FALL_MASK)
#define WIFICMN_ISR_S3_PTA_BT_PRIORITY_FALL_RESET                              0x0
#define WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_RISE_LSB                                1
#define WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_RISE_MSB                                1
#define WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_RISE_MASK                               0x2
#define WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_RISE_GET(x)                             (((x) & WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_RISE_MASK) >> WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_RISE_LSB)
#define WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_RISE_SET(x)                             (((0 | (x)) << WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_RISE_LSB) & WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_RISE_MASK)
#define WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_RISE_RESET                              0x0
#define WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_FALL_LSB                                0
#define WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_FALL_MSB                                0
#define WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_FALL_MASK                               0x1
#define WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_FALL_GET(x)                             (((x) & WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_FALL_MASK) >> WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_FALL_LSB)
#define WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_FALL_SET(x)                             (((0 | (x)) << WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_FALL_LSB) & WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_FALL_MASK)
#define WIFICMN_ISR_S3_PTA_BT_LOW_PRTY_FALL_RESET                              0x0
#define WIFICMN_ISR_S3_ADDRESS                                                 (0x10 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_ISR_S3_RSTMASK                                                 0xff
#define WIFICMN_ISR_S3_RESET                                                   0x0

// 0x14 (WIFICMN_IMR_P)
#define WIFICMN_IMR_P_MEM_ERR_INTR_LSB                                         29
#define WIFICMN_IMR_P_MEM_ERR_INTR_MSB                                         29
#define WIFICMN_IMR_P_MEM_ERR_INTR_MASK                                        0x20000000
#define WIFICMN_IMR_P_MEM_ERR_INTR_GET(x)                                      (((x) & WIFICMN_IMR_P_MEM_ERR_INTR_MASK) >> WIFICMN_IMR_P_MEM_ERR_INTR_LSB)
#define WIFICMN_IMR_P_MEM_ERR_INTR_SET(x)                                      (((0 | (x)) << WIFICMN_IMR_P_MEM_ERR_INTR_LSB) & WIFICMN_IMR_P_MEM_ERR_INTR_MASK)
#define WIFICMN_IMR_P_MEM_ERR_INTR_RESET                                       0x0
#define WIFICMN_IMR_P_RTC_WDT_INTR_LSB                                         28
#define WIFICMN_IMR_P_RTC_WDT_INTR_MSB                                         28
#define WIFICMN_IMR_P_RTC_WDT_INTR_MASK                                        0x10000000
#define WIFICMN_IMR_P_RTC_WDT_INTR_GET(x)                                      (((x) & WIFICMN_IMR_P_RTC_WDT_INTR_MASK) >> WIFICMN_IMR_P_RTC_WDT_INTR_LSB)
#define WIFICMN_IMR_P_RTC_WDT_INTR_SET(x)                                      (((0 | (x)) << WIFICMN_IMR_P_RTC_WDT_INTR_LSB) & WIFICMN_IMR_P_RTC_WDT_INTR_MASK)
#define WIFICMN_IMR_P_RTC_WDT_INTR_RESET                                       0x0
#define WIFICMN_IMR_P_THERM_SENSOR_INTR_LSB                                    27
#define WIFICMN_IMR_P_THERM_SENSOR_INTR_MSB                                    27
#define WIFICMN_IMR_P_THERM_SENSOR_INTR_MASK                                   0x8000000
#define WIFICMN_IMR_P_THERM_SENSOR_INTR_GET(x)                                 (((x) & WIFICMN_IMR_P_THERM_SENSOR_INTR_MASK) >> WIFICMN_IMR_P_THERM_SENSOR_INTR_LSB)
#define WIFICMN_IMR_P_THERM_SENSOR_INTR_SET(x)                                 (((0 | (x)) << WIFICMN_IMR_P_THERM_SENSOR_INTR_LSB) & WIFICMN_IMR_P_THERM_SENSOR_INTR_MASK)
#define WIFICMN_IMR_P_THERM_SENSOR_INTR_RESET                                  0x0
#define WIFICMN_IMR_P_CE_WATCHDOG_ERR_INTR_LSB                                 26
#define WIFICMN_IMR_P_CE_WATCHDOG_ERR_INTR_MSB                                 26
#define WIFICMN_IMR_P_CE_WATCHDOG_ERR_INTR_MASK                                0x4000000
#define WIFICMN_IMR_P_CE_WATCHDOG_ERR_INTR_GET(x)                              (((x) & WIFICMN_IMR_P_CE_WATCHDOG_ERR_INTR_MASK) >> WIFICMN_IMR_P_CE_WATCHDOG_ERR_INTR_LSB)
#define WIFICMN_IMR_P_CE_WATCHDOG_ERR_INTR_SET(x)                              (((0 | (x)) << WIFICMN_IMR_P_CE_WATCHDOG_ERR_INTR_LSB) & WIFICMN_IMR_P_CE_WATCHDOG_ERR_INTR_MASK)
#define WIFICMN_IMR_P_CE_WATCHDOG_ERR_INTR_RESET                               0x0
#define WIFICMN_IMR_P_PCIE_WAKE_INTR_LSB                                       25
#define WIFICMN_IMR_P_PCIE_WAKE_INTR_MSB                                       25
#define WIFICMN_IMR_P_PCIE_WAKE_INTR_MASK                                      0x2000000
#define WIFICMN_IMR_P_PCIE_WAKE_INTR_GET(x)                                    (((x) & WIFICMN_IMR_P_PCIE_WAKE_INTR_MASK) >> WIFICMN_IMR_P_PCIE_WAKE_INTR_LSB)
#define WIFICMN_IMR_P_PCIE_WAKE_INTR_SET(x)                                    (((0 | (x)) << WIFICMN_IMR_P_PCIE_WAKE_INTR_LSB) & WIFICMN_IMR_P_PCIE_WAKE_INTR_MASK)
#define WIFICMN_IMR_P_PCIE_WAKE_INTR_RESET                                     0x0
#define WIFICMN_IMR_P_EFUSE_ERR_INTR_LSB                                       24
#define WIFICMN_IMR_P_EFUSE_ERR_INTR_MSB                                       24
#define WIFICMN_IMR_P_EFUSE_ERR_INTR_MASK                                      0x1000000
#define WIFICMN_IMR_P_EFUSE_ERR_INTR_GET(x)                                    (((x) & WIFICMN_IMR_P_EFUSE_ERR_INTR_MASK) >> WIFICMN_IMR_P_EFUSE_ERR_INTR_LSB)
#define WIFICMN_IMR_P_EFUSE_ERR_INTR_SET(x)                                    (((0 | (x)) << WIFICMN_IMR_P_EFUSE_ERR_INTR_LSB) & WIFICMN_IMR_P_EFUSE_ERR_INTR_MASK)
#define WIFICMN_IMR_P_EFUSE_ERR_INTR_RESET                                     0x0
#define WIFICMN_IMR_P_INVALID_BB_INTR_LSB                                      23
#define WIFICMN_IMR_P_INVALID_BB_INTR_MSB                                      23
#define WIFICMN_IMR_P_INVALID_BB_INTR_MASK                                     0x800000
#define WIFICMN_IMR_P_INVALID_BB_INTR_GET(x)                                   (((x) & WIFICMN_IMR_P_INVALID_BB_INTR_MASK) >> WIFICMN_IMR_P_INVALID_BB_INTR_LSB)
#define WIFICMN_IMR_P_INVALID_BB_INTR_SET(x)                                   (((0 | (x)) << WIFICMN_IMR_P_INVALID_BB_INTR_LSB) & WIFICMN_IMR_P_INVALID_BB_INTR_MASK)
#define WIFICMN_IMR_P_INVALID_BB_INTR_RESET                                    0x0
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_1_LSB                                     22
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_1_MSB                                     22
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_1_MASK                                    0x400000
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_1_GET(x)                                  (((x) & WIFICMN_IMR_P_WMAC_MCMN_INTR_1_MASK) >> WIFICMN_IMR_P_WMAC_MCMN_INTR_1_LSB)
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_1_SET(x)                                  (((0 | (x)) << WIFICMN_IMR_P_WMAC_MCMN_INTR_1_LSB) & WIFICMN_IMR_P_WMAC_MCMN_INTR_1_MASK)
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_1_RESET                                   0x0
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_2_LSB                                     21
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_2_MSB                                     21
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_2_MASK                                    0x200000
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_2_GET(x)                                  (((x) & WIFICMN_IMR_P_WMAC_MCMN_INTR_2_MASK) >> WIFICMN_IMR_P_WMAC_MCMN_INTR_2_LSB)
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_2_SET(x)                                  (((0 | (x)) << WIFICMN_IMR_P_WMAC_MCMN_INTR_2_LSB) & WIFICMN_IMR_P_WMAC_MCMN_INTR_2_MASK)
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_2_RESET                                   0x0
#define WIFICMN_IMR_P_HOST_REG_INTR_LSB                                        20
#define WIFICMN_IMR_P_HOST_REG_INTR_MSB                                        20
#define WIFICMN_IMR_P_HOST_REG_INTR_MASK                                       0x100000
#define WIFICMN_IMR_P_HOST_REG_INTR_GET(x)                                     (((x) & WIFICMN_IMR_P_HOST_REG_INTR_MASK) >> WIFICMN_IMR_P_HOST_REG_INTR_LSB)
#define WIFICMN_IMR_P_HOST_REG_INTR_SET(x)                                     (((0 | (x)) << WIFICMN_IMR_P_HOST_REG_INTR_LSB) & WIFICMN_IMR_P_HOST_REG_INTR_MASK)
#define WIFICMN_IMR_P_HOST_REG_INTR_RESET                                      0x0
#define WIFICMN_IMR_P_CE_INTR_LSB                                              8
#define WIFICMN_IMR_P_CE_INTR_MSB                                              19
#define WIFICMN_IMR_P_CE_INTR_MASK                                             0xfff00
#define WIFICMN_IMR_P_CE_INTR_GET(x)                                           (((x) & WIFICMN_IMR_P_CE_INTR_MASK) >> WIFICMN_IMR_P_CE_INTR_LSB)
#define WIFICMN_IMR_P_CE_INTR_SET(x)                                           (((0 | (x)) << WIFICMN_IMR_P_CE_INTR_LSB) & WIFICMN_IMR_P_CE_INTR_MASK)
#define WIFICMN_IMR_P_CE_INTR_RESET                                            0x0
#define WIFICMN_IMR_P_LF_HF_TIMER_INTR_LSB                                     6
#define WIFICMN_IMR_P_LF_HF_TIMER_INTR_MSB                                     6
#define WIFICMN_IMR_P_LF_HF_TIMER_INTR_MASK                                    0x40
#define WIFICMN_IMR_P_LF_HF_TIMER_INTR_GET(x)                                  (((x) & WIFICMN_IMR_P_LF_HF_TIMER_INTR_MASK) >> WIFICMN_IMR_P_LF_HF_TIMER_INTR_LSB)
#define WIFICMN_IMR_P_LF_HF_TIMER_INTR_SET(x)                                  (((0 | (x)) << WIFICMN_IMR_P_LF_HF_TIMER_INTR_LSB) & WIFICMN_IMR_P_LF_HF_TIMER_INTR_MASK)
#define WIFICMN_IMR_P_LF_HF_TIMER_INTR_RESET                                   0x0
#define WIFICMN_IMR_P_GPIO_INTR_LSB                                            5
#define WIFICMN_IMR_P_GPIO_INTR_MSB                                            5
#define WIFICMN_IMR_P_GPIO_INTR_MASK                                           0x20
#define WIFICMN_IMR_P_GPIO_INTR_GET(x)                                         (((x) & WIFICMN_IMR_P_GPIO_INTR_MASK) >> WIFICMN_IMR_P_GPIO_INTR_LSB)
#define WIFICMN_IMR_P_GPIO_INTR_SET(x)                                         (((0 | (x)) << WIFICMN_IMR_P_GPIO_INTR_LSB) & WIFICMN_IMR_P_GPIO_INTR_MASK)
#define WIFICMN_IMR_P_GPIO_INTR_RESET                                          0x0
#define WIFICMN_IMR_P_SI_UART_INTR_LSB                                         4
#define WIFICMN_IMR_P_SI_UART_INTR_MSB                                         4
#define WIFICMN_IMR_P_SI_UART_INTR_MASK                                        0x10
#define WIFICMN_IMR_P_SI_UART_INTR_GET(x)                                      (((x) & WIFICMN_IMR_P_SI_UART_INTR_MASK) >> WIFICMN_IMR_P_SI_UART_INTR_LSB)
#define WIFICMN_IMR_P_SI_UART_INTR_SET(x)                                      (((0 | (x)) << WIFICMN_IMR_P_SI_UART_INTR_LSB) & WIFICMN_IMR_P_SI_UART_INTR_MASK)
#define WIFICMN_IMR_P_SI_UART_INTR_RESET                                       0x0
#define WIFICMN_IMR_P_RTC_INTR_LSB                                             3
#define WIFICMN_IMR_P_RTC_INTR_MSB                                             3
#define WIFICMN_IMR_P_RTC_INTR_MASK                                            0x8
#define WIFICMN_IMR_P_RTC_INTR_GET(x)                                          (((x) & WIFICMN_IMR_P_RTC_INTR_MASK) >> WIFICMN_IMR_P_RTC_INTR_LSB)
#define WIFICMN_IMR_P_RTC_INTR_SET(x)                                          (((0 | (x)) << WIFICMN_IMR_P_RTC_INTR_LSB) & WIFICMN_IMR_P_RTC_INTR_MASK)
#define WIFICMN_IMR_P_RTC_INTR_RESET                                           0x0
#define WIFICMN_IMR_P_WIFI_TIMER_INTR_LSB                                      2
#define WIFICMN_IMR_P_WIFI_TIMER_INTR_MSB                                      2
#define WIFICMN_IMR_P_WIFI_TIMER_INTR_MASK                                     0x4
#define WIFICMN_IMR_P_WIFI_TIMER_INTR_GET(x)                                   (((x) & WIFICMN_IMR_P_WIFI_TIMER_INTR_MASK) >> WIFICMN_IMR_P_WIFI_TIMER_INTR_LSB)
#define WIFICMN_IMR_P_WIFI_TIMER_INTR_SET(x)                                   (((0 | (x)) << WIFICMN_IMR_P_WIFI_TIMER_INTR_LSB) & WIFICMN_IMR_P_WIFI_TIMER_INTR_MASK)
#define WIFICMN_IMR_P_WIFI_TIMER_INTR_RESET                                    0x0
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_3_LSB                                     1
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_3_MSB                                     1
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_3_MASK                                    0x2
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_3_GET(x)                                  (((x) & WIFICMN_IMR_P_WMAC_MCMN_INTR_3_MASK) >> WIFICMN_IMR_P_WMAC_MCMN_INTR_3_LSB)
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_3_SET(x)                                  (((0 | (x)) << WIFICMN_IMR_P_WMAC_MCMN_INTR_3_LSB) & WIFICMN_IMR_P_WMAC_MCMN_INTR_3_MASK)
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_3_RESET                                   0x0
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_0_LSB                                     0
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_0_MSB                                     0
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_0_MASK                                    0x1
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_0_GET(x)                                  (((x) & WIFICMN_IMR_P_WMAC_MCMN_INTR_0_MASK) >> WIFICMN_IMR_P_WMAC_MCMN_INTR_0_LSB)
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_0_SET(x)                                  (((0 | (x)) << WIFICMN_IMR_P_WMAC_MCMN_INTR_0_LSB) & WIFICMN_IMR_P_WMAC_MCMN_INTR_0_MASK)
#define WIFICMN_IMR_P_WMAC_MCMN_INTR_0_RESET                                   0x0
#define WIFICMN_IMR_P_ADDRESS                                                  (0x14 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_IMR_P_RSTMASK                                                  0x3fffff7f
#define WIFICMN_IMR_P_RESET                                                    0x0

// 0x18 (WIFICMN_IMR_P_CONTD)
#define WIFICMN_IMR_P_CONTD_RFFE_M_LSB                                         2
#define WIFICMN_IMR_P_CONTD_RFFE_M_MSB                                         2
#define WIFICMN_IMR_P_CONTD_RFFE_M_MASK                                        0x4
#define WIFICMN_IMR_P_CONTD_RFFE_M_GET(x)                                      (((x) & WIFICMN_IMR_P_CONTD_RFFE_M_MASK) >> WIFICMN_IMR_P_CONTD_RFFE_M_LSB)
#define WIFICMN_IMR_P_CONTD_RFFE_M_SET(x)                                      (((0 | (x)) << WIFICMN_IMR_P_CONTD_RFFE_M_LSB) & WIFICMN_IMR_P_CONTD_RFFE_M_MASK)
#define WIFICMN_IMR_P_CONTD_RFFE_M_RESET                                       0x0
#define WIFICMN_IMR_P_CONTD_LTE_COEX_LSB                                       1
#define WIFICMN_IMR_P_CONTD_LTE_COEX_MSB                                       1
#define WIFICMN_IMR_P_CONTD_LTE_COEX_MASK                                      0x2
#define WIFICMN_IMR_P_CONTD_LTE_COEX_GET(x)                                    (((x) & WIFICMN_IMR_P_CONTD_LTE_COEX_MASK) >> WIFICMN_IMR_P_CONTD_LTE_COEX_LSB)
#define WIFICMN_IMR_P_CONTD_LTE_COEX_SET(x)                                    (((0 | (x)) << WIFICMN_IMR_P_CONTD_LTE_COEX_LSB) & WIFICMN_IMR_P_CONTD_LTE_COEX_MASK)
#define WIFICMN_IMR_P_CONTD_LTE_COEX_RESET                                     0x0
#define WIFICMN_IMR_P_CONTD_PTA_COEX_LSB                                       0
#define WIFICMN_IMR_P_CONTD_PTA_COEX_MSB                                       0
#define WIFICMN_IMR_P_CONTD_PTA_COEX_MASK                                      0x1
#define WIFICMN_IMR_P_CONTD_PTA_COEX_GET(x)                                    (((x) & WIFICMN_IMR_P_CONTD_PTA_COEX_MASK) >> WIFICMN_IMR_P_CONTD_PTA_COEX_LSB)
#define WIFICMN_IMR_P_CONTD_PTA_COEX_SET(x)                                    (((0 | (x)) << WIFICMN_IMR_P_CONTD_PTA_COEX_LSB) & WIFICMN_IMR_P_CONTD_PTA_COEX_MASK)
#define WIFICMN_IMR_P_CONTD_PTA_COEX_RESET                                     0x0
#define WIFICMN_IMR_P_CONTD_ADDRESS                                            (0x18 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_IMR_P_CONTD_RSTMASK                                            0x7
#define WIFICMN_IMR_P_CONTD_RESET                                              0x0

// 0x1c (WIFICMN_IMR_S0)
#define WIFICMN_IMR_S0_PCU_DTIM_SYNC_LSB                                       10
#define WIFICMN_IMR_S0_PCU_DTIM_SYNC_MSB                                       11
#define WIFICMN_IMR_S0_PCU_DTIM_SYNC_MASK                                      0xc00
#define WIFICMN_IMR_S0_PCU_DTIM_SYNC_GET(x)                                    (((x) & WIFICMN_IMR_S0_PCU_DTIM_SYNC_MASK) >> WIFICMN_IMR_S0_PCU_DTIM_SYNC_LSB)
#define WIFICMN_IMR_S0_PCU_DTIM_SYNC_SET(x)                                    (((0 | (x)) << WIFICMN_IMR_S0_PCU_DTIM_SYNC_LSB) & WIFICMN_IMR_S0_PCU_DTIM_SYNC_MASK)
#define WIFICMN_IMR_S0_PCU_DTIM_SYNC_RESET                                     0x0
#define WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_LSB                                  8
#define WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_MSB                                  9
#define WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_MASK                                 0x300
#define WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_GET(x)                               (((x) & WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_MASK) >> WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_LSB)
#define WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_SET(x)                               (((0 | (x)) << WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_LSB) & WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_MASK)
#define WIFICMN_IMR_S0_PCU_BEACON_TIMEOUT_RESET                                0x0
#define WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_LSB                                     6
#define WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_MSB                                     7
#define WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_MASK                                    0xc0
#define WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_GET(x)                                  (((x) & WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_MASK) >> WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_LSB)
#define WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_SET(x)                                  (((0 | (x)) << WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_LSB) & WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_MASK)
#define WIFICMN_IMR_S0_PCU_CAB_TIMEOUT_RESET                                   0x0
#define WIFICMN_IMR_S0_PCU_CAB_NO_MORE_LSB                                     4
#define WIFICMN_IMR_S0_PCU_CAB_NO_MORE_MSB                                     5
#define WIFICMN_IMR_S0_PCU_CAB_NO_MORE_MASK                                    0x30
#define WIFICMN_IMR_S0_PCU_CAB_NO_MORE_GET(x)                                  (((x) & WIFICMN_IMR_S0_PCU_CAB_NO_MORE_MASK) >> WIFICMN_IMR_S0_PCU_CAB_NO_MORE_LSB)
#define WIFICMN_IMR_S0_PCU_CAB_NO_MORE_SET(x)                                  (((0 | (x)) << WIFICMN_IMR_S0_PCU_CAB_NO_MORE_LSB) & WIFICMN_IMR_S0_PCU_CAB_NO_MORE_MASK)
#define WIFICMN_IMR_S0_PCU_CAB_NO_MORE_RESET                                   0x0
#define WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_LSB                                2
#define WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_MSB                                3
#define WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_MASK                               0xc
#define WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_GET(x)                             (((x) & WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_MASK) >> WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_LSB)
#define WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_SET(x)                             (((0 | (x)) << WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_LSB) & WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_MASK)
#define WIFICMN_IMR_S0_PCU_TSF_OUT_OF_RANGE_RESET                              0x0
#define WIFICMN_IMR_S0_PCU_SLP32_CYCLE_CNT_LSB                                 1
#define WIFICMN_IMR_S0_PCU_SLP32_CYCLE_CNT_MSB                                 1
#define WIFICMN_IMR_S0_PCU_SLP32_CYCLE_CNT_MASK                                0x2
#define WIFICMN_IMR_S0_PCU_SLP32_CYCLE_CNT_GET(x)                              (((x) & WIFICMN_IMR_S0_PCU_SLP32_CYCLE_CNT_MASK) >> WIFICMN_IMR_S0_PCU_SLP32_CYCLE_CNT_LSB)
#define WIFICMN_IMR_S0_PCU_SLP32_CYCLE_CNT_SET(x)                              (((0 | (x)) << WIFICMN_IMR_S0_PCU_SLP32_CYCLE_CNT_LSB) & WIFICMN_IMR_S0_PCU_SLP32_CYCLE_CNT_MASK)
#define WIFICMN_IMR_S0_PCU_SLP32_CYCLE_CNT_RESET                               0x0
#define WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_LSB                                0
#define WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_MSB                                0
#define WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_MASK                               0x1
#define WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_GET(x)                             (((x) & WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_MASK) >> WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_LSB)
#define WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_SET(x)                             (((0 | (x)) << WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_LSB) & WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_MASK)
#define WIFICMN_IMR_S0_PCU_GEN_TIMER_OVRFLW_RESET                              0x0
#define WIFICMN_IMR_S0_ADDRESS                                                 (0x1c + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_IMR_S0_RSTMASK                                                 0xfff
#define WIFICMN_IMR_S0_RESET                                                   0x0

// 0x20 (WIFICMN_IMR_S1)
#define WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_LSB                                16
#define WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_MSB                                31
#define WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_MASK                               0xffff0000
#define WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_GET(x)                             (((x) & WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_MASK) >> WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_LSB)
#define WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_SET(x)                             (((0 | (x)) << WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_LSB) & WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_MASK)
#define WIFICMN_IMR_S1_PCU_GEN_TIMER_THRESH_RESET                              0x0
#define WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_LSB                               0
#define WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_MSB                               15
#define WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_MASK                              0xffff
#define WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_GET(x)                            (((x) & WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_MASK) >> WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_LSB)
#define WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_SET(x)                            (((0 | (x)) << WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_LSB) & WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_MASK)
#define WIFICMN_IMR_S1_PCU_GEN_TIMER_TRIGGER_RESET                             0x0
#define WIFICMN_IMR_S1_ADDRESS                                                 (0x20 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_IMR_S1_RSTMASK                                                 0xffffffff
#define WIFICMN_IMR_S1_RESET                                                   0x0

// 0x28 (WIFICMN_IMR_S2)
#define WIFICMN_IMR_S2_INVALID_BB_LSB                                          2
#define WIFICMN_IMR_S2_INVALID_BB_MSB                                          2
#define WIFICMN_IMR_S2_INVALID_BB_MASK                                         0x4
#define WIFICMN_IMR_S2_INVALID_BB_GET(x)                                       (((x) & WIFICMN_IMR_S2_INVALID_BB_MASK) >> WIFICMN_IMR_S2_INVALID_BB_LSB)
#define WIFICMN_IMR_S2_INVALID_BB_SET(x)                                       (((0 | (x)) << WIFICMN_IMR_S2_INVALID_BB_LSB) & WIFICMN_IMR_S2_INVALID_BB_MASK)
#define WIFICMN_IMR_S2_INVALID_BB_RESET                                        0x0
#define WIFICMN_IMR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_LSB                          1
#define WIFICMN_IMR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_MSB                          1
#define WIFICMN_IMR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_MASK                         0x2
#define WIFICMN_IMR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_GET(x)                       (((x) & WIFICMN_IMR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_MASK) >> WIFICMN_IMR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_LSB)
#define WIFICMN_IMR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_SET(x)                       (((0 | (x)) << WIFICMN_IMR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_LSB) & WIFICMN_IMR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_MASK)
#define WIFICMN_IMR_S2_PMI_CPU_PANIC_WATCHDOG_IRQ_RESET                        0x0
#define WIFICMN_IMR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_LSB                       0
#define WIFICMN_IMR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_MSB                       0
#define WIFICMN_IMR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_MASK                      0x1
#define WIFICMN_IMR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_GET(x)                    (((x) & WIFICMN_IMR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_MASK) >> WIFICMN_IMR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_LSB)
#define WIFICMN_IMR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_SET(x)                    (((0 | (x)) << WIFICMN_IMR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_LSB) & WIFICMN_IMR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_MASK)
#define WIFICMN_IMR_S2_FECNTL_CPU_PANIC_WATCHDOG_IRQ_RESET                     0x0
#define WIFICMN_IMR_S2_ADDRESS                                                 (0x28 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_IMR_S2_RSTMASK                                                 0x7
#define WIFICMN_IMR_S2_RESET                                                   0x0

// 0x2c (WIFICMN_IMR_S3)
#define WIFICMN_IMR_S3_PTA_WL_STOMPED_LSB                                      7
#define WIFICMN_IMR_S3_PTA_WL_STOMPED_MSB                                      7
#define WIFICMN_IMR_S3_PTA_WL_STOMPED_MASK                                     0x80
#define WIFICMN_IMR_S3_PTA_WL_STOMPED_GET(x)                                   (((x) & WIFICMN_IMR_S3_PTA_WL_STOMPED_MASK) >> WIFICMN_IMR_S3_PTA_WL_STOMPED_LSB)
#define WIFICMN_IMR_S3_PTA_WL_STOMPED_SET(x)                                   (((0 | (x)) << WIFICMN_IMR_S3_PTA_WL_STOMPED_LSB) & WIFICMN_IMR_S3_PTA_WL_STOMPED_MASK)
#define WIFICMN_IMR_S3_PTA_WL_STOMPED_RESET                                    0x0
#define WIFICMN_IMR_S3_PTA_BT_STOMPED_LSB                                      6
#define WIFICMN_IMR_S3_PTA_BT_STOMPED_MSB                                      6
#define WIFICMN_IMR_S3_PTA_BT_STOMPED_MASK                                     0x40
#define WIFICMN_IMR_S3_PTA_BT_STOMPED_GET(x)                                   (((x) & WIFICMN_IMR_S3_PTA_BT_STOMPED_MASK) >> WIFICMN_IMR_S3_PTA_BT_STOMPED_LSB)
#define WIFICMN_IMR_S3_PTA_BT_STOMPED_SET(x)                                   (((0 | (x)) << WIFICMN_IMR_S3_PTA_BT_STOMPED_LSB) & WIFICMN_IMR_S3_PTA_BT_STOMPED_MASK)
#define WIFICMN_IMR_S3_PTA_BT_STOMPED_RESET                                    0x0
#define WIFICMN_IMR_S3_PTA_BT_ACTIVE_RISE_LSB                                  5
#define WIFICMN_IMR_S3_PTA_BT_ACTIVE_RISE_MSB                                  5
#define WIFICMN_IMR_S3_PTA_BT_ACTIVE_RISE_MASK                                 0x20
#define WIFICMN_IMR_S3_PTA_BT_ACTIVE_RISE_GET(x)                               (((x) & WIFICMN_IMR_S3_PTA_BT_ACTIVE_RISE_MASK) >> WIFICMN_IMR_S3_PTA_BT_ACTIVE_RISE_LSB)
#define WIFICMN_IMR_S3_PTA_BT_ACTIVE_RISE_SET(x)                               (((0 | (x)) << WIFICMN_IMR_S3_PTA_BT_ACTIVE_RISE_LSB) & WIFICMN_IMR_S3_PTA_BT_ACTIVE_RISE_MASK)
#define WIFICMN_IMR_S3_PTA_BT_ACTIVE_RISE_RESET                                0x0
#define WIFICMN_IMR_S3_PTA_BT_ACTIVE_FALL_LSB                                  4
#define WIFICMN_IMR_S3_PTA_BT_ACTIVE_FALL_MSB                                  4
#define WIFICMN_IMR_S3_PTA_BT_ACTIVE_FALL_MASK                                 0x10
#define WIFICMN_IMR_S3_PTA_BT_ACTIVE_FALL_GET(x)                               (((x) & WIFICMN_IMR_S3_PTA_BT_ACTIVE_FALL_MASK) >> WIFICMN_IMR_S3_PTA_BT_ACTIVE_FALL_LSB)
#define WIFICMN_IMR_S3_PTA_BT_ACTIVE_FALL_SET(x)                               (((0 | (x)) << WIFICMN_IMR_S3_PTA_BT_ACTIVE_FALL_LSB) & WIFICMN_IMR_S3_PTA_BT_ACTIVE_FALL_MASK)
#define WIFICMN_IMR_S3_PTA_BT_ACTIVE_FALL_RESET                                0x0
#define WIFICMN_IMR_S3_PTA_BT_PRIORITY_RISE_LSB                                3
#define WIFICMN_IMR_S3_PTA_BT_PRIORITY_RISE_MSB                                3
#define WIFICMN_IMR_S3_PTA_BT_PRIORITY_RISE_MASK                               0x8
#define WIFICMN_IMR_S3_PTA_BT_PRIORITY_RISE_GET(x)                             (((x) & WIFICMN_IMR_S3_PTA_BT_PRIORITY_RISE_MASK) >> WIFICMN_IMR_S3_PTA_BT_PRIORITY_RISE_LSB)
#define WIFICMN_IMR_S3_PTA_BT_PRIORITY_RISE_SET(x)                             (((0 | (x)) << WIFICMN_IMR_S3_PTA_BT_PRIORITY_RISE_LSB) & WIFICMN_IMR_S3_PTA_BT_PRIORITY_RISE_MASK)
#define WIFICMN_IMR_S3_PTA_BT_PRIORITY_RISE_RESET                              0x0
#define WIFICMN_IMR_S3_PTA_BT_PRIORITY_FALL_LSB                                2
#define WIFICMN_IMR_S3_PTA_BT_PRIORITY_FALL_MSB                                2
#define WIFICMN_IMR_S3_PTA_BT_PRIORITY_FALL_MASK                               0x4
#define WIFICMN_IMR_S3_PTA_BT_PRIORITY_FALL_GET(x)                             (((x) & WIFICMN_IMR_S3_PTA_BT_PRIORITY_FALL_MASK) >> WIFICMN_IMR_S3_PTA_BT_PRIORITY_FALL_LSB)
#define WIFICMN_IMR_S3_PTA_BT_PRIORITY_FALL_SET(x)                             (((0 | (x)) << WIFICMN_IMR_S3_PTA_BT_PRIORITY_FALL_LSB) & WIFICMN_IMR_S3_PTA_BT_PRIORITY_FALL_MASK)
#define WIFICMN_IMR_S3_PTA_BT_PRIORITY_FALL_RESET                              0x0
#define WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_RISE_LSB                                1
#define WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_RISE_MSB                                1
#define WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_RISE_MASK                               0x2
#define WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_RISE_GET(x)                             (((x) & WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_RISE_MASK) >> WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_RISE_LSB)
#define WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_RISE_SET(x)                             (((0 | (x)) << WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_RISE_LSB) & WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_RISE_MASK)
#define WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_RISE_RESET                              0x0
#define WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_FALL_LSB                                0
#define WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_FALL_MSB                                0
#define WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_FALL_MASK                               0x1
#define WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_FALL_GET(x)                             (((x) & WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_FALL_MASK) >> WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_FALL_LSB)
#define WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_FALL_SET(x)                             (((0 | (x)) << WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_FALL_LSB) & WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_FALL_MASK)
#define WIFICMN_IMR_S3_PTA_BT_LOW_PRTY_FALL_RESET                              0x0
#define WIFICMN_IMR_S3_ADDRESS                                                 (0x2c + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_IMR_S3_RSTMASK                                                 0xff
#define WIFICMN_IMR_S3_RESET                                                   0x0

// 0x30 (WIFICMN_PCIE_BAR_REG)
#define WIFICMN_PCIE_BAR_REG_PCIE_BAR_REG_LSB                                  0
#define WIFICMN_PCIE_BAR_REG_PCIE_BAR_REG_MSB                                  31
#define WIFICMN_PCIE_BAR_REG_PCIE_BAR_REG_MASK                                 0xffffffff
#define WIFICMN_PCIE_BAR_REG_PCIE_BAR_REG_GET(x)                               (((x) & WIFICMN_PCIE_BAR_REG_PCIE_BAR_REG_MASK) >> WIFICMN_PCIE_BAR_REG_PCIE_BAR_REG_LSB)
#define WIFICMN_PCIE_BAR_REG_PCIE_BAR_REG_SET(x)                               (((0 | (x)) << WIFICMN_PCIE_BAR_REG_PCIE_BAR_REG_LSB) & WIFICMN_PCIE_BAR_REG_PCIE_BAR_REG_MASK)
#define WIFICMN_PCIE_BAR_REG_PCIE_BAR_REG_RESET                                0x0
#define WIFICMN_PCIE_BAR_REG_ADDRESS                                           (0x30 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_PCIE_BAR_REG_RSTMASK                                           0xffffffff
#define WIFICMN_PCIE_BAR_REG_RESET                                             0x0

// 0x34 (WIFICMN_CTRL_REG)
#define WIFICMN_CTRL_REG_PCIE_ADDR_31_LSB                                      0
#define WIFICMN_CTRL_REG_PCIE_ADDR_31_MSB                                      0
#define WIFICMN_CTRL_REG_PCIE_ADDR_31_MASK                                     0x1
#define WIFICMN_CTRL_REG_PCIE_ADDR_31_GET(x)                                   (((x) & WIFICMN_CTRL_REG_PCIE_ADDR_31_MASK) >> WIFICMN_CTRL_REG_PCIE_ADDR_31_LSB)
#define WIFICMN_CTRL_REG_PCIE_ADDR_31_SET(x)                                   (((0 | (x)) << WIFICMN_CTRL_REG_PCIE_ADDR_31_LSB) & WIFICMN_CTRL_REG_PCIE_ADDR_31_MASK)
#define WIFICMN_CTRL_REG_PCIE_ADDR_31_RESET                                    0x0
#define WIFICMN_CTRL_REG_ADDRESS                                               (0x34 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_CTRL_REG_RSTMASK                                               0x1
#define WIFICMN_CTRL_REG_RESET                                                 0x0

// 0x38 (WIFICMN_CPU_MEM)
#define WIFICMN_CPU_MEM_IRAM_BAR_LSB                                           12
#define WIFICMN_CPU_MEM_IRAM_BAR_MSB                                           23
#define WIFICMN_CPU_MEM_IRAM_BAR_MASK                                          0xfff000
#define WIFICMN_CPU_MEM_IRAM_BAR_GET(x)                                        (((x) & WIFICMN_CPU_MEM_IRAM_BAR_MASK) >> WIFICMN_CPU_MEM_IRAM_BAR_LSB)
#define WIFICMN_CPU_MEM_IRAM_BAR_SET(x)                                        (((0 | (x)) << WIFICMN_CPU_MEM_IRAM_BAR_LSB) & WIFICMN_CPU_MEM_IRAM_BAR_MASK)
#define WIFICMN_CPU_MEM_IRAM_BAR_RESET                                         0x9
#define WIFICMN_CPU_MEM_DRAM_BAR_LSB                                           0
#define WIFICMN_CPU_MEM_DRAM_BAR_MSB                                           11
#define WIFICMN_CPU_MEM_DRAM_BAR_MASK                                          0xfff
#define WIFICMN_CPU_MEM_DRAM_BAR_GET(x)                                        (((x) & WIFICMN_CPU_MEM_DRAM_BAR_MASK) >> WIFICMN_CPU_MEM_DRAM_BAR_LSB)
#define WIFICMN_CPU_MEM_DRAM_BAR_SET(x)                                        (((0 | (x)) << WIFICMN_CPU_MEM_DRAM_BAR_LSB) & WIFICMN_CPU_MEM_DRAM_BAR_MASK)
#define WIFICMN_CPU_MEM_DRAM_BAR_RESET                                         0x4
#define WIFICMN_CPU_MEM_ADDRESS                                                (0x38 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_CPU_MEM_RSTMASK                                                0xffffff
#define WIFICMN_CPU_MEM_RESET                                                  0x9004

// 0x3c (WIFICMN_WOCLR_ISR_P_EN)
#define WIFICMN_WOCLR_ISR_P_EN_VAL_LSB                                         0
#define WIFICMN_WOCLR_ISR_P_EN_VAL_MSB                                         0
#define WIFICMN_WOCLR_ISR_P_EN_VAL_MASK                                        0x1
#define WIFICMN_WOCLR_ISR_P_EN_VAL_GET(x)                                      (((x) & WIFICMN_WOCLR_ISR_P_EN_VAL_MASK) >> WIFICMN_WOCLR_ISR_P_EN_VAL_LSB)
#define WIFICMN_WOCLR_ISR_P_EN_VAL_SET(x)                                      (((0 | (x)) << WIFICMN_WOCLR_ISR_P_EN_VAL_LSB) & WIFICMN_WOCLR_ISR_P_EN_VAL_MASK)
#define WIFICMN_WOCLR_ISR_P_EN_VAL_RESET                                       0x0
#define WIFICMN_WOCLR_ISR_P_EN_ADDRESS                                         (0x3c + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_WOCLR_ISR_P_EN_RSTMASK                                         0x1
#define WIFICMN_WOCLR_ISR_P_EN_RESET                                           0x0

// 0x40 (WIFICMN_LF_HF_WDT_INT_STATUS)
#define WIFICMN_LF_HF_WDT_INT_STATUS_WDT_LSB                                   5
#define WIFICMN_LF_HF_WDT_INT_STATUS_WDT_MSB                                   5
#define WIFICMN_LF_HF_WDT_INT_STATUS_WDT_MASK                                  0x20
#define WIFICMN_LF_HF_WDT_INT_STATUS_WDT_GET(x)                                (((x) & WIFICMN_LF_HF_WDT_INT_STATUS_WDT_MASK) >> WIFICMN_LF_HF_WDT_INT_STATUS_WDT_LSB)
#define WIFICMN_LF_HF_WDT_INT_STATUS_WDT_SET(x)                                (((0 | (x)) << WIFICMN_LF_HF_WDT_INT_STATUS_WDT_LSB) & WIFICMN_LF_HF_WDT_INT_STATUS_WDT_MASK)
#define WIFICMN_LF_HF_WDT_INT_STATUS_WDT_RESET                                 0x0
#define WIFICMN_LF_HF_WDT_INT_STATUS_HF_TIMER_LSB                              4
#define WIFICMN_LF_HF_WDT_INT_STATUS_HF_TIMER_MSB                              4
#define WIFICMN_LF_HF_WDT_INT_STATUS_HF_TIMER_MASK                             0x10
#define WIFICMN_LF_HF_WDT_INT_STATUS_HF_TIMER_GET(x)                           (((x) & WIFICMN_LF_HF_WDT_INT_STATUS_HF_TIMER_MASK) >> WIFICMN_LF_HF_WDT_INT_STATUS_HF_TIMER_LSB)
#define WIFICMN_LF_HF_WDT_INT_STATUS_HF_TIMER_SET(x)                           (((0 | (x)) << WIFICMN_LF_HF_WDT_INT_STATUS_HF_TIMER_LSB) & WIFICMN_LF_HF_WDT_INT_STATUS_HF_TIMER_MASK)
#define WIFICMN_LF_HF_WDT_INT_STATUS_HF_TIMER_RESET                            0x0
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER3_LSB                             3
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER3_MSB                             3
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER3_MASK                            0x8
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER3_GET(x)                          (((x) & WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER3_MASK) >> WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER3_LSB)
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER3_SET(x)                          (((0 | (x)) << WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER3_LSB) & WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER3_MASK)
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER3_RESET                           0x0
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER2_LSB                             2
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER2_MSB                             2
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER2_MASK                            0x4
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER2_GET(x)                          (((x) & WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER2_MASK) >> WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER2_LSB)
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER2_SET(x)                          (((0 | (x)) << WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER2_LSB) & WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER2_MASK)
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER2_RESET                           0x0
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER1_LSB                             1
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER1_MSB                             1
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER1_MASK                            0x2
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER1_GET(x)                          (((x) & WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER1_MASK) >> WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER1_LSB)
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER1_SET(x)                          (((0 | (x)) << WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER1_LSB) & WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER1_MASK)
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER1_RESET                           0x0
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER0_LSB                             0
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER0_MSB                             0
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER0_MASK                            0x1
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER0_GET(x)                          (((x) & WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER0_MASK) >> WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER0_LSB)
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER0_SET(x)                          (((0 | (x)) << WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER0_LSB) & WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER0_MASK)
#define WIFICMN_LF_HF_WDT_INT_STATUS_LF_TIMER0_RESET                           0x0
#define WIFICMN_LF_HF_WDT_INT_STATUS_ADDRESS                                   (0x40 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_LF_HF_WDT_INT_STATUS_RSTMASK                                   0x3f
#define WIFICMN_LF_HF_WDT_INT_STATUS_RESET                                     0x0

// 0x44 (WIFICMN_SCRATCH_0)
#define WIFICMN_SCRATCH_0_VAL_LSB                                              0
#define WIFICMN_SCRATCH_0_VAL_MSB                                              31
#define WIFICMN_SCRATCH_0_VAL_MASK                                             0xffffffff
#define WIFICMN_SCRATCH_0_VAL_GET(x)                                           (((x) & WIFICMN_SCRATCH_0_VAL_MASK) >> WIFICMN_SCRATCH_0_VAL_LSB)
#define WIFICMN_SCRATCH_0_VAL_SET(x)                                           (((0 | (x)) << WIFICMN_SCRATCH_0_VAL_LSB) & WIFICMN_SCRATCH_0_VAL_MASK)
#define WIFICMN_SCRATCH_0_VAL_RESET                                            0x0
#define WIFICMN_SCRATCH_0_ADDRESS                                              (0x44 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_SCRATCH_0_RSTMASK                                              0xffffffff
#define WIFICMN_SCRATCH_0_RESET                                                0x0

// 0x48 (WIFICMN_SCRATCH_1)
#define WIFICMN_SCRATCH_1_VAL_LSB                                              0
#define WIFICMN_SCRATCH_1_VAL_MSB                                              31
#define WIFICMN_SCRATCH_1_VAL_MASK                                             0xffffffff
#define WIFICMN_SCRATCH_1_VAL_GET(x)                                           (((x) & WIFICMN_SCRATCH_1_VAL_MASK) >> WIFICMN_SCRATCH_1_VAL_LSB)
#define WIFICMN_SCRATCH_1_VAL_SET(x)                                           (((0 | (x)) << WIFICMN_SCRATCH_1_VAL_LSB) & WIFICMN_SCRATCH_1_VAL_MASK)
#define WIFICMN_SCRATCH_1_VAL_RESET                                            0x0
#define WIFICMN_SCRATCH_1_ADDRESS                                              (0x48 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_SCRATCH_1_RSTMASK                                              0xffffffff
#define WIFICMN_SCRATCH_1_RESET                                                0x0

// 0x4c (WIFICMN_SCRATCH_2)
#define WIFICMN_SCRATCH_2_VAL_LSB                                              0
#define WIFICMN_SCRATCH_2_VAL_MSB                                              31
#define WIFICMN_SCRATCH_2_VAL_MASK                                             0xffffffff
#define WIFICMN_SCRATCH_2_VAL_GET(x)                                           (((x) & WIFICMN_SCRATCH_2_VAL_MASK) >> WIFICMN_SCRATCH_2_VAL_LSB)
#define WIFICMN_SCRATCH_2_VAL_SET(x)                                           (((0 | (x)) << WIFICMN_SCRATCH_2_VAL_LSB) & WIFICMN_SCRATCH_2_VAL_MASK)
#define WIFICMN_SCRATCH_2_VAL_RESET                                            0x0
#define WIFICMN_SCRATCH_2_ADDRESS                                              (0x4c + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_SCRATCH_2_RSTMASK                                              0xffffffff
#define WIFICMN_SCRATCH_2_RESET                                                0x0

// 0x50 (WIFICMN_SCRATCH_3)
#define WIFICMN_SCRATCH_3_VAL_LSB                                              0
#define WIFICMN_SCRATCH_3_VAL_MSB                                              31
#define WIFICMN_SCRATCH_3_VAL_MASK                                             0xffffffff
#define WIFICMN_SCRATCH_3_VAL_GET(x)                                           (((x) & WIFICMN_SCRATCH_3_VAL_MASK) >> WIFICMN_SCRATCH_3_VAL_LSB)
#define WIFICMN_SCRATCH_3_VAL_SET(x)                                           (((0 | (x)) << WIFICMN_SCRATCH_3_VAL_LSB) & WIFICMN_SCRATCH_3_VAL_MASK)
#define WIFICMN_SCRATCH_3_VAL_RESET                                            0x0
#define WIFICMN_SCRATCH_3_ADDRESS                                              (0x50 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_SCRATCH_3_RSTMASK                                              0xffffffff
#define WIFICMN_SCRATCH_3_RESET                                                0x0

// 0x54 (WIFICMN_INT_STATUS)
#define WIFICMN_INT_STATUS_MEM_ERR_INTR_LSB                                    29
#define WIFICMN_INT_STATUS_MEM_ERR_INTR_MSB                                    29
#define WIFICMN_INT_STATUS_MEM_ERR_INTR_MASK                                   0x20000000
#define WIFICMN_INT_STATUS_MEM_ERR_INTR_GET(x)                                 (((x) & WIFICMN_INT_STATUS_MEM_ERR_INTR_MASK) >> WIFICMN_INT_STATUS_MEM_ERR_INTR_LSB)
#define WIFICMN_INT_STATUS_MEM_ERR_INTR_SET(x)                                 (((0 | (x)) << WIFICMN_INT_STATUS_MEM_ERR_INTR_LSB) & WIFICMN_INT_STATUS_MEM_ERR_INTR_MASK)
#define WIFICMN_INT_STATUS_MEM_ERR_INTR_RESET                                  0x0
#define WIFICMN_INT_STATUS_RTC_WDT_INTR_LSB                                    28
#define WIFICMN_INT_STATUS_RTC_WDT_INTR_MSB                                    28
#define WIFICMN_INT_STATUS_RTC_WDT_INTR_MASK                                   0x10000000
#define WIFICMN_INT_STATUS_RTC_WDT_INTR_GET(x)                                 (((x) & WIFICMN_INT_STATUS_RTC_WDT_INTR_MASK) >> WIFICMN_INT_STATUS_RTC_WDT_INTR_LSB)
#define WIFICMN_INT_STATUS_RTC_WDT_INTR_SET(x)                                 (((0 | (x)) << WIFICMN_INT_STATUS_RTC_WDT_INTR_LSB) & WIFICMN_INT_STATUS_RTC_WDT_INTR_MASK)
#define WIFICMN_INT_STATUS_RTC_WDT_INTR_RESET                                  0x0
#define WIFICMN_INT_STATUS_THERM_SENSOR_INTR_LSB                               27
#define WIFICMN_INT_STATUS_THERM_SENSOR_INTR_MSB                               27
#define WIFICMN_INT_STATUS_THERM_SENSOR_INTR_MASK                              0x8000000
#define WIFICMN_INT_STATUS_THERM_SENSOR_INTR_GET(x)                            (((x) & WIFICMN_INT_STATUS_THERM_SENSOR_INTR_MASK) >> WIFICMN_INT_STATUS_THERM_SENSOR_INTR_LSB)
#define WIFICMN_INT_STATUS_THERM_SENSOR_INTR_SET(x)                            (((0 | (x)) << WIFICMN_INT_STATUS_THERM_SENSOR_INTR_LSB) & WIFICMN_INT_STATUS_THERM_SENSOR_INTR_MASK)
#define WIFICMN_INT_STATUS_THERM_SENSOR_INTR_RESET                             0x0
#define WIFICMN_INT_STATUS_CE_WATCHDOG_ERR_INTR_LSB                            26
#define WIFICMN_INT_STATUS_CE_WATCHDOG_ERR_INTR_MSB                            26
#define WIFICMN_INT_STATUS_CE_WATCHDOG_ERR_INTR_MASK                           0x4000000
#define WIFICMN_INT_STATUS_CE_WATCHDOG_ERR_INTR_GET(x)                         (((x) & WIFICMN_INT_STATUS_CE_WATCHDOG_ERR_INTR_MASK) >> WIFICMN_INT_STATUS_CE_WATCHDOG_ERR_INTR_LSB)
#define WIFICMN_INT_STATUS_CE_WATCHDOG_ERR_INTR_SET(x)                         (((0 | (x)) << WIFICMN_INT_STATUS_CE_WATCHDOG_ERR_INTR_LSB) & WIFICMN_INT_STATUS_CE_WATCHDOG_ERR_INTR_MASK)
#define WIFICMN_INT_STATUS_CE_WATCHDOG_ERR_INTR_RESET                          0x0
#define WIFICMN_INT_STATUS_PCIE_WAKE_INTR_LSB                                  25
#define WIFICMN_INT_STATUS_PCIE_WAKE_INTR_MSB                                  25
#define WIFICMN_INT_STATUS_PCIE_WAKE_INTR_MASK                                 0x2000000
#define WIFICMN_INT_STATUS_PCIE_WAKE_INTR_GET(x)                               (((x) & WIFICMN_INT_STATUS_PCIE_WAKE_INTR_MASK) >> WIFICMN_INT_STATUS_PCIE_WAKE_INTR_LSB)
#define WIFICMN_INT_STATUS_PCIE_WAKE_INTR_SET(x)                               (((0 | (x)) << WIFICMN_INT_STATUS_PCIE_WAKE_INTR_LSB) & WIFICMN_INT_STATUS_PCIE_WAKE_INTR_MASK)
#define WIFICMN_INT_STATUS_PCIE_WAKE_INTR_RESET                                0x0
#define WIFICMN_INT_STATUS_EFUSE_ERR_INTR_LSB                                  24
#define WIFICMN_INT_STATUS_EFUSE_ERR_INTR_MSB                                  24
#define WIFICMN_INT_STATUS_EFUSE_ERR_INTR_MASK                                 0x1000000
#define WIFICMN_INT_STATUS_EFUSE_ERR_INTR_GET(x)                               (((x) & WIFICMN_INT_STATUS_EFUSE_ERR_INTR_MASK) >> WIFICMN_INT_STATUS_EFUSE_ERR_INTR_LSB)
#define WIFICMN_INT_STATUS_EFUSE_ERR_INTR_SET(x)                               (((0 | (x)) << WIFICMN_INT_STATUS_EFUSE_ERR_INTR_LSB) & WIFICMN_INT_STATUS_EFUSE_ERR_INTR_MASK)
#define WIFICMN_INT_STATUS_EFUSE_ERR_INTR_RESET                                0x0
#define WIFICMN_INT_STATUS_INVALID_BB_INTR_LSB                                 23
#define WIFICMN_INT_STATUS_INVALID_BB_INTR_MSB                                 23
#define WIFICMN_INT_STATUS_INVALID_BB_INTR_MASK                                0x800000
#define WIFICMN_INT_STATUS_INVALID_BB_INTR_GET(x)                              (((x) & WIFICMN_INT_STATUS_INVALID_BB_INTR_MASK) >> WIFICMN_INT_STATUS_INVALID_BB_INTR_LSB)
#define WIFICMN_INT_STATUS_INVALID_BB_INTR_SET(x)                              (((0 | (x)) << WIFICMN_INT_STATUS_INVALID_BB_INTR_LSB) & WIFICMN_INT_STATUS_INVALID_BB_INTR_MASK)
#define WIFICMN_INT_STATUS_INVALID_BB_INTR_RESET                               0x0
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_1_LSB                                22
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_1_MSB                                22
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_1_MASK                               0x400000
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_1_GET(x)                             (((x) & WIFICMN_INT_STATUS_WMAC_MCMN_INTR_1_MASK) >> WIFICMN_INT_STATUS_WMAC_MCMN_INTR_1_LSB)
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_1_SET(x)                             (((0 | (x)) << WIFICMN_INT_STATUS_WMAC_MCMN_INTR_1_LSB) & WIFICMN_INT_STATUS_WMAC_MCMN_INTR_1_MASK)
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_1_RESET                              0x0
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_2_LSB                                21
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_2_MSB                                21
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_2_MASK                               0x200000
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_2_GET(x)                             (((x) & WIFICMN_INT_STATUS_WMAC_MCMN_INTR_2_MASK) >> WIFICMN_INT_STATUS_WMAC_MCMN_INTR_2_LSB)
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_2_SET(x)                             (((0 | (x)) << WIFICMN_INT_STATUS_WMAC_MCMN_INTR_2_LSB) & WIFICMN_INT_STATUS_WMAC_MCMN_INTR_2_MASK)
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_2_RESET                              0x0
#define WIFICMN_INT_STATUS_HOST_REG_INTR_LSB                                   20
#define WIFICMN_INT_STATUS_HOST_REG_INTR_MSB                                   20
#define WIFICMN_INT_STATUS_HOST_REG_INTR_MASK                                  0x100000
#define WIFICMN_INT_STATUS_HOST_REG_INTR_GET(x)                                (((x) & WIFICMN_INT_STATUS_HOST_REG_INTR_MASK) >> WIFICMN_INT_STATUS_HOST_REG_INTR_LSB)
#define WIFICMN_INT_STATUS_HOST_REG_INTR_SET(x)                                (((0 | (x)) << WIFICMN_INT_STATUS_HOST_REG_INTR_LSB) & WIFICMN_INT_STATUS_HOST_REG_INTR_MASK)
#define WIFICMN_INT_STATUS_HOST_REG_INTR_RESET                                 0x0
#define WIFICMN_INT_STATUS_CE_INTR_LSB                                         8
#define WIFICMN_INT_STATUS_CE_INTR_MSB                                         19
#define WIFICMN_INT_STATUS_CE_INTR_MASK                                        0xfff00
#define WIFICMN_INT_STATUS_CE_INTR_GET(x)                                      (((x) & WIFICMN_INT_STATUS_CE_INTR_MASK) >> WIFICMN_INT_STATUS_CE_INTR_LSB)
#define WIFICMN_INT_STATUS_CE_INTR_SET(x)                                      (((0 | (x)) << WIFICMN_INT_STATUS_CE_INTR_LSB) & WIFICMN_INT_STATUS_CE_INTR_MASK)
#define WIFICMN_INT_STATUS_CE_INTR_RESET                                       0x0
#define WIFICMN_INT_STATUS_LF_HF_TIMER_INTR_LSB                                6
#define WIFICMN_INT_STATUS_LF_HF_TIMER_INTR_MSB                                6
#define WIFICMN_INT_STATUS_LF_HF_TIMER_INTR_MASK                               0x40
#define WIFICMN_INT_STATUS_LF_HF_TIMER_INTR_GET(x)                             (((x) & WIFICMN_INT_STATUS_LF_HF_TIMER_INTR_MASK) >> WIFICMN_INT_STATUS_LF_HF_TIMER_INTR_LSB)
#define WIFICMN_INT_STATUS_LF_HF_TIMER_INTR_SET(x)                             (((0 | (x)) << WIFICMN_INT_STATUS_LF_HF_TIMER_INTR_LSB) & WIFICMN_INT_STATUS_LF_HF_TIMER_INTR_MASK)
#define WIFICMN_INT_STATUS_LF_HF_TIMER_INTR_RESET                              0x0
#define WIFICMN_INT_STATUS_GPIO_INTR_LSB                                       5
#define WIFICMN_INT_STATUS_GPIO_INTR_MSB                                       5
#define WIFICMN_INT_STATUS_GPIO_INTR_MASK                                      0x20
#define WIFICMN_INT_STATUS_GPIO_INTR_GET(x)                                    (((x) & WIFICMN_INT_STATUS_GPIO_INTR_MASK) >> WIFICMN_INT_STATUS_GPIO_INTR_LSB)
#define WIFICMN_INT_STATUS_GPIO_INTR_SET(x)                                    (((0 | (x)) << WIFICMN_INT_STATUS_GPIO_INTR_LSB) & WIFICMN_INT_STATUS_GPIO_INTR_MASK)
#define WIFICMN_INT_STATUS_GPIO_INTR_RESET                                     0x0
#define WIFICMN_INT_STATUS_SI_UART_INTR_LSB                                    4
#define WIFICMN_INT_STATUS_SI_UART_INTR_MSB                                    4
#define WIFICMN_INT_STATUS_SI_UART_INTR_MASK                                   0x10
#define WIFICMN_INT_STATUS_SI_UART_INTR_GET(x)                                 (((x) & WIFICMN_INT_STATUS_SI_UART_INTR_MASK) >> WIFICMN_INT_STATUS_SI_UART_INTR_LSB)
#define WIFICMN_INT_STATUS_SI_UART_INTR_SET(x)                                 (((0 | (x)) << WIFICMN_INT_STATUS_SI_UART_INTR_LSB) & WIFICMN_INT_STATUS_SI_UART_INTR_MASK)
#define WIFICMN_INT_STATUS_SI_UART_INTR_RESET                                  0x0
#define WIFICMN_INT_STATUS_RTC_INTR_LSB                                        3
#define WIFICMN_INT_STATUS_RTC_INTR_MSB                                        3
#define WIFICMN_INT_STATUS_RTC_INTR_MASK                                       0x8
#define WIFICMN_INT_STATUS_RTC_INTR_GET(x)                                     (((x) & WIFICMN_INT_STATUS_RTC_INTR_MASK) >> WIFICMN_INT_STATUS_RTC_INTR_LSB)
#define WIFICMN_INT_STATUS_RTC_INTR_SET(x)                                     (((0 | (x)) << WIFICMN_INT_STATUS_RTC_INTR_LSB) & WIFICMN_INT_STATUS_RTC_INTR_MASK)
#define WIFICMN_INT_STATUS_RTC_INTR_RESET                                      0x0
#define WIFICMN_INT_STATUS_WIFI_TIMER_INTR_LSB                                 2
#define WIFICMN_INT_STATUS_WIFI_TIMER_INTR_MSB                                 2
#define WIFICMN_INT_STATUS_WIFI_TIMER_INTR_MASK                                0x4
#define WIFICMN_INT_STATUS_WIFI_TIMER_INTR_GET(x)                              (((x) & WIFICMN_INT_STATUS_WIFI_TIMER_INTR_MASK) >> WIFICMN_INT_STATUS_WIFI_TIMER_INTR_LSB)
#define WIFICMN_INT_STATUS_WIFI_TIMER_INTR_SET(x)                              (((0 | (x)) << WIFICMN_INT_STATUS_WIFI_TIMER_INTR_LSB) & WIFICMN_INT_STATUS_WIFI_TIMER_INTR_MASK)
#define WIFICMN_INT_STATUS_WIFI_TIMER_INTR_RESET                               0x0
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_3_LSB                                1
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_3_MSB                                1
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_3_MASK                               0x2
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_3_GET(x)                             (((x) & WIFICMN_INT_STATUS_WMAC_MCMN_INTR_3_MASK) >> WIFICMN_INT_STATUS_WMAC_MCMN_INTR_3_LSB)
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_3_SET(x)                             (((0 | (x)) << WIFICMN_INT_STATUS_WMAC_MCMN_INTR_3_LSB) & WIFICMN_INT_STATUS_WMAC_MCMN_INTR_3_MASK)
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_3_RESET                              0x0
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_0_LSB                                0
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_0_MSB                                0
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_0_MASK                               0x1
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_0_GET(x)                             (((x) & WIFICMN_INT_STATUS_WMAC_MCMN_INTR_0_MASK) >> WIFICMN_INT_STATUS_WMAC_MCMN_INTR_0_LSB)
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_0_SET(x)                             (((0 | (x)) << WIFICMN_INT_STATUS_WMAC_MCMN_INTR_0_LSB) & WIFICMN_INT_STATUS_WMAC_MCMN_INTR_0_MASK)
#define WIFICMN_INT_STATUS_WMAC_MCMN_INTR_0_RESET                              0x0
#define WIFICMN_INT_STATUS_ADDRESS                                             (0x54 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_INT_STATUS_RSTMASK                                             0x3fffff7f
#define WIFICMN_INT_STATUS_RESET                                               0x0

// 0x58 (WIFICMN_INT_STATUS_CONTD)
#define WIFICMN_INT_STATUS_CONTD_RFFE_M_LSB                                    2
#define WIFICMN_INT_STATUS_CONTD_RFFE_M_MSB                                    2
#define WIFICMN_INT_STATUS_CONTD_RFFE_M_MASK                                   0x4
#define WIFICMN_INT_STATUS_CONTD_RFFE_M_GET(x)                                 (((x) & WIFICMN_INT_STATUS_CONTD_RFFE_M_MASK) >> WIFICMN_INT_STATUS_CONTD_RFFE_M_LSB)
#define WIFICMN_INT_STATUS_CONTD_RFFE_M_SET(x)                                 (((0 | (x)) << WIFICMN_INT_STATUS_CONTD_RFFE_M_LSB) & WIFICMN_INT_STATUS_CONTD_RFFE_M_MASK)
#define WIFICMN_INT_STATUS_CONTD_RFFE_M_RESET                                  0x0
#define WIFICMN_INT_STATUS_CONTD_LTE_COEX_LSB                                  1
#define WIFICMN_INT_STATUS_CONTD_LTE_COEX_MSB                                  1
#define WIFICMN_INT_STATUS_CONTD_LTE_COEX_MASK                                 0x2
#define WIFICMN_INT_STATUS_CONTD_LTE_COEX_GET(x)                               (((x) & WIFICMN_INT_STATUS_CONTD_LTE_COEX_MASK) >> WIFICMN_INT_STATUS_CONTD_LTE_COEX_LSB)
#define WIFICMN_INT_STATUS_CONTD_LTE_COEX_SET(x)                               (((0 | (x)) << WIFICMN_INT_STATUS_CONTD_LTE_COEX_LSB) & WIFICMN_INT_STATUS_CONTD_LTE_COEX_MASK)
#define WIFICMN_INT_STATUS_CONTD_LTE_COEX_RESET                                0x0
#define WIFICMN_INT_STATUS_CONTD_PTA_COEX_LSB                                  0
#define WIFICMN_INT_STATUS_CONTD_PTA_COEX_MSB                                  0
#define WIFICMN_INT_STATUS_CONTD_PTA_COEX_MASK                                 0x1
#define WIFICMN_INT_STATUS_CONTD_PTA_COEX_GET(x)                               (((x) & WIFICMN_INT_STATUS_CONTD_PTA_COEX_MASK) >> WIFICMN_INT_STATUS_CONTD_PTA_COEX_LSB)
#define WIFICMN_INT_STATUS_CONTD_PTA_COEX_SET(x)                               (((0 | (x)) << WIFICMN_INT_STATUS_CONTD_PTA_COEX_LSB) & WIFICMN_INT_STATUS_CONTD_PTA_COEX_MASK)
#define WIFICMN_INT_STATUS_CONTD_PTA_COEX_RESET                                0x0
#define WIFICMN_INT_STATUS_CONTD_ADDRESS                                       (0x58 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_INT_STATUS_CONTD_RSTMASK                                       0x7
#define WIFICMN_INT_STATUS_CONTD_RESET                                         0x0

// 0x5c (WIFICMN_TESTBUS_SELECT)
#define WIFICMN_TESTBUS_SELECT_VAL_LSB                                         0
#define WIFICMN_TESTBUS_SELECT_VAL_MSB                                         3
#define WIFICMN_TESTBUS_SELECT_VAL_MASK                                        0xf
#define WIFICMN_TESTBUS_SELECT_VAL_GET(x)                                      (((x) & WIFICMN_TESTBUS_SELECT_VAL_MASK) >> WIFICMN_TESTBUS_SELECT_VAL_LSB)
#define WIFICMN_TESTBUS_SELECT_VAL_SET(x)                                      (((0 | (x)) << WIFICMN_TESTBUS_SELECT_VAL_LSB) & WIFICMN_TESTBUS_SELECT_VAL_MASK)
#define WIFICMN_TESTBUS_SELECT_VAL_RESET                                       0x0
#define WIFICMN_TESTBUS_SELECT_ADDRESS                                         (0x5c + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_TESTBUS_SELECT_RSTMASK                                         0xf
#define WIFICMN_TESTBUS_SELECT_RESET                                           0x0

// 0x60 (WIFICMN_OBS_SELECT)
#define WIFICMN_OBS_SELECT_VAL_LSB                                             0
#define WIFICMN_OBS_SELECT_VAL_MSB                                             3
#define WIFICMN_OBS_SELECT_VAL_MASK                                            0xf
#define WIFICMN_OBS_SELECT_VAL_GET(x)                                          (((x) & WIFICMN_OBS_SELECT_VAL_MASK) >> WIFICMN_OBS_SELECT_VAL_LSB)
#define WIFICMN_OBS_SELECT_VAL_SET(x)                                          (((0 | (x)) << WIFICMN_OBS_SELECT_VAL_LSB) & WIFICMN_OBS_SELECT_VAL_MASK)
#define WIFICMN_OBS_SELECT_VAL_RESET                                           0x0
#define WIFICMN_OBS_SELECT_ADDRESS                                             (0x60 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_OBS_SELECT_RSTMASK                                             0xf
#define WIFICMN_OBS_SELECT_RESET                                               0x0

// 0x64 (WIFICMN_OBS_BYTE_LANE_SELECT)
#define WIFICMN_OBS_BYTE_LANE_SELECT_VAL_LSB                                   0
#define WIFICMN_OBS_BYTE_LANE_SELECT_VAL_MSB                                   4
#define WIFICMN_OBS_BYTE_LANE_SELECT_VAL_MASK                                  0x1f
#define WIFICMN_OBS_BYTE_LANE_SELECT_VAL_GET(x)                                (((x) & WIFICMN_OBS_BYTE_LANE_SELECT_VAL_MASK) >> WIFICMN_OBS_BYTE_LANE_SELECT_VAL_LSB)
#define WIFICMN_OBS_BYTE_LANE_SELECT_VAL_SET(x)                                (((0 | (x)) << WIFICMN_OBS_BYTE_LANE_SELECT_VAL_LSB) & WIFICMN_OBS_BYTE_LANE_SELECT_VAL_MASK)
#define WIFICMN_OBS_BYTE_LANE_SELECT_VAL_RESET                                 0x0
#define WIFICMN_OBS_BYTE_LANE_SELECT_ADDRESS                                   (0x64 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_OBS_BYTE_LANE_SELECT_RSTMASK                                   0x1f
#define WIFICMN_OBS_BYTE_LANE_SELECT_RESET                                     0x0

// 0x68 (WIFICMN_CLK_GATE_EN)
#define WIFICMN_CLK_GATE_EN_VAL_LSB                                            0
#define WIFICMN_CLK_GATE_EN_VAL_MSB                                            7
#define WIFICMN_CLK_GATE_EN_VAL_MASK                                           0xff
#define WIFICMN_CLK_GATE_EN_VAL_GET(x)                                         (((x) & WIFICMN_CLK_GATE_EN_VAL_MASK) >> WIFICMN_CLK_GATE_EN_VAL_LSB)
#define WIFICMN_CLK_GATE_EN_VAL_SET(x)                                         (((0 | (x)) << WIFICMN_CLK_GATE_EN_VAL_LSB) & WIFICMN_CLK_GATE_EN_VAL_MASK)
#define WIFICMN_CLK_GATE_EN_VAL_RESET                                          0x0
#define WIFICMN_CLK_GATE_EN_ADDRESS                                            (0x68 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_CLK_GATE_EN_RSTMASK                                            0xff
#define WIFICMN_CLK_GATE_EN_RESET                                              0x0

// 0x6c (WIFICMN_PHY_TRACE_BUS_SEL)
#define WIFICMN_PHY_TRACE_BUS_SEL_VAL_LSB                                      0
#define WIFICMN_PHY_TRACE_BUS_SEL_VAL_MSB                                      1
#define WIFICMN_PHY_TRACE_BUS_SEL_VAL_MASK                                     0x3
#define WIFICMN_PHY_TRACE_BUS_SEL_VAL_GET(x)                                   (((x) & WIFICMN_PHY_TRACE_BUS_SEL_VAL_MASK) >> WIFICMN_PHY_TRACE_BUS_SEL_VAL_LSB)
#define WIFICMN_PHY_TRACE_BUS_SEL_VAL_SET(x)                                   (((0 | (x)) << WIFICMN_PHY_TRACE_BUS_SEL_VAL_LSB) & WIFICMN_PHY_TRACE_BUS_SEL_VAL_MASK)
#define WIFICMN_PHY_TRACE_BUS_SEL_VAL_RESET                                    0x0
#define WIFICMN_PHY_TRACE_BUS_SEL_ADDRESS                                      (0x6c + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_PHY_TRACE_BUS_SEL_RSTMASK                                      0x3
#define WIFICMN_PHY_TRACE_BUS_SEL_RESET                                        0x0

// 0x70 (WIFICMN_EVENTBUS_SELECT)
#define WIFICMN_EVENTBUS_SELECT_VAL_LSB                                        0
#define WIFICMN_EVENTBUS_SELECT_VAL_MSB                                        3
#define WIFICMN_EVENTBUS_SELECT_VAL_MASK                                       0xf
#define WIFICMN_EVENTBUS_SELECT_VAL_GET(x)                                     (((x) & WIFICMN_EVENTBUS_SELECT_VAL_MASK) >> WIFICMN_EVENTBUS_SELECT_VAL_LSB)
#define WIFICMN_EVENTBUS_SELECT_VAL_SET(x)                                     (((0 | (x)) << WIFICMN_EVENTBUS_SELECT_VAL_LSB) & WIFICMN_EVENTBUS_SELECT_VAL_MASK)
#define WIFICMN_EVENTBUS_SELECT_VAL_RESET                                      0x0
#define WIFICMN_EVENTBUS_SELECT_ADDRESS                                        (0x70 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_EVENTBUS_SELECT_RSTMASK                                        0xf
#define WIFICMN_EVENTBUS_SELECT_RESET                                          0x0

// 0x74 (WIFICMN_ECO_SPARE_REG)
#define WIFICMN_ECO_SPARE_REG_VAL_LSB                                          0
#define WIFICMN_ECO_SPARE_REG_VAL_MSB                                          31
#define WIFICMN_ECO_SPARE_REG_VAL_MASK                                         0xffffffff
#define WIFICMN_ECO_SPARE_REG_VAL_GET(x)                                       (((x) & WIFICMN_ECO_SPARE_REG_VAL_MASK) >> WIFICMN_ECO_SPARE_REG_VAL_LSB)
#define WIFICMN_ECO_SPARE_REG_VAL_SET(x)                                       (((0 | (x)) << WIFICMN_ECO_SPARE_REG_VAL_LSB) & WIFICMN_ECO_SPARE_REG_VAL_MASK)
#define WIFICMN_ECO_SPARE_REG_VAL_RESET                                        0x14
#define WIFICMN_ECO_SPARE_REG_ADDRESS                                          (0x74 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_ECO_SPARE_REG_RSTMASK                                          0xffffffff
#define WIFICMN_ECO_SPARE_REG_RESET                                            0x14

// 0x78 (WIFICMN_MCMN_CLK_GATE_DISABLE)
#define WIFICMN_MCMN_CLK_GATE_DISABLE_VAL_LSB                                  0
#define WIFICMN_MCMN_CLK_GATE_DISABLE_VAL_MSB                                  0
#define WIFICMN_MCMN_CLK_GATE_DISABLE_VAL_MASK                                 0x1
#define WIFICMN_MCMN_CLK_GATE_DISABLE_VAL_GET(x)                               (((x) & WIFICMN_MCMN_CLK_GATE_DISABLE_VAL_MASK) >> WIFICMN_MCMN_CLK_GATE_DISABLE_VAL_LSB)
#define WIFICMN_MCMN_CLK_GATE_DISABLE_VAL_SET(x)                               (((0 | (x)) << WIFICMN_MCMN_CLK_GATE_DISABLE_VAL_LSB) & WIFICMN_MCMN_CLK_GATE_DISABLE_VAL_MASK)
#define WIFICMN_MCMN_CLK_GATE_DISABLE_VAL_RESET                                0x1
#define WIFICMN_MCMN_CLK_GATE_DISABLE_ADDRESS                                  (0x78 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_MCMN_CLK_GATE_DISABLE_RSTMASK                                  0x1
#define WIFICMN_MCMN_CLK_GATE_DISABLE_RESET                                    0x1

// 0x7c (WIFICMN_MEM_CNTL)
#define WIFICMN_MEM_CNTL_CE_RAM_PD_LSB                                         7
#define WIFICMN_MEM_CNTL_CE_RAM_PD_MSB                                         7
#define WIFICMN_MEM_CNTL_CE_RAM_PD_MASK                                        0x80
#define WIFICMN_MEM_CNTL_CE_RAM_PD_GET(x)                                      (((x) & WIFICMN_MEM_CNTL_CE_RAM_PD_MASK) >> WIFICMN_MEM_CNTL_CE_RAM_PD_LSB)
#define WIFICMN_MEM_CNTL_CE_RAM_PD_SET(x)                                      (((0 | (x)) << WIFICMN_MEM_CNTL_CE_RAM_PD_LSB) & WIFICMN_MEM_CNTL_CE_RAM_PD_MASK)
#define WIFICMN_MEM_CNTL_CE_RAM_PD_RESET                                       0x0
#define WIFICMN_MEM_CNTL_WCOEX_RAM_PD_LSB                                      6
#define WIFICMN_MEM_CNTL_WCOEX_RAM_PD_MSB                                      6
#define WIFICMN_MEM_CNTL_WCOEX_RAM_PD_MASK                                     0x40
#define WIFICMN_MEM_CNTL_WCOEX_RAM_PD_GET(x)                                   (((x) & WIFICMN_MEM_CNTL_WCOEX_RAM_PD_MASK) >> WIFICMN_MEM_CNTL_WCOEX_RAM_PD_LSB)
#define WIFICMN_MEM_CNTL_WCOEX_RAM_PD_SET(x)                                   (((0 | (x)) << WIFICMN_MEM_CNTL_WCOEX_RAM_PD_LSB) & WIFICMN_MEM_CNTL_WCOEX_RAM_PD_MASK)
#define WIFICMN_MEM_CNTL_WCOEX_RAM_PD_RESET                                    0x0
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_RTSEL_LSB                                  4
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_RTSEL_MSB                                  5
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_RTSEL_MASK                                 0x30
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_RTSEL_GET(x)                               (((x) & WIFICMN_MEM_CNTL_CPU_SS_RAM_RTSEL_MASK) >> WIFICMN_MEM_CNTL_CPU_SS_RAM_RTSEL_LSB)
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_RTSEL_SET(x)                               (((0 | (x)) << WIFICMN_MEM_CNTL_CPU_SS_RAM_RTSEL_LSB) & WIFICMN_MEM_CNTL_CPU_SS_RAM_RTSEL_MASK)
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_RTSEL_RESET                                0x1
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_WTSEL_LSB                                  2
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_WTSEL_MSB                                  3
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_WTSEL_MASK                                 0xc
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_WTSEL_GET(x)                               (((x) & WIFICMN_MEM_CNTL_CPU_SS_RAM_WTSEL_MASK) >> WIFICMN_MEM_CNTL_CPU_SS_RAM_WTSEL_LSB)
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_WTSEL_SET(x)                               (((0 | (x)) << WIFICMN_MEM_CNTL_CPU_SS_RAM_WTSEL_LSB) & WIFICMN_MEM_CNTL_CPU_SS_RAM_WTSEL_MASK)
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_WTSEL_RESET                                0x1
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_AWT_LSB                                    1
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_AWT_MSB                                    1
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_AWT_MASK                                   0x2
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_AWT_GET(x)                                 (((x) & WIFICMN_MEM_CNTL_CPU_SS_RAM_AWT_MASK) >> WIFICMN_MEM_CNTL_CPU_SS_RAM_AWT_LSB)
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_AWT_SET(x)                                 (((0 | (x)) << WIFICMN_MEM_CNTL_CPU_SS_RAM_AWT_LSB) & WIFICMN_MEM_CNTL_CPU_SS_RAM_AWT_MASK)
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_AWT_RESET                                  0x0
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_PD_LSB                                     0
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_PD_MSB                                     0
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_PD_MASK                                    0x1
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_PD_GET(x)                                  (((x) & WIFICMN_MEM_CNTL_CPU_SS_RAM_PD_MASK) >> WIFICMN_MEM_CNTL_CPU_SS_RAM_PD_LSB)
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_PD_SET(x)                                  (((0 | (x)) << WIFICMN_MEM_CNTL_CPU_SS_RAM_PD_LSB) & WIFICMN_MEM_CNTL_CPU_SS_RAM_PD_MASK)
#define WIFICMN_MEM_CNTL_CPU_SS_RAM_PD_RESET                                   0x0
#define WIFICMN_MEM_CNTL_ADDRESS                                               (0x7c + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_MEM_CNTL_RSTMASK                                               0xff
#define WIFICMN_MEM_CNTL_RESET                                                 0x14

// 0x80 (WIFICMN_PIFAXI_PRIORITY)
#define WIFICMN_PIFAXI_PRIORITY_CPU_SS_AXIREQPRIORITY_LSB                      0
#define WIFICMN_PIFAXI_PRIORITY_CPU_SS_AXIREQPRIORITY_MSB                      1
#define WIFICMN_PIFAXI_PRIORITY_CPU_SS_AXIREQPRIORITY_MASK                     0x3
#define WIFICMN_PIFAXI_PRIORITY_CPU_SS_AXIREQPRIORITY_GET(x)                   (((x) & WIFICMN_PIFAXI_PRIORITY_CPU_SS_AXIREQPRIORITY_MASK) >> WIFICMN_PIFAXI_PRIORITY_CPU_SS_AXIREQPRIORITY_LSB)
#define WIFICMN_PIFAXI_PRIORITY_CPU_SS_AXIREQPRIORITY_SET(x)                   (((0 | (x)) << WIFICMN_PIFAXI_PRIORITY_CPU_SS_AXIREQPRIORITY_LSB) & WIFICMN_PIFAXI_PRIORITY_CPU_SS_AXIREQPRIORITY_MASK)
#define WIFICMN_PIFAXI_PRIORITY_CPU_SS_AXIREQPRIORITY_RESET                    0x2
#define WIFICMN_PIFAXI_PRIORITY_ADDRESS                                        (0x80 + __MAC_WIFICMN_REG_BASE_ADDRESS)
#define WIFICMN_PIFAXI_PRIORITY_RSTMASK                                        0x3
#define WIFICMN_PIFAXI_PRIORITY_RESET                                          0x2



#endif /* _MAC_WIFICMN_REG_H_ */
