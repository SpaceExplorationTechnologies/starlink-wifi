/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _MAC_PDG_REG_H_
#define _MAC_PDG_REG_H_


#ifndef __MAC_PDG_REG_BASE_ADDRESS
#define __MAC_PDG_REG_BASE_ADDRESS (0x30000)
#endif


// 0x0 (PDG_FSM_STATUS)
#define PDG_FSM_STATUS_TXPCU_FSM_STATUS_LSB                                    12
#define PDG_FSM_STATUS_TXPCU_FSM_STATUS_MSB                                    17
#define PDG_FSM_STATUS_TXPCU_FSM_STATUS_MASK                                   0x3f000
#define PDG_FSM_STATUS_TXPCU_FSM_STATUS_GET(x)                                 (((x) & PDG_FSM_STATUS_TXPCU_FSM_STATUS_MASK) >> PDG_FSM_STATUS_TXPCU_FSM_STATUS_LSB)
#define PDG_FSM_STATUS_TXPCU_FSM_STATUS_SET(x)                                 (((0 | (x)) << PDG_FSM_STATUS_TXPCU_FSM_STATUS_LSB) & PDG_FSM_STATUS_TXPCU_FSM_STATUS_MASK)
#define PDG_FSM_STATUS_TXPCU_FSM_STATUS_RESET                                  0x1
#define PDG_FSM_STATUS_COMP_FSM_STATUS_LSB                                     6
#define PDG_FSM_STATUS_COMP_FSM_STATUS_MSB                                     11
#define PDG_FSM_STATUS_COMP_FSM_STATUS_MASK                                    0xfc0
#define PDG_FSM_STATUS_COMP_FSM_STATUS_GET(x)                                  (((x) & PDG_FSM_STATUS_COMP_FSM_STATUS_MASK) >> PDG_FSM_STATUS_COMP_FSM_STATUS_LSB)
#define PDG_FSM_STATUS_COMP_FSM_STATUS_SET(x)                                  (((0 | (x)) << PDG_FSM_STATUS_COMP_FSM_STATUS_LSB) & PDG_FSM_STATUS_COMP_FSM_STATUS_MASK)
#define PDG_FSM_STATUS_COMP_FSM_STATUS_RESET                                   0x1
#define PDG_FSM_STATUS_MAIN_FSM_STATUS_LSB                                     0
#define PDG_FSM_STATUS_MAIN_FSM_STATUS_MSB                                     5
#define PDG_FSM_STATUS_MAIN_FSM_STATUS_MASK                                    0x3f
#define PDG_FSM_STATUS_MAIN_FSM_STATUS_GET(x)                                  (((x) & PDG_FSM_STATUS_MAIN_FSM_STATUS_MASK) >> PDG_FSM_STATUS_MAIN_FSM_STATUS_LSB)
#define PDG_FSM_STATUS_MAIN_FSM_STATUS_SET(x)                                  (((0 | (x)) << PDG_FSM_STATUS_MAIN_FSM_STATUS_LSB) & PDG_FSM_STATUS_MAIN_FSM_STATUS_MASK)
#define PDG_FSM_STATUS_MAIN_FSM_STATUS_RESET                                   0x1
#define PDG_FSM_STATUS_ADDRESS                                                 (0x0 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_FSM_STATUS_RSTMASK                                                 0x3ffff
#define PDG_FSM_STATUS_RESET                                                   0x1041

// 0x4 (PDG_TESTBUS_LS)
#define PDG_TESTBUS_LS_TESTBUS_LSB                                             0
#define PDG_TESTBUS_LS_TESTBUS_MSB                                             31
#define PDG_TESTBUS_LS_TESTBUS_MASK                                            0xffffffff
#define PDG_TESTBUS_LS_TESTBUS_GET(x)                                          (((x) & PDG_TESTBUS_LS_TESTBUS_MASK) >> PDG_TESTBUS_LS_TESTBUS_LSB)
#define PDG_TESTBUS_LS_TESTBUS_SET(x)                                          (((0 | (x)) << PDG_TESTBUS_LS_TESTBUS_LSB) & PDG_TESTBUS_LS_TESTBUS_MASK)
#define PDG_TESTBUS_LS_TESTBUS_RESET                                           0x0
#define PDG_TESTBUS_LS_ADDRESS                                                 (0x4 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_TESTBUS_LS_RSTMASK                                                 0xffffffff
#define PDG_TESTBUS_LS_RESET                                                   0x0

// 0x8 (PDG_TESTBUS_MS)
#define PDG_TESTBUS_MS_TESTBUS_LSB                                             0
#define PDG_TESTBUS_MS_TESTBUS_MSB                                             7
#define PDG_TESTBUS_MS_TESTBUS_MASK                                            0xff
#define PDG_TESTBUS_MS_TESTBUS_GET(x)                                          (((x) & PDG_TESTBUS_MS_TESTBUS_MASK) >> PDG_TESTBUS_MS_TESTBUS_LSB)
#define PDG_TESTBUS_MS_TESTBUS_SET(x)                                          (((0 | (x)) << PDG_TESTBUS_MS_TESTBUS_LSB) & PDG_TESTBUS_MS_TESTBUS_MASK)
#define PDG_TESTBUS_MS_TESTBUS_RESET                                           0x0
#define PDG_TESTBUS_MS_ADDRESS                                                 (0x8 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_TESTBUS_MS_RSTMASK                                                 0xff
#define PDG_TESTBUS_MS_RESET                                                   0x0

