// ------------------------------------------------------------------
// Copyright (c) 2004-2012 Qualcomm Atheros.  All rights reserved.
// $ATH_LICENSE_TARGET_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Qualcomm Atheros"
//===================================================================



#ifndef _EMULATION_MISC_REGS_H_
#define _EMULATION_MISC_REGS_H_


/* macros for FPGA_PHY_LAYER_REVID */
#define FPGA_PHY_LAYER_REVID_ADDRESS                                                      0x00000000
#define FPGA_PHY_LAYER_REVID_OFFSET                                                       0x00000000
#define FPGA_PHY_LAYER_REVID_FPGA_RADIO_FEATURE_INDEX_MSB                                         15
#define FPGA_PHY_LAYER_REVID_FPGA_RADIO_FEATURE_INDEX_LSB                                          0
#define FPGA_PHY_LAYER_REVID_FPGA_RADIO_FEATURE_INDEX_MASK                                0x0000ffff
#define FPGA_PHY_LAYER_REVID_FPGA_RADIO_FEATURE_INDEX_GET(x)               (((x) & 0x0000ffff) >> 0)
#define FPGA_PHY_LAYER_REVID_FPGA_BASEBAND_FEATURE_INDEX_MSB                                      31
#define FPGA_PHY_LAYER_REVID_FPGA_BASEBAND_FEATURE_INDEX_LSB                                      16
#define FPGA_PHY_LAYER_REVID_FPGA_BASEBAND_FEATURE_INDEX_MASK                             0xffff0000
#define FPGA_PHY_LAYER_REVID_FPGA_BASEBAND_FEATURE_INDEX_GET(x)           (((x) & 0xffff0000) >> 16)

/* macros for FPGA_LINK_LAYER_REVID */
#define FPGA_LINK_LAYER_REVID_ADDRESS                                                     0x00000004
#define FPGA_LINK_LAYER_REVID_OFFSET                                                      0x00000004
#define FPGA_LINK_LAYER_REVID_FPGA_MAC_FEATURE_INDEX_MSB                                          15
#define FPGA_LINK_LAYER_REVID_FPGA_MAC_FEATURE_INDEX_LSB                                           0
#define FPGA_LINK_LAYER_REVID_FPGA_MAC_FEATURE_INDEX_MASK                                 0x0000ffff
#define FPGA_LINK_LAYER_REVID_FPGA_MAC_FEATURE_INDEX_GET(x)                (((x) & 0x0000ffff) >> 0)
#define FPGA_LINK_LAYER_REVID_FPGA_SOC_FEATURE_INDEX_MSB                                          31
#define FPGA_LINK_LAYER_REVID_FPGA_SOC_FEATURE_INDEX_LSB                                          16
#define FPGA_LINK_LAYER_REVID_FPGA_SOC_FEATURE_INDEX_MASK                                 0xffff0000
#define FPGA_LINK_LAYER_REVID_FPGA_SOC_FEATURE_INDEX_GET(x)               (((x) & 0xffff0000) >> 16)

