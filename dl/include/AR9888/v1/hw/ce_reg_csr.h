//                                                                             
// File:       ./ce_reg_csr.vrh                                                
// Creator:    shung                                                           
// Time:       Monday Apr 23, 2012 [6:25:34 pm]                                
//                                                                             
// Path:       /trees/shung/shung-dev/chips/peregrine/1.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux/blueprint -odir . -codegen   
//             ath_vrh.codegen -ath_vrh -Wdesc -I                              
//             /trees/shung/shung-dev/chips/peregrine/1.0/blueprint/sysconfig  
//             ce_reg_csr.rdl                                                  
//                                                                             
// Sources:    /trees/shung/shung-dev/chips/peregrine/1.0/ip/athr/ce/rtl/blueprint/ce_reg.rdl
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


#ifndef _CE_REG_CSR_H_
#define _CE_REG_CSR_H_
// 0x0000 (SR_BA)
#define SR_BA_V_MSB                                                  31
#define SR_BA_V_LSB                                                  0
#define SR_BA_V_MASK                                                 0xffffffff
#define SR_BA_V_GET(x)                                               (((x) & SR_BA_V_MASK) >> SR_BA_V_LSB)
#define SR_BA_V_SET(x)                                               (((0 | (x)) << SR_BA_V_LSB) & SR_BA_V_MASK)
#define SR_BA_V_RESET                                                0
#define SR_BA_ADDRESS                                                0x0000
#define SR_BA_HW_MASK                                                0xffffffff
#define SR_BA_SW_MASK                                                0xffffffff
#define SR_BA_HW_WRITE_MASK                                          0x00000000
#define SR_BA_SW_WRITE_MASK                                          0xffffffff
#define SR_BA_RSTMASK                                                0xffffffff
#define SR_BA_RESET                                                  0x00000000

// 0x0004 (SR_SIZE)
#define SR_SIZE_V_MSB                                                15
#define SR_SIZE_V_LSB                                                0
#define SR_SIZE_V_MASK                                               0x0000ffff
#define SR_SIZE_V_GET(x)                                             (((x) & SR_SIZE_V_MASK) >> SR_SIZE_V_LSB)
#define SR_SIZE_V_SET(x)                                             (((0 | (x)) << SR_SIZE_V_LSB) & SR_SIZE_V_MASK)
#define SR_SIZE_V_RESET                                              0
#define SR_SIZE_ADDRESS                                              0x0004
#define SR_SIZE_HW_MASK                                              0x0000ffff
#define SR_SIZE_SW_MASK                                              0x0000ffff
#define SR_SIZE_HW_WRITE_MASK                                        0x00000000
#define SR_SIZE_SW_WRITE_MASK                                        0x0000ffff
#define SR_SIZE_RSTMASK                                              0xffffffff
#define SR_SIZE_RESET                                                0x00000000

// 0x0008 (DR_BA)
#define DR_BA_V_MSB                                                  31
#define DR_BA_V_LSB                                                  0
#define DR_BA_V_MASK                                                 0xffffffff
#define DR_BA_V_GET(x)                                               (((x) & DR_BA_V_MASK) >> DR_BA_V_LSB)
#define DR_BA_V_SET(x)                                               (((0 | (x)) << DR_BA_V_LSB) & DR_BA_V_MASK)
#define DR_BA_V_RESET                                                0
#define DR_BA_ADDRESS                                                0x0008
#define DR_BA_HW_MASK                                                0xffffffff
#define DR_BA_SW_MASK                                                0xffffffff
#define DR_BA_HW_WRITE_MASK                                          0x00000000
#define DR_BA_SW_WRITE_MASK                                          0xffffffff
#define DR_BA_RSTMASK                                                0xffffffff
#define DR_BA_RESET                                                  0x00000000

// 0x000c (DR_SIZE)
#define DR_SIZE_V_MSB                                                15
#define DR_SIZE_V_LSB                                                0
#define DR_SIZE_V_MASK                                               0x0000ffff
#define DR_SIZE_V_GET(x)                                             (((x) & DR_SIZE_V_MASK) >> DR_SIZE_V_LSB)
#define DR_SIZE_V_SET(x)                                             (((0 | (x)) << DR_SIZE_V_LSB) & DR_SIZE_V_MASK)
#define DR_SIZE_V_RESET                                              0
#define DR_SIZE_ADDRESS                                              0x000c
#define DR_SIZE_HW_MASK                                              0x0000ffff
#define DR_SIZE_SW_MASK                                              0x0000ffff
#define DR_SIZE_HW_WRITE_MASK                                        0x00000000
#define DR_SIZE_SW_WRITE_MASK                                        0x0000ffff
#define DR_SIZE_RSTMASK                                              0xffffffff
#define DR_SIZE_RESET                                                0x00000000

// 0x0010 (CE_CTRL1)
#define CE_CTRL1_MSI_EN_MSB                                          18
#define CE_CTRL1_MSI_EN_LSB                                          18
#define CE_CTRL1_MSI_EN_MASK                                         0x00040000
#define CE_CTRL1_MSI_EN_GET(x)                                       (((x) & CE_CTRL1_MSI_EN_MASK) >> CE_CTRL1_MSI_EN_LSB)
#define CE_CTRL1_MSI_EN_SET(x)                                       (((0 | (x)) << CE_CTRL1_MSI_EN_LSB) & CE_CTRL1_MSI_EN_MASK)
#define CE_CTRL1_MSI_EN_RESET                                        0
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_MSB                           17
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_LSB                           17
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_MASK                          0x00020000
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_GET(x)                        (((x) & CE_CTRL1_DST_RING_BYTE_SWAP_EN_MASK) >> CE_CTRL1_DST_RING_BYTE_SWAP_EN_LSB)
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_SET(x)                        (((0 | (x)) << CE_CTRL1_DST_RING_BYTE_SWAP_EN_LSB) & CE_CTRL1_DST_RING_BYTE_SWAP_EN_MASK)
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_RESET                         0
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_MSB                           16
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_LSB                           16
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_MASK                          0x00010000
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_GET(x)                        (((x) & CE_CTRL1_SRC_RING_BYTE_SWAP_EN_MASK) >> CE_CTRL1_SRC_RING_BYTE_SWAP_EN_LSB)
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_SET(x)                        (((0 | (x)) << CE_CTRL1_SRC_RING_BYTE_SWAP_EN_LSB) & CE_CTRL1_SRC_RING_BYTE_SWAP_EN_MASK)
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_RESET                         0
#define CE_CTRL1_DMAX_LENGTH_MSB                                     15
#define CE_CTRL1_DMAX_LENGTH_LSB                                     0
#define CE_CTRL1_DMAX_LENGTH_MASK                                    0x0000ffff
#define CE_CTRL1_DMAX_LENGTH_GET(x)                                  (((x) & CE_CTRL1_DMAX_LENGTH_MASK) >> CE_CTRL1_DMAX_LENGTH_LSB)
#define CE_CTRL1_DMAX_LENGTH_SET(x)                                  (((0 | (x)) << CE_CTRL1_DMAX_LENGTH_LSB) & CE_CTRL1_DMAX_LENGTH_MASK)
#define CE_CTRL1_DMAX_LENGTH_RESET                                   128
#define CE_CTRL1_ADDRESS                                             0x0010
#define CE_CTRL1_HW_MASK                                             0x0007ffff
#define CE_CTRL1_SW_MASK                                             0x0007ffff
#define CE_CTRL1_HW_WRITE_MASK                                       0x00000000
#define CE_CTRL1_SW_WRITE_MASK                                       0x0007ffff
#define CE_CTRL1_RSTMASK                                             0xffffffff
#define CE_CTRL1_RESET                                               0x00000080

