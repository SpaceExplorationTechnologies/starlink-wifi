/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _PCIE_PHY_REG_CSR_H_
#define _PCIE_PHY_REG_CSR_H_


#ifndef __PCIE_PHY_REG_CSR_BASE_ADDRESS
#define __PCIE_PHY_REG_CSR_BASE_ADDRESS (0x8d000)
#endif


// 0x0 (PCIE_PHY_REG_1)
#define PCIE_PHY_REG_1_FORCERXEIDLE_0_EN_LSB                                   31
#define PCIE_PHY_REG_1_FORCERXEIDLE_0_EN_MSB                                   31
#define PCIE_PHY_REG_1_FORCERXEIDLE_0_EN_MASK                                  0x80000000
#define PCIE_PHY_REG_1_FORCERXEIDLE_0_EN_GET(x)                                (((x) & PCIE_PHY_REG_1_FORCERXEIDLE_0_EN_MASK) >> PCIE_PHY_REG_1_FORCERXEIDLE_0_EN_LSB)
#define PCIE_PHY_REG_1_FORCERXEIDLE_0_EN_SET(x)                                (((0 | (x)) << PCIE_PHY_REG_1_FORCERXEIDLE_0_EN_LSB) & PCIE_PHY_REG_1_FORCERXEIDLE_0_EN_MASK)
#define PCIE_PHY_REG_1_FORCERXEIDLE_0_EN_RESET                                 0x0
#define PCIE_PHY_REG_1_REV10_LOOPBACK_EN_LSB                                   30
#define PCIE_PHY_REG_1_REV10_LOOPBACK_EN_MSB                                   30
#define PCIE_PHY_REG_1_REV10_LOOPBACK_EN_MASK                                  0x40000000
#define PCIE_PHY_REG_1_REV10_LOOPBACK_EN_GET(x)                                (((x) & PCIE_PHY_REG_1_REV10_LOOPBACK_EN_MASK) >> PCIE_PHY_REG_1_REV10_LOOPBACK_EN_LSB)
#define PCIE_PHY_REG_1_REV10_LOOPBACK_EN_SET(x)                                (((0 | (x)) << PCIE_PHY_REG_1_REV10_LOOPBACK_EN_LSB) & PCIE_PHY_REG_1_REV10_LOOPBACK_EN_MASK)
#define PCIE_PHY_REG_1_REV10_LOOPBACK_EN_RESET                                 0x0
#define PCIE_PHY_REG_1_ENABLECLKREQ_LSB                                        29
#define PCIE_PHY_REG_1_ENABLECLKREQ_MSB                                        29
#define PCIE_PHY_REG_1_ENABLECLKREQ_MASK                                       0x20000000
#define PCIE_PHY_REG_1_ENABLECLKREQ_GET(x)                                     (((x) & PCIE_PHY_REG_1_ENABLECLKREQ_MASK) >> PCIE_PHY_REG_1_ENABLECLKREQ_LSB)
#define PCIE_PHY_REG_1_ENABLECLKREQ_SET(x)                                     (((0 | (x)) << PCIE_PHY_REG_1_ENABLECLKREQ_LSB) & PCIE_PHY_REG_1_ENABLECLKREQ_MASK)
#define PCIE_PHY_REG_1_ENABLECLKREQ_RESET                                      0x0
#define PCIE_PHY_REG_1_DATAOBSPRBSERR_LSB                                      28
#define PCIE_PHY_REG_1_DATAOBSPRBSERR_MSB                                      28
#define PCIE_PHY_REG_1_DATAOBSPRBSERR_MASK                                     0x10000000
#define PCIE_PHY_REG_1_DATAOBSPRBSERR_GET(x)                                   (((x) & PCIE_PHY_REG_1_DATAOBSPRBSERR_MASK) >> PCIE_PHY_REG_1_DATAOBSPRBSERR_LSB)
#define PCIE_PHY_REG_1_DATAOBSPRBSERR_SET(x)                                   (((0 | (x)) << PCIE_PHY_REG_1_DATAOBSPRBSERR_LSB) & PCIE_PHY_REG_1_DATAOBSPRBSERR_MASK)
#define PCIE_PHY_REG_1_DATAOBSPRBSERR_RESET                                    0x0
#define PCIE_PHY_REG_1_SERDES_EN_LCKDT_LSB                                     27
#define PCIE_PHY_REG_1_SERDES_EN_LCKDT_MSB                                     27
#define PCIE_PHY_REG_1_SERDES_EN_LCKDT_MASK                                    0x8000000
#define PCIE_PHY_REG_1_SERDES_EN_LCKDT_GET(x)                                  (((x) & PCIE_PHY_REG_1_SERDES_EN_LCKDT_MASK) >> PCIE_PHY_REG_1_SERDES_EN_LCKDT_LSB)
#define PCIE_PHY_REG_1_SERDES_EN_LCKDT_SET(x)                                  (((0 | (x)) << PCIE_PHY_REG_1_SERDES_EN_LCKDT_LSB) & PCIE_PHY_REG_1_SERDES_EN_LCKDT_MASK)
#define PCIE_PHY_REG_1_SERDES_EN_LCKDT_RESET                                   0x0
#define PCIE_PHY_REG_1_CLKOBSSEL_LSB                                           25
#define PCIE_PHY_REG_1_CLKOBSSEL_MSB                                           26
#define PCIE_PHY_REG_1_CLKOBSSEL_MASK                                          0x6000000
#define PCIE_PHY_REG_1_CLKOBSSEL_GET(x)                                        (((x) & PCIE_PHY_REG_1_CLKOBSSEL_MASK) >> PCIE_PHY_REG_1_CLKOBSSEL_LSB)
#define PCIE_PHY_REG_1_CLKOBSSEL_SET(x)                                        (((0 | (x)) << PCIE_PHY_REG_1_CLKOBSSEL_LSB) & PCIE_PHY_REG_1_CLKOBSSEL_MASK)
#define PCIE_PHY_REG_1_CLKOBSSEL_RESET                                         0x0
#define PCIE_PHY_REG_1_DATAOBSEN_LSB                                           24
#define PCIE_PHY_REG_1_DATAOBSEN_MSB                                           24
#define PCIE_PHY_REG_1_DATAOBSEN_MASK                                          0x1000000
#define PCIE_PHY_REG_1_DATAOBSEN_GET(x)                                        (((x) & PCIE_PHY_REG_1_DATAOBSEN_MASK) >> PCIE_PHY_REG_1_DATAOBSEN_LSB)
#define PCIE_PHY_REG_1_DATAOBSEN_SET(x)                                        (((0 | (x)) << PCIE_PHY_REG_1_DATAOBSEN_LSB) & PCIE_PHY_REG_1_DATAOBSEN_MASK)
#define PCIE_PHY_REG_1_DATAOBSEN_RESET                                         0x0
#define PCIE_PHY_REG_1_FUNCTESTRXCLKINV_LSB                                    23
#define PCIE_PHY_REG_1_FUNCTESTRXCLKINV_MSB                                    23
#define PCIE_PHY_REG_1_FUNCTESTRXCLKINV_MASK                                   0x800000
#define PCIE_PHY_REG_1_FUNCTESTRXCLKINV_GET(x)                                 (((x) & PCIE_PHY_REG_1_FUNCTESTRXCLKINV_MASK) >> PCIE_PHY_REG_1_FUNCTESTRXCLKINV_LSB)
#define PCIE_PHY_REG_1_FUNCTESTRXCLKINV_SET(x)                                 (((0 | (x)) << PCIE_PHY_REG_1_FUNCTESTRXCLKINV_LSB) & PCIE_PHY_REG_1_FUNCTESTRXCLKINV_MASK)
#define PCIE_PHY_REG_1_FUNCTESTRXCLKINV_RESET                                  0x0
#define PCIE_PHY_REG_1_VCO_FAST_LSB                                            22
#define PCIE_PHY_REG_1_VCO_FAST_MSB                                            22
#define PCIE_PHY_REG_1_VCO_FAST_MASK                                           0x400000
#define PCIE_PHY_REG_1_VCO_FAST_GET(x)                                         (((x) & PCIE_PHY_REG_1_VCO_FAST_MASK) >> PCIE_PHY_REG_1_VCO_FAST_LSB)
#define PCIE_PHY_REG_1_VCO_FAST_SET(x)                                         (((0 | (x)) << PCIE_PHY_REG_1_VCO_FAST_LSB) & PCIE_PHY_REG_1_VCO_FAST_MASK)
#define PCIE_PHY_REG_1_VCO_FAST_RESET                                          0x0
#define PCIE_PHY_REG_1_VCO_SLOW_LSB                                            21
#define PCIE_PHY_REG_1_VCO_SLOW_MSB                                            21
#define PCIE_PHY_REG_1_VCO_SLOW_MASK                                           0x200000
#define PCIE_PHY_REG_1_VCO_SLOW_GET(x)                                         (((x) & PCIE_PHY_REG_1_VCO_SLOW_MASK) >> PCIE_PHY_REG_1_VCO_SLOW_LSB)
#define PCIE_PHY_REG_1_VCO_SLOW_SET(x)                                         (((0 | (x)) << PCIE_PHY_REG_1_VCO_SLOW_LSB) & PCIE_PHY_REG_1_VCO_SLOW_MASK)
#define PCIE_PHY_REG_1_VCO_SLOW_RESET                                          0x0
#define PCIE_PHY_REG_1_PRBS_AA_ENABLE_LSB                                      20
#define PCIE_PHY_REG_1_PRBS_AA_ENABLE_MSB                                      20
#define PCIE_PHY_REG_1_PRBS_AA_ENABLE_MASK                                     0x100000
#define PCIE_PHY_REG_1_PRBS_AA_ENABLE_GET(x)                                   (((x) & PCIE_PHY_REG_1_PRBS_AA_ENABLE_MASK) >> PCIE_PHY_REG_1_PRBS_AA_ENABLE_LSB)
#define PCIE_PHY_REG_1_PRBS_AA_ENABLE_SET(x)                                   (((0 | (x)) << PCIE_PHY_REG_1_PRBS_AA_ENABLE_LSB) & PCIE_PHY_REG_1_PRBS_AA_ENABLE_MASK)
#define PCIE_PHY_REG_1_PRBS_AA_ENABLE_RESET                                    0x0
#define PCIE_PHY_REG_1_SERDES_FROM_PAD_OR_REG_LSB                              19
#define PCIE_PHY_REG_1_SERDES_FROM_PAD_OR_REG_MSB                              19
#define PCIE_PHY_REG_1_SERDES_FROM_PAD_OR_REG_MASK                             0x80000
#define PCIE_PHY_REG_1_SERDES_FROM_PAD_OR_REG_GET(x)                           (((x) & PCIE_PHY_REG_1_SERDES_FROM_PAD_OR_REG_MASK) >> PCIE_PHY_REG_1_SERDES_FROM_PAD_OR_REG_LSB)
#define PCIE_PHY_REG_1_SERDES_FROM_PAD_OR_REG_SET(x)                           (((0 | (x)) << PCIE_PHY_REG_1_SERDES_FROM_PAD_OR_REG_LSB) & PCIE_PHY_REG_1_SERDES_FROM_PAD_OR_REG_MASK)
#define PCIE_PHY_REG_1_SERDES_FROM_PAD_OR_REG_RESET                            0x0
#define PCIE_PHY_REG_1_SERDES_DIS_RXIMP_LSB                                    18
#define PCIE_PHY_REG_1_SERDES_DIS_RXIMP_MSB                                    18
#define PCIE_PHY_REG_1_SERDES_DIS_RXIMP_MASK                                   0x40000
#define PCIE_PHY_REG_1_SERDES_DIS_RXIMP_GET(x)                                 (((x) & PCIE_PHY_REG_1_SERDES_DIS_RXIMP_MASK) >> PCIE_PHY_REG_1_SERDES_DIS_RXIMP_LSB)
#define PCIE_PHY_REG_1_SERDES_DIS_RXIMP_SET(x)                                 (((0 | (x)) << PCIE_PHY_REG_1_SERDES_DIS_RXIMP_LSB) & PCIE_PHY_REG_1_SERDES_DIS_RXIMP_MASK)
#define PCIE_PHY_REG_1_SERDES_DIS_RXIMP_RESET                                  0x0
#define PCIE_PHY_REG_1_SERDES_DISABLE_LSB                                      17
#define PCIE_PHY_REG_1_SERDES_DISABLE_MSB                                      17
#define PCIE_PHY_REG_1_SERDES_DISABLE_MASK                                     0x20000
#define PCIE_PHY_REG_1_SERDES_DISABLE_GET(x)                                   (((x) & PCIE_PHY_REG_1_SERDES_DISABLE_MASK) >> PCIE_PHY_REG_1_SERDES_DISABLE_LSB)
#define PCIE_PHY_REG_1_SERDES_DISABLE_SET(x)                                   (((0 | (x)) << PCIE_PHY_REG_1_SERDES_DISABLE_LSB) & PCIE_PHY_REG_1_SERDES_DISABLE_MASK)
#define PCIE_PHY_REG_1_SERDES_DISABLE_RESET                                    0x0
#define PCIE_PHY_REG_1_RXCLKINV_LSB                                            16
#define PCIE_PHY_REG_1_RXCLKINV_MSB                                            16
#define PCIE_PHY_REG_1_RXCLKINV_MASK                                           0x10000
#define PCIE_PHY_REG_1_RXCLKINV_GET(x)                                         (((x) & PCIE_PHY_REG_1_RXCLKINV_MASK) >> PCIE_PHY_REG_1_RXCLKINV_LSB)
#define PCIE_PHY_REG_1_RXCLKINV_SET(x)                                         (((0 | (x)) << PCIE_PHY_REG_1_RXCLKINV_LSB) & PCIE_PHY_REG_1_RXCLKINV_MASK)
#define PCIE_PHY_REG_1_RXCLKINV_RESET                                          0x1
#define PCIE_PHY_REG_1_FORCELOOPBACK_LSB                                       15
#define PCIE_PHY_REG_1_FORCELOOPBACK_MSB                                       15
#define PCIE_PHY_REG_1_FORCELOOPBACK_MASK                                      0x8000
#define PCIE_PHY_REG_1_FORCELOOPBACK_GET(x)                                    (((x) & PCIE_PHY_REG_1_FORCELOOPBACK_MASK) >> PCIE_PHY_REG_1_FORCELOOPBACK_LSB)
#define PCIE_PHY_REG_1_FORCELOOPBACK_SET(x)                                    (((0 | (x)) << PCIE_PHY_REG_1_FORCELOOPBACK_LSB) & PCIE_PHY_REG_1_FORCELOOPBACK_MASK)
#define PCIE_PHY_REG_1_FORCELOOPBACK_RESET                                     0x0
#define PCIE_PHY_REG_1_SERDES_RX_EQ_LSB                                        13
#define PCIE_PHY_REG_1_SERDES_RX_EQ_MSB                                        14
#define PCIE_PHY_REG_1_SERDES_RX_EQ_MASK                                       0x6000
#define PCIE_PHY_REG_1_SERDES_RX_EQ_GET(x)                                     (((x) & PCIE_PHY_REG_1_SERDES_RX_EQ_MASK) >> PCIE_PHY_REG_1_SERDES_RX_EQ_LSB)
#define PCIE_PHY_REG_1_SERDES_RX_EQ_SET(x)                                     (((0 | (x)) << PCIE_PHY_REG_1_SERDES_RX_EQ_LSB) & PCIE_PHY_REG_1_SERDES_RX_EQ_MASK)
#define PCIE_PHY_REG_1_SERDES_RX_EQ_RESET                                      0x1
#define PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_LSB                               12
#define PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_MSB                               12
#define PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_MASK                              0x1000
#define PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_GET(x)                            (((x) & PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_MASK) >> PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_LSB)
#define PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_SET(x)                            (((0 | (x)) << PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_LSB) & PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_MASK)
#define PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_RESET                             0x0
#define PCIE_PHY_REG_1_SERDES_POWER_SAVE_LSB                                   11
#define PCIE_PHY_REG_1_SERDES_POWER_SAVE_MSB                                   11
#define PCIE_PHY_REG_1_SERDES_POWER_SAVE_MASK                                  0x800
#define PCIE_PHY_REG_1_SERDES_POWER_SAVE_GET(x)                                (((x) & PCIE_PHY_REG_1_SERDES_POWER_SAVE_MASK) >> PCIE_PHY_REG_1_SERDES_POWER_SAVE_LSB)
#define PCIE_PHY_REG_1_SERDES_POWER_SAVE_SET(x)                                (((0 | (x)) << PCIE_PHY_REG_1_SERDES_POWER_SAVE_LSB) & PCIE_PHY_REG_1_SERDES_POWER_SAVE_MASK)
#define PCIE_PHY_REG_1_SERDES_POWER_SAVE_RESET                                 0x0
#define PCIE_PHY_REG_1_SERDES_CDR_BW_LSB                                       9
#define PCIE_PHY_REG_1_SERDES_CDR_BW_MSB                                       10
#define PCIE_PHY_REG_1_SERDES_CDR_BW_MASK                                      0x600
#define PCIE_PHY_REG_1_SERDES_CDR_BW_GET(x)                                    (((x) & PCIE_PHY_REG_1_SERDES_CDR_BW_MASK) >> PCIE_PHY_REG_1_SERDES_CDR_BW_LSB)
#define PCIE_PHY_REG_1_SERDES_CDR_BW_SET(x)                                    (((0 | (x)) << PCIE_PHY_REG_1_SERDES_CDR_BW_LSB) & PCIE_PHY_REG_1_SERDES_CDR_BW_MASK)
#define PCIE_PHY_REG_1_SERDES_CDR_BW_RESET                                     0x1
#define PCIE_PHY_REG_1_SERDES_TH_LOS_LSB                                       6
#define PCIE_PHY_REG_1_SERDES_TH_LOS_MSB                                       8
#define PCIE_PHY_REG_1_SERDES_TH_LOS_MASK                                      0x1c0
#define PCIE_PHY_REG_1_SERDES_TH_LOS_GET(x)                                    (((x) & PCIE_PHY_REG_1_SERDES_TH_LOS_MASK) >> PCIE_PHY_REG_1_SERDES_TH_LOS_LSB)
#define PCIE_PHY_REG_1_SERDES_TH_LOS_SET(x)                                    (((0 | (x)) << PCIE_PHY_REG_1_SERDES_TH_LOS_LSB) & PCIE_PHY_REG_1_SERDES_TH_LOS_MASK)
#define PCIE_PHY_REG_1_SERDES_TH_LOS_RESET                                     0x2
#define PCIE_PHY_REG_1_SERDES_EN_DEEMP_LSB                                     5
#define PCIE_PHY_REG_1_SERDES_EN_DEEMP_MSB                                     5
#define PCIE_PHY_REG_1_SERDES_EN_DEEMP_MASK                                    0x20
#define PCIE_PHY_REG_1_SERDES_EN_DEEMP_GET(x)                                  (((x) & PCIE_PHY_REG_1_SERDES_EN_DEEMP_MASK) >> PCIE_PHY_REG_1_SERDES_EN_DEEMP_LSB)
#define PCIE_PHY_REG_1_SERDES_EN_DEEMP_SET(x)                                  (((0 | (x)) << PCIE_PHY_REG_1_SERDES_EN_DEEMP_LSB) & PCIE_PHY_REG_1_SERDES_EN_DEEMP_MASK)
#define PCIE_PHY_REG_1_SERDES_EN_DEEMP_RESET                                   0x1
#define PCIE_PHY_REG_1_SERDES_SEL_HSP_LSB                                      4
#define PCIE_PHY_REG_1_SERDES_SEL_HSP_MSB                                      4
#define PCIE_PHY_REG_1_SERDES_SEL_HSP_MASK                                     0x10
#define PCIE_PHY_REG_1_SERDES_SEL_HSP_GET(x)                                   (((x) & PCIE_PHY_REG_1_SERDES_SEL_HSP_MASK) >> PCIE_PHY_REG_1_SERDES_SEL_HSP_LSB)
#define PCIE_PHY_REG_1_SERDES_SEL_HSP_SET(x)                                   (((0 | (x)) << PCIE_PHY_REG_1_SERDES_SEL_HSP_LSB) & PCIE_PHY_REG_1_SERDES_SEL_HSP_MASK)
#define PCIE_PHY_REG_1_SERDES_SEL_HSP_RESET                                    0x0
#define PCIE_PHY_REG_1_S_LSB                                                   0
#define PCIE_PHY_REG_1_S_MSB                                                   3
#define PCIE_PHY_REG_1_S_MASK                                                  0xf
#define PCIE_PHY_REG_1_S_GET(x)                                                (((x) & PCIE_PHY_REG_1_S_MASK) >> PCIE_PHY_REG_1_S_LSB)
#define PCIE_PHY_REG_1_S_SET(x)                                                (((0 | (x)) << PCIE_PHY_REG_1_S_LSB) & PCIE_PHY_REG_1_S_MASK)
#define PCIE_PHY_REG_1_S_RESET                                                 0x1
#define PCIE_PHY_REG_1_ADDRESS                                                 (0x0 + __PCIE_PHY_REG_CSR_BASE_ADDRESS)
#define PCIE_PHY_REG_1_RSTMASK                                                 0xffffffff
#define PCIE_PHY_REG_1_RESET                                                   0x122a1

