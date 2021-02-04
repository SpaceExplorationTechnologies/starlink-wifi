/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _MAC_TXDMA_REG_H_
#define _MAC_TXDMA_REG_H_


#ifndef __MAC_TXDMA_REG_BASE_ADDRESS
#define __MAC_TXDMA_REG_BASE_ADDRESS (0x30400)
#endif


// 0x0 (MSDU_INFO_FETCH_CFG)
#define MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_LSB                         0
#define MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_MSB                         2
#define MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_MASK                        0x7
#define MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_GET(x)                      (((x) & MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_MASK) >> MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_LSB)
#define MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_SET(x)                      (((0 | (x)) << MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_LSB) & MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_MASK)
#define MSDU_INFO_FETCH_CFG_MAX_FRAG_TABLE_ENTRIES_RESET                       0x5
#define MSDU_INFO_FETCH_CFG_ADDRESS                                            (0x0 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define MSDU_INFO_FETCH_CFG_RSTMASK                                            0x7
#define MSDU_INFO_FETCH_CFG_RESET                                              0x5

// 0x4 (TXDATA_FETCH_CFG)
#define TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_LSB                           8
#define TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_MSB                           8
#define TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_MASK                          0x100
#define TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_GET(x)                        (((x) & TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_MASK) >> TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_LSB)
#define TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_SET(x)                        (((0 | (x)) << TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_LSB) & TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_MASK)
#define TXDATA_FETCH_CFG_DISABLE_SPACE_AWARE_DMA_RESET                         0x0
#define TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_LSB                       0
#define TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_MSB                       7
#define TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_MASK                      0xff
#define TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_GET(x)                    (((x) & TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_MASK) >> TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_LSB)
#define TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_SET(x)                    (((0 | (x)) << TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_LSB) & TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_MASK)
#define TXDATA_FETCH_CFG_MARGIN_OLE_BUF_AVAIL_DWORDS_RESET                     0x14
#define TXDATA_FETCH_CFG_ADDRESS                                               (0x4 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define TXDATA_FETCH_CFG_RSTMASK                                               0x1ff
#define TXDATA_FETCH_CFG_RESET                                                 0x14

// 0x8 (TXDMA_ERROR_OLE_CFG)
#define TXDMA_ERROR_OLE_CFG_OLE_TIMEOUT_LIMIT_LSB                              0
#define TXDMA_ERROR_OLE_CFG_OLE_TIMEOUT_LIMIT_MSB                              7
#define TXDMA_ERROR_OLE_CFG_OLE_TIMEOUT_LIMIT_MASK                             0xff
#define TXDMA_ERROR_OLE_CFG_OLE_TIMEOUT_LIMIT_GET(x)                           (((x) & TXDMA_ERROR_OLE_CFG_OLE_TIMEOUT_LIMIT_MASK) >> TXDMA_ERROR_OLE_CFG_OLE_TIMEOUT_LIMIT_LSB)
#define TXDMA_ERROR_OLE_CFG_OLE_TIMEOUT_LIMIT_SET(x)                           (((0 | (x)) << TXDMA_ERROR_OLE_CFG_OLE_TIMEOUT_LIMIT_LSB) & TXDMA_ERROR_OLE_CFG_OLE_TIMEOUT_LIMIT_MASK)
#define TXDMA_ERROR_OLE_CFG_OLE_TIMEOUT_LIMIT_RESET                            0x7f
#define TXDMA_ERROR_OLE_CFG_ADDRESS                                            (0x8 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define TXDMA_ERROR_OLE_CFG_RSTMASK                                            0xff
#define TXDMA_ERROR_OLE_CFG_RESET                                              0x7f