/* macros for FPGA_REG1 */
#define FPGA_REG1_ADDRESS                                                                 0x00000008
#define FPGA_REG1_OFFSET                                                                  0x00000008
#define FPGA_REG1_SPARE_REG1_BIT0_MSB                                                              0
#define FPGA_REG1_SPARE_REG1_BIT0_LSB                                                              0
#define FPGA_REG1_SPARE_REG1_BIT0_MASK                                                    0x00000001
#define FPGA_REG1_SPARE_REG1_BIT0_GET(x)                                   (((x) & 0x00000001) >> 0)
#define FPGA_REG1_SPARE_REG1_BIT0_SET(x)                                   (((x) << 0) & 0x00000001)
#define FPGA_REG1_MASK_RX_RF_MSB                                                                   1
#define FPGA_REG1_MASK_RX_RF_LSB                                                                   1
#define FPGA_REG1_MASK_RX_RF_MASK                                                         0x00000002
#define FPGA_REG1_MASK_RX_RF_GET(x)                                        (((x) & 0x00000002) >> 1)
#define FPGA_REG1_MASK_RX_RF_SET(x)                                        (((x) << 1) & 0x00000002)
#define FPGA_REG1_DCM_RELEASE_MSB                                                                  2
#define FPGA_REG1_DCM_RELEASE_LSB                                                                  2
#define FPGA_REG1_DCM_RELEASE_MASK                                                        0x00000004
#define FPGA_REG1_DCM_RELEASE_GET(x)                                       (((x) & 0x00000004) >> 2)
#define FPGA_REG1_SPARE0_MSB                                                                       3
#define FPGA_REG1_SPARE0_LSB                                                                       3
#define FPGA_REG1_SPARE0_MASK                                                             0x00000008
#define FPGA_REG1_SPARE0_GET(x)                                            (((x) & 0x00000008) >> 3)
#define FPGA_REG1_SPARE0_SET(x)                                            (((x) << 3) & 0x00000008)
#define FPGA_REG1_EMULATION_CLOCK_RATIO_MSB                                                        7
#define FPGA_REG1_EMULATION_CLOCK_RATIO_LSB                                                        4
#define FPGA_REG1_EMULATION_CLOCK_RATIO_MASK                                              0x000000f0
#define FPGA_REG1_EMULATION_CLOCK_RATIO_GET(x)                             (((x) & 0x000000f0) >> 4)
#define FPGA_REG1_EMULATION_CLOCK_RATIO_SET(x)                             (((x) << 4) & 0x000000f0)
#define FPGA_REG1_LONG_SHIFT_CHAIN_OVERRIDE_INDEX_MSB                                              9
#define FPGA_REG1_LONG_SHIFT_CHAIN_OVERRIDE_INDEX_LSB                                              8
#define FPGA_REG1_LONG_SHIFT_CHAIN_OVERRIDE_INDEX_MASK                                    0x00000300
#define FPGA_REG1_LONG_SHIFT_CHAIN_OVERRIDE_INDEX_GET(x)                   (((x) & 0x00000300) >> 8)
#define FPGA_REG1_LONG_SHIFT_CHAIN_OVERRIDE_INDEX_SET(x)                   (((x) << 8) & 0x00000300)
#define FPGA_REG1_ENABLE_LONG_SHIFT_CHAIN_OVERRIDE_INDEX_MSB                                      10
#define FPGA_REG1_ENABLE_LONG_SHIFT_CHAIN_OVERRIDE_INDEX_LSB                                      10
#define FPGA_REG1_ENABLE_LONG_SHIFT_CHAIN_OVERRIDE_INDEX_MASK                             0x00000400
#define FPGA_REG1_ENABLE_LONG_SHIFT_CHAIN_OVERRIDE_INDEX_GET(x)           (((x) & 0x00000400) >> 10)
#define FPGA_REG1_ENABLE_LONG_SHIFT_CHAIN_OVERRIDE_INDEX_SET(x)           (((x) << 10) & 0x00000400)
#define FPGA_REG1_LONG_SHIFT_DRIVE_PHASE_MSB                                                      15
#define FPGA_REG1_LONG_SHIFT_DRIVE_PHASE_LSB                                                      11
#define FPGA_REG1_LONG_SHIFT_DRIVE_PHASE_MASK                                             0x0000f800
#define FPGA_REG1_LONG_SHIFT_DRIVE_PHASE_GET(x)                           (((x) & 0x0000f800) >> 11)
#define FPGA_REG1_LONG_SHIFT_DRIVE_PHASE_SET(x)                           (((x) << 11) & 0x0000f800)
#define FPGA_REG1_LONG_SHIFT_SAMPLE_PHASE_MSB                                                     20
#define FPGA_REG1_LONG_SHIFT_SAMPLE_PHASE_LSB                                                     16
#define FPGA_REG1_LONG_SHIFT_SAMPLE_PHASE_MASK                                            0x001f0000
#define FPGA_REG1_LONG_SHIFT_SAMPLE_PHASE_GET(x)                          (((x) & 0x001f0000) >> 16)
#define FPGA_REG1_LONG_SHIFT_SAMPLE_PHASE_SET(x)                          (((x) << 16) & 0x001f0000)
#define FPGA_REG1_SPARE1_MSB                                                                      31
#define FPGA_REG1_SPARE1_LSB                                                                      21
#define FPGA_REG1_SPARE1_MASK                                                             0xffe00000
#define FPGA_REG1_SPARE1_GET(x)                                           (((x) & 0xffe00000) >> 21)
#define FPGA_REG1_SPARE1_SET(x)                                           (((x) << 21) & 0xffe00000)