// 0x0014 (CE_CTRL2)
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_MSB                      29
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_LSB                      25
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_MASK                     0x3e000000
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_GET(x)                   (((x) & CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_MASK) >> CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_LSB)
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_SET(x)                   (((0 | (x)) << CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_LSB) & CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_MASK)
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_RESET                    8
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_MSB                       24
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_LSB                       20
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_MASK                      0x01f00000
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_GET(x)                    (((x) & CE_CTRL2_NUM_AXI_OUTSTANDING_READS_MASK) >> CE_CTRL2_NUM_AXI_OUTSTANDING_READS_LSB)
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_SET(x)                    (((0 | (x)) << CE_CTRL2_NUM_AXI_OUTSTANDING_READS_LSB) & CE_CTRL2_NUM_AXI_OUTSTANDING_READS_MASK)
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_RESET                     24
#define CE_CTRL2_AXI_TIMEOUT_MSB                                     19
#define CE_CTRL2_AXI_TIMEOUT_LSB                                     4
#define CE_CTRL2_AXI_TIMEOUT_MASK                                    0x000ffff0
#define CE_CTRL2_AXI_TIMEOUT_GET(x)                                  (((x) & CE_CTRL2_AXI_TIMEOUT_MASK) >> CE_CTRL2_AXI_TIMEOUT_LSB)
#define CE_CTRL2_AXI_TIMEOUT_SET(x)                                  (((0 | (x)) << CE_CTRL2_AXI_TIMEOUT_LSB) & CE_CTRL2_AXI_TIMEOUT_MASK)
#define CE_CTRL2_AXI_TIMEOUT_RESET                                   8000
#define CE_CTRL2_DEST_AXI_MAX_LEN_MSB                                3
#define CE_CTRL2_DEST_AXI_MAX_LEN_LSB                                2
#define CE_CTRL2_DEST_AXI_MAX_LEN_MASK                               0x0000000c
#define CE_CTRL2_DEST_AXI_MAX_LEN_GET(x)                             (((x) & CE_CTRL2_DEST_AXI_MAX_LEN_MASK) >> CE_CTRL2_DEST_AXI_MAX_LEN_LSB)
#define CE_CTRL2_DEST_AXI_MAX_LEN_SET(x)                             (((0 | (x)) << CE_CTRL2_DEST_AXI_MAX_LEN_LSB) & CE_CTRL2_DEST_AXI_MAX_LEN_MASK)
#define CE_CTRL2_DEST_AXI_MAX_LEN_RESET                              1
#define CE_CTRL2_SRC_AXI_MAX_LEN_MSB                                 1
#define CE_CTRL2_SRC_AXI_MAX_LEN_LSB                                 0
#define CE_CTRL2_SRC_AXI_MAX_LEN_MASK                                0x00000003
#define CE_CTRL2_SRC_AXI_MAX_LEN_GET(x)                              (((x) & CE_CTRL2_SRC_AXI_MAX_LEN_MASK) >> CE_CTRL2_SRC_AXI_MAX_LEN_LSB)
#define CE_CTRL2_SRC_AXI_MAX_LEN_SET(x)                              (((0 | (x)) << CE_CTRL2_SRC_AXI_MAX_LEN_LSB) & CE_CTRL2_SRC_AXI_MAX_LEN_MASK)
#define CE_CTRL2_SRC_AXI_MAX_LEN_RESET                               1
#define CE_CTRL2_ADDRESS                                             0x0014
#define CE_CTRL2_HW_MASK                                             0x3fffffff
#define CE_CTRL2_SW_MASK                                             0x3fffffff
#define CE_CTRL2_HW_WRITE_MASK                                       0x00000000
#define CE_CTRL2_SW_WRITE_MASK                                       0x3fffffff
#define CE_CTRL2_RSTMASK                                             0xffffffff
#define CE_CTRL2_RESET                                               0x1181f405

// 0x0018 (CE_CMD)
#define CE_CMD_HALT_STATUS_MSB                                       3
#define CE_CMD_HALT_STATUS_LSB                                       3
#define CE_CMD_HALT_STATUS_MASK                                      0x00000008
#define CE_CMD_HALT_STATUS_GET(x)                                    (((x) & CE_CMD_HALT_STATUS_MASK) >> CE_CMD_HALT_STATUS_LSB)
#define CE_CMD_HALT_STATUS_SET(x)                                    (((0 | (x)) << CE_CMD_HALT_STATUS_LSB) & CE_CMD_HALT_STATUS_MASK)
#define CE_CMD_HALT_STATUS_RESET                                     0
#define CE_CMD_DST_FLUSH_MSB                                         2
#define CE_CMD_DST_FLUSH_LSB                                         2
#define CE_CMD_DST_FLUSH_MASK                                        0x00000004
#define CE_CMD_DST_FLUSH_GET(x)                                      (((x) & CE_CMD_DST_FLUSH_MASK) >> CE_CMD_DST_FLUSH_LSB)
#define CE_CMD_DST_FLUSH_SET(x)                                      (((0 | (x)) << CE_CMD_DST_FLUSH_LSB) & CE_CMD_DST_FLUSH_MASK)
#define CE_CMD_DST_FLUSH_RESET                                       0
#define CE_CMD_SRC_FLUSH_MSB                                         1
#define CE_CMD_SRC_FLUSH_LSB                                         1
#define CE_CMD_SRC_FLUSH_MASK                                        0x00000002
#define CE_CMD_SRC_FLUSH_GET(x)                                      (((x) & CE_CMD_SRC_FLUSH_MASK) >> CE_CMD_SRC_FLUSH_LSB)
#define CE_CMD_SRC_FLUSH_SET(x)                                      (((0 | (x)) << CE_CMD_SRC_FLUSH_LSB) & CE_CMD_SRC_FLUSH_MASK)
#define CE_CMD_SRC_FLUSH_RESET                                       0
#define CE_CMD_HALT_MSB                                              0
#define CE_CMD_HALT_LSB                                              0
#define CE_CMD_HALT_MASK                                             0x00000001
#define CE_CMD_HALT_GET(x)                                           (((x) & CE_CMD_HALT_MASK) >> CE_CMD_HALT_LSB)
#define CE_CMD_HALT_SET(x)                                           (((0 | (x)) << CE_CMD_HALT_LSB) & CE_CMD_HALT_MASK)
#define CE_CMD_HALT_RESET                                            0
#define CE_CMD_ADDRESS                                               0x0018
#define CE_CMD_HW_MASK                                               0x0000000f
#define CE_CMD_SW_MASK                                               0x0000000f
#define CE_CMD_HW_WRITE_MASK                                         0x00000008
#define CE_CMD_SW_WRITE_MASK                                         0x00000007
#define CE_CMD_RSTMASK                                               0xffffffff
#define CE_CMD_RESET                                                 0x00000000

// 0x001c (MSI_ADDR)
#define MSI_ADDR_V_MSB                                               31
#define MSI_ADDR_V_LSB                                               0
#define MSI_ADDR_V_MASK                                              0xffffffff
#define MSI_ADDR_V_GET(x)                                            (((x) & MSI_ADDR_V_MASK) >> MSI_ADDR_V_LSB)
#define MSI_ADDR_V_SET(x)                                            (((0 | (x)) << MSI_ADDR_V_LSB) & MSI_ADDR_V_MASK)
#define MSI_ADDR_V_RESET                                             0
#define MSI_ADDR_ADDRESS                                             0x001c
#define MSI_ADDR_HW_MASK                                             0xffffffff
#define MSI_ADDR_SW_MASK                                             0xffffffff
#define MSI_ADDR_HW_WRITE_MASK                                       0x00000000
#define MSI_ADDR_SW_WRITE_MASK                                       0xffffffff
#define MSI_ADDR_RSTMASK                                             0xffffffff
#define MSI_ADDR_RESET                                               0x00000000