// 0xc (WATCHDOG)
#define WATCHDOG_STATUS_LSB                                                    16
#define WATCHDOG_STATUS_MSB                                                    31
#define WATCHDOG_STATUS_MASK                                                   0xffff0000
#define WATCHDOG_STATUS_GET(x)                                                 (((x) & WATCHDOG_STATUS_MASK) >> WATCHDOG_STATUS_LSB)
#define WATCHDOG_STATUS_SET(x)                                                 (((0 | (x)) << WATCHDOG_STATUS_LSB) & WATCHDOG_STATUS_MASK)
#define WATCHDOG_STATUS_RESET                                                  0x0
#define WATCHDOG_LIMIT_LSB                                                     0
#define WATCHDOG_LIMIT_MSB                                                     15
#define WATCHDOG_LIMIT_MASK                                                    0xffff
#define WATCHDOG_LIMIT_GET(x)                                                  (((x) & WATCHDOG_LIMIT_MASK) >> WATCHDOG_LIMIT_LSB)
#define WATCHDOG_LIMIT_SET(x)                                                  (((0 | (x)) << WATCHDOG_LIMIT_LSB) & WATCHDOG_LIMIT_MASK)
#define WATCHDOG_LIMIT_RESET                                                   0xffff
#define WATCHDOG_ADDRESS                                                       (0xc + __MAC_TXDMA_REG_BASE_ADDRESS)
#define WATCHDOG_RSTMASK                                                       0xffffffff
#define WATCHDOG_RESET                                                         0xffff

// 0x10 (TXDMA_TRACEBUS)
#define TXDMA_TRACEBUS_SELECT_LSB                                              0
#define TXDMA_TRACEBUS_SELECT_MSB                                              31
#define TXDMA_TRACEBUS_SELECT_MASK                                             0xffffffff
#define TXDMA_TRACEBUS_SELECT_GET(x)                                           (((x) & TXDMA_TRACEBUS_SELECT_MASK) >> TXDMA_TRACEBUS_SELECT_LSB)
#define TXDMA_TRACEBUS_SELECT_SET(x)                                           (((0 | (x)) << TXDMA_TRACEBUS_SELECT_LSB) & TXDMA_TRACEBUS_SELECT_MASK)
#define TXDMA_TRACEBUS_SELECT_RESET                                            0x0
#define TXDMA_TRACEBUS_ADDRESS                                                 (0x10 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define TXDMA_TRACEBUS_RSTMASK                                                 0xffffffff
#define TXDMA_TRACEBUS_RESET                                                   0x0