/* macros for FPGA_REG2 */
#define FPGA_REG2_ADDRESS                                                                 0x0000000c
#define FPGA_REG2_OFFSET                                                                  0x0000000c
#define FPGA_REG2_RXPIPEIFERRINJEN_MSB                                                             0
#define FPGA_REG2_RXPIPEIFERRINJEN_LSB                                                             0
#define FPGA_REG2_RXPIPEIFERRINJEN_MASK                                                   0x00000001
#define FPGA_REG2_RXPIPEIFERRINJEN_GET(x)                                  (((x) & 0x00000001) >> 0)
#define FPGA_REG2_RXPIPEIFERRINJEN_SET(x)                                  (((x) << 0) & 0x00000001)
#define FPGA_REG2_TXPIPEIFERRINJEN_MSB                                                             1
#define FPGA_REG2_TXPIPEIFERRINJEN_LSB                                                             1
#define FPGA_REG2_TXPIPEIFERRINJEN_MASK                                                   0x00000002
#define FPGA_REG2_TXPIPEIFERRINJEN_GET(x)                                  (((x) & 0x00000002) >> 1)
#define FPGA_REG2_TXPIPEIFERRINJEN_SET(x)                                  (((x) << 1) & 0x00000002)
#define FPGA_REG2_RXPIPEIFINJERRINDATAK_MSB                                                        2
#define FPGA_REG2_RXPIPEIFINJERRINDATAK_LSB                                                        2
#define FPGA_REG2_RXPIPEIFINJERRINDATAK_MASK                                              0x00000004
#define FPGA_REG2_RXPIPEIFINJERRINDATAK_GET(x)                             (((x) & 0x00000004) >> 2)
#define FPGA_REG2_RXPIPEIFINJERRINDATAK_SET(x)                             (((x) << 2) & 0x00000004)
#define FPGA_REG2_TXPIPEIFINJERRINDATAK_MSB                                                        3
#define FPGA_REG2_TXPIPEIFINJERRINDATAK_LSB                                                        3
#define FPGA_REG2_TXPIPEIFINJERRINDATAK_MASK                                              0x00000008
#define FPGA_REG2_TXPIPEIFINJERRINDATAK_GET(x)                             (((x) & 0x00000008) >> 3)
#define FPGA_REG2_TXPIPEIFINJERRINDATAK_SET(x)                             (((x) << 3) & 0x00000008)
#define FPGA_REG2_DUMMY_ERROR_INJECTION_MSB                                                       31
#define FPGA_REG2_DUMMY_ERROR_INJECTION_LSB                                                        4
#define FPGA_REG2_DUMMY_ERROR_INJECTION_MASK                                              0xfffffff0
#define FPGA_REG2_DUMMY_ERROR_INJECTION_GET(x)                             (((x) & 0xfffffff0) >> 4)
#define FPGA_REG2_DUMMY_ERROR_INJECTION_SET(x)                             (((x) << 4) & 0xfffffff0)

/* macros for FPGA_REG3 */
#define FPGA_REG3_ADDRESS                                                                 0x00000010
#define FPGA_REG3_OFFSET                                                                  0x00000010
#define FPGA_REG3_FPGA_CHANGELIST_MSB                                                             31
#define FPGA_REG3_FPGA_CHANGELIST_LSB                                                              0
#define FPGA_REG3_FPGA_CHANGELIST_MASK                                                    0xffffffff
#define FPGA_REG3_FPGA_CHANGELIST_GET(x)                                   (((x) & 0xffffffff) >> 0)

