/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _CE_REG_CSR_H_
#define _CE_REG_CSR_H_


#ifndef __CE_REG_CSR_BASE_ADDRESS
#define __CE_REG_CSR_BASE_ADDRESS (0x4cc00)
#endif


// 0x0 (SR_BA)
#define SR_BA_V_LSB                                                            0
#define SR_BA_V_MSB                                                            31
#define SR_BA_V_MASK                                                           0xffffffff
#define SR_BA_V_GET(x)                                                         (((x) & SR_BA_V_MASK) >> SR_BA_V_LSB)
#define SR_BA_V_SET(x)                                                         (((0 | (x)) << SR_BA_V_LSB) & SR_BA_V_MASK)
#define SR_BA_V_RESET                                                          0x0
#define SR_BA_ADDRESS                                                          (0x0 + __CE_REG_CSR_BASE_ADDRESS)
#define SR_BA_RSTMASK                                                          0xffffffff
#define SR_BA_RESET                                                            0x0

// 0x4 (SR_SIZE)
#define SR_SIZE_V_LSB                                                          0
#define SR_SIZE_V_MSB                                                          15
#define SR_SIZE_V_MASK                                                         0xffff
#define SR_SIZE_V_GET(x)                                                       (((x) & SR_SIZE_V_MASK) >> SR_SIZE_V_LSB)
#define SR_SIZE_V_SET(x)                                                       (((0 | (x)) << SR_SIZE_V_LSB) & SR_SIZE_V_MASK)
#define SR_SIZE_V_RESET                                                        0x0
#define SR_SIZE_ADDRESS                                                        (0x4 + __CE_REG_CSR_BASE_ADDRESS)
#define SR_SIZE_RSTMASK                                                        0xffff
#define SR_SIZE_RESET                                                          0x0

// 0x8 (DR_BA)
#define DR_BA_V_LSB                                                            0
#define DR_BA_V_MSB                                                            31
#define DR_BA_V_MASK                                                           0xffffffff
#define DR_BA_V_GET(x)                                                         (((x) & DR_BA_V_MASK) >> DR_BA_V_LSB)
#define DR_BA_V_SET(x)                                                         (((0 | (x)) << DR_BA_V_LSB) & DR_BA_V_MASK)
#define DR_BA_V_RESET                                                          0x0
#define DR_BA_ADDRESS                                                          (0x8 + __CE_REG_CSR_BASE_ADDRESS)
#define DR_BA_RSTMASK                                                          0xffffffff
#define DR_BA_RESET                                                            0x0

// 0xc (DR_SIZE)
#define DR_SIZE_V_LSB                                                          0
#define DR_SIZE_V_MSB                                                          15
#define DR_SIZE_V_MASK                                                         0xffff
#define DR_SIZE_V_GET(x)                                                       (((x) & DR_SIZE_V_MASK) >> DR_SIZE_V_LSB)
#define DR_SIZE_V_SET(x)                                                       (((0 | (x)) << DR_SIZE_V_LSB) & DR_SIZE_V_MASK)
#define DR_SIZE_V_RESET                                                        0x0
#define DR_SIZE_ADDRESS                                                        (0xc + __CE_REG_CSR_BASE_ADDRESS)
#define DR_SIZE_RSTMASK                                                        0xffff
#define DR_SIZE_RESET                                                          0x0

// 0x10 (CE_CTRL1)
#define CE_CTRL1_MSI_EN_LSB                                                    18
#define CE_CTRL1_MSI_EN_MSB                                                    18
#define CE_CTRL1_MSI_EN_MASK                                                   0x40000
#define CE_CTRL1_MSI_EN_GET(x)                                                 (((x) & CE_CTRL1_MSI_EN_MASK) >> CE_CTRL1_MSI_EN_LSB)
#define CE_CTRL1_MSI_EN_SET(x)                                                 (((0 | (x)) << CE_CTRL1_MSI_EN_LSB) & CE_CTRL1_MSI_EN_MASK)
#define CE_CTRL1_MSI_EN_RESET                                                  0x0
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_LSB                                     17
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_MSB                                     17
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_MASK                                    0x20000
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_GET(x)                                  (((x) & CE_CTRL1_DST_RING_BYTE_SWAP_EN_MASK) >> CE_CTRL1_DST_RING_BYTE_SWAP_EN_LSB)
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_SET(x)                                  (((0 | (x)) << CE_CTRL1_DST_RING_BYTE_SWAP_EN_LSB) & CE_CTRL1_DST_RING_BYTE_SWAP_EN_MASK)
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_RESET                                   0x0
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_LSB                                     16
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_MSB                                     16
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_MASK                                    0x10000
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_GET(x)                                  (((x) & CE_CTRL1_SRC_RING_BYTE_SWAP_EN_MASK) >> CE_CTRL1_SRC_RING_BYTE_SWAP_EN_LSB)
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_SET(x)                                  (((0 | (x)) << CE_CTRL1_SRC_RING_BYTE_SWAP_EN_LSB) & CE_CTRL1_SRC_RING_BYTE_SWAP_EN_MASK)
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_RESET                                   0x0
#define CE_CTRL1_DMAX_LENGTH_LSB                                               0
#define CE_CTRL1_DMAX_LENGTH_MSB                                               15
#define CE_CTRL1_DMAX_LENGTH_MASK                                              0xffff
#define CE_CTRL1_DMAX_LENGTH_GET(x)                                            (((x) & CE_CTRL1_DMAX_LENGTH_MASK) >> CE_CTRL1_DMAX_LENGTH_LSB)
#define CE_CTRL1_DMAX_LENGTH_SET(x)                                            (((0 | (x)) << CE_CTRL1_DMAX_LENGTH_LSB) & CE_CTRL1_DMAX_LENGTH_MASK)
#define CE_CTRL1_DMAX_LENGTH_RESET                                             0x80
#define CE_CTRL1_ADDRESS                                                       (0x10 + __CE_REG_CSR_BASE_ADDRESS)
#define CE_CTRL1_RSTMASK                                                       0x7ffff
#define CE_CTRL1_RESET                                                         0x80

