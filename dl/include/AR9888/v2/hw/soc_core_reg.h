//                                                                             
// File:       ./soc_core_reg.vrh                                              
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:47:36 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             soc_core_reg.rdl                                                
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/rtl/wlan/amba_top/blueprint/soc_core_reg.rdl
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    sjod-chinghwa                                                   
// OS:         Linux 2.6.18-308.8.2.el5                                        
// Description:                                                                
//                                                                             
// No Description Provided                                                     
/*
 * Copyright (c) 2012-14 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */


#ifndef _SOC_CORE_REG_H_
#define _SOC_CORE_REG_H_
// 0x0000 (CORE_CTRL)
#define CORE_CTRL_MASK_PCIE_RST_MSB                                  19
#define CORE_CTRL_MASK_PCIE_RST_LSB                                  19
#define CORE_CTRL_MASK_PCIE_RST_MASK                                 0x00080000
#define CORE_CTRL_MASK_PCIE_RST_GET(x)                               (((x) & CORE_CTRL_MASK_PCIE_RST_MASK) >> CORE_CTRL_MASK_PCIE_RST_LSB)
#define CORE_CTRL_MASK_PCIE_RST_SET(x)                               (((0 | (x)) << CORE_CTRL_MASK_PCIE_RST_LSB) & CORE_CTRL_MASK_PCIE_RST_MASK)
#define CORE_CTRL_MASK_PCIE_RST_RESET                                1
#define CORE_CTRL_PCIE_LTSSM_EN_MSB                                  18
#define CORE_CTRL_PCIE_LTSSM_EN_LSB                                  18
#define CORE_CTRL_PCIE_LTSSM_EN_MASK                                 0x00040000
#define CORE_CTRL_PCIE_LTSSM_EN_GET(x)                               (((x) & CORE_CTRL_PCIE_LTSSM_EN_MASK) >> CORE_CTRL_PCIE_LTSSM_EN_LSB)
#define CORE_CTRL_PCIE_LTSSM_EN_SET(x)                               (((0 | (x)) << CORE_CTRL_PCIE_LTSSM_EN_LSB) & CORE_CTRL_PCIE_LTSSM_EN_MASK)
#define CORE_CTRL_PCIE_LTSSM_EN_RESET                                0
#define CORE_CTRL_AUTOCMPLT_CPU_TO_HOST_RD_MSB                       17
#define CORE_CTRL_AUTOCMPLT_CPU_TO_HOST_RD_LSB                       17
#define CORE_CTRL_AUTOCMPLT_CPU_TO_HOST_RD_MASK                      0x00020000
#define CORE_CTRL_AUTOCMPLT_CPU_TO_HOST_RD_GET(x)                    (((x) & CORE_CTRL_AUTOCMPLT_CPU_TO_HOST_RD_MASK) >> CORE_CTRL_AUTOCMPLT_CPU_TO_HOST_RD_LSB)
#define CORE_CTRL_AUTOCMPLT_CPU_TO_HOST_RD_SET(x)                    (((0 | (x)) << CORE_CTRL_AUTOCMPLT_CPU_TO_HOST_RD_LSB) & CORE_CTRL_AUTOCMPLT_CPU_TO_HOST_RD_MASK)
#define CORE_CTRL_AUTOCMPLT_CPU_TO_HOST_RD_RESET                     1
#define CORE_CTRL_OUTBAND_PWRUP_MSB                                  16
#define CORE_CTRL_OUTBAND_PWRUP_LSB                                  16
#define CORE_CTRL_OUTBAND_PWRUP_MASK                                 0x00010000
#define CORE_CTRL_OUTBAND_PWRUP_GET(x)                               (((x) & CORE_CTRL_OUTBAND_PWRUP_MASK) >> CORE_CTRL_OUTBAND_PWRUP_LSB)
#define CORE_CTRL_OUTBAND_PWRUP_SET(x)                               (((0 | (x)) << CORE_CTRL_OUTBAND_PWRUP_LSB) & CORE_CTRL_OUTBAND_PWRUP_MASK)
#define CORE_CTRL_OUTBAND_PWRUP_RESET                                0
#define CORE_CTRL_WAKE_L_MSB                                         15
#define CORE_CTRL_WAKE_L_LSB                                         15
#define CORE_CTRL_WAKE_L_MASK                                        0x00008000
#define CORE_CTRL_WAKE_L_GET(x)                                      (((x) & CORE_CTRL_WAKE_L_MASK) >> CORE_CTRL_WAKE_L_LSB)
#define CORE_CTRL_WAKE_L_SET(x)                                      (((0 | (x)) << CORE_CTRL_WAKE_L_LSB) & CORE_CTRL_WAKE_L_MASK)
#define CORE_CTRL_WAKE_L_RESET                                       1
#define CORE_CTRL_HOST_WAKE_INTR_CLR_MSB                             14
#define CORE_CTRL_HOST_WAKE_INTR_CLR_LSB                             14
#define CORE_CTRL_HOST_WAKE_INTR_CLR_MASK                            0x00004000
#define CORE_CTRL_HOST_WAKE_INTR_CLR_GET(x)                          (((x) & CORE_CTRL_HOST_WAKE_INTR_CLR_MASK) >> CORE_CTRL_HOST_WAKE_INTR_CLR_LSB)
#define CORE_CTRL_HOST_WAKE_INTR_CLR_SET(x)                          (((0 | (x)) << CORE_CTRL_HOST_WAKE_INTR_CLR_LSB) & CORE_CTRL_HOST_WAKE_INTR_CLR_MASK)
#define CORE_CTRL_HOST_WAKE_INTR_CLR_RESET                           0
#define CORE_CTRL_CPU_INTR_MSB                                       13
#define CORE_CTRL_CPU_INTR_LSB                                       13
#define CORE_CTRL_CPU_INTR_MASK                                      0x00002000
#define CORE_CTRL_CPU_INTR_GET(x)                                    (((x) & CORE_CTRL_CPU_INTR_MASK) >> CORE_CTRL_CPU_INTR_LSB)
#define CORE_CTRL_CPU_INTR_SET(x)                                    (((0 | (x)) << CORE_CTRL_CPU_INTR_LSB) & CORE_CTRL_CPU_INTR_MASK)
#define CORE_CTRL_CPU_INTR_RESET                                     0
#define CORE_CTRL_PCIE_INTR_MSB                                      12
#define CORE_CTRL_PCIE_INTR_LSB                                      12
#define CORE_CTRL_PCIE_INTR_MASK                                     0x00001000
#define CORE_CTRL_PCIE_INTR_GET(x)                                   (((x) & CORE_CTRL_PCIE_INTR_MASK) >> CORE_CTRL_PCIE_INTR_LSB)
#define CORE_CTRL_PCIE_INTR_SET(x)                                   (((0 | (x)) << CORE_CTRL_PCIE_INTR_LSB) & CORE_CTRL_PCIE_INTR_MASK)
#define CORE_CTRL_PCIE_INTR_RESET                                    0
#define CORE_CTRL_PCIE_REG_31_MSB                                    11
#define CORE_CTRL_PCIE_REG_31_LSB                                    11
#define CORE_CTRL_PCIE_REG_31_MASK                                   0x00000800
#define CORE_CTRL_PCIE_REG_31_GET(x)                                 (((x) & CORE_CTRL_PCIE_REG_31_MASK) >> CORE_CTRL_PCIE_REG_31_LSB)
#define CORE_CTRL_PCIE_REG_31_SET(x)                                 (((0 | (x)) << CORE_CTRL_PCIE_REG_31_LSB) & CORE_CTRL_PCIE_REG_31_MASK)
#define CORE_CTRL_PCIE_REG_31_RESET                                  0
#define CORE_CTRL_PCIE_BAR_MSB                                       10
#define CORE_CTRL_PCIE_BAR_LSB                                       0
#define CORE_CTRL_PCIE_BAR_MASK                                      0x000007ff
#define CORE_CTRL_PCIE_BAR_GET(x)                                    (((x) & CORE_CTRL_PCIE_BAR_MASK) >> CORE_CTRL_PCIE_BAR_LSB)
#define CORE_CTRL_PCIE_BAR_SET(x)                                    (((0 | (x)) << CORE_CTRL_PCIE_BAR_LSB) & CORE_CTRL_PCIE_BAR_MASK)
#define CORE_CTRL_PCIE_BAR_RESET                                     0
#define CORE_CTRL_ADDRESS                                            0x0000
#define CORE_CTRL_HW_MASK                                            0x000fffff
#define CORE_CTRL_SW_MASK                                            0x000fffff
#define CORE_CTRL_HW_WRITE_MASK                                      0x00004000
#define CORE_CTRL_SW_WRITE_MASK                                      0x000fffff
#define CORE_CTRL_RSTMASK                                            0xffffffff
#define CORE_CTRL_RESET                                              0x000a8000