// 0xc (PDG_DBG_COUNTERS)
#define PDG_DBG_COUNTERS_NUM_OF_PDG_RESPONSE_LSB                               24
#define PDG_DBG_COUNTERS_NUM_OF_PDG_RESPONSE_MSB                               31
#define PDG_DBG_COUNTERS_NUM_OF_PDG_RESPONSE_MASK                              0xff000000
#define PDG_DBG_COUNTERS_NUM_OF_PDG_RESPONSE_GET(x)                            (((x) & PDG_DBG_COUNTERS_NUM_OF_PDG_RESPONSE_MASK) >> PDG_DBG_COUNTERS_NUM_OF_PDG_RESPONSE_LSB)
#define PDG_DBG_COUNTERS_NUM_OF_PDG_RESPONSE_SET(x)                            (((0 | (x)) << PDG_DBG_COUNTERS_NUM_OF_PDG_RESPONSE_LSB) & PDG_DBG_COUNTERS_NUM_OF_PDG_RESPONSE_MASK)
#define PDG_DBG_COUNTERS_NUM_OF_PDG_RESPONSE_RESET                             0x0
#define PDG_DBG_COUNTERS_NUM_OF_PPDU_SETUP_LSB                                 16
#define PDG_DBG_COUNTERS_NUM_OF_PPDU_SETUP_MSB                                 23
#define PDG_DBG_COUNTERS_NUM_OF_PPDU_SETUP_MASK                                0xff0000
#define PDG_DBG_COUNTERS_NUM_OF_PPDU_SETUP_GET(x)                              (((x) & PDG_DBG_COUNTERS_NUM_OF_PPDU_SETUP_MASK) >> PDG_DBG_COUNTERS_NUM_OF_PPDU_SETUP_LSB)
#define PDG_DBG_COUNTERS_NUM_OF_PPDU_SETUP_SET(x)                              (((0 | (x)) << PDG_DBG_COUNTERS_NUM_OF_PPDU_SETUP_LSB) & PDG_DBG_COUNTERS_NUM_OF_PPDU_SETUP_MASK)
#define PDG_DBG_COUNTERS_NUM_OF_PPDU_SETUP_RESET                               0x0
#define PDG_DBG_COUNTERS_NUM_OF_MPDU_LENGTH_INFO_LSB                           8
#define PDG_DBG_COUNTERS_NUM_OF_MPDU_LENGTH_INFO_MSB                           15
#define PDG_DBG_COUNTERS_NUM_OF_MPDU_LENGTH_INFO_MASK                          0xff00
#define PDG_DBG_COUNTERS_NUM_OF_MPDU_LENGTH_INFO_GET(x)                        (((x) & PDG_DBG_COUNTERS_NUM_OF_MPDU_LENGTH_INFO_MASK) >> PDG_DBG_COUNTERS_NUM_OF_MPDU_LENGTH_INFO_LSB)
#define PDG_DBG_COUNTERS_NUM_OF_MPDU_LENGTH_INFO_SET(x)                        (((0 | (x)) << PDG_DBG_COUNTERS_NUM_OF_MPDU_LENGTH_INFO_LSB) & PDG_DBG_COUNTERS_NUM_OF_MPDU_LENGTH_INFO_MASK)
#define PDG_DBG_COUNTERS_NUM_OF_MPDU_LENGTH_INFO_RESET                         0x0
#define PDG_DBG_COUNTERS_NUM_OF_FES_SETUP_LSB                                  0
#define PDG_DBG_COUNTERS_NUM_OF_FES_SETUP_MSB                                  7
#define PDG_DBG_COUNTERS_NUM_OF_FES_SETUP_MASK                                 0xff
#define PDG_DBG_COUNTERS_NUM_OF_FES_SETUP_GET(x)                               (((x) & PDG_DBG_COUNTERS_NUM_OF_FES_SETUP_MASK) >> PDG_DBG_COUNTERS_NUM_OF_FES_SETUP_LSB)
#define PDG_DBG_COUNTERS_NUM_OF_FES_SETUP_SET(x)                               (((0 | (x)) << PDG_DBG_COUNTERS_NUM_OF_FES_SETUP_LSB) & PDG_DBG_COUNTERS_NUM_OF_FES_SETUP_MASK)
#define PDG_DBG_COUNTERS_NUM_OF_FES_SETUP_RESET                                0x0
#define PDG_DBG_COUNTERS_ADDRESS                                               (0xc + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_DBG_COUNTERS_RSTMASK                                               0xffffffff
#define PDG_DBG_COUNTERS_RESET                                                 0x0

// 0x10 (PDG_CONFIG)
#define PDG_CONFIG_SW_11J_11AF_EN_LSB                                          13
#define PDG_CONFIG_SW_11J_11AF_EN_MSB                                          13
#define PDG_CONFIG_SW_11J_11AF_EN_MASK                                         0x2000
#define PDG_CONFIG_SW_11J_11AF_EN_GET(x)                                       (((x) & PDG_CONFIG_SW_11J_11AF_EN_MASK) >> PDG_CONFIG_SW_11J_11AF_EN_LSB)
#define PDG_CONFIG_SW_11J_11AF_EN_SET(x)                                       (((0 | (x)) << PDG_CONFIG_SW_11J_11AF_EN_LSB) & PDG_CONFIG_SW_11J_11AF_EN_MASK)
#define PDG_CONFIG_SW_11J_11AF_EN_RESET                                        0x0
#define PDG_CONFIG_SW_11J_11AF_SCALE_FACTOR_LSB                                8
#define PDG_CONFIG_SW_11J_11AF_SCALE_FACTOR_MSB                                12
#define PDG_CONFIG_SW_11J_11AF_SCALE_FACTOR_MASK                               0x1f00
#define PDG_CONFIG_SW_11J_11AF_SCALE_FACTOR_GET(x)                             (((x) & PDG_CONFIG_SW_11J_11AF_SCALE_FACTOR_MASK) >> PDG_CONFIG_SW_11J_11AF_SCALE_FACTOR_LSB)
#define PDG_CONFIG_SW_11J_11AF_SCALE_FACTOR_SET(x)                             (((0 | (x)) << PDG_CONFIG_SW_11J_11AF_SCALE_FACTOR_LSB) & PDG_CONFIG_SW_11J_11AF_SCALE_FACTOR_MASK)
#define PDG_CONFIG_SW_11J_11AF_SCALE_FACTOR_RESET                              0x0
#define PDG_CONFIG_SW_SIFS_TIME_LSB                                            0
#define PDG_CONFIG_SW_SIFS_TIME_MSB                                            7
#define PDG_CONFIG_SW_SIFS_TIME_MASK                                           0xff
#define PDG_CONFIG_SW_SIFS_TIME_GET(x)                                         (((x) & PDG_CONFIG_SW_SIFS_TIME_MASK) >> PDG_CONFIG_SW_SIFS_TIME_LSB)
#define PDG_CONFIG_SW_SIFS_TIME_SET(x)                                         (((0 | (x)) << PDG_CONFIG_SW_SIFS_TIME_LSB) & PDG_CONFIG_SW_SIFS_TIME_MASK)
#define PDG_CONFIG_SW_SIFS_TIME_RESET                                          0x0
#define PDG_CONFIG_ADDRESS                                                     (0x10 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_CONFIG_RSTMASK                                                     0x3fff
#define PDG_CONFIG_RESET                                                       0x0