// 0x14 (PROG_IDX_SIZE)
#define PROG_IDX_SIZE_MSDU_LINK_MULT_SHIFTED_IDX_BY3_LSB                       7
#define PROG_IDX_SIZE_MSDU_LINK_MULT_SHIFTED_IDX_BY3_MSB                       7
#define PROG_IDX_SIZE_MSDU_LINK_MULT_SHIFTED_IDX_BY3_MASK                      0x80
#define PROG_IDX_SIZE_MSDU_LINK_MULT_SHIFTED_IDX_BY3_GET(x)                    (((x) & PROG_IDX_SIZE_MSDU_LINK_MULT_SHIFTED_IDX_BY3_MASK) >> PROG_IDX_SIZE_MSDU_LINK_MULT_SHIFTED_IDX_BY3_LSB)
#define PROG_IDX_SIZE_MSDU_LINK_MULT_SHIFTED_IDX_BY3_SET(x)                    (((0 | (x)) << PROG_IDX_SIZE_MSDU_LINK_MULT_SHIFTED_IDX_BY3_LSB) & PROG_IDX_SIZE_MSDU_LINK_MULT_SHIFTED_IDX_BY3_MASK)
#define PROG_IDX_SIZE_MSDU_LINK_MULT_SHIFTED_IDX_BY3_RESET                     0x0
#define PROG_IDX_SIZE_MSDU_LINK_SHIFT_FACTOR_LSB                               4
#define PROG_IDX_SIZE_MSDU_LINK_SHIFT_FACTOR_MSB                               6
#define PROG_IDX_SIZE_MSDU_LINK_SHIFT_FACTOR_MASK                              0x70
#define PROG_IDX_SIZE_MSDU_LINK_SHIFT_FACTOR_GET(x)                            (((x) & PROG_IDX_SIZE_MSDU_LINK_SHIFT_FACTOR_MASK) >> PROG_IDX_SIZE_MSDU_LINK_SHIFT_FACTOR_LSB)
#define PROG_IDX_SIZE_MSDU_LINK_SHIFT_FACTOR_SET(x)                            (((0 | (x)) << PROG_IDX_SIZE_MSDU_LINK_SHIFT_FACTOR_LSB) & PROG_IDX_SIZE_MSDU_LINK_SHIFT_FACTOR_MASK)
#define PROG_IDX_SIZE_MSDU_LINK_SHIFT_FACTOR_RESET                             0x0
#define PROG_IDX_SIZE_MPDU_LINK_MULT_SHIFTED_IDX_BY3_LSB                       3
#define PROG_IDX_SIZE_MPDU_LINK_MULT_SHIFTED_IDX_BY3_MSB                       3
#define PROG_IDX_SIZE_MPDU_LINK_MULT_SHIFTED_IDX_BY3_MASK                      0x8
#define PROG_IDX_SIZE_MPDU_LINK_MULT_SHIFTED_IDX_BY3_GET(x)                    (((x) & PROG_IDX_SIZE_MPDU_LINK_MULT_SHIFTED_IDX_BY3_MASK) >> PROG_IDX_SIZE_MPDU_LINK_MULT_SHIFTED_IDX_BY3_LSB)
#define PROG_IDX_SIZE_MPDU_LINK_MULT_SHIFTED_IDX_BY3_SET(x)                    (((0 | (x)) << PROG_IDX_SIZE_MPDU_LINK_MULT_SHIFTED_IDX_BY3_LSB) & PROG_IDX_SIZE_MPDU_LINK_MULT_SHIFTED_IDX_BY3_MASK)
#define PROG_IDX_SIZE_MPDU_LINK_MULT_SHIFTED_IDX_BY3_RESET                     0x0
#define PROG_IDX_SIZE_MPDU_LINK_SHIFT_FACTOR_LSB                               0
#define PROG_IDX_SIZE_MPDU_LINK_SHIFT_FACTOR_MSB                               2
#define PROG_IDX_SIZE_MPDU_LINK_SHIFT_FACTOR_MASK                              0x7
#define PROG_IDX_SIZE_MPDU_LINK_SHIFT_FACTOR_GET(x)                            (((x) & PROG_IDX_SIZE_MPDU_LINK_SHIFT_FACTOR_MASK) >> PROG_IDX_SIZE_MPDU_LINK_SHIFT_FACTOR_LSB)
#define PROG_IDX_SIZE_MPDU_LINK_SHIFT_FACTOR_SET(x)                            (((0 | (x)) << PROG_IDX_SIZE_MPDU_LINK_SHIFT_FACTOR_LSB) & PROG_IDX_SIZE_MPDU_LINK_SHIFT_FACTOR_MASK)
#define PROG_IDX_SIZE_MPDU_LINK_SHIFT_FACTOR_RESET                             0x0
#define PROG_IDX_SIZE_ADDRESS                                                  (0x14 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define PROG_IDX_SIZE_RSTMASK                                                  0xff
#define PROG_IDX_SIZE_RESET                                                    0x0

// 0x18 (TXDMA_TRACEBUS_READ_UPPER)
#define TXDMA_TRACEBUS_READ_UPPER_REG_8_LSB                                    0
#define TXDMA_TRACEBUS_READ_UPPER_REG_8_MSB                                    7
#define TXDMA_TRACEBUS_READ_UPPER_REG_8_MASK                                   0xff
#define TXDMA_TRACEBUS_READ_UPPER_REG_8_GET(x)                                 (((x) & TXDMA_TRACEBUS_READ_UPPER_REG_8_MASK) >> TXDMA_TRACEBUS_READ_UPPER_REG_8_LSB)
#define TXDMA_TRACEBUS_READ_UPPER_REG_8_SET(x)                                 (((0 | (x)) << TXDMA_TRACEBUS_READ_UPPER_REG_8_LSB) & TXDMA_TRACEBUS_READ_UPPER_REG_8_MASK)
#define TXDMA_TRACEBUS_READ_UPPER_REG_8_RESET                                  0x0
#define TXDMA_TRACEBUS_READ_UPPER_ADDRESS                                      (0x18 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define TXDMA_TRACEBUS_READ_UPPER_RSTMASK                                      0xff
#define TXDMA_TRACEBUS_READ_UPPER_RESET                                        0x0

