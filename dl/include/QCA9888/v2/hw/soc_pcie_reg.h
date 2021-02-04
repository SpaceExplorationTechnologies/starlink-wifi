/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _SOC_PCIE_REG_H_
#define _SOC_PCIE_REG_H_


#ifndef __SOC_PCIE_REG_BASE_ADDRESS
#define __SOC_PCIE_REG_BASE_ADDRESS (0x81000)
#endif


// 0x0 (PCIE_DEBUG_LOW)
#define PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_LSB                                 0
#define PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_MSB                                 31
#define PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_MASK                                0xffffffff
#define PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_GET(x)                              (((x) & PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_MASK) >> PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_LSB)
#define PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_SET(x)                              (((0 | (x)) << PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_LSB) & PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_MASK)
#define PCIE_DEBUG_LOW_CXPL_DEBUG_INFO_LOW_RESET                               0x0
#define PCIE_DEBUG_LOW_ADDRESS                                                 (0x0 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_DEBUG_LOW_RSTMASK                                                 0xffffffff
#define PCIE_DEBUG_LOW_RESET                                                   0x0

// 0x4 (PCIE_DEBUG_HIGH)
#define PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_LSB                               0
#define PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_MSB                               31
#define PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_MASK                              0xffffffff
#define PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_GET(x)                            (((x) & PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_MASK) >> PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_LSB)
#define PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_SET(x)                            (((0 | (x)) << PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_LSB) & PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_MASK)
#define PCIE_DEBUG_HIGH_CXPL_DEBUG_INFO_HIGH_RESET                             0x0
#define PCIE_DEBUG_HIGH_ADDRESS                                                (0x4 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_DEBUG_HIGH_RSTMASK                                                0xffffffff
#define PCIE_DEBUG_HIGH_RESET                                                  0x0

// 0x8 (PCIE_PM)
#define PCIE_PM_WAKE_LSB                                                       25
#define PCIE_PM_WAKE_MSB                                                       25
#define PCIE_PM_WAKE_MASK                                                      0x2000000
#define PCIE_PM_WAKE_GET(x)                                                    (((x) & PCIE_PM_WAKE_MASK) >> PCIE_PM_WAKE_LSB)
#define PCIE_PM_WAKE_SET(x)                                                    (((0 | (x)) << PCIE_PM_WAKE_LSB) & PCIE_PM_WAKE_MASK)
#define PCIE_PM_WAKE_RESET                                                     0x0
#define PCIE_PM_XMLH_L1_EXIT_LSB                                               24
#define PCIE_PM_XMLH_L1_EXIT_MSB                                               24
#define PCIE_PM_XMLH_L1_EXIT_MASK                                              0x1000000
#define PCIE_PM_XMLH_L1_EXIT_GET(x)                                            (((x) & PCIE_PM_XMLH_L1_EXIT_MASK) >> PCIE_PM_XMLH_L1_EXIT_LSB)
#define PCIE_PM_XMLH_L1_EXIT_SET(x)                                            (((0 | (x)) << PCIE_PM_XMLH_L1_EXIT_LSB) & PCIE_PM_XMLH_L1_EXIT_MASK)
#define PCIE_PM_XMLH_L1_EXIT_RESET                                             0x0
#define PCIE_PM_LINK_REQ_RST_N_LSB                                             23
#define PCIE_PM_LINK_REQ_RST_N_MSB                                             23
#define PCIE_PM_LINK_REQ_RST_N_MASK                                            0x800000
#define PCIE_PM_LINK_REQ_RST_N_GET(x)                                          (((x) & PCIE_PM_LINK_REQ_RST_N_MASK) >> PCIE_PM_LINK_REQ_RST_N_LSB)
#define PCIE_PM_LINK_REQ_RST_N_SET(x)                                          (((0 | (x)) << PCIE_PM_LINK_REQ_RST_N_LSB) & PCIE_PM_LINK_REQ_RST_N_MASK)
#define PCIE_PM_LINK_REQ_RST_N_RESET                                           0x0
#define PCIE_PM_RDLH_LINK_UP_LSB                                               22
#define PCIE_PM_RDLH_LINK_UP_MSB                                               22
#define PCIE_PM_RDLH_LINK_UP_MASK                                              0x400000
#define PCIE_PM_RDLH_LINK_UP_GET(x)                                            (((x) & PCIE_PM_RDLH_LINK_UP_MASK) >> PCIE_PM_RDLH_LINK_UP_LSB)
#define PCIE_PM_RDLH_LINK_UP_SET(x)                                            (((0 | (x)) << PCIE_PM_RDLH_LINK_UP_LSB) & PCIE_PM_RDLH_LINK_UP_MASK)
#define PCIE_PM_RDLH_LINK_UP_RESET                                             0x0
#define PCIE_PM_MASTER_STATE_LSB                                               17
#define PCIE_PM_MASTER_STATE_MSB                                               21
#define PCIE_PM_MASTER_STATE_MASK                                              0x3e0000
#define PCIE_PM_MASTER_STATE_GET(x)                                            (((x) & PCIE_PM_MASTER_STATE_MASK) >> PCIE_PM_MASTER_STATE_LSB)
#define PCIE_PM_MASTER_STATE_SET(x)                                            (((0 | (x)) << PCIE_PM_MASTER_STATE_LSB) & PCIE_PM_MASTER_STATE_MASK)
#define PCIE_PM_MASTER_STATE_RESET                                             0x0
#define PCIE_PM_PME_EN_LSB                                                     16
#define PCIE_PM_PME_EN_MSB                                                     16
#define PCIE_PM_PME_EN_MASK                                                    0x10000
#define PCIE_PM_PME_EN_GET(x)                                                  (((x) & PCIE_PM_PME_EN_MASK) >> PCIE_PM_PME_EN_LSB)
#define PCIE_PM_PME_EN_SET(x)                                                  (((0 | (x)) << PCIE_PM_PME_EN_LSB) & PCIE_PM_PME_EN_MASK)
#define PCIE_PM_PME_EN_RESET                                                   0x0
#define PCIE_PM_AUX_PM_EN_LSB                                                  15
#define PCIE_PM_AUX_PM_EN_MSB                                                  15
#define PCIE_PM_AUX_PM_EN_MASK                                                 0x8000
#define PCIE_PM_AUX_PM_EN_GET(x)                                               (((x) & PCIE_PM_AUX_PM_EN_MASK) >> PCIE_PM_AUX_PM_EN_LSB)
#define PCIE_PM_AUX_PM_EN_SET(x)                                               (((0 | (x)) << PCIE_PM_AUX_PM_EN_LSB) & PCIE_PM_AUX_PM_EN_MASK)
#define PCIE_PM_AUX_PM_EN_RESET                                                0x0
#define PCIE_PM_XTLH_BLOCK_TLP_LSB                                             14
#define PCIE_PM_XTLH_BLOCK_TLP_MSB                                             14
#define PCIE_PM_XTLH_BLOCK_TLP_MASK                                            0x4000
#define PCIE_PM_XTLH_BLOCK_TLP_GET(x)                                          (((x) & PCIE_PM_XTLH_BLOCK_TLP_MASK) >> PCIE_PM_XTLH_BLOCK_TLP_LSB)
#define PCIE_PM_XTLH_BLOCK_TLP_SET(x)                                          (((0 | (x)) << PCIE_PM_XTLH_BLOCK_TLP_LSB) & PCIE_PM_XTLH_BLOCK_TLP_MASK)
#define PCIE_PM_XTLH_BLOCK_TLP_RESET                                           0x0
#define PCIE_PM_DSTATE_LSB                                                     11
#define PCIE_PM_DSTATE_MSB                                                     13
#define PCIE_PM_DSTATE_MASK                                                    0x3800
#define PCIE_PM_DSTATE_GET(x)                                                  (((x) & PCIE_PM_DSTATE_MASK) >> PCIE_PM_DSTATE_LSB)
#define PCIE_PM_DSTATE_SET(x)                                                  (((0 | (x)) << PCIE_PM_DSTATE_LSB) & PCIE_PM_DSTATE_MASK)
#define PCIE_PM_DSTATE_RESET                                                   0x0
#define PCIE_PM_LTSSM_STATE_LSB                                                5
#define PCIE_PM_LTSSM_STATE_MSB                                                10
#define PCIE_PM_LTSSM_STATE_MASK                                               0x7e0
#define PCIE_PM_LTSSM_STATE_GET(x)                                             (((x) & PCIE_PM_LTSSM_STATE_MASK) >> PCIE_PM_LTSSM_STATE_LSB)
#define PCIE_PM_LTSSM_STATE_SET(x)                                             (((0 | (x)) << PCIE_PM_LTSSM_STATE_LSB) & PCIE_PM_LTSSM_STATE_MASK)
#define PCIE_PM_LTSSM_STATE_RESET                                              0x0
#define PCIE_PM_STATUS_LSB                                                     4
#define PCIE_PM_STATUS_MSB                                                     4
#define PCIE_PM_STATUS_MASK                                                    0x10
#define PCIE_PM_STATUS_GET(x)                                                  (((x) & PCIE_PM_STATUS_MASK) >> PCIE_PM_STATUS_LSB)
#define PCIE_PM_STATUS_SET(x)                                                  (((0 | (x)) << PCIE_PM_STATUS_LSB) & PCIE_PM_STATUS_MASK)
#define PCIE_PM_STATUS_RESET                                                   0x0
#define PCIE_PM_XMLH_LINK_UP_LSB                                               3
#define PCIE_PM_XMLH_LINK_UP_MSB                                               3
#define PCIE_PM_XMLH_LINK_UP_MASK                                              0x8
#define PCIE_PM_XMLH_LINK_UP_GET(x)                                            (((x) & PCIE_PM_XMLH_LINK_UP_MASK) >> PCIE_PM_XMLH_LINK_UP_LSB)
#define PCIE_PM_XMLH_LINK_UP_SET(x)                                            (((0 | (x)) << PCIE_PM_XMLH_LINK_UP_LSB) & PCIE_PM_XMLH_LINK_UP_MASK)
#define PCIE_PM_XMLH_LINK_UP_RESET                                             0x0
#define PCIE_PM_CURNT_STATE_LSB                                                0
#define PCIE_PM_CURNT_STATE_MSB                                                2
#define PCIE_PM_CURNT_STATE_MASK                                               0x7
#define PCIE_PM_CURNT_STATE_GET(x)                                             (((x) & PCIE_PM_CURNT_STATE_MASK) >> PCIE_PM_CURNT_STATE_LSB)
#define PCIE_PM_CURNT_STATE_SET(x)                                             (((0 | (x)) << PCIE_PM_CURNT_STATE_LSB) & PCIE_PM_CURNT_STATE_MASK)
#define PCIE_PM_CURNT_STATE_RESET                                              0x0
#define PCIE_PM_ADDRESS                                                        (0x8 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_PM_RSTMASK                                                        0x3ffffff
#define PCIE_PM_RESET                                                          0x0