// 0x4 (PCIE_PHY_REG_2)
#define PCIE_PHY_REG_2_LCKDT_OUT_LSB                                           31
#define PCIE_PHY_REG_2_LCKDT_OUT_MSB                                           31
#define PCIE_PHY_REG_2_LCKDT_OUT_MASK                                          0x80000000
#define PCIE_PHY_REG_2_LCKDT_OUT_GET(x)                                        (((x) & PCIE_PHY_REG_2_LCKDT_OUT_MASK) >> PCIE_PHY_REG_2_LCKDT_OUT_LSB)
#define PCIE_PHY_REG_2_LCKDT_OUT_SET(x)                                        (((0 | (x)) << PCIE_PHY_REG_2_LCKDT_OUT_LSB) & PCIE_PHY_REG_2_LCKDT_OUT_MASK)
#define PCIE_PHY_REG_2_LCKDT_OUT_RESET                                         0x0
#define PCIE_PHY_REG_2_PRBS_ERROR_COUNT_LSB                                    23
#define PCIE_PHY_REG_2_PRBS_ERROR_COUNT_MSB                                    30
#define PCIE_PHY_REG_2_PRBS_ERROR_COUNT_MASK                                   0x7f800000
#define PCIE_PHY_REG_2_PRBS_ERROR_COUNT_GET(x)                                 (((x) & PCIE_PHY_REG_2_PRBS_ERROR_COUNT_MASK) >> PCIE_PHY_REG_2_PRBS_ERROR_COUNT_LSB)
#define PCIE_PHY_REG_2_PRBS_ERROR_COUNT_SET(x)                                 (((0 | (x)) << PCIE_PHY_REG_2_PRBS_ERROR_COUNT_LSB) & PCIE_PHY_REG_2_PRBS_ERROR_COUNT_MASK)
#define PCIE_PHY_REG_2_PRBS_ERROR_COUNT_RESET                                  0x0
#define PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_LSB                                  22
#define PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_MSB                                  22
#define PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_MASK                                 0x400000
#define PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_GET(x)                               (((x) & PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_MASK) >> PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_LSB)
#define PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_SET(x)                               (((0 | (x)) << PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_LSB) & PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_MASK)
#define PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_RESET                                0x0
#define PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_LSB                                  21
#define PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_MSB                                  21
#define PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_MASK                                 0x200000
#define PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_GET(x)                               (((x) & PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_MASK) >> PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_LSB)
#define PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_SET(x)                               (((0 | (x)) << PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_LSB) & PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_MASK)
#define PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_RESET                                0x0
#define PCIE_PHY_REG_2_PRBS_SCRAMBLE_LSB                                       20
#define PCIE_PHY_REG_2_PRBS_SCRAMBLE_MSB                                       20
#define PCIE_PHY_REG_2_PRBS_SCRAMBLE_MASK                                      0x100000
#define PCIE_PHY_REG_2_PRBS_SCRAMBLE_GET(x)                                    (((x) & PCIE_PHY_REG_2_PRBS_SCRAMBLE_MASK) >> PCIE_PHY_REG_2_PRBS_SCRAMBLE_LSB)
#define PCIE_PHY_REG_2_PRBS_SCRAMBLE_SET(x)                                    (((0 | (x)) << PCIE_PHY_REG_2_PRBS_SCRAMBLE_LSB) & PCIE_PHY_REG_2_PRBS_SCRAMBLE_MASK)
#define PCIE_PHY_REG_2_PRBS_SCRAMBLE_RESET                                     0x0
#define PCIE_PHY_REG_2_PRBS_START_LSB                                          19
#define PCIE_PHY_REG_2_PRBS_START_MSB                                          19
#define PCIE_PHY_REG_2_PRBS_START_MASK                                         0x80000
#define PCIE_PHY_REG_2_PRBS_START_GET(x)                                       (((x) & PCIE_PHY_REG_2_PRBS_START_MASK) >> PCIE_PHY_REG_2_PRBS_START_LSB)
#define PCIE_PHY_REG_2_PRBS_START_SET(x)                                       (((0 | (x)) << PCIE_PHY_REG_2_PRBS_START_LSB) & PCIE_PHY_REG_2_PRBS_START_MASK)
#define PCIE_PHY_REG_2_PRBS_START_RESET                                        0x0
#define PCIE_PHY_REG_2_PRBS_TS_NUM_LSB                                         12
#define PCIE_PHY_REG_2_PRBS_TS_NUM_MSB                                         18
#define PCIE_PHY_REG_2_PRBS_TS_NUM_MASK                                        0x7f000
#define PCIE_PHY_REG_2_PRBS_TS_NUM_GET(x)                                      (((x) & PCIE_PHY_REG_2_PRBS_TS_NUM_MASK) >> PCIE_PHY_REG_2_PRBS_TS_NUM_LSB)
#define PCIE_PHY_REG_2_PRBS_TS_NUM_SET(x)                                      (((0 | (x)) << PCIE_PHY_REG_2_PRBS_TS_NUM_LSB) & PCIE_PHY_REG_2_PRBS_TS_NUM_MASK)
#define PCIE_PHY_REG_2_PRBS_TS_NUM_RESET                                       0x40
#define PCIE_PHY_REG_2_TXDETRXOVRVALUE_LSB                                     11
#define PCIE_PHY_REG_2_TXDETRXOVRVALUE_MSB                                     11
#define PCIE_PHY_REG_2_TXDETRXOVRVALUE_MASK                                    0x800
#define PCIE_PHY_REG_2_TXDETRXOVRVALUE_GET(x)                                  (((x) & PCIE_PHY_REG_2_TXDETRXOVRVALUE_MASK) >> PCIE_PHY_REG_2_TXDETRXOVRVALUE_LSB)
#define PCIE_PHY_REG_2_TXDETRXOVRVALUE_SET(x)                                  (((0 | (x)) << PCIE_PHY_REG_2_TXDETRXOVRVALUE_LSB) & PCIE_PHY_REG_2_TXDETRXOVRVALUE_MASK)
#define PCIE_PHY_REG_2_TXDETRXOVRVALUE_RESET                                   0x0
#define PCIE_PHY_REG_2_TXDETRXOVREN_LSB                                        10
#define PCIE_PHY_REG_2_TXDETRXOVREN_MSB                                        10
#define PCIE_PHY_REG_2_TXDETRXOVREN_MASK                                       0x400
#define PCIE_PHY_REG_2_TXDETRXOVREN_GET(x)                                     (((x) & PCIE_PHY_REG_2_TXDETRXOVREN_MASK) >> PCIE_PHY_REG_2_TXDETRXOVREN_LSB)
#define PCIE_PHY_REG_2_TXDETRXOVREN_SET(x)                                     (((0 | (x)) << PCIE_PHY_REG_2_TXDETRXOVREN_LSB) & PCIE_PHY_REG_2_TXDETRXOVREN_MASK)
#define PCIE_PHY_REG_2_TXDETRXOVREN_RESET                                      0x0
#define PCIE_PHY_REG_2_CDRREADYTIMER_LSB                                       6
#define PCIE_PHY_REG_2_CDRREADYTIMER_MSB                                       9
#define PCIE_PHY_REG_2_CDRREADYTIMER_MASK                                      0x3c0
#define PCIE_PHY_REG_2_CDRREADYTIMER_GET(x)                                    (((x) & PCIE_PHY_REG_2_CDRREADYTIMER_MASK) >> PCIE_PHY_REG_2_CDRREADYTIMER_LSB)
#define PCIE_PHY_REG_2_CDRREADYTIMER_SET(x)                                    (((0 | (x)) << PCIE_PHY_REG_2_CDRREADYTIMER_LSB) & PCIE_PHY_REG_2_CDRREADYTIMER_MASK)
#define PCIE_PHY_REG_2_CDRREADYTIMER_RESET                                     0x7
#define PCIE_PHY_REG_2_TXDETRXTARGETDELAY_LSB                                  1
#define PCIE_PHY_REG_2_TXDETRXTARGETDELAY_MSB                                  5
#define PCIE_PHY_REG_2_TXDETRXTARGETDELAY_MASK                                 0x3e
#define PCIE_PHY_REG_2_TXDETRXTARGETDELAY_GET(x)                               (((x) & PCIE_PHY_REG_2_TXDETRXTARGETDELAY_MASK) >> PCIE_PHY_REG_2_TXDETRXTARGETDELAY_LSB)
#define PCIE_PHY_REG_2_TXDETRXTARGETDELAY_SET(x)                               (((0 | (x)) << PCIE_PHY_REG_2_TXDETRXTARGETDELAY_LSB) & PCIE_PHY_REG_2_TXDETRXTARGETDELAY_MASK)
#define PCIE_PHY_REG_2_TXDETRXTARGETDELAY_RESET                                0xc
#define PCIE_PHY_REG_2_FORCEDETECT_LSB                                         0
#define PCIE_PHY_REG_2_FORCEDETECT_MSB                                         0
#define PCIE_PHY_REG_2_FORCEDETECT_MASK                                        0x1
#define PCIE_PHY_REG_2_FORCEDETECT_GET(x)                                      (((x) & PCIE_PHY_REG_2_FORCEDETECT_MASK) >> PCIE_PHY_REG_2_FORCEDETECT_LSB)
#define PCIE_PHY_REG_2_FORCEDETECT_SET(x)                                      (((0 | (x)) << PCIE_PHY_REG_2_FORCEDETECT_LSB) & PCIE_PHY_REG_2_FORCEDETECT_MASK)
#define PCIE_PHY_REG_2_FORCEDETECT_RESET                                       0x0
#define PCIE_PHY_REG_2_ADDRESS                                                 (0x4 + __PCIE_PHY_REG_CSR_BASE_ADDRESS)
#define PCIE_PHY_REG_2_RSTMASK                                                 0xffffffff
#define PCIE_PHY_REG_2_RESET                                                   0x401d8