// 0x1c (TXDMA_TRACEBUS_READ_LOWER)
#define TXDMA_TRACEBUS_READ_LOWER_REG_32_LSB                                   0
#define TXDMA_TRACEBUS_READ_LOWER_REG_32_MSB                                   31
#define TXDMA_TRACEBUS_READ_LOWER_REG_32_MASK                                  0xffffffff
#define TXDMA_TRACEBUS_READ_LOWER_REG_32_GET(x)                                (((x) & TXDMA_TRACEBUS_READ_LOWER_REG_32_MASK) >> TXDMA_TRACEBUS_READ_LOWER_REG_32_LSB)
#define TXDMA_TRACEBUS_READ_LOWER_REG_32_SET(x)                                (((0 | (x)) << TXDMA_TRACEBUS_READ_LOWER_REG_32_LSB) & TXDMA_TRACEBUS_READ_LOWER_REG_32_MASK)
#define TXDMA_TRACEBUS_READ_LOWER_REG_32_RESET                                 0x8
#define TXDMA_TRACEBUS_READ_LOWER_ADDRESS                                      (0x1c + __MAC_TXDMA_REG_BASE_ADDRESS)
#define TXDMA_TRACEBUS_READ_LOWER_RSTMASK                                      0xffffffff
#define TXDMA_TRACEBUS_READ_LOWER_RESET                                        0x8

// 0x20 (DATA_SWAP)
#define DATA_SWAP_REG_LSB                                                      0
#define DATA_SWAP_REG_MSB                                                      0
#define DATA_SWAP_REG_MASK                                                     0x1
#define DATA_SWAP_REG_GET(x)                                                   (((x) & DATA_SWAP_REG_MASK) >> DATA_SWAP_REG_LSB)
#define DATA_SWAP_REG_SET(x)                                                   (((0 | (x)) << DATA_SWAP_REG_LSB) & DATA_SWAP_REG_MASK)
#define DATA_SWAP_REG_RESET                                                    0x0
#define DATA_SWAP_ADDRESS                                                      (0x20 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define DATA_SWAP_RSTMASK                                                      0x1
#define DATA_SWAP_RESET                                                        0x0

