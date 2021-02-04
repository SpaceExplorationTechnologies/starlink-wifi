//                                                                             
// File:       ./ce_wrapper_reg_csr.vrh                                        
// Creator:    shung                                                           
// Time:       Monday Apr 23, 2012 [6:25:35 pm]                                
//                                                                             
// Path:       /trees/shung/shung-dev/chips/peregrine/1.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux/blueprint -odir . -codegen   
//             ath_vrh.codegen -ath_vrh -Wdesc -I                              
//             /trees/shung/shung-dev/chips/peregrine/1.0/blueprint/sysconfig  
//             ce_wrapper_reg_csr.rdl                                          
//                                                                             
// Sources:    /trees/shung/shung-dev/chips/peregrine/1.0/ip/athr/ce/rtl/blueprint/ce_wrapper_reg.rdl
//             /trees/shung/shung-dev/chips/peregrine/1.0/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Tue Jun 23 00:17:01 PDT 2009)                           
// Machine:    vnc2                                                            
// OS:         Linux 2.4.21-40.ELsmp                                           
// Description:                                                                
//                                                                             
// No Description Provided                                                     
/*
 * Copyright (c) 2012-14 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */


#ifndef _CE_WRAPPER_REG_CSR_H_
#define _CE_WRAPPER_REG_CSR_H_
// 0x0000 (CE_WRAPPER_INTERRUPT_SUMMARY)
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_MSB                    15
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_LSB                    8
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_MASK                   0x0000ff00
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_GET(x)                 (((x) & CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_MASK) >> CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_LSB)
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_SET(x)                 (((0 | (x)) << CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_LSB) & CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_MASK)
#define CE_WRAPPER_INTERRUPT_SUMMARY_HOST_MSI_RESET                  0
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_MSB                        7
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_LSB                        0
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_MASK                       0x000000ff
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_GET(x)                     (((x) & CE_WRAPPER_INTERRUPT_SUMMARY_MISC_MASK) >> CE_WRAPPER_INTERRUPT_SUMMARY_MISC_LSB)
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_SET(x)                     (((0 | (x)) << CE_WRAPPER_INTERRUPT_SUMMARY_MISC_LSB) & CE_WRAPPER_INTERRUPT_SUMMARY_MISC_MASK)
#define CE_WRAPPER_INTERRUPT_SUMMARY_MISC_RESET                      0
#define CE_WRAPPER_INTERRUPT_SUMMARY_ADDRESS                         0x0000
#define CE_WRAPPER_INTERRUPT_SUMMARY_HW_MASK                         0x0000ffff
#define CE_WRAPPER_INTERRUPT_SUMMARY_SW_MASK                         0x0000ffff
#define CE_WRAPPER_INTERRUPT_SUMMARY_HW_WRITE_MASK                   0x0000ffff
#define CE_WRAPPER_INTERRUPT_SUMMARY_SW_WRITE_MASK                   0x00000000
#define CE_WRAPPER_INTERRUPT_SUMMARY_RSTMASK                         0xffffffff
#define CE_WRAPPER_INTERRUPT_SUMMARY_RESET                           0x00000000

// 0x0004 (NUM_AXI_OUTSTANDING)
#define NUM_AXI_OUTSTANDING_WRITES_MSB                               9
#define NUM_AXI_OUTSTANDING_WRITES_LSB                               5
#define NUM_AXI_OUTSTANDING_WRITES_MASK                              0x000003e0
#define NUM_AXI_OUTSTANDING_WRITES_GET(x)                            (((x) & NUM_AXI_OUTSTANDING_WRITES_MASK) >> NUM_AXI_OUTSTANDING_WRITES_LSB)
#define NUM_AXI_OUTSTANDING_WRITES_SET(x)                            (((0 | (x)) << NUM_AXI_OUTSTANDING_WRITES_LSB) & NUM_AXI_OUTSTANDING_WRITES_MASK)
#define NUM_AXI_OUTSTANDING_WRITES_RESET                             8
#define NUM_AXI_OUTSTANDING_READS_MSB                                4
#define NUM_AXI_OUTSTANDING_READS_LSB                                0
#define NUM_AXI_OUTSTANDING_READS_MASK                               0x0000001f
#define NUM_AXI_OUTSTANDING_READS_GET(x)                             (((x) & NUM_AXI_OUTSTANDING_READS_MASK) >> NUM_AXI_OUTSTANDING_READS_LSB)
#define NUM_AXI_OUTSTANDING_READS_SET(x)                             (((0 | (x)) << NUM_AXI_OUTSTANDING_READS_LSB) & NUM_AXI_OUTSTANDING_READS_MASK)
#define NUM_AXI_OUTSTANDING_READS_RESET                              24
#define NUM_AXI_OUTSTANDING_ADDRESS                                  0x0004
#define NUM_AXI_OUTSTANDING_HW_MASK                                  0x000003ff
#define NUM_AXI_OUTSTANDING_SW_MASK                                  0x000003ff
#define NUM_AXI_OUTSTANDING_HW_WRITE_MASK                            0x00000000
#define NUM_AXI_OUTSTANDING_SW_WRITE_MASK                            0x000003ff
#define NUM_AXI_OUTSTANDING_RSTMASK                                  0xffffffff
#define NUM_AXI_OUTSTANDING_RESET                                    0x00000118

// 0x0008 (CE_WRAPPER_DEBUG)
#define CE_WRAPPER_DEBUG_SEL_MSB                                     5
#define CE_WRAPPER_DEBUG_SEL_LSB                                     0
#define CE_WRAPPER_DEBUG_SEL_MASK                                    0x0000003f
#define CE_WRAPPER_DEBUG_SEL_GET(x)                                  (((x) & CE_WRAPPER_DEBUG_SEL_MASK) >> CE_WRAPPER_DEBUG_SEL_LSB)
#define CE_WRAPPER_DEBUG_SEL_SET(x)                                  (((0 | (x)) << CE_WRAPPER_DEBUG_SEL_LSB) & CE_WRAPPER_DEBUG_SEL_MASK)
#define CE_WRAPPER_DEBUG_SEL_RESET                                   0
#define CE_WRAPPER_DEBUG_ADDRESS                                     0x0008
#define CE_WRAPPER_DEBUG_HW_MASK                                     0x0000003f
#define CE_WRAPPER_DEBUG_SW_MASK                                     0x0000003f
#define CE_WRAPPER_DEBUG_HW_WRITE_MASK                               0x00000000
#define CE_WRAPPER_DEBUG_SW_WRITE_MASK                               0x0000003f
#define CE_WRAPPER_DEBUG_RSTMASK                                     0xffffffff
#define CE_WRAPPER_DEBUG_RESET                                       0x00000000


#endif /* _CE_WRAPPER_REG_CSR_H_ */
