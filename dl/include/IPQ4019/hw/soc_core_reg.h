/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _SOC_CORE_REG_H_
#define _SOC_CORE_REG_H_


#ifndef __SOC_CORE_REG_BASE_ADDRESS
#define __SOC_CORE_REG_BASE_ADDRESS (0x82000)
#endif


// 0x0 (CORE_CTRL)
#define CORE_CTRL_HOST_WAKE_INTR_CLR_LSB                                       14
#define CORE_CTRL_HOST_WAKE_INTR_CLR_MSB                                       14
#define CORE_CTRL_HOST_WAKE_INTR_CLR_MASK                                      0x4000
#define CORE_CTRL_HOST_WAKE_INTR_CLR_GET(x)                                    (((x) & CORE_CTRL_HOST_WAKE_INTR_CLR_MASK) >> CORE_CTRL_HOST_WAKE_INTR_CLR_LSB)
#define CORE_CTRL_HOST_WAKE_INTR_CLR_SET(x)                                    (((0 | (x)) << CORE_CTRL_HOST_WAKE_INTR_CLR_LSB) & CORE_CTRL_HOST_WAKE_INTR_CLR_MASK)
#define CORE_CTRL_HOST_WAKE_INTR_CLR_RESET                                     0x0
#define CORE_CTRL_CPU_INTR_LSB                                                 13
#define CORE_CTRL_CPU_INTR_MSB                                                 13
#define CORE_CTRL_CPU_INTR_MASK                                                0x2000
#define CORE_CTRL_CPU_INTR_GET(x)                                              (((x) & CORE_CTRL_CPU_INTR_MASK) >> CORE_CTRL_CPU_INTR_LSB)
#define CORE_CTRL_CPU_INTR_SET(x)                                              (((0 | (x)) << CORE_CTRL_CPU_INTR_LSB) & CORE_CTRL_CPU_INTR_MASK)
#define CORE_CTRL_CPU_INTR_RESET                                               0x0
#define CORE_CTRL_PCIE_INTR_LSB                                                12
#define CORE_CTRL_PCIE_INTR_MSB                                                12
#define CORE_CTRL_PCIE_INTR_MASK                                               0x1000
#define CORE_CTRL_PCIE_INTR_GET(x)                                             (((x) & CORE_CTRL_PCIE_INTR_MASK) >> CORE_CTRL_PCIE_INTR_LSB)
#define CORE_CTRL_PCIE_INTR_SET(x)                                             (((0 | (x)) << CORE_CTRL_PCIE_INTR_LSB) & CORE_CTRL_PCIE_INTR_MASK)
#define CORE_CTRL_PCIE_INTR_RESET                                              0x0
#define CORE_CTRL_ADDRESS                                                      (0x0 + __SOC_CORE_REG_BASE_ADDRESS)
#define CORE_CTRL_RSTMASK                                                      0x7000
#define CORE_CTRL_RESET                                                        0x0

// 0x4 (CORE_SW_OUTPUT)
#define CORE_SW_OUTPUT_LED_LSB                                                 0
#define CORE_SW_OUTPUT_LED_MSB                                                 1
#define CORE_SW_OUTPUT_LED_MASK                                                0x3
#define CORE_SW_OUTPUT_LED_GET(x)                                              (((x) & CORE_SW_OUTPUT_LED_MASK) >> CORE_SW_OUTPUT_LED_LSB)
#define CORE_SW_OUTPUT_LED_SET(x)                                              (((0 | (x)) << CORE_SW_OUTPUT_LED_LSB) & CORE_SW_OUTPUT_LED_MASK)
#define CORE_SW_OUTPUT_LED_RESET                                               0x0
#define CORE_SW_OUTPUT_ADDRESS                                                 (0x4 + __SOC_CORE_REG_BASE_ADDRESS)
#define CORE_SW_OUTPUT_RSTMASK                                                 0x3
#define CORE_SW_OUTPUT_RESET                                                   0x0