// 0x14 (PDG_SCRAMBLING_OVERIDE)
#define PDG_SCRAMBLING_OVERIDE_FORCE_SW_SHIFT_REG_WORD_LSB                     7
#define PDG_SCRAMBLING_OVERIDE_FORCE_SW_SHIFT_REG_WORD_MSB                     7
#define PDG_SCRAMBLING_OVERIDE_FORCE_SW_SHIFT_REG_WORD_MASK                    0x80
#define PDG_SCRAMBLING_OVERIDE_FORCE_SW_SHIFT_REG_WORD_GET(x)                  (((x) & PDG_SCRAMBLING_OVERIDE_FORCE_SW_SHIFT_REG_WORD_MASK) >> PDG_SCRAMBLING_OVERIDE_FORCE_SW_SHIFT_REG_WORD_LSB)
#define PDG_SCRAMBLING_OVERIDE_FORCE_SW_SHIFT_REG_WORD_SET(x)                  (((0 | (x)) << PDG_SCRAMBLING_OVERIDE_FORCE_SW_SHIFT_REG_WORD_LSB) & PDG_SCRAMBLING_OVERIDE_FORCE_SW_SHIFT_REG_WORD_MASK)
#define PDG_SCRAMBLING_OVERIDE_FORCE_SW_SHIFT_REG_WORD_RESET                   0x0
#define PDG_SCRAMBLING_OVERIDE_SCRAMBLING_SHIFT_REG_WORD_LSB                   0
#define PDG_SCRAMBLING_OVERIDE_SCRAMBLING_SHIFT_REG_WORD_MSB                   6
#define PDG_SCRAMBLING_OVERIDE_SCRAMBLING_SHIFT_REG_WORD_MASK                  0x7f
#define PDG_SCRAMBLING_OVERIDE_SCRAMBLING_SHIFT_REG_WORD_GET(x)                (((x) & PDG_SCRAMBLING_OVERIDE_SCRAMBLING_SHIFT_REG_WORD_MASK) >> PDG_SCRAMBLING_OVERIDE_SCRAMBLING_SHIFT_REG_WORD_LSB)
#define PDG_SCRAMBLING_OVERIDE_SCRAMBLING_SHIFT_REG_WORD_SET(x)                (((0 | (x)) << PDG_SCRAMBLING_OVERIDE_SCRAMBLING_SHIFT_REG_WORD_LSB) & PDG_SCRAMBLING_OVERIDE_SCRAMBLING_SHIFT_REG_WORD_MASK)
#define PDG_SCRAMBLING_OVERIDE_SCRAMBLING_SHIFT_REG_WORD_RESET                 0x0
#define PDG_SCRAMBLING_OVERIDE_ADDRESS                                         (0x14 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_SCRAMBLING_OVERIDE_RSTMASK                                         0xff
#define PDG_SCRAMBLING_OVERIDE_RESET                                           0x0

// 0x18 (PDG_RESPONSE_CHAIN_MASK)
#define PDG_RESPONSE_CHAIN_MASK_RESP_CHAIN_MASK_REG_LSB                        0
#define PDG_RESPONSE_CHAIN_MASK_RESP_CHAIN_MASK_REG_MSB                        3
#define PDG_RESPONSE_CHAIN_MASK_RESP_CHAIN_MASK_REG_MASK                       0xf
#define PDG_RESPONSE_CHAIN_MASK_RESP_CHAIN_MASK_REG_GET(x)                     (((x) & PDG_RESPONSE_CHAIN_MASK_RESP_CHAIN_MASK_REG_MASK) >> PDG_RESPONSE_CHAIN_MASK_RESP_CHAIN_MASK_REG_LSB)
#define PDG_RESPONSE_CHAIN_MASK_RESP_CHAIN_MASK_REG_SET(x)                     (((0 | (x)) << PDG_RESPONSE_CHAIN_MASK_RESP_CHAIN_MASK_REG_LSB) & PDG_RESPONSE_CHAIN_MASK_RESP_CHAIN_MASK_REG_MASK)
#define PDG_RESPONSE_CHAIN_MASK_RESP_CHAIN_MASK_REG_RESET                      0x0
#define PDG_RESPONSE_CHAIN_MASK_ADDRESS                                        (0x18 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_RESPONSE_CHAIN_MASK_RSTMASK                                        0xf
#define PDG_RESPONSE_CHAIN_MASK_RESET                                          0x0

// 0x1c (PDG_RESPONSE_PAPRD_CHAIN_MASK)
#define PDG_RESPONSE_PAPRD_CHAIN_MASK_RESP_PAPRD_CHAIN_MASK_REG_LSB            0
#define PDG_RESPONSE_PAPRD_CHAIN_MASK_RESP_PAPRD_CHAIN_MASK_REG_MSB            3
#define PDG_RESPONSE_PAPRD_CHAIN_MASK_RESP_PAPRD_CHAIN_MASK_REG_MASK           0xf
#define PDG_RESPONSE_PAPRD_CHAIN_MASK_RESP_PAPRD_CHAIN_MASK_REG_GET(x)         (((x) & PDG_RESPONSE_PAPRD_CHAIN_MASK_RESP_PAPRD_CHAIN_MASK_REG_MASK) >> PDG_RESPONSE_PAPRD_CHAIN_MASK_RESP_PAPRD_CHAIN_MASK_REG_LSB)
#define PDG_RESPONSE_PAPRD_CHAIN_MASK_RESP_PAPRD_CHAIN_MASK_REG_SET(x)         (((0 | (x)) << PDG_RESPONSE_PAPRD_CHAIN_MASK_RESP_PAPRD_CHAIN_MASK_REG_LSB) & PDG_RESPONSE_PAPRD_CHAIN_MASK_RESP_PAPRD_CHAIN_MASK_REG_MASK)
#define PDG_RESPONSE_PAPRD_CHAIN_MASK_RESP_PAPRD_CHAIN_MASK_REG_RESET          0x0
#define PDG_RESPONSE_PAPRD_CHAIN_MASK_ADDRESS                                  (0x1c + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_RESPONSE_PAPRD_CHAIN_MASK_RSTMASK                                  0xf
#define PDG_RESPONSE_PAPRD_CHAIN_MASK_RESET                                    0x0

// 0x20 (PDG_WATCHDOG)
#define PDG_WATCHDOG_STATUS_LSB                                                16
#define PDG_WATCHDOG_STATUS_MSB                                                31
#define PDG_WATCHDOG_STATUS_MASK                                               0xffff0000
#define PDG_WATCHDOG_STATUS_GET(x)                                             (((x) & PDG_WATCHDOG_STATUS_MASK) >> PDG_WATCHDOG_STATUS_LSB)
#define PDG_WATCHDOG_STATUS_SET(x)                                             (((0 | (x)) << PDG_WATCHDOG_STATUS_LSB) & PDG_WATCHDOG_STATUS_MASK)
#define PDG_WATCHDOG_STATUS_RESET                                              0x0
#define PDG_WATCHDOG_LIMIT_LSB                                                 0
#define PDG_WATCHDOG_LIMIT_MSB                                                 15
#define PDG_WATCHDOG_LIMIT_MASK                                                0xffff
#define PDG_WATCHDOG_LIMIT_GET(x)                                              (((x) & PDG_WATCHDOG_LIMIT_MASK) >> PDG_WATCHDOG_LIMIT_LSB)
#define PDG_WATCHDOG_LIMIT_SET(x)                                              (((0 | (x)) << PDG_WATCHDOG_LIMIT_LSB) & PDG_WATCHDOG_LIMIT_MASK)
#define PDG_WATCHDOG_LIMIT_RESET                                               0xffff
#define PDG_WATCHDOG_ADDRESS                                                   (0x20 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_WATCHDOG_RSTMASK                                                   0xffffffff
#define PDG_WATCHDOG_RESET                                                     0xffff