// 0x0004 (CORE_PM)
#define CORE_PM_DSTATE_MSB                                           5
#define CORE_PM_DSTATE_LSB                                           3
#define CORE_PM_DSTATE_MASK                                          0x00000038
#define CORE_PM_DSTATE_GET(x)                                        (((x) & CORE_PM_DSTATE_MASK) >> CORE_PM_DSTATE_LSB)
#define CORE_PM_DSTATE_SET(x)                                        (((0 | (x)) << CORE_PM_DSTATE_LSB) & CORE_PM_DSTATE_MASK)
#define CORE_PM_DSTATE_RESET                                         0
#define CORE_PM_STATUS_MSB                                           2
#define CORE_PM_STATUS_LSB                                           2
#define CORE_PM_STATUS_MASK                                          0x00000004
#define CORE_PM_STATUS_GET(x)                                        (((x) & CORE_PM_STATUS_MASK) >> CORE_PM_STATUS_LSB)
#define CORE_PM_STATUS_SET(x)                                        (((0 | (x)) << CORE_PM_STATUS_LSB) & CORE_PM_STATUS_MASK)
#define CORE_PM_STATUS_RESET                                         0
#define CORE_PM_AUX_PM_EN_MSB                                        1
#define CORE_PM_AUX_PM_EN_LSB                                        1
#define CORE_PM_AUX_PM_EN_MASK                                       0x00000002
#define CORE_PM_AUX_PM_EN_GET(x)                                     (((x) & CORE_PM_AUX_PM_EN_MASK) >> CORE_PM_AUX_PM_EN_LSB)
#define CORE_PM_AUX_PM_EN_SET(x)                                     (((0 | (x)) << CORE_PM_AUX_PM_EN_LSB) & CORE_PM_AUX_PM_EN_MASK)
#define CORE_PM_AUX_PM_EN_RESET                                      0
#define CORE_PM_PME_EN_MSB                                           0
#define CORE_PM_PME_EN_LSB                                           0
#define CORE_PM_PME_EN_MASK                                          0x00000001
#define CORE_PM_PME_EN_GET(x)                                        (((x) & CORE_PM_PME_EN_MASK) >> CORE_PM_PME_EN_LSB)
#define CORE_PM_PME_EN_SET(x)                                        (((0 | (x)) << CORE_PM_PME_EN_LSB) & CORE_PM_PME_EN_MASK)
#define CORE_PM_PME_EN_RESET                                         0
#define CORE_PM_ADDRESS                                              0x0004
#define CORE_PM_HW_MASK                                              0x0000003f
#define CORE_PM_SW_MASK                                              0x0000003f
#define CORE_PM_HW_WRITE_MASK                                        0x0000003f
#define CORE_PM_SW_WRITE_MASK                                        0x00000000
#define CORE_PM_RSTMASK                                              0xffffffff
#define CORE_PM_RESET                                                0x00000000