// 0xc (PCIE_CTRL)
#define PCIE_CTRL_L123_PCIE_CLK_REMAIN_TIME_LSB                                28
#define PCIE_CTRL_L123_PCIE_CLK_REMAIN_TIME_MSB                                31
#define PCIE_CTRL_L123_PCIE_CLK_REMAIN_TIME_MASK                               0xf0000000
#define PCIE_CTRL_L123_PCIE_CLK_REMAIN_TIME_GET(x)                             (((x) & PCIE_CTRL_L123_PCIE_CLK_REMAIN_TIME_MASK) >> PCIE_CTRL_L123_PCIE_CLK_REMAIN_TIME_LSB)
#define PCIE_CTRL_L123_PCIE_CLK_REMAIN_TIME_SET(x)                             (((0 | (x)) << PCIE_CTRL_L123_PCIE_CLK_REMAIN_TIME_LSB) & PCIE_CTRL_L123_PCIE_CLK_REMAIN_TIME_MASK)
#define PCIE_CTRL_L123_PCIE_CLK_REMAIN_TIME_RESET                              0x6
#define PCIE_CTRL_L123_PCIE_CORE_CLK_UG_GATED_EN_LSB                           27
#define PCIE_CTRL_L123_PCIE_CORE_CLK_UG_GATED_EN_MSB                           27
#define PCIE_CTRL_L123_PCIE_CORE_CLK_UG_GATED_EN_MASK                          0x8000000
#define PCIE_CTRL_L123_PCIE_CORE_CLK_UG_GATED_EN_GET(x)                        (((x) & PCIE_CTRL_L123_PCIE_CORE_CLK_UG_GATED_EN_MASK) >> PCIE_CTRL_L123_PCIE_CORE_CLK_UG_GATED_EN_LSB)
#define PCIE_CTRL_L123_PCIE_CORE_CLK_UG_GATED_EN_SET(x)                        (((0 | (x)) << PCIE_CTRL_L123_PCIE_CORE_CLK_UG_GATED_EN_LSB) & PCIE_CTRL_L123_PCIE_CORE_CLK_UG_GATED_EN_MASK)
#define PCIE_CTRL_L123_PCIE_CORE_CLK_UG_GATED_EN_RESET                         0x0
#define PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_HW_CTRL_EN_LSB                  26
#define PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_HW_CTRL_EN_MSB                  26
#define PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_HW_CTRL_EN_MASK                 0x4000000
#define PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_HW_CTRL_EN_GET(x)               (((x) & PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_HW_CTRL_EN_MASK) >> PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_HW_CTRL_EN_LSB)
#define PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_HW_CTRL_EN_SET(x)               (((0 | (x)) << PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_HW_CTRL_EN_LSB) & PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_HW_CTRL_EN_MASK)
#define PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_HW_CTRL_EN_RESET                0x0
#define PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_SW_CTRL_EN_LSB                  25
#define PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_SW_CTRL_EN_MSB                  25
#define PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_SW_CTRL_EN_MASK                 0x2000000
#define PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_SW_CTRL_EN_GET(x)               (((x) & PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_SW_CTRL_EN_MASK) >> PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_SW_CTRL_EN_LSB)
#define PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_SW_CTRL_EN_SET(x)               (((0 | (x)) << PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_SW_CTRL_EN_LSB) & PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_SW_CTRL_EN_MASK)
#define PCIE_CTRL_L123_PCIETXBUF_AXI_CLK_GATED_SW_CTRL_EN_RESET                0x0
#define PCIE_CTRL_L123_AXI_CLK_GATED_EN_LSB                                    24
#define PCIE_CTRL_L123_AXI_CLK_GATED_EN_MSB                                    24
#define PCIE_CTRL_L123_AXI_CLK_GATED_EN_MASK                                   0x1000000
#define PCIE_CTRL_L123_AXI_CLK_GATED_EN_GET(x)                                 (((x) & PCIE_CTRL_L123_AXI_CLK_GATED_EN_MASK) >> PCIE_CTRL_L123_AXI_CLK_GATED_EN_LSB)
#define PCIE_CTRL_L123_AXI_CLK_GATED_EN_SET(x)                                 (((0 | (x)) << PCIE_CTRL_L123_AXI_CLK_GATED_EN_LSB) & PCIE_CTRL_L123_AXI_CLK_GATED_EN_MASK)
#define PCIE_CTRL_L123_AXI_CLK_GATED_EN_RESET                                  0x0
#define PCIE_CTRL_L123_PCIE_CORE_CLK_GATED_EN_LSB                              23
#define PCIE_CTRL_L123_PCIE_CORE_CLK_GATED_EN_MSB                              23
#define PCIE_CTRL_L123_PCIE_CORE_CLK_GATED_EN_MASK                             0x800000
#define PCIE_CTRL_L123_PCIE_CORE_CLK_GATED_EN_GET(x)                           (((x) & PCIE_CTRL_L123_PCIE_CORE_CLK_GATED_EN_MASK) >> PCIE_CTRL_L123_PCIE_CORE_CLK_GATED_EN_LSB)
#define PCIE_CTRL_L123_PCIE_CORE_CLK_GATED_EN_SET(x)                           (((0 | (x)) << PCIE_CTRL_L123_PCIE_CORE_CLK_GATED_EN_LSB) & PCIE_CTRL_L123_PCIE_CORE_CLK_GATED_EN_MASK)
#define PCIE_CTRL_L123_PCIE_CORE_CLK_GATED_EN_RESET                            0x0
#define PCIE_CTRL_STICKY_RST_FIX_OVRD_LSB                                      22
#define PCIE_CTRL_STICKY_RST_FIX_OVRD_MSB                                      22
#define PCIE_CTRL_STICKY_RST_FIX_OVRD_MASK                                     0x400000
#define PCIE_CTRL_STICKY_RST_FIX_OVRD_GET(x)                                   (((x) & PCIE_CTRL_STICKY_RST_FIX_OVRD_MASK) >> PCIE_CTRL_STICKY_RST_FIX_OVRD_LSB)
#define PCIE_CTRL_STICKY_RST_FIX_OVRD_SET(x)                                   (((0 | (x)) << PCIE_CTRL_STICKY_RST_FIX_OVRD_LSB) & PCIE_CTRL_STICKY_RST_FIX_OVRD_MASK)
#define PCIE_CTRL_STICKY_RST_FIX_OVRD_RESET                                    0x0
#define PCIE_CTRL_STICKY_RST_FIX_EN_LSB                                        21
#define PCIE_CTRL_STICKY_RST_FIX_EN_MSB                                        21
#define PCIE_CTRL_STICKY_RST_FIX_EN_MASK                                       0x200000
#define PCIE_CTRL_STICKY_RST_FIX_EN_GET(x)                                     (((x) & PCIE_CTRL_STICKY_RST_FIX_EN_MASK) >> PCIE_CTRL_STICKY_RST_FIX_EN_LSB)
#define PCIE_CTRL_STICKY_RST_FIX_EN_SET(x)                                     (((0 | (x)) << PCIE_CTRL_STICKY_RST_FIX_EN_LSB) & PCIE_CTRL_STICKY_RST_FIX_EN_MASK)
#define PCIE_CTRL_STICKY_RST_FIX_EN_RESET                                      0x0
#define PCIE_CTRL_RST_MASK_LSB                                                 20
#define PCIE_CTRL_RST_MASK_MSB                                                 20
#define PCIE_CTRL_RST_MASK_MASK                                                0x100000
#define PCIE_CTRL_RST_MASK_GET(x)                                              (((x) & PCIE_CTRL_RST_MASK_MASK) >> PCIE_CTRL_RST_MASK_LSB)
#define PCIE_CTRL_RST_MASK_SET(x)                                              (((0 | (x)) << PCIE_CTRL_RST_MASK_LSB) & PCIE_CTRL_RST_MASK_MASK)
#define PCIE_CTRL_RST_MASK_RESET                                               0x0
#define PCIE_CTRL_PME_GNT_EN_LSB                                               18
#define PCIE_CTRL_PME_GNT_EN_MSB                                               18
#define PCIE_CTRL_PME_GNT_EN_MASK                                              0x40000
#define PCIE_CTRL_PME_GNT_EN_GET(x)                                            (((x) & PCIE_CTRL_PME_GNT_EN_MASK) >> PCIE_CTRL_PME_GNT_EN_LSB)
#define PCIE_CTRL_PME_GNT_EN_SET(x)                                            (((0 | (x)) << PCIE_CTRL_PME_GNT_EN_LSB) & PCIE_CTRL_PME_GNT_EN_MASK)
#define PCIE_CTRL_PME_GNT_EN_RESET                                             0x0
#define PCIE_CTRL_DBI_OVERRIDE_LSB                                             17
#define PCIE_CTRL_DBI_OVERRIDE_MSB                                             17
#define PCIE_CTRL_DBI_OVERRIDE_MASK                                            0x20000
#define PCIE_CTRL_DBI_OVERRIDE_GET(x)                                          (((x) & PCIE_CTRL_DBI_OVERRIDE_MASK) >> PCIE_CTRL_DBI_OVERRIDE_LSB)
#define PCIE_CTRL_DBI_OVERRIDE_SET(x)                                          (((0 | (x)) << PCIE_CTRL_DBI_OVERRIDE_LSB) & PCIE_CTRL_DBI_OVERRIDE_MASK)
#define PCIE_CTRL_DBI_OVERRIDE_RESET                                           0x0
#define PCIE_CTRL_IGNORE_AXI_PCIE_L1_LSB                                       16
#define PCIE_CTRL_IGNORE_AXI_PCIE_L1_MSB                                       16
#define PCIE_CTRL_IGNORE_AXI_PCIE_L1_MASK                                      0x10000
#define PCIE_CTRL_IGNORE_AXI_PCIE_L1_GET(x)                                    (((x) & PCIE_CTRL_IGNORE_AXI_PCIE_L1_MASK) >> PCIE_CTRL_IGNORE_AXI_PCIE_L1_LSB)
#define PCIE_CTRL_IGNORE_AXI_PCIE_L1_SET(x)                                    (((0 | (x)) << PCIE_CTRL_IGNORE_AXI_PCIE_L1_LSB) & PCIE_CTRL_IGNORE_AXI_PCIE_L1_MASK)
#define PCIE_CTRL_IGNORE_AXI_PCIE_L1_RESET                                     0x0
#define PCIE_CTRL_IGNORE_MAC_FOR_L1_LSB                                        15
#define PCIE_CTRL_IGNORE_MAC_FOR_L1_MSB                                        15
#define PCIE_CTRL_IGNORE_MAC_FOR_L1_MASK                                       0x8000
#define PCIE_CTRL_IGNORE_MAC_FOR_L1_GET(x)                                     (((x) & PCIE_CTRL_IGNORE_MAC_FOR_L1_MASK) >> PCIE_CTRL_IGNORE_MAC_FOR_L1_LSB)
#define PCIE_CTRL_IGNORE_MAC_FOR_L1_SET(x)                                     (((0 | (x)) << PCIE_CTRL_IGNORE_MAC_FOR_L1_LSB) & PCIE_CTRL_IGNORE_MAC_FOR_L1_MASK)
#define PCIE_CTRL_IGNORE_MAC_FOR_L1_RESET                                      0x0
#define PCIE_CTRL_TARGET_L1_EN_LSB                                             14
#define PCIE_CTRL_TARGET_L1_EN_MSB                                             14
#define PCIE_CTRL_TARGET_L1_EN_MASK                                            0x4000
#define PCIE_CTRL_TARGET_L1_EN_GET(x)                                          (((x) & PCIE_CTRL_TARGET_L1_EN_MASK) >> PCIE_CTRL_TARGET_L1_EN_LSB)
#define PCIE_CTRL_TARGET_L1_EN_SET(x)                                          (((0 | (x)) << PCIE_CTRL_TARGET_L1_EN_LSB) & PCIE_CTRL_TARGET_L1_EN_MASK)
#define PCIE_CTRL_TARGET_L1_EN_RESET                                           0x0
#define PCIE_CTRL_HOST_L1_EN_LSB                                               13
#define PCIE_CTRL_HOST_L1_EN_MSB                                               13
#define PCIE_CTRL_HOST_L1_EN_MASK                                              0x2000
#define PCIE_CTRL_HOST_L1_EN_GET(x)                                            (((x) & PCIE_CTRL_HOST_L1_EN_MASK) >> PCIE_CTRL_HOST_L1_EN_LSB)
#define PCIE_CTRL_HOST_L1_EN_SET(x)                                            (((0 | (x)) << PCIE_CTRL_HOST_L1_EN_LSB) & PCIE_CTRL_HOST_L1_EN_MASK)
#define PCIE_CTRL_HOST_L1_EN_RESET                                             0x0
#define PCIE_CTRL_TRAINING_RST_EN_LSB                                          12
#define PCIE_CTRL_TRAINING_RST_EN_MSB                                          12
#define PCIE_CTRL_TRAINING_RST_EN_MASK                                         0x1000
#define PCIE_CTRL_TRAINING_RST_EN_GET(x)                                       (((x) & PCIE_CTRL_TRAINING_RST_EN_MASK) >> PCIE_CTRL_TRAINING_RST_EN_LSB)
#define PCIE_CTRL_TRAINING_RST_EN_SET(x)                                       (((0 | (x)) << PCIE_CTRL_TRAINING_RST_EN_LSB) & PCIE_CTRL_TRAINING_RST_EN_MASK)
#define PCIE_CTRL_TRAINING_RST_EN_RESET                                        0x0
#define PCIE_CTRL_RDLH_LINK_RST_EN_LSB                                         11
#define PCIE_CTRL_RDLH_LINK_RST_EN_MSB                                         11
#define PCIE_CTRL_RDLH_LINK_RST_EN_MASK                                        0x800
#define PCIE_CTRL_RDLH_LINK_RST_EN_GET(x)                                      (((x) & PCIE_CTRL_RDLH_LINK_RST_EN_MASK) >> PCIE_CTRL_RDLH_LINK_RST_EN_LSB)
#define PCIE_CTRL_RDLH_LINK_RST_EN_SET(x)                                      (((0 | (x)) << PCIE_CTRL_RDLH_LINK_RST_EN_LSB) & PCIE_CTRL_RDLH_LINK_RST_EN_MASK)
#define PCIE_CTRL_RDLH_LINK_RST_EN_RESET                                       0x0
#define PCIE_CTRL_LINK_REQ_RST_EN_LSB                                          10
#define PCIE_CTRL_LINK_REQ_RST_EN_MSB                                          10
#define PCIE_CTRL_LINK_REQ_RST_EN_MASK                                         0x400
#define PCIE_CTRL_LINK_REQ_RST_EN_GET(x)                                       (((x) & PCIE_CTRL_LINK_REQ_RST_EN_MASK) >> PCIE_CTRL_LINK_REQ_RST_EN_LSB)
#define PCIE_CTRL_LINK_REQ_RST_EN_SET(x)                                       (((0 | (x)) << PCIE_CTRL_LINK_REQ_RST_EN_LSB) & PCIE_CTRL_LINK_REQ_RST_EN_MASK)
#define PCIE_CTRL_LINK_REQ_RST_EN_RESET                                        0x0
#define PCIE_CTRL_XMLH_LINK_RST_EN_LSB                                         9
#define PCIE_CTRL_XMLH_LINK_RST_EN_MSB                                         9
#define PCIE_CTRL_XMLH_LINK_RST_EN_MASK                                        0x200
#define PCIE_CTRL_XMLH_LINK_RST_EN_GET(x)                                      (((x) & PCIE_CTRL_XMLH_LINK_RST_EN_MASK) >> PCIE_CTRL_XMLH_LINK_RST_EN_LSB)
#define PCIE_CTRL_XMLH_LINK_RST_EN_SET(x)                                      (((0 | (x)) << PCIE_CTRL_XMLH_LINK_RST_EN_LSB) & PCIE_CTRL_XMLH_LINK_RST_EN_MASK)
#define PCIE_CTRL_XMLH_LINK_RST_EN_RESET                                       0x1
#define PCIE_CTRL_APP_LTSSM_ENABLE_LSB                                         8
#define PCIE_CTRL_APP_LTSSM_ENABLE_MSB                                         8
#define PCIE_CTRL_APP_LTSSM_ENABLE_MASK                                        0x100
#define PCIE_CTRL_APP_LTSSM_ENABLE_GET(x)                                      (((x) & PCIE_CTRL_APP_LTSSM_ENABLE_MASK) >> PCIE_CTRL_APP_LTSSM_ENABLE_LSB)
#define PCIE_CTRL_APP_LTSSM_ENABLE_SET(x)                                      (((0 | (x)) << PCIE_CTRL_APP_LTSSM_ENABLE_LSB) & PCIE_CTRL_APP_LTSSM_ENABLE_MASK)
#define PCIE_CTRL_APP_LTSSM_ENABLE_RESET                                       0x0
#define PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_LSB                              7
#define PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_MSB                              7
#define PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_MASK                             0x80
#define PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_GET(x)                           (((x) & PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_MASK) >> PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_LSB)
#define PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_SET(x)                           (((0 | (x)) << PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_LSB) & PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_MASK)
#define PCIE_CTRL_ASPM_TIMER_BASED_L1_DISABLE_RESET                            0x0
#define PCIE_CTRL_SYS_AUX_PWR_DET_LSB                                          6
#define PCIE_CTRL_SYS_AUX_PWR_DET_MSB                                          6
#define PCIE_CTRL_SYS_AUX_PWR_DET_MASK                                         0x40
#define PCIE_CTRL_SYS_AUX_PWR_DET_GET(x)                                       (((x) & PCIE_CTRL_SYS_AUX_PWR_DET_MASK) >> PCIE_CTRL_SYS_AUX_PWR_DET_LSB)
#define PCIE_CTRL_SYS_AUX_PWR_DET_SET(x)                                       (((0 | (x)) << PCIE_CTRL_SYS_AUX_PWR_DET_LSB) & PCIE_CTRL_SYS_AUX_PWR_DET_MASK)
#define PCIE_CTRL_SYS_AUX_PWR_DET_RESET                                        0x0
#define PCIE_CTRL_D3_TO_L1_DISABLE_EN_LSB                                      5
#define PCIE_CTRL_D3_TO_L1_DISABLE_EN_MSB                                      5
#define PCIE_CTRL_D3_TO_L1_DISABLE_EN_MASK                                     0x20
#define PCIE_CTRL_D3_TO_L1_DISABLE_EN_GET(x)                                   (((x) & PCIE_CTRL_D3_TO_L1_DISABLE_EN_MASK) >> PCIE_CTRL_D3_TO_L1_DISABLE_EN_LSB)
#define PCIE_CTRL_D3_TO_L1_DISABLE_EN_SET(x)                                   (((0 | (x)) << PCIE_CTRL_D3_TO_L1_DISABLE_EN_LSB) & PCIE_CTRL_D3_TO_L1_DISABLE_EN_MASK)
#define PCIE_CTRL_D3_TO_L1_DISABLE_EN_RESET                                    0x0
#define PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_LSB                                 4
#define PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_MSB                                 4
#define PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_MASK                                0x10
#define PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_GET(x)                              (((x) & PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_MASK) >> PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_LSB)
#define PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_SET(x)                              (((0 | (x)) << PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_LSB) & PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_MASK)
#define PCIE_CTRL_D3_TO_L1_DISABLE_REAL_EN_RESET                               0x0
#define PCIE_CTRL_NO_NAK_WA_EN_LSB                                             3
#define PCIE_CTRL_NO_NAK_WA_EN_MSB                                             3
#define PCIE_CTRL_NO_NAK_WA_EN_MASK                                            0x8
#define PCIE_CTRL_NO_NAK_WA_EN_GET(x)                                          (((x) & PCIE_CTRL_NO_NAK_WA_EN_MASK) >> PCIE_CTRL_NO_NAK_WA_EN_LSB)
#define PCIE_CTRL_NO_NAK_WA_EN_SET(x)                                          (((0 | (x)) << PCIE_CTRL_NO_NAK_WA_EN_LSB) & PCIE_CTRL_NO_NAK_WA_EN_MASK)
#define PCIE_CTRL_NO_NAK_WA_EN_RESET                                           0x0
#define PCIE_CTRL_GDATA_WA_EN_LSB                                              2
#define PCIE_CTRL_GDATA_WA_EN_MSB                                              2
#define PCIE_CTRL_GDATA_WA_EN_MASK                                             0x4
#define PCIE_CTRL_GDATA_WA_EN_GET(x)                                           (((x) & PCIE_CTRL_GDATA_WA_EN_MASK) >> PCIE_CTRL_GDATA_WA_EN_LSB)
#define PCIE_CTRL_GDATA_WA_EN_SET(x)                                           (((0 | (x)) << PCIE_CTRL_GDATA_WA_EN_LSB) & PCIE_CTRL_GDATA_WA_EN_MASK)
#define PCIE_CTRL_GDATA_WA_EN_RESET                                            0x1
#define PCIE_CTRL_TS2_WA_EN_LSB                                                1
#define PCIE_CTRL_TS2_WA_EN_MSB                                                1
#define PCIE_CTRL_TS2_WA_EN_MASK                                               0x2
#define PCIE_CTRL_TS2_WA_EN_GET(x)                                             (((x) & PCIE_CTRL_TS2_WA_EN_MASK) >> PCIE_CTRL_TS2_WA_EN_LSB)
#define PCIE_CTRL_TS2_WA_EN_SET(x)                                             (((0 | (x)) << PCIE_CTRL_TS2_WA_EN_LSB) & PCIE_CTRL_TS2_WA_EN_MASK)
#define PCIE_CTRL_TS2_WA_EN_RESET                                              0x1
#define PCIE_CTRL_TS1_WA_EN_LSB                                                0
#define PCIE_CTRL_TS1_WA_EN_MSB                                                0
#define PCIE_CTRL_TS1_WA_EN_MASK                                               0x1
#define PCIE_CTRL_TS1_WA_EN_GET(x)                                             (((x) & PCIE_CTRL_TS1_WA_EN_MASK) >> PCIE_CTRL_TS1_WA_EN_LSB)
#define PCIE_CTRL_TS1_WA_EN_SET(x)                                             (((0 | (x)) << PCIE_CTRL_TS1_WA_EN_LSB) & PCIE_CTRL_TS1_WA_EN_MASK)
#define PCIE_CTRL_TS1_WA_EN_RESET                                              0x1
#define PCIE_CTRL_ADDRESS                                                      (0xc + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_CTRL_RSTMASK                                                      0xfff7ffff
#define PCIE_CTRL_RESET                                                        0x60000207