// 0x24 (PDG_DEBUG_MODULE_SELECT)
#define PDG_DEBUG_MODULE_SELECT_DEBUG_MODULE_SELECT_LSB                        0
#define PDG_DEBUG_MODULE_SELECT_DEBUG_MODULE_SELECT_MSB                        31
#define PDG_DEBUG_MODULE_SELECT_DEBUG_MODULE_SELECT_MASK                       0xffffffff
#define PDG_DEBUG_MODULE_SELECT_DEBUG_MODULE_SELECT_GET(x)                     (((x) & PDG_DEBUG_MODULE_SELECT_DEBUG_MODULE_SELECT_MASK) >> PDG_DEBUG_MODULE_SELECT_DEBUG_MODULE_SELECT_LSB)
#define PDG_DEBUG_MODULE_SELECT_DEBUG_MODULE_SELECT_SET(x)                     (((0 | (x)) << PDG_DEBUG_MODULE_SELECT_DEBUG_MODULE_SELECT_LSB) & PDG_DEBUG_MODULE_SELECT_DEBUG_MODULE_SELECT_MASK)
#define PDG_DEBUG_MODULE_SELECT_DEBUG_MODULE_SELECT_RESET                      0x0
#define PDG_DEBUG_MODULE_SELECT_ADDRESS                                        (0x24 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_DEBUG_MODULE_SELECT_RSTMASK                                        0xffffffff
#define PDG_DEBUG_MODULE_SELECT_RESET                                          0x0

// 0x2c (PDG_CLOCK_GATE_DISABLE)
#define PDG_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_LSB                          0
#define PDG_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_MSB                          6
#define PDG_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_MASK                         0x7f
#define PDG_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_GET(x)                       (((x) & PDG_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_MASK) >> PDG_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_LSB)
#define PDG_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_SET(x)                       (((0 | (x)) << PDG_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_LSB) & PDG_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_MASK)
#define PDG_CLOCK_GATE_DISABLE_CLOCK_GATE_DISABLE_RESET                        0x7f
#define PDG_CLOCK_GATE_DISABLE_ADDRESS                                         (0x2c + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_CLOCK_GATE_DISABLE_RSTMASK                                         0x7f
#define PDG_CLOCK_GATE_DISABLE_RESET                                           0x7f

// 0x40 (PDG_SLOT_TIME)
#define PDG_SLOT_TIME_PDG_SLOT_TIME_LSB                                        0
#define PDG_SLOT_TIME_PDG_SLOT_TIME_MSB                                        15
#define PDG_SLOT_TIME_PDG_SLOT_TIME_MASK                                       0xffff
#define PDG_SLOT_TIME_PDG_SLOT_TIME_GET(x)                                     (((x) & PDG_SLOT_TIME_PDG_SLOT_TIME_MASK) >> PDG_SLOT_TIME_PDG_SLOT_TIME_LSB)
#define PDG_SLOT_TIME_PDG_SLOT_TIME_SET(x)                                     (((0 | (x)) << PDG_SLOT_TIME_PDG_SLOT_TIME_LSB) & PDG_SLOT_TIME_PDG_SLOT_TIME_MASK)
#define PDG_SLOT_TIME_PDG_SLOT_TIME_RESET                                      0x0
#define PDG_SLOT_TIME_ADDRESS                                                  (0x40 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_SLOT_TIME_RSTMASK                                                  0xffff
#define PDG_SLOT_TIME_RESET                                                    0x0

// 0x44 (PDG_FEATURE_ENABLE)
#define PDG_FEATURE_ENABLE_ENABLE_MPROT_UPDATE_SCRAM_SEED_LSB                  2
#define PDG_FEATURE_ENABLE_ENABLE_MPROT_UPDATE_SCRAM_SEED_MSB                  2
#define PDG_FEATURE_ENABLE_ENABLE_MPROT_UPDATE_SCRAM_SEED_MASK                 0x4
#define PDG_FEATURE_ENABLE_ENABLE_MPROT_UPDATE_SCRAM_SEED_GET(x)               (((x) & PDG_FEATURE_ENABLE_ENABLE_MPROT_UPDATE_SCRAM_SEED_MASK) >> PDG_FEATURE_ENABLE_ENABLE_MPROT_UPDATE_SCRAM_SEED_LSB)
#define PDG_FEATURE_ENABLE_ENABLE_MPROT_UPDATE_SCRAM_SEED_SET(x)               (((0 | (x)) << PDG_FEATURE_ENABLE_ENABLE_MPROT_UPDATE_SCRAM_SEED_LSB) & PDG_FEATURE_ENABLE_ENABLE_MPROT_UPDATE_SCRAM_SEED_MASK)
#define PDG_FEATURE_ENABLE_ENABLE_MPROT_UPDATE_SCRAM_SEED_RESET                0x0
#define PDG_FEATURE_ENABLE_ENABLE_ECO_LSB                                      0
#define PDG_FEATURE_ENABLE_ENABLE_ECO_MSB                                      1
#define PDG_FEATURE_ENABLE_ENABLE_ECO_MASK                                     0x3
#define PDG_FEATURE_ENABLE_ENABLE_ECO_GET(x)                                   (((x) & PDG_FEATURE_ENABLE_ENABLE_ECO_MASK) >> PDG_FEATURE_ENABLE_ENABLE_ECO_LSB)
#define PDG_FEATURE_ENABLE_ENABLE_ECO_SET(x)                                   (((0 | (x)) << PDG_FEATURE_ENABLE_ENABLE_ECO_LSB) & PDG_FEATURE_ENABLE_ENABLE_ECO_MASK)
#define PDG_FEATURE_ENABLE_ENABLE_ECO_RESET                                    0x0
#define PDG_FEATURE_ENABLE_ADDRESS                                             (0x44 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_FEATURE_ENABLE_RSTMASK                                             0x7
#define PDG_FEATURE_ENABLE_RESET                                               0x0