// 0x0008 (PCIE_INTR_ENABLE)
#define PCIE_INTR_ENABLE_VAL_MSB                                     29
#define PCIE_INTR_ENABLE_VAL_LSB                                     0
#define PCIE_INTR_ENABLE_VAL_MASK                                    0x3fffffff
#define PCIE_INTR_ENABLE_VAL_GET(x)                                  (((x) & PCIE_INTR_ENABLE_VAL_MASK) >> PCIE_INTR_ENABLE_VAL_LSB)
#define PCIE_INTR_ENABLE_VAL_SET(x)                                  (((0 | (x)) << PCIE_INTR_ENABLE_VAL_LSB) & PCIE_INTR_ENABLE_VAL_MASK)
#define PCIE_INTR_ENABLE_VAL_RESET                                   0
#define PCIE_INTR_ENABLE_ADDRESS                                     0x0008
#define PCIE_INTR_ENABLE_HW_MASK                                     0x3fffffff
#define PCIE_INTR_ENABLE_SW_MASK                                     0x3fffffff
#define PCIE_INTR_ENABLE_HW_WRITE_MASK                               0x00000000
#define PCIE_INTR_ENABLE_SW_WRITE_MASK                               0x3fffffff
#define PCIE_INTR_ENABLE_RSTMASK                                     0xffffffff
#define PCIE_INTR_ENABLE_RESET                                       0x00000000