// 0x0020 (MSI_DATA)
#define MSI_DATA_V_MSB                                               31
#define MSI_DATA_V_LSB                                               0
#define MSI_DATA_V_MASK                                              0xffffffff
#define MSI_DATA_V_GET(x)                                            (((x) & MSI_DATA_V_MASK) >> MSI_DATA_V_LSB)
#define MSI_DATA_V_SET(x)                                            (((0 | (x)) << MSI_DATA_V_LSB) & MSI_DATA_V_MASK)
#define MSI_DATA_V_RESET                                             0
#define MSI_DATA_ADDRESS                                             0x0020
#define MSI_DATA_HW_MASK                                             0xffffffff
#define MSI_DATA_SW_MASK                                             0xffffffff
#define MSI_DATA_HW_WRITE_MASK                                       0x00000000
#define MSI_DATA_SW_WRITE_MASK                                       0xffffffff
#define MSI_DATA_RSTMASK                                             0xffffffff
#define MSI_DATA_RESET                                               0x00000000

// 0x0024 (TARGET_IE)
#define TARGET_IE_DST_RING_LOW_WATERMARK_MSB                         4
#define TARGET_IE_DST_RING_LOW_WATERMARK_LSB                         4
#define TARGET_IE_DST_RING_LOW_WATERMARK_MASK                        0x00000010
#define TARGET_IE_DST_RING_LOW_WATERMARK_GET(x)                      (((x) & TARGET_IE_DST_RING_LOW_WATERMARK_MASK) >> TARGET_IE_DST_RING_LOW_WATERMARK_LSB)
#define TARGET_IE_DST_RING_LOW_WATERMARK_SET(x)                      (((0 | (x)) << TARGET_IE_DST_RING_LOW_WATERMARK_LSB) & TARGET_IE_DST_RING_LOW_WATERMARK_MASK)
#define TARGET_IE_DST_RING_LOW_WATERMARK_RESET                       0
#define TARGET_IE_DST_RING_HIGH_WATERMARK_MSB                        3
#define TARGET_IE_DST_RING_HIGH_WATERMARK_LSB                        3
#define TARGET_IE_DST_RING_HIGH_WATERMARK_MASK                       0x00000008
#define TARGET_IE_DST_RING_HIGH_WATERMARK_GET(x)                     (((x) & TARGET_IE_DST_RING_HIGH_WATERMARK_MASK) >> TARGET_IE_DST_RING_HIGH_WATERMARK_LSB)
#define TARGET_IE_DST_RING_HIGH_WATERMARK_SET(x)                     (((0 | (x)) << TARGET_IE_DST_RING_HIGH_WATERMARK_LSB) & TARGET_IE_DST_RING_HIGH_WATERMARK_MASK)
#define TARGET_IE_DST_RING_HIGH_WATERMARK_RESET                      0
#define TARGET_IE_SRC_RING_LOW_WATERMARK_MSB                         2
#define TARGET_IE_SRC_RING_LOW_WATERMARK_LSB                         2
#define TARGET_IE_SRC_RING_LOW_WATERMARK_MASK                        0x00000004
#define TARGET_IE_SRC_RING_LOW_WATERMARK_GET(x)                      (((x) & TARGET_IE_SRC_RING_LOW_WATERMARK_MASK) >> TARGET_IE_SRC_RING_LOW_WATERMARK_LSB)
#define TARGET_IE_SRC_RING_LOW_WATERMARK_SET(x)                      (((0 | (x)) << TARGET_IE_SRC_RING_LOW_WATERMARK_LSB) & TARGET_IE_SRC_RING_LOW_WATERMARK_MASK)
#define TARGET_IE_SRC_RING_LOW_WATERMARK_RESET                       0
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_MSB                        1
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_LSB                        1
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_MASK                       0x00000002
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_GET(x)                     (((x) & TARGET_IE_SRC_RING_HIGH_WATERMARK_MASK) >> TARGET_IE_SRC_RING_HIGH_WATERMARK_LSB)
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_SET(x)                     (((0 | (x)) << TARGET_IE_SRC_RING_HIGH_WATERMARK_LSB) & TARGET_IE_SRC_RING_HIGH_WATERMARK_MASK)
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_RESET                      0
#define TARGET_IE_COPY_COMPLETE_MSB                                  0
#define TARGET_IE_COPY_COMPLETE_LSB                                  0
#define TARGET_IE_COPY_COMPLETE_MASK                                 0x00000001
#define TARGET_IE_COPY_COMPLETE_GET(x)                               (((x) & TARGET_IE_COPY_COMPLETE_MASK) >> TARGET_IE_COPY_COMPLETE_LSB)
#define TARGET_IE_COPY_COMPLETE_SET(x)                               (((0 | (x)) << TARGET_IE_COPY_COMPLETE_LSB) & TARGET_IE_COPY_COMPLETE_MASK)
#define TARGET_IE_COPY_COMPLETE_RESET                                0
#define TARGET_IE_ADDRESS                                            0x0024
#define TARGET_IE_HW_MASK                                            0x0000001f
#define TARGET_IE_SW_MASK                                            0x0000001f
#define TARGET_IE_HW_WRITE_MASK                                      0x00000000
#define TARGET_IE_SW_WRITE_MASK                                      0x0000001f
#define TARGET_IE_RSTMASK                                            0xffffffff
#define TARGET_IE_RESET                                              0x00000000

// 0x0028 (TARGET_IS)
#define TARGET_IS_DST_RING_LOW_WATERMARK_MSB                         4
#define TARGET_IS_DST_RING_LOW_WATERMARK_LSB                         4
#define TARGET_IS_DST_RING_LOW_WATERMARK_MASK                        0x00000010
#define TARGET_IS_DST_RING_LOW_WATERMARK_GET(x)                      (((x) & TARGET_IS_DST_RING_LOW_WATERMARK_MASK) >> TARGET_IS_DST_RING_LOW_WATERMARK_LSB)
#define TARGET_IS_DST_RING_LOW_WATERMARK_SET(x)                      (((0 | (x)) << TARGET_IS_DST_RING_LOW_WATERMARK_LSB) & TARGET_IS_DST_RING_LOW_WATERMARK_MASK)
#define TARGET_IS_DST_RING_LOW_WATERMARK_RESET                       0
#define TARGET_IS_DST_RING_HIGH_WATERMARK_MSB                        3
#define TARGET_IS_DST_RING_HIGH_WATERMARK_LSB                        3
#define TARGET_IS_DST_RING_HIGH_WATERMARK_MASK                       0x00000008
#define TARGET_IS_DST_RING_HIGH_WATERMARK_GET(x)                     (((x) & TARGET_IS_DST_RING_HIGH_WATERMARK_MASK) >> TARGET_IS_DST_RING_HIGH_WATERMARK_LSB)
#define TARGET_IS_DST_RING_HIGH_WATERMARK_SET(x)                     (((0 | (x)) << TARGET_IS_DST_RING_HIGH_WATERMARK_LSB) & TARGET_IS_DST_RING_HIGH_WATERMARK_MASK)
#define TARGET_IS_DST_RING_HIGH_WATERMARK_RESET                      0
#define TARGET_IS_SRC_RING_LOW_WATERMARK_MSB                         2
#define TARGET_IS_SRC_RING_LOW_WATERMARK_LSB                         2
#define TARGET_IS_SRC_RING_LOW_WATERMARK_MASK                        0x00000004
#define TARGET_IS_SRC_RING_LOW_WATERMARK_GET(x)                      (((x) & TARGET_IS_SRC_RING_LOW_WATERMARK_MASK) >> TARGET_IS_SRC_RING_LOW_WATERMARK_LSB)
#define TARGET_IS_SRC_RING_LOW_WATERMARK_SET(x)                      (((0 | (x)) << TARGET_IS_SRC_RING_LOW_WATERMARK_LSB) & TARGET_IS_SRC_RING_LOW_WATERMARK_MASK)
#define TARGET_IS_SRC_RING_LOW_WATERMARK_RESET                       0
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_MSB                        1
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_LSB                        1
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_MASK                       0x00000002
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_GET(x)                     (((x) & TARGET_IS_SRC_RING_HIGH_WATERMARK_MASK) >> TARGET_IS_SRC_RING_HIGH_WATERMARK_LSB)
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_SET(x)                     (((0 | (x)) << TARGET_IS_SRC_RING_HIGH_WATERMARK_LSB) & TARGET_IS_SRC_RING_HIGH_WATERMARK_MASK)
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_RESET                      0
#define TARGET_IS_COPY_COMPLETE_MSB                                  0
#define TARGET_IS_COPY_COMPLETE_LSB                                  0
#define TARGET_IS_COPY_COMPLETE_MASK                                 0x00000001
#define TARGET_IS_COPY_COMPLETE_GET(x)                               (((x) & TARGET_IS_COPY_COMPLETE_MASK) >> TARGET_IS_COPY_COMPLETE_LSB)
#define TARGET_IS_COPY_COMPLETE_SET(x)                               (((0 | (x)) << TARGET_IS_COPY_COMPLETE_LSB) & TARGET_IS_COPY_COMPLETE_MASK)
#define TARGET_IS_COPY_COMPLETE_RESET                                0
#define TARGET_IS_ADDRESS                                            0x0028
#define TARGET_IS_HW_MASK                                            0x0000001f
#define TARGET_IS_SW_MASK                                            0x0000001f
#define TARGET_IS_HW_WRITE_MASK                                      0x0000001f
#define TARGET_IS_SW_WRITE_MASK                                      0x0000001f
#define TARGET_IS_RSTMASK                                            0xffffffff
#define TARGET_IS_RESET                                              0x00000000

