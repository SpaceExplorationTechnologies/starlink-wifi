/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _PCIE_LOCAL_REG_H_
#define _PCIE_LOCAL_REG_H_


#ifndef __PCIE_LOCAL_REG_BASE_ADDRESS
#define __PCIE_LOCAL_REG_BASE_ADDRESS (0x0)
#endif


// 0x0 (RTC_STATE)
#define RTC_STATE_COLD_RESET_LSB                                               13
#define RTC_STATE_COLD_RESET_MSB                                               13
#define RTC_STATE_COLD_RESET_MASK                                              0x2000
#define RTC_STATE_COLD_RESET_GET(x)                                            (((x) & RTC_STATE_COLD_RESET_MASK) >> RTC_STATE_COLD_RESET_LSB)
#define RTC_STATE_COLD_RESET_SET(x)                                            (((0 | (x)) << RTC_STATE_COLD_RESET_LSB) & RTC_STATE_COLD_RESET_MASK)
#define RTC_STATE_COLD_RESET_RESET                                             0x0
#define RTC_STATE_XTAL_COUNT_LSB                                               3
#define RTC_STATE_XTAL_COUNT_MSB                                               12
#define RTC_STATE_XTAL_COUNT_MASK                                              0x1ff8
#define RTC_STATE_XTAL_COUNT_GET(x)                                            (((x) & RTC_STATE_XTAL_COUNT_MASK) >> RTC_STATE_XTAL_COUNT_LSB)
#define RTC_STATE_XTAL_COUNT_SET(x)                                            (((0 | (x)) << RTC_STATE_XTAL_COUNT_LSB) & RTC_STATE_XTAL_COUNT_MASK)
#define RTC_STATE_XTAL_COUNT_RESET                                             0x0
#define RTC_STATE_V_LSB                                                        0
#define RTC_STATE_V_MSB                                                        2
#define RTC_STATE_V_MASK                                                       0x7
#define RTC_STATE_V_GET(x)                                                     (((x) & RTC_STATE_V_MASK) >> RTC_STATE_V_LSB)
#define RTC_STATE_V_SET(x)                                                     (((0 | (x)) << RTC_STATE_V_LSB) & RTC_STATE_V_MASK)
#define RTC_STATE_V_RESET                                                      0x0
#define RTC_STATE_ADDRESS                                                      (0x0 + __PCIE_LOCAL_REG_BASE_ADDRESS)
#define RTC_STATE_RSTMASK                                                      0x3fff
#define RTC_STATE_RESET                                                        0x0

// 0x4 (PCIE_SOC_WAKE)
#define PCIE_SOC_WAKE_V_LSB                                                    0
#define PCIE_SOC_WAKE_V_MSB                                                    0
#define PCIE_SOC_WAKE_V_MASK                                                   0x1
#define PCIE_SOC_WAKE_V_GET(x)                                                 (((x) & PCIE_SOC_WAKE_V_MASK) >> PCIE_SOC_WAKE_V_LSB)
#define PCIE_SOC_WAKE_V_SET(x)                                                 (((0 | (x)) << PCIE_SOC_WAKE_V_LSB) & PCIE_SOC_WAKE_V_MASK)
#define PCIE_SOC_WAKE_V_RESET                                                  0x0
#define PCIE_SOC_WAKE_ADDRESS                                                  (0x4 + __PCIE_LOCAL_REG_BASE_ADDRESS)
#define PCIE_SOC_WAKE_RSTMASK                                                  0x1
#define PCIE_SOC_WAKE_RESET                                                    0x0

// 0x8 (SOC_GLOBAL_RESET)
#define SOC_GLOBAL_RESET_MASK_SOC_RST_TO_PCIE_BRIDGE_LSB                       1
#define SOC_GLOBAL_RESET_MASK_SOC_RST_TO_PCIE_BRIDGE_MSB                       1
#define SOC_GLOBAL_RESET_MASK_SOC_RST_TO_PCIE_BRIDGE_MASK                      0x2
#define SOC_GLOBAL_RESET_MASK_SOC_RST_TO_PCIE_BRIDGE_GET(x)                    (((x) & SOC_GLOBAL_RESET_MASK_SOC_RST_TO_PCIE_BRIDGE_MASK) >> SOC_GLOBAL_RESET_MASK_SOC_RST_TO_PCIE_BRIDGE_LSB)
#define SOC_GLOBAL_RESET_MASK_SOC_RST_TO_PCIE_BRIDGE_SET(x)                    (((0 | (x)) << SOC_GLOBAL_RESET_MASK_SOC_RST_TO_PCIE_BRIDGE_LSB) & SOC_GLOBAL_RESET_MASK_SOC_RST_TO_PCIE_BRIDGE_MASK)
#define SOC_GLOBAL_RESET_MASK_SOC_RST_TO_PCIE_BRIDGE_RESET                     0x1
#define SOC_GLOBAL_RESET_V_LSB                                                 0
#define SOC_GLOBAL_RESET_V_MSB                                                 0
#define SOC_GLOBAL_RESET_V_MASK                                                0x1
#define SOC_GLOBAL_RESET_V_GET(x)                                              (((x) & SOC_GLOBAL_RESET_V_MASK) >> SOC_GLOBAL_RESET_V_LSB)
#define SOC_GLOBAL_RESET_V_SET(x)                                              (((0 | (x)) << SOC_GLOBAL_RESET_V_LSB) & SOC_GLOBAL_RESET_V_MASK)
#define SOC_GLOBAL_RESET_V_RESET                                               0x0
#define SOC_GLOBAL_RESET_ADDRESS                                               (0x8 + __PCIE_LOCAL_REG_BASE_ADDRESS)
#define SOC_GLOBAL_RESET_RSTMASK                                               0x3
#define SOC_GLOBAL_RESET_RESET                                                 0x2