// 0x000c (PCIE_INTR_CAUSE)
#define PCIE_INTR_CAUSE_VAL_MSB                                      29
#define PCIE_INTR_CAUSE_VAL_LSB                                      0
#define PCIE_INTR_CAUSE_VAL_MASK                                     0x3fffffff
#define PCIE_INTR_CAUSE_VAL_GET(x)                                   (((x) & PCIE_INTR_CAUSE_VAL_MASK) >> PCIE_INTR_CAUSE_VAL_LSB)
#define PCIE_INTR_CAUSE_VAL_SET(x)                                   (((0 | (x)) << PCIE_INTR_CAUSE_VAL_LSB) & PCIE_INTR_CAUSE_VAL_MASK)
#define PCIE_INTR_CAUSE_VAL_RESET                                    0
#define PCIE_INTR_CAUSE_ADDRESS                                      0x000c
#define PCIE_INTR_CAUSE_HW_MASK                                      0x3fffffff
#define PCIE_INTR_CAUSE_SW_MASK                                      0x3fffffff
#define PCIE_INTR_CAUSE_HW_WRITE_MASK                                0x3fffffff
#define PCIE_INTR_CAUSE_SW_WRITE_MASK                                0x00000000
#define PCIE_INTR_CAUSE_RSTMASK                                      0xffffffff
#define PCIE_INTR_CAUSE_RESET                                        0x00000000

// 0x0010 (CPU_INTR)
#define CPU_INTR_STATUS_MSB                                          29
#define CPU_INTR_STATUS_LSB                                          0
#define CPU_INTR_STATUS_MASK                                         0x3fffffff
#define CPU_INTR_STATUS_GET(x)                                       (((x) & CPU_INTR_STATUS_MASK) >> CPU_INTR_STATUS_LSB)
#define CPU_INTR_STATUS_SET(x)                                       (((0 | (x)) << CPU_INTR_STATUS_LSB) & CPU_INTR_STATUS_MASK)
#define CPU_INTR_STATUS_RESET                                        0
#define CPU_INTR_ADDRESS                                             0x0010
#define CPU_INTR_HW_MASK                                             0x3fffffff
#define CPU_INTR_SW_MASK                                             0x3fffffff
#define CPU_INTR_HW_WRITE_MASK                                       0x3fffffff
#define CPU_INTR_SW_WRITE_MASK                                       0x00000000
#define CPU_INTR_RSTMASK                                             0xffffffff
#define CPU_INTR_RESET                                               0x00000000

// 0x0014 (PCIE_INTR_CLR)
#define PCIE_INTR_CLR_VAL_MSB                                        29
#define PCIE_INTR_CLR_VAL_LSB                                        0
#define PCIE_INTR_CLR_VAL_MASK                                       0x3fffffff
#define PCIE_INTR_CLR_VAL_GET(x)                                     (((x) & PCIE_INTR_CLR_VAL_MASK) >> PCIE_INTR_CLR_VAL_LSB)
#define PCIE_INTR_CLR_VAL_SET(x)                                     (((0 | (x)) << PCIE_INTR_CLR_VAL_LSB) & PCIE_INTR_CLR_VAL_MASK)
#define PCIE_INTR_CLR_VAL_RESET                                      0
#define PCIE_INTR_CLR_ADDRESS                                        0x0014
#define PCIE_INTR_CLR_HW_MASK                                        0x3fffffff
#define PCIE_INTR_CLR_SW_MASK                                        0x3fffffff
#define PCIE_INTR_CLR_HW_WRITE_MASK                                  0x3fffffff
#define PCIE_INTR_CLR_SW_WRITE_MASK                                  0x3fffffff
#define PCIE_INTR_CLR_RSTMASK                                        0xffffffff
#define PCIE_INTR_CLR_RESET                                          0x00000000