// 0x14 (CE_CTRL2)
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_LSB                                25
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_MSB                                29
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_MASK                               0x3e000000
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_GET(x)                             (((x) & CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_MASK) >> CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_LSB)
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_SET(x)                             (((0 | (x)) << CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_LSB) & CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_MASK)
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_RESET                              0x8
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_LSB                                 20
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_MSB                                 24
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_MASK                                0x1f00000
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_GET(x)                              (((x) & CE_CTRL2_NUM_AXI_OUTSTANDING_READS_MASK) >> CE_CTRL2_NUM_AXI_OUTSTANDING_READS_LSB)
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_SET(x)                              (((0 | (x)) << CE_CTRL2_NUM_AXI_OUTSTANDING_READS_LSB) & CE_CTRL2_NUM_AXI_OUTSTANDING_READS_MASK)
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_RESET                               0x18
#define CE_CTRL2_AXI_TIMEOUT_LSB                                               4
#define CE_CTRL2_AXI_TIMEOUT_MSB                                               19
#define CE_CTRL2_AXI_TIMEOUT_MASK                                              0xffff0
#define CE_CTRL2_AXI_TIMEOUT_GET(x)                                            (((x) & CE_CTRL2_AXI_TIMEOUT_MASK) >> CE_CTRL2_AXI_TIMEOUT_LSB)
#define CE_CTRL2_AXI_TIMEOUT_SET(x)                                            (((0 | (x)) << CE_CTRL2_AXI_TIMEOUT_LSB) & CE_CTRL2_AXI_TIMEOUT_MASK)
#define CE_CTRL2_AXI_TIMEOUT_RESET                                             0x1f40
#define CE_CTRL2_DEST_AXI_MAX_LEN_LSB                                          2
#define CE_CTRL2_DEST_AXI_MAX_LEN_MSB                                          3
#define CE_CTRL2_DEST_AXI_MAX_LEN_MASK                                         0xc
#define CE_CTRL2_DEST_AXI_MAX_LEN_GET(x)                                       (((x) & CE_CTRL2_DEST_AXI_MAX_LEN_MASK) >> CE_CTRL2_DEST_AXI_MAX_LEN_LSB)
#define CE_CTRL2_DEST_AXI_MAX_LEN_SET(x)                                       (((0 | (x)) << CE_CTRL2_DEST_AXI_MAX_LEN_LSB) & CE_CTRL2_DEST_AXI_MAX_LEN_MASK)
#define CE_CTRL2_DEST_AXI_MAX_LEN_RESET                                        0x1
#define CE_CTRL2_SRC_AXI_MAX_LEN_LSB                                           0
#define CE_CTRL2_SRC_AXI_MAX_LEN_MSB                                           1
#define CE_CTRL2_SRC_AXI_MAX_LEN_MASK                                          0x3
#define CE_CTRL2_SRC_AXI_MAX_LEN_GET(x)                                        (((x) & CE_CTRL2_SRC_AXI_MAX_LEN_MASK) >> CE_CTRL2_SRC_AXI_MAX_LEN_LSB)
#define CE_CTRL2_SRC_AXI_MAX_LEN_SET(x)                                        (((0 | (x)) << CE_CTRL2_SRC_AXI_MAX_LEN_LSB) & CE_CTRL2_SRC_AXI_MAX_LEN_MASK)
#define CE_CTRL2_SRC_AXI_MAX_LEN_RESET                                         0x1
#define CE_CTRL2_ADDRESS                                                       (0x14 + __CE_REG_CSR_BASE_ADDRESS)
#define CE_CTRL2_RSTMASK                                                       0x3fffffff
#define CE_CTRL2_RESET                                                         0x1181f405

// 0x18 (CE_CMD)
#define CE_CMD_HALT_STATUS_LSB                                                 3
#define CE_CMD_HALT_STATUS_MSB                                                 3
#define CE_CMD_HALT_STATUS_MASK                                                0x8
#define CE_CMD_HALT_STATUS_GET(x)                                              (((x) & CE_CMD_HALT_STATUS_MASK) >> CE_CMD_HALT_STATUS_LSB)
#define CE_CMD_HALT_STATUS_SET(x)                                              (((0 | (x)) << CE_CMD_HALT_STATUS_LSB) & CE_CMD_HALT_STATUS_MASK)
#define CE_CMD_HALT_STATUS_RESET                                               0x0
#define CE_CMD_DST_FLUSH_LSB                                                   2
#define CE_CMD_DST_FLUSH_MSB                                                   2
#define CE_CMD_DST_FLUSH_MASK                                                  0x4
#define CE_CMD_DST_FLUSH_GET(x)                                                (((x) & CE_CMD_DST_FLUSH_MASK) >> CE_CMD_DST_FLUSH_LSB)
#define CE_CMD_DST_FLUSH_SET(x)                                                (((0 | (x)) << CE_CMD_DST_FLUSH_LSB) & CE_CMD_DST_FLUSH_MASK)
#define CE_CMD_DST_FLUSH_RESET                                                 0x0
#define CE_CMD_SRC_FLUSH_LSB                                                   1
#define CE_CMD_SRC_FLUSH_MSB                                                   1
#define CE_CMD_SRC_FLUSH_MASK                                                  0x2
#define CE_CMD_SRC_FLUSH_GET(x)                                                (((x) & CE_CMD_SRC_FLUSH_MASK) >> CE_CMD_SRC_FLUSH_LSB)
#define CE_CMD_SRC_FLUSH_SET(x)                                                (((0 | (x)) << CE_CMD_SRC_FLUSH_LSB) & CE_CMD_SRC_FLUSH_MASK)
#define CE_CMD_SRC_FLUSH_RESET                                                 0x0
#define CE_CMD_HALT_LSB                                                        0
#define CE_CMD_HALT_MSB                                                        0
#define CE_CMD_HALT_MASK                                                       0x1
#define CE_CMD_HALT_GET(x)                                                     (((x) & CE_CMD_HALT_MASK) >> CE_CMD_HALT_LSB)
#define CE_CMD_HALT_SET(x)                                                     (((0 | (x)) << CE_CMD_HALT_LSB) & CE_CMD_HALT_MASK)
#define CE_CMD_HALT_RESET                                                      0x0
#define CE_CMD_ADDRESS                                                         (0x18 + __CE_REG_CSR_BASE_ADDRESS)
#define CE_CMD_RSTMASK                                                         0xf
#define CE_CMD_RESET                                                           0x0

// 0x1c (MSI_ADDR)
#define MSI_ADDR_V_LSB                                                         0
#define MSI_ADDR_V_MSB                                                         31
#define MSI_ADDR_V_MASK                                                        0xffffffff
#define MSI_ADDR_V_GET(x)                                                      (((x) & MSI_ADDR_V_MASK) >> MSI_ADDR_V_LSB)
#define MSI_ADDR_V_SET(x)                                                      (((0 | (x)) << MSI_ADDR_V_LSB) & MSI_ADDR_V_MASK)
#define MSI_ADDR_V_RESET                                                       0x0
#define MSI_ADDR_ADDRESS                                                       (0x1c + __CE_REG_CSR_BASE_ADDRESS)
#define MSI_ADDR_RSTMASK                                                       0xffffffff
#define MSI_ADDR_RESET                                                         0x0

// 0x20 (MSI_DATA)
#define MSI_DATA_V_LSB                                                         0
#define MSI_DATA_V_MSB                                                         31
#define MSI_DATA_V_MASK                                                        0xffffffff
#define MSI_DATA_V_GET(x)                                                      (((x) & MSI_DATA_V_MASK) >> MSI_DATA_V_LSB)
#define MSI_DATA_V_SET(x)                                                      (((0 | (x)) << MSI_DATA_V_LSB) & MSI_DATA_V_MASK)
#define MSI_DATA_V_RESET                                                       0x0
#define MSI_DATA_ADDRESS                                                       (0x20 + __CE_REG_CSR_BASE_ADDRESS)
#define MSI_DATA_RSTMASK                                                       0xffffffff
#define MSI_DATA_RESET                                                         0x0