// 0x002c (HOST_IE)
#define HOST_IE_DST_RING_LOW_WATERMARK_MSB                           4
#define HOST_IE_DST_RING_LOW_WATERMARK_LSB                           4
#define HOST_IE_DST_RING_LOW_WATERMARK_MASK                          0x00000010
#define HOST_IE_DST_RING_LOW_WATERMARK_GET(x)                        (((x) & HOST_IE_DST_RING_LOW_WATERMARK_MASK) >> HOST_IE_DST_RING_LOW_WATERMARK_LSB)
#define HOST_IE_DST_RING_LOW_WATERMARK_SET(x)                        (((0 | (x)) << HOST_IE_DST_RING_LOW_WATERMARK_LSB) & HOST_IE_DST_RING_LOW_WATERMARK_MASK)
#define HOST_IE_DST_RING_LOW_WATERMARK_RESET                         0
#define HOST_IE_DST_RING_HIGH_WATERMARK_MSB                          3
#define HOST_IE_DST_RING_HIGH_WATERMARK_LSB                          3
#define HOST_IE_DST_RING_HIGH_WATERMARK_MASK                         0x00000008
#define HOST_IE_DST_RING_HIGH_WATERMARK_GET(x)                       (((x) & HOST_IE_DST_RING_HIGH_WATERMARK_MASK) >> HOST_IE_DST_RING_HIGH_WATERMARK_LSB)
#define HOST_IE_DST_RING_HIGH_WATERMARK_SET(x)                       (((0 | (x)) << HOST_IE_DST_RING_HIGH_WATERMARK_LSB) & HOST_IE_DST_RING_HIGH_WATERMARK_MASK)
#define HOST_IE_DST_RING_HIGH_WATERMARK_RESET                        0
#define HOST_IE_SRC_RING_LOW_WATERMARK_MSB                           2
#define HOST_IE_SRC_RING_LOW_WATERMARK_LSB                           2
#define HOST_IE_SRC_RING_LOW_WATERMARK_MASK                          0x00000004
#define HOST_IE_SRC_RING_LOW_WATERMARK_GET(x)                        (((x) & HOST_IE_SRC_RING_LOW_WATERMARK_MASK) >> HOST_IE_SRC_RING_LOW_WATERMARK_LSB)
#define HOST_IE_SRC_RING_LOW_WATERMARK_SET(x)                        (((0 | (x)) << HOST_IE_SRC_RING_LOW_WATERMARK_LSB) & HOST_IE_SRC_RING_LOW_WATERMARK_MASK)
#define HOST_IE_SRC_RING_LOW_WATERMARK_RESET                         0
#define HOST_IE_SRC_RING_HIGH_WATERMARK_MSB                          1
#define HOST_IE_SRC_RING_HIGH_WATERMARK_LSB                          1
#define HOST_IE_SRC_RING_HIGH_WATERMARK_MASK                         0x00000002
#define HOST_IE_SRC_RING_HIGH_WATERMARK_GET(x)                       (((x) & HOST_IE_SRC_RING_HIGH_WATERMARK_MASK) >> HOST_IE_SRC_RING_HIGH_WATERMARK_LSB)
#define HOST_IE_SRC_RING_HIGH_WATERMARK_SET(x)                       (((0 | (x)) << HOST_IE_SRC_RING_HIGH_WATERMARK_LSB) & HOST_IE_SRC_RING_HIGH_WATERMARK_MASK)
#define HOST_IE_SRC_RING_HIGH_WATERMARK_RESET                        0
#define HOST_IE_COPY_COMPLETE_MSB                                    0
#define HOST_IE_COPY_COMPLETE_LSB                                    0
#define HOST_IE_COPY_COMPLETE_MASK                                   0x00000001
#define HOST_IE_COPY_COMPLETE_GET(x)                                 (((x) & HOST_IE_COPY_COMPLETE_MASK) >> HOST_IE_COPY_COMPLETE_LSB)
#define HOST_IE_COPY_COMPLETE_SET(x)                                 (((0 | (x)) << HOST_IE_COPY_COMPLETE_LSB) & HOST_IE_COPY_COMPLETE_MASK)
#define HOST_IE_COPY_COMPLETE_RESET                                  0
#define HOST_IE_ADDRESS                                              0x002c
#define HOST_IE_HW_MASK                                              0x0000001f
#define HOST_IE_SW_MASK                                              0x0000001f
#define HOST_IE_HW_WRITE_MASK                                        0x00000000
#define HOST_IE_SW_WRITE_MASK                                        0x0000001f
#define HOST_IE_RSTMASK                                              0xffffffff
#define HOST_IE_RESET                                                0x00000000