// 0x10 (PCIE_LOCAL_CTRL_OBS_MUX)
#define PCIE_LOCAL_CTRL_OBS_MUX_SEL_LSB                                        0
#define PCIE_LOCAL_CTRL_OBS_MUX_SEL_MSB                                        5
#define PCIE_LOCAL_CTRL_OBS_MUX_SEL_MASK                                       0x3f
#define PCIE_LOCAL_CTRL_OBS_MUX_SEL_GET(x)                                     (((x) & PCIE_LOCAL_CTRL_OBS_MUX_SEL_MASK) >> PCIE_LOCAL_CTRL_OBS_MUX_SEL_LSB)
#define PCIE_LOCAL_CTRL_OBS_MUX_SEL_SET(x)                                     (((0 | (x)) << PCIE_LOCAL_CTRL_OBS_MUX_SEL_LSB) & PCIE_LOCAL_CTRL_OBS_MUX_SEL_MASK)
#define PCIE_LOCAL_CTRL_OBS_MUX_SEL_RESET                                      0x0
#define PCIE_LOCAL_CTRL_OBS_MUX_ADDRESS                                        (0x10 + __PCIE_LOCAL_REG_BASE_ADDRESS)
#define PCIE_LOCAL_CTRL_OBS_MUX_RSTMASK                                        0x3f
#define PCIE_LOCAL_CTRL_OBS_MUX_RESET                                          0x0

// 0x14 (PCIE_DEBUG_LOCAL)
#define PCIE_DEBUG_LOCAL_V_LSB                                                 0
#define PCIE_DEBUG_LOCAL_V_MSB                                                 9
#define PCIE_DEBUG_LOCAL_V_MASK                                                0x3ff
#define PCIE_DEBUG_LOCAL_V_GET(x)                                              (((x) & PCIE_DEBUG_LOCAL_V_MASK) >> PCIE_DEBUG_LOCAL_V_LSB)
#define PCIE_DEBUG_LOCAL_V_SET(x)                                              (((0 | (x)) << PCIE_DEBUG_LOCAL_V_LSB) & PCIE_DEBUG_LOCAL_V_MASK)
#define PCIE_DEBUG_LOCAL_V_RESET                                               0x0
#define PCIE_DEBUG_LOCAL_ADDRESS                                               (0x14 + __PCIE_LOCAL_REG_BASE_ADDRESS)
#define PCIE_DEBUG_LOCAL_RSTMASK                                               0x3ff
#define PCIE_DEBUG_LOCAL_RESET                                                 0x0

// 0x18 (PCIE_BAR_VALID)
#define PCIE_BAR_VALID_DBG_LSB                                                 0
#define PCIE_BAR_VALID_DBG_MSB                                                 0
#define PCIE_BAR_VALID_DBG_MASK                                                0x1
#define PCIE_BAR_VALID_DBG_GET(x)                                              (((x) & PCIE_BAR_VALID_DBG_MASK) >> PCIE_BAR_VALID_DBG_LSB)
#define PCIE_BAR_VALID_DBG_SET(x)                                              (((0 | (x)) << PCIE_BAR_VALID_DBG_LSB) & PCIE_BAR_VALID_DBG_MASK)
#define PCIE_BAR_VALID_DBG_RESET                                               0x0
#define PCIE_BAR_VALID_ADDRESS                                                 (0x18 + __PCIE_LOCAL_REG_BASE_ADDRESS)
#define PCIE_BAR_VALID_RSTMASK                                                 0x1
#define PCIE_BAR_VALID_RESET                                                   0x0

// 0x1c (PCIE_SOC_RDY_STATUS)
#define PCIE_SOC_RDY_STATUS_VAL_LSB                                            1
#define PCIE_SOC_RDY_STATUS_VAL_MSB                                            31
#define PCIE_SOC_RDY_STATUS_VAL_MASK                                           0xfffffffe
#define PCIE_SOC_RDY_STATUS_VAL_GET(x)                                         (((x) & PCIE_SOC_RDY_STATUS_VAL_MASK) >> PCIE_SOC_RDY_STATUS_VAL_LSB)
#define PCIE_SOC_RDY_STATUS_VAL_SET(x)                                         (((0 | (x)) << PCIE_SOC_RDY_STATUS_VAL_LSB) & PCIE_SOC_RDY_STATUS_VAL_MASK)
#define PCIE_SOC_RDY_STATUS_VAL_RESET                                          0x0
#define PCIE_SOC_RDY_STATUS_BAR_LSB                                            0
#define PCIE_SOC_RDY_STATUS_BAR_MSB                                            0
#define PCIE_SOC_RDY_STATUS_BAR_MASK                                           0x1
#define PCIE_SOC_RDY_STATUS_BAR_GET(x)                                         (((x) & PCIE_SOC_RDY_STATUS_BAR_MASK) >> PCIE_SOC_RDY_STATUS_BAR_LSB)
#define PCIE_SOC_RDY_STATUS_BAR_SET(x)                                         (((0 | (x)) << PCIE_SOC_RDY_STATUS_BAR_LSB) & PCIE_SOC_RDY_STATUS_BAR_MASK)
#define PCIE_SOC_RDY_STATUS_BAR_RESET                                          0x0
#define PCIE_SOC_RDY_STATUS_ADDRESS                                            (0x1c + __PCIE_LOCAL_REG_BASE_ADDRESS)
#define PCIE_SOC_RDY_STATUS_RSTMASK                                            0xffffffff
#define PCIE_SOC_RDY_STATUS_RESET                                              0x0



#endif /* _PCIE_LOCAL_REG_H_ */