// 0x8 (PCIE_PHY_REG_3)
#define PCIE_PHY_REG_3_SERDES_RSV_7_4_LSB                                      28
#define PCIE_PHY_REG_3_SERDES_RSV_7_4_MSB                                      31
#define PCIE_PHY_REG_3_SERDES_RSV_7_4_MASK                                     0xf0000000
#define PCIE_PHY_REG_3_SERDES_RSV_7_4_GET(x)                                   (((x) & PCIE_PHY_REG_3_SERDES_RSV_7_4_MASK) >> PCIE_PHY_REG_3_SERDES_RSV_7_4_LSB)
#define PCIE_PHY_REG_3_SERDES_RSV_7_4_SET(x)                                   (((0 | (x)) << PCIE_PHY_REG_3_SERDES_RSV_7_4_LSB) & PCIE_PHY_REG_3_SERDES_RSV_7_4_MASK)
#define PCIE_PHY_REG_3_SERDES_RSV_7_4_RESET                                    0x0
#define PCIE_PHY_REG_3_SERDES_TH_DAT_LSB                                       25
#define PCIE_PHY_REG_3_SERDES_TH_DAT_MSB                                       27
#define PCIE_PHY_REG_3_SERDES_TH_DAT_MASK                                      0xe000000
#define PCIE_PHY_REG_3_SERDES_TH_DAT_GET(x)                                    (((x) & PCIE_PHY_REG_3_SERDES_TH_DAT_MASK) >> PCIE_PHY_REG_3_SERDES_TH_DAT_LSB)
#define PCIE_PHY_REG_3_SERDES_TH_DAT_SET(x)                                    (((0 | (x)) << PCIE_PHY_REG_3_SERDES_TH_DAT_LSB) & PCIE_PHY_REG_3_SERDES_TH_DAT_MASK)
#define PCIE_PHY_REG_3_SERDES_TH_DAT_RESET                                     0x3
#define PCIE_PHY_REG_3_SERDES_SEL_LOS_LSB                                      24
#define PCIE_PHY_REG_3_SERDES_SEL_LOS_MSB                                      24
#define PCIE_PHY_REG_3_SERDES_SEL_LOS_MASK                                     0x1000000
#define PCIE_PHY_REG_3_SERDES_SEL_LOS_GET(x)                                   (((x) & PCIE_PHY_REG_3_SERDES_SEL_LOS_MASK) >> PCIE_PHY_REG_3_SERDES_SEL_LOS_LSB)
#define PCIE_PHY_REG_3_SERDES_SEL_LOS_SET(x)                                   (((0 | (x)) << PCIE_PHY_REG_3_SERDES_SEL_LOS_LSB) & PCIE_PHY_REG_3_SERDES_SEL_LOS_MASK)
#define PCIE_PHY_REG_3_SERDES_SEL_LOS_RESET                                    0x0
#define PCIE_PHY_REG_3_SERDES_CDR_STEP_LSB                                     23
#define PCIE_PHY_REG_3_SERDES_CDR_STEP_MSB                                     23
#define PCIE_PHY_REG_3_SERDES_CDR_STEP_MASK                                    0x800000
#define PCIE_PHY_REG_3_SERDES_CDR_STEP_GET(x)                                  (((x) & PCIE_PHY_REG_3_SERDES_CDR_STEP_MASK) >> PCIE_PHY_REG_3_SERDES_CDR_STEP_LSB)
#define PCIE_PHY_REG_3_SERDES_CDR_STEP_SET(x)                                  (((0 | (x)) << PCIE_PHY_REG_3_SERDES_CDR_STEP_LSB) & PCIE_PHY_REG_3_SERDES_CDR_STEP_MASK)
#define PCIE_PHY_REG_3_SERDES_CDR_STEP_RESET                                   0x0
#define PCIE_PHY_REG_3_SERDES_EN_REFCLK_LSB                                    22
#define PCIE_PHY_REG_3_SERDES_EN_REFCLK_MSB                                    22
#define PCIE_PHY_REG_3_SERDES_EN_REFCLK_MASK                                   0x400000
#define PCIE_PHY_REG_3_SERDES_EN_REFCLK_GET(x)                                 (((x) & PCIE_PHY_REG_3_SERDES_EN_REFCLK_MASK) >> PCIE_PHY_REG_3_SERDES_EN_REFCLK_LSB)
#define PCIE_PHY_REG_3_SERDES_EN_REFCLK_SET(x)                                 (((0 | (x)) << PCIE_PHY_REG_3_SERDES_EN_REFCLK_LSB) & PCIE_PHY_REG_3_SERDES_EN_REFCLK_MASK)
#define PCIE_PHY_REG_3_SERDES_EN_REFCLK_RESET                                  0x0
#define PCIE_PHY_REG_3_SERDES_LPF_LOS_LSB                                      19
#define PCIE_PHY_REG_3_SERDES_LPF_LOS_MSB                                      21
#define PCIE_PHY_REG_3_SERDES_LPF_LOS_MASK                                     0x380000
#define PCIE_PHY_REG_3_SERDES_LPF_LOS_GET(x)                                   (((x) & PCIE_PHY_REG_3_SERDES_LPF_LOS_MASK) >> PCIE_PHY_REG_3_SERDES_LPF_LOS_LSB)
#define PCIE_PHY_REG_3_SERDES_LPF_LOS_SET(x)                                   (((0 | (x)) << PCIE_PHY_REG_3_SERDES_LPF_LOS_LSB) & PCIE_PHY_REG_3_SERDES_LPF_LOS_MASK)
#define PCIE_PHY_REG_3_SERDES_LPF_LOS_RESET                                    0x1
#define PCIE_PHY_REG_3_SERDES_CDR_RCK_SEL_LSB                                  18
#define PCIE_PHY_REG_3_SERDES_CDR_RCK_SEL_MSB                                  18
#define PCIE_PHY_REG_3_SERDES_CDR_RCK_SEL_MASK                                 0x40000
#define PCIE_PHY_REG_3_SERDES_CDR_RCK_SEL_GET(x)                               (((x) & PCIE_PHY_REG_3_SERDES_CDR_RCK_SEL_MASK) >> PCIE_PHY_REG_3_SERDES_CDR_RCK_SEL_LSB)
#define PCIE_PHY_REG_3_SERDES_CDR_RCK_SEL_SET(x)                               (((0 | (x)) << PCIE_PHY_REG_3_SERDES_CDR_RCK_SEL_LSB) & PCIE_PHY_REG_3_SERDES_CDR_RCK_SEL_MASK)
#define PCIE_PHY_REG_3_SERDES_CDR_RCK_SEL_RESET                                0x1
#define PCIE_PHY_REG_3_SERDES_OFFB_LSB                                         17
#define PCIE_PHY_REG_3_SERDES_OFFB_MSB                                         17
#define PCIE_PHY_REG_3_SERDES_OFFB_MASK                                        0x20000
#define PCIE_PHY_REG_3_SERDES_OFFB_GET(x)                                      (((x) & PCIE_PHY_REG_3_SERDES_OFFB_MASK) >> PCIE_PHY_REG_3_SERDES_OFFB_LSB)
#define PCIE_PHY_REG_3_SERDES_OFFB_SET(x)                                      (((0 | (x)) << PCIE_PHY_REG_3_SERDES_OFFB_LSB) & PCIE_PHY_REG_3_SERDES_OFFB_MASK)
#define PCIE_PHY_REG_3_SERDES_OFFB_RESET                                       0x1
#define PCIE_PHY_REG_3_SERDES_PLL_BW_LSB                                       16
#define PCIE_PHY_REG_3_SERDES_PLL_BW_MSB                                       16
#define PCIE_PHY_REG_3_SERDES_PLL_BW_MASK                                      0x10000
#define PCIE_PHY_REG_3_SERDES_PLL_BW_GET(x)                                    (((x) & PCIE_PHY_REG_3_SERDES_PLL_BW_MASK) >> PCIE_PHY_REG_3_SERDES_PLL_BW_LSB)
#define PCIE_PHY_REG_3_SERDES_PLL_BW_SET(x)                                    (((0 | (x)) << PCIE_PHY_REG_3_SERDES_PLL_BW_LSB) & PCIE_PHY_REG_3_SERDES_PLL_BW_MASK)
#define PCIE_PHY_REG_3_SERDES_PLL_BW_RESET                                     0x0
#define PCIE_PHY_REG_3_SERDES_CDR_DMT_LSB                                      15
#define PCIE_PHY_REG_3_SERDES_CDR_DMT_MSB                                      15
#define PCIE_PHY_REG_3_SERDES_CDR_DMT_MASK                                     0x8000
#define PCIE_PHY_REG_3_SERDES_CDR_DMT_GET(x)                                   (((x) & PCIE_PHY_REG_3_SERDES_CDR_DMT_MASK) >> PCIE_PHY_REG_3_SERDES_CDR_DMT_LSB)
#define PCIE_PHY_REG_3_SERDES_CDR_DMT_SET(x)                                   (((0 | (x)) << PCIE_PHY_REG_3_SERDES_CDR_DMT_LSB) & PCIE_PHY_REG_3_SERDES_CDR_DMT_MASK)
#define PCIE_PHY_REG_3_SERDES_CDR_DMT_RESET                                    0x0
#define PCIE_PHY_REG_3_SERDES_TX_AMP_LSB                                       12
#define PCIE_PHY_REG_3_SERDES_TX_AMP_MSB                                       14
#define PCIE_PHY_REG_3_SERDES_TX_AMP_MASK                                      0x7000
#define PCIE_PHY_REG_3_SERDES_TX_AMP_GET(x)                                    (((x) & PCIE_PHY_REG_3_SERDES_TX_AMP_MASK) >> PCIE_PHY_REG_3_SERDES_TX_AMP_LSB)
#define PCIE_PHY_REG_3_SERDES_TX_AMP_SET(x)                                    (((0 | (x)) << PCIE_PHY_REG_3_SERDES_TX_AMP_LSB) & PCIE_PHY_REG_3_SERDES_TX_AMP_MASK)
#define PCIE_PHY_REG_3_SERDES_TX_AMP_RESET                                     0x3
#define PCIE_PHY_REG_3_SERDES_RSV_3_0_LSB                                      8
#define PCIE_PHY_REG_3_SERDES_RSV_3_0_MSB                                      11
#define PCIE_PHY_REG_3_SERDES_RSV_3_0_MASK                                     0xf00
#define PCIE_PHY_REG_3_SERDES_RSV_3_0_GET(x)                                   (((x) & PCIE_PHY_REG_3_SERDES_RSV_3_0_MASK) >> PCIE_PHY_REG_3_SERDES_RSV_3_0_LSB)
#define PCIE_PHY_REG_3_SERDES_RSV_3_0_SET(x)                                   (((0 | (x)) << PCIE_PHY_REG_3_SERDES_RSV_3_0_LSB) & PCIE_PHY_REG_3_SERDES_RSV_3_0_MASK)
#define PCIE_PHY_REG_3_SERDES_RSV_3_0_RESET                                    0x2
#define PCIE_PHY_REG_3_SPARE_LSB                                               7
#define PCIE_PHY_REG_3_SPARE_MSB                                               7
#define PCIE_PHY_REG_3_SPARE_MASK                                              0x80
#define PCIE_PHY_REG_3_SPARE_GET(x)                                            (((x) & PCIE_PHY_REG_3_SPARE_MASK) >> PCIE_PHY_REG_3_SPARE_LSB)
#define PCIE_PHY_REG_3_SPARE_SET(x)                                            (((0 | (x)) << PCIE_PHY_REG_3_SPARE_LSB) & PCIE_PHY_REG_3_SPARE_MASK)
#define PCIE_PHY_REG_3_SPARE_RESET                                             0x1
#define PCIE_PHY_REG_3_EN_BEACONGEN_LSB                                        6
#define PCIE_PHY_REG_3_EN_BEACONGEN_MSB                                        6
#define PCIE_PHY_REG_3_EN_BEACONGEN_MASK                                       0x40
#define PCIE_PHY_REG_3_EN_BEACONGEN_GET(x)                                     (((x) & PCIE_PHY_REG_3_EN_BEACONGEN_MASK) >> PCIE_PHY_REG_3_EN_BEACONGEN_LSB)
#define PCIE_PHY_REG_3_EN_BEACONGEN_SET(x)                                     (((0 | (x)) << PCIE_PHY_REG_3_EN_BEACONGEN_LSB) & PCIE_PHY_REG_3_EN_BEACONGEN_MASK)
#define PCIE_PHY_REG_3_EN_BEACONGEN_RESET                                      0x0
#define PCIE_PHY_REG_3_TXELECIDLE_LSB                                          5
#define PCIE_PHY_REG_3_TXELECIDLE_MSB                                          5
#define PCIE_PHY_REG_3_TXELECIDLE_MASK                                         0x20
#define PCIE_PHY_REG_3_TXELECIDLE_GET(x)                                       (((x) & PCIE_PHY_REG_3_TXELECIDLE_MASK) >> PCIE_PHY_REG_3_TXELECIDLE_LSB)
#define PCIE_PHY_REG_3_TXELECIDLE_SET(x)                                       (((0 | (x)) << PCIE_PHY_REG_3_TXELECIDLE_LSB) & PCIE_PHY_REG_3_TXELECIDLE_MASK)
#define PCIE_PHY_REG_3_TXELECIDLE_RESET                                        0x0
#define PCIE_PHY_REG_3_RX_DET_REQ_LSB                                          4
#define PCIE_PHY_REG_3_RX_DET_REQ_MSB                                          4
#define PCIE_PHY_REG_3_RX_DET_REQ_MASK                                         0x10
#define PCIE_PHY_REG_3_RX_DET_REQ_GET(x)                                       (((x) & PCIE_PHY_REG_3_RX_DET_REQ_MASK) >> PCIE_PHY_REG_3_RX_DET_REQ_LSB)
#define PCIE_PHY_REG_3_RX_DET_REQ_SET(x)                                       (((0 | (x)) << PCIE_PHY_REG_3_RX_DET_REQ_LSB) & PCIE_PHY_REG_3_RX_DET_REQ_MASK)
#define PCIE_PHY_REG_3_RX_DET_REQ_RESET                                        0x0
#define PCIE_PHY_REG_3_EN_PLL_LSB                                              3
#define PCIE_PHY_REG_3_EN_PLL_MSB                                              3
#define PCIE_PHY_REG_3_EN_PLL_MASK                                             0x8
#define PCIE_PHY_REG_3_EN_PLL_GET(x)                                           (((x) & PCIE_PHY_REG_3_EN_PLL_MASK) >> PCIE_PHY_REG_3_EN_PLL_LSB)
#define PCIE_PHY_REG_3_EN_PLL_SET(x)                                           (((0 | (x)) << PCIE_PHY_REG_3_EN_PLL_LSB) & PCIE_PHY_REG_3_EN_PLL_MASK)
#define PCIE_PHY_REG_3_EN_PLL_RESET                                            0x1
#define PCIE_PHY_REG_3_EN_LCKDT_LSB                                            2
#define PCIE_PHY_REG_3_EN_LCKDT_MSB                                            2
#define PCIE_PHY_REG_3_EN_LCKDT_MASK                                           0x4
#define PCIE_PHY_REG_3_EN_LCKDT_GET(x)                                         (((x) & PCIE_PHY_REG_3_EN_LCKDT_MASK) >> PCIE_PHY_REG_3_EN_LCKDT_LSB)
#define PCIE_PHY_REG_3_EN_LCKDT_SET(x)                                         (((0 | (x)) << PCIE_PHY_REG_3_EN_LCKDT_LSB) & PCIE_PHY_REG_3_EN_LCKDT_MASK)
#define PCIE_PHY_REG_3_EN_LCKDT_RESET                                          0x1
#define PCIE_PHY_REG_3_EN_BUFS_RX_LSB                                          1
#define PCIE_PHY_REG_3_EN_BUFS_RX_MSB                                          1
#define PCIE_PHY_REG_3_EN_BUFS_RX_MASK                                         0x2
#define PCIE_PHY_REG_3_EN_BUFS_RX_GET(x)                                       (((x) & PCIE_PHY_REG_3_EN_BUFS_RX_MASK) >> PCIE_PHY_REG_3_EN_BUFS_RX_LSB)
#define PCIE_PHY_REG_3_EN_BUFS_RX_SET(x)                                       (((0 | (x)) << PCIE_PHY_REG_3_EN_BUFS_RX_LSB) & PCIE_PHY_REG_3_EN_BUFS_RX_MASK)
#define PCIE_PHY_REG_3_EN_BUFS_RX_RESET                                        0x0
#define PCIE_PHY_REG_3_EN_LSB                                                  0
#define PCIE_PHY_REG_3_EN_MSB                                                  0
#define PCIE_PHY_REG_3_EN_MASK                                                 0x1
#define PCIE_PHY_REG_3_EN_GET(x)                                               (((x) & PCIE_PHY_REG_3_EN_MASK) >> PCIE_PHY_REG_3_EN_LSB)
#define PCIE_PHY_REG_3_EN_SET(x)                                               (((0 | (x)) << PCIE_PHY_REG_3_EN_LSB) & PCIE_PHY_REG_3_EN_MASK)
#define PCIE_PHY_REG_3_EN_RESET                                                0x0
#define PCIE_PHY_REG_3_ADDRESS                                                 (0x8 + __PCIE_PHY_REG_CSR_BASE_ADDRESS)
#define PCIE_PHY_REG_3_RSTMASK                                                 0xffffffff
#define PCIE_PHY_REG_3_RESET                                                   0x60e328c

