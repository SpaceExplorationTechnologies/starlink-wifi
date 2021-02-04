/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _CE_WRAPPER_REG_CSR_H_
#define _CE_WRAPPER_REG_CSR_H_


#ifndef __CE_WRAPPER_REG_CSR_BASE_ADDRESS
#define __CE_WRAPPER_REG_CSR_BASE_ADDRESS (0x4d000)
#endif


// 0x0 (CE_WRAPPER_INTERRUPT_SUMMARY)
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_LSB                              12
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_MSB                              23
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_MASK                             0xfff000
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_GET(x)                           (((x) & CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_MASK) >> CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_LSB)
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_SET(x)                           (((0 | (x)) << CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_LSB) & CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_MASK)
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_RESET                            0x0
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_LSB                                  0
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_MSB                                  11
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_MASK                                 0xfff
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_GET(x)                               (((x) & CE_WRAPPER_INTERRUPT_SUMMARY_MISC_MASK) >> CE_WRAPPER_INTERRUPT_SUMMARY_MISC_LSB)
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_SET(x)                               (((0 | (x)) << CE_WRAPPER_INTERRUPT_SUMMARY_MISC_LSB) & CE_WRAPPER_INTERRUPT_SUMMARY_MISC_MASK)
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_RESET                                0x0
#define CE_WRAPPER_INTERRUPT_SUMMARY_ADDRESS                                   (0x0 + __CE_WRAPPER_REG_CSR_BASE_ADDRESS)
#define CE_WRAPPER_INTERRUPT_SUMMARY_RSTMASK                                   0xffffff
#define CE_WRAPPER_INTERRUPT_SUMMARY_RESET                                     0x0

// 0x4 (NUM_AXI_OUTSTANDING)
#define NUM_AXI_OUTSTANDING_WRITES_LSB                                         5
#define NUM_AXI_OUTSTANDING_WRITES_MSB                                         9
#define NUM_AXI_OUTSTANDING_WRITES_MASK                                        0x3e0
#define NUM_AXI_OUTSTANDING_WRITES_GET(x)                                      (((x) & NUM_AXI_OUTSTANDING_WRITES_MASK) >> NUM_AXI_OUTSTANDING_WRITES_LSB)
#define NUM_AXI_OUTSTANDING_WRITES_SET(x)                                      (((0 | (x)) << NUM_AXI_OUTSTANDING_WRITES_LSB) & NUM_AXI_OUTSTANDING_WRITES_MASK)
#define NUM_AXI_OUTSTANDING_WRITES_RESET                                       0x8
#define NUM_AXI_OUTSTANDING_READS_LSB                                          0
#define NUM_AXI_OUTSTANDING_READS_MSB                                          4
#define NUM_AXI_OUTSTANDING_READS_MASK                                         0x1f
#define NUM_AXI_OUTSTANDING_READS_GET(x)                                       (((x) & NUM_AXI_OUTSTANDING_READS_MASK) >> NUM_AXI_OUTSTANDING_READS_LSB)
#define NUM_AXI_OUTSTANDING_READS_SET(x)                                       (((0 | (x)) << NUM_AXI_OUTSTANDING_READS_LSB) & NUM_AXI_OUTSTANDING_READS_MASK)
#define NUM_AXI_OUTSTANDING_READS_RESET                                        0x18
#define NUM_AXI_OUTSTANDING_ADDRESS                                            (0x4 + __CE_WRAPPER_REG_CSR_BASE_ADDRESS)
#define NUM_AXI_OUTSTANDING_RSTMASK                                            0x3ff
#define NUM_AXI_OUTSTANDING_RESET                                              0x118

// 0x8 (CE_WRAPPER_DEBUG)
#define CE_WRAPPER_DEBUG_SEL_LSB                                               0
#define CE_WRAPPER_DEBUG_SEL_MSB                                               5
#define CE_WRAPPER_DEBUG_SEL_MASK                                              0x3f
#define CE_WRAPPER_DEBUG_SEL_GET(x)                                            (((x) & CE_WRAPPER_DEBUG_SEL_MASK) >> CE_WRAPPER_DEBUG_SEL_LSB)
#define CE_WRAPPER_DEBUG_SEL_SET(x)                                            (((0 | (x)) << CE_WRAPPER_DEBUG_SEL_LSB) & CE_WRAPPER_DEBUG_SEL_MASK)
#define CE_WRAPPER_DEBUG_SEL_RESET                                             0x0
#define CE_WRAPPER_DEBUG_ADDRESS                                               (0x8 + __CE_WRAPPER_REG_CSR_BASE_ADDRESS)
#define CE_WRAPPER_DEBUG_RSTMASK                                               0x3f
#define CE_WRAPPER_DEBUG_RESET                                                 0x0