/* macros for FPGA_REG4 */
#define FPGA_REG4_ADDRESS                                                                 0x00000014
#define FPGA_REG4_OFFSET                                                                  0x00000014
#define FPGA_REG4_RADIO_0_TCK_MSB                                                                  0
#define FPGA_REG4_RADIO_0_TCK_LSB                                                                  0
#define FPGA_REG4_RADIO_0_TCK_MASK                                                        0x00000001
#define FPGA_REG4_RADIO_0_TCK_GET(x)                                       (((x) & 0x00000001) >> 0)
#define FPGA_REG4_RADIO_0_TCK_SET(x)                                       (((x) << 0) & 0x00000001)
#define FPGA_REG4_RADIO_0_TDI_MSB                                                                  1
#define FPGA_REG4_RADIO_0_TDI_LSB                                                                  1
#define FPGA_REG4_RADIO_0_TDI_MASK                                                        0x00000002
#define FPGA_REG4_RADIO_0_TDI_GET(x)                                       (((x) & 0x00000002) >> 1)
#define FPGA_REG4_RADIO_0_TDI_SET(x)                                       (((x) << 1) & 0x00000002)
#define FPGA_REG4_RADIO_0_TMS_MSB                                                                  2
#define FPGA_REG4_RADIO_0_TMS_LSB                                                                  2
#define FPGA_REG4_RADIO_0_TMS_MASK                                                        0x00000004
#define FPGA_REG4_RADIO_0_TMS_GET(x)                                       (((x) & 0x00000004) >> 2)
#define FPGA_REG4_RADIO_0_TMS_SET(x)                                       (((x) << 2) & 0x00000004)
#define FPGA_REG4_RADIO_0_TDO_MSB                                                                  3
#define FPGA_REG4_RADIO_0_TDO_LSB                                                                  3
#define FPGA_REG4_RADIO_0_TDO_MASK                                                        0x00000008
#define FPGA_REG4_RADIO_0_TDO_GET(x)                                       (((x) & 0x00000008) >> 3)
#define FPGA_REG4_RADIO_1_TCK_MSB                                                                  4
#define FPGA_REG4_RADIO_1_TCK_LSB                                                                  4
#define FPGA_REG4_RADIO_1_TCK_MASK                                                        0x00000010
#define FPGA_REG4_RADIO_1_TCK_GET(x)                                       (((x) & 0x00000010) >> 4)
#define FPGA_REG4_RADIO_1_TCK_SET(x)                                       (((x) << 4) & 0x00000010)
#define FPGA_REG4_RADIO_1_TDI_MSB                                                                  5
#define FPGA_REG4_RADIO_1_TDI_LSB                                                                  5
#define FPGA_REG4_RADIO_1_TDI_MASK                                                        0x00000020
#define FPGA_REG4_RADIO_1_TDI_GET(x)                                       (((x) & 0x00000020) >> 5)
#define FPGA_REG4_RADIO_1_TDI_SET(x)                                       (((x) << 5) & 0x00000020)
#define FPGA_REG4_RADIO_1_TMS_MSB                                                                  6
#define FPGA_REG4_RADIO_1_TMS_LSB                                                                  6
#define FPGA_REG4_RADIO_1_TMS_MASK                                                        0x00000040
#define FPGA_REG4_RADIO_1_TMS_GET(x)                                       (((x) & 0x00000040) >> 6)
#define FPGA_REG4_RADIO_1_TMS_SET(x)                                       (((x) << 6) & 0x00000040)
#define FPGA_REG4_RADIO_1_TDO_MSB                                                                  7
#define FPGA_REG4_RADIO_1_TDO_LSB                                                                  7
#define FPGA_REG4_RADIO_1_TDO_MASK                                                        0x00000080
#define FPGA_REG4_RADIO_1_TDO_GET(x)                                       (((x) & 0x00000080) >> 7)
#define FPGA_REG4_RADIO_2_TCK_MSB                                                                  8
#define FPGA_REG4_RADIO_2_TCK_LSB                                                                  8
#define FPGA_REG4_RADIO_2_TCK_MASK                                                        0x00000100
#define FPGA_REG4_RADIO_2_TCK_GET(x)                                       (((x) & 0x00000100) >> 8)
#define FPGA_REG4_RADIO_2_TCK_SET(x)                                       (((x) << 8) & 0x00000100)
#define FPGA_REG4_RADIO_2_TDI_MSB                                                                  9
#define FPGA_REG4_RADIO_2_TDI_LSB                                                                  9
#define FPGA_REG4_RADIO_2_TDI_MASK                                                        0x00000200
#define FPGA_REG4_RADIO_2_TDI_GET(x)                                       (((x) & 0x00000200) >> 9)
#define FPGA_REG4_RADIO_2_TDI_SET(x)                                       (((x) << 9) & 0x00000200)
#define FPGA_REG4_RADIO_2_TMS_MSB                                                                 10
#define FPGA_REG4_RADIO_2_TMS_LSB                                                                 10
#define FPGA_REG4_RADIO_2_TMS_MASK                                                        0x00000400
#define FPGA_REG4_RADIO_2_TMS_GET(x)                                      (((x) & 0x00000400) >> 10)
#define FPGA_REG4_RADIO_2_TMS_SET(x)                                      (((x) << 10) & 0x00000400)
#define FPGA_REG4_RADIO_2_TDO_MSB                                                                 11
#define FPGA_REG4_RADIO_2_TDO_LSB                                                                 11
#define FPGA_REG4_RADIO_2_TDO_MASK                                                        0x00000800
#define FPGA_REG4_RADIO_2_TDO_GET(x)                                      (((x) & 0x00000800) >> 11)
#define FPGA_REG4_RADIO_3_TCK_MSB                                                                 12
#define FPGA_REG4_RADIO_3_TCK_LSB                                                                 12
#define FPGA_REG4_RADIO_3_TCK_MASK                                                        0x00001000
#define FPGA_REG4_RADIO_3_TCK_GET(x)                                      (((x) & 0x00001000) >> 12)
#define FPGA_REG4_RADIO_3_TCK_SET(x)                                      (((x) << 12) & 0x00001000)
#define FPGA_REG4_RADIO_3_TDI_MSB                                                                 13
#define FPGA_REG4_RADIO_3_TDI_LSB                                                                 13
#define FPGA_REG4_RADIO_3_TDI_MASK                                                        0x00002000
#define FPGA_REG4_RADIO_3_TDI_GET(x)                                      (((x) & 0x00002000) >> 13)
#define FPGA_REG4_RADIO_3_TDI_SET(x)                                      (((x) << 13) & 0x00002000)
#define FPGA_REG4_RADIO_3_TMS_MSB                                                                 14
#define FPGA_REG4_RADIO_3_TMS_LSB                                                                 14
#define FPGA_REG4_RADIO_3_TMS_MASK                                                        0x00004000
#define FPGA_REG4_RADIO_3_TMS_GET(x)                                      (((x) & 0x00004000) >> 14)
#define FPGA_REG4_RADIO_3_TMS_SET(x)                                      (((x) << 14) & 0x00004000)
#define FPGA_REG4_RADIO_3_TDO_MSB                                                                 15
#define FPGA_REG4_RADIO_3_TDO_LSB                                                                 15
#define FPGA_REG4_RADIO_3_TDO_MASK                                                        0x00008000
#define FPGA_REG4_RADIO_3_TDO_GET(x)                                      (((x) & 0x00008000) >> 15)
#define FPGA_REG4_RADIO_TRSTL_MSB                                                                 16
#define FPGA_REG4_RADIO_TRSTL_LSB                                                                 16
#define FPGA_REG4_RADIO_TRSTL_MASK                                                        0x00010000
#define FPGA_REG4_RADIO_TRSTL_GET(x)                                      (((x) & 0x00010000) >> 16)
#define FPGA_REG4_RADIO_TRSTL_SET(x)                                      (((x) << 16) & 0x00010000)
#define FPGA_REG4_SOFTWARE_OWNS_JTAG_MSB                                                          17
#define FPGA_REG4_SOFTWARE_OWNS_JTAG_LSB                                                          17
#define FPGA_REG4_SOFTWARE_OWNS_JTAG_MASK                                                 0x00020000
#define FPGA_REG4_SOFTWARE_OWNS_JTAG_GET(x)                               (((x) & 0x00020000) >> 17)
#define FPGA_REG4_SOFTWARE_OWNS_JTAG_SET(x)                               (((x) << 17) & 0x00020000)