// 0xc (PCIE_PHY_REG_4)
#define PCIE_PHY_REG_4_CLK_SWITCH_WAIT_EXT_VALUE_LSB                           29
#define PCIE_PHY_REG_4_CLK_SWITCH_WAIT_EXT_VALUE_MSB                           31
#define PCIE_PHY_REG_4_CLK_SWITCH_WAIT_EXT_VALUE_MASK                          0xe0000000
#define PCIE_PHY_REG_4_CLK_SWITCH_WAIT_EXT_VALUE_GET(x)                        (((x) & PCIE_PHY_REG_4_CLK_SWITCH_WAIT_EXT_VALUE_MASK) >> PCIE_PHY_REG_4_CLK_SWITCH_WAIT_EXT_VALUE_LSB)
#define PCIE_PHY_REG_4_CLK_SWITCH_WAIT_EXT_VALUE_SET(x)                        (((0 | (x)) << PCIE_PHY_REG_4_CLK_SWITCH_WAIT_EXT_VALUE_LSB) & PCIE_PHY_REG_4_CLK_SWITCH_WAIT_EXT_VALUE_MASK)
#define PCIE_PHY_REG_4_CLK_SWITCH_WAIT_EXT_VALUE_RESET                         0x0
#define PCIE_PHY_REG_4_REFCLK_DET_DISABLE_LSB                                  28
#define PCIE_PHY_REG_4_REFCLK_DET_DISABLE_MSB                                  28
#define PCIE_PHY_REG_4_REFCLK_DET_DISABLE_MASK                                 0x10000000
#define PCIE_PHY_REG_4_REFCLK_DET_DISABLE_GET(x)                               (((x) & PCIE_PHY_REG_4_REFCLK_DET_DISABLE_MASK) >> PCIE_PHY_REG_4_REFCLK_DET_DISABLE_LSB)
#define PCIE_PHY_REG_4_REFCLK_DET_DISABLE_SET(x)                               (((0 | (x)) << PCIE_PHY_REG_4_REFCLK_DET_DISABLE_LSB) & PCIE_PHY_REG_4_REFCLK_DET_DISABLE_MASK)
#define PCIE_PHY_REG_4_REFCLK_DET_DISABLE_RESET                                0x0
#define PCIE_PHY_REG_4_REFCLK_WAIT_VALUE_LSB                                   24
#define PCIE_PHY_REG_4_REFCLK_WAIT_VALUE_MSB                                   27
#define PCIE_PHY_REG_4_REFCLK_WAIT_VALUE_MASK                                  0xf000000
#define PCIE_PHY_REG_4_REFCLK_WAIT_VALUE_GET(x)                                (((x) & PCIE_PHY_REG_4_REFCLK_WAIT_VALUE_MASK) >> PCIE_PHY_REG_4_REFCLK_WAIT_VALUE_LSB)
#define PCIE_PHY_REG_4_REFCLK_WAIT_VALUE_SET(x)                                (((0 | (x)) << PCIE_PHY_REG_4_REFCLK_WAIT_VALUE_LSB) & PCIE_PHY_REG_4_REFCLK_WAIT_VALUE_MASK)
#define PCIE_PHY_REG_4_REFCLK_WAIT_VALUE_RESET                                 0x2
#define PCIE_PHY_REG_4_CLK_SWITCH_WAIT_VALUE_LSB                               12
#define PCIE_PHY_REG_4_CLK_SWITCH_WAIT_VALUE_MSB                               23
#define PCIE_PHY_REG_4_CLK_SWITCH_WAIT_VALUE_MASK                              0xfff000
#define PCIE_PHY_REG_4_CLK_SWITCH_WAIT_VALUE_GET(x)                            (((x) & PCIE_PHY_REG_4_CLK_SWITCH_WAIT_VALUE_MASK) >> PCIE_PHY_REG_4_CLK_SWITCH_WAIT_VALUE_LSB)
#define PCIE_PHY_REG_4_CLK_SWITCH_WAIT_VALUE_SET(x)                            (((0 | (x)) << PCIE_PHY_REG_4_CLK_SWITCH_WAIT_VALUE_LSB) & PCIE_PHY_REG_4_CLK_SWITCH_WAIT_VALUE_MASK)
#define PCIE_PHY_REG_4_CLK_SWITCH_WAIT_VALUE_RESET                             0x3c
#define PCIE_PHY_REG_4_PLL_SETTLE_TIME_LSB                                     0
#define PCIE_PHY_REG_4_PLL_SETTLE_TIME_MSB                                     11
#define PCIE_PHY_REG_4_PLL_SETTLE_TIME_MASK                                    0xfff
#define PCIE_PHY_REG_4_PLL_SETTLE_TIME_GET(x)                                  (((x) & PCIE_PHY_REG_4_PLL_SETTLE_TIME_MASK) >> PCIE_PHY_REG_4_PLL_SETTLE_TIME_LSB)
#define PCIE_PHY_REG_4_PLL_SETTLE_TIME_SET(x)                                  (((0 | (x)) << PCIE_PHY_REG_4_PLL_SETTLE_TIME_LSB) & PCIE_PHY_REG_4_PLL_SETTLE_TIME_MASK)
#define PCIE_PHY_REG_4_PLL_SETTLE_TIME_RESET                                   0x48
#define PCIE_PHY_REG_4_ADDRESS                                                 (0xc + __PCIE_PHY_REG_CSR_BASE_ADDRESS)
#define PCIE_PHY_REG_4_RSTMASK                                                 0xffffffff
#define PCIE_PHY_REG_4_RESET                                                   0x203c048