// 0x24 (DEBUG_COUNTER_ENABLE)
#define DEBUG_COUNTER_ENABLE_DATA_DWORDS_LSB                                   5
#define DEBUG_COUNTER_ENABLE_DATA_DWORDS_MSB                                   5
#define DEBUG_COUNTER_ENABLE_DATA_DWORDS_MASK                                  0x20
#define DEBUG_COUNTER_ENABLE_DATA_DWORDS_GET(x)                                (((x) & DEBUG_COUNTER_ENABLE_DATA_DWORDS_MASK) >> DEBUG_COUNTER_ENABLE_DATA_DWORDS_LSB)
#define DEBUG_COUNTER_ENABLE_DATA_DWORDS_SET(x)                                (((0 | (x)) << DEBUG_COUNTER_ENABLE_DATA_DWORDS_LSB) & DEBUG_COUNTER_ENABLE_DATA_DWORDS_MASK)
#define DEBUG_COUNTER_ENABLE_DATA_DWORDS_RESET                                 0x0
#define DEBUG_COUNTER_ENABLE_MPDU_LSB                                          4
#define DEBUG_COUNTER_ENABLE_MPDU_MSB                                          4
#define DEBUG_COUNTER_ENABLE_MPDU_MASK                                         0x10
#define DEBUG_COUNTER_ENABLE_MPDU_GET(x)                                       (((x) & DEBUG_COUNTER_ENABLE_MPDU_MASK) >> DEBUG_COUNTER_ENABLE_MPDU_LSB)
#define DEBUG_COUNTER_ENABLE_MPDU_SET(x)                                       (((0 | (x)) << DEBUG_COUNTER_ENABLE_MPDU_LSB) & DEBUG_COUNTER_ENABLE_MPDU_MASK)
#define DEBUG_COUNTER_ENABLE_MPDU_RESET                                        0x0
#define DEBUG_COUNTER_ENABLE_FLUSH_REQ_LSB                                     3
#define DEBUG_COUNTER_ENABLE_FLUSH_REQ_MSB                                     3
#define DEBUG_COUNTER_ENABLE_FLUSH_REQ_MASK                                    0x8
#define DEBUG_COUNTER_ENABLE_FLUSH_REQ_GET(x)                                  (((x) & DEBUG_COUNTER_ENABLE_FLUSH_REQ_MASK) >> DEBUG_COUNTER_ENABLE_FLUSH_REQ_LSB)
#define DEBUG_COUNTER_ENABLE_FLUSH_REQ_SET(x)                                  (((0 | (x)) << DEBUG_COUNTER_ENABLE_FLUSH_REQ_LSB) & DEBUG_COUNTER_ENABLE_FLUSH_REQ_MASK)
#define DEBUG_COUNTER_ENABLE_FLUSH_REQ_RESET                                   0x0
#define DEBUG_COUNTER_ENABLE_FES_STATUS_LSB                                    2
#define DEBUG_COUNTER_ENABLE_FES_STATUS_MSB                                    2
#define DEBUG_COUNTER_ENABLE_FES_STATUS_MASK                                   0x4
#define DEBUG_COUNTER_ENABLE_FES_STATUS_GET(x)                                 (((x) & DEBUG_COUNTER_ENABLE_FES_STATUS_MASK) >> DEBUG_COUNTER_ENABLE_FES_STATUS_LSB)
#define DEBUG_COUNTER_ENABLE_FES_STATUS_SET(x)                                 (((0 | (x)) << DEBUG_COUNTER_ENABLE_FES_STATUS_LSB) & DEBUG_COUNTER_ENABLE_FES_STATUS_MASK)
#define DEBUG_COUNTER_ENABLE_FES_STATUS_RESET                                  0x0
#define DEBUG_COUNTER_ENABLE_FLUSH_LSB                                         1
#define DEBUG_COUNTER_ENABLE_FLUSH_MSB                                         1
#define DEBUG_COUNTER_ENABLE_FLUSH_MASK                                        0x2
#define DEBUG_COUNTER_ENABLE_FLUSH_GET(x)                                      (((x) & DEBUG_COUNTER_ENABLE_FLUSH_MASK) >> DEBUG_COUNTER_ENABLE_FLUSH_LSB)
#define DEBUG_COUNTER_ENABLE_FLUSH_SET(x)                                      (((0 | (x)) << DEBUG_COUNTER_ENABLE_FLUSH_LSB) & DEBUG_COUNTER_ENABLE_FLUSH_MASK)
#define DEBUG_COUNTER_ENABLE_FLUSH_RESET                                       0x0
#define DEBUG_COUNTER_ENABLE_FES_SETUP_LSB                                     0
#define DEBUG_COUNTER_ENABLE_FES_SETUP_MSB                                     0
#define DEBUG_COUNTER_ENABLE_FES_SETUP_MASK                                    0x1
#define DEBUG_COUNTER_ENABLE_FES_SETUP_GET(x)                                  (((x) & DEBUG_COUNTER_ENABLE_FES_SETUP_MASK) >> DEBUG_COUNTER_ENABLE_FES_SETUP_LSB)
#define DEBUG_COUNTER_ENABLE_FES_SETUP_SET(x)                                  (((0 | (x)) << DEBUG_COUNTER_ENABLE_FES_SETUP_LSB) & DEBUG_COUNTER_ENABLE_FES_SETUP_MASK)
#define DEBUG_COUNTER_ENABLE_FES_SETUP_RESET                                   0x0
#define DEBUG_COUNTER_ENABLE_ADDRESS                                           (0x24 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define DEBUG_COUNTER_ENABLE_RSTMASK                                           0x3f
#define DEBUG_COUNTER_ENABLE_RESET                                             0x0

// 0x28 (DEBUG_FES_SETUP)
#define DEBUG_FES_SETUP_COUNT_LSB                                              0
#define DEBUG_FES_SETUP_COUNT_MSB                                              31
#define DEBUG_FES_SETUP_COUNT_MASK                                             0xffffffff
#define DEBUG_FES_SETUP_COUNT_GET(x)                                           (((x) & DEBUG_FES_SETUP_COUNT_MASK) >> DEBUG_FES_SETUP_COUNT_LSB)
#define DEBUG_FES_SETUP_COUNT_SET(x)                                           (((0 | (x)) << DEBUG_FES_SETUP_COUNT_LSB) & DEBUG_FES_SETUP_COUNT_MASK)
#define DEBUG_FES_SETUP_COUNT_RESET                                            0x0
#define DEBUG_FES_SETUP_ADDRESS                                                (0x28 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define DEBUG_FES_SETUP_RSTMASK                                                0xffffffff
#define DEBUG_FES_SETUP_RESET                                                  0x0