// 0x10 (PCIE_NFTS)
#define PCIE_NFTS_CNTL_EN_LSB                                                  8
#define PCIE_NFTS_CNTL_EN_MSB                                                  8
#define PCIE_NFTS_CNTL_EN_MASK                                                 0x100
#define PCIE_NFTS_CNTL_EN_GET(x)                                               (((x) & PCIE_NFTS_CNTL_EN_MASK) >> PCIE_NFTS_CNTL_EN_LSB)
#define PCIE_NFTS_CNTL_EN_SET(x)                                               (((0 | (x)) << PCIE_NFTS_CNTL_EN_LSB) & PCIE_NFTS_CNTL_EN_MASK)
#define PCIE_NFTS_CNTL_EN_RESET                                                0x0
#define PCIE_NFTS_ADJ_LSB                                                      0
#define PCIE_NFTS_ADJ_MSB                                                      7
#define PCIE_NFTS_ADJ_MASK                                                     0xff
#define PCIE_NFTS_ADJ_GET(x)                                                   (((x) & PCIE_NFTS_ADJ_MASK) >> PCIE_NFTS_ADJ_LSB)
#define PCIE_NFTS_ADJ_SET(x)                                                   (((0 | (x)) << PCIE_NFTS_ADJ_LSB) & PCIE_NFTS_ADJ_MASK)
#define PCIE_NFTS_ADJ_RESET                                                    0x0
#define PCIE_NFTS_ADDRESS                                                      (0x10 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_NFTS_RSTMASK                                                      0x1ff
#define PCIE_NFTS_RESET                                                        0x0

// 0x14 (PCIE_MSI_STATUS)
#define PCIE_MSI_STATUS_MSI_INT_PENDING_LSB                                    21
#define PCIE_MSI_STATUS_MSI_INT_PENDING_MSB                                    24
#define PCIE_MSI_STATUS_MSI_INT_PENDING_MASK                                   0x1e00000
#define PCIE_MSI_STATUS_MSI_INT_PENDING_GET(x)                                 (((x) & PCIE_MSI_STATUS_MSI_INT_PENDING_MASK) >> PCIE_MSI_STATUS_MSI_INT_PENDING_LSB)
#define PCIE_MSI_STATUS_MSI_INT_PENDING_SET(x)                                 (((0 | (x)) << PCIE_MSI_STATUS_MSI_INT_PENDING_LSB) & PCIE_MSI_STATUS_MSI_INT_PENDING_MASK)
#define PCIE_MSI_STATUS_MSI_INT_PENDING_RESET                                  0x0
#define PCIE_MSI_STATUS_MULTI_LSB                                              18
#define PCIE_MSI_STATUS_MULTI_MSB                                              20
#define PCIE_MSI_STATUS_MULTI_MASK                                             0x1c0000
#define PCIE_MSI_STATUS_MULTI_GET(x)                                           (((x) & PCIE_MSI_STATUS_MULTI_MASK) >> PCIE_MSI_STATUS_MULTI_LSB)
#define PCIE_MSI_STATUS_MULTI_SET(x)                                           (((0 | (x)) << PCIE_MSI_STATUS_MULTI_LSB) & PCIE_MSI_STATUS_MULTI_MASK)
#define PCIE_MSI_STATUS_MULTI_RESET                                            0x0
#define PCIE_MSI_STATUS__64_BIT_LSB                                            17
#define PCIE_MSI_STATUS__64_BIT_MSB                                            17
#define PCIE_MSI_STATUS__64_BIT_MASK                                           0x20000
#define PCIE_MSI_STATUS__64_BIT_GET(x)                                         (((x) & PCIE_MSI_STATUS__64_BIT_MASK) >> PCIE_MSI_STATUS__64_BIT_LSB)
#define PCIE_MSI_STATUS__64_BIT_SET(x)                                         (((0 | (x)) << PCIE_MSI_STATUS__64_BIT_LSB) & PCIE_MSI_STATUS__64_BIT_MASK)
#define PCIE_MSI_STATUS__64_BIT_RESET                                          0x0
#define PCIE_MSI_STATUS_DATA_LSB                                               1
#define PCIE_MSI_STATUS_DATA_MSB                                               16
#define PCIE_MSI_STATUS_DATA_MASK                                              0x1fffe
#define PCIE_MSI_STATUS_DATA_GET(x)                                            (((x) & PCIE_MSI_STATUS_DATA_MASK) >> PCIE_MSI_STATUS_DATA_LSB)
#define PCIE_MSI_STATUS_DATA_SET(x)                                            (((0 | (x)) << PCIE_MSI_STATUS_DATA_LSB) & PCIE_MSI_STATUS_DATA_MASK)
#define PCIE_MSI_STATUS_DATA_RESET                                             0x0
#define PCIE_MSI_STATUS_EN_LSB                                                 0
#define PCIE_MSI_STATUS_EN_MSB                                                 0
#define PCIE_MSI_STATUS_EN_MASK                                                0x1
#define PCIE_MSI_STATUS_EN_GET(x)                                              (((x) & PCIE_MSI_STATUS_EN_MASK) >> PCIE_MSI_STATUS_EN_LSB)
#define PCIE_MSI_STATUS_EN_SET(x)                                              (((0 | (x)) << PCIE_MSI_STATUS_EN_LSB) & PCIE_MSI_STATUS_EN_MASK)
#define PCIE_MSI_STATUS_EN_RESET                                               0x0
#define PCIE_MSI_STATUS_ADDRESS                                                (0x14 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_MSI_STATUS_RSTMASK                                                0x1ffffff
#define PCIE_MSI_STATUS_RESET                                                  0x0

// 0x18 (PCIE_MSI_MASK)
#define PCIE_MSI_MASK_VALUE_LSB                                                0
#define PCIE_MSI_MASK_VALUE_MSB                                                31
#define PCIE_MSI_MASK_VALUE_MASK                                               0xffffffff
#define PCIE_MSI_MASK_VALUE_GET(x)                                             (((x) & PCIE_MSI_MASK_VALUE_MASK) >> PCIE_MSI_MASK_VALUE_LSB)
#define PCIE_MSI_MASK_VALUE_SET(x)                                             (((0 | (x)) << PCIE_MSI_MASK_VALUE_LSB) & PCIE_MSI_MASK_VALUE_MASK)
#define PCIE_MSI_MASK_VALUE_RESET                                              0x0
#define PCIE_MSI_MASK_ADDRESS                                                  (0x18 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_MSI_MASK_RSTMASK                                                  0xffffffff
#define PCIE_MSI_MASK_RESET                                                    0x0

// 0x1c (PCIE_MSI_ADDR)
#define PCIE_MSI_ADDR_LOW_LSB                                                  0
#define PCIE_MSI_ADDR_LOW_MSB                                                  31
#define PCIE_MSI_ADDR_LOW_MASK                                                 0xffffffff
#define PCIE_MSI_ADDR_LOW_GET(x)                                               (((x) & PCIE_MSI_ADDR_LOW_MASK) >> PCIE_MSI_ADDR_LOW_LSB)
#define PCIE_MSI_ADDR_LOW_SET(x)                                               (((0 | (x)) << PCIE_MSI_ADDR_LOW_LSB) & PCIE_MSI_ADDR_LOW_MASK)
#define PCIE_MSI_ADDR_LOW_RESET                                                0x0
#define PCIE_MSI_ADDR_ADDRESS                                                  (0x1c + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_MSI_ADDR_RSTMASK                                                  0xffffffff
#define PCIE_MSI_ADDR_RESET                                                    0x0

// 0x20 (PCIE_CO_ERR_CTR0)
#define PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_LSB                                      16
#define PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_MSB                                      23
#define PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_MASK                                     0xff0000
#define PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_GET(x)                                   (((x) & PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_MASK) >> PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_LSB)
#define PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_SET(x)                                   (((0 | (x)) << PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_LSB) & PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_MASK)
#define PCIE_CO_ERR_CTR0_BAD_DLLP_ERR_RESET                                    0x0
#define PCIE_CO_ERR_CTR0_BAD_TLP_ERR_LSB                                       8
#define PCIE_CO_ERR_CTR0_BAD_TLP_ERR_MSB                                       15
#define PCIE_CO_ERR_CTR0_BAD_TLP_ERR_MASK                                      0xff00
#define PCIE_CO_ERR_CTR0_BAD_TLP_ERR_GET(x)                                    (((x) & PCIE_CO_ERR_CTR0_BAD_TLP_ERR_MASK) >> PCIE_CO_ERR_CTR0_BAD_TLP_ERR_LSB)
#define PCIE_CO_ERR_CTR0_BAD_TLP_ERR_SET(x)                                    (((0 | (x)) << PCIE_CO_ERR_CTR0_BAD_TLP_ERR_LSB) & PCIE_CO_ERR_CTR0_BAD_TLP_ERR_MASK)
#define PCIE_CO_ERR_CTR0_BAD_TLP_ERR_RESET                                     0x0
#define PCIE_CO_ERR_CTR0_RCVD_ERR_LSB                                          0
#define PCIE_CO_ERR_CTR0_RCVD_ERR_MSB                                          7
#define PCIE_CO_ERR_CTR0_RCVD_ERR_MASK                                         0xff
#define PCIE_CO_ERR_CTR0_RCVD_ERR_GET(x)                                       (((x) & PCIE_CO_ERR_CTR0_RCVD_ERR_MASK) >> PCIE_CO_ERR_CTR0_RCVD_ERR_LSB)
#define PCIE_CO_ERR_CTR0_RCVD_ERR_SET(x)                                       (((0 | (x)) << PCIE_CO_ERR_CTR0_RCVD_ERR_LSB) & PCIE_CO_ERR_CTR0_RCVD_ERR_MASK)
#define PCIE_CO_ERR_CTR0_RCVD_ERR_RESET                                        0x0
#define PCIE_CO_ERR_CTR0_ADDRESS                                               (0x20 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_CO_ERR_CTR0_RSTMASK                                               0xffffff
#define PCIE_CO_ERR_CTR0_RESET                                                 0x0

// 0x24 (PCIE_CO_ERR_CTR1)
#define PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_LSB                                   8
#define PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_MSB                                   15
#define PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_MASK                                  0xff00
#define PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_GET(x)                                (((x) & PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_MASK) >> PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_LSB)
#define PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_SET(x)                                (((0 | (x)) << PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_LSB) & PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_MASK)
#define PCIE_CO_ERR_CTR1_RPLY_NUM_RO_ERR_RESET                                 0x0
#define PCIE_CO_ERR_CTR1_RPLY_TO_ERR_LSB                                       0
#define PCIE_CO_ERR_CTR1_RPLY_TO_ERR_MSB                                       7
#define PCIE_CO_ERR_CTR1_RPLY_TO_ERR_MASK                                      0xff
#define PCIE_CO_ERR_CTR1_RPLY_TO_ERR_GET(x)                                    (((x) & PCIE_CO_ERR_CTR1_RPLY_TO_ERR_MASK) >> PCIE_CO_ERR_CTR1_RPLY_TO_ERR_LSB)
#define PCIE_CO_ERR_CTR1_RPLY_TO_ERR_SET(x)                                    (((0 | (x)) << PCIE_CO_ERR_CTR1_RPLY_TO_ERR_LSB) & PCIE_CO_ERR_CTR1_RPLY_TO_ERR_MASK)
#define PCIE_CO_ERR_CTR1_RPLY_TO_ERR_RESET                                     0x0
#define PCIE_CO_ERR_CTR1_ADDRESS                                               (0x24 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_CO_ERR_CTR1_RSTMASK                                               0xffff
#define PCIE_CO_ERR_CTR1_RESET                                                 0x0

// 0x28 (PCIE_CO_ERR_CTR_CTRL)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_LSB                 9
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_MSB                 9
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_MASK                0x200
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_GET(x)              (((x) & PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_MASK) >> PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_LSB)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_SET(x)              (((0 | (x)) << PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_LSB) & PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_MASK)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_AUTO_STOP_RESET               0x0
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_LSB                       8
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_MSB                       8
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_MASK                      0x100
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_GET(x)                    (((x) & PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_MASK) >> PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_LSB)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_SET(x)                    (((0 | (x)) << PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_LSB) & PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_MASK)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_NUM_RO_ERR_CTR_RUN_RESET                     0x0
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_LSB                     7
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_MSB                     7
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_MASK                    0x80
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_GET(x)                  (((x) & PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_MASK) >> PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_LSB)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_SET(x)                  (((0 | (x)) << PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_LSB) & PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_MASK)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_AUTO_STOP_RESET                   0x0
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_LSB                           6
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_MSB                           6
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_MASK                          0x40
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_GET(x)                        (((x) & PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_MASK) >> PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_LSB)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_SET(x)                        (((0 | (x)) << PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_LSB) & PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_MASK)
#define PCIE_CO_ERR_CTR_CTRL_RPLY_TO_ERR_CTR_RUN_RESET                         0x0
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_LSB                    5
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_MSB                    5
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_MASK                   0x20
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_GET(x)                 (((x) & PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_MASK) >> PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_LSB)
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_SET(x)                 (((0 | (x)) << PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_LSB) & PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_MASK)
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_AUTO_STOP_RESET                  0x0
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_LSB                          4
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_MSB                          4
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_MASK                         0x10
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_GET(x)                       (((x) & PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_MASK) >> PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_LSB)
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_SET(x)                       (((0 | (x)) << PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_LSB) & PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_MASK)
#define PCIE_CO_ERR_CTR_CTRL_BAD_DLLP_ERR_CTR_RUN_RESET                        0x0
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_LSB                     3
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_MSB                     3
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_MASK                    0x8
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_GET(x)                  (((x) & PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_MASK) >> PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_LSB)
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_SET(x)                  (((0 | (x)) << PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_LSB) & PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_MASK)
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_AUTO_STOP_RESET                   0x0
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_LSB                           2
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_MSB                           2
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_MASK                          0x4
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_GET(x)                        (((x) & PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_MASK) >> PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_LSB)
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_SET(x)                        (((0 | (x)) << PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_LSB) & PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_MASK)
#define PCIE_CO_ERR_CTR_CTRL_BAD_TLP_ERR_CTR_RUN_RESET                         0x0
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_LSB                        1
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_MSB                        1
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_MASK                       0x2
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_GET(x)                     (((x) & PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_MASK) >> PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_LSB)
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_SET(x)                     (((0 | (x)) << PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_LSB) & PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_MASK)
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_AUTO_STOP_RESET                      0x0
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_LSB                              0
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_MSB                              0
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_MASK                             0x1
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_GET(x)                           (((x) & PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_MASK) >> PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_LSB)
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_SET(x)                           (((0 | (x)) << PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_LSB) & PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_MASK)
#define PCIE_CO_ERR_CTR_CTRL_RCVD_ERR_CTR_RUN_RESET                            0x0
#define PCIE_CO_ERR_CTR_CTRL_ADDRESS                                           (0x28 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_CO_ERR_CTR_CTRL_RSTMASK                                           0x3ff
#define PCIE_CO_ERR_CTR_CTRL_RESET                                             0x0