// 0x8 (PCIE_INTR_ENABLE)
#define PCIE_INTR_ENABLE_VAL_LSB                                               0
#define PCIE_INTR_ENABLE_VAL_MSB                                               29
#define PCIE_INTR_ENABLE_VAL_MASK                                              0x3fffffff
#define PCIE_INTR_ENABLE_VAL_GET(x)                                            (((x) & PCIE_INTR_ENABLE_VAL_MASK) >> PCIE_INTR_ENABLE_VAL_LSB)
#define PCIE_INTR_ENABLE_VAL_SET(x)                                            (((0 | (x)) << PCIE_INTR_ENABLE_VAL_LSB) & PCIE_INTR_ENABLE_VAL_MASK)
#define PCIE_INTR_ENABLE_VAL_RESET                                             0x0
#define PCIE_INTR_ENABLE_ADDRESS                                               (0x8 + __SOC_CORE_REG_BASE_ADDRESS)
#define PCIE_INTR_ENABLE_RSTMASK                                               0x3fffffff
#define PCIE_INTR_ENABLE_RESET                                                 0x0

// 0xc (PCIE_INTR_CAUSE)
#define PCIE_INTR_CAUSE_VAL_LSB                                                0
#define PCIE_INTR_CAUSE_VAL_MSB                                                29
#define PCIE_INTR_CAUSE_VAL_MASK                                               0x3fffffff
#define PCIE_INTR_CAUSE_VAL_GET(x)                                             (((x) & PCIE_INTR_CAUSE_VAL_MASK) >> PCIE_INTR_CAUSE_VAL_LSB)
#define PCIE_INTR_CAUSE_VAL_SET(x)                                             (((0 | (x)) << PCIE_INTR_CAUSE_VAL_LSB) & PCIE_INTR_CAUSE_VAL_MASK)
#define PCIE_INTR_CAUSE_VAL_RESET                                              0x0
#define PCIE_INTR_CAUSE_ADDRESS                                                (0xc + __SOC_CORE_REG_BASE_ADDRESS)
#define PCIE_INTR_CAUSE_RSTMASK                                                0x3fffffff
#define PCIE_INTR_CAUSE_RESET                                                  0x0

// 0x10 (PCIE_INTR_CLR)
#define PCIE_INTR_CLR_VAL_LSB                                                  0
#define PCIE_INTR_CLR_VAL_MSB                                                  29
#define PCIE_INTR_CLR_VAL_MASK                                                 0x3fffffff
#define PCIE_INTR_CLR_VAL_GET(x)                                               (((x) & PCIE_INTR_CLR_VAL_MASK) >> PCIE_INTR_CLR_VAL_LSB)
#define PCIE_INTR_CLR_VAL_SET(x)                                               (((0 | (x)) << PCIE_INTR_CLR_VAL_LSB) & PCIE_INTR_CLR_VAL_MASK)
#define PCIE_INTR_CLR_VAL_RESET                                                0x0
#define PCIE_INTR_CLR_ADDRESS                                                  (0x10 + __SOC_CORE_REG_BASE_ADDRESS)
#define PCIE_INTR_CLR_RSTMASK                                                  0x3fffffff
#define PCIE_INTR_CLR_RESET                                                    0x0

// 0x14 (SCRATCH_0)
#define SCRATCH_0_VAL_LSB                                                      0
#define SCRATCH_0_VAL_MSB                                                      31
#define SCRATCH_0_VAL_MASK                                                     0xffffffff
#define SCRATCH_0_VAL_GET(x)                                                   (((x) & SCRATCH_0_VAL_MASK) >> SCRATCH_0_VAL_LSB)
#define SCRATCH_0_VAL_SET(x)                                                   (((0 | (x)) << SCRATCH_0_VAL_LSB) & SCRATCH_0_VAL_MASK)
#define SCRATCH_0_VAL_RESET                                                    0x0
#define SCRATCH_0_ADDRESS                                                      (0x14 + __SOC_CORE_REG_BASE_ADDRESS)
#define SCRATCH_0_RSTMASK                                                      0xffffffff
#define SCRATCH_0_RESET                                                        0x0

// 0x18 (SCRATCH_1)
#define SCRATCH_1_VAL_LSB                                                      0
#define SCRATCH_1_VAL_MSB                                                      31
#define SCRATCH_1_VAL_MASK                                                     0xffffffff
#define SCRATCH_1_VAL_GET(x)                                                   (((x) & SCRATCH_1_VAL_MASK) >> SCRATCH_1_VAL_LSB)
#define SCRATCH_1_VAL_SET(x)                                                   (((0 | (x)) << SCRATCH_1_VAL_LSB) & SCRATCH_1_VAL_MASK)
#define SCRATCH_1_VAL_RESET                                                    0x0
#define SCRATCH_1_ADDRESS                                                      (0x18 + __SOC_CORE_REG_BASE_ADDRESS)
#define SCRATCH_1_RSTMASK                                                      0xffffffff
#define SCRATCH_1_RESET                                                        0x0