// 0x0018 (BT_INTR)
#define BT_INTR_V_MSB                                                0
#define BT_INTR_V_LSB                                                0
#define BT_INTR_V_MASK                                               0x00000001
#define BT_INTR_V_GET(x)                                             (((x) & BT_INTR_V_MASK) >> BT_INTR_V_LSB)
#define BT_INTR_V_SET(x)                                             (((0 | (x)) << BT_INTR_V_LSB) & BT_INTR_V_MASK)
#define BT_INTR_V_RESET                                              0
#define BT_INTR_ADDRESS                                              0x0018
#define BT_INTR_HW_MASK                                              0x00000001
#define BT_INTR_SW_MASK                                              0x00000001
#define BT_INTR_HW_WRITE_MASK                                        0x00000000
#define BT_INTR_SW_WRITE_MASK                                        0x00000001
#define BT_INTR_RSTMASK                                              0xffffffff
#define BT_INTR_RESET                                                0x00000000

// 0x001c (CPU_ADDR_MSB)
#define CPU_ADDR_MSB_V_MSB                                           3
#define CPU_ADDR_MSB_V_LSB                                           0
#define CPU_ADDR_MSB_V_MASK                                          0x0000000f
#define CPU_ADDR_MSB_V_GET(x)                                        (((x) & CPU_ADDR_MSB_V_MASK) >> CPU_ADDR_MSB_V_LSB)
#define CPU_ADDR_MSB_V_SET(x)                                        (((0 | (x)) << CPU_ADDR_MSB_V_LSB) & CPU_ADDR_MSB_V_MASK)
#define CPU_ADDR_MSB_V_RESET                                         4
#define CPU_ADDR_MSB_ADDRESS                                         0x001c
#define CPU_ADDR_MSB_HW_MASK                                         0x0000000f
#define CPU_ADDR_MSB_SW_MASK                                         0x0000000f
#define CPU_ADDR_MSB_HW_WRITE_MASK                                   0x00000000
#define CPU_ADDR_MSB_SW_WRITE_MASK                                   0x0000000f
#define CPU_ADDR_MSB_RSTMASK                                         0xffffffff
#define CPU_ADDR_MSB_RESET                                           0x00000004