// 0x2c (PCIE_MISC_STATUS)
#define PCIE_MISC_STATUS_CFG_ASPM_L1_EN_LSB                                    11
#define PCIE_MISC_STATUS_CFG_ASPM_L1_EN_MSB                                    11
#define PCIE_MISC_STATUS_CFG_ASPM_L1_EN_MASK                                   0x800
#define PCIE_MISC_STATUS_CFG_ASPM_L1_EN_GET(x)                                 (((x) & PCIE_MISC_STATUS_CFG_ASPM_L1_EN_MASK) >> PCIE_MISC_STATUS_CFG_ASPM_L1_EN_LSB)
#define PCIE_MISC_STATUS_CFG_ASPM_L1_EN_SET(x)                                 (((0 | (x)) << PCIE_MISC_STATUS_CFG_ASPM_L1_EN_LSB) & PCIE_MISC_STATUS_CFG_ASPM_L1_EN_MASK)
#define PCIE_MISC_STATUS_CFG_ASPM_L1_EN_RESET                                  0x0
#define PCIE_MISC_STATUS_CFG_CLK_PM_EN_LSB                                     10
#define PCIE_MISC_STATUS_CFG_CLK_PM_EN_MSB                                     10
#define PCIE_MISC_STATUS_CFG_CLK_PM_EN_MASK                                    0x400
#define PCIE_MISC_STATUS_CFG_CLK_PM_EN_GET(x)                                  (((x) & PCIE_MISC_STATUS_CFG_CLK_PM_EN_MASK) >> PCIE_MISC_STATUS_CFG_CLK_PM_EN_LSB)
#define PCIE_MISC_STATUS_CFG_CLK_PM_EN_SET(x)                                  (((0 | (x)) << PCIE_MISC_STATUS_CFG_CLK_PM_EN_LSB) & PCIE_MISC_STATUS_CFG_CLK_PM_EN_MASK)
#define PCIE_MISC_STATUS_CFG_CLK_PM_EN_RESET                                   0x0
#define PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_LSB                                9
#define PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_MSB                                9
#define PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_MASK                               0x200
#define PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_GET(x)                             (((x) & PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_MASK) >> PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_LSB)
#define PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_SET(x)                             (((0 | (x)) << PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_LSB) & PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_MASK)
#define PCIE_MISC_STATUS_CFG_PM_NO_SOFT_RST_RESET                              0x0
#define PCIE_MISC_STATUS_CFG_RCB_LSB                                           8
#define PCIE_MISC_STATUS_CFG_RCB_MSB                                           8
#define PCIE_MISC_STATUS_CFG_RCB_MASK                                          0x100
#define PCIE_MISC_STATUS_CFG_RCB_GET(x)                                        (((x) & PCIE_MISC_STATUS_CFG_RCB_MASK) >> PCIE_MISC_STATUS_CFG_RCB_LSB)
#define PCIE_MISC_STATUS_CFG_RCB_SET(x)                                        (((0 | (x)) << PCIE_MISC_STATUS_CFG_RCB_LSB) & PCIE_MISC_STATUS_CFG_RCB_MASK)
#define PCIE_MISC_STATUS_CFG_RCB_RESET                                         0x0
#define PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_LSB                              5
#define PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_MSB                              7
#define PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_MASK                             0xe0
#define PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_GET(x)                           (((x) & PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_MASK) >> PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_LSB)
#define PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_SET(x)                           (((0 | (x)) << PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_LSB) & PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_MASK)
#define PCIE_MISC_STATUS_CFG_MAX_PAYLOAD_SIZE_RESET                            0x0
#define PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_LSB                               2
#define PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_MSB                               4
#define PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_MASK                              0x1c
#define PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_GET(x)                            (((x) & PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_MASK) >> PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_LSB)
#define PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_SET(x)                            (((0 | (x)) << PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_LSB) & PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_MASK)
#define PCIE_MISC_STATUS_CFG_MAX_RD_REQ_SIZE_RESET                             0x0
#define PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_LSB                                  1
#define PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_MSB                                  1
#define PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_MASK                                 0x2
#define PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_GET(x)                               (((x) & PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_MASK) >> PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_LSB)
#define PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_SET(x)                               (((0 | (x)) << PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_LSB) & PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_MASK)
#define PCIE_MISC_STATUS_CFG_MEM_SPACE_EN_RESET                                0x0
#define PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_LSB                                 0
#define PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_MSB                                 0
#define PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_MASK                                0x1
#define PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_GET(x)                              (((x) & PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_MASK) >> PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_LSB)
#define PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_SET(x)                              (((0 | (x)) << PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_LSB) & PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_MASK)
#define PCIE_MISC_STATUS_CFG_BUS_MASTER_EN_RESET                               0x0
#define PCIE_MISC_STATUS_ADDRESS                                               (0x2c + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_MISC_STATUS_RSTMASK                                               0xfff
#define PCIE_MISC_STATUS_RESET                                                 0x0

// 0x30 (PCIE_BAR0_START)
#define PCIE_BAR0_START_VAL_LSB                                                0
#define PCIE_BAR0_START_VAL_MSB                                                31
#define PCIE_BAR0_START_VAL_MASK                                               0xffffffff
#define PCIE_BAR0_START_VAL_GET(x)                                             (((x) & PCIE_BAR0_START_VAL_MASK) >> PCIE_BAR0_START_VAL_LSB)
#define PCIE_BAR0_START_VAL_SET(x)                                             (((0 | (x)) << PCIE_BAR0_START_VAL_LSB) & PCIE_BAR0_START_VAL_MASK)
#define PCIE_BAR0_START_VAL_RESET                                              0x0
#define PCIE_BAR0_START_ADDRESS                                                (0x30 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_BAR0_START_RSTMASK                                                0xffffffff
#define PCIE_BAR0_START_RESET                                                  0x0

// 0x34 (PCIE_BAR0_LIMIT)
#define PCIE_BAR0_LIMIT_VAL_LSB                                                0
#define PCIE_BAR0_LIMIT_VAL_MSB                                                31
#define PCIE_BAR0_LIMIT_VAL_MASK                                               0xffffffff
#define PCIE_BAR0_LIMIT_VAL_GET(x)                                             (((x) & PCIE_BAR0_LIMIT_VAL_MASK) >> PCIE_BAR0_LIMIT_VAL_LSB)
#define PCIE_BAR0_LIMIT_VAL_SET(x)                                             (((0 | (x)) << PCIE_BAR0_LIMIT_VAL_LSB) & PCIE_BAR0_LIMIT_VAL_MASK)
#define PCIE_BAR0_LIMIT_VAL_RESET                                              0x0
#define PCIE_BAR0_LIMIT_ADDRESS                                                (0x34 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_BAR0_LIMIT_RSTMASK                                                0xffffffff
#define PCIE_BAR0_LIMIT_RESET                                                  0x0

// 0x38 (AUTOCOMPL)
#define AUTOCOMPL_ENABLE_LSB                                                   0
#define AUTOCOMPL_ENABLE_MSB                                                   0
#define AUTOCOMPL_ENABLE_MASK                                                  0x1
#define AUTOCOMPL_ENABLE_GET(x)                                                (((x) & AUTOCOMPL_ENABLE_MASK) >> AUTOCOMPL_ENABLE_LSB)
#define AUTOCOMPL_ENABLE_SET(x)                                                (((0 | (x)) << AUTOCOMPL_ENABLE_LSB) & AUTOCOMPL_ENABLE_MASK)
#define AUTOCOMPL_ENABLE_RESET                                                 0x1
#define AUTOCOMPL_ADDRESS                                                      (0x38 + __SOC_PCIE_REG_BASE_ADDRESS)
#define AUTOCOMPL_RSTMASK                                                      0x1
#define AUTOCOMPL_RESET                                                        0x1

// 0x3c (NUM_READS_WR_PENDING)
#define NUM_READS_WR_PENDING_V_LSB                                             0
#define NUM_READS_WR_PENDING_V_MSB                                             4
#define NUM_READS_WR_PENDING_V_MASK                                            0x1f
#define NUM_READS_WR_PENDING_V_GET(x)                                          (((x) & NUM_READS_WR_PENDING_V_MASK) >> NUM_READS_WR_PENDING_V_LSB)
#define NUM_READS_WR_PENDING_V_SET(x)                                          (((0 | (x)) << NUM_READS_WR_PENDING_V_LSB) & NUM_READS_WR_PENDING_V_MASK)
#define NUM_READS_WR_PENDING_V_RESET                                           0x8
#define NUM_READS_WR_PENDING_ADDRESS                                           (0x3c + __SOC_PCIE_REG_BASE_ADDRESS)
#define NUM_READS_WR_PENDING_RSTMASK                                           0x1f
#define NUM_READS_WR_PENDING_RESET                                             0x8

// 0x40 (LOW_POWER_INT_ENABLE)
#define LOW_POWER_INT_ENABLE_DATA_LSB                                          0
#define LOW_POWER_INT_ENABLE_DATA_MSB                                          5
#define LOW_POWER_INT_ENABLE_DATA_MASK                                         0x3f
#define LOW_POWER_INT_ENABLE_DATA_GET(x)                                       (((x) & LOW_POWER_INT_ENABLE_DATA_MASK) >> LOW_POWER_INT_ENABLE_DATA_LSB)
#define LOW_POWER_INT_ENABLE_DATA_SET(x)                                       (((0 | (x)) << LOW_POWER_INT_ENABLE_DATA_LSB) & LOW_POWER_INT_ENABLE_DATA_MASK)
#define LOW_POWER_INT_ENABLE_DATA_RESET                                        0x0
#define LOW_POWER_INT_ENABLE_ADDRESS                                           (0x40 + __SOC_PCIE_REG_BASE_ADDRESS)
#define LOW_POWER_INT_ENABLE_RSTMASK                                           0x3f
#define LOW_POWER_INT_ENABLE_RESET                                             0x0

// 0x44 (LOW_POWER_INT_MASK)
#define LOW_POWER_INT_MASK_DATA_LSB                                            0
#define LOW_POWER_INT_MASK_DATA_MSB                                            5
#define LOW_POWER_INT_MASK_DATA_MASK                                           0x3f
#define LOW_POWER_INT_MASK_DATA_GET(x)                                         (((x) & LOW_POWER_INT_MASK_DATA_MASK) >> LOW_POWER_INT_MASK_DATA_LSB)
#define LOW_POWER_INT_MASK_DATA_SET(x)                                         (((0 | (x)) << LOW_POWER_INT_MASK_DATA_LSB) & LOW_POWER_INT_MASK_DATA_MASK)
#define LOW_POWER_INT_MASK_DATA_RESET                                          0x0
#define LOW_POWER_INT_MASK_ADDRESS                                             (0x44 + __SOC_PCIE_REG_BASE_ADDRESS)
#define LOW_POWER_INT_MASK_RSTMASK                                             0x3f
#define LOW_POWER_INT_MASK_RESET                                               0x0

// 0x48 (LOW_POWER_INT_STATUS)
#define LOW_POWER_INT_STATUS_DATA_LSB                                          0
#define LOW_POWER_INT_STATUS_DATA_MSB                                          5
#define LOW_POWER_INT_STATUS_DATA_MASK                                         0x3f
#define LOW_POWER_INT_STATUS_DATA_GET(x)                                       (((x) & LOW_POWER_INT_STATUS_DATA_MASK) >> LOW_POWER_INT_STATUS_DATA_LSB)
#define LOW_POWER_INT_STATUS_DATA_SET(x)                                       (((0 | (x)) << LOW_POWER_INT_STATUS_DATA_LSB) & LOW_POWER_INT_STATUS_DATA_MASK)
#define LOW_POWER_INT_STATUS_DATA_RESET                                        0x0
#define LOW_POWER_INT_STATUS_ADDRESS                                           (0x48 + __SOC_PCIE_REG_BASE_ADDRESS)
#define LOW_POWER_INT_STATUS_RSTMASK                                           0x3f
#define LOW_POWER_INT_STATUS_RESET                                             0x0

// 0x4c (LTR_CFG)
#define LTR_CFG_LTR_ENABLE_LSB                                                 31
#define LTR_CFG_LTR_ENABLE_MSB                                                 31
#define LTR_CFG_LTR_ENABLE_MASK                                                0x80000000
#define LTR_CFG_LTR_ENABLE_GET(x)                                              (((x) & LTR_CFG_LTR_ENABLE_MASK) >> LTR_CFG_LTR_ENABLE_LSB)
#define LTR_CFG_LTR_ENABLE_SET(x)                                              (((0 | (x)) << LTR_CFG_LTR_ENABLE_LSB) & LTR_CFG_LTR_ENABLE_MASK)
#define LTR_CFG_LTR_ENABLE_RESET                                               0x0
#define LTR_CFG_RESERVED_1_LSB                                                 29
#define LTR_CFG_RESERVED_1_MSB                                                 30
#define LTR_CFG_RESERVED_1_MASK                                                0x60000000
#define LTR_CFG_RESERVED_1_GET(x)                                              (((x) & LTR_CFG_RESERVED_1_MASK) >> LTR_CFG_RESERVED_1_LSB)
#define LTR_CFG_RESERVED_1_SET(x)                                              (((0 | (x)) << LTR_CFG_RESERVED_1_LSB) & LTR_CFG_RESERVED_1_MASK)
#define LTR_CFG_RESERVED_1_RESET                                               0x0
#define LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_LSB                                   26
#define LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_MSB                                   28
#define LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_MASK                                  0x1c000000
#define LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_GET(x)                                (((x) & LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_MASK) >> LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_LSB)
#define LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_SET(x)                                (((0 | (x)) << LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_LSB) & LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_MASK)
#define LTR_CFG_MAX_NSNOOP_LATENCY_SCALE_RESET                                 0x0
#define LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_LSB                                   16
#define LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_MSB                                   25
#define LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_MASK                                  0x3ff0000
#define LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_GET(x)                                (((x) & LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_MASK) >> LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_LSB)
#define LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_SET(x)                                (((0 | (x)) << LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_LSB) & LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_MASK)
#define LTR_CFG_MAX_NSNOOP_LATENCY_VALUE_RESET                                 0x0
#define LTR_CFG_RESERVED_0_LSB                                                 13
#define LTR_CFG_RESERVED_0_MSB                                                 15
#define LTR_CFG_RESERVED_0_MASK                                                0xe000
#define LTR_CFG_RESERVED_0_GET(x)                                              (((x) & LTR_CFG_RESERVED_0_MASK) >> LTR_CFG_RESERVED_0_LSB)
#define LTR_CFG_RESERVED_0_SET(x)                                              (((0 | (x)) << LTR_CFG_RESERVED_0_LSB) & LTR_CFG_RESERVED_0_MASK)
#define LTR_CFG_RESERVED_0_RESET                                               0x0
#define LTR_CFG_MAX_SNOOP_LATENCY_SCALE_LSB                                    10
#define LTR_CFG_MAX_SNOOP_LATENCY_SCALE_MSB                                    12
#define LTR_CFG_MAX_SNOOP_LATENCY_SCALE_MASK                                   0x1c00
#define LTR_CFG_MAX_SNOOP_LATENCY_SCALE_GET(x)                                 (((x) & LTR_CFG_MAX_SNOOP_LATENCY_SCALE_MASK) >> LTR_CFG_MAX_SNOOP_LATENCY_SCALE_LSB)
#define LTR_CFG_MAX_SNOOP_LATENCY_SCALE_SET(x)                                 (((0 | (x)) << LTR_CFG_MAX_SNOOP_LATENCY_SCALE_LSB) & LTR_CFG_MAX_SNOOP_LATENCY_SCALE_MASK)
#define LTR_CFG_MAX_SNOOP_LATENCY_SCALE_RESET                                  0x0
#define LTR_CFG_MAX_SNOOP_LATENCY_VALUE_LSB                                    0
#define LTR_CFG_MAX_SNOOP_LATENCY_VALUE_MSB                                    9
#define LTR_CFG_MAX_SNOOP_LATENCY_VALUE_MASK                                   0x3ff
#define LTR_CFG_MAX_SNOOP_LATENCY_VALUE_GET(x)                                 (((x) & LTR_CFG_MAX_SNOOP_LATENCY_VALUE_MASK) >> LTR_CFG_MAX_SNOOP_LATENCY_VALUE_LSB)
#define LTR_CFG_MAX_SNOOP_LATENCY_VALUE_SET(x)                                 (((0 | (x)) << LTR_CFG_MAX_SNOOP_LATENCY_VALUE_LSB) & LTR_CFG_MAX_SNOOP_LATENCY_VALUE_MASK)
#define LTR_CFG_MAX_SNOOP_LATENCY_VALUE_RESET                                  0x0
#define LTR_CFG_ADDRESS                                                        (0x4c + __SOC_PCIE_REG_BASE_ADDRESS)
#define LTR_CFG_RSTMASK                                                        0xffffffff
#define LTR_CFG_RESET                                                          0x0