/* macros for FPGA_REG5 */
#define FPGA_REG5_ADDRESS                                                                 0x00000018
#define FPGA_REG5_OFFSET                                                                  0x00000018
#define FPGA_REG5_DRP_DEN_MSB                                                                      0
#define FPGA_REG5_DRP_DEN_LSB                                                                      0
#define FPGA_REG5_DRP_DEN_MASK                                                            0x00000001
#define FPGA_REG5_DRP_DEN_GET(x)                                           (((x) & 0x00000001) >> 0)
#define FPGA_REG5_DRP_DEN_SET(x)                                           (((x) << 0) & 0x00000001)
#define FPGA_REG5_DRP_DWE_MSB                                                                      1
#define FPGA_REG5_DRP_DWE_LSB                                                                      1
#define FPGA_REG5_DRP_DWE_MASK                                                            0x00000002
#define FPGA_REG5_DRP_DWE_GET(x)                                           (((x) & 0x00000002) >> 1)
#define FPGA_REG5_DRP_DWE_SET(x)                                           (((x) << 1) & 0x00000002)
#define FPGA_REG5_DRP_RESET_MSB                                                                    2
#define FPGA_REG5_DRP_RESET_LSB                                                                    2
#define FPGA_REG5_DRP_RESET_MASK                                                          0x00000004
#define FPGA_REG5_DRP_RESET_GET(x)                                         (((x) & 0x00000004) >> 2)
#define FPGA_REG5_DRP_RESET_SET(x)                                         (((x) << 2) & 0x00000004)
#define FPGA_REG5_DRP_ADDRESS_MSB                                                                  7
#define FPGA_REG5_DRP_ADDRESS_LSB                                                                  3
#define FPGA_REG5_DRP_ADDRESS_MASK                                                        0x000000f8
#define FPGA_REG5_DRP_ADDRESS_GET(x)                                       (((x) & 0x000000f8) >> 3)
#define FPGA_REG5_DRP_ADDRESS_SET(x)                                       (((x) << 3) & 0x000000f8)
#define FPGA_REG5_DRP_RESERVED_MSB                                                                15
#define FPGA_REG5_DRP_RESERVED_LSB                                                                 8
#define FPGA_REG5_DRP_RESERVED_MASK                                                       0x0000ff00
#define FPGA_REG5_DRP_RESERVED_GET(x)                                      (((x) & 0x0000ff00) >> 8)
#define FPGA_REG5_DRP_RESERVED_SET(x)                                      (((x) << 8) & 0x0000ff00)
#define FPGA_REG5_DRP_DIN_MSB                                                                     31
#define FPGA_REG5_DRP_DIN_LSB                                                                     16
#define FPGA_REG5_DRP_DIN_MASK                                                            0xffff0000
#define FPGA_REG5_DRP_DIN_GET(x)                                          (((x) & 0xffff0000) >> 16)
#define FPGA_REG5_DRP_DIN_SET(x)                                          (((x) << 16) & 0xffff0000)

/* macros for FPGA_REG6 */
#define FPGA_REG6_ADDRESS                                                                 0x0000001c
#define FPGA_REG6_OFFSET                                                                  0x0000001c
#define FPGA_REG6_DRP_DRDY_MSB                                                                     0
#define FPGA_REG6_DRP_DRDY_LSB                                                                     0
#define FPGA_REG6_DRP_DRDY_MASK                                                           0x00000001
#define FPGA_REG6_DRP_DRDY_GET(x)                                          (((x) & 0x00000001) >> 0)
#define FPGA_REG6_DRP_DOUT_MSB                                                                    31
#define FPGA_REG6_DRP_DOUT_LSB                                                                    16
#define FPGA_REG6_DRP_DOUT_MASK                                                           0xffff0000
#define FPGA_REG6_DRP_DOUT_GET(x)                                         (((x) & 0xffff0000) >> 16)