// 0x2c (DEBUG_FLUSH)
#define DEBUG_FLUSH_COUNT_LSB                                                  0
#define DEBUG_FLUSH_COUNT_MSB                                                  31
#define DEBUG_FLUSH_COUNT_MASK                                                 0xffffffff
#define DEBUG_FLUSH_COUNT_GET(x)                                               (((x) & DEBUG_FLUSH_COUNT_MASK) >> DEBUG_FLUSH_COUNT_LSB)
#define DEBUG_FLUSH_COUNT_SET(x)                                               (((0 | (x)) << DEBUG_FLUSH_COUNT_LSB) & DEBUG_FLUSH_COUNT_MASK)
#define DEBUG_FLUSH_COUNT_RESET                                                0x0
#define DEBUG_FLUSH_ADDRESS                                                    (0x2c + __MAC_TXDMA_REG_BASE_ADDRESS)
#define DEBUG_FLUSH_RSTMASK                                                    0xffffffff
#define DEBUG_FLUSH_RESET                                                      0x0

// 0x30 (DEBUG_FES_STATUS)
#define DEBUG_FES_STATUS_COUNT_LSB                                             0
#define DEBUG_FES_STATUS_COUNT_MSB                                             31
#define DEBUG_FES_STATUS_COUNT_MASK                                            0xffffffff
#define DEBUG_FES_STATUS_COUNT_GET(x)                                          (((x) & DEBUG_FES_STATUS_COUNT_MASK) >> DEBUG_FES_STATUS_COUNT_LSB)
#define DEBUG_FES_STATUS_COUNT_SET(x)                                          (((0 | (x)) << DEBUG_FES_STATUS_COUNT_LSB) & DEBUG_FES_STATUS_COUNT_MASK)
#define DEBUG_FES_STATUS_COUNT_RESET                                           0x0
#define DEBUG_FES_STATUS_ADDRESS                                               (0x30 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define DEBUG_FES_STATUS_RSTMASK                                               0xffffffff
#define DEBUG_FES_STATUS_RESET                                                 0x0

// 0x34 (DEBUG_FLUSH_REQ)
#define DEBUG_FLUSH_REQ_COUNT_LSB                                              0
#define DEBUG_FLUSH_REQ_COUNT_MSB                                              31
#define DEBUG_FLUSH_REQ_COUNT_MASK                                             0xffffffff
#define DEBUG_FLUSH_REQ_COUNT_GET(x)                                           (((x) & DEBUG_FLUSH_REQ_COUNT_MASK) >> DEBUG_FLUSH_REQ_COUNT_LSB)
#define DEBUG_FLUSH_REQ_COUNT_SET(x)                                           (((0 | (x)) << DEBUG_FLUSH_REQ_COUNT_LSB) & DEBUG_FLUSH_REQ_COUNT_MASK)
#define DEBUG_FLUSH_REQ_COUNT_RESET                                            0x0
#define DEBUG_FLUSH_REQ_ADDRESS                                                (0x34 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define DEBUG_FLUSH_REQ_RSTMASK                                                0xffffffff
#define DEBUG_FLUSH_REQ_RESET                                                  0x0

// 0x38 (DEBUG_MPDU)
#define DEBUG_MPDU_COUNT_LSB                                                   0
#define DEBUG_MPDU_COUNT_MSB                                                   31
#define DEBUG_MPDU_COUNT_MASK                                                  0xffffffff
#define DEBUG_MPDU_COUNT_GET(x)                                                (((x) & DEBUG_MPDU_COUNT_MASK) >> DEBUG_MPDU_COUNT_LSB)
#define DEBUG_MPDU_COUNT_SET(x)                                                (((0 | (x)) << DEBUG_MPDU_COUNT_LSB) & DEBUG_MPDU_COUNT_MASK)
#define DEBUG_MPDU_COUNT_RESET                                                 0x0
#define DEBUG_MPDU_ADDRESS                                                     (0x38 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define DEBUG_MPDU_RSTMASK                                                     0xffffffff
#define DEBUG_MPDU_RESET                                                       0x0