// 0x50 (LTR_MSG)
#define LTR_MSG_V_LSB                                                          0
#define LTR_MSG_V_MSB                                                          31
#define LTR_MSG_V_MASK                                                         0xffffffff
#define LTR_MSG_V_GET(x)                                                       (((x) & LTR_MSG_V_MASK) >> LTR_MSG_V_LSB)
#define LTR_MSG_V_SET(x)                                                       (((0 | (x)) << LTR_MSG_V_LSB) & LTR_MSG_V_MASK)
#define LTR_MSG_V_RESET                                                        0x0
#define LTR_MSG_ADDRESS                                                        (0x50 + __SOC_PCIE_REG_BASE_ADDRESS)
#define LTR_MSG_RSTMASK                                                        0xffffffff
#define LTR_MSG_RESET                                                          0x0

// 0x54 (LTR_REQ)
#define LTR_REQ_REQ_LSB                                                        0
#define LTR_REQ_REQ_MSB                                                        0
#define LTR_REQ_REQ_MASK                                                       0x1
#define LTR_REQ_REQ_GET(x)                                                     (((x) & LTR_REQ_REQ_MASK) >> LTR_REQ_REQ_LSB)
#define LTR_REQ_REQ_SET(x)                                                     (((0 | (x)) << LTR_REQ_REQ_LSB) & LTR_REQ_REQ_MASK)
#define LTR_REQ_REQ_RESET                                                      0x0
#define LTR_REQ_ADDRESS                                                        (0x54 + __SOC_PCIE_REG_BASE_ADDRESS)
#define LTR_REQ_RSTMASK                                                        0x1
#define LTR_REQ_RESET                                                          0x0

// 0x58 (OBFF_STATUS)
#define OBFF_STATUS_OBFF_ENABLE_LSB                                            5
#define OBFF_STATUS_OBFF_ENABLE_MSB                                            6
#define OBFF_STATUS_OBFF_ENABLE_MASK                                           0x60
#define OBFF_STATUS_OBFF_ENABLE_GET(x)                                         (((x) & OBFF_STATUS_OBFF_ENABLE_MASK) >> OBFF_STATUS_OBFF_ENABLE_LSB)
#define OBFF_STATUS_OBFF_ENABLE_SET(x)                                         (((0 | (x)) << OBFF_STATUS_OBFF_ENABLE_LSB) & OBFF_STATUS_OBFF_ENABLE_MASK)
#define OBFF_STATUS_OBFF_ENABLE_RESET                                          0x0
#define OBFF_STATUS_VALID_LSB                                                  4
#define OBFF_STATUS_VALID_MSB                                                  4
#define OBFF_STATUS_VALID_MASK                                                 0x10
#define OBFF_STATUS_VALID_GET(x)                                               (((x) & OBFF_STATUS_VALID_MASK) >> OBFF_STATUS_VALID_LSB)
#define OBFF_STATUS_VALID_SET(x)                                               (((0 | (x)) << OBFF_STATUS_VALID_LSB) & OBFF_STATUS_VALID_MASK)
#define OBFF_STATUS_VALID_RESET                                                0x0
#define OBFF_STATUS_STATUS_LSB                                                 0
#define OBFF_STATUS_STATUS_MSB                                                 3
#define OBFF_STATUS_STATUS_MASK                                                0xf
#define OBFF_STATUS_STATUS_GET(x)                                              (((x) & OBFF_STATUS_STATUS_MASK) >> OBFF_STATUS_STATUS_LSB)
#define OBFF_STATUS_STATUS_SET(x)                                              (((0 | (x)) << OBFF_STATUS_STATUS_LSB) & OBFF_STATUS_STATUS_MASK)
#define OBFF_STATUS_STATUS_RESET                                               0x0
#define OBFF_STATUS_ADDRESS                                                    (0x58 + __SOC_PCIE_REG_BASE_ADDRESS)
#define OBFF_STATUS_RSTMASK                                                    0x7f
#define OBFF_STATUS_RESET                                                      0x0

// 0x5c (L1SS_OBS)
#define L1SS_OBS_L1SS_STATE_LSB                                                5
#define L1SS_OBS_L1SS_STATE_MSB                                                8
#define L1SS_OBS_L1SS_STATE_MASK                                               0x1e0
#define L1SS_OBS_L1SS_STATE_GET(x)                                             (((x) & L1SS_OBS_L1SS_STATE_MASK) >> L1SS_OBS_L1SS_STATE_LSB)
#define L1SS_OBS_L1SS_STATE_SET(x)                                             (((0 | (x)) << L1SS_OBS_L1SS_STATE_LSB) & L1SS_OBS_L1SS_STATE_MASK)
#define L1SS_OBS_L1SS_STATE_RESET                                              0x0
#define L1SS_OBS_PCLKREQ_N_LSB                                                 4
#define L1SS_OBS_PCLKREQ_N_MSB                                                 4
#define L1SS_OBS_PCLKREQ_N_MASK                                                0x10
#define L1SS_OBS_PCLKREQ_N_GET(x)                                              (((x) & L1SS_OBS_PCLKREQ_N_MASK) >> L1SS_OBS_PCLKREQ_N_LSB)
#define L1SS_OBS_PCLKREQ_N_SET(x)                                              (((0 | (x)) << L1SS_OBS_PCLKREQ_N_LSB) & L1SS_OBS_PCLKREQ_N_MASK)
#define L1SS_OBS_PCLKREQ_N_RESET                                               0x0
#define L1SS_OBS_CLKREQIN_LSB                                                  3
#define L1SS_OBS_CLKREQIN_MSB                                                  3
#define L1SS_OBS_CLKREQIN_MASK                                                 0x8
#define L1SS_OBS_CLKREQIN_GET(x)                                               (((x) & L1SS_OBS_CLKREQIN_MASK) >> L1SS_OBS_CLKREQIN_LSB)
#define L1SS_OBS_CLKREQIN_SET(x)                                               (((0 | (x)) << L1SS_OBS_CLKREQIN_LSB) & L1SS_OBS_CLKREQIN_MASK)
#define L1SS_OBS_CLKREQIN_RESET                                                0x0
#define L1SS_OBS_AUXCLKACTIVE_LSB                                              2
#define L1SS_OBS_AUXCLKACTIVE_MSB                                              2
#define L1SS_OBS_AUXCLKACTIVE_MASK                                             0x4
#define L1SS_OBS_AUXCLKACTIVE_GET(x)                                           (((x) & L1SS_OBS_AUXCLKACTIVE_MASK) >> L1SS_OBS_AUXCLKACTIVE_LSB)
#define L1SS_OBS_AUXCLKACTIVE_SET(x)                                           (((0 | (x)) << L1SS_OBS_AUXCLKACTIVE_LSB) & L1SS_OBS_AUXCLKACTIVE_MASK)
#define L1SS_OBS_AUXCLKACTIVE_RESET                                            0x0
#define L1SS_OBS_TXCMODE_DIS_LSB                                               1
#define L1SS_OBS_TXCMODE_DIS_MSB                                               1
#define L1SS_OBS_TXCMODE_DIS_MASK                                              0x2
#define L1SS_OBS_TXCMODE_DIS_GET(x)                                            (((x) & L1SS_OBS_TXCMODE_DIS_MASK) >> L1SS_OBS_TXCMODE_DIS_LSB)
#define L1SS_OBS_TXCMODE_DIS_SET(x)                                            (((0 | (x)) << L1SS_OBS_TXCMODE_DIS_LSB) & L1SS_OBS_TXCMODE_DIS_MASK)
#define L1SS_OBS_TXCMODE_DIS_RESET                                             0x0
#define L1SS_OBS_RXEIDLE_DIS_LSB                                               0
#define L1SS_OBS_RXEIDLE_DIS_MSB                                               0
#define L1SS_OBS_RXEIDLE_DIS_MASK                                              0x1
#define L1SS_OBS_RXEIDLE_DIS_GET(x)                                            (((x) & L1SS_OBS_RXEIDLE_DIS_MASK) >> L1SS_OBS_RXEIDLE_DIS_LSB)
#define L1SS_OBS_RXEIDLE_DIS_SET(x)                                            (((0 | (x)) << L1SS_OBS_RXEIDLE_DIS_LSB) & L1SS_OBS_RXEIDLE_DIS_MASK)
#define L1SS_OBS_RXEIDLE_DIS_RESET                                             0x0
#define L1SS_OBS_ADDRESS                                                       (0x5c + __SOC_PCIE_REG_BASE_ADDRESS)
#define L1SS_OBS_RSTMASK                                                       0x1ff
#define L1SS_OBS_RESET                                                         0x0

// 0x60 (L1SS_OVRD)
#define L1SS_OVRD_PCI_PM_L1_1_DISABLE_LSB                                      19
#define L1SS_OVRD_PCI_PM_L1_1_DISABLE_MSB                                      19
#define L1SS_OVRD_PCI_PM_L1_1_DISABLE_MASK                                     0x80000
#define L1SS_OVRD_PCI_PM_L1_1_DISABLE_GET(x)                                   (((x) & L1SS_OVRD_PCI_PM_L1_1_DISABLE_MASK) >> L1SS_OVRD_PCI_PM_L1_1_DISABLE_LSB)
#define L1SS_OVRD_PCI_PM_L1_1_DISABLE_SET(x)                                   (((0 | (x)) << L1SS_OVRD_PCI_PM_L1_1_DISABLE_LSB) & L1SS_OVRD_PCI_PM_L1_1_DISABLE_MASK)
#define L1SS_OVRD_PCI_PM_L1_1_DISABLE_RESET                                    0x0
#define L1SS_OVRD_ASPM_L1_1_DISABLE_LSB                                        18
#define L1SS_OVRD_ASPM_L1_1_DISABLE_MSB                                        18
#define L1SS_OVRD_ASPM_L1_1_DISABLE_MASK                                       0x40000
#define L1SS_OVRD_ASPM_L1_1_DISABLE_GET(x)                                     (((x) & L1SS_OVRD_ASPM_L1_1_DISABLE_MASK) >> L1SS_OVRD_ASPM_L1_1_DISABLE_LSB)
#define L1SS_OVRD_ASPM_L1_1_DISABLE_SET(x)                                     (((0 | (x)) << L1SS_OVRD_ASPM_L1_1_DISABLE_LSB) & L1SS_OVRD_ASPM_L1_1_DISABLE_MASK)
#define L1SS_OVRD_ASPM_L1_1_DISABLE_RESET                                      0x0
#define L1SS_OVRD_PCI_PM_L1_2_DISABLE_LSB                                      17
#define L1SS_OVRD_PCI_PM_L1_2_DISABLE_MSB                                      17
#define L1SS_OVRD_PCI_PM_L1_2_DISABLE_MASK                                     0x20000
#define L1SS_OVRD_PCI_PM_L1_2_DISABLE_GET(x)                                   (((x) & L1SS_OVRD_PCI_PM_L1_2_DISABLE_MASK) >> L1SS_OVRD_PCI_PM_L1_2_DISABLE_LSB)
#define L1SS_OVRD_PCI_PM_L1_2_DISABLE_SET(x)                                   (((0 | (x)) << L1SS_OVRD_PCI_PM_L1_2_DISABLE_LSB) & L1SS_OVRD_PCI_PM_L1_2_DISABLE_MASK)
#define L1SS_OVRD_PCI_PM_L1_2_DISABLE_RESET                                    0x0
#define L1SS_OVRD_ASPM_L1_2_DISABLE_LSB                                        16
#define L1SS_OVRD_ASPM_L1_2_DISABLE_MSB                                        16
#define L1SS_OVRD_ASPM_L1_2_DISABLE_MASK                                       0x10000
#define L1SS_OVRD_ASPM_L1_2_DISABLE_GET(x)                                     (((x) & L1SS_OVRD_ASPM_L1_2_DISABLE_MASK) >> L1SS_OVRD_ASPM_L1_2_DISABLE_LSB)
#define L1SS_OVRD_ASPM_L1_2_DISABLE_SET(x)                                     (((0 | (x)) << L1SS_OVRD_ASPM_L1_2_DISABLE_LSB) & L1SS_OVRD_ASPM_L1_2_DISABLE_MASK)
#define L1SS_OVRD_ASPM_L1_2_DISABLE_RESET                                      0x0
#define L1SS_OVRD_ENABLE_LSB                                                   8
#define L1SS_OVRD_ENABLE_MSB                                                   15
#define L1SS_OVRD_ENABLE_MASK                                                  0xff00
#define L1SS_OVRD_ENABLE_GET(x)                                                (((x) & L1SS_OVRD_ENABLE_MASK) >> L1SS_OVRD_ENABLE_LSB)
#define L1SS_OVRD_ENABLE_SET(x)                                                (((0 | (x)) << L1SS_OVRD_ENABLE_LSB) & L1SS_OVRD_ENABLE_MASK)
#define L1SS_OVRD_ENABLE_RESET                                                 0x0
#define L1SS_OVRD_VALUE_LSB                                                    0
#define L1SS_OVRD_VALUE_MSB                                                    7
#define L1SS_OVRD_VALUE_MASK                                                   0xff
#define L1SS_OVRD_VALUE_GET(x)                                                 (((x) & L1SS_OVRD_VALUE_MASK) >> L1SS_OVRD_VALUE_LSB)
#define L1SS_OVRD_VALUE_SET(x)                                                 (((0 | (x)) << L1SS_OVRD_VALUE_LSB) & L1SS_OVRD_VALUE_MASK)
#define L1SS_OVRD_VALUE_RESET                                                  0x0
#define L1SS_OVRD_ADDRESS                                                      (0x60 + __SOC_PCIE_REG_BASE_ADDRESS)
#define L1SS_OVRD_RSTMASK                                                      0xfffff
#define L1SS_OVRD_RESET                                                        0x0

// 0x70 (PCIE_SCRATCH_0)
#define PCIE_SCRATCH_0_VAL_LSB                                                 0
#define PCIE_SCRATCH_0_VAL_MSB                                                 31
#define PCIE_SCRATCH_0_VAL_MASK                                                0xffffffff
#define PCIE_SCRATCH_0_VAL_GET(x)                                              (((x) & PCIE_SCRATCH_0_VAL_MASK) >> PCIE_SCRATCH_0_VAL_LSB)
#define PCIE_SCRATCH_0_VAL_SET(x)                                              (((0 | (x)) << PCIE_SCRATCH_0_VAL_LSB) & PCIE_SCRATCH_0_VAL_MASK)
#define PCIE_SCRATCH_0_VAL_RESET                                               0x0
#define PCIE_SCRATCH_0_ADDRESS                                                 (0x70 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_SCRATCH_0_RSTMASK                                                 0xffffffff
#define PCIE_SCRATCH_0_RESET                                                   0x0

// 0x74 (PCIE_SCRATCH_1)
#define PCIE_SCRATCH_1_VAL_LSB                                                 0
#define PCIE_SCRATCH_1_VAL_MSB                                                 31
#define PCIE_SCRATCH_1_VAL_MASK                                                0xffffffff
#define PCIE_SCRATCH_1_VAL_GET(x)                                              (((x) & PCIE_SCRATCH_1_VAL_MASK) >> PCIE_SCRATCH_1_VAL_LSB)
#define PCIE_SCRATCH_1_VAL_SET(x)                                              (((0 | (x)) << PCIE_SCRATCH_1_VAL_LSB) & PCIE_SCRATCH_1_VAL_MASK)
#define PCIE_SCRATCH_1_VAL_RESET                                               0x40000000
#define PCIE_SCRATCH_1_ADDRESS                                                 (0x74 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_SCRATCH_1_RSTMASK                                                 0xffffffff
#define PCIE_SCRATCH_1_RESET                                                   0x40000000

// 0x78 (VMI_MSG_LOW)
#define VMI_MSG_LOW_DATA_LSB                                                   0
#define VMI_MSG_LOW_DATA_MSB                                                   31
#define VMI_MSG_LOW_DATA_MASK                                                  0xffffffff
#define VMI_MSG_LOW_DATA_GET(x)                                                (((x) & VMI_MSG_LOW_DATA_MASK) >> VMI_MSG_LOW_DATA_LSB)
#define VMI_MSG_LOW_DATA_SET(x)                                                (((0 | (x)) << VMI_MSG_LOW_DATA_LSB) & VMI_MSG_LOW_DATA_MASK)
#define VMI_MSG_LOW_DATA_RESET                                                 0x0
#define VMI_MSG_LOW_ADDRESS                                                    (0x78 + __SOC_PCIE_REG_BASE_ADDRESS)
#define VMI_MSG_LOW_RSTMASK                                                    0xffffffff
#define VMI_MSG_LOW_RESET                                                      0x0