// 0x24 (TARGET_IE)
#define TARGET_IE_DST_RING_LOW_WATERMARK_LSB                                   4
#define TARGET_IE_DST_RING_LOW_WATERMARK_MSB                                   4
#define TARGET_IE_DST_RING_LOW_WATERMARK_MASK                                  0x10
#define TARGET_IE_DST_RING_LOW_WATERMARK_GET(x)                                (((x) & TARGET_IE_DST_RING_LOW_WATERMARK_MASK) >> TARGET_IE_DST_RING_LOW_WATERMARK_LSB)
#define TARGET_IE_DST_RING_LOW_WATERMARK_SET(x)                                (((0 | (x)) << TARGET_IE_DST_RING_LOW_WATERMARK_LSB) & TARGET_IE_DST_RING_LOW_WATERMARK_MASK)
#define TARGET_IE_DST_RING_LOW_WATERMARK_RESET                                 0x0
#define TARGET_IE_DST_RING_HIGH_WATERMARK_LSB                                  3
#define TARGET_IE_DST_RING_HIGH_WATERMARK_MSB                                  3
#define TARGET_IE_DST_RING_HIGH_WATERMARK_MASK                                 0x8
#define TARGET_IE_DST_RING_HIGH_WATERMARK_GET(x)                               (((x) & TARGET_IE_DST_RING_HIGH_WATERMARK_MASK) >> TARGET_IE_DST_RING_HIGH_WATERMARK_LSB)
#define TARGET_IE_DST_RING_HIGH_WATERMARK_SET(x)                               (((0 | (x)) << TARGET_IE_DST_RING_HIGH_WATERMARK_LSB) & TARGET_IE_DST_RING_HIGH_WATERMARK_MASK)
#define TARGET_IE_DST_RING_HIGH_WATERMARK_RESET                                0x0
#define TARGET_IE_SRC_RING_LOW_WATERMARK_LSB                                   2
#define TARGET_IE_SRC_RING_LOW_WATERMARK_MSB                                   2
#define TARGET_IE_SRC_RING_LOW_WATERMARK_MASK                                  0x4
#define TARGET_IE_SRC_RING_LOW_WATERMARK_GET(x)                                (((x) & TARGET_IE_SRC_RING_LOW_WATERMARK_MASK) >> TARGET_IE_SRC_RING_LOW_WATERMARK_LSB)
#define TARGET_IE_SRC_RING_LOW_WATERMARK_SET(x)                                (((0 | (x)) << TARGET_IE_SRC_RING_LOW_WATERMARK_LSB) & TARGET_IE_SRC_RING_LOW_WATERMARK_MASK)
#define TARGET_IE_SRC_RING_LOW_WATERMARK_RESET                                 0x0
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_LSB                                  1
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_MSB                                  1
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_MASK                                 0x2
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_GET(x)                               (((x) & TARGET_IE_SRC_RING_HIGH_WATERMARK_MASK) >> TARGET_IE_SRC_RING_HIGH_WATERMARK_LSB)
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_SET(x)                               (((0 | (x)) << TARGET_IE_SRC_RING_HIGH_WATERMARK_LSB) & TARGET_IE_SRC_RING_HIGH_WATERMARK_MASK)
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_RESET                                0x0
#define TARGET_IE_COPY_COMPLETE_LSB                                            0
#define TARGET_IE_COPY_COMPLETE_MSB                                            0
#define TARGET_IE_COPY_COMPLETE_MASK                                           0x1
#define TARGET_IE_COPY_COMPLETE_GET(x)                                         (((x) & TARGET_IE_COPY_COMPLETE_MASK) >> TARGET_IE_COPY_COMPLETE_LSB)
#define TARGET_IE_COPY_COMPLETE_SET(x)                                         (((0 | (x)) << TARGET_IE_COPY_COMPLETE_LSB) & TARGET_IE_COPY_COMPLETE_MASK)
#define TARGET_IE_COPY_COMPLETE_RESET                                          0x0
#define TARGET_IE_ADDRESS                                                      (0x24 + __CE_REG_CSR_BASE_ADDRESS)
#define TARGET_IE_RSTMASK                                                      0x1f
#define TARGET_IE_RESET                                                        0x0

// 0x28 (TARGET_IS)
#define TARGET_IS_DST_RING_LOW_WATERMARK_LSB                                   4
#define TARGET_IS_DST_RING_LOW_WATERMARK_MSB                                   4
#define TARGET_IS_DST_RING_LOW_WATERMARK_MASK                                  0x10
#define TARGET_IS_DST_RING_LOW_WATERMARK_GET(x)                                (((x) & TARGET_IS_DST_RING_LOW_WATERMARK_MASK) >> TARGET_IS_DST_RING_LOW_WATERMARK_LSB)
#define TARGET_IS_DST_RING_LOW_WATERMARK_SET(x)                                (((0 | (x)) << TARGET_IS_DST_RING_LOW_WATERMARK_LSB) & TARGET_IS_DST_RING_LOW_WATERMARK_MASK)
#define TARGET_IS_DST_RING_LOW_WATERMARK_RESET                                 0x0
#define TARGET_IS_DST_RING_HIGH_WATERMARK_LSB                                  3
#define TARGET_IS_DST_RING_HIGH_WATERMARK_MSB                                  3
#define TARGET_IS_DST_RING_HIGH_WATERMARK_MASK                                 0x8
#define TARGET_IS_DST_RING_HIGH_WATERMARK_GET(x)                               (((x) & TARGET_IS_DST_RING_HIGH_WATERMARK_MASK) >> TARGET_IS_DST_RING_HIGH_WATERMARK_LSB)
#define TARGET_IS_DST_RING_HIGH_WATERMARK_SET(x)                               (((0 | (x)) << TARGET_IS_DST_RING_HIGH_WATERMARK_LSB) & TARGET_IS_DST_RING_HIGH_WATERMARK_MASK)
#define TARGET_IS_DST_RING_HIGH_WATERMARK_RESET                                0x0
#define TARGET_IS_SRC_RING_LOW_WATERMARK_LSB                                   2
#define TARGET_IS_SRC_RING_LOW_WATERMARK_MSB                                   2
#define TARGET_IS_SRC_RING_LOW_WATERMARK_MASK                                  0x4
#define TARGET_IS_SRC_RING_LOW_WATERMARK_GET(x)                                (((x) & TARGET_IS_SRC_RING_LOW_WATERMARK_MASK) >> TARGET_IS_SRC_RING_LOW_WATERMARK_LSB)
#define TARGET_IS_SRC_RING_LOW_WATERMARK_SET(x)                                (((0 | (x)) << TARGET_IS_SRC_RING_LOW_WATERMARK_LSB) & TARGET_IS_SRC_RING_LOW_WATERMARK_MASK)
#define TARGET_IS_SRC_RING_LOW_WATERMARK_RESET                                 0x0
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_LSB                                  1
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_MSB                                  1
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_MASK                                 0x2
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_GET(x)                               (((x) & TARGET_IS_SRC_RING_HIGH_WATERMARK_MASK) >> TARGET_IS_SRC_RING_HIGH_WATERMARK_LSB)
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_SET(x)                               (((0 | (x)) << TARGET_IS_SRC_RING_HIGH_WATERMARK_LSB) & TARGET_IS_SRC_RING_HIGH_WATERMARK_MASK)
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_RESET                                0x0
#define TARGET_IS_COPY_COMPLETE_LSB                                            0
#define TARGET_IS_COPY_COMPLETE_MSB                                            0
#define TARGET_IS_COPY_COMPLETE_MASK                                           0x1
#define TARGET_IS_COPY_COMPLETE_GET(x)                                         (((x) & TARGET_IS_COPY_COMPLETE_MASK) >> TARGET_IS_COPY_COMPLETE_LSB)
#define TARGET_IS_COPY_COMPLETE_SET(x)                                         (((0 | (x)) << TARGET_IS_COPY_COMPLETE_LSB) & TARGET_IS_COPY_COMPLETE_MASK)
#define TARGET_IS_COPY_COMPLETE_RESET                                          0x0
#define TARGET_IS_ADDRESS                                                      (0x28 + __CE_REG_CSR_BASE_ADDRESS)
#define TARGET_IS_RSTMASK                                                      0x1f
#define TARGET_IS_RESET                                                        0x0

