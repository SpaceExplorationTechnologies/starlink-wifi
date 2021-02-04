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
#define CORE_CTRL_SLV_RESP_ERR_MAP_LSB                                         22
#define CORE_CTRL_SLV_RESP_ERR_MAP_MSB                                         27
#define CORE_CTRL_SLV_RESP_ERR_MAP_MASK                                        0xfc00000
#define CORE_CTRL_SLV_RESP_ERR_MAP_GET(x)                                      (((x) & CORE_CTRL_SLV_RESP_ERR_MAP_MASK) >> CORE_CTRL_SLV_RESP_ERR_MAP_LSB)
#define CORE_CTRL_SLV_RESP_ERR_MAP_SET(x)                                      (((0 | (x)) << CORE_CTRL_SLV_RESP_ERR_MAP_LSB) & CORE_CTRL_SLV_RESP_ERR_MAP_MASK)
#define CORE_CTRL_SLV_RESP_ERR_MAP_RESET                                       0x3f
#define CORE_CTRL_PCS_COMMON_CLOCKS_LSB                                        21
#define CORE_CTRL_PCS_COMMON_CLOCKS_MSB                                        21
#define CORE_CTRL_PCS_COMMON_CLOCKS_MASK                                       0x200000
#define CORE_CTRL_PCS_COMMON_CLOCKS_GET(x)                                     (((x) & CORE_CTRL_PCS_COMMON_CLOCKS_MASK) >> CORE_CTRL_PCS_COMMON_CLOCKS_LSB)
#define CORE_CTRL_PCS_COMMON_CLOCKS_SET(x)                                     (((0 | (x)) << CORE_CTRL_PCS_COMMON_CLOCKS_LSB) & CORE_CTRL_PCS_COMMON_CLOCKS_MASK)
#define CORE_CTRL_PCS_COMMON_CLOCKS_RESET                                      0x0
#define CORE_CTRL_MASK_CORE_RST_TO_PHY_LSB                                     20
#define CORE_CTRL_MASK_CORE_RST_TO_PHY_MSB                                     20
#define CORE_CTRL_MASK_CORE_RST_TO_PHY_MASK                                    0x100000
#define CORE_CTRL_MASK_CORE_RST_TO_PHY_GET(x)                                  (((x) & CORE_CTRL_MASK_CORE_RST_TO_PHY_MASK) >> CORE_CTRL_MASK_CORE_RST_TO_PHY_LSB)
#define CORE_CTRL_MASK_CORE_RST_TO_PHY_SET(x)                                  (((0 | (x)) << CORE_CTRL_MASK_CORE_RST_TO_PHY_LSB) & CORE_CTRL_MASK_CORE_RST_TO_PHY_MASK)
#define CORE_CTRL_MASK_CORE_RST_TO_PHY_RESET                                   0x1
#define CORE_CTRL_MASK_PCIE_RST_LSB                                            19
#define CORE_CTRL_MASK_PCIE_RST_MSB                                            19
#define CORE_CTRL_MASK_PCIE_RST_MASK                                           0x80000
#define CORE_CTRL_MASK_PCIE_RST_GET(x)                                         (((x) & CORE_CTRL_MASK_PCIE_RST_MASK) >> CORE_CTRL_MASK_PCIE_RST_LSB)
#define CORE_CTRL_MASK_PCIE_RST_SET(x)                                         (((0 | (x)) << CORE_CTRL_MASK_PCIE_RST_LSB) & CORE_CTRL_MASK_PCIE_RST_MASK)
#define CORE_CTRL_MASK_PCIE_RST_RESET                                          0x1
#define CORE_CTRL_PCIE_LTSSM_EN_LSB                                            18
#define CORE_CTRL_PCIE_LTSSM_EN_MSB                                            18
#define CORE_CTRL_PCIE_LTSSM_EN_MASK                                           0x40000
#define CORE_CTRL_PCIE_LTSSM_EN_GET(x)                                         (((x) & CORE_CTRL_PCIE_LTSSM_EN_MASK) >> CORE_CTRL_PCIE_LTSSM_EN_LSB)
#define CORE_CTRL_PCIE_LTSSM_EN_SET(x)                                         (((0 | (x)) << CORE_CTRL_PCIE_LTSSM_EN_LSB) & CORE_CTRL_PCIE_LTSSM_EN_MASK)
#define CORE_CTRL_PCIE_LTSSM_EN_RESET                                          0x0
#define CORE_CTRL_OUTBAND_PWRUP_LSB                                            16
#define CORE_CTRL_OUTBAND_PWRUP_MSB                                            16
#define CORE_CTRL_OUTBAND_PWRUP_MASK                                           0x10000
#define CORE_CTRL_OUTBAND_PWRUP_GET(x)                                         (((x) & CORE_CTRL_OUTBAND_PWRUP_MASK) >> CORE_CTRL_OUTBAND_PWRUP_LSB)
#define CORE_CTRL_OUTBAND_PWRUP_SET(x)                                         (((0 | (x)) << CORE_CTRL_OUTBAND_PWRUP_LSB) & CORE_CTRL_OUTBAND_PWRUP_MASK)
#define CORE_CTRL_OUTBAND_PWRUP_RESET                                          0x0
#define CORE_CTRL_WAKE_L_LSB                                                   15
#define CORE_CTRL_WAKE_L_MSB                                                   15
#define CORE_CTRL_WAKE_L_MASK                                                  0x8000
#define CORE_CTRL_WAKE_L_GET(x)                                                (((x) & CORE_CTRL_WAKE_L_MASK) >> CORE_CTRL_WAKE_L_LSB)
#define CORE_CTRL_WAKE_L_SET(x)                                                (((0 | (x)) << CORE_CTRL_WAKE_L_LSB) & CORE_CTRL_WAKE_L_MASK)
#define CORE_CTRL_WAKE_L_RESET                                                 0x1
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
#define CORE_CTRL_RSTMASK                                                      0xffdf000
#define CORE_CTRL_RESET                                                        0xfd88000