// 0x7c (VMI_MSG_HIGH)
#define VMI_MSG_HIGH_DATA_LSB                                                  0
#define VMI_MSG_HIGH_DATA_MSB                                                  31
#define VMI_MSG_HIGH_DATA_MASK                                                 0xffffffff
#define VMI_MSG_HIGH_DATA_GET(x)                                               (((x) & VMI_MSG_HIGH_DATA_MASK) >> VMI_MSG_HIGH_DATA_LSB)
#define VMI_MSG_HIGH_DATA_SET(x)                                               (((0 | (x)) << VMI_MSG_HIGH_DATA_LSB) & VMI_MSG_HIGH_DATA_MASK)
#define VMI_MSG_HIGH_DATA_RESET                                                0x0
#define VMI_MSG_HIGH_ADDRESS                                                   (0x7c + __SOC_PCIE_REG_BASE_ADDRESS)
#define VMI_MSG_HIGH_RSTMASK                                                   0xffffffff
#define VMI_MSG_HIGH_RESET                                                     0x0

// 0x80 (VMI_MSG_MISC)
#define VMI_MSG_MISC_DATA_LSB                                                  0
#define VMI_MSG_MISC_DATA_MSB                                                  31
#define VMI_MSG_MISC_DATA_MASK                                                 0xffffffff
#define VMI_MSG_MISC_DATA_GET(x)                                               (((x) & VMI_MSG_MISC_DATA_MASK) >> VMI_MSG_MISC_DATA_LSB)
#define VMI_MSG_MISC_DATA_SET(x)                                               (((0 | (x)) << VMI_MSG_MISC_DATA_LSB) & VMI_MSG_MISC_DATA_MASK)
#define VMI_MSG_MISC_DATA_RESET                                                0x0
#define VMI_MSG_MISC_ADDRESS                                                   (0x80 + __SOC_PCIE_REG_BASE_ADDRESS)
#define VMI_MSG_MISC_RSTMASK                                                   0xffffffff
#define VMI_MSG_MISC_RESET                                                     0x0

// 0x84 (PCIE_DEBUG_EI)
#define PCIE_DEBUG_EI_CXPL_DEBUG_INFO_EI_LSB                                   0
#define PCIE_DEBUG_EI_CXPL_DEBUG_INFO_EI_MSB                                   31
#define PCIE_DEBUG_EI_CXPL_DEBUG_INFO_EI_MASK                                  0xffffffff
#define PCIE_DEBUG_EI_CXPL_DEBUG_INFO_EI_GET(x)                                (((x) & PCIE_DEBUG_EI_CXPL_DEBUG_INFO_EI_MASK) >> PCIE_DEBUG_EI_CXPL_DEBUG_INFO_EI_LSB)
#define PCIE_DEBUG_EI_CXPL_DEBUG_INFO_EI_SET(x)                                (((0 | (x)) << PCIE_DEBUG_EI_CXPL_DEBUG_INFO_EI_LSB) & PCIE_DEBUG_EI_CXPL_DEBUG_INFO_EI_MASK)
#define PCIE_DEBUG_EI_CXPL_DEBUG_INFO_EI_RESET                                 0x0
#define PCIE_DEBUG_EI_ADDRESS                                                  (0x84 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_DEBUG_EI_RSTMASK                                                  0xffffffff
#define PCIE_DEBUG_EI_RESET                                                    0x0

// 0x88 (PCIE_L1SS_CTRL_STATUS_0)
#define PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_SCALE_LSB                             29
#define PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_SCALE_MSB                             31
#define PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_SCALE_MASK                            0xe0000000
#define PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_SCALE_GET(x)                          (((x) & PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_SCALE_MASK) >> PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_SCALE_LSB)
#define PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_SCALE_SET(x)                          (((0 | (x)) << PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_SCALE_LSB) & PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_SCALE_MASK)
#define PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_SCALE_RESET                           0x0
#define PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_VALUE_LSB                             16
#define PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_VALUE_MSB                             25
#define PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_VALUE_MASK                            0x3ff0000
#define PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_VALUE_GET(x)                          (((x) & PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_VALUE_MASK) >> PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_VALUE_LSB)
#define PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_VALUE_SET(x)                          (((0 | (x)) << PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_VALUE_LSB) & PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_VALUE_MASK)
#define PCIE_L1SS_CTRL_STATUS_0_L1_2_THR_VALUE_RESET                           0x0
#define PCIE_L1SS_CTRL_STATUS_0_COMMON_MODE_RESTORE_TIME_LSB                   8
#define PCIE_L1SS_CTRL_STATUS_0_COMMON_MODE_RESTORE_TIME_MSB                   15
#define PCIE_L1SS_CTRL_STATUS_0_COMMON_MODE_RESTORE_TIME_MASK                  0xff00
#define PCIE_L1SS_CTRL_STATUS_0_COMMON_MODE_RESTORE_TIME_GET(x)                (((x) & PCIE_L1SS_CTRL_STATUS_0_COMMON_MODE_RESTORE_TIME_MASK) >> PCIE_L1SS_CTRL_STATUS_0_COMMON_MODE_RESTORE_TIME_LSB)
#define PCIE_L1SS_CTRL_STATUS_0_COMMON_MODE_RESTORE_TIME_SET(x)                (((0 | (x)) << PCIE_L1SS_CTRL_STATUS_0_COMMON_MODE_RESTORE_TIME_LSB) & PCIE_L1SS_CTRL_STATUS_0_COMMON_MODE_RESTORE_TIME_MASK)
#define PCIE_L1SS_CTRL_STATUS_0_COMMON_MODE_RESTORE_TIME_RESET                 0x0
#define PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_VALUE_LSB                           3
#define PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_VALUE_MSB                           7
#define PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_VALUE_MASK                          0xf8
#define PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_VALUE_GET(x)                        (((x) & PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_VALUE_MASK) >> PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_VALUE_LSB)
#define PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_VALUE_SET(x)                        (((0 | (x)) << PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_VALUE_LSB) & PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_VALUE_MASK)
#define PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_VALUE_RESET                         0x0
#define PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_SCALE_LSB                           0
#define PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_SCALE_MSB                           1
#define PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_SCALE_MASK                          0x3
#define PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_SCALE_GET(x)                        (((x) & PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_SCALE_MASK) >> PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_SCALE_LSB)
#define PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_SCALE_SET(x)                        (((0 | (x)) << PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_SCALE_LSB) & PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_SCALE_MASK)
#define PCIE_L1SS_CTRL_STATUS_0_T_POWER_ON_SCALE_RESET                         0x0
#define PCIE_L1SS_CTRL_STATUS_0_ADDRESS                                        (0x88 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_L1SS_CTRL_STATUS_0_RSTMASK                                        0xe3fffffb
#define PCIE_L1SS_CTRL_STATUS_0_RESET                                          0x0

// 0x8c (PCIE_L1SS_CTRL_STATUS_1)
#define PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_VALUE_LSB                           19
#define PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_VALUE_MSB                           23
#define PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_VALUE_MASK                          0xf80000
#define PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_VALUE_GET(x)                        (((x) & PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_VALUE_MASK) >> PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_VALUE_LSB)
#define PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_VALUE_SET(x)                        (((0 | (x)) << PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_VALUE_LSB) & PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_VALUE_MASK)
#define PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_VALUE_RESET                         0x0
#define PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_SCALE_LSB                           16
#define PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_SCALE_MSB                           17
#define PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_SCALE_MASK                          0x30000
#define PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_SCALE_GET(x)                        (((x) & PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_SCALE_MASK) >> PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_SCALE_LSB)
#define PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_SCALE_SET(x)                        (((0 | (x)) << PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_SCALE_LSB) & PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_SCALE_MASK)
#define PCIE_L1SS_CTRL_STATUS_1_T_POWER_ON_SCALE_RESET                         0x0
#define PCIE_L1SS_CTRL_STATUS_1_COMMON_MODE_RESTORE_TIME_LSB                   8
#define PCIE_L1SS_CTRL_STATUS_1_COMMON_MODE_RESTORE_TIME_MSB                   15
#define PCIE_L1SS_CTRL_STATUS_1_COMMON_MODE_RESTORE_TIME_MASK                  0xff00
#define PCIE_L1SS_CTRL_STATUS_1_COMMON_MODE_RESTORE_TIME_GET(x)                (((x) & PCIE_L1SS_CTRL_STATUS_1_COMMON_MODE_RESTORE_TIME_MASK) >> PCIE_L1SS_CTRL_STATUS_1_COMMON_MODE_RESTORE_TIME_LSB)
#define PCIE_L1SS_CTRL_STATUS_1_COMMON_MODE_RESTORE_TIME_SET(x)                (((0 | (x)) << PCIE_L1SS_CTRL_STATUS_1_COMMON_MODE_RESTORE_TIME_LSB) & PCIE_L1SS_CTRL_STATUS_1_COMMON_MODE_RESTORE_TIME_MASK)
#define PCIE_L1SS_CTRL_STATUS_1_COMMON_MODE_RESTORE_TIME_RESET                 0x0
#define PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_1_ENABLE_LSB                           3
#define PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_1_ENABLE_MSB                           3
#define PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_1_ENABLE_MASK                          0x8
#define PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_1_ENABLE_GET(x)                        (((x) & PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_1_ENABLE_MASK) >> PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_1_ENABLE_LSB)
#define PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_1_ENABLE_SET(x)                        (((0 | (x)) << PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_1_ENABLE_LSB) & PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_1_ENABLE_MASK)
#define PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_1_ENABLE_RESET                         0x0
#define PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_2_ENABLE_LSB                           2
#define PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_2_ENABLE_MSB                           2
#define PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_2_ENABLE_MASK                          0x4
#define PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_2_ENABLE_GET(x)                        (((x) & PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_2_ENABLE_MASK) >> PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_2_ENABLE_LSB)
#define PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_2_ENABLE_SET(x)                        (((0 | (x)) << PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_2_ENABLE_LSB) & PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_2_ENABLE_MASK)
#define PCIE_L1SS_CTRL_STATUS_1_ASPM_L1_2_ENABLE_RESET                         0x0
#define PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_1_ENABLE_LSB                         1
#define PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_1_ENABLE_MSB                         1
#define PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_1_ENABLE_MASK                        0x2
#define PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_1_ENABLE_GET(x)                      (((x) & PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_1_ENABLE_MASK) >> PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_1_ENABLE_LSB)
#define PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_1_ENABLE_SET(x)                      (((0 | (x)) << PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_1_ENABLE_LSB) & PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_1_ENABLE_MASK)
#define PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_1_ENABLE_RESET                       0x0
#define PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_2_ENABLE_LSB                         0
#define PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_2_ENABLE_MSB                         0
#define PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_2_ENABLE_MASK                        0x1
#define PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_2_ENABLE_GET(x)                      (((x) & PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_2_ENABLE_MASK) >> PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_2_ENABLE_LSB)
#define PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_2_ENABLE_SET(x)                      (((0 | (x)) << PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_2_ENABLE_LSB) & PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_2_ENABLE_MASK)
#define PCIE_L1SS_CTRL_STATUS_1_PCI_PM_L1_2_ENABLE_RESET                       0x0
#define PCIE_L1SS_CTRL_STATUS_1_ADDRESS                                        (0x8c + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_L1SS_CTRL_STATUS_1_RSTMASK                                        0xfbff0f
#define PCIE_L1SS_CTRL_STATUS_1_RESET                                          0x0

// 0x90 (PCIE_UNCORRECTABLE_ERROR_INT_ENABLE)
#define PCIE_UNCORRECTABLE_ERROR_INT_ENABLE_DATA_LSB                           0
#define PCIE_UNCORRECTABLE_ERROR_INT_ENABLE_DATA_MSB                           31
#define PCIE_UNCORRECTABLE_ERROR_INT_ENABLE_DATA_MASK                          0xffffffff
#define PCIE_UNCORRECTABLE_ERROR_INT_ENABLE_DATA_GET(x)                        (((x) & PCIE_UNCORRECTABLE_ERROR_INT_ENABLE_DATA_MASK) >> PCIE_UNCORRECTABLE_ERROR_INT_ENABLE_DATA_LSB)
#define PCIE_UNCORRECTABLE_ERROR_INT_ENABLE_DATA_SET(x)                        (((0 | (x)) << PCIE_UNCORRECTABLE_ERROR_INT_ENABLE_DATA_LSB) & PCIE_UNCORRECTABLE_ERROR_INT_ENABLE_DATA_MASK)
#define PCIE_UNCORRECTABLE_ERROR_INT_ENABLE_DATA_RESET                         0x0
#define PCIE_UNCORRECTABLE_ERROR_INT_ENABLE_ADDRESS                            (0x90 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_UNCORRECTABLE_ERROR_INT_ENABLE_RSTMASK                            0xffffffff
#define PCIE_UNCORRECTABLE_ERROR_INT_ENABLE_RESET                              0x0

// 0x94 (PCIE_UNCORRECTABLE_ERROR_INT_MASK)
#define PCIE_UNCORRECTABLE_ERROR_INT_MASK_DATA_LSB                             0
#define PCIE_UNCORRECTABLE_ERROR_INT_MASK_DATA_MSB                             31
#define PCIE_UNCORRECTABLE_ERROR_INT_MASK_DATA_MASK                            0xffffffff
#define PCIE_UNCORRECTABLE_ERROR_INT_MASK_DATA_GET(x)                          (((x) & PCIE_UNCORRECTABLE_ERROR_INT_MASK_DATA_MASK) >> PCIE_UNCORRECTABLE_ERROR_INT_MASK_DATA_LSB)
#define PCIE_UNCORRECTABLE_ERROR_INT_MASK_DATA_SET(x)                          (((0 | (x)) << PCIE_UNCORRECTABLE_ERROR_INT_MASK_DATA_LSB) & PCIE_UNCORRECTABLE_ERROR_INT_MASK_DATA_MASK)
#define PCIE_UNCORRECTABLE_ERROR_INT_MASK_DATA_RESET                           0x0
#define PCIE_UNCORRECTABLE_ERROR_INT_MASK_ADDRESS                              (0x94 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_UNCORRECTABLE_ERROR_INT_MASK_RSTMASK                              0xffffffff
#define PCIE_UNCORRECTABLE_ERROR_INT_MASK_RESET                                0x0

// 0x98 (PCIE_UNCORRECTABLE_ERROR_INT_STATUS)
#define PCIE_UNCORRECTABLE_ERROR_INT_STATUS_DATA_LSB                           0
#define PCIE_UNCORRECTABLE_ERROR_INT_STATUS_DATA_MSB                           31
#define PCIE_UNCORRECTABLE_ERROR_INT_STATUS_DATA_MASK                          0xffffffff
#define PCIE_UNCORRECTABLE_ERROR_INT_STATUS_DATA_GET(x)                        (((x) & PCIE_UNCORRECTABLE_ERROR_INT_STATUS_DATA_MASK) >> PCIE_UNCORRECTABLE_ERROR_INT_STATUS_DATA_LSB)
#define PCIE_UNCORRECTABLE_ERROR_INT_STATUS_DATA_SET(x)                        (((0 | (x)) << PCIE_UNCORRECTABLE_ERROR_INT_STATUS_DATA_LSB) & PCIE_UNCORRECTABLE_ERROR_INT_STATUS_DATA_MASK)
#define PCIE_UNCORRECTABLE_ERROR_INT_STATUS_DATA_RESET                         0x0
#define PCIE_UNCORRECTABLE_ERROR_INT_STATUS_ADDRESS                            (0x98 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_UNCORRECTABLE_ERROR_INT_STATUS_RSTMASK                            0xffffffff
#define PCIE_UNCORRECTABLE_ERROR_INT_STATUS_RESET                              0x0