// 0x2c (HOST_IE)
#define HOST_IE_DST_RING_LOW_WATERMARK_LSB                                     4
#define HOST_IE_DST_RING_LOW_WATERMARK_MSB                                     4
#define HOST_IE_DST_RING_LOW_WATERMARK_MASK                                    0x10
#define HOST_IE_DST_RING_LOW_WATERMARK_GET(x)                                  (((x) & HOST_IE_DST_RING_LOW_WATERMARK_MASK) >> HOST_IE_DST_RING_LOW_WATERMARK_LSB)
#define HOST_IE_DST_RING_LOW_WATERMARK_SET(x)                                  (((0 | (x)) << HOST_IE_DST_RING_LOW_WATERMARK_LSB) & HOST_IE_DST_RING_LOW_WATERMARK_MASK)
#define HOST_IE_DST_RING_LOW_WATERMARK_RESET                                   0x0
#define HOST_IE_DST_RING_HIGH_WATERMARK_LSB                                    3
#define HOST_IE_DST_RING_HIGH_WATERMARK_MSB                                    3
#define HOST_IE_DST_RING_HIGH_WATERMARK_MASK                                   0x8
#define HOST_IE_DST_RING_HIGH_WATERMARK_GET(x)                                 (((x) & HOST_IE_DST_RING_HIGH_WATERMARK_MASK) >> HOST_IE_DST_RING_HIGH_WATERMARK_LSB)
#define HOST_IE_DST_RING_HIGH_WATERMARK_SET(x)                                 (((0 | (x)) << HOST_IE_DST_RING_HIGH_WATERMARK_LSB) & HOST_IE_DST_RING_HIGH_WATERMARK_MASK)
#define HOST_IE_DST_RING_HIGH_WATERMARK_RESET                                  0x0
#define HOST_IE_SRC_RING_LOW_WATERMARK_LSB                                     2
#define HOST_IE_SRC_RING_LOW_WATERMARK_MSB                                     2
#define HOST_IE_SRC_RING_LOW_WATERMARK_MASK                                    0x4
#define HOST_IE_SRC_RING_LOW_WATERMARK_GET(x)                                  (((x) & HOST_IE_SRC_RING_LOW_WATERMARK_MASK) >> HOST_IE_SRC_RING_LOW_WATERMARK_LSB)
#define HOST_IE_SRC_RING_LOW_WATERMARK_SET(x)                                  (((0 | (x)) << HOST_IE_SRC_RING_LOW_WATERMARK_LSB) & HOST_IE_SRC_RING_LOW_WATERMARK_MASK)
#define HOST_IE_SRC_RING_LOW_WATERMARK_RESET                                   0x0
#define HOST_IE_SRC_RING_HIGH_WATERMARK_LSB                                    1
#define HOST_IE_SRC_RING_HIGH_WATERMARK_MSB                                    1
#define HOST_IE_SRC_RING_HIGH_WATERMARK_MASK                                   0x2
#define HOST_IE_SRC_RING_HIGH_WATERMARK_GET(x)                                 (((x) & HOST_IE_SRC_RING_HIGH_WATERMARK_MASK) >> HOST_IE_SRC_RING_HIGH_WATERMARK_LSB)
#define HOST_IE_SRC_RING_HIGH_WATERMARK_SET(x)                                 (((0 | (x)) << HOST_IE_SRC_RING_HIGH_WATERMARK_LSB) & HOST_IE_SRC_RING_HIGH_WATERMARK_MASK)
#define HOST_IE_SRC_RING_HIGH_WATERMARK_RESET                                  0x0
#define HOST_IE_COPY_COMPLETE_LSB                                              0
#define HOST_IE_COPY_COMPLETE_MSB                                              0
#define HOST_IE_COPY_COMPLETE_MASK                                             0x1
#define HOST_IE_COPY_COMPLETE_GET(x)                                           (((x) & HOST_IE_COPY_COMPLETE_MASK) >> HOST_IE_COPY_COMPLETE_LSB)
#define HOST_IE_COPY_COMPLETE_SET(x)                                           (((0 | (x)) << HOST_IE_COPY_COMPLETE_LSB) & HOST_IE_COPY_COMPLETE_MASK)
#define HOST_IE_COPY_COMPLETE_RESET                                            0x0
#define HOST_IE_ADDRESS                                                        (0x2c + __CE_REG_CSR_BASE_ADDRESS)
#define HOST_IE_RSTMASK                                                        0x1f
#define HOST_IE_RESET                                                          0x0

// 0x30 (HOST_IS)
#define HOST_IS_DST_RING_LOW_WATERMARK_LSB                                     4
#define HOST_IS_DST_RING_LOW_WATERMARK_MSB                                     4
#define HOST_IS_DST_RING_LOW_WATERMARK_MASK                                    0x10
#define HOST_IS_DST_RING_LOW_WATERMARK_GET(x)                                  (((x) & HOST_IS_DST_RING_LOW_WATERMARK_MASK) >> HOST_IS_DST_RING_LOW_WATERMARK_LSB)
#define HOST_IS_DST_RING_LOW_WATERMARK_SET(x)                                  (((0 | (x)) << HOST_IS_DST_RING_LOW_WATERMARK_LSB) & HOST_IS_DST_RING_LOW_WATERMARK_MASK)
#define HOST_IS_DST_RING_LOW_WATERMARK_RESET                                   0x0
#define HOST_IS_DST_RING_HIGH_WATERMARK_LSB                                    3
#define HOST_IS_DST_RING_HIGH_WATERMARK_MSB                                    3
#define HOST_IS_DST_RING_HIGH_WATERMARK_MASK                                   0x8
#define HOST_IS_DST_RING_HIGH_WATERMARK_GET(x)                                 (((x) & HOST_IS_DST_RING_HIGH_WATERMARK_MASK) >> HOST_IS_DST_RING_HIGH_WATERMARK_LSB)
#define HOST_IS_DST_RING_HIGH_WATERMARK_SET(x)                                 (((0 | (x)) << HOST_IS_DST_RING_HIGH_WATERMARK_LSB) & HOST_IS_DST_RING_HIGH_WATERMARK_MASK)
#define HOST_IS_DST_RING_HIGH_WATERMARK_RESET                                  0x0
#define HOST_IS_SRC_RING_LOW_WATERMARK_LSB                                     2
#define HOST_IS_SRC_RING_LOW_WATERMARK_MSB                                     2
#define HOST_IS_SRC_RING_LOW_WATERMARK_MASK                                    0x4
#define HOST_IS_SRC_RING_LOW_WATERMARK_GET(x)                                  (((x) & HOST_IS_SRC_RING_LOW_WATERMARK_MASK) >> HOST_IS_SRC_RING_LOW_WATERMARK_LSB)
#define HOST_IS_SRC_RING_LOW_WATERMARK_SET(x)                                  (((0 | (x)) << HOST_IS_SRC_RING_LOW_WATERMARK_LSB) & HOST_IS_SRC_RING_LOW_WATERMARK_MASK)
#define HOST_IS_SRC_RING_LOW_WATERMARK_RESET                                   0x0
#define HOST_IS_SRC_RING_HIGH_WATERMARK_LSB                                    1
#define HOST_IS_SRC_RING_HIGH_WATERMARK_MSB                                    1
#define HOST_IS_SRC_RING_HIGH_WATERMARK_MASK                                   0x2
#define HOST_IS_SRC_RING_HIGH_WATERMARK_GET(x)                                 (((x) & HOST_IS_SRC_RING_HIGH_WATERMARK_MASK) >> HOST_IS_SRC_RING_HIGH_WATERMARK_LSB)
#define HOST_IS_SRC_RING_HIGH_WATERMARK_SET(x)                                 (((0 | (x)) << HOST_IS_SRC_RING_HIGH_WATERMARK_LSB) & HOST_IS_SRC_RING_HIGH_WATERMARK_MASK)
#define HOST_IS_SRC_RING_HIGH_WATERMARK_RESET                                  0x0
#define HOST_IS_COPY_COMPLETE_LSB                                              0
#define HOST_IS_COPY_COMPLETE_MSB                                              0
#define HOST_IS_COPY_COMPLETE_MASK                                             0x1
#define HOST_IS_COPY_COMPLETE_GET(x)                                           (((x) & HOST_IS_COPY_COMPLETE_MASK) >> HOST_IS_COPY_COMPLETE_LSB)
#define HOST_IS_COPY_COMPLETE_SET(x)                                           (((0 | (x)) << HOST_IS_COPY_COMPLETE_LSB) & HOST_IS_COPY_COMPLETE_MASK)
#define HOST_IS_COPY_COMPLETE_RESET                                            0x0
#define HOST_IS_ADDRESS                                                        (0x30 + __CE_REG_CSR_BASE_ADDRESS)
#define HOST_IS_RSTMASK                                                        0x1f
#define HOST_IS_RESET                                                          0x0