// 0x1c (SCRATCH_2)
#define SCRATCH_2_VAL_LSB                                                      0
#define SCRATCH_2_VAL_MSB                                                      31
#define SCRATCH_2_VAL_MASK                                                     0xffffffff
#define SCRATCH_2_VAL_GET(x)                                                   (((x) & SCRATCH_2_VAL_MASK) >> SCRATCH_2_VAL_LSB)
#define SCRATCH_2_VAL_SET(x)                                                   (((0 | (x)) << SCRATCH_2_VAL_LSB) & SCRATCH_2_VAL_MASK)
#define SCRATCH_2_VAL_RESET                                                    0x0
#define SCRATCH_2_ADDRESS                                                      (0x1c + __SOC_CORE_REG_BASE_ADDRESS)
#define SCRATCH_2_RSTMASK                                                      0xffffffff
#define SCRATCH_2_RESET                                                        0x0

// 0x20 (SCRATCH_3)
#define SCRATCH_3_VAL_LSB                                                      0
#define SCRATCH_3_VAL_MSB                                                      31
#define SCRATCH_3_VAL_MASK                                                     0xffffffff
#define SCRATCH_3_VAL_GET(x)                                                   (((x) & SCRATCH_3_VAL_MASK) >> SCRATCH_3_VAL_LSB)
#define SCRATCH_3_VAL_SET(x)                                                   (((0 | (x)) << SCRATCH_3_VAL_LSB) & SCRATCH_3_VAL_MASK)
#define SCRATCH_3_VAL_RESET                                                    0x0
#define SCRATCH_3_ADDRESS                                                      (0x20 + __SOC_CORE_REG_BASE_ADDRESS)
#define SCRATCH_3_RSTMASK                                                      0xffffffff
#define SCRATCH_3_RESET                                                        0x0

// 0x24 (WLAN_APB_ADDR_ERROR_CONTROL)
#define WLAN_APB_ADDR_ERROR_CONTROL_INT_STATUS_LSB                             1
#define WLAN_APB_ADDR_ERROR_CONTROL_INT_STATUS_MSB                             1
#define WLAN_APB_ADDR_ERROR_CONTROL_INT_STATUS_MASK                            0x2
#define WLAN_APB_ADDR_ERROR_CONTROL_INT_STATUS_GET(x)                          (((x) & WLAN_APB_ADDR_ERROR_CONTROL_INT_STATUS_MASK) >> WLAN_APB_ADDR_ERROR_CONTROL_INT_STATUS_LSB)
#define WLAN_APB_ADDR_ERROR_CONTROL_INT_STATUS_SET(x)                          (((0 | (x)) << WLAN_APB_ADDR_ERROR_CONTROL_INT_STATUS_LSB) & WLAN_APB_ADDR_ERROR_CONTROL_INT_STATUS_MASK)
#define WLAN_APB_ADDR_ERROR_CONTROL_INT_STATUS_RESET                           0x0
#define WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_LSB                                 0
#define WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_MSB                                 0
#define WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_MASK                                0x1
#define WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_GET(x)                              (((x) & WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_MASK) >> WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_LSB)
#define WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_SET(x)                              (((0 | (x)) << WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_LSB) & WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_MASK)
#define WLAN_APB_ADDR_ERROR_CONTROL_ENABLE_RESET                               0x0
#define WLAN_APB_ADDR_ERROR_CONTROL_ADDRESS                                    (0x24 + __SOC_CORE_REG_BASE_ADDRESS)
#define WLAN_APB_ADDR_ERROR_CONTROL_RSTMASK                                    0x3
#define WLAN_APB_ADDR_ERROR_CONTROL_RESET                                      0x0

// 0x28 (WLAN_APB_ADDR_ERROR_STATUS)
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_LSB                                 0
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_MSB                                 31
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_MASK                                0xffffffff
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_GET(x)                              (((x) & WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_MASK) >> WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_LSB)
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_SET(x)                              (((0 | (x)) << WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_LSB) & WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_MASK)
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS_RESET                               0x0
#define WLAN_APB_ADDR_ERROR_STATUS_ADDRESS                                     (0x28 + __SOC_CORE_REG_BASE_ADDRESS)
#define WLAN_APB_ADDR_ERROR_STATUS_RSTMASK                                     0xffffffff
#define WLAN_APB_ADDR_ERROR_STATUS_RESET                                       0x0