// 0x48 (PDG_MCP)
#define PDG_MCP_BIT_FOR_COMP_ENG_MCP_LSB                                       8
#define PDG_MCP_BIT_FOR_COMP_ENG_MCP_MSB                                       15
#define PDG_MCP_BIT_FOR_COMP_ENG_MCP_MASK                                      0xff00
#define PDG_MCP_BIT_FOR_COMP_ENG_MCP_GET(x)                                    (((x) & PDG_MCP_BIT_FOR_COMP_ENG_MCP_MASK) >> PDG_MCP_BIT_FOR_COMP_ENG_MCP_LSB)
#define PDG_MCP_BIT_FOR_COMP_ENG_MCP_SET(x)                                    (((0 | (x)) << PDG_MCP_BIT_FOR_COMP_ENG_MCP_LSB) & PDG_MCP_BIT_FOR_COMP_ENG_MCP_MASK)
#define PDG_MCP_BIT_FOR_COMP_ENG_MCP_RESET                                     0x10
#define PDG_MCP_BIT_FOR_COMP_ENG_NSYM_MCP_LSB                                  0
#define PDG_MCP_BIT_FOR_COMP_ENG_NSYM_MCP_MSB                                  7
#define PDG_MCP_BIT_FOR_COMP_ENG_NSYM_MCP_MASK                                 0xff
#define PDG_MCP_BIT_FOR_COMP_ENG_NSYM_MCP_GET(x)                               (((x) & PDG_MCP_BIT_FOR_COMP_ENG_NSYM_MCP_MASK) >> PDG_MCP_BIT_FOR_COMP_ENG_NSYM_MCP_LSB)
#define PDG_MCP_BIT_FOR_COMP_ENG_NSYM_MCP_SET(x)                               (((0 | (x)) << PDG_MCP_BIT_FOR_COMP_ENG_NSYM_MCP_LSB) & PDG_MCP_BIT_FOR_COMP_ENG_NSYM_MCP_MASK)
#define PDG_MCP_BIT_FOR_COMP_ENG_NSYM_MCP_RESET                                0x10
#define PDG_MCP_ADDRESS                                                        (0x48 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_MCP_RSTMASK                                                        0xffff
#define PDG_MCP_RESET                                                          0x1010

// 0x4c (PDG_EVENT_DEBUG_SELECT1)
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_22_24_26_LSB                      20
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_22_24_26_MSB                      24
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_22_24_26_MASK                     0x1f00000
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_22_24_26_GET(x)                   (((x) & PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_22_24_26_MASK) >> PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_22_24_26_LSB)
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_22_24_26_SET(x)                   (((0 | (x)) << PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_22_24_26_LSB) & PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_22_24_26_MASK)
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_22_24_26_RESET                    0x0
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_21_23_25_LSB                      15
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_21_23_25_MSB                      19
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_21_23_25_MASK                     0xf8000
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_21_23_25_GET(x)                   (((x) & PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_21_23_25_MASK) >> PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_21_23_25_LSB)
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_21_23_25_SET(x)                   (((0 | (x)) << PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_21_23_25_LSB) & PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_21_23_25_MASK)
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_21_23_25_RESET                    0x0
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_10TO20_LSB                        10
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_10TO20_MSB                        14
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_10TO20_MASK                       0x7c00
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_10TO20_GET(x)                     (((x) & PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_10TO20_MASK) >> PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_10TO20_LSB)
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_10TO20_SET(x)                     (((0 | (x)) << PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_10TO20_LSB) & PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_10TO20_MASK)
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_10TO20_RESET                      0x0
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_8_LSB                             5
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_8_MSB                             9
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_8_MASK                            0x3e0
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_8_GET(x)                          (((x) & PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_8_MASK) >> PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_8_LSB)
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_8_SET(x)                          (((0 | (x)) << PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_8_LSB) & PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_8_MASK)
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_8_RESET                           0x0
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_7_LSB                             0
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_7_MSB                             4
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_7_MASK                            0x1f
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_7_GET(x)                          (((x) & PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_7_MASK) >> PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_7_LSB)
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_7_SET(x)                          (((0 | (x)) << PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_7_LSB) & PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_7_MASK)
#define PDG_EVENT_DEBUG_SELECT1_EVENT_SELECT_7_RESET                           0x0
#define PDG_EVENT_DEBUG_SELECT1_ADDRESS                                        (0x4c + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_EVENT_DEBUG_SELECT1_RSTMASK                                        0x1ffffff
#define PDG_EVENT_DEBUG_SELECT1_RESET                                          0x0

// 0x50 (PDG_EVENT_DEBUG_SELECT2)
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_31_LSB                            15
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_31_MSB                            19
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_31_MASK                           0xf8000
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_31_GET(x)                         (((x) & PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_31_MASK) >> PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_31_LSB)
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_31_SET(x)                         (((0 | (x)) << PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_31_LSB) & PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_31_MASK)
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_31_RESET                          0x0
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_30_LSB                            10
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_30_MSB                            14
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_30_MASK                           0x7c00
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_30_GET(x)                         (((x) & PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_30_MASK) >> PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_30_LSB)
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_30_SET(x)                         (((0 | (x)) << PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_30_LSB) & PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_30_MASK)
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_30_RESET                          0x0
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_29_LSB                            5
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_29_MSB                            9
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_29_MASK                           0x3e0
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_29_GET(x)                         (((x) & PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_29_MASK) >> PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_29_LSB)
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_29_SET(x)                         (((0 | (x)) << PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_29_LSB) & PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_29_MASK)
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_29_RESET                          0x0
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_28_LSB                            0
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_28_MSB                            4
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_28_MASK                           0x1f
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_28_GET(x)                         (((x) & PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_28_MASK) >> PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_28_LSB)
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_28_SET(x)                         (((0 | (x)) << PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_28_LSB) & PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_28_MASK)
#define PDG_EVENT_DEBUG_SELECT2_EVENT_SELECT_28_RESET                          0x0
#define PDG_EVENT_DEBUG_SELECT2_ADDRESS                                        (0x50 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_EVENT_DEBUG_SELECT2_RSTMASK                                        0xfffff
#define PDG_EVENT_DEBUG_SELECT2_RESET                                          0x0