/* macros for FPGA_REG7 */
#define FPGA_REG7_ADDRESS                                                                 0x00000020
#define FPGA_REG7_OFFSET                                                                  0x00000020
#define FPGA_REG7_RXPIPEIFERRINJMSK_MSB                                                           31
#define FPGA_REG7_RXPIPEIFERRINJMSK_LSB                                                            0
#define FPGA_REG7_RXPIPEIFERRINJMSK_MASK                                                  0xffffffff
#define FPGA_REG7_RXPIPEIFERRINJMSK_GET(x)                                 (((x) & 0xffffffff) >> 0)
#define FPGA_REG7_RXPIPEIFERRINJMSK_SET(x)                                 (((x) << 0) & 0xffffffff)

/* macros for FPGA_REG8 */
#define FPGA_REG8_ADDRESS                                                                 0x00000024
#define FPGA_REG8_OFFSET                                                                  0x00000024
#define FPGA_REG8_TXPIPEIFERRINJMSK_MSB                                                           31
#define FPGA_REG8_TXPIPEIFERRINJMSK_LSB                                                            0
#define FPGA_REG8_TXPIPEIFERRINJMSK_MASK                                                  0xffffffff
#define FPGA_REG8_TXPIPEIFERRINJMSK_GET(x)                                 (((x) & 0xffffffff) >> 0)
#define FPGA_REG8_TXPIPEIFERRINJMSK_SET(x)                                 (((x) << 0) & 0xffffffff)

/* macros for FPGA_REG9 */
#define FPGA_REG9_ADDRESS                                                                 0x00000028
#define FPGA_REG9_OFFSET                                                                  0x00000028
#define FPGA_REG9_RXPIPEIFDATAERRMSK_MSB                                                          15
#define FPGA_REG9_RXPIPEIFDATAERRMSK_LSB                                                           0
#define FPGA_REG9_RXPIPEIFDATAERRMSK_MASK                                                 0x0000ffff
#define FPGA_REG9_RXPIPEIFDATAERRMSK_GET(x)                                (((x) & 0x0000ffff) >> 0)
#define FPGA_REG9_RXPIPEIFDATAERRMSK_SET(x)                                (((x) << 0) & 0x0000ffff)
#define FPGA_REG9_TXPIPEIFDATAERRMSK_MSB                                                          31
#define FPGA_REG9_TXPIPEIFDATAERRMSK_LSB                                                          16
#define FPGA_REG9_TXPIPEIFDATAERRMSK_MASK                                                 0xffff0000
#define FPGA_REG9_TXPIPEIFDATAERRMSK_GET(x)                               (((x) & 0xffff0000) >> 16)
#define FPGA_REG9_TXPIPEIFDATAERRMSK_SET(x)                               (((x) << 16) & 0xffff0000)

/* macros for FPGA_REG10 */
#define FPGA_REG10_ADDRESS                                                                0x0000002c
#define FPGA_REG10_OFFSET                                                                 0x0000002c
#define FPGA_REG10_RXPIPEIFSPDMSK_MSB                                                             15
#define FPGA_REG10_RXPIPEIFSPDMSK_LSB                                                              0
#define FPGA_REG10_RXPIPEIFSPDMSK_MASK                                                    0x0000ffff
#define FPGA_REG10_RXPIPEIFSPDMSK_GET(x)                                   (((x) & 0x0000ffff) >> 0)
#define FPGA_REG10_RXPIPEIFSPDMSK_SET(x)                                   (((x) << 0) & 0x0000ffff)
#define FPGA_REG10_TXPIPEIFSPDMSK_MSB                                                             31
#define FPGA_REG10_TXPIPEIFSPDMSK_LSB                                                             16
#define FPGA_REG10_TXPIPEIFSPDMSK_MASK                                                    0xffff0000
#define FPGA_REG10_TXPIPEIFSPDMSK_GET(x)                                  (((x) & 0xffff0000) >> 16)
#define FPGA_REG10_TXPIPEIFSPDMSK_SET(x)                                  (((x) << 16) & 0xffff0000)

/* macros for FPGA_REG11 */
#define FPGA_REG11_ADDRESS                                                                0x00000030
#define FPGA_REG11_OFFSET                                                                 0x00000030
#define FPGA_REG11_FAKE_BB_LFSR_SPREAD_MSB                                                        31
#define FPGA_REG11_FAKE_BB_LFSR_SPREAD_LSB                                                         0
#define FPGA_REG11_FAKE_BB_LFSR_SPREAD_MASK                                               0xffffffff
#define FPGA_REG11_FAKE_BB_LFSR_SPREAD_GET(x)                              (((x) & 0xffffffff) >> 0)
#define FPGA_REG11_FAKE_BB_LFSR_SPREAD_SET(x)                              (((x) << 0) & 0xffffffff)

/* macros for FPGA_REG12 */
#define FPGA_REG12_ADDRESS                                                                0x00000034
#define FPGA_REG12_OFFSET                                                                 0x00000034
#define FPGA_REG12_FAKE_BB_LFSR_DNSTY_MSK_MSB                                                     31
#define FPGA_REG12_FAKE_BB_LFSR_DNSTY_MSK_LSB                                                      0
#define FPGA_REG12_FAKE_BB_LFSR_DNSTY_MSK_MASK                                            0xffffffff
#define FPGA_REG12_FAKE_BB_LFSR_DNSTY_MSK_GET(x)                           (((x) & 0xffffffff) >> 0)
#define FPGA_REG12_FAKE_BB_LFSR_DNSTY_MSK_SET(x)                           (((x) << 0) & 0xffffffff)