// 0x34 (MISC_IE)
#define MISC_IE_AXI_ERR_LSB                                                    10
#define MISC_IE_AXI_ERR_MSB                                                    10
#define MISC_IE_AXI_ERR_MASK                                                   0x400
#define MISC_IE_AXI_ERR_GET(x)                                                 (((x) & MISC_IE_AXI_ERR_MASK) >> MISC_IE_AXI_ERR_LSB)
#define MISC_IE_AXI_ERR_SET(x)                                                 (((0 | (x)) << MISC_IE_AXI_ERR_LSB) & MISC_IE_AXI_ERR_MASK)
#define MISC_IE_AXI_ERR_RESET                                                  0x0
#define MISC_IE_DST_ADDR_ERR_LSB                                               9
#define MISC_IE_DST_ADDR_ERR_MSB                                               9
#define MISC_IE_DST_ADDR_ERR_MASK                                              0x200
#define MISC_IE_DST_ADDR_ERR_GET(x)                                            (((x) & MISC_IE_DST_ADDR_ERR_MASK) >> MISC_IE_DST_ADDR_ERR_LSB)
#define MISC_IE_DST_ADDR_ERR_SET(x)                                            (((0 | (x)) << MISC_IE_DST_ADDR_ERR_LSB) & MISC_IE_DST_ADDR_ERR_MASK)
#define MISC_IE_DST_ADDR_ERR_RESET                                             0x0
#define MISC_IE_SRC_LEN_ERR_LSB                                                8
#define MISC_IE_SRC_LEN_ERR_MSB                                                8
#define MISC_IE_SRC_LEN_ERR_MASK                                               0x100
#define MISC_IE_SRC_LEN_ERR_GET(x)                                             (((x) & MISC_IE_SRC_LEN_ERR_MASK) >> MISC_IE_SRC_LEN_ERR_LSB)
#define MISC_IE_SRC_LEN_ERR_SET(x)                                             (((0 | (x)) << MISC_IE_SRC_LEN_ERR_LSB) & MISC_IE_SRC_LEN_ERR_MASK)
#define MISC_IE_SRC_LEN_ERR_RESET                                              0x0
#define MISC_IE_DST_MAX_LEN_VIO_LSB                                            7
#define MISC_IE_DST_MAX_LEN_VIO_MSB                                            7
#define MISC_IE_DST_MAX_LEN_VIO_MASK                                           0x80
#define MISC_IE_DST_MAX_LEN_VIO_GET(x)                                         (((x) & MISC_IE_DST_MAX_LEN_VIO_MASK) >> MISC_IE_DST_MAX_LEN_VIO_LSB)
#define MISC_IE_DST_MAX_LEN_VIO_SET(x)                                         (((0 | (x)) << MISC_IE_DST_MAX_LEN_VIO_LSB) & MISC_IE_DST_MAX_LEN_VIO_MASK)
#define MISC_IE_DST_MAX_LEN_VIO_RESET                                          0x0
#define MISC_IE_DST_RING_OVERFLOW_LSB                                          6
#define MISC_IE_DST_RING_OVERFLOW_MSB                                          6
#define MISC_IE_DST_RING_OVERFLOW_MASK                                         0x40
#define MISC_IE_DST_RING_OVERFLOW_GET(x)                                       (((x) & MISC_IE_DST_RING_OVERFLOW_MASK) >> MISC_IE_DST_RING_OVERFLOW_LSB)
#define MISC_IE_DST_RING_OVERFLOW_SET(x)                                       (((0 | (x)) << MISC_IE_DST_RING_OVERFLOW_LSB) & MISC_IE_DST_RING_OVERFLOW_MASK)
#define MISC_IE_DST_RING_OVERFLOW_RESET                                        0x0
#define MISC_IE_SRC_RING_OVERFLOW_LSB                                          5
#define MISC_IE_SRC_RING_OVERFLOW_MSB                                          5
#define MISC_IE_SRC_RING_OVERFLOW_MASK                                         0x20
#define MISC_IE_SRC_RING_OVERFLOW_GET(x)                                       (((x) & MISC_IE_SRC_RING_OVERFLOW_MASK) >> MISC_IE_SRC_RING_OVERFLOW_LSB)
#define MISC_IE_SRC_RING_OVERFLOW_SET(x)                                       (((0 | (x)) << MISC_IE_SRC_RING_OVERFLOW_LSB) & MISC_IE_SRC_RING_OVERFLOW_MASK)
#define MISC_IE_SRC_RING_OVERFLOW_RESET                                        0x0
#define MISC_IE_DST_RING_LOW_WATERMARK_LSB                                     4
#define MISC_IE_DST_RING_LOW_WATERMARK_MSB                                     4
#define MISC_IE_DST_RING_LOW_WATERMARK_MASK                                    0x10
#define MISC_IE_DST_RING_LOW_WATERMARK_GET(x)                                  (((x) & MISC_IE_DST_RING_LOW_WATERMARK_MASK) >> MISC_IE_DST_RING_LOW_WATERMARK_LSB)
#define MISC_IE_DST_RING_LOW_WATERMARK_SET(x)                                  (((0 | (x)) << MISC_IE_DST_RING_LOW_WATERMARK_LSB) & MISC_IE_DST_RING_LOW_WATERMARK_MASK)
#define MISC_IE_DST_RING_LOW_WATERMARK_RESET                                   0x0
#define MISC_IE_DST_RING_HIGH_WATERMARK_LSB                                    3
#define MISC_IE_DST_RING_HIGH_WATERMARK_MSB                                    3
#define MISC_IE_DST_RING_HIGH_WATERMARK_MASK                                   0x8
#define MISC_IE_DST_RING_HIGH_WATERMARK_GET(x)                                 (((x) & MISC_IE_DST_RING_HIGH_WATERMARK_MASK) >> MISC_IE_DST_RING_HIGH_WATERMARK_LSB)
#define MISC_IE_DST_RING_HIGH_WATERMARK_SET(x)                                 (((0 | (x)) << MISC_IE_DST_RING_HIGH_WATERMARK_LSB) & MISC_IE_DST_RING_HIGH_WATERMARK_MASK)
#define MISC_IE_DST_RING_HIGH_WATERMARK_RESET                                  0x0
#define MISC_IE_SRC_RING_LOW_WATERMARK_LSB                                     2
#define MISC_IE_SRC_RING_LOW_WATERMARK_MSB                                     2
#define MISC_IE_SRC_RING_LOW_WATERMARK_MASK                                    0x4
#define MISC_IE_SRC_RING_LOW_WATERMARK_GET(x)                                  (((x) & MISC_IE_SRC_RING_LOW_WATERMARK_MASK) >> MISC_IE_SRC_RING_LOW_WATERMARK_LSB)
#define MISC_IE_SRC_RING_LOW_WATERMARK_SET(x)                                  (((0 | (x)) << MISC_IE_SRC_RING_LOW_WATERMARK_LSB) & MISC_IE_SRC_RING_LOW_WATERMARK_MASK)
#define MISC_IE_SRC_RING_LOW_WATERMARK_RESET                                   0x0
#define MISC_IE_SRC_RING_HIGH_WATERMARK_LSB                                    1
#define MISC_IE_SRC_RING_HIGH_WATERMARK_MSB                                    1
#define MISC_IE_SRC_RING_HIGH_WATERMARK_MASK                                   0x2
#define MISC_IE_SRC_RING_HIGH_WATERMARK_GET(x)                                 (((x) & MISC_IE_SRC_RING_HIGH_WATERMARK_MASK) >> MISC_IE_SRC_RING_HIGH_WATERMARK_LSB)
#define MISC_IE_SRC_RING_HIGH_WATERMARK_SET(x)                                 (((0 | (x)) << MISC_IE_SRC_RING_HIGH_WATERMARK_LSB) & MISC_IE_SRC_RING_HIGH_WATERMARK_MASK)
#define MISC_IE_SRC_RING_HIGH_WATERMARK_RESET                                  0x0
#define MISC_IE_COPY_COMPLETE_LSB                                              0
#define MISC_IE_COPY_COMPLETE_MSB                                              0
#define MISC_IE_COPY_COMPLETE_MASK                                             0x1
#define MISC_IE_COPY_COMPLETE_GET(x)                                           (((x) & MISC_IE_COPY_COMPLETE_MASK) >> MISC_IE_COPY_COMPLETE_LSB)
#define MISC_IE_COPY_COMPLETE_SET(x)                                           (((0 | (x)) << MISC_IE_COPY_COMPLETE_LSB) & MISC_IE_COPY_COMPLETE_MASK)
#define MISC_IE_COPY_COMPLETE_RESET                                            0x0
#define MISC_IE_ADDRESS                                                        (0x34 + __CE_REG_CSR_BASE_ADDRESS)
#define MISC_IE_RSTMASK                                                        0x7ff
#define MISC_IE_RESET                                                          0x0