// 0x10 (PCIE_PHY_REG_5)
#define PCIE_PHY_REG_5_ENABLECLKREQ_PRSTN_LSB                                  28
#define PCIE_PHY_REG_5_ENABLECLKREQ_PRSTN_MSB                                  28
#define PCIE_PHY_REG_5_ENABLECLKREQ_PRSTN_MASK                                 0x10000000
#define PCIE_PHY_REG_5_ENABLECLKREQ_PRSTN_GET(x)                               (((x) & PCIE_PHY_REG_5_ENABLECLKREQ_PRSTN_MASK) >> PCIE_PHY_REG_5_ENABLECLKREQ_PRSTN_LSB)
#define PCIE_PHY_REG_5_ENABLECLKREQ_PRSTN_SET(x)                               (((0 | (x)) << PCIE_PHY_REG_5_ENABLECLKREQ_PRSTN_LSB) & PCIE_PHY_REG_5_ENABLECLKREQ_PRSTN_MASK)
#define PCIE_PHY_REG_5_ENABLECLKREQ_PRSTN_RESET                                0x0
#define PCIE_PHY_REG_5_PLL_FSLCK_TIME_LSB                                      16
#define PCIE_PHY_REG_5_PLL_FSLCK_TIME_MSB                                      27
#define PCIE_PHY_REG_5_PLL_FSLCK_TIME_MASK                                     0xfff0000
#define PCIE_PHY_REG_5_PLL_FSLCK_TIME_GET(x)                                   (((x) & PCIE_PHY_REG_5_PLL_FSLCK_TIME_MASK) >> PCIE_PHY_REG_5_PLL_FSLCK_TIME_LSB)
#define PCIE_PHY_REG_5_PLL_FSLCK_TIME_SET(x)                                   (((0 | (x)) << PCIE_PHY_REG_5_PLL_FSLCK_TIME_LSB) & PCIE_PHY_REG_5_PLL_FSLCK_TIME_MASK)
#define PCIE_PHY_REG_5_PLL_FSLCK_TIME_RESET                                    0x5
#define PCIE_PHY_REG_5_RESERVE_LSB                                             14
#define PCIE_PHY_REG_5_RESERVE_MSB                                             15
#define PCIE_PHY_REG_5_RESERVE_MASK                                            0xc000
#define PCIE_PHY_REG_5_RESERVE_GET(x)                                          (((x) & PCIE_PHY_REG_5_RESERVE_MASK) >> PCIE_PHY_REG_5_RESERVE_LSB)
#define PCIE_PHY_REG_5_RESERVE_SET(x)                                          (((0 | (x)) << PCIE_PHY_REG_5_RESERVE_LSB) & PCIE_PHY_REG_5_RESERVE_MASK)
#define PCIE_PHY_REG_5_RESERVE_RESET                                           0x0
#define PCIE_PHY_REG_5_TXDETECTRX_REFCLK_DETECT_LSB                            13
#define PCIE_PHY_REG_5_TXDETECTRX_REFCLK_DETECT_MSB                            13
#define PCIE_PHY_REG_5_TXDETECTRX_REFCLK_DETECT_MASK                           0x2000
#define PCIE_PHY_REG_5_TXDETECTRX_REFCLK_DETECT_GET(x)                         (((x) & PCIE_PHY_REG_5_TXDETECTRX_REFCLK_DETECT_MASK) >> PCIE_PHY_REG_5_TXDETECTRX_REFCLK_DETECT_LSB)
#define PCIE_PHY_REG_5_TXDETECTRX_REFCLK_DETECT_SET(x)                         (((0 | (x)) << PCIE_PHY_REG_5_TXDETECTRX_REFCLK_DETECT_LSB) & PCIE_PHY_REG_5_TXDETECTRX_REFCLK_DETECT_MASK)
#define PCIE_PHY_REG_5_TXDETECTRX_REFCLK_DETECT_RESET                          0x1
#define PCIE_PHY_REG_5_DIS_TXCM_PERST_DISABLE_N_LSB                            12
#define PCIE_PHY_REG_5_DIS_TXCM_PERST_DISABLE_N_MSB                            12
#define PCIE_PHY_REG_5_DIS_TXCM_PERST_DISABLE_N_MASK                           0x1000
#define PCIE_PHY_REG_5_DIS_TXCM_PERST_DISABLE_N_GET(x)                         (((x) & PCIE_PHY_REG_5_DIS_TXCM_PERST_DISABLE_N_MASK) >> PCIE_PHY_REG_5_DIS_TXCM_PERST_DISABLE_N_LSB)
#define PCIE_PHY_REG_5_DIS_TXCM_PERST_DISABLE_N_SET(x)                         (((0 | (x)) << PCIE_PHY_REG_5_DIS_TXCM_PERST_DISABLE_N_LSB) & PCIE_PHY_REG_5_DIS_TXCM_PERST_DISABLE_N_MASK)
#define PCIE_PHY_REG_5_DIS_TXCM_PERST_DISABLE_N_RESET                          0x1
#define PCIE_PHY_REG_5_SERDES_EN_DEEMP_LSB                                     9
#define PCIE_PHY_REG_5_SERDES_EN_DEEMP_MSB                                     11
#define PCIE_PHY_REG_5_SERDES_EN_DEEMP_MASK                                    0xe00
#define PCIE_PHY_REG_5_SERDES_EN_DEEMP_GET(x)                                  (((x) & PCIE_PHY_REG_5_SERDES_EN_DEEMP_MASK) >> PCIE_PHY_REG_5_SERDES_EN_DEEMP_LSB)
#define PCIE_PHY_REG_5_SERDES_EN_DEEMP_SET(x)                                  (((0 | (x)) << PCIE_PHY_REG_5_SERDES_EN_DEEMP_LSB) & PCIE_PHY_REG_5_SERDES_EN_DEEMP_MASK)
#define PCIE_PHY_REG_5_SERDES_EN_DEEMP_RESET                                   0x3
#define PCIE_PHY_REG_5_SERDES_FSLCK_LEVEL_LSB                                  6
#define PCIE_PHY_REG_5_SERDES_FSLCK_LEVEL_MSB                                  8
#define PCIE_PHY_REG_5_SERDES_FSLCK_LEVEL_MASK                                 0x1c0
#define PCIE_PHY_REG_5_SERDES_FSLCK_LEVEL_GET(x)                               (((x) & PCIE_PHY_REG_5_SERDES_FSLCK_LEVEL_MASK) >> PCIE_PHY_REG_5_SERDES_FSLCK_LEVEL_LSB)
#define PCIE_PHY_REG_5_SERDES_FSLCK_LEVEL_SET(x)                               (((0 | (x)) << PCIE_PHY_REG_5_SERDES_FSLCK_LEVEL_LSB) & PCIE_PHY_REG_5_SERDES_FSLCK_LEVEL_MASK)
#define PCIE_PHY_REG_5_SERDES_FSLCK_LEVEL_RESET                                0x5
#define PCIE_PHY_REG_5_SERDES_VCORNG_CTRL_LSB                                  3
#define PCIE_PHY_REG_5_SERDES_VCORNG_CTRL_MSB                                  5
#define PCIE_PHY_REG_5_SERDES_VCORNG_CTRL_MASK                                 0x38
#define PCIE_PHY_REG_5_SERDES_VCORNG_CTRL_GET(x)                               (((x) & PCIE_PHY_REG_5_SERDES_VCORNG_CTRL_MASK) >> PCIE_PHY_REG_5_SERDES_VCORNG_CTRL_LSB)
#define PCIE_PHY_REG_5_SERDES_VCORNG_CTRL_SET(x)                               (((0 | (x)) << PCIE_PHY_REG_5_SERDES_VCORNG_CTRL_LSB) & PCIE_PHY_REG_5_SERDES_VCORNG_CTRL_MASK)
#define PCIE_PHY_REG_5_SERDES_VCORNG_CTRL_RESET                                0x0
#define PCIE_PHY_REG_5_SERDES_EN_STEPTX_LSB                                    2
#define PCIE_PHY_REG_5_SERDES_EN_STEPTX_MSB                                    2
#define PCIE_PHY_REG_5_SERDES_EN_STEPTX_MASK                                   0x4
#define PCIE_PHY_REG_5_SERDES_EN_STEPTX_GET(x)                                 (((x) & PCIE_PHY_REG_5_SERDES_EN_STEPTX_MASK) >> PCIE_PHY_REG_5_SERDES_EN_STEPTX_LSB)
#define PCIE_PHY_REG_5_SERDES_EN_STEPTX_SET(x)                                 (((0 | (x)) << PCIE_PHY_REG_5_SERDES_EN_STEPTX_LSB) & PCIE_PHY_REG_5_SERDES_EN_STEPTX_MASK)
#define PCIE_PHY_REG_5_SERDES_EN_STEPTX_RESET                                  0x1
#define PCIE_PHY_REG_5_EN_FAST_PLL_LOCK_LSB                                    1
#define PCIE_PHY_REG_5_EN_FAST_PLL_LOCK_MSB                                    1
#define PCIE_PHY_REG_5_EN_FAST_PLL_LOCK_MASK                                   0x2
#define PCIE_PHY_REG_5_EN_FAST_PLL_LOCK_GET(x)                                 (((x) & PCIE_PHY_REG_5_EN_FAST_PLL_LOCK_MASK) >> PCIE_PHY_REG_5_EN_FAST_PLL_LOCK_LSB)
#define PCIE_PHY_REG_5_EN_FAST_PLL_LOCK_SET(x)                                 (((0 | (x)) << PCIE_PHY_REG_5_EN_FAST_PLL_LOCK_LSB) & PCIE_PHY_REG_5_EN_FAST_PLL_LOCK_MASK)
#define PCIE_PHY_REG_5_EN_FAST_PLL_LOCK_RESET                                  0x1
#define PCIE_PHY_REG_5_RX_SIGNAL_DET_OFF_LSB                                   0
#define PCIE_PHY_REG_5_RX_SIGNAL_DET_OFF_MSB                                   0
#define PCIE_PHY_REG_5_RX_SIGNAL_DET_OFF_MASK                                  0x1
#define PCIE_PHY_REG_5_RX_SIGNAL_DET_OFF_GET(x)                                (((x) & PCIE_PHY_REG_5_RX_SIGNAL_DET_OFF_MASK) >> PCIE_PHY_REG_5_RX_SIGNAL_DET_OFF_LSB)
#define PCIE_PHY_REG_5_RX_SIGNAL_DET_OFF_SET(x)                                (((0 | (x)) << PCIE_PHY_REG_5_RX_SIGNAL_DET_OFF_LSB) & PCIE_PHY_REG_5_RX_SIGNAL_DET_OFF_MASK)
#define PCIE_PHY_REG_5_RX_SIGNAL_DET_OFF_RESET                                 0x1
#define PCIE_PHY_REG_5_ADDRESS                                                 (0x10 + __PCIE_PHY_REG_CSR_BASE_ADDRESS)
#define PCIE_PHY_REG_5_RSTMASK                                                 0x1fffffff
#define PCIE_PHY_REG_5_RESET                                                   0x53747