// 0x9c (PCIE_RX_NFTS_PATCH)
#define PCIE_RX_NFTS_PATCH_EN_LSB                                              31
#define PCIE_RX_NFTS_PATCH_EN_MSB                                              31
#define PCIE_RX_NFTS_PATCH_EN_MASK                                             0x80000000
#define PCIE_RX_NFTS_PATCH_EN_GET(x)                                           (((x) & PCIE_RX_NFTS_PATCH_EN_MASK) >> PCIE_RX_NFTS_PATCH_EN_LSB)
#define PCIE_RX_NFTS_PATCH_EN_SET(x)                                           (((0 | (x)) << PCIE_RX_NFTS_PATCH_EN_LSB) & PCIE_RX_NFTS_PATCH_EN_MASK)
#define PCIE_RX_NFTS_PATCH_EN_RESET                                            0x0
#define PCIE_RX_NFTS_PATCH_VAL_LSB                                             0
#define PCIE_RX_NFTS_PATCH_VAL_MSB                                             7
#define PCIE_RX_NFTS_PATCH_VAL_MASK                                            0xff
#define PCIE_RX_NFTS_PATCH_VAL_GET(x)                                          (((x) & PCIE_RX_NFTS_PATCH_VAL_MASK) >> PCIE_RX_NFTS_PATCH_VAL_LSB)
#define PCIE_RX_NFTS_PATCH_VAL_SET(x)                                          (((0 | (x)) << PCIE_RX_NFTS_PATCH_VAL_LSB) & PCIE_RX_NFTS_PATCH_VAL_MASK)
#define PCIE_RX_NFTS_PATCH_VAL_RESET                                           0x3f
#define PCIE_RX_NFTS_PATCH_ADDRESS                                             (0x9c + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_RX_NFTS_PATCH_RSTMASK                                             0x800000ff
#define PCIE_RX_NFTS_PATCH_RESET                                               0x3f

// 0xa0 (PCIE_RX_NFTS_TMO)
#define PCIE_RX_NFTS_TMO_CLR_LSB                                               31
#define PCIE_RX_NFTS_TMO_CLR_MSB                                               31
#define PCIE_RX_NFTS_TMO_CLR_MASK                                              0x80000000
#define PCIE_RX_NFTS_TMO_CLR_GET(x)                                            (((x) & PCIE_RX_NFTS_TMO_CLR_MASK) >> PCIE_RX_NFTS_TMO_CLR_LSB)
#define PCIE_RX_NFTS_TMO_CLR_SET(x)                                            (((0 | (x)) << PCIE_RX_NFTS_TMO_CLR_LSB) & PCIE_RX_NFTS_TMO_CLR_MASK)
#define PCIE_RX_NFTS_TMO_CLR_RESET                                             0x0
#define PCIE_RX_NFTS_TMO_CNT_LSB                                               0
#define PCIE_RX_NFTS_TMO_CNT_MSB                                               15
#define PCIE_RX_NFTS_TMO_CNT_MASK                                              0xffff
#define PCIE_RX_NFTS_TMO_CNT_GET(x)                                            (((x) & PCIE_RX_NFTS_TMO_CNT_MASK) >> PCIE_RX_NFTS_TMO_CNT_LSB)
#define PCIE_RX_NFTS_TMO_CNT_SET(x)                                            (((0 | (x)) << PCIE_RX_NFTS_TMO_CNT_LSB) & PCIE_RX_NFTS_TMO_CNT_MASK)
#define PCIE_RX_NFTS_TMO_CNT_RESET                                             0x0
#define PCIE_RX_NFTS_TMO_ADDRESS                                               (0xa0 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_RX_NFTS_TMO_RSTMASK                                               0x8000ffff
#define PCIE_RX_NFTS_TMO_RESET                                                 0x0

// 0xa4 (LTR_LATENCY)
#define LTR_LATENCY_DATA_LSB                                                   0
#define LTR_LATENCY_DATA_MSB                                                   31
#define LTR_LATENCY_DATA_MASK                                                  0xffffffff
#define LTR_LATENCY_DATA_GET(x)                                                (((x) & LTR_LATENCY_DATA_MASK) >> LTR_LATENCY_DATA_LSB)
#define LTR_LATENCY_DATA_SET(x)                                                (((0 | (x)) << LTR_LATENCY_DATA_LSB) & LTR_LATENCY_DATA_MASK)
#define LTR_LATENCY_DATA_RESET                                                 0x0
#define LTR_LATENCY_ADDRESS                                                    (0xa4 + __SOC_PCIE_REG_BASE_ADDRESS)
#define LTR_LATENCY_RSTMASK                                                    0xffffffff
#define LTR_LATENCY_RESET                                                      0x0

// 0xa8 (STATISTIC_CTRL)
#define STATISTIC_CTRL_CLEAR_LSB                                               1
#define STATISTIC_CTRL_CLEAR_MSB                                               1
#define STATISTIC_CTRL_CLEAR_MASK                                              0x2
#define STATISTIC_CTRL_CLEAR_GET(x)                                            (((x) & STATISTIC_CTRL_CLEAR_MASK) >> STATISTIC_CTRL_CLEAR_LSB)
#define STATISTIC_CTRL_CLEAR_SET(x)                                            (((0 | (x)) << STATISTIC_CTRL_CLEAR_LSB) & STATISTIC_CTRL_CLEAR_MASK)
#define STATISTIC_CTRL_CLEAR_RESET                                             0x0
#define STATISTIC_CTRL_ENABLE_LSB                                              0
#define STATISTIC_CTRL_ENABLE_MSB                                              0
#define STATISTIC_CTRL_ENABLE_MASK                                             0x1
#define STATISTIC_CTRL_ENABLE_GET(x)                                           (((x) & STATISTIC_CTRL_ENABLE_MASK) >> STATISTIC_CTRL_ENABLE_LSB)
#define STATISTIC_CTRL_ENABLE_SET(x)                                           (((0 | (x)) << STATISTIC_CTRL_ENABLE_LSB) & STATISTIC_CTRL_ENABLE_MASK)
#define STATISTIC_CTRL_ENABLE_RESET                                            0x0
#define STATISTIC_CTRL_ADDRESS                                                 (0xa8 + __SOC_PCIE_REG_BASE_ADDRESS)
#define STATISTIC_CTRL_RSTMASK                                                 0x3
#define STATISTIC_CTRL_RESET                                                   0x0

// 0xac (STATISTIC_PERIOD_CNT)
#define STATISTIC_PERIOD_CNT_CNT_LSB                                           0
#define STATISTIC_PERIOD_CNT_CNT_MSB                                           31
#define STATISTIC_PERIOD_CNT_CNT_MASK                                          0xffffffff
#define STATISTIC_PERIOD_CNT_CNT_GET(x)                                        (((x) & STATISTIC_PERIOD_CNT_CNT_MASK) >> STATISTIC_PERIOD_CNT_CNT_LSB)
#define STATISTIC_PERIOD_CNT_CNT_SET(x)                                        (((0 | (x)) << STATISTIC_PERIOD_CNT_CNT_LSB) & STATISTIC_PERIOD_CNT_CNT_MASK)
#define STATISTIC_PERIOD_CNT_CNT_RESET                                         0x0
#define STATISTIC_PERIOD_CNT_ADDRESS                                           (0xac + __SOC_PCIE_REG_BASE_ADDRESS)
#define STATISTIC_PERIOD_CNT_RSTMASK                                           0xffffffff
#define STATISTIC_PERIOD_CNT_RESET                                             0x0

// 0xb0 (L1_TIME_CNT)
#define L1_TIME_CNT_CNT_LSB                                                    0
#define L1_TIME_CNT_CNT_MSB                                                    31
#define L1_TIME_CNT_CNT_MASK                                                   0xffffffff
#define L1_TIME_CNT_CNT_GET(x)                                                 (((x) & L1_TIME_CNT_CNT_MASK) >> L1_TIME_CNT_CNT_LSB)
#define L1_TIME_CNT_CNT_SET(x)                                                 (((0 | (x)) << L1_TIME_CNT_CNT_LSB) & L1_TIME_CNT_CNT_MASK)
#define L1_TIME_CNT_CNT_RESET                                                  0x0
#define L1_TIME_CNT_ADDRESS                                                    (0xb0 + __SOC_PCIE_REG_BASE_ADDRESS)
#define L1_TIME_CNT_RSTMASK                                                    0xffffffff
#define L1_TIME_CNT_RESET                                                      0x0

// 0xb4 (L1_1_TIME_CNT)
#define L1_1_TIME_CNT_CNT_LSB                                                  0
#define L1_1_TIME_CNT_CNT_MSB                                                  31
#define L1_1_TIME_CNT_CNT_MASK                                                 0xffffffff
#define L1_1_TIME_CNT_CNT_GET(x)                                               (((x) & L1_1_TIME_CNT_CNT_MASK) >> L1_1_TIME_CNT_CNT_LSB)
#define L1_1_TIME_CNT_CNT_SET(x)                                               (((0 | (x)) << L1_1_TIME_CNT_CNT_LSB) & L1_1_TIME_CNT_CNT_MASK)
#define L1_1_TIME_CNT_CNT_RESET                                                0x0
#define L1_1_TIME_CNT_ADDRESS                                                  (0xb4 + __SOC_PCIE_REG_BASE_ADDRESS)
#define L1_1_TIME_CNT_RSTMASK                                                  0xffffffff
#define L1_1_TIME_CNT_RESET                                                    0x0

// 0xb8 (L1_2_TIME_CNT)
#define L1_2_TIME_CNT_CNT_LSB                                                  0
#define L1_2_TIME_CNT_CNT_MSB                                                  31
#define L1_2_TIME_CNT_CNT_MASK                                                 0xffffffff
#define L1_2_TIME_CNT_CNT_GET(x)                                               (((x) & L1_2_TIME_CNT_CNT_MASK) >> L1_2_TIME_CNT_CNT_LSB)
#define L1_2_TIME_CNT_CNT_SET(x)                                               (((0 | (x)) << L1_2_TIME_CNT_CNT_LSB) & L1_2_TIME_CNT_CNT_MASK)
#define L1_2_TIME_CNT_CNT_RESET                                                0x0
#define L1_2_TIME_CNT_ADDRESS                                                  (0xb8 + __SOC_PCIE_REG_BASE_ADDRESS)
#define L1_2_TIME_CNT_RSTMASK                                                  0xffffffff
#define L1_2_TIME_CNT_RESET                                                    0x0

// 0xbc (MSI_MAGIC)
#define MSI_MAGIC_EN_LSB                                                       31
#define MSI_MAGIC_EN_MSB                                                       31
#define MSI_MAGIC_EN_MASK                                                      0x80000000
#define MSI_MAGIC_EN_GET(x)                                                    (((x) & MSI_MAGIC_EN_MASK) >> MSI_MAGIC_EN_LSB)
#define MSI_MAGIC_EN_SET(x)                                                    (((0 | (x)) << MSI_MAGIC_EN_LSB) & MSI_MAGIC_EN_MASK)
#define MSI_MAGIC_EN_RESET                                                     0x0
#define MSI_MAGIC_RDY_LSB                                                      0
#define MSI_MAGIC_RDY_MSB                                                      0
#define MSI_MAGIC_RDY_MASK                                                     0x1
#define MSI_MAGIC_RDY_GET(x)                                                   (((x) & MSI_MAGIC_RDY_MASK) >> MSI_MAGIC_RDY_LSB)
#define MSI_MAGIC_RDY_SET(x)                                                   (((0 | (x)) << MSI_MAGIC_RDY_LSB) & MSI_MAGIC_RDY_MASK)
#define MSI_MAGIC_RDY_RESET                                                    0x0
#define MSI_MAGIC_ADDRESS                                                      (0xbc + __SOC_PCIE_REG_BASE_ADDRESS)
#define MSI_MAGIC_RSTMASK                                                      0x80000001
#define MSI_MAGIC_RESET                                                        0x0

// 0xc0 (MSI_MAGIC_ADR)
#define MSI_MAGIC_ADR_VAL_LSB                                                  0
#define MSI_MAGIC_ADR_VAL_MSB                                                  31
#define MSI_MAGIC_ADR_VAL_MASK                                                 0xffffffff
#define MSI_MAGIC_ADR_VAL_GET(x)                                               (((x) & MSI_MAGIC_ADR_VAL_MASK) >> MSI_MAGIC_ADR_VAL_LSB)
#define MSI_MAGIC_ADR_VAL_SET(x)                                               (((0 | (x)) << MSI_MAGIC_ADR_VAL_LSB) & MSI_MAGIC_ADR_VAL_MASK)
#define MSI_MAGIC_ADR_VAL_RESET                                                0x0
#define MSI_MAGIC_ADR_ADDRESS                                                  (0xc0 + __SOC_PCIE_REG_BASE_ADDRESS)
#define MSI_MAGIC_ADR_RSTMASK                                                  0xffffffff
#define MSI_MAGIC_ADR_RESET                                                    0x0