// 0x2c (WLAN_APB_ADDR_ERROR_STATUS_WRITE)
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_VAL_LSB                               0
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_VAL_MSB                               0
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_VAL_MASK                              0x1
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_VAL_GET(x)                            (((x) & WLAN_APB_ADDR_ERROR_STATUS_WRITE_VAL_MASK) >> WLAN_APB_ADDR_ERROR_STATUS_WRITE_VAL_LSB)
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_VAL_SET(x)                            (((0 | (x)) << WLAN_APB_ADDR_ERROR_STATUS_WRITE_VAL_LSB) & WLAN_APB_ADDR_ERROR_STATUS_WRITE_VAL_MASK)
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_VAL_RESET                             0x0
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_ADDRESS                               (0x2c + __SOC_CORE_REG_BASE_ADDRESS)
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_RSTMASK                               0x1
#define WLAN_APB_ADDR_ERROR_STATUS_WRITE_RESET                                 0x0

// 0x30 (WLAN_SUBSYSTEM_CORE_ID)
#define WLAN_SUBSYSTEM_CORE_ID_NUM_LSB                                         0
#define WLAN_SUBSYSTEM_CORE_ID_NUM_MSB                                         1
#define WLAN_SUBSYSTEM_CORE_ID_NUM_MASK                                        0x3
#define WLAN_SUBSYSTEM_CORE_ID_NUM_GET(x)                                      (((x) & WLAN_SUBSYSTEM_CORE_ID_NUM_MASK) >> WLAN_SUBSYSTEM_CORE_ID_NUM_LSB)
#define WLAN_SUBSYSTEM_CORE_ID_NUM_SET(x)                                      (((0 | (x)) << WLAN_SUBSYSTEM_CORE_ID_NUM_LSB) & WLAN_SUBSYSTEM_CORE_ID_NUM_MASK)
#define WLAN_SUBSYSTEM_CORE_ID_NUM_RESET                                       0x0
#define WLAN_SUBSYSTEM_CORE_ID_ADDRESS                                         (0x30 + __SOC_CORE_REG_BASE_ADDRESS)
#define WLAN_SUBSYSTEM_CORE_ID_RSTMASK                                         0x3
#define WLAN_SUBSYSTEM_CORE_ID_RESET                                           0x0

// 0x34 (SOC_DEBUG)
#define SOC_DEBUG_APB_TOGGLE_LSB                                               9
#define SOC_DEBUG_APB_TOGGLE_MSB                                               9
#define SOC_DEBUG_APB_TOGGLE_MASK                                              0x200
#define SOC_DEBUG_APB_TOGGLE_GET(x)                                            (((x) & SOC_DEBUG_APB_TOGGLE_MASK) >> SOC_DEBUG_APB_TOGGLE_LSB)
#define SOC_DEBUG_APB_TOGGLE_SET(x)                                            (((0 | (x)) << SOC_DEBUG_APB_TOGGLE_LSB) & SOC_DEBUG_APB_TOGGLE_MASK)
#define SOC_DEBUG_APB_TOGGLE_RESET                                             0x0
#define SOC_DEBUG_CLOCK_SEL_LSB                                                4
#define SOC_DEBUG_CLOCK_SEL_MSB                                                8
#define SOC_DEBUG_CLOCK_SEL_MASK                                               0x1f0
#define SOC_DEBUG_CLOCK_SEL_GET(x)                                             (((x) & SOC_DEBUG_CLOCK_SEL_MASK) >> SOC_DEBUG_CLOCK_SEL_LSB)
#define SOC_DEBUG_CLOCK_SEL_SET(x)                                             (((0 | (x)) << SOC_DEBUG_CLOCK_SEL_LSB) & SOC_DEBUG_CLOCK_SEL_MASK)
#define SOC_DEBUG_CLOCK_SEL_RESET                                              0x0
#define SOC_DEBUG_SRC_SEL_LSB                                                  1
#define SOC_DEBUG_SRC_SEL_MSB                                                  3
#define SOC_DEBUG_SRC_SEL_MASK                                                 0xe
#define SOC_DEBUG_SRC_SEL_GET(x)                                               (((x) & SOC_DEBUG_SRC_SEL_MASK) >> SOC_DEBUG_SRC_SEL_LSB)
#define SOC_DEBUG_SRC_SEL_SET(x)                                               (((0 | (x)) << SOC_DEBUG_SRC_SEL_LSB) & SOC_DEBUG_SRC_SEL_MASK)
#define SOC_DEBUG_SRC_SEL_RESET                                                0x0
#define SOC_DEBUG_ENABLE_LSB                                                   0
#define SOC_DEBUG_ENABLE_MSB                                                   0
#define SOC_DEBUG_ENABLE_MASK                                                  0x1
#define SOC_DEBUG_ENABLE_GET(x)                                                (((x) & SOC_DEBUG_ENABLE_MASK) >> SOC_DEBUG_ENABLE_LSB)
#define SOC_DEBUG_ENABLE_SET(x)                                                (((0 | (x)) << SOC_DEBUG_ENABLE_LSB) & SOC_DEBUG_ENABLE_MASK)
#define SOC_DEBUG_ENABLE_RESET                                                 0x0
#define SOC_DEBUG_ADDRESS                                                      (0x34 + __SOC_CORE_REG_BASE_ADDRESS)
#define SOC_DEBUG_RSTMASK                                                      0x3ff
#define SOC_DEBUG_RESET                                                        0x0