// 0x0030 (HOST_IS)
#define HOST_IS_DST_RING_LOW_WATERMARK_MSB                           4
#define HOST_IS_DST_RING_LOW_WATERMARK_LSB                           4
#define HOST_IS_DST_RING_LOW_WATERMARK_MASK                          0x00000010
#define HOST_IS_DST_RING_LOW_WATERMARK_GET(x)                        (((x) & HOST_IS_DST_RING_LOW_WATERMARK_MASK) >> HOST_IS_DST_RING_LOW_WATERMARK_LSB)
#define HOST_IS_DST_RING_LOW_WATERMARK_SET(x)                        (((0 | (x)) << HOST_IS_DST_RING_LOW_WATERMARK_LSB) & HOST_IS_DST_RING_LOW_WATERMARK_MASK)
#define HOST_IS_DST_RING_LOW_WATERMARK_RESET                         0
#define HOST_IS_DST_RING_HIGH_WATERMARK_MSB                          3
#define HOST_IS_DST_RING_HIGH_WATERMARK_LSB                          3
#define HOST_IS_DST_RING_HIGH_WATERMARK_MASK                         0x00000008
#define HOST_IS_DST_RING_HIGH_WATERMARK_GET(x)                       (((x) & HOST_IS_DST_RING_HIGH_WATERMARK_MASK) >> HOST_IS_DST_RING_HIGH_WATERMARK_LSB)
#define HOST_IS_DST_RING_HIGH_WATERMARK_SET(x)                       (((0 | (x)) << HOST_IS_DST_RING_HIGH_WATERMARK_LSB) & HOST_IS_DST_RING_HIGH_WATERMARK_MASK)
#define HOST_IS_DST_RING_HIGH_WATERMARK_RESET                        0
#define HOST_IS_SRC_RING_LOW_WATERMARK_MSB                           2
#define HOST_IS_SRC_RING_LOW_WATERMARK_LSB                           2
#define HOST_IS_SRC_RING_LOW_WATERMARK_MASK                          0x00000004
#define HOST_IS_SRC_RING_LOW_WATERMARK_GET(x)                        (((x) & HOST_IS_SRC_RING_LOW_WATERMARK_MASK) >> HOST_IS_SRC_RING_LOW_WATERMARK_LSB)
#define HOST_IS_SRC_RING_LOW_WATERMARK_SET(x)                        (((0 | (x)) << HOST_IS_SRC_RING_LOW_WATERMARK_LSB) & HOST_IS_SRC_RING_LOW_WATERMARK_MASK)
#define HOST_IS_SRC_RING_LOW_WATERMARK_RESET                         0
#define HOST_IS_SRC_RING_HIGH_WATERMARK_MSB                          1
#define HOST_IS_SRC_RING_HIGH_WATERMARK_LSB                          1
#define HOST_IS_SRC_RING_HIGH_WATERMARK_MASK                         0x00000002
#define HOST_IS_SRC_RING_HIGH_WATERMARK_GET(x)                       (((x) & HOST_IS_SRC_RING_HIGH_WATERMARK_MASK) >> HOST_IS_SRC_RING_HIGH_WATERMARK_LSB)
#define HOST_IS_SRC_RING_HIGH_WATERMARK_SET(x)                       (((0 | (x)) << HOST_IS_SRC_RING_HIGH_WATERMARK_LSB) & HOST_IS_SRC_RING_HIGH_WATERMARK_MASK)
#define HOST_IS_SRC_RING_HIGH_WATERMARK_RESET                        0
#define HOST_IS_COPY_COMPLETE_MSB                                    0
#define HOST_IS_COPY_COMPLETE_LSB                                    0
#define HOST_IS_COPY_COMPLETE_MASK                                   0x00000001
#define HOST_IS_COPY_COMPLETE_GET(x)                                 (((x) & HOST_IS_COPY_COMPLETE_MASK) >> HOST_IS_COPY_COMPLETE_LSB)
#define HOST_IS_COPY_COMPLETE_SET(x)                                 (((0 | (x)) << HOST_IS_COPY_COMPLETE_LSB) & HOST_IS_COPY_COMPLETE_MASK)
#define HOST_IS_COPY_COMPLETE_RESET                                  0
#define HOST_IS_ADDRESS                                              0x0030
#define HOST_IS_HW_MASK                                              0x0000001f
#define HOST_IS_SW_MASK                                              0x0000001f
#define HOST_IS_HW_WRITE_MASK                                        0x0000001f
#define HOST_IS_SW_WRITE_MASK                                        0x0000001f
#define HOST_IS_RSTMASK                                              0xffffffff
#define HOST_IS_RESET                                                0x00000000