// 0x3c (DEBUG_MSDU_DATA_DWORDS)
#define DEBUG_MSDU_DATA_DWORDS_COUNT_LSB                                       0
#define DEBUG_MSDU_DATA_DWORDS_COUNT_MSB                                       31
#define DEBUG_MSDU_DATA_DWORDS_COUNT_MASK                                      0xffffffff
#define DEBUG_MSDU_DATA_DWORDS_COUNT_GET(x)                                    (((x) & DEBUG_MSDU_DATA_DWORDS_COUNT_MASK) >> DEBUG_MSDU_DATA_DWORDS_COUNT_LSB)
#define DEBUG_MSDU_DATA_DWORDS_COUNT_SET(x)                                    (((0 | (x)) << DEBUG_MSDU_DATA_DWORDS_COUNT_LSB) & DEBUG_MSDU_DATA_DWORDS_COUNT_MASK)
#define DEBUG_MSDU_DATA_DWORDS_COUNT_RESET                                     0x0
#define DEBUG_MSDU_DATA_DWORDS_ADDRESS                                         (0x3c + __MAC_TXDMA_REG_BASE_ADDRESS)
#define DEBUG_MSDU_DATA_DWORDS_RSTMASK                                         0xffffffff
#define DEBUG_MSDU_DATA_DWORDS_RESET                                           0x0

// 0x40 (DEBUG_STATES_0)
#define DEBUG_STATES_0_REG_25_LSB                                              0
#define DEBUG_STATES_0_REG_25_MSB                                              24
#define DEBUG_STATES_0_REG_25_MASK                                             0x1ffffff
#define DEBUG_STATES_0_REG_25_GET(x)                                           (((x) & DEBUG_STATES_0_REG_25_MASK) >> DEBUG_STATES_0_REG_25_LSB)
#define DEBUG_STATES_0_REG_25_SET(x)                                           (((0 | (x)) << DEBUG_STATES_0_REG_25_LSB) & DEBUG_STATES_0_REG_25_MASK)
#define DEBUG_STATES_0_REG_25_RESET                                            0x8
#define DEBUG_STATES_0_ADDRESS                                                 (0x40 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define DEBUG_STATES_0_RSTMASK                                                 0x1ffffff
#define DEBUG_STATES_0_RESET                                                   0x8

// 0x44 (DEBUG_STATES_1)
#define DEBUG_STATES_1_REG_16_LSB                                              0
#define DEBUG_STATES_1_REG_16_MSB                                              15
#define DEBUG_STATES_1_REG_16_MASK                                             0xffff
#define DEBUG_STATES_1_REG_16_GET(x)                                           (((x) & DEBUG_STATES_1_REG_16_MASK) >> DEBUG_STATES_1_REG_16_LSB)
#define DEBUG_STATES_1_REG_16_SET(x)                                           (((0 | (x)) << DEBUG_STATES_1_REG_16_LSB) & DEBUG_STATES_1_REG_16_MASK)
#define DEBUG_STATES_1_REG_16_RESET                                            0x0
#define DEBUG_STATES_1_ADDRESS                                                 (0x44 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define DEBUG_STATES_1_RSTMASK                                                 0xffff
#define DEBUG_STATES_1_RESET                                                   0x0

// 0x48 (TXDMA_EVENTBUS_31_0)
#define TXDMA_EVENTBUS_31_0_MASK_LSB                                           0
#define TXDMA_EVENTBUS_31_0_MASK_MSB                                           31
#define TXDMA_EVENTBUS_31_0_MASK_MASK                                          0xffffffff
#define TXDMA_EVENTBUS_31_0_MASK_GET(x)                                        (((x) & TXDMA_EVENTBUS_31_0_MASK_MASK) >> TXDMA_EVENTBUS_31_0_MASK_LSB)
#define TXDMA_EVENTBUS_31_0_MASK_SET(x)                                        (((0 | (x)) << TXDMA_EVENTBUS_31_0_MASK_LSB) & TXDMA_EVENTBUS_31_0_MASK_MASK)
#define TXDMA_EVENTBUS_31_0_MASK_RESET                                         0xffffffff
#define TXDMA_EVENTBUS_31_0_ADDRESS                                            (0x48 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define TXDMA_EVENTBUS_31_0_RSTMASK                                            0xffffffff
#define TXDMA_EVENTBUS_31_0_RESET                                              0xffffffff