// 0x38 (MISC_IS)
#define MISC_IS_AXI_ERR_LSB                                                    10
#define MISC_IS_AXI_ERR_MSB                                                    10
#define MISC_IS_AXI_ERR_MASK                                                   0x400
#define MISC_IS_AXI_ERR_GET(x)                                                 (((x) & MISC_IS_AXI_ERR_MASK) >> MISC_IS_AXI_ERR_LSB)
#define MISC_IS_AXI_ERR_SET(x)                                                 (((0 | (x)) << MISC_IS_AXI_ERR_LSB) & MISC_IS_AXI_ERR_MASK)
#define MISC_IS_AXI_ERR_RESET                                                  0x0
#define MISC_IS_DST_ADDR_ERR_LSB                                               9
#define MISC_IS_DST_ADDR_ERR_MSB                                               9
#define MISC_IS_DST_ADDR_ERR_MASK                                              0x200
#define MISC_IS_DST_ADDR_ERR_GET(x)                                            (((x) & MISC_IS_DST_ADDR_ERR_MASK) >> MISC_IS_DST_ADDR_ERR_LSB)
#define MISC_IS_DST_ADDR_ERR_SET(x)                                            (((0 | (x)) << MISC_IS_DST_ADDR_ERR_LSB) & MISC_IS_DST_ADDR_ERR_MASK)
#define MISC_IS_DST_ADDR_ERR_RESET                                             0x0
#define MISC_IS_SRC_LEN_ERR_LSB                                                8
#define MISC_IS_SRC_LEN_ERR_MSB                                                8
#define MISC_IS_SRC_LEN_ERR_MASK                                               0x100
#define MISC_IS_SRC_LEN_ERR_GET(x)                                             (((x) & MISC_IS_SRC_LEN_ERR_MASK) >> MISC_IS_SRC_LEN_ERR_LSB)
#define MISC_IS_SRC_LEN_ERR_SET(x)                                             (((0 | (x)) << MISC_IS_SRC_LEN_ERR_LSB) & MISC_IS_SRC_LEN_ERR_MASK)
#define MISC_IS_SRC_LEN_ERR_RESET                                              0x0
#define MISC_IS_DST_MAX_LEN_VIO_LSB                                            7
#define MISC_IS_DST_MAX_LEN_VIO_MSB                                            7
#define MISC_IS_DST_MAX_LEN_VIO_MASK                                           0x80
#define MISC_IS_DST_MAX_LEN_VIO_GET(x)                                         (((x) & MISC_IS_DST_MAX_LEN_VIO_MASK) >> MISC_IS_DST_MAX_LEN_VIO_LSB)
#define MISC_IS_DST_MAX_LEN_VIO_SET(x)                                         (((0 | (x)) << MISC_IS_DST_MAX_LEN_VIO_LSB) & MISC_IS_DST_MAX_LEN_VIO_MASK)
#define MISC_IS_DST_MAX_LEN_VIO_RESET                                          0x0
#define MISC_IS_DST_RING_OVERFLOW_LSB                                          6
#define MISC_IS_DST_RING_OVERFLOW_MSB                                          6
#define MISC_IS_DST_RING_OVERFLOW_MASK                                         0x40
#define MISC_IS_DST_RING_OVERFLOW_GET(x)                                       (((x) & MISC_IS_DST_RING_OVERFLOW_MASK) >> MISC_IS_DST_RING_OVERFLOW_LSB)
#define MISC_IS_DST_RING_OVERFLOW_SET(x)                                       (((0 | (x)) << MISC_IS_DST_RING_OVERFLOW_LSB) & MISC_IS_DST_RING_OVERFLOW_MASK)
#define MISC_IS_DST_RING_OVERFLOW_RESET                                        0x0
#define MISC_IS_SRC_RING_OVERFLOW_LSB                                          5
#define MISC_IS_SRC_RING_OVERFLOW_MSB                                          5
#define MISC_IS_SRC_RING_OVERFLOW_MASK                                         0x20
#define MISC_IS_SRC_RING_OVERFLOW_GET(x)                                       (((x) & MISC_IS_SRC_RING_OVERFLOW_MASK) >> MISC_IS_SRC_RING_OVERFLOW_LSB)
#define MISC_IS_SRC_RING_OVERFLOW_SET(x)                                       (((0 | (x)) << MISC_IS_SRC_RING_OVERFLOW_LSB) & MISC_IS_SRC_RING_OVERFLOW_MASK)
#define MISC_IS_SRC_RING_OVERFLOW_RESET                                        0x0
#define MISC_IS_DST_RING_LOW_WATERMARK_LSB                                     4
#define MISC_IS_DST_RING_LOW_WATERMARK_MSB                                     4
#define MISC_IS_DST_RING_LOW_WATERMARK_MASK                                    0x10
#define MISC_IS_DST_RING_LOW_WATERMARK_GET(x)                                  (((x) & MISC_IS_DST_RING_LOW_WATERMARK_MASK) >> MISC_IS_DST_RING_LOW_WATERMARK_LSB)
#define MISC_IS_DST_RING_LOW_WATERMARK_SET(x)                                  (((0 | (x)) << MISC_IS_DST_RING_LOW_WATERMARK_LSB) & MISC_IS_DST_RING_LOW_WATERMARK_MASK)
#define MISC_IS_DST_RING_LOW_WATERMARK_RESET                                   0x0
#define MISC_IS_DST_RING_HIGH_WATERMARK_LSB                                    3
#define MISC_IS_DST_RING_HIGH_WATERMARK_MSB                                    3
#define MISC_IS_DST_RING_HIGH_WATERMARK_MASK                                   0x8
#define MISC_IS_DST_RING_HIGH_WATERMARK_GET(x)                                 (((x) & MISC_IS_DST_RING_HIGH_WATERMARK_MASK) >> MISC_IS_DST_RING_HIGH_WATERMARK_LSB)
#define MISC_IS_DST_RING_HIGH_WATERMARK_SET(x)                                 (((0 | (x)) << MISC_IS_DST_RING_HIGH_WATERMARK_LSB) & MISC_IS_DST_RING_HIGH_WATERMARK_MASK)
#define MISC_IS_DST_RING_HIGH_WATERMARK_RESET                                  0x0
#define MISC_IS_SRC_RING_LOW_WATERMARK_LSB                                     2
#define MISC_IS_SRC_RING_LOW_WATERMARK_MSB                                     2
#define MISC_IS_SRC_RING_LOW_WATERMARK_MASK                                    0x4
#define MISC_IS_SRC_RING_LOW_WATERMARK_GET(x)                                  (((x) & MISC_IS_SRC_RING_LOW_WATERMARK_MASK) >> MISC_IS_SRC_RING_LOW_WATERMARK_LSB)
#define MISC_IS_SRC_RING_LOW_WATERMARK_SET(x)                                  (((0 | (x)) << MISC_IS_SRC_RING_LOW_WATERMARK_LSB) & MISC_IS_SRC_RING_LOW_WATERMARK_MASK)
#define MISC_IS_SRC_RING_LOW_WATERMARK_RESET                                   0x0
#define MISC_IS_SRC_RING_HIGH_WATERMARK_LSB                                    1
#define MISC_IS_SRC_RING_HIGH_WATERMARK_MSB                                    1
#define MISC_IS_SRC_RING_HIGH_WATERMARK_MASK                                   0x2
#define MISC_IS_SRC_RING_HIGH_WATERMARK_GET(x)                                 (((x) & MISC_IS_SRC_RING_HIGH_WATERMARK_MASK) >> MISC_IS_SRC_RING_HIGH_WATERMARK_LSB)
#define MISC_IS_SRC_RING_HIGH_WATERMARK_SET(x)                                 (((0 | (x)) << MISC_IS_SRC_RING_HIGH_WATERMARK_LSB) & MISC_IS_SRC_RING_HIGH_WATERMARK_MASK)
#define MISC_IS_SRC_RING_HIGH_WATERMARK_RESET                                  0x0
#define MISC_IS_COPY_COMPLETE_LSB                                              0
#define MISC_IS_COPY_COMPLETE_MSB                                              0
#define MISC_IS_COPY_COMPLETE_MASK                                             0x1
#define MISC_IS_COPY_COMPLETE_GET(x)                                           (((x) & MISC_IS_COPY_COMPLETE_MASK) >> MISC_IS_COPY_COMPLETE_LSB)
#define MISC_IS_COPY_COMPLETE_SET(x)                                           (((0 | (x)) << MISC_IS_COPY_COMPLETE_LSB) & MISC_IS_COPY_COMPLETE_MASK)
#define MISC_IS_COPY_COMPLETE_RESET                                            0x0
#define MISC_IS_ADDRESS                                                        (0x38 + __CE_REG_CSR_BASE_ADDRESS)
#define MISC_IS_RSTMASK                                                        0x7ff
#define MISC_IS_RESET                                                          0x0