// 0x54 (PDG_EVENT_DEBUG_SELECT3)
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_36_LSB                            20
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_36_MSB                            24
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_36_MASK                           0x1f00000
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_36_GET(x)                         (((x) & PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_36_MASK) >> PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_36_LSB)
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_36_SET(x)                         (((0 | (x)) << PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_36_LSB) & PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_36_MASK)
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_36_RESET                          0x0
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_35_LSB                            15
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_35_MSB                            19
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_35_MASK                           0xf8000
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_35_GET(x)                         (((x) & PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_35_MASK) >> PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_35_LSB)
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_35_SET(x)                         (((0 | (x)) << PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_35_LSB) & PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_35_MASK)
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_35_RESET                          0x0
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_34_LSB                            10
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_34_MSB                            14
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_34_MASK                           0x7c00
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_34_GET(x)                         (((x) & PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_34_MASK) >> PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_34_LSB)
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_34_SET(x)                         (((0 | (x)) << PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_34_LSB) & PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_34_MASK)
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_34_RESET                          0x0
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_33_LSB                            5
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_33_MSB                            9
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_33_MASK                           0x3e0
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_33_GET(x)                         (((x) & PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_33_MASK) >> PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_33_LSB)
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_33_SET(x)                         (((0 | (x)) << PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_33_LSB) & PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_33_MASK)
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_33_RESET                          0x0
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_32_LSB                            0
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_32_MSB                            4
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_32_MASK                           0x1f
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_32_GET(x)                         (((x) & PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_32_MASK) >> PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_32_LSB)
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_32_SET(x)                         (((0 | (x)) << PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_32_LSB) & PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_32_MASK)
#define PDG_EVENT_DEBUG_SELECT3_EVENT_SELECT_32_RESET                          0x0
#define PDG_EVENT_DEBUG_SELECT3_ADDRESS                                        (0x54 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_EVENT_DEBUG_SELECT3_RSTMASK                                        0x1ffffff
#define PDG_EVENT_DEBUG_SELECT3_RESET                                          0x0

// 0x58 (PDG_EVENT_MASK_31_0)
#define PDG_EVENT_MASK_31_0_EVENT_MASK_LSB                                     0
#define PDG_EVENT_MASK_31_0_EVENT_MASK_MSB                                     31
#define PDG_EVENT_MASK_31_0_EVENT_MASK_MASK                                    0xffffffff
#define PDG_EVENT_MASK_31_0_EVENT_MASK_GET(x)                                  (((x) & PDG_EVENT_MASK_31_0_EVENT_MASK_MASK) >> PDG_EVENT_MASK_31_0_EVENT_MASK_LSB)
#define PDG_EVENT_MASK_31_0_EVENT_MASK_SET(x)                                  (((0 | (x)) << PDG_EVENT_MASK_31_0_EVENT_MASK_LSB) & PDG_EVENT_MASK_31_0_EVENT_MASK_MASK)
#define PDG_EVENT_MASK_31_0_EVENT_MASK_RESET                                   0x0
#define PDG_EVENT_MASK_31_0_ADDRESS                                            (0x58 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_EVENT_MASK_31_0_RSTMASK                                            0xffffffff
#define PDG_EVENT_MASK_31_0_RESET                                              0x0

// 0x5c (PDG_EVENT_MASK_64_32)
#define PDG_EVENT_MASK_64_32_EVENT_MASK_LSB                                    0
#define PDG_EVENT_MASK_64_32_EVENT_MASK_MSB                                    5
#define PDG_EVENT_MASK_64_32_EVENT_MASK_MASK                                   0x3f
#define PDG_EVENT_MASK_64_32_EVENT_MASK_GET(x)                                 (((x) & PDG_EVENT_MASK_64_32_EVENT_MASK_MASK) >> PDG_EVENT_MASK_64_32_EVENT_MASK_LSB)
#define PDG_EVENT_MASK_64_32_EVENT_MASK_SET(x)                                 (((0 | (x)) << PDG_EVENT_MASK_64_32_EVENT_MASK_LSB) & PDG_EVENT_MASK_64_32_EVENT_MASK_MASK)
#define PDG_EVENT_MASK_64_32_EVENT_MASK_RESET                                  0x0
#define PDG_EVENT_MASK_64_32_ADDRESS                                           (0x5c + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_EVENT_MASK_64_32_RSTMASK                                           0x3f
#define PDG_EVENT_MASK_64_32_RESET                                             0x0

// 0x60 (PDG_OFDM_11A_PKT_PHY_LIMIT)
#define PDG_OFDM_11A_PKT_PHY_LIMIT_OFDM_11A_TIME_LIMIT_LSB                     0
#define PDG_OFDM_11A_PKT_PHY_LIMIT_OFDM_11A_TIME_LIMIT_MSB                     15
#define PDG_OFDM_11A_PKT_PHY_LIMIT_OFDM_11A_TIME_LIMIT_MASK                    0xffff
#define PDG_OFDM_11A_PKT_PHY_LIMIT_OFDM_11A_TIME_LIMIT_GET(x)                  (((x) & PDG_OFDM_11A_PKT_PHY_LIMIT_OFDM_11A_TIME_LIMIT_MASK) >> PDG_OFDM_11A_PKT_PHY_LIMIT_OFDM_11A_TIME_LIMIT_LSB)
#define PDG_OFDM_11A_PKT_PHY_LIMIT_OFDM_11A_TIME_LIMIT_SET(x)                  (((0 | (x)) << PDG_OFDM_11A_PKT_PHY_LIMIT_OFDM_11A_TIME_LIMIT_LSB) & PDG_OFDM_11A_PKT_PHY_LIMIT_OFDM_11A_TIME_LIMIT_MASK)
#define PDG_OFDM_11A_PKT_PHY_LIMIT_OFDM_11A_TIME_LIMIT_RESET                   0xc1c
#define PDG_OFDM_11A_PKT_PHY_LIMIT_ADDRESS                                     (0x60 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_OFDM_11A_PKT_PHY_LIMIT_RSTMASK                                     0xffff
#define PDG_OFDM_11A_PKT_PHY_LIMIT_RESET                                       0xc1c

// 0x64 (PDG_OFDM_11NAC_PKT_PHY_LIMIT)
#define PDG_OFDM_11NAC_PKT_PHY_LIMIT_OFDM_11NAC_TIME_LIMIT_LSB                 0
#define PDG_OFDM_11NAC_PKT_PHY_LIMIT_OFDM_11NAC_TIME_LIMIT_MSB                 15
#define PDG_OFDM_11NAC_PKT_PHY_LIMIT_OFDM_11NAC_TIME_LIMIT_MASK                0xffff
#define PDG_OFDM_11NAC_PKT_PHY_LIMIT_OFDM_11NAC_TIME_LIMIT_GET(x)              (((x) & PDG_OFDM_11NAC_PKT_PHY_LIMIT_OFDM_11NAC_TIME_LIMIT_MASK) >> PDG_OFDM_11NAC_PKT_PHY_LIMIT_OFDM_11NAC_TIME_LIMIT_LSB)
#define PDG_OFDM_11NAC_PKT_PHY_LIMIT_OFDM_11NAC_TIME_LIMIT_SET(x)              (((0 | (x)) << PDG_OFDM_11NAC_PKT_PHY_LIMIT_OFDM_11NAC_TIME_LIMIT_LSB) & PDG_OFDM_11NAC_PKT_PHY_LIMIT_OFDM_11NAC_TIME_LIMIT_MASK)
#define PDG_OFDM_11NAC_PKT_PHY_LIMIT_OFDM_11NAC_TIME_LIMIT_RESET               0x156c
#define PDG_OFDM_11NAC_PKT_PHY_LIMIT_ADDRESS                                   (0x64 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_OFDM_11NAC_PKT_PHY_LIMIT_RSTMASK                                   0xffff
#define PDG_OFDM_11NAC_PKT_PHY_LIMIT_RESET                                     0x156c