// 0x4 (CORE_PM)
#define CORE_PM_PCIEPHY_RTUNE_ACK_LSB                                          6
#define CORE_PM_PCIEPHY_RTUNE_ACK_MSB                                          6
#define CORE_PM_PCIEPHY_RTUNE_ACK_MASK                                         0x40
#define CORE_PM_PCIEPHY_RTUNE_ACK_GET(x)                                       (((x) & CORE_PM_PCIEPHY_RTUNE_ACK_MASK) >> CORE_PM_PCIEPHY_RTUNE_ACK_LSB)
#define CORE_PM_PCIEPHY_RTUNE_ACK_SET(x)                                       (((0 | (x)) << CORE_PM_PCIEPHY_RTUNE_ACK_LSB) & CORE_PM_PCIEPHY_RTUNE_ACK_MASK)
#define CORE_PM_PCIEPHY_RTUNE_ACK_RESET                                        0x0
#define CORE_PM_DSTATE_LSB                                                     3
#define CORE_PM_DSTATE_MSB                                                     5
#define CORE_PM_DSTATE_MASK                                                    0x38
#define CORE_PM_DSTATE_GET(x)                                                  (((x) & CORE_PM_DSTATE_MASK) >> CORE_PM_DSTATE_LSB)
#define CORE_PM_DSTATE_SET(x)                                                  (((0 | (x)) << CORE_PM_DSTATE_LSB) & CORE_PM_DSTATE_MASK)
#define CORE_PM_DSTATE_RESET                                                   0x0
#define CORE_PM_STATUS_LSB                                                     2
#define CORE_PM_STATUS_MSB                                                     2
#define CORE_PM_STATUS_MASK                                                    0x4
#define CORE_PM_STATUS_GET(x)                                                  (((x) & CORE_PM_STATUS_MASK) >> CORE_PM_STATUS_LSB)
#define CORE_PM_STATUS_SET(x)                                                  (((0 | (x)) << CORE_PM_STATUS_LSB) & CORE_PM_STATUS_MASK)
#define CORE_PM_STATUS_RESET                                                   0x0
#define CORE_PM_AUX_PM_EN_LSB                                                  1
#define CORE_PM_AUX_PM_EN_MSB                                                  1
#define CORE_PM_AUX_PM_EN_MASK                                                 0x2
#define CORE_PM_AUX_PM_EN_GET(x)                                               (((x) & CORE_PM_AUX_PM_EN_MASK) >> CORE_PM_AUX_PM_EN_LSB)
#define CORE_PM_AUX_PM_EN_SET(x)                                               (((0 | (x)) << CORE_PM_AUX_PM_EN_LSB) & CORE_PM_AUX_PM_EN_MASK)
#define CORE_PM_AUX_PM_EN_RESET                                                0x0
#define CORE_PM_PME_EN_LSB                                                     0
#define CORE_PM_PME_EN_MSB                                                     0
#define CORE_PM_PME_EN_MASK                                                    0x1
#define CORE_PM_PME_EN_GET(x)                                                  (((x) & CORE_PM_PME_EN_MASK) >> CORE_PM_PME_EN_LSB)
#define CORE_PM_PME_EN_SET(x)                                                  (((0 | (x)) << CORE_PM_PME_EN_LSB) & CORE_PM_PME_EN_MASK)
#define CORE_PM_PME_EN_RESET                                                   0x0
#define CORE_PM_ADDRESS                                                        (0x4 + __SOC_CORE_REG_BASE_ADDRESS)
#define CORE_PM_RSTMASK                                                        0x7f
#define CORE_PM_RESET                                                          0x0

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