// 0x0034 (MISC_IE)
#define MISC_IE_AXI_ERR_MSB                                          10
#define MISC_IE_AXI_ERR_LSB                                          10
#define MISC_IE_AXI_ERR_MASK                                         0x00000400
#define MISC_IE_AXI_ERR_GET(x)                                       (((x) & MISC_IE_AXI_ERR_MASK) >> MISC_IE_AXI_ERR_LSB)
#define MISC_IE_AXI_ERR_SET(x)                                       (((0 | (x)) << MISC_IE_AXI_ERR_LSB) & MISC_IE_AXI_ERR_MASK)
#define MISC_IE_AXI_ERR_RESET                                        0
#define MISC_IE_DST_ADDR_ERR_MSB                                     9
#define MISC_IE_DST_ADDR_ERR_LSB                                     9
#define MISC_IE_DST_ADDR_ERR_MASK                                    0x00000200
#define MISC_IE_DST_ADDR_ERR_GET(x)                                  (((x) & MISC_IE_DST_ADDR_ERR_MASK) >> MISC_IE_DST_ADDR_ERR_LSB)
#define MISC_IE_DST_ADDR_ERR_SET(x)                                  (((0 | (x)) << MISC_IE_DST_ADDR_ERR_LSB) & MISC_IE_DST_ADDR_ERR_MASK)
#define MISC_IE_DST_ADDR_ERR_RESET                                   0
#define MISC_IE_SRC_LEN_ERR_MSB                                      8
#define MISC_IE_SRC_LEN_ERR_LSB                                      8
#define MISC_IE_SRC_LEN_ERR_MASK                                     0x00000100
#define MISC_IE_SRC_LEN_ERR_GET(x)                                   (((x) & MISC_IE_SRC_LEN_ERR_MASK) >> MISC_IE_SRC_LEN_ERR_LSB)
#define MISC_IE_SRC_LEN_ERR_SET(x)                                   (((0 | (x)) << MISC_IE_SRC_LEN_ERR_LSB) & MISC_IE_SRC_LEN_ERR_MASK)
#define MISC_IE_SRC_LEN_ERR_RESET                                    0
#define MISC_IE_DST_MAX_LEN_VIO_MSB                                  7
#define MISC_IE_DST_MAX_LEN_VIO_LSB                                  7
#define MISC_IE_DST_MAX_LEN_VIO_MASK                                 0x00000080
#define MISC_IE_DST_MAX_LEN_VIO_GET(x)                               (((x) & MISC_IE_DST_MAX_LEN_VIO_MASK) >> MISC_IE_DST_MAX_LEN_VIO_LSB)
#define MISC_IE_DST_MAX_LEN_VIO_SET(x)                               (((0 | (x)) << MISC_IE_DST_MAX_LEN_VIO_LSB) & MISC_IE_DST_MAX_LEN_VIO_MASK)
#define MISC_IE_DST_MAX_LEN_VIO_RESET                                0
#define MISC_IE_DST_RING_OVERFLOW_MSB                                6
#define MISC_IE_DST_RING_OVERFLOW_LSB                                6
#define MISC_IE_DST_RING_OVERFLOW_MASK                               0x00000040
#define MISC_IE_DST_RING_OVERFLOW_GET(x)                             (((x) & MISC_IE_DST_RING_OVERFLOW_MASK) >> MISC_IE_DST_RING_OVERFLOW_LSB)
#define MISC_IE_DST_RING_OVERFLOW_SET(x)                             (((0 | (x)) << MISC_IE_DST_RING_OVERFLOW_LSB) & MISC_IE_DST_RING_OVERFLOW_MASK)
#define MISC_IE_DST_RING_OVERFLOW_RESET                              0
#define MISC_IE_SRC_RING_OVERFLOW_MSB                                5
#define MISC_IE_SRC_RING_OVERFLOW_LSB                                5
#define MISC_IE_SRC_RING_OVERFLOW_MASK                               0x00000020
#define MISC_IE_SRC_RING_OVERFLOW_GET(x)                             (((x) & MISC_IE_SRC_RING_OVERFLOW_MASK) >> MISC_IE_SRC_RING_OVERFLOW_LSB)
#define MISC_IE_SRC_RING_OVERFLOW_SET(x)                             (((0 | (x)) << MISC_IE_SRC_RING_OVERFLOW_LSB) & MISC_IE_SRC_RING_OVERFLOW_MASK)
#define MISC_IE_SRC_RING_OVERFLOW_RESET                              0
#define MISC_IE_DST_RING_LOW_WATERMARK_MSB                           4
#define MISC_IE_DST_RING_LOW_WATERMARK_LSB                           4
#define MISC_IE_DST_RING_LOW_WATERMARK_MASK                          0x00000010
#define MISC_IE_DST_RING_LOW_WATERMARK_GET(x)                        (((x) & MISC_IE_DST_RING_LOW_WATERMARK_MASK) >> MISC_IE_DST_RING_LOW_WATERMARK_LSB)
#define MISC_IE_DST_RING_LOW_WATERMARK_SET(x)                        (((0 | (x)) << MISC_IE_DST_RING_LOW_WATERMARK_LSB) & MISC_IE_DST_RING_LOW_WATERMARK_MASK)
#define MISC_IE_DST_RING_LOW_WATERMARK_RESET                         0
#define MISC_IE_DST_RING_HIGH_WATERMARK_MSB                          3
#define MISC_IE_DST_RING_HIGH_WATERMARK_LSB                          3
#define MISC_IE_DST_RING_HIGH_WATERMARK_MASK                         0x00000008
#define MISC_IE_DST_RING_HIGH_WATERMARK_GET(x)                       (((x) & MISC_IE_DST_RING_HIGH_WATERMARK_MASK) >> MISC_IE_DST_RING_HIGH_WATERMARK_LSB)
#define MISC_IE_DST_RING_HIGH_WATERMARK_SET(x)                       (((0 | (x)) << MISC_IE_DST_RING_HIGH_WATERMARK_LSB) & MISC_IE_DST_RING_HIGH_WATERMARK_MASK)
#define MISC_IE_DST_RING_HIGH_WATERMARK_RESET                        0
#define MISC_IE_SRC_RING_LOW_WATERMARK_MSB                           2
#define MISC_IE_SRC_RING_LOW_WATERMARK_LSB                           2
#define MISC_IE_SRC_RING_LOW_WATERMARK_MASK                          0x00000004
#define MISC_IE_SRC_RING_LOW_WATERMARK_GET(x)                        (((x) & MISC_IE_SRC_RING_LOW_WATERMARK_MASK) >> MISC_IE_SRC_RING_LOW_WATERMARK_LSB)
#define MISC_IE_SRC_RING_LOW_WATERMARK_SET(x)                        (((0 | (x)) << MISC_IE_SRC_RING_LOW_WATERMARK_LSB) & MISC_IE_SRC_RING_LOW_WATERMARK_MASK)
#define MISC_IE_SRC_RING_LOW_WATERMARK_RESET                         0
#define MISC_IE_SRC_RING_HIGH_WATERMARK_MSB                          1
#define MISC_IE_SRC_RING_HIGH_WATERMARK_LSB                          1
#define MISC_IE_SRC_RING_HIGH_WATERMARK_MASK                         0x00000002
#define MISC_IE_SRC_RING_HIGH_WATERMARK_GET(x)                       (((x) & MISC_IE_SRC_RING_HIGH_WATERMARK_MASK) >> MISC_IE_SRC_RING_HIGH_WATERMARK_LSB)
#define MISC_IE_SRC_RING_HIGH_WATERMARK_SET(x)                       (((0 | (x)) << MISC_IE_SRC_RING_HIGH_WATERMARK_LSB) & MISC_IE_SRC_RING_HIGH_WATERMARK_MASK)
#define MISC_IE_SRC_RING_HIGH_WATERMARK_RESET                        0
#define MISC_IE_COPY_COMPLETE_MSB                                    0
#define MISC_IE_COPY_COMPLETE_LSB                                    0
#define MISC_IE_COPY_COMPLETE_MASK                                   0x00000001
#define MISC_IE_COPY_COMPLETE_GET(x)                                 (((x) & MISC_IE_COPY_COMPLETE_MASK) >> MISC_IE_COPY_COMPLETE_LSB)
#define MISC_IE_COPY_COMPLETE_SET(x)                                 (((0 | (x)) << MISC_IE_COPY_COMPLETE_LSB) & MISC_IE_COPY_COMPLETE_MASK)
#define MISC_IE_COPY_COMPLETE_RESET                                  0
#define MISC_IE_ADDRESS                                              0x0034
#define MISC_IE_HW_MASK                                              0x000007ff
#define MISC_IE_SW_MASK                                              0x000007ff
#define MISC_IE_HW_WRITE_MASK                                        0x00000000
#define MISC_IE_SW_WRITE_MASK                                        0x000007ff
#define MISC_IE_RSTMASK                                              0xffffffff
#define MISC_IE_RESET                                                0x00000000