// 0x38 (CLOCK_OBS_MUX)
#define CLOCK_OBS_MUX_CLK_SEL_BB_LSB                                           5
#define CLOCK_OBS_MUX_CLK_SEL_BB_MSB                                           8
#define CLOCK_OBS_MUX_CLK_SEL_BB_MASK                                          0x1e0
#define CLOCK_OBS_MUX_CLK_SEL_BB_GET(x)                                        (((x) & CLOCK_OBS_MUX_CLK_SEL_BB_MASK) >> CLOCK_OBS_MUX_CLK_SEL_BB_LSB)
#define CLOCK_OBS_MUX_CLK_SEL_BB_SET(x)                                        (((0 | (x)) << CLOCK_OBS_MUX_CLK_SEL_BB_LSB) & CLOCK_OBS_MUX_CLK_SEL_BB_MASK)
#define CLOCK_OBS_MUX_CLK_SEL_BB_RESET                                         0x0
#define CLOCK_OBS_MUX_CLK_SEL_LSB                                              0
#define CLOCK_OBS_MUX_CLK_SEL_MSB                                              4
#define CLOCK_OBS_MUX_CLK_SEL_MASK                                             0x1f
#define CLOCK_OBS_MUX_CLK_SEL_GET(x)                                           (((x) & CLOCK_OBS_MUX_CLK_SEL_MASK) >> CLOCK_OBS_MUX_CLK_SEL_LSB)
#define CLOCK_OBS_MUX_CLK_SEL_SET(x)                                           (((0 | (x)) << CLOCK_OBS_MUX_CLK_SEL_LSB) & CLOCK_OBS_MUX_CLK_SEL_MASK)
#define CLOCK_OBS_MUX_CLK_SEL_RESET                                            0x0
#define CLOCK_OBS_MUX_ADDRESS                                                  (0x38 + __SOC_CORE_REG_BASE_ADDRESS)
#define CLOCK_OBS_MUX_RSTMASK                                                  0x1ff
#define CLOCK_OBS_MUX_RESET                                                    0x0

// 0x3c (DWC_DEBUG_DATA)
#define DWC_DEBUG_DATA_VAL_LSB                                                 0
#define DWC_DEBUG_DATA_VAL_MSB                                                 31
#define DWC_DEBUG_DATA_VAL_MASK                                                0xffffffff
#define DWC_DEBUG_DATA_VAL_GET(x)                                              (((x) & DWC_DEBUG_DATA_VAL_MASK) >> DWC_DEBUG_DATA_VAL_LSB)
#define DWC_DEBUG_DATA_VAL_SET(x)                                              (((0 | (x)) << DWC_DEBUG_DATA_VAL_LSB) & DWC_DEBUG_DATA_VAL_MASK)
#define DWC_DEBUG_DATA_VAL_RESET                                               0x0
#define DWC_DEBUG_DATA_ADDRESS                                                 (0x3c + __SOC_CORE_REG_BASE_ADDRESS)
#define DWC_DEBUG_DATA_RSTMASK                                                 0xffffffff
#define DWC_DEBUG_DATA_RESET                                                   0x0



#endif /* _SOC_CORE_REG_H_ */
