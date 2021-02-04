/*
 * QCA 955x series processor SOC registers
 *
 * Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _QCA955X_H
#define _QCA955X_H

#define ATH_PCI_DEV_CFGBASE		0x14000000

/* copied from u-boot */
#define PCI_COMMAND			0x04    /* 16 bits */
#define  PCI_COMMAND_IO			0x1     /* Enable response in I/O space */
#define  PCI_COMMAND_MEMORY		0x2     /* Enable response in Memory space */
#define  PCI_COMMAND_MASTER		0x4     /* Enable bus mastering */
#define  PCI_COMMAND_SPECIAL		0x8     /* Enable response to special cycles */
#define  PCI_COMMAND_INVALIDATE		0x10    /* Use memory write and invalidate */
#define  PCI_COMMAND_VGA_PALETTE	0x20   /* Enable palette snooping */
#define  PCI_COMMAND_PARITY		0x40    /* Enable parity checking */
#define  PCI_COMMAND_WAIT		0x80    /* Enable address/data stepping */
#define  PCI_COMMAND_SERR		0x100   /* Enable SERR */
#define  PCI_COMMAND_FAST_BACK		0x200   /* Enable back-to-back writes */


#define ATH_SPI_BASE			0x1f000000
#define ATH_SPI_CLOCK			(ATH_SPI_BASE + 0x04)