// 0x0038 (MISC_IS)
#define MISC_IS_AXI_ERR_MSB                                          10
#define MISC_IS_AXI_ERR_LSB                                          10
#define MISC_IS_AXI_ERR_MASK                                         0x00000400
#define MISC_IS_AXI_ERR_GET(x)                                       (((x) & MISC_IS_AXI_ERR_MASK) >> MISC_IS_AXI_ERR_LSB)
#define MISC_IS_AXI_ERR_SET(x)                                       (((0 | (x)) << MISC_IS_AXI_ERR_LSB) & MISC_IS_AXI_ERR_MASK)
#define MISC_IS_AXI_ERR_RESET                                        0
#define MISC_IS_DST_ADDR_ERR_MSB                                     9
#define MISC_IS_DST_ADDR_ERR_LSB                                     9
#define MISC_IS_DST_ADDR_ERR_MASK                                    0x00000200
#define MISC_IS_DST_ADDR_ERR_GET(x)                                  (((x) & MISC_IS_DST_ADDR_ERR_MASK) >> MISC_IS_DST_ADDR_ERR_LSB)
#define MISC_IS_DST_ADDR_ERR_SET(x)                                  (((0 | (x)) << MISC_IS_DST_ADDR_ERR_LSB) & MISC_IS_DST_ADDR_ERR_MASK)
#define MISC_IS_DST_ADDR_ERR_RESET                                   0
#define MISC_IS_SRC_LEN_ERR_MSB                                      8
#define MISC_IS_SRC_LEN_ERR_LSB                                      8
#define MISC_IS_SRC_LEN_ERR_MASK                                     0x00000100
#define MISC_IS_SRC_LEN_ERR_GET(x)                                   (((x) & MISC_IS_SRC_LEN_ERR_MASK) >> MISC_IS_SRC_LEN_ERR_LSB)
#define MISC_IS_SRC_LEN_ERR_SET(x)                                   (((0 | (x)) << MISC_IS_SRC_LEN_ERR_LSB) & MISC_IS_SRC_LEN_ERR_MASK)
#define MISC_IS_SRC_LEN_ERR_RESET                                    0
#define MISC_IS_DST_MAX_LEN_VIO_MSB                                  7
#define MISC_IS_DST_MAX_LEN_VIO_LSB                                  7
#define MISC_IS_DST_MAX_LEN_VIO_MASK                                 0x00000080
#define MISC_IS_DST_MAX_LEN_VIO_GET(x)                               (((x) & MISC_IS_DST_MAX_LEN_VIO_MASK) >> MISC_IS_DST_MAX_LEN_VIO_LSB)
#define MISC_IS_DST_MAX_LEN_VIO_SET(x)                               (((0 | (x)) << MISC_IS_DST_MAX_LEN_VIO_LSB) & MISC_IS_DST_MAX_LEN_VIO_MASK)
#define MISC_IS_DST_MAX_LEN_VIO_RESET                                0
#define MISC_IS_DST_RING_OVERFLOW_MSB                                6
#define MISC_IS_DST_RING_OVERFLOW_LSB                                6
#define MISC_IS_DST_RING_OVERFLOW_MASK                               0x00000040
#define MISC_IS_DST_RING_OVERFLOW_GET(x)                             (((x) & MISC_IS_DST_RING_OVERFLOW_MASK) >> MISC_IS_DST_RING_OVERFLOW_LSB)
#define MISC_IS_DST_RING_OVERFLOW_SET(x)                             (((0 | (x)) << MISC_IS_DST_RING_OVERFLOW_LSB) & MISC_IS_DST_RING_OVERFLOW_MASK)
#define MISC_IS_DST_RING_OVERFLOW_RESET                              0
#define MISC_IS_SRC_RING_OVERFLOW_MSB                                5
#define MISC_IS_SRC_RING_OVERFLOW_LSB                                5
#define MISC_IS_SRC_RING_OVERFLOW_MASK                               0x00000020
#define MISC_IS_SRC_RING_OVERFLOW_GET(x)                             (((x) & MISC_IS_SRC_RING_OVERFLOW_MASK) >> MISC_IS_SRC_RING_OVERFLOW_LSB)
#define MISC_IS_SRC_RING_OVERFLOW_SET(x)                             (((0 | (x)) << MISC_IS_SRC_RING_OVERFLOW_LSB) & MISC_IS_SRC_RING_OVERFLOW_MASK)
#define MISC_IS_SRC_RING_OVERFLOW_RESET                              0
#define MISC_IS_DST_RING_LOW_WATERMARK_MSB                           4
#define MISC_IS_DST_RING_LOW_WATERMARK_LSB                           4
#define MISC_IS_DST_RING_LOW_WATERMARK_MASK                          0x00000010
#define MISC_IS_DST_RING_LOW_WATERMARK_GET(x)                        (((x) & MISC_IS_DST_RING_LOW_WATERMARK_MASK) >> MISC_IS_DST_RING_LOW_WATERMARK_LSB)
#define MISC_IS_DST_RING_LOW_WATERMARK_SET(x)                        (((0 | (x)) << MISC_IS_DST_RING_LOW_WATERMARK_LSB) & MISC_IS_DST_RING_LOW_WATERMARK_MASK)
#define MISC_IS_DST_RING_LOW_WATERMARK_RESET                         0
#define MISC_IS_DST_RING_HIGH_WATERMARK_MSB                          3
#define MISC_IS_DST_RING_HIGH_WATERMARK_LSB                          3
#define MISC_IS_DST_RING_HIGH_WATERMARK_MASK                         0x00000008
#define MISC_IS_DST_RING_HIGH_WATERMARK_GET(x)                       (((x) & MISC_IS_DST_RING_HIGH_WATERMARK_MASK) >> MISC_IS_DST_RING_HIGH_WATERMARK_LSB)
#define MISC_IS_DST_RING_HIGH_WATERMARK_SET(x)                       (((0 | (x)) << MISC_IS_DST_RING_HIGH_WATERMARK_LSB) & MISC_IS_DST_RING_HIGH_WATERMARK_MASK)
#define MISC_IS_DST_RING_HIGH_WATERMARK_RESET                        0
#define MISC_IS_SRC_RING_LOW_WATERMARK_MSB                           2
#define MISC_IS_SRC_RING_LOW_WATERMARK_LSB                           2
#define MISC_IS_SRC_RING_LOW_WATERMARK_MASK                          0x00000004
#define MISC_IS_SRC_RING_LOW_WATERMARK_GET(x)                        (((x) & MISC_IS_SRC_RING_LOW_WATERMARK_MASK) >> MISC_IS_SRC_RING_LOW_WATERMARK_LSB)
#define MISC_IS_SRC_RING_LOW_WATERMARK_SET(x)                        (((0 | (x)) << MISC_IS_SRC_RING_LOW_WATERMARK_LSB) & MISC_IS_SRC_RING_LOW_WATERMARK_MASK)
#define MISC_IS_SRC_RING_LOW_WATERMARK_RESET                         0
#define MISC_IS_SRC_RING_HIGH_WATERMARK_MSB                          1
#define MISC_IS_SRC_RING_HIGH_WATERMARK_LSB                          1
#define MISC_IS_SRC_RING_HIGH_WATERMARK_MASK                         0x00000002
#define MISC_IS_SRC_RING_HIGH_WATERMARK_GET(x)                       (((x) & MISC_IS_SRC_RING_HIGH_WATERMARK_MASK) >> MISC_IS_SRC_RING_HIGH_WATERMARK_LSB)
#define MISC_IS_SRC_RING_HIGH_WATERMARK_SET(x)                       (((0 | (x)) << MISC_IS_SRC_RING_HIGH_WATERMARK_LSB) & MISC_IS_SRC_RING_HIGH_WATERMARK_MASK)
#define MISC_IS_SRC_RING_HIGH_WATERMARK_RESET                        0
#define MISC_IS_COPY_COMPLETE_MSB                                    0
#define MISC_IS_COPY_COMPLETE_LSB                                    0
#define MISC_IS_COPY_COMPLETE_MASK                                   0x00000001
#define MISC_IS_COPY_COMPLETE_GET(x)                                 (((x) & MISC_IS_COPY_COMPLETE_MASK) >> MISC_IS_COPY_COMPLETE_LSB)
#define MISC_IS_COPY_COMPLETE_SET(x)                                 (((0 | (x)) << MISC_IS_COPY_COMPLETE_LSB) & MISC_IS_COPY_COMPLETE_MASK)
#define MISC_IS_COPY_COMPLETE_RESET                                  0
#define MISC_IS_ADDRESS                                              0x0038
#define MISC_IS_HW_MASK                                              0x000007ff
#define MISC_IS_SW_MASK                                              0x000007ff
#define MISC_IS_HW_WRITE_MASK                                        0x000007ff
#define MISC_IS_SW_WRITE_MASK                                        0x000007ff
#define MISC_IS_RSTMASK                                              0xffffffff
#define MISC_IS_RESET                                                0x00000000

// 0x003c (SR_WR_INDEX)
#define SR_WR_INDEX_V_MSB                                            15
#define SR_WR_INDEX_V_LSB                                            0
#define SR_WR_INDEX_V_MASK                                           0x0000ffff
#define SR_WR_INDEX_V_GET(x)                                         (((x) & SR_WR_INDEX_V_MASK) >> SR_WR_INDEX_V_LSB)
#define SR_WR_INDEX_V_SET(x)                                         (((0 | (x)) << SR_WR_INDEX_V_LSB) & SR_WR_INDEX_V_MASK)
#define SR_WR_INDEX_V_RESET                                          0
#define SR_WR_INDEX_ADDRESS                                          0x003c
#define SR_WR_INDEX_HW_MASK                                          0x0000ffff
#define SR_WR_INDEX_SW_MASK                                          0x0000ffff
#define SR_WR_INDEX_HW_WRITE_MASK                                    0x0000ffff
#define SR_WR_INDEX_SW_WRITE_MASK                                    0x0000ffff
#define SR_WR_INDEX_RSTMASK                                          0xffffffff
#define SR_WR_INDEX_RESET                                            0x00000000