// 0x30 (PMU_CTRL)
#define PMU_CTRL_LPO2MHZ_EN_LSB                                                0
#define PMU_CTRL_LPO2MHZ_EN_MSB                                                0
#define PMU_CTRL_LPO2MHZ_EN_MASK                                               0x1
#define PMU_CTRL_LPO2MHZ_EN_GET(x)                                             (((x) & PMU_CTRL_LPO2MHZ_EN_MASK) >> PMU_CTRL_LPO2MHZ_EN_LSB)
#define PMU_CTRL_LPO2MHZ_EN_SET(x)                                             (((0 | (x)) << PMU_CTRL_LPO2MHZ_EN_LSB) & PMU_CTRL_LPO2MHZ_EN_MASK)
#define PMU_CTRL_LPO2MHZ_EN_RESET                                              0x1
#define PMU_CTRL_ADDRESS                                                       (0x30 + __SOC_CORE_REG_BASE_ADDRESS)
#define PMU_CTRL_RSTMASK                                                       0x1
#define PMU_CTRL_RESET                                                         0x1

// 0x34 (PCIE_TO_HOST_INTMASK)
#define PCIE_TO_HOST_INTMASK_APB_ERROR_INT_MASK_LSB                            1
#define PCIE_TO_HOST_INTMASK_APB_ERROR_INT_MASK_MSB                            1
#define PCIE_TO_HOST_INTMASK_APB_ERROR_INT_MASK_MASK                           0x2
#define PCIE_TO_HOST_INTMASK_APB_ERROR_INT_MASK_GET(x)                         (((x) & PCIE_TO_HOST_INTMASK_APB_ERROR_INT_MASK_MASK) >> PCIE_TO_HOST_INTMASK_APB_ERROR_INT_MASK_LSB)
#define PCIE_TO_HOST_INTMASK_APB_ERROR_INT_MASK_SET(x)                         (((0 | (x)) << PCIE_TO_HOST_INTMASK_APB_ERROR_INT_MASK_LSB) & PCIE_TO_HOST_INTMASK_APB_ERROR_INT_MASK_MASK)
#define PCIE_TO_HOST_INTMASK_APB_ERROR_INT_MASK_RESET                          0x0
#define PCIE_TO_HOST_INTMASK_EFUSE_ERROR_INT_MASK_LSB                          0
#define PCIE_TO_HOST_INTMASK_EFUSE_ERROR_INT_MASK_MSB                          0
#define PCIE_TO_HOST_INTMASK_EFUSE_ERROR_INT_MASK_MASK                         0x1
#define PCIE_TO_HOST_INTMASK_EFUSE_ERROR_INT_MASK_GET(x)                       (((x) & PCIE_TO_HOST_INTMASK_EFUSE_ERROR_INT_MASK_MASK) >> PCIE_TO_HOST_INTMASK_EFUSE_ERROR_INT_MASK_LSB)
#define PCIE_TO_HOST_INTMASK_EFUSE_ERROR_INT_MASK_SET(x)                       (((0 | (x)) << PCIE_TO_HOST_INTMASK_EFUSE_ERROR_INT_MASK_LSB) & PCIE_TO_HOST_INTMASK_EFUSE_ERROR_INT_MASK_MASK)
#define PCIE_TO_HOST_INTMASK_EFUSE_ERROR_INT_MASK_RESET                        0x0
#define PCIE_TO_HOST_INTMASK_ADDRESS                                           (0x34 + __SOC_CORE_REG_BASE_ADDRESS)
#define PCIE_TO_HOST_INTMASK_RSTMASK                                           0x3
#define PCIE_TO_HOST_INTMASK_RESET                                             0x0