// 0x4c (TXDMA_EVENTBUS_63_32)
#define TXDMA_EVENTBUS_63_32_MASK_LSB                                          0
#define TXDMA_EVENTBUS_63_32_MASK_MSB                                          31
#define TXDMA_EVENTBUS_63_32_MASK_MASK                                         0xffffffff
#define TXDMA_EVENTBUS_63_32_MASK_GET(x)                                       (((x) & TXDMA_EVENTBUS_63_32_MASK_MASK) >> TXDMA_EVENTBUS_63_32_MASK_LSB)
#define TXDMA_EVENTBUS_63_32_MASK_SET(x)                                       (((0 | (x)) << TXDMA_EVENTBUS_63_32_MASK_LSB) & TXDMA_EVENTBUS_63_32_MASK_MASK)
#define TXDMA_EVENTBUS_63_32_MASK_RESET                                        0xffffffff
#define TXDMA_EVENTBUS_63_32_ADDRESS                                           (0x4c + __MAC_TXDMA_REG_BASE_ADDRESS)
#define TXDMA_EVENTBUS_63_32_RSTMASK                                           0xffffffff
#define TXDMA_EVENTBUS_63_32_RESET                                             0xffffffff

// 0x50 (TXDMA_ERROR_AXI_CFG)
#define TXDMA_ERROR_AXI_CFG_AXI_TIMEOUT_LIMIT_LSB                              0
#define TXDMA_ERROR_AXI_CFG_AXI_TIMEOUT_LIMIT_MSB                              15
#define TXDMA_ERROR_AXI_CFG_AXI_TIMEOUT_LIMIT_MASK                             0xffff
#define TXDMA_ERROR_AXI_CFG_AXI_TIMEOUT_LIMIT_GET(x)                           (((x) & TXDMA_ERROR_AXI_CFG_AXI_TIMEOUT_LIMIT_MASK) >> TXDMA_ERROR_AXI_CFG_AXI_TIMEOUT_LIMIT_LSB)
#define TXDMA_ERROR_AXI_CFG_AXI_TIMEOUT_LIMIT_SET(x)                           (((0 | (x)) << TXDMA_ERROR_AXI_CFG_AXI_TIMEOUT_LIMIT_LSB) & TXDMA_ERROR_AXI_CFG_AXI_TIMEOUT_LIMIT_MASK)
#define TXDMA_ERROR_AXI_CFG_AXI_TIMEOUT_LIMIT_RESET                            0xff
#define TXDMA_ERROR_AXI_CFG_ADDRESS                                            (0x50 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define TXDMA_ERROR_AXI_CFG_RSTMASK                                            0xffff
#define TXDMA_ERROR_AXI_CFG_RESET                                              0xff

// 0x54 (TXDMA_CLK_GATE_DISABLE)
#define TXDMA_CLK_GATE_DISABLE_VAL_LSB                                         0
#define TXDMA_CLK_GATE_DISABLE_VAL_MSB                                         0
#define TXDMA_CLK_GATE_DISABLE_VAL_MASK                                        0x1
#define TXDMA_CLK_GATE_DISABLE_VAL_GET(x)                                      (((x) & TXDMA_CLK_GATE_DISABLE_VAL_MASK) >> TXDMA_CLK_GATE_DISABLE_VAL_LSB)
#define TXDMA_CLK_GATE_DISABLE_VAL_SET(x)                                      (((0 | (x)) << TXDMA_CLK_GATE_DISABLE_VAL_LSB) & TXDMA_CLK_GATE_DISABLE_VAL_MASK)
#define TXDMA_CLK_GATE_DISABLE_VAL_RESET                                       0x1
#define TXDMA_CLK_GATE_DISABLE_ADDRESS                                         (0x54 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define TXDMA_CLK_GATE_DISABLE_RSTMASK                                         0x1
#define TXDMA_CLK_GATE_DISABLE_RESET                                           0x1

// 0x58 (TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST)
#define TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST_VAL_LSB                          0
#define TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST_VAL_MSB                          0
#define TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST_VAL_MASK                         0x1
#define TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST_VAL_GET(x)                       (((x) & TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST_VAL_MASK) >> TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST_VAL_LSB)
#define TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST_VAL_SET(x)                       (((0 | (x)) << TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST_VAL_LSB) & TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST_VAL_MASK)
#define TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST_VAL_RESET                        0x0
#define TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST_ADDRESS                          (0x58 + __MAC_TXDMA_REG_BASE_ADDRESS)
#define TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST_RSTMASK                          0x1
#define TXDMA_MSDU_LINK_EXT_PTR_FROM_LINKLIST_RESET                            0x0



#endif /* _MAC_TXDMA_REG_H_ */
