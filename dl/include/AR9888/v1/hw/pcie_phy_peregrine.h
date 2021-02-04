// ------------------------------------------------------------------
// Copyright (c) 2004-2012 Qualcomm Atheros.  All rights reserved.
// $ATH_LICENSE_TARGET_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Qualcomm Atheros"
//===================================================================



#ifndef _PCIE_PHY_PEREGRINE_H_
#define _PCIE_PHY_PEREGRINE_H_


/* macros for pcie_phy_pcie_phy_reg_1 */
#define PCIE_PHY_PCIE_PHY_REG_1_ADDRESS                                                   0x00000640
#define PCIE_PHY_PCIE_PHY_REG_1_OFFSET                                                    0x00000640
#define PCIE_PHY_PCIE_PHY_REG_1_S_MSB                                                              3
#define PCIE_PHY_PCIE_PHY_REG_1_S_LSB                                                              0
#define PCIE_PHY_PCIE_PHY_REG_1_S_MASK                                                    0x0000000f
#define PCIE_PHY_PCIE_PHY_REG_1_S_GET(x)                                   (((x) & 0x0000000f) >> 0)
#define PCIE_PHY_PCIE_PHY_REG_1_S_SET(x)                                   (((x) << 0) & 0x0000000f)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_SEL_HSP_MSB                                                 4
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_SEL_HSP_LSB                                                 4
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_SEL_HSP_MASK                                       0x00000010
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_SEL_HSP_GET(x)                      (((x) & 0x00000010) >> 4)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_SEL_HSP_SET(x)                      (((x) << 4) & 0x00000010)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_HALFTXDR_MSB                                                5
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_HALFTXDR_LSB                                                5
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_HALFTXDR_MASK                                      0x00000020
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_HALFTXDR_GET(x)                     (((x) & 0x00000020) >> 5)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_HALFTXDR_SET(x)                     (((x) << 5) & 0x00000020)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_EN_DEEMP_MSB                                                6
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_EN_DEEMP_LSB                                                6
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_EN_DEEMP_MASK                                      0x00000040
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_EN_DEEMP_GET(x)                     (((x) & 0x00000040) >> 6)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_EN_DEEMP_SET(x)                     (((x) << 6) & 0x00000040)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_TH_LOS_MSB                                                  8
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_TH_LOS_LSB                                                  7
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_TH_LOS_MASK                                        0x00000180
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_TH_LOS_GET(x)                       (((x) & 0x00000180) >> 7)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_TH_LOS_SET(x)                       (((x) << 7) & 0x00000180)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_CDR_BW_MSB                                                 10
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_CDR_BW_LSB                                                  9
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_CDR_BW_MASK                                        0x00000600
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_CDR_BW_GET(x)                       (((x) & 0x00000600) >> 9)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_CDR_BW_SET(x)                       (((x) << 9) & 0x00000600)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_POWER_SAVE_MSB                                             11
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_POWER_SAVE_LSB                                             11
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_POWER_SAVE_MASK                                    0x00000800
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_POWER_SAVE_GET(x)                  (((x) & 0x00000800) >> 11)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_POWER_SAVE_SET(x)                  (((x) << 11) & 0x00000800)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_MSB                                         12
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_LSB                                         12
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_MASK                                0x00001000
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_GET(x)              (((x) & 0x00001000) >> 12)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_PLL_DISABLE_L1_SET(x)              (((x) << 12) & 0x00001000)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_EN_LCKDT_MSB                                               13
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_EN_LCKDT_LSB                                               13
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_EN_LCKDT_MASK                                      0x00002000
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_EN_LCKDT_GET(x)                    (((x) & 0x00002000) >> 13)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_EN_LCKDT_SET(x)                    (((x) << 13) & 0x00002000)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_RX_EQ_MSB                                                  14
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_RX_EQ_LSB                                                  14
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_RX_EQ_MASK                                         0x00004000
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_RX_EQ_GET(x)                       (((x) & 0x00004000) >> 14)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_RX_EQ_SET(x)                       (((x) << 14) & 0x00004000)
#define PCIE_PHY_PCIE_PHY_REG_1_SEL_CLK_MSB                                                       16
#define PCIE_PHY_PCIE_PHY_REG_1_SEL_CLK_LSB                                                       15
#define PCIE_PHY_PCIE_PHY_REG_1_SEL_CLK_MASK                                              0x00018000
#define PCIE_PHY_PCIE_PHY_REG_1_SEL_CLK_GET(x)                            (((x) & 0x00018000) >> 15)
#define PCIE_PHY_PCIE_PHY_REG_1_SEL_CLK_SET(x)                            (((x) << 15) & 0x00018000)
#define PCIE_PHY_PCIE_PHY_REG_1_FORCELOOPBACK_MSB                                                 17
#define PCIE_PHY_PCIE_PHY_REG_1_FORCELOOPBACK_LSB                                                 17
#define PCIE_PHY_PCIE_PHY_REG_1_FORCELOOPBACK_MASK                                        0x00020000
#define PCIE_PHY_PCIE_PHY_REG_1_FORCELOOPBACK_GET(x)                      (((x) & 0x00020000) >> 17)
#define PCIE_PHY_PCIE_PHY_REG_1_FORCELOOPBACK_SET(x)                      (((x) << 17) & 0x00020000)
#define PCIE_PHY_PCIE_PHY_REG_1_ENABLECLKREQ_MSB                                                  18
#define PCIE_PHY_PCIE_PHY_REG_1_ENABLECLKREQ_LSB                                                  18
#define PCIE_PHY_PCIE_PHY_REG_1_ENABLECLKREQ_MASK                                         0x00040000
#define PCIE_PHY_PCIE_PHY_REG_1_ENABLECLKREQ_GET(x)                       (((x) & 0x00040000) >> 18)
#define PCIE_PHY_PCIE_PHY_REG_1_ENABLECLKREQ_SET(x)                       (((x) << 18) & 0x00040000)
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTTXCLKINV_MSB                                              19
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTTXCLKINV_LSB                                              19
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTTXCLKINV_MASK                                     0x00080000
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTTXCLKINV_GET(x)                   (((x) & 0x00080000) >> 19)
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTTXCLKINV_SET(x)                   (((x) << 19) & 0x00080000)
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTRXCLKINV_MSB                                              20
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTRXCLKINV_LSB                                              20
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTRXCLKINV_MASK                                     0x00100000
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTRXCLKINV_GET(x)                   (((x) & 0x00100000) >> 20)
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTRXCLKINV_SET(x)                   (((x) << 20) & 0x00100000)
#define PCIE_PHY_PCIE_PHY_REG_1_RXCLKINV_MSB                                                      21
#define PCIE_PHY_PCIE_PHY_REG_1_RXCLKINV_LSB                                                      21
#define PCIE_PHY_PCIE_PHY_REG_1_RXCLKINV_MASK                                             0x00200000
#define PCIE_PHY_PCIE_PHY_REG_1_RXCLKINV_GET(x)                           (((x) & 0x00200000) >> 21)
#define PCIE_PHY_PCIE_PHY_REG_1_RXCLKINV_SET(x)                           (((x) << 21) & 0x00200000)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_DISABLE_MSB                                                22
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_DISABLE_LSB                                                22
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_DISABLE_MASK                                       0x00400000
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_DISABLE_GET(x)                     (((x) & 0x00400000) >> 22)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_DISABLE_SET(x)                     (((x) << 22) & 0x00400000)
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTEN_MSB                                                    23
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTEN_LSB                                                    23
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTEN_MASK                                           0x00800000
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTEN_GET(x)                         (((x) & 0x00800000) >> 23)
#define PCIE_PHY_PCIE_PHY_REG_1_FUNCTESTEN_SET(x)                         (((x) << 23) & 0x00800000)
#define PCIE_PHY_PCIE_PHY_REG_1_DATAOBSEN_MSB                                                     24
#define PCIE_PHY_PCIE_PHY_REG_1_DATAOBSEN_LSB                                                     24
#define PCIE_PHY_PCIE_PHY_REG_1_DATAOBSEN_MASK                                            0x01000000
#define PCIE_PHY_PCIE_PHY_REG_1_DATAOBSEN_GET(x)                          (((x) & 0x01000000) >> 24)
#define PCIE_PHY_PCIE_PHY_REG_1_DATAOBSEN_SET(x)                          (((x) << 24) & 0x01000000)
#define PCIE_PHY_PCIE_PHY_REG_1_CLKOBSSEL_MSB                                                     26
#define PCIE_PHY_PCIE_PHY_REG_1_CLKOBSSEL_LSB                                                     25
#define PCIE_PHY_PCIE_PHY_REG_1_CLKOBSSEL_MASK                                            0x06000000
#define PCIE_PHY_PCIE_PHY_REG_1_CLKOBSSEL_GET(x)                          (((x) & 0x06000000) >> 25)
#define PCIE_PHY_PCIE_PHY_REG_1_CLKOBSSEL_SET(x)                          (((x) << 25) & 0x06000000)
#define PCIE_PHY_PCIE_PHY_REG_1_PERSTDELAY_MSB                                                    28
#define PCIE_PHY_PCIE_PHY_REG_1_PERSTDELAY_LSB                                                    27
#define PCIE_PHY_PCIE_PHY_REG_1_PERSTDELAY_MASK                                           0x18000000
#define PCIE_PHY_PCIE_PHY_REG_1_PERSTDELAY_GET(x)                         (((x) & 0x18000000) >> 27)
#define PCIE_PHY_PCIE_PHY_REG_1_PERSTDELAY_SET(x)                         (((x) << 27) & 0x18000000)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_TXDR_CTRL_MSB                                              30
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_TXDR_CTRL_LSB                                              29
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_TXDR_CTRL_MASK                                     0x60000000
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_TXDR_CTRL_GET(x)                   (((x) & 0x60000000) >> 29)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_TXDR_CTRL_SET(x)                   (((x) << 29) & 0x60000000)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_DIS_RXIMP_MSB                                              31
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_DIS_RXIMP_LSB                                              31
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_DIS_RXIMP_MASK                                     0x80000000
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_DIS_RXIMP_GET(x)                   (((x) & 0x80000000) >> 31)
#define PCIE_PHY_PCIE_PHY_REG_1_SERDES_DIS_RXIMP_SET(x)                   (((x) << 31) & 0x80000000)