// 0xc (CPU_MEM_ADDR)
#define CPU_MEM_ADDR_VAL_LSB                                                   0
#define CPU_MEM_ADDR_VAL_MSB                                                   31
#define CPU_MEM_ADDR_VAL_MASK                                                  0xffffffff
#define CPU_MEM_ADDR_VAL_GET(x)                                                (((x) & CPU_MEM_ADDR_VAL_MASK) >> CPU_MEM_ADDR_VAL_LSB)
#define CPU_MEM_ADDR_VAL_SET(x)                                                (((0 | (x)) << CPU_MEM_ADDR_VAL_LSB) & CPU_MEM_ADDR_VAL_MASK)
#define CPU_MEM_ADDR_VAL_RESET                                                 0x0
#define CPU_MEM_ADDR_ADDRESS                                                   (0xc + __CE_WRAPPER_REG_CSR_BASE_ADDRESS)
#define CPU_MEM_ADDR_RSTMASK                                                   0xffffffff
#define CPU_MEM_ADDR_RESET                                                     0x0

// 0x10 (CPU_MEM_DATA)
#define CPU_MEM_DATA_VAL_LSB                                                   0
#define CPU_MEM_DATA_VAL_MSB                                                   31
#define CPU_MEM_DATA_VAL_MASK                                                  0xffffffff
#define CPU_MEM_DATA_VAL_GET(x)                                                (((x) & CPU_MEM_DATA_VAL_MASK) >> CPU_MEM_DATA_VAL_LSB)
#define CPU_MEM_DATA_VAL_SET(x)                                                (((0 | (x)) << CPU_MEM_DATA_VAL_LSB) & CPU_MEM_DATA_VAL_MASK)
#define CPU_MEM_DATA_VAL_RESET                                                 0x0
#define CPU_MEM_DATA_ADDRESS                                                   (0x10 + __CE_WRAPPER_REG_CSR_BASE_ADDRESS)
#define CPU_MEM_DATA_RSTMASK                                                   0xffffffff
#define CPU_MEM_DATA_RESET                                                     0x0

// 0x14 (CE_WRAPPER_WDG_TMR_IS)
#define CE_WRAPPER_WDG_TMR_IS_VAL_LSB                                          0
#define CE_WRAPPER_WDG_TMR_IS_VAL_MSB                                          11
#define CE_WRAPPER_WDG_TMR_IS_VAL_MASK                                         0xfff
#define CE_WRAPPER_WDG_TMR_IS_VAL_GET(x)                                       (((x) & CE_WRAPPER_WDG_TMR_IS_VAL_MASK) >> CE_WRAPPER_WDG_TMR_IS_VAL_LSB)
#define CE_WRAPPER_WDG_TMR_IS_VAL_SET(x)                                       (((0 | (x)) << CE_WRAPPER_WDG_TMR_IS_VAL_LSB) & CE_WRAPPER_WDG_TMR_IS_VAL_MASK)
#define CE_WRAPPER_WDG_TMR_IS_VAL_RESET                                        0x0
#define CE_WRAPPER_WDG_TMR_IS_ADDRESS                                          (0x14 + __CE_WRAPPER_REG_CSR_BASE_ADDRESS)
#define CE_WRAPPER_WDG_TMR_IS_RSTMASK                                          0xfff
#define CE_WRAPPER_WDG_TMR_IS_RESET                                            0x0

// 0x18 (CE_WRAPPER_WDG_TMR_IE)
#define CE_WRAPPER_WDG_TMR_IE_VAL_LSB                                          0
#define CE_WRAPPER_WDG_TMR_IE_VAL_MSB                                          11
#define CE_WRAPPER_WDG_TMR_IE_VAL_MASK                                         0xfff
#define CE_WRAPPER_WDG_TMR_IE_VAL_GET(x)                                       (((x) & CE_WRAPPER_WDG_TMR_IE_VAL_MASK) >> CE_WRAPPER_WDG_TMR_IE_VAL_LSB)
#define CE_WRAPPER_WDG_TMR_IE_VAL_SET(x)                                       (((0 | (x)) << CE_WRAPPER_WDG_TMR_IE_VAL_LSB) & CE_WRAPPER_WDG_TMR_IE_VAL_MASK)
#define CE_WRAPPER_WDG_TMR_IE_VAL_RESET                                        0x0
#define CE_WRAPPER_WDG_TMR_IE_ADDRESS                                          (0x18 + __CE_WRAPPER_REG_CSR_BASE_ADDRESS)
#define CE_WRAPPER_WDG_TMR_IE_RSTMASK                                          0xfff
#define CE_WRAPPER_WDG_TMR_IE_RESET                                            0x0



#endif /* _CE_WRAPPER_REG_CSR_H_ */