// 0x38 (PCIE_CTRL_STATUS)
#define PCIE_CTRL_STATUS_PCIE_CLK_AVAILABLE_LSB                                0
#define PCIE_CTRL_STATUS_PCIE_CLK_AVAILABLE_MSB                                0
#define PCIE_CTRL_STATUS_PCIE_CLK_AVAILABLE_MASK                               0x1
#define PCIE_CTRL_STATUS_PCIE_CLK_AVAILABLE_GET(x)                             (((x) & PCIE_CTRL_STATUS_PCIE_CLK_AVAILABLE_MASK) >> PCIE_CTRL_STATUS_PCIE_CLK_AVAILABLE_LSB)
#define PCIE_CTRL_STATUS_PCIE_CLK_AVAILABLE_SET(x)                             (((0 | (x)) << PCIE_CTRL_STATUS_PCIE_CLK_AVAILABLE_LSB) & PCIE_CTRL_STATUS_PCIE_CLK_AVAILABLE_MASK)
#define PCIE_CTRL_STATUS_PCIE_CLK_AVAILABLE_RESET                              0x0
#define PCIE_CTRL_STATUS_ADDRESS                                               (0x38 + __SOC_CORE_REG_BASE_ADDRESS)
#define PCIE_CTRL_STATUS_RSTMASK                                               0x1
#define PCIE_CTRL_STATUS_RESET                                                 0x0

// 0x40 (PCIE_SW_PERST_N)
#define PCIE_SW_PERST_N_SW_PERST_N_LSB                                         0
#define PCIE_SW_PERST_N_SW_PERST_N_MSB                                         0
#define PCIE_SW_PERST_N_SW_PERST_N_MASK                                        0x1
#define PCIE_SW_PERST_N_SW_PERST_N_GET(x)                                      (((x) & PCIE_SW_PERST_N_SW_PERST_N_MASK) >> PCIE_SW_PERST_N_SW_PERST_N_LSB)
#define PCIE_SW_PERST_N_SW_PERST_N_SET(x)                                      (((0 | (x)) << PCIE_SW_PERST_N_SW_PERST_N_LSB) & PCIE_SW_PERST_N_SW_PERST_N_MASK)
#define PCIE_SW_PERST_N_SW_PERST_N_RESET                                       0x0
#define PCIE_SW_PERST_N_ADDRESS                                                (0x40 + __SOC_CORE_REG_BASE_ADDRESS)
#define PCIE_SW_PERST_N_RSTMASK                                                0x1
#define PCIE_SW_PERST_N_RESET                                                  0x0



#endif /* _SOC_CORE_REG_H_ */