/* macros for pcie_phy_pcie_phy_reg_2 */
#define PCIE_PHY_PCIE_PHY_REG_2_ADDRESS                                                   0x00000644
#define PCIE_PHY_PCIE_PHY_REG_2_OFFSET                                                    0x00000644
#define PCIE_PHY_PCIE_PHY_REG_2_FORCEDETECT_MSB                                                    0
#define PCIE_PHY_PCIE_PHY_REG_2_FORCEDETECT_LSB                                                    0
#define PCIE_PHY_PCIE_PHY_REG_2_FORCEDETECT_MASK                                          0x00000001
#define PCIE_PHY_PCIE_PHY_REG_2_FORCEDETECT_GET(x)                         (((x) & 0x00000001) >> 0)
#define PCIE_PHY_PCIE_PHY_REG_2_FORCEDETECT_SET(x)                         (((x) << 0) & 0x00000001)
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXTARGETDELAY_MSB                                             5
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXTARGETDELAY_LSB                                             1
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXTARGETDELAY_MASK                                   0x0000003e
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXTARGETDELAY_GET(x)                  (((x) & 0x0000003e) >> 1)
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXTARGETDELAY_SET(x)                  (((x) << 1) & 0x0000003e)
#define PCIE_PHY_PCIE_PHY_REG_2_CDRREADYTIMER_MSB                                                  9
#define PCIE_PHY_PCIE_PHY_REG_2_CDRREADYTIMER_LSB                                                  6
#define PCIE_PHY_PCIE_PHY_REG_2_CDRREADYTIMER_MASK                                        0x000003c0
#define PCIE_PHY_PCIE_PHY_REG_2_CDRREADYTIMER_GET(x)                       (((x) & 0x000003c0) >> 6)
#define PCIE_PHY_PCIE_PHY_REG_2_CDRREADYTIMER_SET(x)                       (((x) << 6) & 0x000003c0)
#define PCIE_PHY_PCIE_PHY_REG_2_DATAOBSPRBSERR_MSB                                                10
#define PCIE_PHY_PCIE_PHY_REG_2_DATAOBSPRBSERR_LSB                                                10
#define PCIE_PHY_PCIE_PHY_REG_2_DATAOBSPRBSERR_MASK                                       0x00000400
#define PCIE_PHY_PCIE_PHY_REG_2_DATAOBSPRBSERR_GET(x)                     (((x) & 0x00000400) >> 10)
#define PCIE_PHY_PCIE_PHY_REG_2_DATAOBSPRBSERR_SET(x)                     (((x) << 10) & 0x00000400)
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXOVREN_MSB                                                  11
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXOVREN_LSB                                                  11
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXOVREN_MASK                                         0x00000800
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXOVREN_GET(x)                       (((x) & 0x00000800) >> 11)
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXOVREN_SET(x)                       (((x) << 11) & 0x00000800)
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXOVRVALUE_MSB                                               12
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXOVRVALUE_LSB                                               12
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXOVRVALUE_MASK                                      0x00001000
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXOVRVALUE_GET(x)                    (((x) & 0x00001000) >> 12)
#define PCIE_PHY_PCIE_PHY_REG_2_TXDETRXOVRVALUE_SET(x)                    (((x) << 12) & 0x00001000)
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_TS_NUM_MSB                                                   19
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_TS_NUM_LSB                                                   13
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_TS_NUM_MASK                                          0x000fe000
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_TS_NUM_GET(x)                        (((x) & 0x000fe000) >> 13)
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_TS_NUM_SET(x)                        (((x) << 13) & 0x000fe000)
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_START_MSB                                                    20
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_START_LSB                                                    20
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_START_MASK                                           0x00100000
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_START_GET(x)                         (((x) & 0x00100000) >> 20)
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_START_SET(x)                         (((x) << 20) & 0x00100000)
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_SCRAMBLE_MSB                                                 21
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_SCRAMBLE_LSB                                                 21
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_SCRAMBLE_MASK                                        0x00200000
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_SCRAMBLE_GET(x)                      (((x) & 0x00200000) >> 21)
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_SCRAMBLE_SET(x)                      (((x) << 21) & 0x00200000)
#define PCIE_PHY_PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_MSB                                            22
#define PCIE_PHY_PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_LSB                                            22
#define PCIE_PHY_PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_MASK                                   0x00400000
#define PCIE_PHY_PCIE_PHY_REG_2_SDS_SDM_RXDETECTED_GET(x)                 (((x) & 0x00400000) >> 22)
#define PCIE_PHY_PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_MSB                                            23
#define PCIE_PHY_PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_LSB                                            23
#define PCIE_PHY_PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_MASK                                   0x00800000
#define PCIE_PHY_PCIE_PHY_REG_2_SDS_SDM_RXELECIDLE_GET(x)                 (((x) & 0x00800000) >> 23)
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_ERROR_COUNT_MSB                                              31
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_ERROR_COUNT_LSB                                              24
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_ERROR_COUNT_MASK                                     0xff000000
#define PCIE_PHY_PCIE_PHY_REG_2_PRBS_ERROR_COUNT_GET(x)                   (((x) & 0xff000000) >> 24)