// 0x3c (SR_WR_INDEX)
#define SR_WR_INDEX_V_LSB                                                      0
#define SR_WR_INDEX_V_MSB                                                      15
#define SR_WR_INDEX_V_MASK                                                     0xffff
#define SR_WR_INDEX_V_GET(x)                                                   (((x) & SR_WR_INDEX_V_MASK) >> SR_WR_INDEX_V_LSB)
#define SR_WR_INDEX_V_SET(x)                                                   (((0 | (x)) << SR_WR_INDEX_V_LSB) & SR_WR_INDEX_V_MASK)
#define SR_WR_INDEX_V_RESET                                                    0x0
#define SR_WR_INDEX_ADDRESS                                                    (0x3c + __CE_REG_CSR_BASE_ADDRESS)
#define SR_WR_INDEX_RSTMASK                                                    0xffff
#define SR_WR_INDEX_RESET                                                      0x0

// 0x40 (DST_WR_INDEX)
#define DST_WR_INDEX_V_LSB                                                     0
#define DST_WR_INDEX_V_MSB                                                     15
#define DST_WR_INDEX_V_MASK                                                    0xffff
#define DST_WR_INDEX_V_GET(x)                                                  (((x) & DST_WR_INDEX_V_MASK) >> DST_WR_INDEX_V_LSB)
#define DST_WR_INDEX_V_SET(x)                                                  (((0 | (x)) << DST_WR_INDEX_V_LSB) & DST_WR_INDEX_V_MASK)
#define DST_WR_INDEX_V_RESET                                                   0x0
#define DST_WR_INDEX_ADDRESS                                                   (0x40 + __CE_REG_CSR_BASE_ADDRESS)
#define DST_WR_INDEX_RSTMASK                                                   0xffff
#define DST_WR_INDEX_RESET                                                     0x0