// 0x68 (PDG_CBF_RESPONSE_PHY_DESC_CFG)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB                         13
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MSB                         19
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK                        0xfe000
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_GET(x)                      (((x) & PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK) >> PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_SET(x)                      (((0 | (x)) << PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB) & PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_RESET                       0x3f
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB                        12
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MSB                        12
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK                       0x1000
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_GET(x)                     (((x) & PDG_CBF_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK) >> PDG_CBF_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_SET(x)                     (((0 | (x)) << PDG_CBF_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB) & PDG_CBF_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_RESET                      0x0
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB                          11
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MSB                          11
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK                         0x800
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_GET(x)                       (((x) & PDG_CBF_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK) >> PDG_CBF_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_SET(x)                       (((0 | (x)) << PDG_CBF_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB) & PDG_CBF_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_RESET                        0x0
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB                               4
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_MSB                               10
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK                              0x7f0
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_GET(x)                            (((x) & PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK) >> PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_SET(x)                            (((0 | (x)) << PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB) & PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TX_PWR_RESET                             0x3f
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB                           3
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MSB                           3
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK                          0x8
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_GET(x)                        (((x) & PDG_CBF_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK) >> PDG_CBF_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_SET(x)                        (((0 | (x)) << PDG_CBF_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB) & PDG_CBF_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_RESET                         0x0
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB                     0
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MSB                     2
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK                    0x7
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_GET(x)                  (((x) & PDG_CBF_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK) >> PDG_CBF_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_SET(x)                  (((0 | (x)) << PDG_CBF_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB) & PDG_CBF_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_RESET                   0x0
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_ADDRESS                                  (0x68 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_RSTMASK                                  0xfffff
#define PDG_CBF_RESPONSE_PHY_DESC_CFG_RESET                                    0x7e3f0

// 0x6c (PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB                   13
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MSB                   19
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK                  0xfe000
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_GET(x)                (((x) & PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK) >> PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_SET(x)                (((0 | (x)) << PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB) & PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_RESET                 0x3f
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB                  12
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MSB                  12
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK                 0x1000
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_GET(x)               (((x) & PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK) >> PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_SET(x)               (((0 | (x)) << PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB) & PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_RESET                0x0
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB                    11
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MSB                    11
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK                   0x800
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_GET(x)                 (((x) & PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK) >> PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_SET(x)                 (((0 | (x)) << PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB) & PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_RESET                  0x0
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB                         4
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_MSB                         10
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK                        0x7f0
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_GET(x)                      (((x) & PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK) >> PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_SET(x)                      (((0 | (x)) << PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB) & PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TX_PWR_RESET                       0x3f
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB                     3
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MSB                     3
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK                    0x8
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_GET(x)                  (((x) & PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK) >> PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_SET(x)                  (((0 | (x)) << PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB) & PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_RESET                   0x0
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB               0
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MSB               2
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK              0x7
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_GET(x)            (((x) & PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK) >> PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_SET(x)            (((0 | (x)) << PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB) & PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_RESET             0x0
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_ADDRESS                            (0x6c + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_RSTMASK                            0xfffff
#define PDG_RTT_HTVHT_RESPONSE_PHY_DESC_CFG_RESET                              0x7e3f0

// 0x70 (PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB                  13
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MSB                  19
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK                 0xfe000
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_GET(x)               (((x) & PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK) >> PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_SET(x)               (((0 | (x)) << PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB) & PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_RESET                0x3f
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB                 12
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MSB                 12
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK                0x1000
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_GET(x)              (((x) & PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK) >> PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_SET(x)              (((0 | (x)) << PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB) & PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_RESET               0x0
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB                   11
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MSB                   11
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK                  0x800
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_GET(x)                (((x) & PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK) >> PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_SET(x)                (((0 | (x)) << PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB) & PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_RESET                 0x0
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB                        4
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_MSB                        10
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK                       0x7f0
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_GET(x)                     (((x) & PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK) >> PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_SET(x)                     (((0 | (x)) << PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB) & PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TX_PWR_RESET                      0x3f
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB                    3
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MSB                    3
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK                   0x8
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_GET(x)                 (((x) & PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK) >> PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_SET(x)                 (((0 | (x)) << PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB) & PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_RESET                  0x0
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB              0
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MSB              2
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK             0x7
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_GET(x)           (((x) & PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK) >> PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_SET(x)           (((0 | (x)) << PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB) & PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_RESET            0x0
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_ADDRESS                           (0x70 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_RSTMASK                           0xfffff
#define PDG_RTT_LEGACY_RESPONSE_PHY_DESC_CFG_RESET                             0x7e3f0

// 0x74 (PDG_OFDM_RESPONSE_PHY_DESC_CFG)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB                        13
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MSB                        19
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK                       0xfe000
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_GET(x)                     (((x) & PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK) >> PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_SET(x)                     (((0 | (x)) << PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB) & PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_RESET                      0x3f
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB                       12
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MSB                       12
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK                      0x1000
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_GET(x)                    (((x) & PDG_OFDM_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK) >> PDG_OFDM_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_SET(x)                    (((0 | (x)) << PDG_OFDM_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB) & PDG_OFDM_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_RESET                     0x0
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB                         11
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MSB                         11
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK                        0x800
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_GET(x)                      (((x) & PDG_OFDM_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK) >> PDG_OFDM_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_SET(x)                      (((0 | (x)) << PDG_OFDM_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB) & PDG_OFDM_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_RESET                       0x0
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB                              4
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_MSB                              10
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK                             0x7f0
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_GET(x)                           (((x) & PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK) >> PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_SET(x)                           (((0 | (x)) << PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB) & PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TX_PWR_RESET                            0x3f
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB                          3
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MSB                          3
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK                         0x8
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_GET(x)                       (((x) & PDG_OFDM_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK) >> PDG_OFDM_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_SET(x)                       (((0 | (x)) << PDG_OFDM_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB) & PDG_OFDM_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_RESET                        0x0
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB                    0
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MSB                    2
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK                   0x7
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_GET(x)                 (((x) & PDG_OFDM_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK) >> PDG_OFDM_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_SET(x)                 (((0 | (x)) << PDG_OFDM_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB) & PDG_OFDM_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_RESET                  0x0
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_ADDRESS                                 (0x74 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_RSTMASK                                 0xfffff
#define PDG_OFDM_RESPONSE_PHY_DESC_CFG_RESET                                   0x7e3f0

// 0x78 (PDG_CCK_RESPONSE_PHY_DESC_CFG)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB                         13
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MSB                         19
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK                        0xfe000
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_GET(x)                      (((x) & PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK) >> PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_SET(x)                      (((0 | (x)) << PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_LSB) & PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_MASK)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_SEC80_RESET                       0x3f
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB                        12
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MSB                        12
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK                       0x1000
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_GET(x)                     (((x) & PDG_CCK_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK) >> PDG_CCK_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_SET(x)                     (((0 | (x)) << PDG_CCK_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_LSB) & PDG_CCK_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_MASK)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_MEASURE_POWER_RESET                      0x0
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB                          11
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MSB                          11
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK                         0x800
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_GET(x)                       (((x) & PDG_CCK_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK) >> PDG_CCK_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_SET(x)                       (((0 | (x)) << PDG_CCK_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_LSB) & PDG_CCK_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_MASK)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_CLPC_ENABLE_RESET                        0x0
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB                               4
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_MSB                               10
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK                              0x7f0
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_GET(x)                            (((x) & PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK) >> PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_SET(x)                            (((0 | (x)) << PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_LSB) & PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_MASK)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TX_PWR_RESET                             0x3f
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB                           3
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MSB                           3
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK                          0x8
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_GET(x)                        (((x) & PDG_CCK_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK) >> PDG_CCK_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_SET(x)                        (((0 | (x)) << PDG_CCK_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_LSB) & PDG_CCK_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_MASK)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_DPD_ENABLE_RESET                         0x0
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB                     0
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MSB                     2
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK                    0x7
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_GET(x)                  (((x) & PDG_CCK_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK) >> PDG_CCK_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_SET(x)                  (((0 | (x)) << PDG_CCK_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_LSB) & PDG_CCK_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_MASK)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_TPC_INIT_PWR_CFG_RESET                   0x0
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_ADDRESS                                  (0x78 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_RSTMASK                                  0xfffff
#define PDG_CCK_RESPONSE_PHY_DESC_CFG_RESET                                    0x7e3f0

// 0x7c (PDG_RESPONSE_RTT_CHAIN_MASK)
#define PDG_RESPONSE_RTT_CHAIN_MASK_RESP_RTT_CHAIN_MASK_REG_LSB                0
#define PDG_RESPONSE_RTT_CHAIN_MASK_RESP_RTT_CHAIN_MASK_REG_MSB                3
#define PDG_RESPONSE_RTT_CHAIN_MASK_RESP_RTT_CHAIN_MASK_REG_MASK               0xf
#define PDG_RESPONSE_RTT_CHAIN_MASK_RESP_RTT_CHAIN_MASK_REG_GET(x)             (((x) & PDG_RESPONSE_RTT_CHAIN_MASK_RESP_RTT_CHAIN_MASK_REG_MASK) >> PDG_RESPONSE_RTT_CHAIN_MASK_RESP_RTT_CHAIN_MASK_REG_LSB)
#define PDG_RESPONSE_RTT_CHAIN_MASK_RESP_RTT_CHAIN_MASK_REG_SET(x)             (((0 | (x)) << PDG_RESPONSE_RTT_CHAIN_MASK_RESP_RTT_CHAIN_MASK_REG_LSB) & PDG_RESPONSE_RTT_CHAIN_MASK_RESP_RTT_CHAIN_MASK_REG_MASK)
#define PDG_RESPONSE_RTT_CHAIN_MASK_RESP_RTT_CHAIN_MASK_REG_RESET              0x0
#define PDG_RESPONSE_RTT_CHAIN_MASK_ADDRESS                                    (0x7c + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_RESPONSE_RTT_CHAIN_MASK_RSTMASK                                    0xf
#define PDG_RESPONSE_RTT_CHAIN_MASK_RESET                                      0x0

// 0x80 (PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK)
#define PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK_RESP_PAPRD_RTT_CHAIN_MASK_REG_LSB    0
#define PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK_RESP_PAPRD_RTT_CHAIN_MASK_REG_MSB    3
#define PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK_RESP_PAPRD_RTT_CHAIN_MASK_REG_MASK   0xf
#define PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK_RESP_PAPRD_RTT_CHAIN_MASK_REG_GET(x) (((x) & PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK_RESP_PAPRD_RTT_CHAIN_MASK_REG_MASK) >> PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK_RESP_PAPRD_RTT_CHAIN_MASK_REG_LSB)
#define PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK_RESP_PAPRD_RTT_CHAIN_MASK_REG_SET(x) (((0 | (x)) << PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK_RESP_PAPRD_RTT_CHAIN_MASK_REG_LSB) & PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK_RESP_PAPRD_RTT_CHAIN_MASK_REG_MASK)
#define PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK_RESP_PAPRD_RTT_CHAIN_MASK_REG_RESET  0x0
#define PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK_ADDRESS                              (0x80 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK_RSTMASK                              0xf
#define PDG_RESPONSE_PAPRD_RTT_CHAIN_MASK_RESET                                0x0

// 0x84 (PDG_CCK_PKT_PHY_LIMIT)
#define PDG_CCK_PKT_PHY_LIMIT_CCK_TIME_LIMIT_LSB                               0
#define PDG_CCK_PKT_PHY_LIMIT_CCK_TIME_LIMIT_MSB                               15
#define PDG_CCK_PKT_PHY_LIMIT_CCK_TIME_LIMIT_MASK                              0xffff
#define PDG_CCK_PKT_PHY_LIMIT_CCK_TIME_LIMIT_GET(x)                            (((x) & PDG_CCK_PKT_PHY_LIMIT_CCK_TIME_LIMIT_MASK) >> PDG_CCK_PKT_PHY_LIMIT_CCK_TIME_LIMIT_LSB)
#define PDG_CCK_PKT_PHY_LIMIT_CCK_TIME_LIMIT_SET(x)                            (((0 | (x)) << PDG_CCK_PKT_PHY_LIMIT_CCK_TIME_LIMIT_LSB) & PDG_CCK_PKT_PHY_LIMIT_CCK_TIME_LIMIT_MASK)
#define PDG_CCK_PKT_PHY_LIMIT_CCK_TIME_LIMIT_RESET                             0x48c0
#define PDG_CCK_PKT_PHY_LIMIT_ADDRESS                                          (0x84 + __MAC_PDG_REG_BASE_ADDRESS)
#define PDG_CCK_PKT_PHY_LIMIT_RSTMASK                                          0xffff
#define PDG_CCK_PKT_PHY_LIMIT_RESET                                            0x48c0



#endif /* _MAC_PDG_REG_H_ */