// 0x0020 (AXI_SPOOFER)
#define AXI_SPOOFER_PCIE_EN_MSB                                      5
#define AXI_SPOOFER_PCIE_EN_LSB                                      5
#define AXI_SPOOFER_PCIE_EN_MASK                                     0x00000020
#define AXI_SPOOFER_PCIE_EN_GET(x)                                   (((x) & AXI_SPOOFER_PCIE_EN_MASK) >> AXI_SPOOFER_PCIE_EN_LSB)
#define AXI_SPOOFER_PCIE_EN_SET(x)                                   (((0 | (x)) << AXI_SPOOFER_PCIE_EN_LSB) & AXI_SPOOFER_PCIE_EN_MASK)
#define AXI_SPOOFER_PCIE_EN_RESET                                    0
#define AXI_SPOOFER_BRIDGE_EN_MSB                                    4
#define AXI_SPOOFER_BRIDGE_EN_LSB                                    4
#define AXI_SPOOFER_BRIDGE_EN_MASK                                   0x00000010
#define AXI_SPOOFER_BRIDGE_EN_GET(x)                                 (((x) & AXI_SPOOFER_BRIDGE_EN_MASK) >> AXI_SPOOFER_BRIDGE_EN_LSB)
#define AXI_SPOOFER_BRIDGE_EN_SET(x)                                 (((0 | (x)) << AXI_SPOOFER_BRIDGE_EN_LSB) & AXI_SPOOFER_BRIDGE_EN_MASK)
#define AXI_SPOOFER_BRIDGE_EN_RESET                                  0
#define AXI_SPOOFER_CPU_S_EN_MSB                                     3
#define AXI_SPOOFER_CPU_S_EN_LSB                                     3
#define AXI_SPOOFER_CPU_S_EN_MASK                                    0x00000008
#define AXI_SPOOFER_CPU_S_EN_GET(x)                                  (((x) & AXI_SPOOFER_CPU_S_EN_MASK) >> AXI_SPOOFER_CPU_S_EN_LSB)
#define AXI_SPOOFER_CPU_S_EN_SET(x)                                  (((0 | (x)) << AXI_SPOOFER_CPU_S_EN_LSB) & AXI_SPOOFER_CPU_S_EN_MASK)
#define AXI_SPOOFER_CPU_S_EN_RESET                                   0
#define AXI_SPOOFER_CE_EN_MSB                                        2
#define AXI_SPOOFER_CE_EN_LSB                                        2
#define AXI_SPOOFER_CE_EN_MASK                                       0x00000004
#define AXI_SPOOFER_CE_EN_GET(x)                                     (((x) & AXI_SPOOFER_CE_EN_MASK) >> AXI_SPOOFER_CE_EN_LSB)
#define AXI_SPOOFER_CE_EN_SET(x)                                     (((0 | (x)) << AXI_SPOOFER_CE_EN_LSB) & AXI_SPOOFER_CE_EN_MASK)
#define AXI_SPOOFER_CE_EN_RESET                                      0
#define AXI_SPOOFER_WMAC_EN_MSB                                      1
#define AXI_SPOOFER_WMAC_EN_LSB                                      1
#define AXI_SPOOFER_WMAC_EN_MASK                                     0x00000002
#define AXI_SPOOFER_WMAC_EN_GET(x)                                   (((x) & AXI_SPOOFER_WMAC_EN_MASK) >> AXI_SPOOFER_WMAC_EN_LSB)
#define AXI_SPOOFER_WMAC_EN_SET(x)                                   (((0 | (x)) << AXI_SPOOFER_WMAC_EN_LSB) & AXI_SPOOFER_WMAC_EN_MASK)
#define AXI_SPOOFER_WMAC_EN_RESET                                    0
#define AXI_SPOOFER_CPU_M_EN_MSB                                     0
#define AXI_SPOOFER_CPU_M_EN_LSB                                     0
#define AXI_SPOOFER_CPU_M_EN_MASK                                    0x00000001
#define AXI_SPOOFER_CPU_M_EN_GET(x)                                  (((x) & AXI_SPOOFER_CPU_M_EN_MASK) >> AXI_SPOOFER_CPU_M_EN_LSB)
#define AXI_SPOOFER_CPU_M_EN_SET(x)                                  (((0 | (x)) << AXI_SPOOFER_CPU_M_EN_LSB) & AXI_SPOOFER_CPU_M_EN_MASK)
#define AXI_SPOOFER_CPU_M_EN_RESET                                   0
#define AXI_SPOOFER_ADDRESS                                          0x0020
#define AXI_SPOOFER_HW_MASK                                          0x0000003f
#define AXI_SPOOFER_SW_MASK                                          0x0000003f
#define AXI_SPOOFER_HW_WRITE_MASK                                    0x00000000
#define AXI_SPOOFER_SW_WRITE_MASK                                    0x0000003f
#define AXI_SPOOFER_RSTMASK                                          0xffffffff
#define AXI_SPOOFER_RESET                                            0x00000000