#define ar7240_write_pci_window(_no)	\
	ar7240_reg_wr(AR7240_PCI_WINDOW##_no##_OFFSET, AR7240_PCI_WINDOW##_no##_VAL)

#define BIT(_x) (1 << (_x))

#define DDR_CONFIG_3_SPARE_MSB                                       31
#define DDR_CONFIG_3_SPARE_LSB                                       4
#define DDR_CONFIG_3_SPARE_MASK                                      0xfffffff0
#define DDR_CONFIG_3_SPARE_GET(x)                                    (((x) & DDR_CONFIG_3_SPARE_MASK) >> DDR_CONFIG_3_SPARE_LSB)
#define DDR_CONFIG_3_SPARE_SET(x)                                    (((x) << DDR_CONFIG_3_SPARE_LSB) & DDR_CONFIG_3_SPARE_MASK)
#define DDR_CONFIG_3_SPARE_RESET                                     0x0 // 0
#define DDR_CONFIG_3_TWR_MSB_MSB                                     3
#define DDR_CONFIG_3_TWR_MSB_LSB                                     3
#define DDR_CONFIG_3_TWR_MSB_MASK                                    0x00000008
#define DDR_CONFIG_3_TWR_MSB_GET(x)                                  (((x) & DDR_CONFIG_3_TWR_MSB_MASK) >> DDR_CONFIG_3_TWR_MSB_LSB)
#define DDR_CONFIG_3_TWR_MSB_SET(x)                                  (((x) << DDR_CONFIG_3_TWR_MSB_LSB) & DDR_CONFIG_3_TWR_MSB_MASK)
#define DDR_CONFIG_3_TWR_MSB_RESET                                   0x0 // 0
#define DDR_CONFIG_3_TRAS_MSB_MSB                                    2
#define DDR_CONFIG_3_TRAS_MSB_LSB                                    2
#define DDR_CONFIG_3_TRAS_MSB_MASK                                   0x00000004
#define DDR_CONFIG_3_TRAS_MSB_GET(x)                                 (((x) & DDR_CONFIG_3_TRAS_MSB_MASK) >> DDR_CONFIG_3_TRAS_MSB_LSB)
#define DDR_CONFIG_3_TRAS_MSB_SET(x)                                 (((x) << DDR_CONFIG_3_TRAS_MSB_LSB) & DDR_CONFIG_3_TRAS_MSB_MASK)
#define DDR_CONFIG_3_TRAS_MSB_RESET                                  0x0 // 0
#define DDR_CONFIG_3_TRFC_LSB_MSB                                    1
#define DDR_CONFIG_3_TRFC_LSB_LSB                                    0
#define DDR_CONFIG_3_TRFC_LSB_MASK                                   0x00000003
#define DDR_CONFIG_3_TRFC_LSB_GET(x)                                 (((x) & DDR_CONFIG_3_TRFC_LSB_MASK) >> DDR_CONFIG_3_TRFC_LSB_LSB)
#define DDR_CONFIG_3_TRFC_LSB_SET(x)                                 (((x) << DDR_CONFIG_3_TRFC_LSB_LSB) & DDR_CONFIG_3_TRFC_LSB_MASK)
#define DDR_CONFIG_3_TRFC_LSB_RESET                                  0x0 // 0
#define DDR_CONFIG_3_ADDRESS                                         0x1800015c

#define BB_DPLL2_RANGE_MSB                                           31
#define BB_DPLL2_RANGE_LSB                                           31
#define BB_DPLL2_RANGE_MASK                                          0x80000000
#define BB_DPLL2_RANGE_GET(x)                                        (((x) & BB_DPLL2_RANGE_MASK) >> BB_DPLL2_RANGE_LSB)
#define BB_DPLL2_RANGE_SET(x)                                        (((x) << BB_DPLL2_RANGE_LSB) & BB_DPLL2_RANGE_MASK)
#define BB_DPLL2_RANGE_RESET                                         0x0 // 0
#define BB_DPLL2_LOCAL_PLL_MSB                                       30
#define BB_DPLL2_LOCAL_PLL_LSB                                       30
#define BB_DPLL2_LOCAL_PLL_MASK                                      0x40000000
#define BB_DPLL2_LOCAL_PLL_GET(x)                                    (((x) & BB_DPLL2_LOCAL_PLL_MASK) >> BB_DPLL2_LOCAL_PLL_LSB)
#define BB_DPLL2_LOCAL_PLL_SET(x)                                    (((x) << BB_DPLL2_LOCAL_PLL_LSB) & BB_DPLL2_LOCAL_PLL_MASK)
#define BB_DPLL2_LOCAL_PLL_RESET                                     0x0 // 0
#define BB_DPLL2_KI_MSB                                              29
#define BB_DPLL2_KI_LSB                                              26
#define BB_DPLL2_KI_MASK                                             0x3c000000
#define BB_DPLL2_KI_GET(x)                                           (((x) & BB_DPLL2_KI_MASK) >> BB_DPLL2_KI_LSB)
#define BB_DPLL2_KI_SET(x)                                           (((x) << BB_DPLL2_KI_LSB) & BB_DPLL2_KI_MASK)
#define BB_DPLL2_KI_RESET                                            0x6 // 6
#define BB_DPLL2_KD_MSB                                              25
#define BB_DPLL2_KD_LSB                                              19
#define BB_DPLL2_KD_MASK                                             0x03f80000
#define BB_DPLL2_KD_GET(x)                                           (((x) & BB_DPLL2_KD_MASK) >> BB_DPLL2_KD_LSB)
#define BB_DPLL2_KD_SET(x)                                           (((x) << BB_DPLL2_KD_LSB) & BB_DPLL2_KD_MASK)
#define BB_DPLL2_KD_RESET                                            0x7f // 127
#define BB_DPLL2_EN_NEGTRIG_MSB                                      18
#define BB_DPLL2_EN_NEGTRIG_LSB                                      18
#define BB_DPLL2_EN_NEGTRIG_MASK                                     0x00040000
#define BB_DPLL2_EN_NEGTRIG_GET(x)                                   (((x) & BB_DPLL2_EN_NEGTRIG_MASK) >> BB_DPLL2_EN_NEGTRIG_LSB)
#define BB_DPLL2_EN_NEGTRIG_SET(x)                                   (((x) << BB_DPLL2_EN_NEGTRIG_LSB) & BB_DPLL2_EN_NEGTRIG_MASK)
#define BB_DPLL2_EN_NEGTRIG_RESET                                    0x0 // 0
#define BB_DPLL2_SEL_1SDM_MSB                                        17
#define BB_DPLL2_SEL_1SDM_LSB                                        17
#define BB_DPLL2_SEL_1SDM_MASK                                       0x00020000
#define BB_DPLL2_SEL_1SDM_GET(x)                                     (((x) & BB_DPLL2_SEL_1SDM_MASK) >> BB_DPLL2_SEL_1SDM_LSB)
#define BB_DPLL2_SEL_1SDM_SET(x)                                     (((x) << BB_DPLL2_SEL_1SDM_LSB) & BB_DPLL2_SEL_1SDM_MASK)
#define BB_DPLL2_SEL_1SDM_RESET                                      0x0 // 0
#define BB_DPLL2_PLL_PWD_MSB                                         16
#define BB_DPLL2_PLL_PWD_LSB                                         16
#define BB_DPLL2_PLL_PWD_MASK                                        0x00010000
#define BB_DPLL2_PLL_PWD_GET(x)                                      (((x) & BB_DPLL2_PLL_PWD_MASK) >> BB_DPLL2_PLL_PWD_LSB)
#define BB_DPLL2_PLL_PWD_SET(x)                                      (((x) << BB_DPLL2_PLL_PWD_LSB) & BB_DPLL2_PLL_PWD_MASK)
#define BB_DPLL2_PLL_PWD_RESET                                       0x1 // 1
#define BB_DPLL2_OUTDIV_MSB                                          15
#define BB_DPLL2_OUTDIV_LSB                                          13
#define BB_DPLL2_OUTDIV_MASK                                         0x0000e000
#define BB_DPLL2_OUTDIV_GET(x)                                       (((x) & BB_DPLL2_OUTDIV_MASK) >> BB_DPLL2_OUTDIV_LSB)
#define BB_DPLL2_OUTDIV_SET(x)                                       (((x) << BB_DPLL2_OUTDIV_LSB) & BB_DPLL2_OUTDIV_MASK)
#define BB_DPLL2_OUTDIV_RESET                                        0x0 // 0
#define BB_DPLL2_DELTA_MSB                                           12
#define BB_DPLL2_DELTA_LSB                                           7
#define BB_DPLL2_DELTA_MASK                                          0x00001f80
#define BB_DPLL2_DELTA_GET(x)                                        (((x) & BB_DPLL2_DELTA_MASK) >> BB_DPLL2_DELTA_LSB)
#define BB_DPLL2_DELTA_SET(x)                                        (((x) << BB_DPLL2_DELTA_LSB) & BB_DPLL2_DELTA_MASK)
#define BB_DPLL2_DELTA_RESET                                         0x1e // 30
#define BB_DPLL2_TESTINMSB_MSB                                       6
#define BB_DPLL2_TESTINMSB_LSB                                       0
#define BB_DPLL2_TESTINMSB_MASK                                      0x0000007f
#define BB_DPLL2_TESTINMSB_GET(x)                                    (((x) & BB_DPLL2_TESTINMSB_MASK) >> BB_DPLL2_TESTINMSB_LSB)
#define BB_DPLL2_TESTINMSB_SET(x)                                    (((x) << BB_DPLL2_TESTINMSB_LSB) & BB_DPLL2_TESTINMSB_MASK)
#define BB_DPLL2_TESTINMSB_RESET                                     0x0 // 0
#define BB_DPLL2_ADDRESS                                             0x18116184

#define PCIe_DPLL2_RANGE_MSB                                         31
#define PCIe_DPLL2_RANGE_LSB                                         31
#define PCIe_DPLL2_RANGE_MASK                                        0x80000000
#define PCIe_DPLL2_RANGE_GET(x)                                      (((x) & PCIe_DPLL2_RANGE_MASK) >> PCIe_DPLL2_RANGE_LSB)
#define PCIe_DPLL2_RANGE_SET(x)                                      (((x) << PCIe_DPLL2_RANGE_LSB) & PCIe_DPLL2_RANGE_MASK)
#define PCIe_DPLL2_RANGE_RESET                                       0x0 // 0
#define PCIe_DPLL2_LOCAL_PLL_MSB                                     30
#define PCIe_DPLL2_LOCAL_PLL_LSB                                     30
#define PCIe_DPLL2_LOCAL_PLL_MASK                                    0x40000000
#define PCIe_DPLL2_LOCAL_PLL_GET(x)                                  (((x) & PCIe_DPLL2_LOCAL_PLL_MASK) >> PCIe_DPLL2_LOCAL_PLL_LSB)
#define PCIe_DPLL2_LOCAL_PLL_SET(x)                                  (((x) << PCIe_DPLL2_LOCAL_PLL_LSB) & PCIe_DPLL2_LOCAL_PLL_MASK)
#define PCIe_DPLL2_LOCAL_PLL_RESET                                   0x0 // 0
#define PCIe_DPLL2_KI_MSB                                            29
#define PCIe_DPLL2_KI_LSB                                            26
#define PCIe_DPLL2_KI_MASK                                           0x3c000000
#define PCIe_DPLL2_KI_GET(x)                                         (((x) & PCIe_DPLL2_KI_MASK) >> PCIe_DPLL2_KI_LSB)
#define PCIe_DPLL2_KI_SET(x)                                         (((x) << PCIe_DPLL2_KI_LSB) & PCIe_DPLL2_KI_MASK)
#define PCIe_DPLL2_KI_RESET                                          0x6 // 6
#define PCIe_DPLL2_KD_MSB                                            25
#define PCIe_DPLL2_KD_LSB                                            19
#define PCIe_DPLL2_KD_MASK                                           0x03f80000
#define PCIe_DPLL2_KD_GET(x)                                         (((x) & PCIe_DPLL2_KD_MASK) >> PCIe_DPLL2_KD_LSB)
#define PCIe_DPLL2_KD_SET(x)                                         (((x) << PCIe_DPLL2_KD_LSB) & PCIe_DPLL2_KD_MASK)
#define PCIe_DPLL2_KD_RESET                                          0x7f // 127
#define PCIe_DPLL2_EN_NEGTRIG_MSB                                    18
#define PCIe_DPLL2_EN_NEGTRIG_LSB                                    18
#define PCIe_DPLL2_EN_NEGTRIG_MASK                                   0x00040000
#define PCIe_DPLL2_EN_NEGTRIG_GET(x)                                 (((x) & PCIe_DPLL2_EN_NEGTRIG_MASK) >> PCIe_DPLL2_EN_NEGTRIG_LSB)
#define PCIe_DPLL2_EN_NEGTRIG_SET(x)                                 (((x) << PCIe_DPLL2_EN_NEGTRIG_LSB) & PCIe_DPLL2_EN_NEGTRIG_MASK)
#define PCIe_DPLL2_EN_NEGTRIG_RESET                                  0x0 // 0
#define PCIe_DPLL2_SEL_1SDM_MSB                                      17
#define PCIe_DPLL2_SEL_1SDM_LSB                                      17
#define PCIe_DPLL2_SEL_1SDM_MASK                                     0x00020000
#define PCIe_DPLL2_SEL_1SDM_GET(x)                                   (((x) & PCIe_DPLL2_SEL_1SDM_MASK) >> PCIe_DPLL2_SEL_1SDM_LSB)
#define PCIe_DPLL2_SEL_1SDM_SET(x)                                   (((x) << PCIe_DPLL2_SEL_1SDM_LSB) & PCIe_DPLL2_SEL_1SDM_MASK)
#define PCIe_DPLL2_SEL_1SDM_RESET                                    0x0 // 0
#define PCIe_DPLL2_PLL_PWD_MSB                                       16
#define PCIe_DPLL2_PLL_PWD_LSB                                       16
#define PCIe_DPLL2_PLL_PWD_MASK                                      0x00010000
#define PCIe_DPLL2_PLL_PWD_GET(x)                                    (((x) & PCIe_DPLL2_PLL_PWD_MASK) >> PCIe_DPLL2_PLL_PWD_LSB)
#define PCIe_DPLL2_PLL_PWD_SET(x)                                    (((x) << PCIe_DPLL2_PLL_PWD_LSB) & PCIe_DPLL2_PLL_PWD_MASK)
#define PCIe_DPLL2_PLL_PWD_RESET                                     0x1 // 1
#define PCIe_DPLL2_OUTDIV_MSB                                        15
#define PCIe_DPLL2_OUTDIV_LSB                                        13
#define PCIe_DPLL2_OUTDIV_MASK                                       0x0000e000
#define PCIe_DPLL2_OUTDIV_GET(x)                                     (((x) & PCIe_DPLL2_OUTDIV_MASK) >> PCIe_DPLL2_OUTDIV_LSB)
#define PCIe_DPLL2_OUTDIV_SET(x)                                     (((x) << PCIe_DPLL2_OUTDIV_LSB) & PCIe_DPLL2_OUTDIV_MASK)
#define PCIe_DPLL2_OUTDIV_RESET                                      0x0 // 0
#define PCIe_DPLL2_DELTA_MSB                                         12
#define PCIe_DPLL2_DELTA_LSB                                         7
#define PCIe_DPLL2_DELTA_MASK                                        0x00001f80
#define PCIe_DPLL2_DELTA_GET(x)                                      (((x) & PCIe_DPLL2_DELTA_MASK) >> PCIe_DPLL2_DELTA_LSB)
#define PCIe_DPLL2_DELTA_SET(x)                                      (((x) << PCIe_DPLL2_DELTA_LSB) & PCIe_DPLL2_DELTA_MASK)
#define PCIe_DPLL2_DELTA_RESET                                       0x1e // 30
#define PCIe_DPLL2_TESTINMSB_MSB                                     6
#define PCIe_DPLL2_TESTINMSB_LSB                                     0
#define PCIe_DPLL2_TESTINMSB_MASK                                    0x0000007f
#define PCIe_DPLL2_TESTINMSB_GET(x)                                  (((x) & PCIe_DPLL2_TESTINMSB_MASK) >> PCIe_DPLL2_TESTINMSB_LSB)
#define PCIe_DPLL2_TESTINMSB_SET(x)                                  (((x) << PCIe_DPLL2_TESTINMSB_LSB) & PCIe_DPLL2_TESTINMSB_MASK)
#define PCIe_DPLL2_TESTINMSB_RESET                                   0x0 // 0
#define PCIe_DPLL2_ADDRESS                                           0x18116c84

#define DDR_DPLL2_RANGE_MSB                                          31
#define DDR_DPLL2_RANGE_LSB                                          31
#define DDR_DPLL2_RANGE_MASK                                         0x80000000
#define DDR_DPLL2_RANGE_GET(x)                                       (((x) & DDR_DPLL2_RANGE_MASK) >> DDR_DPLL2_RANGE_LSB)
#define DDR_DPLL2_RANGE_SET(x)                                       (((x) << DDR_DPLL2_RANGE_LSB) & DDR_DPLL2_RANGE_MASK)
#define DDR_DPLL2_RANGE_RESET                                        0x0 // 0
#define DDR_DPLL2_LOCAL_PLL_MSB                                      30
#define DDR_DPLL2_LOCAL_PLL_LSB                                      30
#define DDR_DPLL2_LOCAL_PLL_MASK                                     0x40000000
#define DDR_DPLL2_LOCAL_PLL_GET(x)                                   (((x) & DDR_DPLL2_LOCAL_PLL_MASK) >> DDR_DPLL2_LOCAL_PLL_LSB)
#define DDR_DPLL2_LOCAL_PLL_SET(x)                                   (((x) << DDR_DPLL2_LOCAL_PLL_LSB) & DDR_DPLL2_LOCAL_PLL_MASK)
#define DDR_DPLL2_LOCAL_PLL_RESET                                    0x0 // 0
#define DDR_DPLL2_KI_MSB                                             29
#define DDR_DPLL2_KI_LSB                                             26
#define DDR_DPLL2_KI_MASK                                            0x3c000000
#define DDR_DPLL2_KI_GET(x)                                          (((x) & DDR_DPLL2_KI_MASK) >> DDR_DPLL2_KI_LSB)
#define DDR_DPLL2_KI_SET(x)                                          (((x) << DDR_DPLL2_KI_LSB) & DDR_DPLL2_KI_MASK)
#define DDR_DPLL2_KI_RESET                                           0x6 // 6
#define DDR_DPLL2_KD_MSB                                             25
#define DDR_DPLL2_KD_LSB                                             19
#define DDR_DPLL2_KD_MASK                                            0x03f80000
#define DDR_DPLL2_KD_GET(x)                                          (((x) & DDR_DPLL2_KD_MASK) >> DDR_DPLL2_KD_LSB)
#define DDR_DPLL2_KD_SET(x)                                          (((x) << DDR_DPLL2_KD_LSB) & DDR_DPLL2_KD_MASK)
#define DDR_DPLL2_KD_RESET                                           0x7f // 127
#define DDR_DPLL2_EN_NEGTRIG_MSB                                     18
#define DDR_DPLL2_EN_NEGTRIG_LSB                                     18
#define DDR_DPLL2_EN_NEGTRIG_MASK                                    0x00040000
#define DDR_DPLL2_EN_NEGTRIG_GET(x)                                  (((x) & DDR_DPLL2_EN_NEGTRIG_MASK) >> DDR_DPLL2_EN_NEGTRIG_LSB)
#define DDR_DPLL2_EN_NEGTRIG_SET(x)                                  (((x) << DDR_DPLL2_EN_NEGTRIG_LSB) & DDR_DPLL2_EN_NEGTRIG_MASK)
#define DDR_DPLL2_EN_NEGTRIG_RESET                                   0x0 // 0
#define DDR_DPLL2_SEL_1SDM_MSB                                       17
#define DDR_DPLL2_SEL_1SDM_LSB                                       17
#define DDR_DPLL2_SEL_1SDM_MASK                                      0x00020000
#define DDR_DPLL2_SEL_1SDM_GET(x)                                    (((x) & DDR_DPLL2_SEL_1SDM_MASK) >> DDR_DPLL2_SEL_1SDM_LSB)
#define DDR_DPLL2_SEL_1SDM_SET(x)                                    (((x) << DDR_DPLL2_SEL_1SDM_LSB) & DDR_DPLL2_SEL_1SDM_MASK)
#define DDR_DPLL2_SEL_1SDM_RESET                                     0x0 // 0
#define DDR_DPLL2_PLL_PWD_MSB                                        16
#define DDR_DPLL2_PLL_PWD_LSB                                        16
#define DDR_DPLL2_PLL_PWD_MASK                                       0x00010000
#define DDR_DPLL2_PLL_PWD_GET(x)                                     (((x) & DDR_DPLL2_PLL_PWD_MASK) >> DDR_DPLL2_PLL_PWD_LSB)
#define DDR_DPLL2_PLL_PWD_SET(x)                                     (((x) << DDR_DPLL2_PLL_PWD_LSB) & DDR_DPLL2_PLL_PWD_MASK)
#define DDR_DPLL2_PLL_PWD_RESET                                      0x1 // 1
#define DDR_DPLL2_OUTDIV_MSB                                         15
#define DDR_DPLL2_OUTDIV_LSB                                         13
#define DDR_DPLL2_OUTDIV_MASK                                        0x0000e000
#define DDR_DPLL2_OUTDIV_GET(x)                                      (((x) & DDR_DPLL2_OUTDIV_MASK) >> DDR_DPLL2_OUTDIV_LSB)
#define DDR_DPLL2_OUTDIV_SET(x)                                      (((x) << DDR_DPLL2_OUTDIV_LSB) & DDR_DPLL2_OUTDIV_MASK)
#define DDR_DPLL2_OUTDIV_RESET                                       0x0 // 0
#define DDR_DPLL2_DELTA_MSB                                          12
#define DDR_DPLL2_DELTA_LSB                                          7
#define DDR_DPLL2_DELTA_MASK                                         0x00001f80
#define DDR_DPLL2_DELTA_GET(x)                                       (((x) & DDR_DPLL2_DELTA_MASK) >> DDR_DPLL2_DELTA_LSB)
#define DDR_DPLL2_DELTA_SET(x)                                       (((x) << DDR_DPLL2_DELTA_LSB) & DDR_DPLL2_DELTA_MASK)
#define DDR_DPLL2_DELTA_RESET                                        0x1e // 30
#define DDR_DPLL2_TESTINMSB_MSB                                      6
#define DDR_DPLL2_TESTINMSB_LSB                                      0
#define DDR_DPLL2_TESTINMSB_MASK                                     0x0000007f
#define DDR_DPLL2_TESTINMSB_GET(x)                                   (((x) & DDR_DPLL2_TESTINMSB_MASK) >> DDR_DPLL2_TESTINMSB_LSB)
#define DDR_DPLL2_TESTINMSB_SET(x)                                   (((x) << DDR_DPLL2_TESTINMSB_LSB) & DDR_DPLL2_TESTINMSB_MASK)
#define DDR_DPLL2_TESTINMSB_RESET                                    0x0 // 0
#define DDR_DPLL2_ADDRESS                                            0x18116ec4

#define CPU_DPLL2_RANGE_MSB                                          31
#define CPU_DPLL2_RANGE_LSB                                          31
#define CPU_DPLL2_RANGE_MASK                                         0x80000000
#define CPU_DPLL2_RANGE_GET(x)                                       (((x) & CPU_DPLL2_RANGE_MASK) >> CPU_DPLL2_RANGE_LSB)
#define CPU_DPLL2_RANGE_SET(x)                                       (((x) << CPU_DPLL2_RANGE_LSB) & CPU_DPLL2_RANGE_MASK)
#define CPU_DPLL2_RANGE_RESET                                        0x0 // 0
#define CPU_DPLL2_LOCAL_PLL_MSB                                      30
#define CPU_DPLL2_LOCAL_PLL_LSB                                      30
#define CPU_DPLL2_LOCAL_PLL_MASK                                     0x40000000
#define CPU_DPLL2_LOCAL_PLL_GET(x)                                   (((x) & CPU_DPLL2_LOCAL_PLL_MASK) >> CPU_DPLL2_LOCAL_PLL_LSB)
#define CPU_DPLL2_LOCAL_PLL_SET(x)                                   (((x) << CPU_DPLL2_LOCAL_PLL_LSB) & CPU_DPLL2_LOCAL_PLL_MASK)
#define CPU_DPLL2_LOCAL_PLL_RESET                                    0x0 // 0
#define CPU_DPLL2_KI_MSB                                             29
#define CPU_DPLL2_KI_LSB                                             26
#define CPU_DPLL2_KI_MASK                                            0x3c000000
#define CPU_DPLL2_KI_GET(x)                                          (((x) & CPU_DPLL2_KI_MASK) >> CPU_DPLL2_KI_LSB)
#define CPU_DPLL2_KI_SET(x)                                          (((x) << CPU_DPLL2_KI_LSB) & CPU_DPLL2_KI_MASK)
#define CPU_DPLL2_KI_RESET                                           0x6 // 6
#define CPU_DPLL2_KD_MSB                                             25
#define CPU_DPLL2_KD_LSB                                             19
#define CPU_DPLL2_KD_MASK                                            0x03f80000
#define CPU_DPLL2_KD_GET(x)                                          (((x) & CPU_DPLL2_KD_MASK) >> CPU_DPLL2_KD_LSB)
#define CPU_DPLL2_KD_SET(x)                                          (((x) << CPU_DPLL2_KD_LSB) & CPU_DPLL2_KD_MASK)
#define CPU_DPLL2_KD_RESET                                           0x7f // 127
#define CPU_DPLL2_EN_NEGTRIG_MSB                                     18
#define CPU_DPLL2_EN_NEGTRIG_LSB                                     18
#define CPU_DPLL2_EN_NEGTRIG_MASK                                    0x00040000
#define CPU_DPLL2_EN_NEGTRIG_GET(x)                                  (((x) & CPU_DPLL2_EN_NEGTRIG_MASK) >> CPU_DPLL2_EN_NEGTRIG_LSB)
#define CPU_DPLL2_EN_NEGTRIG_SET(x)                                  (((x) << CPU_DPLL2_EN_NEGTRIG_LSB) & CPU_DPLL2_EN_NEGTRIG_MASK)
#define CPU_DPLL2_EN_NEGTRIG_RESET                                   0x0 // 0
#define CPU_DPLL2_SEL_1SDM_MSB                                       17
#define CPU_DPLL2_SEL_1SDM_LSB                                       17
#define CPU_DPLL2_SEL_1SDM_MASK                                      0x00020000
#define CPU_DPLL2_SEL_1SDM_GET(x)                                    (((x) & CPU_DPLL2_SEL_1SDM_MASK) >> CPU_DPLL2_SEL_1SDM_LSB)
#define CPU_DPLL2_SEL_1SDM_SET(x)                                    (((x) << CPU_DPLL2_SEL_1SDM_LSB) & CPU_DPLL2_SEL_1SDM_MASK)
#define CPU_DPLL2_SEL_1SDM_RESET                                     0x0 // 0
#define CPU_DPLL2_PLL_PWD_MSB                                        16
#define CPU_DPLL2_PLL_PWD_LSB                                        16
#define CPU_DPLL2_PLL_PWD_MASK                                       0x00010000
#define CPU_DPLL2_PLL_PWD_GET(x)                                     (((x) & CPU_DPLL2_PLL_PWD_MASK) >> CPU_DPLL2_PLL_PWD_LSB)
#define CPU_DPLL2_PLL_PWD_SET(x)                                     (((x) << CPU_DPLL2_PLL_PWD_LSB) & CPU_DPLL2_PLL_PWD_MASK)
#define CPU_DPLL2_PLL_PWD_RESET                                      0x1 // 1
#define CPU_DPLL2_OUTDIV_MSB                                         15
#define CPU_DPLL2_OUTDIV_LSB                                         13
#define CPU_DPLL2_OUTDIV_MASK                                        0x0000e000
#define CPU_DPLL2_OUTDIV_GET(x)                                      (((x) & CPU_DPLL2_OUTDIV_MASK) >> CPU_DPLL2_OUTDIV_LSB)
#define CPU_DPLL2_OUTDIV_SET(x)                                      (((x) << CPU_DPLL2_OUTDIV_LSB) & CPU_DPLL2_OUTDIV_MASK)
#define CPU_DPLL2_OUTDIV_RESET                                       0x0 // 0
#define CPU_DPLL2_DELTA_MSB                                          12
#define CPU_DPLL2_DELTA_LSB                                          7
#define CPU_DPLL2_DELTA_MASK                                         0x00001f80
#define CPU_DPLL2_DELTA_GET(x)                                       (((x) & CPU_DPLL2_DELTA_MASK) >> CPU_DPLL2_DELTA_LSB)
#define CPU_DPLL2_DELTA_SET(x)                                       (((x) << CPU_DPLL2_DELTA_LSB) & CPU_DPLL2_DELTA_MASK)
#define CPU_DPLL2_DELTA_RESET                                        0x1e // 30
#define CPU_DPLL2_TESTINMSB_MSB                                      6
#define CPU_DPLL2_TESTINMSB_LSB                                      0
#define CPU_DPLL2_TESTINMSB_MASK                                     0x0000007f
#define CPU_DPLL2_TESTINMSB_GET(x)                                   (((x) & CPU_DPLL2_TESTINMSB_MASK) >> CPU_DPLL2_TESTINMSB_LSB)
#define CPU_DPLL2_TESTINMSB_SET(x)                                   (((x) << CPU_DPLL2_TESTINMSB_LSB) & CPU_DPLL2_TESTINMSB_MASK)
#define CPU_DPLL2_TESTINMSB_RESET                                    0x0 // 0
#define CPU_DPLL2_ADDRESS                                            0x18116f04

#define DDR_CTL_CONFIG_SRAM_TSEL_MSB                                 31
#define DDR_CTL_CONFIG_SRAM_TSEL_LSB                                 30
#define DDR_CTL_CONFIG_SRAM_TSEL_MASK                                0xc0000000
#define DDR_CTL_CONFIG_SRAM_TSEL_GET(x)                              (((x) & DDR_CTL_CONFIG_SRAM_TSEL_MASK) >> DDR_CTL_CONFIG_SRAM_TSEL_LSB)
#define DDR_CTL_CONFIG_SRAM_TSEL_SET(x)                              (((x) << DDR_CTL_CONFIG_SRAM_TSEL_LSB) & DDR_CTL_CONFIG_SRAM_TSEL_MASK)
#define DDR_CTL_CONFIG_SRAM_TSEL_RESET                               0x1 // 1
#define DDR_CTL_CONFIG_CLIENT_ACTIVITY_MSB                           29
#define DDR_CTL_CONFIG_CLIENT_ACTIVITY_LSB                           21
#define DDR_CTL_CONFIG_CLIENT_ACTIVITY_MASK                          0x3fe00000
#define DDR_CTL_CONFIG_CLIENT_ACTIVITY_GET(x)                        (((x) & DDR_CTL_CONFIG_CLIENT_ACTIVITY_MASK) >> DDR_CTL_CONFIG_CLIENT_ACTIVITY_LSB)
#define DDR_CTL_CONFIG_CLIENT_ACTIVITY_SET(x)                        (((x) << DDR_CTL_CONFIG_CLIENT_ACTIVITY_LSB) & DDR_CTL_CONFIG_CLIENT_ACTIVITY_MASK)
#define DDR_CTL_CONFIG_CLIENT_ACTIVITY_RESET                         0x0 // 0
#define DDR_CTL_CONFIG_GE0_SRAM_SYNC_MSB                             20
#define DDR_CTL_CONFIG_GE0_SRAM_SYNC_LSB                             20
#define DDR_CTL_CONFIG_GE0_SRAM_SYNC_MASK                            0x00100000
#define DDR_CTL_CONFIG_GE0_SRAM_SYNC_GET(x)                          (((x) & DDR_CTL_CONFIG_GE0_SRAM_SYNC_MASK) >> DDR_CTL_CONFIG_GE0_SRAM_SYNC_LSB)
#define DDR_CTL_CONFIG_GE0_SRAM_SYNC_SET(x)                          (((x) << DDR_CTL_CONFIG_GE0_SRAM_SYNC_LSB) & DDR_CTL_CONFIG_GE0_SRAM_SYNC_MASK)
#define DDR_CTL_CONFIG_GE0_SRAM_SYNC_RESET                           0x1 // 1
#define DDR_CTL_CONFIG_GE1_SRAM_SYNC_MSB                             19
#define DDR_CTL_CONFIG_GE1_SRAM_SYNC_LSB                             19
#define DDR_CTL_CONFIG_GE1_SRAM_SYNC_MASK                            0x00080000
#define DDR_CTL_CONFIG_GE1_SRAM_SYNC_GET(x)                          (((x) & DDR_CTL_CONFIG_GE1_SRAM_SYNC_MASK) >> DDR_CTL_CONFIG_GE1_SRAM_SYNC_LSB)
#define DDR_CTL_CONFIG_GE1_SRAM_SYNC_SET(x)                          (((x) << DDR_CTL_CONFIG_GE1_SRAM_SYNC_LSB) & DDR_CTL_CONFIG_GE1_SRAM_SYNC_MASK)
#define DDR_CTL_CONFIG_GE1_SRAM_SYNC_RESET                           0x1 // 1
#define DDR_CTL_CONFIG_USB_SRAM_SYNC_MSB                             18
#define DDR_CTL_CONFIG_USB_SRAM_SYNC_LSB                             18
#define DDR_CTL_CONFIG_USB_SRAM_SYNC_MASK                            0x00040000
#define DDR_CTL_CONFIG_USB_SRAM_SYNC_GET(x)                          (((x) & DDR_CTL_CONFIG_USB_SRAM_SYNC_MASK) >> DDR_CTL_CONFIG_USB_SRAM_SYNC_LSB)
#define DDR_CTL_CONFIG_USB_SRAM_SYNC_SET(x)                          (((x) << DDR_CTL_CONFIG_USB_SRAM_SYNC_LSB) & DDR_CTL_CONFIG_USB_SRAM_SYNC_MASK)
#define DDR_CTL_CONFIG_USB_SRAM_SYNC_RESET                           0x1 // 1
#define DDR_CTL_CONFIG_PCIE_SRAM_SYNC_MSB                            17
#define DDR_CTL_CONFIG_PCIE_SRAM_SYNC_LSB                            17
#define DDR_CTL_CONFIG_PCIE_SRAM_SYNC_MASK                           0x00020000
#define DDR_CTL_CONFIG_PCIE_SRAM_SYNC_GET(x)                         (((x) & DDR_CTL_CONFIG_PCIE_SRAM_SYNC_MASK) >> DDR_CTL_CONFIG_PCIE_SRAM_SYNC_LSB)
#define DDR_CTL_CONFIG_PCIE_SRAM_SYNC_SET(x)                         (((x) << DDR_CTL_CONFIG_PCIE_SRAM_SYNC_LSB) & DDR_CTL_CONFIG_PCIE_SRAM_SYNC_MASK)
#define DDR_CTL_CONFIG_PCIE_SRAM_SYNC_RESET                          0x1 // 1
#define DDR_CTL_CONFIG_WMAC_SRAM_SYNC_MSB                            16
#define DDR_CTL_CONFIG_WMAC_SRAM_SYNC_LSB                            16
#define DDR_CTL_CONFIG_WMAC_SRAM_SYNC_MASK                           0x00010000
#define DDR_CTL_CONFIG_WMAC_SRAM_SYNC_GET(x)                         (((x) & DDR_CTL_CONFIG_WMAC_SRAM_SYNC_MASK) >> DDR_CTL_CONFIG_WMAC_SRAM_SYNC_LSB)
#define DDR_CTL_CONFIG_WMAC_SRAM_SYNC_SET(x)                         (((x) << DDR_CTL_CONFIG_WMAC_SRAM_SYNC_LSB) & DDR_CTL_CONFIG_WMAC_SRAM_SYNC_MASK)
#define DDR_CTL_CONFIG_WMAC_SRAM_SYNC_RESET                          0x1 // 1
#define DDR_CTL_CONFIG_MISC_SRC1_SRAM_SYNC_MSB                       15
#define DDR_CTL_CONFIG_MISC_SRC1_SRAM_SYNC_LSB                       15
#define DDR_CTL_CONFIG_MISC_SRC1_SRAM_SYNC_MASK                      0x00008000
#define DDR_CTL_CONFIG_MISC_SRC1_SRAM_SYNC_GET(x)                    (((x) & DDR_CTL_CONFIG_MISC_SRC1_SRAM_SYNC_MASK) >> DDR_CTL_CONFIG_MISC_SRC1_SRAM_SYNC_LSB)
#define DDR_CTL_CONFIG_MISC_SRC1_SRAM_SYNC_SET(x)                    (((x) << DDR_CTL_CONFIG_MISC_SRC1_SRAM_SYNC_LSB) & DDR_CTL_CONFIG_MISC_SRC1_SRAM_SYNC_MASK)
#define DDR_CTL_CONFIG_MISC_SRC1_SRAM_SYNC_RESET                     0x1 // 1
#define DDR_CTL_CONFIG_MISC_SRC2_SRAM_SYNC_MSB                       14
#define DDR_CTL_CONFIG_MISC_SRC2_SRAM_SYNC_LSB                       14
#define DDR_CTL_CONFIG_MISC_SRC2_SRAM_SYNC_MASK                      0x00004000
#define DDR_CTL_CONFIG_MISC_SRC2_SRAM_SYNC_GET(x)                    (((x) & DDR_CTL_CONFIG_MISC_SRC2_SRAM_SYNC_MASK) >> DDR_CTL_CONFIG_MISC_SRC2_SRAM_SYNC_LSB)
#define DDR_CTL_CONFIG_MISC_SRC2_SRAM_SYNC_SET(x)                    (((x) << DDR_CTL_CONFIG_MISC_SRC2_SRAM_SYNC_LSB) & DDR_CTL_CONFIG_MISC_SRC2_SRAM_SYNC_MASK)
#define DDR_CTL_CONFIG_MISC_SRC2_SRAM_SYNC_RESET                     0x1 // 1
#define DDR_CTL_CONFIG_SPARE_MSB                                     13
#define DDR_CTL_CONFIG_SPARE_LSB                                     7
#define DDR_CTL_CONFIG_SPARE_MASK                                    0x00003f80
#define DDR_CTL_CONFIG_SPARE_GET(x)                                  (((x) & DDR_CTL_CONFIG_SPARE_MASK) >> DDR_CTL_CONFIG_SPARE_LSB)
#define DDR_CTL_CONFIG_SPARE_SET(x)                                  (((x) << DDR_CTL_CONFIG_SPARE_LSB) & DDR_CTL_CONFIG_SPARE_MASK)
#define DDR_CTL_CONFIG_SPARE_RESET                                   0x0 // 0
#define DDR_CTL_CONFIG_PAD_DDR2_SEL_MSB                              6
#define DDR_CTL_CONFIG_PAD_DDR2_SEL_LSB                              6
#define DDR_CTL_CONFIG_PAD_DDR2_SEL_MASK                             0x00000040
#define DDR_CTL_CONFIG_PAD_DDR2_SEL_GET(x)                           (((x) & DDR_CTL_CONFIG_PAD_DDR2_SEL_MASK) >> DDR_CTL_CONFIG_PAD_DDR2_SEL_LSB)
#define DDR_CTL_CONFIG_PAD_DDR2_SEL_SET(x)                           (((x) << DDR_CTL_CONFIG_PAD_DDR2_SEL_LSB) & DDR_CTL_CONFIG_PAD_DDR2_SEL_MASK)
#define DDR_CTL_CONFIG_PAD_DDR2_SEL_RESET                            0x0 // 0
#define DDR_CTL_CONFIG_GATE_SRAM_CLK_MSB                             4
#define DDR_CTL_CONFIG_GATE_SRAM_CLK_LSB                             4
#define DDR_CTL_CONFIG_GATE_SRAM_CLK_MASK                            0x00000010
#define DDR_CTL_CONFIG_GATE_SRAM_CLK_GET(x)                          (((x) & DDR_CTL_CONFIG_GATE_SRAM_CLK_MASK) >> DDR_CTL_CONFIG_GATE_SRAM_CLK_LSB)
#define DDR_CTL_CONFIG_GATE_SRAM_CLK_SET(x)                          (((x) << DDR_CTL_CONFIG_GATE_SRAM_CLK_LSB) & DDR_CTL_CONFIG_GATE_SRAM_CLK_MASK)
#define DDR_CTL_CONFIG_GATE_SRAM_CLK_RESET                           0x0 // 0
#define DDR_CTL_CONFIG_SRAM_REQ_ACK_MSB                              3
#define DDR_CTL_CONFIG_SRAM_REQ_ACK_LSB                              3
#define DDR_CTL_CONFIG_SRAM_REQ_ACK_MASK                             0x00000008
#define DDR_CTL_CONFIG_SRAM_REQ_ACK_GET(x)                           (((x) & DDR_CTL_CONFIG_SRAM_REQ_ACK_MASK) >> DDR_CTL_CONFIG_SRAM_REQ_ACK_LSB)
#define DDR_CTL_CONFIG_SRAM_REQ_ACK_SET(x)                           (((x) << DDR_CTL_CONFIG_SRAM_REQ_ACK_LSB) & DDR_CTL_CONFIG_SRAM_REQ_ACK_MASK)
#define DDR_CTL_CONFIG_SRAM_REQ_ACK_RESET                            0x0 // 0
#define DDR_CTL_CONFIG_CPU_DDR_SYNC_MSB                              2
#define DDR_CTL_CONFIG_CPU_DDR_SYNC_LSB                              2
#define DDR_CTL_CONFIG_CPU_DDR_SYNC_MASK                             0x00000004
#define DDR_CTL_CONFIG_CPU_DDR_SYNC_GET(x)                           (((x) & DDR_CTL_CONFIG_CPU_DDR_SYNC_MASK) >> DDR_CTL_CONFIG_CPU_DDR_SYNC_LSB)
#define DDR_CTL_CONFIG_CPU_DDR_SYNC_SET(x)                           (((x) << DDR_CTL_CONFIG_CPU_DDR_SYNC_LSB) & DDR_CTL_CONFIG_CPU_DDR_SYNC_MASK)
#define DDR_CTL_CONFIG_CPU_DDR_SYNC_RESET                            0x0 // 0
#define DDR_CTL_CONFIG_HALF_WIDTH_MSB                                1
#define DDR_CTL_CONFIG_HALF_WIDTH_LSB                                1
#define DDR_CTL_CONFIG_HALF_WIDTH_MASK                               0x00000002
#define DDR_CTL_CONFIG_HALF_WIDTH_GET(x)                             (((x) & DDR_CTL_CONFIG_HALF_WIDTH_MASK) >> DDR_CTL_CONFIG_HALF_WIDTH_LSB)
#define DDR_CTL_CONFIG_HALF_WIDTH_SET(x)                             (((x) << DDR_CTL_CONFIG_HALF_WIDTH_LSB) & DDR_CTL_CONFIG_HALF_WIDTH_MASK)
#define DDR_CTL_CONFIG_HALF_WIDTH_RESET                              0x1 // 1
#define DDR_CTL_CONFIG_SDRAM_MODE_EN_MSB                             0
#define DDR_CTL_CONFIG_SDRAM_MODE_EN_LSB                             0
#define DDR_CTL_CONFIG_SDRAM_MODE_EN_MASK                            0x00000001
#define DDR_CTL_CONFIG_SDRAM_MODE_EN_GET(x)                          (((x) & DDR_CTL_CONFIG_SDRAM_MODE_EN_MASK) >> DDR_CTL_CONFIG_SDRAM_MODE_EN_LSB)
#define DDR_CTL_CONFIG_SDRAM_MODE_EN_SET(x)                          (((x) << DDR_CTL_CONFIG_SDRAM_MODE_EN_LSB) & DDR_CTL_CONFIG_SDRAM_MODE_EN_MASK)
#define DDR_CTL_CONFIG_SDRAM_MODE_EN_RESET                           0x0 // 0
#define DDR_CTL_CONFIG_ADDRESS                                       0x18000108

#define ETH_SGMII_SERDES_EN_LOCK_DETECT_MSB                          2
#define ETH_SGMII_SERDES_EN_LOCK_DETECT_LSB                          2
#define ETH_SGMII_SERDES_EN_LOCK_DETECT_MASK                         0x00000004
#define ETH_SGMII_SERDES_EN_LOCK_DETECT_GET(x)                       (((x) & ETH_SGMII_SERDES_EN_LOCK_DETECT_MASK) >> ETH_SGMII_SERDES_EN_LOCK_DETECT_LSB)
#define ETH_SGMII_SERDES_EN_LOCK_DETECT_SET(x)                       (((x) << ETH_SGMII_SERDES_EN_LOCK_DETECT_LSB) & ETH_SGMII_SERDES_EN_LOCK_DETECT_MASK)
#define ETH_SGMII_SERDES_EN_LOCK_DETECT_RESET                        0x0 // 0
#define ETH_SGMII_SERDES_PLL_REFCLK_SEL_MSB                          1
#define ETH_SGMII_SERDES_PLL_REFCLK_SEL_LSB                          1
#define ETH_SGMII_SERDES_PLL_REFCLK_SEL_MASK                         0x00000002
#define ETH_SGMII_SERDES_PLL_REFCLK_SEL_GET(x)                       (((x) & ETH_SGMII_SERDES_PLL_REFCLK_SEL_MASK) >> ETH_SGMII_SERDES_PLL_REFCLK_SEL_LSB)
#define ETH_SGMII_SERDES_PLL_REFCLK_SEL_SET(x)                       (((x) << ETH_SGMII_SERDES_PLL_REFCLK_SEL_LSB) & ETH_SGMII_SERDES_PLL_REFCLK_SEL_MASK)
#define ETH_SGMII_SERDES_PLL_REFCLK_SEL_RESET                        0x0 // 0
#define ETH_SGMII_SERDES_EN_PLL_MSB                                  0
#define ETH_SGMII_SERDES_EN_PLL_LSB                                  0
#define ETH_SGMII_SERDES_EN_PLL_MASK                                 0x00000001
#define ETH_SGMII_SERDES_EN_PLL_GET(x)                               (((x) & ETH_SGMII_SERDES_EN_PLL_MASK) >> ETH_SGMII_SERDES_EN_PLL_LSB)
#define ETH_SGMII_SERDES_EN_PLL_SET(x)                               (((x) << ETH_SGMII_SERDES_EN_PLL_LSB) & ETH_SGMII_SERDES_EN_PLL_MASK)
#define ETH_SGMII_SERDES_EN_PLL_RESET                                0x1 // 1
#define ETH_SGMII_SERDES_ADDRESS                                     0x1805004c

#define GMAC_MII0_CTRL                                               0x18070000

#define SGMII_SERDES_VCO_REG_MSB                                     30
#define SGMII_SERDES_VCO_REG_LSB                                     27
#define SGMII_SERDES_VCO_REG_MASK                                    0x78000000
#define SGMII_SERDES_VCO_REG_GET(x)                                  (((x) & SGMII_SERDES_VCO_REG_MASK) >> SGMII_SERDES_VCO_REG_LSB)
#define SGMII_SERDES_VCO_REG_SET(x)                                  (((x) << SGMII_SERDES_VCO_REG_LSB) & SGMII_SERDES_VCO_REG_MASK)
#define SGMII_SERDES_VCO_REG_RESET                                   0x3 // 3
#define SGMII_SERDES_RES_CALIBRATION_MSB                             26
#define SGMII_SERDES_RES_CALIBRATION_LSB                             23
#define SGMII_SERDES_RES_CALIBRATION_MASK                            0x07800000
#define SGMII_SERDES_RES_CALIBRATION_GET(x)                          (((x) & SGMII_SERDES_RES_CALIBRATION_MASK) >> SGMII_SERDES_RES_CALIBRATION_LSB)
#define SGMII_SERDES_RES_CALIBRATION_SET(x)                          (((x) << SGMII_SERDES_RES_CALIBRATION_LSB) & SGMII_SERDES_RES_CALIBRATION_MASK)
#define SGMII_SERDES_RES_CALIBRATION_RESET                           0x0 // 0
#define SGMII_SERDES_FIBER_MODE_MSB                                  21
#define SGMII_SERDES_FIBER_MODE_LSB                                  20
#define SGMII_SERDES_FIBER_MODE_MASK                                 0x00300000
#define SGMII_SERDES_FIBER_MODE_GET(x)                               (((x) & SGMII_SERDES_FIBER_MODE_MASK) >> SGMII_SERDES_FIBER_MODE_LSB)
#define SGMII_SERDES_FIBER_MODE_SET(x)                               (((x) << SGMII_SERDES_FIBER_MODE_LSB) & SGMII_SERDES_FIBER_MODE_MASK)
#define SGMII_SERDES_FIBER_MODE_RESET                                0x0 // 0
#define SGMII_SERDES_THRESHOLD_CTRL_MSB                              19
#define SGMII_SERDES_THRESHOLD_CTRL_LSB                              18
#define SGMII_SERDES_THRESHOLD_CTRL_MASK                             0x000c0000
#define SGMII_SERDES_THRESHOLD_CTRL_GET(x)                           (((x) & SGMII_SERDES_THRESHOLD_CTRL_MASK) >> SGMII_SERDES_THRESHOLD_CTRL_LSB)
#define SGMII_SERDES_THRESHOLD_CTRL_SET(x)                           (((x) << SGMII_SERDES_THRESHOLD_CTRL_LSB) & SGMII_SERDES_THRESHOLD_CTRL_MASK)
#define SGMII_SERDES_THRESHOLD_CTRL_RESET                            0x0 // 0
#define SGMII_SERDES_FIBER_SDO_MSB                                   17
#define SGMII_SERDES_FIBER_SDO_LSB                                   17
#define SGMII_SERDES_FIBER_SDO_MASK                                  0x00020000
#define SGMII_SERDES_FIBER_SDO_GET(x)                                (((x) & SGMII_SERDES_FIBER_SDO_MASK) >> SGMII_SERDES_FIBER_SDO_LSB)
#define SGMII_SERDES_FIBER_SDO_SET(x)                                (((x) << SGMII_SERDES_FIBER_SDO_LSB) & SGMII_SERDES_FIBER_SDO_MASK)
#define SGMII_SERDES_FIBER_SDO_RESET                                 0x0 // 0
#define SGMII_SERDES_EN_SIGNAL_DETECT_MSB                            16
#define SGMII_SERDES_EN_SIGNAL_DETECT_LSB                            16
#define SGMII_SERDES_EN_SIGNAL_DETECT_MASK                           0x00010000
#define SGMII_SERDES_EN_SIGNAL_DETECT_GET(x)                         (((x) & SGMII_SERDES_EN_SIGNAL_DETECT_MASK) >> SGMII_SERDES_EN_SIGNAL_DETECT_LSB)
#define SGMII_SERDES_EN_SIGNAL_DETECT_SET(x)                         (((x) << SGMII_SERDES_EN_SIGNAL_DETECT_LSB) & SGMII_SERDES_EN_SIGNAL_DETECT_MASK)
#define SGMII_SERDES_EN_SIGNAL_DETECT_RESET                          0x1 // 1
#define SGMII_SERDES_LOCK_DETECT_STATUS_MSB                          15
#define SGMII_SERDES_LOCK_DETECT_STATUS_LSB                          15
#define SGMII_SERDES_LOCK_DETECT_STATUS_MASK                         0x00008000
#define SGMII_SERDES_LOCK_DETECT_STATUS_GET(x)                       (((x) & SGMII_SERDES_LOCK_DETECT_STATUS_MASK) >> SGMII_SERDES_LOCK_DETECT_STATUS_LSB)
#define SGMII_SERDES_LOCK_DETECT_STATUS_SET(x)                       (((x) << SGMII_SERDES_LOCK_DETECT_STATUS_LSB) & SGMII_SERDES_LOCK_DETECT_STATUS_MASK)
#define SGMII_SERDES_LOCK_DETECT_STATUS_RESET                        0x0 // 0
#define SGMII_SERDES_SPARE0_MSB                                      14
#define SGMII_SERDES_SPARE0_LSB                                      11
#define SGMII_SERDES_SPARE0_MASK                                     0x00007800
#define SGMII_SERDES_SPARE0_GET(x)                                   (((x) & SGMII_SERDES_SPARE0_MASK) >> SGMII_SERDES_SPARE0_LSB)
#define SGMII_SERDES_SPARE0_SET(x)                                   (((x) << SGMII_SERDES_SPARE0_LSB) & SGMII_SERDES_SPARE0_MASK)
#define SGMII_SERDES_SPARE0_RESET                                    0x0 // 0
#define SGMII_SERDES_VCO_SLOW_MSB                                    10
#define SGMII_SERDES_VCO_SLOW_LSB                                    10
#define SGMII_SERDES_VCO_SLOW_MASK                                   0x00000400
#define SGMII_SERDES_VCO_SLOW_GET(x)                                 (((x) & SGMII_SERDES_VCO_SLOW_MASK) >> SGMII_SERDES_VCO_SLOW_LSB)
#define SGMII_SERDES_VCO_SLOW_SET(x)                                 (((x) << SGMII_SERDES_VCO_SLOW_LSB) & SGMII_SERDES_VCO_SLOW_MASK)
#define SGMII_SERDES_VCO_SLOW_RESET                                  0x0 // 0
#define SGMII_SERDES_VCO_FAST_MSB                                    9
#define SGMII_SERDES_VCO_FAST_LSB                                    9
#define SGMII_SERDES_VCO_FAST_MASK                                   0x00000200
#define SGMII_SERDES_VCO_FAST_GET(x)                                 (((x) & SGMII_SERDES_VCO_FAST_MASK) >> SGMII_SERDES_VCO_FAST_LSB)
#define SGMII_SERDES_VCO_FAST_SET(x)                                 (((x) << SGMII_SERDES_VCO_FAST_LSB) & SGMII_SERDES_VCO_FAST_MASK)
#define SGMII_SERDES_VCO_FAST_RESET                                  0x0 // 0
#define SGMII_SERDES_PLL_BW_MSB                                      8
#define SGMII_SERDES_PLL_BW_LSB                                      8
#define SGMII_SERDES_PLL_BW_MASK                                     0x00000100
#define SGMII_SERDES_PLL_BW_GET(x)                                   (((x) & SGMII_SERDES_PLL_BW_MASK) >> SGMII_SERDES_PLL_BW_LSB)
#define SGMII_SERDES_PLL_BW_SET(x)                                   (((x) << SGMII_SERDES_PLL_BW_LSB) & SGMII_SERDES_PLL_BW_MASK)
#define SGMII_SERDES_PLL_BW_RESET                                    0x1 // 1
#define SGMII_SERDES_TX_IMPEDANCE_MSB                                7
#define SGMII_SERDES_TX_IMPEDANCE_LSB                                7
#define SGMII_SERDES_TX_IMPEDANCE_MASK                               0x00000080
#define SGMII_SERDES_TX_IMPEDANCE_GET(x)                             (((x) & SGMII_SERDES_TX_IMPEDANCE_MASK) >> SGMII_SERDES_TX_IMPEDANCE_LSB)
#define SGMII_SERDES_TX_IMPEDANCE_SET(x)                             (((x) << SGMII_SERDES_TX_IMPEDANCE_LSB) & SGMII_SERDES_TX_IMPEDANCE_MASK)
#define SGMII_SERDES_TX_IMPEDANCE_RESET                              0x0 // 0
#define SGMII_SERDES_TX_DR_CTRL_MSB                                  6
#define SGMII_SERDES_TX_DR_CTRL_LSB                                  4
#define SGMII_SERDES_TX_DR_CTRL_MASK                                 0x00000070
#define SGMII_SERDES_TX_DR_CTRL_GET(x)                               (((x) & SGMII_SERDES_TX_DR_CTRL_MASK) >> SGMII_SERDES_TX_DR_CTRL_LSB)
#define SGMII_SERDES_TX_DR_CTRL_SET(x)                               (((x) << SGMII_SERDES_TX_DR_CTRL_LSB) & SGMII_SERDES_TX_DR_CTRL_MASK)
#define SGMII_SERDES_TX_DR_CTRL_RESET                                0x1 // 1
#define SGMII_SERDES_HALF_TX_MSB                                     3
#define SGMII_SERDES_HALF_TX_LSB                                     3
#define SGMII_SERDES_HALF_TX_MASK                                    0x00000008
#define SGMII_SERDES_HALF_TX_GET(x)                                  (((x) & SGMII_SERDES_HALF_TX_MASK) >> SGMII_SERDES_HALF_TX_LSB)
#define SGMII_SERDES_HALF_TX_SET(x)                                  (((x) << SGMII_SERDES_HALF_TX_LSB) & SGMII_SERDES_HALF_TX_MASK)
#define SGMII_SERDES_HALF_TX_RESET                                   0x0 // 0
#define SGMII_SERDES_CDR_BW_MSB                                      2
#define SGMII_SERDES_CDR_BW_LSB                                      1
#define SGMII_SERDES_CDR_BW_MASK                                     0x00000006
#define SGMII_SERDES_CDR_BW_GET(x)                                   (((x) & SGMII_SERDES_CDR_BW_MASK) >> SGMII_SERDES_CDR_BW_LSB)
#define SGMII_SERDES_CDR_BW_SET(x)                                   (((x) << SGMII_SERDES_CDR_BW_LSB) & SGMII_SERDES_CDR_BW_MASK)
#define SGMII_SERDES_CDR_BW_RESET                                    0x3 // 3
#define SGMII_SERDES_RX_IMPEDANCE_MSB                                0
#define SGMII_SERDES_RX_IMPEDANCE_LSB                                0
#define SGMII_SERDES_RX_IMPEDANCE_MASK                               0x00000001
#define SGMII_SERDES_RX_IMPEDANCE_GET(x)                             (((x) & SGMII_SERDES_RX_IMPEDANCE_MASK) >> SGMII_SERDES_RX_IMPEDANCE_LSB)
#define SGMII_SERDES_RX_IMPEDANCE_SET(x)                             (((x) << SGMII_SERDES_RX_IMPEDANCE_LSB) & SGMII_SERDES_RX_IMPEDANCE_MASK)
#define SGMII_SERDES_RX_IMPEDANCE_RESET                              0x0 // 0
#define SGMII_SERDES_ADDRESS                                         0x18070018

#define PCIERC_RC_REG_0_ADDRESS                                      0x18250000

#define PCIE2_RESET_EP_RESET_L_MSB                                   2
#define PCIE2_RESET_EP_RESET_L_LSB                                   2
#define PCIE2_RESET_EP_RESET_L_MASK                                  0x00000004
#define PCIE2_RESET_EP_RESET_L_GET(x)                                (((x) & PCIE2_RESET_EP_RESET_L_MASK) >> PCIE2_RESET_EP_RESET_L_LSB)
#define PCIE2_RESET_EP_RESET_L_SET(x)                                (((x) << PCIE2_RESET_EP_RESET_L_LSB) & PCIE2_RESET_EP_RESET_L_MASK)
#define PCIE2_RESET_EP_RESET_L_RESET                                 0x0 // 0
#define PCIE2_RESET_LINK_REQ_RESET_MSB                               1
#define PCIE2_RESET_LINK_REQ_RESET_LSB                               1
#define PCIE2_RESET_LINK_REQ_RESET_MASK                              0x00000002
#define PCIE2_RESET_LINK_REQ_RESET_GET(x)                            (((x) & PCIE2_RESET_LINK_REQ_RESET_MASK) >> PCIE2_RESET_LINK_REQ_RESET_LSB)
#define PCIE2_RESET_LINK_REQ_RESET_SET(x)                            (((x) << PCIE2_RESET_LINK_REQ_RESET_LSB) & PCIE2_RESET_LINK_REQ_RESET_MASK)
#define PCIE2_RESET_LINK_REQ_RESET_RESET                             0x0 // 0
#define PCIE2_RESET_LINK_UP_MSB                                      0
#define PCIE2_RESET_LINK_UP_LSB                                      0
#define PCIE2_RESET_LINK_UP_MASK                                     0x00000001
#define PCIE2_RESET_LINK_UP_GET(x)                                   (((x) & PCIE2_RESET_LINK_UP_MASK) >> PCIE2_RESET_LINK_UP_LSB)
#define PCIE2_RESET_LINK_UP_SET(x)                                   (((x) << PCIE2_RESET_LINK_UP_LSB) & PCIE2_RESET_LINK_UP_MASK)
#define PCIE2_RESET_LINK_UP_RESET                                    0x0 // 0
#define PCIE2_RESET_ADDRESS                                          0x18280018

#define PCIE2_APP_CFG_TYPE_MSB                                       21
#define PCIE2_APP_CFG_TYPE_LSB                                       20
#define PCIE2_APP_CFG_TYPE_MASK                                      0x00300000
#define PCIE2_APP_CFG_TYPE_GET(x)                                    (((x) & PCIE2_APP_CFG_TYPE_MASK) >> PCIE2_APP_CFG_TYPE_LSB)
#define PCIE2_APP_CFG_TYPE_SET(x)                                    (((x) << PCIE2_APP_CFG_TYPE_LSB) & PCIE2_APP_CFG_TYPE_MASK)
#define PCIE2_APP_CFG_TYPE_RESET                                     0x0 // 0
#define PCIE2_APP_PCIE2_BAR_MSN_MSB                                   19
#define PCIE2_APP_PCIE2_BAR_MSN_LSB                                   16
#define PCIE2_APP_PCIE2_BAR_MSN_MASK                                  0x000f0000
#define PCIE2_APP_PCIE2_BAR_MSN_GET(x)                                (((x) & PCIE2_APP_PCIE2_BAR_MSN_MASK) >> PCIE2_APP_PCIE2_BAR_MSN_LSB)
#define PCIE2_APP_PCIE2_BAR_MSN_SET(x)                                (((x) << PCIE2_APP_PCIE2_BAR_MSN_LSB) & PCIE2_APP_PCIE2_BAR_MSN_MASK)
#define PCIE2_APP_PCIE2_BAR_MSN_RESET                                 0x1 // 1
#define PCIE2_APP_CFG_BE_MSB                                         15
#define PCIE2_APP_CFG_BE_LSB                                         12
#define PCIE2_APP_CFG_BE_MASK                                        0x0000f000
#define PCIE2_APP_CFG_BE_GET(x)                                      (((x) & PCIE2_APP_CFG_BE_MASK) >> PCIE2_APP_CFG_BE_LSB)
#define PCIE2_APP_CFG_BE_SET(x)                                      (((x) << PCIE2_APP_CFG_BE_LSB) & PCIE2_APP_CFG_BE_MASK)
#define PCIE2_APP_CFG_BE_RESET                                       0xf // 15
#define PCIE2_APP_SLV_RESP_ERR_MAP_MSB                               11
#define PCIE2_APP_SLV_RESP_ERR_MAP_LSB                               6
#define PCIE2_APP_SLV_RESP_ERR_MAP_MASK                              0x00000fc0
#define PCIE2_APP_SLV_RESP_ERR_MAP_GET(x)                            (((x) & PCIE2_APP_SLV_RESP_ERR_MAP_MASK) >> PCIE2_APP_SLV_RESP_ERR_MAP_LSB)
#define PCIE2_APP_SLV_RESP_ERR_MAP_SET(x)                            (((x) << PCIE2_APP_SLV_RESP_ERR_MAP_LSB) & PCIE2_APP_SLV_RESP_ERR_MAP_MASK)
#define PCIE2_APP_SLV_RESP_ERR_MAP_RESET                             0x3f // 63
#define PCIE2_APP_MSTR_RESP_ERR_MAP_MSB                              5
#define PCIE2_APP_MSTR_RESP_ERR_MAP_LSB                              4
#define PCIE2_APP_MSTR_RESP_ERR_MAP_MASK                             0x00000030
#define PCIE2_APP_MSTR_RESP_ERR_MAP_GET(x)                           (((x) & PCIE2_APP_MSTR_RESP_ERR_MAP_MASK) >> PCIE2_APP_MSTR_RESP_ERR_MAP_LSB)
#define PCIE2_APP_MSTR_RESP_ERR_MAP_SET(x)                           (((x) << PCIE2_APP_MSTR_RESP_ERR_MAP_LSB) & PCIE2_APP_MSTR_RESP_ERR_MAP_MASK)
#define PCIE2_APP_MSTR_RESP_ERR_MAP_RESET                            0x0 // 0
#define PCIE2_APP_INIT_RST_MSB                                       3
#define PCIE2_APP_INIT_RST_LSB                                       3
#define PCIE2_APP_INIT_RST_MASK                                      0x00000008
#define PCIE2_APP_INIT_RST_GET(x)                                    (((x) & PCIE2_APP_INIT_RST_MASK) >> PCIE2_APP_INIT_RST_LSB)
#define PCIE2_APP_INIT_RST_SET(x)                                    (((x) << PCIE2_APP_INIT_RST_LSB) & PCIE2_APP_INIT_RST_MASK)
#define PCIE2_APP_INIT_RST_RESET                                     0x0 // 0
#define PCIE2_APP_PM_XMT_TURNOFF_MSB                                 2
#define PCIE2_APP_PM_XMT_TURNOFF_LSB                                 2
#define PCIE2_APP_PM_XMT_TURNOFF_MASK                                0x00000004
#define PCIE2_APP_PM_XMT_TURNOFF_GET(x)                              (((x) & PCIE2_APP_PM_XMT_TURNOFF_MASK) >> PCIE2_APP_PM_XMT_TURNOFF_LSB)
#define PCIE2_APP_PM_XMT_TURNOFF_SET(x)                              (((x) << PCIE2_APP_PM_XMT_TURNOFF_LSB) & PCIE2_APP_PM_XMT_TURNOFF_MASK)
#define PCIE2_APP_PM_XMT_TURNOFF_RESET                               0x0 // 0
#define PCIE2_APP_UNLOCK_MSG_MSB                                     1
#define PCIE2_APP_UNLOCK_MSG_LSB                                     1
#define PCIE2_APP_UNLOCK_MSG_MASK                                    0x00000002
#define PCIE2_APP_UNLOCK_MSG_GET(x)                                  (((x) & PCIE2_APP_UNLOCK_MSG_MASK) >> PCIE2_APP_UNLOCK_MSG_LSB)
#define PCIE2_APP_UNLOCK_MSG_SET(x)                                  (((x) << PCIE2_APP_UNLOCK_MSG_LSB) & PCIE2_APP_UNLOCK_MSG_MASK)
#define PCIE2_APP_UNLOCK_MSG_RESET                                   0x0 // 0
#define PCIE2_APP_LTSSM_ENABLE_MSB                                   0
#define PCIE2_APP_LTSSM_ENABLE_LSB                                   0
#define PCIE2_APP_LTSSM_ENABLE_MASK                                  0x00000001
#define PCIE2_APP_LTSSM_ENABLE_GET(x)                                (((x) & PCIE2_APP_LTSSM_ENABLE_MASK) >> PCIE2_APP_LTSSM_ENABLE_LSB)
#define PCIE2_APP_LTSSM_ENABLE_SET(x)                                (((x) << PCIE2_APP_LTSSM_ENABLE_LSB) & PCIE2_APP_LTSSM_ENABLE_MASK)
#define PCIE2_APP_LTSSM_ENABLE_RESET                                 0x0 // 0
#define PCIE2_APP_ADDRESS                                            0x18280000

#define PCIE_APP_CFG_TYPE_MSB                                        21
#define PCIE_APP_CFG_TYPE_LSB                                        20
#define PCIE_APP_CFG_TYPE_MASK                                       0x00300000
#define PCIE_APP_CFG_TYPE_GET(x)                                     (((x) & PCIE_APP_CFG_TYPE_MASK) >> PCIE_APP_CFG_TYPE_LSB)
#define PCIE_APP_CFG_TYPE_SET(x)                                     (((x) << PCIE_APP_CFG_TYPE_LSB) & PCIE_APP_CFG_TYPE_MASK)
#define PCIE_APP_CFG_TYPE_RESET                                      0x0 // 0
#define PCIE_APP_PCIE_BAR_MSN_MSB                                    19
#define PCIE_APP_PCIE_BAR_MSN_LSB                                    16
#define PCIE_APP_PCIE_BAR_MSN_MASK                                   0x000f0000
#define PCIE_APP_PCIE_BAR_MSN_GET(x)                                 (((x) & PCIE_APP_PCIE_BAR_MSN_MASK) >> PCIE_APP_PCIE_BAR_MSN_LSB)
#define PCIE_APP_PCIE_BAR_MSN_SET(x)                                 (((x) << PCIE_APP_PCIE_BAR_MSN_LSB) & PCIE_APP_PCIE_BAR_MSN_MASK)
#define PCIE_APP_PCIE_BAR_MSN_RESET                                  0x1 // 1
#define PCIE_APP_CFG_BE_MSB                                          15
#define PCIE_APP_CFG_BE_LSB                                          12
#define PCIE_APP_CFG_BE_MASK                                         0x0000f000
#define PCIE_APP_CFG_BE_GET(x)                                       (((x) & PCIE_APP_CFG_BE_MASK) >> PCIE_APP_CFG_BE_LSB)
#define PCIE_APP_CFG_BE_SET(x)                                       (((x) << PCIE_APP_CFG_BE_LSB) & PCIE_APP_CFG_BE_MASK)
#define PCIE_APP_CFG_BE_RESET                                        0xf // 15
#define PCIE_APP_SLV_RESP_ERR_MAP_MSB                                11
#define PCIE_APP_SLV_RESP_ERR_MAP_LSB                                6
#define PCIE_APP_SLV_RESP_ERR_MAP_MASK                               0x00000fc0
#define PCIE_APP_SLV_RESP_ERR_MAP_GET(x)                             (((x) & PCIE_APP_SLV_RESP_ERR_MAP_MASK) >> PCIE_APP_SLV_RESP_ERR_MAP_LSB)
#define PCIE_APP_SLV_RESP_ERR_MAP_SET(x)                             (((x) << PCIE_APP_SLV_RESP_ERR_MAP_LSB) & PCIE_APP_SLV_RESP_ERR_MAP_MASK)
#define PCIE_APP_SLV_RESP_ERR_MAP_RESET                              0x3f // 63
#define PCIE_APP_MSTR_RESP_ERR_MAP_MSB                               5
#define PCIE_APP_MSTR_RESP_ERR_MAP_LSB                               4
#define PCIE_APP_MSTR_RESP_ERR_MAP_MASK                              0x00000030
#define PCIE_APP_MSTR_RESP_ERR_MAP_GET(x)                            (((x) & PCIE_APP_MSTR_RESP_ERR_MAP_MASK) >> PCIE_APP_MSTR_RESP_ERR_MAP_LSB)
#define PCIE_APP_MSTR_RESP_ERR_MAP_SET(x)                            (((x) << PCIE_APP_MSTR_RESP_ERR_MAP_LSB) & PCIE_APP_MSTR_RESP_ERR_MAP_MASK)
#define PCIE_APP_MSTR_RESP_ERR_MAP_RESET                             0x0 // 0
#define PCIE_APP_INIT_RST_MSB                                        3
#define PCIE_APP_INIT_RST_LSB                                        3
#define PCIE_APP_INIT_RST_MASK                                       0x00000008
#define PCIE_APP_INIT_RST_GET(x)                                     (((x) & PCIE_APP_INIT_RST_MASK) >> PCIE_APP_INIT_RST_LSB)
#define PCIE_APP_INIT_RST_SET(x)                                     (((x) << PCIE_APP_INIT_RST_LSB) & PCIE_APP_INIT_RST_MASK)
#define PCIE_APP_INIT_RST_RESET                                      0x0 // 0
#define PCIE_APP_PM_XMT_TURNOFF_MSB                                  2
#define PCIE_APP_PM_XMT_TURNOFF_LSB                                  2
#define PCIE_APP_PM_XMT_TURNOFF_MASK                                 0x00000004
#define PCIE_APP_PM_XMT_TURNOFF_GET(x)                               (((x) & PCIE_APP_PM_XMT_TURNOFF_MASK) >> PCIE_APP_PM_XMT_TURNOFF_LSB)
#define PCIE_APP_PM_XMT_TURNOFF_SET(x)                               (((x) << PCIE_APP_PM_XMT_TURNOFF_LSB) & PCIE_APP_PM_XMT_TURNOFF_MASK)
#define PCIE_APP_PM_XMT_TURNOFF_RESET                                0x0 // 0
#define PCIE_APP_UNLOCK_MSG_MSB                                      1
#define PCIE_APP_UNLOCK_MSG_LSB                                      1
#define PCIE_APP_UNLOCK_MSG_MASK                                     0x00000002
#define PCIE_APP_UNLOCK_MSG_GET(x)                                   (((x) & PCIE_APP_UNLOCK_MSG_MASK) >> PCIE_APP_UNLOCK_MSG_LSB)
#define PCIE_APP_UNLOCK_MSG_SET(x)                                   (((x) << PCIE_APP_UNLOCK_MSG_LSB) & PCIE_APP_UNLOCK_MSG_MASK)
#define PCIE_APP_UNLOCK_MSG_RESET                                    0x0 // 0
#define PCIE_APP_LTSSM_ENABLE_MSB                                    0
#define PCIE_APP_LTSSM_ENABLE_LSB                                    0
#define PCIE_APP_LTSSM_ENABLE_MASK                                   0x00000001
#define PCIE_APP_LTSSM_ENABLE_GET(x)                                 (((x) & PCIE_APP_LTSSM_ENABLE_MASK) >> PCIE_APP_LTSSM_ENABLE_LSB)
#define PCIE_APP_LTSSM_ENABLE_SET(x)                                 (((x) << PCIE_APP_LTSSM_ENABLE_LSB) & PCIE_APP_LTSSM_ENABLE_MASK)
#define PCIE_APP_LTSSM_ENABLE_RESET                                  0x0 // 0
#define PCIE_APP_ADDRESS                                             0x180f0000

#define PMU2_SWREGMSB_MSB                                            31
#define PMU2_SWREGMSB_LSB                                            22
#define PMU2_SWREGMSB_MASK                                           0xffc00000
#define PMU2_SWREGMSB_GET(x)                                         (((x) & PMU2_SWREGMSB_MASK) >> PMU2_SWREGMSB_LSB)
#define PMU2_SWREGMSB_SET(x)                                         (((x) << PMU2_SWREGMSB_LSB) & PMU2_SWREGMSB_MASK)
#define PMU2_SWREGMSB_RESET                                          0x0 // 0
#define PMU2_PGM_MSB                                                 21
#define PMU2_PGM_LSB                                                 21
#define PMU2_PGM_MASK                                                0x00200000
#define PMU2_PGM_GET(x)                                              (((x) & PMU2_PGM_MASK) >> PMU2_PGM_LSB)
#define PMU2_PGM_SET(x)                                              (((x) << PMU2_PGM_LSB) & PMU2_PGM_MASK)
#define PMU2_PGM_RESET                                               0x0 // 0
#define PMU2_LDO_TUNE_MSB                                            20
#define PMU2_LDO_TUNE_LSB                                            19
#define PMU2_LDO_TUNE_MASK                                           0x00180000
#define PMU2_LDO_TUNE_GET(x)                                         (((x) & PMU2_LDO_TUNE_MASK) >> PMU2_LDO_TUNE_LSB)
#define PMU2_LDO_TUNE_SET(x)                                         (((x) << PMU2_LDO_TUNE_LSB) & PMU2_LDO_TUNE_MASK)
#define PMU2_LDO_TUNE_RESET                                          0x0 // 0
#define PMU2_PWDLDO_DDR_MSB                                          18
#define PMU2_PWDLDO_DDR_LSB                                          18
#define PMU2_PWDLDO_DDR_MASK                                         0x00040000
#define PMU2_PWDLDO_DDR_GET(x)                                       (((x) & PMU2_PWDLDO_DDR_MASK) >> PMU2_PWDLDO_DDR_LSB)
#define PMU2_PWDLDO_DDR_SET(x)                                       (((x) << PMU2_PWDLDO_DDR_LSB) & PMU2_PWDLDO_DDR_MASK)
#define PMU2_PWDLDO_DDR_RESET                                        0x0 // 0
#define PMU2_LPOPWD_MSB                                              17
#define PMU2_LPOPWD_LSB                                              17
#define PMU2_LPOPWD_MASK                                             0x00020000
#define PMU2_LPOPWD_GET(x)                                           (((x) & PMU2_LPOPWD_MASK) >> PMU2_LPOPWD_LSB)
#define PMU2_LPOPWD_SET(x)                                           (((x) << PMU2_LPOPWD_LSB) & PMU2_LPOPWD_MASK)
#define PMU2_LPOPWD_RESET                                            0x0 // 0
#define PMU2_SPARE_MSB                                               16
#define PMU2_SPARE_LSB                                               0
#define PMU2_SPARE_MASK                                              0x0001ffff
#define PMU2_SPARE_GET(x)                                            (((x) & PMU2_SPARE_MASK) >> PMU2_SPARE_LSB)
#define PMU2_SPARE_SET(x)                                            (((x) << PMU2_SPARE_LSB) & PMU2_SPARE_MASK)
#define PMU2_SPARE_RESET                                             0x0 // 0
#define PMU2_ADDRESS                                                 0x18116cc4

#define DDR_CONFIG_CAS_LATENCY_MSB_MSB                               31
#define DDR_CONFIG_CAS_LATENCY_MSB_LSB                               31
#define DDR_CONFIG_CAS_LATENCY_MSB_MASK                              0x80000000
#define DDR_CONFIG_CAS_LATENCY_MSB_GET(x)                            (((x) & DDR_CONFIG_CAS_LATENCY_MSB_MASK) >> DDR_CONFIG_CAS_LATENCY_MSB_LSB)
#define DDR_CONFIG_CAS_LATENCY_MSB_SET(x)                            (((x) << DDR_CONFIG_CAS_LATENCY_MSB_LSB) & DDR_CONFIG_CAS_LATENCY_MSB_MASK)
#define DDR_CONFIG_CAS_LATENCY_MSB_RESET                             0x0 // 0
#define DDR_CONFIG_OPEN_PAGE_MSB                                     30
#define DDR_CONFIG_OPEN_PAGE_LSB                                     30
#define DDR_CONFIG_OPEN_PAGE_MASK                                    0x40000000
#define DDR_CONFIG_OPEN_PAGE_GET(x)                                  (((x) & DDR_CONFIG_OPEN_PAGE_MASK) >> DDR_CONFIG_OPEN_PAGE_LSB)
#define DDR_CONFIG_OPEN_PAGE_SET(x)                                  (((x) << DDR_CONFIG_OPEN_PAGE_LSB) & DDR_CONFIG_OPEN_PAGE_MASK)
#define DDR_CONFIG_OPEN_PAGE_RESET                                   0x1 // 1
#define DDR_CONFIG_CAS_LATENCY_MSB                                   29
#define DDR_CONFIG_CAS_LATENCY_LSB                                   27
#define DDR_CONFIG_CAS_LATENCY_MASK                                  0x38000000
#define DDR_CONFIG_CAS_LATENCY_GET(x)                                (((x) & DDR_CONFIG_CAS_LATENCY_MASK) >> DDR_CONFIG_CAS_LATENCY_LSB)
#define DDR_CONFIG_CAS_LATENCY_SET(x)                                (((x) << DDR_CONFIG_CAS_LATENCY_LSB) & DDR_CONFIG_CAS_LATENCY_MASK)
#define DDR_CONFIG_CAS_LATENCY_RESET                                 0x6 // 6
#define DDR_CONFIG_TMRD_MSB                                          26
#define DDR_CONFIG_TMRD_LSB                                          23
#define DDR_CONFIG_TMRD_MASK                                         0x07800000
#define DDR_CONFIG_TMRD_GET(x)                                       (((x) & DDR_CONFIG_TMRD_MASK) >> DDR_CONFIG_TMRD_LSB)
#define DDR_CONFIG_TMRD_SET(x)                                       (((x) << DDR_CONFIG_TMRD_LSB) & DDR_CONFIG_TMRD_MASK)
#define DDR_CONFIG_TMRD_RESET                                        0xf // 15
#define DDR_CONFIG_TRFC_MSB                                          22
#define DDR_CONFIG_TRFC_LSB                                          17
#define DDR_CONFIG_TRFC_MASK                                         0x007e0000
#define DDR_CONFIG_TRFC_GET(x)                                       (((x) & DDR_CONFIG_TRFC_MASK) >> DDR_CONFIG_TRFC_LSB)
#define DDR_CONFIG_TRFC_SET(x)                                       (((x) << DDR_CONFIG_TRFC_LSB) & DDR_CONFIG_TRFC_MASK)
#define DDR_CONFIG_TRFC_RESET                                        0x24 // 36
#define DDR_CONFIG_TRRD_MSB                                          16
#define DDR_CONFIG_TRRD_LSB                                          13
#define DDR_CONFIG_TRRD_MASK                                         0x0001e000
#define DDR_CONFIG_TRRD_GET(x)                                       (((x) & DDR_CONFIG_TRRD_MASK) >> DDR_CONFIG_TRRD_LSB)
#define DDR_CONFIG_TRRD_SET(x)                                       (((x) << DDR_CONFIG_TRRD_LSB) & DDR_CONFIG_TRRD_MASK)
#define DDR_CONFIG_TRRD_RESET                                        0x4 // 4
#define DDR_CONFIG_TRP_MSB                                           12
#define DDR_CONFIG_TRP_LSB                                           9
#define DDR_CONFIG_TRP_MASK                                          0x00001e00
#define DDR_CONFIG_TRP_GET(x)                                        (((x) & DDR_CONFIG_TRP_MASK) >> DDR_CONFIG_TRP_LSB)
#define DDR_CONFIG_TRP_SET(x)                                        (((x) << DDR_CONFIG_TRP_LSB) & DDR_CONFIG_TRP_MASK)
#define DDR_CONFIG_TRP_RESET                                         0x6 // 6
#define DDR_CONFIG_TRCD_MSB                                          8
#define DDR_CONFIG_TRCD_LSB                                          5
#define DDR_CONFIG_TRCD_MASK                                         0x000001e0
#define DDR_CONFIG_TRCD_GET(x)                                       (((x) & DDR_CONFIG_TRCD_MASK) >> DDR_CONFIG_TRCD_LSB)
#define DDR_CONFIG_TRCD_SET(x)                                       (((x) << DDR_CONFIG_TRCD_LSB) & DDR_CONFIG_TRCD_MASK)
#define DDR_CONFIG_TRCD_RESET                                        0x6 // 6
#define DDR_CONFIG_TRAS_MSB                                          4
#define DDR_CONFIG_TRAS_LSB                                          0
#define DDR_CONFIG_TRAS_MASK                                         0x0000001f
#define DDR_CONFIG_TRAS_GET(x)                                       (((x) & DDR_CONFIG_TRAS_MASK) >> DDR_CONFIG_TRAS_LSB)
#define DDR_CONFIG_TRAS_SET(x)                                       (((x) << DDR_CONFIG_TRAS_LSB) & DDR_CONFIG_TRAS_MASK)
#define DDR_CONFIG_TRAS_RESET                                        0x10 // 16
#define DDR_CONFIG_ADDRESS                                           0x18000000

#define DDR_CONFIG2_HALF_WIDTH_LOW_MSB                               31
#define DDR_CONFIG2_HALF_WIDTH_LOW_LSB                               31
#define DDR_CONFIG2_HALF_WIDTH_LOW_MASK                              0x80000000
#define DDR_CONFIG2_HALF_WIDTH_LOW_GET(x)                            (((x) & DDR_CONFIG2_HALF_WIDTH_LOW_MASK) >> DDR_CONFIG2_HALF_WIDTH_LOW_LSB)
#define DDR_CONFIG2_HALF_WIDTH_LOW_SET(x)                            (((x) << DDR_CONFIG2_HALF_WIDTH_LOW_LSB) & DDR_CONFIG2_HALF_WIDTH_LOW_MASK)
#define DDR_CONFIG2_HALF_WIDTH_LOW_RESET                             0x1 // 1
#define DDR_CONFIG2_SWAP_A26_A27_MSB                                 30
#define DDR_CONFIG2_SWAP_A26_A27_LSB                                 30
#define DDR_CONFIG2_SWAP_A26_A27_MASK                                0x40000000
#define DDR_CONFIG2_SWAP_A26_A27_GET(x)                              (((x) & DDR_CONFIG2_SWAP_A26_A27_MASK) >> DDR_CONFIG2_SWAP_A26_A27_LSB)
#define DDR_CONFIG2_SWAP_A26_A27_SET(x)                              (((x) << DDR_CONFIG2_SWAP_A26_A27_LSB) & DDR_CONFIG2_SWAP_A26_A27_MASK)
#define DDR_CONFIG2_SWAP_A26_A27_RESET                               0x0 // 0
#define DDR_CONFIG2_GATE_OPEN_LATENCY_MSB                            29
#define DDR_CONFIG2_GATE_OPEN_LATENCY_LSB                            26
#define DDR_CONFIG2_GATE_OPEN_LATENCY_MASK                           0x3c000000
#define DDR_CONFIG2_GATE_OPEN_LATENCY_GET(x)                         (((x) & DDR_CONFIG2_GATE_OPEN_LATENCY_MASK) >> DDR_CONFIG2_GATE_OPEN_LATENCY_LSB)
#define DDR_CONFIG2_GATE_OPEN_LATENCY_SET(x)                         (((x) << DDR_CONFIG2_GATE_OPEN_LATENCY_LSB) & DDR_CONFIG2_GATE_OPEN_LATENCY_MASK)
#define DDR_CONFIG2_GATE_OPEN_LATENCY_RESET                          0x6 // 6
#define DDR_CONFIG2_TWTR_MSB                                         25
#define DDR_CONFIG2_TWTR_LSB                                         21
#define DDR_CONFIG2_TWTR_MASK                                        0x03e00000
#define DDR_CONFIG2_TWTR_GET(x)                                      (((x) & DDR_CONFIG2_TWTR_MASK) >> DDR_CONFIG2_TWTR_LSB)
#define DDR_CONFIG2_TWTR_SET(x)                                      (((x) << DDR_CONFIG2_TWTR_LSB) & DDR_CONFIG2_TWTR_MASK)
#define DDR_CONFIG2_TWTR_RESET                                       0xe // 14
#define DDR_CONFIG2_TRTP_MSB                                         20
#define DDR_CONFIG2_TRTP_LSB                                         17
#define DDR_CONFIG2_TRTP_MASK                                        0x001e0000
#define DDR_CONFIG2_TRTP_GET(x)                                      (((x) & DDR_CONFIG2_TRTP_MASK) >> DDR_CONFIG2_TRTP_LSB)
#define DDR_CONFIG2_TRTP_SET(x)                                      (((x) << DDR_CONFIG2_TRTP_LSB) & DDR_CONFIG2_TRTP_MASK)
#define DDR_CONFIG2_TRTP_RESET                                       0x8 // 8
#define DDR_CONFIG2_TRTW_MSB                                         16
#define DDR_CONFIG2_TRTW_LSB                                         12
#define DDR_CONFIG2_TRTW_MASK                                        0x0001f000
#define DDR_CONFIG2_TRTW_GET(x)                                      (((x) & DDR_CONFIG2_TRTW_MASK) >> DDR_CONFIG2_TRTW_LSB)
#define DDR_CONFIG2_TRTW_SET(x)                                      (((x) << DDR_CONFIG2_TRTW_LSB) & DDR_CONFIG2_TRTW_MASK)
#define DDR_CONFIG2_TRTW_RESET                                       0x10 // 16
#define DDR_CONFIG2_TWR_MSB                                          11
#define DDR_CONFIG2_TWR_LSB                                          8
#define DDR_CONFIG2_TWR_MASK                                         0x00000f00
#define DDR_CONFIG2_TWR_GET(x)                                       (((x) & DDR_CONFIG2_TWR_MASK) >> DDR_CONFIG2_TWR_LSB)
#define DDR_CONFIG2_TWR_SET(x)                                       (((x) << DDR_CONFIG2_TWR_LSB) & DDR_CONFIG2_TWR_MASK)
#define DDR_CONFIG2_TWR_RESET                                        0x6 // 6
#define DDR_CONFIG2_CKE_MSB                                          7
#define DDR_CONFIG2_CKE_LSB                                          7
#define DDR_CONFIG2_CKE_MASK                                         0x00000080
#define DDR_CONFIG2_CKE_GET(x)                                       (((x) & DDR_CONFIG2_CKE_MASK) >> DDR_CONFIG2_CKE_LSB)
#define DDR_CONFIG2_CKE_SET(x)                                       (((x) << DDR_CONFIG2_CKE_LSB) & DDR_CONFIG2_CKE_MASK)
#define DDR_CONFIG2_CKE_RESET                                        0x0 // 0
#define DDR_CONFIG2_PHASE_SELECT_MSB                                 6
#define DDR_CONFIG2_PHASE_SELECT_LSB                                 6
#define DDR_CONFIG2_PHASE_SELECT_MASK                                0x00000040
#define DDR_CONFIG2_PHASE_SELECT_GET(x)                              (((x) & DDR_CONFIG2_PHASE_SELECT_MASK) >> DDR_CONFIG2_PHASE_SELECT_LSB)
#define DDR_CONFIG2_PHASE_SELECT_SET(x)                              (((x) << DDR_CONFIG2_PHASE_SELECT_LSB) & DDR_CONFIG2_PHASE_SELECT_MASK)
#define DDR_CONFIG2_PHASE_SELECT_RESET                               0x0 // 0
#define DDR_CONFIG2_CNTL_OE_EN_MSB                                   5
#define DDR_CONFIG2_CNTL_OE_EN_LSB                                   5
#define DDR_CONFIG2_CNTL_OE_EN_MASK                                  0x00000020
#define DDR_CONFIG2_CNTL_OE_EN_GET(x)                                (((x) & DDR_CONFIG2_CNTL_OE_EN_MASK) >> DDR_CONFIG2_CNTL_OE_EN_LSB)
#define DDR_CONFIG2_CNTL_OE_EN_SET(x)                                (((x) << DDR_CONFIG2_CNTL_OE_EN_LSB) & DDR_CONFIG2_CNTL_OE_EN_MASK)
#define DDR_CONFIG2_CNTL_OE_EN_RESET                                 0x1 // 1
#define DDR_CONFIG2_BURST_TYPE_MSB                                   4
#define DDR_CONFIG2_BURST_TYPE_LSB                                   4
#define DDR_CONFIG2_BURST_TYPE_MASK                                  0x00000010
#define DDR_CONFIG2_BURST_TYPE_GET(x)                                (((x) & DDR_CONFIG2_BURST_TYPE_MASK) >> DDR_CONFIG2_BURST_TYPE_LSB)
#define DDR_CONFIG2_BURST_TYPE_SET(x)                                (((x) << DDR_CONFIG2_BURST_TYPE_LSB) & DDR_CONFIG2_BURST_TYPE_MASK)
#define DDR_CONFIG2_BURST_TYPE_RESET                                 0x0 // 0
#define DDR_CONFIG2_BURST_LENGTH_MSB                                 3
#define DDR_CONFIG2_BURST_LENGTH_LSB                                 0
#define DDR_CONFIG2_BURST_LENGTH_MASK                                0x0000000f
#define DDR_CONFIG2_BURST_LENGTH_GET(x)                              (((x) & DDR_CONFIG2_BURST_LENGTH_MASK) >> DDR_CONFIG2_BURST_LENGTH_LSB)
#define DDR_CONFIG2_BURST_LENGTH_SET(x)                              (((x) << DDR_CONFIG2_BURST_LENGTH_LSB) & DDR_CONFIG2_BURST_LENGTH_MASK)
#define DDR_CONFIG2_BURST_LENGTH_RESET                               0x8 // 8
#define DDR_CONFIG2_ADDRESS                                          0x18000004

#define XTAL_TCXODET_MSB                                             31
#define XTAL_TCXODET_LSB                                             31
#define XTAL_TCXODET_MASK                                            0x80000000
#define XTAL_TCXODET_GET(x)                                          (((x) & XTAL_TCXODET_MASK) >> XTAL_TCXODET_LSB)
#define XTAL_TCXODET_SET(x)                                          (((x) << XTAL_TCXODET_LSB) & XTAL_TCXODET_MASK)
#define XTAL_TCXODET_RESET                                           0x0 // 0
#define XTAL_XTAL_CAPINDAC_MSB                                       30
#define XTAL_XTAL_CAPINDAC_LSB                                       24
#define XTAL_XTAL_CAPINDAC_MASK                                      0x7f000000
#define XTAL_XTAL_CAPINDAC_GET(x)                                    (((x) & XTAL_XTAL_CAPINDAC_MASK) >> XTAL_XTAL_CAPINDAC_LSB)
#define XTAL_XTAL_CAPINDAC_SET(x)                                    (((x) << XTAL_XTAL_CAPINDAC_LSB) & XTAL_XTAL_CAPINDAC_MASK)
#define XTAL_XTAL_CAPINDAC_RESET                                     0x4b // 75
#define XTAL_XTAL_CAPOUTDAC_MSB                                      23
#define XTAL_XTAL_CAPOUTDAC_LSB                                      17
#define XTAL_XTAL_CAPOUTDAC_MASK                                     0x00fe0000
#define XTAL_XTAL_CAPOUTDAC_GET(x)                                   (((x) & XTAL_XTAL_CAPOUTDAC_MASK) >> XTAL_XTAL_CAPOUTDAC_LSB)
#define XTAL_XTAL_CAPOUTDAC_SET(x)                                   (((x) << XTAL_XTAL_CAPOUTDAC_LSB) & XTAL_XTAL_CAPOUTDAC_MASK)
#define XTAL_XTAL_CAPOUTDAC_RESET                                    0x4b // 75
#define XTAL_XTAL_DRVSTR_MSB                                         16
#define XTAL_XTAL_DRVSTR_LSB                                         15
#define XTAL_XTAL_DRVSTR_MASK                                        0x00018000
#define XTAL_XTAL_DRVSTR_GET(x)                                      (((x) & XTAL_XTAL_DRVSTR_MASK) >> XTAL_XTAL_DRVSTR_LSB)
#define XTAL_XTAL_DRVSTR_SET(x)                                      (((x) << XTAL_XTAL_DRVSTR_LSB) & XTAL_XTAL_DRVSTR_MASK)
#define XTAL_XTAL_DRVSTR_RESET                                       0x0 // 0
#define XTAL_XTAL_SHORTXIN_MSB                                       14
#define XTAL_XTAL_SHORTXIN_LSB                                       14
#define XTAL_XTAL_SHORTXIN_MASK                                      0x00004000
#define XTAL_XTAL_SHORTXIN_GET(x)                                    (((x) & XTAL_XTAL_SHORTXIN_MASK) >> XTAL_XTAL_SHORTXIN_LSB)
#define XTAL_XTAL_SHORTXIN_SET(x)                                    (((x) << XTAL_XTAL_SHORTXIN_LSB) & XTAL_XTAL_SHORTXIN_MASK)
#define XTAL_XTAL_SHORTXIN_RESET                                     0x0 // 0
#define XTAL_XTAL_LOCALBIAS_MSB                                      13
#define XTAL_XTAL_LOCALBIAS_LSB                                      13
#define XTAL_XTAL_LOCALBIAS_MASK                                     0x00002000
#define XTAL_XTAL_LOCALBIAS_GET(x)                                   (((x) & XTAL_XTAL_LOCALBIAS_MASK) >> XTAL_XTAL_LOCALBIAS_LSB)
#define XTAL_XTAL_LOCALBIAS_SET(x)                                   (((x) << XTAL_XTAL_LOCALBIAS_LSB) & XTAL_XTAL_LOCALBIAS_MASK)
#define XTAL_XTAL_LOCALBIAS_RESET                                    0x1 // 1
#define XTAL_XTAL_PWDCLKD_MSB                                        12
#define XTAL_XTAL_PWDCLKD_LSB                                        12
#define XTAL_XTAL_PWDCLKD_MASK                                       0x00001000
#define XTAL_XTAL_PWDCLKD_GET(x)                                     (((x) & XTAL_XTAL_PWDCLKD_MASK) >> XTAL_XTAL_PWDCLKD_LSB)
#define XTAL_XTAL_PWDCLKD_SET(x)                                     (((x) << XTAL_XTAL_PWDCLKD_LSB) & XTAL_XTAL_PWDCLKD_MASK)
#define XTAL_XTAL_PWDCLKD_RESET                                      0x0 // 0
#define XTAL_XTAL_BIAS2X_MSB                                         11
#define XTAL_XTAL_BIAS2X_LSB                                         11
#define XTAL_XTAL_BIAS2X_MASK                                        0x00000800
#define XTAL_XTAL_BIAS2X_GET(x)                                      (((x) & XTAL_XTAL_BIAS2X_MASK) >> XTAL_XTAL_BIAS2X_LSB)
#define XTAL_XTAL_BIAS2X_SET(x)                                      (((x) << XTAL_XTAL_BIAS2X_LSB) & XTAL_XTAL_BIAS2X_MASK)
#define XTAL_XTAL_BIAS2X_RESET                                       0x1 // 1
#define XTAL_XTAL_LBIAS2X_MSB                                        10
#define XTAL_XTAL_LBIAS2X_LSB                                        10
#define XTAL_XTAL_LBIAS2X_MASK                                       0x00000400
#define XTAL_XTAL_LBIAS2X_GET(x)                                     (((x) & XTAL_XTAL_LBIAS2X_MASK) >> XTAL_XTAL_LBIAS2X_LSB)
#define XTAL_XTAL_LBIAS2X_SET(x)                                     (((x) << XTAL_XTAL_LBIAS2X_LSB) & XTAL_XTAL_LBIAS2X_MASK)
#define XTAL_XTAL_LBIAS2X_RESET                                      0x1 // 1
#define XTAL_XTAL_ATBVREG_MSB                                        9
#define XTAL_XTAL_ATBVREG_LSB                                        9
#define XTAL_XTAL_ATBVREG_MASK                                       0x00000200
#define XTAL_XTAL_ATBVREG_GET(x)                                     (((x) & XTAL_XTAL_ATBVREG_MASK) >> XTAL_XTAL_ATBVREG_LSB)
#define XTAL_XTAL_ATBVREG_SET(x)                                     (((x) << XTAL_XTAL_ATBVREG_LSB) & XTAL_XTAL_ATBVREG_MASK)
#define XTAL_XTAL_ATBVREG_RESET                                      0x0 // 0
#define XTAL_XTAL_OSCON_MSB                                          8
#define XTAL_XTAL_OSCON_LSB                                          8
#define XTAL_XTAL_OSCON_MASK                                         0x00000100
#define XTAL_XTAL_OSCON_GET(x)                                       (((x) & XTAL_XTAL_OSCON_MASK) >> XTAL_XTAL_OSCON_LSB)
#define XTAL_XTAL_OSCON_SET(x)                                       (((x) << XTAL_XTAL_OSCON_LSB) & XTAL_XTAL_OSCON_MASK)
#define XTAL_XTAL_OSCON_RESET                                        0x1 // 1
#define XTAL_XTAL_PWDCLKIN_MSB                                       7
#define XTAL_XTAL_PWDCLKIN_LSB                                       7
#define XTAL_XTAL_PWDCLKIN_MASK                                      0x00000080
#define XTAL_XTAL_PWDCLKIN_GET(x)                                    (((x) & XTAL_XTAL_PWDCLKIN_MASK) >> XTAL_XTAL_PWDCLKIN_LSB)
#define XTAL_XTAL_PWDCLKIN_SET(x)                                    (((x) << XTAL_XTAL_PWDCLKIN_LSB) & XTAL_XTAL_PWDCLKIN_MASK)
#define XTAL_XTAL_PWDCLKIN_RESET                                     0x0 // 0
#define XTAL_LOCAL_XTAL_MSB                                          6
#define XTAL_LOCAL_XTAL_LSB                                          6
#define XTAL_LOCAL_XTAL_MASK                                         0x00000040
#define XTAL_LOCAL_XTAL_GET(x)                                       (((x) & XTAL_LOCAL_XTAL_MASK) >> XTAL_LOCAL_XTAL_LSB)
#define XTAL_LOCAL_XTAL_SET(x)                                       (((x) << XTAL_LOCAL_XTAL_LSB) & XTAL_LOCAL_XTAL_MASK)
#define XTAL_LOCAL_XTAL_RESET                                        0x0 // 0
#define XTAL_PWD_SWREGCLK_MSB                                        5
#define XTAL_PWD_SWREGCLK_LSB                                        5
#define XTAL_PWD_SWREGCLK_MASK                                       0x00000020
#define XTAL_PWD_SWREGCLK_GET(x)                                     (((x) & XTAL_PWD_SWREGCLK_MASK) >> XTAL_PWD_SWREGCLK_LSB)
#define XTAL_PWD_SWREGCLK_SET(x)                                     (((x) << XTAL_PWD_SWREGCLK_LSB) & XTAL_PWD_SWREGCLK_MASK)
#define XTAL_PWD_SWREGCLK_RESET                                      0x0 // 0
#define XTAL_SWREGCLK_EDGE_SEL_MSB                                   4
#define XTAL_SWREGCLK_EDGE_SEL_LSB                                   4
#define XTAL_SWREGCLK_EDGE_SEL_MASK                                  0x00000010
#define XTAL_SWREGCLK_EDGE_SEL_GET(x)                                (((x) & XTAL_SWREGCLK_EDGE_SEL_MASK) >> XTAL_SWREGCLK_EDGE_SEL_LSB)
#define XTAL_SWREGCLK_EDGE_SEL_SET(x)                                (((x) << XTAL_SWREGCLK_EDGE_SEL_LSB) & XTAL_SWREGCLK_EDGE_SEL_MASK)
#define XTAL_SWREGCLK_EDGE_SEL_RESET                                 0x0 // 0
#define XTAL_SPARE_MSB                                               3
#define XTAL_SPARE_LSB                                               0
#define XTAL_SPARE_MASK                                              0x0000000f
#define XTAL_SPARE_GET(x)                                            (((x) & XTAL_SPARE_MASK) >> XTAL_SPARE_LSB)
#define XTAL_SPARE_SET(x)                                            (((x) << XTAL_SPARE_LSB) & XTAL_SPARE_MASK)
#define XTAL_SPARE_RESET                                             0xf // 15
#define XTAL_ADDRESS                                                 0x18116290

/*
 * `cfg_pll_freq' is defined using -D command line option and gets
 * converted to `CFG_PLL_FREQ'.
 *
 * Per `man cpp'
 *	-D name=definition
 *		The contents of definition are tokenized and processed as if
 *		they appeared during translation phase three in a #define
 *		directive.
 *
 * Hence, the following round about way of defining it...
 */
#define CFG_PLL_FREQ	cfg_pll_freq

#if defined(CFG_ATH_EMULATION)

#define CPU_PLL_CONFIG_NINT_VAL			CPU_PLL_CONFIG_NINT_SET(2)	// 80 MHz
#define DDR_PLL_CONFIG_NINT_VAL			DDR_PLL_CONFIG_NINT_SET(1)	// 40 MHz

#elif (CFG_PLL_FREQ == CFG_PLL_720_600_200)

#define CPU_DDR_SYNC_MODE			DDR_CTL_CONFIG_CPU_DDR_SYNC_SET(0)

#define CPU_PLL_CONFIG_NINT_VAL			CPU_PLL_CONFIG_NINT_SET(18)
#define CPU_PLL_CONFIG_REF_DIV_VAL		CPU_PLL_CONFIG_REFDIV_SET(1)
#define CPU_PLL_CONFIG_RANGE_VAL		CPU_PLL_CONFIG_RANGE_SET(1)
#define CPU_PLL_CONFIG_OUT_DIV_VAL1		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_CONFIG_OUT_DIV_VAL2		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_DITHER_VAL			CPU_PLL_DITHER_DITHER_EN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_MAX_SET(0x3f) | \
						CPU_PLL_DITHER_NFRAC_MIN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_STEP_SET(1) | \
						CPU_PLL_DITHER_UPDATE_COUNT_SET(0xf)

#define DDR_PLL_CONFIG_NINT_VAL			DDR_PLL_CONFIG_NINT_SET(15)
#define DDR_PLL_CONFIG_REF_DIV_VAL		DDR_PLL_CONFIG_REFDIV_SET(1)
#define DDR_PLL_CONFIG_RANGE_VAL		DDR_PLL_CONFIG_RANGE_SET(1)
#define DDR_PLL_CONFIG_OUT_DIV_VAL1		DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_CONFIG_OUT_DIV_VAL2		DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_DITHER_VAL			DDR_PLL_DITHER_DITHER_EN_SET(0) | \
						DDR_PLL_DITHER_NFRAC_MAX_SET(0x3ff) | \
						DDR_PLL_DITHER_NFRAC_MIN_SET(0) | \
						DDR_PLL_DITHER_NFRAC_STEP_SET(1) | \
						DDR_PLL_DITHER_UPDATE_COUNT_SET(0xf)

#define CPU_DDR_CLOCK_CONTROL_AHB_DIV_VAL	CPU_DDR_CLOCK_CONTROL_AHB_POST_DIV_SET(2)
#define AHB_CLK_FROM_DDR			CPU_DDR_CLOCK_CONTROL_AHBCLK_FROM_DDRPLL_SET(1)
#define CPU_AND_DDR_CLK_FROM_DDR		CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_DDRPLL_SET(0)
#define CPU_AND_DDR_CLK_FROM_CPU		CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_CPUPLL_SET(0)
#define CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV	CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV_SET(0)
#define CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV	CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV_SET(0)

#elif (CFG_PLL_FREQ == CFG_PLL_720_600_300)

#define CPU_DDR_SYNC_MODE			DDR_CTL_CONFIG_CPU_DDR_SYNC_SET(0)

#define CPU_PLL_CONFIG_NINT_VAL			CPU_PLL_CONFIG_NINT_SET(18)
#define CPU_PLL_CONFIG_REF_DIV_VAL		CPU_PLL_CONFIG_REFDIV_SET(1)
#define CPU_PLL_CONFIG_RANGE_VAL		CPU_PLL_CONFIG_RANGE_SET(1)
#define CPU_PLL_CONFIG_OUT_DIV_VAL1		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_CONFIG_OUT_DIV_VAL2		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_DITHER_VAL			CPU_PLL_DITHER_DITHER_EN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_MAX_SET(0x3f) | \
						CPU_PLL_DITHER_NFRAC_MIN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_STEP_SET(1) | \
						CPU_PLL_DITHER_UPDATE_COUNT_SET(0xf)

#define DDR_PLL_CONFIG_NINT_VAL			DDR_PLL_CONFIG_NINT_SET(15)
#define DDR_PLL_CONFIG_REF_DIV_VAL		DDR_PLL_CONFIG_REFDIV_SET(1)
#define DDR_PLL_CONFIG_RANGE_VAL		DDR_PLL_CONFIG_RANGE_SET(1)
#define DDR_PLL_CONFIG_OUT_DIV_VAL1		DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_CONFIG_OUT_DIV_VAL2		DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_DITHER_VAL			DDR_PLL_DITHER_DITHER_EN_SET(0) | \
						DDR_PLL_DITHER_NFRAC_MAX_SET(0x3ff) | \
						DDR_PLL_DITHER_NFRAC_MIN_SET(0) | \
						DDR_PLL_DITHER_NFRAC_STEP_SET(1) | \
						DDR_PLL_DITHER_UPDATE_COUNT_SET(0xf)

#define CPU_DDR_CLOCK_CONTROL_AHB_DIV_VAL	CPU_DDR_CLOCK_CONTROL_AHB_POST_DIV_SET(1)
#define AHB_CLK_FROM_DDR			CPU_DDR_CLOCK_CONTROL_AHBCLK_FROM_DDRPLL_SET(1)
#define CPU_AND_DDR_CLK_FROM_DDR		CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_DDRPLL_SET(0)
#define CPU_AND_DDR_CLK_FROM_CPU		CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_CPUPLL_SET(0)
#define CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV	CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV_SET(0)
#define CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV	CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV_SET(0)

#elif (CFG_PLL_FREQ == CFG_PLL_400_400_200)

#define CPU_DDR_SYNC_MODE			DDR_CTL_CONFIG_CPU_DDR_SYNC_SET(0)

#define CPU_PLL_CONFIG_NINT_VAL			CPU_PLL_CONFIG_NINT_SET(10)
#define CPU_PLL_CONFIG_REF_DIV_VAL		CPU_PLL_CONFIG_REFDIV_SET(1)
#define CPU_PLL_CONFIG_RANGE_VAL		CPU_PLL_CONFIG_RANGE_SET(1)
#define CPU_PLL_CONFIG_OUT_DIV_VAL1		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_CONFIG_OUT_DIV_VAL2		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_DITHER_VAL			CPU_PLL_DITHER_DITHER_EN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_MAX_SET(0x3f) | \
						CPU_PLL_DITHER_NFRAC_MIN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_STEP_SET(1) | \
						CPU_PLL_DITHER_UPDATE_COUNT_SET(0xf)

#define DDR_PLL_CONFIG_NINT_VAL			DDR_PLL_CONFIG_NINT_SET(10)
#define DDR_PLL_CONFIG_REF_DIV_VAL		DDR_PLL_CONFIG_REFDIV_SET(1)
#elif (CFG_PLL_FREQ == CFG_PLL_720_680_240)

#define CPU_DDR_SYNC_MODE			DDR_CTL_CONFIG_CPU_DDR_SYNC_SET(0)

#define CPU_PLL_CONFIG_NINT_VAL			CPU_PLL_CONFIG_NINT_SET(18)
#define CPU_PLL_CONFIG_REF_DIV_VAL		CPU_PLL_CONFIG_REFDIV_SET(1)
#define CPU_PLL_CONFIG_RANGE_VAL		CPU_PLL_CONFIG_RANGE_SET(1)
#define CPU_PLL_CONFIG_OUT_DIV_VAL1		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_CONFIG_OUT_DIV_VAL2		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_DITHER_VAL			CPU_PLL_DITHER_DITHER_EN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_MAX_SET(0x3f) | \
						CPU_PLL_DITHER_NFRAC_MIN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_STEP_SET(1) | \
						CPU_PLL_DITHER_UPDATE_COUNT_SET(0xf)

#define DDR_PLL_CONFIG_NINT_VAL			DDR_PLL_CONFIG_NINT_SET(17)
#define DDR_PLL_CONFIG_REF_DIV_VAL		DDR_PLL_CONFIG_REFDIV_SET(1)
#define DDR_PLL_CONFIG_RANGE_VAL		DDR_PLL_CONFIG_RANGE_SET(1)
#define DDR_PLL_CONFIG_OUT_DIV_VAL1		DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_CONFIG_OUT_DIV_VAL2		DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_DITHER_VAL			DDR_PLL_DITHER_DITHER_EN_SET(0) | \
						DDR_PLL_DITHER_NFRAC_MAX_SET(0x3ff) | \
						DDR_PLL_DITHER_NFRAC_MIN_SET(0) | \
						DDR_PLL_DITHER_NFRAC_STEP_SET(1) | \
						DDR_PLL_DITHER_UPDATE_COUNT_SET(0xf)

#define CPU_DDR_CLOCK_CONTROL_AHB_DIV_VAL	CPU_DDR_CLOCK_CONTROL_AHB_POST_DIV_SET(2)
#define AHB_CLK_FROM_DDR			CPU_DDR_CLOCK_CONTROL_AHBCLK_FROM_DDRPLL_SET(0)
#define CPU_AND_DDR_CLK_FROM_DDR		CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_DDRPLL_SET(0)
#define CPU_AND_DDR_CLK_FROM_CPU		CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_CPUPLL_SET(0)
#define CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV	CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV_SET(0)
#define CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV	CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV_SET(0)

#elif (CFG_PLL_FREQ == CFG_PLL_720_600_240)

#define CPU_DDR_SYNC_MODE			DDR_CTL_CONFIG_CPU_DDR_SYNC_SET(0)

#define CPU_PLL_CONFIG_NINT_VAL			CPU_PLL_CONFIG_NINT_SET(18)
#define CPU_PLL_CONFIG_REF_DIV_VAL		CPU_PLL_CONFIG_REFDIV_SET(1)
#define CPU_PLL_CONFIG_RANGE_VAL		CPU_PLL_CONFIG_RANGE_SET(1)
#define CPU_PLL_CONFIG_OUT_DIV_VAL1		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_CONFIG_OUT_DIV_VAL2		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_DITHER_VAL			CPU_PLL_DITHER_DITHER_EN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_MAX_SET(0x3f) | \
						CPU_PLL_DITHER_NFRAC_MIN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_STEP_SET(1) | \
						CPU_PLL_DITHER_UPDATE_COUNT_SET(0xf)

#define DDR_PLL_CONFIG_NINT_VAL			DDR_PLL_CONFIG_NINT_SET(15)
#define DDR_PLL_CONFIG_REF_DIV_VAL		DDR_PLL_CONFIG_REFDIV_SET(1)
#define DDR_PLL_CONFIG_RANGE_VAL		DDR_PLL_CONFIG_RANGE_SET(1)
#define DDR_PLL_CONFIG_OUT_DIV_VAL1		DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_CONFIG_OUT_DIV_VAL2		DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_DITHER_VAL			DDR_PLL_DITHER_DITHER_EN_SET(0) | \
						DDR_PLL_DITHER_NFRAC_MAX_SET(0x3ff) | \
						DDR_PLL_DITHER_NFRAC_MIN_SET(0) | \
						DDR_PLL_DITHER_NFRAC_STEP_SET(1) | \
						DDR_PLL_DITHER_UPDATE_COUNT_SET(0xf)

#define CPU_DDR_CLOCK_CONTROL_AHB_DIV_VAL	CPU_DDR_CLOCK_CONTROL_AHB_POST_DIV_SET(2)
#define AHB_CLK_FROM_DDR			CPU_DDR_CLOCK_CONTROL_AHBCLK_FROM_DDRPLL_SET(0)
#define CPU_AND_DDR_CLK_FROM_DDR		CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_DDRPLL_SET(0)
#define CPU_AND_DDR_CLK_FROM_CPU		CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_CPUPLL_SET(0)
#define CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV	CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV_SET(0)
#define CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV	CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV_SET(0)

#elif (CFG_PLL_FREQ == CFG_PLL_560_450_220)

#define CPU_DDR_SYNC_MODE			DDR_CTL_CONFIG_CPU_DDR_SYNC_SET(0)

#define CPU_PLL_CONFIG_NINT_VAL			CPU_PLL_CONFIG_NINT_SET(14)
#define CPU_PLL_CONFIG_REF_DIV_VAL		CPU_PLL_CONFIG_REFDIV_SET(1)
#define CPU_PLL_CONFIG_RANGE_VAL		CPU_PLL_CONFIG_RANGE_SET(1)
#define CPU_PLL_CONFIG_OUT_DIV_VAL1		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_CONFIG_OUT_DIV_VAL2		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_DITHER_VAL			CPU_PLL_DITHER_DITHER_EN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_MAX_SET(0x3f) | \
						CPU_PLL_DITHER_NFRAC_MIN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_STEP_SET(1) | \
						CPU_PLL_DITHER_UPDATE_COUNT_SET(0xf)

#define DDR_PLL_CONFIG_NINT_VAL			DDR_PLL_CONFIG_NINT_SET(11)
#define DDR_PLL_CONFIG_REF_DIV_VAL		DDR_PLL_CONFIG_REFDIV_SET(1)
#define DDR_PLL_CONFIG_RANGE_VAL		DDR_PLL_CONFIG_RANGE_SET(1)
#define DDR_PLL_CONFIG_OUT_DIV_VAL1		DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_CONFIG_OUT_DIV_VAL2		DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_DITHER_VAL			DDR_PLL_DITHER_DITHER_EN_SET(0) | \
						DDR_PLL_DITHER_NFRAC_MAX_SET(0x3ff) | \
						DDR_PLL_DITHER_NFRAC_MIN_SET(0x100) | \
						DDR_PLL_DITHER_NFRAC_STEP_SET(1) | \
						DDR_PLL_DITHER_UPDATE_COUNT_SET(0xf)

#define CPU_DDR_CLOCK_CONTROL_AHB_DIV_VAL	CPU_DDR_CLOCK_CONTROL_AHB_POST_DIV_SET(1)
#define AHB_CLK_FROM_DDR			CPU_DDR_CLOCK_CONTROL_AHBCLK_FROM_DDRPLL_SET(1)
#define CPU_AND_DDR_CLK_FROM_DDR		CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_DDRPLL_SET(0)
#define CPU_AND_DDR_CLK_FROM_CPU		CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_CPUPLL_SET(0)
#define CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV	CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV_SET(0)
#define CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV	CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV_SET(0)

#elif (CFG_PLL_FREQ == CFG_PLL_680_680_226)

#define CPU_DDR_SYNC_MODE			DDR_CTL_CONFIG_CPU_DDR_SYNC_SET(1)

#define CPU_PLL_CONFIG_NINT_VAL			CPU_PLL_CONFIG_NINT_SET(17)
#define CPU_PLL_CONFIG_REF_DIV_VAL		CPU_PLL_CONFIG_REFDIV_SET(1)
#define CPU_PLL_CONFIG_RANGE_VAL		CPU_PLL_CONFIG_RANGE_SET(1)
#define CPU_PLL_CONFIG_OUT_DIV_VAL1		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_CONFIG_OUT_DIV_VAL2		CPU_PLL_CONFIG_OUTDIV_SET(0)
#define CPU_PLL_DITHER_VAL			CPU_PLL_DITHER_DITHER_EN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_MAX_SET(0x3f) | \
						CPU_PLL_DITHER_NFRAC_MIN_SET(0) | \
						CPU_PLL_DITHER_NFRAC_STEP_SET(1) | \
						CPU_PLL_DITHER_UPDATE_COUNT_SET(0xf)

#define DDR_PLL_CONFIG_NINT_VAL			DDR_PLL_CONFIG_NINT_SET(17)
#define DDR_PLL_CONFIG_REF_DIV_VAL		DDR_PLL_CONFIG_REFDIV_SET(1)
#define DDR_PLL_CONFIG_RANGE_VAL		DDR_PLL_CONFIG_RANGE_SET(1)
#define DDR_PLL_CONFIG_OUT_DIV_VAL1		DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_CONFIG_OUT_DIV_VAL2		DDR_PLL_CONFIG_OUTDIV_SET(0)
#define DDR_PLL_DITHER_VAL			DDR_PLL_DITHER_DITHER_EN_SET(0) | \
						DDR_PLL_DITHER_NFRAC_MAX_SET(0x3ff) | \
						DDR_PLL_DITHER_NFRAC_MIN_SET(0) | \
						DDR_PLL_DITHER_NFRAC_STEP_SET(1) | \
						DDR_PLL_DITHER_UPDATE_COUNT_SET(0xf)

#define CPU_DDR_CLOCK_CONTROL_AHB_DIV_VAL	CPU_DDR_CLOCK_CONTROL_AHB_POST_DIV_SET(2)
#define AHB_CLK_FROM_DDR			CPU_DDR_CLOCK_CONTROL_AHBCLK_FROM_DDRPLL_SET(1)
#define CPU_AND_DDR_CLK_FROM_DDR		CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_DDRPLL_SET(1)
#define CPU_AND_DDR_CLK_FROM_CPU		CPU_DDR_CLOCK_CONTROL_CPU_DDR_CLK_FROM_CPUPLL_SET(0)
#define CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV	CPU_DDR_CLOCK_CONTROL_DDR_POST_DIV_SET(0)
#define CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV	CPU_DDR_CLOCK_CONTROL_CPU_POST_DIV_SET(0)

#else
#	error "CFG_PLL_FREQ not set"
#endif	// CFG_PLL_FREQ

#if CPU_AND_DDR_CLK_FROM_DDR && CPU_AND_DDR_CLK_FROM_CPU
#	error "Incorrect settings. Both 'from CPU' and 'from DDR' set"
#endif


#endif /* _QCA955X_H */