// 0xc4 (PCIE_AXI_BRIDGE_CTRL_CLIENT)
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_ATTR_LSB                               3
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_ATTR_MSB                               4
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_ATTR_MASK                              0x18
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_ATTR_GET(x)                            (((x) & PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_ATTR_MASK) >> PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_ATTR_LSB)
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_ATTR_SET(x)                            (((0 | (x)) << PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_ATTR_LSB) & PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_ATTR_MASK)
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_ATTR_RESET                             0x0
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_TC_LSB                                 0
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_TC_MSB                                 2
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_TC_MASK                                0x7
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_TC_GET(x)                              (((x) & PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_TC_MASK) >> PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_TC_LSB)
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_TC_SET(x)                              (((0 | (x)) << PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_TC_LSB) & PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_TC_MASK)
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_TLP_TC_RESET                               0x0
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_ADDRESS                                    (0xc4 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_RSTMASK                                    0x1f
#define PCIE_AXI_BRIDGE_CTRL_CLIENT_RESET                                      0x0

// 0xc8 (SOC_RDY_STATUS)
#define SOC_RDY_STATUS_VAL_LSB                                                 1
#define SOC_RDY_STATUS_VAL_MSB                                                 31
#define SOC_RDY_STATUS_VAL_MASK                                                0xfffffffe
#define SOC_RDY_STATUS_VAL_GET(x)                                              (((x) & SOC_RDY_STATUS_VAL_MASK) >> SOC_RDY_STATUS_VAL_LSB)
#define SOC_RDY_STATUS_VAL_SET(x)                                              (((0 | (x)) << SOC_RDY_STATUS_VAL_LSB) & SOC_RDY_STATUS_VAL_MASK)
#define SOC_RDY_STATUS_VAL_RESET                                               0x0
#define SOC_RDY_STATUS_BAR_LSB                                                 0
#define SOC_RDY_STATUS_BAR_MSB                                                 0
#define SOC_RDY_STATUS_BAR_MASK                                                0x1
#define SOC_RDY_STATUS_BAR_GET(x)                                              (((x) & SOC_RDY_STATUS_BAR_MASK) >> SOC_RDY_STATUS_BAR_LSB)
#define SOC_RDY_STATUS_BAR_SET(x)                                              (((0 | (x)) << SOC_RDY_STATUS_BAR_LSB) & SOC_RDY_STATUS_BAR_MASK)
#define SOC_RDY_STATUS_BAR_RESET                                               0x0
#define SOC_RDY_STATUS_ADDRESS                                                 (0xc8 + __SOC_PCIE_REG_BASE_ADDRESS)
#define SOC_RDY_STATUS_RSTMASK                                                 0xffffffff
#define SOC_RDY_STATUS_RESET                                                   0x0

// 0xcc (PCIE_MISC_CTRL)
#define PCIE_MISC_CTRL_STAR_569307_LSB                                         4
#define PCIE_MISC_CTRL_STAR_569307_MSB                                         4
#define PCIE_MISC_CTRL_STAR_569307_MASK                                        0x10
#define PCIE_MISC_CTRL_STAR_569307_GET(x)                                      (((x) & PCIE_MISC_CTRL_STAR_569307_MASK) >> PCIE_MISC_CTRL_STAR_569307_LSB)
#define PCIE_MISC_CTRL_STAR_569307_SET(x)                                      (((0 | (x)) << PCIE_MISC_CTRL_STAR_569307_LSB) & PCIE_MISC_CTRL_STAR_569307_MASK)
#define PCIE_MISC_CTRL_STAR_569307_RESET                                       0x0
#define PCIE_MISC_CTRL_STAR_494311_LSB                                         3
#define PCIE_MISC_CTRL_STAR_494311_MSB                                         3
#define PCIE_MISC_CTRL_STAR_494311_MASK                                        0x8
#define PCIE_MISC_CTRL_STAR_494311_GET(x)                                      (((x) & PCIE_MISC_CTRL_STAR_494311_MASK) >> PCIE_MISC_CTRL_STAR_494311_LSB)
#define PCIE_MISC_CTRL_STAR_494311_SET(x)                                      (((0 | (x)) << PCIE_MISC_CTRL_STAR_494311_LSB) & PCIE_MISC_CTRL_STAR_494311_MASK)
#define PCIE_MISC_CTRL_STAR_494311_RESET                                       0x0
#define PCIE_MISC_CTRL_STAR_471173_LSB                                         2
#define PCIE_MISC_CTRL_STAR_471173_MSB                                         2
#define PCIE_MISC_CTRL_STAR_471173_MASK                                        0x4
#define PCIE_MISC_CTRL_STAR_471173_GET(x)                                      (((x) & PCIE_MISC_CTRL_STAR_471173_MASK) >> PCIE_MISC_CTRL_STAR_471173_LSB)
#define PCIE_MISC_CTRL_STAR_471173_SET(x)                                      (((0 | (x)) << PCIE_MISC_CTRL_STAR_471173_LSB) & PCIE_MISC_CTRL_STAR_471173_MASK)
#define PCIE_MISC_CTRL_STAR_471173_RESET                                       0x0
#define PCIE_MISC_CTRL_TS_EXPECTED_WA_EN_LSB                                   1
#define PCIE_MISC_CTRL_TS_EXPECTED_WA_EN_MSB                                   1
#define PCIE_MISC_CTRL_TS_EXPECTED_WA_EN_MASK                                  0x2
#define PCIE_MISC_CTRL_TS_EXPECTED_WA_EN_GET(x)                                (((x) & PCIE_MISC_CTRL_TS_EXPECTED_WA_EN_MASK) >> PCIE_MISC_CTRL_TS_EXPECTED_WA_EN_LSB)
#define PCIE_MISC_CTRL_TS_EXPECTED_WA_EN_SET(x)                                (((0 | (x)) << PCIE_MISC_CTRL_TS_EXPECTED_WA_EN_LSB) & PCIE_MISC_CTRL_TS_EXPECTED_WA_EN_MASK)
#define PCIE_MISC_CTRL_TS_EXPECTED_WA_EN_RESET                                 0x1
#define PCIE_MISC_CTRL_EXT_RBIAS_CTRL_LSB                                      0
#define PCIE_MISC_CTRL_EXT_RBIAS_CTRL_MSB                                      0
#define PCIE_MISC_CTRL_EXT_RBIAS_CTRL_MASK                                     0x1
#define PCIE_MISC_CTRL_EXT_RBIAS_CTRL_GET(x)                                   (((x) & PCIE_MISC_CTRL_EXT_RBIAS_CTRL_MASK) >> PCIE_MISC_CTRL_EXT_RBIAS_CTRL_LSB)
#define PCIE_MISC_CTRL_EXT_RBIAS_CTRL_SET(x)                                   (((0 | (x)) << PCIE_MISC_CTRL_EXT_RBIAS_CTRL_LSB) & PCIE_MISC_CTRL_EXT_RBIAS_CTRL_MASK)
#define PCIE_MISC_CTRL_EXT_RBIAS_CTRL_RESET                                    0x1
#define PCIE_MISC_CTRL_ADDRESS                                                 (0xcc + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_MISC_CTRL_RSTMASK                                                 0x1f
#define PCIE_MISC_CTRL_RESET                                                   0x3

// 0xd0 (PCIE_IDLE_DLY)
#define PCIE_IDLE_DLY_IDLE_DLY_EN_LSB                                          31
#define PCIE_IDLE_DLY_IDLE_DLY_EN_MSB                                          31
#define PCIE_IDLE_DLY_IDLE_DLY_EN_MASK                                         0x80000000
#define PCIE_IDLE_DLY_IDLE_DLY_EN_GET(x)                                       (((x) & PCIE_IDLE_DLY_IDLE_DLY_EN_MASK) >> PCIE_IDLE_DLY_IDLE_DLY_EN_LSB)
#define PCIE_IDLE_DLY_IDLE_DLY_EN_SET(x)                                       (((0 | (x)) << PCIE_IDLE_DLY_IDLE_DLY_EN_LSB) & PCIE_IDLE_DLY_IDLE_DLY_EN_MASK)
#define PCIE_IDLE_DLY_IDLE_DLY_EN_RESET                                        0x0
#define PCIE_IDLE_DLY_IDLE_DLY_CLR_LSB                                         30
#define PCIE_IDLE_DLY_IDLE_DLY_CLR_MSB                                         30
#define PCIE_IDLE_DLY_IDLE_DLY_CLR_MASK                                        0x40000000
#define PCIE_IDLE_DLY_IDLE_DLY_CLR_GET(x)                                      (((x) & PCIE_IDLE_DLY_IDLE_DLY_CLR_MASK) >> PCIE_IDLE_DLY_IDLE_DLY_CLR_LSB)
#define PCIE_IDLE_DLY_IDLE_DLY_CLR_SET(x)                                      (((0 | (x)) << PCIE_IDLE_DLY_IDLE_DLY_CLR_LSB) & PCIE_IDLE_DLY_IDLE_DLY_CLR_MASK)
#define PCIE_IDLE_DLY_IDLE_DLY_CLR_RESET                                       0x0
#define PCIE_IDLE_DLY_IDLE_DLY_SCALE_LSB                                       16
#define PCIE_IDLE_DLY_IDLE_DLY_SCALE_MSB                                       19
#define PCIE_IDLE_DLY_IDLE_DLY_SCALE_MASK                                      0xf0000
#define PCIE_IDLE_DLY_IDLE_DLY_SCALE_GET(x)                                    (((x) & PCIE_IDLE_DLY_IDLE_DLY_SCALE_MASK) >> PCIE_IDLE_DLY_IDLE_DLY_SCALE_LSB)
#define PCIE_IDLE_DLY_IDLE_DLY_SCALE_SET(x)                                    (((0 | (x)) << PCIE_IDLE_DLY_IDLE_DLY_SCALE_LSB) & PCIE_IDLE_DLY_IDLE_DLY_SCALE_MASK)
#define PCIE_IDLE_DLY_IDLE_DLY_SCALE_RESET                                     0x0
#define PCIE_IDLE_DLY_IDLE_DLY_VALUE_LSB                                       0
#define PCIE_IDLE_DLY_IDLE_DLY_VALUE_MSB                                       15
#define PCIE_IDLE_DLY_IDLE_DLY_VALUE_MASK                                      0xffff
#define PCIE_IDLE_DLY_IDLE_DLY_VALUE_GET(x)                                    (((x) & PCIE_IDLE_DLY_IDLE_DLY_VALUE_MASK) >> PCIE_IDLE_DLY_IDLE_DLY_VALUE_LSB)
#define PCIE_IDLE_DLY_IDLE_DLY_VALUE_SET(x)                                    (((0 | (x)) << PCIE_IDLE_DLY_IDLE_DLY_VALUE_LSB) & PCIE_IDLE_DLY_IDLE_DLY_VALUE_MASK)
#define PCIE_IDLE_DLY_IDLE_DLY_VALUE_RESET                                     0x0
#define PCIE_IDLE_DLY_ADDRESS                                                  (0xd0 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_IDLE_DLY_RSTMASK                                                  0xc00fffff
#define PCIE_IDLE_DLY_RESET                                                    0x0

// 0xd4 (L1_ENTER_CNT)
#define L1_ENTER_CNT_CNT_LSB                                                   0
#define L1_ENTER_CNT_CNT_MSB                                                   31
#define L1_ENTER_CNT_CNT_MASK                                                  0xffffffff
#define L1_ENTER_CNT_CNT_GET(x)                                                (((x) & L1_ENTER_CNT_CNT_MASK) >> L1_ENTER_CNT_CNT_LSB)
#define L1_ENTER_CNT_CNT_SET(x)                                                (((0 | (x)) << L1_ENTER_CNT_CNT_LSB) & L1_ENTER_CNT_CNT_MASK)
#define L1_ENTER_CNT_CNT_RESET                                                 0x0
#define L1_ENTER_CNT_ADDRESS                                                   (0xd4 + __SOC_PCIE_REG_BASE_ADDRESS)
#define L1_ENTER_CNT_RSTMASK                                                   0xffffffff
#define L1_ENTER_CNT_RESET                                                     0x0

// 0xd8 (L1_1_ENTER_CNT)
#define L1_1_ENTER_CNT_CNT_LSB                                                 0
#define L1_1_ENTER_CNT_CNT_MSB                                                 31
#define L1_1_ENTER_CNT_CNT_MASK                                                0xffffffff
#define L1_1_ENTER_CNT_CNT_GET(x)                                              (((x) & L1_1_ENTER_CNT_CNT_MASK) >> L1_1_ENTER_CNT_CNT_LSB)
#define L1_1_ENTER_CNT_CNT_SET(x)                                              (((0 | (x)) << L1_1_ENTER_CNT_CNT_LSB) & L1_1_ENTER_CNT_CNT_MASK)
#define L1_1_ENTER_CNT_CNT_RESET                                               0x0
#define L1_1_ENTER_CNT_ADDRESS                                                 (0xd8 + __SOC_PCIE_REG_BASE_ADDRESS)
#define L1_1_ENTER_CNT_RSTMASK                                                 0xffffffff
#define L1_1_ENTER_CNT_RESET                                                   0x0

// 0xdc (L1_2_ENTER_CNT)
#define L1_2_ENTER_CNT_CNT_LSB                                                 0
#define L1_2_ENTER_CNT_CNT_MSB                                                 31
#define L1_2_ENTER_CNT_CNT_MASK                                                0xffffffff
#define L1_2_ENTER_CNT_CNT_GET(x)                                              (((x) & L1_2_ENTER_CNT_CNT_MASK) >> L1_2_ENTER_CNT_CNT_LSB)
#define L1_2_ENTER_CNT_CNT_SET(x)                                              (((0 | (x)) << L1_2_ENTER_CNT_CNT_LSB) & L1_2_ENTER_CNT_CNT_MASK)
#define L1_2_ENTER_CNT_CNT_RESET                                               0x0
#define L1_2_ENTER_CNT_ADDRESS                                                 (0xdc + __SOC_PCIE_REG_BASE_ADDRESS)
#define L1_2_ENTER_CNT_RSTMASK                                                 0xffffffff
#define L1_2_ENTER_CNT_RESET                                                   0x0

// 0xe0 (PCIE_WRAP_INTR_MASK)
#define PCIE_WRAP_INTR_MASK_CONTROL_LSB                                        0
#define PCIE_WRAP_INTR_MASK_CONTROL_MSB                                        31
#define PCIE_WRAP_INTR_MASK_CONTROL_MASK                                       0xffffffff
#define PCIE_WRAP_INTR_MASK_CONTROL_GET(x)                                     (((x) & PCIE_WRAP_INTR_MASK_CONTROL_MASK) >> PCIE_WRAP_INTR_MASK_CONTROL_LSB)
#define PCIE_WRAP_INTR_MASK_CONTROL_SET(x)                                     (((0 | (x)) << PCIE_WRAP_INTR_MASK_CONTROL_LSB) & PCIE_WRAP_INTR_MASK_CONTROL_MASK)
#define PCIE_WRAP_INTR_MASK_CONTROL_RESET                                      0x0
#define PCIE_WRAP_INTR_MASK_ADDRESS                                            (0xe0 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_WRAP_INTR_MASK_RSTMASK                                            0xffffffff
#define PCIE_WRAP_INTR_MASK_RESET                                              0x0

// 0xe4 (PCIE_WRAP_INTR_HOST_MASK)
#define PCIE_WRAP_INTR_HOST_MASK_CONTROL_LSB                                   0
#define PCIE_WRAP_INTR_HOST_MASK_CONTROL_MSB                                   31
#define PCIE_WRAP_INTR_HOST_MASK_CONTROL_MASK                                  0xffffffff
#define PCIE_WRAP_INTR_HOST_MASK_CONTROL_GET(x)                                (((x) & PCIE_WRAP_INTR_HOST_MASK_CONTROL_MASK) >> PCIE_WRAP_INTR_HOST_MASK_CONTROL_LSB)
#define PCIE_WRAP_INTR_HOST_MASK_CONTROL_SET(x)                                (((0 | (x)) << PCIE_WRAP_INTR_HOST_MASK_CONTROL_LSB) & PCIE_WRAP_INTR_HOST_MASK_CONTROL_MASK)
#define PCIE_WRAP_INTR_HOST_MASK_CONTROL_RESET                                 0x0
#define PCIE_WRAP_INTR_HOST_MASK_ADDRESS                                       (0xe4 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_WRAP_INTR_HOST_MASK_RSTMASK                                       0xffffffff
#define PCIE_WRAP_INTR_HOST_MASK_RESET                                         0x0

// 0xe8 (PCIE_WRAP_INTR_STATUS)
#define PCIE_WRAP_INTR_STATUS_VALUE_LSB                                        0
#define PCIE_WRAP_INTR_STATUS_VALUE_MSB                                        31
#define PCIE_WRAP_INTR_STATUS_VALUE_MASK                                       0xffffffff
#define PCIE_WRAP_INTR_STATUS_VALUE_GET(x)                                     (((x) & PCIE_WRAP_INTR_STATUS_VALUE_MASK) >> PCIE_WRAP_INTR_STATUS_VALUE_LSB)
#define PCIE_WRAP_INTR_STATUS_VALUE_SET(x)                                     (((0 | (x)) << PCIE_WRAP_INTR_STATUS_VALUE_LSB) & PCIE_WRAP_INTR_STATUS_VALUE_MASK)
#define PCIE_WRAP_INTR_STATUS_VALUE_RESET                                      0x0
#define PCIE_WRAP_INTR_STATUS_ADDRESS                                          (0xe8 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_WRAP_INTR_STATUS_RSTMASK                                          0xffffffff
#define PCIE_WRAP_INTR_STATUS_RESET                                            0x0

// 0xec (EV144272)
#define EV144272_ENABLE_LSB                                                    0
#define EV144272_ENABLE_MSB                                                    0
#define EV144272_ENABLE_MASK                                                   0x1
#define EV144272_ENABLE_GET(x)                                                 (((x) & EV144272_ENABLE_MASK) >> EV144272_ENABLE_LSB)
#define EV144272_ENABLE_SET(x)                                                 (((0 | (x)) << EV144272_ENABLE_LSB) & EV144272_ENABLE_MASK)
#define EV144272_ENABLE_RESET                                                  0x0
#define EV144272_ADDRESS                                                       (0xec + __SOC_PCIE_REG_BASE_ADDRESS)
#define EV144272_RSTMASK                                                       0x1
#define EV144272_RESET                                                         0x0

// 0xf0 (PCIE_CTRL_EXT)
#define PCIE_CTRL_EXT_ASPM_APP_REQ_L1_DIS_LSB                                  0
#define PCIE_CTRL_EXT_ASPM_APP_REQ_L1_DIS_MSB                                  0
#define PCIE_CTRL_EXT_ASPM_APP_REQ_L1_DIS_MASK                                 0x1
#define PCIE_CTRL_EXT_ASPM_APP_REQ_L1_DIS_GET(x)                               (((x) & PCIE_CTRL_EXT_ASPM_APP_REQ_L1_DIS_MASK) >> PCIE_CTRL_EXT_ASPM_APP_REQ_L1_DIS_LSB)
#define PCIE_CTRL_EXT_ASPM_APP_REQ_L1_DIS_SET(x)                               (((0 | (x)) << PCIE_CTRL_EXT_ASPM_APP_REQ_L1_DIS_LSB) & PCIE_CTRL_EXT_ASPM_APP_REQ_L1_DIS_MASK)
#define PCIE_CTRL_EXT_ASPM_APP_REQ_L1_DIS_RESET                                0x0
#define PCIE_CTRL_EXT_ADDRESS                                                  (0xf0 + __SOC_PCIE_REG_BASE_ADDRESS)
#define PCIE_CTRL_EXT_RSTMASK                                                  0x1
#define PCIE_CTRL_EXT_RESET                                                    0x0



#endif /* _SOC_PCIE_REG_H_ */