// 0x0024 (SCRATCH_0)
#define SCRATCH_0_VAL_MSB                                            31
#define SCRATCH_0_VAL_LSB                                            0
#define SCRATCH_0_VAL_MASK                                           0xffffffff
#define SCRATCH_0_VAL_GET(x)                                         (((x) & SCRATCH_0_VAL_MASK) >> SCRATCH_0_VAL_LSB)
#define SCRATCH_0_VAL_SET(x)                                         (((0 | (x)) << SCRATCH_0_VAL_LSB) & SCRATCH_0_VAL_MASK)
#define SCRATCH_0_VAL_RESET                                          0
#define SCRATCH_0_ADDRESS                                            0x0024
#define SCRATCH_0_HW_MASK                                            0xffffffff
#define SCRATCH_0_SW_MASK                                            0xffffffff
#define SCRATCH_0_HW_WRITE_MASK                                      0x00000000
#define SCRATCH_0_SW_WRITE_MASK                                      0xffffffff
#define SCRATCH_0_RSTMASK                                            0xffffffff
#define SCRATCH_0_RESET                                              0x00000000

// 0x0028 (SCRATCH_1)
#define SCRATCH_1_VAL_MSB                                            31
#define SCRATCH_1_VAL_LSB                                            0
#define SCRATCH_1_VAL_MASK                                           0xffffffff
#define SCRATCH_1_VAL_GET(x)                                         (((x) & SCRATCH_1_VAL_MASK) >> SCRATCH_1_VAL_LSB)
#define SCRATCH_1_VAL_SET(x)                                         (((0 | (x)) << SCRATCH_1_VAL_LSB) & SCRATCH_1_VAL_MASK)
#define SCRATCH_1_VAL_RESET                                          0
#define SCRATCH_1_ADDRESS                                            0x0028
#define SCRATCH_1_HW_MASK                                            0xffffffff
#define SCRATCH_1_SW_MASK                                            0xffffffff
#define SCRATCH_1_HW_WRITE_MASK                                      0x00000000
#define SCRATCH_1_SW_WRITE_MASK                                      0xffffffff
#define SCRATCH_1_RSTMASK                                            0xffffffff
#define SCRATCH_1_RESET                                              0x00000000

// 0x002c (SCRATCH_2)
#define SCRATCH_2_VAL_MSB                                            31
#define SCRATCH_2_VAL_LSB                                            0
#define SCRATCH_2_VAL_MASK                                           0xffffffff
#define SCRATCH_2_VAL_GET(x)                                         (((x) & SCRATCH_2_VAL_MASK) >> SCRATCH_2_VAL_LSB)
#define SCRATCH_2_VAL_SET(x)                                         (((0 | (x)) << SCRATCH_2_VAL_LSB) & SCRATCH_2_VAL_MASK)
#define SCRATCH_2_VAL_RESET                                          0
#define SCRATCH_2_ADDRESS                                            0x002c
#define SCRATCH_2_HW_MASK                                            0xffffffff
#define SCRATCH_2_SW_MASK                                            0xffffffff
#define SCRATCH_2_HW_WRITE_MASK                                      0x00000000
#define SCRATCH_2_SW_WRITE_MASK                                      0xffffffff
#define SCRATCH_2_RSTMASK                                            0xffffffff
#define SCRATCH_2_RESET                                              0x00000000

// 0x0030 (SCRATCH_3)
#define SCRATCH_3_VAL_MSB                                            31
#define SCRATCH_3_VAL_LSB                                            0
#define SCRATCH_3_VAL_MASK                                           0xffffffff
#define SCRATCH_3_VAL_GET(x)                                         (((x) & SCRATCH_3_VAL_MASK) >> SCRATCH_3_VAL_LSB)
#define SCRATCH_3_VAL_SET(x)                                         (((0 | (x)) << SCRATCH_3_VAL_LSB) & SCRATCH_3_VAL_MASK)
#define SCRATCH_3_VAL_RESET                                          0
#define SCRATCH_3_ADDRESS                                            0x0030
#define SCRATCH_3_HW_MASK                                            0xffffffff
#define SCRATCH_3_SW_MASK                                            0xffffffff
#define SCRATCH_3_HW_WRITE_MASK                                      0x00000000
#define SCRATCH_3_SW_WRITE_MASK                                      0xffffffff
#define SCRATCH_3_RSTMASK                                            0xffffffff
#define SCRATCH_3_RESET                                              0x00000000


#endif /* _SOC_CORE_REG_H_ */