// 0x14 (PCIE_PHY_REG_6)
#define PCIE_PHY_REG_6_RESERVE_LSB                                             14
#define PCIE_PHY_REG_6_RESERVE_MSB                                             31
#define PCIE_PHY_REG_6_RESERVE_MASK                                            0xffffc000
#define PCIE_PHY_REG_6_RESERVE_GET(x)                                          (((x) & PCIE_PHY_REG_6_RESERVE_MASK) >> PCIE_PHY_REG_6_RESERVE_LSB)
#define PCIE_PHY_REG_6_RESERVE_SET(x)                                          (((0 | (x)) << PCIE_PHY_REG_6_RESERVE_LSB) & PCIE_PHY_REG_6_RESERVE_MASK)
#define PCIE_PHY_REG_6_RESERVE_RESET                                           0x2c
#define PCIE_PHY_REG_6_LOCKDETECT_RST_N_LSB                                    13
#define PCIE_PHY_REG_6_LOCKDETECT_RST_N_MSB                                    13
#define PCIE_PHY_REG_6_LOCKDETECT_RST_N_MASK                                   0x2000
#define PCIE_PHY_REG_6_LOCKDETECT_RST_N_GET(x)                                 (((x) & PCIE_PHY_REG_6_LOCKDETECT_RST_N_MASK) >> PCIE_PHY_REG_6_LOCKDETECT_RST_N_LSB)
#define PCIE_PHY_REG_6_LOCKDETECT_RST_N_SET(x)                                 (((0 | (x)) << PCIE_PHY_REG_6_LOCKDETECT_RST_N_LSB) & PCIE_PHY_REG_6_LOCKDETECT_RST_N_MASK)
#define PCIE_PHY_REG_6_LOCKDETECT_RST_N_RESET                                  0x1
#define PCIE_PHY_REG_6_EN_BUFS_RX_DELAY_ENABLE_LSB                             12
#define PCIE_PHY_REG_6_EN_BUFS_RX_DELAY_ENABLE_MSB                             12
#define PCIE_PHY_REG_6_EN_BUFS_RX_DELAY_ENABLE_MASK                            0x1000
#define PCIE_PHY_REG_6_EN_BUFS_RX_DELAY_ENABLE_GET(x)                          (((x) & PCIE_PHY_REG_6_EN_BUFS_RX_DELAY_ENABLE_MASK) >> PCIE_PHY_REG_6_EN_BUFS_RX_DELAY_ENABLE_LSB)
#define PCIE_PHY_REG_6_EN_BUFS_RX_DELAY_ENABLE_SET(x)                          (((0 | (x)) << PCIE_PHY_REG_6_EN_BUFS_RX_DELAY_ENABLE_LSB) & PCIE_PHY_REG_6_EN_BUFS_RX_DELAY_ENABLE_MASK)
#define PCIE_PHY_REG_6_EN_BUFS_RX_DELAY_ENABLE_RESET                           0x0
#define PCIE_PHY_REG_6_EN_BUFS_RX_VALUE_LSB                                    0
#define PCIE_PHY_REG_6_EN_BUFS_RX_VALUE_MSB                                    11
#define PCIE_PHY_REG_6_EN_BUFS_RX_VALUE_MASK                                   0xfff
#define PCIE_PHY_REG_6_EN_BUFS_RX_VALUE_GET(x)                                 (((x) & PCIE_PHY_REG_6_EN_BUFS_RX_VALUE_MASK) >> PCIE_PHY_REG_6_EN_BUFS_RX_VALUE_LSB)
#define PCIE_PHY_REG_6_EN_BUFS_RX_VALUE_SET(x)                                 (((0 | (x)) << PCIE_PHY_REG_6_EN_BUFS_RX_VALUE_LSB) & PCIE_PHY_REG_6_EN_BUFS_RX_VALUE_MASK)
#define PCIE_PHY_REG_6_EN_BUFS_RX_VALUE_RESET                                  0x38
#define PCIE_PHY_REG_6_ADDRESS                                                 (0x14 + __PCIE_PHY_REG_CSR_BASE_ADDRESS)
#define PCIE_PHY_REG_6_RSTMASK                                                 0xffffffff
#define PCIE_PHY_REG_6_RESET                                                   0xb2038



#endif /* _PCIE_PHY_REG_CSR_H_ */