/* macros for FPGA_REG13 */
#define FPGA_REG13_ADDRESS                                                                0x00000038
#define FPGA_REG13_OFFSET                                                                 0x00000038
#define FPGA_REG13_FAKE_BB_ERR_INJECT_ENABLE_MSB                                                   0
#define FPGA_REG13_FAKE_BB_ERR_INJECT_ENABLE_LSB                                                   0
#define FPGA_REG13_FAKE_BB_ERR_INJECT_ENABLE_MASK                                         0x00000001
#define FPGA_REG13_FAKE_BB_ERR_INJECT_ENABLE_GET(x)                        (((x) & 0x00000001) >> 0)
#define FPGA_REG13_FAKE_BB_ERR_INJECT_ENABLE_SET(x)                        (((x) << 0) & 0x00000001)

/* macros for FPGA_REG14 */
#define FPGA_REG14_ADDRESS                                                                0x0000003c
#define FPGA_REG14_OFFSET                                                                 0x0000003c
#define FPGA_REG14_RX_CLR_STOMP_ENABLE_MSB                                                         3
#define FPGA_REG14_RX_CLR_STOMP_ENABLE_LSB                                                         0
#define FPGA_REG14_RX_CLR_STOMP_ENABLE_MASK                                               0x0000000f
#define FPGA_REG14_RX_CLR_STOMP_ENABLE_GET(x)                              (((x) & 0x0000000f) >> 0)
#define FPGA_REG14_RX_CLR_STOMP_ENABLE_SET(x)                              (((x) << 0) & 0x0000000f)

/* macros for FPGA_REG15 */
#define FPGA_REG15_ADDRESS                                                                0x00000040
#define FPGA_REG15_OFFSET                                                                 0x00000040
#define FPGA_REG15_PRI_CLR_CNT_MSB                                                                31
#define FPGA_REG15_PRI_CLR_CNT_LSB                                                                 0
#define FPGA_REG15_PRI_CLR_CNT_MASK                                                       0xffffffff
#define FPGA_REG15_PRI_CLR_CNT_GET(x)                                      (((x) & 0xffffffff) >> 0)
#define FPGA_REG15_PRI_CLR_CNT_SET(x)                                      (((x) << 0) & 0xffffffff)

/* macros for FPGA_REG16 */
#define FPGA_REG16_ADDRESS                                                                0x00000044
#define FPGA_REG16_OFFSET                                                                 0x00000044
#define FPGA_REG16_PRI_BUSY_CNT_MSB                                                               15
#define FPGA_REG16_PRI_BUSY_CNT_LSB                                                                0
#define FPGA_REG16_PRI_BUSY_CNT_MASK                                                      0x0000ffff
#define FPGA_REG16_PRI_BUSY_CNT_GET(x)                                     (((x) & 0x0000ffff) >> 0)
#define FPGA_REG16_PRI_BUSY_CNT_SET(x)                                     (((x) << 0) & 0x0000ffff)

/* macros for FPGA_REG17 */
#define FPGA_REG17_ADDRESS                                                                0x00000048
#define FPGA_REG17_OFFSET                                                                 0x00000048
#define FPGA_REG17_SEC20_CLR_CNT_MSB                                                              31
#define FPGA_REG17_SEC20_CLR_CNT_LSB                                                               0
#define FPGA_REG17_SEC20_CLR_CNT_MASK                                                     0xffffffff
#define FPGA_REG17_SEC20_CLR_CNT_GET(x)                                    (((x) & 0xffffffff) >> 0)
#define FPGA_REG17_SEC20_CLR_CNT_SET(x)                                    (((x) << 0) & 0xffffffff)

/* macros for FPGA_REG18 */
#define FPGA_REG18_ADDRESS                                                                0x0000004c
#define FPGA_REG18_OFFSET                                                                 0x0000004c
#define FPGA_REG18_SEC20_BUSY_CNT_MSB                                                             15
#define FPGA_REG18_SEC20_BUSY_CNT_LSB                                                              0
#define FPGA_REG18_SEC20_BUSY_CNT_MASK                                                    0x0000ffff
#define FPGA_REG18_SEC20_BUSY_CNT_GET(x)                                   (((x) & 0x0000ffff) >> 0)
#define FPGA_REG18_SEC20_BUSY_CNT_SET(x)                                   (((x) << 0) & 0x0000ffff)