// 0x0040 (DST_WR_INDEX)
#define DST_WR_INDEX_V_MSB                                           15
#define DST_WR_INDEX_V_LSB                                           0
#define DST_WR_INDEX_V_MASK                                          0x0000ffff
#define DST_WR_INDEX_V_GET(x)                                        (((x) & DST_WR_INDEX_V_MASK) >> DST_WR_INDEX_V_LSB)
#define DST_WR_INDEX_V_SET(x)                                        (((0 | (x)) << DST_WR_INDEX_V_LSB) & DST_WR_INDEX_V_MASK)
#define DST_WR_INDEX_V_RESET                                         0
#define DST_WR_INDEX_ADDRESS                                         0x0040
#define DST_WR_INDEX_HW_MASK                                         0x0000ffff
#define DST_WR_INDEX_SW_MASK                                         0x0000ffff
#define DST_WR_INDEX_HW_WRITE_MASK                                   0x0000ffff
#define DST_WR_INDEX_SW_WRITE_MASK                                   0x0000ffff
#define DST_WR_INDEX_RSTMASK                                         0xffffffff
#define DST_WR_INDEX_RESET                                           0x00000000

// 0x0044 (CURRENT_SRRI)
#define CURRENT_SRRI_V_MSB                                           15
#define CURRENT_SRRI_V_LSB                                           0
#define CURRENT_SRRI_V_MASK                                          0x0000ffff
#define CURRENT_SRRI_V_GET(x)                                        (((x) & CURRENT_SRRI_V_MASK) >> CURRENT_SRRI_V_LSB)
#define CURRENT_SRRI_V_SET(x)                                        (((0 | (x)) << CURRENT_SRRI_V_LSB) & CURRENT_SRRI_V_MASK)
#define CURRENT_SRRI_V_RESET                                         0
#define CURRENT_SRRI_ADDRESS                                         0x0044
#define CURRENT_SRRI_HW_MASK                                         0x0000ffff
#define CURRENT_SRRI_SW_MASK                                         0x0000ffff
#define CURRENT_SRRI_HW_WRITE_MASK                                   0x0000ffff
#define CURRENT_SRRI_SW_WRITE_MASK                                   0x00000000
#define CURRENT_SRRI_RSTMASK                                         0xffffffff
#define CURRENT_SRRI_RESET                                           0x00000000

// 0x0048 (CURRENT_DRRI)
#define CURRENT_DRRI_V_MSB                                           15
#define CURRENT_DRRI_V_LSB                                           0
#define CURRENT_DRRI_V_MASK                                          0x0000ffff
#define CURRENT_DRRI_V_GET(x)                                        (((x) & CURRENT_DRRI_V_MASK) >> CURRENT_DRRI_V_LSB)
#define CURRENT_DRRI_V_SET(x)                                        (((0 | (x)) << CURRENT_DRRI_V_LSB) & CURRENT_DRRI_V_MASK)
#define CURRENT_DRRI_V_RESET                                         0
#define CURRENT_DRRI_ADDRESS                                         0x0048
#define CURRENT_DRRI_HW_MASK                                         0x0000ffff
#define CURRENT_DRRI_SW_MASK                                         0x0000ffff
#define CURRENT_DRRI_HW_WRITE_MASK                                   0x0000ffff
#define CURRENT_DRRI_SW_WRITE_MASK                                   0x00000000
#define CURRENT_DRRI_RSTMASK                                         0xffffffff
#define CURRENT_DRRI_RESET                                           0x00000000

// 0x004c (SRC_WATERMARK)
#define SRC_WATERMARK_LOW_MSB                                        31
#define SRC_WATERMARK_LOW_LSB                                        16
#define SRC_WATERMARK_LOW_MASK                                       0xffff0000
#define SRC_WATERMARK_LOW_GET(x)                                     (((x) & SRC_WATERMARK_LOW_MASK) >> SRC_WATERMARK_LOW_LSB)
#define SRC_WATERMARK_LOW_SET(x)                                     (((0 | (x)) << SRC_WATERMARK_LOW_LSB) & SRC_WATERMARK_LOW_MASK)
#define SRC_WATERMARK_LOW_RESET                                      0
#define SRC_WATERMARK_HIGH_MSB                                       15
#define SRC_WATERMARK_HIGH_LSB                                       0
#define SRC_WATERMARK_HIGH_MASK                                      0x0000ffff
#define SRC_WATERMARK_HIGH_GET(x)                                    (((x) & SRC_WATERMARK_HIGH_MASK) >> SRC_WATERMARK_HIGH_LSB)
#define SRC_WATERMARK_HIGH_SET(x)                                    (((0 | (x)) << SRC_WATERMARK_HIGH_LSB) & SRC_WATERMARK_HIGH_MASK)
#define SRC_WATERMARK_HIGH_RESET                                     0
#define SRC_WATERMARK_ADDRESS                                        0x004c
#define SRC_WATERMARK_HW_MASK                                        0xffffffff
#define SRC_WATERMARK_SW_MASK                                        0xffffffff
#define SRC_WATERMARK_HW_WRITE_MASK                                  0x00000000
#define SRC_WATERMARK_SW_WRITE_MASK                                  0xffffffff
#define SRC_WATERMARK_RSTMASK                                        0xffffffff
#define SRC_WATERMARK_RESET                                          0x00000000

// 0x0050 (DST_WATERMARK)
#define DST_WATERMARK_LOW_MSB                                        31
#define DST_WATERMARK_LOW_LSB                                        16
#define DST_WATERMARK_LOW_MASK                                       0xffff0000
#define DST_WATERMARK_LOW_GET(x)                                     (((x) & DST_WATERMARK_LOW_MASK) >> DST_WATERMARK_LOW_LSB)
#define DST_WATERMARK_LOW_SET(x)                                     (((0 | (x)) << DST_WATERMARK_LOW_LSB) & DST_WATERMARK_LOW_MASK)
#define DST_WATERMARK_LOW_RESET                                      0
#define DST_WATERMARK_HIGH_MSB                                       15
#define DST_WATERMARK_HIGH_LSB                                       0
#define DST_WATERMARK_HIGH_MASK                                      0x0000ffff
#define DST_WATERMARK_HIGH_GET(x)                                    (((x) & DST_WATERMARK_HIGH_MASK) >> DST_WATERMARK_HIGH_LSB)
#define DST_WATERMARK_HIGH_SET(x)                                    (((0 | (x)) << DST_WATERMARK_HIGH_LSB) & DST_WATERMARK_HIGH_MASK)
#define DST_WATERMARK_HIGH_RESET                                     0
#define DST_WATERMARK_ADDRESS                                        0x0050
#define DST_WATERMARK_HW_MASK                                        0xffffffff
#define DST_WATERMARK_SW_MASK                                        0xffffffff
#define DST_WATERMARK_HW_WRITE_MASK                                  0x00000000
#define DST_WATERMARK_SW_WRITE_MASK                                  0xffffffff
#define DST_WATERMARK_RSTMASK                                        0xffffffff
#define DST_WATERMARK_RESET                                          0x00000000

// 0x0054 (CE_DEBUG)
#define CE_DEBUG_SEL_MSB                                             5
#define CE_DEBUG_SEL_LSB                                             0
#define CE_DEBUG_SEL_MASK                                            0x0000003f
#define CE_DEBUG_SEL_GET(x)                                          (((x) & CE_DEBUG_SEL_MASK) >> CE_DEBUG_SEL_LSB)
#define CE_DEBUG_SEL_SET(x)                                          (((0 | (x)) << CE_DEBUG_SEL_LSB) & CE_DEBUG_SEL_MASK)
#define CE_DEBUG_SEL_RESET                                           0
#define CE_DEBUG_ADDRESS                                             0x0054
#define CE_DEBUG_HW_MASK                                             0x0000003f
#define CE_DEBUG_SW_MASK                                             0x0000003f
#define CE_DEBUG_HW_WRITE_MASK                                       0x00000000
#define CE_DEBUG_SW_WRITE_MASK                                       0x0000003f
#define CE_DEBUG_RSTMASK                                             0xffffffff
#define CE_DEBUG_RESET                                               0x00000000


#endif /* _CE_REG_CSR_H_ */