// 0x44 (CURRENT_SRRI)
#define CURRENT_SRRI_V_LSB                                                     0
#define CURRENT_SRRI_V_MSB                                                     15
#define CURRENT_SRRI_V_MASK                                                    0xffff
#define CURRENT_SRRI_V_GET(x)                                                  (((x) & CURRENT_SRRI_V_MASK) >> CURRENT_SRRI_V_LSB)
#define CURRENT_SRRI_V_SET(x)                                                  (((0 | (x)) << CURRENT_SRRI_V_LSB) & CURRENT_SRRI_V_MASK)
#define CURRENT_SRRI_V_RESET                                                   0x0
#define CURRENT_SRRI_ADDRESS                                                   (0x44 + __CE_REG_CSR_BASE_ADDRESS)
#define CURRENT_SRRI_RSTMASK                                                   0xffff
#define CURRENT_SRRI_RESET                                                     0x0

// 0x48 (CURRENT_DRRI)
#define CURRENT_DRRI_V_LSB                                                     0
#define CURRENT_DRRI_V_MSB                                                     15
#define CURRENT_DRRI_V_MASK                                                    0xffff
#define CURRENT_DRRI_V_GET(x)                                                  (((x) & CURRENT_DRRI_V_MASK) >> CURRENT_DRRI_V_LSB)
#define CURRENT_DRRI_V_SET(x)                                                  (((0 | (x)) << CURRENT_DRRI_V_LSB) & CURRENT_DRRI_V_MASK)
#define CURRENT_DRRI_V_RESET                                                   0x0
#define CURRENT_DRRI_ADDRESS                                                   (0x48 + __CE_REG_CSR_BASE_ADDRESS)
#define CURRENT_DRRI_RSTMASK                                                   0xffff
#define CURRENT_DRRI_RESET                                                     0x0

// 0x4c (SRC_WATERMARK)
#define SRC_WATERMARK_LOW_LSB                                                  16
#define SRC_WATERMARK_LOW_MSB                                                  31
#define SRC_WATERMARK_LOW_MASK                                                 0xffff0000
#define SRC_WATERMARK_LOW_GET(x)                                               (((x) & SRC_WATERMARK_LOW_MASK) >> SRC_WATERMARK_LOW_LSB)
#define SRC_WATERMARK_LOW_SET(x)                                               (((0 | (x)) << SRC_WATERMARK_LOW_LSB) & SRC_WATERMARK_LOW_MASK)
#define SRC_WATERMARK_LOW_RESET                                                0x0
#define SRC_WATERMARK_HIGH_LSB                                                 0
#define SRC_WATERMARK_HIGH_MSB                                                 15
#define SRC_WATERMARK_HIGH_MASK                                                0xffff
#define SRC_WATERMARK_HIGH_GET(x)                                              (((x) & SRC_WATERMARK_HIGH_MASK) >> SRC_WATERMARK_HIGH_LSB)
#define SRC_WATERMARK_HIGH_SET(x)                                              (((0 | (x)) << SRC_WATERMARK_HIGH_LSB) & SRC_WATERMARK_HIGH_MASK)
#define SRC_WATERMARK_HIGH_RESET                                               0x0
#define SRC_WATERMARK_ADDRESS                                                  (0x4c + __CE_REG_CSR_BASE_ADDRESS)
#define SRC_WATERMARK_RSTMASK                                                  0xffffffff
#define SRC_WATERMARK_RESET                                                    0x0

// 0x50 (DST_WATERMARK)
#define DST_WATERMARK_LOW_LSB                                                  16
#define DST_WATERMARK_LOW_MSB                                                  31
#define DST_WATERMARK_LOW_MASK                                                 0xffff0000
#define DST_WATERMARK_LOW_GET(x)                                               (((x) & DST_WATERMARK_LOW_MASK) >> DST_WATERMARK_LOW_LSB)
#define DST_WATERMARK_LOW_SET(x)                                               (((0 | (x)) << DST_WATERMARK_LOW_LSB) & DST_WATERMARK_LOW_MASK)
#define DST_WATERMARK_LOW_RESET                                                0x0
#define DST_WATERMARK_HIGH_LSB                                                 0
#define DST_WATERMARK_HIGH_MSB                                                 15
#define DST_WATERMARK_HIGH_MASK                                                0xffff
#define DST_WATERMARK_HIGH_GET(x)                                              (((x) & DST_WATERMARK_HIGH_MASK) >> DST_WATERMARK_HIGH_LSB)
#define DST_WATERMARK_HIGH_SET(x)                                              (((0 | (x)) << DST_WATERMARK_HIGH_LSB) & DST_WATERMARK_HIGH_MASK)
#define DST_WATERMARK_HIGH_RESET                                               0x0
#define DST_WATERMARK_ADDRESS                                                  (0x50 + __CE_REG_CSR_BASE_ADDRESS)
#define DST_WATERMARK_RSTMASK                                                  0xffffffff
#define DST_WATERMARK_RESET                                                    0x0

// 0x54 (CE_DEBUG)
#define CE_DEBUG_SEL_LSB                                                       0
#define CE_DEBUG_SEL_MSB                                                       5
#define CE_DEBUG_SEL_MASK                                                      0x3f
#define CE_DEBUG_SEL_GET(x)                                                    (((x) & CE_DEBUG_SEL_MASK) >> CE_DEBUG_SEL_LSB)
#define CE_DEBUG_SEL_SET(x)                                                    (((0 | (x)) << CE_DEBUG_SEL_LSB) & CE_DEBUG_SEL_MASK)
#define CE_DEBUG_SEL_RESET                                                     0x0
#define CE_DEBUG_ADDRESS                                                       (0x54 + __CE_REG_CSR_BASE_ADDRESS)
#define CE_DEBUG_RSTMASK                                                       0x3f
#define CE_DEBUG_RESET                                                         0x0

// 0x58 (CE_WATCHDOG)
#define CE_WATCHDOG_STATUS_LSB                                                 16
#define CE_WATCHDOG_STATUS_MSB                                                 31
#define CE_WATCHDOG_STATUS_MASK                                                0xffff0000
#define CE_WATCHDOG_STATUS_GET(x)                                              (((x) & CE_WATCHDOG_STATUS_MASK) >> CE_WATCHDOG_STATUS_LSB)
#define CE_WATCHDOG_STATUS_SET(x)                                              (((0 | (x)) << CE_WATCHDOG_STATUS_LSB) & CE_WATCHDOG_STATUS_MASK)
#define CE_WATCHDOG_STATUS_RESET                                               0x0
#define CE_WATCHDOG_LIMIT_LSB                                                  0
#define CE_WATCHDOG_LIMIT_MSB                                                  15
#define CE_WATCHDOG_LIMIT_MASK                                                 0xffff
#define CE_WATCHDOG_LIMIT_GET(x)                                               (((x) & CE_WATCHDOG_LIMIT_MASK) >> CE_WATCHDOG_LIMIT_LSB)
#define CE_WATCHDOG_LIMIT_SET(x)                                               (((0 | (x)) << CE_WATCHDOG_LIMIT_LSB) & CE_WATCHDOG_LIMIT_MASK)
#define CE_WATCHDOG_LIMIT_RESET                                                0xffff
#define CE_WATCHDOG_ADDRESS                                                    (0x58 + __CE_REG_CSR_BASE_ADDRESS)
#define CE_WATCHDOG_RSTMASK                                                    0xffffffff
#define CE_WATCHDOG_RESET                                                      0xffff



#endif /* _CE_REG_CSR_H_ */