/* macros for FPGA_REG19 */
#define FPGA_REG19_ADDRESS                                                                0x00000050
#define FPGA_REG19_OFFSET                                                                 0x00000050
#define FPGA_REG19_SEC40_CLR_CNT_MSB                                                              31
#define FPGA_REG19_SEC40_CLR_CNT_LSB                                                               0
#define FPGA_REG19_SEC40_CLR_CNT_MASK                                                     0xffffffff
#define FPGA_REG19_SEC40_CLR_CNT_GET(x)                                    (((x) & 0xffffffff) >> 0)
#define FPGA_REG19_SEC40_CLR_CNT_SET(x)                                    (((x) << 0) & 0xffffffff)

/* macros for FPGA_REG20 */
#define FPGA_REG20_ADDRESS                                                                0x00000054
#define FPGA_REG20_OFFSET                                                                 0x00000054
#define FPGA_REG20_SEC40_BUSY_CNT_MSB                                                             15
#define FPGA_REG20_SEC40_BUSY_CNT_LSB                                                              0
#define FPGA_REG20_SEC40_BUSY_CNT_MASK                                                    0x0000ffff
#define FPGA_REG20_SEC40_BUSY_CNT_GET(x)                                   (((x) & 0x0000ffff) >> 0)
#define FPGA_REG20_SEC40_BUSY_CNT_SET(x)                                   (((x) << 0) & 0x0000ffff)

/* macros for FPGA_REG21 */
#define FPGA_REG21_ADDRESS                                                                0x00000058
#define FPGA_REG21_OFFSET                                                                 0x00000058
#define FPGA_REG21_SEC80_CLR_CNT_MSB                                                              31
#define FPGA_REG21_SEC80_CLR_CNT_LSB                                                               0
#define FPGA_REG21_SEC80_CLR_CNT_MASK                                                     0xffffffff
#define FPGA_REG21_SEC80_CLR_CNT_GET(x)                                    (((x) & 0xffffffff) >> 0)
#define FPGA_REG21_SEC80_CLR_CNT_SET(x)                                    (((x) << 0) & 0xffffffff)

/* macros for FPGA_REG22 */
#define FPGA_REG22_ADDRESS                                                                0x0000005c
#define FPGA_REG22_OFFSET                                                                 0x0000005c
#define FPGA_REG22_SEC80_BUSY_CNT_MSB                                                             15
#define FPGA_REG22_SEC80_BUSY_CNT_LSB                                                              0
#define FPGA_REG22_SEC80_BUSY_CNT_MASK                                                    0x0000ffff
#define FPGA_REG22_SEC80_BUSY_CNT_GET(x)                                   (((x) & 0x0000ffff) >> 0)
#define FPGA_REG22_SEC80_BUSY_CNT_SET(x)                                   (((x) << 0) & 0x0000ffff)


#ifndef __ASSEMBLER__

typedef struct emulation_misc_regs_reg_s {
  volatile unsigned int FPGA_PHY_LAYER_REVID;                          /*        0x0 - 0x4        */
  volatile unsigned int FPGA_LINK_LAYER_REVID;                         /*        0x4 - 0x8        */
  volatile unsigned int FPGA_REG1;                                     /*        0x8 - 0xc        */
  volatile unsigned int FPGA_REG2;                                     /*        0xc - 0x10       */
  volatile unsigned int FPGA_REG3;                                     /*       0x10 - 0x14       */
  volatile unsigned int FPGA_REG4;                                     /*       0x14 - 0x18       */
  volatile unsigned int FPGA_REG5;                                     /*       0x18 - 0x1c       */
  volatile unsigned int FPGA_REG6;                                     /*       0x1c - 0x20       */
  volatile unsigned int FPGA_REG7;                                     /*       0x20 - 0x24       */
  volatile unsigned int FPGA_REG8;                                     /*       0x24 - 0x28       */
  volatile unsigned int FPGA_REG9;                                     /*       0x28 - 0x2c       */
  volatile unsigned int FPGA_REG10;                                    /*       0x2c - 0x30       */
  volatile unsigned int FPGA_REG11;                                    /*       0x30 - 0x34       */
  volatile unsigned int FPGA_REG12;                                    /*       0x34 - 0x38       */
  volatile unsigned int FPGA_REG13;                                    /*       0x38 - 0x3c       */
  volatile unsigned int FPGA_REG14;                                    /*       0x3c - 0x40       */
  volatile unsigned int FPGA_REG15;                                    /*       0x40 - 0x44       */
  volatile unsigned int FPGA_REG16;                                    /*       0x44 - 0x48       */
  volatile unsigned int FPGA_REG17;                                    /*       0x48 - 0x4c       */
  volatile unsigned int FPGA_REG18;                                    /*       0x4c - 0x50       */
  volatile unsigned int FPGA_REG19;                                    /*       0x50 - 0x54       */
  volatile unsigned int FPGA_REG20;                                    /*       0x54 - 0x58       */
  volatile unsigned int FPGA_REG21;                                    /*       0x58 - 0x5c       */
  volatile unsigned int FPGA_REG22;                                    /*       0x5c - 0x60       */
} emulation_misc_regs_reg_t;

#endif /* __ASSEMBLER__ */

#endif /* _EMULATION_MISC_REGS_H_ */