/* macros for pcie_phy_pcie_phy_reg_3 */
#define PCIE_PHY_PCIE_PHY_REG_3_ADDRESS                                                   0x00000648
#define PCIE_PHY_PCIE_PHY_REG_3_OFFSET                                                    0x00000648
#define PCIE_PHY_PCIE_PHY_REG_3_EN_MSB                                                             0
#define PCIE_PHY_PCIE_PHY_REG_3_EN_LSB                                                             0
#define PCIE_PHY_PCIE_PHY_REG_3_EN_MASK                                                   0x00000001
#define PCIE_PHY_PCIE_PHY_REG_3_EN_GET(x)                                  (((x) & 0x00000001) >> 0)
#define PCIE_PHY_PCIE_PHY_REG_3_EN_SET(x)                                  (((x) << 0) & 0x00000001)
#define PCIE_PHY_PCIE_PHY_REG_3_EN_BUFS_RX_MSB                                                     1
#define PCIE_PHY_PCIE_PHY_REG_3_EN_BUFS_RX_LSB                                                     1
#define PCIE_PHY_PCIE_PHY_REG_3_EN_BUFS_RX_MASK                                           0x00000002
#define PCIE_PHY_PCIE_PHY_REG_3_EN_BUFS_RX_GET(x)                          (((x) & 0x00000002) >> 1)
#define PCIE_PHY_PCIE_PHY_REG_3_EN_BUFS_RX_SET(x)                          (((x) << 1) & 0x00000002)
#define PCIE_PHY_PCIE_PHY_REG_3_EN_LCKDT_MSB                                                       2
#define PCIE_PHY_PCIE_PHY_REG_3_EN_LCKDT_LSB                                                       2
#define PCIE_PHY_PCIE_PHY_REG_3_EN_LCKDT_MASK                                             0x00000004
#define PCIE_PHY_PCIE_PHY_REG_3_EN_LCKDT_GET(x)                            (((x) & 0x00000004) >> 2)
#define PCIE_PHY_PCIE_PHY_REG_3_EN_LCKDT_SET(x)                            (((x) << 2) & 0x00000004)
#define PCIE_PHY_PCIE_PHY_REG_3_EN_PLL_MSB                                                         3
#define PCIE_PHY_PCIE_PHY_REG_3_EN_PLL_LSB                                                         3
#define PCIE_PHY_PCIE_PHY_REG_3_EN_PLL_MASK                                               0x00000008
#define PCIE_PHY_PCIE_PHY_REG_3_EN_PLL_GET(x)                              (((x) & 0x00000008) >> 3)
#define PCIE_PHY_PCIE_PHY_REG_3_EN_PLL_SET(x)                              (((x) << 3) & 0x00000008)
#define PCIE_PHY_PCIE_PHY_REG_3_MODE_OCLK_IN_MSB                                                   4
#define PCIE_PHY_PCIE_PHY_REG_3_MODE_OCLK_IN_LSB                                                   4
#define PCIE_PHY_PCIE_PHY_REG_3_MODE_OCLK_IN_MASK                                         0x00000010
#define PCIE_PHY_PCIE_PHY_REG_3_MODE_OCLK_IN_GET(x)                        (((x) & 0x00000010) >> 4)
#define PCIE_PHY_PCIE_PHY_REG_3_MODE_OCLK_IN_SET(x)                        (((x) << 4) & 0x00000010)
#define PCIE_PHY_PCIE_PHY_REG_3_RX_DET_REQ_MSB                                                     5
#define PCIE_PHY_PCIE_PHY_REG_3_RX_DET_REQ_LSB                                                     5
#define PCIE_PHY_PCIE_PHY_REG_3_RX_DET_REQ_MASK                                           0x00000020
#define PCIE_PHY_PCIE_PHY_REG_3_RX_DET_REQ_GET(x)                          (((x) & 0x00000020) >> 5)
#define PCIE_PHY_PCIE_PHY_REG_3_RX_DET_REQ_SET(x)                          (((x) << 5) & 0x00000020)
#define PCIE_PHY_PCIE_PHY_REG_3_SEL_CLK_MSB                                                        7
#define PCIE_PHY_PCIE_PHY_REG_3_SEL_CLK_LSB                                                        6
#define PCIE_PHY_PCIE_PHY_REG_3_SEL_CLK_MASK                                              0x000000c0
#define PCIE_PHY_PCIE_PHY_REG_3_SEL_CLK_GET(x)                             (((x) & 0x000000c0) >> 6)
#define PCIE_PHY_PCIE_PHY_REG_3_SEL_CLK_SET(x)                             (((x) << 6) & 0x000000c0)
#define PCIE_PHY_PCIE_PHY_REG_3_TXELECIDLE_MSB                                                     8
#define PCIE_PHY_PCIE_PHY_REG_3_TXELECIDLE_LSB                                                     8
#define PCIE_PHY_PCIE_PHY_REG_3_TXELECIDLE_MASK                                           0x00000100
#define PCIE_PHY_PCIE_PHY_REG_3_TXELECIDLE_GET(x)                          (((x) & 0x00000100) >> 8)
#define PCIE_PHY_PCIE_PHY_REG_3_TXELECIDLE_SET(x)                          (((x) << 8) & 0x00000100)
#define PCIE_PHY_PCIE_PHY_REG_3_EN_BEACONGEN_MSB                                                   9
#define PCIE_PHY_PCIE_PHY_REG_3_EN_BEACONGEN_LSB                                                   9
#define PCIE_PHY_PCIE_PHY_REG_3_EN_BEACONGEN_MASK                                         0x00000200
#define PCIE_PHY_PCIE_PHY_REG_3_EN_BEACONGEN_GET(x)                        (((x) & 0x00000200) >> 9)
#define PCIE_PHY_PCIE_PHY_REG_3_EN_BEACONGEN_SET(x)                        (((x) << 9) & 0x00000200)
#define PCIE_PHY_PCIE_PHY_REG_3_SEL_CLK100_MSB                                                    10
#define PCIE_PHY_PCIE_PHY_REG_3_SEL_CLK100_LSB                                                    10
#define PCIE_PHY_PCIE_PHY_REG_3_SEL_CLK100_MASK                                           0x00000400
#define PCIE_PHY_PCIE_PHY_REG_3_SEL_CLK100_GET(x)                         (((x) & 0x00000400) >> 10)
#define PCIE_PHY_PCIE_PHY_REG_3_SEL_CLK100_SET(x)                         (((x) << 10) & 0x00000400)
#define PCIE_PHY_PCIE_PHY_REG_3_SPARE_MSB                                                         15
#define PCIE_PHY_PCIE_PHY_REG_3_SPARE_LSB                                                         11
#define PCIE_PHY_PCIE_PHY_REG_3_SPARE_MASK                                                0x0000f800
#define PCIE_PHY_PCIE_PHY_REG_3_SPARE_GET(x)                              (((x) & 0x0000f800) >> 11)
#define PCIE_PHY_PCIE_PHY_REG_3_SPARE_SET(x)                              (((x) << 11) & 0x0000f800)
#define PCIE_PHY_PCIE_PHY_REG_3_SERDES_REG_MSB                                                    20
#define PCIE_PHY_PCIE_PHY_REG_3_SERDES_REG_LSB                                                    16
#define PCIE_PHY_PCIE_PHY_REG_3_SERDES_REG_MASK                                           0x001f0000
#define PCIE_PHY_PCIE_PHY_REG_3_SERDES_REG_GET(x)                         (((x) & 0x001f0000) >> 16)
#define PCIE_PHY_PCIE_PHY_REG_3_SERDES_REG_SET(x)                         (((x) << 16) & 0x001f0000)


#ifndef __ASSEMBLER__

typedef struct pcie_phy_peregrine_reg_s {
  volatile char pad__0[0x640];                                         /*        0x0 - 0x640      */
  volatile unsigned int pcie_phy_pcie_phy_reg_1;                       /*      0x640 - 0x644      */
  volatile unsigned int pcie_phy_pcie_phy_reg_2;                       /*      0x644 - 0x648      */
  volatile unsigned int pcie_phy_pcie_phy_reg_3;                       /*      0x648 - 0x64c      */
} pcie_phy_peregrine_reg_t;

#endif /* __ASSEMBLER__ */

#endif /* _PCIE_PHY_PEREGRINE_H_ */
